/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/


#ifndef _PL_AM_NVM_H_
#define _PL_AM_NVM_H_

#define     PL_AM_NVM_GENERATE_ASSERT_ON_COM_ERR_DEF_VAL    TRUE
#define     PL_AM_NVM_ENABLE_EXT_TRACING_DEF_VAL            FALSE
#define		WB_BANDS 			5

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT32 aplpQDepth;
  UINT32 aplpStackSize;
  UINT32 aplpTaskPriority;
  UINT32 aplpHighQDepth;
  UINT32 aplpHighStackSize;
  UINT32 aplpHighTaskPriority;
}aplpConfigParams_ts;

//ICAT EXPORTED ENUM
typedef enum
{
  DISABLE_L1C_FEATURE = 0,
  ENABLE_L1C_FEATURE  = 1
}l1FeatureEnable_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  l1FeatureEnable_ts enableSleep;
  l1FeatureEnable_ts SleepAlike;
  l1FeatureEnable_ts enableExtendedTracing;
  l1FeatureEnable_ts periodicDetected;
}featuresParams_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  l1FeatureEnable_ts RESERVED1;
  l1FeatureEnable_ts RESERVED2;
  l1FeatureEnable_ts AnritsuSetup;
  l1FeatureEnable_ts RESERVED4;
  l1FeatureEnable_ts frameToDiag;
  l1FeatureEnable_ts RESERVED6;
  l1FeatureEnable_ts RESERVED7;
  l1FeatureEnable_ts RESERVED8;
}featuresUnderDevelopment_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  long dpchMaxInitPower[WB_BANDS];
  long dpchMinInitPower;
  long dpchMaxPowerLevel[WB_BANDS];
  long prachMaxInitPower[WB_BANDS];
  long prachMinInitPower;
  long prachMaxPowerLevel[WB_BANDS];
  UINT32 numFramesToWakePccpchSkip;
}MS_configParams_ts;
//ICAT EXPORTED STRUCT
typedef struct
{
  UINT16   Qin;
  UINT16   Qout;
}dataPkg_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
  UINT8  maxPccpchShifts;
  UINT8  maxTmUpdtB4DummyTracker;
  UINT8  tccInterrupt0Offset;
  UINT8  tccInterrupt1Offset;
}tccTmPkg_ts;

//ICAT EXPORTED ENUM
typedef enum
{
	NORMAL_MODE  =	0, //handle COM_WARNING as warnings, COM_ERROR and DSP_EXCEPTION as errors
	ALL_ERRORS   =	1, //handle all as errors
	ALL_WARNINGS =	2, //handle all as warnings
	LISTEN_TO_DSP=	3,  //handle according to DSP message (bit indicating treatment way)
	TRACE_N_CONTINUE = 4  //send trace to ICAT and do nothing
}L1ErrHandleMode_e;

//ICAT EXPORTED STRUCT
typedef struct
{
	L1ErrHandleMode_e plpErrHandleMode;
	L1ErrHandleMode_e aplpErrHandleMode;
	l1FeatureEnable_ts		enablePlwErrIndToPs;
    UINT8              pad;
}L1_ErrorHandlerConfig_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
   aplpConfigParams_ts          aplpConfigParams;
   featuresParams_ts            featuresParams;
   MS_configParams_ts           MS_configParams;
   dataPkg_ts                   dataPackageParams;
   tccTmPkg_ts                  tccTmPkgParams;
   featuresUnderDevelopment_ts  developmentSwitch;
   L1_ErrorHandlerConfig_ts     l1ErrHandler;
}l1cNvm_ts;


// Function Prototypes
BOOL plAmNvmCreate(void);
BOOL plAmNvmRead(aplpConfigParams_ts* aplpConfig);
void plAmGetDataNvmParams(UINT16* DATA_Qin,UINT16* DATA_Qout);
UINT16 plAmGetMaxPccpchShifts(void);
UINT16 plAmGetNumFramesToWakePccpchSkip(void);
void plAmNvmDisableBchSkip(void);
l1FeatureEnable_ts plAmGetPeriodicDetectedSwitch(void);
UINT8 plAmGetDevSwitch_2(void);
Bool plwAmIsExtendedTracingEnabled(void);

UINT8 plAmGetDevSwitch_5(void);

UINT16 plAmGetInt0Offset(void);
UINT16 plAmGetInt1Offset(void);


#endif
