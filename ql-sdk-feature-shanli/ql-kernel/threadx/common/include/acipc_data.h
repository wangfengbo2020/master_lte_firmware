/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*											                            */
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
/*  form or by any means without the express written consent of Marvell */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: Application Communication IPC Driver                          */
/*                                                                      */
/* Filename: acipc_data.h                                               */
/*                                                                      */
/* Author:   Ian Levine                                                 */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel & Boerne RTOS, HAL          */
/*                                                                      */
/* Remarks: -                                                           */
/*                                                                      */
/* Created: 4/2/2007                                                    */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/
#if !(defined _ACIPC_DATA_H_)
#define _ACIPC_DATA_H_

#include "global_types.h"

#ifdef  EXTERN
#undef  EXTERN
#endif

#ifdef __cplusplus
#define     EXTERN      extern
extern "C" {
#else
#define     EXTERN
#endif

/*----------- Global defines -------------------------------------------------*/

#if (defined OSA_NUCLEUS)
#ifndef PHS_SW_DEMO_TTC
    #define     ACIPCD_APPADDR_TO_COMADDR(aDDRESS)    ((aDDRESS)  &&  (UINT32)(aDDRESS) < 0xD0000000  ?  (UINT32)(aDDRESS)+0x11000000  :  (UINT32)(aDDRESS))
#else
    #define     ACIPCD_APPADDR_TO_COMADDR(aDDRESS)    ((UINT32)(aDDRESS)) //((aDDRESS)  &&  (UINT32)(aDDRESS) < 0xD0000000  ?  (UINT32)(aDDRESS)+0x11000000  :  (UINT32)(aDDRESS))
#endif    
    #define     ACIPCD_COMADDR_TO_APPADDR(aDDRESS)    ((UINT32)(aDDRESS)) //-0x11000000)
#endif

#if (defined OSA_WINCE)
    #include    "ComMemMapping.h"
    #define     ACIPCD_APPADDR_TO_COMADDR(aDDRESS)  MAP_VIRTUAL_TO_PHYSICAL_ADDRESS(aDDRESS)
    #define     ACIPCD_COMADDR_TO_APPADDR(aDDR)     MAP_PHYSICAL_TO_VIRTUAL_ADDRESS(aDDR)
#endif

#define     ACIPCD_MAX_RPC      32      //  Can't exceed 32

//ICAT EXPORTED ENUM
typedef enum
{
#ifdef PHS_SW_DEMO_TTC
	ACIPCD_RESERVED = 0,
	ACIPCD_CI_SID,			/* ci stub */
	ACIPCD_NVM_SID,			/* nvm stub */
	ACIPCD_CI_DATA_SID,		/* ci data stub */
	ACIPCD_DIAG_PORT_SID,	/* DIAG port stub */
	ACIPCD_AUDIO_SID,		/* Audio stub */
	ACIPCD_DIAG_SID = 16,	/* DIAG control stub */
	ACIPCD_RTC_SID = 18,	/* RTC tunnel stub */
	ACIPCD_USB_SID,			/* USB tunnel stub */
	ACIPCD_LAST_SID = 31,	/* Max service id = 31 */	
	ACIPCD_DIAG_DATA_SID = 0	/* DIAG data stub */
#else
    ACICPD_RESERVED = 0,
    ACICPD_NVM_RPC,
    ACICPD_USBMGR_TUNNEL,
	ACICPD_DIAG_CONTROL,
	ACICPD_DIAG_DATA,
    ACICPD_RTC,
    ACICPD_AGPS,
    ACICPD_CI_SH_REG,
    ACICPD_CI_SH_REQ,
    ACICPD_CI_REQ_CNF,
    ACICPD_CI_IND_RES,
    ACICPD_RESERVE_1,
    ACICPD_RESERVE_2,                   //  Can add more ...
    ACICPD_LAST_SERVICE_ID
#endif
} ACIPCD_ServiceIdE ;

#ifdef PHS_SW_DEMO_TTC
typedef enum
{
	ACIPCD_ServicePriority_Highest = 0,
	ACIPCD_ServicePriority_0 = ACIPCD_ServicePriority_Highest,
	ACIPCD_ServicePriority_1,
	ACIPCD_ServicePriority_2,
	ACIPCD_ServicePriority_3,
	ACIPCD_ServicePriority_4,
	ACIPCD_ServicePriority_5,
	ACIPCD_ServicePriority_6,
	ACIPCD_ServicePriority_Lowest = ACIPCD_ServicePriority_6,
	ACIPCD_ServicePriority_7,
	ACIPCD_ServicePriority_Reserved = ACIPCD_ServicePriority_7,
} ACIPCD_ServicePriorityE ;
#endif

//ICAT EXPORTED ENUM
typedef enum
{
    ACIPCD_DO_NOTHING,          //  No action is required before send or after receive.
    ACIPCD_HANDLE_CACHE,        //  Tx: Clean cache before sending / Rx: Invalidate cache before receive.
    ACIPCD_COPY                 //  Tx: Copy to shared memory before sending / Rx: Currently not supported.
} ACIPCD_ActionE ;

typedef enum
{
    ACIPCD_RC_OK = 0,
    ACIPCD_RC_HIGH_WM,		//	The message WAS added to the queue.
	ACIPCD_RC_LINK_DOWN,    //	The message was NOT added to the queue.
    ACIPCD_RC_Q_FULL,       //  The message was NOT added to the queue.
    ACIPCD_RC_ILLEGAL_PARAM,
    ACIPCD_RC_NO_MEMORY
}ACIPCD_ReturnCodeE ;

/*
 * All Call Back Functions are called under a HISR
 */
//ICAT EXPORTED STRUCT
typedef struct
{
    void    (*RxIndCB)(void *, UINT32) ;        //  Data indication (Pointer to the data & its length).
    void    (*LinkStatusIndCB)(BOOL) ;          //  Link status (TRUE=Up, FALSE=Down).
    void    (*LowWmIndCB)(void) ;               //  Low water mark indication - can restart sending.
    void    (*TxDoneCnfCB)(void *) ;            //  Tx complete (Pointer to buffer) - can free the buffer.
    void    (*TxFailCnfCB)(void *) ;            //  Tx fail (Pointer to buffer) - can free the buffer.
} ACIPCD_CallBackFuncS ;

//ICAT EXPORTED STRUCT
typedef struct
{
    void    (*RxIndCB)(int id, void *ptr, UINT32 size);     //  Data indication (Pointer to the data & its length).
    void    (*LinkStatusIndCB)(int id, BOOL up_down);       //  Link status (TRUE=Up, FALSE=Down).
    void    (*LowWmIndCB)(int id);               			//  Low water mark indication - can restart sending.
    void    (*TxDoneCnfCB)(int id, void *ptr);            	//  Tx complete (Pointer to buffer) - can free the buffer.
    void    (*TxFailCnfCB)(int id, void *ptr);            	//  Tx fail (Pointer to buffer) - can free the buffer.
} ACIPCD_CallBackFuncExtS;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32          RpcTimout ;             //  0 - Not RPC, Else timout according to OSA.
    UINT8           HighWm ;                //  How many messages we allow other side to send befor he receives our TxComplete.
    UINT8           LowWm ;                 //  Once he stoped sending, he will restart when Send-Ack <= LowWm
    ACIPCD_ActionE  TxAction ;              //  Action to take before sending.
    ACIPCD_ActionE  RxAction ;              //  Action to take before calling the RxIndCB callback function.
    BOOL            BlockOnRegister ;       //  TRUE - ACIPCD will block until the link on the other side is up.
} ACIPCD_ConfigS ;

/*----------- API prototype -------------------------------------------------*/
#ifdef FN
#undef FN
#endif

#if (defined OSA_WINCE)  &&  (! defined SHMEM_MODULE)
    #define     ACIPCDCheckForRxInd     ACIPCDCheckForRxIndShell
    #define     ACIPCDLinkStatus        ACIPCDLinkStatusShell
    #define     ACIPCDPhase1Init        ACIPCDPhase1InitShell
    #define     ACIPCDPhase2Init        ACIPCDPhase2InitShell
    #define     ACIPCDRegister          ACIPCDRegisterShell
    #define     ACIPCDTxReq             ACIPCDTxReqShell
    #define     ACIPCDRxDoneRsp         ACIPCDRxDoneRspShell
#endif

#define     ACIPCDSendReq(a,b,c)        ACIPCDTxReq(a,b,c)
#define     ACIPCDTxComplete(a,b)       ACIPCDRxDoneRsp(a,b)
#define     DataIndCB                   RxIndCB
#define     TxCompleteIndCB             TxDoneCnfCB
#define     TxFailIndCB                 TxFailCnfCB

EXTERN  void                ACIPCDPhase1Init    ( void ) ;
EXTERN  void                ACIPCDPhase2Init    ( void ) ;

EXTERN  ACIPCD_ReturnCodeE  ACIPCDRegister      ( ACIPCD_ServiceIdE, ACIPCD_CallBackFuncS *, ACIPCD_ConfigS * ) ;

EXTERN  BOOL                ACIPCDLinkStatus    ( ACIPCD_ServiceIdE ) ;                 //  TRUE=Up, FALSE=Down.
EXTERN  void                ACIPCDCheckForRxInd ( void ) ;                              //  This is external only if want to work in polling.

EXTERN  ACIPCD_ReturnCodeE  ACIPCDTxReq         ( ACIPCD_ServiceIdE, void *, UINT16 ) ; //  ServiceId, Data, Length.
EXTERN  ACIPCD_ReturnCodeE  ACIPCDRxDoneRsp     ( ACIPCD_ServiceIdE, void * ) ;         //  ServiceId, Data

EXTERN int ACIPC_Init_Complete(void);
ACIPCD_ReturnCodeE  ACIPCDPSDRxDoneRsp( void *pData);

#ifdef __cplusplus
}
#endif

#undef  EXTERN

#endif  /* _ACIPC_DATA_H_ */
