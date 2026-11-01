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

#ifndef     CSW_MEM
#define     CSW_MEM

#include    <stdlib.h>      //  malloc, free, calloc
#include "global_types.h"
#include "osa.h"
#include "sig_mem.h"


#if !defined(CSW_MEM_C)
extern const
#endif
OsaRefT
    ExternalMemoryDynamicPool,
    InternalMemoryDynamicPool ;


#define     SHMEM_POOL      "ShmemPool"

/*
 * Pool Init Functions
 */
UINT32 dtcmHeapInit( UINT32 start, UINT32 end ) ;
UINT32 extMemHeapInit( UINT32 start, UINT32 end, BOOL DefaultPool ) ;
UINT32 intMemHeapInit( UINT32 start, UINT32 end, BOOL DefaultPool ) ;
void   memPoolX_Init ( UINT32 size,  void* poolAddr ) ;

/*
 * Malloc Functions
 */
void        *alignMallocPoolX( UINT32 Size ) ;
void        *alignMalloc( UINT32 Size ) ;
void        *mallocExt( size_t Size );


    void        *malloc_shell( OsaRefT PoolRef, UINT32 Size ) ;

    #define     Malloc(sIZE)                    malloc_shell(NULL,sIZE)

    #define     BlockingMalloc                  Malloc
    #define     sysAlloc                        Malloc

    #define     extMemDynMalloc(sIZE)           malloc_shell(ExternalMemoryDynamicPool,sIZE)
    #define     intMemDynMalloc(sIZE)           malloc_shell(InternalMemoryDynamicPool,sIZE)

#if defined(FLAVOR_APP)
    #define     ShmemAlloc                      alignMallocPoolX
#else
    #define     ShmemAlloc                      alignMalloc
#endif

/*
 * Calloc Functions
 */

void        *calloc_shell( OsaRefT PoolRef, UINT32 nItems, UINT32 itemSize ) ;

#define     Calloc(NiTEMS,IsIZE)            calloc_shelll(NULL,NiTEMS,IsIZE)
#define     alignCalloc                     Calloc

#define     extMemDynCalloc(NiTEMS,IsIZE)   calloc_shelll(ExternalMemoryDynamicPool,NiTEMS,IsIZE)
#define     intMemDynCalloc(NiTEMS,IsIZE)   calloc_shelll(InternalMemoryDynamicPool,NiTEMS,IsIZE)

/*
 * Free Functions
 */

    #define     Free                        OsaMemFree

    #define     alignFreePoolX              Free
    #define     alignFree                   Free
    #define     dynFree                     Free
    #define     sysFree                     Free

#if defined(FLAVOR_APP)
    #define     ShmemFree                       alignMallocPoolX
#else
    #define     ShmemFree                       alignFree
#endif

/*
 * romHeapInit, romAlloc & romFree function were in csw_memory\src\heaps.c but romHeapInit is never called
 * and the remarks say that it is defeatured.
 * The romAlloc & romFree are used in a special L1 build in aplp_etc\dlm\samples\trace\tracepoint.c
 */
#define     romAlloc(sIZE)          NULL
#define     romFree(pTR)


/*
 * Cache Handling
 */
#define     ALIGN_MALLOC_BYTES      32
#define     ALIGN_MALLOC_MASK       (ALIGN_MALLOC_BYTES-1)

#define     SIZEOF_CACHE_LINE       32
#define     CACHE_LINE_MASK         (SIZEOF_CACHE_LINE-1)

BOOL SysIsAssert(void);
void  memInvalidate( void *pMem );
void  memClean( void *pMem );
void CleanDataCache(UINT32 address, UINT32 size);

void  CacheCleanMemory             ( void *pMem ,UINT32 size);
void  CacheInvalidateMemory        ( void *pMem, UINT32 size);
void InvalidateDataCache(UINT32 address, UINT32 size);
void  CacheInvalidateMemoryNoClean ( void *pMem, UINT32 size);
void  CacheCleanAndInvalidateMemory( void *pMem ,UINT32 size);
#if defined(ENABLE_TVRTD_MULTICARRIER_DTC)
void  KiCacheCleanMemory             ( void *pMem ,UINT32 size);
void  KiCacheInvalidateMemory        ( void *pMem, UINT32 size);
#endif

#ifdef PROJ_ASR_APP_001
void *MmiMalloc(UINT32 size, BOOL trigAss);
OsaRefT GetMMIPool( void );
#endif

#endif
