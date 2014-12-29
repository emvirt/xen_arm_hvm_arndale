#include <os/types.h>
#include <trustzone/trustzone.h>
#include <trustzone/switch.h>
#include <trustzone/communication.h>

extern void *vector_table;

int nonsecure_fault;

/*
 *  ?ーゲット依存の初期化
 */
void tegra_init_irq(void);
extern void arndale_gic_dist_init();
extern void arndale_gic_cpu_init();
#define MC_BASE_ADDR					0x7000F000

#define MC_SMMU_CONFIG_0                                0x10
#define MC_SMMU_CONFIG_0_SMMU_ENABLE_DISABLE            0
#define MC_SMMU_CONFIG_0_SMMU_ENABLE_ENABLE             1

#define MC_SMMU_ASID_SECURITY_0                         0x38

#define MC_SMMU_TRANSLATION_ENABLE_0_0                  0x228
#define MC_SMMU_TRANSLATION_ENABLE_1_0                  0x22c
#define MC_SMMU_TRANSLATION_ENABLE_2_0                  0x230

void
trustzone_initialize(void)
{
	unsigned int tmp;
	unsigned int tmp1, tmp2;
	nonsecure_fault = 0;

        arndale_gic_dist_init();
	arndale_gic_cpu_init();
	//tmp = 0x1E660;
	tmp = 0x5DC0;
	__asm(" MCR p15, 0, %0, c14, c3, 0"::"r"(tmp));
	__asm("isb sy");
//	tmp1=0x0; 
//	tmp2=0x578B;
//	__asm("mcrr p15, 3, %0, %1, c14"::"r"(tmp2), "r"(tmp1));

	//tmp = 0x5;
	tmp = 0x7;
	__asm("mcr p15, 0, %0, c14, c3, 1"::"r"(tmp)); //enable CNTV_CTL
	__asm("isb sy");
	CP15_SET_VBAR((uint32_t) &vector_table);

}

#define __raw_writeb(v,a)       (*(volatile unsigned char *)(a) = (v))
#define __raw_writew(v,a)       (*(volatile unsigned short *)(a) = (v))
#define __raw_writel(v,a)       (*(volatile unsigned int *)(a) = (v))

#define __raw_readb(a)          (*(volatile unsigned char *)(a))
#define __raw_readw(a)          (*(volatile unsigned short *)(a))
#define __raw_readl(a)          (*(volatile unsigned int *)(a))


#define TZIC0_BASE_ADDR				(0xE5000000)

//#define TZIC_UNLOCK_CODE			(0xACCE550)

#define oINTEN				(0x08)		// TZIC INT EN
#define oFIQEN				(0x0C)		// TZIC FIQ EN
#define oFIQENCLEAR			(0x10)		// TZIC FIQ EN CLEAR
#define oLOCKEN				(0x1C)		// TZIC LOCK EN

#define TZPCR0SIZE					0xE3800000

void tz_communication_handler(void) {
    printk("TZ Communication!!!\n");
    // printk("size : %d\n", tz_communication_get_size());
    // printk("id : %d\n", tz_communication_get_id());
	tz_communication_get_buffer()[tz_communication_get_size()] = '\0';
        printk("buf : %s\n", tz_communication_get_buffer());
	tz_communication_set_ret_value(0);
//	__raw_writel(TZIC_UNLOCK_CODE, TZIC0_BASE_ADDR+oLOCKEN);
//	__raw_writel(0x1FF, TZPCR0SIZE);
//	__raw_writel(0x1, TZIC0_BASE_ADDR+oLOCKEN);
	safeg_switch_to_nt();
}

void tz_pagefault_handler(int lr, int ptb, int addr, int status) {
	printk("TZ pagefault!!!\n");
	printk("pagefault lr : %x\n", lr);
	printk("pagefault ptb : %x\n", ptb);
	printk("pagefault addr : %x\n", addr);
	printk("pagefault status : %x\n", status);
    tz_communication_clear();
//	if (addr==0xF4700000) {
		__raw_writel(TZIC_UNLOCK_CODE, TZIC0_BASE_ADDR+oLOCKEN);
		__raw_writel(0x17, TZPCR0SIZE);
		__raw_writel(0x1, TZIC0_BASE_ADDR+oLOCKEN);
		nonsecure_fault = 0;
//	}
	safeg_switch_to_nt();
}
