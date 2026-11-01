/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUECTEL_NTP_APP_H
#define  QUECTEL_NTP_APP_H

#include "quectel_apptcpip_util.h"
#include "quec_apptcpip_msg.h"
#if defined(QUEC_NTP_SUPPORT)

#define QUEC_NTP_RETRY_TIMES_MIN 			1
#define QUEC_NTP_RETRY_TIMES_MAX 			10
#define QUEC_NTP_RETRY_INTERVAL_MIN			5
#define QUEC_NTP_RETRY_INTERVAL_MAX 		60

#define QUEC_NTP_TIMERCON         				125	//sec
#define QUEC_NTP_TIMERCONSTEP         			15//sec

#define   QUECTEL_NTP_DEFAULT_HOST_PORT             123
#define   QUEC_EFS_QNTPCFG_RETRY_CNT		 	    "quectel_efs_qntpcfg_retry_cnt_value.cfg"

#define   QUECTEL_NTP_MAX_RETRY_TIMES      		    3
#define   QUECTEL_NTP_MAX_RETRY_INTERVAL   	        15

#define QUEC_NTP_PDP_ID_MIN					1
#define QUEC_NTP_PDP_ID_MAX					15
#define	QUEC_NTP_PDP_ID_DEFAULT				1

#define QUEC_NTP_PORT_MIN					0
#define QUEC_NTP_PORT_MAX					65535
#define	QUEC_NTP_PORT_DEFAULT				0

#define QUEC_NTP_AUTOSETTIME_MODE_MIN		0
#define QUEC_NTP_AUTOSETTIME_MODE_MAX		1
#define QUEC_NTP_AUTOSETTIME_MODE_DEFAULT	1


typedef enum
{
	NTP_CLIENT_IDLE = 0,
	NTP_CLIENT_PDP_ACTIVING,
	NTP_CLIENT_DNSGIP,
	NTP_CLIENT_SENDING_REQ,
	NTP_CLIENT_WAITING_RSP,
	NTP_CLIENT_SYNC_FINISHING,
	NTP_CLIENT_SYNC_FINISHED = NTP_CLIENT_IDLE
}quectel_ntp_client_status;



typedef struct
{
	UINT32                         atHandle;
	UINT32                         pdp_cid;
	INT16                          sock_fd;
	UINT16                         quec_ip_vsn;
	UINT8                          retry_count;
	UINT32                         orig_time;
	UINT32                         sync_time;
	uint32                         retry_timer_id;
	quectel_ntp_client_status      ntp_client_status;
	BOOL                           auto_sync_local_time;
	UINT16                         ntp_server_port;
	quec_ip_addr                   ntp_server_ipaddr;
	char                           ntp_server_hostname[255];
	apptcpip_host_address_type     ntp_server_addr_type;
	char                           local_addr[255];
	quec_ip_addr                   local_ip;
	UINT16                         local_port;
	UINT32                         sync_result;
	quec_sem_t                     pdp_act_sem;
}quectel_ntp_client_struct;

typedef struct
{
    UINT32                          atHandle;
	UINT32                          pdp_cid;
	UINT32                          auto_sync_local_time;
	apptcpip_host_address_type      address_type;
	quec_ip_addr                    ip_address;
	UINT8                           host_name[255];
	UINT32                          host_port;
	UINT32                          local_port;
}quectel_ntp_sync_param;

typedef struct{
	int            event_mask;
	int            result;
}quec_ntp_soc_event_ind;


typedef  struct
{
	UINT32                          atHandle;
	UINT32                          result;
	UINT32                          pdp_cid;
	UINT32                          sync_time;
	Q_BOOL                          auto_sync_local_time;
}quectel_ntp_sync_result_ind_params;

typedef  struct
{
	UINT32                          atHandle;
	UINT32                          result;
	UINT16                          ntp_server_port; 
	quec_ip_addr                    ntp_server_ipaddr;
	UINT8                           ntp_server_hostname[255];
	apptcpip_host_address_type      ntp_server_addr_type;
}quectel_ntp_read_server_info_rsp_params;

typedef struct{
	UINT32		   atHandle;
}quec_apptcpip_ntp_query_cnf;

void  quectel_ntp_client_init
(
void
);

Q_BOOL  quectel_ntp_client_is_running
(
void
);

UINT32  quectel_ntp_client_sync_time
(
quectel_ntp_sync_param  *sync_params
);

uint32  quectel_ntp_client_read_server_info
(
quec_apptcpip_ntp_query_cnf  *cnf_msg
);


#endif/*QUECTEL_NTP_APP_H*/
#endif
