/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*******************************************************************
 *
 *
 *    HISTORY:
 *		YK 21 March 2007	duplicated APIs to reside on both DDR (for init) and TCM (for D2 exit)
 *      SE 05 Decemeber 2007 TTC modifications
 * NOTE:
 *  APIs with _DS _TCS mean they are duplicated twice, to run at init from DDR
 *	and to run from TCM on D2 exit. The source files are duplicated in CC and controlled
 *	by compilation switch and MACROS of FUNCNAME_CTRL, TABLENAME_CTRL
 *
 **********************************************************************************/
#ifndef __ARM496E_MPU_H__
#define __ARM496E_MPU_H__

#include "arm946e_config.h"
#include "global_types.h"

// Access permission encoding
#define ARM946E_MPU_ATT_SUP_NO_ACCESS_USR_NO_ACCESS (0x0L) // (b0000)
#define ARM946E_MPU_ATT_SUP_RW_USR_NO_ACCESS        (0x1L) // (b0001)
#define ARM946E_MPU_ATT_SUP_RW_USR_R                (0x2L) // (b0010)
#define ARM946E_MPU_ATT_SUP_RW_USR_RW               (0x3L) // (b0011)
#define ARM946E_MPU_ATT_SUP_R_USR_NO_ACCESS         (0x5L) // (b0101)
#define ARM946E_MPU_ATT_SUP_R_USR_R                 (0x6L) // (b0110)

// Instruction & data access permission masks
#define ARM946E_MPU_AP_MASK	 (0x0000000F)
#define ARM946E_MPU_AP0_MASK (0xFFFFFFF0)
#define ARM946E_MPU_AP1_MASK (0xFFFFFF0F)
#define ARM946E_MPU_AP2_MASK (0xFFFFF0FF)
#define ARM946E_MPU_AP3_MASK (0xFFFF0FFF)
#define ARM946E_MPU_AP4_MASK (0xFFF0FFFF)
#define ARM946E_MPU_AP5_MASK (0xFF0FFFFF)
#define ARM946E_MPU_AP6_MASK (0xF0FFFFFF)
#define ARM946E_MPU_AP7_MASK (0x0FFFFFFF)

// Region size encoding
#define ARM946E_MPU_REGION_SIZE_4K   (0xBL)  // (b01011)
#define ARM946E_MPU_REGION_SIZE_8K   (0xCL)  // (b01100)
#define ARM946E_MPU_REGION_SIZE_16K  (0xDL)  // (b01101)
#define ARM946E_MPU_REGION_SIZE_32K  (0xEL)  // (b01110)
#define ARM946E_MPU_REGION_SIZE_64K  (0xFL)  // (b01111)
#define ARM946E_MPU_REGION_SIZE_128K (0x10L) // (b10000)
#define ARM946E_MPU_REGION_SIZE_256K (0x11L) // (b10001)
#define ARM946E_MPU_REGION_SIZE_512K (0x12L) // (b10010)
#define ARM946E_MPU_REGION_SIZE_1M   (0x13L) // (b10011)
#define ARM946E_MPU_REGION_SIZE_2M   (0x14L) // (b10100)
#define ARM946E_MPU_REGION_SIZE_4M   (0x15L) // (b10101)
#define ARM946E_MPU_REGION_SIZE_8M   (0x16L) // (b10110)
#define ARM946E_MPU_REGION_SIZE_16M  (0x17L) // (b10111)
#define ARM946E_MPU_REGION_SIZE_32M  (0x18L) // (b11000)
#define ARM946E_MPU_REGION_SIZE_64M  (0x19L) // (b11001)
#define ARM946E_MPU_REGION_SIZE_128M (0x1AL) // (b11010)
#define ARM946E_MPU_REGION_SIZE_256M (0x1BL) // (b11011)
#define ARM946E_MPU_REGION_SIZE_512M (0x1CL) // (b11100)
#define ARM946E_MPU_REGION_SIZE_1G   (0x1DL) // (b11101)
#define ARM946E_MPU_REGION_SIZE_2G   (0x1EL) // (b11110)
#define ARM946E_MPU_REGION_SIZE_4G   (0x1FL) // (b11111)

typedef struct{
	U32Bits iattributs;
	U32Bits dattributs;
}CMpuRegionAttributes;

// General definitions
typedef enum{
 ARM946E_MPU_NO_REGION =-1,
 ARM946E_MPU_REGION_0 = 0,
 ARM946E_MPU_REGION_1,
 ARM946E_MPU_REGION_2,
 ARM946E_MPU_REGION_3,
 ARM946E_MPU_REGION_4,
 ARM946E_MPU_REGION_5,
 ARM946E_MPU_REGION_6,
 ARM946E_MPU_REGION_7,
 ARM946E_MPU_REGIONS_NUM
}EMpuRegionsId;



typedef enum{
	ARM946E_MPU_REGION_DISABLE,
	ARM946E_MPU_REGION_ENABLE
}EMpuRegionMode;




typedef struct{
	EMpuRegionsId regionId;
	UINT32 baseAddress;
	UINT32 regionSize;
	BOOL   isICachable;
	BOOL   isDCachable;
	BOOL   isBufferable;
	CMpuRegionAttributes attributes;
	EMpuRegionMode regionEnableDisable;
}Arm946eMpuMemoryRegion;

#if defined (TTC_CORE_ARM946_CP15)
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_DS[ARM946E_MPU_REGIONS_NUM];
#else
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_UpRO_DS[ARM946E_MPU_REGIONS_NUM];
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_10MB_DS[ARM946E_MPU_REGIONS_NUM];
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_12MB_DS[ARM946E_MPU_REGIONS_NUM];

extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_UpRO_TCS[ARM946E_MPU_REGIONS_NUM];
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_10MB_TCS[ARM946E_MPU_REGIONS_NUM];
extern const Arm946eMpuMemoryRegion _arm946eMpuRegions_12MB_TCS[ARM946E_MPU_REGIONS_NUM];
#endif

#if defined (TTC_CORE_ARM946_CP15)
/*added to keep current common API for Tavor & TTC*/
#define   Arm946MpuInitRegion_TCS Arm946MpuInitRegion_DS
#define   Arm946eMpuInit_TCS   Arm946eMpuInit_DS
#define   EnableITCM_TCS       EnableITCM_DS
#endif

// functions prototypes
void Arm946MpuRegionsDelete(void);
void Arm946eMpuInit_DS(BOOL bEnableMpu);
void Arm946eMpuInit_TCS(BOOL bEnableMpu);
void Arm946eMpuLoadToITCM(UINT32 srcAddress,UINT32 destAddress,UINT32 length);
void Arm946eMpuLoadToDTCM(UINT32 srcAddress,UINT32 destAddress,UINT32 length);
void EnableITCM_DS(UINT32  ARM946E_TCM_SIZE_code);
void EnableITCM_TCS(UINT32  ARM946E_TCM_SIZE_code);
void Arm946eMpuITCMRegion_Init(void);
void Arm946eSetRegionBufferedAttr(EMpuRegionsId regionId,BOOL enable);
// function declaration to delegate between the regular and memRetain modules
extern void Arm946MpuInitRegion_DS(const Arm946eMpuMemoryRegion * region);
extern void Arm946MpuInitRegion_TCS(const Arm946eMpuMemoryRegion * region);
extern void Arm946eMpuSetITCMRegionAttributs(CMpuRegionAttributes newAttributs );

//#define MSA_L2_SRAM_BASE_ADDR    0xD1E00000
//#define MSA_ARM_SHARED_BASE_ADDR 0xD1E00000
//#define AHB_SRAM_BASE_ADDR       0xCFD00000
//#define APB_DEVICES_BASE_ADDR    0xD4000000
//#define GB_SYS_MMR_BASE_ADDR	 0xFFD00000

#define ITCM_BASE_ADDR           0x00000000 // Shaul - should be removed from here. Should use arbel.h

//Refer also DDR_NONCACHE_REGION in scatter file and correct region size in SMPU
//Refer also preprocessor's define DDR_RO_SIZE in scatter file.
//Refer also preprocessor's define HARBELL_DDR_BASE_ADDR in scatter file.
#if !defined (TTC_CORE_ARM946_CP15)
#define HARBELL_DDR_BASE_ADDR  ((UINT32)(&Load$$LOAD_TABLE$$Base))
extern                           UINT32   Load$$LOAD_TABLE$$Base;

#define DDR_NON_CACH_BASE_ADDR ((UINT32)(&Image$$DDR_NONCACHE_REGION$$Base))
extern                           UINT32   Image$$DDR_NONCACHE_REGION$$Base;
#endif

#if defined (TTC_CORE_ARM946_CP15)
#define MPU_ITCM_REGION                ARM946E_MPU_REGION_0
#define MPU_ITCM_REGION_TABLE_IDX      MPU_ITCM_REGION

#define MPU_DTCM_REGION                ARM946E_MPU_REGION_1
#define MPU_DTCM_REGION_TABLE_IDX      MPU_DTCM_REGION

#define MPU_MSA_SRAM_REGION            ARM946E_MPU_REGION_5

 // is TTC_CORE_ARM946_CP15
#else
 // not TTC_CORE_ARM946_CP15

#define MPU_ITCM_REGION                ARM946E_MPU_REGION_6
#define MPU_ITCM_REGION_TABLE_IDX      MPU_ITCM_REGION

#define MPU_DTCM_REGION                ARM946E_MPU_REGION_0
#define MPU_DTCM_REGION_TABLE_IDX      MPU_DTCM_REGION

#endif//TTC_CORE_ARM946_CP15

#endif //__ARM496E_MPU_H__

