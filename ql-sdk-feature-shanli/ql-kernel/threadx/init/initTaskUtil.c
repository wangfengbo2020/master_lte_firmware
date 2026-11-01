/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/
/**
*  Filename: initTaskUtil.c
*
* high level inits done in the InitTask
*
**/

#include "string.h"       /*memset*/
#include "global_types.h"
#include "hal_cfg.h"
#include "bsp_hisr.h"
#include "bsp_config.h"
#include "bsp.h"
#include "asserts.h"
#include "diag.h"
#include "timer.h"
#include "EEHandler.h"
#if 0
#include "HSI.h"
#endif
#include "log.h"
#include <FreqChange.h>
#include "acipc.h"
#include "pmic.h"
#include "ningbo.h"
#include "guilin.h"
#include "guilin_lite.h"
#include "guilin_lite2.h"

#if defined(PHS_SW_DEMO_TTC)
/*@Hongji 2008.8.22 PHS debug*/
#include "osa.h"
#include "diag_API.h"
/****/
#endif

//#if defined (_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
#include "arbel.h"
#include "arm946e_s.h"
#include "pm_ext_debug.h"
#else
#include "pmu.h"
#if defined(_HERMON_B0_SILICON_) && !defined(INTEL_2CHIP_PLAT_BVD)
#include "hermon_regs.h"
#include "pmue.h"
#endif
#endif

#if defined (INTEL_FDI)
#include "FDI_EXT.h"
#include "FDI_FILE.h"
#include "FDI_ERR.h"
#include "runvars.h"
#endif

#ifdef  FOTA_GS_FEATURE
#include "asr_fota.h"
#endif

#ifndef OSA_USED
#define OSA_USED
#endif
#include "osa.h"

#include "main.h"
#include "IPCComm.h"

#if defined (INTEL_2CHIP_PLAT_BVD) || defined (_TAVOR_BOERNE_) || defined (SILICON_TTC_CORE_MOHAWK)
#define APP_SIDE_CORE
 #if !defined (NO_AUDIO)
 #define APP_AUDIO_ENABLE
 #endif
#else
 #define COMM_SIDE_CORE
#endif

#if defined (COMM_SIDE_CORE)
#include "lowtasks.h"
#endif

//#if defined (_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
extern void PMInit  (void);
#else
#if defined(HERMON_POWER_MANAGEMENT)
#include "power_manager.h"
extern void pmActivate(void);
#include "os_tick.h"
#endif
#endif

#if defined(_TAVOR_BOERNE_)
#include "pm_brn_ext.h"
#endif
#include "utilities.h"
#if QUEC_SIM_PIN_CTRL_FUNC
extern void sim_gpio_read_flash(void);
#endif

//#include "powerManagement.h"
extern void PMUendInit(void);
extern void PMUendInitForce(void);
extern void DbgPrintf(char* fmt, ...);
extern TIMER_TCR_CONFIGURE_RC timerTCRconfigureForSync(TCR_NUMBER tcr_number, TCR_CONFIGURATION *tcr_configuration);
extern BOOL psNvmCreate(void);
extern UINT8 GetIAptStatus(void);
extern void PP_init(void);
extern void PP_set_voltage(PP_TYPE pp, PP_VOLTAGE_T voltage);
extern FC_RTN_CODE_T PP_Switch(UINT8 ProductPoint);
extern void SysRestartReasonPrint(void);
extern void DDRFrequencySetDefault(void);
extern void PlatformBuckAptConfig(void);
extern void dumpPreExcepInfo(void);
extern void PlatformRfSwitchPowerConfig(void);
extern void wirelessModemSubsysPhase2Init(void);

extern void set_pp_for_test(void);



//#if !defined (_TAVOR_HARBELL_)|| defined(SILICON_PV2)
#if 1
#include "leds.h"
#include "idletask.h"
#endif

/* Extern Functions */
/*EXPORT*/  OSATimerRef TimerDeleteInitTask;
OSATimerRef    DiagThroughPutTimerRef;
extern void DeleteInitPhase2TaskByTimer(UINT32 id) ;
extern PM_TYPE gPMEnableFlag;

#if defined (APP_AUDIO_ENABLE)
extern void ACMInit(void);
#endif
#if 1  //ma xinhua for temp test
extern 	void L1cCommFrameIntHisrHandler(void);
static UINT16 tdSfn = 0;
static UINT32 timeStampFI = 0;
void TCMTestTimerHandle(void)
{
	UINT32 currentTime;
	UINT32 timerPeriod;;
	currentTime = timerElapsedTimeGet()/1000;
	if(currentTime > timeStampFI)
	{
		timerPeriod = currentTime - timeStampFI;
	}
	else
	{
		timerPeriod = timeStampFI - currentTime;

	}
	timeStampFI = currentTime;
#if 1
	if((tdSfn % 10) == 0)
	{
		DIAG_FILTER(PM,CommPM,TCMTestTimerHandle_1,DIAG_INFORMATION)
		diagPrintf("Frame interrupt timer out,sfn:%x,timeinterval:%d",tdSfn,timerPeriod);
	}
#endif

	tdSfn++;
	//L1cCommFrameIntHisrHandler();
	if (tdSfn == 0xFFFF)
	{
		tdSfn = 0;
	}

}
void TCMStartFITimer(void)
{
#if defined(TIMER_32K_MULTIPLIER)
  #define FREQ_MUL_1	 (1000*TIMER_32K_MULTIPLIER)	  // 5000 Usec = 5 mSec
#else
  #define FREQ_MUL_1	 1000	   // 5000 Usec = 5 mSec
#endif
	TIMER_TCR_CONFIGURE_RC	timerStatus;
	TIMER_RETURN_CODE       timerRCStatus; //added for removing warning
	TCR_CONFIGURATION		timer_config;
	UINT32					uSec;

	// deactivate OS_TIMER_ID
	timerRCStatus = timerDeActivate(TCR_3);
	if (timerRCStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}
	memset(&timer_config,0,sizeof(timer_config));

	// configure OS_TIMER_ID
	timer_config.clock_mode  = CLK_32KHZ; // 32.768Khz ==> 1 hw tick clock = 30517.578125 nSec = 30.517 Usec
	timer_config.tcmr_mode	 = C_TCMR_HW_PERIODIC_TCMR_MODE;
	timer_config.tplcr_mode  = C_TPLCR_FREE_RUNNING ;
	timer_config.tplvr_value = 0;
	timer_config.microSecTimeInterval = (OSA_TICK_FREQ_IN_MILLISEC*FREQ_MUL_1);
	timer_config.cookie = TCR_3;
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)TCMTestTimerHandle; //Expiration callback
	timer_config.interrupt_required = TO_INTERRUPT_REQUIRED;  // called from LISR Context

	timerStatus = timerTCRconfigure(TCR_3, &timer_config);
	if (timerStatus != TCR_CONFIGURE_OK)
	{
		ASSERT(FALSE);
	}

	timerRCStatus = timerActivate(TCR_3);
	timeStampFI = timerElapsedTimeGet()/1000;
	if (timerRCStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}
	DIAG_FILTER(PM,CommPM,TCMStartFITimer_1,DIAG_INFORMATION)
	diagPrintf("Frame interrupt timer start");
	return;
}
#endif

UINT32 sync_days=0;


void SyncTimerHandler(UINT8 val)
{

	UINT32 val1, val2;
	sync_days++;
	DbgPrintf("sync_days=%d\r\n",sync_days);
//	SyncTimerInit(0x0);
#if 0
	val1=timerCountRead(TCR_2);
	val2=timerCountRead(TCR_3);
	DbgPrintf("SyncTimerHandler 0x%x,0x%x\r\n",val1,val2);
#endif
}

void SyncTimerInit(UINT32 value)
{

	TIMER_TCR_CONFIGURE_RC	timerStatus;
	TIMER_RETURN_CODE       timerRCStatus; //added for removing warning
	TCR_CONFIGURATION		timer_config;
	UINT32					uSec;

	timerRCStatus = timerDeActivate(TCR_3);
	if (timerRCStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}
	memset(&timer_config,0,sizeof(timer_config));


	timer_config.clock_mode  = CLK_32KHZ; // 32.768Khz ==> 1 hw tick clock = 30517.578125 nSec = 30.517 Usec
	timer_config.tcmr_mode	 = C_TCMR_HW_PERIODIC_TCMR_MODE;
	timer_config.tplcr_mode  = C_TPLCR_ENABLE_PRELOAD_WITH_MATCH_O ;
	timer_config.tplvr_value = value;

	timer_config.microSecTimeInterval = 1000000;//(OSA_TICK_FREQ_IN_MILLISEC*FREQ_MUL_1);
	timer_config.cookie = TCR_3;
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)SyncTimerHandler; //Expiration callback
	timer_config.interrupt_required = TMR_INTERRUPT_NONE;// TO_INTERRUPT_REQUIRED;  // called from LISR Context

	timerStatus = timerTCRconfigureForSync(TCR_3, &timer_config);
	if (timerStatus != TCR_CONFIGURE_OK)
	{
		ASSERT(FALSE);
	}

//	timer_reg_dump();

	timerRCStatus = timerActivate(TCR_3);

	if (timerRCStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}

	return;
}

void timer_monitor(void)
{
	UINT32 val1,val2;
	val1=timerCountRead(TCR_2);
	val2=timerCountRead(TCR_3);
	DbgPrintf("val1=0x%x,val2=0x%x\r\n",val1,val2);

}

/******************************************************************************
* Function: InitTimers
*******************************************************************************
* Description:  This function configures and activates the HW of the OS Timer
*
* Notes : Function is called from Phase2Inits function
*         Initialize only free running Timer
*******************************************************************************/
int TS_TIMER_INIT = 0;
void InitTimers(void)
{
#if 1
  #if defined(TIMER_32K_MULTIPLIER)
    #define FREQ_MUL   (1000*TIMER_32K_MULTIPLIER)      // 5000 Usec = 5 mSec
  #else
    #define FREQ_MUL   1000      // 5000 Usec = 5 mSec
  #endif

    TCR_CONFIGURATION	     timer_config;
    TIMER_TCR_CONFIGURE_RC   timerStatus;
	TIMER_RETURN_CODE time_stat;


	//   all  platforms - default
	memset(&timer_config,0,sizeof(timer_config));
	timer_config.clock_mode  = CLK_32KHZ;                                 // 32.768Khz ==> 1 hw tick clock = 30517.578125 nSec = 30.517 Usec
	timer_config.timerNotificationPtr = NULL;
	timer_config.interrupt_required = 0;
//#if defined (_TAVOR_HARBELL_) || defined(SILICON_PV2)
#if defined(SILICON_PV2)
    // Harbell: has a different API
    //timer_config.tcmr_mode   = (TCMR_MODES)TCMR_EN_FREERUN_MODE;  //  One Shot mode + SW periodic reload
    timer_config.tcmr_mode   = (TCMR_MODES)TCMR_EN_PERIOD_MODE;  //  One Shot mode + SW periodic reload
#elif defined (_TAVOR_BOERNE_)
    // Boerne:
	timer_config.tcmr_mode   = C_TCMR_HW_FREE_RUN_MODE;
#else
    // Legacy Hermon timer API and usage model
	timer_config.tcmr_mode   = C_TCMR_SW_PERIODIC_TCMR_MODE;              //  One Shot mode + SW periodic reload
#endif
	timer_config.tplcr_mode  = C_TPLCR_FREE_RUNNING ;                     // C_TPLCR_ENABLE_PRELOAD_WITH_MATCH_O;
	timer_config.tplvr_value = 0;                                         // after match occurs, pre-load value = 0; match#0 value - unchanged.
	//timer_config.microSecTimeInterval = (OSA_TICK_FREQ_IN_MILLISEC*FREQ_MUL);
	timer_config.microSecTimeInterval = 0xFFFFFFFF;
	//timer_config.microSecTimeInterval = (OSA_TICK_FREQ_IN_MILLISEC*1000000);
	timer_config.cookie = (UINT8)TS_TIMER_ID;
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)TShandler;  //hengshanyang 2018-7-24
	timer_config.interrupt_required = TO_INTERRUPT_REQUIRED;
	//more accurate timer init function
	AccTimerInitilize();

//#if defined(HERMON_POWER_MANAGEMENT) && !defined(_TAVOR_HARBELL_) && !defined(_TAVOR_BOERNE_) && !defined(SILICON_PV2)       // will be replaced by HERMON_POWER_MANAGEMENT only when this is not defined in Tavor builds
#if defined(HERMON_POWER_MANAGEMENT) && !defined(_TAVOR_BOERNE_) && !defined(SILICON_PV2)       // will be replaced by HERMON_POWER_MANAGEMENT only when this is not defined in Tavor builds
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)OSTickHandler;
	timer_config.interrupt_required = TO_INTERRUPT_REQUIRED|TO_LISR_NOTIFICATION;
#endif //TAVOR_HRBEL platform

   	timerStatus = timerTCRconfigure(TS_TIMER_ID, &timer_config);
    ASSERT_NO_DIAG(timerStatus == TCR_CONFIGURE_OK);
	time_stat = timerActivate(TS_TIMER_ID);
	ASSERT_NO_DIAG(time_stat == TIMER_RC_OK);

	TS_TIMER_INIT = 1;

#if defined (ENABLE_LEDS)
//  ledsInit();
#endif

#else

	TIMER_TCR_CONFIGURE_RC	timerStatus;
	TCR_CONFIGURATION		timer_config;
	UINT32					uSec;

	timerStatus = timerDeActivate(TCR_2);
	if (timerStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}
	memset(&timer_config,0,sizeof(timer_config));


	timer_config.clock_mode  = CLK_32KHZ; // 32.768Khz ==> 1 hw tick clock = 30517.578125 nSec = 30.517 Usec
	timer_config.tcmr_mode	 = C_TCMR_HW_PERIODIC_TCMR_MODE;
	timer_config.tplcr_mode  = C_TPLCR_ENABLE_PRELOAD_WITH_MATCH_O ;
	timer_config.tplvr_value = 0x0;

	timer_config.microSecTimeInterval = 1000000;//(OSA_TICK_FREQ_IN_MILLISEC*FREQ_MUL_1);
	timer_config.cookie = TCR_2;
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)SyncTimerHandler; //Expiration callback
	timer_config.interrupt_required = TMR_INTERRUPT_NONE;// TO_INTERRUPT_REQUIRED;  // called from LISR Context

	timerStatus = timerTCRconfigureForSync(TCR_2, &timer_config);
	if (timerStatus != TCR_CONFIGURE_OK)
	{
		ASSERT(FALSE);
	}

//	timer_reg_dump();

	timerStatus = timerActivate(TCR_2);

	if (timerStatus != TIMER_RC_OK)
	{
		ASSERT(FALSE);
	}

	return;



#endif
}

void InitHSITimers(void)
{
  #if defined(TIMER_32K_MULTIPLIER)
    #define FREQ_MUL   (1000*TIMER_32K_MULTIPLIER)      // 5000 Usec = 5 mSec
  #else
    #define FREQ_MUL   1000      // 5000 Usec = 5 mSec
  #endif

    TCR_CONFIGURATION	     timer_config;
    TIMER_TCR_CONFIGURE_RC   timerStatus;
	TIMER_RETURN_CODE time_stat;


	//   all  platforms - default
	memset(&timer_config,0,sizeof(timer_config));
	timer_config.clock_mode  = CLK_FAST;                                 // 32.768Khz ==> 1 hw tick clock = 30517.578125 nSec = 30.517 Usec
	timer_config.timerNotificationPtr = NULL;
	timer_config.interrupt_required = 0;
//#if defined (_TAVOR_HARBELL_)
#if 0
    // Harbell: has a different API
    //timer_config.tcmr_mode   = (TCMR_MODES)TCMR_EN_FREERUN_MODE;  //  One Shot mode + SW periodic reload
    timer_config.tcmr_mode   = (TCMR_MODES)TCMR_EN_PERIOD_MODE;  //  One Shot mode + SW periodic reload
#elif defined (_TAVOR_BOERNE_)
    // Boerne:
	timer_config.tcmr_mode   = C_TCMR_HW_FREE_RUN_MODE;
#else
    // Legacy Hermon timer API and usage model
	timer_config.tcmr_mode   = C_TCMR_SW_PERIODIC_TCMR_MODE;              //  One Shot mode + SW periodic reload
#endif
	timer_config.tplcr_mode  = C_TPLCR_FREE_RUNNING ;                     // C_TPLCR_ENABLE_PRELOAD_WITH_MATCH_O;
	timer_config.tplvr_value = 0;                                         // after match occurs, pre-load value = 0; match#0 value - unchanged.
	timer_config.microSecTimeInterval = (OSA_TICK_FREQ_IN_MILLISEC*FREQ_MUL);
	timer_config.cookie = (UINT8)GB_FIRST_TIMER;
//#if defined(HERMON_POWER_MANAGEMENT) && !defined(_TAVOR_HARBELL_) && !defined(_TAVOR_BOERNE_)        // will be replaced by HERMON_POWER_MANAGEMENT only when this is not defined in Tavor builds
#if defined(HERMON_POWER_MANAGEMENT) && !defined(_TAVOR_BOERNE_)        // will be replaced by HERMON_POWER_MANAGEMENT only when this is not defined in Tavor builds
	timer_config.timerNotificationPtr = (TIMER_CALLBACK_FUNCTION)OSTickHandler;
	timer_config.interrupt_required = TO_INTERRUPT_REQUIRED|TO_LISR_NOTIFICATION;
#endif //TAVOR_HRBEL platform

   	timerStatus = timerTCRconfigure(GB_FIRST_TIMER, &timer_config);
    ASSERT_NO_DIAG(timerStatus == TCR_CONFIGURE_OK);
	time_stat = timerActivate(GB_FIRST_TIMER);
	ASSERT_NO_DIAG(time_stat == TIMER_RC_OK);

#if defined (ENABLE_LEDS)
  //ledsInit();
#endif
}


/************************************************************************
* Function: Delay                                                  *
*************************************************************************
*    Description: Will be OK while uSec < 4G/100~=40M = 40s
*                                                                     *
*                                                                       *
************************************************************************/
void Delay(unsigned long  uSec)
{
    timerDelay(uSec);
}


/************************************************************************/
void DSPResetAck(void)
{ /* Currently nothing */
}


/************************************************************************/
void PeripheralInits(void)
{ /* Currently nothing */
}


/************************************************************************
*
* Set required clocks and go to MODEM_MGR
**/
void CommunicationInits(void)
{
    CPUartLogPrintf("CommunicationInits");

#if !defined(FLAVOR_MINIPLAT)
#if defined (APP_SIDE_CORE)
    extern int WPSGMInit(void); //Called by ps_init.c for FULL-System
    WPSGMInit();
#else

#if 0
#ifdef PHS_SW_DEMO_TTC
#if defined (INTEL_FDI)
	{
    	FILE_INFO  info;
    	if (FDI_findfirst("SystemControl.nvm", &info) != 0)
    	{
    	  psNvmCreate();
    	}
	}
#endif
#endif
#endif

   //MODEM_MGR entry
   //  In case of PLATFORM_ONLY initialize IPC
   //     NOTE: Unification required for HERMON,HARBELL,L1,PLATFORM,IPC,UPGRDE_TAVOR_COMMUNICATION,main.c
//#if defined (FLAVOR_COM) || !defined(FLAVOR_DUALCORE)

#if !defined (PLATFORM_ONLY)
   {
        wirelessModemSubsysPhase2Init();
   }
#else
#if defined (TTC_DSP_INIT)
// Delay to allow time for ICAT handshake - otherwise MSA startup messages are not seen in ICAT
#if defined(_QT_)
	OSATaskSleep(1);
#else
	OSATaskSleep(400);
#endif // QT
    /* DSP start execution */
    PRMDSPCoreStartStop(FALSE);
#endif // TTC
#endif // PLATFORM_ONLY

#endif //APP_SIDE_CORE
#endif //Flavor Miniplat

    CPUartLogPrintf("Communication Init done");

}


 /******************************************************************************
 * Function     : InitTask
 *******************************************************************************
 *
 * Description  : Init Phase2, peripherals, comms, OS and audio applications.
 *
 *
 ******************************************************************************/

#define CPU_USAGE_DUMP_START 0x10

__align(4) unsigned char TestStack2[1024];
OSATaskRef		TestTaskRef2;
OSAFlagRef cpu_usage_dump_flag=NULL;


extern UINT32 diagRxTaskStack[];
#ifndef LTEONLY_THIN
OSATaskRef		TestTaskRef1;




__align(4) unsigned char TestStack1[2048];
#endif

void dumpTimerRegs(void);
void BBU_puthexd(UINT32 val);
#include "diag_API.h"
UINT32 CommunicationInitsDone = 0;

BOOL diagteststart=0;
#if 1
//ICAT EXPORTED FUNCTION - ADEMO,DIAGTHRPUT,Enable
void DIAGTHRPUTEnable(void)
{

	diagteststart=1;
	DIAG_FILTER(ADEMO, DIAGTHRPUT, Enable, DIAG_INFORMATION)
	diagPrintf ( "DIAGTHRPUT Enable");
}
#endif

extern void LedOn(UINT8 num);
extern void LedOff(UINT8 num);
extern void LedInits(void);
extern void LittleDelay(UINT32 num);
BspCustomType customtype;


extern void IPCCommWriteToMSAGpRegister(void);

#define hwAcs_IPC_CONTROL__WRITE(IPCCtrlReg,interrupt) \
(*((volatile UINT32 *)(IPCCtrlReg)) = (interrupt))

UINT32 hwAcs_IPC_REG__READ(UINT32 reg)
{
 // Dummy write-before-read
 *((volatile UINT32 *)reg) = 0;

 return *((volatile UINT32 *)reg);
}

VOID sendTestIPCcommand(VOID)
{
	STATUS status;
	IPC_Command cmd;
	UINT32 GPintStatus;
    UINT16 dataBuf[8] = {0,1,2,3,4,5,6,7};

	uart_printf("sendTestIPCcommand \r\n");

   	cmd.opCode = 0;
   	cmd.cmdLength = 8;
   	cmd.cmdData = dataBuf;


	/* Send the PLP command: */
   	if (IPCCommCommandSend(&cmd, 0) != IPC_RC_available)
   	{
	   uart_printf("sendTestIPCcommand  Failed \r\n");
   	}

	uart_printf("sendTestIPCcommand Done\r\n");
}
extern volatile unsigned long diagtxDone;
extern void print_USB_debug_info(void);
#if defined(MMI_INTERFACE)
unsigned int g_asrlcd_framebuffer[240*320*16/8];
#ifdef CRANE_MCU_DONGLE
#define MMI_POOL_SIZE   1024
#else
#define MMI_POOL_SIZE   460*1024+32*1024+2048+2048+40960+1*1024*1024-250*1024	//add hsy
#endif
unsigned char mmiPool[MMI_POOL_SIZE];
const unsigned int mmiPoolSize = MMI_POOL_SIZE;
#endif


VOID TestTask_1(VOID *argv)
{
	UINT32 cnt=0;
	while(1)
	{
		DIAG_FILTER(SW_PLAT,Log,Log001,DIAG_INFORMATION)
		diagPrintf("TestTask_1 [%d]", cnt);

		uart_printf("TestTask_1 [%06d]\r\n", cnt++);
		OSATaskSleep(200);
	}
}

void SetCpuUsageDumpFlag(void)
{
/*
	if(isCpuUsageDumpEnabled() == TRUE)
	{
		if(cpu_usage_dump_flag!= NULL)
		{
			//OSAFlagSet(cpu_usage_dump_flag, CPU_USAGE_DUMP_START,OSA_FLAG_OR);
		}
	}
*/
	return ;
}

extern 	BOOL isCpuUsageDumpEnabled(void);
UINT32 WDTRstMoniterTaskTime = 0;
extern UINT32 AssertRandomFlag;
extern UINT32 assertCnt;
VOID CpuUsageDumpTask(VOID *argv)
{
	  UINT32 cnt=0;
	  OSA_STATUS status;
	  UINT32 flags;
	  UINT32 val;

	  status = OSAFlagCreate(&cpu_usage_dump_flag);
	  ASSERT(status == OS_SUCCESS);

	  if(isCpuUsageDumpEnabled() == FALSE)
	  	return ;

	  OSATaskSleep(2000);

	  WDTRstMoniterTaskTime= timerCountRead(TS_TIMER_ID);
	  while(1)
	  {

		  /* wating event */
		  status = OSAFlagWait(cpu_usage_dump_flag, CPU_USAGE_DUMP_START, OSA_FLAG_OR_CLEAR, &flags, OSA_SUSPEND);
		  ASSERT(status == OS_SUCCESS);

		  DIAG_FILTER(SW_PLAT,Log,Log002,DIAG_INFORMATION)
		  diagPrintf("CpuUsageDumpTask [%d]", cnt);

		  extern UINT32 AssertRandomFlag;
		  if(AssertRandomFlag==1)
		  {
			  val=timerCountRead(TS_TIMER_ID);
			  DIAG_FILTER(SW_PLAT,Log,Log003,DIAG_INFORMATION)
			  diagPrintf("trigger assert, val:%d ticks,assertCnt:%d\r\n",val,assertCnt);
			  if((val - WDTRstMoniterTaskTime) > (5*60* 32768))
			  {
				uart_printf("reset:%d\r\n",assertCnt);
				ASSERT(0);
			  }
		  }

		  if(isEnable_performance_count() == 0)
		  {
		  	rti_thread_set_enable(1);
		  }
		  else
		  {
			rti_thread_set_enable(0);
			DIAG_FILTER(SW_PLAT,Log,dump_start,DIAG_INFORMATION)
			diagPrintf (">>>>>>>>>>>>>>>>>>>  period IdleDBG [%d] >>>>>>>>>>>>>>>>\r\n", cnt++);

			rti_thread_dump(FALSE);

			DIAG_FILTER(SW_PLAT,Log,dump_end,DIAG_INFORMATION)
			diagTextPrintf (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

			rti_thread_set_enable(1);
		  }

	  }

}
#if 0
VOID TestTask_3(VOID *argv)
{
	  UINT32 cnt=0;
	 // OSATaskSleep(600);

	  while(1)
	  {
		  rti_thread_set_enable(1);
		  OSATaskSleep(1000);

		  DIAG_FILTER(SW_PLAT,Log,Log003,DIAG_INFORMATION)
		  diagPrintf("TestTask_3 [%d]", cnt);

		  rti_thread_set_enable(0);

		  DIAG_FILTER(SW_PLAT,Log,dump_start,DIAG_INFORMATION)
		  diagPrintf (">>>>>>>>>>>>>>>>>>>  period IdleDBG [%d] >>>>>>>>>>>>>>>>\r\n", cnt);

		  uart_printf(">>>>>>>>>>>>>>>>>>>  period IdleDBG [%06d] >>>>>>>>>>>>>>>>\r\n", cnt++);
		  rti_thread_dump();

		  DIAG_FILTER(SW_PLAT,Log,dump_end,DIAG_INFORMATION)
		  diagTextPrintf (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");


		  uart_printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n");
	  }

}
#endif
extern HWDFC_TEST_TYPE	gHWDFCTestFlag;

#ifdef EDEN_1928

void dfc_status_check(void){
	UINT32 count = 5000;
	static UINT32 timeout_count = 0;

	while(BU_REG_READ(CPMU_DDRDFC_CTRL) & DFC_INT_PROGRESS){
		count--;
		if(count == 0){
			timeout_count++;
			fatal_printf("WARNING: CP HW-DFC frequency change is time out, CPMU_DDRDFC_CTRL: 0x%x\r\n", BU_REG_READ(CPMU_DDRDFC_CTRL) );
		}
	}

	if(timeout_count == 10){
		fatal_printf("ERROR: CP HW-DFC is blocked, CPMU_DDRDFC_CTRL: 0x%x\r\n", BU_REG_READ(CPMU_DDRDFC_CTRL));
		ASSERT(0);
	}
	timeout_count = 0;
}

void _set_ddr_hwdfc_test(UINT8 cp_hwdfc_idx)
{
    volatile UINT32 tmp, ts, cpsr;
    UINT64 cycles;
	UINT32 count = 5000;
	static UINT32 timeout_count = 0;

    while(BU_REG_READ(CPMU_DDRDFC_CTRL) & DFC_INT_PROGRESS){
		count--;
		timeout_count++;
		if(count == 0){
			fatal_printf("WARNING: CP HW-DFC frequency change cannot start as it is in progress, CPMU_DDRDFC_CTRL: 0x%x\r\n", BU_REG_READ(CPMU_DDRDFC_CTRL) );
			if(timeout_count == 10){
				fatal_printf("ERROR: CP HW-DFC is blocked, CPMU_DDRDFC_CTRL: 0x%x\r\n", BU_REG_READ(CPMU_DDRDFC_CTRL));
				ASSERT(0);
			}
			return;
		}
    }
	timeout_count = 0;

    tmp = BU_REG_READ(CPMU_DDRDFC_CTRL);

    if(BU_REG_READ(CPMU_DDRDFC_CTRL) & DFC_INT)
    {
        //Clear the DFC interrupt
        tmp = BU_REG_READ(CPMU_DDRDFC_CTRL);
        tmp |= DFC_INT_CLR;
        BU_REG_WRITE(CPMU_DDRDFC_CTRL, tmp);

        tmp = BU_REG_READ(CPMU_DDRDFC_CTRL);
        tmp &= ~DFC_INT_CLR;
        BU_REG_WRITE(CPMU_DDRDFC_CTRL, tmp);
    }

	DIAG_FILTER(PM, HWDFC, DDR_freq_set_test, DIAG_INFORMATION)
    diagPrintf("set ddr freq to level %ld!!", cp_hwdfc_idx);

}
#endif
extern void _set_ddr_hwdfc(UINT8 cp_hwdfc_idx);
extern void _set_cpu_freq(CPU_PLL_T cpu_freq_val);
UINT32 DDRFreq_Id_Plat=0xff;

#if 0
VOID TestTask_3(VOID *argv){
	UINT32 i = 0, j = 0;
	UINT32 m = 0, n = 0;
	UINT32 lpm = 0;
	UINT32 timeout_value;
	UINT32 tickInit = 0, tickDelta = 0;
	UINT32 dfc_status;


	OSATaskSleep(2000);

	fatal_printf("Before freq change stress test~\r\n");

	OSATaskSleep(200);

	timeout_value = 200;

	if(gHWDFCTestFlag == _HWDFC_TEST_CORE){
		HWDFC_disable();
	}else if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE){
		HWDFC_enable();
#if defined(NEZHA3_1826)
		fatal_printf("Disable HW_DFC LPM trigger\r\n");
		BU_REG_WRITE(CPMU_DFC_CP, BU_REG_READ(CPMU_DFC_CP) & (~(0x1<<8)));
		BU_REG_WRITE(CPMU_DFC_DP, BU_REG_READ(CPMU_DFC_DP) & (~(0x1<<8)));

#elif  (!defined(EDEN_1928))
		fatal_printf("Disable HW_DFC LPM trigger\r\n");
		BU_REG_WRITE(PMUA_DFC_CP, 0x0);
#endif

	}else{
		HWDFC_enable();
	}

#if defined(NEZHA3_1826)

	switch(gHWDFCTestFlag){
		case _HWDFC_TEST_ACTIVE_LPM_CORE:
			fatal_printf("start active HW-DFC + LPM HW-DFC + Core freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_ACTIVE_LPM:
			fatal_printf("start active + LPM HW-DFC freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_ACTIVE:
			fatal_printf("start active HW-DFC freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_CORE:
			fatal_printf("start CP core freq change stress test!!\r\n");
			break; /* coverity: Missing break in switch. */
		case _HWDFC_TEST_NEW_API:
			uart_printf("start New API stress test!!\r\n");
			break;
		default:
			fatal_printf("ERROR: frequency change stress test is terminated, test parameters invalid\r\n");
			break;
	}


	while(1){

		if(gHWDFCTestFlag == _HWDFC_TEST_NEW_API)
		{
			OSATaskSleep(200);
			DDRFrequencyChangeRequest(DDRFreq_Id_Plat,DDR_FREQUENCY_LV1);
			OSATaskSleep(200);
			DDRFrequencyChangeRequest(DDRFreq_Id_Plat,DDR_FREQUENCY_LV2);
		}
		//active hw-dfc test
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE){

			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_312);
				set_ddr_freq(DDR_FREQUENCY_400);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_156);
				set_ddr_freq(DDR_FREQUENCY_400);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_156);
				set_ddr_freq(DDR_FREQUENCY_312);
			}


			while( BU_REG_READ(CPMU_DFC_STATUS)&0x1 ){
				m++;
				if(m == 100000){
					fatal_printf("Active HWDFC dead lock!!!\r\n");
					fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
						BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
						BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
					fatal_printf("DFC_CP: 0x%x, DFC_DP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
						BU_REG_READ(CPMU_DFC_CP), BU_REG_READ(CPMU_DFC_DP),BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(CPMU_DFC_STATUS));
					ASSERT(0);
				}
			}
			uart_printf("_HWDFC_TEST_ACTIVE %d!!\r\n",tickDelta++ );

		}


		//pp change and dvc change
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_CORE ){

			for(i = 0; i < 100; i++){
				Nezha3_PP_change(5); //416M
				set_cpu_dvc(CP_DVC_LV1);
				m = 0;
				while( BU_REG_READ(CPMU_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){

						fatal_printf("set cpu freq 416M dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(CPMU_DFC_STATUS));
						ASSERT(0);

					}
				}

				Nezha3_PP_change(8); //624M
				set_cpu_dvc(CP_DVC_LV2);
				m = 0;
				while( BU_REG_READ(CPMU_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){

						fatal_printf("set cpu freq 624M dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(CPMU_DFC_STATUS));
						ASSERT(0);

					}
				}
			}
			uart_printf("_HWDFC_TEST_CORE %d!!\r\n",tickDelta++ );
		}

		OSATaskSleep(1);
		//simulate lpm hw-dfc
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM){


			if(j == 2){
				set_ddr_freq(DDR_FREQUENCY_312);
				j = 0;
			}
			else if(j == 0){
				set_ddr_freq(DDR_FREQUENCY_400);
				j = 1;
			}
			else{
//				set_ddr_freq(DDR_FREQUENCY_528);//only for helan2
				set_ddr_freq(DDR_FREQUENCY_312);
				j = 2;
			}
		#if 1
			if(n >= 2){
				Nezha3_PP_change(8); //624M
				set_cpu_dvc(CP_DVC_LV2);
				n = 0;
			}
			else {
				Nezha3_PP_change(5); //416M
				set_cpu_dvc(CP_DVC_LV1);
				n++;

			}
		#endif

			for(i = 0; i < 100; ){
				OSATaskSleep(1);
				m = 0;
				while( BU_REG_READ(CPMU_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){
						fatal_printf("exit from LPM dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(CPMU_DFC_STATUS));
						ASSERT(0);
					}
				}
				i++;
			}

		}

	}

#elif  defined(EDEN_1928)


	switch(gHWDFCTestFlag){
		case _HWDFC_TEST_ACTIVE_LPM_CORE:
			fatal_printf("start HW-DFC + Core freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_ACTIVE_LPM:
		case _HWDFC_TEST_ACTIVE:
			fatal_printf("start HW-DFC freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_CORE:
			fatal_printf("start CP core freq change stress test!!\r\n");
			break;
		default:
			fatal_printf("ERROR: frequency change stress test is terminated, test parameters invalid\r\n");
			break;
	}


	while(1){
		//active hw-dfc test
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE){

			for(i = 0; i < 100; i++){
				_set_ddr_hwdfc_test(DDR_FREQUENCY_156);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_208);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_156);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_400);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_156);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_528);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_156);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_667);
				dfc_status_check();
			}
			OSATaskSleep(1);
			for(i = 0; i < 100; i++){
				_set_ddr_hwdfc(DDR_FREQUENCY_208);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_400);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_208);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_528);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_208);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_667);
				dfc_status_check();
			}
			OSATaskSleep(1);
			for(i = 0; i < 100; i++){
				_set_ddr_hwdfc(DDR_FREQUENCY_400);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_528);
				dfc_status_check();

				_set_ddr_hwdfc(DDR_FREQUENCY_400);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_667);
				dfc_status_check();
			}
			OSATaskSleep(1);
			for(i = 0; i < 100; i++){
				_set_ddr_hwdfc(DDR_FREQUENCY_528);
				dfc_status_check();
				_set_ddr_hwdfc(DDR_FREQUENCY_667);
				dfc_status_check();
			}

			OSATaskSleep(1);
			if(j == 0){
				_set_ddr_hwdfc(DDR_FREQUENCY_156);
				j = 1;
			}
			else if(j == 1){
				_set_ddr_hwdfc(DDR_FREQUENCY_208);
				j = 2;
			}
			else if(j == 2){
				_set_ddr_hwdfc(DDR_FREQUENCY_400);
				j = 3;
			}
			else if(j == 3){
				_set_ddr_hwdfc(DDR_FREQUENCY_528);
				j = 4;
			}
			else{
				_set_ddr_hwdfc(DDR_FREQUENCY_667);
				j = 4;
			}

			OSATaskSleep(1);
		}

		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_CORE ){
			for(i = 0; i < 100; i++){

				_set_cpu_freq(cpu_PLL1_156MHZ);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_208MHZ);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_312MHZ);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_416MHZ);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_624MHz);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_832MHz);
				dfc_status_check();
				_set_cpu_freq(cpu_PLL1_1248MHz);
				dfc_status_check();

				if(i%10 == 0)OSATaskSleep(1);
			}
			OSATaskSleep(1);
		}
	}
#else

	switch(gHWDFCTestFlag){
		case _HWDFC_TEST_ACTIVE_LPM_CORE:
			fatal_printf("start active HW-DFC + LPM HW-DFC + Core freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_ACTIVE_LPM:
			fatal_printf("start active + LPM HW-DFC freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_ACTIVE:
			fatal_printf("start active HW-DFC freq change stress test!!\r\n");
			break;
		case _HWDFC_TEST_CORE:
			fatal_printf("start CP core freq change stress test!!\r\n");
			break;
		default:
			fatal_printf("ERROR: frequency change stress test is terminated, test parameters invalid\r\n");
			break;
	}


	while(1){
		//active hw-dfc test
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE){

			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_312);
				set_ddr_freq(DDR_FREQUENCY_400);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_156);
				set_ddr_freq(DDR_FREQUENCY_400);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_156);
				set_ddr_freq(DDR_FREQUENCY_312);
			}

#if 0			//For Helan2
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_156);
				set_ddr_freq(DDR_FREQUENCY_528);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_312);
				set_ddr_freq(DDR_FREQUENCY_528);
			}
			for(i = 0; i < 100; i++){
				set_ddr_freq(DDR_FREQUENCY_400);
				set_ddr_freq(DDR_FREQUENCY_528);
			}
#endif
			while( BU_REG_READ(PMUA_DFC_STATUS)&0x1 ){
				m++;
				if(m == 100000){
					fatal_printf("Active HWDFC dead lock!!!\r\n");
					fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
						BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
						BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
					fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
						BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(PMUA_DFC_STATUS));
					ASSERT(0);
				}
			}


		}


		//cpu freq change
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_CORE ){

			for(i = 0; i < 100; i++){
				set_cpu_freq(core_PLL1_416MHz);
				m = 0;
				while( BU_REG_READ(PMUA_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){

						fatal_printf("set cpu freq 416M dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(PMUA_DFC_STATUS));
						ASSERT(0);

					}
				}

				set_cpu_freq(core_PLL1_624MHz);
				m = 0;
				while( BU_REG_READ(PMUA_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){

						fatal_printf("set cpu freq 624M dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(PMUA_DFC_STATUS));
						ASSERT(0);

					}
				}
			}

		}

		OSATaskSleep(1);
		//simulate lpm hw-dfc
		if(gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM_CORE
		|| gHWDFCTestFlag == _HWDFC_TEST_ACTIVE_LPM){


			if(j == 2){
				set_ddr_freq(DDR_FREQUENCY_312);
				j = 0;
			}
			else if(j == 0){
				set_ddr_freq(DDR_FREQUENCY_400);
				j = 1;
			}
			else{
//				set_ddr_freq(DDR_FREQUENCY_528);//only for helan2
				set_ddr_freq(DDR_FREQUENCY_312);
				j = 2;
			}
		#if 1
			if(n >= 2){
				set_cpu_freq(core_PLL1_624MHz);
				n = 0;
			}
			else {
				set_cpu_freq(core_PLL1_416MHz);
				n++;

			}
		#endif

			for(i = 0; i < 100; ){
				OSATaskSleep(1);
				m = 0;
				while( BU_REG_READ(PMUA_DFC_STATUS)&0x1 ){
					m++;
					if(m == 100000){
						fatal_printf("exit from LPM dead lock!!!\r\n");
						fatal_printf("Warning ISR CP_ISR:%08x, AP_ISR:%08x, CC_CP:%08x,CP_IMR:%08x,CC_AP:%08x,CC_STATUS:%08x,FCCR:%08x\r\n",
							BU_REG_READ(PMUA_CP_ISR),BU_REG_READ(PMUA_AP_ISR),BU_REG_READ(PMUA_CC_CP),BU_REG_READ(PMUA_CP_IMR),BU_REG_READ(PMUA_CC_AP),
							BU_REG_READ(PMUA_CP_STATUS),BU_REG_READ(PMU_FCCR_T));
						fatal_printf("DFC_CP: 0x%x, DFC_AP: 0x%x, DFC_STATUS: 0x%x\r\n",
							BU_REG_READ(PMUA_DFC_CP), BU_REG_READ(PMUA_DFC_AP), BU_REG_READ(PMUA_DFC_STATUS));
						ASSERT(0);
					}
				}
				i++;
			}

		}

	}
#endif

}
#endif

#ifndef LTEONLY_THIN
void dumpTimerRegs(void)
{
		volatile UINT32 *TmReg1 = (volatile UINT32 *)0xd4014000;
		volatile UINT32 *TmReg2 = (volatile UINT32 *)0xd4016000;
		static UINT32 tm_val_1[0xac/4], tm_val_2[0xac/4], ii;
		for (ii=0;ii<0xac/4;ii++)
		{
			tm_val_1[ii]=*(TmReg1+ii);
			tm_val_2[ii]=*(TmReg2+ii);
		}
 }
#endif

#ifdef PHS_SW_DEMO_TTC
//ICAT EXPORTED FUNCTION - ADEMO,RESET,PrintfResetStatus
void PrintfResetStatus(void)
{
	extern UINT32 Reset_Status;
	UINT32 Reset_Current=*(volatile UINT32 *)0xd4050028;
	DIAG_FILTER(ADEMO,RESET,PrintfResetStatus1,DIAG_INFORMATION)
	diagPrintf("0xd4050028 boot value is 0x%lx, current value is 0x%lx",Reset_Status, Reset_Current);
}
#endif

volatile unsigned long start_comm = 0;
//ICAT EXPORTED FUNCTION - ADEMO,START_PS,startCommInit
void startCommInit(void)
{
	start_comm = 0xB0B0B0B0;
	DIAG_FILTER(ADEMO,START_PS,startCommInit1,DIAG_INFORMATION)
	diagPrintf("start comm 0x%lx", start_comm);
	//CommunicationInits();
	//CommunicationInitsDone = 1;
}


#ifdef __QUEC_OEM_VER_JMK__
/**********************************
*pony add 2021-06-09
*function:
*return锟斤拷1: v1.1 //2锟斤拷v1.2
**********************************/
unsigned int QUEC_CRANEM_HARD_VERSION=0;
unsigned int quec_get_cranem_hardver(void)
{
    return QUEC_CRANEM_HARD_VERSION;
}
void Quec_CraneM_Hard_Vresion(void)
{
    unsigned char P69_level=0;
    unsigned char P70_level=0;
    GPIOConfiguration gpio_config_data = {
		.pinDir  = GPIO_IN_PIN,
		.pinPull = GPIO_PULLDN_ENABLE,
		.initLv  = 0,  //??????????
		.pinEd 	 = GPIO_NO_EDGE,
		.isr 	 = NULL,
		.wu 	 = NULL,
	};
    GpioInitConfiguration(69, gpio_config_data);//gpio69
    GpioInitConfiguration(70, gpio_config_data);//gpio69
    P69_level=GpioGetLevel(69);
    P70_level=GpioGetLevel(70);
	if(P69_level&&P70_level)//EC600NV1.1
    {
        QUEC_CRANEM_HARD_VERSION = 1;
        RTI_LOG("++++++++++++EC600NV1.1+++++++++++++++++\r\n");
    }
    else if((!P69_level)&&P70_level) //EC600NV1.2
    {
        QUEC_CRANEM_HARD_VERSION = 2;
	    RTI_LOG("++++++++++++EC600NV1.2+++++++++++++++++\r\n");
    }  
}

#endif

extern void ACMInit_MSASSP(void);
extern UINT8 PMIsEnable(void);
void PMIC8211workaroundForFirstLDOoperation(void)
{
	int i;
	/***********************************************************************
      Special for Nezha(1802): Enable power supply for AVDD_CODEC, then enable GSSP
    ************************************************************************/
    //pin name: TDS_DIO9, func 1: GPIO77, used for 8211_LDO_EN, supply power for AVDD_CODEC
	*(volatile UINT32*)0xD401E2DC = 0xA0C1;
	//set GPIO77 as output and high to enable power supply
	*(volatile UINT32*)0xD4015008 = 0x3; //enable GPIO clock
	*(volatile UINT32*)(0xD4019008+0x54) = 0x1<<(77-64); //set GPIO77 as output
	*(volatile UINT32*)(0xD4019008+0x18) = 0x1<<(77-64); //set GPIO77 as high

	 for(i=0;i<100000;i++);
	    /***********************************************************************
      Special for Nezha(1802): Disable power supply for AVDD_CODEC, then disable GSSP
    ************************************************************************/
	*(volatile UINT32*)(0xD4019008+0x54) = 0x1<<(77-64); //set GPIO77 as output
    *(volatile UINT32*)(0xD4019008+0x24) = 0x1<<(77-64); //set GPIO77 as low
}
extern void diagStartPsCfg(void);

extern void Nezha2_PP_change(UINT8 ProductPoint);
extern void PM812_APT_enable(void);
extern void PM812_BUCK5_Enable(void);

#ifdef NEZHA3_1826
extern void Nezha3_PP_change(UINT8 ProductPoint);
#endif

VOID InitTask(VOID *argv)
{
    OS_STATUS   status;

    CPUartLogPrintf("InitTask started");

	/* Phase 2 (OS based) initializations*/

	Phase2Inits();
#ifdef ADD_ACC_TIMER_TEST_CASE
   test_AccTimer();
#endif

#ifndef MIN_SYS	
if(!IsMiniSystem())
{
#if QUEC_SIM_PIN_CTRL_FUNC
	sim_gpio_read_flash(); //need to set sim pin value , before sim init
#endif
}
#endif

    if (PLATFORM_IS_ASIC)
    {
        PlatformRfSwitchPowerConfig();
        if (GetIAptStatus())
        {
            PlatformBuckAptConfig();
        }
    }


#if defined(DM_SUPPORT_FRAMEWORK) || defined(PROJ_MINIPHONE)
#ifndef MIN_SYS 
    extern int __attribute__((used)) ui_init_phase2(void);
    if(!IsMiniSystem())
    {
        ui_init_phase2();
    }
#endif
#endif


    PMInit();

	//NVM_Init_Reg();	//19.04.28

    init_lowEventHandleTask();

#if !defined(FLAVOR_MINIPLAT)
#ifndef LTEONLY_THIN
	if (!isLPMEnabled()) //No test tasks if LPM is enabled.
    {
    	/* set this flag to stop PS automatically startup */
    	status = OSATaskCreate(&TestTaskRef1, TestStack1, 2048, 200, "TTask 1", TestTask_1, NULL);
    	ASSERT(status == OS_SUCCESS);

    }

#endif
	status = OSATaskCreate(&TestTaskRef2, TestStack2, 1024, 70, "CpuUsage", CpuUsageDumpTask, NULL);
    ASSERT(status == OS_SUCCESS);


	dumpPreExcepInfo();

    if (CHIP_IS_CRANEG_AX)
    {
        if(ifPsramSupports500M())
            PsramPhyFreqChangeTo500();
        else if(ifPsramUHS())
            PsramPhyFreqChangeTo1066();
    }

    PMIC_Phase3Init(); //Fix putting clk_xo cfg here.

	start_comm = 0xB0B0B0B0;
	while(start_comm != 0xB0B0B0B0)
	{
		OSATaskSleep(200);
		DIAG_FILTER(ADEMO,InitTask,CommunicationInits_WAIT,DIAG_INFORMATION)
		diagPrintf("Waitting for Start Comm ......");
		CPUartLogPrintf("Waitting for Start Comm ......");
	}

	/* Communication initializations - perform specific inits for communications*/
	 CommunicationInits();

	 //lfs_cache_task_resume();
#if 1
      extern void DCXOLPMEnable(void);
      DCXOLPMEnable();
#endif

	 CommunicationInitsDone = 1;


	 //move nvm phase3 from phase2init to here to reduce handshake waitting time

#ifdef MACRO_FOR_LWG
	extern void CellulaPowerInitNotifyToDMAForLTE(void);
	CellulaPowerInitNotifyToDMAForLTE();
#endif

#ifndef PHS_SW_DEMO_TTC
	/* Application initializations*/
	//AppsInits();
#if defined (APP_AUDIO_ENABLE)
    PMUendInitForce(); //Uses platform.nvm config, so called before ACM
   	ACMInit();
#endif
#endif

	PMUendInit();  // should be done after ACM INIT done - initiates first frequency cahnge !
#endif //FLAVOR_MINIPLAT

#if defined (PHS_SW_TTC_CPONLY) && defined (SILICON_PV2)
	{
		extern void ReadMiccoAllConfig(void);
		extern void ConfigMiccoRegs(void);
		extern void EnablePhonePcm(void);
		ConfigMiccoRegs();
		ReadMiccoAllConfig();

		ConfigMiccoRegs();
		ReadMiccoAllConfig();
	}
#endif

     initState=BSP_INIT_TASK_FINISH;

#ifdef PHS_SW_TAVORP_YARDEN_CP
	{
		extern void ReadMiccoAllConfig(void);
		extern void ConfigMiccoRegs(void);
		extern void EnablePhonePcm(void);
		ConfigMiccoRegs();
		ReadMiccoAllConfig();
		ConfigMiccoRegs();
		ReadMiccoAllConfig();
	}
#endif

#ifdef PLAT_USE_ALIOS
    extern void aos_app_entry(void) __attribute__((weak));
    aos_app_entry();
#endif

#ifdef FOTA_GS_FEATURE
    fota_init();
#endif

#ifdef  ENABLE_UART_DBGSHELL
	void dbgshell_init(void);
	dbgshell_init();
#endif

#ifdef ALIOTA_FEATURE
	extern void aliota_init(void);
	aliota_init();
#endif

    SysRestartReasonPrint();

#ifdef FOTA_RS_FEATURE
	extern void rs_sdk_start(void);
	rs_sdk_start();
#endif

     set_pp_for_test();

     #if !defined(NOT_SUPPORT_PM813)
     if(isSysRestartByRdProduction()==1)
     {
         uart_printf("in prod mode, disable charger!!\n");
         if (PMIC_IS_PM813()||PMIC_IS_PM813S()) {
            pm813_charger_switch(0);
         }
         
     }
     #endif
{
	 extern void usim_fast_boot_task_del(void);
	 usim_fast_boot_task_del();
}
     OSATimerCreate(&TimerDeleteInitTask);
     OSATimerCreate(&DiagThroughPutTimerRef);
     OSATimerStart(TimerDeleteInitTask, 400, 0, DeleteInitPhase2TaskByTimer, 0);

} /* InitTask */

extern void ActivateDiagThroughPutHisr(UINT32);

UINT32 DiagThroughStartTick;

void StartDiagThroughPutTimer(void)
{
	extern UINT32 get_current_TStimer_tick(void);
	DiagThroughStartTick=get_current_TStimer_tick();
	OSATimerStart(DiagThroughPutTimerRef, 200, 200, ActivateDiagThroughPutHisr, 0);
}

/******************************************************************************
 * Function     : GetTCRTimerCnt
 *******************************************************************************
 *
 * Description  : To be called to get time stamp. 32KHz timer i.e. updated each ~31us
 *
 *
 ******************************************************************************/
#pragma arm section code="GETTCRTIMERCOUNET"
UINT32 GetTCRTimerCnt(void)
{
	return(timerCountRead( TS_TIMER_ID ));
}
#pragma arm section code

extern UINT32 get_cpu_freq(void);
extern UINT32 get_performance_count(void);
extern UINT32 get_overflow_flag_status(void);
extern UINT32 timerCountRead(TCR_NUMBER tcr_number);

UINT64 T32kHzBase = 0;
UINT32 T32kCountLast = 0;
int T32kCountInitialized = 0;

void initTimerCount13MHz(void)
{
	T32kCountLast = timerCountRead(TS_TIMER_ID);
	enable_performance_count();//reset the performance count
	uart_printf("initTimerCount13MHz, T32kHzBase:%x\r\n", T32kCountLast);
	T32kHzBase = T32kCountLast;
	T32kCountInitialized = 1;
}
/**
 *    32kHz      --> 13MHz: tick32k * (13M/32k) = tick32k * 406.25
 * cpu_freq/64 --> 13MHz: tickFreq * (13M/(Freq/64))
*/
#ifdef QUECTEL_PROJECT_CUST
//tomas.qin 20240622 STASR1606-3382 1/2，修复因为在擦除flash期间频繁调用xip上的timerCountReadU64，导致flash被挂起大于1700次，擦除时间大于1秒的问题
#pragma arm section code="TIMERCOUNTREADU64"
#endif
UINT64 timerCountReadU64(void)
{
	UINT32 overflow,p;
	UINT64 performance_count,tmp0_13M, tmp1_13M, sum;
	UINT64 cpu_freq = (UINT64)get_cr5_cpu_freq();
	UINT64 t32k_count;
#if 0
	fatal_printf("cpu_freq == %lu, ts_now:0x%lx\r\n", (UINT32)cpu_freq, timerCountRead(TS_TIMER_ID));
#endif
	if(cpu_freq == 0){
		cpu_freq = 1;
	}
	t32k_count = T32kHzBase;
	tmp0_13M = t32k_count * 397 - t32k_count/4;

	overflow = get_overflow_flag_status();
	p = get_performance_count();
	performance_count = p;
#if 0
	fatal_printf("overflow:%lx, performance_count:%lx, T32kHzBase:%lx\r\n", overflow, p, (UINT32)t32k_count);
#endif

	if(overflow & 0x80000000)
		performance_count += 0xffffffff;

	tmp1_13M = (performance_count * 13 * 64) / cpu_freq;

	sum = tmp0_13M + tmp1_13M;

#if 0
		UINT32 high, low, baseHigh, baseLow, hi, lo;

	high = (tmp0_13M>>32)&0xffffffff;
	low = tmp0_13M&0xffffffff;

	baseHigh = (tmp1_13M>>32)&0xffffffff;
	baseLow = tmp1_13M&0xffffffff;

	hi = (sum>>32)&0xffffffff;
	lo = sum&0xffffffff;

	fatal_printf("tmp0_13M:%lx,%lx, tmp1_13M:%lx,%lx, sum:%lx, %lx\r\n", high, low, baseHigh, baseLow, hi, lo);
#endif

	return sum;
}
#ifdef QUECTEL_PROJECT_CUST
//tomas.qin 20240622 STASR1606-3382 2/2，修复因为在擦除flash期间频繁调用xip上的timerCountReadU64，导致flash被挂起大于1700次，擦除时间大于1秒的问题
#pragma arm section code
#endif

//ICAT EXPORTED FUNCTION - ADEMO, TCRu64, TimerCountReadU64
void ICATTimerCountReadU64(void)
{
	unsigned long high, low, baseHigh, baseLow;
	UINT64 tmp = timerCountReadU64();
	UINT32 time_milsec = 0;

	high = (tmp>>32)&0xffffffff;
	low = tmp&0xffffffff;

	baseHigh = (T32kHzBase>>32)&0xffffffff;
	baseLow = T32kHzBase&0xffffffff;

	time_milsec = tmp/13000;//convert to millisecond
	DIAG_FILTER(ADEMO,TCRu64,TimerCountReadU64,DIAG_INFORMATION)
    diagPrintf("T32kHzBase:%lx,%lx, tsU64:%lx,%lx, milSEC:%u", baseHigh, baseLow, high, low, time_milsec);

	log_printf("tsU64:%llu, milSEC:%u", tmp, time_milsec);

	fatal_printf("[TEST] T32kHzBase:%lx,%lx, tsU64:%lx,%lx, milSEC:%u\r\n\r\n",
				baseHigh, baseLow, high, low, time_milsec);

}

