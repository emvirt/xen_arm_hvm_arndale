/*
 *  TOPPERS/SafeG Dual-OS monitor
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Safety Gate Dual-OS monitor
 *
 *  Copyright (C) 2009-2011 by Embedded and Real-Time Systems Laboratory
 *     Graduate School of Information Science, Nagoya University, JAPAN
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
 */
#ifndef _T_TRUSTZONE_SWITCH_H_
#define _T_TRUSTZONE_SWITCH_H_

#ifndef __ASSEMBLY__

#define T_SMC_SWITCH  0 /* switch to NT */
#define     T_SMC_SWITCH_OK      0 /* no error */
#define     T_SMC_SWITCH_ERR     1 /* error, return to T */
#define     T_SMC_SWITCH_HANDLER 2 /* NT returns, raise safeg handler*/
#define     T_SMC_SWITCH_RET     3 /* NT returns */
#define     T_SMC_SWITCH_SHVAR   4 /* NT returns, arg1 = shared variable */

#define T_SMC_REBOOT  1 /* reboot NT */
#define     T_SMC_REBOOT_OK      0 /* no error */
#define     T_SMC_REBOOT_ERR     1 /* error, return to T */

struct safeg_smc_args {
    int arg0;
    int arg1;
};

extern int nonsecure_fault;

static inline
void safeg_switch_to_nt(/*volatile struct safeg_smc_args *ret_args*/void)
{
struct safeg_smc_args ret_args;
//    ret_args->arg0 = T_SMC_SWITCH_OK;
//    while (1) {
	if (!nonsecure_fault)
	        __asm__ __volatile__("stmfd sp!, {r0, r1}\n\t"
		    "mov r0, %0\n\t"
        	    "mov r1, %1\n\t"
	            "smc 0\n\t"
		    "ldmfd sp!, {r0, r1}\n\t"
	            : /* no output */
	            : "I" (T_SMC_SWITCH), "r" (&ret_args)
	            : "r0", "r1", "memory");
//        if (ret_args->arg0 != T_SMC_SWITCH_OK) return;
//    }
}

static inline void safeg_reboot_nt(void)
{
    __asm__ __volatile__("stmfd sp!, {r0, r1}\n\t"
	"mov r0, %0\n\t"
        "mov r1, #0x8000\n\t"
        "smc 0\n\t"
	"ldmfd sp!, {r0, r1}\n\t"
        : /* no output */
        : "I" (T_SMC_REBOOT)
        : "r0", "r1", "memory");
}

extern void send_timer_interrupt_to_nt(void);
extern void clear_timer_interrupt_to_nt(void);

#endif /* __ASSEMBLY__ */

#endif /* _T_SAFEG_SYSCALLS_H_ */
