/**  @file
  quec_production_cfg.h

  @brief
  This file is used to define the configuration for different Quectel Project.

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
04/15/2020        Ramos      	 Init version
=================================================================*/
/*通用类型，解决h重复应用导致的编译报错，ponyadd 2023 12 26*/
#ifndef STQUECCOMINFO_T
typedef struct quecCfgItem{
	unsigned short   ItemIndexInflash;
	unsigned int    Item_size;
	unsigned short     data_crc;
} ST_quecComInfo;
#define STQUECCOMINFO_T
#endif


#ifndef _QUEC_PRODUCTION_CFG_H
#define _QUEC_PRODUCTION_CFG_H

/*> include header files here*/

#include "quec_cust_feature.h"
//#include "quec_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef QUEC_PRODUCTION_CFG_SUPPORT

/*========================================================================
 *  Macro Definition
 *========================================================================*/
#define QUEC_CFG_BYTE_LEN	16
#define QUEC_CFG_BYTE_STR	"QuecCfg"

#define QUECCFG_HEAD_MAGIC1        (0x51D24368)
#define QUECCFG_HEAD_MAGIC2        (0x4378AC6E)

#define QUECCFG_TAIL_MAGIC1        (0x78E5D4C2)
#define QUECCFG_TAIL_MAGIC2        (0x54F7D60E)

#define QUECCFG_TAIL_ENDFLAG      0xAA55AA55


#define QUEC_CFG_DUALPORT_ENABLE 1
#define QUEC_CFG_DUALPORT_DISABLE 0
#define QUEC_PRODUCTION_CFG_SIZE     0x1000




/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
//枚举类型需与g_QuecCfgItemSize条目一致，否则会导致结构体访问越界
// 此枚举必须按顺序添加，千万不能跳跃！！！！！，移植时也要保证顺序??
typedef enum{
	QUEC_PARA_HEAD=0,
	QUEC_PIDVID,
	QUEC_USB_NET,
	QUEC_DUALPORT,
#ifdef QUEC_ASR_ATCMD_USB_NET_MAC_SUPPORT
	QUEC_USBNET_PARAMS_CFG,
#endif
	QUEC_CUST_FEATURE_CFG,
//	QUEC_IPR,
//	QUEC_DIAGPORT_IPR,
#if defined QUEC_AUDIO_SUPPORT	
//we must add one by one, if you insert one in the list will be case a big bug, quality problem . 
	QUEC_AUDIO_SET,
#endif
#if QUEC_DUAL_SIM_SUPPORT
	QUEC_SIM2_DFT_CFG,
#endif
// the follow is not allow add any enum
	QUEC_CFG_END_TAIL,
	QUEC_CFG_MAX,
}Enum_paraCfgId;



/*========================================================================
 *  Type Definition
 *========================================================================*/
typedef struct quecPorjectPara{
	char        version[6];
	char        projecteName[20];
	UINT8      quec_vid_LSB;
	UINT8      quec_vid_MSB;
	UINT8      quec_pid_LSB;
	UINT8      quec_pid_MSB;
	UINT32     usbnet;
	UINT32     ipr;
	UINT32     ipr_diagport;
	
#if 0
	band;
	usbnetautoconnect;
	led;
	UINT32      diagport;


	donglemifi;
	quecthing;
	URCport;
	Risigtype;
	URCcfg;()
	PPPREmotuIP;
#endif
	
} ST_quecPorjectPara;

 /*=================================================================================================*/

/*===============================================
 *  Important Note: the follow struct not change when 
 *=====================================================*/

typedef struct quecItemInfoMap{
	Enum_paraCfgId Item_Id;
	INT32 Item_size;
	int (*quecCfg_get_defualtV)(Enum_paraCfgId itemId, void *quecCfgPara, INT32 quecCfgItemSize);
}ST_quecItemInfoMap;

 
typedef struct quecSysParaHead{
	char     version[8];  //字节对齐
    UINT32 magic1;  
    UINT32 magic2;
} ST_quecSysParaHead;


typedef struct quecSysParaTail{
    UINT32    magic1;  
    UINT32    magic2;
	UINT32    endflag;
	UINT16    Totaldata_crc;
} ST_quecSysParaTAIL;

typedef struct {
	ST_quecComInfo quecComInfo;
	UINT32  queCfgPID;
	UINT32  queCfgVID;
}ST_quecCfgUsbPidVid;


typedef struct {
	ST_quecComInfo quecComInfo;
	UINT32  quecCfgUsbNet;
}ST_quecCfgUsbNet;


typedef struct {
	ST_quecComInfo quecComInfo;
	UINT32  quecCfgDualport;
#if QUEC_DEBUG_LOG_SWITCH
	int	debug_onff;
#endif
	UINT32 startup_time_flag;
	UINT32 tone_incoming_cmd_value;
	UINT32 reserved[62];
}ST_quecCfgDualport;


/* moden cust feature params */
typedef struct
{
	ST_quecComInfo quecComInfo;
    /*air plane out pin crtl */
	UINT32 airPlanePinEnable; /* AT+QCFG="airplanecontrol" */
	UINT8 netLedMode;         /* AT+QCFG="ledmode",..       */
	UINT8 lteDfltCid;	      /* AT+QCFG="LTEDFTCID",..     */
	/* oem land feature */
    UINT8 oemLandi;           /* AT+QOEM="landi",..         */
	UINT8 oemLandiPin;        /* AT+QOEM="landipin",..         */
	 
	UINT32 reserved[20];      /*if you add one param before,here need delete one (4byte struct alinged 4) */
}ST_quecCfgCustFeatureParams;

//Fitz.xu 20211014: Add to save default bear for SIM2 
typedef struct {
	ST_quecComInfo quecComInfo;
	UINT8 lteDfltCid;
	char  reserved[16];
}ST_quecCfgSim2DftCfg;


/******************************************************************
*	 Functions
******************************************************************/

int Quec_SyscfgItem_head_default_get(Enum_paraCfgId itemId, void* quecCfgPara, INT32 quecCfgItemSize);
int Quec_SyscfgItem_UsbPidVid_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);
int Quec_SyscfgItem_UsbNet_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);
int Quec_SyscfgItem_dualport_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);
//add new param
#ifndef MV_USB2_NO_USBNET
int Quec_SyscfgItem_UsbNet_Params_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);
#endif
int Quec_SyscfgItem_CustFearture_Params_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);


int Quec_SyscfgItem_EndTail_default_get(Enum_paraCfgId itemId, void* quecCfgPara, INT32 quecCfgItemSize);


int Quec_SysItemPara_Item_set(Enum_paraCfgId ItemId, void *quecCfgPara,  INT32 quecCfgItemSize);
int Quec_SysItemPara_Item_get(Enum_paraCfgId ItemId, void *quecCfgPara, INT32 quecCfgItemSize) ;
int Quec_SyscfgItem_audio_default_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);
int Quec_SyscfgItem_sim2_dft_cfg_get(Enum_paraCfgId itemId,  void *quecCfgPara, INT32 quecCfgItemSize);




void Quec_load_QuecCfg_SysPara(void);



/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
typedef enum
{
	
	QUEC_CFG_CODE_GENERAL_ERROR = -100,
		
	QUEC_CFG_CODE_NULL_POINTER,
	
	QUEC_CFG_CODE_HEADER_CHECK_ERROR,
	
	QUEC_CFG_CODE_FLASH_ERASE_ERROR = -80,
	QUEC_CFG_CODE_FLASH_WRITE_ERROR,
	QUEC_CFG_CODE_FLASH_READ_ERROR,
	
	QUEC_CFG_CODE_MEMORY_ERROR = -10,
	
	QUEC_CFG_CODE_NOERROR = 0,
	QUEC_CFG_CODE_GENERAL_SUCESS = QUEC_CFG_CODE_NOERROR,
	
}quec_cfg_error_code_e;

//
typedef enum
{
	QUEC_FOTA_EXEC_NULL = 0,
	QUEC_FOTA_EXEC_BY_SDK,
	QUEC_FOTA_EXEC_BY_OBM,
	QUEC_FOTA_EXEC_MAX,
}quec_fota_exec_option;

//
typedef enum
{
	QUEC_RECOVERY_EXEC_NULL = 0,
	QUEC_RECOVERY_EXEC_BY_SDK,
	QUEC_RECOVERY_EXEC_BY_OBM_ONLY_CHECK,
	QUEC_RECOVERY_EXEC_BY_OBM,
	QUEC_RECOVERY_EXEC_MAX,
}quec_recovery_exec_option;


/*========================================================================
 *  Type Definition
 *========================================================================*/
//to save all configuration
//need 4 bytes align
typedef struct quec_production_cfg
{
	char quec_chk_bytes[QUEC_CFG_BYTE_LEN];//for header check
	int quec_dualport_support;//dual at serial port support or not
	int quec_fota_exec_opt;
	int quec_recovery_exec_opt;
#if QUEC_DEBUG_LOG_SWITCH
	int	debug_onff;
#endif
}quec_production_cfg_s;


/******************************************************************
*	 Functions
******************************************************************/
//read configuration from flash and check the header
int quec_production_cfg_read(quec_production_cfg_s * p_config);
int quec_production_current_cfg_get(quec_production_cfg_s * p_config);

//save configuration to flash
int quec_production_cfg_write(quec_production_cfg_s * p_config);

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif



