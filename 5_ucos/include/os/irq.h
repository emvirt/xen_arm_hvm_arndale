#ifndef __IRQ_H__
#define __IRQ_H__

//#include <os/os.h>

#if 0
// jjw
#define barrier() __asm__ __volatile__("": : :"memory")

#define mb() __asm__ __volatile__ ("" : : : "memory")
#define rmb()   mb()
#define wmb()	mb()
#else
#define barrier() __asm__ __volatile__("": : :"memory")

#define mb() __asm__ __volatile__ ("dmb": : : "memory")
#define dsb() __asm__ __volatile__ ("dsb" dmb: : : "memory")
#define rmb()   mb()
#define	wmb()	mb()
#endif

/* 
 * The use of 'barrier' in the following reflects their use as local-lock
 * operations. Reentrancy must be prevented (e.g., __cli()) /before/ following
 * critical operations are executed. All critical operations must complete
 * /before/ reentrancy is permitted (e.g., __sti()). Alpha architecture also
 * includes these barriers, for example.
 */

#define raw_local_irq_save(x)                                   \
        ({                                                      \
        __asm__ __volatile__(                                   \
        "mrs    %0, cpsr                @ local_irq_save\n"     \
        "cpsid  f\n"                                            \
        "cpsid  i\n"                                            \
        : "=r" (x) : : "memory", "cc");                         \
        })

#define raw_local_irq_enable()  __asm__("cpsie i        @ __sti" : : : "memory", "cc")
#define raw_local_irq_disable() __asm__("cpsid i        @ __cli" : : : "memory", "cc")


#define raw_local_save_flags(x)                                 \
        ({                                                      \
        __asm__ __volatile__(                                   \
        "mrs    %0, cpsr                @ local_save_flags"     \
        : "=r" (x) : : "memory", "cc");                         \
        })

#define raw_local_irq_restore(x)                                \
        __asm__ __volatile__(                                   \
        "msr    cpsr_c, %0              @ local_irq_restore\n"  \
        :                                                       \
        : "r" (x)                                               \
        : "memory", "cc")


#define safe_halt()		((void)0)

#define local_irq_save(x)	raw_local_irq_save(x)
#define local_irq_restore(x)	raw_local_irq_restore(x)
#define local_save_flags(x)	raw_local_save_flags(x)
#define local_irq_disable()	raw_local_irq_disable()
#define local_irq_enable()	raw_local_irq_enable()

/*
 * Make sure gcc doesn't try to be clever and move things around
 * on us. We need to use _exactly_ the address the user gave us,
 * not some alias that contains the same information.
 */
typedef struct { volatile int counter; } atomic_t;

//#define cpu_idle() __asm__ __volatile__ ("wfi": : : "memory")
#define cpu_idle()				\
	{					\
		int x;				\
		local_irq_save(x);		\
/*		safeg_switch_to_nt();		*/\
		local_irq_restore(x);		\
	}

#endif
