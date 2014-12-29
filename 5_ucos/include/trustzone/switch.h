/*
 *  TOPPERS/SafeG Dual-OS monitor
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Safety Gate Dual-OS monitor
 *
 *  Copyright (C) 2009-2011 by Embedded and Real-Time Systems Laboratory
 *     Graduate School of Information Science, Nagoya University, JAPAN
 *
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本?フトウェ
 *  ア（本?フトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本?フトウェアを?ースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形で?ー
 *      スコード中に含まれていること．
 *  (2) 本?フトウェアを，ライブラリ形式など，他の?フトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うド?ュメント（利用
 *      者?ニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本?フトウェアを，機器に組み込むなど，他の?フトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うド?ュメント（利用者?ニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェ?トに
 *        報告すること．
 *  (4) 本?フトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェ?トを免責すること．
 *      また，本?フトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェ?トを
 *      免責すること．
 *
 *  本?フトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェ?トは，本?フトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本?フトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
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
