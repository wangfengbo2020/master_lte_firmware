/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************//*                                                                      */
/* Title: Power Resource Manager Header File                            */
/*                                                                      */
/* Filename: prm.h                                                      */
/*                                                                      */
/* Author:   Marcelo Brafman                                            */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Boerne, PM Module  		    	*/
/*												                        */
/* Remarks: -                                                           */
/*    										                        	*/
/* Created: 21/12/2006                                                  */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/


#if !defined PRM_H
#define PRM_H

#include "powerManagement.h"		// for PM states
//MBTODO - Add this define in Harbell
#if defined (PRM_BRN_C)|| defined(PRM_HRBL_C)
#define PRM_EXTERN
#else
#define PRM_EXTERN extern
#endif


#include "global_types.h"

#define PRM_EXT_MAX_NUM_WU_EVENTS 32

/*----------- Global type definitions ----------------------------------------*/

// This enumerator describes the various values that may be returned.
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_RC_OK = 0,
	PRM_RC_FAIL, //MB _ Added General Fail
    PRM_RC_RESET_NOT_SUPPORTED,
    PRM_RC_ERR_CLOCK = -100,
    PRM_RC_ERR_FREQ,
    PRM_RC_ERR_NULL_POINTER,
    PRM_RC_WAKEUP_NOT_SUPPORTED,
	PRM_RC_SERVICE_NOT_SUPPORTED,
    PRM_RC_ERR_CPMU				//MB  - Arbel Specific on reset on CPMU
}PRM_ReturnCodeE;
///////////////////////////////////////////////////////////////////////////////////////////////////////
//ATTENTION!!!! THIS TABLE MUST BE UPDATED TOGETHER WITH lOCAL TABLEs IN PRM_XXX.H !!!!!!
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Enum of supported services.

#ifdef PHS_SW_DEMO_TTC_PM
//ICAT EXPORTED ENUM
typedef enum
{
	PRM_SRVC_DMA,
	PRM_SRVC_DVFM,
	PRM_SRVC_DSSP0_GB,
	PRM_SRVC_DSSP1_GB,
	PRM_SRVC_DSSP2_GB,	
	PRM_SRVC_I2C,
	PRM_SRVC_MSL,
	PRM_SRVC_RTC,
	PRM_SRVC_SSP1,
	PRM_SRVC_SSP2,
	PRM_SRVC_SSP3,	
	PRM_SRVC_TIMER0_13M,
	PRM_SRVC_TIMER1_13M,
	PRM_SRVC_TIMER2_13M_GB,
	PRM_SRVC_TIMER3_13M_GB,
	PRM_SRVC_VCTCXO,
	PRM_SRVC_UART1,
	PRM_SRVC_USIM,
	PRM_SRVC_WB_CIPHER_GB,     //DTC
	PRM_SRVC_USIM2,
		/*should be deleted for wujing */
	PRM_SRVC_CPA_DDR_HPerf,         // Seagull - DDR Request from Harbell (calls PRM_SRVC_MC_DDR_HPerf if needed)
	PRM_SRVC_AIRQ,                 	  // Seagull
	PRM_SRVC_COMM_IPC,                // Seagull
	PRM_SRVC_RESOURCE_IPC,            // Seagull
	PRM_SRVC_AXI_CFG,                 // Seagull
	PRM_SRVC_ETB,                     // Seagull
	PRM_SRVC_DTC,                     // Seagull
	PRM_SRVC_TCU_CTRL,                 // Seagull
	PRM_SRVC_ABP_BUS,                 // Seagull
    PRM_SRVC_AXI_BUS,                 // Seagull 
	PRM_LAST_SERVICE=PRM_SRVC_AXI_BUS, //Always update this field.
	PRM_NUM_OF_SRVCS,
	PRM_SRVC_NOT_AVAILABLE, 
	PRM_SRVC_MC_DDR_HPerf = PRM_SRVC_NOT_AVAILABLE
	
}PRM_ServiceE;

#else
//ICAT EXPORTED ENUM
typedef enum
{
	PRM_SRVC_DSSP3,					// Harbell
    PRM_SRVC_GSSP2, 				// Harbell
    PRM_SRVC_I2C, 					// Harbell, BRN
    PRM_SRVC_MSL, 					// Harbell, BRN	(MSL0 IN BRN)
    PRM_SRVC_USIM, 					// Harbell
    PRM_SRVC_TIMER0_13M, 			// Harbell
    PRM_SRVC_TIMER1_13M, 			// Harbell
    PRM_SRVC_DMA, 					// Harbell, BRN
    PRM_SRVC_TCU, 					// Harbell
    PRM_SRVC_SCK, 					// Harbell
    PRM_SRVC_WB_SLEEP_MODUL,		// Harbell ,
    PRM_SRVC_VCTCXO, 				// Harbell, BRN  (Enable disable is controled by HW)
    PRM_SRVC_GSSP1_GB, 				// Harbell
    PRM_SRVC_WB_CIPHER_GB, 			// Harbell
    PRM_SRVC_DSSP2_GB, 				// Harbell
    PRM_SRVC_DSSP1_GB, 				// Harbell
    PRM_SRVC_DSSP0_GB, 				// Harbell
    PRM_SRVC_TTPCOM_GB, 			// Harbell
    PRM_SRVC_TIMER2_13M_GB, 		// Harbell
    PRM_SRVC_TIMER3_13M_GB, 		// Harbell
    PRM_SRVC_UART1, 				// Harbell, BRN
    PRM_SRVC_UART2, 				// BRN
    PRM_SRVC_UART3, 				// BRN
	PRM_SRVC_DVFM,                  // Harbell, BRN
    PRM_SRVC_USB20_CLIENT, 			// BRN
	PRM_SRVC_UDC,					// BRN
	PRM_SRVC_USB_20_CLIENT_OTG0_PV,	// BRN ----------> NOT EXISTS in TAVOR_P
	PRM_SRVC_USB_20_HOST_PV,		// BRN ----------> NOT EXISTS in TAVOR_P
	PRM_SRVC_USB_20_HOST_HS_PV,     // BRN ----------> NOT EXISTS in TAVOR_P
	PRM_SRVC_MVED,                  // BRN ----------> NOT EXISTS in TAVOR_P
    PRM_SRVC_MC_DDR_HPerf, 			//Harbell, BRN - multi client handling and also DDR request from Harbell.
	PRM_SRVC_CPA_DDR_HPerf,          //Harbell - DDR Request from Harbell (calls PRM_SRVC_MC_DDR_HPerf if needed)
  	PRM_SRVC_DDR_Regular,			//BRN-represent DDR request from Harbell
	PRM_SRVC_LCD_Main	,			//BRN
	PRM_SRVC_SSP1		,			//BRN -Must find a common interface for BRN/ARBEL SSPs for is separated
	PRM_SRVC_SSP2		,			//BRN -Must find a common interface for BRN/ARBEL SSPs for is separated
	PRM_SRVC_SSP3		,			//BRN -Must find a common interface for BRN/ARBEL SSPs for is separated
	PRM_SRVC_SSP4		,			//BRN -Must find a common interface for BRN/ARBEL SSPs for is separated

	///////////////////////////////////////////////////////////////////////////////////
	//The following resources are always on as defined in system documents - 21/12/2006//
  	//////////////////////////////////////////////////////////////////////////////////

	PRM_SRVC_NAND_FLASH_CTRL,		  // BRN  _Always ON RTOS.
	PRM_SRVC_DYN_MEMC,				  // BRN _ Always ON RTOS.
	PRM_SRVC_STATIC_MEMC,			  // BRN _ Always ON RTOS.
	PRM_SRVC_ISRAM_MEMC,			  // BRN _ Always ON RTOS.
	PRM_SRVC_GPIO,					  // BRN _ Always ON RTOS.

	///////////////////////////////////////////////////////////////////////////////////////////////
	//The below resources are always off in Tavor App as defined in system documents - 21/12/2006//
	//Part of them are not supported in Tavor App , part of them are no supported in RTOS-       //
	//Tavor but may be used in WINCE. Use with Care!!!!!!!					    				 //
  	//////////////////////////////////////////////////////////////////////////////////////////////
	PRM_SRVC_USB_HOST,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_CMR_IF,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_GRAPH_CTRL,			  // BRN	  Always OFF RTOS.
	PRM_SRVC_BOOT_ROM,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_KPD_CTRL,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_MMC0,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_MMC1,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_MMC3,					  // BRN	  Always OFF RTOS - MMC0 on AXI bus.
	PRM_SRVC_MMC4,					  // BRN	  Always OFF RTOS - MMC1 on AXI bus.
	PRM_SRVC_MMC5,					  // BRN	  Always OFF RTOS - MMC2 on AXI bus.
	PRM_SRVC_CNSMR_IR,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_USIM0,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_USIM1,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_AC97,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_PWM0,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_PWM1,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_1WIRE,					  // BRN	  Always OFF RTOS.
	PRM_SRVC_MiniIM,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_MiniLCD,				  // BRN	  Always OFF RTOS.
	PRM_SRVC_ECIPHER,                  // HARBELL   for PV only - defined because chip identification done in run time
	PRM_SRVC_USIM2,                  // HARBELL   for PV only - defined because chip identification done in run time
	PRM_SRVC_SDIO,                 	// HARBELL   for PV only - defined because chip identification done in run time


   	PRM_LAST_SERVICE=PRM_SRVC_SDIO,	//Always update this field.
  	PRM_NUM_OF_SRVCS,
	PRM_SRVC_NOT_AVAILABLE,

}PRM_ServiceE;
#endif

///////////////////////////////////////////////////////////////////////
//USB, UARTS, and multiple wakeup resources must de rechecked
//in order to understyand if single r multiple drivers handle the event.
////////////////////////////////////////////////////////////////////////
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_WU_SRVC_TIMER,				// Harbell, BRN(relevant for RTOS)
    PRM_WU_SRVC_SSP, 				// Harbell 
    PRM_WU_SRVC_SCK, 				// Harbell
    PRM_WU_SRVC_WB_SLEEP_MODULE, 	// Harbell
    PRM_WU_SRVC_TD_SLEEP_MODULE = PRM_WU_SRVC_WB_SLEEP_MODULE,
	PRM_WU_SRVC_LTE_SLEEP_MODULE, 	// Harbell
    PRM_WU_SRVC_TD_LTE_SLEEP_MODULE,
    PRM_WU_SRVC_TCU, 				// Harbell
	PRM_WU_SRVC_UART,				// Harbell, (BRN via GPIO (relevant for RTOS))	   
	PRM_WU_SRVC_AC_IPC,				// Harbell, BRN	(relevant for RTOS) 
	PRM_WU_SRVC_RTC,				// BRN
	PRM_WU_SRVC_ROTARY,				// BRN
	PRM_WU_SRVC_USB20_CLIENT,		// BRN - Do we need to USB events or not?
	PRM_WU_SRVC_USB_OTGP2,			// BRN - Tx,P2,P3(3 diferent wakeups)
	PRM_WU_SRVC_USB_OTGP3,			// BRN - Tx,P2,P3(3 diferent wakeups)
	PRM_WU_SRVC_KEYPAD,				// BRN
	PRM_WU_SRVC_USIM,				// BRN	
	PRM_WU_SRVC_USB_OTGTX,			// BRN - Tx,P2,P3(3 diferent wakeups)
	PRM_WU_SRVC_GPIO,				// BRN (relevant for RTOS) 
   	PRM_WU_SRVC_COMM_WDT,		   	// BRN		
	PRM_WU_SRVC_AC97,				// BRN ored with BSSP wakeup
	PRM_WU_SRVC_CI2C,				// BRN
	PRM_WU_SRVC_MMC1,				// BRN
	PRM_WU_SRVC_SDIO1,				// BRN
	PRM_WU_SRVC_MMC2,				// BRN
	PRM_WU_SRVC_SDIO2,				// BRN
	PRM_WU_SRVC_NAND,				// BRN
	PRM_WU_SRVC_PMIC,				// BRN (relevant for RTOS)
	PRM_WU_BTUART,					// BRN 
	PRM_WU_STUART,					// BRN 
	PRM_WU_SRVC_ICP,				// BRN  - In A0 is ored with UARTs wakeup
	PRM_WU_SRVC_KEYPAD_ROTARY,	   	//BRN
	PRM_WU_SRVC_KEYPAD_DIRECT_KEYS,	//BRN
	PRM_WU_SRVC_EXTERNAL_EVENT0,	// BRN 	- Special case - Driver not defined
	PRM_WU_SRVC_EXTERNAL_EVENT1,	// BRN 	- Special case - Driver not defined
	PRM_WU_SRVC_BSSP1	,			 // BRN
	PRM_WU_SRVC_BSSP2	,			 // BRN
	PRM_WU_SRVC_BSSP3	,			 // BRN
	PRM_WU_SRVC_BSSP4	,			 // BRN

	PRM_NUM_OF_WU_SRVCS,
	PRM_ORED_INT_MSL0,               //For BRM B0
	PRM_WU_INVALID_RSRC 
} PRM_WU_ServiceE;



//MBTODO - The resources that are required by WINCE should be added in here. Based on the 
// previous table of all available resources will be added on a per sevice request. 
//The driver should support it automaically.

//Resources that registre in Resource Manager for keeping their registers.
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_NONRETAINED_SRVC_INTC = 0,	   		// Harbell, BRN	
    PRM_NONRETAINED_SRVC_TIMER,         		// Harbell, BRN  
    PRM_NONRETAINED_SRVC_SSP,           		// Harbell, BRN   
    PRM_NONRETAINED_SRVC_DMA,		   		// Harbell, BRN
    PRM_NONRETAINED_SRVC_I2C,           		// Harbell, BRN  
    PRM_NONRETAINED_SRVC_WDT,           		// Harbell, BRN(?)  
    PRM_NONRETAINED_SRVC_IPC,		   		// Harbell
    PRM_NONRETAINED_SRVC_USIM,          		// Harbell  
    PRM_NONRETAINED_SRVC_PMIC,          		// Harbell  
    PRM_NONRETAINED_SRVC_MSL,           		// Harbell, BRN  
    PRM_NONRETAINED_SRVC_SCK,           		// Harbell  
    PRM_NONRETAINED_SRVC_WB_SLEEP_MODULE, 	// Harbell 
    PRM_NONRETAINED_SRVC_LTE_SLEEP_MODULE, 	// Harbell 
    PRM_NONRETAINED_SRVC_TD_LTE_SLEEP_MODULE, 	// Harbell 
    PRM_NONRETAINED_SRVC_TCU,		   		// Harbell
 	PRM_NONRETAINED_SRVC_UART,		   		// Harbell, BRN
 	PRM_NONRETAINED_SRVC_HSI,
 	PRM_NONRETAINED_SRVC_GPIO,				// BRN
	PRM_NONRETAINED_SRVC_USB20,				// BRN
	PRM_NONRETAINED_SRVC_UDC,				// BRN
	PRM_NONRETAINED_SRVC_LCD,				// BRN
	PRM_NONRETAINED_SRVC_DTC,				// Seagull
	PRM_NONRETAINED_SRVC_PMNC,				// Seagull

    PRM_NUM_OF_NONRETAINED_SRVCS,
    PRM_INVALID_NONRETAINED 


}PRM_NRS_ServiceE;

// This enumerator describes the available services' clock frequencies.
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_FREQ_13MHZ = 0,
    PRM_FREQ_26MHZ,
    PRM_FREQ_52MHZ,
    PRM_FREQ_78MHZ,
	PRM_FREQ_89_1MHZ,
    PRM_FREQ_104MHZ,
 	PRM_FREQ_124_8MHZ   ,
	PRM_FREQ_156MHZ		,
	PRM_FREQ_208MHZ		,
	PRM_FREQ_260MHZ		,
	PRM_FREQ_312MHZ		,
    PRM_NUM_OF_FREQS,
	PRM_INVALID_FREQ
}PRM_ServiceFreqE;

// This enumerator describes the requests made by services.
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_RSRC_FREE=0,
    PRM_RSRC_ALLOC
    
}PRM_AllocFreeE;

// SC -single client resource, each alloc enables resource, 
//     each free disables it.
// MC - multi client resource, count alloc/free requests
// 	on first alloc - enables resource
//	   on last free, disables the resource
//ICAT EXPORTED ENUM
typedef enum
{
    PRM_RSRC_SC_FREE=1,//resource is free, single client handling
    PRM_RSRC_SC_BUSY, // resource is busy, single client handling
    PRM_RSRC_MC_FREE, // resource is free, multi client handling
    PRM_RSRC_MC_BUSY, // resource is busy, multi client handling
    PRM_RSRC_NOT_DEFINED // resource is not defined 
                         // in this plat/sub-system
} PRM_resourceStatusE;



//Callback functions typedef

typedef void (*PRM_CallbackFuncWakeupT)( PM_PowerStatesE sleepstate, PM_PowerStatesE WUState, BOOL b_DDR_ready, BOOL b_RegsRetainedState);
typedef void (*PRM_CallbackFuncPrepareT)( PM_PowerStatesE statetoprepare);
typedef void (*PRM_CallbackFuncRecoverT)( PM_PowerStatesE stateexited, BOOL b_DDR_ready, BOOL b_RegsRetainedState);
typedef void (*PRM_CallbackFuncBeforeIntT)(void);

/*----------- Global function prototypes -------------------------------------*/



// Package specific APIs.
PRM_EXTERN void                 PRMManage			(PRM_ServiceE		resource,
											 		 PRM_AllocFreeE		pmallocFree);

PRM_EXTERN PRM_ReturnCodeE      PRMServiceFreqSet(PRM_ServiceE   resource,
                                           PRM_ServiceFreqE newServiceFreq);

PRM_EXTERN PRM_ServiceFreqE     PRMServiceFreqGet(PRM_ServiceE   resource);
                           

PRM_EXTERN PRM_ReturnCodeE      PRMSWReset  (PRM_ServiceE resource);


PRM_EXTERN PRM_resourceStatusE  PRMGetResourceStatus(PRM_ServiceE resource);


PRM_EXTERN PRM_ReturnCodeE PRMRegisterWakeupControl (PRM_WU_ServiceE resource, 
									 PRM_CallbackFuncWakeupT CBwakeupfunction, 
									 PM_PowerStatesE FromDxState, 
									 PM_PowerStatesE ToDxState);


PRM_EXTERN PRM_ReturnCodeE PRMRegisterForNonRetainState(PRM_NRS_ServiceE resource, 
									   	PRM_CallbackFuncPrepareT CBprepare, 
									   	PRM_CallbackFuncRecoverT CBrecover);


PRM_EXTERN PRM_ReturnCodeE PRMUnRegisterForNonRetainState (PRM_NRS_ServiceE resource);

//The below functions are used in Harbell before interrupt disable in LPT.
PRM_EXTERN void PRMRegisterBeforeIntDisable (PRM_ServiceE resource, 
					                    PRM_CallbackFuncBeforeIntT    cbkBeforeIntDis);        

PRM_EXTERN void PRMDoBeforeIntDis(void);
// API for exception handling - to set resource clock but ignore it for D2 decisions/deepSleep
PRM_EXTERN void PRMTurnOnAndIgnoreLpmSrvc(PRM_ServiceE Srvc, UINT32 bExceptionState);


#undef PRM_EXTERN

#endif  /* PRM_H */
