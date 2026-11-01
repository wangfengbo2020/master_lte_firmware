/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/

#ifndef QUEC_TTS_TSAKMGR_H
#define QUEC_TTS_TSAKMGR_H


typedef struct {
    int  code;
    char *text; // point to TTS text
} ivTTS_text_type;

typedef enum {
    QL_TTS_EVT_INIT,
    QL_TTS_EVT_DEINIT,
    QL_TTS_EVT_PLAY_START,
    QL_TTS_EVT_PLAY_STOP,
    QL_TTS_EVT_PLAY_FINISH,
    QL_TTS_EVT_PLAY_FAILED,
    QL_TTS_EVT_PLAY_INTERRUPT,
} QL_TTS_ENVENT_E;

typedef void (*ql_tts_cb_type)(QL_TTS_ENVENT_E event, char *str);

int ql_tts_init(ql_tts_cb_type usr_cb);
int ql_tts_play(int mode, const char* string);
/*mode:
	1--UNICODE16(Size end conversion)  
	2--UTF-8  
	3--UNICODE16(Don't convert)
*/
int ql_tts_stop(void);
int ql_tts_state(void);
int ql_tts_set_volume(int volume);
int ql_tts_get_volume(void);
int ql_tts_set_speed(int speed);
int ql_tts_get_speed(void);
int ql_tts_deinit(void);
int ql_tts_digit_mode(int mode);
int ql_get_tts_digit_mode(void);
int ql_set_tts_file_name(char *file_path, int path_len);
char *ql_get_tts_file_name(void);

#endif/*QUECTEL_APPTCPIP_SUPPORT*/


