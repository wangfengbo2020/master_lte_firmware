/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
*               MODULE HEADER FILE
*******************************************************************************
*  COPYRIGHT (C) 2005 Intel Corporation, All rights reserved..
*
*  This file and the software in it is furnished under
*  license and may only be used or copied in accordance with the terms of the
*  license. The information in this file is furnished for informational use
*  only, is subject to change without notice, and should not be construed as
*  a commitment by Intel Corporation. Intel Corporation assumes no
*  responsibility or liability for any errors or inaccuracies that may appear
*  in this document or any software that may be provided in association with
*  this document.
*  Except as permitted by such license, no part of this document may be
*  reproduced, stored in a retrieval system, or transmitted in any form or by
*  any means without the express written consent of Intel Corporation.
*
* Title: USIM Data-Link header file
*
* Filename: usim_dl.h
*
* Authors: Eilam Ben-Dror
*
* Description: This is the header file for the USIM Data Link layer.
*
* Last Updated: 14-Dec-2005
*
******************************************************************************/

#ifndef _USIM_DL_H_
#define _USIM_DL_H_

#include "global_types.h"

/*----------- Global defines ------------------------------------------------*/

#define USIM_T1_MAX_BLOCK_SIZE 260

#define USIM_T1_FRAME_SIZE 4	// bytes in the prologue + epilogue


/*----------- Global macro definitions --------------------------------------*/

/*----------- Global type definitions ---------------------------------------*/



/*----------- Extern definition ---------------------------------------------*/

/*----------- Global variable declarations ----------------------------------*/


/*----------- Global constant definitions -----------------------------------*/

/*---------- Global function prototypes -------------------------------------*/
void USIMrxLevelSet(USIM_Card card, UINT32 length);
USIM_ReturnCode USIM_DL_Check_States( USIM_Card card);
void USIM_WDT_TIMER_STOP(USIM_Card card);

UINT32 USIM_DL_read(USIM_Card card, UINT32 length, UINT8 * buffer);
UINT32 USIM_DL_writeRead (USIM_Card card,
                          UINT32 writeLength, UINT8 * writeBuffer,
                          UINT32 readLength, UINT8 * readBuffer);
void usim_record_event_one_data(UINT32 card, UINT8 event, UINT8 data);
void usim_record_event_two_data(UINT32 card, UINT8 event, UINT16 data);
void usim_record_event_four_data(UINT32 card, UINT8 event, UINT32 data);

USIM_ReturnCode USIM_DL_T1Send(USIM_Card card, UINT32 infoLen, UINT8 * info);
USIM_ReturnCode USIM_DL_T1Initiate(USIM_Card card);
VOID USIM_DL_WWTSet(USIM_Card card);
VOID USIM_DL_BWTSet(USIM_Card card);
BOOL USIM_DL_ErrorDetectedT0(USIM_Card card);
BOOL USIM_DL_CheckFlagSetState( USIM_Card card, UINT32 extFlags);
void USIM_WDT_TIMER_START(USIM_Card card,UINT32 interval);
int USIMCompRxFifoLevel(UINT32 length);
void usim_record_event(UINT32 card, UINT8 event);
void usim_record_one_data(UINT32 card, UINT8 data);
#endif /* _USIM_DL_H_ */
