/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2004-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ��?�եȥ���
 *  ������?�եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) ��?�եȥ�������?���������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη���?��
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) ��?�եȥ������򡤥饤�֥������ʤɡ�¾��?�եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ����?����ȡ�����
 *      ��?�˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) ��?�եȥ������򡤵�����Ȥ߹���ʤɡ�¾��?�եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ����?����ȡ����Ѽ�?�˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ���?�Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) ��?�եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ���?�Ȥ����դ��뤳�ȡ�
 *      �ޤ�����?�եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ���?�Ȥ�
 *      ���դ��뤳�ȡ�
 *
 *  ��?�եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ���?�Ȥϡ���?�եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ�����?�եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 *
 *  @(#) $Id: cm922t.h 264 2007-07-12 08:23:10Z hiro $
 */

#ifndef TOPPERS_PB1176T_H
#define TOPPERS_PB1176T_H

//#include <sil.h>
//#include "../../../safeg/safeg_measures.h" /* TODO: improve this */

/*
 * ������Ԥ�̿��
 */
#define ASM_TARGET_WAIT_INTERRUPT nop


/*
 *  TZIC�˴ؤ������
 */

//#define TZIC_BASE 0x1011f000
#define TZIC_BASE 0xE5000000 // for S5PC100

#define TZIC_STATUS      (TZIC_BASE + 0x00)
#define TZIC_RAWSTATUS   (TZIC_BASE + 0x04)
#define TZIC_INTSELECT   (TZIC_BASE + 0x08)
#define TZIC_ENABLE      (TZIC_BASE + 0x0C)
#define TZIC_CLEAR       (TZIC_BASE + 0x10)
#define TZIC_PROTECTION  (TZIC_BASE + 0x18)
#define TZIC_LOCK        (TZIC_BASE + 0x1C)
#define TZIC_LOCK_STATUS (TZIC_BASE + 0x20)

#define TZIC_UNLOCK_CODE 0x0ACCE550
#define TZIC_LOCK_CODE   0x00000000


#define TZIC0_BASE			0xE5000000
#define TZIC0_STATUS 		(TZIC0_BASE + 0x00)
#define TZIC0_RAWSTATUS 	(TZIC0_BASE + 0x04)
#define TZIC0_INTSELECT		(TZIC0_BASE + 0x08)
#define TZIC0_ENABLE		(TZIC0_BASE + 0x0C)
#define TZIC0_CLEAR			(TZIC0_BASE + 0x10)
#define TZIC0_PROTECTION	(TZIC0_BASE + 0x18)
#define TZIC0_LOCK			(TZIC0_BASE + 0x1C)
#define TZIC0_LOCK_STATUS	(TZIC0_BASE + 0x20)

#define TZIC1_BASE			0xE5100000
#define TZIC1_STATUS 		(TZIC1_BASE + 0x00)
#define TZIC1_RAWSTATUS 	(TZIC1_BASE + 0x04)
#define TZIC1_INTSELECT		(TZIC1_BASE + 0x08)
#define TZIC1_ENABLE		(TZIC1_BASE + 0x0C)
#define TZIC1_CLEAR			(TZIC1_BASE + 0x10)
#define TZIC1_PROTECTION	(TZIC1_BASE + 0x18)
#define TZIC1_LOCK			(TZIC1_BASE + 0x1C)
#define TZIC1_LOCK_STATUS	(TZIC1_BASE + 0x20)

#define TZIC2_BASE			0xe5200000
#define TZIC2_STATUS 		(TZIC2_BASE + 0x00)
#define TZIC2_RAWSTATUS 	(TZIC2_BASE + 0x04)
#define TZIC2_INTSELECT		(TZIC2_BASE + 0x08)
#define TZIC2_ENABLE		(TZIC2_BASE + 0x0C)
#define TZIC2_CLEAR			(TZIC2_BASE + 0x10)
#define TZIC2_PROTECTION	(TZIC2_BASE + 0x18)
#define TZIC2_LOCK			(TZIC2_BASE + 0x1C)
#define TZIC2_LOCK_STATUS	(TZIC2_BASE + 0x20)


/*
 * FPGA tzpc registers
 */
#define FPGA_TZPCDECPROT0Stat    0x10003800
#define FPGA_TZPCDECPROT0Set     0x10003804
#define FPGA_TZPCDECPROT0Clr     0x10003808
#define FPGA_TZPCDECPROT1Stat    0x1000380C
#define FPGA_TZPCDECPROT1Set     0x10003810
#define FPGA_TZPCDECPROT1Clr     0x10003814
#define FPGA_TZPCDECPROT2Stat    0x10003818
#define FPGA_TZPCDECPROT2Set     0x1000381C
#define FPGA_TZPCDECPROT2Clr     0x10003820
#define FPGA_TZPCDECPROT3Stat    0x10003824
#define FPGA_TZPCDECPROT3Set     0x10003828
#define FPGA_TZPCDECPROT3Clr     0x1000382C

/*
* dev-chip tzpc registers for pb1176
*/
/*
#define TZPCR0SIZE          0x10101000
#define TZPCDECPROT0Stat    0x10101800
#define TZPCDECPROT0Set     0x10101804
#define TZPCDECPROT0Clr     0x10101808
#define TZPCDECPROT1Stat    0x1010180C
#define TZPCDECPROT1Set     0x10101810
#define TZPCDECPROT1Clr     0x10101814
#define TZPCDECPROT2Stat    0x10101818
#define TZPCDECPROT2Set     0x1010181C
#define TZPCDECPROT2Clr     0x10101820
*/

//New Version of S5PC100 TZPC Registers

#define TZPCR0SIZE					0xE3800000
#define TZPC0_TZPCDECPROT0Stat		0xE3800800
#define TZPC0_TZPCDECPROT0Set		0xE3800804
#define TZPC0_TZPCDECPROT0Clr		0xE3800808
#define TZPC0_TZPCDECPROT1Stat		0xE380080C
#define TZPC0_TZPCDECPROT1Set		0xE3800810
#define TZPC0_TZPCDECPROT1Clr		0xE3800814
//not Used 
#define TZPC0_TZPCDECPROT2Stat		0xE3800818
#define TZPC0_TZPCDECPROT2Set		0xE380081C
#define TZPC0_TZPCDECPROT2Clr		0xE3800820

#define TZPC1_TZPCDECPROT0Stat		0xE2800800
#define TZPC1_TZPCDECPROT0Set		0xE2800804
#define TZPC1_TZPCDECPROT0Clr		0xE2800808
#define TZPC1_TZPCDECPROT1Stat		0xE280080C
#define TZPC1_TZPCDECPROT1Set		0xE2800810
#define TZPC1_TZPCDECPROT1Clr		0xE2800814
#define TZPC1_TZPCDECPROT2Stat		0xE2800818
#define TZPC1_TZPCDECPROT2Set		0xE280081C
#define TZPC1_TZPCDECPROT2Clr		0xE2800820

#define TZPC2_TZPCDECPROT0Stat		0xE2900800
#define TZPC2_TZPCDECPROT0Set		0xE2900804
#define TZPC2_TZPCDECPROT0Clr		0xE2900808
#define TZPC2_TZPCDECPROT1Stat		0xE290080C
#define TZPC2_TZPCDECPROT1Set		0xE2900810
#define TZPC2_TZPCDECPROT1Clr		0xE2900814
#define TZPC2_TZPCDECPROT2Stat		0xE2900818
#define TZPC2_TZPCDECPROT2Set		0xE290081C
#define TZPC2_TZPCDECPROT2Clr		0xE2900820





/*
 * ����ߥϥ�ɥ��ֹ椫�顤IRC���Τ���Υӥåȥ�?��������??��
 */
#define INTNO_BITPAT(intno) (1U << intno)


/*
 *  UART�˴ؤ������
 */
#if 0
#define UART0_BASE_REG    0x1010c000
#define UART1_BASE_REG    0x1010d000
#define UART2_BASE_REG    0x1010e000
#define UART3_BASE_REG    0x1010f000
#endif

/*
 *  linux �� UART0 ����Ѥ��뤿��, ?���ɤ� UART1, UART2 ��
 *  ASP �� SIO0, SIO1 �Ȥ��ƻ��Ѥ���
 */
#define UART0_BASE_REG    0x1010d000
#define UART1_BASE_REG    0x1010e000

/*
 *  ?����󥰽��Ϥǻ��Ѥ���?����
 */
#define PB1176_PUTC_BASE_REG UART0_BASE_REG

/*
 * UART Control Registers
 */
#define UART_PL011_DR			 0x000
#define UART_PL011_SR_CR		 0x004
#define UART_PL011_FR			 0x018
#define UART_PL011_LPR			 0x020
#define UART_PL011_IBRD			 0x024
#define UART_PL011_FBRD			 0x028
#define UART_PL011_LCR_H		 0x02C
#define UART_PL011_CR	 		 0x030
#define UART_PL011_IFLS			 0x034
#define UART_PL011_IMSC			 0x038
#define UART_PL011_RIS			 0x03C
#define UART_PL011_MIS			 0x040
#define UART_PL011_ICR			 0x044
#define UART_PL011_DMACR		 0x048

/*
 * Flag Register Constants : UARTx_FR
 */
/*[7] Transmit FIFO Empty*/
#define UFR_TXFE    0x80
/*[6] Receive FIFO Full*/
#define UFR_RXFF    0x40
/*[5] Transmit FIFO Full*/
#define UFR_TXFF    0x20
/*[4] Receive FIFO Empty*/
#define UFR_RXFE    0x10
/*[3] UART Busy*/
#define UFR_BUSY    0x08
/*[2] Data Carrier Detect*/
#define UFR_DCD     0x04
/*[1] Data Set Ready*/
#define UFR_DSR     0x02
/*[0] Clear To Send*/
#define UFR_CTS     0x01

#define UART_IMSC_RXIM 0x0010 /* ���������?��?          */
#define UART_IMSC_TXIM 0x0020 /* ���������?��?          */

/*
 *  UART������ֹ�
 */
#define IRQNO_UART0    18
#define IRQNO_UART1    19
#define IRQNO_UART2    20
#define IRQNO_UART3    21

/*
 *  ?��?����Ϣ
 */
#define TIMER_BASE_REG         0x10105000
#define OVRTIMER_BASE_REG      0x10106000

#define TIMER_SP804_1LOAD		0x000
#define TIMER_SP804_1VALUE		0x004
#define TIMER_SP804_1CONTROL	0x008
#define TIMER_SP804_1CLEAR		0x00C
#define TIMER_SP804_1RIS		0x010
#define TIMER_SP804_2LOAD		0x020
#define TIMER_SP804_2VALUE		0x024
#define TIMER_SP804_2CONTROL	0x028
#define TIMER_SP804_2CLEAR		0x02C

#define OVRTIMER_SP804_CONTROL_BITS  0x23
#define OVRTIMER_SP804_CONTROL_ENA   0x80

#if ASP_MEASURE_TIMER_LAT == 1
#define IRQNO_TIMER            7 /* performance measurement timer interrupt */
#else
#define IRQNO_TIMER            9
#endif
#define IRQNO_OVRTIMER         10

#ifndef TOPPERS_MACRO_ONLY

/*
 * ���ץ�ؤΥ�??��??��
 */
#define CP15_CONTROL_READ(x)     __asm__ __volatile__("mrc p15, 0, %0, c1, c0, 0":"=r"(x))
#define CP15_CONTROL_WRITE(x)    __asm__ __volatile__("mcr p15, 0, %0, c1, c0, 0"::"r"(x))

#define CP15_AUXILIARY_READ(x)   __asm__ __volatile__("mrc p15, 0, %0, c1, c0, 1":"=r"(x))
#define CP15_AUXILIARY_WRITE(x)  __asm__ __volatile__("mcr p15, 0, %0, c1, c0, 1"::"r"(x))

#define CP15_CACHE_INVALIDATE_BOTH() __asm__ __volatile__("mcr p15, 0, %0, c7, c7, 0":: "r"(0))
#define CP15_ICACHE_INVALIDATE() __asm__ __volatile__("mcr p15, 0, %0, c7, c5, 0"::"r"(0))
#define CP15_DCACHE_INVALIDATE() __asm__ __volatile__("mcr p15, 0, %0, c7, c6, 0"::"r"(0))
#define CP15_DCACHE_CLEAN_AND_INVALIDATE() \
	__asm__ __volatile__("mcr p15, 0, %0, c7, c14, 0":: "r"(0))
#define CP15_PBUFFER_FLUSH()     __asm__ __volatile__("mcr p15, 0, %0, c7, c5, 4"::"r"(0))
#define CP15_DATA_SYNC_BARRIER() __asm__ __volatile__("mcr p15, 0, %0, c7, c10, 4"::"r"(0))
#define CP15_DATA_MEMORY_BARRIER() __asm__ __volatile__("mcr p15, 0, %0, c7, c10, 5"::"r" (0));

#define CP15_INVALIDATE_UNIFIED_TLB() __asm__ __volatile__("mcr p15, 0, %0, c8, c7, 0"::"r"(0))

#define CP15_TTBCR_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c2, c0, 2"::"r"(x))
#define CP15_TTB0_READ(x)   __asm__ __volatile__("mrc p15, 0, %0, c2, c0, 0":"=r"(x))
#define CP15_TTB0_WRITE(x)  __asm__ __volatile__("mcr p15, 0, %0, c2, c0, 0"::"r"(x))

#define CP15_DOMAINS_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c3, c0, 0":: "r"(x))

#define CP15_SET_VBAR(x)    __asm__ __volatile__("mcr p15, 0, %0, c12, c0, 0"::"r"(x))

#define CP15_PM_CONTROL_READ(x) __asm__ __volatile__("mrc p15, 0, %0, c15, c12, 0":"=r"(x))
#define CP15_PM_CONTROL_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c15, c12, 0"::"r"(x))
#define CP15_PM_CYCLE_READ(x) __asm__ __volatile__("mrc p15, 0, %0, c15, c12, 1":"=r"(x))
#define CP15_PM_CYCLE_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c15, c12, 1"::"r"(x))
#define CP15_PM_CR0_READ(x) __asm__ __volatile__("mrc p15, 0, %0, c15, c12, 2":"=r"(x))
#define CP15_PM_CR0_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c15, c12, 2"::"r"(x))
#define CP15_PM_CR1_READ(x) __asm__ __volatile__("mrc p15, 0, %0, c15, c12, 3":"=r"(x))
#define CP15_PM_CR1_WRITE(x) __asm__ __volatile__("mcr p15, 0, %0, c15, c12, 3"::"r"(x))

#define CP15_TCM_STATUS_READ(x) __asm__ __volatile__("mrc p15, 0, %0, c0, c0, 2":"=r"(x))
#define CP15_TCM_SEL_READ(x)    __asm__ __volatile__("mrc p15, 0, %0, c9, c2, 0":"=r"(x))
#define CP15_TCM_SEL_WRITE(x)   __asm__ __volatile__("mcr p15, 0, %0, c9, c2, 0"::"r"(x))
#define CP15_DTCM_REG_READ(x)   __asm__ __volatile__("mrc p15, 0, %0, c9, c1, 0":"=r"(x))
#define CP15_DTCM_REG_WRITE(x)  __asm__ __volatile__("mcr p15, 0, %0, c9, c1, 0"::"r"(x))
#define CP15_ITCM_REG_READ(x)   __asm__ __volatile__("mrc p15, 0, %0, c9, c1, 1":"=r"(x))
#define CP15_ITCM_REG_WRITE(x)  __asm__ __volatile__("mcr p15, 0, %0, c9, c1, 1"::"r"(x))
#define CP15_DTCM_NS_READ(x)    __asm__ __volatile__("mrc p15, 0, %0, c9, c1, 2":"=r"(x))
#define CP15_DTCM_NS_WRITE(x)   __asm__ __volatile__("mcr p15, 0, %0, c9, c1, 2"::"r"(x))
#define CP15_ITCM_NS_READ(x)    __asm__ __volatile__("mrc p15, 0, %0, c9, c1, 3":"=r"(x))
#define CP15_ITCM_NS_WRITE(x)   __asm__ __volatile__("mcr p15, 0, %0, c9, c1, 3"::"r"(x))

#define CP15_VALIDATION_REG_WRITE(x)  __asm__ __volatile__("mcr p15, 0, %0, c15, c9, 0"::"r"(x))

/*
 * TCM mapping addresses (continuously mapped +0x1000 (4Kb))
 * NOTE: must be the same as in pb1176nt.h
 */

#define TCM_BASE_ADDRESS  0x70000000
#define ITCM0_ADDRESS     TCM_BASE_ADDRESS
#define ITCM1_ADDRESS     (TCM_BASE_ADDRESS + 0x1000)
#define DTCM0_ADDRESS     (TCM_BASE_ADDRESS + 0x2000)
#define DTCM1_ADDRESS     (TCM_BASE_ADDRESS + 0x3000)

/*
 * ���ץ�Υӥå����
 */
#define CP15_CONTROL_XP_BIT   (1 << 23)
#define CP15_CONTROL_I_BIT    (1 << 12)
#define CP15_CONTROL_C_BIT    (1 <<  2)
#define CP15_CONTROL_M_BIT    (1 <<  0)

#define CP15_TTB0_C           (1 << 0)
#define CP15_TTB0_S           (1 << 1)
#define CP15_TTB0_RGN_WBWA    (1 << 3)

#if 0
/*
 * ���ץ���Ѥ����롼����
 */

/*
 *  Data Synchronization Barrier
 *  �����ȯ�Ԥ��줿 read �� write �ν�λ���Ԥ�
 *  ��?��å��塤�֥����ץ�ǥ�?�����TLB�����ν�λ���Ԥ�
 *  ������̿��θ�˽񤫤줿̿��ϼ¹Ԥ���ʤ�
 */
Inline void
pb1176_data_sync_barrier(void){
    CP15_DATA_SYNC_BARRIER();
}

/*
 * Data Memory Barrier
 * ���ץ���?�ε��Ҥ˽��äơ���˽񤫤줿̿��ǤΥ��ꥢ??����
 *   ��λ����ޤ��Ԥġ�
 *
 */
Inline void
pb1176_data_memory_barrier(void){
    CP15_DATA_MEMORY_BARRIER();
}

/*
 * TLB��̵����
 */
Inline void
pb1176_invalidate_unfied_tlb(void){
    CP15_DATA_SYNC_BARRIER();
}


/*
 * D?��å����̵����
 */
Inline void
pb1176_dcache_invalidate(void){
    CP15_DCACHE_INVALIDATE();
}


/*
 * D?��å����?�꡼���̵����
 */
Inline void
pb1176_dcache_clean_and_invalidate(void){
    CP15_DCACHE_CLEAN_AND_INVALIDATE();
}


/*
 * I?��å����̵����
 */
Inline void
pb1176_icache_invalidate(void){
    CP15_ICACHE_INVALIDATE();
}

/*
 * �ץ�ե��å��Хåե���?�ꥢ
 */
Inline void
pb1176_pbuffer_flash(void){
    CP15_PBUFFER_FLUSH();
}
/*
 * TZIC���ؿ�
 */

/*
 * �쥸��?�Υ�����?
 */
Inline void
tzic_unlock(void){
	sil_wrw_mem((void *)TZIC_LOCK,  TZIC_UNLOCK_CODE);
}

/*
 * �쥸��?�Υ��?
 */
Inline void
tzic_lock(void){
	sil_wrw_mem((void *)TZIC_LOCK,  TZIC_LOCK_CODE);
}

/*
 * ������׵�򥹥롼����irq������Ϥ���
 */
Inline void
tzic_pass_through_irqout(uint32_t mask){
	tzic_unlock();

	sil_wrw_mem((void *)TZIC_INTSELECT,
				sil_rew_mem((void *)TZIC_INTSELECT) &  ~mask);
	tzic_lock();
}

/*
 * ������׵��?��?
 */
Inline void
tzic_disable_int(uint32_t mask)
{
	tzic_unlock();
	sil_wrw_mem((void *)TZIC_CLEAR,
				sil_rew_mem((void *)TZIC_CLEAR) | mask);
	tzic_lock();
}

/*
 * ������׵��?��?�β��
 */
Inline void
tzic_enable_int(uint32_t mask)
{
	tzic_unlock();
    sil_wrw_mem((void *)TZIC_ENABLE,
				sil_rew_mem((void *)TZIC_ENABLE) | mask);
	tzic_lock();
}

/*
 * ������׵��?�ꥢ
 */
Inline void
tzic_clear_int(uint32_t mask)
{

}

/*
 * ������׵�Υ�����?
 */
Inline bool_t
tzic_probe_int(uint32_t mask)
{
    return((sil_rew_mem((void *)TZIC_STATUS) & mask) == mask);
}

/*
 * Interrupt Raw status (before masked)
 */
Inline bool_t
tzic_probe_raw_int(uint32_t mask)
{
    return((sil_rew_mem((void *)TZIC_RAWSTATUS) & mask) == mask);
}

Inline uint32_t
tzic_get_raw_status()
{
    return sil_rew_mem((void *)TZIC_RAWSTATUS);
}

/*
 * FIQ��ȯ�����Ȥ����Ѥ���
 */
Inline void
tzic_use_fiq_gen(uint32_t mask){
    tzic_unlock();
    sil_wrw_mem((void *)TZIC_INTSELECT,
				sil_rew_mem((void *)TZIC_INTSELECT)| mask);
    tzic_lock();
}

#endif
inline void
s5pc100_tzpc_init(void)
{
	*((unsigned int *) TZPCR0SIZE) = 0x1FF;

/*	*((unsigned int *) TZPC0_TZPCDECPROT0Set) = 0xFF;
	*((unsigned int *) TZPC0_TZPCDECPROT1Set) = 0x10;


	*((unsigned int *) TZPC1_TZPCDECPROT0Set) = 0xFF;
	*((unsigned int *) TZPC1_TZPCDECPROT1Set) = 0xFF;
	*((unsigned int *) TZPC1_TZPCDECPROT2Set) = 0xF;

	*((unsigned int *) TZPC2_TZPCDECPROT0Set) = 0xFF;
	*((unsigned int *) TZPC2_TZPCDECPROT1Set) = 0xFF;*/
//	*((unsigned int *) TZPC2_TZPCDECPROT2Set) = 0xF;
	*((unsigned int *) TZPC0_TZPCDECPROT0Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC0_TZPCDECPROT1Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC0_TZPCDECPROT2Set) = 0xFFFFFFFF;

	*((unsigned int *) TZPC1_TZPCDECPROT0Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC1_TZPCDECPROT1Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC1_TZPCDECPROT2Set) = 0xFFFFFFFF;

	*((unsigned int *) TZPC2_TZPCDECPROT0Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC2_TZPCDECPROT1Set) = 0xFFFFFFFF;
	*((unsigned int *) TZPC2_TZPCDECPROT2Set) = 0xFFFFFFFF;



}

#if 0
Inline void
pb1176t_tzpc_init(void)
{
	/*
	*  all the 512KB SRAM for SafeG + T-ASP is secure
	*  realview: ce ((unsigned long *)S:0x10101000)[0]=0xFF
	*/
	*((unsigned int *) TZPCR0SIZE) = 0x1FF;
	
	/*
	* dev-chip tzpc is limited nonsecure setting
	* timers 2/3/4/5, uart 1,2 and tzic are secure
	* realview:
	* ce ((unsigned long *)S:0x10101804)[0]=0x9F9D
	* ce ((unsigned long *)S:0x10101810)[0]=0x3FFF
	* ce ((unsigned long *)S:0x1010181C)[0]=0x007F
	*/
	*((unsigned int *) TZPCDECPROT0Set) = 0x9F9D;
	*((unsigned int *) TZPCDECPROT1Set) = 0x3FFF;
	*((unsigned int *) TZPCDECPROT2Set) = 0x007F;
	
	/*
	* fpga tzpc is all non-secure setting
	* realview:
	* ce ((unsigned long *)S:0x10003804)[0]=0x00FF
	* ce ((unsigned long *)S:0x10003810)[0]=0x00FF
	* ce ((unsigned long *)S:0x1000381C)[0]=0x000F
	*/
	*((unsigned int *) FPGA_TZPCDECPROT0Set) = 0x00FF;
	*((unsigned int *) FPGA_TZPCDECPROT1Set) = 0x00FF;
	*((unsigned int *) FPGA_TZPCDECPROT2Set) = 0x000F;
}


/*
 * ?���ͥ뵯ư���Υ������Ѥν����
 */
Inline void
pb1176t_init_uart(void)
{
	/*
	 * setup baud rate divisor (38400bps)
	 */
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_IBRD), 0x27);
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_FBRD), 0x04);

	/* refer to the TRM for details */
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_CR), 0x301);
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_LCR_H), 0x060);
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_IFLS), 0x000);

	/* Mask all interrupt */
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_IMSC), 0);
}

/*
 *  UART�����?����󥰽���
 */
Inline void
pb1176t_putc(char_t c)
{
	while((sil_rew_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_FR)) & UFR_TXFF) == UFR_TXFF);
	sil_wrw_mem((void *)(PB1176_PUTC_BASE_REG + UART_PL011_DR), c);
}

/*
 * TCM initialization (after initialization, cache must be invalidated)
 */
Inline void
pb1176t_init_tcm(void)
{
	// Set both DTCM and ITCM to Non-Secure
	CP15_TCM_SEL_WRITE(0);
	CP15_DTCM_NS_WRITE(1);
	CP15_ITCM_NS_WRITE(1);

	CP15_TCM_SEL_WRITE(1);
	CP15_DTCM_NS_WRITE(1);
	CP15_ITCM_NS_WRITE(1);

	// Map TCM and enable
	CP15_TCM_SEL_WRITE(0);
	CP15_DTCM_REG_WRITE(DTCM0_ADDRESS | 1);
	CP15_ITCM_REG_WRITE(ITCM0_ADDRESS | 1);

	CP15_TCM_SEL_WRITE(1);
	CP15_DTCM_REG_WRITE(DTCM1_ADDRESS | 1);
	CP15_ITCM_REG_WRITE(ITCM1_ADDRESS | 1);
}

/*
 * ��λ����
 */
Inline void
pb1176t_exit(void)
{

}
#endif 

#endif /* TOPPPERS_MACRO_ONLY */
#endif /* TOPPERS_CM922T_H */
