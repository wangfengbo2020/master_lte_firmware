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
04/11/2020 		  Luffy      modify qiaccept logic same as ASR code frame such as /proc/cnf/ind	 delete old struct 
=================================================================*/
#ifndef QUEC_TCPIP_APP_H
#define QUEC_TCPIP_APP_H

#include "quec_apptcpip_msg.h"

#ifdef QUEC_APPTCPIP_SUPPORT

#define QUEC_TCPIP_ERR_START                 550
#define QUEC_MAX_TCPIP_SERVICE_NUM    12
#ifdef __QUEC_OEM_VER_OA__
#define QUEC_MAX_TCPIP_PKT_LEN        1024
#else
#define QUEC_MAX_TCPIP_PKT_LEN        1500
#endif


#define QUEC_MAX_TCPIP_RX_DATA_CACHE_LEN   15*1024 /* 10*1024 ,mod 20200110*/
#define QUEC_TCPIP_RX_LOW_DATA_CACHE_LEN   2*1024

#define QUEC_MAX_TCPIP_TX_DATA_CACHE_LEN   7*1024
#define QUEC_MIN_TCPIP_TX_DATA_CACHE_LEN   2*1024

//限制不能无限增大的原因是因为我们当我们上层拉流控然后发送数据，一次性向协议栈发送大量数据会导致协议栈进入write wouldblock状态
#define QUEC_TCP_DATA_MODE_MAX_CACHE_LEN   16*1024   //透传模式下最大缓存16K 超过16K数据将被丢失掉

typedef enum{
	QUEC_TCPIP_OK = 0,
	QUEC_TCPIP_ERR_FAILURE = QUEC_TCPIP_ERR_START,
    QUEC_TCPIP_ERR_WODBLOCK,
    QUEC_TCPIP_ERR_INVALID_PARAM,
    QUEC_TCPIP_ERR_OUT_OF_MEMORY,
    QUEC_TCPIP_ERR_NEW_SOCKET_FAILURE,
    QUEC_TCPIP_ERR_NOT_SUPPORT,
    QUEC_TCPIP_ERR_SOC_BIND_FAILURE,
    QUEC_TCPIP_ERR_SOC_LISTEN_FAILURE,
    QUEC_TCPIP_ERR_SOC_WRITE_FAILURE,
    QUEC_TCPIP_ERR_SOC_READ_FAILURE,
    QUEC_TCPIP_ERR_SOC_ACCEPT_FAILURE,
    QUEC_TCPIP_ERR_OPEN_PDP_FAILURE,
    QUEC_TCPIP_ERR_CLOSE_PDP_FAILURE,
    QUEC_TCPIP_ERR_SOC_INDEX_USED,
    QUEC_TCPIP_ERR_DNS_BUSY,
    QUEC_TCPIP_ERR_DNS_FAILURE,
    QUEC_TCPIP_ERR_SOC_CONNECT_FAILURE,
    QUEC_TCPIP_ERR_SOC_CLOSED,
    QUEC_TCPIP_ERR_OPT_BUSY,
    QUEC_TCPIP_ERR_OPT_TIMEOUT,
    QUEC_TCPIP_ERR_NET_DOWN,
    QUEC_TCPIP_ERR_CANCEL_SEND,
    QUEC_TCPIP_ERR_NOT_ALLOWED,
    QUEC_TCPIP_ERR_PORT_BUSY,
    QUEC_TCPIP_ERR_PDP_ACTIVED,
#ifdef QUEC_SSL_SUPPORT
	QUEC_TCPIP_ERR_SSL_INDEC_USED,
#endif
    QUEC_TCPIP_ERR_SSL_DECRYPT_FAILURE,
    QUEC_TCPIP_ERR_SSL_ENCRYPT_FAILURE,
    QUEC_TCPIP_ERR_SSL_DATA_VERIFY_FAILURE,
    QUEC_TCPIP_ERR_SSL_RESET,

    QUEC_TCPIP_ERR_MISSING_PARAM,
	QUEC_TCPIP_LAST_ERR_CODE
}quec_tcpip_error_code;

typedef enum{
	QUEC_TCP_CLIENT_SERVICE = 0,
    QUEC_TCP_LISTENER_SERVICE,
    QUEC_TCP_INCOME_SERVICE,
    QUEC_UDP_CLIENT_SERVICE,
    QUEC_UDP_LISTENER_SERVICE,
    QUEC_UDP_CLIENT_LISTENER_SERVICE,
    QUEC_UDP_INCOME_SERVICE,
    QUEC_TCP_SSL_CLIENT_SERVICE,
    QUEC_MAX_TCPIP_SERVICE
}quec_tcpip_service_type;

typedef enum{
	QUEC_TCPIP_SERVICE_STATE_IDLE = 0,
	QUEC_TCPIP_SERVICE_STATE_INIT = 1,
	QUEC_TCPIP_SERVICE_STATE_LISTENING = 2,
	QUEC_TCPIP_SERVICE_STATE_CONNECTING,
	QUEC_TCPIP_SERVICE_STATE_CONNECT,
	QUEC_TCPIP_SERVICE_STATE_CLOSING,
#ifdef QUEC_SSL_SUPPORT
	QUEC_TCPIP_SERVICE_SSL_HANDSHARK,
#endif
	QUEC_TCPIP_SERVICE_STATE_CLOSED = QUEC_TCPIP_SERVICE_STATE_IDLE,
}quec_tcpip_service_state;

typedef enum{
	QUEC_TCPIP_TEXT_DATA = 0,
	QUEC_TCPIP_HEX_DATA = 1,
}quec_tcpip_data_format_type;


typedef enum{
	QUEC_TCPIP_SERVICE_USED_INFO =  1, //at+qistate
	QUEC_TCPIP_SERVICE_WRITE_INFO = 2, //at+qisend=x,0
	QUEC_TCPIP_SERVICE_READ_INFO = 3, //at+qird=x,0
#ifdef QUEC_SSL_SUPPORT
    QUEC_TCPIP_SSL_SERVICE_INFO = 4, //at+qsslstate=x
    QUEC_TCPIP_SSL_SERVICE_READ_INFO = 5, //at+qsslrecv=x,0
#endif
}quec_tcpip_state_info_type;

typedef enum{
    QUEC_TCP_CONNECT_PASSIVE_CLOSE_MODE = 1,
}quec_tcpip_socketopt_type;

typedef enum{
    QUEC_TCP_NO_CONNECT_KEEPALIVE_MODE = 1,
#ifdef QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE
	QUEC_TCP_EDIT_SENDMODE_TIMEOUT = 2,/*编辑模式处理发送超时*/
#endif	
}quec_tcpip_serveropt_type;


typedef enum{
	QUEC_TCPIP_CUST_MIN = 0,
	QUEC_TCPIP_CUST_STD = QUEC_TCPIP_CUST_MIN,
	QUEC_TCPIP_CUST_MAX,
}quec_tcpip_customer_id;

typedef enum{
	QUEC_TCPIP_PASSIVE_CLOSED_DEAFULT = 0,
	QUEC_TCPIP_PASSIVE_CLOSED_ACTIVE,/*Actively close the socket connection*/
	QUEC_TCPIP_PASSIVE_CLOSED_URC, /*If there is data in the cache, it will also report a prompt*/
}quec_tcpip_passive_close_qicfg;

typedef struct{
	UINT32	  size;
	UINT32	  used;
	UINT8	 *orig_data_ptr;
	uint8	 *data_ptr;
}quec_tcpip_data;

typedef struct{
	quec_ip_addr	 ip_addr;
	uint16			 ip_port;
	quec_tcpip_data  *data;
}quec_udp_pkt;

typedef struct{
	OSATimerRef   transparent_intervl_timer;
	UINT32		  total_rx_size;
	UINT32		  read_rx_size;
	uint8		  sio_tx_high; //socket read(tcpip rx)--->sio tx

	UINT32		  total_tx_size;
	UINT32		  ack_tx_size;
	UINT32		  write_tx_size;
	uint8		  sio_rx_high; // sio rx ---->qisend(tcpip tx)
	union{
		struct {
			quec_tcpip_data 	*current_rx_data_ptr;
			quec_tcpip_data 	*current_tx_data_ptr;
			linklist_handler_t	rx_q;
			linklist_handler_t	tx_q;
		}tcp_session;

		struct{
			quec_udp_pkt		*current_rx_data_ptr;
			quec_udp_pkt		*current_tx_data_ptr;
			linklist_handler_t	 rx_q;
			linklist_handler_t	 tx_q;
		}udp_session;
	}u;
}quec_tcpip_transfer_session;

typedef struct{
	UINT32		max_income_num;
	UINT32		income_sess_mask;
}quec_tcpip_listen_service;

#define QUEC_TCPIP_SERVER_SOCKET_ADDR_LEN_MAX   46 /*Optimize resource usage*/

typedef struct{
	UINT32      	atHandle;
	int         	pdp_cid;
	int         	connect_id;
#if defined(QUEC_SSL_SUPPORT)
    int             ssl_ctx_id;
    UINT32          ssl_session_handle;
    bool            ssl_abort;
#ifdef QUECTEL_DTLS_FEATURE 
	int 			is_dtls;
	uint32			dtls_conn_timer;
	uint32 			dtls_conn_time_out;
#endif
#endif	
	int             server_id;
	int   			quec_sockfd;
	int         	quec_ip_vsn;
    int         	service_type;
	int         	access_mode;
	int         	service_state;
	char        	remote_addr[QUEC_TCPIP_SERVER_SOCKET_ADDR_LEN_MAX];/*Cache analyzed server IP address information*/
	char            remote_host[256];/*Cache domain name IP information for SNI*/
	char        	local_addr[QUEC_TCPIP_SERVER_SOCKET_ADDR_LEN_MAX];/*Cache analyzed client IP address information*/
	quec_ip_addr 	remote_ip;
	quec_ip_addr    local_ip;
	uint16      	remote_port;
	uint16      	local_port;
	uint8       	close_called;
    bool            recv_urc_report;
	int 			open_access_mode;
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
		bool			qiaccept_process;
		int 			incomming_id;
		int 			tcp_accept_flag;			//设置已经执行qicfg="tcp/accept"指令；
		int 			accept_mode;				//qiaccept 甚至是否连接，1连接，0关闭连接；
#endif

	union{
		quec_tcpip_transfer_session    transfer_sess;
		quec_tcpip_listen_service      listen_service;
	}serivce;
	quec_sem_t		pdp_act_sem;
    bool            recv_ri;/*Receive data and pull Ri pin flag*/ 
    bool            close_urc_report;/*socket close event,report urc flag*/ 
    bool            send_mode;//进入QISEND可编辑模式收数据 
    int             no_report_buff_data_len;//QISEND进入可编辑模式下，且配置recvind，那么测试记录这段时间内没有上报的数据长度
#ifdef QUEC_TCP_NETCONN_EVT_SENDACKED_FEATURE
    int             tcp_sendmode_len;/*SEND OK 上报模式,send 长度计数*/
#endif
}quec_tcpip_service_ctx;

#ifdef QUECTEL_QISEND_AUTO_BYTIME
#define QUEC_LPC_QICFG_LEN_MAX   256
typedef struct
{
    uint32          next_send_time_handle;
    uint32          qisend_auto_period;
    char			qisend_auto_msg[QUEC_LPC_QICFG_LEN_MAX];
    uint16			qisend_auto_msg_len;
    char            qirecv_ignore_msg[QUEC_LPC_QICFG_LEN_MAX];
    uint16          qirecv_ignore_msg_len;
	bool            qisend_auto_enable;
	bool            qirecv_ignore_enable;
	uint8           show_auto_format;
	uint8   		try_times;
	uint8           show_ignore_format;
    uint8           first_send;
}quec_tcpip_auto_send_ctx;

typedef struct
{
    uint32          client_id;
	uint32    		qisend_auto_period;
	char    		qisend_auto_msg[QUEC_LPC_QICFG_LEN_MAX];
	uint32   		qisend_auto_msg_len;
    uint8           show_format;/*0:hex-string; 1:hex; 2:string*/
	uint8   		try_times;
    uint8           first_send;
}qeuc_tcpip_auto_send_msg_opt;

typedef struct
{
    uint32          client_id;
	char    		qirecv_ignore_msg[QUEC_LPC_QICFG_LEN_MAX];
	uint32   		qirecv_ignore_msg_len;
    uint8           show_format;
}qeuc_tcpip_ignore_recv_msg_opt;
#ifdef QUEC_TCPIP_WAKEUP_DATA_FEATURE
typedef struct
{
    bool            wakeup_enable;
    uint8           show_format;
    char			wakeup_msg[QUEC_LPC_QICFG_LEN_MAX];
    uint16			wakeup_msg_len;
    uint32          client_id;
}quec_tcpip_wakeup_ctx;
#endif
#endif

typedef struct
{
	uint32    		keepalive_enable;
	uint32   		idle_time;
	uint32   		interval_time;
	uint32   		max_probe_cnt;
}qeuc_tcpip_keepalive_opt;

#ifdef QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE
typedef  struct
{
	bool			edit_timer_flag;/*定时器标志*/
	bool			enable_edit_timeout;/*使能编辑超时功能定时器*/
    uint32          edit_sendmode_timeout;/*进入编辑模式超时时间,不包含qisend超时*/ 
	OSATimerRef 	edit_timer;/*定时器句柄*/ 
	quec_mutex_t	edit_mutex;/*互斥锁*/ 
	int32           athandle;
#if defined(QUECTEL_QISEND_TIMEOUT)			
	int32           qisend_timeout;
#endif

}qeuc_tcpip_edit_timeout_opt;
#endif

#ifdef QUECTEL_CTWing_SUPPORT
#define QUEC_CTWING_PARM_LEN 64
typedef struct
{
	int				connect_id;
	bool			ctwing_enable; //1:enable  0:disable
	char 			productid[QUEC_CTWING_PARM_LEN];
	char			deviceid[QUEC_CTWING_PARM_LEN];
	char 			password[QUEC_CTWING_PARM_LEN];
	INT32 			athandle;
	uint32    		qisend_auto_period;
	int				ctwing_used;	//0:unused	1:used
}quec_tcpip_ctwing_opt;
#endif

#ifdef QUEC_TCPIP_QICLOSE_ASYNC_FEATURE
typedef  struct
{
    uint32          close_mode;/*qiclose mode, 0:sync, 1:async*/ 
	/*New function parameter added*/

}qeuc_tcpip_extself_global_opt;/*Pay attention to format alignment, add the number of type conversion bytes*/
#endif

#ifdef QUEC_TCPIP_SWITCH_MULTIPLE_MODE_FEATURE
typedef enum{
	QUEC_INIT_MODE = 0,
	QUEC_TRANSPARENT_ASSESS_MODE = 1,	
	QUEC_CHANGE_DATA_MODE = 2,
}quec_tcpip_data_mode;
#endif

extern void quec_tcpip_free_data(quec_tcpip_data *tcpip_data);
extern quec_tcpip_data *quec_tcpip_new_data_2(uint8 *data_ptr,int len);
extern quec_tcpip_data *quec_tcpip_new_data(int len);
extern int  quec_apptcpip_requst(int msg_id, void* msg_data_ptr);

void quec_tcpip_init(void);

void quec_tcpip_request_handler(quec_apptcpip_msg *api_msg);

void quec_tcpip_cnf_handler(quec_apptcpip_msg *api_msg);

int quec_tcpip_covert_err_to_at_errno(int apptcpip_err);

void quec_tcpip_set_last_errno(int errno);

int  quec_tcpip_get_last_errno(void);

int  quec_tcpip_get_conn_state(int connect_id);

int  quec_tcpip_get_conn_type(int connect_id);

int  quec_tcpip_get_transparent_pkt_size(void);

void  quec_tcpip_set_transparent_pkt_size(int pkt_size);

int  quec_tcpip_get_transparent_wait_tm(void);

void  quec_tcpip_set_transparent_wait_tm(int wait_tm);

void  quec_tcpip_get_dataformat(int *writefmt, int *readfmt);

void  quec_tcpip_set_dataformat(int writefmt, int readfmt);

int  quec_tcpip_get_udp_send_mode(void);

void  quec_tcpip_set_udp_send_mode(int mode);

int  quec_tcpip_get_udp_read_mode(void);

void  quec_tcpip_set_udp_read_mode(int mode);

int quec_tcpip_open(quec_apptcpip_tcpip_open_req *req_msg);

int quec_tcpip_read(quec_apptcpip_tcpip_read_req *req_msg);

int quec_tcpip_send(quec_apptcpip_tcpip_send_req  *req_msg);

int quec_tcpip_state(quec_apptcpip_tcpip_state_info_req *req_msg);

int quec_tcpip_close(quec_apptcpip_tcpip_close_req        *req_msg);

int quec_tcpip_change_mode(quec_apptcpip_tcpip_change_mode_req *req_msg);

uint16  quec_tcpip_generate_local_port(void);

uint16  quec_tcpip_generate_local_port_ex(void);

int quec_tcpip_is_valid_ip46_address(char *ip_string);

int quec_tcpip_get_keep_alive(qeuc_tcpip_keepalive_opt	 *opt_val);

int quec_tcpip_set_keep_alive(qeuc_tcpip_keepalive_opt    	   *opt_val);
#ifdef QUEC_TCP_EDIT_SENDMODE_TIMEOUT_FEATURE
int  quec_tcpip_get_edit_timeout(qeuc_tcpip_edit_timeout_opt *opt_val);
int  quec_tcpip_set_edit_timeout(qeuc_tcpip_edit_timeout_opt *opt_val);
#endif
void quec_tcpip_set_tcpclient_num(int num);

int quec_tcpip_get_tcpclient_num(void);

void quec_tcpip_set_conn_passive_close_mode(int value);

int quec_tcpip_get_conn_passive_close_mode(void);

void quec_tcpip_set_viewmode(int value);

int quec_tcpip_get_viewmode(void);

int  quec_tcpip_get_tcp_retranscfg(void);

void  quec_tcpip_set_tcp_retranscfg(int max_backoffs ,int rto);
int quec_tcpip_set_enter_sendmode(bool flag);
int quec_tcpip_get_enter_sendmode(void);

/***********************************
获取recvind_mode的值；
***********************************/
int quec_tcpip_get_recvind(void);
/**********************************
设置recvind_mode的值：
**********************************/
void quec_tcpip_set_recvind(int recvind_mode);
/*********************************
设置模块当前是否是透传模式的值
*********************************/
void quec_tcpip_set_connector_rawmode_flag(int connect_id, int open_access_mode);
/*********************************
获取模块当前是否存在透传模式连接
*********************************/
int  quec_tcpip_get_connector_rawmode_flag(void);
/*********************************
获取当前模块服务器是否存在透传模式连接
*********************************/
int quec_tcpip_get_server_rawmode_flag(void);
#ifdef QUEC_TCPIP_QIACCEPT_SUPPORT
/**********************************************
设置tcp/accept 状态
0：手动连接，1：主动连接
added by luffy @2019/11/26
**********************************************/
void quec_tcpip_set_tcp_accept(int tcp_accept);
/**********************************************
获取tcp/accept 状态
0：手动连接，1：主动连接
added by luffy @2019/11/26
**********************************************/
int  quec_tcpip_get_tcp_accept(void);

#ifdef QUEC_TCP_QISEND_SENDINFO_FEATURE
/**********************************************
使能或禁止以URC 形式显示执行AT+QISEND 返回信息
0：禁止 1：使能
added by carson.liu @2021/04/13
**********************************************/
void quec_tcpip_set_tcp_sendinfo(int send_info);
int  quec_tcpip_get_tcp_sendinfo(void);
#endif

/*********************************************
qiaccept处理函数
added by luffy @2019/11/26
**********************************************/
int  quec_tcpip_qiaccept(quec_apptcpip_tcpip_qiaccept_req *qiaccept_req);
#endif
#ifdef QUEC_TCP_NETCONN_EVT_SENDACKED_FEATURE
uint32 quec_tcpip_get_tcp_send_mode(int client_id);
void quec_tcpip_set_tcp_send_mode(int tcp_send_mode);
#endif
QuecOSStatus quec_tcpip_set_dcd_level(TelAtParserID atp_index, quec_pin_level_value_e level);
#ifdef QUECTEL_QISEND_AUTO_BYTIME
int  quec_tcpip_set_auto_send_cfg(qeuc_tcpip_auto_send_msg_opt *opt_val);
int  quec_tcpip_get_auto_send_cfg(int client_id, qeuc_tcpip_auto_send_msg_opt          *opt_val);
int  quec_tcpip_set_recv_msg_cfg(qeuc_tcpip_ignore_recv_msg_opt    		*opt_val);
int  quec_tcpip_get_recv_msg_cfg(int client_id, qeuc_tcpip_ignore_recv_msg_opt          *opt_val);
#ifdef QUEC_TCPIP_WAKEUP_DATA_FEATURE 
int  quec_tcpip_get_wakeup_msg_cfg(int client_id, quec_tcpip_wakeup_ctx   *opt_val);
int  quec_tcpip_set_wakeup_msg_cfg(quec_tcpip_wakeup_ctx   *opt_val);
#endif /*QUEC_TCPIP_WAKEUP_DATA_FEATURE*/
#endif
#endif

#ifdef QUEC_CIP_TCP_SUPPORT
#define QUEC_TCPIP_CONNECTION_NUMBER_MIN 		0
#define QUEC_TCPIP_CONNECTION_NUMBER_MAX 		7
#define QUEC_TCPIP_CONNECTION_NUMBER_DEFAULT 	0

typedef enum
{
	QUEC_MULTI_DISABLE = 0,
	QUEC_MULTI_ENABLE = 1,
}quec_tcpip_cipmux_state;

void quec_tcpip_set_multi_value(uint8 value);
uint8 quec_tcpip_get_multi_value(void);
void quec_tcpip_set_rxget_mode(uint8 mode);
uint8 quec_tcpip_get_rxget_mode(void);
bool quec_tcpip_connect_state(void);

#endif

#endif
