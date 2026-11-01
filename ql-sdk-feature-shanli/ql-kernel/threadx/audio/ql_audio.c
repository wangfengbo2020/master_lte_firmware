/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file	ql_audio.c
 * @author	august.yang
 * @version V1.0.0
 * @date	2022/04/09
 * @brief	此文件存放audio相关api的封装
 ******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "ql_audio.h"
//#include "quec_audio.h"
#include "quec_track_audio.h"


void ql_set_volume(QL_AUDIOHAL_SPK_LEVEL vol)
{
	quec_set_volume(vol);
}

int ql_get_volume(void)
{
	return quec_get_volume();
}

void ql_bind_speakerpa_cb(ql_cb_on_speakerpa cb)
{
	quec_bind_speakerpa_cb(cb);
}

void ql_set_audio_path_earphone(void)
{
	quec_set_audio_path_to_headset();
}

void ql_set_audio_path_receiver(void)
{
	quec_set_audio_path_to_handset();
}

void ql_set_audio_path_speaker(void)
{
	quec_set_audio_path_to_speaker();
}

int ql_set_dtmf_detect(ql_cb_dtmf_detect cb, int onoff)
{
	return quec_set_dtmf_detect(cb,onoff);
}

int ql_aud_dtmf_play(QL_AUDIOHAL_TONE_TYPE dtmf, int onoff)
{
	return quec_aud_dtmf_play(dtmf, onoff);
}

int ql_aud_tone_play(int f1, int f2, int onoff)
{
	return quec_aud_tone_play(f1, f2, onoff);
}

void ql_codec_choose(codec_choose_state codec_choose, quec_codecpcm_config* pcm_config)
{
	quec_codec_choose(codec_choose, pcm_config);
}

int ql_get_audio_state(void)
{
	return quec_get_audio_state();
}

void ql_set_dtmf_volume(int vo)
{
	quec_set_dtmf_volume(vo);
}

int ql_set_dsp_gain_table(unsigned int profile_id, signed short *gain)
{
	return quec_set_dsp_gain_out(profile_id, gain);
}

void ql_set_txdspgain(signed char gain)
{
	quec_set_txdspgain(gain);
}

signed char ql_get_txdspgain(void)
{
	return quec_get_txdspgain();
}

void ql_set_txcodecgain(short gain)
{
	quec_set_txcodecgain(gain);
}
short ql_get_txcodecgain(void)
{
	return quec_get_txcodecgain();
}

int ql_set_txcodec_gain_table(unsigned int profile_id, unsigned int PGA_Stage1, unsigned int PGA_Stage2, unsigned int diggain)
{
	return quec_set_txcodec_gain_table(profile_id, PGA_Stage1, PGA_Stage2, diggain);
}

int ql_set_rxcodec_gain_table(unsigned int profile_id, signed int level, unsigned int data1,  unsigned int data2, unsigned int data3, unsigned int data4, unsigned int data5)
{
	return quec_set_codec_gain_table(profile_id, level, data1, data2, data3, data4, data5);
}

int ql_set_eqcoeff_table(unsigned int profile_id, signed int tx_rx, unsigned int rate, signed short * data)
{
	return quec_set_eqcoeff_table(profile_id,tx_rx,rate,data);
}

int ql_set_mediave_coeff_table(QL_MediaVEarametersT *AudioMediaVETable){
	return quec_set_mediave_coeff_table(AudioMediaVETable);
}

audio_track_handle ql_audio_track_open(unsigned int rate, unsigned int channels, int64_t option, audio_track_callback event_cb)
{
    return quec_audio_track_open(rate,channels,option,event_cb);
}
int ql_audio_track_write(audio_track_handle handle, uint8_t* data, unsigned int size)
{
    return quec_audio_track_write(handle,  data, size);
}
int ql_audio_track_close(audio_track_handle handle,int force)
{
    return  quec_audio_track_close(handle,force); 
}
int ql_audio_track_ctrl(audio_track_handle handle, acm_audio_track_control_t ctrl_type, int ctrl_value)
{
    return  quec_audio_track_ctrl(handle,ctrl_type,ctrl_value); 
}
audio_record_handle  ql_audio_record_open(unsigned int rate, unsigned int channels, int64_t option, audio_record_callback event_cb)
{
    return quec_audio_record_open(rate, channels, option,event_cb);
}

int ql_audio_record_read(audio_record_handle handle, uint8_t*data, unsigned int*count)
{
    return quec_audio_record_read(handle,data,count);
}

int ql_audio_record_close(audio_record_handle handle,int force)
{
    return  quec_audio_record_close(handle,force);
}
int ql_audio_record_ctrl(audio_record_handle handle, acm_audio_record_control_t ctrl_type, int ctrl_value) 
{
    return  quec_audio_record_ctrl(handle,ctrl_type,ctrl_value);
}

int ql_wav_play(const char* file_name, struct audio_track_config* track_config, audio_track_handle* handle)
{
    return quec_wav_play( file_name,  track_config, handle);
}

int ql_wav_play_stop(audio_track_handle handle,char force)
{
    return quec_wav_play_stop(handle, force);
}
#ifdef  QUEC_MP3_FUNC
int ql_play_mp3(char *file_name,Mp3PlaybackHandle* handle,Mp3PlayConfigInfo* mp3_configInfo)
{
    return quec_mp3_play(file_name,handle,mp3_configInfo); 
}
int ql_play_mp3_stream_buffer(Mp3PlaybackHandle handle,unsigned char *mp3_buff, int mp3_size)
{
    return quec_mp3_stream_play_buffer(handle,mp3_buff,mp3_size);
}
int ql_stop_mp3_play(Mp3PlaybackHandle handle,int drain)
{
    return quec_mp3_play_stop(handle,drain);
}
int ql_mp3_get_pcm_handle(Mp3PlaybackHandle handle, unsigned int* pcm_handle)
{
    return quec_mp3_get_pcm_handle(handle,pcm_handle);
}
int ql_mp3_play_get_duration(const char* file_name, int* duration)
{
    return quec_mp3_play_get_duration(file_name,duration);
}
int ql_mp3_stream_get_duration(Mp3PlaybackHandle handle, Mp3PlayInfoType type, int* value)
{
    return quec_mp3_stream_get_duration(handle, type, value);
}
#endif
#ifdef  QUEC_AMR_FUNC
int ql_play_amr(char *file_name,AmrPlaybackHandle* handle,AmrPlaybackConfigInfo* amr_configInfo)
{
    return quec_amr_play(file_name,handle,amr_configInfo); 
}
int ql_play_amr_stream_buffer(AmrPlaybackHandle handle,unsigned char *amr_buff, int amr_size)
{
    return quec_amr_stream_play_buffer(handle,amr_buff,amr_size);
}
int ql_stop_amr_play(AmrPlaybackHandle handle,int drain)
{
    return quec_amr_play_stop(handle,drain);
}
int ql_amr_get_pcm_handle(AmrPlaybackHandle handle, unsigned int* track_handle)
{
    return quec_amr_get_pcm_handle(handle,track_handle);
}

int ql_record_amr(char *file_name,AmrEncodeHandle* handle,AmrEncConfigInfo* amr_configInfo)
{
    return quec_amr_record(file_name, handle, amr_configInfo);
}
int ql_record_amr_stop(AmrEncodeHandle handle)
{
    return quec_amr_record_stop(handle);
}
#endif
void ql_set_dtmf_volume2(int vo)
{
    ACMAudioSetDTMFVolume(vo);
}

int ql_audio_get_veparam(unsigned short profile, QL_ACMDSP_VEParametersT *out_params)
{
    return ACMCalibration_GetVEParam(profile, out_params);
}

void ql_audio_set_veparam(QL_ACMDSP_VEParametersT *ve_params)
{
    ACMCalibration_ConfigVE((short*)ve_params);
}



