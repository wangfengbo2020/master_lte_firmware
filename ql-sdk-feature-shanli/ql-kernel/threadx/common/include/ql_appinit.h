/*==========================================================================
 |               Quectel OpenCPU --  User API
 |
 |              Copyright (c) 2010 Quectel Ltd.
 |
 |--------------------------------------------------------------------------
 |
 | File Description
 | ----------------
 |      Definitions for application initialization parameters
 |
 |--------------------------------------------------------------------------
 |
 |  Designed by    :    Jay XIN
 |  Coded by       :    Jay XIN
 |  Tested by      :    Stanley YONG
 |
 \=========================================================================*/

#ifndef __QL_APPINIT_H__
#define __QL_APPINIT_H__
#include "ql_type.h"
#define QL_OPEN_APP_OFFSET  8
typedef struct app_cfg         
{
    u32 debug_mode;
	//add customer conifg here
}app_cfg;

typedef struct sys_info         
{
    u32 heam_size;
    u32 availible_heap_size;
	//add system info here
}sys_info;

typedef struct boot_para          
{
    void *static_maping;
    void *kernel_maping;
}boot_para;

/* Entry Point */
typedef struct {
    void    (*boot)(boot_para *boottime_para);
	void    (*kernel)(void *kerneltime_para);
    void    (*main)(void *runtime_para);
    u32     *app_config;
    u32     *system_infomation;
    u32     data_load_addr;
    u32     data_ram_start;
    u32     data_ram_end;
}ql_open_entry;

#endif  // End-of __QL_APPINIT_H__
