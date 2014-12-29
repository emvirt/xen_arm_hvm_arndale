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
//#include <net/net_err.h>
//typedef  CPU_INT16U  CPU_INT16U;

/*
*********************************************************************************************************
*
*                                        NETWORK INTERFACE CARD
*
*                                               CS8900A
*
* Filename      : net_nic.h
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

/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   NET_NIC_MODULE
#define  NET_NIC_EXT
#else
#define  NET_NIC_EXT  extern
#endif

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

                                                                /* Assumption - all registers are 16 bits                 */
                                                                /* Directly visible registers through IP Port             */
#define CS8900_RTDATA_OFFSET    0x00
#define CS8900_TxCMD_OFFSET     0x04
#define CS8900_TxLEN_OFFSET     0x06
#define CS8900_ISQ_OFFSET       0x08
#define CS8900_PPTR_OFFSET      0x0A
#define CS8900_PDATA_OFFSET     0x0C

                                                                /* ISQ Events                                             */
#define ISQ_RxEvent             0x04
#define ISQ_TxEvent             0x08
#define ISQ_BufEvent            0x0C
#define ISQ_RxMissEvent         0x10
#define ISQ_TxColEvent          0x12
#define ISQ_EventMask           0x3F

                                                                /* Registers avail. via "page pointer" (indirect access.) */
#define PP_ChipID               0x0000                          /* Chip identifier - must be 0x630E                       */
#define PP_ChipRev              0x0002                          /* Chip revision, model codes                             */

#define PP_IntReg               0x0022                          /* Interrupt configuration                                */
#define PP_IntReg_IRQ0          0x0000                          /* Use INTR0 pin                                          */
#define PP_IntReg_IRQ1          0x0001                          /* Use INTR1 pin                                          */
#define PP_IntReg_IRQ2          0x0002                          /* Use INTR2 pin                                          */
#define PP_IntReg_IRQ3          0x0003                          /* Use INTR3 pin                                          */

#define PP_RxCFG                0x0102                          /* Receiver configuration                                 */
#define PP_RxCFG_Skip1          0x0040                          /* Skip (i.e. discard) current frame                      */
#define PP_RxCFG_Stream         0x0080                          /* Enable streaming mode                                  */
#define PP_RxCFG_RxOK           0x0100                          /* RxOK interrupt enable                                  */
#define PP_RxCFG_RxDMAonly      0x0200                          /* Use RxDMA for all frames                               */
#define PP_RxCFG_AutoRxDMA      0x0400                          /* Select RxDMA automatically                             */
#define PP_RxCFG_BufferCRC      0x0800                          /* Include CRC characters in frame                        */
#define PP_RxCFG_CRC            0x1000                          /* Enable interrupt on CRC error                          */
#define PP_RxCFG_RUNT           0x2000                          /* Enable interrupt on RUNT frames                        */
#define PP_RxCFG_EXTRA          0x4000                          /* Enable interrupt on frames with extra data             */

#define PP_RxCTL                0x0104                          /* Receiver control                                       */
#define PP_RxCTL_IAHash         0x0040                          /* Accept frames that match hash                          */
#define PP_RxCTL_Promiscuous    0x0080                          /* Accept any frame                                       */
#define PP_RxCTL_RxOK           0x0100                          /* Accept well formed frames                              */
#define PP_RxCTL_Multicast      0x0200                          /* Accept multicast frames                                */
#define PP_RxCTL_IA             0x0400                          /* Accept frame that matches IA                           */
#define PP_RxCTL_Broadcast      0x0800                          /* Accept broadcast frames                                */
#define PP_RxCTL_CRC            0x1000                          /* Accept frames with bad CRC                             */
#define PP_RxCTL_RUNT           0x2000                          /* Accept runt frames                                     */
#define PP_RxCTL_EXTRA          0x4000                          /* Accept frames that are too long                        */

#define PP_TxCFG                0x0106                          /* Transmit configuration                                 */
#define PP_TxCFG_CRS            0x0040                          /* Enable interrupt on loss of carrier                    */
#define PP_TxCFG_SQE            0x0080                          /* Enable interrupt on Signal Quality Error               */
#define PP_TxCFG_TxOK           0x0100                          /* Enable interrupt on successful xmits                   */
#define PP_TxCFG_Late           0x0200                          /* Enable interrupt on "out of window"                    */
#define PP_TxCFG_Jabber         0x0400                          /* Enable interrupt on jabber detect                      */
#define PP_TxCFG_Collision      0x0800                          /* Enable interrupt if collision                          */
#define PP_TxCFG_16Collisions   0x8000                          /* Enable interrupt if > 16 collisions                    */
#define PP_TxCFG_ALL_IE         0x87C0                          /* Mask for all Tx events                                 */

#define PP_TxCmd                0x0108                          /* Transmit command status                                */
#define PP_TxCmd_TxStart_5      0x0000                          /* Start after 5 bytes in buffer                          */
#define PP_TxCmd_TxStart_381    0x0040                          /* Start after 381 bytes in buffer                        */
#define PP_TxCmd_TxStart_1021   0x0080                          /* Start after 1021 bytes in buffer                       */
#define PP_TxCmd_TxStart_Full   0x00C0                          /* Start after all bytes loaded                           */
#define PP_TxCmd_Force          0x0100                          /* Discard any pending packets                            */
#define PP_TxCmd_OneCollision   0x0200                          /* Abort after a single collision                         */
#define PP_TxCmd_NoCRC          0x1000                          /* Do not add CRC                                         */
#define PP_TxCmd_NoPad          0x2000                          /* Do not pad short packets                               */

#define PP_BufCFG               0x010A                          /* Buffer configuration                                   */
#define PP_BufCFG_SWI           0x0040                          /* Force interrupt via software                           */
#define PP_BufCFG_RxDMA         0x0080                          /* Enable interrupt on Rx DMA                             */
#define PP_BufCFG_TxRDY         0x0100                          /* Enable interrupt when ready for Tx                     */
#define PP_BufCFG_TxUE          0x0200                          /* Enable interrupt in Tx underrun                        */
#define PP_BufCFG_RxMiss        0x0400                          /* Enable interrupt on missed Rx packets                  */
#define PP_BufCFG_Rx128         0x0800                          /* Enable Rx interrupt after 128 bytes                    */
#define PP_BufCFG_TxCol         0x1000                          /* Enable int on Tx collision ctr overflow                */
#define PP_BufCFG_Miss          0x2000                          /* Enable int on Rx miss ctr overflow                     */
#define PP_BufCFG_RxDest        0x8000                          /* Enable int on Rx dest addr match                       */

#define PP_LineCTL              0x0112                          /* Line control                                           */
#define PP_LineCTL_Rx           0x0040                          /* Enable receiver                                        */
#define PP_LineCTL_Tx           0x0080                          /* Enable transmitter                                     */

#define PP_TestCTL              0x0118                          /* Test control                                           */
#define PP_TestCTL_DisableLT    0x0080                          /* Disable LT                                             */
#define PP_TestCTL_FDX          0x4000                          /* Full Dulpex Mode                                       */

#define PP_RER                  0x0124                          /* Receive event                                          */
#define PP_RER_IAHash           0x0040                          /* Frame hash match                                       */
#define PP_RER_Dribble          0x0080                          /* Frame had 1-7 extra bits after last byte               */
#define PP_RER_RxOK             0x0100                          /* Frame received with no errors                          */
#define PP_RER_Hashed           0x0200                          /* Frame address hashed OK                                */
#define PP_RER_IA               0x0400                          /* Frame address matched IA                               */
#define PP_RER_Broadcast        0x0800                          /* Broadcast frame                                        */
#define PP_RER_CRC              0x1000                          /* Frame had CRC error                                    */
#define PP_RER_RUNT             0x2000                          /* Runt frame                                             */
#define PP_RER_EXTRA            0x4000                          /* Frame was too long                                     */

#define PP_TER                  0x0128                          /* Transmit event                                         */
#define PP_TER_CRS              0x0040                          /* Carrier lost                                           */
#define PP_TER_SQE              0x0080                          /* Signal Quality Error                                   */
#define PP_TER_TxOK             0x0100                          /* Packet sent without error                              */
#define PP_TER_Late             0x0200                          /* Out of window                                          */
#define PP_TER_Jabber           0x0400                          /* Stuck transmit?                                        */
#define PP_TER_NumCollisions    0x7800                          /* Number of collisions                                   */
#define PP_TER_16Collisions     0x8000                          /* > 16 collisions                                        */

#define PP_SelfCtl              0x0114                          /* Chip control                                           */
#define PP_SelfCtl_Reset        0x0040                          /* Self-clearing reset                                    */

#define PP_BusCtl               0x0116                          /* Bus control                                            */
#define PP_BusCtl_ResetRxDMA    0x0040                          /* Reset receiver DMA engine                              */
#define PP_BusCtl_DMAextend     0x0100
#define PP_BusCtl_UseSA         0x0200
#define PP_BusCtl_MemoryE       0x0400                          /* Enable "memory mode"                                   */
#define PP_BusCtl_DMAburst      0x0800
#define PP_BusCtl_IOCH_RDYE     0x1000
#define PP_BusCtl_RxDMAsize     0x2000
#define PP_BusCtl_EnableIRQ     0x8000                          /* Enable interrupts                                      */

#define PP_BufEvent             0x012C                          /* Buffer Event                                           */
#define PP_BufEvent_SWInt	    0x0040
#define PP_BufEvent_Rdy4Tx	    0x0100
#define PP_BufEvent_TxUnder 	0x0200
#define PP_BufEvent_RxMiss	    0x0400


#define PP_LineStat             0x0134                          /* Line status                                            */
#define PP_LineStat_LinkOK      0x0080                          /* Line is connected and working                          */
#define PP_LineStat_AUI         0x0100                          /* Connected via AUI                                      */
#define PP_LineStat_10BT        0x0200                          /* Connected via twisted pair                             */
#define PP_LineStat_Polarity    0x1000                          /* Line polarity OK (10BT only)                           */
#define PP_LineStat_CRS         0x4000                          /* Frame being received                                   */

#define PP_SelfStat             0x0136                          /* Chip status                                            */
#define PP_SelfStat_InitD       0x0080                          /* Chip initialization complete                           */
#define PP_SelfStat_SIBSY       0x0100                          /* EEPROM is busy                                         */
#define PP_SelfStat_EEPROM      0x0200                          /* EEPROM present                                         */
#define PP_SelfStat_EEPROM_OK   0x0400                          /* EEPROM checks out                                      */
#define PP_SelfStat_ELPresent   0x0800                          /* External address latch logic available                 */
#define PP_SelfStat_EEsize      0x1000                          /* Size of EEPROM                                         */

#define PP_BusStat              0x0138                          /* Bus status                                             */
#define PP_BusStat_TxBid        0x0080                          /* Tx error                                               */
#define PP_BusStat_TxRDY        0x0100                          /* Ready for Tx data                                      */

#define PP_LAF                  0x0150                          /* Logical address filter (6 bytes)                       */
#define PP_IA                   0x0158                          /* Individual address (MAC)                               */

#define PP_Rx_LENGTH            0x0402                          /* Receive length, in bytes                               */

/*
*********************************************************************************************************
*                               NIC DRIVER LAYER / ETHERNET ERROR CODES
*
* Note(s) : (1) ALL NIC-independent     error codes #define'd in      'net_err.h';
*               ALL CS8900A-specific    error codes #define'd in this 'net_nic.h'.
*
*           (2) Network error code '10,000' series reserved for NIC drivers.
*********************************************************************************************************
*/

#define  CS8900_ERR_RX_BUSY                        10700
#define  CS8900_ERR_TX_BUSY                        10701


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

NET_NIC_EXT  CPU_BOOLEAN  NetNIC_ConnStatus;                    /* NIC's connection status : DEF_ON/DEF_OFF.              */

#if (NET_CTR_CFG_STAT_EN == DEF_ENABLED)                        /* -------------------- NET DRV STATS ------------------- */
NET_NIC_EXT  NET_CTR      NetNIC_StatRxPktCtr;
NET_NIC_EXT  NET_CTR      NetNIC_StatTxPktCtr;
#endif

#if (NET_CTR_CFG_ERR_EN  == DEF_ENABLED)                        /* -------------------- NET DRV ERRS -------------------- */
NET_NIC_EXT  NET_CTR      NetNIC_ErrRxPktDiscardedCtr;
NET_NIC_EXT  NET_CTR      NetNIC_ErrTxPktDiscardedCtr;
#endif


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void         NetNIC_Init             (CPU_INT16U      *perr);

void         NetNIC_IntEn            (CPU_INT16U      *perr);

void         NetNIC_MAC_AddrSet      (CPU_INT08U   *paddr,      CPU_INT16U     *perr);


                                                                /* -------------------- STATUS FNCTS -------------------- */
CPU_BOOLEAN  NetNIC_ConnStatusGet    (void);

//void         NetNIC_ISR_Handler      (void);                    /* Decode & handle rx/tx ISRs.                            */


                                                                /* ---------------------- RX FNCTS ---------------------- */
CPU_INT16U   NetNIC_RxPktGetSize     (void);                    /* Get NIC rx pkt size.                                   */

void         NetNIC_RxPkt            (void         *ppkt,       /* Rx pkt from NIC.                                       */
                                      CPU_INT16U    size,
                                      CPU_INT16U      *perr);

void         NetNIC_RxPktDiscard     (CPU_INT16U    size,       /* Discard rx pkt in NIC.                                 */
                                      CPU_INT16U      *perr);


                                                                /* ---------------------- TX FNCTS ---------------------- */
void         NetNIC_TxPkt            (void         *ppkt,
                                      CPU_INT16U    size,
                                      CPU_INT16U      *perr);


                                                                /* -------------------- PHYTER FNCTS -------------------- */
void         NetNIC_PhyInit          (CPU_INT16U      *perr);

CPU_INT16U   NetNIC_PhyRegRd         (CPU_INT08U    phy,
                                      CPU_INT08U    reg,
                                      CPU_INT16U      *perr);

void         NetNIC_PhyRegWr         (CPU_INT08U    phy,
                                      CPU_INT08U    reg,
                                      CPU_INT16U    val,
                                      CPU_INT16U      *perr);


                                                                /* ------------------ CS8900A REG FNCTS ----------------- */
#if (NET_DBG_CFG_TEST_EN == DEF_ENABLED)
CPU_INT32U   CS8900_RegRd            (CPU_INT32U    reg_bank,
                                      CPU_INT32U    reg_offset);
#endif


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                      DEFINED IN OS'S  net_os.c
*********************************************************************************************************
*/

void         NetOS_NIC_Init          (CPU_INT16U      *perr);      /* Create Drv objs & start Drv tasks.                     */

void         NetOS_NIC_TxRdyWait     (CPU_INT16U      *perr);      /* Wait on drv tx empty signal from NIC.                  */

void         NetOS_NIC_TxRdySignal   (void);                    /* Post    drv tx empty signal from NIC.                  */


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                    DEFINED IN PRODUCT'S  net_bsp.c
*********************************************************************************************************
*/

CPU_INT16U   NetNIC_Rd16             (CPU_INT16U    reg_offset);

void         NetNIC_Wr16             (CPU_INT16U    reg_offset,
                                      CPU_INT16U    val);
                                                                /* See this 'net_nic.h  Notes #3b & #3c'.                 */
CPU_INT32U   NetNIC_Rd32             (CPU_INT32U    reg_offset);

void         NetNIC_Wr32             (CPU_INT32U    reg_offset,
                                      CPU_INT32U    val);

void         CS8900_PhyFrameDly      (void);                    /* Implement ???? dly; #### remove if unnecessary.        */
                                                                /*   MAY  use OS dly to preempt or tmr loop.              */

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                  DEFINED IN PRODUCT's  net_isr_a.s
*********************************************************************************************************
*/

void         NetNIC_ISR              (void);


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*                                    DEFINED IN PRODUCT'S  net_isr.c
*
* Note(s) : (1) See this 'net_nic.c  CS8900_Init()     Note #5'.
*
*           (2) See this 'net_nic.c  NetNIC_ISR_Handler()  Note #3'.
*********************************************************************************************************
*/

#if (NET_NIC_CFG_INT_CTRL_EN == DEF_ENABLED)
void         NetNIC_IntInit          (void);                    /* Init int ctrl'r        [see Note #1].                  */

void         NetNIC_IntClr           (void);                    /* Clr  int ctrl'r src(s) [see Note #2].                  */
#endif


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

