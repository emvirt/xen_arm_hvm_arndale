/*
*********************************************************************************************************
*                                    APPLICATION SPECIFIC RTOS SETUP
*
*                             (c) Copyright 2005, Micrium, Inc., Weston, FL
*                                          All Rights Reserved
*
*                                          CONFIGURATION FILE
*
* File : app_cfg.h
* By   : Eric Shufro
*
* Xen-Arm version by OS LAB, Korea University (mrpark@os.korea.ac.kr)
*********************************************************************************************************
*/

#ifndef  APP_CFG_H
#define  APP_CFG_H

#include <lib_def.h>

#ifndef CONFIG_XEN
#define CONFIG_XEN DEF_ENABLED
#endif
/*
*********************************************************************************************************
*                                      APPLICATION CONFIGURATION
*
* Note(s) : (1) Configure the product's/application's desired product configuration values.
*********************************************************************************************************
*/
#ifdef CONFIG_XEN

#define  LIB_STR_CFG_FP_EN               DEF_DISABLED 
#define  uC_CFG_OPTIMIZE_ASM_EN          DEF_ENABLED
#define  OS_CPU_ARM_DCC_EN               DEF_DISABLED
#define  uC_PROBE_OS_PLUGIN             DEF_DISABLED                    
#define  uC_PROBE_COM_MODULE          DEF_DISABLED
#define  uC_TCPIP_MODULE                 DEF_DISABLED

#else
#define  LIB_STR_CFG_FP_EN               DEF_ENABLED                    /* DEF_ENABLED = Present, DEF_DISABLED = Not Present        */
#define  uC_CFG_OPTIMIZE_ASM_EN          DEF_ENABLED
#define  OS_CPU_ARM_DCC_EN               DEF_DISABLED
#define  uC_PROBE_OS_PLUGIN              DEF_ENABLED                    
#define  uC_PROBE_COM_MODULE             DEF_ENABLED
#define  uC_TCPIP_MODULE                 DEF_ENABLED
#endif

/*
*********************************************************************************************************
*                                            TASKS PRIORITIES
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                   2
#define  OS_PROBE_TASK_PRIO                    4
#define  OS_PROBE_TASK_ID                      4
#define  OS_TASK_TMR_PRIO                      8
#define  NET_OS_CFG_TMR_TASK_PRIO             12
#define  NET_OS_CFG_IF_RX_TASK_PRIO           14

/*
*********************************************************************************************************
*                                       STACK SIZES
*                            Size of the task stacks (# of OS_STK entries)
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE             512
#define  OS_PROBE_TASK_STK_SIZE              256
#define  NET_OS_CFG_TMR_TASK_STK_SIZE       1024
#define  NET_OS_CFG_IF_RX_TASK_STK_SIZE     1024

/*
*********************************************************************************************************
*                               uC/Probe plug-in for uC/OS-II CONFIGURATION
*********************************************************************************************************
*/

#define  OS_PROBE_TASK                         1                /* Task will be created for uC/Probe OS Plug-In             */
#define  OS_PROBE_TMR_32_BITS                  0                /* OS-View timer is a 32-bit timer                          */
#define  OS_PROBE_TIMER_SEL                    2
#define  OS_PROBE_HOOKS_EN                     0 //1

/*
*********************************************************************************************************
*                                       TRACE / DEBUG CONFIGURATION*                            
*********************************************************************************************************
*/

#define  TRACE_LEVEL_OFF                       0
#define  TRACE_LEVEL_INFO                      1
#define  TRACE_LEVEL_DEBUG                     2

#define  APP_TRACE_LEVEL                TRACE_LEVEL_DEBUG
#define  APP_TRACE                        printf

#define  APP_TRACE_INFO(x)            ((APP_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_TRACE x) : (void)0)
#define  APP_TRACE_DEBUG(x)           ((APP_TRACE_LEVEL >= TRACE_LEVEL_DEBUG) ? (void)(APP_TRACE x) : (void)0)


#endif                                                                  /* End of file                                              */


