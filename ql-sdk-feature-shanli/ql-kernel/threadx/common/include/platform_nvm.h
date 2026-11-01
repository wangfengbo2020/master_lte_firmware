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


#ifndef _PLATFORM_NVM_H_
#define _PLATFORM_NVM_H_

#define PLATFORM_NVM_CURRENT_VERSION   "2.7"
#define PLATFORM_NVM_FILE_NAME         "platform.nvm"

#define ACI_RTOS_CFG_FILE_NAME          "aci_rtos.cfg"
#define ACI_RTOS_CFG_TEXT               "Default ACI used by APPS RTOS is ACI_GKI_ONLY"

//ICAT EXPORTED ENUM 
typedef enum
{
	/* @ENUM_DESC@ Configures Product Debug Level */
  PRODUCT_MODE = 0, /* @ENUM_VAL_DESC@ Product Mode Debug level*/
  DEBUG_NORMAL = 1, /* @ENUM_VAL_DESC@ Normal Debug level*/
  DEBUG_EXTEND = 2 /* @ENUM_VAL_DESC@ Extended Debug level*/
}ProductDebugLevel_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures UART route */
  UART_DEFAULT   = 0, /* @ENUM_VAL_DESC@ Maintain code default*/
  UART_DATA_IO   = 1, /* @ENUM_VAL_DESC@ Route UART to DATA IO */
  UART_DIAG_ACAT = 2, /* @ENUM_VAL_DESC@ Route UART to DIAG ACAT */
  UART_NULL      = 0xFF /* @ENUM_VAL_DESC@ Disable*/
}platformUART_route_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures DIAG route */
  DIAG_DEFAULT = 0, /* @ENUM_VAL_DESC@ Maintain code default*/
  USB     = 1,      /* @ENUM_VAL_DESC@ Route DIAG through USB*/
  UART    = 2       /* @ENUM_VAL_DESC@ Route DIAG through UART*/
}platformDIAG_route_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures USB detection*/
  USB_DETECT_DEFAULT = 0,	/* @ENUM_VAL_DESC@ Maintain code default*/
  USB_DETECT_ENABLE  = 1,	/* @ENUM_VAL_DESC@ Enable USB detection*/
  USB_DETECT_DISABLE = 2,	/* @ENUM_VAL_DESC@ Disable USB detection*/
  USB_ALWAYS_CONNECT = 3,	/* @ENUM_VAL_DESC@ Always connect to USB*/
  USB_ALWAYS_DISCONNECT = 4 /* @ENUM_VAL_DESC@ Never connect to USB*/
}platformUSBdetection_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures HeartBeat mode*/
  HB_DISABLE= 0,	/* @ENUM_VAL_DESC@ Disable heart beat*/
  TO_UART   = 1,    /* @ENUM_VAL_DESC@ Send heart beat to UART*/
  TO_ACAT   = 2,    /* @ENUM_VAL_DESC@ Send heart beat to ACAT*/
  ANOTHER   = 3     /* @ENUM_VAL_DESC@ Reserved*/
}platformHeartBeat_ts;


//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures RTC Client*/
  RTC_CLIENT_DEFAULT = 0x0, /* @ENUM_VAL_DESC@ Maintain code default*/
  RTC_CLIENT_ENABLE  = 1,   /* @ENUM_VAL_DESC@ Enable RTC client*/
  RTC_CLIENT_DISABLE = 2    /* @ENUM_VAL_DESC@ Disable RTC client*/
}platformRtcClient_ts;

//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures Relaiable Data load source*/
  RD_DEFAULT = 0x0,                         /* @ENUM_VAL_DESC@ Maintain code default*/
  RD_LOAD_CALIB_FILES_FROM_FLASH = 1,       /* @ENUM_VAL_DESC@ Load Callibration files from flash*/
  RD_DONT_LOAD_CALIB_FILES_FROM_FALSH = 2   /* @ENUM_VAL_DESC@ Don't load Callibration files from flash*/
}platformRelaibeData_ts;



//=PM========================================================
//Refer also SYSTEM  "enum{ DISABLE,CORE_ONLY,CORE_PX,CORE_PX_DROWSY,FULL}xscalePowerManagement_ts"
//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configure Comm-Apps sync*/
  PM_COMM_APPS_SYNC_DISABLED  = 0,  /* @ENUM_VAL_DESC@ Disable Comm-Apps sync*/
  PM_COMM_APPS_SYNC_ENABLED  = 1    /* @ENUM_VAL_DESC@ Enable Comm-Apps sync*/
}nvmPM_CommAppsSync_ts;



//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configure Power Manager operation level*/
  PM_DEFAULT      = 0,  /* @ENUM_VAL_DESC@ Maintain code default*/
  PM_FULL_ENABLE  = 1,  /* @ENUM_VAL_DESC@ Enable Power Manager full functionality*/
  PM_DISABLE      = 2,  /* @ENUM_VAL_DESC@ Disable Power Manager */
  PM_LEVEL_C1     = 3,  /* @ENUM_VAL_DESC@ Enable Power Manager C1 */
  PM_LEVEL_D2     = 4   /* @ENUM_VAL_DESC@ Enable Power Manager D2 */
}nvmPM_level_ts;

//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Set product point*/
  PP_DEFAULT = 0,  /* @ENUM_VAL_DESC@ Maintain code default*/
  PP_1    = 1,     /* @ENUM_VAL_DESC@ Set product point to 1*/
  PP_2    = 2,     /* @ENUM_VAL_DESC@ Set product point to 2*/
  PP_3    = 3,     /* @ENUM_VAL_DESC@ Set product point to 3*/
  PP_4    = 4      /* @ENUM_VAL_DESC@ Set product point to 4*/
}nvmPM_ProductPoint_ts;

//ICAT EXPORTED ENUM
typedef enum
{
	PNVM_DEFAULT=0,
	PNVM_ENABLE,
	PNVM_DISABLE
}nvm_EN_DIS_DEF_ts;


//ICAT EXPORTED STRUCT
typedef struct
{
	/* @STRUCT_DESC@ Configures Power Manager*/
  nvmPM_CommAppsSync_ts PM_AppsCommSyncEnabled; /* @ITEM_DESC@ Configure Comm-Apps sync, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
  nvmPM_ProductPoint_ts PM_ProductPoint;        /* @ITEM_DESC@ Set product point, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
  nvmPM_level_ts        PM_dbgLevel;            /* @ITEM_DESC@ Configure Power Manager operation level, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
  nvm_EN_DIS_DEF_ts		PM_newDDRHandshakeEnabled;
}platformPowerMngr_ts;
//=PM========================================================


//=USIM========================================================
//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures USIM error handling*/
  USIM_ERR_SILENT   = 0,    /* @ENUM_VAL_DESC@ Silent error handling*/
  USIM_ERR_ASSERT   = 1,    /* @ENUM_VAL_DESC@ Assert on error*/
  USIM_ERR_RECOVERY = 2     /* @ENUM_VAL_DESC@ error handling recovery*/
}nvmUsimErrorHandler_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	/* @STRUCT_DESC@ Configures USIM driver settings*/
  ProductDebugLevel_ts      DebugLevel;			/* @ITEM_DESC@ Configures USIM Debug Level, @ITEM_MODE@ Debug, @ITEM_UNIT@  see enum*/
  UINT8                     TxDmaDisable;       /* @ITEM_DESC@ Configure Tx Dma Disable, @ITEM_MODE@ Debug, @ITEM_UNIT@ 0-0xFF*/
  UINT8                     DetectGpioPinNo;    /* @ITEM_DESC@ Set USIM detection GPIO, @ITEM_MODE@ ReadWrite, @ITEM_UNIT@ Entries 1-0xFF according to available GPIOs, 0 to diasble detection*/ //disable=0, Detect_Pin=0xFF, others are GPIO/CGPIO pins
  nvmUsimErrorHandler_ts    ErrorHandler;       /* @ITEM_DESC@ Configures USIM error handling, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
}platformUsim_ts;
//=USIM========================================================


//=APPS_COMM_MODE================================================
//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures AppCommMode*/
  APPCOMM_DEFAULT       = 0,            /* @ENUM_VAL_DESC@ Maintain code default*/
  APPCOMM_COMM_IN_RESET = 1,            /* @ENUM_VAL_DESC@ Set Comm in reset*/
  APPCOMM_LONG_TYPE     = 0x0FFFFFFF    /* @ENUM_VAL_DESC@ force AppsComm enum long*/
}platformAppsCommMode_ts;
//=APPS_COMM_MODE================================================


//=OSA================================================
//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures OSA Error behavior*/
  OSA_ERROR_DEFAULT    = 0,             /* @ENUM_VAL_DESC@ Maintain code default*/
  OSA_ERROR_ASSERT     = 1,             /* @ENUM_VAL_DESC@ Assert on OSA errors*/
  OSA_ERROR_IGNORE     = 2,             /* @ENUM_VAL_DESC@ Ignore OSA errors*/
  OSA_ERROR_RESTORE_OK = 3,             /* @ENUM_VAL_DESC@ OSA error restore*/
  OSA_ERROR_LONG_TYPE  = 0x0FFFFFFF     /* @ENUM_VAL_DESC@ force OSA error enum long*/
}platformOsaErrBehavior_ts;
//=OSA================================================

//=I2C ================================================
//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures I2C FAST-SLOW mode*/
  NVM_I2C_CLK_DEFAULT   	= 0,             /* @ENUM_VAL_DESC@ Maintain code default*/
  NVM_I2C_SLOW_ClK_MODE 	= 0x00007fff,    /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/
  NVM_I2C_FAST_CLK_MODE 	= 0x00008000,    /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/
  NVM_I2C_CLK_LONG_TYPE  	= 0x0FFFFFFF     /* @ENUM_VAL_DESC@ force I2C error enum long*/
}platfromI2cModeCfg_ts;

//ICAT EXPORTED ENUM
typedef enum
{
	/* @ENUM_DESC@ Configures I2C repeat start configuration */
  NVM_I2C_REPEAT_DEFAULT	= 0,             /* @ENUM_VAL_DESC@ Maintain code default*/
  NVM_I2C_NOT_REPEAT_START  = 1,             /* @ENUM_VAL_DESC@ Configure for slow mode align to I2c.h*/
  NVM_I2C_REPEAT_START  	= 2,             /* @ENUM_VAL_DESC@ Configure for fast mode align to I2c.h*/
  NVM_I2C_REPEAT_LONG_TYPE  = 0x0FFFFFFF     /* @ENUM_VAL_DESC@ force I2C error enum long*/
}platfromI2cRepeatCfg_ts;

//ICAT EXPORTED STRUCT
typedef struct
{
	/* @STRUCT_DESC@ I2C Configures */
  platfromI2cModeCfg_ts    I2cClkMode;/* @ITEM_DESC@ Configures I2C CLK mode FAST/SLOW,@ITEM_MODE@ Configuration , @ITEM_UNIT@  see enum*/
  platfromI2cRepeatCfg_ts  I2cRptStrt;/* @ITEM_DESC@ Configures I2C REPEAT_START mode yes/no, @ITEM_MODE@ Configuration, @ITEM_UNIT@  see enum*/
}platfromI2cCfg_ts;

//=I2C ================================================



//====SUMMARY=====================================================
//ICAT EXPORTED STRUCT
typedef struct
{
	/* @STRUCT_DESC@ Platfrom configuration */
	/* @STRUCT_NVM_FILE_NAME@ platfrom.nvm */
   ProductDebugLevel_ts    ProductDebugLevel;	/* @ITEM_DESC@ Configures Product Debug Level, @ITEM_MODE@ Debug, @ITEM_UNIT@  see enum*/

   UINT32                  DelayMSEC_Startup;   /* @ITEM_DESC@ Startup Delay, @ITEM_MODE@ Debug, @ITEM_UNIT@ milisec*/
   UINT32                  DelayMSEC_MSL;		/* @ITEM_DESC@ MSL Delay, @ITEM_MODE@ Debug, @ITEM_UNIT@ milisec*/
   UINT32                  DelayMSEC_Audio;     /* @ITEM_DESC@ Audio Delay, @ITEM_MODE@ Debug, @ITEM_UNIT@ milisec*/
   UINT32                  DelayMSEC_Power;     /* @ITEM_DESC@ Power Delay, @ITEM_MODE@ Debug, @ITEM_UNIT@ milisec*/
   UINT32                  DelayMSEC_L1start;   /* @ITEM_DESC@ L1 start Delay, @ITEM_MODE@ Debug, @ITEM_UNIT@ milisec*/
   UINT32                  DelayMSEC_reserv1;   /* @ITEM_DESC@ Reserved, @ITEM_MODE@ ReadOnly, @ITEM_UNIT@ Not Relevant*/

   platformUART_route_ts   UART_route;          /* @ITEM_DESC@ Configures UART route, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platformDIAG_route_ts   DIAG_route;          /* @ITEM_DESC@ Configures DIAG route, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platformUSBdetection_ts USBdetection;        /* @ITEM_DESC@ Configures USB detection, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platformHeartBeat_ts    HeartBeat;           /* @ITEM_DESC@ Configures HeartBeat modes, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platformPowerMngr_ts    PowerManagement;     /* @ITEM_DESC@ Configures Power Manager, @ITEM_MODE@ Debug, @ITEM_UNIT@ see structure*/
   platformRtcClient_ts    RTC_Client;          /* @ITEM_DESC@ Configures RTC Client, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platformRelaibeData_ts  RD_LoadCalibFiles;   /* @ITEM_DESC@ Configures Relaiable Data load source, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/


   platformUsim_ts         USIM;                /* @ITEM_DESC@ Configures USIM driver settings, @ITEM_MODE@ Debug, @ITEM_UNIT@ see structure*/
   platformAppsCommMode_ts AppCommMode;         /* @ITEM_DESC@ Configures AppCommMode, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/

   platformOsaErrBehavior_ts    OsaErrBehavior; /* @ITEM_DESC@ Configures OSA Error behavior, @ITEM_MODE@ Debug, @ITEM_UNIT@ see enum*/
   platfromI2cCfg_ts     		NvmCfgI2C; 		/* @ITEM_DESC@ Configures I2c CLK and REPEAT_START, @ITEM_MODE@ Configuration, @ITEM_UNIT@ see enum*/
   /* the reserved[X] must be update for backward
	* compatible if new fields are added to PlatformNvm_ts.
	* for example if you add UNIT32 you need to reduce X = X-4*/
   UINT8                   		reserved[44];   /* @ITEM_DESC@ the amount of the reserved must be reduced if fields are added, @ITEM_MODE@ debugging, @ITEM_UNIT@ none*/

}PlatformNvm_ts;


extern PlatformNvm_ts* p_PlatformNvm;

// Init brings data from  given file  into specified buffer or
//                  from default-file into default buffer
//Resulting data should be referenced by global pointer PlatformNvm_ts* p_PlatformNvm
void PlatformNvm_Init(char* filePath, void* nvmBuf);
void PlatformNvm_Print(void);
void PlatformNvm_CreateAciCfgFile(char* fullPath);
BOOL PlatformNvm_AppsIsRtosLike(void);

#endif //_PLATFORM_NVM_H_

