/* wroted by YSB */

/*4Byte Move Macro*/
.macro mov32, reg, val
        movw    \reg, #:lower16:\val
        movt    \reg, #:upper16:\val
.endm
/*4Byte Moveeq Macro*/
.macro mov32eq, reg, val
        movweq    \reg, #:lower16:\val
        movteq    \reg, #:upper16:\val
.endm
/*4Byte Moveeq Macro*/
.macro mov32ne, reg, val
        movwne    \reg, #:lower16:\val
        movtne    \reg, #:upper16:\val
.endm


.macro  cpu_id, rd
        mrc     p15, 0, \rd, c0, c0, 5
        and     \rd, \rd, #0xF
.endm

        .global secondary_startup
secondary_startup:
        cpu_id  r0
	mov32   r2, 0x80010EA0 /*safeg_now_init_core*/
secondary_startup_loop:
	ldr	r1, [r2]
	cmp	r0, r1
	bne	secondary_startup_loop

	mov32	r1, 0x80010E40 /*SafeGSecondaryBoot*/

	cmp	r0, #0x1
	mov32eq	r0, 0x94010d7c /*boot loader start addr*/
        mov32ne	r0, 0x900691c0 /* linux - tegra_secondary_startup */
	mov	pc, r1

secondary_wait:
	cpsie	i
secondary_wait_loop:
	wfi
	b	secondary_wait_loop
