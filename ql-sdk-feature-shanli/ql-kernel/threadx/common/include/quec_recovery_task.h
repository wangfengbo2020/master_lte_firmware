/**  @file
  quec_recovery_task.h

@brief
This file is used to define the recovery task for different Quectel Project.

*/

/*================================================================
Copyright (c) 2019 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

					  EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN				WHO 		WHAT, WHERE, WHY
------------	   -------	   -------------------------------------------------------------------------------
26/02/2019		Jensen		   Init version
=================================================================*/



#ifndef _QUEC_RECOVERY_TASK_H
#define _QUEC_RECOVERY_TASK_H

/*> include header files here*/

#include "quec_recovery.h"
#include "quec_fota.h"
#include "quec_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_RECOVERY_SUPPORT

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
QuecOSStatus quec_recovery_task_init(void);
int quec_recovery_process(int image_index, int image_len, unsigned char *image_md5);
#if defined QUEC_FOTA_SUPPORT
int quec_update_image_info(quec_fota_pkg_info_s *image_info_new);
int quec_fota_update_flag(quec_fota_info_s *fota_flag);
#endif
int quec_update_main_image_info(unsigned char *p_image_info);


#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif




