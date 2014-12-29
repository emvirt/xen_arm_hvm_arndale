/***************************************************************************
 **
 **    This file defines the Special Function Registers for
 **    Motorola MC9328MX21 Dragonball
 **
 **    Used with ICCARM and AARM.
 **
 **    (c) Copyright IAR Systems 2003
 **
 **    $Revision: 1.5 $
 **
 ***************************************************************************/

#ifndef __MC9328MX21_H
#define __MC9328MX21_H




/***************************************************************************
 ***************************************************************************
 **
 **    MC9328MX21 SPECIAL FUNCTION REGISTERS
 **
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************/

/* C specific declarations  ************************************************/




#if 0
/* -------------------------------------------------------------------------*/
/*               AITC registers                                             */
/* -------------------------------------------------------------------------*/
typedef struct {        /* Interrupt Control Register (0xE0040000) Reset (0x00000000)                   */
__REG32          : 2;     // Bits 0-1     - Reserved
__REG32 POINTER  :10;     // Bits 2-11    - Interrupt Vector Table Pointer
__REG32          : 4;     // Bits 12-15   - Reserved
__REG32 MD       : 1;     // Bit 16       - Interrupt Vector Table Mode
__REG32          : 2;     // Bits 17-18   - Reserved
__REG32 FIAD     : 1;     // Bit 19       - Fast Interrupt Arbiter Disable
__REG32 NIAD     : 1;     // Bit 20       - Normal Interrupt Arbiter Disable
__REG32 FIDIS    : 1;     // Bit 21       - Fast Interrupt Disable
__REG32 NIDIS    : 1;     // Bit 22       - Normal Interrupt Disable
__REG32          : 1;     // Bit 23       - Reserved
__REG32 ABFEN    : 1;     // Bit 24       - ABFLAG Sticky Enable
__REG32 ABFLAG   : 1;     // Bit 25       - Core Arbitration Prioritization Risen Flag
__REG32          : 6;     // Bits 26-31   - Reserved
} __INTCNTL_bits;

typedef struct {        /* Normal Interrupt Mask Register (0xE0040004) Reset (0x0000001F)                       */
__REG32 NIMASK  : 5;     // Bits 0-4     - Normal Interrupt Mask (0 = Disable priority level 0 ints, 1 = disable priority 1 and lower... 16+ = disable all interrupts)
__REG32         :27;     // Bits 5-31    - Reserved
} __NIMASK_bits;

typedef struct {        /* Interrupt Enable Number Register (0xE0040008) Reset (0x00000000)                     */
__REG32 ENNUM  : 6;     // Bits 0-5     - Interrupt Enable Number - Enables/Disables the interrupt source associated with this value.
__REG32        :26;     // Bits 6-31    - Reserved
} __INTENNUM_bits;

typedef struct {        /* Interrupt Disable Number Register (0xE004000C) Reset (0x00000000)                    */
__REG32 DISNUM  : 6;     // Bits 0-5     - Interrupt Disable Number - Enables/Disables the interrupt source associated with this value.
__REG32         :26;     // Bits 6-31    - Reserved
} __INTDISNUM_bits;

typedef struct {        /* Interrupt Enable Register High (0xE0040010) Reset (0x00000000)                       */
__REG32 INTENABLE32  : 1;     // Bit  0           - Interrupt Enable
__REG32 INTENABLE33  : 1;     // Bit  1           - Interrupt Enable
__REG32 INTENABLE34  : 1;     // Bit  2           - Interrupt Enable
__REG32 INTENABLE35  : 1;     // Bit  3           - Interrupt Enable
__REG32 INTENABLE36  : 1;     // Bit  4           - Interrupt Enable
__REG32 INTENABLE37  : 1;     // Bit  5           - Interrupt Enable
__REG32 INTENABLE38  : 1;     // Bit  6           - Interrupt Enable
__REG32 INTENABLE39  : 1;     // Bit  7           - Interrupt Enable
__REG32 INTENABLE40  : 1;     // Bit  8           - Interrupt Enable
__REG32 INTENABLE41  : 1;     // Bit  9           - Interrupt Enable
__REG32 INTENABLE42  : 1;     // Bit  10          - Interrupt Enable
__REG32 INTENABLE43  : 1;     // Bit  11          - Interrupt Enable
__REG32 INTENABLE44  : 1;     // Bit  12          - Interrupt Enable
__REG32 INTENABLE45  : 1;     // Bit  13          - Interrupt Enable
__REG32 INTENABLE46  : 1;     // Bit  14          - Interrupt Enable
__REG32 INTENABLE47  : 1;     // Bit  15          - Interrupt Enable
__REG32 INTENABLE48  : 1;     // Bit  16          - Interrupt Enable
__REG32 INTENABLE49  : 1;     // Bit  17          - Interrupt Enable
__REG32 INTENABLE50  : 1;     // Bit  18          - Interrupt Enable
__REG32 INTENABLE51  : 1;     // Bit  19          - Interrupt Enable
__REG32 INTENABLE52  : 1;     // Bit  20          - Interrupt Enable
__REG32 INTENABLE53  : 1;     // Bit  21          - Interrupt Enable
__REG32 INTENABLE54  : 1;     // Bit  22          - Interrupt Enable
__REG32 INTENABLE55  : 1;     // Bit  23          - Interrupt Enable
__REG32 INTENABLE56  : 1;     // Bit  24          - Interrupt Enable
__REG32 INTENABLE57  : 1;     // Bit  25          - Interrupt Enable
__REG32 INTENABLE58  : 1;     // Bit  26          - Interrupt Enable
__REG32 INTENABLE59  : 1;     // Bit  27          - Interrupt Enable
__REG32 INTENABLE60  : 1;     // Bit  28          - Interrupt Enable
__REG32 INTENABLE61  : 1;     // Bit  29          - Interrupt Enable
__REG32 INTENABLE62  : 1;     // Bit  30          - Interrupt Enable
__REG32 INTENABLE63  : 1;     // Bit  31          - Interrupt Enable
} __INTENABLEH_bits;

typedef struct {        /* Interrupt Enable Register Low (0xE0040014) Reset (0x00000000)                        */
__REG32 INTENABLE0   : 1;     // Bit  0           - Interrupt Enable
__REG32 INTENABLE1   : 1;     // Bit  1           - Interrupt Enable
__REG32 INTENABLE2   : 1;     // Bit  2           - Interrupt Enable
__REG32 INTENABLE3   : 1;     // Bit  3           - Interrupt Enable
__REG32 INTENABLE4   : 1;     // Bit  4           - Interrupt Enable
__REG32 INTENABLE5   : 1;     // Bit  5           - Interrupt Enable
__REG32 INTENABLE6   : 1;     // Bit  6           - Interrupt Enable
__REG32 INTENABLE7   : 1;     // Bit  7           - Interrupt Enable
__REG32 INTENABLE8   : 1;     // Bit  8           - Interrupt Enable
__REG32 INTENABLE9   : 1;     // Bit  9           - Interrupt Enable
__REG32 INTENABLE10  : 1;     // Bit  10          - Interrupt Enable
__REG32 INTENABLE11  : 1;     // Bit  11          - Interrupt Enable
__REG32 INTENABLE12  : 1;     // Bit  12          - Interrupt Enable
__REG32 INTENABLE13  : 1;     // Bit  13          - Interrupt Enable
__REG32 INTENABLE14  : 1;     // Bit  14          - Interrupt Enable
__REG32 INTENABLE15  : 1;     // Bit  15          - Interrupt Enable
__REG32 INTENABLE16  : 1;     // Bit  16          - Interrupt Enable
__REG32 INTENABLE17  : 1;     // Bit  17          - Interrupt Enable
__REG32 INTENABLE18  : 1;     // Bit  18          - Interrupt Enable
__REG32 INTENABLE19  : 1;     // Bit  19          - Interrupt Enable
__REG32 INTENABLE20  : 1;     // Bit  20          - Interrupt Enable
__REG32 INTENABLE21  : 1;     // Bit  21          - Interrupt Enable
__REG32 INTENABLE22  : 1;     // Bit  22          - Interrupt Enable
__REG32 INTENABLE23  : 1;     // Bit  23          - Interrupt Enable
__REG32 INTENABLE24  : 1;     // Bit  24          - Interrupt Enable
__REG32 INTENABLE25  : 1;     // Bit  25          - Interrupt Enable
__REG32 INTENABLE26  : 1;     // Bit  26          - Interrupt Enable
__REG32 INTENABLE27  : 1;     // Bit  27          - Interrupt Enable
__REG32 INTENABLE28  : 1;     // Bit  28          - Interrupt Enable
__REG32 INTENABLE29  : 1;     // Bit  29          - Interrupt Enable
__REG32 INTENABLE30  : 1;     // Bit  30          - Interrupt Enable
__REG32 INTENABLE31  : 1;     // Bit  31          - Interrupt Enable
} __INTENABLEL_bits;

typedef struct {        /* Interrupt Type Register High (0xE0040018) Reset (0x00000000)                 */
__REG32 INTTYPE32  : 1;     // Bit  0         - Interrupt Enable
__REG32 INTTYPE33  : 1;     // Bit  1         - Interrupt Enable
__REG32 INTTYPE34  : 1;     // Bit  2         - Interrupt Enable
__REG32 INTTYPE35  : 1;     // Bit  3         - Interrupt Enable
__REG32 INTTYPE36  : 1;     // Bit  4         - Interrupt Enable
__REG32 INTTYPE37  : 1;     // Bit  5         - Interrupt Enable
__REG32 INTTYPE38  : 1;     // Bit  6         - Interrupt Enable
__REG32 INTTYPE39  : 1;     // Bit  7         - Interrupt Enable
__REG32 INTTYPE40  : 1;     // Bit  8         - Interrupt Enable
__REG32 INTTYPE41  : 1;     // Bit  9         - Interrupt Enable
__REG32 INTTYPE42  : 1;     // Bit  10        - Interrupt Enable
__REG32 INTTYPE43  : 1;     // Bit  11        - Interrupt Enable
__REG32 INTTYPE44  : 1;     // Bit  12        - Interrupt Enable
__REG32 INTTYPE45  : 1;     // Bit  13        - Interrupt Enable
__REG32 INTTYPE46  : 1;     // Bit  14        - Interrupt Enable
__REG32 INTTYPE47  : 1;     // Bit  15        - Interrupt Enable
__REG32 INTTYPE48  : 1;     // Bit  16        - Interrupt Enable
__REG32 INTTYPE49  : 1;     // Bit  17        - Interrupt Enable
__REG32 INTTYPE50  : 1;     // Bit  18        - Interrupt Enable
__REG32 INTTYPE51  : 1;     // Bit  19        - Interrupt Enable
__REG32 INTTYPE52  : 1;     // Bit  20        - Interrupt Enable
__REG32 INTTYPE53  : 1;     // Bit  21        - Interrupt Enable
__REG32 INTTYPE54  : 1;     // Bit  22        - Interrupt Enable
__REG32 INTTYPE55  : 1;     // Bit  23        - Interrupt Enable
__REG32 INTTYPE56  : 1;     // Bit  24        - Interrupt Enable
__REG32 INTTYPE57  : 1;     // Bit  25        - Interrupt Enable
__REG32 INTTYPE58  : 1;     // Bit  26        - Interrupt Enable
__REG32 INTTYPE59  : 1;     // Bit  27        - Interrupt Enable
__REG32 INTTYPE60  : 1;     // Bit  28        - Interrupt Enable
__REG32 INTTYPE61  : 1;     // Bit  29        - Interrupt Enable
__REG32 INTTYPE62  : 1;     // Bit  30        - Interrupt Enable
__REG32 INTTYPE63  : 1;     // Bit  31        - Interrupt Enable
} __INTTYPEH_bits;

typedef struct {        /* Interrupt Enable Register Low (0xE004001C) Reset (0x00000000)                        */
__REG32 INTTYPE0   : 1;     // Bit  0         - Interrupt Enable
__REG32 INTTYPE1   : 1;     // Bit  1         - Interrupt Enable
__REG32 INTTYPE2   : 1;     // Bit  2         - Interrupt Enable
__REG32 INTTYPE3   : 1;     // Bit  3         - Interrupt Enable
__REG32 INTTYPE4   : 1;     // Bit  4         - Interrupt Enable
__REG32 INTTYPE5   : 1;     // Bit  5         - Interrupt Enable
__REG32 INTTYPE6   : 1;     // Bit  6         - Interrupt Enable
__REG32 INTTYPE7   : 1;     // Bit  7         - Interrupt Enable
__REG32 INTTYPE8   : 1;     // Bit  8         - Interrupt Enable
__REG32 INTTYPE9   : 1;     // Bit  9         - Interrupt Enable
__REG32 INTTYPE10  : 1;     // Bit  10        - Interrupt Enable
__REG32 INTTYPE11  : 1;     // Bit  11        - Interrupt Enable
__REG32 INTTYPE12  : 1;     // Bit  12        - Interrupt Enable
__REG32 INTTYPE13  : 1;     // Bit  13        - Interrupt Enable
__REG32 INTTYPE14  : 1;     // Bit  14        - Interrupt Enable
__REG32 INTTYPE15  : 1;     // Bit  15        - Interrupt Enable
__REG32 INTTYPE16  : 1;     // Bit  16        - Interrupt Enable
__REG32 INTTYPE17  : 1;     // Bit  17        - Interrupt Enable
__REG32 INTTYPE18  : 1;     // Bit  18        - Interrupt Enable
__REG32 INTTYPE19  : 1;     // Bit  19        - Interrupt Enable
__REG32 INTTYPE20  : 1;     // Bit  20        - Interrupt Enable
__REG32 INTTYPE21  : 1;     // Bit  21        - Interrupt Enable
__REG32 INTTYPE22  : 1;     // Bit  22        - Interrupt Enable
__REG32 INTTYPE23  : 1;     // Bit  23        - Interrupt Enable
__REG32 INTTYPE24  : 1;     // Bit  24        - Interrupt Enable
__REG32 INTTYPE25  : 1;     // Bit  25        - Interrupt Enable
__REG32 INTTYPE26  : 1;     // Bit  26        - Interrupt Enable
__REG32 INTTYPE27  : 1;     // Bit  27        - Interrupt Enable
__REG32 INTTYPE28  : 1;     // Bit  28        - Interrupt Enable
__REG32 INTTYPE29  : 1;     // Bit  29        - Interrupt Enable
__REG32 INTTYPE30  : 1;     // Bit  30        - Interrupt Enable
__REG32 INTTYPE31  : 1;     // Bit  31        - Interrupt Enable
} __INTTYPEL_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 7 (0xE0040020) Reset (0x00000000)                   */
__REG32 NIPR56  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR57  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR58  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR59  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR60  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR61  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR62  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR63  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY7_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 6 (0xE0040024) Reset (0x00000000)                   */
__REG32 NIPR48  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR49  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR50  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR51  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR52  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR53  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR54  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR55  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY6_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 5 (0xE0040028) Reset (0x00000000)                   */
__REG32 NIPR40  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR41  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR42  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR43  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR44  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR45  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR46  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR47  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY5_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 4 (0xE004002C) Reset (0x00000000)                   */
__REG32 NIPR32  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR33  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR34  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR35  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR36  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR37  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR38  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR39  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY4_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 3 (0xE0040030) Reset (0x00000000)                   */
__REG32 NIPR24  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR25  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR26  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR27  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR28  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR29  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR30  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR31  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY3_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 2 (0xE0040034) Reset (0x00000000)                   */
__REG32 NIPR16  : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR17  : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR18  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR19  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR20  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR21  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR22  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR23  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY2_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 1 (0xE0040038) Reset (0x00000000)                   */
__REG32 NIPR8   : 4;     // Bits 0-3     - Normal Interrupt Priority Level
__REG32 NIPR9   : 4;     // Bits 4-7     - Normal Interrupt Priority Level
__REG32 NIPR10  : 4;     // Bits 8-11    - Normal Interrupt Priority Level
__REG32 NIPR11  : 4;     // Bits 12-15   - Normal Interrupt Priority Level
__REG32 NIPR12  : 4;     // Bits 16-19   - Normal Interrupt Priority Level
__REG32 NIPR13  : 4;     // Bits 20-23   - Normal Interrupt Priority Level
__REG32 NIPR14  : 4;     // Bits 24-27   - Normal Interrupt Priority Level
__REG32 NIPR15  : 4;     // Bits 28-31   - Normal Interrupt Priority Level
} __NIPRIORITY1_bits;

typedef struct {        /* Normal Interrupt Priority Level Register 0 (0xE004003C) Reset (0x00000000)                   */
__REG32 NIPR0  : 4;     // Bits 0  - 3  - Normal Interrupt Priority Level
__REG32 NIPR1  : 4;     // Bits 4  - 7  - Normal Interrupt Priority Level
__REG32 NIPR2  : 4;     // Bits 8  - 11 - Normal Interrupt Priority Level
__REG32 NIPR3  : 4;     // Bits 12 - 15 - Normal Interrupt Priority Level
__REG32 NIPR4  : 4;     // Bits 16 - 19 - Normal Interrupt Priority Level
__REG32 NIPR5  : 4;     // Bits 20 - 23 - Normal Interrupt Priority Level
__REG32 NIPR6  : 4;     // Bits 24 - 27 - Normal Interrupt Priority Level
__REG32 NIPR7  : 4;     // Bits 28 - 31 - Normal Interrupt Priority Level
} __NIPRIORITY0_bits;

typedef struct {        /* Normal Interrupt Vector and Status Register (0xE0040040) Reset (0xFFFFFFFF)  */
__REG32 NIPRILVL  :16;     // Bits 0  - 15 - Normal Interrupt Priority Level - Indicates the priority level of the highest priority normal interrupt.
__REG32 NIVECTOR  :16;     // Bits 16 - 31 - Normal Interrupt Vector - Indicates vector index for the highest pending normal interrupt.
} __NIVECSR_bits;

typedef struct {        /* Interrupt Source Register High (0xE0040048) Reset (0x00000000)       */
__REG32 INTIN32  : 1;     // Bit  0       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN33  : 1;     // Bit  1       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN34  : 1;     // Bit  2       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN35  : 1;     // Bit  3       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN36  : 1;     // Bit  4       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN37  : 1;     // Bit  5       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN38  : 1;     // Bit  6       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN39  : 1;     // Bit  7       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN40  : 1;     // Bit  8       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN41  : 1;     // Bit  9       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN42  : 1;     // Bit  10      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN43  : 1;     // Bit  11      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN44  : 1;     // Bit  12      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN45  : 1;     // Bit  13      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN46  : 1;     // Bit  14      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN47  : 1;     // Bit  15      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN48  : 1;     // Bit  16      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN49  : 1;     // Bit  17      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN50  : 1;     // Bit  18      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN51  : 1;     // Bit  19      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN52  : 1;     // Bit  20      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN53  : 1;     // Bit  21      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN54  : 1;     // Bit  22      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN55  : 1;     // Bit  23      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN56  : 1;     // Bit  24      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN57  : 1;     // Bit  25      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN58  : 1;     // Bit  26      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN59  : 1;     // Bit  27      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN60  : 1;     // Bit  28      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN61  : 1;     // Bit  29      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN62  : 1;     // Bit  30      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN63  : 1;     // Bit  31      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
} __INTSRCH_bits;

typedef struct {        /* Interrupt Source Register Low (0xE004004C) Reset (0x00000000)        */
__REG32 INTIN0   : 1;     // Bit  0       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN1   : 1;     // Bit  1       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN2   : 1;     // Bit  2       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN3   : 1;     // Bit  3       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN4   : 1;     // Bit  4       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN5   : 1;     // Bit  5       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN6   : 1;     // Bit  6       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN7   : 1;     // Bit  7       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN8   : 1;     // Bit  8       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN9   : 1;     // Bit  9       - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN10  : 1;     // Bit  10      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN11  : 1;     // Bit  11      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN12  : 1;     // Bit  12      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN13  : 1;     // Bit  13      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN14  : 1;     // Bit  14      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN15  : 1;     // Bit  15      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN16  : 1;     // Bit  16      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN17  : 1;     // Bit  17      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN18  : 1;     // Bit  18      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN19  : 1;     // Bit  19      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN20  : 1;     // Bit  20      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN21  : 1;     // Bit  21      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN22  : 1;     // Bit  22      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN23  : 1;     // Bit  23      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN24  : 1;     // Bit  24      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN25  : 1;     // Bit  25      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN26  : 1;     // Bit  26      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN27  : 1;     // Bit  27      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN28  : 1;     // Bit  28      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN29  : 1;     // Bit  29      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN30  : 1;     // Bit  30      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
__REG32 INTIN31  : 1;     // Bit  31      - Interrupt Source (0 = Interrupt source negated, 1 = Interrupt source asserted)
} __INTSRCL_bits;

typedef struct {        /* Interrupt Force Register High (0xE0040050) Reset (0x00000000)        */
__REG32 FORCE32  : 1;     // Bit  0       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE33  : 1;     // Bit  1       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE34  : 1;     // Bit  2       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE35  : 1;     // Bit  3       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE36  : 1;     // Bit  4       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE37  : 1;     // Bit  5       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE38  : 1;     // Bit  6       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE39  : 1;     // Bit  7       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE40  : 1;     // Bit  8       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE41  : 1;     // Bit  9       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE42  : 1;     // Bit  10      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE43  : 1;     // Bit  11      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE44  : 1;     // Bit  12      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE45  : 1;     // Bit  13      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE46  : 1;     // Bit  14      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE47  : 1;     // Bit  15      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE48  : 1;     // Bit  16      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE49  : 1;     // Bit  17      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE50  : 1;     // Bit  18      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE51  : 1;     // Bit  19      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE52  : 1;     // Bit  20      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE53  : 1;     // Bit  21      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE54  : 1;     // Bit  22      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE55  : 1;     // Bit  23      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE56  : 1;     // Bit  24      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE57  : 1;     // Bit  25      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE58  : 1;     // Bit  26      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE59  : 1;     // Bit  27      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE60  : 1;     // Bit  28      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE61  : 1;     // Bit  29      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE62  : 1;     // Bit  30      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE63  : 1;     // Bit  31      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
} __INTFRCH_bits;

typedef struct {        /* Interrupt Force Register Low (0xE0040054) Reset (0x00000000) */
__REG32 FORCE0   : 1;     // Bit  0       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE1   : 1;     // Bit  1       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE2   : 1;     // Bit  2       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE3   : 1;     // Bit  3       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE4   : 1;     // Bit  4       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE5   : 1;     // Bit  5       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE6   : 1;     // Bit  6       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE7   : 1;     // Bit  7       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE8   : 1;     // Bit  8       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE9   : 1;     // Bit  9       - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE10  : 1;     // Bit  10      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE11  : 1;     // Bit  11      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE12  : 1;     // Bit  12      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE13  : 1;     // Bit  13      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE14  : 1;     // Bit  14      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE15  : 1;     // Bit  15      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE16  : 1;     // Bit  16      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE17  : 1;     // Bit  17      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE18  : 1;     // Bit  18      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE19  : 1;     // Bit  19      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE20  : 1;     // Bit  20      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE21  : 1;     // Bit  21      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE22  : 1;     // Bit  22      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE23  : 1;     // Bit  23      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE24  : 1;     // Bit  24      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE25  : 1;     // Bit  25      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE26  : 1;     // Bit  26      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE27  : 1;     // Bit  27      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE28  : 1;     // Bit  28      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE29  : 1;     // Bit  29      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE30  : 1;     // Bit  30      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
__REG32 FORCE31  : 1;     // Bit  31      - Interrupt Source Force Request - Writing a 1 Forces a request for the corresponding interrupt source.
} __INTFRCL_bits;

typedef struct {        /* Normal Interrupt Pending Register High (0xE0040058) Reset (0x00000000)       */
__REG32 NIPEND32  : 1;     // Bit  0       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND33  : 1;     // Bit  1       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND34  : 1;     // Bit  2       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND35  : 1;     // Bit  3       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND36  : 1;     // Bit  4       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND37  : 1;     // Bit  5       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND38  : 1;     // Bit  6       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND39  : 1;     // Bit  7       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND40  : 1;     // Bit  8       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND41  : 1;     // Bit  9       - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND42  : 1;     // Bit  10      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND43  : 1;     // Bit  11      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND44  : 1;     // Bit  12      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND45  : 1;     // Bit  13      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND46  : 1;     // Bit  14      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND47  : 1;     // Bit  15      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND48  : 1;     // Bit  16      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND49  : 1;     // Bit  17      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
__REG32 NIPEND50  : 1;     // Bit  18      - Normal Interrupt Pending Bit - (0=No int pending, 1 = Normal Interrupt request pending)
#define __REG(x) (*((volatile u32 *)x))
 

#endif

/* Common declarations  ****************************************************/
/***************************************************************************
 **
 **  Interrupt Controller
 **
 ***************************************************************************/
#define INTCNTL __REG(0xe0040000)
#define NIMASK __REG(0xe0040004)
#define INTENNUM  __REG(0xe0040008)
#define INTDISNUM __REG(0xe004000C)
#define INTENABLEH __REG(0xe0040010)
#define INTENABLEL __REG(0xe0040014)
#define INTTYPEH __REG(0xe0040018)
#define INTTYPEL __REG(0xe004001C)
#define NIPRIORITY7 __REG(0xe0040020)
#define NIPRIORITY6 __REG(0xe0040024)
#define NIPRIORITY5 __REG(0xe0040028)
#define NIPRIORITY4 __REG(0xe004002C)
#define NIPRIORITY3 __REG(0xe0040030)
#define NIPRIORITY2 __REG(0xe0040034)
#define NIPRIORITY1 __REG(0xe0040038)
#define NIPRIORITY0 __REG(0xe004003C)
#define NIVECSR __REG(0xe0040040)
#define FIVECSR __REG(0xe0040044)
#define INTSRCH __REG(0xe0040048)
#define INTSRCL __REG(0xe004004C)
#define INTFRCH __REG(0xe0040050)
#define INTFRCL __REG(0xe0040054)
#define NIPNDH __REG(0xe0040058)
#define NIPNDL __REG(0xe004005C)
#define FIPNDH __REG(0xe0040060)
#define FIPNDL __REG(0xe0040064)

/***************************************************************************
 **
 **  ROMPATCH
 **
 ***************************************************************************/
#define  ROMPATCHD15 __REG(0xe00410B4)
#define  ROMPATCHD14 __REG(0xe00410B8)
#define  ROMPATCHD13 __REG(0xe00410BC)
#define  ROMPATCHD12 __REG(0xe00410C0)
#define  ROMPATCHD11 __REG(0xe00410C4)
#define  ROMPATCHD10 __REG(0xe00410C8)
#define  ROMPATCHD9 __REG(0xe00410CC)
#define  ROMPATCHD8 __REG(0xe00410D0)
#define  ROMPATCHD7 __REG(0xe00410D4)
#define  ROMPATCHD6 __REG(0xe00410D8)
#define  ROMPATCHD5 __REG(0xe00410DC)
#define  ROMPATCHD4 __REG(0xe00410E0)
#define  ROMPATCHD3 __REG(0xe00410E4)
#define  ROMPATCHD2 __REG(0xe00410E8)
#define  ROMPATCHD1 __REG(0xe00410EC)
#define  ROMPATCHD0 __REG(0xe00410F0)
#define ROMPATCHCNTL __REG(0xE00410F4)
#define ROMPATCH  __REG(0xe00410F8)
#define ROMPATCL __REG(0xe00410FC)
#define ROMPATCHA0 __REG(0xe0041100)
#define ROMPATCHA1 __REG(0xe0041104)
#define ROMPATCHA2 __REG(0xe0041108)
#define ROMPATCHA3 __REG(0xe004110C)
#define ROMPATCHA4 __REG(0xe0041110)
#define ROMPATCHA5 __REG(0xe0041114)
#define ROMPATCHA6 __REG(0xe0041118)
#define ROMPATCHA7 __REG(0xe004111C)
#define ROMPATCHA8 __REG(0xe0041120)
#define ROMPATCHA9 __REG(0xe0041124)
#define ROMPATCHA10 __REG(0xe0041128)
#define ROMPATCHA11 __REG(0xe004112C)
#define ROMPATCHA12 __REG(0xe0041130)
#define ROMPATCHA13 __REG(0xe0041134)
#define ROMPATCHA14 __REG(0xe0041138)
#define ROMPATCHA15 __REG(0xe004113C)
#define ROMPATCHA16 __REG(0xe0041140)
#define ROMPATCHA17 __REG(0xe0041144)
#define ROMPATCHA18 __REG(0xe0041148)
#define ROMPATCHA19 __REG(0xe004114C)
#define ROMPATCHA20 __REG(0xe0041150)
#define ROMPATCHA21 __REG(0xe0041154)
#define ROMPATCHA22 __REG(0xe0041158)
#define ROMPATCHA23 __REG(0xe004115C)
#define ROMPATCHA24 __REG(0xe0041160)
#define ROMPATCHA25 __REG(0xe0041164)
#define ROMPATCHA26 __REG(0xe0041168)
#define ROMPATCHA27 __REG(0xe004116C)
#define ROMPATCHA28 __REG(0xe0041170)
#define ROMPATCHA29 __REG(0xe0041174)
#define ROMPATCHA30 __REG(0xe0041178)
#define ROMPATCHA31 __REG(0xe004117C)
#define ROMPATCHA32 __REG(0xe0041180)
#define ROMPATCHA33 __REG(0xe0041184)
#define ROMPATCHA34 __REG(0xe0041188)
#define ROMPATCHA35 __REG(0xe004118C)
#define ROMPATCHA36 __REG(0xe0041190)
#define ROMPATCHA37 __REG(0xe0041194)
#define ROMPATCHA38 __REG(0xe0041198)
#define ROMPATCHA39 __REG(0xe004119C)
#define ROMPATCHA40 __REG(0xe00411A0)
#define ROMPATCHA41 __REG(0xe00411A4)
#define ROMPATCHA42 __REG(0xe00411A8)
#define ROMPATCHA43 __REG(0xe00411AC)
#define ROMPATCHA44 __REG(0xe00411B0)
#define ROMPATCHA45 __REG(0xe00411B4)
#define ROMPATCHA46 __REG(0xe00411B8)
#define ROMPATCHA47 __REG(0xe00411BC)
#define ROMPATCHA48 __REG(0xe00411C0)
#define ROMPATCHA49 __REG(0xe00411C4)
#define ROMPATCHA50 __REG(0xe00411C8)
#define ROMPATCHA51 __REG(0xe00411CC)
#define ROMPATCHA52 __REG(0xe00411D0)
#define ROMPATCHA53 __REG(0xe00411D4)
#define ROMPATCHA54 __REG(0xe00411D8)
#define ROMPATCHA55 __REG(0xe00411DC)
#define ROMPATCHA56 __REG(0xe00411E0)
#define ROMPATCHA57 __REG(0xe00411E4)
#define ROMPATCHA58 __REG(0xe00411E8)
#define ROMPATCHA59 __REG(0xe00411EC)
#define ROMPATCHA60 __REG(0xe00411F0)
#define ROMPATCHA61 __REG(0xe00411F4)
#define ROMPATCHA62 __REG(0xe00411F8)
#define ROMPATCHA63 __REG(0xe00411FC)
#define ROMPATCHBASEA __REG(0xE0041204)
#define ROMPATCHSR __REG(0xe0041208)
#define ROMPATCHABSR __REG(0xE004120C)
#define  ROMPATCHDADR __REG(0xE0041210)

/***************************************************************************
 **
 **  PLLCLK
 **
 ***************************************************************************/
#define CSCR __REG(0xe0027000)
#define MPCTL0   __REG(0xe0027004)
#define MPCTL1   __REG(0xe0027008)
#define SPCTL0   __REG(0xe002700C)
#define SPCTL1   __REG(0xe0027010)
#define OSC26MCTL __REG(0xe0027014)
#define PCDR0    __REG(0xe0027018)
#define PCDR1    __REG(0xe002701C)
#define PCCR0    __REG(0xe0027020)
#define PCCR1    __REG(0xe0027024)
#define CCSR __REG(0xe0027028)
#define WKGDCTL  __REG(0xe0027034)

/***************************************************************************
 **
 **  AIPI1
 **
 ***************************************************************************/
#define AIPI1_PSR0 __REG(0xe0000000)
#define AIPI1_PSR1 __REG(0xe0000004)
#define AIPI1_PAR __REG(0xe0000008)

/***************************************************************************
 **
 **  AIPI2
 **
 ***************************************************************************/
#define AIPI2_PSR0 __REG(0xe0020000)
#define AIPI2_PSR1 __REG(0xe0020004)
#define AIPI2_PAR __REG(0xe0020008)

/***************************************************************************
 **
 **  SYS CTRL
 **
 ***************************************************************************/
#define  SUID0    __REG(0xe0027804)
#define  SUID1    __REG(0xe0027808)
#define  CID      __REG(0xe002780C)
#define FUSE __REG(0xe0027810)
#define FMCR __REG(0xe0027814)
#define GPCR __REG(0xe0027818)
#define WBCR __REG(0xe002781C)
#define DSCR1    __REG(0xe0027820)
#define DSCR2    __REG(0xe0027824)
#define DSCR3    __REG(0xe0027828)
#define DSCR4    __REG(0xe002782C)
#define DSCR5    __REG(0xe0027830)
#define DSCR6    __REG(0xe0027834)
#define DSCR7    __REG(0xe0027838)
#define DSCR8    __REG(0xe002783C)
#define DSCR9    __REG(0xe0027840)
#define DSCR10   __REG(0xe0027844)
#define DSCR11   __REG(0xe0027848)
#define DSCR12   __REG(0xe002784C)
#define PCSR __REG(0xe0027850)

/***************************************************************************
 **
 **  Multi-layer AHB Crossbar Switch (MAX)
 **
 ***************************************************************************/
#define MPR0 __REG(0xe003F000)
#define AMPR0   __REG(0xe003F004)
#define SGPCR0   __REG(0xe003F010)
#define ASGPCR0  __REG(0xe003F014)
#define MPR1 __REG(0xe003F100)
#define AMPR1    __REG(0xe003F104)
#define SGPCR1   __REG(0xe003F110)
#define ASGPCR1  __REG(0xe003F114)
#define MPR2 __REG(0xe003F200)
#define AMPR2    __REG(0xe003F204)
#define SGPCR2   __REG(0xe003F210)
#define ASGPCR2  __REG(0xe003F214)
#define MPR3 __REG(0xe003F300)
#define AMPR3    __REG(0xe003F304)
#define SGPCR3   __REG(0xe003F310)
#define ASGPCR3  __REG(0xe003F314)
#define MGPCR0   __REG(0xe003F800)
#define MGPCR1   __REG(0xe003F900)
#define MGPCR2   __REG(0xe003FA00)
#define MGPCR3   __REG(0xe003FB00)
#define MGPCR4   __REG(0xe003FC00)
#define MGPCR5   __REG(0xe003FD00)

/***************************************************************************
 **
 **  Watchdog
 **
 ***************************************************************************/
#define WCR      __REG(0xe0002000)
#define WSR      __REG(0xe0002002)
#define WRSR __REG(0xe0002004)

/***************************************************************************
 **
 **  RTC
 **
 ***************************************************************************/
#define HOURMIN  __REG(0xe0007000)
#define _SECONDS  __REG(0xe0007004) // TODO
#define ALRM_HM  __REG(0xe0007008)
#define ALRM_SEC __REG(0xe000700C)
#define RCCTL    __REG(0xe0007010)
#define RTCISR   __REG(0xe0007014)
#define RTCIENR  __REG(0xe0007018)
#define STPWCH   __REG(0xe000701C)
#define DAYR __REG(0xe0007020)
#define DAYALARM __REG(0xe0007024)

/***************************************************************************
 **
 **  General-Purpose Timer1
 **
 ***************************************************************************/
#define TCTL1    __REG(0xe0003000)
#define TPRER1   __REG(0xe0003004)
#define  TCMP1    __REG(0xe0003008)
#define  TCR1 __REG(0xe000300C)
#define  TCN1 __REG(0xe0003010)
#define TSTAT1   __REG(0xe0003014)


/***************************************************************************
 **
 **  General-Purpose Timer2
 **
 ***************************************************************************/
#define TCTL2    __REG(0xe0004000)
#define TPRER2   __REG(0xe0004004)
#define  TCMP2    __REG(0xe0004008)
#define  TCR2 __REG(0xe000400C)
#define  TCN2 __REG(0xe0004010)
#define TSTAT2   __REG(0xe0004014)

/***************************************************************************
 **
 **  General-Purpose Timer3
 **
 ***************************************************************************/
#define TCTL3    __REG(0xe0005000)
#define TPRER3   __REG(0xe0005004)
#define  TCMP3    __REG(0xe0005008)
#define  TCR3 __REG(0xe000500C)
#define  TCN3 __REG(0xe0005010)
#define TSTAT3   __REG(0xe0005014)

/***************************************************************************
 **
 **  PWM
 **
 ***************************************************************************/
#define PWMC __REG(0xe0006000)
#define PWMS __REG(0xe0006004)
#define PWMP __REG(0xe0006008)
#define PWMCNT   __REG(0xe000600C)

/***************************************************************************
 **
 **  GPIO
 **
 ***************************************************************************/
#define PMASK    __REG(0xe0015600)

/***************************************************************************
 **
 **  GPIO PORTA
 **
 ***************************************************************************/
#define PTA_DDIR __REG(0xe0015000)
#define PTA_OCR1 __REG(0xe0015004)
#define PTA_OCR2 __REG(0xe0015008)
#define PTA_ICONFA1 __REG(0xe001500C)
#define PTA_ICONFA2 __REG(0xe0015010)
#define PTA_ICONFB1 __REG(0xe0015014)
#define PTA_ICONFB2 __REG(0xe0015018)
#define PTA_DR   __REG(0xe001501C)
#define PTA_GIUS __REG(0xe0015020)
#define PTA_SSR  __REG(0xe0015024)
#define PTA_ICR1 __REG(0xe0015028)
#define PTA_ICR2 __REG(0xe001502C)
#define PTA_IMR  __REG(0xe0015030)
#define PTA_ISR  __REG(0xe0015034)
#define PTA_GPR  __REG(0xe0015038)
#define PTA_SWR  __REG(0xe001503C)
#define PTA_PUEN __REG(0xe0015040)

/***************************************************************************
 **
 **  GPIO PORTB
 **
 ***************************************************************************/
#define PTB_DDIR __REG(0xe0015100)
#define PTB_OCR1 __REG(0xe0015104)
#define PTB_OCR2 __REG(0xe0015108)
#define PTB_ICONFA1 __REG(0xe001510C)
#define PTB_ICONFA2 __REG(0xe0015110)
#define PTB_ICONFB1 __REG(0xe0015114)
#define PTB_ICONFB2 __REG(0xe0015118)
#define PTB_DR   __REG(0xe001511C)
#define PTB_GIUS __REG(0xe0015120)
#define PTB_SSR  __REG(0xe0015124)
#define PTB_ICR1 __REG(0xe0015128)
#define PTB_ICR2 __REG(0xe001512C)
#define PTB_IMR  __REG(0xe0015130)
#define PTB_ISR  __REG(0xe0015134)
#define PTB_GPR  __REG(0xe0015138)
#define PTB_SWR  __REG(0xe001513C)
#define PTB_PUEN __REG(0xe0015140)

/***************************************************************************
 **
 **  GPIO PORTC
 **
 ***************************************************************************/
#define PTC_DDIR __REG(0xe0015200)
#define PTC_OCR1 __REG(0xe0015204)
#define PTC_OCR2 __REG(0xe0015208)
#define PTC_ICONFA1 __REG(0xe001520C)
#define PTC_ICONFA2 __REG(0xe0015210)
#define PTC_ICONFB1 __REG(0xe0015214)
#define PTC_ICONFB2 __REG(0xe0015218)
#define PTC_DR  __REG(0xe001521C)
#define PTC_GIUS __REG(0xe0015220)
#define PTC_SSR  __REG(0xe0015224)
#define PTC_ICR1 __REG(0xe0015228)
#define PTC_ICR2 __REG(0xe001522C)
#define PTC_IMR  __REG(0xe0015230)
#define PTC_ISR __REG(0xe0015234)
#define PTC_GPR  __REG(0xe0015238)
#define PTC_SWR  __REG(0xe001523C)
#define PTC_PUEN __REG(0xe0015240)

/***************************************************************************
 **
 **  GPIO PORTD
 **
 ***************************************************************************/
#define PTD_DDIR __REG(0xe0015300)
#define PTD_OCR1 __REG(0xe0015304)
#define PTD_OCR2 __REG(0xe0015308)
#define PTD_ICONFA1 __REG(0xe001530C)
#define PTD_ICONFA2 __REG(0xe0015310)
#define PTD_ICONFB1 __REG(0xe0015314)
#define PTD_ICONFB2 __REG(0xe0015318)
#define PTD_DR   __REG(0xe001531C)
#define PTD_GIUS __REG(0xe0015320)
#define PTD_SSR  __REG(0xe0015324)
#define PTD_ICR1 __REG(0xe0015328)
#define PTD_ICR2 __REG(0xe001532C)
#define PTD_IMR __REG(0xe0015330)
#define PTD_ISR  __REG(0xe0015334)
#define PTD_GP __REG(0xe0015338)
#define PTD_SWR  __REG(0xe001533C)
#define PTD_PUEN __REG(0xe0015340)

/***************************************************************************
 **
 **  GPIO PORTE
 **
 ***************************************************************************/
#define PTE_DDIR __REG(0xe0015400)
#define PTE_OCR1 __REG(0xe0015404)
#define PTE_OCR2 __REG(0xe0015408)
#define PTE_ICONFA1 __REG(0xe001540C)
#define PTE_ICONFA2 __REG(0xe0015410)
#define PTE_ICONFB1 __REG(0xe0015414)
#define PTE_ICONFB2 __REG(0xe0015418)
#define PTE_DR   __REG(0xe001541C)
#define PTE_GIUS __REG(0xe0015420)
#define PTE_SSR  __REG(0xe0015424)
#define PTE_ICR1 __REG(0xe0015428)
#define PTE_ICR2 __REG(0xe001542C)
#define PTE_IMR  __REG(0xe0015430)
#define PTE_ISR  __REG(0xe0015434)
#define PTE_GPR  __REG(0xe0015438)
#define PTE_SWR  __REG(0xe001543C)
#define PTE_PUEN __REG(0xe0015440)

/***************************************************************************
 **
 **  GPIO PORTF
 **
 ***************************************************************************/
#define PTF_DDIR __REG(0xe0015500)
#define PTF_OCR1 __REG(0xe0015504)
#define PTF_OCR2 __REG(0xe0015508)
#define PTF_ICONFA1 __REG(0xe001550C)
#define PTF_ICONFA2 __REG(0xe0015510)
#define PTF_ICONFB1 __REG(0xe0015514)
#define PTF_ICONFB2 __REG(0xe0015518)
#define PTF_DR   __REG(0xe001551C)
#define PTF_GIUS __REG(0xe0015520)
#define PTF_SSR  __REG(0xe0015524)
#define PTF_ICR1 __REG(0xe0015528)
#define PTF_ICR2 __REG(0xe001552C)
#define PTF_IMR  __REG(0xe0015530)
#define PTF_ISR __REG(0xe0015534)
#define PTF_GPR  __REG(0xe0015538)
#define PTF_SWR  __REG(0xe001553C)
#define PTF_PUEN __REG(0xe0015540)

/***************************************************************************
 **
 **  Security Controller
 **
 ***************************************************************************/
#define SCM_RED_START __REG(0xE0043000)
#define SCM_BLACK_START __REG(0xE0043004)
#define SCM_LENGTH __REG(0xe0043008)
#define SCM_CONTROL __REG(0xe004300C)
#define SCM_STATUS __REG(0xe0043010)
#define SCM_ERROR __REG(0xe0043014)
#define SCM_INT_CTRL __REG(0xE0043018)
#define SCM_CFG   __REG(0xe004301C)
#define  SCM_VEC0 __REG(0xe0043020)
#define  SCM_VEC1 __REG(0xe0043024)
#define SMN_STATUS __REG(0xe0042000)
#define SMN_COMMAND __REG(0xe0042004)
#define SMN_SSR __REG(0xe0042008)
#define SMN_SER  __REG(0xe004200C)
#define SMN_SCR   __REG(0xe0042010)
#define SMN_BCR   __REG(0xe0042014)
#define SMN_ISR   __REG(0xe0042018)
#define SMN_BBDR __REG(0xe004201C,__WRITE     ,__SMN_BBDR_bits)
#define SMN_CSR   __REG(0xe0042020)
#define  SMN_PLAINTEXT __REG(0xE0042024)
#define  SMN_CIPHERTEXT __REG(0xE0042028)
#define  SMN_IVR  __REG(0xe004202C)
#define SMN_TCR  __REG(0xe0042030)
#define SMN_DDR  __REG(0xe0042034)
#define  SMN_TR   __REG(0xe0042038)

/***************************************************************************
 **
 **  Run-Time Integrity Checker (RTIC)
 **
 ***************************************************************************/
#define RTICSR   __REG(0xe002A000)
#define RTICMD   __REG(0xe002A004)
#define RTICCNTLR __REG(0xe002A008)
#define RTICTR   __REG(0xe002A00C)
#define  RTICAMSAR1 __REG(0xe002A010)
#define  RTICAMLR1 __REG(0xe002A014)
#define  RTICAMSAR2 __REG(0xe002A018)
#define  RTICAMLR2 __REG(0xe002A01C)
#define  RTICBMSAR1 __REG(0xe002A030)
#define  RTICBMLR1 __REG(0xe002A034)
#define  RTICBMSAR2 __REG(0xe002A038)
#define  RTICBMLR2 __REG(0xe002A03C)
#define  RTICCMSAR1 __REG(0xe002A050)
#define  RTICCMLR1 __REG(0xe002A054)
#define  RTICCMSAR2 __REG(0xe002A058)
#define  RTICCMLR2 __REG(0xe002A05C)
#define  RTICDMSAR1 __REG(0xe002A070)
#define  RTICDMLR1 __REG(0xe002A074)
#define  RTICDMSAR2 __REG(0xe002A078)
#define  RTICDMLR2 __REG(0xe002A07C)
#define  RTICFAR  __REG(0xe002A090)
#define RTICWR  __REG(0xe002A094)
#define  RTICAMHR1 __REG(0xe002A0A0)
#define  RTICAMHR2 __REG(0xe002A0A4)
#define  RTICAMHR3 __REG(0xe002A0A8)
#define  RTICAMHR4 __REG(0xe002A0AC)
#define  RTICAMHR5 __REG(0xe002A0B0)
#define  RTICBMHR1 __REG(0xe002A0C0)
#define  RTICBMHR2 __REG(0xe002A0C4)
#define  RTICBMHR3 __REG(0xe002A0C8)
#define  RTICBMHR4 __REG(0xe002A0CC)
#define  RTICBMHR5 __REG(0xe002A0D0)
#define  RTICCMHR1 __REG(0xe002A0E0)
#define  RTICCMHR2 __REG(0xe002A0E4)
#define  RTICCMHR3 __REG(0xe002A0E8)
#define  RTICCMHR4 __REG(0xe002A0EC)
#define  RTICCMHR5 __REG(0xe002A0F0)
#define  RTICDMHR1 __REG(0xe002A100)
#define  RTICDMHR2 __REG(0xe002A104)
#define  RTICDMHR3 __REG(0xe002A108)
#define  RTICDMHR4 __REG(0xe002A10C)
#define  RTICDMHR5 __REG(0xe002A110)

/***************************************************************************
 **
 **  Random Number Generator Accelerator (RNGA)
 **
 ***************************************************************************/
#define RNGACR   __REG(0xe0029000)
#define RNGASR   __REG(0xe0029004)
#define  RNGAER   __REG(0xe0029008)
#define  RNGAFIFO __REG(0xe002900C)
#define RNGAMR   __REG(0xe0029010)
#define RNGAVCR  __REG(0xe0029014)
#define RNGAOCCR __REG(0xe0029018)
#define RNGAO1CR __REG(0xe002901C)
#define RNGAO2CR __REG(0xe0029020)
#define RNGAOCSR __REG(0xe0029024)

/***************************************************************************
 **
 **  SDRAMC
 **
 ***************************************************************************/
#define SDCTL0   __REG(0xeB000000)
#define SDCTL1   __REG(0xeB000004)
#define MISCELLANEOUS  __REG(0xEB000014)
#define SDRST    __REG(0xeB000018)

/***************************************************************************
 **
 **  DMA
 **
 ***************************************************************************/
#define DCR      __REG(0xe0001000)
#define DISR __REG(0xe0001004)
#define DIMR __REG(0xe0001008)
#define DBTOSR   __REG(0xe000100C)
#define DRTOSR   __REG(0xe0001010)
#define DSESR    __REG(0xe0001014)
#define DBOSR    __REG(0xe0001018)
#define DBTOCR   __REG(0xe000101C)
#define WSRA __REG(0xe0001040)
#define XSRA __REG(0xe0001044)
#define YSRA __REG(0xe0001048)
#define WSRB __REG(0xe000104C)
#define XSRB __REG(0xe0001050)
#define YSRB __REG(0xe0001054)
#define SAR0 __REG(0xe0001080)
#define DAR0 __REG(0xe0001084)
#define CNTR0    __REG(0xe0001088)
#define CCR0 __REG(0xe000108C)
#define RSSR0    __REG(0xe0001090)
#define BLR0 __REG(0xe0001094)
#define RTOR0    __REG(0xe0001098)
#define BUCR0_bit     RTOR0_bit
#define BUCR0         RTOR0
#define CCNR0    __REG(0xe000109C)
#define SAR1 __REG(0xe00010C0)
#define DAR1 __REG(0xe00010C4)
#define CNTR1    __REG(0xe00010C8)
#define CCR1 __REG(0xe00010CC)
#define RSSR1    __REG(0xe00010D0)
#define BLR1 __REG(0xe00010D4)
#define RTOR1    __REG(0xe00010D8)
#define BUCR1_bit     RTOR1_bit
#define BUCR1         RTOR1
#define CCNR1    __REG(0xe00010DC)
#define SAR2 __REG(0xe0001100)
#define DAR2 __REG(0xe0001104)
#define CNTR2    __REG(0xe0001108)
#define CCR2 __REG(0xe000110C)
#define RSSR2    __REG(0xe0001110)
#define BLR2 __REG(0xe0001114)
#define RTOR2    __REG(0xe0001118)
#define BUCR2_bit     RTOR2_bit
#define BUCR2         RTOR2
#define CCNR2    __REG(0xe000111C)
#define SAR3 __REG(0xe0001140)
#define DAR3 __REG(0xe0001144)
#define CNTR3    __REG(0xe0001148)
#define CCR3 __REG(0xe000114C)
#define RSSR3    __REG(0xe0001150)
#define BLR3 __REG(0xe0001154)
#define RTOR3    __REG(0xe0001158)
#define BUCR3_bit     RTOR3_bit
#define BUCR3         RTOR3
#define CCNR3    __REG(0xe000115C)
#define SAR4 __REG(0xe0001180)
#define DAR4 __REG(0xe0001184)
#define CNTR4    __REG(0xe0001188)
#define CCR4 __REG(0xe000118C)
#define RSSR4    __REG(0xe0001190)
#define BLR4 __REG(0xe0001194)
#define RTOR4    __REG(0xe0001198)
#define BUCR4_bit     RTOR4_bit
#define BUCR4         RTOR4
#define CCNR4    __REG(0xe000119C)
#define SAR5 __REG(0xe00011C0)
#define DAR5 __REG(0xe00011C4)
#define CNTR5    __REG(0xe00011C8)
#define CCR5 __REG(0xe00011CC)
#define RSSR5    __REG(0xe00011D0)
#define BLR5 __REG(0xe00011D4)
#define RTOR5    __REG(0xe00011D8)
#define BUCR5_bit     RTOR5_bit
#define BUCR5         RTOR5
#define CCNR5    __REG(0xe00011DC)
#define SAR6 __REG(0xe0001200)
#define DAR6 __REG(0xe0001204)
#define CNTR6    __REG(0xe0001208)
#define CCR6 __REG(0xe000120C)
#define RSSR6    __REG(0xe0001210)
#define BLR6 __REG(0xe0001214)
#define RTOR6    __REG(0xe0001218)
#define BUCR6_bit     RTOR6_bit
#define BUCR6         RTOR6
#define CCNR6    __REG(0xe000121C)
#define SAR7 __REG(0xe0001240)
#define DAR7 __REG(0xe0001244)
#define CNTR7    __REG(0xe0001248)
#define CCR7 __REG(0xe000124C)
#define RSSR7    __REG(0xe0001250)
#define BLR7 __REG(0xe0001254)
#define RTOR7    __REG(0xe0001258)
#define BUCR7_bit     RTOR7_bit
#define BUCR7         RTOR7
#define CCNR7    __REG(0xe000125C)
#define SAR8 __REG(0xe0001280)
#define DAR8 __REG(0xe0001284)
#define CNTR8    __REG(0xe0001288)
#define CCR8 __REG(0xe000128C)
#define RSSR8    __REG(0xe0001290)
#define BLR8 __REG(0xe0001294)
#define RTOR8    __REG(0xe0001298)
#define BUCR8_bit     RTOR8_bit
#define BUCR8         RTOR8
#define CCNR8    __REG(0xe000129C)
#define SAR9 __REG(0xe00012C0)
#define DAR9 __REG(0xe00012C4)
#define CNTR9    __REG(0xe00012C8)
#define CCR9 __REG(0xe00012CC)
#define RSSR9    __REG(0xe00012D0)
#define BLR9 __REG(0xe00012D4)
#define RTOR9    __REG(0xe00012D8)
#define BUCR9_bit     RTOR9_bit
#define BUCR9         RTOR9
#define CCNR9    __REG(0xe00012DC)
#define SAR10    __REG(0xe0001300)
#define DAR10    __REG(0xe0001304)
#define CNTR10   __REG(0xe0001308)
#define CCR10   __REG(0xe000130C)
#define RSSR10   __REG(0xe0001310)
#define BLR10    __REG(0xe0001314)
#define RTOR10   __REG(0xe0001318)
#define BUCR10_bit    RTOR10_bit
#define BUCR10        RTOR10
#define CCNR10   __REG(0xe000131C)
#define SAR11    __REG(0xe0001340)
#define DAR11    __REG(0xe0001344)
#define CNTR11   __REG(0xe0001348)
#define CCR11   __REG(0xe000134C)
#define RSSR11   __REG(0xe0001350)
#define BLR11    __REG(0xe0001354)
#define RTOR11   __REG(0xe0001358)
#define BUCR11_bit    RTOR11_bit
#define BUCR11        RTOR11
#define CCNR11   __REG(0xe000135C)
#define SAR12    __REG(0xe0001380)
#define DAR12    __REG(0xe0001384)
#define CNTR12   __REG(0xe0001388)
#define CCR12    __REG(0xe000138C)
#define RSSR12   __REG(0xe0001390)
#define BLR12    __REG(0xe0001394)
#define RTOR12   __REG(0xe0001398)
#define BUCR12_bit    RTOR12_bit
#define BUCR12        RTOR12
#define CCNR12   __REG(0xe000139C)
#define SAR13    __REG(0xe00013C0)
#define DAR13    __REG(0xe00013C4)
#define CNTR13   __REG(0xe00013C8)
#define CCR13    __REG(0xe00013CC)
#define RSSR13   __REG(0xe00013D0)
#define BLR13    __REG(0xe00013D4)
#define RTOR13   __REG(0xe00013D8)
#define BUCR13_bit    RTOR13_bit
#define BUCR13        RTOR13
#define CCNR13   __REG(0xe00013DC)
#define SAR14    __REG(0xe0001400)
#define DAR14    __REG(0xe0001404)
#define CNTR14   __REG(0xe0001408)
#define CCR14   __REG(0xe000140C)
#define RSSR14   __REG(0xe0001410)
#define BLR14    __REG(0xe0001414)
#define RTOR14   __REG(0xe0001418)
#define BUCR14_bit    RTOR14_bit
#define BUCR14        RTOR14
#define CCNR14   __REG(0xe000141C)
#define SAR15    __REG(0xe0001440)
#define DAR15    __REG(0xe0001444)
#define CNTR15   __REG(0xe0001448)
#define CCR15    __REG(0xe000144C)
#define RSSR15   __REG(0xe0001450)
#define BLR15    __REG(0xe0001454)
#define RTOR15   __REG(0xe0001458)
#define BUCR15_bit    RTOR15_bit
#define BUCR15        RTOR15
#define CCNR15   __REG(0xe000145C)

/***************************************************************************
 **
 **  NAND Flash Memory Controller (NANDFC)
 **
 ***************************************************************************/
#define NFC_BUFSIZE __REG(0xeB003E00)
#define     NFC_BAL  __REG(0xeB003E02)
#define NFC_RBA  __REG(0xeB003E04)
#define     NAND_FLASH_ADD __REG(0xEB003E06)
#define     NAND_FLASH_CMD __REG(0xEB003E08)
#define NFC_IBLC __REG(0xeB003E0A)
#define ECC_SRR  __REG(0xeB003E0C)
#define ECC_RSLT_MA __REG(0xeB003E0E)
#define ECC_RSLT_SA __REG(0xeB003E10)
#define NF_WR_PROT __REG(0xeB003E12)
#define     NFC_USBA __REG(0xeB003E14)
#define     NFC_UEBA __REG(0xeB003E16)
#define NF_WR_PROT_STA __REG(0xEB003E18)
#define NAND_FC1 __REG(0xeB003E1A)
#define NAND_FC2 __REG(0xeB003E1C)

/***************************************************************************
 **
 **  EIM
 **
 ***************************************************************************/
#define CS0U __REG(0xeB001000)
#define CS0L __REG(0xeB001004)
#define CS1U __REG(0xeB001008)
#define CS1L __REG(0xeB00100C)
#define CS2U __REG(0xeB001010)
#define CS2L __REG(0xeB001014)
#define CS3U __REG(0xeB001018)
#define CS3L __REG(0xeB00101C)
#define CS4U __REG(0xeB001020)
#define CS4L __REG(0xeB001024)
#define CS5U __REG(0xeB001028)
#define CS5L __REG(0xeB00102C)
#define EIM      __REG(0xeB001030)

/***************************************************************************
 **
 **  Bus Master Interface (BMI)
 **
 ***************************************************************************/
#define BMICTLR1 __REG(0xA0000000)
#define BMICTLR2 __REG(0xA0000004)
#define BMISTR __REG(0xA0000008)
#define  BMIRXD __REG(0xA000000C)
#define  BMITXD __REG(0xA0000010,__WRITE     )

/***************************************************************************
 **
 **  I2C
 **
 ***************************************************************************/
#define IADR __REG(0xe0012000)
#define IFDR __REG(0xe0012004)
#define I2CR __REG(0xe0012008)
#define I2SR __REG(0xe001200C)
#define I2DR __REG(0xe0012010)

/***************************************************************************
 **
 **  SPI1
 **
 ***************************************************************************/
#define  RXDATAREG1 __REG(0xe000E000)
#define  TXDATAREG1 __REG(0xe000E004)
#define CONTROLREG1 __REG(0xe000E008)
#define INTREG1  __REG(0xe000E00C)
#define TESTREG1 __REG(0xe000E010)
#define PERIODREG1 __REG(0xe000E014)
#define DMAREG1  __REG(0xe000E018)
#define RESETREG1 __REG(0xe000E01C)

/***************************************************************************
 **
 **  SPI2
 **
 ***************************************************************************/
#define  RXDATAREG2 __REG(0xe000F000)
#define  TXDATAREG2 __REG(0xe000F004)
#define CONTROLREG2 __REG(0xe000F008)
#define INTREG2  __REG(0xe000F00C)
#define TESTREG2 __REG(0xe000F010)
#define PERIODREG2 __REG(0xe000F014)
#define DMAREG2  __REG(0xe000F018)
#define RESETREG2 __REG(0xe000F01C)

/***************************************************************************
 **
 **  SPI3
 **
 ***************************************************************************/
#define  RXDATAREG3 __REG(0xe0017000)
#define  TXDATAREG3 __REG(0xe0017004)
#define CONTROLREG3 __REG(0xe0017008)
#define INTREG3  __REG(0xe001700C)
#define TESTREG3 __REG(0xe0017010)
#define PERIODREG3 __REG(0xe0017014)
#define DMAREG3  __REG(0xe0017018)
#define RESETREG3 __REG(0xe001701C)

/***************************************************************************
 **
 **  SSI1
 **
 ***************************************************************************/
#define SSI1_STX0 __REG(0xe0010000)
#define SSI1_STX1 __REG(0xe0010004)
#define SSI1_SRX0 __REG(0xe0010008)
#define SSI1_SRX1 __REG(0xe001000C)
#define SSI1_SCR __REG(0xe0010010)
#define SSI1_SISR __REG(0xe0010014)
#define SSI1_SIER __REG(0xe0010018)
#define SSI1_STCR __REG(0xe001001C)
#define SSI1_SRCR __REG(0xe0010020)
#define SSI1_STCCR __REG(0xe0010024)
#define SSI1_SRCCR __REG(0xe0010028)
#define SSI1_SFCSR __REG(0xe001002C)
#define SSI1_STR __REG(0xe0010030)
#define SSI1_SOR __REG(0xe0010034)
#define SSI1_SACNT __REG(0xe0010038)
#define SSI1_SACADD __REG(0xe001003C)
#define SSI1_SACDAT __REG(0xe0010040)
#define SSI1_SATAG __REG(0xe0010044)
#define  SSI1_STMSK __REG(0xe0010048)
#define  SSI1_SRMSK __REG(0xe001004C)

/***************************************************************************
 **
 **  SSI2
 **
 ***************************************************************************/
#define SSI2_STX0 __REG(0xe0011000)
#define SSI2_STX1 __REG(0xe0011004)
#define SSI2_SRX0 __REG(0xe0011008)
#define SSI2_SRX1 __REG(0xe001100C)
#define SSI2_SCR __REG(0xe0011010)
#define SSI2_SISR __REG(0xe0011014)
#define SSI2_SIER __REG(0xe0011018)
#define SSI2_STCR __REG(0xe001101C)
#define SSI2_SRCR __REG(0xe0011020)
#define SSI2_STCCR __REG(0xe0011024)
#define SSI2_SRCCR __REG(0xe0011028)
#define SSI2_SFCSR __REG(0xe001102C)
#define SSI2_STR __REG(0xe0011030)
#define SSI2_SOR __REG(0xe0011034)
#define SSI2_SACNT __REG(0xe0011038)
#define SSI2_SACADD __REG(0xe001103C)
#define SSI2_SACDAT __REG(0xe0011040)
#define SSI2_SATAG  __REG(0xe0011044)
#define  SSI2_STMSK __REG(0xe0011048)
#define  SSI2_SRMSK __REG(0xe001104C)

/***************************************************************************
 **
 **  CSI
 **
 ***************************************************************************/
#define CSICR1 __REG(0x80000000)
#define CSICR2 __REG(0x80000004)
#define CSISR __REG(0x80000008)
#define  CSISTATFIFO __REG(0x8000000C)
#define  CSIRFIFO __REG(0x80000010)
#define CSIRXCNT __REG(0x80000014)
#define CSICR3 __REG(0x8000001C)

/***************************************************************************
 **
 **  LCDC
 **
 ***************************************************************************/
#define LSSAR    __REG(0xe0021000)
#define _LSR __REG(0xe0021004)
#define LVPWR    __REG(0xe0021008)
#define LCPR __REG(0xe002100C)
#define LCWHB    __REG(0xe0021010)
#define LCCMR    __REG(0xe0021014)
#define LPCR __REG(0xe0021018)
#define LHCR __REG(0xe002101C)
#define LVCR __REG(0xe0021020)
#define LPOR __REG(0xe0021024)
#define LSCR __REG(0xe0021028)
#define LPCCR   __REG(0xe002102C)
#define LDCR __REG(0xe0021030)
#define LRMCR    __REG(0xe0021034)
#define LICR __REG(0xe0021038)
#define LIER __REG(0xe002103C)
#define LISR __REG(0xe0021040)
#define LGWSAR   __REG(0xe0021050)
#define LGWSR    __REG(0xe0021054)
#define LGWVPWR  __REG(0xe0021058)
#define LGWPOR   __REG(0xe002105C)
#define LGWPR    __REG(0xe0021060)
#define LGWCR    __REG(0xe0021064)
#define LGWDCR   __REG(0xe0021068)

/***************************************************************************
 **
 **  Smart Liquid Crystal Display Controller (SLCDC)
 **
 ***************************************************************************/
#define DATA_BASE_ADDR __REG(0xE0022000)
#define ATA_BUFF_SIZE __REG(0xE0022004)
#define CMD_BASE_ADDR __REG(0xE0022008)
#define CMD_BUFF_SIZE __REG(0xE002200C)
#define STRING_SIZE __REG(0xe0022010)
#define FIFO_CONFIG __REG(0xe0022014)
#define LCD_CONFIG  __REG(0xe0022018)
#define LCDTRANSCONFIG __REG(0xE002201C)
#define DMA_CTRL_STAT __REG(0xE0022020)
#define LCD_CLK_CONFIG __REG(0xE0022024)
#define LCD_WRITE_DATA __REG(0xE0022028)

/***************************************************************************
 **
 **  enhanced Multimedia Accelerator (eMMA)
 **
 ***************************************************************************/
#define PP_CNTL  __REG(0xe0026000)
#define PP_INTRCNTL __REG(0xe0026004)
#define PP_INTRSTATUS __REG(0xE0026008)
#define  PP_SOURCE_Y_PTR __REG(0xE002600C)
#define  PP_SOURCE_CB_PTR __REG(0xE0026010)
#define  PP_SOURCE_CR_PTR __REG(0xE0026014)
#define  PP_DEST_RGB_PTR __REG(0xE0026018)
#define  PP_QUANTIZER_PTR __REG(0xE002601C)
#define PPP_PROCESS_PARA  __REG(0xE0026020)
#define PP_FRAME_WIDTH __REG(0xE0026024)
#define PP_DISPLAY_WIDTH __REG(0xE0026028)
#define PP_IMAGE_SIZE __REG(0xE002602C)
#define PP_DEST_FRAME_FMT_CNTL __REG(0xE0026030)
#define PP_RESIZE_INDEX __REG(0xE0026034)
#define PP_CSC_COEF_123 __REG(0xE0026038)
#define PP_CSC_COEF_4 __REG(0xE002603C)
#define PP_RESIZE_COEF_TBL0 __REG(0xE0026100)
#define PP_RESIZE_COEF_TBL1 __REG(0xE0026104)
#define PP_RESIZE_COEF_TBL2 __REG(0xE0026108)
#define PP_RESIZE_COEF_TBL3 __REG(0xE002610C)
#define PP_RESIZE_COEF_TBL4 __REG(0xE0026110)
#define PP_RESIZE_COEF_TBL5 __REG(0xE0026114)
#define PP_RESIZE_COEF_TBL6 __REG(0xE0026118)
#define PP_RESIZE_COEF_TBL7 __REG(0xE002611C)
#define PP_RESIZE_COEF_TBL8 __REG(0xE0026120)
#define PP_RESIZE_COEF_TBL9 __REG(0xE0026124)
#define PP_RESIZE_COEF_TBL10 __REG(0xE0026128)
#define PP_RESIZE_COEF_TBL11 __REG(0xE002612C)
#define PP_RESIZE_COEF_TBL12 __REG(0xE0026130)
#define PP_RESIZE_COEF_TBL13 __REG(0xE0026134)
#define PP_RESIZE_COEF_TBL14 __REG(0xE0026138)
#define PP_RESIZE_COEF_TBL15 __REG(0xE002613C)
#define PP_RESIZE_COEF_TBL16 __REG(0xE0026140)
#define PP_RESIZE_COEF_TBL17 __REG(0xE0026144)
#define PP_RESIZE_COEF_TBL18 __REG(0xE0026148)
#define PP_RESIZE_COEF_TBL19 __REG(0xE002614C)
#define PP_RESIZE_COEF_TBL20 __REG(0xE0026150)
#define PP_RESIZE_COEF_TBL21 __REG(0xE0026154)
#define PP_RESIZE_COEF_TBL22 __REG(0xE0026158)
#define PP_RESIZE_COEF_TBL23 __REG(0xE002615C)
#define PP_RESIZE_COEF_TBL24 __REG(0xE0026160)
#define PP_RESIZE_COEF_TBL25 __REG(0xE0026164)
#define PP_RESIZE_COEF_TBL26 __REG(0xE0026168)
#define PP_RESIZE_COEF_TBL27 __REG(0xE002616C)
#define PP_RESIZE_COEF_TBL28 __REG(0xE0026170)
#define PP_RESIZE_COEF_TBL29 __REG(0xE0026174)
#define PP_RESIZE_COEF_TBL30 __REG(0xE0026178)
#define PP_RESIZE_COEF_TBL31 __REG(0xE002617C)
#define PRP_CNTL __REG(0xe0026400)
#define PRP_INTR_CNTL __REG(0xE0026404)
#define PRP_INTRSTATUS __REG(0xE0026408)
#define  PRP_SOURCE_Y_PTR __REG(0xE002640C)
#define  PRP_SOURCE_CB_PTR __REG(0xE0026410)
#define  PRP_SOURCE_CR_PTR __REG(0xE0026414)
#define  PRP_DEST_RGB1_PTR  __REG(0xE0026418)
#define  PRP_DEST_RGB2_PTR  __REG(0xE002641C)
#define  PRP_DEST_Y_PTR __REG(0xE0026420)
#define  PRP_DEST_CB_PTR __REG(0xE0026424)
#define  PRP_DEST_CR_PTR __REG(0xE0026428)
#define PRP_SRC_FRAME_SIZE __REG(0xE002642C)
#define PRP_DEST_CH1_LINE_STRIDE __REG(0xE0026430)
#define PRP_SRC_PIXEL_FORMAT_CNTL __REG(0xE026434)
#define PRP_CH1_PIXEL_FORMAT_CNTL __REG(0xE026438)
#define PRP_CH1_OUT_IMAGE_SIZE __REG(0xE002643C)
#define PRP_CH2_OUT_IMAGE_SIZE __REG(0xE0026440)
#define PRP_SRC_LINE_STRIDE __REG(0xE0026444)
#define PRP_CSC_COEF_012  __REG(0xE0026448)
#define PRP_CSC_COEF_345  __REG(0xE002644C)
#define PRP_CSC_COEF_678 __REG(0xE0026450)
#define PRP_CH1_RZ_HORI_COEF1  __REG(0xE0026454)
#define PRP_CH1_RZ_HORI_COEF2 __REG(0xE0026458)
#define PRP_CH1_RZ_HORI_VALID __REG(0xE002645C)
#define PRP_CH1_RZ_VERT_COEF1 __REG(0xE0026460)
#define PRP_CH1_RZ_VERT_COEF2 __REG(0xE0026464)
#define PRP_CH1_RZ_VERT_VALID __REG(0xE0026468)
#define PRP_CH2_RZ_HORI_COEF1 __REG(0xE002646C)
#define PRP_CH2_RZ_HORI_COEF2 __REG(0xE0026470)
#define PRP_CH2_RZ_HORI_VALID __REG(0xE0026474)
#define PRP_CH2_RZ_VERT_COEF1 __REG(0xE0026478)
#define PRP_CH2_RZ_VERT_COEF2 __REG(0xE002647C)
#define PRP_CH2_RZ_VERT_VALID __REG(0xE0026480)

 /***************************************************************************
 **
 **  MMC/SDHC1
 **
 ***************************************************************************/
#define SDHC1_STR_STP_CLK __REG(0xE0013000)
#define SDHC1_STATUS __REG(0xE0013004)
#define SDHC1_CLK_RATE __REG(0xE0013008)
#define SDHC1_CMD_DAT_CONT __REG(0xE001300C)
#define SDHC1_RES_TO __REG(0xE0013010)
#define SDHC1_READ_TO __REG(0xE0013014)
#define SDHC1_BLK_LEN __REG(0xE0013018)
#define SDHC1_NOB __REG(0xe001301C)
#define SDHC1_REV_NO __REG(0xE0013020)
#define SDHC1_INT_CTRL __REG(0xE0013024)
#define SDHC1_CMD __REG(0xe0013028)
#define SDHC1_ARGH __REG(0xe001302C)
#define SDHC1_ARGL __REG(0xe0013030)
#define SDHC1_RES_FIFO __REG(0xE0013034)
#define SDHC1_BUFFER_ACCESS __REG(0xE0013038)

 /***************************************************************************
 **
 **  MMC/SDHC2
 **
 ***************************************************************************/
#define SDHC2_STR_STP_CLK __REG(0xE0014000)
#define SDHC2_STATUS __REG(0xE0014004)
#define SDHC2_CLK_RATE __REG(0xE0014008)
#define SDHC2_CMD_DAT_CONT __REG(0xE001400C)
#define SDHC2_RES_TO __REG(0xE0014010)
#define SDHC2_READ_TO __REG(0xE0014014)
#define SDHC2_BLK_LEN __REG(0xE0014018)
#define SDHC2_NOB __REG(0xe001401C)
#define SDHC2_REV_NO __REG(0xE0014020)
#define SDHC2_INT_CTRL __REG(0xE0014024)
#define SDHC2_CMD __REG(0xe0014028)
#define SDHC2_ARGH __REG(0xe001402C)
#define SDHC2_ARGL __REG(0xe0014030)
#define SDHC2_RES_FIFO __REG(0xE0014034)
#define SDHC2_BUFFER_ACCESS __REG(0xE0014038)

/***************************************************************************
 **
 **  Digital Audio Mux (AUDMUX)
 **
 ***************************************************************************/
#define HPCR1 __REG(0xe0016000)
#define HPCR2 __REG(0xe0016004)
#define HPCR3 __REG(0xe0016008)
#define PPCR1 __REG(0xe0016010)
#define PPCR2 __REG(0xe0016014)
#define PPCR3 __REG(0xe001601C)

/***************************************************************************
 **
 **  UART1
 **
 ***************************************************************************/
#define URXD_1 __REG(0xe000A000)
#define UTXD_1 __REG(0xe000A040)
#define UCR1_1 __REG(0xe000A080)
#define UCR2_1 __REG(0xe000A084)
#define UCR3_1 __REG(0xe000A088)
#define UCR4_1 __REG(0xe000A08C)
#define UFCR_1 __REG(0xe000A090)
#define USR1_1 __REG(0xe000A094)
#define USR2_1 __REG(0xe000A098)
#define UESC_1 __REG(0xe000A09C)
#define UTIM_1 __REG(0xe000A0A0)
#define UBIR_1 __REG(0xe000A0A4)
#define UBMR_1 __REG(0xe000A0A8)
#define UBRC_1 __REG(0xe000A0AC)
#define ONEMS_1  __REG(0xe000A0B0)
#define UTS_1 __REG(0xe000A0B4)

/***************************************************************************
 **
 **  UART2
 **
 ***************************************************************************/
#define URXD_2 __REG(0xe000B000)
#define UTXD_2 __REG(0xe000B040)
#define UCR1_2 __REG(0xe000B080)
#define UCR2_2 __REG(0xe000B084)
#define UCR3_2 __REG(0xe000B088)
#define UCR4_2 __REG(0xe000B08C)
#define UFCR_2 __REG(0xe000B090)
#define USR1_2 __REG(0xe000B094)
#define USR2_2 __REG(0xe000B098)
#define UESC_2 __REG(0xe000B09C)
#define UTIM_2 __REG(0xe000B0A0)
#define UBIR_2 __REG(0xe000B0A4)
#define UBMR_2 __REG(0xe000B0A8)
#define UBRC_2 __REG(0xe000B0AC)
#define ONEMS_2  __REG(0xe000B0B0)
#define UTS_2 __REG(0xe000B0B4)

/***************************************************************************
 **
 **  UART3
 **
 ***************************************************************************/
#define URXD_3 __REG(0xe000C000)
#define UTXD_3 __REG(0xe000C040)
#define UCR1_3 __REG(0xe000C080)
#define UCR2_3 __REG(0xe000C084)
#define UCR3_3 __REG(0xe000C088)
#define UCR4_3 __REG(0xe000C08C)
#define UFCR_3 __REG(0xe000C090)
#define USR1_3 __REG(0xe000C094)
#define USR2_3 __REG(0xe000C098)
#define UESC_3 __REG(0xe000C09C)
#define UTIM_3 __REG(0xe000C0A0)
#define UBIR_3 __REG(0xe000C0A4)
#define UBMR_3 __REG(0xe000C0A8)
#define UBRC_3 __REG(0xe000C0AC)
#define ONEMS_3  __REG(0xe000C0B0)
#define UTS_3 __REG(0xe000C0B4)

/***************************************************************************
 **
 **  UART4
 **
 ***************************************************************************/
#define URXD_4 __REG(0xe000D000)
#define UTXD_4 __REG(0xe000D040)
#define UCR1_4 __REG(0xe000D080)
#define UCR2_4 __REG(0xe000D084)
#define UCR3_4 __REG(0xe000D088)
#define UCR4_4 __REG(0xe000D08C)
#define UFCR_4 __REG(0xe000D090)
#define USR1_4 __REG(0xe000D094)
#define USR2_4 __REG(0xe000D098)
#define UESC_4 __REG(0xe000D09C)
#define UTIM_4 __REG(0xe000D0A0)
#define UBIR_4 __REG(0xe000D0A4)
#define UBMR_4 __REG(0xe000D0A8)
#define UBRC_4 __REG(0xe000D0AC)
#define ONEMS_4  __REG(0xe000D0B0)
#define UTS_4 __REG(0xe000D0B4)

/***************************************************************************
 **
 **  USB OTG
 **
 ***************************************************************************/
#define HWMODE __REG(0xe0024000)
#define CINT_STAT __REG(0xe0024004)
#define CINT_STEN __REG(0xe0024008)
#define CLK_CTRL __REG(0xe002400C)
#define RST_CTRL __REG(0xe0024010)
#define FRM_INVTL __REG(0xe0024014)
#define FRM_REMAIN __REG(0xe0024018)
#define HNP_CTRL __REG(0xe002401C)
#define HNP_TMR1 __REG(0xe0024020)
#define HNP_TMR2 __REG(0xe0024024)
#define HNP_TMR3 __REG(0xe0024028)
#define HNP_INT_STAT __REG(0xE002402C)
#define HNP_INT_EN __REG(0xe0024030)
#define FUNCOMSTAT __REG(0xe0024040)
#define DEVADDR  __REG(0xe0024044)
#define SYSINTSTAT __REG(0xe0024048)
#define SYSINTEN __REG(0xe002404C)
#define XBUFINTSTAT __REG(0xe0024050)
#define YBUFINTSTAT __REG(0xe0024054)
#define XYINT_INT_EN __REG(0xE0024058)
#define OTG_XFILLSTAT __REG(0xE002405C)
#define OTG_YFILLSTAT __REG(0xE0024060)
#define ENDPNTEN __REG(0xe0024064)
#define ENDPNRDY __REG(0xe0024068)
#define IMEDINT  __REG(0xe002406C)
#define EPNTDONESTAT __REG(0xE0024070)
#define EPNTDONEEN __REG(0xe0024074)
#define EPNTTOGBITS __REG(0xe0024078)
#define FNEPRDYCLR __REG(0xe002407C)
#define HOST_CTRL __REG(0xe0024080)
#define SYSISR __REG(0xe0024088)
#define SYSIEN __REG(0xe002408C)
#define XBUFSTAT __REG(0xe0024098)
#define YBUFSTAT __REG(0xe002409C)
#define XYINTEN __REG(0xe00240A0)
#define XFILLSTAT __REG(0xe00240A8)
#define YFILLSTAT __REG(0xe00240AC)
#define ETDENSET __REG(0xe00240C0)
#define ETDENCLR __REG(0xe00240C4)
#define IMMEDINT __REG(0xe00240CC)
#define ETDDONESTAT __REG(0xe00240D0)
#define ETDDONEN __REG(0xe00240D4)
#define FRMNUB __REG(0xe00240E0)
#define LSTHRESH __REG(0xe00240E4)
#define ROOTHUBA __REG(0xe00240E8)
#define ROOTHUBB __REG(0xe00240EC)
#define ROOTSTAT __REG(0xe00240F0)
#define PORTSTAT1 __REG(0xe00240F4)
#define PORTSTAT2 __REG(0xe00240F8)
#define PORTSTAT3 __REG(0xe00240FC)
#define USB_EP0_DWORD0 __REG(0xE0024200)
#define USB_EP0_DWORD1 __REG(0xE0024204)
#define USB_EP0_DWORD2 __REG(0xE0024208)
#define USB_EP0_DWORD3 __REG(0xE002420C)
#define USB_EP1_DWORD0 __REG(0xE0024210)
#define USB_EP1_DWORD1 __REG(0xE0024214)
#define USB_EP1_DWORD2 __REG(0xE0024218)
#define USB_EP1_DWORD3 __REG(0xE002421C)
#define USB_EP2_DWORD0 __REG(0xE0024220)
#define USB_EP2_DWORD1 __REG(0xE0024224)
#define USB_EP2_DWORD2 __REG(0xE0024228)
#define USB_EP2_DWORD3 __REG(0xE002422C)
#define USB_EP3_DWORD0 __REG(0xE0024230)
#define USB_EP3_DWORD1 __REG(0xE0024234)
#define USB_EP3_DWORD2 __REG(0xE0024238)
#define USB_EP3_DWORD3 __REG(0xE002423C)
#define USB_EP4_DWORD0 __REG(0xE0024240)
#define USB_EP4_DWORD1 __REG(0xE0024244)
#define USB_EP4_DWORD2 __REG(0xE0024248)
#define USB_EP4_DWORD3 __REG(0xE002424C)
#define USB_EP5_DWORD0 __REG(0xE0024250)
#define USB_EP5_DWORD1 __REG(0xE0024254)
#define USB_EP5_DWORD2 __REG(0xE0024258)
#define USB_EP5_DWORD3 __REG(0xE002425C)
#define USB_EP6_DWORD0 __REG(0xE0024260)
#define USB_EP6_DWORD1 __REG(0xE0024264)
#define USB_EP6_DWORD2 __REG(0xE0024268)
#define USB_EP6_DWORD3 __REG(0xE002426C)
#define USB_EP7_DWORD0 __REG(0xE0024270)
#define USB_EP7_DWORD1 __REG(0xE0024274)
#define USB_EP7_DWORD2 __REG(0xE0024278)
#define USB_EP7_DWORD3 __REG(0xE002427C)
#define USB_EP8_DWORD0 __REG(0xE0024280)
#define USB_EP8_DWORD1 __REG(0xE0024284)
#define USB_EP8_DWORD2 __REG(0xE0024288)
#define USB_EP8_DWORD3 __REG(0xE002428C)
#define USB_EP9_DWORD0 __REG(0xE0024290)
#define USB_EP9_DWORD1 __REG(0xE0024294)
#define USB_EP9_DWORD2 __REG(0xE0024298)
#define USB_EP9_DWORD3 __REG(0xE002429C)
#define USB_EP10_DWORD0 __REG(0xE00242A0)
#define USB_EP10_DWORD1 __REG(0xE00242A4)
#define USB_EP10_DWORD2 __REG(0xE00242A8)
#define USB_EP10_DWORD3 __REG(0xE00242AC)
#define USB_EP11_DWORD0 __REG(0xE00242B0)
#define USB_EP11_DWORD1 __REG(0xE00242B4)
#define USB_EP11_DWORD2 __REG(0xE00242B8)
#define USB_EP11_DWORD3 __REG(0xE00242BC)
#define USB_EP12_DWORD0 __REG(0xE00242C0)
#define USB_EP12_DWORD1 __REG(0xE00242C4)
#define USB_EP12_DWORD2 __REG(0xE00242C8)
#define USB_EP12_DWORD3 __REG(0xE00242CC)
#define USB_EP13_DWORD0 __REG(0xE00242D0)
#define USB_EP13_DWORD1 __REG(0xE00242D4)
#define USB_EP13_DWORD2 __REG(0xE00242D8)
#define USB_EP13_DWORD3 __REG(0xE00242DC)
#define USB_EP14_DWORD0 __REG(0xE00242E0)
#define USB_EP14_DWORD1 __REG(0xE00242E4)
#define USB_EP14_DWORD2 __REG(0xE00242E8)
#define USB_EP14_DWORD3 __REG(0xE00242EC)
#define USB_EP15_DWORD0 __REG(0xE00242F0)
#define USB_EP15_DWORD1 __REG(0xE00242F4)
#define USB_EP15_DWORD2 __REG(0xE00242F8)
#define USB_EP15_DWORD3 __REG(0xE00242FC)
#define USB_EP16_DWORD0 __REG(0xE0024300)
#define USB_EP16_DWORD1 __REG(0xE0024304)
#define USB_EP16_DWORD2 __REG(0xE0024308)
#define USB_EP16_DWORD3 __REG(0xE002430C)
#define USB_EP17_DWORD0 __REG(0xE0024310)
#define USB_EP17_DWORD1 __REG(0xE0024314)
#define USB_EP17_DWORD2 __REG(0xE0024318)
#define USB_EP17_DWORD3 __REG(0xE002431C)
#define USB_EP18_DWORD0 __REG(0xE0024320)
#define USB_EP18_DWORD1 __REG(0xE0024324)
#define USB_EP18_DWORD2 __REG(0xE0024328)
#define USB_EP18_DWORD3 __REG(0xE002432C)
#define USB_EP19_DWORD0 __REG(0xE0024330)
#define USB_EP19_DWORD1 __REG(0xE0024334)
#define USB_EP19_DWORD2 __REG(0xE0024338)
#define USB_EP19_DWORD3 __REG(0xE002433C)
#define USB_EP20_DWORD0 __REG(0xE0024340)
#define USB_EP20_DWORD1 __REG(0xE0024344)
#define USB_EP20_DWORD2 __REG(0xE0024348)
#define USB_EP20_DWORD3 __REG(0xE002434C)
#define USB_EP21_DWORD0 __REG(0xE0024350)
#define USB_EP21_DWORD1 __REG(0xE0024354)
#define USB_EP21_DWORD2 __REG(0xE0024358)
#define USB_EP21_DWORD3 __REG(0xE002435C)
#define USB_EP22_DWORD0 __REG(0xE0024360)
#define USB_EP22_DWORD1 __REG(0xE0024364)
#define USB_EP22_DWORD2 __REG(0xE0024368)
#define USB_EP22_DWORD3 __REG(0xE002436C)
#define USB_EP23_DWORD0 __REG(0xE0024370)
#define USB_EP23_DWORD1 __REG(0xE0024374)
#define USB_EP23_DWORD2 __REG(0xE0024378)
#define USB_EP23_DWORD3 __REG(0xE002437C)
#define USB_EP24_DWORD0 __REG(0xE0024380)
#define USB_EP24_DWORD1 __REG(0xE0024384)
#define USB_EP24_DWORD2 __REG(0xE0024388)
#define USB_EP24_DWORD3 __REG(0xE002438C)
#define USB_EP25_DWORD0 __REG(0xE0024390)
#define USB_EP25_DWORD1 __REG(0xE0024394)
#define USB_EP25_DWORD2 __REG(0xE0024398)
#define USB_EP25_DWORD3 __REG(0xE002439C)
#define USB_EP26_DWORD0 __REG(0xE00243A0)
#define USB_EP26_DWORD1 __REG(0xE00243A4)
#define USB_EP26_DWORD2 __REG(0xE00243A8)
#define USB_EP26_DWORD3 __REG(0xE00243AC)
#define USB_EP27_DWORD0 __REG(0xE00243B0)
#define USB_EP27_DWORD1 __REG(0xE00243B4)
#define USB_EP27_DWORD2 __REG(0xE00243B8)
#define USB_EP27_DWORD3 __REG(0xE00243BC)
#define USB_EP28_DWORD0 __REG(0xE00243C0)
#define USB_EP28_DWORD1 __REG(0xE00243C4)
#define USB_EP28_DWORD2 __REG(0xE00243C8)
#define USB_EP28_DWORD3 __REG(0xE00243CC)
#define USB_EP29_DWORD0 __REG(0xE00243D0)
#define USB_EP29_DWORD1 __REG(0xE00243D4)
#define USB_EP29_DWORD2 __REG(0xE00243D8)
#define USB_EP29_DWORD3 __REG(0xE00243DC)
#define USB_EP30_DWORD0 __REG(0xE00243E0)
#define USB_EP30_DWORD1 __REG(0xE00243E4)
#define USB_EP30_DWORD2 __REG(0xE00243E8)
#define USB_EP30_DWORD3 __REG(0xE00243EC)
#define USB_EP31_DWORD0 __REG(0xE00243F0)
#define USB_EP31_DWORD1 __REG(0xE00243F4)
#define USB_EP31_DWORD2 __REG(0xE00243F8)
#define USB_EP31_DWORD3 __REG(0xE00243FC)
#define OTG_EP0_DWORD0 __REG(0xE0024400)
#define OTG_EP0_DWORD1 __REG(0xE0024404)
#define  OTG_EP0_DWORD2 __REG(0xE0024408)
#define OTG_EP0_DWORD3 __REG(0xE002440C)
#define OTG_EP1_DWORD0 __REG(0xE0024410)
#define OTG_EP1_DWORD1 __REG(0xE0024414)
#define  OTG_EP1_DWORD2 __REG(0xE0024418)
#define OTG_EP1_DWORD3 __REG(0xE002441C)
#define OTG_EP2_DWORD0 __REG(0xE0024420)
#define OTG_EP2_DWORD1 __REG(0xE0024424)
#define  OTG_EP2_DWORD2 __REG(0xE0024428)
#define OTG_EP2_DWORD3 __REG(0xE002442C)
#define OTG_EP3_DWORD0 __REG(0xE0024430)
#define OTG_EP3_DWORD1 __REG(0xE0024434)
#define  OTG_EP3_DWORD2 __REG(0xE0024438)
#define OTG_EP3_DWORD3 __REG(0xE002443C)
#define OTG_EP4_DWORD0 __REG(0xE0024440)
#define OTG_EP4_DWORD1 __REG(0xE0024444)
#define  OTG_EP4_DWORD2 __REG(0xE0024448)
#define OTG_EP4_DWORD3 __REG(0xE002444C)
#define OTG_EP5_DWORD0 __REG(0xE0024450)
#define OTG_EP5_DWORD1 __REG(0xE0024454)
#define  OTG_EP5_DWORD2 __REG(0xE0024458)
#define OTG_EP5_DWORD3 __REG(0xE002445C)
#define OTG_EP6_DWORD0 __REG(0xE0024460)
#define OTG_EP6_DWORD1 __REG(0xE0024464)
#define  OTG_EP6_DWORD2 __REG(0xE0024468)
#define OTG_EP6_DWORD3 __REG(0xE002446C)
#define OTG_EP7_DWORD0 __REG(0xE0024470)
#define OTG_EP7_DWORD1 __REG(0xE0024474)
#define  OTG_EP7_DWORD2 __REG(0xE0024478)
#define OTG_EP7_DWORD3 __REG(0xE002447C)
#define OTG_EP8_DWORD0 __REG(0xE0024480)
#define OTG_EP8_DWORD1 __REG(0xE0024484)
#define  OTG_EP8_DWORD2 __REG(0xE0024488)
#define OTG_EP8_DWORD3 __REG(0xE002448C)
#define OTG_EP9_DWORD0 __REG(0xE0024490)
#define OTG_EP9_DWORD1 __REG(0xE0024494)
#define  OTG_EP9_DWORD2 __REG(0xE0024498)
#define OTG_EP9_DWORD3 __REG(0xE002449C)
#define OTG_EP10_DWORD0 __REG(0xE00244A0)
#define OTG_EP10_DWORD1 __REG(0xE00244A4)
#define  OTG_EP10_DWORD2 __REG(0xE00244A8)
#define OTG_EP10_DWORD3 __REG(0xE00244AC)
#define OTG_EP11_DWORD0 __REG(0xE00244B0)
#define OTG_EP11_DWORD1 __REG(0xE00244B4)
#define  OTG_EP11_DWORD2 __REG(0xE00244B8)
#define OTG_EP11_DWORD3 __REG(0xE00244BC)
#define OTG_EP12_DWORD0 __REG(0xE00244C0)
#define OTG_EP12_DWORD1 __REG(0xE00244C4)
#define  OTG_EP12_DWORD2 __REG(0xE00244C8)
#define OTG_EP12_DWORD3 __REG(0xE00244CC)
#define OTG_EP13_DWORD0 __REG(0xE00244D0)
#define OTG_EP13_DWORD1 __REG(0xE00244D4)
#define  OTG_EP13_DWORD2 __REG(0xE00244D8)
#define OTG_EP13_DWORD3 __REG(0xE00244DC)
#define OTG_EP14_DWORD0 __REG(0xE00244E0)
#define OTG_EP14_DWORD1 __REG(0xE00244E4)
#define  OTG_EP14_DWORD2 __REG(0xE00244E8)
#define OTG_EP14_DWORD3 __REG(0xE00244EC)
#define OTG_EP15_DWORD0 __REG(0xE00244F0)
#define OTG_EP15_DWORD1 __REG(0xE00244F4)
#define  OTG_EP15_DWORD2 __REG(0xE00244F8)
#define OTG_EP15_DWORD3 __REG(0xE00244FC)
#define OTG_EP16_DWORD0 __REG(0xE0024500)
#define OTG_EP16_DWORD1 __REG(0xE0024504)
#define  OTG_EP16_DWORD2 __REG(0xE0024508)
#define OTG_EP16_DWORD3 __REG(0xE002450C)
#define OTG_EP17_DWORD0 __REG(0xE0024510)
#define OTG_EP17_DWORD1 __REG(0xE0024514)
#define  OTG_EP17_DWORD2 __REG(0xE0024518)
#define OTG_EP17_DWORD3 __REG(0xE002451C)
#define OTG_EP18_DWORD0 __REG(0xE0024520)
#define OTG_EP18_DWORD1 __REG(0xE0024524)
#define  OTG_EP18_DWORD2 __REG(0xE0024528)
#define OTG_EP18_DWORD3 __REG(0xE002452C)
#define OTG_EP19_DWORD0 __REG(0xE0024530)
#define OTG_EP19_DWORD1 __REG(0xE0024534)
#define  OTG_EP19_DWORD2 __REG(0xE0024538)
#define OTG_EP19_DWORD3 __REG(0xE002453C)
#define OTG_EP20_DWORD0 __REG(0xE0024540)
#define OTG_EP20_DWORD1 __REG(0xE0024544)
#define  OTG_EP20_DWORD2 __REG(0xE0024548)
#define OTG_EP20_DWORD3 __REG(0xE002454C)
#define OTG_EP21_DWORD0 __REG(0xE0024550)
#define OTG_EP21_DWORD1 __REG(0xE0024554)
#define  OTG_EP21_DWORD2 __REG(0xE0024558)
#define OTG_EP21_DWORD3 __REG(0xE002455C)
#define OTG_EP22_DWORD0 __REG(0xE0024560)
#define OTG_EP22_DWORD1 __REG(0xE0024564)
#define  OTG_EP22_DWORD2 __REG(0xE0024568)
#define OTG_EP22_DWORD3 __REG(0xE002456C)
#define OTG_EP23_DWORD0 __REG(0xE0024570)
#define OTG_EP23_DWORD1 __REG(0xE0024574)
#define  OTG_EP23_DWORD2 __REG(0xE0024578)
#define OTG_EP23_DWORD3 __REG(0xE002457C)
#define OTG_EP24_DWORD0 __REG(0xE0024580)
#define OTG_EP24_DWORD1 __REG(0xE0024584)
#define  OTG_EP24_DWORD2 __REG(0xE0024588)
#define OTG_EP24_DWORD3 __REG(0xE002458C)
#define OTG_EP25_DWORD0 __REG(0xE0024590)
#define OTG_EP25_DWORD1 __REG(0xE0024594)
#define  OTG_EP25_DWORD2 __REG(0xE0024598)
#define OTG_EP25_DWORD3 __REG(0xE002459C)
#define OTG_EP26_DWORD0 __REG(0xE00245A0)
#define OTG_EP26_DWORD1 __REG(0xE00245A4)
#define  OTG_EP26_DWORD2 __REG(0xE00245A8)
#define OTG_EP26_DWORD3 __REG(0xE00245AC)
#define OTG_EP27_DWORD0 __REG(0xE00245B0)
#define OTG_EP27_DWORD1 __REG(0xE00245B4)
#define  OTG_EP27_DWORD2 __REG(0xE00245B8)
#define OTG_EP27_DWORD3 __REG(0xE00245BC)
#define OTG_EP28_DWORD0 __REG(0xE00245C0)
#define OTG_EP28_DWORD1 __REG(0xE00245C4)
#define  OTG_EP28_DWORD2 __REG(0xE00245C8)
#define OTG_EP28_DWORD3 __REG(0xE00245CC)
#define OTG_EP29_DWORD0 __REG(0xE00245D0)
#define OTG_EP29_DWORD1 __REG(0xE00245D4)
#define  OTG_EP29_DWORD2 __REG(0xE00245D8)
#define OTG_EP29_DWORD3 __REG(0xE00245DC)
#define OTG_EP30_DWORD0 __REG(0xE00245E0)
#define OTG_EP30_DWORD1 __REG(0xE00245E4)
#define  OTG_EP30_DWORD2 __REG(0xE00245E8)
#define OTG_EP30_DWORD3 __REG(0xE00245EC)
#define OTG_EP31_DWORD0 __REG(0xE00245F0)
#define OTG_EP31_DWORD1 __REG(0xE00245F4)
#define  OTG_EP31_DWORD2 __REG(0xE00245F8)
#define OTG_EP31_DWORD3 __REG(0xE00245FC)
#define USBCTRL  __REG(0xe0024600)
#define DMAREV __REG(0xe0024800)
#define DMAINTSTAT __REG(0xe0024804)
#define DMAINTEN __REG(0xe0024808)
#define  ETDDMAERSTAT __REG(0xE002480C)
#define  EPDMAERSTAT __REG(0xe0024810)
#define  ETDDMAEN __REG(0xe0024820)
#define  EPDMAEN  __REG(0xe0024824)
#define  ETDDMAXTEN __REG(0xe0024828)
#define  EPDMAXTEN __REG(0xe002482C)
#define  ETDDMAENXYT __REG(0xe0024830)
#define  EPDMAENXYT __REG(0xe0024834)
#define  ETCDMABST4EN __REG(0xE0024838)
#define  EPDMABST4EN __REG(0xe002483C)
#define MISCCONTROL __REG(0xe0024840)
#define  ETDDMACHANLCLR __REG(0xE0024848)
#define  EPDMACHANLCLR __REG(0xE002484C)
#define  ETDSMSA0 __REG(0xe0024900)
#define  ETDSMSA1 __REG(0xe0024904)
#define  ETDSMSA2 __REG(0xe0024908)
#define  ETDSMSA3 __REG(0xe002490C)
#define  ETDSMSA4 __REG(0xe0024910)
#define  ETDSMSA5 __REG(0xe0024914)
#define  ETDSMSA6 __REG(0xe0024918)
#define  ETDSMSA7 __REG(0xe002491C)
#define  ETDSMSA8 __REG(0xe0024920)
#define  ETDSMSA9 __REG(0xe0024924)
#define  ETDSMSA10 __REG(0xe0024928)
#define  ETDSMSA11 __REG(0xe002492C)
#define  ETDSMSA12 __REG(0xe0024930)
#define  ETDSMSA13 __REG(0xe0024934)
#define  ETDSMSA14 __REG(0xe0024938)
#define  ETDSMSA15 __REG(0xe002493C)
#define  ETDSMSA16 __REG(0xe0024940)
#define  ETDSMSA17 __REG(0xe0024944)
#define  ETDSMSA18 __REG(0xe0024948)
#define  ETDSMSA19 __REG(0xe002494C)
#define  ETDSMSA20 __REG(0xe0024950)
#define  ETDSMSA21 __REG(0xe0024954)
#define  ETDSMSA22 __REG(0xe0024958)
#define  ETDSMSA23 __REG(0xe002495C)
#define  ETDSMSA24 __REG(0xe0024960)
#define  ETDSMSA25 __REG(0xe0024964)
#define  ETDSMSA26 __REG(0xe0024968)
#define  ETDSMSA27 __REG(0xe002496C)
#define  ETDSMSA28 __REG(0xe0024970)
#define  ETDSMSA29 __REG(0xe0024974)
#define  ETDSMSA30 __REG(0xe0024978)
#define  ETDSMSA31 __REG(0xe002497C)
#define  EPSMSA0 __REG(0xe0024980)
#define  EPSMSA1 __REG(0xe0024984)
#define  EPSMSA2 __REG(0xe0024988)
#define  EPSMSA3 __REG(0xe002498C)
#define  EPSMSA4 __REG(0xe0024990)
#define  EPSMSA5 __REG(0xe0024994)
#define  EPSMSA6 __REG(0xe0024998)
#define  EPSMSA7 __REG(0xe002499C)
#define  EPSMSA8 __REG(0xe00249A0)
#define  EPSMSA9 __REG(0xe00249A4)
#define  EPSMSA10 __REG(0xe00249A8)
#define  EPSMSA11 __REG(0xe00249AC)
#define  EPSMSA12 __REG(0xe00249B0)
#define  EPSMSA13 __REG(0xe00249B4)
#define  EPSMSA14 __REG(0xe00249B8)
#define  EPSMSA15 __REG(0xe00249BC)
#define  EPSMSA16 __REG(0xe00249C0)
#define  EPSMSA17 __REG(0xe00249C4)
#define  EPSMSA18 __REG(0xe00249C8)
#define  EPSMSA19 __REG(0xe00249CC)
#define  EPSMSA20 __REG(0xe00249D0)
#define  EPSMSA21 __REG(0xe00249D4)
#define  EPSMSA22 __REG(0xe00249D8)
#define  EPSMSA23 __REG(0xe00249DC)
#define  EPSMSA24 __REG(0xe00249E0)
#define  EPSMSA25 __REG(0xe00249E4)
#define  EPSMSA26 __REG(0xe00249E8)
#define  EPSMSA27 __REG(0xe00249EC)
#define  EPSMSA28 __REG(0xe00249F0)
#define  EPSMSA29 __REG(0xe00249F4)
#define  EPSMSA30 __REG(0xe00249F8)
#define  EPSMSA31 __REG(0xe00249FC)
#define  ETDDMABUFPTR0 __REG(0xE0024A00)
#define  ETDDMABUFPTR1 __REG(0xE0024A04)
#define  ETDDMABUFPTR2 __REG(0xE0024A08)
#define  ETDDMABUFPTR3 __REG(0xE0024A0C)
#define  ETDDMABUFPTR4 __REG(0xE0024A10)
#define  ETDDMABUFPTR5 __REG(0xE0024A14)
#define  ETDDMABUFPTR6 __REG(0xE0024A18)
#define  ETDDMABUFPTR7 __REG(0xE0024A1C)
#define  ETDDMABUFPTR8 __REG(0xE0024A20)
#define  ETDDMABUFPTR9 __REG(0xE0024A24)
#define  ETDDMABUFPTR10 __REG(0xE0024A28)
#define  ETDDMABUFPTR11 __REG(0xE0024A2C)
#define  ETDDMABUFPTR12 __REG(0xE0024A30)
#define  ETDDMABUFPTR13 __REG(0xE0024A34)
#define  ETDDMABUFPTR14 __REG(0xE0024A38)
#define  ETDDMABUFPTR15 __REG(0xE0024A3C)
#define  ETDDMABUFPTR16 __REG(0xE0024A40)
#define  ETDDMABUFPTR17 __REG(0xE0024A44)
#define  ETDDMABUFPTR18 __REG(0xE0024A48)
#define  ETDDMABUFPTR19 __REG(0xE0024A4C)
#define  ETDDMABUFPTR20 __REG(0xE0024A50)
#define  ETDDMABUFPTR21 __REG(0xE0024A54)
#define  ETDDMABUFPTR22 __REG(0xE0024A58)
#define  ETDDMABUFPTR23 __REG(0xE0024A5C)
#define  ETDDMABUFPTR24 __REG(0xE0024A60)
#define  ETDDMABUFPTR25 __REG(0xE0024A64)
#define  ETDDMABUFPTR26 __REG(0xE0024A68)
#define  ETDDMABUFPTR27 __REG(0xE0024A6C)
#define  ETDDMABUFPTR28 __REG(0xE0024A70)
#define  ETDDMABUFPTR29 __REG(0xE0024A74)
#define  ETDDMABUFPTR30 __REG(0xE0024A78)
#define  ETDDMABUFPTR31 __REG(0xE0024A7C)
#define  EPDMABUFPTR0 __REG(0xE0024A80)
#define  EPDMABUFPTR1 __REG(0xE0024A84)
#define  EPDMABUFPTR2 __REG(0xE0024A88)
#define  EPDMABUFPTR3 __REG(0xE0024A8C)
#define  EPDMABUFPTR4 __REG(0xE0024A90)
#define  EPDMABUFPTR5 __REG(0xE0024A94)
#define  EPDMABUFPTR6 __REG(0xE0024A98)
#define  EPDMABUFPTR7 __REG(0xE0024A9C)
#define  EPDMABUFPTR8 __REG(0xE0024AA0)
#define  EPDMABUFPTR9 __REG(0xE0024AA4)
#define  EPDMABUFPTR10 __REG(0xE0024AA8)
#define  EPDMABUFPTR11 __REG(0xE0024AAC)
#define  EPDMABUFPTR12 __REG(0xE0024AB0)
#define  EPDMABUFPTR13 __REG(0xE0024AB4)
#define  EPDMABUFPTR14 __REG(0xE0024AB8)
#define  EPDMABUFPTR15 __REG(0xE0024ABC)
#define  EPDMABUFPTR16 __REG(0xE0024AC0)
#define  EPDMABUFPTR17 __REG(0xE0024AC4)
#define  EPDMABUFPTR18 __REG(0xE0024AC8)
#define  EPDMABUFPTR19 __REG(0xE0024ACC)
#define  EPDMABUFPTR20 __REG(0xE0024AD0)
#define  EPDMABUFPTR21 __REG(0xE0024AD4)
#define  EPDMABUFPTR22 __REG(0xE0024AD8)
#define  EPDMABUFPTR23 __REG(0xE0024ADC)
#define  EPDMABUFPTR24 __REG(0xE0024AE0)
#define  EPDMABUFPTR25 __REG(0xE0024AE4)
#define  EPDMABUFPTR26 __REG(0xE0024AE8)
#define  EPDMABUFPTR27 __REG(0xE0024AEC)
#define  EPDMABUFPTR28 __REG(0xE0024AF0)
#define  EPDMABUFPTR29 __REG(0xE0024AF4)
#define  EPDMABUFPTR30 __REG(0xE0024AF8)
#define  EPDMABUFPTR31 __REG(0xE0024AFC)

/***************************************************************************
 **
 **  PCMCIA
 **
 ***************************************************************************/
#define PIPR __REG(0xeB002000)
#define PSCR __REG(0xeB002004)
#define PER      __REG(0xeB002008)
#define PBR0 __REG(0xeB00200C)
#define PBR1 __REG(0xeB002010)
#define PBR2 __REG(0xeB002014)
#define PBR3 __REG(0xeB002018)
#define PBR4 __REG(0xeB00201C)
#define POR0 __REG(0xeB002028)
#define POR1 __REG(0xeB00202C)
#define POR2 __REG(0xeB002030)
#define POR3 __REG(0xeB002034)
#define POR4 __REG(0xeB002038)
#define POFR0 __REG(0xeB002044)
#define POFR1 __REG(0xeB002048)
#define POFR2 __REG(0xeB00204C)
#define POFR3 __REG(0xeB002050)
#define POFR4 __REG(0xeB002054)
#define PGCR __REG(0xeB002060)
#define PGSR __REG(0xeB002064)

/***************************************************************************
 **
 **  Keypad Port (KPP)
 **
 ***************************************************************************/
#define KPCR __REG(0xe0008000)
#define KPSR __REG(0xe0008002)
#define KDDR __REG(0xe0008004)
#define KPDR __REG(0xe0008006)

/***************************************************************************
 **
 **  Fast InfraRed Interface (FIRI) Module
 **
 ***************************************************************************/
#define FIRITCR __REG(0xe0028000)
#define FIRITCTR __REG(0xe0028004)
#define FIRIRCR __REG(0xe0028008)
#define FIRITSR __REG(0xe002800C)
#define FIRIRSR __REG(0xe0028010)
#define  FIRITXD __REG(0xe0028014)
#define  FIRIRXD __REG(0xe0028018)
#define FIRICR __REG(0xe002801C)

/***************************************************************************
 **
 **  One Wire
 **
 ***************************************************************************/
#define OW_CONTROL __REG(0xe0009000)
#define OW_TIME_DIVIDER __REG(0xE0009002)
#define OW_RESET __REG(0xe0009004)


/* Assembler specific declarations  ****************************************/

#ifdef __IAR_SYSTEMS_ASM__

#endif    /* __IAR_SYSTEMS_ASM__ */

/***************************************************************************
 **
 **   MC9328MX21 interrupt sources
 **
 ***************************************************************************/
//#define Unused                0              // Unused
//#define Unused                1              // Unused
//#define Unused                2              // Unused
//#define Unused                3              // Unused
//#define Unused                4              // Unused
//#define Unused                5              // Unused
#define NT_CSPI3               6              // Configurable SPI (CSPI3)
#define INT_SRCL               7              // Random Number Generator Accelerator (RNGA)
#define INT_GPIO               8              // General Purpose Input/Output (GPIO)
#define INT_FIRI               9              // Fast Infra Red Interface (FIRI)
#define INT_SDHC2              10             // Secure Digital Host Controller (SDHC2)
#define INT_SDHC1              11             // Secure Digital Host Controller (SDHC1)
#define INT_I2C                12             // I2C Bus Controller (I2C)
#define INT_SS2                13             // Synchronous Serial Interface 2(SSI2)
#define INT_SSI1               14             // Synchronous Serial Interface 1(SSI1)
#define INT_CSPI2              15             // Configurable SPI (CSPI2)
#define INT_CSPI1              16             // Configurable SPI (CSPI1)
#define INT_UART4              17             // UART4
#define INT_UART3              18             // UART3
#define INT_UART2              19             // UART2
#define INT_UART1              20             // UART1
#define INT_KPP                21             // Key Pad Port (KPP)
#define INT_RTC                22             // Real-Time Clock (RTC)
#define INT_PWM                23             // Pulse Width Modulator (PWM)
#define INT_GPT3               24             // General Purpose Timer (GPT3)
#define INT_GPT2               25             // General Purpose Timer (GPT2)
#define INT_GPT1               26             // General Purpose Timer (GPT1)
#define INT_WDOG               27             // Watchdog (WDOG)
#define INT_PCMCIA             28             // PCMCIA/CF Host Controller (PCMCIA)
#define INT_NFC                29             // Nand Flash Controller (NFC)
#define INT_BMI                30             // Bus Master Interface (BMI)
#define INT_CSI                31             // CMOS Sensor Interface (CSI)
#define INT_DMACH0             32             // DMA Channel 0
#define INT_DMACH1             33             // DMA Channel 1
#define INT_DMACH2             34             // DMA Channel 2
#define INT_DMACH3             35             // DMA Channel 3
#define INT_DMACH4             36             // DMA Channel 4
#define INT_DMACH5             37             // DMA Channel 5
#define INT_DMACH6             38             // DMA Channel 6
#define INT_DMACH7             39             // DMA Channel 7
#define INT_DMACH8             40             // DMA Channel 8
#define INT_DMACH9             41             // DMA Channel 9
#define INT_DMACH10            42             // DMA Channel 10
#define INT_DMACH11            43             // DMA Channel 11
#define INT_DMACH12            44             // DMA Channel 12
#define INT_DMACH13            45             // DMA Channel 13
#define INT_DMACH14            46             // DMA Channel 14
#define INT_DMACH15            47             // DMA Channel 15
//#define Reserved               48             // Unused
#define INT_EMMAENC            49             // eMMA Encoder Interrupt
#define INT_EMMADEC            50             // eMMA Decoder Interrupt
#define INT_EMMAPRP            51             // eMMA Pre Processor Interrupt
#define INT_EMMAPP             52             // eMMA Post Processor Interrupt
#define INT_USBWKUP            53             // USBOTG Wakeup Interrupt
#define INT_USBDMA             54             // USBOTG DMA Interrupt
#define INT_USBHOST            55             // USBOTG Host Interrupt
#define INT_USBFUNC            56             // USBOTG Function Interrupt
#define INT_USBMNP             57             // USBOTG HNP Interrupt
#define INT_USBCTRL            58             // USB OTG Control Interrupt
#define INT_SRCH               59             // Run-Time Integrity Checker (RTIC)
#define INT_SLCDC              60             // Smart LCD Controller (SLCDC)
#define INT_LCDC               61             // LCD Controller (LCDC)
//#define Reserved               62             // Unused
//#define Reserved               63             // Unused


#endif    /* __MC9328MX21_H */
