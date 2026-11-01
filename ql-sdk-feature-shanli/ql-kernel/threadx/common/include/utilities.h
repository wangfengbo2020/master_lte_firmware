/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/************************************************************************/
/*  COPYRIGHT (C) 2002 Intel Corporation.                               */
/*                                                                      */
/*  This file and the software in it is furnished under                 */
/*  license and may only be used or copied in accordance with the terms */
/*  of the license. The information in this file is furnished for       */
/*  informational use only, is subject to change without notice, and    */
/*  should not be construed as a commitment by Intel Corporation.       */
/*  Intel Corporation assumes no responsibility or liability for any    */
/*  errors or inaccuracies that may appear in this document or any      */
/*  software that may be provided in association with this document.    */
/*  Except as permitted by such license, no part of this document may   */
/*  be reproduced, stored in a retrieval system, or transmitted in any  */
/*  form or by any means without the express written consent of Intel   */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: Arbel platform utility header file     	                    */
/*                                                                      */
/* Filename: utilities.h                                                */
/*                                                                      */
/* Author:   Eli Levy                                                   */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel, HOP     					*/
/*																		*/
/* Remarks: -                                                           */
/*    													                */
/* Created: 26/3/2006                                                   */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/
#ifndef _UTILITIES_H
#define _UTILITIES_H
#ifdef __cplusplus
extern "C" {
#endif

#include "global_types.h"
#include "UART.h"

/*===========================================================================

                                LOCAL MACRO
===========================================================================*/

#define rti_get_mode() rti_current_mode

/*===========================================================================

                          Struct definition.

===========================================================================*/

typedef UINT32  rti_uint32_t;
typedef UINT64  rti_uint64_t;

/*UART Setting */
#define MAX_ActivateCode_NUM	    4
#define MAX_ActivateCode_LENGTH     100

/* RTI thread timeout count */
#define RTI_THREAD_TIMEOUT_SIZE	    32

//see note about this bug on intc_xirq.c. currently the trace for that bug is enabled
#if defined(NVM_INCLUDE)
#ifndef PHS_SW_DEMO_TTC
#define ARIQ_MASK_INTERRUPT_BUG_WORKAROUND_TRACE
#endif
#endif

#if defined(ARIQ_MASK_INTERRUPT_BUG_WORKAROUND_TRACE)
#define AIM_ARR_MAX_SIZE 20
//ICAT EXPORTED STRUCT
typedef struct{
	UINT32 aimVal;
	UINT16 lastCin;
	UINT16 currentCin;
}AIMBugArrStruct;

//ICAT EXPORTED STRUCT
typedef struct{
	AIMBugArrStruct AIMHistoricalVal[AIM_ARR_MAX_SIZE];
	UINT32 AIMArrIndex;
}AIMBugTraceStruct;
/* prototypes*/
#endif


/*
*****************************************************************************************
*			SOC TSENSOR Macros List
*
*Note:  the following MACROs default state: "CLOSED".
*1. ADD_TSENSOR_DEBUG              				If define this MACRO, add debug code for SOC Tsensor
*****************************************************************************************
*/


//#define ADD_TSENSOR_DEBUG




//ICAT EXPORTED STRUCT
typedef struct{
	UINT32 product_id;
	UINT8  data[20];
}InfoForBoardTracking_t;


typedef struct rt_task_info
{
	/*Fixed coverity[overrun-local]*/
	#if 0
	unsigned char task_info[12];
	unsigned long task_ts;
	#else
	unsigned char task_info[16];
	#endif
} RT_TASK_INFO;

typedef struct usbIntDebug_struct
{
	unsigned long ep;
	unsigned long direction;
	unsigned short request_type;
	unsigned short request;
	unsigned long timeStamp;
} usbIntDebug_t;


typedef struct rti_task_rt
{
	unsigned long rti_rt_cnt;
	unsigned long spos;
	unsigned long cpos;
	unsigned long ipc_lr;
	RT_TASK_INFO rti_rt_list[128];
	unsigned long nearest_event_func;
	unsigned long nearest_event_time;
	unsigned long aam_status;
	unsigned long valid_app_found;
	unsigned long nearest_app_time;
	unsigned long eehandler_magic[2];
	unsigned long eehandler_counter;
	unsigned long int_optype;
	unsigned long int_caller;
	unsigned long diag_call_func;
	unsigned long sleep_time;
	unsigned long sleep_state;
	unsigned long sleep_step;
	unsigned long wakeupBits;
	unsigned long CPMnewPowerState;
	unsigned long DDRFlushFlag;
	unsigned long CPFCTsLow;
	unsigned long CPFCTsHigh;
	unsigned long DFCTsLow;
	unsigned long DFCTsHigh;
} rti_rt_t;

#if defined(LTEONLY_8M8M) || defined(LTEONLY_THIN)
#define LONG_RTI_SWITCH_ARRAY_SIZE 2048
typedef struct
{
	unsigned long rti_rt_cnt;
	char header[12];
	RT_TASK_INFO rti_rt_list[LONG_RTI_SWITCH_ARRAY_SIZE];
} long_rti_rt_t;
#endif
typedef enum
{
	rti_pm_idle_pre=1,
	rti_pm_idle_out,
	rti_pm_sleep_pre,
	rti_pm_sleep_out
}rti_pm_state;


typedef enum
{
	rti_pm_step_01=1,
	rti_pm_step_02,
	rti_pm_step_03,
	rti_pm_step_04,
	rti_pm_step_05,
	rti_pm_step_06,
	rti_pm_step_07,
	rti_pm_step_08,
	rti_pm_step_09,
	rti_pm_step_10,
	rti_pm_step_11,
	rti_pm_step_12,
	rti_pm_step_13,
	rti_pm_step_14,
	rti_pm_step_15,
	rti_pm_step_16,
	rti_pm_step_17,
	rti_pm_step_18,
	rti_pm_step_19,
	rti_pm_step_20
}rti_pm_step;

typedef enum
{
    rti_mode_none       = 0x00,
    rti_memory_mode     = 0x01,
    rti_timer_mode      = 0x02,
    rti_log2acat_mode   = 0x03,
    rti_psoff_mode      = 0x04,
    rti_uarttrace_mode  = 0x05,

    rti_urtlog_mode     = 0x100,
    rti_usbtrace_mode   = 0x101,
    rti_muxtrace_mode   = 0x102,
    rti_fsyslog_mode    = 0x103,
    rti_mode_max        = 0xFFFF
}rti_mode;

typedef struct rti_timeout_t
{
    UINT32 thread_to;
    UINT32 ostick_to;
} rti_timeout_t;

typedef struct rti_mode_info
{
	char string[6];
	rti_mode  mode;
} rti_mode_info;

typedef struct rti_thread_timeout_item
{
    UINT8 task[11];
	UINT32 tick_to;
	UINT32 tick_out;
}rti_thread_timeout_item;

//ICAT EXPORTED ENUM
typedef enum {
	RTI_DISABLE=0,
	RTI_EN_VER1=1,
	RTI_EN_VER2=2
} RTI_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	RTI_QUE_DISABLE=0,
	RTI_QUE_ENABLE=1
} RTI_QUE_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
	RTI_EVT_DISABLE=0,
	RTI_EVT_ENABLE=1
} RTI_EVT_TYPE;

//ICAT EXPORTED ENUM
typedef enum {
    TIME_OUT_3MS=0x62,
	TIME_OUT_4MS=0x83,
	TIME_OUT_5MS=0xA4,
	TIME_OUT_6MS=0xC4,
	TIME_OUT_MAX=0xFF
} Timeout_Threshold;

//ICAT EXPORTED STRUCT
typedef struct {
	RTI_TYPE rtiType;
	RTI_QUE_TYPE rtiQueType;
	RTI_EVT_TYPE rtiEvtType;

	int rtiChange;
	int rtiHT;
	int rtiLT;

	int modeChange;
	int modeHT;
	int modeLT;

	Timeout_Threshold Timeout;
} RTICfg_t;

//ICAT EXPORTED ENUM
typedef enum {
	UART_DEV_UART,
	UART_DEV_DIAG,
} UART_DEV_TYPE;

//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32 offset;
	UINT32 size;
}activateCode_info_t;

//ICAT EXPORTED STRUCT
typedef struct {
	UART_DEV_TYPE uartDevType;
	BOOL actiCodeFlag;
	activateCode_info_t activateCode[MAX_ActivateCode_NUM];	//for Ali activation code, [0]:flag,[1]:offset, [2]:size
	BOOL astRandomFlag;
	UINT8 multiVol;//for log_parition
	UINT8 reserved1_1;
	UINT8 reserved1_2;
	UINT8 reserved1_3;
	UINT32 reserved2;
	UINT32 reserved3;

} uartCfgDataS;

/*===========================================================================

            EXTERN DECLARATIONS FOR MODULE

===========================================================================*/

extern rti_mode rti_current_mode;

/*===========================================================================

                        EXTERN FUNCTION DECLARATIONS

===========================================================================*/

void utilitiesPhase3Init (void);
BOOL SysIsAssert(void);
BOOL uart_trace_enable(void);
void rti_init_mode(void);
void uart_reset(void);
unsigned long uart_busy(void);
void hsic_pm_gpio_setting(void);

//fix build warnning
void DbgPrintf(char* fmt, ...);
UINT32 DbgGetType(void);
void qspi_printf(char* fmt, ...);
UINT32 GetDate(CHAR *StrDate);
void DelayInMilliSecond(unsigned int us);
void Timer0_Switch(unsigned char OnOff);
void rti_thread_dump(BOOL isUart);
UINT32 diag_get_32k_tick(void);
char *getCurrentTaskName(void);
BOOL ifPsramSupports500M(void);
BOOL ifPsramUHS(void);
BOOL ifPsramLimit200M(void);


#define cplog_printf uart_printf


/*+++++++++++++CP Log_Priority Start++++++++++++++++++++++++*/
#define CP_LOGSEVERITY_D 1
#define CP_LOGSEVERITY_I 2
#define CP_LOGSEVERITY_W 3
#define CP_LOGSEVERITY_E 4

#ifndef CP_LOGSEVERITY
#define CP_LOGSEVERITY CP_LOGSEVERITY_I	/* use macro "CP_LOGSEVERITY" to control uart log priority */
#endif

#ifndef CP_LOGNDEBUG
	#ifdef CP_NDEBUG						/* use macro "CP_NDEBUG" to control debug log in specific *.c file */
	#define CP_LOGNDEBUG 1		
	#else
	#define CP_LOGNDEBUG 0
	#endif
#endif


#if CP_LOGNDEBUG
#define CP_LOGD(x,...)
#else
#define CP_LOGD(x,...) do{if (CP_LOGSEVERITY <= CP_LOGSEVERITY_D) cplog_printf(x,##__VA_ARGS__);}while(0)
#endif

#define CP_LOGI(x,...) do{if (CP_LOGSEVERITY <= CP_LOGSEVERITY_I) cplog_printf(x,##__VA_ARGS__);}while(0)
#define CP_LOGW(x,...) do{if (CP_LOGSEVERITY <= CP_LOGSEVERITY_W) cplog_printf(x,##__VA_ARGS__);}while(0)
#define CP_LOGE(x,...) do{if (CP_LOGSEVERITY <= CP_LOGSEVERITY_E) cplog_printf(x,##__VA_ARGS__);}while(0)

/*+++++++++++++CP Log_Priority End++++++++++++++++++++++++*/


#define TSEN_GAIN     (1)
#define TSEN_OFFSET_28nm   (-275)
#define TSEN_OFFSET_22nm   (-276)
#define TSEN_LITE_OFFSET_22nm   (-274) /* CraneGT/CraneLS */


#ifndef __IO
#define     __IO    volatile
#endif

typedef struct
{
    __IO UINT32 PCTRL;                 //0x0 Pin control register
    __IO UINT32 INT_CLR;               //0x4 INTERRUPT CLEAR register    
    __IO UINT32 INT_MASK;              //0x8 INTERRUPT MASK Register
    __IO UINT32 RESERVED1;
    __IO UINT32 INT_STATUS;            //0x10 INTERRUPT STATUS Register
    __IO UINT32 READ_DATA0;            //0x14 READ DATA0 Register
    __IO UINT32 TIME_CTRL;             //0x18 TIME CONTROL Register
    __IO UINT32 READ_DATA1;            //0x1c READ DATA1 Register
    __IO UINT32 TEMP_THRESHOLD0;       //0x20 TEMP  Register
    __IO UINT32 TEMP_THRESHOLD1;       //0x24 TEMP  Register
    __IO UINT32 TEMP_THRESHOLD2;       //0x28 TEMP  Register
    __IO UINT32 TEMP_THRESHOLD3;       //0x2c TEMP  Register
    __IO UINT32 REBOOT_TEMP_THR;       //0x30 EMERGENT_REBOOT_TEMP_THR  Register
    __IO UINT32 AUTO_MODE_INTERVAL;    //0x34 AUTO_MODE_INTERVAL  Register
    __IO UINT32 RESERVED[19];          //0x38~0x7c
    __IO UINT32 AUXADC_RESULT0;        //0x80 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT2;        //0x84 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT4;        //0x88 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT6;        //0x8c AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT8;        //0x90 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT10;       //0x94 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT12;       //0x98 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT14;       //0x9c AUXADC RESULT  Register

}THSESOR_TypeDef;

typedef struct
{
    __IO UINT32 CFG;                    //0x0 config register
    __IO UINT32 TEMP_THRSHLD;           //0x4 temp threshold register    
    __IO UINT32 INT_MASK;               //0x8 INTERRUPT MASK Register
    __IO UINT32 INT_STATUS;             //0xC INTERRUPT STATUS Register
    __IO UINT32 INT_CLR;                //0x10 INTERRUPT CLEAR Register
    __IO UINT32 RBT_TEMP_THRSHLD;       //0x14 REBOOT TEMP THRESHOLD Register
    __IO UINT32 READ_TDATA;              //0x18 READ DATA Register
    __IO UINT32 VREF_EFUSE;             //0x1C VREF EFUSE Register
    __IO UINT32 RESERVED1[24];          //0x20~0x7C
    __IO UINT32 AUXADC_RESULT0;         //0x80 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT2;         //0x84 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT4;         //0x88 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT6;         //0x8c AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT8;         //0x90 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT10;        //0x94 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT12;        //0x98 AUXADC RESULT  Register
    __IO UINT32 AUXADC_RESULT14;        //0x9c AUXADC RESULT  Register
    
    __IO UINT32 AUXADC_INT_STS;         //0xA0 AUXADC INT STATUS Register, only CraneGT has
    __IO UINT32 RESERVED2[19];          //0xA4~0xEC
    __IO UINT32 AUXADC_INT_CLR;         //0xF0 AUXADC INT CLEAR Register, only CraneGT has

}TSENSOR_LITE_TypeDef;

#define	   APBC_TSEN_CLK_RST 0xd401506c
#define    THSESOR_BASE      0xD4013300
#define    TSENSOR_BASE_CRANELS 0xD4013350

#define    TSEN  (( THSESOR_TypeDef *) THSESOR_BASE )
#define    TSEN_LITE  (( TSENSOR_LITE_TypeDef *) THSESOR_BASE )
#define    TSEN_LITE_CRANELS  (( TSENSOR_LITE_TypeDef *) TSENSOR_BASE_CRANELS )

#define BIT_0 (1 << 0)
#define BIT_1 (1 << 1)
#define BIT_2 (1 << 2)
#define BIT_3 (1 << 3)
#define BIT_4 (1 << 4)
#define BIT_5 (1 << 5)
#define BIT_6 (1 << 6)
#define BIT_7 (1 << 7)
#define BIT_8 (1 << 8)
#define BIT_9 (1 << 9)
#define BIT_10 (1 << 10)
#define BIT_11 (1 << 11)
#define BIT_12 (1 << 12)
#define BIT_13 (1 << 13)
#define BIT_14 (1 << 14)
#define BIT_15 (1 << 15)
#define BIT_16 (1 << 16)
#define BIT_17 (1 << 17)
#define BIT_18 (1 << 18)
#define BIT_19 (1 << 19)
#define BIT_20 (1 << 20)
#define BIT_21 (1 << 21)
#define BIT_22 (1 << 22)
#define BIT_23 (1 << 23)
#define BIT_24 (1 << 24)
#define BIT_25 (1 << 25)
#define BIT_26 (1 << 26)
#define BIT_27 (1 << 27)
#define BIT_28 (1 << 28)
#define BIT_29 (1 << 29)
#define BIT_30 (1 << 30)
#define BIT_31 ((unsigned)1 << 31)



/* TSEN_PCTRL */
#define EN_SENSOR                    BIT_0
#define TEMP_MODE                    BIT_3
#define BJT_SEL                      BIT_4
#define TEMP_DATA_OUTPUT_MODE        BIT_22
#define HW_AUTO_MODEE                BIT_23
#define SENSOR_EN_BITMAP             BIT_24

/* INT_CLR */
#define EMERGENT_REBOOT_TEMP_CLR     BIT_9
#define TSEN3_OVERFLOW_INT_CLR       BIT_8
#define TSEN3_UNDERFLOW_INT_CLR      BIT_7
#define TSEN2_OVERFLOW_INT_CLR       BIT_6
#define TSEN2_UNDERFLOW_INT_CLR      BIT_5
#define TSEN1_OVERFLOW_INT_CLR       BIT_4
#define TSEN1_UNDERFLOW_INT_CLR      BIT_3
#define TSEN0_OVERFLOW_INT_CLR       BIT_2
#define TSEN0_UNDERFLOW_INT_CLR      BIT_1
#define TSEN_INT_CLR                 BIT_0

/* INT_MASK */
#define EMERGENT_REBOOT_TEMP_MASK    BIT_9
#define TSEN3_OVERFLOW_INT_MASK      BIT_8
#define TSEN3_UNDERFLOW_INT_MASK     BIT_7
#define TSEN2_OVERFLOW_INT_MASK      BIT_6
#define TSEN2_UNDERFLOW_INT_MASK     BIT_5
#define TSEN1_OVERFLOW_INT_MASK      BIT_4
#define TSEN1_UNDERFLOW_INT_MASK     BIT_3
#define TSEN0_OVERFLOW_INT_MASK      BIT_2
#define TSEN0_UNDERFLOW_INT_MASK     BIT_1
#define TSEN_INT_MASK                BIT_0

/* INT_STATUS */
#define EMERGENT_REBOOT_TEMP_STAUTS  BIT_9
#define TSEN3_OVERFLOW_INT_STATUS    BIT_8
#define TSEN3_UNDERFLOW_INT_STATUS   BIT_7
#define TSEN2_OVERFLOW_INT_STATUS    BIT_6
#define TSEN2_UNDERFLOW_INT_STATUS   BIT_5
#define TSEN1_OVERFLOW_INT_STATUS    BIT_4
#define TSEN1_UNDERFLOW_INT_STATUS   BIT_3
#define TSEN0_OVERFLOW_INT_STATUS    BIT_2
#define TSEN0_UNDERFLOW_INT_STATUS   BIT_1
#define TSEN_INT_STATUS              BIT_0

/* READ_DATA0 */
#define TSEN_READ_DATA1              BIT_16
#define TSEN_READ_DATA0              BIT_0

/* TIME_CTRL */
#define FILTER_PERIOD                BIT_8
#define RST_ADC_CNT                  BIT_4
#define WAIT_REF_CNT                 BIT_0

/* READ_DATA1 */
#define TSEN_READ_DATA3              BIT_16
#define TSEN_READ_DATA2              BIT_0

/* TSEN_TEMP_THRESHOLD0 */
#define TSEN_HIGH_THR0               BIT_16
#define TSEN_LOW_THR0                BIT_0

/* TSEN_TEMP_THRESHOLD1 */
#define TSEN_HIGH_THR1               BIT_16
#define TSEN_LOW_THR1                BIT_0

/* TSEN_TEMP_THRESHOLD2 */
#define TSEN_HIGH_THR2               BIT_16
#define TSEN_LOW_THR2                BIT_0

/* TSEN_TEMP_THRESHOLD3 */
#define TSEN_HIGH_THR3               BIT_16
#define TSEN_LOW_THR3                BIT_0

/* EMERGENT_REBOOT_TEMP_THR */
#define EMERGENT_REBOOT_TEMP_THR     BIT_0

/* TSEN AUTO_MODE_INTERVAL */
#define TSEN_AUTO_MODE_INTERVAL      BIT_0

#define AP_16M              0
#define WB_16M              1
#define AP_8M8M             2
#define WB_8M8M             4
#define AP_8M               5
#define WB_8M               6
#define WB_250MHZ_8M        7
#define AP_UHS_8M8M         8
#define WB_250MHZ_8M8M      9
#define AP_250MHZ_8M8M      10
#define WB_XCCELA_8M        11
#define WB_XCCELA_8M8M      12
#define WB_4M               13
#define AP_4M               14
#define WB_XCCELA_4M        15
#define AP_250MHZ_8M        16
#define WB_32M              17
#define AP_250MHZ_16M       18
#define WB_250MHZ_16M       19

int getTsensorTemperatureCelsiusValue( void );
UINT32 getTsensorTemperatureRawValue( void );



#if ( defined ADD_TSENSOR_DEBUG )
void Create_Test_Tsensor_Task(void);
#endif




void thread_measurement_enable(void);
void thread_measurement_disable(void);
void rti_thread_dump_buf(char* buf);
void rti_thread_set_enable(rti_uint32_t enable);
int get_sdcard_log_partition_status(void);
void setLogSdcardPartitionType(int type);
unsigned long isEnable_performance_count(void);
void rti_timer_switch_to(unsigned long routine);
void rti_check_thread_timeout(void);
void rti_record_line(const char *string, unsigned int line);

//void vbat_pm803_init(void);

typedef struct{
	UINT32 AdcValue;
	UINT32 VoltageValue;
}MrdAdc_t;

/***********************************************************************
 *
 * Name:	MRDAdcValueGet
 *
 * Description: Get the value of ADC info which is written in prod mode.
 *
 * Parameters:
 *  UINT32	index			[IN]    const character string for file name specifier.
 *  UINT32	value1,value2	[OUT] 	const character string for type specification;
 *          value1 --- AdcValue
 *          value2 --- VoltageValue
 *
 * Returns:
 *	0: 	ok.
 * -1:	invalid input or value get
 *	1:	the value1/value2 get is null
 *
 ***********************************************************************/
INT32 MRDAdcValueGet_boot(UINT32 index, UINT32 *value1, UINT32 *value2);
/***********************************************************************
 *
 * Name:	MRDAdcFlagGet
 *
 * Description: Get the flag of ADC info which is written in prod mode.
  * Returns:
 *	0: 	the ADC calibration flag is not set.
 *	1:	the ADC calibration flag is set.
***********************************************************************/
INT32 MRDAdcFlagGet_boot(void);

UINT32 MRDAdcCntGet_boot( void );

void MrdBubbleSort( MrdAdc_t *p_MrdAdcData[],const UINT32 DataNum );

/**
 * @brief get vbat by pm803 and rd adc
 * @param: None
 * @retva: value > 0 : The valid vbat value(unit: mv).
 *         vlaue <0  : Error value
 *				-1: PMIC is not PM803
 *				-2: dsp not ready
 *				-3: get vbat fail
 */
INT16 GetPm803VrtpAdc(void);

void cranel_adc_init1(void);
void cranel_adc_init2(void);

UINT8 getPsramType(void);
#ifdef __cplusplus
}
#endif
#endif  /*_UTILITIES_H*/



