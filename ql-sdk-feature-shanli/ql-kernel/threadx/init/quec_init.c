/*==========================================================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
===========================================================================================================*/

/*==========================================================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
09/04/2022        Pony.Ma    此文件服务内核加载APP，进行APP的 RO/RW/BSS的加载和初始化
                              
09/04/200         Sharon.li  在内核跳转APP之前，进行用户fs的挂载和初始化
===========================================================================================================*/

#include "global_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
#include "ptable.h"
#include "ql_ocpu_api.h"
#include "ql_appinit.h"
#include "ql_fs.h"
#include "quec_init.h"


/*----------- External include files -----------------------------------------*/
#if defined(__arm)
#include <locale.h>
#endif
//#include <string.h>


#ifdef QUECTEL_OPEN_CPU 

#define QUEC_OPEN_APP_BACKUP   1        /*APP备份功能 0:关闭，1:开启 */
int quec_app_backup_enable = QUEC_OPEN_APP_BACKUP;
/***********************************************************************
 *
 * Name:       
 *
 * Description: 将app镜像拷贝到执行位置，如果是ramapp则将正ro+rw拷贝到ram_addr
 *              若是xipapp则只会将 rw拷贝到ram_addr
 *
 * Parameters: app_name app分区名；ram_addr appram地址
 *
 * Returns:
 *
 * Notes: 
 *
 ***********************************************************************/
extern int copy_customer_app_from_flash_to_psram(char *app_name,unsigned int ram_addr);
extern char IsFullfota_app(void);
void ql_boot(void);

void ql_app_start_prepare(void)
{
    if(!IsFullfota_app()){
        if(copy_customer_app_from_flash_to_psram("customer_app",(unsigned int)QUECTEL_OPEN_CPU_ENTRY)){
        //uart_printf("file:%s,function:%s,line:%d\r\n", __FILE__,__func__,__LINE__);
        ASSERT(0);
        }
        ql_boot();
    } 
}

void ql_boot(void)
{
	ql_boot_2("customer_app",(unsigned int)QUECTEL_OPEN_CPU_ENTRY);
}



void ql_kernel(void)
{
    _ptentry* partition_entrance = NULL;

    partition_entrance = ptable_find_entry("customer_fs");
    quec_app_log("0x%x , 0x%x",partition_entrance->vstart,partition_entrance->vstart & 0x80000000);
	//挂载文件系统
	if(partition_entrance->vstart >= 0x90000000){
		extern quec_get_extflash_select_port();
	    quec_app_log("SPI FS ADDR:0X%08x SIZE:0x%x",partition_entrance->start,partition_entrance->size);
	    qextfs_init('U', "external_fs", 0, quec_get_extflash_select_port(), partition_entrance->start, partition_entrance->size);
	} else {
        qfs_init(U_DISK_SYM, "customer_fs", 0); 
	}
	#ifndef QUEC_NOAUDIO //增加open项目在fs中配置audio参数文件功能
	extern void ql_update_audio_parameters(void);
	ql_update_audio_parameters();
	#endif
	extern char IsFullfota_app(void);
	if(!IsFullfota_app())
		ql_kernel_2("customer_app",(unsigned int)QUECTEL_OPEN_CPU_ENTRY);
}

void ql_main(void * argv)
{
    ql_main_2("customer_app",(unsigned int)QUECTEL_OPEN_CPU_ENTRY);
    quec_rtos_task_delete_ex(NULL);
}


#endif




