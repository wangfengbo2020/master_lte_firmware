/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2001
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: BSP
###
###  Module: MMAP.H - This module consists of  memory map configuration definitions

###
###########################################################################*/

#ifndef _MMAP_H_
#define _MMAP_H_

#include "gbl_types.h"
#include "mmu.h"
#include "bsp.h"
#include "loadTable.h"       // for ADDR_CONVERT definition

extern UINT32 Image$$EXT_RAM_FIRST$$Base;

/****************************************************************************************
* Non FULL_SYSTEM (PLATFORM_ONLY for example) Target by default has reduced memory mapping
* But it may be forced to INT+EXT upon Target Variant request
* In that case the MMAP_EXTENDED_INT_EXT_RAM_FLASH may be already defined in makefile
******/
#if defined(FULL_SYSTEM) && !defined(MMAP_EXTENDED_INT_EXT_RAM_FLASH)
#define MMAP_EXTENDED_INT_EXT_RAM_FLASH
#endif

// VIRTUAL MEMORY MAP: SHOULD BE ALIGNED WITH THE LINK CONTROL FILE
//=== ALLOC management ===
#if !defined (MMAP_EXTENDED_INT_EXT_RAM_FLASH) && !defined(_TAVOR_BOERNE_)
  // !FULL_SYSTEM is PLATFORM-Only
#define MALLOC_ORDER_IS_INT2EXT
#endif

#if defined(_FDI_VER_71_) /*FDI7 small chunks workaround, but FDI5 doesn't need them */
#define CSW_MEM_SMALL_PARTITION_COUNT   1500   /*Number of chunks*/
//#define FDI_USES_STATIC_RAM_POOL             /* Another possibility */
#else
#define CSW_MEM_SMALL_PARTITION_COUNT      0   /*Don't use chunks*/
#endif

// Top area of internal flash reserved (for MSA), affects FDI partition location
//#define INT_FLASH_RESERVED_SIZE 0x10000

//-----------------------------------------------------------------------------------------------------------------------------
#if defined(INTEL_2CHIP_PLAT_BVD) || defined(_TAVOR_BOERNE_)
  #if !defined (NO_INT_FLASH_USAGE)
    #define NO_INT_FLASH_USAGE
  #endif
#endif

#if defined (NO_INT_FLASH_USAGE)
     // no INT-flash
#else//BVD
 #if !defined (MMAP_EXTENDED_INT_EXT_RAM_FLASH)
   #define FDI_INTERNAL_FLASH
 #else
   #if (  defined(HERMON_MCP2_CFG) ||  defined(INTEL_2CHIP_PLAT) )
   #define FDI_INTERNAL_FLASH
   #endif
 #endif
#endif//BVD

#if defined(_FDI_VER_71_INT_)
	#define FDI_INTERNAL_FLASH
#endif

// Size of FDI partition
// This MUST be a compile-time constant
#if !defined(FDI_INTERNAL_FLASH)
  #if defined (MMAP_EXTENDED_INT_EXT_RAM_FLASH) && !(defined(INTEL_2CHIP_PLAT_BVD) || defined(_TAVOR_BOERNE_))
#define FDI_PARTITION_SIZE                      0x00800000
  #else
#define FDI_PARTITION_SIZE                      0x00100000
  #endif
#else
#define FDI_PARTITION_SIZE                      0x00030000
#endif

// Size of Application Code + RO data
#define APP_CODE_SIZE                           (_4MB - FDI_PARTITION_SIZE) /*bspGetProgramRomSize()*/

// FDI partition offset from CS start (physical space)
#define FDI_PARTITION_BASE_PH_OFFSET            (APP_CODE_SIZE)

// Start address of FDI partition - virtual address (same for all configurations)
#if (!defined(_FDI_VER_71_) && !defined(DATALIGHT))
	#define FDI_PARTITION_BASE_ADDRESS              (_64MB -_16MB)
#else //for FDI71 or 2Chip Bulverde
	#define FDI_PARTITION_BASE_ADDRESS              (CACHED_TO_NON_CACHED_OFFSET)
#endif //_FDI_VER_71
//-----------------------------------------------------------------------------------------------------------------------------
// Disable cache for the QuickTurn:
#ifdef _QT_
//#define DISABLE_DCACHE
#endif

///////////////////////////////////////////////////////////////////////////////
//   Virtual address space for non-cacheable areas - mainly for DMA use
///////////////////////////////////////////////////////////////////////////////
#if !defined(SILICON_PV2) && !defined(SILICON_TTC_CORE_SEAGULL)
#if defined(PHS_SW_DEMO_TTC)
#define CACHED_TO_NON_CACHED_OFFSET 0x00000000
#else
#define CACHED_TO_NON_CACHED_OFFSET 0x20000000
#endif
#else
#define CACHED_TO_NON_CACHED_OFFSET 0x00000000
#endif

// since there is an address space shared by Harbell & Boerne (seen by Boerne as 0xD... or by Harbel as 0xBF...)
#if defined (_TAVOR_BOERNE_)
#if defined(PHS_SW_DEMO_TTC)
    #define CACHED_TO_NON_CACHED(cACHED)    ((void *)(((UINT32)(cACHED)) | (UINT32)CACHED_TO_NON_CACHED_OFFSET))
    #define NON_CACHED_TO_CACHED(nON_CACHED)  ((void *)(((UINT32)(nON_CACHED)) & (~(UINT32)CACHED_TO_NON_CACHED_OFFSET)))
#else
    #define CACHED_TO_NON_CACHED(cACHED)    ((void *)(((UINT32)cACHED >= (0xD0000000)) ? ((UINT32)ADDR_CONVERT(cACHED)) \
                                                    : ((((UINT32)(cACHED)) | (UINT32)CACHED_TO_NON_CACHED_OFFSET))))
    #define NON_CACHED_TO_CACHED(nON_CACHED)  ((void *)(((UINT32)nON_CACHED < 0xD0000000 && (UINT32)nON_CACHED > 0xBF000000) \
                                                    ? ((UINT32)nON_CACHED + 0x11000000) \
                                                    : ((((UINT32)(nON_CACHED)) & (~(UINT32)CACHED_TO_NON_CACHED_OFFSET)))))
#endif
#else
    #define CACHED_TO_NON_CACHED(cACHED)    ((void *)(((UINT32)(cACHED)) | (UINT32)CACHED_TO_NON_CACHED_OFFSET))
    #define NON_CACHED_TO_CACHED(nON_CACHED)  ((void *)(((UINT32)(nON_CACHED)) & (~(UINT32)CACHED_TO_NON_CACHED_OFFSET)))
#endif


// Re-define some public MMU-based services
void* VirtualToPhysical(void* inAddress);
void* PhysicalToVirtualCached(void* inAddress);
void* PhysicalToVirtualNonCached(void* inAddress);

// Other configuration switches

// IMPORTANT: it is strongly not recommended to run with MMU protection disabled.
// This allows the software to issue illegal accesses to the XSC Flash, e.g. 32-bit writes.
// The Gasket in this case rejects the access causing an imprecise abort to the XSC core,
// leaving caches corrupted, e.g. writing to 0+ area will leave the data written into the D-cache,
// which may result in incorrect abort exception handling and case debug problems.
#define ENABLE_PROTECTIONS

// This definition allows internal-only heap allocation on certain conditions

#if defined (MMAP_EXTENDED_INT_EXT_RAM_FLASH)
#define HEAP_MIN_SIZE (0x5a000)
#else
#define HEAP_MIN_SIZE (4*0x400)
#endif

// for B0: temp until we'll move to SDRAM - use SRAM
//#define USE_MB_SRAM

// For HSL on SDK
// When this define is used the SDK UART port has Rx/Tx only
// At the moment we have a problem using this as the PS configures the data port as a full UART
#define SDK_WITH_HSL
//-----------------------------------------------------------------------------------------------------------------------------
#if defined(_TAVOR_BOERNE_)
#define BSP_RAM_IMAGE
#define DDR_RO_BASE        DDR_EXEC_REGION
#define DDR_RO_SIZE        _4MB
#define DDR_RW_BASE        (DDR_RO_BASE+DDR_RO_SIZE)
#define DDR_RW_SIZE        (DDR_EXEC_REGION_SIZE-DDR_RO_SIZE)
#define EXCEPTION_VECTOR_PHY	(UINT32)(&Image$$EXT_RAM_FIRST$$Base)
#endif

#if defined(SILICON_TTC)
#define BSP_RAM_IMAGE
#define DDR_CP_AREA_SIZE   0x01000000
#define DDR_RO_BASE        (TTC_DDR_BASE+DDR_CP_AREA_SIZE)
#define DDR_RO_SIZE        _4MB
#define DDR_RW_BASE        (DDR_RO_BASE+DDR_RO_SIZE)
#define DDR_RW_SIZE        (_64MB-DDR_RO_SIZE-DDR_CP_AREA_SIZE)
#define EXCEPTION_VECTOR_PHY	(UINT32)(&Image$$EXT_RAM_FIRST$$Base)

#endif
//-----------------------------------------------------------------------------------------------------------------------------
#if defined(_HERMON_B0_SILICON_) && !defined(_TAVOR_BOERNE_)
// XIP model:
// - System starts running from flash and uses internal RAM only (these are mapped 1:1)
// - External memories (RAM and Flash) are/can be mapped to virtual addresses for abstraction (RAM type/address) reasons
// - or for optimization reasons (form one virtual areas containing both flashes)

#define BSP_SDRAM_AS_IMAGE_FLASH_SUPPORT
#define BSP_XIP_FLASH

// Main external RAM space: default occupies the CS4 (physical only) space.
//#define EXT_RAM_VIRTUAL   0x10000000 /*Occupy the physical address space of unused CS4 */

#ifndef EXT_FLASH_VIRTUAL
// NOTE: the address is chosen to make EXT_FLASH close enough to INT_FLASH.
// ARM branches (BL) are limited to +/-32MB offset. The linker generates long branch veneers for
// branches out of this range. The veneer cost is
// * 1 extra instruction (and ICache line fetch): LDR pc,[pc-4]       ;jump to the following address
// * D-cache line fetch, i.e. stall             : DCD target_address
#define EXT_FLASH_VIRTUAL _4MB
#endif
#ifndef EXT_ROM_SIZE
#define EXT_ROM_SIZE _32MB
#endif

#endif // Hermon - XIP
//-----------------------------------------------------------------------------------------------------------------------------
#endif //_MMAP_H_
