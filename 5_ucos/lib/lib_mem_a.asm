.global Mem_Copy
.align 0
Mem_Copy:
        CMP         R0, #0
        MOVEQ       PC, LR                  ; return if pdest == NULL

        CMP         R1, #0
        MOVEQ       PC, LR                  ; return if psrc  == NULL

        CMP         R2, #0
        MOVEQ       PC, LR                  ; return if size  == 0

        STMFD       SP!, {R3-R12}           ; save registers on stack


Check_Align_32:                             ; check if both dest & src 32-bit aligned
        AND         R3, R0, #0x03
        AND         R4, R1, #0x03
        CMP         R3, R4
        BNE         Check_Align_16          ; not 32-bit aligned, check for 16-bit alignment

        RSB         R3, R3, #0x04           ; compute 1-2-3 pre-copy bytes (to align to the next 32-bit boundary)
        AND         R3, R3, #0x03

Pre_Copy_1:
        CMP         R3, #1                  ; copy 1-2-3 bytes (to align to the next 32-bit boundary)
        BCC         Copy_32_1               ; start real 32-bit copy
        CMP         R2, #1                  ; if no more data to copy (security if R2 < R3)
        BCC         Mem_Copy_END            ; goto END

        LDRB        R4, [R1], #1
        STRB        R4, [R0], #1
        SUB         R3, R3, #1
        SUB         R2, R2, #1
        B           Pre_Copy_1

Check_Align_16:                             ; check if both dest & src 16-bit aligned
        AND         R3, R0, #0x01
        AND         R4, R1, #0x01
        CMP         R3, R4
        BNE         Copy_08_1               ; not 16-bit aligned, start 8-bit copy

Pre_Copy_2:
        CMP         R3, #1                  ; copy 1 byte (to align to the next 16-bit boundary)
        BCC         Copy_16_1               ; start real 16-bit copy

        LDRB        R4, [R1], #1
        STRB        R4, [R0], #1
        SUB         R3, R3, #1
        SUB         R2, R2, #1
        B           Pre_Copy_2

Copy_32_1:
        CMP         R2, #(04*10*09)         ; Copy 9 chunks of 10 32-bit words (360 octets per loop)
        BCC         Copy_32_2
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        SUB         R2, R2, #(04*10*09)
        B           Copy_32_1

Copy_32_2:
        CMP         R2, #(04*10*01)         ; Copy chunks of 10 32-bit words (40 octets per loop)
        BCC         Copy_32_3
        LDMIA       R1!, {R3-R12}
        STMIA       R0!, {R3-R12}
        SUB         R2, R2, #(04*10*01)
        B           Copy_32_2

Copy_32_3:
        CMP         R2, #(04*01*01)         ; Copy remaining 32-bit words
        BCC         Copy_16_1
        LDR         R3, [R1], #4
        STR         R3, [R0], #4
        SUB         R2, R2, #(04*01*01)
        B           Copy_32_3

Copy_16_1:
        CMP         R2, #(02*01*16)         ; Copy chunks of 16 16-bit words (32 bytes per loop)
        BCC         Copy_16_2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        SUB         R2, R2, #(02*01*16)
        B           Copy_16_1

Copy_16_2:
        CMP         R2, #(02*01*01)         ; Copy remaining 16-bit words
        BCC         Copy_08_1
        LDRH        R3, [R1], #2
        STRH        R3, [R0], #2
        SUB         R2, R2, #(02*01*01)
        B           Copy_16_2

Copy_08_1:
        CMP         R2, #(01*01*16)         ; Copy chunks of 16 8-bit words (16 bytes per loop)
        BCC         Copy_08_2
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        SUB         R2, R2, #(01*01*16)
        B           Copy_08_1

Copy_08_2:
        CMP         R2, #(01*01*01)         ; Copy remaining 8-bit words
        BCC         Mem_Copy_END
        LDRB        R3, [R1], #1
        STRB        R3, [R0], #1
        SUB         R2, R2, #(01*01*01)
        B           Copy_08_2

Mem_Copy_END:
        LDMFD       SP!, {R3-R12}           ; restore registers from stack
        BX          LR                      ; return



