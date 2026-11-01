/*================================================================
  Copyright (c) 2022, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#ifndef _QL_CPU_FRE_H
#define _QL_CPU_FRE_H

#ifdef QUEC_DUMP_NVM_SUPPORT
typedef struct
{
    char fname[16];
    unsigned char* EEbuf;
    unsigned int buflen;    
}QL_DUMP_BIN_FILE;
#endif
typedef enum QL_CPU_FREQUENCY_PP_ENUM
{
	QL_PP1 = 1,//312M
	QL_PP2,//416M
	QL_PP3,//499M
	QL_PP4,//624M
	QL_PP5,//832M
}QL_CPU_FREQUENCY_PP_E;

/*========================================================================
 *  Fias Definition 2021.10.21  //about set ymodem_dump
 *========================================================================*/
typedef enum YMODEM_DUMP_ENUM
{
	YMODEM_CLOSE,
	YMODEM_OPEN,
}YMODEM_DUMP_E;

typedef void(*ql_dump_cb)(void);

int ql_cpu_fre_set(unsigned int cpu_fre);

unsigned int ql_cpu_fre_get(void);

unsigned int ql_geu_random_number(void);

unsigned int ql_pseudo_random_number(void);  
#ifdef QUEC_DUMP_NVM_SUPPORT
int ql_get_dump_cnt(void);
int ql_get_dump_file(QL_DUMP_BIN_FILE* EEbuf,unsigned int EEbufnum);
int ql_get_dsp_dump_file(char* buf,unsigned int len);
int ql_get_dsp_dump_len(void);
void ql_flash_save_dump_enable(unsigned char EnableFlag);
int ql_del_dump_file(void);
int ql_clean_dump_cnt(void);

const char*  ql_asr_property_get(const char *name);
int ql_asr_property_get_buffer(const char *name, char *buffer);


#endif
int ql_set_dump_cb(ql_dump_cb dump_cb);
int ql_get_dump_cnt(void);
/*Fias 2021/10/21  在app侧增加可进入ymodem_dump 的api接口 */
int ql_set_ymodem_cfg(unsigned char flag);

#endif
