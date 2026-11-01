/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2001
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: TYPE.H - This module consists of definitions that the OEM needs
###                   to evaluate when porting to his/her system.
###
###  $Archive: /FDI/SRC/INCLUDE/fdi_type.h $
###  $Revision: 122 $
###  $Date: 10/18/04 10:10a $
###  $Author: Ljchang $
###  $NoKeywords $
########################################################################### */

/*
 *****************************************************************
 * NOTICE OF LICENSE AGREEMENT
 *
 * This code is provided by Intel Corp., and the use is governed
 * under the terms of a license agreement. See license agreement
 * for complete terms of license.
 *
 * YOU MAY ONLY USE THE SOFTWARE WITH INTEL FLASH PRODUCTS.  YOUR
 * USE OF THE SOFTWARE WITH ANY OTHER FLASH PRODUCTS IS EXPRESSLY
 * PROHIBITED UNLESS AND UNTIL YOU APPLY FOR, AND ARE GRANTED IN
 * INTEL'S SOLE DISCRETION, A SEPARATE WRITTEN SOFTWARE LICENSE
 * FROM INTEL LICENSING ANY SUCH USE.
 *****************************************************************
 */


#ifndef TYPE_H
#define TYPE_H
/*
 * The following is broken up into the following areas:
 * - Customer Platform/OS Definitions
 *        Place platform specific declarations here
 *        (OS "*.h" includes, test engine, and hardware
 *        I/O declarations).
 * - Platform configuration section
 *        Place OS, Test, and hardware configuration
 *        switches here.
 * - FDI Feature Switches section
 *        This is where major IFDI features are switched ON/OFF.
 * - FDI configuration section
 *        This is where major IFDI configuration is performed.
 * - Basic Data Type Definitions
 *        This is where fundamental data types in IFDI are declared.
 * - FDI abstraction typedefs and macros section
 *        This is where Platform abstraction macros are declared.
 *        In this section Platform declarations are combined to define
 *        how the platform abstraction macros for an implementation of IFDI.
 * - Debug section
 *        This section is where debug features are switched and configured.
 * - Globally used includes
 *        This is where include files used through out IFDI are placed.
 */

/*FDI 5.0 for CCDi SYS  start */
/*
 * This macro has to be define in order to enable Common FDI porting features !
 */
/*sys:currently I dont know customer need it or not,so add it here .July 29,2002*/
#define FDI_COMMON_PORTING

/*FDI 5.0 for CCDi SYS  end */

/*
 * ### Customer Platform/OS Definitions:
 * ############################################################################
 */
//#ifdef _HERMON_
#include <stdio.h>
//#endif // _HERMON_
#include "fdi_cfg.h"
#include "FDI_CUST.h"
#include "runvars.h" /* changes for Run-time variables */
/*FDI 5.0 for CCDi SYS  start */
#include "mmap.h"
#ifdef _FDI_USE_OSA_
#include "osa.h"
#else
#include "nucleus.h"
#endif //_FDI_USE_OSA_
#include "global_types.h"
#include "utils.h"
/*FDI 5.0 for CCDi SYS  end */

/*
 * ### Basic Data Type Definitions:
 * ############################################################################
 */

/*
 * These are what are used to create standard data types.  If these are
 * defined elsewhere, the three typedefs below can be removed.  When doing
 * so, is is imperative that the replacement definitions provide storage
 * of the same number of bits and same sign as the definitions below.
 */

/*
 * The following macro, BWD_TYPES, should initialy be undefined
 * for stand alone FDI and customer use if BYTE, WORD, and DWORD
 * are not already defined in the customer application code.
 */
#ifndef BWD_TYPES
/*FDI 5.0 for CCDi SYS  start */
#define BWD_TYPES
/*FDI 5.0 for CCDi SYS  end */
typedef unsigned char              BYTE; /*  8 bits wide, unsigned           */
typedef unsigned short int         WORD; /* 16 bits wide, unsigned           */
typedef unsigned long             DWORD; /* 32 bits wide, unsigned           */
/* E.5.5.5.986 Begin */
/* Uncomment these type(s) if not defined elsewhere */
/*
typedef void                       VOID;
typedef unsigned char              BOOL;
typedef unsigned char             UINT8;
typedef unsigned short int       UINT16;
typedef unsigned long            UINT32;
*/
/* E.5.5.5.986 End */
#endif /* BWD_TYPES */

/*
 * The following macro, PTR_TYPES, should initialy be undefined
 * for stand alone FDI and customer use if VOID_PTR,
 * BYTE_PTR, DWORD_PTR, BYTE_BITMASK, and VOID_PTR_PTR
 * are not already defined in the customer application code.
 */

#ifndef PTR_TYPES
typedef WORD *                 WORD_PTR;
typedef DWORD *               DWORD_PTR;
typedef BYTE               BYTE_BITMASK; /* 8 bits wide mask                 */
typedef VOID_PTR *         VOID_PTR_PTR;
/* E.5.5.5.986 Begin */
/* Uncomment these type(s) if not defined elsewhere */
/*
typedef BOOL *                 BOOL_PTR;
typedef UINT8 *               UINT8_PTR;
typedef UINT16 *             UINT16_PTR;
typedef UINT32 *             UINT32_PTR;
*/
/* E.5.5.5.986 End */
#endif /* PTR_TYPES */

#ifndef TRUE
#define TRUE                    1
#endif /* !TRUE */

#ifndef FALSE
#define FALSE                   0
#endif /* !FALSE */

#ifndef NULL
#define NULL                 ((void *)0)
#endif /* !NULL */
/*
 * ### Platform configuration section:
 * ############################################################################
 */

/*
 * FLASH_DATA_WIDTH is equal to the width of the data bus to flash.  For a
 * 16-bit data bus, typedef a WORD to FLASH_DATA_WIDTH.  For a 32-bit data
 * bus, typedef a DWORD to FLASH_DATA_WIDTH.
 */
#if defined (FDI_USES_32BIT_FLASH)
typedef DWORD          FLASH_DATA_WIDTH;
#else
typedef WORD           FLASH_DATA_WIDTH;
#endif

/*
 * If two flash components comprise the width of the data bus, set the
 * following option to TRUE; otherwise, the option should be set to FALSE.
 */
#if defined (FDI_USES_32BIT_FLASH)
#define FLASH_PAIRED               TRUE
#else
#define FLASH_PAIRED               FALSE
#endif

#ifndef FLASH_START_ADDRESS
/* Set this address to be the appropriate address for the part being used    */
/*FDI 5.0 for CCDi SYS  start */
#define  FLASH_START_ADDRESS        (FDI_PARTITION_BASE_ADDRESS)
/*#define FLASH_START_ADDRESS   0x08000000 */
/*FDI 5.0 for CCDi SYS  end */
#endif /* !FLASH_START_ADDRESS */

/*
 * ### FDI Feature Switches section:
 * ############################################################################
 */

#if !defined(FDI_NO_DAV_VOLUME)
#define DIRECT_ACCESS_VOLUME        TRUE /* Enable this for DAV capability   */
#else
#define DIRECT_ACCESS_VOLUME       FALSE /* Disable this otherwise   */
#endif
#if (DIRECT_ACCESS_VOLUME == TRUE)       /* Select the DAV blocks.  Must be
                                          * outside the range specified for
                                          * FDI data types
                                          * (i.e. NUM_BOOT_BLOCKS,
                                          * NUM_DATA_BLOCKS).                */
#define DAV_START_ADDRESS DavStartAddress /* address at which the Direct Access
                                          * Volume begins */
#define DAV_BLOCKCOUNT      DavBlockCount /* number of code storage blocks    */
#define DAV_BLOCK_SIZE       DavBlockSize /* number of bytes in each block of
                                          * the direct access volume. */
#define DAV_NUM_CLASS_FILES DavNumClassFiles
#endif /* DIRECT_ACCESS_VOLUME */

/*FDI 5.0 for CCDi SYS  start */
#define FILE_MANAGER                TRUE /* Enable this for FM support       */
/*FDI 5.0 for CCDi SYS  end */
#if (FILE_MANAGER == TRUE)
typedef char FDI_TCHAR;                  /* size of character */

#define NUM_FILES                NumFiles /* Supported number of files. Must be
                                          * greater than 0 and less than
                                          * 65,535.                          */
/*FDI 5.0 for CCDi SYS  end */
/*FDI 5.0 for CCDi SYS  start */
#define NUM_OPEN_FILES                32 /* Number of simultaneous open files
                                          * supported.  Must be greater than
                                          * 0 and less than or equal to
                                          * NUM_FILES.                       */
/*FDI 5.0 for CCDi SYS  end */
#define FILE_SUPPORT_INFO_TYPE        12 /* File info structure's FDI type   */
#define FILE_SUPPORT_DATA_TYPE        13 /* Raw data's FDI type              */
/*FDI 5.0 for CCDi SYS  start */
#ifdef LTEONLY_THIN
#define FILE_NAME_SIZE               96 /* Maximum length of filename       */
#else
#define FILE_NAME_SIZE               128 /* Maximum length of filename       */
#endif
/*FDI 5.0 for CCDi SYS  end */
#endif /* FILE_MANAGER */

#define INCLUDE_FORMAT              TRUE /* True includes format code, false
                                          * excludes                         */

#define CONSISTENT_ACCESS_TIME      TRUE /*Enable this for Consistent Access Time
                                          Support*/

//#define FDI_NO_SLEEP TRUE
#define FDI_NO_SLEEP FALSE
#define  PERF_TEST        FALSE /*TRUE*/
#define  GSM_EMULATION    FALSE
/*
 * This define includes the capability to have data that fragments and is
 * tracked by sequence tables if set to TRUE. Taking this option out prevents
 * the fragmentation of data, saves 10-12 KB of ROM, and prevents any attempts
 * to fragment data by returning an error code
 */
#define INCLUDE_FRAGMENTED_DATA     TRUE

/*FDI 5.0 for CCDi SYS  start */
#define DATA_STREAM                FALSE /* Set to TRUE if need to maintain a
                                          * data rate otherwise set to FALSE */
/*FDI 5.0 for CCDi SYS  end */

#define FDI_NONE                       0
#define SINGLE_PR                      1
#define NUM_USER_PR_REGISTERS         17 /* number of user protection
                                          * registers in the flash part
                                          * There are 17 user protection
                                          * registers in Trumbull.           */
#define ENABLE_PR             SINGLE_PR /* number of user protection
                                          * number of user protection
                                          * registers in the flash part      */
/*
 * To enable protection register support, the absolute starting address of
 * the parameter partition must be supplied.  If a parameter partition is
 * not present on the flash component(s), the starting address of flash
 * must be specified.
 */
#define PARAMETER_PARTITION_START_ADDRESS FLASH_START_ADDRESS

#define BLOCK_LOCK_SUPPORT          TRUE /* Turn on flex locking capability  */
#define ENABLE_NONFDI_BLOCKLOCKING  TRUE
#define ENABLE_FDI_BLOCKLOCKING     TRUE

#if (INCLUDE_FRAGMENTED_DATA == TRUE)
#define PACKET_DATA                TRUE
#else /* INCLUDE_FRAGMENTED_DATA */
#define PACKET_DATA                FALSE
#define INCLUDE_FRAGMENTED_DATA    FALSE
#endif
#define PARAM_CHECK                 TRUE

#define HANDLE_NO_ERASE_COUNT       TRUE

/* When setting PARTITONS to SINGLE, FDI will treat the NUM_DATA_BLOCKS blocks
 * as one partition, interrupt polling or DIH is needed.
 * DUAL, will not use interrupt polling or DIH.
 * MULTI is essentially the same as dual but this option can be used when the
 * Flash part supports read while write(RWW).
 */

#define SINGLE                         1
#define DUAL                           2
#define MULTI                          3

/*FDI 5.0 for CCDi SYS  start */
#define PARTITIONS                  SINGLE/*  Set to SINGLE/DUAL/MULTI when
                                          * using Intel SINGLE/DUAL/MULTI
                                          * Partition architecture components
                                          * respectively.                    */
/*FDI 5.0 for CCDi SYS  end */

#define FREE_SPACE_FUNCTIONS        TRUE /* Turn on/off free space function  */


/* To disable the Data Volume expansion feature, set ADD_BLOCK to FALSE.  To
 * add blocks before the Data Volume, set ADD_BLOCK to BEFORE.  To add blocks
 * after the Data Volume, set ADD_BLOCK to AFTER.
 */
#define BEFORE                         1 /* Add Blocks before existing data
                                          * blocks                           */
#define AFTER                          2 /* Add Blocks after existing data
                                          * blocks                           */
#define ADD_BLOCK                  FALSE /* Turn on/off Add block feature    */

/*
 * ### FDI configuration section:
 * ############################################################################
 */
#define FDV_START_ADDRESS FdvStartAddress /* address at which the Data Volume
                                          * begins.  */
#define FDV_BLOCKCOUNT     FdvBlockCount /* number of data storage blocks    */
#define FDV_BLOCK_SIZE      FdvBlockSize /* number of bytes in each block of
                                          * the data volume. */
#define UNIT_GRANULARITY UnitGranularity /* minimum unit size in bytes       */
#define FDI_QUEUE_SIZE      FDIQueueSize /* bytes of memory used by queue    */
#define FDI_QUEUE_START                0 /* does not require changing        */
#define MIN_INSTANCES                  3 /* min number in multi-instance unit,
                                          * used to calculate the unit size  */
/*FDI 5.0 for CCDi SYS  start */
//#define BUFFER_SIZE                    0 /* size of internal flash buffer    */
//#define FDI_BUFFER_SIZE                0 /* size of internal flash buffer    */
//
/*FDI 5.0 for CCDi SYS  end */

#define RELOCATE_CODE              FALSE /* to have FDI relocate the low-level
                                          * functions, set to TRUE.  to have
                                          * the boot loader or application
                                          * relocate the low-level functions,
                                          * set to FALSE.                    */
#if (RELOCATE_CODE == TRUE)
#define FDI_RAM_START         0x00000000 /* RAM address where low-lvl funcs
                                          * will be copied.  If 0, the start
                                          * address will be automatically
                                          * determined. If non-zero the
                                          * non-zero value is assumed to be
                                          * the start address.               */
#endif /* RELOCATE_CODE */

#define SYSTEM_THRESHOLD   FDI_THRESHOLD /* This defines the free space
                                          * limit before reclaim is requested*/
#define RECL_PRIORITY       ReclPriority /* OS priority of reclaim task      */
#define RECL_STACK_SIZE    ReclStackSize /* stack size of reclaim task       */
#define BKGD_PRIORITY       BkgdPriority /* OS priority of background task   */
#define BKGD_STACK_SIZE    BkgdStackSize /* stack size of background task    */

#define NUM_TYPE0_PARMS    NumType0Parms
#define NUM_TYPE1_PARMS    NumType1Parms
#define NUM_TYPE2_PARMS    NumType2Parms
#define NUM_TYPE3_PARMS    NumType3Parms
#define NUM_TYPE4_PARMS    NumType4Parms
#define NUM_TYPE5_PARMS    NumType5Parms
#define NUM_TYPE6_PARMS    NumType6Parms
#define NUM_TYPE7_PARMS    NumType7Parms
#define NUM_TYPE8_PARMS    NumType8Parms
#define NUM_TYPE9_PARMS    NumType9Parms
#define NUM_TYPE10_PARMS  NumType10Parms
#define NUM_TYPE11_PARMS  NumType11Parms
#define NUM_TYPE12_PARMS  NumFiles
#define NUM_TYPE13_PARMS  NumFiles

/*
 * FDI has been optimized to work with the Phone.com UP.Browser(tm). If the
 * browser is installed, you should not use Type 14. It is reserved for the
 * browser. If the browser is not installed, Type 14 is available to your
 * application.
 */
#define NUM_TYPE14_PARMS  NumType14Parms


#if (FILE_MANAGER == TRUE)
/* !!! DO NOT MODIFY DEFINES BELOW IF FILE_MANAGER == TRUE.     !!! */
/* !!! NUM_FILES will override user defined values for types    !!! */
/* !!! FILE_SUPPORT_INFO_TYPE and FILE_SUPPORT_DATA_TYPE.       !!! */
#if ((FILE_SUPPORT_INFO_TYPE == 0) || (FILE_SUPPORT_DATA_TYPE == 0))
#undef  NUM_TYPE0_PARMS
#define NUM_TYPE0_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 1) || (FILE_SUPPORT_DATA_TYPE == 1))
#undef  NUM_TYPE1_PARMS
#define NUM_TYPE1_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 2) || (FILE_SUPPORT_DATA_TYPE == 2))
#undef  NUM_TYPE2_PARMS
#define NUM_TYPE2_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 3) || (FILE_SUPPORT_DATA_TYPE == 3))
#undef  NUM_TYPE3_PARMS
#define NUM_TYPE3_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 4) || (FILE_SUPPORT_DATA_TYPE == 4))
#undef  NUM_TYPE4_PARMS
#define NUM_TYPE4_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 5) || (FILE_SUPPORT_DATA_TYPE == 5))
#undef  NUM_TYPE5_PARMS
#define NUM_TYPE5_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 6) || (FILE_SUPPORT_DATA_TYPE == 6))
#undef  NUM_TYPE6_PARMS
#define NUM_TYPE6_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 7) || (FILE_SUPPORT_DATA_TYPE == 7))
#undef  NUM_TYPE7_PARMS
#define NUM_TYPE7_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 8) || (FILE_SUPPORT_DATA_TYPE == 8))
#undef  NUM_TYPE8_PARMS
#define NUM_TYPE8_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 9) || (FILE_SUPPORT_DATA_TYPE == 9))
#undef  NUM_TYPE9_PARMS
#define NUM_TYPE9_PARMS  NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 10) || (FILE_SUPPORT_DATA_TYPE == 10))
#undef  NUM_TYPE10_PARMS
#define NUM_TYPE10_PARMS NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 11) || (FILE_SUPPORT_DATA_TYPE == 11))
#undef  NUM_TYPE11_PARMS
#define NUM_TYPE11_PARMS NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 12) || (FILE_SUPPORT_DATA_TYPE == 12))
#undef  NUM_TYPE12_PARMS
#define NUM_TYPE12_PARMS NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 13) || (FILE_SUPPORT_DATA_TYPE == 13))
#undef  NUM_TYPE13_PARMS
#define NUM_TYPE13_PARMS NUM_FILES
#endif
#if ((FILE_SUPPORT_INFO_TYPE == 14) || (FILE_SUPPORT_DATA_TYPE == 14))
#undef  NUM_TYPE14_PARMS
#define NUM_TYPE14_PARMS NUM_FILES
#endif
/* !!! DO NOT MODIFY DEFINES ABOVE IF FILE_MANAGER == TRUE.     !!! */
/* !!! NUM_FILES will override user defined values for types    !!! */
/* !!! FILE_SUPPORT_INFO_TYPE and FILE_SUPPORT_DATA_TYPE.       !!! */
#endif

/*FDI 5.0 for CCDi SYS  start */
#define NUM_OPEN_PARAMS               32 /* Number of simultaneous open streams
                                          * supported.  If FILE_MANAGER is set
                                          * to FALSE, then NUM_OPEN_PARAMS must
                                          * be greater than 0 and less than or
                                          * equal to 127.
                                          * If FILE_MANAGER is set to TRUE,
                                          * then (NUM_OPEN_FILES +
                                          * NUM_OPEN_PARAMS) must be greater
                                          * than 0 and less than or equal to
                                          * 127.                             */
/*FDI 5.0 for CCDi SYS  end */

#define WEARLEVELING_LIMIT          1000 /* difference between most and least
                                          * erased block for reclamation     */



/*
 * ### FDI abstraction typedefs and macros section:
 * ############################################################################
 */

/*
 * If your system does not have definition for the following you must define
 * them here
 */

/*FDI 5.0 for CCDi SYS  start */
/* semaphore ID type */
/*sys:this is nuclues semaphore type.*/
#ifdef _FDI_USE_OSA_
typedef OSASemaRef SEM_ID;
#else
typedef NU_SEMAPHORE *SEM_ID;
#endif //_FDI_USE_OSA_

/* semaphore status type */
typedef int          SEM_STATUS;
 /*FDI 5.0 for CCDi SYS  end*/

/* typedef void * SEM_ID; */
/* E.5.0.708 START */
/* Change PACKED to FDI_PACKED */

/*FDI 5.0 for CCDi SYS  start*/
   typedef  struct
   {
      int  current_task_id;
      WORD wait_count;
      SEM_ID binary_sem;
      BYTE used;
      BYTE reserved;
   } FDI_PACKED(SEM_MTX);
/*FDI 5.0 for CCDi SYS  end*/

   typedef SEM_MTX * SEM_MTX_ID;
/* E.5.0.708 END */

/*E.5.0.598.START*/
/* Semaphore Routine Macros: */
/*
 * TASK_CREATE_DESTROY - If TRUE, FDI can dynamically create and destroy
 * the BKGD_Task and the RECL_Task.  Customers using operating systems that
 * don't allow dynamic creation and destruction of tasks can statically
 * define their tasks.  Test_GSM will create and destroy these two tasks
 * on startup and shutdown if this is FALSE
 */
#define TASK_CREATE_DESTROY TRUE       /* default is TRUE */

/*
 * SEM_CREATE_DESTROY - If TRUE, FDI can dynamically create and destroy
 * the semaphores for background and reclaim.  Customers using operating
 * systems that don't allow dynamic creation and destruction of semaphores
 * can statically define their semaphores.  Test_GSM will create and destroy
 * these semaphores on startup and shutdown if this is FALSE
 */
#define SEM_CREATE_DESTROY TRUE        /* default is TRUE */

/*
 * Static tasks and dynamic semaphores is not supported at this time.
 * Do not set TASK_CREATE_DESTROY to FALSE and SEM_CREATE_DESTROY to
 * TRUE.
 */

/*
 * The following macro, OS_MACROS, should initialy be undefined
 * for stand alone FDI and customer use. Define it only if the following
 * macros are defined else where.
 */
#if(SEM_CREATE_DESTROY == TRUE)
/*
#ifndef OS_MACROS
#define SEM_TRY_WAIT(a)                semTake(a, NO_WAIT)
#define SEM_WAIT(a)                    semTake(a, WAIT_FOREVER)
#define SEM_WAIT_TIME(a,b)             semTake(a, b)
#define SEM_POST(a)                    semGive(a)
#define SEM_BIN_CREATE()               semBCreate(SEM_Q_FIFO, SEM_EMPTY)
#define SEM_DESTROY(a)                 semDelete(a); a = SEM_NULL
#endif
*/  /*OS_MACROS*/

/*FDI 5.0 for CCDi SYS  start */
#ifdef _FDI_USE_OSA_
#define SEM_TRY_WAIT(a)                FDI_SemWait(a, OSA_NO_SUSPEND)
#define SEM_WAIT(a)                    FDI_SemWait(a, OSA_SUSPEND)
#else
#define SEM_TRY_WAIT(a)                FDI_SemWait(a, NU_NO_SUSPEND)
#define SEM_WAIT(a)                    FDI_SemWait(a, NU_SUSPEND)
#endif //_FDI_USE_OSA_
#define SEM_WAIT_TIME(a,b)             FDI_SemWait(a, b)
#define SEM_POST(a)                    FDI_SemPost(a)
#define SEM_BIN_CREATE()               FDI_SemBinCreate()
#define SEM_DESTROY(a)                 FDI_SemDestroy(a); a = SEM_NULL
#define SEM_OK                         0
#define SEM_ERROR                      -1

#define SEM_MTX_CREATE()               FDI_SemMtxCreate()
#define SEM_MTX_POST(a)                FDI_SemMtxPost(a)
#define SEM_MTX_TRY_WAIT(a)            FDI_SemMtxTryWait(a)
#define SEM_MTX_WAIT(a)                FDI_SemMtxWait(a)
#define SEM_MTX_DESTROY(a)             FDI_SemMtxDestroy(a); a = SEM_NULL

/*FDI 5.0 for CCDi SYS  end */
#endif /* SEM_CREATE_DESTROY */

/*FDI 5.0 for CCDi SYS  start */
/*sys
#ifndef SEM_MTX_CREATE
#ifndef OS_MACROS
#define SEM_MTX_CREATE()               Sem_Mtx_Create()
#define SEM_MTX_POST(a)                Sem_Mtx_Post(a)
#define SEM_MTX_TRY_WAIT(a)            Sem_Mtx_Try_Wait(a)
#define SEM_MTX_WAIT(a)                Sem_Mtx_Wait(a)
#define SEM_MTX_DESTROY(a)             Sem_Mtx_Destroy(a); a = SEM_NULL
#define Q_STATIC_SEM_CNT                9
#endif  *//*OS_MACROS*/
//#endif
/*FDI 5.0 for CCDi SYS  end */
/*SEM_MTX_CREATE*/

#if (TASK_CREATE_DESTROY == TRUE)
#ifndef OS_MACROS
/*FDI 5.0 for CCDi SYS  start */
#define SPAWN(a,b,c,d,e)              FDI_TaskSpawn(a, b, c, d, (VOID (*)( UNSIGNED, VOID * ))e)
/*FDI 5.0 for CCDi SYS  end */
   /*sys SPAWN_ERROR is used for */
#define SPAWN_ERROR                    ((int)(-1))
/*FDI 5.0 for CCDi SYS  start */
#define VX_FP_TASK                     0
/*FDI 5.0 for CCDi SYS  end */
#define TASK_OPTIONS                   VX_FP_TASK
/*FDI 5.0 for CCDi SYS  start */
#define TASK_DESTROY(a)                FDI_TaskDestroy(a); a = 0
/*FDI 5.0 for CCDi SYS  end */
#endif /* OS_MACROS */
#endif /*TASK_CREATE_DESTROY*/
/*E.5.0.598.END*/
#ifndef offsetof
#define offsetof(type, member)         ((unsigned int)&((type *)0)->member)
#endif

#ifndef mFDI_MemberSize
#define mFDI_MemberSize(type, member)  (sizeof(((type *)0)->member))
#endif

/*FDI 5.0 for CCDi SYS  start */
#define Current_Task_Pointer()         taskIdSelf()
#define Interupt_Level_Set             intLevelSet
#define TaskDelay(a)                 FDI_TaskDelayTicks(a)
/*FDI 5.0 for CCDi SYS  end */
/*FDI 5.0 for CCDi SYS  start */
#define   FDI_MALLOC(x)    FDI_MemMalloc(x)
#define   FDI_FREE(x)    FDI_MemFree(x)
/*FDI 5.0 for CCDi SYS  end */

/*FDI 5.0 for CCDi SYS  start */

/* system specific macro to disable / enable system interrupts */

#ifdef _FDI_USE_OSA_
#define DISABLE_INTERRUPTS()    OSAIsrDisable(OSA_DISABLE_INTERRUPTS)
#define ENABLE_INTERRUPTS(a)    OSAIsrEnable(a)

//the following is used for original define.
//in the following files.
#define FDI_ENABLE_INTERRUPTS(key0, key1) \
   OSAIsrEnable((int) (key0)); \
   (key1) = (key0)

#define FDI_DISABLE_INTERRUPTS(key0, key1) \
   (key0) = (DWORD) OSAIsrDisable(OSA_DISABLE_INTERRUPTS); \
   (key1) = (key0)
#else
#define DISABLE_INTERRUPTS()    NU_Control_Interrupts(NU_DISABLE_INTERRUPTS)
#define ENABLE_INTERRUPTS(a)    NU_Control_Interrupts(a)

//the following is used for original define.
//in the following files.
#define FDI_ENABLE_INTERRUPTS(key0, key1) \
   NU_Control_Interrupts((int) (key0)); \
   (key1) = (key0)

#define FDI_DISABLE_INTERRUPTS(key0, key1) \
   (key0) = (DWORD) NU_Control_Interrupts(NU_DISABLE_INTERRUPTS); \
   (key1) = (key0)
#endif //_FDI_USE_OSA_

/*
 * This macro catches the FDI fatal error whenever it occurs
 */
//#define FDI_ASSERT(x)           if (!(x)) {DISABLE_INTERRUPTS(); while (TRUE);}
#define FDI_ASSERT(x)             {\
                                    if (!(x)) \
                                    { \
                                        utilsAssertFail(#x , __FILE__, __LINE__, 1);\
                                    } \
                                  }

/*FDI 5.0 for CCDi SYS  end */

/* size_t is defined in stdio.h.  If your OS does not have this
 * uncomment the following
 */
/*FDI 5.0 for CCDi SYS  start */
#ifndef __size_t
#define __size_t 1
//#ifndef _HERMON_
//typedef unsigned int size_t ;
//#endif // _HERMON_
#endif
/*FDI 5.0 for CCDi SYS  end */

/*
 * ### Debug section:
 * ############################################################################
 */
/*#define writeToFile*/                  /* If logMsgs from screen need to be
                                          * logged to a file. If you want the
                                          * timing info logged, you have to
                                          * also uncomment TIMING define
                                          * above                            */
#ifdef TESTING
#ifdef writeToFile
   FILE *rw;
#endif
#endif

/* #define TIMING */                     /* uncomment this if timing needs to
                                          * occur - requires FDI_DEVELOPMENT */
/* #define TEST_MSGS 1 */                /* uncomment this to display test
                                          * messages.                        */
/*
 * ### Globaly used includes:
 * ############################################################################
 */
#include "FDI_ERR.h"

/*FDI 5.0 for CCDi SYS  start */
#include "FDI_OS.h"
/*FDI 5.0 for CCDi SYS  end */

#endif /* Sentry Header */

