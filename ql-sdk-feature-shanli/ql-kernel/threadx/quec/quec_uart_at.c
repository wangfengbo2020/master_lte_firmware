/**
 ******************************************************************************
 * @file    quec_uart.h
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
10/15/2018		  Chaim	     Init version
=================================================================*/

#include "quec_include.h"
#include "quec_gpio.h"
#include "gpio_config.h"
#include "quec_uart_at.h"
#include "uart.h"
#include "gpio.h"
#include "quec_msg_process.h"
#include "UART_CommonControl.h"
#include "quec_power_manager.h"
#include "quec_board_common.h"
#include "quec_sio.h"
#include "quec_siolib.h"
#include "quec_uart.h"
#include "quec_urc.h"

#ifdef QUEC_UART_ENABLE

#ifndef MIN_SYS

#ifdef QUEC_UART_LOG_ENABLE
#define uart_log(msg, ...) custom_log("UART", msg, ##__VA_ARGS__)
#else
#define uart_log(msg, ...)
#endif

quec_cmux_log_level_e quec_cmux_log_enable = QUEC_CMUX_LOG_NONE;

extern void quec_sio_flowctl_set_send_status(TelAtParserID atpIndex, bool enable);
extern bool quec_is_sleepMode(void);

void quec_uart1_dtr_timer_handler(void);
void quec_uart1_cts_timer_handler(void);

#if defined(__QUEC_OEM_VER_WUS__)
quec_pin_level_value_e quec_dtr_det_level = QUEC_PIN_LEVEL_HIGH;
#else
quec_pin_level_value_e quec_dtr_det_level = QUEC_PIN_LEVEL_LOW;
#endif

quec_gpio_debounce_s dtr_debounce = {UART_DTR_PIN_NUM,
                                     NULL,
                                     QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
                                     QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
                                     0,
                                     0,
                                     0,
                                     quec_uart1_dtr_timer_handler};

#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

quec_gpio_debounce_s cts_debounce = {UART_CTS_PIN_NUM,
                                     NULL,
                                     QUEC_GPIO_DEBOUNCE_INTERVAL_MS,
                                     QUEC_GPIO_DEBOUNCE_INTERVAL_COUNT,
                                     0,
                                     0,
                                     0,
                                     quec_uart1_cts_timer_handler};
#endif
/*
Chaim 2019.1.17
for compatibility weith qualcomm rename minor_uart to uart2,and uart1 or uart2 is software level,
not same with hardware
(debug_port UART_PORT_STUART minor_uart ) --->uart2
(UART_PORT_FFUART uart1)--------------------->uart1

*/
#define UART_IPR_SET_WAIT_TIME 1000 / 5 // ms
extern quec_debug_port_data_show_s uart_data_show;
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

quec_ifc_value_s g_uart_ifc_value = {0, 0};
quec_ifc_value_s g_uart_temp_ifc_value = {0, 0};
static OSATimerRef uart1_flowctrl_ref = NULL;
#define UART1_IFC_CHANGE_WAIT_TIME 300 / 5 // wai 200 ms

extern QuecOSStatus quec_ifc_value_effect(TelAtParserID atp_index, bool enable);
#endif

extern QuecOSStatus at_urc_port_config(TelAtParserID atp_index, bool en);

#define QUEC_UART2_IPR_NAME "uart2_ipr.baudrate"

#define QUEC_CHECK_UART_PORT_VALID(port_num)               \
    do                                                     \
    {                                                      \
        if (port_num >= NUMBER_OF_PORTS)                   \
        {                                                  \
            uart_log("port_num =%d is invalid", port_num); \
            return kGeneralErr;                            \
        }                                                  \
    } while (0)

#if QUEC_SLEEP_DTR_HIGH_FREQ_FEATURE
// extern void des_print(const char *fmt, ...);
// extern void quec_debug_print_uart(char * msg, ...);
// #define des_print(fmt,args...) quec_debug_print_uart(fmt, ##args);
extern BOOL SystemSleepEnable_flag;
extern quec_queue_t g_quec_sleep_queue;
typedef struct
{
    uint8 hisr_trig_flag;
    uint8 dtr_msg_err;
    quec_sleep_msg_s last_dtr_msg;
} QUEC_DTR_HIGH_FREQ_RATE_S;
QUEC_DTR_HIGH_FREQ_RATE_S g_dtr_high_freq = {0};
#endif

// chaim@2018.11.18 not need these baud,for same with qualcomm
uint32 quec_uart_baud_array[] = {
    // UART_BAUD_150,
    // UART_BAUD_300,
    // UART_BAUD_600,
    // UART_BAUD_1200,
    // UART_BAUD_2400,
    // UART_BAUD_3600,
    UART_BAUD_4800,
    //  UART_BAUD_7200,
    UART_BAUD_9600,
    // UART_BAUD_14400,
    UART_BAUD_19200,
    // UART_BAUD_28800,
    UART_BAUD_38400,
    UART_BAUD_57600,
    UART_BAUD_115200,
    UART_BAUD_230400,
    UART_BAUD_460800,
    UART_BAUD_921600,
#ifdef QUECTEL_PROJECT_CUST
    UART_BAUD_1000000,
// UART_BAUD_1842000,
// UART_BAUD_3686400,

#endif
    UART_BAUD_1125000,
    UART_BAUD_1800000,
    UART_BAUD_3000000,
    UART_BAUD_3600000,

};

extern BOOL uartState[NUMBER_OF_SUPPORT_PORTS];

static QuecOSStatus quec_uart1_ipr_timer_handler(void);
static QuecOSStatus quec_uart2_ipr_timer_handler(void);

quec_baudration_self_adaption_flag_e g_quec_baud_self_adaption = QUEC_BAUD_SELF_ADAPTION_FALSE;
OSATimerRef uart2_mode_change_timer_ref = NULL; // Chaim 20190727 for uart2 change mode,qc1579
#define UART2_MODE_CHANGE_WAIT_TIME 500         // wait 500 ms Reduce frequent interruptions

quec_ipr_set_s g_uart_ipr_set[] =
    {
#if defined __QUEC_OEM_VER_UD96__
        {QUEC_UART1_CHANNEL, NULL, quec_uart1_ipr_timer_handler, {QUEC_BAUD_CURRENT_CONFIG, AT_IPR}, UART_BAUD_9600, UART_MAX_NUM_BAUD, FALSE},
#else
        {QUEC_UART1_CHANNEL, NULL, quec_uart1_ipr_timer_handler, {QUEC_BAUD_CURRENT_CONFIG, AT_IPR}, UART_BAUD_115200, UART_MAX_NUM_BAUD, FALSE},
#endif
#ifdef QUEC_UART2_ENABLE
        {TEL_AT_CMD_ATP_UART2, NULL, quec_uart2_ipr_timer_handler, {QUEC_BAUD_FROM_FAT, QUEC_UART2_IPR_NAME}, UART_BAUD_115200, UART_MAX_NUM_BAUD, FALSE},
#endif
};

// ����
QuecOSStatus quec_uart_set_cmux_log(uint8 log)
{
    QuecOSStatus ret = kGeneralErr;

    if (log >= QUEC_CMUX_LOG_MAX)
    {
        uart_log("log=%d is invalid", log);
        return ret;
    }

    if (quec_cmux_log_enable == log)
    {
        uart_log("log=%d is same with quec_cmux_log_enable=%d", log, quec_cmux_log_enable);
        return QUEC_SUCCESS;
    }
    quec_cmux_log_enable = log;
    return QUEC_SUCCESS;
}

BOOL quec_uart_get_cmux_log(void)
{
    return quec_cmux_log_enable;
}

/*�˺������ڻ�ȡ�ݴ洮�����õ�ȫ�ֱ�����ַ*/
QuecOSStatus quec_get_uart_ipr_pointer(TelAtParserID atp_index, quec_ipr_set_s **pipr_set)
{
    uint8 i = 0;
    for (i = 0; i < sizeof(g_uart_ipr_set) / sizeof(quec_ipr_set_s); i++)
    {
        if (atp_index == g_uart_ipr_set[i].atp_index)
        {
            *pipr_set = &g_uart_ipr_set[i];
            return QUEC_SUCCESS;
        }
    }
    uart_log("atp_index=%d not found", atp_index);
    return kGeneralErr;
}

/*���ò����ʺ�Ҫ�����ò�����at��ok���غ����ȥ���ã���������ͻȻ�ı�ok��ʧ���ͻ���Ϊ����ʧ��*/
/*��������һ����ʱ���������ò�����at��������������Ӳ�������ǻ�������ʱ����һ���¼����ڶ�ʱ�ص����ò�����*/
QuecOSStatus quec_uart_ipr_timer_init(TelAtParserID atp_index)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uint8 i = 0;
    quec_ipr_set_s *pipr_set = NULL;

    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get pointer fail", atp_index);
        return kGeneralErr;
    }

    if (pipr_set->timer_ref == NULL)
    {
        ret = OSATimerCreate(&pipr_set->timer_ref);
        if (ret != OS_SUCCESS)
        {
            uart_log("atp_index=%d creat timer fail", atp_index);
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*���ò����ʺ�Ҫ�����ò�����at��ok���غ����ȥ���ã���������ͻȻ�ı�ok��ʧ���ͻ���Ϊ����ʧ��*/
/*��������һ����ʱ���������ò�����at��������������Ӳ�������ǻ�������ʱ����һ��ʱ����ڶ�ʱ�ص����ò�����*/
QuecOSStatus quec_uart_ipr_timer_start(TelAtParserID atp_index)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uint8 i = 0;

    quec_ipr_set_s *pipr_set = NULL;
    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get pointer fail", atp_index);
        return kGeneralErr;
    }

    if ((pipr_set->timer_ref != NULL) && (pipr_set->timerout_handler != NULL))
    {

        ret = OSATimerStart(pipr_set->timer_ref,
                            UART_IPR_SET_WAIT_TIME,
                            0,
                            pipr_set->timerout_handler,
                            0);

        if (ret != OS_SUCCESS)
        {
            uart_log("atp_index=%d creat timer fail", atp_index);
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*���ò����ʺ�Ҫ�����ò�����at��ok���غ����ȥ���ã���������ͻȻ�ı�ok��ʧ���ͻ���Ϊ����ʧ��*/
/*��������һ����ʱ���������ò�����at��������������Ӳ�������ǻ�������ʱ����һ���¼����ڶ�ʱ�ص����ò�����*/
static QuecOSStatus quec_uart1_ipr_timer_handler(void)
{
    // temporary send msg to modem router,later will be modify
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_ipr_msg_s ipr_msg = {0, 0};

    quec_ipr_set_s *pipr_set = NULL;
    ret = quec_get_uart_ipr_pointer(QUEC_UART1_CHANNEL, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get pointer fail", QUEC_UART1_CHANNEL);
        return kGeneralErr;
    }
    ipr_msg.atp_index = QUEC_UART1_CHANNEL;
    ipr_msg.baudrate = pipr_set->set_baudrate;
    uart_log("chaim1213_test,atp_index=%d,baud=%d ", ipr_msg.atp_index, ipr_msg.baudrate);

    quec_send_msg_to_handle_task(QUEC_IPR_SET_MSG, &ipr_msg, sizeof(ipr_msg));
    return QUEC_SUCCESS;
}
#ifdef QUEC_UART2_ENABLE
/*���ò����ʺ�Ҫ�����ò�����at��ok���غ����ȥ���ã���������ͻȻ�ı�ok��ʧ���ͻ���Ϊ����ʧ��*/
/*��������һ����ʱ���������ò�����at��������������Ӳ�������ǻ�������ʱ����һ���¼����ڶ�ʱ�ص����ò�����*/
static QuecOSStatus quec_uart2_ipr_timer_handler(void)
{
    // temporary send msg to modem router,later will be modify
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_ipr_msg_s ipr_msg = {0, 0};

    quec_ipr_set_s *pipr_set = NULL;
    ret = quec_get_uart_ipr_pointer(TEL_AT_CMD_ATP_UART2, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get pointer fail", TEL_AT_CMD_ATP_UART2);
        return kGeneralErr;
    }
    ipr_msg.atp_index = TEL_AT_CMD_ATP_UART2;
    ipr_msg.baudrate = pipr_set->set_baudrate;
    uart_log("chaim1213_test,atp_index=%d,baud=%d ", ipr_msg.atp_index, ipr_msg.baudrate);

    quec_send_msg_to_handle_task(QUEC_IPR_SET_MSG, &ipr_msg, sizeof(ipr_msg));
    return QUEC_SUCCESS;
}
#endif
/*�˺������ڻ�ȡatͨ����ʵ���������ڵ�ӳ���ϵ*/
QuecOSStatus quec_uart_get_portnum(TelAtParserID atp_index, UART_Port *portNumber)
{
    // UART_Port portNumber = NUMBER_OF_PORTS;
    switch (atp_index)
    {
    case QUEC_UART1_CHANNEL:
        *portNumber = UART_PORT_STUART;
        break;

    case TEL_AT_CMD_ATP_UART2:
        *portNumber = UART_PORT_FFUART;
        break;

    default:
        uart_log("atp_index =%d is invalid", atp_index);
        return kGeneralErr;
        break;
    }
    return QUEC_SUCCESS;
}

/*�˺������ڻ�ȡ�տ���ʱ����������ֵ*/
QuecOSStatus quec_uart_get_poweron_baudrate(TelAtParserID atp_index, UART_BaudRates *pbaudrate)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UART_Port portNumber = NUMBER_OF_PORTS;

    if (pbaudrate == NULL)
    {
        uart_log("pbaudrate is a null pointer");
        return kGeneralErr;
    }
    ret = quec_uart_get_portnum(atp_index, &portNumber);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get portnum fail", atp_index);
        return kGeneralErr;
    }

    *pbaudrate = _UARTPorts[portNumber].config.baudRate;

    return QUEC_SUCCESS;
}

/*�˺������ڻ�ȡ��ǰ���õĴ��ڲ�����*/
QuecOSStatus quec_uart_get_current_baudrate(TelAtParserID atp_index, UART_BaudRates *pbaudrate)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UART_Port portNumber = NUMBER_OF_PORTS;
    quec_ipr_set_s *pipr_set = NULL;

    if (pbaudrate == NULL)
    {
        uart_log("pbaudrate is a null pointer");
        return kGeneralErr;
    }
    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get ipr_pointer fail", atp_index);
        return kGeneralErr;
    }

    *pbaudrate = pipr_set->current_baudrate;

    return QUEC_SUCCESS;
}

/*���at���õĲ������Ƿ�Ϸ�*/
QuecOSStatus quec_uart_check_baudrate(uint32 baudrate)
{
    uint8 i = 0;
    for (i = 0; i < sizeof(quec_uart_baud_array) / sizeof(uint32); i++)
    {
        if (quec_uart_baud_array[i] == baudrate)
        {
            uart_log("find legal baudrate=%d success,i=%d", baudrate, i);
            return QUEC_SUCCESS;
        }
    }

    return kGeneralErr;
}

/*�Ƚ����������õ�ȫ�ֱ������ȴ�timer��ʱ�����õ������Ĵ���*/
QuecOSStatus quec_uart_ipr_set_baudrate(TelAtParserID atp_index, UART_BaudRates baudrate)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_ipr_set_s *pipr_set = NULL;

    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get ipr_pointer fail", atp_index);
        return ret;
    }
    uart_log("chaim1213_test,atp_index=%d pipr_set->baudrate=%d,set_baudrate=%d ", atp_index, pipr_set->set_baudrate, baudrate);

    pipr_set->set_baudrate = baudrate;

    return ret;
}

#if 1
#define QUEC_CP_BAUDRATE_INI "quec_cp_baudrate.ini"
/*���沨���ʵ��ļ�ϵͳ��֮�����¿�������ȥ���ļ���ȡ*/
int quec_save_baudrate_to_file(UART_BaudRates baudrate)
{
    UART_BaudRates tmp_baudrate = UART_BAUD_115200;
    unsigned short filestream = 0;
    int ret = 0;

    filestream = FDI_fopen(QUEC_CP_BAUDRATE_INI, "rb");
    if (filestream > 0)
    {
        ret = FDI_fread((void *)&tmp_baudrate, sizeof(tmp_baudrate), 1, filestream);
        if (sizeof(tmp_baudrate) != ret)
        {
            uart_log("quec_cp_baudrate.ini is empty");
        }
        else
        {
            uart_log("save FDI_fread file ret=%d", ret);
        }

        FDI_fclose(filestream);
    }
    if (tmp_baudrate != baudrate) //
    {
        uart_log("FDI_fwrite quec_cp_baudrate.ini start!");
        tmp_baudrate = baudrate;
        filestream = FDI_fopen(QUEC_CP_BAUDRATE_INI, "wb");
        if (filestream > 0)
        {
            ret = FDI_fwrite((void *)&tmp_baudrate, sizeof(tmp_baudrate), 1, filestream);
            if (sizeof(tmp_baudrate) != ret)
            {
                uart_log("quec_cp_baudrate.ini FDI_fwrite error!");
            }
            else
            {
                uart_log("quec_cp_baudrate.ini FDI_fwrite success!!!!");
            }
            FDI_fclose(filestream);
        }
        else
        {
            uart_log("quec_cp_baudrate.ini FDI_fopen failed!!!");
        }
    }
    else
    {
        uart_log("quec_cp_baudrate.ini not need save!");
    }

    return ret;
}

#endif
/*���������ò����ʽӿ�*/
static QuecOSStatus quec_uart_set_baudrate(UART_Port portNumber, UART_BaudRates baudrate)
{
    QuecOSStatus status = QUEC_SUCCESS;
    quec_uart_config_t uart_dcb = {0};
    uart_log("chaim1213_test,portNumber=%d baudrate=%d ", portNumber, baudrate);

    quec_save_baudrate_to_file(baudrate);

    QUEC_CHECK_UART_PORT_VALID(portNumber);
    status = quec_uart_check_baudrate(baudrate);
    if (status != QUEC_SUCCESS)
    {
        uart_log("set baudrate=%d invalid", baudrate);
        return kGeneralErr;
    }

    quec_uart_get_dcbconfig(portNumber, &uart_dcb);

    if (baudrate != uart_dcb.baudrate)
    {
        uartState[portNumber] = FALSE;
        uart_dcb.baudrate = baudrate;
        quec_uart_set_dcbconfig(portNumber, &uart_dcb);
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
        quec_uart1_ifc_msg_process();
#endif
        uartState[portNumber] = TRUE;
    }

    return QUEC_SUCCESS;
}

/*��ȡ�ڶ�·���ڲ�����*/
void quec_read_uart2_baudrate_to_sdk(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uint32 baudrate = UART_MAX_NUM_BAUD;
    ret = quectel_nv_fat_read(QUEC_UART2_IPR_NAME, &baudrate, sizeof(baudrate));
    if (QUEC_SUCCESS == ret)
    {
        _UARTPorts[UART_PORT_FFUART].config.baudRate = baudrate;
    }
    return;
}

/*���ø��ϵ�ʱ���ڲ�����*/
static QuecOSStatus quec_uart_set_poweron_baudrate(TelAtParserID atp_index)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uint32 baudrate = UART_MAX_NUM_BAUD;
    UART_Port portNumber = NUMBER_OF_PORTS;
    quec_ipr_set_s *pipr_set = NULL;

    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get pointer fail,baudrate", atp_index);
        return kGeneralErr;
    }

    switch (pipr_set->baud_info.baud_src)
    {
    case QUEC_BAUD_FROM_FAT:
        ret = quectel_nv_fat_read(pipr_set->baud_info.info.filename, &baudrate, sizeof(baudrate));
        break;

    case QUEC_BAUD_CURRENT_CONFIG:
        ret = quectel_current_config_value_get(AT_IPR, &baudrate);
        if (baudrate == UART_BAUD_SELF_ADAPTION_0)
        {
            g_quec_baud_self_adaption = QUEC_BAUD_SELF_ADAPTION_TRUE;
            quec_uart_baud_selfadatpt_enable(UART_PORT_STUART);
            pipr_set->baud_selfadapt_state = TRUE;
            return QUEC_SUCCESS;
        }
        else
        {
            g_quec_baud_self_adaption = QUEC_BAUD_SELF_ADAPTION_FALSE;
            pipr_set->baud_selfadapt_state = FALSE;
            quec_save_baudrate_to_file(baudrate);
        }
        break;

    default:
        ret = kGeneralErr;
        uart_log("atp_index=%d baud_src=%d invalid", pipr_set->atp_index, pipr_set->baud_info.baud_src);
        break;
    }
    if (ret != QUEC_SUCCESS)
    {
        ret = quec_uart_get_poweron_baudrate(pipr_set->atp_index, &pipr_set->current_baudrate); // update current baudrate
        uart_log("atp_index=%d get baud_src=%d fail,update baudrate=%d", pipr_set->atp_index, pipr_set->baud_info.baud_src, pipr_set->current_baudrate);
        return kGeneralErr;
    }
    ret = quec_uart_get_portnum(pipr_set->atp_index, &portNumber);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get portNumber=%d fail", pipr_set->atp_index, portNumber);
        return kGeneralErr;
    }
    if (pipr_set->current_baudrate != baudrate)
    {
        ret = quec_uart_set_baudrate(portNumber, baudrate);
        if (ret != QUEC_SUCCESS)
        {
            uart_log("atp_index=%d set baudrate fail,use system baudrate=%d", pipr_set->atp_index, baudrate);
            return kGeneralErr;
        }
        pipr_set->current_baudrate = baudrate; // update sys_tem baudrate
    }
    return QUEC_SUCCESS;
}

/*��ʱ����������debug��ģʽ��debug��at����ģʽ*/
QuecOSStatus quec_uart2_mode_change_timer_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    if (NULL == uart2_mode_change_timer_ref)
    {
        //        ret = OSATimerCreate(&uart2_mode_change_timer_ref);
        ret = quec_rtos_timer_create(&uart2_mode_change_timer_ref);

        if (ret != OS_SUCCESS)
        {
            uart_log("uart2 mode change timer ref creat timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*��ʱ����������debug��ģʽ��debug��at����ģʽ*/
static QuecOSStatus quec_uart2_mode_change_timer_handler(uint32 argc)
{
    uint8 diagport = (uint8)argc;
    // quec_log("argc=%d,diagport=%d",argc,diagport);
    return quec_send_msg_to_handle_task(QUEC_UART2_MODE_CHANG_MSG, &diagport, sizeof(diagport));
}

/*��ʱ����������debug��ģʽ��debug��at����ģʽ*/
QuecOSStatus quec_uart2_mode_change_timer_start(uint32 diagport)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_log("mode_change timer_ref=%p,diagport=%d", uart2_mode_change_timer_ref, diagport);
    if (NULL != uart2_mode_change_timer_ref)
    {

        quec_log("egan timer start");
        ret = quec_rtos_timer_start(uart2_mode_change_timer_ref,
                                    //        ret = OSATimerStart(uart2_mode_change_timer_ref,
                                    UART2_MODE_CHANGE_WAIT_TIME,
                                    0,
                                    quec_uart2_mode_change_timer_handler,
                                    diagport);

        if (ret != OS_SUCCESS)
        {
            uart_log("start timer fail");
            return kGeneralErr;
        }
    }

    return ret;
}

#ifdef QUEC_UART1_ENABLE

OS_HISR uart1dtrHisr = NULL;
OS_HISR uart1ctsHisr = NULL;

// we can not use include board_config.h because it contain array define
// attention: move array define to board_config.c and board_config.h only declaration,remain report error

// sio_mutex
static quec_mutex_t uart1_send_mutex = NULL;

extern BOOL uartState[NUMBER_OF_SUPPORT_PORTS];

void quec_uart1_dtr_hisr(void);
void quec_uart1_cts_hisr(void);

// for clear flow auto control
extern UINT8 Uart2_FlowControl_Cfg;
extern void UART_Clear_Auto_FlowControl(UART_Port portNumber);
extern void UART2_FlowControl_SetSetting(UINT8 FlowControl_Cfg);

// uart dcd  LOW indicate at penetrate state
#define UART1_DCD_MFPREG (UART1_DCD_PIN_NUM_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C | QUEC_RESERVED_C)

#define UART1_DCD_CONFIG                         \
    {                                            \
        .pinNumber = UART1_DCD_PIN_NUM,          \
        .debounce = GPIO_DEBOUNCE_DISABLE,       \
        .direction = GPIO_OUT_PIN,               \
        .pullUpDown = GPIO_PULL_DISABLE,         \
        .initialValue = GPIO_INITIAL_VALUE_HIGH, \
        .transitionType = GPIO_NO_EDGE}

// uart ri
// ���ù�������
#define UART1_RI_MFPREG (UART1_RI_PIN_NUM_AF | QUEC_PULL_UP_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C)

#define UART1_RI_CONFIG                          \
    {                                            \
        .pinNumber = UART1_RI_PIN_NUM,           \
        .debounce = GPIO_DEBOUNCE_DISABLE,       \
        .direction = GPIO_OUT_PIN,               \
        .pullUpDown = GPIO_PULL_DISABLE,         \
        .initialValue = GPIO_INITIAL_VALUE_HIGH, \
        .transitionType = GPIO_NO_EDGE}

// uart dtr wakeup system
#if defined(__QUEC_OEM_VER_WUS__)
#define UART1_DTR_MFPREG ((UART_DTR_PIN_NUM_AF | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C | (1 << 4) | (1 << 5) | QUEC_RESERVED_C) & (~QUEC_EDGE_CLEAR))

#define UART1_DTR_CONFIG                  \
    {                                     \
        .pinNumber = UART_DTR_PIN_NUM,    \
        .direction = GPIO_IN_PIN,         \
        .transitionType = GPIO_TWO_EDGE,  \
        .debounce = GPIO_DEBOUNCE_ENABLE, \
        .pullUpDown = GPIO_PULLDN_ENABLE, \
        .initialValue = GPIO_INITIAL_VALUE_LOW}
#else
#define UART1_DTR_MFPREG ((UART_DTR_PIN_NUM_AF | QUEC_PULL_UP_C | QUEC_DRV_SLOW_C | (1 << 4) | (1 << 5) | QUEC_RESERVED_C) & (~QUEC_EDGE_CLEAR))

#define UART1_DTR_CONFIG                  \
    {                                     \
        .pinNumber = UART_DTR_PIN_NUM,    \
        .direction = GPIO_IN_PIN,         \
        .transitionType = GPIO_TWO_EDGE,  \
        .debounce = GPIO_DEBOUNCE_ENABLE, \
        .pullUpDown = GPIO_PULLUP_ENABLE, \
        .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE}
#endif
// uart rts
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

#define UART1_RTS_MFPREG (UART1_RTS_PIN_NUM_AF | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C | QUEC_RESERVED_C)

#define UART1_RTS_CONFIG                        \
    {                                           \
        .pinNumber = UART1_RTS_PIN_NUM,         \
        .debounce = GPIO_DEBOUNCE_DISABLE,      \
        .direction = GPIO_OUT_PIN,              \
        .pullUpDown = GPIO_PULL_DISABLE,        \
        .initialValue = GPIO_INITIAL_VALUE_LOW, \
        .transitionType = GPIO_NO_EDGE}

// Chaim2019.1.15 bit4 bit5 is set to wakeup
#define UART1_CTS_MFPREG (UART_CTS_PIN_NUM_AF | QUEC_PULL_DN_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C)

// Chaim 20190822 input config,init level is  GPIO_INITIAL_VALUE_NO_CHANGE
#define UART1_CTS_CONFIG                  \
    {                                     \
        .pinNumber = UART_CTS_PIN_NUM,    \
        .direction = GPIO_IN_PIN,         \
        .transitionType = GPIO_TWO_EDGE,  \
        .debounce = GPIO_DEBOUNCE_ENABLE, \
        .pullUpDown = GPIO_PULLDN_ENABLE, \
        .initialValue = GPIO_INITIAL_VALUE_NO_CHANGE}

void Quec_CTS_GPIOCallback(void)
{
    GPIOEdgeDetectionDisable(UART_CTS_PIN_NUM);
    if (uart1ctsHisr != NULL)
    {
        OS_Activate_HISR(&uart1ctsHisr);
    }
}
#endif
void Quec_DTR_GPIOCallback(void)
{
    GPIOEdgeDetectionDisable(UART_DTR_PIN_NUM);
    uart_log("uart1dtrHisr=%d", uart1dtrHisr);
    if (uart1dtrHisr != NULL)
    {
        OS_Activate_HISR(&uart1dtrHisr);
    }
}

// sizeof(uart_gpio_init_array)/sizeof(quec_pin_config_s)
quec_pin_config_s uart_gpio_init_array[] = {

    {UART1_DCD_CONFIG, UART1_DCD_MFPREG, NULL},
    {UART1_RI_CONFIG, UART1_RI_MFPREG, NULL},
    {UART1_DTR_CONFIG, UART1_DTR_MFPREG, Quec_DTR_GPIOCallback},
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
    {UART1_CTS_CONFIG, UART1_CTS_MFPREG, Quec_CTS_GPIOCallback},
    {UART1_RTS_CONFIG, UART1_RTS_MFPREG, NULL},
#endif
};

/*����uart�����ж� hisr*/
QuecOSStatus quec_create_hisr(GPIO_PinNumbers pinNumber)
{
    QuecOSStatus status = QUEC_SUCCESS;

    switch (pinNumber)
    {
    case UART_DTR_PIN_NUM:
        OS_Create_HISR(&uart1dtrHisr, "dtr", quec_uart1_dtr_hisr, HISR_PRIORITY_2);
        /*
           1. if we set mfpr rgister twice ,select up_resistance and down_resistance will cause level change
           2. level change will cause interrupt if set
           3. open interrupt before enable will eliminate interrupt influence
        */
        quec_gpio_debounce_init(&dtr_debounce);
        GpioClearEdgeDetection(pinNumber);
        GpioEnableEdgeDetection(pinNumber, GPIO_TWO_EDGE);
        break;
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
    case UART_CTS_PIN_NUM:
        OS_Create_HISR(&uart1ctsHisr, "cts", quec_uart1_cts_hisr, HISR_PRIORITY_2);
        quec_gpio_debounce_init(&cts_debounce);
        GpioClearEdgeDetection(pinNumber);
        GpioEnableEdgeDetection(pinNumber, GPIO_TWO_EDGE);
        break;
#endif
    default:
        uart_log("gpio_num=%d is invalid", pinNumber);
        status = kGeneralErr;
        break;
    }
    return status;
}

/*����uart �ⲿ�������Ż����ж�*/
static QuecOSStatus quec_uart_interrupt_pin_init(quec_pin_config_s *pin_config)
{
    QuecOSStatus status = kGeneralErr;
    if (pin_config == NULL)
    {
        uart_log("pin_config is a null pointer");
        return status;
    }

    // Chaim compiled shield
    GPIO_PinNumbers faultPin = GPIO_PIN_NOT_ASSIGNED;
    unsigned long mfprReg_data = pin_config->mfprReg_data;
    GPIO_PinNumbers pinNumber = pin_config->config.pinNumber;

    status = quec_set_gpio_mfprReg(pinNumber, mfprReg_data);
    if (status != QUEC_SUCCESS)
    {
        uart_log("gpio_num=%d,gpio set mfpreg fail", pinNumber);
        return status;
    }
    if (NULL == pin_config->GPIOCallback)
    {
        uart_log("gpio_num=%d,gpio configure GPIOCallback is NULL !!!!!", pinNumber);
        return kGeneralErr;
    }

    status = GPIOConfigure_Ex(&(pin_config->config), pin_config->GPIOCallback, NULL); // 0 is ok
    if (GPIORC_OK != status)
    {
        uart_log("gpio_num=%d,gpio configure fail", pinNumber);
        return kGeneralErr;
    }

    status = quec_create_hisr(pinNumber);
    if (QUEC_SUCCESS != status)
    {
        uart_log("gpio_num=%d,gpio interrupt open fail", pinNumber);
        return status;
    }
    return status; // use our owen return value
}

/*����uart �������ŵ�ƽ*/
QuecOSStatus quec_uart_set_pin_level(GPIO_PinNumbers set_pin_number, quec_ioctl_param *param)
{
    QuecOSStatus status = QUEC_SUCCESS;
    quec_pin_level_value_e level = *((quec_pin_level_value_e *)(param));

    if ((level != QUEC_PIN_LEVEL_LOW) && (level != QUEC_PIN_LEVEL_HIGH))
    {
        uart_log("level=%d is invalid", level);
        return kGeneralErr;
    }
    status = quec_set_gpio_level(set_pin_number, level);
    if (QUEC_SUCCESS != status)
    {
        uart_log("set pin_num=%d pin level=%d fail", set_pin_number, level);
        return status;
    }

    return status;
}

/*��ȡuart ���ƽŵ�ƽ*/
QuecOSStatus quec_uart_get_pin_level(GPIO_PinNumbers set_pin_number, quec_ioctl_param *param)
{
    QuecOSStatus status = QUEC_SUCCESS;

    if (param == NULL)
    {
        uart_log("param is a null pointer");
        return kGeneralErr;
    }

    quec_pin_level_value_e *plevel = (quec_pin_level_value_e *)param;

    status = quec_get_gpio_level(set_pin_number, plevel);
    if (QUEC_SUCCESS != status)
    {
        uart_log("get pin_num dcd level fail", set_pin_number);
        return status;
    }

    return status;
}
#ifdef QUEC_HALF_HARDWARE_FLOWERCTRL // added on 20181101
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

QuecOSStatus quec_uart1_ifc_timer_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    if (NULL == uart1_flowctrl_ref)
    {
        ret = OSATimerCreate(&uart1_flowctrl_ref);
        if (ret != OS_SUCCESS)
        {
            uart_log("uart1 flowctrl ref creat timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

static QuecOSStatus quec_uart1_ifc_timer_handler(uint32 argc)
{
    return quec_send_msg_to_handle_task(QUEC_UART1_IFC_TIMEROUT_MSG, NULL, QUEC_MSG_LEN_NONE);
}

QuecOSStatus quec_uart1_ifc_timer_start(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uart_log("uart1 flowctrl ref=%p", uart1_flowctrl_ref);
    if (NULL != uart1_flowctrl_ref)
    {
        ret = OSATimerStart(uart1_flowctrl_ref,
                            UART1_IFC_CHANGE_WAIT_TIME,
                            0,
                            quec_uart1_ifc_timer_handler,
                            0);

        if (ret != OS_SUCCESS)
        {
            uart_log("start timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*��Ӧifcָ���Ӳ������*/
QuecOSStatus quec_uart1_ifc_msg_process(void)
{
    QuecOSStatus ret = kGeneralErr;
    quec_ifc_value_s uart_ifc_value = {0, 0};
#if QUEC_HALF_HARDWARE_FLOWERCTRL
    if ((g_uart_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_SOF) && (g_uart_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_SOF))
    {
        quec_uart1_close_cts_interrupt();
    }
    else
    {
        if ((g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MAX) && (g_uart_temp_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_MAX))
        {
            if (TRUE == quec_get_uart_hardware_rts_flag_value()) // ��������Ƿ��Ѿ�������
            {
                quec_set_uart_hardware_rts_flag_value(FALSE);
                UARTInterruptControl(UART_PORT_STUART, IER_TIME_OUT, TRUE);
                UARTInterruptControl(UART_PORT_STUART, IER_RCV_DATA_AVAILABLE, TRUE);
            }
        }
        quec_cts_hardwareDisable();
    }

    quec_uart_cts_rts_pin_init(&g_uart_temp_ifc_value);

    quec_ifc_value_effect(QUEC_UART1_CHANNEL, FALSE);

    uart_log("init ok");
    if ((g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MAX) && (g_uart_temp_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_MAX))
    {
        ret = quec_cts_rts_hardware_init();
        uart_log("cts_rts_init");
        if (QUEC_SUCCESS != ret)
        {
            uart_log("open cts hardware init fail");
            return ret;
        }
    }
    else if ((g_uart_temp_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_SOF) && (g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MAX))
    {
        uart_log("cts_init");
        ret = quec_cts_hardware_init();
        if (QUEC_SUCCESS != ret)
        {
            uart_log("open cts hardware init fail");
            return ret;
        }
    }
    else if ((g_uart_temp_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_SOF) && (g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_SOF))
    {
        ret = quec_uart1_open_cts_interrupt();
        if (QUEC_SUCCESS == ret)
        {
            quec_ifc_value_effect(QUEC_UART1_CHANNEL, TRUE);
        }
        else
        {
            uart_log("open cts interrupt fail");
            return ret;
        }
    }
    else if ((g_uart_temp_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_MIN) && (g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MIN))
    {
        if ((g_uart_ifc_value.rts_control == QUEC_AT_IFC_CMD_VAL_SOF) && (g_uart_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_SOF))
        {
            quec_uart1_close_cts_interrupt();
        }
        else
        {
            quec_cts_hardwareDisable();
            quec_log("egan disable hardware");
        }
        quec_ifc_value_effect(QUEC_UART1_CHANNEL, FALSE);
    }
    else
    {
        uart_log("not find this mode !!!");
    }

#else

    if (g_uart_temp_ifc_value.cts_control == QUEC_AT_IFC_CMD_VAL_MAX)
    {
        ret = quec_uart1_open_cts_interrupt();
        if (QUEC_SUCCESS == ret)
        {
            quec_ifc_value_effect(QUEC_UART1_CHANNEL, TRUE);
        }
        else
        {
            uart_log("open cts interrupt fail");
            return ret;
        }
    }
    else
    {
        quec_uart1_close_cts_interrupt();
        quec_ifc_value_effect(QUEC_UART1_CHANNEL, FALSE);
    }
#endif
#if 0 // modify by wayne 2020.08.28 for reslove at+ifc;&w not save bug.
    ret = quectel_current_config_value_set(AT_IFC_RTS,g_uart_temp_ifc_value.rts_control);
    if(ret != utlSUCCESS)
    {
        uart_log("set rts value fail"); 
        return ret;
    }
    ret = quectel_current_config_value_set(AT_IFC_CTS,g_uart_temp_ifc_value.cts_control);
    if(ret != utlSUCCESS)
    {
        uart_log("set cts value fail"); 
        return ret;
    }
#endif
    memcpy(&g_uart_ifc_value, &g_uart_temp_ifc_value, sizeof(quec_ifc_value_s));
    uart_log("msg_process end");

    return ret;
}

/*�򿪴���1cts�ж�*/
QuecOSStatus quec_uart1_open_cts_interrupt(void)
{
    QuecOSStatus ret = kGeneralErr;
    GPIO_PinConfiguration *pconfig = NULL;
    quec_pin_level_value_e get_level = QUEC_PIN_LEVEL_LOW;
    unsigned int pin_status = 0;
    uint8 i = 0;

    for (i = 0; i < sizeof(uart_gpio_init_array) / sizeof(quec_pin_config_s); i++)
    {
        pconfig = &uart_gpio_init_array[i].config;

        if (pconfig->pinNumber == UART_CTS_PIN_NUM) // check
        {
            uart_log("find cts pin");
            if (1) // not init yet
            {
                ret = quec_uart_interrupt_pin_init(&uart_gpio_init_array[i]);
                if (QUEC_SUCCESS != ret)
                {
                    uart_log("pinNumber=%d interrupt init fail", pconfig->pinNumber);
                    return ret;
                }
            }
            else // already init,open it
            {
                uart_log("enable cts interrupt");
                GpioClearEdgeDetection(UART_CTS_PIN_NUM);
                GpioEnableEdgeDetection(UART_CTS_PIN_NUM, GPIO_TWO_EDGE);
            }

            pin_status = GpioGetLevel(UART_CTS_PIN_NUM); // Chaim 20190823 avoid not detect level when open cts interrupt and level is change at same time
            if (pin_status)                              // high  level
            {
                uart_log("enable cts interrupt,current level is high,not allow send");
                quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, FALSE); // not send
            }
            else
            {
                uart_log("enable cts interrupt,current level is low,allow send");
                quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, TRUE);
                quec_sio_wm_send_msg_to_dds(QUEC_UART1_CHANNEL, SIO_TX, 0); // Chaim 20190822 no wait
            }

            return QUEC_SUCCESS;
        }
    } // end for
    uart_log(" cts pin not found");
    return ret;
}
/*�رմ���1cts�ж�ʹ��*/
QuecOSStatus quec_uart1_close_cts_interrupt(void)
{
    GPIOEdgeDetectionDisable(UART_CTS_PIN_NUM);
    uart_log("disable cts interrupt");

    return QUEC_SUCCESS;
}

typedef enum
{
    RTS_NONE = -1,
    RTS_DEASSERT = 0,
    RTS_ASSERT = 1,
    RTS_AUTO = 2,
} UartRtsControlType;

#define uart_reg_read(reg) *(volatile unsigned int *)(reg)
#define uart_reg_write(reg, val) *(volatile unsigned int *)(reg) = (val);
#define uart_reg_bit_set(reg, val) *(volatile unsigned int *)(reg) |= (val);
#define uart_reg_bit_clr(reg, val) *(volatile unsigned int *)(reg) &= ~(val);

static int cts_hardware_lisr_flag = 0; // this flag is the function to make sure the cts is ok or not

OS_HISR UartModemHISRRef = NULL;
static OSATimerRef uart1_dds_start_ref = NULL;
// static int quec_ctrl_flower_mode=0;

/*��ȡ����״̬*/
QuecOSStatus quec_get_ctrl_flower_mode(int *mode)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    *mode = cts_hardware_lisr_flag;
    return QUEC_SUCCESS;
}

/*��������״̬*/
QuecOSStatus quec_set_ctrl_flower_mode(int mode)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    cts_hardware_lisr_flag = mode;
    return QUEC_SUCCESS;
}

/*����cts�жϲ����󣬾����ϲ��������������������ڷ�,�˴���ʱ����Ϊ����λ��*/
QuecOSStatus quec_uart1_dds_start_timer_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    if (NULL == uart1_dds_start_ref)
    {
        ret = quec_rtos_timer_create(&uart1_dds_start_ref);
        if (ret != OS_SUCCESS)
        {
            uart_log("uart1 dds start timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*����cts�жϲ����󣬾����ϲ��������������������ڷ�*/
static QuecOSStatus quec_uart1_dds_start_timer_handler(uint32 argc)
{
    return quec_sio_wm_send_msg_to_dds(QUEC_UART1_CHANNEL, SIO_TX, 0);
}

/*����cts�жϲ����󣬾����ϲ��������������������ڷ�*/
QuecOSStatus quec_uart1_dds_start_timer_start(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_timer_status_t timerStatus = {0};
    uart_log("uart1 flowctrl ref=%p", uart1_dds_start_ref);
    if (NULL != uart1_dds_start_ref)
    {
        quec_rtos_timer_get_status(uart1_dds_start_ref, &timerStatus);
        if (QUEC_TMR_STA_ENABLED == timerStatus.status)
        {
            return QUEC_SUCCESS;
        }
        ret = quec_rtos_timer_start(uart1_dds_start_ref,
                                    5,
                                    0,
                                    quec_uart1_dds_start_timer_handler,
                                    0);

        if (ret != OS_SUCCESS)
        {
            uart_log("start timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

/*�ж��м��cts�ĵ�ƽ״̬*/
void UartModemStatusLISRCallback(void)
{
    UINT32 reg, count = 0;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];
    HW_UART_READ_MSR(address, reg); // read cts level from MSR register.
    if (reg & 0x10)                 // bit4,CTS level,0:high;1:low  //bit0:Delta CTS
    {
        cts_hardware_lisr_flag = 0;
        quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, TRUE);
        interrupt_log("rts level is low");
    }
    else
    {
        cts_hardware_lisr_flag = 1;
        quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, FALSE); // not send
        interrupt_log("rts level is high");
    }
}
/*cts�ж�*/
void UartModemStatusLISR(void)
{
    /* Activate HISR*/
    UartModemStatusLISRCallback();
    ASSERT(OS_Activate_HISR(&UartModemHISRRef) == OS_SUCCESS);
}
/*dds task���������cts״̬*/
void quec_get_uart_msr_register_state_allow(void)
{
    UINT32 reg;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];
    HW_UART_READ_MSR(address, reg); // read cts level from MSR register.
    if (reg & 0X10)
    {
        quec_debug_print_uart("warning: interrupt check");
        CPUartLogPrintf("warning: interrupt fail");
        ASSERT(OS_Activate_HISR(&UartModemHISRRef) == OS_SUCCESS);
        return TRUE;
    }
}
/*���cts״̬���Ϊ���򣬼���dds���ⷢ����*/
void UartModemStatusHISR(void)
{
    UINT32 reg, count;
    OSA_STATUS osa_status;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];

    HW_UART_READ_MSR(address, reg); // read cts level from MSR register.
    if (reg & 0X10)                 // bit4,CTS level,0:high;1:low  //bit0:Delta CTS
    {
        quec_set_ctrl_flower_mode(FALSE);
        quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, TRUE);
        interrupt_log("rts level is low");
        quec_sio_wm_send_msg_to_dds_check((int *)&count);
        if (!count)
        {
            quec_sio_wm_send_msg_to_dds(QUEC_UART1_CHANNEL, SIO_TX, 0);
        }
        else
        {
            quec_uart1_dds_start_timer_start();
        }
    }
    else
    {
        interrupt_log("rts level is high");
        quec_set_ctrl_flower_mode(TRUE);
        quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, FALSE); // not send
    }
}

/*ctsӲ����ʼ��*/
QuecOSStatus quec_cts_hardware_init(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UINT32 cpsr;
    quec_ioctl_param ioctl_param;
    ioctl_param.pin_level = QUEC_PIN_LEVEL_LOW;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];
    status = quec_set_gpio_mfprReg(UART_CTS_PIN_NUM, (QUEC_AF1_C | QUEC_PULL_DN_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C));
    quec_uart_set_pin_level(UART1_RTS_PIN_NUM, &ioctl_param);

    quec_uart1_dds_start_timer_init();
    cpsr = disableInterrupts();
    HW_UART_WRITE_MCR(address, (MCR_AFE | MCR_ENABLE_INTS)); // enable cts

    if (!UartModemHISRRef)
    {
        OS_Create_HISR(&UartModemHISRRef, "uartmodem", UartModemStatusHISR, 2);
    }

    /* Unbind the handler for the Modem interrupt*/
    UARTISRUnbind(UART_PORT_STUART, UART_NotifyModemInterrupt);

    /* Bind the handler for the Modem interrupt*/
    if (UARTISRBind(UART_PORT_STUART, UART_NotifyModemInterrupt, UartModemStatusLISR) != UART_RC_OK)
    {
        CPUartLogPrintf("UART bind modem int ISR failed");
    }
    /* Enable the RX data available interrupt*/
    UARTInterruptControl(UART_PORT_STUART, IER_MODEM_STATUS, TRUE);
    restoreInterrupts(cpsr);
    return status;
}
/*cts rts Ӳ����ʼ��*/
QuecOSStatus quec_cts_rts_hardware_init(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UINT32 cpsr;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];
    status = quec_set_gpio_mfprReg(UART1_RTS_PIN_NUM, (QUEC_AF1_C | QUEC_PULL_DN_C | QUEC_DRV_SLOW_C | QUEC_RESERVED_C));
    quec_set_gpio_mfprReg(UART_CTS_PIN_NUM, (QUEC_AF1_C | QUEC_PULL_DN_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C));
    quec_uart1_dds_start_timer_init();
    cpsr = disableInterrupts();
    HW_UART_WRITE_MCR(address, (MCR_AFE | MCR_FORCE_RTS | MCR_ENABLE_INTS));
    //	HW_UART_WRITE_MCR(address,(MCR_AFE|MCR_ENABLE_INTS)); //enable cts

    if (!UartModemHISRRef)
    {
        OS_Create_HISR(&UartModemHISRRef, "uartmodem", UartModemStatusHISR, 2);
    }

    /* Unbind the handler for the Modem interrupt*/
    UARTISRUnbind(UART_PORT_STUART, UART_NotifyModemInterrupt);

    /* Bind the handler for the Modem interrupt*/
    if (UARTISRBind(UART_PORT_STUART, UART_NotifyModemInterrupt, UartModemStatusLISR) != UART_RC_OK)
    {
        CPUartLogPrintf("UART bind modem int ISR failed");
    }

    /* Enable the RX data available interrupt*/
    UARTInterruptControl(UART_PORT_STUART, IER_MODEM_STATUS, TRUE);
    restoreInterrupts(cpsr);
    UartModemStatusLISRCallback();
    return status;
}

/*�ر�ctsӲ��ʹ��*/
QuecOSStatus quec_cts_hardwareDisable(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UINT32 cpsr;
    UINT32 address = _UARTHwAddresses[UART_PORT_STUART];
//	hardware_cts_rts_flag=0;
#if QUEC_HALF_HARDWARE_FLOWERCTRL
    UINT32 reg = 0;
#endif

    cpsr = disableInterrupts();
    HW_UART_WRITE_MCR(address, (MCR_ENABLE_INTS));

    UARTISRUnbind(UART_PORT_STUART, UART_NotifyModemInterrupt);
    UARTInterruptControl(UART_PORT_STUART, IER_MODEM_STATUS, FALSE);
#if QUEC_HALF_HARDWARE_FLOWERCTRL
    HW_UART_READ_MSR(address, reg);
#endif
    restoreInterrupts(cpsr);
    quec_set_gpio_mfprReg(UART_CTS_PIN_NUM, (QUEC_AF0_C | QUEC_PULL_DN_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C));
    quec_set_gpio_mfprReg(UART1_RTS_PIN_NUM, (QUEC_AF0_C | QUEC_PULL_DN_C | QUEC_DRV_FAST_C | QUEC_RESERVED_C));
    cts_hardware_lisr_flag = 0;
    quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, TRUE);
    quec_sio_wm_send_msg_to_dds(QUEC_UART1_CHANNEL, SIO_TX, 0);
    return status;
}

/*��rts ctsӲ��ʹ��*/
void quec_uart_cts_rts_pin_init(quec_ifc_value_s *ifc_value)
{
    QuecOSStatus status = QUEC_SUCCESS;
    GPIO_PinConfiguration *pconfig = NULL;
    uint8 i = 0;
    if ((QUEC_AT_IFC_CMD_VAL_SOF == ifc_value->cts_control) && (QUEC_AT_IFC_CMD_VAL_SOF == ifc_value->rts_control))
    {
        for (i = 0; i < sizeof(uart_gpio_init_array) / sizeof(quec_pin_config_s); i++)
        {
            pconfig = &uart_gpio_init_array[i].config;

            if (pconfig->pinNumber == UART_CTS_PIN_NUM) // check if
            {

                status = quec_set_gpio_mfprReg(UART_CTS_PIN_NUM, uart_gpio_init_array[i].mfprReg_data);
                if (status != QUEC_SUCCESS)
                {
                    uart_log("gpio_num=%d,gpio set mfpreg fail", UART_CTS_PIN_NUM);
                    continue;
                }
                /*				status=quec_uart_interrupt_pin_init(&uart_gpio_init_array[i]);
                                if(QUEC_SUCCESS != status)
                                {
                                    quec_debug_print_uart("pinNumber=%d interrupt init fail", pconfig->pinNumber);
                                    continue;
                                }*/
            }
            if (pconfig->pinNumber == UART1_RTS_PIN_NUM) // check if
            {
                status = quec_gpio_init(&uart_gpio_init_array[i]);
                if (QUEC_SUCCESS != status)
                {
                    quec_debug_print_uart("pinNumber=%d output init fail", pconfig->pinNumber);
                    continue;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < sizeof(uart_gpio_init_array) / sizeof(quec_pin_config_s); i++)
        {
            if ((pconfig->pinNumber == UART_CTS_PIN_NUM) || (pconfig->pinNumber == UART1_RTS_PIN_NUM))
            {
                status = quec_gpio_init(&uart_gpio_init_array[i]);
                if (QUEC_SUCCESS != status)
                {
                    quec_debug_print_uart("pinNumber=%d output init fail", pconfig->pinNumber);
                    continue;
                }
            }
        }
    }
}
volatile static bool quec_uart_hardware_rts_flag = 0;
void quec_set_uart_hardware_rts_flag_value(bool status)
{
    interrupt_log("egan hardware_rts_flag set = %d", status);
    quec_uart_hardware_rts_flag = status;
}

bool quec_get_uart_hardware_rts_flag_value(void)
{
    //	interrupt_log("egan hardware_rts_flag get = %d",quec_uart_hardware_rts_flag);
    bool flag = quec_uart_hardware_rts_flag;
    return flag;
}

QuecOSStatus quec_uart_rts_effect_hardware(GPIO_PinNumbers set_pin_number, quec_ioctl_param *param)
{
    QuecOSStatus status = QUEC_SUCCESS;
    UART_ReturnCode ret = UART_RC_OK;
    bool event = param->pin_level;
    if (UART1_RTS_PIN_NUM != set_pin_number)
    {
        status = kGeneralErr;
        goto exit;
    }

    if (quec_get_uart_hardware_rts_flag_value() == event)
    {
        interrupt_log("egan new status is the same as before: %d", event);
        goto exit;
    }
    quec_set_uart_hardware_rts_flag_value(event);
    if (!event)
    {
        UARTInterruptControl(UART_PORT_STUART, IER_TIME_OUT, TRUE);
        UARTInterruptControl(UART_PORT_STUART, IER_RCV_DATA_AVAILABLE, TRUE);
        interrupt_log("egan recv data %d", ret);
    }

exit:
    return status;
}

#endif /* QUEC_UART1_HARDWARE_FLOWERCTRL */
#endif
static void quec_uart_pin_init(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    GPIO_PinConfiguration *pconfig = NULL;
    quec_ifc_value_s ifc_value = {0, 0};
    uint8 i = 0;

    for (i = 0; i < sizeof(uart_gpio_init_array) / sizeof(quec_pin_config_s); i++)
    {
        pconfig = &uart_gpio_init_array[i].config;
#ifdef QUEC_HALF_HARDWARE_FLOWERCTRL

        if (pconfig->pinNumber == UART_CTS_PIN_NUM) // check if
        {
            status = quec_set_gpio_mfprReg(UART_CTS_PIN_NUM, uart_gpio_init_array[i].mfprReg_data);
            if (status != QUEC_SUCCESS)
            {
                uart_log("gpio_num=%d,gpio set mfpreg fail", UART_CTS_PIN_NUM);
                continue;
            }
            status = quec_get_ifc_value(QUEC_UART1_CHANNEL, &ifc_value);
            if ((status != QUEC_SUCCESS) || (QUEC_AT_IFC_CMD_VAL_MIN == ifc_value.cts_control)) // not need init if get ifc_value error or zero
            {
                quec_debug_print_uart("cts value=%d not need init", ifc_value.cts_control);
                continue;
            }
        }
#endif
        // input pin
        if (pconfig->direction == GPIO_IN_PIN)
        {
#ifdef QUEC_HALF_HARDWARE_FLOWERCTRL
            if (pconfig->pinNumber == UART_CTS_PIN_NUM)
            {
                continue;
            }
#endif
            status = quec_uart_interrupt_pin_init(&uart_gpio_init_array[i]);
            if (QUEC_SUCCESS != status)
            {
                quec_debug_print_uart("pinNumber=%d interrupt init fail", pconfig->pinNumber);
                continue;
            }
        }
        else //(pconfig->direction == GPIO_OUT_PIN)  //output init
        {
            if (pconfig->pinNumber == UART1_RI_PIN_NUM)
            {
                if (urc_context.config.ri.ri_gpio_level == RI_OUT_LEVEL_HIGH)
                {
                    pconfig->initialValue = GPIO_INITIAL_VALUE_HIGH;
                    uart_gpio_init_array[i].mfprReg_data &= ~(0x7 << 13);
                    uart_gpio_init_array[i].mfprReg_data |= QUEC_PULL_UP_C;
                }
                else
                {
                    pconfig->initialValue = GPIO_INITIAL_VALUE_LOW;
                    uart_gpio_init_array[i].mfprReg_data &= ~(0x7 << 13);
                    uart_gpio_init_array[i].mfprReg_data |= QUEC_PULL_DN_C;
                }
            }

            status = quec_gpio_init(&uart_gpio_init_array[i]);
            if (QUEC_SUCCESS != status)
            {
                quec_debug_print_uart("pinNumber=%d output init fail", pconfig->pinNumber);
                continue;
            }
        }

    } // end for

    return status;
}

void quec_uart1_dtr_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;
    quec_msg_io_conf_value_s dtr_s = {0};
    quec_sleep_msg_s sleep_msg = {0};
    // uart_log("chaim_test dtr int");
    ret = quec_gpio_debounce_timer_handler(&dtr_debounce);
    // quec_debug_print_uart("dtr debounce timer,ret=%d",ret);
    if (QUEC_SUCCESS == ret)
    {
        dtr_s.atp_index = QUEC_UART1_CHANNEL;
        dtr_s.level = dtr_debounce.last_level;

        quec_send_dtr_change_msg(&dtr_s);

#ifdef QUEC_POWER_MANAGER_ENABLE

        sleep_msg.sleep_bit = QUEC_SLEEP_DTR_BIT;
        if (quec_dtr_det_level != dtr_debounce.last_level)
        {
            sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_ALLOW_SLEEP;
        }
        else
        {
            sleep_msg.value.sleep_flag = QUEC_CUSTOMER_FLAG_NOT_SLEEP;
            quec_sleep_not_allown_sleep(); // Chaim 20190726 for msg tranfer long time ,cp will sleep possibility
        }
        ret = quec_send_sleep_msg(&sleep_msg);

#if QUEC_SLEEP_DTR_HIGH_FREQ_FEATURE
        if (ret == kGeneralErr)
        {
            // customer use high frequecy dtr pull up down with every at command, sleep msg queue maybe is full;
            // cache last sleep msg which is send err, sleep task will check again.
            g_dtr_high_freq.dtr_msg_err = TRUE;
            g_dtr_high_freq.last_dtr_msg.sleep_bit = sleep_msg.sleep_bit;
            g_dtr_high_freq.last_dtr_msg.value.sleep_flag = sleep_msg.value.sleep_flag;
        }
        else
        {
            g_dtr_high_freq.dtr_msg_err = FALSE;
        }
        g_dtr_high_freq.hisr_trig_flag = FALSE;
#endif

#endif
    }
}

#if QUEC_SLEEP_DTR_HIGH_FREQ_FEATURE
// return ture is has err msg need send again.
BOOL quec_dtr_high_freq_check_send_err_msg(void)
{
    BOOL ret = FALSE;
    if (g_dtr_high_freq.dtr_msg_err == TRUE)
    {
        // retry send last dtr err msg
        // des_print("[DTR] re send last msg err again!");
        quec_send_sleep_msg(&g_dtr_high_freq.last_dtr_msg);
        g_dtr_high_freq.dtr_msg_err = FALSE;
        ret = TRUE;
    }
    return ret;
}

// return ture is allow set sleep flag.
BOOL quec_dtr_high_freq_check_in_allow_sleep(void)
{
    BOOL ret = TRUE;
    uint8_t queue_cnt = 0;

    if (kNoErr == quec_rtos_queue_get_cnt(g_quec_sleep_queue, &queue_cnt))
    {
        // des_print("[DTR]GETQ:%d", queue_cnt);
        if (queue_cnt == 0)
        {
            /* dtr msg send err with queue full need double check last debunce status */
            if (quec_dtr_high_freq_check_send_err_msg() == TRUE)
            {
                if (g_dtr_high_freq.last_dtr_msg.value.sleep_flag == QUEC_CUSTOMER_FLAG_NOT_SLEEP)
                {
                    // des_print("[DTR] not allow:last msg send err status!");
                    ret = FALSE;
                }
            }
        }
        else if (queue_cnt >= 1)
        { // MSG pengding need double check DTR PIN state;
            if (GpioGetLevel(UART_DTR_PIN_NUM) == quec_dtr_det_level)
            {
                // des_print("[DTR] not allow sleep: pin level:%d!", GpioGetLevel(UART_DTR_PIN_NUM));
                ret = FALSE;
            }
        }
    }
    // maybe dtr pin is in trigger, in will sleep need check immediately.
    if (g_dtr_high_freq.hisr_trig_flag == TRUE)
    {
        if (GpioGetLevel(UART_DTR_PIN_NUM) == quec_dtr_det_level)
        {
            // des_print("[DTR] not allow sleep: dtr in hisr cur level is:%d!",GpioGetLevel(UART_DTR_PIN_NUM));
            ret = FALSE;
        }
    }

    return ret;
}
//
BOOL quec_dtr_high_freq_check_in_not_allow_sleep(void)
{
    BOOL ret = TRUE;
    uint8_t queue_cnt = 0;
    if (kNoErr == quec_rtos_queue_get_cnt(g_quec_sleep_queue, &queue_cnt))
    {
        // des_print("[DTR]GETQ2:%d", queue_cnt);
        if (queue_cnt == 0)
        {
            quec_dtr_high_freq_check_send_err_msg();
        }
    }
    return ret;
}
#endif
#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL

void quec_uart1_cts_timer_handler(void)
{
    QuecOSStatus ret = kGeneralErr;
    ret = quec_gpio_debounce_timer_handler(&cts_debounce);
    // quec_debug_print_uart("cts debounce timer,ret=%d",ret);
    if (QUEC_SUCCESS == ret)
    {
        if (cts_debounce.last_level)
        {
            // QUEC_PIN_LEVEL_HIGH;
            quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, FALSE); // not send
        }
        else
        {
            // QUEC_PIN_LEVEL_LOW;
            quec_sio_flowctl_set_send_status(QUEC_UART1_CHANNEL, TRUE);
            quec_sio_wm_send_msg_to_dds(QUEC_UART1_CHANNEL, SIO_TX, 0); // Chaim 20190822 no wait
        }
    }
}

void quec_uart1_cts_hisr(void)
{

    // GPIOInterruptClear(UART_CTS_PIN_NUM);
    // GPIOEdgeDetectionDisable(UART_CTS_PIN_NUM);
    interrupt_log("cts hisr");
    quec_gpio_interrupt_debounce_handler(&cts_debounce);
}
#endif

void quec_uart1_dtr_hisr(void)
{

    // GPIOInterruptClear(UART_DTR_PIN_NUM);
    // GPIOEdgeDetectionDisable(UART_DTR_PIN_NUM);
    uart_log("quec_dtr");
    interrupt_log("dtr hisr");
    g_dtr_high_freq.hisr_trig_flag = TRUE;
    quec_gpio_interrupt_debounce_handler(&dtr_debounce);
}

static QuecOSStatus quec_uart_crit_section_init(void)
{
    QuecOSStatus err = kNoErr;

    err = quec_rtos_mutex_create(&uart1_send_mutex);
    if (err != kNoErr)
    {
        uart_log("uart1_send_mutex creat error");
    }

    return err;
}

static QuecOSStatus quec_uart_enter_send_crit_section(void)
{
    if (uart1_send_mutex == NULL)
    {
        uart_log("uart1 enter uart1_send_mutex is NULL");
        return kGeneralErr;
    }

    return quec_rtos_mutex_lock(uart1_send_mutex, QUEC_WAIT_FOREVER);
}

static QuecOSStatus quec_uart_leave_send_crit_section(void)
{
    if (uart1_send_mutex == NULL)
    {
        uart_log("uart1 leave uart1_send_mutex is NULL");
        return kGeneralErr;
    }

    return quec_rtos_mutex_unlock(uart1_send_mutex);
}

// this function  will be block
QuecOSStatus quec_uart1_send(TelAtParserID atp_index, uint8 *data, uint32 len)
{
    QuecOSStatus status = OS_SUCCESS;
    uint16 send_len = 0;
    uint16 unsend_len = (UINT16)len;
    uint32 i = 0;

    if ((data == NULL) || (len <= 0))
    {
        uart_log("uart atp_index=%d data pointer null", atp_index);
        return kGeneralErr;
    }

    // Fitz.xu 20210421: Add for FAE-10441
#if defined(__QUEC_OEM_VER_LT__)
    extern void quec_LT_data_transmit(void);
    quec_LT_data_transmit();
#endif

    /*
      if(atp_index != TEL_AT_CMD_ATP_7)
      {
          if((atp_index < TEL_AT_CMD_ATP_CMUX_0)  || (atp_index > TEL_AT_CMD_ATP_CMUX_5))
          {
              uart_log("uart atp_index=%d error", atp_index);
              return kGeneralErr;
          }
      }
      */
    /*
        if(TRUE == uart_data_show.tx_data_flag)
        {
            uart_log("atp7 =%d send datalen=%d",atp_index,len);
            for(i=0;i<len;i++)
            {
                uart_log("atp7 uart_send[%d] =0x%x",i,data[i]);
            }
        }
    */

    /*   uint8 port_num = UART_PORT_FFUART;
       if((port_num != UART_PORT_FFUART) && (port_num != UART_PORT_STUART))
       {
           uart_log("port_num=%d error", port_num);
           return kGeneralErr;
       }

       if(len <= 0)
       {
           uart_log("port_num=%d data is null pointer or len=%d error", port_num,len);
           return kGeneralErr;
       }
       */

    status = quec_uart_enter_send_crit_section();
    if (status != OS_SUCCESS)
    {
        uart_log("atp_index=%d,enter critical zone fail", atp_index);
        return status;
    }

#ifdef QUEC_SLEEP_ENABLE
    quec_sleep_com_port_recordtick(QUEC_SLEEP_MAJORUART_TX_BIT);
#if 0 // Chaim 20200907  quec_sleep_com_port_recordtick() function  already send active sleep task
   if(TRUE == quec_is_sleepMode())
   {
    	 /*isaac-20200723 ��D��y?Y��?��?��???D?sleep task,�䨮????D?led task,��1net_sta��?����??*/
    	quec_sleep_active_sleep_task(QUEC_SLEEP_UART_DATA_TRANSMITING_ACTIVE);
   }
#endif
#endif

    while (send_len < len)
    {
        UARTFIFOWrite((UART_Port)UART_PORT_STUART, (uint8 *)(data + send_len), &unsend_len);
        send_len = len - unsend_len;
    }

    status = quec_uart_leave_send_crit_section();
    if (status != OS_SUCCESS)
    {
        uart_log("atp_index=%d,enter critical zone fail", atp_index);
    }

    return status;
}

#ifdef QUEC_HALF_HARDWARE_FLOWERCTRL // added on 20181101
QuecOSStatus quec_uart1_send_ex(TelAtParserID atp_index, uint8 *data, uint32 *datelen)
{
    QuecOSStatus status = OS_SUCCESS;
    uint16 send_len = 0;
    uint32 len = *datelen;
    uint16 unsend_len = (UINT16)len;
    uint32 i = 0, ret = UART_RC_OK;

    if ((data == NULL) || (len <= 0))
    {
        uart_log("uart atp_index=%d data pointer null", atp_index);
        return kGeneralErr;
    }

    // Fitz.xu 20210421: Add for FAE-10441
#if defined(__QUEC_OEM_VER_LT__)
    extern void quec_LT_data_transmit(void);
    quec_LT_data_transmit();
#endif

    /*
      if(atp_index != TEL_AT_CMD_ATP_7)
      {
          if((atp_index < TEL_AT_CMD_ATP_CMUX_0)  || (atp_index > TEL_AT_CMD_ATP_CMUX_5))
          {
              uart_log("uart atp_index=%d error", atp_index);
              return kGeneralErr;
          }
      }
      */

    if (TRUE == uart_data_show.tx_data_flag)
    {
        uart_log("atp7 =%d send datalen=%d", atp_index, len);
        for (i = 0; i < len; i++)
        {
            uart_log("atp7 uart_send[%d] =0x%x", i, data[i]);
        }
    }

    /*   uint8 port_num = UART_PORT_FFUART;
       if((port_num != UART_PORT_FFUART) && (port_num != UART_PORT_STUART))
       {
           uart_log("port_num=%d error", port_num);
           return kGeneralErr;
       }

       if(len <= 0)
       {
           uart_log("port_num=%d data is null pointer or len=%d error", port_num,len);
           return kGeneralErr;
       }
       */

    status = quec_uart_enter_send_crit_section();
    if (status != OS_SUCCESS)
    {
        uart_log("atp_index=%d,enter critical zone fail", atp_index);
        return status;
    }

#ifdef QUEC_SLEEP_ENABLE
    quec_sleep_com_port_recordtick(QUEC_SLEEP_MAJORUART_TX_BIT);
#endif

    while (send_len < len)
    {
        ret = UARTFIFOWrite((UART_Port)UART_PORT_STUART, (uint8 *)(data + send_len), &unsend_len);
        send_len = len - unsend_len;
        //	  if(ret==UART_CTS_ENABLE_ERR)
        if (cts_hardware_lisr_flag)
        {
            *datelen = unsend_len;
            quec_log("egan_flowctl_en len=%d", unsend_len);
            status = quec_uart_leave_send_crit_section();
            if (status != OS_SUCCESS)
            {
                uart_log("atp_index=%d,enter critical zone fail", atp_index);
            }
            return OS_FAIL;
        }
    }
    *datelen = NULL;
    status = quec_uart_leave_send_crit_section();
    if (status != OS_SUCCESS)
    {
        uart_log("atp_index=%d,enter critical zone fail", atp_index);
        return status;
    }

    return OS_SUCCESS;
}
#endif

/*isaac 20210113 �´�½ʹ�ñ�׼�汾����ȫ�ֱ���ֻ���´�½�ͻ�ʹ�ã�AT+CBAUD,Ҫ��at&w�����沨���ʣ����Էſ����*/
extern uint8 g_quec_cbaud_excute;

QuecOSStatus quec_uart_selfadatpt_baudrate_set_back(TelAtParserID atp_index)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UART_BaudRates getbaudrate = UART_MAX_NUM_BAUD;
    UART_Port portNumber = NUMBER_OF_PORTS;
    unsigned int selfadatpt_baud = 0;
    quec_ipr_set_s *pipr_set = NULL;
    ret = quec_uart_get_portnum(atp_index, &portNumber);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get portnum fail", atp_index);
        return kGeneralErr;
    }

    quec_uart_baud_selfadatpt_disable(UART_PORT_STUART, &selfadatpt_baud);

    ret = quec_uart_get_current_baudrate(atp_index, &getbaudrate);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get baudrate fail", atp_index);
        return kGeneralErr;
    }
    uart_log("atp_index=%d,getbaudrate=%d", atp_index, getbaudrate);

    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get ipr_pointer fail", atp_index);
        return ret;
    }

    if (getbaudrate == selfadatpt_baud)
    {
        uart_log("atp_index=%d get_baudrate=%d same with setbaudrate,not need set", atp_index, getbaudrate);
        return QUEC_SUCCESS;
    }

    pipr_set->current_baudrate = selfadatpt_baud;

    switch (pipr_set->baud_info.baud_src)
    {
    case QUEC_BAUD_FROM_FAT:
        ret = quectel_nv_fat_write(pipr_set->baud_info.info.filename, &selfadatpt_baud, sizeof(selfadatpt_baud));
        if (QUEC_SUCCESS != ret)
        {
            uart_log("atp_index=%dsave baudrate=%d fail", atp_index, selfadatpt_baud);
        }
        break;

    case QUEC_BAUD_CURRENT_CONFIG:
        /*isaac 20210113 �´�½ʹ�ñ�׼�汾����ȫ�ֱ���ֻ���´�½�ͻ�ʹ�ã�AT+CBAUD,Ҫ��at&w�����沨���ʣ����Էſ����*/
        if (g_quec_cbaud_excute)
        {
            g_quec_cbaud_excute = FALSE;
            uart_log("atp_index=%d cbaud not save", atp_index);
            break;
        }

        ret = quectel_current_config_value_set(AT_IPR, pipr_set->current_baudrate);
        if (QUEC_SUCCESS != ret)
        {
            uart_log("atp_index=%d save baudrate=%d fail", atp_index, selfadatpt_baud);
        }
        break;

    default:
        ret = kGeneralErr;
        uart_log("baud_src=%d is invalid", pipr_set->baud_info.baud_src);
        break;
    }

    return ret;
}

QuecOSStatus quec_uart_reset_baudrate(TelAtParserID atp_index, UART_BaudRates baudrate)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UART_BaudRates getbaudrate = UART_MAX_NUM_BAUD;
    UART_Port portNumber = NUMBER_OF_PORTS;
    quec_ipr_set_s *pipr_set = NULL;

    ret = quec_uart_get_portnum(atp_index, &portNumber);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get portnum fail", atp_index);
        return kGeneralErr;
    }
    uart_log("chaim1213_test,portNumber=%d", portNumber);

    ret = quec_uart_get_current_baudrate(atp_index, &getbaudrate);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get baudrate fail", atp_index);
        return kGeneralErr;
    }
    uart_log("atp_index=%d,getbaudrate=%d", atp_index, getbaudrate);

    ret = quec_get_uart_ipr_pointer(atp_index, &pipr_set);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d get ipr_pointer fail", atp_index);
        return ret;
    }

    if (getbaudrate == baudrate)
    {
        uart_log("atp_index=%d get_baudrate=%d same with setbaudrate,not need set", atp_index, getbaudrate);
        return QUEC_SUCCESS;
    }

    ret = quec_uart_set_baudrate(portNumber, baudrate);
    if (QUEC_SUCCESS != ret)
    {
        _UARTPorts[portNumber].config.baudRate = pipr_set->current_baudrate; // set fail and resume baudrate

        uart_log("ipr can not set baudrate %d,resume baudrate =%d", baudrate, pipr_set->current_baudrate);
        return ret;
    }

    pipr_set->current_baudrate = _UARTPorts[portNumber].config.baudRate; // update baudrate

    switch (pipr_set->baud_info.baud_src)
    {
    case QUEC_BAUD_FROM_FAT:
        ret = quectel_nv_fat_write(pipr_set->baud_info.info.filename, &baudrate, sizeof(baudrate));
        if (QUEC_SUCCESS != ret)
        {
            uart_log("atp_index=%dsave baudrate=%d fail", atp_index, baudrate);
        }
        break;

    case QUEC_BAUD_CURRENT_CONFIG:
        /*isaac 20210113 �´�½ʹ�ñ�׼�汾����ȫ�ֱ���ֻ���´�½�ͻ�ʹ�ã�AT+CBAUD,Ҫ��at&w�����沨���ʣ����Էſ����*/
        if (g_quec_cbaud_excute)
        {
            g_quec_cbaud_excute = FALSE;
            uart_log("atp_index=%d cbaud not save", atp_index);
            break;
        }

        ret = quectel_current_config_value_set(AT_IPR, pipr_set->current_baudrate);
        if (QUEC_SUCCESS != ret)
        {
            uart_log("atp_index=%d save baudrate=%d fail", atp_index, baudrate);
        }
        break;

    default:
        ret = kGeneralErr;
        uart_log("baud_src=%d is invalid", pipr_set->baud_info.baud_src);
        break;
    }

    return ret;
}

// read nv form fat
static void quec_uart_fat_read(void)
{
    QuecOSStatus status = QUEC_SUCCESS;
    uint32 baudrate = UART_MAX_NUM_BAUD;
    UART_Port portNumber = NUMBER_OF_PORTS;
    uint8 i = 0;
    /*
         //asr initread from nvm,if use auto flow control, clear it,we not use auto flow control
        if(Uart2_FlowControl_Cfg != 0)
        {
            UART_Clear_Auto_FlowControl(UART_PORT_FFUART);
            Uart2_FlowControl_Cfg = 0;
            UART2_FlowControl_SetSetting(0);
        }
    */
    status = quec_uart_set_poweron_baudrate(QUEC_UART1_CHANNEL);
    if (status != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d quec_uart_set_poweron_baudrate fail", QUEC_UART1_CHANNEL);
    }
}

QuecOSStatus quec_clear_pin_awake_flag(GPIO_PinNumbers pin_num)
{
    QuecOSStatus status = QUEC_SUCCESS;
    unsigned long mfprReg_data;
    if (pin_num > GPIO_MAX_AMOUNT_OF_PINS)
    {
        uart_log("pin_num=%d error", pin_num);
        return kParamErr;
    }

    status = quec_gpio_get_mfprReg(pin_num, &mfprReg_data);
    if (status != QUEC_SUCCESS)
    {
        uart_log("gpio_num=%d,gpio set mfpreg awake flag fail", pin_num);
        return status;
    }
    mfprReg_data &= ~(1 << QUEC_MFPR_REG_EDGE_CLEAR_SHIFT);
    status = quec_set_gpio_mfprReg(pin_num, mfprReg_data);
    if (status != QUEC_SUCCESS)
    {
        uart_log("gpio_num=%d,gpio set mfpreg awake flag fail", pin_num);
        return status;
    }

    return status;
}

QuecOSStatus quec_set_pin_awake_flag(GPIO_PinNumbers pin_num)
{
    QuecOSStatus status = QUEC_SUCCESS;
    unsigned long mfprReg_data;
    if (pin_num > GPIO_MAX_AMOUNT_OF_PINS)
    {
        uart_log("pin_num=%d error", pin_num);
        return kParamErr;
    }
    status = quec_gpio_get_mfprReg(pin_num, &mfprReg_data);
    if (status != QUEC_SUCCESS)
    {
        uart_log("gpio_num=%d,gpio set mfpreg awake flag fail", pin_num);
        return status;
    }
    mfprReg_data |= (1 << QUEC_MFPR_REG_EDGE_CLEAR_SHIFT);

    status = quec_set_gpio_mfprReg(pin_num, mfprReg_data);
    if (status != QUEC_SUCCESS)
    {
        uart_log("gpio_num=%d,gpio set mfpreg awake flag fail", pin_num);
        return status;
    }

    return status;
}

#ifdef QUEC_URC_RI_DCD_SUPPORT
extern quec_pin_config_s wake_ind_gpio_init_data;
#endif
#ifdef QUECTEL_PROJECT_EC800N_BSP
extern quec_gpio_func_t quec_gpio_func;
#endif
// register will add this function to  HW_IOCTL
QuecOSStatus quec_uart1_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param)
{
    QuecOSStatus status = QUEC_SUCCESS;
    quec_ifc_value_s ifc_value = {0, 0};
    // chaim_test
    if (atp_index != QUEC_UART1_CHANNEL)
    {
        uart_log("atp_index=%d error", atp_index);
        return kGeneralErr;
    }

    switch (cmd)
    {
    case IOCTL_WRITE_DCD_CMD:
#ifdef QUECTEL_PROJECT_EC800N_BSP
        if (quec_gpio_func == GPIO_FUNC_PA_CTL)
            uart_log("GPIO is used by PA,DCD CHANGED FAILED!");
        else
#endif
#ifdef QUEC_URC_RI_DCD_SUPPORT
            if (GlobalRiPin_Flag != QUEC_URC_RI_DCD)
#endif
            status = quec_uart_set_pin_level(UART1_DCD_PIN_NUM, param);
        break;

    case IOCTL_READ_DCD_CMD:
        status = quec_uart_get_pin_level(UART1_DCD_PIN_NUM, param);
        break;

    case IOCTL_WRITE_RI_CMD:
#ifdef QUEC_URC_RI_DCD_SUPPORT
        if (GlobalRiPin_Flag == QUEC_URC_RI_WAKEUP)
        {
            if (quec_set_gpio_level((GPIO_PinNumbers)wake_ind_gpio_init_data.config.pinNumber, *((quec_pin_level_value_e *)(param))) != kNoErr)
            {
                uart_log("wakeup pin set failed");
            }
        }
        else if (GlobalRiPin_Flag == QUEC_URC_RI_DCD)
        {
            status = quec_uart_set_pin_level(UART1_DCD_PIN_NUM, param);
        }
        else
#endif
        {
            status = quec_uart_set_pin_level(UART1_RI_PIN_NUM, param);
        }
        // status =quec_uart_set_pin_level(UART1_RI_PIN_NUM,param);
        break;

    case IOCTL_READ_RI_CMD:
        status = quec_uart_get_pin_level(UART1_RI_PIN_NUM, param);
        break;
#if QUEC_HALF_HARDWARE_FLOWERCTRL

    case IOCTL_WRITE_RTS_CMD:
        status = quec_get_ifc_value(atp_index, &ifc_value);
#if QUEC_HALF_HARDWARE_FLOWERCTRL
        if ((status == QUEC_SUCCESS) && (QUEC_AT_IFC_CMD_VAL_SOF == ifc_value.rts_control))
        {
            status = quec_uart_set_pin_level(UART1_RTS_PIN_NUM, param);
        }
        else if ((status == QUEC_SUCCESS) && (QUEC_AT_IFC_CMD_VAL_MAX == ifc_value.rts_control))
        {
            status = quec_uart_rts_effect_hardware(UART1_RTS_PIN_NUM, param);
        }
#else
        if ((status == QUEC_SUCCESS) && (QUEC_AT_IFC_CMD_VAL_MAX == ifc_value.rts_control))
        {
            status = quec_uart_set_pin_level(UART1_RTS_PIN_NUM, param);
        }
#endif
        else
        {
            uart_log("status=%d, rts value=%d not set success", status, ifc_value.rts_control);
        }
        break;

    case IOCTL_READ_CTS_CMD:
        status = quec_uart_get_pin_level(UART_CTS_PIN_NUM, param);
        break;

    case IOCTL_READ_RTS_CMD:
        status = quec_uart_get_pin_level(UART1_RTS_PIN_NUM, param);
        break;
#endif

    case IOCTL_READ_DTR_CMD:
        status = quec_uart_get_pin_level(UART_DTR_PIN_NUM, param);
        break;

    default:
        uart_log("no cmd=%d found", cmd);
        status = kGeneralErr;
        break;
    }

    return status;
}

// must return success,else watermark not effect and will be dump
// if asr uart init already,we just init dcd ri pin only
QuecOSStatus quec_uart_init(TelAtParserID atp_index)
{
    QuecOSStatus status = QUEC_SUCCESS;

    if (atp_index != QUEC_UART1_CHANNEL)
    {
        uart_log("atp_index=%d error", atp_index);
        return kGeneralErr;
    }
    status = quec_uart_crit_section_init();
    if (QUEC_SUCCESS != status)
    {
        uart_log("quec_uart_crit_section_init status=%d error", status);
    }

    // Chaim2018.12.6 uart open here avoid dump in system init enter at_cmd
    UARTOpen(UART_PORT_STUART);
    UART_Set_Rcv_Fifo_TriggerLevel(UART_PORT_STUART, UART_INT_TRIGGER_L32);

    quec_uart_fat_read();
/*open��Ŀ����dtr���û��Զ��壬�˴�������ʼ��ȥ��*/
#ifndef QUECTEL_OPEN_CPU
    quec_uart_pin_init();

#ifdef QUEC_UART1_HARDWARE_FLOWERCTRL
    quec_uart1_ifc_timer_init();
#endif
#endif
    status = quec_uart_ipr_timer_init(QUEC_UART1_CHANNEL);
    if (QUEC_SUCCESS != status)
    {
        uart_log("quec_uart_ipr_timer_init status=%d error", status);
    }
    return QUEC_SUCCESS;
}

#if 0
const quec_baudration_self_adaption_parameter_s uart_baudrate_match[] =
{
    {UART_BAUD_115200,  0x61},  //a
    {UART_BAUD_115200,  0x41},  //A
    {UART_BAUD_57600,   0x06},
    {UART_BAUD_38400,   0x1C},
    {UART_BAUD_19200,   0xE0},
    {UART_BAUD_14400,   0x80},
    {UART_BAUD_9600,    0x00}
};

void quec_uart1_baud_selfadatpt(UINT8 *buf)
{
    uint8 i = 0;
    uint8 char_parse=0;
    uint8 array_size =0;
    UART_BaudRates uart_match_baudrate =  UART_MAX_NUM_BAUD;
    //uart_log("char=0x%x,adaption=%d", *(uint8 *)buf, g_quec_baud_self_adaption); 
    if(g_quec_baud_self_adaption == QUEC_BAUD_SELF_ADAPTION_TRUE)    
    {
       char_parse = *(uint8 *)buf;
       array_size =sizeof(uart_baudrate_match)/sizeof(uart_baudrate_match[0]);
        for(i = 0; i < array_size; i++ )
        {
            if(char_parse == uart_baudrate_match[i].character_match)
            {
                uart_match_baudrate = uart_baudrate_match[i].baudrate;
                break;
            }
        }

        if(i== array_size)
        {
           uart_log("%s,line=%d,i=%d array_size=%d",__func__,__LINE__,i,array_size); 
           return ; 
        }
        else
        {
            uart_log("reset baudrate=%d",uart_match_baudrate); 
            quec_uart_reset_baudrate(QUEC_UART1_CHANNEL, uart_match_baudrate);
            g_quec_baud_self_adaption =  QUEC_BAUD_SELF_ADAPTION_FALSE;
        }
        
        return ; 
    }

    
   
}
#endif
#endif

static QuecOSStatus quec_conifg_uart_port(UART_Port portNumber, UARTConfiguration *config)
{
    QuecOSStatus status = QUEC_SUCCESS;

    QUEC_CHECK_UART_PORT_VALID(portNumber);

    if (config == NULL)
    {
        uart_log("config is null pointer");
        return kGeneralErr;
    }
    // UARTInitializePortAddress((UART_Port)UART_PORT_FFUART);
    /* Close UART port. */
    UARTClose((UART_Port)portNumber);

    /* Confige the INTC (interrupt controller) */
    UARTConfigINTC((UART_Port)portNumber);

    /* Confige the STUART port */
    UARTConfigure((UART_Port)portNumber, config);
    /* Open UART port. */
    UARTOpen((UART_Port)portNumber);
    uartState[portNumber] = TRUE;

    return QUEC_SUCCESS;
}

#ifdef QUEC_UART2_ENABLE

extern uart_mode_info UartModeInfo;

extern quec_uart2_mode_e g_uart2_mode;

// Chaim 20200226 obm storage fail,use nv storage to debug
#define QUEC_UART2_DEBUG_MODE "uart2_mode"
#ifdef QUEC_PRODUCTION_CFG_SUPPORT

void quec_read_uart2_debug_mode(void)
{
    QuecOSStatus ret = QUEC_CFG_CODE_NOERROR;
    quec_production_cfg_s uart2_mode_cfg = {NULL, QUEC_UART2_MODE_TO_DEBUG};
    ret = quec_production_current_cfg_get(&uart2_mode_cfg);
    if (QUEC_CFG_CODE_NOERROR != ret)
    {
        uart_log("read before save qdiagport=%d fail,ret=%d", g_uart2_mode, ret);
        return kGeneralErr;
    }
    g_uart2_mode = uart2_mode_cfg.quec_dualport_support;
    /*	uint8   uart2mode = QUEC_UART2_MODE_TO_DEBUG;

        ret = quectel_nv_fat_read(QUEC_UART2_DEBUG_MODE , &uart2mode, sizeof(uart2mode));
        if(QUEC_SUCCESS == ret)
        {
            uart_log("uart2 mode read fail");
        }
        g_uart2_mode =  uart2mode;
        */
    return;
}

void quec_storage_uart2_debug_mode(uint8 uart2mode)
{
    QuecOSStatus ret = QUEC_CFG_CODE_NOERROR;
    quec_production_cfg_s uart2_mode_cfg = {NULL, QUEC_UART2_MODE_TO_ATCMD};
    ret = quec_production_current_cfg_get(&uart2_mode_cfg);
    if (QUEC_CFG_CODE_NOERROR != ret)
    {
        uart_log("read before save qdiagport=%d fail,ret=%d", g_uart2_mode, ret);
        return kGeneralErr;
    }
    memcpy(&uart2_mode_cfg.quec_chk_bytes, QUEC_CFG_BYTE_STR, sizeof(QUEC_CFG_BYTE_STR));
    uart2_mode_cfg.quec_dualport_support = uart2mode;

    ret = quec_production_cfg_write(&uart2_mode_cfg);
    if (QUEC_CFG_CODE_NOERROR != ret)
    {
        uart_log("save qdiagport=%d fail,ret=%d", g_uart2_mode, ret);
        return kGeneralErr;
    }
    /*	ret = quectel_nv_fat_write(QUEC_UART2_DEBUG_MODE , &uart2mode, sizeof(uart2mode));
        if(QUEC_SUCCESS == ret)
        {
            uart_log("uart2 mode write fail");
        }*/
    return;
}
#endif
QuecOSStatus quec_uart2_urc_port_config(quec_uart2_mode_e value)
{
    QuecOSStatus ret = kGeneralErr;
    switch (value)
    {
    case QUEC_UART2_MODE_TO_DEBUG:
        ret = at_urc_port_config(TEL_AT_CMD_ATP_UART2, FALSE);
        break;

    case QUEC_UART2_MODE_TO_ATCMD:
        ret = at_urc_port_config(TEL_AT_CMD_ATP_UART2, TRUE);
        break;

    default:
        uart_log("urc port config value =%d is invalid", value);
        break;
    }
    return ret;
}

quec_uart2_mode_e quec_uart2_get_mode(void)
{
    return g_uart2_mode;
}

static QuecOSStatus quec_uart2_mode_to_debug_support(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UARTConfiguration uart_config;

    UART_Config_Type inter_type = UartModeInfo.Type[UART_PORT_FFUART];
    UartModeInfo.Type[UART_PORT_FFUART] = UART_INT_DISABLE;
    memcpy(&uart_config, &_UARTPorts[UART_PORT_FFUART].config, sizeof(UARTConfiguration));

    ret = quec_conifg_uart_port(UART_PORT_FFUART, &uart_config);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("minor uart int disable fail");
        UartModeInfo.Type[UART_PORT_FFUART] = inter_type; // set fail,resume  config
    }
    quec_rtos_task_sleep_ms(500);
    enable_uart_print();
    return ret;
}

static QuecOSStatus quec_uart2_mode_to_atcmd_support(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    UARTConfiguration uart_config;

    UART_Config_Type inter_type = UartModeInfo.Type[UART_PORT_FFUART];

    UartModeInfo.Type[UART_PORT_FFUART] = UART_INT_ENABLE;

    memcpy(&uart_config, &_UARTPorts[UART_PORT_FFUART].config, sizeof(UARTConfiguration));
    g_uart2_mode = QUEC_UART2_MODE_TO_ATCMD;
    disable_uart_print();
    ret = quec_conifg_uart_port(UART_PORT_FFUART, &uart_config);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("minor uart int enable fail");
        g_uart2_mode = QUEC_UART2_MODE_TO_DEBUG;
        UartModeInfo.Type[UART_PORT_FFUART] = inter_type; // set fail,resume  config
    }
    quec_rtos_task_sleep_ms(500);
    return ret;
}

QuecOSStatus quec_uart2_mode_set(quec_uart2_mode_e mode)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    switch (mode)
    {
    case QUEC_UART2_MODE_TO_DEBUG:
        ret = quec_uart2_mode_to_debug_support();
        g_uart2_mode = mode;
        break;

    case QUEC_UART2_MODE_TO_ATCMD:
        g_uart2_mode = mode;
        ret = quec_uart2_mode_to_atcmd_support();
        UART_Set_Rcv_Fifo_TriggerLevel(UART_PORT_FFUART, UART_INT_TRIGGER_L32);
        break;
    default:
        ret = kGeneralErr;
        uart_log("set g_uart2_mode=%d is invalid", mode);
        break;
    }

    if (ret == QUEC_SUCCESS)
    {
        uart_log("save g_uart2_mode=%d", mode);
        ret = quec_uart2_urc_port_config(g_uart2_mode);
        if (ret != QUEC_SUCCESS)
        {
            uart_log("uart2 urc port config fail");
        }
    }
    return ret;
}

QuecOSStatus quec_uart2_set_mode(quec_msg_process_s *puart2_mod) // quec_uart2_mode_e value)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    // quec_production_cfg_s uart2_mode_cfg ={NULL,QUEC_UART2_MODE_TO_DEBUG};
    quec_uart2_mode_e value = QUEC_UART2_MODE_TO_DEBUG;
    if ((NULL == puart2_mod) || (sizeof(uint8) != puart2_mod->data_len))
    {
        uart_log("puart2_mod=0x%p,data_len=%d", puart2_mod, puart2_mod->data_len);
        return kGeneralErr;
    }
    value = *(quec_uart2_mode_e *)(puart2_mod->pdata);
    // quec_log("Egan_uart2_mode=%d,set_mode=%d", g_uart2_mode,value);
    if (g_uart2_mode == value)
    {
        uart_log("g_uart2_mode=%d is same with value=%d,not need set", g_uart2_mode);
        return QUEC_SUCCESS;
    }
    switch (value)
    {
    case QUEC_UART2_MODE_TO_DEBUG:
        ret = quec_uart2_mode_to_debug_support();
        g_uart2_mode = value;
        break;

    case QUEC_UART2_MODE_TO_ATCMD:
        g_uart2_mode = value;
        ret = quec_uart2_mode_to_atcmd_support();
        UART_Set_Rcv_Fifo_TriggerLevel(UART_PORT_FFUART, UART_INT_TRIGGER_L32);
        break;

    default:
        ret = kGeneralErr;
        uart_log("set g_uart2_mode=%d is invalid", value);
        break;
    }
    // quec_log("egan_storage");
    if (ret == QUEC_SUCCESS)
    {
        uart_log("save g_uart2_mode=%d", value);
        ret = quec_uart2_urc_port_config(g_uart2_mode);
        if (ret != QUEC_SUCCESS)
        {
            uart_log("uart2 urc port config fail");
        }
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
        quec_storage_uart2_debug_mode(g_uart2_mode);
#endif

        /*
        //save
        ret = quec_production_current_cfg_get(&uart2_mode_cfg);
        if(QUEC_CFG_CODE_NOERROR != ret)
        {
            uart_log("read before save qdiagport=%d fail,ret=%d", g_uart2_mode,ret);
            return kGeneralErr;
        }
        strncpy(&uart2_mode_cfg.quec_chk_bytes,QUEC_CFG_BYTE_STR,sizeof(QUEC_CFG_BYTE_STR));
        uart2_mode_cfg.quec_dualport_support = g_uart2_mode;

        ret = quec_production_cfg_write(&uart2_mode_cfg);
        if(QUEC_CFG_CODE_NOERROR != ret)
        {
            uart_log("save qdiagport=%d fail,ret=%d", g_uart2_mode,ret);
            return kGeneralErr;
        }
        */
    }
    quec_log("Egan_set end");
    return QUEC_SUCCESS;
}

void quec_uart2_read_mode(void)
{
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
    quec_read_uart2_debug_mode(); // Chaim 20200226 no obm storage test
#endif

    /*
        QuecOSStatus ret = QUEC_SUCCESS;
        quec_production_cfg_s uart2_getcfg ={NULL,QUEC_UART2_MODE_TO_DEBUG};

        ret = quec_production_cfg_read(&uart2_getcfg);
        if(QUEC_CFG_CODE_NOERROR != ret)
        {
            uart_log("save qdiagport=%d fail,ret=%d", g_uart2_mode,ret);
            g_uart2_mode =  QUEC_UART2_MODE_TO_DEBUG;  //default  for diag_port
           // return ;
        }


        #ifdef __QUEC_OEM_VER_NL__   //Chaim 20190830 new land default use two uart

            if(QUEC_UART2_MODE_TO_ATCMD != g_uart2_mode)
            {
                g_uart2_mode = QUEC_UART2_MODE_TO_ATCMD;
                strncpy(&uart2_getcfg.quec_chk_bytes,QUEC_CFG_BYTE_STR,sizeof(QUEC_CFG_BYTE_STR));
                uart2_getcfg.quec_dualport_support = QUEC_UART2_MODE_TO_ATCMD;

                ret = quec_production_cfg_write(&uart2_getcfg);
                if(QUEC_CFG_CODE_NOERROR != ret)
                {
                    uart_log("save qdiagport=%d fail,ret=%d", g_uart2_mode,ret);
                    return kGeneralErr;
                }
            }
        #else
            g_uart2_mode = uart2_getcfg.quec_dualport_support;
            ret = quec_uart2_urc_port_config(g_uart2_mode);
            if(ret != QUEC_SUCCESS)
            {
                uart_log("uart2 urc port config fail");
            }
        #endif

        uart_log("success g_uart2_mode =%d",g_uart2_mode);
        */
}

QuecOSStatus quec_uart2_send(TelAtParserID atp_index, uint8 *data, uint32 len)
{
    uint16 send_len = 0;
    uint16 unsend_len = (UINT16)len;

    if (g_uart2_mode == QUEC_UART2_MODE_TO_DEBUG)
    {
        uart_log("debug_port is diag_mode,not need take initiative to send,include urc!");
        return QUEC_SUCCESS;
    }

    if ((data == NULL) || (len <= 0))
    {
        uart_log("uart2 atp_index=%d or len=%d data pointer null", atp_index, len);
        return kGeneralErr;
    }

    if (atp_index != TEL_AT_CMD_ATP_UART2)
    {
        uart_log("uart2 atp_index=%d error", atp_index);
        return kGeneralErr;
    }

#ifdef __QUEC_OEM_VER_NL__
    quec_sleep_com_port_recordtick(QUEC_SLEEP_MINORUART_TX_BIT);
#endif
    if (uartState[UART_PORT_FFUART])
    {
        quec_uart2_tx_mutexlock();

        while (send_len < len)
        {
            UARTFIFOWrite((UART_Port)UART_PORT_FFUART, (UINT8 *)(data + send_len), &unsend_len);
            send_len = len - unsend_len;
        }

        quec_uart2_tx_mutexunlock();
    }

    return QUEC_SUCCESS;
}

QuecOSStatus quec_uart2_ioctl(TelAtParserID atp_index, quec_ioctl_cmd_type_e cmd, quec_ioctl_param *param)
{
    return QUEC_SUCCESS;
}

// must return success,else watermark not effect and will be dump
QuecOSStatus quec_uart2_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;

#if (QUEC_MINOR_UART_LOG_FOR_TEST == 0)

    if (g_uart2_mode == QUEC_UART2_MODE_TO_ATCMD)
    {
        UARTOpen(UART_PORT_FFUART);
        UART_Set_Rcv_Fifo_TriggerLevel(UART_PORT_FFUART, UART_INT_TRIGGER_L32);
    }

#endif
    ret = quec_uart2_mode_change_timer_init();
    if (QUEC_SUCCESS != ret)
    {
        uart_log("quec_uart2_mode_change_timer_init=%d error", ret);
    }

    ret = quec_uart_ipr_timer_init(TEL_AT_CMD_ATP_UART2);
    if (QUEC_SUCCESS != ret)
    {
        uart_log("quec_uart_ipr_timer_init status=%d error", ret);
    }

    ret = quec_uart_set_poweron_baudrate(TEL_AT_CMD_ATP_UART2);
    if (ret != QUEC_SUCCESS)
    {
        uart_log("atp_index=%d quec_uart_set_poweron_baudrate fail", TEL_AT_CMD_ATP_UART2);
    }

    return QUEC_SUCCESS;
}

#endif

#endif

#if defined(__QUEC_OEM_VER_NL__) || defined(__QUEC_OEM_VER_XGD__)
extern int quec_get_mipcall_pdp_status(void);

uint8 g_fibo_atk_value = 0;

uint8 g_fibo_atc_value = 1;
uint16 g_fibo_dcd_delay = 10;
// OSATimerRef g_fibo_dcd_delay_time_ref =NULL;
uint8 g_lpmmode = 0;
uint8 g_fibo_gprsreact = QUEC_FIBO_GPRSREACT_DEFAULT;

uint8 quec_fibo_get_gprsreact_value(void)
{
    uart_log("g_fibo_gprsreact=%d", g_fibo_gprsreact);
    return g_fibo_gprsreact;
}

QuecOSStatus quec_fibo_set_gprsreact_value(uint8 value)
{
    QuecOSStatus ret = kGeneralErr;
    if (value > QUEC_FIBO_GPRSREACT_MAX)
    {
        uart_log("set gprs react,value=%d is invalid", value);
        return ret;
    }
    if (g_fibo_gprsreact == value)
    {
        uart_log("set gprs react,value=%d is same", value);
        return QUEC_SUCCESS;
    }
    g_fibo_gprsreact = value;
    return QUEC_SUCCESS;
}

uint8 quec_fibo_get_lpmmode_value(void)
{
    return g_lpmmode;
}

void quec_fibo_set_lpmmode_value(uint8 lpmmode)
{
    g_lpmmode = lpmmode;
}

uint8 quec_fibo_get_atk_value(void)
{
    return g_fibo_atk_value;
}

uint8 quec_fibo_update_atk_value(uint8 atk_value)
{
    switch (atk_value)
    {
    case 0:
    case 3:
    case 6:
        g_fibo_atk_value = atk_value;
        break;

    default:
        uart_log("set atk_value=%d is invalid", atk_value);
        break;
    }
}

QuecOSStatus quec_fibo_atcmd_set_atk_value(TelAtParserID atp_index, uint8 atk_value)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    quec_ifc_value_s ifc_value = {0, 0};

    switch (atk_value)
    {
    case 0:
        ret = quec_set_majoruart_ifc_value(atp_index, ifc_value);
        if (QUEC_SUCCESS == ret)
        {
            quec_fibo_update_atk_value(atk_value);
        }
        break;

    case 3:
    case 6:
        ifc_value.rts_control = 2;
        ifc_value.cts_control = 2;
        ret = quec_set_majoruart_ifc_value(atp_index, ifc_value);
        if (QUEC_SUCCESS == ret)
        {
            quec_fibo_update_atk_value(atk_value);
        }
        break;

    default:
        uart_log("atk_value=%d is invalid", atk_value);
        ret = kGeneralErr;
        break;
    }

    return ret;
}

uint8 quec_fibo_get_atc_value(void)
{
    return g_fibo_atc_value;
}

QuecOSStatus quec_fibo_atcmd_set_atc_value(uint8 atc_value)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    int pdp_status = -1;
    uart_log("set atc_value=%d", atc_value);
    switch (atc_value)
    {
    case 0:
    case 1:
    case 2:
        uart_log("atc_value=%d is not support", atc_value);
        break;
    case 100:
        g_fibo_atc_value = atc_value;
        pdp_status = quec_get_mipcall_pdp_status();
        if (pdp_status != 1)
        {
            quec_siolib_fibo_set_dcd_level(QUEC_PIN_LEVEL_HIGH);
        }
        else
        {
            quec_siolib_fibo_set_dcd_level(QUEC_PIN_LEVEL_LOW);
        }
        break;

    default:
        uart_log("atc_value=%d is invalid", atc_value);
        ret = kGeneralErr;
        break;
    }
    return ret;
}

uint16 quec_fibo_get_dcd_value(void)
{
    uart_log("g_fibo_dcd_delay=%d", g_fibo_dcd_delay);
    return g_fibo_dcd_delay;
}

QuecOSStatus quec_fibo_set_dcd_value(uint16 dcd_delay)
{
    uart_log("set dcd_delay=%d", dcd_delay);
    g_fibo_dcd_delay = dcd_delay;
    return QUEC_SUCCESS;
}
/*

QuecOSStatus quec_fibo_dcd_delay_timer_init(void)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    if(NULL == g_fibo_dcd_delay_time_ref)
    {
        ret = OSATimerCreate(&g_fibo_dcd_delay_time_ref);
        if(ret != OS_SUCCESS)
        {
            uart_log("g_fibo_time_ref ref creat timer fail");
            return kGeneralErr;
        }
    }
    return QUEC_SUCCESS;
}

static QuecOSStatus quec_fibo_dcd_timer_handler(uint32 argc)
{
    quec_pin_level_value_e level = argc;
    //uart_log("argc=%d,diagport=%d",argc,diagport);
    return quec_send_msg_to_modem_router(QUEC_FIBO_DCD_DELAY_MSG, &level, sizeof(level));
}

QuecOSStatus quec_fibo_dcd_delay_timer_start(quec_pin_level_value_e level)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    uint16 dcd_delay = quec_fibo_get_dcd_value();
    if(!dcd_delay)
    {
        uart_log("dcd delay=%d,not need start timer",dcd_delay);
        return QUEC_SUCCESS;
    }
    uart_log("dcd delay=%d timer start",dcd_delay,g_fibo_dcd_delay_time_ref);
    if(NULL != g_fibo_dcd_delay_time_ref)
    {

        ret = OSATimerStart(g_fibo_dcd_delay_time_ref,
                         dcd_delay,
                         0,
                         quec_fibo_dcd_timer_handler,
                         level);

        if(ret != OS_SUCCESS)
        {
            uart_log("start timer fail");
            return kGeneralErr;
        }

    }
    else
    {
        uart_log("dcd delay timer not init");
        return kGeneralErr;
    }
}

QuecOSStatus quec_fibo_dcd_delay_timer_stop(void)
{
    QuecOSStatus ret = kGeneralErr;

    quec_timer_status_t timerStatus ={0};

    if(g_fibo_dcd_delay_time_ref == NULL)
    {
        uart_log("fibo dcd delay timer not init");
        return kGeneralErr;
    }

    ret = quec_rtos_timer_get_status(g_fibo_dcd_delay_time_ref,&timerStatus);
    if (ret != kNoErr)
    {
        uart_log("fibo dcd delay timer  get status fail,can not stop");
        return kGeneralErr;
    }

    if(timerStatus.status == QUEC_TMR_STA_ENABLED)
    {
        ret = quec_rtos_timer_stop(g_fibo_dcd_delay_time_ref);;
        if (ret != kNoErr)
        {
            uart_log("fibo dcd delay timer stop fail");
            return kGeneralErr;
        }
    }
    uart_log("fibo dcd delay timer  stop success");
    return QUEC_SUCCESS;

}
*/

#endif /*MIN_SYS*/

#endif
