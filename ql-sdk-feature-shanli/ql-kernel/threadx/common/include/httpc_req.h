/**
 ******************************************************************************
 * @file    httpc_req.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    06-Dec-2018
 * @brief   This file declares http request APIs.
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


#ifndef _HTTPC_REQ_H
#define _HTTPC_REQ_H

#include "quec_common.h"
#include "quec_rtos.h"
#include "quec_memory.h"
#include "quec_debug.h"
#include "httpc_common.h"
#include "linklist.h"
#include "watermark.h"


/*========================================================================
 *	HTTP Request Method
 *========================================================================*/

#define HTTP_REQ_MTD_LIST(E)				\
		E(HTTP_REQ_MTD_GET, 	"GET")		\
		E(HTTP_REQ_MTD_HEAD, 	"HEAD")		\
		E(HTTP_REQ_MTD_POST, 	"POST")		\
		E(HTTP_REQ_MTD_PUT, 	"PUT")		\
		E(HTTP_REQ_MTD_DELETE,	"DELETE")	

#define HTTP_REQ_MTD_ENUM_DEF(enum, str)		enum,
#define HTTP_REQ_MTD_TBL_FILL(enum, str)		[enum] = str,

typedef enum
{
	HTTP_REQ_MTD_LIST(HTTP_REQ_MTD_ENUM_DEF)
	HTTP_REQ_MTD_MAX
} httpc_request_method_e;


/*========================================================================
 *	HTTP Request Head
 *========================================================================*/

#define HTTP_REQ_HEAD_LIST(E)												\
		E(HTTP_REQ_HEAD_ACCEPT, 				"Accept")					\
		E(HTTP_REQ_HEAD_CONNECTION, 			"Connection")				\
		E(HTTP_REQ_HEAD_CONTENT_LENGTH, 		"Content-Length")			\
		E(HTTP_REQ_HEAD_CONTENT_TYPE, 			"Content-Type")				\
		E(HTTP_REQ_HEAD_HOST, 					"Host")						\
		E(HTTP_REQ_HEAD_RANGE, 					"Range")

#define HTTP_REQ_HEAD_ENUM_DEF(enum, str)	enum,
#define HTTP_REQ_HEAD_TBL_FILL(enum, str)	[enum] = str,

typedef enum
{
	HTTP_REQ_HEAD_LIST(HTTP_REQ_HEAD_ENUM_DEF)
	HTTP_REQ_HEAD_MAX
} httpc_request_head_e;


/*========================================================================
 *	HTTP Request Structure
 *========================================================================*/

typedef struct
{
	struct
	{
		linklist_handler_t 	handle;
		uint32				total_len;
	} head_linklist_mgr;

	struct
	{
		linklist_handler_t 	handle;
		quec_mutex_t		mutex;	// hasn't create thie mutex
		uint32				total_len;
	} body_linklist_mgr;

	struct
	{
		wm_handle_t 		handle;
		quec_mutex_t		mutex;
		struct
		{
			void(* reached_low)(void *);
			void(* reached_high)(void *);
			void(* wm_empty)(void *);
		} cb;
	} wm_mgr;
} httpc_request_t;


/*========================================================================
 *	HTTP Request APIs Decalrations
 *========================================================================*/

extern QuecOSStatus httpc_request_new
					(
						httpc_request_t * httpc_request_ptr,
						uint32 wm_size,
						uint32 wm_low_val,
						uint32 wm_high_val
					);
extern QuecOSStatus httpc_request_add_line(httpc_request_t * httpc_request_ptr, httpc_request_method_e httpc_request_method, char * path);
extern QuecOSStatus httpc_request_add_head(httpc_request_t * httpc_request_ptr, char * request_head_name, char * request_head_value);
extern QuecOSStatus httpc_request_rmv_head(httpc_request_t * httpc_request_ptr, char * request_head_name);
extern QuecOSStatus httpc_request_generate_pkt_head(httpc_request_t * httpc_request_ptr);
extern QuecOSStatus httpc_request_wm_lock(httpc_request_t * httpc_request_ptr);
extern QuecOSStatus httpc_request_wm_unlock(httpc_request_t * httpc_request_ptr);
extern QuecOSStatus httpc_request_body_linklist_lock(httpc_request_t * httpc_request_ptr);
extern QuecOSStatus httpc_request_body_linklist_unlock(httpc_request_t * httpc_request_ptr);
extern QuecOSStatus httpc_request_destroy(httpc_request_t * httpc_request_ptr);


#endif

