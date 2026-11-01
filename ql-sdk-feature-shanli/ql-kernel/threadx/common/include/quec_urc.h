/**
 ******************************************************************************
 * @file    quec_urc.h
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


#ifndef _QUEC_URC_H
#define _QUEC_URC_H


#include "teldef.h"
#include "quec_driver_common.h"
#include "quec_common.h"
#include "string_utils.h"
#include "quec_rtos.h"
#include "quec_cust_feature.h"

#define URC_COUNTER_MAX			40
#define URC_QUEUE_MSG_MAX		(URC_COUNTER_MAX*2) /*must more than URC buf size*/
//the urc config file name
#define QUEC_URC_CONFIG_CONTEXT "urc_context.config"
#define QUEC_URC_METHOD_FORCE "urc_out_method_force"  /*miles.ma 20220924 add a flag to configure the URC out method*/

/*========================================================================
 *  URC Broadcast Device Definitions
 *========================================================================*/

typedef enum
{
	URC_OUT_METHOD_UNICAST,
	URC_OUT_METHOD_BROADCAST,
	URC_OUT_METHOD_MAX
} urc_out_method_e;

typedef enum
{
	URC_DEV_NONE = -1,
	URC_DEV_0,
	URC_DEV_1,
	URC_DEV_2,
	URC_DEV_3,
	URC_DEV_4,
	URC_DEV_5,
	URC_DEV_6,
	URC_DEV_7,
	URC_DEV_8,
	URC_DEV_9,
	URC_DEV_10,
	URC_DEV_11,
	URC_DEV_12,
	URC_DEV_MAX
} urc_dev_e;

#define URC_DEV_DEFAULT_VALUE					 		                            \
		{														 		            \
            [URC_DEV_0]  = {QUEC_USBAT_CHANNEL,	        "usbat",	    1},  	\
			[URC_DEV_1]  = {QUEC_USBMODEM_CHANNEL,		    "usbmodem",     1}, 	\
			[URC_DEV_2]  = {TEL_AT_CMD_ATP_1,		        NULL,		    0}, 	\
			[URC_DEV_3]  = {QUEC_CMUX_CHANNEL_1,		    "CMUX1",		0}, 	\
			[URC_DEV_4]  = {QUEC_CMUX_CHANNEL_2,		    "CMUX2",		0}, 	\
			[URC_DEV_5]  = {QUEC_CMUX_CHANNEL_3,		    "CMUX3",		0}, 	\
			[URC_DEV_6]  = {QUEC_CMUX_CHANNEL_4,		    "CMUX4",		0}, 	\
			[URC_DEV_7]  = {TEL_AT_CMD_ATP_6,		        NULL,		    0}, 	\
			[URC_DEV_8]  = {QUEC_UART1_CHANNEL,		        "uart1", 	    1}, 	\
			[URC_DEV_9]  = {TEL_AT_CMD_ATP_8,		        NULL,		    0}, 	\
			[URC_DEV_10] = {TEL_AT_CMD_ATP_9,		        NULL,		    0}, 	\
			[URC_DEV_11] = {TEL_AT_CMD_ATP_10,		        NULL,		    0}, 	\
            [URC_DEV_12] = {TEL_AT_CMD_ATP_UART2,           "uart2",        0}      \
		}

typedef struct
{
	TelAtParserID 	atpIndex;
	char *			port_name;
	bool 			is_registered;
} urc_dev_info_t;

typedef struct
{
	bool				is_already_broadcast_by_this_port;
	bool				is_already_delayed_on_this_port;
} urc_send_sta_t;

typedef struct
{
	TelAtParserID	atpIndex;
	uint32 			id;
} urc_event_msg_t;

typedef struct
{
	TelAtParserID			atpIndex;
	uint8					* data;
	uint32					len;
	uint32					id;
	urc_out_method_e		method;
	uint32					is_already_broadcast_cnt;
} urc_out_t;


/*========================================================================
 *  URC RI Corresponding Definitions
 *========================================================================*/

typedef enum
{
	RI_CATEG_RING,
	RI_CATEG_SMS,
	RI_CATEG_OTHERS,
	RI_CATEG_MAX
} ri_category_e;


typedef enum
{
	RI_OUT_TYPE_NONE = -1,
	RI_OUT_TYPE_OFF,
	RI_OUT_TYPE_PULSE,
	RI_OUT_TYPE_ALWAYS,
	RI_OUT_TYPE_AUTO,
	RI_OUT_TYPE_WAVE,
	RI_OUT_TYPE_MAX
} ri_out_type_e;

#define RI_OUTTYPE_STR_DEFAULT_VALUE			\
		{										\
			[RI_OUT_TYPE_OFF] 		= "off",	\
			[RI_OUT_TYPE_PULSE] 	= "pulse",	\
			[RI_OUT_TYPE_ALWAYS] 	= "always",	\
			[RI_OUT_TYPE_AUTO] 		= "auto",	\
			[RI_OUT_TYPE_WAVE] 		= "wave"	\
		}

typedef enum
{
	RI_SIGNAL_TYPE_RESPECTIVE,
	RI_SIGNAL_TYPE_PHYSICAL,
	RI_SIGNAL_TYPE_MAX
} ri_signal_type_e;

typedef enum
{
	RI_OUT_LEVEL_LOW = QUEC_PIN_LEVEL_LOW,
	RI_OUT_LEVEL_HIGH = QUEC_PIN_LEVEL_HIGH,
	RI_OUT_LEVEL_MAX
} ri_out_level_e;

typedef struct
{
	ri_out_type_e 	out_type;					// RI pulse output type
	uint32 			duration;					// RI pulse duration
	uint32			counter;					// RI pulse counter
} ri_pulse_t;

typedef struct
{
	GPIO_PinNumbers		ri_gpio_pin;			// RI gpio pin
	ri_out_level_e		ri_gpio_level;			// RI gpio pin
} ri_pin_config_t;

typedef struct
{
	ri_pulse_t			pulse[RI_CATEG_MAX];	// RI pulse config for each category
	ri_signal_type_e	signal_type;			// RI singnal type
	GPIO_PinNumbers		ri_gpio_pin;			// RI gpio pin
	UINT32              sleep_time;             // RI IND not allown sleep
	ri_out_level_e		ri_gpio_level;			// RI gpio pin level
} ri_config_t;
#define RI_SLEEP_TIME_MIN     (0)
#define RI_SLEEP_TIME_MAX     (20)
#define RI_SLEEP_TIME_DEFAULT (0)

typedef enum
{
	URC_MSG_RI_ACTION,
	URC_MSG_URC_ACTION
} urc_msg_e;

typedef struct
{
	urc_msg_e type;
	uint8 * data_ptr; // malloc
	uint32 data_len;
} urc_msg_t;

/*========================================================================
 *  URC Context Definitions
 *========================================================================*/

typedef struct
{
	bool					enable;				// turn on/off URC output
	TelAtParserID			atpIndex;			// URC output port
	uint32					delay_time;			// when to put URC out
	bool					cache;				// XXX:
	bool                    cache_datamode;     // When in DATAMODE,put data in cache or not.
	ri_config_t				ri;					// RI config
} urc_config_t, * urc_config_ptr_t;				// need to config by AT command

typedef linklist_handler_t	urc_cache_t;

typedef struct
{
	urc_config_t			config;				// URC config
	urc_cache_t 			cache;				// URC buffer
	quec_mutex_t			urc_mutex;
	quec_mutex_t			urc_cfg_mutex;
	quec_sem_t				urc_sem;
	quec_queue_t			urc_queue;
	quec_mutex_t			ri_mutex;
	quec_queue_t			ri_tmr_cb_queue;
	bool					is_urc_initialized;
} urc_context_t, * urc_context_handler_t;



#define URC_CONFIG_ENABLE_DEFAULT_VALUE						QUEC_ENABLE
#define URC_CONFIG_ENABLE_MAX_VALUE							QUEC_ENABLE
#define URC_CONFIG_ENABLE_MIN_VALUE							QUEC_DISABLE

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__) || defined (__QUEC_OEM_VER_ALLIED__)
/* NL and XGD use uart1  as URC port by default */
#define URC_CONFIG_ATPINDEX_DEFAULT_VALUE					QUEC_UART1_CHANNEL
#else
#define URC_CONFIG_ATPINDEX_DEFAULT_VALUE					QUEC_USBAT_CHANNEL
#endif
#define URC_CONFIG_ATPINDEX_MAX_VALUE						(NUM_OF_TEL_ATP - 1)
#define URC_CONFIG_ATPINDEX_MIN_VALUE						TEL_AT_CMD_ATP_0


#define URC_CONFIG_DELAY_TIME_DEFAULT_VALUE					0
#define URC_CONFIG_DELAY_TIME_MAX_VALUE						120
#define URC_CONFIG_DELAY_TIME_MIN_VALUE						0

#define	URC_CONFIG_CACHE_DATAMODE_DEFAULT_VALUE				TRUE

#define	URC_CONFIG_CACHE_DEFAULT_VALUE						FALSE
#define	URC_CONFIG_CACHE_MAX_VALUE							TRUE
#define	URC_CONFIG_CACHE_MIN_VALUE							FALSE


#define	URC_CONFIG_RI_PULSE_RING_OUTTYPE_DEFAULT_VALUE		RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_RING_OUTTYPE_MAX_VALUE			RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_RING_OUTTYPE_MIN_VALUE			RI_OUT_TYPE_OFF


#define	URC_CONFIG_RI_PULSE_RING_DURATION_DEFAULT_VALUE		120
#define	URC_CONFIG_RI_PULSE_RING_DURATION_MAX_VALUE			2000

#define URC_CONFIG_METHOD_DEFAULT_VALUE					0
#define URC_CONFIG_METHOD_MAX_VALUE						2
#define URC_CONFIG_METHOD_MIN_VALUE						0
#define URC_CONFIG_METHOD_FORCE_UNICAST                 1
#define URC_CONFIG_METHOD_FORCE_BROADCAST               2
#if 0
#define	URC_CONFIG_RI_PULSE_RING_DURATION_MIN_VALUE			1
#else
/* Fitz.xu 20200313: for asr 1 tick = 5ms */
#define	URC_CONFIG_RI_PULSE_RING_DURATION_MIN_VALUE			5
#endif

#define	URC_CONFIG_RI_PULSE_RING_COUNTER_DEFAULT_VALUE		1
#define	URC_CONFIG_RI_PULSE_RING_COUNTER_MAX_VALUE			5
#define	URC_CONFIG_RI_PULSE_RING_COUNTER_MIN_VALUE			1


#define	URC_CONFIG_RI_PULSE_SMS_OUTTYPE_DEFAULT_VALUE		RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_SMS_OUTTYPE_MAX_VALUE			RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_SMS_OUTTYPE_MIN_VALUE			RI_OUT_TYPE_OFF


#define	URC_CONFIG_RI_PULSE_SMS_DURATION_DEFAULT_VALUE		120
#define	URC_CONFIG_RI_PULSE_SMS_DURATION_MAX_VALUE			2000
#if 0
#define	URC_CONFIG_RI_PULSE_SMS_DURATION_MIN_VALUE			1
#else
/* Fitz.xu 20200313: for asr 1 tick = 5ms */
#define	URC_CONFIG_RI_PULSE_SMS_DURATION_MIN_VALUE			5
#endif

#define	URC_CONFIG_RI_PULSE_SMS_COUNTER_DEFAULT_VALUE		1
#define	URC_CONFIG_RI_PULSE_SMS_COUNTER_MAX_VALUE			5
#define	URC_CONFIG_RI_PULSE_SMS_COUNTER_MIN_VALUE			1


#define	URC_CONFIG_RI_PULSE_OTHERS_OUTTYPE_DEFAULT_VALUE	RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_OTHERS_OUTTYPE_MAX_VALUE		RI_OUT_TYPE_PULSE
#define	URC_CONFIG_RI_PULSE_OTHERS_OUTTYPE_MIN_VALUE		RI_OUT_TYPE_OFF


#define	URC_CONFIG_RI_PULSE_OTHERS_DURATION_DEFAULT_VALUE	120
#define	URC_CONFIG_RI_PULSE_OTHERS_DURATION_MAX_VALUE		2000
#if 0
#define	URC_CONFIG_RI_PULSE_OTHERS_DURATION_MIN_VALUE		1
#else
/* Fitz.xu 20200313: for asr 1 tick = 5ms */
#define	URC_CONFIG_RI_PULSE_OTHERS_DURATION_MIN_VALUE		5
#endif

#define	URC_CONFIG_RI_PULSE_OTHERS_COUNTER_DEFAULT_VALUE	1
#define	URC_CONFIG_RI_PULSE_OTHERS_COUNTER_MAX_VALUE		5
#define	URC_CONFIG_RI_PULSE_OTHERS_COUNTER_MIN_VALUE		1


#define URC_CONFIG_RI_SIGNAL_TYPE_DEFAULT_VALUE				RI_SIGNAL_TYPE_RESPECTIVE
#define URC_CONFIG_RI_SIGNAL_TYPE_MAX_VALUE					(RI_SIGNAL_TYPE_MAX - 1)
#define URC_CONFIG_RI_SIGNAL_TYPE_MIN_VALUE					RI_SIGNAL_TYPE_RESPECTIVE


#define URC_CONFIG_RI_GPIO_PIN_DEFAULT_VALUE				GPIO_PIN_23
#define URC_CONFIG_RI_GPIO_PIN_MAX_VALUE					GPIO_PIN_127
#define URC_CONFIG_RI_GPIO_PIN_MIN_VALUE					GPIO_PIN_0

#define URC_CONFIG_RI_GPIO_PIN_DEFAULT_LEVEL				RI_OUT_LEVEL_HIGH
#define URC_CONFIG_RI_GPIO_PIN_MAX_LEVEL					RI_OUT_LEVEL_HIGH
#define URC_CONFIG_RI_GPIO_PIN_MIN_LEVEL					RI_OUT_LEVEL_LOW

#define URC_CONTEXT_DEFAULT_VALUE																	\
		{																							\
			.config = 																				\
			{																						\
				.enable = URC_CONFIG_ENABLE_DEFAULT_VALUE,											\
				.atpIndex = URC_CONFIG_ATPINDEX_DEFAULT_VALUE,										\
				.delay_time = URC_CONFIG_DELAY_TIME_DEFAULT_VALUE,									\
				.cache = URC_CONFIG_CACHE_DEFAULT_VALUE,											\
				.cache_datamode = URC_CONFIG_CACHE_DATAMODE_DEFAULT_VALUE,											\
				.ri = 																				\
				{																					\
					.pulse = 																		\
					{																				\
						[RI_CATEG_RING] 	= {URC_CONFIG_RI_PULSE_RING_OUTTYPE_DEFAULT_VALUE, 		\
											   URC_CONFIG_RI_PULSE_RING_DURATION_DEFAULT_VALUE, 	\
											   URC_CONFIG_RI_PULSE_RING_COUNTER_DEFAULT_VALUE},		\
						[RI_CATEG_SMS]  	= {URC_CONFIG_RI_PULSE_SMS_OUTTYPE_DEFAULT_VALUE, 		\
											   URC_CONFIG_RI_PULSE_SMS_DURATION_DEFAULT_VALUE, 		\
											   URC_CONFIG_RI_PULSE_SMS_COUNTER_DEFAULT_VALUE},		\
						[RI_CATEG_OTHERS] 	= {URC_CONFIG_RI_PULSE_OTHERS_OUTTYPE_DEFAULT_VALUE, 	\
											   URC_CONFIG_RI_PULSE_OTHERS_DURATION_DEFAULT_VALUE, 	\
											   URC_CONFIG_RI_PULSE_OTHERS_COUNTER_DEFAULT_VALUE}	\
					},																				\
					.signal_type = URC_CONFIG_RI_SIGNAL_TYPE_DEFAULT_VALUE,							\
					.ri_gpio_pin = URC_CONFIG_RI_GPIO_PIN_DEFAULT_VALUE,							\
					.sleep_time  = RI_SLEEP_TIME_DEFAULT,											\
					.ri_gpio_level  = URC_CONFIG_RI_GPIO_PIN_DEFAULT_LEVEL 							\
				}																					\
			},																						\
			.cache = NULL,																			\
			.urc_mutex = NULL,																		\
			.urc_sem = NULL,																		\
			.urc_queue = NULL,																		\
			.ri_mutex = NULL,																		\
			.is_urc_initialized = FALSE																\
		}


/*========================================================================
 *  URC RI Output Definitions
 *========================================================================*/

typedef enum
{
	RI_OUT_LEVEL_REQUIRE_IDLE,
	RI_OUT_LEVEL_REQUIRE_RUN
} ri_out_level_require_e;

typedef struct
{
	bool					is_used;
	quec_timer_t			timer;
	urc_config_t			* urc_config_ptr;
	urc_out_t 				* urc_out_ptr;
	urc_send_sta_t			status;
	TelAtParserID			actually_out_atpindex;
	ri_out_level_require_e	ri_out_level_require;
    uint8                   pusle_change_cnt; // to count the pulse number
#if defined(QUEC_URC_RI_TYPE_SUPPORT)
    ri_category_e           ri_type; // to save ri type
#endif
} ri_out_t;

#if 1 //west 201181106:add for atz respone
#define QUEC_URC_RES_RING 			"RING"
#define QUEC_URC_RES_CONNECT 		"CONNECT"
#define QUEC_URC_RES_NO_CARRIER 	"NO CARRIER"

#define QUEC_ATV_RES_VALUE_NUM  \
				{						\
					{"CONNECT",    '1'},	\
					{"RING",	   '2'},	\
					{"NO CARRIER", '3'},	\
				}

		typedef struct
		{
			char *atv_res_string;
			char atv_res_value;
		}atv_res_info;
#endif


/*========================================================================
 *  URC Configuration Definitions
 *========================================================================*/

typedef enum
{
	URC_CFG_OPT_ENABLE,
	URC_CFG_OPT_PORT,
	URC_CFG_OPT_DELAY,
	URC_CFG_OPT_CACHE,
	URC_CFG_OPT_CACHE_DATAMODE,
	URC_CFG_OPT_RI_RING,
	URC_CFG_OPT_RI_SMS,
	URC_CFG_OPT_RI_OTHERS,
	URC_CFG_OPT_RI_SIG_TYPE,
	URC_CFG_OPT_RI_SLEEP_TIME,
	URC_CFG_OPT_RI_LEVEL,
	URC_CFG_OPT_ALL
} urc_cfg_opt_e;


/*========================================================================
 *  Extern Functions Declarations
 *========================================================================*/
 
extern urc_context_t urc_context;
extern bool urc_enable_cache;

extern QuecOSStatus 			at_urc_init(void);
extern bool 					at_urc_is_initialized(void);
extern urc_context_handler_t 	at_urc_get_context(void);
extern urc_config_ptr_t 		at_urc_get_context_config(void);
extern urc_dev_info_t * 		at_urc_get_dev_info(void);
extern QuecOSStatus				at_urc_flush(void);
extern QuecOSStatus 			at_urc_ri_action(TelAtParserID atpIndex);
extern QuecOSStatus 			at_urc_send(TelAtParserID atpIndex, uint8 * data, uint32 len, bool is_output_firstly, urc_out_method_e urc_out_method, uint32 * urc_id_ptr);
extern bool 					at_urc_port_is_registered(TelAtParserID atpIndex);
extern QuecOSStatus 			at_urc_config_set_opt(urc_cfg_opt_e urc_cfg_opt, void * option);
extern QuecOSStatus 			at_urc_config_get_opt(urc_cfg_opt_e urc_cfg_opt, void * option);
extern ri_out_type_e 			at_urc_ri_get_outtype_enum(char * _ri_outtype_str);
extern char * 					at_urc_ri_get_outtype_str(ri_out_type_e ri_out_type);
extern QuecOSStatus             at_urc_write_config_data_to_nv(void);
extern QuecOSStatus             at_urc_write_urc_method_to_nv(void);
extern QuecOSStatus 			at_urc_port_config(TelAtParserID 	atp_index, bool en);
ri_signal_type_e at_urc_get_ri_signal_enum(char *ri_signal_str);
char *at_urc_get_ri_signal_type_str(ri_signal_type_e ri_signal_type);
int quec_urc_buf_high_mark(void);

#endif

