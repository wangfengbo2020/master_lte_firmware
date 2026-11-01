/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file	ql_audio.h
 * @author	august.yang
 * @version V1.0.0
 * @date	2022/04/09
 * @brief	Audio interface header file creation
 ******************************************************************************
 */
#ifndef _QL_AUDIO_H_
#define _QL_AUDIO_H_
#include "acm_audio_track.h"
#include "acm_audio_record.h"
#include "quec_track_audio.h"

#define ACM_RATE_CNT     2  	//voice enhancement rate number

  typedef enum
  {
      AUDIOHAL_DTMF_0 = 0,
      AUDIOHAL_DTMF_1,
      AUDIOHAL_DTMF_2,
      AUDIOHAL_DTMF_3,
      AUDIOHAL_DTMF_4,
      AUDIOHAL_DTMF_5,
      AUDIOHAL_DTMF_6,
      AUDIOHAL_DTMF_7,
      AUDIOHAL_DTMF_8,
      AUDIOHAL_DTMF_9,
      AUDIOHAL_DTMF_A,
      AUDIOHAL_DTMF_B,
      AUDIOHAL_DTMF_C,
      AUDIOHAL_DTMF_D,
      AUDIOHAL_DTMF_S,        //* key
      AUDIOHAL_DTMF_P,        //# key
      AUDIOHAL_COMFORT_425,
      AUDIOHAL_COMFORT_950,
      AUDIOHAL_COMFORT_1400,
      AUDIOHAL_COMFORT_1800,
  } QL_AUDIOHAL_TONE_TYPE;
 
  typedef enum
  {
      AUDIOHAL_SPK_MUTE         = 0,
      AUDIOHAL_SPK_VOL_1,
      AUDIOHAL_SPK_VOL_2,
      AUDIOHAL_SPK_VOL_3,
      AUDIOHAL_SPK_VOL_4,
      AUDIOHAL_SPK_VOL_5,
      AUDIOHAL_SPK_VOL_6,
      AUDIOHAL_SPK_VOL_7,
      AUDIOHAL_SPK_VOL_8,
      AUDIOHAL_SPK_VOL_9,
      AUDIOHAL_SPK_VOL_10,
      AUDIOHAL_SPK_VOL_11,    // 11
  
      AUDIOHAL_SPK_VOL_QTY    // 12
  } QL_AUDIOHAL_SPK_LEVEL;
 
  typedef enum
  {
      PCM_FS_32,
      PCM_FS_64,
      PCM_FS_128,
      PCM_FS_256,
      PCM_FS_512,
      PCM_FS_1024,
      PCM_FS_2048,
      PCM_FS_MAX,
  }ql_pcm_bclk;
 
  typedef enum
  {
      PCM_CODEC_SAMPLE_8000 = 8000,
      PCM_CODEC_SAMPLE_16000 = 16000,
      PCM_CODEC_SAMPLE_32000 = 32000,
      PCM_CODEC_SAMPLE_48000 = 48000,
  }ql_pcm_codec_sample;
 
 typedef struct
 {	  
	 unsigned short  drcGain;
	 unsigned short  cutOffFreqIdx;
	 unsigned short  resv1;
	 unsigned short  resv2;
	 
 } QL_MediaDRCParaT;
 
 typedef struct
 {	  
	 unsigned short  maxRms;
	 unsigned short  Alpha;
	 unsigned short  N2cos;
	 unsigned short resv;
	 
 } QL_SPKProParaT;

 typedef struct
 {
	 short a[3];	// a[0], a[1], a[2]
	 short b[3];   // b[0], b[1], b[2]
 } QL_BiQuadCoeffsStruct;
 
 typedef struct
 {
	 unsigned short BiquadEnControl;	 //bit 0 ~bit 4 is on/off of each filter.
	 //unsigned short reserved0;
	 //short	 reserve1;
	 QL_BiQuadCoeffsStruct Tuningmem[5];	 //get from user input or read workspace log
 }QL_EqParamIn;

 typedef struct
 {	  
	 unsigned int	 index;
	 unsigned int	 onoffCtl; // bit0:eq,	bit1: drc, bit2: spkPro
	 QL_EqParamIn		 eqParam;
	 QL_MediaDRCParaT drcParam;
	 QL_SPKProParaT spkProParam;
	 unsigned short 		 Reserved[7];
	 unsigned short 		 Tag;		 //Fixed as 0xBEEF
 } QL_MediaVEarametersT;

 
 //ICAT EXPORTED STRUCT
 typedef struct {// res parameters
	  signed short	 ResMode;
	  signed short	 DtGainDb;
	  signed short	 FestGainDb;
	  signed short	 NoiseFloorDbov;
	  signed short	 CnGaindb;	 
	  signed short	 DtThresh;
	  signed short	 Gamma;
	  //following is expert paramters
	  signed short	 AuditoryMasking;
	  signed short	 NonlinearModel;
	  signed short	 WinitCntThresh;
	  signed short	 EstResMatrix;
	  signed short	 VadhangRef;
	  signed short	 VadhangNear;
	  signed short	 reserved;
 } QL_ACMDSP_NSResParamsT;
 
 
 //ICAT EXPORTED STRUCT
 typedef struct {// reserved  parameters for dual_mic
	  signed short	TapsNum; 
	  signed short	Oversuppression;
	  signed short	OverAuditoryMasking;
	  signed short	DualMicVmThresh;
	  signed short	DualMicVmOffset;
	  signed short	DualMicNoiseThresh;
	  signed short	DualMicVadHang;
	  signed short	DualMicVmRelease;
	  signed short	NonStationaryLeftDb;
 } QL_ACMDSP_NSDmParamsT;
 
  //ICAT EXPORTED STRUCT
 typedef struct {
	  signed short	 MaxSuppressDb; 	 // [-40,0)db.
	  signed short	 PeakNoiseDb;		 // [-70,-12)db.
	  signed short	 NoiseMatrix;		 // following is expert parameters
	  signed short	 FrameSmoothFactor;
	  signed short	 reserved;
 } QL_ACMDSP_NSParamsT; //noise suppression para, for both TX&RX
 //ICAT EXPORTED STRUCT
 typedef struct {
	  QL_ACMDSP_NSParamsT	  NsParams;
	  QL_ACMDSP_NSResParamsT ResParams;
	  QL_ACMDSP_NSDmParamsT  DmParams;
 } QL_ACMDSP_NSTxParamsT;		 //TX only

 typedef struct
 {
	 signed short	 SampleDelay;		 // reference delay to echo
	 signed short	 NumOfTaps; 		 // Fir filter length
	 signed short	 ConvergenceSpeed;	 // slowdown
	 signed short	 Ref2EchoPowerRatio; // ratio of ref to echo, [-12 ~30]db, decimal number
	 signed short	 DC_factor; 		 //[14000 ~16350]  but default should be 16200
	 signed short	 reserved0;  
 } QL_ACMDSP_ECParamsT;


 //ICAT EXPORTED STRUCT
 typedef struct
 {
	 signed short	 BoostMode; 		 // 0 , 1, 2, 3
	 signed short	 BoostGainDb; 
	 signed short	 PeakGainDb;
	 signed short	 BoostNoiseGainDb;
	 signed short	 NoiseLevel;
	 signed short	 BoostAttach;
	 signed short	 BoostRelease;
	 signed short	 reserved;
	 signed short	 TargetLevel;
	 signed short	 AgcMaxGainDb;
	 signed short	 AgcMaxRMS; 		
	 signed short	 AgcEnvStep;		 //expert parameters
	 signed short	 RMStrackStep;		 //expert parameters
 } QL_ACMDSP_AGCParamsT;

 //ICAT EXPORTED STRUCT
 typedef struct 
 {
	 unsigned short  PeriodDelta;
	 unsigned short  ExpandRate;
	 unsigned short  CorrectionThreshold;
	 signed short	 reserved;
 } QL_ACMDSP_SlowVoiceParamsT;

 typedef struct
 {	  
	 signed short 		 Profile;
	 signed short			 Version;
	 unsigned short 		 VoiceControl;
 
 //TX path
	 signed short			 ExpertParam1[ACM_RATE_CNT];
	 QL_ACMDSP_ECParamsT		 EcParams[ACM_RATE_CNT];
	 QL_ACMDSP_NSTxParamsT 	 NsParamsTx[ACM_RATE_CNT];
	 signed short			 TxFreq_eqCoeffArray[ACM_RATE_CNT][24];
	 QL_ACMDSP_AGCParamsT		 TxAgcParams[ACM_RATE_CNT];
 
 //RX path
	 signed short			 ExpertParam2[ACM_RATE_CNT];
	 QL_ACMDSP_NSParamsT		 NsParamsRx[ACM_RATE_CNT];
	 signed short			 RxFreq_eqCoeffArray[ACM_RATE_CNT][24];
	 QL_ACMDSP_AGCParamsT		 RxAgcParams[ACM_RATE_CNT];
	 QL_BiQuadCoeffsStruct	 BiQuadIIR[ACM_RATE_CNT]; //can be used as hpf/lpf or notch filter
	 QL_ACMDSP_SlowVoiceParamsT SlowVoiceParam;
 
 //Reserved    
	 unsigned short 		 Reserved[6];
	 unsigned short 		 Tag;		 //Fixed as 0xBEEF
 } QL_ACMDSP_VEParametersT;

 typedef void (*ql_cb_on_speakerpa) (unsigned int on);
 typedef int (*ql_cb_dtmf_detect)(unsigned short DTMFCode);
 int ql_get_audio_state(void);
 void ql_set_volume(QL_AUDIOHAL_SPK_LEVEL vol);
 int ql_get_volume(void);
 void ql_bind_speakerpa_cb(ql_cb_on_speakerpa cb);
 void ql_set_audio_path_earphone(void);
 void ql_set_audio_path_receiver(void);
 void ql_set_audio_path_speaker(void);
 int ql_set_dtmf_detect(ql_cb_dtmf_detect cb, int onoff);
 int ql_aud_dtmf_play(QL_AUDIOHAL_TONE_TYPE dtmf, int onoff); 
 int ql_aud_tone_play(int f1, int f2, int onoff);
 void ql_codec_choose(codec_choose_state codec_choose, quec_codecpcm_config* pcm_config);
 void ql_set_dtmf_volume(int vo);
 int ql_set_dsp_gain_table(unsigned int profile_id, signed short *gain);
 void ql_set_txdspgain(signed char gain);
 signed char ql_get_txdspgain(void);
 void ql_set_txcodecgain(short gain);
 short ql_get_txcodecgain(void);
 int ql_set_txcodec_gain_table(unsigned int profile_id, unsigned int PGA_Stage1, unsigned int PGA_Stage2, unsigned int diggain);
 int ql_set_rxcodec_gain_table(unsigned int profile_id, signed int level, unsigned int data1,  unsigned int data2, unsigned int data3, unsigned int data4, unsigned int data5);
 int ql_set_eqcoeff_table(unsigned int profile_id, signed int tx_rx, unsigned int rate, signed short * data);
 int ql_set_mediave_coeff_table(QL_MediaVEarametersT *AudioMediaVETable);
audio_track_handle ql_audio_track_open(unsigned int rate, unsigned int channels, int64_t option, audio_track_callback event_cb);
int ql_audio_track_write(audio_track_handle handle, uint8_t* data, unsigned int size);
int ql_audio_track_close(audio_track_handle handle,int force);
int ql_audio_track_ctrl(audio_track_handle handle, acm_audio_track_control_t ctrl_type, int ctrl_value);
audio_record_handle  ql_audio_record_open(unsigned int rate, unsigned int channels, int64_t option, audio_record_callback event_cb);
int ql_audio_record_read(audio_record_handle handle, uint8_t*data, unsigned int* count);
int ql_audio_record_close(audio_record_handle handle,int force);
int ql_audio_record_ctrl(audio_record_handle handle, acm_audio_record_control_t ctrl_type, int ctrl_value); 
int ql_wav_play(const char* file_name, struct audio_track_config* track_config, audio_track_handle* handle);
int ql_wav_play_stop(audio_track_handle handle,char force);
int ql_play_mp3(char *file_name,Mp3PlaybackHandle* handle,Mp3PlayConfigInfo* mp3_configInfo);
int ql_play_mp3_stream_buffer(Mp3PlaybackHandle handle,unsigned char *mp3_buff, int mp3_size);
int ql_stop_mp3_play(Mp3PlaybackHandle handle,int drain);
int ql_mp3_get_pcm_handle(Mp3PlaybackHandle handle, unsigned int* pcm_handle);
int ql_play_amr(char *file_name,AmrPlaybackHandle* handle,AmrPlaybackConfigInfo* amr_configInfo);
int ql_play_amr_stream_buffer(AmrPlaybackHandle handle,unsigned char *amr_buff, int amr_size);
int ql_stop_amr_play(AmrPlaybackHandle handle,int drain);
int ql_amr_get_pcm_handle(AmrPlaybackHandle handle, unsigned int* track_handle);
int ql_record_amr(char *file_name,AmrEncodeHandle* handle,AmrEncConfigInfo* amr_configInfo);
int ql_record_amr_stop(AmrEncodeHandle handle);
void ql_set_dtmf_volume2(int vo);
int ql_audio_get_veparam(unsigned short profile, QL_ACMDSP_VEParametersT *out_params);
void ql_audio_set_veparam(QL_ACMDSP_VEParametersT *ve_params);
int ql_mp3_play_get_duration(const char* file_name, int* duration);
int ql_mp3_stream_get_duration(Mp3PlaybackHandle handle, Mp3PlayInfoType type, int* value);
#endif
