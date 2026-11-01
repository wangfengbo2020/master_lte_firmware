/**  @file
  quec_audio.h

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


#ifndef _QUEC_AUDIO_H_
#define _QUEC_AUDIO_H_

/*> include header files here*/
#include "quec_include.h"
#include "quec_production_cfg.h"
#include "quec_cust_feature.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QUEC_AUDIO_SUPPORT


#if defined (__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_LF__) || defined (__QUECTEL_PROJECT_EC600MCN_CC__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_GC__) || defined (__QUECTEL_PROJECT_EC600MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_MC__) || defined (__QUECTEL_PROJECT_EC100MCN_LA__)\
	|| defined (__QUECTEL_PROJECT_EC600NCN_AC__) || defined (__QUECTEL_PROJECT_EC600KCN_CC__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CC__) || defined (__QUECTEL_PROJECT_EC600MCN_NC__)\
	|| defined (__QUECTEL_PROJECT_EG800KCN_GC__) || defined (__QUECTEL_PROJECT_EC600MEU_LA__)\
	|| defined (__QUECTEL_PROJECT_EG800KEU_CC__) || defined (__QUECTEL_PROJECT_EC800KCN_CZ__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_LC__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EG800PCN_00LA__)|| defined (__QUECTEL_PROJECT_EC800KCN_MC__) \
	|| defined (__QUECTEL_PROJECT_EC600KCN_MC__) || defined (__QUECTEL_PROJECT_EG800KLA_CC__)	\
	|| defined (__QUECTEL_PROJECT_EC800KCN_MD__) || defined (__QUECTEL_PROJECT_EC600MLA_LA__) \
	|| defined (__QUECTEL_PROJECT_EC800KLA_LC__) || defined (__QUECTEL_PROJECT_EC800KEU_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)
	
#define QUEC_AUDIO_IIC_CHANNEL     1
//#include "i2c.h"

#elif defined ( __QUECTEL_PROJECT_EC800MCN_LA__ ) || defined (__QUECTEL_PROJECT_EC800MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_LC__) || defined (__QUECTEL_PROJECT_EC800MCN_LF__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_GC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GM__) || defined (__QUECTEL_PROJECT_EC800MCN_MC__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_CC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_NC__) || defined (__QUECTEL_PROJECT_EC800MCN_GD__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_LA__) || defined (__QUECTEL_PROJECT_EC200MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_GB__) || defined (__QUECTEL_PROJECT_EC200MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_LE__)|| defined (__QUECTEL_PROJECT_EC200MCN_LF__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__) \
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG810MLA_LC__)


#define QUEC_AUDIO_IIC_CHANNEL     0

#else
#error "Please configure the project"
#endif

/*========================================================================
 *  Macro Definition
 *========================================================================*/
#define NAU8810_REG_RESET		0x00
#define NAU8810_REG_POWER1		0x01
#define NAU8810_REG_POWER2		0x02
#define NAU8810_REG_POWER3		0x03
#define NAU8810_REG_IFACE		0x04
#define NAU8810_REG_COMP		0x05
#define NAU8810_REG_CLOCK		0x06
#define NAU8810_REG_SMPLR		0x07
#define NAU8810_REG_DAC		0x0A
#define NAU8810_REG_DACGAIN		0x0B
#define NAU8810_REG_ADC		0x0E
#define NAU8810_REG_ADCGAIN		0x0F
#define NAU8810_REG_EQ1		0x12
#define NAU8810_REG_EQ2		0x13
#define NAU8810_REG_EQ3		0x14
#define NAU8810_REG_EQ4		0x15
#define NAU8810_REG_EQ5		0x16
#define NAU8810_REG_DACLIM1		0x18
#define NAU8810_REG_DACLIM2		0x19
#define NAU8810_REG_NOTCH1		0x1B
#define NAU8810_REG_NOTCH2		0x1C
#define NAU8810_REG_NOTCH3		0x1D
#define NAU8810_REG_NOTCH4		0x1E
#define NAU8810_REG_ALC1		0x20
#define NAU8810_REG_ALC2		0x21
#define NAU8810_REG_ALC3		0x22
#define NAU8810_REG_NOISEGATE		0x23
#define NAU8810_REG_PLLN		0x24
#define NAU8810_REG_PLLK1		0x25
#define NAU8810_REG_PLLK2		0x26
#define NAU8810_REG_PLLK3		0x27
#define NAU8810_REG_ATTEN		0x28
#define NAU8810_REG_INPUT_SIGNAL	0x2C
#define NAU8810_REG_PGAGAIN		0x2D
#define NAU8810_REG_ADCBOOST		0x2F
#define NAU8810_REG_OUTPUT		0x31
#define NAU8810_REG_SPKMIX		0x32
#define NAU8810_REG_SPKGAIN		0x36
#define NAU8810_REG_MONOMIX		0x38
#define NAU8810_REG_POWER4		0x3A
#define NAU8810_REG_TSLOTCTL1		0x3B
#define NAU8810_REG_TSLOTCTL2		0x3C
#define NAU8810_REG_DEVICE_REVID	0x3E
#define NAU8810_REG_I2C_DEVICEID	0x3F
#define NAU8810_REG_ADDITIONID	0x40
#define NAU8810_REG_RESERVE		0x41
#define NAU8810_REG_OUTCTL		0x45
#define NAU8810_REG_ALC1ENHAN1	0x46
#define NAU8810_REG_ALC1ENHAN2	0x47
#define NAU8810_REG_MISCCTL		0x49
#define NAU8810_REG_OUTTIEOFF		0x4B
#define NAU8810_REG_AGCP2POUT	0x4C
#define NAU8810_REG_AGCPOUT		0x4D
#define NAU8810_REG_AMTCTL		0x4E
#define NAU8810_REG_OUTTIEOFFMAN	0x4F
#define NAU8810_REG_MAX		NAU8810_REG_OUTTIEOFFMAN


/*===========================================================================
 * struct/enum definition
 ===========================================================================*/

/* defined for current codec type */
typedef enum
{
    QUEC_AUDIO_CODEC_NONE = 0,
    QUEC_AUDIO_CODEC_IS_5616 = 1,
    QUEC_AUDIO_CODEC_IS_8810 = 2, 
}QUEC_AUDIO_CODEC_TYPE_E;

/* QDAI IO type */
typedef enum
{
	IO_DIGITAL_PCM_OUTPUT = 1,
	IO_ANALOG_OUTPUT_NAU8814 = 2,
	IO_ANALOG_OUTPUT_ALC5616 = 3,
	IO_ANALOG_OUTPUT_TLV320_AIC3104 = 5,
}QDAI_IO_TYPE;

/* QDAI mode */
typedef enum
{
	MASTER_MODE = 0,
	SLAVE_MODE = 1,
}QDAI_MODE_TYPE;

/* QDAI FSYNC */
typedef enum
{
	PRIMARY_MODE_SHORT_SYNC = 0,
	AUXILIARY_MODE_LONG_SYNC = 1,
}QDAI_FSYNC_TYPE;

/* QDAI clock */
typedef enum
{
	CLK_128K = 0,
	CLK_256K = 1,
	CLK_512K = 2,
	CLK_1024K = 3,
	CLK_2048K = 4,
	CLK_4096K = 5,
}QDAI_CLOCK_TYPE;

/* QDAI format */
typedef enum
{
	FORMAT_16_BIT_LINEAR = 0,
	FORMAT_8_BIT_A_LAW = 1,
	FORMAT_8_BIT_U_LAW = 2,
}QDAI_FORMAT_TYPE;

/* QDAI sample */
typedef enum
{
	SAMPLE_8K  = 0,
	SAMPLE_16K = 1,
	SAMPLE_32K = 3,
	SAMPLE_48K = 5,
}QDAI_SAMPLE_TYPE;

/* QDAI config structure */
typedef struct qdai
{
	char io;
	char mode;
	char fsync;
    char clock;
	char format;
	char sample;
	char num_slots;
	char slot_mapping;
}qdai_t;

typedef struct  HSDet_Status
{
	UINT8 contorl;
	UINT8 hsdet_type;
}HSDet_Status_Info;

typedef struct {
	ST_quecComInfo quecComInfo;
	HSDet_Status_Info HSDet_Status_set;
	qdai_t qdai_set;
	unsigned char quec_clvl_cur;
	char   quec_audmod;
	char   reserved[14];
}ST_quecCfgAudioset;

/*===========================================================================
 * Global/static Variable
 ===========================================================================*/
extern qdai_t g_qdai_cfg;

/*===========================================================================
 * Extern
 ===========================================================================*/
extern bool quec_audio_init(void);
extern int quec_qdai_set(void);
extern int quec_qdai_get(qdai_t *qdai_cfg);
extern unsigned char quec_get_current_codec_type(void);
extern void quec_set_audio_path_to_handset(void);
extern void quec_set_audio_path_to_headset(void);
extern void quec_set_audio_path_to_speaker(void);
extern void AudioHAL_AifUseSSPA_32K(void);
#endif

#ifdef __cplusplus
} /*"C" */
#endif

#endif




