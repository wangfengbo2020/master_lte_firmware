/**  @file
  quec_fota_task.h

  @brief
  This file is used to define the fota task thread for different Quectel Project.

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
01/02/2019        Jensen     	 Init version
=================================================================*/


#ifndef _QUEC_FOTA_TASK_H
#define _QUEC_FOTA_TASK_H

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
#define QUEC_FOTA_TASK_DEBUG 0
/*g_quecFotaFeedQueue Keep the number the same to prevent overflow*/
#define QUEC_FOTA_RECV_QUEUE_MAX 128 //max fota msg num for recv task

/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
typedef enum
{
	QUEC_FOTA_PATH_NULL = 0,
	QUEC_FOTA_PATH_FILE,//fota by file
	QUEC_FOTA_PATH_SD,//fota by sd card
	QUEC_FOTA_PATH_MEMORY,//fota by memory
	QUEC_FOTA_PATH_HTTP,//fota by http
	QUEC_FOTA_PATH_FTP,//fota by ftp
	QUEC_FOTA_PATH_MAX,
}quec_fota_path_e;


/*========================================================================
 *  Type Definition
 *========================================================================*/
//callback to report the fota state, init at the fota task initialization
typedef QuecOSStatus (*quec_fota_callback)(QuecOSStatus fota_state, quec_fota_error_code_e fota_error_code);

typedef struct
{
	char * p_fota_data;//pointer of the fota data
	int data_len;//the length of the fota data
}quec_fota_msg_s;


/******************************************************************
*	 Functions
******************************************************************/
//                        FOTA General Step
//
//quec_fota_task_init --> quec_fota_data_put --> quec_fota_task_exit
//
//fota task init, task will be deleted when fota is over every time
//so before start to do fota, call this init handler first
QuecOSStatus quec_fota_task_init(quec_fota_callback quec_fota_callback_fn);
uint32 quec_fota_recv_queue_cnt_get(void);
//after fota task init ok, call this handler to put the fota msg down
//the buffer of msg and msg data will be freed at write task when its data is writen into flash
//if error here, upper layer call task exit without wait the quec_fota_callback_handler(err);
QuecOSStatus quec_fota_data_put(quec_fota_msg_s * p_fota_msg);

//fota task exit, call it whenever fota is failed or successfully, except init error.
//parameter fota_code is used for upper layer to send its result for URC report.
QuecOSStatus quec_fota_task_exit(void);

//read the fota flag block then to get the fota upgrade state
QuecOSStatus quec_get_fota_upgrade_result(unsigned int * p_fota_state);

//read the fota flag block then to get the fota upgrade state and the file in fota pkg detail result array
QuecOSStatus quec_get_fota_upgrade_result_detail(unsigned int *p_fota_state, unsigned int *p_file_num, unsigned int results[]);


#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif


