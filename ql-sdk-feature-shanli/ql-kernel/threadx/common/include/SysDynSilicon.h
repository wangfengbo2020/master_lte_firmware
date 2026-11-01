/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/* SysDynSilicon.h														*/
/* 																		*/
/************************************************************************/

#ifndef UTILS_CFG_SILICON_H
#define UTILS_CFG_SILICON_H

#include "global_types.h"


typedef enum
{
    LEGACY_DSSP=0,
    REGULAR_DSSP
}DSSPModeEn;

BOOL isTCx874    (void);
BOOL isHermon874 (void);

UINT32 	Sys_wdtKickRegAddress(void);
UINT32  Sys_usbVersion(void);
BOOL   	Sys_CommpmUsimNmosEngageInUse(void);
BOOL   	Sys_CommpmMemConfRequired(void);
BOOL 	Sys_IsDataOMSLOverACIPC(void);
BOOL 	Sys_ACIPCIntEna(void);
BOOL 	Sys_PowerModificationsForPVEnable(void);
BOOL 	SysUSIMWakeupIntResetEna(void);
BOOL 	Sys_CSSR_WDT_KICK_MODE_BIT_SetIsEnable(void);
BOOL    Sys_usimUseDma(void);
UINT8   Sys_usimDetectGpioPinNo(void);
BOOL 	Sys_intcIsThirdRegisterExist(void);
BOOL    Sys_IsProductIDTavorLlike(void);
UINT16 Sys_AplpRFD_GetRxTxDelay(void);
BOOL   Sys_IsWorkingWith3dBOffset(void);
BOOL    Sys_TavorSiliconIs_PV_B0orUpper(void);
BOOL   Sys_isCpuEshel(void);

typedef struct Sys_L1Crd_param_tag
{
	UINT32  L2GramBuffSize;
	UINT32  L2GramBuffAdd;
	UINT32  L2ShmBuffSize;
	UINT32  L2ShmBuffAdd;
	UINT32  L1DataABuffSize;
	UINT32  L1DataABuffAdd;
	UINT32  L1DataBBuffSize;
	UINT32  L1DataBBuffAdd;
	UINT32  L2GramBuff2Size;
	UINT32  L2GramBuff2Add;
} Sys_L1Crd_param;
Sys_L1Crd_param* Sys_CrdGBdump(void);
#endif // UTILS_CFG_SILICON_H
