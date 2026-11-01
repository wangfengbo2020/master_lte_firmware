/**  @file
  quec_fota_feed_task.h

  @brief
  This file is used to define the fota feed task thread for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
01/15/2019       Larson      Init version
=================================================================*/


#ifndef _QUEC_FOTA_FEED_TASK_H
#define _QUEC_FOTA_FEED_TASK_H

/*> include header files here*/
#include "quec_common.h"
#include "quec_cust_feature.h"
#include "quec_fota_task.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef QUEC_FOTA_FEED_SUPPORT

/*========================================================================
 *  Macro Definition
 *========================================================================*/
#define QUEC_FOTAUPL_PATH_MAX_LEN            (256)
#define QUEC_FOTA_FEED_TASK_STACK_SIZE      (2<<12)     /* fota feed task stack size     */
#define QUEC_FOTA_FEED_QUEUE_MAX            (128)        /* fota feed queue max numbers   */
#define QUEC_FOTA_FEED_FLAG_VALUE           (1)         /* file feed flag mask value     */


#define QUEC_FOTA_DATA_TYPE_FILE        "FILE:"
#define QUEC_FOTA_DATA_TYPE_HTTP        "HTTP:"
#define QUEC_FOTA_DATA_TYPE_FTP         "FTP:"

#define QUEC_ATCMD_PARAM_1 0  //at param index
#define QUEC_ATCMD_PARAM_2 1
#define QUEC_ATCMD_PARAM_3 2
#define QUEC_ATCMD_PARAM_4 3
#define QUEC_ATCMD_PARAM_5 4

#define QUEC_FOTA_FILE_SIZE_DEFAULT (10<<10)

#define QUEC_FOTA_FILE_LENGTH_MIN 0
#define QUEC_FOTA_FILE_LENGTH_MAX 0x7fffffff
#define QUEC_FOTA_FILE_LENGTH_DEFAULT QUEC_FOTA_FILE_SIZE_DEFAULT //should get storage size

#define QUEC_FOTA_UPGRADE_MODE_MIN 0
#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
#define QUEC_FOTA_UPGRADE_MODE_MAX 2
#else
#define QUEC_FOTA_UPGRADE_MODE_MAX 1
#endif

#define QUEC_FOTA_UPGRADE_MODE_DEFAULT 1

/* fota download flag range */
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
#define QUEC_FOTA_URC_NUM_NONE      (0)
#define QUEC_FOTA_URC_NUM_MIN       (5)
#define QUEC_FOTA_URC_NUM_MAX       (100)
#define QUEC_FOTA_GENUS_URC_NUM     (5)
#endif

#define FOTA_IND_HEADR_STR			"+QIND: \"FOTA\","
#define FOTA_IND_UPGRADE_START_STR	"\"START\"\r\n"
#define FOTA_IND_UPGRADE_ING_STR	"\"UPDATING\","
#define FOTA_IND_UPGRADE_END_STR	"\"END\","
#define FOTA_IND_HTTP_START_STR		"\"HTTPSTART\"\r\n"
#define FOTA_IND_HTTP_END_STR		"\"HTTPEND\","
#define FOTA_IND_FTP_START_STR		"\"FTPSTART\"\r\n"
#define FOTA_IND_FTP_END_STR		"\"FTPEND\","
#define FOTA_IND_FILE_START_STR		"\"FILESTART\"\r\n"
#define FOTA_IND_FILE_END_STR		"\"FILEEND\","
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
#define FOTA_IND_DOWNLOAD_ING_STR	"\"DOWNLOADING\","
#endif

#define QUEC_FOTA_CID_MIN	(1)
#define QUEC_FOTA_CID_MAX	(15)




/*========================================================================
 *  Enumeration Definition
 *========================================================================*/

/* fota upgrade start status */
typedef enum{
	QUEC_FOTA_UPGRADE_STOP = 0,
	QUEC_FOTA_UPGRADE_START
}QUEC_FOTA_UPGRADE_STATUS;


/* Data source type */
typedef enum
{
	FOTA_FILE = 0, 			/* FILE 		 */
	FOTA_HTTP, 				/* HTTP 		 */
	FOTA_FTP,				/* FTP			 */
	FOTA_MAX
}QF_DATATYPE;

typedef enum
{
	UPGRADE_WAIT = 0,        /* wait user manually restart */
	UPGRADE_NOW              /* Upgrade now after restart  */
}QF_UPGRADEETYPE;

/* Disable/Enable URC report when FOTA downloading */
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
typedef enum
{
    FOTA_DOWNLOAD_URC_DISABLE = 0,
    FOTA_DOWNLOAD_URC_ENABLE = 1,    
}QF_DOWNLOAD_FLAG;
#endif

typedef enum
{
    FOTA_RX_WM_LOW = 0,
    FOTA_RX_WM_HIGH,
}quec_fota_wm_type;

#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
typedef enum
{
    PROTOCOL_DOWNLOAD_EXIT = 0,
    PROTOCOL_DOWNLOAD_CMD_MODE = 1,
    PROTOCOL_DOWNLOAD_DATA_TRNSPORT=2,
}quec_protocol_down_state;


#endif


/*========================================================================
 *  Type Definition
 *========================================================================*/
#ifdef QUEC_JUDGE_FOTA_FILE_EXIST
		typedef struct qfotafile_exist_param
		{
			uint8			 mode;/*1: 8M mini Os*/
			uint8			 type;/*0: judge mini firmware ,1:judge large*/
			uint8			 rsv1;
			uint8			 rsv2; 
		}qfotafile_exist_st;
		extern qfotafile_exist_st ffexist_st;
#define QUEC_8M_MINIOS_MODE	(1)
#endif

typedef struct qfotaupl_param
{
	char              path_name[QUEC_FOTAUPL_PATH_MAX_LEN];
	quec_fota_path_e  data_type;      //数据来源类型
	uint32            upgrade_flag;   //是否立即升级
	uint32            want_size;      //期待总长度
	uint32            size_uploaded;  //文件以送给fota_task长度
#ifdef QUEC_FOTA_HTTP_RETRY_SUPPORT
	uint32            remaining_size; //Remaining size to download when http  fota retry 
#endif
	uint32            cache_count;    //缓存长度
	uint32            atHandle;       //处理句柄
	uint32            current_dw_len; //当前正在接收数据长度
	TelAtParserID     atp_index;      //数据来源索引
	QuecOSStatus      error_code;     //升级错误标致
	uint16            fota_error_code; //fota upgrade error
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
    uint8             dl_urc_num;     //max number of urc when downloading
    uint8             up_urc_num;     //max number of urc when updating
    uint8             urc_cnt;        //urc report counter  
    uint32            flash_wr_size;  //Size of data has writen to flash
    uint32            flash_want_size;//Expect total size write to falsh
#ifdef __QUEC_OEM_VER_LT__
    uint8             report_urc_num; //report urc times for downloading
    uint32            report_urc_size;//already reported length
#endif
#endif

#ifdef QUEC_PROTOCOL_DOWNLOAD_FILE_FOTA
    uint8 protocol_down_flag;
#endif
#ifdef QUECTEL_QUECFOTA_SUPPORT
	uint32			  quecfota_fota_flag;	//quecfota_fota_flag:1:quecfota enable.0:disable quecfota
#endif
    uint8			  fota_exit_flag; //fota http exit flag
}QFOTAUPL_PARAM;


extern QUEC_FOTA_UPGRADE_STATUS g_quec_fota_feed_status;

/******************************************************************
*	 Functions
******************************************************************/
QuecOSStatus quec_fota_feed_flag_init(void);
QuecOSStatus quec_fota_feed_flag_exit(void);
QuecOSStatus quec_fota_feed_flag_wait(uint32 *flag_value);
QuecOSStatus quec_fota_feed_flag_release(uint32 flag_vaue);
QuecOSStatus quec_fota_feed_queue_init(void);
QuecOSStatus quec_fota_feed_queue_exit(void);
QuecOSStatus quec_fota_feed_queue_put_data(quec_fota_msg_s *cmd_ptr);
uint32       quec_fota_feed_queue_cnt_get(void);
QuecOSStatus quec_fota_feed_factor_init(QFOTAUPL_PARAM *qfotaupl_param);
QuecOSStatus quec_fota_feed_exit(void);
QuecOSStatus quec_fota_feed_init(void);
uint8 quec_fota_cid_get(void);
QuecOSStatus quec_fota_cid_set(uint8 fota_cid);
int quec_fota_urc_cnt_get(void);
void quec_fota_update_urc_set(void);
//report the fota upgrade result urc
QuecOSStatus quec_fota_upgrade_result_urc_report(void);
QUEC_FOTA_UPGRADE_STATUS quec_fota_status_get(void);
#ifdef QUEC_FOTA_DOWNLOAD_URC_SUPPORT
void quec_fota_set_ftp_want_size(uint32 size);
void quec_fota_download_urc_report(uint32 data_len);
#ifdef QUEC_JIEDIAN_PROJECT
void quec_fota_download_urc_report_jiedian(uint32 data_len);
#endif
int quec_fota_update_urc_get(void);
void quec_fota_set_flash_want_size(uint32 size);
#endif

/* fota  timer opration */
QuecOSStatus quec_fota_timer_create(void);
QuecOSStatus quec_fota_timer_start(uint32 init_time, bool cyclical_enable, void(* callback_routine)(UINT32), uint32 timer_argc);
QuecOSStatus quec_fota_timer_stop(void);
QuecOSStatus quec_fota_timer_delete(void);
void QuecFotaTimerCallback(UINT32          timer);

#ifdef QUEC_FTP_FOTA_SUPPORT
extern void quec_ftp_fota_exit(void);
#endif

//RETURNCODE_T  quec_exec_qfotadl_cmd
//(
//	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
//	const char					   *command_name_p, 	 /* AT cmd name 		 */
//	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
//	const size_t					num_parameters, 	 /* AT cmd number		 */
//	const char					   *info_text_p,		 /* AT cmd usage string  */
//	unsigned int				   *xid_p,				 /* AT cmd handle		 */
//	void						   *arg_p				 /* AT cmd parser number */
//);


#ifdef QUEC_JIEDIAN_PROJECT
RETURNCODE_T  quec_exec_Jfotadl_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_Jfotagrd_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);

#endif

#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif

