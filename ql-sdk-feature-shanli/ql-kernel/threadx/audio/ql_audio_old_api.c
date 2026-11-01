
/*兼容旧同步接口*/
/*这些接口灵活性很低不建议客户使用*/
/*在kernel使用接口请自行移植到kernel*/
#include <stdlib.h>
#include <string.h>
#include "ql_audio.h"
#include "ql_audio_old_api.h"
#include "ql_rtos.h"
#include "ql_fs.h"

#define true 1
#define false 0
#define SEEK_SET 0
#define ID_RIFF 	0x46464952
#define ID_WAVE		0x45564157
#define ID_FMT  	0x20746d66
#define ID_DATA 	0x61746164
#define ID_IOS		0x524c4c46//wav data id by IOS
#define QUEC_PCM_BLOCK_FLAG		(0x01)
#define QUEC_PCM_NONBLOCK_FLAG	(0x02)
#define QUEC_PCM_READ_FLAG    	(0x04)
#define QUEC_PCM_WRITE_FLAG		(0x08)
#define AUDIO_PLAY 1
#define AUDIO_RECORD 2

#ifndef QUEC_MP3_FUNC
int ql_play_mp3(char *file_name,Mp3PlaybackHandle* handle,Mp3PlayConfigInfo* mp3_configInfo)
{
    return -1;
}
int ql_play_mp3_stream_buffer(Mp3PlaybackHandle handle,unsigned char *mp3_buff, int mp3_size)
{
    return -1;
}
int ql_stop_mp3_play(Mp3PlaybackHandle handle,int drain)
{
    return -1;
}
int ql_mp3_get_pcm_handle(Mp3PlaybackHandle handle, unsigned int* pcm_handle)
{
    return -1;
}
#endif
#ifndef QUEC_AMR_FUNC
int ql_play_amr(char *file_name,AmrPlaybackHandle* handle,AmrPlaybackConfigInfo* amr_configInfo)
{
    return -1;
}
int ql_play_amr_stream_buffer(AmrPlaybackHandle handle,unsigned char *amr_buff, int amr_size)
{
    return -1;
}
int ql_stop_amr_play(AmrPlaybackHandle handle,int drain)
{
    return -1;
}
int ql_amr_get_pcm_handle(AmrPlaybackHandle handle, unsigned int* track_handle)
{
    return -1;
}

int ql_record_amr(char *file_name,AmrEncodeHandle* handle,AmrEncConfigInfo* amr_configInfo)
{
    return -1;
}
int ql_record_amr_stop(AmrEncodeHandle handle)
{
    return -1;
}
#endif

long long QUEC_2_ASR_AUDIO_TRACK_OPTION(unsigned int flags)
{
    AUDIO_PLAY_OPTION option ;
    long long option1;
    memset(&option,0,sizeof(long long));
    if(QUEC_PCM_BLOCK_FLAG&flags)
    {
        option.write_mode = 1;
    }
    else if(QUEC_PCM_NONBLOCK_FLAG&flags)
    {
        option.write_mode = 0;
    }
    option.active_point = 1;
    memcpy(&option1,&option,sizeof(long long));
    return  option1; 
}
static char is_support_samplerate(unsigned int rate)
{
    switch(rate) {
        case 8000:
        case 16000:
            return true;
        }
	return false;
}

static int check_wav_file(QFILE *fd, aud_input_para_t *para)
{
	int ret = 0,i = 0;
	struct riff_chunk riff_hdr;
	struct format_chunk format_hdr;
	struct data_chunk data_hdr;
	unsigned int chunk_id = 0,chunk_size = 0,chunk_len = 0;
	unsigned int data = 0,data_size = 0;
	
	if(!para)
	{
		return -1;
	}

	ret = ql_fseek(fd, 0, SEEK_SET);
	if(ret < 0)
	{
		return -1;
	}
	ret = ql_fread(&riff_hdr, sizeof(riff_hdr),1,fd);							//riff
	if(ret < sizeof(riff_hdr))
	{
		ql_fseek(fd, 0, SEEK_SET);
		return -1;
	}
	if( (riff_hdr.riff != ID_RIFF) || (riff_hdr.wave!= ID_WAVE))
	{
		return -1;
	}

	for(i = 0;i < riff_hdr.file_size;){										//format
		ql_fread(&chunk_id, sizeof(chunk_id),1,fd);
		if(chunk_id == ID_FMT){
			ql_fread(&format_hdr.format_size, sizeof(unsigned int),1,fd);
			format_hdr.format = chunk_id;
			break;
		}else{
			ql_fread(&chunk_size, sizeof(chunk_size),1,fd);
			i += (chunk_size + 8);
			if(i > riff_hdr.file_size)
				return -1;
			ret = ql_fseek(fd, chunk_size, 1);
			if(ret < chunk_size)
				return -1;
			chunk_len = i;
		}
				
	}
	ql_fread(&format_hdr.aud_fmt, format_hdr.format_size,1,fd);
	// if(is_support_samplerate(format_hdr.sample) == false){
	// 	return -1;
	// }


	for(i = 0;i < (riff_hdr.file_size-chunk_len-format_hdr.format_size);){			//data
		ql_fread(&data, sizeof(data),1,fd);
		if(data == ID_DATA){
			ql_fread(&data_hdr.data_size, sizeof(unsigned int),1,fd);
			data_hdr.data = data;
			break;
		}else{
			ql_fread(&data_size, sizeof(data_size),1,fd);
			i += (data_size + 8);
			if(i > riff_hdr.file_size-chunk_len-format_hdr.format_size)
				return -1;
			ret = ql_fseek(fd, data_size, 1);
			if(ret < data_size)
				return -1;
		}
	}

	switch (format_hdr.bits_sample)
	{
		case 8:
			para->format = QUEC_PCM_FORMAT_S8;
			break;
		case 16:
			para->format = QUEC_PCM_FORMAT_S16_LE;
			break;
		case 24:
			para->format = QUEC_PCM_FORMAT_S24_LE;
			break;
		case 32:
			para->format = QUEC_PCM_FORMAT_S32_LE;
			break;
		default:
			return -1;
	}

	para->rate = format_hdr.sample;
	para->channels = format_hdr.channel;
	para->hsize = 4;
	para->type = AUD_STREAM_FORMAT_PCM;
	para->file_size = data_hdr.data_size;

	return 0;	
}

static int check_mp3_file(QFILE *fd)
{
	int ret = 0;
	char head[10] = {0};

	ret = ql_fseek(fd, 0, SEEK_SET);
	if(ret < 0)
	{
		return -1;
	}

	ret = ql_fread(head, sizeof(head),1,fd);
	if(ret < sizeof(head))
	{
		ql_fseek(fd, 0, SEEK_SET);
		return -1;
	}

	if(memcmp(head, "ID3", 3) == 0)
	{
		return 0;
	}
	else if( (head[0] == 0xFF) && (head[1] & 0xF0) == 0xF0 )
	{
		return 0;
	}
	
	return 1;
}

static int check_amr_file(QFILE *fd, aud_input_para_t *para)
{
	int bytesRead = 0;
	int ret = 0;
	char header[6] = {0};
	ret = ql_fseek(fd, 0, SEEK_SET);
	if(ret < 0)
	{
		return -1;
	}
	// Validate the input AMR file
	bytesRead = ql_fread(header, 6,1,fd);
	if (bytesRead != 6 || memcmp(header, "#!AMR\n", 6)) {
		return -1;
	}

	return 0;
}

int check_audio_format(QFILE *fd, aud_input_para_t *para)
{
	
	if(!check_wav_file(fd, para))
	{
		return AUD_STREAM_FORMAT_PCM;
	}
	else if(!check_mp3_file(fd))
	{
		return AUD_STREAM_FORMAT_MP3;
	}
	else if(!check_amr_file(fd, para))
	{
		return AUD_STREAM_FORMAT_AMR;
	}else{
		return -1;
	}
}

/***********************************************************************
 *
 * Name:       ql_audio_file_play
 *
 * Description: 播放音频文件 ，文件类型可以是mp3，pcm ，wav  异步接口
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes: 
 *
 ***********************************************************************/
static cb_on_player aud_play_cb = NULL;

static Mp3PlaybackHandle  mp3_handle;
static Mp3PlayConfigInfo  mp3_configInfo;
static unsigned char is_mp3_playing = 0;
static audio_track_handle wav_handle;
static AmrPlaybackHandle amr_handle;
static AmrPlaybackConfigInfo amr_config;
static struct audio_track_config wav_config;
static unsigned char is_wav_file_playing;
static unsigned char is_amr_file_playing;

static AmrPlaybackHandle amr_stream_handle;
static AmrPlaybackConfigInfo amr_stream_config;
static unsigned char is_amr_stream_playing = 0;

int ql_audio_play_init(cb_on_player aud_cb)
{
    aud_play_cb = aud_cb;
    return 0;
}

static void wav_play_callback(acm_audio_track_handle handle, acm_audio_track_event_t event)
{
    if(handle == wav_handle)
    {
        if(event == AUDIO_TRACK_EVENT_STARTED)
        {
            is_wav_file_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
        }
        if(event == AUDIO_TRACK_EVENT_CLOSED)
        {
            is_wav_file_playing = 0;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }
        }
    }
    
}
static void ql_Mp3PlaybackEvent(Mp3PlayEventType event, int val)
{
    if(event == MP3_PLAYBACK_EVENT_STATUS){
       if(val == MP3_PLAYBACK_STATUS_STARTED)
       {
            is_mp3_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
       }
       if(val == MP3_PLAYBACK_STATUS_ENDED)
       {
            is_mp3_playing = 0;  
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }        
       }
    }
}

static void ql_amr_palyback_event(AmrPlaybackEventType event, int val)
{
    if(event == AMR_PLAYBACK_EVENT_STATUS){
       if(val == AMR_PLAYBACK_STATUS_STARTED)
       {
            is_amr_file_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
       }
       if(val == AMR_PLAYBACK_STATUS_ENDED)
       {
            is_amr_stream_playing = 0;
            is_amr_file_playing = 0;     
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }     
       }
    }
}
int ql_audio_file_play(char *file_name)
{
    int rc = 0,ret=0;
    QFILE * fd = NULL;
    aud_input_para_t para;
    rc = ql_access(file_name,0);
    if(rc == 0)
    {
        fd = ql_fopen(file_name, "rb");
        if(fd == NULL)
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    ret = check_audio_format(fd, &para);
    ql_fclose(fd);
    if(AUD_STREAM_FORMAT_MP3 == ret)
	{
       if(is_mp3_playing == 1) {
        return -2;
        }
        mp3_configInfo.listener = ql_Mp3PlaybackEvent;
        ql_play_mp3(file_name,&mp3_handle,&mp3_configInfo);
	}
	else if(AUD_STREAM_FORMAT_PCM == ret)
	{
        if(is_wav_file_playing == 1)
        {
           return -2; 
        }
        wav_config.event_cb = wav_play_callback;
		ql_wav_play(file_name,&wav_config,&wav_handle);
	}
	else if(AUD_STREAM_FORMAT_AMR == ret)
	{
        if(is_amr_file_playing == 1)
        {
           return -2; 
        }
        amr_config.listener = ql_amr_palyback_event;
        ret = ql_play_amr(file_name,&amr_handle,&amr_config);
	}

	return ret;
}

int ql_audio_file_stop(void)
{
    if (is_mp3_playing == 1 && mp3_handle)
    {
       ql_stop_mp3_play(mp3_handle,0);
       is_mp3_playing = 0;
    }
    if (is_wav_file_playing == 1 && wav_handle)
    {
       ql_wav_play_stop(wav_handle,1);
       ql_rtos_task_sleep_ms(20);
       is_wav_file_playing = 0;
       wav_handle = 0;
    }
	return 0;
}
/***********************************************************************
 *
 * Name:       ql_play_file_start
 *
 * Description: 播放音频文件 ，文件类型可以是mp3，pcm ，wav ,,同步接口
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes: 
 *
 ***********************************************************************/
static Mp3PlaybackHandle  mp3_handle_sync;
static Mp3PlayConfigInfo  mp3_configInfo_sync;
static unsigned char mp3_sync_playing = 0;

static audio_track_handle wav_handle_sync;
static struct audio_track_config wav_config_sync;
static unsigned char wav_sync_playing = 0;

static AmrPlaybackHandle amr_handle_sync;
static AmrPlaybackConfigInfo amr_config_sync;
static unsigned char amr_sync_playing = 0;

static void wav_sync_play_callback(acm_audio_track_handle handle, acm_audio_track_event_t event)
{
    if(handle == wav_handle)
    {
        if(event == AUDIO_TRACK_EVENT_STARTED)
        {
            wav_sync_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
        }
        if(event == AUDIO_TRACK_EVENT_UNDERRUN)
        {
            wav_sync_playing = 0;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }
        }
    }
    
}
static void mp3_sync_play_callback(Mp3PlayEventType event, int val)
{
    if(event == MP3_PLAYBACK_EVENT_STATUS){
       if(val == MP3_PLAYBACK_STATUS_STARTED)
       {
            mp3_sync_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
       }
       if(val == MP3_PLAYBACK_STATUS_ENDED)
       {
            mp3_sync_playing = 0;  
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }        
       }
    }
}

static void amr_sync_play_callback(AmrPlaybackEventType event, int val)
{
    if(event == AMR_PLAYBACK_EVENT_STATUS){
       if(val == AMR_PLAYBACK_STATUS_STARTED)
       {
            amr_sync_playing = 1;
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_START);
            }
       }
       if(val == AMR_PLAYBACK_STATUS_ENDED)
       {
            amr_sync_playing = 0;     
            if(aud_play_cb)
            {
                aud_play_cb(NULL, 0, AUD_PLAYER_FINISHED);
            }     
       }
    }
}


int ql_play_file_start(char *file_name)
{
    int rc = 0,ret=0;
    QFILE * fd = NULL;
    aud_input_para_t para;
    rc = ql_access(file_name,0);
    if(rc == 0)
    {
        fd = ql_fopen(file_name, "rb");
        if(fd == NULL)
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    ret = check_audio_format(fd, &para);
    ql_fclose(fd);
    if(AUD_STREAM_FORMAT_MP3 == ret)
	{
       if(mp3_sync_playing == 1) {
            return -2;
        }
        mp3_configInfo_sync.listener = mp3_sync_play_callback;
        ret = ql_play_mp3(file_name,&mp3_handle_sync,&mp3_configInfo_sync);
        do
        {
            ql_rtos_task_sleep_ms(50);
        } while (mp3_sync_playing); 
	}
	else if(AUD_STREAM_FORMAT_PCM == ret)
	{
        if(wav_sync_playing == 1)
        {
           return -2; 
        }
        wav_config_sync.event_cb = wav_sync_play_callback;
		ret = ql_wav_play(file_name,&wav_config_sync,&wav_handle_sync);
        do
        {
            ql_rtos_task_sleep_ms(50);
        } while (wav_sync_playing); 
	}
	else if(AUD_STREAM_FORMAT_AMR == ret)
	{
        if(amr_sync_playing == 1)
        {
           return -2; 
        }
        amr_config_sync.listener = amr_sync_play_callback;
        ret = ql_play_amr(file_name,&amr_handle_sync,&amr_config_sync);
        do
        {
            ql_rtos_task_sleep_ms(50);
        } while (amr_sync_playing); 
	}

    return ret;
}

int ql_play_file_stop(void)
{
	return 0;
}



int ql_wav_file_play(char *file_name)
{
    if(!file_name){
		return -1;
	}
    if(is_wav_file_playing == 1)
    {
       return -2; 
    }
    wav_config.event_cb = wav_play_callback;
	wav_config.prepare_threshold = 64;
    return ql_wav_play(file_name,&wav_config,&wav_handle); 
}

void ql_wav_file_stop(void)
{
    ql_wav_play_stop(wav_handle,1);
}

int ql_mp3_file_play(char *file_name)
{
     if(!file_name){
		return -1;
	}
	
    if(is_mp3_playing == 1) {
        return -2;
    }
    mp3_configInfo.listener = ql_Mp3PlaybackEvent;
    return ql_play_mp3(file_name,&mp3_handle,&mp3_configInfo);
}

void ql_mp3_file_stop(void)
{
    ql_stop_mp3_play(mp3_handle,0);
}


static int ql_amr_file_play_type = 0;
int ql_amr_file_play(char *file_name)
{
     if(!file_name){
		return -1;
	}
	
    if(is_amr_file_playing == 1) {
        return -2;
    }
    ql_amr_file_play_type = 0;
    amr_config.listener = ql_amr_palyback_event;
    return ql_play_amr(file_name,&amr_handle,&amr_config);
}

int ql_amr_file_play2(const char *data, unsigned int size)
{
    int ret = -1;
    if(is_amr_stream_playing == 0) 
    {
        amr_config.listener = ql_amr_palyback_event;
	    ql_play_amr(NULL,&amr_stream_handle,&amr_stream_config);
        is_amr_stream_playing = 1;
        ql_amr_file_play_type = 1;
        ret = ql_play_amr_stream_buffer(amr_stream_handle,(unsigned char *)data, size);
        if (ret == 0)
        {
            ret = ql_stop_amr_play(amr_stream_handle,1);//播缓存，等待结束事件
        }
    }
    return ret;
}

void ql_amr_file_stop(void)
{
    if (ql_amr_file_play_type == 0)//文件播放调用播文件句柄
    {
        ql_stop_amr_play(amr_handle,0);
    }
    else
    {
        ql_amr_file_play_type = 0;
        if (is_amr_stream_playing)
        {
            is_amr_stream_playing = 0;
            ql_stop_amr_play(amr_stream_handle,0);
        }
    }
}

static AmrEncodeHandle record_amr_handle;
static AmrEncConfigInfo record_amr_config;
int ql_record_amr_file_start(char *file_name)
{
     if(!file_name){
		return -1;
	}
	return ql_record_amr(file_name, &record_amr_handle , &record_amr_config);
}
 
void ql_record_amr_file_stop(void)
{
    ql_record_amr_stop(record_amr_handle);
}



/***********************************************************************
 *
 * Name:       
 *
 * Description: 播放音频文件 ，文件类型可以是mp3，pcm ，wav
 *
 * Parameters:
 *
 * Returns:
 *
 * Notes: 
 *
 ***********************************************************************/
 /*尾插单链表*/
 typedef struct Node {
     unsigned int data;
     struct Node* next;
 } Node;
 // 初始化一个空链表
Node* initializeList() {
    return NULL;
}
// 在链表末尾插入一个新节点
Node* insertNode(Node* head, unsigned int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// 删除链表中第一个匹配给定数据的节点
Node* deleteNode(Node* head, unsigned int data) {
    if (head == NULL) {
        return NULL; // 空链表，无需删除
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return head;
}

PCM_HANDLE_T findList(Node* head , unsigned int handle) {
    Node* current = head;
    PCM_HANDLE_T quec_audio_handle = NULL;
    while (current != NULL) {
        quec_audio_handle = (PCM_HANDLE_T)current->data;
        if(quec_audio_handle->handle == handle)
        {
            break;
        }
        else
        {
            quec_audio_handle = NULL;
        }
        current = current->next;
    }
    return quec_audio_handle;
}

// 释放链表内存
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
 Node* pcm_hadle_list;
#define PCM_END_FLAG   0x1
 char record_work_mode=0;
 char list_created = 0;
 void OLD_pcm_play_callback(acm_audio_track_handle handle, acm_audio_track_event_t event)
 {
    PCM_HANDLE_T quec_audio_handle = findList(pcm_hadle_list , (unsigned int)handle);
    if(quec_audio_handle){
        if(event == AUDIO_TRACK_EVENT_CLOSED)
            ql_rtos_flag_release(quec_audio_handle->pcm_stream_flag,PCM_END_FLAG, QL_FLAG_OR);
    }
    
 }

PCM_HANDLE_T ql_pcm_open(QL_PCM_CONFIG_T *config, unsigned int flags)
{
    PCM_HANDLE_T quec_audio_handle = malloc(sizeof(ql_pcm_hadle_t));
    long long option = 0;
    if (flags&QUEC_PCM_WRITE_FLAG) 
    {
        if(list_created)
        {
            list_created=1;
            pcm_hadle_list=initializeList();
        }
        pcm_hadle_list = insertNode(pcm_hadle_list, (unsigned int)quec_audio_handle);
        ql_rtos_flag_create(&(quec_audio_handle->pcm_stream_flag));
        quec_audio_handle->record_or_play = AUDIO_PLAY;
        option = QUEC_2_ASR_AUDIO_TRACK_OPTION(flags);
        quec_audio_handle->handle = ql_audio_track_open(config->samplerate, config->channels,option, OLD_pcm_play_callback);
    }
    else if(flags&QUEC_PCM_READ_FLAG)
    {
        if(flags&QUEC_PCM_BLOCK_FLAG)
            record_work_mode = 1;
        else 
            record_work_mode = 0;
        quec_audio_handle->record_or_play = AUDIO_RECORD;
         quec_audio_handle->handle = ql_audio_record_open(config->samplerate, config->channels, option,NULL);
    }
    return (PCM_HANDLE_T)quec_audio_handle;
}

int ql_pcm_read(PCM_HANDLE_T handle, void *data, unsigned int count)
{
    ql_pcm_hadle_t *quec_audio_handle = handle;
    int ret = -1,CNT=0;
    unsigned int count1=0;
    if(count == 0 || data == NULL)
        return ret;
    count1 = count;
    if(record_work_mode == 1)/*由于asr的录音不带阻塞模式，故在此增加阻塞*/
    {
        while(ret&&CNT<10){
            count1 = count;
            ret = ql_audio_record_read(quec_audio_handle->handle,  data, &count1);
            ql_rtos_task_sleep_ms(5);
            CNT++;
        }
        if(ret<0)
            count1 = 0; 
    }
    else
    {
        ret = ql_audio_record_read(quec_audio_handle->handle,  data, &count1);
        if(ret<0)
            count1 = 0; 
    }

    return count1;
}

int ql_pcm_write(PCM_HANDLE_T handle, void *data, unsigned int count)
{
    int ret = 0;
    int temp_cnt = 0;

    temp_cnt = count;
    ql_pcm_hadle_t *quec_audio_handle = handle;
    ret = ql_audio_track_write(quec_audio_handle->handle,  data, count);
    if (ret == 0)
    {
        return temp_cnt;
    }
    else
    {
        return 0;
    }
}

int ql_pcm_close(PCM_HANDLE_T handle) 
{
    ql_pcm_hadle_t *quec_audio_handle = handle;
    int ret = 0;
    u32 flags = 0;
    if(quec_audio_handle->record_or_play==AUDIO_PLAY)
    {
        ret = ql_audio_track_close(quec_audio_handle->handle,1);
        ql_rtos_task_sleep_ms(20);
        // ql_rtos_flag_wait(quec_audio_handle->pcm_stream_flag, PCM_END_FLAG, QL_FLAG_OR_CLEAR, &flags, 0xFFFFFFFF);
        pcm_hadle_list = deleteNode(pcm_hadle_list, (unsigned int)quec_audio_handle);
        ql_rtos_flag_delete(quec_audio_handle->pcm_stream_flag);
    }
    else if(quec_audio_handle->record_or_play==AUDIO_RECORD)
    {
        ret = ql_audio_record_close(quec_audio_handle->handle,1);
    }
    else 
    {
        ret = -1;
    }
    
    free(quec_audio_handle);
    return ret;
}
cb_on_player ql_pcm_play_cb;
audio_track_handle track_handle = 0;

static void pcm_play_callback(acm_audio_track_handle handle, acm_audio_track_event_t event)
{
    enum_aud_player_state ql_aug_event = AUD_PLAYER_ERROR;
    if(handle == track_handle)
    {
        if(event == AUDIO_TRACK_EVENT_STARTED)
        {
             if(ql_pcm_play_cb)
                ql_pcm_play_cb(NULL,0,AUD_PLAYER_START);
        }
        if(event == AUDIO_TRACK_EVENT_UNDERRUN)
        {
            if(ql_pcm_play_cb)
                ql_pcm_play_cb(NULL,0,AUD_PLAYER_NODATA);
        }
        if(event == AUDIO_TRACK_EVENT_NEARLY_OVERRUN)
        {
            if(ql_pcm_play_cb)
                ql_pcm_play_cb(NULL,0,AUD_PLAYER_MOREDATA);
        }
        if(event == AUDIO_TRACK_EVENT_NEARLY_UNDERRUN)
        {
            if(ql_pcm_play_cb)
                ql_pcm_play_cb(NULL,0,AUD_PLAYER_LESSDATA);
        }
       
    }
}


int ql_pcm_play_init(cb_on_player play_cb)
{
   ql_pcm_play_cb=play_cb;
   return 0;
}
int ql_pcm_play(int hdl, unsigned char *buffer, int wav_size)
{
    track_handle = ql_audio_track_open(8000, 1,0, pcm_play_callback);
    return ql_audio_track_write(track_handle, buffer, wav_size);
}

int ql_pcm_play_stop(int hdl)
{
    return ql_audio_track_close(track_handle,0);
}

int ql_pcm_play_deinit(int hdl)
{
    ql_pcm_play_cb=0;
    return 0;
}


