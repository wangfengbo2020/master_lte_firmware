/**
 ******************************************************************************
 * @file    mrd_file_opt.h
 * @author  West.Wang
 * @version V1.0.0
 * @date    16-Oct-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */
#ifndef MRD_FILE_OPT_H
#define MRD_FILE_OPT_H

#include "quec_common.h"
#include "MRD.h"
/******************************************************************************
 *  macro define 
 ******************************************************************************/
#define mrd_log(msg, ...)   custom_log("MRD", msg, ##__VA_ARGS__) /* debug    */
#define CDF_FILE_FULL_NAME  "www\\temp\\cdfnvmfile"  /* rdisk tmp file        */  

#define QUEC_CUSTOMER_FILE_NAME "ql_custer_data.bin"
#define QUEC_MRD_CD_TYPE  0xA5A50001
#define QUEC_CUSTOMER_AREA_MAX_SIZE 30
/******************************************************************************
 *  file handle description
 ******************************************************************************/
typedef struct {
    int32  file_version;    /* file version     */
    int32  file_type;       /* file type        */
    int32  file_date;       /* file date        */
} quec_mrd_file_handle, *quec_mrd_file_handle_t;

/*===========================================================================

FUNCTION QUEC_MRD_IS_FILE_EXIST
DESCRIPTION
  This function is file exist.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : file exist.
    FALSE: file not exist.

SIDE EFFECTS
  None
===========================================================================*/
bool quec_mrd_is_file_exist
(
    int8                   *file_name,      /* file name        */
    quec_mrd_file_handle_t  file_handler    /*  file handler    */
);

/*===========================================================================

FUNCTION QUEC_MRD_READ
DESCRIPTION
  This function is read data from mrd.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if it is a success execute.
    FALSE : if it is a failed execute.

SIDE EFFECTS
  None
===========================================================================*/
int32 quec_mrd_read
(
    int8                   *file_name,      /* file name        */
    int8                   *read_buf,       /* read buf         */    
    uint32                  read_size,      /* read size        */
    quec_mrd_file_handle_t  file_handler    /* file handler     */
);
/*===========================================================================

FUNCTION QUEC_MRD_WRITE
DESCRIPTION
  This function is write data to mrd.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if it is a success execute.
    FALSE : if it is a failed execute.

SIDE EFFECTS
  None
===========================================================================*/
int32 quec_mrd_write
(
    int8                   *file_name,      /* file name        */
    int8                   *write_buf,      /* write buf        */
    uint32                  write_size,     /* write size       */
    quec_mrd_file_handle_t  file_handler    /* file handler     */
);
/*===========================================================================

FUNCTION QUEC_MRD_DELETE
DESCRIPTION
  This function is delete data from mrd.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if it is a success execute.
    FALSE : if it is a failed execute.

SIDE EFFECTS
  None
===========================================================================*/
int32 quec_mrd_delete
(
    int8                   *file_name,          /* file name       */
    quec_mrd_file_handle_t  file_handler        /* file handler    */
);
/*===========================================================================

FUNCTION QUEC_BACKUP_MRD
DESCRIPTION
  This function is backup mrd1 data to mrd2.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if it is a success execute.
    FALSE : if it is a failed execute.

SIDE EFFECTS
  None
===========================================================================*/
int32 quec_backup_mrd(void);
/*===========================================================================

FUNCTION QUEC_RESTORE_MRD
DESCRIPTION
  This function is restore data from mrd2 to mrd1.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if it is a success execute.
    FALSE : if it is a failed execute.

SIDE EFFECTS
  None
===========================================================================*/
int32 quec_restore_mrd(void);

#endif /*  MRD_FILE_OPT_H */