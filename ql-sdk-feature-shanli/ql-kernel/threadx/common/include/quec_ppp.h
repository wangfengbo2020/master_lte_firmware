/**
 ******************************************************************************
 * @file    quec_ppp.h
 * @author  Chaim.qian
 * @version V1.0.0
 * @date    6-Nov-2018
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

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

						EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN			  WHO		  WHAT, WHERE, WHY
------------	 -------	 -------------------------------------------------------------------------------
11/6/2018		  Chaim 	 add ppp function
=================================================================*/
#ifndef __QUEC_PPP_H_
#define __QUEC_PPP_H_


#include "quec_cust_feature.h"
#include "quec_debug.h"

#include "quec_net.h"
#include "ppp_platform.h"
#include "ppp_types.h"
#include "quec_msg_process.h"

//chaim 2018.11.6 QUEC PPP log enable 
#define QUEC_PPP_LOG_ENABLE

// chaim  modem_control will use ppp_log,so put it in .h file
#ifdef QUEC_PPP_LOG_ENABLE
	#define ppp_log(msg,...)  custom_log("PPP",msg,##__VA_ARGS__)
#else
	#define ppp_log(msg,...)
#endif
typedef enum
{
    QUEC_PPP_NONE =-1,   //Chaim 2019.1.20 ppp not exist
    QUEC_PPP_OPEN = 0,   //Chaim 2019.1.20 ppp_open,in datamode but ppp not connect
    QUEC_PPP_CMD_MODE,   //Chaim 2019.1.20 ppp connect,but receive +++ and in cmd mode
    QUEC_PPP_DATA_MODE,   //Chaim 2019.1.20 ppp connect and in data mode
}quec_ppp_state_e;

/*
Chaim 2019.1.16 add enum
0--if initiative terminate ppp,will not send ppp terminate_frame
1---if initiative terminate ppp,will send ppp terminate_frame,
*/
typedef enum 
{
    QUEC_PPP_NOT_SEND_TERM_FRAME =0,
    QUEC_PPP_SEND_TERM_FRAME
}quec_ppp_termframe_flag_e;
    


typedef enum
{
    QUEC_PPP_DISCONNECT_NORMAL=0,   //before disconnect need check ppp state
    QUEC_PPP_DISCONNECT_ABORT,       //send terminate requestion immediately
    QUEC_PPP_DISCONNECT_TIMEOUT,     //wait terminate ack timeout,terminate imediately
}quec_ppp_disconnect_flag_e;

typedef enum
{
    QUEC_TERMFRAME_NO_SEND=0,     //QPPPDROP must not sed ppp termframe
    QUEC_TERMFRAME_AUTO_SEND,     //depend on whether unvarnished transmission,if in need send
    QUEC_TERMFRAME_NEED_SEND,     //must send
    QUEC_TERMFRAME_MAX,     //must send
}quec_ppp_drop_flag_e;
    

typedef struct
{
    TelAtParserID atp_index;
    quec_ppp_disconnect_flag_e flag;
}quec_msg_ppp_escape_s; 

typedef enum
{
    QUEC_DIAL_STRIGN_ANALYSIS_NONE =0,
    QUEC_DIAL_STRIGN_ANALYSIS_START,
    //QUEC_DIAL_STRIGN_ANALYSIS_PROCEED,
    QUEC_DIAL_STRIGN_ANALYSIS_END
}quec_dial_string_find_state_e;

typedef enum 
{
    QUEC_PPP_DEBUG_DISABLE = 0,
    QUEC_PPP_DEBUG_ENABLE
}quec_ppp_debug_type_e;


/*-----------------------------------------------------------------------------------------
 * Function: receive +++ in ppp dial,and  not get ip dns in ppp process,terminate ppp process.
 *
 * Parameter:
 *    NULL
 * 
 * Return:
 *    QUEC_SUCCESS: not get ip dns,terminate ppp process .
 *    kOptionErr:	had get ip dns,not handle.
 *
 * Note:
 *    NULL
-----------------------------------------------------------------------------------------*/
extern QuecOSStatus quec_ppp_three_plus_process(void);

extern void quec_ppp_terminate_req_immediately(void);


extern  QuecOSStatus quec_ppp_terminate_req(quec_msg_process_s *pmsg_set);
extern QuecOSStatus quec_ppp_set_terminateframe_flag(quec_ppp_termframe_flag_e flag);
extern quec_ppp_termframe_flag_e quec_ppp_get_terminateframe_flag(void);
extern bool quec_ppp_is_connect(void);
extern QuecOSStatus quec_ppp_read_terminateframe_flag(void);
extern bool quec_ppp_get_modem_if_state(void);
extern bool quec_ppp_is_exist(void);
extern int quec_dial_string_parse(char *str);
extern  QuecOSStatus quec_ppp_set_debug_enable(quec_ppp_debug_type_e set_debug, uint8 storage_en);
extern quec_ppp_debug_type_e quec_ppp_get_debug_enable(void);
extern QuecOSStatus quec_ppp_debug_init(void);
extern QuecOSStatus quec_ppp_netif_config(quec_netif_status_e bind_op, quec_lwip_ip_type_e ip_type);
extern void quec_ppp_atcmd_result_handle(atcmdResultE result);

extern QuecOSStatus quec_ppp_set_state(PppStateE state);
extern PppStateE  quec_ppp_get_state(void);
extern QuecOSStatus quec_ppp_response(TelAtParserID atp_index,char *at_rsp);
extern QuecOSStatus quec_ppp_set_dcd_level(TelAtParserID atp_index,quec_pin_level_value_e level);
extern bool quec_ppp_get_atp_invalid(TelAtParserID atp_index);
extern QuecOSStatus quec_read_ppp_remoteip(void);
extern QuecOSStatus quec_set_ppp_remoteip(uint8 value);
extern bool quec_get_ppp_remoteip(void);
extern QuecOSStatus quec_ppp_set_drop_value(uint8 set_value);
extern quec_ppp_drop_flag_e quec_ppp_get_drop_and_reset(void);
extern QuecOSStatus quec_ppp_get_ipv4(uint32 ip,uint8 *pdotted_ip);
extern QuecOSStatus quec_ppp_get_iptype(uint8 dial_cid,quec_lwip_ip_type_e *p_iptype);
extern QuecOSStatus quec_ppp_set_cgdcont(uint8 cid);

#ifdef QUEC_PPP_MAX_MALLOC_CTRL
bool quec_ppp_malloc_check(void);

#endif

#if QUEC_PPP_NETIF_IP_DN_WLIST_FEATURE	
typedef enum
{
	QUEC_WHITE_DN_F_NONE = 0,
	QUEC_WHITE_DN_F_INIT,
	QUEC_WHITE_DN_F_OK,
	QUEC_WHITE_DN_F_FAILED
}quec_dn_flag_e;


#define	QUEC_IP_DNS_F_NONE  (0x0)
#define	QUEC_IP_DNS_F_NW    (0x1)
#define	QUEC_IP_DNS1_F_AT   (0x2)
#define	QUEC_IP_DNS2_F_AT   (0x4)


typedef struct
{
	ip_addr_t ip;    // ipv4 addr
	uint32    ttl;   // addr time to live
	void*     next;  // next ip node
} QUEC_IP_WHITE,*QUEC_IP_WHITE_P;

typedef struct
{
	char*         d_name;    // domain name
	uint8         s_len;     // domain name str len
	uint8         flags;     // domain name status
	QUEC_IP_WHITE_P ip_list; // domain name convert ip addr list
	void*         next;      // next domain node
} QUEC_DN_WHITE,*QUEC_DN_WHITE_P;

typedef struct
{
	ip_addr_t ip_s1;    // dns ipv4 addr
	ip_addr_t ip_s2;    // dns ipv4 addr
	ip_addr_t ip_gw;    // dns ipv4 gw for mifi mode
	uint8     flags;    // config by network or manual from command
} QUEC_IP_DNS,*QUEC_IP_DNS_P;

void         quec_ip_wlist_init(void);
void         quec_ppp_ip_wlist_dns_remove(void);

QuecOSStatus quec_ip_wlist_add(uint32 ip_addr, uint32 ttl);
QuecOSStatus quec_ip_wlist_show(TelAtParserID atp_index);
QuecOSStatus quec_dn_wlist_show(int type , TelAtParserID atp_index);
QuecOSStatus quec_dn_server_ip_show(int type , TelAtParserID atp_index);
QuecOSStatus quec_ip_dn_wlist_config(int type ,char* ip_dn_buf, int option);
QuecOSStatus quec_dn_wlist_query(char* d_name, uint32 *ip, uint8 check);
QuecOSStatus quec_dns_sniffer_task_init(void);

#endif


#endif

