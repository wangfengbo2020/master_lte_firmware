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
09/04/2022        Sharon.li  ¡ä????t¨º???kerenlAPI¨®3¨¦?,1?APP2¨¤¨º1¨®?¡ê?¡Á¡é¨°a?aD?API?a?¨ª?¡ì?¨¦?¡§??2???¦Ì?API¡ê?
                             ¡ä????t???¨ª?¡ì?¨¦??
							 
===========================================================================================================*/


#include "ql_type.h"
#include "ql_audio.h"
#include "ql_audio_old_api.h"
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
#include "broad.h"
 #ifdef QUEC_AUDIO_DENOISE
#include "ql_audio_denoise.h"
#include "quec_track_audio.h"
#endif

#ifdef QUEC_AUDIO_KWS
#include "ql_kws_pipeline.h"
extern int hal_websocket_start(void);
extern void websocket_send_start_signal(void);
extern void hal_ws_send_write_msg(void *Msg, unsigned int len);
extern void hal_ws_send_end_write_msg(void );
extern int ql_set_kws_app_info(kws_app_info_t *kws_app_info);
#endif


extern void quec_kernel_api_test(void);
void ql_user_api_map_test(void)
{
	RTI_LOG("This is an user api mapping test line\r\n");
}

extern void poc_device_bts(int *mcc, int *mnc, int *lac, int*cid);
void poc_device_bts(int *mcc, int *mnc, int *lac, int*cid)
{
	int ret = 0,i;
	int temp;
	char Bts[32] = {0};
	QL_NW_CELL_INFO_T  *ql_nw_cell_info= calloc(1,sizeof(QL_NW_CELL_INFO_T));
	ret = ql_nw_get_cell_info(ql_nw_cell_info);
	*mcc = ql_nw_cell_info->lte_info[0].mcc;
	*mnc = ql_nw_cell_info->lte_info[0].mnc;
	*lac = ql_nw_cell_info->lte_info[0].tac;
	*cid = ql_nw_cell_info->lte_info[0].cid;
	free(ql_nw_cell_info);
}

int poc_get_sim_operator() 
{
	int ret = 0;
	QL_NW_OPERATOR_INFO_T ql_nw_operator_name_info = {0};
	ql_nw_get_operator_name(&ql_nw_operator_name_info);
	// 0:¡Á¡é??¨º¡ì¡ã¨¹ 1:¨°??¡¥ 2:¨¢a¨ª¡§ 3:¦Ì?D?
	if (strstr(ql_nw_operator_name_info.long_eons, "CHN-CT")) {
		//¦Ì?D?
		ret = 3;
	} else if (strstr(ql_nw_operator_name_info.long_eons, "CHN-UNICOM")) {
		//¨¢a¨ª¡§
		ret = 2;
	} else if (strstr(ql_nw_operator_name_info.long_eons, "MOBILE")) {
		//¨°??¡¥
		ret = 1;
	} else {
		ret = 0;
		//?T¡¤¡§¨º?¡Àe
	}
	return ret;
}

ql_open_api_list vUserAPITable[] __attribute__((used, section("DDR_USER_API_TABLE"))) =
{
	{0x60BCEA5A, 							         (void*)ql_user_api_map_test},	
	{0xFFFFFFFF, 							         (void*)quec_kernel_api_test},

/********************************************
*********/
	{0x6BC3EB80,(void*)broad_init},
	{0xDB94DA3A,(void*)broad_free},
	{0x477CA8B6,(void*)broad_log},
	{0xF53A721E,(void*)broad_login},
	{0x9508DB34,(void*)broad_logout},
	{0xCB7DAEEC,(void*)broad_joingroup},
	{0x4A8708C2,(void*)broad_leavegroup},
	{0x77E45F26,(void*)broad_speak},
	{0xEF3825DE,(void*)broad_calluser},
	{0x1CD74BB2,(void*)broad_group_getbyindex},
	{0x9E4C3ABA,(void*)broad_group_getbyid},
	{0x16451B7A,(void*)broad_member_getbyid},
	{0x0FF69C90,(void*)broad_get_loginstate},
	{0xB82163B4,(void*)broad_get_groupcount},
	{0x42E2442A,(void*)broad_get_grouplist},
	{0x341C6248,(void*)broad_get_membercount},
	{0xB78854A6,(void*)broad_get_memberlist},
	{0x413E5F46,(void*)broad_get_audiostate},
	{0xC791E03A,(void*)broad_play_tts},
	{0x78E648FA,(void*)broad_send_ping},
	{0x15A92E30,(void*)broad_send_gpsinfo},
	{0xD2A82C46,(void*)broad_get_version},
	{0x5A7490D0,(void*)broad_current_zone_time},
	{0x93CAEFEE,(void*)broad_set_tts_enable},
	{0x1DFC4EC2,(void*)broad_set_vol},
	{0x73EF423E,(void*)broad_get_vol},
	{0xF8FD365A,(void*)broad_get_account_day},
	{0x4D8A04B2,(void*)broad_set_rec_audio_mode},
	{0x9E50F216,(void*)broad_get_rec_audio_count},
	{0xB2AC7810,(void*)broad_get_rec_audio_info},
	{0x836B4B14,(void*)broad_play_rec_audio},
	{0x59472F98,(void*)broad_register_audio_cb},
	{0x6D535C78,(void*)broad_register_join_group_cb},
	{0x45FCEA5E,(void*)broad_register_listupdate_cb},
	{0x7BED7AE8,(void*)broad_register_member_change_cb},
	{0xE0AA46EA,(void*)broad_register_error_cb},
	{0xB8126034,(void*)broad_send_at},
	{0xE182C6E4,(void*)broad_register_poc_at_cb},
	{0xB84AB8FE,(void*)broad_set_poc_uart_device},
	{0xC357BE26,(void*)broad_set_call_auto_leave_temp_group},
	{0x722DEDC2,(void*)broad_set_call_end_timeptr},
	{0x6729B9D4,(void*)broad_write_custom},
	{0xCF0FAD48,(void*)broad_read_custom},
	{0xCCEFD30C,(void*)broad_set_notify_mode},
	{0x23CA23CA,(void*)broad_set_solution},
	{0x30043D5C,(void*)broad_set_solution_version},
	{0x6C846AC0,(void*)broad_request_upgrade},
	{0xEAAA456E,(void*)broad_register_upgrade_cb},
	{0xF8F13882,(void*)broad_set_productInfo},
	{0x74F7B54C,(void*)broad_set_manufacturer},
	{0x13C58786,(void*)broad_get_init_status},
	{0x2BE38F3A,(void*)broad_set_tone_enable},
	{0xDE96A2B6,(void*)broad_register_member_audio_enable_cb},
	{0xB3E58B6C,(void*)broad_register_reminder_cb},
	{0xFAC33B06,(void*)broad_callusers},
	{0x2FF4D3DC,(void*)broad_register_pa_cb},
	{0xE3B8A1DE,(void*)broad_get_upgrade_version},
	{0x84A78F70,(void*)broad_request_lbs_info},
	{0xF57AB64C,(void*)broad_register_request_lbs_info_cb},
	{0x3FD94ECE,(void*)broad_register_location_change_cb},
	{0x562F387A,(void*)broad_request_weather_info},
	{0x45FFF0D8,(void*)broad_register_weather_info_cb},
	{0x7EA4E850,(void*)broad_register_cell_location_change_cb},
	{0x534AE5B6,(void*)broad_get_logininfo},
	{0x42E975F0,(void*)broad_login_by_saved},
	{0x1919DBF2,(void*)broad_change_logininfo},
	{0x8D541B24,(void*)broad_request_create_full_duplex_group},
	{0x27B57FB2,(void*)broad_response_create_full_duplex_group},
	{0x689C5EA0,(void*)broad_register_request_invite_ack_cb},
	{0xCE40B6D6,(void*)broad_register_response_invite_ack_cb},
	{0x746ED1C2,(void*)broad_register_push_invite_cb},
	{0xF45233A2,(void*)broad_register_push_response_invite_cb},
	{0x2F4E2EDE,(void*)broad_sos_start},
	{0xE40AF684,(void*)broad_query_sos_map},
	{0x080F6FD2,(void*)broad_register_sos_status_cb},
	{0x1D323EEA,(void*)broad_register_sos_map_cb},
	{0x8ACDADCA,(void*)broad_register_recv_sos_info_cb},
	{0x64368D82,(void*)broad_register_recv_enclosure_alarm_cb},
	{0xDE02F582,(void*)broad_register_recv_broadcast_info_cb},
	{0xB1B7CACE,(void*)broad_get_contactlist_count},
	{0xE3A1C76E,(void*)broad_get_contactlist},
	{0x5F650C9C,(void*)broad_http_add_group},
	{0xA28DB6CC,(void*)broad_http_add_members},
	{0x6567D508,(void*)broad_http_remove_members},
	{0xC5163864,(void*)broad_http_delete_group},
	{0x255EB97A,(void*)broad_http_update_group_owner},
	{0xFF61D494,(void*)broad_http_get_invitation_code_group},
	{0x554E28F0,(void*)broad_http_join_group},
	{0x98956A5A,(void*)broad_http_exit_group},
	{0x03490C56,(void*)broad_register_recv_http_add_group_cb},
	{0x0BCB390E,(void*)broad_register_recv_http_add_members_cb},
	{0x0A6823F2,(void*)broad_register_recv_http_remove_members_cb},
	{0x4B8689C6,(void*)broad_register_recv_http_delete_group_cb},
	{0x75F91EDC,(void*)broad_register_recv_http_update_group_owner_cb},
	{0x68A8F2F2,(void*)broad_register_recv_http_get_invitation_code_cb},
	{0x9C8CEFAA,(void*)broad_register_recv_http_join_group_cb},
	{0xAE8C2944,(void*)broad_register_recv_http_exit_group_cb},
	{0xC29A8D36,(void*)broad_register_recv_http_request_timeout_cb},
	{0x00DCB2C4,(void*)broad_register_create_group_switch_cb},
	{0x36156FA8,(void*)broad_report_sos},
	{0xB0D44A02,(void*)broad_set_terminal_info},
	{0x6CCF3D94,(void*)broad_register_recv_sos_alarm_cb},
	{0x41816688,(void*)broad_register_recv_report_sos_ack_cb},
	{0x7F8C3EB2,(void*)broad_register_recv_close_sos_cb},
	{0x470358E8,(void*)broad_register_recv_report_sos_ack_timeout_cb},
	{0xBA9CA30C,(void*)broad_register_sos_switch_cb},
	{0x0BEB08A6,(void*)broad_set_broadcast_tts_enable},
	{0xEB6CFE20,(void*)broad_register_recv_reportType_msg_cb},
	{0x6F7D1156,(void*)broad_get_default_group_id},
	{0xF63728CC,(void*)broad_recorder_audio_run},
	{0x9B45FD60,(void*)broad_register_recv_ai_audio_info_cb},
	{0x8B08F594,(void*)broad_register_ai_switch_cb},
	{0x81B16BEA,(void*)broad_stop_play_ai_tts},
	{0x5FB87F40,(void*)broad_register_record_file_err_cb},
	{0x8EC91A88,(void*)broad_register_record_file_list_cb},
	{0xBAEA56CA,(void*)broad_http_record_file},
	{0xA61BD5C6,(void*)broad_http_record_file_stop_play},	
   /************************************************************************************************
   *   audio 
   *************************************************************************************************/
#ifndef QUEC_NOAUDIO 
    /*[ 0]*/{0x4C66F2E6,                             (void *)ql_get_audio_state},
    /*[ 1]*/{0x03000E14,                             (void *)ql_set_volume},
	/*[ 2]*/{0x24CFFC90,                             (void *)ql_get_volume},
	/*[ 3]*/{0x89A34594,                             (void *)ql_bind_speakerpa_cb},
	/*[ 4]*/{0xAB704D0E,                             (void *)ql_set_audio_path_earphone},
	/*[ 5]*/{0xAF712ADA,                             (void *)ql_set_audio_path_receiver},
	/*[ 6]*/{0xF3D116CC,                             (void *)ql_set_audio_path_speaker},
	/*[ 7]*/{0x084514A6,                             (void *)ql_aud_dtmf_play},
	/*[ 8]*/{0xA67CE8B2,                             (void *)ql_aud_tone_play},
	/*[ 9]*/{0x1386E4CA,                             (void *)ql_codec_choose},
	/*[ 10]*/{0x6617F108,                            (void *)ql_set_rxcodec_gain_table},
	/*[ 11]*/{0x2ED86FEC, 			   				 (void *)ql_set_eqcoeff_table},
	/*[ 12]*/{0x5F80E0B8,                            (void *)ql_set_mediave_coeff_table},
	/*[ 14]*/{0x99026E80,                            (void *)ql_set_dtmf_detect},
    /*[ 45]*/{0xC773B1B4,							 (void *)ql_set_dtmf_volume},
    /*[ 47]*/{0x7F3D99B4,							 (void *)ql_set_dsp_gain_table},
	/*[ 48]*/{0xF42A9D82,							 (void *)ql_set_txdspgain},
	/*[ 49]*/{0x6987038E,							 (void *)ql_get_txdspgain},
	/*[ 50]*/{0xDB6D59F0,							 (void *)ql_set_txcodecgain},
	/*[ 51]*/{0xF0DC64CC,							 (void *)ql_get_txcodecgain},
	/*[ 52]*/{0xF46C869E,							 (void *)ql_set_txcodec_gain_table},
	/*[ 52]*/{0x7A5794EE,							 (void *)ql_set_dtmf_volume2},
	/*[ 53]*/{0xCE18DC32,                             (void *)ql_audio_get_veparam},
	/*[ 54]*/{0x686A7106,                             (void *)ql_audio_set_veparam},
	/*[ 42]*/{0xC60A1428,                            (void *)ql_play_file_start},
	/*[ 43]*/{0x6BBA8154,                            (void *)ql_play_file_stop},
	/*[ 42]*/{0x0D3367B6,                            (void *)ql_audio_file_play},
	/*[ 43]*/{0xA7E6E072,                            (void *)ql_audio_file_stop},
#ifdef QUEC_PCM_FUNC
    /*[ 19]*/{0xF878E268,                             (void *)ql_audio_track_open},
	/*[ 20]*/{0x259E2582,                             (void *)ql_audio_track_write},
	/*[ 21]*/{0x1A7DE77E,                             (void *)ql_audio_track_close},
	/*[ 21]*/{0xC2331E66,                             (void *)ql_audio_track_ctrl},
	/*[ 22]*/{0x9C143DE6,                             (void *)ql_audio_record_open},
	/*[ 21]*/{0xE7D31F80,                             (void *)ql_audio_record_read},
	/*[ 21]*/{0x43DB0BCC,                             (void *)ql_audio_record_close},
	/*[ 21]*/{0x7868F160,                             (void *)ql_audio_record_ctrl},
	/*[ 11]*/{0x7CBEB56C,                             (void *)ql_pcm_open},
	/*[ 12]*/{0xEF6E9746,                             (void *)ql_pcm_read},
	/*[ 13]*/{0xC0504EFE,                             (void *)ql_pcm_write},
	/*[ 14]*/{0x28AC062A,                             (void *)ql_pcm_close},
	/*[ 15]*/{0x4304AB6E,                             (void *)ql_pcm_play_init},
	/*[ 16]*/{0x4B0B3EC8,                             (void *)ql_pcm_play},
	/*[ 17]*/{0xA6969FF8,                             (void *)ql_pcm_play_stop},
	/*[ 18]*/{0x0E66492C,                             (void *)ql_pcm_play_deinit},
#endif	
#ifdef QUEC_WAV_FUNC
	/*[ 35]*/{0xF58A2758,                             (void *)ql_wav_file_play},
	/*[ 39]*/{0x3B4B8F94,                             (void *)ql_wav_file_stop},
    /*[ 22]*/{0xE4611DEA,                             (void *)ql_wav_play},
	/*[ 22]*/{0xD22B9F6E,                             (void *)ql_wav_play_stop},
#endif
#ifdef QUEC_MP3_FUNC
	/*[ 30]*/{0x79120A86,                             (void *)ql_mp3_file_play},
	/*[ 31]*/{0xAA904502,                             (void *)ql_mp3_file_stop},
	/*[ 20]*/{0x5279E300,                             (void *)ql_play_mp3},
	/*[ 22]*/{0x96484B84,                             (void *)ql_play_mp3_stream_buffer},
	/*[ 22]*/{0x3040BDE8,                             (void *)ql_stop_mp3_play},
	/*[ 22]*/{0xB710575E,                             (void *)ql_mp3_get_pcm_handle},
	/*[ 22]*/{0xDFA26F0,                             (void *)ql_mp3_play_get_duration},
	/*[ 22]*/{0xF5DDE938,                             (void *)ql_mp3_stream_get_duration},
#endif
#ifdef QUEC_AMR_FUNC
	/*[ 22]*/{0x4377D52A,                            (void *)ql_amr_file_play},
	/*[ 24]*/{0xC4A988B6,                            (void *)ql_amr_file_stop},
	/*[ 22]*/{0xBAFF6B6C,                            (void *)ql_play_amr},
	/*[ 24]*/{0x88001B8,                             (void *)ql_play_amr_stream_buffer},
	/*[ 25]*/{0x15752214,                            (void *)ql_stop_amr_play},
	/*[ 25]*/{0x072703DA,                            (void *)ql_amr_get_pcm_handle},
	/*[ 26]*/{0x5F317C2,                             (void *)ql_record_amr},
	/*[ 28]*/{0xECF0D5E6,                            (void *)ql_record_amr_stop},
#endif
    /************************************************************************************************
    *   tts 
    *************************************************************************************************/
#if QUEC_AUDIO_TTS_SUPPORT
     /*[ 1]*/{0x775C88B0,                             (void *)ql_tts_init},
     /*[ 2]*/{0xE001DAF6,                             (void *)ql_tts_play},
     /*[ 3]*/{0x145DF132,                             (void *)ql_tts_stop},
     /*[ 4]*/{0xB6C2CB56,                             (void *)ql_tts_state},
     /*[ 5]*/{0xC6AEEB80,                             (void *)ql_tts_set_volume},
     /*[ 6]*/{0x0946A41C,                             (void *)ql_tts_get_volume},
     /*[ 7]*/{0x7AC6381C,                             (void *)ql_tts_set_speed},
     /*[ 8]*/{0x1E7A79C8,                             (void *)ql_tts_get_speed},
     /*[ 9]*/{0xD2165922,                             (void *)ql_tts_deinit},
     /*[ 10]*/{0xEEF9277A,                            (void *)ql_tts_digit_mode},
     /*[ 11]*/{0xBCAC3D8C,                            (void *)ql_get_tts_digit_mode},
     /*[ 1]*/{0xC88764DA,                             (void *)ql_set_tts_file_name},
	 /*[ 2]*/{0x9E78E096,                             (void *)ql_get_tts_file_name},
 #endif

#endif /*QUEC_NOAUDIO*/


 /* audio deniose */
#ifdef QL_AUDIO_DENOISE
#ifdef QUEC_AUDIO_DENOISE
	/*[ 8]*/{0xFD1E5CF6,                             (void *)ql_denoise_licenses_verify},
	/*[ 9]*/{0x967BCAFC,                             (void *)ql_set_denoise_flag},
	/*[ 10]*/{0x937CE268,                            (void *)ql_get_denoise_flag},
	/*[ 11]*/{0x889DCFCA,                            (void *)ql_denoise_get_version},
	/*[ 11]*/{0x6321F70A,                            (void *)ql_denoise_mute_time},
	/*[ 13]*/{0x7F44733E,                            (void *)ql_denoise_get_dev_info},
    /*[ 14]*/{0xD9FFBDF6,                            (void *)ql_denoise_save_info_from_app},
#endif 
#endif

#ifdef QL_AUDIO_KWS
#ifdef QUEC_AUDIO_KWS
    /*[ 13]*/{0x3F57C69C,                            (void *)ql_kws_init},
    /*[ 14]*/{0xF676CACE,                            (void *)ql_kws_process},
    /*[ 15]*/{0xF434AC5E,                            (void *)ql_kws_cleanup},
    /*[ 16]*/{0x4092FECC,                            (void *)hal_websocket_start},
    /*[ 17]*/{0x5C8EDE14,                            (void *)websocket_send_start_signal},
    /*[ 18]*/{0x2905627E,                            (void *)hal_ws_send_write_msg},
    /*[ 19]*/{0x06F27D7A,                            (void *)hal_ws_send_end_write_msg},
    /*[ 20]*/{0x7CBA66F8,                            (void *)ql_set_kws_app_info},
    /*[ 21]*/{0xFE12FF5E,                            (void *)ql_kws_dsp_get_memory_needed},
    /*[ 22]*/{0x30C44088,                            (void *)ql_kws_set_memory_base},
#endif
#endif
    /************************************************************************************************
	*	lcd
	*************************************************************************************************/
	#ifdef QL_LCD
	/*[ 1]*/{0x38630058,				(void *)ql_lcd_init},
	/*[ 2]*/{0x30820D1C,				(void *)ql_lcd_write_sync},
	/*[ 3]*/{0xAE0D6C5C,				(void *)ql_lcd_clear_screen},
	/*[ 4]*/{0xC83C0EE6,				(void *)ql_lcd_display_on},
	/*[ 5]*/{0x295573DC,				(void *)ql_lcd_display_off},
	/*[ 6]*/{0x2F49264C,				(void *)ql_spi_lcd_write_cmd},
	/*[ 7]*/{0xBE5C53CA,				(void *)ql_spi_lcd_write_data},
	/*[ 8]*/{0x78D29074,				(void *)ql_lcd_wakeup},
	/*[ 9]*/{0x2742D542,                (void *)ql_lcd_updata_config},
	/*[ 10]*/{0xEC6A3956,				(void *)ql_lcd_read_id},
	#endif

	
	/************************************************************************************************
	*	camera
	*************************************************************************************************/
	#ifdef 	QL_CAMERA
	/*[1]*/{0x79F1C274,                  (void *)ql_qr_camera_open},
	/*[2]*/{0x1E3AF672,                  (void *)ql_qr_camera_close},
	/*[3]*/{0xAE237E22,                (void *)Ql_Cam_Identify},
	/*[4]*/{0x797C7BCE,                (void *)ql_set_decode_mirror},
	#endif
	/************************************************************************************************
	*	keypad
	*************************************************************************************************/
    #ifdef  QL_KEYPAD
    /*[ 1]*/{0x751C7EDA,                (void *)ql_keypad_Register},
	/*[ 2]*/{0x04B2049E,                (void *)ql_keypad_MultikeyEn},
	/*[ 3]*/{0x29D9AB22,                (void *)ql_keypad_Config},
    #endif
	/************************************************************************************************
	*	gnss
	*************************************************************************************************/
	#ifdef QL_GNSS
	/*[ 1]*/{0xD15CF0D8,               (void *)ql_gnss_open},
	/*[ 2]*/{0xE93EC1EE,               (void *)ql_gnss_close},
	/*[ 3]*/{0x3529A72E,               (void *)ql_gnss_cfgsys_set},
	/*[ 4]*/{0xF5A6FBFA,               (void *)ql_gnss_cfgmsg_set},
	/*[ 5]*/{0x75D387B4,               (void *)ql_gnss_agps_cfg},
	/*[ 6]*/{0xC0783130,               (void *)ql_gnss_apflash_cfg},
	/*[ 7]*/{0x462A201C,               (void *)ql_gnss_reset_type_set},
	/*[ 8]*/{0xDBE6FCC0,               (void *)ql_gnss_get_location},
	/*[ 9]*/{0x51B20D2C,               (void *)ql_get_agps_sate_num},
	/*[ 10]*/{0xCDA477C4,               (void *)ql_set_agps_file},
	/*[ 11]*/{0x4E5B86C0,               (void *)ql_send_agps_to_gps},
	/*[ 11]*/{0x7FF4FC26,               (void *)ql_set_gnss_nmea_mode},
	/*[ 12]*/{0x84842144,               (void *)ql_monitor_param_print},
	/*[ 13]*/{0xBB5DA85E,               (void *)ql_hx_bckp_set},
	/*[ 13]*/{0x772FEF08,				(void *)ql_gnss_agps_param_cfg},
	/*[ 14]*/{0x32C9BF2C,				(void *)ql_gnss_ntp_url_cfg},
	#endif
   /*************************************************************************************************
	* spi_nand?¨C?????3????????¡°??????£¤???
	*************************************************************************************************/
#ifdef QL_NAND_YAFFS
	/*[15]*/{0xA12C908A,                (void *)ql_nand_fopen},
	/*[16]*/{0x5077E310,                (void *)ql_nand_fclose},
	/*[17]*/{0xF4936E14,                (void *)ql_nand_fread},
	/*[18]*/{0x23A6F590,                (void *)ql_nand_fwrite},
	/*[19]*/{0x195EE09A,                (void *)ql_nand_fseek},
	/*[20]*/{0xBE179778,                (void *)ql_nand_fremove},
	/*[21]*/{0xFF7C09BA,                (void *)ql_nand_frename},
	/*[22]*/{0xC5E30FE4,                (void *)ql_nand_fsize},
	/*[23]*/{0x1E9C36C6,                (void *)ql_nand_mkdir},
	/*[24]*/{0x1D34B818,                (void *)ql_nand_access},
	/*[25]*/{0x0B703784,                (void *)ql_nand_get_free_size},
	/*[26]*/{0xDFF47F80,                (void *)ql_nand_format},
	/*[27]*/{0xDD91734,                 (void *)ql_spi_nand_init},
	/*[28]*/{0x2A79192,                 (void *)ql_nand_removedir},
	/*[29]*/{0x6814E202,                 (void *)ql_nand_closedir},
	/*[30]*/{0x26E61DA ,                 (void *)ql_nand_readddir},
	/*[31]*/{0xD0103DE0 ,                (void *)ql_nand_opendir},
	/*[32]*/{0x3263B33A ,                (void *)ql_nand_lstat},
	/*[33]*/{0x12B37820 ,                (void *)ql_nand_lseek},
	/*[34]*/{0xDC61E364 ,                (void *)ql_nand_ftell},
	/*[35]*/{0x85ADC424 ,                (void *)ql_nand_fgetc},
	/*[36]*/{0x826C17F4 ,                (void *)ql_nand_fgets},
	/*[37]*/{0xDE2B03F2 ,                (void *)ql_nand_fsync},
	/*[38]*/{0x5D06D9E ,                 (void *)ql_nand_feof},
	/*[39]*/{0x9990DC6E ,                (void *)ql_nand_frewind},
	/*[40]*/{0xA157B608 ,                (void *)ql_nand_yaffs_sync},
    /*************************************************************************************************
     * yaffs????¡±???£¤??¡ê
     *************************************************************************************************/
    /*[1]*/{0xE28F4C3C ,                (void *)ql_yaffs_start_up},
    /*[2]*/{0xF82E4126 ,                (void *)ql_yaffs_create_dev},
    /*[3]*/{0xFFA11320 ,                (void *)ql_yaffs_mount},
    /*[4]*/{0x5B0A2BE4 ,                (void *)ql_yaffs_unmount},
    /*[5]*/{0xA9E25CCE ,                (void *)ql_yaffs_open},
    /*[6]*/{0x610CEC04 ,                (void *)ql_yaffs_close},
    /*[7]*/{0xA70E9038 ,                (void *)ql_yaffs_read},
    /*[8]*/{0x24B3AB5C ,                (void *)ql_yaffs_write},
    /*[9]*/{0x33C8D172 ,                (void *)ql_yaffs_lseek},
    /*[10]*/{0x50D9B6FE ,                (void *)ql_yaffs_unlink},
    /*[11]*/{0x77B4EEFA ,                (void *)ql_yaffs_fsize},
    /*[12]*/{0xF883CD7E ,                (void *)ql_yaffs_rename},
    /*[13]*/{0x1AA739C ,                 (void *)ql_yaffs_mkdir},
    /*[14]*/{0x4BC0BED6 ,                 (void *)ql_yaffs_opendir},
    /*[15]*/{0x3DEA7F8 ,                 (void *)ql_yaffs_closedir},
    /*[16]*/{0x411CB61A ,                (void *)ql_yaffs_rmdir},
    /*[17]*/{0x1159BEA ,                 (void *)ql_yaffs_access},
    /*[18]*/{0xE498967E ,                (void *)ql_yaffs_freespace},
    /*[19]*/{0x85804928 ,                (void *)ql_yaffs_fsync},
    /*[20]*/{0x59835EC6 ,                (void *)ql_yaffs_sync},    
    /*[21]*/{0xD758D016 ,                (void *)ql_yaffs_format},
    /*[22]*/{0x78A25B32 ,                (void *)ql_yaffs_ftell},
    /*[23]*/{0xCAB513A ,                 (void *)ql_yaffs_fgetc},
    /*[24]*/{0xD59FACA ,                 (void *)ql_yaffs_fgets},
    /*[25]*/{0xF37E2630 ,                (void *)ql_yaffs_feof},
    /*[26]*/{0x5557FA2C ,                (void *)ql_yaffs_frewind},
    /*[27]*/{0x746E35E8 ,                (void *)ql_yaffs_readddir},
    /*[28]*/{0x208AE2BC ,                (void *)ql_yaffs_lstat},
#endif

#ifdef QUEC_BT_SUPPORT
	/************************************************************************************************
	*	BT
	*************************************************************************************************/
	/*[ 1]*/{0x1D3E22C4,							 (void *)ql_bt_open},
	/*[ 2]*/{0xD26E3882,							 (void *)ql_bt_close},
	/*[ 3]*/{0x8118C6C6,							 (void *)ql_bt_get_bt_address},
	/*[ 3]*/{0x6A740B3A,							 (void *)ql_bt_set_bt_address},
	/*[ 4]*/{0xC810C3FA,							 (void *)ql_bt_inquiry},
	/*[ 5]*/{0x09E42D98,							 (void *)ql_bt_inquiry_cancel},
	/*[ 6]*/{0xEE8D46C0,							 (void *)ql_bt_connect_headset},
	/*[ 7]*/{0x1628EDBE,							 (void *)ql_bt_set_visiable},
	/*[ 8]*/{0x54216686,							 (void *)ql_bt_le_set_gap_name},
	/*[ 9]*/{0x8A5F8D36,							 (void *)ql_bt_le_create_adv_data},
	/*[ 10]*/{0xD0795CC8,							 (void *)ql_bt_le_set_adv_data},
	/*[ 11]*/{0x17D075EA,							 (void *)ql_le_set_scan_response_data},
	/*[ 12]*/{0xCAE5BB6A,							 (void *)ql_bt_le_set_adv_parameters},
	/*[ 13]*/{0xE4FFBAFE,							 (void *)ql_bt_le_set_adv_enable},
	/*[ 14]*/{0xBE0A7B4A,							 (void *)ql_bt_le_register_service},
	/*[ 15]*/{0x4236F5CE,							 (void *)ql_bt_le_unregister_service},
	/*[ 16]*/{0xC69D2CB6,							 (void *)ql_get_bt_open_status},
	/*[ 17]*/{0xCCAA3672,							 (void *)ql_bt_le_set_random_address},
	/*[ 18]*/{0x90DC0BD4,							 (void *)ql_bt_le_set_ext_adv_parameters},
	/*[ 19]*/{0xFFAA2940,							 (void *)ql_bt_le_set_adv_set_random_address},
	/*[ 20]*/{0x7602EDB2,							 (void *)ql_bt_le_set_ext_adv_data},
	/*[ 21]*/{0xA8EC6DDA,							 (void *)ql_bt_le_set_ext_scan_response},
	/*[ 22]*/{0xC59D0024,							 (void *)ql_bt_le_set_ext_adv_enable},
	/*[ 23]*/{0x63BD02F4,							 (void *)ql_appbt_le_notify},
	/*[ 24]*/{0x836293EC,							 (void *)ql_read_rssi},
	/*[ 25]*/{0xCC291F20,							 (void *)ql_bt_le_set_pair_enable},
	/*[ 26]*/{0xD3728C4E,							 (void *)ql_bt_le_disconnect},
	/*[ 27]*/{0x123B9DE6,							 (void *)ql_get_scan_bt_status},
	/*[ 28]*/{0x77604E28,							 (void *)ql_get_bt_connect_status},
	/*[ 29]*/{0x02DAF47C,                            (void *)ql_bt_send_bttask_command},
	/*[ 30]*/{0x3183CDF0,							 (void *)ql_bt_accept_bonding},
	/*[ 31]*/{0xC92EE81C,                            (void *)ql_bt_sort_device_record},
	/*[ 32]*/{0x22E49518,							 (void *)ql_bt_a2dp_connected_handler},
	/*[ 33]*/{0xBF151AE8,							 (void *)ql_bt_hfp_accept_connection},
	/*[ 34]*/{0x446BFE14,							 (void *)ql_bt_mgr_handler}, 
	/*[ 35]*/{0x73F7234A,							 (void *)ql_bt_a2dp_disconnected_handler},
	/*[ 36]*/{0xA3615FA8,                            (void *)ql_bt_add_device_record},
	/*[ 37]*/{0x5CDE002A,							 (void *)ql_bt_sco_connect},
	/*[ 38]*/{0x0706AA4C,							 (void *)ql_bt_obex_disconnect},
	/*[ 39]*/{0x81C34A40,                            (void *)ql_bt_spp_disconnect},
	/*[ 40]*/{0xA0192C5C,							 (void *)ql_bt_a2dp_start_handler},
	/*[ 41]*/{0xC8BF8E60,                            (void *)ql_bt_close_set},
	/*[ 42]*/{0x69A7104C,							 (void *)ql_bt_a2dp_remote_sbc_capabilities_handler},
	/*[ 43]*/{0x2E98372A,							 (void *)ql_bt_pin_reply},
	/*[ 44]*/{0xB648893C,							 (void *)ql_bt_a2dp_send_start},
	/*[ 45]*/{0x47C3252C,							 (void *)ql_bt_obex_send_response},
	/*[ 46]*/{0x5841F218,                            (void *)ql_bt_spp_send_data},
	/*[ 47]*/{0x01811BBE,							 (void *)ql_bt_a2dp_send_suspend},
	/*[ 48]*/{0xD0C8EA82,							 (void *)ql_bt_a2dp_send_pcm_data},
	/*[ 49]*/{0xB343890A,							 (void *)ql_bt_le_read_by_group_type_request},
	/*[ 50]*/{0xE24A6E86,                            (void *)ql_bt_le_get_device_records},
	/*[ 51]*/{0x14DEFFE8,                            (void *)ql_le_find_information_request},
	/*[ 52]*/{0x32DBF034,							 (void *)ql_bt_le_connect},
	/*[ 53]*/{0x7E61A766,                            (void *)ql_ble_update_device_record},
	/*[ 54]*/{0xC3BF4CCE,							 (void *)ql_bt_le_read_by_type_request},
	/*[ 55]*/{0x3B71E16C,							 (void *)ql_bt_le_mtu_request},
	/*[ 56]*/{0x5142C594,							 (void *)ql_bt_free},
	/*[ 57]*/{0xBC81F0E2,							 (void *)ql_bt_le_scan_stop},
	/*[ 58]*/{0xF2FDEAA8,							 (void *)ql_bt_le_register_att_service},
	/*[ 59]*/{0xE7E82A82,							 (void *)ql_le_get_pair_info},
	/*[ 60]*/{0x1774CC42,							 (void *)ql_le_remove_pair_info},
	/*[ 61]*/{0xCC946014,							 (void *)ql_le_send_service_change},
	/*[ 62]*/{0xEECB2E6E,							 (void *)ql_bt_le_scan},
	/*[ 63]*/{0xD107D70E,							 (void *)ql_le_custom_gatt_scan_start},
	/*[ 64]*/{0x76CFB4CA,							 (void *)ql_le_custom_write_command},
	/*[ 65]*/{0xFEFE3DF0,							 (void *)ql_le_custom_write_request},
	/*[ 66]*/{0x2E737178,							 (void *)ql_le_custom_read_request},
	/*[ 67]*/{0xEA905582,							 (void *)ql_le_custom_mtu_request},
	/*[ 68]*/{0xD88B25B4,							 (void *)ql_le_disconnect_with_handle},
	/*[ 69]*/{0xAF0894F2,							 (void *)ql_le_set_adv_mode},
	/*[ 70]*/{0x7FAEA68C,							 (void *)ql_le_custom_connection_parameter_update_request},
	/*[ 71]*/{0xBF151AE8,							 (void *)ql_bt_hfp_accept_connection},
	/*[ 72]*/{0x0B2CF450,                            (void *)ql_bt_acl_connect},
	/*[ 73]*/{0x54D7A922,                            (void *)ql_bt_acl_disconnect},
	/*[ 74]*/{0xDB36D888,							 (void *)ql_bt_bonding},
    /*[ 75]*/{0xD7713B1C,							 (void *)ql_bt_unbond},
	/*[ 76]*/{0xE0E51516,							 (void *)ql_bt_pin_negative_reply},
	/*[ 77]*/{0x83B4D58E,                            (void *)ql_bt_spp_connect},
	/*[ 78]*/{0xF007F94A,							 (void *)ql_bt_obex_send_file},
	/*[ 79]*/{0xE70CCE3E,							 (void *)ql_bt_get_open_status},
	/*[ 80]*/{0x608CB39A,							 (void *)ql_bt_obex_connect},
	/*[ 81]*/{0x030A17D8,							 (void *)ql_bt_switch_voice_to_phone},
	/*[ 82]*/{0xC9AEEB36,							 (void *)ql_bt_switch_voice_to_headset},
	/*[ 83]*/{0x633AC9E4,							 (void *)ql_bt_avrcp_connect},
	/*[ 84]*/{0x561505DE,							 (void *)ql_bt_avrcp_disconnect},
	/*[ 85]*/{0x948C173C,							 (void *)ql_bt_sco_disconnect},
	/*[ 86]*/{0xF2A630F4,							 (void *)ql_bt_hfp_connect},
	/*[ 87]*/{0x70EF538E,							 (void *)ql_bt_hfp_disconnect},
    /*[ 88]*/{0x9F06F9DE,							 (void *)ql_bt_disconnect_headset},	
	/*[ 89]*/{0x6BC0D4FC,							 (void *)ql_bt_hfp_reject_connection},
	/*[ 90]*/{0x9543B676,							 (void *)ql_bt_hfp_update_callstatus},
	/*[ 91]*/{0x88B165C8,							 (void *)ql_bt_hfp_update_phone_number},
	/*[ 92]*/{0xB569E0CE,							 (void *)ql_bt_hfp_update_callhold},
	/*[ 93]*/{0xE6856B28,							 (void *)ql_bt_hfp_callhold},
	/*[ 94]*/{0xEBBDA310,							 (void *)ql_bt_hfp_voice_recogonition},
	/*[ 95]*/{0x98B8638E,							 (void *)ql_bt_hfp_set_speaker_gain},
	/*[ 96]*/{0x331CA0A8,							 (void *)ql_bt_hfp_set_microphone_gain},
	/*[ 97]*/{0x1C26A2AC,							 (void *)ql_bt_a2dp_SBC_test_send_message},
	/*[ 98]*/{0x45E0B5C6,							 (void *)ql_bt_a2dp_connect},
	/*[ 99]*/{0x8A755CA8,							 (void *)ql_bt_a2dp_disconnect},
	/*[100]*/{0xFB763012,							 (void *)ql_bt_a2dp_send_sbc_data},
	/*[101]*/{0x11075754,							 (void *)ql_bt_bt_dut},
	/*[102]*/{0xABD5B9D0,							 (void *)ql_bt_change_local_name},
	/*[103]*/{0x9251130A,							 (void *)ql_bt_cancel_acl_connect},
    /*[104]*/{0x6FA6BDFC,                            (void *)ql_bt_get_device_records},	
	/*[105]*/{0x1255F6C0,							 (void *)ql_bt_update_device_record},
	/*[106]*/{0xC2606BE0,                            (void *)ql_bt_hfp_atchld},

#endif

};

u16 ql_user_api_table_size = 0;

void ql_user_api_table_init(void)
{
	ql_user_api_table_size = sizeof(vUserAPITable)/sizeof(vUserAPITable[0]);
}

