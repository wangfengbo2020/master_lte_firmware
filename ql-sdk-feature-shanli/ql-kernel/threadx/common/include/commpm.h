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
/* Title: Comm. Power Manager Header File                               */
/*                                                                      */
/* Filename: commpm.h                                                   */
/*                                                                      */
/* Author:   Raviv Levi                                                 */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     					*/
/*																		*/
/* Remarks: -                                                           */
/*    													                */
/* Created: 19/9/2005                                                   */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/


#ifndef _COMMPM_H_
    #define _COMMPM_H_


    #include "global_types.h"
	#include "powerManagement.h"
    /*----------- Global defines -------------------------------------------------*/
    //#if ((defined PM_DEBUG_MODE_ENABLED))/* && (!defined COMMPM_DEBUG_MODE_ENABLED))*/
    //    #define COMMPM_DEBUG_MODE_ENABLED
    //#endif
    /*----------- Global macro definitions ---------------------------------------*/

	#define COMMPM_MAX_TIME_TABLE 30
    /*----------- Global type definitions ----------------------------------------*/

    // This enumerator describes the various values that may be returned.
    typedef enum
    {
        COMMPM_RC_ERR = -100,
        COMMPM_RC_OK  = 0
    } CommPM_ReturnValueE;

    // This enumerator describes the various core frequencies available through
    // the CommPM package. Note that the frequencies relate to the GB core as the
    // Arbel core frequencies are determines by the 2:1 / 3:2 ratio (according to the fuse settings).
    // This enumerator is basically a wrapper to the CommCCU_SystemPLLFreqE enumerator.
    typedef enum
    {
        COMMPM_GB_CORE_FREQ_52MHZ = 0,
        COMMPM_GB_CORE_FREQ_104MHZ,
        COMMPM_GB_CORE_FREQ_156MHZ,
        COMMPM_GB_CORE_FREQ_208MHZ,
        COMMPM_GB_CORE_FREQ_312MHZ,
        COMMPM_GB_CORE_NUM_OF_FREQS
    }CommPM_GBCoreFreqsE;

// this ENUM is added for the CommPMDDRRequestManage called by RM to handle the request of the DDR
	typedef enum
    {
        COMMPM_RELQ_HIGH_FREQ_DDR = 0,
		COMMPM_REQUEST_HIGH_FREQ_DDR
    }CommPM_DDRRequestE;

    // This enumerator describes the various wakeup sources currently supported by our HW.
    typedef enum
    {
        COMMPM_WAKEUP_SOURCE_SSP = 0,   // Only GSSP2 is used. (even though GSSP1 is connected too)
        COMMPM_WAKEUP_SOURCE_I2C,       // Not used.
        COMMPM_WAKEUP_SOURCE_MSL,
        COMMPM_WAKEUP_SOURCE_USIM,      // Not used.
        COMMPM_WAKEUP_SOURCE_TIMER,
        COMMPM_WAKEUP_SOURCE_SCK,
        COMMPM_WAKEUP_SOURCE_WDT,
        COMMPM_WAKEUP_SOURCE_WB_SLEEP_MODULE,
        COMMPM_WAKEUP_SOURCE_TCU,       // Not used.
        COMMPM_WAKEUP_SOURCE_PMIC,      // Not used.
		COMMPM_WAKEUP_SOURCE_UART,
		COMMPM_WAKEUP_SOURCE_AC_IPC,	// Apps Comm IPC wakeup
		COMMPM_WAKEUP_SOURCE_CGPIO,
        COMMPM_NUM_OF_WAKEUP_SOURCES
    }CommPM_WakeupSourcesE;

    // This enumerator describes the wakeup states of a CommPM wakeup source.
    typedef enum
    {
        COMMPM_WAKEUP_SOURCE_ENABLED = 0,
        COMMPM_WAKEUP_SOURCE_DISABLED
    }CommPM_SourceWakeupStateE;

//this enum represents the available DDR acknoledges
   typedef enum
    {
		COMMPM_DDR_READY_ACK = 0,
        COMMPM_DDR_HF_READY_ACK,
        COMMPM_DDR_HF_RELQ_ACK
    }CommPM_DDRAckE;

//this enum represents the available clients for DDR and PP notify
//Currently, the only COMM application known is CPA (L1 representing also PS)
// future may add more applications.
   typedef enum
    {
		COMMPM_CLIENT_0_NOTUSED = 0,
        COMMPM_CLIENT_CPA_1,COMMPM_CLIENT_CPA_GSM_UMTS_1=COMMPM_CLIENT_CPA_1,
        COMMPM_CLIENT_CPA_GSM_TD_1 = COMMPM_CLIENT_CPA_1,
        COMMPM_CLIENT_AUDIO_2,
		COMMPM_CLIENT_3, COMMPM_CLIENT_CPA_LTE_3=COMMPM_CLIENT_3,
		COMMPM_CLIENT_CPA_SIMB_POWERON,
		COMMPM_CLIENT_PLATFORM_INTERNAL,
		COMMPM_CLIENT_MMI,
		COMMPM_NUMBER_OF_CLIENTS
    }CommPM_ClientsE;

//this enum represents the available PP (product points)
//ICAT EXPORTED ENUM
typedef enum {
	COMMPM_PP_NOTSET,
	COMMPM_PP_1,
	COMMPM_PP_2,
	COMMPM_PP_3,
	COMMPM_PP_4,
	COMMPM_NUMBER_OF_PP = 4
} CommPM_PPE;

#define COMMPM_MAX_PP COMMPM_PP_4
#define COMMPM_D2	COMMPM_PP_NOTSET	// for duty cycle
// This type definition describes the DDR notify callback functions type.
typedef void (*COMMPM_DDRAckNotificationT)(CommPM_DDRAckE ackType);

// This type definition describes the PP change notify callback functions type.
typedef void (*COMMPM_DDRDVFMNotificationT)(CommPM_PPE PPType);

	// Services and applications that control entry to D1 (D1 is entered when both COMM and MSA are in C1)
	// Due to Silicon bug in A0 - the D1 state causes problems for several services:
	// UART, TCU, HSDPA (?)
//ICAT EXPORTED ENUM
	typedef enum
	{
		Service_UART	= 0x01,
		Enable_TCU_clock= 0x02,
		Service_HSPDA	= 0x04,
		Service_ICAT	= 0x08,
		Service_client5 = 0x10,
		Service_client6	= 0x20,
		Service_client7	= 0x40,
		Service_client8	= 0x80

	} CommPM_servicesD1E;

//ICAT EXPORTED ENUM
typedef enum {	
	COMMPM_MODEM_ENABLE = 0,
    COMMPM_MODEM_DISABLE,
    COMMPM_INVALID_STATE

}PM_Modem_StateE;
typedef enum
{
    COMMPM_BIT_DISABLE= 0,
    COMMPM_BIT_ENABLE,

}CommPM_Bit_StatusE;

typedef enum
{
    COMMPM_NMOS_ENGAGE= 0,
    COMMPM_NMOS_DISENGAGE,
}CommPM_Nmos_StatusE;


//rafiagiv 27.02.07
// added control in A0 - PM bits spread in various placed in HRBL, thus controled via commPM
typedef enum
{
	//CPMU drivers controls
	COMMPM_WB_GSM_TCU_CE_SEL = 0,          //TCU_CE_SEL
	COMMPM_WB_GSM_SLP_TIMER_SEL,           //SGW
	COMMPM_GSM_STKY_RST,				   //GWE_STKY_RST
	COMMPM_WB_SLEEP_MODULE_POLARITY_FIX,   //(not documented yet)
	COMMPM_WB_NUM_OF_CONROL_BITS_IN_CPMU,
	//MCCU drivers controls
    COMMPM_WB_SLP_EQ_EN,			       //GWbWakeSel
	COMMPM_WB_WAKE_SEL,					   //GWbslpEqEn
	COMMPM_WB_NUM_OF_CONROL_BITS
}CommPM_WB_GSM_Control_BitsE;

	/* Work Directive - what to activate in power */
	/* By default (May 06) all is disabled, When mature, the default will
	   be all enabled (set in CommPMInit()) */
	//ICAT EXPORTED STRUCT
	   typedef struct
	   {
		UINT32 D2mode;	// 0 - no D2, 1 - D2 alike, 2 - full D2
		UINT32 D2Variation;	// 0 Stay in D0, 1, go to C1, 2 Full D2
		UINT32 LPTsleepTicks;	// how many ticks the LPT should sleep
		// temp solution for L1 Standalone.
		UINT32	LPTdebugBusyWait;	// to enable time to enter commands when
		// waking up (since currently (Sep 06) at C1/D2
		// we can not submit commands)
		UINT32  DDRFunctionalityIsOn;  // 0-regular work without DDR / 1-DDR functionality is open for debug / 2-DDR full functionality
		UINT32	endlessLoopAfterD2nExit;
		UINT32	endlessLoopAfterDDRgrantnTimes;
		UINT32	kickWDTonD2Exit;
		UINT16 ServiceD1control;	// word that indicates service controlling D1, if bit is set, D1 should be prevented
									// (the bit position is set by the enum  CommPM_servicesD1E)
		UINT8	AppsCommSyncActivated;
		BOOL allowC1;	// when set real C1 from HW	 (if D2 set, also C1 ?)
		BOOL notifyMSA;	// if set - we work with L1, and should notify them
						// otherwise we are in 'D2 standalone' - only us
		BOOL LPTidle;	// LPT does nothing
		BOOL LPTdecisionOnly; 	// do only decision no setting to HW, no prepare
							 	// (means no real D2, no C1) (not relevant in LPTidle)
								// if not set - we have full LPT functionality
		BOOL	L1isRegister;	// to synchronize D2 decisions on L1 registration
		BOOL PmDebugTaskEnalbe; //to enable/disable comm pm debug task
	   } CommPM_workModeS;

	   // Timing for DDR request (reg, HF) - (to put under PMDEBUG?)
	   //ICAT EXPORTED STRUCT
	   typedef struct
	   {
		   UINT32 DdrHfRequestTS;	 		// current client request TS (maybe DDR in HF already)
		   UINT32 DdrHfRequestFirstClientTS;	// signifies the first client request (the one we wait for its ack)
		   UINT32 DdrRegRequestTS;
		   UINT32 DdrRegMaxResponseTime;
		   UINT32 DdrHfClientTabResponseTime[COMMPM_MAX_TIME_TABLE];
		   UINT32 DdrRegClientTabResponseTime[COMMPM_MAX_TIME_TABLE];
		   UINT32 DdrHfMaxResponseTime;
	   } CommPM_DDRtimingS;
    /*----------- Extern definition ----------------------------------------------*/

	extern CommPM_workModeS _CPMworkMode;
	//#define PMUM_POCR_VCXOST                                71      // PMUM_POCR[23:16]  VCXOST  0~-0xE5
	//#define PMUM_POCR_VCXOST                                99      // PMUM_POCR[23:16]  VCXOST  0~-0xE5
	//#define PMUM_POCR_VCXOST                                94      // PMUM_POCR[23:16]  VCXOST  0~-0xE5
#ifdef L1_DCXO_ENABLED	
	extern UINT16 RfDcxoIsUsingFlg;
	extern UINT8 check_if_DCS_mode(void);
	#define PMUM_POCR_VCXOST                                (((RfDcxoIsUsingFlg == TRUE) && (check_if_DCS_mode() == TRUE)) ? 141 : 94)
#else
	#define PMUM_POCR_VCXOST                                94      // PMUM_POCR[23:16]  VCXOST  0~-0xE5
#endif
	//Please note - the following define VCTCXO_STAB_TIME is for calculation only. It is not the actual VCTCXO stabilization (OSCC register)
    //#define COMMPM_DEFAULT_VCTCXO_STAB_TIME_IN_SCK_TVR_P	(PMUM_POCR_VCXOST - 15 + 65 + 80)	//0.5 (stabilization time in OSCC) + 1.55 (DC) = 2.05ms
	#define COMMPM_DEFAULT_VCTCXO_STAB_TIME_IN_SCK_TVR_P	(PMUM_POCR_VCXOST - 15 + 40)	//0.5 (stabilization time in OSCC) + 1.55 (DC) = 2.05ms
//	#define COMMPM_DEFAULT_VCTCXO_STAB_TIME_IN_SCK_TVR_P	68		//0.5 (stabilization time in OSCC) + 1.55 (DC) = 2.05ms
	#define COMMPM_DEFAULT_VCTCXO_STAB_TIME_IN_SCK_TVR_PV	19		//0.550(stabilization time in OSCC)
	#define COMMPM_DEFAULT_MAIN_PLL_STAB_TIME_IN_SCK 				0
	#define COMMPM_DEFAULT_HARBELL_IPC_REC_TIME_IN_SCK_NO_SYNC		113   //38 +75 (additonal ~2 msec of apps ack time for ddr req)
	#define COMMPM_DEFAULT_HARBELL_IPC_REC_TIME_IN_SCK_WITH_SYNC 	58  //38 +75 (additonal ~2 msec of apps ack time for ddr req) -55 (1.7)
	#define COMMPM_DEFAULT_PLATFORM_RECOVERY_TIME_IN_SCK_GSM		9
	#define COMMPM_DEFAULT_PLATFORM_RECOVERY_TIME_IN_SCK_WB			6
	#define COMMPM_DEFAULT_APPS_D2_ROUND_TRIP_TIME_IN_SCK			86	//~2.6mSec for APPS D2 round trip(goes to D2 and wake)
	#define COMMPM_DEFAULT_PLATFORM_D2_ENTRY_TIME_IN_SCK			32	//~1mSec for COMM D2 entry sequence (from interrupts disable till sleep)


	typedef struct
	{
		UINT32 DefaultVctcxoStabTimeInSck;
		UINT32 DefaultMainPllStabTimeInSck;
		UINT32 DefaultHarbelIPCrecTimeInSck;
		UINT32 DefaultPlatformRecoveryTimeInSck;
	} CommPM_WBWakeupParamsS;

	/* CPU state - active or idle for duty cycle tool */
	//ICAT EXPORTED ENUM
	typedef enum {
        CommPM_Active,
        CommPM_Idle,
        COMMPM_NUMBER_OF_CPU_STATES,
    } CommPM_CPUStateE;
	
	/* Comm state PP or LPM  for duty cycle */
    typedef enum {
		CommPM_D2,
        CommPM_PP,
    } CommPM_CoreStateE;

	/* Send PP update to DSP */
	typedef enum {
		CommPmSendDSP,
		CommPmDontSendDSP,
	} CommPM_SendDSPE;
#ifdef DutyCycleDspEnable
	/*IPC Commands for MSA Duty Cycles*/
	#define COMMPM_MSA_POWER_MANAGER_CTRL_LENGTH			1
	#define COMMPM_MSA_POWER_MANAGER_CTRL_CMD				0
	#define COMMPM_MSA_POWER_MANAGER_CTRL_OPCODE			0x00F6
	#define COMMPM_MSA_POWER_MANAGER_CTRL_IPC_RET_OPCODE	0x000D
	#define COMMPM_MSA_POWER_MANAGER_CTRL_START_CMD			0x000D
	#define COMMPM_MSA_POWER_MANAGER_CTRL_STOP_CMD			0x000E
	#define COMMPM_MSA_POWER_MANAGER_CTRL_RESET_CMD			0x0010
	#define COMMPM_MSA_POWER_MANAGER_CTRL_DISPLAY_CMD		0x000F
	#define COMMPM_MSA_POWER_MANAGER_CTRL_CHANGE_PP1_CMD	0x0011
	#define COMMPM_MSA_POWER_MANAGER_CTRL_CHANGE_PP2_CMD	0x0012
	#define COMMPM_MSA_POWER_MANAGER_CTRL_CHANGE_PP3_CMD	0x0013
	#define COMMPM_MSA_POWER_MANAGER_CTRL_CHANGE_PP4_CMD	0x0014
	#define COMMPM_MSA_POWER_MANAGER_WRONG_OPCODE			0
	#define COMMPM_MSA_POWER_MANAGER_CANNOT_REGISTER_TO_IPC	0
#endif
	  typedef enum {
		  DutyCycleOff,
		  DutyCycleOn,
      } CommPM_DutyCycleSateE;

	  typedef enum {
		  DutyCycleCore,
		  DutyCycleDSP,
      } DutyCycleWhichCore;

typedef struct {
	UINT32 Time[COMMPM_NUMBER_OF_PP+1][COMMPM_NUMBER_OF_CPU_STATES];
} DutyCycleDataS;


/* Duty Cycle Tool - debug time spent in each pp and cpu state */
typedef struct {
	DutyCycleDataS	DutyCycleData;
	UINT32 LastTime;
	CommPM_DutyCycleSateE state;
} CommPM_DutyCycleS;
/*duty cycle event*/
typedef enum
{
	CP_FREQ_416M = 0,
	CP_FREQ_624 = 1,
	CP_D2 = 2,
} DutyCycleEvent ;

////duty cycle end///////////

extern CommPM_DutyCycleS GCommPM_DutyCycle;
	typedef struct
	{
		UINT32 CommPmD2WakeupTime;
		UINT32 EarlyWakeupTime;
	} CommPM_GSMWakeupParamsS;

    /*----------- Global variable declarations -----------------------------------*/

    /*----------- Global constant definitions ------------------------------------*/

    /*----------- Global function prototypes -------------------------------------*/
    // Init functions.
	void CommPMInit					(void);

    // Package specific APIs.
	void CommPMWaitForHWSignal		(BOOL						 waitForHWSignal);

	void CommPMWakeupSourceStateSet (CommPM_WakeupSourcesE		 wakeupSource,
									 CommPM_SourceWakeupStateE	 sourceWakeupState);
	void CommPMDDRRequestManage(CommPM_DDRRequestE request);
	void AC_IPCInterruptHandler(UINT32 status);
	// API to control entering D1, if TRUE - allow D1, if FALSE - prevent D1
	void CommPMControlEnterD1state(CommPM_servicesD1E service, BOOL b_enable);
	void CommpmWbGsmBitSet (CommPM_WB_GSM_Control_BitsE controlBit ,CommPM_Bit_StatusE enableDisable);
	CommPM_Bit_StatusE CommpmWbGsmBitGet (CommPM_WB_GSM_Control_BitsE controlBit); 
	void CommpmUsimNmosEngageSet (CommPM_Nmos_StatusE enableDisable);   
	CommPM_Nmos_StatusE CommpmUsimNmosEngageGet(void);
	void CommpmDDRAckNotificationCBBind(CommPM_ClientsE client , COMMPM_DDRAckNotificationT cbkForDDRAck);
	void CommpmDDRAckNotify(CommPM_DDRAckE DDRAck);
	void PMsetApplication(void);
	// Debug functions.
    #if defined(COMMPM_DEBUG_MODE_ENABLED)
	void CommPMDebugTaskCreate(void);
    #endif // COMMPM_DEBUG_MODE_ENABLED

    /*----------- Module internal function prototypes -------------------------------------*/
	PM_PowerStatesE CommPMD2EntryExit_TillDDRAck(PM_PowerStatesE state);
    void CommPMCP15D2Recover(void);
	BOOL CommPMD2EnterAsm(UINT32 r0PlaceHolder,UINT32 r1PlaceHolder);
    BOOL CommPMD2ExitHandlerAsmPhase1(void);
	void CommpmUartEnableForDebug(void);		//D2DEBUG
	void SendSignalToUART(char signal);		//D2DEBUG

	void CommPMGetGSMWakeupTime(CommPM_GSMWakeupParamsS *CommPM_GSMWakeupParams);
	void CommPMGetWBWakeupTime (CommPM_WBWakeupParamsS  *CommPM_WBWakeupParams);
    
	void CommPmDutyCycleUpdate(UINT32 timestamp_32khz,	DutyCycleEvent ppEvent, CommPM_CPUStateE cpuState, CommPM_SendDSPE sendDsp);
	
	DutyCycleEvent ChangeCoreFreqToDutyCycleEvent(void);

typedef int (*MMIC1PrepareFunc)(void);
typedef int (*MMIC1RecoverFunc)(void);

typedef int (*MMID2PrepareFunc)(void);
typedef int (*MMID2RecoverFunc)(BOOL ExitFromD2);
typedef int (*MMIStatusFunc)(void);



void mmiD2CallbackRegister(UINT32 prepare_func, UINT32 recover_func);
void mmiC1CallbackRegister(UINT32 prepare_func, UINT32 recover_func);

int MMID2Prepare(void);
int MMID2Recover(BOOL ExitFromD2);
int MMIC1Prepare(void);
int MMIC1Recover(void);
int MMIStatus(void);

UINT32 DCXOLPMRegister(unsigned char *name);
void   DCXOLPMOn(UINT32 client);
void   DCXOLPMOff(UINT32 client);

#endif //_COMMPM_H_

