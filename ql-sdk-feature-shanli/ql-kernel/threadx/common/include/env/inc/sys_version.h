/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code (“Material? are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************
 *
 * Filename: sys_version.h
 *
 * Programmers:  NONE
 *
 * Description:  SYSTEM release information
 *
 * Cautions:     THIS FILE IS AOUTOGENERATED. MANUAL CHANGES ARE ALLOWED
 *               BUT THEY WILL BE REMOVED IN THE NEXT RELEASE.
 *
 **********************************************************************/
#ifndef SYS_VERSION_H
#define SYS_VERSION_H

//#if __ARMCC_VERSION < 400000
//# error NOT RVCT 4.1
//#endif

#define RELEASE_TYPE(T) _RELEASE_TYPE(T)
#define _RELEASE_TYPE(T) #T

#define PLAT_STREAM_NAME "CRANE_PLT"



#define HL_NAME "HL_"
#define NZ_NAME "NZ_"

#ifdef NEZHA3_1826
//CAT1 version
#define NZ3_NAME "CRANE_CAT1_CP_"
#define SYSTEM_VERSION "SDK_1.010.117" 
#endif
extern 	void setAPVersion(char *apVer);
extern char *GetSystemReleaseName(void);
#define SYSTEM_RELEASE_NAME GetSystemReleaseName()

#define SYSTEM_RELEASE_LETTER "MAIN-FS"
#define SYSTEM_MAJOR_NUMBER "00"
#define SYSTEM_MINOR_NUMBER "30"
#define SYSTEM_BUILD_NUMBER ""

/* defined SVN for IMEISV, value is decimal 0..98, 99 is reselved*/
#define SYSTEM_IMEI_SV 1

#define SYSTEM_RELEASE_CREATION_DATE "NO_DATE_NO_TIME"//xiaoke remove DATE&TIME for SDK delta patch auto diff

#define SYSTEM_RELEASE_COMMENTS "system build"

//this val is used to mark SDK release distribution version as MIXTURE_SDK_20190714
//would be replaced during SDK build period ,by <crane_ds_buildlib.bat> scipt
#define DISTRIBUTION_VERSION "SDK_20201006"

//MARK PS_MODE
#ifdef ENABLE_CAT1_LG
 #define SYSTEM_PS_MODE "LTEGSM"
#else
 #define SYSTEM_PS_MODE "LTEONLY"
#endif

//MARK TARGET OS
#ifdef PLAT_USE_THREADX
#define SYSTEM_TARGET_OS "TX"
#endif
#ifdef PLAT_USE_ALIOS
#define SYSTEM_TARGET_OS "ALIOS"
#endif

//MARK MMI SKU
#ifdef PROJ_ASR_APP_001
 #ifdef MMI_INTERFACE
  #define SYSTEM_CUST_SKU      "GENERIC"
  #define SYSTEM_SKU_REVERSION "FWKR1479_765a02d"
 #else
  #define SYSTEM_CUST_SKU      "MINIGUI"
  #ifndef CRANE_CUST_BUILD
   #define SYSTEM_SKU_REVERSION "MMILIBS_D_2431_20201030"
  #else
   #define SYSTEM_SKU_REVERSION "SDK"
  #endif
 #endif
#else
 #ifdef CRANE_MCU_DONGLE
  #define SYSTEM_CUST_SKU      "DATAMODULE"
  #define SYSTEM_SKU_REVERSION "DEFAULT"
 #else
  #define SYSTEM_CUST_SKU      "N/A"
  #define SYSTEM_SKU_REVERSION "N/A"
 #endif
#endif

#define APPEND_REVERSION     SYSTEM_CUST_SKU##"_"##SYSTEM_SKU_REVERSION

//cust release SDK version info
#define CRANE_CUST_VER_INFO "["##SYSTEM_VERSION##"]["##DISTRIBUTION_VERSION##"]["##SYSTEM_TARGET_OS##"]["##SYSTEM_PS_MODE##"]["##APPEND_REVERSION##"]"

//refer to struct SUeCpInfo at diag_types.h
#define UE_D_NA	0
#define UE_D_RATTYP_LWG		1
#define UE_D_RATTYP_LTG		2
#define UE_D_RATTYP_WG		3
#define UE_D_RATTYP_TG		4

#define UE_D_SIMTYP_SSSS	1
#define UE_D_SIMTYP_DSDS	2
#define UE_D_SIMTYP_DSDL	3
//number
#define UE_INFO_VERSION	2
#define UE_INFO_RATTYPE	UE_D_RATTYP_LWG
#define UE_INFO_SIMTYPE	UE_D_SIMTYP_SSSS
//string
#define UE_INFO_CP_VER		SYSTEM_VERSION
#define UE_INFO_MSA_VER		"N/A"
#define UE_INFO_BOARD_VER	"N/A"
//VOB stream name
#define UE_INFO_PLAT_STREAM_NAME 	PLAT_STREAM_NAME
#define UE_INFO_PS_STREAM_NAME		"N/A"
#define UE_INFO_MSA_STREAM_NAME		"N/A"

#endif /* SYS_VERSION_H */





