/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/****************************************************************************
*                         DataCollector.h
*
*   Created:        20/01/2005
*   Author:			Israel Davidenko
*   Description :   Intel ISPT Data Collector Interface
*   Last Changed:   20/01/2005
*
****************************************************************************/


#ifndef _DATA_COLLECTOR_H_
#define _DATA_COLLECTOR_H_

#include "osa.h"

OSA_STATUS InitDC(void);
void RemoveDC(void);

OSA_STATUS StartDC(void *pData);
void StopDC(void);
void CalibrateDC(void);
void FireEventDC(void);
void SetDCMode(int mode);

#define FULL_LOG_MODE_C  0x00
#define NO_LOG_MODE_C	 0x01
#define PAT_MODE_C 		 0x02
#define PART_LOG_MODE_C  0x03
#define MIPS_XDA_MODE_C	 0x04
#define MIPS_RAM_MODE_C  0x05

#endif

