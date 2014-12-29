	.align 5
    .globl vector_table
vector_table:
    b vector_reset       /* ¥ê¥»¥Ã¥È             */
    b vector_und       /* Ì¤ÄêµÁÌ¿Îá           */
    b vector_swi         /* ¥½¥Õ¥È¥¦¥§¥¢³ä¹þ¤ß   */
    b vector_pabt     /* ¥×¥ê¥Õ¥§¥Ã¥Á¥¢¥Ü¡¼¥É */
    b vector_dabt  /* ¥Ç¡¼¥¿¥¢¥Ü¡¼¥É       */
    b vector_addrexcptn
    b vector_irq         /* IRQ                  */
    b vector_fiq         /* FIQ                  */
    b vector_safeg       /* SAFEG                */

	.align 5
	.global vector_reset
vector_reset:
	b	.


	.align 5
	.global vector_und
vector_und:
	b	.


	.align 5
	.global vector_swi
vector_swi:
	cpsie	f
//	stmfd	sp!, {r0, r1}
	ldr	r2, =nonsecure_fault
	mov	r3, #1
	str	r3, [r2]
	mrc     p15, 0, r3, c5, c0, 0	/* get FSR */
	mrc     p15, 0, r2, c6, c0, 0	/* get FAR */
	bl	tz_pagefault_handler
//	ldmfd	sp!, {r0, r1}
//	b	.
	mov	pc, lr

	.align 5
	.global vector_pabt
vector_pabt:
	b	.


	.align 5
	.global vector_dabt
vector_dabt:
	b	.


	.align 5
	.global vector_addrexcptn
vector_addrexcptn:
	b	.


	.align 5
	.global vector_irq
vector_irq:
#ifdef PROFILE_IRQ_LATENCY
	//mov	r5, #0x3005
	//movt	r5, #0x410F
	ldr	r5, =0x80000000
	mcr	p15, 0, r5, c9, c12, 1 //Enable Count Enable Set Register
	ldr  	r5, =0x410f3005
	mcr	p15, 0, r5, c9, c12, 0 //Enable PMU
#endif
	b	OS_CPU_ARM_ExceptIrqHndlr


	.align 5
	.global vector_fiq
vector_fiq:
	b	.

vector_safeg:
	b	.
