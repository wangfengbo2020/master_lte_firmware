/**
 ******************************************************************************
 * @file    quec_net.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    26-Sep-2018
 * @brief   This file contains the common definitions, macros and functions to
 *          be shared throughout the project.
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 QUECTEL Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */
/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
04/15/2020		  Harold	 mod qicsgp user name and password support up to 128 bytes each
=================================================================*/

#ifndef QUEC_NET_H
#define QUEC_NET_H

#include "sys_arch.h"

#include "quec_common.h"
#include "ci_api_types.h"
#include "teldef.h"
#include "netif_td.h"
#include "ci_ps.h"
#include "connect_management.h"
#include "quec_rtos.h"
#include "ci_sim.h"



#pragma pack(push)
#pragma pack(1)

#ifdef QUEC_APPTCPIP_SUPPORT
#ifdef QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808
#define QUEC_USERPWD_PROFILE_SIZE      (129)
#endif

typedef enum {
	QUEC_PDP_STATE_NONE = 0,
	QUEC_PDP_STATE_PDP_ACTIVED,
	QUEC_PDP_STATE_PDP_DEACTIVED = QUEC_PDP_STATE_NONE
}quec_pdp_state;

typedef enum{
	QUEC_PDP_INVALID = 0,
	QUEC_PDP_IPV4 = 1,
	QUEC_PDP_IPV6 = 2,
	QUEC_PDP_IPV4V6 = 3
}quec_pdp_type;

typedef struct{
	uint32	ip_addr;
}quec_ipv4_addr;
	
typedef struct{
	uint32	 ip_addr[4];
}quec_ipv6_addr;
	
typedef struct{
	int8 ip_vsn;
	union{
		quec_ipv4_addr	  ipv4_addr;
		quec_ipv6_addr	  ipv6_addr;
	}addr;
#define  quec_ipv4_addr   addr.ipv4_addr
#define  quec_ipv6_addr   addr.ipv6_addr
}quec_ip_addr;

	
typedef struct{
	int    pdp_type;
#ifdef QUEC_PATCH_1802S_AUTHREQ_SIZE128_12808
	char   apn[QUEC_USERPWD_PROFILE_SIZE];
	int    auth_type;
	char   user_name[QUEC_USERPWD_PROFILE_SIZE];
	char   password[QUEC_USERPWD_PROFILE_SIZE];
#else
	char   apn[128];
	int    auth_type;
	char   user_name[128];
	char   password[128];
#endif

}quec_pdp_profile;

typedef struct{
 #ifdef QUEC_PDP_IPV4V6_SUPPORT
    int8 pdp_ip_type;
 #endif
	quec_ip_addr   ip_addr_v4;
	quec_ip_addr   ip_addr_v6;
	quec_ip_addr   pri_dns_v4;//pri dns
	quec_ip_addr   pri_dns_v6;
	quec_ip_addr   sec_dns_v4; //sec dns
	quec_ip_addr   sec_dns_v6;
}quec_pdp_info;


typedef struct{
	UINT32                atHandle;
	int 				  pdp_id;
	quec_pdp_profile	  pdp_profile;
	int 				  pdp_state;
	quec_pdp_info         pdp_info;
}quec_pdp_ctx;

#endif

#define PDP_CTX_MAX_ID	6

typedef enum
{
	PDP_OP_ACT,
	PDP_OP_DACT
} pdp_act_op_e;

typedef enum
{
	PDP_OPT_ONE,
	PDP_OPT_ALL
} pdp_act_opt_e;

typedef struct
{
	uint32		 context_id;
	QuecOSStatus result;
	uint32		 ipaddr_u32;
	char		 ipaddr_str[20];
} pdp_act_result_t;

typedef struct
{
	int 			pdp_cid;
	pdp_act_op_e	op;
	int				status;
} pdp_act_status_t;

typedef enum
{
	NETIF_OP_BIND,
	NETIF_OP_UNBIND
} netif_bind_op_e;

typedef struct
{
	int 			pdp_cid;
	netif_bind_op_e	op;
	int				status;
} netif_bind_status_t;

typedef struct
{
	TelAtParserID 		atpIndex;
	
	quec_task_t			pdpActServiceTask;
	quec_mutex_t		pdpActServiceMutex;
	bool 				isPdpActServiceStarted;
	uint32 				pdpActRetryTimes;
	pdp_act_status_t	pdpActStatus;
	
	quec_task_t			netifBindServiceTask;
	quec_mutex_t		netifBindServiceMutex;
	bool 				isNetifBindServiceStarted;
	uint32 				netifBindRetryTimes;
	uint32 				netifBindPeriod_ms;
	netif_bind_status_t netifBindStatus;
	uint32 				pdpActPeriod_s;
} net_service_t;



#define QUEC_INVALID_SET_CID  0

typedef enum 
{
    QUEC_NETIF_DISCONNECT=0,
    QUEC_NETIF_CONNECT,
    QUEC_NETIF_REMOVE=0xFF,
}quec_netif_status_e;
    

typedef enum 
{
    QUEC_LWIP_IP_TYPE_IPNONE =0,
    QUEC_LWIP_IP_TYPE_IPV4 =IP_TYPE_IPV4, 
    QUEC_LWIP_IP_TYPE_IPV6 =IP_TYPE_IPV6,
    QUEC_LWIP_IP_TYPE_IPV4V6 =0x3
}quec_lwip_ip_type_e;

typedef enum
{
    QUEC_PDP_TYPE_SECOND  =0,
    QUEC_PDP_TYPE_PRIMARY = 1
}quec_pdp_type_e;


    

typedef enum
{
    QUEC_CM_DISCONNECTED =0,
    QUEC_CM_CONNECTED,
    QUEC_CM_CONNECTING,
    QUEC_CM_DISCONNECTING,
}quec_cm_connect_status_e;


typedef enum 
{
    QUEC_NETCARD_BIND_NONE=0,        //netcard no bind to cid
    QUEC_NETCARD_BIND_PDP_ONCE,      //netcard bind only once
    QUEC_NETCARD_BIND_PDP_ACTIVITY,  //netcard bind one activity pdp context
    QUEC_NETCARD_BIND_PDP_AUTO,      //netcard can activate and bind one pdp context 
    QUEC_NET_CARD_BIND_MAX
}quec_netcard_attribute_e;

typedef enum 
{
    QUEC_NETDEVCTL_SET_URC_NONE = 0,     //at set no urc 
    QUEC_NETDEVCTL_SET_URC_EXIST,       //at set urc report   
}quec_netcard_set_urc_e;


typedef enum 
{
    QUEC_NETDEVCTL_URC_TYPE_NONE =0,
    QUEC_NETDEVCTL_URC_TYPE_CLOSE,     //netcard close urc
    QUEC_NETDEVCTL_URC_TYPE_OPEN,    //netcard open  urc   
}quec_netcard_urc_type_e;
	
typedef enum 
{
    QUEC_LWIP_LOG_LEVEL_NONE = 0,
    QUEC_LWIP_LOG_LEVEL_ERROR , 
    QUEC_LWIP_LOG_LEVEL_API ,
    QUEC_LWIP_LOG_LEVEL_ERROR_API ,
    QUEC_LWIP_LOG_LEVEL_INFO ,
    QUEC_LWIP_LOG_LEVEL_ERROR_INFO ,
    QUEC_LWIP_LOG_LEVEL_API_INFO ,
    QUEC_LWIP_LOG_LEVEL_ERROR_API_INFO ,
    QUEC_LWIP_LOG_LEVEL_MAX,
}quec_lwip_loglevel_e;

typedef struct
{
    quec_netcard_attribute_e attri;
    quec_netcard_set_urc_e urc;
    uint8  cid;
	uint32  at_handle;
}quec_netcard_attribute_s;

// all netcard message type
typedef enum 
{
    QUEC_NETCARD_TYPE_NONE = CI_PS_PRIM_LAST_COMMON_PRIM+1,

	QUEC_NETCARD_PDP_ACTIVITY, 
	QUEC_NETCARD_TIMER_CHECK,//214
      
    QUEC_NETCARD_OPEN ,   
    QUEC_NETCARD_CLOSE,
    QUEC_NETCARD_AUTO,
    QUEC_NETCARD_TRY_BIND,

    QUEC_NETCARD_NETWORK_STATE_IND,  //from psInd function 
    
    QUEC_NETCARD_TYPE_MAX
    
}quec_netcard_msg_type_e;


typedef enum 
{
    QUEC_NETDEVCTL_MSG_NONE =0,
    QUEC_NETDEVCTL_MSG_FROM_AT,   //from at/usb external port  need at_resp
    QUEC_NETDEVCTL_MSG_FROM_IND,   //from with protocol stack interaction not need at_resp
    QUEC_NETDEVCTL_MSG_FROM_SELF,   //from software control           
    QUEC_NETDEVCTL_MSG_MAX
}quec_netdevctl_msg_from_e;


typedef struct
{
    quec_netdevctl_msg_from_e  msg_from;
    quec_netcard_msg_type_e  msg_type;
    uint8 data_len;
    uint8 *p_data;  //malloc type need release
}quec_netcard_msg_s;

typedef struct
{
    char *buf;
    uint8 bit_pos;
}quec_pdp_flag_attribute_s;

typedef struct
{
    quec_netif_status_e netif_config;
    uint8 actual_cid;
    uint8 pdp_flag_bit_pos;
    uint8 is_netdev;
    uint8 retry_times;
}quec_lwip_netif_config_s;


#define QUEC_PDP_TIMER_NUMBER  4
#define QUEC_DATA_NO_ACK_CONTROL_POSITION 23

#define QUEC_PDP_TIMER_TIME_MIN 0

#define QUEC_PDP_TIMER_TIME_MAX 65535

#define QUEC_PDP_TIMER_RETRY_MIN 0

#define QUEC_PDP_TIMER_RETRY_MAX 255

typedef enum
{
    T3380_TIME_PERIOD_POSITION =62,			//Chaim 20200526, 1601 use different with1802s serial product.t3380 use position 62
    T3380_TIME_RETRY_COUNT_POSITION,
    T3390_TIME_PERIOD_POSITION,
    T3390_TIME_RETRY_COUNT_POSITION,

    T3482_TIME_PERIOD_POSITION,
    T3482_TIME_RETRY_COUNT_POSITION,

    T3492_TIME_PERIOD_POSITION,
    T3492_TIME_RETRY_COUNT_POSITION,
    //PDP_TIMER_RLC_ACK_POSITION =23,
}quec_pdp_timer_position_e;

typedef enum
{
    PDP_TIMER_T3380 =0,
    PDP_TIMER_T3390,
    PDP_TIMER_T3482,
    PDP_TIMER_T3492,
   // PDP_TIMER_RLC_ACK,   //long time no ack reselect
    PDP_TIMER_TMAX
}quec_pdp_timer_name_e;


typedef struct
{
    uint8  period_position;
    uint16 period_time;
}quec_pdp_timer_period_s;

typedef struct
{
    uint8  retry_position;
    uint16 retry_count;
}quec_pdp_timer_rerycount_s;

typedef struct
{
    quec_pdp_timer_name_e  timer_name;
    quec_pdp_timer_period_s period;
    quec_pdp_timer_rerycount_s retry;
}quec_pdp_timer_params;

typedef enum
{
    CI_WRITE =0,
    CI_READ,
    CI_PDP_TIMER_WRITE,
    CI_PDP_TIMER_READ,
    CI_MODE_MAX,
}quec_ci_mode_e;
/*
typedef enum
{
    QUEC_PDP_READ  =0,
    QUEC_PDP_WRITE   
}quec_pdp_timer_mode_e;
*/
typedef enum 
{
    DNS_NETWORK_PROXY = 0,
    DNS_MODULE_PROXY,
}quec_dns_proxy_e;
        

//only for save to nv
typedef struct
{
    quec_pdp_timer_name_e timer_name;
    uint16 period_time;
    uint16 retry_count;
}quec_pdp_timer_storage_s;

typedef struct
{
    bool qspn_atcmd;
    uint8 spn_display;
    uint8 Length;   
    uint8 coding;
    uint8 Name[ CI_MAX_NAME_LENGTH ]; 
}quec_spn_s;

typedef enum 
{
    SPN_CODING_GSM7 =0,
    SPN_CODING_UCS2 =1,
}quec_spn_coding_e;

extern quec_spn_s g_spn_name;
extern quec_pdp_timer_storage_s quec_timer_storage[QUEC_PDP_TIMER_NUMBER];
extern quec_pdp_timer_params quec_pdp_timer[QUEC_PDP_TIMER_NUMBER];
#pragma pack(pop)

typedef enum 
{
	
	QUEC_NCELL_RESELECT_PRIORITY_CALC =0,
	QUEC_NCELL_RESELECT_PRIORITY_IGNOR,
}quec_ncell_reselect_priority_state_e;

#define QUEC_NCELL_PRIORITY_POSIRION  79

typedef struct
{
	quec_ncell_reselect_priority_state_e nv;
	quec_ncell_reselect_priority_state_e medcr;
	quec_ncell_reselect_priority_state_e temp;
	bool atcmd_exe;                                   //Chaim 20200616 record whether ncell/priority cmd execute
}quec_ncell_reselect_priority_state_s;

extern quec_ncell_reselect_priority_state_s ncell_priority_s;


extern QuecOSStatus quec_netdevctl_at_handle(quec_netcard_attribute_s *pnetcard_attr);


extern QuecOSStatus quec_netdevctl_bind_cid_query(uint8 *p_cid);
extern QuecOSStatus quec_netdevctl_task_init(void);
extern QuecOSStatus quec_netdevctl_msg_send(quec_netdevctl_msg_from_e msg_from, quec_netcard_msg_type_e msg_type,uint8 *pdata,uint8 data_len);
extern QuecOSStatus quec_lwip_netif_get_pdp_flag(uint8 actual_cid, char *p_pdp_flag);

extern BOOL quec_pdp_context_is_update(uint8 actual_cid,uint16 interval_ms, uint8 retry_times);
extern QuecOSStatus quec_net_socket_lwip_netif_config(quec_netif_status_e bind_op,uint8 actual_cid, bool is_netdev);
#ifdef QUEC_LED_NET_MODE_SUPPORT
extern int quec_ledmode_set(uint8 mode);
extern int quec_ledmode_get(uint8 *p_mode);
#endif

extern  QuecOSStatus quec_get_pdp_timer(quec_pdp_timer_name_e pdp_timer,uint16 *period_time,uint16 *pretry_count);
extern QuecOSStatus quec_pdp_timer_at_cmd_ci_set(quec_pdp_timer_storage_s *ptimer_set,uint32 atHandle,CiReturnCode *prc);
extern QuecOSStatus quec_pdp_timer_read(void);
extern QuecOSStatus quec_pdp_timer_write(uint8 set_position);
extern void quec_pdp_timer_update(uint8 get_position,uint16 value);
extern QuecOSStatus quec_pdp_timer_retry_count_set(uint32 atHandle,quec_pdp_timer_position_e position);
extern QuecOSStatus quec_qspn_spn_ci_req(UINT32 atHandle);
extern QuecOSStatus quec_qspn_spn_ci_cnf_process(UINT32 atHandle,CiSimPrimGetServiceProviderNameCnf  *getSpnCnf);
extern void quec_netdevctl_send_atcmd_semphore(int result);
extern void quec_netdevctl_network_ind_msg_send(quec_netdevctl_msg_from_e msg_from,quec_netcard_msg_type_e msg_type,uint8 *pdata,uint8 data_len);
extern void quec_netdevctl_set_auto_time_interval_default(void);
extern QuecOSStatus quec_netdevctl_lwip_config(quec_netif_status_e netif_config,uint8 set_cid);
extern QuecOSStatus quec_netdevctl_urc_report(quec_netcard_urc_type_e urc_type);

extern QuecOSStatus quec_set_ncell_priority_state( UINT32 ncell_atHandle,quec_ncell_reselect_priority_state_e nc_state);
extern QuecOSStatus quec_storage_ncell_priority_state(void);
extern QuecOSStatus quec_qurey_ncell_priority_state(UINT32 ncell_atHandle);
extern void quec_ncell_priority_init(void);
extern void quec_update_asr_ncell_priority(uint8 value);

#ifdef QUEC_NETDUALCH_CFG
void quec_set_netif_flags(uint8 ip_type_flag);
int quec_get_netif_flags(void);
#endif

#endif

