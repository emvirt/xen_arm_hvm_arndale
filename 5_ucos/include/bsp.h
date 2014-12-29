/*
*********************************************************************************************************
*                                               Freescale i.MX21ADS
*
*                                    (c) Copyright 2005, Micrium, Weston, FL
*                                              All Rights Reserved
*
*
* File : BSP.H
* By   : Eric Shufro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           DEFINES
*********************************************************************************************************
*/

#define  BSP_CLK_ALWAYS    (0)                                          /* Processor clock argument definitions for BSP_ClkFreq()   */
#define  BSP_CLK           (1)
#define  BSP_HCK           (2)
#define  BSP_IPG_CLK       (3)
#define  BSP_NFC_CLK       (4)
#define  BSP_PERCLK1       (5)
#define  BSP_PERCLK2       (6)
#define  BSP_PERCLK3       (7)
#define  BSP_PERCLK4       (8)
#define  BSP_FIRICLK       (9)
#define  BSP_CLK48M       (10)
#define  BSP_SSI1CLK      (11)
#define  BSP_SSI2CLK      (12)
                                                                        /* Extended IO                                              */
                                                                        /* 16 bit data bus for LED and UART enables ...             */
#define  EXTENDED_IO      (*(CPU_INT16U *)0xCC800000) 

/*
*********************************************************************************************************
*                                           DATA TYPES
*********************************************************************************************************
*/

typedef  void (*BSP_FNCT_PTR)(void);

/*
*********************************************************************************************************
*                                            FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  BSP_Init(void);
void  BSP_IntDisAll(void);
void  BSP_IntDis(CPU_INT08U VecNum);
void  BSP_IntEn(CPU_INT08U VecNum);
void  BSP_Set_FIQ_Vector(CPU_INT08U VecNum, BSP_FNCT_PTR BSP_FIQ_VEC);
void  BSP_Set_IRQ_Vector(CPU_INT08U VecNum, BSP_FNCT_PTR BSP_IRQ_VEC);
CPU_INT32U  BSP_ClkFreq(CPU_INT08U  selclk);

void  Ser_WrStr(CPU_INT08U *s);
void  Ser_RdStr(CPU_INT08U *s, CPU_INT16U numBytes);
void  Ser_Printf(CPU_INT08U *format, ...);
void  Ser_Init(CPU_INT32U baud);
void  Ser_WrByte(CPU_INT08U b);
CPU_INT08U  Ser_RdByte(void);



/*
*********************************************************************************************************
*                                             LED SERVICES
*********************************************************************************************************
*/

void  LED_Init(void);
void  LED_On(CPU_INT08U led);
void  LED_Off(CPU_INT08U led);
void  LED_Toggle(CPU_INT08U led);

/*
*********************************************************************************************************
*                                             TICK SERVICES
*********************************************************************************************************
*/

void Tmr_TickISR_Handler();

/*
*********************************************************************************************************
*                                           CONFIGURATION CHECKING
*********************************************************************************************************
*/

