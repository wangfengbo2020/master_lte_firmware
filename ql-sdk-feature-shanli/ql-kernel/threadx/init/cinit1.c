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

/*********************************************************************************
* DESCRIPTION:
* Title:    Core initialization module  1 and 2 also (cinit1, cinit2)
*           Responsible for initialization of MPU,Caches,TCMs
*
* NOTE_1:
*  The TAVOR-HARBELL has differences with XSCALE
*   XSCALE:
*     Code running from FLASH
*     FLASH and RAM may be INT and EXT. On startup the only INTs are available.
*     The EXTs are initialized with Cinit1, and are used in Cinit2
*   TAVOR:
*     Code is placed in EXT DDR and may run from it.
*     The "INT" code RAM (I-TCM) is not ready and must be initialized with code.
*     The "INT" data RAM (D-TCM) also must be initialized.
*     The "INT" (but not "EXT") are initialized with Cinit1
*
* NOTE_2:
*   Cinit1 is running on SYS and HISR stacks initialized by init.s on the ZI BSS
*   Cinit2 initialize NU stacks on static arrays
*
* NOTE_3:
*   This code initializes ZI static data. DO NOT USE any data-ZI here!
*********************************************************************************/

/** include files **/
#include "bsp_config.h"
#include "global_types.h"
#include <string.h>
#include "arm946e_smpu.h"
#include "arm946e_sCP15.h"

#include "arbel.h"
#include "arm946e_s.h"
#include "utils.h"
#include "bsp.h"
#include "loadTable.h"
#include "ptable.h"
#include "csw_mem.h"
#include "dtc.h"
#ifdef PHS_SW_DEMO_TTC
#include "sCP15_l2cache.h"
#endif
#include "FreqChange.h"
#include <osa.h>
#include "sys_version.h"
#include "EE_silentReset.h"
#include "utilities.h"
#include "asr_property.h"
#include "main.h"
#include "quec_production_cfg.h"
#include "UART.h"
#include "quec_cust_feature.h"
#include "platform.h"
extern UINT32  Load$$DDR_ITCM$$Base		;/* Load Address of DDR_ITCM region			*/
extern UINT32 Image$$DDR_ITCM$$Base		;/* Exec Address of DDR_ITCM region			*/
extern UINT32 Image$$DDR_ITCM$$Length		;/* Length of DDR_ITCM region				*/
extern UINT32  Load$$DDR_DTCM$$Base		;/* Load Address of DDR_DTCM region			*/
extern UINT32 Image$$DDR_DTCM$$Base		;/* Exec Address of DDR_DTCM region			*/
extern UINT32 Image$$DDR_DTCM$$Length		;/* Length of DDR_DTCM region  				*/
extern UINT32 Image$$DDR_DTCM$$ZI$$Base	;
extern UINT32 Image$$DDR_DTCM$$ZI$$Limit	;
extern UINT32 Image$$DDR_DTCM_ENDMARKER$$Base;
extern UINT32  Load$$DDR_RW_DATA$$Base	;  /* Load Address of DDR_RW_DATA region	*/
extern UINT32 Image$$DDR_RW_DATA$$Base	;  /* Exec Address of DDR_RW_DATA region	*/
extern UINT32 Image$$DDR_RW_DATA$$Length	;  /* Length of DDR_RW_DATA region			*/
extern UINT32 Image$$DDR_RW_DATA$$ZI$$Base;
extern UINT32 Image$$DDR_RW_DATA$$ZI$$Limit;
extern UINT32 Image$$DDR_HEAP_ENDMARK$$Base;
extern UINT32 Image$$DDR_HEAP_GUARD$$Base;
#if 0
extern UINT32 Image$$DDR_IMS_HEAP_ENDMARK$$Base;
extern UINT32 Image$$DDR_IMS_HEAP_GUARD$$Base;
#endif
extern UINT32  Load$$HSDPA$$Base	;
extern UINT32 Image$$HSDPA$$Base	;
extern UINT32 Image$$HSDPA$$Length	;

#ifdef RUN_XIP_MODE
extern UINT32 Image$$PS_CODE_IN_PSRAM$$Base;
extern UINT32 Image$$PS_CODE_IN_PSRAM$$Length;
extern UINT32 Load$$PS_CODE_IN_PSRAM$$Base;
#endif

#ifdef PROJ_ASR_APP_001
#ifndef RUN_XIP_MODE
extern UINT32  Load$$MMI_CODE$$Base;
extern UINT32 Image$$MMI_CODE$$Base;
extern UINT32 Image$$MMI_CODE$$Length;
#endif
extern UINT32  Load$$MMI_DATA$$Base;
extern UINT32 Image$$MMI_DATA$$Base;
extern UINT32 Image$$MMI_DATA$$Length;
extern UINT32 Image$$MMI_DATA$$ZI$$Base;
extern UINT32 Image$$MMI_DATA$$ZI$$Limit;
#endif

#ifdef MACRO_FOR_LWG
	extern UINT32 Image$$DTC_DATA$$ZI$$Base;
	extern UINT32 Image$$DTC_DATA$$ZI$$Limit;
#endif

extern UINT32 Image$$PS_NONCACHE_DATA$$ZI$$Base;
extern UINT32 Image$$PS_NONCACHE_DATA$$ZI$$Limit;
extern UINT32 Load$$PS_NONCACHE_DATA$$Base	;  /* Load Address of PS_NONCACHE_DATA region	*/
extern UINT32 Image$$PS_NONCACHE_DATA$$Base	;  /* Exec Address of PS_NONCACHE_DATA region	*/
extern UINT32 Image$$PS_NONCACHE_DATA$$Length	;  /* Length of PS_NONCACHE_DATA region			*/

extern UINT32 Image$$DDR_NONCACHE_REGION_ACIPC_OTHER_UL$$ZI$$Base;
extern UINT32 Image$$DDR_NONCACHE_REGION_ACIPC_OTHER_UL$$ZI$$Limit;

extern UINT32 Image$$DDR_NONCACHE_REGION_PTABLE$$Base;
extern UINT32 Image$$DDR_NONCACHE_REGION_PTABLE_ENDMARK$$Base;
extern UINT32 Image$$DDR_NONCACHE_REGION_PROP$$Base;
extern UINT32 Image$$DDR_NONCACHE_REGION_PROP_ENDMARK$$Base;

extern UINT32  Load$$INIT_DATA$$Base	;
extern UINT32 Image$$INIT_DATA$$Base	;
extern UINT32 Image$$INIT_DATA$$Length;
extern const char pin_data_magic_key[];
#ifdef LWIP_IPNETBUF_SUPPORT
extern UINT32 Image$$DDR_NONCACHE_USB$$ZI$$Base;
extern UINT32 Image$$DDR_NONCACHE_USB$$ZI$$Limit;

extern UINT32 Load$$DDR_NONCACHE_USB$$Base;
extern UINT32 Image$$DDR_NONCACHE_USB$$Base;
extern UINT32 Image$$DDR_NONCACHE_USB$$Length;
#endif
extern UINT32  Load$$D2_VECT$$Base	;
extern UINT32 Image$$D2_VECT$$Base	;
extern UINT32 Image$$D2_VECT$$Length;

extern void seagull_uart_init(void);
extern void EnableL2Cache_310(void);
extern void SetspecialPShandle(void);
extern void set_cpu_init(void);
extern void HWDFC_init(void);

extern void Cinit2(void);
extern void SetPMNC(void);
extern void Set_Seagull_MFPR(void);
extern void uart_reset(void);
extern void ustica_I2CInit(void);
extern void _set_cpu_freq(CPU_PLL_T cpu_freq_val);
extern void PlatformGetMemDebugFlag(BOOL *enable);
extern BOOL whether_RW_region_compressed(void);
#if defined(MIPS_TEST_RAM)
extern void mipsRamStart(void);
#endif

//extern dtcF8DescriptorInfo dtcDescriptorsTable_g_2_wb[];

static UINT32 GetBaseLoadAddrITCM(void);
static UINT32 GetBaseBackupAddrITCM(void);
static UINT32 GetBaseExecAddrITCM(void);
static UINT32 GetBaseLoadAddrDTCM(void);
static UINT32 GetBaseExecAddrDTCM(void);
static UINT32 GetImageLengthITCM (void);
static UINT32 GetImageLengthDTCM (void);
static UINT32 GetExecAddrPTABLE_START(void);
static UINT32 GetExecAddrPTABLE_END(void);
static UINT32 GetExecAddrPROP_START(void);
static UINT32 GetExecAddrPROP_END(void);



static void SetDataZeroInitialized(void);
static void CopyDataRWtoImage(void);  /* Copies all RW DATA from LOAD region into exec/Image region*/
static void CopyHSDPARWtoImage(void);
/* remove INIT_DATA region
static void CopyInitDataRWtoImage(void);
*/

static UINT32 intRamFreeStart;
static UINT32 intRamFreeEnd;
static UINT32 dtcmFreeStart;
static UINT32 dtcmFreeEnd;
#if 0
static UINT32 intIMSRamFreeStart;
static UINT32 intIMSRamFreeEnd;
#endif
#define NeZhaSQUStartAddress (0xd1100000)
#define HeLanSQUStartAddress (0xd1000000)
#define WuJingSQUStartAddress (0xd1100000)
#define KunLunSQUStartAddress (0xd1000000)
//extern dtcF8DescriptorInfo *dtcDescriptorsTable_g_2;
extern UINT32 (*lteChainBaseAddressCh0)[8];
extern UINT32 (*lteChainBaseAddressCh1)[8];
//extern UINT32 lteChainBaseAddressCh0_wujing[255][8];
//extern UINT32 lteChainBaseAddressCh1_wujing[255][8];
//extern UINT32 lteChainBaseAddressCh0_kunlun[255][8];
//extern UINT32 lteChainBaseAddressCh1_kunkun[255][8];
extern UINT32 lteChainBaseAddressCh0_nezha[255][8];
extern UINT32 lteChainBaseAddressCh1_nezha[255][8];
extern UINT32 lteChainBaseAddressCh0_helan[255][8];
extern UINT32 lteChainBaseAddressCh1_helan[255][8];
#ifdef EDEN_1928
extern UINT32 lteChainBaseAddressCh0_eden[255][8];
extern UINT32 lteChainBaseAddressCh1_eden[255][8];
#endif
extern volatile UINT32 BsramBaseAddr;

//static UINT32 extRamFreeStart;
//static UINT32 extRamFreeEnd;
//static BOOL   bspExtMemUsed = FALSE;     // external DDR is initialized "under internal name"

// Global variables.
// Must be set only outside of the  {{{ BEGIN "Don't use GLOBALs" area END }}}
UINT32 DTCM_SZ;
UINT32 ITCM_SZ;

/* Local variables*/
UINT32 initState=BSP_INIT_PROCESS_START;

BOOL IsPhase2Passed(void)
{
	if(initState>=BSP_INIT_PHASE2_PASSED)
		return TRUE;
	else
		return FALSE;
}

BOOL IsCinit1Passed(void)
{
	if(initState>=BSP_INIT_CINIT1_PASSED)
		return TRUE;
	else
		return FALSE;
}

#if 0 //LOADTABLE_REFACTOR@xiaokeweng_20190423 build pass
/*******************************************************************************
* forceLinkIntoImage() - dummy procedure used to force-link procedure or data into the image
*                        Should be never achieved in a fact
**/
void forceLinkIntoImage(void)
{
    if( loadTable.imageBegin    ==0x55)  return;
}
#endif

extern void   ReliableDataPrePhase1 ( void );
extern 	UINT32 needToDump;
/*******************************************************************************
* initProtectedArea - initialize the data in protected area(s) in CODE or RO-DATA
*                     Called before the MPU configuration
*                     Basically used for Factory-Default copy from APPS to COMM
**/
static void cinit1ProtectedArea(void)
{
#if defined(RELIABLE_DATA)
	ReliableDataPrePhase1();
#endif
}

//pinmux_b
#include "board_config.h"
#include "bsp.h"


BOOL IS_TDNewChip(void)
{
	return TRUE;
}

BOOL TDChipIS_Y2(void)
{
	return TRUE;
}

BOOL TDChipIS_A0(void)
{
	return TRUE;
}

BOOL TDChipIS_A1(void)
{
	return TRUE;
}



void MFPR_Config(unsigned long *mfpr_offset, unsigned long *mfpr_data)
{
    int i;

	for(i = 0; ;i++)
	{
	   if(mfpr_offset[i] == 0x00)  break;
	   	
       if(mfpr_offset[i]!=0xff)
       {
            *(volatile unsigned long *)(xlli_MFPR_PHYSICAL_BASE_C + mfpr_offset[i]) = mfpr_data[i];
       }
	}
}

#define PULL_UP_C       0xC000  // Enable pull up resistor                            
#define PULL_DN_C       0xA000  // Enable pull down resistor                      
#define DRV_SLOW_C      0x0800  // Use slow drive strength                        
#define DRV_MED_C       0x1000  // Use medium drive strength                          	   
#define DRV_FAST_C      0x1800  // Use fast drive strength                                
#define AF0_C           0X0000  // Alternate function 0                                   
#define AF1_C           0X0001  // Alternate function 1                                   
#define AF2_C           0X0002  // Alternate function 2                                   
#define AF3_C           0X0003  // Alternate function 3                                   
#define AF4_C           0X0004  // Alternate function 4                                   
#define AF5_C           0X0005  // Alternate function 5                                   
#define AF6_C           0X0006  // Alternate function 6                               		 
#define AF7_C           0X0007  // Alternate function 7                                   
#define RESERVED_C      0x00C0  // RESERVED_C bits that must be set  

void EnableMFPRGSSPFunction(void)
{
			*(volatile unsigned long *)(0xD401E000 + 0x140) = (0x9000 | DRV_MED_C | RESERVED_C | AF1_C);
			*(volatile unsigned long *)(0xD401E000 + 0x144) = (0x9000 | DRV_MED_C | RESERVED_C | AF1_C);
			*(volatile unsigned long *)(0xD401E000 + 0x148) = (0x9000 | DRV_MED_C | RESERVED_C | AF1_C);
			*(volatile unsigned long *)(0xD401E000 + 0x14C) = (0x9000 | DRV_MED_C | RESERVED_C | AF1_C);		
}

void DisableMFPRGSSPFunction(void)
{
	if(AC_IS_2CHIP)
	{
		*(volatile unsigned long *)(0xD401E000 + 0x140) = (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C);
		*(volatile unsigned long *)(0xD401E000 + 0x144) = (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C);
		*(volatile unsigned long *)(0xD401E000 + 0x148) = (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C);
		*(volatile unsigned long *)(0xD401E000 + 0x14C) = (PULL_DN_C | DRV_MED_C | RESERVED_C | AF0_C);		 
			
		*(volatile unsigned long *)0xd4019060 = 0x0F << 25;
	}
}

#ifdef LTEONLY_THIN
//Sharon.li@220322 将1606平台MMC1相关pin脚(GPIO51/52/53/54/31/27)电压域切换到1.8V;平台默认3.3V
void Quec_Thin_Platform_Switch_MMC_Pin_Voltage_Domain(void) 
{

	*(volatile unsigned long *)(0xD4015050) = 0XBABA;
	*(volatile unsigned long *)(0xD4015054) = 0XEB10;
	*(volatile unsigned long *)(0xD401E81C) = 0X85;//AIB_MMC1_IO_REG

}
#endif

void Platform_Pinmux_Config(void)
{
     unsigned char board_detail;
	 unsigned long *mfpr_offset = NULL;
	 unsigned long *mfpr_data = NULL;


#ifndef QUECTEL_PROJECT_CUST
    if (CHIP_IS_HELAN4||CHIP_IS_ULC2)
        return;
#ifndef NEZHA3_1826
    if (!CHIP_IS_NEZHA2)
        return; //only set pinmux for nezha2 in this function.
#endif
    board_detail =  bspGetBoardType();
    switch(board_detail)
    {
    #if 0
        case CUSTOM_APSE:
    #endif
        case CUSTOM_FF_P1:
            mfpr_offset = (unsigned long *)MFPR_offset_emei;
            mfpr_data	= (unsigned long *)MFPR_data_emei;
        break;
        case CUSTOM_1920:
    #ifdef SS_FEATURE
            return;
    #endif	
            mfpr_offset = (unsigned long *)MFPR_offset_1920;
            mfpr_data	= (unsigned long *)MFPR_data_1920;
        break;
        case CUSTOM_EVB3:
        case CUSTOM_NOKIA:
        case ASR_EVB:
        case CUSTOM_SIM2:
    #ifndef NEZHA3_1826
        if (CHIP_IS_NEZHA)
        {
            mfpr_offset = (unsigned long *)MFPR_offset;
            mfpr_data   = (unsigned long *)MFPR_data;
        }
        else if (CHIP_IS_NEZHA2)
    #endif
        {
            mfpr_offset = (unsigned long *)MFPR_offset_nezha2;
            mfpr_data   = (unsigned long *)MFPR_data_nezha2;
        }
        break;

        default:
        //mfpr_offset = (unsigned long *)MFPR_offset;
        //mfpr_data   = (unsigned long *)MFPR_data;
        break;
    }

    if ((mfpr_offset == NULL)||(mfpr_data == NULL))
        return;
    /*mischecked by coverity*/
    /*coverity[uninit_use_in_call]*/
    MFPR_Config((unsigned long *)mfpr_offset,(unsigned long *)mfpr_data);
#else
#if 0
    mfpr_offset = (unsigned long *)quec_MFPR_offset;
    mfpr_data   = (unsigned long *)quec_MFPR_data;

    if ((mfpr_offset == NULL)||(mfpr_data == NULL))
        return;

    MFPR_Config((unsigned long *)mfpr_offset,(unsigned long *)mfpr_data);
#endif
#endif
}


/*******************************************************************************
* Function: Cinit1
********************************************************************************
* Description:
* 	Reset all Peripherals
* 	Init Internal Memory region
* 	InitMux
* 	Init MEMC
* 	Init MMU
* 	External Region Init
* 	Call Cinit2, which may reside in external memory
*
* Return value: None
*
* Notes:
*
*  called from init.s
*
*  APIs with _DS _TCS mean they are duplicated twice, to run at init from DDR
*  and to run from TCM on D2 exit.
*  Cinit1 is the function handle the init (run from DDR), so it calls _DS APIs.
*******************************************************************************/
/* remove INIT_DATA region
static unsigned long InitDataFlag = 0;
 */
extern UMTS_Chip_Version	Umts_Chip_Version;

UINT8 isNezhaY0Above(void) //Nezha Y0 and later version, note that Y0 is renamed Z3 according to operation team's rule.
{ //From Nezha Y0, the EVB2.0 is applied, on which the PMIC is replaced from Ustica to PM8609+8211.
#if 1 //qianying
    return TRUE;
#else
#ifdef EDEN_1928
	return TRUE;
#else
    if (!CHIP_IS_NEZHA)
        return TRUE;
    else
    {
        UINT32 temp = (*(volatile UINT32*)0xD4282C00)>>16; //read CPU ID register to get RevID
        return (temp!=0xF0)?TRUE:FALSE;
    }
#endif
#endif
}


void WA_40LP_PLL1_stablize(void)
{
    UINT32 temp = *(volatile UINT32*)0xD4090100; //PLL1 SW control register

    temp &= ~(0x3<<12);
    temp |= 0x3<<12;
    *(volatile UINT32*)0xD4090100 = temp;
}

#define PMU_AES_CLK_RES_CTRL    0xD4282868
#define BLOCK0_RESERVED_1       0xD4201420

typedef enum
{
	F_TSMC_40LP = 0x0,
	F_GF_40LP = 0x1,
	F_UMC_40LP = 0x2,
	
	F_Reserved = 0xf,
}foundryList;

foundryList GetSiliconFoundry(void)
{
    UINT32 i, val;

    /* Read out fuse value, need enable GEU clock, if already disable,
    * need enable it firstly. */
    if (!(BU_REG_READ(PMU_AES_CLK_RES_CTRL)&0x8))
    {
        BU_REG_WRITE(PMU_AES_CLK_RES_CTRL, 0x9);
        for (i=0;i<0x10;i++);
    }
    val = BU_REG_READ(BLOCK0_RESERVED_1);
    return (foundryList)((val>>13)&0x7); //Bank0[239:237]
}

void Configure_RTC_WTC(void)
{    
#if 0 //qianying
        if(CHIP_IS_ULC2)
		{
        }
		else if(CHIP_IS_HELAN4)
		{
		}	
		else if(CHIP_IS_NEZHA3)
		{ //CR5_PCLK=312/416
			BU_REG_WRITE(0xD4282CA4, 0x11111115); //CR5 L1 cache RTC/WTC
			BU_REG_WRITE(0xD4282CB8, 0x00000011); //CR5 L2 cache RTC/WTC
            BU_REG_WRITE(0xD4051080, 0x29E08622); //GB L1/L2/ROM/BSRAM cache RTC/WTC
		}
#endif		
}

#ifdef NEZHA3_1826
volatile UINT32 BsramBaseAddr = 0xD1000000;
UINT32 GetSiliconBsramAddr(void)
{
    return 0xD1000000;
}
#endif
#ifdef EDEN_1928
void SetCP624M()
{
	volatile UINT32 temp;
	temp = *(volatile UINT32*)0xd4051200;
	temp &= ~0x3f;
	temp |= (1<<5)|(0x3<<3); 
	*(volatile UINT32*)0xd4051200 = temp;
}

void SetCGPIO()
{
	BU_REG_WRITE(0xD401E228,0xd0c2); //fun2=C_GPIO[0]
	BU_REG_WRITE(0xD0240120,BU_REG_READ(0xD0240120)|0x1);//output
}
#endif

#if 1 //#if defined EDEN_1928 && defined SS_FEATURE
unsigned long discrete_board = 0;
#endif

UINT8 isDcsMode = 1; //DCS mode as default

UINT8 check_if_DCS_mode(void)
{
    if (CHIP_IS_CRANE)
        return TRUE; //Crane doesn't support SCS.
    else
        return isDcsMode;
}

#define PSRAM_BASE 0xc0100000
#define GEU_BASE   0xD4201000
#define BANK3_160_191 (GEU_BASE + 0x4A4)
extern UINT32 Image$$DDR_DSP_RO$$Base;

//#define RUN_XIP_MODE 1
void Cinit1(void)
{
 //{{{ BEGIN "Don't use GLOBALs" area (till END)
 	//[klocwork][issue id: 9070-9071]
    UINT32 l_DTCM_SZ = 0;
    UINT32 l_ITCM_SZ = 0;

    UINT32 itcmLdAddr ;
    UINT32 itcmExAddr ;
	UINT32 itcmLength ;
	UINT32 CurrTcmSz;
	UINT32 dtcmLength;
	UINT32 dtcmBaseAddr;
	UINT32 dtcmExBaseAddr;
	volatile UINT32 read_data, version;
#ifdef CRANE_MCU_DONGLE
	UINT32 dsp_temp_addr;
	UINT32 dsp_backup_size;
	UINT32 dsp_unpressed_size = 0;
	UINT32 dsp_flash_addr = 0;
#endif

#ifdef RUN_XIP_MODE
	UINT32 psramLdAddr ;
	UINT32 psramExAddr ;
	UINT32 psramLength ;
#endif

    // xiaokeweng@asrmicro.com 20200509
    // force PSRAM MMAP to 16M (for 16M PSRAM project)
    // avoid WB_8+8M prefetch abnormal address access hang
    //  8M [20:16] = 7
    // 16M [20:16] = 8
    // 32M [20:16] = 9
    // 64M [20:16] = 10
    read_data = *(volatile unsigned long*)(PSRAM_BASE + 0x0004);
    read_data &= ~(0xf << 16);
    read_data |=  (0x8 << 16);
    *(volatile unsigned long*)(PSRAM_BASE + 0x0004) = read_data;

/*---------------------------------------------------------------------*/

	//xiaoke@20190925: backup ptable info from DTCM into {NONCACHE_REGION_PTABLE}
	UINT32 ptablestart,ptableend;
	UINT32 prop_start,prop_end;

 	dtcmExBaseAddr = GetBaseExecAddrDTCM()          ; /* get exec addr. of region , to be load into D-TCM	*/

/**************************************
 *  [0xB0020000]~[0xB0020C00] PTABLE
 *  [0xB0020C00]~[0xB0022C00] PROPERTY
 **************************************/
#define PTABLE_SIZE   0xC00  //3K from BTCM beging for PTABLE struct
#define ASR_PROP_SIZE 0x1000 //4K

	ptablestart    = GetExecAddrPTABLE_START()      ; /* get length of region ptable	*/
	prop_start     = GetExecAddrPROP_START();       /* get length of region prop	*/

	/* backup ptable info from D-TCM into Noncache ptable region*/
	memcpy((void*)ptablestart,(void*)dtcmExBaseAddr,PTABLE_SIZE);

	/* startup property info size should be 4K backup startup prop info from (D-TCM + 3K) into Noncache prop region*/
	/* exec img before CP set the prop hand over to CP side */
	memcpy((void*)prop_start,(void*)(dtcmExBaseAddr+PTABLE_SIZE),(ASR_PROP_SIZE));

	dtcmLength     = GetImageLengthDTCM()           ; /* get length of region , to be load into D-TCM		*/
	dtcmBaseAddr   = GetBaseLoadAddrDTCM()          ; /* get load addr. of region , to be load into D-TCM	*/
	memcpy((void*)dtcmExBaseAddr,(void*)dtcmBaseAddr,dtcmLength);

    #if (defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM))
    /*ITCM is region compressed on craneL,roy add*/
    itcmExAddr  = GetBaseExecAddrITCM()			; /* get exec addr. of region , to be load into D-TCM		*/
	itcmLdAddr  = GetBaseBackupAddrITCM()			; /* get load addr. of region , to be load into D-TCM		*/
	itcmLength  = GetImageLengthITCM()			; /* get length  of region , to be load into D-TCM			*/
	memcpy((void*)itcmExAddr,(void*)itcmLdAddr,itcmLength);
    #else
	itcmExAddr  = GetBaseExecAddrITCM()			; /* get exec addr. of region , to be load into D-TCM		*/
	itcmLdAddr  = GetBaseLoadAddrITCM()			; /* get load addr. of region , to be load into D-TCM		*/
	itcmLength  = GetImageLengthITCM()			; /* get length  of region , to be load into D-TCM			*/
	memcpy((void*)itcmExAddr,(void*)itcmLdAddr,itcmLength);
	#endif


#if defined (TTC_BSP_ARM946_CP15) || (PHS_SW_DEMO_TTC)
	/*change vector table location to 0x00000000 since for TTC the vector is expected at the high address upon reset */
	Arm946eCP15SetAlternateVectorSelect(VECTOR_SELECT_MODE0);
#endif


/*---------------------------------------------------------------------*/











#if 0 //qianying
#ifndef EDEN_1928
	if (CHIP_IS_NEZHA)
	{
        WA_40LP_PLL1_stablize();
	}

	Platform_Pinmux_Config();
	//*(volatile unsigned long *)0xD401E294 = 0xa0c0;
#endif

#endif

#if defined EDEN_1928 && !defined SS_FEATURE
	//SetCP624M();
	//SetCGPIO() ;
	Set_Seagull_MFPR();
#endif

#ifndef EDEN_1928
	#ifdef RELEASE_REMAP
	WRITE_ARBEL_RC(0x0);
	WRITE_ARBEL_AGPOS(0x12345678);
	WRITE_ARBEL_MSEL(0x7777);
	#endif
#endif

#ifndef NEZHA3_1826
    if(!CHIP_IS_NEZHA2)
	{		
        /* Fetch Size of DTCM & ITCM , limit to set TCMs with ARM946E_TCM_SIZE_xxxK */
    	CurrTcmSz = Arm946eCP15GetTCMSizeReg();
    	l_DTCM_SZ = (CurrTcmSz >> DTCM_SZ_REGISTER_OFFSET) &  ARM946E_TCM_SZ_REG_AND_MASK ;
    	l_DTCM_SZ = (l_DTCM_SZ < ARM946E_TCM_SIZE_256K) ? l_DTCM_SZ :  ARM946E_TCM_SIZE_256K;
    	l_ITCM_SZ = (CurrTcmSz >> ITCM_SZ_REGISTER_OFFSET) &  ARM946E_TCM_SZ_REG_AND_MASK ;
    	l_ITCM_SZ = (l_ITCM_SZ < ARM946E_TCM_SIZE_128K) ? l_ITCM_SZ :  ARM946E_TCM_SIZE_128K;
	}
#endif

/* remove INIT_DATA region
	if(strcmp(pin_data_magic_key, "Init Reserved Data") != 0)
	{
		CopyInitDataRWtoImage();
		InitDataFlag = 1;
	}
*/
	commImageTableInit();
	
	/* Copy non-ZI data from load region into execution region */
	CopyDataRWtoImage();

	commImageTableInit();

#ifndef RUN_XIP_MODE
//    incrementCommNumOfLife();
#endif

//	cinit1ProtectedArea();
	
	//CopyHSDPARWtoImage()


/*---------------------------------------------------------------------*/




/*---------------------------------------------------------------------*/





#if 0
#if defined (TTC_BSP_ARM946_CP15) || (PHS_SW_DEMO_TTC)
	/*change vector table location to 0x00000000 since for TTC the vector is expected at the high address upon reset */
	Arm946eCP15SetAlternateVectorSelect(VECTOR_SELECT_MODE0);
#endif
#endif

	silentReset_Check();
	needToDump = 0;
	if((*(volatile unsigned long*)0xd4080070) & 0x1)
	{
		if(Startupmode_get()!= STARTUP_SILENTRESET)
		{
			needToDump = 1;
		}
	}
	extern void recordPreExcepInfo(void);
	recordPreExcepInfo();

    SetDataZeroInitialized();
 //}}} END "Don't use GLOBALs" area

    // Set now all required globals
	 uart_reset();

	 PlatformGetConstData();


/***************************************************************************************************************************
*Sharon.li@20220425此处可以进行板级初始化，包括Pin脚状态、电压域等
*Board-level initialization can be performed here, including Pin status, voltage domain, etc.
****************************************************************************************************************************/
#if defined QUECTEL_PROJECT_CUST
#if defined (__QUECTEL_PROJECT_EC600MCN_LC__) || defined (__QUECTEL_PROJECT_EC600MCN_CC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_GC__) || defined (__QUECTEL_PROJECT_EC600MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_LF__) || defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
    || defined (__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_LC__) || defined (__QUECTEL_PROJECT_EC800MCN_LF__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_MC__) || defined (__QUECTEL_PROJECT_EC800MCN_GA__)\
    || defined (__QUECTEL_PROJECT_EC800MCN_GC__) || defined (__QUECTEL_PROJECT_EC600MCN_MC__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined (__QUECTEL_PROJECT_EG810MCN_GA__)\
    || defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__) \
    || defined (__QUECTEL_PROJECT_EC600MCN_NC__) || defined (__QUECTEL_PROJECT_EC600MEU_LA__) \
    || defined (__QUECTEL_PROJECT_EC800MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__) \
    || defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG810MLA_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600MLA_LA__)
#include "guilin_lite.h"

if(PMIC_IS_PM803()) 
{
	GuilinLite_Ldo_7_set(0);
}

#endif


#endif
/**************************************************************************************************************************/

	//seagull_uart_init();
	//while(1);
	 if (!CHIP_IS_CRANE)
     {
         isDcsMode = *(volatile UINT32*)0xD40C001C & 0x1; //SCS RTC reg
         if (isDcsMode)
            CP_LOGI("in DCS mode.\r\n");
         else
            CP_LOGI("in SCS mode.\r\n");
     }
   if (CHIP_IS_CRANE)
     {
         /*fix DMA issue*/
         *(volatile unsigned long*)(0xd4282c00 + 0x1a4) &= ~(0x1 << 1); //CP DMA
         *(volatile unsigned long*)(0xd4050000 + 0x1054) &= ~(0x1 << 30); //X1 DMA
     }
     else if (CHIP_IS_CRANEG_Z2)
     {
         /*fix DMA issue*/
         *(volatile unsigned long*)(0xd4282c00 + 0x1a4) &= ~(0x1 << 1); //CP DMA
     }
	 ptable_init();
	 
	#ifndef MIN_SYS
	if (!IsMiniSystem()) 
	{//MiniSystem

#ifdef QUEC_UART2_ENABLE
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
		{
			extern void CPUartLogPrint(char* log, BOOL CRLF);
			UINT32 quec_cfg_addr = get_quec_cfg_start_address();
			quec_production_cfg_s *ptr = (quec_production_cfg_s*)quec_cfg_addr;
			uart_printf("Egan=%d 0x%x %d\r\n",ptr->debug_onff,quec_cfg_addr,ptr->quec_dualport_support);
			uart_printf("\r\n");
			fatal_printf("\r\n");
			CPUartLogPrint("\r\n", FALSE);
		// 	 memcpy(&uart2_mode_cfg,0x80FD7000,sizeof(uart2_mode_cfg));
			if (0 == memcmp(ptr->quec_chk_bytes, QUEC_CFG_BYTE_STR, strlen(QUEC_CFG_BYTE_STR)))
			{
				g_uart2_mode=ptr->quec_dualport_support;
				uart_printf("quec_cfg ok %d\r\n",g_uart2_mode);
				#if QUEC_DEBUG_LOG_SWITCH
				{
				extern int cp_log_flag;
				if((ptr->debug_onff==1)||(ptr->debug_onff==0))
				{
				//cp_log_flag=ptr->debug_onff;
				}
				}
				#endif
			}
		}
#endif
#endif	 
	}
	#endif

	 ptable_dump();
	 asr_property_dump();
	 uart_printf("srand(1)\r\n");
	 srand(1);

	 GetUmtsChipVersion();

#ifndef NEZHA3_1826
	/*for volte packet, the data buffer would was allocated from heap.  the process of data buffer would be executed by DTC,
for 1920/1928/1908, the DTC only can access 0x07000000-0x08000000, for Nezha3 no this limitation*/
    if((UINT32)&Image$$DDR_HEAP_GUARD$$Base>0x07000000)
		 intRamFreeStart = 0x07000000; 
	else
		 intRamFreeStart=(UINT32)&Image$$DDR_HEAP_GUARD$$Base;
#else
	intRamFreeStart = (UINT32)&Image$$DDR_HEAP_GUARD$$Base; //Image$$DTC_DATA$$ZI$$Limit;//Image$$DDR_RW_DATA$$ZI$$Limit;
#endif
    intRamFreeEnd   = (UINT32)&Image$$DDR_HEAP_ENDMARK$$Base;

#if 0
    intIMSRamFreeStart = (UINT32)&Image$$DDR_IMS_HEAP_GUARD$$Base;
    intIMSRamFreeEnd = (UINT32)&Image$$DDR_IMS_HEAP_ENDMARK$$Base;
#endif

    dtcmFreeStart = (UINT32)&Image$$DDR_DTCM$$ZI$$Limit;
    dtcmFreeEnd   = (UINT32)&Image$$DDR_DTCM_ENDMARKER$$Base ;

#ifndef NEZHA3_1826
    if(!CHIP_IS_NEZHA2)
    {
        DTCM_SZ = l_DTCM_SZ;
        ITCM_SZ = l_ITCM_SZ;
    }
#endif

#if defined(MIPS_TEST_RAM)
#if 0
    mipsRamStart();
#endif
#endif

	/* enable Cycle counter */
	SetPMNC();

	read_data = *(volatile UINT32 *)0xD4050024;
	read_data |= 0x1000;
	*(volatile UINT32 *)0xD4050024 = read_data;

	read_data = *(volatile UINT32 *)0xD4282868;
	read_data |= 0x9;
	*(volatile UINT32 *)0xD4282868 = read_data;

	read_data = *(volatile UINT32 *)BANK3_160_191;

	*(volatile UINT32 *)0xD4282868 = 0x0;

	version = (read_data >> 8) & 0x7;


	if(version == 4)
	{
		read_data = *(volatile UINT32 *)(PSRAM_BASE + 0x8000);
		read_data &= 0xff00ffff;
		read_data |= (5<<16)|(5<<20);
		*(volatile UINT32 *)(PSRAM_BASE + 0x8000) = read_data;
	}

    // xiaokeweng@asrmicro.com 20200509
    // should force PSRAM MMAP to 16M (for 16M PSRAM project)
    // avoid WB_8+8M prefetch abnormal address access hang
    // do PSRAM MMAP cfg reg dump here
    //  8M [20:16] = 7
    // 16M [20:16] = 8
    // 32M [20:16] = 9
    // 64M [20:16] = 10
    uart_printf("@0x%0.8x: 0x%0.8x\r\n",(PSRAM_BASE+0x0004),*(volatile unsigned long*)(PSRAM_BASE + 0x0004));

    // set psram fast refresh and config lpm table
    extern int crane_psram_init(void);
    crane_psram_init();

    /*********** Configure the DDR access priority --- begin ***********/
    {
        *(volatile UINT32 *)0xD4051054 &= ~(0xFFFF<<8); //CP_FAB_CTRL in PMUM
        *(volatile UINT32 *)0xD4051054 |= (0x4444<<8); //X1 weighs same as modem
        /* X1(29:27)=4,LTE(26:24)=3,CR5(5:3)=2, others:0 */
        *(volatile UINT32 *)0xD4282D18 = 0x23000010; //port QoS

        *(volatile UINT32 *)0xC0100000 |= (0x1<<6); //port weight enable
        *(volatile UINT32 *)0xC0100008 = 0xF030F030; //port weight

        *(volatile UINT32 *)0xC010000C &= ~((0xFFFFUL<<16)|(0xF<<6)); //wcb_rcb aging counter
        *(volatile UINT32 *)0xC010000C |= (0x3030<<16)|(0x1<<9)|(0x1<<6); //ratio-> 1:1

        *(volatile UINT32 *)0xC010400C = 0x446603A0; //qos4=3, qos3=2, qos_2=2, qos_1=0, qos_0=0

        uart_printf("@0xD4051054: 0x%x, @0xC010000C: 0x%x, @0xC010400C: 0x%x\r\n",
        *(volatile UINT32 *)0xD4051054,*(volatile UINT32 *)0xC010000C,*(volatile UINT32 *)0xC010400C);

        uart_printf("@0xD4282D18: 0x%x, @0xC0100000: 0x%x, @0xC0100008: 0x%x\r\n",
        *(volatile UINT32 *)0xD4282D18,*(volatile UINT32 *)0xC0100000,*(volatile UINT32 *)0xC0100008);

    }
    /*********** Configure the DDR access priority --- end *************/

	/* 20090116, PHS move MSAPhase1Init to CInit1 (before enable MPU and I/D cache) */

//		MSAPhase1Init(); 

	//for PS bit transfer
	SetspecialPShandle();

    initState=BSP_INIT_CINIT1_PASSED;

#ifdef NEZHA3_1826
	lteChainBaseAddressCh0=lteChainBaseAddressCh0_nezha;
	lteChainBaseAddressCh1=lteChainBaseAddressCh1_nezha;
#else
	if(CHIP_IS_HELTE)
	{
		lteChainBaseAddressCh0=lteChainBaseAddressCh0_helan;
		lteChainBaseAddressCh1=lteChainBaseAddressCh1_helan;

	}
	else
	{
		lteChainBaseAddressCh0=lteChainBaseAddressCh0_nezha;
		lteChainBaseAddressCh1=lteChainBaseAddressCh1_nezha;
	}
#endif

    /* configure RTC/WTC for Seagull's TCM/L1$/L2$ */
    Configure_RTC_WTC();

	if(CHIP_IS_CRANELR)
	{
		*(volatile UINT32 *)(0xd4090128) = 0x4842414;  //set PSRAM IO DS=0 from default 1
	}	

#if (defined(CRANE_MCU_DONGLE) && !defined(NO_MUTI_LOADTABLE_SUPPORT))
	 /* NOTE : Must recover the dsp backup info  before heap init !!! */
	 //recover sector1 dsp.bin to execute region
	dsp_temp_addr = get_dsp_backup_addr();
	dsp_backup_size = get_dsp_backup_size();

    extern unsigned int LzmaUncompressLen(const unsigned char *src);
    extern UINT32 dsp_dtcm_bk_addr;
    dsp_flash_addr = get_dsp_start_address();
    if(dsp_flash_addr & 0x80000000){
        dsp_unpressed_size = (UINT32)LzmaUncompressLen((const unsigned char *)dsp_flash_addr);
    }
    
    //0x0004C000-------DSP Reduce Sulog Buffer Size[304KB] {128KB ITCM + 248KB RAM}, RF Address[0x7E000000]
    //0x0003E000-------DSP Reduce Sulog Buffer Size[248KB] {248KB RAM             }, RF Address[0x7E010000]
    //0x00049000-------DSP Reduce Sulog Buffer Size[292KB] {292KB RAM             }, RF Address[0x7E010000]
    //0x00052000-------DSP Reduce Sulog        Size[328KB] {328KB RAM             }, RF Address[0x7E010000]
    //0x00070000-------DSP ALLIN               Size[448KB] {448KB RAM             }, CraneL RF Address[0x7E065000],craneLS and craneLR RF Address[0x7E045000]

    //dsp_unpressed_size = 0,dsp on external flash,not support xip can't get dsp unpressed size
     if((dsp_unpressed_size == 0x0004C000)
         || (dsp_unpressed_size == 0 && dsp_backup_size == 0x0004C000)){
         memcpy((UINT8 *)(dsp_temp_addr + 0x0004C000), (UINT8 *)dsp_temp_addr, 0x00020000);
         dsp_dtcm_bk_addr = dsp_temp_addr + 0x0004C000;
         memcpy((UINT8 *)(UINT32)&Image$$DDR_DSP_RO$$Base, (UINT8 *)(dsp_temp_addr + 0x0000E000), 0x0003E000);
         
     }else{
         //memcpy((UINT8 *)(dsp_temp_addr + dsp_backup_size), (UINT8 *)dsp_temp_addr, 0x00020000);
         memcpy((UINT8 *)(UINT32)&Image$$DDR_DSP_RO$$Base,(UINT8 *)dsp_temp_addr,dsp_backup_size);
         //dsp_dtcm_bk_addr = dsp_temp_addr + dsp_backup_size;
     }
#if 0
#if (defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM))
        if(dsp_backup_size != dsp_unpressed_size){
            //dsp on external flash,not support xip can't get dsp unpressed size
            if((dsp_unpressed_size==0) || ((dsp_backup_size <= 0x00052000) && (dsp_unpressed_size>dsp_backup_size))){

                CPUartLogPrintf("Cinit 1,DSP error!!![%08x]:[%08x]",dsp_unpressed_size,dsp_backup_size);
                while(1);
            }
        }
    
#endif
#endif
#endif

	Cinit2();

    //Dummy procedure used to force-link procedure or data into the image
    //Should never be reached
#if 0 //LOADTABLE_REFACTOR@xiaokeweng_20190423 build pass
    forceLinkIntoImage();
#endif
} /* Cinit1 */



/*******************************************************************************
*  "C" wrappers for ASM implemented functions - used by DLM only
*
* Arm946eDisableInterrupts - disables IRQ & FIQ, returns the old value
* Arm946eEnableInterrupts  - enable   IRQ & FIQ unconditionally
* Arm946eRestoreInterrupts - restore  IRQ & FIQ to the value given by calling function
**/

UINT32 Arm946eDisableInterrupts(void) { return disableInterrupts();  }
UINT32 Arm946eEnableInterrupts (void) { return enableInterrupts ();  }
void   Arm946eRestoreInterrupts(UINT32  ir    )  { restoreInterrupts (ir); }


/*******************************************************************************
*          MEMORY INITIALIZATION utilities
*              get addresss
*              get length
*              zero initialize an area
*              make copy
*
*  Load$$xx$$Base   - beginning of "Flash located" area, this is SourceAddr if should be copied
*  Load$$xx$$Length - length    of "Flash located" area
* Image$$xx$$Base   - beginning of " RAM  located" area, this is DectinationAddr if should be copied
* Image$$xx$$Length - length    of " RAM  located" area
**/
static UINT32 GetImageLengthITCM (void) { return (UINT32)&(Image$$DDR_ITCM$$Length); }
static UINT32 GetImageLengthDTCM (void) { return (UINT32)&(Image$$DDR_DTCM$$Length); }
static UINT32 GetBaseLoadAddrITCM(void) { return (UINT32)&(Load$$DDR_ITCM$$Base); }
static UINT32 GetBaseBackupAddrITCM(void) { return (UINT32)&(Image$$DDR_NONCACHE_USB$$Base); }/*using DDR_NONCACHE_USB to backup itcm code*/
static UINT32 GetBaseExecAddrITCM(void) { return (UINT32)&(Image$$DDR_ITCM$$Base); }
static UINT32 GetBaseLoadAddrDTCM(void) { return (UINT32)&(Load$$DDR_DTCM$$Base); }
static UINT32 GetBaseExecAddrDTCM(void) { return (UINT32)&(Image$$DDR_DTCM$$Base); }

static UINT32 GetExecAddrPTABLE_START(void) { return (UINT32)&(Image$$DDR_NONCACHE_REGION_PTABLE$$Base); }
static UINT32 GetExecAddrPTABLE_END(void)   { return (UINT32)&(Image$$DDR_NONCACHE_REGION_PTABLE_ENDMARK$$Base); }
static UINT32 GetExecAddrPROP_START(void) { return (UINT32)&(Image$$DDR_NONCACHE_REGION_PROP$$Base); }
static UINT32 GetExecAddrPROP_END(void)   { return (UINT32)&(Image$$DDR_NONCACHE_REGION_PROP_ENDMARK$$Base); }

static void SetDataZeroInitialized(void)
{
	UINT32 *start_addr;
	UINT32 *end_addr  ;
	UINT32 length;
	

	start_addr = &(Image$$DDR_RW_DATA$$ZI$$Base) ;
	end_addr   = &(Image$$DDR_RW_DATA$$ZI$$Limit);
	length = (UINT32)end_addr - (UINT32)start_addr;
	memset((UINT8 *)start_addr, 0, length);


	start_addr = &(Image$$DDR_DTCM$$ZI$$Base) ;
	end_addr   = &(Image$$DDR_DTCM$$ZI$$Limit);
	length = (UINT32)end_addr - (UINT32)start_addr;
	memset((UINT8 *)start_addr, 0, length);


	if(needToDump == 0)
	{
		extern UINT32  Image$$DDR_NONCACHE_REGION$$ZI$$Base;
		extern UINT32  Image$$DDR_NONCACHE_REGION$$ZI$$Limit;
		start_addr = &(Image$$DDR_NONCACHE_REGION$$ZI$$Base) ;
		end_addr   = &(Image$$DDR_NONCACHE_REGION$$ZI$$Limit);
		length = (UINT32)end_addr - (UINT32)start_addr;
		memset((UINT8 *)start_addr, 0, length);
	}
#ifdef LWIP_IPNETBUF_SUPPORT
    start_addr = &(Image$$DDR_NONCACHE_USB$$ZI$$Base) ;
	end_addr   = &(Image$$DDR_NONCACHE_USB$$ZI$$Limit);
	length = (UINT32)end_addr - (UINT32)start_addr;

	if(length > 0)
	{
	    memset((UINT8 *)start_addr, 0, length);
	}
#endif

#ifdef PROJ_ASR_APP_001
	start_addr = &(Image$$MMI_DATA$$ZI$$Base);
	end_addr   = &(Image$$MMI_DATA$$ZI$$Limit);
	length = (UINT32)end_addr - (UINT32)start_addr;
	memset((UINT8 *)start_addr, 0, length);
#endif

}


void copyRWtoImage(UINT32 * src, UINT32 * dst, UINT32 length)
{
#ifdef RUN_XIP_MODE
    //no need to check memory overlap for XIP version, and "memcpy" will shorten the copy period.
    if(dst != src)
    {
        // Check Load and Image overlap
        if(  (src < dst) && ( (src + (length>>2)) >= dst )
            || (src > dst) && ( (dst + (length>>2)) >= src )  )
        {
           ASSERT(0);
        }

        if(length > 0)
        {
	   memcpy((UINT8 *)dst, (UINT8 *)src, length);
        }
    }
#else
    length /= sizeof(unsigned int);

    if ((src < dst) && ( (src + (length)) >= dst ))//little-End case
    {
		src+=length;
		dst+=length;
        while(length>0){*dst-- = *src--;length--;}
    }else{
        while(length>0){*dst++ = *src++;length--;}
    }
#endif
}


/* remove INIT_DATA region
static void CopyInitDataRWtoImage(void)
{
    UINT32 *src;
    UINT32 *dst;
    UINT32 length;
    dst    = &(Image$$INIT_DATA$$Base);
    src    = &(Load$$INIT_DATA$$Base);
    length = (unsigned int)&(Image$$INIT_DATA$$Length);

    copyRWtoImage(src,dst,length);
}
*/

static void CopyDataRWtoImage(void)
{
    UINT32 *src;
    UINT32 *dst;
    UINT32 length;


#if (defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM))
    /*DDR_NONCACHE_USB is not region compressed on craneL,roy add*/
    #ifdef LWIP_IPNETBUF_SUPPORT
    //DDR_NONCACHE_USB ???
    dst    = &(Image$$DDR_NONCACHE_USB$$Base);
    src    = &(Load$$DDR_NONCACHE_USB$$Base);
    length = (UINT32)&(Image$$DDR_NONCACHE_USB$$Length);
    copyRWtoImage(src,dst,length);
    #endif
#else
//xiaoke@20190303 ++ external RW REGION compress
if (whether_RW_region_compressed() == FALSE){
 
    #ifdef LWIP_IPNETBUF_SUPPORT
    //DDR_NONCACHE_USB ???
    dst    = &(Image$$DDR_NONCACHE_USB$$Base);
    src    = &(Load$$DDR_NONCACHE_USB$$Base);
    length = (UINT32)&(Image$$DDR_NONCACHE_USB$$Length);
    copyRWtoImage(src,dst,length);
    #endif

    //NONCACHE_DATA
    dst    = &(Image$$PS_NONCACHE_DATA$$Base);
    src    = &(Load$$PS_NONCACHE_DATA$$Base);
    length = (unsigned int)&(Image$$PS_NONCACHE_DATA$$Length);
    copyRWtoImage(src,dst,length);

        //DDR_RW_DATA
        dst    = &(Image$$DDR_RW_DATA$$Base);
        src    = &(Load$$DDR_RW_DATA$$Base);
        length = (unsigned int)&(Image$$DDR_RW_DATA$$Length);
        copyRWtoImage(src,dst,length);

        #ifdef PROJ_ASR_APP_001
        //MMI_DATA
        dst    = &(Image$$MMI_DATA$$Base);
        src    = &(Load$$MMI_DATA$$Base);
        length = (unsigned int)&(Image$$MMI_DATA$$Length);
        copyRWtoImage(src,dst,length);
        #endif

        #ifdef RUN_XIP_MODE
        dst    = &(Image$$PS_CODE_IN_PSRAM$$Base);
        src    = &(Load$$PS_CODE_IN_PSRAM$$Base);
        length = (unsigned int)(&(Image$$PS_CODE_IN_PSRAM$$Length));
        copyRWtoImage(src,dst,length);
        #endif
    }
#endif

    //D2_VECT
    dst    = &(Image$$D2_VECT$$Base);
    src    = &(Load$$D2_VECT$$Base);
    length = (unsigned int)&(Image$$D2_VECT$$Length);
    copyRWtoImage(src,dst,length);

}

static void CopyHSDPARWtoImage(void)
{
    UINT32 *src;
    UINT32 *dst;
    UINT32 length;
    dst    = &(Image$$HSDPA$$Base);
    src    = &(Load$$HSDPA$$Base);
    length = (unsigned int)&(Image$$HSDPA$$Length);

    copyRWtoImage(src,dst,length);
}

/******************************************************************
* The pointer function Arm946eMemcpy() is used in DLM tables.
*  Keep it here till DLM modification
*/
int Arm946eMemcpy (void* dst,void* src , int length)
{
    unsigned char *dst1 = (unsigned char*)dst;
    unsigned char *src1 = (unsigned char*)src;
    if(dst1 != src1)
    {
        while(length >0)
    { 
        *dst1++ = *src1++;
        length--; 
    }
  }
    return 0;
}

void DynamicMemoryInit(void)
{
    intMemHeapInit(intRamFreeStart, intRamFreeEnd, TRUE);   //  Use as default pool.

    dtcmHeapInit(dtcmFreeStart, dtcmFreeEnd);

#if defined (DLDATA_IN_PSRAM)
	extern UINT32 is_psramfotastart(void);
	if(is_psramfotastart()){
		uart_printf("%s,psram fota don't call mmiHeadInit\r\n",__func__);

	}else

#endif
	{
#ifdef PROJ_ASR_APP_001
	extern unsigned char mmiPool[];
	extern unsigned int mmiPoolSize;

	mmiHeapInit((unsigned int)mmiPool, (unsigned int)mmiPool + mmiPoolSize);
#endif
	}
/***
	if(bspExtMemUsed || ((intRamFreeEnd-intRamFreeStart)<HEAP_MIN_SIZE))
	{
	  extMemHeapInit(extRamFreeStart, extRamFreeEnd);
	  bspExtMemUsed = TRUE;
	}
***/
}

/************************************************************************
* Function: bspIsExtMemUsed                                             *
*************************************************************************
* Description:                                                          *
*                                                                       *
************************************************************************/
/***
BOOL bspIsExtMemUsed(void)
{
	return bspExtMemUsed;
}
***/
