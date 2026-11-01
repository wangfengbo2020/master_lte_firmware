/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file	quec_track_audio.h
 * @author	pony.ma
 * @version V1.0.0
 * @date	2022/06/19
 * @brief	audio interface driver header file
 ******************************************************************************
 */

#ifndef _QUEC_TRACK_AUDIO_H
#define _QUEC_TRACK_AUDIO_H
#include "acm_audio_track.h"
#include "acm_audio_record.h"
#include "mp3dec_api.h"
#include "amr_vocoder_api.h"
#include "audio_bind.h"
#include "stdbool.h"
typedef enum
{
	QUEC_PCM_CODEC_SAMPLE_8000 = 8000,
	QUEC_PCM_CODEC_SAMPLE_16000 = 16000,
	QUEC_PCM_CODEC_SAMPLE_32000 = 32000,
	QUEC_PCM_CODEC_SAMPLE_48000 = 48000,
}pcm_codec_sample;
typedef enum
{
	QUEC_PCM_FS_32,
	QUEC_PCM_FS_64,
	QUEC_PCM_FS_128,
	QUEC_PCM_FS_256,
	QUEC_PCM_FS_512,
	QUEC_PCM_FS_1024,
	QUEC_PCM_FS_2048,
	QUEC_PCM_FS_MAX,
}pcm_bclk;
typedef struct quec_codecpcm_config
{
	pcm_bclk pcmbclk;
	pcm_codec_sample sample;
}quec_codecpcm_config;

typedef enum
{
    QUEC_AUD_INTERNAL_CODEC,
    QUEC_AUD_EXTERNAL_CODEC,
}codec_choose_state;

typedef enum
{
    QUEC_AUDIOHAL_DTMF_0 = 0,
    QUEC_AUDIOHAL_DTMF_1,
    QUEC_AUDIOHAL_DTMF_2,
    QUEC_AUDIOHAL_DTMF_3,
    QUEC_AUDIOHAL_DTMF_4,
    QUEC_AUDIOHAL_DTMF_5,
    QUEC_AUDIOHAL_DTMF_6,
    QUEC_AUDIOHAL_DTMF_7,
    QUEC_AUDIOHAL_DTMF_8,
    QUEC_AUDIOHAL_DTMF_9,
    QUEC_AUDIOHAL_DTMF_A,
    QUEC_AUDIOHAL_DTMF_B,
    QUEC_AUDIOHAL_DTMF_C,
    QUEC_AUDIOHAL_DTMF_D,
    QUEC_AUDIOHAL_DTMF_S,        //* key
    QUEC_AUDIOHAL_DTMF_P,        //# key
    QUEC_AUDIOHAL_COMFORT_425,
    QUEC_AUDIOHAL_COMFORT_950,
    QUEC_AUDIOHAL_COMFORT_1400,
    QUEC_AUDIOHAL_COMFORT_1800,
} QUEC_AUDIOHAL_TONE_TYPE;
//version
typedef struct
{
	char file_type[64];
	unsigned int version;
	unsigned int reserve_1;
	unsigned int reserve_2;
} QUEC_ACMAudio_HEAD;

typedef enum
{
	MUTE_ERR_NO,	
	MUTE_ERR_PARAMETER,	//参数错误
	MUTE_ERR_TIMEOUT,	//超时未等到通话
	MUTE_ERR_NO_VOICECALL,//未发现通话请求
}QUEC_Mute_Err;

typedef enum
{
	TWO_WAY,
	PHONE_TO_MODULE,
	MODULE_TO_PHONE,
}QUEC_Mute_VoiceCall;

typedef void (*cb_on_speakerpa) (unsigned int on);

#ifdef QUEC_AUDIO_DENOISE
bool ql_get_denoise_flag(void);
void ql_set_denoise_flag(bool onoff);
#endif

audio_track_handle quec_audio_track_open(unsigned int rate, unsigned int channels, int64_t option, audio_track_callback event_cb);
int quec_audio_track_write(audio_track_handle handle, uint8_t* data, unsigned int size);
int quec_audio_track_close(audio_track_handle handle,int force);
int quec_audio_track_ctrl(audio_track_handle handle, acm_audio_track_control_t ctrl_type, int ctrl_value);
audio_record_handle  quec_audio_record_open(unsigned int rate, unsigned int channels, int64_t option, audio_record_callback event_cb);
int quec_audio_record_read(audio_record_handle handle, uint8_t*data, unsigned int* count);
int quec_audio_record_close(audio_record_handle handle,int force);
int quec_audio_record_ctrl(audio_record_handle handle, enum audio_record_control ctrl_type, int ctrl_value); 
int quec_wav_play(const char* file_name, struct audio_track_config* track_config, audio_track_handle* handle);
int quec_wav_play_stop(audio_track_handle handle,char force);
void quec_set_audio_path_to_handset(void);
int quec_get_audio_state(void);
void quec_codec_choose(codec_choose_state codec_choose, quec_codecpcm_config* pcm_config);
int quec_get_volume(void);
void quec_set_volume(char vol);
int quec_mp3_play(char *file_name,Mp3PlaybackHandle* handle,Mp3PlayConfigInfo* mp3_configInfo);
int quec_mp3_stream_play_buffer(Mp3PlaybackHandle handle,unsigned char *mp3_buff, int mp3_size);
int quec_mp3_play_stop(Mp3PlaybackHandle handle,int drain);
int quec_mp3_get_pcm_handle(Mp3PlaybackHandle handle, unsigned int* pcm_handle);
int quec_set_dtmf_detect(DTMFDetectionHandler_t cb, int onoff);
int quec_set_far_mode(int farend);
int quec_aud_tone_play(int f1, int f2, int onoff);
int quec_aud_dtmf_play(QUEC_AUDIOHAL_TONE_TYPE tone, int onoff);
void quec_bind_speakerpa_cb(cb_on_speakerpa cb);
void quec_set_audio_path_to_headset(void);
void quec_set_audio_path_to_speaker(void);
void quec_set_dtmf_volume(int vo);
int quec_amr_play(char* file_name,AmrPlaybackHandle* handle,AmrPlaybackConfigInfo* amr_config);
int quec_amr_stream_play_buffer(AmrPlaybackHandle handle,unsigned char *amr_buff, int amr_size);
int quec_amr_play_stop(AmrPlaybackHandle handle,int drain);
int quec_amr_get_pcm_handle(AmrPlaybackHandle handle, unsigned int* track_handle);
int quec_amr_record(char* file_name,AmrEncodeHandle* handle,AmrEncConfigInfo* config);
int quec_amr_record_stop(AmrEncodeHandle handle);



#endif

