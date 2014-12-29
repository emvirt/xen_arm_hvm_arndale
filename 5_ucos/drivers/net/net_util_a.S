.global NetUtil_16BitSumDataCalcAlign_32
.align 0
NetUtil_16BitSumDataCalcAlign_32:
        STMFD       SP!, {R2-R12}

        MOV         R2, #0
        B           NetUtil_16BitSumDataCalcAlign_32_0

NetUtil_16BitSumDataCalcAlign_32_1:
        LDMIA       R0!, {R5-R12}                           //; Calc sum of sixteen 16-bit words ...
							//; ... using eight 32-bit CPU regs.

        MOV         R3, R5, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R5, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R6, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R6, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R7, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R7, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R8, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R8, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R9, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R9, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R10, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R10, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R11, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R11, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2


        MOV         R3, R12, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R12, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        SUB         R1, R1, #(32) //4*8*1)

NetUtil_16BitSumDataCalcAlign_32_0:
        CMP         R1, #(32) //4*8*1)                            //; end of loop
        BCS         NetUtil_16BitSumDataCalcAlign_32_1

        B           NetUtil_16BitSumDataCalcAlign_32_2


NetUtil_16BitSumDataCalcAlign_32_3:
        LDMIA       R0!, {R5}                               //; Calc sum of two 16-bit words ...
                                                            //; ... using   one 32-bit CPU reg.

        MOV         R3, R5, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        MOV         R3, R5, LSL #16
        MOV         R3, R3, LSR #16
        MOV         R4, R3, LSR #8
        AND         R3, R3, #0xFF
        ORR         R4, R4, R3, LSL #8
        ADD         R2, R4, R2

        SUB         R1, R1, #(4) //4*1*1)

NetUtil_16BitSumDataCalcAlign_32_2:

        CMP         R1, #(4) //4*1*1)                            //; end of loop
        BCS         NetUtil_16BitSumDataCalcAlign_32_3

        MOV         R0, R2
        LDMFD       SP!, {R2-R12}
        BX          LR                                      //; return



