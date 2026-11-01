/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    example_kws.c
 * @author  aidan.jin
 * @version V1.0.0
 * @date    2024/04/03
 * @brief   This file kws audio webcoscket client
 ******************************************************************************
 */

#include "ql_type.h"
#include "ql_func.h"
#include "ql_audio.h"
#include "ql_rtos.h"
#include "ql_application.h"
#include <stdio.h>
#include "ql_gpio.h"
#include "ql_platform.h"
#include "ql_data_call.h"
#include "ql_log.h"
#include "inet.h"
#include "ql_fs.h"
#include "ql_audio.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define QUECTEL_KWS_EN

#ifdef QUECTEL_KWS_EN
#include "ql_kws_pipeline.h"

#define ONCE_SEND_BUFF_LEN 16000
#define SEND_HOW_TIMES 6
#define FRAME_LEN (10)
#define NTP_SERVER_DOMAIN "ntp.aliyun.com"
#define QL_NTP_SUCCESS  0
#define AF_INET 2
#define  SPEECH_TO_TEXT_SIZE 40


typedef enum QL_KWS_type
{
    QL_KWS_MULTI_CMDS = 1,
    QL_KWS_PROCESS_CMD = 160,
} eQL_KWS_type;


//发送账户，每个客户都不相同，详情请联系quectel销售
#define SPEECH_TO_TEXT_TYPE_WAV_APPKEY "EC45F0DA7B84037D6D5403C83F56E7F2"
#define SPEECH_TO_TEXT_TYPE_WAV_APP_SECRET "4DF7753679DF8BDE7472B097B99644F7"



//接受录音数组
char send_audio_buff[ONCE_SEND_BUFF_LEN *SEND_HOW_TIMES] = {0}; 

//处理底层消息控制的信号量
static ql_sem_t g_ql_kws_task_sem = NULL;
static ql_sem_t g_ql_kws_g_delete_sem = NULL;

static void kws_get_ntp_callback(int ntp_status)
{
	printf("========== get ntp status:%d ...ready please speak\r\n", ntp_status);
}


static void ql_kws_nw_status_callback(int profile_idx, int nw_status)
{
	printf("profile(%d) status: %d\r\n", profile_idx, nw_status);
}

static int kws_datacall_satrt(void)
{
	int i=0;
	printf("wait for network register done\r\n");

	while(i<10)
	{
		if(ql_network_register_wait(120) == 0)
		{
			break;
		}
		else 
		{
			i++;
		}		
	}

	if(i>=10)
	{
		printf("*** network register fail ***\r\n");
		return 1;
	}
	
	printf("doing network activing ...\r\n");
	
	ql_wan_start(ql_kws_nw_status_callback);
	ql_set_auto_connect(1, TRUE);
	ql_start_data_call(1, 0, NULL, NULL, NULL, 0);

	return 0;
}


/*处理结果的CB函数*/
static void ql_kws_websocket_process_result_cb(void *arg)
{
    //将结果打印
    char *token = NULL;
    char *yuan  = "元";
    token = strtok(arg,yuan);
    printf("kws_websocket_process_result :%s\n",token);
}

//用于处理底层消息控制的信号量的CB函数
static void  ql_kws_control_websocket_task_destroy_cb(void)
{
    int kws_task_sem_var = -1;
    ql_rtos_semaphore_get_cnt(g_ql_kws_task_sem,&kws_task_sem_var) ;
    if(kws_task_sem_var == 0)
    ql_rtos_semaphore_release(g_ql_kws_task_sem);    
}

//用于处理底层消息控制的信号量的CB函数
static void ql_kws_control_websocket_global_variable_delete_cb(void)
{
    int kws_destroy_sem_var = -1;
    ql_rtos_semaphore_get_cnt(g_ql_kws_g_delete_sem,&kws_destroy_sem_var);
    if(kws_destroy_sem_var == 0)
	ql_rtos_semaphore_release(g_ql_kws_g_delete_sem);
}


void example_kws_web_test(void *arg)
{
	ql_log_mask_set(QL_LOG_APP_MASK,QL_LOG_PORT_USB);
    int ret = 0;
    int status = -1;
    int read_ret = -1, write_ret = -1;
    int kws_task_sem_var = -1;
    int kws_destroy_sem_var = -1;
    int i = 0, j = 0;
    int is_voice = 0;
    unsigned int curr_pp = 0;
    unsigned int PPx = QL_PP5;    
    int sample_rate = 16000;
    int frame_size = sample_rate * FRAME_LEN / 1000;   
    int in_buffer_size = 1 * frame_size;

    int channels = 1;
    int websocket_send_len = 16000;
    int record_len = in_buffer_size * sizeof(short) * 2;
    audio_track_handle kws_track_hd;
    audio_record_handle kws_record_hd;

    //拉高主频加快处理速度
    ql_rtos_task_sleep_s(3);
    curr_pp = ql_cpu_fre_get();
    printf("pre  PP: %d\n", curr_pp);
    ql_cpu_fre_set(PPx); // PP1-PP5
    curr_pp = ql_cpu_fre_get();
    printf("currtnt  PP: %d\n", curr_pp);
    ql_rtos_task_sleep_s(1);
    
    //驻网
    struct ql_data_call_info info = {0};
	char ip4_addr_str[16] = {0};
    if(kws_datacall_satrt()!=0)
    {	
        goto exit;
	}   
    ql_get_data_call_info(1, 0, &info);
    while (info.v4.state == 0)
    {
        printf("wait for ip\r\n");
        ql_rtos_task_sleep_s(5);  
        ql_get_data_call_info(1, 0, &info);
    }
    printf("info.profile_idx: %d\r\n", info.profile_idx);
    printf("info.ip_version: %d\r\n", info.ip_version);
    printf("info.v4.state: %d\r\n", info.v4.state);
    printf("info.v4.reconnect: %d\r\n", info.v4.reconnect);
    inet_ntop(AF_INET, &info.v4.addr.ip, ip4_addr_str, sizeof(ip4_addr_str));
    printf("info.v4.addr.ip: %s\r\n", ip4_addr_str);    
    inet_ntop(AF_INET, &info.v4.addr.pri_dns, ip4_addr_str, sizeof(ip4_addr_str));
    printf("info.v4.addr.pri_dns: %s\r\n", ip4_addr_str);
    inet_ntop(AF_INET, &info.v4.addr.sec_dns, ip4_addr_str, sizeof(ip4_addr_str));
    printf("info.v4.addr.sec_dns: %s\r\n", ip4_addr_str);

    //执行NTP同步时间   发送云端需要时间戳，时间需要准确
    ret = ql_ntp_set_server(NTP_SERVER_DOMAIN);
	printf("========ql_ntp_client set:%d==server %s======== !\n", ret, NTP_SERVER_DOMAIN);
	ret = ql_ntp_set_cid(1);
	if(ret != QL_NTP_SUCCESS)
    {
        printf("ql_ntp_init failed!!\n");
    }   
	printf("========ql_ntp_sync!!===== !\n");
	ql_ntp_sync_ex(kws_get_ntp_callback);

    //等待audio底层初始化完成
    while (!ql_get_audio_state())
    {
        ql_rtos_task_sleep_ms(50);
    }
    printf("pcm test start ...\r\n");    
    ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
	ql_set_audio_path_receiver();
	ql_set_volume(10);
    
    printf("this is websocket test\n");
    kws_track_hd = ql_audio_track_open(sample_rate, channels,0x100,NULL);
    if(kws_track_hd == 0)
    {
        printf("open pcm track error:%d\n",kws_track_hd);
    }
    kws_record_hd = ql_audio_record_open(sample_rate, channels,0,NULL);
    if(kws_record_hd == 0)
    {
        printf("open pcm record error:%d\n",kws_record_hd);
    }

    //申请空间存放一帧采取的音频数据，
    short *mic = malloc(in_buffer_size * sizeof(short)*2);  
    if (mic == NULL )
    {
        printf("Err:mic == NULL \r\n");
        goto exit;
    }
    printf("OK:mic == 0x%x\r\n", mic);
    short *mic_process = malloc(in_buffer_size * sizeof(short));  
    if (mic_process == NULL )
    {
        printf("Err:mic_process == NULL \r\n");
        goto exit;
    }
    printf("OK:mic_process == 0x%x\r\n", mic_process);


    //创建信号量处理底层消息控制
	ql_rtos_semaphore_create(&g_ql_kws_task_sem,1);    
	ql_rtos_semaphore_create(&g_ql_kws_g_delete_sem,1);

    //清收款设置信息接口，appkey/secret /处理结果的cb函数 控制信号量的cb函数
    kws_app_info_t *kws_app_set_info = NULL;
    kws_app_set_info = (kws_app_info_t *)malloc(sizeof(kws_app_info_t));
    if(kws_app_set_info == NULL)
    {
        printf("kws_app_set_info malloc error \n");
        goto exit;
    }
    kws_app_set_info->process_cb = ql_kws_websocket_process_result_cb;
    kws_app_set_info->task_destroy_cb = ql_kws_control_websocket_task_destroy_cb;
    kws_app_set_info->variable_delete_cb = ql_kws_control_websocket_global_variable_delete_cb;
    memcpy(kws_app_set_info->speech_to_text_appkey,SPEECH_TO_TEXT_TYPE_WAV_APPKEY,SPEECH_TO_TEXT_SIZE);
    memcpy(kws_app_set_info->speech_to_text_secret,SPEECH_TO_TEXT_TYPE_WAV_APP_SECRET,SPEECH_TO_TEXT_SIZE);  
    ql_set_kws_app_info(kws_app_set_info);

    //算法需要空间大小申请
    unsigned int mem_needed = 0;
    mem_needed = ql_kws_dsp_get_memory_needed();
    printf("mem_needed %u ...\r\n", mem_needed);
    if (mem_needed <= 0)
    {
        goto exit;
    }
    printf("program run line %d ...\r\n", __LINE__);
    void *ql_memory = malloc(mem_needed);
    printf("OK ql_memory 0x%x ...\r\n", ql_memory);
    if (ql_memory == NULL)
    {
        printf("Err:ql_memory == NULL\r\n");
        return;
    }
    printf("program run line %d ...\r\n", __LINE__);
    ql_kws_set_memory_base(ql_memory, mem_needed);
    printf("program run line %d ...\r\n", __LINE__);

    //算法初始化
    void *inst = ql_kws_init();
    if (inst == NULL)
    {
        printf("Err:inst == NULL\r\n");
        return;
    }
    printf("OK:inst == 0x%x\r\n", inst);

    while (1)
    {   
		ql_rtos_semaphore_get_cnt(g_ql_kws_task_sem,&kws_task_sem_var);
        ql_rtos_semaphore_get_cnt(g_ql_kws_g_delete_sem,&kws_destroy_sem_var);
        if(kws_task_sem_var == 1 && kws_destroy_sem_var == 1)
		{		    
            ql_rtos_semaphore_wait(g_ql_kws_task_sem,QL_WAIT_FOREVER);                
            ql_rtos_semaphore_wait(g_ql_kws_g_delete_sem,QL_WAIT_FOREVER);
			//注册websocket事件
			ql_rtos_task_sleep_s(1);
			if(hal_websocket_start())
			{
				printf("websocket register ok,please speak\n");
			}
			else 
			{
				printf("websocket register error\n");
			}
		}
        //录音
        read_ret = ql_audio_record_read(kws_record_hd, mic,&record_len); 
	    if ((read_ret == 0) && record_len > 0)       
        {
            
            for(j = 0; j < 2 ; j++)
            {
                is_voice = 0;
                memset(mic_process,0,in_buffer_size * sizeof(short));
                memcpy(mic_process,mic + j * in_buffer_size,in_buffer_size * sizeof(short));
                is_voice = ql_kws_process(inst, mic_process, QL_KWS_PROCESS_CMD);
                if(is_voice == 100)
                {   
                    websocket_send_start_signal();                
                    break;
                }
            } 
            //“识别请收款标志位”
    	    if (is_voice == 100)                                            		    
    	    {	
    	        printf("recognition is_voice = %d\n", is_voice);
    			memset(send_audio_buff,0,ONCE_SEND_BUFF_LEN * SEND_HOW_TIMES);
                //连同处理“请收款”这一帧一起送往云端
                hal_ws_send_write_msg((void *)(mic_process) ,in_buffer_size * sizeof(short));
    			//加上标志位或者锁来保证此全局数组不被两个线程同时操作	
    			//每段16k，采集声音，分段发送
    			for(i = 0;i < SEND_HOW_TIMES ;i++)  
    			{                     
    			    while(1)
                    {
                        //录音,每段采集16k
                        websocket_send_len = 16000;
        				read_ret = ql_audio_record_read(kws_record_hd, send_audio_buff + i*ONCE_SEND_BUFF_LEN,&websocket_send_len);        //录音,每段采集16k       
                        if ((read_ret == 0) && websocket_send_len > 0)
                        {
                            hal_ws_send_write_msg((void *)(send_audio_buff + i*ONCE_SEND_BUFF_LEN),ONCE_SEND_BUFF_LEN);
                            break;
                        }
                    }                  
    			}
                
    			hal_ws_send_end_write_msg(); 
    	    } 
            //未识别到“请收款”循环播音 
            write_ret = ql_audio_track_write(kws_track_hd, mic, record_len);   
        }   
                   
    }
exit:
    ql_audio_record_close(kws_record_hd,0);
    ql_audio_track_close(kws_track_hd,0);
    if(mic != NULL)
    {
        free(mic);     
        mic = NULL;
    }
    if(mic_process != NULL)
    {
        free(mic_process);
        mic_process = NULL;
    }
    if(inst != NULL)
    {
        ql_kws_cleanup(inst);
        inst = NULL;
    }
    if (kws_app_set_info != NULL)
    {
        free(kws_app_set_info);
        kws_app_set_info = NULL;
    }
    if(ql_memory!= NULL)
    {
        free(ql_memory); 
        ql_memory = NULL;
    }
    if(g_ql_kws_task_sem != NULL)
    {
        ql_rtos_semaphore_delete(&g_ql_kws_task_sem);
        g_ql_kws_task_sem = NULL;
    }
    if(g_ql_kws_g_delete_sem != NULL)
    {
        ql_rtos_semaphore_delete(&g_ql_kws_g_delete_sem);
        g_ql_kws_g_delete_sem = NULL;
    }
}
 //application_init(example_kws_web_test, "example_kws_web_test", 20, 95);
#endif // DEBUG
