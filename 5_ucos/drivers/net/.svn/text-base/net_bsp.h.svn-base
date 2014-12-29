/*
*********************************************************************************************************
*                                              uC/TCP-IP
*                                      The Embedded TCP/IP Suite
*
*                          (c) Copyright 2003-2005; Micrium, Inc.; Weston, FL
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                BOARD SUPPORT PACKAGE (BSP) FUNCTIONS
*
*                                              TEMPLATE
*
* Filename      : net_bsp.h
* Version       : V1.72
* Programmer(s) : Eric Shufro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef     NET_BSP_MODULE
#define    NET_BSP_EXT
#else
#define    NET_BSP_EXT  extern
#endif


/*$PAGE*/
/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


#define  EMAC_CFG_MAC_ADDR_SEL     EMAC_MAC_ADDR_SEL_CFG            /* Configure MAC address set method :                       */
                                                                    /* EMAC_MAC_ADDR_SEL_EEPROM from NIC's EEPROM               */
                                                                    /* EMAC_MAC_ADDR_SEL_CFG    from application                */

/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

//void  NET_BSP_CS8900A_Reset_Delay(void);

/*
*********************************************************************************************************
*                                              MACRO'S
*
* Note(s) : (1) When NET_NIC_CFG_RD_WR_SEL configured to NET_NIC_RD_WR_SEL_MACRO, implement NIC read/write
*               functionality with macro's.
*
*               (a) The developer MUST implement the NIC read/write macro functions with the correct number
*                   & type of arguments necessary to implement the NIC's read/write functionality.
*
*               (b) The developer SHOULD appropriately name the NIC read/write macro functions by appending
*                   the number of bits that the macro functions read/write to the end of the macro function
*                   name :
*
*                           NetNIC_Rd_xx()
*                           NetNIC_Wr_xx()
*
*                   For example, 16-bit read/write macro functions should be named :
*
*                           NetNIC_Rd_16()
*                           NetNIC_Wr_16()
*
*
*               See also 'net_bsp.c  NetNIC_Rd_xx()  Note #1'
*                      & 'net_bsp.c  NetNIC_Wr_xx()  Note #1'.
*********************************************************************************************************
*/

#if (NET_NIC_CFG_RD_WR_SEL != NET_NIC_CFG_RD_WR_SEL_FNCT)
#endif


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

//void  NET_BSP_CS8900A_Reset_Delay(void);

/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  NET_NIC_CFG_INT_CTRL_EN
#error   NET_NIC_CFG_INT_CTRL_EN           not #define'd in 'net_bsp.h'
#error                               [MUST be  DEF_DISABLED]
#error                               [     ||  DEF_ENABLED ]
#elif  ((NET_NIC_CFG_INT_CTRL_EN != DEF_DISABLED) && \
        (NET_NIC_CFG_INT_CTRL_EN != DEF_ENABLED ))
#error   NET_NIC_CFG_INT_CTRL_EN     illegally #define'd in 'net_bsp.h'
#error                               [MUST be  DEF_DISABLED]
#error                               [     ||  DEF_ENABLED ]
#endif


#ifndef  EMAC_CFG_MAC_ADDR_SEL
#error   EMAC_CFG_MAC_ADDR_SEL        not #define'd in 'net_bsp.h'
#error                               [MUST be  EMAC_MAC_ADDR_SEL_CFG   ]
#error                               [     ||  EMAC_MAC_ADDR_SEL_EEPROM]
#elif  ((EMAC_CFG_MAC_ADDR_SEL != EMAC_MAC_ADDR_SEL_CFG   ) && \
        (EMAC_CFG_MAC_ADDR_SEL != EMAC_MAC_ADDR_SEL_EEPROM))
#error   EMAC_CFG_MAC_ADDR_SEL  illegally #define'd in 'net_bsp.h'
#error                               [MUST be  EMAC_MAC_ADDR_SEL_CFG   ]
#error                               [     ||  EMAC_MAC_ADDR_SEL_EEPROM]
#endif
