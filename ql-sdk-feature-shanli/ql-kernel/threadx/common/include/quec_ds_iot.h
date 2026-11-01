/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#include "ci_api.h"
#include "telcontroller.h"
#include "telatci.h"
#include "telconfig.h"
#include "telatparamdef.h"
#include "teldbg.h"
#include "telcc.h"
#include "telmm.h"
#include "telps.h"
#include "telpb.h"
#include "telss.h"
#include "teldev.h"
#include "teldat.h"
#include "telmsg.h"
#include "telsim.h"
#include "utlMalloc.h"
#include <stdio.h>
#include <osa.h>
#include "utlTrace.h"
#include "stub.h"
#include "stdlib.h"
#include "string.h"
#include "telcmux.h"
#include "m2m_api.h"
#include "telm2m.h"
#include "teldef.h"
#include "teldbg.h"
#include "quec_include.h"
#include "quec_siolib.h"
#include "quec_urc.h"
#include "string_utils.h"
#include "quec_cust_feature.h"
#include "quec_msg_process.h"
#include "quec_atcmd_param.h"
#include "quec_at_common.h"
#include "quec_atcmd_tcpip.h"
#include "quec_net.h"
#include "quec_tcpip_app.h"
#include "quec_net_app.h"
#include "float.h"


#include "quec_iot_app.h"
#include "quec_iot_msg.h"
#include "quectel_apptcpip_util.h"
#include "fat32_file_opt.h"
#ifdef QUECTEL_IOT_RPT_SUPPORT

typedef  unsigned char      boolean; 
#define QUEC_IOTRPT_CONFIG_CONTEXT "iotrpt_context.config"
#define QUEC_IOTRPT_SERVER_CONFIG_CONTEXT "iotrpt_server_context.config"
#define QUEC_IOTRPT_TIMER_CONFIG_CONTEXT "iotrpt_timer_context.config"
#define QUEC_IOTRPT_UEICCID_CONFIG_CONTEXT "iotrpt_ueiccid_context.config"

typedef enum
{
	DS_IOT_OK              = 0,
	DS_IOT_ERROR           = 801,
	DS_IOT_WOULDBLOCK      = 802,
	DS_IOT_BUSY            = 803,
	DS_IOT_NETWORK_ERR     = 804,
	DS_IOT_INVALID_PARAM   = 810,
}quectel_ds_iot_error_code;

typedef enum
{
	QUEC_IOT_CFG_PDP_CID = 0,
	QUEC_IOT_CFG_SEVER_INFO,
	QUEC_IOT_CFG_UEICC_ID,
	QUEC_IOT_CFG_ENCRYPT,
	QUEC_IOT_CFG_TIMEOUT,
	QUEC_MAX_IOT_CFG_TYPE
}iot_cfg_type;

typedef struct
{
	UINT8						uEnable;
	UINT8						is_send_urc;
	int32						pdp_cid;
	UINT32						atHandle;
	boolean						iot_opened;
	int							sio_port;
	int32						encrypt;
	int32						retry;
	int32						current_cnt;
	int32						rsp_timeout;
	int32						creg_retry;
	int32						creg_rsp_timeout;
	char						server_addr_str[256];
	char						ueiccid[32];
	quec_ip_addr				server_ip;
	UINT16						server_port;
	int							decode_state;
	int							retry_time;
	boolean						call_close;

	int							register_mode;
	
	OSATimerRef					creg_timer;
	OSATimerRef					ps_reg_timer;

	quectel_iot_context			*iot_ctx;
	boolean						wm_have_init;
	quec_tcpip_transfer_session	trans_wm_ptr;
}quectel_iot_mgr;


typedef struct
{
	int						uEnable;
	int						is_send_urc;
	int						sio_port;
}quectel_iotrpt_nv_param;

typedef struct
{
	char					server_addr_str[256];
	UINT16					server_port;
}quectel_iotrpt_sever_nv_param;


typedef struct
{
	int						retry;
	int						rsp_timeout;
}quectel_iotrpt_timer_nv_param;


RETURNCODE_T ds_iot_cfg
(
UINT32 atHandle, 
utlAtParameterValue_P2c  parameter_values_p, 
UINT8	arg_cnt
);

RETURNCODE_T  ds_iotrpt_open
(
UINT32 atHandle, 
utlAtParameterValue_P2c  parameter_values_p, 
UINT8	arg_cnt
);

void ds_iot_event_cb
(
quectel_iot_event_enum event, 
quectel_iot_event_info_type *event_ptr
);

RETURNCODE_T  ds_iotrpt_state
(
UINT32 atHandle, 
utlAtParameterValue_P2c  parameter_values_p, 
UINT8	arg_cnt
);

void quectel_iot_get_data
(
quectel_iot_data_context * iot_data
);

UINT8 quec_iot_check_net_status(void);

boolean quec_iot_check_iccid_is_register(void);

#endif

