/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*================================================================================================
File        : osa_mem.h
Description : OSA structures definitions
---------------------------------------------------------------------*/

#ifndef OSA_MEM_H
#define OSA_MEM_H


/*
 * Includes
 */
#include <stdio.h>
#include "osa.h"

/*
 * Constants
 */

#if defined(OSA_NUCLEUS)
#include "csw_mem.h"
#define     INVALIDATE_MEMORY(PmEM,sIZE)    CacheInvalidateMemoryNoClean((void *)(PmEM),(sIZE))
#define     INVALIDATE_LINE(PmEM)           INVALIDATE_MEMORY((PmEM),32)
#define     CLEAN_LINE(PmEM)                CacheCleanMemory((void *)(PmEM),32)
#else
#define     SIZEOF_CACHE_LINE               32
#define     CACHE_LINE_MASK                 (SIZEOF_CACHE_LINE - 1)
#define     INVALIDATE_MEMORY(PmEM,sIZE)
#endif

#define     FREE_MEM                        0x4D454D46
#define     FREE_MSK                        0x4B534D46
#define     MERG_MEM                        0x4D47454D

#define     BUF_HDR_GUARD                   2
#define     MAX_NAME_LENGTH                 20
#define     GUARD_PATTERN                   0xDEADBEEF

#define     SIZEOF_MIN_BUF                  (SIZEOF_CACHE_LINE * 1)     //  Must be SIZEOF_CACHE_LINE * OddNumber
#define     LARGEST_BUF_WITH_SPECIAL_LIST   (SIZEOF_MIN_BUF * 64)       //  Must be SIZEOF_MIN_BUF * n
#define     NUMBER_OF_FREE_LISTS            (1 + (LARGEST_BUF_WITH_SPECIAL_LIST / SIZEOF_MIN_BUF))

#define     LAST_FREE_LIST(PpOOLhEADER)     (&PpOOLhEADER->FreeList[NUMBER_OF_FREE_LISTS - 1])

/*
 * Task ID magic
 */

#define     INIT_TASK_TD                    0x74696E49
#define     CI_SERVER_INIT_TASK_ID          0x54495343

/*
 * Data Types
 */

typedef struct MemBufTag
{
    UINT32              Guard ;
    UINT32              ReqSize ;           //  This is used only for the DATA GUARD CHECK otherwise it can be added to the Header Guard.
    UINT32              UserParam ;         //  Free for the user to use.
    OsaRefT             poolRef ;
    struct MemBufTag    *pPrevBuf ;         //  The buf that is physicaly befor this buf - not prev free.
    UINT32              AllocCount ;
    UINT32              BufSize ;
	UINT32              callerAddress ;		//Saves the caller address
    struct MemBufTag    *pNextFreeBuf ;     //  Next buf on free list. This is also the first address of the allocated buffer.
} OsaMem_BufHdr ;

typedef struct MemBlkHdrTag
{
    UINT32                  FirstAddress ;
    UINT32                  LastAddress ;
    struct MemBlkHdrTag     *pNextMemBlk ;
} OsaMem_MemBlkHdr ;


typedef struct FreeListTag
{
    struct FreeListTag  *pNextList ;
    OsaMem_BufHdr       *pFirstBuf ;
    UINT32              TotalAllocReq ;     //  Total Alloc request on this memory size.
    UINT32              TotalFreeReq ;      //  Total Free  request on this memory size.
    UINT32              MaxAllocBuf ;       //  Maximum allocated buffers at the same time = max(TotalAllocReq-TotalFreeReq).
    UINT32              nFreeBuf ;          //  Number of free buffers on this list.
    UINT32              maxFreeBuf ;        //  Maximum number of free buffers on this list.
} OsaMem_FreeList ;


typedef struct PoolHeaderTag
{
    UINT32                      PoolID ;        //  Uswd for the ICAT EXPORTED FUNCTIONs
    OsaRefT                     CriticalSectionHandle ;
    OsaMem_FreeList             FreeList[NUMBER_OF_FREE_LISTS] ;
    OsaMem_MemBlkHdr            *pFirstMemBlk ;
    struct PoolHeaderTag        *pNextPool ;
    UINT32                      poolSize ;
    UINT32                      BytesInUse ;
    UINT32                      MaxBytesInUse ;
    UINT32                      BytesAllocated ;
    UINT32                      MaxBytesAllocated ;
    UINT32                      LowWaterMark ;
    void                        (*LowWaterMarkCbFunc)(UINT32) ;
    char                        poolName[MAX_NAME_LENGTH] ;
} OsaMem_PoolHeader ;

#define     SIZEOF_HDR_OF_ALLOC_BUF         (offsetof(OsaMem_BufHdr,pNextFreeBuf))
#define     ALLOC_BUF_ADRS(PbUFhDR)         ((void *)((UINT32)(PbUFhDR) + SIZEOF_HDR_OF_ALLOC_BUF))
#define     NEXT_BUF_ADRS(PbUFhDR)          ((OsaMem_BufHdr *)((UINT32)ALLOC_BUF_ADRS(PbUFhDR) + PbUFhDR->BufSize))

/*
 * Functions prototypes
 */

void OsaMemSetUserParamsFast( void *pMem, UINT32 UserParam, UINT32 CallerAddress  );
UINT32 OsaGetMemPoolFreeSize(OSPoolRef poolRef);
UINT32 getOsaMemPoolsUsage(OSPoolRef poolRef, BOOL logEnale);
UINT32 OsaGetDefaultMemPoolTotalSize(void);
UINT32 OsaGetDefaultMemPoolFreeSize(void);
UINT32 OsaGetPoolFreeRate(void);
void OsaMemPoolsCheckValidity( void );

#endif //OSA_MEM_H
