/**  @file
  quec_atcmd_network.h

  @brief
  This file is used to define the network at command handler for different Quectel Project.

*/

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
01/21/2019		  Tery	     add at+qoem="landipin" function
11/09/2018        Jensen     Init version
=================================================================*/


#ifndef _QUEC_ATCMD_NETWORK_H
#define _QUEC_ATCMD_NETWORK_H

/*> include header files here*/

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quec_cust_feature.h"
#include "quec_common.h"
#include "quec_atcmd_param.h"
#include "quec_at_common.h"
#include "ci_ps.h"
#include "telatci.h"
#if defined(__QUEC_OEM_VER_LT__)
#include "quec_rtos.h"
#endif

/*========================================================================
 *  Type Definition
 *========================================================================*/
 
#ifdef QUECTEL_NETWORK_SUPPORT


typedef enum
{
  QUEC_NETMODE_NONE = 0,
    
  QUEC_NETMODE_GSM = 1,
  QUEC_NETMODE_WCDMA = 2,
  QUEC_NETMODE_LTE = 3,
  
  //OTHERS

  QUEC_NETMODE_MAX,
}quec_network_mode_type;
	typedef struct
	{
		 char act[10] ;
		 char plmn[10] ;
		 char band_description[20] ;
		 UINT32 active_channel;
		 UINT8 service_domain;// 0:cs only 1:ps only 2:cs+ps
		 UINT8 roam_status;//0:home 1:roaming
		 UINT8 sim_state;//0:valid 1:invalid 2:not_insert
	}Quec_qnwinfo_type;


	typedef struct
	{
		 UINT8 pdp_act_status;  // 1:act 0:deact
	}Quec_pdp_act_status_type;

	
	//used for distinguish diffrent action when use the same ASR API
	typedef enum {
	    QNWINFO_GET=0,          // qnwinfo
	    QENG_SERVINGCELL_GET,   //servingcell
	    QENG_NEIGHBOURCELL_GET,  //neighbourcell
#ifndef ENABLE_DM_LTEONLY 
	    QENG_3GCOMM_GET,              //3gcomm
	    QSMONC,                   //SMONC
#endif
#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
		MCELL,
#endif
	#ifdef QUEC_ENGINEER_OUTPUT
		QENG_ALL_INFO,
	#endif
#ifdef QUECTEL_CELL
       CELL_GET,       //neighbourcell get cellid
#endif
#ifdef QUEC_RSRP_SUPPORT
       RSRP_GET,
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
       QCELLINFOEX_GET,
#endif
#ifdef QUEC_CCED_SUPPORT
	   QUEC_CCED_S_GET,
	   QUEC_CCED_NB_GET,
#endif
#ifdef QUEC_QNWCFG_SUPPORT
		QCQI_MCS_GET,
#endif

	    //add new here 
	} quectel_eng_mode_query_e_type;

	typedef struct
	{
		 UINT8 mode;   //0,1,2
		 UINT8 bfr;    //0,1
	}Quec_cgerep_type;

	//used to distinguish diffrent action of qeng command
	typedef enum
	{
	   QUECTEL_QENG_SCELL_MODE = 0,
	   QUECTEL_QENG_NCELL_MODE,
	   QUECTEL_QENG_3G_USUAL_INFO,
	   //add new here 
	   QUECTEL_QENG_MAX_MODE
	}quectel_qeng_query_e_type;
	   
	#define SCELL_VAL_BUF_MAX 20
	
	typedef struct
	{
		char state[10] ;
		char tdd_fdd[5] ;
		UINT16 mcc ;
		UINT16 mnc ;
		UINT16  pci;
   	    UINT32  cid;
        UINT16  tac;
        UINT32  earfcn;
		UINT8 band;
		UINT8 ul_bandwidth;
		UINT8 dl_bandwidth;
		INT16 rsrp;
		INT16 rsrq;
		INT16 rssi;
		INT16 sinr;
		INT16 srxlev;
	}Quec_LTE_scell_type;

	typedef struct
	{
		UINT64 u64PrevRxCnt; //which is used to record the rx cnt every time after power on and reset to 0
		UINT64 u64TotalRxCnt;
		UINT64 u64PrevTxCnt; //which is used to record the tx cnt every time after power on and reset to 0
		UINT64 u64TotalTxCnt; 
	}QuecDataCntInfoType;

	typedef struct
	{
		UINT8 net_mode; //which is used to record the support mode
		UINT8 pref_mode; //which is used to record the prefer  mode
		UINT8 update_flag; //which is used to record if it the mode had been update
		UINT8 gprsattach;
		UINT32 gsm_band;
		UINT32 umts_band;
		UINT32 lte_band_h;
		UINT32 lte_band_l;
		UINT32 lte_band_ext;
		UINT8 service_domain;
		UINT8 roamservice;
		UINT8 operation;
        UINT8 atp_index;
	}QuecNetModeCfgType;
#ifdef QUECTEL_AT_RFTEST_SUPPORT
	typedef struct tx_band_label_s {
		quec_network_mode_type 	mode;
		char	*name;
		UINT32   band;
		UINT32   tx_chanel_min;
		UINT32 	 tx_chanel_max;
		UINT32   rx_chanel_min;
		UINT32 	 rx_chanel_max;
	  } tx_band_label_type;
	  
	  typedef struct  quec_rftestmode_param{
			  quec_network_mode_type  mode;
			  UINT8   tx_enable;
			  UINT8   rx_enable;
			} quec_rftestmode_param_type;

#define QUEC_MAX_TX_POWER 2047
#define QUEC_MIN_TX_POWER 0

#define QUEC_MAX_RX_POWER 2047
#define QUEC_MIN_RX_POWER 0
#endif

#ifdef QUEC_POWER_BACKOFF_SUPPORT
#define QUEC_MAX_POWER_BACKOFF 20
#define QUEC_MIN_POWER_BACKOFF 0
	typedef enum
	{
	    QUEC_PWR_BACKOFF_NONE = 0,
		QUEC_PWR_BACKOFF_GSM900,
		QUEC_PWR_BACKOFF_GSM850,
		QUEC_PWR_BACKOFF_GSM1800,
		QUEC_PWR_BACKOFF_GSM1900,
		QUEC_PWR_BACKOFF_LTE_BANDx,
		QUEC_PWR_BACKOFF_MAX
	} quec_pwr_backoff_mode;
   typedef struct  
	{
		quec_pwr_backoff_mode 	mode;
		char	*band_name;
	} quec_pwr_backoff_label_type;

#endif
/*========================================================================
 *  Enumeration Definition
 *========================================================================*/
//typedef struct
//{
//	UINT16 backg_scan_num; //which is used to save background freq scan cache num
//	UINT16 foreg_scan_num; //which is used to save foreground freq scan cache num
//}QuecFreqScanType;

/*========================================================================
 *  Macro Definition
 *========================================================================*/

#define QUEC_AT_CTZRVALUE "quec_at_ctzr.value"
#define QUEC_AT_GDCNTVALUE "quec_at_qgdcnt.value"
#define QUEC_AT_QOEM "quec_at_qoem.value"
#define QUEC_AT_MODE_BACKUP  "quec_at_mode_backup.value"

#define QUEC_QENG_RESBUFLEN_MIN  1024
#define QUEC_QENG_RESBUFLEN_MAX  16384

#define QUEC_MIN_AUTO_GDCNT_INTERVAL 30*1000 //unit: second
#define QUEC_MAX_AUTO_GDCNT_INTERVAL 65535*1000 //unit: second
#define QUEC_DEFAULT_AUTO_GDCNT_INTERVAL 0

#define QUEC_INVALID_C_VALUE 0x7FFFFFFF
#define QUEC_MAX_SMONC_ITEMS 6+1

#ifdef QUECTEL_CSQ_TYPE
 /* Signal level conversion result codes */
#define RSSI_TOOLO_CODE   0
#define RSSI_TOOHI_CODE   31
#define RSSI_UNKNOWN_CODE 99
 /*宝蓝csq 门限值 定位重启问题*/
#define RSSI_TOTHRESHOLD_CODE 10
#define RSSI_OFFSET_6       6
#define RSSI_OFFSET_4       4
 /* RSSI range conversion */
#define RSSI_MIN        51   /* per 3GPP 27.007  (negative value) */
#define RSSI_MAX        113  /* per 3GPP 27.007  (negative value) */
#define RSSI_NO_SIGNAL  125  /* from CM */
#define RSSI_OFFSET     182.26
#define RSSI_SLOPE      (-100.0/62.0)
#endif

#ifdef 	QUECTEL_NETWORK_SUPPORT
    //±|à?csq issue
    typedef enum
    {
        QUEC_RSSI_NET_NO_SERV = 12,
        QUEC_RSSI_CSQ_5 = 14,
        QUEC_RSSI_CSQ_8 = 16,
        QUEC_RSSI_CSQ_11 = 20,
        QUEC_RSSI_CSQ_MAX
    }quec_rssi_2_csq_e_t;
#endif


#if QUEC_DUAL_SIM_SUPPORT
	extern Quec_qnwinfo_type quec_qnwinfo[2];
	extern Quec_cgerep_type cgerep_info[2];
#else
	extern Quec_qnwinfo_type quec_qnwinfo;
	extern Quec_cgerep_type cgerep_info;
#endif
	extern UINT64 network_infor_bitmsk;	
	extern UINT8 ctzr_reporting;
	extern int qlts_mode; 
	extern char *quec_QengResBuf;
	extern UINT32 quec_QengResDataLen;
	extern UINT32 quec_QengResBufLen;
	extern QuecDataCntInfoType  QuecDataCntInfo;
	extern QuecNetModeCfgType  QuecNetModeCfg;
	extern Quec_pdp_act_status_type 	quec_pdp_act_state[CI_PS_MAX_CID];
	extern UINT8 quec_qcsq_report_flag;
	extern void quec_qeng_get_currrent_state(char * sate);
	extern UINT8 quec_act_asr2quec(UINT8 asr_act);
	extern UINT8 quec_regstatus_asr2quec(UINT8 asr_status, uint8 need_attach);
	extern UINT8 quec_get_regstatus(uint8 need_attach);
	extern UINT8 quec_get_ps_regstatus(void);
	extern quec_network_mode_type quec_get_current_rat(uint8 need_attach);
	extern QuecOSStatus Quectel_GDCNTSaveParamToNV(void);
	extern void quec_cesq_2quec_csq(void * netquality_info,INT16 * rssi,INT16 * ber);
	extern int quec_update_mode_pref(QuecNetModeCfgType *p_quec_net_cfg);
	extern UINT8 quec_report_creg(char * report_buf,UINT32 reqHandle);
	extern UINT8 quec_report_cgreg(char * report_buf,UINT32 reqHandle);
	extern UINT8 quec_report_cereg(char * report_buf,UINT32 reqHandle);
	extern UINT8 quec_report_qcsq(UINT8 force_report,char * report_buf);
    extern void quec_dual_nw_reoprt(char *src_str,UINT16 str_tollen,UINT32 reqHandle);
#endif

#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2019/01/21 add the qindcfg="act"
    extern UINT8 quec_ratchg_indication(UINT8 forece_report,UINT8 new_rat,UINT8 new_reg_status,char * new_rat_string_buf);
#endif 


#define LANDI_VAL_BUF_MAX     20

#define GET_VALID_VAL(buf,val)  do{  \
                                        if ( (val != (typeof(val))0) && (val != (typeof(val))-1))   \
                                        {   \
                                           sprintf(buf,"%04X",(uint32)val);\
                                        }\
                                        else    \
                                        {   \
                                            sprintf(buf,"%s","-"); \
                                        }   \
                                      }while(0)


#ifdef __QUEC_OEM_VER_LD__

typedef enum
{
	QUECTEL_QOEM_ITEM_INVALID = -1,
#ifdef __QUEC_OEM_VER_LD__
    QUECTEL_QOEM_ITEM_LANDI = 0, 
    QUECTEL_QOEM_ITEM_LANDI_PIN ,
#endif
	QUECTEL_QOEM_ITEM_MAX
}QOEM_ITEM;

extern UINT8 Quectel_IsOEMLandiEnable(void);
extern UINT8 quec_IsOEMLandiEnable;
#endif


#ifdef QUECTEL_NETWORK_SUPPORT
RETURNCODE_T quectel_exec_qnwinfo_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
#ifndef QUEC_MINI_SYSTEM_SUPPORT

RETURNCODE_T quectel_exec_cgreg_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
#endif

#ifndef QUEC_MINI_SYSTEM_SUPPORT
RETURNCODE_T quectel_exec_cereg_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
#endif

RETURNCODE_T quectel_exec_creg_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_csq_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qcsq_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_cgerep_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


/*===========================================================================

FUNCTION QUEC_EXEC_CTZR_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command 	control the time zone  Reporting .

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.
    utlFAILED :if there was any problem in executing the command.

SIDE EFFECTS
  None
===========================================================================*/

RETURNCODE_T quectel_exec_ctzr_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qeng_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qlts_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qgdcnt_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qaugdcnt_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qoem_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
#ifndef ENABLE_DM_LTEONLY
RETURNCODE_T dsat_exec_smonc_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/	
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/	 
	void						   *arg_p				/* AT cmd parser number */
);
#endif

RETURNCODE_T quectel_exec_qgpapn_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


#ifdef QUECTEL_AT_RFTEST_SUPPORT

RETURNCODE_T quectel_exec_qrftestmode_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qrftest_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qrxftm_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


#endif

#endif

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
RETURNCODE_T  quec_g510_mcell_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

typedef enum
{
    QUEC_FIBO_MCELL_SYSN = 0,
    QUEC_FIBO_MCELL_SYSN_EX ,
    QUEC_FIBO_MCELL_ASYN
}quec_fibo_mcell_show_e;

extern quec_fibo_mcell_show_e quec_fibo_mcell_show(void);

extern uint8 quec_fibo_mcell_format(char * str);


RETURNCODE_T  quec_g510_t3302_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
);

#endif

#ifdef QUECTEL_JAMDET_FEATURE
#define QUEC_JD_ARFCN_INVALID (0)
#define QUEC_JD_RSSI_INVALID (0)
#define QUEC_JD_SINR_INVALID (0X7FFF)
#define QUEC_JD_BSIC_MAX_INVALID (0XFF)
#define QUEC_JD_BSIC_MIN_INVALID (0)
#define QUEC_JD_PCID_INVALID (0XFFFF)

typedef enum {
    JAM_DET_RES_NONE   = -1,
	JAM_DET_REMOVE     = 0,
	JAM_DET_INSERT     = 1,
	JAM_DET_INSERT_URC_DISABLE = 2, //add: jd=1,urc=0,开干扰，input urc=1,不报jamming
} jamdet_res_e_type;
	
typedef enum
{
    JDCFG_ENUM_NONE = -1,       
    JDENABLE        = 0,        
    JDURC,                     
    JDPERIOD,                 
    JDMINCH,                   
    JDSINR,                  
    JDRXLEV,							            
    JDRSRP,                    
    JDRSRQ,                    
    JDRSSI,                                 
    JDSHAKEPERIOD,                             
    JDCFG_ENUM_MAX              
}quectel_jdcfg_e_t;

typedef struct 
{
    quectel_jdcfg_e_t   qjdcfg_enum;
    const char          cmd_str[20];
    int                 value;
    const int           minval;
    const int           maxval;
}quectel_jdcfg_s_t;

/* jdcfg values save to nv */
typedef struct 
{
    int jdvalue[JDCFG_ENUM_MAX];
}quectel_jdval_s_t;

typedef enum {
    JAM_DET_CMD_NONE   = -1,
	JAM_DET_GSM_TYPE   = 0,
    JAM_DET_WCDMA_TYPE,
    JAM_DET_CDMA_TYPE,
    JAM_DET_FDD_LTE_TYPE,
} jamdet_cmd_e_type;

typedef enum 
{
	QUEC_TIMER_MIN = -1,
	QUEC_REPORT_TIMER = 0,
	QUEC_PERIOD_TIMER,
	QUEC_TIMER_MAX
}quec_time_type_e_t;

typedef enum 
{
	QUEC_NW_MODE_MIN = -1,
	QUEC_GSM_MODE,
	QUEC_UMTS_MODE,
	QUEC_LTE_MODE,
	QUEC_NW_MODE_MAX
}quec_nw_mode_e_t;

RETURNCODE_T quec_exec_qjdr_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);
RETURNCODE_T quec_exec_qjdcfg_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/
	void						   *arg_p				/* AT cmd parser number */
);

extern QuecOSStatus quec_jam_det_read_from_nv(void);
extern QuecOSStatus quec_jam_det_set_to_nv(quectel_jdval_s_t *jdcfgP);
extern void quec_jam_detect_indicate_urc(jamdet_cmd_e_type type, jamdet_res_e_type det_status);
extern void quec_jd_period_report_Timer_callback(UINT32 argv);
extern QuecOSStatus quec_timer_create_init(quec_time_type_e_t timer_type);
extern jamdet_res_e_type quec_get_jamming_status(void);
extern int quec_get_jdcfg_val(quectel_jdcfg_e_t jdcfg_type);
extern int quec_get_jdcfg_min_val(quectel_jdcfg_e_t jdcfg_type);
extern bool quec_vaild_jdcfg_type(quectel_jdcfg_e_t jdcfg_type);
extern int quec_get_jdcfg_max_val(quectel_jdcfg_e_t jdcfg_type);

#endif


#if 0
QuecOSStatus quec_read_freq_scan_config(void);
QuecOSStatus quec_freq_scan_config_set(void);
RETURNCODE_T quectel_exec_qcfg_freqscanopt_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);
#endif
#ifdef QUEC_POWER_BACKOFF_SUPPORT
RETURNCODE_T quec_exec_qpwrbackoff_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
RETURNCODE_T quec_exec_qgrip_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

#endif

#if defined(__QUEC_OEM_VER_LT__)
#define QUEC_AVGRSSI_TIMER_OUT (1000*60) /*1 minute*/
#define QUEC_AVGRSSI_MSG_LEN_NONE (0)

typedef struct
{
    UINT32 csq_number;  /*csq: effective sampling number*/
    INT16  avg_csq;     /*csq average*/
}csq_info_s_t;
QuecOSStatus quec_avgrssi_timer_create_init(void);
void quec_avgrssi_msg_process(void);
void quec_avgrssi_Timer_callback(UINT32 argv);
QuecOSStatus quec_avgrssi_start_timer
(
    quec_timer_t timer,
    uint32 time_experiod,
    void (*callBackRoutine)(UINT32)
);

RETURNCODE_T quectel_exec_avgrssi_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qnwscan_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
UINT8 quec_get_qnwscan_cops_flag(void);
void quec_set_qnwscan_cops_flag(UINT8 cops_flag);
void quec_restore_default_band_nwmode(void);
#endif

#if QUEC_DUAL_SIM_SUPPORT
UINT8 quec_report_qcsq_dual_sim(UINT8 force_report,char * report_buf, char simid);
#endif

#ifdef QUEC_CCED_SUPPORT
#define QUEC_CCED_NO_AUTO_MODE 0
#define QUEC_CCED_AUTO_MODE 1
#define QUEC_CCED_REQUESTED_MAIN_CELL 1
#define QUEC_CCED_REQUESTED_NEIGHBOUR_CELL 2
#define QUEC_CCED_REQUESTED_MAIN_CELL_RSSI 8

RETURNCODE_T quectel_exec_cced_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
#endif

#ifdef QUEC_QNWCFG_SUPPORT
RETURNCODE_T  quec_exec_qnwcfg_cmd
(
	const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	const char 					*command_name_p,		/* AT cmd name					*/
	const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	const size_t					 num_parameters,		/* AT cmd number				*/
	const char 					*info_text_p,			/* AT cmd usage string			*/
	unsigned int					*xid_p, 				/* AT cmd handle				*/
	void							*arg_p					/* AT cmd parser number 		*/
);

#define QUEC_EFS_QNWCFG_EN_CFG  "qnwcfg_en_cfg"
void quec_nv_qnwcfg_cfg_init(void);

typedef struct
{
    UINT16	DLMCS0;      /* Modulation and coding scheme of PDSC  main antenna*/
	UINT16	DLMCS1;      /* Modulation and coding scheme of PDSC diversity antenna*/
    UINT8	RI;  		/*Effective number of data layers of PDSCH*/
    UINT8	CQI;  		/*Channel Quality Indicato*/
	UINT16	PMI;		/*Precoding Matrix Indicator*/
	UINT32	TB_size;	/*TB byte length*/
	UINT16	num_RBs;	/*Number of allocated resource block*/
	UINT8	mod_type;	/*Modulation orde 2:QPSK 4:16QAM 6: 64QAM 8:256QAM 10:1024QAM*/
}quec_csi_info_s_t;


#endif

#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
RETURNCODE_T quec_exec_qnetworkstatus_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
);
#define QUEC_EFS_REJECTSTATUS_CFG  "rejectstatus_cfg"

#endif
void quec_nwlock_nv_read_params_init(void);

RETURNCODE_T quectel_exec_qnwlock_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


RETURNCODE_T  quectel_exec_qnwlock_lte_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

#ifdef QUEC_OPER_OOS_PHASE_PERIOD

RETURNCODE_T  quectel_exec_qoospp_cmd
(
       const utlAtParameterOp_T        op,                 /* AT cmd type          */
       const char                     *command_name_p,     /* AT cmd name          */
       const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
       const size_t                    num_parameters,     /* AT cmd number        */
       const char                     *info_text_p,        /* AT cmd usage string  */
       unsigned int                   *xid_p,              /* AT cmd handle        */
       void                           *arg_p
);

#endif

#endif




