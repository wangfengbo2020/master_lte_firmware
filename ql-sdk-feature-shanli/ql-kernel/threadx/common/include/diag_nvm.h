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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 *     File name:      diag_nvm.c                                                  *
 *     Programmer:     Anton Eidelman                                              *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 *       Create Date:  February, 2004                                              *
 *                                                                                 *
 *       Description: DIAG NVM CONFIGURATION DEFINITIONS                           *
 *                                                                                 *
 *       Notes:                                                                    *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined (_DIAG_NVM_H_)
#define _DIAG_NVM_H_

/* PHS Add DIAG Setting */
#define DIAG_CFG_FILE	"diagCfg.nvm"

/*
 * NVM access
 */
typedef enum
{
	nvhsOK,
	nvhsFileTooShort,
	nvhsStructNameMismatch,
	nvhsStructFormat
} NVM_Header_Status_te;

//ICAT EXPORTED ENUM
typedef enum {
	DIAG_INT_IFC,
	DIAG_EXT_IFC
} DIAG_IF_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	DIAG_DEV_USB,
	DIAG_DEV_SD,
	DIAG_DEV_FS,
	DIAG_DEV_UART,
	DIAG_DEV_SPI,
	DIAG_DEV_NONE
} DIAG_DEV_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	SULOG_DEV_USB,
	SULOG_DEV_SD
} SULOG_DEV_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	EEH_DUMP_DEV_USB_SD,
	EEH_DUMP_DEV_SPI
} EEH_DUMP_DEV_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	DIAG_START_PS_OFF,
	DIAG_START_PS_ON
} DIAG_START_PS_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	DIAG_UART_SPEED_115200,
	DIAG_UART_SPEED_460800,
	DIAG_UART_SPEED_921600,
	DIAG_UART_DISABLE
} DIAG_UART_SPEED_TYPE;

//ICAT EXPORTED STRUCT
typedef struct {
	DIAG_IF_TYPE useIntIf; 	/* use internal interface or external interface */
	DIAG_UART_SPEED_TYPE useHighSpeedUART;		/* high speed UART(460800) or low speed UART(115200)*/
	//DIAG_MEM_SWITCH diagMemSwitch;
	BOOL   GLFeatureFlag;
	DIAG_START_PS_TYPE diagStartPS;
	DIAG_DEV_TYPE diagDevType;
	SULOG_DEV_TYPE sulogDevType;
	EEH_DUMP_DEV_TYPE eehDumpDevType;
	//DIAG_MEM_SWITCH diagMemSwitch;
	BOOL usbUserMode;
} diagCfgDataS;

//ICAT EXPORTED STRUCT
typedef struct
{
   UINT32 dbID;
   UINT32 filterBitLength;
   UINT32 reserved[6];
}DIAG_Nvm_Filter_File_Header_t;

//ICAT EXPORTED ENUM
typedef enum
{
	LOG_DISABLE     = 0x0,
	UART_LOG_ENABLE = 0x1,
	ACAT_LOG_ENABLE = 0x2
} Log_ConfigE;

//ICAT EXPORTED ENUM
typedef enum
{
	MSG_DISABLE     = 0x0,
	ACAT_MSG_ENABLE = 0x1
} Msg_ConfigE;

//ICAT EXPORTED ENUM
typedef enum
{
	RTI_LOG_DISABLE = 0x0,
	RTI_DUMP_ENABLE = 0x1,
	RTI_TASK_ENABLE = 0x2,
	RTI_MIPS_ENABLE = 0x3
} RTI_ConfigE;

#if 0
//ICAT EXPORTED ENUM
typedef enum
{
	MASS_STORAGE_DISABLE = 0x0,
	MASS_STORAGE_ENABLE  = 0x1
} MassStorage_ConfigE;
#endif
//ICAT EXPORTED STRUCT
typedef struct {
	Log_ConfigE log_cfg;
	Msg_ConfigE msg_cfg;
	RTI_ConfigE rti_cfg;
} Log_ConfigS;

//ICAT EXPORTED ENUM
typedef enum
{
	YMODEM_DISABLE = 0x0,
	YMODEM_ENABLE  = 0x1
} Ymodem_Dump_config;

//ICAT EXPORTED STRUCT
typedef struct {
	Ymodem_Dump_config config;
} Ymodem_Dump_type;

//ICAT EXPORTED ENUM
typedef enum
{
    /* MIFI driver*/
	USB_GENERIC_MIFI_DRIVER     = 0x0,
	USB_MARVELL_MIFI_DRIVER     = 0x1,
	USB_ASR_MIFI_DRIVER 	    = 0x2,
	USB_GENERIC_MOD_DRIVER      = 0x10,
	USB_GENERIC_MOD_ECM_DRIVER  = 0x12,
#ifdef QUEC_USB_CDC_SUPPORT
	USB_CDC_ACM_ONLY_DRIVER 	= 0x13,
#endif
	USB_DIAG_UAC_DRIVER         = 0x14,

	/* MBIM driver*/
	USB_MBIM_ONLY_DRIVER 	    = 0x40,
	USB_MBIM_GENERIC_DRIVER     = 0x41,
	USB_MBIM_MAX_DRIVER         = 0x4F,

	/* Other driver*/
	USB_CDROM_ONLY_DRIVER       = 0x91,
	USB_CDROM_DIAG_DRIVER       = 0x92,
	USB_DIAG_ONLY_DRIVER        = 0x93,
	USB_MODEM_ONLY_DRIVER       = 0x94,
	USB_MODEM_DIAG_DRIVER       = 0x95,

	USB_MAX_DRIVER              = 0xFF
} Usb_driver_typeE;

//ICAT EXPORTED ENUM
typedef enum
{
	MASS_STORAGE_DISABLE = 0x0,
	MASS_STORAGE_ENABLE  = 0x1
} MassStorage_ConfigE;

//ICAT EXPORTED ENUM
typedef enum
{
	USB_AUTO_INSTALL_DISABLE = 0x0,
	USB_AUTO_INSTALL_ENABLE  = 0x1
} Usb_auto_install_type;

//ICAT EXPORTED ENUM
typedef enum
{
	USB_OS_DETECT_DISABLE = 0x0,
	USB_OS_DETECT_ENABLE  = 0x1
} Usb_OS_detect_type;

//ICAT EXPORTED STRUCT
typedef struct {
	Usb_driver_typeE usb_driver;
	MassStorage_ConfigE mass_storage;
	Usb_auto_install_type auto_install;
	Usb_OS_detect_type os_detect;
} Usb_DriverS;

//fix build warnning
BOOL getUsbUserMode(void);
void diagCfgDevInit(void);
UINT8 Sulog2SDCard(void);
void setDiagDevType(DIAG_DEV_TYPE type);
void setSulogDevType(SULOG_DEV_TYPE type);
DIAG_DEV_TYPE diagGetDevType(void);

#endif //_DIAG_NVM_H_
