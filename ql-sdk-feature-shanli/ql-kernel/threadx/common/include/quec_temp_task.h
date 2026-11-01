/**  @file
  quec_temp_task.h

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
10/08/2019        Fitz        Init version
=================================================================*/

#ifndef _QUEC_TEMP_TASK_H
#define _QUEC_TEMP_TASK_H

/*> include header files here*/
#include "quec_common.h"
#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef QUEC_TEMP_SUPPORT

/*========================================================================
 *  Macro Definition
 *========================================================================*/


/*========================================================================
 *  Enumeration Definition
 *========================================================================*/


/*========================================================================
 *  Type Definition
 *========================================================================*/



/******************************************************************
*	 Functions
******************************************************************/

extern void quec_temp_init(void);
extern void quec_temp_read(void);
extern int quec_temp_get(void);

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif




