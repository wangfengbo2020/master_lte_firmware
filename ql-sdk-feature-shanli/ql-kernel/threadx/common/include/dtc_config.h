/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

#ifndef _DTC_CONFIG_H_
#define _DTC_CONFIG_H_


//#if defined(L1_UPGRADE_R6) | defined(SILICON_TTC)
#define UPGRADE_DTC_DRIVER
//#endif

#ifdef UPGRADE_DTC_DRIVER

#ifndef SILICON_TTC
#ifdef  PHS_SW_DEMO_TTC	//jacques   ifndef - simulator, ifdef - hardware
//nothing
#else
#define UPGRADE_DTC_SIMULATOR
#endif
#endif //TTC

#include "global_types.h"

#define DTC_BIGENDIAN_CKIK
// CQ00092184 begin
#if !defined(DTC_TEST_MODE)
#define HIGH_PRIORITY_Q_DEPTH	2
#else
#define HIGH_PRIORITY_Q_DEPTH	32
#endif
// CQ00092184 end
#define LOW_PRIORITY_Q_DEPTH	32

//define memory protection area
#define MPR_HIGH0_ADDR		0xFFFFFFFF
#define MPR_LOW0_ADDR		0x00000000
#define MPR_HIGH1_ADDR		0xFFFFFFFF
#define MPR_LOW1_ADDR		0x00000000
#define MPR_HIGH2_ADDR		0xFFFFFFFF
#define MPR_LOW2_ADDR		0x00000000

#endif //UPGRADE_DTC_DRIVER
#endif //_DTC_CONFIG_H_

