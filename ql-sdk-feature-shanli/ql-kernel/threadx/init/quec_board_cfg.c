/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/

/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN              WHO         WHAT, WHERE, WHY
------------     -------     -------------------------------------------------------------------------------
2022/04/26        Sharon.li   此文件实现开机阶段初始化pin脚的功能函数；注意此文件为大系统和小系统共同使用禁止调用大系统里的代码
=================================================================*/

#include "quec_cust_feature.h"


#ifdef QUECTEL_PROJECT_CUST
#include "quec_gpio.h"




GPIO_PinConfiguration quec_board_gpio_cfg[] =
{
	{QUEC_WAKEUP_IN_GPIO, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLDN_ENABLE, GPIO_INITIAL_VALUE_LOW},       // wakeup_in
	{QUEC_APREADY_DET_PIN, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_LOW},      // ap_ready
	{IPC_SLEEP_IND_NUM, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_LOW},        // sleep_ind
	{QUEC_AIR_PLAN_CTRL_PIN, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_LOW},    // fly mode control
	{QUEC_NET_MODE_GPIO, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_LOW},       // net mode
    {QUEC_NET_STATUS_GPIO, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_HIGH},    // net status
	{QUEC_USIM_DET_PIN, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_HIGH},         // usim det
	{QUEC_POWER_STATUS_PIN, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW},     // power status
	{UART1_RI_PIN_NUM, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_HIGH},        // RI
    {UART1_DCD_PIN_NUM, GPIO_OUT_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULL_DISABLE, GPIO_INITIAL_VALUE_LOW},         // DCD   
    {UART_DTR_PIN_NUM, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_HIGH},         // DTR
    {QUEC_GPIO_CTRL_CAMIOVDD_PIN, GPIO_IN_PIN, GPIO_NO_EDGE, GPIO_DEBOUNCE_ENABLE, GPIO_PULLUP_ENABLE, GPIO_INITIAL_VALUE_HIGH},         // For Ctrl CameraIOvdd
};	

const unsigned long quec_board_gpio_mfpr_reg_data[] = 
{
    QUEC_WAKEUP_IN_GPIO_AF,     // wakeup_in
    QUEC_APREADY_DET_PIN_AF,     // ap_ready
	IPC_SLEEP_IND_NUM_AF,     // sleep_ind
    QUEC_AIR_PLAN_CTRL_PIN_AF,     // fly mode control
    QUEC_NET_MODE_GPIO_AF,     // net mode
	QUEC_NET_STATUS_GPIO_AF,     // net status
    QUEC_USIM_DET_PIN_AF,     // usim det
	QUEC_POWER_STATUS_PIN_AF,	 // power status
	UART1_RI_PIN_NUM_AF,	 // RI
    UART1_DCD_PIN_NUM_AF,     // DCD
    UART_DTR_PIN_NUM_AF,     // DTR
    QUEC_GPIO_CTRL_CAMIOVDD_PIN_AF,//For Ctrl CameraIOvdd
};

int quec_set_gpio_mfprReg(GPIO_PinNumbers pin_num, unsigned long mfprReg_data )
{
	if( pin_num >= GPIO_MAX_AMOUNT_OF_PINS || pin_num < GPIO_PIN_0 )
	{
		 CPUartLogPrintf("pin_num=%d error", pin_num);
		 return kParamErr;
	}
	
	unsigned int mfpr_addr = (GPIO_MFPR_ADDR(pin_num));
	if(INVALID_GPIO_MFPR_ADDR != mfpr_addr)
		*(volatile unsigned long *)(mfpr_addr) = mfprReg_data;
	else
		CPUartLogPrintf("ERR:pin_num=%d INVALID_GPIO_MFPR_ADDR", pin_num);
	
	return QUEC_SUCCESS;
}

//jensen.fang 20181102: to write configuration of one or more gpio
QuecOSStatus quec_gpio_config_set(GPIO_PinConfiguration *pin_config)
{
	if( pin_config->pinNumber >= GPIO_MAX_AMOUNT_OF_PINS || pin_config->pinNumber < GPIO_PIN_0 )
	{
		 CPUartLogPrintf("pin_num=%d error", pin_config->pinNumber);
		 return kGeneralErr;
	}
	GPIO_ReturnCode ret = GPIO_RC_INVALID_PIN_NUM;
	ret = GPIOConfigure(pin_config);
	if (GPIORC_OK != ret)
	{	
		CPUartLogPrintf("[Quec][GPIO] gpio %d configure fail: ret=%d", pin_config->pinNumber, ret);
		return kGeneralErr;
	}
	return QUEC_SUCCESS;
}


QuecOSStatus quec_gpio_cust_config(void)
{
	int i=0;
	for(i =0; i <  QUEC_ARR_SIZE(quec_board_gpio_cfg) ; i++)
	{
		if((quec_board_gpio_cfg[i].pinNumber>=GPIO_PIN_0)&&(quec_board_gpio_cfg[i].pinNumber<GPIO_MAX_AMOUNT_OF_PINS))
		{
			quec_set_gpio_mfprReg(quec_board_gpio_cfg[i].pinNumber, quec_board_gpio_mfpr_reg_data[i]);// set gpio function
			if (QUEC_SUCCESS != quec_gpio_config_set(&quec_board_gpio_cfg[i]))
			{
				CPUartLogPrintf("error: configure quectel custom gpio fail!");
				return kGeneralErr;
			}
		}
	}

	return QUEC_SUCCESS;
}

typedef struct quec_gpio_pinmux_map{
	unsigned char pin;
	unsigned char gpio;
}quec_gpio_pinmux_map_t;
typedef struct quec_pin_to_gpio_cfg{
	char proj_name[16];
	quec_gpio_pinmux_map_t map_table[GPIO_MAX_AMOUNT_OF_PINS];
}quec_pin_to_gpio_cfg_t;
extern char mob_model_id[];
//添加一个OC需增加此全局变量
static quec_pin_to_gpio_cfg_t cfg[] = {
	{
		{"EC600M"},
		{
			{54,GPIO_PIN_4},	{49,GPIO_PIN_5},	{52,GPIO_PIN_6},	{53,GPIO_PIN_7},
			{57,GPIO_PIN_10},	{56,GPIO_PIN_11},	{67,GPIO_PIN_12},	{65,GPIO_PIN_13},
			{63,GPIO_PIN_14},	{66,GPIO_PIN_15},	{16,GPIO_PIN_20},	{10,GPIO_PIN_21},
			{13,GPIO_PIN_22},	{15,GPIO_PIN_23},	{14,GPIO_PIN_24},	{11,GPIO_PIN_25},
			{12,GPIO_PIN_26},	{72,GPIO_PIN_29},	{71,GPIO_PIN_30},	{69,GPIO_PIN_32},
			{50,GPIO_PIN_71},	{51,GPIO_PIN_72},	{109,GPIO_PIN_0},	{110,GPIO_PIN_1},
			{48,GPIO_PIN_2},	{55,GPIO_PIN_9},	{61,GPIO_PIN_16},	{58,GPIO_PIN_17},
			{60,GPIO_PIN_18},	{59,GPIO_PIN_19},	{112,GPIO_PIN_69},	{111,GPIO_PIN_70},
			{31,GPIO_PIN_51},	{32,GPIO_PIN_52},	{34,GPIO_PIN_53},	{33,GPIO_PIN_54},
			{40,GPIO_PIN_31},	{39,GPIO_PIN_27},	{70,GPIO_PIN_117},	{130,GPIO_PIN_79},
			{131,GPIO_PIN_80},	{62,GPIO_PIN_28},	{1,GPIO_PIN_33},	{4,GPIO_PIN_34},
			{2,GPIO_PIN_35},	{3,GPIO_PIN_36},	{9,GPIO_PIN_49},	{64,GPIO_PIN_50},
			{5,GPIO_PIN_81},	{6,GPIO_PIN_82},	{7,GPIO_PIN_83},	{147,GPIO_PIN_45},
			{146,GPIO_PIN_46},	{145,GPIO_PIN_47},
		}
	},
	{
		{"EC800M"},
		{
			{77,GPIO_PIN_4},	{76,GPIO_PIN_5},	{16,GPIO_PIN_6},	{78,GPIO_PIN_7},
			{75,GPIO_PIN_10},	{74,GPIO_PIN_11},	{68,GPIO_PIN_12},	{69,GPIO_PIN_13},
			{84,GPIO_PIN_14},	{85,GPIO_PIN_15},	{81,GPIO_PIN_20},	{54,GPIO_PIN_21},
			{80,GPIO_PIN_22},	{56,GPIO_PIN_23},	{55,GPIO_PIN_24},	{57,GPIO_PIN_25},
			{58,GPIO_PIN_26},	{38,GPIO_PIN_29},	{39,GPIO_PIN_30},	{49,GPIO_PIN_32},
			{21,GPIO_PIN_124},	{87,GPIO_PIN_0},	{86,GPIO_PIN_1},	{28,GPIO_PIN_2},
			{29,GPIO_PIN_3},	{83,GPIO_PIN_8},	{82,GPIO_PIN_9},	{30,GPIO_PIN_16},
			{31,GPIO_PIN_17},	{33,GPIO_PIN_18},	{32,GPIO_PIN_19},	{79,GPIO_PIN_69},
			{25,GPIO_PIN_70},	{17,GPIO_PIN_51},	{18,GPIO_PIN_52},	{23,GPIO_PIN_53},
			{22,GPIO_PIN_54},	{20,GPIO_PIN_31},	{19,GPIO_PIN_27},	{105,GPIO_PIN_79},
			{104,GPIO_PIN_80},	{53,GPIO_PIN_33},	{52,GPIO_PIN_34},	{51,GPIO_PIN_35},
			{50,GPIO_PIN_36},	{67,GPIO_PIN_49},	{66,GPIO_PIN_50},	{13,GPIO_PIN_81},
			{11,GPIO_PIN_82},	{12,GPIO_PIN_83},	{62,GPIO_PIN_45},	{64,GPIO_PIN_46},
			{63,GPIO_PIN_47},	
		}
	},
	{
		{"EC200M"},
		{
			{3,GPIO_PIN_4},		{4,GPIO_PIN_5},		{6,GPIO_PIN_6},		{2,GPIO_PIN_7},
			{141,GPIO_PIN_10},	{142,GPIO_PIN_11},	{73,GPIO_PIN_12},	{13,GPIO_PIN_13},
			{23,GPIO_PIN_20},	{30,GPIO_PIN_21},	{31,GPIO_PIN_22},	{33,GPIO_PIN_23},
			{32,GPIO_PIN_24},	{28,GPIO_PIN_25},	{29,GPIO_PIN_26},	{11,GPIO_PIN_29},
			{12,GPIO_PIN_30},	{120,GPIO_PIN_32},	{84,GPIO_PIN_71},	{83,GPIO_PIN_72},
			{81,GPIO_PIN_73},	{80,GPIO_PIN_74},	{78,GPIO_PIN_0},	{77,GPIO_PIN_1},
			{61,GPIO_PIN_2},	{5,GPIO_PIN_3},		{1,GPIO_PIN_8},		{115,GPIO_PIN_9},
			{27,GPIO_PIN_16},	{26,GPIO_PIN_17},	{25,GPIO_PIN_18},	{24,GPIO_PIN_19},
			{74,GPIO_PIN_69},	{75,GPIO_PIN_70},	{68,GPIO_PIN_51},	{67,GPIO_PIN_52},
			{65,GPIO_PIN_53},	{64,GPIO_PIN_54},	{62,GPIO_PIN_31},	{66,GPIO_PIN_27},
			{116,GPIO_PIN_78},	{143,GPIO_PIN_79},	{144,GPIO_PIN_80},	{63,GPIO_PIN_28},
			{40,GPIO_PIN_33},	{37,GPIO_PIN_34},	{39,GPIO_PIN_35},	{38,GPIO_PIN_36},
			{41,GPIO_PIN_49},	{42,GPIO_PIN_50},	{118,GPIO_PIN_122},	{16,GPIO_PIN_81},
			{15,GPIO_PIN_82},	{17,GPIO_PIN_83},	{121,GPIO_PIN_45},	{122,GPIO_PIN_46},	
			{119,GPIO_PIN_47},
		}
	},
	{
		{"EG810M"},
		{
			{77,GPIO_PIN_4},	{76,GPIO_PIN_5},	{16,GPIO_PIN_6},	{78,GPIO_PIN_7},
			{75,GPIO_PIN_10},	{74,GPIO_PIN_11},	{68,GPIO_PIN_12},	{69,GPIO_PIN_13},
			{84,GPIO_PIN_14},	{85,GPIO_PIN_15},	{81,GPIO_PIN_20},	{54,GPIO_PIN_21},
			{80,GPIO_PIN_22},	{56,GPIO_PIN_23},	{55,GPIO_PIN_24},	{57,GPIO_PIN_25},
			{58,GPIO_PIN_26},	{38,GPIO_PIN_29},	{39,GPIO_PIN_30},	{49,GPIO_PIN_32},
			{21,GPIO_PIN_124},	{87,GPIO_PIN_0},	{86,GPIO_PIN_1},	{28,GPIO_PIN_2},
			{29,GPIO_PIN_3},	{83,GPIO_PIN_8},	{82,GPIO_PIN_9},	{30,GPIO_PIN_16},
			{31,GPIO_PIN_17},	{33,GPIO_PIN_18},	{32,GPIO_PIN_19},	{79,GPIO_PIN_69},
			{25,GPIO_PIN_70},	{17,GPIO_PIN_51},	{18,GPIO_PIN_52},	{23,GPIO_PIN_53},
			{22,GPIO_PIN_54},	{20,GPIO_PIN_31},	{19,GPIO_PIN_27},	{105,GPIO_PIN_79},
			{104,GPIO_PIN_80},	{53,GPIO_PIN_33},	{52,GPIO_PIN_34},	{51,GPIO_PIN_35},
			{50,GPIO_PIN_36},	{67,GPIO_PIN_49},	{66,GPIO_PIN_50},	{13,GPIO_PIN_81},
			{11,GPIO_PIN_82},	{12,GPIO_PIN_83},	{62,GPIO_PIN_45},	{64,GPIO_PIN_46},
			{63,GPIO_PIN_47},
		}
	},
	{
		{"EC600K"},
		{
			{61,GPIO_PIN_4},	{58,GPIO_PIN_5},	{59,GPIO_PIN_6},	{60,GPIO_PIN_7},
			{11,GPIO_PIN_10},	{12,GPIO_PIN_11},	{1,GPIO_PIN_12},	{4,GPIO_PIN_13},
			{2,GPIO_PIN_14},	{3,GPIO_PIN_15},	{72,GPIO_PIN_71},	{71,GPIO_PIN_72},
			{39,GPIO_PIN_73},	{48,GPIO_PIN_74},	{52,GPIO_PIN_0},	{53,GPIO_PIN_1},
			{54,GPIO_PIN_2},	{49,GPIO_PIN_3},	{50,GPIO_PIN_8},	{55,GPIO_PIN_9},
			{51,GPIO_PIN_68},	{70,GPIO_PIN_69},	{69,GPIO_PIN_70},	{9,GPIO_PIN_85},
			{16,GPIO_PIN_86},	{13,GPIO_PIN_87},	{14,GPIO_PIN_88},	{15,GPIO_PIN_89},
			{10,GPIO_PIN_90},	{130,GPIO_PIN_79},	{131,GPIO_PIN_80},	{67,GPIO_PIN_33},
			{65,GPIO_PIN_34},	{63,GPIO_PIN_35},	{66,GPIO_PIN_36},	{57,GPIO_PIN_49},
			{56,GPIO_PIN_50},	{31,GPIO_PIN_51},	{32,GPIO_PIN_52},	{34,GPIO_PIN_53},
			{33,GPIO_PIN_54},	{64,GPIO_PIN_55},	{40,GPIO_PIN_56},	{62,GPIO_PIN_57},
			{5,GPIO_PIN_81},	{6,GPIO_PIN_82},	{7,GPIO_PIN_83},
		}
	},
	{
		{"EC800K"},
		{
			{75,GPIO_PIN_4},	{74,GPIO_PIN_5},	{77,GPIO_PIN_6},	{76,GPIO_PIN_7},
			{68,GPIO_PIN_10},	{69,GPIO_PIN_11},	{53,GPIO_PIN_12},	{52,GPIO_PIN_13},
			{51,GPIO_PIN_14},	{50,GPIO_PIN_15},	{38,GPIO_PIN_71},	{39,GPIO_PIN_72},
			{19,GPIO_PIN_73},	{20,GPIO_PIN_74},	{87,GPIO_PIN_0},	{86,GPIO_PIN_1},
			{28,GPIO_PIN_2},	{29,GPIO_PIN_3},	{81,GPIO_PIN_8},	{82,GPIO_PIN_9},
			{25,GPIO_PIN_68},	{16,GPIO_PIN_69},	{83,GPIO_PIN_70},	{57,GPIO_PIN_84},
			{56,GPIO_PIN_85},	{58,GPIO_PIN_86},	{55,GPIO_PIN_87},	{78,GPIO_PIN_89},
			{49,GPIO_PIN_90},	{104,GPIO_PIN_79},	{105,GPIO_PIN_80},	{30,GPIO_PIN_33},
			{31,GPIO_PIN_34},	{33,GPIO_PIN_35},	{32,GPIO_PIN_36},	{79,GPIO_PIN_37},
			{67,GPIO_PIN_49},	{66,GPIO_PIN_50},	{17,GPIO_PIN_51},	{18,GPIO_PIN_52},
			{23,GPIO_PIN_53},	{22,GPIO_PIN_54},	{21,GPIO_PIN_55},	{80,GPIO_PIN_56},
			{54,GPIO_PIN_57},	{13,GPIO_PIN_81},	{11,GPIO_PIN_82},	{12,GPIO_PIN_83},
		}
	},
	{
		{"EG800K"},
		{
			{75,GPIO_PIN_4},	{74,GPIO_PIN_5},	{77,GPIO_PIN_6},	{76,GPIO_PIN_7},
			{68,GPIO_PIN_10},	{69,GPIO_PIN_11},	{53,GPIO_PIN_12},	{52,GPIO_PIN_13},
			{51,GPIO_PIN_14},	{50,GPIO_PIN_15},	{38,GPIO_PIN_71},	{39,GPIO_PIN_72},
			{19,GPIO_PIN_73},	{20,GPIO_PIN_74},	{87,GPIO_PIN_0},	{86,GPIO_PIN_1},
			{28,GPIO_PIN_2},	{29,GPIO_PIN_3},	{81,GPIO_PIN_8},	{82,GPIO_PIN_9},
			{25,GPIO_PIN_68},	{16,GPIO_PIN_69},	{83,GPIO_PIN_70},	{57,GPIO_PIN_84},
			{56,GPIO_PIN_85},	{58,GPIO_PIN_86},	{55,GPIO_PIN_87},	{78,GPIO_PIN_89},
			{49,GPIO_PIN_90},	{104,GPIO_PIN_79},	{105,GPIO_PIN_80},	{30,GPIO_PIN_33},
			{31,GPIO_PIN_34},	{33,GPIO_PIN_35},	{32,GPIO_PIN_36},	{79,GPIO_PIN_37},
			{67,GPIO_PIN_49},	{66,GPIO_PIN_50},	{17,GPIO_PIN_51},	{18,GPIO_PIN_52},
			{23,GPIO_PIN_53},	{22,GPIO_PIN_54},	{21,GPIO_PIN_55},	{80,GPIO_PIN_56},
			{54,GPIO_PIN_57},	{13,GPIO_PIN_81},	{11,GPIO_PIN_82},	{12,GPIO_PIN_83},
		}
	},
};
int quec_gpiocfg_pin2gpio(int pin)
{
	int i = 0;
	static int item = 0;
	static int flag = 0;

	//fst 判断项目是否添加
	if(0 == flag)
	{
		for(i=0;i<(sizeof(cfg)/sizeof(cfg[0]));i++)
		{
			if(0 == strcmp(mob_model_id,cfg[i].proj_name))
			{
				flag = 1;
				item = i;
				break;
			}
		}
	}
	
	//sec 判断pin脚是否存在
	if(flag)
	{
		for(i=0;i<GPIO_MAX_AMOUNT_OF_PINS;i++)
		{
			if(cfg[item].map_table[i].pin == pin)
				return cfg[item].map_table[i].gpio;
		}
	}
	
	return -1;
}

#ifdef  HX_GNSS_SUPPORT

//为了兼容多项目gnss,增加这个函数用来在初始化阶段选择gnss pin脚
#include "gps_channel.h"

int quec_boardcfg_gnss_pin_init(quec_gps_gpio_struct_t *gpio_pin)
{
	if(NULL == gpio_pin)
		return -1;
	
	gpio_pin->tx = GPIO_PIN_74;
	gpio_pin->rx = GPIO_PIN_73;
	
	#if defined(__QUECTEL_PROJECT_EC600MCN_GC__)
		gpio_pin->rst = GPIO_PIN_3;
		gpio_pin->pwr_en = GPIO_PIN_120;

	#else
		gpio_pin->rst = GPIO_PIN_71;
	#endif

	return 0;
}

//20230807 和芯gnss rom1 or rom2 check 后续新增和芯gnss项目须在此接口中添加项目宏控 
//20231011 增加gnss_type 3类型：ROM2 OC不接备电
int quec_gnss_type_check(void)
{
	int gnss_type;
#if defined (__QUECTEL_PROJECT_EC800MCN_GC__) || defined(__QUECTEL_PROJECT_EC800MCN_GA__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined(__QUECTEL_PROJECT_EG810MCN_GA__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_GC__)
	gnss_type = 1; //ROM1
#elif defined(__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__)
	gnss_type = 2; //ROM2
#else 
	gnss_type = 1;
#endif
	return gnss_type;
}
#endif

#endif

