/**  @file
  quec_atcmd_general.h

  @brief
  This file is used to define the general at command handler for different Quectel Project.

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
03/28/2019		  Tery	     aad airplanecontrol function
12/03/2018		  Chavis     Add QCFG cmd enumeration
11/27/2018		  Tery	     Delete quec_exec_iccid_cmd function define
10/11/2018        West       Add general at cmds
10/09/2018		  Jensen	 Init version
=================================================================*/


#ifndef QUEC_ATCMD_GENERAL_H
#define QUEC_ATCMD_GENERAL_H

#include "quec_cust_feature.h"
#include "quec_common.h"
#include "quec_atcmd_param.h"
#include "quec_at_common.h"
#ifdef QUEC_NETDUALCH_CFG
#include "quec_msg_process.h"
#endif
#if QUEC_PRODUCTION_CFG_SUPPORT
#include "mvUsbNet.h"
#endif
#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
#include "ci_dev.h"
#endif

//eckard.cao 20220907 at+qpowd value
#define QUEC_AT_QPOWD_CMD_VAL_MIN                   0
#define QUEC_AT_QPOWD_CMD_VAL_MAX                   1
#define QUEC_AT_QPOWD_CMD_VAL_DEFAULT               1

//chaim 2018.10.24 at+qpppdrop value
#define QUEC_AT_QPPPDROP_CMD_VAL_MIN				0
#define QUEC_AT_QPPPDROP_CMD_VAL_MAX				2
#define QUEC_AT_QPPPDROP_CMD_VAL_DEFAULT			1

//chaim 2018.10.24 at&c value
#define QUEC_AT_H_CMD_VAL_MIN						0
#define QUEC_AT_H_CMD_VAL_MAX						5
#define QUEC_AT_H_CMD_VAL_DEFAULT					0

//chaim 2018.10.24 at&c value
#define QUEC_AT_C_CMD_VAL_MIN						0
#define QUEC_AT_C_CMD_VAL_MAX						1
#define QUEC_AT_C_CMD_VAL_DEFAULT					1

//chaim 2018.10.24 at&d value
#define QUEC_AT_D_CMD_VAL_MIN						0
#define QUEC_AT_D_CMD_VAL_MAX						2
#define QUEC_AT_D_CMD_VAL_DEFAULT					1


//chaim 2018.11.12 IPR value
#define QUEC_IPR_CMD_VAL_MIN        0

#ifdef QUECTEL_AT_QCFG_SUPPORT

typedef enum {
    QUEC_AUTO  = 0,			/**< AUTO 	*/
    QUEC_GSM ,    			/**< GSM 	*/
    QUEC_WCDMA, 	    	/**< WCDMA 	*/
    QUEC_LTE,				/**< LTE 	*/
    QUEC_UMTS=5        		/**< UMTS 	*/   //connor 2018/11/19 add UMTS support
}   QUEC_NWSCANMODE;

typedef enum {
    QUEC_SEQ_AUTO  = QUEC_AUTO,
    QUEC_SEQ_G     =QUEC_GSM ,
    QUEC_SEQ_W     =QUEC_WCDMA,
    QUEC_SEQ_L     =QUEC_LTE,
    QUEC_SEQ_G_W_L,
    QUEC_SEQ_W_G_L,    //5
    QUEC_SEQ_L_W,
    QUEC_SEQ_L_G,
    QUEC_SEQ_W_L,      //8
    QUEC_SEQ_W_G,
    QUEC_SEQ_G_L,
    QUEC_SEQ_G_W,     //11
    QUEC_SEQ_L_W_G, //lte first
    QUEC_SEQ_MAX

}   QUEC_NWSCANSEQ;


#define   QUEC_BAND_GSM_900        0x01 //B8
#define   QUEC_BAND_GSM_1800        0x02        //B3
#define   QUEC_BAND_GSM_850        0x04         //B5
#define   QUEC_BAND_GSM_1900        0x08        //B2
#define   QUEC_BAND_WCDMA_2100        0x10         //B1
#define   QUEC_BAND_WCDMA_1900        0x20        //B2
#define   QUEC_BAND_WCDMA_850        0x40         //B5
#define   QUEC_BAND_WCDMA_900        0x80        //B8
#define   QUEC_BAND_WCDMA_800        0x100         //B6
#define   QUEC_BAND_WCDMA_1700        0x200        //B4
#define   QUEC_BAND_LTE_BAND1        0x01         
#define   QUEC_BAND_LTE_BAND2        0x02        
#define   QUEC_BAND_LTE_BAND3        0x04         
#define   QUEC_BAND_LTE_BAND4        0x08        
#define   QUEC_BAND_LTE_BAND5        0x10         
#define   QUEC_BAND_LTE_BAND7        0x40        
#define   QUEC_BAND_LTE_BAND8        0x80        
#define   QUEC_BAND_LTE_BAND17        0x10000          
#define   QUEC_BAND_LTE_BAND20        0x80000         
#define   QUEC_BAND_LTE_BAND28        0x8000000         	//add band 28
#define   QUEC_BAND_LTE_BAND31        0x40000000         	//add band 31
#define   QUEC_BAND_LTE_BAND33        0x100000000           //add band 33
#define   QUEC_BAND_LTE_BAND34        0x200000000           //add band 34
#define   QUEC_BAND_LTE_BAND38        0x2000000000          
#define   QUEC_BAND_LTE_BAND39        0x4000000000         
#define   QUEC_BAND_LTE_BAND40        0x8000000000          
#define   QUEC_BAND_LTE_BAND41        0x10000000000        
#define   QUEC_BAND_LTE_BAND65        0x1        
#define   QUEC_BAND_LTE_BAND66        0x2        
#define   QUEC_BAND_LTE_BAND72        0x80        




#define    ASR_BAND_PGSM_900        0x01         
#define    ASR_BAND_GSM_1800        0x02        
#define    ASR_BAND_GSM_1900        0x04         
#define    ASR_BAND_EGSM_900        0x08        
#define    ASR_BAND_GSM_450        0x10         
#define    ASR_BAND_GSM_480        0x20        
#define    ASR_BAND_GSM_850        0x40         
#define    ASR_BAND_GSM_LOOK_BIT        0x200        
#define    ASR_BAND_UMTS_BAND1        0x01         
#define    ASR_BAND_UMTS_BAND2        0x02         
#define    ASR_BAND_UMTS_BAND3        0x04         
#define    ASR_BAND_UMTS_BAND4        0x08         
#define    ASR_BAND_UMTS_BAND5        0x10         
#define    ASR_BAND_UMTS_BAND6        0x20         
#define    ASR_BAND_UMTS_BAND7        0x40         
#define    ASR_BAND_UMTS_BAND8        0x80         
#define    ASR_BAND_UMTS_BAND9        0x100         
#define    ASR_BAND_LTE_BAND1        0x01         
#define    ASR_BAND_LTE_BAND3        0x04         
#define    ASR_BAND_LTE_BAND4        0x08         
#define    ASR_BAND_LTE_BAND5        0x10         
#define    ASR_BAND_LTE_BAND7        0x40         
#define    ASR_BAND_LTE_BAND8        0x80         
#define    ASR_BAND_LTE_BAND17        0x10000         
#define    ASR_BAND_LTE_BAND20        0x80000         
#define    ASR_BAND_LTE_BAND28        0x8000000         //add band 28
#define    ASR_BAND_LTE_BAND31        0x40000000         //add band 31
#define    ASR_BAND_LTE_BAND33        0x01         // add asr band 33
#define    ASR_BAND_LTE_BAND34        0x02         // add asr band 34
#define    ASR_BAND_LTE_BAND38        0x20         
#define    ASR_BAND_LTE_BAND39        0x40         
#define    ASR_BAND_LTE_BAND40        0x80         
#define    ASR_BAND_LTE_BAND41        0x100        
#define    ASR_BAND_LTE_BAND65        0x1        
#define    ASR_BAND_LTE_BAND66        0x2        
#define    ASR_BAND_LTE_BAND72        0x80        

	
typedef enum {
	QCFG_GPRSATTACH_GET=0,
	QCFG_GPRSATTACH_SET,
	QCFG_SERVICEDOMIAN_GET,
	QCFG_SERVICEDOMIAN_SET,
	QCFG_ROAMSERVICE_GET,
	QCFG_ROAMSERVICE_SET,
	QCFG_NWSCANMODEEX_GET,
	QCFG_NWSCANMODEEX_SET,
	QCFG_NWSCANMODE_GET,
	QCFG_NWSCANMODE_SET,
	QCFG_NWSCANSEQ_GET,
	QCFG_NWSCANSEQ_SET,
	QCFG_BAND_GET,
	QCFG_BAND_SET,
	COPS_AUTO,
	COPS_MANUAL,
	} Qcfg_Cmd_Type;

typedef struct
{
	 char *name;
	 RETURNCODE_T (*proc_func)(
                                   const utlAtParameterOp_T        op,                 /* AT cmd type          */
                                   const char                     *command_name_p,     /* AT cmd name          */
                                   const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
                                   const size_t                    num_parameters,     /* AT cmd number        */
                                   const char                     *info_text_p,        /* AT cmd usage string  */
                                   unsigned int                   *xid_p,              /* AT cmd handle        */
                                   void                           *arg_p
                             );
}quectel_common_cfg_cmd_type;


 typedef enum {
	 QUE_MODE_BIT_GSM	= 0x0004,		 
	 QUE_MODE_BIT_UMTS  = 0x0008, 			
	 QUE_MODE_BIT_LTE   = 0x0010,
#if QUEC_LTE_SUPPORT
	 QUE_MODE_BIT_ALL   = (QUE_MODE_BIT_GSM | QUE_MODE_BIT_UMTS | QUE_MODE_BIT_LTE),
 #else
	 QUE_MODE_BIT_ALL   = (QUE_MODE_BIT_GSM | QUE_MODE_BIT_UMTS),
 #endif
 }	 QUEC_MODE_BIT_MASK;


 typedef struct
{
    UINT8               asr_mode;
    QUEC_MODE_BIT_MASK  quec_mode_bitmask;
}quectel_mode_match;

#if defined (__QUECTEL_PROJECT_EC600MCN_LC__) || defined (__QUECTEL_PROJECT_EC600MCN_CC__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_GC__) || defined (__QUECTEL_PROJECT_EC600MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC600MCN_LF__) || defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_LF__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GA__) || defined (__QUECTEL_PROJECT_EC800MCN_GC__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GA__) || defined (__QUECTEL_PROJECT_EC200MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC200MCN_LC__) || defined (__QUECTEL_PROJECT_EC200MCN_GB__) \
	|| defined (__QUECTEL_PROJECT_EC100MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_CC__)\
	|| defined (__QUECTEL_PROJECT_EC800MCN_GD__) || defined (__QUECTEL_PROJECT_EG810MCN_LA__) \
	|| defined (__QUECTEL_PROJECT_EC600KCN_CC__) || defined (__QUECTEL_PROJECT_EC200MCN_LE__)\
	|| defined (__QUECTEL_PROJECT_EC200MCN_LF__) || defined (__QUECTEL_PROJECT_EC800KCN_CC__)\
	|| defined (__QUECTEL_PROJECT_EG800KCN_GC__) || defined (__QUECTEL_PROJECT_EC800KCN_CZ__) \
	|| defined (__QUECTEL_PROJECT_EC800MCN_GB__) || defined (__QUECTEL_PROJECT_EC800KCN_LC__)\
	|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EC600KCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EG800PCN_00LA__)|| defined (__QUECTEL_PROJECT_EG810MCN_LC__) \
	|| defined (__QUECTEL_PROJECT_EC600KCN_CK__) || defined (__QUECTEL_PROJECT_EC600KCN_LK__)\
	|| defined (__QUECTEL_PROJECT_EC800KCN_CK__) || defined (__QUECTEL_PROJECT_EC800KCN_LK__)


	
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND1|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND8)  //band 1 3 5 8
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 38 39 40 41

#elif defined  (__QUECTEL_PROJECT_EC600MCN_MC__)
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND8)  //band 3  8
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 38 39 40 41

#elif defined (__QUECTEL_PROJECT_EC800MCN_GM__)  || defined (__QUECTEL_PROJECT_EC800MCN_NC__) || defined (__QUECTEL_PROJECT_EC600MCN_NC__)
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 38 39 40 41

#elif defined (__QUECTEL_PROJECT_EC800MCN_MC__)
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND8)  //band 3  8
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 39 40 41

#elif defined (__QUECTEL_PROJECT_EC600NCN_AC__)
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND1|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND8)  //band 1 3 5 8
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 38 39 40 41
#define QUEC_GSM_BAND_VALUE  (QUEC_BAND_GSM_900|QUEC_BAND_GSM_1800)  //band 3 8

#elif defined (__QUECTEL_PROJECT_EG800KEU_CC__) || defined (__QUECTEL_PROJECT_EG810MEU_LA__) || defined (__QUECTEL_PROJECT_EG810MEU_LC__) || defined (__QUECTEL_PROJECT_EG800KEU_LC__) 
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND1|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND7|QUEC_BAND_LTE_BAND8|QUEC_BAND_LTE_BAND20|QUEC_BAND_LTE_BAND28)  //band 1 3 5 7 8 20 28

#elif defined (__QUECTEL_PROJECT_EC600MEU_LA__)
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND1|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND7|QUEC_BAND_LTE_BAND8|QUEC_BAND_LTE_BAND20|QUEC_BAND_LTE_BAND28)  //band 1 3 5 7 8 20 28
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 38 40 41

#elif defined (__QUECTEL_PROJECT_EC800KCN_MC__) || defined (__QUECTEL_PROJECT_EC600KCN_MC__) || defined (__QUECTEL_PROJECT_EC800KCN_MD__)
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND8)  //band 3 8
#define QUEC_LTE_BAND_TDD_VALUE  (QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41)  //band 34 39 40 41

#elif defined (__QUECTEL_PROJECT_EG810MLA_LC__) || defined (__QUECTEL_PROJECT_EG800KLA_CC__) || defined (__QUECTEL_PROJECT_EC600MLA_LA__) || defined (__QUECTEL_PROJECT_EG800KLA_LC__) 
#define QUEC_LTE_BAND_FDD_VALUE  (QUEC_BAND_LTE_BAND2|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND4|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND7|QUEC_BAND_LTE_BAND8|QUEC_BAND_LTE_BAND28) //band 2 3 4 5 7 8 28
#define QUEC_LTE_BAND_VALUE_EXT  (QUEC_BAND_LTE_BAND66)  //band 66


#else
	#error "Please configure the project"
#endif


#define QCFG_IPRECOVERY_DEFAULT 0 //we set to disable as defalut
#define QCFG_LTEDFTCID_DEFAULT 1 //CID=1
#if QUEC_DUAL_SIM_SUPPORT
#define QCFG_SIM2_LTEDFTCID_DEFAULT 5
#endif


#define QUEC_AT_IPRECOVERY "quec_at_recovery.value"
#define QUEC_AT_LTEDFTCID "quec_at_ltedftcid.value"

#ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT
#define QUEC_AUTO_UPDATE_EARFCN_LEN_DEFAULT   3600  //uint s  connor.wu 2019/3/12 set the default len to 1 hour 
#define QUEC_AUTO_UPDATE_EARFCN_LEN_MIN   60
#define QUEC_AUTO_UPDATE_EARFCN_LEN_MAX   4147200  //48 days
#define QUEC_AT_AUTO_UPDATE_EARFCN "quec_at_auto_update_earfcn.value"
#endif
#endif

#ifdef QUECTEL_AT_QINDCFG_SUPPORT
typedef enum
{
    QUECTEL_URC_ALL_IND = 0,  //use to contol all urc report set true as default
    QUECTEL_URC_CSQ_IND,
    QUECTEL_URC_DATASTATUS_IND, // use to contol asr unique DATASTATUS urc report
    QUECTEL_URC_MODE_IND, // use to contol asr unique MODE urc report
    QUECTEL_URC_SMS_FULL,// use to contol asr unique msg full urc report
    QUECTEL_URC_SMS_INCOMING,// use to contol asr unique new msg incoming urc report
    //add new here
    QUECTEL_URC_ACTCHGRPT_IND, //use to contol network mode change urc report
    QUECTEL_URC_SERVICE,
    QUECTEL_URC_CALL,
    QUECTEL_URC_MESSAGE,
    QUECTEL_URC_SQ_IND,  //RSRP,RSRQ,SINR URC REPORT
    QUECTEL_URC_PHONEBOOK,
    QUECTEL_URC_RING,
    QUECTEL_URC_NOCARRIER,
    QUECTEL_URC_MAX_IND,
}quectel_urc_ind_cfg_e_type;


#define __QUEC_AT_QINDCFG_VALUE "quec_at_qindcfg.value"

#endif

#ifdef QUEC_GRIP_PARAM_SAVE_SUPPORT
#define QUEC_AT_GPIP_PARAM_VALUE  "quec_at_grip_value"
typedef struct {
    int option;
    int value;
    int networkMode;
	int band;
}quec_grip_param_cfg_s;

#endif

/*Tery 20190328 aad airplanecontrol function*/
#define __QUEC_AT_AIRPLANECONTROL_VALUE  "quec_at_airplanecontrol_value"

#ifdef QUEC_AT_AMPW_V_SUPPORT
typedef enum {
    AT_AMP_C = 0,
    AT_AMP_D,
    AT_AMP_F,
    AT_AMP_W,
    AT_E,
    AT_Q,
    AT_V,
    AT_X,
    AT_Z,
    AT_S_0,
    AT_S_3,
    AT_S_4,
    AT_S_5,
    AT_S_6,
    AT_S_7,
    AT_S_8,
    AT_S_10,
    AT_CREG,
    AT_CEREG,
    AT_CGREG,
    AT_IPR,
    AT_IFC_RTS,
    AT_IFC_CTS,
    AT_CONFIG_MAX_NUM,
}__QUEC_CONFIG_ENUM;

/*attention :
  ATS7(carrier wait time (in seconds)) in 9x07 the value is 0, update it as 0 too*/
  //Chaim 20190801 HAIXIN version uart default 9600
  //Fitz.xu 20210421: Add for FAE-10441
#if defined (__QUEC_OEM_VER_UD96__) || defined (__QUEC_OEM_VER_LT__) || defined(__QUEC_OEM_VER_ALLIED__)

    #define __QUEC_CONFIG_LIST(VALUE) \
        VALUE(AT_AMP_C, "&C", 1) \
        VALUE(AT_AMP_D, "&D", 2) \
        VALUE(AT_AMP_F, "&F", 0) \
        VALUE(AT_AMP_W, "&W", 0) \
        VALUE(AT_E, "E", 1) \
        VALUE(AT_Q, "Q", 0) \
        VALUE(AT_V, "V", 1) \
        VALUE(AT_X, "X", 4) \
        VALUE(AT_Z, "Z", 0) \
        VALUE(AT_S_0, "S0", 0) \
        VALUE(AT_S_3, "S3", 13) \
        VALUE(AT_S_4, "S4", 10) \
        VALUE(AT_S_5, "S5", 8) \
        VALUE(AT_S_6, "S6", 2) \
        VALUE(AT_S_7, "S7", 0) \
        VALUE(AT_S_8, "S8", 2) \
        VALUE(AT_S_10, "S10", 15) \
        VALUE(AT_CREG, "CREG", 0) \
        VALUE(AT_CEREG, "CEREG", 0) \
        VALUE(AT_CGREG, "CGREG", 0)\
        VALUE(AT_IPR, "IPR", 9600)\
        VALUE(AT_IFC_RTS, "IFC_RTS", 0) \
        VALUE(AT_IFC_CTS, "IFC_CTS", 0)
        
#elif defined(__QUEC_OEM_VER_AR__)
#define __QUEC_CONFIG_LIST(VALUE) \
        VALUE(AT_AMP_C, "&C", 1) \
        VALUE(AT_AMP_D, "&D", 2) \
        VALUE(AT_AMP_F, "&F", 0) \
        VALUE(AT_AMP_W, "&W", 0) \
        VALUE(AT_E, "E", 1) \
        VALUE(AT_Q, "Q", 0) \
        VALUE(AT_V, "V", 1) \
        VALUE(AT_X, "X", 4) \
        VALUE(AT_Z, "Z", 0) \
        VALUE(AT_S_0, "S0", 0) \
        VALUE(AT_S_3, "S3", 13) \
        VALUE(AT_S_4, "S4", 10) \
        VALUE(AT_S_5, "S5", 8) \
        VALUE(AT_S_6, "S6", 2) \
        VALUE(AT_S_7, "S7", 0) \
        VALUE(AT_S_8, "S8", 2) \
        VALUE(AT_S_10, "S10", 15) \
        VALUE(AT_CREG, "CREG", 0) \
        VALUE(AT_CEREG, "CEREG", 0) \
        VALUE(AT_CGREG, "CGREG", 0)\
        VALUE(AT_IPR, "IPR", 0)\
        VALUE(AT_IFC_RTS, "IFC_RTS", 0) \
        VALUE(AT_IFC_CTS, "IFC_CTS", 0)
        
#elif defined(QUECTEL_OPEN_CPU)
//OPEN°æ±¾Ä¬ÈÏ¹Ø±ÕATµÄ»ØÏÔ
#define __QUEC_CONFIG_LIST(VALUE) \
		VALUE(AT_AMP_C, "&C", 1) \
		VALUE(AT_AMP_D, "&D", 2) \
		VALUE(AT_AMP_F, "&F", 0) \
		VALUE(AT_AMP_W, "&W", 0) \
		VALUE(AT_E, "E", 0) \
		VALUE(AT_Q, "Q", 0) \
		VALUE(AT_V, "V", 1) \
		VALUE(AT_X, "X", 4) \
		VALUE(AT_Z, "Z", 0) \
		VALUE(AT_S_0, "S0", 0) \
		VALUE(AT_S_3, "S3", 13) \
		VALUE(AT_S_4, "S4", 10) \
		VALUE(AT_S_5, "S5", 8) \
		VALUE(AT_S_6, "S6", 2) \
		VALUE(AT_S_7, "S7", 0) \
		VALUE(AT_S_8, "S8", 2) \
		VALUE(AT_S_10, "S10", 15) \
		VALUE(AT_CREG, "CREG", 0) \
		VALUE(AT_CEREG, "CEREG", 0) \
		VALUE(AT_CGREG, "CGREG", 0)\
		VALUE(AT_IPR, "IPR", 115200)\
		VALUE(AT_IFC_RTS, "IFC_RTS", 0) \
		VALUE(AT_IFC_CTS, "IFC_CTS", 0)

#else
    #define __QUEC_CONFIG_LIST(VALUE) \
        VALUE(AT_AMP_C, "&C", 1) \
        VALUE(AT_AMP_D, "&D", 2) \
        VALUE(AT_AMP_F, "&F", 0) \
        VALUE(AT_AMP_W, "&W", 0) \
        VALUE(AT_E, "E", 1) \
        VALUE(AT_Q, "Q", 0) \
        VALUE(AT_V, "V", 1) \
        VALUE(AT_X, "X", 4) \
        VALUE(AT_Z, "Z", 0) \
        VALUE(AT_S_0, "S0", 0) \
        VALUE(AT_S_3, "S3", 13) \
        VALUE(AT_S_4, "S4", 10) \
        VALUE(AT_S_5, "S5", 8) \
        VALUE(AT_S_6, "S6", 2) \
        VALUE(AT_S_7, "S7", 0) \
        VALUE(AT_S_8, "S8", 2) \
        VALUE(AT_S_10, "S10", 15) \
        VALUE(AT_CREG, "CREG", 0) \
        VALUE(AT_CEREG, "CEREG", 0) \
        VALUE(AT_CGREG, "CGREG", 0)\
        VALUE(AT_IPR, "IPR", 115200)\
        VALUE(AT_IFC_RTS, "IFC_RTS", 0) \
        VALUE(AT_IFC_CTS, "IFC_CTS", 0)
 #endif   

#define __QUEC_CONFIG_VALUE_GET(num, string, value) {num, string, value},
typedef struct {
    unsigned int config_num;
    char  *config_str;
    unsigned int config_value;
}__QUEC_CONFIG_DES;

//system config table name
#define __QUEC_AT_CONFIG_TABLE "quec_system_config.conf"
#endif

typedef struct {
    UINT8 opt_enable;
    UINT8 opt_bit_cfg;
    UINT8 opt_epsnsc_cfg; //6fe4
}quec_sim_write_opt_s;

#define QUEC_NETMASK_BIT_NUM_MIN 8
#define QUEC_NETMASK_STR_LEN 64
typedef struct {
    UINT8 mask_bit_num;//0=disable, enable if >= QUEC_NETMASK_BIT_NUM_MIN
    char mask_str[QUEC_NETMASK_STR_LEN];
}quec_netmask_cfg_s;

#if QUEC_PRODUCTION_CFG_SUPPORT
#ifdef QUEC_ASR_ATCMD_USB_NET_MAC_SUPPORT
#include "quec_production_cfg.h"
/* USBNET MAC\MASK */
typedef struct
{
	ST_quecComInfo quecComInfo;
	mvUsbMacAddr macAddr; /* AT+QCFG="usbnetmac"*/
	quec_netmask_cfg_s netMask;
	
	UINT32 reserved[20];
}ST_quecCfgUsbNetParams;
#endif
#endif


#ifdef QUEC_AT_CIND_SUPPORT

typedef enum 
{
	QUEC_CIND_CALL_IND,
	QUEC_CIND_ROAM_IND,
	QUEC_CIND_SIGNAL_IND,
	QUEC_CIND_SERVICE_IND,
	QUEC_CIND_GPRS_COVERAGE_IND,
	QUEC_CIND_MESSAGE_IND,
	QUEC_CIND_MAX_IND,
}quec_cind_descr_index_e;

typedef enum 
{
	QUEC_CIND_IND_VALUE_0,
	QUEC_CIND_IND_VALUE_1,
	QUEC_CIND_IND_VALUE_2,
	QUEC_CIND_IND_VALUE_3,
	QUEC_CIND_IND_VALUE_4,
	QUEC_CIND_IND_VALUE_5,
}quec_cind_ind_value_e;
	

typedef struct
{
	quec_cind_descr_index_e cind_descr_index;
	uint8 value;
}quec_at_cind_s;

extern quec_at_cind_s quec_at_cind[QUEC_CIND_MAX_IND];
extern void quec_cind_set_ind_value(quec_cind_descr_index_e index,quec_cind_ind_value_e value);
#endif

#ifdef QUEC_URC_RI_DCD_SUPPORT
typedef enum{
       QUEC_URC_RI_DEFAULT=0,
       QUEC_URC_RI_DCD,
       QUEC_URC_RI_WAKEUP,
}quec_urc_ri_pin_e;
extern quec_urc_ri_pin_e GlobalRiPin_Flag;
#endif


/*ford.zhang-2020/07/28: fixed wifiscan pend 3m while having data transmission*/
#ifdef QUEC_USB_QWIFISCAN_SUPPORT   
void quec_local_release_enable_tau(void);
void quec_local_release_without_tau(UINT32 atHandle);
void quec_immediate_release_rrc(UINT32 atHandle);
#endif
/*ford.zhang-2020/07/28: end fixed wifiscan pend 3m while having data transmission*/
//isaac 20200225: add at+qcellselectcfg
#ifdef QUECTEL_CELL_SELECT_CFG

typedef enum 
{
	CELL_SELECT_ENUM_NONE = -1,
	SCELL_OFFSET = 0,
	SCELL_QUAL_OFFSET,
	NCELL_LTE_OFFSET,
	NCELL_LTE_QUAL_OFFSET,
	NCELL_UMTS_OFFSET,
	NCELL_UMTS_QUAL_OFFSET,
	NCELL_GSM_OFFSET,
	CELL_SELECT_ENUM_MAX
}quec_cell_select_cfg_e_t;


typedef struct 
{
	quec_cell_select_cfg_e_t CellSelectcfgEnum;
	const char 	cmd_str[32];
	INT8 		val;
	const INT8 	minval;
	const INT8 	maxval;
}quec_cell_select_cfg_s_t;

RETURNCODE_T  quec_exec_cell_select_cfg_cmd
(
    const utlAtParameterOp_T      op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p
);
#endif

#ifdef QUEC_USB_REMOTEWAKEUP_SUPPORT

#define QUEC_DTR_WAKEUP_MODE 1
#define QUEC_RECEIVE_DATA_WAKEUP_MODE 2
#define QUEC_RETURN_DATA_WAKEUP_MODE 3
#define QUEC_QREMOTEWAKE_VALUE_MIN 0
#define QUEC_QREMOTEWAKE_VALUE_MAX 3
#define QUEC_QREMOTEWAKE_VALUE_DEFAULT 0
#define QUEC_QREMOTEWAKE_MODEM_MIN 0
#define QUEC_QREMOTEWAKE_MODEM_MAX 3
#define QUEC_QREMOTEWAKE_MODEM_DEFAULT 0
#define QUEC_QREMOTEWAKE_NV_MIN 0
#define QUEC_QREMOTEWAKE_NV_MAX 1
#define QUEC_QREMOTEWAKE_NV_DEFAULT 0
#define QUEC_QREMOTEWAKE_NETBIT 4

#define QUEC_RECEIVE_DATA_WAKEUP_SHIFT   4
#endif


#ifdef QUECTEL_AT_QCFG_SUPPORT
extern UINT64 qcfg_cmd_type_bitmask;
extern UINT8 qcfg_gprsattach;
extern UINT8 qcfg_service_domain;
extern UINT8  qcfg_roamservice;
extern UINT8 qcfg_nwscanmode;
extern UINT8 qcfg_nwscanmodeex_prefmode;
extern UINT8 qcfg_nwscanseq;
extern UINT64 qcfg_band[3];
extern UINT8 qcfg_iprecovery;
extern UINT8  qcfg_ltedftcid;
#if QUEC_DUAL_SIM_SUPPORT
extern UINT8 qcfg_ltedftcid_1;
#endif
extern quec_netmask_cfg_s quec_netmaskset_cfg;
extern UINT8 quec_creg_report_emergency;

extern UINT64 quec_get_gsm_band(void);
extern UINT64 quec_get_wcdma_band(void);
extern UINT64 quec_get_lte_band(void);
extern UINT64 quec_get_lte_band_ext(void);
extern UINT16 quec_asrmode2_nwscanmodeex (UINT8 asr_mode);
extern UINT8 quec_nwscanmodeex2_asrmode(UINT16 nwscanmodeex);
#ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT
extern void quec_update_earfcn_list(UINT8 is_lte);
#endif
#endif

#ifdef QUECTEL_AT_QINDCFG_SUPPORT
extern UINT8 quectel_read_urc_ind_flag ( quectel_urc_ind_cfg_e_type flag );
#endif

#ifdef QUEC_AT_AMPW_V_SUPPORT

//convert Sx to num
extern int quectel_convert_s_val_to_num(__QUEC_CONFIG_ENUM s);

//convert num to Sx
extern __QUEC_CONFIG_ENUM quectel_convert_num_to_s_val(int num);

//set current value
extern int quectel_current_config_value_set(int config_num, int config_value);
//get current value
extern int quectel_current_config_value_get(int config_num, int *config_value);
//set default/factory config
extern void quectel_config_value_set(__QUEC_CONFIG_DES *quec_config_des ,int config_num, int config_value);
//get default/factory config
extern void quectel_config_value_get(__QUEC_CONFIG_DES *quec_config_des ,int config_num, int *config_value);
#endif


#ifdef QUEC_ASR_ATCMD_TAU_TYPE_SUPPORT
QuecOSStatus quec_tau_type_cfg(void);

RETURNCODE_T  quectel_exec_qcfg_tautype_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);
#endif
#if defined(__QUEC_OEM_VER_CBZ__)
RETURNCODE_T  quec_exec_qcrc_cmd(const utlAtParameterOp_T		op,
									const char					 *command_name_p,
									const utlAtParameterValue_P2c parameter_values_p,
									const size_t				  num_parameters,
									const char					 *info_text_p,
									unsigned int				 *xid_p,
									void						 *arg_p);
#endif


RETURNCODE_T  quec_exec_qpowd_cmd(
	const utlAtParameterOp_T op,
	const char *command_name_p,
	const utlAtParameterValue_P2c parameter_values_p,
	const size_t num_parameters,
	const char *info_text_p,
	unsigned int *xid_p,
	void *arg_p
);
#ifdef QUEC_AT_URC_SUPPORT
RETURNCODE_T quec_exec_qurccfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif
#ifndef QUEC_MINI_SYSTEM_SUPPORT	
/*===========================================================================

FUNCTION QUEC_BASIC_ATI_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes I command.
  This command returns identification information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_basic_ati_cmd
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
#ifdef QUECTEL_AT_COMMAND


/*===========================================================================

FUNCTION QUEC_BASIC_ATC_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes C command.


DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_basic_atc_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */
    void                          *arg_p              /* AT cmd parser number */
);

/*===========================================================================

FUNCTION QUEC_BASIC_ATD_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes C command.


DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T  quec_basic_atd_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
	const char                    *command_name_p,	  /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,		  /* AT cmd usage string  */
    unsigned int                  *xid_p,	          /* AT cmd handle        */
    void                          *arg_p              /* AT cmd parser number */
);



RETURNCODE_T  quec_exec_qpdptimer_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
    const char                    *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,       /* AT cmd usage string  */
    unsigned int                  *xid_p,             /* AT cmd handle        */
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qdebounce_cmd
(
    const utlAtParameterOp_T       op,                /* AT cmd type          */
    const char                    *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value         */
    const size_t                   num_parameters,    /* AT cmd number        */
    const char                    *info_text_p,       /* AT cmd usage string  */
    unsigned int                  *xid_p,             /* AT cmd handle        */
    void                          *arg_p              /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qspn_cmd(const utlAtParameterOp_T 	 op,
	const char					 *command_name_p,
	const utlAtParameterValue_P2c parameter_values_p,
	const size_t				  num_parameters,
	const char					 *info_text_p,
	unsigned int				 *xid_p,
	void						 *arg_p);


RETURNCODE_T  quec_exec_qsclkcfg_cmd(const utlAtParameterOp_T    op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p);

#ifdef QUEC_UART1_ENABLE

/*===========================================================================

FUNCTION QUEC_EXEC_IPR_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +IPR command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_ipr_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

RETURNCODE_T quec_exec_cbaud_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

#endif

#ifdef QUEC_UART2_ENABLE
/*===========================================================================

FUNCTION QUEC_EXEC_QDIAGPORT_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QDIAGPORT command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_qdiagport_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

#endif
#ifdef QUEC_PPP_ENABLE

/*===========================================================================

FUNCTION QUEC_EXEC_QPPPDROP_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QPPDROP command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_qpppdrop_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif
//Chaim 2019.1.17 add datamode cmd
RETURNCODE_T quec_exec_datamode_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);


#ifdef QUEC_SLEEP_ENABLE

/*===========================================================================

FUNCTION QUEC_EXEC_QSCLK_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QSCLK command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_qsclk_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#ifdef QUEC_QSCLKEX_ENABLE

RETURNCODE_T quec_exec_qsclkex_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

RETURNCODE_T quec_exec_qsclkexcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);



#endif

#endif

#ifdef QUEC_CMUX_ENABLE

/*===========================================================================

FUNCTION QUEC_EXEC_QSCLK_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QSCLK command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_cmux_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

#endif

#ifdef QUEC_NETWORK_CARD_ENABLE


/*===========================================================================

FUNCTION QUEC_EXEC_QNETDEVCTL_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QNETDEVCTL command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_qnetdevctl_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);

#endif

#ifdef QUEC_ENGINEER_OUTPUT

RETURNCODE_T quec_exec_qenginfo_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif


#ifdef QUEC_UART1_ENABLE

/*===========================================================================

FUNCTION QUEC_EXEC_IFC_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +IFC command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_ifc_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif

#ifdef QUEC_STARTUP_OPTIMIZATION
RETURNCODE_T quec_exec_startuptime_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif

#ifdef QUEC_AT_QDEBUGCFG_SUPPORT

RETURNCODE_T quectel_exec_qdbgcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);


RETURNCODE_T quectel_exec_qdbgcfg_ppp_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qdbgcfg_log_port_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);
RETURNCODE_T  quectel_exec_qdbgcfg_dumpcfg_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);

//jensen.fang 20190130: added interface to set the catstudio log level
RETURNCODE_T  quectel_exec_qdbgcfg_loglevel_cmd(const utlAtParameterOp_T 	 op,
												const char					 *command_name_p,
												const utlAtParameterValue_P2c parameter_values_p,
												const size_t				  num_parameters,
												const char					 *info_text_p,
												unsigned int				 *xid_p,
												void						 *arg_p);


RETURNCODE_T  quectel_exec_qdbgcfg_memory_cmd(const utlAtParameterOp_T     op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);


RETURNCODE_T  quectel_exec_qdbgcfg_sleep_debug_cmd(const utlAtParameterOp_T     op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);


RETURNCODE_T  quectel_exec_qdbgcfg_flash_check_cmd(
											     const utlAtParameterOp_T        op,                    
											     const char                     *command_name_p,       
											     const utlAtParameterValue_P2c   parameter_values_p,    
											     const size_t                    num_parameters,       
											     const char                     *info_text_p,           
											     unsigned int                   *xid_p,                 
											     void                           *arg_p ); 


                                                
RETURNCODE_T  quectel_exec_qdbgcfg_cmux_log_cmd(const utlAtParameterOp_T     op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);


RETURNCODE_T  quectel_exec_qdbgcfg_system_abort_cmd(const utlAtParameterOp_T     op,
                                                const char                   *command_name_p,
                                                const utlAtParameterValue_P2c parameter_values_p,
                                                const size_t                  num_parameters,
                                                const char                   *info_text_p,
                                                unsigned int                 *xid_p,
                                                void                         *arg_p);
                                                
RETURNCODE_T  quectel_exec_qdbgcfg_tcpip_rate_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qdbgcfg_show_rx_data_stream_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qdbgcfg_usbinfo_to_uart_log_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qdbgcfg_usbinfo_query_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

QuecOSStatus quec_read_rtilog_mode(void);

RETURNCODE_T quectel_exec_qdbgcfg_rtilog_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T quectel_exec_qdbgcfg_interrupt_log_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T quectel_exec_qdbgcfg_lwip_loglevel_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T quectel_exec_qdbgcfg_urc_option_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T quectel_exec_qdbgcfg_port_data_show_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T quectel_exec_qdbgcfg_oem_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T quectel_exec_qdbgcfg_netcfg_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T quectel_exec_qdbgcfg_simcfg_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

#endif
#endif
#ifdef __QUECTEL_COMMOM_AT_SUPPORT
/*===========================================================================

FUNCTION QUEC_BASIC_AT_PARSER_SHELL_SET_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes E command.
  This command controls echoing of the command line to TE.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
utlReturnCode_T quec_basic_at_parser_shell_set_cmd
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

FUNCTION QUEC_EXEC_IDENTIFICATION_REQUEST_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +GMI/+GMM/+GMR/+CGMI/+CGMM/+CGMR command.
  This command returns : manufacturer/module/revision information.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
utlReturnCode_T quec_exec_identification_request_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,	/* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,	/* AT cmd value         */
    const size_t                    num_parameters,	    /* AT cmd number        */
    const char                      *info_text_p,		/* AT cmd usage string  */
    unsigned int                    *xid_p,		        /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif
#ifdef QUEC_AT_CGSN_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_CGSN_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +GSN/+CGSN command.
  This command returns serial number information.

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
RETURNCODE_T  quec_exec_cgsn_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);
RETURNCODE_T  quec_exec_gsn_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);
#endif

RETURNCODE_T  quec_exec_qgsn_cmd
(
    const utlAtParameterOp_T        op,                  /* AT cmd type          */
    const char                     *command_name_p,      /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p,  /* AT cmd value         */
    const size_t                    num_parameters,      /* AT cmd number        */
    const char                     *info_text_p,         /* AT cmd usage string  */
    unsigned int                   *xid_p,               /* AT cmd handle        */
    void                           *arg_p                /* AT cmd parser number */
);

#ifdef QUEC_AT_CFUN_SUPPORT
#ifndef QUEC_MINI_SYSTEM_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_CFUN_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +CFUN command.
  This command selects the level of functionality in the phone to
  control power consumption. Additionally, certain UE specific
  modes (e.ge FTM) can be select.

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
RETURNCODE_T  quec_exec_cfun_cmd
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
#ifdef QUEC_AT_CSCS_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_CSCS_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +CSCS command.
  This command informs the module which character set is usedby the TE.
  this enable the UE ti convert character strings correctly between TE and UE character sets.

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
utlReturnCode_T  quec_exec_cscs_cmd
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
#ifdef QUEC_AT_AMPW_V_SUPPORT
/*===========================================================================

FUNCTION QUEC_BASIC_AT_AMPV_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes &V command.
  This command display the current settings of serveral AT command [arameters,
  including the single-letter AT command parameter which are not readable otherwise.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
utlReturnCode_T quec_basic_at_ampv_cmd
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

FUNCTION QUEC_BASIC_AT_AMPW_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes &W command.
  This command store the current AT command setting to a user defined
  profile in non-volatile mempry.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
utlReturnCode_T quec_basic_at_ampw_cmd
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
#ifdef QUEC_AT_CMEE_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_CMEE_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +CMEE command.
  This command controls the format of error result codes:
  ERROR, error numbers, or verbose message.

DEPENDENCIES
  None

RETURN VALUE
  returns an enum that describes the result of the command execution.
  possible values:
    utlSUCCESS : if it is a success.

SIDE EFFECTS
  None
===========================================================================*/
RETURNCODE_T quec_exec_cmee_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif


#ifdef QUECTEL_AT_QCFG_SUPPORT


#if defined (LTEONLY_THIN_SINGLE_SIM) || defined (QUECTEL_OPEN_CPU)
/*AT+QCFG="NW/Optmz",108,600weqewqewqe */
RETURNCODE_T  quectel_exec_qcfg_nwoptmz_cmd
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

RETURNCODE_T quectel_exec_qcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_qcfg_gprsattach_cmd
(
       const utlAtParameterOp_T        op,                 /* AT cmd type          */
       const char                     *command_name_p,     /* AT cmd name          */
       const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
       const size_t                    num_parameters,     /* AT cmd number        */
       const char                     *info_text_p,        /* AT cmd usage string  */
       unsigned int                   *xid_p,              /* AT cmd handle        */
       void                           *arg_p
 );

 RETURNCODE_T quectel_exec_qcfg_servicedomain_cmd
 (
        const utlAtParameterOp_T        op,                 /* AT cmd type          */
        const char                     *command_name_p,     /* AT cmd name          */
        const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
        const size_t                    num_parameters,     /* AT cmd number        */
        const char                     *info_text_p,        /* AT cmd usage string  */
        unsigned int                   *xid_p,              /* AT cmd handle        */
        void                           *arg_p
  );

  RETURNCODE_T quectel_exec_qcfg_roamservice_cmd
 (
        const utlAtParameterOp_T        op,                 /* AT cmd type          */
        const char                     *command_name_p,     /* AT cmd name          */
        const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
        const size_t                    num_parameters,     /* AT cmd number        */
        const char                     *info_text_p,        /* AT cmd usage string  */
        unsigned int                   *xid_p,              /* AT cmd handle        */
        void                           *arg_p
  );

//Isaac 20201228 support at+qcfg="roamserviceex"
#ifdef QUECTEL_AT_QCFG_ROAMSERVICEEX
    typedef enum {
        QUEC_ROAMSERVICEEX_DISABLE  = 0,        /*disable roamserviceex cfg Õý³£¹¤×÷Ä£Ê½£¬ÎÞÏÞÖÆ·þÎñ*/
        QUEC_ROAMSERVICEEX_DISABLE_DIAL,        /*disable the internet access(NIC dialing) ÔÚÂþÓÎÄ£Ê½ÏÂ½ûÓÃÍø¿¨²¦ºÅÉÏÍø¹¦ÄÜ*/
        QUEC_ROAMSERVICEEX_DISABLE_CALL,        /*disable voice call ÔÚÂþÓÎÄ£Ê½ÏÂ½ûÓÃÓïÒôÍ¨»°¹¦ÄÜ*/
        QUEC_ROAMSERVICEEX_DISABLE_DIAL_CALL,   /*disable the internet access(NIC dialing) and disable voice call Á½Õß¶¼½ûÓÃ*/
        QUEC_ROAMSERVICEEX_MAX
    }quec_roamserviceex_e;
    
    RETURNCODE_T quectel_exec_qcfg_roamserviceex_cmd
    (
        const utlAtParameterOp_T        op,                 /* AT cmd type          */
        const char                     *command_name_p,     /* AT cmd name          */
        const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
        const size_t                    num_parameters,     /* AT cmd number        */
        const char                     *info_text_p,        /* AT cmd usage string  */
        unsigned int                   *xid_p,              /* AT cmd handle        */
        void                           *arg_p
    );
    int32 quec_get_roamserviceex_cfg(void);
    void quec_set_roamserviceex_cfg(int32 val);
    QuecOSStatus quec_save_roamserviceex_cfg_nv(int32 val);
    void quec_roamserviceex_cfg_init_nv(void);
    bool quec_is_roam_status(void);
    bool quectel_roam_disable_status_get_bit(uint8 bit);
#endif


RETURNCODE_T  quectel_exec_qcfg_nwscanmode_cmd
(
       const utlAtParameterOp_T        op,                 /* AT cmd type          */
       const char                     *command_name_p,     /* AT cmd name          */
       const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
       const size_t                    num_parameters,     /* AT cmd number        */
       const char                     *info_text_p,        /* AT cmd usage string  */
       unsigned int                   *xid_p,              /* AT cmd handle        */
       void                           *arg_p
 );

 RETURNCODE_T  quectel_exec_qcfg_nwscanmodeex_cmd
 (
		const utlAtParameterOp_T		op, 				/* AT cmd type			*/
		const char					   *command_name_p, 	/* AT cmd name			*/
		const utlAtParameterValue_P2c	parameter_values_p, /* AT cmd value 		*/
		const size_t					num_parameters, 	/* AT cmd number		*/
		const char					   *info_text_p,		/* AT cmd usage string	*/
		unsigned int				   *xid_p,				/* AT cmd handle		*/
		void						   *arg_p
  );

 

 RETURNCODE_T quectel_exec_qcfg_nwscanseq_cmd
 (
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
 );

 RETURNCODE_T quectel_exec_qcfg_band_cmd
 (
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
 );


RETURNCODE_T  quectel_exec_qcfg_urc_delay_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_urc_cache_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_urc_datamode_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p                  /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_urc_ri_ring_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_urc_ri_smsincoming_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_urc_ri_other_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_urc_method_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p
);

RETURNCODE_T  quectel_exec_qcfg_risignaltype_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);
RETURNCODE_T  quectel_exec_qcfg_urc_ri_sleep_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p                  /* AT cmd parser number         */

);

/*ford.zhang@2020.07.21  add for command "AT+QCFG="usbnetmac"*/
#if 1//def QUEC_ASR_ATCMD_USB_NET_MAC_SUPPORT
RETURNCODE_T  quectel_exec_qcfg_usbnetmac_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);
#endif
/*ford.zhang@2020.07.21  end add for command "AT+QCFG="usbnetmac"*/

//destin 2020.09.24 add for "AT+QCFG="csqgpiodisp" 
RETURNCODE_T  quectel_exec_qcfg_csqgpiodisp_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p                  /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_usbnet_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbid_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbifc_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbdtd_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbauto_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);
RETURNCODE_T  quectel_exec_qcfg_usbmanufacturer_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbversion_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_usbphy_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				    /* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_uart2ipr_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

//Chaim@qian add 2019.1.16 add ppp/termframe cmd   
RETURNCODE_T  quectel_exec_qcfg_termframe_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p 					/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_pppdcd_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p                  /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_iprecovery_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);


RETURNCODE_T  quectel_exec_qcfg_cmux_channel_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

RETURNCODE_T  quectel_exec_qcfg_fota_cid_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

RETURNCODE_T  quectel_exec_qcfg_fota_times_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

//gunner.yang 2019-06-03
RETURNCODE_T  quectel_exec_qcfg_pcmclk_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
//end gunner
RETURNCODE_T  quectel_exec_qcfg_ncell_priority_cmd
(
	 const utlAtParameterOp_T		 op,				 /* AT cmd type 		 */
	 const char 					*command_name_p,	 /* AT cmd name 		 */
	 const utlAtParameterValue_P2c	 parameter_values_p, /* AT cmd value		 */
	 const size_t					 num_parameters,	 /* AT cmd number		 */
	 const char 					*info_text_p,		 /* AT cmd usage string  */
	 unsigned int					*xid_p, 			 /* AT cmd handle		 */
	 void							*arg_p
);


#ifdef QUEC_NTP_SUPPORT
RETURNCODE_T  quectel_exec_qcfg_ntp_cmd
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

RETURNCODE_T  quectel_exec_qdbgcfg_iptrace_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
#ifdef QUECTEL_AT_QCFG_ACQDB_OPT_SUPPORT

RETURNCODE_T  quectel_exec_qcfg_acq_query_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
RETURNCODE_T  quectel_exec_qcfg_acq_insert_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
RETURNCODE_T  quectel_exec_qcfg_acq_clear_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
RETURNCODE_T  quectel_exec_qcfg_acq_update_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);
RETURNCODE_T  quectel_exec_qcfg_nwoptmz_acq_cmd
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

RETURNCODE_T  quectel_exec_qcfg_ltedftcid_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

/*Tery 20190328 aad airplanecontrol function*/
RETURNCODE_T  quectel_exec_qcfg_airplane_cmd
(
		 const utlAtParameterOp_T		 op,				 /* AT cmd type 		 */
		 const char 					*command_name_p,	 /* AT cmd name 		 */
		 const utlAtParameterValue_P2c	 parameter_values_p, /* AT cmd value		 */
		 const size_t					 num_parameters,	 /* AT cmd number		 */
		 const char 					*info_text_p,		 /* AT cmd usage string  */
		 unsigned int					*xid_p, 			 /* AT cmd handle		 */
		 void							*arg_p
);


QuecOSStatus quec_feature_switch_read(void);

RETURNCODE_T  quectel_exec_qcfg_feature_switch_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_ledmode_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_ppp_remoteip_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_dns_proxy_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_nat_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

QuecOSStatus quec_dhcp_cfg_read(void);

RETURNCODE_T  quectel_exec_qcfg_dhcpcfg_cmd 
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_netmaskset_cmd 
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_tone_incoming_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_cmux_urcport_cmd 
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_creg_emergency_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_pdp_retrytimes_cmd
(
	 const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	 const char 					*command_name_p,		/* AT cmd name					*/
	 const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	 const size_t					 num_parameters,		/* AT cmd number				*/
	 const char 					*info_text_p,			/* AT cmd usage string			*/
	 unsigned int					*xid_p, 				/* AT cmd handle				*/
	 void							*arg_p				/* AT cmd parser number 		*/
);

RETURNCODE_T  quectel_exec_qcfg_addehplmn_cmd
(
	const utlAtParameterOp_T		 op,					/* AT cmd type					*/
	const char					*command_name_p,		/* AT cmd name					*/
	const utlAtParameterValue_P2c	 parameter_values_p,	/* AT cmd value 				*/
	const size_t					 num_parameters,		/* AT cmd number				*/
	const char					*info_text_p,			/* AT cmd usage string			*/
	unsigned int					*xid_p, 				/* AT cmd handle				*/
	void							*arg_p					/* AT cmd parser number 		*/
);

#endif
#ifdef QUEC_URC_RI_DCD_SUPPORT
RETURNCODE_T quectel_exec_qcfg_urc_ri_pin_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);
#endif

#ifdef QUEC_PRECHECK_SUPPORT
RETURNCODE_T quectel_exec_qcfg_precheck_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
);
#endif

RETURNCODE_T quectel_exec_qcfg_ims_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);

#ifdef QUECTEL_AT_QINDCFG_SUPPORT
/*===========================================================================

FUNCTION QUEC_EXEC_QINDCFG_CMD

DESCRIPTION
  This function takes the result from the command line parser
  and executes it. It executes +QINDCFG command.
  This command is used to control URC indication.

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

RETURNCODE_T quectel_exec_qindcfg_cmd
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

#ifdef QUEC_AT_CIND_SUPPORT
RETURNCODE_T quectel_exec_cindcfg_cmd
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

//Fitz.xu 20200414: add AT^DSCI
#ifdef QUEC_CALL_DSCI_SUPPORT
extern uint8 quec_dsci_flag_get(void);

RETURNCODE_T  quec_exec_call_dsci_cmd
(
    const utlAtParameterOp_T    op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p
);
#endif

#if QUEC_SIM_PIN_CTRL_FUNC
#define QUEC_PIN_CTRL_FILE   "quec_pin_ctl.value"
#define QUEC_SIM_GPIOCTL_TASK_STACK_SIZE        (2048)
#define QUEC_SIM_GPIOCTL_TASK_PRIORITY          (105)
#define QUEC_SIM_GPIOCTL_HANDLE_MAX  			(1)
#define LCC_SIMCTL_PIN		119 
#define ASR_SIMCTL_PIN		11

typedef struct
{
	UINT8 sim_119_pin_value ;  //default value is 1
	UINT8 sim_119_pin_func_enable ;
	UINT8 max_pin;          //reserve for future using , if you have some config need saving to file ,can use this file and struct
}quec_pin_ctrl_t;

void sim_gpio_ctl(UINT8 value) ;
int32 sim_gpio_sim_write_flash(quec_pin_ctrl_t *sim_pin_ctrl_value);
void sim_gpio_read_flash(void);
void quec_sim_change(void);
static void quec_sim_gpioctl_handle_task(void * argv);
QuecOSStatus sim_gpioctl_task_init(void);
QuecOSStatus sim_gpioctl_task_delete(void);

RETURNCODE_T  quec_exec_qdsim_cmd
(
    const utlAtParameterOp_T    op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p
);


#endif

#if QUEC_AT_QGPIOEXT_SUPPORT
RETURNCODE_T  quec_exec_qgpioext_cmd
(
    const utlAtParameterOp_T    op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p
);
#endif



#if QUEC_CUSD_OPTIMIZE
RETURNCODE_T quec_exec_qcusdcvt_cmd
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

//isaac 20200602: add at+qcfg="csqtype",<val> to calculate csq by rssi(val is 0) or rsrp(val is 1)
#ifdef QUECTEL_CSQ_TYPE
RETURNCODE_T  quectel_exec_qcfg_csqtype_cmd
(
    const utlAtParameterOp_T      op,
    const char                   *command_name_p,
    const utlAtParameterValue_P2c parameter_values_p,
    const size_t                  num_parameters,
    const char                   *info_text_p,
    unsigned int                 *xid_p,
    void                         *arg_p
);

UINT32 quec_get_csq_type(void);
void quec_set_csq_type(UINT32 csqtype);
QuecOSStatus quec_csq_gpio_cfg_state_read(void);
QuecOSStatus quec_read_csq_type_from_nv(void);
QuecOSStatus quec_save_csq_type_to_nv(UINT32 csqtype);

#endif

//isaac 20200708: add at+qsimpollcfg sim¿¨ÂÖÑµ¼ì²â¹¦ÄÜ
#ifdef QUECTEL_SIM_POLL_CFG
RETURNCODE_T  quec_exec_sim_poll_cfg_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);
UINT8 quec_get_sim_poll_cfg(void);
void quec_set_sim_poll_cfg(UINT8 sim_poll_cfg);
void quec_nv_sim_poll_cfg_init(void);

#endif

//isaac 20200804 add at+qncell Ö§³Ö²éÑ¯ÁÚÇøcellid,Òòat+qeng="neighbourcell" ²»·µ»Øcellid
#if defined (QUECTEL_CELL) || defined (QUEC_QCELLINFO_SUPPORT)
RETURNCODE_T  quec_cell_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);

#define QUEC_CELLEX_INFO_MAX_LEN (1024)
#define QUEC_UPDATE_CELLEX_INFO_DEFAULT_TIME (120)  //120s
#define QUEC_UPDATE_CELLEX_INFO_FIRST_TIME (7)  //7s
#define QUEC_CELLEX_INFO_MAX_NUM (8)

RETURNCODE_T  quec_cellex_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);
void quec_set_qcellex(int32 val);
int32 quec_get_qcellex(void);
QuecOSStatus quec_update_cellex_info(void);
void quec_qeng_cellex_info_max_limited(char *qeng_buff , UINT32 buff_len);

#endif

#ifdef QUEC_AT_FLASH_ERASE_COUNT_CMD
RETURNCODE_T quectel_exec_qerasecount_cmd
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

//isaac 20201107 add at+rsrp cmd
#ifdef QUEC_RSRP_SUPPORT
RETURNCODE_T  quec_rsrp_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);
#endif

#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
RETURNCODE_T quectel_exec_qcfg_ipc_server_type_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p
);

RETURNCODE_T quectel_exec_qcfg_ipc_pdpcid_num_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p
);

RETURNCODE_T quectel_exec_qcfg_sleepind_level_cmd
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

//#ifdef QUEC_AT_QCFG_USB_NEMA
#define QUEC_USB_NEMA_DISABLE (0)
#define QUEC_USB_NEMA_ENABLE  (1)

RETURNCODE_T quectel_exec_qcfg_usb_nema_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p
);
int32 quec_get_usb_nema_cfg(void);
void quec_set_usb_nema_cfg(int32 val);
QuecOSStatus quec_save_usb_nema_cfg_nv(int32 val);
void quec_usb_nema_cfg_init_nv(void);
int32 quec_get_usb_nema_ec20(void);

//#endif

//#if defined(QUEC_SLEEP_AP_READY)||defined(QUECTEL_PROJECT_EC800N_BSP)
RETURNCODE_T quectel_exec_qcfg_ipc_apready_enable_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p
);
//#endif
void quec_at_fetch_config(void);

QuecOSStatus quec_transmission_rate_config(void);
#ifdef QUEC_ASR_ATCMD_USB_NET_MAC_SUPPORT
extern void quectel_usbnet_mac_read(void);
#endif
#ifdef QUEC_CDMA_IMSI_SUPPORT

#if defined QUEC_AT_CMD_CAMERA_SUPPORT





#endif

RETURNCODE_T quec_exec_qcdma_imsi_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                      *command_name_p,    /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                      *info_text_p,       /* AT cmd usage string  */
    unsigned int                    *xid_p,             /* AT cmd handle        */
    void                            *arg_p              /* AT cmd parser number */
);
#endif

#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
RETURNCODE_T  quec_exec_qpagupdate_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);
#endif

#ifdef QUEC_QCELLINFO_SUPPORT
RETURNCODE_T quec_qcellinfoex_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
RETURNCODE_T quec_qcellinfo_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

/*
»ñÈ¡QCELLINFOµÄ×´Ì¬
return
0£¬´ú±í²»Ê¹ÓÃ»º´æµÄÐÅÏ¢
1£¬´ú±íÊ¹ÓÃ»º´æµÄÐÅÏ¢
*/
int32 quec_get_qcellinfo(void);
void quec_set_qcellinfo(int32 val);

#endif

UINT8  quectel_set_urc_ind_save_flag
(
	quectel_urc_ind_cfg_e_type flag,
	UINT8 value
);

#ifdef QUECTEL_AT_QCFG_SUPPORT
#define QUEC_QCFG_MIFI_LINK_DOWN (0)
#define QUEC_QCFG_MIFI_LINK_UP   (1)

void quec_set_qcfg_mifi_link_flag(bool set_value);
void quec_get_qcfg_mifi_link_flag(bool *get_value);

RETURNCODE_T  quectel_exec_qcfg_mifilink_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_mifi_tmr_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

#endif
#if QUEC_SMS_QCMGSP_SUPPORT
RETURNCODE_T quec_exec_qcmgsp_cmd
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

#ifdef QUEC_AT_CIVER_SUPPORT
void quec_ci_debug_set(void);
#endif


#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
#define QUEC_MAX_BLACK_CELL_NUM 10
#define QUEC_MAX_BLACK_CELL_LEN 128
#define QUEC_INVALID_AFRCN  0
#define QUEC_INVALID_CELLID 0
#define QUEC_BLACKCELL_ENABLE 1
#define QUEC_BLACKCELL_DISABLE 0

typedef enum 
{
    BLACKCELL_GSM = 0,
    BLACKCELL_WCDMA,
    BLACKCELL_LTE,
    BLACKCELL_MAX,
}quec_rat_e_t;

typedef enum 
{
    BLACKCELL_ADD = 0,
    BLACKCELL_DELETE,
    BLACKCELL_OP_MAX
}quec_optype_e_t;

typedef struct
{
    UINT8 opType; /*add or delete black cell: 0 is set; 1 is delete*/
    UINT8 rat;    /*0: gsm; 1: wcdma; 2: lte */
    UINT8 gsmBlackCellValid[QUEC_MAX_BLACK_CELL_NUM];
    UINT8 wcdmaBlackCellValid[QUEC_MAX_BLACK_CELL_NUM];
    UINT8 lteBlackCellValid[QUEC_MAX_BLACK_CELL_NUM];
    CiDevLteBlackCellList  LteBlackCellList;
    CiDevUmtsBlackCellList UmtsBlackCellList;
    CiDevGsmBlackCellList  GsmBlackCellList;
}quec_black_cell_s_t;

RETURNCODE_T quectel_exec_blackcell_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_blackcellcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_blackextand_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

#define QUEC_BLACKE_EXTAND_CONFIG_OFF 0
#define QUEC_BLACKE_EXTAND_CONFIG_ON   1
#define QUEC_BLACKE_EXTAND_CONFIG_DEFAULT 1
#define QUEC_BLACK_EXTAND_CONFIG   "quec_blacke_extand_config"

void quec_delete_all_blackcell(void);
void quec_set_black_cell_cfg(int blackcellCfg);
int quec_get_black_cell_cfg(void);
UINT8 quec_get_electric_blackextand_cfg(void);

#endif

#if QUEC_BIP_SUPPORT
RETURNCODE_T quectel_exec_qcfg_bip_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p
);
void quec_bip_config_init(void);
BOOL quec_bip_state(void);
#endif
#ifdef QUEC_BLACK_CELL_SUPPORT
#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_MAX_NUM 8
#define QUEC_BLACK_ELECTRIC_FENCE_CELL_MAX_NUM 10

#define QUEC_BLACK_ELECTRIC_FENCE_TIMER_MIN 300
#define QUEC_BLACK_ELECTRIC_FENCE_TIMER_MAX 86400
#define QUEC_BLACK_ELECTRIC_FENCE_TIMER_DEFAULT 1800

#define QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_MODE_OFF 0
#define QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_MODE_ON 1

#define QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_TIMER_MIN 60
#define QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_TIMER_MAX 3600
#define QUEC_BLACK_ELECTRIC_FENCE_PREVENTION_TIMER_DEFAULT 300

#define QUEC_BLACK_ELECTRIC_FENCE_CONTINUOUS_JUDGE 0
#define QUEC_BLACK_ELECTRIC_FENCE_ACCUMULATE_JUDGE 1

#define QUEC_BLACK_ELECTRIC_FENCE_REJECT_COUNT_MIN 1
#define QUEC_BLACK_ELECTRIC_FENCE_REJECT_COUNT_MAX 255
#define QUEC_BLACK_ELECTRIC_FENCE_REJECT_COUNT_DEFAULT 5

#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_NUM_MIN 1
#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_NUM_MAX 255
#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_NUM_DEFAULT 3

#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_CYCLE_MIN 300
#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_CYCLE_MAX 32400
#define QUEC_BLACK_ELECTRIC_FENCE_ALGRAPH_LOOP_CYCLE_DEFAULT 600

#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_MIN 0
#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_MAX 7
#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_DEFAULT 0

#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_WEIGHT_MIN 0
#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_WEIGHT_MAX 255
#define QUEC_BLACK_ELECTRIC_FENCE_EVENT_WEIGHT_DEFAULT 4

#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_OFF 0
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_ON   1
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_DEFAULT 0

#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_COUNT_MIN 1
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_COUNT_MAX 255
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_COUNT_DEFAULT 100

#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_CYCLE_MIN 60
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_CYCLE_MAX 86400
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_CYCLE_DEFAULT 600

#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_RETRYNUM_MIN 1
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_RETRYNUM_MAX 255
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_RETRYNUM_DEFAULT 3

#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_BLACKCELL_INVAILD 0
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_BLACKCELL_VAILD   1
#define QUEC_BLACK_ELECTRIC_FENCE_LWIPCFG_BLACKCELL_DEFAULT 0

#define QUEC_ELECTRIC_FENCE_CONFIG   "quec_electric_fence_config"

typedef enum 
{
	QUEC_BLACKCELL_REGISTER_SUCCESS = 0,
    QUEC_BLACKCELL_NETWORK_DROPOUT,
    QUEC_BLACKCELL_PREVENT_TIMEOUT
}quec_blackcell_preventtimer_update_e_t;

typedef enum 
{
    BLACKCELL_ATTACH_SUCCESS = 0,
    BLACKCELL_REGISTER_SERVICE_REJECT, //  ATTACH/TAU/SERVICE/AUTHENTICATION REJECT
    BLACKCELL_REGISTER_TIMEOUT,        //  ATTACH/TAU TIMEOUT
    BLACKCELL_SERVICE_TIMEOUT          //  SERVICE TIMEOUT + RRC_CONN_SETUP_NOT_RECEIVED
}quec_black_oneshoot_type_e_t;

typedef enum 
{
	NONE_OPERATE = 0x0,
	TIMER_EVENT = 0x01,
	CFUN_EVENT = 0x02,
    POWERDOWN_EVENT = 0x04,
	ALL_EVENT = 0xFF
}quec_electric_fence_bitmask;

typedef enum 
{
	FENCE_NAS_REJECT_EVENT = 0x0,
	FENCE_NAS_TIMEOUT_EVENT = 0x01,
	FENCE_NAS_SERVICE_NOT_RECEIVE = 0x02,
    FENCE_LWIP_NO_DOWNLINK = 0x03,
    FENCE_REGISTER_PING_PONG = 0x04,
	FENCE_ALL_EVENT = 0x07
}quec_electric_fence_blacksence;

typedef enum 
{
	QUEC_BLACKWLIP_PING_SUCCESS = 0,
    QUEC_BLACKWLIP_PING_FAILD,
    QUEC_BLACKWLIP_PING_RESET,
}quec_blacklwip_pingstatus_e_t;

typedef enum
{
	PREVENTMR_STA_NULL,
	PREVENTMR_STA_ENABLED,
	PREVENTMR_STA_DISABLED,
	PREVENTMR_STA_ERROR,
} quec_preventtmr_sta_e;

typedef struct 
{
    bool                    vaild;
    UINT8                   rat;     /*0: gsm; 1: wcdma; 2: lte */
    UINT32                  arfcn;   /**<  LTE : EARFCN; URTAN: UARFCN; GSM: ARFCN */
    UINT16                  cellId;  /**< LTE : PCI; URTAN: PSC; GSM: BSCI */
	UINT8                   weightmask;     /* */
	UINT32                  black_ticks; 
	UINT8                   event_index;
}quec_blackcellid;

typedef struct 
{
   UINT8				   blackcell_num;
   UINT8                   fence_state;
   UINT32                  blackcelltimer_size;
   UINT8                   blackcellprevention_mode;
   UINT32                  blackcellpreventiontimer_size;
   UINT8                   blackcellreject_judgemode;
   UINT8                   blackcellreject_judgenum;
   INT8					   fence_loopnum;
   INT32				   fence_loopcycle; 
   quec_blackcellid        blackcellid_list[QUEC_BLACK_ELECTRIC_FENCE_CELL_MAX_NUM];  
   UINT8                   blackeventweight[QUEC_BLACK_ELECTRIC_FENCE_EVENT_MAX_NUM];
}quec_electric_fence_list;

#define QUEC_SCELL_VERTEX_NUM_MAX 30
#define QUEC_SCELL_ARC_NUM_MAX 254

typedef struct QuecScellArriveInfo{          
	UINT32                  arrive_ticks;   /**< The time point of the last switch to this cell */
	UINT8                   srccell_index;
	UINT8                   inarc_index;
	UINT8                   inarc_type;
}QuecScellArriveInfo;

typedef struct QuecScellinfo{
	UINT32                  afrcn;        
    UINT16                  cellId;    
	UINT8                   arrive_num;
	QuecScellArriveInfo     latest_ticks[10];   /**< The time point of the last switch to this cell */
	UINT8                   indegree;
	UINT8                   outdegree;
	BOOL                    isloop;
	UINT8                 	rsrp;
    UINT8                  	rsrq;
}QuecScellinfo;

typedef struct QuecScellSwitchArcNode{
	INT8                      		  dstvertex_index;
	INT8					          arc_index;	
	UINT32                            switch_ticks;
	UINT8                             switch_type;
	struct QuecScellSwitchArcNode*    nextarc;
}QuecScellSwitchArcNode;

typedef struct QuecScellinfoNode{
	INT8					vertex_index;	
	QuecScellinfo           quecscellinfo;
	QuecScellSwitchArcNode* firstarc;
}QuecScellinfoNode;

typedef struct{
    QuecScellinfoNode       QuecScellNodeList[QUEC_SCELL_VERTEX_NUM_MAX];
	INT8					vertex_num;
	INT8					arc_num;
	INT8					loopflag;
	INT8					loop_level;
}QuecScellALGragh;

typedef struct QuecScelldegreeInfo{          
	UINT8                   indegree;
	UINT8                   outdegree;
	bool                    isvisited;
}QuecScelldegreeInfo;

typedef struct {
    bool                    vaild;
	UINT16                  blacklwip_packectcount;
    UINT16                  blacklwip_fencenum;
    UINT32                  blacklwip_fencecycle;   
    UINT8                   retrynum;  
	UINT8                   pingcount; 
	char                    blackping_host[256];  	
	UINT32                  blackcell_vaild; 
	UINT32                  athandle; 
}quec_blacklwipcfg;

RETURNCODE_T quectel_exec_blackcellex_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_blackcellcfgex_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_blackcellweight_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quectel_exec_blacklwipcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

int quec_get_black_cell_cfg_ex(void);
void quec_set_black_cell_cfg_ex(int blackcellCfg);
UINT8 quec_get_black_event_weight(int index);
void quec_electric_fence_send_event_msg(int event);
QuecOSStatus quec_electric_fence_list_set_blackcell(UINT8 optype,UINT8 rat,UINT32 arfcn,UINT16 cellId,UINT8 weightmask,UINT8 event_index);
int quec_get_black_cell_reject_judge_num(void);
int quec_get_black_cell_reject_judge_mode(void);
int quec_insert_scell_arc
(	QuecScellALGragh* ScellALGragh,     
	CiDevCommonLteCellInfo sourceLteCell, 
	CiDevCommonLteCellInfo dstceLteCell,
	UINT8                  rsrpOfsourceCell,
    UINT8                  rsrqOfsourceCell,
    UINT8                  rsrpOfdstceLteCell,
    UINT8                  rsrqOfdstceLteCell,
    UINT8                  eventtype);

void quec_get_blacklwipcfg_host(char* pinghost);
UINT32 quec_get_blacklwipcfg_athandle(void);
BOOL quec_get_blacklwipcfg_vaild(void);
void quec_electric_fence_lwip_uplink_count(void);
void quec_electric_fence_lwip_downlink_count(void);
int quec_get_black_cell_prevention_mode(void);
void quec_electric_fence_send_prevent_event_msg(int prevent_event);
void quec_electric_fence_delete_all_blackcell(void);
UINT8 quec_electric_fence_preventiontimer_get_status(void);
#endif

#ifdef QUEC_LWIP_WAN_PING_FLAG_CFG_SUPPORT
RETURNCODE_T quec_exec_qlwpingcfg_cmd
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

#if defined(__QUECTEL_PROJECT_EC800KCN_CC__)|| defined (__QUECTEL_PROJECT_EC800KCN_CK__)
RETURNCODE_T quec_exec_qphwinfo_cmd
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

#if defined(QUEC_CAMMERA_DECODE_AUTHORIZATION)||defined(QUEC_AUDIO_DENOISE)
#ifdef QUEC_CAMMERA_DECODE_AUTHORIZATION
RETURNCODE_T quectel_qauthcode_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */
    void                           *arg_p               /* AT cmd parser number */
);
RETURNCODE_T quectel_get_uid_cmd
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
RETURNCODE_T  quec_exec_qlicenseinfo_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);

RETURNCODE_T  quec_exec_qlicense_cmd
(
	const utlAtParameterOp_T	   op,				  /* AT cmd type		  */
	const char					  *command_name_p,	  /* AT cmd name		  */
	const utlAtParameterValue_P2c  parameter_values_p,/* AT cmd value		  */	
	const size_t				   num_parameters,	  /* AT cmd number		  */
	const char					  *info_text_p, 	  /* AT cmd usage string  */
	unsigned int				  *xid_p,			  /* AT cmd handle		  */	
	void						  *arg_p			  /* AT cmd parser number */
);

#endif

RETURNCODE_T  quectel_exec_qdbgcfg_usbunplug_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

RETURNCODE_T  quectel_exec_qdbgcfg_gps_debug_level_cmd
(
         const utlAtParameterOp_T        op,                 /* AT cmd type          */
         const char                     *command_name_p,     /* AT cmd name          */
         const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */
         const size_t                    num_parameters,     /* AT cmd number        */
         const char                     *info_text_p,        /* AT cmd usage string  */
         unsigned int                   *xid_p,              /* AT cmd handle        */
         void                           *arg_p
);

#ifdef QUEC_UESTAT_SUPPORT
RETURNCODE_T quec_exec_questat_cmd
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





#ifdef  QUEC_CUST_FOR_POS_SUPPORT


/*  AT+QMUXCFG=1,1,1  */

RETURNCODE_T quec_exec_qmuxcfg_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);



/*AT+QIREGAPP="CMNET"*/
RETURNCODE_T quec_exec_qiregapp_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


/*AT+QIFGCNT=0*/
RETURNCODE_T quec_exec_qifgcnt_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);



/*AT+QPPPTIMER=1,0,15,1*/
RETURNCODE_T quec_exec_qifgcnt_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);


/*AT+QPPPTIMER=1,0,15,1*/
RETURNCODE_T quec_exec_qppptimer_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

/*AT+CGATTex=1*/

RETURNCODE_T quec_exec_cgattex_cmd
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





#ifdef QUEC_SLEEP_INFO_SUPPORT
RETURNCODE_T quectel_exec_sleep_info_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
void quec_sleep_info_urc(uint8 *data_buff,uint16 data_len);
void quec_sleep_info_check(UINT32 avrg);
BOOL quec_sleepinfo_is_empty(void);
#endif


RETURNCODE_T  quectel_exec_qcfg_wakeupin_level_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

#ifdef YS_GNSS_SUPPORT
RETURNCODE_T  quec_exec_yscpof_cmd(
	const utlAtParameterOp_T op,
	const char *command_name_p,
	const utlAtParameterValue_P2c parameter_values_p,
	const size_t num_parameters,
	const char *info_text_p,
	unsigned int *xid_p,
	void *arg_p
);

#endif

RETURNCODE_T  quectel_exec_qcfg_rtc_alarm_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

RETURNCODE_T  quectel_exec_qcfg_netif_wlist_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);

#ifdef QUEC_CUST_TESTFLAG_SUPPORT
void quec_get_bnn_testflag_from_nv(void);
RETURNCODE_T quec_exec_testflag_cmd
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

RETURNCODE_T quectel_exec_qcfg_urc_ri_level_cmd
(
        const utlAtParameterOp_T      op,
        const char                   *command_name_p,
        const utlAtParameterValue_P2c parameter_values_p,
        const size_t                  num_parameters,
        const char                   *info_text_p,
        unsigned int                 *xid_p,
        void                         *arg_p
);

/*ÓÃÓÚÉèÖÃrrcµÄ×´Ì¬*/
void quec_set_rrc_state(int state);
/*ÓÃÓÚ»ñÈ¡rrcµÄ×´Ì¬
·µ»Ø0,´ú±íRRC¿ÕÏÐÌ¬
·µ»Ø1,´ú±íRRCÁ¬½ÓÌ¬*/
int quec_get_rrc_state(void);

RETURNCODE_T quectel_exec_qcfg_clat_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
);

#ifdef QUEC_SMS_WHITE_SUPPORT
RETURNCODE_T quec_qtnumctl_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
);
#endif

RETURNCODE_T quectel_exec_qcfg_sms_quomark_cmd
(
		const utlAtParameterOp_T	  op,
		const char					 *command_name_p,
		const utlAtParameterValue_P2c parameter_values_p,
		const size_t				  num_parameters,
		const char					 *info_text_p,
		unsigned int				 *xid_p,
		void						 *arg_p
);

#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT
RETURNCODE_T quec_exec_qautoapn_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

RETURNCODE_T quec_exec_qautoapnurc_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

#define QUEC_AUTO_APN_CONFIG   "quec_autoapn_config"

#define QUEC_AUTO_APN_CFG_OFF   0
#define QUEC_AUTO_APN_CFG_ON    1

#define QUEC_AUTO_APN_URC_OFF   0
#define QUEC_AUTO_APN_URC_ON    1

typedef enum
{
	QUEC_AUTOAPN_NULL,
	QUEC_AUTOAPN_MATCHING,
	QUEC_AUTOAPN_SYNC,
	QUEC_AUTOAPN_COMPLETED,
	QUEC_AUTOAPN_FAIL,
	QUEC_AUTOAPN_SUSPEND, 
} quec_autoapn_flag;

typedef enum 
{
	QUEC_IMSI_UPDATE,
	QUEC_PDP_REJECT_GENERAL,
	QUEC_PDP_REJECT_SPECIAL,
	QUEC_PDP_ACTIVATE,
    QUEC_NEW_ATTACH_REQ
}quec_autoapn_msg;

typedef struct 
{
    int                    vaild;
    int                    adjust_status;    
    char                   current_IMSI[16];            
    UINT32                 reserved1;
}quec_autoapn_cfg;

void quec_autoapn_table_link_init_by_current_imsi(void);
int quec_get_autoapn_cfg_vaild(void);
int quec_get_autoapn_adjust_status(void);
void quec_set_autoapn_adjust_status(int status);
void quec_autoapn_imsi_judge(char *simRspImsiBuf,INT32 len);
void quec_autoapn_handle_by_event(int event);
bool quec_get_autoapnurc_status(void);
void quec_update_autoapn_config(void);
#endif

#ifdef QUEC_IMS_XML_SUPPORT
RETURNCODE_T quec_exec_qimsxmlurc_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);
  
#define QUEC_IMSXML_URC_OFF   0
#define QUEC_IMSXML_URC_ON    1
bool quec_get_imsxmlurc_status(void);
#endif

#ifdef QUEC_NETDUALCH_CFG
#define QUEC_PDP_CID_MIN 1
#define QUEC_PDP_CID_MAX 16
#define QUEC_NETDUALCHCFG_TASK_PRIORITY 80
#define QUEC_NETDUALCHCFG_QUEUE_MAX  20

typedef enum
{
    QUEC_NET_DUALCH_DISCONNECT, /*ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?*/
    QUEC_NET_DUALCH_CONNECT,    /*ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½*/
	QUEC_NET_DUALCH_CHECK,	    /*ï¿½ï¿½Ñ¯ï¿½ï¿½ï¿½ï¿½*/
    QUEC_NET_DUALCH_UNKNOW_OP
}quec_net_dualch_status_e_t;
    
typedef enum 
{
    QUEC_NET_DEFAULT_FLAG,  /*usb ï¿½ï¿½ï¿½ï¿½*/
    QUEC_NET_APP_FLAG,      /*app ï¿½ï¿½ï¿½ï¿½*/
    QUEC_NET_DEFAULT_PASS_FLAG,     /* usb transparent mode */
    QUEC_NET_MAX_FLAG
}quec_net_flag_e_t;

typedef enum 
{   
    QUEC_NET_DUALCH_1 = 1,   /*cid: 1-16*/
    QUEC_NET_DUALCH_2,
    QUEC_NET_DUALCH_3,
    QUEC_NET_DUALCH_4,
    QUEC_NET_DUALCH_5,
    QUEC_NET_DUALCH_6,
    QUEC_NET_DUALCH_7,
    QUEC_NET_DUALCH_8,
    QUEC_NET_DUALCH_9,
    QUEC_NET_DUALCH_10,
    QUEC_NET_DUALCH_11,
    QUEC_NET_DUALCH_12,
    QUEC_NET_DUALCH_13,
    QUEC_NET_DUALCH_14,
    QUEC_NET_DUALCH_15,
    QUEC_NET_DUALCH_16,
    QUEC_NET_DUALCH_MAX
}quec_net_dualch_e_t;

typedef struct 
{
    quec_net_dualch_status_e_t status;  /*connect,disconnect*/
    quec_net_dualch_e_t cid;            /*channel number*/
    char mac[20];                       /*mac addr*/
    quec_net_flag_e_t net_flag;         /*ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í£ï¿½ usb,app*/
}quec_net_dualch_cfg_s_t;

typedef struct 
{
    int atHandle;
    quec_net_dualch_cfg_s_t qnetdualchcfg;
}qnetdualch_msg_t;

typedef enum 
{
    QUEC_NETDUALCH_PDP_ACT_TYPE,        /*ï¿½ï¿½ï¿½ï¿½pdp*/
    QUEC_NETDUALCH_USB_BIND_TYPE,       /*ï¿½ï¿½usbï¿½ï¿½ï¿½ï¿½*/
    QUEC_NETDUALCH_APP_BIND_TYPE,       /*ï¿½ï¿½appï¿½ï¿½ï¿½ï¿½*/
    QUEC_NETDUALCH_SET_MAC_CID_TABLE,   /*ï¿½Â·ï¿½mac,cidÓ³ï¿½ï¿½ï¿½ï¿½lwip*/
    QUEC_NETDUALCH_TYPE_MAX
}quec_netdualch_msg_type_e;

typedef struct
{
    quec_netdualch_msg_type_e msg_type;
    uint8 data_len;
    uint8 *p_data;  /*malloc type need release*/
}quec_netdualch_msg_s;

typedef struct
{
    OSSemaRef atcmd_semphore;
    int issend;         /*0--not send atcmd_semphore,1--send atcmd_semphore*/
    int atcmd_result;   /*0--act ok,1--act fail,accord from quec_pdp_act_service() result cold*/ 
}quec_netdualch_atcmd_s;

/*Í³Ò»Ö¸ï¿½ï¿½ó£¬°ï¿½ï¿½ï¿½pdpï¿½ï¿½ï¿½î£¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Â·ï¿½mac cid tableï¿½ï¿½urcï¿½Ï±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½×¶ï¿½×´Ì¬*/
typedef enum 
{
    QUEC_QNETDUALCHCFG_PDP_ACT_URC,
    QUEC_QNETDUALCHCFG_NETIF_BIND_URC,
    QUEC_QNETDUALCHCFG_MAC_CID_URC,
    QUEC_QNETDUALCHCFG_MAX_URC
}quec_qnetdualchcfg_urc_e_t;

QuecOSStatus quec_net_dualch_cfg_mac_nwif_table(quec_net_dualch_cfg_s_t *pNetdualchcfg);
QuecOSStatus quec_netdualchcfg_process(quec_msg_process_s *pNetdualch);
//QuecOSStatus quec_disconnect_net_config(quec_net_dualch_cfg_s_t *pNetdualchcfg);
QuecOSStatus quec_connect_netif_config(quec_net_dualch_cfg_s_t *pNetdualchcfg);

int quec_get_net_flag_by_cid(int cid);
UINT8 quec_get_usb_forward_flag(void);
void quec_set_usb_forward_flag(UINT8 usb_forward_flag);
QuecOSStatus quec_qnetdualchcfg_urc_report(quec_qnetdualchcfg_urc_e_t urc_type,uint8 cid,uint8 is_success);
void quec_netdualchcfg_pdpdeacted_urc_report(void);
QuecOSStatus quec_netif_app_proc(quec_net_dualch_cfg_s_t *pNet_dualchcfg);
void quec_delete_semp(void);
//void quec_pdp_act_at_resp(UINT32 qnetatHandle,UINT8 is_ok);
void quec_netdualch_send_atcmd_semphore(int result,quec_netdualch_msg_type_e at_flag);


RETURNCODE_T quec_netdualch_cfg_cmd
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p                  /* AT cmd parser number         */
);

#endif
RETURNCODE_T quec_exec_qmnclk_cmd
(
    const utlAtParameterOp_T        op,                 /* AT cmd type          */
    const char                     *command_name_p,     /* AT cmd name          */
    const utlAtParameterValue_P2c   parameter_values_p, /* AT cmd value         */  
    const size_t                    num_parameters,     /* AT cmd number        */
    const char                     *info_text_p,        /* AT cmd usage string  */
    unsigned int                   *xid_p,              /* AT cmd handle        */   
    void                           *arg_p               /* AT cmd parser number */
);

#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
typedef enum 
{
	QUEC_ERR_CAUSE_MODE_DEFAULT = 0,
	QUEC_ERR_CAUSE_MODE_URC_EN,
	QUEC_ERR_CAUSE_CLEAR_CACHE ,
	QUEC_ERR_CAUSE_CLEAR_CACHE_URC_EN,
	QUEC_ERR_CAUSE_CONFIG_MAX
}QUEC_ERR_CAUSE_CONFIG;
	
#define QUEC_ERR_CAUSE_LEN     (128)
RETURNCODE_T  quec_exec_qceer_report
(
     const utlAtParameterOp_T        op,                    /* AT cmd type                  */
     const char                     *command_name_p,        /* AT cmd name                  */
     const utlAtParameterValue_P2c   parameter_values_p,    /* AT cmd value                 */
     const size_t                    num_parameters,        /* AT cmd number                */
     const char                     *info_text_p,           /* AT cmd usage string          */
     unsigned int                   *xid_p,                 /* AT cmd handle                */
     void                           *arg_p              /* AT cmd parser number         */
);
BOOL quec_get_err_cause_urc_en(void);
void quec_set_clear_err_cause(void);
#endif /* QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT */

#endif /* QUEC_ATCMD_GENERAL_H */
