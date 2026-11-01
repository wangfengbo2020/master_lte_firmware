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

#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                main.h


GENERAL DESCRIPTION

    This file is for main.c.

EXTERNALIZED FUNCTIONS

INITIALIZATION AND SEQUENCING REQUIREMENTS

   Copyright (c) 2011 by Marvell, Incorporated.  All Rights Reserved.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when         who        what, where, why
--------   ------     ----------------------------------------------------------
05/07/2020   leafmoon    Created module
===========================================================================*/


/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include "osa.h"
#include "platform.h"
#include "iml_nvm.h"
#include "diag_nvm.h"
//#include "lfs_cache.h"
#include "utilities.h"
#include "FreqChange.h"
#include "EEHandler_nvm.h"

/*===========================================================================

                                LOCAL MACRO
===========================================================================*/

/* Size of system memory pool */
#define SYSTEM_MEMORY_SIZE		25000

/* Size of the init task stack */
#define INIT_STACK_SIZE			0x2000

/* priority of the init task */
#define INIT_TASK_PRIORITY		220

/* Platform Cfg file name */
#define PLATFORM_CFG_FILE	    "PlatformCfg.nvm"

/* Platform Cfg guard */
#define PLATFORM_CFG_GUARD      0x47464350
/*

* Defines of workaround for solving Timer GPB collision problem : Controls the number of write retries
* to the GPB (when busy) -currently endless , and the number of cycles between them -15
* NEED  TO BE CONSIDERED BT SYSTEM!!!!

*/
#define PBRCR_ADDRESS				0xFFD07000UL
#define RF_CONT_MUX_ADDRESS			0xD4000D20UL

#define PBRCR_REG					(*((volatile UINT32*) PBRCR_ADDRESS))
#define RF_CONT_MUX_REG				(*((volatile UINT32*) RF_CONT_MUX_ADDRESS))

/*===========================================================================

                          Struct definition.

===========================================================================*/

//ICAT EXPORTED ENUM
typedef enum {
	SULOG_OFF = 0,
	SULOG_ENABLE_HW_SW,
	SULOG_ENABLE_HW,
	SULOG_ENABLE_SW,
} SULOG_TYPE_ID;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32 value32[2];
} LteSulogCfgS;

//ICAT EXPORTED STRUCT
typedef struct
{
	SULOG_TYPE_ID logSwitch;
	LteSulogCfgS PrintLevel;
	UINT8 Sulog2SdCardFlag;
	UINT8 reserved[3];
}SULOG_ST;

//ICAT EXPORTED STRUCT
typedef struct
{
	SULOG_TYPE_ID logSwitch;
	LteSulogCfgS PrintLevelForSdCardDisable;
	LteSulogCfgS PrintLevelForSdCardEnable;
	UINT8 Sulog2SdCardFlag;
}SulogCfgDataS;

//ICAT EXPORTED ENUM
typedef enum {
	HSL_DISABLE = 0,
	HSL_BIGBOARD_ENABLE,
	HSL_MINIBOARD_ENABLE,
} HSL_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	_PM_DISABLE = 0,
	_PM_ENABLE,
} PM_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	VCXO_SD_DISABLE = 0,
	VCXO_SD_ENABLE,
} VCXO_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	SD_LOG_DISABLE = 0,
	SD_LOG_ENABLE,
} SDLOG_TYPE;

/* CQ0003TTTT - begin */
//ICAT EXPORTED ENUM
typedef enum {
	_L1_ACAT_LOG_DISABLE = 0,
	_L1_ACAT_LOG_ENABLE,
} L1AcatLog_TYPE;
/* CQ0003TTTT - end */

//ICAT EXPORTED ENUM
typedef enum {
	L1_IML2DDR_DISABLE = 0,
	L1_IML2DDR_ENABLE,
} L1IML2DDR_TYPE;

#ifdef SS_IPC_SUPPORT
//ICAT EXPORTED ENUM
typedef enum {
	DIP_DISABLE = 0,
	DIP_ENABLE_MANUAL_MODE_FOR_SPECIAL_USE,
	DIP_ENABLE_MANUAL_MODE_FOR_USER_MODEL,
	DIP_ENABLE_AUTO_MODE_FOR_END_USER,
} DIPOPTION_TYPE;
#endif

//ICAT EXPORTED STRUCT
typedef struct {
	PM_TYPE        PMCfgVal;
	HWDFC_TYPE     HWDFCCfgVal;
	HWDFC_TEST_TYPE HWDFCTestCfgVal;
	VCXO_TYPE      VCXOCfgVal;
	SDLOG_TYPE     SDLogCfgVal;
	L1AcatLog_TYPE L1AcatLogVal; /* CQ0003TTTT */
	#ifdef SS_IPC_SUPPORT
	DIPOPTION_TYPE dipEnable;
	#endif
	IMLCfgDataS IMLCfgdata;
} HSLCfgDataS;


//ICAT EXPORTED ENUM
typedef enum {
	_CPU_USAGE_DUMP_DISABLE = 0,
	_CPU_USAGE_DUMP_ENABLE
} CPUUSAGEDUMP_TYPE;


//ICAT EXPORTED STRUCT
typedef struct {
	CPUUSAGEDUMP_TYPE cpuUsageDumpEnable;
	UINT32 dumpInterval;
} SYSDBGCfgDataS;

//ICAT EXPORTED ENUM
typedef enum {
	APT_DISABLE = 0,
	APT_ENABLE,
} APT_TYPE;

//ICAT EXPORTED STRUCT
typedef struct {
	UINT8 ucVcxoStableTime;
	UINT8 ucPllStableTime;
	UINT8 ucClkGenTime;
	UINT8 ucDualCarrierFlag;
	UINT8 ucDualAntFlag;
	APT_TYPE AptFlag;
} MSACfgDataS;

//ICAT EXPORTED STRUCT
typedef struct {
	MSACfgDataS MsaCfg;
	HSLCfgDataS HslCfg;
	SYSDBGCfgDataS SysDbgCfg;
	Log_ConfigS LogCfg;
	Usb_DriverS usbDrvCfg;
	LTE_CONFIG_S LteCfg;
	Ymodem_Dump_type YmodemCfg;
	SulogCfgDataS SulogCfg;
	RTICfg_t rtiConfig;
	uartCfgDataS uartCfg;
	EE_Configuration_t eeCfg;
	diagCfgDataS diagCfg;
	UINT32 TailGuard;
} PlatformCfgDataS;


/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/

extern void diagPhase1Init(void);
extern void diagPhase2Init(void);
extern BOOL diagReadFilterFile( void );
extern void Phase2Inits (void);
extern BOOL isLPMEnabled(void);
extern void DbgInitFifo(void);
extern void DbgInitUart(UINT32 fifoEn);
extern UINT32 DbgGetType(void);
extern void RMPhase1Init(void);
extern void RMPhase2Init(void);
extern void PP_init(void);
#ifdef VOLTE_ENABLE
extern void ims_rtos_init(void);
#endif

#ifndef SS_FEATURE
extern void lwip_init_all(void);
extern int streamingmedia_init(void);
#endif
extern void mslPhase1Init(void);
extern void mslPhase2Init(void);
extern void DynamicMemoryInit(void);
extern void TransferControl(unsigned int);
//Temp fix, mjkim
extern void  BBU_putstr(char *str);
extern void BBU_UART_Open(int baud);
extern void InitTimers(void);
extern int sdcard_init(void);
extern void asm_NUSetSystemStackPtr(void);
extern BOOL DspRomFwMaskNameOK(void);
extern void bspXDAEnable(void);
extern void IPNetShmInit(void);
extern BOOL CPACheckNeedSendIPCDirectly(void);
extern void CPASendDspLogSettingToDSP(void);
extern BOOL sacDevSetDipOption(UINT8 dipOption);
extern void ACIPCDPSDPhase2Init( void );  //PS_PATH_V1
extern void PMIC_Phase1Init(void);
extern void PMIC_Phase2Init(void);
extern void Phase1Inits (void);
extern void SSPTestIcatMain(void);
extern void cmux_init(void);
extern void keypad_init(void);
extern void InitTask(VOID *argv);
extern void PadEdgeDetectISR(void);
extern void USIMResourceInit(void);
extern void platform_type_init(void);
extern void PlatformGetConstData(void);
extern int NVM_RAM_fileinit(void);
extern void USBMgrPhase1Init(void);
extern void hsi_gpio_init(void);
extern void RIPCPhase1Init( void );
extern void log_set_module_level(const char* module, int level);
extern const char* bspGetAcLinkName(void);
extern void ACIShmChannelInit(void);
extern void TestPortInit(void);
extern void RIPCPhase2Init(void);
extern OSA_STATUS FDI2FatSysInit(void);
extern void bootup_gpio_ind(void);
extern void PlatformNvm_CreateCOMCfgFile(void);
extern void PlatformNvm_CreatePlatformNVMFile(void);
extern void AcIPCDStatInit(void);
extern void audioServerPhase2Init(void);
extern void PlatformCfgGetSetting(void);
extern void rti_rt_init(void);
extern void SulogInit(void);
extern void asrbt_main(void);
extern void IpNetUpLinkInit(void);
extern void uartCfgDevInit(void);
extern int qspi_dma_init(void);
extern void psm_lowlevel_init(void);
extern void assert_cnt_flag_init(void);
extern void initTimerCount13MHz(void);
extern void ModemLwipPsDlInit(void);
extern void ModemTftAndVoLteInit(void);
extern UINT8 SysRestartReasonGet(void);
extern int getYmodemConfig(void);
extern void setYmodemdumpflag(int flag);
extern BOOL PMIC_IS_PM803(void);
extern UINT8 isSysRestartByRdProduction(void);
extern void CPASendSulogConfigToDSP(SULOG_ST SulogSet);
extern void SysRestartReasonGetGlobal(void);
extern UINT8 PM812_GET_POWER_UP_REASON(void);;
extern UINT32 log_sdcard_partition_is_multi(void);
extern UINT32 AIB_Secure_Read(unsigned int address);
extern void ReliableDataPrePhase1 (void);
extern OSA_STATUS FAT_FatSysInit(void);
extern void pmic_set_sys_restart_reason(void);
extern void setSacCcDisableCsCallFlag( BOOL flag );
#ifdef NEZHA3_1826
extern unsigned char Is_Nezha3Stepping_FromZ3(void);
#endif
#ifdef WIFI_FUNCTION_SUPPORT
extern void initWiFiMACAddr(void);
#endif
extern int initDualSimType(void);
#ifdef CTCC_DM_ENABLE
extern void telecom_init(void);
#endif
#ifdef CTCC_DM_SMS_ENABLE
extern void telecom_SMS_init(void);
#endif
#ifdef CRANE_OTA_SD_SUPPORT
//Check is OTA_SD Reboot System
extern void OTA_SD_Reboot_Flag_Check(void);
extern void OTA_SD_Flag_Reset(void);
#define EXECUTE_OTA_SD_IN_BOOTING_ALWAYS
#ifdef EXECUTE_OTA_SD_IN_BOOTING_ALWAYS
extern void Update_OTA_Flag_And_Reboot(void);
#endif
#endif
extern void AIB_Secure_Write(unsigned int address, unsigned int value);
extern unsigned int spi_nor_do_read(unsigned int addr, unsigned int buf_addr, unsigned int size, BOOL flashType);
extern int sw_jtag_cmd(unsigned long address, int addr_len, unsigned int *data,	int len, unsigned int *read_array);
extern int lzop_decompress_safe(unsigned char *src,  unsigned char *dest, unsigned int *dest_len, unsigned int *cpz_src_len);
extern unsigned long PsShareMemoryOffset(void);

#endif // MAIN_HEADER_H
