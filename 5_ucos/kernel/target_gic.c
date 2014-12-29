#include "io.h"
#include <target_gic.h>

#define NUM_ICTLRS (INT_MAIN_NR/32)

static void *ictlr_reg_base[] = {
	TEGRA_PRIMARY_ICTLR_BASE,
	TEGRA_SECONDARY_ICTLR_BASE,
	TEGRA_TERTIARY_ICTLR_BASE,
	TEGRA_QUATERNARY_ICTLR_BASE,
#if (NUM_ICTLRS > 4)
	TEGRA_QUINARY_ICTLR_BASE,
#endif
};

#define GIC_DIST_CTRL			0x000
#define GIC_DIST_CTR			0x004
#define GIC_DIST_SEC0			0x080

#define GIC_DIST_ENABLE_SET		0x100
#define GIC_DIST_ENABLE_CLEAR		0x180
#define GIC_DIST_PENDING_SET		0x200
#define GIC_DIST_PENDING_CLEAR		0x280
#define GIC_DIST_ACTIVE_BIT		0x300
#define GIC_DIST_PRI			0x400
#define GIC_DIST_TARGET			0x800
#define GIC_DIST_CONFIG			0xc00
#define GIC_DIST_SOFTINT		0xf00

#define max(x, y) ({				\
	typeof(x) _max1 = (x);			\
	typeof(y) _max2 = (y);			\
	(void) (&_max1 == &_max2);		\
	_max1 > _max2 ? _max1 : _max2; })

static unsigned int _gic_dist_init(unsigned int gic_nr)
{
	unsigned int max_irq, i;
//	void __iomem *base = gic_data[gic_nr].dist_base;
	void *base = TEGRA_ARM_INT_DIST_BASE;

	void *tmp_base;

	//SWKIM ---FIXME
//	u32 cpumask = 1 << smp_processor_id();
	unsigned int cpumask = /*1 << 0;*/ 1;
	
	cpumask |= cpumask << 8;
	cpumask |= cpumask << 16;

	writel(0, base + GIC_DIST_CTRL);


	writel(0xFFFFFFFF, base + GIC_DIST_SEC0);
	writel(0xFFFFFFFF, base + GIC_DIST_SEC0+0x4);
	writel(0xFFFFFFFF, base + GIC_DIST_SEC0+0x8);
	writel(0xFFFFFFFF, base + GIC_DIST_SEC0+0xc);
	writel(0xFFFFFFFF, base + GIC_DIST_SEC0+0x10);
	writel(0xFFFFFFFF, base + GIC_DIST_SEC0+0x14);

/*
	for(i=0; i < 0x1F; i++)
	{


	}
*/
	/*
	 * Find out how many interrupts are supported.
	 */
	max_irq = readl(base + GIC_DIST_CTR) & 0x1f;
	max_irq = (max_irq + 1) * 32;

	/*
	 * The GIC only supports up to 1020 interrupt sources.
	 * Limit this to either the architected maximum, or the
	 * platform maximum.
	 */
	if (max_irq > max(1020, NR_IRQS))
		max_irq = max(1020, NR_IRQS);

	/*
	 * Set all global interrupts to be level triggered, active low.
	 */
	for (i = 32; i < max_irq; i += 16)
		writel(0, base + GIC_DIST_CONFIG + i * 4 / 16);

	/*
	 * Set all global interrupts to this CPU only.
	 */
	for (i = 32; i < max_irq; i += 4)
		writel(cpumask, base + GIC_DIST_TARGET + i * 4 / 4);

	/*
	 * Set priority on all interrupts.
	 */
	for (i = 0; i < max_irq; i += 4)
		writel(0xa0a0a0a0, base + GIC_DIST_PRI + i * 4 / 4);

	/*
	 * Disable all interrupts.
	 */
	for (i = 0; i < max_irq; i += 32)
		writel(0xffffffff, base + GIC_DIST_ENABLE_CLEAR + i * 4 / 32);
	return max_irq;
}


void gic_dist_init(unsigned int gic_nr, void *base,
			  unsigned int irq_start)
{
	unsigned int max_irq;
	unsigned int i;

#if 0
	if (gic_nr >= MAX_GIC_NR)
		BUG();

	gic_data[gic_nr].dist_base = base;
	gic_data[gic_nr].irq_offset = (irq_start - 1) & ~31;
#endif
	max_irq = _gic_dist_init(gic_nr);
#if 0
	gic_data[gic_nr].max_irq = max_irq;

	/*
	 * Setup the Linux IRQ subsystem.
	 */
	for (i = irq_start; i < gic_data[gic_nr].irq_offset + max_irq; i++) {
		set_irq_chip(i, &gic_chip);
		set_irq_chip_data(i, &gic_data[gic_nr]);
		set_irq_handler(i, handle_level_irq);
		set_irq_flags(i, IRQF_VALID | IRQF_PROBE);
	}
#endif
	writel(1, base + GIC_DIST_CTRL);
}

#define GIC_CPU_PRIMASK			0x04
#define GIC_CPU_CTRL			0x00

void gic_cpu_init(unsigned int gic_nr, void *base)
{

#if 0
	if (gic_nr >= MAX_GIC_NR)
		BUG();

	gic_data[gic_nr].cpu_base = base;
#endif

	writel(0xf0, base + GIC_CPU_PRIMASK);
	writel(1, base + GIC_CPU_CTRL);

//임시로 이곳에 SCU Non-Secure Access Control Register를 설정 해둠
	writel(0xFFF, TEGRA_ARM_PERIF_BASE+0x54);
}

#define IRQF_VALID	(1 << 0)
#define IRQF_PROBE	(1 << 1)
#define IRQF_NOAUTOEN	(1 << 2)

void tegra_init_legacy_irq(void)
{
	int i;

	for (i = 0; i < NUM_ICTLRS; i++) {
		void *ictlr = ictlr_reg_base[i];
		writel(~0, ictlr + ICTLR_CPU_IER_CLR);
		writel(0, ictlr + ICTLR_CPU_IEP_CLASS);
		writel(~0, ictlr + ICTLR_CPU_IEP_FIR_CLR);
	}
}


void tegra_init_irq(void)
{
	unsigned int i;
	int irq;

	tegra_init_legacy_irq();

	gic_dist_init(0, TEGRA_ARM_INT_DIST_BASE, 29);
	gic_cpu_init(0, TEGRA_ARM_PERIF_BASE + 0x100);
#if 0
	for (i = 0; i < INT_MAIN_NR; i++) {
		irq = INT_PRI_BASE + i;
		set_irq_chip(irq, &tegra_irq);
		set_irq_handler(irq, handle_level_irq);
		set_irq_flags(irq, IRQF_VALID);
	}
#endif
}

