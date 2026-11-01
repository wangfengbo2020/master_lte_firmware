/**  @file
  quec_atcmd_network.c

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

/******************************************************************
 * include files
 ******************************************************************/
#include "quec_include.h"
#include "quec_cust_feature.h"
#include "ci_api.h"
#include "telcontroller.h"
#include "telatci.h"
#include "telconfig.h"
#include "telatparamdef.h"
#include "teldbg.h"
#include "telcc.h"
#include "telmm.h"
#include "telps.h"
#include "telpb.h"
#include "telss.h"
#include "teldev.h"
#include "teldat.h"
#include "telmsg.h"
#include "telsim.h"
#include "utlMalloc.h"
#include <stdio.h>
#include <osa.h>
#include "utlTrace.h"
#include "stub.h"
#include "stdlib.h"
#include "string.h"
#include "telcmux.h"
#include "m2m_api.h"
#include "telm2m.h"
#include "teldef.h"
#include "teldbg.h"
#include "quec_ver_inc.h"
#include "quec_include.h"
#include "quec_siolib.h"
#include "quec_urc.h"
#include "string_utils.h"
#include "quec_cust_feature.h"
#include "quec_msg_process.h"
#include "ci_ps.h"
#include "ci_mm.h"
#include "mm_api.h"
#include "ci_api.h"
#include "quec_atcmd_general.h"
#include "quec_atcmd_network.h"
#include "quec_urc.h"
#include "quec_rtos.h"
#include "quec_msg_process.h"
#ifdef QUEC_POWER_BACKOFF_SUPPORT
#include "\CRD\DSPDebugConfig\inc\DSPDebugConfig_NVM.h"
#endif
#ifdef QUECTEL_JAMDET_FEATURE
#include "ci_dev.h"
#endif


#ifndef MIN_SYS


#ifdef QUEC_ATCMD_LOG
	#define atcmd_nw_log(msg, ...)  custom_log("ATCMD_NW", msg, ##__VA_ARGS__)
#else
	#define atcmd_nw_log(msg, ...)
#endif



/******************************************************************
 *   Global Variable
 ******************************************************************/
#define QUEC_CESQ_TO_CSQ_RSSI_OFFSET  4


#ifdef QUECTEL_NETWORK_SUPPORT
 extern int gSysMainMode;
#ifdef QUEC_CSQ_FIX
 extern int gSysMode;
#endif
 //extern int gSysMode_1;
 Quec_pdp_act_status_type 	quec_pdp_act_state[CI_PS_MAX_CID]={0};
 UINT64 network_infor_bitmsk=0;

 #if QUEC_DUAL_SIM_SUPPORT
 Quec_qnwinfo_type quec_qnwinfo[2];
 CiPsNwRegInfo quec_cgreg_info[2];
 CiPs4GNwRegInfo quec_cereg_info[2];
 CiMmPrimRegResultInd quec_creg_info[2];
 mmExtendedSignal_quec quec_netquality_info[2];
 Quec_cgerep_type cgerep_info[2]={{0,0}, {0,0}};
 #else
 Quec_qnwinfo_type quec_qnwinfo;
 CiPsNwRegInfo quec_cgreg_info;
 CiPs4GNwRegInfo quec_cereg_info;
 CiMmPrimRegResultInd quec_creg_info;
 mmExtendedSignal_quec quec_netquality_info;
 Quec_cgerep_type cgerep_info={0,0};
 #endif 

 int qlts_mode=0; //0 current time 1 current GMT time 2 current local time
 UINT8 ctzr_reporting=0;
 UINT8 quec_qcsq_report_flag=0;
 
#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)

	#define QUEC_ECNO_MIN  -24  //Chaim 20190930 ecno min value
	#define QUEC_ECNO_MAX  0
	int g_3g_ecno = 0;

#endif
 
 UINT8 qeng_type_name[][20] =
{
     "servingcell"              //servingcell
    ,"neighbourcell"            //neighbourcell
    ,"3gcomm"                   //3gcomm
    //add new here
};
char * quec_QengResBuf;
UINT32 quec_QengResDataLen = 0;
UINT32 quec_QengResBufLen = 0;
QuecDataCntInfoType  QuecDataCntInfo = {0};
#if QUEC_LTE_SUPPORT
QuecNetModeCfgType  QuecNetModeCfg = {CI_DEV_NW_GSM_UMTS_LTE,CI_DEV_NW_GSM_UMTS_LTE,0,1,0xFF,0xFF,0xFF,0xFF,0xFF,2,1,0xFF,0xFF};
#else
QuecNetModeCfgType  QuecNetModeCfg = {CI_DEV_NW_GSM_UMTS,CI_DEV_NW_GSM_UMTS,0,1,0xFF,0xFF,0xFF,0xFF,0xFF,2,1,0xFF,0xFF};
#endif
UINT32 AutoGDCNTInterval = QUEC_DEFAULT_AUTO_GDCNT_INTERVAL;
OSATimerRef quec_qaugdcnt_time_ref = NULL;

//QuecFreqScanType quec_freq_scan_config = {200,100};
//QuecFreqScanType quec_asr_freq_scan_config = {0,0};
//#define QUEC_FREQ_SCAN_NVM   "freq_scan_config"
#ifdef QUEC_ENGINEER_OUTPUT
char * quec_QengineerResBuf = NULL;
UINT32 quec_QengineerResLen = 0;
UINT32 quec_QengineerBufLen = 0;
UINT32 quec_qengineer_atp =0;

#endif

UINT8 qeng_type_num=QUEC_ARR_SIZE(qeng_type_name);



enum ATCI_SYSINFO_SYSTEM_MODE
{
    ATCI_SYSINFO_SYSTEMO_MODE_NO_SERVICE = 0,
    ATCI_SYSINFO_SYSTEMO_MODE_RESERVED_1 = 1,
    ATCI_SYSINFO_SYSTEMO_MODE_RESERVED_2 = 2,
    ATCI_SYSINFO_SYSTEMO_MODE_GSM_GPRS = 3,
    ATCI_SYSINFO_SYSTEMO_MODE_WCDMA = 5,
    ATCI_SYSINFO_SYSTEMO_MODE_TDSCDMA = 15,
#ifdef LWIP_IPNETBUF_SUPPORT
    ATCI_SYSINFO_SYSTEMO_MODE_LTE = 17,
#endif
}quec_AtciSysinfoSystemMode;


#ifdef __QUEC_OEM_VER_LD__
uint8 qoem_type_name[QUECTEL_QOEM_ITEM_MAX][20] =
{
#ifdef __QUEC_OEM_VER_LD__
	"landi" ,
	"landipin" 
#endif
};
UINT8 qoem_type_num=QUEC_ARR_SIZE(qoem_type_name);
UINT8 quec_IsOEMLandiEnable=0;

#endif

#ifdef QUECTEL_AT_RFTEST_SUPPORT
	quec_rftestmode_param_type quec_rftestmode={QUEC_NETMODE_NONE, 0, 0};

	tx_band_label_type qrftest_labels[] = {
	  { QUEC_NETMODE_GSM,	"GSM900", ASR_BAND_EGSM_900,0,1023,0,1023}, //For EGSM 900, range: (0-124) and (975-1023)
	  { QUEC_NETMODE_GSM,	"GSM1800",ASR_BAND_GSM_1800,512,885,512,885},
	  { QUEC_NETMODE_GSM,	"GSM1900",ASR_BAND_GSM_1900,512,810,512,810},
	  { QUEC_NETMODE_GSM,	"GSM850",ASR_BAND_GSM_850,128,251,128,251},
	  //lte channel TS36.101 5.7.3.1
	  { QUEC_NETMODE_LTE, "LTE BAND1",1,18000,18599,0,599},
	  { QUEC_NETMODE_LTE, "LTE BAND3",3,19200,19949,1200,1949},
	  { QUEC_NETMODE_LTE, "LTE BAND4",4,19950,20399,1950,2399},  
	  { QUEC_NETMODE_LTE, "LTE BAND5",5,20400,20649,2400,2649},
	  { QUEC_NETMODE_LTE, "LTE BAND7",7,20750,21449,2750,3449},
	  { QUEC_NETMODE_LTE, "LTE BAND8",8,21450,21799,3450,3799},
	  { QUEC_NETMODE_LTE, "LTE BAND17",17,23730,23849,5730,5849},
	  { QUEC_NETMODE_LTE, "LTE BAND20",20,24150,24449,6150,6449},
	  { QUEC_NETMODE_LTE, "LTE BAND28",28,27210,27659,9210,9659},
	  { QUEC_NETMODE_LTE, "LTE BAND31",31,27760,27809,9870,9919},
	  { QUEC_NETMODE_LTE, "LTE BAND33",33,36000,36199,36000,36199},
	  { QUEC_NETMODE_LTE, "LTE BAND34",34,36200,36349,36200,36349},
	  { QUEC_NETMODE_LTE, "LTE BAND38",38,37750,38249,37750,38249},   
	  { QUEC_NETMODE_LTE, "LTE BAND39",39,38250,38649,38250,38649},   
	  { QUEC_NETMODE_LTE, "LTE BAND40",40,38650,39649,38650,39649},   
	  { QUEC_NETMODE_LTE, "LTE BAND41",41,39650,41589,39650,41589},
	  { QUEC_NETMODE_LTE, "LTE BAND65",65,131072,131971,65536,66435},
	  { QUEC_NETMODE_LTE, "LTE BAND66",66,131972,132671,66436,67335},
	  { QUEC_NETMODE_LTE, "LTE BAND72",72,133472,133521,68936,68985}
	 };
#endif

#define QUEC_NWLOCK_PARAMS_NVM "quec_nwlock_params.nvm"
 
typedef struct 
{
	int mode ; /* <mode> 0 lock 1 unlock */
	int act  ; /* <act>  0 GSM 1	UMTS_TD 2 UMTS_WB 3 LTE */
	int band ;
	int freq ;
	int cellId ;
} quec_nwlock_s, *quec_nwlock_p;

quec_nwlock_s g_quec_nwlock = {0};
 
#define QNWLOCK_CMD_LIST(E)													    \
		   E(QNWLOCK_CMD_LTE,		   "lte",				   quectel_exec_qnwlock_lte_cmd)	   
   
	   
#define QNWLOCK_CMD_ENUM_DEF(enum, cmd_str, cmd_fnc)	enum,
	   
#define QNWLOCK_CMD_TBL_FILL(enum, cmd_str, cmd_fnc)	[enum] = {cmd_str, cmd_fnc},
	   
enum
{
   QNWLOCK_CMD_LIST(QNWLOCK_CMD_ENUM_DEF)
   QNWLOCK_CMD_MAX
};
   
quectel_common_cfg_cmd_type	quectel_qnwlock_cmd_tbl[QNWLOCK_CMD_MAX] =
{
   QNWLOCK_CMD_LIST(QNWLOCK_CMD_TBL_FILL)
};
	   
const unsigned int quectel_qnwlock_cmd_tbl_size = QUEC_ARR_SIZE( quectel_qnwlock_cmd_tbl);

 /*===========================================================================
 
 FUNCTION QUEC_UPDATE_MODE_PREF
 
 DESCRIPTION
   This function update the mode pref when customer change it by at .
 
 DEPENDENCIES
   None
 
 RETURN VALUE
   returns the 0, 1 or -1
 SIDE EFFECTS
   None
 ===========================================================================*/
    
extern UINT8 update_lte;
extern UINT8 update_2g_3g;
 int quec_update_mode_pref(QuecNetModeCfgType *p_quec_net_cfg)
 {
	//UINT8 ret=1;
	atcmd_nw_log("net_mode[%d,%d]->[%d,%d], update_flag=%d",QuecNetModeCfg.net_mode,QuecNetModeCfg.pref_mode,
	    p_quec_net_cfg->net_mode, p_quec_net_cfg->pref_mode,QuecNetModeCfg.update_flag);

	//the value is same we do not need to update
	if(memcmp(p_quec_net_cfg, &QuecNetModeCfg, sizeof(QuecNetModeCfgType)) == 0)
	{
		atcmd_nw_log("net mode cfg same, nothing to update ");
		return 0;
	}
	else
	{
	    p_quec_net_cfg->update_flag = 1;
		if(QUEC_FAT_SUCCESS != quectel_nv_fat_write(QUEC_AT_MODE_BACKUP, p_quec_net_cfg, sizeof(QuecNetModeCfgType)))
		{
			atcmd_nw_log("net mode cfg save error !!! ");
			QuecNetModeCfg.update_flag = 0;
			return -1;
			
		}
        
        if ((p_quec_net_cfg->net_mode != QuecNetModeCfg.pref_mode) || (p_quec_net_cfg->pref_mode != QuecNetModeCfg.pref_mode))
        {
            if ((p_quec_net_cfg->net_mode >= CI_DEV_NW_LTE) && (p_quec_net_cfg->net_mode <= CI_DEV_NW_GSM_UMTS_LTE))
            {
			    atcmd_nw_log("update_lte set to 0");
                update_lte = 0;
            }
			#ifndef LTEONLY_THIN_SINGLE_SIM  //单卡的2M Flash项目不支持
            if ((p_quec_net_cfg->net_mode != CI_DEV_NW_LTE) && (p_quec_net_cfg->net_mode < CI_DEV_NUM_NW_MODES))
            {
			    atcmd_nw_log("update_2g_3g set to 0");
                update_2g_3g = 0;
            }
			#endif
        }
		memcpy(&QuecNetModeCfg, p_quec_net_cfg, sizeof(QuecNetModeCfgType));
	}

	return 1;
 }

 /*===========================================================================
 
 FUNCTION QUEC_GET_CURREENT_STATE
 
 DESCRIPTION
   This function get the current state.
 
 DEPENDENCIES
   None
 
 RETURN VALUE
   returns the state
 SIDE EFFECTS
   None
 ===========================================================================*/
 void quec_qeng_get_currrent_state(char * sate)
{
	if(quec_get_regstatus(1))
    {
        //is_voice_call ? we do not support voice call so always NOCONN
#if defined(QUEC_AUDIO_SUPPORT) && defined(QUEC_AT_CMD_AUDIO_SUPPORT)
		if(quec_audio_get_call_status())
#else
		if(quec_led_get_call_status())
#endif
		{
			memcpy(sate,(char *)"CONNECT",strlen((char *)"CONNECT"));
		}
		else
		{
			memcpy(sate,(char *)"NOCONN",strlen((char *)"NOCONN"));
		}
	}
	else
	{
		memcpy(sate,(char *)"LIMSRV",strlen((char *)"LIMSRV"));
	}

 
}

 /*===========================================================================
 
 FUNCTION QUEC_CESQ_2QUEC_CSQ
 
 DESCRIPTION
   This function map the  cEsq signal to csq signal.
 
 DEPENDENCIES
   None
 
 RETURN VALUE
   returns the signal of quec
 SIDE EFFECTS
   None
 ===========================================================================*/
 void quec_cesq_2quec_csq(void* netquality_info,INT16 * rssi,INT16 * ber)
 {
	 *rssi =99;
	 * ber=99;
	 mmExtendedSignal_quec *info_temp=NULL;
	 info_temp =(mmExtendedSignal_quec *)netquality_info;
     quec_network_mode_type current_rat=quec_get_current_rat(0);
     atcmd_nw_log("[quec csq] info_temp->rssi=%d,rsrp=%d",info_temp->rssi,info_temp->rsrp-140);
	 switch(current_rat)
	 {
	   case  QUEC_NETMODE_GSM:
	   case  QUEC_NETMODE_LTE://connor.wu 2018/03/08  CESQ support LTE rssi report
#ifdef 	QUECTEL_NETWORK_SUPPORT
#ifdef QUECTEL_CSQ_TYPE
        if ((1 == quec_get_csq_type()) && (QUEC_NETMODE_LTE == current_rat))
        {
            int rsrp = 0;
            rsrp = -1 * (info_temp->rsrp - 120);
            
            if ((RSSI_MIN < rsrp) && (RSSI_MAX > rsrp))
            {
                /* Round to nearest integer on scale */
                *rssi = (INT16)(((rsrp * RSSI_SLOPE + RSSI_OFFSET) * RSSI_TOOHI_CODE)/100 + 0.5);
                /*对比高通弱信号下低5dbm*/
                if ((*rssi <= 13) && (*rssi > RSSI_TOTHRESHOLD_CODE))
                {
                    *rssi += RSSI_OFFSET_4; 
                }
                else if (*rssi <= RSSI_TOTHRESHOLD_CODE)
                {
                     *rssi += RSSI_OFFSET_6; //宝蓝csq弱信号下抬高6dbm。
                }
               
                atcmd_nw_log("[quec csq] csq = %d",*rssi);
            }
            else if ((RSSI_MAX <= rsrp) && (RSSI_NO_SIGNAL != rsrp)) 
            {
                //*rssi = RSSI_TOOLO_CODE;
                *rssi = RSSI_OFFSET_6; //宝蓝csq门限值为3。
            }
            else if (RSSI_MIN >= rsrp)
            {
                *rssi = RSSI_TOOHI_CODE;  /* Capped maximum */
            }
            else
            {
                atcmd_nw_log("[quec csq] rsrp outside signal range: %d", rsrp);
                //*rssi = RSSI_UNKNOWN_CODE;
                *rssi = RSSI_OFFSET_6; //宝蓝csq门限值为3。
            } 
        }
        else
#endif     
#endif
        {
            /*LTE 以rsrp做保护*/
            if (QUEC_NETMODE_LTE == current_rat)
            {
                if (info_temp->rsrp <= QUEC_RSSI_NET_NO_SERV)
                {
                    *rssi = 4;
                }
                else if ((info_temp->rsrp <= QUEC_RSSI_CSQ_5) && (QUEC_RSSI_NET_NO_SERV < info_temp->rsrp))
                {
                    *rssi = 5;
                }
                else if ((info_temp->rsrp <= QUEC_RSSI_CSQ_8) && (QUEC_RSSI_CSQ_5 < info_temp->rsrp))
                {
                    *rssi = 8;
                }
                else if ((info_temp->rsrp <= QUEC_RSSI_CSQ_11) && (QUEC_RSSI_CSQ_8 < info_temp->rsrp))
                {
                    *rssi = 10;
                }
                else 
                {
                     *rssi = ((info_temp->rssi+QUEC_CESQ_TO_CSQ_RSSI_OFFSET)/2)>31 ? 31 : ((info_temp->rssi+QUEC_CESQ_TO_CSQ_RSSI_OFFSET)/2);  //Chaim20200818 cesq use45.008 is -110 dbm,n-110= 2*csq_value-113,but we need 0.5dbm，so add 4 not 3
                }
            }
            else
            {
		         *rssi = ((info_temp->rssi+QUEC_CESQ_TO_CSQ_RSSI_OFFSET)/2)>31 ? 31 : ((info_temp->rssi+QUEC_CESQ_TO_CSQ_RSSI_OFFSET)/2);  //Chaim20200818 cesq use45.008 is -110 dbm,n-110= 2*csq_value-113,but we need 0.5dbm，so add 4 not 3
            }
        }
	   		 if(current_rat == QUEC_NETMODE_GSM)
			 {
			 	* ber =info_temp->ber;
	   		 }
			 break;
	   case  QUEC_NETMODE_WCDMA: 
	   		#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)    //Chaim,info_temp->rscp-120-g_3g_ecno is rssi,convert to level
				atcmd_nw_log("csq=%d,g_3g_ecno=%d",info_temp->rscp,g_3g_ecno);
				if((g_3g_ecno > QUEC_ECNO_MAX)||(g_3g_ecno <QUEC_ECNO_MIN))//Chaim 20190928 check  g_3g_ecno is valid
				{
					atcmd_nw_log("g_3g_ecno=%d is invalid",g_3g_ecno);
					#if defined (__QUEC_OEM_VER_PAX__)
						g_3g_ecno = -10;	 //Chaim 20190928 use pax default value
					#else
						g_3g_ecno = 0;	   //Chaim 20190928 use default value
					#endif 
				}

				//*rssi =  ((info_temp->rscp-120-g_3g_ecno)+111)/2+1 >31?31:((info_temp->rscp-120-g_3g_ecno)+111)/2+1;
				//Chaim 20191017 rscp form -120 ~ -25,convert inter value form -5~91
				//rscp form -113 ~ -51,convert inter value form 0~31
				*rssi = ((info_temp->rscp -120 +5 -g_3g_ecno)+113)/2;

			#if QUEC_DUAL_SIM_SUPPORT
				atcmd_nw_log("csq,rscp=%d,ecno=%d,rssi=%d",quec_netquality_info[isMasterSim0() ? SIM1 : SIM2].rscp,g_3g_ecno,*rssi);
			#else
				atcmd_nw_log("csq,rscp=%d,ecno=%d,rssi=%d",quec_netquality_info.rscp,g_3g_ecno,*rssi);
			#endif 
			
				if(*rssi >31 ) //Chaim 20191017 for protect if rscp not in normal scope
				{
					*rssi = 31;	
				}
				else if(*rssi < 0)
				{
					*rssi = 0;		
				}
				else
				{
					//can not go to here
				}

			#else
				*rssi = (info_temp->rscp/3)>31 ? 31 : (info_temp->rscp/3); 
			#endif
		 	 break;
	   /*case  QUEC_NETMODE_LTE:

			 *rssi = (info_temp->rsrp/3)>31 ? 31 : (info_temp->rsrp/3); 
		 break;*/
	   default:
	   	 atcmd_nw_log("invalid rat=%d",current_rat);
	   	 break;
	 }
	 return ;
 }

  /*===========================================================================
   
   FUNCTION QUEC_REGSTATUS_ASR2QUEC
   
   DESCRIPTION
     This function map the asr regstatus to quec.
   
   DEPENDENCIES
     None
   
   RETURN VALUE
     returns the signal of quec
   SIDE EFFECTS
     None
   ===========================================================================*/
   
UINT8 quec_regstatus_asr2quec(UINT8 asr_status, uint8 need_attach)
{
     UINT8 quec_status=0;
     atcmd_nw_log("asr_status=%d",asr_status);
     switch(asr_status)
     {
         case  0:  //not registered, MT is not currently searching an operator to register to
         case  8:  //attached for emergency bearer services only 
             quec_status=0; // Not registered, MT is not currently searching an operator to register to
             break;
         case  11: //emergency bearer services only
             if (0 == need_attach)
             {
                 quec_status=6; //emergency
             }
             else
             {
                 quec_status = 0;// Not registered, MT is not currently searching an operator to register to
             }
             break;
         case  1:  //registered, home network
         case  6:  //registered for "SMS only" home network (not applicable) 
         case  9: //registered for "CSFB not preferred" home network (not applicable)
             quec_status=1; // Registered, home network
             break;
         case  2: 
             quec_status=2; // not registered, but MT is currently trying to attach or searching an operator to register to
             break;
         case  3: 
             quec_status=3; // registration denied
             break;
         case  4: 
             quec_status=4; // unknown
             break;
         case  5:  //registered, roaming
         case  7:  //registered for "MS only" roaming (not applicable)
         case  10: //registered for "CSFB not preferred" roaming (not applicable)
             quec_status=5; // registered, roaming
             break;
         default:
             quec_status=4; // unknown
             atcmd_nw_log("reg status error asr_status=%d",asr_status);  
             break;
     }
     return quec_status;
}



  /*===========================================================================
	
	FUNCTION QUEC_REGSTATUS_ASR2QUEC
	
	DESCRIPTION
	  This function map the asr act to quec.
	
	DEPENDENCIES
	  None
	
	RETURN VALUE
	  returns the signal of quec
	SIDE EFFECTS
	  None
	===========================================================================*/
	
  UINT8 quec_act_asr2quec(UINT8 asr_act)
  {
	  UINT8 quec_act=0xff;
	  atcmd_nw_log("asr_act=%d",asr_act);
	  switch(asr_act)
	  {
		  case	8:	//CI_MM_ACT_UTRAN_HSPA_PLUS map to CI_MM_ACT_UTRAN_HSPA
		  	  quec_act=6; 
			  break;
		  case	9:	//CI_MM_ACT_EUTRAN_PLUS map to CI_MM_ACT_EUTRAN
			  quec_act=7; 
			  break;
	
		  default:
			  quec_act=asr_act; 
			  break;
	  }
	  atcmd_nw_log("quec_act=%d",quec_act);
	  return quec_act;
  }

  /*===========================================================================
	
	FUNCTION QUEC_REGSTATUS_ASR2QUEC
	
	DESCRIPTION
	  This function get the net status of CREG/CEREG/CGREG.
	
	DEPENDENCIES
	  None
	
	RETURN VALUE
	  returns the regstatus 0:not registered 1: registered
	SIDE EFFECTS
	  None
	===========================================================================*/
	
UINT8 quec_get_regstatus(uint8 need_attach)
{
    UINT8 regstatus=0;
#if QUEC_DUAL_SIM_SUPPORT
	UINT8 creg_status=quec_regstatus_asr2quec(quec_creg_info[isMasterSim0() ? SIM1 : SIM2].RegStatus, need_attach);
	UINT8 cereg_status=quec_regstatus_asr2quec(quec_cereg_info[isMasterSim0() ? SIM1 : SIM2].status, need_attach);
	UINT8 cgreg_status=quec_regstatus_asr2quec(quec_cgreg_info[isMasterSim0() ? SIM1 : SIM2].status, need_attach);
#else	
    UINT8 creg_status=quec_regstatus_asr2quec(quec_creg_info.RegStatus, need_attach);
    UINT8 cereg_status=quec_regstatus_asr2quec(quec_cgreg_info.status, need_attach);
    UINT8 cgreg_status=quec_regstatus_asr2quec(quec_cereg_info.status, need_attach);
#endif 
    if((creg_status==1 || creg_status==5)
        ||(cereg_status==1 || cereg_status==5)
        ||(cgreg_status==1 || cgreg_status==5))
    {
        regstatus = 1;
    }
    else if ((0 == need_attach) && 
    ((6 == creg_status)
    #if defined(__QUEC_OEM_VER_OA__)
    ||(creg_status == 3)
    #endif
    ))
    {
        regstatus = 2;
    }
    else
    {
        regstatus = 0;
    }	
    atcmd_nw_log("regstatus=%d, need_attach=%d",regstatus, need_attach);	
    return regstatus;
}
	/*===========================================================================
	
	FUNCTION QUEC_GET_PS_REGSTATUS
	
	DESCRIPTION
	  This function get the net status of ps.
	
	DEPENDENCIES
	  None
	
	RETURN VALUE
	  returns the regstatus 0:not registered 1: registered
	SIDE EFFECTS
	  None
	===========================================================================*/
	
UINT8 quec_get_ps_regstatus(void)
{
	  UINT8 ps_regstatus=0;
#if QUEC_DUAL_SIM_SUPPORT
	  UINT8 cereg_status=quec_regstatus_asr2quec(quec_cgreg_info[isMasterSim0() ? SIM1 : SIM2].status, 1);
	  UINT8 cgreg_status=quec_regstatus_asr2quec(quec_cereg_info[isMasterSim0() ? SIM1 : SIM2].status, 1);
#else
	  UINT8 cereg_status=quec_regstatus_asr2quec(quec_cgreg_info.status, 1);
	  UINT8 cgreg_status=quec_regstatus_asr2quec(quec_cereg_info.status, 1);
#endif 

	  if((cereg_status==1 || cereg_status==5)
		  ||(cgreg_status==1 || cgreg_status==5))
	  {
		  ps_regstatus = 1;
	  }
	  else
	  {
		  ps_regstatus = 0;
	  } 
	  atcmd_nw_log("ps_regstatus=%d",ps_regstatus);	
	  return ps_regstatus;
}

/*===========================================================================
  
  FUNCTION QUEC_GET_CURRENT_RAT
  
  DESCRIPTION
	 This function get the  curret rat .
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 returns the current rat
  SIDE EFFECTS
	 None
  ===========================================================================*/
  
quec_network_mode_type quec_get_current_rat(uint8 need_attach)
{
    quec_network_mode_type current_rat=QUEC_NETMODE_NONE;
    UINT8 cur_reg_status;
#if QUEC_DUAL_SIM_SUPPORT
	extern int gSysMainMode;
	extern int gSysMainMode_1;
	extern int gSysMode;
    extern int gSysMode_1;
	int gSysMainMode_temp = isMasterSim0() ? (gSysMainMode) : (gSysMainMode_1);
	int gSysMode_temp = isMasterSim0() ? (gSysMode) : (gSysMode_1);
#else
	int gSysMainMode_temp = gSysMainMode;
#endif

    /*if(quec_get_regstatus())
    {
        if(quec_cereg_info.act==7 )
        {
            current_rat=QUEC_NETMODE_LTE;
        } 
        else if((quec_cgreg_info.act==2 
        || quec_cgreg_info.act==4 
        || quec_cgreg_info.act==5 
        || quec_cgreg_info.act==6 
        || quec_cgreg_info.act==8 ))
        {
            current_rat=QUEC_NETMODE_WCDMA;
        }
        else if((quec_cgreg_info.act==0 
        || quec_cgreg_info.act==1 ))
        {
            current_rat=QUEC_NETMODE_GSM;
        } 
    }*/
    cur_reg_status = quec_get_regstatus(need_attach);
    if ((1 == cur_reg_status) || (2 == cur_reg_status))
    {
#ifdef QUEC_CSQ_FIX
	#if QUEC_DUAL_SIM_SUPPORT
		if (gSysMainMode_temp == ATCI_SYSINFO_SYSTEMO_MODE_LTE ||
           gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_EUTRAN)
        {
            current_rat = QUEC_NETMODE_LTE;
        } 
        else if (gSysMainMode_temp == ATCI_SYSINFO_SYSTEMO_MODE_WCDMA ||
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN ||
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSDPA ||
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSUPA ||
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSPA)
        {
            current_rat = QUEC_NETMODE_WCDMA;
        }
        else if (gSysMainMode_temp == ATCI_SYSINFO_SYSTEMO_MODE_GSM_GPRS || 
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM ||
                gSysMode_temp == ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM_EGPRS)
        {
            current_rat = QUEC_NETMODE_GSM;
        }
	#else
        if(gSysMainMode==ATCI_SYSINFO_SYSTEMO_MODE_LTE ||
           gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_EUTRAN)
        {
            current_rat=QUEC_NETMODE_LTE;
        } 
        else if(gSysMainMode==ATCI_SYSINFO_SYSTEMO_MODE_WCDMA ||
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN ||
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSDPA ||
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSUPA ||
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSPA)
        {
            current_rat=QUEC_NETMODE_WCDMA;
        }
        else if(gSysMainMode==ATCI_SYSINFO_SYSTEMO_MODE_GSM_GPRS || 
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM ||
                gSysMode==ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM_EGPRS)
        {
            current_rat=QUEC_NETMODE_GSM;
        }
	#endif			
#else
        if(gSysMainMode_temp==ATCI_SYSINFO_SYSTEMO_MODE_LTE )
        {
            current_rat=QUEC_NETMODE_LTE;
        } 
        else if(gSysMainMode_temp==ATCI_SYSINFO_SYSTEMO_MODE_WCDMA )
        {
            current_rat=QUEC_NETMODE_WCDMA;
        }
        else if(gSysMainMode_temp==ATCI_SYSINFO_SYSTEMO_MODE_GSM_GPRS )
        {
            current_rat=QUEC_NETMODE_GSM;
        } 
#endif
    }
#ifdef QUEC_CSQ_FIX
    atcmd_nw_log("gSysMainMode=%d,gSysMode=%d,current_rat=%d, need_attach=%d", gSysMainMode,gSysMode, current_rat, need_attach);
#else
    atcmd_nw_log("gSysMainMode=%d,current_rat=%d, need_attach=%d", gSysMainMode, current_rat, need_attach);	
#endif
    return current_rat;
}

void quec_get_current_rat_sinr(INT16 * sinr)
{
	 *sinr =-120;
	 mmExtendedSignal_quec *info_temp=NULL;
#if QUEC_DUAL_SIM_SUPPORT
	info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]);
#else
	 info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info);
#endif
	 quec_network_mode_type current_rat=quec_get_current_rat(0);
	 atcmd_nw_log("[quec rsrp] info_temp->rssi=%d,rsrp=%d, %d",info_temp->rssi,info_temp->rsrp, info_temp->rsrp-140);
	 switch(current_rat)
	 {
	   case  QUEC_NETMODE_GSM:
	   case  QUEC_NETMODE_LTE:
		if (QUEC_NETMODE_LTE == current_rat)
		{
			*sinr = info_temp->sinr;
		}
		else
		{
			 *sinr = info_temp->sinr;
		}
		break;
			 
	   case  QUEC_NETMODE_WCDMA: 
		   *sinr = info_temp->sinr; 
			 break;

	   default:
		 atcmd_nw_log("invalid rat=%d",current_rat);
		 break;
	}

	atcmd_nw_log("[quec sinr] sinr=%d",*sinr);
	return ;
}

void quec_get_current_rat_rsrp(INT16 * rsrp)
{
	*rsrp =-120;
	mmExtendedSignal_quec *info_temp=NULL;
#if QUEC_DUAL_SIM_SUPPORT
	info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]);
#else
	info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info);
#endif
	quec_network_mode_type current_rat=quec_get_current_rat(0);
	atcmd_nw_log("[quec rsrp] info_temp->rssi=%d,rsrp=%d, %d",info_temp->rssi,info_temp->rsrp, info_temp->rsrp-140);
	switch(current_rat)
	{
		case  QUEC_NETMODE_GSM:
		case  QUEC_NETMODE_LTE:
		if (QUEC_NETMODE_LTE == current_rat)
		{
			*rsrp = info_temp->rsrp;
		}
		else
		{
			*rsrp = info_temp->rssi;
		}
		break;
		   
		case  QUEC_NETMODE_WCDMA: 
		 *rsrp = info_temp->rscp; 
		   break;

		default:
		atcmd_nw_log("invalid rat=%d",current_rat);
		break;
	}

	atcmd_nw_log("[quec rsrp] rsrp=%d",*rsrp);
	return ;
}

#ifdef QUEC_MQTT_UNIFY_SUPPORT
void quec_uniot_get_current_rat_rsxx(UINT32* rsrp, UINT32* rsrq)
{
	*rsrp =-120;
	mmExtendedSignal_quec *info_temp=NULL;
#if QUEC_DUAL_SIM_SUPPORT
	info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]);
#else
	info_temp =(mmExtendedSignal_quec *)(&quec_netquality_info);
#endif
	quec_network_mode_type current_rat=quec_get_current_rat(0);
	atcmd_nw_log("[quec rsrp] info_temp->rssi=%d,rsrp=%d, %d",info_temp->rssi,info_temp->rsrp, info_temp->rsrp-140);
	switch(current_rat)
	{
		case  QUEC_NETMODE_GSM:
		case  QUEC_NETMODE_LTE:
		if (QUEC_NETMODE_LTE == current_rat)
		{
			*rsrp = info_temp->rsrp;
		}
		else
		{
			*rsrp = info_temp->rssi;
		}
		break;
		   
		case  QUEC_NETMODE_WCDMA: 
		 *rsrp = info_temp->rscp; 
		   break;

		default:
		atcmd_nw_log("invalid rat=%d",current_rat);
		break;
	}
	*rsrq = info_temp->rsrq;
	atcmd_nw_log("[quec rsrp] rsrp=%d",*rsrp);
}
#endif

void quec_get_current_rat_cellid_lac(UINT32 * cellId, UINT32 * lac)
{
	*cellId = 0;
	*lac = 0;
	quec_network_mode_type current_rat=quec_get_current_rat(0);
	switch(current_rat)
	{
		case QUEC_NETMODE_LTE:
		{
		#if QUEC_DUAL_SIM_SUPPORT
			CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info[isMasterSim0() ? SIM1 : SIM2];
		#else
			CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info;
		#endif
			*cellId = p_quec_cereg_info->cellId;
			*lac = p_quec_cereg_info->tac;
			break;
		}
		case QUEC_NETMODE_GSM:
		case QUEC_NETMODE_WCDMA: 
		{
		#if QUEC_DUAL_SIM_SUPPORT
			CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info[isMasterSim0() ? SIM1 : SIM2];
		#else
			CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info;
		#endif
		 	*cellId = p_quec_cgreg_info->cellId;
			*lac = p_quec_cgreg_info->lac;
		break;
		}
		default:
		  atcmd_nw_log("invalid rat=%d",current_rat);
		break;
	}

	atcmd_nw_log("CellID: %d, Lac: %d",*cellId, *lac);
	return ;
}

 /*===========================================================================

FUNCTION QUEC_REPORT_CREG

DESCRIPTION
  This function check if need report creg to avoid the same report

DEPENDENCIES
  None

RETURN VALUE
  returns the  0:not need report 1: need report
SIDE EFFECTS
  None
===========================================================================*/

UINT8 quec_report_creg(char * report_buf,UINT32 reqHandle)
{
	if(!quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
	{
		return 0;	
	}
	static char creg_buf[2][50] = {0};
    SIMID sim_id=SIM1;
    sim_id=isHandleForSim0(reqHandle)?SIM1:SIM2;
    if(((isMasterSim0()==TRUE && sim_id!=SIM1)||(isMasterSim0()!=TRUE && sim_id!=SIM2))
        &&
        ((getDualSimType()==CM_DUAL_SIM_SGIT)||(getDualSimType()==CM_DUAL_SIM_SINGLE_STANDBY))
       )
    {
        CPUartLogPrintf("%s,%d,DSSS only master sim need report",__FUNCTION__,__LINE__);
        return 0;
    }

	if(strcasecmp(creg_buf[sim_id], report_buf) == 0 )
	{
		return 0 ;
	}
	else
	{	
		memset(creg_buf[sim_id],0,sizeof(creg_buf[sim_id]));
		memcpy(creg_buf[sim_id],report_buf,strlen(report_buf));
		return 1;
	}
	   
}  

/*===========================================================================

FUNCTION QUEC_REPORT_CEREG

DESCRIPTION
  This function check if need report creg to avoid the same report

DEPENDENCIES
  None

RETURN VALUE
  returns the  0:not need report 1: need report
SIDE EFFECTS
  None
===========================================================================*/

UINT8 quec_report_cereg(char * report_buf,UINT32 reqHandle)
{

	static char cereg_buf[2][50] = {0};
    SIMID sim_id=SIM1;
    sim_id=isHandleForSim0(reqHandle)?SIM1:SIM2;
	if(!quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
	{
		return 0;	
	}

    if(((isMasterSim0()==TRUE && sim_id!=SIM1)||(isMasterSim0()!=TRUE && sim_id!=SIM2))
        &&
        ((getDualSimType()==CM_DUAL_SIM_SGIT)||(getDualSimType()==CM_DUAL_SIM_SINGLE_STANDBY))
       )
    {
        CPUartLogPrintf("%s,%d,DSSS only master sim need report",__FUNCTION__,__LINE__);
        return 0;
    }
       
	if(strcasecmp(cereg_buf[sim_id], report_buf) == 0 )
	{
		return 0 ;
	}
	else
	{	
		memset(cereg_buf[sim_id],0,sizeof(cereg_buf[sim_id]));
		memcpy(cereg_buf[sim_id],report_buf,strlen(report_buf));
		return 1;
	}
	   
}  

/*===========================================================================

FUNCTION QUEC_REPORT_CGREG

DESCRIPTION
  This function check if need report creg to avoid the same report

DEPENDENCIES
  None

RETURN VALUE
  returns the  0:not need report 1: need report
SIDE EFFECTS
  None
===========================================================================*/

UINT8 quec_report_cgreg(char * report_buf,UINT32 reqHandle)
{

	static char cgreg_buf[2][50] = {0};
    SIMID sim_id=SIM1;
    sim_id=isHandleForSim0(reqHandle)?SIM1:SIM2;
	if(!quectel_read_urc_ind_flag(QUECTEL_URC_ALL_IND))
	{
		return 0;	
	}
    if(((isMasterSim0()==TRUE && sim_id!=SIM1)||(isMasterSim0()!=TRUE && sim_id!=SIM2))
        &&
        ((getDualSimType()==CM_DUAL_SIM_SGIT)||(getDualSimType()==CM_DUAL_SIM_SINGLE_STANDBY))
       )
    {
        CPUartLogPrintf("%s,%d,DSSS only master sim need report",__FUNCTION__,__LINE__);
        return 0;
    }
       
	if(strcasecmp(cgreg_buf[sim_id], report_buf) == 0 )
	{
		return 0 ;
	}
	else
	{	
		memset(cgreg_buf[sim_id],0,sizeof(cgreg_buf[sim_id]));
		memcpy(cgreg_buf[sim_id],report_buf,strlen(report_buf));
		return 1;
	}
	   
}  
			
/*===========================================================================

FUNCTION quec_dual_nw_reoprt

DESCRIPTION
  This function to deal with the nw report according to SIM num;

DEPENDENCIES
  None

RETURN VALUE
  None
SIDE EFFECTS
  None
===========================================================================*/

void quec_dual_nw_reoprt(char *src_str,UINT16 str_tollen,UINT32 reqHandle)
{
    char *temp_str=NULL;
    char *temp_buff=NULL;
    if((src_str==NULL)||(str_tollen<=(strlen(src_str)+4)))
       return;
    if((isHandleForSim0(reqHandle)==FALSE)
        &&
       ((getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY)||(getDualSimType()==CM_DUAL_SIM_DUAL_STANDBY_FP)))
    {
        temp_buff=malloc(strlen(src_str)+4);
        if(temp_buff==NULL)
           return;
        memset(temp_buff,0,strlen(src_str)+4);
        temp_str=strstr(src_str,":");
        memcpy(temp_buff, src_str,(temp_str-src_str));
        snprintf((temp_buff+(temp_str-src_str)),(strlen(src_str)+4),"DS%s",temp_str);
        memset(src_str,0,(strlen(src_str)+4));
        strncpy(src_str, temp_buff, strlen(temp_buff));
        if(temp_buff!=NULL)
        {
           free(temp_buff);
           temp_buff=NULL;
        }
    }
    else
    {
       CPUartLogPrintf("%s,%d,MASTER SIM,NO NEED SPECIAL",__FUNCTION__,__LINE__);
    }
}
/*===========================================================================

FUNCTION QUEC_EXEC_QCFG_QNWINFO_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network information of the phone .

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
RETURNCODE_T quectel_exec_qnwinfo_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 
    *xid_p = atHandle;
    atcmd_nw_log("command type=%d",op);
    switch (op)
    {
    
        case TEL_EXT_ACTION_CMD:    
            {   
                if(network_infor_bitmsk !=0 )
                {
                   
                   atcmd_nw_log("error other commadn is executing :network_infor_bitmsk=%d",network_infor_bitmsk);
                   ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
                }
                else
                {
				#if QUEC_DUAL_SIM_SUPPORT
                   memset(&quec_qnwinfo[isMasterSim0() ? SIM1 : SIM2],0,sizeof(quec_qnwinfo[isMasterSim0() ? SIM1 : SIM2]));
				#else
                   memset(&quec_qnwinfo,0,sizeof(quec_qnwinfo));
				#endif
                   BIT_SET(network_infor_bitmsk,QNWINFO_GET) ;
                   ret = MM_GetSysInfo(atHandle);
                   
                }
                break;
           }
        case TEL_EXT_TEST_CMD:
        case TEL_EXT_SET_CMD:
        case TEL_EXT_GET_CMD:    
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}

/*===========================================================================

FUNCTION QUEC_EXEC_CGREG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network ps reg information of the phone .

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
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    UINT32 reg_status=0;
    UINT8 net_status=0;
#ifdef __QUEC_OEM_VER_LD__
	char lac_buf[LANDI_VAL_BUF_MAX] = {0};
    char cid_buf[LANDI_VAL_BUF_MAX] = {0};
#endif
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
    {
        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CGREG: (0-2)\r\n");
                    break;
                }    
            case TEL_EXT_GET_CMD: 
                {
				#if QUEC_DUAL_SIM_SUPPORT
                	CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info[isMasterSim0() ? SIM1 : SIM2];
				#else
                	CiPsNwRegInfo *p_quec_cgreg_info = &quec_cgreg_info;
				#endif
				
                    quectel_current_config_value_get(AT_CGREG,&reg_status);
					net_status=quec_regstatus_asr2quec(p_quec_cgreg_info->status, 1);
                    if(p_quec_cgreg_info->status !=0)
                    {    
                        if(reg_status==0 || reg_status==1)
                        {
                             sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
                        }
                        else 
                        {    
                            if(p_quec_cgreg_info->lacPresent &&(net_status == 1 || net_status == 5))
                            {   
                            	GET_VALID_VAL(lac_buf, p_quec_cgreg_info->lac);
       						#ifdef __QUEC_OEM_VER_LD__  
        						if (TRUE == Quectel_IsOEMLandiEnable())
        						{
            						GET_VALID_VAL(lac_buf, p_quec_cgreg_info->lac);
									GET_VALID_VAL(cid_buf, p_quec_cgreg_info->cellId);
									sprintf( resBuf,"+CGREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,lac_buf,cid_buf,quec_act_asr2quec(p_quec_cgreg_info->act));
        						}
			        			else
							#endif
			        			{
									sprintf( resBuf,"+CGREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cgreg_info->lac,p_quec_cgreg_info->cellId,quec_act_asr2quec(p_quec_cgreg_info->act));
			       				}
                            }
                            else
                            {
                               atcmd_nw_log("LAC/TAC not present");
                               sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
                            }
                        }
                    }
                    else
                    {	
					#if QUEC_DUAL_SIM_SUPPORT
	                	CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info[isMasterSim0() ? SIM1 : SIM2];
					#else
	                	CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info;
					#endif

                    	net_status=quec_regstatus_asr2quec(p_quec_cereg_info->status, 1);
                        if(reg_status==0 || reg_status==1)
                        {
                             sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
                        }
                        else 
                        {    
                            if(p_quec_cereg_info->tacPresent &&(net_status == 1 || net_status == 5))
                            {    
                            	#ifdef __QUEC_OEM_VER_LD__  
        						if (TRUE == Quectel_IsOEMLandiEnable())
        						{
            						GET_VALID_VAL(lac_buf, p_quec_cereg_info->tac);
									GET_VALID_VAL(cid_buf, p_quec_cereg_info->cellId);
									sprintf( resBuf,"+CGREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,lac_buf,cid_buf,quec_act_asr2quec(p_quec_cereg_info->act));
        						}
			        			else
								#endif
			        			{
									sprintf( resBuf,"+CGREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cereg_info->tac,p_quec_cereg_info->cellId,quec_act_asr2quec(p_quec_cereg_info->act));
			       				}
                            }
                            else
                            {
                               atcmd_nw_log("LAC/TAC not present");
                               sprintf( resBuf,"+CGREG: %d,%d\r\n",reg_status,net_status);
                            }
                        }
                    }
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:
                {
                    if((getExtValue(parameter_values_p, 0, &reg_status, 0, 2, 0) == TRUE) 
                        && (quectel_current_config_value_set(AT_CGREG,reg_status)==utlSUCCESS))
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    }
                    else
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                    }
                    break;
                        
                }
            case TEL_EXT_ACTION_CMD:
            default:
                {
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {
        return ciPSRegStatus(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
    }
}
#endif

#ifndef QUEC_MINI_SYSTEM_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_CEREG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network EPS ps reg information of the phone .

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
RETURNCODE_T quectel_exec_cereg_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    UINT32 reg_status=0;
    UINT8 net_status=0;

#ifdef __QUEC_OEM_VER_LD__
	char tac_buf[LANDI_VAL_BUF_MAX] = {0};
    char cid_buf[LANDI_VAL_BUF_MAX] = {0};
#endif
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
	{
        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CEREG: (0-2)\r\n");
                    break;
                }    
            case TEL_EXT_GET_CMD: 
                {
				#if QUEC_DUAL_SIM_SUPPORT
					CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info[isMasterSim0() ? SIM1 : SIM2];
				#else
					CiPs4GNwRegInfo *p_quec_cereg_info = &quec_cereg_info;
				#endif
                    quectel_current_config_value_get(AT_CEREG,&reg_status);
					net_status=quec_regstatus_asr2quec(p_quec_cereg_info->status, 1);
                    if(reg_status==0 || reg_status==1)
                    {
                         sprintf( resBuf,"+CEREG: %d,%d\r\n",reg_status,net_status);
                    }
                    else 
                    {    
                        if(p_quec_cereg_info->tacPresent &&(net_status == 1 || net_status == 5))
                        {    
						#ifdef __QUEC_OEM_VER_LD__  
        					if (TRUE == Quectel_IsOEMLandiEnable())
        					{
            					GET_VALID_VAL(tac_buf, p_quec_cereg_info->tac);
								GET_VALID_VAL(cid_buf, p_quec_cereg_info->cellId);
								sprintf( resBuf,"+CEREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,tac_buf,cid_buf,quec_act_asr2quec(p_quec_cereg_info->act));
        					}
			        		else
						#endif
			        		{
								sprintf( resBuf,"+CEREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_cereg_info->tac,p_quec_cereg_info->cellId,quec_act_asr2quec(p_quec_cereg_info->act));
			       			}
						}
                        else
                        {
                           atcmd_nw_log("TAC not present");
                           sprintf( resBuf,"+CEREG: %d,%d\r\n",reg_status,net_status);
                        }
                    }
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:
                {
                    if((getExtValue(parameter_values_p, 0, &reg_status, 0, 2, 0) == TRUE) 
                        && (quectel_current_config_value_set(AT_CEREG,reg_status)==utlSUCCESS))
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    }
                    else
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                    }
                    break;
                        
                }
            case TEL_EXT_ACTION_CMD:
            default:
                {
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {
        return ciERegStatus(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
    }
}
#endif   
/*===========================================================================

FUNCTION QUEC_EXEC_CREG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network cs reg information of the phone .

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
RETURNCODE_T quectel_exec_creg_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    UINT32 reg_status=0;
    UINT8 net_status=0;
	UINT8 cereg_status=0;
#ifdef __QUEC_OEM_VER_LD__
	char lac_buf[LANDI_VAL_BUF_MAX] = {0};
    char cid_buf[LANDI_VAL_BUF_MAX] = {0};
#endif

    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
    {
        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CREG: (0-2)\r\n");
                    break;
                }    
            case TEL_EXT_GET_CMD: 
                {
				#if QUEC_DUAL_SIM_SUPPORT
					CiMmPrimRegResultInd *p_quec_creg_info = &quec_creg_info[isMasterSim0() ? SIM1 : SIM2];
				#else
					CiMmPrimRegResultInd *p_quec_creg_info = &quec_creg_info;
				#endif

				#ifdef QUECTEL_NETWORK_SUPPORT
                    /*isaac-20200810 不插卡返回基站信息，at+qcfg="creg/emergency",1控制*/
                    extern UINT8 quec_creg_report_emergency;
                    if (1 == quec_creg_report_emergency)
                    {
						#if QUEC_DUAL_SIM_SUPPORT
							net_status=quec_regstatus_asr2quec(quec_creg_info[isMasterSim0() ? SIM1 : SIM2].RegStatus, 0);
						#else
	                        net_status=quec_regstatus_asr2quec(quec_creg_info.RegStatus, 0);
						#endif
                    }
                    else 
				#endif
                    {
						#if QUEC_DUAL_SIM_SUPPORT
							net_status=quec_regstatus_asr2quec(quec_creg_info[isMasterSim0() ? SIM1 : SIM2].RegStatus, 1);
						#else
	                	    net_status=quec_regstatus_asr2quec(quec_creg_info.RegStatus, 1);
						#endif
                    }
					
					//connor.wu if use the china telecom and register on lte the creg status return 0 
					//this is accord with 3GPP we just want to be in accordance with Qualcommm
				#if QUEC_DUAL_SIM_SUPPORT
					cereg_status=quec_regstatus_asr2quec(quec_cereg_info[isMasterSim0() ? SIM1 : SIM2].status, 1);
				#else
					cereg_status=quec_regstatus_asr2quec(quec_cereg_info.status, 1);
				#endif 
				
					if(net_status==0 && cereg_status != 0)
					{
						net_status=cereg_status;
					}
					
                    quectel_current_config_value_get(AT_CREG,&reg_status);
					
                    if(reg_status==0 || reg_status==1)
                    {
                         sprintf( resBuf,"+CREG: %d,%d\r\n",reg_status,net_status);
                    }
                    else 
                    {    
                        if(p_quec_creg_info->info.Present &&(net_status == 1 || net_status == 5 || net_status == 6) )
                        {    
							#ifdef __QUEC_OEM_VER_LD__  
        					if (TRUE == Quectel_IsOEMLandiEnable())
        					{
            					GET_VALID_VAL(lac_buf, p_quec_creg_info->info.LocArea);
								GET_VALID_VAL(cid_buf, p_quec_creg_info->info.CellId);
								sprintf( resBuf,"+CREG: %d,%d,\"%s\",\"%s\",%d\r\n",reg_status,net_status,lac_buf,cid_buf,quec_act_asr2quec(p_quec_creg_info->info.AcT));
        					}
			        		else
							#endif
			        		{ 
								#ifdef QUECTEL_NETWORK_SUPPORT
			        		    /*isaac-20200810 不插卡返回基站信息，at+qcfg="creg/emergency",1控制*/
			        		    if ( (1 == quec_creg_report_emergency) && (6 == net_status) )
                                {
                                    /*配置at+creg=2后,和creg urc上报保持一致*/
                                    net_status = 0;
                                }  
								#endif
								sprintf( resBuf,"+CREG: %d,%d,\"%04X\",\"%04X\",%d\r\n",reg_status,net_status,p_quec_creg_info->info.LocArea,p_quec_creg_info->info.CellId,quec_act_asr2quec(p_quec_creg_info->info.AcT));
			       			}	
						}
                        else
                        {
                           atcmd_nw_log("LAC not present");
                           sprintf( resBuf,"+CREG: %d,%d\r\n",reg_status,net_status);
                        }
                    }
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:
                {
                    if((getExtValue(parameter_values_p, 0, &reg_status, 0, 2, 0) == TRUE) 
                        && (quectel_current_config_value_set(AT_CREG,reg_status)==utlSUCCESS))
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    }
                    else
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                    }
                    break;
                        
                }
            case TEL_EXT_ACTION_CMD:
            default:
                {
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {	
		#ifndef LTEONLY_THIN
        /* Fitz.xu 20201104: to fix STASR1601-1884 */
        rc = ciRegStatus(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
		#endif

		return rc;
    }
}

#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
extern bool g_ecno_ci_send;
QuecOSStatus quec_qcsq_wcdma_check(UINT32 atHandle)
{
#if QUEC_DUAL_SIM_SUPPORT
	mmExtendedSignal_quec *p_quec_netquality_info = &quec_netquality_info[isMasterSim0() ? SIM1 : SIM2];
#else
	mmExtendedSignal_quec *p_quec_netquality_info = &quec_netquality_info;
#endif

	atcmd_nw_log("mode=%d,rscp=%d,network_infor_bitmsk=%d",quec_get_current_rat(1),p_quec_netquality_info->rscp,network_infor_bitmsk);
	if((quec_get_current_rat(1) == QUEC_NETMODE_WCDMA)&&(p_quec_netquality_info->rscp != 255)&&(network_infor_bitmsk == 0))
	{
		g_ecno_ci_send = TRUE;
		BIT_SET(network_infor_bitmsk,QENG_SERVINGCELL_GET) ;
	    MM_GetSysInfo(atHandle);
		return QUEC_SUCCESS;
	}
	return kGeneralErr;
}
#endif


UINT8 quec_report_qcsq(UINT8 force_report,char * report_buf)
{

	static char qcsq_buf[50] = {0};
	char *p;
	uint8 rssi_temp =0;

#if QUEC_DUAL_SIM_SUPPORT
	 mmExtendedSignal_quec *p_quec_netquality_info = &quec_netquality_info[isMasterSim0() ? SIM1 : SIM2];
#else
	 mmExtendedSignal_quec *p_quec_netquality_info = &quec_netquality_info;
#endif

	 p=report_buf;
	 atcmd_nw_log("mode=%d,rssi=%d,ber=%d,rscp=%d,ecno=%d,rsrq=%d,rsrp=%d,sinr=%d",quec_get_current_rat(1),
	 	p_quec_netquality_info->rssi,p_quec_netquality_info->ber,p_quec_netquality_info->rscp,p_quec_netquality_info->ecno,
	 	p_quec_netquality_info->rsrq,p_quec_netquality_info->rsrp,p_quec_netquality_info->sinr);
	if(quec_get_current_rat(1) == QUEC_NETMODE_GSM)
	{
		if(p_quec_netquality_info->rssi == 99)
		{
			sprintf( report_buf,"+QCSQ: \"GSM\",0\r\n");
		}
		else
		{
			/******************************************************************
			<rxlev>: integer type, received signal strength level (see 3GPP TS 45.008 [20] subclause 8.1.4).
	 		0		rssi < -110 dBm
			1		-110 dBm < rssi < -109 dBm
			2		-109 dBm < rssi < -108 dBm
			:			:	:	:
			61		-50 dBm < rssi < -49 dBm
			62		-49 dBm < rssi < -48 dBm
			63		-48 dBm < rssi
			99		not known or not detectable
	 		******************************************************************/
			sprintf( report_buf,"+QCSQ: \"GSM\",%d\r\n",(-1)*(p_quec_netquality_info->rssi-110)); 
		}
		
	}
	else if(quec_get_current_rat(1) == QUEC_NETMODE_WCDMA)
	{
		//becasue WCDMA does not had RSSI so we use RSCP
		if(p_quec_netquality_info->rscp == 255)
		{
			p +=sprintf( p,"+QCSQ: \"WCDMA\",0");
		}
		else
		{
			#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
				atcmd_nw_log("qcsq,rscp=%d,g_3g_ecno=%d",p_quec_netquality_info->rscp,g_3g_ecno);
				if((g_3g_ecno >QUEC_ECNO_MAX)||(g_3g_ecno <QUEC_ECNO_MIN)) //Chaim 20190928 check  g_3g_ecno is valid
				{
					atcmd_nw_log("qcsq g_3g_ecno=%d is invalid",g_3g_ecno);
					#ifdef __QUEC_OEM_VER_PAX__
						g_3g_ecno = -10;	//Chaim 20190928 use pax default value
					#else
						g_3g_ecno = 0;	//Chaim 20190928 use default value
					#endif 
				}
				//Chaim 20191212 from qualcomm
				 /**< RSSI in positive dBm. 75 means -75 dBm. The ranges are as follows:
		           - AMPS:      -110 to -89 dBm.
		           - 800 CDMA:  -105 to -90 dBm.
		           - 1900 CDMA: -108 to -93 dBm.
		           - GSM/WCDMA: -105 to -60 dBm. 
		           - TD-SCDMA:  -120 to -25 dBm. */
				{
					rssi_temp = -1*(p_quec_netquality_info->rscp-120+5-g_3g_ecno);
					atcmd_nw_log("qcsq,rscp=%d,ecno=%d,rssi_temp=%d",p_quec_netquality_info->rscp,g_3g_ecno,rssi_temp);
					if(rssi_temp >120)
					{
						rssi_temp =120;	
					}
					else if(rssi_temp < 25)
					{
						rssi_temp = 25;	
					}
					else
					{
						// can not go to here
					}
				}
				   
				 p +=sprintf( p,"+QCSQ: \"WCDMA\",%d",rssi_temp); //Chaim 20190917 if rscp is positive,need rscp-120
				//p +=sprintf( p,"+QCSQ: \"WCDMA\",%d",-1*(quec_netquality_info.rscp-120-g_3g_ecno)); //Chaim 20190917 if rscp is positive,need rscp-120
			#else
				p +=sprintf( p,"+QCSQ: \"WCDMA\",%d",(-1)*((p_quec_netquality_info->rscp*2)/3-110)); 
			#endif
		}

		if(p_quec_netquality_info->rscp == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			<rscp>: integer type, received signal code power (see 3GPP TS 25.133 [95] subclause 9.1.1.3 and 3GPP TS 25.123 [96] subclause 9.1.1.1.3).
			0		rscp < -120 dBm
			1		-120 dBm < rscp < -119 dBm
			2		-119 dBm < rscp < -118 dBm
			:			:	:	:
			94		-27 dBm < rscp < -26 dBm
			95		-26 dBm < rscp < -25 dBm
			96	-	25 dBm < rscp
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d",p_quec_netquality_info->rscp-120);
		}

		if(p_quec_netquality_info->ecno == 255)
		{
			p +=sprintf( p,",255\r\n");
		}
		else
		{
			/******************************************************************
			<ecno>: integer type, ratio of the received energy per PN chip to the total received power spectral density (see 3GPP TS 25.133 [95] subclause).
			0		Ec/Io < -24 dB
			1		-24 dB < Ec/Io < -23.5 dB
			2		-23.5 dB < Ec/Io < -23 dB
			:			:	:	:
			47		-1 dB < Ec/Io < -0.5 dB
			48		-0.5 dB < Ec/Io < 0 dB
			49		0 dB < Ec/Io
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d\r\n",p_quec_netquality_info->ecno/2-24);
		}
		
	}
	else if(quec_get_current_rat(1) == QUEC_NETMODE_LTE)
	{
		if(p_quec_netquality_info->rssi == 99)
		{
			p +=sprintf( p,"+QCSQ: \"LTE\",0");
		}
		else
		{
			p +=sprintf( p,"+QCSQ: \"LTE\",%d",(-1)*(p_quec_netquality_info->rssi-110));
		}

		if(p_quec_netquality_info->rsrp == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			<rsrp>: integer type, reference signal received power (see 3GPP TS 36.133 [96] subclause 9.1.4).
			0		rsrp < -140 dBm
			1		-140 dBm < rsrp < -139 dBm
			2		-139 dBm < rsrp < -138 dBm
			:			:	:	:
			95		-46 dBm < rsrp < -45 dBm
			96		-45 dBm < rsrp < -44 dBm
			97		-44 dBm < rsrp
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d",p_quec_netquality_info->rsrp- 140);
		}

		if(p_quec_netquality_info->sinr == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			 to be same with Qualcomm
			 For LTE SINR: 10xdB values which are from -200 to 300 
                        are mapped to range 0 - 250. -20 db maps to 0, 
                        -19.8 db maps to 1, -19.6 maps to 2 ....
                        30 db maps to 250 
	 		******************************************************************/
			p +=sprintf( p,",%d",(p_quec_netquality_info->sinr+20)*5);
		}

		if(p_quec_netquality_info->rsrq == 255)
		{
			p +=sprintf( p,",255\r\n");
		}
		else
		{
			/******************************************************************
			<rsrq>: integer type, reference signal received quality (see 3GPP TS 36.133 [96] subclause 9.1.7).
			0		rsrq < -19.5 dB
			1		-19.5 dB < rsrq < -19 dB
			2		-19 dB < rsrq < -18.5 dB
			:			:	:	:
			32		-4 dB < rsrq < -3.5 dB
			33		-3.5 dB < rsrq < -3 dB
			34		-3 dB < rsrq
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d\r\n",p_quec_netquality_info->rsrq/2-20);
		}
	}
	else
	{
		sprintf( report_buf,"+QCSQ: \"NOSERVICE\"\r\n");
	}
	
	if(strcasecmp(qcsq_buf, report_buf) == 0 && force_report==0 )
	{
		return 0 ;
	}
	else
	{	
		memset(qcsq_buf,0,sizeof(qcsq_buf));
		memcpy(qcsq_buf,report_buf,strlen(report_buf));
		return 1;
	}

}

//Fitz.xu 20211231: To fix STASR1601-4812
#if QUEC_DUAL_SIM_SUPPORT
UINT8 quec_report_qcsq_dual_sim(UINT8 force_report,char * report_buf, char simid)
{
	char *p;
	uint8 rssi_temp =0;
	mmExtendedSignal_quec *p_quec_netquality_info = NULL;

	if (simid == SIM1)
	{
		p_quec_netquality_info = &quec_netquality_info[SIM1];
	}
	else
	{
		p_quec_netquality_info = &quec_netquality_info[SIM2];
	}
	
	 p=report_buf;
	 atcmd_nw_log("mode=%d,rssi=%d,ber=%d,rscp=%d,ecno=%d,rsrq=%d,rsrp=%d,sinr=%d",quec_get_current_rat(1),
	 	p_quec_netquality_info->rssi,p_quec_netquality_info->ber,p_quec_netquality_info->rscp,p_quec_netquality_info->ecno,
	 	p_quec_netquality_info->rsrq,p_quec_netquality_info->rsrp,p_quec_netquality_info->sinr);
	if(quec_get_current_rat(1) == QUEC_NETMODE_GSM)
	{
		if(p_quec_netquality_info->rssi == 99)
		{
			sprintf( report_buf,"\"GSM\",0\r\n");
		}
		else
		{
			/******************************************************************
			<rxlev>: integer type, received signal strength level (see 3GPP TS 45.008 [20] subclause 8.1.4).
	 		0		rssi < -110 dBm
			1		-110 dBm < rssi < -109 dBm
			2		-109 dBm < rssi < -108 dBm
			:			:	:	:
			61		-50 dBm < rssi < -49 dBm
			62		-49 dBm < rssi < -48 dBm
			63		-48 dBm < rssi
			99		not known or not detectable
	 		******************************************************************/
			sprintf( report_buf,"\"GSM\",%d\r\n",(-1)*(p_quec_netquality_info->rssi-110)); 
		}
		
	}
	else if(quec_get_current_rat(1) == QUEC_NETMODE_WCDMA)
	{
		//becasue WCDMA does not had RSSI so we use RSCP
		if(p_quec_netquality_info->rscp == 255)
		{
			p +=sprintf( p,"\"WCDMA\",0");
		}
		else
		{
			#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
				atcmd_nw_log("qcsq,rscp=%d,g_3g_ecno=%d",p_quec_netquality_info->rscp,g_3g_ecno);
				if((g_3g_ecno >QUEC_ECNO_MAX)||(g_3g_ecno <QUEC_ECNO_MIN)) //Chaim 20190928 check  g_3g_ecno is valid
				{
					atcmd_nw_log("qcsq g_3g_ecno=%d is invalid",g_3g_ecno);
					#ifdef __QUEC_OEM_VER_PAX__
						g_3g_ecno = -10;	//Chaim 20190928 use pax default value
					#else
						g_3g_ecno = 0;	//Chaim 20190928 use default value
					#endif 
				}
				//Chaim 20191212 from qualcomm
				 /**< RSSI in positive dBm. 75 means -75 dBm. The ranges are as follows:
		           - AMPS:      -110 to -89 dBm.
		           - 800 CDMA:  -105 to -90 dBm.
		           - 1900 CDMA: -108 to -93 dBm.
		           - GSM/WCDMA: -105 to -60 dBm. 
		           - TD-SCDMA:  -120 to -25 dBm. */
				{
					rssi_temp = -1*(p_quec_netquality_info->rscp-120+5-g_3g_ecno);
					atcmd_nw_log("qcsq,rscp=%d,ecno=%d,rssi_temp=%d",p_quec_netquality_info->rscp,g_3g_ecno,rssi_temp);
					if(rssi_temp >120)
					{
						rssi_temp =120;	
					}
					else if(rssi_temp < 25)
					{
						rssi_temp = 25;	
					}
					else
					{
						// can not go to here
					}
				}
				   
				 p +=sprintf( p,"\"WCDMA\",%d",rssi_temp); //Chaim 20190917 if rscp is positive,need rscp-120
				//p +=sprintf( p,"+QCSQ: \"WCDMA\",%d",-1*(quec_netquality_info.rscp-120-g_3g_ecno)); //Chaim 20190917 if rscp is positive,need rscp-120
			#else
				p +=sprintf( p,"\"WCDMA\",%d",(-1)*((p_quec_netquality_info->rscp*2)/3-110)); 
			#endif
		}

		if(p_quec_netquality_info->rscp == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			<rscp>: integer type, received signal code power (see 3GPP TS 25.133 [95] subclause 9.1.1.3 and 3GPP TS 25.123 [96] subclause 9.1.1.1.3).
			0		rscp < -120 dBm
			1		-120 dBm < rscp < -119 dBm
			2		-119 dBm < rscp < -118 dBm
			:			:	:	:
			94		-27 dBm < rscp < -26 dBm
			95		-26 dBm < rscp < -25 dBm
			96	-	25 dBm < rscp
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d",p_quec_netquality_info->rscp-120);
		}

		if(p_quec_netquality_info->ecno == 255)
		{
			p +=sprintf( p,",255\r\n");
		}
		else
		{
			/******************************************************************
			<ecno>: integer type, ratio of the received energy per PN chip to the total received power spectral density (see 3GPP TS 25.133 [95] subclause).
			0		Ec/Io < -24 dB
			1		-24 dB < Ec/Io < -23.5 dB
			2		-23.5 dB < Ec/Io < -23 dB
			:			:	:	:
			47		-1 dB < Ec/Io < -0.5 dB
			48		-0.5 dB < Ec/Io < 0 dB
			49		0 dB < Ec/Io
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d\r\n",p_quec_netquality_info->ecno/2-24);
		}
		
	}
	else if(quec_get_current_rat(1) == QUEC_NETMODE_LTE)
	{
		if(p_quec_netquality_info->rssi == 99)
		{
			p +=sprintf( p,"\"LTE\",0");
		}
		else
		{
			p +=sprintf( p,"\"LTE\",%d",(-1)*(p_quec_netquality_info->rssi-110));
		}

		if(p_quec_netquality_info->rsrp == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			<rsrp>: integer type, reference signal received power (see 3GPP TS 36.133 [96] subclause 9.1.4).
			0		rsrp < -140 dBm
			1		-140 dBm < rsrp < -139 dBm
			2		-139 dBm < rsrp < -138 dBm
			:			:	:	:
			95		-46 dBm < rsrp < -45 dBm
			96		-45 dBm < rsrp < -44 dBm
			97		-44 dBm < rsrp
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d",p_quec_netquality_info->rsrp- 140);
		}

		if(p_quec_netquality_info->sinr == 255)
		{
			p +=sprintf( p,",255");
		}
		else
		{
			/******************************************************************
			 to be same with Qualcomm
			 For LTE SINR: 10xdB values which are from -200 to 300 
                        are mapped to range 0 - 250. -20 db maps to 0, 
                        -19.8 db maps to 1, -19.6 maps to 2 ....
                        30 db maps to 250 
	 		******************************************************************/
			p +=sprintf( p,",%d",(p_quec_netquality_info->sinr+20)*5);
		}

		if(p_quec_netquality_info->rsrq == 255)
		{
			p +=sprintf( p,",255\r\n");
		}
		else
		{
			/******************************************************************
			<rsrq>: integer type, reference signal received quality (see 3GPP TS 36.133 [96] subclause 9.1.7).
			0		rsrq < -19.5 dB
			1		-19.5 dB < rsrq < -19 dB
			2		-19 dB < rsrq < -18.5 dB
			:			:	:	:
			32		-4 dB < rsrq < -3.5 dB
			33		-3.5 dB < rsrq < -3 dB
			34		-3 dB < rsrq
			255 not known or not detectable
	 		******************************************************************/
			p +=sprintf( p,",%d\r\n",p_quec_netquality_info->rsrq/2-20);
		}
	}
	else
	{
		sprintf( report_buf,"\"NOSERVICE\"\r\n");
	}
	
	return 1;
}

#endif

/*===========================================================================

FUNCTION QUEC_EXEC_QCSQ_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network signal quality information of the phone .
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

RETURNCODE_T quectel_exec_qcsq_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	UINT32 qcsq_report_flag=0;
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QCSQ: \"NOSERVICE\",\"GSM\",\"WCDMA\",\"LTE\"\r\n");
                break;
            }
		case TEL_EXT_GET_CMD:

			{
				sprintf( resBuf,"+QCSQ: %d\r\n",quec_qcsq_report_flag);
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                break;
			}
		case TEL_EXT_SET_CMD:
			
		case TEL_EXT_ACTION_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
				if(param_num == 0 )
				{
					#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
	 					if(QUEC_SUCCESS == quec_qcsq_wcdma_check(atHandle))
	 					{
	 						atcmd_nw_log("param=%d,pax wcdma need ecno value",param_num);
							ret = CIRC_SUCCESS;
	 						break;
	 					}
 					#endif
					quec_report_qcsq(1,resBuf);
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
				}
				else if (param_num == 1 && (getExtValue(parameter_values_p, 0, &qcsq_report_flag, 0, 2, 0) == TRUE))
				{
					if((0 != qcsq_report_flag)&&(1 != qcsq_report_flag))
					{
						atcmd_nw_log("qcsq_report_flag=%d is invalid",qcsq_report_flag);
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);	
					}
					else
					{
						if(quec_qcsq_report_flag !=qcsq_report_flag)
						{
							quec_qcsq_report_flag=qcsq_report_flag;
							
							//Chaim 2020.02.09 fix jira STASR1802S-982 not report first 
							/*
							if(quec_qcsq_report_flag ==1)
							{
								#if defined (__QUEC_OEM_VER_PAX__) || defined (QUEC_NETWORK_GET_ECNO)
									if(QUEC_SUCCESS == quec_qcsq_wcdma_check(atHandle))
									{
										atcmd_nw_log("param=%d,pax wcdma need ecno value",param_num);
										ret = CIRC_SUCCESS;
										break;
									}
								#endif
								
								//Chaim 2020.02.09 fix jira STASR1802S-418 not report first 
								//quec_report_qcsq(1,resBuf);
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}
							else  
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}*/
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
						else
						{
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
					}

				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				
}
                break;
                    
            }
        default:
            {	
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    
    }
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}

   
/*===========================================================================

FUNCTION QUEC_EXEC_CSQ_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network signal quality information of the phone .

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
RETURNCODE_T quectel_exec_csq_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    UINT8 reg_status=0;
    INT16 csq_temp1=99;
	INT16 csq_temp2=99;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
	{
        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CSQ: (0-31,99),(0-7,99)\r\n");
                    break;
                }    
            case TEL_EXT_ACTION_CMD: 
                {			
				#if QUEC_DUAL_SIM_SUPPORT
                    quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]),&csq_temp1,&csq_temp2);
				#else
                    quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info),&csq_temp1,&csq_temp2);
				#endif 
#ifdef 	QUECTEL_NETWORK_SUPPORT
                    /*Isaac 20201223 宝蓝客户，添加搜网状态下或者OOS,返回6,at+qeng,at+qnwinfo*/
                    if ((1 == quec_get_csq_type()) && (0 == quec_get_current_net_regstatus()))
                    {
                       /* 宝蓝csq门限值为3，重新初始化 */
                       csq_temp1 = RSSI_OFFSET_6;  
                    }
#endif
					sprintf( resBuf,"+CSQ: %d,%d\r\n",csq_temp1,csq_temp2);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:				
            case TEL_EXT_GET_CMD:
            default:
                {
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {
        return ciSignalQuality(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
    }
}

/*===========================================================================

FUNCTION QUEC_EXEC_CREG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network Packet Domain Event Reporting .

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

RETURNCODE_T quectel_exec_cgerep_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
    {
	#if QUEC_DUAL_SIM_SUPPORT
		Quec_cgerep_type *p_cgerep_info = &cgerep_info[isMasterSim0() ? SIM1 : SIM2];
	#else
		Quec_cgerep_type *p_cgerep_info = &cgerep_info;
	#endif
		int tmp_mode = (int)p_cgerep_info->mode;
		int tmp_bfr = (int)p_cgerep_info->bfr;

        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CGEREP: (0-2),(0,1)\r\n");
                    break;
                }    
            case TEL_EXT_GET_CMD: 
                {
                    sprintf( resBuf,"+CGEREP: %d,%d\r\n",p_cgerep_info->mode, p_cgerep_info->bfr);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:
                {
                	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
					atcmd_nw_log("param_num=%d",param_num);
                    if(param_num==1 && (getExtValue(parameter_values_p, 0, &tmp_mode, 0, 2, 0) == TRUE))
                    {
                    	p_cgerep_info->mode = tmp_mode;
                    	atcmd_nw_log("mode=%d",p_cgerep_info->mode);
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    }
                    else if(param_num==2 
							&& (getExtValue(parameter_values_p, 0, &tmp_mode, 0, 2, 0) == TRUE)
							&& (getExtValue(parameter_values_p, 1, &tmp_bfr, 0, 1, 0) == TRUE))
                    {
						//Fitz.xu 20211126: To fix FAE-18770
						p_cgerep_info->mode = tmp_mode;
						p_cgerep_info->bfr = tmp_bfr;
						
                    	atcmd_nw_log("mode=%d,bfr=%d",p_cgerep_info->mode,p_cgerep_info->bfr);
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                    }
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					}
                    break;
                        
                }
            case TEL_EXT_ACTION_CMD:
            default:
                {	
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {	
        return ciCGEREP(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
    }
}
   
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
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	int ctzr_temp=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    if(QUEC_IS_VALID_ATP(atp_index))//when AT\PPP\UART channel, we handle it as quectel function, else if it is virtual at channel, still go with ASR function like query param of network with at cmd
	{
        switch (op)
        {
            case TEL_EXT_TEST_CMD:
                {   
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CTZR: (0-2)\r\n");
                    break;
                }    
            case TEL_EXT_GET_CMD: 
                {
                    sprintf( resBuf,"+CTZR: %d\r\n",ctzr_reporting);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                    break;
                }
            case TEL_EXT_SET_CMD:
                {
                	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
					atcmd_nw_log("param_num=%d",param_num);
                    if(param_num==1 && (getExtValue(parameter_values_p, 0, &ctzr_temp, 0, 2, 0) == TRUE))
                    {
                    	atcmd_nw_log("ctzr_reporting=%d",ctzr_temp);
						if(ctzr_temp != ctzr_reporting)
						{
							ctzr_reporting = (UINT8)ctzr_temp;
							if(quectel_nv_fat_write(QUEC_AT_CTZRVALUE, &ctzr_reporting, sizeof(ctzr_reporting))==QUEC_FAT_SUCCESS)
							{						
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}
							else
							{
								atcmd_nw_log("save_to_nv ERROR");
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
							}
						}
						else
						{
                        	ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
                    }
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					}
                    break;
                        
                }
            case TEL_EXT_ACTION_CMD:
            default:
                {	
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                    break;
                }
     
        }
        rc = HANDLE_RETURN_VALUE(ret); 
        return(rc);
    }
    else
    {	
        return ciCTZR(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
    }
}
/*===========================================================================

FUNCTION QUEC_EXEC_QQENG_CMD

DESCRIPTION
  This function get the monitor_type of the QENG cmd

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of  monitor_type of the QENG cmd
  possible values:
    utlSUCCESS : valid monitor_type
    utlFAILED : invalid monitor_type

SIDE EFFECTS
  None
===========================================================================*/

quectel_qeng_query_e_type  quec_qeng_get_monitor_type(char  * monitor_type)
{
    uint32  type_index = 0;
    
    for(type_index = 0; type_index < qeng_type_num;type_index++)
    {
        if(strncasecmp(monitor_type, qeng_type_name[type_index], strlen((char*)qeng_type_name[type_index])) == 0
            &&(strlen((char*)monitor_type) ==  strlen((char*)qeng_type_name[type_index])))
        {
            break;
        }
    }

    return (quectel_qeng_query_e_type)type_index;
}  

/*===========================================================================

FUNCTION QUEC_EXEC_QQENG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network cell information of the phone .

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
RETURNCODE_T quectel_exec_qeng_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 	
    *xid_p = atHandle;
    atcmd_nw_log("command type=%d",op);
	char  qeng_cmd_str[40] = {0};
	UINT8 qeng_cmd_str_len=0;
	quectel_qeng_query_e_type qeng_monitor_type=QUECTEL_QENG_MAX_MODE;
	char res_buf[50]={0};
    switch (op)
    {
    
        case TEL_EXT_SET_CMD:    
            {   
            	if(network_infor_bitmsk !=0 )
                {
                   
                	atcmd_nw_log("error other commadn is executing :network_infor_bitmsk=%d",network_infor_bitmsk);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
					break;
                }
                else if((getExtString(parameter_values_p, 0, qeng_cmd_str, sizeof(qeng_cmd_str), &qeng_cmd_str_len, NULL) != TRUE)
					 	|| ((qeng_monitor_type=quec_qeng_get_monitor_type(qeng_cmd_str)) == QUECTEL_QENG_MAX_MODE))
                {
                	ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;

				}
				switch(qeng_monitor_type)
            	{
	                case QUECTEL_QENG_SCELL_MODE:
	                {
	                	BIT_SET(network_infor_bitmsk,QENG_SERVINGCELL_GET) ;
	                    ret = MM_GetSysInfo(atHandle);
						break;
	                }

	                case QUECTEL_QENG_NCELL_MODE:
	                {
	                    BIT_SET(network_infor_bitmsk,QENG_NEIGHBOURCELL_GET) ;
	                    ret = MM_GetSysInfo(atHandle);
						break;
	                }
					
					#ifndef ENABLE_DM_LTEONLY 
					case QUECTEL_QENG_3G_USUAL_INFO:
	                {
	                    BIT_SET(network_infor_bitmsk,QENG_3GCOMM_GET) ;
	                    ret = MM_GetSysInfo(atHandle);
						break;
	                }
					#endif
	                default:
                	{
                		ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                		break;
	                }
	                
            	}
				break;
        }
        case TEL_EXT_TEST_CMD:
        	{
        	   
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QENG: (\"servingcell\",\"neighbourcell\",\"3gcomm\")");
				break;
        	}
        case TEL_EXT_ACTION_CMD:
        case TEL_EXT_GET_CMD:    
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}


/*===========================================================================

FUNCTION QUEC_EXEC_QLTS_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command Obtain the Latest Time Synchronized Through Network .

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

RETURNCODE_T quectel_exec_qlts_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	qlts_mode=0;
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QLTS: (0-2)\r\n");
                break;
            }
		case TEL_EXT_SET_CMD:
		case TEL_EXT_ACTION_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
                if(!(param_num==0 || (param_num==1 && (getExtValue(parameter_values_p, 0, &qlts_mode, 0, 2, 0) == TRUE))))
                {
                	
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
                }
				atcmd_nw_log("mode=%d",qlts_mode);
                ret = Quec_GetRealTimeClock(atHandle);
                break;
                    
            }
        default:
            {	
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    
    }
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}
/*===========================================================================
  
  FUNCTION Quectel_GDCNTResetAllCnt
  
  DESCRIPTION
	 This function reset the GDCNT.
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 None
  SIDE EFFECTS
	 None
  ===========================================================================*/
QuecOSStatus Quectel_GDCNTResetAllCnt(void)
{
	atcmd_nw_log("ResetAllCnt");
    QuecDataCntInfo.u64TotalRxCnt = 0;
    QuecDataCntInfo.u64TotalTxCnt = 0;
    return Quectel_GDCNTSaveParamToNV();
}

/*===========================================================================
  
  FUNCTION Quectel_GDCNTUpdateAllCnt
  
  DESCRIPTION
	 This function update the GDCNT.
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 None
  SIDE EFFECTS
	 None
  ===========================================================================*/
void Quectel_GDCNTUpdateAllCnt(void)
{
	atcmd_nw_log("GDCNTUpdateAllCnt PrevRx=%llu,PrevTx=%llu,TotalRx=%llu,TotalTx=%llu",
		QuecDataCntInfo.u64PrevRxCnt,
		QuecDataCntInfo.u64PrevTxCnt,
		QuecDataCntInfo.u64TotalRxCnt,
		QuecDataCntInfo.u64TotalTxCnt);
	
	UINT64 rx_byte=0;
	UINT64 tx_byte=0;
	rx_byte=get_rx_byte_all();
	tx_byte=get_tx_byte_all();

	if(rx_byte >= QuecDataCntInfo.u64PrevRxCnt)
	{
	    QuecDataCntInfo.u64TotalRxCnt+=rx_byte-QuecDataCntInfo.u64PrevRxCnt;
	}
	else //the total size had expire UINT64 so we start from 0 again 
	{
		QuecDataCntInfo.u64TotalRxCnt=rx_byte;
	}
	
	if(tx_byte >= QuecDataCntInfo.u64PrevTxCnt)
	{
		QuecDataCntInfo.u64TotalTxCnt+=tx_byte-QuecDataCntInfo.u64PrevTxCnt;
	}
	else //the total size had expire UINT64 so we start from 0 again 
	{
		QuecDataCntInfo.u64TotalTxCnt=tx_byte;
	}
	
	QuecDataCntInfo.u64PrevRxCnt=rx_byte;
	QuecDataCntInfo.u64PrevTxCnt=tx_byte;
}

/*===========================================================================
  
  FUNCTION Quectel_GDCNTResetAllCnt
  
  DESCRIPTION
	 This function save the GDCNT to nv
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 0: save success
	 -1: save fail
  SIDE EFFECTS
	 None
  ===========================================================================*/
QuecOSStatus Quectel_GDCNTSaveParamToNV(void)
{
	atcmd_nw_log("GDCNTSaveParamToNV rxbye=%llu,txbyte=%llu",QuecDataCntInfo.u64TotalRxCnt,QuecDataCntInfo.u64TotalTxCnt);
	QuecOSStatus status = QUEC_SUCCESS;
	QuecDataCntInfoType QuecDataCntInfo_temp={0};
	memcpy(&QuecDataCntInfo_temp,&QuecDataCntInfo,sizeof(QuecDataCntInfo));
	//QuecDataCntInfo_temp.u64PrevRxCnt=0;
	//QuecDataCntInfo_temp.u64PrevTxCnt=0;
    if(QUEC_FAT_SUCCESS != quectel_nv_fat_write(QUEC_AT_GDCNTVALUE, &QuecDataCntInfo_temp, sizeof(QuecDataCntInfo_temp)))
	{
		status = kGeneralErr;
	}

	return status;
}

/*===========================================================================

FUNCTION QUEC_EXEC_QGDCNT_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command 	is used check packet data counter .

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

RETURNCODE_T quectel_exec_qgdcnt_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	UINT32 qgdcnt_temp=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	
	Quectel_GDCNTUpdateAllCnt();
	
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QGDCNT: (0,1)\r\n");
                break;
            }    
        case TEL_EXT_GET_CMD: 
            {
                sprintf( resBuf,"+QGDCNT: %llu,%llu\r\n",QuecDataCntInfo.u64TotalTxCnt,QuecDataCntInfo.u64TotalRxCnt);
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                break;
            }
        case TEL_EXT_SET_CMD:
            {
            	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
                if(param_num==1 && (getExtValue(parameter_values_p, 0, &qgdcnt_temp, 0, 1, 0) == TRUE))
                {
                	atcmd_nw_log("qgdcnt_temp=%d",qgdcnt_temp);
					if(qgdcnt_temp == 0)
					{
						if(Quectel_GDCNTResetAllCnt() == QUEC_SUCCESS)
						{						
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
						else
						{
							atcmd_nw_log("reset ERROR");
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
						}
					}
					else if(qgdcnt_temp == 1)
					{
						if(Quectel_GDCNTSaveParamToNV() ==QUEC_SUCCESS)
						{						
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
						else
						{
							atcmd_nw_log("save ERROR");
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
						}
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					}
                }
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
                break;
                    
            }
        case TEL_EXT_ACTION_CMD:
        default:
            {	
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    
    }
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
   	
  
}
/*===========================================================================
  
  FUNCTION Quectel_GDCNTAutoTimerExpired
  
  DESCRIPTION
	 This function start the .
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 None
  SIDE EFFECTS
	 None
  ===========================================================================*/
 QuecOSStatus Quectel_GDCNTAutoTimerExpired(void)
{
	QuecOSStatus status = QUEC_SUCCESS;
	
	Quectel_GDCNTUpdateAllCnt();
	
	atcmd_nw_log("GDCNTAutoTimerExpired");
    if(AutoGDCNTInterval <= QUEC_MAX_AUTO_GDCNT_INTERVAL && AutoGDCNTInterval >= QUEC_MIN_AUTO_GDCNT_INTERVAL)
	{
		status = quec_rtos_timer_start(quec_qaugdcnt_time_ref,
	                                 AutoGDCNTInterval,
	                                 0,
	                                 Quectel_GDCNTAutoTimerExpired,
	                                 0);

	    ASSERT(status == OS_SUCCESS);
	    if(status != OS_SUCCESS)
	    {
	        return 0;
	    }
	}
	else
	{
		return 0;
	}
	#ifdef QUEC_PPP_INTERNAL_CHANNEL_HANDLE_AT_RESP
		status = quec_send_msg_to_handle_task(QUEC_QGDCNT_AUTOSAVE_MSG, NULL, QUEC_MSG_LEN_NONE);
	#else
		status = quec_send_msg_to_handle_task(QUEC_QGDCNT_AUTOSAVE_MSG, NULL, QUEC_MSG_LEN_NONE);
	#endif
    return status;
	//return Quectel_GDCNTSaveParamToNV();
	
}

/*===========================================================================
  
  FUNCTION Quectel_GDCNTAutoTimerStart
  
  DESCRIPTION
	 This function start the .
  
  DEPENDENCIES
	 None
  
  RETURN VALUE
	 None
  SIDE EFFECTS
	 None
  ===========================================================================*/

UINT8 Quectel_GDCNTAutoTimerStart(void)
{
	QuecOSStatus status = QUEC_SUCCESS;
	atcmd_nw_log("GDCNTAutoTimerStart AutoGDCNTInterval=%d",AutoGDCNTInterval);
	if (quec_qaugdcnt_time_ref == NULL)
    {
        status = OSATimerCreate(&quec_qaugdcnt_time_ref);
        if(status != OS_SUCCESS)
    	{
            atcmd_nw_log("OSATimerCreate status=%d error", status);
    		status = kGeneralErr;
			return 0;
    	}
    }
	
	if(AutoGDCNTInterval ==0)
	{
		status = OSATimerStop(quec_qaugdcnt_time_ref);
	    if(status != OS_SUCCESS)
	    {
	        return 0;
	    }
	}
	else if(AutoGDCNTInterval <= QUEC_MAX_AUTO_GDCNT_INTERVAL && AutoGDCNTInterval >= QUEC_MIN_AUTO_GDCNT_INTERVAL)
	{
		status = quec_rtos_timer_start(quec_qaugdcnt_time_ref,
	                                 AutoGDCNTInterval,
	                                 0,
	                                 Quectel_GDCNTAutoTimerExpired,
	                                 0);
	    if(status != OS_SUCCESS)
	    {
	        return 0;
	    }
	}
	else
	{
		return 0;
	}
	
	return 1;
	
}
/*===========================================================================

FUNCTION QUEC_EXEC_QAUGDCNT_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command 	is used save packet data counter .

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

RETURNCODE_T quectel_exec_qaugdcnt_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char resBuf[200];
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	UINT32 interval=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	
	QuecDataCntInfo.u64TotalRxCnt+=get_rx_byte_all();
	QuecDataCntInfo.u64TotalTxCnt+=get_tx_byte_all();
	
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QAUGDCNT: (0,30-65535)\r\n");
                break;
            }    
        case TEL_EXT_GET_CMD: 
            {
                sprintf( resBuf,"+QAUGDCNT: %lu\r\n",AutoGDCNTInterval/1000);
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                break;
            }
        case TEL_EXT_SET_CMD:
            {
            	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
                if(param_num==1 && (getExtValue(parameter_values_p, 0, &interval, QUEC_DEFAULT_AUTO_GDCNT_INTERVAL, QUEC_MAX_AUTO_GDCNT_INTERVAL, QUEC_DEFAULT_AUTO_GDCNT_INTERVAL) == TRUE))
                {
                	atcmd_nw_log("qgdcnt_temp=%d",interval);
					if(interval == 0 || interval >= 30)
					{
						if(AutoGDCNTInterval !=interval*1000)
						{
							AutoGDCNTInterval=interval*1000;
							if(Quectel_GDCNTAutoTimerStart())
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}
							else
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
							}
						}
						else
						{
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						}
						
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					}
                }
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
                break;
                    
            }
        case TEL_EXT_ACTION_CMD:
        default:
            {	
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    
    }
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
   	
  
}


#ifndef ENABLE_DM_LTEONLY
char * Quectel_SMONCPrintf(UINT8 bFirstItem,  char*res_buff_ptr, char *szPlmn, UINT16 u16Lac, UINT32 uiCid, UINT8 u8BSIC, UINT16 u16Freq, INT32 iRssi, INT32 iC1, INT32 iC2)
{
	char *res_buff =res_buff_ptr;
	
	if(NULL == res_buff_ptr)
	{
		atcmd_nw_log("pointer is NULL!");
		return NULL;
	}

	if(1 == bFirstItem)
	{
    	res_buff+=sprintf(res_buff,"^SMONC: ");
		res_buff+=sprintf(res_buff,"%s,%04X,%04lX,%02d,%d,%ld", szPlmn, u16Lac, uiCid, u8BSIC, u16Freq, iRssi);
	}
	else
	{
		res_buff+=sprintf(res_buff,",%s,%04X,%04lX,%02d,%d,%ld", szPlmn, u16Lac, uiCid, u8BSIC, u16Freq, iRssi);
	}

	if(QUEC_INVALID_C_VALUE == iC1)
	{
		res_buff+=sprintf(res_buff,",-");
	}
	else
	{
		res_buff+=sprintf(res_buff,",%ld",iC1);
	}

	if(QUEC_INVALID_C_VALUE == iC2)
	{
		res_buff+=sprintf(res_buff,",-");
	}
	else
	{
		res_buff+=sprintf(res_buff,",%ld",iC2);
	}
	return res_buff;
}


RETURNCODE_T dsat_exec_smonc_cmd
(
	const utlAtParameterOp_T		op, 				/* AT cmd type			*/
	const char					   *command_name_p, 	/* AT cmd name			*/
	const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/	
	const size_t					num_parameters, 	/* AT cmd number		*/
	const char					   *info_text_p,		/* AT cmd usage string	*/
	unsigned int				   *xid_p,				/* AT cmd handle		*/	 
	void						   *arg_p				/* AT cmd parser number */
)
{
	RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 	
    *xid_p = atHandle;
    atcmd_nw_log("command type=%d",op);
	UINT8 param_num=0;
    switch (op)
    {
    
        case TEL_EXT_TEST_CMD:
        	{
        	   
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				break;
        	}
		case TEL_EXT_ACTION_CMD:
		case TEL_EXT_SET_CMD:	
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
				if(param_num !=0 )
                {	
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				
			}
        case TEL_EXT_GET_CMD:  
        	{
				
            	if(network_infor_bitmsk !=0 )
                {
                   
                	atcmd_nw_log("error other commadn is executing :network_infor_bitmsk=%d",network_infor_bitmsk);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
					break;
                }
	            BIT_SET(network_infor_bitmsk,QSMONC) ;
	            ret = MM_GetSysInfo(atHandle);
				break;
	                
			
        	}
		
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
 	
}
#endif
#ifdef __QUEC_OEM_VER_LD__

UINT8 Quectel_IsOEMLandiEnable(void)
{
	if(quec_IsOEMLandiEnable==1)
		return TRUE;
	else 
		return FALSE;
}


QuecOSStatus Quectel_OEMLandiSaveParamToNV(UINT8 bValue)
{
	atcmd_nw_log("Quectel_OEMLandiSaveParamToNV bValue=%d",bValue);
	QuecOSStatus status = QUEC_SUCCESS;
#if QUEC_PRODUCTION_CFG_SUPPORT
	ST_quecCfgCustFeatureParams ST_CustFeatureParams = {0};
	/* relaod params */
	if(QUEC_SUCCESS != Quec_SysItemPara_Item_get(QUEC_CUST_FEATURE_CFG,&ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams)))
	{
		atcmd_nw_log("Failed:Quec_SysItemPara_Item_get QUEC_CUST_FEATURE_CFG ");
	}
	/*save params*/
	ST_CustFeatureParams.oemLandi = bValue;
	status = Quec_SysItemPara_Item_set(QUEC_CUST_FEATURE_CFG,&ST_CustFeatureParams, sizeof(ST_quecCfgCustFeatureParams));
	if(status != QUEC_SUCCESS)
#else
	if(QUEC_FAT_SUCCESS != quectel_nv_fat_write(QUEC_AT_QOEM, &bValue, sizeof(bValue)))
#endif
	{
		status = kGeneralErr;
	}
	return status;
}


/*===========================================================================

FUNCTION QUEC_EXEC_QOEM_LIANDI_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command 	is used control liandi at param formate .

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

RETURNCODE_T  quectel_exec_qoem_landi_cmd
(
       const utlAtParameterOp_T        op,                 /* AT cmd type          */
       const char                     *command_name_p,     /* AT cmd name          */
       const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
       const size_t                    num_parameters,     /* AT cmd number        */
       const char                     *info_text_p,        /* AT cmd usage string  */
       unsigned int                   *xid_p,              /* AT cmd handle        */
       void                           *arg_p
)
{
    RETURNCODE_T     rc       = INITIAL_RETURN_CODE;
    CiReturnCode     ret      = CIRC_FAIL;
    int              type;


    UINT32 atHandle =      *xid_p;
    UINT32 enable=0;
    UINT8 param_num=0;
    char res_buf[100]={0};
    char  cfg_cmd_param_str[20] = {0};
    UINT8 cfg_cmd_param_str_len=0;
    /*
     **  Check the format of the request.
     */
    param_num=quec_get_at_param_num(parameter_values_p,num_parameters);

    atcmd_nw_log("command type=%d,param_num=%d",op,param_num);
    switch (op)
    {
        case TEL_EXT_SET_CMD:    /* AT+QCFG="NWSCANMODE",..  */
            {

                if(param_num==1)
                {
                	sprintf( res_buf,"+QOEM: landi,%d",quec_IsOEMLandiEnable);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
                }
                else if(param_num==2)
                {
                    if ((getExtString(parameter_values_p, 1, cfg_cmd_param_str, 20, &cfg_cmd_param_str_len, NULL) == TRUE))
                    {
                         if(str2int32(cfg_cmd_param_str,1,&enable) &&(enable==0 || enable== 1) )
                         {
                             atcmd_nw_log(" enable=%d",enable);
							 quec_IsOEMLandiEnable=enable;
							 if(Quectel_OEMLandiSaveParamToNV(enable) == QUEC_SUCCESS)
							 {
							 	ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0,NULL);
							 }
							 else
							 {
								 atcmd_nw_log(" save error");	
							 	ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
							 }
                         }
                         else
                         {
                         	ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                         }
                    }
                    else
                    {
                         ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                    }
                }
                else
                {
                     ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                }
                break;
            }

        case TEL_EXT_TEST_CMD:    /* AT+QCFG=? */    
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }

    }

    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret);
    return(rc);
}

/*Tery.shi 20190121 add at+qoem="landipin" function*/
/*===========================================================================

FUNCTION quectel_exec_qoem_landipin_cmd

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command 	is used control liandipin at param formate .

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

RETURNCODE_T  quectel_exec_qoem_landipin_cmd
(
       const utlAtParameterOp_T        op,                 /* AT cmd type          */
       const char                     *command_name_p,     /* AT cmd name          */
       const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
       const size_t                    num_parameters,     /* AT cmd number        */
       const char                     *info_text_p,        /* AT cmd usage string  */
       unsigned int                   *xid_p,              /* AT cmd handle        */
       void                           *arg_p
)
{
    RETURNCODE_T     rc       = INITIAL_RETURN_CODE;
    CiReturnCode     ret      = CIRC_FAIL;
    int              type;


    UINT32 atHandle =      *xid_p;
    UINT8 enable=0;
    UINT8 param_num=0;
    char res_buf[100]={0};
    char  cfg_cmd_param_str[20] = {0};
    UINT8 cfg_cmd_param_str_len=0;
    /*
     **  Check the format of the request.
     */
    param_num=quec_get_at_param_num(parameter_values_p,num_parameters);

    atcmd_nw_log("command type=%d,param_num=%d",op,param_num);
    switch (op)
    {
        case TEL_EXT_SET_CMD:    /* AT+QCFG="NWSCANMODE",..  */
            {
                if(param_num==1)
                {
                    uint8 landipin_value = 0;
                    if(quec_get_sim_landipin_status(&landipin_value))
                    {
                        sprintf( res_buf,"+QOEM: \"landipin\",%d",landipin_value);
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
                    }
                    else
                    {
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
                    }
                }
				else if(param_num==2)
				{
				    if((getExtString(parameter_values_p, 1, cfg_cmd_param_str, 20, &cfg_cmd_param_str_len, NULL) == TRUE))
				    {
				        if(str2int32(cfg_cmd_param_str,1,&enable) &&(enable==0 || enable== 1) )
				        {
				            if(quec_set_sim_landipin_status(enable))
				            {
				                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				            }
							else
							{
							    ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
							}
				        }
				    }
				}
                break;
            }

        case TEL_EXT_TEST_CMD:    /* AT+QCFG=? */    
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }

    }

    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret);
    return(rc);
}

#endif
#ifdef __QUEC_OEM_VER_LD__
/*===========================================================================

FUNCTION QUEC_EXEC_QOEM_CMD

DESCRIPTION
  This function get the monitor_type of the QOEM cmd

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of  monitor_type of the QENG cmd
  possible values:
    utlSUCCESS : valid monitor_type
    utlFAILED : invalid monitor_type

SIDE EFFECTS
  None
===========================================================================*/

QOEM_ITEM quec_qoem_get_monitor_type(UINT8  * monitor_type)
{
    uint32  type_index = 0;
    
    for(type_index = 0; type_index < qoem_type_num;type_index++)
    {
        if(strncasecmp(monitor_type, qoem_type_name[type_index], strlen((char*)qoem_type_name[type_index])) == 0
            &&(strlen((char*)monitor_type) ==  strlen((char*)qoem_type_name[type_index])))
        {
            return (QOEM_ITEM)type_index;
        }
    }

    return QUECTEL_QOEM_ITEM_MAX;
}  

RETURNCODE_T quectel_exec_qoem_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 	
    *xid_p = atHandle;
    atcmd_nw_log("command type=%d",op);
	char  qoem_cmd_str[40] = {0};
	UINT8 qoem_cmd_str_len=0;
	QOEM_ITEM qoem_monitor_type=QUECTEL_QOEM_ITEM_MAX;
	char res_buf[50]={0};
    switch (op)
    {
    
        case TEL_EXT_SET_CMD:    
            {   

                if((getExtString(parameter_values_p, 0, qoem_cmd_str, sizeof(qoem_cmd_str), &qoem_cmd_str_len, NULL) != TRUE)
					 	|| ((qoem_monitor_type=quec_qoem_get_monitor_type(qoem_cmd_str)) == QUECTEL_QOEM_ITEM_MAX))
                {
                	ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;

				}
				switch(qoem_monitor_type)
            	{
	                case QUECTEL_QOEM_ITEM_LANDI:
	                {
	                	return quectel_exec_qoem_landi_cmd(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
	                }
					case QUECTEL_QOEM_ITEM_LANDI_PIN:
					{
					    return quectel_exec_qoem_landipin_cmd(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
					    break;
					}
	                default:
                	{
                		ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
                		break;
	                }
	                
            	}
        }
        case TEL_EXT_TEST_CMD:
        	{
        	   
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QOEM: \"landi\",(0,1)\r\n+QOEM: \"landipin\",(0,1)");
				break;
        	}
        case TEL_EXT_ACTION_CMD:
        case TEL_EXT_GET_CMD:   
			{
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                break;
            }
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}  
#endif
#ifdef QUECTEL_AT_QINDCFG_SUPPORT //connor 2019/01/21 add the qindcfg="act"
/*===========================================================================

FUNCTION QUEC_RATCHG_INDICATION

DESCRIPTION
  This function indicate whether the rat change

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of  monitor_type of the QENG cmd
  possible values:
    TRUE : rat change
    FLASE : rat unchange

SIDE EFFECTS
  None
===========================================================================*/

UINT8 quec_ratchg_indication(UINT8 forece_report,UINT8 new_rat,UINT8 new_reg_status,char * new_rat_string_buf)
{

	static char rat_buf[50] = {0};
	atcmd_nw_log("forece_report=%d,new_rat=%d,new_reg_status=%d",forece_report,new_rat,new_reg_status);

	
	if(new_reg_status !=1 && new_reg_status !=5) //in not register state
	{
		if(quec_get_regstatus(1)) //escape from CEREG/CGREG/CREG in diffrent order which lead we indicate register then indicate no register
		{
			return 0 ;
		}
		sprintf( new_rat_string_buf,"UNKNOWN");
	}
	else 
	{
		/*witch(new_rat)
		{
			case  ATCI_SYSINFO_SYSTEMO_SUBMODE_NO_SERVICE: 
				sprintf( new_rat_string_buf,"UNKNOWN");
				break;
		    case  ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM:   //GSM
		    	sprintf( new_rat_string_buf,"GSM");
		  		break;
		    case  ATCI_SYSINFO_SYSTEMO_SUBMODE_GSM_EGPRS:  //EGPRS
				sprintf( new_rat_string_buf,"EGPRS");
			 	break;
		    case  ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSDPA:  //HSDPA
		  	 	sprintf( new_rat_string_buf,"HSDPA");
			 	break;
			case  ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSUPA:  //HSUPA
		  	 	sprintf( new_rat_string_buf,"HSUPA");
			 	break;
			case  ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN_HSPA:  //HSDPA&HSUPA
		  	 	sprintf( new_rat_string_buf,"HSDPA&HSUPA");
				break;
			case  ATCI_SYSINFO_SYSTEMO_SUBMODE_UTRAN:  //WCDMA
				sprintf( new_rat_string_buf,"WCDMA");
				break;
			case  ATCI_SYSINFO_SYSTEMO_SUBMODE_EUTRAN:  //LTE
		  	 	sprintf( new_rat_string_buf,"LTE");
				break;
		  	default:
		  	 	atcmd_nw_log("invalid rat=%d",new_rat);
			 	sprintf( new_rat_string_buf,"UNKNOWN");
		  	 	break;
		}*/
		switch(new_rat)
		{
			case  0: 
		    case  1:   //GSM
		    	sprintf( new_rat_string_buf,"GSM");
		  		break;
		    case  2:  //WCDMA
				sprintf( new_rat_string_buf,"WCDMA");
			 	break;
		    case  3:  //EGPRS
		  	 	sprintf( new_rat_string_buf,"EGPRS");
			 	break;
			case  4:  //HSDPA
		  	 	sprintf( new_rat_string_buf,"HSDPA");
			 	break;
			case  5:  //HSUPA
		  	 	sprintf( new_rat_string_buf,"HSUPA");
				break;
			case  6:  //HSDPA&HSUPA
			case  8:  //HSPA+
		  	 	sprintf( new_rat_string_buf,"HSDPA&HSUPA");
				break;
			case  7:  //LTE
		  	 	sprintf( new_rat_string_buf,"LTE");
			 	break;
		  	default:
		  	 	atcmd_nw_log("invalid rat=%d",new_rat);
			 	sprintf( new_rat_string_buf,"UNKNOWN");
		  	 	break;
		}
	}
	
	if(strcasecmp(rat_buf, new_rat_string_buf) == 0 && forece_report == 0)
	{
		return 0 ;
	}
	else
	{	
		memset(rat_buf,0,sizeof(rat_buf));
		memcpy(rat_buf,new_rat_string_buf,strlen(new_rat_string_buf));
		return 1;
	}
	   
}  

#endif

/*===========================================================================

FUNCTION QUEC_EXEC_QGPAPN 

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. 
  This command query the network assigne apn of all actived context .

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
RETURNCODE_T quectel_exec_qgpapn_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    char tempBuf[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM][MAX_APN_INFO_LEN+1]={0};
	char resBuf[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM*(MAX_APN_INFO_LEN+10)]={0};
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT32 cid=0;
	UINT8 cid_temp=0;
    atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
    UINT8 index=0;
	char *p=resBuf;
	PdpContextList	*tmp_list = NULL, *list_head = NULL;

    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QGPAPN: (1-15)\r\n");
                break;
            } 
		case TEL_EXT_GET_CMD:
        case TEL_EXT_ACTION_CMD: 
		case TEL_EXT_SET_CMD:
            {				
				if((getExtValue(parameter_values_p, 0, &cid, 1, 15, 0) == TRUE) )
				{
					if(cid == 0)//all cid
					{
						for(index=TEL_AT_CMD_ATP_0;index< NUM_OF_TEL_ATP ;index ++)
						{
							if(gAtpCtrl[index].pdpCtx.head !=NULL )
							{
								tmp_list = gAtpCtrl[index].pdpCtx.head;
								while(tmp_list)
								{
									if(tmp_list->PDP.Pdp_Info.PDP_Type == 1)
									{
										cid_temp = tmp_list->PDP.Pdp_Info.PrimaryCID;
									}
									else
									{
										cid_temp = tmp_list->PDP.Pdp_Info.SecondaryCID;
									}
									atcmd_nw_log("cid_temp=%d,APN=%s",cid_temp,tmp_list->PDP.Pdp_Info.APN);
									if(cid_temp+1>0 && cid_temp +1< CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM && strlen(tmp_list->PDP.Pdp_Info.APN) !=0)
									{
										sprintf( tempBuf[cid_temp],"%s",tmp_list->PDP.Pdp_Info.APN);
									}
									tmp_list = tmp_list->next;
								}
							
}
						}
					}
					else
					{
						for(index=TEL_AT_CMD_ATP_0;index< NUM_OF_TEL_ATP ;index ++)
						{
							if(gAtpCtrl[index].pdpCtx.head !=NULL )
							{
								tmp_list = gAtpCtrl[index].pdpCtx.head;
								while(tmp_list)
								{
									if(tmp_list->PDP.Pdp_Info.PDP_Type == 1)
									{
										cid_temp = tmp_list->PDP.Pdp_Info.PrimaryCID;
									}
									else
									{
										cid_temp = tmp_list->PDP.Pdp_Info.SecondaryCID;
									}
									atcmd_nw_log("cid_temp=%d,APN=%s",cid_temp,tmp_list->PDP.Pdp_Info.APN);
									if(cid_temp+1==cid && strlen(tmp_list->PDP.Pdp_Info.APN) !=0)
									{
										sprintf( tempBuf[cid_temp],"%s",tmp_list->PDP.Pdp_Info.APN);
									}
									tmp_list = tmp_list->next;
								}
							
}
						}
					}

					if(cid==0)
					{
						for(index=0;index<CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM;index++)
						{
							atcmd_nw_log("pdp_act_status=%d",quec_pdp_act_state[index].pdp_act_status);
							if(strlen(tempBuf[index]) !=0 && quec_pdp_act_state[index].pdp_act_status ==1 )
							{
								p+=sprintf( p,"+QGPAPN: %d,\"%s\"\r\n",index+1,tempBuf[cid]);
							}
							else
							{
								p+=sprintf( p,"+QGPAPN: %d,\"\"\r\n",index+1);
							}	
						}
					}
					else 
					{
						atcmd_nw_log("pdp_act_status=%d",quec_pdp_act_state[cid-1].pdp_act_status);
						if(strlen(tempBuf[cid-1]) !=0 && quec_pdp_act_state[cid-1].pdp_act_status ==1)
						{
							p+=sprintf( p,"+QGPAPN: %d,\"%s\"\r\n",cid,tempBuf[cid-1]);
						}
						else
						{
							p+=sprintf( p,"+QGPAPN: %d,\"\"\r\n",cid);
						}	
					}
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
				}
                break;
            }
        				
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    
    }
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
    
}

#ifdef QUECTEL_AT_RFTEST_SUPPORT
uint8 quec_ftm_state_flag=0;
RETURNCODE_T quectel_exec_qrftestmode_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc		 = INITIAL_RETURN_CODE;
	CiReturnCode	ret 	 = CIRC_FAIL;
	UINT32			 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	char resBuf[200];
	*xid_p = atHandle;
	UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	UINT32 test_mode=0;
	atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	switch (op)
	{
		case TEL_EXT_TEST_CMD:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QRFTESTMODE: (0,1)\r\n");
				break;
			}	 
		case TEL_EXT_GET_CMD: 
			{
				sprintf( resBuf,"+QRFTESTMODE: %d\r\n",quec_rftestmode.tx_enable);
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
				break;
			}
		case TEL_EXT_SET_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
				if(param_num==1 && (getExtValue(parameter_values_p, 0, &test_mode, 0, 1, 0) == TRUE))
				{
					atcmd_nw_log("[wayne]test_mode=%d,tx_enable %d",test_mode,quec_rftestmode.tx_enable);
					if(test_mode != quec_rftestmode.tx_enable)
					{
						quec_rftestmode.tx_enable=test_mode;
						if(quec_rftestmode.tx_enable ==1 )
						{
						    DEV_GetBandModeReq(atHandle);//此处与1802s不同,1601需要先执行at*band?将信息同步到相关变量
							ret = DEV_SetFunc(atHandle, 0, 0, FALSE, 0, 0);//set cfun=0,0 to enter RF test mode
							if (CIRC_SUCCESS == ret)
							{
								atcmd_nw_log("[wayne]enter RF test mode success");
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}
							else
							{
								atcmd_nw_log("[wayne]enter RF test mode fail");
								ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CMS_ME_FAILURE, NULL);
							}
						}
						else
						{
						  atcmd_nw_log("[wayne]rftestmode=%d",quec_rftestmode.mode);
							if(quec_rftestmode.mode==QUEC_NETMODE_LTE)
							{
								ret = DEV_SetLTEModeTxRxReq(atHandle, 2, 0, 0,0);
								if(ret != CIRC_SUCCESS)
								{
									atcmd_nw_log("[wayne]exit RF LTE test mode fail");
								}
							}
							#ifndef LTEONLY_THIN
							else if (quec_rftestmode.mode==QUEC_NETMODE_GSM)
							{
								ret = DEV_SetGsmModeTxRxReq(atHandle, 3, 0, 0, 0, 0, 0);
								if(ret != CIRC_SUCCESS)
								{
									atcmd_nw_log("[wayne]exit RF GSM test mode fail");
								}
							}
							#endif
							ret = DEV_SetFunc(atHandle, 1, 0, FALSE, 0, 0);//set cfun=1,0 to exist RF test mode
							if (CIRC_SUCCESS == ret)
							{
								atcmd_nw_log("[wayne]exit RF test mode success");
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
							}
							else
							{
								atcmd_nw_log("[wayne]exit RF test mode fail");
								ret = ATRESP(atHandle, ATCI_RESULT_CODE_CME_ERROR, CMS_ME_FAILURE, NULL);
							}
						}
						
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
					}
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
				break;
					
			}
		case TEL_EXT_ACTION_CMD:
		default:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
				break;
			}
	
	}
	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}

quec_network_mode_type  quec_get_qrftest_labels_type(char  * monitor_type,UINT8 * index)
{
    uint32  type_index = 0;
    quec_network_mode_type mode=QUEC_NETMODE_NONE;
    for(type_index = 0; type_index < sizeof(qrftest_labels)/sizeof(qrftest_labels[0]);type_index++)
    {
    	atcmd_nw_log("name=%s",qrftest_labels[type_index].name);
        if(strcasecmp(monitor_type, qrftest_labels[type_index].name) == 0)
        {
        	mode=qrftest_labels[type_index].mode;
			*index=type_index;
            break;
        }
    }
	atcmd_nw_log("mode=%d",mode);
    return mode;
}  

RETURNCODE_T quectel_exec_qrftest_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc		 = INITIAL_RETURN_CODE;
	CiReturnCode	ret 	 = CIRC_FAIL;
	UINT32			 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	char resBuf[200];
	*xid_p = atHandle;
	UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	char  band_str[40] = {0};
	char  tx_enable_str[10] = {0};
	UINT8 tx_enable_str_len=0;
	UINT8 band_str_len=0;
	UINT8 tx_enable=0;
	UINT32 tx_power=0;
	UINT32 tx_channel=0;
	UINT8 lab_index=0;
	quec_network_mode_type mode=QUEC_NETMODE_NONE;
	atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	
	switch (op)
	{
		case TEL_EXT_TEST_CMD:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				break;
			}	 
		case TEL_EXT_SET_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("param_num=%d",param_num);
				if((getExtString(parameter_values_p, 0, band_str, sizeof(band_str), &band_str_len, NULL) == TRUE))
				{
					atcmd_nw_log("band=%s",band_str);
					mode=quec_get_qrftest_labels_type(band_str,&lab_index);
					atcmd_nw_log("mode=%d",mode);
					if( mode != QUEC_NETMODE_NONE
						&& (getExtValue(parameter_values_p, 1, &tx_channel, qrftest_labels[lab_index].tx_chanel_min, qrftest_labels[lab_index].tx_chanel_max, 0) == TRUE)
						&& (getExtString(parameter_values_p, 2, tx_enable_str, sizeof(tx_enable_str), &tx_enable_str_len, NULL) == TRUE)
						&& (strcasecmp(tx_enable_str, (char *)"off") == 0 || strcasecmp(tx_enable_str, (char *)"on") == 0)
						&& (getExtValue(parameter_values_p, 3, &tx_power, QUEC_MIN_TX_POWER, QUEC_MAX_TX_POWER, 0) == TRUE))
					{
						 if(strcasecmp(tx_enable_str, (char *)"off") == 0 )
						 {
							tx_enable=0;
						 }
						 else
						 {
						 	tx_enable=1;
						 }
						atcmd_nw_log("[wayne]mode %d,index %d,band=%d,channel=%d,tx_enable=%d,tx_power=%d",mode,lab_index,qrftest_labels[lab_index].band,tx_channel,tx_enable,tx_power);
						if(mode == QUEC_NETMODE_LTE) //tx_power is rang from 0-2047
						{
							if(tx_enable == 0)
							{
								ret = DEV_SetLTEModeTxRxReq(atHandle, 2, 0, 0,0);
								quec_rftestmode.mode=QUEC_NETMODE_NONE;
							}
							else
							{
								quec_rftestmode.mode=QUEC_NETMODE_LTE;
                                if (lab_index < 20)
                                {
                                    ret = DEV_SetLTEModeTxRxReq(atHandle, 0, tx_channel, tx_power,0);
                                }
                                else 
                                {
                                    /*扩展band: b65,b66,b72*/
                                    ret = DEV_SetLTEModeTxRxReq(atHandle, 0, EarfcnPro(tx_channel), tx_power,0);
                                }
							}
						}
						#ifndef LTEONLY_THIN
						else if(mode == QUEC_NETMODE_GSM ) //Range: (0-1023), suggested range is (200-700) (too bigger will cause Tx saturated, and equipmentcould not detect it)
						{
							if(tx_power > 0 && tx_power < 1023)
							{
								if(tx_enable == 0)
								{
									quec_rftestmode.mode=QUEC_NETMODE_NONE;
							 		ret = DEV_SetGsmModeTxRxReq(atHandle, 3, 0, 0, 0, 0, 0);
								}
								else
								{
									quec_rftestmode.mode=QUEC_NETMODE_GSM;
									if(qrftest_labels[lab_index].band == ASR_BAND_EGSM_900 
										&& (tx_channel > 124 && tx_channel < 975))
									{
										atcmd_nw_log("invalid tx_channel=%d",tx_channel);
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"invaild tx_channel");
										break;
									}
									ret = DEV_SetGsmModeTxRxReq(atHandle, 0, qrftest_labels[lab_index].band,tx_channel, 6000, tx_power, 20);
								}
							}
							else
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"invaild tx_power");
							}
						}
						#endif
						else
						{
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"invaild tx_mode");
						}
							
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM,(char*)"Parameter parsing error");
					}
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"band parsing error");
				}
				break;
					
			}
		case TEL_EXT_ACTION_CMD:
		case TEL_EXT_GET_CMD:
		default:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, (char*)"OPERATION_NOT_SUPPORTED");
				break;
			}
	
	}
    atcmd_nw_log("[wayne] qrftest_ret=%d",ret);
	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}

RETURNCODE_T quectel_exec_qrxftm_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc		 = INITIAL_RETURN_CODE;
	CiReturnCode	ret 	 = CIRC_FAIL;
	UINT32			 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	char resBuf[200];
	*xid_p = atHandle;
	UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	char  band_str[40] = {0};
	char  rx_enable_str[10] = {0};
	UINT8 rx_enable_str_len=0;
	UINT8 band_str_len=0;
	UINT8 rx_enable=0;
	INT32 rx_power=0;
	//INT16 rxpower_target=0;
	UINT32 rx_channel=0;
	UINT8 lab_index=0;
	UINT32 rx_bw=0;
	quec_network_mode_type mode=QUEC_NETMODE_NONE;
	atcmd_nw_log("command type=%d,atp_index=%d",op,atp_index);
	
	switch (op)
	{
		case TEL_EXT_TEST_CMD:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				break;
			}	 
		case TEL_EXT_SET_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("[wayne]rx param_num=%d",param_num);
				if((getExtString(parameter_values_p, 0, band_str, sizeof(band_str), &band_str_len, NULL) == TRUE))
				{
					
					mode=quec_get_qrftest_labels_type(band_str,&lab_index);
					atcmd_nw_log("[wayne]rx band=%s,rx mode=%d,lab_index %d\n",band_str,mode,lab_index);
					if( mode != QUEC_NETMODE_NONE
						&& (getExtValue(parameter_values_p, 1, &rx_channel, qrftest_labels[lab_index].rx_chanel_min, qrftest_labels[lab_index].rx_chanel_max, 0) == TRUE)
						&& (getExtString(parameter_values_p, 2, rx_enable_str, sizeof(rx_enable_str), &rx_enable_str_len, NULL) == TRUE)
						&& (strcasecmp(rx_enable_str, (char *)"off") == 0 || strcasecmp(rx_enable_str, (char *)"on") == 0)
						&& (getExtValue(parameter_values_p, 3, &rx_power, QUEC_MIN_RX_POWER, QUEC_MAX_RX_POWER, 0) == TRUE))
					{
						 if(strcasecmp(rx_enable_str, (char *)"off") == 0)
						 {
							rx_enable=0;
							quec_ftm_state_flag=0;
						 }
						 else
						 {
						 	rx_enable=1;
							quec_ftm_state_flag=1;
						 }
						atcmd_nw_log("[wayne]mode =%d,rx band=%d,channel=%d,rx_enable=%d,rx_power=%d,flag=%d",mode,qrftest_labels[lab_index].band,rx_channel,rx_enable,rx_power,quec_ftm_state_flag);
						if(mode == QUEC_NETMODE_LTE) //lte rx_power is rang from 0 -100
						{
						  getExtValue(parameter_values_p, 4, &rx_bw,0, 5, 0);
                          rx_bw=0; ////此处与1802s不同,1802s代码仅为1有效，1601仅为0有效
                          /* 044基线升级到049基线后，ASR调整了代码逻辑，需要配置rx_bw为0,010.052以上dsp版本且rx_power左移4位，tx和关闭强收不需要参数rx_bw */
                          //rx_bw = 1;
						  rx_power = rx_power << 4;
						  rx_power= -rx_power;
							if(rx_enable == 0)
							{
								ret = DEV_SetLTEModeTxRxReq(atHandle, 2, 0, 0,0);
								quec_rftestmode.mode=QUEC_NETMODE_NONE;
							}
							else
							{
								quec_rftestmode.mode=QUEC_NETMODE_LTE;
                                if (lab_index < 20)
                                {
                                    ret = DEV_SetLTEModeTxRxReq(atHandle, 1, rx_channel, rx_power,rx_bw);
                                }
                                else 
                                {
                                    /*扩展band: b65,b66,b72*/
                                    ret = DEV_SetLTEModeTxRxReq(atHandle, 1, EarfcnPro(rx_channel), rx_power,rx_bw);
                                }
							}
						}
						#ifndef LTEONLY_THIN
						else if(mode == QUEC_NETMODE_GSM ) //Range: (0-1023), suggested range is (200-700) (too bigger will cause Tx saturated, and equipmentcould not detect it)
						{
							if(rx_power > 0 && rx_power < 1023)
							{
								if(rx_enable == 0)
								{
									quec_rftestmode.mode=QUEC_NETMODE_NONE;
							 		ret = DEV_SetGsmModeTxRxReq(atHandle, 3, 0, 0, 0, 0, 0);
								}
								else
								{
									quec_rftestmode.mode=QUEC_NETMODE_GSM;
									if(qrftest_labels[lab_index].band == ASR_BAND_EGSM_900 
										&& (rx_channel > 124 && rx_channel < 975))
									{
										atcmd_nw_log("[wayne]invalid rx_channel=%d",rx_channel);
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM,(char*)"invaild rx_channel");
										break;
									}
									ret = DEV_SetGsmModeTxRxReq(atHandle, 1, qrftest_labels[lab_index].band,rx_channel, 6000, rx_power, 20);
								}
							}
							else
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM,(char*)"invaild rx_power");
							}
						}
						#endif
						else
						{
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM,(char*)"invaild rx_mode");
						}
							
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM,(char*)"Parameter parsing error");
					}
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"band parsing error");
				}
				break;
					
			}
		case TEL_EXT_ACTION_CMD:
		case TEL_EXT_GET_CMD:
		default:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, (char*)"OPERATION_NOT_SUPPORTED");
				break;
			}
	
	}
	atcmd_nw_log("[wayne] qrxftm_ret=%d",ret);
	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}
#endif

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)

#define G510_MCELL_MODE_DEFAULT               0

#define G510_MCELL_SCREENT_TYPE_MIN           0
#define G510_MCELL_SCREENT_TYPE_MAX           26
#define G510_MCELL_SCREENT_TYPE_DEFAULT       25

uint8 g_fibo_mcell_screentype = 0;


RETURNCODE_T  quec_g510_mcell_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	RETURNCODE_T ret = utlSUCCESS;
	char buf[512]={0};
	INT16 buf_len =0;
	UINT8 validCmd = TRUE;	
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
						
	*xid_p = atHandle;
								
	atcmd_nw_log("%s,athandle=%d\r\n",__FUNCTION__, atHandle);
	switch (op)
	{
	case TEL_EXT_TEST_CMD:	  /* AT+MIPDNS=? */
		buf_len =0;
		buf_len += snprintf(buf, 512, "+MCELL: (0),(0-26)\r\n");
		ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, buf);
		break;
	case TEL_EXT_SET_CMD:
		{
			int request_mode;
			int screen_type;
			UINT8 validCmd = TRUE;
			UINT8 	arg_cnt;
			UINT8   arg_index = 0;
		

			arg_cnt = quec_get_at_param_num(parameter_values_p,num_parameters);		

			while(arg_index < arg_cnt && validCmd){
				switch(arg_index){
				case 0:
					 if(getExtValue( parameter_values_p, 0, &request_mode, G510_MCELL_MODE_DEFAULT, G510_MCELL_MODE_DEFAULT, G510_MCELL_MODE_DEFAULT) == FALSE ){
						validCmd = FALSE;
					 }
					break;					
				case 1:
					 if(getExtValue( parameter_values_p, 1, &screen_type, G510_MCELL_SCREENT_TYPE_MIN, G510_MCELL_SCREENT_TYPE_MAX, G510_MCELL_SCREENT_TYPE_DEFAULT) == FALSE ){
						validCmd = FALSE;
					 }
					 break;
				default:
					validCmd = FALSE;
					break;
				}
				arg_index++;
			}
			if(validCmd && (screen_type == 21 || screen_type == 25||screen_type == 26)){
                g_fibo_mcell_screentype = screen_type;

                if(screen_type == 21)
                {
                    ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
                }
                
				BIT_SET(network_infor_bitmsk, MCELL);
				MM_GetSysInfo(atHandle);
			}else{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			}
		}
		break;

	case TEL_EXT_GET_CMD:
		ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
		break;
	}
}

quec_fibo_mcell_show_e quec_fibo_mcell_show(void)
{
    if(g_fibo_mcell_screentype == 21)
    {
        return QUEC_FIBO_MCELL_ASYN;
    }
    else if(g_fibo_mcell_screentype == 26)
    {
        return QUEC_FIBO_MCELL_SYSN_EX;
    }
    else
    {
        return QUEC_FIBO_MCELL_SYSN;
    }
}

// NL AT+MCELL=26 only show data like follow
//AT+MCELL=0,26
//1120,1,21772,465,-,0672,04,-48
uint8 quec_fibo_mcell_format(char * str)
{
   int i = 0;
   int pos = 0;
   
   if(str == NULL)
   {
     return FALSE;
   }

   while(str[i] != '\0')
   {
       if((str[i] >= '0' && str[i] <= '9')
          || str[i] == '-' || str[i] == ',' 
          || str[i] == '\r' || str[i] == '\n')
       {
           str[pos] = str[i];
           pos++;
       }

       i++;
   }

   str[pos] = '\0';

   return TRUE;
}


#define G510_T3302_MIN           0
#define G510_T3302_MAX           12
#define G510_T3302_DEFAULT       0

uint8 g_t3302 = 12;

RETURNCODE_T  quec_g510_t3302_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */	
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */    
    void                          *arg_p              /* AT cmd parser number */
)
{
	RETURNCODE_T ret = utlSUCCESS;
	char buf[512]={0};
	INT16 buf_len =0;
	UINT8 validCmd = TRUE;	
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
						
	*xid_p = atHandle;
								
	atcmd_nw_log("%s,athandle=%d\r\n",__FUNCTION__, atHandle);
	switch (op)
	{
	case TEL_EXT_TEST_CMD:	  /* AT+T3302=? */
		buf_len =0;
		buf_len += snprintf(buf, 512, "+T3302: (0-12)\r\n");
		ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, buf);
		break;
	case TEL_EXT_SET_CMD:
		{
			int request_mode;
			int t3302=0;
			UINT8 validCmd = TRUE;
			UINT8 	arg_cnt;
			UINT8   arg_index = 0;
		
			arg_cnt = quec_get_at_param_num(parameter_values_p,num_parameters);		

			while(arg_index < arg_cnt && validCmd){
				switch(arg_index){
				case 0:
					 if(getExtValue( parameter_values_p, 0, &t3302, G510_T3302_DEFAULT, G510_T3302_MIN, G510_T3302_MAX) == FALSE ){
						validCmd = FALSE;
					 }
					break;					
				default:
					validCmd = FALSE;
					break;
				}
				arg_index++;
			}
			if(validCmd){
                g_t3302 = t3302;
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}else{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			}
		}
		break;

	case TEL_EXT_GET_CMD:
    	buf_len += snprintf(buf+buf_len, (512 -buf_len), "+T3302: %d\r\n",g_t3302);
		ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, buf);
		break;
	}

}

#endif

/* isaac-20200414 jamming detection */
#ifdef QUECTEL_JAMDET_FEATURE
#define QUEC_EFS_JAM_DET   "jam_detect"   
#define QUEC_JD_MSG_LEN_NONE 0
#define QUEC_TIME_UNIT_SECOND 1000 /*单位: 秒*/

quectel_jdcfg_s_t rr_quectel_jdcfg[JDCFG_ENUM_MAX] = {
    {JDENABLE,          "enable",       0,     0,   1    },
    {JDURC,             "urc",          0,     0,   1    },
    {JDPERIOD,          "period",       0,     0,   120  },
    {JDMINCH,           "minch",        5,     0,   254  },
    {JDSINR,            "sinr",         -7,   -50,  50   }, /* 1603: maxval 30 change 50 */
    {JDRXLEV,           "rxlev",        -52,   -105, -10 },
    {JDRSRP,            "rsrp",        -110,  -140, -44  },
    {JDRSRQ,            "rsrq",        -15,   -19,  -1   }, 
    {JDRSSI,            "rssi",        -50,   -90,  -5   }, /* 1603: -47 change -50 */
    {JDSHAKEPERIOD,     "shakeperiod",  3,     1,   10   }, 
};
	
jamdet_res_e_type 	jamdet_current_status = JAM_DET_REMOVE;
quec_timer_t  		g_jd_period_report_Timer = NULL;    /*jd period report timer*/

bool quec_is_nw_mode_vaild(CiDevEngModeNetwork nw_mode)
{
	if ((nw_mode > QUEC_LTE_MODE) || (nw_mode < QUEC_GSM_MODE))
	{
		return FALSE;
	}
	return TRUE;
}

void quec_log_cell_info(CiDevPrimCellsInfoInd *pCiDevPrimCellsInfoInd)
{
	uint16 i = 0;
	
	if (NULL == pCiDevPrimCellsInfoInd)
	{
		Log_Print("[quec jd] pCiDevPrimCellsInfoInd is NULL");
		return;
	}
	if (FALSE == quec_is_nw_mode_vaild(pCiDevPrimCellsInfoInd->network))
	{
		Log_Print("[quec jd] nw mode %d is vaild",pCiDevPrimCellsInfoInd->network); 
		return;
	}
	
	switch(pCiDevPrimCellsInfoInd->network)
	{
		case QUEC_GSM_MODE:
			for (i = 0;(i < pCiDevPrimCellsInfoInd->numGsmCells) && (i < CI_DEV_MAX_CELLS_INFO);i++)
			{
				Log_Print("[quec jd] GsmCells[%d]:  arfcn=%d,bsic=%d,cellType=%d,decodeResult=%d,RX_Lev=%d,sinr=%d\n", 
					i, pCiDevPrimCellsInfoInd->gsmCellInfo[i].arfcn,
					pCiDevPrimCellsInfoInd->gsmCellInfo[i].bsic,
					pCiDevPrimCellsInfoInd->gsmCellInfo[i].cellType,
					pCiDevPrimCellsInfoInd->gsmCellInfo[i].decodeRc,
					pCiDevPrimCellsInfoInd->gsmCellInfo[i].rssi,
					pCiDevPrimCellsInfoInd->gsmCellInfo[i].sinr);
			}
			break;
		case QUEC_UMTS_MODE:
			for (i = 0;(i < pCiDevPrimCellsInfoInd->numUmtsCells) && (i < CI_DEV_MAX_CELLS_INFO);i++)
			{
				Log_Print("[quec jd] UMTSCells[%d]:  arfcn=%d,psc=%d,cellType=%d,decodeResult=%d,rssi=%d,rscp=%d,ecN0=%d,sinr=%d\n", 
					i, pCiDevPrimCellsInfoInd->umtsCellInfo[i].arfcn,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].psc,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].cellType,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].decodeRc,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].rssi,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].rscp,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].ecN0,
					pCiDevPrimCellsInfoInd->umtsCellInfo[i].sinr);
			}
			break;
		case QUEC_LTE_MODE:
			for(i = 0; (i < pCiDevPrimCellsInfoInd->numLteCells) && (i < CI_DEV_MAX_CELLS_INFO);i++)
			{
				Log_Print("[quec jd] LTECells[%d]:  earfcn=%d,pci=%d,cellType=%d,decodeResult=%d,rssi=%d,rsrp=%d,rsrq=%d,sinr=%d\n", 
					i, pCiDevPrimCellsInfoInd->lteCellInfo[i].earfcn,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].physCellId,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].cellType,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].decodeRc,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].rssi,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].rsrp,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].rsrq,
					pCiDevPrimCellsInfoInd->lteCellInfo[i].sinr);
			}
			break;
		default:
			break;
	}
	return;
}

jamdet_res_e_type quec_get_jamming_status(void)
{
	return jamdet_current_status;
}

bool quec_vaild_jdcfg_type(quectel_jdcfg_e_t jdcfg_type)
{
	if ((jdcfg_type > JDSHAKEPERIOD) || (jdcfg_type < JDENABLE))
	{
		return FALSE;
	}
	return TRUE;
}

int quec_get_jdcfg_val(quectel_jdcfg_e_t jdcfg_type)
{
	if (FALSE == quec_vaild_jdcfg_type(jdcfg_type))
	{
		Log_Print("[quec jd] jdcfg type %d is vaild,use default value",jdcfg_type);
		return kGeneralErr;
	}
	
	return rr_quectel_jdcfg[jdcfg_type].value;
}

int quec_get_jdcfg_min_val(quectel_jdcfg_e_t jdcfg_type)
{
	if (FALSE == quec_vaild_jdcfg_type(jdcfg_type))
	{
		Log_Print("[quec jd] jdcfg type %d is vaild,use default value",jdcfg_type);
		return kGeneralErr;
	}

	return rr_quectel_jdcfg[jdcfg_type].minval;
}

int quec_get_jdcfg_max_val(quectel_jdcfg_e_t jdcfg_type)
{
	if (FALSE == quec_vaild_jdcfg_type(jdcfg_type))
	{
		Log_Print("[quec jd] jdcfg type %d is vaild,use default value",jdcfg_type);
		return kGeneralErr;
	}

	return rr_quectel_jdcfg[jdcfg_type].maxval;
}

QuecOSStatus quec_jd_report_start_timer
(
	quec_time_type_e_t time_type,
	quec_timer_t timer,
	uint32 time_experiod,
	void (*callBackRoutine)(UINT32)
)
{
	QuecOSStatus err = kNoErr;
	
	if (kNoErr != quec_rtos_timer_start(timer, time_experiod, TRUE, callBackRoutine, 0))
	{
		Log_Print("[quec jd] timer %d start failed",time_type);
		err = kGeneralErr;
	}
	
	return err;
}


/*nv init: read jdcfg*/
QuecOSStatus quec_jam_det_read_from_nv(void)
{
	QuecOSStatus ret = kGeneralErr;
	quectel_jdval_s_t jdcfg;
	UINT8 i = 0;
	
	memset(&jdcfg, 0, sizeof(jdcfg));
    ret = quectel_nv_fat_read(QUEC_EFS_JAM_DET, &jdcfg, sizeof(quectel_jdval_s_t));
    if(ret != QUEC_FAT_SUCCESS)
    {
        atcmd_nw_log("[quec jd]nv init: jdcfg read failed"); 
        return ret;
    }
	else
	{
		/*loading user cfg to RAM*/
        for (i = 0; i < JDCFG_ENUM_MAX; i++)
        {
            rr_quectel_jdcfg[i].value = jdcfg.jdvalue[i];
        }	
	}

	if ( 1 == rr_quectel_jdcfg[JDENABLE].value )
	{
		/* 通过CI_DEV_PRIM_CELLS_INFO_IND 上报，无需定时器， 只保留周期上报定时器即可 */
		if ((rr_quectel_jdcfg[JDPERIOD].value != 0) && (1 == rr_quectel_jdcfg[JDURC].value))
		{
			/*create jd report timer and start timer*/
			quec_timer_create_init(QUEC_PERIOD_TIMER);
			if (kNoErr != quec_jd_report_start_timer(QUEC_PERIOD_TIMER,
									g_jd_period_report_Timer,
									rr_quectel_jdcfg[JDPERIOD].value*QUEC_TIME_UNIT_SECOND,
									quec_jd_period_report_Timer_callback))
			{
				atcmd_nw_log("[quec jd]jd period report timer start failed");
			}
		}
		
	}

    return QUEC_SUCCESS;
}

QuecOSStatus quec_jam_det_set_to_nv(quectel_jdval_s_t *jdcfgP)
{
    QuecOSStatus ret = kGeneralErr;
	quectel_jdval_s_t old_val;

	if (NULL == jdcfgP)
	{
		atcmd_nw_log("[quec jd] jdcfg is NULL,jdcfg save to nv failed");
		return ret;
	}
	memset(&old_val, 0, sizeof(old_val));
	if (QUEC_FAT_SUCCESS != quectel_nv_fat_read(QUEC_EFS_JAM_DET,&old_val,sizeof(quectel_jdval_s_t)))
	{
		atcmd_nw_log("[quec jd] jdcfg read nv failed,use default value");
	}
	if (0 != memcmp(&old_val,jdcfgP,sizeof(quectel_jdval_s_t)))
	{
        ret = quectel_nv_fat_write(QUEC_EFS_JAM_DET, jdcfgP, sizeof(quectel_jdval_s_t));
    	if (ret != QUEC_FAT_SUCCESS)
    	{
        	atcmd_nw_log("[quec jd] jd cfg values write failed");
       	 	return ret;
    	}
	}
    else 
    {
		atcmd_nw_log("[quec jd]jd cfg values no change");
	}
    return QUEC_SUCCESS;
}

bool quec_vaild_timer_type(quec_time_type_e_t timer_type)
{
	if ((timer_type < QUEC_REPORT_TIMER) || (timer_type > QUEC_PERIOD_TIMER))
	{
		return FALSE;
	}
	return TRUE;
}


QuecOSStatus quec_timer_create_init(quec_time_type_e_t timer_type)
{
	QuecOSStatus err = kNoErr;

	if (FALSE == quec_vaild_timer_type(timer_type))
	{
		Log_Print("[quec jd] timer type is invaild");
		return kGeneralErr;
	}
	
	switch(timer_type)
	{
	  /* 通过CI_DEV_PRIM_CELLS_INFO_IND 上报，无需定时器， 只保留周期上报定时器即可 */	
		case QUEC_PERIOD_TIMER:
		{
			if (NULL != g_jd_period_report_Timer)
			{
				Log_Print("[quec jd] period timer already create");
				return kNoErr;
			}
			if (kNoErr != quec_rtos_timer_create(&g_jd_period_report_Timer))
			{
				Log_Print("[quec jd] timer create failed");
				err = kGeneralErr;
			}
			break;
		}
			
		default:
			break;
	}

	return err;
}

RETURNCODE_T quec_exec_qjdr_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc = INITIAL_RETURN_CODE;
	CiReturnCode	ret	= CIRC_FAIL;
	char res_buf[128] = {0};
	UINT8 resp_len = 0;
	UINT8 param_num = 0;
	UINT8 i = 0;
	int jd_temp = 0;
	quectel_jdval_s_t val;
	 
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);				
	*xid_p = atHandle;

	/*
	 **  Check the format of the request.
	 */
	param_num = quec_get_at_param_num(parameter_values_p,num_parameters);
	atcmd_nw_log("[quec jd]command type=%d,param_num=%d,atHandle=%d",op,param_num,atHandle);
    
	switch (op)
	{
		case TEL_EXT_SET_CMD:	 /* AT+QJDR=(0,1) */
		{
			if (1 == param_num)
			{
				if (FALSE == getExtValue( parameter_values_p, 
								 		  0, 
								 		  &jd_temp, 
								          rr_quectel_jdcfg[JDENABLE].minval, 
								          rr_quectel_jdcfg[JDENABLE].maxval, 
								          0
								         )
			    )
				{
					atcmd_nw_log("[quec jd]set jd enable value %d is invaild",jd_temp);
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
				else 
				{
                    if (jd_temp != rr_quectel_jdcfg[JDENABLE].value)
                    {
                        if (1 == jd_temp)
                        {
                            /* 打开干扰检测上报信息at+MEDCR=0,56,1, 56对应CI_DEV_PRIM_CELLS_INFO_IND */
                            ret = DEV_SetMEDCR(atHandle, 56, 1);
                        }
                        else 
                        {
                            /*jd disable,disable CI_DEV_PRIM_CELLS_INFO_IND report*/
                            ret = DEV_SetMEDCR(atHandle, 56, 0);
                        }
                        rr_quectel_jdcfg[JDENABLE].value = jd_temp;
                        atcmd_nw_log("[quec jd]jd enable = %d",rr_quectel_jdcfg[JDENABLE].value);
                        /*save to nv*/
                        memset(&val, 0, sizeof(quectel_jdval_s_t));
                        for (i = 0; i < JDCFG_ENUM_MAX; i++)
                        {
                            val.jdvalue[i] = rr_quectel_jdcfg[i].value;
                        }
                        quec_jam_det_set_to_nv(&val);
                        if (0 == rr_quectel_jdcfg[JDENABLE].value)
                        {
                        	jamdet_current_status = JAM_DET_REMOVE;
                        	/*stop period report timer*/
                        	if (0 != quec_get_jdcfg_val(JDPERIOD))
                        	{
                        	    if (NULL != g_jd_period_report_Timer)
                                {
                                    if (kNoErr != quec_rtos_timer_stop(g_jd_period_report_Timer))
                        		    {
                        			    atcmd_nw_log("[quec jd]jd period report timer stop failed");
                        		    }
                                }
                        	}
                        }
                    }

					ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}
			}
			else
			{
				atcmd_nw_log("[quec jd]param number mismatch,param_num =%d",param_num);
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
			break;
		}
		case TEL_EXT_GET_CMD:
		{
			if ( FALSE == (bool)rr_quectel_jdcfg[JDENABLE].value )
			{
				resp_len = snprintf(res_buf, sizeof(res_buf)-1, "+QJDR: %d\r\n",rr_quectel_jdcfg[JDENABLE].value);
			}
			else 
			{
				if((jamdet_current_status == JAM_DET_INSERT) || (jamdet_current_status == JAM_DET_INSERT_URC_DISABLE))
            	{
					resp_len = snprintf(res_buf, sizeof(res_buf)-1, "+QJDR: JAMMED\r\n");
				}
				else
				{
					resp_len = snprintf(res_buf, sizeof(res_buf)-1, "+QJDR: NOJAMMING\r\n");
				}
			}
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
			break;
		}
		case TEL_EXT_TEST_CMD:	  /* AT+QCFG=? */
		{
			resp_len = snprintf(res_buf, sizeof(res_buf)-1, "+QJDR: (0,1)\r\n");
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			break;
		}
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

void quec_jamming_detection_period_msg_process(void)
{
	char at_urc_buf[64] = {0};
	uint32 at_urc_len = 0;
    static bool no_jamming_is_reported = TRUE;
    bool is_send = FALSE;
	QuecOSStatus err = kNoErr;
	
	atcmd_nw_log("[quec jd] period report timer process");

	if ((rr_quectel_jdcfg[JDPERIOD].value != 0)
        &&(rr_quectel_jdcfg[JDENABLE].value != 0)
        &&(rr_quectel_jdcfg[JDURC].value != 0))
	{       
        if(JAM_DET_INSERT == jamdet_current_status)
        {
			sprintf(at_urc_buf, "+QJDR: %s", "JAMMED");
        	at_urc_len = strlen(at_urc_buf);
            is_send = TRUE;
            no_jamming_is_reported = FALSE;
        }
        else if(JAM_DET_REMOVE == jamdet_current_status)
        {
			sprintf(at_urc_buf, "+QJDR: %s", "NOJAMMING");
        	at_urc_len = strlen(at_urc_buf);
            if(!no_jamming_is_reported)
            {
                is_send = TRUE;
                no_jamming_is_reported = TRUE;
            }
            else
            {
                is_send = FALSE;
            }
        }
		
        if(is_send)
        {
        	/* URC_OUT_METHOD_BROADCAST or URC_OUT_METHOD_UNICAST*/
            err = at_urc_send(NUM_OF_TEL_ATP, at_urc_buf, at_urc_len, 0, URC_OUT_METHOD_UNICAST, NULL);
			if (err != kNoErr)
			{
				atcmd_nw_log("[quec jd]jd state urc send failed");
				return;
			}
        }
	}
	return;
}

void quec_jd_period_report_Timer_callback(UINT32 argv)
{
	QuecOSStatus ret = QUEC_SUCCESS;

	ret = quec_send_msg_to_handle_task(QUEC_JAM_DET_PERIOD_MSG, NULL, QUEC_JD_MSG_LEN_NONE);
	if(ret != QUEC_SUCCESS)
	{
		atcmd_nw_log("[quec jd]quec_send_msg_to_modem_router send period JD msg failed");
	} 
	return;
}

/*jd urc report */
void quec_jam_detect_indicate_urc(jamdet_cmd_e_type type, jamdet_res_e_type det_status)
{
	char at_urc_buf[64] = {0};
	uint32 at_urc_len = 0;
	bool need_send = FALSE;
	QuecOSStatus err = kGeneralErr;

	atcmd_nw_log("[quec jd] jd old status %d,new status %d",jamdet_current_status,det_status);
	memset(at_urc_buf,0,sizeof(at_urc_buf));
	
	if (jamdet_current_status == det_status)
	{
		atcmd_nw_log("[quec jd]jd status %d",det_status);
		return;
	}
	else
	{
		jamdet_current_status = det_status;
	}
	
	if( (0 != rr_quectel_jdcfg[JDURC].value) &&
		(0 != rr_quectel_jdcfg[JDENABLE].value)
	)
	{
		switch(type)
		{
			case JAM_DET_GSM_TYPE:
        	case JAM_DET_WCDMA_TYPE:
			case JAM_DET_FDD_LTE_TYPE:
        	{
        		need_send = TRUE;
				if (JAM_DET_INSERT == det_status)
				{
					jamdet_current_status = JAM_DET_INSERT;
					sprintf(at_urc_buf, "+QJDR: %s", "JAMMED");
        			at_urc_len = strlen(at_urc_buf);
				}
				else 
				{
					jamdet_current_status = JAM_DET_REMOVE;
					sprintf(at_urc_buf, "+QJDR: %s", "NOJAMMING");
        			at_urc_len = strlen(at_urc_buf);
				}
				if(rr_quectel_jdcfg[JDPERIOD].value != 0)
                {
                    //only record the jamdet_current_status. not report the URC.
                    need_send = FALSE;
                }
			}
			break;
			
			default:
            	break;
		}
	}
	else 
	{
		need_send = FALSE;
	}
	
	if (need_send)
	{
		(void)at_urc_send(NUM_OF_TEL_ATP, at_urc_buf, at_urc_len, FALSE, URC_OUT_METHOD_UNICAST, NULL);
	}
	return;
}

/******************************************************************************************
isaac.shi@quectel.com-2020/05/09:Description....
Refer to [Issue-Depot].[IS0001187][Submitter:2020-05-09,Date:2020-05-09]
<模块网络的干扰检测功能，at+qjdcfg="rssi",<val>等命令，配置为负数的时候全部报错>
******************************************************************************************/

bool quec_vaild_qjdcfg_val(UINT8 index,int32 val)
{
	bool ret = FALSE;

	if ((val >= rr_quectel_jdcfg[index].minval) && (val <= rr_quectel_jdcfg[index].maxval))
	{
		ret = TRUE;
	}

	return ret;
}

RETURNCODE_T quec_exec_qjdcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc = INITIAL_RETURN_CODE;
	CiReturnCode	ret	= CIRC_FAIL;
	char res_buf[512] = {0};
	UINT8 resp_len = 0;
	UINT8 param_num = 0;
	UINT8 cmd_index = 0;
	char jdcfg_cmd_str[20] = {0};
	INT16 jdcfg_cmd_str_len = 0; 
	quectel_jdval_s_t val;
	int32 tmp_val = 0;
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);				
	*xid_p = atHandle;
	UINT32 index = *(TelAtParserID*)arg_p;

	/*
	 **  Check the format of the request.
	 */
	param_num = quec_get_at_param_num(parameter_values_p,num_parameters);
	atcmd_nw_log("[quec jd]command type=%d,param_num=%d,atHandle=%d",op,param_num,atHandle);

	switch (op)
	{
		case TEL_EXT_SET_CMD:	 
		{
			if (2 != param_num)
			{
				atcmd_nw_log("[quec jd]param number mismatch,param_num =%d",param_num);
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
			else 
			{
				if (FALSE == getExtString(parameter_values_p, 0, jdcfg_cmd_str, 20, &jdcfg_cmd_str_len, NULL))
				{
					atcmd_nw_log("[quec jd] param error,jdcfg_cmd_str=%s",jdcfg_cmd_str);
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
				else 
				{
					for(cmd_index = JDURC; cmd_index < JDCFG_ENUM_MAX; cmd_index++)
					{
						if (0 == strcasecmp(jdcfg_cmd_str, rr_quectel_jdcfg[cmd_index].cmd_str))
						{	
							memset(jdcfg_cmd_str,0,sizeof(jdcfg_cmd_str));
							if (FALSE == getExtString(parameter_values_p, 1, jdcfg_cmd_str,20, &jdcfg_cmd_str_len, NULL))
							{
								atcmd_nw_log("[quec jd] param error,jdcfg_str_val=%s",jdcfg_cmd_str);
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
								rc = HANDLE_RETURN_VALUE(ret);
								return(rc);
							}
							else 
							{
								if(FALSE == str2int32(jdcfg_cmd_str, 4, &tmp_val))
								{
									atcmd_nw_log("[quec jd] param error,jdcfg_str_val=%s",jdcfg_cmd_str);
									ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
									rc = HANDLE_RETURN_VALUE(ret);
									return(rc);
								}
								if (FALSE == quec_vaild_qjdcfg_val(cmd_index,tmp_val))
								{
									atcmd_nw_log("[quec jd] cmd_index=%d,tmp_val=%d",cmd_index,tmp_val);
									ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
									rc = HANDLE_RETURN_VALUE(ret);
									return(rc);
								}
								rr_quectel_jdcfg[cmd_index].value = tmp_val;
								if (cmd_index == JDPERIOD)
								{
									if (rr_quectel_jdcfg[JDPERIOD].value != 0)
									{
										/*create and start urc period report timer*/
										quec_timer_create_init(QUEC_PERIOD_TIMER);
										if (kNoErr != quec_jd_report_start_timer(QUEC_PERIOD_TIMER,
															g_jd_period_report_Timer,
															rr_quectel_jdcfg[JDPERIOD].value*QUEC_TIME_UNIT_SECOND,
															quec_jd_period_report_Timer_callback))
										{
											atcmd_nw_log("[quec jd]jd period report timer start failed");
										}
									}
									else 
									{
										/*stop period report timer */
										if (NULL != g_jd_period_report_Timer)
                                        {
										    quec_rtos_timer_stop(g_jd_period_report_Timer);
                                        }
									}
								}
							}
							break;
						}
					}
					if (cmd_index >= JDCFG_ENUM_MAX)
					{
						atcmd_nw_log("[quec jd]index(%d) >= JDCFG_ENUM_MAX(%d)",cmd_index,JDCFG_ENUM_MAX);
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
						rc = HANDLE_RETURN_VALUE(ret);
						return(rc);
					}
					/*save to nv*/
					memset(&val, 0, sizeof(quectel_jdval_s_t));
					for (cmd_index = 0; cmd_index < JDCFG_ENUM_MAX; cmd_index++)
					{
						val.jdvalue[cmd_index] = rr_quectel_jdcfg[cmd_index].value;
					}
					quec_jam_det_set_to_nv(&val);
					ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
				}			
			}
			break;
		}
		case TEL_EXT_GET_CMD:
		{
		    int buf_index = 0;
			
			for (cmd_index = JDURC; cmd_index < JDCFG_ENUM_MAX;cmd_index++)
			{
				resp_len = snprintf(res_buf + buf_index, sizeof(res_buf)-buf_index-1, "+QJDCFG: \"%s\",%d\r\n",
									rr_quectel_jdcfg[cmd_index].cmd_str,rr_quectel_jdcfg[cmd_index].value);
				buf_index += resp_len;
			}
			atcmd_nw_log("[quec jd]resp_len %d,resbuf = %s",buf_index,res_buf);
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
			break;
		}
		case TEL_EXT_TEST_CMD:	  /* AT+QCFG=? */
		{
			 quec_siolib_transmit_to_atp(*(TelAtParserID*)arg_p, "\r\n", 2, NULL);
             for(cmd_index = JDURC; cmd_index < JDCFG_ENUM_MAX; cmd_index++)
             {
                if (((cmd_index >= JDURC) && (cmd_index <= JDMINCH)) || (cmd_index == JDSHAKEPERIOD))
				{
					resp_len = 0;
					memset(res_buf,0,sizeof(res_buf));
					resp_len=snprintf(res_buf, sizeof(res_buf)-1, "+QJDCFG: \"%s\",(%d,%d)\r\n",
                			rr_quectel_jdcfg[cmd_index].cmd_str,rr_quectel_jdcfg[cmd_index].minval,rr_quectel_jdcfg[cmd_index].maxval);
					ret = quec_siolib_transmit_to_atp(index, (uint8*)res_buf, resp_len, NULL);
				}
				else 
				{
					resp_len = 0;
					memset(res_buf,0,sizeof(res_buf));
					resp_len=snprintf(res_buf, sizeof(res_buf)-1, "+QJDCFG: \"%s\",(%d~%d)\r\n",
                			rr_quectel_jdcfg[cmd_index].cmd_str,rr_quectel_jdcfg[cmd_index].minval,rr_quectel_jdcfg[cmd_index].maxval);
					ret = quec_siolib_transmit_to_atp(index, (uint8*)res_buf, resp_len, NULL);
				}
             }
			 
             ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
             atcmd_nw_log("[quec jd]ret = %d",ret);
			break;
		}
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}
	}
	
	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

#endif


#if 0
QuecOSStatus quec_read_freq_scan_config(void)
{
    QuecOSStatus ret = kGeneralErr;
	QuecFreqScanType freq_scan_config_rd = {0};

    ret = quectel_nv_fat_read(QUEC_FREQ_SCAN_NVM, &freq_scan_config_rd, sizeof(QuecFreqScanType));
    if(ret != QUEC_FAT_SUCCESS)
    {
        atcmd_nw_log("freq_scan_config read failed"); 
        return ret;
    }
	
	atcmd_nw_log("freq_scan_config %d %d", freq_scan_config_rd.backg_scan_num, freq_scan_config_rd.foreg_scan_num); 
	memcpy(&quec_freq_scan_config, &freq_scan_config_rd, sizeof(QuecFreqScanType));
    return QUEC_SUCCESS;
}

QuecOSStatus quec_write_freq_scan_config(UINT16 bg_scan_opt, UINT16 fg_scan_opt)
{
    QuecOSStatus ret = kGeneralErr;
	QuecFreqScanType freq_scan_config_wr = {0};
	if ((quec_freq_scan_config.backg_scan_num==bg_scan_opt) && (quec_freq_scan_config.foreg_scan_num==fg_scan_opt))
	{
        atcmd_nw_log("freq_scan_config %d %d, no change", bg_scan_opt, fg_scan_opt);
        return QUEC_SUCCESS;
	}
	freq_scan_config_wr.backg_scan_num = bg_scan_opt;
	freq_scan_config_wr.foreg_scan_num = fg_scan_opt;
    ret = quectel_nv_fat_write(QUEC_FREQ_SCAN_NVM, &freq_scan_config_wr, sizeof(QuecFreqScanType));
    if (ret != QUEC_FAT_SUCCESS)
    {
        atcmd_nw_log("freq_scan_config %d %d write failed", freq_scan_config_wr.backg_scan_num, freq_scan_config_wr.foreg_scan_num);
        return ret;
    }
	
	atcmd_nw_log("freq_scan_config update %d %d", freq_scan_config_wr.backg_scan_num, freq_scan_config_wr.foreg_scan_num); 
	memcpy(&quec_freq_scan_config, &freq_scan_config_wr, sizeof(QuecFreqScanType));
    return QUEC_SUCCESS ;
}

extern UINT8 get_commonReserved_value(UINT8 positionToGet, UINT8 SimID);//0~31
extern UINT16 get_commonReserved_1_value(UINT8 positionToGet, UINT8 SimID);//32~128, the real param is position-32, eg: 32=0, 33=1
QuecOSStatus quec_freq_scan_config_set(void)
{
	char res_buf[128] = {0};
	char set_buf[64] = {0};
	
//	quec_asr_freq_scan_config.backg_scan_num = get_commonReserved_1_value(0);//0=32-32
//	quec_asr_freq_scan_config.foreg_scan_num = get_commonReserved_1_value(1);//1=33-32

	//SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+MEDCR=1,32\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
	//SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "AT+MEDCR=1,33\r\n", 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
	
    atcmd_nw_log("get asr freq scan config %d %d", quec_asr_freq_scan_config.backg_scan_num, quec_asr_freq_scan_config.foreg_scan_num);
	
	if (quec_freq_scan_config.backg_scan_num != quec_asr_freq_scan_config.backg_scan_num)
	{
		sprintf(set_buf, "AT+MEDCR=0,32,%d\r\n", quec_freq_scan_config.backg_scan_num);
		SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, set_buf, 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
	}
	if (quec_freq_scan_config.foreg_scan_num != quec_asr_freq_scan_config.foreg_scan_num)
	{
		sprintf(set_buf, "AT+MEDCR=0,33,%d\r\n", quec_freq_scan_config.foreg_scan_num);
		SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, set_buf, 20, NULL, 1, NULL, res_buf, sizeof(res_buf));
	}
}
RETURNCODE_T quectel_exec_qcfg_freqscanopt_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	 rc 	  = INITIAL_RETURN_CODE;
	CiReturnCode	 ret	  = CIRC_FAIL;
	QuecOSStatus	 status   = QUEC_SUCCESS;
	int 			 type;
	UINT32	index;

	UINT32 atHandle =	   *xid_p;
	index  = *(TelAtParserID *)arg_p;
	char res_buf[100]={0};
	char  cfg_cmd_param_str[20] = {0};
	UINT8 cfg_cmd_param_str_len=0;
	UINT8 resp_len=0;
	UINT8 param_num=0;
	UINT8 opt_index = 0;
	UINT16 scan_num = 0;
	
	/*
	 **  Check the format of the request.
	 */
	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);

	atcmd_nw_log("command type=%d,param_num=%d",op,param_num);
	switch (op)
	{
		case TEL_EXT_SET_CMD:	 /* AT+QCFG="freqscanopt",..  */
		{
			if (param_num == 1)
			{
				atcmd_nw_log("freqscanopt=%d,%d", quec_freq_scan_config.backg_scan_num, quec_freq_scan_config.foreg_scan_num);
				resp_len = snprintf(res_buf, sizeof(res_buf)-1, "+QCFG: \"freqscanopt\",%d,%d\r\n", quec_freq_scan_config.backg_scan_num, quec_freq_scan_config.foreg_scan_num);
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
			}
			else if (param_num == 3)
			{
				if (TRUE != getExtString(parameter_values_p, 1, cfg_cmd_param_str, 20, &cfg_cmd_param_str_len, NULL))
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				if(TRUE != str2int32(cfg_cmd_param_str, 1, &opt_index))
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				if (opt_index > 1)
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				
				if (TRUE != getExtString(parameter_values_p, 2, cfg_cmd_param_str, 20, &cfg_cmd_param_str_len, NULL))
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				if(TRUE != str2int32(cfg_cmd_param_str, 3, &scan_num))
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				if (((scan_num>0) && (scan_num<20)) || (scan_num>300))
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
				atcmd_nw_log("set freqscanopt=%d, %d", opt_index, scan_num);

				
				UINT16 bg_scan_num = quec_freq_scan_config.backg_scan_num;
				UINT16 fg_scan_num = quec_freq_scan_config.foreg_scan_num;
				if (opt_index == 0)
				{
					if (quec_freq_scan_config.backg_scan_num == scan_num)
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						break;
					}
					bg_scan_num = scan_num;
				}
				else if (opt_index == 1)
				{
					if (quec_freq_scan_config.foreg_scan_num == scan_num)
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						break;
					}
					fg_scan_num = scan_num;
				}
				
				status = quec_write_freq_scan_config(bg_scan_num, fg_scan_num);
				if(status != QUEC_SUCCESS)
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_ERROR, NULL, NULL);
					atcmd_nw_log(" quec set freqscanopt fail, status=%d", status);
				}
				else
				{
#ifdef QUECTEL_PROJECT_CUST 
					ret = DEV_SetMEDCR(atHandle, 0, 32+opt_index, scan_num);
#else
					ret = DEV_SetMEDCR(atHandle, 32+opt_index, scan_num);
#endif
				}
			}
			else
			{
				 ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
			break;
		}
		case TEL_EXT_TEST_CMD:	  /* AT+QCFG=? */
		{
			resp_len=snprintf(res_buf, sizeof(res_buf)-1, "+QCFG: \"freqscanopt\",(0,1),(0,20-300)\r\n");
			ret=quec_siolib_transmit_to_atp(index, res_buf, resp_len, NULL);
			break;
		}
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}

	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}
#endif

#ifdef QUEC_POWER_BACKOFF_SUPPORT  
/*************************************
  Add by Wayne.wei 2020.07.31 
  新增2G/4G功率回退功能，通过at+qpwrbackoff命令配置相应参数，配置的参数会保存到nv中，重启模块后会自动使能功率回退功能.
************************************/
#define QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME	"RFPmaxReductionConfig.nvm"
#define QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME "RspDigRfLtepmaxReductionConfig.nvm"

extern BOOL RFPmaxReductionConfigFile_CreateNVMFile(void);
extern BOOL LtePmaxReductionConfigFile_CreateNVMFile(void);

extern bool quectel_nv_fat_file_is_exist(const char *file_name);
extern int32 quec_ASR_nv_fat_read_pwr_backoff_file(const char *file_path,   void *read_buf,    size_t read_size);
extern int32 quec_ASR_nv_fat_write_pwr_backoff_file(const char  *file_name, void *write_buf,  size_t   write_size );

int  Quec_read_LTE_pwrbackoff_nv_config(RspDigRfLtePmaxReductionConfig_ts * quec_rflte_pwrbackoff_read_config)
{
	int32 ret=QUEC_FAT_SUCCESS;

	ret = quec_ASR_nv_fat_read_pwr_backoff_file(QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME, quec_rflte_pwrbackoff_read_config, sizeof(RspDigRfLtePmaxReductionConfig_ts));
	if(ret != QUEC_FAT_SUCCESS)
	{
		atcmd_nw_log("[wayne]quectel_nv_fat_write lte fail");
	}
	return ret;

}

int Quec_write_LTE_pwrbackoff_nv_config(RspDigRfLtePmaxReductionConfig_ts * quec_rflte_pwrbackoff_write_config)
{
	int32 ret=QUEC_FAT_SUCCESS;
	ret = quec_ASR_nv_fat_write_pwr_backoff_file(QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME, quec_rflte_pwrbackoff_write_config, sizeof(RspDigRfLtePmaxReductionConfig_ts));
	if(ret != QUEC_FAT_SUCCESS)
	{
		atcmd_nw_log("[wayne]quectel_nv_fat_write lte fail");
	}
	return ret;
} 
int  Quec_read_pwrbackoff_nv_config(RspDigRf3GPmaxReductionConfig_ts * quec_rf3g_pwrbackoff_read_config)
{
	int32 ret=QUEC_FAT_SUCCESS;

	ret = quec_ASR_nv_fat_read_pwr_backoff_file(QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME, quec_rf3g_pwrbackoff_read_config, sizeof(RspDigRf3GPmaxReductionConfig_ts));
	if(ret != QUEC_FAT_SUCCESS)
	{
		atcmd_nw_log("[wayne]quectel_nv_fat_write fail");
	}
	return ret;

}

int Quec_write_pwrbackoff_nv_config(RspDigRf3GPmaxReductionConfig_ts * quec_rf3g_pwrbackoff_write_config)
{
	int32 ret=QUEC_FAT_SUCCESS;
	ret = quec_ASR_nv_fat_write_pwr_backoff_file(QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME, quec_rf3g_pwrbackoff_write_config, sizeof(RspDigRf3GPmaxReductionConfig_ts));
	if(ret != QUEC_FAT_SUCCESS)
	{
		atcmd_nw_log("[wayne]quectel_nv_fat_write fail");
	}
	return ret;
}
 quec_pwr_backoff_mode  quec_get_pwr_backoff_labels_type(char  * quec_set_band_name)
{
    uint32  type_index = 0;
    quec_pwr_backoff_mode mode=QUEC_PWR_BACKOFF_NONE;
	quec_pwr_backoff_label_type quec_pwr_backoff_labels[]= {
	   { QUEC_PWR_BACKOFF_GSM900, "GSM900"}, 
	   { QUEC_PWR_BACKOFF_GSM850, "GSM850"},
	   { QUEC_PWR_BACKOFF_GSM1800, "GSM1800"},
	   { QUEC_PWR_BACKOFF_GSM1900, "GSM1900"},	   
	   { QUEC_PWR_BACKOFF_LTE_BANDx, "LTEx"},
 	};
    for(type_index = 0; type_index < sizeof(quec_pwr_backoff_labels)/sizeof(quec_pwr_backoff_labels[0]);type_index++)
    {
        if(strcasecmp(quec_set_band_name, quec_pwr_backoff_labels[type_index].band_name) == 0)
        {
        	mode=quec_pwr_backoff_labels[type_index].mode;
            break;
        }	
    }
	if(strncasecmp(quec_set_band_name,"LTE",3)==0)
	{
		mode=QUEC_PWR_BACKOFF_LTE_BANDx;
	}
    return mode;
	
}  
int  Quec_RspDigRfLtePmaxReductionConfig_ts_config(char  * lte_band,INT16 pwr_backoff_value)
{
		int ret=0,lte_band_value=0,lte_nv_value=0;
		RspDigRfLtePmaxReductionConfig_ts quec_rflte_pwrbackoff_config_update;
		INT16 *lte_value_ptr=NULL;
		lte_value_ptr=&(quec_rflte_pwrbackoff_config_update.pmaxReductionValueLTEBand1);
		memset(&quec_rflte_pwrbackoff_config_update,0,sizeof(quec_rflte_pwrbackoff_config_update));
		if( quectel_nv_fat_file_is_exist(QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
		{
			if(Quec_read_LTE_pwrbackoff_nv_config(&quec_rflte_pwrbackoff_config_update))
			{
		   		atcmd_nw_log("[wayne]Quec_read_lte_pwrbackoff_nv_config error!");
		   		return -1;
			}
		}
		else
		{
		    atcmd_nw_log("[wayne]RspDigRfLtepmaxReductionConfig.nvm not exist,and now create it!");
			LtePmaxReductionConfigFile_CreateNVMFile();
		}
		sscanf(lte_band, "LTE%d", &lte_band_value);
		if(lte_band_value <1 ||lte_band_value >44 )
		{
			atcmd_nw_log("[wayne]lte_band_value error!");
			return -2;
		}
		lte_nv_value=*(lte_value_ptr+lte_band_value-1);
		atcmd_nw_log("[wayne]lte_band %d,lte_nv_value %d,pwr_backoff_value %d,flag %d",lte_band_value,lte_nv_value,pwr_backoff_value,quec_rflte_pwrbackoff_config_update.pmaxReductionFlag);
		if(lte_nv_value != pwr_backoff_value)
		{		
			if(quec_rflte_pwrbackoff_config_update.pmaxReductionFlag==PMAX_REDUCTION_DISABLE)
			{
				quec_rflte_pwrbackoff_config_update.pmaxReductionFlag=PMAX_REDUCTION_ENABLE;
			}
			*(lte_value_ptr+lte_band_value-1)=pwr_backoff_value;
			ret =Quec_write_LTE_pwrbackoff_nv_config(&quec_rflte_pwrbackoff_config_update);
			atcmd_nw_log("[wayne] write lte nv,ret %d",ret);
		}
		else
		{
			atcmd_nw_log("[wayne]quec_rflte_pwrbackoff_config value is identical!");
		}
	return ret;
}

/*****************************************
此函数通过传入的参数来配置对应的制式下band的功率回退值，函数做了判同处理；
************************************/
int  Quec_RspDigRf3GPmaxReductionConfig_ts_config(quec_pwr_backoff_mode mode,INT16 pwr_backoff_value)
{
		int i,j,update_flag=0;
		int ret=0;
		RspDigRf3GPmaxReductionConfig_ts quec_rf3g_pwrbackoff_config_update;
		memset(&quec_rf3g_pwrbackoff_config_update,0,sizeof(quec_rf3g_pwrbackoff_config_update));
		if( quectel_nv_fat_file_is_exist(QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
		{
			if(Quec_read_pwrbackoff_nv_config(&quec_rf3g_pwrbackoff_config_update))
			{
		   		atcmd_nw_log("[wayne]Quec_read_pwrbackoff_nv_config error!");
		   		return -1;
			}
		}
		else
		{
		    atcmd_nw_log("[wayne]RFPmaxReductionConfig.nvm not exist,and now create it!");
			RFPmaxReductionConfigFile_CreateNVMFile();
		}
		atcmd_nw_log("[wayne]config_mode %d,value %d!",mode,pwr_backoff_value);
		switch (mode) {
		case QUEC_PWR_BACKOFF_GSM900:
			for(i=0;i<2;i++)
			{
				for(j=0;j<4;j++)
				{ 
					if( quec_rf3g_pwrbackoff_config_update.pmaxReductionValueEGSM[i][j] != pwr_backoff_value )
					{
						quec_rf3g_pwrbackoff_config_update.pmaxReductionValueEGSM[i][j]=pwr_backoff_value;
						update_flag = 1;
					}
				}
			}			
			break;
		case QUEC_PWR_BACKOFF_GSM850:
			for(i=0;i<2;i++)
			{
				for(j=0;j<4;j++)
				{
					if(quec_rf3g_pwrbackoff_config_update.pmaxReductionValueGSM850[i][j] != pwr_backoff_value)
					{
						quec_rf3g_pwrbackoff_config_update.pmaxReductionValueGSM850[i][j]=pwr_backoff_value;
						update_flag = 1;
					}
				}
			}
			break;
		case QUEC_PWR_BACKOFF_GSM1800:
			for(i=0;i<2;i++)
			{
				for(j=0;j<4;j++)
				{
					if(quec_rf3g_pwrbackoff_config_update.pmaxReductionValueDCS[i][j] != pwr_backoff_value)
					{
						quec_rf3g_pwrbackoff_config_update.pmaxReductionValueDCS[i][j]=pwr_backoff_value;
						update_flag = 1;
					}
				}
			}
			break;
		case QUEC_PWR_BACKOFF_GSM1900:
			for(i=0;i<2;i++)
			{
				for(j=0;j<4;j++)
				{
					if(quec_rf3g_pwrbackoff_config_update.pmaxReductionValuePCS[i][j] != pwr_backoff_value)
					{
						quec_rf3g_pwrbackoff_config_update.pmaxReductionValuePCS[i][j]=pwr_backoff_value;
						update_flag = 1;
					}
				}
			}
			break;
		default:
			ret =-2;
			atcmd_nw_log("[wayne]mode is default!");
			return ret;
			break;
		}
		if(update_flag)
		{
			if(quec_rf3g_pwrbackoff_config_update.pmaxReductionFlag==PMAX_REDUCTION_DISABLE)
			{
				quec_rf3g_pwrbackoff_config_update.pmaxReductionFlag=PMAX_REDUCTION_ENABLE;
			}
			ret =Quec_write_pwrbackoff_nv_config(&quec_rf3g_pwrbackoff_config_update);
			atcmd_nw_log("[wayne] write nv,ret %d",ret);
		}
		else
		{
			atcmd_nw_log("[wayne]quec_rf3g_pwrbackoff_config value is identical!");
		}
	return ret;
}
int  Quec_read_pwrbackoff_nv_config_switch(quec_pwr_backoff_mode mode,char *band_str,char *resp_buf)
{
    int ret =0;
	if(mode==QUEC_PWR_BACKOFF_LTE_BANDx)
	{
		RspDigRfLtePmaxReductionConfig_ts quec_rflte_pwrbackoff_config_read;
		int lte_band=0;
		INT16 *lte_value_ptr=NULL;
		lte_value_ptr=&(quec_rflte_pwrbackoff_config_read.pmaxReductionValueLTEBand1);
		memset(&quec_rflte_pwrbackoff_config_read,0,sizeof(quec_rflte_pwrbackoff_config_read));
		if(quectel_nv_fat_file_is_exist(QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
		{
			if(Quec_read_LTE_pwrbackoff_nv_config(&quec_rflte_pwrbackoff_config_read) != QUEC_FAT_SUCCESS)
			{
				atcmd_nw_log("[wayne]Quec_read_LTE_pwrbackoff_nv_config fail!!!");
				return -4;
			}
			sscanf(band_str, "LTE%d", &lte_band);
			atcmd_nw_log("[wayne]lte_band is %d\n",lte_band);
			if((0<lte_band)&&(lte_band<45))
			{
				sprintf(resp_buf,"+QPWRBACKOFF: %s,%d\r\n",band_str,*(lte_value_ptr+lte_band-1));
			}
			else
			{
				return -5;
			}
		}
		else
		{
			atcmd_nw_log("[wayne]RspDigRfLtepmaxReductionConfig.nvm not exist!!!");
			return -6;
		}
	}
	else
	{
	/*
		RspDigRf3GPmaxReductionConfig_ts quec_rf3g_pwrbackoff_config_read;
		memset(&quec_rf3g_pwrbackoff_config_read,0,sizeof(quec_rf3g_pwrbackoff_config_read));
		if(quectel_nv_fat_file_is_exist(QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
		{
			if(Quec_read_pwrbackoff_nv_config(&quec_rf3g_pwrbackoff_config_read) != QUEC_FAT_SUCCESS)
			{
				atcmd_nw_log("[wayne]Quec_read_pwrbackoff_nv_config fail!!!");
				return -1;
			}
		}
		else
		{
			atcmd_nw_log("[wayne]RFPmaxReductionConfig.nvm not exist!!!");
			return -2;
		}
		switch (mode) {
				case QUEC_PWR_BACKOFF_GSM900:
					sprintf(resp_buf,"+QPWRBACKOFF: %s,%d\r\n",band_str,quec_rf3g_pwrbackoff_config_read.pmaxReductionValueEGSM[0][0]/8);
					break;
				case QUEC_PWR_BACKOFF_GSM850:
					sprintf(resp_buf,"+QPWRBACKOFF: %s,%d\r\n",band_str,quec_rf3g_pwrbackoff_config_read.pmaxReductionValueGSM850[0][0]/8);
					break;
				case QUEC_PWR_BACKOFF_GSM1800:
					sprintf(resp_buf,"+QPWRBACKOFF: %s,%d\r\n",band_str,quec_rf3g_pwrbackoff_config_read.pmaxReductionValueDCS[0][0]/8);
					break;
				case QUEC_PWR_BACKOFF_GSM1900:
					sprintf(resp_buf,"+QPWRBACKOFF: %s,%d\r\n",band_str,quec_rf3g_pwrbackoff_config_read.pmaxReductionValuePCS[0][0]/8);
					break;
				default:
					atcmd_nw_log("[wayne]mode is default!");
					return -3;
					break;
				}
	*/			
	}
	return ret;

}
/*****************************************
执行AT+qpwrbackoff=<band>,<value>调用此函数来配置不同制式下band的功率回退值，目前实行了GSM和WCDMA制式的功率回退功能
，执行命令配置完参数后，模块重启后功率回退生效，后面也可通过at+grip命令开关进行关闭和使能；
************************************/
RETURNCODE_T quec_exec_qpwrbackoff_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
	RETURNCODE_T	rc		 = INITIAL_RETURN_CODE;
	CiReturnCode	ret 	 = CIRC_FAIL;
		UINT32			 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	*xid_p = atHandle;
	UINT32 atp_index=GET_ATP_INDEX(atHandle);
	UINT8 param_num=0;
	char  band_str[32] = {0};
	UINT8 band_str_len=0;
	
	char resp_buf[64]={0};	
	quec_pwr_backoff_mode mode=QUEC_PWR_BACKOFF_NONE;
    int quec_pwr_backoff_value=0;
	int read_ret=0;
	
	atcmd_nw_log("[wayne]command type=%d,atp_index=%d",op,atp_index);
	
	switch (op)
	{
		case TEL_EXT_TEST_CMD:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QPWRBACKOFF: <band>,(0-20)\r\n");
				break;
			}	 
		case TEL_EXT_SET_CMD:
			{
				param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
				atcmd_nw_log("[wayne]rx param_num=%d",param_num);
				
				if(getExtString(parameter_values_p, 0, band_str, sizeof(band_str), &band_str_len, NULL) == TRUE)
				{
					mode=quec_get_pwr_backoff_labels_type(band_str);
					atcmd_nw_log("[wayne]rx band=%s,rx mode=%d\n",band_str,mode);
					str2upper(band_str,strlen(band_str));
					if(( mode != QUEC_PWR_BACKOFF_NONE)&&(mode != QUEC_PWR_BACKOFF_MAX))
					{
						if(param_num==1)
						{
                           	read_ret= Quec_read_pwrbackoff_nv_config_switch(mode,band_str,resp_buf);
						   	atcmd_nw_log("[wayne]reap_buf is %s,read_ret %d\n",resp_buf,read_ret);
							if(read_ret<0)
							{
							  ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"read config error!");
							}
							else
							{
								ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resp_buf);
							}
						   	break;
						}
						else if(param_num==2)
						{
							if(getExtValue(parameter_values_p, 1, &quec_pwr_backoff_value, QUEC_MIN_POWER_BACKOFF, QUEC_MAX_POWER_BACKOFF, 0) == TRUE)
							{
							    if(mode != QUEC_PWR_BACKOFF_LTE_BANDx)
						    	{
									quec_pwr_backoff_value = quec_pwr_backoff_value*8;//Scale unit 1/8 dB 

									if(Quec_RspDigRf3GPmaxReductionConfig_ts_config(mode,quec_pwr_backoff_value)==0)
									{
										atcmd_nw_log("[wayne]config_success\n");
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
										break;
									}
									else
									{
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"set 2G config error!");
										break;
									}
						    	}
								else
								{
									if(Quec_RspDigRfLtePmaxReductionConfig_ts_config(band_str,quec_pwr_backoff_value)==0)
									{
										atcmd_nw_log("[wayne]config_lte_success\n");
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
										break;
									}
									else
									{
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"set LTE config error!");
										break;
									}
								}
							}
						}
						else
						{
						  ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"parameter number error!");
						}

					}
					else 
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, (char*)"input band error!");
					}

				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
				break;
					
			}
		case TEL_EXT_ACTION_CMD:
		case TEL_EXT_GET_CMD:
		default:
			{	
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, (char*)"OPERATION_NOT_SUPPORTED");
				break;
			}
	
	}
	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}
static UINT8 quec_pwr_backoff_enable=0;
/*****************************************
可通过配置此AT命令决定是否使能功率回退，at+qgrip=1使能，at+qgrip=0关闭；
************************************/
RETURNCODE_T quec_exec_qgrip_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{

//	UNUSEDPARAM(command_name_p);
//	UNUSEDPARAM(num_parameters);
//	UNUSEDPARAM(info_text_p);
	RETURNCODE_T rc = INITIAL_RETURN_CODE;
	CiReturnCode ret = CIRC_FAIL;
	UINT32 atHandle = MAKE_AT_HANDLE(*(TelAtParserID *)arg_p);
	BOOL cmdValid = FALSE;
	char resBuf[32];

	*xid_p = atHandle;
	DBGMSG("%s: atHandle = %d.\n", __FUNCTION__, atHandle);


	switch ( op )
	{
		case TEL_EXT_SET_CMD:         /* AT*GRIP= */
		{
			int option = 0;
			int value = 0;
			if ( getExtValue(parameter_values_p, 0, &option, 0, 255, 0) == TRUE )
			{
				quec_pwr_backoff_enable=(UINT8)option;
			}
			else
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
			if( getExtValue(parameter_values_p, 1, &value, 0, 255, 0) != TRUE )
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				break;
			}
#if defined QUECTEL_PROJECT_CUST
            //Isaac 20210816: Just to make compile pass
			ret = DEV_SetPowerBackOffReq(atHandle, option, value, 6, 0);
#else
			ret = DEV_SetPowerBackOffReq(atHandle, option,value);
#endif
			break;
		}
		case TEL_EXT_GET_CMD: 
		{
		    sprintf( resBuf,"+QGRIP: %u\r\n",quec_pwr_backoff_enable);
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
		    break;
		}
		case TEL_EXT_TEST_CMD:
		{   
		    ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QGRIP: (0,1)\r\n");
		    break;
		} 
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}
	}

	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret);
	return(rc);
}

/**********************************
模块开机初始化时候会调用此函数，函数中会读取功率回退nv，然后根据nv值来判定是否启动功率回退功能
**********************************/
bool quec_grip_enbale_flag=FALSE;

void quec_check_nv_enable_rf3g_pwrbackoff(void)
{
/*
	CiReturnCode ret = CIRC_FAIL;
	RspDigRf3GPmaxReductionConfig_ts quec_rf3g_pwrbackoff_config;
	memset(&quec_rf3g_pwrbackoff_config,0,sizeof(quec_rf3g_pwrbackoff_config));
	if( quectel_nv_fat_file_is_exist(QUEC_RF_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
	{
		if(Quec_read_pwrbackoff_nv_config(&quec_rf3g_pwrbackoff_config)!= QUEC_FAT_SUCCESS)
		{
			atcmd_nw_log("[wayne]Quec_read_3g_pwrbackoff_nv_config error!");
		}
	}
	atcmd_nw_log("[wayne]rf3g_enable %d !",quec_rf3g_pwrbackoff_config.pmaxReductionFlag);
	if(quec_rf3g_pwrbackoff_config.pmaxReductionFlag==PMAX_REDUCTION_ENABLE)
	{
		quec_pwr_backoff_enable=1;
	    ret = DEV_SetPowerBackOffReq(IND_REQ_HANDLE,1,0);
		atcmd_nw_log("[wayne]3G PMAX_REDUCTION_ENABLE,ret= %d!",ret);

	}
	else
	{
		atcmd_nw_log("[wayne]3G PMAX_REDUCTION_DISABLE,return!");
	}
    return;
*/    
}

void quec_check_nv_enable_rflte_pwrbackoff(void)
{
	CiReturnCode ret = CIRC_FAIL;
	RspDigRfLtePmaxReductionConfig_ts quec_rflte_pwrbackoff_config;
	if(quec_grip_enbale_flag==FALSE)
	{
		memset(&quec_rflte_pwrbackoff_config,0,sizeof(quec_rflte_pwrbackoff_config));
		if( quectel_nv_fat_file_is_exist(QUEC_LTE_PMAX_REDUCTION_CONFIG_NVM_FILE_NAME))
		{
			if(Quec_read_LTE_pwrbackoff_nv_config(&quec_rflte_pwrbackoff_config)!= QUEC_FAT_SUCCESS)
			{
				atcmd_nw_log("[wayne]Quec_read_lte_pwrbackoff_nv_config error!");
			}
		}
		atcmd_nw_log("[wayne]rflte_enable %d !",quec_rflte_pwrbackoff_config.pmaxReductionFlag);
		if(quec_rflte_pwrbackoff_config.pmaxReductionFlag==PMAX_REDUCTION_ENABLE)
		{
			quec_pwr_backoff_enable=1;
			ret = DEV_SetPowerBackOffReq(IND_REQ_HANDLE,1,0);
			atcmd_nw_log("[wayne]LTE PMAX_REDUCTION_ENABLE,ret= %d!",ret);
		}
		else
		{
			atcmd_nw_log("[wayne]LTE PMAX_REDUCTION_DISABLE,return!");
		}
		quec_grip_enbale_flag=TRUE;
	}
    return;

}


#endif

#if defined(__QUEC_OEM_VER_LT__)
csq_info_s_t csq_info = {0};
quec_timer_t g_avgrssi_timer = NULL;    /*avgrssi report timer*/

QuecOSStatus quec_avgrssi_timer_create_init(void)
{
    QuecOSStatus err = kNoErr;

    if (NULL != g_avgrssi_timer)
    {
        atcmd_nw_log("quec avgrssi timer already create");
        return kNoErr;
	}
    if (kNoErr != quec_rtos_timer_create(&g_avgrssi_timer))
    {
        atcmd_nw_log("quec avgrssi timer create failed");
        err = kGeneralErr;
    }
    return err;
}

QuecOSStatus quec_avgrssi_start_timer
(
    quec_timer_t timer,
    uint32 time_experiod,
    void (*callBackRoutine)(UINT32)
)
{
	QuecOSStatus err = kNoErr;
	
	if (kNoErr != quec_rtos_timer_start(timer, time_experiod, TRUE, callBackRoutine, 0))
	{
		err = kGeneralErr;
	}
	
	return err;
}

void quec_avgrssi_msg_process(void)
{
    static INT16 pre_csq = 0;
    INT16 csq_temp1 = 99,csq_temp2 = 99;

#if QUEC_DUAL_SIM_SUPPORT
	quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info[isMasterSim0() ? SIM1 : SIM2]),&csq_temp1,&csq_temp2);
#else
    quec_cesq_2quec_csq((mmExtendedSignal_quec *)(&quec_netquality_info),&csq_temp1,&csq_temp2);
#endif
    if (csq_temp1 != 99)
    {
        csq_info.avg_csq = csq_temp1;
        csq_info.csq_number++;
    }
    else 
    {
        atcmd_nw_log("avgrssi: csq is invalid");
        return;
    }
    atcmd_nw_log("avgrssi: 1 minute time out,csq number = %d,csq = %d",csq_info.csq_number,csq_temp1);
    if (csq_info.csq_number != 0)
    {
        if (csq_info.csq_number == 1)
        {
            pre_csq = 0;
            csq_info.avg_csq = csq_info.avg_csq + pre_csq;
        }
        else 
        {
            csq_info.avg_csq = (csq_info.avg_csq + pre_csq) / 2;
        }
        pre_csq = csq_info.avg_csq;
    }

    return;
}
void quec_avgrssi_Timer_callback(UINT32 argv)
{
    QuecOSStatus ret = QUEC_SUCCESS;
    
    ret = quec_send_msg_to_handle_task(QUEC_AVGRSSI_PROCESS_MSG, NULL, QUEC_AVGRSSI_MSG_LEN_NONE);
    if(ret != QUEC_SUCCESS)
    {
    	atcmd_nw_log("quec avgrssi: avgrssi send msg failed");
    } 

    return;
}

RETURNCODE_T quectel_exec_avgrssi_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32          atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
    char   resBuf[64] = {0};

    atcmd_nw_log("avgrssi: command type=%d,atp_index=%d",op,atp_index);
    memset(resBuf,0,sizeof(resBuf));
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QAVGRSSI: (0,0XFFFFFFFF),(0,31)\r\n");
                break;
            }    
        case TEL_EXT_ACTION_CMD: 
            {
                sprintf(resBuf,"+QAVGRSSI: %d,%d\r\n",csq_info.csq_number,csq_info.avg_csq);
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
                /*clear avg rssi and csq number*/
                csq_info.csq_number = 0;
                csq_info.avg_csq = 0;
                break;
            }
        case TEL_EXT_SET_CMD:
        case TEL_EXT_GET_CMD:
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
    }
    
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}

char  g_qnwscan_band[8] = {0}; /*nw scan band*/
UINT8 qnwscan_cops_flag = 0; /*qnwscan at cmd call cops=? flag*/
#define QUEC_VAILD_MIN_BAND (1)
#define QUEC_VAILD_MAX_BAND (72) /*check band vaild: band max support band 72*/
#define QUEC_LTE_HIGH_BAND (32)
UINT8 quec_get_qnwscan_cops_flag(void)
{
    atcmd_nw_log("qnwscan: qnwscan_cops_flag=%d",qnwscan_cops_flag);
    return qnwscan_cops_flag;
}

void quec_set_qnwscan_cops_flag(UINT8 cops_flag)
{
    qnwscan_cops_flag = cops_flag;
    return;
}

void quec_restore_default_band_nwmode(void)
{
    int ret = CIRC_SUCCESS;
    
    ret = SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "at+qcfg=\"band\",0,0\r\n", 3, NULL, 1, NULL, NULL, 0);
    if (ret != CIRC_SUCCESS)
    {
        atcmd_nw_log("qnwscan: ret = %d,restore default band error",ret);
    }
    ret = SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "at+qcfg=\"nwscanmode\",0\r\n", 3, NULL, 1, NULL, NULL, 0);
    if (ret != CIRC_SUCCESS)
    {
        atcmd_nw_log("qnwscan: ret = %d,restore auto mode error",ret);
    }
    return;
}

RETURNCODE_T quectel_exec_qnwscan_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32          atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    *xid_p = atHandle;
    UINT32 atp_index = GET_ATP_INDEX(atHandle);
    char   resBuf[64] = {0};
    char   scan_band[8] = {0};
    char   res_buf[64] = {0};
    UINT8  param_num = 0;
    INT16  scan_band_len = 0;
    int    tmp_val = 0;

    atcmd_nw_log("qnwscan: command type=%d,atp_index=%d",op,atp_index);
    memset(resBuf,0,sizeof(resBuf));
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
        {
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QNWSCAN: <scan_band>\r\n");
            break;
        }
        case TEL_EXT_SET_CMD:
        {
            param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
			if (1 == param_num)
            {
                if(getExtString(parameter_values_p, 0, scan_band, sizeof(scan_band), &scan_band_len, NULL) == TRUE)
                {
                    if (0 == strcasecmp(scan_band, "GSM"))
                    {
                        memcpy(g_qnwscan_band,scan_band,sizeof(scan_band));
                        quec_set_qnwscan_cops_flag(1);
                        SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "at+qcfg=\"nwscanmode\",1\r\n", 3, NULL, 1, NULL, NULL, 0);
                        SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "at+qcfg=\"band\",0,0\r\n", 3, NULL, 1, NULL, NULL, 0);
                        ret = MM_QuerySuppOperator(atHandle);
                        break;
                    }
                    /* example input b3,so need skip the first character: scan_band[1] */
                    if(FALSE == str2int32(&scan_band[1], 4, &tmp_val))
					{
						atcmd_nw_log("qnwscan: tmp_val=%s",scan_band);
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
						break;
					}
                    memcpy(g_qnwscan_band,scan_band,sizeof(scan_band));
                    atcmd_nw_log("qnwscan: tmp_val=%d",tmp_val);
                    if ((tmp_val <= QUEC_VAILD_MAX_BAND) && (tmp_val >= QUEC_VAILD_MIN_BAND))
                    {
                        memset(res_buf,0,sizeof(res_buf));
                        SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, "at+qcfg=\"nwscanmode\",3\r\n", 3, NULL, 1, NULL, NULL, 0);
                        /*LT customer not support lte extend band,so don't check*/
                        if (tmp_val > QUEC_LTE_HIGH_BAND)
                        {
                            sprintf(res_buf,"at+qcfg=\"band\",0,%x%08x\r\n",1 << (tmp_val-1-QUEC_LTE_HIGH_BAND),0);
                        }
                        else 
                        {
                            sprintf(res_buf,"at+qcfg=\"band\",0,%x\r\n",1 << (tmp_val-1));
                        }
                        SendATCMDWaitResp(TEL_AT_CMD_ATP_QUEC_INTERNAL, res_buf, 3, NULL, 1, NULL, NULL, 0);
                        quec_set_qnwscan_cops_flag(1);
                        ret = MM_QuerySuppOperator(atHandle);
                    }
                    else 
                    {
                        atcmd_nw_log("qnwscan: err,tmp_val=%d",tmp_val);
                        ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
                    }
                }
                else 
                {
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
                }
            }
            else if (0 == param_num)
            {
                sprintf(resBuf,(char *)"+QNWSCAN: \"%s\"\r\n",g_qnwscan_band);
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resBuf);
            }
			else 
            {
                atcmd_nw_log("qnwscan: param_num=%d",param_num);
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, 0, NULL);
            }
            break;
        }
        case TEL_EXT_GET_CMD:
        default:
        {
            ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
            break;
        }
    }
    
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}

#endif /*__QUEC_OEM_VER_LT__*/

#ifdef QUEC_CCED_SUPPORT
int quec_cced_mode = -1;
int quec_requested_dump = -1;

RETURNCODE_T quectel_exec_cced_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 	
    *xid_p = atHandle;
    atcmd_nw_log("command type=%d",op);
	int cced_mode;
	int requested_dump;
    switch (op)
    {
        case TEL_EXT_SET_CMD:    
        {   
            if(network_infor_bitmsk !=0 )
            {                   
                atcmd_nw_log("[quec cced] error, other command is executing :network_infor_bitmsk=%d",network_infor_bitmsk);
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
            }
            else if(getExtValue(parameter_values_p, 0, &cced_mode, QUEC_CCED_NO_AUTO_MODE, QUEC_CCED_AUTO_MODE, QUEC_CCED_NO_AUTO_MODE) != TRUE)
            {
            	atcmd_nw_log("[quec cced] invalid parameter");
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}
			else if(getExtValue(parameter_values_p, 1, &requested_dump, QUEC_CCED_REQUESTED_MAIN_CELL, QUEC_CCED_REQUESTED_MAIN_CELL_RSSI, QUEC_CCED_REQUESTED_MAIN_CELL) != TRUE)
            {
            	//Currently QUEC_CCED_REQUESTED_MAIN_CELL_RSSI not supported 
            	if((requested_dump != QUEC_CCED_REQUESTED_MAIN_CELL) && (requested_dump != QUEC_CCED_REQUESTED_NEIGHBOUR_CELL))
            	{
            		atcmd_nw_log("[quec cced] invalid parameter");
                	ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
					break;
            	}
			}

			quec_cced_mode = cced_mode;
			quec_requested_dump = requested_dump;

			if(cced_mode == QUEC_CCED_NO_AUTO_MODE)
			{
				if (requested_dump == QUEC_CCED_REQUESTED_MAIN_CELL) 
				{
					ret = SIM_GetImsi(atHandle);
					BIT_SET(network_infor_bitmsk,QUEC_CCED_S_GET);
					ret = MM_GetSysInfo(atHandle);
				}
				else if(requested_dump == QUEC_CCED_REQUESTED_NEIGHBOUR_CELL)
				{
					BIT_SET(network_infor_bitmsk,QUEC_CCED_NB_GET);
					ret = MM_GetSysInfo(atHandle);
				}
			}
			else 
			{	
				//Currently not supported
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
				break;
			}				
			break;
        }
		case TEL_EXT_TEST_CMD:
        {
        	   
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+CCED: (0,1),(1,2,8)");
			break;
        }
        case TEL_EXT_ACTION_CMD: 
		case TEL_EXT_GET_CMD:
        default:
            {
                ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);
}
#endif

#ifdef QUEC_QNWCFG_SUPPORT
UINT8 qnwcfg_enable=0;

RETURNCODE_T quec_exec_qnwcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
 	
    *xid_p = atHandle;
	char  qnwcfg_cmd_str[40] = {0};
	INT16 qnwcfg_cmd_str_len=0;
	char res_buf[50]={0};
	UINT8 param_num=0;
	int qnwcfg_cmd_enable=0;
    switch (op)
    {
    
        case TEL_EXT_SET_CMD:    
            {   
            	param_num=quec_get_at_param_num(parameter_values_p,num_parameters);
            	if(network_infor_bitmsk !=0 )
                {
                   
                	atcmd_nw_log("error other commadn is executing :network_infor_bitmsk=%d",network_infor_bitmsk);
                    ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_ALLOWED, NULL);
					break;
                }
				else if(param_num==1 && (getExtString(parameter_values_p, 0, qnwcfg_cmd_str, sizeof(qnwcfg_cmd_str), &qnwcfg_cmd_str_len, NULL) == TRUE))
				{
					if(strcasecmp((char *)qnwcfg_cmd_str, "lte_csi_ext") == 0)
					{
						if(qnwcfg_enable==1)
						{
							BIT_SET(network_infor_bitmsk,QCQI_MCS_GET);
							ret = MM_GetSysInfo(atHandle);
							break;
						}
						else
						{
							sprintf( res_buf,"+QNWCFG: \"lte_csi_ext\",%d\r\n",qnwcfg_enable);
							ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, res_buf);
							break;
						}
					}
					else
					{
                		ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
						break;
					}
				}
                else if(param_num==2 &&(getExtString(parameter_values_p, 0, qnwcfg_cmd_str, sizeof(qnwcfg_cmd_str), &qnwcfg_cmd_str_len, NULL) == TRUE)
					&& (getExtValue(parameter_values_p, 1, &qnwcfg_cmd_enable, 0,1, 0) == TRUE))
                {
					if(strcasecmp((char *)qnwcfg_cmd_str, "lte_csi_ext") == 0)
					{
						if(qnwcfg_enable!=qnwcfg_cmd_enable)
						{
							quectel_nv_fat_write(QUEC_EFS_QNWCFG_EN_CFG, &qnwcfg_cmd_enable, sizeof(UINT8));
							qnwcfg_enable=qnwcfg_cmd_enable;
						}
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
						break;
					}
					else
					{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
						break;
					}
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
					break;
				}
        	}
        case TEL_EXT_TEST_CMD:
        	{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QNWCFG: \"lte_csi_ext\"\r\n");
				break;
        	}
        case TEL_EXT_ACTION_CMD:
        case TEL_EXT_GET_CMD:    
        default:
            {
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
                break;
            }
 
    }
     
    /* handle the return value */
    rc = HANDLE_RETURN_VALUE(ret); 
    return(rc);

	
}
#endif

#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
UINT8 netreject_mode=0;

RETURNCODE_T quec_exec_qnetworkstatus_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
)
{
	CiReturnCode	 ret	  = CIRC_FAIL;
	RETURNCODE_T     rc       = INITIAL_RETURN_CODE;
	int 			 mode;
    CHAR             resp_buffer[32] = {0};
    UINT16           resp_len = 0;
	UINT32			 atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);

	*xid_p = atHandle;

	atcmd_nw_log("enter quec_exec_qnetworkstatus_cmd");
	switch (op)
	{
		case TEL_EXT_TEST_CMD:	 
		{			
			sprintf(resp_buffer, "+QNETWORKSTATUS: (0,1)");
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resp_buffer);
			break;
		}
		case TEL_EXT_GET_CMD:	 
		{			
			sprintf(resp_buffer, "+QNETWORKSTATUS: %d",netreject_mode);
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, resp_buffer);
			break;
		}
		case TEL_EXT_SET_CMD:
		{
			if( getExtValue( parameter_values_p, 0, &mode, 0, 1, 0 ) == TRUE )
			{
				if(mode!=netreject_mode)
				{
					netreject_mode=mode;
					quectel_nv_fat_write(QUEC_EFS_REJECTSTATUS_CFG, &mode, sizeof(UINT8));
				}
				ret= ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else 
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
			break;
		}
		default:
		{
			ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, 0, NULL);
			break;
		}
	}

    rc = HANDLE_RETURN_VALUE(ret);
    return rc;
}
#endif

static BOOL quec_nwlock_nv_params_check_is_same(quec_nwlock_p p_nwlock_set)
{
	quec_nwlock_p p_nwlock = NULL;
	p_nwlock = &g_quec_nwlock;
	
	if(p_nwlock_set == NULL){
		return FALSE;
	}
	
	if(0 == memcmp(p_nwlock, p_nwlock_set, sizeof(quec_nwlock_s))){
		CPUartLogPrintf("%s Yes.", __func__);
		return TRUE;
	}else{
		return FALSE;
	}
}

static int quec_nwlock_nv_save_params(quec_nwlock_p p_nwlock_set)
{
	quec_nwlock_p p_nwlock = NULL;
	p_nwlock = &g_quec_nwlock;

	if(p_nwlock_set == NULL){
		return kGeneralErr;
	}
	
	memcpy(p_nwlock, p_nwlock_set, sizeof(quec_nwlock_s));
	if(QUEC_FAT_SUCCESS != quectel_nv_fat_write(QUEC_NWLOCK_PARAMS_NVM, p_nwlock, sizeof(quec_nwlock_s)))
	{
		CPUartLogPrintf("%s, nv write failed!", __func__);
		return kGeneralErr;
	}
	return QUEC_SUCCESS;
}

void quec_nwlock_nv_read_params_init(void)
{
	quec_nwlock_p p_nwlock = NULL;
	p_nwlock = &g_quec_nwlock;
	if(QUEC_FAT_SUCCESS != quectel_nv_fat_read(QUEC_NWLOCK_PARAMS_NVM, p_nwlock, sizeof(quec_nwlock_s)))
	{
		CPUartLogPrintf("%s, nv read failed!", __func__);
	}
		
}

RETURNCODE_T quectel_exec_qnwlock_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
)
{

    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    *xid_p = atHandle;
    char  at_cmd_str[100] = {0};
    int at_cmd_str_len=0;
    UINT8 cmd_index = 0;     
    char res_buf[100]={0};
	UINT32 index  = *(TelAtParserID *)arg_p;
    atcmd_nw_log("command type=%d",op);
    atcmd_nw_log("atHandle=%d, index=%d",atHandle,*(TelAtParserID*)arg_p);   
	switch (op)
	{
		case TEL_EXT_SET_CMD:	  /* AT+QNWLOCK=...  */
		 {
			 if((getExtString(parameter_values_p, 0, at_cmd_str, 40, (INT16 *)&at_cmd_str_len, NULL) == TRUE))
			 {
				 atcmd_nw_log("qnwlock_cmd_str=%s", at_cmd_str);
				 for(cmd_index = 0; cmd_index < quectel_qnwlock_cmd_tbl_size; cmd_index++)
				 {
					 if(strcasecmp(at_cmd_str, quectel_qnwlock_cmd_tbl[cmd_index].name) == 0)
					 {
						 if(quectel_qnwlock_cmd_tbl[cmd_index].proc_func != NULL)
						 return quectel_qnwlock_cmd_tbl[cmd_index].proc_func(op, command_name_p, parameter_values_p, num_parameters,info_text_p,xid_p,arg_p);
					 }
				 }
			 }
			 ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);

			 break;
		 }
		case TEL_EXT_TEST_CMD:    /* AT+QNWLOCK=? */
		{
			quec_siolib_transmit_to_atp(*(TelAtParserID*)arg_p, "\r\n", 2, NULL);							
						
			strcpy(res_buf, "+QNWLOCK: \"lte\"[,(0-2)[,<freq>,[<pci>]]]\r\n");
			ret=quec_siolib_transmit_to_atp((TelAtParserID)index,(uint8 *)res_buf,strlen(res_buf), NULL);
			
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			atcmd_nw_log(" ret=%d",ret);
			break;
		}
		case TEL_EXT_ACTION_CMD:	 /* AT+QNWLOCK  */
		case TEL_EXT_GET_CMD:	  /* AT+QNWLOCK?  */
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			break;
		}
	}
	
	/* handle the return value */
	
	 rc = HANDLE_RETURN_VALUE(ret);
	 return(rc);
}

RETURNCODE_T quectel_exec_qnwlock_lte_cmd
(     
	 const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
)
{
	RETURNCODE_T	rc		 = INITIAL_RETURN_CODE;
	CiReturnCode	ret 	 = CIRC_FAIL;
	UINT32			atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
	*xid_p = atHandle;
	
	BOOL  cmdValid		= FALSE;
	UINT8 param_num 	= 0;
	char* pstr			= NULL; 
	char  str_param[64] = {0}; 
	UINT8 str_len		= 0;
	UINT32 index  = *(TelAtParserID *)arg_p;
	int mode_input   = 0; /* 0 unlock all  1 unlock cell  2 unlock freq */
	int act    = 3; /* force LTE <act> 0 GSM  1 UMTS_TD  2 UMTS_WB	3 LTE */
	int band   = 0;
	int freq_input   = 0;
	int cellId_input = 0;
	quec_nwlock_p p_quec_nwlock = NULL;
	quec_nwlock_s nwlock = {0};
	atcmd_nw_log("command type=%d",op);
	char res_buf[100]={0};
	param_num = quec_get_at_param_num(parameter_values_p, num_parameters);
	switch (op)
	{		
		case TEL_EXT_SET_CMD:
		{			
			/* return query info */
			if(param_num == 1) 
			{
				p_quec_nwlock = &g_quec_nwlock;
				if(p_quec_nwlock->mode==0)
				{
					sprintf(str_param,"+QNWLOCK: \"lte\",%d", p_quec_nwlock->mode);
				}
				else
				{
					if(p_quec_nwlock->cellId==0)
					{
						sprintf(str_param,"+QNWLOCK: \"lte\",2,%d",p_quec_nwlock->freq);
					}
					else
					{
						sprintf(str_param,"+QNWLOCK: \"lte\",1,%d,%d",p_quec_nwlock->freq, p_quec_nwlock->cellId);
					}
				}
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, str_param);
			}
			else if((param_num >= 2) && (param_num <= 4))/* change lock mode */ 
			{
				/* check params */
				if ( getExtValue(parameter_values_p, 1, &mode_input, TEL_AT_CELLLOCK_MODE_MIN, TEL_AT_CELLLOCK_MODE_MAX, TEL_AT_CELLLOCK_MODE_DEFAULT) == TRUE )
				{
					if ( getExtValue(parameter_values_p, 2, &freq_input, TEL_AT_CELLLOCK_FREQ_MIN, TEL_AT_CELLLOCK_FREQ_MAX, TEL_AT_CELLLOCK_FREQ_DEFAULT) == TRUE )
					{
						if ( getExtValue(parameter_values_p, 3, &cellId_input, TEL_AT_CELLLOCK_CELLID_MIN, TEL_AT_CELLLOCK_CELLID_MAX, TEL_AT_CELLLOCK_CELLID_DEFAULT) == TRUE )
						{
							{
								if(mode_input == 0){
									nwlock.mode   = CIMM_CELL_LOCK_MODE_NONE; // unlock 
									nwlock.act    = 0; // clear all
									nwlock.band   = 0;
									nwlock.freq   = 0;
									nwlock.cellId = 0;
									if(freq_input!=0|| cellId_input!=0) // unlock mode no need input freq and cellId
									{
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
										break;
									}
								}
								else if(mode_input==1)//cell lock
								{
									if(freq_input==0||cellId_input==0) // cell lock mode need input freq and cellId
									{
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
										break;
									}
									nwlock.mode   = CIMM_CELL_LOCK_MODE_LOCKCELL; // set cell lock enable
								}
								else //mode==2 freq lock
								{									
									if(freq_input==0|| cellId_input!=0) // freq lock mode need input freq ,not need input cellId
									{
										ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
										break;
									}
									nwlock.mode   = CIMM_CELL_LOCK_MODE_LOCKFREQ; // set freq lock enable
								}
								
								nwlock.act	  = act;
								nwlock.band   = band;
								nwlock.freq   = freq_input;
								nwlock.cellId = cellId_input;
								cmdValid	  = TRUE;
							}
						}
					}	
				}

				/* set cell lock request */
				CPUartLogPrintf("qnwlock lte cmd input params,mode:%d act:%d band:%d freq:%d cellid:%d",mode_input,act,band,freq_input,cellId_input);
				if (cmdValid == TRUE) {
					//is not the same compare with params which is last set,so updata cell lock.
					if(!quec_nwlock_nv_params_check_is_same(&nwlock)){
						CPUartLogPrintf("MM_SetCellLOCK cmd input params,mode:%d act:%d band:%d freq:%d cellid:%d",nwlock.mode,act,band,nwlock.freq,nwlock.cellId);
						ret = MM_SetCellLOCK(atHandle,nwlock.mode,act, band,nwlock.freq, nwlock.cellId);
						if(ret == utlSUCCESS){
							/* save params to nv */
							quec_nwlock_nv_save_params(&nwlock);
						}
					}else{
						ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, NULL, NULL);
					}
				}
				else
				{
					ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
				}
			}
			else
			{
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
			}
	
			break;
		}
		case TEL_EXT_TEST_CMD:			
		case TEL_EXT_GET_CMD: 
		case TEL_EXT_ACTION_CMD:	
		default:
		{
			ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_OPERATION_NOT_SUPPORTED, NULL);
			break;
		}
 
	}
	 
	/* handle the return value */
	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}

#ifdef QUEC_OPER_OOS_PHASE_PERIOD
/*===========================================================================

FUNCTION QUEC_EXEC_QGPAPN 

DESCRIPTION
  This function set oos phase period

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

#define QUEC_OOS_PHASE_PERIOD_MIN_1 0
#define QUEC_OOS_PHASE_PERIOD_MIN_2_3 1
#define QUEC_OOS_PHASE_PERIOD_MAX 255
#define QUEC_OOS_PHASE_PERIOD_DEFALUT 5

RETURNCODE_T quectel_exec_qoospp_cmd

(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
)
{
  
    RETURNCODE_T    rc       = INITIAL_RETURN_CODE;
    CiReturnCode    ret      = CIRC_FAIL;
    UINT32           atHandle = MAKE_AT_HANDLE(*(TelAtParserID*)arg_p);
    *xid_p = atHandle;
    UINT32 atp_index=GET_ATP_INDEX(atHandle);
	
    atcmd_nw_log("==quecoos==command type=%d,atp_index=%d",op,atp_index);

	UINT8 Oos_PhasePeriod[CI_MM_MAX_OOS_RECOVERY_PHASES] = {0};
    switch (op)
    {
        case TEL_EXT_TEST_CMD:
            {   
                ret = ATRESP( atHandle, ATCI_RESULT_CODE_OK, 0, (char *)"+QOOSPP: (0-255),(1-255),(1-255)\r\n");
                break;
            } 

		case TEL_EXT_SET_CMD:
		case TEL_EXT_ACTION_CMD:	
	
			if((getExtValue( parameter_values_p, 0, Oos_PhasePeriod, QUEC_OOS_PHASE_PERIOD_MIN_1, QUEC_OOS_PHASE_PERIOD_MAX, QUEC_OOS_PHASE_PERIOD_DEFALUT) == TRUE)\
				&&(getExtValue( parameter_values_p, 1, Oos_PhasePeriod+1, QUEC_OOS_PHASE_PERIOD_MIN_2_3, QUEC_OOS_PHASE_PERIOD_MAX, QUEC_OOS_PHASE_PERIOD_DEFALUT) == TRUE)\
				&&(getExtValue( parameter_values_p, 2, Oos_PhasePeriod+2, QUEC_OOS_PHASE_PERIOD_MIN_2_3, QUEC_OOS_PHASE_PERIOD_MAX, QUEC_OOS_PHASE_PERIOD_DEFALUT) == TRUE))
			{				
				atcmd_nw_log("==quecoos==parameter1:%d, param2:%d, param3:%d", Oos_PhasePeriod[0],Oos_PhasePeriod[1],Oos_PhasePeriod[2]);
				DEV_SetOosPhasePeriod_req(atHandle, Oos_PhasePeriod);

				ret = ATRESP(atHandle, ATCI_RESULT_CODE_OK, 0, NULL);
			}
			else 
				ret = ATRESP( atHandle, ATCI_RESULT_CODE_CME_ERROR, CME_INVALID_PARAM, NULL);
							
			break;

		case TEL_EXT_GET_CMD:
			ret = DEV_GetOosPhasePeriod_req(atHandle, NULL);
			if(ret)
			{
				ret = ATRESP(atHandle, ATCI_RESULT_CODE_ERROR, CME_SIM_WRONG, NULL);
			}
			break;
    }

	rc = HANDLE_RETURN_VALUE(ret); 
	return(rc);
}				
#endif 


#endif  /*QUECTEL_NETWORK_SUPPORT*/

#endif /*MIN_SYS*/

