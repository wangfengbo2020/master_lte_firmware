/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************
 *    Copyright (C) 2004 Intel Corporation
 *
 *    DESCRIPTION:
 *
 *    AUTHOR:
 *
 *    Date Created:3/21/2004 8:32:31 AM
 *
 *    HISTORY:
 *	SE  05 December 2007 TTC modfications
 *  YK 21 March 2007	duplicated APIs to reside on both DDR (for init) and TCM (for D2 exit)
 *
 * NOTE:
 *  APIs with _DS _TCS mean they are duplicated twice, to run at init from DDR
 *	and to run from TCM on D2 exit. The source files are duplicated in CC and controlled
 *	by compilation switch and MACROS of FUNCNAME_CTRL, TABLENAME_CTRL
 *
 *******************************************************************/

#if !defined (ARM946E_SCP15_H)
#define ARM946E_SCP15_H

/** include files **/
#include "arm946e_config.h"
#include "global_types.h"
#if defined (TTC_CORE_ARM946_CP15)
#include "sCP15_l2cache.h"
#endif
#include "arm946e_smpu.h"

#if defined (TTC_CORE_ARM946_CP15)
/* TTC - maintaining legacy API for core package routines */
#define Arm946eCP15GetControlReg_TCS Arm946eCP15GetControlReg_DS
#define Arm946eCP15GetMPUEnalbe_TCS Arm946eCP15GetMPUEnalbe_DS
#define Arm946eCP15SetInstTCMEnable_TCS Arm946eCP15SetInstTCMEnable_DS
#define Arm946eCP15SetDataTCMEnable_TCS Arm946eCP15SetDataTCMEnable_DS
#define Arm946eCP15SetInstCacheEnable_TCS Arm946eCP15SetInstCacheEnable_DS
#define Arm946eCP15SetDataCacheEnable_TCS Arm946eCP15SetDataCacheEnable_DS
#define Arm946eCP15SetMPUEnalbe_TCS Arm946eCP15SetMPUEnalbe_DS
#define Arm946eCP15SetMPUDisable_TCS Arm946eCP15SetMPUDisable_DS
#define Arm946eCP15RestoreMPUEnableDisable_TCS Arm946eCP15RestoreMPUEnableDisable_DS
#define Arm946eCP15SetRegionAccessPermission_TCS Arm946eCP15SetRegionAccessPermission_DS
#define Arm946eCP15SetRegionBaseAndSizeReg_TCS Arm946eCP15SetRegionBaseAndSizeReg_DS
#define Arm946eCP15SetDataTCMRegionBaseAndSizeReg_TCS Arm946eCP15SetDataTCMRegionBaseAndSizeReg_DS
#define Arm946eCP15SetInstTCMRegionBaseAndSizeReg_TCS Arm946eCP15SetInstTCMRegionBaseAndSizeReg_DS
#define asm_Arm9ReadCP15_TCS asm_Arm9ReadCP15_DS
#define asm_Arm9WriteCP15_TCS asm_Arm9WriteCP15_DS
#endif


typedef union
{
	struct
	{
		UINT32 pmuEnable:1;
		UINT32 :1 ; // reserved
		UINT32 dCacheEnable:1 ;
		UINT32 :4 ;	// reserved
		UINT32 bigEndian:1;
#if defined (TTC_CORE_ARM946_CP15)
		UINT32 :3 ;	// reserved
		UINT32 bpuEnable:1;
#else
        UINT32 :4 ;	// reserved
#endif
		UINT32 iCacheEnable:1;
		UINT32 alternateVectorSelect:1;
		UINT32 roundRobinReplacement:1;
		UINT32 diableLoadingTIBT:1;
		UINT32 dTCMEnable:1;
		UINT32 dTCMLoadMode:1;
		UINT32 iTCMEnable:1;
		UINT32 iTCMLoadMode:1;
		UINT32 :12; // reserved
	}bits;

	UINT32 all;
} arm946eControlRegU;

extern arm946eControlRegU _arm946eControlReg_DS;

// General IDs for read & write from CP15 registers
#if defined (TTC_CORE_ARM946_CP15)
typedef enum {
	ARM946E_CP15_CONTROL_REG = 0,
	ARM946E_CP15_DATA_CACHEABLE_REG,
	ARM946E_CP15_INST_CACHABLE_REG,
	ARM946E_CP15_DATA_BUFFERABLE_REG,
	ARM946E_CP15_DATA_ACCESS_PREMISSION_REG,
	ARM946E_CP15_INSTRUCTION_ACCESS_PREMISSION_REG,
	ARM946E_CP15_PROTECTION_REGION_0_REG,
	ARM946E_CP15_PROTECTION_REGION_1_REG,
	ARM946E_CP15_PROTECTION_REGION_2_REG,
	ARM946E_CP15_PROTECTION_REGION_3_REG,
	ARM946E_CP15_PROTECTION_REGION_4_REG,
	ARM946E_CP15_PROTECTION_REGION_5_REG,
	ARM946E_CP15_PROTECTION_REGION_6_REG,
	ARM946E_CP15_PROTECTION_REGION_7_REG,
	ARM946E_CP15_DATA_LOCKDOWN_CONTROL_REG,
	ARM946E_CP15_INST_LOCKDOWN_CONTROL_REG,
	ARM946E_CP15_DATA_TCM_REGION_REG,
	ARM946E_CP15_INST_TCM_REGION_REG,
	ARM946E_CP15_PID_REG,
	ARM946E_CP15_CACHE_DEBUG_INDEX_REG,
	ARM946E_CP15_INST_TAG_WRITE_REG,
	ARM946E_CP15_DATA_TAG_WRITE_REG,
	ARM946E_CP15_INST_CACHE_WRITE_REG,
	ARM946E_CP15_DATA_CACHE_WRITE_REG,
	ARM946E_CP15_CONTROL_CONFIGURATION_REG,
	ARM946E_CP15_PERFORMANCE_COUNTER_AP_REG,
	ARM946E_CP15_COPROCESSOR_ENABLE_REG,
	ARM946E_CP15_REGISTERS_NUM
} EARM946ECP15Regs;
#else
typedef enum {
	ARM946E_CP15_ID_CODE_REG =0 ,
	ARM946E_CP15_CACHE_DETAILS_REG,
	ARM946E_CP15_TCM_SIZE_REG,
	ARM946E_CP15_CONTROL_REG,
	ARM946E_CP15_DATA_CACHEABLE_REG,
	ARM946E_CP15_INST_CACHABLE_REG,
	ARM946E_CP15_DATA_BUFFERABLE_REG,
	ARM946E_CP15_DATA_ACCESS_PREMISSION_REG,
	ARM946E_CP15_INSTRUCTION_ACCESS_PREMISSION_REG,
	ARM946E_CP15_PROTECTION_REGION_0_REG,
	ARM946E_CP15_PROTECTION_REGION_1_REG,
	ARM946E_CP15_PROTECTION_REGION_2_REG,
	ARM946E_CP15_PROTECTION_REGION_3_REG,
	ARM946E_CP15_PROTECTION_REGION_4_REG,
	ARM946E_CP15_PROTECTION_REGION_5_REG,
	ARM946E_CP15_PROTECTION_REGION_6_REG,
	ARM946E_CP15_PROTECTION_REGION_7_REG,
	ARM946E_CP15_FLUSH_INST_CACHE_REG,
	ARM946E_CP15_INVALIDATE_INST_CACHE_SINGLE_ENTRY_REG,
	ARM946E_CP15_PREFETCH_INST_CACHE_LINE_REG,
	ARM946E_CP15_FLUSH_DATA_CACHE_REG,                      /*20*/
	ARM946E_CP15_INVALIDATE_DATA_CACHE_SINGLE_ENTRY_REG,
	ARM946E_CP15_CLEAN_DATA_CACHE_ENTRY_REG,
	/*Added by AlexR 15.07.2004*/
	ARM946E_CP15_CLEAN_AND_FLASH_DATA_CACHE__ENTRY_REG,
	ARM946E_CP15_FLUSH_DATA_CACHE_SINGLE_ENTRY_INDEX_AND_SEGMENT_REG,
	ARM946E_CP15_CLEAN_DATA_CACHE_INDEX_AND_SEGMENT_ENTRY_REG,
	ARM946E_CP15_DRAIN_WRITE_BUFFER_REG,
	ARM946E_CP15_LOW_POWER_STATE_REG,
	ARM946E_CP15_DATA_LOCKDOWN_CONTROL_REG,
	ARM946E_CP15_INST_LOCKDOWN_CONTROL_REG,
	ARM946E_CP15_DATA_TCM_REGION_REG,
	ARM946E_CP15_INST_TCM_REGION_REG,
	ARM946E_CP15_PID_REG,
	ARM946E_CP15_TAG_BIST_CONTROL_REG,
	ARM946E_CP15_TCM_BIST_CONTROL_REG,
	ARM946E_CP15_CACHE_RAM_BIST_CONTROL_REG,
	ARM946E_CP15_INST_TAG_BIST_ADDR_REG,
	ARM946E_CP15_INST_TAG_BIST_GENERAL_REG,
	ARM946E_CP15_DATA_TAG_BIST_ADDR_REG,
	ARM946E_CP15_DATA_TAG_BIST_GENERAL_REG,
	ARM946E_CP15_INST_TCM_BIST_ADDR_REG,
	ARM946E_CP15_INST_TCM_BIST_GENERAL_REG,
	ARM946E_CP15_DATA_TCM_BIST_ADDR_REG,
	ARM946E_CP15_DATA_TCM_BIST_GENERAL_REG,
	ARM946E_CP15_INST_CACHE_RAM_BIST_ADDR_REG,
	ARM946E_CP15_INST_CACHE_RAM_BIST_GENERAL_REG,
	ARM946E_CP15_DATA_CACHE_RAM_BIST_ADDR_REG,
	ARM946E_CP15_DATA_CACHE_RAM_BIST_GENERAL_REG,
	ARM946E_CP15_TEST_STATE_REG,
	ARM946E_CP15_CACHE_DEBUG_INDEX_REG,
	ARM946E_CP15_INST_TAG_WRITE_REG,
	ARM946E_CP15_DATA_TAG_WRITE_REG,
	ARM946E_CP15_INST_CACHE_WRITE_REG,
	ARM946E_CP15_DATA_CACHE_WRITE_REG,
	ARM946E_CP15_TRACE_CONTROL_REG,
	ARM946E_CP15_DCACHE_LN_INVALIDATE_REG,
	ARM946E_CP15_REGISTERS_NUM
} EARM946ECP15Regs;
#endif
// TCM load mode
typedef enum{
	TCM_LOAD_MODE_DISABLE = 0,
	TCM_LOAD_MODE_ENABLE
}ETCMLoadMode;

typedef enum{
	TCM_DISABLE = 0,
	TCM_ENABLE
}ETCMMode;

typedef enum{
	CACHE_DISABLE = 0,
	CACHE_ENABLE
}ECacheMode;

typedef enum{
	VECTOR_SELECT_MODE0 = 0,
	VECTOR_SELECT_MODE1
}EVectorSelectMode;

typedef enum{
	LITTLE_ENDIAN =0,
	BIG_ENDIAN
}EEndianConfiguration;

typedef enum{
	PMU_DISABLE = 0,
	PMU_ENABLE
}EPMUMode;

#if defined (TTC_CORE_ARM946_CP15)
typedef enum{
	BPU_DISABLE = 0,
	BPU_ENABLE
}EBpuMode;
#endif


//Cache size definitions
#define ARM946E_CACHE_SIZE_0K   (0x0L) // (b0000)
#define ARM946E_CACHE_SIZE_4K   (0x3L) // (b0011)
#define ARM946E_CACHE_SIZE_8K   (0x4L) // (b0100)
#define ARM946E_CACHE_SIZE_16K  (0x5L) // (b0101)
#define ARM946E_CACHE_SIZE_32K  (0x6L) // (b0110)
#define ARM946E_CACHE_SIZE_64K  (0x7L) // (b0111)
#define ARM946E_CACHE_SIZE_128K (0x8L) // (b1000)
#define ARM946E_CACHE_SIZE_256K (0x9L) // (b1001)
#define ARM946E_CACHE_SIZE_512K (0xAL) // (b1010)
#define ARM946E_CACHE_SIZE_1M   (0xBL) // (b1011)

//TCM size definitions
#define ARM946E_TCM_SIZE_0K   (0x0L) // (b0000)
#define ARM946E_TCM_SIZE_4K   (0x3L) // (b0011)
#define ARM946E_TCM_SIZE_8K   (0x4L) // (b0100)
#define ARM946E_TCM_SIZE_16K  (0x5L) // (b0101)
#define ARM946E_TCM_SIZE_32K  (0x6L) // (b0110)
#define ARM946E_TCM_SIZE_64K  (0x7L) // (b0111)
#define ARM946E_TCM_SIZE_128K (0x8L) // (b1000)
#define ARM946E_TCM_SIZE_256K (0x9L) // (b1001)
#define ARM946E_TCM_SIZE_512K (0xAL) // (b1010)
#define ARM946E_TCM_SIZE_1M   (0xBL) // (b1011)



// Cache masks
#define ARM946E_DATA_CACHE_SIZE_MASK (0x3C0000)
#define ARM946E_INST_CACHE_SIZE_MASK (0x3C0)




// Gernal control masks
#define ARM946E_CONTROL_REG_AND_MASK (0xFF0DF)
#define ARM946E_CONTROL_REG_OR_MASK  (0x78)
#define ARM946E_TCM_SZ_REG_AND_MASK  (0xf)

// General defines
#define REGION_BASE_REGISTER_OFFSET (12)
#define ITCM_SZ_REGISTER_OFFSET     (6)
#define DTCM_SZ_REGISTER_OFFSET     (18)


// Function prototypes

//General functions
UINT32 Arm946eCP15Read(UINT32 reg);
UINT32 Arm946eCP15Write(UINT32 value,UINT32 reg);

// Get...
UINT32 Arm946eCP15GetIDCodeReg(void);
UINT32 Arm946eCP15GetCacheTypeReg(void);
UINT32 Arm946eCP15GetDataCacheSize(void);
UINT32 Arm946eCP15GetInstructionCacheSize(void);
UINT32 Arm946eCP15GetTCMSizeReg(void);
UINT32 Arm946eCP15GetDataTCMSize(void);
UINT32 Arm946eCP15GetInstTCMSize(void);

UINT32 Arm946eCP15GetControlReg_DS(void);
UINT32 Arm946eCP15GetControlReg_TCS(void);
ETCMLoadMode Arm946eCP15GetInstTCMLoadMode(void);
UINT32 Arm946eCP15GetInstTCMEnable(void);
UINT32 Arm946eCP15GetDataTCMLoadMode(void);
UINT32 Arm946eCP15GetDataTCMEnable(void);
UINT32 Arm946eCP15GetInstCacheEnable(void);
#if defined (TTC_CORE_ARM946_CP15)
UINT32 Arm946eCP15GetBpuEnable(void);
#endif
UINT32 Arm946eCP15GetDataCacheEnable(void);
UINT32 Arm946eCP15GetAlternateVectorSelect(void);
UINT32 Arm946eCP15GetBigEndian(void);
UINT32 Arm946eCP15GetMPUEnalbe_DS(void);
UINT32 Arm946eCP15GetMPUEnalbe_TCS(void);

UINT32 Arm946eCP15GetRegionBaseAndSizeReg(EMpuRegionsId region);
UINT32 Arm946eCP15GetDataTCMRegionBaseAndSizeReg(void);
UINT32 Arm946eCP15GetInstTCMRegionBaseAndSizeReg(void);


// Set...
UINT32 Arm946eCP15SetControlReg(UINT32 value);
UINT32 Arm946eCP15SetInstTCMLoadMode(ETCMLoadMode loadMode);
UINT32 Arm946eCP15SetInstTCMEnable_DS(void);
UINT32 Arm946eCP15SetInstTCMEnable_TCS(void);

UINT32 Arm946eCP15SetInstTCMDisable(void);
UINT32 Arm946eCP15RestoreInstTCMEnable(ETCMMode oldITcmEnableMode);
UINT32 Arm946eCP15RestoreDataTCMEnable(ETCMMode oldITcmEnableMode);
UINT32 Arm946eCP15SetDataTCMLoadMode(ETCMLoadMode loadMode);
UINT32 Arm946eCP15SetDataTCMEnable_DS(void);
UINT32 Arm946eCP15SetDataTCMEnable_TCS(void);
UINT32 Arm946eCP15SetDataTCMDisable(void);
UINT32 Arm946eCP15SetInstCacheEnable_DS(void);
UINT32 Arm946eCP15SetInstCacheEnable_TCS(void);
UINT32 Arm946eCP15SetInstCacheDisable(void);
UINT32 Arm946eCP15SetDataCacheEnable_DS(void);
UINT32 Arm946eCP15SetDataCacheEnable_TCS(void);
UINT32 Arm946eCP15SetDataCacheDisable(void);
UINT32 Arm946eCP15SetAlternateVectorSelect(EVectorSelectMode vectorSelectMode);
UINT32 Arm946eCP15SetBigEndian(EEndianConfiguration endianMode);
UINT32 Arm946eCP15SetMPUEnalbe_DS(void);
UINT32 Arm946eCP15SetMPUEnalbe_TCS(void);

UINT32 Arm946eCP15SetMPUDisable_DS(void);
UINT32 Arm946eCP15SetMPUDisable_TCS(void);

UINT32 Arm946eCP15RestoreMPUEnableDisable_DS(UINT32 enableDisable);
UINT32 Arm946eCP15RestoreMPUEnableDisable_TCS(UINT32 enableDisable);
UINT32 Arm946eCP15SetRegionAccessPermission_DS(EMpuRegionsId region,CMpuRegionAttributes attribute);
UINT32 Arm946eCP15SetRegionAccessPermission_TCS(EMpuRegionsId region,CMpuRegionAttributes attribute);

UINT32 Arm946eCP15SetRegionBaseAndSizeReg_DS(EMpuRegionsId region,UINT32 baseAddress,UINT32 regionSize,EMpuRegionMode regionEnableDisable);
UINT32 Arm946eCP15SetRegionBaseAndSizeReg_TCS(EMpuRegionsId region,UINT32 baseAddress,UINT32 regionSize,EMpuRegionMode regionEnableDisable);

UINT32 Arm946eCP15FlushInstCache(void);
UINT32 Arm946eCP15FlushDataCache(void);
UINT32 Arm946eCP15DrainWriteBuffer(void);
UINT32 Arm946eCP15SetLowPowerState(void);
UINT32 Arm946eCP15SetDataTCMRegionBaseAndSizeReg_DS(UINT32 areaSize,UINT32 regionBase);
UINT32 Arm946eCP15SetDataTCMRegionBaseAndSizeReg_TCS(UINT32 areaSize,UINT32 regionBase);
UINT32 Arm946eCP15SetInstTCMRegionBaseAndSizeReg_DS(UINT32 areaSize,UINT32 regionBase);
UINT32 Arm946eCP15SetInstTCMRegionBaseAndSizeReg_TCS(UINT32 areaSize,UINT32 regionBase);

UINT32 Arm946eCP15DCacheLineInvalidReg(UINT32 Addr);

UINT32 asm_Arm9ReadCP15_DS  (UINT32 add_r0);
UINT32 asm_Arm9ReadCP15_TCS (UINT32 add_r0);

UINT32 asm_Arm9WriteCP15_DS (UINT32 val_r0 ,UINT32 add_r1);
UINT32 asm_Arm9WriteCP15_TCS(UINT32 val_r0 ,UINT32 add_r1);

#if defined (TTC_CORE_ARM946_CP15)
UINT32 Arm946eCP15GetBpuEnable(void);
UINT32 Arm946eCP15SetBpuEnable(void);
UINT32 Arm946eCP15SetBpuDisable(void);
UINT32 asm_arm946e_InvalidateInsCacheFlushBPU(void);
UINT32 asm_arm946e_FlushDCache(void);
UINT32 asm_arm946e_DrainBuffers(void);
UINT32 asm_arm946e_WaitForInterruptLowPower(void);
void Arm946eCP15FlushCleanDcacheIcache(void);
UINT32 asm_arm946e_ReadIDCode(void);
UINT32 asm_arm946e_ReadCacheType(void);
UINT32 asm_arm946e_ReadTCMSize(void);
void asm_arm946e_CleanInvalidateDCacheAll(void);
#endif
void InvalidateDataCache(UINT32 address, UINT32 size);

#endif //ARM946E_SCP15_H
