/**
 ******************************************************************************
 * @file    httpc_resp.h
 * @author  Chavis.Chen
 * @version V1.0.0
 * @date    06-Dec-2018
 * @brief   This file declares http response APIs.
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


#ifndef _HTTPC_RESP_H
#define _HTTPC_RESP_H

#include "quec_common.h"
#include "quec_rtos.h"
#include "quec_memory.h"
#include "quec_debug.h"
#include "httpc_common.h"
#include "watermark.h"


/*========================================================================
 *	HTTP Response Macro Definition
 *========================================================================*/



/*========================================================================
 *	HTTP Response Code
 *========================================================================*/

#define HTTP_RESP_CODE_LIST(E)												\
		E(HTTP_RESP_CODE_100,	"100",	"Continue")							\
		E(HTTP_RESP_CODE_101, 	"101",	"Switching Protocols")				\
		E(HTTP_RESP_CODE_200, 	"200",	"OK")								\
		E(HTTP_RESP_CODE_201, 	"201",	"Created")							\
		E(HTTP_RESP_CODE_202,	"202",	"Accepted")							\
		E(HTTP_RESP_CODE_203,	"203",	"Non-Authoritative Information")	\
		E(HTTP_RESP_CODE_204,	"204",	"No Content")						\
		E(HTTP_RESP_CODE_205,	"205",	"Reset Content")					\
		E(HTTP_RESP_CODE_206,	"206",	"Partial Content")					\
		E(HTTP_RESP_CODE_300,	"300",	"Multiple Choices")					\
		E(HTTP_RESP_CODE_301,	"301",	"Moved Permanently")				\
		E(HTTP_RESP_CODE_302,	"302",	"Found")							\
		E(HTTP_RESP_CODE_303,	"303",	"See Other")						\
		E(HTTP_RESP_CODE_304,	"304",	"Not Modified")						\
		E(HTTP_RESP_CODE_305,	"305",	"Use Proxy")						\
		E(HTTP_RESP_CODE_306,	"306",	"Unused")							\
		E(HTTP_RESP_CODE_307,	"307",	"Temporary Redirect")				\
		E(HTTP_RESP_CODE_400,	"400",	"Bad Request")						\
		E(HTTP_RESP_CODE_401,	"401",	"Unauthorized")						\
		E(HTTP_RESP_CODE_402,	"402",	"Payment Required")					\
		E(HTTP_RESP_CODE_403,	"403",	"Forbidden")						\
		E(HTTP_RESP_CODE_404,	"404",	"Not Found")						\
		E(HTTP_RESP_CODE_405,	"405",	"Method Not Allowed")				\
		E(HTTP_RESP_CODE_406,	"406",	"Not Acceptable")					\
		E(HTTP_RESP_CODE_407,	"407",	"Proxy Authentication Required")	\
		E(HTTP_RESP_CODE_408,	"408",	"Request Time-out")					\
		E(HTTP_RESP_CODE_409,	"409",	"Conflict")							\
		E(HTTP_RESP_CODE_410,	"410",	"Gone")								\
		E(HTTP_RESP_CODE_411,	"411",	"Length Required")					\
		E(HTTP_RESP_CODE_412,	"412",	"Precondition Failed")				\
		E(HTTP_RESP_CODE_413,	"413",	"Request Entity Too Large")			\
		E(HTTP_RESP_CODE_414,	"414",	"Request-URI Too Large")			\
		E(HTTP_RESP_CODE_415,	"415",	"Unsupported Media Type")			\
		E(HTTP_RESP_CODE_416,	"416",	"Requested range not satisfiable")	\
		E(HTTP_RESP_CODE_417,	"417",	"Expectation Failed")				\
		E(HTTP_RESP_CODE_500,	"500",	"Internal Server Error")			\
		E(HTTP_RESP_CODE_501,	"501",	"Not Implemented")					\
		E(HTTP_RESP_CODE_502,	"502",	"Bad Gateway")						\
		E(HTTP_RESP_CODE_503,	"503",	"Service Unavailable")				\
		E(HTTP_RESP_CODE_504,	"504",	"Gateway Time-out")					\
		E(HTTP_RESP_CODE_505,	"505",	"HTTP Version not supported")

#define HTTP_RESP_CODE_ENUM_DEF(enum, code_str, meaning_str)	enum,
#define HTTP_RESP_CODE_TBL_FILL(enum, code_str, meaning_str)	[enum] = {code_str, meaning_str},

typedef enum
{
	HTTP_RESP_CODE_LIST(HTTP_RESP_CODE_ENUM_DEF)
	HTTP_RESP_CODE_MAX
} httpc_response_code_e;

typedef struct
{
	char * code;
	char * meaning;
} httpc_response_code_t;


/*========================================================================
 *	HTTP Response Head
 *========================================================================*/

#define HTTP_RESP_HEAD_LIST(E)											\
		E(HTTP_RESP_HEAD_ACCEPT_RANGES,			"Accept-Ranges")		\
		E(HTTP_RESP_HEAD_AGE,					"Age")					\
		E(HTTP_RESP_HEAD_ALLOW,					"Allow")				\
		E(HTTP_RESP_HEAD_CACHE_CONTROL,			"Cache-Control")		\
		E(HTTP_RESP_HEAD_CONTENT_ENCODING,		"Content-Encoding")		\
		E(HTTP_RESP_HEAD_CONTENT_LANGUAGE,		"Content-Language")		\
		E(HTTP_RESP_HEAD_CONTENT_LENGTH,		"Content-Length")		\
		E(HTTP_RESP_HEAD_CONTENT_LOCATION,		"Content-Location")		\
		E(HTTP_RESP_HEAD_CONTENT_MD5,			"Content-MD5")			\
		E(HTTP_RESP_HEAD_CONTENT_RANGE,			"Content-Range")		\
		E(HTTP_RESP_HEAD_CONTENT_TYPE,			"Content-Type")			\
		E(HTTP_RESP_HEAD_DATE,					"Date")					\
		E(HTTP_RESP_HEAD_ETAG,					"ETag")					\
		E(HTTP_RESP_HEAD_EXPIRES,				"Expires")				\
		E(HTTP_RESP_HEAD_LAST_MODIFIED,			"Last-Modified")		\
		E(HTTP_RESP_HEAD_LOCATION,				"Location")				\
		E(HTTP_RESP_HEAD_PRAGMA,				"Pragma")				\
		E(HTTP_RESP_HEAD_PROXY_AUTHENTICATE,	"Proxy-Authenticate")	\
		E(HTTP_RESP_HEAD_REFRESH,				"Refresh")				\
		E(HTTP_RESP_HEAD_RETRY_AFTER,			"Retry-After")			\
		E(HTTP_RESP_HEAD_SERVER,				"Server")				\
		E(HTTP_RESP_HEAD_SET_COOKIE,			"Set-Cookie")			\
		E(HTTP_RESP_HEAD_TRAILER,				"Trailer")				\
		E(HTTP_RESP_HEAD_TRANSFER_ENCODING,		"Transfer-Encoding")	\
		E(HTTP_RESP_HEAD_VARY,					"Vary")					\
		E(HTTP_RESP_HEAD_VIA,					"Via")					\
		E(HTTP_RESP_HEAD_WARNING,				"Warning")				\
		E(HTTP_RESP_HEAD_WWW_AUTHENTICATE,		"WWW-Authenticate")		\
		E(HTTP_RESP_HEAD_CONNECTION,            "Connection")
		
#define HTTP_RESP_HEAD_ENUM_DEF(enum, str)	enum,
#define HTTP_RESP_HEAD_TBL_FILL(enum, str )	[enum] = str,

typedef enum
{
	HTTP_RESP_HEAD_LIST(HTTP_RESP_HEAD_ENUM_DEF)
	HTTP_RESP_HEAD_MAX
} httpc_response_head_e;


#define HTTP_RESP_TRANS_ENC_MODE_LIST(E)					\
		E(HTTP_RESP_TRANS_ENC_MODE_CHUNKED, "chunked")

#define HTTP_RESP_TRANS_ENC_MODE_ENUM_DEF(enum, str)	enum,
#define HTTP_RESP_TRANS_ENC_MODE_TBL_FILL(enum, str)	[enum] = str,

typedef enum
{
	HTTP_RESP_TRANS_ENC_MODE_NONE = -1,
	HTTP_RESP_TRANS_ENC_MODE_LIST(HTTP_RESP_TRANS_ENC_MODE_ENUM_DEF)
	HTTP_RESP_TRANS_ENC_MODE_MAX
} httpc_response_trans_enc_mode_e;

/*========================================================================
 *	HTTP Response Structure
 *========================================================================*/

typedef struct
{
	httpc_data_t	wholePkt;
	httpc_data_t	code;
	httpc_data_t	field[HTTP_RESP_HEAD_MAX];
} httpc_response_head_t;

typedef struct
{
	int32	data_len;				/*> total legnth of every single chunked data mass */
	int32	read_len;				/*> already read length of every single chunked data mass */
	uint8 * tmp_buf;				/*> malloc a block of memory to save the original data which is read form wm of http downlink */
	int32	tmp_buf_used_len;		/*> valid data length in tmp_buf */
	int32	tmp_buf_empty_len;		/*> empty length in tmp_buf */
	int32	mark_head_end;			/*> mark for http head end,
										[0]: no <CR> or <LF> found,
										[1]: found <CR>,
										[2]: found <CR><LF>,
										[3]: found <CR><LF><CR>,
										[4]: found <CR><LF><CR><LF> */
	bool	is_totally_rcved;		/*> all the http data is received by user */
} httpc_response_chunked_t;

typedef struct
{
	struct
	{
		wm_handle_t			handle;
		quec_mutex_t		mutex;
		struct
		{
			void(* reached_low)(void *);
			void(* reached_high)(void *);
			void(* wm_empty)(void *);
		} cb;
	} wm_mgr;
	httpc_response_head_t	head;		/*> malloc a block of memory to save head when necessary */
	uint32					read_len;
	httpc_response_chunked_t chunked;	/*> malloc */
} httpc_response_t;

typedef enum
{
	HTTP_RESP_TYPE_HEAD,
	HTTP_RESP_TYPE_BODY,
	HTTP_RESP_TYPE_WHOLE
} httpc_response_type_e;


/*========================================================================
 *	HTTP Response APIs Decalrations
 *========================================================================*/

extern QuecOSStatus 	httpc_response_new
						(
							httpc_response_t * httpc_response_ptr,
							uint32 wm_size,
							uint32 wm_low_val,
							uint32 wm_high_val
						);
extern QuecOSStatus 	httpc_response_wm_lock(httpc_response_t * httpc_response_ptr);
extern QuecOSStatus 	httpc_response_wm_unlock(httpc_response_t * httpc_response_ptr);
extern QuecOSStatus 	httpc_response_head_parse(httpc_response_t * httpc_response_ptr, uint32 head_wait_timeout_ms, bool require_drop_head);
extern httpc_data_t * 	httpc_response_head_get_field(httpc_response_t * httpc_response_ptr, httpc_response_head_e httpc_response_head);
extern int 				httpc_response_head_get_code(httpc_response_t * httpc_response_ptr);
extern char * 			httpc_response_head_get_code_meaning(httpc_response_t * httpc_response_ptr);
extern httpc_response_trans_enc_mode_e httpc_response_get_transfer_encoding_mode(httpc_response_t * httpc_response_ptr);
extern int 				httpc_response_get_whole_pkt_length(httpc_response_t * httpc_response_ptr);
extern QuecOSStatus 	httpc_response_body_read(httpc_response_t * httpc_response_ptr, uint8 * body_buf, uint32 toReadLen, uint32 * pActualReadLen, bool * isTotallyRead);
extern QuecOSStatus 	httpc_response_body_chunked_read(httpc_response_t * httpc_response_ptr, uint8 * body_buf, uint32 toReadLen, uint32 * pActualReadLen, bool * isTotallyRead);
extern QuecOSStatus 	httpc_response_whole_read(httpc_response_t * httpc_response_ptr, uint8 * whole_buf, uint32 toReadLen, uint32 * pActualReadLen, bool * isTotallyRead);
extern QuecOSStatus 	httpc_response_whole_chunked_read(httpc_response_t * httpc_response_ptr, uint8 * whole_buf, uint32 toReadLen, uint32 * pActualReadLen, bool * isTotallyRead);

#endif

