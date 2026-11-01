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
04/11/2020 		  Luffy      modify qiaccept logic same as ASR code frame such as /proc/cnf/ind	 add msgid 
=================================================================*/

#ifndef QUEC_APPTCPIP_MSG_H
#define QUEC_APPTCPIP_MSG_H

#include "modem_platform.h"
#include "quec_include.h"

#include "quec_net.h"


#ifdef QUEC_APPTCPIP_SUPPORT


#ifdef QUEC_ATCMD_LOG
	#define apptcpip_printf(msg, ...)  custom_log("apptcpip", msg, ##__VA_ARGS__)
#else
	#define apptcpip_printf(msg, ...)
#endif

#define apptcpip_min(a,b) (a > b)?b:a



#define QUEC_APPTCPIP_BUFFER_MODE    0
#define QUEC_APPTCPIP_URC_MODE       1
#define QUEC_APPTCPIP_DATA_MODE      2

typedef enum{
	QUEC_APPTCPIP_OK = 0,
	QUEC_APPTCPIP_INVALID_PARAM = -1,
	QUEC_APPTCPIP_OPT_WODBLOCK = -2,
	QUEC_APPTCPIP_OUT_OF_MEM = -3,
	QUEC_APPTCPIP_NOT_ALLOW = -4,
	QUEC_APPTCPIP_NET_OPEN_FAIL = -5,
	QUEC_APPTCPIP_NET_CLOSE_FAIL = -6,
	QUEC_APPTCPIP_CONNECT_ID_USED = -7,
	QUEC_APPTCPIP_SOC_CREATE_FAIL = -8,
	QUEC_APPTCPIP_SOC_BIND_FAIL = -9,
	QUEC_APPTCPIP_SOC_CONNECT_FAIL = -10,
	QUEC_APPTCPIP_SOC_LISTEN_FAIL = -11,
	QUEC_APPTCPIP_SOC_CLOSE_FAIL = -12,
	QUEC_APPTCPIP_DNS_FAIL = -13,
	QUEC_APPTCPIP_NET_NOT_OPEN = -14,
#ifdef QUEC_SSL_SUPPORT
    QUEC_APPTCPIP_SSL_CONNECT_ID_USED = -15,
#endif
	QUEC_APPTCPIP_TIMEOUT = -16,
	QUEC_APPTCPIP_SOC_CLOSED = -17,
	QUEC_APPTCPIP_NET_DOWN = -18,
#ifdef QUEC_TCPIP_SENDCRC_SUPPORT
    QUEC_APPTCPIP_CRC16_ERROR = -19,
#endif
}quec_apptcpip_err_code;

typedef enum{
	QUEC_ATCMD_RESULT_ERROR,
	QUEC_ATCMD_RESULT_OK,
}quec_apptcpip_atcmd_result;

typedef enum{
	QUEC_APPTCPIP_MIN_MSG = 0,
		//TCPIP Command
	QUEC_APPTCPIP_PDP_PROFILE_SET_REQ,//1
	QUEC_APPTCPIP_PDP_PROFILE_SET_CNF, 

	QUEC_APPTCPIP_PDP_PROFILE_GET_REQ,//3
	QUEC_APPTCPIP_PDP_PROFILE_GET_CNF,

	QUEC_APPTCPIP_PDP_ACTIVE_REQ,//5
	QUEC_APPTCPIP_PDP_ACTIVE_CNF,

	QUEC_APPTCPIP_PDP_INFO_GET_REQ,//7
	QUEC_APPTCPIP_PDP_INFO_GET_CNF,

	QUEC_APPTCPIP_PDP_DEACTIVE_REQ,//9
	QUEC_APPTCPIP_PDP_DEACTIVE_CNF,

	QUEC_APPTCPIP_PDP_DEACTIVE_IND,//11

	QUEC_APPTCPIP_DNS_GET_REQ,//12
	QUEC_APPTCPIP_DNS_GET_CNF,

	QUEC_APPTCPIP_DNS_SET_REQ,//14
	QUEC_APPTCPIP_DNS_SET_CNF,

	QUEC_APPTCPIP_DNS_REQ, //at+qidnsgip
	QUEC_APPTCPIP_DNS_CNF,
	
	QUEC_APPTCPIP_TCPIP_SOC_EVENT_IND, //18
	
	QUEC_APPTCPIP_TCPIP_OPEN_REQ,//19
	QUEC_APPTCPIP_TCPIP_OPEN_CNF,

	QUEC_APPTCPIP_TCPIP_DATA_READ_IND,//dest to at//21
	QUEC_APPTCPIP_TCPIP_READ_REQ,
	QUEC_APPTCPIP_TCPIP_READ_CNF,
	QUEC_APPTCPIP_TCPIP_TX_FLOW_CTRL_IND, //dest to tcpip //24

	QUEC_APPTCPIP_TCPIP_DATA_WRITE_IND, //dest to tcpip//25
	QUEC_APPTCPIP_TCPIP_SEND_REQ,//26
	QUEC_APPTCPIP_TCPIP_SEND_CNF,
	QUEC_APPTCPIP_TCPIP_RX_FLOW_CTRL_IND, //dest to at

	QUEC_APPTCPIP_TCPIP_CLOSE_REQ,
	QUEC_APPTCPIP_TCPIP_CLOSE_CNF,
	QUEC_APPTCPIP_TCPIP_CLOSE_IND, //dest to at

#ifdef QUEC_CIP_TCP_SUPPORT
	QUEC_CIP_TCPIP_CLOSE_REQ,
	QUEC_CIP_TCPIP_STATE_INFO_CNF,
#endif
	QUEC_APPTCPIP_TCPIP_ACCEPT_IND,

	QUEC_APPTCPIP_TCPIP_STATE_INFO_REQ,
	QUEC_APPTCPIP_TCPIP_STATE_INFO_CNF,

	QUEC_APPTCPIP_TCPIP_CHANGE_MODE_REQ,
	QUEC_APPTCPIP_TCPIP_CHANGE_MODE_CNF,

	QUEC_APPTCPIP_TCPIP_EXIT_DATA_MODE_IND, //dest to at

#ifdef QUEC_NTP_SUPPORT
	QUEC_APPTCPIP_NTP_SET_CMD,
	QUEC_APPTCPIP_NTP_CNF,
	QUEC_APPTCPIP_NTP_EVENT_IND,
	QUEC_APPTCPIP_NTP_TIMEOUT_IND,
#endif
    QUEC_APPTCPIP_PDP_DEACTEXTIVE_REQ,
    QUEC_APPTCPIP_PDP_DEACTEXTIVE_CNF,
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
	QUEC_APPTCPIP_TCPIP_QIACCEPT_REQ,
	QUEC_APPTCPIP_TCPIP_QIACCEPT_CNF,
	QUEC_APPTCPIP_TCPIP_QIACCEPT_IND,
#endif
#ifdef QUEC_TCPIP_PUSH_AT_PARSER_32BYTE_MULTIPLE_0A
	QUEC_APPTCPIP_ENTER_DIRECT_PUSH_MODE_REQ,
#endif
#ifdef QUECTEL_QISEND_AUTO_BYTIME
    QUEC_APPTCPIP_AUTO_SEND_REQ,
#endif
#ifdef QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE
	QUEC_APPTCPIP_TCPIP_EDIT_TIMEOUT_IND,
#endif
#ifdef QUEC_TCPIP_DATAMODE_NETDOWN_URC_FIX
    QUEC_APPTCPIP_TCPIP_NETDOWN_IND,
#endif
#ifdef QUEC_TCIOT_SUPPORT
	QUEC_APPTCPIP_TCIOT_TCREGNET_REQ,		//at+tcregnet
	QUEC_APPTCPIP_TCIOT_TCREGNET_CNF,
#endif
#ifdef QUEC_TCPIP_SWITCH_MULTIPLE_MODE_FEATURE
	QUEC_APPTCPIP_TCPIP_CHANGE_MULTIPLE_MODE_REQ,
	QUEC_APPTCPIP_TCPIP_CHANGE_MULTIPLE_MODE_CNF,
#endif
	QUEC_APPTCPIP_TCPIP_CHECK_URC_REPORT,
	QUEC_APPTCPIP_MAX_MSG
}quec_apptcpip_msg_id;

#ifdef QUECTEL_QISEND_AUTO_BYTIME
typedef struct{
	int 			  client_id;
}quec_apptcpip_auto_send_req;
#endif


typedef struct {
	quec_apptcpip_msg_id  msg_id;
	void                 *data_ptr;
}quec_apptcpip_msg;

#ifdef QUEC_TCIOT_SUPPORT
typedef struct{
	UINT32 			  atHandle;
	int 			  pdp_cid;
	quec_pdp_profile  profile_info;
}quec_apptcpip_tciot_tcregnet_req;

typedef struct{
	UINT32             atHandle; 
	int 			   result;
	UINT8              result_info[256]; 
}quec_apptcpip_tciot_tcregnet_cnf;

#endif

typedef struct{
	UINT32 			  atHandle;
	int 			  pdp_cid;
	quec_pdp_profile  profile_info;
}quec_apptcpip_pdp_profile_set_req;

typedef struct{
	UINT32             atHandle; 
	int 			  result;
}quec_apptcpip_pdp_profile_set_cnf;



typedef struct{
	UINT32            atHandle; 
	int 			  pdp_cid;
}quec_apptcpip_pdp_profile_get_req;

typedef struct{
	UINT32            atHandle;
	int 			  result;
	int               pdp_cid;
	quec_pdp_profile  profile_info;
}quec_apptcpip_pdp_profile_get_cnf;



typedef struct{
	UINT32            atHandle;
	int 			  pdp_cid;
}quec_apptcpip_pdp_active_req;

typedef struct{
	UINT32            atHandle;
	int 			  result;
}quec_apptcpip_pdp_active_cnf;


typedef struct{
	UINT32            atHandle; 
	int 			  pdp_cid;
    int               request_cmd;
}quec_apptcpip_pdp_deactive_req;

typedef struct{
	UINT32            atHandle; 
	int 			  result;
    int 			  pdp_cid;
    int               request_cmd;
}quec_apptcpip_pdp_deactive_cnf;


typedef struct{
	int 			  pdp_cid;
}quec_apptcpip_pdp_deactive_ind;



typedef struct{
	UINT32           atHandle;
	int              result;
	int              request_cmd;
    int              view_mode;
    int              pdp_cid;
}quec_apptcpip_pdp_info_get_req;

typedef struct{
	UINT32           atHandle; 
	int              result;
	int              request_cmd;
    int              view_mode;
    int              pdp_cid;
}quec_apptcpip_pdp_info_get_cnf;

typedef struct{
	UINT32           atHandle;
	int              pdp_cid;
}quec_apptcpip_dns_get_req;

typedef struct{
	UINT32           atHandle;
	int              result;
	int              pdp_cid;
	char             pri_dns_v4[128];
	char             sec_dns_v4[128];
	char             pri_dns_v6[128];
	char             sec_dns_v6[128];
}quec_apptcpip_dns_get_cnf;

typedef struct{
	UINT32           atHandle;
	int              pdp_cid;
	UINT8            pri_dns_valid;
	char             pri_dns[128];
	UINT8            sec_dns_valid;
	char             sec_dns[128];
}quec_apptcpip_dns_set_req;

typedef struct{
	UINT32           atHandle;
	int              result;
	int              pdp_cid;	
}quec_apptcpip_dns_set_cnf;

typedef struct{
	UINT32          atHandle;
	int             pdp_cid;
	char            host_name[256];
}quec_apptcpip_dns_get_addr_req;


typedef struct{
	UINT32          atHandle;
	int             result;
	uint16          ttl_val;
	uint8           record_cnt;
	quec_ip_addr    record[5];
}quec_apptcpip_dns_get_addr_cnf;

typedef struct{
	UINT32          atHandle;
	int   			pdp_cid;
	int     		connect_id;
#if defined(QUEC_SSL_SUPPORT)
    int             ssl_ctx_id;
#endif
	int     		service_type;
	char    		address[256];
	uint16  		remote_port;
	uint16  		local_port;
	uint8   		access_mode;
	int          	tcp_client_maxnum;
}quec_apptcpip_tcpip_open_req;

typedef struct{
	UINT32          atHandle;	
	int             result;
	int             connect_id;
	int             access_mode;
	int          	tcp_client_maxnum;
	int             server_type;
}quec_apptcpip_tcpip_open_cnf;

typedef struct{
	int            connect_id;
	int            event_mask;
	int            result;
}quec_apptcpip_tcpip_soc_event_ind;


typedef struct{
	UINT32        atHandle;
	int           connect_id;
	uint8         remote_addr[256];
	uint16        remote_port;
	int           write_len;
	uint8        *write_data;
	uint8         data_format_valid;
	uint8         data_format;
	int 		  heart_data;	//0:general data 1:heart data
#ifdef QUEC_TCPIP_SENDCRC_SUPPORT
    uint8         crc_flag;
    int           crc_num;
#endif
}quec_apptcpip_tcpip_send_req;

typedef struct{
	UINT32       atHandle;
	int          connect_id;	
	int          result;
#ifdef QUEC_TCP_QISEND_SENDINFO_FEATURE
    UINT32        freesize;
    uint8         status;
#endif
}quec_apptcpip_tcpip_send_cnf;

typedef struct{
	UINT32       atHandle;
	int          connect_id;
	uint8        rx_enble;
}quec_apptcpip_tcpip_raw_rx_flow_ctrl_ind;

typedef struct{
	int          connect_id;
}quec_apptcpip_tcpip_write_ind;

typedef struct{
	UINT32        atHandle;
	int           connect_id;
	int           read_len;
#ifdef QUEC_CIP_TCP_SUPPORT
	uint8 		  set_mode;
#endif
}quec_apptcpip_tcpip_read_req;

typedef struct{
	UINT32       atHandle;
	int          connect_id;	
	int          result;
	int          read_len;
	int          access_mode;
	int          service_type;
#ifdef QUEC_CIP_TCP_SUPPORT
	uint8 		 set_mode;
#endif	
}quec_apptcpip_tcpip_read_cnf;


typedef struct{
	UINT32       atHandle;	
	int          connect_id;
	int          service_type;
	int          access_mode;
	int 		 recv_len;		 //增加recv数据长度
}quec_apptcpip_tcpip_data_read_ind;

typedef struct{
	UINT32       atp_index;
	uint8        tx_enble;
}quec_apptcpip_tcpip_tx_flow_ctrl_ind;


typedef struct{
	UINT32            atHandle; 	
	int 			  connect_id;
	int               close_tm;
#ifdef QUEC_CIP_TCP_SUPPORT	
	bool			  set_connect;
#endif
}quec_apptcpip_tcpip_close_req;

typedef struct{
	UINT32            atHandle;		
	int 			  connect_id;
	int               result;
#ifdef QUEC_CIP_TCP_SUPPORT
	bool			  set_connect;
#endif
}quec_apptcpip_tcpip_close_cnf;

typedef struct{
	UINT32            atHandle; 
	int 			  connect_id;
	int               access_mode;
}quec_apptcpip_tcpip_close_ind;

#ifdef QUEC_TCPIP_DATAMODE_NETDOWN_URC_FIX
typedef struct{
	UINT32            atHandle; 
	int 			  connect_id;
	int               access_mode;
}quec_apptcpip_tcpip_netdown_ind;
#endif

typedef struct{
	UINT32           atHandle;
	int              listener_connect_id;
	int              result;
	int              incoming_connect_id;
	uint8            remote_addr[256];
	uint16           remote_port;
	int 			 access_mode;
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
	int 			qiaccept_process; //为了判断是否是qiaccept流程
#endif

}quec_apptcpip_tcpip_accept_ind;

typedef struct{
	UINT32            atHandle;		
	int               info_type;//1:qistate 2: write info 3: read info
#ifdef QUEC_CIP_TCP_SUPPORT
	uint8 			  set_mode;
#endif
 	union{
		struct{
			int   connect_id;
		}rw_info_req;

		struct{
			uint8     pdp_id_valid;
			int       pdp_cid;
			uint8     connect_id_valid;
			int       connect_id;
		}state_info_req;
	}u;
}quec_apptcpip_tcpip_state_info_req;

typedef struct{
	UINT32             atHandle;
	int                info_type;
#ifdef QUEC_CIP_TCP_SUPPORT
	uint8 			  set_mode;
	int   			  connect_id;
#endif	
	int                result;
	union{
		struct{
			int     total_tx_size;
			int     ack_tx_size;
			int     unack_tx_size;
		}write_info;

		struct{
			int    total_rx_size;
			int    read_rx_size;
			int    unread_rx_size;
		}read_info;

		struct{
			uint8     connect_cnt;
			UINT16    connect_id_mask;
		}state_info;
	}u;
}quec_apptcpip_tcpip_state_info_cnf;

typedef struct{
	UINT32             atHandle;
	int                connect_id;
	int                access_mode;
}quec_apptcpip_tcpip_change_mode_req;

typedef struct{
	UINT32             atHandle;
	int                connect_id;
	int                access_mode;
	int                result;
}quec_apptcpip_tcpip_change_mode_cnf;

typedef struct{
	int                atp_index;
	uint8              normal_escape;
}quec_apptcpip_tcpip_exit_data_mode_ind;

#ifdef QUEC_TCPIP_PUSH_AT_PARSER_32BYTE_MULTIPLE_0A
typedef struct{
	int 			   atp_index;
	int			       connect_id;
}quec_apptcpip_tcpip_enter_data_mode_ind;
#endif

//void apptcpip_printf(const char *fmt, ...);
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
typedef struct 
{
	UINT32      	atHandle;
	int32 			connect_id;				
	int32 			accept_mod;				//1:接受0：拒绝
	int32 			incomming_id;			//指定连接路序号
	bool 			accept_process;			//qiaccept指令标志
}quec_apptcpip_tcpip_qiaccept_req;			//qiaccept req参数

typedef struct 
{
	UINT32      	atHandle;
	int32           result;
}quec_apptcpip_tcpip_qiaccept_cnf;			//qiaccept cnf参数

typedef struct 
{
	UINT32           atHandle;
	int              listener_connect_id;
	int              result;
	int              incoming_connect_id;
	uint8            remote_addr[256];
	uint16           remote_port;
	int 			 access_mode;
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
	int 			qiaccept_process; //为了判断是否是qiaccept流程
#endif
}quec_apptcpip_tcpip_qiaccept_ind;			//qiaccept参数与accept ind结构体保持一致

#endif

#endif

#endif
