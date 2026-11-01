/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.
-------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************
 *
 * Filename: audio_bind.h
 *
 * Programmers: Yishai Gil (yg)
 *
 * Description: audio I/F to communication side (L1) typdefs
 * --------------------------------------------------------------------
 * Revision History
 *
 * Date         Who        Version           Description
 * --------------------------------------------------------------------
 * 12-Sep-2004  yg        	0.01               File Created
 **********************************************************************/
#ifndef AUDIO_BIND_H
#define AUDIO_BIND_H

#include "global_types.h"
#include "acm_comm.h"
#include "singleToneDect.h"
#include "audio_def.h"

#define AUDIO_SUPPORT_POC_API
#if FEATURE_AUDIO_POC_STREAM == 0
#undef AUDIO_SUPPORT_POC_API
#endif

enum  audio_bind_function_names
{
  AUDIO_BIND_NULL              = 0
 ,AUDIO_GET_RAT
 ,AUDIO_SWAP_BYTES
 ,AUDIO_GSM_START_VOICE
 ,AUDIO_GSM_STOP_VOICE
 ,AUDIO_GSM_GET_VOCODER_TYPE
 ,AUDIO_GSM_GET_DTX_SUPPORT
 ,AUDIO_GSM_GET_TX_BUFFER
 ,AUDIO_GSM_SET_AMR_TOC
 ,AUDIO_GSM_SET_AMR_SID_TYPE_IND
 ,AUDIO_GSM_SET_ENCODER_FLAGS
 ,AUDIO_GSM_SET_DECODER_SID_IND
 ,POCVOICE_GET_TX_PCM   //For POC: got Tx PCM
 ,POCVOICE_GET_RX_PCM   //For POC: request Rx PCM 
 ,POCVOICE_GET_TX_AMR   //For POC: got Tx AMR  
 ,POCVOICE_GET_RX_AMR   //For POC: request Rx AMR  
 ,AUDIO_GET_DTMF_CODE   
 ,AUDIO_GET_VOICE_DATA 
 ,MAX_AUDIO_BIND
};

//ICAT EXPORTED ENUM
typedef enum
{
	AUDIO_GSM_RAT,
	AUDIO_WCDMA_RAT,
	AUDIO_LTE_RAT,
	AUDIO_NULL_RAT,
	AUDIO_ALL_RAT,
	AUDIO_UNKNOWN_RAT,
}audioRat_te;

enum  poc_bind_types
{
  BIND_NONE              = 0
 ,BIND_PCM
 ,BIND_AMR
 ,BIND_PCM_STREAMING
 ,BIND_PCM_STREAMING_TX
 ,BIND_PCM_STREAMING_RX
 ,MAX_BIND_TYPES
};

#define AUDIO_DTMF_TX 0
#define AUDIO_DTMF_RX 1
#define AUDIO_DTMF_OFF 0
#define AUDIO_DTMF_ON 1
#define dialToneToOthersTones_DEFAULT 0x19
#define dialTonesToOthersDialTones_DEFAULT 4
#define dialVadDuration_DEFAULT 3

typedef struct voiceGetDTMFMSG
{
	UINT16 dtmfType; /* 0=TX, 1=RX*/
	UINT16 keyValue; /* detected DTMF Number */
} voiceGetDTMFMSG_t;

typedef struct DTMFDetectionControl
{
    UINT16 dtmfType;                   /* 0=TX, 1=RX */
    UINT16 onoff;                      /* 0=Disable, 1=Enable */
    UINT16 dialToneToOthersTones;      /* param1, default is 50 */
    UINT16 dialTonesToOthersDialTones; /* param2, default is 4 */
    UINT16 dialVadDuration;            /* param3, default is 3 */
} DTMFDetectionControl_t;


typedef struct PocPcmConfig_t
{
	unsigned int sampleRate; 
	unsigned char pcm2FarEnd;
	unsigned char rsv[3];
} PocPcmConfig;



typedef audioRat_te (*audioGetRAT_t)(void);
typedef unsigned char (*audioDoDataSwapBytes_t)(void);
typedef void (*audioGsmStartVoicePath_t)(void);
typedef void (*audioGsmStopVoicePath_t)(void);
#ifdef MACRO_FOR_LTG
typedef unsigned short (*audioGsmGetVocoderType_t)(void);
#endif
//#ifdef MACRO_FOR_LWG
typedef void (*audioGsmGetVocoderTypeRate_t)(unsigned short *vocoderType, unsigned short *vocoderRate);
//#endif
typedef BOOL  (*audioGsmGetDtxSupport_t)(void);
typedef void* (*audioGsmGetTxBuffer_t)(void);
typedef void  (*audioGsmSetAmrToc_t)(unsigned short);
typedef void  (*audioGsmSetAmrSidTypeInd_t)(unsigned short);
typedef void  (*audioGsmSetEncoderFlags_t)(unsigned short);
typedef void  (*audioGsmSetDecoderSidInd_t)(unsigned short);
typedef void  (*POCTxPCMHandler_t)(short *pData, unsigned short Length);
typedef void  (*POCRxPCMHandler_t)(short *pData, unsigned short Length);
typedef int  (*POCTxAMRHandler_t)(void const * frame, unsigned short Length);
typedef int  (*POCRxAMRHandler_t)(void* frame, unsigned short Length);
typedef void  (*DTMFDetectionHandler_t)(unsigned short DTMFCode);
typedef void  (*OEMAudio_GetVoiceDataCallback_t)(short *rx, short *tx, short *mixed, short length, unsigned int count);


void audioBindGetRAT(audioGetRAT_t);
void audioBindDoDataSwapBytes(audioDoDataSwapBytes_t);
void audioBindGsmStartVoicePath(audioGsmStartVoicePath_t);
void audioBindGsmStopVoicePath(audioGsmStopVoicePath_t);
#ifdef MACRO_FOR_LTG
void audioBindGsmGetVocoderType(audioGsmGetVocoderType_t);
#endif
//#ifdef MACRO_FOR_LWG
void audioBindGsmGetVocoderTypeRate(audioGsmGetVocoderTypeRate_t);
//#endif
void audioBindGsmGetDtxSupport(audioGsmGetDtxSupport_t);
void audioBindGsmGetTxBuffer(audioGsmGetTxBuffer_t);
void audioBindGsmSetAmrToc(audioGsmSetAmrToc_t);
void audioBindGsmSetAmrSidTypeInd(audioGsmSetAmrSidTypeInd_t);
void audioBindGsmSetEncoderFlags(audioGsmSetEncoderFlags_t);
void audioBindGsmSetDecoderSidInd(audioGsmSetDecoderSidInd_t);
int POCVoice_BindPCMHandler(POCTxPCMHandler_t, POCRxPCMHandler_t);
int POCVoice_UnBindPCMHandler(POCTxPCMHandler_t, POCRxPCMHandler_t);
int POCVoice_BindPCMPlay(PocPcmConfig* config, POCRxPCMHandler_t play_cb);
int POCVoice_UnBindPCMPlay(POCRxPCMHandler_t play_cb);
int POCVoice_BindPCMRecord(PocPcmConfig* config, POCRxPCMHandler_t record_cb);
int POCVoice_UnBindPCMRecord(POCRxPCMHandler_t record_cb);
int POCVoice_BindAMRHandlers(POCTxAMRHandler_t cb_tx, POCRxAMRHandler_t cb_rx);
int POCVoice_UnBindAMRHandlers(POCTxAMRHandler_t cb_tx, POCRxAMRHandler_t cb_rx);
int POCVoice_DTMF_Button(unsigned int start, int ascii_pushbutton);
int POCVoice_DTMF_Freq(unsigned int start, int f1, int f2);


int POCVoice_ConfigureAMR(UINT8 Band, UINT8 Rate, UINT8 Format);
int POCVoice_StartTTSPlay(int play_direction, int is_wb, SetDownLinkStream cb);
int POCVoice_MuteTTSPlay(int tx_mute, int rx_mute);
int POCVoice_StopTTSPlay(SetDownLinkStream cb);
BOOL POCVoice_UseBitstream(void);

int OEMAudio_singleToneDetectConfigure(ToneDecStateForCustomerStruct* config, int type);
int OEMAudio_BindDTMFDetectionHandler(DTMFDetectionHandler_t cb, DTMFDetectionControl_t *pDTMFDetectionControl);
int OEMAudio_UnBindDTMFDetectionHandler(DTMFDetectionHandler_t cb, DTMFDetectionControl_t *pDTMFDetectionControl);
int OEMAudio_BindGetVoiceDataCallback(OEMAudio_GetVoiceDataCallback_t cb);
int OEMAudio_UnBindGetVoiceDataCallback(OEMAudio_GetVoiceDataCallback_t cb);
int OEMAudio_SetVoiceData(int wb, int VoiceType);
void AcmSetPCMRate(BOOL wb);
unsigned char AcmGetPCMRate(void);

int POCVoice_ConfigPlay2FarEnd(unsigned int nearCodec, unsigned int substitute);
int POCVoice_ConfigPlay2NearEnd(unsigned int nearCodec, unsigned int substitute);
#ifdef	QUECTEL_OPEN_CPU //Add POC class interface to set the bottom codec switch
void POCDelay_StopCnt(unsigned int cnt);
#endif
int POCVoice_ConfigRecord(unsigned int nearCodec);




int getPOCBindType(void);
void setPOCBindType(int);

extern BOOL OEMAudio_DetectRxDTMF;

extern void *audio_bind[MAX_AUDIO_BIND];

#define audioGetRAT(a)            (*(audioGetRAT_t)(audio_bind[AUDIO_GET_RAT]))(a)
#define audioDoDataSwapBytes(a)   (*(audioDoDataSwapBytes_t)(audio_bind[AUDIO_SWAP_BYTES]))(a)
#define audioGsmStartVoicePath(a) (*(audioGsmStartVoicePath_t)(audio_bind[AUDIO_GSM_START_VOICE]))(a)
#define audioGsmStopVoicePath(a)  (*(audioGsmStopVoicePath_t)(audio_bind[AUDIO_GSM_STOP_VOICE]))(a)

#ifdef MACRO_FOR_LTG
#define audioGsmGetVocoderType(a)     (*(audioGsmGetVocoderType_t)(audio_bind[AUDIO_GSM_GET_VOCODER_TYPE]))(a)
#endif
//#ifdef MACRO_FOR_LWG
#define audioGsmGetVocoderTypeRate(a, b) (*(audioGsmGetVocoderTypeRate_t)(audio_bind[AUDIO_GSM_GET_VOCODER_TYPE]))(a, b)
//#endif
#define audioGsmGetDtxSupport(a)      (*(audioGsmGetDtxSupport_t)(audio_bind[AUDIO_GSM_GET_DTX_SUPPORT]))(a)
#define audioGsmGetTxBuffer(a)        (*(audioGsmGetTxBuffer_t)(audio_bind[AUDIO_GSM_GET_TX_BUFFER]))(a)

#define audioGsmSetAmrToc(a)          (*(audioGsmSetAmrToc_t)(audio_bind[AUDIO_GSM_SET_AMR_TOC]))(a)
#define audioGsmSetAmrSidTypeInd(a)  (*(audioGsmSetAmrSidTypeInd_t)(audio_bind[AUDIO_GSM_SET_AMR_SID_TYPE_IND]))(a)
#define audioGsmSetEncoderFlags(a)    (*(audioGsmSetEncoderFlags_t)(audio_bind[AUDIO_GSM_SET_ENCODER_FLAGS]))(a)
#define audioGsmSetDecoderSidInd(a)   (*(audioGsmSetDecoderSidInd_t)(audio_bind[AUDIO_GSM_SET_DECODER_SID_IND]))(a)
#define POCVOICEGetTxPCM(a, b)   (*(POCTxPCMHandler_t)(audio_bind[POCVOICE_GET_TX_PCM]))(a, b)
#define POCVOICEGetRxPCM(a, b)   (*(POCRxPCMHandler_t)(audio_bind[POCVOICE_GET_RX_PCM]))(a, b)
#define POCVOICE_TxAMR_CB(a, b)   (*(POCTxAMRHandler_t)(audio_bind[POCVOICE_GET_TX_AMR]))(a, b)
#define POCVOICE_RxAMR_CB(a, b)   (*(POCRxAMRHandler_t)(audio_bind[POCVOICE_GET_RX_AMR]))(a, b)
#define DTMFDetectionHandlerCB(a)   (*(DTMFDetectionHandler_t)(audio_bind[AUDIO_GET_DTMF_CODE]))(a)
#define audioGetVoiceDataCB(a, b, c, d, e)   (*(OEMAudio_GetVoiceDataCallback_t)(audio_bind[AUDIO_GET_VOICE_DATA]))(a, b, c, d, e)

#endif   /* AUDIO_BIND_H */
