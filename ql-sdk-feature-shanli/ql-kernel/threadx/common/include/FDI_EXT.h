/* ###########################################################################
###  Intel Confidential 
###  Copyright (c) Intel Corporation 1995-2002
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator
###
###  Module: FDI_EXT.H - This module is the only module the OEM should need to
###                      include to obtain all api interfaces.
###  
###  $Archive: /FDI/SRC/INCLUDE/fdi_ext.h $
###  $Revision: 118 $
###  $Date: 10/14/04 2:05p $
###  $Author: Wtiso $
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
 

#ifndef __FDI_EXT_H                   /* sentry header */
#define __FDI_EXT_H

/* ### Include Files
 * ################################# */
 /* E.5.0.690 Begin */ 
/*remove  fdi_type.h*/
/*#include "fdi_type.h"*/
/* E.5.0.690 End */ 
#include "FDI_INT.h"

/* ### Compile-time Options: 
 * ######################################################################## */

 
/* for Open command */

#define   OPEN_READ           0        /* Open for read only */
#define   OPEN_MODIFY         1        /* Open for edits */
#define   OPEN_CREATE         2        /* Open for write-create only */

/* for Get command */

#define   GET_FIRST           0        /* Get first data */
#define   GET_NEXT            1        /* Get next data */
#define   GET_MATCHED         2        /* Get matching data */

/* for write commands */

#define  WRITE_RESERVED       0        /* reserve space to modify later */
#define  WRITE_APPEND         1        /* append to or create data */
#define  WRITE_REPLACE        2        /* replace current value with new */
#define  WRITE_MODIFY         3        /* modify current value in place */
#define WRITE_TRUNCATE        6

/* for low level command */

#define   FDI_PROGRAM         1        /* Command is program */
#define   FDI_ERASE           2        /* Command is erase */
#define   FDI_COPY            3        /* read from / write to */

/* for priority limits */

#define FDI_MIN_PRIORITY      1        /* Minimum data priority */
#define FDI_MAX_PRIORITY   0x10 /*was 0xFE changed for better performance in queue*/    /* Maximum data priority */

/* E5.0.601 Begin */
#define MIN_DAV_TYPE             FDI_HT_BeginUserTypes
/* E5.0.601 End */

/* Maximum bytes that can be reserved. */
/* E.5.1.759 Begin */
#define MAX_RESERVE_BYTES    (MAX_SEQ_ENTRY * FDI_MAX_FRAG_SIZE )
/* E.5.1.759 End */
/* 
 * query status
 */
#define  FDI_CLEAN               0x0   /* no pending reclamation requests.
                                        * reclamation not in progress.
                                        * queue is empty. */
#define  FDI_RECL_IN_PROG        0x1   /* no pending reclamation requests.
                                        * reclamation is in progress.
                                        * queue is empty. */
#define  FDI_Q_PEND              0x2   /* no pending reclamation requests.
                                        * reclamation not in progress.
                                        * message pending in the queue. */
#define  FDI_RECL_IN_PROG_Q_PEND 0x3   /* no pending reclamation requests.
                                        * reclamation is in progress.
                                        * message pending in the queue. */

#if (DIRECT_ACCESS_VOLUME == TRUE)

/* FDI_ReclLock() tells FMM that it must request a reclaim before proceeding.
   This semaphore protects the shared Flash data from being moved inappropriately */
#define FDI_ReclLock()    \
        (SEM_MTX_WAIT(SEM_DAVReclLock))

/* FDI_ReclUnlock() tells DAV that it does not need to request a reclaim 
   before proceeding */
#define FDI_ReclUnlock()  \
        (SEM_MTX_POST(SEM_DAVReclLock))

/* FDI_ReclPending() Checks to see if DAV is requesting a reclaim.  If 1,
   then reclaim has been requested by DAV. */
#define FDI_ReclPending() \
        (((SEM_TRY_WAIT(SEM_DAVReclRequest))==0)?1:0)
        
/* FDI_ReclWait() Waits for FMM reclaim to complete */
#define FDI_ReclWait()   \
        SEM_WAIT(SEM_DAVReclRequest)

#endif/* (DIRECT_ACCESS_VOLUME == TRUE)*/

/* ### Data Type Definitions:                             
 * ######################################################################## */

/* 
 * identifier to be used for new data stream being created the first time if 
 * choose to let the FDI assign id for the data streams.
 */

#define  NEW_DATA_STREAM_ID       WORDMAX

/* 
 * The following define should be used if choosen not to use 
 * NEW_DATA_STREAM_ID, but choose to assign an id for the data streams 
 */

/*********************** COMMAND CONTROL STRUCTURE *************************/
/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
typedef struct {
   BYTE_PTR buffer_ptr;                /* buffer address */
   DWORD    count;                     /* number of bytes desired */
   DWORD    offset;                    /* beginning offset into the data */
   DWORD    aux;                       /* supplementary field */
   DWORD    actual;                    /* number of actual bytes acted on */ 
   WORD     identifier;                /* unique identity for each data item */
   BYTE     type;                      /* command type: either data or stream*/
   BYTE     priority;                  /* each item is assigned a priority */
   BYTE     sub_command;               /* sub-command expands functionality */
   BYTE     pad1;                  /* Padded for DWORD allignment. */
   BYTE     pad2;                  /* Padded for DWORD allignment. */
   BYTE     pad3;                  /* Padded for DWORD allignment. */
}
FDI_PACKED(COMMAND_CONTROL);
/* E.5.0.708 END */

typedef COMMAND_CONTROL *     CMD_CNTRL_PTR;

/* Block Lock State Enumerations
 */
typedef enum {
   FDI_UNLOCK   = 0, 
   FDI_LOCK     = 1, 
/* E.5.1.812 START */
   FDI_LOCKDOWN_UNLOCK = 2,
/* E.5.1.812 END */   
   FDI_LOCKDOWN = 3
} LOCK_STATUS;


/* ### Global Functions
 * ################################# */

ERR_CODE FDI_Open( CMD_CNTRL_PTR );
/* E.5.0.652 Begin */
ERR_CODE FDI_Close( COMMAND_CONTROL * );
/* E.5.0.652 End */
ERR_CODE FDI_Get( CMD_CNTRL_PTR );
ERR_CODE FDI_Write( CMD_CNTRL_PTR );
/* E.5.0.652 Begin */
ERR_CODE FDI_Delete( COMMAND_CONTROL * );
/* E.5.0.652 End */
ERR_CODE FDI_Read( CMD_CNTRL_PTR );
ERR_CODE FDI_Statistics( DWORD_PTR, DWORD_PTR );
ERR_CODE FDI_ReclaimEnable( void );
ERR_CODE FDI_Status( BYTE_PTR );
ERR_CODE FDI_Format( void );
ERR_CODE FDI_Init( void );
ERR_CODE FDI_GetError ( ERROR_INFO *, DWORD);

#if (ENABLE_PR != FDI_NONE)
ERR_CODE FDI_ReadProtectionRegister(BYTE_PTR, BYTE_PTR, BYTE);
ERR_CODE FDI_WriteProtectionRegister(BYTE_PTR, BYTE, BYTE);
ERR_CODE FDI_ReadProtectionRegisterLock(BYTE_PTR, BYTE);
ERR_CODE FDI_WriteProtectionRegisterLock(BYTE);
#endif  /* ENABLE_PR */

#if ((BLOCK_LOCK_SUPPORT == TRUE) && (ENABLE_NONFDI_BLOCKLOCKING == TRUE))
ERR_CODE FDI_LockBlock(DWORD, BYTE);
ERR_CODE FDI_UnlockBlock(DWORD);
ERR_CODE FDI_ReadLockStatus(DWORD, BYTE_PTR);
#endif /* ENABLE_NONFDI_BLOCKLOCKING */
#if (FREE_SPACE_FUNCTIONS == TRUE)             /* edie added for space function */
#define FDI_AVLSP_MAX_SIZE_PERAPP                                            \
                  ((MAX_APPGRAN < MAX_NUM_UNITS_PER_FRAG ?               \
                  MAX_APPGRAN : MAX_NUM_UNITS_PER_FRAG)*UNIT_GRANULARITY)
extern ERR_CODE FDI_ItemsAvailable (DWORD data_size, WORD_PTR items);
#if (INCLUDE_FRAGMENTED_DATA )
extern ERR_CODE FDI_SizeAvailable (WORD frag_size,DWORD_PTR total_size);
#endif
/* E.5.0.689 START */
extern ERR_CODE FDI_SpaceUsed(WORD identifier, BYTE type, DWORD_PTR spaceused);
/* E.5.0.689 END */
#endif   /* FREE_SPACE_FUNCTIONS */

/*
 *maximum data types allowed 
 */
#define  MAX_TYPE                    14
#define  NUM_STREAMS                (NUM_TYPE0_PARMS + NUM_TYPE1_PARMS + \
                                     NUM_TYPE2_PARMS +\
                                     NUM_TYPE3_PARMS + NUM_TYPE4_PARMS + \
                                     NUM_TYPE5_PARMS + NUM_TYPE6_PARMS + \
                                     NUM_TYPE7_PARMS + NUM_TYPE8_PARMS + \
                                     NUM_TYPE9_PARMS + NUM_TYPE10_PARMS + \
                                     NUM_TYPE11_PARMS + NUM_TYPE12_PARMS + \
                                     NUM_TYPE13_PARMS + NUM_TYPE14_PARMS) 

/* E.5.0.690 Begin */ 
/*move to fdi_int.h */
/*#define FIRST_HEADER_OFFSET         0*/
/* E.5.0.690 End */ 


#endif                                 /* sentry */
