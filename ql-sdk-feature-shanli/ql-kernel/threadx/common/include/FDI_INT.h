/* ###########################################################################
###  Intel Confidential
###  Copyright (c) Intel Corporation 1995-2002
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: FDI_INT.H - This module consists of all the internal FDI control
###                      struct definitions and function prototypes required.
###
###  $Archive: /FDI/SRC/INCLUDE/fdi_int.h $
###  $Revision: 173 $
###  $Date: 1/18/05 10:59a $
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


#ifndef __FDI_INT_H                   /* sentry header */
#define __FDI_INT_H

/* ### Include Files
 * ################################# */
/* E.5.0.690 Begin */
/*remove fdi_lowl.h,fdi_que.h,fdi_err.h, add fdi_type,h */
#include "FDI_TYPE.h"
/* E.5.0.690 End */
/* ### Definitions
 * ################################# */

typedef WORD            IDTYPE;          /* data identifier type used in FDI */

#define  BYTEMAX        0xff
#define  WORDMAX        0xffff
#define  DWORDMAX       0xffffffff
#define  NOTUSED        WORDMAX
/* number of bytes from the bottom of flash that the FDV resides in */
#define  FDV_RELATIVE_ADDRESS       ((DWORD)(FDV_START_ADDRESS - \
                                             FLASH_START_ADDRESS))

/*
 * maximum number of UNIT_GRANULARITY before data is broken up into
 * smaller fragments
 */
#define MAX_NUM_UNITS_PER_FRAG         2   /*was 8*128, now 512*2 */

#define TRUNCATE_SUPPORT             FALSE /*TRUE*/
#if (PACKET_DATA == TRUE)
#define PACKETNPLRTEST               FALSE
#endif
/*
 * Use this define in the TO_BYTE() macro
 * "<< GRAN_SHIFT" rather than "* UNIT_GRANULARITY"
 */
/* changes for Run-time variables */
#if 0
#if (UNIT_GRANULARITY ==     16)
#define GRAN_SHIFT    4
#elif (UNIT_GRANULARITY ==   32)
#define GRAN_SHIFT    5
#elif (UNIT_GRANULARITY ==   64)
#define GRAN_SHIFT    6
#elif (UNIT_GRANULARITY ==  128)
#define GRAN_SHIFT    7
#elif (UNIT_GRANULARITY ==  256)
#define GRAN_SHIFT    8
#elif (UNIT_GRANULARITY ==  512)
#define GRAN_SHIFT    9
#elif (UNIT_GRANULARITY == 1024)
#define GRAN_SHIFT   10
#elif (UNIT_GRANULARITY == 2048)
#define GRAN_SHIFT   11
#elif (UNIT_GRANULARITY == 4096)
#define GRAN_SHIFT   12
#elif (UNIT_GRANULARITY == 8192)
#define GRAN_SHIFT   13
#else
#error UNIT_GRANULARITY > 8192 OR < 16 OR not 2**n !!
#endif /* UNIT_GRANULARITY */
#endif

/* This is calculated in FDI_Init */
#define  GRAN_SHIFT           GranShift
#define  SEM_NULL             NULL     /* change for semaphore type SEM_ID */

#define  NIBBLE               4
#define  BADSTUFF             -1
#define  EVEN_NIBBLE(x)       ((x) % 2 == 0)
#define  ODD_NIBBLE(x)        ((x) % 2 == 1)
#define  NIBBLE_LOW(x)        (BYTE)((x)&0x0f)
#define  NIBBLE_HIGH(x)       (BYTE)(((x)>>NIBBLE)&0x0f)
#define  BYTE_HIGH(x)         (BYTE)(((x)>>8)&0xff)
#define  BYTE_LOW(x)          (BYTE)((x) & 0xff)
#define  WORD_HIGH(x)         (WORD)(((x)>>16)&0xffff))
#define  WORD_LOW(x)          (WORD)((x)&0xffff)
#define  BYTEMASK(high,low)   (BYTE)(((high)<<NIBBLE) | ((low)&0x0f))
#define  WORDMASK(high,low)   (WORD)(((high)<<8)|((low)&0xff))
#define  DWORDMASK(high,low)  (DWORD)(((high)<<16)|((low)&0xffff))
#define  BLOCK_ADDRESS(x)     ((DWORD)(x)*(DWORD)FDV_BLOCK_SIZE+\
                                FDV_RELATIVE_ADDRESS)
#define  TO_BYTES(a)          ((a)<<GRAN_SHIFT)
/* E.5.6.2.1004 Begin */
/* E 5.1.849 START */
#define  TO_GRAN(a)           ((((a)>>GRAN_SHIFT)+\
                               ((((a)&(UNIT_GRANULARITY-1))!=0)?1:0)))
/* E 5.1.849 END */
#define  TO_SIZE(a,b)         ((((a)/(b))+((((a)%(b))!=0)?1:0)))
/* E.5.6.2.1004 End */
#define  OPEN_STREAM_FLAG     2 /* bitmask value for OpenStream use */

/* E.5.1.759 Begin */
#define FDI_MAX_FRAG_SIZE            (UNIT_GRANULARITY*MAX_NUM_UNITS_PER_FRAG)
/* E.5.1.759 End */

/*E.5.5.946 Begin*/
#ifdef  INCLUDE_FRAGMENTED_DATA
//#error  "Please remove the definition in FDI_type.h"
#endif
#undef  INCLUDE_FRAGMENTED_DATA
#define INCLUDE_FRAGMENTED_DATA     TRUE
/*E.5.5.946 END*/
/*
 * For data streaming we must use the include fragmented data define
 */
#if (DATA_STREAM == TRUE)
#undef INCLUDE_FRAGMENTED_DATA
#define INCLUDE_FRAGMENTED_DATA  TRUE
#endif /* DATA_STREAM */

/*
 * The following is used to increase the allowable open params array size
 * to the sum of OPEN_ARRAY_SIZE and NUM_OPEN_FILES to guarantee the
 * File Open operations from the file manager as well as the direct FDI calls
 */

#ifndef FILE_MANAGER
  #define FILE_MANAGER    FALSE
#endif

#if(FILE_MANAGER == TRUE)
  #define   OPEN_ARRAY_SIZE  (NUM_OPEN_PARAMS + NUM_OPEN_FILES)
#else
  #define   OPEN_ARRAY_SIZE   NUM_OPEN_PARAMS
#endif

#define SET_LAST_HEADER_OFFSET(block, hdr_addr)   \
      (FDI_LogicalBlockTable[(block)].last_header_offset = \
      (WORD)(((hdr_addr)-FIRST_HEADER_OFFSET)/(sizeof(UNIT_HEADER))))

#define LAST_HEADER_OFFSET(block)  \
      (((DWORD)(FDI_LogicalBlockTable[(block)].last_header_offset) * \
      (DWORD)(sizeof(UNIT_HEADER))) + FIRST_HEADER_OFFSET)

/* Used to set all fields of a DLT entry. */
#if (CONSISTENT_ACCESS_TIME == TRUE)

/* if the input header offset is DWORDMAX, the header index will be set to
 * WORDMAX, which means the index is empty */

#define SET_LOOKUP_TABLE( type, id,  block, hdr_offset, stream ) \
        { \
           (FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num = (block);\
           if((hdr_offset) != DWORDMAX)\
           {\
              (FDI_DataLookupPtrTable[(type)] + (id))->hdr_index = \
              (WORD)(((hdr_offset)-FIRST_HEADER_OFFSET)/sizeof(UNIT_HEADER));\
           }\
           else\
           {\
              (FDI_DataLookupPtrTable[(type)] + (id))->hdr_index = WORDMAX;\
           }\
           (FDI_DataLookupPtrTable[(type)]+(id))->open_stream_index=(stream);\
           (FDI_DataLookupPtrTable[(type)]+(id))->paraExist = 0; \
           (FDI_DataLookupPtrTable[(type)]+(id))->delete_pending = BYTEMAX; \
        }
#else
#define SET_LOOKUP_TABLE(id, block, stream, type) \
        { \
           (FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num = (block); \
           (FDI_DataLookupPtrTable[(type)]+(id))->open_stream_index=(stream);\
           (FDI_DataLookupPtrTable[(type)]+(id))->paraExist = 0; \
           (FDI_DataLookupPtrTable[(type)]+(id))->delete_pending = BYTEMAX; \
        }
#endif

/* Used to get the logical block number from a DLT entry. */
#define LOOKUP_TABLE_BLOCK(type, id) \
          ((WORD)((FDI_DataLookupPtrTable[(type)] + (id))->logical_blk_num))

/* Used to initialize all fields of a DLT entry. */
#if (CONSISTENT_ACCESS_TIME == TRUE)
#define INIT_LOOKUP_TABLE(type, id) \
        { \
           (FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num = WORDMAX;\
           (FDI_DataLookupPtrTable[(type)]+(id))->hdr_index = WORDMAX; \
           (FDI_DataLookupPtrTable[(type)]+(id))->open_stream_index=BYTEMAX;\
           (FDI_DataLookupPtrTable[(type)]+(id))->paraExist = BYTEMAX; \
           (FDI_DataLookupPtrTable[(type)]+(id))->delete_pending = BYTEMAX; \
        }
#else
#define INIT_LOOKUP_TABLE(type, id) \
        { \
           (FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num = WORDMAX;\
           (FDI_DataLookupPtrTable[(type)]+(id))->open_stream_index=BYTEMAX;\
           (FDI_DataLookupPtrTable[(type)]+(id))->paraExist = BYTEMAX; \
           (FDI_DataLookupPtrTable[(type)]+(id))->delete_pending = BYTEMAX; \
        }
#endif

/* Used to test if a DLT entry is empty, it returns TRUE if a DLT entry empty.
 * Can't check just the paramexists field because fdi_delete fails if only
 * exists field is checked.  Not sure why. This needs to be investigated.
*/
#define EMPTY_LOOKUP_TABLE(type, id) \
       (((FDI_DataLookupPtrTable[(type)]+(id))->paraExist == BYTEMAX ) &&\
       ((FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num==WORDMAX) &&\
       ((FDI_DataLookupPtrTable[(type)]+(id))->open_stream_index==BYTEMAX) &&\
       ((FDI_DataLookupPtrTable[(type)]+(id))->delete_pending==BYTEMAX))


/* Used to test if the logical block number field of a DLT entry is empty,
 * it returns TRUE if logical block entry is empty. i.e. WORDMAX */
#define NO_LOOKUP_TABLE_BLOCK(type, id) \
          ((FDI_DataLookupPtrTable[(type)] + (id))->logical_blk_num == WORDMAX)

/* Used to test if a DLT entry is not empty, it returns TRUE if the entry
 * is not empty. */
#define NOT_EMPTY_LOOKUP_TABLE(type, id) \
          (((FDI_DataLookupPtrTable[(type)]+(id))->paraExist == 0 ) || \
          ((FDI_DataLookupPtrTable[(type)]+(id))->logical_blk_num != WORDMAX))

/* Used to get the open stream field of a DLT entry. */
#define LOOKUP_TABLE_OSFIELD(type, id) \
          ((BYTE)((FDI_DataLookupPtrTable[(type)] + (id))->open_stream_index))

/* Used to set the open stream field of a DLT entry. */
#define SET_LOOKUP_TABLE_OSFIELD(type, id, open) \
          (FDI_DataLookupPtrTable[(type)] + (id))->open_stream_index = (open)

/* Used to clear the open stream field of a DLT entry. */
#define CLEAR_LOOKUP_TABLE_OSFIELD(type, id) \
          (FDI_DataLookupPtrTable[(type)] + (id))->open_stream_index = BYTEMAX

/*Used to check if the OSFIELD of a DLT entry is empty */
#define EMPTY_LOOKUP_TABLE_OSFIELD(type, id) \
    ((FDI_DataLookupPtrTable[(type)] + (id))->open_stream_index == BYTEMAX)

/* Used to set the PE field( i.e. 0: valid;
 *                           other value: invalid )
 */
#define SET_LOOKUP_TABLE_PEBIT(type, id)  \
          (FDI_DataLookupPtrTable[(type)] + (id))->paraExist = 0

#if (CONSISTENT_ACCESS_TIME == TRUE)
/* Used to set the hdr index field of a DLT entry */
#define SET_LOOKUP_TABLE_HDR(type, id, hdr_offset) \
        if((hdr_offset) != DWORDMAX)\
        {\
           (FDI_DataLookupPtrTable[(type)] + (id))->hdr_index = \
           (WORD)(((hdr_offset)-FIRST_HEADER_OFFSET)/sizeof(UNIT_HEADER));\
        }\
        else\
        {\
           (FDI_DataLookupPtrTable[(type)] + (id))->hdr_index = WORDMAX;\
        }

/* Used to get the hdr offset from a DLT entry */
#define LOOKUP_TABLE_HDR(type, id) \
           (((FDI_DataLookupPtrTable[(type)] + \
           (id))->hdr_index ) * sizeof(UNIT_HEADER) + FIRST_HEADER_OFFSET)

#endif /* end of CONSISTENT_ACCESS_TIME == TRUE */

/* Used to set the delete_pending flag in the lookup table */
#define SET_LOOKUP_TABLE_DELETE_PENDING(type,id) \
	        ((FDI_DataLookupPtrTable[(type)]+(id))->delete_pending = 0)

/* Used to test the delete_pending flag in the lookup table */
/* macro will return TRUE if flag has be set and file is being deleted */
#define TEST_LOOKUP_TABLE_DELETE_PENDING(type,id) \
	        ((FDI_DataLookupPtrTable[(type)]+(id))->delete_pending == 0)

/*
 * calculate the number of instances that fit in this unit: (unit size
 * in bytes minus size of MULTI_INSTANCE structure) divided by
 * (parameter size plus a byte for status)
 */
#define INSTANCES(a,b)        (((a)-sizeof(MULTI_INSTANCE))/((b)+1))
#define GRAN_REMAINING(a)     (UNIT_GRANULARITY-((a)%UNIT_GRANULARITY))

#define  MAX_DATA_BLOCKS (FDV_BLOCKCOUNT-1) /* last block to skip */ //FdvBlockCount
#define  BLOCK_INTEGRITY 0xf0f0        /* block's data integrity */
#define  BLK_INTEGRITY_INVALID 0xf0c0  /* invalidated block data integrity */
#define  LAST_BLOCK_ADDR (FDV_BLOCK_SIZE-1)   /* maximum block offset value */
#define  MAX_QUEUE_ITEM_SIZE ((((FDI_QUEUE_SIZE-sizeof(COMMAND))-\
sizeof(Q_DESCRIPTOR))-sizeof(Q_PRIORITY_HEADER))-sizeof(Q_ITEM_INFO))


/* maximum number of sequence table entries in one unit = 16 */
#define  MAX_SEQ_ENTRY (UNIT_GRANULARITY/sizeof(ENTRY_TABLE))

#define  ERASE_COUNT_UNIT_SIZE (TO_BYTES(TO_SIZE((sizeof(MULTI_INSTANCE)+\
(sizeof(DWORD)*MIN_INSTANCES)+TO_SIZE(MIN_INSTANCES,2)),UNIT_GRANULARITY))+\
sizeof(UNIT_HEADER))

#if (FDI_BUFFER_SIZE > 0)
#define  BUFFER_OFFSET_MASK FDI_BUFFER_SIZE-1
#define  BUFFER_OFFSET(a)  ((BYTE)FDI_BUFFER_SIZE - (BYTE)((DWORD)(a)&((DWORD)BUFFER_OFFSET_MASK)))
                        /* returns 0 if on buffer boundary.  Otherwise,
                           the number of bytes from the next boundary */
#endif

#if ((DATA_STREAM == TRUE) && (INCLUDE_FRAGMENTED_DATA == TRUE))
/* in B/S */
#define DATA_RATE (14400/8)

/* derived from excel spreadsheet in seconds */
#if PARTITIONS == SINGLE
#define RECLAIM_TIME 10
#else
#define RECLAIM_TIME 8
#endif
/* in Bytes */
#define DATA_STREAM_OVERHEAD (RECLAIM_TIME*DATA_RATE)

/* number of fragments */
#define  FDI_DATA_STREAM_FRAG ((DATA_STREAM_OVERHEAD)/\
              (UNIT_GRANULARITY+sizeof(UNIT_HEADER)))

/* maximum number of sequence table units = 20 */
#define  FDI_DATA_STREAM_SEQ_UNIT ((FDI_DATA_STREAM_FRAG/MAX_SEQ_ENTRY)+\
             (((FDI_DATA_STREAM_FRAG/MAX_SEQ_ENTRY)%UNIT_GRANULARITY)?1:0)+\
             ((FDI_DATA_STREAM_FRAG/MAX_SEQ_ENTRY)?0:1))

/* maximum units needed based on biggest sequence table unit = 20 */
#define  FDI_DATA_STREAM_GRP_UNIT ((FDI_DATA_STREAM_SEQ_UNIT/MAX_SEQ_ENTRY)+\
         (((FDI_DATA_STREAM_SEQ_UNIT/MAX_SEQ_ENTRY)%UNIT_GRANULARITY)?1:0)+\
         ((FDI_DATA_STREAM_SEQ_UNIT/MAX_SEQ_ENTRY)?0:1))
/* in Bytes */
#define FDI_DATA_STREAM_STRUCTURE_OVERHEAD ((FDI_DATA_STREAM_SEQ_UNIT+\
        FDI_DATA_STREAM_GRP_UNIT)*(UNIT_GRANULARITY+sizeof(UNIT_HEADER)))+\
        (FDI_DATA_STREAM_FRAG*sizeof(UNIT_HEADER))

#define FDI_OVERHEAD_PER_BLOCK (DATA_STREAM_OVERHEAD+\
        FDI_DATA_STREAM_STRUCTURE_OVERHEAD)

/* available space for the data after format */
#define  MAX_MEDIA_SIZE ((MAX_DATA_BLOCKS*(FDV_BLOCK_SIZE-sizeof(BLOCK_INFO)-\
         FDI_OVERHEAD_PER_BLOCK-sizeof(UNIT_HEADER)))-ERASE_COUNT_UNIT_SIZE)
                          /* for erase count parameter and it's header */

#define FDI_THRESHOLD (MAX_DATA_BLOCKS*FDI_OVERHEAD_PER_BLOCK)

#endif /* DATA_STREAM and FRAGMENTED_DATA*/


/*
 * There are 8 data blocks defined in fdi_type.h, 7 are used for storing data
 * and one is used for the spare block. Each of the 7 data blocks has a 16
 * byte block information structure and a 8 byte unit header terminator used
 * to separate unit headers and data. On the flash a 1 byte parameter is used
 * to store the flash wear leveling cycle count. This byte is maintained by
 * the FDI software system. Since unit granularity is defined as 128 bytes, it
 * will take 128 bytes of flash to store this parameter, plus 8 bytes for the
 * associated unit header.
 * Therefore, the free units after format is...
 * (7 blocks for data)(8192 bytes per block - 16 bytes per block info struc. -
 * 8 bytes per unit header/data separator) -
 * 128 bytes for wear leveling cycle count parameter - 8 bytes for unit header
 * equals 57,040 free bytes (0xded0)
 */

#if ((DATA_STREAM == FALSE) && (INCLUDE_FRAGMENTED_DATA == TRUE))
/* available space for the data after format */
#define  MAX_MEDIA_SIZE ((MAX_DATA_BLOCKS*(FDV_BLOCK_SIZE-sizeof(BLOCK_INFO)-\
sizeof(UNIT_HEADER)))-ERASE_COUNT_UNIT_SIZE)
                          /* for erase count parameter and it's header */

#endif /* !DATA_STREAM && INCLUDE_FRAGMENTED_DATA */

#if (INCLUDE_FRAGMENTED_DATA == FALSE)
/* available space for the data after format */
#define  MAX_MEDIA_SIZE ((MAX_DATA_BLOCKS*(FDV_BLOCK_SIZE-sizeof(BLOCK_INFO)-\
sizeof(UNIT_HEADER)))-ERASE_COUNT_UNIT_SIZE)
                          /* for erase count parameter and it's header */
#endif /* !INCLUDE_FRAGMENTED_DATA */

/* maximum 3 unit chunks of data that can be queued = 3 */
/* E.5.1.759 Begin */
#define  MAX_FRAG ((MAX_QUEUE_ITEM_SIZE/\
        FDI_MAX_FRAG_SIZE)+((MAX_QUEUE_ITEM_SIZE%\
        FDI_MAX_FRAG_SIZE!=0)?1:0))
/* E.5.1.759 End */

/*maximum units needed for the fragments of the biggest data in the media=21*/
#define  MAX_FRAG_UNITS ((MAX_DATA_BLOCKS*MAX_NUM_UNITS_PER_FRAG)*\
          ((MAX_FRAG/MAX_DATA_BLOCKS)+1))

/* maximum fragment units of a biggest data possible in the media = 419 */
/*
 * maximum number of fragments and associated headers that can fit in
 * MAX_MEDIA_SIZE
 */
#define  MAX_MEDIA_FRAG (MAX_MEDIA_SIZE-sizeof(UNIT_HEADER))/\
         (UNIT_GRANULARITY+sizeof(UNIT_HEADER))

#if (INCLUDE_FRAGMENTED_DATA == TRUE)

/*The Maximum Number of Entries in a Group Table is limited to a BYTE*/
/* Based on the Above limitation the size of the Group table is calculated*/
/*This define is added to limit the MAX_GRP_UNIT to 65536 */

/* E.5.0.728 Begin */
/*the original definition miss 2* before the last sizeof(UINT_HEADER)*/
#define MAX_GRP_UNIT_ENTRIES (((((FDV_BLOCK_SIZE - sizeof(BLOCK_INFO)) - 2*sizeof(UNIT_HEADER))  \
                             /sizeof(ENTRY_TABLE)) < 65536)? (((FDV_BLOCK_SIZE -       \
                             sizeof(BLOCK_INFO)) - 2*sizeof(UNIT_HEADER))  \
                             /sizeof(ENTRY_TABLE)): 65536 )
 /* E.5.0.728 End */
#define MAX_GRP_UNIT_SIZE ((((MAX_GRP_UNIT_ENTRIES *(sizeof(ENTRY_TABLE)))+ \
                                   sizeof(UNIT_HEADER))/UNIT_GRANULARITY))

/* maximum number of sequence table units = 20 */
#define  MAX_SEQ_UNIT  ((MAX_MEDIA_FRAG/MAX_SEQ_ENTRY)+\
          (((MAX_MEDIA_FRAG/MAX_SEQ_ENTRY)%UNIT_GRANULARITY)?1:0)+\
          ((MAX_MEDIA_FRAG/MAX_SEQ_ENTRY)?0:1))

/* maximum units needed based on biggest sequence table unit = 20 */
/*Maximum size of a Group Table based on the Size of the Media*/
#define  MAX_GRP_UNIT_MEDIA_SIZE  ((MAX_SEQ_UNIT/MAX_SEQ_ENTRY)+\
          (((MAX_SEQ_UNIT/MAX_SEQ_ENTRY)%UNIT_GRANULARITY)?1:0)+\
          ((MAX_SEQ_UNIT/MAX_SEQ_ENTRY)?0:1))

/* Size of the Maximum Group Table is fixed based on whether
   the size of the Group Table exceeds 65536 entries  or not  */
#define MAX_GRP_UNIT ((MAX_GRP_UNIT_MEDIA_SIZE>MAX_GRP_UNIT_SIZE)?\
                       MAX_GRP_UNIT_SIZE:MAX_GRP_UNIT_MEDIA_SIZE)

#endif /* INCLUDE_FRAGMENTED_DATA */

#if (DATA_STREAM == FALSE)
#if (INCLUDE_FRAGMENTED_DATA == TRUE)

#define SEQ_REPLACE_UNITS     ((MAX_FRAG/MAX_SEQ_ENTRY)+1+\
                              ((MAX_FRAG%MAX_SEQ_ENTRY)?1:0))

#define  MAX_THRESHOLD_UNIT   (MAX_FRAG_UNITS+FDI_MaxGrpUnit+SEQ_REPLACE_UNITS)

#else /* !INCLUDE_FRAGMENTED_DATA */

/* threshold in units = 21 */
#define  MAX_THRESHOLD_UNIT  ((MAX_MEDIA_FRAG<MAX_FRAG_UNITS)?\
MAX_MEDIA_FRAG:MAX_FRAG_UNITS)
#endif /* !INCLUDE_FRAGMENTED_DATA */

#if (INCLUDE_FRAGMENTED_DATA == TRUE)
/* threshold in bytes = 2688 */
#define  FDI_THRESHOLD ((MAX_THRESHOLD_UNIT*UNIT_GRANULARITY)+\
                   UNIT_GRANULARITY+sizeof(UNIT_HEADER))
                                       /* for replacing wearleveling parameter
                                        * unit and it's header. This defines
                                        * the absolute free space limit before
                                        * the background task pends on reclaim
                                        */
#else

/* threshold in bytes */
#define  FDI_THRESHOLD (((MAX_NUM_UNITS_PER_FRAG*MAX_DATA_BLOCKS)*\
UNIT_GRANULARITY)+sizeof(UNIT_HEADER)+(UNIT_GRANULARITY+sizeof(UNIT_HEADER)))
#endif /* INCLUDE_FRAGMENTED_DATA */

#endif /* !DATA_STREAM */

#if ((INCLUDE_FRAGMENTED_DATA == TRUE) && (DATA_STREAM == FALSE))
#define MAX_DATA_SIZE (((MAX_MEDIA_FRAG-MAX_SEQ_UNIT-FDI_MaxGrpUnit)*\
UNIT_GRANULARITY)-FDI_THRESHOLD)
#endif

#if ((INCLUDE_FRAGMENTED_DATA == TRUE) && (DATA_STREAM == TRUE))
#define MAX_DATA_SIZE ((MAX_MEDIA_FRAG-MAX_SEQ_UNIT-FDI_MaxGrpUnit)*\
UNIT_GRANULARITY)
#endif

#if (INCLUDE_FRAGMENTED_DATA == FALSE)
#define MAX_DATA_SIZE (MAX_MEDIA_SIZE-FDI_THRESHOLD)
#endif


#define  MAX_HEADERS    ((FDV_BLOCK_SIZE - sizeof(BLOCK_INFO)) / \
                         sizeof(UNIT_HEADER))

/* make sure if the block lock support is disabled all defines are false */
#if (BLOCK_LOCK_SUPPORT == FALSE)
#undef ENABLE_NONFDI_BLOCKLOCKING
#undef ENABLE_FDI_BLOCKLOCKING
#define ENABLE_NONFDI_BLOCKLOCKING  FALSE
#define ENABLE_FDI_BLOCKLOCKING     FALSE
#endif /* BLOCK_LOCK_SUPPORT */

/*
 * unit header status types. Changed for ISF to take bits down from right
   to left
 */
#define  HDR_EMPTY                0xFFFF
#define  HDR_ALLOCATING           0xFFFC
#define  HDR_VALID_HDR            0xFFF0
#define  HDR_ALLOCATED            0xFFC0
#define  HDR_VALID                0xFF00
#define  HDR_INVALIDATING         0xFC00
#define  HDR_INVALID              0xF000

#define  HDR_CORRUPT(status)      ((((status) & HDR_INVALID) != HDR_INVALID) ? 1:0 )
#define  INVALIDATE_HDR           0xF3FF
#define  INVALID_HDR(status)      (((status) & 0x0800) == 0)

/* HDR_READ_MASK is used to mask the higher status bit of each status cell
 * during status read.  HDR_STATE returns 1 if the status is in this state,
 * otherwise 0. */
#define  HDR_READ_MASK                      0xFAAA
#define  HDR_STATE(state, status)           (((status) & HDR_READ_MASK) == \
                                             ((state) & HDR_READ_MASK))

/* To determine if a status is in an intermediate state, the status can be
 * shifted 1 bit and exclusive-or'd with itself to overlay each cell's bits
 * over each other to determine if the cell was '10' or '01'.
 * HDR_INTERMEDIATE_MASK is used to mask the exclusive-or'd cell status bits
 * from the shift.  HDR_INTERMEDIATE returns a non-zero value if the status
 * is in an intermediate state.  The non-zero return value can be passed as
 * inter into HDR_FIX_INTERMEDIATE with status to return the fixed status. */
#define  HDR_INTERMEDIATE_MASK               0x0AAA
#define  HDR_INTERMEDIATE(status)            (((status) ^ ((status) << 1)) & \
                                              HDR_INTERMEDIATE_MASK)
#define  HDR_FIX_INTERMEDIATE(inter, status) ((~((inter) | ((inter) >> 1))) \
                                              & (status))

/*
 * sequence table status types
 */
#define  SEQ_EMPTY                0xFF
#define  SEQ_ALLOCATING           0xFC
#define  SEQ_VALID_ENTRY          0xF0
#define  SEQ_VALID                0xC0
#define  SEQ_INVALID              0x00
#define  GRP_EMPTY                SEQ_EMPTY
#define  GRP_ALLOCATING           SEQ_ALLOCATING
#define  GRP_VALID_ENTRY          SEQ_VALID_ENTRY
#define  GRP_VALID                SEQ_VALID
#define  GRP_INVALID              SEQ_INVALID

#define  INVALIDATE_ENTRY         0x3F
#define  INVALID_ENTRY(status)    (((status) & 0x80) == 0)

/* ENTRY_READ_MASK is used to mask the higher status bit of each status cell
 * during status read.  ENTRY_STATE returns 1 if the status is in this state,
 * otherwise 0. */
#define  ENTRY_READ_MASK                    0xAA
#define  ENTRY_STATE(state, status)         (((status) & ENTRY_READ_MASK) == \
                                             ((state) & ENTRY_READ_MASK))

/* To determine if a status is in an intermediate state, the status can be
 * shifted 1 bit and exclusive-or'd with itself to overlay each cell's bits
 * over each other to determine if the cell was '10' or '01'.
 * ENTRY_INTERMEDIATE_MASK is used to mask the exclusive-or'd cell status bits
 * from the shift.  ENTRY_INTERMEDIATE returns a non-zero value if the status
 * is in an intermediate state.  The non-zero return value can be passed as
 * inter into ENTRY_FIX_INTERMEDIATE with status to return the fixed status. */
#define  ENTRY_INTERMEDIATE_MASK               0xAA
#define  ENTRY_INTERMEDIATE(status)            (((status) ^ ((status) << 1)) & \
                                                ENTRY_INTERMEDIATE_MASK)
#define  ENTRY_FIX_INTERMEDIATE(inter, status) ((~((inter) | ((inter) >> 1))) \
                                                & (status))

/*
 * Mask to check the reclamation status and queue status.
 */
#define  RECLAIM_PENDING          0x01
#define  QUEUE_PENDING            0x02

/*
 * multiple instance status types
 */
#define  INST_EMPTY               0xFF
#define  INST_ALLOCATING          0xFC
#define  INST_VALID               0xF0
#define  INST_INVALID             0xC0

#define  INVALIDATE_INST          0xCF
#define  INVALID_INST(status)     (((status) & 0x20) == 0)

/* INST_READ_MASK is used to mask the higher status bit of each status cell
 * during status read.  INST_STATE returns 1 if the status is in this state,
 * otherwise 0. */
#define  INST_READ_MASK                     0xAA
#define  INST_STATE(state, status)          (((status) & INST_READ_MASK) == \
                                             ((state) & INST_READ_MASK))

/* To determine if a status is in an intermediate state, the status can be
 * shifted 1 bit and exclusive-or'd with itself to overlay each cell's bits
 * over each other to determine if the cell was '10' or '01'.
 * INST_INTERMEDIATE_MASK is used to mask the exclusive-or'd cell status bits
 * from the shift.  INST_INTERMEDIATE returns a non-zero value if the status
 * is in an intermediate state.  The non-zero return value can be passed as
 * inter into INST_FIX_INTERMEDIATE with status to return the fixed status. */
#define  INST_INTERMEDIATE_MASK               0xAA
#define  INST_INTERMEDIATE(status)            (((status) ^ ((status) << 1)) & \
                                               INST_INTERMEDIATE_MASK)
#define  INST_FIX_INTERMEDIATE(inter, status) ((~((inter) | ((inter) >> 1))) \
                                               & (status))
#define  GetBitStatus(data, bit)     (data & (1 << bit))
#define  SetBitStatus(data, bit)     (data = (data | (1 << bit)))
#define  ClearBitStatus(data, bit)   (data = (data & ~(1 << bit)))
/*
 * block status types
 */
#define  BLK_ERASED               0xFF
#define  BLK_RECOVER              0xFC
#define  BLK_ERASING              0xF0
#define  BLK_UPDATING             0xC0
#define  BLK_WRITE                0x00

/* BLK_READ_MASK is used to mask the higher status bit of each status cell
 * during status read.  BLK_STATE returns 1 if the status is in this state,
 * otherwise 0. */
#define  BLK_READ_MASK                      0xAA
#define  BLK_STATE(state, status)           (((status) & BLK_READ_MASK) == \
                                             ((state) & BLK_READ_MASK))

/* To determine if a status is in an intermediate state, the status can be
 * shifted 1 bit and exclusive-or'd with itself to overlay each cell's bits
 * over each other to determine if the cell was '10' or '01'.
 * BLK_INTERMEDIATE_MASK is used to mask the exclusive-or'd cell status bits
 * from the shift.  BLK_INTERMEDIATE returns a non-zero value if the status
 * is in an intermediate state.  The non-zero return value can be passed as
 * inter into BLK_FIX_INTERMEDIATE with status to return the fixed status. */
#define  BLK_INTERMEDIATE_MASK               0xAA
#define  BLK_INTERMEDIATE(status)            (((status) ^ ((status) << 1)) & \
                                              BLK_INTERMEDIATE_MASK)
#define  BLK_FIX_INTERMEDIATE(inter, status) ((~((inter) | ((inter) >> 1))) \
                                              & (status))

/*
 * unit header type_attribute attributes
 */
#define  ATTR_MULTI_INST          0x0c
#define  ATTR_SEQ_TABLE           0x00
#define  ATTR_GRP_TABLE           0x0d
#define  ATTR_SINGL_INST          0x0e
#define  ATTR_DATA_FRAG           0x02

/*
 * Attribute mask
 */
#define  ATTRIBUTE_MASK           0x0f

/*
 * erase count identifier
 */
#define  ERASE_COUNT_ID           (NUM_TYPE14_PARMS)
#define  ERASE_COUNT_TYPE         14
/* additions for write commands */

#define  WRITE_DELETE              4   /* delete the data from FDI */

/* commands for FindInstance function */

#define  FIND_INSTANCE             0
#define  FIND_LAST_HEADER          1

/* To indicate that power loss recovery occurred during initialization. */

#define DELETE_IN_PROG          0x01
#define WRITE_IN_PROG           0x02
#define HDR_VALIDATION_IN_PROG  0x04
#define RECL_COPY_IN_PROG       0x08
#define RECL_ERASE_IN_PROG      0x10
#define UPDATE_IN_PROG          0x12

#define READ_DATA               0x01
#define MODIFY_DATA             0x02

#define DATA_BOTTOM     ((DWORD)(FDV_BLOCK_SIZE - sizeof(BLOCK_INFO)))
#define INITIAL_FREE    ((DWORD)(DATA_BOTTOM - sizeof(UNIT_HEADER) - \
                                FIRST_HEADER_OFFSET));
#define BLKINFO          (DATA_BOTTOM)
#define BLKINFO_STATUS   ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, status)))
#define BLKINFO_STATE    ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, current_state)))
#define BLKINFO_PHYCPY   ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, physical_copy)))
#define BLKINFO_LOGBLK   ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, logical_block_number)))
#define BLKINFO_ERASCNT  ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, erase_count)))
#define BLKINFO_PHYSCNT  ((DWORD)(DATA_BOTTOM + offsetof(BLOCK_INFO, physical_erase_count)))

/* Default Table Number Defines */
#define SEQUENCE_HDR_TABLE_NUMBER		0

/* First Instance Number Count */
#define FIRST_INSTANCE_NUMBER		1


/* ### Data Type Definitions:
 * ######################################################################## */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
/* Header corruption structure */
typedef struct CORRUPT_HDR {
   WORD  Id;      /* Header's identifier field */
   WORD  Block;   /* Header logical block number */
   WORD  Index;   /* Header index into block */
   WORD  TblNum;  /* Header's table number field */
   BYTE  TypAttr; /* Header's type/attribute field */
   BYTE  Exists;  /* Corruption counter */
   BYTE  Valid;   /* True if a valid header is found w/ same identity */
   BYTE  Rescan;  /* Header scan control */
}
FDI_PACKED(CORRUPT_HDR);
/* E.5.0.708 END */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct RECL_INFO {
   DWORD erase_cnt;           /* Erase count of block in updating state. */
   DWORD erase_hdr_addr;      /* Erase count header address. */
   DWORD updating_blk_addr;   /* Block found in reclaim updating state */
}
FDI_PACKED(RECL_INFO);
/* E.5.0.708 END */

/* Reclamation State Enumerations
 */
typedef enum {
   RECL_DISABLED = 0,
   RECL_ENABLED,
   RECL_BLK_FOUND,
   RECL_RECOVERING,
   RECL_ERASING,
   RECL_DONE,
   RECL_BAILED
} RECL_STATES;


/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct DATA_LOOKUP {
   WORD logical_blk_num;               /* logical block number of the data */
#if (CONSISTENT_ACCESS_TIME == TRUE)
   WORD hdr_index;                     /* index number for the header of
                                        * the data */
#endif
   BYTE open_stream_index;          /* index of FDI_OpenParam table */
   BYTE paraExist;                  /* 0: the data exists;
                                     * other value: the data doesn't exist */
   BYTE delete_pending;	            /* flag to indicate a background delete */
#if (CONSISTENT_ACCESS_TIME == TRUE)
   BYTE pad1;                       /* for DWORD alignment */
#else
   BYTE pad1, pad2, pad3;
#endif
}
FDI_PACKED(DATA_LOOKUP);
/* E.5.0.708 END */

typedef DATA_LOOKUP * DATA_LOOKUP_PTR;

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct UNIT_HEADER {
   WORD  identifier;                   /* unique identity per parameter */
   WORD  table_number;                 /* sequence table number of instance */
   WORD  g_unit_size;                  /* in multiples of granularity */
   WORD  g_unit_offset_bottom;         /* in granularities from top of the
                                        * block information */
   BYTE  type_attribute;               /* data type and unit attribute:
                                        * multiple instance, single instance,
                                        * sequence table, etc. */
   BYTE  pad1;                         /* 1 byte-expansion of type and
                                        * attribute
                                        * to separate bytes */
   WORD  status;                       /* power loss recovery status field
                                        * expanded to a word */
}
FDI_PACKED(UNIT_HEADER);
/* E.5.0.708 END */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct MULTI_INSTANCE {
   WORD  size_of_instance;             /* size of this instance of the data */
   WORD  number_of_instances;          /* number of data instances available
                                        * in this unit */
}
FDI_PACKED(MULTI_INSTANCE);
/* E.5.0.708 END */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct BLOCK_INFO {

/* E.5.5.937 Begin */
#if (FDI_BUFFER_SIZE > 0)
   BYTE  pad1[FDI_BUFFER_SIZE-16];
#endif
/* E.5.5.937 End */
   DWORD erase_count;                  /* number of times erased */
   DWORD physical_erase_count;         /* number of times the reclaim block is
                                        * erased */
   WORD  logical_block_number;         /* allows for movable spare block */
   WORD  physical_copy;                /* physical block number being
                                        * copied during reclamation */
   WORD  current_state;                /* this will demonstrate block
                                        * integrity */
   BYTE  status;                       /* reclamation information */
   BYTE  reserved_byte;                /* padding for data alignment */
}
FDI_PACKED(BLOCK_INFO);
/* E.5.0.708 END */


/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct ENTRY_TABLE {
   WORD  block_number;                 /* virtual block number */
   WORD  entry_instance;               /* the instance of this frag/table */
   WORD  old_entry_block;              /* replaced entry's logical block # */
   WORD  physical_index;               /* the physical unit header index of
                                        * the header that needs to be
                                        * invalidated. */
   WORD  entry_size;                   /* in multiples of granularity */
   BYTE  entry_status;                 /* table entry status byte - POR */
   BYTE  pad1;
}
FDI_PACKED(ENTRY_TABLE);
/* E.5.0.708 END */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct LOGICAL_BLOCK {
   DWORD  free_space;                  /* the amount of free space in the
                                        * physical block in multiple DWORDs */
   DWORD  dirty_space;                 /* the amount of invalid space in the
                                        * physical block in multiple DWORDs */
   WORD  physical_block_number;        /* physical block identifier */
   WORD  last_header_offset;
}
FDI_PACKED(LOGICAL_BLOCK);
/* E.5.0.708 END */

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct DATA_LOCATION {
   IDTYPE   identifier;                /* identity of data accessed */
   BYTE  type_attribute;               /* data and unit type / attributes
                                        * accessed */
   BYTE     pad1;                      /*pad to make the structure DWORD alligned*/
}
FDI_PACKED(DATA_LOCATION);
/* E.5.0.708 END */


/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct OPEN_PARAM {            /*MOF*/
   DWORD  block_addr;                  /* the first address of the block */
   DWORD  tabl_block_addr;             /* first address of block containing
                                        * the sequence table unit */
   DWORD  frag_block_addr;             /* first address of block containing
                                        * fragment */
   DWORD  b_total_size;                /* number of bytes written total */
   DWORD  b_unit_size;                 /* data unit size in terms of bytes */
   DWORD  b_hdr_offset;                /* offset of the unit header */
   DWORD  b_tabl_hdr_offset;           /* byte offset of seq table header */
   DWORD  b_frag_hdr_offset;           /* byte offset of frag data header */
   DWORD  b_begin_unit_offset;         /* byte offset of beginning of unit */
   DWORD  b_grp_table_entry_offset;    /* offset into the group table unit */
   DWORD  b_begin_tabl_offset;         /* byte offset of beginning of table */
   DWORD  b_seq_table_entry_offset;    /* offset into the seq table unit */
   DWORD  b_current_file_offset;       /* byte offset into the data
                                        * stream(file) being accessed */
   DWORD  b_remaining_in_unit;         /* bytes remaining in the data unit */
   IDTYPE identifier;                  /* uniquely identifies param/stream */
   WORD   logical_block;               /* logical block number of block_addr */
   WORD   table_number;                /* used for group table entry in hdr */
   BYTE   type_attribute;              /* type and attribute identifier */
   BYTE   data_streaming;              /* used to indicate if opened for data
                                        * streaming */
}
FDI_PACKED(OPEN_PARAM);
/* E.5.0.708 END */

/* E.5.6.2.1004 Begin */
typedef struct GRAN_NEEDED {
   DWORD        frag_needed;            /* granularity needed by fragment */
   WORD        seq_needed;             /* granularity needed by sequence */
   WORD        grp_needed;             /* granularity needed by GRP table */
   /*BYTE        pad1, pad2;*/             /*pads to make the structure DWORD alligned*/
} GRAN_NEEDED;
/* E.5.6.2.1004 End */
#define TOTALGRAN(x)                 (x.frag_needed+x.seq_needed+x.grp_needed)
#define FDI_ONEGRANGRP_MAX_FRAGS     (MAX_SEQ_ENTRY*MAX_SEQ_ENTRY)
/* E.5.1.759 Begin */
/*
#define FDI_MAX_FRAG_SIZE            (UNIT_GRANULARITY*MAX_NUM_UNITS_PER_FRAG)
*/
/* E.5.1.759 End */
#define TO_SEQTBL(x)                 TO_SIZE(x,MAX_SEQ_ENTRY)

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct COMMAND {
   DWORD       data_offset;            /* beginning byte offset into data */
   GRAN_NEEDED gran_needed;            /* space needed terms of granularity */
   IDTYPE      identifier;             /* identity of data accessed */
   BYTE        sub_command;            /* task execution sub command */
   BYTE        type;                   /* command type: either data parameter,
                                        * data stream, etc. */
   BYTE        priority;               /* */
   BYTE        pad1, pad2, pad3;       /*pad to make the structure DWORD alligned*/
}
FDI_PACKED(COMMAND);
/* E.5.0.708 END */


typedef enum {
   FREE_UNITS = 0,
   DIRTY_UNITS
} FDI_SPACE;


typedef DATA_LOCATION *    DATA_LOC_PTR;
typedef OPEN_PARAM *      OPEN_STREAM_PTR;
typedef COMMAND *          COMMAND_PTR;
typedef UNIT_HEADER *      UNIT_HDR_PTR;
typedef MULTI_INSTANCE *   MULTI_INST_PTR;
typedef BLOCK_INFO *       BLK_INFO_PTR;





/* ### Global Variables
 * ################################# */
extern OPEN_PARAM *  FDI_OpenParamPtr;
extern WORD                FDI_SpareBlock;
extern WORD          GranShift; /* changes for Run-time variables */

/* global defined to track max grp tbl size */
/* E.5.0.660 Begin */
extern WORD FDI_MaxGrpUnit;
/* E.5.0.660 End */
/* changes for Run-time variables */
/* externed here rather than in every C file */
extern LOGICAL_BLOCK *FDI_LogicalBlockTable;


/* ### Global Functions
 * ################################# */
/* changes for Run-time variables */
ERR_CODE allocateMemory(void);

ERR_CODE InitVariables(void);

/* usage: status = InitUnit();
 */
ERR_CODE InitUnit(void);

/* usage: status = FDI_Terminate();
 */
HW_ERROR FDI_Terminate(void);

/* usage: status = DataFind(id, type, command);
 */
ERR_CODE DataFind(IDTYPE, BYTE, BYTE);

/* usage: status = GetDataSize(&size, id, type, priority);
 */
ERR_CODE GetDataSize(DWORD_PTR, IDTYPE, BYTE, BYTE);

/* Validates the unit header and updates the free_space field of the
 * logical block table, if the unit_header_status is valid.  Invalidates the
 * unit header and updates the dirty_space field of the logical block table,
 * if the unit_header_status is invalid.
 */
ERR_CODE WriteUnitHeaderStatus(DWORD, WORD, WORD, WORD, BYTE);

/* If the unit_header_status is allocated or valid, scans the entire media to
 * see if an valid identifier of same type exists, and return it's address
 * in invalidating_hdr_addr if
 * it exists, or a NULL if it no valid sequence table unit header exists.
 * If the unit_header_status is allocating, scans the entire media to
 * invalidate all the unit headers of matching identifier that are not marked
 * valid. If the unit_header_status is invalidating, scans the entire media
 * and invalidates the matching unit headers that not marked invalid.
 */

/* usage: status = SearchForIdentifier(&new_unit_header,&old_hdr_addr,
 *               current_unit_index, current_logical_block, init_flag);
 */
/* E.5.0.652 Begin */
/* E.5.3.877 Start */
ERR_CODE SearchForIdentifier(UNIT_HEADER *, DWORD_PTR, DWORD, WORD, WORD, BYTE, BYTE);
/* E.5.3.877 END */
HW_ERROR FlashDevInvalidateInstance(WORD);
/* E.5.0.652 End */

/*
 * Checks the currently validated header address with the currently
 * processed header address and returns either BYTEMAX or 0 to indicate if
 * the free space, and dirty space fields are already updated or not.
 */
BYTE CheckAddr(DWORD, WORD, WORD);


/* usage: MemoryMove(&dest_buff, &source_buff, size);
 */
/* E.5.0.652 Begin */
void MemoryMove(BYTE_PTR, BYTE *, WORD);
/* E.5.0.652 End */

/* usage: dest_buff_ptr = MemorySet(&dest_buff, value, size);
 */
BYTE_PTR MemorySet(BYTE_PTR, BYTE, DWORD);

/* usage: equal = MemoryCompare(&dest_buff, &source_buff, size);
 */
/* E.5.0.652 Begin */
BYTE MemoryCompare(BYTE *, BYTE *, DWORD);
/* E.5.0.652 End */

HW_ERROR
ReadModify(BYTE_PTR, DWORD_PTR, DWORD, DWORD, IDTYPE, BYTE, BYTE, BYTE);

/* usage: wr_status = WriteData(buf_ptr, offset, id, size, type, sub_cmd);
 */
HW_ERROR WriteData(BYTE_PTR, DWORD, IDTYPE, WORD, BYTE, BYTE);

/* usage:
 * hw_status =
 *    FlashDevFindInstance(&block_addr, &header_offset, &unit_offset, identifier,
 *                      table_number, instance, logical_block, HDR_VALID,
 *                      type, attribute, command);
 */
extern HW_ERROR FlashDevFindInstance(DWORD_PTR , DWORD_PTR ,DWORD_PTR ,IDTYPE ,WORD ,
                      WORD ,WORD ,WORD ,BYTE ,BYTE ,BYTE );
/* usage: recl_status = RECL_Init();
 */
HW_ERROR RECL_Init(void);

/* usage: recl_status = RECL_Terminate();
 */
HW_ERROR RECL_Terminate(void);

/* usage: bkgd_status = BKGD_Init();
 */
HW_ERROR BKGD_Init(void);

/* usage: bkgd_status = BKGD_Terminate();
 */
HW_ERROR BKGD_Terminate(void);

/* usage: total_space = BKGD_GetTotalSpace(field);
 */
DWORD BKGD_GetTotalSpace(FDI_SPACE field);

/* usage:
 * hw_status =
 *    LookupToHeader(&block_addr, &unit_addr, &header_offset, &unit_header,
 *                   &logical_block, identifier, type);
 */
HW_ERROR LookupToHeader(DWORD_PTR, DWORD_PTR, DWORD_PTR, UNIT_HDR_PTR,
                        WORD_PTR, IDTYPE, BYTE);
/*
 * usage:
 * status = BKGD_GetTableEntry(&location, &invalid_grp_entries,
 *                             &invalid_seq_entries, &grp_entries,
 *                             &seq_entries, offset,
 *                             grp_table_size / sizeof(ENTRY_TABLE));
 */
/* E.5.6.2.1004 Begin */
HW_ERROR BKGD_GetTableEntry(OPEN_STREAM_PTR, DWORD_PTR, BYTE_PTR, WORD_PTR,
                            BYTE_PTR, DWORD, WORD);
/* E.5.6.2.1004 End */

/* usage:
 *
 */
void
FDI_HandleError(HW_ERROR);

/* usage:
 * recl_state = RECL_GetState();
 */
RECL_STATES RECL_GetState(void);

/* usage:
 * reclaim_block_number = RECL_GetBlock();
 */
WORD RECL_GetBlock(void);

/* usage:
 * status = BKGD_CheckForSpace(command_struct_ptr, data_size, foregnd_flag);
 */
#if (FREE_SPACE_FUNCTIONS == FALSE)
HW_ERROR BKGD_CheckForSpace(COMMAND_PTR, WORD, BYTE);
#endif   /* FREE_SPACE_FUNCTIONS */

#if (INCLUDE_FRAGMENTED_DATA)
/* E.5.3.877 Start */
/* E.5.5.988 Start */
HW_ERROR BKGD_TruncateTable( DWORD, DWORD, DWORD, DWORD, DWORD, IDTYPE,
                            WORD, WORD, BYTE, BYTE, BYTE);
/* E.5.5.988 END */
/* E.5.3.877 END */
#endif

/* usage:
 * status = RIP_Write(data_ptr, header_addr, unit_addr, offset, data_size);
 */
HW_ERROR RIP_Write(BYTE_PTR, DWORD, DWORD, DWORD, WORD);

/* usage:
 * status = RIP_Copy(dest_hdr_addr, dest_unit_addr, src_unit_addr, offset,
 *                   data_size);
 */
HW_ERROR RIP_Copy(DWORD, DWORD, DWORD, DWORD, WORD);

/* usage:
 * status = RIP_SetSpace(header_offset, size, DIRTY_UNITS);
 *
 */
/*Changed SPACE to FDI_SPACE to eliminate porting problems*/
HW_ERROR RIP_SetSpace(DWORD, DWORD, WORD, FDI_SPACE);
HW_ERROR BKGD_ReplaceMulti(BYTE_PTR, DWORD, DWORD, DWORD, DWORD, IDTYPE,
                           WORD, WORD, BYTE, BYTE);

#if(HANDLE_NO_ERASE_COUNT == TRUE)
HW_ERROR HandleEraseCount( void );
#endif /* HANDLE_NO_ERASE_COUNT */


#if (FREE_SPACE_FUNCTIONS == TRUE)
typedef  enum {
   NORMAL_CALCCHK = 0,
   AVLSP_GRAN_CALC_ONLY,
   AVLSP_CALC_AND_CHECK
}  SPACECHECK_CODE;
#define FREE_SPFUN_QPRIORITY     FDI_MIN_PRIORITY
/* E.5.1.759 Begin */
/*
 #define MAX_FRAG_SIZE  (UNIT_GRANULARITY*MAX_NUM_UNITS_PER_FRAG)
 */
/* E.5.1.759 End */
#define MAX_APPGRAN    (MAX_QUEUE_ITEM_SIZE/UNIT_GRANULARITY)

/* E.5.0.584 Begin */
/*Removed the unused defines*/
/*E.5.0.584.End*/
  #define MAX_AVAIL_IDENTIFIERS  (NUM_STREAMS-1)

/* E.5.0.707 Begin */
/* rename the original simulate_accum_free , simulate_accum_dirty*/
/* E.5.6.2.1004 Begin */
extern DWORD SimulateAccumFree;
extern DWORD SimulateAccumDirty;
/* E.5.6.2.1004 End */
/* E.5.0.707 End */
extern HW_ERROR BKGD_CheckForSpace(COMMAND_PTR, WORD, BYTE,
                                     SPACECHECK_CODE);
//extern WORD GetUnitsAvailable ();
extern WORD GetUnitsAvailable (void);

#endif   /* FREE_SPACE_FUNCTIONS */
#define  OBJECT_SIZE    (WORD)(UNIT_GRANULARITY + sizeof(UNIT_HEADER))
/*E.5.0.598.START*/
/*Moved TASK_CREATE_DESTROY and SEM_CREATE_DESTROY to Type.h*/
/*E.5.0.598.END*/

/* E.5.0.690 Begin */
/*move from fdi_ext.h */
#define FIRST_HEADER_OFFSET         0
/* E.5.0.690 End */
#endif                                 /* sentry */


