/**
 ******************************************************************************
 * @file    fat32_file_opt.h
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
#ifndef FILE_OPT_H
#define FILE_OPT_H

#include "quec_common.h"
#if QUEC_DUAL_SIM_SUPPORT
#include "teldef.h"
#endif

/******************************************************************************
 *  error code enum 
 ******************************************************************************/
typedef enum
{
    QUEC_FAT_SUCCESS = 0,       /* no error        */
    QUEC_FAT_PARAM_INVALID,     /* param invalid   */
    QUEC_FAT_ERR_OPEN,          /* open failed     */
    QUEC_FAT_ERR_WRITE,         /* write failed    */
    QUEC_FAT_ERR_READ,          /* read failed     */
    QUEC_FAT_FILE_NOT_EXIST,    /* file not exist  */
    QUEC_FAT_FAILED,            /* failed          */
    QUEC_FAT_HEAD_LEN_FLAG_ERROR,
    QUEC_FAT_CRC_ERROR,
}QUEC_FAT_ERR_NUM;
/*===========================================================================

FUNCTION QUEC_NV_FAT_IS_EXIST
DESCRIPTION
  This function get file is exist.

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    TRUE : if file exist.
    FALSE: if file not exist.

SIDE EFFECTS
  None
===========================================================================*/
bool quectel_nv_fat_file_is_exist
(
	const char *file_name
);
/*===========================================================================

FUNCTION QUEC_NV_FAT_WRITE
DESCRIPTION
  This function write data to nv (fat32 fs).

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    utlSUCCESS : if it is a success.
    ERROR_CODE : if it is a failed.

SIDE EFFECTS
  None
===========================================================================*/
int32 quectel_nv_fat_write
(
    const char  *file_name,     /*  file name           */
    void        *write_buf,     /*  write data ptr      */
    size_t       write_size     /*  write data length   */
);
/*===========================================================================

FUNCTION QUEC_NV_FAT_READ
DESCRIPTION
  This function read data from nv (fat32 fs).

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    utlSUCCESS : if it is a success.
    ERROR_CODE : if it is a failed.

SIDE EFFECTS
  None
===========================================================================*/
int quectel_nv_fat_read
(
    const char *file_name,      /* file name         */
    void       *read_buf,       /* read buf ptr      */
    size_t      read_size       /*  read data length */
);

#ifdef QUEC_ADD_FALSH_TEST_SUPPORT
/*===========================================================================
FUNCTION quectel_test_fat_read

DESCRIPTION
  This function write file data to nv (fat32 fs).
  this is no backup and size limit,just test for stress fs opration  ,add by brent

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    QUEC_FAT_SUCCESS : if file write success.
    QUEC_FAT_FAILED: if file write failed.

SIDE EFFECTS
  None
===========================================================================*/
int32 quectel_test_fat_read
(
    const char *file_name,      /* file name         */
    void       *read_buf,       /* read buf ptr      */
    size_t      read_size       /*  read data length */
);

/*===========================================================================

FUNCTION quectel_test_fat_write

DESCRIPTION
  This function write file data to nv (fat32 fs).
  this is no backup and size limit,just test for stress fs opration  ,add by brent

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    QUEC_FAT_SUCCESS : if file write success.
    QUEC_FAT_FAILED: if file write failed.

SIDE EFFECTS
  None
===========================================================================*/
int32 quectel_test_fat_write
(
    const char  *file_name,     /*  file name           */
    void        *write_buf,     /*  write data ptr      */
    size_t       write_size     /*  write data length   */
);

//brent add for internal test operation, no block, just with address receive from at
int quec_test_operation_block(unsigned int flashaddr,unsigned int flashsize,int data,unsigned int disable_protect,int urc_threshold);


#endif


/*===========================================================================

FUNCTION QUEC_NV_FAT_DELETE
DESCRIPTION
  This function dalete data to nv (fat32 fs).

DEPENDENCIES
  None

RETURN VALUE
  possible values:
    utlSUCCESS : if it is a success.
    ERROR_CODE : if it is a failed.

SIDE EFFECTS
  None
===========================================================================*/
int32 quectel_nv_fat_delete
(
    const char *file_name   /*  file name */
);

#ifdef QUEC_FAT_TEST_SUPPORT
int quec_fat_test_destroy(const char *file_name);
int quec_fat_test_recovery(const char *file_name, unsigned int *cnt);
#endif

#if QUEC_DUAL_SIM_SUPPORT
#define QUEC_NV_CGDCONT_INFO  			"quec_nv_cgdcont_info.dat"
#define QUEC_NV_CGDCONT_INFO_MAX_LEN	(QUEC_MAX_CGDCONT_LEN)
#define QUEC_NV_AUTHREQ_INFO  			"quec_nv_authreq_info.dat"
#define QUEC_NV_AUTHREQ_INFO_MAX_LEN	(300)
#define QUEC_MAX_PDP_CTX_NUM            (8) //CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM
#endif

#endif /*  FAT32_FILE_OPT_H */
