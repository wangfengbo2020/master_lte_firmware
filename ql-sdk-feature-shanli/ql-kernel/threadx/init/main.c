/*---------------------------------------------------------------
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

/***************************************************************************
*               MODULE IMPLEMENTATION FILE
****************************************************************************
* Title: Initialing code
*
* Filename: main.c
*
* Target, platform: Tavor
*
* Authors: Alexander Rivman
*
* Description:
* 	Application_Initialize
*
*
* Last Updated:
*
* Notes:
******************************************************************************/
/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/

#include "global_types.h"
#include <stdlib.h>
#include "asserts.h"
#include "hal_cfg.h"
#include "nucleus.h"
#include "bsp_config.h"
#include "arbel.h"
#include "arm946e_s.h"
#include "commccu.h"
#include "mccu.h"
#include "apbccu.h"
#include "prm.h"
#include "csw_mem.h"
#include "i2c_eeprom.h"
#include "bsp.h"
#include "dsp_boot.h"
#include "IMEI.h"
#include "mep.h"
#include "simPin.h"
#include "utilities.h"
#include "loadTable.h"
#include "log.h"
#include "FreqChange.h"
#include "sdio.h"
#include "cgpio.h"
#include "EE_silentReset.h"
#ifdef BT_SUPPORT
//#include "bt_api.h"
#endif
#include "nvm_header.h"
#include "DVFM_ext.h"
#include "WS_HwAcs.h"
#ifdef OPENCPU_SUPPORT
#include "FuncTable.h"
#endif
#ifdef _DIAG_ENABLED_
#include "diag.h"
#include "diag_nvm.h"
#include "mvUsbStorage.h"
#include "diag_mem.h"
#include "ICAT_config.h"
#endif

#include "platform_nvm.h"
#include "crossPlatformSW.h"
#include "dma.h"
#include "timer.h"
#if !defined(TTC_BSP_ARM946_CP15)
#include "cpmu.h"
#include "tick_manager.h"
#include "NUtick.h"
#endif
#include "intc.h"
#include "bsp_config.h"
#include "pm_ext_debug.h"
#include "cpu_mips_test.h"
#include "bspUartManager.h"
#include "rtc.h"

#if !defined(TTC_BSP_ARM946_CP15)
#include "acipc.h"
#include "acipc_data.h"
#endif

#include "osa.h"

#include "watchdog.h"
#if defined(IPC_ENABLED)
#include "IPCComm.h"
#include "WS_IPCComm.h"
#endif

//#include "ssp.h"

#include "EEHandler.h"

#if defined DATA_COLLECTOR_IMPL
#include "DataCollector.h"
#endif
#include "iml_nvm.h"

//Hongji 201011
#include "usb.h"

#include "I2C.h"
#include "miccoConfig.h"

#ifndef _PMC_ENABLED_
#define _PMC_ENABLED_
#endif

#ifdef _PMC_ENABLED_
#include "PMChip.h"
#endif

#include "bspLog.h"

#if defined(RELIABLE_DATA)
#include "ReliableData.h"
#endif

#include "COMCfg.h"

#if ((defined(CRANE_MCU_DONGLE)) && (!defined(REMOVE_FOTA)))
#include "download.h"
#endif

#ifdef _USIM_ENABLED_
#include "usim.h"
#endif
#if !defined(TTC_BSP_ARM946_CP15)
#include "aam.h"
#endif

#if defined(__arm)
	#include <locale.h>
#endif
#include <ctype.h>

#include "platform.h"
#include "usb_init.h"
#include "crane_ds_mpu.h"
#include "diag_comm_SD.h"
#include "usb_descriptor.h"
#include "main.h"
#if defined(LZOP_SUPPORT)
#include "lzop.h"
#endif
#include "ptable.h"
#include "utils.h"
#include "EE_silentReset.h"
#include "sys_version.h"

#include "asr_property.h"
#include "utilities.h"
#ifdef AGPS_ENABLE
#include "agps.h"
#endif
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
#include "quec_production_cfg.h"
#endif
extern BOOL PMIC_IS_PM803(void);
extern BOOL PMIC_IS_PM803L(void);
#ifdef QUECTEL_PROJECT_CUST
int quec_minisys_hal_init(void);
#include "quec_board_common.h"
#endif
#include "MRD.h"

#if QUEC_DUAL_SIM_SUPPORT
#include "connect_management.h"
#include "ims_api_psram.h"
#endif

/*===========================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

===========================================================================*/

/* Init Task reference. */
OSATaskRef initTaskRef;

/* ACIPC psd version. */
UINT32 ACIPC_PSD_VERSION = 0;

/* Need to dump flag. */
UINT32 needToDump = 0;

/* Dump vol string. */
char *DUMP_VOL = "D:";

/* Init Task stack. */
static void* InitTaskStack = NULL;

/* Vcxo Stable Time. */
UINT8 gVcxoStableTime = 0xFF;

/* Pll Stable Time. */
UINT8 gPllStableTime = 0xFF;

/* Clk Gen Time. */
UINT8 gClkGenTime = 0xFF;

/* Dual Carrier Flag. */
UINT8 gDualCarrierFlag = 0;

/* Powerup Save Time Flag. */
UINT8 gPowerupSaveTimeFlag = 0;

/* 1: move CI init to higher priority task than DmNvPTasK(80) */
UINT8 gPowerupPsInitFastFlag = 0; 

/* Dual Ant Flag. */
UINT8 gDualAntFlag = 0;

/* Apt Flag. */
#if defined (EDEN_1928) || defined (NEZHA3_1826)
APT_TYPE gAptFlag = APT_ENABLE;
#else
APT_TYPE gAptFlag = APT_DISABLE;
#endif

/* PM Enable Flag and VCXO Enable Flag. */
#if defined (ENABLE_SLT_FEATURE)
PM_TYPE  gPMEnableFlag = _PM_DISABLE;
VCXO_TYPE gVCXOEnableFlag = VCXO_SD_DISABLE;
#else
#if defined (CRANEL_8MRAM) || defined (CRANEL_4MRAM)	//for craneL
PM_TYPE  gPMEnableFlag = _PM_ENABLE;
#else
PM_TYPE  gPMEnableFlag = _PM_ENABLE;
#endif
VCXO_TYPE gVCXOEnableFlag = VCXO_SD_ENABLE;
#endif

#ifdef YMODEM_EEH_DUMP
/* Ymodem Dump Cfg. */
#ifdef QUECTEL_PROJECT_CUST
Ymodem_Dump_type  YmodemDumpCfg = {YMODEM_DISABLE};
#else
Ymodem_Dump_type  YmodemDumpCfg = {YMODEM_ENABLE};
#endif
/* Ymodem Dump flag. */
static volatile int ymodemdumpflag = 0;
#endif

/* HW DFC Enable Flag. */
HWDFC_TYPE	gHWDFCEnableFlag = _HWDFC_DISABEL;

/* SD Log Enable Flag. */
SDLOG_TYPE SDLogEnableFlag = SD_LOG_DISABLE;

/* HW DFC Test Flag. */
HWDFC_TEST_TYPE	gHWDFCTestFlag = _HWDFC_TEST_DISABEL;

/* L1 Acat Log Enable Flag. */
L1AcatLog_TYPE gL1AcatLogEnableFlag = _L1_ACAT_LOG_DISABLE;

/* Sulog Default Cfg Data. */
SulogCfgDataS SulogCfgDataDefault =
{
	SULOG_ENABLE_HW_SW,
	//{1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 0, 1, 1, 1, 1},
	{0x4A656515, 0x55},
	//{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	{0x45555515, 0x55},
	0
};

/* Sulog Default Cfg Data. */
SULOG_ST SulogSetDefault;

/* Platform configuration Data. */
PlatformCfgDataS PlatformCfg;

/* Default Log configuration */
Log_ConfigS log_config =
{
    ACAT_LOG_ENABLE,
    ACAT_MSG_ENABLE,
    RTI_DUMP_ENABLE
};

/* Backup Log configuration */
Log_ConfigS log_config_bak;

/* Usb driver configuration */
#if QUECTEL_PROJECT_CUST
Usb_DriverS usbDrvCfg = 
{
#ifndef MBIM_FUNCTION
	USB_GENERIC_MOD_ECM_DRIVER, 
	MASS_STORAGE_DISABLE, 
	USB_AUTO_INSTALL_DISABLE, 
	USB_OS_DETECT_DISABLE
#else // MBIM_FUNCTION
	USB_MBIM_GENERIC_DRIVER,
	MASS_STORAGE_DISABLE,
	USB_AUTO_INSTALL_DISABLE,
	USB_OS_DETECT_DISABLE
#endif // MBIM_FUNCTION
};
#else
Usb_DriverS usbDrvCfg = {USB_GENERIC_MOD_DRIVER, MASS_STORAGE_DISABLE, USB_AUTO_INSTALL_DISABLE, USB_OS_DETECT_DISABLE};
#endif


/* LTE configuration*/
LTE_CONFIG_S LteCfg =
{
    CFG_PP_AUTO,
    MIPS_8_5,
    MIPS_3_0,
    LTE_DMA_208M,
    VOLTAGE_DEFAULT,
    VOLTAGE_DEFAULT
};

/* Systwm debug configuration */
SYSDBGCfgDataS SysDbgCfg =
{
    _CPU_USAGE_DUMP_ENABLE,
    5000
};

/* IML configuration data */
IMLCfgDataS gIMLCfgdata =
{
    IMLConfig_2SU_ENABLE,
    0,
    {NULL}
};

#ifdef SS_IPC_SUPPORT
DIPOPTION_TYPE gDipEnable = DIP_DISABLE;
#endif

#if (!defined(REMOVE_FOTA))
/* Mini system enable flag. */
int mini_sys_enable = MINI_SYS_STATUS_NONE;
#endif

/*===========================================================================

            EXTERN DEFINITIONS AND DECLARATIONS FOR MODULE

===========================================================================*/

/* GL Feature Flag */
extern BOOL GLFeatureFlag;

/* usb User Mode */
extern BOOL usbUserMode;

/* RTI Config. */
extern RTICfg_t rtiConfig;

/* Uart Config. */
extern uartCfgDataS uartCfg;

/* Default diag configuration */
extern diagCfgDataS diagCfg;

/* Activate Code Flag. */
extern UINT32 activateCodeFlag;

/* Assert Random Flag. */
extern UINT32 AssertRandomFlag;

/* Delete InitTask Timer refernce. */
extern OSATimerRef TimerDeleteInitTask;

/* ee Configuration. */
extern EE_Configuration_t eeConfiguration;


extern void flush_cfun4_rsp_init(void);

 /*===========================================================================

                           INTERNAL FUNCTION DEFINITIONS

 ===========================================================================*/

 /*************************************************************************/
 /*                                                                       */
 /* FUNCTION                                                              */
 /*                                                                       */
 /*      Application_Initialize                                           */
 /*                                                                       */
 /* DESCRIPTION                                                           */
 /*                                                                       */
 /*      The function is called by NUCLEUS (INC_Initialize) in context    */
 /*      of the init process.  Must be supplied for every application     */
 /*      using NUCLEUS.                                                   */
 /*                                                                       */
 /* CALLED BY                                                             */
 /*                                                                       */
 /*      Application                                                      */
 /*                                                                       */
 /* CALLS                                                                 */
 /*                                                                       */
 /*      Application                         The application function     */
 /*                                                                       */
 /* INPUTS                                                                */
 /*                                                                       */
 /*      None                                N/A                          */
 /*                                                                       */
 /* OUTPUTS                                                               */
 /*                                                                       */
 /*      None                                N/A                          */
 /*                                                                       */
 /*************************************************************************/

VOID Application_Initialize(VOID)
{
    OS_STATUS      status;

    initState = BSP_INIT_CINIT2_PASSED;
    uart_printf("Application Initialize\r\n");

    status = OSAInitialize();
    ASSERT(status == OS_SUCCESS);

	platform_type_init();

	DynamicMemoryInit(); /*cinit1*/
	
#ifdef CRANE_MCU_DONGLE
    extern void save_bx_Itcm_to_heap(void);
	save_bx_Itcm_to_heap();
#endif

    commImageTableInit();

	if(needToDump == 0)
	{
#if QUECTEL_PROJECT_CUST
		DumpLogPrintf_Extend("silentreset, don't need to dump\r\n");
#else
		uart_printf("silentreset, don't need to dump\r\n");
#endif		
	}
	else
	{
#if	QUECTEL_PROJECT_CUST
				    /* Printf CIU register information. */
	    	DumpLogPrintf_Extend("======= CIU register =======");
	    	DumpLogPrintf_Extend("[ PC ]0x%x: 0x%x", (0xD4282C00 + 0x138), *(volatile UINT32 *)(0xD4282C00 + 0x138));
	    	DumpLogPrintf_Extend("[CPSR]0x%x: 0x%x", (0xD4282C00 + 0x13C), *(volatile UINT32 *)(0xD4282C00 + 0x13C));
	    	DumpLogPrintf_Extend("[SPSR]0x%x: 0x%x", (0xD4282C00 + 0x140), *(volatile UINT32 *)(0xD4282C00 + 0x140));
			DumpLogPrintf_Extend("need to dump\r\n");		
#else
		uart_printf("need to dump\r\n");
#endif
#ifdef QUEC_RF_CALI_TEMP_MODIFY	
		DumpLogPrintf_Extend("++++++++++++++++++++++++++++++++++++++++++++++++++++print last rti log\r\n");		
		rti_info_dump_all();
#endif
	}

	DbgInitFifo();

	if(DbgGetType()==1)
	{
		DbgInitUart(1);
	}

    assert_cnt_flag_init();

    /*Phase 1 (not OS based) initializations*/
    Phase1Inits();

    initState = BSP_INIT_PHASE1_PASSED;
#if defined(DM_SUPPORT_FRAMEWORK) || defined(PROJ_MINIPHONE)
#ifndef MIN_SYS
    extern int __attribute__((used)) ui_init_phase1(void);
    if(!IsMiniSystem())
    {
	    ui_init_phase1();
	}
#endif
#endif
#if QUEC_DEBUG_LOG_SWITCH
		extern int cp_log_flag;
		cp_log_flag = 0;
#endif
    /* Allocate dynamic memory */
    InitTaskStack = malloc( INIT_STACK_SIZE );

    /* Run the system initialization task */
    memset(InitTaskStack, 0xA5, INIT_STACK_SIZE);
    status = OSATaskCreate(&initTaskRef, InitTaskStack, INIT_STACK_SIZE, INIT_TASK_PRIORITY, "InitTask", InitTask, NULL);
    ASSERT(status == OS_SUCCESS);
#ifdef CTCC_DM_SMS_ENABLE
	telecom_SMS_init();
#endif
#ifdef CTCC_DM_ENABLE
	telecom_init();
#endif
}/* End of <Application_Initialize> */


/******************************************************************************
 * Function     : DeleteInitPhase2Task
 *******************************************************************************
 *
 * Description  : free the init task stack and delete the task. (timer call back function)
 *
 ******************************************************************************/
 void DeleteInitPhase2Task(void)
{
/* This function is called (by mistake) from GPLC::L1BgInitialise()
 * Let's keep the call there and filler-function here.
 * For real delete let's use the DeleteInitPhase2TaskByTimer()
 */
}

/******************************************************************************
* Function     : DeleteInitPhase2TaskByTimer
*******************************************************************************
*
* Description  :
*
******************************************************************************/
void DeleteInitPhase2TaskByTimer(UINT32 id)
{
    OSA_STATUS status;

    if(initTaskRef)
    {
        status = OSATaskDelete(initTaskRef);
        ASSERT(status == OS_SUCCESS);

        if(InitTaskStack)
        {
            free(InitTaskStack);

            InitTaskStack = NULL;
        }
    }

#if defined(LTEONLY_8M8M) || defined(CRANEL_4MRAM)
	 //lfs_cache_task_resume();
#endif

    OSATimerDelete (TimerDeleteInitTask);
}

#ifdef PHS_SW_DEMO_TTC

#define NVM_HEAD_SET_STRING(header,field,value) \
   strncpy(header.field,value,sizeof(header.field)-1)

BOOL PlatformNvmHeaderValid(NVM_Header_ts *header)
{
    if ((strcmp(header->StructName, "PlatformCfgDataS") != 0)||
	    (strcmp(header->Version, "1.0") != 0)||
	    (strcmp(header->HW_ID, "TTC") != 0))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


BOOL isLPMEnabled(void)
{
    return (gPMEnableFlag == _PM_ENABLE);
}

//ICAT EXPORTED FUNCTION - SW_PLAT,NVM,MSASetting
void setAptFlagInMsaCfgNvm(INT8 aptFlag)
{
#if defined (INTEL_FDI)
	FILE_ID 			fd;
	UINT32 				length;
	NVM_Header_ts		header;

	fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
	if (fd != 0)
	{
		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		ASSERT(PlatformNvmHeaderValid((&header)));

		/* read structure */
		length = FDI_fread((void *)(&(PlatformCfg.MsaCfg)), sizeof(MSACfgDataS), 1, fd);
		if (length == 1)
		{
			/* update config */
			gVcxoStableTime     = PlatformCfg.MsaCfg.ucVcxoStableTime;
			gPllStableTime      = PlatformCfg.MsaCfg.ucPllStableTime;
			gClkGenTime         = PlatformCfg.MsaCfg.ucClkGenTime;
			gDualCarrierFlag    = PlatformCfg.MsaCfg.ucDualCarrierFlag;
			gDualAntFlag        = PlatformCfg.MsaCfg.ucDualAntFlag;
			gAptFlag            = PlatformCfg.MsaCfg.AptFlag;
			FDI_fclose(fd);

			fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
			if (fd != 0)
			{
				FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);
				gAptFlag = (APT_TYPE)aptFlag;
				PlatformCfg.MsaCfg.AptFlag = (APT_TYPE)aptFlag;
				FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);
				FDI_fclose(fd);
			}
		}
	}
	else
	{
		/* write diag cfg */
		fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
		if (fd != 0)
		{
			/* write structure header */
			header.StructSize = sizeof(PlatformCfgDataS);
			header.NumofStructs = 1;
			NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
			NVM_HEAD_SET_STRING(header,Date,"");
			NVM_HEAD_SET_STRING(header,time,"");
			NVM_HEAD_SET_STRING(header,Version,"1.0");
			NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
			NVM_HEAD_SET_STRING(header,CalibVersion,"");

			FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

			PlatformCfg.MsaCfg.ucVcxoStableTime     = gVcxoStableTime;
			PlatformCfg.MsaCfg.ucPllStableTime      = gPllStableTime;
			PlatformCfg.MsaCfg.ucClkGenTime         = gClkGenTime;
			PlatformCfg.MsaCfg.ucDualCarrierFlag    = gDualCarrierFlag;
			PlatformCfg.MsaCfg.ucDualAntFlag        = gDualAntFlag;
			gAptFlag                                = (APT_TYPE)aptFlag;
			PlatformCfg.MsaCfg.AptFlag              = (APT_TYPE)aptFlag;

			FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);
			FDI_fclose(fd);
		}
	}
#endif

}


int getAptFlagInMsaCfgNvm(void)
{
	DbgPrintf("getAptFlagInMsaCfgNvm = %d\r\n",(int)gAptFlag);
	return (int)gAptFlag;
}

UINT8 Sulog2SDCard(void)
{
	return SulogSetDefault.Sulog2SdCardFlag;
}

SULOG_TYPE_ID SulogType(void)
{
	return SulogSetDefault.logSwitch;
}

void InitSulogConfigToDSP(void)
{
	CPASendSulogConfigToDSP(SulogSetDefault);
}

void SulogCfgUpdateSetting(SULOG_ST SulogSet, int saved)
{
#if defined (INTEL_FDI)
	FILE_ID 			fd;
	UINT32				length;
	NVM_Header_ts		header;

	if(SulogSet.logSwitch == SulogCfgDataDefault.logSwitch)
	{
		CPASendSulogConfigToDSP(SulogSet);
	}

	if(saved)
	{
		SulogCfgDataDefault.logSwitch = SulogSet.logSwitch;
		SulogCfgDataDefault.Sulog2SdCardFlag = SulogSet.Sulog2SdCardFlag;
		if(SulogSet.Sulog2SdCardFlag)
			SulogCfgDataDefault.PrintLevelForSdCardEnable = SulogSet.PrintLevel;
		else
			SulogCfgDataDefault.PrintLevelForSdCardDisable = SulogSet.PrintLevel;

		fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
		if (fd != 0)
		{
			/* write structure header */
			header.StructSize = sizeof(PlatformCfgDataS);
			header.NumofStructs = 1;
			NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
			NVM_HEAD_SET_STRING(header,Date,"");
			NVM_HEAD_SET_STRING(header,time,"");
			NVM_HEAD_SET_STRING(header,Version,"1.0");
			NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
			NVM_HEAD_SET_STRING(header,CalibVersion,"");

			FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

			/* Sulog Cfg Data */
			memcpy(&(PlatformCfg.SulogCfg), &SulogCfgDataDefault, sizeof(SulogCfgDataS));

			FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

			/* close file */
			FDI_fclose(fd);
		}

	}
#endif
}

UINT8 GetDualCarrierCfg(void)
{
	return gDualCarrierFlag;
}

UINT8 GetDualAntCfg(void)
{
	return gDualAntFlag;
}

UINT8 GetIAptStatus(void)
{
	return (UINT8)(gAptFlag);
}

BOOL isCpuUsageDumpEnabled(void)
{
	return (SysDbgCfg.cpuUsageDumpEnable == _CPU_USAGE_DUMP_ENABLE)?TRUE : FALSE;
}

UINT32 getCpuDumpInterval(void)
{
	return SysDbgCfg.dumpInterval;
}

BOOL gIMLSettingNeedUpdateFlag=FALSE;

void CPAGetDspLogSettingInfo(BOOL * IMLSettingNeedUpdateFlag,HSLCfgDataS*pIMLCfgdata)
{


	*IMLSettingNeedUpdateFlag=gIMLSettingNeedUpdateFlag;


	memcpy(pIMLCfgdata,&gIMLCfgdata,sizeof(gIMLCfgdata));


}

void CPASetDsplogSettingUpdateFlag(BOOL flag)
{

	gIMLSettingNeedUpdateFlag=flag;


}



void SetHSLPinMux()
{
    if((CUSTOM_EVB3 == bspGetBoardType())||
		(CUSTOM_SIM2 == bspGetBoardType())||
		(CUSTOM_NOKIA == bspGetBoardType())||
		(ASR_EVB == bspGetBoardType())) //SAARN has no HSL.
    {
		if(gIMLCfgdata.IMLConfigVal == IMLConfig_2HSL_BIGBOARD)
		{
			// GPIO_61- 66	pinmux (used by HSL)
			*(volatile unsigned long *)0xD401E308 = 0x00001845;
			*(volatile unsigned long *)0xD401E30C = 0x00001845;
			*(volatile unsigned long *)0xD401E310 = 0x00001845;
			*(volatile unsigned long *)0xD401E314 = 0x00001845;
			*(volatile unsigned long *)0xD401E318 = 0x00001845;
			*(volatile unsigned long *)0xD401E31C = 0x00001845;
		}
	}
}

void SetIMLSettingToNVM(IMLCfgDataS *IMLCfgdata)
{
	FILE_ID 			fd;
	UINT32				length;
	NVM_Header_ts		header;

	fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
	if (fd != 0)
	{
		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		ASSERT(PlatformNvmHeaderValid((&header)));

		/* read structure */
		length = FDI_fread((void *)(&(PlatformCfg.HslCfg)), sizeof(HSLCfgDataS), 1, fd);
		if (length == 1)
		{
			/* update config */

			gPMEnableFlag		    = PlatformCfg.HslCfg.PMCfgVal;
			gHWDFCEnableFlag	    = PlatformCfg.HslCfg.HWDFCCfgVal;
			gHWDFCTestFlag		    = PlatformCfg.HslCfg.HWDFCTestCfgVal;
			gVCXOEnableFlag 	    = PlatformCfg.HslCfg.VCXOCfgVal;
			SDLogEnableFlag 	    = PlatformCfg.HslCfg.SDLogCfgVal;
			gL1AcatLogEnableFlag    = PlatformCfg.HslCfg.L1AcatLogVal;

#ifdef SS_IPC_SUPPORT
			gDipEnable		        = PlatformCfg.HslCfg.dipEnable;
#endif
		}
		/* close file */
		FDI_fclose(fd);
	}
	else// NO nvm
	{
		//should have this nvm file, if do not have, should have created default one when boot up.
		//shuold never come here
		ASSERT(FALSE);

	}

	fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
	if (fd != 0)
	{
		/* write structure header */
		header.StructSize = sizeof(PlatformCfgDataS);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

		FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		PlatformCfg.HslCfg.PMCfgVal         = gPMEnableFlag;
		PlatformCfg.HslCfg.VCXOCfgVal       = gVCXOEnableFlag;
		PlatformCfg.HslCfg.HWDFCCfgVal      = gHWDFCEnableFlag;
		PlatformCfg.HslCfg.HWDFCTestCfgVal  = gHWDFCTestFlag;
		PlatformCfg.HslCfg.SDLogCfgVal      = SD_LOG_DISABLE;
		PlatformCfg.HslCfg.L1AcatLogVal     = gL1AcatLogEnableFlag; /* CQ0003TTTT */
		//write the setting value into NVM
		memcpy(&(PlatformCfg.HslCfg.IMLCfgdata),IMLCfgdata,sizeof(gIMLCfgdata));

		//store NVM current config value to golbal one, L1 may use it
		memcpy(&gIMLCfgdata,IMLCfgdata,sizeof(gIMLCfgdata));

#ifdef SS_IPC_SUPPORT
		PlatformCfg.HslCfg.dipEnable = gDipEnable;
#endif

		/* write structure */
		FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

		/* close file */
		FDI_fclose(fd);

		//after set nvm, check if HSL enabled we need config HSL PINMUX
		SetHSLPinMux();

		if(CPACheckNeedSendIPCDirectly())
		{
			CPASetDsplogSettingUpdateFlag(TRUE);
			CPASendDspLogSettingToDSP();
		}

		else
		{
			CPASetDsplogSettingUpdateFlag(TRUE);

		}
	}

}


void GetIMLSettingFromNVM(IMLCfgDataS *IMLCfgdata)
{
	FILE_ID 			fd;
	UINT32				length;
	NVM_Header_ts		header;

	fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
	if (fd != 0)
	{
		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		ASSERT(PlatformNvmHeaderValid((&header)));

		/* read structure */
		length = FDI_fread((void *)(&(PlatformCfg.HslCfg)), sizeof(HSLCfgDataS), 1, fd);
		if (length == 1)
		{
			/* update config */
			//gHSLEnableFlag	    = PlatformCfg.HslCfg.HSLCfgVal;
			gPMEnableFlag		    = PlatformCfg.HslCfg.PMCfgVal;
			gHWDFCEnableFlag	    = PlatformCfg.HslCfg.HWDFCCfgVal;
			gHWDFCTestFlag		    = PlatformCfg.HslCfg.HWDFCTestCfgVal;
			gVCXOEnableFlag 	    = PlatformCfg.HslCfg.VCXOCfgVal;
			SDLogEnableFlag 	    = PlatformCfg.HslCfg.SDLogCfgVal;
			gL1AcatLogEnableFlag    = PlatformCfg.HslCfg.L1AcatLogVal; /* CQ00028095*/
			//gL1IML2DDRVal 	    = PlatformCfg.HslCfg.L1IML2DDRVal;

			memcpy(&gIMLCfgdata, &(PlatformCfg.HslCfg.IMLCfgdata), sizeof(gIMLCfgdata));

#ifdef SS_IPC_SUPPORT
			gDipEnable		        = PlatformCfg.HslCfg.dipEnable;
#endif
		}
		//write the value in NVM to function caller
		memcpy(IMLCfgdata, &gIMLCfgdata, sizeof(gIMLCfgdata));

		/* close file */
		FDI_fclose(fd);
	}
	else// NO nvm
	{
		//should have this nvm file, if do not have, should have created default one when boot up.
		//shuold never come here
		ASSERT(FALSE);
	}
}

/* CQ0003TTTT - begin */
UINT8 GetHslL1AcatLogFlag(void)
{
	return (UINT8)(gL1AcatLogEnableFlag);
}
/* CQ0003TTTT - end */
void GetIMLConfigStatus(IMLCfgDataS *IMLCfgdata)
{

	memcpy(IMLCfgdata,&gIMLCfgdata,sizeof(gIMLCfgdata));

}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      GetUsbDriverConfig                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get the usb driver configuration.                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Usb_DriverS                         Driver configuration.        */
/*                                                                       */
/*************************************************************************/
Usb_DriverS *GetUsbDriverConfig(void)
{
    return &usbDrvCfg;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      useYmodem                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function get ymodem flag.                                   */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL useYmodem(void)
{
#ifdef YMODEM_EEH_DUMP
    if ((ymodemdumpflag == 1) &&
        (YmodemDumpCfg.config == YMODEM_ENABLE))
    {
        return TRUE;
    }
	else
#endif
	{
	    return FALSE;
    }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      getYmodemConfig                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function get ymodem config.                                 */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      size                                Memory size                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
int getYmodemConfig(void)
{
#ifdef YMODEM_EEH_DUMP
    return YmodemDumpCfg.config;
#else
    return 0;
#endif
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diagGetDevType                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get diag device type.                               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
DIAG_DEV_TYPE diagGetDevType(void)
{
    return diagCfg.diagDevType;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      diagCommSdLogEnable                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function check whether the Diag SD logging is enable or not. */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
BOOL diagCommSdLogEnable(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
	if (!sdcard_is_ready())
	{
		return FALSE;
	}

	if (SysIsAssert())
	{
		return TRUE;
	}

	if (diagGetDevType() == DIAG_DEV_SD)
	{
		return TRUE;
	}
	else
#endif
	{
		return FALSE;
	}
}

/*===========================================================================

FUNCTION DumpFileToSDEnable

DESCRIPTION
  Check whether we dump assert bin to SD card is enable or not.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
BOOL DumpFileToSDEnable(void)
{
#ifndef CRANE_SD_NOT_SUPPORT
    if (sdcard_is_ready())
    {
        return TRUE;
    }
	else
#endif
	{
        return FALSE;
	}
}

extern UINT32 rti_enable_bak;
extern unsigned int rti_enable;

#ifdef PLAT_USE_ALIOS
UINT32 alios_dbg_dis_opt_bak = 0;
#endif

void set_mifi_log(int para1, int backup) // backup: 0 no backup, 1 back up, 2: restore
{
    char log = 0;
    char msg = 0;
    char rti = 0;

    if (backup == 1) {
#ifdef CRNAE_LOG_OPTIMIZE
        log_config_bak = log_config;
#ifdef PLAT_USE_ALIOS
        alios_dbg_dis_opt_bak = OsaGetDbgDisOpt();
#endif
#endif
        rti_enable_bak = rti_enable;

     }
    if (backup != 2) {
#ifdef CRNAE_LOG_OPTIMIZE
        log = (para1 & 0xF00)>>8;
        msg = (para1 & 0xF0)>>4;
#endif
        rti = para1 & 0x0F;

#ifdef CRNAE_LOG_OPTIMIZE
        log_config.log_cfg = (Log_ConfigE)log;
        log_config.msg_cfg = (Msg_ConfigE)msg;
        log_config.rti_cfg = (RTI_ConfigE)rti;
#endif
        rti_enable = rti;

#ifdef PLAT_USE_ALIOS
		if(rti_enable == 0 )
		{
			OsaSetDbgDisOpt(3);
		}
		else
		{
			OsaSetDbgDisOpt(0);
		}
#endif
    }
    else {
#ifdef CRNAE_LOG_OPTIMIZE
        log_config = log_config_bak;
#endif
        rti_enable = rti_enable_bak;

#ifdef PLAT_USE_ALIOS
		OsaSetDbgDisOpt(alios_dbg_dis_opt_bak);
#endif
    }
}

/*===========================================================================

FUNCTION LogConfigure

DESCRIPTION
  The function modify the log configuration.

DEPENDENCIES
  none

RETURN VALUE
  return staus

SIDE EFFECTS
  none

===========================================================================*/
void LogConfigure(char log, char msg, char rti)
{
#if defined (INTEL_FDI)
    FILE_ID             fd;
    NVM_Header_ts       header;

    /* write diag cfg */
    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
		header.StructSize = sizeof(PlatformCfgDataS);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        if(log <= (char)ACAT_LOG_ENABLE)
        {
            log_config.log_cfg  = (Log_ConfigE)log;
        }

        if(msg <= (char)ACAT_MSG_ENABLE)
        {
            log_config.msg_cfg  = (Msg_ConfigE)msg;
        }

        if(rti <= (char)RTI_MIPS_ENABLE)
        {
            log_config.rti_cfg  = (RTI_ConfigE)rti;
            //rtiCurrentConfig    = (RTI_ConfigE)rti;
        }

        /* Log Cfg Data */
		memcpy(&(PlatformCfg.LogCfg), &log_config, sizeof(Log_ConfigS));

        FDI_fwrite((void*)&PlatformCfg, sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
#endif
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      PlatformCfgGetSetting                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function get platform configuration from NVM file.           */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void PlatformCfgGetSetting(void)
{
#if defined (INTEL_FDI)
	FILE_ID fd;
	BOOL valid = FALSE;
	NVM_Header_ts header;

	fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
	if (fd != 0)
	{
		/* Read structure header */
		FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		if (!PlatformNvmHeaderValid((&header)))
	    {
	        /* close file */
		    FDI_fclose(fd);

	        CPUartLogPrintf("!!Warning: Invalid Platform_Cfg.nvm");
            FDI_remove(PLATFORM_CFG_FILE);

            /* It is invalid file */
            valid = FALSE;
	    }
	    else
	    {

    		/* read structure */
    		FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

    		/* close file */
    		FDI_fclose(fd);

            /* Check the validity of Tail guard */
    		if(PlatformCfg.TailGuard == PLATFORM_CFG_GUARD)
    		{
                /* MSA Cfg Data */
                gVcxoStableTime         = PlatformCfg.MsaCfg.ucVcxoStableTime;
                gPllStableTime          = PlatformCfg.MsaCfg.ucPllStableTime;
                gClkGenTime             = PlatformCfg.MsaCfg.ucClkGenTime;
                gDualCarrierFlag        = PlatformCfg.MsaCfg.ucDualCarrierFlag;
                gDualAntFlag            = PlatformCfg.MsaCfg.ucDualAntFlag;
                gAptFlag                = PlatformCfg.MsaCfg.AptFlag;

                /* HSL Cfg Data */
                gPMEnableFlag           = PlatformCfg.HslCfg.PMCfgVal;
                gHWDFCEnableFlag	    = PlatformCfg.HslCfg.HWDFCCfgVal;
                gHWDFCTestFlag		    = PlatformCfg.HslCfg.HWDFCTestCfgVal;
                gVCXOEnableFlag         = PlatformCfg.HslCfg.VCXOCfgVal;
                SDLogEnableFlag         = PlatformCfg.HslCfg.SDLogCfgVal;
                gL1AcatLogEnableFlag    = PlatformCfg.HslCfg.L1AcatLogVal; /* CQ00028095*/
                //gL1IML2DDRVal        = PlatformCfg.HslCfg.L1IML2DDRVal;
                memcpy(&gIMLCfgdata, &(PlatformCfg.HslCfg.IMLCfgdata), sizeof(gIMLCfgdata));
#ifdef SS_IPC_SUPPORT
                gDipEnable		        = PlatformCfg.HslCfg.dipEnable;
#endif

                /* System debug Cfg Data */
        		memcpy(&SysDbgCfg, &(PlatformCfg.SysDbgCfg), sizeof(SYSDBGCfgDataS));

        		/* Log Cfg Data */
        		memcpy(&log_config, &(PlatformCfg.LogCfg), sizeof(Log_ConfigS));

        		/* Usb driver Cfg Data */
        		memcpy(&usbDrvCfg, &(PlatformCfg.usbDrvCfg), sizeof(Usb_DriverS));

                /* LTE Cfg Data */
        		memcpy(&LteCfg, &(PlatformCfg.LteCfg), sizeof(LTE_CONFIG_S));

        		/* Ymodem Cfg Data */
        		memcpy(&YmodemDumpCfg, &(PlatformCfg.YmodemCfg), sizeof(Ymodem_Dump_type));

        		/* Sulog Cfg Data */
        		memcpy(&SulogCfgDataDefault, &(PlatformCfg.SulogCfg), sizeof(SulogCfgDataS));

        		/* RTI Cfg Data */
        		memcpy(&rtiConfig, &(PlatformCfg.rtiConfig), sizeof(RTICfg_t));

                /* UART Cfg Data */
        		memcpy(&uartCfg, &(PlatformCfg.uartCfg), sizeof(uartCfgDataS));

                /* Activate Code Flag. */
        		activateCodeFlag = PlatformCfg.uartCfg.actiCodeFlag;

        		/* Assert Random Flag. */
        		AssertRandomFlag = PlatformCfg.uartCfg.astRandomFlag;

        		/* EE Cfg Data */
        		memcpy(&eeConfiguration, &(PlatformCfg.eeCfg), sizeof(EE_Configuration_t));

        		/* Diag config */
    			memcpy(&diagCfg, &(PlatformCfg.diagCfg), sizeof(diagCfgDataS));

    			GLFeatureFlag = diagCfg.GLFeatureFlag;

        		if (diagCfg.usbUserMode)
        		{
        			usbUserMode = TRUE;
        		}

                /* It is valid file */
        		valid = TRUE;
    		}
    		else
    		{
                CPUartLogPrintf("!!Wrong Tail 0x%x, Invalid Platform_Cfg.nvm", PlatformCfg.TailGuard);
                FDI_remove(PLATFORM_CFG_FILE);

                /* It is invalid file */
                valid = FALSE;
    		}
		}
	}

	if(!valid)
	{
		/* write diag cfg */
		fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
		if (fd != 0)
		{
			/* write structure header */
			header.StructSize = sizeof(PlatformCfgDataS);
			header.NumofStructs = 1;
			NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
			NVM_HEAD_SET_STRING(header,Date,"");
			NVM_HEAD_SET_STRING(header,time,"");
			NVM_HEAD_SET_STRING(header,Version,"1.0");
			NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
			NVM_HEAD_SET_STRING(header,CalibVersion,"");

			FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

            /* MSA Cfg Data */
			PlatformCfg.MsaCfg.ucVcxoStableTime  = gVcxoStableTime;
            PlatformCfg.MsaCfg.ucPllStableTime   = gPllStableTime;
            PlatformCfg.MsaCfg.ucClkGenTime      = gClkGenTime;
            PlatformCfg.MsaCfg.ucDualCarrierFlag = gDualCarrierFlag;
            PlatformCfg.MsaCfg.ucDualAntFlag     = gDualAntFlag;
            PlatformCfg.MsaCfg.AptFlag           = gAptFlag;

            /* HSL Cfg Data */
			PlatformCfg.HslCfg.PMCfgVal         = gPMEnableFlag;
			PlatformCfg.HslCfg.VCXOCfgVal       = gVCXOEnableFlag;
			PlatformCfg.HslCfg.HWDFCCfgVal      = gHWDFCEnableFlag;
			PlatformCfg.HslCfg.HWDFCTestCfgVal  = gHWDFCTestFlag;
			PlatformCfg.HslCfg.SDLogCfgVal      = SD_LOG_DISABLE;
			PlatformCfg.HslCfg.L1AcatLogVal     = gL1AcatLogEnableFlag; /* CQ0003TTTT */
#ifdef SS_IPC_SUPPORT
            PlatformCfg.HslCfg.dipEnable        = gDipEnable;
#endif
			memcpy(&(PlatformCfg.HslCfg.IMLCfgdata), &gIMLCfgdata, sizeof(gIMLCfgdata));

            /* System debug Cfg Data */
			memcpy(&(PlatformCfg.SysDbgCfg), &SysDbgCfg, sizeof(SYSDBGCfgDataS));

			/* Log Cfg Data */
			memcpy(&(PlatformCfg.LogCfg), &log_config, sizeof(Log_ConfigS));

			/* Usb driver Cfg Data */
			memcpy(&(PlatformCfg.usbDrvCfg), &usbDrvCfg, sizeof(Usb_DriverS));

            /* LTE Cfg Data */
			memcpy(&(PlatformCfg.LteCfg), &LteCfg, sizeof(LTE_CONFIG_S));

			/* Ymodem Cfg Data */
			memcpy(&(PlatformCfg.YmodemCfg), &YmodemDumpCfg, sizeof(Ymodem_Dump_type));

			/* Sulog Cfg Data */
			memcpy(&(PlatformCfg.SulogCfg), &SulogCfgDataDefault, sizeof(SulogCfgDataS));

			CPUartLogPrintf("sulog Disable:0x%x,0x%x",
				SulogCfgDataDefault.PrintLevelForSdCardDisable.value32[0],
				SulogCfgDataDefault.PrintLevelForSdCardDisable.value32[1]
				);

			CPUartLogPrintf("sulog Enable:0x%x,0x%x",
				SulogCfgDataDefault.PrintLevelForSdCardEnable.value32[0],
				SulogCfgDataDefault.PrintLevelForSdCardEnable.value32[1]
				);

            /* RTI Cfg Data */
		    memcpy(&(PlatformCfg.rtiConfig), &rtiConfig, sizeof(RTICfg_t));

            /* UART Cfg Data */
            memcpy(&(PlatformCfg.uartCfg), &uartCfg, sizeof(uartCfgDataS));

            /* Init default EE Cfg Flag. */
            eeInitDfltConfiguration();

            /* EE Cfg Data */
    		memcpy(&(PlatformCfg.eeCfg), &eeConfiguration, sizeof(EE_Configuration_t));

    		/* Diag config */
			memcpy(&(PlatformCfg.diagCfg), &diagCfg, sizeof(diagCfgDataS));

            /* Tail guard */
			PlatformCfg.TailGuard = PLATFORM_CFG_GUARD;

			/* write structure */
			FDI_fwrite((void*)&PlatformCfg, sizeof(PlatformCfgDataS), 1, fd);

			/* close file */
			FDI_fclose(fd);
		}
	}

#ifdef SS_IPC_SUPPORT
    sacDevSetDipOption(gDipEnable);
#endif

	CPASetDsplogSettingUpdateFlag(TRUE);

	DIAG_FILTER(SW_PLAT, NVM, DUMP, DIAG_INFORMATION)
	diagStructPrintf("DIAG Configuartion: %S{HSLCfgDataS}", &(PlatformCfg.HslCfg), sizeof(HSLCfgDataS));

	SulogSetDefault.logSwitch        = SulogCfgDataDefault.logSwitch;
	SulogSetDefault.Sulog2SdCardFlag = SulogCfgDataDefault.Sulog2SdCardFlag;

	if(SulogSetDefault.Sulog2SdCardFlag)
	{
		SulogSetDefault.PrintLevel = SulogCfgDataDefault.PrintLevelForSdCardEnable;
	}
	else
	{
		SulogSetDefault.PrintLevel = SulogCfgDataDefault.PrintLevelForSdCardDisable;
	}

	memcpy(&log_config_bak, &log_config, sizeof(Log_ConfigS));

    /* uart Cfg Dev Init */
	uartCfgDevInit();

    /* Suspend LFS cache task till communication init done. */
#if defined(LTEONLY_8M8M) || defined(CRANEL_4MRAM)
	//lfs_cache_task_suspend();
#endif
#endif

}

void setLogSdcardPartitionType(int type)
{
	FILE_ID 			fd;
	UINT32				length;
	NVM_Header_ts		header;

	fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
	if (fd != 0)
	{
		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

		/* close file */
		FDI_fclose(fd);
	}
	else// NO nvm
	{
		//should have this nvm file, if do not have, should have created default one when boot up.
		//shuold never come here
		ASSERT(FALSE);
		return;

	}

	fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
	if (fd != 0)
	{
	    /* write structure header */
		header.StructSize = sizeof(PlatformCfgDataS);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

		FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        PlatformCfg.uartCfg.multiVol = type;

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

		/* close file */
		FDI_fclose(fd);

	}
}

#define CHANGEABLE_CFG_FILE	    "CCfg.dat"


void save_usim_swap_flag(UINT32 val)
{
	FILE_ID 			fd;
	UINT32				length;
	NVM_Header_ts		header;
	UINT8 v8;
	UINT8 buf[16];
	extern UINT32 usim_swap_flag;

	usim_swap_flag=val;

	memset(buf, 0, 16);

	fd = FDI_fopen(CHANGEABLE_CFG_FILE, "rb");
	if (fd != 0)
	{
		length = FDI_fread((void *)buf, 1, 16, fd);
		FDI_fclose(fd);
	}

	fd = FDI_fopen(CHANGEABLE_CFG_FILE, "wb");
	if (fd != 0)
	{
		buf[0]&=~0x1;
		buf[0]|=(val&0x1);

        FDI_fwrite((void *)buf, 1, 16, fd);
		FDI_fclose(fd);
	}
}



UINT32 read_usim_swap_flag(void)
{

	UINT8 buf[16];
	FILE_ID fd;
	UINT32 length;

	fd = FDI_fopen(CHANGEABLE_CFG_FILE, "rb");
	if (fd != 0)
	{
        length = FDI_fread((void *)buf, 1, 16, fd);
		FDI_fclose(fd);

		if(length==16)
		{
			if((buf[0]&0x1)==1)
				return 1;
			else
				return 0;
		}
		else
			return 0;
		
	}
	else
		return 0;


}

#ifdef YMODEM_EEH_DUMP
void setYmodemdumpflag(int flag)
{
    ymodemdumpflag = flag;
}

int YmodemCfgSet(int type)
{
	FILE_ID 			fd;
	NVM_Header_ts		header;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
		header.StructSize = sizeof(PlatformCfgDataS);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		if (type == YMODEM_ENABLE)
			YmodemDumpCfg.config = YMODEM_ENABLE;
		else
			YmodemDumpCfg.config = YMODEM_DISABLE;

        /* Ymodem Cfg Data */
		memcpy(&(PlatformCfg.YmodemCfg), &YmodemDumpCfg, sizeof(Ymodem_Dump_type));

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
	else
	{
		return -1;
    }

	return 0;
}
#endif

//ICAT EXPORTED FUNCTION - EE_HANDLER,EE,eeConfiguration_SilentReset
void eeConfiguration_SilentReset(FinalAct_t finalAction)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
        return;

    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        eeConfiguration.finalAction = finalAction;

        /* Copy EE Cfg Data */
		memcpy(&(PlatformCfg.eeCfg), &eeConfiguration, sizeof(EE_Configuration_t));
        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

    }
}

#ifdef QUECTEL_PROJECT_CUST
//ICAT EXPORTED FUNCTION - EE_HANDLER,EE,eeConfiguration_SilentReset
int eeConfiguration_SilentResetFLAG(UINT32 resetflag)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;
	int ret = TRUE;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        if(!PlatformNvmHeaderValid((&header)))
        {
        	FDI_fclose(fd);
			return FALSE;
        }

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        return FALSE;

    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        eeConfiguration.dumpResetFlag = resetflag;

        PlatformCfg.eeCfg.dumpResetFlag = resetflag;

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
	return TRUE;
}
#endif
//ICAT EXPORTED FUNCTION - EE_HANDLER,EE,SilentResetEnable
void SilentResetEnable(void)
{
	eeConfiguration_SilentReset(EE_RESET);
}

//ICAT EXPORTED FUNCTION - EE_HANDLER,EE,SilentResetDisable
void SilentResetDisable(void)
{
	eeConfiguration_SilentReset(EE_EXTERNAL);
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,getUsbUserMode
BOOL getUsbUserMode(void)
{
	FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;

    usbUserMode = FALSE;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);
        if (length == 1)
		{
			memcpy(&diagCfg, &(PlatformCfg.diagCfg), sizeof(diagCfgDataS));
		}

		if(diagCfg.usbUserMode)
		{
			usbUserMode = TRUE;
		}

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
    }

    return usbUserMode;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      setGLFeatureFlag                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function set GLF eature Flag.                                */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void setGLFeatureFlag(BOOL lGLFeatureFlag)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
        return;

    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		//update set value to golbal flag
		GLFeatureFlag = lGLFeatureFlag;

		//update set value in NVM
        diagCfg.GLFeatureFlag = lGLFeatureFlag;

        /* Diag config */
		memcpy(&(PlatformCfg.diagCfg), &diagCfg, sizeof(diagCfgDataS));

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

    }

    DIAG_FILTER(SW_PLAT,DIAG,setGLFeatureFlag,DIAG_INFORMATION)
	diagPrintf("setGLFeatureFlag to NVM, current value is : %d", lGLFeatureFlag);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      setDiagDevType                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function set diag device type.                               */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void setDiagDevType(DIAG_DEV_TYPE type)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;
    DIAG_DEV_TYPE       OrigType;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
        return;

    }

    OrigType = PlatformCfg.diagCfg.diagDevType;
    if((OrigType == type)||(OrigType == DIAG_DEV_FS))
    {
        return;
    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		diagCfg.diagDevType = type;

		/* Diag config */
		memcpy(&(PlatformCfg.diagCfg), &diagCfg, sizeof(diagCfgDataS));

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

    }

    switch(OrigType)
    {
        case DIAG_DEV_SD:
        {
        #if !defined (CRANE_SD_NOT_SUPPORT)
            diag_comm_sd_uninit();
        #endif
            break;
        }

        default:
        {
            break;
        }
    }

    switch(type)
    {
        case DIAG_DEV_SD:
        {
            #if !defined (CRANE_SD_NOT_SUPPORT)
            diag_comm_sd_init();
            #endif
            break;
        }

        default:
        {
            break;
        }
    }
}

#ifdef QUECTEL_PROJECT_CUST

BOOL quec_sd_log_enable(BOOL en)
{
	if(TRUE == en)
	{
		CPUartLogPrintf("diag sd");
		diagCfg.diagDevType = DIAG_DEV_SD;
		PlatformCfg.diagCfg.diagDevType = DIAG_DEV_SD;
		#if !defined (CRANE_SD_NOT_SUPPORT)
			return diag_comm_sd_init();
		#else
			return 0;
		#endif
	}
	else
	{
		CPUartLogPrintf("diag no sd");
		diagCfg.diagDevType = DIAG_DEV_USB;
		PlatformCfg.diagCfg.diagDevType = DIAG_DEV_USB;
		#if !defined (CRANE_SD_NOT_SUPPORT)
			return diag_comm_sd_uninit();
		#else
			return 0;
		#endif
	}
}
#endif
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      setSulogDevType                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function set sulog device type.                              */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void setSulogDevType(SULOG_DEV_TYPE type)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
        return;

    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        diagCfg.sulogDevType = type;

        /* Diag config */
		memcpy(&(PlatformCfg.diagCfg), &diagCfg, sizeof(diagCfgDataS));

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

    }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      setEehDumpDevType                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      The function set eeh device type.                                */
/*                                                                       */
/* CALLED BY                                                             */
/*                                                                       */
/*      Application                                                      */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      Application                         The application function     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                N/A                          */
/*                                                                       */
/*************************************************************************/
void setEehDumpDevType(EEH_DUMP_DEV_TYPE type)
{
    FILE_ID             fd;
    UINT32              length;
    NVM_Header_ts       header;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        /* read structure header */
        length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
        ASSERT(PlatformNvmHeaderValid((&header)));

        /* read structure */
        length = FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);
    }
    else// NO nvm
    {
        //should have this nvm file, if do not have, should have created default one when boot up.
        //shuold never come here
        ASSERT(FALSE);
        return;

    }

    fd = FDI_fopen(PLATFORM_CFG_FILE, "wb");
    if (fd != 0)
    {
        /* write structure header */
        header.StructSize = sizeof(PlatformCfgDataS);
        header.NumofStructs = 1;
        NVM_HEAD_SET_STRING(header,StructName,"PlatformCfgDataS");
        NVM_HEAD_SET_STRING(header,Date,"");
        NVM_HEAD_SET_STRING(header,time,"");
        NVM_HEAD_SET_STRING(header,Version,"1.0");
        NVM_HEAD_SET_STRING(header,HW_ID,"TTC");
        NVM_HEAD_SET_STRING(header,CalibVersion,"");

        FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

        diagCfg.eehDumpDevType = type;

        /* Diag config */
		memcpy(&(PlatformCfg.diagCfg), &diagCfg, sizeof(diagCfgDataS));

        /* write structure */
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

    }
}

#define __REG(x)        *(volatile unsigned long*)(x)
#define GPIO112_ADDERSS 0xD401E2A0
#define GPIO78_ADDERSS 	0xD401E2E0
#define GPIO_3_PDR()     __REG(0xD401910C)     /* GPIO pin direction register */
#define GPIO_3_PSR(n)     __REG(0xD4019118)     /* GPIO pin output set register */
#define PULL_UP_C          0xC000  //Enable pull up resistor
#define PULL_DN_C          0xA000  //Enable pull down resistor
#define DRV_SLOW_C         0x0800  //Use slow drive strength
#define DRV_MED_C          0x1000  //Use medium drive strength
#define DRV_FAST_C         0x1800  //Use fast drive strength
#define AF0_C              0X0000  //Alternate function 0
#define AF1_C              0X0001  //Alternate function 1
#define AF2_C              0X0002  //Alternate function 2
#define AF3_C              0X0003  //Alternate function 3
#define AF4_C              0X0004  //Alternate function 4
#define AF5_C              0X0005  //Alternate function 5
#define AF6_C              0X0006  //Alternate function 6
#define AF7_C              0X0007  //Alternate function 7
#define RESERVED_C         0x00C0  //RESERVED_C bits that must be set

void MSAInit() //qianying, use this whole function for Crane.
{
	volatile unsigned long temp;
	UMTS_Chip_Version	Local_Umts_Chip_Version;

#if defined (NEZHA3_1826)

#if 0 //qianying, remove the clock configuration for FPGA.
    // CCGR & ACGR
    if(AC_IS_SHM)   //disable BBSD and MSALPEN
    {
	    *(volatile unsigned long *)0xD02500C4 &= ~((1<<25)|(1<<14)); //disable BBSD and MSASLPEN
    }
    temp = *(volatile unsigned long *)0xD0250034; //CP hardware clock gating
    temp |= 0x77FFFFFF;
    *(volatile unsigned long *)0xD0250034 = temp;

	*(volatile unsigned long *)0xD02500C8 = 0xdffefffe;

    *(volatile unsigned long *)0xD0250068 = 0x003FC7FF; //CPSS clock gating
    *(volatile unsigned long *)0xD025005C = 0x0; //set GB clock as 416M@PLL1 for default
#endif
	temp = *(volatile unsigned long *)0xD4050024;
    temp |= 0xFFFFFFFE;
	*(volatile unsigned long *)0xD4050024 = temp;

	// Set MSA clock
	*(volatile unsigned long *)0xd405003c = *(volatile unsigned long *)0xd405003c & 0xfffffffc;

    // enable I2S clock
    *(volatile unsigned long *)0xd4050040 = 0xF820130B;
    *(volatile unsigned long *)0xd4050044 = 0xF820130B;

    // AIB CLK enable
    *(volatile unsigned long *)0xD401503C = 0x3;

    // GPIO CLK enable
    *(volatile unsigned long *)0xD4015008 = 0x3;

#endif
}

UINT8 MSA_LOADER_BIN[] = {
	0x03,0xc0,0x00,0x18,0x24,0x00,0x3c,0xe1,0x00,0x00,
	0x3d,0xe1,0x00,0x00,0x48,0xe1,0xff,0xd0,0x08,0xe1,
	0x00,0xff,0x40,0x91,0x40,0x34,0x51,0xe1,0xe0,0xd1,
	0x11,0xe1,0x00,0x00,0x49,0xe1,0x01,0x00,0x09,0xe1,
	0x00,0x40,0x00,0x9c,0xa2,0xe0,0x02,0x10,0x03,0xc8,
	0x00,0x18,0x08,0x9e,0x00,0x9c,0x72,0xe2,0x64,0x62,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
#define MSA_LOADER_BIN_LEN	0x80

char* APP_BIN = (char*)0x07f00000;
#define APP_BIN_LEN 0x50000


void AIB_Secure_Write(unsigned int address, unsigned int value)
{
	BU_REG_WRITE(0xd4015050, 0xBABA);
	BU_REG_WRITE(0xd4015054, 0xEB10);
	BU_REG_WRITE(address, value);
}

UINT32 AIB_Secure_Read(unsigned int address)
{
	UINT32 val;
	BU_REG_WRITE(0xd4015050, 0xBABA);
	BU_REG_WRITE(0xd4015054, 0xEB10);
	val = BU_REG_READ(address);
	return val;
}

#ifdef OPENCPU_SUPPORT
BOOL copy_app_from_flash_to_psram(void)
{
    _ptentry *AppEntry = NULL;
	UINT32 AppFlashAddress = 0, AppCopySize = 0, AppLoadAddress = 0;

	AppEntry = ptable_find_entry("app");

	if(AppEntry != NULL)
	{
    	AppFlashAddress     = get_app_begin_address();
    	AppCopySize         = get_app_bin_size();
    	AppLoadAddress      = get_app_load_addr();

    	CPUartLogPrintf("[APP ] AppFlashAddress=[0x%x], CopySize=[%x], LoadAddress=[%x]",
    	                AppFlashAddress, AppCopySize, AppLoadAddress);

        memcpy( (void *)AppLoadAddress,(void *)AppFlashAddress, AppCopySize);

        return TRUE;
    }

    return FALSE;
}

void AppPhase1Init(void)
{
    UINT32 magic = 0;
    UINT32 AppAreaSize    = get_app_area_length();
    UINT32 AppLoadAddress = get_app_load_addr();
    UINT32 pFuncEntry = AppLoadAddress + 0xC;

	//load APP.bin
	if(!copy_app_from_flash_to_psram())
	{
		return;
	}

    /* Load Function table */
	memcpy((void *)pFuncEntry, (void *)FunctionEntry, sizeof(FunctionEntry));

    /* Cache clean APP area */
    CPUartLogPrintf("AppLoadAddress=[0x%x], AppAreaSize=[0x%x]", AppLoadAddress, AppAreaSize);
    CacheCleanMemory( (void *)AppLoadAddress, AppAreaSize);

    /* Check the validity of APP.bin */
    magic = *((volatile UINT32*)AppLoadAddress);
    if(magic != APP_MAGIC)
    {
        CPUartLogPrintf("Wrong App magic: 0x%x", magic);
    }
    else
    {
        CPUartLogPrintf("TransferControl to 0x%x", AppLoadAddress);
        TransferControl(AppLoadAddress);
    }
}
#endif

extern UINT8 isChip3601S;

#ifdef CRANE_MCU_DONGLE
int dsp_cpy_by_boot=0;
typedef struct {
    UINT32 address;
    UINT32 len;
    UINT32 reserved[6];
}dsp_backup_info;
#endif

int copy_dsp_from_flash_to_psram()
{
	extern UINT32 Image$$DDR_DSP_RO$$Base;
	unsigned int inLen = 0;
	UINT32 address, dsp_load_target_address;
	unsigned long magic;
    //COPY DSP.bin
    unsigned int ret = 1;
    unsigned int outLen = 1;
    unsigned int expected_dsp_size;
	unsigned int *dspBuffer;

	/*  before DDR_HEAP region initialed , the memeory could be reused as 64K lzop decompressed tmp buffer
	 *  reminder the cinit1 & cini2 recovery order & MPU config time.
	 */

	UINT32 dsp_bin_size            = 0;
	UINT32 dsp_load_source_address = 0;
	UINT32 dsp_flash_start_addr    = 0;
	BOOL is_dsp_on_internal_flash;

    address                   = (UINT32)(&Image$$DDR_DSP_RO$$Base);
	dsp_load_target_address   = ADDRESS_ALIGN(address);
	expected_dsp_size         = get_dsp_copy_size();
	is_dsp_on_internal_flash  = is_partition_internal_flash("dsp");
	dsp_flash_start_addr      = get_dsp_start_address();

	CPUartLogPrintf("[DSP] expected released dsp size [0x%.08x]", expected_dsp_size);
	CPUartLogPrintf("[DSP] decompress from flash [%s:0x%.08x] to [0x%0.8x]"
			,(is_dsp_on_internal_flash?PTABLE_FLASH_INTERNAL:PTABLE_FLASH_EXTERNAL)
			,dsp_flash_start_addr
			,dsp_load_target_address);

	//prepare for dsp source address
	//[internal] : base address 0x0000_0000 ,load into ram firstly.
	//[external] : base address 0x8000_0000 ,read directly.
	if(is_dsp_on_internal_flash)
	{
		//internal flash
		dsp_bin_size = get_dsp_partition_size();

		//TODO:
		//refine for case that default heap size smaller than target dsp.bin
		dspBuffer = (unsigned int *)malloc(dsp_bin_size);
		ASSERT(dspBuffer != NULL);

		CPUartLogPrintf("[DSP] copy dsp.bin from [interna:0x%0.8x] to heap buff =[0x%0.8x] len=[%x]"
				,dsp_flash_start_addr
				,dspBuffer
				,dsp_bin_size);

		CPUartLogPrintf("[DSP] spi_nor_do_read ++");
		ret = spi_nor_do_read(dsp_flash_start_addr, (unsigned int)dspBuffer, dsp_bin_size, 1);	//MQ:set dsp flash type to internal spi
		ASSERT(ret == 0);
		CPUartLogPrintf("[DSP] spi_nor_do_read --");

		dsp_load_source_address = (UINT32)dspBuffer;
	}else{
		//external flash
		dsp_load_source_address = dsp_flash_start_addr;
	}

	//do action
	//invoke lzop decompress to load dsp into target region
	magic = *(volatile unsigned long*)dsp_load_source_address;
	#if defined(LZOP_SUPPORT)
	if (0x4f5a4c89 == magic) //"a lzop image"
	{
		if(!lzop_decompress_safe((unsigned char *)dsp_load_source_address,(unsigned char *)dsp_load_target_address,&outLen,&inLen)){
			CPUartLogPrintf("[DSP] released dsp size [0x%.08x] inLen=[0x%.08x]", outLen,inLen);
			if(outLen != expected_dsp_size){
				CPUartLogPrintf("[DSP] WARNING: decompressed length [0x%.08x] unmatch with expected [0x%.08x].",outLen,expected_dsp_size);
			}
			ret = 0;
		} else {
			CPUartLogPrintf("** ERROR: DSP image decompress failed .");
		}
	} else
    #endif
	{
	#ifdef CRANE_MCU_DONGLE
	    if (0x0400005D == magic
	    || 0x0800005D == magic){//"a lzma image"
            dsp_backup_info *dspbk=NULL;
            extern UINT32 Image$$PS_NONCACHE_DATA$$Base;
            extern UINT32 Image$$DDR_DSP_RO$$Base;
            #define DSP_BACKUP_SIZE 0x00040000
            UINT32 *ncah_addr = NULL;
            UINT32 *dsp_addr = NULL;
            //UINT32 ps_udl_ddr_size = 0;
            ncah_addr    = &(Image$$PS_NONCACHE_DATA$$Base);
            dsp_addr    = &(Image$$DDR_DSP_RO$$Base);
            CPUartLogPrintf("** DSP image decompress by boot .");
            dspbk=(dsp_backup_info *)asr_property_get("dsp.backup.info");

            if(dspbk){
                /*
                ps_udl_ddr_size = get_ps_ul_dl_ddr_size();
                CPUartLogPrintf("copy dsp from_[%08x] to [%08x],len[%08x],ps_udl_ddr_size[%08x]",(unsigned char *)dspbk->address, dsp_addr,dspbk->len,ps_udl_ddr_size);
                if(dspbk->len>ps_udl_ddr_size){
                    CPUartLogPrintf("bkg size too larger!");
                    ASSERT(0);
                }
                memcpy((unsigned char *)dsp_addr,(unsigned char *)dspbk->address,dspbk->len);
                */
                ASSERT(0);
            }else{
                CPUartLogPrintf("copy dsp from_[%08x] to [%08x]",(unsigned char *)ncah_addr-DSP_BACKUP_SIZE, dsp_addr);
                memcpy((unsigned char *)dsp_addr,(unsigned char *)ncah_addr-DSP_BACKUP_SIZE,DSP_BACKUP_SIZE);
                dsp_cpy_by_boot=1;
            }

	    }
	    else{
	        CPUartLogPrintf("no compress dsp,copy dsp from_[%08x] to [%08x],len[%08x]",(unsigned char *)dsp_load_source_address, dsp_load_target_address,expected_dsp_size);
            memcpy((unsigned char *)dsp_load_target_address,(unsigned char *)dsp_load_source_address,expected_dsp_size);
	    }

        ret = 0;
     #else
        CPUartLogPrintf("** ERROR: expected a compressed DSP image.");
     #endif
    }

	if(is_dsp_on_internal_flash){
		free(dspBuffer);
	}

    return ret;

}
int copy_rf_from_flash_to_psram()
{
	UINT32 rfFlashAddress,rfCopySize,rfLoadAddress,magic;
	BOOL is_rf_on_internal_flash;


#if ((defined(LTEONLY_THIN_SINGLE_SIM) && !defined(NOT_REDUCE_SULOG_DSP)) || defined(REDUCE_SULOG_IRBUF_DSP))
    static UINT32 rfBackupAddress = 0;
    extern UINT32  Image$$DDR_NONCACHE_REGION_ACIPC_PS_DL$$Base;
    if(rfBackupAddress==NULL){
        rfFlashAddress           = (UINT32)(&Image$$DDR_NONCACHE_REGION_ACIPC_PS_DL$$Base);
        magic                    =  *(volatile unsigned long*)(rfFlashAddress);
        rfCopySize               =  *(volatile unsigned long*)(rfFlashAddress+4);
        //CPUartLogPrintf("[RF ] magic[%08x],rfFlashAddress=[%x],rfCopySize=[%x]\r\n"
        //            ,magic
        //            ,rfFlashAddress
        //            ,rfCopySize);
        rfBackupAddress = (UINT32)malloc(rfCopySize+8);
        //CPUartLogPrintf("[RF ] rfBackupAddress=[%x]\r\n"
        //            ,rfBackupAddress);

        memcpy( (void *)rfBackupAddress,(void *)(rfFlashAddress),rfCopySize+8);

    }else{
        magic                    =  *(volatile unsigned long*)(rfBackupAddress);
        rfCopySize               =  *(volatile unsigned long*)(rfBackupAddress+4);
        extern UINT32 dsp_dtcm_bk_addr;
        if(dsp_dtcm_bk_addr){
            #define LT_RF_LOAD_ADDR_A0_REDUCE_SULOG_BUF_V2 (0x7E000000)
            rfLoadAddress            = LT_RF_LOAD_ADDR_A0_REDUCE_SULOG_BUF_V2;
        }else{
            rfLoadAddress            = get_rf_load_addr();
        }
        

        //checkusm=fbf_checksum((unsigned char *)(rfBackupAddress+8),rfCopySize,0);
        //CPUartLogPrintf("[RF ] magic[%08x],rfBackupAddress=[%x],rfCopySize=[%x],rfLoadAddress[%x],checkusm[%x]\r\n"
        //            ,magic
        //            ,rfBackupAddress
        //            ,rfCopySize
        //            ,rfLoadAddress
        //            ,checkusm);

        
        memcpy( (void *)rfLoadAddress,(void *)(rfBackupAddress+8),rfCopySize);
        CacheCleanMemory((void *)rfLoadAddress, rfCopySize);
        
        free((void *)rfBackupAddress);
        rfBackupAddress = NULL;

    }

#else
#ifdef CRANE_MCU_DONGLE
    if(dsp_cpy_by_boot)
        return 0;
#endif

    //COPY rf.bin
	is_rf_on_internal_flash  = is_partition_internal_flash("rfbin");
	rfFlashAddress           = get_rf_start_address();
	rfCopySize               = get_rf_bin_size();
	rfLoadAddress            = get_rf_load_addr();

	uart_printf("[RF ] rfFlashAddress=[%s:%x],rfCopySize=[%x],rfLoadAddress=[%x]\r\n"
				,(is_rf_on_internal_flash?PTABLE_FLASH_INTERNAL:PTABLE_FLASH_EXTERNAL)
				,rfFlashAddress
				,rfCopySize
				,rfLoadAddress);

    if(rfLoadAddress == INVALID_ADDRESS)
    {
        uart_printf("[RF ] skip rf.bin load as rfLoadAddress = INVALID_ADDRESS\r\n");
        return 0;
    }
	else
	{
		if(is_rf_on_internal_flash)
		{
			spi_nor_do_read(rfFlashAddress,rfLoadAddress,rfCopySize, 1);
		}else{
	    	memcpy( (void *)rfLoadAddress,(void *)rfFlashAddress,rfCopySize);
		}
    }
#endif
    return 0;
}




void DSPPhase1Init()
{

#ifdef CRANE_MCU_DONGLE
#if ((defined(LTEONLY_THIN_SINGLE_SIM) && !defined(NOT_REDUCE_SULOG_DSP)) || defined(REDUCE_SULOG_IRBUF_DSP))
    copy_rf_from_flash_to_psram();
#endif


#if defined(NO_MUTI_LOADTABLE_SUPPORT)
	//load DSP.bin
	if(copy_dsp_from_flash_to_psram()){
		ASSERT(0);
	}

	//load RF.bin
	if(copy_rf_from_flash_to_psram()){
		ASSERT(0);
	}
#endif

#ifdef DSP_UNCOMPRESS_DEBUG
    extern unsigned int fbf_checksum(unsigned char * src, unsigned int len, unsigned int checksum);

    extern UINT32 Image$$DDR_DSP_RO$$Base;
    unsigned int checksum=0;
    unsigned int address=0;
    unsigned int expected_dsp_size=0;

    address                   = (UINT32)(&Image$$DDR_DSP_RO$$Base);
    expected_dsp_size         = get_dsp_copy_size();
    checksum = fbf_checksum((unsigned char *)address,expected_dsp_size,0);
    CPUartLogPrintf("[DSP] DSPPhase1Init checksum[0x%.08x]", checksum);
#endif

#endif

}

void MSAPhase1Init()
{
    CPUartLogPrintf("MSAPhase1Init");

#ifdef NEZHA3_1826
//	volatile UINT32* MSA_RESET_REG = (volatile UINT32*) 0xD02500C0;
    volatile UINT32* MSA_RESET_REG = (volatile UINT32*)0xD4050020; //qianying
#elif defined(EDEN_1928)
	volatile UINT32* MSA_RESET_REG = (volatile UINT32*) (CHIP_IS_EDEN_A0?0xD4050020:0xD02500C0);
#else
	volatile UINT32* MSA_RESET_REG = (volatile UINT32*)0xD4050020;
#endif

#if defined (EDEN_1928) || defined (NEZHA3_1826)
//	volatile UINT32* MSA_BOOT_REG  = (volatile UINT32*) 0xD0270000;
    volatile UINT32* MSA_BOOT_REG  = (volatile UINT32*) 0xD4070000; //qianying
#else
	volatile UINT32* MSA_BOOT_REG  = (volatile UINT32*) 0xD4070000;
#endif
	UINT32 *run_bin, *run_bin_dest;
	UINT32 i, dummy;

	MSAInit();

#if 0 //qianying
#ifdef EDEN_1928
	*(volatile UINT32 *)0xD4051088 = 0x83; //map 0xD2000000 to 0x06000000
#elif defined (NEZHA3_1826)
    *(volatile UINT32 *)0xD4051088 = 0x83; //make sure MSA uses 0xD3?????? to access physical 0x07??????
#else
	*(volatile UINT32 *)0xD4200200 = 0x07;
#endif
#endif

	/* reset MSA and baseband */
	dummy=*(MSA_RESET_REG);
	*(MSA_RESET_REG) |= 0x0c;
	for (i = 0; i < 0xffff; i++) ;

	/* set boot address */
	dummy=*(MSA_BOOT_REG);
#ifdef EDEN_1928
	*(MSA_BOOT_REG)=0xd3ffffc0;
#elif defined (NEZHA3_1826)
    *(MSA_BOOT_REG)=0xd3ffffc0; //qianying
#else
	*(MSA_BOOT_REG)=0xd0ffffc0;
#endif
}

#define PMUM_CPRR *(volatile UINT32*) 0xD4050020
#define CEVA_SYS_CTRL *(volatile UINT32*) 0xD4070030
#define CEVA_VECTOR *(volatile UINT32*) 0xD4070034
#define BIT_0 (1 << 0)
#define BIT_1 (1 << 1)
#define BIT_2 (1 << 2)
#define BIT_3 (1 << 3)
#define BIT_4 (1 << 4)
#define BIT_5 (1 << 5)
#define BIT_6 (1 << 6)
#define BIT_7 (1 << 7)
#define BIT_8 (1 << 8)
#define BIT_9 (1 << 9)
#define BIT_10 (1 << 10)
#define BIT_11 (1 << 11)
#define BIT_12 (1 << 12)
#define BIT_13 (1 << 13)
#define BIT_14 (1 << 14)
#define BIT_15 (1 << 15)
#define BIT_16 (1 << 16)
#define BIT_17 (1 << 17)
#define BIT_18 (1 << 18)
#define BIT_19 (1 << 19)
#define BIT_20 (1 << 20)
#define BIT_21 (1 << 21)
#define BIT_22 (1 << 22)
#define BIT_23 (1 << 23)
#define BIT_24 (1 << 24)
#define BIT_25 (1 << 25)
#define BIT_26 (1 << 26)
#define BIT_27 (1 << 27)
#define BIT_28 (1 << 28)
#define BIT_29 (1 << 29)
#define BIT_30 (1 << 30)
#define BIT_31 ((unsigned)1 << 31)

void set_dsp_d2_reset_address(void)
{
	CEVA_SYS_CTRL &= ~0x1;
}

//0x00052000-------DSP Reduce Sulog        Size[328KB] {328KB RAM             }, RF Address[0x7E010000]
//0x00070000-------DSP ALLIN               Size[448KB] {448KB RAM             }, CraneL RF Address[0x7E065000],craneLS and craneLR RF Address[0x7E045000]
UINT32 dsp_dtcm_bk_addr = 0;
void save_bx_Itcm_to_heap(void)
{
    UINT32 copy_len=0,addr=0;
    if(dsp_dtcm_bk_addr==0){
        return;

    }
    //CPUartLogPrintf("save_bx_Itcm_to_heap start[%08x]",dsp_dtcm_bk_addr);
    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
    {
        copy_len = 0x20000; //128K, BX2's ITCM
        addr = (UINT32)malloc(copy_len);
        memcpy((void*)addr,(void*)dsp_dtcm_bk_addr,copy_len);
        dsp_dtcm_bk_addr = addr;
    }
    //CPUartLogPrintf("save_bx_Itcm_to_heap end[%08x]",dsp_dtcm_bk_addr);
}

void release_bx_itcm_from_heap(void)
{
    if(dsp_dtcm_bk_addr){
        //CPUartLogPrintf("release_bx_itcm_from_heap[%08x]",dsp_dtcm_bk_addr);
        free((void*)dsp_dtcm_bk_addr);
        dsp_dtcm_bk_addr = 0;
    }
}

void boot_x1_external_from_squ_new(void)
{
    UINT32 code_addr, squ_addr,copy_len,i;
    UINT32 ptcm_addr = 0xF0200000;
    volatile UINT32 delay_counter;
    //UINT32 cpsr;
	//cpsr=disableInterrupts();
	if(dsp_dtcm_bk_addr){
        squ_addr = dsp_dtcm_bk_addr;
	}else{
        squ_addr = 0x7e000000;
	}

    
    if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
    {
        copy_len = 0x20000; //128K, BX2's ITCM
    }
    else
    {
#if (defined(ENABLE_CAT1_LG) || defined(DM_LTEONLY_CP_LTEGSM_DSP))
        copy_len = 0x20000; //128K
#elif defined(ENABLE_DM_LTEONLY)
        copy_len = 0x30000; //192K
#else
        copy_len = 0x40000; //256K
#endif
    }
    CEVA_SYS_CTRL |= 0x1; //boot from external
    CEVA_VECTOR = 0x10;   //external boot addr
    PMUM_CPRR |= (BIT_2 | BIT_3);

    PMUM_CPRR |= BIT_5;//DSRAMINT
    PMUM_CPRR &= ~(BIT_2 | BIT_3);

    CPUartLogPrintf("Copy X1 code to PTCM");

    //force delay for CEVA EDAP get ready
    for(delay_counter=0; delay_counter<100*100;delay_counter++){};

	if(!needToDump)
	{
        if (CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
        {
            for(i=0;i< copy_len/4;i++) {
               *(volatile UINT32*)(ptcm_addr+i*4) = *(volatile UINT32*)(squ_addr+i*4);
            }

            #if ((defined(LTEONLY_THIN_SINGLE_SIM) && !defined(NOT_REDUCE_SULOG_DSP)) || defined(REDUCE_SULOG_IRBUF_DSP))
                copy_rf_from_flash_to_psram();
            #endif

            release_bx_itcm_from_heap();

        }
        else
        {
    	for(i = 0; i < copy_len/16; i++)
    		{
    			BU_REG_WRITE(ptcm_addr+16*i+0,	BU_REG_READ(squ_addr+16*i+8));
    			BU_REG_WRITE(ptcm_addr+16*i+4,	BU_REG_READ(squ_addr+16*i+12));
    			BU_REG_WRITE(ptcm_addr+16*i+8,	BU_REG_READ(squ_addr+16*i+0));
    			BU_REG_WRITE(ptcm_addr+16*i+12, BU_REG_READ(squ_addr+16*i+4));
    		}
        }
        PMUM_CPRR &= ~BIT_5;
        CPUartLogPrintf("Release X1");
    }
}

void boot_x1_from_ptcm(void)
{
#if 1
    UINT32 code_addr, end, code_len, data_addr, data_len,i;
    UINT32 ptcm_addr = 0xF0200000;
    UINT32 dtcm_addr = 0xF0000000;
    int time_out = 1000;
    code_addr = 0xd1200000;
    //end = &x1_code_end;
    code_len = 0x20000;
   // data_addr = 0xd1220000;
    //end = &x1_data_end;
    //data_len = 0x20000;
    CEVA_SYS_CTRL &= ~0x1; //boot from internal
    PMUM_CPRR |= (BIT_2 | BIT_3);

    PMUM_CPRR |= BIT_5;  //DSRAMINT
    PMUM_CPRR &= ~(BIT_2 | BIT_3);

    CPUartLogPrintf("Copy X1 code to PTCM");

    for(i = 0; i < code_len/16; i++)
    {
        BU_REG_WRITE(ptcm_addr+16*i+0,  BU_REG_READ(code_addr+16*i+8));
        BU_REG_WRITE(ptcm_addr+16*i+4,  BU_REG_READ(code_addr+16*i+12));
        BU_REG_WRITE(ptcm_addr+16*i+8,  BU_REG_READ(code_addr+16*i+0));
        BU_REG_WRITE(ptcm_addr+16*i+12, BU_REG_READ(code_addr+16*i+4));
    }

   // uart_printf("Copy X1 Data to PTCM\n\r");
    //memcpy(dtcm_addr, data_addr, data_len);

    PMUM_CPRR &= ~BIT_5;
    CPUartLogPrintf("Release X1");
#endif
}

void boot_x1_from_ptcm_new(void)
{

    UINT32 code_addr, end, code_len, data_addr, data_len,i;
    UINT32 ptcm_addr = 0xF0200000;
    //UINT32 dtcm_addr = 0xF0000000;
    int time_out = 1000;
    code_addr = 0x7e700000;
    //end = &x1_code_end;
    code_len = 0x20000;
   // data_addr = 0xd1220000;
    //end = &x1_data_end;
    //data_len = 0x20000;
    CEVA_SYS_CTRL &= ~0x1; //boot from internal
    PMUM_CPRR |= (BIT_2 | BIT_3);

    PMUM_CPRR |= BIT_5;  //DSRAMINT
    PMUM_CPRR &= ~(BIT_2 | BIT_3);

    CPUartLogPrintf("Copy X1 code to PTCM");

    for(i = 0; i < code_len/16; i++)
    {
        BU_REG_WRITE(ptcm_addr+16*i+0,  BU_REG_READ(code_addr+16*i+8));
        BU_REG_WRITE(ptcm_addr+16*i+4,  BU_REG_READ(code_addr+16*i+12));
        BU_REG_WRITE(ptcm_addr+16*i+8,  BU_REG_READ(code_addr+16*i+0));
        BU_REG_WRITE(ptcm_addr+16*i+12, BU_REG_READ(code_addr+16*i+4));
    }

   // uart_printf("Copy X1 Data to PTCM\n\r");
    //memcpy(dtcm_addr, data_addr, data_len);

    PMUM_CPRR &= ~BIT_5;
    CPUartLogPrintf("Release X1 new");

}
#define hwAcs_IPC_CONTROL___WRITE(IPCCtrlReg,interrupt) \
(*((volatile UINT32 *)(IPCCtrlReg)) = (interrupt))

void MSAPhase2Init()
{
	hwAcs_IPC_CONTROL___WRITE(ACP_INT_CLR, CLR_ACP_GP_INT);

	boot_x1_external_from_squ_new();

	CPUartLogPrintf("MSA Phase2 Init");

	//MSA boot address after wakeup
}
#endif

#ifdef PHS_SW_DEMO_TTC
 extern void BBU_UART_Open(int baud);
 extern void BBU_putstr(char *str);
 extern void BBU_puthexd(UINT32);
 extern void initGPIO(void);
 extern void setGPIO81_HIGH(void);
 extern void setGPIO81_LOW(void);
 extern void setGPIO82_HIGH(void);
 extern void setGPIO82_LOW(void);

void BBULogPrintf(const char* fmt, ...)
{
	va_list ap;
	char buffer[128];
	UINT32 cpsr;

	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);


	cpsr = disableInterrupts();
	BBU_putstr(buffer);
	BBU_putstr("\n\r");
	restoreInterrupts(cpsr);
	/*The va_end has been called after calling va_start*/
	/*coverity[missing_va_end]*/
}
#endif

#ifndef PLAT_TEST
#include "tc_defs.h"
extern void* TCD_Current_Thread;
void debug_mme(void)
{
	BBULogPrintf(((TC_TCB *)TCD_Current_Thread)->tc_name);
	BBU_putstr("\n\r");
	BBU_puthexd(((TC_TCB *)TCD_Current_Thread)->tc_id);
	BBU_putstr("\n\r");
}
#endif

 void AIBAuxInit(void)
 {
	 volatile unsigned long val;

	 val = AIB_Secure_Read(0xd401e800); //AFE
	 val &= ~(0x3 << 6);
	 AIB_Secure_Write(0xd401e800, val);

	 val = AIB_Secure_Read(0xd401e804); //ANT
	 val &= ~(0x3 << 6);
	 AIB_Secure_Write(0xd401e804, val);

	 val = AIB_Secure_Read(0xd401e814); //GSM
	 val &= ~(0x3 << 6);
	 AIB_Secure_Write(0xd401e814, val);

	 val = AIB_Secure_Read(0xd401e830); //WB_IO
	 val &= ~(0x3 << 6);
	 AIB_Secure_Write(0xd401e830, val);
 }


 /******************************************************************************
 * Function     : Phase1Inits
 *******************************************************************************
 *
 * Description  :  Perform phase1 inits
 *                 Called from Application_Initialize only !!!
 *                Evaluates the HW initialization and database initialization of every package
 * 				  Note : at this stage the NUCLEUS is not running
 ******************************************************************************/
#ifdef PHS_SW_DEMO_TTC
UINT32 Reset_Status=0;
#endif
extern BOOL is_ram_fs;
static void LittleDelay(UINT32 num)
{
	while(num--)
	{;}
}

void SET_DCDC_EN_HIGH()
{
	/* GPIO112 as DCDC_EN */
	*(volatile UINT32 *)GPIO112_ADDERSS= (DRV_SLOW_C | RESERVED_C | AF0_C);

	GPIO_3_PDR() |= (1 << (112%32));
	LittleDelay(200);

	GPIO_3_PSR() |= (1 << (112%32));
}

static void setnandpinlow()
{
    #define ND_CS1 0xd401e048 /*86 f1*/
    #define SM_CS0 0xd401e04c /*87 f1*/
    #define SM_CS1 0xd401e050 /*88 f1*/

    #define SM_SCLK 0xd401e064 /*13 f3*/

    #define SM_BE0 0xd401e06c /*126 f0*/
    #define SM_BE1 0xd401e070 /*127 f0*/

    #define SM_ADV 0xd401e074 /*0 f1*/
    #define ND_RDY1 0xd401e078 /*1 f1*/
    #define SM_ADVMUX 0xd401e07c /*2 f1*/
    #define SM_RDY 0xd401e080 /*3 f1*/

    #define ND_IO15 0xd401e004 /*20 f1*/
    #define ND_IO14 0xd401e008 /*21 f1*/
    #define ND_IO13 0xd401e00c /*22 f1*/
    #define ND_IO12 0xd401e010 /*23 f1*/
    #define ND_IO11 0xd401e014 /*24 f1*/
    #define ND_IO10 0xd401e018 /*25 f1*/
    #define ND_IO9 0xd401e01c /*26 f1*/
    #define ND_IO8 0xd401e020 /*27 f1*/

    #define ND_IO7 0xd401e024 /*4 f2*/
	#define ND_IO6 0xd401e028 /*5 f2*/
	#define ND_IO5 0xd401e02c /*6 f2*/
	#define ND_IO4 0xd401e030 /*7 f2*/
	#define ND_IO3 0xd401e034 /*8 f2*/
	#define ND_IO2 0xd401e038 /*9 f2*/
	#define ND_IO1 0xd401e03c /*10 f2*/
	#define ND_IO0 0xd401e040 /*11 f2*/

	#define ND_CS0 0xd401e044 /*85 f1*/
	#define ND_WE 0xd401e054 /*89 f0*/
	#define ND_RE 0xd401e058 /*90 f0*/
	#define ND_CLE 0xd401e05c /*12 f3*/
	#define ND_ALE 0xd401e060 /*91 f0*/

	BU_REG_WRITE(ND_IO15, 0xb0c0);
	BU_REG_WRITE(ND_IO14, 0xb0c0);
	BU_REG_WRITE(ND_IO13, 0xb0c0);
	BU_REG_WRITE(ND_IO12, 0xb0c0);
	BU_REG_WRITE(ND_IO11, 0xb0c0);
	BU_REG_WRITE(ND_IO10, 0xb0c0);
	BU_REG_WRITE(ND_IO9, 0xb0c0);
	BU_REG_WRITE(ND_IO8, 0xb0c0);

	BU_REG_WRITE(ND_IO7, 0xb0c0);
	BU_REG_WRITE(ND_IO6, 0xb0c0);
	BU_REG_WRITE(ND_IO5, 0xb0c0);
	BU_REG_WRITE(ND_IO4, 0xb0c0);
	BU_REG_WRITE(ND_IO3, 0xb0c0);
	BU_REG_WRITE(ND_IO2, 0xb0c0);
	BU_REG_WRITE(ND_IO1, 0xb0c0);
	BU_REG_WRITE(ND_IO0, 0xb0c0);
}

static void Phase1Inits (void)
{
	BspCustomType customtype = bspGetBoardType();

    CPUartLogPrintf("Phase1Inits");

#ifdef CRANE_OTA_SD_SUPPORT
	//add for OTA_SD reset check
	OTA_SD_Reboot_Flag_Check();
#endif

#ifdef PHS_SW_DEMO_TTC
#ifndef EDEN_1928
	UINT32 Rstatus_temp=0;
	SET_DCDC_EN_HIGH();

	Reset_Status=(*(volatile UINT32 *)0xd4050028);
	Rstatus_temp=(Reset_Status&0xe00)>>9;

	if(Rstatus_temp>=7)
	{
		Rstatus_temp=0;
	}
	else
	{
		Rstatus_temp++;
	}

	*(volatile UINT32 *)0xd4050028=(Reset_Status&(~0xe00))|(Rstatus_temp<<9);
#endif
#endif


#ifdef GPIO_TRACE
#ifndef EDEN_1928
		initGPIO();
#endif
#endif

#if defined(__arm)
	 /* Ensure proper functionality of some C library functions */
    setlocale(LC_ALL, "C");
#endif

#if defined(IPC_ENABLED)
	IPCCreateEvent();
#endif

#if 0
    /* Initialzies the Power Management*/
	CPMUPhase1Init();
#endif


#if !defined(TTC_BSP_ARM946_CP15)
   /* all the modules that uses timers must be before the ipc init */
	RMPhase1Init();
    AAMPhase1Init();
#ifndef PHS_SW_DEMO_TTC_PM
	DVFMPhase1Init();
#endif
#endif

	INTCPhase1Init();            /* Initializes interrupt controller HW and database*/

   	timerPhase1Init();           /* Initializes timers controlller HW and database*/

#ifdef GPIO_TRACE
	GpioPhase1Init();
#endif

	/* IPC package : HW initialization and database initializatio */

#if defined(IPC_ENABLED)
	{
	    IPC_Config initialIPCConfig;
	    initialIPCConfig.msgWorkMode = IPC_WM_NOTIFICATION;

		IPCCommPhase1Init(&initialIPCConfig);
	}
#endif

#ifdef SPI_MUX
	SSPPhase1Init();
#endif
#if !defined(TTC_BSP_ARM946_CP15)

	if(AC_IS_CPONLY)
	{
        //SSPPhase1Init(); /* Initializes ssp package HW and database*/
        //set GSSP clk frm pin as slave input direction,then it will not affect AP I2S interface
#ifdef NEZHA3_1826
#if 0 //qianying
        *(volatile UINT32 *)0xd023b00c=0x1;
        *(volatile UINT32 *)0xd0239004=0x63001c01;
        *(volatile UINT32 *)0xd023b00c=0x0;
#endif
#else
        *(volatile UINT32 *)0xd403b00c=0x1;
        *(volatile UINT32 *)0xd4039004=0x63001c01;
        *(volatile UINT32 *)0xd403b00c=0x0;
#endif
    }
#endif//!TTC_BSP_ARM946_CP15

    //memPoolX_Init( DIAG_MEM_POOL_SIZE, NULL ); //"NULL" to allocate on heap
    SetDiagMemFns(alignMallocPoolX,alignFreePoolX);

	diagPhase1Init(); /* Initializes diag package HW and database*/

	if(AC_IS_CPONLY)
	{
		USBDevicePhase1Init();

#if defined(PHS_SW_DEMO_TTC) && !defined(CRANE_MCU_DONGLE)
	    USBMgrTnlPhase1Init (); /* init USB Mgr Tunnel Phase 1*/
#endif
	}

	crossPlatformSWPhase1Init();  /* Initializes cross Platform SW database*/

#ifdef NEZHA3_1826

    watchdogPhase1Init(); /* Initializes Watch Dog package HW and database*/
#endif

#if 1//!defined(TTC_BSP_ARM946_CP15)
	TickPhase1Init(); /*Add Tick Manager initialization */
#endif

#if defined(_USIM_ENABLED_)
   	USIMPhase1Init(); /* Initializes USIM package HW and database*/
#endif

#ifdef _RTC_ENABLED_
	RTCPhase1Init();
#endif

    if (PLATFORM_IS_ASIC)
    {
    	PMIC_Phase1Init();
        CpCoreFreqChangeTo624(); //624M by default to speed up booting process
        if (ifPsramLimit200M())
            psram_phy_fc_config(3); //PSRAM PHY@350
        else
            psram_phy_fc_config(4); //PSRAM PHY@416
		if(Is_silentReset())
		{
			CPUartLogPrintf("Bootup is silent");
		}
		else
		{
			CPUartLogPrintf("Bootup not silent");
		    simPin_invalidate(0);
			simPin_invalidate(1);
		}

		{
			extern void sim_pin_fota_restore(void);
			sim_pin_fota_restore();
		}

        pmic_set_sys_restart_reason();
    }
#ifndef REMOVE_MEP
	MEPPhase1Iinit();
    MEPPhase1Iinit_2();	
#endif
}

 /******************************************************************************
 * Function     : Phase2Inits
 *******************************************************************************
 *
 * Description  :  Perform phase2 inits
 *                 Including the OS object for every package
 *                 Called from the Init Task context
 ******************************************************************************/
#if QUEC_IMS_XML_SUPPORT 
 extern void quec_process_ims_xml(void);
#endif 
void Phase2Inits (void)
{
    CPUartLogPrintf("Chip ID: 0x%lx", GetLongChipID());

    if(IsMiniSystem())
    {
        setSacCcDisableCsCallFlag(TRUE);
        CPUartLogPrintf("******It is mini system******");
    }

    if(!needToDump)
    {
        DSPPhase1Init();
    }

	//config mpu for crane ds project

	crane_ds_mpu();

#ifdef OPENCPU_SUPPORT
	AppPhase1Init();
#endif

#if !defined(TTC_BSP_ARM946_CP15)
    //Remote file is not accessible.
    //Try to load permanent "PlatformNvm_ts* p_PlatformNvm" buffer from a given buffer
    //(it may be already corrected by file-server).
    //Update from real file later.
//    PlatformNvm_Init(NULL, (void*)(pLoadTable->sharedFreeBegin));

#ifndef PHS_SW_DEMO_TTC
    CommCCUPhase2Init();
    MCCUPhase2Init();
#endif //PHS_SW_DEMO_TTC

#ifdef PHS_SW_DEMO_TTC_PM
	RMPhase2Init();
#endif
#endif

	INTCPhase2Init();

	timerPhase2Init();

	InitTimers();    //Configure timers to have OS tick

	initTimerCount13MHz();//Configure 13MHz time counter with 32kHz and performance_count

#ifdef GPIO_TRACE
	GpioPhase2Init();
#endif
	qspi_dma_init();

#ifdef SPI_MUX
	SSPPhase2Init();
#endif

	ModemLwipPsDlInit();
	IpNetUpLinkInit();

	ModemTftAndVoLteInit();

	/* Add registration to the tick manager*/
	NUTickRegister();

	/* Configure  Timer for Tick Manager interrupts*/
	TickPhase2Init();

#ifndef PHS_SW_DEMO_TTC_PM
    DVFMPhase2Init();
#endif

    RIPCPhase2Init();
	/********************************
	quec_set_extflash_select_port功能描述
	此功能用于选择外挂flash 端口 
	0：SSP0使用GPIO16~19引脚
	1: SSP0使用GPIO33~36	  默认配置
	2: SSP2使用GPIO33~36
	3: SSP2使用GPIO12~15
	
	如果客户不使用外挂flash，此接口可以屏蔽
	**********************************/

#ifdef QUECTEL_OPEN_CPU 
#ifdef  QL_EXTFLASH
    extern void quec_set_extflash_select_port(int port);
	quec_set_extflash_select_port(1);
#endif
	
#endif

	FDI2FatSysInit();
	
#ifndef MIN_SYS
#ifdef QUECTEL_OPEN_CPU 
    extern void ql_app_start_prepare(void);
    if(!IsMiniSystem()){ /*此位置不可随意乱动*/
		ql_app_start_prepare();
    }
#endif
#endif

    /* Fitz.xu 20200723: add ims xml process here, 
       after FS initialized and before ims stack read xml from FS. 
     */
//#ifndef MIN_SYS	 
#if 0
if(!IsMiniSystem())
{	 
#if QUEC_IMS_XML_SUPPORT
    quec_process_ims_xml();
#endif
}
#endif
    PlatformCfgGetSetting();

#ifdef CRANE_OTA_SD_SUPPORT
	//If OTA_SD Reboot Success, Clear OTA_Flag
	OTA_SD_Flag_Reset();
#endif

#ifndef MIN_SYS
	if (!IsMiniSystem())
	{
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
		Quec_load_QuecCfg_SysPara();
#endif		
	}
#endif

    if (PLATFORM_IS_ASIC)
    {
    	PMIC_Phase2Init();
    }

#ifdef NEZHA3_1826
	watchdogPhase2Init();
#endif

#if defined(EE_HANDLER_ENABLE)
	 eeHandlerPhase2Init();  //read cnfg file.
#endif

#if defined(EE_HANDLER_ENABLE)
	 eeHandlerPhase3Init(); //read cnfg file.
#endif

#if defined(EE_HANDLER_ENABLE)
    eeWdtMgrInit();
#endif

  	crossPlatformSWPhase2Init();  /* Initializes cross Platform SW tasks*/

	crossPlatformSWPhase3Init();  /* opens NVM channel over GPC*/

	PlatformNvm_CreatePlatformNVMFile();

#ifdef PSM_ENABLE
	/* Psm low level driver initialization */
	psm_lowlevel_init();
#endif

    /* init dual sim type in early stage, PS will get dual sim type */
   	initDualSimType();
   	
//#ifndef LTEONLY_THIN	
	flush_cfun4_rsp_init();
//#endif	


#if defined(AT_OVER_UART) //&& (!defined(BT_SUPPORT))
#ifdef QUEC_STARTUP_OPTIMIZATION
	if(0x5a5a5a5a != gPowerupSaveTimeFlag)
	{
		bspUartPhase2Init();
	}
	else
	{
		extern UINT8 ciServerStubInit(void);
		bspUartPhase2Init();
		ciServerStubInit();
	}
#else
	bspUartPhase2Init();
#endif
#endif

#ifdef BT_SUPPORT
//Sharon.li@20230406 锟斤拷远锟斤拷锟诫不使锟矫此达拷
//    appbt_gpio_init();
#endif

    //enable at over uart to edge dect wake up
    INTCConfigure(INTC_SRC_ICU_RESERVED9, INTC_IRQ, INTC_HIGH_LEVEL);
#ifdef QUECTEL_OPEN_CPU
#ifndef MIN_SYS
 extern void GpioCommonWakeupCallback();
    if(!IsMiniSystem()){
        ASSERT(INTCBind(INTC_SRC_ICU_RESERVED9, (INTC_ISR)GpioCommonWakeupCallback) == INTC_RC_OK);
    }
    INTCEnable(INTC_SRC_ICU_RESERVED9);
#endif
#else
    ASSERT(INTCBind(INTC_SRC_ICU_RESERVED9, (INTC_ISR)PadEdgeDetectISR) == INTC_RC_OK);
#endif

#ifndef CRANE_SD_NOT_SUPPORT
    if(log_sdcard_partition_is_multi()){
		DUMP_VOL = "M:";
    }

	sdcard_init();
#endif

#ifdef CRANE_OTA_SD_SUPPORT
	//If execute OTA_SD API by user, comment out the following MACRO:EXECUTE_OTA_SD_IN_BOOTING_ALWAYS
	#ifdef EXECUTE_OTA_SD_IN_BOOTING_ALWAYS
		uart_printf("----------------------------------------\r\n");
		Update_OTA_Flag_And_Reboot();
		uart_printf("----------------------------------------\r\n");
	#endif
#endif

    ReliableDataPrePhase1();

#ifndef REMOVE_MEP
    MEPPhase2Iinit();
    MEPPhase2Iinit_2();
#endif

    ReliableDataPhase2();

#if ( defined ADD_TSENSOR_DEBUG )
	Create_Test_Tsensor_Task();
#endif	/* ADD_TSENSOR_DEBUG */


if (PMIC_IS_PM803() || PMIC_IS_PM803L())
{
	#ifndef LTEONLY_THIN
	#ifdef ASR_PLATFORM_CRANEM //sharon.li@20220412 只锟斤拷ASR 1603平台支锟斤拷PM803锟斤拷RF adc
		vbat_pm803_init();
	#endif
	#endif
	//Fias.fan@20220609 锟斤拷锟斤拷锟斤拷始锟斤拷ADC 锟斤拷锟絇M803 锟斤拷锟斤拷要锟斤拷应锟矫诧拷锟绞硷拷锟斤拷锟?
    if (IsChipCraneL() || IsChipCraneLS() || IsChipCraneLR()) {
		cranel_adc_init1();
		cranel_adc_init2();
	}

}


#ifndef MIN_SYS
#ifdef QUEC_USB_CDC_SUPPORT
	extern void quec_sulog_set_status(unsigned char value);
	extern unsigned char quec_sulog_get_status(void);
    if(!IsMiniSystem())
    quec_sulog_set_status(0);
#endif
#endif

    usb_device_init();

#ifndef MIN_SYS
	if(!IsMiniSystem())
	{
		#ifdef QUEC_USB_CDC_SUPPORT
	    	if(quec_sulog_get_status()==1)
		#elif defined(QUEC_AT_QCFG_USB_NEMA)
		    #define QUEC_NEMA_ENABLE (1)
		    extern int quec_get_usb_nema_ec20(void);
		    if (QUEC_NEMA_ENABLE != quec_get_usb_nema_ec20()) 
		#endif
        	SulogInit();
	}
#endif


#ifndef QUEC_CMUX_ENABLE
#ifdef CRANE_MODULE_SUPPORT
    /* Init Cmux service */
    cmux_init();
#endif
#endif

#if !defined(TTC_BSP_ARM946_CP15)
#ifdef _UART_ENABLED_
    bspUartPhase3Init(); /* update to platformNvm */
#endif
#endif //!defined(TTC_BSP_ARM946_CP15)

#if !defined(TTC_BSP_ARM946_CP15)
    PlatformNvm_Print();
#endif /*(TTC_BSP_ARM946_CP15)*/

	COMCfgPhase2Init(); /* Initializes the COM platfrom configuration information */

	//Note: In some cases COMCfgPhase2Init sets initState=BSP_INIT_PHASE2_PASSED. however, even if changed it is restored before returning.
	/*****Attention: All modules who needs COMCfg services must be initialized after this line*****/
#if defined(_USIM_ENABLED_)
	USIMResourceInit();
	USIMPhase2Init();
#endif

#if !defined(TTC_BSP_ARM946_CP15)
    initState = BSP_INIT_PHASE2_BASIC_PASSED;
#endif /*(TTC_BSP_ARM946_CP15)*/

#if defined (IPC_ENABLED)
	IPCCommPhase2Init();
    // Check ROM-Mask before the IPC init
    // since if mask is wrong the IPCCommPhase3Init() may never return
#endif

#ifdef PHS_SW_DEMO_TTC
	MSAPhase2Init();
#endif

    utilitiesPhase3Init();

#ifndef NO_AUDIO
	//Enable Wujing audio,2012-0612
    audioServerPhase2Init();
#endif

    rti_rt_init();

    PP_init();

    lwip_init_all();
	
	//Fitz.xu 20211019: For DSDS, set sim2 ims cid to 4.
#ifdef VOLTE_ENABLE	
#if QUEC_DUAL_SIM_SUPPORT
	if ((getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY) || (getDualSimType() == CM_DUAL_SIM_DUAL_STANDBY_FP))
	{
		ims_set_cid(CM_SIM_0, 4);
	}
#endif
#endif

#ifdef VOLTE_ENABLE
    ims_rtos_init();
#endif

#ifdef AGPS_ENABLE
    agps_main();
#endif

    //asrbt_main();

    //keypad_init();

    INTCEnable(INTC_SRC_PMIC); //moved from PMIC_Phase2Init()
#ifdef WIFI_FUNCTION_SUPPORT
	initWiFiMACAddr();
	sdio_init(2, 83, 34, -1, -1, 1);
#endif
#ifdef SPINAND_SUPPORT
	FAT_FatSysInit();
#endif

#ifndef MIN_SYS
	if (!IsMiniSystem()) 
	{//MiniSystem
		#ifdef QUECTEL_PROJECT_CUST
		do
		{
			extern OSA_STATUS quecMain(void * argv);
			quecMain(NULL);
		}while(0);
		#endif
	}//MiniSystem
	else
	{
		quec_minisys_hal_init();
	}
#endif /*MIN_SYS*/

    initState = BSP_INIT_PHASE2_PASSED;


} /* Phase2Inits */



void platformemptyTask_0(void)
{

}
void platformemptyTask_1(void)
{

}
void platformemptyTask_2(void)
{

}


#if defined (SSP_USE_FOR_ASSERT)
// Function: ssp_enable
// ICAT EXPORTED FUNCTION - SW_PLAT, tavor, ssp_enable
void ssp_enable (void *p)
{
	SSP_ReturnCode	rc;
  UINT32 cspr;

	//UINT16 _diag_rx_data_buffer_dummy;
	static  UINT32	_diag_rx_data_buffer_dummy[10];
#error  Wrong using of the HARBELL_DDR_BASE_ADDR
	volatile int* msgPtr = ;;;error;; 0xd0800000   =HARBELL_DDR_BASE_ADDR
	UINT32 msgLength = 4;

	diagDisconnectIcat(); // use different way, data-struct not avaiable //diagBlocked.flags.icatNotReady = 1; // disable diag
	cspr = disableInterrupts();

	SSPWriteThroughData(1,(UINT8 *)msgPtr, msgLength);

	restoreInterrupts(cspr);
//	rc = SSPElementsSend(SSP_PORT_1,(void *)_diag_rx_data_buffer_dummy, (void *)msgPtr, msgLength);
//	ASSERT(rc == SSP_RC_OK)
}

// Function: diag_enable
// ICAT EXPORTED FUNCTION - SW_PLAT, tavor, diag_enable
void diag_enable (void *p)
{
	//SSP_ReturnCode	rc;
	//UINT16 _diag_rx_data_buffer_dummy;
	//static  UINT32	_diag_rx_data_buffer_dummy[10];
	//UINT8 *msgPtr = *(volatile int*)0xd0800000;
	//UINT32 msgLength = 4;

	//use different way (diagBlocked.flags.icatNotReady = 0;) // disable diag
	//SSPWriteThroughData((UINT8)msgPtr, msgLength);
//	rc = SSPElementsSend(SSP_PORT_1,(void *)_diag_rx_data_buffer_dummy, (void *)msgPtr, msgLength);
//	ASSERT(rc == SSP_RC_OK)
}


// Function: diag_enable
// ICAT EXPORTED FUNCTION - SW_PLAT, tavor, wr_string
void write_string (void *p)
{
	//SSP_ReturnCode	rc;
	//UINT16 _diag_rx_data_buffer_dummy;
	//static  UINT32	_diag_rx_data_buffer_dummy[10];
	//UINT8 *msgPtr = *(volatile int*)0xd0800000;
	//UINT32 msgLength = 4;
	SSPDebugWriteString("SASHA_RIVMAN");

	//SSPWriteThroughData((UINT8)msgPtr, msgLength);
//	rc = SSPElementsSend(SSP_PORT_1,(void *)_diag_rx_data_buffer_dummy, (void *)msgPtr, msgLength);
//	ASSERT(rc == SSP_RC_OK)
}
#endif


// ICAT EXPORTED FUNCTION - SW_PLAT, tavor, Config_RF_CONT_MUX
void Config_RF_CONT_MUX (void *p)
{
	RF_CONT_MUX_REG = *(UINT32*)p;
}
#ifdef _RTC_ENABLED_
// Currently RTC back register is used
#define RR_RTC_BACKUP_REG_N RTC_BACKUP_REG_0
#define RR_RTC_BITS_MASK  ((UINT32)0xff)
#endif

void bspSwResetReasonSet(UINT8 rr)
{
#if 0
#ifdef _RTC_ENABLED_
   UINT32 sx=disableInterrupts();
   UINT32 value;
   RTCBackupRegisterRead(RR_RTC_BACKUP_REG_N,&value);
   value=(value&~RR_RTC_BITS_MASK)|rr;
   RTCBackupRegisterWrite(RR_RTC_BACKUP_REG_N,value);
   restoreInterrupts(sx);
#else
   //nothing
#endif
#endif
}

#if (defined LOCAL_NVM)     //  This is true for NVMORAM and for TTC.
#define     _BSP_FLASH_C_
#include "bsp_flash.h"
/*elevy- this function will return the virtual base address of OneNAND CS*/
int getOnenandBaseAddress(void)
{
    return 0 ;          //  Dummy address for NVMORAM, need it to pass link.
}
#endif
//ICAT EXPORTED FUNCTION - SW_PLAT,NVM,platNvmPmuFlagRead
void platNvmPmuFlagRead(void)
{
    FILE_ID         fd;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb");
    if (fd != 0)
    {
        FDI_fseek(fd, sizeof(NVM_Header_ts), SEEK_SET);

        /* read structure */
        FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        if (PlatformCfg.HslCfg.PMCfgVal == _PM_ENABLE)
        {
            DIAG_FILTER(SW_PLAT, NVM, platNvmPmuFlagRead1, DIAG_INFORMATION)
            diagPrintf("Current PMCfgVal flag: _PM_ENABLE");
        }
        else
        {
            DIAG_FILTER(SW_PLAT, NVM, platNvmPmuFlagRead2, DIAG_INFORMATION)
            diagPrintf("Current PMCfgVal flag: _PM_DISABLE");
        }

        /* close file */
        FDI_fclose(fd);
    }
}

//ICAT EXPORTED FUNCTION - SW_PLAT,NVM,platNvmPmuEnable
void platNvmPmuEnable(void)
{
    FILE_ID         fd;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb+");
    if (fd != 0)
    {
       FDI_fseek(fd, sizeof(NVM_Header_ts), SEEK_SET);

       /* read structure */
       FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

       PlatformCfg.HslCfg.PMCfgVal   = _PM_ENABLE;
       PlatformCfg.HslCfg.VCXOCfgVal = VCXO_SD_ENABLE;

       FDI_fseek(fd, sizeof(NVM_Header_ts), SEEK_SET);
       FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

       /* close file */
       FDI_fclose(fd);

       DIAG_FILTER(SW_PLAT, NVM, platNvmPmuEnable, DIAG_INFORMATION)
       diagPrintf("PMCfgVal is set as _PM_ENABLE");
    }
}

//ICAT EXPORTED FUNCTION - SW_PLAT,NVM,platNvmPmuDisable
void platNvmPmuDisable(void)
{
    FILE_ID         fd;
    HSLCfgDataS     HSL_temp;

    fd = FDI_fopen(PLATFORM_CFG_FILE, "rb+");
    if (fd != 0)
    {
        FDI_fseek(fd, sizeof(NVM_Header_ts), SEEK_SET);
        /* read structure */
        FDI_fread((void *)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        PlatformCfg.HslCfg.PMCfgVal   = _PM_DISABLE;
        PlatformCfg.HslCfg.VCXOCfgVal = VCXO_SD_DISABLE;

        FDI_fseek(fd, sizeof(NVM_Header_ts), SEEK_SET);
        FDI_fwrite((void*)(&PlatformCfg), sizeof(PlatformCfgDataS), 1, fd);

        /* close file */
        FDI_fclose(fd);

        DIAG_FILTER(SW_PLAT, NVM, platNvmPmuDisable, DIAG_INFORMATION)
        diagPrintf("PMCfgVal is set as _PM_DISABLE");
    }
}

BOOL DDRFrequencyIDCreate(UINT32 *Freq_Id)
{
	return TRUE;
}

void DDRFrequencyChangeRequest(UINT32 Freq_Id, DDR_FREQUENCY_LEVEL frequency)
{
}

void setStatisticValueInAcStatOptionNvm(int statisicEnableValue)
{
}


unsigned int nvm_rfs_sync_status(void)
{
	return 0;
}

BOOL IsMiniSystem(void)
{
#if (defined(CRANE_MCU_DONGLE)&&(!defined(REMOVE_FOTA)))
    if(mini_sys_enable==MINI_SYS_STATUS_NONE){
        struct fota_param param;
        unsigned int address=get_fota_param_start_address();
        unsigned int    end=get_fota_param_end_address();
        if(address<end && (end-address)>=3*FLASH_4K_SECTOR){
            memcpy(&param,(const void *)address,sizeof(struct fota_param));
            if(param.mini_sys_enable==MINI_SYS_STATUS_ENABLE){
                mini_sys_enable = MINI_SYS_STATUS_ENABLE;
            }else{
                mini_sys_enable = MINI_SYS_STATUS_DISABLE;
            }
        }else{
            mini_sys_enable = MINI_SYS_STATUS_DISABLE;
        }
    }

    return mini_sys_enable==MINI_SYS_STATUS_ENABLE? TRUE:FALSE;
#else
    return FALSE;
#endif
}


BOOL IsLTEOnly_XIP(void)
{
#ifdef CRANE_MCU_DONGLE

#if defined(LTEONLY_8M8M) || defined(CRANEL_4MRAM)
    return TRUE;
#else
    return FALSE;
#endif

#else
    return FALSE;
#endif
}
#ifdef QUECTEL_PROJECT_CUST
char IsFullfota_app(void)
{
    char header[9] = {0};
    unsigned int address=get_fota_param_start_address();
    memcpy(header, (const void *)address, 8);
    if(memcmp((const void *)header, "FULLOTA1", 8) == 0)
        return 1;
    else if(memcmp((const void *)header, "FULLOTA2", 8) == 0)
        return 2;
    else
        return 0;
}
#endif
#ifdef MBIM_FUNCTION
UINT8 IsMbimEnabled(void)
{
    Usb_DriverS * pCfg = GetUsbDriverConfig();

    if ((pCfg->usb_driver < USB_MBIM_MAX_DRIVER)&&
        (pCfg->usb_driver >= USB_MBIM_ONLY_DRIVER))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif

/*the offset value is SQU offset on crane,PS side use this interface*/
unsigned long PsShareMemoryOffset(void)
{
    unsigned int offset=0;
    if(CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR){
        offset = 0x5000;
    }else{
        offset = 0x8000;
    }
    CPUartLogPrintf("%s, value[%08x]\r\n",__func__,offset);
    return offset;
}

#ifdef QUECTEL_PROJECT_CUST
#include "quec_gpio.h"

/* Get Array Size */
#define QUEC_ARR_SIZE(a)         	( sizeof(a) / sizeof(a[0]) )
/* Bit Mask Operation */
#define BIT_MASK(bit)      			(1 << (bit))
#define BIT_CLR(x,bit)     			((x) &= ~ BIT_MASK (bit))
#define BIT_SET(x,bit)     			((x) |= BIT_MASK (bit))
#define CHECK_BIT_SET(x,bit)  		((x) & BIT_MASK (bit))

/*===========================================================================
 * Global Variable
 ===========================================================================*/

//set gpio level
QuecOSStatus quec_minisys_set_gpio_level(GPIO_PinNumbers pin_num, quec_pin_level_value_e pin_level)
{
	GPIO_ReturnCode status = GPIORC_OK;
	status = GpioSetLevel(pin_num, pin_level);
	if(status != GPIORC_OK)
	{
		CPUartLogPrintf("port handle invalid or pin_num=%d m pin_level=%d, error=%d", pin_num, pin_level, status);
		return kParamErr;
	}
	return QUEC_SUCCESS;
}

//jensen.fang 20181103: to init STATUS gpio to indicate power state
QuecOSStatus quec_minisys_gpio_power_status_init(void)
{
	if (QUEC_SUCCESS != quec_minisys_set_gpio_level(QUEC_POWER_STATUS_PIN, QUEC_PIN_LEVEL_HIGH))
	{
		CPUartLogPrintf("error: set STATUS gpio to high level failed!");
		return kGeneralErr;
	}
	return QUEC_SUCCESS;
}


int quec_minisys_gpio_cust_init(void)
{
	QuecOSStatus err = kNoErr;
	
	err = quec_gpio_cust_config();
	if(err != QUEC_SUCCESS)
	{
		CPUartLogPrintf("error: quec_minisys_gpio_cust_config gpio fail!");
		return kGeneralErr;		
	}

	err = quec_minisys_gpio_power_status_init();
	if(err != QUEC_SUCCESS)
	{
		CPUartLogPrintf("error: quec_minisys_gpio_power_status_init gpio fail!");
		return kGeneralErr;		
	}

exit:
	return err;

}

int quec_minisys_hal_init(void)
{
	QuecOSStatus err = kNoErr;
	quec_minisys_gpio_cust_init();

	return kGeneralErr;
}
void quec_minisys_netmode_led(int level)
{
	quec_minisys_set_gpio_level(QUEC_NET_MODE_GPIO, level);
   
}

void quec_minisys_netsta_led(int level)
{
	quec_minisys_set_gpio_level(QUEC_NET_STATUS_GPIO, level);

}

#endif

//START 2022.03.29 update baseline , value of the DRO that you read exceeds the definition of the DRO, resulting in power-off
extern void PMIC_WRITE_REG_POWER(UINT8 addr, UINT8 value);
extern UINT8 PMIC_READ_REG_POWER(UINT8 addr);
extern unsigned char CRN_SVC_FP[];
extern unsigned char SVC_LVL_TBL_CRNM[NUM_PROFILES_CRNGM][NUM_SVC_LVL_CRNGM];
extern unsigned char SVC_LVL_TBL_CRNG[NUM_PROFILES_CRNGM][NUM_SVC_LVL_CRNGM];

#define USE_DEF_SVC    255

const unsigned char SVC_LVL_TBL_CRNM_DEFAULT[NUM_SVC_LVL_CRNGM] = 
{
    VOLTAGE_0_90,
    VOLTAGE_0_90,
    VOLTAGE_0_95,
    VOLTAGE_1_00
};

const unsigned char SVC_LVL_TBL_CRNG_DEFAULT[NUM_SVC_LVL_CRNGM] = 
{
    VOLTAGE_0_825,
    VOLTAGE_0_8375,
    VOLTAGE_0_85,
    VOLTAGE_0_95
};

unsigned int get_dro(void)
{
	unsigned int val, svt_cyc, svt_dro;
    UINT8 bkp;

    bkp = PMIC_READ_REG_POWER(0x21);
    PMIC_WRITE_REG_POWER(0x21, bkp&~(0x1<<7)); //Disable PMIC DVC to ensure buck1 change.
	//Set core voltage
	PlatformVcoreConfigForDro(); //get DRO under different core voltage

	//Enable DRO clock
	*((volatile unsigned int *)REG_APBC_APBC_DRO_CLK_RST)=0x5;
	*((volatile unsigned int *)REG_APBC_APBC_DRO_CLK_RST)=0x1;

	//Enable DRO
	*((volatile unsigned int *)REG_DRO_CONTROLIS_DRO_CNT_TIME) = 0x1FFF;
	*((volatile unsigned int *)REG_DRO_CONTROLIS_DRO_CTRL) = 0x3;

	//Wait for dro timer done
	do{
		val=*((volatile unsigned int *)REG_DRO_CONTROLIS_DRO_CNT_TIME);
	}while((val & 0x80000000)!=(0x80000000) /*(val&1<<31)!=(1<<31)*/);
	*((volatile unsigned int *)REG_DRO_CONTROLIS_DRO_CTRL) = 0x2;

	//Get svt cycle number
	svt_cyc = *((volatile unsigned int *)REG_DRO_CONTROLIS_DRO_SVT);
	svt_cyc = (((svt_cyc>>16)&0xffff) + (svt_cyc&0xffff))/2;

	//Calculate dro instric freq
    svt_dro = (int)(svt_cyc/315);
	CPUartLogPrintf("SVT %d",svt_dro);

    PMIC_WRITE_REG_POWER(0x21, bkp); //Restore register content.

    return svt_dro;
}

int get_prf_num_by_dro_crangm(unsigned int dro)
{
    int prf_num = -1;
    int max = 0;
    int min = 0;

    if (CHIP_IS_CRANEG)
    {
        max = 121;
        min = 82;
    }
    else if(CHIP_IS_CRANEM)
    {
        max = 153;
        min = 114;
    }
	if (dro < min)
	{
        CPUartLogPrintf("DRO=%d vs typical[%d~%d], use default SVC item.", dro,min,max);
        return USE_DEF_SVC;
	}
	if (dro > max)  dro = max;

    /* profile num 0~3, vs DRO 82(114)~121(163), 10 as stepping */
	prf_num = NUM_PROFILES_CRNGM -1 - (dro - min)/10;

	CPUartLogPrintf("profile num = %d", prf_num);
    return prf_num;
}

void Get_Svc_Level_Values(void)
{
    unsigned int i, dro = get_dro();
    int profile; 

    profile = get_prf_num_by_dro_crangm(dro);

    for (i = 0; i < NUM_SVC_LVL_CRNGM; i++)
    {
        if (profile == USE_DEF_SVC)
            CRN_SVC_FP[i] = (CHIP_IS_CRANEG)?SVC_LVL_TBL_CRNG_DEFAULT[i]:SVC_LVL_TBL_CRNM_DEFAULT[i];
        else
            CRN_SVC_FP[i] = (CHIP_IS_CRANEG)?SVC_LVL_TBL_CRNG[profile][i]:SVC_LVL_TBL_CRNM[profile][i];

        CPUartLogPrintf("CRN_SVC_FP[%d] = 0x%x", i, CRN_SVC_FP[i]);
    }
}

//END 2022.03.29 update baseline , value of the DRO that you read exceeds the definition of the DRO, resulting in power-off


