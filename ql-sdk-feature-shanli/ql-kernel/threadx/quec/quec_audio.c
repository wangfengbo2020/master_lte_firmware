/**  @file
  quec_audio.c

  @brief
  This file is used to define the audio for different Quectel Project.

*/

/*================================================================
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd.  All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
=================================================================*/
/*=================================================================

                        EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

WHEN                WHO            WHAT, WHERE, WHY
------------        -------     -------------------------------------------------------------------------------
12/04/2018      grady           Init version
=================================================================*/

/******************************************************************
 * include files
 ******************************************************************/
#include "quec_audio.h"
#include "quec_include.h"
#include "quec_cust_feature.h"
//#include "acm_rt5616.h"
//#include "acm_comm.h"
#include "quec_iic.h"
#if QUEC_AUDIO_SUPPORT
#include "AudioHAL.h"
#endif
#ifdef CRANE_MCU_DONGLE
#include "pmic.h"
#else
#include "I2C.h"
#endif
#include "quec_production_cfg.h"

#ifndef MIN_SYS


/*===========================================================================
 * Macro Definition
 ===========================================================================*/
#ifdef QUEC_AUDIO_SUPPORT
	#define quec_audio_log(msg, ...)  custom_log("ATCMD_AUDIO", msg, ##__VA_ARGS__)
#else
	#define quec_audio_log(msg, ...)
#endif


#if defined QUEC_AUDIO_SUPPORT

#define NAU8810_I2C_SLAVE_ADDR      0x1A
#define NAU8810_SLAVE_WRITE_ADDR    0x34
#define NAU8810_SLAVE_READ_ADDR     0x35

#define RT5616_I2C_SLAVE_ADDR       0x1B
#define RT5616_SLAVE_WRITE_ADDR     0x36
#define RT5616_SLAVE_READ_ADDR      0x37


#define QUEC_NV_QDAI_CFG  "quec_nv_qdai_cfg"

/*===========================================================================
 * struct/enum definition
 ===========================================================================*/
/*
static int rt5616_init_reg[] = {
	0x08080002,	//0002 is the addr, 0808 is the value
	0x40000045,
	0x3F000066,
	0x50000080,
	0x08000082,
	0x8019008E,
};
*/

static int rt5616_init_reg[] = {
	0x08080002,	//0002 is the addr, 0808 is the value
	0x08080003,
	0x80000005,
	0x04C0000D,
	0x0808000F,
	0xAFAF0019,
	0x5C5C001C,
	0x0000001E,
	0x38200027,
	0x80800029,
	0x1250002A,
	0x0000003B,
	0x004F003C,
	0x2000003D,
	0x004F003E,
	0x40000045,
	0x0000004D,
	0x0000004E,
	0x0278004F,
	0x00000050,
	0x00000051,
	0x02780052,
	0xC8000053,
	0x98060061,
	0x88000062,
	0xF8FE0063,
	0x0A000064,
	0xCC000065,
	0x3F000066,
	0x003D006A,
	0x3600006C,
	0x80820070,
	0x00000073,
	0x0C000074,
	0x50000080,
	0x0E1C0081,
	0x08000082,
	0x0019008E,
	0x3100008F,
	0x2C000093,
	0x02000094,
	0x208000B0,
	0x000000B1,
	0x001100FA,
};

static uint16 nau8810_init_reg[][2] = {	
#ifdef QUEC_AT_CMD_AUDIO_SUPPORT
	{NAU8810_REG_POWER1,   			0x0110},
#else
	{NAU8810_REG_POWER1,   			0x011d},
#endif
	{NAU8810_REG_POWER2,   			0x0015},
	{NAU8810_REG_POWER3,   			0x00ED},
	{NAU8810_REG_IFACE,    			0x0118},
	{NAU8810_REG_CLOCK,    			0x000C},
	{NAU8810_REG_DAC,	 			0x0008},
	{NAU8810_REG_ADC,				0x0108},
	{NAU8810_REG_INPUT_SIGNAL,		0x0003},
	{NAU8810_REG_PGAGAIN,			0x0024},
	{NAU8810_REG_SPKMIX,			0x0001},
	{NAU8810_REG_MONOMIX,			0x0001},
	{NAU8810_REG_ADCBOOST,			0x0000},
};
/*static uint16 nau8810_init_reg[][2] = { 
	{NAU8810_REG_POWER1,			0x011d},
	{NAU8810_REG_POWER2,			0x0015},
	{NAU8810_REG_POWER3,			0x00ED},
	{NAU8810_REG_IFACE, 			0x0118},
	{NAU8810_REG_COMP,				0x0000},	
	{NAU8810_REG_CLOCK, 			0x000C},
	{NAU8810_REG_SMPLR, 			0x000a},
	{NAU8810_REG_DAC,				0x0008},
	{NAU8810_REG_DACGAIN,			0x00FF},
	{NAU8810_REG_ADC,				0x0108},
	{NAU8810_REG_ADCGAIN,			0x00FF},

	//equalizer
	{NAU8810_REG_EQ1,				0x0000},
	{NAU8810_REG_EQ2,				0x0000},
	{NAU8810_REG_EQ3,				0x0000},
	{NAU8810_REG_EQ4,				0x0000},
	{NAU8810_REG_EQ5,				0x0000},
	//dac limiter
	{NAU8810_REG_DACLIM1,			0x0032},
	{NAU8810_REG_DACLIM2,			0x000C},
	//notch filter
	{NAU8810_REG_NOTCH1,			0x0000},
	{NAU8810_REG_NOTCH2,			0x0000},
	{NAU8810_REG_NOTCH3,			0x0000},
	{NAU8810_REG_NOTCH4,			0x0000},
	//alc control
	{NAU8810_REG_ALC1,				0x0038},
	{NAU8810_REG_ALC2,				0x000B},
	{NAU8810_REG_ALC3,				0x0032},
	{NAU8810_REG_NOISEGATE, 		0x0000},
	//pll contrl
	{NAU8810_REG_PLLN,				0x0000},
	{NAU8810_REG_PLLK1, 			0x0000},
	{NAU8810_REG_PLLK2, 			0x0000},
	{NAU8810_REG_PLLK3, 			0x0000},
	
	//byp control
	{NAU8810_REG_ATTEN, 			0x0000},

	// input output mixer
	{NAU8810_REG_INPUT_SIGNAL,		0x0003},
	{NAU8810_REG_PGAGAIN,			0x0024},
	{NAU8810_REG_ADCBOOST,			0x0000},
	{NAU8810_REG_OUTPUT,			0x0002},
	{NAU8810_REG_SPKMIX,			0x0001},
	{NAU8810_REG_SPKGAIN,			0x0020},
	{NAU8810_REG_MONOMIX,			0x0001},

	{NAU8810_REG_POWER4,			0x0000},
	{0x48,			0x0006},
	{NAU8810_REG_AGCP2POUT, 		0x0005},
	{NAU8810_REG_AGCP2POUT, 		0x0005},
};
*/

#define RT5616_INIT_REG_LEN sizeof(rt5616_init_reg)/sizeof(rt5616_init_reg[0])
#define NAU8810_INIT_REG_LEN sizeof(nau8810_init_reg)/sizeof(nau8810_init_reg[0])

/*===========================================================================
 * Global/static Variable
 ===========================================================================*/
/* Save qdai config */
qdai_t g_qdai_cfg;

/* Current codec, 1-5616, 2-8810*/
static QUEC_AUDIO_CODEC_TYPE_E cur_codec_type = QUEC_AUDIO_CODEC_NONE;

/*===========================================================================
 * Extern
 ===========================================================================*/
extern int ACMAudioSet_BCLK_Type(int bclk_type);
//extern void ACMAudioDTMF_Start(int f1, int f2);
//extern void ACMAudioDTMF_Stop(void);
extern int POCVoice_FillRxPCM(short *pData, unsigned short Length);
extern int POCVoice_BindTxPCMHandler(POCTxPCMHandler_t);
extern int POCVoice_UnBindTxPCMHandler(POCTxPCMHandler_t);
//extern void codec_rt5616_enable_headphone(void);
//extern void codec_rt5616_enable_speaker(void);
extern void codec_i2c_write(void *data);
extern int ACMSetModemMaster(void);
#if defined(QUEC_FEATURE_1802S_AUDIO_WTTS_9257)
extern void ACMSetModemSlave(void);
#else
extern int ACMSetModemSlave(void);
#endif
static void quec_qdai_get_default(void);

static I2C_ReturnCode quec_rt5616_write_reg(uint8 RegAddr, uint16 RegData);
static I2C_ReturnCode quec_nau8810_write_reg(uint8 RegAddr, uint16 RegData);


/*===========================================================================
 * Function
 ===========================================================================*/

/*===========================================================================

FUNCTION quec_rt5616_init

DESCRIPTION
  init codec ALC5616

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
static void quec_rt5616_init(void)
{
	char i = 0;
	
	for (i = 0; i < RT5616_INIT_REG_LEN; i++)
	{
		//codec_i2c_write(&rt5616_init_reg[i]);
		quec_rt5616_write_reg(rt5616_init_reg[i]&0xFFFF, rt5616_init_reg[i]>>16);
	}
}

/*===========================================================================

FUNCTION quec_rt5616_read_reg

DESCRIPTION
  read api of codec ALC5616

DEPENDENCIES
  None

RETURN VALUE
  result of I2C operation

SIDE EFFECTS
  None
===========================================================================*/
static I2C_ReturnCode quec_rt5616_read_reg(uint8 RegAddr, uint16 *p_value)
{
	I2C_ReturnCode status = I2C_RC_NOT_OK;
	uint8 temp_buf[2];
	uint8 retry_count = 5;

	do 
    {
        status = quec_i2c_read(QUEC_AUDIO_IIC_CHANNEL, RT5616_I2C_SLAVE_ADDR, RegAddr, temp_buf, 2);
		if (status != I2C_RC_OK)
		{
            quec_audio_log("Error:[%dth] device[0x%x] addr[0x%x] failed", retry_count, RT5616_I2C_SLAVE_ADDR, RegAddr);
            uart_printf("Error:rt5616 [%dth] device[0x%x] addr[0x%x] failed\n", retry_count, RT5616_I2C_SLAVE_ADDR, RegAddr);
        }	
		else
        {
			*p_value = (((uint16)temp_buf[0]) << 8) | temp_buf[1];
			break;
		}
	} while (--retry_count);

	return status;
}

/*===========================================================================

FUNCTION quec_rt5616_write_reg

DESCRIPTION
  write api of codec ALC5616

DEPENDENCIES
  None

RETURN VALUE
  result of I2C operation

SIDE EFFECTS
  None
===========================================================================*/
static I2C_ReturnCode quec_rt5616_write_reg(uint8 RegAddr, uint16 RegData)
{
    I2C_ReturnCode status = I2C_RC_NOT_OK;
    uint8 param_data[3] = {0x00};
    uint8 retry_count = 5;

    param_data[0] = (uint8)((RegData >> 8) & 0xFF);
    param_data[1] = (uint8)(RegData & 0xff);

    do 
    {
        status = quec_i2c_write(QUEC_AUDIO_IIC_CHANNEL, RT5616_I2C_SLAVE_ADDR, RegAddr, param_data, 2);
        if (status != I2C_RC_OK)
        {
            quec_audio_log("Error:[%dth] device[0x%x] addr[0x%x] data[0x%x] failed", retry_count, RT5616_I2C_SLAVE_ADDR, RegAddr, RegData);
            uart_printf("Error:[%dth] device[0x%x] addr[0x%x] failed\n", retry_count, RT5616_I2C_SLAVE_ADDR, RegAddr);
        }        
        else 
        {
            break;
        }
    } while (--retry_count);

    return status;
}

/*===========================================================================
FUNCTION quec_nau8810_init

DESCRIPTION
  init codec NAU88C10

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
static void quec_nau8810_init(void)
{
	unsigned char i = 0;
	
	for (i = 0; i < NAU8810_INIT_REG_LEN; i++)
	{
		quec_nau8810_write_reg(nau8810_init_reg[i][0], nau8810_init_reg[i][1]);
	}
}

/*===========================================================================
FUNCTION quec_nau8810_read_reg

DESCRIPTION
  read api of codec NAU88C10

DEPENDENCIES
  None

RETURN VALUE
  result of I2C operation

SIDE EFFECTS
  None
===========================================================================*/
static I2C_ReturnCode quec_nau8810_read_reg(uint8 RegAddr, uint16 *p_value)
{
	I2C_ReturnCode status = I2C_RC_NOT_OK;
	uint8 temp_buf[2];
	uint8 retry_count = 5;
	RegAddr = (RegAddr << 1) & 0xFE;
	do 
    {
        status = quec_i2c_read(QUEC_AUDIO_IIC_CHANNEL, NAU8810_I2C_SLAVE_ADDR, RegAddr, temp_buf, 2);
		if (status != I2C_RC_OK)
		{
            quec_audio_log("Error:[%dth] device[0x%x] addr[0x%x] failed", retry_count, NAU8810_I2C_SLAVE_ADDR, RegAddr);
            uart_printf("Error:[%dth] device[0x%x] addr[0x%x] failed\n", retry_count, NAU8810_I2C_SLAVE_ADDR, RegAddr);
        }	
		else
        {
        	quec_audio_log("tempo=0x%x, temp1=0x%x\n", temp_buf[0], temp_buf[1]);
            uart_printf("tempo=0x%x, temp1=0x%x\n", temp_buf[0], temp_buf[1]);
			*p_value = (((uint16)temp_buf[0]) << 8) | temp_buf[1];
			break;
		}
	} while (--retry_count);

	return status;
}

/*===========================================================================
FUNCTION quec_nau8810_write_reg

DESCRIPTION
  write api of codec NAU88C10

DEPENDENCIES
  None

RETURN VALUE
  result of I2C operation

SIDE EFFECTS
  None
===========================================================================*/
static I2C_ReturnCode quec_nau8810_write_reg(uint8 RegAddr, uint16 RegData)
{
    I2C_ReturnCode status = I2C_RC_NOT_OK;
    uint8 param_data[3] = {0x00};
    uint8 retry_count = 5;

    //param_data[0] = ((RegAddr<<1) & 0xFE) | ((RegData >> 8) & 0x01);
    param_data[0] = (uint8)((RegData >> 8) & 0xFF);
    param_data[1] = (uint8)(RegData & 0xFF);
	RegAddr = (RegAddr << 1) & 0xFE;
    RegAddr = RegAddr|((RegData>>8)&0x01);
    param_data[0] = (uint8)(RegData & 0xFF);
	
    do 
    {
        status = quec_i2c_write(QUEC_AUDIO_IIC_CHANNEL, NAU8810_I2C_SLAVE_ADDR, RegAddr, param_data, 2);
        if (status != I2C_RC_OK)
        {
            quec_audio_log("Error:[%dth] device[0x%x] addr[0x%x] data[0x%x] failed", retry_count, NAU8810_I2C_SLAVE_ADDR, RegAddr, RegData);
            uart_printf("Error:[%dth] device[0x%x] addr[0x%x] failed\n", retry_count, NAU8810_I2C_SLAVE_ADDR, RegAddr);
        }        
        else 
        {
            break;
        }
    } while (--retry_count);

    return status;
}

/*===========================================================================
FUNCTION quec_audio_init

DESCRIPTION
  set bclk, get codec type, set dsp gain

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
#ifdef QUEC_AT_CMD_AUDIO_SUPPORT
#if QUEC_AUDIO_ACDB_SUPPORT 
extern bool quec_audio_gain_table_config(void);
#endif
bool quec_audio_init(void)
{
	uint16 val;
	I2C_ReturnCode status = I2C_RC_NOT_OK;
    int fat_ret = 0;
	unsigned char clvl_val = 0;
	uint32 vol_set = 0;
//	AudioHAL_AifBindCodec_CB((AUDIOHAL_SpeakerPA_T)quec_audio_codec_onff_callback); //we need ctrl codec
    //ql_onoff_earphone();
#if QUEC_AUDIO_ACDB_SUPPORT
//#if 0
	CPUartLogPrint("quec_audio_gain_table_config!!!",FALSE);

	fat_ret=quec_audio_gain_table_config();
	if(FALSE==fat_ret)
	{
		quec_audio_log("audio gain config error\r\n");
	}

// 获取保存的音量并设置
	quec_audio_clvl_read(&clvl_val);
	vol_set=(clvl_val>=5) ? 11  : (clvl_val<<1);
    AudioHAL_AifSetVolume(vol_set);
#endif
    quec_i2c_init(QUEC_AUDIO_IIC_CHANNEL, 0);//IIC初始化
    
    fat_ret = quec_qdai_get(&g_qdai_cfg);
    if (fat_ret != QUEC_FAT_SUCCESS)
    {
        quec_qdai_get_default();
    }

	if (g_qdai_cfg.clock > 0)
    {
    	quec_audio_log("audio_bitclock_val=%d\n", g_qdai_cfg.clock);
		fat_ret=AudioHAL_sspaSetBCLKType(g_qdai_cfg.clock - 1);
		if(NULL != fat_ret)
		{
			quec_audio_log("bitclk set error %d\r\n",fat_ret);
		}
    }
    else
    {
    	AudioHAL_sspaSetBCLKType(g_qdai_cfg.clock);
    }

	if(g_qdai_cfg.sample==SAMPLE_8K)
	{
		AudioHAL_AifUseSSPA_NB(); //8k			
	}
	else if(g_qdai_cfg.sample==SAMPLE_16K)
	{
		AudioHAL_AifUseSSPA();	  //16k 
	}else if(g_qdai_cfg.sample==SAMPLE_32K)
	{
		AudioHAL_AifUseSSPA_32K();//32k
	}else
	{
		quec_audio_log("not find sample");
	}

	AcmSetPCMRate(0);
	if(IO_DIGITAL_PCM_OUTPUT == g_qdai_cfg.io)
	{
		AudioHAL_sspaSetI2S(g_qdai_cfg.fsync);
		return TRUE;
	}
#if QUEC_AUDIO_CODEC_SW_SUPPORT
	{
		extern bool quec_audio_codec_init(void);
		if(quec_audio_codec_init())
		{
#if QUEC_AUDIO_HSDet_SUPPORT
			quec_audio_hsdet_int();
#endif
			CPUartLogPrint("use built-in codec!!!",FALSE);
			quec_audio_log("use built-in codec\n");
			return TRUE;
		}
	}
#endif

	if(g_qdai_cfg.sample==SAMPLE_8K)
	{
		AudioHAL_AifUseSSPA_NB(); //8k			
	}
	else
	{
		AudioHAL_AifUseSSPA();    //16k	
	}	
	CPUartLogPrint("quec_rt5616_read_reg!!!",FALSE);
	status = quec_rt5616_read_reg(0xFE, &val);
	quec_audio_log("ALC5616, status=%d, val=%d", status, val);
    uart_printf("ALC5616, status=%d, val=0x%x\n", status, val);
	if ((status == I2C_RC_OK) && (0x10EC == val)) 
	{
		quec_rt5616_init();
        cur_codec_type = QUEC_AUDIO_CODEC_IS_5616;
		CPUartLogPrint("quec_rt5616_init!!!",FALSE);
	}
	else if (I2C_RC_OK == quec_nau8810_read_reg(NAU8810_REG_I2C_DEVICEID, &val))
	{
		quec_audio_log("NAU88C10, val=%d", val);
        uart_printf("NAU88C10, val=0x%x\n", val);
		if (0x1A == val)
		{							
			quec_nau8810_init();
			/*
			{
				int i=0,val_data;
				for(i;i<=0x4f;i++)
				{	
					quec_nau8810_read_reg(i,&val_data);
					uart_printf("addr=0x%x,val=0x%x\r\n",i,val_data);
				}
			}*/
            cur_codec_type = QUEC_AUDIO_CODEC_IS_8810;
			uart_printf("NAU88C10_init\r\n");
		}
	}	
	/* Fitz 20200324: add internal codec support */ 
    else
    {
        quec_set_audio_path_to_handset();
		quec_set_audio_mode(0);
		AudioHAL_AifUseInternalCodec();
        quec_audio_log("use internal codec");
        uart_printf("use internal codec\n");
    }
	
#if defined(__QUEC_OEM_VER_NL__)
    /* For NL, initial dsp gain is the max 12dB. */
    //extern void ACMSetDspOutGain(signed char dB);
    //ACMSetDspOutGain(12);
#endif
    
	return TRUE;	
}	
#endif
/*===========================================================================

FUNCTION quec_audio_iic_read

DESCRIPTION
  IIC read

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
I2C_ReturnCode quec_audio_iic_read(uint8 dev_addr, uint8 reg_addr, uint8 size, uint16 *p_val)
{
    I2C_ReturnCode ret = I2C_RC_NOT_OK;

    /* 5616 */
    if (0x1B == dev_addr)
    {
        ret = quec_rt5616_read_reg(reg_addr, p_val);
    }
    /* 8810 */
    else if (0x1A == dev_addr)
    {
        ret = quec_nau8810_read_reg(reg_addr, p_val);
    }

    return ret;
}

/*===========================================================================

FUNCTION quec_audio_iic_write

DESCRIPTION
  IIC write

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
I2C_ReturnCode quec_audio_iic_write(uint8 dev_addr, uint8 reg_addr, uint8 size, uint16 val)
{
    I2C_ReturnCode ret = I2C_RC_NOT_OK;

    /* 5616 */
    if (0x1B == dev_addr)
    {
        ret = quec_rt5616_write_reg(reg_addr, val);
    }
    /* 8810 */
    else if (0x1A == dev_addr)
    {
        ret = quec_nau8810_write_reg(reg_addr, val);
    }

    return ret;
}

/*===========================================================================

FUNCTION quec_qdai_set

DESCRIPTION
  save QDAI config to NV

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
int quec_qdai_set(void)
{
    int fat_ret = QUEC_FAT_FAILED;
    
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgAudioset QuecAudioCfg = {0};
	/* relaod params */
	if(QUEC_SUCCESS != Quec_SysItemPara_Item_get(QUEC_AUDIO_SET, &QuecAudioCfg, sizeof(QuecAudioCfg)))
	{
		quec_audio_log("Failed:Quec_SysItemPara_Item_get QUEC_CUST_FEATURE_CFG"); 
	}
	/* save params */
	QuecAudioCfg.qdai_set = g_qdai_cfg;
	fat_ret = Quec_SysItemPara_Item_set(QUEC_AUDIO_SET, &QuecAudioCfg, sizeof(QuecAudioCfg));
#else
	fat_ret = quectel_nv_fat_write(QUEC_NV_QDAI_CFG, &g_qdai_cfg, sizeof(qdai_t));
#endif

    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        quec_audio_log("quec_qdai_set err=%d", fat_ret);    
    }

    return fat_ret;
}

/*===========================================================================

FUNCTION quec_qdai_get

DESCRIPTION
  read QDAI config from NV

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
int quec_qdai_get(qdai_t *qdai_cfg)
{
    int fat_ret = QUEC_FAT_FAILED;
    
    if (qdai_cfg == NULL)
    {
        return fat_ret;        
    }

#ifdef QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgAudioset QuecAudioCfg = {0};
	fat_ret = Quec_SysItemPara_Item_get(QUEC_AUDIO_SET, &QuecAudioCfg, sizeof(QuecAudioCfg));
	if(fat_ret == QUEC_SUCCESS){
		memcpy(qdai_cfg,&(QuecAudioCfg.qdai_set),sizeof(qdai_t));
	}
#else
	fat_ret = quectel_nv_fat_read(QUEC_NV_QDAI_CFG, qdai_cfg, sizeof(qdai_t));
#endif
	RTI_LOG("mode = %d mode = %d",g_qdai_cfg.mode,QuecAudioCfg.qdai_set.mode);
    if (QUEC_FAT_SUCCESS != fat_ret)
    {
        quec_audio_log("quec_qdai_get err=%d", fat_ret);    
    }

    return fat_ret; 
}

/*===========================================================================
FUNCTION quec_qdai_get_default

DESCRIPTION
  get QDAI default config

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
static void quec_qdai_get_default(void)
{
    g_qdai_cfg.io = IO_ANALOG_OUTPUT_ALC5616;
    g_qdai_cfg.mode = MASTER_MODE;
    g_qdai_cfg.fsync = PRIMARY_MODE_SHORT_SYNC;
    /* By default set 2048K */
    g_qdai_cfg.clock = CLK_2048K;
    g_qdai_cfg.format = FORMAT_16_BIT_LINEAR;
    g_qdai_cfg.sample = SAMPLE_8K;
    g_qdai_cfg.num_slots = 1;
    g_qdai_cfg.slot_mapping = 1;
}

/*===========================================================================
FUNCTION quec_get_current_codec_type

DESCRIPTION
  get current codec type

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
unsigned char quec_get_current_codec_type(void)
{  
    quec_audio_log("current codec type is %d", cur_codec_type);    
    return cur_codec_type;
}

/*===========================================================================
FUNCTION quec_set_audio_path_handset

DESCRIPTION
  set audio path to handset/receiver

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_set_audio_path_to_handset(void)
{
	AUDIOHAL_AIF_DEVICE_CFG_T config;
	AUDIOHAL_AIF_LEVEL_T level;
	level.micLevel = AUDIOHAL_MIC_ENABLE;
	level.spkLevel = AUDIOHAL_SPK_VOL_7;
	level.toneLevel = AUDIOHAL_TONE_M3DB;
	level.sideLevel = AUDIOHAL_SIDE_VOL_7;
	config.spkSel = AUDIOHAL_SPK_RECEIVER;
	config.micSel = AUDIOHAL_MIC_LOUDSPEAKER;
	config.spkType = AUDIOHAL_SPEAKER_STEREO;
	config.level = &level;
	
	AudioHAL_AifOpen(AUDIOHAL_ITF_RECEIVER, &config);
	//AudioHAL_AifSwitch(AUDIOHAL_ITF_RECEIVER);
}

/*===========================================================================
FUNCTION ql_set_audio_path_headset

DESCRIPTION
  set audio path to headset/earphone

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_set_audio_path_to_headset(void)
{
	AUDIOHAL_AIF_DEVICE_CFG_T config;
	AUDIOHAL_AIF_LEVEL_T level;
	level.micLevel = AUDIOHAL_MIC_ENABLE;
	level.spkLevel = AUDIOHAL_SPK_VOL_7;
	level.toneLevel = AUDIOHAL_TONE_M3DB;
	level.sideLevel = AUDIOHAL_SIDE_VOL_7;
	config.spkSel = AUDIOHAL_SPK_EARPIECE;
	config.micSel = AUDIOHAL_MIC_EARPIECE;
	config.spkType = AUDIOHAL_SPEAKER_STEREO;
	config.level = &level;
    
	AudioHAL_AifOpen(AUDIOHAL_ITF_EARPIECE, &config);
	//AudioHAL_AifSwitch(AUDIOHAL_ITF_EARPIECE);
/*
#if QUEC_AUDIO_HSDet_SUPPORT
extern uint8 quec_get_hsdet_status(void);
	if(!quec_get_hsdet_status()) //use in-codec and use headmode and close headhsdet
	{
		AudioHAL_NeedChargePump(1);
	}
#endif
*/
}

/*===========================================================================
FUNCTION quec_set_audio_path_to_speaker

DESCRIPTION
  set audio path to speaker

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_set_audio_path_to_speaker(void)
{
	AUDIOHAL_AIF_DEVICE_CFG_T config;
	AUDIOHAL_AIF_LEVEL_T level;
	level.micLevel = AUDIOHAL_MIC_ENABLE;
	level.spkLevel = AUDIOHAL_SPK_VOL_7;
	level.toneLevel = AUDIOHAL_TONE_M3DB;
	level.sideLevel = AUDIOHAL_SIDE_VOL_7;
	config.spkSel = AUDIOHAL_SPK_LOUDSPEAKER;
	config.micSel = AUDIOHAL_MIC_LOUDSPEAKER;
	config.spkType = AUDIOHAL_SPEAKER_STEREO;
	config.level = &level;
	
	AudioHAL_AifOpen(AUDIOHAL_ITF_LOUDSPEAKER, &config);
	//AudioHAL_AifSwitch(AUDIOHAL_ITF_LOUDSPEAKER);
}

/*===========================================================================
FUNCTION quec_set_audio_path_to_speaker

DESCRIPTION
  when power on, use auto set audio path by default.
  when earphone is not exist ---> audio path is speaker + phone'MIC
  when earphone is exist     ---> audio path is earphone + earphone'MIC

  when use AudioHAL_AifOpen(...) to change audio path, you can use AudioHAL_AifClose()
  to resume auto set audio path.
  
DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void quec_auto_set_audio_path(void)
{
    AudioHAL_AifClose();
}

#ifdef QUEC_AT_CMD_AUDIO_SUPPORT
void quec_set_8810_power_reg_on(void)
{
	if(cur_codec_type == QUEC_AUDIO_CODEC_IS_8810) {
		quec_nau8810_write_reg(0x01, 0x11d);
	}
}

void quec_set_8810_power_reg_off(void)
{
	if(cur_codec_type == QUEC_AUDIO_CODEC_IS_8810) {
		quec_nau8810_write_reg(0x01, 0x110);
	}
}
#endif

#endif

#endif /*MIN_SYS*/

