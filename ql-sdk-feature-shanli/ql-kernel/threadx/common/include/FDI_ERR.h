/* ###########################################################################
###  Intel Confidential 
###  Copyright (c) Intel Corporation 1995-2002
###  All Rights Reserved.
###  -------------------------------------------------------------------------
###  Project: Flash Data Integrator 
### 
###  Module: ERROR.H - This module consists of definitions that the OEM needs 
###                    to understand error code returns for API functions. 
### 
###  $Archive: /FDI/SRC/INCLUDE/fdi_err.h $
###  $Revision: 75 $
###  $Date: 5/26/04 7:59a $
###  $Author: Mhprice $
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
 

#ifndef ERROR_H
#define ERROR_H
/* E.5.0.690 Begin */ 
/*remove fdi_type.h */
/* #include "fdi_type.h"*/
/* E.5.0.690 End */ 


typedef enum
{
   ERR_NONE = 0,               /* 0x00 - command was successful */
   ERR_READ,                   /* 0x01 - error reading the flash */
   ERR_WRITE,                  /* 0x02 - error writing to the flash */
   ERR_PARAM,                  /* 0x03 - incorrect parameter to a function */
   ERR_OPEN,                   /* 0x04 - a data has been opened already */
   ERR_EXISTS,                 /* 0x05 - data already exists */
   ERR_NOTEXISTS,              /* 0x06 - data does not exist */
   ERR_SPACE,                  /* 0x07 - no free space left. needs reclaim */
   ERR_NOTOPEN,                /* 0x08 - accessed an unopened data stream */
   ERR_ERASE,                  /* 0x09 - error erasing the flash block */
   ERR_MAX_EXISTS,             /* 0x0A - defined maximum parameter limit */
   ERR_FORMAT,                 /* 0x0B - unformatted media */
   ERR_MEDIA_TYPE,             /* 0x0C - unsupported media type */
   ERR_NOT_DONE,               /* 0x0D - aborted before completion */
   ERR_WRITE_PROTECT,          /* 0x0E - attempt write on protected media */
   ERR_FLASH_FULL,             /* 0x0F - flash media is full */
   ERR_SYSTEM,                 /* 0x10 - system error */
   ERR_MAX_OPEN,               /* 0x11 - tried to open more than maximum
                                *        number of data that can be opened at
                                *        any given time. */
   ERR_INIT,                   /* 0x12 - error during initialization */
   ERR_Q_FULL,                 /* 0x13 - FDI queue is full */
#ifdef LWIP_IPNETBUF_SUPPORT
   ERR_TIME_OUT,               /* 0x14 - system timeout */
#else
   ERR_TIMEOUT,                /* 0x14 - system timeout */
#endif
   ERR_SUSPEND,                /* 0x15 - flash is in program suspended mode. */
   ERR_NOTRDY,                 /* 0x16 - flash device not ready */
   ERR_LOCK,                   /* 0x17 - error while locking */
   ERR_Q_NOT_EMPTY,            /* 0x18 - error while queue is not empty */
   ERR_PCKTID_MUTEX,           /* 0x19 - Try to Operate to packet object when
                                *        it is not finished */
   ERR_WIP,                    /* 0x1A - Indicates that there is already a 
                                *        WIP object */
   ERR_CRASH_N_BURN,           /* 0x1B - not sure what this error code means */
   ERR_NO_MORE_ENTRIES,        /* 0x1C - err code used by DAV internally */
   ERR_PLR_TEST_FAILURE,       /* 0x1D - err code used by DAV PLR */
   ERR_DIFF_SIZE,              /* 0x1E - err code used by DAV Compare Object */
   ERR_NOT_COMPARE,            /* 0x1F - err code used by DAV Compare Object */
   ERR_ACCESS,                 /* 0x20 - file system access error */
   ERR_OPENMODE,               /* 0x21 - file was opened in the wrong mode */
   ERR_EOF,                    /* 0x22 - error return from test gsm if end of 
                                *        file is true */
   ERR_MALLOC,                 /* 0x23 - error code for malloc error */
   ERR_PERF,                   /* 0x24 - error code for perfromance test */
   ERR_MAXITEMSIZE,            /* 0x25 - maximum data size limit reached */ 
   ERR_TRUNCATE,               /* 0x26 -  */
   ERR_STATE,                  /* 0x27 - error in DAV state, indicates a sw bug */
   ERR_NOTHING_TO_DO,          /* 0x28 - nothing to defrag */
   ERR_NOTNEEDED,              /* 0x29 - defrag not needed */
   ERR_NODEFRAGWHILEWIP,       /* 0x2A - can't defrag while WIP object exists */
   ERR_PINNED,                 /* 0x2B - can't deallocate or reallocate a pinned object */
   ERR_SIZENOTAVAIL,           /* 0x2C - unable to provide the requested size */  
   ERR_FILE_NUM_LIMIT,
   ERR_FILE_NAME_LIMIT,
   ERR_FILE_ALREADY_OPEN,
   ERR_FILE_NOT_EXIST,
   ERR_FILE_NO_SPACE,
   ERR_MAX_CODE                /* This entry should always be the
                                * LAST ENTRY in this enum */
}  ERR_CODE;

/* E.5.0.690 Begin */ 
/*moved from fdi_lowl.h */
/* Hardware Error Values */

typedef enum
{
   HW_ERR_NONE = 0,
   HW_ERR_PARAM,
   HW_ERR_READ,
   HW_ERR_WRITE,
   HW_ERR_ERASE,
   HW_ERR_ABORT,
   HW_ERR_JEDEC,
   HW_ERR_EMPTY_LKUP,
   HW_ERR_SPACE,
   HW_ERR_FLASH_FULL,
   HW_ERR_SYSTEM,
   HW_ERR_SUSPEND,
   HW_ERR_DELETE,
   HW_ERR_NOTRDY,
   HW_ERR_LOCK,
   HW_ERR_COMPAT,
/* E 5.1.849 START */   
   HW_ERR_PLR_TEST_FAILURE = 0x1D
/* E 5.1.849 END */   
} HW_ERROR;


/* E.5.0.690 End */ 

/* E.5.0.708 START */
/* change PACKED to FDI_PACKED */
/*****************************ERROR CODE STRUCTURE **************************/
typedef struct
{

   BYTE error_handled;
   BYTE error_code;
   BYTE pad1, pad2;
}
FDI_PACKED(ERROR_INFO);
/* E.5.0.708 END */
#endif
