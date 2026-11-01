/*--------------------------------------------------------------------------------------------------------------------
(C) Copyright 2006, 2007 Marvell DSPC Ltd. All Rights Reserved.
-------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
*  INTEL CONFIDENTIAL
*  Copyright 2006 Intel Corporation All Rights Reserved.
*  The source code contained or described herein and all documents related to the source code (“Material? are owned
*  by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
*  its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
*  Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
*  treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
*  transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.
*
*  No license under any patent, copyright, trade secret or other intellectual property right is granted to or
*  conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
*  estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
*  Intel in writing.
*  -------------------------------------------------------------------------------------------------------------------
*
*  Filename: telatparamdef.h
*
*  Authors:  Vincent Yeung
*
*  Description: Defines for AT Command Parameters
*
*  History:
*   May 19, 2006 - Creation of file
*
*  Notes:
*
******************************************************************************/



#ifndef TELATPARAMDEF_H
#define TELATPARAMDEF_H

#include "ci_mm.h"
#include "ci_ps.h"

#ifdef LWIP_IPNETBUF_SUPPORT
#if defined QUECTEL_PROJECT_CUST
#define TEL_AT_CMDSTR_MAX_LEN   1600
#else
#define TEL_AT_CMDSTR_MAX_LEN	(1024)
#endif
#else
#define TEL_AT_CMDSTR_MAX_LEN   (512)
#endif

#ifdef CRANE_MCU_DONGLE
#if defined QUECTEL_PROJECT_CUST
#define AUTH_PAP_CHAP_OPTIMIZE //add PAP or CHAP
#endif
#endif

#ifdef AUTH_PAP_CHAP_OPTIMIZE
#define AUTH_PAP_OR_CHAP_SUPPORT
#endif

#ifdef QUEC_ASR_SMS_ENABLE   /*Tery.shi 20181120 solve source address encoding problem*/
#define TEL_AT_MAX_ADDRESS_LENGTH (164 + 1)    /*1 for the '+'*/
#else
#define TEL_AT_MAX_ADDRESS_LENGTH (40 + 1)    /*1 for the '+'*/
#endif
#define TEL_AT_MAX_PASSWORD_LENGTH 16

/* AT+CVHU */
#define TEL_AT_CVHU_0_MODE_MIN      0
#define TEL_AT_CVHU_0_MODE_MAX      2
#define TEL_AT_CVHU_0_MODE_DEFAULT  2
#define TEL_AT_CVHU_0_MODE_0        0
#define TEL_AT_CVHU_0_MODE_1        1
#define TEL_AT_CVHU_0_MODE_2		2

/* AT+CACM */
#define TEL_AT_CACM_0_PASSWD_STR_DEFAULT        NULL
#define TEL_AT_CACM_0_PASSWD_STR_MAX_LEN        TEL_AT_MAX_PASSWORD_LENGTH

/* AT+CAMM */
#define CALL_METER_STR_LEN                      3
#define TEL_AT_CAMM_0_ACMMAX_STR_DEFAULT        NULL
#define TEL_AT_CAMM_0_ACMMAX_STR_MAX_LEN        CALL_METER_STR_LEN

#define TEL_AT_CAMM_1_PASSWD_STR_DEFAULT        NULL
#define TEL_AT_CAMM_1_PASSWD_STR_MAX_LEN        TEL_AT_MAX_PASSWORD_LENGTH

/* AT+CHLD */
#define TEL_AT_CHLD_0_N_VAL_MIN				ATCI_CHLD_MODE_0
#define TEL_AT_CHLD_0_N_VAL_MAX				(ATCI_CHLD_MODE_2X + 5)
#define TEL_AT_CHLD_0_N_VAL_DEFAULT			ATCI_CHLD_MODE_0

/* AT+CBST */
#define TEL_AT_CBST_0_SPEED_VAL_MIN				0
#define TEL_AT_CBST_0_SPEED_VAL_MAX				134
#define TEL_AT_CBST_0_SPEED_VAL_DEFAULT			7	/* 9600 bps */

#define TEL_AT_CBST_1_NAME_VAL_MIN				0
#define TEL_AT_CBST_1_NAME_VAL_MAX				7
#define TEL_AT_CBST_1_NAME_VAL_DEFAULT			0 /* for asynchronous modem */

#define TEL_AT_CBST_2_CE_VAL_MIN				0
#define TEL_AT_CBST_2_CE_VAL_MAX				3
#define TEL_AT_CBST_2_CE_VAL_DEFAULT			1 /* for the non-transparent */

/* AT+FCLASS */
#define TEL_AT_FCLASS_0_N_VAL_MIN				8
#define TEL_AT_FCLASS_0_N_VAL_MAX				8
#define TEL_AT_FCLASS_0_N_VAL_DEFAULT			8

#define TEL_AT_FCLASS_FAX						1 /* According to TS27.007, it should be 1 */
#define TEL_AT_FCLASS_DATA						0 /* According to TS27.007, it should be 0 */
#define TEL_AT_FCLASS_VOICE						8


/* AT+CMOD */
#define TEL_AT_CMOD_0_MODE_VAL_MIN				0
#define TEL_AT_CMOD_0_MODE_VAL_MAX				3
#define TEL_AT_CMOD_0_MODE_VAL_DEFAULT			0

/* AT+CLCC */

/* AT+CCFC */
#define TEL_AT_CCFC_0_REASON_VAL_MIN				0
#define TEL_AT_CCFC_0_REASON_VAL_MAX				5
#define TEL_AT_CCFC_0_REASON_VAL_DEFAULT			0

#define TEL_AT_CCFC_1_MODE_VAL_MIN				0
#define TEL_AT_CCFC_1_MODE_VAL_MAX				4
#define TEL_AT_CCFC_1_MODE_VAL_DEFAULT			0

#define TEL_AT_CCFC_2_NUMBER_STR_DEFAULT                NULL
#define TEL_AT_CCFC_2_NUMBER_STR_MAX_LEN                TEL_AT_MAX_ADDRESS_LENGTH

#define TEL_AT_CCFC_3_TYPE_VAL_MIN              0
#define TEL_AT_CCFC_3_TYPE_VAL_MAX              145
#define TEL_AT_CCFC_3_TYPE_VAL_DEFAULT          129

#define TEL_AT_CCFC_4_CLASSX_VAL_MIN                0
#define TEL_AT_CCFC_4_CLASSX_VAL_MAX                255
#define TEL_AT_CCFC_4_CLASSX_VAL_DEFAULT            7  /* CISS_BSMAP_DEFAULT */

#define TEL_AT_CCFC_5_SUBADDR_STR_DEFAULT       NULL
#define TEL_AT_CCFC_5_SUBADDR_STR_MAX_LEN       TEL_AT_MAX_ADDRESS_LENGTH

#define TEL_AT_CCFC_6_SATYPE_VAL_MIN              0
#define TEL_AT_CCFC_6_SATYPE_VAL_MAX              145
#define TEL_AT_CCFC_6_SATYPE_VAL_DEFAULT          128

#define TEL_AT_CCFC_7_TIME_VAL_MIN                1
#define TEL_AT_CCFC_7_TIME_VAL_MAX                30
#define TEL_AT_CCFC_7_TIME_VAL_DEFAULT            20 /* CI_CFNRY_TIMER_DEFAULT */


/* AT+CCWA */
#define TEL_AT_CCWA_0_N_VAL_MIN                0
#define TEL_AT_CCWA_0_N_VAL_MAX                1
#define TEL_AT_CCWA_0_N_VAL_DEFAULT            2  /* Empty */

#define TEL_AT_CCWA_1_MODE_VAL_MIN                0
#define TEL_AT_CCWA_1_MODE_VAL_MAX                2
#define TEL_AT_CCWA_1_MODE_VAL_DEFAULT            255 /* CCWA_MODE_DEFAULT, just to indicate not used*/

#define TEL_AT_CCWA_2_CLASSX_VAL_MIN                0
#define TEL_AT_CCWA_2_CLASSX_VAL_MAX                255
#define TEL_AT_CCWA_2_CLASSX_VAL_DEFAULT            7  /* CISS_BSMAP_DEFAULT */

/* AT+COLP */
#define TEL_AT_COLP_0_N_VAL_MIN                0
#define TEL_AT_COLP_0_N_VAL_MAX                1
#define TEL_AT_COLP_0_N_VAL_DEFAULT            0  /* disable */

/* AT+CLIP */
#define TEL_AT_CLIP_0_N_VAL_MIN                0
#define TEL_AT_CLIP_0_N_VAL_MAX                1
#define TEL_AT_CLIP_0_N_VAL_DEFAULT            0  /* disable */

/* AT+CLIR */
#define TEL_AT_CLIR_0_N_VAL_MIN                0
#define TEL_AT_CLIR_0_N_VAL_MAX                2
#define TEL_AT_CLIR_0_N_VAL_DEFAULT            0  /* disable */

/* AT+CNAP */
#define TEL_AT_CNAP_0_N_VAL_MIN                0
#define TEL_AT_CNAP_0_N_VAL_MAX                1
#define TEL_AT_CNAP_0_N_VAL_DEFAULT            0  /* disable */
/* AT+CAOC */
#define TEL_AT_CAOC_0_MODE_VAL_MIN                0
#define TEL_AT_CAOC_0_MODE_VAL_MAX                2
#define TEL_AT_CAOC_0_MODE_VAL_DEFAULT            0  /* query */

/* AT+VTS*/
#define TEL_AT_VTS_0_DTMF_STR_DEFAULT		NULL
#define TEL_AT_VTS_0_DTMF_STR_MAX_LEN		32

#define TEL_AT_VTS_1_DURATION_VAL_MIN		100
#define TEL_AT_VTS_1_DURATION_VAL_MAX		1000
#define TEL_AT_VTS_1_DURATION_VAL_DEFAULT	100

/* AT+CRLP - michal Bukai - modified the default, max and min values*/
#define TEL_AT_CRLP_0_IWS_VAL_MIN                0
#define TEL_AT_CRLP_0_IWS_VAL_MAX                61	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_0_IWS_VAL_DEFAULT            61  /*  */

#define TEL_AT_CRLP_1_MWS_VAL_MIN                0
#define TEL_AT_CRLP_1_MWS_VAL_MAX                61	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_1_MWS_VAL_DEFAULT            61  /*  */

#define TEL_AT_CRLP_2_T1_VAL_MIN                39
#define TEL_AT_CRLP_2_T1_VAL_MAX                255	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_2_T1_VAL_DEFAULT            48  /*  */

#define TEL_AT_CRLP_3_N2_VAL_MIN                1
#define TEL_AT_CRLP_3_N2_VAL_MAX                255	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_3_N2_VAL_DEFAULT            6  /*  */

#define TEL_AT_CRLP_4_VER_VAL_MIN                0
#define TEL_AT_CRLP_4_VER_VAL_MAX                1	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_4_VER_VAL_DEFAULT            1  /*  */

#define TEL_AT_CRLP_5_T4_VAL_MIN                3
#define TEL_AT_CRLP_5_T4_VAL_MAX                255	 /* please refer to TS 24.022 [18] */
#define TEL_AT_CRLP_5_T4_VAL_DEFAULT            3  /*  */

/* AT+CSSN */
#define TEL_AT_CSSN_0_N_VAL_MIN                0
#define TEL_AT_CSSN_0_N_VAL_MAX                1
#define TEL_AT_CSSN_0_N_VAL_DEFAULT            0  /* disable */

#define TEL_AT_CSSN_1_M_VAL_MIN                0
#define TEL_AT_CSSN_1_M_VAL_MAX                1
#define TEL_AT_CSSN_1_M_VAL_DEFAULT            0  /* disable */

/* AT+CUSD */
#define TEL_AT_CUSD_0_N_VAL_MIN                0
#define TEL_AT_CUSD_0_N_VAL_MAX                2
#define TEL_AT_CUSD_0_N_VAL_DEFAULT            0  /* disable */

#define TEL_AT_CUSD_1_STR_DEFAULT		NULL
#define TEL_AT_CUSD_1_STR_MAX_LEN		229	   /* CI_MAX_USSD_LENGTH */



#define TEL_AT_CUSD_2_DCS_VAL_MIN                0
//change the MAX value for +CUSD since <dcs>: 3GPP TS 23.038 [25] Cell Broadcast Data Coding Scheme in integer format (default 0)
//#define TEL_AT_CUSD_0_N_VAL_MAX                1
#define TEL_AT_CUSD_2_DCS_VAL_MAX                0xF7	/* 3GPP TS 23.038 [25] */

//Fitz.xu 20200907: use GSM7bit as default to fix BZASR-1191
//#define TEL_AT_CUSD_2_DCS_VAL_DEFAULT            0x11	/* default is UCS2*/
#define TEL_AT_CUSD_2_DCS_VAL_DEFAULT            0x10	/* default is GSM */



/* AT+CLCK */
#define TEL_AT_CLCK_0_FAC_STR_DEFAULT				NULL
#define TEL_AT_CLCK_0_FAC_STR_MAX_LEN				2	   /*  */

#define TEL_AT_CLCK_1_MODE_VAL_MIN                0
#define TEL_AT_CLCK_1_MODE_VAL_MAX                2
#define TEL_AT_CLCK_1_MODE_VAL_DEFAULT            0  /* unlock */

#define TEL_AT_CLCK_2_PASSWD_STR_DEFAULT                                NULL
#define TEL_AT_CLCK_2_PASSWD_STR_MAX_LEN                                TEL_AT_MAX_PASSWORD_LENGTH         /* CI_MAX_PASSWORD_LENGTH */

#define TEL_AT_CLCK_3_CLASSX_VAL_MIN                0
#define TEL_AT_CLCK_3_CLASSX_VAL_MAX                255
#define TEL_AT_CLCK_3_CLASSX_VAL_DEFAULT            7  /* CISS_BSMAP_DEFAULT */

/* AT+CCWE */
#define TEL_AT_CCWE_0_CLASSX_VAL_MIN                0
#define TEL_AT_CCWE_0_CLASSX_VAL_MAX                1
#define TEL_AT_CCWE_0_CLASSX_VAL_DEFAULT            0  /* disable */

/* AT+CPWD */
#define TEL_AT_CPWD_0_FAC_STR_DEFAULT				NULL
#define TEL_AT_CPWD_0_FAC_STR_MAX_LEN				2	   /*  */

#define TEL_AT_CPWD_1_OLDPW_STR_DEFAULT                         NULL
#define TEL_AT_CPWD_1_OLDPW_STR_MAX_LEN                         TEL_AT_MAX_PASSWORD_LENGTH         /*  */

#define TEL_AT_CPWD_2_NEWPW_STR_DEFAULT                         NULL
#define TEL_AT_CPWD_2_NEWPW_STR_MAX_LEN                         TEL_AT_MAX_PASSWORD_LENGTH         /*  */

#define TEL_AT_CPWD_3_NEWPWVER_STR_DEFAULT                              NULL
#define TEL_AT_CPWD_3_NEWPWVER_STR_MAX_LEN                              TEL_AT_MAX_PASSWORD_LENGTH         /*  */

/* AT+COPS */
#define TEL_AT_COPS_0_MODE_VAL_MIN                0
#define TEL_AT_COPS_0_MODE_VAL_MAX                5
#define TEL_AT_COPS_0_MODE_VAL_DEFAULT            0  /* disable */

#define TEL_AT_COPS_1_FORMAT_VAL_MIN                0
#define TEL_AT_COPS_1_FORMAT_VAL_MAX                4
#ifdef QUECTEL_NETWORK_SUPPORT  //connor.wu 2019/03/21
#define TEL_AT_COPS_1_FORMAT_VAL_DEFAULT            0  /*long format alphanumeric*/
#else
#define TEL_AT_COPS_1_FORMAT_VAL_DEFAULT            2  /* numeric */
#endif

#define TEL_AT_COPS_2_OPER_STR_DEFAULT				NULL
#define TEL_AT_COPS_2_OPER_STR_MAX_LEN				16	   /* ATCI_PLMN_LONG_NAME_LENGTH */

#define TEL_AT_COPS_3_ACT_VAL_MIN                	0
/* modified by zuohuaxu for LTE PC AT command 20120313, begin */
/* #define TEL_AT_COPS_3_ACT_VAL_MAX                    2 */
#define TEL_AT_COPS_3_ACT_VAL_MAX           CI_MM_NUM_ACT - 1
/* modified by zuohuaxu for LTE PC AT command 20120313, end */
#define TEL_AT_COPS_3_ACT_VAL_DEFAULT            	CI_MM_NUM_ACT  

#define TEL_AT_COPS_4_DOMAIN_VAL_MIN                	0
#define TEL_AT_COPS_4_DOMAIN_VAL_MAX             	2
#define TEL_AT_COPS_4_DOMAIN_VAL_DEFAULT          	1



/* AT+CPOL */
#define TEL_AT_CPOL_0_INDEX_VAL_MIN                1
#define TEL_AT_CPOL_0_INDEX_VAL_MAX                254
#define TEL_AT_CPOL_0_INDEX_VAL_DEFAULT            255 /*empty */
#ifdef QUECTEL_NETWORK_SUPPORT
#define TEL_AT_CPOL_0_INDEX_VAL_5                  5
#endif

#define TEL_AT_CPOL_1_FORMAT_VAL_MIN                0
#define TEL_AT_CPOL_1_FORMAT_VAL_MAX                2
#define TEL_AT_CPOL_1_FORMAT_VAL_DEFAULT            2  /* NUM*/

#define TEL_AT_CPOL_2_OPER_STR_DEFAULT				NULL
#define TEL_AT_CPOL_2_OPER_STR_MAX_LEN				16	   /* ATCI_PLMN_LONG_NAME_LENGTH */
/*Added by Michal Bukai - at support for AccTchMode parameter*/
#define TEL_AT_CPOL_3_GSM_ACT_VAL_MIN                0
#define TEL_AT_CPOL_3_GSM_ACT_VAL_MAX                1
#define TEL_AT_CPOL_3_GSM_ACT_VAL_DEFAULT            0

#define TEL_AT_CPOL_4_GSM_COMPACT_ACT_VAL_MIN                0
#define TEL_AT_CPOL_4_GSM_COMPACT_ACT_VAL_MAX                1
#define TEL_AT_CPOL_4_GSM_COMPACT_ACT_VAL_DEFAULT            0

#define TEL_AT_CPOL_5_UTRAN_ACT_VAL_MIN                0
#define TEL_AT_CPOL_5_UTRAN_ACT_VAL_MAX                1
#define TEL_AT_CPOL_5_UTRAN_ACT_VAL_DEFAULT            0

//mengliang add fror e-utran_act
#define TEL_AT_CPOL_6_EUTRAN_ACT_VAL_MIN                     0
#define TEL_AT_CPOL_6_EUTRAN_ACT_VAL_MAX                     1
#define TEL_AT_CPOL_6_EUTRAN_ACT_VAL_DEFAULT                 0

/* AT+CFUN */
#define TEL_AT_CFUN_0_FUN_VAL_MIN                0
#define TEL_AT_CFUN_0_FUN_VAL_MAX                127
#define TEL_AT_CFUN_0_FUN_VAL_DEFAULT            1  /* full functionality */

#define TEL_AT_CFUN_1_RST_VAL_MIN                0
#define TEL_AT_CFUN_1_RST_VAL_MAX                1
#define TEL_AT_CFUN_1_RST_VAL_DEFAULT            0 /* To be compatible with Anite GCF script, Phone will always be reset for both 0->1 or 1->0 power level setting circle. */


/*AT*CFUN - Add a generic comm. feature configuration option in CI_DEV_PRIM_SET_FUNC_REQ*/
#define TEL_AT_CFUN_2_EN_CONFIG_VAL_MIN                0
#define TEL_AT_CFUN_2_EN_CONFIG_VAL_MAX                1
#define TEL_AT_CFUN_2_EN_CONFIG_VAL_DEFAULT            0

#define TEL_AT_CFUN_3_CONFIG_VAL_MIN                0
#define TEL_AT_CFUN_3_CONFIG_VAL_MAX                63 /* bitmap for comm. configurations for CSD, FAX, PRODUCTION, CONVENTIONAL_GPS, MS_BASED_GPS, MS_ASSISTED_GPS */
#define TEL_AT_CFUN_3_CONFIG_VAL_DEFAULT            0


/* AT+CGED */
#define TEL_AT_CGED_0_MODE_VAL_MIN                0
#define TEL_AT_CGED_0_MODE_VAL_MAX                2
#define TEL_AT_CGED_0_MODE_VAL_DEFAULT            0  /* reprot the EM information once */

#define TEL_AT_CGED_1_INTERVAL_VAL_MIN                1
#define TEL_AT_CGED_1_INTERVAL_VAL_MAX                65535
#define TEL_AT_CGED_1_INTERVAL_VAL_DEFAULT            15 /* default time interval 15 seconds  */

#define TEL_AT_PSSDC_0_CID_VAL_MIN           0
#define TEL_AT_PSSDC_0_CID_VAL_MAX           15
#define TEL_AT_PSSDC_0_CID_VAL_DEFAULT           1

/*
*  PS Related
*/
#define TEL_AT_PS_CID_VAL_MAX 					(CI_PS_MAX_CID-1) /* CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM */
#define TEL_AT_PS_CID_VAL_DEFAULT 				1 /* CI_PS_MAX_PDP_CTX_NUM */

/* AT+CGATT */
#define TEL_AT_CGATT_0_STATE_VAL_MIN                0
#define TEL_AT_CGATT_0_STATE_VAL_MAX                1
#define TEL_AT_CGATT_0_STATE_VAL_DEFAULT            1  /* attached */

/* AT*CGATTC */
#define TEL_AT_CGATTC_0_STATE_VAL_MIN                0
#define TEL_AT_CGATTC_0_STATE_VAL_MAX                1
#define TEL_AT_CGATTC_0_STATE_VAL_DEFAULT            1  /* attached */

#define TEL_AT_CGATTC_1_CAUSE_VAL_MIN                0
#define TEL_AT_CGATTC_1_CAUSE_VAL_MAX                18
#define TEL_AT_CGATTC_1_CAUSE_VAL_DEFAULT            0  /* no cause */

/* AT+CGACT */
#define TEL_AT_CGACT_0_STATE_VAL_MIN                0
#define TEL_AT_CGACT_0_STATE_VAL_MAX                1
#define TEL_AT_CGACT_0_STATE_VAL_DEFAULT            1  /* activated */

#define TEL_AT_CGACT_1_CID_VAL_MIN                0
#define TEL_AT_CGACT_1_CID_VAL_MAX                TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGACT_1_CID_VAL_DEFAULT            TEL_AT_PS_CID_VAL_DEFAULT

/* AT+CGDATA */
#define TEL_AT_CGDATA_0_L2P_STR_DEFAULT                         "PPP"
#define TEL_AT_CGDATA_0_L2P_STR_MAX_LEN                         (TEL_AT_CMDSTR_MAX_LEN - ATCI_NULL_TERMINATOR_LENGTH)

#define TEL_AT_CGDATA_1_CID_VAL_MIN                0
#define TEL_AT_CGDATA_1_CID_VAL_MAX                TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGDATA_1_CID_VAL_DEFAULT            TEL_AT_PS_CID_VAL_DEFAULT

/* AT+CGDCONT */
#define TEL_AT_CGDCONT_0_CID_VAL_MIN                0
#define TEL_AT_CGDCONT_0_CID_VAL_MAX                TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGDCONT_0_CID_VAL_DEFAULT            TEL_AT_PS_CID_VAL_DEFAULT

#define TEL_AT_CGDCONT_1_PDPTYPE_STR_DEFAULT             "IP"
#define TEL_AT_CGDCONT_1_PDPTYPE_STR_MAX_LEN             (TEL_AT_CMDSTR_MAX_LEN - ATCI_NULL_TERMINATOR_LENGTH)

#define TEL_AT_CGDCONT_2_APN_STR_DEFAULT             NULL
#define TEL_AT_CGDCONT_2_APN_STR_MAX_LEN             100

#define TEL_AT_CGDCONT_3_PDPADDRESS_STR_DEFAULT             NULL
#define TEL_AT_CGDCONT_3_PDPADDRESS_STR_MAX_LEN             80 /* CI_PS_PDP_IP_V4_SIZE + CI_PS_PDP_IP_V6_SIZE */

#define TEL_AT_CGDCONT_4_DCOMP_VAL_MIN                0
#define TEL_AT_CGDCONT_4_DCOMP_VAL_MAX                3
#define TEL_AT_CGDCONT_4_DCOMP_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGDCONT_5_HCOMP_VAL_MIN                0
#define TEL_AT_CGDCONT_5_HCOMP_VAL_MAX                4
#define TEL_AT_CGDCONT_5_HCOMP_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MIN      0
#define TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_MAX      1
#define TEL_AT_CGDCONT_6_IPV4ADDRALLOC_VAL_DEFAULT  0

#if 0
#define TEL_AT_CGDCONT_7_EMERGENCYIND_VAL_MIN   0
#define TEL_AT_CGDCONT_7_EMERGENCYIND_VAL_MAX   1
#define TEL_AT_CGDCONT_7_EMERGENCYIND_VAL_DEFAULT   0
#else
#define TEL_AT_CGDCONT_7_REQTYPE_VAL_MIN   0
#define TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX   11  
#define TEL_AT_CGDCONT_7_REQTYPE_VAL_DEFAULT   0
/*Quectel modify: cgdcont=? req type max modify 1,but req type still can set 2,3,4*/
#define QUEC_TEL_AT_CGDCONT_7_REQTYPE_VAL_MAX 1
#endif

#define TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MIN   0
#define TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_MAX   2
#define TEL_AT_CGDCONT_8_PCSCFDISCOVERY_VAL_DEFAULT   0

#define TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MIN   0
#define TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_MAX   1
#define TEL_AT_CGDCONT_9_IMCNSIGFLAGIND_VAL_DEFAULT   0


/* AT+CEREG */
#define TEL_AT_CEREG_0_MODE_VAL_MIN							0
#define TEL_AT_CEREG_0_MODE_VAL_MAX							5
#define TEL_AT_CEREG_0_MODE_VAL_DEFAULT						0


/* AT+CGDSCONT */
#define TEL_AT_CGDSCONT_0_CID_VAL_MIN                0
#define TEL_AT_CGDSCONT_0_CID_VAL_MAX                TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGDSCONT_0_CID_VAL_DEFAULT            TEL_AT_PS_CID_VAL_DEFAULT

#define TEL_AT_CGDSCONT_1_PCID_VAL_MIN                0
#define TEL_AT_CGDSCONT_1_PCID_VAL_MAX                255
#define TEL_AT_CGDSCONT_1_PCID_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGDSCONT_2_DCOMP_VAL_MIN                0
#define TEL_AT_CGDSCONT_2_DCOMP_VAL_MAX                3
#define TEL_AT_CGDSCONT_2_DCOMP_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGDSCONT_3_HCOMP_VAL_MIN                0
#define TEL_AT_CGDSCONT_3_HCOMP_VAL_MAX                4
#define TEL_AT_CGDSCONT_3_HCOMP_VAL_DEFAULT            0  /*  */
/* AT*CGDFLT */
#define TEL_AT_CGDFLT_0_MODE_VAL_MIN							0
#define TEL_AT_CGDFLT_0_MODE_VAL_MAX							1
#define TEL_AT_CGDFLT_0_MODE_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_1_PDPTYPE_STR_DEFAULT             "IP"
#define TEL_AT_CGDFLT_1_PDPTYPE_STR_MAX_LEN             (TEL_AT_CMDSTR_MAX_LEN - ATCI_NULL_TERMINATOR_LENGTH)

#define TEL_AT_CGDFLT_2_APN_STR_DEFAULT             NULL
#define TEL_AT_CGDFLT_2_APN_STR_MAX_LEN             100

#define TEL_AT_CGDFLT_3_EMGIND_VAL_MIN							0
#define TEL_AT_CGDFLT_3_EMGIND_VAL_MAX							1
#define TEL_AT_CGDFLT_3_EMGIND_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_4_IPCPREQ_VAL_MIN							0
#define TEL_AT_CGDFLT_4_IPCPREQ_VAL_MAX							1
#define TEL_AT_CGDFLT_4_IPCPREQ_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_MIN							0
#define TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_MAX							1
#define TEL_AT_CGDFLT_5_PCSCFIPV6REQ_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_6_IMCNSIG_VAL_MIN							0
#define TEL_AT_CGDFLT_6_IMCNSIG_VAL_MAX							1
#define TEL_AT_CGDFLT_6_IMCNSIG_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_7_DNSIPV6_VAL_MIN							0
#define TEL_AT_CGDFLT_7_DNSIPV6_VAL_MAX							1
#define TEL_AT_CGDFLT_7_DNSIPV6_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_8_NWBEAR_VAL_MIN							0
#define TEL_AT_CGDFLT_8_NWBEAR_VAL_MAX							1
#define TEL_AT_CGDFLT_8_NWBEAR_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_MIN							0
#define TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_MAX							1
#define TEL_AT_CGDFLT_9_DSMIPV6HA_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_MIN							0
#define TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_MAX							1
#define TEL_AT_CGDFLT_10_DSMIPV6PREF_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_MIN							0
#define TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_MAX							1
#define TEL_AT_CGDFLT_11_DSMIPV6HAIPV4_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_12_IPVIANAS_VAL_MIN							0
#define TEL_AT_CGDFLT_12_IPVIANAS_VAL_MAX							1
#define TEL_AT_CGDFLT_12_IPVIANAS_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_13_IPVIADHCP_VAL_MIN							0
#define TEL_AT_CGDFLT_13_IPVIADHCP_VAL_MAX							1
#define TEL_AT_CGDFLT_13_IPVIADHCP_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_MIN							0
#define TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_MAX							1
#define TEL_AT_CGDFLT_14_PCSCFIPV4_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_15_DNSIPV4_VAL_MIN							0
#define TEL_AT_CGDFLT_15_DNSIPV4_VAL_MAX							1
#define TEL_AT_CGDFLT_15_DNSIPV4_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_16_MSISDN_VAL_MIN							0
#define TEL_AT_CGDFLT_16_MSISDN_VAL_MAX							1
#define TEL_AT_CGDFLT_16_MSISDN_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_17_IFOM_VAL_MIN							0
#define TEL_AT_CGDFLT_17_IFOM_VAL_MAX							1
#define TEL_AT_CGDFLT_17_IFOM_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_18_V4MTU_VAL_MIN							0
#define TEL_AT_CGDFLT_18_V4MTU_VAL_MAX							1
#define TEL_AT_CGDFLT_18_V4MTU_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_19_LOCALTFT_VAL_MIN							0
#define TEL_AT_CGDFLT_19_LOCALTFT_VAL_MAX							1
#define TEL_AT_CGDFLT_19_LOCALTFT_VAL_DEFAULT						0

#define TEL_AT_CGDFLT_20_ETIF_VAL_MIN							0
#define TEL_AT_CGDFLT_20_ETIF_VAL_MAX							1
#define TEL_AT_CGDFLT_20_ETIF_VAL_DEFAULT						0


#define TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_MIN                0
#define TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_MAX                1
#define TEL_AT_CGDSCONT_4_IMCNSIGFLAG_VAL_DEFAULT            0  /*  */

/* AT+CGQMIN */
#define TEL_AT_CGQMIN_0_CID_VAL_MIN                0
#define TEL_AT_CGQMIN_0_CID_VAL_MAX                255
#define TEL_AT_CGQMIN_0_CID_VAL_DEFAULT            0

#define TEL_AT_CGQMIN_1_PRECEDENCE_VAL_MIN                0
#define TEL_AT_CGQMIN_1_PRECEDENCE_VAL_MAX                255
#define TEL_AT_CGQMIN_1_PRECEDENCE_VAL_DEFAULT            0  /* 3GPP TS 23.107 [46] */

#define TEL_AT_CGQMIN_2_DELAY_VAL_MIN                0
#define TEL_AT_CGQMIN_2_DELAY_VAL_MAX                255
#define TEL_AT_CGQMIN_2_DELAY_VAL_DEFAULT            0  /*  3GPP TS 23.107 [46]*/

#define TEL_AT_CGQMIN_3_RELIABILITY_VAL_MIN                0
#define TEL_AT_CGQMIN_3_RELIABILITY_VAL_MAX                255
#define TEL_AT_CGQMIN_3_RELIABILITY_VAL_DEFAULT            0  /* 3GPP TS 23.107 [46] */

#define TEL_AT_CGQMIN_4_PEAK_VAL_MIN                0
#define TEL_AT_CGQMIN_4_PEAK_VAL_MAX                255
#define TEL_AT_CGQMIN_4_PEAK_VAL_DEFAULT            0  /*  3GPP TS 23.107 [46] */

#define TEL_AT_CGQMIN_5_MEAN_VAL_MIN                0
#define TEL_AT_CGQMIN_5_MEAN_VAL_MAX                255
#define TEL_AT_CGQMIN_5_MEAN_VAL_DEFAULT            0  /* 3GPP TS 23.107 [46] */

/* AT+CGQREQ */

#define TEL_AT_CGQREQ_0_CID_VAL_MIN                0
#define TEL_AT_CGQREQ_0_CID_VAL_MAX                255
#define TEL_AT_CGQREQ_0_CID_VAL_DEFAULT            0

/* AT+CGEQREQ and AT+CGEQMIN */
#define TEL_AT_CGEQREQ_0_CID_VAL_MIN                0
#define TEL_AT_CGEQREQ_0_CID_VAL_MAX                255
#define TEL_AT_CGEQREQ_0_CID_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGEQREQ_1_TRAFFIC_VAL_MIN                0
#define TEL_AT_CGEQREQ_1_TRAFFIC_VAL_MAX                4  /*  */
#define TEL_AT_CGEQREQ_1_TRAFFIC_VAL_DEFAULT            4  /*  CI_PS_3G_TRAFFIC_CLASS_SUBSCRIBED */

#define TEL_AT_CGEQREQ_2_MAX_UL_VAL_MIN                0
#define TEL_AT_CGEQREQ_2_MAX_UL_VAL_MAX                256000	 /* in kbs */
#define TEL_AT_CGEQREQ_2_MAX_UL_VAL_DEFAULT            0  /* (refer TS 24.008 [8] subclause 10.5.6.5 */

#define TEL_AT_CGEQREQ_3_MAX_DL_VAL_MIN                0
#define TEL_AT_CGEQREQ_3_MAX_DL_VAL_MAX                256000
#define TEL_AT_CGEQREQ_3_MAX_DL_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGEQREQ_4_GUA_UL_VAL_MIN                0
#define TEL_AT_CGEQREQ_4_GUA_UL_VAL_MAX                256000
#define TEL_AT_CGEQREQ_4_GUA_UL_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGEQREQ_5_GUA_DL_VAL_MIN                0
#define TEL_AT_CGEQREQ_5_GUA_DL_VAL_MAX                256000
#define TEL_AT_CGEQREQ_5_GUA_DL_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGEQREQ_6_DELORDER_VAL_MIN              	0
#define TEL_AT_CGEQREQ_6_DELORDER_VAL_MAX               2
#define TEL_AT_CGEQREQ_6_DELORDER_VAL_DEFAULT           2  /* CI_PS_3G_DLV_ORDER_SUBSCRIBED */

#define TEL_AT_CGEQREQ_7_MAXSDU_VAL_MIN                0
#define TEL_AT_CGEQREQ_7_MAXSDU_VAL_MAX                1520
#define TEL_AT_CGEQREQ_7_MAXSDU_VAL_DEFAULT            0  /*  subscribed value */

#define TEL_AT_CGEQREQ_8_SDUERR_VAL_MIN                0
#define TEL_AT_CGEQREQ_8_SDUERR_VAL_MAX                15 /* GPRS_SDU_ERROR_RATIO_RESERVED */
#define TEL_AT_CGEQREQ_8_SDUERR_VAL_DEFAULT            0  /* GPRS_SDU_ERROR_RATIO_SUBSCRIBED */

#define TEL_AT_CGEQREQ_9_RBERR_VAL_MIN                0
#define TEL_AT_CGEQREQ_9_RBERR_VAL_MAX                3
#define TEL_AT_CGEQREQ_9_RBERR_VAL_DEFAULT            0  /* GPRS_RESIDUAL_BER_SUBSCRIBED */

#define TEL_AT_CGEQREQ_10_DERSDU_VAL_MIN                0
#define TEL_AT_CGEQREQ_10_DERSDU_VAL_MAX                3
#define TEL_AT_CGEQREQ_10_DERSDU_VAL_DEFAULT            0  /*  */

#define TEL_AT_CGEQREQ_11_TRDELAY_VAL_MIN                0
#define TEL_AT_CGEQREQ_11_TRDELAY_VAL_MAX                1024	 /* ?? */
#define TEL_AT_CGEQREQ_11_TRDELAY_VAL_DEFAULT            0  /* refer TS 24.008 [8] subclause 10.5.6.5 */

#define TEL_AT_CGEQREQ_12_PRIORITY_VAL_MIN                0
#define TEL_AT_CGEQREQ_12_PRIORITY_VAL_MAX                3
#define TEL_AT_CGEQREQ_12_PRIORITY_VAL_DEFAULT            0  /*  CI_PS_3G_SDU_TRAFFIC_PRIORITY_SUBSCRIBED */
#define TEL_AT_CGEQREQ_13_SOURCEDESCRIPTOR_VAL_MIN                0
#define TEL_AT_CGEQREQ_13_SOURCEDESCRIPTOR_VAL_MAX                1
#define TEL_AT_CGEQREQ_13_SOURCEDESCRIPTOR_VAL_DEFAULT            0  /*  SourceStatisticDescriptor TRUE OR FALSE */

#define TEL_AT_CGEQREQ_14_SIGNALINDICATION_VAL_MIN                0
#define TEL_AT_CGEQREQ_14_SIGNALINDICATION_VAL_MAX                1
#define TEL_AT_CGEQREQ_14_SIGNALINDICATION_VAL_DEFAULT            0  /*  SignallingIndication   TRUE OR FALSE*/

/* Added by Daniel for LTE PC AT command server 20120201, begin */
#define TEL_AT_CGEQOS_QCI_MIN							0
#define TEL_AT_CGEQOS_QCI_MAX							9
#define TEL_AT_CGEQOS_QCI_DEFAULT						0

#define TEL_AT_CGEQOS_MIN_DLGBR							0
#define TEL_AT_CGEQOS_MAX_DLGBR							256000
#define TEL_AT_CGEQOS_DEFAULT_DLGBR						0

#define TEL_AT_CGEQOS_MIN_ULGBR							0
#define TEL_AT_CGEQOS_MAX_ULGBR							256000
#define TEL_AT_CGEQOS_DEFAULT_ULGBR						0

#define TEL_AT_CGEQOS_MIN_DLMBR							0
#define TEL_AT_CGEQOS_MAX_DLMBR							256000
#define TEL_AT_CGEQOS_DEFAULT_DLMBR						0

#define TEL_AT_CGEQOS_MIN_ULMBR							0
#define TEL_AT_CGEQOS_MAX_ULMBR							256000
#define TEL_AT_CGEQOS_DEFAULT_ULMBR						0


#define TEL_AT_CGEQOS_MIN_ARBMP							0
#define TEL_AT_CGEQOS_MAX_ARBMP							1
#define TEL_AT_CGEQOS_DEFAULT_ARBMP						0

#define TEL_AT_CGEQOS_MIN_APNDLNUM							0
#define TEL_AT_CGEQOS_MAX_APNDLNUM							256000
#define TEL_AT_CGEQOS_DEFAULT_APNDLNUM						0

#define TEL_AT_CGEQOS_MIN_APNUPNUM							0
#define TEL_AT_CGEQOS_MAX_APNUPNUM							256000
#define TEL_AT_CGEQOS_DEFAULT_APNUPNUM						0




#define TEL_AT_CGEREP_MIN_MODE							0
#define TEL_AT_CGEREP_MAX_MODE							2
#define TEL_AT_CGEREP_DEFAULT_MODE						0

#define TEL_AT_CGEREP_MIN_BFR							0
#define TEL_AT_CGEREP_MAX_BFR							1
#define TEL_AT_CGEREP_DEFAULT_BFR						0

#define TEL_AT_CVMODE_MIN_MODE							0
#define TEL_AT_CVMODE_MAX_MODE							3
#define	TEL_AT_CVMODE_DEFAULT_MODE						0

#define TEL_AT_CEMODE_MIN_MODE							0
#define TEL_AT_CEMODE_MAX_MODE							3
#define	TEL_AT_CEMODE_DEFAULT_MODE						0

#define TEL_AT_CGPIAF_IPV6ADDRFORMAT_VAL_MIN			0
#define TEL_AT_CGPIAF_IPV6ADDRFORMAT_VAL_MAX			1
#define TEL_AT_CGPIAF_IPV6ADDRFORMAT_VAL_DEFAULT		0

#define TEL_AT_CGPIAF_IPV6SUBNOTATION_VAL_MIN			0
#define TEL_AT_CGPIAF_IPV6SUBNOTATION_VAL_MAX			1
#define TEL_AT_CGPIAF_IPV6SUBNOTATION_VAL_DEFAULT		0

#define TEL_AT_CGPIAF_IPV6LEADZEROS_VAL_MIN				0
#define TEL_AT_CGPIAF_IPV6LEADZEROS_VAL_MAX				1
#define TEL_AT_CGPIAF_IPV6LEADZEROS_VAL_DEFAULT			0

#define TEL_AT_CGPIAF_IPV6COMPZEROS_VAL_MIN				0
#define TEL_AT_CGPIAF_IPV6COMPZEROS_VAL_MAX				1
#define TEL_AT_CGPIAF_IPV6COMPZEROS_VAL_DEFAULT			1

#define TEL_AT_CGCLASS_DEFAULT_CLASS        "A"
#define TEL_AT_CGCLASS_MAX_CLASS_LEN        2
/* AT*CGDFAUTH */
#define TEL_AT_CGDFAUTH_0_MODE_VAL_MIN							0
#define TEL_AT_CGDFAUTH_0_MODE_VAL_MAX							1
#define TEL_AT_CGDFAUTH_0_MODE_VAL_DEFAULT							1
#define TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_MIN							0
#define TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_MAX							(CI_PS_AUTHENTICATION_TYPE_NUM - 1)
#define TEL_AT_CGDFAUTH_1_AUTHPROT_VAL_DEFAULT							0

#define TEL_AT_CGDFAUTH_2_USERNAME_STR_DEFAULT             NULL
#define TEL_AT_CGDFAUTH_2_USERNAME_STR_MAX_LEN             200
#define TEL_AT_CGDFAUTH_3_PASSWORD_STR_DEFAULT             NULL
#define TEL_AT_CGDFAUTH_3_PASSWORD_STR_MAX_LEN             200

#define TEL_AT_CGDFAUTH_PARAM_MAX_COUNT			   3

/* Added by Daniel for LTE PC AT command server 20120201, end */

/* AT+VZWAPNE */
#define TEL_AT_VZWAPNE_0_WAPN_VAL_MIN							0
#define TEL_AT_VZWAPNE_0_WAPN_VAL_MAX							255
#define TEL_AT_VZWAPNE_0_WAPN_VAL_DEFAULT						0

#define TEL_AT_VZWAPNE_1_APNCL_VAL_MIN							1
#define TEL_AT_VZWAPNE_1_APNCL_VAL_MAX							5
#define TEL_AT_VZWAPNE_1_APNCL_VAL_DEFAULT						1

#define TEL_AT_VZWAPNE_2_APN_STR_DEFAULT             NULL
#define TEL_AT_VZWAPNE_2_APN_STR_MAX_LEN             100

#define TEL_AT_VZWAPNE_3_APNTYPE_STR_DEFAULT             "IPv6"
#define TEL_AT_VZWAPNE_3_APNTYPE_STR_MAX_LEN             100

#define TEL_AT_VZWAPNE_4_APNBEAR_STR_DEFAULT							"LTE"
#define TEL_AT_VZWAPNE_4_APNBEAR_STR_MAX_LEN						10

#define TEL_AT_VZWAPNE_5_APNED_STR_DEFAULT							NULL
#define TEL_AT_VZWAPNE_5_APNED_STR_MAX_LEN						10

#define TEL_AT_VZWAPNE_6_APNTIME_VAL_MIN							0
#define TEL_AT_VZWAPNE_6_APNTIME_VAL_MAX							2147483647
#define TEL_AT_VZWAPNE_6_APNTIME_VAL_DEFAULT						0

/* AT+CGSMS */
#define TEL_AT_CGSMS_0_SERVICE_VAL_MIN						0
#define TEL_AT_CGSMS_0_SERVICE_VAL_MAX						3
#define TEL_AT_CGSMS_0_SERVICE_VAL_DEFAULT					3 /* CI_MSG_MOSMS_SRV_CS_PREFERRED */

/* AT+CSIM */
#define TEL_AT_CSIM_0_LENGTH_VAL_MIN						0
#define TEL_AT_CSIM_0_LENGTH_VAL_MAX
#define TEL_AT_CSIM_0_LENGTH_VAL_DEFAULT					3 /* CI_MSG_MOSMS_SRV_CS_PREFERRED */

/*
 *  PB related
 */
#define TEL_AT_PB_INDEX_VAL_MIN                                         0
#define TEL_AT_PB_INDEX_VAL_MAX                                         65535
#define TEL_AT_PB_INDEX_VAL_DEFAULT                                     0

#define TELAT_CPBW_4_ISHIDDEN_MIN						0
#define TELAT_CPBW_4_ISHIDDEN_MAX						1
#define TELAT_CPBW_4_ISHIDDEN_DEFAULT					0

#define TELAT_CPBW_CATEGORY_INDEX_MIN					0
#define TELAT_CPBW_CATEGORY_INDEX_MAX					5
#define TELAT_CPBW_CATEGORY_INDEX_DEFAULT				TELAT_CPBW_CATEGORY_INDEX_MIN

#define TEL_AT_PB_CODING_MIN			0
#define TEL_AT_PB_CODING_MAX			1
#define TEL_AT_PB_CODING_DEFAULT			0
/* AT+CPBS */
#define TEL_AT_CPBS_0_STORAGE_STR_DEFAULT                               "ME"
#define TEL_AT_CPBS_0_STORAGE_STR_MAX_LEN                               4

#define TEL_AT_CPBS_1_PASSWORD_STR_DEFAULT				NULL
#define TEL_AT_CPBS_1_PASSWORD_STR_MAX_LEN                              TEL_AT_MAX_PASSWORD_LENGTH

/*
*  SMS Related
*/

#define TEL_SMS_MAX_ADDR_LEN TEL_AT_MAX_ADDRESS_LENGTH
#define TEL_AT_SMS_PDUMODE_MAX_LEN 232

#define TEL_AT_SMS_MAX_LEN 640
#define TEL_AT_SMS_TEXTMODE_MAX_LEN 75
#define TEL_AT_SMS_TEXTMODE_ADDR_MAX_LEN 32
#define TEL_AT_SMS_TEXTMODE_ADDRTYPE_MAX 255

#define TEL_AT_SMS_INDEX_VAL_MIN						0
#define TEL_AT_SMS_INDEX_VAL_MAX						255
#define TEL_AT_SMS_INDEX_VAL_DEFAULT					0

/*+CMRSS*/
#define TEL_AT_SMS_CMRSS_0_INDEX_VAL_MIN						0
#define TEL_AT_SMS_CMRSS_0_INDEX_VAL_MAX						255
#define TEL_AT_SMS_CMRSS_0_INDEX_VAL_DEFAULT					0

#define TEL_AT_SMS_CMRSS_1_INDEX_VAL_MIN						0
#define TEL_AT_SMS_CMRSS_1_INDEX_VAL_MAX						255
#define TEL_AT_SMS_CMRSS_1_INDEX_VAL_DEFAULT					0

#define TEL_AT_SMS_CMRSS_2_STATUS_VAL_MIN						0
#define TEL_AT_SMS_CMRSS_2_STATUS_VAL_MAX						4
#define TEL_AT_SMS_CMRSS_2_STATIS_VAL_DEFAULT					0


#define TEL_AT_SMS_MEM_STORE_INDEX_VAL_MIN						0
#define TEL_AT_SMS_MEM_STORE_INDEX_VAL_MAX						255
#define TEL_AT_SMS_MEM_STORE_INDEX_VAL_DEFAULT					0

#define TEL_AT_SMS_MEM_RECORD_INDEX_VAL_MIN						0
#define TEL_AT_SMS_MEM_RECORD_INDEX_VAL_MAX						255
#define TEL_AT_SMS_MEM_RECORD_INDEX_VAL_DEFAULT					0

#define TEL_AT_SMS_RECORD_COUNT_INDEX_VAL_MIN						0
#define TEL_AT_SMS_RECORD_COUNT_INDEX_VAL_MAX						255
#define TEL_AT_SMS_RECORD_COUNT_INDEX_VAL_DEFAULT					0

#define TEL_AT_SMS_MAX_RECORD_LENGTH						157


/* AT+CMGW */
#define TEL_AT_CMGW_1_STAT_VAL_MIN                                              0
#define TEL_AT_CMGW_1_STAT_VAL_MAX                                              3
#define TEL_AT_CMGW_1_STAT_VAL_DEFAULT                                          2
#define TEL_AT_CMGW_1_STAT_STR_DEFAULT                                          "STO UNSENT"

/* AT+CMGL */
#define TEL_AT_CMGL_0_STATE_VAL_MIN						0
#define TEL_AT_CMGL_0_STATE_VAL_MAX						255
#define TEL_AT_CMGL_0_STATE_VAL_DEFAULT					255

/* AT+CMGD */
//#define TEL_AT_SMS_INDEX_VAL_MIN						0
//#define TEL_AT_SMS_INDEX_VAL_MAX						255
//#define TEL_AT_SMS_INDEX_VAL_DEFAULT					0

#define TEL_AT_CMGD_1_DEFFLAG_VAL_MIN						0
#define TEL_AT_CMGD_1_DEFFLAG_VAL_MAX						4
#define TEL_AT_CMGD_1_DEFFLAG_VAL_DEFAULT					0

/* AT+CMGF */
#define TEL_AT_CMGF_0_MODE_VAL_MIN						0
#define TEL_AT_CMGF_0_MODE_VAL_MAX						1
#define TEL_AT_CMGF_0_MODE_VAL_DEFAULT					0

/* AT+CSMP */
#define TEL_AT_CSMP_0_FO_VAL_MIN						0
#define TEL_AT_CSMP_0_FO_VAL_MAX						63
#define TEL_AT_CSMP_0_FO_VAL_DEFAULT					1

#define TEL_AT_CSMP_1_VP_VAL_MIN						0
#define TEL_AT_CSMP_1_VP_VAL_MAX						255
#define TEL_AT_CSMP_1_VP_VAL_DEFAULT					167

#define TEL_AT_CSMP_2_PID_VAL_MIN						0
#define TEL_AT_CSMP_2_PID_VAL_MAX						1
#define TEL_AT_CSMP_2_PID_VAL_DEFAULT					0

#define TEL_AT_CSMP_3_DCS_VAL_MIN						0
/* Fitz.xu 20200330: to fix STASR1601-131 */
#if defined(QUEC_ASR_SMS_ENABLE)
#define TEL_AT_CSMP_3_DCS_VAL_MAX						255
#else
#define TEL_AT_CSMP_3_DCS_VAL_MAX						11
#endif
#define TEL_AT_CSMP_3_DCS_VAL_DEFAULT					0

#ifdef QUEC_ASR_SMS_ENABLE
/* AT+CSDH */
#define TEL_AT_CSDH_0_SHOW_VAL_MIN                      0
#define TEL_AT_CSDH_0_SHOW_VAL_MAX                      1
#define TEL_AT_CSDH_0_SHOW_VAL_DEFAULT                  0
#endif
/* AT+CSCB */
#define TEL_AT_CSCB_0_MODE_VAL_MIN						0
#define TEL_AT_CSCB_0_MODE_VAL_MAX						1
#define TEL_AT_CSCB_0_MODE_VAL_DEFAULT					0

#define TEL_AT_CSCB_1_MIDS_MAX_LENGTH                                              (TEL_AT_CMDSTR_MAX_LEN - ATCI_NULL_TERMINATOR_LENGTH)
#define TEL_AT_CSCB_2_DCSS_MAX_LENGTH                                              (TEL_AT_CMDSTR_MAX_LEN - ATCI_NULL_TERMINATOR_LENGTH)

/*AT*CSCB */
#define TEL_AT_CSCB_3_ENABLE_ALL_VAL_MIN                                         0
#define TEL_AT_CSCB_3_ENABLE_ALL_VAL_MAX                                         1
#define TEL_AT_CSCB_3_ENABLE_ALL_VAL_DEFAULT                                     0

#define TEL_AT_CSCB_4_DISABLE_DCSS_VAL_MIN                                       0
#define TEL_AT_CSCB_4_DISABLE_DCSS_VAL_MAX                                       1
#define TEL_AT_CSCB_4_DISABLE_DCSS_VAL_DEFAULT                                   0

/* AT+CNMI */
#define TEL_AT_CNMI_0_MODE_VAL_MIN						0
#define TEL_AT_CNMI_0_MODE_VAL_MAX						3
#define TEL_AT_CNMI_0_MODE_VAL_DEFAULT					0

#define TEL_AT_CNMI_1_MT_VAL_MIN						0
#define TEL_AT_CNMI_1_MT_VAL_MAX						3
#define TEL_AT_CNMI_1_MT_VAL_DEFAULT					0

#define TEL_AT_CNMI_2_BM_VAL_MIN						0
#define TEL_AT_CNMI_2_BM_VAL_MAX						3
#define TEL_AT_CNMI_2_BM_VAL_DEFAULT					0

#define TEL_AT_CNMI_3_DS_VAL_MIN						0
#define TEL_AT_CNMI_3_DS_VAL_MAX						2
#define TEL_AT_CNMI_3_DS_VAL_DEFAULT					0

#define TEL_AT_CNMI_4_BFR_VAL_MIN						0
#define TEL_AT_CNMI_4_BFR_VAL_MAX						1
#define TEL_AT_CNMI_4_BFR_VAL_DEFAULT					0

/* AT+CSMS */
#define TEL_AT_CSMS_0_SERVICE_VAL_MIN						0
#define TEL_AT_CSMS_0_SERVICE_VAL_MAX						127
#define TEL_AT_CSMS_0_SERVICE_VAL_DEFAULT					0/* CI_MSG_SERVICE_NORMAL */

/* AT+GETIP */
#define TEL_AT_IP_INDEX_VAL_MIN                                         1
#define TEL_AT_IP_INDEX_VAL_MAX                                         16
#define TEL_AT_IP_INDEX_VAL_DEFAULT                                     1


/* Danfeng: AT*CCIREG */
#define TEL_AT_CCIREG_0_N_VAL_MIN                0
#define TEL_AT_CCIREG_0_N_VAL_MAX                1
#define TEL_AT_CCIREG_0_N_VAL_DEFAULT            0  /* disable */

/* AT+CMMS */
#define TEL_AT_CMMS_MODE_VAL_MIN                 0
#define TEL_AT_CMMS_MODE_VAL_MAX                 2
#define TEL_AT_CMMS_MODE_VAL_DEFAULT             0


/* AT+CGREG */
#define TEL_AT_CGREG_MODE_0_N_VAL_MIN                 0
#define TEL_AT_CGREG_MODE_0_N_VAL_MAX                 3
#define TEL_AT_CGREG_MODE_0_N_VAL_DEFAULT             0

#ifndef REMOVE_CC 
#ifndef NO_AUDIO

/* Michal Bukai - AT+CMUT */
#define TEL_AT_CMUT_0_MODE_VAL_MIN						0
#define TEL_AT_CMUT_0_MODE_VAL_MAX						1
#define TEL_AT_CMUT_0_MODE_VAL_DEFAULT					0

#define ATCI_CMUT_NUM_MODE								2

#endif
#endif

/* Michal Bukai - AT+CPUC */
#define TEL_AT_CPUC_0_CURRENCY_STR_DEFAULT          NULL
#define TEL_AT_CPUC_0_CURRENCY_STR_MAX_LEN          3 /* CICC_MAX_CURR_LENGTH */

#define TEL_AT_CPUC_1_PPU_STR_DEFAULT               NULL
#define TEL_AT_CPUC_1_PPU_STR_MAX_LEN               8

#define TEL_AT_CPUC_2_PASSWD_STR_DEFAULT                NULL
#define TEL_AT_CPUC_2_PASSWD_STR_MAX_LEN                TEL_AT_MAX_PASSWORD_LENGTH

/* Michal Bukai - AT+CTZR */
#define TEL_AT_CTZR_MODE_VAL_MIN						0
#define TEL_AT_CTZR_MODE_VAL_MAX						1
#define TEL_AT_CTZR_MODE_VAL_DEFAULT					0

/*+PACSP*/
#define TEL_AT_PACSP_INDEX_VAL_MIN						0
#define TEL_AT_PACSP_INDEX_VAL_MAX						1
#define TEL_AT_PACSP_INDEX_VAL_DEFAULT					0


#define ATCI_CTZR_NUM_MODE						2

#define SWAP_NIBBLE(x) ((((x)<<4)&0xF0)+(((x)>>4)&0x0F))
#define SWAP_NIBBLE_INT(x)	((((x)&0x0F)*10)+(((x)>>4)&0x0F))

/* Michal Bukai - AT+CTZU */
#define TEL_AT_CTZU_MODE_VAL_MIN						0
#ifdef	QUECTEL_NETWORK_SUPPORT
#define TEL_AT_CTZU_MODE_VAL_MAX						3
#else
#define TEL_AT_CTZU_MODE_VAL_MAX						1
#endif
#define TEL_AT_CTZU_MODE_VAL_DEFAULT					0

#define ATCI_CTZU_NUM_MODE						2

/* AT+CTTY */
#define	TEL_AT_CTTY_STATUS_VAL_MIN				0	/* Voice. TTY is desabled*/
#define	TEL_AT_CTTY_STATUS_VAL_MAX				3	/* TTY is enabled */
#define	TEL_AT_CTTY_STATUS_VAL_DEFAULT			0
#define	TEL_AT_CTTY_BaudotRate_VAL_MIN			0	/* 45.45 */
#define	TEL_AT_CTTY_BaudotRate_VAL_MAX			1	/* 50 */
#define	TEL_AT_CTTY_BaudotRate_VAL_DEFAULT		0	/* 45.45 */
/* Michal Bukai - AT+CSTA */
#define TEL_AT_CSTA_ADDRESS_TYPE_VAL_MIN						0
#define TEL_AT_CSTA_ADDRESS_TYPE_VAL_MAX						241
#define TEL_AT_CSTA_ADDRESS_TYPE_VAL_DEFAULT					129

/* Michal Bukai - AT+CRC */
#define TEL_AT_CRC_MODE_VAL_MIN						0
#define TEL_AT_CRC_MODE_VAL_MAX						1
#define TEL_AT_CRC_MODE_VAL_DEFAULT					0

/* Michal Bukai - AT+CR */
#define TEL_AT_CR_MODE_VAL_MIN						0
#define TEL_AT_CR_MODE_VAL_MAX						1
#define TEL_AT_CR_MODE_VAL_DEFAULT					0

/* Michal Bukai - AT+CMEE */
#define TEL_AT_CMEE_MODE_VAL_MIN						0
#define TEL_AT_CMEE_MODE_VAL_MAX						2
#define TEL_AT_CMEE_MODE_VAL_DEFAULT                                    1
/* Michal Bukai - AT+CIND */
#define TEL_AT_CIND_SIGNAL_VAL_MIN                  0
#define TEL_AT_CIND_SIGNAL_VAL_MAX                  5
#define TEL_AT_CIND_SIGNAL_VAL_DEFAULT              0

#define TEL_AT_CIND_SERVICE_VAL_MIN                 0
#define TEL_AT_CIND_SERVICE_VAL_MAX                 1
#define TEL_AT_CIND_SERVICE_VAL_DEFAULT             0

#define TEL_AT_CIND_MESSAGE_VAL_MIN                 0
#define TEL_AT_CIND_MESSAGE_VAL_MAX                 1
#define TEL_AT_CIND_MESSAGE_VAL_DEFAULT             0

#define TEL_AT_CIND_CALL_VAL_MIN                    0
#define TEL_AT_CIND_CALL_VAL_MAX                    1
#define TEL_AT_CIND_CALL_VAL_DEFAULT                0

#define TEL_AT_CIND_ROAM_VAL_MIN                    0
#define TEL_AT_CIND_ROAM_VAL_MAX                    1
#define TEL_AT_CIND_ROAM_VAL_DEFAULT                0

/* Michal Bukai - AT+CMER - only parameter #4 (ind) is configurable */
#define TEL_AT_CMER_MODE_VAL_DEFAULT              	3
#define TEL_AT_CMER_KEY_VAL_DEFAULT                	0
#define TEL_AT_CMER_DIS_VAL_DEFAULT                	0
#define TEL_AT_CMER_BUFFER_VAL_DEFAULT              0

#define TEL_AT_CMER_IND_VAL_MIN                    	0
#define TEL_AT_CMER_IND_VAL_MAX                    	2
#define TEL_AT_CMER_IND_VAL_DEFAULT                	0

#define TEL_AT_CMER_IND_MODE1                    	1
#define TEL_AT_CMER_IND_MODE2                    	2
/* Michal Bukai - AT+CGCMOD */
#define TEL_AT_CGCMOD_CID_VAL_MIN				 	0
#define TEL_AT_CGCMOD_CID_VAL_MAX                	TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGCMOD_CID_VAL_DEFAULT            	0
/* Michal Bukai - AT+DS */
#define TEL_AT_DS_0_P0_VAL_MIN                	0
#define TEL_AT_DS_0_P0_VAL_MAX                	3
#define TEL_AT_DS_0_P0_VAL_DEFAULT            	3

#define TEL_AT_DS_1_N_VAL_MIN                	0
#define TEL_AT_DS_1_N_VAL_MAX                	1
#define TEL_AT_DS_1_N_VAL_DEFAULT            	0

#define TEL_AT_DS_2_P1_VAL_MIN                	512
#define TEL_AT_DS_2_P1_VAL_MAX                	65535
#define TEL_AT_DS_2_P1_VAL_DEFAULT            	512

#define TEL_AT_DS_3_P2_VAL_MIN                	6
#define TEL_AT_DS_3_P2_VAL_MAX                	250
#define TEL_AT_DS_3_P2_VAL_DEFAULT            	6
/* Michal Bukai - AT+CDIP */
#define TEL_AT_CDIP_0_N_VAL_MIN                0
#define TEL_AT_CDIP_0_N_VAL_MAX                1
#define TEL_AT_CDIP_0_N_VAL_DEFAULT            0  /* disable */
/* Michal Bukai - AT+CPLS */
#define TEL_AT_CPLS_0_LIST_VAL_MIN					0
#define TEL_AT_CPLS_0_LIST_VAL_MAX					2
#define TEL_AT_CPLS_0_LIST_VAL_DEFAULT            	0
/* Michal Bukai - AT+CGTFT */
#define TEL_AT_CGTFT_CID_VAL_MIN					0
#define TEL_AT_CGTFT_CID_VAL_MAX					TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGTFT_CID_VAL_DEFAULT            	TEL_AT_PS_CID_VAL_DEFAULT

#define TEL_AT_CGTFT_PFID_VAL_MIN					1
#define TEL_AT_CGTFT_PFID_VAL_MAX           16
#define TEL_AT_CGTFT_PFID_VAL_DEFAULT            	0

#define TEL_AT_CGTFT_EPINDEX_VAL_MIN					0
#define TEL_AT_CGTFT_EPINDEX_VAL_MAX					255
#define TEL_AT_CGTFT_EPINDEX_VAL_DEFAULT            	0

#define TEL_AT_CGTFT_ADDRESS_STR_MIN_LEN				0
#define TEL_AT_CGTFT_ADDRESS_STR_MAX_LEN				128
#define TEL_AT_CGTFT_ADDRESS_STR_DEFAULT            	NULL

#define TEL_AT_CGTFT_PROTOCOLNUM_VAL_MIN					0
#define TEL_AT_CGTFT_PROTOCOLNUM_VAL_MAX					255
#define TEL_AT_CGTFT_PROTOCOLNUM_VAL_DEFAULT            	0

#define TEL_AT_CGTFT_PORT_STR_MAX_LEN                           12
#define TEL_AT_CGTFT_PORT_STR_DEFAULT            	NULL

#define TEL_AT_CGTFT_IPSEC_STR_MAX_LEN				9
#define TEL_AT_CGTFT_IPSEC_STR_DEFAULT            	NULL

#define TEL_AT_CGTFT_TOS_STR_MAX_LEN				8
#define TEL_AT_CGTFT_TOS_STR_DEFAULT            	NULL

#define TEL_AT_CGTFT_FLOWLABLE_STR_MAX_LEN				6
#define TEL_AT_CGTFT_FLOWLABLE_STR_DEFAULT            	NULL

/* Added by Daniel for LTE PC AT command server 20120312, begin */
#define TEL_AT_CGTFT_DIRECTION_MIN				    0
#define TEL_AT_CGTFT_DIRECTION_MAX                  3
#define TEL_AT_CGTFT_DIRECTION_DEFAULT            	0
/* Added by Daniel for LTE PC AT command server 20120312, end */

#define TEL_AT_MEP_CLCK_0_FAC_STR_DEFAULT				NULL
#define TEL_AT_MEP_CLCK_0_FAC_STR_MAX_LEN				2	   /*  */
#define TEL_AT_MEP_CLCK_1_MODE_VAL_MIN                0
#define TEL_AT_MEP_CLCK_1_MODE_VAL_MAX                2
#define TEL_AT_MEP_CLCK_1_MODE_VAL_DEFAULT            2  /*query*/
#define TEL_AT_MEP_CLCK_2_PASSWD_STR_DEFAULT				NULL
#define TEL_AT_MEP_CLCK_2_PASSWD_STR_MAX_LEN                            TEL_AT_MAX_PASSWORD_LENGTH              /* CI_MAX_PASSWORD_LENGTH */
#define TEL_AT_ULCK_0_FAC_VAL_MIN                0
#define TEL_AT_ULCK_0_FAC_VAL_MAX                1
#define TEL_AT_ULCK_0_FAC_VAL_DEFAULT            0
#define TEL_AT_ULCK_1_MODE_VAL_MIN                0
#define TEL_AT_ULCK_1_MODE_VAL_MAX                2
#define TEL_AT_ULCK_1_MODE_VAL_DEFAULT            2  /*query*/
#define TEL_AT_ULCK_2_PASSWD_STR_DEFAULT				NULL
#define TEL_AT_ULCK_2_PASSWD_STR_MAX_LEN				16	   /* CI_MAX_PASSWORD_LENGTH */
#define TEL_AT_UCPWD_PASSWD_STR_DEFAULT				NULL
#define TEL_AT_UCPWD_PASSWD_STR_MAX_LEN				16	   /* CI_MAX_PASSWORD_LENGTH */
#define TEL_AT_UASLM_0_OPER_VAL_MIN                0
#define TEL_AT_UASLM_0_OPER_VAL_MAX                3
#define TEL_AT_UASLM_0_OPER_VAL_DEFAULT            3  /*query*/
#define TEL_AT_UASLM_1_ICCID_STR_DEFAULT				NULL
#define TEL_AT_UASLM_1_ICCID_STR_MAX_LEN				10	   /* CI_SIM_UDP_ICCID_LEN */
/* Michal Bukai - AT*BAND */
#define TEL_AT_BAND_NW_MODE_VAL_MIN         0
#define TEL_AT_BAND_NW_MODE_VAL_MAX         18
#define TEL_AT_BAND_NW_MODE_VAL_DEFAULT     0xf0

#define TEL_AT_LTEBAND_NW_MODE_VAL_MIN         0
#define TEL_AT_LTEBAND_NW_MODE_VAL_MAX         64
#define TEL_AT_LTEBAND_NW_MODE_VAL_DEFAULT     0x0
#define TEL_AT_BAND_NW_BAND_TYPE_VAL_MIN         0
#define TEL_AT_BAND_NW_BAND_TYPE_VAL_MAX         2
#define TEL_AT_BAND_NW_BAND_TYPE_VAL_DEFAULT     0


#define TEL_AT_BAND_BAND_VAL_MIN					0
#define TEL_AT_BAND_BAND_VAL_MAX					0x7fffffff
#define TEL_AT_BAND_BAND_VAL_DEFAULT            	0

#define TEL_AT_BAND_ROAMING_CONFIG_VAL_MIN         0
#define TEL_AT_BAND_ROAMING_CONFIG_VAL_MAX         2
#define TEL_AT_BAND_ROAMING_CONFIG_VAL_DEFAULT     2

#define TEL_AT_BAND_SRV_DOMAIN_VAL_MIN             0
#define TEL_AT_BAND_SRV_DOMAIN_VAL_MAX             4
#define TEL_AT_BAND_SRV_DOMAIN_VAL_DEFAULT         4

#define TEL_AT_BAND_BAND_PRIORITY_VAL_MIN             0
#define TEL_AT_BAND_BAND_PRIORITY_VAL_MAX             2
#define TEL_AT_BAND_BAND_PRIORITY_VAL_DEFAULT         0


#define TEL_AT_BANSELCT_CMD_TYPE_MIN          0
#define TEL_AT_BANSELCT_CMD_TYPE_MAX          2
#define TEL_AT_BANSELCT_CMD_TYPE_DEFAULT          1

#define TEL_AT_BANSELCT_BAND_TYPE_MIN          0
#define TEL_AT_BANSELCT_BAND_TYPE_MAX          50
#define TEL_AT_BANSELCT_BAND_TYPE_DEFAULT          0

/* AT*L1DEBUG*/
#define TEL_AT_L1DEBUG_ADDRESS_STR_MIN_LEN				0
#define TEL_AT_L1DEBUG_ADDRESS_STR_MAX_LEN				10
#define TEL_AT_L1DEBUG_ADDRESS_STR_DEFAULT            	NULL


/* Michal Bukai - AT*BANDIND */
#define TEL_AT_BANDIND_MODE_VAL_MIN						0
#define TEL_AT_BANDIND_MODE_VAL_MAX						1
#define TEL_AT_BANDIND_MODE_VAL_DEFAULT            		0
/* Michal Bukai - AT*READ_CAL_STATUS */
#define TEL_AT_CAL_STATUS_VAL_MIN					0
#define TEL_AT_CAL_STATUS_VAL_MAX					1
#define TEL_AT_CAL_STATUS_VAL_DEFAULT            	0
/* Michal Bukai - AT*CNMA */
#define TEL_AT_NEW_MSG_ACK_VAL_MIN					0
#define TEL_AT_NEW_MSG_ACK_VAL_MAX					2
#define TEL_AT_NEW_MSG_ACK_VAL_DEFAULT            	0
#define TEL_AT_CNMA_0_N_VAL_MIN                                      0
#define TEL_AT_CNMA_0_N_VAL_MAX                                      2
#define TEL_AT_CNMA_0_N_VAL_DEFAULT                                  0
#define TEL_AT_CNMA_1_LEN_VAL_MIN                                    0
#define TEL_AT_CNMA_1_LEN_VAL_MAX                                    180 /* CI_MAX_CI_MSG_PDU_SIZE */
#define TEL_AT_CNMA_1_LEN_VAL_DEFAULT                                0
/* AT*POWERIND */
#define TEL_AT_POWERIND_MODE_VAL_MIN                                             0
#define TEL_AT_POWERIND_MODE_VAL_MAX                                             1
#define TEL_AT_POWERIND_MODE_VAL_DEFAULT                         1
/* AT+WS46 */
#define TEL_AT_WIRELESS_NW_MODE_VAL_MIN                    12
#define TEL_AT_WIRELESS_NW_MODE_VAL_MAX                    32
#define TEL_AT_WIRELESS_NW_MODE_VAL_DEFAULT                    12

/* AT+LPOTDOAREQ */
#define TEL_AT_LPOTDOAREQ_LEN_VAL_MIN 0
#define TEL_AT_LPOTDOAREQ_LEN_VAL_MAX 4096
#define TEL_AT_LPOTDOAREQ_LEN_VAL_DEFAULT 2660
#define TEL_AT_LPOTDOAREQ_COUNT_VAL_MIN 0
#define TEL_AT_LPOTDOAREQ_COUNT_VAL_MAX 6
#define TEL_AT_LPOTDOAREQ_COUNT_VAL_DEFAULT 0


/*   AT+OPERCFG */

#define TEL_AT_OPERCFG_FEATUREID_VAL_MIN  0
#define TEL_AT_OPERCFG_FEATUREID_VAL_MAX  0x7fffffff
#define TEL_AT_OPERCFG_FEATUREID_VAL_DEFAULT 0

#define TEL_AT_OPERCFG_FEATURE_VALUE_VAL_MIN  0
#if QUECTEL_PROJECT_CUST
#define TEL_AT_OPERCFG_FEATURE_VALUE_VAL_MAX  0xffffffff
#else
#define TEL_AT_OPERCFG_FEATURE_VALUE_VAL_MAX  0x7fffffff
#endif
#define TEL_AT_OPERCFG_FEATURE_VALUE_VAL_DEFAULT 0


/* AT+C */

/* AT+C */

/* AT+EEMOPT */
#define TEL_AT_EEMOPT_0_MODE_VAL_MIN                0
#define TEL_AT_EEMOPT_0_MODE_VAL_MAX                4
#define TEL_AT_EEMOPT_0_MODE_VAL_DEFAULT            0  /* Turn off indicator*/

#define TEL_AT_EEMOPT_1_INTERVAL_VAL_MIN                1
#define TEL_AT_EEMOPT_1_INTERVAL_VAL_MAX                65535
#define TEL_AT_EEMOPT_1_INTERVAL_VAL_DEFAULT            15 /* default time interval 15 seconds  */

/*EEMNCELL*/
#define TEL_AT_EEMNCELL_0_MODE_VAL_MIN                0
#define TEL_AT_EEMNCELL_0_MODE_VAL_MAX                1
#define TEL_AT_EEMNCELL_0_MODE_VAL_DEFAULT            0  /* Turn off indicator*/

#define TEL_AT_EEMNCELL_1_INTERVAL_VAL_MIN                1
#define TEL_AT_EEMNCELL_1_INTERVAL_VAL_MAX                65535
#define TEL_AT_EEMNCELL_1_INTERVAL_VAL_DEFAULT            15 /* default time interval 15 seconds  */


/* AT+ECHUPVT for Video telephony */
#define TEL_AT_ECHUPVT_CAUSE_VAL_MIN      0   /* unknown */
#define TEL_AT_ECHUPVT_CAUSE_VAL_MAX      127 /* TS24.008 Cause value 127 interworking, unspecified */
#define TEL_AT_ECHUPVT_CAUSE_VAL_DEFAULT  0    /* unknown */

//#ifdef AT_PRODUCTION_CMNDS
/*Michal Bukai - AT*AUTHReq support*/
#define TEL_AT_AUTH_0_CID_VAL_MIN                0
#define TEL_AT_AUTH_0_CID_VAL_MAX                TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_AUTH_0_CID_VAL_DEFAULT            TEL_AT_PS_CID_VAL_DEFAULT

#define TEL_AT_AUTH_1_TYPE_VAL_MIN                0
#define TEL_AT_AUTH_1_TYPE_VAL_MAX                (CI_PS_AUTHENTICATION_TYPE_NUM - 1)
#define TEL_AT_AUTH_1_TYPE_VAL_DEFAULT            0

#define TEL_AT_AUTH_2_USERNAME_STR_MIN_LEN				0
#define TEL_AT_AUTH_2_USERNAME_STR_MAX_LEN				200 
#define TEL_AT_AUTH_2_USERNAME_STR_DEFAULT            	NULL

#define TEL_AT_AUTH_3_PASSWORD_STR_MIN_LEN				0
#define TEL_AT_AUTH_3_PASSWORD_STR_MAX_LEN				200
#define TEL_AT_AUTH_3_PASSWORD_STR_DEFAULT            	NULL
/* AT*GSMTR */
#define TEL_AT_GSMTR_OPTION_MAX                  3
#define TEL_AT_GSMTR_OPTION_MIN                  0
#define TEL_AT_GSMTR_OPTION_DEFAULT              0
#define TEL_AT_GSMTR_BAND_MODE_MAX               127
#define TEL_AT_GSMTR_BAND_MODE_MIN               1
#define TEL_AT_GSMTR_BAND_MODE_DEFAULT           1
#define TEL_AT_GSMTR_ARFCN_MAX                   1023
#define TEL_AT_GSMTR_ARFCN_MIN                   0
#define TEL_AT_GSMTR_ARFCN_DEFAULT               0
#define TEL_AT_GSMTR_AFCDAC_MAX                  32000
#define TEL_AT_GSMTR_AFCDAC_MIN                  5000
#define TEL_AT_GSMTR_AFCDAC_DEFAULT              5000
#define TEL_AT_GSMTR_TXRAMP_SCALE_MAX            1023
#define TEL_AT_GSMTR_TXRAMP_SCALE_MIN            0
#define TEL_AT_GSMTR_TXRAMP_SCALE_DEFAULT        200
#define TEL_AT_GSMTR_RXGAIN_CODE_MAX             49
#define TEL_AT_GSMTR_RXGAIN_CODE_MIN             0
#define TEL_AT_GSMTR_RXGAIN_CODE_DEFAULT         0

//#endif /* AT_PRODUCTION_CMNDS */

//Michal Bukai - AT*CellLock
#define TEL_AT_CELLLOCK_0_MODE_VAL_MIN						0
#define TEL_AT_CELLLOCK_0_MODE_VAL_MAX						3
#define TEL_AT_CELLLOCK_0_MODE_VAL_DEFAULT					TEL_AT_CELLLOCK_0_MODE_VAL_MIN

#if 0
#define TEL_AT_CELLLOCK_1_ACT_VAL_MIN						0 //gsm
#define TEL_AT_CELLLOCK_1_ACT_VAL_MAX						2 //umts
#define TEL_AT_CELLLOCK_1_ACT_VAL_DEFAULT					TEL_AT_CELLLOCK_1_ACT_VAL_MIN

//according to CiGsmBandsType
#define TEL_AT_CELLLOCK_2_BAND_VAL_MIN						0
#define TEL_AT_CELLLOCK_2_BAND_VAL_MAX						255
#define TEL_AT_CELLLOCK_2_BAND_VAL_DEFAULT					TEL_AT_CELLLOCK_2_BAND_VAL_MIN
#endif

#define TEL_AT_CELLLOCK_3_ARFCN_VAL_MIN						0
#define TEL_AT_CELLLOCK_3_ARFCN_VAL_MAX						0xffff
#define TEL_AT_CELLLOCK_3_ARFCN_VAL_DEFAULT					TEL_AT_CELLLOCK_3_ARFCN_VAL_MIN


#define TEL_AT_CELLLOCK_4_SC_VAL_MIN						0
#define TEL_AT_CELLLOCK_4_SC_VAL_MAX						127
#define TEL_AT_CELLLOCK_4_SC_VAL_DEFAULT					TEL_AT_CELLLOCK_4_SC_VAL_MIN

#define TEL_AT_CELLLOCK_5_TDDOFFSET_STR_MAX_LEN				4
#define TEL_AT_CELLLOCK_5_TDDOFFSET_STR_DEFAULT				"-85"
#define TEL_AT_CELLLOCK_5_TDDOFFSET_VAL_MIN					-115
#define TEL_AT_CELLLOCK_5_TDDOFFSET_VAL_MAX					-25
#define TEL_AT_CELLLOCK_MODE_MIN 		0
#define TEL_AT_CELLLOCK_MODE_MAX 		4
#define TEL_AT_CELLLOCK_MODE_DEFAULT 	0

#define TEL_AT_CELLLOCK_ACT_MIN   	0
#define TEL_AT_CELLLOCK_ACT_MAX   	3
#define TEL_AT_CELLLOCK_ACT_DEFAULT 	0

#define TEL_AT_CELLLOCK_BAND_MIN   	0
#define TEL_AT_CELLLOCK_BAND_MAX   	64
#define TEL_AT_CELLLOCK_BAND_DEFAULT 	0

#define TEL_AT_CELLLOCK_FREQ_MIN   	0
#define TEL_AT_CELLLOCK_FREQ_MAX   	65535
#define TEL_AT_CELLLOCK_FREQ_DEFAULT 	0

#define TEL_AT_CELLLOCK_CELLID_MIN   	0
#define TEL_AT_CELLLOCK_CELLID_MAX   	32767
#define TEL_AT_CELLLOCK_CELLID_DEFAULT 	0

/* macros for Cell Lock */
#define UARFCN_A_BAND_MIN       10054
#define UARFCN_A_BAND_MAX       10121
#define UARFCN_F_BAND_MIN       9404
#define UARFCN_F_BAND_MAX       9596
#define INVALID_UARFCN          0xFFFF

#define MAX_CELL_PARAMETER_ID   127
#define INVALID_CELL_PARAM_ID   0xFF

#define EARFCN_38_BAND_MIN      37750
#define EARFCN_38_BAND_MAX      38249
#define EARFCN_40_BAND_MIN      38650
#define EARFCN_40_BAND_MAX      39649

#define MAX_EUTRAN_CELL_ID      503
//AT*CELL
#define TEL_AT_CELL_0_MODE_VAL_MIN						0
#define TEL_AT_CELL_0_MODE_VAL_MAX						1
#define TEL_AT_CELL_0_MODE_VAL_DEFAULT					        TEL_AT_CELL_0_MODE_VAL_MIN

#define TEL_AT_CELL_1_ACT_VAL_MIN						0 //gsm
#define TEL_AT_CELL_1_ACT_VAL_MAX						3 //umts
#define TEL_AT_CELL_1_ACT_VAL_DEFAULT					        TEL_AT_CELL_1_ACT_VAL_MIN

//according to CiGsmBandsType
#define TEL_AT_CELL_2_GSM_BAND_VAL_MIN						0
#define TEL_AT_CELL_2_GSM_BAND_VAL_MAX						255
#define TEL_AT_CELL_2_GSM_BAND_VAL_DEFAULT					TEL_AT_CELL_2_GSM_BAND_VAL_MIN

//according to CiUmtsBandsType
#define TEL_AT_CELL_3_UMTS_BAND_VAL_MIN				        0
#define TEL_AT_CELL_3_UMTS_BAND_VAL_MAX				        8
#define TEL_AT_CELL_3_UMTS_BAND_VAL_DEFAULT					TEL_AT_CELL_3_UMTS_BAND_VAL_MIN

#define TEL_AT_CELL_4_ARFCN_VAL_MIN						0
#define TEL_AT_CELL_4_ARFCN_VAL_MAX						0xffff
#define TEL_AT_CELL_4_ARFCN_VAL_DEFAULT					TEL_AT_CELL_4_ARFCN_VAL_MIN

#define TEL_AT_CELL_5_SC_VAL_MIN						0
#define TEL_AT_CELL_5_SC_VAL_MAX						127
#define TEL_AT_CELL_5_SC_VAL_DEFAULT					        TEL_AT_CELL_5_SC_VAL_MIN


#define TEL_AT_HTCCTO_2_MODE_VAL_MIN 1
#define TEL_AT_HTCCTO_2_MODE_VAL_MAX 7
#define TEL_AT_HTCCTO_2_MODE_VAL_DEFAULT 1
#define TEL_AT_HTCCTO_2_MODE_SET 1
#define TEL_AT_HTCCTO_2_MODE_GET 2
#define TEL_AT_HTCCTO_2_MODE_TEST 4
#define TEL_AT_BGLTEPLMN_0_MODE_VAL_MIN          0
#define TEL_AT_BGLTEPLMN_0_MODE_VAL_MAX          1
#define TEL_AT_BGLTEPLMN_0_MODE_VAL_DEFAULT      0  /* disable */

#define TEL_AT_BGLTEPLMN_1_MODE_VAL_MIN          0
#define TEL_AT_BGLTEPLMN_1_MODE_VAL_MAX          0xffff
#define TEL_AT_BGLTEPLMN_1_MODE_VAL_DEFAULT      0xffff  /* disable */
#define TEL_AT_BGLTEPLMN_1_INTERVAL_VAL_MIN          0
#define TEL_AT_BGLTEPLMN_1_INTERVAL_VAL_MAX          0xFFFF
#define TEL_AT_BGLTEPLMN_1_INTERVAL_VAL_DEFAULT      10


#define MAX_REALTIME_LEN 20

#define TEL_AT_EHSDPA_PARAMETER_MAX   0x7ff
/*AT*EHSDPA*/
#define TEL_AT_EHSDPA_0_MODE_VAL_DEFAULT 0
#define TEL_AT_EHSDPA_1_DL_CATEGORY_VAL_DEFAULT_TD 15
#define TEL_AT_EHSDPA_2_UL_CATEGORY_VAL_DEFAULT_TD 6
#define TEL_AT_EHSDPA_3_CPC_STATE_VAL_DEFAULT_TD 0
#define TEL_AT_EHSDPA_4_DPA_CATEGORY_EXT_DEFAULT_TD 0
#define TEL_AT_EHSDPA_5_EDCH_CATEGORY_EXT_DEFAULT_TD 0
#define TEL_AT_EHSDPA_6_FDPCH_STATE_DEFAULT_TD 0
#define TEL_AT_EHSDPA_7_EFDPCH_STATE_DEFAULT_TD 0

#define TEL_AT_EHSDPA_1_DL_CATEGORY_VAL_DEFAULT_UMTS 10
#define TEL_AT_EHSDPA_2_UL_CATEGORY_VAL_DEFAULT_UMTS 6
#define TEL_AT_EHSDPA_3_CPC_STATE_VAL_DEFAULT_UMTS 0
#define TEL_AT_EHSDPA_4_DPA_CATEGORY_EXT_DEFAULT_UMTS 14
#define TEL_AT_EHSDPA_5_EDCH_CATEGORY_EXT_DEFAULT_UMTS 7
#define TEL_AT_EHSDPA_6_FDPCH_STATE_DEFAULT_UMTS 1
#define TEL_AT_EHSDPA_7_EFDPCH_STATE_DEFAULT_UMTS 1
#define TEL_AT_TPCN_0_OPTION_VAL_MIN 0
#define TEL_AT_TPCN_0_OPTION_VAL_MAX 4
#define TEL_AT_TPCN_0_OPTION_VAL_DEFAULT 0


/*AT+FWDB*/
#define TEL_AT_FWDB_0_TYPE_VAL_MIN 1
#define TEL_AT_FWDB_0_TYPE_VAL_MAX 1
#define TEL_AT_FWDB_0_TYPE_VAL_DEFAULT 1
#define TEL_AT_FWDB_1_NUMBER_VAL_MIN 1
#define TEL_AT_FWDB_1_NUMBER_VAL_MAX 5
#define TEL_AT_FWDB_1_NUMBER_VAL_DEFAULT 1
#define TEL_AT_FWDB_INDEX_VAL_MIN 0
#define TEL_AT_FWDB_INDEX_VAL_MAX 99
#define TEL_AT_FWDB_INDEX_VAL_DEFAULT -1
#define TEL_AT_FWDB_PHONE_NUMBER_MAX_LENGTH 30
#define TEL_AT_FWDB_PHONE_NUMBER_VALID_CHARACTERS "0123456789?"

#ifdef GPS_SUPPORT
/*AT+GPSINIT*/
#define TEL_AT_GSPINIT_VAL_MIN 1
#define TEL_AT_GSPINIT_VAL_MAX 2
#define TEL_AT_GSPINIT_VAL_DEFAULT 1

/*AT+GPSSLEEP*/
#define TEL_AT_GSPSLEEP_VAL_MIN 0
#define TEL_AT_GSPSLEEP_VAL_MAX 1
#define TEL_AT_GSPSLEEP_VAL_DEFAULT 1

#endif
#endif
/* AT*FDY */
#define TEL_AT_FDY_0_TYPE_VAL_MIN 0
#define TEL_AT_FDY_0_TYPE_VAL_MAX 1
#define TEL_AT_FDY_0_TYPE_VAL_DEFAULT 0
#define TEL_AT_FDY_1_INTERVAL_VAL_MIN 0
#define TEL_AT_FDY_1_INTERVAL_VAL_MAX 0x7FFFFFFF
#define TEL_AT_FDY_1_INTERVAL_VAL_DEFAULT 5000
#define TEL_AT_FDY_2_INTERVAL_VAL_MIN 0
#define TEL_AT_FDY_2_INTERVAL_VAL_MAX 0x7FFFFFFF
#define TEL_AT_FDY_2_INTERVAL_VAL_DEFAULT 5000
#define TEL_AT_FDY_3_INTERVAL_VAL_MIN 0
#define TEL_AT_FDY_3_INTERVAL_VAL_MAX 0x7FFFFFFF
#define TEL_AT_FDY_3_INTERVAL_VAL_DEFAULT 5000
#define TEL_AT_FDY_4_INTERVAL_VAL_MIN 0
#define TEL_AT_FDY_4_INTERVAL_VAL_MAX 0x7FFFFFFF
#define TEL_AT_FDY_4_INTERVAL_VAL_DEFAULT 5000

/*AT^HVER*/
#define TEL_AT_HVER_MAX_HARDWARE_VERSION_LEN 31

/* AT*DIALE */
#define TEL_AT_DIALE_SVC_VAL_MIN      0   /* network default */
#define TEL_AT_DIALE_SVC_VAL_MAX      31 /* TS24.008 10.5.4.33 service category 0x1F */
#define TEL_AT_DIALE_SVC_VAL_DEFAULT  0    /*  network default */

/* Added by Alan for LTE PC AT command server 09242013, begin  */
#define TEL_AT_VZWTESTAPP_APN_STR_DEFAULT             NULL
#define TEL_AT_VZWTESTAPP_APN_STR_MAX_LEN             100

#define TEL_AT_VZWTESTAPP_STATE_MIN                   0
#define TEL_AT_VZWTESTAPP_STATE_MAX                   2
#define TEL_AT_VZWTESTAPP_STATE_DEFAULT               0

#define TEL_AT_VZWTESTAPP_MSPERIOD_MIN                   0
#define TEL_AT_VZWTESTAPP_MSPERIOD_MAX                   65535
#define TEL_AT_VZWTESTAPP_MSPERIOD_DEFAULT               10000
/* Added by Alan for LTE PC AT command server 09242013, end  */

/* AT+MAXPOWER */
#define TEL_AT_MAXPOWER_OPTION_MAX                  3
#define TEL_AT_MAXPOWER_OPTION_MIN                  0
#define TEL_AT_MAXPOWER_OPTION_DEFAULT              0

#define TEL_AT_MAXPOWER_PARA1_MAX                  9
#define TEL_AT_MAXPOWER_PARA1_MIN                  0
#define TEL_AT_MAXPOWER_PARA1_DEFAULT              0

#define TEL_AT_MAXPOWER_PARA2_MAX                  9
#define TEL_AT_MAXPOWER_PARA2_MIN                  0
#define TEL_AT_MAXPOWER_PARA2_DEFAULT              0


/*AT*SECCAP*/


#define TEL_AT_NAS_SECCAP_MAX    0x7fffffff
#define TEL_AT_NAS_SECCAP_MIN    0x80000000
#define TEL_AT_NAS_SECCAP_DEFAULT    0x7fffffff


#define TEL_AT_NAS_SECCAP_UMTSRRCCAPCAP_MAX    0xffff
#define TEL_AT_NAS_SECCAP_UMTSRRCCAPCAP_MIN    0
#define TEL_AT_NAS_SECCAP_UMTSRRCCAPCAP_DEFAULT    0xffff

#define TEL_AT_NAS_SECCAP_UMTSRRCIPCCAP_MAX    0xffff
#define TEL_AT_NAS_SECCAP_UMTSRRCIPCCAP_MIN    0
#define TEL_AT_NAS_SECCAP_UMTSRRCIPCCAP_DEFAULT    0xffff

/* AT+LTEPOWER */
#define TEL_AT_LTEPOWER_OPTION_MAX                  2
#define TEL_AT_LTEPOWER_OPTION_MIN                  0
#define TEL_AT_LTEPOWER_OPTION_DEFAULT              0

#define TEL_AT_LTEPOWER_CHANNEL_MAX                  74
#define TEL_AT_LTEPOWER_CHANNEL_MIN                  1
#define TEL_AT_LTEPOWER_CHANNEL_DEFAULT              1

#define TEL_AT_LTEPOWER_POWER_MAX                  9
#define TEL_AT_LTEPOWER_POWER_MIN                  0
#define TEL_AT_LTEPOWER_POWER_DEFAULT              0
#define TEL_AT_LTEPOWER_BANDWIDTH_MAX                  5
#define TEL_AT_LTEPOWER_BANDWIDTH_MIN                  0
#define TEL_AT_LTEPOWER_BANDWIDTH_DEFAULT              1

/* AT+MCCMNCCC */
#define TEL_AT_MCCMNCCC_COUNTRYCODE_MAX                  (0xFFFF)
#define TEL_AT_MCCMNCCC_COUNTRYCODE_MIN                  0
#define TEL_AT_MCCMNCCC_COUNTRYCODE_DEFAULT              0

#define TEL_AT_MCCMNCCC_OPERATORCODE_MAX                  (0xFFFF)
#define TEL_AT_MCCMNCCC_OPERATORCODE_MIN                  0
#define TEL_AT_MCCMNCCC_OPERATORCODE_DEFAULT              0
#define TEL_AT_TDTR_TX_RX_GAIN_STR_LEN_MAX       4

/*  AT+CUAD  */
#define TEL_AT_CUAD_0_OPTION_VAL_MIN			0
#define TEL_AT_CUAD_0_OPTION_VAL_DEFAULT  		0
#define TEL_AT_CUAD_0_OPTION_VAL_MAX          	1


/* AT+CNEM */
#define TEL_AT_CNEM_REPORTING_MIN 0
#define TEL_AT_CNEM_REPORTING_MAX 1
#define TEL_AT_CNEM_REPORTING_DEFAULT 0

/* AT+CISRVCC */
#define TEL_AT_SRVCC_SUPPORT_MIN 0
#define TEL_AT_SRVCC_SUPPORT_MAX 1
#define TEL_AT_SRVCC_SUPPORT_DEFAULT 0

/* AT+CVDP / AT+CEVDP */
#define TEL_AT_VOICE_DOMAIN_PREFERENCE_MIN 1
#define TEL_AT_EUTRAN_VOICE_DOMAIN_PREFERENCE_MAX 4
#define TEL_AT_UTRAN_VOICE_DOMAIN_PREFERENCE_MAX 3
#define TEL_AT_VOICE_DOMAIN_PREFERENCE_DEFAULT 1

/* AT+CEUS */
#define TEL_AT_EPS_USAGE_SETTING_MIN 0
#define TEL_AT_EPS_USAGE_SETTING_MAX 1
#define TEL_AT_EPS_USAGE_SETTING_DEFAULT 0

#ifdef LWIP_IPNETBUF_SUPPORT
#ifdef VOLTE_ENABLE
/* AT*PRSYSET */
#define TEL_AT_PRXYSET_REG_MIN 0
#define TEL_AT_PRXYSET_REG_MAX 1
#define TEL_AT_PRXYSET_REG_DEFAULT 0

/* AT*PRSYRSP */
#define TEL_AT_PRXYRSP_XID_MIN 1
#define TEL_AT_PRXYRSP_XID_MAX 0xffffffff
#define TEL_AT_PRXYRSP_XID_DEFAULT 1

/* AT*PRSYRSP */
#define TEL_AT_PRXYRSP_INTER_MIN 0
#define TEL_AT_PRXYRSP_INTER_MAX 1
#define TEL_AT_PRXYRSP_INTER_DEFAULT 0

#define TEL_AT_PRXYRSP_ERROR_TYEP_MIN 	ATCI_RESULT_CODE_OK
#define TEL_AT_PRXYRSP_ERROR_TYEP_MAX 	ATCI_RESULT_CODE_CMS_ERROR_PROXY
#define TEL_AT_PRXYRSP_ERROR_TYEP_DEFAULT 	ATCI_RESULT_CODE_OK

#define TEL_AT_PRXYRSP_ERROR_CODE_MIN 	CME_PHONE_FAILURE
#define TEL_AT_PRXYRSP_ERROR_CODE_MAX 	0x7fffffff
#define TEL_AT_PRXYRSP_ERROR_CODE_DEFAULT 	CME_PHONE_FAILURE

#define TEL_AT_IMS_REG_STATE_MIN 0
#define TEL_AT_IMS_REG_STATE_MAX 1
#define TEL_AT_IMS_REG_STATE_DEFAULT 0

/* AT+CAVIMS */
#define TEL_AT_IMS_VOICE_CALL_AVAILABILITY_MIN 0
#define TEL_AT_IMS_VOICE_CALL_AVAILABILITY_MAX 1
#define TEL_AT_IMS_VOICE_CALL_AVAILABILITY_DEFAULT 0

/* AT+CASIMS */
#define TEL_AT_IMS_SMS_AVAILABILITY_MIN 0
#define TEL_AT_IMS_SMS_AVAILABILITY_MAX 1
#define TEL_AT_IMS_SMS_AVAILABILITY_DEFAULT 0

/* AT*IMSSRV */
#define TEL_AT_IMS_SERVICE_TYPE_MIN 0
#define TEL_AT_IMS_SERVICE_TYPE_MAX 9
#define TEL_AT_IMS_SERVICE_TYPE_DEFAULT 0

#define TEL_AT_IMS_SERVICE_STATUS_MIN 0
#define TEL_AT_IMS_SERVICE_STATUS_MAX 2
#define TEL_AT_IMS_SERVICE_STATUS_DEFAULT 0

#define TEL_AT_IMS_SERVICE_FAIL_CAUSE_MIN 0
#define TEL_AT_IMS_SERVICE_FAIL_CAUSE_MAX 4
#define TEL_AT_IMS_SERVICE_FAIL_CAUSE_DEFAULT 0

/* AT+CIREP */
#define TEL_AT_IMS_NW_REPORT_MODE_MIN 0
#define TEL_AT_IMS_NW_REPORT_MODE_MAX 1
#define TEL_AT_IMS_NW_REPORT_MODE_DEFAULT 1
#endif
#endif

/* AT*IMLCONFIG */
#define TEL_AT_IMLCONFIG_TYPE_VAL_MIN 0
#define TEL_AT_IMLCONFIG_TYPE_VAL_MAX 6
#define TEL_AT_IMLCONFIG_TYPE_VAL_DEFAULT 0

/*AT+LPNWUL*/
#define TEL_AT_LPNWUL_1_LEN_VAL_MIN 0
#define TEL_AT_LPNWUL_1_LEN_VAL_MAX 2000
#define TEL_AT_LPNWUL_1_LEN_VAL_DEFAULT 500
#define TEL_AT_LPNWUL_2_COUNT_VAL_MIN 0
#define TEL_AT_LPNWUL_2_COUNT_VAL_MAX 3
#define TEL_AT_LPNWUL_2_COUNT_VAL_DEFAULT 0
#define TEL_AT_LPNWUL_3_TYPE_VAL_MIN 0
#define TEL_AT_LPNWUL_3_TYPE_VAL_MAX 4
#define TEL_AT_LPNWUL_3_TYPE_VAL_DEFAULT 0
#define TEL_AT_LPNWUL_4_FINAL_VAL_MIN 0
#define MAX_STRING_LEN   128
#define TEL_AT_LPNWUL_4_FINAL_VAL_MAX 1
#define TEL_AT_LPNWUL_4_FINAL_VAL_DEFAULT 0
#define TEL_AT_LPNWUL_6_ADDINFOLEN_VAL_MIN 0
#define TEL_AT_LPNWUL_6_ADDINFOLEN_VAL_MAX CI_DEV_MAX_ADD_INFO_LEN
#define TEL_AT_LPNWUL_6_ADDINFOLEN_VAL_DEFAULT 0

/*AT+CEN*/
#define TEL_AT_CEN_REPORTING_MIN 0
#define TEL_AT_CEN_REPORTING_MAX 1
#define TEL_AT_CEN_REPORTING_DEFAULT 0


/* AT+CMMIVT */
#define TEL_AT_MM_IMS_VOICE_TERMINATION_MIN 1
#define TEL_AT_MM_IMS_VOICE_TERMINATION_MAX 2
#define TEL_AT_MM_IMS_VOICE_TERMINATION_DEFAULT 1

/* AT*POCCMD */
#define TEL_AT_POCCMD_TYPE_MIN 0
#define TEL_AT_POCCMD_TYPE_MAX 1
#define TEL_AT_POCCMD_TYPE_DEFAULT 0

#define TEL_AT_POCCMD_STATUS_MIN 0
#define TEL_AT_POCCMD_STATUS_MAX 2
#define TEL_AT_POCCMD_STATUS_DEFAULT 0


/* AT+CPSMS */
#define TEL_AT_CPSMS_0_MODE_VAL_MIN						0
#define TEL_AT_CPSMS_0_MODE_VAL_MAX						2
#define TEL_AT_CPSMS_0_MODE_VAL_DEFAULT					0
#define TEL_AT_CPSMS_PARAMETER_STR_LENGTH				8


/* AT+CEDRXS */
#define TEL_AT_CEDRXS_0_MODE_VAL_MIN						0
#define TEL_AT_CEDRXS_0_MODE_VAL_MAX						3
#define TEL_AT_CEDRXS_0_MODE_VAL_DEFAULT					0

#define TEL_AT_CEDRXS_1_ACT_TYPE_VAL_MIN						1
#define TEL_AT_CEDRXS_1_ACT_TYPE_VAL_MAX						5
#define TEL_AT_CEDRXS_1_ACT_TYPE_VAL_DEFAULT					5
#define TEL_AT_CEDRXS_EDRX_STR_LENGTH				4


/* AT+CCIOTOPT */
#define TEL_AT_CCIOTOPT_0_MODE_VAL_MIN						0
#define TEL_AT_CCIOTOPT_0_MODE_VAL_MAX						2
#define TEL_AT_CCIOTOPT_0_MODE_VAL_DEFAULT					0

#define TEL_AT_CCIOTOPT_1_SUPPORTED_UE_OPT_VAL_MIN						0
#define TEL_AT_CCIOTOPT_1_SUPPORTED_UE_OPT_VAL_MAX						3
#define TEL_AT_CCIOTOPT_1_SUPPORTED_UE_OPT_VAL_DEFAULT					0

#define TEL_AT_CCIOTOPT_2_PREFERRED_UE_OPT_VAL_MIN						0
#define TEL_AT_CCIOTOPT_2_PREFERRED_UE_OPT_VAL_MAX						3
#define TEL_AT_CCIOTOPT_2_PREFERRED_UE_OPT_VAL_DEFAULT					0


/* AT+CSCON */
#define TEL_AT_CSCON_0_OPTION_VAL_MIN						0
#define TEL_AT_CSCON_0_OPTION_VAL_MAX						3
#define TEL_AT_CSCON_0_OPTION_VAL_DEFAULT					0

/* AT+CIPCA */
#define TEL_AT_CIPCA_0_OPTION_VAL_MIN						0
#define TEL_AT_CIPCA_0_OPTION_VAL_MAX						3
#define TEL_AT_CIPCA_0_OPTION_VAL_DEFAULT					0

#define TEL_AT_CIPCA_1_ATTACH_WITHOUT_PDN_VAL_MIN						0
#define TEL_AT_CIPCA_1_ATTACH_WITHOUT_PDN_VAL_MAX						1
#define TEL_AT_CIPCA_1_ATTACH_WITHOUT_PDN_VAL_DEFAULT					0


/* AT+CABTSR */
#define TEL_AT_CABTSR_STATUS_VAL_MIN						0
#define TEL_AT_CABTSR_STATUS_VAL_MAX						1
#define TEL_AT_CABTSR_STATUS_VAL_DEFAULT					0


/* AT+CABTRDP */
#define TEL_AT_CABTRDP_APN_STR_MAX_LEN             100

/* AT+CGAPNRC */
#define TEL_AT_CGAPNRC_CID_VAL_MIN             0
#define TEL_AT_CGAPNRC_CID_VAL_MAX             TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CGAPNRC_CID_VAL_DEFAULT         TEL_AT_PS_CID_VAL_DEFAULT


/* AT+CSODCP */
#define TEL_AT_CSODCP_CID_VAL_MIN             1
#define TEL_AT_CSODCP_CID_VAL_MAX             TEL_AT_PS_CID_VAL_MAX
#define TEL_AT_CSODCP_CID_VAL_DEFAULT         TEL_AT_PS_CID_VAL_DEFAULT

#define TEL_AT_CSODCP_DATA_LENGTH_VAL_MIN             0
#define TEL_AT_CSODCP_DATA_LENGTH_VAL_MAX             1358
#define TEL_AT_CSODCP_DATA_LENGTH_VAL_DEFAULT         0


#define TEL_AT_CSODCP_RAI_VAL_MIN             0
#define TEL_AT_CSODCP_RAI_VAL_MAX             2
#define TEL_AT_CSODCP_RAI_VAL_DEFAULT         0

#define TEL_AT_CSODCP_TYPE_VAL_MIN             0
#define TEL_AT_CSODCP_TYPE_VAL_MAX             1
#define TEL_AT_CSODCP_TYPE_VAL_DEFAULT         0

/* AT+CRTDCP */
#define TEL_AT_CRTDCP_OPTION_VAL_MIN             0
#define TEL_AT_CRTDCP_OPTION_VAL_MAX             1
#define TEL_AT_CRTDCP_OPTION_VAL_DEFAULT         0

/*AT+MEDCR*/
#define TEL_AT_MEDCR_0_MIN 0
#define TEL_AT_MEDCR_0_MAX 1
#define TEL_AT_MEDCR_0_DEFAULT 0

#define TEL_AT_MEDCR_1_MIN 0
#define TEL_AT_MEDCR_1_MAX 255
#define TEL_AT_MEDCR_1_DEFAULT 0

#define TEL_AT_MEDCR_2_MIN 0
#define TEL_AT_MEDCR_2_MAX 255
#define TEL_AT_MEDCR_2_DEFAULT 1
#define TEL_AT_NETCON_CHANNEL_MIN	0
#define TEL_AT_NETCON_CHANNEL_MAX	 5
#define TEL_AT_NETCON_IP_FILTER_ID_MIN	0
#define TEL_AT_NETCON_IP_FILTER_ID_MAX	 4
#define TEL_AT_NETCON_CHANNEL_DEFAULT     0
#define TEL_AT_NETCON_TYPE_STR_MIN_LEN	2
#define TEL_AT_NETCON_TYPE_STR_MAX_LEN	MAX_STRING_LEN
#define TEL_AT_NETCON_TYPE_STR_DEFAULT           NULL
#define TEL_AT_NETCON_CFGT_MIN	1
#define TEL_AT_NETCON_CFGT_MAX	 65535
#define TEL_AT_NETCON_CFGT_DEFAULT     100
#define TEL_AT_NETCON_CFGP_MIN	1
#define TEL_AT_NETCON_CFGP_MAX	 1460
#define TEL_AT_NETCON_CFGP_DEFAULT     1024
#define TEL_AT_NETCON_AUTH_MIN	0
#define TEL_AT_NETCON_AUTH_MAX	 2
#define TEL_AT_NETCON_AUTH_DEFAULT    1
#define TEL_AT_NETCON_STATE_MIN	0
#define TEL_AT_NETCON_STATE_MAX	 1
#define TEL_AT_NETCON_STATE_DEFAULT    0
#define TEL_AT_IPV4_STR_MIN_LEN	7
#define TEL_AT_IPV4_STR_MAX_LEN	 16
#define TEL_AT_IPV4_STR_DEFAULT           NULL
#define TEL_AT_NET_IPFILTER_ACTION_MIN	0
#define TEL_AT_NET_IPFILTER_ACTION_MAX	 2
#define TEL_AT_NET_IPFILTER_ACTION_DEFAULT    0
#define TEL_AT_NET_SOCKET_ID_MIN	0
#define TEL_AT_NET_SOCKET_ID_MAX	 5
#define TEL_AT_NET_SOCKET_ID_DEFAULT    0
#define TEL_AT_NET_TYPE_MIN	0
#define TEL_AT_NET_TYPE_MAX	 2
#define TEL_AT_NET_TYPE_DEFAULT    0
#define TEL_AT_IPV4_PROT_STR_MAX_LEN	 22
#define TEL_AT_NET_SOCKET_READ_MIN_LEN	1
#define TEL_AT_NET_SOCKET_READ_MAX_LEN	 3072
#define TEL_AT_NET_SOCKET_READ_DEFAULT    1
#define TEL_AT_NET_PORT_MIN	0
#define TEL_AT_NET_PORT_MAX	 65535
#define TEL_AT_NET_PORT_DEFAULT    1
#define TEL_AT_NET_SRC_PORT_DEFAULT    0
#define TEL_AT_FTP_HOST_MAX_LEN	 128
#define TEL_AT_FTP_HOST_DEFAULT        NULL
#define TEL_AT_FTP_USERNAME_MAX_LEN	 128
#define TEL_AT_FTP_USERNAME_DEFAULT	 NULL
#define TEL_AT_FTP_PASSWORD_MAX_LEN   128
#define TEL_AT_FTP_PASSWORD_DEFAULT	 NULL
#define TEL_AT_FTP_MODE_MIN	0
#define TEL_AT_FTP_MODE_MAX	 1
#define TEL_AT_FTP_MODE_DEFAULT    1
#define TEL_AT_FTP_TYPE_MIN	0
#define TEL_AT_FTP_TYPE_MAX	 1
#define TEL_AT_FTP_TYPE_DEFAULT    1
#define TEL_AT_FTP_TIMEOUT_MIN	5
#define TEL_AT_FTP_TIMEOUT_MIN_1	20
#define TEL_AT_FTP_TIMEOUT_MAX	 180
#define TEL_AT_FTP_TIMEOUT_DEFAULT    30
#define TEL_AT_FTP_FILE_MAX_LEN   128
#define TEL_AT_FTP_FILE_DEFAULT	 NULL
#define TEL_AT_FTP_SSLTYPE_MIN	0
#define TEL_AT_FTP_SSLTYPE_MAX	 1
#define TEL_AT_FTP_SSLTYPE_DEFAULT    0
#define TEL_AT_FTP_SSLCTXID_MIN	0
#define TEL_AT_FTP_SSLCTXID_MAX	 5
#define TEL_AT_FTP_SSLCTXID_DEFAULT    0
#define TEL_AT_FTP_PORT_DEFAULT    21

#define TEL_AT_FTP_DATA_LEN_MIN	        0
#define TEL_AT_FTP_DATA_LEN_MAX	        3072
#define TEL_AT_FTP_PUT_DATA_LEN_MIN	    0
#define TEL_AT_FTP_PUT_DATA_LEN_MAX	    3072
#define TEL_AT_FTPA_PUT_DATA_LEN_MAX	0x7FFFFFFF


#define TEL_AT_FOTA_MODE_MIN	0
#define TEL_AT_FOTA_MODE_MAX	 1
#define TEL_AT_FOTA_MODE_DEFAULT    1

#define TEL_AT_GPS_POS_TYPE_MIN	0
#define TEL_AT_GPS_POS_TYPE_MAX	5
#define TEL_AT_GPS_POS_TYPE_DEFAULT     0

#define TEL_AT_MYBAND_MIN	0
#define TEL_AT_MYBAND_MAX	2
#define TEL_AT_MYBAND_DEFAULT     0

#define TEL_AT_MYBCCH_MIN	0
#define TEL_AT_MYBCCH_MAX	2
#define TEL_AT_MYBCCH_DEFAULT     0

#define TEL_AT_SECRET_KEY_MAX_LEN   16
#define TEL_AT_SECRET_KEY_DEFAULT   16

#define TEL_AT_MODULE_INFO_MAX_LEN   128
#define TEL_AT_MANUFACTURE_MAX_LEN   4
#define TEL_AT_MODEL_MAX_LEN   8
#define TEL_AT_FW_DATE_MAX_LEN   6

#define TEL_AT_MODULE_INFO_AID_MAX_LEN   34
#define TEL_AT_MODULE_INFO_TAR_MAX_LEN   6
#define TEL_AT_MODULE_INFO_SQ_INTERVAL_MAX_LEN   8

#define TEL_AT_SYS_INFO_MODE_MIN	1
#define TEL_AT_SYS_INFO_MODE_MAX	7
#define TEL_AT_SYS_INFO_MODE_DEFAULT     0

#define TEL_AT_SYS_INFO_URC_MODE_MIN	0
#define TEL_AT_SYS_INFO_URC_MODE_MAX	1
#define TEL_AT_SYS_INFO_URC_MODE_DEFAULT     0


#define TEL_AT_DOWNLOAD_MODE_MIN	0
#define TEL_AT_DOWNLOAD_MODE_MAX	1
#define TEL_AT_DOWNLOAD_MODE_DEFAULT     0

#define TEL_AT_CONTEXT_IP_TYPE_MIN	1
#define TEL_AT_CONTEXT_IP_TYPE_MAX	2
#define TEL_AT_CONTEXT_IP_TYPE_DEFAULT     1

#define TEL_AT_ASROPEN_CONTEXT_ID_MIN	1
#define TEL_AT_ASROPEN_CONTEXT_ID_MAX	6
#define TEL_AT_ASROPEN_CONTEXT_ID_DEFAULT     1

#define TEL_AT_ASROPEN_CONNECT_ID_MIN	0
#define TEL_AT_ASROPEN_CONNECT_ID_MAX	5
#define TEL_AT_ASROPEN_CONNECT_ID_DEFAULT     0

#define TEL_AT_ASROPEN_SERVICE_TYPE_MAX_LEN	12
#define TEL_AT_ASROPEN_SERVICE_TYPE_DEFAULT	NULL

#define TEL_AT_ASROPEN_IP_ADDRESS_MAX_LEN	128
#define TEL_AT_ASROPEN_IP_ADDRESS_DEFAULT	NULL


#define TEL_AT_ASROPEN_REMOTE_PORT_MIN	0
#define TEL_AT_ASROPEN_REMOTE_PORT_MAX	65535
#define TEL_AT_ASROPEN_REMOTE_PORT_DEFAULT     0

#define TEL_AT_ASROPEN_LOCAL_PORT_MIN	0
#define TEL_AT_ASROPEN_LOCAL_PORT_MAX	65535
#define TEL_AT_ASROPEN_LOCAL_PORT_DEFAULT     0

#define TEL_AT_ASROPEN_ACCESS_MODE_MIN	0
#define TEL_AT_ASROPEN_ACCESS_MODE_MAX	2
#define TEL_AT_ASROPEN_ACCESS_MODE_DEFAULT     0

#define TEL_AT_ASRCLOSE_TIMEOUT_MIN	0
#define TEL_AT_ASRCLOSE_TIMEOUT_MAX	65535
#define TEL_AT_ASRCLOSE_TIMEOUT_DEFAULT     0

#define TEL_AT_ASRSTATE_QUERY_MIN	0
#define TEL_AT_ASRSTATE_QUERY_MAX	1
#define TEL_AT_ASRSTATE_QUERY_DEFAULT     0

#define TEL_AT_ASRSEND_DATA_LEN_MIN	    0
#define TEL_AT_ASRSEND_DATA_LEN_MAX	    1460
#define TEL_AT_ASRSEND_DATA_LEN_DEFAULT    0xFFFFFFFF

#define TEL_AT_ASRREAD_DATA_LEN_MIN	    0
#define TEL_AT_ASRREAD_DATA_LEN_MAX	    1500
#define TEL_AT_ASRREAD_DATA_LEN_DEFAULT    0

#define TEL_AT_ASRSEND_SEND_HEX_MAX_LEN	2048
#define TEL_AT_ASRSEND_SEND_HEX_DEFAULT	NULL

#define TEL_AT_ASR_ACCESS_MODE_MIN	    0
#define TEL_AT_ASR_ACCESS_MODE_MAX	    2
#define TEL_AT_ASR_ACCESS_MODE_DEFAULT    0


#define TEL_AT_ASRSDE_ECHO_MIN	    0
#define TEL_AT_ASRSDE_ECHO_MAX	    1
#define TEL_AT_ASRSDE_ECHO_DEFAULT      0

#define TEL_AT_ASRS_CFG_MAX_LEN	14
#define TEL_AT_ASRS_CFG_DEFAULT	NULL

#define TEL_AT_TRANS_PKT_SIZE_MIN	    1
#define TEL_AT_TRANS_PKT_SIZE_MAX	    1460
#define TEL_AT_TRANS_PKT_SIZE_DEFAULT      1460

#define TEL_AT_TRANS_WAIT_TM_MIN	    0
#define TEL_AT_TRANS_WAIT_TM_MAX	    20
#define TEL_AT_TRANS_WAIT_TM_DEFAULT      0

#define TEL_AT_DATA_FORMAT_MIN	    0
#define TEL_AT_DATA_FORMAT_MAX	    1
#define TEL_AT_DATA_FORMAT_DEFAULT      0

#define TEL_AT_VIEW_MODE_MIN	    0
#define TEL_AT_VIEW_MODE_MAX	    1
#define TEL_AT_VIEW_MODE_DEFAULT      0

#define TEL_AT_TCP_RETRANSCFG_MIN	    3
#define TEL_AT_TCP_RETRANSCFG_MAX	    20
#define TEL_AT_TCP_RETRANSCFG_DEFAULT      3

#define TEL_AT_TCP_RETRANSCFG_TIME_MIN	    5
#define TEL_AT_TCP_RETRANSCFG_TIME_MAX	    1000
#define TEL_AT_TCP_RETRANSCFG_TIME_DEFAULT      5

#define TEL_AT_DNS_CACHE_MIN	    0
#define TEL_AT_DNS_CACHE_MAX	    1
#define TEL_AT_DNS_CACHE_DEFAULT      0

#define TEL_AT_SEND_TIMEOUT_MIN	    0
#define TEL_AT_SEND_TIMEOUT_MAX	    3600
#define TEL_AT_SEND_TIMEOUT_DEFAULT      0

#define TEL_AT_PASSIVE_CLOSED_MIN	    0
#define TEL_AT_PASSIVE_CLOSED_MAX	    1
#define TEL_AT_PASSIVE_CLOSED_DEFAULT      0



#define TEL_AT_M2M_CREATE_TOTAL_SIZE_MIN	        0
#define TEL_AT_M2M_CREATE_TOTAL_SIZE_MAX	        65535
#define TEL_AT_M2M_CREATE_TOTAL_SIZE_DEFAULT        0

#define TEL_AT_M2M_VERSION_MAX_LEN	        32


#define TEL_AT_M2M_CREATE_CONFIG_MAX_LEN	        512
#define TEL_AT_M2M_CREATE_CONFIG_DEFAULT	        NULL

#define TEL_AT_M2M_INDEX_MIN	                0
#define TEL_AT_M2M_INDEX_MAX	                32
#define TEL_AT_M2M_INDEX_DEFAULT             0

#define TEL_AT_M2M_CREATE_CURRENT_SIZE_MIN	        1
#define TEL_AT_M2M_CREATE_CURRENT_SIZE_MAX	        512
#define TEL_AT_M2M_CREATE_CURRENT_SIZE_DEFAULT      1

#define TEL_AT_M2M_FLAG_MIN	        0
#define TEL_AT_M2M_FLAG_MAX	        2
#define TEL_AT_M2M_FLAG_DEFAULT      0

#define TEL_AT_M2M_ACK_ID_MIN	        0
#define TEL_AT_M2M_ACK_ID_MAX	        65535
#define TEL_AT_M2M_ACK_ID_DEFAULT      0


#define TEL_AT_M2M_REF_MIN	        0
#define TEL_AT_M2M_REF_MAX	        0
#define TEL_AT_M2M_REF_DEFAULT       0


#define TEL_AT_M2M_OBJECT_ID_MIN	        1
#define TEL_AT_M2M_OBJECT_ID_MAX	        65535
#define TEL_AT_M2M_OBJECT_ID_DEFAULT        1

#define TEL_AT_M2M_INSTANCE_COUNT_MIN	    1
#define TEL_AT_M2M_INSTANCE_COUNT_MAX	    128
#define TEL_AT_M2M_INSTANCE_COUNT_DEFAULT   1


#define TEL_AT_M2M_INSTANCE_BIT_MAP_MAX_LEN	        16
#define TEL_AT_M2M_INSTANCE_BIT_MAP_DEFAULT	        NULL


#define TEL_AT_M2M_ATTRIBUTE_COUNT_MIN	        0
#define TEL_AT_M2M_ATTRIBUTE_COUNT_MAX	        128
#define TEL_AT_M2M_ATTRIBUTE_COUNT_DEFAULT      0


#define TEL_AT_M2M_ACTION_COUNT_MIN	        0
#define TEL_AT_M2M_ACTION_COUNT_MAX	        128
#define TEL_AT_M2M_ACTION_COUNT_DEFAULT      0


#define TEL_AT_M2M_REG_TIMEOUT_MIN	            0
#define TEL_AT_M2M_REG_TIMEOUT_MAX	            65535
#define TEL_AT_M2M_REG_TIMEOUT_DEFAULT            0


#define TEL_AT_M2M_LIFE_TIME_MIN	            0
#define TEL_AT_M2M_LIFE_TIME_MAX	            (0x7FFFFFFF-1)
#define TEL_AT_M2M_LIFE_TIME_DEFAULT            0

#define TEL_AT_M2M_WITH_OBJECT_FLAG_MIN	        0
#define TEL_AT_M2M_WITH_OBJECT_FLAG_MAX	        1
#define TEL_AT_M2M_WITH_OBJECT_FLAG_DEFAULT     0

#define TEL_AT_M2M_MSG_ID_MIN	            0
#define TEL_AT_M2M_MSG_ID_MAX	            (0x7FFFFFFF-1)
#define TEL_AT_M2M_MSG_ID_DEFAULT            0

#define TEL_AT_M2M_LENGTH_MIN	            0
#define TEL_AT_M2M_LENGTH_MAX	            65535
#define TEL_AT_M2M_LENGTH_DEFAULT            0

#define TEL_AT_M2M_DISCOVER_VALUE_MAX_LEN	        512
#define TEL_AT_M2M_DISCOVER_VALUE_DEFAULT	        NULL

#define TEL_AT_M2M_INSTANCE_ID_MIN	        0
#define TEL_AT_M2M_INSTANCE_ID_MAX	        65535
#define TEL_AT_M2M_INSTANCE_ID_DEFAULT        1

#define TEL_AT_M2M_RESOURCE_ID_MIN	        0
#define TEL_AT_M2M_RESOURCE_ID_MAX	        65535
#define TEL_AT_M2M_RESOURCE_ID_DEFAULT        1


#define TEL_AT_M2M_VALUE_TYPE_MIN	        1
#define TEL_AT_M2M_VALUE_TYPE_MAX	        5
#define TEL_AT_M2M_VALUE_TYPE_DEFAULT        1

#define TEL_AT_M2M_READ_VALUE_MAX_LEN	        512
#define TEL_AT_M2M_READ_VALUE_DEFAULT	        NULL


#define TEL_AT_M2M_RESULT_MIN	            1
#define TEL_AT_M2M_RESULT_MAX	            15
#define TEL_AT_M2M_RESULT_DEFAULT         1


#define TEL_AT_SSL_CONFIG_MAX_LEN	15
#define TEL_AT_SSL_CONFIG_DEFAULT	NULL

#define TEL_AT_SSL_CTX_ID_MIN	            0
#define TEL_AT_SSL_CTX_ID_MAX	            5
#define TEL_AT_SSL_CTX_ID_DEFAULT           0


#define TEL_AT_SSL_CONFIG_VERSION_MAX_LEN	1
#define TEL_AT_SSL_CONFIG_VERSION_DEFAULT	NULL

#define TEL_AT_SSL_CONFIG_CIPHERSUITES_MAX_LEN	6
#define TEL_AT_SSL_CONFIG_CIPHERSUITES_DEFAULT	NULL

#define TEL_AT_SSL_CONFIG_PATH_MAX_LEN	128
#define TEL_AT_SSL_CONFIG_PATH_DEFAULT	NULL

#define TEL_AT_SSL_CONFIG_SECLEVEL_MAX_LEN	1
#define TEL_AT_SSL_CONFIG_SECLEVEL_DEFAULT	NULL

#define TEL_AT_SSL_CONFIG_IGNORELOCALTIME_MAX_LEN	1
#define TEL_AT_SSL_CONFIG_IGNORELOCALTIME_DEFAULT	NULL

#define TEL_AT_SSL_CONFIG_NEGOTIATETIME_MAX_LEN	3
#define TEL_AT_SSL_CONFIG_NEGOTIATETIME_DEFAULT	NULL

#define TEL_AT_SSL_RECV_LEN_MIN	    1
#define TEL_AT_SSL_RECV_LEN_MAX	    1500
#define TEL_AT_SSL_RECV_LEN_DEFAULT    0

//AT*SULOGCFG
#define TEL_AT_SULOGCFG_0_MAX                3
#define TEL_AT_SULOGCFG_0_MIN                0
#define TEL_AT_SULOGCFG_0_DEFAULT            0

#define TEL_AT_SULOGCFG_1_MAX                0x7FFFFFFF
#if QUECTEL_PROJECT_CUST
#define TEL_AT_SULOGCFG_1_MIN                0
#else
#define TEL_AT_SULOGCFG_1_MIN                (0-0x80000000)
#endif
#define TEL_AT_SULOGCFG_1_DEFAULT            0

#define TEL_AT_SULOGCFG_2_MAX                0x7FFFFFFF
#if QUECTEL_PROJECT_CUST
#define TEL_AT_SULOGCFG_2_MIN                0
#else
#define TEL_AT_SULOGCFG_2_MIN                (0-0x80000000)
#endif
#define TEL_AT_SULOGCFG_2_DEFAULT            0

#define TEL_AT_SULOGCFG_3_MAX                1
#define TEL_AT_SULOGCFG_3_MIN                0
#define TEL_AT_SULOGCFG_3_DEFAULT            0

#define TEL_AT_SULOGCFG_4_MAX                1
#define TEL_AT_SULOGCFG_4_MIN                0
#define TEL_AT_SULOGCFG_4_DEFAULT            0


#ifdef ENABLE_WIFI_SCAN 
//AT*WIFICTRL
#define TEL_AT_WIFLCTRL_OPTION_MIN	    0
#define TEL_AT_WIFLCTRL_OPTION_MAX	    3
#define TEL_AT_WIFLCTRL_OPTION_DEFAULT    0
#endif
#define TEL_AT_SIM_POLL_0_MODE_VAL_MIN                0
#define TEL_AT_SIM_POLL_0_MODE_VAL_MAX                1
#define TEL_AT_SIM_POLL_0_MODE_VAL_DEFAULT				1

#define TEL_AT_SIM_POLL_1_POLL_CFG_VAL_MIN                0
#define TEL_AT_SIM_POLL_1_POLL_CFG_VAL_MAX                1
#define TEL_AT_SIM_POLL_1_POLL_CFG_VAL_DEFAULT				0

#define TEL_AT_SIM_POLL_2_STK_POLL_VAL_MIN                0
#define TEL_AT_SIM_POLL_2_STK_POLL_VAL_MAX                1
#define TEL_AT_SIM_POLL_2_STK_POLL_VAL_DEFAULT				1

#define TEL_AT_SIM_POLL_3_STK_INTERVAL_VAL_MIN                1
#define TEL_AT_SIM_POLL_3_STK_INTERVAL_VAL_MAX                65535
#define TEL_AT_SIM_POLL_3_STK_INTERVAL_VAL_DEFAULT				1
//AT+EEMGINFO
#define TEL_AT_EEMGINFO_TYPE_VAL_MIN 0
#define TEL_AT_EEMGINFO_TYPE_VAL_MAX 1
#define TEL_AT_EEMGINFO_TYPE_VAL_DEFAULT 0


/* AT$MYDOWNLOAD */
#define TEL_AT_DOWNLOAD_TYPE_VAL_MIN 0
#define TEL_AT_DOWNLOAD_TYPE_VAL_MAX 1
#define TEL_AT_DOWNLOAD_TYPE_VAL_DEFAULT 1

/* AT+CSAS */
#define TEL_AT_CSAS_PROF_MIN 0
#define TEL_AT_CSAS_PROF_MAX 255
#define TEL_AT_CSAS_PROF_DEFAULT 0

/* AT+CPNER */
#define TEL_AT_CPNER_REPORTING_VAL_MIN				0
#define TEL_AT_CPNER_REPORTING_VAL_MAX				1
#define TEL_AT_CPNER_REPORTING_VAL_DEFAULT			0

//AT*TESTCMD
#define TEL_AT_TESTCMD_0_MAX                3
#define TEL_AT_TESTCMD_0_MIN                0
#define TEL_AT_TESTCMD_0_DEFAULT            0

//AT*ENVCFG
#define TEL_AT_ENVCFG_0_MAX                3
#define TEL_AT_ENVCFG_0_MIN                0
#define TEL_AT_ENVCFG_0_DEFAULT            1

//AT*ECALLCFG
#define TEL_ATP_ECALLCFG_TIMER_VAL_MAX 30
#define TEL_ATP_ECALLCFG_TIMER_VAL_MIN 0
#define TEL_ATP_ECALLCFG_TIMER_VAL_DEFAULT 0

#define TEL_ATP_ECALLCFG_INTIMER_VAL_MAX 1440
#define TEL_ATP_ECALLCFG_INTIMER_VAL_MIN 1
#define TEL_ATP_ECALLCFG_INTIMER_VAL_DEFAULT 0

//AT*ECALLONLY
#define TEL_ATP_ECALLONLY_ACTIVE_VAL_MAX 1
#define TEL_ATP_ECALLONLY_ACTIVE_VAL_MIN 0
#define TEL_ATP_ECALLONLY_ACTIVE_VAL_DEFAULT 0

//AT*ECALLREG
#define TEL_ATP_ECALLREG_ACTIVE_VAL_MAX 1
#define TEL_ATP_ECALLREG_ACTIVE_VAL_MIN 0
#define TEL_ATP_ECALLREG_ACTIVE_VAL_DEFAULT 0

#define TEL_ATP_ECALLONLY_TESTNUM_STR_DEFAULT NULL
#define TEL_ATP_ECALLONLY_TESTNUM_STR_MAX_LEN 40

#define TEL_ATP_ECALLONLY_RECONFIGNUM_STR_DEFAULT NULL
#define TEL_ATP_ECALLONLY_RECONFIGNUM_STR_MAX_LEN 40

/* AT+CECALL */
#define TEL_AT_CECALL_VAL_MIN		0
#define TEL_AT_CECALL_VAL_MAX		3
#define TEL_AT_CECALL_DEFAULT		0

/* AT*ECALLDATA */
#define TEL_AT_ECALLDATA_0_OP_VAL_MIN						0
#define TEL_AT_ECALLDATA_0_OP_VAL_MAX						7
#define TEL_AT_ECALLDATA_0_OP_VAL_DEFAULT					0

#define TEL_AT_ECALLDATA_1_PARA_VAL_MIN						0
#define TEL_AT_ECALLDATA_1_PARA_VAL_MAX						0xFFFFFFFF
#define TEL_AT_ECALLDATA_1_PARA_VAL_DEFAULT					0


/* AT*ECALLVOICE */
#define TEL_AT_ECALLVOICE_0_ID_VAL_MIN						0
#define TEL_AT_ECALLVOICE_0_ID_VAL_MAX						4
#define TEL_AT_ECALLVOICE_0_ID_VAL_DEFAULT					0

#define TEL_AT_ECALLVOICE_1_PARA_VAL_MIN						0
#define TEL_AT_ECALLVOICE_1_PARA_VAL_MAX						1
#define TEL_AT_ECALLVOICE_1_PARA_VAL_DEFAULT					0

#define TEL_AT_ECALLVOICE_2_DATA_VAL_MIN						0
#define TEL_AT_ECALLVOICE_2_DATA_VAL_MAX						1
#define TEL_AT_ECALLVOICE_2_DATA_VAL_DEFAULT					0

/* AT*ECALLSYNC */
#define TEL_AT_ECALLSYNC_0_MSD_STR_DEFAULT		NULL
#define TEL_AT_ECALLSYNC_0_MSD_STR_MAX_LEN		280 

#define TEL_AT_ECALLSYNC_1_STATE_MIN		    0
#define TEL_AT_ECALLSYNC_1_STATE_MAX		    1
#define TEL_AT_ECALLSYNC_1_STATE_DEFAULT		0

/* AT*ECALLSENDMSD */
#define TEL_AT_ECALLSENDMSD_0_MSD_STR_DEFAULT		NULL
#define TEL_AT_ECALLSENDMSD_0_MSD_STR_MAX_LEN		280 

/* END OF FILE */
