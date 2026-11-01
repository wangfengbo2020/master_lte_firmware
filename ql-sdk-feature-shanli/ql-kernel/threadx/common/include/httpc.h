/**
 ******************************************************************************
 * @file    httpc.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    06-Dec-2018
 * @brief   This file declares the http client external APIs.
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


#ifndef _HTTPC_H
#define _HTTPC_H

#include "httpc_req.h"
#include "httpc_resp.h"

#ifdef QUEC_WOLFSSL_SUPPORT
#include "quectel_ssl_interface.h"
#include "ssl.h"
#include "error-ssl.h"
#else

#endif

typedef enum
{
	HTTP_ERR_SUCCESS = 0,
	HTTP_ERR_INVALID_OBJ,
	HTTP_ERR_INVALID_URL,
	HTTP_ERR_DNS_FAIL,
	HTTP_ERR_SOCK_CREATE_FAIL,
	HTTP_ERR_SOCK_BIND_FAIL,
	HTTP_ERR_SOCK_CONN_FAIL,
	HTTP_ERR_SOCK_SEND_FAIL,
	HTTP_ERR_SOCK_RECV_FAIL,
	HTTP_ERR_SOCK_CLOSE_FAIL,
	HTTP_ERR_INVALID_REQ_MTD,
	HTTP_ERR_RESP_TIMEOUT,
	HTTP_ERR_RESP_INVALID_VER,
	HTTP_ERR_RESP_INVALID_FORMAT,
	HTTP_ERR_NO_MEMORY,
	HTTP_ERR_UNKNOWN
} httpc_errno_e;

typedef enum
{
	HTTP_EVENT_IDLE = 0,
	HTTP_EVENT_CONNECTING,
	HTTP_EVENT_CONNECTED,
	HTTP_EVENT_SEND_FAIL,
	HTTP_EVENT_DWNLK_PAUSE,
	HTTP_EVENT_DWNLK_FAIL,
	HTTP_EVENT_DATA_INCOME,
	HTTP_EVENT_DISCONNECTED
} httpc_event_e;

typedef struct
{
	struct
	{
		httpc_data_t url;	/*> malloc */
		int			 fd;
		int			 ai_family;
		int			 pdp_cid;
		int 		 nosack_enable;

		struct
		{
			bool				enable;
			int					ctx_id;
#ifdef QUEC_WOLFSSL_SUPPORT

			WOLFSSL *			session_ptr;
			struct
			{
				WOLFSSL_SESSION *	session_ptr;
				struct sockaddr		sockaddr;
			} session_reuse;
#else
			int                 ssl_session_id;
#endif
		} ssl;
		
		struct
		{
			uint32	timeout_ms;
		} connect;

		struct
		{
			uint32	buf_sz;
			uint32	timeout_ms;
			bool	is_proc_started;
			bool	user_require_head;
            bool    cache_send;
			struct
			{
				quec_sem_t	 sem;
				quec_sem_t	 rdy_sem;
				quec_task_t  task;
				quec_mutex_t mutex;
				bool         select_status;
				bool         recv_status;/*select 状态*/
			} preprocess;
			struct
			{
				quec_sem_t	sem;
				quec_sem_t	rdy_sem;
				quec_task_t task;
			} process;
			struct
			{
				bool		recv_retrieve_pause_enable;
				bool		dwnlk_pause_enable;
			} ioctl;
		} send, recv;

		struct
		{
			uint32 linger_time_s;
		} close;

		struct
		{
		    bool    ipv6_domain;/* Ipv6 domain name type */
			char * 	domain;		/*> malloc */
			uint16 	port;
			char * 	path;		/*> malloc */
			bool	try_multi_host;
		} peer;

		void(* event_cb )(void * httpc, httpc_event_e httpc_event, int argv);
	} sock;

	httpc_request_t		request;
	httpc_response_t	response;

	struct
	{
		httpc_errno_e	httpc_errno;
		quec_mutex_t	mutex;
	} err_mgr;

	struct
	{
		quec_task_t 	task;
		quec_sem_t		sem;
		bool			wait_for_resource_recycle;/*资源释放标志*/
	} destroy;
	
	bool is_initialized;
} httpc_t;


extern QuecOSStatus httpc_new(httpc_t * httpc);
extern QuecOSStatus httpc_destroy(httpc_t * httpc);
extern QuecOSStatus httpc_destroy_wait(httpc_t * httpc);
extern QuecOSStatus httpc_send_proc_start(httpc_t * httpc);
extern QuecOSStatus httpc_recv_proc_start(httpc_t * httpc);
extern void 		httpc_set_errno(httpc_t * httpc, httpc_errno_e errno);
extern QuecOSStatus httpc_get_errno(httpc_t * httpc, httpc_errno_e * errno);
extern QuecOSStatus httpc_url_parse(httpc_t * httpc);
extern QuecOSStatus httpc_connect_to_server(httpc_t * httpc);
extern QuecOSStatus httpc_send(httpc_t * httpc, uint8 * send_data, uint32 send_len);
extern QuecOSStatus httpc_recv_whole(httpc_t * httpc, uint8 * recvBuf, uint32 toRecvLen, uint32 * pActualRecvLen, bool * isTotallyRecvd, int no_chunked);
extern QuecOSStatus httpc_recv_body(httpc_t * httpc, uint8 * recvBuf, uint32 toRecvLen, uint32 * pActualRecvLen, bool * isTotallyRecvd, int no_chunked);
extern QuecOSStatus httpc_recv_pause_retrieve_to_buffer(httpc_t * httpc);
extern QuecOSStatus httpc_recv_continue_retrieve_to_buffer(httpc_t * httpc);
extern QuecOSStatus httpc_dwnlk_pause_request(httpc_t * httpc);
extern QuecOSStatus httpc_dwnlk_pause(httpc_t * httpc);
extern QuecOSStatus httpc_dwnlk_continue(httpc_t * httpc);

extern QuecOSStatus httpc_send_save_wm(httpc_t * httpc, uint8 * send_data, uint32 send_len);

#endif


