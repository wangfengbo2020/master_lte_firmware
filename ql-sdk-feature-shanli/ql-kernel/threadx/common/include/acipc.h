/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************//*                                                                      */
/* Title: Application Communication IPC Driver                          */
/*                                                                      */
/* Filename: acipc.h                                                    */
/*                                                                      */
/* Author:   Eli Levy                                                   */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HAL     			    	*/
/*												                        */
/* Remarks: -                                                           */
/*    										                        	*/
/* Created: 24/12/2006                                                  */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/
#if !(defined _ACIPC_H_)
#define _ACIPC_H_

#include "global_types.h"


/*----------- Global defines -------------------------------------------------*/

/* this enum define the event type*/
//ICAT EXPORTED ENUM
typedef enum
{
	ACIPC_DDR_RELQ_REQ		= 0x00000001,
	ACIPC_DDR_RELQ_ACK		= 0x00000001,
	ACIPC_DDR_260_RELQ_REQ	= 0x00000002,
	ACIPC_DDR_260_RELQ_ACK	= 0x00000002,
	ACIPC_MSL_SLEEP_ALLOW	= 0x00000004,
	ACIPC_MSL_WAKEUP_ACK	= 0x00000008,
	ACIPC_MSL_WAKEUP_REQ	= 0x00000010,
    ACIPC_DATA_Q_ADRS       = 0x00000020,
    ACIPC_DATA_IND          = 0x00000040,
	ACIPC_SPARE_1			= 0x00000080,
	ACIPC_DDR_260_READY_REQ	= 0x00000100,
	ACIPC_DDR_260_READY_ACK	= 0x00000100,
	ACIPC_DDR_READY_REQ		= 0x00000200,
	ACIPC_DDR_READY_ACK		= 0x00000200,

}ACIPC_EventsE;

#if defined(NEZHA3_1826)

//ICAT EXPORTED ENUM
typedef enum
{
	DDR_FREQUENCY_104,	
	DDR_FREQUENCY_156,
	DDR_FREQUENCY_208,	
	DDR_FREQUENCY_312,
	DDR_FREQUENCY_400,
	DDR_FREQUENCY_528,
	DDR_FREQUENCY_NUM, 
	DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM,
} DDR_FREQUENCY ;

#elif defined(EDEN_1928)
//ICAT EXPORTED ENUM
typedef enum
{
	DDR_FREQUENCY_78,
	DDR_FREQUENCY_104,	
	DDR_FREQUENCY_156,
	DDR_FREQUENCY_208,	
	DDR_FREQUENCY_312,
	DDR_FREQUENCY_400,
	DDR_FREQUENCY_528,
    DDR_FREQUENCY_624,	
	DDR_FREQUENCY_667,
	DDR_FREQUENCY_800,
	DDR_FREQUENCY_NUM, 
	DDR_FREQUENCY_INVALID = DDR_FREQUENCY_NUM,
} DDR_FREQUENCY ;
#else
typedef enum
{
	DDR_FREQUENCY_156,
	DDR_FREQUENCY_312,
	DDR_FREQUENCY_400,
	DDR_FREQUENCY_416 = DDR_FREQUENCY_400,		//For ULC
	DDR_FREQUENCY_528,		//For ULC
	DDR_FREQUENCY_624,		//For ULC
	DDR_FREQUENCY_667_800,	//For ULC
	DDR_FREQUENCY_INVALID

} DDR_FREQUENCY ;
#endif

// only use for DDR FC level setting.
typedef enum
{
	DDR_FREQUENCY_LV0,		//For PS use DDR frequency choose.
	DDR_FREQUENCY_LV1,		//For PS use DDR frequency choose.
	DDR_FREQUENCY_LV2,		//For PS use DDR frequency choose.
	DDR_FREQUENCY_LV3,		//For PS use DDR frequency choose.
	DDR_FREQUENCY_LV_INVALID
} DDR_FREQUENCY_LEVEL ;

/* ACIPC return code enum*/
//ICAT EXPORTED ENUM
typedef enum
{
	ACIPC_DDR_AVAIL=0x00000001
}ACIPC_FlagsE;
typedef enum
{
	ACIPC_RC_OK=0,
	ACIPC_HISTORICAL_EVENT_OCCUR,
	ACIPC_EVENT_ALREADY_BIND,
}ACIPC_ReturnCodeE;

/* used by clients when binding a callback to an event*/
//ICAT EXPORTED ENUM
typedef enum
{
	ACIPC_CB_NORMAL=0,     /* callback will be called only if the DDR available        */
	ACIPC_CB_ALWAYS_NO_DDR /* callback will be called always ,even if the DDR is not available*/
}ACIPC_CBModeE;

/* clients callback type*/
/*ICAT EXPORTED FUNCTION_TYPEDEF*/
typedef UINT32 (*ACIPC_RecEventCB)(UINT32 eventsStatus);

/* the element that clients send or receive*/
typedef UINT32 ACIPC_Data;

/*----------- API prototype -------------------------------------------------*/
/*
	When more than one DLL/Module uses a LIB each one has a private code instans of the LIB functions
	that are transelated to IOCCTL calls to the lib. This causes that the LIB functions can't have the
	names that the modules use.
	The solution is in the following defines that cause that all the LIB functions are called
	FunctionName_kernel. It is all solved in this defined and the _kernel functions should NOT be used
	anyware in the code.
*/
#if (defined BUILD_KERNEL)
    #define     ACIPCEventSet		ACIPCEventSet_kernel
    #define     ACIPCDataSend		ACIPCDataSend_kernel
    #define     ACIPCDataRead		ACIPCDataRead_kernel
    #define     ACIPCEventStatus    ACIPCEventStatus_kernel
    #define     ACIPCEventBind      ACIPCEventBind_kernel
    #define     ACIPCEventUnBind    ACIPCEventUnBind_kernel
    #define     ASSERT(cONTD)                                   //  Kernel has an issue with ASSERT.
#endif

#ifdef __cplusplus
extern "C"{
#endif

// add by zhangwl for DDR frequency choose.
typedef struct _DDRFreChg_DataNodeS
{
	struct _DDRFreChg_DataNodeS *pNext;

	UINT32 DDRFreq_Id;
	DDR_FREQUENCY_LEVEL DDR_Freq;
} DDRFreChg_DataNodeS;

ACIPC_ReturnCodeE ACIPCEventSet(ACIPC_EventsE userEvent);
ACIPC_ReturnCodeE ACIPCDataSend(ACIPC_EventsE userEvent,ACIPC_Data data);
ACIPC_ReturnCodeE ACIPCDataRead(ACIPC_Data *data);
ACIPC_ReturnCodeE ACIPCEventStatusGet(UINT32 userEvent,UINT32 *status);
ACIPC_ReturnCodeE ACIPCEventBind(UINT32 userEvent,ACIPC_RecEventCB cb,ACIPC_CBModeE cbMode,UINT32 *historicalEventStatus);
ACIPC_ReturnCodeE ACIPCEventUnBind(UINT32 userEvent);
DDR_FREQUENCY readDDRFrequencyChangeValue(void);
DDR_FREQUENCY readDDRFreqRequestedByHWDFC(void);
BOOL DDRFrequencyIDCreate(UINT32 *Freq_Id);
void DDRFrequencyChangeRequest(UINT32 Freq_Id, DDR_FREQUENCY_LEVEL frequency);
void DDRFrequencyChangeRequestToAP(void);
void ACIPCPhase1Init(void);
void ACIPCPhase2Init(void);
void GetHWDFCTable(void);

#ifdef __cplusplus
}
#endif


#endif  /* _ACIPC_H_ */
