#define TEGRA_EXCEPTION_VECTORS_BASE    0x6000F000
#define TEGRA_CLK_RESET_BASE            0x60006000
#define TEGRA_FLOW_CTRL_BASE            0x60007000
#define TEGRA_PMC_BASE                  0x7000E400


#define EVP_CPU_RSVD_VECTOR \
        (TEGRA_EXCEPTION_VECTORS_BASE + 0x114)
#define CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET \
        (TEGRA_CLK_RESET_BASE + 0x340)
#define CLK_RST_CONTROLLER_RST_CPU_CMPLX_CLR \
        (TEGRA_CLK_RESET_BASE + 0x344)
#define CLK_RST_CONTROLLER_CLK_CPU_CMPLX \
        (TEGRA_CLK_RESET_BASE + 0x4c)
#define CLK_RST_CONTROLLER_CPU_CMPLX_STATUS \
        (TEGRA_CLK_RESET_BASE + 0x470)

#define CPU_CLOCK(cpu)  (0x1<<(8+cpu))
#define CPU_RESET(cpu)  (0x1111ul<<(cpu))

#define FLOW_CTRL_HALT_CPUx_EVENTS(cpu) (TEGRA_FLOW_CTRL_BASE + \
        ((cpu)?(((cpu)-1)*0x8 + 0x14) : 0x0))
#define FLOW_CTRL_CPUx_CSR(cpu)         (TEGRA_FLOW_CTRL_BASE + \
        ((cpu)?(((cpu)-1)*0x8 + 0x18) : 0x8))

#define __raw_writel(v,a)       (*(volatile unsigned int *)(a) = (v))
#define __raw_readl(a)          (*(volatile unsigned int *)(a))

static inline void flowctrl_writel(unsigned long val, void *addr)
{
        __raw_writel(val, addr);
        (void)__raw_readl(addr);
}


#ifndef _MACH_TEGRA_POWERGATE_H_
#define _MACH_TEGRA_POWERGATE_H_

#define TEGRA_POWERGATE_CPU     0
#define TEGRA_POWERGATE_CPU0    TEGRA_POWERGATE_CPU
#define TEGRA_POWERGATE_3D      1
#define TEGRA_POWERGATE_3D0     TEGRA_POWERGATE_3D
#define TEGRA_POWERGATE_VENC    2
#define TEGRA_POWERGATE_PCIE    3
#define TEGRA_POWERGATE_VDEC    4
#define TEGRA_POWERGATE_L2      5
#define TEGRA_POWERGATE_MPE     6
#define TEGRA_POWERGATE_HEG     7
#define TEGRA_POWERGATE_SATA    8
#define TEGRA_POWERGATE_CPU1    9
#define TEGRA_POWERGATE_CPU2    10
#define TEGRA_POWERGATE_CPU3    11
#define TEGRA_POWERGATE_A9LP    12
#define TEGRA_POWERGATE_3D1     13
#define TEGRA_NUM_POWERGATE     14
#define TEGRA_CPU_POWERGATE_ID(cpu)     ((cpu == 0) ? TEGRA_POWERGATE_CPU0 : \
                                                (cpu + TEGRA_POWERGATE_CPU1 - 1))
#define TEGRA_IS_CPU_POWERGATE_ID(id)  (((id) == TEGRA_POWERGATE_CPU)  || \
                                        ((id) == TEGRA_POWERGATE_CPU1) || \
                                        ((id) == TEGRA_POWERGATE_CPU2) || \
                                        ((id) == TEGRA_POWERGATE_CPU3))
#endif

#define PWRGATE_TOGGLE          0x30
#define PWRGATE_TOGGLE_START    (1 << 8)

#define REMOVE_CLAMPING         0x34

#define PWRGATE_STATUS          0x38


static void *pmc = TEGRA_PMC_BASE;

static int pmc_read(unsigned long reg)
{
        return __raw_readl(pmc + reg);
}

static void pmc_write(int val, unsigned long reg)
{
        __raw_writel(val, pmc + reg);
}


#include <os/irq.h>
#include <ucos_ii.h>


int tegra_powergate_is_powered(int id)
{
        int status;

        if (id < 0 || id >= TEGRA_NUM_POWERGATE)
                return 0;

        status = pmc_read(PWRGATE_STATUS) & (1 << id);
        return !!status;
}

int tegra_powergate_remove_clamping(int id)
{
        int mask;
        if (id < 0 || id >= TEGRA_NUM_POWERGATE)
                return -1;

        /*
         * PCIE and VDE clamping masks are swapped with respect to their
         * partition ids
         */
        if (id ==  TEGRA_POWERGATE_VDEC)
                mask = (1 << TEGRA_POWERGATE_PCIE);
        else if (id == TEGRA_POWERGATE_PCIE)
                mask = (1 << TEGRA_POWERGATE_VDEC);
        else
                mask = (1 << id);

        pmc_write(mask, REMOVE_CLAMPING);

        return 0;
}

static int tegra_powergate_set(int id, int new_state)
{
        int status;
        unsigned long flags;
        /* 10us timeout for toggle operation if it takes affect*/
        int toggle_timeout = 10;
        /* 100 * 10 = 1000us timeout for toggle command to take affect in case
           of contention with h/w initiated CPU power gating */
        int contention_timeout = 100;

	new_state = !!new_state;

        status = !!(pmc_read(PWRGATE_STATUS) & (1 << id));

        if (status == new_state) {
                return -1;
        }

        if (TEGRA_IS_CPU_POWERGATE_ID(id)) {
                /* CPU ungated in s/w only during boot/resume with outer
                   waiting loop and no contention from other CPUs */
                pmc_write(PWRGATE_TOGGLE_START | id, PWRGATE_TOGGLE);
                return 0;
        }

        do {
                pmc_write(PWRGATE_TOGGLE_START | id, PWRGATE_TOGGLE);
                do {
                        udelay(1);
                        status = !!(pmc_read(PWRGATE_STATUS) & (1 << id));

                        toggle_timeout--;
                } while ((status != new_state) && (toggle_timeout > 0));

                contention_timeout--;
        } while ((status != new_state) && (contention_timeout > 0));

        if (status != new_state) {
                //WARN(1, "Could not set powergate %d to %d", id, new_state);
                return -2;
        }

        return 0;
}

static int power_up_cpu(unsigned int cpu)
{
        int ret;
        int reg;
//        unsigned long timeout;
        /* If this cpu has booted this function is entered after
         * CPU has been already un-gated by flow controller. Wait
         * for confirmation that cpu is powered and remove clamps.
         * On first boot entry do not wait - go to direct ungate.
         */
//        if (cpu_isset(cpu, *((cpumask_t *) &tegra_cpu_init_map)))
//        {
//                timeout = jiffies + 5;
//                do {
                        udelay(900);
                        if ( tegra_powergate_is_powered(TEGRA_CPU_POWERGATE_ID(cpu)) )
                                goto remove_clamps;
                        udelay(10);
//                } while (/*time_before(jiffies, timeout)*/1);
//        }
        /* 1'st boot or Flow controller did not work as expected - try directly toggle
           power gates. Bail out if direct power on also failed */
//        if (!is_cpu_powered(cpu))
//        {
//                ret = tegra_unpowergate_partition(TEGRA_CPU_POWERGATE_ID(cpu));
		tegra_powergate_set(TEGRA_CPU_POWERGATE_ID(cpu), 1);
                if (ret)
                        goto fail;

                /* Wait for the power to come up. */
                //timeout = jiffies + 10*HZ;

                do {
                        if (tegra_powergate_is_powered(TEGRA_CPU_POWERGATE_ID(cpu)) )
                                goto remove_clamps;
                        udelay(10);
                } while (1);//time_before(jiffies, timeout));
//                ret = -ETIMEDOUT;
                //goto fail;
//        }
remove_clamps:
        /* now CPU is up: enable clock, propagate reset, and remove clamps */
        reg = __raw_readl(CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
        __raw_writel(reg & ~CPU_CLOCK(cpu), CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
        barrier();
        reg = __raw_readl(CLK_RST_CONTROLLER_CLK_CPU_CMPLX);

        udelay(10);
        ret = tegra_powergate_remove_clamping(TEGRA_CPU_POWERGATE_ID(cpu));
fail:
        return ret;
}

void boot_secondary(unsigned int cpu)
{
#if 0
        unsigned long timeout;
        int status;

        /* Avoid timer calibration on slave cpus. Use the value calibrated
         * on master cpu. This reduces the bringup time for each slave cpu
         * by around 260ms.
         */
        preset_lpj = loops_per_jiffy;
        if (is_lp_cluster()) {
                struct clk *cpu_clk, *cpu_g_clk;

                /* The G CPU may not be available for a
                   variety of reasons. */
                status = is_g_cluster_available(cpu);
                if (status)
                        return status;

                cpu_clk = tegra_get_clock_by_name("cpu");
                cpu_g_clk = tegra_get_clock_by_name("cpu_g");

                /* Switch to G CPU before continuing. */
                if (!cpu_clk || !cpu_g_clk) {
                        /* Early boot, clock infrastructure is not initialized
                           - CPU mode switch is not allowed */
                        status = -EINVAL;
                } else
                        status = clk_set_parent(cpu_clk, cpu_g_clk);

                if (status)
                        return status;
        }
#endif
        /*
         * set synchronization state between this boot processor
         * and the secondary one
         */
        OS_ENTER_CRITICAL();

        /* WARNING:
                The compiler just loves to reorder the following code.
                This code is very sensitive to the register write sequence.
                DO NOT remove the barrier() calls. */

        barrier();
        __raw_writel(~0, EVP_CPU_RSVD_VECTOR);
        barrier();

        /* Force the CPU into reset. The CPU must remain in reset when the
           flow controller state is cleared (which will cause the flow
           controller to stop driving reset if the CPU has been power-gated
           via the flow controller). This will have no effect on first boot
           of the CPU since it should already be in reset. */
        __raw_writel(CPU_RESET(cpu), CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
        barrier();

        /* Unhalt the CPU. If the flow controller was used to power-gate the
           CPU this will cause the flow controller to stop driving reset.
           The CPU will remain in reset because the clock and reset block
           is now driving reset. */
        wmb();
        flowctrl_writel(0, FLOW_CTRL_HALT_CPUx_EVENTS(cpu));
        barrier();

        /* On Tegra3 secondary CPU was power gated (not just halted). Clearing
           CSR may abort power on state machine transition - do it only after
           CPU is powered up */
        /*status = */power_up_cpu(cpu);
        //if (status)
        //        goto done;
        flowctrl_writel(0, FLOW_CTRL_CPUx_CSR(cpu));
        barrier();

        udelay(10);     /* power up delay */
        __raw_writel(CPU_RESET(cpu), CLK_RST_CONTROLLER_RST_CPU_CMPLX_CLR);
        wmb();
        barrier();

//        timeout = jiffies + HZ;i
#if 0
        while (/*time_before(jiffies, timeout)*/1) {
                if (__raw_readl(EVP_CPU_RSVD_VECTOR) != ~0) {
                        //status = 0;
                        goto done;
                }
                udelay(10);
        }
//        status = -ETIMEDOUT;
#endif
done:

        /*
         * now the secondary core is starting up let it run its
         * calibrations, then wait for it to finish
         */
        OS_EXIT_CRITICAL();
}

extern void secondary_startup();
void cpu_reset_handler_init() {
	__raw_writel(secondary_startup, TEGRA_EXCEPTION_VECTORS_BASE+0x100);
}
