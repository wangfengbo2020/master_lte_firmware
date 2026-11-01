/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/*  COPYRIGHT (C) 2002 Intel Corporation.                               */
/*                                                                      */
/*  This file and the software in it is furnished under                 */
/*  license and may only be used or copied in accordance with the terms */
/*  of the license. The information in this file is furnished for       */
/*  informational use only, is subject to change without notice, and    */
/*  should not be construed as a commitment by Intel Corporation.       */
/*  Intel Corporation assumes no responsibility or liability for any    */
/*  errors or inaccuracies that may appear in this document or any      */
/*  software that may be provided in association with this document.    */
/*  Except as permitted by such license, no part of this document may   */
/*  be reproduced, stored in a retrieval system, or transmitted in any  */
/*  form or by any means without the express written consent of Intel   */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: Comm. DVFM Header File for external use                       */
/*                                                                      */
/* Filename: DVFM_ext.h                                                 */
/*                                                                      */
/* Author:  Idan Bartura                                                */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     					*/
/*																		*/
/* Remarks: -                                                           */
/*    													                */
/* Created: 12/4/2007                                                   */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/
#ifndef _DVFM_EXT_H_
#define _DVFM_EXT_H_

#include "global_types.h"
#include "diag_API.h" // diag output to ICAT
#include "diag.h"	  // diag output to ICAT
#include "commccu.h"
#include "commpm.h"
#include "pm_ext_debug.h" /* D2-L1 integration */

typedef UINT32 DVFMHandlerT;

//the answer to PP chnage req should detrmine if current PP is equal/lower/higher then the requested PP
typedef enum
{
	PP_CURRENT_IS_AS_REQUESTED_NO_CHANGE = 0,
    PP_CURRENT_HIGHER_THEN_REQUESTED,
    PP_CURRENT_LOWER_THEN_REQUESTED,
	PP_FORCE_REQUESTED
}DVFM_Req_Answer;

//DVFMClientCbkT to call after PP change finished
typedef void (DVFMClientCbkT)(CommPM_PPE NewPP);

typedef struct  {
		DVFMClientCbkT*    DoAfterFreqChange;
	}DVFMDoAfterFreqChange;

//function prototypes

DVFMHandlerT DVFMRegister (CommPM_ClientsE client, DVFMClientCbkT Cbk);

DVFM_Req_Answer DVFMChangePP (DVFMHandlerT ClientHandler, CommPM_PPE NewPP);

CommPM_PPE DVFMGetHWCurrentPP(void);

CommPM_PPE DVFMGetStatus(void);

void DVFMPhase1Init(void);

void DVFMPhase2Init(void);

void DVFMD2Recover(void);

void DVFMChangeVoltageAfterD2(void);
void DVFMChangeVoltageForD2Step1(CommPM_PPE D2PP);
void DVFMChangeVoltageForD2Step2(void);
void DVFMChangeFreqAfterD2(void);
void DVFMChangeVoltageAfterD2PP1(void);

#endif
