/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ============================================================================
File        : gbl_config.h
Description : Global configuration file for testing the
              os/kal package.

Notes       : This file is only used to test the compilation and
              archiving for the os/kal package.

Copyright 2001, Intel Corporation, All rights reserved.
============================================================================ */

#if !defined(_GBL_CONFIG_H_)
#define _GBL_CONFIG_H_

#ifdef OSA_MEM_POOLS // from osa_config.h
#undef OSA_MEM_POOLS
#undef OSA_TASKS
#undef OSA_SEMAPHORES
#undef OSA_MBOX_QUEUES
#undef OSA_MESSAGING_POOL_SIZE
#undef OSA_MSG_QUEUES
#undef OSA_TIMERS

// Re-define according to system needs
/****************************************************************************************
*        Dear CUSTOMER, please PAY ATTENTION
*  The numbers below are optimized and correct for case: 
*    PLATFORM & L1 using OSA, whilst 3GPS is using direct access to NUCLEUS (without OSA).
*  The spare is very small.
*  If your 3GPS application uses the OSA you probably need to increase these numbers.
*****************************************************************************************/
  #define OSA_MEM_POOLS       		40
  #define OSA_TASKS          		27
  #define OSA_SEMAPHORES      		34
  #define OSA_MBOX_QUEUES     		10
  #define OSA_MESSAGING_POOL_SIZE   (18*1024)
  #define OSA_MSG_QUEUES      		25
  #define OSA_TIMERS                40
#endif//ifdef OSA_MEM_POOLS

//#undef  OSA_INTERRUPTS
//#define OSA_INTERRUPTS 0

#ifndef OSA_DEBUG
#define OSA_DEBUG
#endif

/* OSA 2.3.4 and above support queue names as an API option to supply a queue name to OSAMsgQCreate
 * (enabled by macro OSA_QUEUE_NAMES, default: off).
 * This presents a non backwards-compatible API change.
 * Any code using OSAMsgQCreate must be able to supply the added parameter.
 * For compatibility with previous OSA version undefine the below switch.
 * A compilation failure would occur if an old OSA version was used along with OSA_QUEUE_NAMES defined.
 * */
#define OSA_NO_PRIORITY_CONVERSION


#if defined (UPGRADE_ARBEL_PLATFORM)
#define ROM_MASK_M02	2
#define ROM_MASK_M03	3
#define ROM_MASK_M04	4
#endif	// UPGRADE_ARBEL_PLATFORM

#endif /* _GBL_CONFIG_H_ */

/*                      end of gbl_config.h
--------------------------------------------------------------------------- */

