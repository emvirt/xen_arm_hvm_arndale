/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                              (c) Copyright 1992-2005, Micrium, Weston, FL
*                                           All Rights Reserved
*
*                                           MASTER INCLUDE FILE
*********************************************************************************************************
*/

#ifndef  INCLUDES_H
#define  INCLUDES_H

#ifndef CONFIG_XEN 
#define CONFIG_XEN
#endif

#ifndef CONFIG_XEN
//#include  <stdio.h>
//#include  <string.h>
//#include  <ctype.h>
//#include  <stdlib.h>
//#include  <stdarg.h>
//#include  <intrinsics.h>

#endif // CONFIG_XEN

#include  <ucos_ii.h>
#include  <cpu.h>

#include  <iomc9328mx21.h>
#include  <lib_def.h>
#include  <lib_mem.h>
#include  <lib_str.h>

#include  <bsp.h>

#if (uC_PROBE_OS_PLUGIN > 0)
#include  <os_probe.h>
#endif

#if (uC_PROBE_COM_MODULE > 0)
#include  <probe_com.h>
#endif

#if (PROBE_COM_METHOD_RS232 > 0)
#include  <probe_rs232.h>
#endif

#ifdef CONFIG_XEN
#include  <net/net.h>
#endif

#endif

