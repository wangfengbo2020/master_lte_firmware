#include <stdio.h>
#include <string.h>
#include "ql_audio.h"
#include "ql_fs.h"
#include "ql_rtos.h"
#include "ql_application.h"
#include "ql_uart.h"

#define FILE_NAME			"huimanfen001.mp3"

#define U_DISK				"U:"
#define U_ROOT_PATH			""U_DISK"/"
#define U_FILE_UNDER_ROOT 	""U_DISK"/"FILE_NAME""

static void list_dir(const char *path)
{
	QDIR * dp = NULL;
	struct lfs_info info = {0};
	int ret;
	
	dp = ql_opendir(path);
	if(dp == NULL)
	{
		printf("[FS] *** dir open fail: %s ***\r\n", path);
		return;
	}
	printf("[FS] dir opened: %s\r\n", path);

	printf("[FS] ----- start dir list -----\r\n");
	printf("[FS] type\tsize\tname\r\n");
	while(1)
	{
		ret = ql_readdir(dp, &info);
		if(ret < 0)
		{
			printf("[FS] *** dir read fail: %s ***\r\n", path);
			break;
		}
		else if(ret == 0)
		{
			printf("[FS] ----- end of dir list -----\r\n");
			break;
		}
		else
		{
			printf("[FS] %-4d\t%-4d\t%s\r\n", info.type, info.size, info.name);
		}
	}

	if(dp)
	{
		ql_closedir(dp);
		printf("[FS] dir closed: %s\r\n", path);
	}
}
int user_file_size;
Mp3PlaybackHandle handle;
Mp3PlayConfigInfo mp3_config;
ql_sem_t  semaRef;
static unsigned int mp3play_stop=0;

//#define QUEC_AUDIO_MP3_STREAM 

static void mp3_cb(Mp3PlayEventType event,int n)
{
switch(event) {

  case MP3_PLAYBACK_EVENT_STATUS:

    if(n == MP3_PLAYBACK_STATUS_STARTED)
    {
         printf("mp3 play start\n");
    }
    if(n == MP3_PLAYBACK_STATUS_ENDED)
    {
         printf("mp3 play end\n");
		 	
#ifdef QUEC_AUDIO_MP3_STREAM
        ql_rtos_semaphore_release(semaRef);   	  
#else
		ql_stop_mp3_play(handle,0); 
		mp3play_stop=0;
#endif		 
           
    }
    if(n == MP3_PLAYBACK_STATUS_OPENED)
    {
         printf("MP3_PLAYBACK_STATUS_OPENED\n");
    }
    if(n == MP3_PLAYBACK_STATUS_FILE_READED)
    {
         printf("MP3_PLAYBACK_STATUS_FILE_READED\n");
    }
    if(n == MP3_STREAM_STATUS_NEARLY_OVERRUN)
    {
         //printf("MP3_STREAM_STATUS_NEARLY_OVERRUN\n");
    }
    if(n == MP3_STREAM_STATUS_NEARLY_UNDERRUN)
    {
        // printf("MP3_STREAM_STATUS_NEARLY_UNDERRUN\n");
    }
    break;
    
  case MP3_FILE_EVENT_ID3OFFSET:
    
    break;

  case MP3_FILE_EVENT_SAMPLERATE:
    
    break;

  case MP3_FILE_EVENT_CHANNEL:
   
    break;

  case MP3_FILE_EVENT_BITRATE: 
    
    break;

  case MP3_FILE_EVENT_FILENAME:
   break;
    
 case MP3_FILE_EVENT_POSITION :
#ifndef QUEC_AUDIO_MP3_STREAM
	printf("MP3_FILE_EVENT_POSITION :%d\n",n);
#endif	
 	break;
  default:
    break;
  }
}

//流播播放时长测试
//粗略计算MP3流播总的时长estimated_duation，以及当前播放时间position，等参数。不支持精准计算
//支持CBR VBR格式MP3
void ql_mp3_time_count(void)
{
	ql_rtos_task_sleep_s(8);
	int offset = 0, frame_count = 0, frame_size = 0, total_frame_count = 0, sample_count = 0, sample_rate = 0,position=0,duration=0;
    int total_size = user_file_size;
	while (1)
	{
		ql_rtos_task_sleep_ms(500);
		if(handle!=NULL)	
		{
			printf("-------get mp3 time conut-----\n");
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_POSITION, &position);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_DURATION, &duration);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_FRAME_OFFSET, &offset);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_FRAME_COUNT, &frame_count);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_FRAME_COUNT_TOTAL, &total_frame_count);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_FRAME_SIZE, &frame_size);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_SAMPLE_COUNT, &sample_count);
			ql_mp3_stream_get_duration(handle, MP3_PLAYBACK_INFO_PCM_RATE, &sample_rate);
			
			if (frame_count > 0) {
				if (total_frame_count == 0) {
					//CBR
					int estimated_duation = (unsigned long long)(total_size - offset) / frame_size * sample_count * 1000 / sample_rate;
					printf("CBR---->position:%ld,duration:%ld, offset:%ld,frame_count:%ld,frame_size:%ld,estimated_duation:%ld\n",position,duration, offset, frame_count, frame_size, estimated_duation);
				}
				else {
					//VBR
					int estimated_duation = (unsigned long long)total_frame_count * sample_count * 1000 / sample_rate;
					printf("VBR----> position:%ld,duration:%ld,offset:%ld,frame_count:%ld,frame_size:%ld,estimated_duation:%ld,sample_count:%ld,sample_rate:%ld\n", position,duration,offset, frame_count, frame_size, estimated_duation,sample_count,sample_rate);
				}
			}
		}
	}
}
void ql_mp3_test(void * argv)
{
    int i=0,ret=0;
	unsigned int heap_size=0,freebuf_size=0;
    int size =0;
    QFILE* fp;
    unsigned char* buffer = malloc(4096);
	mp3_config.listener=mp3_cb;
	mp3_config.sync_mode=0;
	list_dir(U_ROOT_PATH);
    while(!ql_get_audio_state()){
		ql_rtos_task_sleep_ms(50);
	}
    ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
    ql_set_audio_path_receiver();
	ql_set_volume(3);
	ql_rtos_task_sleep_s(7);
#ifdef QUEC_AUDIO_MP3_STREAM
	ql_rtos_semaphore_create(&semaRef, 0);
	while (1)
	{
		fp = ql_fopen(U_FILE_UNDER_ROOT,"rb");
		user_file_size=ql_fsize(fp);
		if(fp == NULL)
		{
			printf("[FS]ERROR!!! *** file open fail: %s ***\r\n", U_FILE_UNDER_ROOT);
		}
		ret = ql_play_mp3(NULL,&handle,&mp3_config);
		printf("ql_play_mp3= %d\r\n",ret);
		while(1)
		{
			size = ql_fread(buffer, 4096, 1, fp);
			printf("size=%d!!\n",size);
			if(size<=0)
			{
				printf("end!!\n");
				ql_stop_mp3_play(handle,1);
				ql_fclose(fp);
				break;
			}
			ql_play_mp3_stream_buffer(handle, buffer, size);
			ql_rtos_task_sleep_ms(20);
		}
		ql_rtos_semaphore_wait(semaRef, QL_WAIT_FOREVER);
		ql_rtos_task_sleep_s(10);
	}
#else
	int duration=0;
	printf("-------get mp3 time conut-----\n");
	//获取文件播放时长测试，在播放文件前调用一次即可，通过回调MP3_FILE_EVENT_POSITION获取当前播放位置
	ql_mp3_play_get_duration(U_FILE_UNDER_ROOT,&duration);
	printf("duration:%ld\n",duration);
	while (1)
	{
		if (!mp3play_stop)
		{
			mp3play_stop = 1;
			ql_play_mp3(U_FILE_UNDER_ROOT,&handle,&mp3_config);
		}
		ql_rtos_task_sleep_ms(500);
	}
	
	
#endif	

}

#define QUEC_AUDIO_MP3_CTRL
#define SERIAL_RX_BUFFER_LEN  2048
static Mp3PlaybackHandle  		mp3_handle;
static Mp3PlayConfigInfo  		mp3_configInfo;
static AmrPlaybackHandle  		amr_handle;
static AmrPlaybackConfigInfo  	amr_configInfo;
static unsigned int mp3pcm_handle=0;
static unsigned int amrpcm_handle=0;
static unsigned int mp3_play_stop=0;
static unsigned int amr_play_stop=0;
static u8 m_RxBuf_Uart1[SERIAL_RX_BUFFER_LEN];

static void quec_main_uart_callback(QL_UART_PORT_NUMBER_E port, void *para)
{
	unsigned int pcm_handle = 0;
	
#ifdef QUEC_AUDIO_MP3_CTRL
	ql_mp3_get_pcm_handle(mp3_handle, &mp3pcm_handle);
	pcm_handle = mp3pcm_handle;
#else
	ql_amr_get_pcm_handle(amr_handle, &amrpcm_handle);
	pcm_handle = amrpcm_handle;
#endif // QUEC_AUDIO_MP3_CTRL
	printf("pcm handle=: %d\n",pcm_handle);
	unsigned int  totalBytes = ql_uart_read(port, m_RxBuf_Uart1, sizeof(m_RxBuf_Uart1));
	if (totalBytes <= 0)
	{
		printf("<-- No data in UART buffer! -->\r\n");
		return;
	}

	if(0 == memcmp(m_RxBuf_Uart1,"AUDIO_TRACK_CTRL_SUSPEND",24)) 
	{
		printf("<-%s -->\r\n",m_RxBuf_Uart1);
		ql_audio_track_ctrl(pcm_handle, AUDIO_TRACK_CTRL_SUSPEND, 0);
		goto end;
	}

	if(0 == memcmp(m_RxBuf_Uart1,"AUDIO_TRACK_CTRL_RESUME",23)) 
	{
		printf("<-%s -->\r\n",m_RxBuf_Uart1);
		ql_audio_track_ctrl(pcm_handle, AUDIO_TRACK_CTRL_RESUME, 0);
		goto end;
	}
	if(0 == memcmp(m_RxBuf_Uart1,"AUDIO_TRACK_CTRL_MUTE_ON",24)) 
	{
		printf("<-%s -->\r\n",m_RxBuf_Uart1);
		ql_audio_track_ctrl(pcm_handle, AUDIO_TRACK_CTRL_MUTE_ON, 0);
		goto end;
	}
	if(0 == memcmp(m_RxBuf_Uart1,"AUDIO_TRACK_CTRL_MUTE_OFF",25)) 
	{
		printf("<-%s -->\r\n",m_RxBuf_Uart1);
		ql_audio_track_ctrl(pcm_handle, AUDIO_TRACK_CTRL_MUTE_OFF, 0);
		goto end;
	}
	if(0 == memcmp(m_RxBuf_Uart1,"AUDIO_TRACK_CTRL_GAIN",21)) 
	{
		printf("<-%s -->\r\n",m_RxBuf_Uart1);
		ql_audio_track_ctrl(pcm_handle, AUDIO_TRACK_CTRL_GAIN, 1000);
		goto end;
	}
	
end:
	ql_uart_write(port,m_RxBuf_Uart1,totalBytes);
	memset(m_RxBuf_Uart1,0,SERIAL_RX_BUFFER_LEN);
	return;
}
#ifdef QUEC_AUDIO_MP3_CTRL
static void ql_Mp3PlaybackEvent(Mp3PlayEventType event, int val)
{
    if(event == MP3_PLAYBACK_EVENT_STATUS){
       if(val == MP3_PLAYBACK_STATUS_STARTED)
       {
            printf("mp3 play start\r\n");
       }
       if(val == MP3_PLAYBACK_STATUS_ENDED)
       {
            printf("mp3 play end\r\n");
            ql_stop_mp3_play(mp3_handle,0);  
			mp3_play_stop = 0;       
       }
    }
}
#else
static void ql_AmrPlaybackEvent(AmrPlaybackEventType event, int val)
{
    if(event == AMR_PLAYBACK_EVENT_STATUS){
       if(val == AMR_FILE_STATUS_STARTED)
       {
            printf("amr play start\r\n");
       }
       if(val == AMR_FILE_STATUS_ENDED)
       {
            printf("amr play end\r\n");
            ql_stop_amr_play(amr_handle,0);  
			amr_play_stop = 0;       
       }
    }
}
#endif // QUEC_AUDIO_MP3_CTRL
void ql_audio_contorl_test(void * argv)
{
	int ret =0;
    // list "U:/"
	list_dir(U_ROOT_PATH);
    while(!ql_get_audio_state()){
		ql_rtos_task_sleep_ms(50);
	}
	ret = ql_uart_open(QL_MAIN_UART_PORT, QL_UART_BAUD_115200, QL_FC_NONE);
	if (ret) 
	{
		printf("open uart[%d] failed! \n", QL_MAIN_UART_PORT);
		return;
	}
    ql_uart_register_cb(QL_MAIN_UART_PORT, quec_main_uart_callback);	//use callback to read uart data

	ql_uart_write(QL_MAIN_UART_PORT,"MAIN_UART_REDY\r\n",16);
    ql_codec_choose(AUD_INTERNAL_CODEC, NULL);
    ql_set_audio_path_receiver();
	ql_set_volume(10);

    printf("quec audio ctrl test start\r\n");

#ifdef QUEC_AUDIO_MP3_CTRL
	mp3_configInfo.listener = ql_Mp3PlaybackEvent;
	while (1)
	{
		if (!mp3_play_stop)
		{
			mp3_play_stop = 1;
			ql_play_mp3("U:/testmp3.mp3",&mp3_handle,&mp3_configInfo);
		}
		ql_rtos_task_sleep_ms(500);
	}
#else
	amr_configInfo.listener = ql_AmrPlaybackEvent;
	while (1)
	{
		if (!amr_play_stop)
		{
			amr_play_stop = 1;
			ql_play_amr("U:/testamr.amr",&amr_handle,&amr_configInfo);
		}
		ql_rtos_task_sleep_ms(500);
	}
#endif // QUEC_AUDIO_MP3_CTRL
}
//application_init(ql_audio_contorl_test, "ql_audio_contorl_test", 10, 2);
application_init(ql_mp3_test, "mp3_test", 10, 2);
application_init(ql_mp3_time_count, "ql_mp3_time_count", 10, 2);


