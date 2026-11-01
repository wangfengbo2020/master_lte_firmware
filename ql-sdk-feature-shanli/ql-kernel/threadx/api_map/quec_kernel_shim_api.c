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
2023/12/20        Sharon.li  此文件是为了裁剪内核实现了一些假的API函数[为了能正常编译]，都是为了成就智慧地球

===========================================================================================================*/


#include "ql_type.h"
#include "ql_audio.h"
#include "ql_tts.h"
#include "ql_ocpu_api.h"
#include "quec_cust_feature.h"
#include "ql_lcd.h"
#include "ql_camera.h"
#include "ql_keypad.h"
#include "ql_rtc.h"
#include "ql_time.h"
#include "ql_power.h"
#include "ql_nw.h"
#include "ql_flash.h"
#include "ql_platform.h"
#include "ql_gnss.h"
#include "ql_fs.h"
#include "ql_bt.h"
#include "ql_sim.h"
#include "ql_kws_pipeline.h"

#if 1//禁止删除此函数,否则会出现意外的效果/*Deletion of this function is prohibited*/
void quec_kernel_api_test(void)
{
	RTI_LOG("Fun:quec_kernel_api_test\r\n");
}
#endif

//客户不想使用AT+Qdownload=1进入下载模式，打开下面函数，内部函数实现会被优化掉
#if 0
void miDownload(void)
{

	return 0;
}
#endif
//音频降噪算法裁剪假实现,如果确实需要降噪算法,则下面不参与编译
#ifndef QL_AUDIO_DENOISE
unsigned int ql_denoise_dsp_get_memory_needed(void)
{
    return 0;
}
void ql_denoise_set_memory_base(void *base, unsigned int total)
{
    return ;
}

void *ql_denoise_init(int sample_rate,float lvl, float drc_post_gain,int datalen)
{      
	return NULL;
}

int ql_denoise_process(void* instance, short* mic, short* out)
{
    return -1;
}
void ql_denoise_cleanup(void *instance)
{
    return ;
}

int ql_denoise_licenses_verify(void)
{
	return -1;
}

void ql_denoise_get_version(char *version )
{
    return;
}

void ql_denoise_mute_time(unsigned int delay_ms)
{
    return;
}

unsigned int mobvoi_dsp_get_memory_needed(void)
{
    return 20;
}

void mobvoi_set_memory_base(void* base, unsigned int total)
{
    return ;
}

void* mobvoi_ql_nndenoise_init(int sample_rate,float lvl, float drc_post_gain,int datalen)
{
	return NULL;
}

int mobvoi_ql_nndenoise_process(void* instance, short* mic, short* out)
{
    return -1;
}


void mobvoi_ql_nndenoise_cleanup(void* instance)
{
	return -1;
}

void mobvoi_get_version(char* version)
{
    return ;
}

void mobvoi_yiyuan_mute_time(unsigned int delay_ms)
{
    return;
}

void ql_denoise_set_vad_lvl(void* instance, int enable, float vad_threshold)
{
    return;
}

void mobvoi_ql_nndenoise_set_vad_lvl(void* instance, int enable, float vad_threshold)
{
	return;
}

int ql_denoise_get_dev_info(unsigned char *dev_info)
{
    return -10;
}
int ql_denoise_save_info_from_app(unsigned char *license_data,int data_len)
{
    return -10;
}

#endif

//KWS语音识别算法裁剪假实现,如果确实需要KWS语音识别算法,则下面不参与编译
#ifndef QL_AUDIO_KWS
unsigned int ql_kws_dsp_get_memory_needed(void)
{
    return 0;
}


void ql_kws_set_memory_base(void *base, unsigned int total)
{
    return ;
}


void *ql_kws_init(void)
{
    return NULL;
}

int ql_kws_process(void* inst,short* mic_in,int len)
{
    return 0;
}


void ql_kws_cleanup(void *inst)
{
    return ;
}


int hal_websocket_start(void)
{
    return 0;
}

void websocket_send_start_signal(void)
{
    return ;
}


void hal_ws_send_write_msg(void *Msg, unsigned int len)
{
    return ;
}



void hal_ws_send_end_write_msg(void )
{
    return ;
}



int ql_set_kws_app_info(kws_app_info_t *kws_app_info)
{
    return 0;
}


unsigned int mobvoi_kws_get_memory_needed(void)
{
    return 0;
}

void mobvoi_kws_set_memory_base(void* base, unsigned int total)
{
    return ;
}

void* mobvoi_kws_online_detect_init(void)
{
    return NULL;
}

int mobvoi_kws_online_detect_process(void* inst,short* mic_in,int len)
{
    return 0;
}


void mobvoi_kws_online_detect_cleanup(void* inst)
{
    return ;
}



#endif

