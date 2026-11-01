/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2001
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Package: MMU
###
###  Module: Mmu.h - API definitions for MMU package
###
###  $Archive: /MMU/INC/Mmu_api.h $
###  $Revision: 80 $
###  $Date: 8/01/02
###  $Author: Irit Studniberg
###  $NoKeywords $
###########################################################################*/

#ifndef _MMU_H
#define _MMU_H

#include "gbl_types.h"

// Define MMU attributes (can be or-combined)
// Please, do not alter the values
#define MMU_ATT_CACHEABLE                   0x0002
#define MMU_ATT_BUFFERABLE                  0x0001

#define MMU_ATT_CACH_BUFFER_WTHROUGH        MMU_ATT_CACHEABLE
#define MMU_ATT_NO_CACH_BUFFER              MMU_ATT_BUFFERABLE
#define MMU_ATT_CACHE_COPYBACK             (MMU_ATT_CACHEABLE|MMU_ATT_BUFFERABLE)
#define MMU_ATT_NO_CACH_NO_BUFFER           0x0000
#define MMU_ATT_X_BIT                       0x0010

#define MMU_ATT_WRITE_PERMISSION            0x0008
#define MMU_ATT_READ_PERMISSION             0x0004
#define MMU_ATT_READ_WRITE_PERMISSION       0x000C
#define MMU_ATT_NOACCESS                    0x0020

#define MMU_ATT_DEFAULT (MMU_ATT_C | MMU_ATT_B)
#define MMU_ATT_IO      0               // C=0, B=0

// Size constants
#define _1KB                                    (0x400)
#define _4KB                                    (0x1000)
#define _16KB                                   (0x4000)
#define _32KB                                   (0x8000)
#define _64KB                                   (0x10000)
#define _128KB                                  (0x20000)
#define _256KB                                  (0x40000)
#define _512KB                                  (0x80000)


#define _1MB                                    (0x00100000)
#define _2MB                                    (0x00200000)
#define _3MB                                    (0x00300000)
#define _4MB                                    (0x00400000)
#define _8MB                                    (0x00800000)
#define _16MB                                   (0x01000000)
#define _32MB                                   (0x02000000)
#define _48MB									(0x03000000)
#define _56MB									(0x03800000)
#define _64MB                                   (0x04000000)
#define _128MB                                  (0x08000000)
#define _256MB                                  (0x10000000)
#define _512MB                                  (0x20000000)
#define _1GB                                    (0x40000000)

#define CACHELINESIZE          (0x20)

typedef struct
{
 UINT16 ic;      // I-Cache size (bytes)
 UINT16 dc;      // D-Cache size (bytes)
 UINT16 minidc;  // Mini D-Cache size (bytes)
}MMU_CacheSize;


typedef UINT32 Attribs_Mmu;

typedef enum
{
    MMU_ENABLE,
    MMU_DISABLE
} MMU_STATUS;

typedef enum
 {
    MMU_RC_OK,
    MMU_RC_ERROR,
    MMU_RC_MAPPING_ERROR,
	MMU_RC_WRONG_ALIGNMENT,
	MMU_RC_NOFREETABLE,
    MMU_RC_VIRTUAL_ADDRESS_EXIST
 }  MMU_ReturnCode;


typedef enum
 {
  SECTION,
  PAGE64K,
  PAGE4K,
  PAGE1K
 }MEM_type;

typedef enum
 {
  _DOMAIN_0,
  _DOMAIN_1,
  _DOMAIN_2,
  _DOMAIN_3,
  _DOMAIN_4,
  _DOMAIN_5,
  _DOMAIN_6,
  _DOMAIN_7,
  _DOMAIN_8,
  _DOMAIN_9,
  _DOMAIN_10,
  _DOMAIN_11,
  _DOMAIN_12,
  _DOMAIN_13,
  _DOMAIN_14,
  _DOMAIN_15
 }_DOMAIN;

typedef enum
{
	MMU_VECTORS_LOW,
	MMU_VECTORS_HIGH
} MMU_VECTORS_LOCATION;

typedef struct
{
    UINT32          Domain_access_control;
    BOOL            MMU_status;
	BOOL            DCache_status;
	BOOL            ICache_status;
    BOOL            Alignment_status;
    BOOL            S_status;
    BOOL            R_status;
    BOOL            Write_Buffer_Coalescing;
    BOOL            BTB_status;
    BOOL            MiniDC_WriteBack;
    BOOL            MiniDC_WriteAllocate;
}MMU_CONFIGURE;

#define MMU_DOMAIN_ACCESS_CHECK_PERMISSIONS 0x55555555 //all domains
#define MMU_DOMAIN_ACCESS_NO_PERMISSIONS    0xFFFFFFFF //all domains

// Minimal of 17KB space is required for MMU data and the primary table (allows 1MB resolution only)
// More space allows page mapping (4KB and 64KB resolution) with cost of 1K table space per 1MB of virtual address space
#define MMU_MIN_TABLE_SPACE 0x4400

typedef struct
{
  UINT32    Error_address;
  UINT16    Error_reason;
  UINT8     Domain;
}MMU_ERROR_STATUS;

typedef void (* mmuNotifyEventFunc)(MMU_ERROR_STATUS mmuErrorHandle);


//
// System level services
//
// MMU
MMU_ReturnCode  mmuInit(UINT32 mmuTablesSpace,UINT32 mmuTableSpaceSize, const MMU_CONFIGURE*  configuration );
UINT32          mmuGetTableAreaSize(void);
MMU_ReturnCode  mmuEnable(void);
MMU_ReturnCode  mmuDisable(void);
MMU_ReturnCode  mmuConfigure (const MMU_CONFIGURE* configure);
MMU_ReturnCode  mmuConfigurationGet (MMU_CONFIGURE* configure);
UINT32          mmuDomainAccessControlGet(void);
void            mmuDomainAccessControlSet(UINT32 value);
UINT32          mmuProtectionDisable(void);
void            mmuProtectionRestore(UINT32 value);

void            mmuSetVectorsLocation(MMU_VECTORS_LOCATION vLoc);

// Query the actual cache size
const MMU_CacheSize* mmuCacheSizeGet(void);


// D-cache
MMU_ReturnCode  mmuDataCacheEnable(void);
MMU_ReturnCode  mmuDataCacheDisable(void);
MMU_ReturnCode  mmuFullDataCacheInvalidate  (void);
#define mmuFullDataCacheFlash mmuFullDataCacheClean
#if defined (L2_CACHE_ENABLE)&& defined(CREATE_L2_RAM)
#define mmuFullDataCacheClean DCacheGloballyClean
#endif		//(L2_CACHE_ENABLE)&&(CREATE_L2_RAM)
MMU_ReturnCode  mmuFullDataCacheClean(void);
MMU_ReturnCode  mmuFullDataCacheUnLock (void);
#define mmuDataCacheUnLock mmuFullDataCacheUnLock

// I-cache
MMU_ReturnCode  mmuInstructionCacheEnable(void);
MMU_ReturnCode  mmuInstructionCacheDisable(void);
MMU_ReturnCode  mmuFullInstructionCacheUnLock (void);
MMU_ReturnCode  mmuFullInstructionCacheInvalidate  (void);

//
// Other actions
//
MMU_ReturnCode  mmuBTBInvalidate(void);
MMU_ReturnCode  mmuDrainBuffers(void);

//
// Cache services (per virtual address, 1 cache line resolution)
//

// D-cache
MMU_ReturnCode  mmuDataCacheClean (UINT32 address, UINT32 size);
#define mmuDataCacheFlash mmuDataCacheClean
MMU_ReturnCode  mmuDataCacheInvalidate (UINT32 address, UINT32 size);
// For misaligned cases: flushes cache-lines that partly belong to the given area
MMU_ReturnCode  mmuDataCacheInvalidateSafe(UINT32 p, UINT32 size);
MMU_ReturnCode  mmuDataCacheCleanInvalidate (UINT32 address, UINT32 size);
MMU_ReturnCode  mmuDataCacheLock (UINT32 address, UINT32 size);

// I-cache
MMU_ReturnCode  mmuInstructionCacheInvalidate (UINT32 address, UINT32 size);
MMU_ReturnCode  mmuInstructionCacheLock (UINT32 address, UINT32 size);

//
// Mapping and address translation services
//

int             mmuMap(UINT32 virt, UINT32 ph, UINT32 sz, Attribs_Mmu att);
MMU_ReturnCode  mmuMemoryMapping (UINT32 mmu_virtualAddress, UINT32 mmu_physicalAddress, UINT32 mmu_size, MEM_type mmu_MemType, Attribs_Mmu attributes,_DOMAIN domain);
MMU_ReturnCode  mmuMemoryMappingAutoExt (UINT32 virtualAddress, UINT32 physicalAddress, UINT32 size, Attribs_Mmu attributes,_DOMAIN domain);
#define mmuMemoryMappingAuto(v,p,s,a) mmuMemoryMappingAutoExt(v,p,s,a,_DOMAIN_15) //default domain is set
//
// Address translation services
//
UINT32          mmuVirtualToPhysicalTranslate(UINT32 VirtualAddress);
UINT32          mmuPhysicalToVirtualTranslate(UINT32 PhysicalAddress);
//alias
void* VirtualToPhysical(void* inAddress);

#endif // _MMU_H















