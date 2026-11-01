/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef _QUEC_INIT_H
#define _QUEC_INIT_H

#include "global_types.h"
#include "utilities.h"
#include "ptable.h"
#include "LzmaLib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ql_appinit.h"
#include "quec_spi_nor.h"


#define quec_app_log(msg , ...)     RTI_LOG("[QUEC APP]"msg"", ##__VA_ARGS__)

#define QUECTEL_APP_PARTION_NAME "customer_app"
extern UINT32 Image$$APP_CODE_IN_PSRAM$$Base;
extern UINT32 Image$$DDR_RW_DATA$$Base;
#define QUECTEL_OPEN_CPU_ENTRY      &(Image$$APP_CODE_IN_PSRAM$$Base)
#define QUECTEL_APP_CODE_SIZE       ((int)&(Image$$DDR_RW_DATA$$Base) - (int)&(Image$$APP_CODE_IN_PSRAM$$Base))


typedef enum
{
    QUEC_APP_XIP = 0,
    QUEC_APP_RAM,
    QUEC_APP_LZMA,
    QUEC_APP_EXTERNAL_SPI
}QUEC_APP_MODE;

ql_open_entry* ql_get_ocpu_entry(unsigned int app_image_addr);

void ql_boot_2(char *app_name,unsigned int ram_addr);
void ql_kernel_2(char *app_name,unsigned int ram_addr);
void ql_main_2(char *app_name,unsigned int ram_addr);

#endif

