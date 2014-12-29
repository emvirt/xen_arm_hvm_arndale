/*
*********************************************************************************************************
*                                              uC/TCP-IP
*                                      The Embedded TCP/IP Stack
*
*                            (c) Copyright 2004; Micrium, Inc.; Weston, FL
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*
*                                BOARD SUPPORT PACKAGE (BSP) FUNCTIONS
*
*                                          Freescale i.MX21
*
* Filename   : net_bsp.c
* Programmer : Eric Shufro
*********************************************************************************************************
*/
/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>
#include <os/irq.h>
#include <os/lib.h>
#include <os/evtchn.h>
/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


#ifdef CONFIG_XEN
#define  CS8900ABaseAddress               (*((INT16U *)0xEC000000))
#else
#define  CS8900ABaseAddress               (*((INT16U *)0xCC000000))   // 16 bytes long      
#endif

#define  INT_ARM_PortE                                          8     /* ARM IRQ 8 is internally mapped to GPIO Interrupts       */
#define  INT_GPIO_Pin_Mask                               (1 << 11)    /* GPIO Port E, pin 11 is attached to the cs8900 INTRQ pin */
#define  PortE_Edge_Sel                                  (1 << 23)    /* Set pin 11 to high level sensitive. Bits 23:22 = 1:0    */

/*
*********************************************************************************************************
*                                            PROTOTYPES
*********************************************************************************************************
*/

extern void  NetNIC_ISR_Handler(void);

/*$PAGE*/
/*
*********************************************************************************************************
*********************************************************************************************************
*                                  NETWORK INTERFACE CARD FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        NETWORK INTERRUPT INITIALIZATION
*
* Description : This function is called by CS8900_Init() to to initialize the interrupt structure for the NIC.
*
* Arguments   : none
*
* Note(s)     : 1) The CS8900A is connected to external interrupt #4 on the LogicPD board because it
*                  passes through the I/O board.
*********************************************************************************************************
*/

void  NetNIC_IntInit (void)
{
     
     printk("NetNIC_IntInit\n");
     
#ifdef  CONFIG_XEN
     // TODO 
     printk("TODO !!!\n"); 
     bind_pirq(0xcb, (void *)NetNIC_ISR_Handler);
     pirq_unmask_notify(0xcb);
#else     
     BSP_Set_IRQ_Vector(INT_ARM_PortE, NetNIC_ISR_Handler);     /* Insert the CS8900A ISR Handler into the interrupt table */
     BSP_IntEn(INT_ARM_PortE);                                  /* Enable GPIO Port E interrupts                           */
     PTE_ICR1    =   PortE_Edge_Sel;                            /* Set port E pin 11 interrupt to trigger on high level    */
     PTE_IMR     =   INT_GPIO_Pin_Mask;                         /* Unmask Port E, pin 11 interrupts                        */
#endif
     
}


/*
*********************************************************************************************************
*                                    INITIALIZE INTERRUPT CONTROLLER
*
* Description : This function is called to clear the interrupt controller associated with the NIC.
*
* Arguments   : none
*********************************************************************************************************
*/

void  NetNIC_IntClr (void)
{
#ifndef CONFIG_XEN
    PTE_ISR |= INT_GPIO_Pin_Mask;                               /* Clear the port E, pin 11 interrupt flag                 */
#endif

}


/*$PAGE*/
/*
*********************************************************************************************************
*                                           NetNIC_Rd16()
*
* Description : Read 16-bit data value from the Ethernet chip.
*
* Argument(s) : reg_offset      Register address offset.
*
* Return(s)   : 16-bit data read from register.
*
* Caller(s)   : CS8900A_RegRd().
*
* Notes(s)    : 1) You need to know the actual physical address or location of the NIC.  From that, you
*                  simply add the offset passed to this function to this 'base' address.
*********************************************************************************************************
*/

CPU_INT16U  NetNIC_Rd16 (CPU_INT16U reg_offset)
{
   INT16U *CS8900Addr;

   CS8900Addr = &CS8900ABaseAddress;                                 /* Set a pointer to the CS8900 Base Address                */
   return CS8900Addr[reg_offset/2];                                  /* Get the data from the specified offset                  */
                                                                     /* Offset / 2 to make the offset type (8 bit) the same as  */
                                                                     /* the register type (16 bit)                              */
}


/*
*********************************************************************************************************
*                                           NetNIC_Wr16()
*
* Description : Write 16-bit data value to the NIC
*
* Argument(s) : reg_offset      Register address offset.
*
*               val             16-bit data to write to register.
*
* Return(s)   : none.
*
* Caller(s)   : CS8900A_RegRd(),
*               CS8900A_RegWr().
*
* Notes(s)    : 1) You need to know the actual physical address or location of the NIC.  From that, you
*                  simply add the offset passed to this function to this 'base' address.
*********************************************************************************************************
*/

void  NetNIC_Wr16 (CPU_INT16U reg_offset, CPU_INT16U val)
{
   INT16U *targetRegister;

   targetRegister = &CS8900ABaseAddress;                             /* declare a pointer to the cs8900 base address            */ 
   targetRegister[reg_offset/2] = val;                               /* Write the value to the register                         */
                                                                     /* Offset / 2 to make the offset type (8 bit) the same as  */
                                                                     /* the register type (16 bit)                              */
}


/*$PAGE*/
/*
*********************************************************************************************************
*                                         CS8900A_PwrCtrl()
*
* Description : Control power to the CS8900A, if supported by your application's hardware.  This feature
*               would be provided if power consumption is an issue in your application.
*
* Argument(s) : pwr         Control power to the CS8900A :
*
*						        NET_ON              Apply  power to   the CS8900A
*						        NET_OFF             Remove power from the CS8900A
*
* Return(s)   : none.
*
* Caller(s)   : none.
*
* Note(s)     : Not supported on the Freescale i.MX21ADS
*********************************************************************************************************
*/

void  CS8900A_PwrCtrl (CPU_BOOLEAN  pwr)
{
}


/*
*********************************************************************************************************
*                                         CS8900A_Reset_Delay()
*
* Description : Delays the CS8900 initialization task for approximately 10 or more ms while the
*               CS8900 stabilizes after reset.
*
* Argument(s) : None
*
* Return(s)   : none.
*
* Caller(s)   : net_nic.c
*
* Notes       : This functiond does not require the presence of an OS. Spinning a loop for
*             : 10ms or more will suffice.
*********************************************************************************************************
*/

void  NET_BSP_CS8900A_Reset_Delay (void)
{
    OSTimeDlyHMSM(0,0,0,20);                                         /* Delay 20ms while the CS8900 resets                        */
}


/*$PAGE*/
/*
*********************************************************************************************************
*********************************************************************************************************
*                                      NETWORK MODULE FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          NetUtil_TS_Get()
*
* Description : Get current Internet Timestamp.
*
*               (1) "The Timestamp is a right-justified, 32-bit timestamp in milliseconds since midnight
*                    UT [Universal Time]" (RFC #791, Section 3.1 'Options : Internet Timestamp').
*
*               (2) The developer is responsible for providing a real-time clock with correct time-zone
*                   configuration to implement the Internet Timestamp.
*
*
* Argument(s) : none.
*
* Return(s)   : Internet Timestamp.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

NET_TS  NetUtil_TS_Get (void)
{
   NET_TS  ts;

   /* $$$$ Insert code to return Internet Timestamp (see Notes #1 & #2).   */

   ts = NET_TS_NONE;

   return (ts);
}


/*$PAGE*/
/*
*********************************************************************************************************
*********************************************************************************************************
*                            TRANSMISSION CONTROL PROTOCOL LAYER FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        NetTCP_InitTxSeqNbr()
*
* Description : Initialize the TCP Transmit Initial Sequence Counter, 'NetTCP_TxSeqNbrCtr'.
*
*               (1) Possible initialization methods include :
*
*                   (a) Time-based initialization is one preferred method since it more appropriately
*                       provides a pseudo-random initial sequence number.
*                   (b) Hardware-generated random number initialization is NOT a preferred method since it
*                       tends to produce a discrete set of pseudo-random initial sequence numbers--often
*                       the same initial sequence number.
*                   (c) Hard-coded initial sequence number is NOT a preferred method since it is NOT random.
*
*                   See also 'net_tcp.h  MACRO'S  Note #2'.
*
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : NetTCP_Init().
*
* Note(s)     : none.
*********************************************************************************************************
*/

#ifdef  NET_TCP_MODULE_PRESENT
void  NetTCP_InitTxSeqNbr (void)
{

   NetTCP_TxSeqNbrCtr = 5000;
}
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                     NetTCP_TxRTT_GetTS()
*
* Description : Get a TCP Round-Trip Time (RTT) timestamp.
*
*               (1) (a) (1) Although RFC #2988, Section 4 states that "there is no requirement for the
*                           clock granularity G used for computing RTT measurements ... experience has
*                           shown that finer clock granularities (<= 100 msec) perform somewhat better
*                           than more coarse granularities".
*
*                       (2) (A) RFC #2988, Section 2.4 states that "whenever RTO is computed, if it is
*                               less than 1 second then the RTO SHOULD be rounded up to 1 second".
*
*                           (B) RFC #1122, Section 4.2.3.1 states that "the recommended ... RTO ... upper
*                               bound should be 2*MSL" where RFC #793, Section 3.3 'Sequence Numbers :
*                               Knowing When to Keep Quiet' states that "the Maximum Segment Lifetime
*                               (MSL) is ... to be 2 minutes".
*
*                               Therefore, the required upper bound is :
*
*                                   2 * MSL = 2 * 2 minutes = 4 minutes = 240 seconds
*
*                   (b) Therefore, the developer is responsible for providing a timestamp clock with
*                       adequate resolution to satisfy the clock granularity (see Note #1a1) & adequate
*                       range to satisfy the minimum/maximum RTO values (see Note #1a2).
*
*
* Argument(s) : none.
*
* Return(s)   : TCP RTT timestamp, in milliseconds.
*
* Caller(s)   : NetTCP_RxPktValidate(),
*               NetTCP_TxPktPrepareHdr().
*
* Note(s)     : (2) (a) To avoid timestamp calculation overflow, a maximum clock tick threshold value
*                       MUST be configured to truncate all clock tick values.
*
*                   (b) Also, since the clock tick integer will periodically overflow; the maximum
*                       threshold MUST be a multiple of the clock tick to avoid a discontinuity in
*                       the timestamp calculation when the clock tick integer overflows.
*********************************************************************************************************
*/

#ifdef  NET_TCP_MODULE_PRESENT
NET_TCP_TX_RTT_TS_MS  NetTCP_TxRTT_GetTS (void)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    CPU_SR                cpu_sr;
#endif
    NET_TCP_TX_RTT_TS_MS  rtt_ts_ms;
    CPU_INT32U            clk_tick;
    CPU_INT32U            clk_tick_th;


    CPU_CRITICAL_ENTER();
    clk_tick = (CPU_INT32U)OSTime;
    CPU_CRITICAL_EXIT();

    if (OS_TICKS_PER_SEC > 0) {
        clk_tick_th  = (NET_TCP_TX_RTT_TS_MAX                       /* MUST cfg clk tick th ...                         */
                     /  DEF_TIME_NBR_mS_PER_SEC);                   /* ... as multiple of max ts (see Note #2b).        */
        clk_tick    %=  clk_tick_th;                                /* Truncate clk ticks to avoid ovf (see Note #2a).  */

        rtt_ts_ms    = (NET_TCP_TX_RTT_TS_MS)((clk_tick * DEF_TIME_NBR_mS_PER_SEC) / OS_TICKS_PER_SEC);

    } else {
        rtt_ts_ms    = (NET_TCP_TX_RTT_TS_MS)clk_tick;
    }


    return (rtt_ts_ms);
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                     NetTCP_TxConnRTT_GetTS_ms()
*
* Description : Get a TCP Round-Trip Time (RTT) timestamp.
*
*               (1) (a) (1) Although RFC #2988, Section 4 states that "there is no requirement for the
*                           clock granularity G used for computing RTT measurements ... experience has
*                           shown that finer clock granularities (<= 100 msec) perform somewhat better
*                           than more coarse granularities".
*
*                       (2) (A) RFC #2988, Section 2.4 states that "whenever RTO is computed, if it is
*                               less than 1 second then the RTO SHOULD be rounded up to 1 second".
*
*                           (B) RFC #1122, Section 4.2.3.1 states that "the recommended ... RTO ... upper
*                               bound should be 2*MSL" where RFC #793, Section 3.3 'Sequence Numbers :
*                               Knowing When to Keep Quiet' states that "the Maximum Segment Lifetime
*                               (MSL) is ... to be 2 minutes".
*
*                               Therefore, the required upper bound is :
*
*                                   2 * MSL = 2 * 2 minutes = 4 minutes = 240 seconds
*
*                   (b) Therefore, the developer is responsible for providing a timestamp clock with
*                       adequate resolution to satisfy the clock granularity (see Note #1a1) & adequate
*                       range to satisfy the minimum/maximum RTO values (see Note #1a2).
*
*
* Argument(s) : none.
*
* Return(s)   : TCP RTT timestamp, in milliseconds.
*
* Caller(s)   : NetTCP_RxPktValidate(),
*               NetTCP_TxPktPrepareHdr().
*
* Note(s)     : none.
*********************************************************************************************************
*/

#ifdef  NET_TCP_MODULE_PRESENT
NET_TCP_TX_RTT_TS_MS  NetTCP_TxConnRTT_GetTS_ms (void)
{
    NET_TCP_TX_RTT_TS_MS  rtt_ts_ms;


    /* $$$$ Insert code to return TCP RTT timestamp (see Note #1).  */

    rtt_ts_ms = NET_TCP_TX_RTT_TS_NONE;

    return (rtt_ts_ms);
}
#endif

