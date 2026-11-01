/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/


#ifndef QUEC_NET_APP_H
#define QUEC_NET_APP_H

#ifdef QUEC_APPTCPIP_SUPPORT

#include "quec_apptcpip_msg.h"
void quec_net_request_handler(quec_apptcpip_msg *api_msg);

void quec_net_cnf_handler(quec_apptcpip_msg *api_msg);

void quec_net_app_init(void);

int quec_net_set_pdp_profile(int pdp_cid, quec_pdp_profile  *profile_info);

int quec_net_get_pdp_profile(int pdp_cid, quec_pdp_profile  *profile_info);

int quec_net_get_pdp_state(int pdp_cid);

int quec_net_get_pdp_info(int pdp_cid, quec_pdp_info *pdp_info_ptr);


int quec_pdp_profile_set(quec_apptcpip_pdp_profile_set_req       *req_msg);

int quec_pdp_profile_get(quec_apptcpip_pdp_profile_get_req       *req_msg);

int quec_pdp_info_get(quec_apptcpip_pdp_info_get_req *req_msg);

int quec_pdp_active(quec_apptcpip_pdp_active_req *req_msg);

int quec_pdp_deactive(quec_apptcpip_pdp_deactive_req      *req_msg);

int quec_pdp_deactextive(quec_apptcpip_pdp_deactive_req      *req_msg);

int quec_pdp_dns_get(quec_apptcpip_dns_get_req *req_msg);

int quec_pdp_dns_set(quec_apptcpip_dns_set_req *req_msg);

int quec_pdp_getaddrinfo(quec_apptcpip_dns_get_addr_req  *req_msg);

int quec_netif_get_bind_status(int pdp_cid);

QuecOSStatus quec_netif_bind_service_start(int pdpCid, uint32 period_ms, uint32 netifBindTimeout_s);

QuecOSStatus quec_netif_bind_service_stop(int pdpCid);

int quec_pdp_active_ex(quec_apptcpip_pdp_active_req * req_msg);

int quec_pdp_deactive_ex(quec_apptcpip_pdp_deactive_req * req_msg);

int quec_pdp_get_act_status(int pdp_cid);
//获取pdp激活重试次数
uint32 quec_get_pdp_act_retrytimes(void);
//设置pdp激活重试次数
void quec_set_pdp_act_retrytimes(int retry_times);

QuecOSStatus quec_pdp_act_service_start(int pdpCid, TelAtParserID atpIndex, uint32 retryTimes);

QuecOSStatus quec_pdp_act_service_stop(int pdpCid);

QuecOSStatus quec_net_status_mgr_init(void);

#if defined(QUEC_LED_TASK_SUPPORT)
extern int quec_pdp_act_status_check(void);
#endif

#ifdef QUEC_DEACT_PDP_FROM_DEATTCH
#define QUEC_PDP_MAX_NUM   16
#endif

#ifdef QUEC_TCP_DNS_TIMEOUT_CONFIG_FEATURE
	// caican.lin 2021.05.10
	#define QUEC_TCPIP_DNS_RETRIES_MIN		2
	#define QUEC_TCPIP_DNS_RETRIES_MAX		DNS_MAX_RETRIES
	#define QUEC_TCPIP_DNS_RETRIES_DEFAULT	4
	
	
	// caican.lin 2021.05.21
	#define QUEC_TCPIP_DNS_TOTAL_TIMEOUT	60
	// 这是单次超时时间间隔，非总的超时时间总和
	#define QUEC_TCPIP_DNS_TIMEOUT_MIN		2
	#define QUEC_TCPIP_DNS_TIMEOUT_MAX		8
	#define QUEC_TCPIP_DNS_TIMEOUT_DEFAULT	8
	
	int quec_dns_set_timeout(uint8_t sec, uint8_t retries);
	uint8_t quec_get_dns_set_wait_tmr(void);
#endif


#endif

#endif
