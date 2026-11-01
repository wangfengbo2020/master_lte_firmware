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
/* Title: Arbel platform Utility					                    */
/*                                                                      */
/* Filename: utilities.c                                                */
/*                                                                      */
/* Author:   Eli Levy                                                   */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     					*/
/*																		*/
/* Remarks: -                                                           */
/*    													                */
/* Created: 26/3/2006                                                   */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/

#define L_WORD_MASK 0xffff0000
#define L_BYTE_MASK 0xffffff00
#define HwdRead32(reg)	(*((volatile UINT32*)(reg)))
#define HwdWrite32(reg,data)	do{*((volatile UINT32*)(reg))=(data);}while(0)


#include <stdint.h>

#include "osa.h"
#include "global_types.h"
#include "diag_API.h"
#include "utilities.h"

#include "timer.h"
#include "timer_config.h"
#include "timer_hw.h"
#include "log.h"
#include "FreqChange.h"
#include "commpm.h"
#include "mvUsbLog.h"
#include "bsp.h"
#include "udc2_hw.h"
#ifdef CRANE_MCU_DONGLE
#include "lfs_cache.h"
#endif

#include "quec_cust_feature.h"
#include "quec_power_manager.h"

#include "MRD.h"
#include "Pmic.h"
#include "UART.h"
#include "osa_mem.h"
#ifdef LWIP_IPNETBUF_SUPPORT
#include "diag_nvm.h"
#endif
#include "asr_property.h"
#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
#include "quec_atcmd_ipc.h"
#endif


#define FREQ_MODE	"[SYS ]"

#if ( defined CRANE_SOC_TEMPERATURE_SENSOR )
static int data_2_celsius(uint32_t data);
static void tsensor_power_switch( UINT8 onoff );
static void tsensor_init1( void );
static void tsensor_init2( void );
static uint32_t get_polling_data( void );
static void tsensor_clock_enable( BOOL FLAG );
static void dump_tsensor_register( void );
#endif



UINT16 grip_threshold_val = 50;// currently set to 50Bytes/s for verification, could be changed per test result
UINT8 grip_last_notify_ap_state=0;// default 0. 0 GRIP sensor off ;1 GRIP sensor on
extern BOOL GetPmaxReductionFlagIn23GNVM(void);
extern BOOL GetLtePmaxReductionFlag(void);
#if defined(ARIQ_MASK_INTERRUPT_BUG_WORKAROUND_TRACE)
#include "osa.h"
#include "GenericFS_API.h"
#include "lowtasks.h"
#include "nvm_header.h"
#include "I2C.h"
#include "i2c_eeprom.h"
#include "SysDynSilicon.h"


#define AIM_BUG_HAPPENED 0

static OSATimerRef printAIMTraceTimerRef;
static lowTaskEventHandler_t AIMTrace2FileHandler = 0;
AIMBugTraceStruct AIMTrace;
void AIMBugTrace2File(lowTaskEventHandler_t eventHandler);
FDI_TCHAR fNamep[]="AIM_BUG_HAPPEN.nvm";
#endif

void DbgPrintf(char* fmt, ...);
void mem_trace_init(void);
TIMER_RETURN_CODE timerTMRsetForSync(TCR_NUMBER tcr_number);
UINT64 timerCountReadU64(void);
extern void check_all_address(void);
UINT64 spi_nor_do_read_uid(void);
extern UINT32 OSAHISRIsValid(OsaRefT OsaRef);
extern UINT32 OsaGetDefaultMemPoolFreeSize(void);
extern BOOL IsDeviceConnctedExternally(void);
extern void L1aAdcValueQueryReq(void);
extern INT16 getAdcValue(void);

extern UINT32  g_IDLE_times;
extern int memory_flg;
extern OSATaskRef commpmLPTRef;
rti_thread_timeout_item rti_thread_timeout[RTI_THREAD_TIMEOUT_SIZE];
UINT32 rti_thread_timeout_index;

rti_mode rti_current_mode = rti_mode_none;
#pragma arm section rodata="RTIMD"
const rti_mode_info rtiModeInfo = {"RTIMD", rti_mode_none};
#pragma arm section rodata

static void SoftDelay( volatile UINT32 count );
extern void setAdcValue( INT16 value );
typedef UINT8 Boolean;
extern Boolean L1aCheckHasRxModeReport(void);
extern void L1aAdcValueQueryReqExt(UINT8 queryType, UINT8 queryCntx);
extern INT16 getAdcValueForRtp(void);
extern void setAdcValueForRtp(INT16 value);
extern INT16 getAdcValueForRtn(void);


/******************************************************************************
* Function name: writeUINT32/16/8
*******************************************************************************
*
* Description  :  this exported function allow user to write UINT32/UINT16/UINT8 value to harbel memory via ICAT
*
* Input args   : base address of 2 arguments : pointer to the destination address, pointer to the data to store
*
* Output args  :   none
*
* Return value :    none
*
* Notes        :
*     1. the status msg that is printed in ICAT read the value just written from the memory.
*     2. in ICAT chose 2 DWORD arguments - the first should be the address the second should be the data
*	  3. it assume that the user access a valid Harbel address.
*
******************************************************************************/
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, writeUINT32
void u_writeUINT32(volatile void *base)
{
	volatile UINT32 *desAdd = (UINT32*)(*(UINT32*)(base));
	UINT32 val2Write = *((UINT32*)base+1);

	*desAdd = val2Write;

	DIAG_FILTER(HW_PLAT, utilities, writeUINT32, writeUINT32a)
	diagPrintf ("address %lx contain %lx",desAdd,*desAdd);

}

//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, writeUINT16
void u_writeUINT16(volatile void *base)
{
	volatile UINT32 *desAdd = (UINT32*)(*(UINT32*)(base));
	UINT16 val2Write = *((UINT16*)base+2);

    *desAdd = (*desAdd & L_WORD_MASK) | val2Write;

	DIAG_FILTER(HW_PLAT, utilities, writeUINT16, writeUINT16a)
	diagPrintf ("address %lx contain %lx",desAdd,*desAdd);

}

//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, writeUINT8
void u_writeUINT8(volatile void *base)
{
	volatile UINT32 *desAdd = ((UINT32*)(*(UINT32*)(base)));
	UINT8 val2Write = *((UINT8*)base+4);

	*desAdd = (*desAdd & L_BYTE_MASK) | val2Write;

	DIAG_FILTER(HW_PLAT, utilities, writeUINT8, writeUINT8a)
	diagPrintf ("address %lx contain %lx",desAdd,*desAdd);

}
/******************************************************************************
* Function name: readUINT32/16/8
*******************************************************************************
*
* Description  : this exported function allow user to read UINT32/UINT16/UINT8 value from Harbel memory via ICAT
*
* Input args   : base address of 2 arguments : address we like to read, number of memory units
*				(byte,word,dword) will like to read
*
* Output args  : none
*
* Return value : none
*
* Notes        :
*     1. in ICAT chose 2 DWORD arguments - the first should be the address the second should be the amount of unit to	*		read
*     2. it assume that the user access a valid Harbel address.
*
******************************************************************************/
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, readUINT32
void u_readUINT32(volatile void *base, void *byteAmount)
{
	UINT32 numOfUINT32,i,*baseAdd;
	numOfUINT32 = *((UINT32*)base+1);
	baseAdd = (UINT32*)(*(volatile UINT32*)base);

	if ((UINT32)byteAmount==4)
		numOfUINT32=1; /* in case only address is given*/

	for(i=numOfUINT32;i>0;i--)
	{
		DIAG_FILTER(HW_PLAT, utilities, readUINT32, readUINT32a)
		diagPrintf ("address %lx contain %lx",baseAdd,*baseAdd);
		baseAdd++;
	}
}
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, readUINT16
void u_readUINT16(volatile void *base,void *byteAmount)
{
	UINT32 numOfUINT16,i;
	volatile UINT16 *baseAdd;

    numOfUINT16 = *((UINT32*)base+1);
	baseAdd = (UINT16*)(*(UINT32*)base);

	if ((UINT32)byteAmount==4)
		numOfUINT16=1; /* in case only address is given*/

	for(i=numOfUINT16;i>0;i--)
	{
		DIAG_FILTER(HW_PLAT, utilities, readUINT16, readUINT16a)
		diagPrintf ("address %lx contain %x",baseAdd,*baseAdd);
		baseAdd++;
	}
}
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, readUINT8
void u_readUINT8(volatile void *base,void *byteAmount)
{
	UINT32 numOfUINT8,i;
	volatile UINT8 *baseAdd;

	numOfUINT8 = *((UINT32*)base+1);
	baseAdd = (UINT8 *)(*(UINT32*)base);

	if ((UINT32)byteAmount==4)
		numOfUINT8=1; /* in case only address is given*/

	for(i=numOfUINT8;i>0;i--)
	{
		DIAG_FILTER(HW_PLAT, utilities, readUINT8, readUINT8a)
		diagPrintf ("address %lx contain %x",baseAdd,*baseAdd);
		baseAdd++;
	}
}
#if defined(ARIQ_MASK_INTERRUPT_BUG_WORKAROUND_TRACE)

UINT32 lastIndexWritten=0;
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, printAIMBugTrace
void printAIMBugTrace (UINT32 cookie)
{
	if (AIMTrace.AIMArrIndex >lastIndexWritten)
	{
		/* if the bug happen print to ICAT and save a file to flash*/
		DIAG_FILTER(HW_PLAT, utilities, printAIMBugTrace, DIAG_INFORMATION)
		diagStructPrintf("AIM Bug Test log - %S{AIMBugTraceStruct}", &(AIMTrace) ,sizeof(AIMBugTraceStruct));
		/*Trigger the low priority task that will save a file with the trace.*/
		LowEventActivate(AIMTrace2FileHandler);
		/* we only print or save file if the trace has records or if a change occur since last saved*/
		lastIndexWritten=AIMTrace.AIMArrIndex;
	}

}

void AIMBugTrace2File(lowTaskEventHandler_t eventHandler)
{
	UINT32 actualWrite;
	FILE_ID fileS;
	NVM_Header_ts nvmHeader;

	if (eventHandler==AIMTrace2FileHandler)
	{
		if((fileS = FDI_fopen(fNamep,"wb"))!=0)
		{
			/* init the NVM header for flash explorer*/
			strcpy(nvmHeader.StructName, "AIMBugTraceStruct");
			nvmHeader.StructSize=sizeof(AIMBugTraceStruct);
			nvmHeader.NumofStructs=1;

			FDI_fwrite(&nvmHeader, 1,sizeof(NVM_Header_ts), fileS);
			actualWrite=FDI_fwrite(&(AIMTrace),sizeof(char),sizeof(AIMBugTraceStruct),fileS);
			FDI_fclose(fileS);

			DIAG_FILTER(HW_PLAT, utilities, AIMFileSaved, DIAG_INFORMATION)
			diagPrintf("AIM Bug file was saved to Flash.please call Eli/Shay.actual bytes written %d",actualWrite);
		}
	}
}
/*
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, addRecordToAIMTrace
void addRecordToAIMTrace (void)
{
	AIMTrace.AIMHistoricalVal[AIMTrace.AIMArrIndex].aimVal=0x1111;
	AIMTrace.AIMHistoricalVal[AIMTrace.AIMArrIndex].lastCin=0xBAD;
	AIMTrace.AIMHistoricalVal[AIMTrace.AIMArrIndex].currentCin=0x2222;
	AIMTrace.AIMArrIndex++;
}
*/

#endif

void utilitiesPhase3Init (void)
{
#if defined(ARIQ_MASK_INTERRUPT_BUG_WORKAROUND_TRACE)
	FILE_INFO file_info;
	/* if this file exist in flash it means the bug happen. since it urgent issue we like to be notified asap.Thanks :) */
	ASSERT(FDI_findfirst(fNamep, &file_info)!=AIM_BUG_HAPPENED);


	/* register function that print the trace to file */
	AIMTrace2FileHandler = LowEventBind(AIMBugTrace2File,LOWEST_EVENT_PRIORITY - 0x01);

	/*print trace and save it to file if needed */
	OSATimerCreate(&printAIMTraceTimerRef);
	ASSERT(OS_SUCCESS == OSATimerStart(printAIMTraceTimerRef, 6000, 6000, printAIMBugTrace, 0));

	AIMTrace.AIMArrIndex=0;

#endif
}

extern void i2cConfigFast ( void   *p );
extern void i2c_Register ( void   *p );
extern void i2c_control ( void   *p );
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, BoardInfoForTracking
void BoardInfoForTracking ( void )
{
#if defined(SILICON_TTC) || defined(PHS_SW_DEMO_TTC)
	 /* TBD */
#else
	UINT8 data1 = EEPROM_I2C_WRITE_SLAVE_ADDRESS;
	UINT8 data2 = EEPROM_I2C_READ_SLAVE_ADDRESS;
	UINT8 data3[3] = {EEPROM_I2C_WRITE_SLAVE_ADDRESS,I2C_FAST,I2C_REPEAT_START};
	UINT8 data4[3] = {EEPROM_I2C_READ_SLAVE_ADDRESS,I2C_FAST,I2C_REPEAT_START};
#endif //SILICON_TTC
	UINT32 p_addressToRead_PV = 0xF0240080;//product ID address until Tavor PV
	UINT32 p_addressToRead_L = 0xD4282C00;//product ID adddress from Tavor L
	InfoForBoardTracking_t entry ={0};

	DIAG_FILTER(HW_PLAT, utilities, BeginBoardInfo, DIAG_INFORMATION)
	diagPrintf("BeginBoardInfo");

#if defined(SILICON_TTC) || defined(PHS_SW_DEMO_TTC)
	 /* TBD */
#else

	if(Sys_IsProductIDTavorLlike()) //Product ID from Tavor L
	{
	   entry.product_id = *(UINT32*)p_addressToRead_L;

	}else //product ID from Tavor PV
	{
	   entry.product_id = *(UINT32*)p_addressToRead_PV;
	}

	i2cConfigFast(&data1);
	i2cConfigFast(&data2);
	i2c_Register(&data1);
	i2c_Register(&data2);
	i2c_control(&data3);
	i2c_control(&data4);

	EEPROM_ReadDataFromMemoryBlocking(0x00,entry.data,0x0F);
#endif//SILICON_TTC

	DIAG_FILTER(HW_PLAT, utilities ,InfoForBoardTracking, DIAG_INFORMATION)
    diagStructPrintf("BoardInfo for Tracking:  %S{InfoForBoardTracking_t}",(VOID*)&entry,sizeof(InfoForBoardTracking_t));

	DIAG_FILTER(HW_PLAT, utilities, endBoardInfo, DIAG_INFORMATION)
	diagPrintf("EndBoardInfo");
}
#ifdef PHS_SW_DEMO_TTC
/* ---- platform options begin ---- */
#include <diag_API.h>

#if defined(PLAT_USE_THREADX)
typedef TX_THREAD* rti_thread_t;

#define RTI_LOCK_INIT		rti_uint32_t level
#define RTI_LOCK_DISABLE	level = disableInterrupts()
#define RTI_LOCK_ENABLE		restoreInterrupts(level)
#define RTI_CURRENT_TICK	diag_get_32k_tick()
#define RTI_CURRENT_OSTICK	OSAGetTicks()
#define RTI_THREAD_DELAY(t)	OSATaskSleep(t)
#define RTI_THREAD_NAME(t)	((TX_THREAD*)t)->tx_thread_name
#define RTI_THREAD_PRIORITY(t)	((TX_THREAD*)t)->tx_thread_priority
#define RTI_THREAD_STATUS(t)	((TX_THREAD*)t)->tx_thread_state
#define RTI_THREAD_ITEM(t)	\
	&rti_thread_array[((TX_THREAD*)t)->tx_system_reserved_2]
#define RTI_THREAD_ITEMINDEX_CHECK(t)	\
		if(((TX_THREAD*)t)->tx_system_reserved_2 >= RTI_THREAD_ARRAY_SIZE) return;
extern TX_THREAD * _tx_thread_current_ptr;
#define RTI_THREAD_CURRENT	_tx_thread_current_ptr

#elif defined(PLAT_USE_ALIOS)
typedef ktask_t* rti_thread_t;

#define RTI_LOCK_INIT		rti_uint32_t level
#define RTI_LOCK_DISABLE	level = disableInterrupts()
#define RTI_LOCK_ENABLE		restoreInterrupts(level)

#define RTI_CURRENT_TICK	diag_get_32k_tick()
#define RTI_CURRENT_OSTICK	OSAGetTicks()
#define RTI_THREAD_DELAY(t)	OSATaskSleep(t)
#define RTI_THREAD_NAME(t)	((ktask_t*)t)->task_name
#define RTI_THREAD_PRIORITY(t)	((ktask_t*)t)->prio
#define RTI_THREAD_STATUS(t)	((ktask_t*)t)->task_state
#define RTI_THREAD_ITEM(t)	\
	(struct rti_thread_item *)(((ktask_t*)t)->sys_info[AOS_KERNEL_SYS_INFO_KEY_RTI])
extern ktask_t* g_active_task[];
#define RTI_THREAD_CURRENT	g_active_task[0]

#else
typedef TC_TCB* rti_thread_t;

#define RTI_LOCK_INIT		rti_uint32_t level
#define RTI_LOCK_DISABLE	level = disableInterrupts()
#define RTI_LOCK_ENABLE		restoreInterrupts(level)

#define RTI_CURRENT_TICK	timerCountReadU64()
#define RTI_CURRENT_OSTICK	OSAGetTicks()
#define RTI_THREAD_DELAY(t)	OSATaskSleep(t)
#define RTI_THREAD_NAME(t)	((TC_TCB*)t)->tc_name
#define RTI_THREAD_PRIORITY(t)	((TC_TCB*)t)->tc_priority
#define RTI_THREAD_STATUS(t)	((TC_TCB*)t)->tc_status
#define RTI_THREAD_ITEM(t)	\
	((TC_TCB*)t)->tc_id == TC_HISR_ID? \
	&rti_thread_array[((TC_HCB*)t)->tc_system_reserved_2] : \
	&rti_thread_array[((TC_TCB*)t)->tc_system_reserved_2]
extern TC_TCB* TCD_Current_Thread;
#define RTI_THREAD_CURRENT	TCD_Current_Thread
#endif

#pragma arm section zidata="RTI_DATA"
static UINT8  gCheckPoint = 0;
rti_uint32_t rti_enable = 0;
rti_uint32_t rti_enable_bak = 0;

#pragma arm section zidata

/* diag printf */
void RTI_LOG(const char* fmt, ...)
{
	va_list ap;
	char buffer[128];
    rti_mode rtiMode = rti_get_mode();

	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);

    switch(rtiMode)
    {
        case rti_log2acat_mode:
        case rti_uarttrace_mode:
        {
        	DIAG_FILTER(HW_PLAT,utilities,LOG, DIAG_INFORMATION)
        	diagPrintf("%s", buffer);
        	break;
	    }

	    default:
	    {
            CPUartLogPrint(buffer, TRUE);
            break;
        }
    }
}

/* ---- platform options end   ---- */

struct rti_thread_item
{
	rti_thread_t tid;

	/* total runed tick count */
	rti_uint64_t tick_count;
	/* last tick count */
	rti_uint64_t last_tick;

	/* scheduled/preemptive count */
	rti_uint32_t scheduled_count;
#ifdef PLAT_USE_ALIOS
	rti_uint32_t thread_entry;
#endif
};
static struct rti_thread_item rti_thread_array[RTI_THREAD_ARRAY_SIZE];
static rti_uint32_t rti_thread_index 		= 0;
static rti_uint32_t rti_thread_enable 		= 0; // to enable target insight, please set to 1
static rti_uint64_t rti_thread_total_tick 	= 0;


rti_uint32_t rti_thread_sm_inited = 1;

rti_uint64_t intc_tick = 0;
rti_uint64_t intc_tick_count = 0;
rti_uint64_t idle_tick_count = 0;
rti_uint64_t idle_last_tick = 0;

extern rti_rt_t rti_rt;
rti_rt_t *rti_ptr = &rti_rt;

#define RTI_SWITCH_ARRAY_SIZE 128
static rti_uint32_t rti_switch_index = 0;
UINT32 PsUploadDataSize=0;
UINT32 PsDownloadDataSize=0;
UINT32 CurrentUpDataThroughput=0;
UINT32 CurrentDlDataThroughput=0;
UINT32 CurrentDiagDataThroughput=0;
extern UINT32 diag_statistics_tx_cnt;


#define RTI_USER_ARRAY_SIZE 128
struct rti_user_item
{
	rti_uint32_t type;
	rti_uint64_t tick;
};

#ifndef LTEONLY_THIN
struct rti_user_item rti_user_array[RTI_USER_ARRAY_SIZE] = {{0, 0}};
static rti_uint32_t rti_user_index = 0;
#endif

const unsigned char hex_num_str[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

#include "EEHandler.h"

void rti_set_eehandler_counter(unsigned long eehandler_counter)
{
	rti_ptr->eehandler_counter = eehandler_counter;
}

void rti_set_eehandler_magic(unsigned long index, unsigned long eehandler_magic)
{
	if(index == 0)
		rti_ptr->eehandler_magic[0] = eehandler_magic;
	else
		rti_ptr->eehandler_magic[1] = eehandler_magic;
}

unsigned long rti_get_eehandler_magic(unsigned long index)
{
	return rti_ptr->eehandler_magic[index];
}


void rti_record_app_time(unsigned long nearest_app_time)
{
	if(rti_enable)
	{
		rti_ptr->nearest_app_time = nearest_app_time;
	}
}

void rti_record_app_found(unsigned long valid_app_found)
{
	if(rti_enable)
	{
		rti_ptr->valid_app_found = valid_app_found;
	}
}

void rti_record_nearest_event(unsigned long func, unsigned long time)
{
	if(rti_enable)
	{
		rti_ptr->nearest_event_func = func;
		rti_ptr->nearest_event_time = time;
	}
}

void rti_record_aam_status(unsigned long aam_status)
{
	if(rti_enable)
	{
		rti_ptr->aam_status = aam_status;
	}
}

#ifndef LTEONLY_THIN
void rti_user_stamp(rti_uint32_t type)
{
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;

	rti_user_array[rti_user_index].type = type;
	rti_user_array[rti_user_index].tick = RTI_CURRENT_TICK;

	rti_user_index ++;
	if (rti_user_index >= RTI_USER_ARRAY_SIZE) rti_user_index = 0;
	RTI_LOCK_ENABLE;
}

void rti_user_value(rti_uint32_t type, rti_uint32_t value)
{
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;

	rti_user_array[rti_user_index].type = type;
	rti_user_array[rti_user_index].tick = value;

	rti_user_index ++;
	if (rti_user_index >= RTI_USER_ARRAY_SIZE) rti_user_index = 0;
	RTI_LOCK_ENABLE;
}
#endif

rti_uint32_t rti_alloc_thread(rti_thread_t tid)
{
	struct rti_thread_item* item = NULL;
	rti_uint32_t item_offset=0;
	UINT16 index;
	BOOL found = FALSE;
	static BOOL rti_thread_info_overflow = FALSE;

	RTI_LOCK_INIT;

	if (TRUE == rti_thread_info_overflow)
	{
		for(index = rti_thread_index; index< RTI_THREAD_ARRAY_SIZE; index++)
		{
			if(rti_thread_array[index].tid == NULL)
			{
				RTI_LOCK_DISABLE;
				item_offset = index;
				rti_thread_index = index;
				rti_thread_index ++;
				RTI_LOCK_ENABLE;

				found = TRUE;
				break;
			}
		}

		if(found == FALSE)
		{
			for(index = 0; index< rti_thread_index; index++)
			{
				if(rti_thread_array[index].tid == NULL)
				{
					RTI_LOCK_DISABLE;
					item_offset = index;
					rti_thread_index = index;
					rti_thread_index ++;
					RTI_LOCK_ENABLE;

					found = TRUE;
					break;
				}
			}

			ASSERT_EXT((found == TRUE), "rti thread array overflow, cnt 0x%x", rti_thread_index);
		}

	}
	else
	{
		/* get the next thread record item */
		RTI_LOCK_DISABLE;
		item_offset = rti_thread_index;
		rti_thread_index ++;
		if(rti_thread_index>= RTI_THREAD_ARRAY_SIZE)
		{
			rti_thread_info_overflow = TRUE;
		}
		RTI_LOCK_ENABLE;

	}

	/* init item */
	item = &rti_thread_array[item_offset];
	item->tid = tid;
	item->tick_count = 0;
	item->scheduled_count = 0;
	item->last_tick = 0;

#ifdef PLAT_USE_ALIOS
	item->thread_entry = OsaGetThreadEntry((OsaRefT)tid);
	return (rti_uint32_t)item;
#else
	return item_offset;
#endif
}

void rti_delete_thread(rti_thread_t tid)
{
	struct rti_thread_item* item = NULL;

	if(tid == NULL)
		return ;

#ifdef PLAT_USE_THREADX
	RTI_THREAD_ITEMINDEX_CHECK(tid);
#endif


	item = RTI_THREAD_ITEM(tid);
	if(item != NULL)
	{
		/*un-init item */
		item->tid = NULL;
		item->tick_count = 0;
		item->scheduled_count = 0;
		item->last_tick = 0;
#ifdef PLAT_USE_ALIOS
		item->thread_entry = NULL;
#endif
	}
	return ;
}

#if 1
extern INTC_InterruptSources Timer_INTC[MAX_TCR_NUMBER];
extern TIMER_CONFIG_STR   Timers[MAX_TCR_NUMBER];

extern TIMER_RETURN_CODE timerTCCRSet(TCR_NUMBER tcr_number, TCR_CONFIGURATION *tcr_configuration);
extern void timerDBModeSet(TCR_NUMBER tcr_number, TCR_CONFIGURATION *tcr_configuration);
extern void timerTPLCRSet(TCR_NUMBER tcr_number, TCR_CONFIGURATION *tcr_configuration);

#define TIMER_INTCID(tcr_number)   (Timer_INTC[(tcr_number)])
#define     TmrController    (* (volatile struct TIMER_HW_REGISTERS *) TIMER_BASE_ADDRESS)

TIMER_TCR_CONFIGURE_RC timerTCRconfigureForSync(TCR_NUMBER tcr_number, TCR_CONFIGURATION *tcr_configuration)
{
	UINT32 cpsrVal;
   TIMER_RETURN_CODE status = TIMER_RC_OK;

   DbgPrintf("timerTCRconfigureForLargeTime %d\r\n",tcr_number);

   cpsrVal = disableInterrupts();

   if  (tcr_number >= MAX_TCR_NUMBER)
   {
		  restoreInterrupts(cpsrVal);
   		return (TCR_CONFIGURE_TCR_ERR_NUM);
   }

   if (Timers[tcr_number].busy == TRUE)                 /* ??? check all relevant configurations here. */
   {
	   restoreInterrupts(cpsrVal);
     return (TCR_CONFIGURE_FAIL);
   }

   Timers[tcr_number].busy = TRUE;
   Timers[tcr_number].timerNotificationPtr = tcr_configuration->timerNotificationPtr;
   Timers[tcr_number].microSec             = tcr_configuration->microSecTimeInterval;
   Timers[tcr_number].cookie    = tcr_configuration->cookie;
   Timers[tcr_number].interrupt_required = tcr_configuration->interrupt_required;


//   timerTCMRSet(tcr_number , TCMR_DISABLE_MODE); /* set TCMR - one shot, periodic */

   status = timerTCCRSet (tcr_number, tcr_configuration);                     /* set TCCR - clock source :fast, 32K, ext, 1K */
   if (status != TIMER_RC_OK)
   {
   	  Timers[tcr_number].busy = FALSE;
	    restoreInterrupts(cpsrVal);
      return (TCR_CONFIGURE_FAIL);
   }

   status = timerTMRsetForSync(tcr_number);                     /* set Match Values */

   if (status != TIMER_RC_OK)
   {
      Timers[tcr_number].busy = FALSE;
      restoreInterrupts(cpsrVal);
	  	return (TCR_CONFIGURE_FAIL);
   }

  if (Timers[tcr_number].interrupt_required&TO_INTERRUPT_REQUIRED)
  {
  #ifdef PHS_SW_DEMO_TTC
  	/*mischecked by coverity*/
  	/*coverity[overrun-local]*/
  	TmrController.tier[tcr_number].reg = 1;
  #else
	TmrController.tier_A.reg |= (1<<tcr_number);
  #endif
    INTCEnable(TIMER_INTCID(tcr_number));     /* Enable Interrupts for relevant TCR */

  }

   timerDBModeSet (tcr_number, tcr_configuration);            /* update the timer mode in the Timers DB   */

//   timerInterruptModeSet(tcr_number, C_TILR_LEVEL);                  /* set TILR (level or Edge) */
   timerTPLCRSet(tcr_number, tcr_configuration);                     /* set TPLCR & TPLVR - preload setting */

//   timerAPBClock(tcr_number);//,PMU_OFF);
	 restoreInterrupts(cpsrVal);
   return (TCR_CONFIGURE_OK);
} /* <End of timerTCRconfigure> */


TIMER_RETURN_CODE timerTMRsetForSync(TCR_NUMBER tcr_number)
{
    UINT32 delta_time;

    // ASSERT(tcr_number < MAX_TCR_NUMBER); /* it can't reach here, the caller function has judged the input para */

      switch (Timers[tcr_number].clock_mode)
      {
         case CLK_FAST:
             delta_time = 0; //no Warnings
             //ASSERT(0);
             return TIMER_RC_NOT_VALID;
         //break;

         case CLK_32KHZ:
             delta_time = 0xA8C00000;
//            TIMER_MIPS_TEST(6);
         break;

         default:
             delta_time = 0; //no Warnings
             //ASSERT(0);			 
             return TIMER_RC_NOT_VALID;
         //break;
      } /* switch */


      Timers[tcr_number].timerAddingValue = delta_time;  /* update timers DB with HW ticks value, according to src clk */
//      TIMER_MIPS_TEST_DATA(delta_time);


#ifdef PHS_SW_DEMO_TTC
      TmrController.tmr[tcr_number].match_reg_0 = delta_time;
#else
      TmrController.tmatch_count[tcr_number].tmr = delta_time;
#endif


	return TIMER_RC_OK;
} /* End of <timerTMRset> */




#endif



/*------------------------------------------UART START------------------------------------------*/
//#define EN_UART_DBG	1

#ifndef CRANE_MCU_DONGLE

typedef struct dfifo
{
	UINT8 *buf;
	UINT32 size;
	UINT32 in;
	UINT32 out;
	UINT32 cnt;
}dfifo_t;

typedef enum
{
	UART_FIFO_DIS=0,
	UART_FIFO_EN=1,
}UART_FIFO_OP;

#define Min(a,b) ((a)>(b)?(b):(a))



#define UARTStableTime	0x2000

UINT8 DbgLogTaskBuf[64];
#define DbgLogCnt	64
#define DbgAryCnt	2
UINT8 DbgLogBuf[DbgLogCnt][128];
UINT8 DbgAryBuf[DbgAryCnt][4096];
UINT32 DbgLogCur=0;
UINT32 DbgAryCur=0;





#if 1
#define DbgBufSize (0x400*64)
UINT8 DbgBuf[DbgBufSize];
#else
#define DbgBufSize 0x200000
UINT8 *DbgBuf=(UINT8*)0x07000000;
#endif

dfifo_t DbgFifo;
static volatile UINT32 DbgUartInitd=0;
static volatile UINT32 DbgFifoInitd=0;

extern unsigned int EEHandlerFlag;
extern unsigned int rtidisableInterrupts(void);
extern void rtirestoreInterrupts(unsigned int ir);

UINT32 DbgStopFlag=0;
UINT32 DbgType=2;

UINT32 DbgSwitchFlagAry[9]={0x11223344, 0x55667788, 0x88776655, 0x44332211, 2, 0x12345678, 0x87654321, 0xA5A5A5A5, 0x5A5A5A5A};

inline void dfifo_init(dfifo_t *fifo, UINT8 *buf, UINT32 size)
{
	fifo->buf=buf;
	fifo->size=size;
	fifo->in=0;
	fifo->out=0;
	fifo->cnt=0;
}

inline UINT32 dfifo_put(dfifo_t *fifo, UINT8 *buf, UINT32 len)
{
	UINT32 ret;
	UINT32 val;

	if(DbgType==1)
	{

		val=fifo->size-fifo->cnt;
		ret=(val>=len)?len:val;
		fifo->cnt+=ret;
		val=fifo->size-1-fifo->in;
		if(val>=ret)
		{
			memcpy(fifo->buf+fifo->in+1,buf,ret);
			fifo->in+=ret;
		}
		else
		{
			memcpy(fifo->buf+fifo->in+1,buf,val);
			memcpy(fifo->buf,buf+val,ret-val);
			fifo->in=ret-val-1;
		}
		return ret;
	}
	else if(DbgType==2)
	{
		val=fifo->size-1-fifo->in;

		if(val>=len)
		{
			memcpy(fifo->buf+fifo->in+1,buf,len);
			fifo->in+=len;
		}
		else
		{
			memcpy(fifo->buf+fifo->in+1,buf,val);
			memcpy(fifo->buf,buf+val,len-val);
			fifo->in=len-val-1;
		}
		return len;

	}
	else
		return len;
}

inline UINT32 dfifo_get(dfifo_t *fifo, UINT8 *buf, UINT32 len)
{
	UINT32 ret;
	UINT32 val;

	ret=(fifo->cnt>=len)?len:fifo->cnt;
	fifo->cnt-=ret;
	val=fifo->size-fifo->out-1;
	if(val>=ret)
	{
		memcpy(buf,fifo->buf+fifo->out+1,ret);
		fifo->out+=ret;
	}
	else
	{
		memcpy(buf,fifo->buf+fifo->out+1,val);
		memcpy(buf+val,fifo->buf,ret-val);
		fifo->out=ret-val-1;
	}
	return ret;
}


inline UINT32 dfifo_cnt(dfifo_t *fifo)
{
	return fifo->cnt;
}

void loop_delay(UINT32 n)
{
	volatile UINT32 i;
	for(i=0;i<n;i++)
		;

}

void DbgInitUart(UINT32 fifoEn)
{
	seagull_uart_init();
	DbgUartInitd=1;
}

UINT32 DbgGetType(void)
{
	return DbgType;
}

void DbgInitFifo(void)
{
	extern UINT32 nvm_tfs_fat_check_assert_flag;
	extern UINT32 nvm_tfs_fat_check_detail_log;


	if(DbgSwitchFlagAry[4]==0x2)
	{
		DbgType=2;
	}
	else if(DbgSwitchFlagAry[4]==0x1)
	{
		DbgType=1;
	}
	else if(DbgSwitchFlagAry[4]==0x3)
	{
		DbgType=1;
		nvm_tfs_fat_check_assert_flag=1;
		nvm_tfs_fat_check_detail_log=0;
	}
	else if(DbgSwitchFlagAry[4]==0x4)
	{
		DbgType=2;
		nvm_tfs_fat_check_assert_flag=1;
		nvm_tfs_fat_check_detail_log=0;
	}
	else if(DbgSwitchFlagAry[4]==0x5)
	{
		DbgType=1;
		nvm_tfs_fat_check_assert_flag=1;
		nvm_tfs_fat_check_detail_log=1;
	}
	else if(DbgSwitchFlagAry[4]==0x6)
	{
		DbgType=2;
		nvm_tfs_fat_check_assert_flag=1;
		nvm_tfs_fat_check_detail_log=1;
	}




	dfifo_init(&DbgFifo,DbgBuf,DbgBufSize);
	DbgFifoInitd=1;
}

void DbgEnableUart(void)
{
	extern unsigned long PMEnableSleep;

	if(DbgUartInitd==1)
		return;

	if(timerCountRead(TS_TIMER_ID)>UARTStableTime)
	{
		PMEnableSleep=0;
		DbgInitUart(UART_FIFO_EN);
	}
}

#define SEAGULL_UART_BASE   0xd4017000


UINT32 DbgLogTask(void)
{
	UINT32 len;
	UINT32 i;
	volatile unsigned long* ualsr=(volatile unsigned long*)(SEAGULL_UART_BASE + 0x14);
	volatile unsigned long* uathr=(volatile unsigned long*)(SEAGULL_UART_BASE);



	if((DbgUartInitd==0)||(DbgFifoInitd==0))
		return 0xFFFF;

	if((*ualsr & 0x40)==0x40)
	{
		len=dfifo_get(&DbgFifo,DbgLogTaskBuf,64);
		for(i=0;i<len;i++)
			*uathr = *(DbgLogTaskBuf+i);
	}
	else
		return 0xFFFF;


	return len;
}

void DbgPut(UINT8* src, UINT32 len)
{
	volatile unsigned long* ualsr=(volatile unsigned long*)(SEAGULL_UART_BASE + 0x14);
	volatile unsigned long* uathr=(volatile unsigned long*)(SEAGULL_UART_BASE);
	UINT32 i;

	if(DbgUartInitd==0)
		return;

	for(i=0;i<len;i++)
	{
		while (!(*ualsr & 0x20))
			;
		*uathr = *(src+i);
	}
}

void LogFlush(void)
{
	if(DbgType==1)
	{
		if(DbgUartInitd==0)
			DbgInitUart(1);
		while(DbgLogTask()!=0)
			;
	}
}


void DbgPrintf(char* fmt, ...)
{

}


void qspi_printf(char* fmt, ...)
{
#if 1
	UINT32 len;
	UINT32 cpsr;
	va_list ArgP;
	UINT8 *pbuf;
	UINT32 count;

//	if(DbgStopFlag==1)
//		return;

	cpsr=rtidisableInterrupts();
	pbuf=DbgLogBuf[DbgLogCur];
	DbgLogCur++;
	if(DbgLogCur==DbgLogCnt)
		DbgLogCur=0;
	rtirestoreInterrupts(cpsr);

	va_start(ArgP,fmt);
	len=vsprintf((char*)pbuf,fmt,ArgP);
	va_end(ArgP);


	if(DbgType==1)
	{
		DbgPut(pbuf,len);
	}
	else
	{
		if(DbgFifoInitd==0)
		{
			return;
		}

		cpsr=rtidisableInterrupts();
		count=dfifo_put(&DbgFifo,pbuf,len);
		if(count!=len)
			DbgStopFlag=1;
		rtirestoreInterrupts(cpsr);

	}

#if 0

	if(EEHandlerFlag==0)
	{
		if(DbgFifoInitd==0)
		{
			return;
		}

		cpsr=rtidisableInterrupts();
		count=dfifo_put(&DbgFifo,pbuf,len);
		if(count!=len)
			DbgStopFlag=1;
		rtirestoreInterrupts(cpsr);

	}
	else
	{
		DbgPut(pbuf,len);
	}

#endif

#endif
	/*coverity[missing_va_end]*/
}


void DbgPutChar(UINT8* src, UINT32 len)
{
	volatile unsigned long* ualsr=(volatile unsigned long*)(SEAGULL_UART_BASE + 0x14);
	volatile unsigned long* uathr=(volatile unsigned long*)(SEAGULL_UART_BASE);
	UINT32 i;

	for(i=0;i<len;i++)
	{
		while (!(*ualsr & 0x20))
			;
		if(*(src+i)!=0)
			*uathr = *(src+i);
		else
			return;
	}
}


void DbgShow(void)
{
	UINT8 *p;
	UINT32 cur;
	UINT32 size;

	if(DbgType==2)
	{
		p=DbgFifo.buf;
		cur=DbgFifo.in+1;
		if(cur==DbgFifo.size)
			cur=0;
		size=DbgFifo.size;
		DbgPutChar(p+cur, size-cur);
		DbgPutChar(p, cur);
	}
}





void nvm_printf(char* fmt, ...)
{}


void DbgLog(char* fmt, ...)
{
	UINT32 len;
	UINT32 cpsr;
	va_list ArgP;
	UINT8 *pbuf;

	cpsr=rtidisableInterrupts();
	pbuf=DbgLogBuf[DbgLogCur];
	DbgLogCur++;
	if(DbgLogCur==DbgLogCnt)
		DbgLogCur=0;
	rtirestoreInterrupts(cpsr);

	va_start(ArgP,fmt);
	len=vsprintf((char*)pbuf,fmt,ArgP);
	va_end(ArgP);

	DbgPut(pbuf,len);
	/*coverity[missing_va_end]*/
}

void DbgArrayPrintf(UINT8* ptr, UINT32 len)
{
#if 0
	va_list ArgP;
	UINT32 cnt,i,j;
	UINT8 *p=ptr;
	UINT32 cpsr;
	UINT8* pbuf;

//	if(DbgStopFlag==1)
//		return;

	cnt=len>>10;

	for(i=0;i<cnt;i++)
	{
		cpsr=rtidisableInterrupts();
		pbuf=DbgAryBuf[DbgAryCur];
		DbgAryCur++;
		if(DbgAryCur==DbgAryCnt)
			DbgAryCur=0;
		rtirestoreInterrupts(cpsr);

		for(j=0;j<1024;j++)
			sprintf((char*)(pbuf+4*j),"%02x, ",*p++);

		if(EEHandlerFlag==0)
		{
			if(DbgFifoInitd==0)
				return;
			cpsr=rtidisableInterrupts();
			dfifo_put(&DbgFifo,pbuf,4096);
			rtirestoreInterrupts(cpsr);
		}
		else
		{
			DbgPut(pbuf,4096);
		}
		len-=1024;
	}
	if(len!=0)
	{
		cpsr=rtidisableInterrupts();
		pbuf=DbgAryBuf[DbgAryCur];
		DbgAryCur++;
		if(DbgAryCur==DbgAryCnt)
			DbgAryCur=0;
		rtirestoreInterrupts(cpsr);

		for(j=0;j<len;j++)
			sprintf((char*)(pbuf+4*j),"%02x, ",*p++);

		if(EEHandlerFlag==0)
		{
			if(DbgFifoInitd==0)
				return;
			cpsr=rtidisableInterrupts();
			dfifo_put(&DbgFifo,pbuf,len*4);
			rtirestoreInterrupts(cpsr);
		}
		else
		{
			DbgPut(pbuf,len*4);
		}

	}

#endif
}

#else

/* log configuration. */
extern Log_ConfigS log_config;

UINT32 DbgGetType(void)
{

    if (log_config.log_cfg == LOG_DISABLE)
    {
        return 1;
    } 

	return 0;
}
void DbgPrintf(char* fmt, ...)
{
}

void DbgShow(void)
{
}
void DbgArrayPrintf(UINT8* ptr, UINT32 len)
{
}
UINT32 DbgLogTask(void)
{
	/*Fix coverity[missing_return]*/
	return 0;
}
void DbgInitFifo(void)
{
}
void DbgEnableUart(void)
{
}
void LogFlush(void)
{
}

void loop_delay(UINT32 n)
{
	volatile UINT32 i;
	for(i=0;i<n;i++)
		;

}
volatile UINT32 SEAGULL_UART_BASE_ADDR_diag = 0xd4018000;//The CP UART base address may vary between different board types.
void seagull_uart_init_diag()
{
	volatile unsigned long *r;

	{
		unsigned long uart_delay = 0xffff;
		while(uart_delay--);
	}

	// UALCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0xc);
	*r = 0x83;

	// UADLL
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0x0);
	*r = 84;


	// UADLH
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0x4);
	*r = 0;

	// UALCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0xC);
	*r &= ~0x80;

	// UAFCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0x8);
	*r = 0x07;

	// UAIER
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR_diag + 0x4);
	*r = 0x40;

}

void DbgInitUart(UINT32 fifoEn)
{

	seagull_uart_init_diag();

}

void qspi_printf(char* fmt, ...)
{

}

void nvm_printf(char* fmt, ...)
{
}


#endif

/*------------------------------------------UART END------------------------------------------*/


UINT32	GetDate(CHAR *StrDate)
{
	struct tm *time_m;
	time_t ctime;
	int date_y,date_m,date_d;
	int i;
	char tmpstr[5];
	int rc;
	char *month[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

	// convert first 2 char to day in month
	memcpy(tmpstr,(char *)StrDate,2);
	tmpstr[2]=0;
	date_d = atoi(tmpstr);

	// convert next 3 char to month
	memcpy(tmpstr,(char *)&StrDate[2],3);
	tmpstr[3] = 0;
	for (i=0; i<12; i++)
	{
		rc = strcmp(month[i], tmpstr);
		if (rc == 0)
			break;
	}
	date_m = i;
	// convert last 4 char to year
	date_y = atoi((char *)&StrDate[5]);

//	time(&ctime);
	time_m = localtime ( &ctime );
	// Fill in time_t sturture with input date.
	time_m->tm_year = date_y - 1900;
	time_m->tm_mon = date_m;
	time_m->tm_mday = date_d;

	time_m->tm_hour = 0;
	time_m->tm_min = 0;
	time_m->tm_sec = 0;
	time_m->tm_isdst = 0;
	//time_m->tm_wday
	//time_m->tm_yday
	ctime = mktime(time_m);
	return (ctime);
}



void date_to_utc(char* buf, UINT32 date)
{
	UINT32 lDate;
	lDate=date;
	strncpy(buf, ctime((time_t *)&lDate),24);
	buf[24]=0;
}
extern void TriggerWatchdogTimeout(void);

#ifdef MEMLOG_ENABLE
extern void log_set_output(void *parameter);
#endif
#ifndef CRANE_MCU_DONGLE
//extern void sector_timeout_add(UINT32 sec);

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,RemapTest
void RemapTest(void)
{
#if 0
	sector_timeout_add(0);
	sector_timeout_add(1);
#endif
	ASSERT(0);
}




//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,set_1x_drx
void set_1x_drx(void)
{
	DIAG_FILTER(HW_PLAT, utilities, set_1x_drx, DIAG_INFORMATION)
	diagPrintf("set_1x_drx");

	rrDsChangePagingDrxLength(1);
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,set_2x_drx
void set_2x_drx(void)
{
	DIAG_FILTER(HW_PLAT, utilities, set_2x_drx, DIAG_INFORMATION)
	diagPrintf("set_2x_drx");

	rrDsChangePagingDrxLength(2);
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,set_4x_drx
void set_4x_drx(void)
{
	DIAG_FILTER(HW_PLAT, utilities, set_4x_drx, DIAG_INFORMATION)
	diagPrintf("set_4x_drx");

	rrDsChangePagingDrxLength(4);
}



#endif

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,WDTTest
void WDTTest(void)
{
	uart_printf("\r\nWDTTest\r\n");

	DIAG_FILTER(HW_PLAT, utilities, WDTTest, DIAG_INFORMATION)
	diagPrintf("WDTTest");

 	TriggerWatchdogTimeout();
}



//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,NVMFlashErase
void NVMFlashErase(void)
{
	unsigned int cpsr;

	CPUartLogPrintf("NVMFlashErase");

	cpsr = disableInterrupts();

#if defined(CRANE_MCU_DONGLE) && defined(LFS_FILE_SYS)
    lfs_erase_all();
#else
	qspi_sim_buf_erase_all();
#endif

	CPUartLogPrintf("NVMFlashErase done");

	while(1)
		;

}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,NVMErasePartition
void NVMErasePartition(void)
{
#if defined(CRANE_MCU_DONGLE) && defined(LFS_FILE_SYS)
	CPUartLogPrintf("NVMErasePartition, Caller 0x%x", __return_address());

    lfs_erase_partition();

	CPUartLogPrintf("NVMErasePartition done");
#endif
}

/*------------------------------------------UART END------------------------------------------*/

#define REG_APBC_GPIO_CLK_RST	0xD4015008
#define REG_GPIO_0_PLR	0xD4019000
#define REG_GPIO_1_PLR	0xD4019004
#define REG_GPIO_2_PLR	0xD4019008
#define REG_GPIO_3_PLR	0xD4019100
#define REG_GPIO_0_PDR	0xD401900C
#define REG_GPIO_1_PDR	0xD4019010
#define REG_GPIO_2_PDR	0xD4019014
#define REG_GPIO_3_PDR	0xD401910C
#define REG_GPIO_0_PSR	0xD4019018
#define REG_GPIO_1_PSR	0xD401901C
#define REG_GPIO_2_PSR	0xD4019020
#define REG_GPIO_3_PSR	0xD4019118
#define REG_GPIO_0_PCR	0xD4019024
#define REG_GPIO_1_PCR	0xD4019028
#define REG_GPIO_2_PCR	0xD401902C
#define REG_GPIO_3_PCR	0xD4019124

#define GPIO33_ADDERSS 0xD401e160
#define GPIO34_ADDERSS 0xD401e164
#define GPIO35_ADDERSS 0xD401e168
#define GPIO36_ADDERSS 0xD401e16C
#define GPIO50_ADDERSS 0xD401E1A4
#define GPIO54_ADDERSS 0xD401E1B4
#define GPIO124_ADDERSS 0xD401E0D0
void cp_clear_gpio_ed(UINT32 gpio);

UINT32 GetGpioGroup(UINT32 gpio)
{
	if(gpio<VSPI_GPIO_32)
		return 0;
	else if(gpio<VSPI_GPIO_64)
		return 1;
	else if(gpio<VSPI_GPIO_96)
		return 2;
	else if(gpio<=VSPI_GPIO_MAX)
		return 3;
	/*Fixed coverity[missing_return]*/
	else
	{
		ASSERT(0);
		return 0;
	}
}
void SetGpioLvl(UINT32 gpio, UINT32 lv)
{
	UINT32 PSRAddr[4]={REG_GPIO_0_PSR, REG_GPIO_1_PSR, REG_GPIO_2_PSR, REG_GPIO_3_PSR};
	UINT32 PCRAddr[4]={REG_GPIO_0_PCR, REG_GPIO_1_PCR, REG_GPIO_2_PCR, REG_GPIO_3_PCR};
	UINT32 i;
	i=GetGpioGroup(gpio);
	if(lv==1)
		HwdWrite32(PSRAddr[i],1<<(gpio-32*i));
	else
		HwdWrite32(PCRAddr[i],1<<(gpio-32*i));
}
UINT32 GetGpioLvl(UINT32 gpio)
{
	UINT32 RegAddr[4]={REG_GPIO_0_PLR, REG_GPIO_1_PLR, REG_GPIO_2_PLR, REG_GPIO_3_PLR};
	UINT32 val,i;
	i=GetGpioGroup(gpio);
	val=HwdRead32(RegAddr[i])&(1<<(gpio-32*i));
	if(val==0)
		return 0;
	else
		return 1;
}
void cp_init_gpio_ed(UINT32 gpio, void func(UINT32))
{
	UINT32 mfpr_addr = 0;
	UINT32 regval;
	if(gpio==33)
		mfpr_addr=GPIO33_ADDERSS;
	else if(gpio==34)
		mfpr_addr=GPIO34_ADDERSS;
	else if(gpio==35)
		mfpr_addr=GPIO35_ADDERSS;
	else if(gpio==36)
		mfpr_addr=GPIO36_ADDERSS;
	else if(gpio==50)
		mfpr_addr=GPIO50_ADDERSS;
	else if(gpio==54)
		mfpr_addr=GPIO54_ADDERSS;
	else if(gpio==124)
		mfpr_addr=GPIO124_ADDERSS;
	/*Fix coverity[uninit_use]*/
	else
		ASSERT(0);

	cp_clear_gpio_ed(gpio);
	regval = HwdRead32(mfpr_addr);
	HwdWrite32(mfpr_addr,regval | (1 << 4) | (1 << 13) & ~(1 << 14));
}

void cp_clear_gpio_ed(UINT32 gpio)
{
	UINT32 mfpr_addr = 0;
	UINT32 regval;
	if(gpio==33)
		mfpr_addr=GPIO33_ADDERSS;
	else if(gpio==34)
		mfpr_addr=GPIO34_ADDERSS;
	else if(gpio==35)
		mfpr_addr=GPIO35_ADDERSS;
	else if(gpio==36)
		mfpr_addr=GPIO36_ADDERSS;
	else if(gpio==50)
		mfpr_addr=GPIO50_ADDERSS;
	else if(gpio==54)
		mfpr_addr=GPIO54_ADDERSS;
	else if(gpio==124)
		mfpr_addr=GPIO124_ADDERSS;
	/*Fix coverity[uninit_use]*/
	else
		ASSERT(0);

	regval = HwdRead32(mfpr_addr);
	HwdWrite32(mfpr_addr, regval | (1 << 6));
	regval = HwdRead32(mfpr_addr);
	HwdWrite32(mfpr_addr, regval & ~(1 << 6));
}
void cp_gpio_init(UINT32 gpio, UINT32 dir)
{
	UINT32 i;
	UINT32 mfpr_addr=0;
	UINT32 RegAddr[4]={REG_GPIO_0_PDR, REG_GPIO_1_PDR, REG_GPIO_2_PDR, REG_GPIO_3_PDR};
	if(gpio==33)
		mfpr_addr=GPIO33_ADDERSS;
	else if(gpio==34)
		mfpr_addr=GPIO34_ADDERSS;
	else if(gpio==35)
		mfpr_addr=GPIO35_ADDERSS;
	else if(gpio==36)
		mfpr_addr=GPIO36_ADDERSS;
	else if(gpio==50)
		mfpr_addr=GPIO50_ADDERSS;
	else if(gpio==54)
		mfpr_addr=GPIO54_ADDERSS;
	else if(gpio==124)
		mfpr_addr=GPIO124_ADDERSS;
	i=GetGpioGroup(gpio);
	HwdWrite32(mfpr_addr,0xD0C0);
	if(dir==1)
		HwdWrite32(RegAddr[i],HwdRead32(RegAddr[i])|(1<<(gpio-32*i)));
	else
		HwdWrite32(RegAddr[i],HwdRead32(RegAddr[i])&(~(1<<(gpio-32*i))));
}

void hsic_pm_gpio_setting(void)
{
	HwdWrite32(0xD401E164,0xD090);
	if(HwdRead32(0xD401E164)!=0xD090)
		ASSERT(0);
}


/*------------------------------------------RTICFG START------------------------------------------*/

#if defined (INTEL_FDI)

#include "FDI_EXT.h"
#include "FDI_FILE.h"
#include "FDI_ERR.h"
#include "nvm_header.h"

#define RTI_NVM_VERSION	"1.0"
#define NVM_HEAD_SET_STRING(header,field,value) strncpy(header.field,value,sizeof(header.field)-1)

RTICfg_t rtiConfig=
{
	RTI_EN_VER1,
	RTI_QUE_DISABLE,
	RTI_EVT_DISABLE,

	0, 					/* disable RTI change in different CPU usage */
	35,
	55,

	1, 					/* enable Running Mode change */
	40,
	65,
	TIME_OUT_6MS
};

static BOOL rtiWriteNvmHeader(FILE_ID fdiID)
{
	NVM_Header_ts header;
	UINT32 ret;

	FDI_fseek(fdiID,0,SEEK_SET);
	header.StructSize = sizeof(RTICfg_t);
	header.NumofStructs = 1;
	NVM_HEAD_SET_STRING(header,StructName,"RTICfg_t");
	NVM_HEAD_SET_STRING(header,Date,"");
	NVM_HEAD_SET_STRING(header,time,"");
	NVM_HEAD_SET_STRING(header,Version,  RTI_NVM_VERSION);
	NVM_HEAD_SET_STRING(header,HW_ID,"");
	NVM_HEAD_SET_STRING(header,CalibVersion,"");
	ret=FDI_fwrite(&header,sizeof(NVM_Header_ts),1,fdiID);
	if(ret!=1)
		return FALSE;
	return TRUE;
}
void GetRTISetting(int *enable, int *ht, int *lt)
{
	*enable = rtiConfig.rtiChange;
	*ht = rtiConfig.rtiHT;
	*lt = rtiConfig.rtiLT;
}

void GetModeSetting(int *enable, int *ht, int *lt)
{
	*enable = rtiConfig.modeChange;
	*ht = rtiConfig.modeHT;
	*lt = rtiConfig.modeLT;
}

//ICAT EXPORTED FUNCTION - SW_PLAT, utilities, DisableModeChange
void DisableModeChange(void)
{
    rtiConfig.modeChange = 0;
	DIAG_FILTER(SW_PLAT, utilities, DisableModeChange, DIAG_INFORMATION)
	diagPrintf ("DisableModeChange.");
}

//ICAT EXPORTED FUNCTION - SW_PLAT, utilities, EnableModeChange
void EnableModeChange(void)
{
    rtiConfig.modeChange = 1;
	DIAG_FILTER(SW_PLAT, utilities, EnableModeChange, DIAG_INFORMATION)
	diagPrintf ("EnableModeChange.");
}

#endif

/*------------------------------------------RTICFG END------------------------------------------*/


/*------------------------------------------RTI START------------------------------------------*/

typedef enum
{
	rt_ThreadSwitch=0,
	rt_ICUSwitch,
	rt_XIRQSwitch,
	rt_DisableInt,
	rt_EnableInt,
	rt_RestoreInt,
	rt_SendToQueue,
	rt_SendToQueueRet,
	rt_ReceiveFromQueue,
	rt_ReceiveFromQueueRet,
	rt_SetEvent,
	rt_SetEventRet,
	rt_GetEvent,
	rt_GetEventRet,
	rt_MaxType,
	rt_Printf,
	rt_TimeTest
}rti_info_type;

#define RTI_BUF_SIZE (128*16)

#define rt_ThreadSwitch_len	13
#define rt_ICUSwitch_len	6
#define rt_XIRQSwitch_len	6
#define rt_DisableInt_len	6
#define rt_EnableInt_len	6
#define rt_RestoreInt_len	6
#define rt_SendToQueue_len	17
#define rt_SendToQueueRet_len	6
#define rt_ReceiveFromQueue_len	5
#define rt_ReceiveFromQueueRet_len	18
#define rt_SetEvent_len	9
#define rt_SetEventRet_len	9
#define rt_GetEvent_len	9
#define rt_GetEventRet_len	10


UINT32 ItemLen[rt_MaxType]=
{
	rt_ThreadSwitch_len,
	rt_ICUSwitch_len,
	rt_XIRQSwitch_len,
	rt_DisableInt_len,
	rt_EnableInt_len,
	rt_RestoreInt_len,
	rt_SendToQueue_len,
	rt_SendToQueueRet_len,
	rt_ReceiveFromQueue_len,
	rt_ReceiveFromQueueRet_len,
	rt_SetEvent_len,
	rt_SetEventRet_len,
	rt_GetEvent_len,
	rt_GetEventRet_len,
};

static UINT32 GetItemLen(UINT32 pos)
{
#if 0
	UINT32 length;
	UINT8 i;
	UINT8 *rti_buf=(UINT8*)(rti_ptr->rti_rt_list);

	i=rti_buf[pos];

	if(i==rt_Printf)
	{
		if(pos==RTI_BUF_SIZE-1)
			return rti_buf[0]+2;
		else
			return rti_buf[pos+1]+2;
	}
	else if(i==rt_TimeTest)
	{
		if(pos==RTI_BUF_SIZE-1)
			return rti_buf[0];
		else
			return rti_buf[pos+1];
	}
	else
		return ItemLen[i];
#else
	/*Fixed coverity[missing_return]*/
	return 0;
#endif
}

static UINT32 rti_add_pos(UINT32 pos, UINT32 cnt)
{
#if 0
	if((RTI_BUF_SIZE-pos-1)>=cnt)
		return pos+cnt;
	else
		return cnt-(RTI_BUF_SIZE-pos);
#else
	/*Fixed coverity[missing_return]*/
	return 0;
#endif
}

static void rti_update_spos(UINT32 len)
{
#if 0
	UINT32 length;
	UINT8 i,j;
	UINT32 cnt;
	UINT8 *rti_buf=(UINT8*)(rti_ptr->rti_rt_list);

	if(rti_ptr->spos>rti_ptr->cpos)
		length=rti_ptr->spos-rti_ptr->cpos;
	else
		length=RTI_BUF_SIZE-(rti_ptr->cpos-rti_ptr->spos);

	while(length<=len)
	{
		cnt=GetItemLen(rti_ptr->spos);
		rti_ptr->spos=rti_add_pos(rti_ptr->spos, cnt);
		length+=cnt;
	}
#endif
}

static void rti_record(UINT8* buf, UINT32 len)
{
#if 0
	UINT32 i=rti_ptr->cpos;
	UINT32 j;
	UINT8 *rti_buf=(UINT8*)(rti_ptr->rti_rt_list);

	if(i>=RTI_BUF_SIZE)
		return;

	rti_update_spos(len);

	for(j=0;j<len;j++)
	{
		rti_buf[i]=*buf++;
		if(i==RTI_BUF_SIZE-1)
			i=0;
		else
			i++;
	}
	rti_ptr->cpos=rti_add_pos(rti_ptr->cpos, len);
#endif
}

void rti_SendQueue_record(VOID *queue_ptr, VOID *message)
{
#if 0
	if((rtiConfig.rtiType==RTI_EN_VER2)&&(rtiConfig.rtiQueType==RTI_QUE_ENABLE))
	{
	/*
		byte[1-4]=queue_ptr
		byte[5-16]=message
	*/
		UINT32 len=rt_SendToQueue_len;
		UINT8 buf[rt_SendToQueue_len];
		UINT32 val;
	    UINT32 cpsr;
		UINT32 *p32;
		UINT32 add;

		if(rti_thread_simple_mode && rti_thread_sm_inited)
		{
			buf[0]=rt_SendToQueue;
			val=(UINT32)queue_ptr;
			buf[1]=(val>>24)&0xFF;
			buf[2]=(val>>16)&0xFF;
			buf[3]=(val>>8)&0xFF;
			buf[4]=val&0xFF;
			val=*(UINT32*)message;
			buf[5]=(val>>24)&0xFF;
			buf[6]=(val>>16)&0xFF;
			buf[7]=(val>>8)&0xFF;
			buf[8]=val&0xFF;

			add=val&(~0x3);

			if((add>=0x07400000)&&(add<=(0x07A00000-32)))
			{
				p32=(UINT32*)add;
				val=*p32;
				buf[9]=(val>>24)&0xFF;
				buf[10]=(val>>16)&0xFF;
				buf[11]=(val>>8)&0xFF;
				buf[12]=val&0xFF;
				val=*(p32+6);
				buf[13]=(val>>24)&0xFF;
				buf[14]=(val>>16)&0xFF;
				buf[15]=(val>>8)&0xFF;
				buf[16]=val&0xFF;
			}
			else
			{
				buf[9]=0xA5;
				buf[10]=0xA5;
				buf[11]=0xA5;
				buf[12]=0xA5;
				buf[13]=0x5A;
				buf[14]=0x5A;
				buf[15]=0x5A;
				buf[16]=0x5A;
			}
			cpsr = rtidisableInterrupts();
			rti_record(buf, len);
			rtirestoreInterrupts(cpsr);
		}
	}
#endif
}


void rti_SetEvent_record(VOID *event_group_ptr, UINT32 events)
{
#if 0
	if((rtiConfig.rtiType==RTI_EN_VER2)&&(rtiConfig.rtiEvtType==RTI_EVT_ENABLE))
	{
	/*
		byte[1-4]=event_group_ptr
		byte[5-8]=events
	*/
		UINT32 len=rt_SetEvent_len;
		UINT8 buf[rt_SetEvent_len];
		UINT32 val;
		UINT32 cpsr;

		if(rti_thread_simple_mode && rti_thread_sm_inited)
		{
			buf[0]=rt_SetEvent;
			val=(UINT32)event_group_ptr;
			buf[1]=(val>>24)&0xFF;
			buf[2]=(val>>16)&0xFF;
			buf[3]=(val>>8)&0xFF;
			buf[4]=val&0xFF;
			val=events;
			buf[5]=(val>>24)&0xFF;
			buf[6]=(val>>16)&0xFF;
			buf[7]=(val>>8)&0xFF;
			buf[8]=val&0xFF;
			cpsr = rtidisableInterrupts();
			rti_record(buf, len);
			rtirestoreInterrupts(cpsr);
		}
	}
#endif
}

void rti_printf(char *Fmt, ...)
{
#if 0
	if(rtiConfig.rtiType==RTI_EN_VER2)
	{
	/*
		byte[1]=len
		byte[2-X]=data
	*/
		UINT32 len;
		char buf[256+2];
		UINT32 cpsr;

		if(rti_thread_simple_mode && rti_thread_sm_inited)
		{
			va_list ArgP;
			va_start(ArgP, Fmt);
			len=vsprintf(buf+2, Fmt, ArgP);
			va_end(ArgP);
			len=strlen(buf+2);
			buf[0]=rt_Printf;
			buf[1]=len;
			cpsr = rtidisableInterrupts();
			rti_record((UINT8*)buf, len+2);
			rtirestoreInterrupts(cpsr);
		}
	}
#endif
}


void rti_diag_caller(UINT32 val)
{
	if(rti_enable)
		rti_ptr->diag_call_func=val;
}

void rti_pm_sleep_time(UINT32 val)
{
	if(rti_enable)
		rti_ptr->sleep_time=val;
}

void rti_pm_sleep_state(UINT32 val)
{
	if(rti_enable)
		rti_ptr->sleep_state=val;
}

void rti_pm_sleep_step(UINT32 val)
{
	if(rti_enable)
		rti_ptr->sleep_step=val;
}

void rti_set_wakeupBits(UINT32 val)
{
	if(rti_enable)
		rti_ptr->wakeupBits=val;
}

void rti_set_CPMnewPowerState(UINT32 val)
{
	if(rti_enable)
		rti_ptr->CPMnewPowerState=val;
}

/*===========================================================================

FUNCTION rti_init_mode

DESCRIPTION
  This function init current RTI mode.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None

===========================================================================*/
void rti_init_mode(void)
{
	rti_mode_info *pMode = (rti_mode_info *)(&rtiModeInfo);

	rti_current_mode = pMode->mode;
}

/*------------------------------------------RTI END------------------------------------------*/

UINT32 *rti_ipclr_ptr=&(rti_rt.ipc_lr);

#if 0
#define INTC_DEBUG_RECORD_MAX_COUNT 	128
static UINT32 gIntcTimeStampDgb[128][2];
static UINT8 gIntcDgbCount = 0;
#endif

extern UINT32 gNuTickDelayOwner;










#pragma push

/* we use ARM instruction for switch information collection */

#pragma arm section code="RTI_SWITCH"


//#define RTI_SWITCH_CHECK
void rti_switch_check_data(UINT8 checkPoint)
{

	#ifdef RTI_SWITCH_CHECK
	if(initState >= BSP_INIT_TASK_FINISH)
	{
		gCheckPoint = checkPoint;

	}
	#endif
	return ;
}

/*===========================================================================
FUNCTION rti_timer_switch_to

DESCRIPTION
  None.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS

===========================================================================*/
void rti_timer_switch_to(unsigned long routine)
{
	if (rti_enable)
    {

	    UINT32 cpsr;
	    unsigned char *sp_list;

        cpsr = disableInterrupts();

		rti_rt.rti_rt_cnt++;

		if (rti_rt.rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE)
		{
		    rti_rt.rti_rt_cnt = 0;
        }

		sp_list = rti_rt.rti_rt_list[rti_rt.rti_rt_cnt].task_info;

		*sp_list	   = 'T';
		*(sp_list + 1) = 'I';
		*(sp_list + 2) = 'M';
		*(sp_list + 3) = ':';
		*(sp_list + 4) = hex_num_str[(routine >> 28) & 0xF];
		*(sp_list + 5) = hex_num_str[(routine >> 24) & 0xF];
		*(sp_list + 6) = hex_num_str[(routine >> 20) & 0xF];
		*(sp_list + 7) = hex_num_str[(routine >> 16) & 0xF];
		*(sp_list + 8) = hex_num_str[(routine >> 12) & 0xF];
		*(sp_list + 9) = hex_num_str[(routine >> 8) & 0xF];
		*(sp_list + 10) = hex_num_str[(routine >> 4) & 0xF];
		*(sp_list + 11) = hex_num_str[routine & 0xF];

		*(rti_uint32_t *)(sp_list + 12) = timerCountRead(TS_TIMER_ID);

        restoreInterrupts(cpsr);

    }
}

/*===========================================================================
FUNCTION rti_record_line

DESCRIPTION
  None.

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS

===========================================================================*/
void rti_record_line(const char *string, unsigned int line)
{
    if (rti_enable)
    {
        UINT32 cpsr;
        unsigned char *sp_list;

        cpsr = disableInterrupts();

        rti_rt.rti_rt_cnt++;

        if (rti_rt.rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE)
        {
            rti_rt.rti_rt_cnt = 0;
        }

        sp_list = rti_rt.rti_rt_list[rti_rt.rti_rt_cnt].task_info;

        *sp_list       = string[0];
        *(sp_list + 1) = string[1];
        *(sp_list + 2) = string[2];
        *(sp_list + 3) = ':';
        *(sp_list + 4) = hex_num_str[(line >> 28) & 0xF];
        *(sp_list + 5) = hex_num_str[(line >> 24) & 0xF];
        *(sp_list + 6) = hex_num_str[(line >> 20) & 0xF];
        *(sp_list + 7) = hex_num_str[(line >> 16) & 0xF];
        *(sp_list + 8) = hex_num_str[(line >> 12) & 0xF];
        *(sp_list + 9) = hex_num_str[(line >> 8) & 0xF];
        *(sp_list + 10) = hex_num_str[(line >> 4) & 0xF];
        *(sp_list + 11) = hex_num_str[line & 0xF];

        *(rti_uint32_t *)(sp_list + 12) = timerCountRead(TS_TIMER_ID);

        restoreInterrupts(cpsr);

    }
}


void rti_thread_timeout_record(rti_uint32_t *sp_list, UINT32 CurrentTicks)
{
    UINT32 name[2];
    UINT32 tick_to = 0, UsedTicks = 0;
    UINT8 *pSpInfo = (UINT8 *)sp_list;

    name[0] = *(sp_list + 1);
    name[1] = *(sp_list + 2);
    tick_to = *(sp_list + 3);

    if((name[0] != 0x6D6D6F43) && (name[1] != 0x4C5F4D50) && (tick_to != 0))
    {
        if (CurrentTicks < tick_to)
        {
            UsedTicks = CurrentTicks + (0xFFFFFFFF - tick_to);
        }
        else
        {
            UsedTicks = CurrentTicks - tick_to;
        }

        if (UsedTicks >= rtiConfig.Timeout)
        {
            memcpy(rti_thread_timeout[rti_thread_timeout_index].task, pSpInfo + 2, 10);
            rti_thread_timeout[rti_thread_timeout_index].task[10]   = 0x00;
            rti_thread_timeout[rti_thread_timeout_index].tick_to    = tick_to;
            rti_thread_timeout[rti_thread_timeout_index].tick_out   = CurrentTicks;
            rti_thread_timeout_index++;

            if (rti_thread_timeout_index >= RTI_THREAD_TIMEOUT_SIZE)
            {
                rti_thread_timeout_index = 0;
            }
        }
    }
}

void rti_icu_switch_to(unsigned long isrSource)
{
#if 0
	gIntcTimeStampDgb[gIntcDgbCount][0] = timerCountRead(TS_TIMER_ID);
	gIntcTimeStampDgb[gIntcDgbCount][1] = isrSource;
	gIntcDgbCount++;
	if(gIntcDgbCount >= INTC_DEBUG_RECORD_MAX_COUNT)
	{
		gIntcDgbCount = 0;
	}
#endif

	DbgLogTask();
	if (rti_enable)
	{
		rti_uint32_t *sp_list;
		rti_uint32_t index;
        rti_uint32_t *last_sp_list = NULL;
		rti_uint32_t current_tick = timerCountRead(TS_TIMER_ID);

        if(rti_ptr->rti_rt_cnt < RTI_SWITCH_ARRAY_SIZE)
        {
		    last_sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[rti_ptr->rti_rt_cnt].task_info;
		    rti_thread_timeout_record(last_sp_list, current_tick);
		}

		rti_ptr->rti_rt_cnt++;
		if (rti_ptr->rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE) rti_ptr->rti_rt_cnt = 0;

		index = rti_ptr->rti_rt_cnt;

		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;

		*sp_list =
			(hex_num_str[(index >> 4) & 0xF]) |
			(hex_num_str[index & 0xF] << 8) |
			('I' << 16) | (':' << 24);

		*(sp_list + 1) =
			(hex_num_str[(isrSource >> 4) & 0xF]) |
			(hex_num_str[isrSource & 0xF] << 8);
		*(sp_list + 2) = 0;
		*(sp_list + 3) = current_tick;
	}
	rti_switch_check_data(4);
}

#if defined(LTEONLY_8M8M) || defined(LTEONLY_THIN)
void rti_dump_ipc_lisr(UINT32 total_cnt, UINT32 r_index)
{
#if 0
	DbgLogTask();
	if (rti_enable)
	{
		rti_uint32_t *sp_list;
		rti_uint32_t index;

		p_long_rti_rt->rti_rt_cnt++;
		if (p_long_rti_rt->rti_rt_cnt >= LONG_RTI_SWITCH_ARRAY_SIZE)
			p_long_rti_rt->rti_rt_cnt = 0;

		index = p_long_rti_rt->rti_rt_cnt;

		sp_list = (rti_uint32_t*)p_long_rti_rt->rti_rt_list[index].task_info;

		*sp_list =
			(hex_num_str[(index >> 4) & 0xF]) |
			(hex_num_str[index & 0xF] << 8) |
			('L' << 16) | (':' << 24);

		*(sp_list + 1) = total_cnt;
		*(sp_list + 2) = r_index;
		*(sp_list + 3) = timerCountRead(TS_TIMER_ID);


	}
#endif
}


void rti_dump_ipc_hisr(UINT32 opcode, UINT32 length)
{
#if 0

	DbgLogTask();
	if (rti_enable)
	{
		rti_uint32_t *sp_list;
		rti_uint32_t index;

		p_long_rti_rt->rti_rt_cnt++;
		if (p_long_rti_rt->rti_rt_cnt >= LONG_RTI_SWITCH_ARRAY_SIZE)
			p_long_rti_rt->rti_rt_cnt = 0;

		index = p_long_rti_rt->rti_rt_cnt;

		sp_list = (rti_uint32_t*)p_long_rti_rt->rti_rt_list[index].task_info;

		*sp_list =
			(hex_num_str[(index >> 4) & 0xF]) |
			(hex_num_str[index & 0xF] << 8) |
			('H' << 16) | (':' << 24);

		*(sp_list + 1) = opcode;
		*(sp_list + 2) = length;
		*(sp_list + 3) = timerCountRead(TS_TIMER_ID);


	}
#endif
}
#endif


/* NUM_SWI:16, NUM_RI: 8, NUM_XSWI: 1, NUM_EIRQ: 3 */
void rti_xirq_switch_to(unsigned long isrSource)
{
#if 0
	gIntcTimeStampDgb[gIntcDgbCount][0] = timerCountRead(TS_TIMER_ID);
	gIntcTimeStampDgb[gIntcDgbCount][1] = isrSource | (0x1<<31);
	gIntcDgbCount++;
	if(gIntcDgbCount >= INTC_DEBUG_RECORD_MAX_COUNT)
	{
		gIntcDgbCount = 0;
	}
#endif


//	gNuTickDelayOwner = isrSource | (0x1<<31);
	DbgLogTask();
	if (rti_enable)
	{
		rti_uint32_t *sp_list;
		rti_uint32_t index;
        rti_uint32_t *last_sp_list = NULL;
		rti_uint32_t current_tick = timerCountRead(TS_TIMER_ID);

        if(rti_ptr->rti_rt_cnt < RTI_SWITCH_ARRAY_SIZE)
        {
		    last_sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[rti_ptr->rti_rt_cnt].task_info;
		    rti_thread_timeout_record(last_sp_list, current_tick);
		}

		rti_ptr->rti_rt_cnt++;
		if (rti_ptr->rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE) rti_ptr->rti_rt_cnt = 0;
		index = rti_ptr->rti_rt_cnt;

		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;

		*sp_list =
			(hex_num_str[(index >> 4) & 0xF]) |
			(hex_num_str[index & 0xF] << 8) |
			('X' << 16) | (':' << 24);

		*(sp_list + 1) =
			(hex_num_str[(isrSource >> 4) & 0xF]) |
			(hex_num_str[isrSource & 0xF] << 8);
		*(sp_list + 2) = 0;
		*(sp_list + 3) = current_tick;
	}

	rti_switch_check_data(3);
}

#if 0
UINT32 task_info_debug[16];
UINT32 task_ts_debug[16];
UINT32 task_cnt_debug = 0;
#endif

void rti_thread_switch_to(struct rti_thread_item* thread)
{
	DbgLogTask();
	gNuTickDelayOwner = (UINT32)thread->tid;
	if (rti_enable)
	{
		rti_uint32_t *sp_list = NULL;
		rti_uint32_t *last_sp_list = NULL;
		rti_uint32_t index;
		rti_uint32_t current_tick = timerCountRead(TS_TIMER_ID);

        if(rti_ptr->rti_rt_cnt < RTI_SWITCH_ARRAY_SIZE)
        {
		    last_sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[rti_ptr->rti_rt_cnt].task_info;
		    rti_thread_timeout_record(last_sp_list, current_tick);
		}

		rti_ptr->rti_rt_cnt++;
		if (rti_ptr->rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE) rti_ptr->rti_rt_cnt = 0;

		index = rti_ptr->rti_rt_cnt;

		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;

		*sp_list =
			(hex_num_str[(index >> 4) & 0xF]) |
			(hex_num_str[index & 0xF] << 8) |
			('T' << 16) | (':' << 24);
#ifdef PLAT_USE_THREADX
		*(sp_list + 1)  = *(unsigned long *)(thread->tid->tx_thread_name);
		*(sp_list + 2)  = *((unsigned long *)(thread->tid->tx_thread_name) + 1);
#elif PLAT_USE_ALIOS
		*(sp_list + 1)	= *(unsigned long *)(thread->tid->task_name);
		*(sp_list + 2)	= *((unsigned long *)(thread->tid->task_name) + 1);
#else
		*(sp_list + 1)  = *(unsigned long *)(thread->tid->tc_name);
		*(sp_list + 2)  = *((unsigned long *)(thread->tid->tc_name) + 1);
#endif
		*(sp_list + 3) = current_tick;

#if 0
	task_info_debug[task_cnt_debug] = (UINT32)thread->tid;
	task_ts_debug[task_cnt_debug] = *(sp_list + 3);
	task_cnt_debug++;
	if(task_cnt_debug == 16) task_cnt_debug = 0;

#endif

#ifndef PLAT_USE_ALIOS
	{
		UINT32 stack_magic, stack_magic_;

		stack_magic  = *(UINT32 *)(thread->tid->tx_thread_stack_start);
		stack_magic_ = *(UINT32 *)((UINT8 *)(thread->tid->tx_thread_stack_end) + 1);

        if(thread->tid->tx_thread_id != TX_THREAD_ID)
		{
			ASSERT_EXT(0, "Thread 0x%x, Invalid ID 0x%x", thread->tid, thread->tid->tx_thread_id);
		}

		if((stack_magic != 0xEFEFEFEF) || (stack_magic_ != 0xEFEFEFEF))
		{
			ASSERT_EXT(0, "stack of %s overflow", thread->tid->tx_thread_name);
		}
	}
#endif

	}

	if (rti_thread_enable)
	{
		thread->last_tick = RTI_CURRENT_TICK;
		thread->scheduled_count ++;
	}
}

void dump_task_info()
{
#if 0
	unsigned long i;
	rti_thread_t tid;
	UINT32 *ptr;

	uart_printf("\r\n=======================\r\n");
	for(i = 0; i < 16; i++)
	{
		tid = (rti_thread_t)task_info_debug[i];
		uart_printf("[0x%08x] %s\r\n", task_ts_debug[i], tid->tx_thread_name);
	}
	uart_printf("=======================\r\n");
	uart_printf("Stack Magic (start) 0x%x\r\n", *(UINT32 *)(RTI_THREAD_CURRENT->tx_thread_stack_start));
	uart_printf("Stack Magic (end)   0x%x\r\n", *(UINT32 *)((UINT8 *)(RTI_THREAD_CURRENT->tx_thread_stack_end) + 1));
	uart_printf("Stack Ptr 0x%x\r\n", (UINT32)(RTI_THREAD_CURRENT->tx_thread_stack_ptr));
	uart_printf("=======================\r\n");


	ptr = (UINT32 *)(RTI_THREAD_CURRENT->tx_thread_stack_ptr) - 32;
	for(i = 0; i < 64; i++)
	{
		if(!(i%4)) uart_printf("\r\n");
		uart_printf("%08x ", *(ptr - i));
	}
	uart_printf("\r\n");
	uart_printf("=======================\r\n");
#endif
}



void rti_thread_switch_out(struct rti_thread_item* thread)
{
	if(rti_enable && thread)
	{
		UINT32 stack_magic, stack_magic_;

#ifndef PLAT_USE_ALIOS
		stack_magic  = *(UINT32 *)(thread->tid->tx_thread_stack_start);
		stack_magic_ = *(UINT32 *)((UINT8 *)(thread->tid->tx_thread_stack_end) + 1);

        if(thread->tid->tx_thread_id != TX_THREAD_ID)
		{
			ASSERT_EXT(0, "Thread 0x%x, Invalid ID 0x%x", thread->tid, thread->tid->tx_thread_id);
		}

		if((stack_magic != 0xEFEFEFEF) || (stack_magic_ != 0xEFEFEFEF))
		{
		    ASSERT_EXT(0, "stack of %s overflow by itself", thread->tid->tx_thread_name);
		}
#endif

	}


	/* target insight is disable, return directly */
	if (!rti_thread_enable || !thread->last_tick) return;


	thread->tick_count += RTI_CURRENT_TICK - thread->last_tick;
	thread->last_tick = 0;
}
void switch_out(void)
{
	if (RTI_THREAD_CURRENT)
	{
		struct rti_thread_item* thread;

		thread = RTI_THREAD_ITEM(RTI_THREAD_CURRENT);

#ifdef PLAT_USE_ALIOS
		if(thread == NULL)
			return;
#endif

		rti_thread_switch_out(thread);
#ifdef PLAT_USE_ALIOS
		if (!strcmp(RTI_THREAD_CURRENT->task_name, "CommPM_L"))
#else
		if ((RTI_THREAD_CURRENT == commpmLPTRef))
#endif
		{
			rti_uint64_t tick;

			tick = RTI_CURRENT_TICK;

			/* calculate IDLE thread usage rate */
			idle_tick_count += (tick - idle_last_tick);
			idle_last_tick = 0;
			g_IDLE_times ++;
		}
		rti_switch_check_data(2);
            if(memory_flg  == 1) {
                check_all_address();
            }

	}
}

void switch_to(void)
{
	if (RTI_THREAD_CURRENT)
	{
		struct rti_thread_item* thread;

		thread = RTI_THREAD_ITEM(RTI_THREAD_CURRENT);
		rti_thread_switch_to(thread);
#ifdef PLAT_USE_ALIOS
		if (!strcmp(RTI_THREAD_CURRENT->task_name, "CommPM_L"))
#else
		if ((RTI_THREAD_CURRENT == commpmLPTRef))
#endif
		{
			idle_last_tick = RTI_CURRENT_TICK;
		}

		rti_switch_check_data(1);

	}
}

UINT32 isEnable_performance_count(void)
{
	return rti_thread_enable;
}


#pragma arm section code

#pragma pop

#ifndef PLAT_USE_ALIOS
TX_THREAD* task_list[128];
extern TX_THREAD *     _tx_thread_created_ptr;

UINT32 check_stack(UINT32 stack_start, UINT32 stack_size)
{
	UINT32 i, *ptr;
	ptr = (UINT32 *)stack_start;
	for(i = 0; i < (stack_size/4); i++)
	{
		if(*ptr != TX_STACK_FILL)
			return (UINT32)ptr;
		ptr++;
	}

	return (UINT32)ptr;
}
#endif

void dump_stack_info()
{
#ifndef PLAT_USE_ALIOS

	UINT32 stack_ptr, i, task_cnt = 0;
	TX_THREAD* tsk;


	i = 1;
	uart_printf("_tx_thread_created_ptr : 0x%x\r\n", _tx_thread_created_ptr);

	tsk = _tx_thread_created_ptr;

	do{
		uart_printf("=================================================\r\n");
		uart_printf("[%d] Task Name : %s\r\n", i, tsk->tx_thread_name);
		uart_printf("priority      : %d\r\n", tsk->tx_thread_priority);
		uart_printf("stack start   : 0x%x\r\n", tsk->tx_thread_stack_start);
		uart_printf("stack end     : 0x%x\r\n", tsk->tx_thread_stack_end);
		stack_ptr = check_stack((UINT32)tsk->tx_thread_stack_start, tsk->tx_thread_stack_size + 4);
		uart_printf("stack pointer : 0x%x\r\n", stack_ptr);
		uart_printf("stack size    : 0x%x\r\n", tsk->tx_thread_stack_size + 4);
		uart_printf("stack usage   : 0x%x\r\n", (UINT32)tsk->tx_thread_stack_end - stack_ptr);

		tsk = tsk->tx_thread_created_next;
		i++;

	}while(tsk != _tx_thread_created_ptr);


	uart_printf("=================================================\r\n");

#endif

#if 0
	task_cnt = OSATaskList(&task_list[0], 128);
	uart_printf("Task Count : %d\r\n", task_cnt);

	for(i = 0; i < task_cnt; i++)
	{
		tsk = task_list[i];
		uart_printf("[%d] Task Name : %s\r\n", i, tsk->tx_thread_name);
	}

#endif

}



void rti_set_enable(rti_uint32_t enable)
{
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;
	if (rti_enable != enable)
	{
		rti_uint32_t *sp_list;
		rti_uint32_t index;
		rti_enable = enable;

		rti_ptr->rti_rt_cnt++;
		if (rti_ptr->rti_rt_cnt >= RTI_SWITCH_ARRAY_SIZE) rti_ptr->rti_rt_cnt = 0;
		index = rti_ptr->rti_rt_cnt;

		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;

		if (rti_enable)
		{
			*sp_list =
					(hex_num_str[(index >> 4) & 0xF]) |
					(hex_num_str[index & 0xF] << 8) |
					('+' << 16) | (':' << 24);
			#ifdef PLAT_USE_ALIOS
			OsaSetDbgDisOpt(0);
			#endif
		}
		else
		{
			*sp_list =
					(hex_num_str[(index >> 4) & 0xF]) |
					(hex_num_str[index & 0xF] << 8) |
					('-' << 16) | (':' << 24);
			#ifdef PLAT_USE_ALIOS
			OsaSetDbgDisOpt(3);
			#endif
		}

		*(sp_list + 1)	= 0;
		*(sp_list + 2)	= 0;
		*(sp_list + 3) = timerCountRead(TS_TIMER_ID);
	}
	RTI_LOCK_ENABLE;
}

extern UINT32 PsShmTxIntcount;
static UINT32 rti_thread_total_int_count 	= 0;

void rti_thread_set_enable(rti_uint32_t enable)
{
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;

	if(rti_thread_enable==enable)
	{
		RTI_LOCK_ENABLE;
		return;
	}

	if (!enable)
	{
		/* target insight is disable, trigger current thread */
		rti_thread_switch_out(RTI_THREAD_ITEM(RTI_THREAD_CURRENT));

		/* update total tick */
		//uart_printf("End tick: %llu", rti_thread_total_tick);
		rti_thread_total_tick = RTI_CURRENT_TICK - rti_thread_total_tick;
		/* set thread enable */
		rti_thread_enable = enable;
		intc_tick_count = intc_tick - intc_tick_count;
#if 0
		rti_thread_total_int_count=PsShmTxIntcount;
#endif
	}
	else
	{
		UINT32 index;

		intc_tick = 0;
		intc_tick_count = 0;
		for (index = 0; index < RTI_THREAD_ARRAY_SIZE; index ++)
		{
			rti_thread_array[index].tick_count = 0;
			rti_thread_array[index].scheduled_count = 0;
		}

		/* set init total tick */
		rti_thread_total_tick = RTI_CURRENT_TICK;

		//uart_printf("Start tick: %llu", rti_thread_total_tick);

		/* set thread enable */
		rti_thread_enable = enable;
#if 0
		PsShmTxIntcount=0;
#endif
		/* switch to current thread */
		rti_thread_switch_to(RTI_THREAD_ITEM(RTI_THREAD_CURRENT));
	}
	RTI_LOCK_ENABLE;
}

#ifdef MEMLOG_ENABLE
//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,thread_dump_To_UART
void rti_thread_dump_To_UART(void)
{
	int OutPut;
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;
	OutPut=LOG_OUTPUT_UART;
	log_set_output(&OutPut);
	RTI_LOCK_ENABLE;
}
//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,thread_dump_To_ACAT
void rti_thread_dump_To_ACAT(void)
{
	int OutPut;
	RTI_LOCK_INIT;

	RTI_LOCK_DISABLE;
	OutPut=LOG_OUTPUT_ACAT;
	log_set_output(&OutPut);
	RTI_LOCK_ENABLE;
}
#endif

extern OSATaskRef commpmSuspTaskRef;
extern unsigned int EEHandlerFlag;

static void dump_printf(BOOL isUart,const char* fmt, ...)
{
	va_list ap;
	char buffer[128];

	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);


	if(isUart)
	{
		RTI_LOG("%s",buffer);
	}
	else
	{
		if (EEHandlerFlag==1)
			return ;

		DIAG_FILTER(HW_PLAT, utilities,diag_printf,DIAG_INFORMATION)
		diagPrintf("%s", buffer);
	}
   return;

}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,thread_dump
void rti_thread_dump(BOOL isUart)
{
	rti_uint32_t index;
	rti_uint64_t idle_tick = 0;
	char name[9];

	dump_printf(isUart,"commpmLPTRef:%lx, commpmSuspTaskRef:%lx\n", commpmLPTRef, commpmSuspTaskRef);
	dump_printf(isUart,"TotalTick: %llu\n", (rti_thread_total_tick));
	dump_printf(isUart,"priority,thread name, scheduled count, total run tick,percentage\n");

	for (index = 0; index < RTI_THREAD_ARRAY_SIZE; index ++)
	{
		/* remove unecessary information */
		if (rti_thread_array[index].tid==  NULL)
		{
			continue;
		}

		if (rti_thread_array[index].scheduled_count == 0) continue;
		if (RTI_THREAD_PRIORITY(rti_thread_array[index].tid) > 255) continue;

		memcpy(name, RTI_THREAD_NAME(rti_thread_array[index].tid), 8);
		name[8] = '\0';

		dump_printf(isUart,"%8d, %-8s, %8d, %10llu, %d%c\n",
			RTI_THREAD_PRIORITY(rti_thread_array[index].tid),
			name,
			rti_thread_array[index].scheduled_count,
			rti_thread_array[index].tick_count,
			(rti_thread_array[index].tick_count * 100)/rti_thread_total_tick,
			'%');


	//	if ((index + 1) % 10 == 0)
		//	RTI_THREAD_DELAY(5);

		if (rti_thread_array[index].tid == commpmLPTRef)
			idle_tick += rti_thread_array[index].tick_count;
		if (rti_thread_array[index].tid == commpmSuspTaskRef)
			idle_tick += rti_thread_array[index].tick_count;
	}

	dump_printf(isUart,"%8s, %-8s, %8s, %10llu, %d%c\n","N/A","INTC","N/A",intc_tick_count,(intc_tick_count*100)/rti_thread_total_tick,'%');

	dump_printf(isUart,"CPU IdleRate: %d%c\n",
		(idle_tick * 100)/rti_thread_total_tick,
		'%');


}


void rti_thread_dump_buf(char* buf)
{
	rti_uint32_t index;
	rti_uint64_t idle_tick = 0;
	char name[9];
	UINT32 buf_len=1024-128;

	*buf=0;

	sprintf(buf+strlen(buf),"commpmLPTRef:%lx, commpmSuspTaskRef:%lx\n", commpmLPTRef, commpmSuspTaskRef);
	sprintf(buf+strlen(buf),"TotalTick: %llu\n", (rti_thread_total_tick));
	sprintf(buf+strlen(buf),"thread name, scheduled count, total run tick\n");

	if(strlen(buf)>buf_len)
		return;

	for (index = 0; index < RTI_THREAD_ARRAY_SIZE; index ++)
	{
		/* remove unecessary information */
		if (rti_thread_array[index].tid== NULL)
		{
			continue;
		}

		if (rti_thread_array[index].scheduled_count == 0) continue;

		memcpy(name, RTI_THREAD_NAME(rti_thread_array[index].tid), 8);
		name[8] = '\0';


		sprintf(buf+strlen(buf),"%-8s, %8d, %10llu\n",
			name,
			rti_thread_array[index].scheduled_count,
			rti_thread_array[index].tick_count);


		if(strlen(buf)>buf_len)
		{
			DbgPrintf("buf len=%d\r\n",strlen(buf));
			return;
		}



		if ((index + 1) % 10 == 0)
			RTI_THREAD_DELAY(5);

		if (rti_thread_array[index].tid == commpmLPTRef)
			idle_tick += rti_thread_array[index].tick_count;
		if (rti_thread_array[index].tid == commpmSuspTaskRef)
			idle_tick += rti_thread_array[index].tick_count;
	}
	RTI_LOG("INTC, 0, %llu\n", intc_tick_count);

	sprintf(buf+strlen(buf),"INTC, 0, %llu\n", intc_tick_count);
	if(strlen(buf)>buf_len)
		return;

	sprintf(buf+strlen(buf),"CPU IdleRate: %f%c\n",
		(double)(idle_tick * 100)/(double)rti_thread_total_tick,
		'%');
	if(strlen(buf)>buf_len)
		return;


	RTI_LOG("Share memory Tx int Send to AP %d per second\n",
		(double)(rti_thread_total_int_count )/((double)rti_thread_total_tick/13000000));

	sprintf(buf+strlen(buf),"Share memory Tx int Send to AP %f per second\n",
		(double)(rti_thread_total_int_count )/((double)rti_thread_total_tick/13000000));
	if(strlen(buf)>buf_len)
		return;


#ifndef LTEONLY_THIN
	if (rti_user_array[0].tick != 0)
	{


		sprintf(buf+strlen(buf),"user recording");
		if(strlen(buf)>buf_len)
			return;



		for (index = rti_user_index; index < RTI_USER_ARRAY_SIZE; index ++)
		{


			sprintf(buf+strlen(buf),"%d, %llu\n",
				rti_user_array[index].type,
				rti_user_array[index].tick);
			if(strlen(buf)>buf_len)
				return;



			if ((index + 1) % 10 == 0)
				RTI_THREAD_DELAY(5);
		}
		for (index = 0; index < rti_switch_index; index ++)
		{
			sprintf(buf+strlen(buf),"%d, %llu\n",
				rti_user_array[index].type,
				rti_user_array[index].tick);
			if(strlen(buf)>buf_len)
				return;


			if ((index + 1) % 10 == 0)
				RTI_THREAD_DELAY(5);
		}
	}
#endif
}


void rti_info_dump_all(void)
{
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem

	unsigned long index;
	rti_uint32_t *sp_list;
	char tmp_data[8]={0},tmp_name[12]={0};
#if		QUECTEL_PROJECT_CUST
	DumpLogPrintf_Extend("assert in check point %d\r\n",gCheckPoint);
	DumpLogPrintf_Extend("Try to dump all RTI record, current rti count %d\r\n",rti_ptr->rti_rt_cnt);
	{
		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[rti_ptr->rti_rt_cnt].task_info;
		memcpy(tmp_name,(char*)(sp_list+1),4);
		memcpy(tmp_name+4,(char*)(sp_list+2),4);
		tmp_name[8]='\0';
		DumpLogPrintf_Extend("EE LOG: Task Name:%s\r\n",tmp_name);
	}
#else
	RTI_LOG("assert in check point %d",gCheckPoint);
	RTI_LOG("Try to dump all RTI record, current rti count %d",rti_ptr->rti_rt_cnt);
#endif
	for (index = 0; index < 128; index ++)
	{
		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;
		memcpy(tmp_data,(char*)sp_list,4);
		tmp_data[4]='\0';
		memcpy(tmp_name,(char*)(sp_list+1),4);
		memcpy(tmp_name+4,(char*)(sp_list+2),4);
		tmp_name[8]='\0';
#if		QUECTEL_PROJECT_CUST
		DumpLogPrintf_Extend("indec %d, type: %s, name %s, timestamp 0x%lx\r\n",index,tmp_data,tmp_name,sp_list[3]);
#else
		uart_printf("indec %d, type: %s, name %s, timestamp 0x%lx\r\n",index,tmp_data,tmp_name,sp_list[3]);
#endif	
	}
}//MiniSystem
else
{
	unsigned long index;
	rti_uint32_t *sp_list;
	char tmp_data[8]={0},tmp_name[12]={0};

	RTI_LOG("assert in check point %d",gCheckPoint);
	RTI_LOG("Try to dump all RTI record, current rti count %d",rti_ptr->rti_rt_cnt);

	for (index = 0; index < 128; index ++)
	{
		sp_list = (rti_uint32_t*)rti_ptr->rti_rt_list[index].task_info;
		memcpy(tmp_data,(char*)sp_list,4);
		tmp_data[4]='\0';
		memcpy(tmp_name,(char*)(sp_list+1),4);
		memcpy(tmp_name+4,(char*)(sp_list+2),4);
		tmp_name[8]='\0';

        /* coverity[overrun-local] */
		RTI_LOG("indec %d, type: %s, name %s, timestamp 0x%lx",index,tmp_data,tmp_name,sp_list[3]);

	}
}
#endif /*MIN_SYS*/	
}


BOOL CurrentThreadIsHISR(void)
{
	if( OSAHISRIsValid(RTI_THREAD_CURRENT) )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

extern void GripNotifyAP(BOOL NeedNotifyAP);
extern void ACIPC_Status_Print(void);
extern UINT32 readDDRFrequencyValue(void);
extern UINT32 get_cpu_freq(void);
extern UINT32 get_cpu_dvc(void);
extern UINT32 get_dsp_dvc(void);
extern FILE* EELOG_fopen(const char * fileName, const char *modeStr);
extern size_t  EELOG_fwrite(const void *buf, size_t chunkSize, size_t numChunks, FILE* handl);
extern int EELOG_fclose(FILE* handl);
extern BOOL EE_PostmortemRegistration(char* name, UINT8* bufAddr, UINT32 bufLen);
extern UINT32 ACIPCIntCount;
extern BOOL diag_open;
extern volatile UINT32 USBUnplugCallerAddress;
extern volatile UINT32 USBUnplugCount;
extern volatile UINT32 diagUsbTxCnt;
extern volatile UINT32 diagUsbTxDoneCnt;

#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
extern quec_ipc_conf ipcapp_msg;
extern  QuecOSStatus quec_set_gpio_level(GPIO_PinNumbers pin_num, quec_pin_level_value_e pin_level);
extern quec_sleep_ind sleep_ind;
#define IPC_CPU_IDLE_RAT 98
#endif
extern void diagGetLibsVersion (void);
#if QUECTEL_PROJECT_CUST
unsigned int fs_mode_is_fat(void);
#endif
UINT32 CPUIdleRate = 0;
/* IDLE RATE */
int CPUUsageInfo(UINT64 duration)
{
	UINT64 count;
	UINT32 DDRFreq,CPFreq,CPDvc,DSPDvc;
	float CurDl,CurUl,CurDiag;
	static int libTimeCount = 0;
	UINT32 pool_size;

#ifdef LFS_USE_CACHE
    Lfs_block_preerase();
#endif

	RTI_LOCK_INIT;
	RTI_LOCK_DISABLE;
	if (duration == 0)
	{
		/* clean tick */
		idle_tick_count = 0;

		RTI_LOCK_ENABLE;
		return 100;
	}
	count = idle_tick_count;
	idle_tick_count = 0;
	RTI_LOCK_ENABLE;

	pool_size = OsaGetDefaultMemPoolFreeSize();

	CPUIdleRate = (UINT32)((count * 100)/duration);
#ifndef MIN_SYS
if (!IsMiniSystem()) 
{//MiniSystem
	
#ifdef QUEC_UART_ENABLE
	if(QUEC_SLEEP_INFO_TO_USB != quec_get_sleepinfo_uart_log())
	{
		uart_printf("System IdleRate: %d,Heap=%u\r\n", CPUIdleRate,pool_size);
	}
#else
	RTI_LOG("IdleRate: %d, %lu, %lu; Heap: %u, cats[%lu %lu]: %d %d %d %d %d",
	        CPUIdleRate, OSAGetTicks(), g_IDLE_times, pool_size, diagUsbTxCnt, diagUsbTxDoneCnt, diag_open,
	        IsDeviceConnctedExternally(), isDiagConnected(), !isDiagBlocked(), diagCommUsbLogEnable());
#endif

#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
    if((TRUE == ipcapp_msg.benable) && (FALSE == sleep_ind.b_pkt_wakeup_flag))
    {
        //quec_debug_print_uart("System IdleRate: %d,gfrom_d2_cnt=%d\r\n", CPUIdleRate,sleep_ind.from_d2_cnt);
        if(CPUIdleRate < IPC_CPU_IDLE_RAT)
        {
            if(0 == sleep_ind.from_d2_cnt)
            {
                sleep_ind.enter_d2_cnt = 0;
                sleep_ind.from_d2_cnt = 1;
                quec_set_gpio_level(IPC_SLEEP_IND_NUM, (quec_pin_level_value_e)(QUEC_PIN_LEVEL_HIGH - sleep_ind.init_sleep_level));
            }                
        }
    }
#endif
#ifdef QUEC_PATCH_SHIELD_LOG_BUG_31755
	extern UINT32 InProduction_Mode(void);
	if (!InProduction_Mode())
	{
		DIAG_FILTER(HW_PLAT, utilities, CPUUsageInfo, DIAG_INFORMATION)
		diagPrintf ("cpu idle rate: %d, Heap: %lu", CPUIdleRate, pool_size);
	}
#else
	DIAG_FILTER(HW_PLAT, utilities, CPUUsageInfo, DIAG_INFORMATION)
	diagPrintf ("cpu idle rate: %d, Heap: %lu", CPUIdleRate, pool_size);
#endif
#ifndef QUECTEL_PROJECT_CUST
    if(USBUnplugCallerAddress != 0)
    {
        RTI_LOG("USBUnplug: 0x%lx, count:%ld", USBUnplugCallerAddress, USBUnplugCount);
    }
#endif
}//MiniSystem
else
{
	RTI_LOG("I: %d, %lu, %lu; H: %u, cat[%d][%lu %lu]: %d %d %d %d, Q: %lu, Phy: %d",
	        CPUIdleRate, OSAGetTicks(), g_IDLE_times, pool_size, diagGetDevType(), diagUsbTxCnt, diagUsbTxDoneCnt, diag_open,
	        IsDeviceConnctedExternally(), isDiagConnected(), !isDiagBlocked(), LfsGetMsgQCnt(0), USB2_PHY_PLL_READY());

	if (!InProduction_Mode())
	{
		DIAG_FILTER(HW_PLAT, utilities, CPUUsageInfo, DIAG_INFORMATION)
		diagPrintf ("cpu idle rate: %d, Heap: %lu", CPUIdleRate, pool_size);
	}
    if(USBUnplugCallerAddress != 0)
    {
        RTI_LOG("USBUnplug: 0x%lx, count:%ld", USBUnplugCallerAddress, USBUnplugCount);
    }

}
#endif /*MIN_SYS*/
	return count * 100 / duration;
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,thread_measurement_enable
void thread_measurement_enable(void)
{
	rti_thread_set_enable(1);
}
//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,thread_measurement_disable
void thread_measurement_disable(void)
{
	rti_thread_set_enable(0);
}


static char line_buffer[128];
const char* status_str[] =
{
	"NU_READY",
	"NU_PURE_SUSPEND",
	"NU_SLEEP_SUSPEND",
	"NU_MAILBOX_SUSPEND",
	"NU_QUEUE_SUSPEND",
	"NU_PIPE_SUSPEND",
	"NU_SEMAPHORE_SUSPEND",
	"NU_EVENT_SUSPEND",
	"NU_PARTITION_SUSPEND",
	"NU_MEMORY_SUSPEND",
	"NU_DRIVER_SUSPEND",
	"NU_FINISHED",
	"NU_TERMINATED",
};
void rti_ee_save()
{
#ifndef PLAT_USE_ALIOS
	FILE* handle;
	rti_uint32_t index;
	rti_uint32_t line_length;

	handle = EELOG_fopen("rti", "wb");

	line_length = sprintf(line_buffer, "thread performance statistics\n");
	EELOG_fwrite(line_buffer, line_length, 1, handle);
	line_length = sprintf(line_buffer, "name, scheduled_time, total runed tick, priority, status\n");
	EELOG_fwrite(line_buffer, line_length, 1, handle);

	for (index = 0; index < RTI_THREAD_ARRAY_SIZE; index ++)
	{
		if(rti_thread_array[index].tid == NULL)
			continue;

#ifdef PLAT_USE_THREADX
		if (((TX_THREAD*)rti_thread_array[index].tid)->tx_thread_id == 0x5441534bUL)
#else
		if (((TC_TCB*)rti_thread_array[index].tid)->tc_id == 0x5441534bUL)
#endif
		{
			/* It's a Task */
			line_length = sprintf(&line_buffer[0], "%.8s, %d, %llu, %d, %s\n",
				RTI_THREAD_NAME(rti_thread_array[index].tid),
				rti_thread_array[index].scheduled_count,
				rti_thread_array[index].tick_count,
				RTI_THREAD_PRIORITY(rti_thread_array[index].tid),
				status_str[RTI_THREAD_STATUS(rti_thread_array[index].tid)]);
			EELOG_fwrite(line_buffer, line_length, 1, handle);
		}
#ifdef PLAT_USE_THREADX
		else if (((TX_THREAD*)rti_thread_array[index].tid)->tx_thread_id == 0UL)
#else
		else if (((TC_TCB*)rti_thread_array[index].tid)->tc_id == 0UL)
#endif
		{
			/* It's a deleted task */
			line_length = sprintf(&line_buffer[0], "%.8s, %d, %llu, DELETED\n",
				RTI_THREAD_NAME(rti_thread_array[index].tid),
				rti_thread_array[index].scheduled_count,
				rti_thread_array[index].tick_count);
			EELOG_fwrite(line_buffer, line_length, 1, handle);
		}
		else
		{
			/* It's a HISR */
			line_length = sprintf(&line_buffer[0], "%.8s, %d, %llu, %d, HISR\n",
				RTI_THREAD_NAME(rti_thread_array[index].tid),
				rti_thread_array[index].scheduled_count,
				rti_thread_array[index].tick_count,
				RTI_THREAD_PRIORITY(rti_thread_array[index].tid));
			EELOG_fwrite(line_buffer, line_length, 1, handle);
		}
	}

#ifndef LTEONLY_THIN
	if (rti_user_array[0].tick != 0)
	{
		line_length = sprintf(line_buffer, "user recording\n");
		EELOG_fwrite(line_buffer, line_length, 1, handle);
		for (index = rti_user_index; index < RTI_USER_ARRAY_SIZE; index ++)
		{
			line_length = sprintf(&line_buffer[0], "%d, %llu\n",
				rti_user_array[index].type,
				rti_user_array[index].tick);
			EELOG_fwrite(line_buffer, line_length, 1, handle);
		}
		for (index = 0; index < rti_switch_index; index ++)
		{
			line_length = sprintf(&line_buffer[0], "%d, %llu\n",
				rti_user_array[index].type,
				rti_user_array[index].tick);
			EELOG_fwrite(line_buffer, line_length, 1, handle);
		}
	}
#endif

	EELOG_fclose(handle);
#endif
}


//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,StopIMLLog
void StopIMLLog(void)
{
	*(volatile unsigned long *)0xD401E170 = 0x0000c0c0;
	*(volatile unsigned long *)0xD401E174 = 0x0000c0c0;
	*(volatile unsigned long *)0xD401E178 = 0x0000c0c0;
	*(volatile unsigned long *)0xD401E17C = 0x0000c0c0;
	*(volatile unsigned long *)0xD401E180 = 0x0000c0c0;
	*(volatile unsigned long *)0xD401E184 = 0x0000c0c0;
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,rti_rt_test
void rti_rt_test()
{
	disableInterrupts();
	while(1);
}

extern unsigned char * CP_MEMLOG_BASE_ADDR;
extern unsigned int  CP_MEMLOG_SIZE;
#define PMU_MOD "[PMU]"

typedef struct _pmu_reg_info_t
{
    UINT32 MPMU_CPCR;
    UINT32 MPMU_CPSR;
    UINT32 MPMU_APCR;
    UINT32 MPMU_APSR;
    UINT32 MPMU_CWUCRS;
    UINT32 MPMU_CWUCRM;
    UINT32 MPMU_AWUCRS;
    UINT32 MPMU_AWUCRM;
    UINT32 PMUCP_DDRRC;
    UINT32 PMUCP_DVCCP;
    UINT32 PMUCP_DVCDP;
    UINT32 PMUCP_DVCST;
    UINT32 PMUCP_DFCCP;
    UINT32 PMUCP_DFCDP;
    UINT32 PMUCP_DFCST;
    UINT32 PMUAP_DMCCCP;
    UINT32 PMUAP_DMCCAP;
    UINT32 PMUAP_ISR;
    UINT32 PMUAP_DFCAP;
    UINT32 PMUAP_DFCST;
}pmu_reg_info_t;

extern pmu_reg_info_t pmu_reg_info;
extern UINT8 power_up_reason;
extern UINT8 power_down_reason;

extern UINT32 needToDump;
extern void registereeWDTbuf(void);

extern UINT32 commpmdebuglog[36+16+8];
extern char crane_cust_ver_info_list[128];
extern volatile UINT32 usbresetDebuglog[32];
extern volatile usbIntDebug_t usbIntDebugLog[16];
#define IPC_DEBUG_MAX_COUNT	16
extern UINT32 IPCDebugLog[IPC_DEBUG_MAX_COUNT][2];
extern UINT8 UsbLogMemory[USB_LOG_LENGTH];
UINT32 rti_rt_backup[4] = {1};
void dumpPreExcepInfo(void)
{
	DIAG_FILTER (EE_HANDLER, EE_LOG, dumpPreExcepInfo_0, DIAG_INFORMATION)
    diagStructPrintf ("pre rti: ", (void *)(rti_rt_backup), 4*sizeof(UINT32));
}

void recordPreExcepInfo(void)
{
	rti_rt_backup[0] = rti_rt.eehandler_counter;
	rti_rt_backup[1] = rti_rt.eehandler_magic[0];
	rti_rt_backup[2] = rti_rt.eehandler_magic[1];
	if(rti_rt.rti_rt_cnt < 128)
	{
		rti_rt_backup[3] = *((UINT32*)&(rti_rt.rti_rt_list[rti_rt.rti_rt_cnt].task_info[12]));
	}
	else
	{
		rti_rt_backup[3] = 0xFFFFFFFF;
	}


}

void rti_rt_init()
{
	rti_ptr = (rti_rt_t*)&rti_rt;
	EE_PostmortemRegistration("rti_tsk", (UINT8*)&rti_rt, sizeof(rti_rt));
	EE_PostmortemRegistration("compmdebug", (UINT8*)commpmdebuglog, sizeof(commpmdebuglog));
	EE_PostmortemRegistration("usbResetDebug", (UINT8*)usbresetDebuglog, sizeof(usbresetDebuglog));
	EE_PostmortemRegistration("usbIntD", (UINT8*)usbIntDebugLog, 16*sizeof(usbIntDebug_t));
	EE_PostmortemRegistration("usbLog", (UINT8*)UsbLogMemory, USB_LOG_LENGTH);
	EE_PostmortemRegistration("CustVersion", (UINT8*)crane_cust_ver_info_list, sizeof(crane_cust_ver_info_list));

	registereeWDTbuf();

	RTI_LOG("power_up_reason: 0x%x, power_down_reason: 0x%x", power_up_reason, power_down_reason);

	if(needToDump)
	{
	    /* Printf CIU register information. */
    	RTI_LOG("======= CIU register =======");
    	RTI_LOG("[ PC ]0x%x: 0x%x", (0xD4282C00 + 0x138), *(volatile UINT32 *)(0xD4282C00 + 0x138));
    	RTI_LOG("[CPSR]0x%x: 0x%x", (0xD4282C00 + 0x13C), *(volatile UINT32 *)(0xD4282C00 + 0x13C));
    	RTI_LOG("[SPSR]0x%x: 0x%x", (0xD4282C00 + 0x140), *(volatile UINT32 *)(0xD4282C00 + 0x140));

		RTI_LOG("need to dump");

		rti_info_dump_all();
		ASSERT_EXT(0, "Need to Dump: Last WDT timeout");
	}

	/* Set state hold ctrl register. */
	*(volatile UINT32 *)0xD4282CF0 = 1;

	memset((void *)(&rti_rt), 0x0, sizeof(rti_rt));

	memset((UINT8 *)commpmdebuglog, 0x0, sizeof(commpmdebuglog));
	memset((UINT8 *)usbresetDebuglog, 0x0, sizeof(usbresetDebuglog));
	memset((UINT8 *)usbIntDebugLog, 0x0, 16*sizeof(usbIntDebug_t));
	memset((UINT8 *)crane_cust_ver_info_list, 0x0, sizeof(crane_cust_ver_info_list));
	rti_enable = 1;
	rti_enable_bak = 1;
	#ifdef PLAT_USE_ALIOS
	OsaSetDbgDisOpt(0x0);
	#endif
}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,rti_enable_ee
void rti_init()
{
	static int inited = 0;

	rti_thread_set_enable(1);
	if (!inited)
	{
		EELOG_RegisterForLogstream(rti_ee_save);
		inited = 1;
	}
}


void rti_check_thread_timeout(void)
{
    int i = 0;
    UINT32 tick_to = 0, tick_out = 0;
    int name_len = 0;

    for(i = 0; i < RTI_THREAD_TIMEOUT_SIZE; i++)
    {
        tick_to = rti_thread_timeout[i].tick_to;
        tick_out = rti_thread_timeout[i].tick_out;
        name_len = strlen((const char *)rti_thread_timeout[i].task);

        if((tick_to != 0) && (tick_out != 0)&&
           (name_len > 0) && (name_len < 11))
        {
            ErrorLogPrintf("Task %s run tick: [0x%x -> 0x%x]", rti_thread_timeout[i].task, tick_to, tick_out);
        }
    }
}

/* Help Function */
char *getCurrentTaskName(void)
{
	struct rti_thread_item* thread;

    if (OS_INTERRUTPT_COUNT != 0)
    {
        return "Interrupt";
    }
	else if (RTI_THREAD_CURRENT)
	{
		thread = RTI_THREAD_ITEM(RTI_THREAD_CURRENT);
#ifndef PLAT_USE_ALIOS
		return thread->tid->tx_thread_name;
#else
		return (char *)(thread->tid->task_name);
#endif
	}
	else
	{
		return "None";
    }
}
#ifndef LTEONLY_THIN

#define CONTEXT_MAX	 50
UINT32 suspend_context[CONTEXT_MAX][5]={0};
UINT32 resume_context[CONTEXT_MAX][5]={0};
extern UINT32 ee_handler_sign;

#ifdef PLAT_USE_THREADX
void record_pure_suspend_context(TX_THREAD *task_ptr)
#elif defined(PLAT_USE_ALIOS)
void record_pure_suspend_context(ktask_t *task_ptr)
#else
void record_pure_suspend_context(TC_TCB *task_ptr)
#endif
{
	UINT8 *N_ptr;
	static UINT8 suspend_index=0;

	if(ee_handler_sign)
		return;

	suspend_context[suspend_index][0]=timerCountRead(TS_TIMER_ID);//RTI_CURRENT_TICK;
	N_ptr=(UINT8 *)&suspend_context[suspend_index][1]+7;
#ifdef PLAT_USE_THREADX
	memcpy(&suspend_context[suspend_index][1],&RTI_THREAD_CURRENT->tx_thread_name[0],7);
#elif defined(PLAT_USE_ALIOS)
	memcpy(&suspend_context[suspend_index][1],&RTI_THREAD_CURRENT->task_name[0],7);
#else
	memcpy(&suspend_context[suspend_index][1],&RTI_THREAD_CURRENT->tc_name[0],7);
#endif
	*N_ptr='\0';
	N_ptr=(UINT8 *)&suspend_context[suspend_index][3]+7;
#ifdef PLAT_USE_THREADX
	memcpy(&suspend_context[suspend_index][3],&task_ptr->tx_thread_name[0],7);
#elif defined(PLAT_USE_ALIOS)
	memcpy(&suspend_context[suspend_index][3],&task_ptr->task_name[0],7);
#else
	memcpy(&suspend_context[suspend_index][3],&task_ptr->tc_name[0],7);
#endif
	*N_ptr='\0';

	if((++suspend_index)>=CONTEXT_MAX)
	{
		suspend_index=0;
	}

}

#ifdef PLAT_USE_THREADX
void record_pure_resume_context(TX_THREAD *task_ptr)
#elif defined(PLAT_USE_ALIOS)
void record_pure_resume_context(ktask_t *task_ptr)
#else
void record_pure_resume_context(TC_TCB *task_ptr)
#endif
{
	UINT8 *N_ptr;
	static UINT8 resume_index=0;

	if(ee_handler_sign)
		return;

	resume_context[resume_index][0]= timerCountRead(TS_TIMER_ID);//RTI_CURRENT_TICK;
	N_ptr=(UINT8 *)&resume_context[resume_index][1]+7;
#ifdef PLAT_USE_THREADX
	memcpy(&resume_context[resume_index][1],&RTI_THREAD_CURRENT->tx_thread_name[0],7);
#elif defined(PLAT_USE_ALIOS)
	memcpy(&resume_context[resume_index][1],&RTI_THREAD_CURRENT->task_name[0],7);
#else
	memcpy(&resume_context[resume_index][1],&RTI_THREAD_CURRENT->tc_name[0],7);
#endif
	*N_ptr='\0';
	N_ptr=(UINT8 *)&resume_context[resume_index][3]+7;
#ifdef PLAT_USE_THREADX
	memcpy(&resume_context[resume_index][3],&task_ptr->tx_thread_name[0],7);
#elif defined(PLAT_USE_ALIOS)
	memcpy(&resume_context[resume_index][3],&task_ptr->task_name[0],7);
#else
	memcpy(&resume_context[resume_index][3],&task_ptr->tc_name[0],7);
#endif
	*N_ptr='\0';

	if((++resume_index)>=CONTEXT_MAX)
	{
		resume_index=0;
	}
}

extern void UartLogPrintf(const char *fmt, ...);

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,dump_pure_suspend
void dump_pure_suspend_resume_context(void)
{
	UINT8 i;

	for(i=0;i<CONTEXT_MAX;i++)
	{
		DIAG_FILTER(ADEMO, PURE, Suspend, DIAG_INFORMATION)
		diagPrintf("No.%d, Timer 0x%lx,%s suspend %s",i,suspend_context[i][0],&suspend_context[i][1],&suspend_context[i][3]);
		UartLogPrintf("No.%d, Timer 0x%lx,%s suspend %s",i,suspend_context[i][0],&suspend_context[i][1],&suspend_context[i][3]);

	}

	for(i=0;i<CONTEXT_MAX;i++)
	{
		DIAG_FILTER(ADEMO, PURE, Resume, DIAG_INFORMATION)
		diagPrintf("No.%d, Timer 0x%lx,%s Resume %s",i,resume_context[i][0],&resume_context[i][1],&resume_context[i][3]);
		UartLogPrintf("No.%d, Timer 0x%lx,%s suspend %s",i,suspend_context[i][0],&suspend_context[i][1],&suspend_context[i][3]);

	}

}
#endif
#pragma arm section code="CURRENT_TICK"
UINT32 get_current_TStimer_tick(void)
{
	//return RTI_CURRENT_TICK;
	return timerCountRead(TS_TIMER_ID);
}
#pragma arm section code

/** if count = 1, delay 1/32768s(30.5us)
 ** accuracy range: count*30.5us~(count+1)*30.5us
**/
void delay_us(UINT8 count)
{
    UINT32 stick = get_current_TStimer_tick();
    while ((UINT8)(get_current_TStimer_tick() - stick) < (count + 1));
}

/* Seagull Uart Routine */
#define REG32(x)	*((volatile unsigned long*)(x))
#if defined (EDEN_1928)
#define SEAGULL_UART_BASE   0xd0236000
#elif defined (NEZHA3_1826)
//#define SEAGULL_UART_BASE   0xd4017000 //Use AP UART for bring up on Nezha3 DKB V1.0
volatile UINT32 SEAGULL_UART_BASE_ADDR = 0xd4017000; //The CP UART base address may vary between different board types.
#else
#define SEAGULL_UART_BASE   0xd4036000
#endif

#ifdef LWIP_IPNETBUF_SUPPORT
int uart_inited = 0;
#else
static int uart_inited = 0;
#endif


void seagull_uart_init()
{
	volatile unsigned long *r;

	if (1==uart_inited)
	{
		return;
	}

	/* PMUM_CCGR */
	REG32(0xd4050024) = 0xffffffff;

	/* AIB clock */
	REG32(0xd401503c) = 0x03;

    SEAGULL_UART_BASE_ADDR = 0xD4017000; //use CP UART
    if (CHIP_IS_CRANELR)
    {
        /* MFPR GPIO 71 */
        r = (volatile unsigned long*)0xd401e1bc; //AP_UART1_RXD
        *r = 0xc0c1; //0xd0c1;
        *r = 0xc0c1; //0xd0c1;
        
        /* MFPR GPIO 72 */
        r = (volatile unsigned long*)0xd401e1c0; //AP_UART1_TXD
        *r = 0xc0c1; //0xd0c1;
    }
    else if (CHIP_IS_CRANELS_A0)
    {
        /* MFPR GPIO 27 */
        r = (volatile unsigned long*)0xd401e148; //AP_UART1_RXD
        *r = 0xd0c1;

        /* MFPR GPIO 28 */
        r = (volatile unsigned long*)0xd401e14C; //AP_UART1_TXD
        *r = 0xd0c1;

    }
    else
    {
    	/* MFPR GPIO 29 */
    	r = (volatile unsigned long*)0xd401e150; //UART1_RXD
    	*r = 0xd0c1;

    	/* MFPR GPIO 30 */
    	r = (volatile unsigned long*)0xd401e154; //UART1_TXD
    	*r = 0xd0c1;
    }
	/* UART clock control/UCER */
	REG32(0xd4015000) = 0x00;

	{
		unsigned long uart_delay = 0xffff;
		while(uart_delay--);
	}

	/* UART clock control/UCER */
	REG32(0xd4015000) = 0x03; //switch to high speed clock source

	{
		unsigned long uart_delay = 0xffff;
		while(uart_delay--);
	}

	// UALCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0xc);
	*r = 0x83;


    if (PLATFORM_IS_ASIC)
	{
		// UADLL
		r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x0);
		*r = 0x20; //0x20 for 59.429M
	}
    else if(PLATFORM_IS_FPGA)
	{
		// UADLL
		r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x0);
		*r = 0x07;
	}
	// UADLH
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x4);
	*r = 0;

	// UALCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0xC);
	*r &= ~0x80;

	// UAFCR
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x8);
	*r = 0x07;

	// UAIER
	r = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x4);
	*r = 0x140; //switch to high speed clock source

	uart_inited = 1;
}

void seagull_uart_putc(const char ch)
{
	volatile unsigned long* ualsr;
	volatile unsigned long* uathr;

	if (!uart_inited) seagull_uart_init();

	ualsr = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x14);
	uathr = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR);

	if (ch == '\n')
	{
		while (!(*ualsr & 0x20));
		*uathr = '\r';
	}

	while (!(*ualsr & 0x20));
	*uathr = ch;
}

unsigned long uart_busy(void)
{
	if(uart_inited)
	{
		volatile unsigned long* ualsr;
		ualsr = (volatile unsigned long*)(SEAGULL_UART_BASE_ADDR + 0x14);
		return ((*ualsr) & (1 << 6)) ? 0 : 1;
	}

	/*Fix coverity[missing_return]*/
	return 0;
}

uartCfgDataS uartCfg =
{
	UART_DEV_UART,
	0,
	{{0,0},{0,0},{0,0},{0,0}},
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

UINT32 activateCodeFlag=0;
UINT32 AssertRandomFlag=0;

UINT32 uart_output_dev=UART_DEV_UART;
UINT32 log_sdcard_dev_partition = 0;
int sdcard_fatfs2_mount_status_g = 0;
extern int sdcard_fatfs_mount_status_g;

void uartCfgDevInit(void)
{
	uart_output_dev = uartCfg.uartDevType;
	log_sdcard_dev_partition = uartCfg.multiVol;
}

void log_sdcard_set_partition(int i)
{
	log_sdcard_dev_partition = i;
}

#pragma arm section code="SDCARD_LOG_STATUS"

UINT32 log_sdcard_partition_is_multi(void)
{
	if(log_sdcard_dev_partition)
		return 1;
	else
		return 0;
}

int get_sdcard_log_partition_status(void)
{
	if(log_sdcard_partition_is_multi()) {
        return sdcard_fatfs2_mount_status_g;
	}
    else {
	    return sdcard_fatfs_mount_status_g;
    }
}
#pragma arm section code

UINT32 sdcard_fat_fs_is_ready(void)
{
	return sdcard_fatfs_mount_status_g;

}

//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,SDCARDMULTIPARTITION
void sdcard_log_two_partition(void)
{
	setLogSdcardPartitionType(1);
}
//ICAT EXPORTED FUNCTION - HW_PLAT,utilities,SDCARDSINGLEPARTITION
void sdcard_log_single_partition(void)
{
    setLogSdcardPartitionType(0);
}

extern UINT32 initState;
BOOL isInMMICodeRange(UINT32 addr)
{
	return FALSE;
}
typedef unsigned char	uint8_t;	  /* Unsigned 8-bit quantity		*/
typedef unsigned short	uint16_t; 	  /* Unsigned 16-bit quantity		*/

BOOL uart_trace_enable(void)
{
    rti_mode rtiMode = rti_get_mode();

    if(rtiMode < rti_urtlog_mode)
    {
        return FALSE;
    }

    return TRUE;
}

#if !defined(LTEONLY_THIN) && !defined(LTEONLY_8M8M)
int uart_printf(const char* fmt, ...)
{
	int ret = 0;

	if(uart_trace_enable())
    {
        va_list ap;
        char buffer[128], *ptr;
        void (*console_output)(const char ch);

        memset(buffer, 0, sizeof(buffer));
        va_start(ap, fmt);
        vsnprintf(buffer, sizeof(buffer)-1, fmt, ap);
        va_end(ap);

        console_output = seagull_uart_putc;
        if (!uart_inited) seagull_uart_init();

        ptr = &buffer[0];
        while (*ptr)
        {
            console_output(*ptr);
            ptr ++;
        }

        ret = ptr - buffer;
    }
	else
	{
        ret = 0;
	}

    return ret;
}

int fatal_printf(const char* fmt, ...)
{

#ifndef PROJ_MINIPHONE
	if(!SysIsAssert())
	{
		return 0;
    }
#endif
	va_list ap;
	char buffer[128], *ptr;
	static int fatal_uart_inited = 0;

	memset(buffer, 0, sizeof(buffer));
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer)-1, fmt, ap);
	va_end(ap);

	if (!fatal_uart_inited)
	{
		fatal_uart_inited = 1;
		seagull_uart_init();
	}

	ptr = &buffer[0];
	while (*ptr)
	{
		seagull_uart_putc(*ptr);
		ptr ++;
	}
	/*Have been called va_end  after calling va_start*/
	/*coverity[missing_va_end]*/
	return ptr - buffer;
}
#endif

void uart_dump(char* data, int length)
{
	int index = 0, col = 0;

	if (!uart_inited) seagull_uart_init();

	//uart_printf("   00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
	//uart_printf("00 ");
	for (index = 0; index < length; index ++)
	{
		uart_printf("%02x ", *data);
		data ++;
		if ((index + 1) % 16 == 0)
			uart_printf("\n%02x ", col ++);
	}
	uart_printf("\n");
}
void uart_reset(void){
	uart_inited=0;

}

#if 0

#define MEMTRACE_MAX			1024
#define MEMTRACE_STACK_LEVEL	8
#define MEMTRACE_HASH_SIZE		256

struct mem_trace_item
{
	unsigned char name[8];	/* task/hisr name */

	unsigned int stack[MEMTRACE_STACK_LEVEL];
	void* memblock;			/* allocated memblock */
	unsigned long length;	/* memory length */

	/* item list for hash table */
	struct mem_trace_item* next;
};

/* trace list */
__align(4)
struct mem_trace_item trace_list[MEMTRACE_MAX];
struct mem_trace_item *item_hash[MEMTRACE_HASH_SIZE];
struct mem_trace_item *item_free;

void mem_trace_stacktrace(struct mem_trace_item* item)
{
	int index;
	unsigned int ptr;

	/* get lr and stack pointer */
	ptr = __current_sp();

	/* skip first two function */
	for (index = 0; index < 1; )
	{
		ptr = ptr - 4;
		if ((*(unsigned int*)ptr & 0x01 == 0x01) &&
			(*(unsigned int*)ptr > 0x07a00000) &&
			(*(unsigned int*)ptr < 0x08a00000))
		{
			index ++;
		}

		if (*(unsigned int*)ptr == 0xa5a5a5a5) return;
	}

	for (index = 0; index < MEMTRACE_STACK_LEVEL; )
	{
		ptr = ptr - 4;
		if ((*(unsigned int*)ptr & 0x01 == 0x01) &&
			(*(unsigned int*)ptr > 0x07a00000) &&
			(*(unsigned int*)ptr < 0x08a00000))
		{
			item->stack[index] = *(unsigned long*)ptr;
			index ++;
		}

		if (*(unsigned int*)ptr == 0xa5a5a5a5) return;
	}
}

void mem_trace_init()
{
	struct mem_trace_item *item;
	unsigned long index;

	memset(trace_list, 0, sizeof(trace_list));
	memset(item_hash, 0, sizeof(item_hash));

	item_free = &trace_list[0];
	item = &trace_list[0];

	/* add all item to the free list */
	for (index = 1; index < MEMTRACE_MAX; index ++)
	{
		item->next = &trace_list[index];
		item = item->next;
	}

	item->next = NULL;
}

void mem_trace_allocate(void* buffer, unsigned long length)
{
	struct mem_trace_item* item;
	unsigned long index;
#ifndef PLAT_USE_THREADX
	extern TC_TCB* TCD_Current_Thread;
#endif
	unsigned long cpsr;

	/* get mem item */
	cpsr = disableInterrupts();
	if (item_free == NULL)
	{
		/* no free item */
		restoreInterrupts(cpsr);
		return;
	}
	item = item_free;
	item_free = item_free->next;
	restoreInterrupts(cpsr);

	/* fill item */
#ifdef PLAT_USE_THREADX
	memcpy(item->name, (unsigned char*)RTI_THREAD_CURRENT->tx_thread_name, 8);
#else
	memcpy(item->name, (unsigned char*)RTI_THREAD_CURRENT->tc_name, 8);
#endif
	item->name[7] = '\0';
	item->memblock = buffer;
	item->length = length;
	item->next = NULL;

#ifdef TRACE_ON_TRACE
	DIAG_FILTER(MemTrace, Allocate, fill, DIAG_INFORMATION)
	diagPrintf("[%s] allocate block %lx, len %d", item->name, item->memblock, item->length);
#endif

	/* record call stack */
	mem_trace_stacktrace(item);

	/* add to mem trace hash table */
	index = ((unsigned long)buffer) % MEMTRACE_HASH_SIZE;

	cpsr = disableInterrupts();
	if (item_hash[index] != NULL)
	{
		/* add to the end of list */
		struct mem_trace_item* tail;

		/* get tail of hash node link */
		tail = item_hash[index];
		while (tail->next != NULL)
			tail = tail->next;

		tail->next = item;
	}
	else
	{
		/* it's an empty list */
		item_hash[index] = item;
	}

	restoreInterrupts(cpsr);
}

void mem_trace_free(void* buffer)
{
	struct mem_trace_item* item;
	unsigned long index, cpsr;

	/* get mem item */
	index = ((unsigned long)buffer) % MEMTRACE_HASH_SIZE;

	cpsr = disableInterrupts();
	if (item_hash[index] != NULL)
	{
		item = item_hash[index];
		if (item->memblock == buffer)
		{
			/* delete item from list */
			item_hash[index] = item->next;
			restoreInterrupts(cpsr);
		}
		else
		{
			/*Fixed coverity[check_after_deref]*/
			#if 0
			while (item->next->memblock != buffer && item->next != NULL)
			#else
			while (item->next != NULL && item->next->memblock != buffer)
			#endif
				item = item->next;

			/* delete item from list */

			/*No need to check the pointer*/
			/*coverity[check_after_deref]*/
			if (item->next != NULL)
			{
				struct mem_trace_item* i;

				i = item->next;
				item->next = item->next->next;
				restoreInterrupts(cpsr);

				item = i;
			}
			else
			{
				/* not found */
				DIAG_FILTER(MemTrace, Free, NO_FOUND, DIAG_INFORMATION)
				diagPrintf("Not found block %lx", item->memblock);

				return;
			}
		}

#ifdef TRACE_ON_TRACE
		DIAG_FILTER(MemTrace, Free, free, DIAG_INFORMATION)
		diagPrintf("free block %lx, len %d, allocate at task: %s", item->memblock, item->length, item->name);
#endif

		/* clear item */
		memset(item, 0, sizeof(struct mem_trace_item));

		/* add item to free list */
		cpsr = disableInterrupts();
		item->next = item_free;
		item_free = item;
		restoreInterrupts(cpsr);
	}
}

//ICAT EXPORTED FUNCTION - MEM,TRACE,display
void mem_trace_display()
{
	unsigned long index;
	struct mem_trace_item* item;

	for (index = 0; index < MEMTRACE_MAX; index ++)
	{
		item = &trace_list[index];

		/* dump memory trace item */
		if (item->name[0] != '\0')
		{
			unsigned int i;

			uart_printf("%s[alloc %d bytes @ 0x%08x, bt", item->name, item->length, item->memblock);
			for (i = 0; i < MEMTRACE_STACK_LEVEL; i ++)
				uart_printf(":0x%08x", item->stack[i]);
			uart_printf("]\n");
		}
	}
}

//ICAT EXPORTED FUNCTION - MEM,TRACE,all
void mem_trace_dump_all()
{
	unsigned long index;
	struct mem_trace_item* item;

	DIAG_FILTER(MEM, DUMP, Prepare, DIAG_INFORMATION)
	diagPrintf("Try to dump all mem allocation record");

	for (index = 0; index < MEMTRACE_MAX; index ++)
	{
		item = &trace_list[index];

		/* dump memory trace item */
		if (item->name[0] != '\0')
		{
			DIAG_FILTER(MEM, DUMP, ALL, DIAG_INFORMATION)
			diagPrintf("Name %s, len %d, block 0x%lx", item->name, item->length, item->memblock);

			OSATaskSleep(5);
		}
	}
}

#endif


/*
UINT32 cp14ReadCCNT(void) // OLD non-generic name, to be obsolete.
{
		return 0;
}

UINT32 cp_ReadCCNT(void) // OLD non-generic name, to be obsolete.
{
			return 0;
}
*/
UINT32 ReadCCNT_with_PP(void)
{
			return cp_ReadCCNT();
}

void keypadConfigure(void)
{
   return;
}
typedef enum
{
    KEYPAD_RC_OK = 1,
    KEYPAD_RC_INVALID_FUNC_BIND,
    KEYPAD_RC_NO_ISR_BOUND,
    KEYPAD_RC_ISR_ALREADY_BOUND
} KEYPAD_ReturnCode;
typedef struct
{
    UINT8           row;
    UINT8           column;
} KEY_MAP;
#define KEYPAD_NO_OF_ROWS                       7
#define KEYPAD_NO_OF_COLUMNS                    7
#define KEYPAD_NO_OF_DIRECT_KEYS                4

typedef struct
{
    UINT8           num_of_key_pressed;
    KEY_MAP         key[KEYPAD_NO_OF_ROWS * KEYPAD_NO_OF_COLUMNS];
} KEY_PRESS;

typedef struct
{
    int           num0;
    int           num1;
} KP_ROTARY;

typedef void (*KeypadNotifyEventFunc)(KEY_PRESS 	keypadRegisters);
typedef void (*KeypadNotifyRotaryEventFunc)(KP_ROTARY    rotaryPosition );

KEYPAD_ReturnCode keypadNotifyEventBind ( KeypadNotifyEventFunc             keypadFunc,
                                          KeypadNotifyRotaryEventFunc       keypadRotaryFunc )
{



    return KEYPAD_RC_OK;
}
typedef unsigned long (*RpcFuncType)(unsigned short, void *, unsigned short, void *) ;

RpcFuncType RPCFuncRegister( char *funcName, RpcFuncType funcPtr)
{
	return NULL;
}

void DbgPrintf_sim(char* fmt, ...)
{


}

#define JTAGSW_CLKRST   0xD4015040

#define TDI     0x3
#define TRST        0x2
#define TMS     0x6
#define TDITMS      0x7
#define TCK     0xa
#define TDITCK      0xb
#define TMSTCK      0xe
#define TDITMSTCK   0xf

#define TDI_NRST             0x1
#define TMS_NRST     	      0x4
#define TDITMS_NRST       0x5
#define TCK_NRST     		0x8
#define TDITCK_NRST      0x9
#define TMSTCK_NRST      0xc
#define TDITMSTCK_NRST   0xd

#define __trace__   uart_printf
#define REG_JTAGSW_JTAGSW_EN    0xD4013100
#define REG_JTAGSW_JTAGSW_CTRL  0xD4013104
#define REG_JTAGSW_JTAGSW_DATA  0xD4013108

#define  setbit1 \
do { \
    BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDI); \
    BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDITCK); \
} while(0)

#define  setbit0 \
do { \
    BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST); \
    BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK); \
} while(0)

//**************************************************************
//      jtag_sw() interface:
//      void jtag_rw(unsigned long address, int addr_len, unsigned long *data,
//              int len, unsigned long *read_array)
//
//      address: the IR address.
//      addr_len: IR register length. For all of our chips, the IR address length is 9.
//      len:   DR register length.
//      Since DR register may be larger than 32bit, so you need to use an array for write/read DR data.
//      Data[]: DR register value to write.
//      Read_array[]: DR register read out value.
//**************************************************************
static void jtag_rw(unsigned long address, int addr_len, unsigned int *data,
		    int len, unsigned int *read_array)
{
	unsigned int addr_shift, data_shift, read_shift, read_tdo;
	int len_int, i, j;

	read_shift=0;	//to fix warning

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto RUTI */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	/* TAP goto SDRS */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	/* TAP goto SIRS */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto CAIR */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* goto SHIR state, data will be latched in next negedge */

	addr_shift = address;

	for (i = 0; i < addr_len - 1; i++) {
		if ((addr_shift & 0x1) == 0x1)
			setbit1;
		else
			setbit0;
		addr_shift = addr_shift >> 1;
		/* bit0 is the first to shift out */
	}

	/* the last bit will be latched in next state */
	if (addr_shift & 0x1) {
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDITMS);
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDITMSTCK);
		/* posedge latch bit[7]=1, and TAP goto Exit1_IR */
	} else {
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	}

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	/* TAP goto update IR */

	/* IR done, goto DR */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto RUTI */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	/* TAP goto SDRS */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto capture DR */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto shift DR state, data will be latched in next neg edge */

	len_int = len;
	data_shift = data[0];

	j = 0;
	while (len_int != 0) {
		read_shift = 0;
		if (len_int <= 32) {
			/* less than 32-bit */
			for (i = 0; i < len_int - 1; i++) {
				if ((data_shift & 0x1) == 0x1)
					setbit1;
				else
					setbit0;
				data_shift = data_shift >> 1;
				/* bit0 is the first to shift out */
				read_tdo = BU_REG_READ(REG_JTAGSW_JTAGSW_DATA);
				read_shift = read_shift | (read_tdo << i);
			}
			len_int = 0;
			read_array[j] = read_shift;
		} else {
			/* 32b-bit write */
			for (i = 0; i < 32; i++) {
				if ((data_shift & 0x1) == 0x1)
					setbit1;
				else
					setbit0;
				data_shift = data_shift >> 1;
				/* bit0 is the first to shift out. */
				read_tdo = BU_REG_READ(REG_JTAGSW_JTAGSW_DATA);
				read_shift = read_shift | (read_tdo << i);
			}
			read_array[j] = read_shift;
			j = j + 1;
			data_shift = data[j];
			len_int = len_int - 32;
		}
	}
	/* the last bit will be latched in next state. */
	if (data_shift & 0x1) {
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDITMS);
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TDITMSTCK);
		/* posedge latch bit[7]=1, and TAP goto Exit1_DR */
	} else {
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
		BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	}
	read_tdo = BU_REG_READ(REG_JTAGSW_JTAGSW_DATA);
	read_shift = read_shift | (read_tdo << i);
	read_array[j] = read_shift;

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
	/* TAP goto update DR */

	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TRST);
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TCK);
	/* TAP goto run RUTI */
}
//**************************************************************
//	  int sw_jtag_cmd(unsigned long address, int addr_len, unsigned int *data,
//		int len, unsigned int *read_array)
//      address: the IR address.
//      addr_len: IR register length. For all of our chips, the IR address length is 9.
//      len:   DR register length.
//      Since DR register may be larger than 32bit, so you need to use an array for write/read DR data.
//      data[]: DR register value to write.
//      read_array[]: DR register read out value.
//**************************************************************
int sw_jtag_cmd(unsigned long address, int addr_len, unsigned int *data,
		int len, unsigned int *read_array)
{
	unsigned i;
	static int init=0;
	int cnt = 0;
	int diff=0;

// I: Enable SW_JTAG mode:
	BU_REG_WRITE(JTAGSW_CLKRST, 0x3);	/* release SW_JTAG reset */
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_EN, 0x1);	/* enable JTAG SW mode, hardware JTAG will be invalid now */

// II: reset TAG controller
	/* force TAP to reset state */
	if(init==0)
	{
		for (i = 0; i < 30; i++) {
			BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMS);
			BU_REG_WRITE(REG_JTAGSW_JTAGSW_CTRL, TMSTCK);
		}
		init=1;
	}

// III: start programming with jtag_sw() routine.
	__trace__("Start IR/DR programming:\r\n");

	jtag_rw(address, addr_len, data, len, read_array);
	jtag_rw(address, addr_len, data, len, read_array);	// 2nd write to get 1st dr out for comparison

	if (len % 32)
		cnt = len/32 + 1;
	else
		cnt = len/32;

	__trace__("dr command:\r\n",cnt);
	i=0;
	while (i<cnt) {
		__trace__("dr%.3d~%.3d: %.8x\r\n", (i+1)*32-1,i*32,data[i]);
		i++;
	}

	__trace__("readout tdo:\r\n",cnt);
	i=0;
	while (i<cnt) {
		__trace__("dr%.3d~%.3d: %.8x\r\n", (i+1)*32-1,i*32,read_array[i]);
		if(data[i]!=read_array[i])
		{
			__trace__("Warning: read out different dr values!!!\r\n");
			diff=1;
		}
		i++;
	}

	if(!diff)
		__trace__("Successful IR/DR programming!\r\n");

// IV: disable SW_JTAG mode once it is done
	BU_REG_WRITE(REG_JTAGSW_JTAGSW_EN, 0x0);
	return 0;
}

UINT64 global_cpu_uid = 0;
UINT64 global_flash_uid = 0;

//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, Read_Crane_CPU_UID
UINT64 Read_Crane_CPU_UID(void)
{
    UINT64 uid=0;
    UINT64 uid_temp=0;
    UINT32 uid_s, uid_h, uid_l;
    UINT32 uid_x, uid_y, uid_wafer;

    if (global_cpu_uid == 0)
    {
        *((volatile UINT32 *)0xd4282868) = 0x09;

        uid_l = *((volatile UINT32 *)0xd42014A4);
        uid_h = *((volatile UINT32 *)0xd420141C);
        uid_s = *((volatile UINT32 *)0xd4201420);

        *((volatile UINT32 *)0xd4282868) = 0x0;

        if (CHIP_IS_CRANEG || CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
        {
            uid_wafer = ((uid_h&0x3)<<3)|((uid_l>>29)&0x7); //Wafer, 5 bits, [193:189]
            uid_x = (uid_l>>22)&0x7f; //X, 7 bits, [188:182]
            uid_y = (uid_l>>15)&0x7f; //Y, 7 bits, [181:175]

            uid = (UINT64)(uid_s&0x3f);
            uid <<= 49; //lotid_0
            uid_temp = (UINT64)(uid_h>>2);
            /* uid[54:0]= LotID(36)_[54:19] + WaferID(5)_[18:14] + X(7)_[13:7] + Y(7)_[6:0] */
            uid |= (uid_temp<<19) | (uid_wafer<<14) | (uid_x<<7) | uid_y;
        }
        else if (CHIP_IS_CRANE)
        {
            uid_y = (uid_l>>12)&0x7f; //Y, 7 bits
            uid_x = (uid_l>>19)&0x7f; //X, 7 bits
            uid_wafer = (uid_l>>26)&0x1f; //Wafer, 5 bits

            uid = (UINT64)(uid_s&0x7FF);
            uid <<= 50;
            uid_temp = (UINT64)(uid_h>>1);
            /* uid[60:0]= LotID(42)_[60:19] + WaferID(5)_[18:14] + X(7)_[13:7] + Y(7)_[6:0] */
            uid |= (uid_temp<<19) | (uid_wafer<<14) | (uid_x<<7) | uid_y;
        }
        else
            return 0xFFFFFFFFFFFFFFFF; //unknown chip type

        global_cpu_uid = uid;
    }
    
    CPUartLogPrintf("---Read_Crane_CPU_UID(%x):(0x%llx) ---", GetChipID(), global_cpu_uid);
    return global_cpu_uid;
}

#ifdef QUECTEL_OPEN_CPU

UINT64 global_cpu_uid_old = 0;

UINT64 QUEC_Read_Crane_CPU_UID_OLD(void)
{
    UINT64 uid=0;
    UINT64 uid_temp=0;
    UINT32 uid_s, uid_h, uid_l;
    UINT32 uid_x, uid_y, uid_wafer;

    if (global_cpu_uid_old == 0)
    {
        *((volatile UINT32 *)0xd4282868) = 0x09;

        uid_l = *((volatile UINT32 *)0xd42014A4);
        uid_h = *((volatile UINT32 *)0xd420141C);
        uid_s = *((volatile UINT32 *)0xd4201420);

        uid_y = (uid_l>>12)&0x7f; //Y, 7 bits
        uid_x = (uid_l>>19)&0x7f; //X, 7 bits
        uid_wafer = (uid_l>>26)&0x1f; //Wafer, 5 bits

        uid = (UINT64)(uid_s&0x7FF);
        uid <<= 50;
        uid_temp = (UINT64)(uid_h>>1);
        /* uid[62:0]= LotID(44)_[62:19] + WaferID(5)_[18:14] + X(7)_[13:7] + Y(7)_[6:0] */
        uid |= (uid_temp<<19) | (uid_wafer<<14) | (uid_x<<7) | uid_y;

        *((volatile UINT32 *)0xd4282868) = 0x0;

        global_cpu_uid_old = uid;
    }
    return global_cpu_uid_old;
}
#endif
//ICAT EXPORTED FUNCTION - HW_PLAT, utilities, Get_Chip_Fuse_Info
void Get_Chip_Fuse_Info(void)
{
    UINT32 uid_x, uid_y, uid_wafer, lotid[6], fuse[3];

    *((volatile UINT32 *)0xd4282868) = 0x9;

    fuse[1] = *((volatile UINT32 *)0xd4201420); //bank3[255:224]
    fuse[2] = *((volatile UINT32 *)0xd420141C); //bank3[223:192]
    fuse[0] = *((volatile UINT32 *)0xd42014A4); //bank3[191:160]
    *((volatile UINT32 *)0xd4282868) = 0x0;
    if (CHIP_IS_CRANEG || CHIP_IS_CRANEM || CHIP_IS_CRANEL || CHIP_IS_CRANELS || CHIP_IS_CRANELR)
    {
        uid_wafer = ((fuse[2]&0x3)<<3)|((fuse[0]>>29)&0x7); //Wafer, 5 bits, [193:189]
        uid_x = (fuse[0]>>22)&0x7f; //X, 7 bits, [188:182]
        uid_y = (fuse[0]>>15)&0x7f; //Y, 7 bits, [181:175]
        lotid[0] = (fuse[1])&0x3f; //6 bits, [229:224]
        lotid[1] = (fuse[2]>>26)&0x3f; //6 bits, [223:218]
        lotid[2] = (fuse[2]>>20)&0x3f; //6 bits, [217:212]
        lotid[3] = (fuse[2]>>14)&0x3f; //6 bits, [211:206]
        lotid[4] = (fuse[2]>>8)&0x3f; //6 bits, [205:200]
        lotid[5] = (fuse[2]>>2)&0x3f; //6 bits, [199:194]
    }
    else if (CHIP_IS_CRANE)
    {
        uid_y = (fuse[0]>>12)&0x7f; //Y, 7 bits, [178:172]
        uid_x = (fuse[0]>>19)&0x7f; //X, 7 bits, [185:179]
        uid_wafer = (fuse[0]>>26)&0x1f; //Wafer, 5 bits, [190:186]

        lotid[0] = (fuse[1]>>4)&0x7f; //7 bits, [234:228]
        lotid[1] = ((fuse[1]&0xf)<<3)|((fuse[2]>>29)&0x7); //7 bits, [227:221]
        lotid[2] = (fuse[2]>>22)&0x7f; //7 bits, [220:214]
        lotid[3] = (fuse[2]>>15)&0x7f; //7 bits, [213:207]
        lotid[4] = (fuse[2]>>8)&0x7f; //7 bits, [206:200]
        lotid[5] = (fuse[2]>>1)&0x7f; //7 bits, [199:193]
    }
    else
        return;

    uart_printf("\r\n---Chip eFuse Info(%x): ---\r\n",GetChipID());
    uart_printf("lotid_0:    %3d\r\n",lotid[0]);
    uart_printf("lotid_1:    %3d\r\n",lotid[1]);
    uart_printf("lotid_2:    %3d\r\n",lotid[2]);
    uart_printf("lotid_3:    %3d\r\n",lotid[3]);
    uart_printf("lotid_4:    %3d\r\n",lotid[4]);
    uart_printf("lotid_5:    %3d\r\n",lotid[5]);
    uart_printf("X_location: %3d\r\n",uid_x);
    uart_printf("Y_location: %3d\r\n",uid_y);
    uart_printf("Wafer:      %3d\r\n",uid_wafer);

}





#define AP_16M_STR			"AP_16M"
#define WB_16M_STR			"WB_16M"
#define AP_8M8M_STR         "AP_8M8M"
#define WB_8M8M_STR         "WB_8M8M"
#define AP_8M_STR         	"AP_8M"
#define WB_8M_STR         	"WB_8M"
#define WB_250MHZ_8M_STR	"WB_250MHZ_8M"
#define AP_UHS_8M8M_STR		"AP_UHS_8M8M"
#define WB_250MHZ_8M8M_STR	"WB_250MHZ_8M8M"
#define AP_250MHZ_8M8M_STR	"AP_250MHZ_8M8M"
#define WB_XCCELA_8M_STR	"WB_XCCELA_8M"
#define WB_XCCELA_8M8M_STR	"WB_XCCELA_8M8M"
#define WB_4M_STR			"WB_4M"
#define AP_4M_STR			"AP_4M"
#define WB_XCCELA_4M_STR	"WB_XCCELA_4M"
#define AP_250MHZ_8M_STR	"AP_250MHZ_8M"
#define WB_32M_STR			"WB_32M"
#define AP_250MHZ_16M_STR	"AP_250MHZ_16M"
#define WB_250MHZ_16M_STR	"WB_250MHZ_16M"


static UINT8 get_psram_type_from_asrproperty(void)
{
	const char* psram_pro=asr_property_get("fuse.psram.type");
	//RTI_LOG("get fuse.psram.type=[%s]\r\n",psram_pro);
	if(!strcmp(psram_pro,WB_32M_STR)){
		return WB_32M;
	}else if(!strcmp(psram_pro,AP_16M_STR)){
		return AP_16M;
	}else if(!strcmp(psram_pro,WB_16M_STR)){
		return WB_16M;
	}else if(!strcmp(psram_pro,AP_8M8M_STR)){
		return AP_8M8M;
	}else if(!strcmp(psram_pro,WB_8M8M_STR)){
		return WB_8M8M;
	}else if(!strcmp(psram_pro,AP_UHS_8M8M_STR)){
		return AP_UHS_8M8M;
	}else if(!strcmp(psram_pro,WB_250MHZ_8M8M_STR)){
		return WB_250MHZ_8M8M;
	}else if(!strcmp(psram_pro,AP_250MHZ_8M8M_STR)){
		return AP_250MHZ_8M8M;
	}else if(!strcmp(psram_pro,WB_XCCELA_8M8M_STR)){
		return WB_XCCELA_8M8M;
	}else if(!strcmp(psram_pro,AP_250MHZ_16M_STR)){
		return AP_250MHZ_16M;
	}else if(!strcmp(psram_pro,WB_250MHZ_16M_STR)){
		return WB_250MHZ_16M;
	}else if(!strcmp(psram_pro,AP_8M_STR)){
		return AP_8M;
	}else if(!strcmp(psram_pro,WB_8M_STR)){
		return WB_8M;
	}else if(!strcmp(psram_pro,WB_XCCELA_8M_STR)){
		return WB_XCCELA_8M;
	}else if(!strcmp(psram_pro,AP_250MHZ_8M_STR)){
		return AP_250MHZ_8M;
	}else if(!strcmp(psram_pro,AP_4M_STR)){
		return AP_4M;
	}else if(!strcmp(psram_pro,WB_XCCELA_4M_STR)){
		return WB_XCCELA_4M;
	}else if(!strcmp(psram_pro,WB_4M_STR)){
		return WB_4M;
	}
	RTI_LOG("get fuse.psram.type=[%s] error!\r\n",psram_pro);
	while(1);
}

UINT8 readPsramFuse(void)
{
#define GEU_BASE                            0xD4201000
#define GEU_FUSE_VAL_APCFG3                 (GEU_BASE + 0x040C)
#define GEU_BLOCK3_RESERVED_191_160         (GEU_BASE + 0x04A4)
    UINT32 value, value1;
    UINT8 psram_flag;
	if(CHIP_IS_CRANELS || CHIP_IS_CRANELR){
		psram_flag=get_psram_type_from_asrproperty();//for no phy psram not have fuse about psram type,using asr property get psram type
	}else{
        *((volatile UINT32 *)0xd4282868) = 0x9;
        value = *(volatile UINT32 *)GEU_BLOCK3_RESERVED_191_160;
        value1 = *(volatile UINT32 *)GEU_FUSE_VAL_APCFG3; //bank0[93] as PSRAM type:[4] for CraneL
        *((volatile UINT32 *)0xd4282868) = 0x0;
        
        if(CHIP_IS_CRANE){
            psram_flag = (value >> 8) & 7;
        }else{
            psram_flag = (CHIP_IS_CRANEL)?(((value>>8)&0xF)|(((value1>>13)&0x1)<<4)):((value>>8)&0x1F);
        } 
	}

    CPUartLogPrintf("PSRAM fuse: %d\r\n",psram_flag);
    return psram_flag;
}

static UINT8 fuseinfo3 = 0xFF;

BOOL ifPsramSupports500M(void)
{

    if (fuseinfo3 == 0xFF)
        fuseinfo3 = readPsramFuse();
    return ((fuseinfo3 == WB_250MHZ_8M8M)||(fuseinfo3 == AP_250MHZ_8M8M));
}

BOOL ifPsramUHS(void)
{

    if (fuseinfo3 == 0xFF)
        fuseinfo3 = readPsramFuse();
    return (fuseinfo3 == AP_UHS_8M8M);
}

BOOL ifPsramLimit200M(void)
{

    if (fuseinfo3 == 0xFF)
        fuseinfo3 = readPsramFuse();
    return ((fuseinfo3 == WB_4M) || (fuseinfo3 == AP_4M));
}
UINT8 getPsramType(void)
{
    if (fuseinfo3 == 0xFF)
        fuseinfo3 = readPsramFuse();
    return fuseinfo3;
}

UINT64 Read_Crane_Flash_UID(void)
{
    if (global_flash_uid == 0)
        global_flash_uid = spi_nor_do_read_uid();
    return global_flash_uid;
}

UINT8 isChip3601S=FALSE;
UINT8 isChip3621S=FALSE;
BOOL isChip_3601S(void)
{
    static UINT8 tmp = FALSE;
    if (!tmp)
    {
        *((volatile UINT32 *)0xd4282868) = 0x09;
		//bank0[28&21], 28 for 3601S, 21 for 3621S
        isChip3601S = (*((volatile UINT32 *)0xd4201404)&(1<<12))? TRUE: FALSE;
        *((volatile UINT32 *)0xd4282868) = 0x0;
        tmp = TRUE;

    }
    uart_printf("isChip3601S:%d\r\n",isChip3601S);
    return isChip3601S;
}

BOOL isChip_3621S(void)
{
    static UINT8 tmp = FALSE;
    if (!tmp)
    {
        *((volatile UINT32 *)0xd4282868) = 0x09;
		//bank0[28&21], 28 for 3601S, 21 for 3621S
        isChip3621S = (*((volatile UINT32 *)0xd4201404)&(1<<5))? TRUE: FALSE;
        *((volatile UINT32 *)0xd4282868) = 0x0;
        tmp = TRUE;

    }
    uart_printf("isChip3621S:%d\r\n",isChip3621S);
    return isChip3621S;
}




#endif

//ICAT EXPORTED FUNCTION - OSA,OSA_DUMP,OsaListAllOsaMoudleInfo
void OSAListAllOsaModuleInfo(void)
{
	OSAListAllCreatedTasks();
	OSAListAllCreatedTimers();
	OSAListAllCreatedEventFlags();
	OSAListAllCreatedMemBlockPools();
	OSAListAllCreatedMsgQs();
	OSAListAllCreatedSemaphores();
	//OsaListAllCreatedMutexs();
	OSAListAllCreatedMemBytesPoolsStatus();
}

/* Timer0_0 is configured to free run @1MHz from BootROM. */
#define APBTIMER0_CNT_REG   0xD4014090
#define APBTIMER0_EN_REG    0xD4014000

unsigned long Timer0IntervalInMicro(unsigned long Before, unsigned long After)
{
    unsigned long temp = (After - Before);
    return temp;
}

unsigned long GetTimer0CNT(void)
{
    return *(volatile unsigned long*)APBTIMER0_CNT_REG;
}

void DelayInMilliSecond(unsigned int us)
{
    unsigned long startTime, endTime;

    startTime = GetTimer0CNT(); 
    do
    {
        endTime = GetTimer0CNT();    
    }
    while(Timer0IntervalInMicro(startTime, endTime) < us);
}

void Timer0_Switch(unsigned char OnOff)
{
    if (OnOff)
        *(volatile unsigned long*)APBTIMER0_EN_REG |= 0x1; //enable Timer0_0 (in free run)
    else
        *(volatile unsigned long*)APBTIMER0_EN_REG &= ~0x1; //disable Timer0_0 (in free run)
}
#ifdef CRANE_SOC_TEMPERATURE_SENSOR
static int data_2_celsius(uint32_t data)
{
	int celsius;
	int tsen_offset;
	static BOOL s_PrintFlag = TRUE;
	
	/* [1] Obtain the soc temperature offset corresponding to the current process parameters */
	if (IsChipCraneLS())
	{
        return (int)data/8 + TSEN_LITE_OFFSET_22nm; /* /8 correponding to register CFG[3:2] */
	}
	if( IsChipCraneG() || IsChipCraneM() ){
		// 22nm
		tsen_offset = TSEN_OFFSET_22nm;
	}else {
		// 28nm
		tsen_offset = TSEN_OFFSET_28nm;   
	}
	if( s_PrintFlag == TRUE ){
		CP_LOGI("tsen_offset:%d\r\n",tsen_offset);
		s_PrintFlag = FALSE;
	}

	/* [2] switch data into celsius value */
	celsius = ( (int)data ) * TSEN_GAIN + tsen_offset;

	return celsius;
}

static void tsensor_power_switch( UINT8 onoff )
{
    volatile UINT32 val;
   if (IsChipCraneLS())
	{
        if (onoff)
            TSEN_LITE_CRANELS->CFG |= EN_SENSOR;
        else
            TSEN_LITE_CRANELS->CFG &= ~EN_SENSOR;
        
        val=TSEN_LITE_CRANELS->CFG; //make sure the register is programmed.
	}
    else
    {
        if (onoff)    	
			TSEN->PCTRL |= EN_SENSOR;
    	else
	    	TSEN->PCTRL &= ~EN_SENSOR;

		val=TSEN->PCTRL; //make sure the register is programmed.
	}
}

static void tsensor_init1( void )
{
	/**
	 * Reset Temperature Sensor when system power on.
	 * Note: After reset, need to disable tsensor clock in order to Reduce Power Consumption.
	 */
//	Timer0_Switch(1);
//	loop_delay(1000);
//	unsigned long t1,t2;
	
	*(volatile UINT32 *)APBC_TSEN_CLK_RST = 0x3;
//	t1 = GetTimer0CNT();
	loop_delay(1000);			// delay 10us ( get data from "GetTimer0CNT") 
//	t2 = GetTimer0CNT();
	*(volatile UINT32 *)APBC_TSEN_CLK_RST = 0x0;

//	CP_LOGD("%s,t1:%d,t2:%d\r\n",__FUNCTION__,t1,t2);
}

static void tsensor_init2( void )
{
	/* Reinit reg value to prevent introducing differences from different process parameters   */
	if (IsChipCraneLS())
	{
        TSEN_LITE_CRANELS->CFG = 0xA005007; //consecutive mode and start sampling
        return;
	}
	if( IsChipCraneG() || IsChipCraneM()/* || IsChipCrane() */ ){
		/* 22nm need init CTRL and TIME_CTRL register */
		TSEN->PCTRL = 0x280889;
		TSEN->TIME_CTRL = 0x4000FF;
	}
	uart_printf("1 TSEN->PCTRL:0x%x\r\n",TSEN->PCTRL);
	uart_printf("1 TSEN->TIME_CTRL:0x%x\r\n",TSEN->TIME_CTRL);
	
	/* Note: Must power down sensor before config "TSEN PIN Control Register" */
	TSEN->PCTRL &= ~EN_SENSOR;	
	TSEN->PCTRL |= TEMP_MODE;					// consecutive test 
	TSEN->PCTRL &= ~TEMP_DATA_OUTPUT_MODE;
	TSEN->PCTRL &= ~HW_AUTO_MODEE;				// software test mode
	
	TSEN->INT_MASK |= TSEN_INT_MASK;			// disable the interrupt

	/* After config register, power on tsensor */
	TSEN->PCTRL |= EN_SENSOR;

	uart_printf("2 TSEN->PCTRL:0x%x\r\n",TSEN->PCTRL);
	uart_printf("2 TSEN->TIME_CTRL:0x%x\r\n",TSEN->TIME_CTRL);
}

static uint32_t get_polling_data( void )
{
	uint32_t data = 0;
	uint32_t timeout = 0;
	volatile static BOOL Init1_Flag = TRUE;
	volatile static BOOL Init2_Flag = TRUE;

	/* [1] reset tsensor related register. Note: only execute once */
	if( Init1_Flag == TRUE ){
		tsensor_init1();
		Init1_Flag = FALSE;
	}

	/* [2] enable tsensor clock */
	tsensor_clock_enable( TRUE );

	/* [3] config tsensor CTRL register */
	if( Init2_Flag == TRUE ){
		tsensor_init2();
		Init2_Flag = FALSE;
	}

	/* [4] power on tsensor. */
    tsensor_power_switch(TRUE);
    
	if(initState >= BSP_INIT_TASK_FINISH)
        OSATaskSleep(30); ; //requires more than 100ms, better 150ms if bandgap is off in D2, with BG_OUT 1uF.
//        OSATaskSleep(8); //with bandgap filter capacitor (BG_OUT) of 0.1uF instead of 1uF, expect 20~50ms, 40ms fine
	/* [5] get temperature data from TSEN READ DATA REGISTER */
	if (IsChipCraneLS())
    {
        data = ( TSEN_LITE_CRANELS->READ_TDATA & 0xFFF );
    }
    else
    {
		while( timeout < 3000 ){
			if( TSEN->INT_STATUS & TSEN_INT_STATUS ){
				/* The bit0 of TESN_INT_STATUS will be 1 when each temperature data calculation period is finished */
				data = ( TSEN->READ_DATA0 & 0xFFFF );
				if(data > 0)
					break;
			}
			loop_delay(1000);
			timeout++;
		}
		if(timeout == 3000){
			CP_LOGE("Tsensor: timeout %s %d\n\r", __FUNCTION__,__LINE__);
		}
    }
	/* [6] power down tsensor. */
	// Note: can not consecutive test if power down, otherwise wait 16ms after power on.
    tsensor_power_switch(FALSE); //to save power, and powering up Tsen again is required when bandgap once off.
    
	/* [7] disable tsensor clock */
	tsensor_clock_enable( FALSE );
	
	return data;
}

static void tsensor_clock_enable( BOOL FLAG )
{
	/**
	  * when use tsensor, enable temperature sensor clock.
	  * After use, disable temperature in order to Reduce Power Consumption.
	  * Note: After close tsensor clock, read register value will be UNRELIABLE.
	  */
	if( FLAG == TRUE ){
		*(volatile UINT32 *)0xd401506c = 0x1;		// enable temperature sensor clock
	}else{
		*(volatile UINT32 *)0xd401506c = 0x0;		// disable temperature sensor clock.
	}
}


static void dump_tsensor_register( void )
{
	CP_LOGD("TSEN_CLK_RST:0x%.08x\r\n",*(volatile UINT32 *)APBC_TSEN_CLK_RST);
	CP_LOGD("TSEN->PCTRL:0x%.08x\r\n",TSEN->PCTRL);
	CP_LOGD("TSEN->INT_MASK:0x%.08x\r\n",TSEN->INT_MASK);
}




int getTsensorTemperatureCelsiusValue( void )
{
	UINT32 data;
	int celsius;

    if (CHIP_IS_CRANELR)
    {
        RTI_LOG("CraneLR has no Tsensor!");
        return -1;
    }
	data = get_polling_data();
	celsius = data_2_celsius(data);
		
	return celsius;
}

UINT32 getTsensorTemperatureRawValue( void )
{
	UINT32 data;
	
	data = get_polling_data();
	
	return data;
}


#ifdef ADD_TSENSOR_DEBUG
void Test_Tsensor(VOID *argv)
{
	int celsius;
	unsigned long t1,t2;

	static UINT32 index = 0;

	OSATaskSleep( 200 * 10 );	// delay 10s

	/* test case1 */
	while(1){
		t1 = GetTimer0CNT();
		celsius = getTsensorTemperatureCelsiusValue();
		t2 = GetTimer0CNT();
		index++;
		CP_LOGI("[%d],tsen-->  Current temperature: %d Celsius, time_delat: %d\n\r", index,celsius, t2 - t1);
		OSATaskSleep( 200 * 5 );	// delay 5s
	}
}

OSTaskRef SOC_TSENSOR_TASK_Ref;
__align(4) unsigned char SOC_TSENSOR_TASK_Stack[2048];
void Create_Test_Tsensor_Task(void)
{
	OSA_STATUS status;

	status = OSATaskCreate(&SOC_TSENSOR_TASK_Ref, SOC_TSENSOR_TASK_Stack, 2048, 102, "SOC_TSENSOR", Test_Tsensor, NULL);
    ASSERT(status == OS_SUCCESS);
}

#endif	/* ADD_TSENSOR_DEBUG */
#endif	/* CRANE_SOC_TEMPERATURE_SENSOR */

#define GEU_FUSE_BANK0_239_208         (0xD4201000 + 0x0414)
#define GEU_FUSE_BANK0_255_240         (0xD4201000 + 0x04C8)
#ifndef LTEONLY_THIN
#ifdef ASR_PLATFORM_CRANEM

extern UINT32 AdcCheckFlag[];
extern UINT32 CommunicationInitsDone;


#define INIT_ADC_VALUE  (0xFFEE)
#define READ_TIMES      (5)

static void MrdSwap( MrdAdc_t *p_MrdAdcData1, MrdAdc_t *p_MrdAdcData2 )
{
	volatile MrdAdc_t temp;

	temp.AdcValue = p_MrdAdcData2->AdcValue;
//	temp.DataValid = p_MrdAdcData2->DataValid;		// as valid is same, so skip this statement
	temp.VoltageValue = p_MrdAdcData2->VoltageValue;

	p_MrdAdcData2->AdcValue = p_MrdAdcData1->AdcValue;
	p_MrdAdcData2->VoltageValue = p_MrdAdcData1->VoltageValue;

	p_MrdAdcData1->AdcValue = temp.AdcValue;
	p_MrdAdcData1->VoltageValue = temp.VoltageValue;
}


void MrdBubbleSort( MrdAdc_t *p_MrdAdcData[],const UINT32 DataNum )
{
	INT32 i,j;

	for( i = 0; i < DataNum - 1; i++ )
		for( j = 0; j < DataNum - 1 - i; j++ )
			if( p_MrdAdcData[j]->AdcValue > p_MrdAdcData[j+1]->AdcValue )
				MrdSwap(p_MrdAdcData[j],p_MrdAdcData[j+1]);
}


typedef struct vbatadc
{
    INT16 x; //adc_val
    INT16 y; //vbat
}__vbatadc;

__vbatadc vbat_pm803_def[TEMP_TYPE_MAX][MAX_ADC_GROUP_CNT] =
//__vbatadc vbat_pm803_def[] =
{
   { {497,3265},
    {502,3319},
    {514,3446},
    {521,3519},
    {535,3656},
    {541,3741},
    {548,3809},
    {558,3922},
    {569,4039},
    {580,4150}},
   	{0},
   	{0}
};
int MrdValueNum[TEMP_TYPE_MAX] = {MAX_ADC_GROUP_CNT,MAX_ADC_GROUP_CNT, MAX_ADC_GROUP_CNT};

int MrdValueNum_rtp = MAX_ADC_GROUP_CNT;
__vbatadc rtp_pm803_def[MAX_ADC_GROUP_CNT] =
{
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0}
};


INT16 rtn_pm803_def[2] =
{
    323,/*for 400mV*/
    651 /*for 1600mV*/
};

void rf_rtn_adc_calib_init(void)
{

    UINT32 value1,value2;
    INT16 adcVal1,adcVal2;
    
    *((volatile UINT32 *)0xd4282868) = 0x9;
    value1 = *(volatile UINT32 *)GEU_FUSE_BANK0_239_208;
    value2 = *(volatile UINT32 *)GEU_FUSE_BANK0_255_240;
    *((volatile UINT32 *)0xd4282868) = 0x0;

    if ((value1==0)||(value2==0))
    {
        //RTI_LOG("No ATE calibration for RF ADC...\r\n");
        return; //no calibration applied
    }
    adcVal1 = ((value2&0x3F)<<4)|(value1>>28); //fuse_bank0[245:236]
    adcVal2 = value2>>6; //fuse_bank0[255:246]

    if(CHIP_IS_CRANEM)
    {
        rtn_pm803_def[0]=adcVal2;
        rtn_pm803_def[1]=adcVal1;
    }
    else if(CHIP_IS_CRANEG)
    {
        rtn_pm803_def[0]=adcVal1;
        rtn_pm803_def[1]=adcVal2;
    }
    RTI_LOG("\r\nRF ADC value %d@400mV, %d@1600mV\r\n", rtn_pm803_def[0],rtn_pm803_def[1]);
}

void vbat_pm803_init_temp(PM803_ADC_TYPE type, ADC_TEMP_t tempType)
{
    /* If vbat calib data are valid, clear the default vbat_pm803_def[] values, and get real values from flash, and then make sorting, thus the real data are ready for use. */
	INT32 MRD_GetValueRes = -1;
	volatile MrdAdc_t temp_MrdData;
	//MrdAdc_t MrdDataStructure[MAX_ADC_GROUP_CNT];
	MrdAdc_t *MrdDataStructure[MAX_ADC_GROUP_CNT] = { NULL };
	UINT8 i, MrdValidDataNum = 0;

	PM803_ADC_TYPE adc_type=type;
	int *pMrdValueNum = NULL;
	__vbatadc *pAdcCalData = NULL;

    CPUartLogPrintf("%s: enter, type=%d, tempType=%d",__FUNCTION__,adc_type,tempType);

	if(adc_type == ADC_VBAT)
	{
		pMrdValueNum = &MrdValueNum[tempType];
		pAdcCalData = vbat_pm803_def[tempType];
	}
	else
	{
		pMrdValueNum = &MrdValueNum_rtp;
		pAdcCalData = rtp_pm803_def;
	}
    if ((MRDAdcFlagGet(adc_type, tempType))||(AdcCheckFlag[adc_type]==1))
    {
        memset(pAdcCalData, 0, sizeof(vbat_pm803_def)/TEMP_TYPE_MAX);

    	/* get MRD value number */
    	*pMrdValueNum = MRDAdcCntGet(adc_type, tempType);
    	if( *pMrdValueNum > MAX_ADC_GROUP_CNT || *pMrdValueNum < 2 ){
    		CPUartLogPrintf("[DSP_ADC] MrdValueNum: %d is error!\r\n",*pMrdValueNum);
		DIAG_FILTER(MRD,vbat_pm803_init,lab001,DIAG_INFORMATION)
		diagPrintf("MrdValueNum: %d is error!",*pMrdValueNum);
    		return;
    	}
    	/* get MRD value and sort */
    	for( i = 0; i < MAX_ADC_GROUP_CNT; i++ ){

            if((MrdDataStructure[i] = (MrdAdc_t *)calloc(1, sizeof(MrdAdc_t))) == NULL)
            {
                CPUartLogPrintf("%s: calloc error\n", __FUNCTION__);
                goto error;
            }


    		MRD_GetValueRes = MRDAdcValueGet( i, (UINT32 *)&temp_MrdData.AdcValue, (UINT32 *)&temp_MrdData.VoltageValue,adc_type,tempType);
    		if( MRD_GetValueRes != 0 ){
    			if( MRD_GetValueRes != 1 ){
    				CPUartLogPrintf("[DSP_ADC] %s, MRD get value fail, MRD_GetValueRes:%d\r\n",__func__,MRD_GetValueRes);
				DIAG_FILTER(MRD,vbat_pm803_init,lab002,DIAG_INFORMATION)
				diagPrintf("MRD get value fail, MRD_GetValueRes:%d\r\n",__func__,MRD_GetValueRes);
    			}
    			continue;
    		}
    		MrdDataStructure[MrdValidDataNum]->AdcValue = temp_MrdData.AdcValue;
    		MrdDataStructure[MrdValidDataNum]->VoltageValue = temp_MrdData.VoltageValue;
    		MrdValidDataNum++;
    	}
    	DIAG_FILTER(MRD,vbat_pm803_init,lab003,DIAG_INFORMATION)
    	diagPrintf("MrdValidDataNum:%d,MrdValueNum:%d",MrdValidDataNum,*pMrdValueNum);
    	if( MrdValidDataNum != *pMrdValueNum ){
    		CPUartLogPrintf("[DSP_ADC] MrdValidDataNum is not match with MrdValueNum!\r\n");
    		CPUartLogPrintf("MrdValidDataNum:%d,MrdValueNum:%d\r\n",MrdValidDataNum,*pMrdValueNum);
    		//return;
    		goto error;
    	}

    	MrdBubbleSort(MrdDataStructure,MrdValidDataNum);	// only spend 4us to execute bubble sort

#if 1
    	// dump MRD value
    	CPUartLogPrintf("Dump %s cal data",(adc_type == ADC_VBAT)?"VBAT":"RTP");
    	CPUartLogPrintf("index		%s		%s\r\n","MrdAdc  ","MrdVoltage");
    	for( i = 0; i < *pMrdValueNum; i++ )
    	{
    		CPUartLogPrintf("%5d		%.08d		%.08d\r\n",i,MrdDataStructure[i]->AdcValue, MrdDataStructure[i]->VoltageValue);
    	}
#endif
        for (i=0;i<*pMrdValueNum;i++)
        {
            pAdcCalData[i].x = (INT16)MrdDataStructure[i]->AdcValue;
            pAdcCalData[i].y = (INT16)MrdDataStructure[i]->VoltageValue;
        }


error:

    	for( i = 0; i < MAX_ADC_GROUP_CNT; i++ ){

            if(MrdDataStructure[i] != NULL){
                free(MrdDataStructure[i]);
                MrdDataStructure[i] = NULL;
            }
    	}

		RTI_LOG("%s, %s ADC, CalCnt:%d, CalFlg:%d", __func__, (adc_type == ADC_VBAT)?"VBAT":"RTP", *pMrdValueNum, MRDAdcFlagGet(adc_type,tempType));
    }
	else
	{
		DIAG_FILTER(MRD,vbat_pm803_init,lab004,DIAG_INFORMATION)
		diagPrintf("Not Init!");
	}

	CPUartLogPrintf("%s: leave",__FUNCTION__);
}

void vbat_pm803_init(void)
{
	ADC_TEMP_t i=0;

	for(i=0;i<TEMP_TYPE_MAX;i++)
		vbat_pm803_init_temp(ADC_VBAT, i);			//VBAT ADC
	vbat_pm803_init_temp(ADC_RTP, TEMP_NORMAL);	//RTP ADC
    rf_rtn_adc_calib_init();
}
INT16 curVbatAdc = 0;
//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetPm803VbatAdc
INT16 GetPm803VbatAdc(ADC_TEMP_t tempType)
{
    float slope=0;
    INT16 intercept=0, calVbat;
    UINT8 i=0,index=0;

	volatile UINT8 count1 = READ_TIMES;
	volatile UINT32 delay1 = 0x20000;

	if (!PMIC_IS_PM803()){
		DIAG_FILTER(MRD,GetPm803VbatAdc,lab001,DIAG_INFORMATION)
		diagPrintf("Not support vbat_adc since NOT PM803... ");
		return -1;
	}

	if(CommunicationInitsDone==0)
	{
		CP_LOGI("PS not done\r\n");
		DIAG_FILTER(MRD,GetPm803VbatAdc,lab002,DIAG_INFORMATION)
		diagPrintf("PS not done");
		return -2;
	}

	/* [3] get vbat from dsp (RD ADC module) */
	count1 = READ_TIMES;
	setAdcValue(INIT_ADC_VALUE);	// clear ADC value before reading
	do{
		CP_LOGD("INIT value: 0x%x\r\n",getAdcValue());
		L1aAdcValueQueryReq();		// send IPC message to DSP. ( NOTE: dsp must be in ready before sending)

		if( READ_TIMES == count1-- ){
		// Case1 - First time: use softdelay to wait ADC value to decrease time
		SoftDelay(delay1);
		}else{
		// Case2 - Except for the first time
		OSATaskSleep(1);
		}
		curVbatAdc = getAdcValue();
#ifdef QUECTEL_PROJECT_CUST
		}while( count1 != 0 && (curVbatAdc == INIT_ADC_VALUE || curVbatAdc == 0));
#else
		}while( count1 != 0 && curVbatAdc == INIT_ADC_VALUE  );
#endif

	/* [4] check read adc value valid ? */
	if( curVbatAdc == INIT_ADC_VALUE )
	{
		DIAG_FILTER(MRD,GetPm803VbatAdc,lab003,DIAG_INFORMATION)
		diagPrintf("get VbatAdc fail after reading several times from IPC");
		return -3;
	}

	CPUartLogPrintf("count:%d,tempType: %d, GetVbatAdc = %d\r\n", count1,tempType, curVbatAdc);
	DIAG_FILTER(MRD,GetPm803VbatAdc,lab004,DIAG_INFORMATION)
	diagPrintf("count:%d,tempType: %d, GetVbatAdc = %d", count1,tempType, curVbatAdc);

	/* [5] switch vbat adc value into real vbat(unit:mv) */
    for (i=1;i<MrdValueNum[tempType];i++)
    {
        if (curVbatAdc<vbat_pm803_def[tempType][i].x)
        {
            index=i-1;
            break;
        }
    }
    if (i==MrdValueNum[tempType])
    {
        index=i-2;
    }
    CPUartLogPrintf("vbat_index = %d\r\n",index);
    slope = (float)(vbat_pm803_def[tempType][index+1].y-vbat_pm803_def[tempType][index].y)/(vbat_pm803_def[tempType][index+1].x-vbat_pm803_def[tempType][index].x);
    CPUartLogPrintf("vbat_slope = %.3f\r\n",slope);
    intercept = vbat_pm803_def[tempType][index].y - (INT16)(slope * vbat_pm803_def[tempType][index].x);
    CPUartLogPrintf("vbat_intercept = %d\r\n",intercept);

	calVbat = (INT16)(slope*curVbatAdc+intercept);
//	calVbat = (INT16)(slope*curRtpAdc_avg+intercept);
	CPUartLogPrintf("calVbat = %d\r\n",calVbat);
	DIAG_FILTER(MRD,GetPm803VbatAdc,lab005,DIAG_INFORMATION)
	diagPrintf("calVbat = %d",calVbat);

    return calVbat;
}

//ICAT EXPORTED FUNCTION - SW_PLAT, utilities, GetRfAdcForVbat
INT16 GetRfAdcForVbat(void)
{
	if (!PMIC_IS_PM803())
	{
		DIAG_FILTER(MRD,GetPm803VbatAdc_mrd,lab001,DIAG_INFORMATION)
		diagPrintf("Not support vbat_adc since NOT PM803... ");
		return -1;
	}

	if(CommunicationInitsDone==0)
	{
		CPUartLogPrintf("PS not done\r\n");
		return -2;
	}
	L1aAdcValueQueryReq();
	OSATaskSleep(1); //delay to wait for IPC feedback
	curVbatAdc = getAdcValue();
	DIAG_FILTER(MRD,GetPm803VbatAdc_mrd,lab002,DIAG_INFORMATION)
	diagPrintf("GetVbatAdc = %d", curVbatAdc);

	return curVbatAdc;
}

INT16 curRtnAdc = 0;
//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetPm803RtnAdc
INT16 GetPm803RtnAdc(void)
{
    float slope=0;
    INT16 intercept=0, calRtn;

	#define INIT_ADC_VALUE	(0xFFEE)
	#define READ_TIMES		(5)
	volatile UINT8 count = READ_TIMES;
	volatile UINT32 delay = 0x10000;
	
	/* [1] check pmic id: pm803 or not */
    if (!PMIC_IS_PM803()){
        uart_printf("Not support vbat_adc since NOT PM803... ");
        return -1;
    }

    /* [2] check dsp status: ready or not */
	if(CommunicationInitsDone==0)
	{
		CPUartLogPrintf("PS not done\r\n");
		return -2;
	}

    /* [3] get AUXADCIN1_RTN from dsp (RD ADC module) */
    setAdcValue(INIT_ADC_VALUE);    // clear ADC value before reading
    do{
        uart_printf("INIT value: 0x%x\r\n",getAdcValueForRtn());
        L1aAdcValueQueryReqExt(2,0);      // send IPC message to DSP for RTN path. ( NOTE: dsp must be in ready before sending)

        if( READ_TIMES == count-- ){
            // Case1 - First time: use softdelay to wait ADC value to decrease time
            SoftDelay(delay);
        }else{
            // Case2 - Except for the first time
            OSATaskSleep(1);
        }
        curRtnAdc = getAdcValueForRtn();
    }while( count != 0 && curRtnAdc == INIT_ADC_VALUE );

    /* [4] check read adc value valid ? */
    if( curRtnAdc == INIT_ADC_VALUE ){
        RTI_LOG("get RfAdcForRTN fail after reading several times from IPC\r\n");
        return -3;
    }

    //uart_printf("\r\ncount:%d,GetRtnAdc = %d\r\n", count,curRtnAdc);

	/* [5] switch RTN adc value into real voltage(unit:mv) */
    slope = (float)(1600-400)/(rtn_pm803_def[1]-rtn_pm803_def[0]);
    uart_printf("vRtn_slope = %.3f\r\n",slope);
    intercept = 400 - (INT16)(slope * rtn_pm803_def[0]);
    uart_printf("vRtn_intercept = %d\r\n",intercept);

    calRtn = (INT16)(slope*curRtnAdc+intercept);
    RTI_LOG("calRtnVol = %d, curRtnAdc = %d\r\n",calRtn,curRtnAdc);
	
    return calRtn;
}

/* Vbat = Vin * (R3+R4//(R1+R2)) / (R4//(R1+R2)), 
R3 and R4 should be in Kohm unit. Here "R1+R2" is fixed to be 160*9 (unit: Kohm). */

INT16 auxAdcRtn_Resistor3 = 680; //in Kohm
INT16 auxAdcRtn_Resistor4 = 470; //in Kohm

//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetAuxAdcRtnVbat_Cust
INT16 GetAuxAdcRtnVbat_customized(void)
{
    INT16 Res3 = auxAdcRtn_Resistor3;
    INT16 Res4 = auxAdcRtn_Resistor4;
    INT16 calRtn,AuxVbat;
    float tmp;

    uart_printf("r3 = %d, r4 = %d\r\n", Res3, Res4);
    calRtn=GetPm803RtnAdc();
    tmp = (float)Res3/Res4+(float)Res3/(160*9)+1;
    uart_printf("r3_r4 cal= %.3f\r\n", tmp);
    AuxVbat = (INT16)(calRtn * tmp);
    RTI_LOG("GetAuxAdcRtnVbat_customized = %d\r\n",AuxVbat);
	return AuxVbat;
}

static void SoftDelay( volatile UINT32 delay )
{
	while(delay--);
}

 //added for rtp cal
INT16 curRfAdc_Rtp = 0;

//ICAT EXPORTED FUNCTION - SW_PLAT, utilities, GetRfAdcForRTP
INT16 GetRfAdcForRTP(void)
{
    volatile UINT8 count1 = READ_TIMES;
    volatile UINT32 delay1 = 0x10000;

    /* [2] check dsp status: ready or not */
	if(CommunicationInitsDone==0)
	{
		CPUartLogPrintf("PS not done\r\n");
		return -2;
	}

    /* [3] get AUXADCIN1_RTP from dsp (RD ADC module) */
    setAdcValueForRtp(INIT_ADC_VALUE);    // clear ADC value before reading
    do{
        CPUartLogPrintf("INIT value: 0x%x\r\n",getAdcValueForRtp());
        L1aAdcValueQueryReqExt(2,1);      // send IPC message to DSP for RTP path. ( NOTE: dsp must be in ready before sending)

        if( READ_TIMES == count1-- ){
            // Case1 - First time: use softdelay to wait ADC value to decrease time
            SoftDelay(delay1);
        }else{
            // Case2 - Except for the first time
            OSATaskSleep(1);
        }
        curRfAdc_Rtp = getAdcValueForRtp();
    }while( count1 != 0 && curRfAdc_Rtp == INIT_ADC_VALUE );

    /* [4] check read adc value valid ? */
    if( curRfAdc_Rtp == INIT_ADC_VALUE ){
        CPUartLogPrintf("get RfAdcForRTP fail after reading several times from IPC\r\n");
        return -3;
    }

	DIAG_FILTER(MRD,GetPm80RtpAdc_mrd,lab002,DIAG_INFORMATION)
	diagPrintf("curRfAdc_Rtp = %d", curRfAdc_Rtp);

    RTI_LOG("\r\ncount:%d,GetRfAdcForRTP = %d\r\n", count1,curRfAdc_Rtp);
    return curRfAdc_Rtp;
}


//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetPm803VrtpAdc
INT16 GetPm803VrtpAdc(void)
{
    float slope=0;
    INT16 intercept=0, calVbat;
    UINT8 i=0,index=0;	
	volatile UINT8 count1 = READ_TIMES;
    volatile UINT32 delay1 = 0x10000;

	if (!PMIC_IS_PM803())
	{
		DIAG_FILTER(MRD,GetPm803VrtpAdc,lab001,DIAG_INFORMATION)
		diagPrintf("%s,Not support vbat_adc since NOT PM803... ",__func__);
		return -1;
	}
	if(CommunicationInitsDone==0)
	{
		CP_LOGI("PS not done\r\n");
		DIAG_FILTER(MRD,GetPm803VrtpAdc,lab002,DIAG_INFORMATION)
		diagPrintf("PS not done");
		return -2;
	}
#if 0      
	L1aAdcValueQueryReqExt(2,1);
    OSATaskSleep(1); //delay to wait for IPC feedback
    curRfAdc_Rtp = getAdcValueForRtp();
	curRtpAdc_avg = curRfAdc_Rtp;
    CPUartLogPrintf("curRfAdc_Rtp = %d\r\n", curRfAdc_Rtp);
#else
		count1 = READ_TIMES;
		/* [3] get AUXADCIN1_RTP from dsp (RD ADC module) */
	    setAdcValueForRtp(INIT_ADC_VALUE);    // clear ADC value before reading
	    do{
	        CPUartLogPrintf("INIT value: 0x%x\r\n",getAdcValueForRtp());
	        L1aAdcValueQueryReqExt(2,1);      // send IPC message to DSP for RTP path. ( NOTE: dsp must be in ready before sending)

	        if( READ_TIMES == count1-- ){
	            // Case1 - First time: use softdelay to wait ADC value to decrease time
	            SoftDelay(delay1);
	        }else{
	            // Case2 - Except for the first time
	            OSATaskSleep(1);
	        }
	        curRfAdc_Rtp = getAdcValueForRtp();
#ifdef QUECTEL_PROJECT_CUST
	    }while( count1 != 0 && (curRfAdc_Rtp == INIT_ADC_VALUE || curRfAdc_Rtp == 0));
#else
	    }while( count1 != 0 && curRfAdc_Rtp == INIT_ADC_VALUE );
#endif

#ifdef QUECTEL_PROJECT_CUST
		if(curRfAdc_Rtp == INIT_ADC_VALUE && curRfAdc_Rtp != 0)
#else
	if( curRfAdc_Rtp == INIT_ADC_VALUE )
#endif
	{
		DIAG_FILTER(MRD,GetPm803VrtpAdc,lab003,DIAG_INFORMATION)
		diagPrintf("get GetPm803VrtpAdc fail after reading several times from IPC\r\n");
		return -3;
	}
	CPUartLogPrintf("count:%d,curRfAdc_Rtp = %d\r\n", count1, curRfAdc_Rtp);
	DIAG_FILTER(MRD,GetPm803VrtpAdc,lab004,DIAG_INFORMATION)
	diagPrintf("count:%d,curRfAdc_Rtp = %d", count1, curRfAdc_Rtp);
#endif

    for (i=1;i<MrdValueNum_rtp;i++)
    {
        if (curRfAdc_Rtp<rtp_pm803_def[i].x)
        {
            index=i-1;
            break;
        }
    }
    if (i==MrdValueNum_rtp)
    {
        index=i-2;
    }
    CPUartLogPrintf("rtp_index = %d\r\n",index);
    slope = (float)(rtp_pm803_def[index+1].y-rtp_pm803_def[index].y)/(rtp_pm803_def[index+1].x-rtp_pm803_def[index].x);
    CPUartLogPrintf("rtp_slope = %.3f\r\n",slope);
    intercept = rtp_pm803_def[index].y - (INT16)(slope * rtp_pm803_def[index].x);
    CPUartLogPrintf("rtp_intercept = %d\r\n",intercept);

    //calVbat = (INT16)(slope*curRfAdc_Rtp+intercept);
	calVbat = (INT16)(slope*curRfAdc_Rtp+intercept);

	CPUartLogPrintf("curRfAdc_Rtp=%d, rtpcalVbat = %d\r\n",curRfAdc_Rtp, calVbat);
	DIAG_FILTER(MRD,GetPm803VrtpAdc,lab005,DIAG_INFORMATION)
	diagPrintf("curRfAdc_Rtp=%d, rtpcalVbat = %d",curRfAdc_Rtp, calVbat);
	return calVbat;
}

INT16 curRtpAdc = 0;
//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetPm803RtpAdc
INT16 GetPm803RtpAdc(void)
{
    float slope=0;
    INT16 intercept=0, calRtp;

	#define INIT_ADC_VALUE	(0xFFEE)
	#define READ_TIMES		(5)
	volatile UINT8 count = READ_TIMES;
	volatile UINT32 delay = 0x10000;
	
	/* [1] check pmic id: pm803 or not */
    if (!PMIC_IS_PM803()){
        uart_printf("Not support vbat_adc since NOT PM803... ");
        return -1;
    }

    /* [2] check dsp status: ready or not */
	if(CommunicationInitsDone==0)
	{
		CPUartLogPrintf("PS not done\r\n");
		return -2;
	}

    /* [3] get AUXADCIN1_RTP from dsp (RD ADC module) */
    setAdcValueForRtp(INIT_ADC_VALUE);    // clear ADC value before reading
    do{
        uart_printf("INIT value: 0x%x\r\n",getAdcValueForRtp());
        L1aAdcValueQueryReqExt(2,1);      // send IPC message to DSP for RTP path. ( NOTE: dsp must be in ready before sending)

        if( READ_TIMES == count-- ){
            // Case1 - First time: use softdelay to wait ADC value to decrease time
            SoftDelay(delay);
        }else{
            // Case2 - Except for the first time
            OSATaskSleep(1);
        }
        curRtpAdc = getAdcValueForRtp();
    }while( count != 0 && curRtpAdc == INIT_ADC_VALUE );

    /* [4] check read adc value valid ? */
    if( curRtpAdc == INIT_ADC_VALUE ){
        RTI_LOG("get RfAdcForRTP fail after reading several times from IPC\r\n");
        return -3;
    }

    uart_printf("\r\ncount:%d,GetRtpAdc = %d\r\n", count,curRtpAdc);

	/* [5] switch RTP adc value into real voltage(unit:mv) */
    slope = (float)(1600-400)/(rtn_pm803_def[1]-rtn_pm803_def[0]);
    uart_printf("vRtp_slope = %.3f\r\n",slope);
    intercept = 400 - (INT16)(slope * rtn_pm803_def[0]);
    uart_printf("vRtp_intercept = %d\r\n",intercept);

    calRtp = (INT16)(slope*curRtpAdc+intercept);
    RTI_LOG("calRtpVol = %d, curRtpAdc=%d\r\n",calRtp,curRtpAdc);
	
    return calRtp;
}
#endif
#endif

static INT8 craneL_adc_calibration_value_def[2] =
{
    0,   /* gain_error_efuse */
    0    /* offset_efuse */
};

#define GEU_BASE                       0xD4201000
//#define GEU_FUSE_BANK0_239_208         (GEU_BASE + 0x0414)
#define GEU_FUSE_BANK3_255_224         (GEU_BASE + 0x0420)

static void craneL_adc_calibration_value_get(void)
{
    UINT32 bank0_239_208, bank3_255_224;
    INT8 gain_error_efuse, offset_efuse;

    *((volatile UINT32 *)0xd4282868) = 0x9;
    bank0_239_208 = *(volatile UINT32 *)GEU_FUSE_BANK0_239_208;
    bank3_255_224 = *(volatile UINT32 *)GEU_FUSE_BANK3_255_224;
    *((volatile UINT32 *)0xd4282868) = 0x0;
    //RTI_LOG("bank0_239_208 %08x, bank3_255_224 %08x", bank0_239_208, bank3_255_224);

    if ((bank3_255_224 & 0x80000000) == 0x80000000) {
        gain_error_efuse = (bank0_239_208 & 0x000003E0) >> 5;
        offset_efuse = bank0_239_208 & 0x0000001F;
        /** gain_error_efuse and offset_efuse store complement in fuse **/
        craneL_adc_calibration_value_def[0] = ((gain_error_efuse & 0x10) != 0x10) ? gain_error_efuse : (gain_error_efuse - 32); // fuse_bank0[217:213]
        craneL_adc_calibration_value_def[1] = ((offset_efuse & 0x10) != 0x10) ? offset_efuse : (offset_efuse - 32); // fuse_bank0[212:208]
        //RTI_LOG("gain_error_efuse %d, offset_efuse %d", craneL_adc_calibration_value_def[0], craneL_adc_calibration_value_def[1]);
    }
}

#define GEU_FUSE_BANK0_47_16         (GEU_BASE + 0x0404)
//#define GEU_FUSE_BANK0_255_240       (GEU_BASE + 0x04C8) // bit31:16 reserved
#define APB_SPARE_BASE               0xD4090000
#define APB_SPARE2_REGISTER          (APB_SPARE_BASE + 0x104)

static void craneL_adc_band_gap_trim_value_set(void)
{
    UINT32 band_gap_trim_value, bank0_47_16, bank0_255_240, bank3_255_224;

    *((volatile UINT32 *)0xd4282868) = 0x9;
    bank0_47_16 = *(volatile UINT32 *)GEU_FUSE_BANK0_47_16;
    bank0_255_240 = *(volatile UINT32 *)GEU_FUSE_BANK0_255_240;
    bank3_255_224 = *(volatile UINT32 *)GEU_FUSE_BANK3_255_224;
    *((volatile UINT32 *)0xd4282868) = 0x0;
    //CPUartLogPrintf("bank3_255_224 %08x, bank0_47_16 %08x, bank0_255_240 %08x", bank3_255_224, bank0_47_16, bank0_255_240);

    if ((bank3_255_224 & 0x80000000) == 0x80000000) {
        if (IsChipCraneLS() || IsChipCraneLR()) { //CraneLS/LR donot need check fuse table version
            *((volatile UINT32 *)APB_SPARE2_REGISTER) &= ~0x3f000000; // clear bg_reg[5:4](rtemp) and bg_reg[3:0]
            if(IsChipCraneLS())
            {
                band_gap_trim_value = bank0_255_240 & 0x000001e0;
                *((volatile UINT32 *)APB_SPARE2_REGISTER) |= ((band_gap_trim_value << 19) & 0x0f000000) | 0x10000000;
            } else {
                band_gap_trim_value = bank0_47_16 & 0xf0000000;
                *((volatile UINT32 *)APB_SPARE2_REGISTER) |= ((band_gap_trim_value >> 4) & 0x0f000000) | 0x10000000;
            }
            //CPUartLogPrintf("band gap register %08x", *((volatile UINT32 *)APB_SPARE2_REGISTER));
        } else { //craneL
            *((volatile UINT32 *)APB_SPARE2_REGISTER) &= ~0x1f000000; // clear bg_reg[4:2] and bg_reg[1:0](rtemp)
            if ((bank0_255_240 & 0x00004000) == 0x00004000) { // fuse table verison(after 0511.2022)
                band_gap_trim_value = bank0_47_16 & 0x70000000;
                *((volatile UINT32 *)APB_SPARE2_REGISTER) |= ((band_gap_trim_value >> 2) & 0x1c000000) | 0x02000000;
                //CPUartLogPrintf("post fuse table version, band gap register %08x", *((volatile UINT32 *)APB_SPARE2_REGISTER));
            } else {
                *((volatile UINT32 *)APB_SPARE2_REGISTER) |= 0x0d000000;
                //CPUartLogPrintf("pre fuse table version, band gap register %08x", *((volatile UINT32 *)APB_SPARE2_REGISTER));
            }
        }
		CPUartLogPrintf("band gap register %08x", *((volatile UINT32 *)APB_SPARE2_REGISTER));
        delay_us(1);
    }
}
static OSFlagRef ADCDoneFlgRef = NULL;
#if !defined(NOT_SUPPORT_PM803L)
static void SetRatioDivRes(unsigned char ratio);
#endif

void cranel_adc_init1(void)
{
    if (IsChipCraneL() || IsChipCraneLS()||IsChipCraneLR()) {
        *(volatile UINT32 *)APBC_TSEN_CLK_RST = 0x1;
        *(volatile UINT32 *)0xD40133F0 = 0x1; // clr int
        delay_us(10);
        craneL_adc_band_gap_trim_value_set();
        craneL_adc_calibration_value_get();

#if !defined(NOT_SUPPORT_PM803L)
        if (IsChipCraneLS() || IsChipCraneLR()) {
            SetRatioDivRes(0x01); // according to PMIC AE coworker's(weijing) recommendation, write 0x01 to vinldo_sns
        }
#endif
    }
}

static void adc_int(INTC_InterruptInfo src)
{
    *(volatile UINT32 *)0xD40133F0 = 0x1; // clr int
    OSAFlagSet(ADCDoneFlgRef, 0x01, OSA_FLAG_OR);
}

static OSASemaRef adc_Sema = NULL;
static void Adc_mutex_init(void)
{
    OSA_STATUS status;
    status = OSASemaphoreCreate(&adc_Sema, 1, OSA_FIFO);
    ASSERT(status == OS_SUCCESS);
    CPUartLogPrintf("Adc_mutex_init!!!!!");
    //s_adc_mutex = UOS_NewMutex("get_adc_mutex");
}

#define AUXADC_INT0      INTC_SRC_SM
void cranel_adc_init2(void)
{
    INTC_ReturnCode intcStatus;

    if (IsChipCraneL() || IsChipCraneLS()||IsChipCraneLR()) {
        intcStatus = INTCConfigure(AUXADC_INT0, INTC_IRQ, INTC_RISING_EDGE);
        ASSERT(intcStatus == INTC_RC_OK);
        INTCUnbind(AUXADC_INT0);
        intcStatus = INTCBind(AUXADC_INT0, adc_int);
        ASSERT(intcStatus == INTC_RC_OK);
        INTCEnable(AUXADC_INT0);

        ASSERT(OSAFlagCreate(&ADCDoneFlgRef) == OS_SUCCESS);
        Adc_mutex_init();
    }
}

static void sort(UINT16 *a, UINT8 l)
{
	UINT8 i, j;
	UINT16 v;

	for(i = 0; i < l - 1; i++) {
		for(j = i + 1; j < l; j++) {
			if(a[i] > a[j]) {
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
    }
}

static UINT16 average(UINT16 *a, UINT8 l)
{
    UINT8 i = 0;
    UINT32 sum = 0;

    for (i = 0; i < l; i++) {
        sum += a[i];
    }

    return (UINT16)(sum / l);
}

/** vin_ measure = adc*(1200+gain_error_efuse*2mV)/4096 + offset_efuse*2*1200/4096
 ** 1200mv is reference source
 **/
static UINT16 adc_value_calibrate(UINT16 adc, UINT16 ref)
{
	int cal_value;
	cal_value = (adc*(ref+craneL_adc_calibration_value_def[0]*2)/4096 + (craneL_adc_calibration_value_def[1]*2*ref)/4096);
	//增加保护，经校准参数计算后的电压值若为负值，返回0V
	if (cal_value >= 0)
		return (UINT16)cal_value;
	else
		return 0;
}


static volatile BOOL CranelAdcWorkFlag = FALSE;
BOOL CraneLAdcWork(void)
{
	return CranelAdcWorkFlag;
}

void SetCraneLAdcWork(BOOL flag)
{
	CranelAdcWorkFlag = flag;
}

extern volatile UINT32 g_TS_last_D2Recover;
#define ADC_BAND_GAP_TIME 30 //ms

#define APB_SPARE3_REGISTER     (APB_SPARE_BASE + 0x108)
#define ADC_RESULT             (THSESOR_BASE + 0x80)

static void AdcMutexLock(void)
{
    OSA_STATUS status;

    if(NULL == adc_Sema)
    {
        Adc_mutex_init();
    }
    status = OSASemaphoreAcquire(adc_Sema, OS_SUSPEND);
    ASSERT(status == OS_SUCCESS);
}

static void AdcMutexUnlock(void)
{
    OSA_STATUS status;
    if(NULL == adc_Sema)
    {
        return;
    }
    status = OSASemaphoreRelease(adc_Sema);
    ASSERT(status == OS_SUCCESS);
}

typedef enum {
	eADC_CS_DISABLE = 0,
	eADC_CS_ENABLE,
} adc_cs_t;

//current source
struct adc_cs_opt {
	adc_cs_t ipc;			// support current source
	UINT8 current;		// current set 0x1~2ua,0xf~30ua,step 2ua
} adc_cs_opt;

/** this struct fits in with ICAT EXPORTED FUNCTION(TestCraneLAdc()) adc option when use CATStudio console **/
struct adc_opt {
    UINT8 channel;  // adc channel
    UINT8 mode;     // adc mode
    UINT8 opt2;     // apb spare3 23:16(bit5:4 bias current and reference source, bit4 = 0: internel 1.2V reference)
    UINT8 opt3;     // apb spare3 31:24(bit2:0 adc sample delay clock; bit4:3 clock divider for AUXADC clock)
    UINT8 cnt;      // sample cnt that is used to calculate average value
    struct adc_cs_opt cs; // for current source option
    UINT8 ratio; // for 830l ratio of divider resistance
};

#define GEU_FUSE_BANK0_16_47		   (GEU_BASE + 0x0404)
#define GEU_FUSE_BANK0_48_79		   (GEU_BASE + 0x0408)
#define GEU_FUSE_BANK3_255_224         (GEU_BASE + 0x0420)
#define APB_SPARE13_REGISTER           (APB_SPARE_BASE + 0x130)

INT8 set_cranel_current_source_opt(void *adc)
{

	UINT32 bank0_47_16, bank0_48_79, bank3_255_224, band_gap_trim_value;

	struct adc_opt* opt = (struct adc_opt *)adc;
	struct adc_cs_opt p_cs = opt->cs;

#if 0
	if(p_cs == NULL)
	{
		CPUartLogPrintf("craneL adc current source struct is not config..\r\n");
		return -1;

	}

	if(opt->channel > 3)
	{
		CPUartLogPrintf("craneL adc current source channel %d isn't support[1~3]\r\n", opt->channel);
		return -2;
	}
#endif

	if(p_cs.current % 2 || p_cs.current > 30)
	{
		CPUartLogPrintf("craneL adc current config %d[uA] isn't support & must be even number[2,4,6,8,10..30]\r\n", p_cs.current);
		return -3;
	}

	UINT32 reg2_sel = p_cs.current/2;

	//get ipc trim
	*((volatile UINT32 *)0xd4282868) = 0x9;
	bank0_47_16 = *(volatile UINT32 *)GEU_FUSE_BANK0_16_47;
	bank0_48_79 = *(volatile UINT32 *)GEU_FUSE_BANK0_48_79;
	bank3_255_224 = *(volatile UINT32 *)GEU_FUSE_BANK3_255_224;
	*((volatile UINT32 *)0xd4282868) = 0x0;


	//set trim value
    if ((bank3_255_224 & 0x80000000) == 0x80000000) {

		UINT32 tuning_value = *((volatile UINT32 *)APB_SPARE13_REGISTER) & 0x0000003F;

		if(IsChipCraneLS())
		    band_gap_trim_value = (bank0_48_79 >> 5) & 0x3F;
		else
		    band_gap_trim_value = (bank0_47_16 >> 22) & 0x3F;

		if(tuning_value != band_gap_trim_value)
		{
	        *((volatile UINT32 *)APB_SPARE13_REGISTER) &= ~0x0000003F;
	        *((volatile UINT32 *)APB_SPARE13_REGISTER) |= band_gap_trim_value ;
	        CPUartLogPrintf("band gap register 0x%08x", *((volatile UINT32 *)APB_SPARE13_REGISTER));
		}
    }

	//clear current of channel
	*((volatile UINT32 *)APB_SPARE13_REGISTER)	&= ~(0xf << (4*opt->channel+4));
	if(p_cs.ipc == eADC_CS_DISABLE)
	{
		*((volatile UINT32 *)APB_SPARE13_REGISTER) &= ~(1<<26);
	}
	else
	{
		*((volatile UINT32 *)APB_SPARE13_REGISTER) |=  (1<<26) | (reg2_sel << (4*opt->channel+4)) ;
	}
	CPUartLogPrintf("APB_SPARE13_REGISTER value = 0x%08x, p_cs.current = %d", *((volatile UINT32 *)APB_SPARE13_REGISTER), p_cs.current);
	return 0;

}

static void StartCraneLAdc(void *opt)
{
    /** this func is non-thread-safe in APB_SPARE3_REGISTER, so it isnot recommeded to call
     ** this func in multi-thread. Add protection is necessary in multi-thread, which is done in get_cranel_adc_for_tsc()
     **/

    UINT32 apb_spare3_seting = 0;
    struct adc_opt* adc = (struct adc_opt *)opt;

    CPUartLogPrintf("adc config channel : 0x%02x, mode : 0x%02x, opt2 : 0x%02x, opt3 : 0x%02x, cnt : 0x%02x",
        adc->channel, adc->mode, adc->opt2, adc->opt3, adc->cnt);

    if (adc->opt2 != 0x00) { // modify default value(0x0060 0000)
        *((volatile UINT32 *)APB_SPARE3_REGISTER) = 0x00000000;
    }

    apb_spare3_seting = (adc->opt3 << 24) | (adc->opt2 << 16)
                        | ((0xF & adc->channel) << 11 | (0x1 & adc->mode) << 10) // channel num, conversion mode
                        | (0x1 << 8); // power up
    *((volatile UINT32 *)APB_SPARE3_REGISTER) |= apb_spare3_seting;
    delay_us(1);
    CPUartLogPrintf("apb spare3 0x%08x", *((volatile UINT32 *)APB_SPARE3_REGISTER));

    *((volatile UINT32 *)APB_SPARE3_REGISTER) |= 0x1 << 9; // soc
    *(volatile UINT32 *)APBC_TSEN_CLK_RST |= 0x1; // fix some board wdt reset when call GetCraneLAdc(),
                                                  // APBC_TSEN_CLK_RST is cleared in these board, which cause that entry
                                                  // to adc int callback again and again, and wdt reset in the end.
}

UINT16 obj_reg =0;//Felix @20221026 obj_reg为校准后的adc寄存器值

//ICAT EXPORTED FUNCTION - ADEMO, ADC, GetCraneLAdc
UINT16 GetCraneLAdc(void *opt)
{
    UINT32 flag_value;
    OSA_STATUS os_status = OS_SUCCESS;
    struct adc_opt* adc = (struct adc_opt *)opt;
    UINT8 cnt = adc->cnt;
    UINT16 *result = (UINT16 *)malloc(cnt * sizeof(UINT16));
    UINT16 adc_ave = 0, reference_source[2] = {1200, 1800}; // 1200mV or 1800mV reference source
	UINT32 BG_delay;
	UINT32 ts_cnt;

    if (cnt == 0) {
        CPUartLogPrintf("count of adc sample is zero!!");
        free(result);
        result = NULL;
        return 0;
    }

	SetCraneLAdcWork(TRUE); //no allow to enter D2 again before adc sample complete
	
	ts_cnt = get_current_TStimer_tick();
	if(ts_cnt >= g_TS_last_D2Recover )
	{
		BG_delay= ts_cnt - g_TS_last_D2Recover;
	}
	else
	{
		BG_delay= ts_cnt + 0xFFFFFFFF - g_TS_last_D2Recover;
	}
		
	if(BG_delay < (30*ADC_BAND_GAP_TIME))  //wait for BG stablity before adc sample  //1ms=30ticks
	{
		OSATaskSleep(ADC_BAND_GAP_TIME/5 - BG_delay/(30*5) + 1); 
	}

    if (adc->cs.ipc == eADC_CS_ENABLE)
	    set_cranel_current_source_opt(opt);
    StartCraneLAdc(opt);
    while (cnt--) {
        os_status = OSAFlagWait(ADCDoneFlgRef, 0x01, OSA_FLAG_OR_CLEAR, &flag_value, 200);
        if(os_status != OS_SUCCESS) {
            CPUartLogPrintf("adc timeout!!");
            cnt++;
            continue;
        }

        CPUartLogPrintf("adc result 0x%03x", *(volatile UINT32 *)ADC_RESULT);
        *result = adc_value_calibrate(*(volatile UINT32 *)ADC_RESULT & 0xFFF, reference_source[(adc->opt2 & 0x10) >> 4]);
        result++;
		/* 默认关闭 需要获取adc校准后的寄存器值时请打开*/
		#if 0 
			obj_reg = ((*(volatile UINT32 *)ADC_RESULT & 0xFFF)*(1200+2*craneL_adc_calibration_value_def[0])+craneL_adc_calibration_value_def[1]*2400)/1200;
		#endif

        if (!adc->mode) { // single conversion, restart soc
            *((volatile UINT32 *)APB_SPARE3_REGISTER) &= ~(0x1 << 9);
            *((volatile UINT32 *)APB_SPARE3_REGISTER) |= 0x1 << 9;
        }
    }

	SetCraneLAdcWork(FALSE);  //allow to enter D2

    *((volatile UINT32 *)APB_SPARE3_REGISTER) &= ~(0x1 << 9);
    *((volatile UINT32 *)APB_SPARE3_REGISTER) &= ~(0x1 << 8);


    if (adc->cnt > 2) {
        sort(result - adc->cnt, adc->cnt);
        adc_ave = average(result - adc->cnt + 1, adc->cnt - 2);
    } else {
        adc_ave = average(result - adc->cnt, adc->cnt);
    }

    CPUartLogPrintf("adc ave value %dmV", adc_ave);

    result = result - adc->cnt;
    free(result);
    result = NULL;

    return adc_ave;
}

#if !defined(NOT_SUPPORT_PM803L)
#include "guilin_lite2.h"
static unsigned char GetRatioDivResFrom803L(void)
{
    unsigned char var, index;

    GuilinLite2Read(GUILIN_LITE2_BASE_Reg, 0x1D, &var);
    CPUartLogPrintf("803L read sns reg : 0x%2x", var);
    index = ((var & 0x30) >> 4) & 0x03;

    return index;
}

#define GUILIN_LITE2_EN_VINLDO_SNS_MASK 0x30
static void SetRatioDivResTo803L(unsigned char ratio)
{
    unsigned char var;

    GuilinLite2Read(GUILIN_LITE2_BASE_Reg, 0x1D, &var);

    if (ratio == 0)
        var &= ~GUILIN_LITE2_EN_VINLDO_SNS_MASK;
    else
        var |= ratio;

    GuilinLite2Write(GUILIN_LITE2_BASE_Reg, 0x1D, var);
}

static unsigned char GetRatioDivRes(void)
{
    unsigned char ratio = GetRatioDivResFrom803L();

    if (ratio > 0x03) {
        CPUartLogPrintf("invalid vinldo sns");
        return 0;
    }

    if (ratio == 0x00)
        CPUartLogPrintf("vinldo sns is off");

    CPUartLogPrintf("DivResRatio : 0x%x", ratio);
    return ratio;
}

static void SetRatioDivRes(unsigned char ratio)
{
    //SetCraneLAdcWork(TRUE); // avoid to enter D2 after write vinldo_sns reg, which will cause curret leak
    ratio = (ratio << 4) & GUILIN_LITE2_EN_VINLDO_SNS_MASK;
    SetRatioDivResTo803L(ratio);
}

static void CleanRatioDivRes(void)
{
    SetRatioDivResTo803L(0);
    SetCraneLAdcWork(FALSE);
}

static UINT16 _GetCraneLAdcByMap(struct adc_opt *adc)
{
    UINT8 ratio;
    UINT16 vbat = 0;

    //SetRatioDivRes(adc->ratio);
    //SetRatioDivRes(0x01); // according to PMIC AE coworker's(weijing) recommendation, write 0x01 to vinldo_sns
    //if (adc->ratio) {
        //CPUartLogPrintf("wait pm803l 80ms");
        //OSATaskSleep(16);
    //}
    ratio = GetRatioDivRes(); // it isnot a necessary step due to write fixed value(0x01) to PMIC reg vinldo_sns

    if (ratio == 0x01)
        vbat = GetCraneLAdc((void *)(adc))*1680/440;
    else if (ratio == 0x02)
        vbat = GetCraneLAdc((void *)(adc))*775/155;
    else if (ratio == 0x03)
        vbat = GetCraneLAdc((void *)(adc))*840/220;
    else
        vbat = 0;

    //CleanRatioDivRes();

    return vbat;
}
#endif

static UINT16 _GetCraneLAdc(struct adc_opt *adc)
{
    UINT16 vbat = 0;

    if (IsChipCraneLS()) {
#if !defined(NOT_SUPPORT_PM803L)
        vbat = _GetCraneLAdcByMap(adc); // use pm803l in 1608
#else
    #ifdef QUECTEL_PROJECT_CUST
		vbat = GetCraneLAdc((void *)(adc))*(390+120)/120; // use non-pm803l in 1609 //移远1609项目vbat分压计算
	#else
        vbat = GetCraneLAdc((void *)(adc))*(680+200)/200; // use non-pm803l in 1609
    #endif
#endif
    }
#if !defined(NOT_SUPPORT_PM803L)
    else if(IsChipCraneLR()) // cranelr board contain 803l default
        vbat = _GetCraneLAdcByMap(adc); // use pm803l in 1602
#endif
    else // cranel
#ifdef QUECTEL_PROJECT_CUST
        vbat = GetCraneLAdc((void *)(adc))*(390+120)/120;//移远1606项目vbat分压计算
#else
		vbat = GetCraneLAdc((void *)(adc))*(620+220)/220;
#endif
    return vbat;
}
#ifdef QUECTEL_PROJECT_CUST
UINT32 get_cranel_adc0(void)
{
	UINT32 adc0 = 0;
    struct adc_opt adc = {0x01, 0x00, 0x47, 0x12, 0x0a, 0x00, 0x00, 0x00};
	if(IsChipCraneLR()){
		//600K系列800K系列ADC channel不同
		#if defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__)\
		 || defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
		 || defined (__QUECTEL_PROJECT_EC600KCN_MC__)
		adc.channel = 2;
		#else
		adc.channel = 3;
		#endif
	}
	AdcMutexLock();
	adc0 = GetCraneLAdc((void *)(&adc));
	AdcMutexUnlock();
    return adc0;
}

UINT32 get_cranel_adc1(void)
{
	UINT32 adc1 = 0;
    struct adc_opt adc = {0x02, 0x00, 0x47, 0x12, 0x0a, 0x00, 0x00, 0x00};
	if(IsChipCraneLR()){
		//600K系列800K系列ADC channel不同
		#if defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__)\
		 || defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
		 || defined (__QUECTEL_PROJECT_EC600KCN_MC__)
		adc.channel = 3;
		#else
		adc.channel = 2;
		#endif
	}
	AdcMutexLock();
	adc1 = GetCraneLAdc((void *)(&adc));
	AdcMutexUnlock();
    return adc1;
}
//Felix @20221026客户反馈想要获取adc寄存器的值，以便自己上层做算法处理
UINT16 quec_get_cranel_adc_reg(unsigned char adc_channel)
{
	UINT16 vbat = 0;
	struct adc_opt adc = {0x01+adc_channel, 0x00, 0x47, 0x12, 0x01, 0x00, 0x00, 0x00};
	GetCraneLAdc((void *)(&adc));
	return obj_reg;
}

//Felix @20221117 新增需求：获取温度值接口
int quec_get_temperature_celsius_value(void)
{
	return getTsensorTemperatureCelsiusValue();
}

#endif



UINT16 get_cranel_vbat(void)
{
	UINT16 vbat = 0;
#ifdef QUECTEL_PROJECT_CUST
	/* Felix@20220830 客户反馈VBAT电压存在误差,由于ASR量产的芯片ADC采用了ATE校准,此处将ADC参考电压由原来的1.8v更改为1.2v */
	struct adc_opt adc = {0x03, 0x00, 0x47, 0x12, 0x03, 0x00, 0x00, 0x00};
#else
	struct adc_opt adc = {0x01, 0x00, 0x47, 0x12, 0x01, 0x00, 0x00, 0x00};
#endif
	if(IsChipCraneLR()){
		adc.channel = 1;
	}
    /** 1.620/220(different platforms have different values) is value of two resistance which form bleeding chain;
     **   adc get the voltage of divider resistance, so need to convert this voltage to
     **   vbat by multiply the ratio of divider resistance;
     ** 2.bit4 of adc.opt2 equal to 1 that indicate use 1.8V reference, clean bit4 of adc.opt2 to 0 if use internel 1.2V reference
     ** 3.1602(cranelr)/1608(one chip of cranels series) use pm803l to form bleeding chain, so read pmic reg to set ratio of divider resistance, but usually,
     **   set pmic reg by adc.ratio before read pmic reg when start adc sample, and clean pmic reg after adc sample
     **/
    AdcMutexLock();
    vbat = _GetCraneLAdc(&adc);
    AdcMutexUnlock();

    return vbat;
}

UINT16 get_cranel_ntc(void)
{
     UINT32 vntc = 0;
	struct adc_cs_opt cs = {eADC_CS_ENABLE, 2};
	struct adc_opt adc = {0x02, 0x00, 0x47, 0x12, 0x01, cs};

    /** use the code below to disable current and switch source when one chip(ex: cranels) donnot use current source to sample volt
     ** if (IsChipCraneLS())
     **     cs.ipc = eADC_CS_DISABLE;
     **/

    if (cs.ipc == eADC_CS_ENABLE) {
        if (IsChipCraneLR())
            adc.channel = 0x03;
        
        AdcMutexLock();
        vntc = GetCraneLAdc((void *)(&adc));
        AdcMutexUnlock();
        
        while(vntc < 450 && cs.current < 30)
        {
            cs.current *= (UINT8)(900/vntc);
            if(cs.current > 30)
                cs.current = 30;
        
            AdcMutexLock();
            vntc = GetCraneLAdc((void *)(&adc));
            AdcMutexUnlock();
        }
        
        CPUartLogPrintf("%s : vntc = %d, current = %d", __func__, vntc, cs.current);
        return vntc*1000/cs.current; // return NTC impedance
    }else {
        AdcMutexLock();
        vntc = GetCraneLAdc((void *)(&adc));
        AdcMutexUnlock();

        return vntc;
    }
}

//ICAT EXPORTED FUNCTION - ADEMO, ADC, TestCraneLAdc
void TestCraneLAdc(void *opt)
{
    struct adc_opt* adc = (struct adc_opt *)opt;

    if (adc->ratio && (adc->cs.ipc == eADC_CS_ENABLE)) {
        CPUartLogPrintf("choose one of pm803l(voltage source) and current source, not both!!");
    } else {
        if (adc->ratio) { // only test adc that use pm803l to form bleeding chain
            CPUartLogPrintf("voltage(pm803l) %dmV", _GetCraneLAdc(opt));
        } else {
            CPUartLogPrintf("voltage %dmV", GetCraneLAdc(opt));
        }
    }
}

void TestCraneLAdcAPI(void *opt)
{
    CPUartLogPrintf("vbat %dmV", get_cranel_vbat());
    CPUartLogPrintf("ntc %d", get_cranel_ntc());
}



