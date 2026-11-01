/**
 ******************************************************************************
 * @file    quec_debug.h
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

#ifndef _QUEC_DEBUG_H
#define _QUEC_DEBUG_H

#include "quec_uart_at.h"
#include "quec_rtos.h"
#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define QUEC_DEBGU_WITH_UART	1
#define QUEC_DEBGU_WITH_USB		1

#define QUEC_LOG_MAX_LENGTH		200


#define QUEC_INFOMSG(fmt, args ...)  		ppp_module_Printf(1, fmt, ##args)
#define QUEC_DBGMSG(fmt, args ...)  		ppp_module_Printf(1, fmt, ##args)
#define QUEC_ERRMSG(fmt, args ...)  		ppp_module_Printf(1, fmt, ##args)

typedef enum
{
	LOG_PORT_NONE = 0x00,
	LOG_PORT_ONLY_UART = 0x01,
	LOG_PORT_ONLY_USB  = 0x02,
	LOG_PORT_UART_USB  = 0x03,
	LOG_PORT_ONLY_SD  = 0x012,
	LOG_PORT_MAX  = 0x04
} quec_log_port_e;

extern quec_log_port_e quec_debug_log_port;  //Chaim 2019.03.12 set system log 
extern quec_log_port_e quec_dbg_log_port_cache;
extern bool g_temp_debug;  //only for debug print,set port/datashow at cmd

/*========================================================================
 *  Type Definitions
 *========================================================================*/

typedef struct
{
	bool 			isInitialized;
	quec_log_port_e	port;
	quec_mutex_t	mutex;
} quec_debug_context_t;

typedef enum
{
   QUEC_UART_LOG_OFF,
   QUEC_UART_LOG_ON 
}quec_dbg_log_enable;

/*========================================================================
 *  Function Declarations
 *========================================================================*/

extern bool 		quec_debug_get_init_status(void);
extern QuecOSStatus quec_debug_port_lock(void);
extern QuecOSStatus quec_debug_port_unlock(void);
extern QuecOSStatus quec_debug_init(void);
extern char * 		quec_debug_get_short_file_name(char * file_name);
extern void 		quec_debug_print_uart(char * msg, ...);
extern void 		quec_debug_print_usb(char * msg, va_list arg_ptr);

extern uint8 		quec_debug_get_log_port(void);
extern QuecOSStatus quec_debug_set_log_port(quec_log_port_e set_log_port,int storage_en);
extern QuecOSStatus quec_debug_log_port_init(void);
typedef void (*debug_to_app_callback)(char *data);
void quec_register_debug_to_app_callback(debug_to_app_callback callback);
void quec_unregister_debug_to_app_callback(void);

extern void 		quec_log(char *msg, ...);

/*========================================================================
 *  Debug Print Definitions
 *========================================================================*/

#if QUEC_MEMORY_OPTIMIZE	

#ifndef SHORT_FILE
#define SHORT_FILE								quec_debug_get_short_file_name(__FILE__)				
#endif

#ifdef LTEONLY_THIN_SINGLE_SIM
//Sharon.li@20230704 单卡基线的项目裁剪log
#define quec_debug(msg, ...)					quec_log(""msg"", ##__VA_ARGS__)
#define custom_log(user_str, msg, ...)			quec_log(""msg"", ##__VA_ARGS__)

#else
#define quec_debug(msg, ...)					quec_log("%s,%d,"msg"", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define custom_log(user_str, msg, ...)			quec_log("%s,%d,"msg"", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif

#else
#define SHORT_FILE								quec_debug_get_short_file_name(__FILE__)

#define quec_debug(msg, ...)					quec_log("[QUEC][%s, %s, %d] "msg"", SHORT_FILE, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define custom_log(user_str, msg, ...)			quec_log("[QUEC]["user_str"][%s, %s, %d] "msg"", SHORT_FILE, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif

// you can define a log print macro in your app as below:
// #define http_log(msg, ...)	custom_log("HTTP", msg, ##__VA_ARGS__)
// when you call the macro above like: http_log("%s, http client init ok.", "hi")
// you will get the log output as below:
// [http.c, http_client_init, 100] [HTTP] hi, http client init ok.



/*> debug print assertion definition	*/

#if !defined(unlikely)
	#define unlikely(expression)				!!(expression)
#endif

/*---------------------------------*/

#if !defined(debug_print_error)
	#define debug_print_error(str) 				do {quec_debug("**ERROR** %s""", (str != NULL) ? str : "" );}while(0==1)
#endif

#if !defined(debug_print_assert)
	#define debug_print_assert(str) 			do {quec_debug("**ASSERT** %s""", (str != NULL) ? str : "" );}while(0==1)
#endif

/*---------------------------------*/

#if !defined(require)
	#define require(x, lable)																					\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					debug_print_error(NULL);               														\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_quiet)
	#define require_quiet(x, lable)																				\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_string)
	#define require_string(x, lable, str)																		\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					debug_print_error(str);																		\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_action)
	#define require_action(x, lable, action)																	\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					debug_print_error(NULL);																	\
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_action_quiet)
	#define require_action_quiet(x, lable, action)																\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif


/*---------------------------------*/

#if !defined(require_action_string)
	#define require_action_string(x, lable, action, str)														\
			do                                                                                                  \
			{                                                                                                   \
				if( unlikely( !(x) ) )                                                                          \
				{                                                                                               \
					debug_print_error(str);																		\
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr)
	#define require_noerr(err, lable)																			\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                      \
				{                                                                                               \
					debug_print_error(NULL);               														\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr_string)
	#define require_noerr_string(err, lable, str)																\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                      \
				{                                                                                               \
					debug_print_error(str);    	           														\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr_quiet)
	#define require_noerr_quiet(err, lable)																		\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                      \
				{                                                                                               \
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr_action)
	#define require_noerr_action(err, lable, action)															\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                     	\
				{                                                                                               \
					debug_print_error(NULL);               														\
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr_action_quiet)
	#define require_noerr_action_quiet(err, lable, action)														\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                     	\
				{                                                                                               \
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

/*---------------------------------*/

#if !defined(require_noerr_action_string)
	#define require_noerr_action_string(err, lable, action, str)												\
			do                                                                                                  \
			{                                                                                                   \
				QuecOSStatus localErr;																			\
				localErr = (QuecOSStatus)(err);																	\
				if( unlikely( localErr ) )                                                                     	\
				{                                                                                               \
					debug_print_error(str); 	              													\
					{action;}																					\
					goto lable;                                                                                 \
				}                                                                                               \
			} while( 1==0 )
#endif

#define QUEC_ASSERT(x)		do 														\
							{														\
								debug_print_assert("system will dump !!!");			\
								ASSERT(x);											\
							} while( 1==0 )



#ifdef __cplusplus
} /*"C" */
#endif

#endif

