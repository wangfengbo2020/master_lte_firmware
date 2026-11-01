/**  @file
  quec_fota_update_task.h

  @brief
  This file is used to define the fota update task thread for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
12/03/2019        Fitz        Init version
=================================================================*/

#ifndef _QUEC_FOTA_UPDATE_TASK_H
#define _QUEC_FOTA_UPDATE_TASK_H

/*> include header files here*/
#include "quec_fota.h"
#include "quec_common.h"
#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_FOTA_SUPPORT

/*========================================================================
 *  Macro Definition
 *========================================================================*/
#define QUEC_FOTA_UPDATE_START   (0x01)
#define QUEC_FOTA_UPDATE_PROCESS (0x02)
#define QUEC_FOTA_UPDATE_END     (0x03)
#define QUEC_FOTA_URC_DISABLE    (0x00)
#define QUEC_FOTA_URC_ENABLE     (0x01)


/*========================================================================
 *  Enumeration Definition
 *========================================================================*/


/*========================================================================
 *  Type Definition
 *========================================================================*/
extern unsigned int fota_wr_len;
extern unsigned int fota_total_len;
extern char fota_urc_enable;


/******************************************************************
*	 Functions
******************************************************************/
QuecOSStatus quec_fota_update_task_init(int enable_recovery);
QuecOSStatus quec_fota_update_urc_report(int fota_update_status, unsigned int fota_wr_len, int err_code);


#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif



