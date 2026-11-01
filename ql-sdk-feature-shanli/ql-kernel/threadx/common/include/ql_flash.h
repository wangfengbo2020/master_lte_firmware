/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _QL_FLASHRW_H_
#define _QL_FLASHRW_H_

#define FLASH_RW_ERROR     -1

extern void ql_norflash_get_addr(unsigned char *patition_name, unsigned int *start_addr, unsigned int *size);

extern unsigned int ql_norflash_do_read(unsigned char *patition_name, unsigned int addr, unsigned int buf_addr, unsigned int size);

extern unsigned int ql_norflash_do_write(unsigned char *patition_name, unsigned int addr, unsigned int buf_addr, unsigned int size);

extern int ql_norflash_do_erase(unsigned char *patition_name, unsigned int addr, unsigned int size);

extern int ql_norflash_read_id(void);
#endif