/**  @file
  quec_recovery.h

@brief
This file is used to define the recovery of image for different Quectel Project.

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



#ifndef _QUEC_RECOVERY_H
#define _QUEC_RECOVERY_H

/*> include header files here*/
#include "Typedef.h"
#include "Errors.h"
//#include "download.h"
#include "FlashPartition.h"
#include "quec_cust_feature.h"
#include "quec_fota.h"

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
typedef enum
{
	QUEC_RECOVERY_GENERAL_ERROR = -100,

	QUEC_RECOVERY_IMAGE_TYPE_ERROR,//RECOVERY包类型错误，应为完整包或者差分包
	QUEC_RECOVERY_DIFF_IMAGE_NOTSUPPORT,//RECOVERY差分包格式不支持
		
	QUEC_RECOVERY_CRC32_CALCULATE_ERROR,//CRC32计算错误
	QUEC_RECOVERY_CRC32_CHECK_ERROR,//CRC32校验错误
	QUEC_RECOVERY_MD5_CALCULATE_ERROR,//MD5计算错误
	QUEC_RECOVERY_MD5_CHECK_ERROR,//MD5校验错误
	QUEC_RECOVERY_HEADER_CHECK_ERROR,//RECOVERY常量字节头检验错误

	QUEC_RECOVERY_FLAG_READ_ERROR,//升级/备份标志区读取错误
	QUEC_RECOVERY_FLAG_WRITE_ERROR,//升级/备份标志区回写错误
	QUEC_RECOVERY_FLAG_ERASE_ERROR,//升级/备份标志区擦除错误
	QUEC_RECOVERY_FLAG_INDEX_ERROR,//升级/备份标志包序号错误
	QUEC_RECOVERY_FLAG_INDEX_MISMATCH,//升级/备份标志程序包序号不匹配
	QUEC_RECOVERY_FLAG_INDEX_NOTSUPPORT,//升级/备份标志程序包序号不支持
	
	QUEC_RECOVERY_SRC_IMAGE_LEN_ERROR,//升级/备份程序包长度错误
	QUEC_RECOVERY_SRC_IMAGE_NOT_FULL_ERROR,//升级/备份程序包错误：不是完整包
	QUEC_RECOVERY_SRC_IMAGE_UNCOMPRESSED_ERROR,//升级/备份程序包错误：未压缩
	QUEC_RECOVERY_SRC_IMAGE_DECOMPRESS_ERROR,//升级/备份程序包解压错误
	QUEC_RECOVERY_SRC_IMAGE_DECOMPRESS_LEN_ERROR,//升级/备份程序包解压后长度错误
	QUEC_RECOVERY_SRC_IMAGE_READ_ERROR,//升级/备份程序包读取错误
	QUEC_RECOVERY_SRC_IMAGE_WRITE_ERROR,//升级/备份程序包写错误
	QUEC_RECOVERY_SRC_IMAGE_ERASE_ERROR,//升级/备份程序包擦除错误
	QUEC_RECOVERY_SRC_IMAGE_CHECK_ERROR,//升级/备份程序包校验错误
	
	QUEC_RECOVERY_DST_IMAGE_READ_ERROR,//用于加载使用的程序包读取错误（包括升级前后）
	QUEC_RECOVERY_DST_IMAGE_WRITE_ERROR,//用于加载使用的程序包更新错误
	QUEC_RECOVERY_DST_IMAGE_ERASE_ERROR,//用于加载使用的程序包擦除错误
	QUEC_RECOVERY_DST_IMAGE_CHECK_ERROR,//用于加载使用的程序包校验错误
	
	QUEC_RECOVERY_NOERROR = 0,
	QUEC_RECOVERY_GENERAL_SUCESS = QUEC_RECOVERY_NOERROR,

	QUEC_RECOVERY_WAIT_TO_UPDATE = 90,//校验失败，需要更新
	QUEC_RECOVERY_UPDATE_SUCCESS = 100,//备份程序包恢复成功
}quec_recovery_internal_result;

typedef enum
{
	QUEC_RECOVERY_STATE_OK = 0,
	QUEC_RECOVERY_STATE_NEED_UPDATE_FOTA,
	QUEC_RECOVERY_STATE_NEED_UPDATE_RECOVERY,
	QUEC_RECOVERY_STATE_MAX,
}quec_recovery_state_option;


/*========================================================================
 *  Type Definition
 *========================================================================*/


/******************************************************************
*	 Functions
******************************************************************/


#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif



