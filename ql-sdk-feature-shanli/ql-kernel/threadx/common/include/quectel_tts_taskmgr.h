/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUECTEL_TTS_TSAKMGR_H
#define QUECTEL_TTS_TSAKMGR_H

/*===========================================================================
 * include files
 ===========================================================================*/
#include "quec_include.h"
#include "quec_cust_feature.h"
#include "quec_audio.h"
#include "telatci.h"


#ifdef __cplusplus
extern "C" {
#endif

#if defined(QUECTEL_TTS_FEATURE)

/*===========================================================================
 * Macro Definition
 ===========================================================================*/


/*===========================================================================
 * struct,enum definition
 ===========================================================================*/
typedef struct 
{   
#if defined(QUEC_QWTTS_SUPPORT)
    char tts_type; //TTS or WTTS
    uint8 ulmute;  //uplink mute/umute
    uint8 dlmute;  //downlink mute/unmute
#endif 
    int  mode;  // mode
    char *text; // point to TTS text
    int  len;   // length of TTS text
#ifdef UAC_SUPPORT
    char uac_mode; //tts data to uac
#endif
} ivTTS_text_type;

/*===========================================================================
 * Global Variable
 ===========================================================================*/


/*===========================================================================
 * extern
 ===========================================================================*/
int32   tts_task_startup(void);
void quec_tts_stop(void);
Bool quec_tts_is_playing(void);

#endif/*QUECTEL_APPTCPIP_SUPPORT*/

#ifdef __cplusplus
}
#endif

#endif /*QUECTEL_APPTCPIP_TASKMGR_H*/
