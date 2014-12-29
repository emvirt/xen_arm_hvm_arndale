#include <os/config.h>

.section __xen_guest
	.ascii	"GUEST_OS=uC_OS_II"
	.ascii 	",XEN_VER=xen-3.0"
	.ascii	",VIRT_BASE=0x0"
	.ascii	",ELF_PADDR_OFFSET=0x0"  
	.ascii	",HYPERCALL_PAGE=0x8"
	.ascii	",LOADER=generic"
	.text

.global hypercall_page, shared_info

	cps     0x12 //#CPSR_MODE_IRQ
	ldr	sp, __init_sp_irq
	cps     0x13 //#CPSR_MODE_SVC 
        ldr     sp, __init_sp_svc

        b       sta_ker

        
__init_sp_svc:
        .long __stack_end + 0x400
__init_sp_irq:
        .long __stack_end + 0x200



//__init_sp:
//	.long __stack_end + 0x1000

//	.org 0x1000

shared_info:
	.org 0x2000

hypercall_page:
	.org 0x3000

//        .org 0x1000

//.section ".bss.stack_aligned","w"
__stack_end:
       .fill 0x400,1,0  @ 4KB
//	.org 0x1000




/*

ENTRY(shared_info)
	.fill 0x8000,1,0	@ 32KB

.section ".bss.stack_aligned","w"
__stack_end:
	.fill 0x1000,1,0	@ 8KB
*/


/*
	cps     0x12 //#CPSR_MODE_IRQ
	ldr	sp, __init_sp_irq
	cps     0x13 //#CPSR_MODE_SVC 
        ldr     sp, __init_sp_svc

        b       sta_ker

__init_sp_svc:
        .long __stack_end + 0x400
__init_sp_irq:
        .long __stack_end + 0x200

//        .org 0x1000

.section ".bss.stack_aligned","w"
__stack_end:
        .fill 0x400,1,0  @ 4KB
*/


