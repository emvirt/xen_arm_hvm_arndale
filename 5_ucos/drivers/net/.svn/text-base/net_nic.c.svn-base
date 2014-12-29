/*
*********************************************************************************************************
*                                              uC/TCP-IP
*                                      The Embedded TCP/IP Suite
*
*                          (c) Copyright 2003-2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/TCP-IP is provided in source form for FREE evaluation, for educational
*               use or peaceful research.  If you plan on using uC/TCP-IP in a commercial
*               product you need to contact Micrium to properly license its use in your
*               product.  We provide ALL the source code for your convenience and to help
*               you experience uC/TCP-IP.  The fact that the source code is provided does
*               NOT mean that you can use it without paying a licensing fee.
*
*               Network Interface Card (NIC) port files provided, as is, for FREE and do
*               NOT require any additional licensing or licensing fee.
*
*               Knowledge of the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/
#include <os/lib.h> 
#include <cpu.h>
#include <os/irq.h>
/*
*********************************************************************************************************
*
*                                        NETWORK INTERFACE CARD
*
*                                               CS8900A
*
* Filename      : net_nic.c
* Version       : V1.90
* Programmer(s) : EHS
*********************************************************************************************************
* Note(s)       : (1) Supports the Cirrus CS8900A 10 MBPS Ethernet Controller (MAC + PHY)
*
*                         Cirrus Corporation (Cirrus; http://www.cirrus.com)
*
*                 (2) REQUIREs Ethernet Network Interface Layer located in the following network directory :
*
*                         \<Network Protocol Suite>\IF\Ether\
*
*                              where
*                                      <Network Protocol Suite>    directory path for network protocol suite
*********************************************************************************************************
*/

#define  NET_NIC_MODULE

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <net.h>

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#define  CS8900_DBG_PRINT_EN              DEF_DISABLED

                                                                                /* ---------------- CS8900 BUFFERS ------------- */
                                                                                /* Buffer size MUST be divisible by 16 and MUST  */
#define  CS8900_RX_BUF_SIZE                       1536                          /* ... be greater than 1518 or 1522 (VLAN) bytes */
#define  CS8900_TX_BUF_SIZE                       1536
#define  CS8900_NUM_ETH_FRAME_BUF                    5
#define  CS8900_Phy_Reg_Link_Mask              (1 << 7)                         /* LinkOK Bit in CS8900A LineStatus Register     */

/*
*********************************************************************************************************
*                                                MACROS
*********************************************************************************************************
*/
#if (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)

#define  CS8900_NIC_TO_HOST_16(val)             ((((CPU_INT16U)(val) & 0xFF00) >> 8) | \
                                                 (((CPU_INT16U)(val) & 0x00FF) << 8))

#else

#define  CS8900_NIC_TO_HOST_16(val)                            (val)

#endif


#define  CS8900_HOST_TO_NIC_16(val)       CS8900_NIC_TO_HOST_16(val)

#if (CS8900_DBG_PRINT_EN == DEF_ENABLED)
extern  void  Uart_Printf(char *ptr);
#define       CS8900_DBG_PRINT(a)                   Uart_Printf(a)

#else

#define       CS8900_DBG_PRINT(a)

#endif

/*
*********************************************************************************************************
*                                              DATA TYPES
*********************************************************************************************************
*/

typedef struct {
    CPU_INT16U  size;
    CPU_INT08U  Frame[CS8900_RX_BUF_SIZE];
} CS8900_ETH_FRAME;

/*
*********************************************************************************************************
*                                              CONSTANTS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

NET_LOCAL  CS8900_ETH_FRAME  frame_bff[CS8900_NUM_ETH_FRAME_BUF];
NET_LOCAL  CPU_INT08U        frame_bff_head;
NET_LOCAL  CPU_INT08U        frame_bff_tail;
NET_LOCAL  CPU_INT08U        frame_bff_num;

/*
*********************************************************************************************************
*                                      EXTERNAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

NET_EXT void NET_BSP_CS8900A_Reset_Delay(void);

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

NET_LOCAL  void        NetNIC_RxISR_Handler    (void);                          /* ISR for RX interrupts.                        */
NET_LOCAL  void        NetNIC_TxISR_Handler    (void);                          /* ISR for TX interrupts.                        */
NET_LOCAL  void        NetNIC_TxPktDiscard     (NET_ERR      *perr);

                                                                                /* ---------- CS8900 REG FNCTS ----------------- */
NET_LOCAL  CPU_INT16U  CS8900_RegRd            (CPU_INT16U    reg_offset);
NET_LOCAL  void        CS8900_RegWr            (CPU_INT16U    reg_offset,
                                                CPU_INT16U    val);

NET_LOCAL  CPU_INT16U  CS8900_PPRegRd          (CPU_INT16U    regOffset);

NET_LOCAL  void        CS8900_PPRegWr          (CPU_INT16U    regOffset,
                                                CPU_INT16U    val);

NET_LOCAL  CPU_INT32S  CS8900_Reset            (void);

                                                                                /* ---------- CS8900 FNCTS --------------------- */
NET_LOCAL  void        CS8900_Init             (void);


                                                                                /* ---------- CS8900 RX FNCTS ------------------ */
NET_LOCAL  void        CS8900_RxPkt            (void         *ppkt,
                                                CPU_INT16U    size,
                                                NET_ERR      *perr);
NET_LOCAL  void        CS8900_RxPktDiscard     (CPU_INT16U    size);


                                                                                /* ---------- CS8900 TX FNCTS ------------------ */
NET_LOCAL  void        CS8900_TxPkt            (void         *ppkt,
                                                CPU_INT16U    size,
                                                NET_ERR      *perr);


NET_LOCAL CPU_INT32S   CS8900_Int_Receive      (CS8900_ETH_FRAME *pframe,
                                                CPU_INT16U        RxEventStatus);


/*$PAGE*/
/*
*********************************************************************************************************
*                                 CS8900_RegRd()
*
* Description : Read 16 bit data from addressable CS8900A registers
*********************************************************************************************************
*/

NET_LOCAL  CPU_INT16U  CS8900_RegRd (CPU_INT16U reg_offset)
{
    CPU_INT16U  reg_val;


    reg_val = NetNIC_Rd16(reg_offset);
    reg_val = CS8900_NIC_TO_HOST_16(reg_val);
	
    return (reg_val);
}

/*
*********************************************************************************************************
*                                 CS8900_RegWr()
*
* Description : Write 16 bit data to addressable CS8900A registers
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_RegWr (CPU_INT16U reg_offset, CPU_INT16U value)
{
    value = CS8900_HOST_TO_NIC_16(value);
    //printk("NetNIC_Wr16\n");
    NetNIC_Wr16(reg_offset, value);
}

/*
*********************************************************************************************************
*                                 CS8900_PPRegRd()
*
* Description : Read 16 bit data from indirectly accessible CS8900A registers though the packet page port
*********************************************************************************************************
*/

NET_LOCAL  CPU_INT16U  CS8900_PPRegRd (CPU_INT16U regOffset)
{
    CPU_INT16U  data;


    CS8900_RegWr(CS8900_PPTR_OFFSET, regOffset);
    data = CS8900_RegRd(CS8900_PDATA_OFFSET);

    return (data);
}

/*
*********************************************************************************************************
*                                 CS8900_PPRegWr()
*
* Description : Write 16 bit data to indirectly accessible CS8900A registers though the packet page port
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_PPRegWr (CPU_INT16U regOffset, CPU_INT16U val)
{
    //printk("CS8900_PPTR_OFFSET\n");
    CS8900_RegWr(CS8900_PPTR_OFFSET, regOffset);
    //printk("CS8900_PDATA_OFFSET\n");
    CS8900_RegWr(CS8900_PDATA_OFFSET, val);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            NetNIC_Init()
*
* Description : (1) Initialize Network Interface Card :
*
*                   (a) Perform NIC Layer OS initialization
*                   (b) Initialize NIC status
*                   (c) Initialize NIC statistics & error counters
*                   (d) Initialize CS8900
*
*
* Argument(s) : perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                    Network interface card successfully initialized.
*
*                                                                   -------- RETURNED BY NetOS_NIC_Init() : --------
*                               NET_OS_ERR_INIT_NIC_TX_RDY          NIC transmit ready signal NOT successfully
*                                                                       initialized.
*                               NET_OS_ERR_INIT_NIC_TX_RDY_NAME     NIC transmit ready name   NOT successfully
*                                                                       configured.
* Return(s)   : none.
*
* Caller(s)   : Net_Init().
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  NetNIC_Init (NET_ERR  *perr)
{
                                                                   /* --------------- PERFORM NIC/OS INIT ----------------       */

    NetOS_NIC_Init(perr);                                          /* Create NIC objs.                                           */
    if (*perr != NET_OS_ERR_NONE) {
        return;
    }

                                                                   /* ----------------- INIT NIC STATUS ------------------       */
    NetNIC_ConnStatus           =  DEF_ON;


                                                                   /* ------------- INIT NIC STAT & ERR CTRS -------------       */
#if (NET_CTR_CFG_STAT_EN       == DEF_ENABLED)
    NetNIC_StatRxPktCtr         =  0;
    NetNIC_StatTxPktCtr         =  0;
#endif

#if (NET_CTR_CFG_ERR_EN        == DEF_ENABLED)
    NetNIC_ErrRxPktDiscardedCtr =  0;
    NetNIC_ErrTxPktDiscardedCtr =  0;
#endif

                                                                   /* ----------------- INIT CS8900   -------------------        */
    printk("CS8900_Init\n");
    CS8900_Init();

    *perr = NET_NIC_ERR_NONE;
}

/*
*********************************************************************************************************
*                                           NetNIC_IntEn()
*
* Description : Enable NIC interrupts.
*
* Argument(s) : perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                NIC interrupts successfully enabled.
*
* Return(s)   : none.
*
* Caller(s)   : Net_Init().
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  NetNIC_IntEn (NET_ERR  *perr)
{
    CPU_INT16U val;

    
    val   = CS8900_PPRegRd(PP_BusCtl);                           /* Read value from BusCTL register                              */

    val  |= PP_BusCtl_EnableIRQ;                                 /* Set the bit PP_BusCtl_EnableIRQ, for cs8900 global IntEn     */
    CS8900_PPRegWr(PP_BusCtl, val);                              /* Write back to BusCTL register                                */
    *perr = NET_NIC_ERR_NONE;
}

/*
*********************************************************************************************************
*                                       NetNIC_ConnStatusChk()
*
* Description : Check the NIC's network connection status.  This function checks the PHY to see if the
*               connection is still established and sets 'NetNIC_ConnStatus' accordingly.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : ####
*
* Note(s)     : (1) Check NIC connection status :
*
*                   (a) By NIC transmit handler(s)
*                   (b) By NIC status state machine
*                   (c) May be configured with a network timer to execute periodically
*********************************************************************************************************
*/

void  NetNIC_ConnStatusChk (void)
{
    CPU_INT16U  phy_reg_val;


    phy_reg_val           = CS8900_PPRegRd(PP_LineStat);         /* Read value from LineStat register                            */
    phy_reg_val          &= CS8900_Phy_Reg_Link_Mask;            /* Extract the LinkOK information from the register data        */

    if (phy_reg_val      == CS8900_Phy_Reg_Link_Mask) {          /* If Link is on...                                             */
        NetNIC_ConnStatus = DEF_ON;
    } else {
        NetNIC_ConnStatus = DEF_OFF;
    }
}

/*
*********************************************************************************************************
*                                       NetNIC_ConnStatusGet()
*
* Description : Get NIC's network connection status.
*
*               (1) Obtaining the NIC's network connection status is encapsulated in this function for the
*                   possibility that obtaining a NIC's connection status requires a non-trivial procedure.
*
*
* Argument(s) : none.
*
* Return(s)   : NIC network connection status :
*
*                   DEF_OFF         Network connection DOWN.
*                   DEF_ON          Network connection UP.
*
* Caller(s)   : NetIF_Pkt_Tx()
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_BOOLEAN  NetNIC_ConnStatusGet (void)
{
    NetNIC_ConnStatusChk();
    return (NetNIC_ConnStatus);
}

/*
*********************************************************************************************************
*                                        NetNIC_ISR_Handler()
*
* Description : (1) Decode ISR & call appropriate ISR handler :
*
*                   (a) CS8900 Receive Buffer Not Available ISR     NetNIC_RxPktDiscard()
*                   (b) CS8900 Receive  ISR                         NetNIC_RxISR_Handler()
*                   (c) CS8900 Transmit ISR                         NetNIC_TxISR_Handler()
*
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This function is an Interrupt Service Routine
*
* Note(s)     : (1) This function clears the interrupt source(s) on an external interrupt controller
*                   if enabled.
*********************************************************************************************************
*/

void  NetNIC_ISR_Handler (void)
{
    CPU_INT16U  int_stat;
    CPU_INT32S  size;

    //printk("NetNIC_ISR_Handler but do not handle it\n");
    //    int_stat = CS8900_RegRd(CS8900_ISQ_OFFSET);
    //while (int_stat != 0) {
     //   int_stat = CS8900_RegRd(CS8900_ISQ_OFFSET);
     // }
    
    //NetNIC_IntClr();                                               /* Clr int ctrl'r CS8900 int                                  */
    //unmask_evtchn(2);
    //return;
    
    int_stat = CS8900_RegRd(CS8900_ISQ_OFFSET);
    while (int_stat != 0) {
        switch (int_stat&ISQ_EventMask) {
            case ISQ_RxEvent:
                 size = CS8900_Int_Receive(&frame_bff[frame_bff_head], int_stat);
                 if (size > 40) {
                     if (++frame_bff_head >= (CS8900_NUM_ETH_FRAME_BUF - 1)) {
                        frame_bff_head = 0;
                     }
                     NetNIC_RxISR_Handler();
                     CS8900_DBG_PRINT("ISQ_RxEvent\r\n");
                 } else {
                     CS8900_DBG_PRINT("Something wrong\r\n");
                 }
                 break;

            case ISQ_TxEvent:
                 CS8900_DBG_PRINT("ISQ_TxEvent\r\n");
                 NetNIC_TxISR_Handler();
                 break;

            case ISQ_BufEvent:
                 CS8900_DBG_PRINT("ISQ_BufEvent\r\n");
                 break;

            case ISQ_RxMissEvent:
                 CS8900_DBG_PRINT("ISQ_RxMissEvent\r\n");
                 break;

            case ISQ_TxColEvent:
                 CS8900_DBG_PRINT("ISQ_TxColEvent\r\n");           /* counter-overflow report: TxCOL (register 12)               */
                 break;

            default:
                 break;
        }
        int_stat = CS8900_RegRd(CS8900_ISQ_OFFSET);
    }

#if (NET_NIC_CFG_INT_CTRL_EN == DEF_ENABLED)
    NetNIC_IntClr();                                               /* Clr int ctrl'r CS8900 int                                  */
#endif
#ifdef CONFIG_XEN
    unmask_evtchn(2);  // TODO
#endif
}


/*
*********************************************************************************************************
*                                        NetNIC_RxPktGetSize()
*
* Description : Get network packet size from NIC.
*
* Argument(s) : none.
*
* Return(s)   : Size, in octets, of NIC's next network packet.
*
* Caller(s)   : NetIF_RxTaskHandler().
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_INT16U  NetNIC_RxPktGetSize (void)
{
    CPU_INT16U  size;


    size = frame_bff[frame_bff_tail].size;
    return (size);
}


/*
*********************************************************************************************************
*                                           NetNIC_RxPkt()
*
* Description : Read network packet from NIC into buffer.
*
* Argument(s) : ppkt        Pointer to memory buffer to receive NIC packet.
*
*               size        Number of packet frame octets to read into buffer.
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                Packet successfully read.
*                               NET_ERR_INIT_INCOMPLETE         Network initialization NOT complete.
*                               NET_NIC_ERR_NULL_PTR            Argument 'ppkt' passed a NULL pointer.
*                               NET_NIC_ERR_INVALID_SIZE        Invalid size.
*
* Return(s)   : none.
*
* Caller(s)   : NetIF_RxTaskHandler().
*
* Note(s)     : (1) NetNIC_RxPkt() blocked until network initialization completes; perform NO action.
*********************************************************************************************************
*/

void  NetNIC_RxPkt (void        *ppkt,
                    CPU_INT16U   size,
                    NET_ERR     *perr)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
   // CPU_SR  cpu_sr;
#endif


    if (Net_InitDone != DEF_YES) {                                 /* If init NOT complete, exit rx (see Note #2).               */
        *perr = NET_ERR_INIT_INCOMPLETE;
         return;
    }


#if (NET_ERR_CFG_ARG_CHK_DBG_EN == DEF_ENABLED)
                                                                   /* ------------------- VALIDATE PTR -------------------       */
    if (ppkt == (void *)0) {
        *perr = NET_NIC_ERR_NULL_PTR;
         return;
    }

                                                                   /* ------------------- VALIDATE SIZE ------------------       */
    if (size < NET_IF_FRAME_MIN_SIZE) {
        *perr  = NET_NIC_ERR_INVALID_SIZE;
         return;
    }
#endif

    CS8900_RxPkt(ppkt, size, perr);                                /* Rd rx pkt from NIC.                                        */

    if (*perr != NET_NIC_ERR_NONE) {
        return;
    }

    NET_CTR_STAT_INC(NetNIC_StatRxPktCtr);

    *perr = NET_NIC_ERR_NONE;
}


/*
*********************************************************************************************************
*                                        NetNIC_RxPktDiscard()
*
* Description : Discard network packet from NIC to free NIC packet frames for new receive packets.
*
* Argument(s) : size        Number of packet frame octets.
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                Packet successfully discarded.
*                               NET_ERR_INIT_INCOMPLETE         Network initialization NOT complete.
*
* Return(s)   : none.
*
* Caller(s)   : NetIF_RxTaskHandler().
*
* Note(s)     : (1) NetNIC_RxPktDiscard() blocked until network initialization completes; perform NO action.
*
*               (2) #### 'perr' may NOT be necessary (remove before product release if unnecessary).
*********************************************************************************************************
*/

void  NetNIC_RxPktDiscard (CPU_INT16U   size,
                           NET_ERR     *perr)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR  cpu_sr;
#endif


    if (Net_InitDone != DEF_YES) {                                 /* If init NOT complete, exit discard (see Note #1).          */
        *perr = NET_ERR_INIT_INCOMPLETE;
         return;
    }

    CS8900_RxPktDiscard(size);

    NET_CTR_ERR_INC(NetNIC_ErrRxPktDiscardedCtr);

    *perr = NET_NIC_ERR_NONE;
}


/*
*********************************************************************************************************
*                                             NetNIC_TxPkt()
*
* Description : Transmit data packets from network driver layer to network interface card.
*
* Argument(s) : ppkt        Pointer to memory buffer to transmit NIC packet.
*
*               size        Number of packet frame octets to write to frame.
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                Packet successfully transmitted.
*                               NET_ERR_INIT_INCOMPLETE         Network initialization NOT complete.
*
*                                                               - RETURNED BY NetNIC_TxPktDiscard() : -
*                               NET_ERR_TX                      Transmit error; packet discarded.
*
* Return(s)   : none.
*
* Caller(s)   : NetIF_Pkt_Tx().
*
* Note(s)     : (1) NetNIC_TxPkt() blocked until network initialization completes; perform NO action.
*********************************************************************************************************
*/

void  NetNIC_TxPkt (void        *ppkt,
                    CPU_INT16U   size,
                    NET_ERR     *perr)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR  cpu_sr;
#endif


    if (Net_InitDone != DEF_YES) {                                 /* If init NOT complete, exit tx (see Note #1).               */
        *perr = NET_ERR_INIT_INCOMPLETE;
         return;
    }


#if (NET_ERR_CFG_ARG_CHK_DBG_EN == DEF_ENABLED)
    if (ppkt == (void *)0) {                                       /* ------------------- VALIDATE PTR -------------------       */
        NetNIC_TxPktDiscard(perr);
        return;
    }
#endif

    CS8900_TxPkt(ppkt, size, perr);                                /* Tx pkt to CS8900.                                          */

    if (*perr != NET_NIC_ERR_NONE) {
        NetNIC_TxPktDiscard(perr);
        return;
    }

    NET_CTR_STAT_INC(NetNIC_StatTxPktCtr);
}


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           LOCAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       NetNIC_RxISR_Handler()
*
* Description : Signal Network Interface Receive Task that a receive packet is available.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_ISR_Handler().
*
* Note(s)     : (1) NetNIC_ISR_Handler() decodes CS8900 Receive ISR & calls NetNIC_RxISR_Handler().
*********************************************************************************************************
*/

NET_LOCAL  void NetNIC_RxISR_Handler (void)
{
    NET_ERR  err;

                                                                   /* Interrupts are acknowledged when ISR read                  */
                                                                   /* ISR are previously read in NetNIC_ISR_Handler().           */

    NetOS_IF_RxTaskSignal(&err);                                   /* Signal Net IF Rx Task of NIC rx pkt.                       */

    switch (err) {
        case NET_IF_ERR_NONE:
             break;

        case NET_IF_ERR_RX_Q_FULL:

        case NET_IF_ERR_RX_Q_POST_FAIL:

        default:
             NetNIC_RxPktDiscard(0, &err);                         /* If any net drv signal err, discard rx pkt.                 */
             break;
    }
}


/*
*********************************************************************************************************
*                                       NetNIC_TxISR_Handler()
*
* Description : (1) Clear transmit interrupt &/or transmit errors :
*
*                   (a) Acknowledge transmit interrupt
*                   (b) Post transmit FIFO empty signal
*
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_ISR_Handler().
*
* Note(s)     : (2) NetNIC_ISR_Handler() decodes CS8900 Transmit ISR & calls NetNIC_TxISR_Handler().
*********************************************************************************************************
*/

NET_LOCAL  void  NetNIC_TxISR_Handler (void)
{
                                                                  /* ISR are previously read in NetNIC_ISR_Handler().           */
                                                                  /* --------------- POST TX EMPTY SIGNAL ---------------       */
    NetOS_NIC_TxRdySignal();
}


/*
*********************************************************************************************************
*                                        NetNIC_TxPktDiscard()
*
* Description : On any Transmit errors, set error.
*
* Argument(s) : pbuf        Pointer to network buffer.
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_ERR_TX                      Transmit error; packet discarded.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_TxPkt().
*
* Note(s)     : none.
*********************************************************************************************************
*/

NET_LOCAL  void  NetNIC_TxPktDiscard (NET_ERR  *perr)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR  cpu_sr;
#endif


    NET_CTR_ERR_INC(NetNIC_ErrTxPktDiscardedCtr);

    *perr = NET_ERR_TX;
}


/*
*********************************************************************************************************
*                                           CS8900_Init()
*
* Description : (1) Initialize & start CS8900 :
*
*                   (a) Initialize Interrupts
*                   (b) Initialize Registers
*                   (c) Initialize MAC Address
*                   (d) Initialize RX Buffer descriptors
*                   (e) Initialize Auto Negotiation
*                   (f) Enable     Receiver/Transmitter
*                   (g) Initialize External Interrupt Controller    See Note #4
*
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_Init().
*
* Note(s)     : (2) See this 'net_nic.c  CS8900 REGISTER BITS' for register bit summary.
*
*               (3) (a) Assumes MAC address to set has previously been initialized by
*
*                       (1) CS8900's EEPROM         for CS8900_MAC_ADDR_SEL_EEPROM
*                       (2) Application code            for CS8900_MAC_ADDR_SEL_CFG
*
*                   (b) CS8900 NIC module allows of one MAC addresses that will be
*                       used to accept or reject an ethernet packet.
*
*               (4) Interrupts MUST be enabled ONLY after ALL network initialization is complete (see also
*                   'net.c  Net_Init()  Note #4c').
*
*               (5) This function initializes an external interrupt controller (if present) &, if ENABLED,
*                   MUST be developer-implemented in
*
*                       \<Your Product Application>\net_isr.c
*
*                           where
*                                   <Your Product Application>    directory path for Your Product's Application
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_Init (void)
{
    CPU_INT16U  reg_val;
#if (EMAC_CFG_MAC_ADDR_SEL == EMAC_MAC_ADDR_SEL_EEPROM)
	CPU_INT16U  i;
#endif

    frame_bff_head = 0;
    frame_bff_tail = 0;
    frame_bff_num  = 0;

    reg_val = CS8900_Reset();                                     /* Step 1: software reset the chip                             */
    if (reg_val != 0 ) {
        CS8900_DBG_PRINT("CS8900 Error: Reset Failed!\r\n");
        return;
    }
    //printk("PPREgWr...\n");

                                                                  /* Step 2: Configure RxCTL to receive good frames for          */
                                                                  /*         Indivual Addr, Broadcast, and Multicast             */
    CS8900_PPRegWr(PP_RxCTL,
                   PP_RxCTL_RxOK | PP_RxCTL_IA | PP_RxCTL_Broadcast | PP_RxCTL_Multicast);

#if 0
    CS8900_PPRegWr(PP_RxCTL,
                   PP_RxCTL_Promiscuous | PP_RxCTL_RxOK);         /* Step 3: OR set to Promiscuous mode to receive all traffic   */
#endif


    CS8900_PPRegWr(PP_TestCTL, 0);                                /* Step 4: Configure TestCTL (DuplexMode)                      */
                                                                  /*         default: 0:half duplex;  0x4000=Full duplex         */

    CS8900_PPRegWr(PP_LineCTL,                                    /* Step 5: Set SerRxOn, SerTxOn in LineCTL                     */
                   PP_LineCTL_Rx | PP_LineCTL_Tx);

    CS8900_PPRegWr(PP_IntReg, 0);                                 /* Step 6: Set the IRQ number in the chip                      */
                                                                  /*         0:IRQ10; 1:IRQ11 2:IRQ12 3:IRQ5                     */

                                                                  /* Step 7: Initialize RxCFG register for Rx Event Interrupt    */
                                                                  /*         Accept good and bad Rx frames                       */
    CS8900_PPRegWr(PP_RxCFG,
                   PP_RxCFG_RxOK | PP_RxCFG_CRC | PP_RxCFG_RUNT | PP_RxCFG_EXTRA);

#if 0
    CS8900_PPRegWr(PP_RxCFG, PP_RxCFG_RxOK );                     /*         Or just accept good Rx frames and don't worry       */
#endif                                                            /*         about Rx statistics including details for bad ones. */

    CS8900_PPRegWr(PP_TxCFG, PP_TxCFG_ALL_IE);                    /* Step 8: Initialize TxCFG register for Tx Event Interrupt    */
                                                                  /*         Enable all Tx IEs. Please refer to cs8900.h for     */
                                                                  /*         what Tx interrupts are available enabled.           */

    CS8900_PPRegWr(PP_BufCFG, PP_BufCFG_TxRDY);                   /* Step 9: Enable interrupt when ready for Tx                  */

#if (EMAC_CFG_MAC_ADDR_SEL == EMAC_MAC_ADDR_SEL_EEPROM)           /*         MAC address is fetched from EMAC EEPROM             */
    for (i = 0; i < sizeof(NetIF_MAC_Addr); i += sizeof(CPU_INT16U)) {
        reg_val               = CS8900_PPRegRd(PP_IA + i);

        NetIF_MAC_Addr[i]     = (CPU_INT08U) reg_val;
        NetIF_MAC_Addr[i + 1] = (CPU_INT08U)(reg_val  >> DEF_OCTET_NBR_BITS);
    }
#else
        reg_val = (NetIF_MAC_Addr[1] << DEF_OCTET_NBR_BITS) | NetIF_MAC_Addr[0];
        CS8900_PPRegWr(PP_IA + 0, reg_val);
        reg_val = (NetIF_MAC_Addr[3] << DEF_OCTET_NBR_BITS) | NetIF_MAC_Addr[2];
        CS8900_PPRegWr(PP_IA + 2, reg_val);
        reg_val = (NetIF_MAC_Addr[5] << DEF_OCTET_NBR_BITS) | NetIF_MAC_Addr[4];
        CS8900_PPRegWr(PP_IA + 4, reg_val);
#endif

#if 0
CS8900_DBG_PRINT("MAC addr : %x %x %x %x %x %x\r\n",
                 NetIF_MAC_Addr[0],
                 NetIF_MAC_Addr[1],
                 NetIF_MAC_Addr[2],
                 NetIF_MAC_Addr[3],
                 NetIF_MAC_Addr[4],
                 NetIF_MAC_Addr[5]);

#endif

    NetIF_MAC_AddrValid       = DEF_YES;

                                                                  /* ----------------- INIT INT CTRL'R ------------------        */
#if (NET_NIC_CFG_INT_CTRL_EN == DEF_ENABLED)
    NetNIC_IntInit();                                             /* See Note #5. (Enable CPU interrupts to accept CS8900 int    */
#endif
    CS8900_DBG_PRINT("8900 init done\r\n");
}

/*
*********************************************************************************************************
*                                          CS8900_RxPkt()
*
* Description : (1) Read network packet from NIC into buffer :
*
*                   (a) Clear all receiver errors
*                   (b) Find the first buffer marked 'software-owned'
*                       'software owned' means that the NIC has copied a packet frame into it
*                   (c) Read received packet frame from CS8900
*                   (d) Release received packet
*
*
* Argument(s) : ppkt        Pointer to memory buffer to receive NIC packet.
*               ----        Argument checked in NetNIC_RxPkt().
*
*               size        Number of packet frame octets to read into buffer.
*               ----        Argument checked in NetNIC_RxPkt().
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                Packet successfully transmitted.
*                               CS8900_ERR_RX_BUSY              Receiver not ready.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_RxPkt().
*
* Note(s)     : (2) See 'CS8900 RECEIVE BUFFER DESCRIPTOR' for packet frame format.
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_RxPkt (void        *ppkt,
                               CPU_INT16U   size,
                               NET_ERR     *perr)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR      cpu_sr;
#endif
    char       *ptr;


    *perr = NET_NIC_ERR_NONE;

    CPU_CRITICAL_ENTER();
    if (frame_bff_num  == 0) {
        CS8900_DBG_PRINT("Frame buffer underflow\r\n");
        CPU_CRITICAL_EXIT();
        return;
    }

    ptr = (char *)&frame_bff[frame_bff_tail].Frame;
	frame_bff_tail++;

    if (frame_bff_tail >= (CS8900_NUM_ETH_FRAME_BUF - 1)) {
        frame_bff_tail  = 0;
    }
	frame_bff_num--;
    CPU_CRITICAL_EXIT();

    Mem_Copy((char *)ppkt, (char *)ptr,size);
}


/*
*********************************************************************************************************
*                                      CS8900_RxPktDiscard()
*
* Description : Discard network packet from NIC to free NIC packet frames for new receive packets.
*
* Argument(s) : size        Number of packet frame octets.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_RxPktDiscard().
*
* Note(s)     : (1) 'size' NOT required for CS8900 packet discard.
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_RxPktDiscard (CPU_INT16U  size)
{
#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR      cpu_sr;
#endif


    (void)size;

    CPU_CRITICAL_ENTER();
    CPU_CRITICAL_EXIT();
}

/*
*********************************************************************************************************
*                                          CS8900_TxPkt()
*
* Description : (1) Instruct CS8900 NIC to send network packet :
*
*                   (a) Check is transmitter ready.
*                   (b) Copy packet info transmitter buffer
*                   (c) Clear all transmitter errors.
*                   (d) Inform transmitter about buffer address and size.
*                       This starts actual transmission of the packet.
*
*
* Argument(s) : ppkt        Pointer to memory buffer to transmit NIC packet.
*               ----        Argument checked in NetNIC_TxPkt().
*
*               size        Number of packet frame octets to write to frame.
*
*               perr        Pointer to variable that will hold the return error code from this function :
*
*                               NET_NIC_ERR_NONE                Packet successfully transmitted.
*                               CS8900_ERR_TX_BUSY              Transmitter not ready.
*
* Return(s)   : none.
*
* Caller(s)   : NetNIC_TxPkt().
*
* Note(s)     : (2) See 'CS8900 RECEIVE BUFFER DESCRIPTOR' for packet frame format.
*********************************************************************************************************
*/

NET_LOCAL  void  CS8900_TxPkt (void        *ppkt,
                               CPU_INT16U   size,
                               NET_ERR     *perr)
{

#if (CPU_CFG_CRITICAL_METHOD == CPU_CRITICAL_METHOD_STATUS_LOCAL)
    //CPU_SR       cpu_sr;
#endif

    CPU_INT16U   stat;
    CPU_INT16U  *sdata;


    *perr = NET_NIC_ERR_NONE;

    CPU_CRITICAL_ENTER();

    CS8900_RegWr(CS8900_TxCMD_OFFSET, PP_TxCmd_TxStart_Full);     /* Step 1: Write the TX command                                */
    CS8900_RegWr(CS8900_TxLEN_OFFSET, size);                      /* Step 2: Bid for Tx                                          */
                                                                  /*         Write the frame length  (number of bytes to TX)     */

                                                                  /* Note: After the frame length has been written, CS8900       */
                                                                  /* reserves Tx bufferfor this bid no matter PP_BusStat_TxRDY   */
                                                                  /* is set or not.                                              */

    stat = CS8900_PPRegRd(PP_BusStat);                            /* Read BusST to verify it is set as Rdy4TxNow.                */

    if ((stat & PP_BusStat_TxBid) != 0) {                         /* Step 3: check if TxBidErr happens                           */
        CS8900_DBG_PRINT("Tx Bid Error!\r\n");
        CPU_CRITICAL_EXIT();                                      /* Step 3.1: enable interrupts at processor level.             */
        *perr = NET_NIC_ERR_NONE;
        return;
   }

   if ((stat & PP_BusStat_TxRDY) == 0) {                          /* Step 4: check if chip is ready for Tx                       */
                                                                  /*         If Bid4Tx not ready, return immediately and wait    */
                                                                  /*         for ReadyForTx Interrupt.                           */
       CPU_CRITICAL_EXIT();                                       /* Step 4.1: enable interrupts at processor level.             */
       *perr = NET_NIC_ERR_NONE;
       return;
   }

   sdata = (CPU_INT16U *)ppkt;                                    /* Step 5: copy Tx data into CS8900's buffer                   */

    if (size > 0) {                                               /* This actually starts the Txmit                              */
        while (size > 1) {                                        /* Output contiguous words, two bytes at a time.               */
            CS8900_RegWr(CS8900_RTDATA_OFFSET, *sdata);
            sdata++;
            size -= 2;
        }
        if (size == 1) {                                          /* If Odd bytes, copy the last one byte to chip.               */
            CS8900_RegWr(CS8900_RTDATA_OFFSET, (*sdata) & 0x00FF);
        }
    }

    CPU_CRITICAL_EXIT();                                          /* Enable interrupts at processor level                        */
}


/*
*********************************************************************************************************
*                                          CS8900_Reset()
*
* Description : (1) Reset the CS8900 by writing to the Self Control Register
*
* Argument(s) : none.
* Return(s)   : 0, -1 (Pass / Fail
* Caller(s)   : CS8900_Init()
*
* Note(s)     : none.
*********************************************************************************************************
*/

NET_LOCAL  CPU_INT32S  CS8900_Reset (void)
{
    CPU_INT16U  i;
    CPU_INT16U  status;

    //printk("CS8900_PPRegWr\n");
    CS8900_PPRegWr(PP_SelfCtl, PP_SelfCtl_Reset);                 /* Reset chip                                                 */

    //printk("NET_BSP_CS8900A_Reset_Delay\n");
    NET_BSP_CS8900A_Reset_Delay();                                /* Wait for the chip to come out of reset 10ms minimum        */

    //printk("for..\n");
    for (i = 0; i < 3000; i++) {                                  /* check PP_SelfStat_InitD bit if the chip successflly reset  */
       status = (CS8900_PPRegRd(PP_SelfStat)&PP_SelfStat_InitD);
       if (status != 0) {
         //printk("return 0\n");
           return (0);
       }
    }

    return (-1);
}

/*
*********************************************************************************************************
*                                          CS8900_Int_Receive()
*
* Description : (1) Process Receive Interrupts
*
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : NetNIC_ISR_Handler()
*
* Note(s)     : none.
*********************************************************************************************************
*/

NET_LOCAL CPU_INT32S CS8900_Int_Receive (CS8900_ETH_FRAME *pframe, CPU_INT16U RxEventStatus)
{
    CPU_INT16U   val;
    CPU_INT16U   leftLen;
    CPU_INT16U  *pdata;
    CPU_INT08U  *cp;


                                                                  /* Step 1: Determine if there is Rx Error.                     */
    if ((RxEventStatus & PP_RER_RxOK) == 0) {                     /* If RxOk bit is not set, Rx Error occurred                   */
        if ( RxEventStatus & PP_RER_CRC) {
            CS8900_DBG_PRINT("CRC error.\r\n");
        } else if (RxEventStatus & PP_RER_RUNT) {
            CS8900_DBG_PRINT("RUNT error.\r\n");
        } else if (RxEventStatus & PP_RER_EXTRA) {
            CS8900_DBG_PRINT("EXTRA error.\r\n");
        } else {
            CS8900_DBG_PRINT("Unknown Error.\r\n");
        }

        CS8900_PPRegRd(PP_Rx_LENGTH);                             /* Step 2: skip this received error frame.                     */
                                                                  /* Note: Must skip this received error frame.                  */
                                                                  /* Otherwise, CS8900 hangs here.                               */
                                                                  /* Read the length of Rx frame                                 */

        val  = CS8900_PPRegRd(PP_RxCFG);                          /* Write Skip to RxCfg Register and also keep the              */
                                                                  /* current configuration.                                      */
        val |= PP_RxCFG_Skip1;
        CS8900_PPRegWr(PP_RxCFG, val);

        return (-1);                                              /* return failed                                               */
    }

    if (frame_bff_num >= CS8900_NUM_ETH_FRAME_BUF) {
        CS8900_DBG_PRINT("Frame buffer overflow\r\n");
        return (-1);
    }

    frame_bff_num++;

    pframe->size = CS8900_PPRegRd(PP_Rx_LENGTH);                  /* Step 3: Read the length of Rx frame                         */

    pdata        = (CPU_INT16U *)pframe->Frame;                   /* Step 4: Read the Rx data from Chip and store it to          */
                                                                  /*         the stacks buffer                                   */
    leftLen      = pframe->size;

    while (leftLen >= 2) {                                        /* read 2 bytes at a time                                      */
        *pdata++ = CS8900_RegRd(CS8900_RTDATA_OFFSET);
        leftLen -= 2;
    }

    if (leftLen == 1) {                                           /* if odd bytes, read the last byte from chip                  */
        val      = CS8900_RegRd(CS8900_RTDATA_OFFSET);            /* Read the last byte from chip                                */
        cp       = (CPU_INT08U *)pdata;                           /* point to the last one byte of the user buffer               */

        *cp      = (CPU_INT08U)(val & 0xFF);                      /* truncate the word (2-bytes) read from chip to one byte      */
    }

    return (pframe->size);
}
