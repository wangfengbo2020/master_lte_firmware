/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#ifndef _IML_MVM_H
#define _IML_MVM_H (1)

//ICAT EXPORTED ENUM
typedef enum {

	IMLConfig_OFF=0,
	IMLConfig_2SD,
	IMLConfig_2DDR,
	IMLConfig_2HSL_BIGBOARD,
	IMLConfig_2HSL_SMALLBOARD,
	IMLConfig_2SU_ENABLE,
	IMLConfig_2SU_DISABLE

} IMLCONFIG_TYPE;

//ICAT EXPORTED STRUCT
typedef struct {

IMLCONFIG_TYPE IMLConfigVal;

UINT8 DataLen;
UINT8 data[64];
} IMLCfgDataS;

void SetIMLSettingToNVM(IMLCfgDataS *IMLCfgdata);
void GetIMLSettingFromNVM(IMLCfgDataS *IMLCfgdata);

#endif /*_IML_MVM_H*/
