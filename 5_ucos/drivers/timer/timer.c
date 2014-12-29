/* linux/arch/arm/plat-s5pc1xx/s5pc1xx-time.c
 *
 * Copyright (C) 2003-2005 Simtec Electronics
 *	Jongpill Lee, <boyko.lee@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * This code is based on plat-s3c/time.c
 */

//#include <os/lib.h>

#define __raw_writeb(v,a)       (*(volatile unsigned char *)(a) = (v))
#define __raw_writew(v,a)       (*(volatile unsigned short *)(a) = (v))
#define __raw_writel(v,a)       (*(volatile unsigned int *)(a) = (v))

#define __raw_readb(a)          (*(volatile unsigned char *)(a))
#define __raw_readw(a)          (*(volatile unsigned short *)(a))
#define __raw_readl(a)          (*(volatile unsigned int *)(a))

#define HZ 10

#define TEGRA_TMR7_BASE			0x60005070

#define TIMER_PTV 0x0
#define TIMER_PCR 0x4

#include <target_gic.h>

#define GIC_DIST_CTRL                   0x000
#define GIC_DIST_CTRL                   0x000
#define GIC_DIST_CTR                    0x004
#define GIC_DIST_SEC0                   0x080

#define GIC_DIST_ENABLE_SET             0x100
#define GIC_DIST_ENABLE_CLEAR           0x180
#define GIC_DIST_PENDING_SET            0x200
#define GIC_DIST_PENDING_CLEAR          0x280
#define GIC_DIST_ACTIVE_BIT             0x300
#define GIC_DIST_PRI                    0x400
#define GIC_DIST_TARGET                 0x800
#define GIC_DIST_CONFIG                 0xc00
#define GIC_DIST_SOFTINT                0xf00


void tegra_timer_init(void)
{
	__raw_writel(0x0, TEGRA_ARM_INT_DIST_BASE+GIC_DIST_CTRL);

        __raw_writel(~(1<<26), TEGRA_ARM_INT_DIST_BASE+GIC_DIST_SEC0+0x10);
	__raw_writel(1<<26, TEGRA_ARM_INT_DIST_BASE+GIC_DIST_ENABLE_SET+0x10);

	__raw_writel(0x1, TEGRA_ARM_INT_DIST_BASE+GIC_DIST_CTRL);
	__raw_writel(0x9, TEGRA_ARM_PERIF_BASE+0x100+GIC_DIST_CTRL);

	__raw_writel(0xC000270F, TEGRA_TMR7_BASE+TIMER_PTV);
}

void tegra_timer_clear(void) {
	__raw_writel(1<<30, TEGRA_TMR7_BASE+TIMER_PCR);
}

void send_timer_interrupt_to_nt(void) {
//	__raw_writel(IRQ_SYSTEM_TIMER_MASK, VIC0_BASE_ADDR+oINTSUBSET);
}
void clear_timer_interrupt_to_nt(void) {
//	__raw_writel(IRQ_SYSTEM_TIMER_MASK, VIC0_BASE_ADDR+oINTSUBMSK);
}
