/*------------------------------------------------------------
(C) Copyright [2006-2009] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_dev.h
Description : Data types file for the DEV service group

Notes       :

INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intel's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded
in Materials by Intel or Intel's suppliers or licensors in any way.
=========================================================================== */

#if !defined(_CI_DEV_H_)
#define _CI_DEV_H_

#ifdef __cplusplus
    extern "C" {
#endif

/* Added by lalon CIQ Eng mode begin */
#include "ci_dev_engm.h"
/* Added by lalon CIQ Eng mode end */

#include "ci_api_types.h"
/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_DEV_VER_MAJOR 7
//#define CI_DEV_VER_MINOR 0
#define CI_DEV_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version


#define CI_DEV_ENG_MAX_ACTIVE_PDP_CONTEXT    7
#define CI_DEV_PDP_IP_V6_SIZE                               16
#define CI_DEV_MAX_APN_NAME  					100
#define CI_DEV_MAX_ARFCN_LIST                   64 /*Michal Bukai - I-Mate Addition.*/

#define CI_DEV_LTE_MAX_CELL_INTRA 16
#define CI_DEV_LTE_MAX_CELL_INTER 16
#define CI_DEV_LTE_MAX_CELL_UTRA 16
#define CI_DEV_LTE_MAX_CELL_GSM 16
#define CI_DEV_LTE_PLMN_LIST_SIZE 6

#define CI_DEV_MAX_IMS_MEDIA_REQ_BUF    		1200

/* ----------------------------------------------------------------------------- */

/* CI_DEV Primitive ID definitions */

/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_PRIM {
    CI_DEV_PRIM_STATUS_IND = 1,								/**< \brief Indicates that the device status has changed \details The client should not begin its initialization process before receiving CI_DEV_PRIM_STATUS_IND (CI_DEV_STATUS_READY). This indication cannot be disabled.  */
    CI_DEV_PRIM_GET_MANU_ID_REQ,							/**< \brief Requests the manufacturer ID \details   */
    CI_DEV_PRIM_GET_MANU_ID_CNF,							/**< \brief Confirms a request and returns the manufacturer ID \details   */
    CI_DEV_PRIM_GET_MODEL_ID_REQ,							/**< \brief Requests the model ID \details   */
    CI_DEV_PRIM_GET_MODEL_ID_CNF,							/**< \brief Confirms a request and returns the model ID \details   */
    CI_DEV_PRIM_GET_REVISION_ID_REQ,						/**< \brief Requests the revision ID  \details   */
    CI_DEV_PRIM_GET_REVISION_ID_CNF,						/**< \brief Confirms a request and returns the revision ID  \details   */
    CI_DEV_PRIM_GET_SERIALNUM_ID_REQ,						/**< \brief Requests the serial number ID (IMEI)  \details   */
    CI_DEV_PRIM_GET_SERIALNUM_ID_CNF,						/**< \brief Confirms a request and returns the serial number ID  \details   */
    CI_DEV_PRIM_SET_FUNC_REQ = 10,							/**< \brief Requests to set the level of functionality in the cellular subsystem  \details   */
    CI_DEV_PRIM_SET_FUNC_CNF,								/**< \brief Confirms a request and sets the level of functionality in the cellular subsystem \details   */
    CI_DEV_PRIM_GET_FUNC_REQ,								/**< \brief Requests to get the level of functionality in the cellular subsystem  \details   */
    CI_DEV_PRIM_GET_FUNC_CNF,								/**< \brief Confirms a  request and returns the level of functionality in the cellular subsystem  \details   */
    CI_DEV_PRIM_GET_FUNC_CAP_REQ,							/**< \brief Requests to get the level of functional capability in the cellular subsystem \details   */
    CI_DEV_PRIM_GET_FUNC_CAP_CNF,							/**< \brief Confirms a  request and returns the level of functional capability in the cellular subsystem \details   */
    CI_DEV_PRIM_SET_GSM_POWER_CLASS_REQ,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_SET_GSM_POWER_CLASS_CNF,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_GET_GSM_POWER_CLASS_REQ,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_GET_GSM_POWER_CLASS_CNF,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_REQ = 20,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_GET_GSM_POWER_CLASS_CAP_CNF,			/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */

    CI_DEV_PRIM_PM_POWER_DOWN_REQ,						/**< \brief Requests to perform power down for the current device \details   */
    CI_DEV_PRIM_PM_POWER_DOWN_CNF,						/**< \brief Confirms a request and powers down the current device \details   */

    CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ,			/**< \brief Requests to set the option for reporting engineering mode information \details If the Periodic option is selected: \n-
  *   - For GSM, CCI sends a periodic CI_DEV_PRIM_GSM_ENGMODE_INFO_IND indication containing the current engineering mode information. For UMTS, the following periodic messages are sent: \n
  *   CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND \n
  *   CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND \n
  *   CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND \n
  *   CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND \n
  *   The report interval is received as the parameter interval of the CiDevPrimSetEngmodeRepOptReq structure.
  *   If the request option is selected, the application requests current engineering mode information using the CI_DEV_PRIM_GET_ENGMODE_INFO_REQ request.
  *   The default option is on request.   */
    CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_CNF,			/**< \brief Confirms a request and sets the option for reporting engineering mode information  \details   */
    CI_DEV_PRIM_GET_ENGMODE_INFO_REQ,					/**< \brief Requests current engineering mode information  \details Use this request when the engineering mode report option is set to on request.
  *   Engineering mode information is currently available for GSM as well as for UMTS.  */
    CI_DEV_PRIM_GET_ENGMODE_INFO_CNF,					/**< \brief Confirms a request and returns current engineering mode information \details Engineering mode information is currently available for GSM as well as UMTS.  */
    CI_DEV_PRIM_ENGMODE_INFO_IND,							/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */

    CI_DEV_PRIM_GSM_ENGMODE_INFO_IND,					/**< \brief Indicates current GSM engineering mode information \details   */
    CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND = 30,		/**< \brief Indicates UMTS engineering mode serving cell information \details   */
    CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND,		/**< \brief Indicates UMTS engineering mode intra-frequency measurements information  \details   */
    CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND,		/**< \brief Indicates UMTS engineering mode inter-frequency measurements information  \details   */
    CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND,			/**< \brief Indicates UMTS engineering mode inter-rat measurements information  \details   */
    CI_DEV_PRIM_DO_SELF_TEST_REQ,							/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_DO_SELF_TEST_CNF,							/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_DO_SELF_TEST_IND,							/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_SET_RFS_REQ,								/**< \brief Requests to change the current reset factory settings \details   */
    CI_DEV_PRIM_SET_RFS_CNF,								/**< \brief Confirms a request and changes the current reset factory setting  \details   */
    CI_DEV_PRIM_GET_RFS_REQ,								/**< \brief Requests to obtain the current reset factory settings  \details   */
    CI_DEV_PRIM_GET_RFS_CNF = 40,							/**< \brief Confirms a request and obtains the current reset factory settings \details   */
    CI_DEV_PRIM_UMTS_ENGMODE_ACTIVE_SET_INFO_IND,		/**< \brief Indicates UMTS engineering mode active set information \details   */
    CI_DEV_PRIM_ACTIVE_PDP_CONTEXT_ENGMODE_IND,			/**< \brief Indicates engineering mode active PDP context information \details   */
    CI_DEV_PRIM_NETWORK_MONITOR_INFO_IND,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_DEV_PRIM_LP_NWUL_MSG_REQ,							/**< \brief Requests the PS to deliver a location position message to the network
															 * \details  The message can contain the location results, location error, or protocol error. */
    CI_DEV_PRIM_LP_NWUL_MSG_CNF,							/**< \brief Confirms a request and delivers a location position message to the network   \details   */
    CI_DEV_PRIM_LP_NWDL_MSG_IND,							/**< \brief Indicates a request from the network to provide location position information, for example, assistance data, location request, or a combination of the two
  *    \details   */
    CI_DEV_PRIM_LP_RRC_STATE_IND,							/**< \brief Indicates a change in the RRC state \details It should be called by ABPS whenever the RRC state changes while a positioning session is active.  */
    CI_DEV_PRIM_LP_MEAS_TERMINATE_IND,					/**< \brief Indicates that the PS terminated the current location session \details A location session is terminated when PS changes RAT or enters out of service.  */
    CI_DEV_PRIM_LP_RESET_STORED_UE_POS_IND,				/**< \brief Indicates a request from the network to reset all stored assistance data
 														 * \details  This is a test I/F message (TIM); therefore, it is not sent by a real network. */
    /*Michal Bukai - Silent Reset support - START*/
    CI_DEV_PRIM_COMM_ASSERT_REQ = 50,                       /**< \brief Requests the communication subsystem to assert \details There is no confirmation for this primitive. This primitive is used for testing. */
    /*Michal Bukai - Silent Reset support - END*/
    /*Michal Bukai *BAND support - START*/
    CI_DEV_PRIM_SET_BAND_MODE_REQ,	/**< \brief Requests the PS to set band and RAT mode
 								   * \details  The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.
									 * If the requested RAT is dual mode, the communication subsystem resets to default band parameters. */

    CI_DEV_PRIM_SET_BAND_MODE_CNF,   /**< \brief Confirms a request and sets band and RAT mode parameters
									  * \details The communication subsystem performs a SW reset after sending the confirmation for updating RAT and band.*/
    CI_DEV_PRIM_GET_BAND_MODE_REQ,   /**< \brief Requests to read the current band and RAT mode setting */
    CI_DEV_PRIM_GET_BAND_MODE_CNF,   /**<  \brief Confirms the request and returns the current band and RAT mode setting */
    CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_REQ,  /**< \brief Requests the supported bands and supported RAT modes */
    CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_CNF,  /**< \brief Confirms the request and returns the supported bands and supported RAT modes */

    /*Michal Bukai *BAND support - END*/
	/*Michal Bukai - IMEI support - START*/
	CI_DEV_PRIM_SET_SV_REQ,								/**< \brief Requests to update the SV digits in IMEISV. \details The default value of the SV digits is the value set during production.  */
	CI_DEV_PRIM_SET_SV_CNF,								/**< \brief Confirms a request to set SV digits in IMEISV. \details   */
	CI_DEV_PRIM_GET_SV_REQ,								/**< \brief Requests to get the SV digits in IMEISV. \details   */
	CI_DEV_PRIM_GET_SV_CNF = 60,						/**< \brief Confirms a request and returns the SV digits in IMEISV. \details The full IMEISV can be read using the primitive CI_DEV_PRIM_GET_SERIALNUM_ID_REQ to read IMEI and this primitive to get SV digits.   */
	/*Michal Bukai - IMEI support - END*/

    CI_DEV_PRIM_AP_POWER_NOTIFY_REQ,
    CI_DEV_PRIM_AP_POWER_NOTIFY_CNF,

	CI_DEV_PRIM_SET_TD_MODE_TX_RX_REQ,					/**< \brief Requests to set Tx or Rx on TD for radio testing.  */
	CI_DEV_PRIM_SET_TD_MODE_TX_RX_CNF,					/**< \brief Confirms the TD Tx/Rx mode request.   */
	CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_REQ,				/**< \brief Requests to set loopback mode on TD for radio testing.   */
	CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_CNF,				/**< \brief Confirms to set loopback mode on TD for radio testing.   */

	CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ,					/**< \brief Requests to set Tx/Rx on GSM for radio testing.  */
	CI_DEV_PRIM_SET_GSM_MODE_TX_RX_CNF,					/**< \brief Confirms the GSM Tx/Rx mode request.   */
	CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_REQ,			/**< \brief Requests to set GSM for control interface.   */
	CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_CNF = 70,		/**< \brief Confirms to set option on GSM for control interface testing.   */
	CI_DEV_PRIM_ENABLE_HSDPA_REQ,
	CI_DEV_PRIM_ENABLE_HSDPA_CNF,
	CI_DEV_PRIM_GET_HSDPA_STATUS_REQ,
	CI_DEV_PRIM_GET_HSDPA_STATUS_CNF,

    CI_DEV_PRIM_READ_RF_TEMPERATURE_REQ,                /**< \brief Requests to read temperature from RF chip.  */
    CI_DEV_PRIM_READ_RF_TEMPERATURE_CNF,                /**< \brief Confirms to read temperature from RF chip.   */

    /*Mason CMCC Smart Network Monitor support - START*/
    /* AT^DCTS */
    CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ,
    CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF,
    CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_REQ,
    CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF = 80,

    /* AT^DEELS */
    CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ,
    CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF,
    CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_REQ,
    CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF,
    CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND,

    /* AT^DEVEI */
    CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ,
    CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF,
    CI_DEV_PRIM_GET_EVENT_IND_CONFIG_REQ,
    CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF,
    CI_DEV_PRIM_EVENT_REPORT_IND = 90,

    /* AT^DNPR */
    CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ,
    CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF,
    CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_REQ,
    CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF,
    CI_DEV_PRIM_WIRELESS_PARAM_IND,

    /* AT^DUSR */
    CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ,
    CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF,
    CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_REQ,
    CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF,
    CI_DEV_PRIM_SIGNALING_REPORT_IND = 100,
    /*Mason CMCC Smart Network Monitor support -- END*/

    /*Alan DIP Channel support -- START*/
	CI_DEV_PRIM_DIP_CHANNEL_CHANGE_IND,
	/*Alan DIP Channel support -- END*/

    /*Add by Alan for LteEngModeInfoInd 12192012 -- Start*/
    CI_DEV_PRIM_LTE_ENGMODE_INFO_IND,
    /*Add by Alan for LteEngModeInfoInd 12192012 -- End*/
	
    CI_DEV_PRIM_CURRENT_AMR_CODEC_IND,
    
/*Add by Alan for Power BackOff  04082013, begin*/
    CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ,        /**< \brief Requests to set feature calibration of Grip Sensor TX power.  */
    CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF,        /**< \brief Confirms to set feature calibration of Grip Sensor TX power.  */
/*Add by Alan for Power BackOff  04082013, end*/

    CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ,  /**< \brief Requests the internal revision ID and build time \details   */
    CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF,  /**< \brief Confirms a request and returns the internal revision ID and build time  \details   */

    CI_DEV_PRIM_SET_COM_CONFIG_REQ,     /**< \brief Set a com related configuration.
                                                                      * \details Sending this CI overrides the value configured through the com config NVM file on the com side. It does not update the com config NVM file.   */
    CI_DEV_PRIM_SET_COM_CONFIG_CNF,     /**< \brief Confirms the request to set a com related configuration \details   */
    CI_DEV_PRIM_GET_COM_CONFIG_REQ = 110,     /**< \brief Request to get a com configuration token \details   */
    CI_DEV_PRIM_GET_COM_CONFIG_CNF,     /**< \brief Confirmation and get com config token \details   */

/*Add by Alan for WCDMA Radio test  05292013, begin*/
    CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_REQ,   /**< \brief Requests to set Tx or Rx on WCDMA for radio testing.  */
    CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_CNF,   /**< \brief Confirms the WCDMA Tx/Rx mode request.   */

    /*Michal Bukai - Security Configuration - Samsung - START*/
    CI_DEV_PRIM_SET_SECURITY_PARAMS_REQ,                /**< \brief Requests to enable / disable ciphering and integrity protection. \details The setting will affect
                                                        *   the ciphering and integrity UE capabilities reported to the NW .
                                                        *   In case ciphering or integrity protection is enabled, the reported capabilities will be derived from NVM setting.
                                                        *   In case ciphering or  integrity protection is disabled, all algorithms will be reported as unsupported,
                                                        *   This command will not affect NVM setting.*/
    CI_DEV_PRIM_SET_SECURITY_PARAMS_CNF,                /**< \brief Confirms a request to enable / disable ciphering and integrity protection \details   */
    CI_DEV_PRIM_GET_SECURITY_PARAMS_REQ,                /**< \brief Requests to read ciphering and integrity protection status \details   */
    CI_DEV_PRIM_GET_SECURITY_PARAMS_CNF,                /**< \brief Confirms the request and returns the ciphering and integrity protection status \details   */
    /*Michal Bukai - Security Configuration - Samsung - END*/
    CI_DEV_PRIM_RESET_REQUEST_IND,						/**< \brief Indication to request the apps to perform com reset   */
    CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_REQ,			/**< \brief Requests to set the option for reporting user testing information   */
    CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_CNF = 120,			/**< \brief Confirms a request for reporting user testing information   */
    CI_DEV_PRIM_USER_TEST_VALUABLE_EVENT_REPORT_IND,			/**< \brief Reports a user testing valuable event   */
	CI_DEV_PRIM_SET_PARK_MODE_REQ,						/**< \brief Request to set the modem to enter or exit park mode */
	CI_DEV_PRIM_SET_PARK_MODE_CNF,						/**< \brief Confirm the request to set the park mode. */
	CI_DEV_PRIM_GET_PARK_MODE_REQ,						/**< \brief Request to get current status of park mode. */
	CI_DEV_PRIM_GET_PARK_MODE_CNF,						/**< \brief Confirmation for the request to get the current park mode setting */

	CI_DEV_PRIM_LP_ECID_MEAS_REQ,
	CI_DEV_PRIM_LP_ECID_MEAS_CNF,

	CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_REQ,
	CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_CNF,
	CI_DEV_PRIM_LP_UE_AREA_INFO_IND = 130,
    CI_DEV_PRIM_SET_IMS_MEDIA_REQ,                      /**< \brief Request to set IMS Media configuration parameters   */
    CI_DEV_PRIM_SET_IMS_MEDIA_CNF,                      /**< \brief Confirmation to the setting of the IMS media   */
    CI_DEV_PRIM_IMS_MEDIA_IND,                      /**< \brief Indication from the IMS media on the com side   */

	/* Lilei VZWRSRP&VZWRSRQ support -- Start */
    CI_DEV_PRIM_GET_LTE_MEAS_REQ,						/**< \brief Request to get lte rsrp&rsrq measurement info.  */
    CI_DEV_PRIM_GET_LTE_MEAS_CNF,						/**< \brief Confirm the request to get lte rsrp&rsrq measurement info.  */
	/* Lilei VZWRSRP&VZWRSRQ support -- End */

	/* Lilei LTE&WIFI coexist support 20131022 -- Start */
    CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ,
    CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_CNF,
    CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ,
    CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF,
    CI_DEV_PRIM_LTE_COEX_INFO_IND = 140,
	/* Lilei LTE&WIFI coexist support 20131022 -- End */

/*Added by Lilei for neighbor cell info report on 01082014, begin*/
//#if defined(SS_IPC_SUPPORT)
    CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_REQ,    /**< \brief Requests to enable/disable the report of neighbor cell information \details If it's enabled, \n
  *   CCI sends a periodic CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND indication containing the current neighbor cell information. \n
  *   The report interval is received as the parameter interval of the CiDevPrimSetEngmodeNcellRepOptReq structure, or set a defualt value. */
    CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_CNF,    /**< \brief Confirms a request of enable/disable the report of neighbor cell information  \details   */
    CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_REQ,             /**< \brief Requests current neighbor cell information  \details */
    CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_CNF,             /**< \brief Confirms a request and returns current neighbor cell information \details */
    CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND,                 /**< \brief Indicates current neighbor cell information \details */
//#endif
/*Added by Lilei for neighbor cell info report on 01082014, end*/

/*Added by Lilei for LTE Radio test on 01232014, begin*/
    CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ,   /**< \brief Requests to set Tx or Rx on LTE for radio testing.  */
    CI_DEV_PRIM_SET_LTE_MODE_TX_RX_CNF,   /**< \brief Confirms the LTE Tx/Rx mode request.   */
/*Added by Lilei for LTE Radio test on 01232014, end*/

/* Merged from UMTS7_Rel by Lilei 02182014, begin */
/*Add by Alan for L2RandomFillBitsEnabled on 02082014, CQ54160, begin*/
    CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_REQ,  /**< \brief Requests to set L2RandomFillBitsEnabled.  */
    CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_CNF,  /**< \brief Confirms to set L2RandomFillBitsEnabled request. */   
    CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_REQ = 150,  /**< \brief Requests to get L2RandomFillBitsEnabled.  */
    CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_CNF,  /**< \brief Confirms to get L2RandomFillBitsEnabled request. */   
/*Add by Alan for L2RandomFillBitsEnabled on 02082014, CQ54160, end*/

/*Add by Alan for reporting T323 on 02082014, CQ54159, begin*/
    CI_DEV_PRIM_T323_IND,
/*Add by Alan for reporting T323 on 02082014, CQ54159, end*/
/* Merged from UMTS7_Rel by Lilei 02182014, end */

/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND,   /**< \brief Indicates LTE engineering mode serving cell information \details   */
    CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND, /**< \brief Indicates LTE engineering mode intra-frequency measurements information  \details   */
    CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND, /**< \brief Indicates LTE engineering mode inter-frequency measurements information  \details   */
    CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND,  /**< \brief Indicates LTE engineering mode inter-rat measurements information  \details   */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

/*Add by Alan for MCC, MNC and CC on 03102014, CQ54159, begin*/
   CI_DEV_PRIM_SET_MCC_MNC_CC_REQ,  /**< \brief Requests to set MCC_MNC_CC.  */
   CI_DEV_PRIM_SET_MCC_MNC_CC_CNF,  /**< \brief Confirms to set MCC_MNC_CC request. */   
   CI_DEV_PRIM_GET_MCC_MNC_CC_REQ,  /**< \brief Requests to get MCC_MNC_CC.  */
   CI_DEV_PRIM_GET_MCC_MNC_CC_CNF = 160,  /**< \brief Confirms to get MCC_MNC_CC request. */   
/*Add by Alan for MCC, MNC and CC on 03102014, CQ54159, end*/

/*Added by Lilei for AT*L1DEBUG CQ60995 on 05162014, begin*/
    CI_DEV_PRIM_SET_L1DEBUG_REQ,    /**< \brief Requests to set L1 debug data. */
    CI_DEV_PRIM_SET_L1DEBUG_CNF,    /**< \brief Confirms to set L1 debug data. */
    CI_DEV_PRIM_L1DEBUG_INFO_IND,   /**< \brief Indicates L1 debug info. */
/*Added by Lilei for AT*L1DEBUG CQ60995 on 05162014, end*/

/*Added by Lilei for LTE positioning support, begin*/
    CI_DEV_PRIM_LP_OTDOA_MEAS_REQ,
    CI_DEV_PRIM_LP_OTDOA_MEAS_CNF,
    CI_DEV_PRIM_LP_OTDOA_MEAS_IND,
    CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ,
    CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_CNF,
    CI_DEV_PRIM_RETRIEVE_LOCATION_IND,
    CI_DEV_PRIM_RETRIEVE_LOCATION_RSP = 170,
/*Added by Lilei for LTE positioning support, end*/

/* Added by lalon CIQ Eng mode begin */
	CI_DEV_PRIM_COMMON_ENGMODE_INFO_IND,				  
	CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_REQ,
	CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_CNF,
	CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_REQ,
	CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_CNF,
/* Added by lalon CIQ Eng mode end */
	/*Added by arthurr for FRAT feature begin*/
	CI_DEV_PRIM_SET_IGNITION_STATE_REQ,
	CI_DEV_PRIM_SET_IGNITION_STATE_CNF,
	CI_DEV_PRIM_GET_IGNITION_STATE_REQ,
	CI_DEV_PRIM_GET_IGNITION_STATE_CNF,
	/*Added by arthurr for FRAT feature end*/


/*Lilei, CQ00079390, 20141217, begin*/
    CI_DEV_PRIM_SET_IMLCONFIG_REQ = 180,
    CI_DEV_PRIM_SET_IMLCONFIG_CNF,
    CI_DEV_PRIM_GET_IMLCONFIG_REQ,
    CI_DEV_PRIM_GET_IMLCONFIG_CNF,
/*Lilei, CQ00079390, 20141217, end*/

/*Lilei, CQ00080629, 20150104, begin*/
    CI_DEV_PRIM_RB_TEST_MODE_IND,           /**< \brief Indicates RB Test Loopback Mode status. */
/*Lilei, CQ00080629, 20150104, end*/

/*Lilei, CQ00085118, 20150202, begin*/
    CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ,     /**< \brief Requests to set LTE band scan order. */
    CI_DEV_PRIM_SET_LTE_BAND_ORDER_CNF,     /**< \brief Confirms to set LTE band scan order. */
    CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ,     /**< \brief Requests to get LTE band scan order. */
    CI_DEV_PRIM_GET_LTE_BAND_ORDER_CNF,     /**< \brief Confirms to get LTE band scan order. */
/*Lilei, CQ00085118, 20150202, end*/

    
/*Lilei, CQ00087682, 20150304, begin*/
    CI_DEV_PRIM_SET_SALES_CODE_REQ,
    CI_DEV_PRIM_SET_SALES_CODE_CNF = 190,
    CI_DEV_PRIM_GET_SALES_CODE_REQ,
    CI_DEV_PRIM_GET_SALES_CODE_CNF,
    CI_DEV_PRIM_SET_OPER_CONFIG_REQ,
    CI_DEV_PRIM_SET_OPER_CONFIG_CNF,
    CI_DEV_PRIM_GET_OPER_CONFIG_REQ,
    CI_DEV_PRIM_GET_OPER_CONFIG_CNF,
/*Lilei, CQ00087682, 20150304, end*/
    CI_DEV_PRIM_MRD_CONFIG_REQ,// don't distinguish read/write/del operation, just transfer to platform
	CI_DEV_PRIM_MRD_CONFIG_CNF,// don't distinguish read/write/del operation, just transfer to platform		
	CI_DEV_PRIM_GET_STATUS_REQ,//added by taow 20170524 
	CI_DEV_PRIM_GET_STATUS_CNF = 200,

/*Lilei, CQ00108730, 20171225, begin*/
    CI_DEV_PRIM_FACTORY_RESET_REQ,
    CI_DEV_PRIM_FACTORY_RESET_CNF,
/*Lilei, CQ00108730, 20171225, end*/

/*Lilei, CQ00112021, 20180903, begin*/
    CI_DEV_PRIM_GET_IMS_UL_STATISTIC_REQ,
    CI_DEV_PRIM_GET_IMS_UL_STATISTIC_CNF,
/*Lilei, CQ00112021, 20180903, end*/

    /*add by taow 20180525 CQ00110536 begin*/
    CI_DEV_PRIM_SET_MEDATA_RESERVER_REQ,     /**< \brief Requests to set MEDATA COMM RESERVER . */
    CI_DEV_PRIM_SET_MEDATA_RESERVER_CNF,     /**< \brief Requests to set MEDATA COMM RESERVER . */
    CI_DEV_PRIM_GET_MEDATA_RESERVER_REQ,     /**< \brief Requests to get MEDATA COMM RESERVER . */
    CI_DEV_PRIM_GET_MEDATA_RESERVER_CNF,     /**< \brief Requests to get MEDATA COMM RESERVER . */
    /*add by taow 20180525 CQ00110536 end*/

/*Lilei, CQ00115548, 20190719, begin*/
    CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ,     /**< \brief Requests to set cell select config. */
    CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF = 210,     /**< \brief Requests to set cell selectr config. */
    CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ,      /**< \brief Requests to get cell select config. */
    CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF,     /**< \brief Requests to get cell select config. */
/*Lilei, CQ00115548, 20190719, end*/
    
    CI_DEV_PRIM_COMMON_REPORT_IND,          /**< \brief Indicates common reports. */
    /*20190819 CQ00116678 add by taow begin*/
    CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_REQ,
    CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_CNF,
    CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_REQ,
    CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_CNF,
    CI_DEV_PRIM_SET_BLACK_CELL_REQ,
    CI_DEV_PRIM_SET_BLACK_CELL_CNF,
    CI_DEV_PRIM_GET_BLACK_CELL_REQ = 220,
    CI_DEV_PRIM_GET_BLACK_CELL_CNF,
    /*20190819 CQ00116678  add by taow end*/
    
/*Lilei, CQ00113795, 20190215, begin*/
    CI_DEV_PRIM_SET_FEATURE_CONFIG_REQ,
    CI_DEV_PRIM_SET_FEATURE_CONFIG_CNF,
    CI_DEV_PRIM_GET_FEATURE_CONFIG_REQ,
    CI_DEV_PRIM_GET_FEATURE_CONFIG_CNF,
    CI_DEV_PRIM_SET_ROAM_CONFIG_REQ,
    CI_DEV_PRIM_SET_ROAM_CONFIG_CNF,
    CI_DEV_PRIM_GET_ROAM_CONFIG_REQ,
    CI_DEV_PRIM_GET_ROAM_CONFIG_CNF,
/*Lilei, CQ00113795, 20190215, end*/

    /*Lilei, CQ00119368, 20200331, begin*/
    CI_DEV_PRIM_CELLS_INFO_IND = 230,             /**< \brief Report cells info. */
    /*Lilei, CQ00119368, 20200331, end*/

/* ==============  Added for REL13 ====================================================*/
    CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_REQ,     /**< \brief Requests to set hardware PSM configuration . */
    CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_CNF,     /**< \brief Confirms to set hardware PSM configuration . */
    CI_DEV_PRIM_GET_HW_PSM_PROFILE_REQ,        /**< \brief Requests to get hardware PSM configuration . */
    CI_DEV_PRIM_GET_HW_PSM_PROFILE_CNF,        /**< \brief Confirms to get hardware PSM configuration . */

    /*Lilei, CQ00126499, 20201207, begin*/
    CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_REQ,     /**< \brief Requests to set DRX dynamic adjust params. */
    CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_CNF,     /**< \brief Confirms to set DRX dynamic adjust params. */
    /*Lilei, CQ00126499, 20201207, end*/

    /*Lilei, CQ00127745, 20210119, begin*/
    CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_REQ,    /**< \brief Requests to set antenna tuner param. */
    CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_CNF,    /**< \brief Confirms to set antenna tuner param. */
    /*Lilei, CQ00127745, 20210119, end*/

    /*Lilei, CQ00131521, 20210706, begin*/
    CI_DEV_PRIM_PAGING_FAILURE_IND,             /**< \brief Report paging failure ind. */
    /*Lilei, CQ00131521, 20210706, end*/
    /* add by taow 20211214 CQ00134561 begin*/
    CI_DEV_PRIM_SET_COMMON_FEATURE_REQ = 240,
    CI_DEV_PRIM_SET_COMMON_FEATURE_CNF,

    CI_DEV_PRIM_GET_COMMON_FEATURE_REQ,
    CI_DEV_PRIM_GET_COMMON_FEATURE_CNF,
    /* add by taow 20211214 CQ00134561 end*/
    /*add by lilei 20220119 CQ00135497 begin */
    CI_DEV_PRIM_SET_NST_TX_RX_REQ,              /**< \brief Requests to set NST Tx or Rx for radio testing.  */
    CI_DEV_PRIM_SET_NST_TX_RX_CNF,              /**< \brief Confirms the NST Tx/Rx mode request.   */
    /*add by lilei 20220119 CQ00135497 end */

	CI_DEV_PRIM_SET_SIM_SLOT_REQ,
	CI_DEV_PRIM_SET_SIM_SLOT_CNF,
	CI_DEV_PRIM_GET_SIM_SLOT_REQ,
	CI_DEV_PRIM_GET_SIM_SLOT_CNF,
	
    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_DEV_PRIM_LAST_COMMON_PRIM' */
    /* END OF COMMON PRIMITIVES LIST */
    CI_DEV_PRIM_LAST_COMMON_PRIM

    /* The customer specific extension primitives must be added starting from
    * CI_DEV_PRIM_firstCustPrim = CI_DEV_PRIM_LAST_COMMON_PRIM as the first identifier.
    * The actual primitive names and IDs are defined in the associated
    * 'ci_dev_cust_xxx.h' file.
    */

    /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiDevPrim;

/* specify the number of default common DEV primitives */
#define CI_DEV_NUM_COMMON_PRIM ( CI_DEV_PRIM_LAST_COMMON_PRIM - 1 )
/**@}*/

/*Michal Bukai - I-Mate Addition. Start:*/
/****************************************/
//ICAT EXPORTED ENUM
typedef enum CIDEV_AMR_CODEC_TYPE_TAG{
    CI_DEV_CODEC_WB_AMR = 0,
    CI_DEV_CODEC_NB_AMR = 1,
    CI_DEV_CODEC_OTHERS = 2,
    
    CI_DEV_NUM_OF_CODEC_TYPES
}_CiDevAmrCodecType;

typedef UINT8 CiDevAmrCodecType;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_CURRENT_AMR_CODEC_IND">   */
typedef struct CiDevPrimCurrentAmrCodecInd_struct
{
    CiDevAmrCodecType codecType;
	UINT32			  speechCodecRate;//added by taow 20141106
} CiDevPrimCurrentAmrCodecInd;

/** \brief Cell priority values  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_CELL_PRIORITY_TYPE_TAG{
	CI_DEV_CELL_PRIORITY_NORMAL =0,	/**< Normal cell priority */
	CI_DEV_CELL_PRIORITY_BARRED,		/**< Barred cell priority */
	CI_DEV_CELL_PRIORITY_LOW,			/**< Low cell priority */
	CI_DEV_NUM_CELL_PRIORITY
} _CiDevCellPrioriytType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Cell priority values
 * \sa CIDEV_CELL_PRIORITY_TYPE_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiDevCellPrioriytType;
/**@}*/

/** \brief List of ARFCNs assigned for frequency hopping */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevHoppingGroup_struct
{
      UINT8 	length;				/**< Length of the arfcn list. Range is 0-64.0 - means list is not available */
      UINT16    Arfcns[CI_DEV_MAX_ARFCN_LIST];	/**< Absolute radio frequency channel number */
} CiDevHoppingGroup;

/*Michal Bukai - I-Mate Addition. End*/
/****************************************/
/** \brief Device status  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVSTATUS_TAG{
    CI_DEV_STATUS_READY = 0,    		/**< Device is ready to handle requests */
    CI_DEV_STATUS_UNAVAILABLE,   	/**< Device cannot handle requests */
    CI_DEV_STATUS_UNKNOWN,       	/**< Device status unknown */
    CI_DEV_STATUS_RINGING,       		/**< Device is ringing */
    CI_DEV_STATUS_CALLINPROG,    	/**< Device has a call in progress */
    CI_DEV_STATUS_ASLEEP,        		/**< Device is in a low functionality state */
    CI_DEV_STATUS_CALLACTIVE,      /**< Device has a call in active */

    CI_DEV_NUM_STATUSES
} _CiDevStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Device status
 * \sa CIDEVSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevStatus;
/**@}*/

/** \brief DEV group return codes */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRCDEV_TAG{
    CIRC_DEV_SUCCESS = 0,   				/**< Request completed successfully */
    CIRC_DEV_FAILURE,       				/**< Phone failure */
    CIRC_DEV_NO_CONNECTION, 				/**< No connection to phone */
    CIRC_DEV_UNKNOWN,       				/**< Unknown error */
	CIRC_DEV_INVALID_PARAMETER,				/**< Generic error - the requested service primitive has invalid parameters */
	CIRC_DEV_INVALID_REQ,					/**< Generic error - the requested service primitive can not be handled at current state */
	CIRC_DEV_SIM_NOT_READY,					/**< Generic error - the requested service primitive fails because SIM is not ready */
	CIRC_DEV_ACCESS_DENIED,					/**< Generic error - the requested service primitive fails because access is denied */ 
#if defined(SS_IPC_SUPPORT)
	CIRC_DEV_ERR_SIM_NOT_INSERTED,
#endif

	CIRC_DEV_BUSY_WITH_OTHER_PROCESS,		/**< Generic error - the requested service primitive fails because other process is ongoing */ 

    CIRC_DEV_NUM_RESCODES
} _CiDevRc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Result code
 *  \sa CIRCDEV_TAG
 * \remarks Common Data Section */
typedef UINT16 CiDevRc;
/**@}*/

/** \brief Phone functionality mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVFUNC_TAG{
    CI_DEV_FUNC_MIN = 0,          		/**< Minimum functionality (lowest power level) */
    CI_DEV_FUNC_FULL,             		/**< Full functionality (highest power level) */
    CI_DEV_FUNC_DISABLE_TX_RF,    	/**< Disable phone transmit RF circuits only */
    CI_DEV_FUNC_DISABLE_RX_RF,    	/**< Disable phone receive RF circuits only */
    CI_DEV_FUNC_DISABLE_BOTH_RF,  	/**< Disable both phone transmit and receive RF circuits */
    CI_DEV_FUNC_UPDATE_NVM_MIN,   /**< Update NVM file with minimum functionality mode */
    CI_DEV_FUNC_UPDATE_NVM_FULL,  /**< Update NVM file with full functionality mode */
    CI_DEV_FUNC_MIN_NO_IMSI_DETACH, /**< minimum functionality but without IMSI detach */
    CI_DEV_FUNC_DISABLE_SIM,    /**< disable SIM */    
    CI_DEV_FUNC_UPDATE_NVM_DISABLE_BOTH_RF = 9,  /**< Update NVM file with both transmit and receive RF circuits disable mode */
    CI_DEV_FUNC_FULL_SECONDARY_RX_OFF = 10, 	 /**< full functionality for primary RF, secondary RX is OFF */

    /*Lilei, CQ00085158, 20150128, begin*/
    CI_DEV_FUNC_INIT_RF_3G,          /**< Init 3G RF setting. Only used for 3G RF test */
    CI_DEV_FUNC_PRI_ONLY_RF_3G,      /**< Enable only primary RF (Pri TX + Pri RX). Only used for 3G RF test */
    CI_DEV_FUNC_SEC_ONLY_RF_3G,      /**< Enable only secondary RF (Pri TX + Sec RX). Only used for 3G RF test */
    CI_DEV_FUNC_PRI_SEC_RF_3G,       /**< Enable both primary and secondary RF (Pri TX + Pri RX + Sec RX). Only used for 3G RF test */
    /*Lilei, CQ00085158, 20150128, end*/

    CI_DEV_NUM_FUNCS
} _CiDevFunc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Phone functionality mode
 *  \sa CIDEVFUNC_TAG
 * \remarks Common Data Section */
typedef UINT8 CiDevFunc;
/**@}*/

/** \brief Phone functionality mode. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVCOMMFEATURECONFIG_TAG {
    CI_DEV_CSD = 1,			/**< CSD is supported */
    CI_DEV_FAX,				/**< FAX is supported */
    CI_DEV_PRODUCTION,		/**< Production Mode is in use*/
    CI_DEV_CONVENTIONAL_GPS,/**< Conventional GPS is supported */
    CI_DEV_MS_BASED_GPS,	/**< Ms-Based A-GPS is supported */
    CI_DEV_MS_ASSISTED_GPS, /**< Ms-Assisted A-GPS is supported */

    CI_DEV_NUM_COMM_FEATURE_CONFIG    
} _CommFeatureConfig;

/** \brief Band mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVBAND_TAG{
    CI_DEV_BAND_GSM_900 = 0,		/**< GSM_900 band */
    CI_DEV_BAND_GSM_1800,			/**< GSM_1800 band */
    CI_DEV_BAND_GSM_1900,			/**< GSM_1900 band */
    CI_DEV_BAND_GSM_400,			/**< GSM_400 band */

    CI_DEV_NUM_BANDS
} _CiDevBand;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Band mode
 *  \sa CIDEVBAND_TAG
 * \remarks Common Data Section */
typedef UINT8 CiDevBand;
/**@}*/

/** \brief Power classes values, refer to 3GPP TS 45.05  4.1.1 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVPWCLS_TAG{
    CI_DEV_PWCLS_DEFAULT = 0,          /**< Default power class */
    CI_DEV_PWCLS_1,                    /**< Power class 1 */
    CI_DEV_PWCLS_2,                    /**< Power class 2 */
    CI_DEV_PWCLS_3,                    /**< Power class 3 */
    CI_DEV_PWCLS_4,                    /**< Power class 4 */
    CI_DEV_PWCLS_5,                    /**< Power class 5 */

    CI_DEV_NUM_PWCLSES
} _CiDevPwCls;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Power classes
 * \sa CIDEVPWCLS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevPwCls;

/* Engineering mode: Reporting options */

/* Engineering mode: Maximum Number of Neighboring cells in Report */
#define CI_DEV_MAX_GSM_NEIGHBORING_CELLS     6     /* GSM neighbors */
#define CI_DEV_MAX_UMTS_NEIGHBORING_CELLS   32    /* FDD and GSM neighbors */

/* Maximum number of cells in active set */
#define CI_DEV_MAX_CELLS_IN_AS                          6

/**@}*/

/** \brief Engineering mode: Reporting option type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_REPORTOPTION_TAG
{
    CI_DEV_EM_OPTION_NONE = 0,  	/**< Engineering mode report delivery: Turn off */
    CI_DEV_EM_OPTION_REQUEST,   	/**< Engineering mode report delivery: On request */
    CI_DEV_EM_OPTION_PERIODIC,  	/**< Engineering mode report delivery: Periodic */
    /*Lilei, CQ00091516, 20150423, begin*/
    CI_DEV_EM_OPTION_INTERNAL_CALL_END, /**< Engineering mode opened for internal purpose: call end statistic */
    /*Lilei, CQ00091516, 20150423, end*/
    CI_DEV_NUM_EM_REPORT_OPTIONS
} _CiDevEngModeReportOption;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode: reporting option type
 * \sa CIDEV_ENGMODE_REPORTOPTION_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevEngModeReportOption;
/**@}*/

/** \brief Engineering mode: mode type/state  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_STATE_TAG
{
    CI_DEV_EM_GSM_IDLE_STATE = 0,			/**< Mode is GSM in idle */
    CI_DEV_EM_GSM_DEDICATED_STATE,		/**< Mode is GSM in dedicated */
    CI_DEV_EM_GPRS_EGPRS_PTM_STATE,		/**< Mode is GSM and at least one PDP context is activated*/
    CI_DEV_EM_INVALID_STATE,

    /* This must be the last entry */
    CI_DEV_NUM_EM_STATES
} _CiDevEngModeState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode: mode type/state
 * \sa CIDEV_ENGMODE_STATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevEngModeState;
/**@}*/

/** \brief Engineering mode: network type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_NETWORK_TAG
{
    CI_DEV_EM_NETWORK_GSM = 0,		/**< GSM network */
    CI_DEV_EM_NETWORK_UMTS,			/**< UMTS network */
    CI_DEV_EM_NETWORK_LTE,          /**< LTE Network */   

    /* This must be the last entry */
    CI_DEV_NUM_EM_NETWORKS
} _CiDevEngModeNetwork;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode: Network type
 * \sa CIDEV_ENGMODE_NETWORK_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevEngModeNetwork;
/**@}*/

/** \brief Engineering mode: 3G user equipment (UE) RRC state */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_UERRC_STATE_TAG
{
    CI_DEV_EM_UERRC_DEACTIVATED = 0,			/**< (UE) RRC state DEACTIVATED RRC state */
    CI_DEV_EM_UERRC_SUSPENDED,				/**< (UE) RRC state SUSPENDED RRC state */
    CI_DEV_EM_UERRC_IDLE,						/**< (UE) RRC state IDLE RRC state */
    CI_DEV_EM_UERRC_CONN_URA_PCH,			/**< (UE) RRC state CONN_URA_PCH RRC state */
    CI_DEV_EM_UERRC_CONN_CELL_PCH,			/**< (UE) RRC state CONN_CELL_PCH RRC state */
    CI_DEV_EM_UERRC_CONN_CELL_FACH,			/**< (UE) RRC state DEACTIVATED RRC state */
    CI_DEV_EM_UERRC_CONN_CELL_DCH,			/**< (UE) RRC state CONN_CELL_FACH RRC state */

    /* This must be the last entry */
    CI_DEV_NUM_EM_UERRC_STATES
} _CiDevEngModeUeRrcState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode: 3G user equipment (UE) RRC state
 * \sa CIDEV_ENGMODE_UERRC_STATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevEngModeUeRrcState;
/**@}*/

/* ===================================================================================
                2G (GSM) Engineering Mode Structures
   ===================================================================================*/

/** \brief Network monitor mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_NETWORKMONITOR_MODE_TAG
{
    CI_DEV_NM_IDLE_MODE = 0,			/**< Current GSM mode - idle */
    CI_DEV_NM_DEDICATED_MODE,			/**< Current GSM mode - dedicated  */
    CI_DEV_NM_GPRS_MODE,				/**< Current GSM mode - during GPRS  */

    /* This must be the last entry */
    CI_DEV_NUM_NM_MODES
} _CiDevNetworkMonitorMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network monitor mode
 * \sa CIDEV_NETWORKMONITOR_MODE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevNetworkMonitorMode;
/**@}*/
/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_BEPCVMEAN_STATUS_TAG{
        CI_DEV_BEP_NONE    =0,
        CI_DEV_BEP_GMSK,
        CI_DEV_BEP_EIGHT_PSK,
        CI_DEV_BEP_GMSK_AND_EIGHT_PSK,
        CI_DEV_NUM_BEP_STATUS
} _CiDevBepCvMeanStatus;
/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
typedef UINT32 CiDevBepCvMeanStatus;

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_CHANNEL_TYPE_TAG
{
    CI_DEV_TCH_F_PLUS_ACCH  = 1,
    CI_DEV_TCH_H_PLUS_ACCH  = 2,
    CI_DEV_SDCCH_4  = 4,
    CI_DEV_SDCCH_8  = 8,

    /* This must be the last entry */
    CI_DEV_NUM_CHANNEL_TYPE
} _CiDevChannelType;

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
typedef UINT8 CiDevChannelType;


/** \brief Modulation scheme */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_MODULATION_SCHEME_TAG
{
    CI_DEV_MS_GMSK = 0,			/**< GMSK */
    CI_DEV_MS_8PSK = 1,			/**< 8PSK */
    CI_DEV_MS_INVALID = 0xff,	/**< Invalid value */
    CI_DEV_NUM_MS				/**< Must be the last entry */
} _CiDevModulationScheme;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Modulation scheme
 * \sa CIDEV_MODULATION_SCHEME_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevModulationScheme;
/**@}*/

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_CODE_SCHEME_TAG
{
    CI_DEV_CS_CS_1 = 0,
    CI_DEV_CS_CS_2,
    CI_DEV_CS_CS_3,
    CI_DEV_CS_CS_4,
    CI_DEV_CS_CS_RACH_8,
    CI_DEV_CS_CS_RACH_11,
    CI_DEV_CS_MCS_1,
    CI_DEV_CS_MCS_2,
    CI_DEV_CS_MCS_3,
    CI_DEV_CS_MCS_4,
    CI_DEV_CS_MCS_5,
    CI_DEV_CS_MCS_6,
    CI_DEV_CS_MCS_7,
    CI_DEV_CS_MCS_8,
    CI_DEV_CS_MCS_9,
    CI_DEV_CS_MCS_5_7,
    CI_DEV_CS_MCS_6_9,
    CI_DEV_CS_INVALID = 0xff,

    /* This must be the last entry */
    CI_DEV_NUM_CS
} _CiDevCodeScheme;

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
typedef UINT8 CiDevCodeScheme;


/** \brief Packet idle type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_PACKET_IDLE_TYPE_TAG
{
    CI_DEV_PACKET_IDLE_NONE = 0,  /**< Not attached to packet domain */
    CI_DEV_PACKET_IDLE_GPRS,      /**< Packet domain supports GPRS */
    CI_DEV_PACKET_IDLE_EDGE,      /**< Packet domain supports GPRS and EDGE */

    /* This must be the last entry */
    CI_DEV_NUM_PACKET_IDLE
} _CiDevPacketIdleType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Packet idle type
 * \sa CIDEV_PACKET_IDLE_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevPacketIdleType;
/**@}*/

/** \brief GPRS service type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_GPRS_SERVICE_TYPE_TAG
{
    CI_DEV_GPRS_SERVICE_TYPE_GRPS = 0,   /**< Packet domain support GPRS */
    CI_DEV_GPRS_SERVICE_TYPE_EDGE,       /**< Packet domain support GPRS and EDGE */

    /* This must be the last entry */
    CI_DEV_NUM_SERVICE_TYPE
} _CiDevGprsServiceType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GPRS service type
 * \sa CIDEV_GPRS_SERVICE_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevGprsServiceType;
/**@}*/

/** Not in use - BEP Info */
//ICAT EXPORTED STRUCT
typedef struct CiDevEgprsBepCvMeanInfo_struct
{
    CiDevBepCvMeanStatus   status;

    UINT8    				gmskMeanBep;
    UINT8    				gmskCvBep;
    UINT8    				eightPskMeanBep;
    UINT8    				eightPskCvBep;
    UINT8    				res1U8[3];      		/**< (padding) */
} CiDevEgprsBepCvMeanInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevNetworkMonitorNcellInfo_struct
{
    UINT8     bsic;                /* Base transceiver station identity code */
    UINT8     rxSigLevel;     /* Receive signal level - BCCH */

    UINT16    arfcn;             /* Absolute radio frequency channel number */
    INT16      C1;                 /* Path loss criterion parameter #1 */
    INT16      C2;                 /* Path loss criterion parameter #2 */
} CiDevNetworkMonitorNcellInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevNetworkMonitorIdleInfo_struct
{
    UINT16    arfcn;             /* Absolute radio frequency channel number */
    INT16      C1;                 /* Path loss criterion parameter #1 */
    INT16      C2;                 /* Path loss criterion parameter #2 */

    UINT8     bsic;               /* Base transceiver station identity code */
    UINT8     rxSigLevel;     /* Receive signal level - BCCH */

    CiDevPacketIdleType  isInPacketIdle;
    UINT8     txPower;       /* Transmit power - TBD: phase 2 */
    UINT8     res1U8[2];      /* (padding) */
}CiDevNetworkMonitorIdleInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevNetworkMonitorDedicatedInfo_struct
{
    UINT16   arfcn;              /* Absolute radio frequency channel number */
    INT16     C1;                   /* Path loss criterion parameter #1 */

    UINT8     bsic;                     /* Base transceiver station identity code */
    UINT8     rxSigLevelFull;    /* Receive signal level accessed over all TDMA frames */
    UINT8     rxSigLevelSub;    /* Receive signal level accessed over subset of TDMA frames*/
    UINT8     rxQualityFull;       /* Receive quality accessed over all TDMA frames */
    UINT8     rxQualitySub;       /* Receive quality accessed over subset of TDMA frames */
    UINT8     timingAdv;           /* Initial timing advance or timing advance in SACCH block */

    CiBoolean    isChannelHopping;       /* Channeling is hopping*/
    CiDevChannelType  channelType;    /* Channel type*/
    UINT16   arfcnTch;                          /* ARFCN for traffic channel*/

    UINT8     timeSlot;       /* Server time slot */
    UINT8     txPower;       /* Transmit Power - TBD: phase 2 */
}CiDevNetworkMonitorDedicatedInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevNetworkMonitorGprsInfo_struct
{
    UINT16   arfcn;              						/* Absolute radio frequency channel number */
    INT16     C1;                   						/* Path loss criterion parameter #1 */
    INT16     C2;                   						/* Path loss criterion parameter #2 */

    UINT8     bsic;                    					/* Base transceiver station identity code */
    UINT8     rxSigLevelFull;    					/* Receive signal level accessed over all TDMA frames */
    UINT8     rxSigLevelSub;    					/* Receive signal level accessed over subset of TDMA frames*/
    UINT8     rxQualityFull;       					/* Receive quality accessed over all TDMA frames */
    UINT8     rxQualitySub;       					/* Receive quality accessed over subset of TDMA frames */
    UINT8     cValue;                 					/* C Value */
    UINT8     txPower;                					/* Transmit power - TBD: phase 2 */
    UINT8     ulTimeSlot;            					/* Uplink time slot - TBD: phase 2 */
    UINT8     dlTimeSlot;            					/* Downlink time slot - TBD: phase 2 */

    CiDevGprsServiceType     gprsServiceType; 	/* GPRS service type - TBD: phase 2 */
    CiDevCodeScheme                  ulCs;            		/* Uplink code scheme - TBD: phase 2 */
    CiDevCodeScheme                  dlCs;            		/* Downlink code scheme - TBD: phase 2 */
    CiDevModulationScheme          ulMod;          	/* Uplink modulation - TBD: phase 2 */
    CiDevModulationScheme          dlMod;          	/* Downlink modulation - TBD: phase 2 */
    CiDevEgprsBepCvMeanInfo       egprsBep;    	/* TBD: phase 2 */
}CiDevNetworkMonitorGprsInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevNetworkMonitorData_struct
{
    CiDevNetworkMonitorMode    mode;         /* Current mode (idle/dedicated/GPRS) */
    UINT8     res1U8[3];  /* (padding) */

    /* Serving Cell information */
    union
    {
      CiDevNetworkMonitorIdleInfo           IdleData;
      CiDevNetworkMonitorDedicatedInfo  DedicatedData;
      CiDevNetworkMonitorGprsInfo          GprsData;
    }svcCellInfo;

    /* Neighboring Cell information */
    UINT8     numNCells;     /* 0..CI_DEV_MAX_GSM_NEIGHBORING_CELLS */
    UINT8     res2U8[3];      /* (padding) */
    CiDevNetworkMonitorNcellInfo    nbCellInfo[ CI_DEV_MAX_GSM_NEIGHBORING_CELLS ];
}CiDevNetworkMonitorData;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimNetworkMonitorInfoInd_struct
{
    CiDevNetworkMonitorData    info;
}CiDevPrimNetworkMonitorInfoInd;

//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_CHANNEL_TYPE_TAG
{
	CI_DEV_EM_TCH_F             =   1,
	CI_DEV_EM_TCH_H            =   2,
	CI_DEV_EM_SDCCH_4        =   4,
	CI_DEV_EM_SDCCH_8        =   8
} _CiDevEngChannelType;

typedef UINT8 CiDevEngChannelType;

//ICAT EXPORTED ENUM
typedef enum CIDEV_SERVICE_TYPE_TAG
{
    CI_DEV_CIRCUIT_SWITCHED_SERVICE = 0,
    CI_DEV_GPRS_SERVICE             = 1,
    CI_DEV_COMBINED_SERVICE         = 2,
    CI_DEV_NO_SERVICES_AVAILABLE    = 3,
    
    CI_DEV_NUM_OF_SERVICE_TYPES
}_CiDevServiceType;

typedef UINT8 CiDevServiceType;

/** \brief Engineering mode: 2G (GSM) serving cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevGsmServingCellInfo_struct
{
    UINT8     rxSigLevel;     		/**< Receive signal level [range: 0h-3Fh] */
    UINT8     rxSigLevelFull; 	/**< Receive signal level accessed over all TDMA frames  [range: 0h-3Fh]*/
    UINT8     rxSigLevelSub;  	/**< Receive signal level accessed over subset of TDMA frames  [range: 0h-3Fh]*/
    UINT8     rxQualityFull;  		/**< Receive quality accessed over all TDMA frames [range: 0-7] */
    UINT8     rxQualitySub;   	/**< Receive quality accessed over subset of TDMA frames [range: 0-7] */
    UINT8     rac;           			/**< Routing area code [range: 0-1 (1 bit)] */
    UINT8     bsic;           		/**< Base transceiver station identity code [range: 0h-3Fh (6 bits)] */
    UINT8     nom;            		/**< Network operation mode [range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2] */
    UINT8     nco;            		/**< Network control order  [range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3] */
    UINT8     bs_pa_mfrms;    	/**< Number of multiframes between paging messages sent [range: 0-7] */

    UINT16    mcc;            		/**< Mobile country code [range:  0-999 (3 digits)] */
    UINT16    mnc;            		/**< Mobile network code [range: 0-99 (2 digits)] */
    UINT16    lac;            		/**< Location area code [range: 0h-FFFFh (2 octets)] */
    UINT16    ci;             		/**< Cell identity [range: 0h-FFFFh (2 octets)] */
    UINT16    arfcn;          		/**< Absolute radio frequency channel number [range:  0-1023] */

    INT16     C1;             		/**< Path loss criterion parameter #1 */

    INT16     C2;             		/**< Path loss criterion parameter #2 */

    INT16     C31;            		/**< GPRS signal level threshold criterion parameter*/

    INT16     C32;           		 /**< GPRS cell ranking criterion parameter */


    UINT16    t3212;          		/**< Periodic LA update timer (T3212) in minutes */
    UINT16    t3312;          		/**< Periodic RA update timer (T3312) in minutes */

    CiBoolean pbcchSupport;   						/**< Support of PBCCH \sa CCI API Ref Manual */
    UINT8					TxPowerLevel;			/**< Tx power level [range: 0h-3Fh] */
    UINT8					timingAdv;				/**< Timing advance [range 0-63] */
    CiBoolean				hoppingChannel;			/**< Hopping channel */
    CiBoolean				EGPRSSupport;			/**< EGPRS support capability */
    CiDevEngChannelType   	ChType;                 		/**< Values are TCH_F = 1, TCH_H = 2, SDCCH_4 = 4, SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */
    CiBoolean				nccPermitted;			/**< The NCC permitted parameter sets the NCCs (network color codes) that the mobile station is permitted to report. \sa CCI API Ref Manual */
    UINT8   				RadioLinkTimeout;		/**< Radio link timeout [range: value >=0] */
    UINT16       			hoCount;				/**< Handovers counter [range: value>=0] */
    UINT16       			hoSuccessCount;			/**< Success handovers counter [range: value>=0] */
    UINT16       			chanAssCount;			/**< Channel assignment counter [range: value>=0]*/
    UINT16       			chanAssSuccessCount;  	/**< Success channel assignment counter [range: value>=0]*/

    UINT16    arfcnTch;    							/**< ARFCN for traffic channel, only valid for dedicated state [range:  0-1023]*/
    UINT8      timeSlot;    							/**< Time slot, only valid for dedicated state*/
    CiDevPacketIdleType  isInPacketIdle;    			/**< Only valid for idle state \sa CiDevPacketIdleType */
    /*Michal Bukai - I-Mate Addition. Start:*/
    CiBoolean               IsForbiddenLA;          /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */
    CiDevCellPrioriytType   CellPriority;           /**< Cell priority for cell selection or reselection. Cell priority can be normal, low or barred. \sa CiDevCellPrioriytType */
    UINT8                   HSN;                    /**< Hopping sequence number. Value 0 means cyclic hopping is done*/
    CiDevHoppingGroup       HoppingGroup;           /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */
    /*Michal Bukai - I-Mate Addition. End*/
/*Added by Lilei for Network Info CQ56702, begin*/
    UINT8                   gsmBand;                /**< 0:PGSM_900; 1:DCS_GSM_1800; 2:PCS_GSM_1900; 3:EGSM_900; 4:GSM_450; 5:GSM_480; 6:GSM_850 */
    UINT8                   channelMode;            /**< Mode of a dedicated channel, used during dedicated channel setup to specify channel mode (signaling-only, speech or data), mode version and data rate. */
/*Added by Lilei for Network Info CQ56702, end*/
/*Lilei, CQ00092855, 20150427, begin*/
    UINT8                   lenOfMnc;             /**< Length of MNC, value range (2,3) */
/*Lilei, CQ00092855, 20150427, end*/
	/*added by taow 20181107 CQ00112754 begin*/
	CiDevAmrCodecType 	    codecType;/*wCdma*/
	UINT32					speechCodecRate;/*wCdma*/
	INT16                   RLA;    //rxlevAccessMin;
	INT8					DRX;//drxTimerMax
	INT8                    maio;
	/*added by taow 20181107 CQ00112754 end*/
/*Lilei, CQ00115868, 20190815, begin*/
    UINT32                  succeededGsmIratReselectionCount;   //gsm irat 4g to 2g count
    UINT32                  succeededGsmHandoverCount;          //gsm cs irat handover count
/*Lilei, CQ00115868, 20190815, end*/
} CiDevGsmServingCellInfo;



/** \brief Reject cause (10.5.3.6) sent in CM Service Reject, Abort, MM-Status and Location Updating Reject messages to MM from the network */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_MM_REJECTCAUSE_CODE_TYPE {
	CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_HLR = 2,						/**< MS identification cause */
	CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_MS=3,								/**< MS identification cause */
	CI_DEV_EM_MM_REJ_CAUSE_IMSI_UNKNOWN_IN_VLR =4,	 					/**< MS identification cause */
	CI_DEV_EM_MM_REJ_CAUSE_IMEI_NOT_ACCEPTED =5,						/**< MS identification cause */
	CI_DEV_EM_MM_REJ_CAUSE_ILLEGAL_ME =6,								/**< MS identification cause */
	CI_DEV_EM_MM_REJ_CAUSE_PLMN_NOT_ALLOWED =11,						/**< Subscription options */
	CI_DEV_EM_MM_REJ_CAUSE_LOCATION_AREA_NOT_ALLOWED =12,				/**< Subscription options */
	CI_DEV_EM_MM_REJ_CAUSE_ROAMING_NOT_ALLOWED_IN_THIS_LOCATION_AREA =13,		/**< Subscription options */
	CI_DEV_EM_MM_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LOCATION_AREA =15,				/**< Subscription options */
	CI_DEV_EM_MM_REJ_CAUSE_NETWORK_FAILURE=17,									/**< PLMN specific network failures and congestion/authentication failures */
	CI_DEV_EM_MM_REJ_CAUSE_MAC_FAILURE=20,												/**< PLMN specific network failures and congestion/authentication failures*/
	CI_DEV_EM_MM_REJ_CAUSE_SYNC_FAILURE=21, 												/**< PLMN specific network failures and congestion/authentication failures*/
	CI_DEV_EM_MM_REJ_CAUSE_CONGESTION=22, 												/**< PLMN specific network failures and congestion/authentication failures*/
	CI_DEV_EM_MM_REJ_CAUSE_GSM_AUTHENTICATION_UNACCEPTABLE=23, 						/**< PLMN specific network failures and congestion/authentication failures */
	CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_NOT_SUPPORTED=32, 							/**< Nature of request */
	CI_DEV_EM_MM_REJ_CAUSE_REQUEST_SERVICE_OPTION_NOT_SUBSCRIBED=33,					/**< Nature of request */
	CI_DEV_EM_MM_REJ_CAUSE_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER=34,				/**< Nature of request */
	CI_DEV_EM_MM_REJ_CAUSE_CALL_CANNOT_BE_IDENTIFIED=38,  								/**< Nature of request */
	CI_DEV_EM_MM_REJ_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE=95, 							/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_INVALID_MANDATORY_INFORMATION=96, 							/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED=97, 			/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE=98, 			/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED=99, 	/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_CONDITIONAL_IE_ERROR=100,										/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_PROTOCOL_ERROR_UNSPECIFIED=111, 							/**< Invalid message */
	CI_DEV_EM_MM_REJ_CAUSE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF									/**< Used for alignment */

} _CiDevEngMMRejectCauseCodeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Reject cause (10.5.3.6) sent in CM Service Reject, Abort, MM-Status and Location Updating Reject messages to MM from the network
 * \sa CIDEV_ENGMODE_MM_REJECTCAUSE_CODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngMMRejectCauseCodeType;
/**@}*/

/** \brief Band mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_BAND_MODE_TYPE {
	CI_DEV_EM_BAND_MODE_PGSM_MODE=0,						/**< Standard or primary GSM 900 (PGSM) band supported */
	CI_DEV_EM_BAND_MODE_EGSM_MODE,							/**< Extended GSM 900 band supported */
	CI_DEV_EM_BAND_MODE_DCS_MODE,							/**< DCS 1800 band supported */
	CI_DEV_EM_BAND_MODE_PCS_MODE,							/**< PCS 1900 band supported */
	CI_DEV_EM_BAND_MODE_GSM850_MODE,						/**< GSM 850 band supported */
	CI_DEV_EM_BAND_MODE_PGSM_DCS_MODE,						/**< PGSM band and DCS 1800 band supported  */
	CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE,						/**< Extended GSM 900 band and DCS 1800 band supported */
	CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE,						/**< PGSM band and PCS 1900 band supported */
	CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE,						/**< Extended GSM 900 band and PCS 1900 band supported */
	CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE,					/**< GSM 850 band and DCS 1800 band supported */
	CI_DEV_EM_BAND_MODE_GSM850_PCS_MODE,					/**< GSM 850 band and PCS 1900 band supported */
	CI_DEV_EM_BAND_MODE_EGSM_MODE_LOCK,						/**< Lock the MS to Extended GSM 900 band mode. Autoband DISABLED. For use in testing only. */
	CI_DEV_EM_BAND_MODE_DCS_MODE_LOCK,						/**< Lock the MS to DCS 1800 band mode. Autoband DISABLED. For use in testing only. */
	CI_DEV_EM_BAND_MODE_PCS_MODE_LOCK,						/**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900/1900 countries only. */
	CI_DEV_EM_BAND_MODE_GSM850_MODE_LOCK,					/**< Lock the MS to GSM 850 band mode. Autoband DISABLED. For use in testing only. */
	CI_DEV_EM_BAND_MODE_PGSM_PCS_MODE_LOCK,					/**< Lock the MS to PGSM band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900/1900 countries only. */
	CI_DEV_EM_BAND_MODE_EGSM_PCS_MODE_LOCK,					/**< Lock the MS to Extended GSM 900 band or PCS 1900 band mode. Autoband DISABLED. For use in testing and 900/1900 countries only. */
	CI_DEV_EM_BAND_MODE_EGSM_DCS_MODE_LOCK,					/**< Lock the MS to Extended GSM 900 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 900/1800 countries only. */
	CI_DEV_EM_BAND_MODE_GSM850_DCS_MODE_LOCK,				/**< Lock the MS to GSM 850 band or DCS 1800 band mode. Autoband DISABLED. For use in testing and 850/1800 countries only. */
	CI_DEV_EM_BAND_MODE_INVALID_BAND_MODE,					/**< Invalid band */
	CI_DEV_EM_BAND_MODE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngBandModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Band mode
 * \sa CIDEV_ENGMODE_BAND_MODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngBandmodeType;
/**@}*/


/** \brief Mobility management information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevGsmGMMInfo_struct
{
	UINT16							MccLastRegisteredNetwork;	/**< Mcc of last registered network */
	UINT16							MncLastRegisteredNetwork;	/**< Mnc of last registered network */
 	UINT32							TMSI;						/**< TMSI */
	UINT32							PTMSI;						/**< PTMSI */
    CiBoolean                       IsSingleMmRejectCause;		/**< TRUE - only one MM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual */
 	CiDevEngMMRejectCauseCodeType	MMRejectCause;				/**< The one that was reported during the last engineering information period. Reject cause (10.5.3.6) sent in CM Service Reject, Abort, MM-Status, and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */
 	CiDevEngBandmodeType			currentBandMode;			/**< Band mode \sa CiDevEngBandModeType */
	UINT8							mmState;					/**< MM state refer to 3GPP 24.008 section 4.1.2   */  /* see enum MmState in Mm_comm.h. */
 	UINT8							gmmState;					/**< GMM state refer to 3GPP 24.008 section 4.1.3  */  /* see enum GmmState in Gmm_comm.h */
 	UINT8							gprsReadyState;				/**< 0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /*For details, see enum GprsReadyState in grrmrtyp.h. */
 	UINT16							readyTimerValueInSecs;		/**< MM ready timer value in seconds [value >0]. Value of 0xffff indicates the timer is not running */
/*Added by Lilei for Network Info CQ56702, begin*/
    UINT8                           serviceStatus;              /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */
    UINT8                           LAU_status;                 /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */
    UINT16                          LAU_count;                  /**<LAU attempt counter as held by UE; number of consecutive LAU failures in current LAU procedure attempt */
/*Added by Lilei for Network Info CQ56702, end*/
/*Lilei, CQ00082362, 20150116, begin*/
    UINT8                           RAU_status;                 /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */
    UINT16                          RAU_count;                  /**<RAU attempt counter as held by UE; number of consecutive RAU failures in current RAU procedure attempt*/
/*Lilei, CQ00082362, 20150116, end*/
} CiDevGsmGMMInfo;

/** \brief Channel modes */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_AMR_CHANNEL_MODE_TYPE {
	CI_DEV_EM_AMR_CH_MODE_AMR_FR = 0,					/**< CHM_SPEECH_FULL_RATE_VER3 channel mode */
	CI_DEV_EM_AMR_CH_MODE_AMR_HR,						/**< CHM_SPEECH_HALF_RATE_VER3 channel mode */
	CI_DEV_EM_AMR_CH_MODE_EFR,							/**< CHM_SPEECH_FULL_RATE_VER2 / CHM_SPEECH_HALF_RATE_VER2 channel modes */
	CI_DEV_EM_AMR_CH_MODE_FR,							/**< CHM_SPEECH_FULL_RATE channel mode */
	CI_DEV_EM_AMR_CH_MODE_HR,							/**< CHM_SPEECH_HALF_RATE channel mode */
	CI_DEV_EM_AMR_CH_MODE_ALIGN_32_BIT=0XFFFFFFF		/**< For alignment */
} _CiDevEngAMRChannelModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Channel modes
 * \sa CIDEV_ENGMODE_AMR_CHANNEL_MODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngAMRChannelModeType;
/**@}*/

/** \brief AMR codec rate  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_AMR_CODE_TYPE{
	CI_DEV_EM_AMR_CODE_TYPE_4_75_KBPS = 1,				/**< AMR codec rate enumeration for 4.75 Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_5_15_KBPS,					/**< AMR codec rate enumeration for 5.15 Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_5_9_KBPS,					/**< AMR codec rate enumeration for 5.9  Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_6_7_KBPS,					/**< AMR codec rate enumeration for 6.7  Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_7_4_KBPS,					/**< AMR codec rate enumeration for 7.4  Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_7_95_KPBS,					/**< AMR codec rate enumeration for 7.95 Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_10_2_KPBS,					/**< AMR codec rate enumeration for 10.2 Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_12_2_KBPS,					/**< AMR codec rate enumeration for 12.2 Kbit/s codec rate  */
	CI_DEV_EM_AMR_CODE_TYPE_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngAMRCodeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief AMR codec rate
 * \sa CIDEV_ENGMODE_AMR_CODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngAMRCodeType;
/**@}*/

/** \brief Active code set (ACS)  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngAMRActiveCodeSetType_struct
{
      UINT8	AcsSize;				/**< Number of codes in AMR AS - up to 4 */
      UINT8      res1U8[3];   			/**< (padding) */

      CiDevEngAMRCodeType	 Acs[4];	/**< AMR code type \sa CiDevEngAMRCodeType */
} CiDevEngAMRActiveCodeSetType;

/** \brief AMR information  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevAMRInfo_struct
{
	CiDevEngAMRChannelModeType		ULChannelMode;		/**< Current uplink channel mode {AMR FR, AMR HR, EFR, FR, HR} \sa CiDevEngAMRChannelModeType */
	CiDevEngAMRChannelModeType		DLChannelMode;		/**< Current downlink channel mode {AMR FR, AMR HR, EFR, FR, HR} \sa CiDevEngAMRChannelModeType */
	CiDevEngAMRActiveCodeSetType	ActiveCodeSet;		/**< Active code set (ACS) \sa CiDevEngAMRActiveCodeSetType_struct */
	CiBoolean						DTXUl;				/**< DTX UL on/off \sa CCI API Ref Manual  */
	CiBoolean						DTXDl;				/**< If at least one DTX during DL has happened, then DTXDI =TRUE, otherwise = FALSE. \sa CCI API Ref Manual */
	INT16							DlCi;				/**< L1 calculates average of confidence measure for frequency offset for all the bursts of the multiframe. [Ratio linear value 0-500]. */
	UINT8							RxQualSub;			/**< Used when DTX is on, range is 0-7 */
       UINT8             					res1U8[3]; 	/**< (padding) */
} CiDevAMRInfo;

/** \brief GPRS attach type  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_GPRS_ATTACH_TYPE{
	CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ONLY_ATTACH=0,					/**< GPRS only */
	CI_DEV_EM_GPRS_ATTACH_TYPE_GPRS_ATTACH_WHILE_IMSI_ATTACHED,	/**< GPRS attach while IMSI attached */
	CI_DEV_EM_GPRS_ATTACH_TYPE_COMBINED_IMSI_ATTACH,					/**< Combined GPRS attach */
	CI_DEV_EM_GPRS_ATTACH_TYPE_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngGPRSAttachType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GPRS attach type
 * \sa CIDEV_ENGMODE_GPRS_ATTACH_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngGPRSAttachType;
/**@}*/

/** \brief MAc mode type - methods of allocating uplink radio resources  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_MACMODE_TYPE{
	CI_DEV_EM_MACMODE_TYPE_MAC_DYNAMIC_ALLOC =0,					/**< Dynamic allocation (DA) */
	CI_DEV_EM_MACMODE_TYPE_MAC_EXTENDED_DYNAMIC_ALLOC,			/**< Extended dynamic allocation (EDA) */
	CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_NOT_HALF_DUPLEX,	/**< Fixed not half duplex allocation */
	CI_DEV_EM_MACMODE_TYPE_MAC_FIXED_ALLOC_HALF_DUPLEX,		/**< Fixed half duplex allocation */
	CI_DEV_EM_MACMODE_TYPE_MAC_UNKNOWN_ALLOC_MODE,			/**< Unknown allocation */
	CI_DEV_EM_MACMODE_TYPE_CI_DEV_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngMacModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief MAc mode type - methods of allocating uplink radio resources
 * \sa CIDEV_ENGMODE_MACMODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngMacModeType;
/**@}*/

/* Not in use. Network Control Order */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_NETWORK_CTRL_TYPE{
	CI_DEV_EM_NW_CTRL_NC_0 =0,
	CI_DEV_EM_NW_CTRL_NC_1,
	CI_DEV_EM_NW_CTRL_NC_2,
	CI_DEV_EM_NW_CTRL_NC_RESERVED,
	CI_DEV_EM_NW_CTRL_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngNetworkControlType;

typedef UINT32 CiDevEngNetworkControlType;

/** \brief Network mode  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_NW_MODE_TYPE{
	CI_DEV_EM_NW_MODE_TYPE_NOM1 =0,	       /**< NW provides simultaneous CS and PS */
	CI_DEV_EM_NW_MODE_TYPE_NOM2,		       /**< UE remains attached to PS while receiving CS */
	CI_DEV_EM_NW_MODE_TYPE_NOM3,		       /**< UE can be connected to CS or PS */
	CI_DEV_EM_NW_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngNetworkModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network mode
 * \sa CIDEV_ENGMODE_NW_MODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngNetworkModeType;
/**@}*/

/** \brief Coding schemes  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_CODINGSCHEME_TYPE{
	CI_DEV_EM_CS_1 =0,						/**< CS1 */
	CI_DEV_EM_CS_2,						/**< CS2 */
	CI_DEV_EM_CS_3,						/**< CS3 */
	CI_DEV_EM_CS_4,						/**< CS4 */
	CI_DEV_EM_MCS_1,						/**< MCS1 */
	CI_DEV_EM_MCS_2,						/**< MCS2 */
	CI_DEV_EM_MCS_3,						/**< MCS3 */
	CI_DEV_EM_MCS_4,						/**< MCS4 */
	CI_DEV_EM_MCS_5,						/**< MCS5 */
	CI_DEV_EM_MCS_6,						/**< MCS6 */
	CI_DEV_EM_MCS_7,						/**< MCS7 */
	CI_DEV_EM_MCS_8,						/**< MCS8 */
	CI_DEV_EM_MCS_9,						/**< MCS9 */
	CI_DEV_EM_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngCodingSchemeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Coding schemes
 * \sa CIDEV_ENGMODE_CODINGSCHEME_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngCodingSchemeType;
/**@}*/

/** \brief Link quality measurement mode values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_EGPR_SLQ_MEAS_MODE_TYPE{
	CI_DEV_EM_NO_LINK_QUAL_MEASUREMENTS =0,			/**< No report */
	CI_DEV_EM_LINK_QUAL_INT_MEAS_ONLY,				/**< Report interference measurements */
	CI_DEV_EM_LINK_QUAL_BEP_MEAS_ONLY,				/**< Report mean BEP measurements */
	CI_DEV_EM_LINK_QUAL_INT_AND_BEP_MEAS,			/**< Report both interference and BEP measurements */
	CI_DEV_EM_EGPR_SLQ_MEAS_MODE_TYPE_ALIGN_32_BIT=0XFFFFFFF
}_CiDevEngEGPRSLQMeasModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Link quality measurement mode
 * \sa CIDEV_ENGMODE_EGPR_SLQ_MEAS_MODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngEGPRSLQMeasModeType;
/**@}*/

/** \brief GMM reject cause values; refer to 3GPP TS 24.008  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_GMM_REJ_CAUSE_CODE_TYPE{
	CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_NOT_ALLOWED=7,				/**< GPRS services not allowed */
	CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICE_AND_NON_GPRS_SERVICE_NOT_ALLOWED=8,   /**< GPRS services and non-GPRS services not allowed */
	CI_DEV_EM_GMM_REJ_CAUSE_MS_IDENTITY_CANNOT_BE_DERIVED_BY_NW=9,  /**< MS identity cannot be derived by the network */
	CI_DEV_EM_GMM_REJ_CAUSE_IMPLICITLY_DETACHED=10,					/**< Implicitly detached */
	CI_DEV_EM_GMM_REJ_CAUSE_GPRS_SERVICES_NOT_ALLOWED_IN_PLMN=14,	/**< GPRS services not allowed in this PLMN */
	CI_DEV_EM_GMM_REJ_CAUSE_MSC_TEMPORARILY_NOT_REACHABLE=16,       /**< MSC temporarily not reachable */
	CI_DEV_EM_GMM_REJ_CAUSE_NO_PDP_CONTEXT_ACTIVATED=40,            /**< No PDP context activated */
	CI_DEV_EM_GMM_REJ_CAUSE_ALIGN_32_BIT=0XFFFFFFF
} _CiDevEngGMMRejectCauseCodeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GMM reject cause
 * \sa CIDEV_ENGMODE_GMM_REJ_CAUSE_CODE_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngGMMRejectCauseCodeType;
/**@}*/

/** \brief IP address  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct   CiDevEngIPAddressType_struct
{
       UINT8   len;          							/**< Length of the address field */
	UINT8   address[CI_DEV_PDP_IP_V6_SIZE];	/**< Address field */
} CiDevEngIPAddressType;

/** \brief Delay class  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_DELAY_CLASS_TYPE{
	CI_DEV_EM_GPRS_DELAY_CLASS_SUBSCRIBED =0,					/**<  Subscribed delay class  */
	CI_DEV_EM_GPRS_DELAY_CLASS_1,								/**<  Delay class 1 */
	CI_DEV_EM_GPRS_DELAY_CLASS_PACKET_CELL_CHANGE_ORDER2,	/**<  Delay class 2 */
	CI_DEV_EM_GPRS_DELAY_CLASS_3,								/**<  Delay class 3 */
	CI_DEV_EM_GPRS_DELAY_CLASS_4,								/**<  Delay class 4 (best effort) */
	CI_DEV_EM_GPRS_DELAY_CLASS_RESERVED = 7,					/**<  Reserved */
	CI_DEV_EM_DELAY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF			/**< Alignment */
} _CiDevEngDelayClassType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Delay class
 * \sa CIDEV_ENGMODE_DELAY_CLASS_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngDelayClassType;
/**@}*/

/** \brief Reliability class type  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_RELIABILITY_CLASS_TYPE{
	CI_DEV_EM_GPRS_RELIAB_CLASS_SUBSCRIBED =0,			    	/**< Subscribed reliability class */
	CI_DEV_EM_GPRS_RELIAB_CLASS_1,								/**< Unused. If received, it is interpreted as '010'. */
	CI_DEV_EM_GPRS_RELIAB_CLASS_2,								/**< Unacknowledged GTP; acknowledged LLC and RLC, protected data */
	CI_DEV_EM_GPRS_RELIAB_CLASS_3,								/**< Unacknowledged GTP and LLC; acknowledged RLC, protected data */
	CI_DEV_EM_GPRS_RELIAB_CLASS_4,								/**< Unacknowledged GTP, LLC, and RLC, protected data */
	CI_DEV_EM_GPRS_RELIAB_CLASS_5,								/**< Unacknowledged GTP, LLC, and RLC, unprotected data */
	CI_DEV_EM_RELIABILITY_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF	    /**< Alignment */
} _CiDevEngReliabilityClassType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Reliability class type
 * \sa CIDEV_ENGMODE_RELIABILITY_CLASS_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngReliabilityClassType;
/**@}*/

/** \brief Peak throughput class (1 to 9) - maximum rate in octets per second  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_PEAK_THR_TYPE{
	CI_DEV_EM_GPRS_PEAK_THRPT_SUBSCRIBED =0, 			/**< Subscribed peak throughput */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_1KOCT,				/**< Up to 1,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_2KOCT,				/**< Up to 2,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_4KOCT,				/**< Up to 4,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_8KOCT ,			/**< Up to 8,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_16KOCT,			/**< Up to 16,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_32KOCT,			/**< Up to 32,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_64KOCT,			/**< Up to 64,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_128KOCT,			/**< Up to 128,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_UPTO_256KOCT,			/**< Up to 256,000 octet/s */
	CI_DEV_EM_GPRS_PEAK_THRPT_RESERVED = 0x0f,		/**< Reserved */
	CI_DEV_EM_PEAK_THR_TYPE_ALIGN_32_BIT=0XFFFFFFF		/**< Alignment */
} _CiDevEngPeakThroughputType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Peak throughput class (1 to 9) - maximum rate in octets per second
 * \sa CIDEV_ENGMODE_PEAK_THR_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngPeakThroughputType;
/**@}*/

/** \brief Engineering mode precedence class type  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_PRECEDENCE_CLASS_TYPE{
	CI_DEV_EM_GPRS_PRECED_CLASS_SUBSCRIBED =0, 	/**< Subscribed precedence (in MS to network direction) */
	CI_DEV_EM_GPRS_PRECED_CLASS_1,					/**< High priority (in MS to network direction) */
	CI_DEV_EM_GPRS_PRECED_CLASS_2,					/**< Normal priority (in MS to network direction) */
	CI_DEV_EM_GPRS_PRECED_CLASS_3,					/**< Low priority (in MS to network direction) */
	CI_DEV_EM_GPRS_PRECED_CLASS_RESERVED = 7,		/**< Reserved */
	CI_DEV_EM_PRECEDENCE_CLASS_TYPE_ALIGN_32_BIT=0XFFFFFFF
}  _CiDevEngprecedenceClassType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode precedence class type
 * \sa CIDEV_ENGMODE_PRECEDENCE_CLASS_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevEngprecedenceClassType;
/**@}*/

/** \brief Mean throughput - average rate in octets per hour  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_ENGMODE_MEANTHROUGHPUT_TYPE{
	CI_DEV_EM_GPRS_MEAN_THRPT_SUBSCRIBED =0, 		/**< Subscribed precedence (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_100_OPH,				/**< 100 octet/h (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_200_OPH,				/**< 200 octet/h (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_500_OPH,				/**< 500 octet/h (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_1K_OPH,				/**< 1,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_2K_OPH,				/**< 2,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_5K_OPH,				/**< 5,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_10K_OPH,				/**< 10,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_20K_OPH,				/**< 20,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_50K_OPH,				/**< 50,000 octet/h (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_100K_OPH,			/**< 100,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_200K_OPH,			/**< 200,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_500K_OPH,			/**< 500,000 octet/h (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_1M_OPH,				/**< 1,000,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_2M_OPH,				/**< 2,000,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_5M_OPH,				/**< 5,000,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_10M_OPH,			/**< 10,000,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_20M_OPH,			/**< 20,000,000 octet/h  (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_50M_OPH,			/**< 50,000,000 octet/h  (in MS to network direction and in network to MS direction) */
       CI_DEV_EM_GPRS_MEAN_THRPT_RESERVED       = 30, 	/**<  Reserved (in MS to network direction and in network to MS direction) */
	CI_DEV_EM_GPRS_MEAN_THRPT_BEST_EFFORT = 31,	/**<  Best effort. The value indicates that throughput is made available to the MS on a per need and availability basis (in MS to network direction and in network to MS direction). */
	CI_DEV_EM_MEANTHROUGHPUT_TYPE_ALIGN_32_BIT=0XFFFFFFF
}  _CiDevMeanThroughputType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Mean throughput - average rate in octets per hour
 * \sa CIDEV_ENGMODE_MEANTHROUGHPUT_TYPE */
/** \remarks Common Data Section */
typedef UINT32 CiDevMeanThroughputType;
/**@}*/

/** \brief Quality of service information structure  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct	CiDevEngQualityOfServiceType_struct
{
	CiDevEngDelayClassType	       delayClass;			/**< GPRS delay class \sa CiDevEngDelayClassType */
	CiDevEngReliabilityClassType	reliabilityClass;		/**< Reliability class \sa CiDevEngReliabilityClassType */
	CiDevEngPeakThroughputType	peakThroughput;		/**<  Peak throughput \sa CiDevEngPeakThroughputType */
	CiDevEngprecedenceClassType	precedenceClass;	/**< Precedence class \sa CiDevEngprecedenceClassType */
	CiDevMeanThroughputType	       meanThroughput;	/**< Mean throughput \sa CiDevMeanThroughputType */
} CiDevEngQualityOfServiceType;

/** \brief APN type info  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct	CiDevEngAPNType_struct
{
	INT8		length;
       UINT8  	res1U8[3];      						/**< (padding) */
	UINT8	name [CI_DEV_MAX_APN_NAME];        	/**< IP address or an ASCII character string that identifies the GGSN */
} CiDevEngAPNType;

/** \brief PDP context information  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngActivePDPContextinfoType_struct
{
	CiDevEngIPAddressType			IPaddress;	/**< IP address \sa CiDevEngIPAddressType_struct */
       CiDevEngQualityOfServiceType		QOS;		/**< Quality of service information  \sa CiDevEngQualityOfServiceType_struct */
       CiDevEngAPNType				      	APN;		/**< \sa CiDevEngAPNType_struct */
} CiDevEngActivePDPContextinfoType;

/** <paramref name="CI_DEV_PRIM_ACTIVE_PDP_CONTEXT_ENGMODE_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimActivePDPContextEngModeInd_struct {
        UINT8 							Index;					/**< PDP context index */
        CiDevEngActivePDPContextinfoType   ActivePDPContextinfo;  	/**< PDP context information \sa CiDevEngActivePDPContextinfoType_struct */
} CiDevPrimActivePDPContextEngModeInd;

/** \brief Packet data information  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevGPRSPTMInfo_struct
{
	CiBoolean						GPRSAttached;				/**< TRUE - MS is GPRS attached; FALSE - other  \sa CCI API Ref Manual */
	INT8								EGPRSBEPPeriod;			/**< BEP measurement averaging coefficient  */
	CiBoolean						IsSingleGmmRejectCause;	/**< TRUE - only one GMM reject cause reported during the last engineering information period; FALSE - other  \sa CCI API Ref Manual */
	UINT8  						       NumActivePDPContext;		/**< 0 means no active PDP context [range: 0-7] */

	CiDevEngGPRSAttachType			GPRSAttachType;			/**< GPRS attach type \sa CiDevEngGPRSAttachType */
	CiDevEngMacModeType		       MacMode;					/**< Mac mode type \sa CiDevEngMacModeType */
	CiDevEngNetworkControlType		NetworkControl;				/**< Not in use (network control order) \sa CiDevEngNetworkControlType */
       CiDevEngNetworkModeType			NetworkMode;				/**< Network mode type \sa CiDevEngNetworkModeType */
       CiDevEngCodingSchemeType		CodingSchemeUL;			/**< UL coding scheme \sa CiDevEngCodingSchemeType */
       CiDevEngCodingSchemeType		CodingSchemeDL;			/**< DL coding scheme \sa CiDevEngCodingSchemeType*/
	CiDevEngEGPRSLQMeasModeType	EGPRSLQMeasurementMode;	/**< Link quality measurement mode  \sa CiDevEngEGPRSLQMeasModeType */
	CiDevEngGMMRejectCauseCodeType	GMMRejectCause;			/**< Reported during the last engineering information period  \sa CiDevEngGMMRejectCauseCodeType */

    	UINT8     							cValue;            			/**< C value */
    	UINT8     							txPower;           			/**< Transmit power of every block - TBD: phase 2 */
    	UINT8     							ulTimeSlot;         	   	/**< Uplink time slot allocation bitmap */
    	UINT8     							dlTimeSlot;        			/**< Downlink time slot allocation bitmap */

    	CiDevGprsServiceType     			gprsServiceType; 			/**< GPRS service type GPRS/EDGE \sa CiDevGprsServiceType */
    	CiDevModulationScheme          		ulMod;          			/**< Uplink modulation - TBD: phase 2 \sa CiDevModulationScheme */
    	CiDevModulationScheme          		dlMod;          			/**< Downlink modulation - TBD: phase 2 \sa CiDevModulationScheme */
    /*Michal Bukai - I-Mate Addition. Start:*/
    UINT8               USFGranularity;          /**< USF granularity defines the number of RLC/MAC blocks to transmit if USF is present. 0 - the mobile station shall transmit one RLC/MAC block, 1 - the mobile station shall transmit four consecutive RLC/MAC blocks */
    UINT32              ULThroughput;           /**< UL throughput in octets per second */
    UINT32              DLThroughput;           /**< DL throughput in octets per second */
    /*Michal Bukai - I-Mate Addition. End*/
   	CiDevEgprsBepCvMeanInfo      		egprsBep;   					/**< BEP period - TBD: phase 2 \sa CiDevEgprsBepCvMeanInfo_struct */
} CiDevGPRSPTMInfo;
/*Added by Lilei for neighbor cell info report on 01082014, begin*/
#define CI_DEV_MAX_NEIGHBORING_CELLS 32

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoGsm_struct{
    UINT32                          ci; /**< Cell identity */
    UINT16                          lac; /**< Location area code */
    UINT16                          arfcn; /**< Absolute radio frequency channel number */   
    UINT8                           bsic; /**< Base transceiver station identity code */
    UINT8                           rxSigLevel; /**< Receive signal level */
}CiDevEngModeNcellInfoGsm;

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoListGsm_struct{
    UINT8                           numNcellGsm; /**< Number of GSM neighbor cells */
    CiDevEngModeNcellInfoGsm        nCellInfoGsm[CI_DEV_MAX_NEIGHBORING_CELLS]; /**< GSM neighbor cells info, maximum 32 cells */
}CiDevEngModeNcellInfoListGsm;

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoUmts_struct{
    UINT32                          ci; /**< Cell Identity */
    UINT16                          lac; /**< Location area code */
    UINT16                          arfcn; /**< Absolute radio frequency channel number */    
    UINT16                          psc_cellParameterId; /**< Primary scrambling code for FDD or Cell parameter id for TDD */
    INT16                           rscp; /**< CPICH/PCCPCH received signal code power */
}CiDevEngModeNcellInfoUmts;

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoListUmts_struct{
    UINT8                           numNcellUmts; /**< Number of UMTS neighbor cells */
    CiDevEngModeNcellInfoUmts       nCellInfoUmts[CI_DEV_MAX_NEIGHBORING_CELLS*2]; /**< UMTS neighbor cells info, maximum 32(intraFreq)+32(interFreq) cells */
}CiDevEngModeNcellInfoListUmts;

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoLte_struct{
	UINT16					        physCellId; /**< Physical cell identity */
    UINT32					        earfcn; /**< Eutra absolute radio frequency channel number */
	UINT8 					        rsrp; /**< Reference signal receive power */
	UINT8 					        rsrq; /**< Reference signal receive quality */
	/*added by taow 20181107 CQ00112754 begin*/
	INT16							s_rxlev;
	/*added by taow 20181107 CQ00112754 end*/
}CiDevEngModeNcellInfoLte;

//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeNcellInfoListLte_struct{
    UINT8                           numNcellLte; /**< Number of LTE neighbor cells */
    CiDevEngModeNcellInfoLte        nCellInfoLte[CI_DEV_MAX_NEIGHBORING_CELLS*2]; /**< LTE neighbor cells info, maximum 32(intraFreq)+32(interFreq) cells */
}CiDevEngModeNcellInfoListLte;

/*Added by Lilei for neighbor cell info report on 01082014, end*/

/** \brief Engineering mode: 2G (GSM) neighboring cell information structure  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevGsmNeighboringCellInfo_struct
{
    UINT8  rxSigLevel;  			/**< Receive signal level */
    UINT8  bsic;        				/**< Base transceiver station identity code */
    UINT8  rac;         				/**< Routing area code */
    UINT8  res1U8;      				/**< (padding) */

    UINT16 mcc;         				/**< Mobile country code */
    UINT16 mnc;         				/**< Mobile network code */
    UINT16 lac;         				/**< Location area code */
    UINT16 ci;          				/**< Cell identity */
    UINT16 arfcn;       				/**< Absolute radio frequency channel number */

    INT16  C1;          				/**< Path loss criterion parameter #1 */
    INT16  C2;          				/**< Path loss criterion parameter #2 */
    INT16  C31;         				/**< GPRS signal level threshold criterion parameter */
    INT16  C32;         				/**< GPRS cell ranking criterion parameter */
    /*Michal Bukai - I-Mate Addition. Start:*/
    CiBoolean               IsForbiddenLA;          /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */
    CiDevCellPrioriytType   CellPriority;           /**< Cell priority for cell selection or reselection. Cell priority can be normal, low or barred. \sa CiDevCellPrioriytType */
    /*Michal Bukai - I-Mate Addition. End*/
    /*Lilei, CQ00134586, 20211221, begin*/
    UINT8  lenOfMnc;                    /**< Length of MNC, value range (2,3) */
   	UINT32 reserved1; 
    UINT32 reserved2;
    /*Lilei, CQ00134586, 20211221, begin*/
} CiDevGsmNeighboringCellInfo;

/** \brief Engineering mode: 2G (UMTS) neighboring cell information structure  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevGsmUMTSNeighboringCellInfo_struct
{
    UINT16     arfcn;                 		/**< Absolute radio frequency channel number */
    UINT16    psc_cellParameterId;          /**< Primary scrambling code for FDD or Cell parameter id for TDD */

    INT16       rscp;         		/**< CPICH/PCCPCH received signal code power */
    INT16       cpichEcN0;         		/**< CPICH Ec/N0, only valid for FDD */       
} CiDevGsmUMTSNeighboringCellInfo;

/** \brief Engineering mode: GSM data structure  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeGsmData_struct
{
    CiDevGsmServingCellInfo     		svcCellInfo;		/**< Serving cell information \sa CiDevGsmServingCellInfo_struct */

    CiDevGsmGMMInfo		    		    GMMInfo;		/**< Mobility management information  \sa CiDevGsmGMMInfo_struct */
    CiDevAMRInfo			    		AMRInfo;		/**< AMR information \sa CiDevAMRInfo_struct */
    CiDevGPRSPTMInfo		    		GPRSPTMInfo;	/**< Packet data information \sa CiDevGPRSPTMInfo_struct */

    UINT8                               numNCells;     		/**< Number of neighboring cells [0..CI_DEV_MAX_GSM_NEIGHBORING_CELLS] */
    UINT8                       			res1U8[3];    												/**< (padding) */
    CiDevGsmNeighboringCellInfo 		nbCellInfo[ CI_DEV_MAX_GSM_NEIGHBORING_CELLS ]; 		/**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */

    UINT8                 		        numInterRATNCells;     									/**< Number of InterRAT cells [0..CI_DEV_MAX_GSM_NEIGHBORING_CELLS] */
   UINT8                       	                     res2U8[3];                     									/**< (padding) */
    CiDevGsmUMTSNeighboringCellInfo     InterRATCellInfo[ CI_DEV_MAX_GSM_NEIGHBORING_CELLS ];	/**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */
	/*added by taow 20181107 CQ00112754 begin*/
    CiDevEngModeNcellInfoListLte    nCellInfoListLte; /**< LTE neighbor cells info list */
	/*added by taow 20181107 CQ00112754 end*/
} CiDevEngModeGsmData;

/* ===================================================================================
                3G (UMTS) Engineering Mode Structures
   ===================================================================================*/

/** \brief Engineering mode: 3G (UMTS) serving cell measurements structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsServingCellMeasurements_struct
{
    INT16     rscp;        	/**< CPICH/PCCPCH received signal code power; in UMTS FDD/TDD messages RSCP is
                                    transmitted as an integer value in the range of -120 dBm to -25 dBm.
                                    The value is coded into integers from -5 to 99 according to 3GPP's 25.133.  */
    INT16     utraRssi;         	/**< 	UTRA Carrier RSSI; range 0 - 63
						    		UTRA_carrier_RSSI_LEV _00: UTRA carrier RSSI < -94 dBm
									UTRA_carrier_RSSI_LEV _01: -94 dBm  ?UTRA carrier RSSI < -93 dBm
									UTRA_carrier_RSSI_LEV _02: -93 dBm  ?UTRA carrier RSSI < -92 dBm
									UTRA_carrier_RSSI_LEV _61: -32 dBm  ?UTRA carrier RSSI < -33 dBm
									UTRA_carrier_RSSI_LEV _62: -33 dBm  ?UTRA carrier RSSI < -32 dBm
									UTRA_carrier_RSSI_LEV _63: -32 dBm  ?UTRA carrier RSSI	   */
    INT16     cpichEcN0;        	/**< CPICH Ec/N0, only valid for FDD */
    INT16     sQual;            	/**< Cell selection quality (Squal), only valid for FDD */
    INT16     sRxLev;           	/**< Cell selection Rx level (Srxlev) */
    INT16     txPower;         		/**< UE transmitted power */
    INT16     RxPower;         		/**< CDMA will don't support now, be filled in future *//*added by taow 20181107 CQ00112754 */
/*  TBD: Transport Channel BLER */

} CiDevUmtsServingCellMeasurements;

/** \brief Engineering mode: 3G (UMTS) serving cell PLMN/cell parameters structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsServingCellParameters_struct
{
    UINT8     rac;              			/**< Routing area code */
    UINT8     nom;              			/**< Network operation mode */

    UINT16    mcc;              			/**< Mobile country code */
    UINT16    mnc;              			/**< Mobile network code */
    UINT16    lac;              			/**< Location area code */
    UINT32    ci;               			/**< Cell identity; as per 3G TS 25.331, 10.3.2.2 (28 bits) */
    UINT16    uraId;            			/**< URA identity */
    UINT16    psc_cellParameterId;          /**< Primary scrambling code for FDD or Cell parameter id for TDD */
    UINT16    arfcn;            			/**< Absolute radio frequency channel number */

    UINT16    t3212;            			/**< Periodic LA update timer (T3212) in minutes */
    UINT16    t3312;            			/**< Periodic RA update timer (T3312) in minutes */

    CiBoolean hcsUsed;          		/**< Hierarchical cell structure used? \sa CCI API Ref Manual */
    CiBoolean attDetAllowed;    		/**< Attach-detach allowed? \sa CCI API Ref Manual */


    UINT16    csDrxCycleLen;    		/**< CS domain DRX cycle length */
    UINT16    psDrxCycleLen;    		/**< PS domain DRX cycle length */
    UINT16    utranDrxCycleLen; 	/**< UTRAN DRX cycle length */
    CiBoolean	 HSDPASupport;		/**< TRUE - serving cell supports HSDPA; FALSE - other. \sa CCI API Ref Manual */
    CiBoolean	 HSUPASupport;		/**< TRUE - serving cell supports HSUPA; FALSE - other. \sa CCI API Ref Manual */

    /*Lilei, CQ00092855, 20150427, begin*/
    UINT8     lenOfMnc;             /**< Length of MNC, value range (2,3) */
    /*Lilei, CQ00092855, 20150427, end*/
    /*Lilei, CQ00109042, 20180118, begin*/
    UINT8     band;
    /*Lilei, CQ00109042, 20180118, end*/
    /*Lilei, CQ00115868, 20190815, begin*/
    UINT32    totalHandoversCount;
    UINT32    succeededHandoversCount;
    UINT32    succeededUmtsReselectionCount;
    UINT32    timeStayUmtsConnectedMode; //seconds
    /*Lilei, CQ00115868, 20190815, begin*/
} CiDevUmtsServingCellParameters;

/** \brief Cipher algorithm type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_CIPHER_ALGORITHM_TYPE
{
    CI_CIPHER_ALGORITHM_TYPE_UEA0,    	/**< As per 3G TS 25.331, 10.3.3.4 */
    CI_CIPHER_ALGORITHM_TYPE_UEA1		/**< As per 3G TS 25.331, 10.3.3.4 */
} _CiCipherAlgorithmType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Cipher algorithm type
 * \sa CI_CIPHER_ALGORITHM_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiCipherAlgorithmType;
/**@}*/

/** \brief Cipher algorithm information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCipherAlgorithm_struct
{
    CiBoolean               		algPresent;    	/**< Indicates if an algorithm is defined \sa CCI API Ref Manual */
    CiCipherAlgorithmType   	cipherAlg;		/**< Cipher algorithm type \sa CiCipherAlgorithmType  */
    CiBoolean               		cipherOn;      	/* Ciphering status = on/off \sa CCI API Ref Manual */
}  CiCipherAlgorithmInfo;

/** \brief Engineering mode: 3G (UMTS) UE operation status structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsUeOperationStatus_struct
{
    CiDevEngModeUeRrcState  			rrcState;         				/**< RRC state \sa CiDevEngModeUeRrcState */
    UINT8                   					numLinks;         				/**< Number of radio links */

    UINT16                  					srncId;           				/**<  U-RNTI: SRNC identifier */
    UINT32                  					sRnti;            					/**<  U-RNTI: S-RNTI */
    CiCipherAlgorithmInfo   				csCipherInfo;     				/**<  CS domain ciphering information. \sa CiCipherAlgorithm_struct */
    CiCipherAlgorithmInfo   				psCipherInfo;     				/**<  PS domain ciphering information. \sa CiCipherAlgorithm_struct */
    CiBoolean	 						HSDPAActive;				/**<  TRUE - HSDPA is currently activated; FALSE - other  \sa CCI API Ref Manual  */
    CiBoolean	 						HSUPAActive;				/**<  TRUE - HSUPA is currently activated; FALSE - other  \sa CCI API Ref Manual  */
    UINT16							MccLastRegisteredNetwork;	/**<  Mcc of last registered network */
    UINT16							MncLastRegisteredNetwork;	/**<  Mnc of last registered network */
    INT32	       						TMSI;						/**<  TMSI */
    INT32	       						PTMSI;						/**<  PTMSI */
    CiBoolean                                             IsSingleMmRejectCause;		/**<  TRUE - only one MM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual  */
    CiBoolean                                             IsSingleGmmRejectCause;	/**<  TRUE - only one GMM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual  */
    CiDevEngMMRejectCauseCodeType	 MMRejectCause;				/**<  The one that was reported during the last engineering information period reject cause (10.5.3.6) sent in CM Service Reject, Abort, MM-Status, and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */
    CiDevEngGMMRejectCauseCodeType	 GMMRejectCause;			/**<  Reported during the last engineering information period  \sa CiDevEngGMMRejectCauseCodeType */
    UINT8 								 mmState;					/**<  MM state refer to 3GPP 24.008 section 4.1.2  */  /* see enum MmState in Mm_comm.h. */
    UINT8 								 gmmState;					/**<  GMM state refer to 3GPP 24.008 section 4.1.3  */  /* see enum GmmState in Gmm_comm.h */
    UINT8								 gprsReadyState;				/**<  0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */
    UINT16							 readyTimerValueInSecs;		/**<  MM ready timer value in sec [value >0] */
    UINT8								 NumActivePDPContext;		/**<  Number of active PDP contexts */
	/*Michal Bukai - I-Mate Addition. Start:*/
	UINT32              ULThroughput;           /**< UL throughput in octets per second */
	UINT32              DLThroughput;           /**< DL throughput in octets per second */
	/*Michal Bukai - I-Mate Addition. End*/
/*Added by Lilei for Network Info CQ56702, begin*/
    UINT8                           serviceStatus;              /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */
    UINT8                           pmmState;                   /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */
/*Added by Lilei for Network Info CQ56702, end*/
/*Lilei, CQ00082362, 20150116, begin*/
    UINT8                           LAU_status;                 /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */
    UINT16                          LAU_count;                  /**<LAU attempt counter as held by UE; number of consecutive LAU failures in current LAU procedure attempt */
    UINT8                           RAU_status;                 /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */
    UINT16                          RAU_count;                  /**<RAU attempt counter as held by UE; number of consecutive RAU failures in current RAU procedure attempt*/
/*Lilei, CQ00082362, 20150116, end*/
    /*added by taow 20181107 CQ00112754 begin*/
	UINT16                phyChType;// 0 is DPCH, 1 is FDPCH. 0xFF is invalid
	UINT16                sf;
	UINT8                 slotFormat;
    CiBoolean             compressMode;
	CiDevAmrCodecType               codecType;/*wCdma*/
    UINT32			                speechCodecRate;/*wCdma*/
	INT16         					rssi; 
	CiBoolean						isSinrPresent;
	INT16         					sinr;
	
	/*added by taow 20181107 CQ00112754 end*/

} CiDevUmtsUeOperationStatus;

/** \brief Engineering mode 3G (UMTS) serving cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsServingCellInfo_struct
{
    CiBoolean                        		 	sCellMeasPresent; 	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    CiBoolean                         			sCellParamPresent;	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    CiBoolean                         			ueOpStatusPresent;	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    UINT8                             				res1U8;				/**< padding */
    CiDevUmtsServingCellMeasurements  	sCellMeas;  			/**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */
    CiDevUmtsServingCellParameters    	sCellParam; 			/**< PLMN/cell parameters \sa CiDevUmtsServingCellParameters_struct 	*/
    CiDevUmtsUeOperationStatus        		ueOpStatus; 			/**< UE operation status \sa CiDevUmtsUeOperationStatus_struct 		*/
} CiDevUmtsServingCellInfo;


/** \brief Engineering mode 3G (UMTS) active set information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsASInfo_struct
{
    UINT32   	 ci;               					/**< Cell identity; as per 3G TS 25.331, 10.3.2.2 (28 bits) */
    UINT16   	 psc;             			 		/**< Primary scrambling code */
    CiBoolean	 HSDPAServingCell;			/**< Indicates if this cell is the HSDPA serving cell \sa CCI API Ref Manual */
    CiBoolean	 HSUPAServingCell;  			/**< Indicates if this cell is part of the HSUPA active set - relevant for rel. 6 \sa CCI API Ref Manual */
    INT16     	 cpichRSCP;    		 		/**< CPICH received signal code power; in UMTS FDD messages RSCP is transmitted as an integer value in the range of -120 dBm to -25 dBm. The value is coded into integers from -5 to 99 according to 3GPP's 25.133.  */
    INT16         cpichEcN0;   					/**< CPICH Ec/N0 [dB]  */
    UINT16    mcc;          					/**< Mobile country code */
    UINT16    mnc;         				  	/**< Mobile network code */
    UINT16    lac;          						/**< Location area code */
    UINT8     rac;	      						/**< Routing area code, range 0-1 (1 bit) */
} CiDevUmtsASInfo;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_ACTIVE_SET_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeActiveSetInfoInd_struct
{
  UINT8               		NumCells;  							 /**< Number of cells in active set */
  UINT16    	              arfcn;       							 /**< Absolute Radio Frequency Channel Number; number 0-1023  */
  UINT8               		res1U8;     							 /**< (padding) */
  CiDevUmtsASInfo 	ASinfo[CI_DEV_MAX_CELLS_IN_AS]; 	 /**< Active Set Information. \sa CiDevUmtsASInfo_struct */
} CiDevPrimUmtsEngmodeActiveSetInfo;


/** \brief  Engineering mode 3G (UMTS) intra-frequency/inter-frequency FDD/TDD cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsFddTddNeighborInfo_struct
{
    /* Measurements */
    INT16  rscp;        	    /**< CPICH/PCCPCH received signal code power */
    INT16  utraRssi;           	/**< UTRA carrier RSSI */
    INT16  cpichEcN0;        	/**< CPICH Ec/N0, only valid for FDD */
    INT16  sQual;              	/**< Cell selection quality (Squal), only valid for FDD  */
    INT16  sRxLev;            	/**< Cell selection Rx level (Srxlev) */

    /* PLMN/Cell Parameters */
    UINT16   mcc;              	/**< Mobile country code */
    UINT16   mnc;              	/**< Mobile network code */
    UINT16   lac;                	/**< Location area code */
    UINT16   ci;                  	/**< Cell Identity */
    UINT16   arfcn;            	/**< Absolute radio frequency channel number */
    UINT16   psc_cellParameterId; /**< Primary scrambling code for FDD or Cell parameter id for TDD */
	/*added by taow 20181107 CQ00112754 begin*/
	CiBoolean set;               /* intra  freq neighbor 1: active ;  0 : 2 sync neighbor set  ,3 Async neighbor set */
	/*added by taow 20181107 CQ00112754 end*/
} CiDevUmtsFddTddNeighborInfo;

/** \brief  Engineering mode 3G (UMTS) inter-RAT GSM cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsGsmNeighborInfo_struct
{
    /* Measurements */
    INT16  gsmRssi;         	/**< GSM carrier RSSI */
    INT16  rxLev;             	/**< Cell selection Rx level */
    INT16  C1;                  /**< Path loss criterion parameter #1 */
    INT16  C2;                  /**< Path loss criterion parameter #2 */

    /* PLMN/Cell Parameters */
    UINT16  mcc;               	/**< Mobile country code */
    UINT16  mnc;               	/**< Mobile network code */
    UINT16  lac;                /**< Location area code */
    UINT16  ci;                 /**< Cell identity */
    UINT16  arfcn;             	/**< Absolute radio frequency channel number */
    UINT8   bsic;		   	    /**< Base transceiver station identity code; range 0h-3Fh (6 bits) */
    UINT8   res1U8;
	/*added by taow 20181107 CQ00112754 begin*/
	INT16   rank;              //  rValueRscp;
	/*added by taow 20181107 CQ00112754 end*/
} CiDevUmtsGsmNeighborInfo;

/** \brief  Engineering mode: UMTS data structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeUmtsData_struct
{
    /* Serving Cell information */
    CiDevUmtsServingCellInfo  		 svcCellInfo;										/**< Serving cell information.  \sa CiDevUmtsServingCellInfo_struct */
    UINT8                     				 LastsCellParamsListIndex; 						/**< Number of serving cells in last serving cells list */
    CiDevUmtsServingCellParameters    LastsCellParamsList[CI_DEV_MAX_CELLS_IN_AS];  	/**< PLMN/cell parameters of the list  \sa CiDevUmtsServingCellParameters_struct */

    CiDevPrimUmtsEngmodeActiveSetInfo	   ASInfo; 									/**< Active set information  \sa CiDevPrimUmtsEngmodeActiveSetInfoInd_struct */

    /* Neighboring Cell information */
    UINT8                     numIntraFreq; 												/**< Number of intra-frequency FDD cells */
    UINT8                     numInterFreq; 												/**< Number of inter-frequency FDD cells */
    UINT8                     numInterRAT;  												/**< Number of inter-RAT GSM cells */
	/*Add by taow for SSG request to get RRC release casue 20140902,CQ 69749, , begin*/
    UINT8                	  numberOfRabs;//in order to not impact current EM CI interface, this only used by call drop
    UINT16              	  ul_arfcn;//in order to not impact current EM CI interface, this only used by call drop , CQ77239
	/*Add by taow for SSG request to get RRC release casue 20140902,CQ 69749, , end*/    												

    CiDevUmtsFddTddNeighborInfo  		intraFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ]; 	/**< Intra-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */
    CiDevUmtsFddTddNeighborInfo  		interFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];	/**< Inter-frequency information \sa CiDevUmtsFddTddNeighborInfo_struct */
    CiDevUmtsGsmNeighborInfo  			interRAT[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];	/**< Inter-RAT information  \sa CiDevUmtsGsmNeighborInfo_struct */

    CiDevEngActivePDPContextinfoType       activePDPContextinfo[CI_DEV_ENG_MAX_ACTIVE_PDP_CONTEXT];  /**< Active PDP context data  \sa CiDevEngActivePDPContextinfoType_struct */
	/*added by taow 20181107 CQ00112754 begin*/
    CiDevEngModeNcellInfoListLte    nCellInfoListLte; /**< LTE neighbor cells info list */
	/*added by taow 20181107 CQ00112754 end*/
} CiDevEngModeUmtsData;

/** \brief LteEngErrc Mode State */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_ENG_MODE_STATE_TAG
{
    CI_DEV_LTE_ENGINEER_RRC_DEACTIVATED = 0,    /**< RRC DEACTIVATED */
    CI_DEV_LTE_ENGINEER_RRC_IDLE,               /**< RRC IDLE */
    CI_DEV_LTE_ENGINEER_RRC_CONNECTED,          /**< RRC CONNECTED */   
    CI_DEV_LTE_ENGINEER_RRC_IRAT_RESELETCTION,  /**< RRC RESELETCTION */ 

    /* This must be the last entry */
    CI_DEV_NUM_LTE_ENGINEER_MODE_STATE
} _CiDevLteEngModeState;


/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief LteEngErrc Mode State.
 * \sa CIDEV_LTEENGMODE_STATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLteEngModeState;
/**@}*/

/** \brief LteEngL1Config Type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiDEV_LTE_ENG_L1_CONFIG_TYPE_TAG
{
    CI_DEV_LTE_ENG_INVALID_RRC_L1_CONFIG,// The IE is not initialized
    CI_DEV_LTE_ENG_NOTCHANGE_SETUP_RRC_L1_CONFIG,//The IE was setup and its value is not changed in this configuration
    CI_DEV_LTE_ENG_NOTCHANGE_RELEASE_RRC_L1_CONFIG,//The IE was released and its value is not changed in this configuration
    CI_DEV_LTE_ENG_SETUP_RRC_L1_CONFIG, //The IE's value is setup or configured
    CI_DEV_LTE_ENG_RELEASE_RRC_L1_CONFIG, //The IE's value is released
    CI_DEV_LTE_ENG_L1_CREATE_VALUE_CONFIG,// Used for NEED OP with absent flag only, only when the default value is maintained by L1

    CI_DEV_LTE_ENG_RRC_L1_CONFIG_TYPE_INVALID = 0x7FFFFFFF
}
_CiDevLteEngL1ConfigType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief LteRrcL1Config Type.
 * \sa _CiDEV_LTE_ENG_L1_CONFIG_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLteEngL1ConfigType;
/**@}*/

//ICAT EXPORTED STRUCT
typedef struct  CiDevLteEngDrxConfig_struct
{
    //Timer for DRX in TS 36.321, value range(1,2,3,4,5,6,8,10,20,30,40,50,60,80,100,200)
    UINT8     onDurationTimer;
    //Timer for DRX in TS 36.321,value range (1,2,4,6,8,16,24,33)
    UINT8     drxRetransmissionTimer;
    //Drx inactivity timer in TS36.321, value range(1,2,3,4,5,6,8,10,20,30,40,50,60,80,100,200,300,500,750,1280,1920,2560)
    UINT16    drxInactivityTimer;

    //long DRX cycle, value range(10,20,32,40,64,80,128,160,256,320,512,640,1024,1280,2048,2560)
    UINT16    longDrxCycle;
    //drx Start offset, value range (0~2559), this value should be less than longDrxCycle
    UINT16    drxStartOffset;

    //If this IE doesn't exists in ASN.1 message, value 0 for release should be filled here
    //Value range(2,5,8,16,20,32.40,64,80,128,160,256,320,512,640)
    UINT16    shortDrxCycle;
    //If this IE doesn't exists in ASN.1 message, value 0 for release should be filled here
    //Value range:1~16
    UINT8     drxShortCycleTimer;
    UINT8     reserved0;

    //Configuration type of  shortDrx
    CiDevLteEngL1ConfigType  shortDrxConfigType;
}
CiDevLteEngDrxConfig;

//ICAT EXPORTED STRUCT
typedef struct CiDevLtePlmnIdentity_struct
{
    UINT16                  mcc;
    //Length of MNC, value range (2,3)
    UINT8                   lenOfMnc;
    //2-3 digits of MNC
    UINT16                  mnc;
}CiDevLtePlmnIdentity;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellParams_struct
{
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                  mcc;
    UINT8                   lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                  mnc;        /**< 2-3 digits of MNC */
    UINT16                  tac;
    UINT16                  phyCellId;
    UINT32                  dlEuArfcn;
    UINT32                  ulEuArfcn;
    UINT16                  band;
    UINT8                   dlBandwidth;/*0 - 1.4M, 1 - 3M, 2 - 5M, 3 - 10M, 4 - 15M, 5 - 20M */
    UINT32                  cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
/*Added by taow for LTE EM L2 info, begin*/
	UINT8           		subFrameAssignType;
	UINT8           		specialSubframePatterns;
	UINT8           		transMode;
/*Added by taow for LTE EM L2 info, end*/

/*Added by taow for Handover event info, begin*/

	UINT32					totalHandoversCount;
	UINT32					succeededHandoversCount;
/*Added by taow for Handover event info, begin*/
	/*added by taow 20181107 CQ00112754 begin*/
    CiBoolean               isTdd; 
    UINT8			        subframeAssignment;//only Valid if isTdd= TRUE, Value range: (0,1,2,3,4,5,6), in SIB1 tdd-Config.
	/*added by taow 20181107 CQ00112754 end*/
/*Lilei, CQ00115868, 20190815, begin*/
    UINT32                  succeededLteReselectionCount;
    UINT32                  succeededLteReestCounter;
    UINT32                  timeStayConnectedMode; //seconds
/*Lilei, CQ00115868, 20190815, end*/
/*Lilei, CQ00126320, 20201123, begin*/
	CiBoolean			    longDRXCyclePresent;
	UINT16				    longDRXCycle;  /**< long DRX cycle in ms */
	CiBoolean			    shortDRXCyclePresent;
	UINT16				    shortDRXCycle; /**< short DRX cycle in ms */
    UINT16                  pagingCycle; /**< The pagingCycle is configured in unit of 10ms, aligned to 36.331 */
/*Lilei, CQ00126320, 20201123, end*/
/*Lilei, CQ00134582, 20211221, begin*/
    UINT16                  t3402; /**< timer T3402 in seconds */
    UINT16                  t3412; /**< timer T3412 in seconds */
    /*Lilei, CQ00137275, 20220616, begin*/
    //UINT32                  reserved1;
   	INT8                    refSignalPower; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50, invalid(0x7F). */
    UINT8                   establishmentCause; /**< RRC connection request cause */ /*Lilei, CQ00146454, 20231023*/
   	UINT16      			reserved1; 
    /*Lilei, CQ00137275, 20220616, end*/
    UINT32                  reserved2;
    UINT32                  reserved3;
    UINT32                  reserved4;
/*Lilei, CQ00134582, 20211221, end*/
}
CiDevLteEngScellParams;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellMeas_struct
{
    UINT8                   rsrp;
    UINT8                   rsrq;
    INT8                    sinr;	
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT8                   mainRsrp; /**< Rsrp of main antenna. Value range: 0~97, invalid(0xFF) */
    UINT8                   diversityRsrp; /**< Rsrp of diversity antenna. Value range: 0~97, invalid(0xFF) */
    UINT8                   mainRsrq; /**< Rsrq of main antenna. Value range: 0~34, invalid(0xFF) */
    UINT8                   diversityRsrq; /**< Rsrq of diversity antenna. Value range: 0~34, invalid(0xFF) */
    UINT8                   rssi; /**< Same value as CESQ rxlev */
    UINT16                  cqi; /**< Value range: 0~15, invalid(0xFFFF). */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/	
/*Added by taow for LTE EM L2 info, begin*/	
	UINT8           		pathLoss;
	UINT32          		tb0DlTpt;
	UINT32          		tb1DlTpt;
	UINT32           		tb0DlPeakTpt;
    UINT32           		tb1DlPeakTpt;
    UINT32           		tb0UlPeakTpt;
    UINT32           		tb1UlPeakTpt;
	//EmacdlStatisticDataTag
	UINT32					dlThroughPut;     //dl throughtput unit bps, sum(dl tb size in bits)/dl statistic time duration
	UINT32      			dlPeakThroughPut; //Kbps
	UINT8       			averDlPRB;
	UINT8       			averCQITb0;
	UINT8       			averCQITb1;    
	UINT8       			rankIndex;
	// EmaculStatisticDataTag
	UINT32      			grantTotal;        //total received grant size in unit of BYTE	
	UINT32      			ulThroughPut; //Kbps
	UINT32      			ulPeakThroughPut; //Kbps
	INT16      				currPuschTxPower;
	UINT8       			averUlPRB;
  //add by taow 20150415 begin  
    UINT8       			averULMcs;//modify by taow 20190220
    UINT16      			dlBler;
    UINT16      			ulBler;
    /*modify by taow CQ00131112 20210621 begin*/
    //UINT32      			      reserved1;    
    INT8                    diversitySinr;
    UINT8                   diversityRssi;
    UINT8                   qRxLevMin;       /**<  report value range[0,96],real value range[-140, -44],real value =IE value - 140 ;eg:0-140= -140,96-140=-44*/
    /*Lilei, CQ00137040, 20220527, begin*/
    INT8                    qQualMin;
    //UINT8                   reserved1_1;     
    /*Lilei, CQ00137040, 20220527, end*/
	/*modify by taow CQ00131112 20210621 end*/
    /*Lilei, CQ00143212, 20230424, begin*/
   	//UINT32      			reserved2; 
    INT8                    mainSinr; /**< SINR of main antenna */
    UINT8                   mainRssi; /**< RSSI of main antenna */
   	UINT16     			    reserved2_1; 
    /*Lilei, CQ00143212, 20230424, end*/
    
	UINT32      			reserved3; 
	UINT32      			reserved4;
  //add by taow 20150415 end  
/*Added by taow for LTE EM L2 info, end*/
    /*added by taow 20181107 CQ00112754 begin*/
    INT16                    srxlev; 
    INT16                    txPower; //PUSCH tx power.
 	UINT8                   mainDLMcs; /**< Modulation and coding scheme (MCS) of main antenna. Value range: 0~32 */
    UINT8                   diversityDLMcs; /**< Modulation and coding scheme (MCS) of diversity antenna. Value range: 0~32 */
    /*added by taow 20181107 CQ00112754 end*/
    /*Lilei, CQ00115868, 20190815, begin*/
    UINT8                   averDlMcsTb0;
    UINT8                   averDlMcsTb1;
    /*Lilei, CQ00115868, 20190815, end*/
}
CiDevLteEngScellMeas;

//ICAT EXPORTED STRUCT
typedef struct CiDevLtePlmnIdentityInfo_struct
{
    CiDevLtePlmnIdentity                  plmnIdentity;
    CiBoolean                          cellReservedForOperatorUse;
}CiDevLtePlmnIdentityInfo;

/** \brief LteRrcConfig Type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_CONFIG_TYPE_TAG
{
    CI_DEV_LTE_NOTPRESENT_RRC_CONFIG,
    //PRESENT,
    CI_DEV_LTE_SETUP_RRC_CONFIG,
    CI_DEV_LTE_RELEASE_RRC_CONFIG    
}
_CiDevLteRrcConfigType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief LteRrcConfig Type.
 * \sa CIDEV_LTE_RRC_CONFIG_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLteRrcConfigType;
/**@}*/


//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngineerCellAccessRestrictions_struct
{
    UINT8                                   numOfPlmnInList;
    CiDevLtePlmnIdentityInfo                    plmnIdentityList[CI_DEV_LTE_PLMN_LIST_SIZE];
    //To identify a tracking area within the scope of a PLMN
    UINT16                                  trackingAreaCode;
    // the IE is used to unambiguously identify a cll within a PLMN
    UINT32                                  cellIdentity;
    CiBoolean                                cellBarred;
    CiBoolean                                intraFreqReselAllowed;
    CiBoolean                                csgIndication;
    //Release or set up a closed subscriber group
    CiDevLteRrcConfigType                       csgIdentityR9ConfigType;
    //to identify a Closed Subscriber Group,BIT STRING (SIZE (27))
    UINT32                                  csgIdentityR9;

}CiDevLteEngineerCellAccessRestrictions;

/** \brief lte engineer barred status Type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_ENGINEER_BARRED_STATUS_TAG
{
    CI_DEV_LTE_ENGINEER_NOT_BARRED,
    CI_DEV_LTE_ENGINEER_BARRED_NO_SERVICE,
    CI_DEV_LTE_ENGINEER_BARRED_EMERGENCY_ONLY
}
_CiDevLteEngineerBarredStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief lte engineer barred status Type.
 * \sa CIDEV_LTE_RRC_CONFIG_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLteEngineerBarredStatus;
/**@}*/

/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
//ICAT EXPORTED STRUCT
typedef struct CiDevLteUeOperationStatus_struct
{
    CiDevLteEngModeState            errcModeState;      /**< ERRC state \sa CiDevLteEngModeState */
    UINT8                           emmState;           /**<  EMM state  */  /* see enum EmmState in Mmr_sig.h */
    UINT8                           serviceState;       /**<  Service state  */  /* see enum ServiceStatus in Mmr_sig.h */
    CiBoolean                       IsSingleEmmRejectCause;		/**<  TRUE - only one EMM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual  */
    UINT32                          EMMRejectCause;             /**<  Reported during the last engineering information period  */
    UINT16                          mmeGroupId;         /**< A member of GUTI */
    UINT8                           mmeCode;            /**< A member of GUTI */
    UINT32                          mTmsi;              /**< A member of GUTI */
    /*Lilei, CQ00126320, 20201123, begin*/
    CiDevServiceType                serviceDomain;      /**< CS or PS domain, 0:CS only;1:PS only;2:Combined CS/PS;3:no service */
    /*Lilei, CQ00126320, 20201123, end*/
} CiDevLteUeOperationStatus;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellInfo_struct
{
    CiDevLteEngScellParams       params;
    CiDevLteEngScellMeas         meas;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
    //CiDevLteEngineerBarredStatus            barredStatus;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    CiDevLteUeOperationStatus               ueOpStatus;     /**< UE operation status \sa CiDevLteUeOperationStatus */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
}
CiDevLteEngScellInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngNcellSib1_struct
{
    //To indicate for cell re-selection the required minimum received RSRP level in the (E-UTRA) cell. 
    //Corresponds to parameter Qrxlevmin in 36.304 [4]. Actual value Qrxlevmin = IE value * 2 [dBm].
    INT16                      qRxLevMin;      //RHGUO: -140 ~ -44
    CiBoolean                  qRxLevMinOffsetPresent;
    //Parameter Qrxlevminoffset in 36.304 [4]. Actual value Qrxlevminoffset = IE value * 2 [dB]. If absent,
    //apply the (default) value of 0 [dB] for Qrxlevminoffset. Affects the minimum required Rx level in the cell.
    UINT8                      qRxLevMinOffset;
    CiBoolean                  cellSelectionInfoV920Present;
    INT8                       qQualMinR9;
    CiBoolean                  qQualMinOffsetR9Present;
    UINT8                      qQualMinOffsetR9;
}
CiDevLteEngNcellSib1;


/**
 * Engineering mode information about
 * an Intra-Frequency LTE cell.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngIntraFreqNcellInfo_struct
{
    UINT16                        phyCellId;
    UINT32                        euArfcn;
    UINT8                         rsrp;
    UINT8                         rsrq;
    //CiBoolean                     ncellSib1Valid;
    //CiDevLteEngNcellSib1          ncellSib1;
    //CiBoolean                     accessRestrictionsPresent;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                        mcc;
    UINT8                         lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                        mnc;        /**< 2-3 digits of MNC */
    UINT16                        tac;
    UINT32                        cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
	/*added by taow 20181107 CQ00112754 begin*/ 
    INT16 						   srxlev; 
    //Value range:0~7, Value 0 means lowest priority
    UINT8            cellReselectionPriority;
    UINT8            sNonIntraSearch;
    UINT8            threshServingLow;
    UINT16           sIntraSearch;
	//Int8                       sinr     //  replace by rsrq;	
   	/*added by taow 20181107 CQ00112754 end*/
    /*Lilei, CQ00137275, 20220630, begin*/
   	INT8                    refSignalPower; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50, invalid(0x7F). */
    /*Lilei, CQ00137275, 20220630, end*/
    UINT8                   reserved1_0;
   	UINT16      			reserved1; 
   	UINT32      			reserved2;
	UINT32      			reserved3;
	UINT32      			reserved4;
}
CiDevLteEngIntraFreqNcellInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngIntraFreqNcellList_struct
{
    UINT8                               numberOfCells;
    CiDevLteEngIntraFreqNcellInfo       cellInfo[CI_DEV_LTE_MAX_CELL_INTRA];
}
CiDevLteEngIntraFreqNcellList;

/**
 * Engineering mode information about
 * an Inter-Frequency LTE cell.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngInterFreqNcellInfo_struct
{
    UINT16                         phyCellId;
    UINT32                         euArfcn;
    UINT8                          rsrp;
    UINT8                          rsrq;
    //CiBoolean                      ncellSib1Valid;
    //CiDevLteEngNcellSib1           ncellSib1;
    //CiBoolean                      accessRestrictionsPresent;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                         mcc;
    UINT8                          lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                         mnc;        /**< 2-3 digits of MNC */
    UINT16                         tac;
    UINT32                         cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
     /*added by taow 20181107 CQ00112754 begin*/
	 INT16						   srxlev; 
	 UINT8						   threshXLow;//Value range:0~31 received from SIB5
	 UINT8						   threshXHigh;//Value range:0~31 received from SIB5
	 UINT8			 			   cellReselectionPriority;
	 /*added by taow 20181107 CQ00112754 begin*/
	 //Int8                       sinr     //  replace by rsrq;
	 /*added by taow 20181107 CQ00112754 end*/
	 /*added by taow 20181107 CQ00112754 end*/
     /*Lilei, CQ00137275, 20220630, begin*/
     INT8                    refSignalPower; /**< PDSCH-ConfigCommon.referenceSignalPower. Value range: -60~50, invalid(0x7F). */
     /*Lilei, CQ00137275, 20220630, end*/
     UINT8                   reserved1_0;
     UINT16                  reserved1; 
     UINT32                  reserved2;
     UINT32                  reserved3;
     UINT32                  reserved4;
}
CiDevLteEngInterFreqNcellInfo;


/**
 * Engineering mode information about the
 * Inter-Frequency LTE cells.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngInterFreqNcellList_struct
{
    UINT8                               numberOfCells;
    CiDevLteEngInterFreqNcellInfo       cellInfo[CI_DEV_LTE_MAX_CELL_INTER];
}
CiDevLteEngInterFreqNcellList;

/**
 * GSM cell parameter information.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraCellParamsStruct
{
    UINT16              mcc;              			/**< Mobile country code */
    UINT16              mnc;              			/**< Mobile network code */
    UINT16              lac;              			/**< Location area code */
    UINT32              ci;               			/**< Cell identity; as per 3G TS 25.331, 10.3.2.2 (28 bits) */
    UINT16              uArfcn;
    UINT16              psc_cellParameterId;        /**< Primary scrambling code for FDD or Cell parameter id for TDD */
    //UINT16              phyCellId;
     /*added by taow 20181107 CQ00112754 begin*/
    UINT8               cellReselectionPriority;
    UINT8               threshXHigh;//Value range:0~31 received from SIB6
    UINT8               threshXLow;//Value range:0~31 received from SIB6
    /*added by taow 20181107 CQ00112754 end*/
    /*Lilei, CQ00134586, 20211221, begin*/
    UINT8               lenOfMnc;                   /**< Length of MNC, value range (2,3) */
    UINT32              reserved1;
    UINT32              reserved2;
    /*Lilei, CQ00134586, 20211221, end*/
}
CiDevLteEngUtraCellParams;

/**
 * Utra cell measurement information.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraCellMeas_struct
{
    INT16               rscp;        	            /**< CPICH/PCCPCH received signal code power; in UMTS FDD/TDD messages RSCP is
                                                                                                transmitted as an integer value in the range of -120 dBm to -25 dBm.
                                                                                                The value is coded into integers from -5 to 99 according to 3GPP's 25.133.  */
    //INT16                pccpch_RSCP; //for TDD
    INT16               cpichEcN0;//For FDD
    //INT16                cpichRscp;//For FDD
    INT16                srxlev;/*added by taow 20181107 CQ00112754 */
}
CiDevLteEngUtraCellMeas;

/**
 * Engineering mode information about
 * an Utra cell.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraNcellInfo_struct
{
    CiDevLteEngUtraCellParams   params;
    CiDevLteEngUtraCellMeas     meas;
}
CiDevLteEngUtraNcellInfo;

/**
 * Engineering mode information about the
 * Utra cells.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraCellList_struct
{
    UINT8                          numberOfCells;
    CiDevLteEngUtraNcellInfo       cellInfo[CI_DEV_LTE_MAX_CELL_UTRA];
}
CiDevLteEngUtraCellList;

/**
 * GSM cell parameter information.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngBsic_struct
{
    // the lowest 0~2 bits of bsic store the bcc, the lowest 3~5 bit of bsic store the ncc
    UINT8    ncc;
    UINT8    bcc;
}
CiDevLteEngBsic;

/**
 * GSM cell parameter information.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellParams_struct
{
    UINT16              mcc;               	        /**< Mobile country code */
    UINT16              mnc;               	        /**< Mobile network code */
    UINT16              lac;                        /**< Location area code */
    UINT32              ci;                         /**< Cell identity */
    UINT16              arfcn;                      /**< Absolute radio frequency channel number */
    //UINT8              gsmBandIndicator;
    //CiBoolean          bsicPresent; //ncc and bcc is valid only when bsicPresent is TURE.
    //CiDevLteEngBsic    bsic;
    UINT8               bsic;                       /**< Base transceiver station identity code; range 0h-3Fh (6 bits); 0xFF means not present */
	 /*added by taow 20181107 CQ00112754 begin*/
	UINT8               gsmBandIndicator;
    UINT8               cellReselectionPriority;
    UINT8               threshXHigh;//Value range:0~31 received from SIB7
    UINT8               threshXLow;//Value range:0~31 received from SIB7
    CiBoolean			nccPermitted;
    /*added by taow 20181107 CQ00112754 end*/
    /*Lilei, CQ00134586, 20211221, begin*/
    UINT8               lenOfMnc;                   /**< Length of MNC, value range (2,3) */
    UINT32              reserved1;
    UINT32              reserved2;
    /*Lilei, CQ00134586, 20211221, end*/
}
CiDevLteEngGsmCellParams;

/**
 * GSM cell measurement information.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellMeas_struct
{
    INT16       rssi;         /**< GSM carrier RSSI */
	INT16       srxlev; /*added by taow 20181107 CQ00112754 */
}
CiDevLteEngGsmCellMeas;

/**
 * Engineering mode information about a  GSM cell.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellInfo_struct
{
    CiDevLteEngGsmCellParams   params;
    CiDevLteEngGsmCellMeas     meas;
}
CiDevLteEngGsmCellInfo;


/**
 * Engineering mode information about the GSM cells.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellList_struct
{
    UINT8                      numberOfCells;
    CiDevLteEngGsmCellInfo     cellInfo[CI_DEV_LTE_MAX_CELL_GSM];
}
CiDevLteEngGsmCellList;

#if 0 //no use any more by taow
/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INFO_IND">   */
typedef struct CiDevPrimLteEngModeInfoInd_struct
{
    CiDevLteEngModeState            errcModeState;  /**< RRC DEACTIVATED, IDLE,CONNECTED and RESELETCTION*/
    CiBoolean                       sCellPresent;                
    CiDevLteEngScellInfo            sCell;
    CiBoolean                       intraFreqNcellsPresent;
    CiDevLteEngIntraFreqNcellList   intraFreqNcells;
    CiBoolean                       interFreqNcellsPresent;
    CiDevLteEngInterFreqNcellList   interFreqNcells;
    CiBoolean                       utraNcellsPresent;
    CiDevLteEngUtraCellList         utraNcells;
    CiBoolean                       gsmNcellsPresent;
    CiDevLteEngGsmCellList          gsmNcells;
} CiDevPrimLteEngModeInfoInd;
#endif
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_struct
{
  //CiDevLteEngModeState              mode;               /**< Current mode (deactivated/idle/connected/reselection) \sa CiDevLteEngModeState */
  CiBoolean                         sCellPresent;       /**< Whether serving cell engmode info is present */
  UINT8               	            res1U8[3];          /**< (padding) */
  CiDevLteEngScellInfo 	            info;  	            /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */
} CiDevPrimLteEngmodeScellInfoInd;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_struct
{
    UINT8                     	    numIntraFreq; 								/**< Number of Intra-Frequency Cells */
    UINT8                     	    res1U8[3];    								/**< (padding) */
    CiDevLteEngIntraFreqNcellInfo   intraFreq[ CI_DEV_LTE_MAX_CELL_INTRA ];		/**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */
} CiDevPrimLteEngmodeIntraFreqInfoInd;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_struct
{
    UINT8                     	    numInterFreq;                               /**< Number of Inter-Frequency Cells */
    UINT8                     	    res1U8[3];    	                            /**< (padding) */
    CiDevLteEngInterFreqNcellInfo   interFreq[ CI_DEV_LTE_MAX_CELL_INTER ];	    /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */
} CiDevPrimLteEngmodeInterFreqInfoInd;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeInterRatInfoInd_struct
{
    UINT8                     	    numInterRATUtra;                            /**< Number of Inter-RAT UMTS Cells */
    UINT8                     	    numInterRATGsm;                             /**< Number of Inter-RAT GSM Cells */
    UINT8                     	    res1U8[2];                                  /**< (padding) */
    CiDevLteEngUtraNcellInfo        interRATUtra[ CI_DEV_LTE_MAX_CELL_UTRA ];   /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */
    CiDevLteEngGsmCellInfo          interRATGsm[ CI_DEV_LTE_MAX_CELL_GSM ];     /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */
} CiDevPrimLteEngmodeInterRatInfoInd;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

/*===================================================================================
         El Gato Gordo: Main Engineering Mode Information structures
  ===================================================================================*/

/** \brief  Engineering mode: GSM data structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeGsmDataInfo_struct
{
      CiDevEngModeGsmData   			data;    /* GSM data \sa CiDevEngModeGsmData_struct  */
      CiDevEngActivePDPContextinfoType     activePDPContextinfo[CI_DEV_ENG_MAX_ACTIVE_PDP_CONTEXT];  /* ActivePDPContext data. \sa CiDevEngActivePDPContextinfoType_struct */
} CiDevEngModeGsmDataInfo;

/* VADIM fix for CQ00082654 - debug only */
/** \brief  UMTS and GSM Data Information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeGsmUmtsData_struct{
      CiDevEngModeUmtsData  			umtsData;   	/**< UMTS Data. \sa CiDevEngModeUmtsData_struct */
      CiDevEngModeGsmDataInfo   	       gsmData;    	/**< GSM Data. \sa CiDevEngModeGsmDataInfo_struct */
} CiDevEngModeGsmUmtsData;
/* VADIM fix for CQ00082654 - debug only */

/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
/** \brief  Engineering mode: LTE data structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeLteData_struct
{
    //CiDevLteEngModeState            errcModeState;      /**< RRC DEACTIVATED, IDLE,CONNECTED and RESELETCTION*/
    
    CiBoolean                       sCellPresent;
    CiBoolean                       intraFreqNcellsPresent;
    CiBoolean                       interFreqNcellsPresent;
    CiBoolean                       utraNcellsPresent;
    CiBoolean                       gsmNcellsPresent;
    CiBoolean                       sCellUpdated;   /**< wether svc cell has been updated or not */
    UINT8                           res1U8[2];          /**< (padding) */
    
    CiDevLteEngScellInfo            sCell;
    CiDevLteEngIntraFreqNcellList   intraFreqNcells;
    CiDevLteEngInterFreqNcellList   interFreqNcells;
    CiDevLteEngUtraCellList         utraNcells;
    CiDevLteEngGsmCellList          gsmNcells;
} CiDevEngModeLteData;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

/** \brief  Main engineering mode information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeInfo_struct
{
    CiDevEngModeState       mode;       				/**< Current mode (idle/dedicated) \sa CiDevEngModeState */
    CiDevEngModeNetwork     network;    				/**< Network type (GSM/UMTS) \sa CiDevEngModeNetwork */
    UINT8                   res1U8[2];  					/**< (padding) */

/* VADIM fix for CQ00082654 - debug only */
    CiDevEngModeGsmUmtsData   *data;
    /* UMTS or GSM Data -- depending on network type */
    /* UMTS or GSM Data -- depending on Network Type */
//    union
//    {
//      CiDevEngModeUmtsData  			umtsData;   	/**< UMTS Data. \sa CiDevEngModeUmtsData_struct */
//      CiDevEngModeGsmDataInfo   	       gsmData;    	/**< GSM Data. \sa CiDevEngModeGsmDataInfo_struct */
//    } data;
/* VADIM fix for CQ00082654 - debug only */
    
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    CiDevEngModeLteData     *lteData;    /**< LTE Enginerring Mode Data */
    CiBoolean               isDualLinkLteOn;    /**< Whether LTE is registered for dual link */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
} CiDevEngModeInfo;

/** <paramref name="CI_DEV_PRIM_STATUS_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimStatusInd_struct{
    CiDevStatus status;		/**< Device status  \sa CiDevStatus */
} CiDevPrimStatusInd;

/** <paramref name="CI_DEV_PRIM_GET_MANU_ID_REQ">   */
typedef CiEmptyPrim CiDevPrimGetManuIdReq;

/** <paramref name="CI_DEV_PRIM_GET_MANU_ID_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetManuIdCnf_struct{
    CiDevRc     rc;				/**< Result code  \sa CiDevRc */
    CiString    manuStr;			/**< Manufacture ID string. Refer to "Cellular Interface Application Programming Interface", revision i0.6. Max length is 2048. \sa CCI API Ref Manual */
} CiDevPrimGetManuIdCnf;

/** <paramref name="CI_DEV_PRIM_GET_MODEL_ID_REQ">   */
typedef CiEmptyPrim CiDevPrimGetModelIdReq;

/** <paramref name="CI_DEV_PRIM_GET_MODEL_ID_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetModelIdCnf_struct{
    CiDevRc rc;					/**< Result code   \sa CiDevRc */
    CiString    modelStr;			/**< Model ID string.  Refer to "Cellular Interface Application Programming Interface", revision i0.6. Max length is 2048. \sa CCI API Ref Manual  */
} CiDevPrimGetModelIdCnf;

/** <paramref name="CI_DEV_PRIM_GET_REVISION_ID_REQ">   */
typedef CiEmptyPrim CiDevPrimGetRevisionIdReq;

/** <paramref name="CI_DEV_PRIM_GET_REVISION_ID_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetRevisionIdCnf_struct{
    CiDevRc rc;					/**< Result code   \sa CiDevRc */
    CiString    revisionStr;			/**< Revision ID string.  Refer to "Cellular Interface Application Programming Interface", revision i0.6. Max length is 2048. \sa CCI API Ref Manual  */
} CiDevPrimGetRevisionIdCnf;

/** <paramref name="CI_DEV_PRIM_GET_SERIALNUM_ID_REQ">   */
typedef CiEmptyPrim CiDevPrimGetSerialNumIdReq;

/** <paramref name="CI_DEV_PRIM_GET_SERIALNUM_ID_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSerialNumIdCnf_struct{
    CiDevRc   rc;					/**< Result code   \sa CiDevRc */
    CiString  serialNumStr;			/**< Serial number ID string.  Refer to "Cellular Interface Application Programming Interface", revision i0.6. Max length is 2048. \sa CCI API Ref Manual */
} CiDevPrimGetSerialNumIdCnf;

/** <paramref name="CI_DEV_PRIM_SET_FUNC_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetFuncReq_struct{
    CiDevFunc func;			/**< Functionality, related to the power level a phone should draw. \sa CiDevFunc */
    CiBoolean reset;			/**< TRUE - Reset before setting to functionality power level; FALSE - No reset before setting (default) \sa CCI API Ref Manual */
    CiBoolean IsCommFeatureConfig; /**< TRUE - CommFeatureConfig should be changed, next field present */
    CiBitRange CommFeatureConfig; /**< communication feature configuration Enable/Disable like CSD/FAX/etc */
} CiDevPrimSetFuncReq;

/** <paramref name="CI_DEV_PRIM_SET_FUNC_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetFuncCnf_struct{
    CiDevRc rc;			/**< Result code \sa CiDevRc */
} CiDevPrimSetFuncCnf;

/** <paramref name="CI_DEV_PRIM_GET_FUNC_REQ">   */
typedef CiEmptyPrim CiDevPrimGetFuncReq;

/** <paramref name="CI_DEV_PRIM_GET_FUNC_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetFuncCnf_struct{
    CiDevRc   rc;			/**< Result code \sa CiDevRc */
    CiDevFunc func;		/**< Functionality, related to the power level a phone should draw.  \sa CiDevFunc */
    CiBitRange  CommFeatureConfig; /**< communication feature configuration Enable/Disable like CSD/FAX/etc */
} CiDevPrimGetFuncCnf;

/** <paramref name="CI_DEV_PRIM_GET_FUNC_CAP_REQ">   */
typedef CiEmptyPrim CiDevPrimGetFuncCapReq;

/** <paramref name="CI_DEV_PRIM_GET_FUNC_CAP_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetFuncCapCnf_struct{
    CiDevRc     rc;			/**< Result code \sa CiDevRc */
    CiBitRange  bitsFunc;	/**< Supported functionality setting. Refer to "Cellular Interface Application Programming Interface", revision i0.6. \sa CCI API Ref Manual */
    CiBitRange  bitsReset;	/**< Supported reset setting. Refer to "Cellular Interface Application Programming Interface", revision i0.6. \sa CCI API Ref Manual */
} CiDevPrimGetFuncCapCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmPowerClassReq_struct{
    CiDevBand   band;
    CiDevPwCls  pwcls;
} CiDevPrimSetGsmPowerClassReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmPowerClassCnf_struct{
    CiDevRc rc;
} CiDevPrimSetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetGsmPowerClassReq_struct{
    CiDevBand band;
} CiDevPrimGetGsmPowerClassReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetGsmPowerClassCnf_struct{
    CiDevRc     rc;
    CiDevPwCls  curPwCls;
    CiDevPwCls  defPwCls;
} CiDevPrimGetGsmPowerClassCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetGsmPowerClassCapReq_struct{
    CiDevBand band;
} CiDevPrimGetGsmPowerClassCapReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetGsmPowerClassCapCnf_struct{
    CiDevRc     rc;
    CiBitRange  bitsPwCls;
} CiDevPrimGetGsmPowerClassCapCnf;

/** <paramref name="CI_DEV_PRIM_PM_POWER_DOWN_REQ">   */
typedef CiEmptyPrim CiDevPrimPmPowerDownReq;

/** <paramref name="CI_DEV_PRIM_PM_POWER_DOWN_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimPmPowerDownCnf_struct{
    CiDevRc rc;		/**< Result code \sa CiDevRc */
} CiDevPrimPmPowerDownCnf;

/** <paramref name="CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetEngmodeRepOptReq_struct
{
    CiDevEngModeReportOption 	type;       	/**< Report type \sa CiDevEngModeReportOption */
    UINT16                   			interval;   	/**< Report interval (in seconds) for PERIODIC */
} CiDevPrimSetEngmodeRepOptReq;

/** <paramref name="CI_DEV_PRIM_SET_ENGMODE_REPORT_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetEngmodeRepOptCnf_struct
{
    CiDevRc rc;			/**< Result code \sa  CiDevRc */
    UINT8   res1U8[2];
} CiDevPrimSetEngmodeRepOptCnf;
/*modified by taow 20191206 CQ00117373 begin*/
//ICAT EXPORTED ENUM
typedef enum CiDEVENGMODETYPE_TAG{
    CI_DEV_ENGINEER_MODE_NONE= 0,/**< worked with AT+ EEMOPT;step1: AT+ EEMOPT, step2: AT+EEMGINFO?; */
    CI_DEV_ENGINEER_MODE_NORMAL, /**< no used in oneshot mode AT+EEMGNFO? occupy a position*/
    CI_DEV_ENGINEER_MODE_ONESHOT,/**< used in oneshot mode AT+EEMGNFO?  may include Ncell info*/
    CI_DEV_ENGINEER_MODE_ONESHOT_NCELL_REQUIRED,/**< used in oneshot mode AT+EEMGNFO?.must decode system info to get Ncell, but in the end, may still not get NCELL.   this cost 7s*/
    CI_DEV_ENGINEER_MODE_MAX

} _CiDevEngmodeType;


typedef UINT8 CiDevEngmodeType;
/*modified by taow 20191206 CQ00117373 end*/
/** <paramref name="CI_DEV_PRIM_GET_ENGMODE_INFO_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetEngmodeInfoReq_struct
{	
/*added by taow 20181107 CQ00112754 begin*/ 
    CiDevEngmodeType engmodeEnhanceType;       	/**< enhancement request: until all engineer IND msgs from AS were recieved ,  sac send request confirm to AP  */ 
/*added by taow 20181107 CQ00112754 end*/
} CiDevPrimGetEngmodeInfoReq;


/** <paramref name="CI_DEV_PRIM_GET_ENGMODE_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetEngmodeInfoCnf_struct
{
    CiDevRc                		rc;			/**< Result code \sa CiDevRc */
    CiDevEngModeState      	mode;       	/**< Current mode (idle/dedicated) \sa CiDevEngModeState */
    CiDevEngModeNetwork    network;    	/**< Network type (GSM/UMTS) \sa CiDevEngModeNetwork */
} CiDevPrimGetEngmodeInfoCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimEngmodeInfoInd_struct
{
    CiDevEngModeInfo info;
} CiDevPrimEngmodeInfoInd; /*NO USE NOW*/

/** <paramref name="CI_DEV_PRIM_GSM_ENGMODE_INFO_IND">   */
/*Michal Bukai - Modified this struc to support - I-Mate Addition*/
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGsmEngmodeInfoInd_struct
{
  CiDevEngModeState     mode;       		/**< Current Mode (Idle/Dedicated). \sa CiDevEngModeState */
  UINT8                 releaseVersion; /**< 3GPP release versions */       
  UINT8               	res1U8[2];  		/**< (padding) */
  CiDevEngModeGsmData 	info;  			/**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */
} CiDevPrimGsmEngmodeInfoInd;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_SVCCELL_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_struct
{
  CiDevEngModeState   			mode;       		/**< Current mode (idle/dedicated) \sa CiDevEngModeState */
  UINT8               				res1U8[3];  		/**< (padding) */
  CiDevUmtsServingCellInfo 		info;  			/**< Engineering mode 3G (UMTS) serving cell information \sa CiDevUmtsServingCellInfo_struct */
} CiDevPrimUmtsEngmodeScellInfoInd;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_struct
{
    UINT8                     			numIntraFreq; 											/**< Number of Intra-Frequency FDD Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsFddTddNeighborInfo  	intraFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];		/**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */
} CiDevPrimUmtsEngmodeIntraFreqInfoInd;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_struct
{
    UINT8                     			numInterFreq; 											/**< Number of Inter-Frequency FDD Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsFddTddNeighborInfo 	 interFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];		/**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */
} CiDevPrimUmtsEngmodeInterFreqInfoInd;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_struct
{
    UINT8                     			numInterRAT;  											/**< Number of Inter-RAT GSM Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsGsmNeighborInfo 	 interRAT[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ]; 		/**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */
	/*added by taow 20181107 CQ00112754 begin*/
    CiDevEngModeNcellInfoListLte    nCellInfoListLte; /**< LTE neighbor cells info list */
	/*added by taow 20181107 CQ00112754 end*/
} CiDevPrimUmtsEngmodeInterRatInfoInd;


/*Added by Lilei for neighbor cell info report on 01082014, begin*/

/******************************************************************************
 * CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_REQ & CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_CNF
 * Enable/disable the report of neighbor cell info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetEngmodeNcellReportOptionReq_struct{
    CiBoolean                       enable; /**< Enable (1) /disable (0) neighbor cell info report */
    UINT16                          interval; /**< Periodic report interval (in seconds), default 2 seconds */
}CiDevPrimSetEngmodeNcellReportOptionReq;

/** <paramref name="CI_DEV_PRIM_SET_ENGMODE_NCELL_REPORT_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetEngmodeNcellReportOptionCnf_struct{
    CiDevRc                         result; /**< Result code. \sa CiDevRc. */
}CiDevPrimSetEngmodeNcellReportOptionCnf;


/******************************************************************************
 * CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_REQ & CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_CNF
 * Inquiry the neighbor cell info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_REQ">   */
typedef CiEmptyPrim CiDevPrimGetEngmodeNcellInfoReq;

/** <paramref name="CI_DEV_PRIM_GET_ENGMODE_NCELL_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetEngmodeNcellInfoCnf_struct{
    CiDevRc                         result; /**< Result code. \sa CiDevRc */
    CiDevEngModeNetwork             network; /**< Current network type. \sa  CiDevEngModeNetwork */
    CiDevEngModeNcellInfoListGsm    nCellInfoListGsm; /**< GSM neighbor cells info list */
    CiDevEngModeNcellInfoListUmts   nCellInfoListUmts; /**< UMTS neighbor cells info list */
    CiDevEngModeNcellInfoListLte    nCellInfoListLte; /**< LTE neighbor cells info list */
}CiDevPrimGetEngmodeNcellInfoCnf;

/******************************************************************************
 * CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND
 * Indicate/report the neighbor cell info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_ENGMODE_NCELL_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimEngmodeNcellInfoInd_struct{
    CiDevEngModeNetwork             network; /**< Current network type. \sa  CiDevEngModeNetwork */
    CiDevEngModeNcellInfoListGsm    nCellInfoListGsm; /**< GSM neighbor cells info list */
    CiDevEngModeNcellInfoListUmts   nCellInfoListUmts; /**< UMTS neighbor cells info list */
    CiDevEngModeNcellInfoListLte    nCellInfoListLte; /**< LTE neighbor cells info list */
}CiDevPrimEngmodeNcellInfoInd;
/*Added by Lilei for neighbor cell info report on 01082014, end*/

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
//ICAT EXPORTED ENUM
typedef enum CI_DEV_SELF_TEST_RESULT
{
  CI_DEV_SELF_TEST_OK,
  CI_DEV_SELF_TEST_FAILURE,
  CI_DEV_SELF_TEST_INCOMPATIBLE_SW_VERSION,
  CI_DEV_SELF_TEST_ILLEGAL_BATTERY,

  CI_DEV_NUM_SELF_TEST_RESULTS

} _CiDevSelfTestResult;

/*-----------------5/21/2009 3:53PM-----------------
* Not in use
* --------------------------------------------------*/
typedef UINT8 CiDevSelfTestResult;


//ICAT EXPORTED ENUM
typedef enum CI_DEV_RFS_LEVEL
{
  CI_DEV_RFS_USER_LEVEL,
  CI_DEV_RFS_DEEP_LEVEL,

  CI_DEV_NUM_RFS_LEVEL

} _CiDevRfsLevel;

typedef UINT8 CiDevRfsLevel;
#if !defined (ON_PC)
#define AT_CMD_MAX_AGPS_MSG_SIZE			480
#define CI_DEV_MAX_APGS_MSG_SIZE    		1500 //500 /*Modified by Lilei for LTE positioning support*/
#else
#define CI_DEV_MAX_APGS_MSG_SIZE    		375
#define AT_CMD_MAX_AGPS_MSG_SIZE			375
#endif
#define CI_DEV_MAX_NUM_NWDL_MSG_IND    	4
#define CI_DEV_MAX_ADD_INFO_LEN    	4


/** \brief  RRC state values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiDEVLPRRCSTATE_TAG
{
	CI_DEV_LP_RRC_STATE_CELL_DCH = 0,  /**< RRC state CELL DCH */
	CI_DEV_LP_RRC_STATE_CELL_FACH,     /**< RRC state CELL FACH */
	CI_DEV_LP_RRC_STATE_CELL_PCH,      /**< RRC state CELL PCH */
	CI_DEV_LP_RRC_STATE_URA_PCH,       /**< RRC state URA PCH */
	CI_DEV_LP_RRC_STATE_IDLE           /**< RRC state idle */
} _CiDevLpRRCState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief RRC state
 * \sa CiDEVLPRRCSTATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLpRRCState;
/**@}*/

/** \brief  Location position (LP) radio bearer type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVLPBEARERTYPE_TAG
{
	CI_DEV_LP_RRC = 0, 	/**<  RRC */
	CI_DEV_LP_RRLP,     /**< Radio resource location protocol */
	CI_DEV_LP_RRC_SIB15,  /**< RRC SIB15 */
	CI_DEV_LP_SS_AGPS_ASSIST_REQ,   /**< Supplementary service AGPS assist request */
	CI_DEV_LP_LPP,	/**< LPP container */
	CI_DEV_LP_LCS, /**< LCS container */
	CI_DEV_LP_RRC_UL_EXT, /**<RRC with uplink extensions support, added by lalon for CQ00094785 begin */
	CI_DEV_LP_NUM_OF_BEARER_TYPE
} _CiDevLpBearerType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Radio bearer type
 * \sa CIDEVLPBEARERTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLpBearerType;
/**@}*/

/** \brief  Location position (LP) session type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiDEVLPSESSIONTYPE_TAG
{
	CI_DEV_LP_NO_EMERGENCY = 0x0, /**< Not an emergency call */
	CI_DEV_LP_EMERGENCY           /**< An emergency call */
}_CiDevLpSessionType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Emergency call indication
 * \sa CiDEVLPSESSIONTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLpSessionType;
/**@}*/

//ICAT EXPORTED ENUM
typedef enum CiDevNetworkType_Tag
{
	CI_DEV_NETWORK_TYPE_GERAN = 0x0,
	CI_DEV_NETWORK_TYPE_UTRAN,
	CI_DEV_NETWORK_TYPE_EUTRAN,
	
	CI_DEV_NUM_NETWORK_TYPES
}_CiDevNetworkType;

typedef UINT8 CiDevNetworkType;

/** <paramref name="CI_DEV_PRIM_LP_NWDL_MSG_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpNwdlMsgInd_struct {
	CiDevLpBearerType 				BearerType;								/**< Bearer type information \sa CiDevLpBearerType */
	UINT8							msg_data[CI_DEV_MAX_APGS_MSG_SIZE];	/**< Encoded RRLP/RRC data */
	UINT32 							msg_size;								/**< Size of data, include all fragments */
	CiDevLpSessionType 				sessionType;								/**< Session type information  \sa CiDevLpSessionType */
	CiDevLpRRCState 				RrcState;								/**< RRC state  \sa CiDevLpRRCState */
	UINT8							count; 									/**< Ordinal number of the message/fragment */
	UINT8							additional_info_len;			/**< Length of the additional information. If length is zero, than the additional information is not present.*/
	UINT8							additional_info[CI_DEV_MAX_ADD_INFO_LEN];				/**< Contains the value of the additional information element. Used for Routing Identifier (24.171)*/
} CiDevPrimLpNwdlMsgInd;

/** <paramref name="CI_DEV_PRIM_LP_NWUL_MSG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpNwulMsgReq_struct{
	UINT8							msg_data[AT_CMD_MAX_AGPS_MSG_SIZE];			/**< OTA message */
	UINT32							msg_data_len;			                /**< Size of data, include all fragments */
	UINT8							count;									/**< Ordinal number of the message/fragment */
	CiDevLpBearerType				bearer_type;								/**< Radio bearer type \sa CiDevLpBearerType */
	CiBoolean						isFinalResponse;						/**< Indication that this message is the last message in the AGPS session \sa CCI API Ref Manual */
	UINT8							additional_info_len;			/**< Length of the additional information. If length is zero, than the additional information is not present.*/
	UINT8							additional_info[CI_DEV_MAX_ADD_INFO_LEN];				/**< Contains the value of the additional information element. Used for Routing Identifier (24.171)*/
}CiDevPrimLpNwulMsgReq;

/** <paramref name="CI_DEV_PRIM_LP_NWUL_MSG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpNwulMsgCnf_struct{
	CiDevRc	       result;		/**< Result code \sa CiDevRc. */
       UINT8  		res1U8[2];    	/**< (padding) */
}CiDevPrimLpNwulMsgCnf;

/*============= ECID/OTDOA measurement, begin ====================*/
#define CI_DEV_MAX_NUM_GSM_NMR_CELLS 32
#define CI_DEV_MAX_NUM_UTRA_RESULT_CELLS 32
#define CI_DEV_MAX_NUM_UTRA_RESULT_FREQS 3
#define CI_DEV_MAX_SIZE_EUTRA_MEAS_RESULT_LIST 32

//ICAT EXPORTED STRUCT
typedef struct CiDevNmrCellResult_struct
{
	UINT16			arfcn;
	UINT8			bsic;
	UINT8			rxLev;
} CiDevNmrCellResult;

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidInfoGsm_struct
{
	UINT16					mcc;
	UINT16					mnc;
	UINT16					lac;
	UINT16					ci;
	UINT8					numOfCells;
	CiDevNmrCellResult		nmrCellResult[CI_DEV_MAX_NUM_GSM_NMR_CELLS]; /**< Network measurement result */
	CiBoolean				taPresent;
	UINT8					timingAdv;
} CiDevEcidInfoGsm;

//ICAT EXPORTED STRUCT
typedef struct CiDevCellResult_struct
{
	CiBoolean				ucidPresent;
	UINT32					ucid; /**< Cell identiy */
    UINT16                  psc_cellParameterId; /**< Primary scrambling code for FDD or Cell parameter id for TDD */
	UINT8					cpichRscp; /**< FDD only */
	UINT8					cpichEcN0; /**< FDD only */
	CiBoolean				pathLossPresent;
	UINT16					pathLoss;
} CiDevCellResult;

//ICAT EXPORTED STRUCT
typedef struct CiDevCellResultList_struct
{
	UINT8					numOfCells;
	CiDevCellResult			cellResult[CI_DEV_MAX_NUM_UTRA_RESULT_CELLS];
} CiDevCellResultList;

//ICAT EXPORTED STRUCT
typedef struct CiDevUtraMeasResult_struct
{
	UINT16					uarfcnDl;
	UINT16					rssi;
	CiDevCellResultList		cellResultList;
} CiDevUtraMeasResult;

//ICAT EXPORTED STRUCT
typedef struct CiDevUtraMeasResultList_struct
{
	UINT8					numUtraReportedFreqs;
	CiDevUtraMeasResult		utraMeasResult[CI_DEV_MAX_NUM_UTRA_RESULT_FREQS];
} CiDevUtraMeasResultList;

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidInfoUtra_struct
{
	UINT16						mcc;
	UINT16						mnc;
	UINT32						ucid;
	UINT16						uarfcnDl;
	UINT16						uarfcnUl;
	UINT16						psc;
	CiBoolean					MeasResultPresent;
	CiDevUtraMeasResultList		measResult;
} CiDevEcidInfoUtra;

//ICAT EXPORTED STRUCT
typedef struct CiDevCellGlobalIdEutra_struct
{
	CiBoolean	mccPresent;
	UINT16		mcc;
	UINT16		mnc;
	UINT32		cellId;
} CiDevCellGlobalIdEutra;

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidMeasuredResultsElement_struct
{
	UINT16					physCellId;
	CiBoolean				cgiPresent;
	CiDevCellGlobalIdEutra	cellGlobalId;
	UINT32					arfcnEutra;
	CiBoolean				sfnPresent;
	UINT16					systemFrameNumber;
	CiBoolean 				rsrpPresent;
	UINT8 					rsrp;
	CiBoolean 				rsrqPresent;
	UINT8 					rsrq;
	CiBoolean 				rxTxTimeDiffPresent;
	UINT16 					rxTxTimeDiff; /**< UE RX-TX time difference measurement. Only valid for measurements of the primary cell */
	CiBoolean 				taPresent;
	UINT16 					timingAdvance;
	CiBoolean 				tacPresent;
	UINT16 					trackingAreaCode;
} CiDevEcidMeasuredResultsElement; /*< As per 3GPP TS36.355 6.5.3.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidSignalMeasInfo_struct
{
	CiBoolean							primaryCellMeasuredResultsPresent;
	CiDevEcidMeasuredResultsElement		primaryCellMeasuredResults; /**< Measurements for the primary cell. It's omitted when only primary cell measurements are reported,
	                                                                                                                             in which case the measurements of the primary cell are reported in the measuredResultsList */
	UINT8								measuredResultsListLength;
	CiDevEcidMeasuredResultsElement		measuredResultsList[CI_DEV_MAX_SIZE_EUTRA_MEAS_RESULT_LIST];
} CiDevEcidSignalMeasInfo; /*< As per 3GPP TS36.355 6.5.3.2 */

//ICAT EXPORTED ENUM
typedef enum ECID_ERROR_CAUSES_ENUM
{
	CI_DEV_ECID_ERROR_CAUSE_UNDEFINED = 0x00,
	CI_DEV_ECID_ERROR_CAUSE_REQUESTED_MEASUREMENT_NOT_AVAILABLE,
	CI_DEV_ECID_ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE,
	CI_DEV_ECID_ERROR_CAUSE_RESERVED = 0xFF
}_EcidErrorCauses; /*< As per 3GPP TS36.355 6.5.3.6 */
typedef UINT8 EcidErrorCauses;

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidError_struct
{
	EcidErrorCauses			ecidErrorCauses;
	CiBoolean				rsrpMeasurementNotPossible; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */
	CiBoolean				rsrqMeasurementNotPossible; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */
	CiBoolean				ueRxTxMeasurementNotPossible; /**< Only for ERROR_CAUSE_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE */
} CiDevEcidError; /*< As per 3GPP TS36.355 6.5.3.6 */

//ICAT EXPORTED STRUCT
typedef struct CiDevEcidInfoEutra_struct
{
	CiBoolean					 ecidSignalMeasInfoPresent;
	CiDevEcidSignalMeasInfo      ecidSignalMeasInfo;
	CiBoolean					 ecidErrorPresent;
	CiDevEcidError				 ecidError;
} CiDevEcidInfoEutra; /*< As per 3GPP TS36.355 6.5.3.1 */

//ICAT EXPORTED UNION
typedef union CiDevEcidInfo_union
{
	CiDevEcidInfoGsm	gsmInfo;
	CiDevEcidInfoUtra	utraInfo;
	CiDevEcidInfoEutra	eutraInfo;
}CiDevEcidInfo;

/** <paramref name="CI_DEV_PRIM_LP_ECID_MEAS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpEcidMeasReq_struct
{
    UINT8               ecidMeasRequested; /**< bit 0: rsrpReq; bit1: rsrqReq; bit2: ueRxTxTimeDiffReq; bit3-bit7: reserved. */
}CiDevPrimLpEcidMeasReq; /*< As per 3GPP TS36.355 6.5.3.3 */

//typedef CiEmptyPrim CiDevPrimLpEcidMeasReq;

/** <paramref name="CI_DEV_PRIM_LP_ECID_MEAS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpEcidMeasCnf_struct
{
	CiDevRc		        rc;		/**< Result code \sa CiDevRc. */
	CiDevNetworkType	networkType; /**< EUTRAN, UTRAN, or GERAN */
	CiDevEcidInfo       info;
}CiDevPrimLpEcidMeasCnf;


/*Added by Lilei for LTE positioning support, begin*/
#define CI_DEV_MAX_NUM_OTDOA_FREQ_LAYERS 3
#define CI_DEV_MAX_NUM_OTDOA_NCELLS 24

//ICAT EXPORTED STRUCT
typedef struct CiDevEcgi_struct
{
    CiDevLtePlmnIdentity    plmnIdentity;
	UINT32			        cellIdentity; /* 0 to 268435455 */
} CiDevEcgi;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrsInfo_struct
{
    UINT8                      prsBandwidth; /**< Specified in number of resource blocks. Value range: 6, 15, 25, 50, 75, 100 */
	UINT16                     prsConfigIndex; /**< Value range: 0 - 4095 */
	UINT8                      numDLFrames; /**< The number of consecutive DL subframes. Value range: 1, 2, 4, 6 */
	CiBoolean                  prsMutingInfoR9Present;
	UINT8                      prsMutingInfoR9LenInBit; /**< PRS muting sequence length in bits. Value range: 2, 4, 8, 16 */
	UINT16                     prsMutingInfoR9; /**< PRS muting sequence */
}CiDevPrsInfo; /*< As per 3GPP TS36.355 6.5.1.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaReferenceCellInfo_struct
{
    UINT16                     physCellId; /**< Physical cell identity of the assistance data reference cell. Value range: 0-503 */
    CiBoolean                  cgiPresent;
    CiDevEcgi                  cellGlobalId; /**< ECGI of the assistance data reference cell. */
    CiBoolean                  earfcnRefPresent; /**< TRUE if not same as primary cell, otherwise FALSE. */
    UINT32                     earfcnRef; /**< EARFCN of the assistance data reference cell. */
    CiBoolean                  antennaPortConfigPresent; /**< TRUE if not same as primary cell, otherwise FALSE. */
    UINT8                      antennaPortConfig; /**< The number of antenna ports for cell specific reference signals (CRS). 0: 1 or 2 port(s); 1: 4 ports */
    UINT8                      cpLength; /**< Cyclic prefix length of PRS if prsInfo is present, otherwise of CRS. 0: normal; 1: extended  */
    CiBoolean                  prsInfoPresent;
    CiDevPrsInfo               prsInfo; /**< PRS configuration of the assistance data reference cell. */
}CiDevOtdoaReferenceCellInfo; /*< As per 3GPP TS36.355 6.5.1.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaNeighbouCellInfoElement_struct
{
    UINT16                     physCellId; /**< Physical cell identity of the neighbour cell. Value range: 0-503 */
    CiBoolean                  cgiPresent;
    CiDevEcgi                  cellGlobalId; /**< ECGI of the neighbour cell. */
    CiBoolean                  earfcnRefPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    UINT32                     earfcnNbr; /**< EARFCN of the neighbour cell. */
    CiBoolean                  cpLengthPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    UINT8                      cpLength; /**< Cyclic prefix length of PRS if prsInfo is present, otherwise of CRS. 0: normal; 1: extended  */
    CiBoolean                  prsInfoPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    CiDevPrsInfo               prsInfo; /**< PRS configuration */
    CiBoolean                  antennaPortConfigPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    UINT8                      antennaPortConfig; /**< The number of antenna ports for cell specific reference signals (CRS). 0: 1 or 2 port(s); 1: 4 ports */
    CiBoolean                  slotNumberOffsetPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    UINT8                      slotNumberOffset; /**< Slot number offset at the transmitter between this cell and the assistance data reference cell. Value range: 0-19 */
    CiBoolean                  prsSubframeOffsetPresent;
    UINT16                     prsSubframeOffset; /**< Value range: 0-1279 */
    UINT16                     expectedRSTD; /**< Value range: 0-16383 */
    UINT16                     expectedRSTDUncertainty; /**< Value range: 0-1023 */
}CiDevOtdoaNeighbouCellInfoElement; /*< As per 3GPP TS36.355 6.5.1.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaNeighbourFreqInfo_struct
{
    UINT8                                  otdoaNeighbouCellInfoListLength;
    CiDevOtdoaNeighbouCellInfoElement      otdoaNeighbouCellInfoList[CI_DEV_MAX_NUM_OTDOA_NCELLS];
}CiDevOtdoaNeighbourFreqInfo; /*< As per 3GPP TS36.355 6.5.1.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaNeighbourCellInfoList_struct
{
    UINT8                                  otdoaNeighbourFreqInfoNum;
	//CiDevOtdoaNeighbourFreqInfo            otdoaNeighbourFreqInfo[CI_DEV_MAX_NUM_OTDOA_FREQ_LAYERS];
	UINT8                                  otdoaNeighbourFreqCellNum[CI_DEV_MAX_NUM_OTDOA_FREQ_LAYERS]; //Each element indicates how many cells belong to each frequency layer
	UINT8                                  otdoaNeighbouCellInfoListLength;
    CiDevOtdoaNeighbouCellInfoElement      otdoaNeighbouCellInfoList[CI_DEV_MAX_NUM_OTDOA_NCELLS]; //Totally a maximum of 24 cells
}CiDevOtdoaNeighbourCellInfoList; /*< As per 3GPP TS36.355 6.5.1.2 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaAssistanceData_struct
{
    CiBoolean                           otdoaReferenceCellInfoPresent;
    CiDevOtdoaReferenceCellInfo         otdoaReferenceCellInfo;
    CiBoolean                           otdoaNeighbourCellInfoListPresent;
    CiDevOtdoaNeighbourCellInfoList     otdoaNeighbourCellInfoList;
}CiDevOtdoaAssistanceData;

/** <paramref name="CI_DEV_PRIM_LP_OTDOA_MEAS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpOtdoaMeasReq_struct
{
    CiDevOtdoaAssistanceData  otdoaAssistanceData;
}CiDevPrimLpOtdoaMeasReq;
//typedef CiEmptyPrim CiDevPrimLpOtdoaMeasReq;

/** <paramref name="CI_DEV_PRIM_LP_OTDOA_MEAS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpOtdoaMeasCnf_struct
{
    CiDevRc             rc;			 /**< Result code \sa CiDevRc. */
}CiDevPrimLpOtdoaMeasCnf;

/** <paramref name="CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_REQ">   */
typedef CiEmptyPrim CiDevPrimLpOtdoaMeasAbortReq;

/** <paramref name="CI_DEV_PRIM_LP_OTDOA_MEAS_ABORT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpOtdoaMeasAbortCnf_struct
{
     CiDevRc  rc;
}CiDevPrimLpOtdoaMeasAbortCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaMeasQuality_struct
{
    UINT8                      errorResolution; /**< Resolution R. '00': 5 meters; '01': 10 meters; '10': 20 meters; '11': 30 meters */
	UINT8                      errorValue; /**< Best estimate of the uncertainty of measurement. 
	                                                                               '00000': 0     - (R*1-1) meters;
	                                                                               '00001': R*1 - (R*2-1) meters;
	                                                                               '00010': R*2 - (R*3-1) meters;
	                                                                               ...
	                                                                               '11111': R*31 meters or more */
	CiBoolean                  errorNumSamplesPresent;
	UINT8                      errorNumSamples; /**< Measurements sample size.
	                                                                                         '000': Not the baseline metric (default value);
	                                                                                         '001': 5-9;
	                                                                                         '010': 10-14;
	                                                                                         '011': 15-24;
	                                                                                         '100': 25-34;
	                                                                                         '101': 53-44;
	                                                                                         '110': 45-54;
	                                                                                         '111': 55 or more */
}CiDevOtdoaMeasQuality; /*< As per 3GPP TS36.355 6.5.1.5 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaNeighbourMeasurementElement_struct
{
    UINT16                     physCellIdNeighbour; /**< Physical cell identity of the neighbour cell. Value range: 0-503 */
    CiBoolean                  cgiNeighbourPresent;
    CiDevEcgi                  cellGlobalIdNeighbour; /**< ECGI of the neighbour cell. */
    CiBoolean                  earfcnNeighbourPresent; /**< TRUE if not same as RSTD reference cell, otherwise FALSE. */
    UINT32                     earfcnNeighbour; /**< EARFCN of the neighbour cell. */
    UINT16                     rstd; /**< Relative timing difference between this eighbour cell and the RSTD reference cell. Value range: 0-12711 */
    CiDevOtdoaMeasQuality      rstdQuality; /**< Best estimate of the quality of the measured rstd. */
}CiDevOtdoaNeighbourMeasurementElement; /*< As per 3GPP TS36.355 6.5.1.5 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaNeighbourMeasurementList_struct
{
    UINT8                                    otdoaNeighbourMeasurementListLength;
    CiDevOtdoaNeighbourMeasurementElement    otdoaNeighbourMeasurementList[CI_DEV_MAX_NUM_OTDOA_NCELLS];
}CiDevOtdoaNeighbourMeasurementList; /*< As per 3GPP TS36.355 6.5.1.5 */

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaSignalMeasInfo_struct
{
    UINT16                     systemFrameNumber; /**< SFN of the RSTD reference cell. */
    UINT16                     physCellIdRef; /**< Physical cell identity of the RSTD reference cell. Value range: 0-503 */
    CiBoolean                  cgiRefPresent;
    CiDevEcgi                  cellGlobalIdRef; /**< ECGI of the RSTD reference cell. */
    CiBoolean                  earfcnRefPresent; /**< TRUE if not same as assistance data reference cell, otherwise FALSE. */
    UINT32                     earfcnRef; /**< EARFCN of the RSTD reference cell. */
    CiBoolean                  referenceQualityPresent;
    CiDevOtdoaMeasQuality      referenceQuality; /**< Best estimate of the quality of TOA measurement from the RSTD reference cell. */
    CiDevOtdoaNeighbourMeasurementList   neighbourMeasurementList;
}CiDevOtdoaSignalMeasInfo; /*< As per 3GPP TS36.355 6.5.1.5 */

//ICAT EXPORTED ENUM
typedef enum OTDOA_ERROR_CAUSES_ENUM
{
    CI_DEV_OTDOA_ERROR_CAUSE_UNDEFINED = 0x00,
    CI_DEV_OTDOA_ERROR_CAUSE_ASSISTANCE_DATA_MISSING,
    CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_REFERENCE_CELL,
    CI_DEV_OTDOA_ERROR_CAUSE_UNABLE_TO_MEASURE_ANY_NEIGHBOUR_CELL,
    CI_DEV_OTDOA_ERROR_CAUSE_ATTEMPTED_BUT_UNABLE_TO_MEASURE_SOME_NEIGHBOUR_CELLS,
    CI_DEV_OTDOA_ERROR_CAUSE_RESERVED = 0xFF
}_OtdoaErrorCauses; /*< As per 3GPP TS36.355 6.5.1.9 */
typedef UINT8 OtdoaErrorCauses;

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaError_struct
{
    OtdoaErrorCauses     otdoaErrorCauses;
}CiDevOtdoaError;

//ICAT EXPORTED STRUCT
typedef struct CiDevOtdoaInfoEutra_struct
{
    CiBoolean                    otdoaSignalMeasInfoPresent;
    CiDevOtdoaSignalMeasInfo     otdoaSignalMeasInfo;
    CiBoolean                    otdoaErrorPresent;
    CiDevOtdoaError              otdoaError;
}CiDevOtdoaInfoEutra; /*< As per 3GPP TS36.355 6.5.1.4 */

//ICAT EXPORTED UNION
typedef union CiDevOtdoaInfo_union
{
    //CiDevOtdoaInfoUtra       utraInfo; //TBD
    CiDevOtdoaInfoEutra      eutraInfo;
}CiDevOtdoaInfo;

/** <paramref name="CI_DEV_PRIM_LP_OTDOA_MEAS_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpOtdoaMeasInd_struct
{
    CiDevNetworkType    networkType; /**< EUTRAN, UTRAN, or GERAN */
    CiDevOtdoaInfo      info;
}CiDevPrimLpOtdoaMeasInd;
/*============= ECID/OTDOA measurement, end ====================*/

/*============= Logging measurement feature support, begin ==============*/
#define CI_DEV_MAX_LOCATION_COORDINATE_SIZE 20
#define CI_DEV_MAX_HORIZONTAL_VELOCITY_SIZE 4
#define CI_DEV_MAX_GNSS_TOD_MSEC_SIZE 4

//ICAT EXPORTED ENUM
typedef enum CIDEV_LOCATION_COORDINATE_TYPE_ENUM
{
    CiDevLocCoordType_EllipsoidPoint = 0x00,
	CiDevLocCoordType_EllipsoidPointWithAltitude,
    CiDevLocCoordType_EllipsoidPointWithUncertaintyCircle,
    CiDevLocCoordType_EllipsoidPointWithUncertaintyEllipse,
    CiDevLocCoordType_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid,
    CiDevLocCoordType_EllipsoidArc,
    CiDevLocCoordType_Polygon,
    CiDevLocCoordType_Reserved = 0xFF
}_CiDevLocationCoordinateType; /*< As per 3GPP TS36.355 6.4.1 */

typedef UINT8 CiDevLocationCoordinateType;

//ICAT EXPORTED STRUCT
typedef struct CiDevLocationInfo_struct
{
    CiDevLocationCoordinateType    locationCoordinateType;
    UINT8               locationCoordinateLength;
    UINT8               locationCoordinate[CI_DEV_MAX_LOCATION_COORDINATE_SIZE];
    CiBoolean           horizontalVelocityPresent;
    UINT8               horizontalVelocityLength;
    UINT8               horizontalVelocity[CI_DEV_MAX_HORIZONTAL_VELOCITY_SIZE];
    CiBoolean           gnssTODMsecPresent;
    UINT8               gnssTODMsecLength;
    UINT8               gnssTODMsec[CI_DEV_MAX_GNSS_TOD_MSEC_SIZE];
}CiDevLocationInfo;

/** <paramref name="CI_DEV_PRIM_RETRIEVE_LOCATION_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimRetrieveLocationInd_struct
{
	UINT16		        seqNum; /*< sequence number */ 
}CiDevPrimRetrieveLocationInd;

/** <paramref name="CI_DEV_PRIM_RETRIEVE_LOCATION_RSP">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimRetrieveLocationRsp_struct{
	UINT16				seqNum; /*< sequence number */
	CiBoolean			locationPresent;
	CiDevLocationInfo	location;
}CiDevPrimRetrieveLocationRsp;
/*============= Logging measurement feature support, end ================*/

/*Added by Lilei for LTE positioning support, end*/

/*Added by arthurr for FRAT feature begin*/
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetIgnitionStateReq_struct{
    CiBoolean            ignitionOn;                                           /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */
    CiBoolean            updateSlowFratTimer;                   /**< TRUE - enables update of slowFratTimer . FALSE otherwise. \sa CCI API Ref Manual */
    UINT16               slowFratTimer;                                  /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */
    CiBoolean            updateFastFratTimer;                      /**< TRUE - enables update of fastFratTimer. FALSE otherwise. \sa CCI API Ref Manual */
    UINT16               fastFratTimer;                                   /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received  \sa CCI API Ref Manual */
} CiDevPrimSetIgnitionStateReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetIgnitionStateCnf_struct{
    CiDevRc              rc;                              /**< Result code. \sa CiDevRc. */
} CiDevPrimSetIgnitionStateCnf;


typedef CiEmptyPrim CiDevPrimGetIgnitionStateReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetIgnitionStateCnf_struct{
	CiDevRc              rc; 
    CiBoolean            ignitionOn;                                           /**< TRUE - ignition is on . FALSE otherwise \sa CCI API Ref Manual */
    UINT16               slowFratTimer;                                  /**< SLOW FRAT Timer defines the periodicity of the HPPLMN searches when the SLOW FRAT trigger has been received \sa CCI API Ref Manual */
    UINT16               fastFratTimer;                                   /**< FAST FRAT Timer defines the periodicity of the HPPLMN searches when the FAST FRAT trigger has been received  \sa CCI API Ref Manual */
} CiDevPrimGetIgnitionStateCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDevAreaInfoGsm_struct
{
	UINT16		mcc;
	UINT16		mnc;
	UINT16		lac;
	UINT16		ci;
} CiDevAreaInfoGsm;

//ICAT EXPORTED STRUCT
typedef struct CiDevAreaInfoUtra_struct
{
	UINT16		mcc;
	UINT16		mnc;
	UINT16		lac;
	UINT32		ucid;
} CiDevAreaInfoUtra;

//ICAT EXPORTED STRUCT
typedef struct CiDevAreaInfoEutra_struct
{
	UINT16					arfcnEutra;
	UINT16					physCellId;
	CiBoolean				cgiPresent;
	CiDevCellGlobalIdEutra	cellGlobalId;
} CiDevAreaInfoEutra;

//ICAT EXPORTED UNION
typedef union CiDevAreaInfo_union{
	CiDevAreaInfoGsm	gsmInfo;
	CiDevAreaInfoUtra	utraInfo;
	CiDevAreaInfoEutra	eutraInfo;
}CiDevAreaInfo;

/** <paramref name="CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLpUeAreaInfoIndReq_struct{
	CiBoolean		enableUeAreaInfoInd;
}CiDevPrimSetLpUeAreaInfoIndReq;

/** <paramref name="CI_DEV_PRIM_SET_LP_UE_AREA_INFO_IND_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLpUeAreaInfoIndCnf_struct{
	CiDevRc		rc;		/**< Result code \sa CiDevRc. */
}CiDevPrimSetLpUeAreaInfoIndCnf;

/** <paramref name="CI_DEV_PRIM_LP_UE_AREA_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpUeAreaInfoInd_struct{
	CiDevNetworkType	networkType;
	CiDevAreaInfo info;
}CiDevPrimLpUeAreaInfoInd;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_LP_RRC_STATE_IND">   */
typedef struct CiDevPrimLpRrcStateInd_struct{
	CiDevLpBearerType 	bearer_type;		/**< Radio bearer type \sa CiDevLpBearerType */
	CiDevLpRRCState 		rrc_state;		/**< Current RRC state \sa CiDevLpRRCState */
       UINT8  				res1U8[2];    		/**< (padding) */
}CiDevPrimLpRrcStateInd;

/** <paramref name="CI_DEV_PRIM_LP_MEAS_TERMINATE_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpMeasTerminateInd_struct{
	CiDevLpBearerType 	bearer_type;		/**< Radio bearer type \sa CiDevLpBearerType */
       UINT8  				res1U8[3];    		/**< (padding) */
}CiDevPrimLpMeasTerminateInd;

/** <paramref name="CI_DEV_PRIM_LP_RESET_STORED_UE_POS_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLpResetStoreUePosInd_struct{
	CiDevLpBearerType 	bearer_type;		/**< Radio bearer type \sa CiDevLpBearerType */
       UINT8  				res1U8[3];    		/**< (padding) */
}CiDevPrimLpResetStoreUePosInd;


/* ********************************************************************************************* */
/* primitives definitions */
/* ********************************************************************************************* */

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_DO_SELF_TEST_REQ">   */
typedef struct CiDevPrimDoSelfTestReq_struct {

  UINT32    appVersion;		/* Not in use */

} CiDevPrimDoSelfTestReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_DO_SELF_TEST_CNF">   */
typedef struct CiDevPrimDoSelfTestCnf_struct {

	CiDevRc	              	result;		/* Result code  \sa CiDevRc */
	CiDevSelfTestResult   	testResult;	/* Test result   \sa CiDevSelfTestResult */

} CiDevPrimDoSelfTestCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_DO_SELF_TEST_IND">   */
typedef struct CiCustPrimPerformSelfTestInd_struct {

	CiDevSelfTestResult    testResult;	/* Test result \sa CiDevSelfTestResult */

} CiDevPrimDoSelfTestInd;

/** <paramref name="CI_DEV_PRIM_SET_RFS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRfsReq_struct {

  CiDevRfsLevel        level;		/**< Not in use */

} CiDevPrimSetRfsReq;

/** <paramref name="CI_DEV_PRIM_SET_RFS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRfsCnf_struct {

	CiDevRc	              result;		/**< Result code \sa CiDevRc. */

} CiDevPrimSetRfsCnf;

/** <paramref name="CI_DEV_PRIM_GET_RFS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetRfsReq_struct {

  CiDevRfsLevel        level;		/**< Not in use */

} CiDevPrimGetRfsReq;

/** <paramref name="CI_DEV_PRIM_GET_RFS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetRfsCnf_struct {

	CiDevRc	              result;		/**< Result code \sa CiDevRc. */

} CiDevPrimGetRfsCnf;

/*Michal Bukai - Silent Reset support - START*/
/** <paramref name="CI_DEV_PRIM_COMM_ASSERT_REQ">   */
typedef CiEmptyPrim CiDevPrimCommAssertReq;
/*Michal Bukai - Silent Reset support - END*/

/* Modified by Lilei 20131009, begin */
/** \brief  AT*BAND mode values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVNWMODESET_TAG{
    CI_DEV_NW_GSM_MODE  = 0,	/**< GSM */
    CI_DEV_NW_UMTS_MODE,    	/**< UMTS */
    
    CI_DEV_NW_DUAL_GSM_UMTS_MODE,   	/**< GSM_UMTS, auto */
    CI_DEV_NW_DUAL_GSM_UMTS_MODE_GSM,	/**< GSM_UMTS, GSM preferred */
    CI_DEV_NW_DUAL_GSM_UMTS_MODE_UMTS,	/**< GSM_UMTS, UMTS preferred */
    
    CI_DEV_NW_LTE_MODE,			/**< LTE */
    
    CI_DEV_NW_DUAL_GSM_LTE_MODE,		/**< GSM_LTE, auto, single link */
	CI_DEV_NW_DUAL_GSM_LTE_MODE_GSM,	/**< GSM_LTE, GSM preferred, single link */
	CI_DEV_NW_DUAL_GSM_LTE_MODE_LTE,	/**< GSM_LTE, LTE preferred, single link */
	
	CI_DEV_NW_DUAL_UMTS_LTE_MODE,		/**< UMTS_LTE, auto, single link */
    CI_DEV_NW_DUAL_UMTS_LTE_MODE_UMTS,	/**< UMTS_LTE, UMTS preferred, single link */
    CI_DEV_NW_DUAL_UMTS_LTE_MODE_LTE,	/**< UMTS_LTE, LTE preferred, single link */
    
    CI_DEV_NW_TRIP_MODE,		/**< GSM_UMTS_LTE, auto, single link */
    CI_DEV_NW_TRIP_MODE_GSM,	/**< GSM_UMTS_LTE, GSM preferred, single link */
    CI_DEV_NW_TRIP_MODE_UMTS,	/**< GSM_UMTS_LTE, UMTS preferred, single link */
    CI_DEV_NW_TRIP_MODE_LTE,	/**< GSM_UMTS_LTE, LTE preferred, single link */

    CI_DEV_NW_GSM_LTE_MODE_DUALLINK,	/**< GSM_LTE, dual link */
    CI_DEV_NW_UMTS_LTE_MODE_DUALLINK,	/**< UMTS_LTE, dual link */
    CI_DEV_NW_TRIP_MODE_DUALLINK,		/**< GSM_UMTS_LTE, dual link */

    CI_DEV_NW_MODE_NOT_CHANGE = 0xF0,
    
    CI_DEV_NUM_NW_MODES_SET

} _CiDevNwModeSet;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief AT*BAND mode set
 * \sa CIDEVNWMODESET_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevNwModeSet;
/**@}*/


/*Michal Bukai *BAND support - START*/
/** \brief  Network mode values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVNWMODES_TAG{
    CI_DEV_NW_GSM  = 0,		/**< GSM */
    CI_DEV_NW_UMTS ,    	/**< UMTS */    
    CI_DEV_NW_GSM_UMTS, 	/**< GSM_UMTS */    
    CI_DEV_NW_LTE,			/**< LTE */    
    CI_DEV_NW_GSM_LTE,		/**< GSM_LTE */
    CI_DEV_NW_UMTS_LTE,		/**< UMTS_LTE */    
    CI_DEV_NW_GSM_UMTS_LTE,	/**< GSM_UMTS_LTE */
     
    CI_DEV_NUM_NW_MODES

} _CiDevNetworkMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network mode is used to define the RAT mode of the ME
 * \sa CIDEVNWMODES_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevNetworkMode;
/**@}*/
/* Modified by Lilei 20131009, end */


/** \brief  GSM band options values - GSM frequency bands are defined in 3GPP TS 45.005 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVGSMBANDMODES_TAG{
    CI_DEV_PGSM_900 = 0,  	/**< Standard or primary GSM 900 band */
    CI_DEV_DCS_GSM_1800,    /**< DCS 1800 band */
    CI_DEV_PCS_GSM_1900,    /**< PCS 1900 band */
    CI_DEV_EGSM_900,        /**< Extended GSM 900 band */
    CI_DEV_GSM_450,         /**< GSM 450 band */
    CI_DEV_GSM_480,         /**< GSM 480 band */
    CI_DEV_GSM_850,         /**< GSM 850 band */

    CI_DEV_NUM_GSM_BAND
} _CiDevGSMBandMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GSM band options
 * \sa CIDEVGSMBANDMODES_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevGSMBandMode;
/**@}*/


/** \brief UMTS band option values -  UMTS frequency bands are defined in 3GPP TS 25.101 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVUMTSBANDMODES_TAG{
    CI_DEV_UMTS_BAND_1  = 0,     /**< UMTS operating band 1 */
    CI_DEV_UMTS_BAND_2,          /**< UMTS operating band 2 */
    CI_DEV_UMTS_BAND_3,          /**< UMTS operating band 3 */
    CI_DEV_UMTS_BAND_4,          /**< UMTS operating band 4 */
    CI_DEV_UMTS_BAND_5,          /**< UMTS operating band 5 */
    CI_DEV_UMTS_BAND_6,          /**< UMTS operating band 6 */
    CI_DEV_UMTS_BAND_7,          /**< UMTS operating band 7 */
    CI_DEV_UMTS_BAND_8,          /**< UMTS operating band 8 */
    CI_DEV_UMTS_BAND_9,          /**< UMTS operating band 9 */

    CI_DEV_UMTS_BAND_10,         /**< UMTS operating band 10 */
	CI_DEV_UMTS_BAND_11, 		 /**< UMTS operating band 11 */
	CI_DEV_UMTS_BAND_12, 		 /**< UMTS operating band 12 */
	CI_DEV_UMTS_BAND_13, 		 /**< UMTS operating band 13 */
	CI_DEV_UMTS_BAND_14, 		 /**< UMTS operating band 14 */
	CI_DEV_UMTS_BAND_15, 		 /**< UMTS operating band 15 */
	CI_DEV_UMTS_BAND_16, 		 /**< UMTS operating band 16 */
	CI_DEV_UMTS_BAND_17, 		 /**< UMTS operating band 17 */
	CI_DEV_UMTS_BAND_18,		 /**< UMTS operating band 18 */
	CI_DEV_UMTS_BAND_19,		 /**< UMTS operating band 19 */

    CI_DEV_NUM_UMTS_BAND

} _CiDevUMTSBandMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief UMTS band options
 * \sa CIDEVGSMBANDMODES_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevUMTSBandMode;
/**@}*/

/** \brief E-UTRAN band option values - E-UTRAN frequency bands are defined in 3GPP TS 36.101. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVEUTRANLOWBANDMODES_TAG{
    CI_DEV_EUTRAN_BAND_1  = 0,		/**< E-UTRAN operating band 1*/
    CI_DEV_EUTRAN_BAND_2,			/**< E-UTRAN operating band 2 */
    CI_DEV_EUTRAN_BAND_3,			/**< E-UTRAN operating band 3 */
    CI_DEV_EUTRAN_BAND_4,			/**< E-UTRAN operating band 4 */
    CI_DEV_EUTRAN_BAND_5,			/**< E-UTRAN operating band 5 */
    CI_DEV_EUTRAN_BAND_6,			/**< E-UTRAN operating band 6 */
    CI_DEV_EUTRAN_BAND_7,			/**< E-UTRAN operating band 7 */
    CI_DEV_EUTRAN_BAND_8,			/**< E-UTRAN operating band 8 */
    CI_DEV_EUTRAN_BAND_9,			/**< E-UTRAN operating band 10 */
	CI_DEV_EUTRAN_BAND_10,          /**< E-UTRAN operating band 11 */
    CI_DEV_EUTRAN_BAND_11,          /**< E-UTRAN operating band 12 */
    CI_DEV_EUTRAN_BAND_12,          /**< E-UTRAN operating band 13 */
    CI_DEV_EUTRAN_BAND_13,          /**< E-UTRAN operating band 14 */
    CI_DEV_EUTRAN_BAND_14,          /**< E-UTRAN operating band 15 */
    CI_DEV_EUTRAN_BAND_15_NOT_USED, 
    CI_DEV_EUTRAN_BAND_16_NOT_USED, 
    CI_DEV_EUTRAN_BAND_17,          /**< E-UTRAN operating band 17 */
	CI_DEV_EUTRAN_BAND_18,          /**< E-UTRAN operating band 18 */
    CI_DEV_EUTRAN_BAND_19,          /**< E-UTRAN operating band 19 */
    CI_DEV_EUTRAN_BAND_20,          /**< E-UTRAN operating band 20 */
    CI_DEV_EUTRAN_BAND_21,          /**< E-UTRAN operating band 21 */
    CI_DEV_EUTRAN_BAND_22,          /**< E-UTRAN operating band 22 */
	CI_DEV_EUTRAN_BAND_23,          /**< E-UTRAN operating band 23 */
    CI_DEV_EUTRAN_BAND_24,          /**< E-UTRAN operating band 24 */
	CI_DEV_EUTRAN_BAND_25,          /**< E-UTRAN operating band 25 */
    CI_DEV_EUTRAN_BAND_26,          /**< E-UTRAN operating band 26 */
	CI_DEV_EUTRAN_BAND_27_NOT_USED, 
    CI_DEV_EUTRAN_BAND_28_NOT_USED, 
	CI_DEV_EUTRAN_BAND_29_NOT_USED, 
    CI_DEV_EUTRAN_BAND_30_NOT_USED, 
    CI_DEV_EUTRAN_BAND_31_NOT_USED, 
    CI_DEV_EUTRAN_BAND_32_NOT_USED, 
	CI_DEV_NUM_LOW_EUTRAN_BAND
} _CiDevEUTRANLowBandMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief E-UTRAN band options
 * \sa CIDEVEUTRANLOWBANDMODES_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiDevEUTRANLowBandMode;
/**@}*/

/** \brief E-UTRAN band option values - E-UTRAN frequency bands are defined in 3GPP TS 36.101. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVEUTRANHIGHBANDMODES_TAG{
    CI_DEV_EUTRAN_BAND_33  = 0, /**< E-UTRAN operating band 33 */
	CI_DEV_EUTRAN_BAND_34,          /**< E-UTRAN operating band 34 */
    CI_DEV_EUTRAN_BAND_35,          /**< E-UTRAN operating band 35 */
    CI_DEV_EUTRAN_BAND_36,          /**< E-UTRAN operating band 36 */
    CI_DEV_EUTRAN_BAND_37,          /**< E-UTRAN operating band 37 */
    CI_DEV_EUTRAN_BAND_38,          /**< E-UTRAN operating band 38 */
	CI_DEV_EUTRAN_BAND_39,          /**< E-UTRAN operating band 39 */
    CI_DEV_EUTRAN_BAND_40,          /**< E-UTRAN operating band 40 */
	CI_DEV_EUTRAN_BAND_41,          /**< E-UTRAN operating band 41 */
    CI_DEV_EUTRAN_BAND_42,          /**< E-UTRAN operating band 42 */
	CI_DEV_EUTRAN_BAND_43,          /**< E-UTRAN operating band 43 */
    CI_DEV_NUM_HIGH_EUTRAN_BAND
} _CiDevEUTRANHighBandMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief E-UTRAN band options
 * \sa CIDEVEUTRANHIGHBANDMODES_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiDevEUTRANHighBandMode;
/**@}*/

typedef enum CiDevSetBandRoamingConfig_tag
{
    CI_DEV_SET_BAND_ROAMING_NOT_SUPPORT,
    CI_DEV_SET_BAND_ROAMING_SUPPORT,
    CI_DEV_SET_BAND_ROAMING_NOT_CHANGE,
    
    CI_DEV_SET_BAND_ROAMING_NUM
}_CiDevSetBandRoamingConfig;

typedef UINT8 CiDevSetBandRoamingConfig;

typedef enum CiDevSetBandSrvDomain_tag
{
    CI_DEV_SET_BAND_CS_ONLY,
    CI_DEV_SET_BAND_PS_ONLY,
    CI_DEV_SET_BAND_COMBINED_SERVICE,
    CI_DEV_SET_BAND_ANY_SERVICE,
    CI_DEV_SET_BAND_SERVICE_NOT_CHANGE,
    
    CI_DEV_SET_BAND_SERVICE_NUM
}_CiDevSetBandSrvDomain;

typedef UINT8 CiDevSetBandSrvDomain;

typedef enum CiDevSetBandPriorityFlag_tag
{
    CI_DEV_SET_BAND_DEFAULT_PRIORITY,
    CI_DEV_SET_BAND_TDD_LTE_PREFER,
    CI_DEV_SET_BAND_FDD_LTE_PREFER,
    
    CI_DEV_SET_BAND_PRIORITY_NUM
}_CiDevSetBandPriorityFlag;

typedef UINT8 CiDevSetBandPriorityFlag;

typedef enum CiDevSetBandUsageType_enum
{
    CI_DEV_SET_BAND_UE_BAND_CAPABILITY, /**<  default value*/
    CI_DEV_SET_BAND_PREFER_BAND,
    CI_DEV_SET_BAND_REGISTER_BAND,
    CI_DEV_SET_PREFER_NW_MODE_THEN_BACK_TO_AUTO,
    CI_DEV_SET_BAND_WO_NETWORK_MODE,/**< no save usermode, only save band infomation used in LOCKBAND*/
    CI_DEV_SET_BAND_WITHOUT_SAVING,/**< added CQ00113946 by taow 20190218: DON'T saving all config param to NVM */
    CI_DEV_SET_BAND_MODE_NUM
}_CiDevSetBandUsageType;

typedef UINT8 CiDevSetBandUsageType;

/** <paramref name="CI_DEV_PRIM_SET_BAND_MODE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetBandModeReq_struct{
    CiDevNetworkMode    networkMode;
    CiDevNetworkMode    preferredMode;	
    CiBitRange          GSMBandMode;
    CiBitRange          UMTSBandMode;
    CiBitRange          EUTRANBandModeH;/**< Bit mask indicating the required E-UTRAN bands High part (bands 33 - 43). If bit is set the
                                         *   band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/
    CiBitRange          EUTRANBandModeL;/**< Bit mask indicating the required E-UTRAN bands Low part (bands 1 - 32). If bit is set the
                                         *   band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/
    CiDevSetBandRoamingConfig  roamingConfig; /**< Roaming: 0-not support, 1-support, 2-no change(default) */
    CiDevSetBandSrvDomain      srvDomain; /**< Service domain: 0-CS only, 1- PS only, 2-CS and PS, 3 - ANY, 4 -no change(default) */
    CiDevSetBandPriorityFlag   bandPriorityFlag; /**0: default; 1: TD-LTE; 2:FDD-LTE*/
    CiBoolean	               isLteDualLink; /**TRUE: dual Link; FALSE: single Link*/

    /*Added by Lilei for preferred band setting on 01152014, begin*/
#if 1//defined(SS_IPC_SUPPORT)
    CiDevSetBandUsageType      bandType; /**< Band type: 0-band capability(default), 1-preferred band, 2-only registration band */
#endif
    /*Added by Lilei for preferred band setting on 01152014, end*/
    CiBitRange          EUTRANBandModeExt;/**< Bit mask indicating the required E-UTRAN bands Extended part (bands 65 - 69). */
}CiDevPrimSetBandModeReq;

//ICAT EXPORTED ENUM
typedef enum CIDEVSETBANDCNFACT_TAG{
    CI_DEV_SET_BAND_CNF_NO_ACT = 0,
    CI_DEV_SET_BAND_CNF_NEED_SILENT_RESET
}_CiDevSetBandCnfAct;

typedef UINT8 CiDevSetBandCnfAct; 

/** <paramref name="CI_DEV_PRIM_SET_BAND_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetBandModeCnf_struct{
    CiDevRc result; 	/**< Result code  \sa CiDevRc */
    CiDevSetBandCnfAct apAct;
}CiDevPrimSetBandModeCnf;

/** <paramref name="CI_DEV_PRIM_GET_BAND_MODE_REQ"> */
typedef CiEmptyPrim CiDevPrimGetBandModeReq;

/** <paramref name="CI_DEV_PRIM_GET_BAND_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetBandModeCnf_struct{
    CiDevRc             result;
    CiDevNetworkMode    networkMode;
    CiDevNetworkMode    preferredMode;		
    CiBitRange          GSMBandMode;
    CiBitRange          UMTSBandMode;
    CiBitRange          EUTRANBandModeH;/**< Bit mask indicating the required E-UTRAN bands High part (bands 33 - 43). If bit is set the
                                        *   band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/
    CiBitRange          EUTRANBandModeL;/**< Bit mask indicating the required E-UTRAN bands Low part (bands 1 - 32). If bit is set the
                                        *   band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/
	UINT8  roamingConfig; /**< Roaming: 0-not support, 1-support */
	UINT8  srvDomain;  /**< Service domain: 0-CS only, 1- PS only, 2-CS and PS, 3 - ANY*/
	UINT8		  bandPriorityFlag; /**0: default; 1: TD-LTE; 2:FDD-LTE*/
	/* Added by Lilei 20131009, begin */
	CiBoolean	isLteDualLink; /**TRUE: dual Link; FALSE: single Link*/
	/* Added by Lilei 20131009, end */
    CiBitRange          EUTRANBandModeExt;/**< Bit mask indicating the required E-UTRAN bands Extended part (bands 65 - 69). */
} CiDevPrimGetBandModeCnf;
/** <paramref name="CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_REQ"> */
typedef CiEmptyPrim CiDevPrimGetSupportedBandModeReq;

/** <paramref name="CI_DEV_PRIM_GET_SUPPORTED_BAND_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSupportedBandModeCnf_struct{
    CiDevRc         result;       /**< Result code  \sa CiDevRc */
    CiBitRange      bitsNetworkMode;    /**< Bit mask indicating the supported RAT modes. If bit is set the band is supported. Bit definition is based on CIDEVNWMODES_TAG \sa CCI API Ref Manual*/
    CiBitRange      bitsGSMBandMode;    /**< Bit mask indicating the supported GSM bands. If bit is set the band is supported. Bit definition is based on CIDEVGSMBANDMODES_TAG \sa CCI API Ref Manual */
    CiBitRange      bitsUMTSBandMode;   /**< Bit mask indicating the supportedUMTS bands. If bit is set the band is supported. Bit definition is based on CIDEVUMTSBANDMODES_TAG \sa CCI API Ref Manual */
    CiBitRange      bitsEUTRANBandModeH;/**< Bit mask indicating the required E-UTRAN bands High part (bands 33 - 43). If bit is set the
                                        *   band is supported. Bit definition is based on CIDEVEUTRANHIGHBANDMODES_TAG*/
    CiBitRange      bitsEUTRANBandModeL;/**< Bit mask indicating the required E-UTRAN bands Low part (bands 1 - 32). If bit is set the
                                        *   band is supported. Bit definition is based on CIDEVEUTRANLOWBANDMODES_TAG*/
    CiBitRange      bitsEUTRANBandModeExt;/**< Bit mask indicating the required E-UTRAN bands Extended part (bands 65 - 69). */
} CiDevPrimGetSupportedBandModeCnf;

/*Michal Bukai *BAND support - END*/

/*Michal Bukai - IMEI support - START*/

//** \brief IMEI SV structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiImei_struct{
	UINT8  len; /**< Length */
	CHAR   val[CI_MAX_IMEI_SV_LEN];	/**< IMEI digits */
}CiImei;

/** <paramref name="CI_DEV_PRIM_SET_SV_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSvReq_struct{
    CiImei		SVDigits;	/**< IMEI SV digits.  \sa CiImei */
} CiDevPrimSetSvReq;

/** <paramref name="CI_DEV_PRIM_SET_SV_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSvCnf_struct{
    CiDevRc rc;	/**< Result code. \sa CiDevRc. */
} CiDevPrimSetSvCnf;

/** <paramref name="CI_DEV_PRIM_GET_SV_REQ">   */
typedef CiEmptyPrim CiDevPrimGetSvReq;


/** <paramref name="CI_DEV_PRIM_GET_SV_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSvCnf_struct{
	CiImei		SVDigits;	/**< IMEI SV dugits.  \sa CiImei */
    CiDevRc		rc;	/**< Result code. \sa CiDevRc. */
} CiDevPrimGetSvCnf;
/*Michal Bukai - IMEI support - END*/

/** <paramref name="CI_DEV_PRIM_AP_POWER_NOTIFY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimApPowerNotifyReq_struct{
	UINT32	powerState;                /**< AP power state: 1~31 means suspend, bitmap: bit0 - NETWORK;
	                                                                                    bit1 - SIM;
	                                                                                    bit2 - SMS;
	                                                                                    bit3 - CS CALL
	                                                                                    bit4 - PS DATA
	                                                           0 means resume all.  \sa powerState */
} CiDevPrimApPowerNotifyReq;

/** <paramref name="CI_DEV_PRIM_AP_POWER_NOTIFY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimApPowerNotifyCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
} CiDevPrimApPowerNotifyCnf;

//ICAT EXPORTED ENUM
typedef enum CIDEV_TD_RX_TX_OPTION_TAG{
    CI_DEV_TD_TX_START = 0,
    CI_DEV_TD_RX_START,
    CI_DEV_TD_TX_RX_STOP,

    CI_DEV_NUM_TD_TX_RX
} _CiDevTdTxRxOption; 

typedef UINT8 CiDevTdTxRxOption;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_RX_TX_OPTION_TAG{
    CI_DEV_GSM_TX_START = 0,
    CI_DEV_GSM_RX_START,
    CI_DEV_GSM_TX_RX_START,
    CI_DEV_GSM_TX_RX_STOP,

    CI_DEV_NUM_GSM_TX_RX
} _CiDevGsmTxRxOption; 

typedef UINT8 CiDevGsmTxRxOption;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_CONTROL_MODE_TAG{
    CI_DEV_GSM_CONTROL_READ = 0,
    CI_DEV_GSM_CONTROL_WRITE,
    CI_DEV_GSM_CONTROL_LOOPBACK,

    CI_DEV_NUM_GSM_CONTROL
} _CiDevGsmControlMode; 

typedef UINT8 CiDevGsmControlMode;

/** <paramref name="CI_DEV_PRIM_SET_TD_MODE_TX_RX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetTdModeTxRxReq_struct {
	CiDevTdTxRxOption option;     /**< TD option. \sa CiDevTdTxRxOption */
	INT16 txRxGain;       /**<  Tx or Rx gain */
	UINT16 freq;           /**<  TD frequency */
} CiDevPrimSetTdModeTxRxReq;

/** <paramref name="CI_DEV_PRIM_SET_TD_MODE_TX_RX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetTdModeTxRxCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
} CiDevPrimSetTdModeTxRxCnf;

/** <paramref name="CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetTdModeLoopbackReq_struct {
	UINT32 regValue;       /**<  The value to be written into RF register */
} CiDevPrimSetTdModeLoopbackReq;

/** <paramref name="CI_DEV_PRIM_SET_TD_MODE_LOOPBACK_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetTdModeLoopbackCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
	UINT32 regValue;       /**<  The value to be read from RF register */
} CiDevPrimSetTdModeLoopbackCnf;

/*Add by Alan for WCDMA Radio test  05292013, begin*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_WCDMA_RX_TX_OPTION_TAG{
    CI_DEV_WCDMA_TX_START = 0,
    CI_DEV_WCDMA_RX_START,
    CI_DEV_WCDMA_TX_RX_STOP,

    CI_DEV_NUM_WCDMA_TX_RX
} _CiDevWcdmaTxRxOption; 

typedef UINT8 CiDevWcdmaTxRxOption;

/** <paramref name="CI_DEV_PRIM_SET_WCDMA_MODE_TX_RX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetWcdmaModeTxRxReq_struct {
    CiDevWcdmaTxRxOption option;     /**< WCDMA option. \sa CiDevWcdmaTxRxOption */
    UINT16     DL_UARFCN;          /**< Downlink UARFCN*/
    UINT16     UL_UARFCN;          /**< Uplink UARFCN*/
    UINT8      PA_Mode;            /**< PA mode :2; range (0,1,2)*/
    UINT16     APC_Dac;       /**<  APC DAC :1600; range [0,2047] */
    UINT16     DCDC_Dac;       /**<DCDC DAC :Not used for LT02*/
    INT16      AFC_Dac;       /**<  AFC DAC :18000*/
} CiDevPrimSetWcdmaModeTxRxReq;

/** <paramref name="CI_DEV_PRIM_SET_TD_MODE_TX_RX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetWcdmaModeTxRxCnf_struct {
    CiDevRc rc;     /**< Result code. \sa CiDevRc */
    signed short acqRssi;          /**<  The Rssi value to be returned in case of GSM RX mode*/
} CiDevPrimSetWcdmaModeTxRxCnf;
/*Add by Alan for WCDMA Radio test  05292013, end*/

/*Added by Lilei for LTE Radio test on 01232014, begin*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RX_TX_OPTION_TAG{
    CI_DEV_LTE_TX_START = 0,
    CI_DEV_LTE_RX_START,
    CI_DEV_LTE_TX_RX_STOP,

    CI_DEV_NUM_LTE_TX_RX
} _CiDevLteTxRxOption; 

typedef UINT8 CiDevLteTxRxOption;

/** <paramref name="CI_DEV_PRIM_SET_LTE_MODE_TX_RX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteModeTxRxReq_struct {
	CiDevLteTxRxOption option;     /**< LTE option. \sa CiDevLteTxRxOption */
	INT16 txRxPower;       /**<  Tx or Rx power. Range [0,2047] for TX*/
	UINT16 freq;           /**<  LTE carrier frequency. Range[0,45589] */
	UINT8 bandwidth; 		/**<  LTE bandwidth. Range[0,5] */
} CiDevPrimSetLteModeTxRxReq;

/** <paramref name="CI_DEV_PRIM_SET_LTE_MODE_TX_RX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteModeTxRxCnf_struct {
    CiDevRc rc;     /**< Result code. \sa CiDevRc */
#if 1 //added on 20191219 for quectel case#2278	
	INT16 rssiPri;
	INT16 rssiSec;
#endif
} CiDevPrimSetLteModeTxRxCnf;
/*Added by Lilei for LTE Radio test on 01232014, end*/

/** <paramref name="CI_DEV_PRIM_SET_GSM_MODE_TX_RX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmModeTxRxReq_struct {
	CiDevGsmTxRxOption option;     /**< TD option. \sa CiDevGsmTxRxOption */
	CiBitRange gsmBandMode;       /**<  GSM band mode */
	UINT16 arfcn;            /**<  Absolute Radio Frequency Channel Number */
	UINT32 afcDac;           /**<  AFC DAC value*/
	UINT32 txRampScale;      /**<  Tx ramp scale, only valid for Tx or Tx+Rx mode*/
	UINT32 rxGainCode;       /**<  Rx gain code, only valid for Rx or Tx+Rx mode*/
} CiDevPrimSetGsmModeTxRxReq;

/** <paramref name="CI_DEV_PRIM_SET_GSM_MODE_TX_RX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmModeTxRxCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
	signed short rssiDbmValue;          /**<  The Rssi value to be returned in case of GSM RX mode*/
} CiDevPrimSetGsmModeTxRxCnf;

/** <paramref name="CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmControlInterfaceReq_struct {
	CiDevGsmControlMode mode;     /**< Operation mode. \sa CiDevGsmControlMode */
	UINT16 addrReg;           /**<  Register address*/
	UINT16 regValue;          /**<  The payload value to be written into RFIC in case of write or loopback mode*/
} CiDevPrimSetGsmControlInterfaceReq;

/** <paramref name="CI_DEV_PRIM_SET_GSM_CONTROL_INTERFACE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetGsmControlInterfaceCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
	UINT16 addrReg;           /**<  Register address*/
	UINT16 regValue;          /**<  The payload value to be read from RFIC in case of read or loopback mode*/	
} CiDevPrimSetGsmControlInterfaceCnf;

//ICAT EXPORTED ENUM
typedef enum CIDEV_HSPA_CONFIG_TAG{
    CI_DEV_HSDPA_OFF_HSUPA_OFF = 0,  /* set RRC release to R5 */
    CI_DEV_HSDPA_ON_HSUPA_OFF,       /* set RRC release to R5 */
    CI_DEV_HSDPA_ON_HSUPA_ON,        /* set RRC release to R7 */
    CI_DEV_HSDPA_ON_HSUPA_ON_DLDC,   /* set RRC release to R9, only used for TD-SCDMA */
    CI_DEV_HSPA_REL6,                /* set RRC release to R6, only used for WCDMA */

    CI_DEV_NUM_HSPA_CONFIG
} _CiDevHspaConfig; 

typedef UINT8 CiDevHspaConfig;

/** <paramref name="CI_DEV_PRIM_ENABLE_HSDPA_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimEnableHsdpaReq_struct{
    CiDevHspaConfig   hspaConfig;      /**< HSPA configurations \sa CiDevHspaConfig */
    UINT8             dlCategory;      /**<  DL category, for WCDMA support 1~12, default 10 for Rel7;support 1~15 except 12 on TD HSDPA, 16,23,35 on DLDC, default 15*/
    UINT8             ulCategory;      /**<  UL category, for WCDMA support 1~6, default 6; only support 6 on TD HSUPA, fix it if UPA is enabled */
    UINT8             cpcState;        /**<  CPC state only used for WCDMA Rel7, 0:disabled,1:enabled, default enabled; not supported on TD-SCDMA, hard coded with 0 or ingore it*/
    
    UINT8             dpaCategoryExt;  /**<  DPA category ext, for WCDMA Rel7 support 1~14, default 14 for Rel7*/
    UINT8             edchCategoryExt; /**<  EDCH category ext, for WCDMA Rel7 only support 7 as default*/

    UINT8             fdpchState;      /**<  F-DPCH enabled or disabled on R6/R7 for WCDMA, 0:disabled,1:enabled, default enabled*/
    UINT8             eFdpchState;     /**<  Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0:disabled,1:enabled, default enabled*/

    /*Lilei, CQ00090354, 20150410, begin*/
    UINT8             eFachState;     /**<  Enhanced FACH enabled or disabled on R7 for WCDMA. 0:disabled,1:enabled, default enabled*/
    /*Lilei, CQ00090354, 20150410, end*/
} CiDevPrimEnableHsdpaReq;

/** <paramref name="CI_DEV_PRIM_ENABLE_HSDPA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimEnableHsdpaCnf_struct {
	CiDevRc rc;     /**< Result code. \sa CiDevRc */
} CiDevPrimEnableHsdpaCnf;

/** <paramref name="CI_DEV_PRIM_GET_HSDPA_STATUS_REQ">   */
typedef CiEmptyPrim CiDevPrimGetHsdpaStatusReq;

/** <paramref name="CI_DEV_PRIM_GET_HSDPA_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetHsdpaStatusCnf_struct {
    CiDevRc rc;     /**< Result code. \sa CiDevRc */

    CiDevHspaConfig   hspaConfig;      /**< HSPA configurations \sa CiDevHspaConfig */
    UINT8             dlCategory;      /**<  DL category, for WCDMA support 1~12, default 10 for Rel7;support 1~15 except 12 on TD HSDPA, 16,23,35 on DLDC, default 15*/
    UINT8             ulCategory;      /**<  UL category, for WCDMA support 1~6, default 6; only support 6 on TD HSUPA, fix it if UPA is enabled */
    UINT8             cpcState;        /**<  CPC state only used for WCDMA Rel7, 0:disabled,1:enabled, default enabled; not supported on TD-SCDMA, hard coded with 0 or ingore it*/
    
    UINT8             dpaCategoryExt;  /**<  DPA category ext, for WCDMA Rel7 support 1~14, default 14 for Rel7*/
    UINT8             edchCategoryExt; /**<  EDCH category ext, for WCDMA Rel7 only support 7 as default*/

    UINT8             fdpchState;      /**<  F-DPCH enabled or disabled on R6/R7 for WCDMA, 0:disabled,1:enabled, default enabled*/
    UINT8             eFdpchState;     /**<  Enhanced F-DPCH enabled or disabled on R7 for WCDMA 0:disabled,1:enabled, default enabled*/

    /*Lilei, CQ00090354, 20150410, begin*/
    UINT8             eFachState;     /**<  Enhanced FACH enabled or disabled on R7 for WCDMA. 0:disabled,1:enabled, default enabled*/
    /*Lilei, CQ00090354, 20150410, end*/
} CiDevPrimGetHsdpaStatusCnf;

//ICAT EXPORTED ENUM
typedef enum CIDEV_RF_TEMP_TYPE_TAG{
    CI_DEV_RF_TEMP_CELSIUS = 0,         /**< internal RF temp */
    CI_DEV_RF_TEMP_RAW_DATA,            /**< internal RF temp */

    /*Lilei, CQ00125096, 20201013, begin*/
    CI_DEV_RF_TEMP_CELSIUS_EXTERNAL,    /**< external RF temp */
    CI_DEV_RF_TEMP_RAW_DATA_EXTERNAL,   /**< external RF temp */
    /*Lilei, CQ00125096, 20201013, end*/

    CI_DEV_NUM_RF_TEMP
} _CiDevRfTempType; 

typedef UINT8 CiDevRfTempType;

/** <paramref name="CI_DEV_PRIM_READ_RF_TEMPERATURE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimReadRfTemperatureReq_struct{
    CiDevRfTempType type;     /**< Read type. \sa CiDevRfTempType  */
} CiDevPrimReadRfTemperatureReq;

/** <paramref name="CI_DEV_PRIM_READ_RF_TEMPERATURE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimReadRfTemperatureCnf_struct {
    CiDevRc rc;     /**< Result code. \sa CiDevRc */
    INT32   tempData;  /**< Temperature data */
} CiDevPrimReadRfTemperatureCnf;

/*Mason CMCC Smart Network Monitor support - START*/
#define CI_DEV_MAX_TDD_TIMESLOT_ISCP    7
#define CI_DEV_MAX_TDD_DPCH_RSCP        7
#define CI_DEV_MAX_TDD_DEDICATED_PHYCH  96

#define CI_DEV_MAX_GSM_DL_NUM_BLK       4
#define CI_DEV_MAX_GSM_UL_DL_CS_MCS     50
#define CI_DEV_MAX_GSM_NUM_TIMESLOT     4
#define CI_DEV_MAX_GSM_NUM_REPORTED_ARFCN     64
#define CI_DEV_MAX_GSM_NUM_CELL_ALLOCATION    64

#define CI_DEV_MAX_WIRELESS_DATA_LENGTH      1908//1912
#define CI_DEV_MAX_PEER_MSG_LENGTH      356

//ICAT EXPORTED ENUM
typedef enum CIDEV_NW_MONITOR_MODE_TAG{
    CI_DEV_NW_MONIOTR_NORMAL = 16,
    CI_DEV_NW_MONIOTR_DETECT = 96,

    CI_DEV_NUM_RNW_MONIOTR
} _CiDevNwMonitorMode; 

typedef UINT8 CiDevNwMonitorMode;

//ICAT EXPORTED ENUM
typedef enum CIDEV_PROTOCOL_STATUS_TAG{
    CI_DEV_PROTOCOL_STATUS_IDLE = 0,
    CI_DEV_PROTOCOL_STATUS_CONNECT,

    CI_DEV_NUM_PROTOCOL_STATUS
} _CiDevProtocolStatus; 

typedef UINT8 CiDevProtocolStatus;

//ICAT EXPORTED ENUM
typedef enum CIDEV_EVENT_OPER_TYPE_TAG{
    CI_DEV_EVENT_OPER_CS_VOICE = 0,
    CI_DEV_EVENT_OPER_CS_DATA,
    CI_DEV_EVENT_OPER_PS,
    CI_DEV_EVENT_OPER_SMS,

    CI_DEV_NUM_EVENT_OPER
} _CiDevEventOperType;

typedef UINT8 CiDevEventOperType;

typedef UINT32 CiDevEventId;

//ICAT EXPORTED ENUM
typedef enum CIDEV_SIGNALING_MSG_ID_TAG{
    CI_DEV_SIGNALING_BCH_MSG_IND = 12202,  /* only for TDD */
    CI_DEV_SIGNALING_BCCH_FACH_MSG_IND = 2020,  /* only for TDD */
    CI_DEV_SIGNALING_PCCH_PCH_MSG_IND = 2021,  /* only for TDD */
    CI_DEV_SIGNALING_UL_CCH_MSG_IND = 3005,  /* only for TDD */
    CI_DEV_SIGNALING_DL_CCH_MSG_IND = 3006,  /* only for TDD */    

    CI_DEV_SIGNALING_GSM_MSG_IND = 12155,  /* only for GSM */    

    CI_DEV_NUM_SIGNALING_MSG_D = 0xFFFF
} _CiDevSignalingMsgId; 

typedef UINT32 CiDevSignalingMsgId;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_BAND_TAG{
    CI_DEV_GSM_BAND_PGSM_900 = 0,
    CI_DEV_GSM_BAND_EGSM_900,
    CI_DEV_GSM_BAND_RGSM_900,
    CI_DEV_GSM_BAND_DCS_1800,
    CI_DEV_GSM_BAND_PCS_1900,
    CI_DEV_GSM_BAND_450,
    CI_DEV_GSM_BAND_480,
    CI_DEV_GSM_BAND_850,
    CI_DEV_GSM_BAND_750,

    CI_DEV_NUM_BAND
} _CiDevGsmBand;

typedef UINT8 CiDevGsmBand;

//ICAT EXPORTED STRUCT
typedef struct CiDevPlmnMcc_struct
{
    UINT8   mcc[3];
} CiDevPlmnMcc;

//ICAT EXPORTED STRUCT
typedef struct CiDevPlmnMnc_struct
{
    UINT8   len;
    UINT8   mnc[3];
} CiDevPlmnMnc;

//ICAT EXPORTED STRUCT
typedef struct CiDevTsIscp_struct
{
    UINT8 timeSlot;    /**< TimeSlot (0..6) */
    UINT8 iscp;        /**< ISCP (0..91), real value(dbm)=IE value -116 */
} CiDevTsIscp;

//ICAT EXPORTED STRUCT
typedef struct CiDevTsIscpArray_struct
{
    UINT8 num;
    CiDevTsIscp  data[CI_DEV_MAX_TDD_TIMESLOT_ISCP];
} CiDevTsIscpArray;

//ICAT EXPORTED STRUCT
typedef struct CiDevDpchRscp_struct
{
    UINT8 timeSlot;    /**< TimeSlot (0..6) */
    UINT8 rscp;        /**< DPCH RSCP (0..91), real value(dbm)=IE value -116 */
} CiDevDpchRscp;

//ICAT EXPORTED STRUCT
typedef struct CiDevDpchRscpArray_struct
{
    UINT8 num;
    CiDevDpchRscp  data[CI_DEV_MAX_TDD_DPCH_RSCP];
} CiDevDpchRscpArray;

//ICAT EXPORTED STRUCT
typedef struct CiDevTxPower_struct
{
    UINT8 timeSlot;    /**< TimeSlot (0..6) */
    UINT8 txPower;     /**< UE Transmitted Power (21..104), 0xff means UE TxPower is not available.
                                              real value(dbm)=IE value -71 */
} CiDevTxPower;

//ICAT EXPORTED STRUCT
typedef struct CiDevTxPowerArray_struct
{
    UINT8 num;
    CiDevTxPower  data[CI_DEV_MAX_TDD_DPCH_RSCP];
} CiDevTxPowerArray;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddNcellTsIscp_struct
{
    UINT8    tsNum;    /**< Timeslot number. (0..6)*/
    UINT8    tsIscp;   /**< Timeslot ISCP. (0..91) */
} CiDevTddNcellTsIscp;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddRrcDiagNcellTddPara_struct
{
    UINT8          cellParamId;  /**< Neighbor cell parameter ID. (0..127)*/
    UINT16         uArfcn;       /**< Neighbor cell UARFCN. (0..16383) */
    UINT8          pccpchRscp;   /**< Neighbor cell PCCPCH RSCP. (0..91) */

    UINT8          res1U8;       /**< (padding) */
    UINT8          iscpNum;      /**(0..6) If it equals to 0,nCellTsIscp does not xist. */ 
    CiDevTddNcellTsIscp  nCellTsIscp[CI_DEV_MAX_TDD_TIMESLOT_ISCP-1];

    UINT32         res2U32;      /**< (padding) */
} CiDevTddRrcDiagNcellTddPara;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddRrcDiagNcellGsmPara_struct
{
    UINT16          arfcn; /**< Neighbor cell ARFCN info. (0..1023)*/
    CiDevGsmBand    band;  /**< Neighbor cell current freq band. */
    UINT8           bsic;  /**< Neighbor cell BSIC. (0..63)*/
    UINT8           rxlev; /**< Neighbor cell GSM received signal level. */ 
    UINT8   res1U16[3];    /**< (padding) */ 
} CiDevTddRrcDiagNcellGsmPara;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddNcellParamList_struct
{
    UINT8 numNcellTdd;     /**<  If it equals 0, the IE below will not exist */
    CiDevTddRrcDiagNcellTddPara  nbCellInfoTdd[CI_DEV_MAX_GSM_NEIGHBORING_CELLS];

    UINT8 res1U8;          /**< (padding), always fill with 0xFE */
    UINT8 numNcellGsm;     /**<  If it equals 0, the IE below will not exist */
    CiDevTddRrcDiagNcellGsmPara  nbCellInfoGsm[CI_DEV_MAX_GSM_NEIGHBORING_CELLS];
} CiDevTddNcellParamList;

//ICAT EXPORTED ENUM
typedef enum CIDEV_TDD_CHANNEL_CODE_TAG{
    CI_DEV_TDD_CC1_1 = 0,
    CI_DEV_TDD_CC2_1,
    CI_DEV_TDD_CC2_2,
    CI_DEV_TDD_CC4_1,
    CI_DEV_TDD_CC4_2,
    CI_DEV_TDD_CC4_3,
    CI_DEV_TDD_CC4_4,
    CI_DEV_TDD_CC8_1,
    CI_DEV_TDD_CC8_2,
    CI_DEV_TDD_CC8_3,
    CI_DEV_TDD_CC8_4,
    CI_DEV_TDD_CC8_5,
    CI_DEV_TDD_CC8_6,
    CI_DEV_TDD_CC8_7,
    CI_DEV_TDD_CC8_8,
    CI_DEV_TDD_CC16_1,
    CI_DEV_TDD_CC16_2,
    CI_DEV_TDD_CC16_3,
    CI_DEV_TDD_CC16_4,
    CI_DEV_TDD_CC16_5,
    CI_DEV_TDD_CC16_6,
    CI_DEV_TDD_CC16_7,
    CI_DEV_TDD_CC16_8,
    CI_DEV_TDD_CC16_9,
    CI_DEV_TDD_CC16_10,
    CI_DEV_TDD_CC16_11,
    CI_DEV_TDD_CC16_12,
    CI_DEV_TDD_CC16_13,
    CI_DEV_TDD_CC16_14,
    CI_DEV_TDD_CC16_15,
    CI_DEV_TDD_CC16_16,

    CI_DEV_NUM_TDD_CC
} _CiDevTddChannelCode;

typedef UINT8 CiDevTddChannelCode;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_CODING_SCHEME_TAG {
    CI_DEV_GSM_CS_1 = 7,
    CI_DEV_GSM_CS_2,
    CI_DEV_GSM_CS_3,
    CI_DEV_GSM_CS_4,

    CI_DEV_GSM_MCS_1 = 11,
    CI_DEV_GSM_MCS_2,
    CI_DEV_GSM_MCS_3,
    CI_DEV_GSM_MCS_4,
    CI_DEV_GSM_MCS_5,
    CI_DEV_GSM_MCS_6,
    CI_DEV_GSM_MCS_7,
    CI_DEV_GSM_MCS_8,
    CI_DEV_GSM_MCS_9,
    
    CI_DEV_GSM_CS_INVALID = 0xFF,
    
    CI_DEV_NUM_GSM_CS
} _CiDevGsmCodingScheme;

typedef UINT8 CiDevGsmCodingScheme;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddRrcDiagPhych_struct
{
    UINT8   phychId;         /**< PhyCH Id (0..47)*/
    UINT8   phychDirection;  /**< PhyCH Direction, 0:uplink;1:downlink*/
    UINT8   timeSlot;        /**< Timeslot (0..6)*/

    CiDevTddChannelCode   channelCode;     /**< Channel code */ 
    UINT16  res1U16[2];      /**< (padding) */ 
} CiDevTddRrcDiagPhych;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddDedicatedPhyCchParam_struct
{
    UINT8   numPhych;       /**< (0..96),0: all the followed item not exist; others(1-96): actual physical channel number; and the followed times exist*/
    CiDevTddRrcDiagPhych  phychInfo[CI_DEV_MAX_TDD_DEDICATED_PHYCH];

    UINT32  res1U32;       /**< (padding) */
    UINT16  workFreq;       /**< Work frequency,(0..16383) UARFCN,real requency(Mhz)=UARFCN/5. It indicates the work frequency */
} CiDevTddDedicatedPhyCchParam;

//ICAT EXPORTED STRUCT
typedef struct CiDevHrnti_struct
{
    CiBoolean   flag;    /**< 0: H-RNTI is not existed, 1:H-RNTI is existed */
    UINT16      hrnti;   /**< (0..65535),exist only when flag=1 */
} CiDevHrnti;

//ICAT EXPORTED STRUCT
typedef struct CiDevErnti_struct
{
    CiBoolean   flag;    /**< 0: E-RNTI is not existed, 1:E-RNTI is existed */
    UINT16      ernti;   /**< (0..65535),exist only when flag=1 */
} CiDevErnti;

//ICAT EXPORTED STRUCT
typedef struct CiDevUrntiCrnti_struct
{
    UINT8       flag;    /**< Bit0:C-RNTI; Bit1:U-RNTI; 0:not existed,1:existed*/
    UINT32      urnti;   /**< (0..4294967295),exist only when flag=1 */
    UINT16      crnti;   /**< (0..65535),exist only when flag=1 */
} CiDevUrntiCrnti;

//ICAT EXPORTED STRUCT
typedef struct CiDevTddData_struct
{
    CiDevTsIscpArray      iscp;    /**< TimeSlot ISCP */
    CiDevDpchRscpArray    rscp;    /**< DPCH RSCP */
    CiDevTxPowerArray     txPower; /**< UE Timeslot Transmitted Power */

    UINT8   sCellPccphRscp;       /**< Scell P-CCPCH RSCP, (0..91) real value(dbm)=IE value -116 */
    UINT32  sCellId;              /**< Scell Cell Identifier, BITSTRING(28) MSB 4 bits are 0 */
    UINT8   sCellParamId;         /**< Scell Cell parameter id, (0..127) */
    UINT16  sCellUarfcn;          /**< Scell UARFCN, (0..16383), real frequency(MHz)=UARFCN/5 */
    UINT8   sCellUtraRssi;        /**< Scell UTRA Carrier RSSI, (0..76) real value(dbm)=IE value - 101 */

    CiDevTddNcellParamList        nbCellInfo;    /**< Neigbour cell parameter list */
    CiDevTddDedicatedPhyCchParam  dedicatedInfo; /**< Dedicated PhyCh parameter */

    CiDevHrnti      hRnti; /**< H-RNTI */
    CiDevErnti      eRnti; /**< E-RNTI */
    CiDevUrntiCrnti rnti;  /**< U-RNTI/C-RNTI */
} CiDevTddData;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmScellSysInfo_struct
{
    UINT16         arfcn;    /**< Serving cell ARFCN (0..1023) */    
    UINT16         ci;       /**< Serving cell cell identity */

    UINT16         res1U16;  /**< (padding) */   
    CiDevGsmBand   band;     /**< Serving cell current freq band */

    UINT32         res1U32;  /**< (padding) */
} CiDevGsmScellSysInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmScellRadioInfo_struct
{
    UINT8         fieldMap;    /**< bit0:C2 exist or not, bit1:C31 exist or not, bit2:C32 exist or not */    
    INT16         rxLev;       /**< Serving cell GSM received signal level.(-110..-30) */
    UINT8         bsic;        /**< Serving cell BSIC.(0..63)*/
    INT16         c1;          /**< Serving cell Path loss param C1*/
    INT16         c2;          /**< Serving cell Path loss param C2*/
    INT16         c31;         /**< Serving cell GPRS signal level threshold criterion param C31*/
    INT16         c32;         /**< Serving cell GPRS cell ranking criterion param C32*/
} CiDevGsmScellRadioInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmNcellSysInfo_struct
{
    UINT16         arfcn;    /**< GSM neigbour cell ARFCN (0..1023) */    
    UINT16         res1U16;  /**< (padding) */

    CiDevGsmBand   band;     /**< GSM neigbour cell current freq band */
    UINT8          bsic;     /**< GSM neigbour cell BSIC.(0..63)*/
    UINT16         ci;       /**< GSM Ncell identity */

    CiDevPlmnMcc   mcc;       /**< Mobile country code (3 digitals). \sa  CiDevPlmnMcc */
    CiDevPlmnMnc   mnc;       /**< Mobile network code (2 or 3 digitals). \sa  CiDevPlmnMnc */

    UINT16         lac;       /**< Location area code */
} CiDevGsmNcellSysInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmNcellRadioInfo_struct
{
    UINT8         fieldMap;    /**< bit0:C2 exist or not, bit1:C31 exist or not, bit2:C32 exist or not */
    INT16         c1;          /**< GSM neigbour cell Path loss param C1*/
    INT16         rxLev;       /**< GSM neigbour cell GSM received signal level.(-110..-30) */

    INT16         c2;          /**< GSM neigbour cell Path loss param C2*/
    INT16         c31;         /**< GSM neigbour cell GPRS signal level threshold criterion param C31*/
    INT16         c32;         /**< GSM neigbour cell GPRS cell ranking criterion param C32*/
} CiDevGsmNcellRadioInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmNcellInfoGsm_struct
{
    CiDevGsmNcellSysInfo    sysInfo;
    CiDevGsmNcellRadioInfo  radioInfo;
} CiDevGsmNcellInfoGsm;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmTdNcellInfoTdd_struct
{
    UINT8   cellParamId;         /**< Cell parameter id, (0..127) */
    UINT16  uArfcn;              /**< UARFCN, (0..16383), real frequency(MHz)=UARFCN/5  */
    UINT8   pccpchRSCP;          /**< PCCPCH RSCP, (0..91) real value(dbm)=IE value -116 */
    UINT8   utraRssi;            /**< UTRA carrier RSSI, (0..76) real value(dbm)=IE value - 101  */
} CiDevGsmNcellInfoTdd;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmNcellInfo_struct
{
    UINT8 numNcellGsm;
    CiDevGsmNcellInfoGsm   nbCellInfoGsm[CI_DEV_MAX_GSM_NEIGHBORING_CELLS];

    UINT8 res1U8[3];       /**< (padding) */
    UINT8 numNcellTdd;     /**<  Note: numNcellGsm+numNcellTdd <= CI_DEV_MAX_GSM_NEIGHBORING_CELLS */
    CiDevGsmNcellInfoTdd   nbCellInfoTdd[CI_DEV_MAX_GSM_NEIGHBORING_CELLS];
} CiDevGsmNcellInfo;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_SPEECH_CODE_TAG{
    CI_DEV_GSM_SPEECH_GSM_HR = 0,
    CI_DEV_GSM_SPEECH_GSM_FR,
    CI_DEV_GSM_SPEECH_GSM_EFR,
    CI_DEV_GSM_SPEECH_HR_AMR,
    CI_DEV_GSM_SPEECH_FR_AMR,

    CI_DEV_NUM_GSM_SPEECH
} _CiDevGsmSpeechCode;

typedef UINT8 CiDevGsmSpeechCode;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_DED_CHANNEL_TYPE_TAG{
    CI_DEV_GSM_DEDICATED_TCH = 0,
    CI_DEV_GSM_DEDICATED_SDCCH,
    CI_DEV_GSM_DEDICATED_PDCH,

    CI_DEV_NUM_GSM_DEDICATED_CHANNEL
} _CiDevGsmDedChannelType;

typedef UINT8 CiDevGsmDedChannelType;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmCellAlloc_struct
{
    UINT8         numCellAlloc; /**< The number of Cell Allocation.(1~64) */
    UINT16        cellAlloc[CI_DEV_MAX_GSM_NUM_CELL_ALLOCATION]; /**< Cell Allocation list.(0~1024) */
} CiDevGsmCellAlloc;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmDedArfcn_struct
{
    CiBoolean         hoppingChannel; /**< dedicated channel support arfcn hopping or not */
    UINT16            arfcn;          /**< absolute RF channel number. (0..1023) only exist when hoppingChannel=0 */
    CiDevHoppingGroup hoppingGroup;   /**< Hopping List, exist when hoppingChannel=1 */
    CiDevGsmCellAlloc cellAlloc;      /**< Cell Allocation*/

    UINT8             MAIO;           /**< mobile allocation index offset, (0..63) exist when hoppingChannel=1*/
    UINT8             HSN;            /**< hopping sequence number, (0..63) exist when hoppingChannel=1*/
} CiDevGsmDedArfcn;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmDedChannelInfo_struct
{
    UINT8                         fieldMap;        /**< Bit0:Ded_arfcn_beforetime;Bit1:Speech code used;Bit2:Ded_arfcn_after_time and tn */
    CiDevGsmDedArfcn              arfcnAfterTime;  /**< Arfcn of dedicated channel after starting timer  */

    UINT8                         tn;              /**< current dedicated maining link timeslot mapping(List of timeslots used.(0..7) */

    CiDevGsmSpeechCode            speechCode;      /**< Speech code used */
    CiDevGsmDedChannelType        channelType;     /**< Channel Type */

    CiDevGsmDedArfcn              arfcnBeforeTime; /**<  Arfcn of dedicated channel before starting timer */
} CiDevGsmDedChannelInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmDedMeasInfo_struct
{
    UINT8     sCellRxQualFull;    /**< Dedicated channel RXQUAL_FULL,(0..7)*/
    UINT8     sCellRxQualSub;     /**< Dedicated channel RXQUAL_SUB,(0..7)  */
    UINT8     sCellTimingAdv;     /**< TA,(0..63),0xff:invalid value */
    UINT8     sCellTxPower;       /**< power class of current dedicated channel */

    UINT8     sCellRxLevFull;     /**< service cell received signal level full,(0..63) invalid value 0xff,real value(dBm)=IE value-110 */
    UINT8     sCellRxLevSub;      /**< service cell received signal level sub,(0..63) invalid value 0xff,real value(dBm)=IE value-110 */
    UINT8     res1U8;             /**< (padding) */
    UINT8     bler;               /**< Block error rate for all code schemes. The actual ratio should be devided by 100.0xff:invalid value*/
} CiDevGsmDedMeasInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmTimeSlotCi_struct
{
    UINT8 tsNo;       /**< Timeslot */
    INT16 rxLev;
    INT16 ci;         /**< Bit0~bit7(LSB):decimal part,unsigned data; Bit8~bit15(LSB): integer part, signed data. */
} CiDevGsmTimeSlotCi;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmArfcnCiRep_struct
{
    UINT16       arfcn;      /**< BCCH Frequency,(0..1023) */
    CiDevGsmBand band;       /**< Frequency band */

    UINT8  numSlot;          /**< The number of slots which this arfcn has appeared at one time. (0..4) */
    CiDevGsmTimeSlotCi slotCiArray[CI_DEV_MAX_GSM_NUM_TIMESLOT];
} CiDevGsmArfcnCiRep;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmCIInfo_struct
{
    UINT8       repArfcnNum;      /**< The number of the arfcn reported.(0..64) */
    CiDevGsmArfcnCiRep data[CI_DEV_MAX_GSM_NUM_REPORTED_ARFCN];
} CiDevGsmCIInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmBepCvBepInfo_struct
{
    CiBoolean  isGmskValid;  /**< 0:GMSK_MEAN_BEP and GMSK_CV_BEP is absent; 1:GMSK_MEAN_BEP and GMSK_CV_BEP is present*/ 
    UINT8      gmskMeanBepCvBep;  /**< GMSK_MEAN_BEP: High 5 bits of 1 octet; GMSK_CV_BEP: Low 3bits of above octet*/

    CiBoolean  is8pskValid;  /**< 0:8PSK_MEAN_BEP and 8PSK_CV_BEP is absent; 1:8PSK_MEAN_BEP and 8PSK_CV_BEP is present*/ 
    UINT8      psk8MeanBepCvBep;  /**< 8PSK_MEAN_BEP: High 5 bits of 1 octet; 8PSK_CV_BEP: Low 3bits of above octet*/
} CiDevGsmBepCvBepInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmUlCsMcs_struct
{
    UINT32 frameNo;       /**< Frame number of this UL block */
    CiDevGsmCodingScheme  mcsCs;         /**< 7~10:CS1~CS4; 11~19:MCS1~MCS9 */
} CiDevGsmUlCsMcs;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmMcsCs_struct
{
    UINT8 tsNo;       /**< Timeslot of this DL block */
    CiDevGsmCodingScheme  mcsCs;         /**< 7~10:CS1~CS4; 11~19:MCS1~MCS9 */
} CiDevGsmMcsCs;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmDlCsMcs_struct
{
    UINT32 frameNo;       /**< Frame number of this DL block */

    UINT8  blkNum;        /**< The number of DL block received */
    CiDevGsmMcsCs  mcsCs[CI_DEV_MAX_GSM_DL_NUM_BLK];
} CiDevGsmDlCsMcs;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmMcsCsInfo_struct
{
    UINT8 ulLength;       /**< The number of UL_CS_MCS in peroid 1s*/
    CiDevGsmUlCsMcs    ulCsMcs[CI_DEV_MAX_GSM_UL_DL_CS_MCS];

    UINT8 dlLength;       /**< The number of DL_CS_MCS in peroid 1s*/
    CiDevGsmDlCsMcs    dlCsMcs[CI_DEV_MAX_GSM_UL_DL_CS_MCS];
} CiDevGsmMcsCsInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmTfiTimeslot_struct
{
    CiBoolean isUlTfiValid;    /**< 0:UL_TFI and UL timeslot allocation is absent; 1: UL_TFI and UL timeslot allocation is present*/
    UINT8     ulTfi;           /**< UL_TFI  */
    UINT8     ulTimeSlotAlloc; /**< UL timeslot allocation */

    CiBoolean isDlTfiValid;    /**< 0:DL_TFI and DL timeslot allocation is absent; 1: DL_TFI and DL timeslot allocation is present*/
    UINT8     dlTfi;           /**< DL_TFI*/
    UINT8     dlTimeSlotAlloc; /**< DL timeslot allocation */
} CiDevGsmTfiTimeslot;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmData_struct
{
    CiDevGsmScellSysInfo      sCellSysInfo;    /**< Serving cell system information. */
    UINT8 sCellSysInfoDtxInd;        /**< Serving cell reselection system information.
                                                                 (0..2), DTX indicator, 0:the MS may use uplink discontinous transmission,
                                                                                                1:the MS shall use uplink discontinous transmission,
                                                                                                2:the MS shall not use uplink discontinous transmission*/

    CiDevGsmScellRadioInfo    sCellRadioInfo;   /**< Serving cell radio information. */
    CiDevGsmNcellInfo         nCellInfo;        /**< Neighbour cell information. */

    CiDevGsmDedChannelInfo    dedChannelInfo;   /**< Dedicated channel information. */
    CiDevGsmDedMeasInfo       dedMeasInfo;      /**< Dedicated measurement information. */ 

    CiDevGsmCIInfo            ciInfo;           /**< C/I. */
    CiDevGsmBepCvBepInfo      bepCvBepinfo;     /**< BEP/CV BEP. */
    CiDevGsmMcsCsInfo         mscCsInfo;        /**< MCS/CS (up/down). */
    CiDevGsmTfiTimeslot       tfiTimeSlotInfo;  /**< TFI(up/down) and Timeslot Allocation(up/down). */
} CiDevGsmData;

//ICAT EXPORTED STRUCT
typedef struct CiDevMobileId_struct
{
    UINT8   digitSize;
    UINT8   digit[CI_MAX_IMEI_SV_LEN];
} CiDevMobileId;

//ICAT EXPORTED STRUCT
typedef struct CiDevUeId_struct
{
    CiDevMobileId  imei; /**< IMEI for 14~16 digit. \sa  CiDevMobileId */
    CiDevMobileId  imsi; /**< IMSI for 15 digit. \sa  CiDevMobileId */
    CiDevMobileId  tmsi; /**< TMSI for 4 Hex. \sa  CiDevMobileId */
    CiDevMobileId  ptmsi; /**< PTMSI for 4 Hex. \sa  CiDevMobileId */
} CiDevUeId;

//ICAT EXPORTED STRUCT
typedef struct CiDevMmInfo_struct
{
    CiDevPlmnMcc  mcc;  /**< Mobile country code (3 digitals). \sa  CiDevPlmnMcc */
    CiDevPlmnMnc  mnc;  /**< Mobile network code (2 or 3 digitals). \sa  CiDevPlmnMnc */

    UINT16  lac;    /**< Location area code */
    UINT16  res1U16;  /**< (padding) */
} CiDevMmInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonData_struct
{
    CiDevUeId      ueId;      /**< UE ID */
    CiDevMmInfo    mmInfo;    /**< MM inforamtion */
} CiDevCommonData;

//ICAT EXPORTED STRUCT
typedef struct CiDevWirelessParam_struct
{
    CiDevTddData     tddInfo;    /**< TDSCDMA parameters  */
    CiDevCommonData  commonInfo; /**< Common parameters  */
    CiDevGsmData     gsmInfo;    /**< GSM parameters  */
} CiDevWirelessParam;

//ICAT EXPORTED ENUM
typedef enum CIDEV_SYSTEM_INFO_TYPE_TAG {
    CI_DEV_SYS_INFO_TYPE_MIB = 0,
    CI_DEV_SYS_INFO_TYPE_SB1,
    CI_DEV_SYS_INFO_TYPE_SB2,
    CI_DEV_SYS_INFO_TYPE1,
    CI_DEV_SYS_INFO_TYPE2,
    CI_DEV_SYS_INFO_TYPE3,
    CI_DEV_SYS_INFO_TYPE4,
    CI_DEV_SYS_INFO_TYPE5,
    CI_DEV_SYS_INFO_TYPE6,
    CI_DEV_SYS_INFO_TYPE7,
    CI_DEV_SYS_INFO_TYPE8,
    CI_DEV_SYS_INFO_TYPE9,
    CI_DEV_SYS_INFO_TYPE10,
    CI_DEV_SYS_INFO_TYPE11,
    CI_DEV_SYS_INFO_TYPE12,
    CI_DEV_SYS_INFO_TYPE13,
    CI_DEV_SYS_INFO_TYPE13_1,
    CI_DEV_SYS_INFO_TYPE13_2,
    CI_DEV_SYS_INFO_TYPE13_3,
    CI_DEV_SYS_INFO_TYPE13_4,
    CI_DEV_SYS_INFO_TYPE14,
    CI_DEV_SYS_INFO_TYPE15,
    CI_DEV_SYS_INFO_TYPE15_1,
    CI_DEV_SYS_INFO_TYPE15_2,
    CI_DEV_SYS_INFO_TYPE15_3,
    CI_DEV_SYS_INFO_TYPE15_4,
    CI_DEV_SYS_INFO_TYPE15_5,
    CI_DEV_SYS_INFO_TYPE16,
    CI_DEV_SYS_INFO_TYPE17,
    CI_DEV_SYS_INFO_TYPE18,
    CI_DEV_SYS_INFO_TYPE5bis,

    CI_DEV_NUM_SYS_FINO
} _CiDevSystemInfoType;

typedef UINT8 CiDevSystemInfoType;

//ICAT EXPORTED STRUCT
typedef struct CiDevBcchFachParam_struct
{
    UINT8     rbId;  /**< Rb identity. Value 34, It is used for message from FACH to BCCH*/
    UINT16    noTb;  /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI, beased on the TFI value*/
} CiDevBcchFachParam;

//ICAT EXPORTED STRUCT
typedef struct CiDevPcchPchParam_struct
{
    UINT8     rbId;   /**< Rb identity. Value 33, It is used for message from PCH to PCCH*/
    UINT16    noTb;   /**< Indicates the number of transport blocks transmitted by the peer entity within the TTI, beased on the TFI value*/
} CiDevPcchPchParam;

//ICAT EXPORTED STRUCT
typedef struct CiDevAmDataInd_struct
{
    UINT8     fieldInd;  /**< Indicate the presence or absence of peer_msg and disc_info. 01:peer_msg exists; 02:disc_info exists*/
    UINT16    discInfo;  /**< Indicates to ULR the discarded RLC SDU in the peer-RLC AM entity. 0~65535*/
} CiDevAmDataInd;

//ICAT EXPORTED STRUCT
typedef struct CiDevTmDataInd_struct
{
    CiBoolean errIndFlag;  /**< Indicate the presence or absence of error_ind. 1means exists. When"err_SDU_delv" is configured as YES and 
                                                      there are SDUs received in error, the err_ind parameter is present*/
    UINT8     errInd;      /**< Indicates that the RLC SDU is erroneous*/
} CiDevTmDataInd;

//ICAT EXPORTED STRUCT
typedef struct CiDevDataIndPara_struct
{
    UINT8     rlcMode;  /**< RLC mode. 1:AM;2:UM;3:TM; Other values are reserved*/

    union
    {
      CiDevAmDataInd  dlAmData;
      CiDevTmDataInd  dlTmData;
    }dataIndPara;
} CiDevDataIndPara;

//ICAT EXPORTED STRUCT
typedef struct CiDevDlCchParam_struct
{
    UINT8     rbId;  /**< Rb identity. 0:CCCH;1~32:DCCH;36:MCCH*/
    CiDevDataIndPara    dataIndPara;  /**<  \sa CiDevDataIndPara */
} CiDevDlCchParam;

//ICAT EXPORTED STRUCT
typedef struct CiDevAmDataReq_struct
{
    CiBoolean cnfReq;   /**< If the value is true, uplayer requests RLC to confirm the reception of RLC SDUs by te peer-RLC AM entity. 
                                                  If the value is false, no confirmation is requested*/
    CiBoolean fieldInd; /**< Indicate the presence or absence of MUI. When disc_req and CNF are both false, MUI does not exist. other situation, MUI exists.*/
    UINT16    mui;      /**< RLC shall give discarded info using this identifier for SDU. MUI: 0~65535*/
} CiDevAmDataReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevUmDataReq_struct
{
    UINT16    mui;  /**< RLC shall give discarded info using this identifier for SDU. MUI: 0~65535*/
} CiDevUmDataReq;

//ICAT EXPORTED STRUCT
typedef struct CiDevTmDataReq_struct
{
    UINT16    mui;  /**< RLC shall give discarded info using this identifier for SDU. MUI: 0~65535*/
} CiDevTmDataReq;

typedef struct CiDevDataReqPara_struct
{
    UINT8     rlcMode;  /**< RLC mode. 1:AM;2:UM;3:TM; Other values are reserved*/

    union
    {
      CiDevAmDataReq  dlAmData;
      CiDevUmDataReq  dlUmData;
      CiDevTmDataReq  dlTmData;
    }dataReqPara;
} CiDevDataReqPara;

//ICAT EXPORTED STRUCT
typedef struct CiDevUlCchParam_struct
{
    UINT8     rbId;    /**< Rb identity. 0~32*/
    CiBoolean discReq;  /**< If the value is true, uplink layer requests RLC for the discarded RLC SDU by local entity.
                                                  If the value if false,no discarded RLC SDU is requested*/
    CiDevDataReqPara    dataReqPara;  /**<  \sa CiDevDataReqPara */
} CiDevUlCchParam;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_CHANNEL_TYPE_TAG {
    CI_DEV_GSM_PBCCH = 1,
    CI_DEV_GSM_PRACH,
    CI_DEV_GSM_PCCCH,
    CI_DEV_GSM_PDTCH,
    CI_DEV_GSM_PACCH,
    CI_DEV_GSM_BCCH,
    CI_DEV_GSM_N_BCCH,
    CI_DEV_GSM_E_BCCH,
    CI_DEV_GSM_CCCH,
    CI_DEV_GSM_PAG_CH,
    CI_DEV_GSM_RACH,
    
    CI_DEV_GSM_SDCCH,
    CI_DEV_GSM_SDCCH4_0,  /**< SDCCH/4 subchannel number 0*/
    CI_DEV_GSM_SDCCH4_1,  /**< SDCCH/4 subchannel number 1*/
    CI_DEV_GSM_SDCCH4_2,  /**< SDCCH/4 subchannel number 2*/
    CI_DEV_GSM_SDCCH4_3,  /**< SDCCH/4 subchannel number 3*/
    CI_DEV_GSM_SDCCH8_0,  /**< SDCCH/8 subchannel number 0*/
    CI_DEV_GSM_SDCCH8_1,  /**< SDCCH/8 subchannel number 1*/
    CI_DEV_GSM_SDCCH8_2,  /**< SDCCH/8 subchannel number 2*/
    CI_DEV_GSM_SDCCH8_3,  /**< SDCCH/8 subchannel number 3*/
    CI_DEV_GSM_SDCCH8_4,  /**< SDCCH/8 subchannel number 4*/
    CI_DEV_GSM_SDCCH8_5,  /**< SDCCH/8 subchannel number 5*/
    CI_DEV_GSM_SDCCH8_6,  /**< SDCCH/8 subchannel number 6*/
    CI_DEV_GSM_SDCCH8_7,  /**< SDCCH/8 subchannel number 7*/
    
    CI_DEV_GSM_SACCH,
    CI_DEV_GSM_FACCH,
    CI_DEV_GSM_TCH_F,
    CI_DEV_GSM_TCH_H_0,  /**< TCH/H subchannel number 0*/
    CI_DEV_GSM_TCH_H_1,  /**< TCH/H subchannel number 1*/

    CI_DEV_GSM_PPCH,
    CI_DEV_GSM_ETCH_F,
    CI_DEV_GSM_ATCH_F,
    CI_DEV_GSM_ATCH_H,
    CI_DEV_GSM_EIACCH_F,
    CI_DEV_GSM_CBCH_4,
    CI_DEV_GSM_CBCH_8,

    CI_DEV_NUM_GSM_CHANNEL
} _CiDevGsmChannelType;

typedef UINT8 CiDevGsmChannelType;

//ICAT EXPORTED ENUM
typedef enum CIDEV_GSM_BURST_TYPE_TAG {
    CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_8_BITS = 0,
    CI_DEV_GSM_ONE_ACCESS_BURST_OF_TYPE_11_BITS,
    CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_8_BITS,
    CI_DEV_GSM_FOUR_ACCESS_BURST_OF_TYPE_11_BITS,
    CI_DEV_GSM_FREQUENCY_CORRECTION_BURST,
    CI_DEV_GSM_SYNCHRONIZATION_BURST,
    CI_DEV_GSM_DUMMY_BURST,
    CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST,
    CI_DEV_GSM_NORMAL_CS_2_RADIO_BLK_BURST,
    CI_DEV_GSM_NORMAL_CS_3_RADIO_BLK_BURST,
    CI_DEV_GSM_NORMAL_CS_4_RADIO_BLK_BURST,
    CI_DEV_GSM_NORMAL_BURST = CI_DEV_GSM_NORMAL_CS_1_RADIO_BLK_BURST,
    
    CI_DEV_NUM_GSM_BURST
} _CiDevGsmBurstType;

typedef UINT8 CiDevGsmBurstType;
typedef UINT8 CiDevGsmSignalName;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmParam_struct
{
    CiBoolean     isBadFrame;    /**< 1: bad frame; 0:not bad frame*/
    CiBoolean     isUpDownData;  /**< 1: uplink data; 0:downlink data*/
    CiBoolean     isNasMsg;      /**< 1: nas message; 0:not nas message*/

    CiDevGsmChannelType   chType;   /**<  \sa CiDevGsmChannelType */
    CiDevGsmCodingScheme  cs;       /**<  \sa CiDevGsmCodingScheme */
    CiDevGsmBurstType burstType;    /**<  \sa CiDevGsmBurstType */
    CiDevGsmSignalName signalName;  /*add for GSM message decode*/
	
    UINT8 sapi;        /**< sapi=0 or sapi=3, other reserved */
} CiDevGsmParam;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_REQ">   */
typedef struct CiDevPrimSetNetworkMonitorOptReq_struct
{
    CiBoolean Option;         /**<  Always hard coded with zero. \sa CiBoolean  */
    CiDevNwMonitorMode  Mode;       /**< Report mode. \sa CiDevNwMonitorMode */
} CiDevPrimSetNetworkMonitorOptReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_NETWORK_MONITOR_OPTION_CNF">   */
typedef struct CiDevPrimSetNetworkMonitorOptCnf_struct
{
    CiDevRc rc;        /**< Result code. \sa  CiDevRc */
    UINT8   res1U8[2]; /**< (padding) */
} CiDevPrimSetNetworkMonitorOptCnf;

/** <paramref name="CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_REQ">   */
typedef CiEmptyPrim CiDevPrimGetNetworkMonitorOptReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_NETWORK_MONITOR_OPTION_CNF">   */
typedef struct CiDevPrimGetNetworkMonitorOptCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    CiBoolean Option;         /**<  Always hard coded with zero. \sa CiBoolean  */
    CiDevNwMonitorMode  Mode;       /**< Report mode. \sa CiDevNwMonitorMode */
} CiDevPrimGetNetworkMonitorOptCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_REQ">   */
typedef struct CiDevPrimSetProtocolStatusConfigReq_struct
{
    CiBoolean    Option;         /**<  0: disable unsolicited result code(default); 1:enable unsolicited result code*/
} CiDevPrimSetProtocolStatusConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_PROTOCOL_STATUS_CONFIG_CNF">   */
typedef struct CiDevPrimSetProtocolStatusConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    UINT8   res1U8[2];  /**< (padding) */
} CiDevPrimSetProtocolStatusConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetProtocolStatusConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_PROTOCOL_STATUS_CONFIG_CNF">   */
typedef struct CiDevPrimGetProtocolStatusConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    CiBoolean  Option;  /**<  0: disable unsolicited result code(default); 1:enable unsolicited result code*/
} CiDevPrimGetProtocolStatusConfigCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_PROTOCOL_STATUS_CHANGED_IND">   */
typedef struct CiDevPrimProtocolStatusChangedInd_struct
{
    CiDevProtocolStatus status;     /**< Protocol status. \sa CiDevProtocolStatus */
    UINT8   res1U8[3];   /**< (padding) */
} CiDevPrimProtocolStatusChangedInd;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_EVENT_IND_CONFIG_REQ">   */
typedef struct CiDevPrimSetEventIndConfigReq_struct
{
    CiBoolean    Option;         /**<  0: disable intermediate result code(default); 1:enable intermediate result code*/
} CiDevPrimSetEventIndConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_EVENT_IND_CONFIG_CNF">   */
typedef struct CiDevPrimSetEventIndConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    UINT8   res1U8[2];  /**< (padding) */
} CiDevPrimSetEventIndConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_EVENT_IND_CONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetEventIndConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_EVENT_IND_CONFIG_CNF">   */
typedef struct CiDevPrimGetEventIndConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    CiBoolean  Option;  /**<  0: disable unsolicited result code(default); 1:enable unsolicited result code*/
} CiDevPrimGetEventIndConfigCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_EVENT_REPORT_IND">   */
typedef struct CiDevPrimEventReportInd_struct
{
    UINT32       timeStamp;       /**< System tick value, (0,4294967295).*/
    CiBitRange   operationType;   /**< Operation type, bitmap - bit0:CS voice;bit1:CS data;bit2:PS;bit3:SMS \sa CiDevEventOperType */
    CiDevEventId eventId;         /**< Event ID.*/
} CiDevPrimEventReportInd;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_REQ">   */
typedef struct CiDevPrimSetWirelessParamConfigReq_struct
{
    CiBoolean    Option;         /**<  0: disable result code presentation to TE(default); 1:enable result code presentation to TE*/
    UINT16       Interval;       /**< Report Interval (seconds) for PERIODIC, default 3s */
} CiDevPrimSetWirelessParamConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_WIRELESS_PARAM_CONFIG_CNF">   */
typedef struct CiDevPrimSetWirelessParamConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    UINT8   res1U8[2];  /**< (padding) */
} CiDevPrimSetWirelessParamConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetWirelessParamConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_WIRELESS_PARAM_CONFIG_CNF">   */
typedef struct CiDevPrimGetWirelessParamConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    CiBoolean    Option;         /**<  0: disable result code presentation to TE(default); 1:enable result code presentation to TE*/
    UINT16       Interval;       /**< Report Interval (seconds) for PERIODIC, default 3s */
} CiDevPrimGetWirelessParamConfigCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_WIRELESS_PARAM_IND">   */
typedef struct CiDevPrimWirelessParamInd_struct
{
    CiDevEngModeNetwork network;  /**< Network Type (GSM/UMTS). \sa CiDevEngModeNetwork */

    UINT32       timeStamp;       /**< System tick value, (0,4294967295).*/

    CiDevCommonData  commonInfo;  /**< Common parameters  */

    UINT32       data_size;       /**< Size of data for CiDevTddData/CiDevGsmData */
    UINT8        tddGsmData[CI_DEV_MAX_WIRELESS_DATA_LENGTH];    /**< data for CiDevTddData/CiDevGsmData */
    UINT8        count;           /**< Ordinal number of the data. [range:1-2]  */     
} CiDevPrimWirelessParamInd;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_REQ">   */
typedef struct CiDevPrimSetSignalingReportConfigReq_struct
{
    CiBoolean    Option;       /**<  0: disable unsolicited result code(default); 1:enable unsolicited result code*/
    CiBoolean    Mode;         /**<  0: disable Uu signaling report(default); 1:enable Uu signaling report*/    
} CiDevPrimSetSignalingReportConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_SIGNALING_REPORT_CONFIG_CNF">   */
typedef struct CiDevPrimSetSignalingReportConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    UINT8   res1U8[2];  /**< (padding) */
} CiDevPrimSetSignalingReportConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetSignalingReportConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_SIGNALING_REPORT_CONFIG_CNF">   */
typedef struct CiDevPrimGetSignalingReportConfigCnf_struct
{
    CiDevRc rc;         /**< Result code. \sa  CiDevRc */
    CiBoolean    Option;       /**<  0: disable unsolicited result code(default); 1:enable unsolicited result code*/
    CiBoolean    Mode;         /**<  0: disable Uu signaling report(default); 1:enable Uu signaling report*/    
} CiDevPrimGetSignalingReportConfigCnf;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SIGNALING_REPORT_IND">   */
typedef struct CiDevPrimSignalingReportInd_struct
{
    UINT16       totalMsglen;     /**< The total message length = parameter length + peer message length + 17 */
    UINT8        frameType;       /**< The type of freame, 0xAA: used for trace data; others: reserved.*/

    CiDevSignalingMsgId msgId;    /**< The message identifier. \sa CiDevSignalingMsgId */
    UINT32       timeStamp;       /**< Timrt counter, Unit:ms, the value would be set to 0 when power on.*/

    UINT16       paramLen;        /**< The length of the parameter data in byte, the length can be zero, in such case, the parameter would include nother */
    union
    {
      CiDevSystemInfoType bchParam;
      CiDevBcchFachParam  bcchFachParam;      
      CiDevPcchPchParam   pcchPchParam;
      CiDevDlCchParam     dlCchParam;
      CiDevUlCchParam     ulCchParam;
      CiDevGsmParam       gsmParam;
    }paramData;

    UINT16   peerMsgLen;         /**< The length of the peer message in byte */
    UINT16   freeHeaderSpaceLen; /**< The length of the free bit header space in bit. It is said the number of the free header space length bits is just filled for alignment, and not usefull */
    UINT8    peerMsgData[CI_DEV_MAX_PEER_MSG_LENGTH];         /**< Peer message encoded with ASN.1.*/
} CiDevPrimSignalingReportInd;
/*Mason CMCC Smart Network Monitor support -- END*/

/*Alan DIP Channel support -- START*/
typedef UINT16 Arfcn; 

/** <paramref name="CI_DEV_PRIM_DIP_CHANNEL_CHANGE_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimDipChannelChangeInd_struct
{
    CiDevNetworkMode    networkMode; //0: CI_DEV_NW_GSM; 1:CI_DEV_NW_UMTS; 3: CI_DEV_NW_LTE
    /*Arfcn*/UINT32     arfcn; /*Lilei, CQ00073839, 20141023*/
    CiDevBand           band; //band: Dip band GSM : 0: EGSM 1:DCS 2:PCS 6:GSM850;WCDMA:1: BAND1; 2:BAND2;...;14:BAND14; LTE: 1: BAND1; 2: BAND2...
	CiDevServiceType    servicetype;
/*Added by Lilei for CQ58144 on 04032014, begin*/
    UINT8               dipOption; //0: disable; 1: enable manual mode for special case (such as test model)-default one; 2: enable manual mode for user model; 3: enable auto mode for end user (not used)
/*Added by Lilei for CQ58144 on 04032014, end*/
/*Added by Lilei for CQ58144 on 04292014, begin*/
    CiBoolean           LpmEnabled; //0: Lpm disabled; 1: Lpm enabled
/*Added by Lilei for CQ58144 on 04292014, end*/
} CiDevPrimDipChannelChangeInd;
/*Alan DIP Channel support -- END*/

/*Michal Bukai - Security Configuration - Samsung - START*/
/*********************************************************/
/** <paramref name="CI_DEV_PRIM_SET_SECURITY_PARAMS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSecurityParamsReq_struct{
	CiBoolean       EnableCiphering;                /**< TRUE - ciphering capabilities are derived from NVM; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */
	CiBoolean       EnableIntegrityProtection;      /**< TRUE - integrity protection capabilities are derived from NVM; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */
} CiDevPrimSetSecurityParamsReq;

/** <paramref name="CI_DEV_PRIM_SET_SECURITY_PARAMS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSecurityParamsCnf_struct{
    CiDevRc rc;	    /**< Result code. \sa CiDevRc. */
} CiDevPrimSetSecurityParamsCnf;

/** <paramref name="CI_DEV_PRIM_GET_SECURITY_PARAMS_REQ">   */
typedef CiEmptyPrim CiDevPrimGetSecurityParamsReq;


/** <paramref name="CI_DEV_PRIM_GET_SECURITY_PARAMS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSecurityParamsCnf_struct{
    CiDevRc         rc;	                            /**< Result code. \sa CiDevRc. */
    CiBoolean       EnableCiphering;                /**< TRUE - ciphering capabilities are derived from NVM; FALSE - ciphering capabilities are disabled. \sa CCI API Ref Manual */
	CiBoolean       EnableIntegrityProtection;      /**< TRUE - integrity protection capabilities are derived from NVM; FALSE - integrity protection capabilities are disabled. \sa CCI API Ref Manual */
} CiDevPrimGetSecurityParamsCnf;
/*Michal Bukai - Security Configuration - Samsung - END*/


//ICAT EXPORTED ENUM
/*add by taow 20180920 begin*/
typedef enum CIDEV_SET_POWER_BACK_OFF_TYPE_TAG{
    CI_DEV_POWER_BACK_OFF = 0,      // for grip sensor control
    CI_DEV_POWER_BACK_ON = 1,       // for grip sensor control
    CI_DEV_POWER_REDUCTION = 2,     // for temperature control
    CI_DEV_POWER_RAISING = 3,       // for temperature control
    CI_DEV_POWER_PCLFIX = 4, 		// for PCLFIX
    
    CI_DEV_UNLOCK_FREQUENCY = 8,    // for frequency unthrottle
    CI_DEV_LOCK_FREQUENCY = 9,      // for frequency throttle
    
    CI_DEV_NUM_OF_POWER_BACK_OFF_TYPES
}_CiDevSetPowerBackOffType;
typedef UINT8 CiDevSetPowerBackOffType;
/*add by taow 20180920 end*/

/*Add by Alan for Power BackOff  04082013, begin*/
//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_POWER_BACK_OFF_REQ">   */
typedef struct CiDevPrimSetPowerBackOffReq_struct
{
    CiDevSetPowerBackOffType    PowerBackOffType;
    UINT8                       value;  /**< Specific value for certain type, such as power reduction/raising */
    /*Lilei, CQ00124125, 20200914, begin*/
    CiDevEngModeNetwork         networkMode; /**< 0: GSM; 1: UMTS; 2: LTE; 6: all modes & bands (default) */
    UINT8                       band;   /**< GSM: 0-PGSM,1-DCS,2-PCS,3-EGSM,4-GSM450,5-GSM480,6-GSM850;
                                                                                 WCDMA: 1-BAND1,2-BAND2,...,14:BAND14;  LTE: 1-BAND1,2-BAND2... 
                                                                                  If mode is 0/1/2 (single mode), band=0xFF means all bands. 
                                                                                  If mode is 6 (multi-mode), band is not used.*/
    /*Lilei, CQ00124125, 20200914, end*/
	/*Lilei, CQ00137338, 20220621, begin*/
    UINT8                       bandwidth;  /**< 0: invalid; 1: 1.4MHz; 2: 3MHz; 3: 5MHz; 4: 10MHz; 5: 15MHz; 6: 20MHz; If bandwidth > 0, then <value> is in 0.1Db unit*/
    /*Lilei, CQ00137338, 20220621, end*/
    UINT32                      reserved1;
    UINT32                      reserved2;
    UINT32                      reserved3;
    UINT32                      reserved4;
} CiDevPrimSetPowerBackOffReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_SET_POWER_BACK_OFF_CNF">   */
typedef struct CiDevPrimSetPowerBackOffCnf_struct
{
    CiDevRc rc;      /**< Result code. \sa  CiDevRc */  
} CiDevPrimSetPowerBackOffCnf;
/*Add by Alan for Power BackOff  04082013, end*/

#define CI_DEV_MAX_REVISION_LENGTH 400

//ICAT EXPORTED STRUCT
typedef struct CiDevRevision_struct{
    UINT16      len; 
    CHAR        valStr[CI_DEV_MAX_REVISION_LENGTH];
}CiDevRevision;

/** <paramref name="CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_REQ">   */
typedef CiEmptyPrim CiDevPrimGetInternalRevisionIdReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_GET_INTERNAL_REVISION_ID_CNF">   */
typedef struct CiDevPrimGetInternalRevisionIdCnf_struct{
    CiDevRc         rc;                      /**< Result code   \sa CiDevRc */
    CiDevRevision   internalRevisionStr;     /**< Internal Revision ID string. Max length is 100. \sa CCI API Ref Manual  */
    CiString        buildTimeStr;            /**< Build Time string. Max length is 100. \sa CCI API Ref Manual  */
} CiDevPrimGetInternalRevisionIdCnf;

//ICAT EXPORTED ENUM
/** \brief Mode of requested reset*/
typedef enum CIDEVRESETMODETYPE_TAG{
	CI_DEV_RESET_FUN,				/**< Perform Functionality reset (CFUN=0 - CFUN=1) */
	CI_DEV_RESET_HW					/**< Perform com hardware reset */
} _CiDevResetModeType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Mode of requested reset
 * \sa CIDEVRESETMODETYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevResetModeType;
/**@}*/

/** <paramref name="CI_DEV_PRIM_RESET_REQUEST_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimResetRequestInd_struct{
	CiDevResetModeType	reset_mode;
} CiDevPrimResetRequestInd;

/** <paramref name="CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetUsertestReportOptionReq_struct{
	CiBoolean	enable;		/**< TRUE - Set User Testing reporting to ON; FALSE - Set User Testing reporting to OFF. */
	UINT8		reserved[3];
}CiDevPrimSetUsertestReportOptionReq;

/** <paramref name="CI_DEV_PRIM_SET_USER_TEST_REPORT_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetUsertestReportOptionCnf_struct{
	CiDevRc		rc;		/**< Result code. \sa CiDevRc. */
}CiDevPrimSetUsertestReportOptionCnf;

/** <paramref name="CI_DEV_PRIM_USER_TEST_VALUABLE_EVENT_REPORT_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUsertestValuableEventReportInd_struct{
	UINT32		initiator;	/**< Event initiator environment. */
	UINT32		eventType;	/**< Type of valuable event (severity, etc.). */
	CiString	eventDescription;	/**< Event description as ASCII string. */
	CiBoolean	includeSdLog;		/**< Indicates if SD log should be sent to user test server. */
	UINT8		reserved[3];
	UINT32		binaryLogSize;		/**< Indicates how many bytes (if any) are used by binaryLog array. */
	UINT8		binaryLog[1024];		/**< User supplied binary log. */
}CiDevPrimUsertestValuableEventReportInd;

/** <paramref name="CI_DEV_PRIM_SET_PARK_MODE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetParkModeReq_struct{
	CiBoolean	enableParkMode;			/**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */
	UINT8		roamingTimer;			/**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */
	UINT8		emergencyTimer;			/**< timer value for PLMN search in limited service state (emergency only). This override the default value \sa CCI API Ref Manual */
	UINT8		oosTimer;				/**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */
} CiDevPrimSetParkModeReq;

/** <paramref name="CI_DEV_PRIM_SET_PARK_MODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetParkModeCnf_struct{
	CiDevRc         rc;	                            /**< Result code. \sa CiDevRc. */
} CiDevPrimSetParkModeCnf;

/** <paramref name="CI_DEV_PRIM_GET_PARK_MODE_REQ">   */
typedef CiEmptyPrim CiDevPrimGetParkModeReq;

/** <paramref name="CI_DEV_PRIM_GET_PARK_MODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetParkModeCnf_struct{
	CiDevRc		rc;						/**< Result code. \sa CiDevRc. */
	CiBoolean	enableParkMode;			/**< TRUE - enables park mode. FALSE disables park mode. \sa CCI API Ref Manual */
	UINT8		roamingTimer;			/**< timer value for PLMN search in roaming state. This override the default value \sa CCI API Ref Manual */
	UINT8		emergencyTimer;			/**< timer value for PLMN search in limited service state (emergency only). This override the default value \sa CCI API Ref Manual */
	UINT8		oosTimer;				/**< timer value for PLMN search in out of service state. This override the default value \sa CCI API Ref Manual */
} CiDevPrimGetParkModeCnf;

/** <paramref name="CI_DEV_PRIM_SET_IMS_MEDIA_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetIMSMediaReq_struct{
    UINT32      requestId;                              /**< Media request identifier */
    UINT32      inBufSize;                              /**< Media API input parameter length  */
    UINT8       inBuf[CI_DEV_MAX_IMS_MEDIA_REQ_BUF];    /**< array of char of length InBufSize  */
} CiDevPrimSetIMSMediaReq;

/** <paramref name="CI_DEV_PRIM_SET_IMS_MEDIA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetIMSMediaCnf_struct{
    CiDevRc     rc;				                        /**< Result code  \sa CiDevRc */
    UINT32      retCode;                               /**< Return Code Value */
    UINT32      outBufSize;                             /**< Media API input parameter length  */
    UINT8       outBuf[CI_DEV_MAX_IMS_MEDIA_REQ_BUF];   /**< array of char of length OutBufSize  */
} CiDevPrimSetIMSMediaCnf;

/** <paramref name="CI_DEV_PRIM_IMS_MEDIA_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimIMSMediaInd_struct{
    UINT32      notifyCode;                         /**< Media notification identifier  */
    UINT32      bufSize;                            /**< Media API parameter length  */
    UINT8       buf[CI_DEV_MAX_IMS_MEDIA_REQ_BUF];  /**< array of char of length BufSize  */
} CiDevPrimIMSMediaInd;

//ICAT EXPORTED ENUM
/** \brief Com Config types */
/** \remarks Common Data Section */
typedef enum CIDEV_COMCFG_TOKEN_TYPE{
			
    CI_DEV_COMCFG_TOKEN_UMTS_WB_AMR = 0,     
    CI_DEV_COMCFG_TOKEN_GSM_WB_AMR,          
    //CI_DEV_COMCFG_TOKEN_HSDPA,          
    //CI_DEV_COMCFG_TOKEN_HSUPA,          
    CI_DEV_COMCFG_TOKEN_VENDOR,          
    CI_DEV_COMCFG_TOKEN_MANUFACTURE,          
/*Added by Lilei for LTE category on 05282014, begin*/
    CI_DEV_COMCFG_TOKEN_LTE_CATEGORY,
/*Added by Lilei for LTE category on 05282014, end*/
    /*Lilei, CQ00124026, 20200910, begin*/
    CI_DEV_COMCFG_TOKEN_MULTISLOT_POWERPROFILE = 5,
    /*Lilei, CQ00124026, 20200910, end*/
	
    CI_DEV_COMCFG_TOKEN_LTE_SMS_ONLY,/*presentation of SMS only for additional update type in ATTACH reqest or TAU*/

    CI_DEV_COMCFG_TOKEN_EC_SUPPORTED,/*presentation of restriction of enhanced coverage in ATTACH reqest or TAU, 0: not supported, EC is restrited; 1: supported, EC is not restricted */
    CI_DEV_COMCFG_TOKEN_EPCO_SUPPORTED, /* 0 - ePCO not support, 1 - ePCO support */    
    CI_DEV_COMCFG_TOKEN_HCCP_SUPPORTED, /* 0 - HC-CP CIoT not support, 1 - HC-CP CIoT support */
    CI_DEV_COMCFG_TOKEN_MDRB_SUPPORTED = 10, /* 0 - multipleDRB not support, 1 - multipleDRB support */
    CI_DEV_COMCFG_TOKEN_CP_BACKOFF,     /* 0 - CP backoff not support, 1 - CP backoff support */

    CI_DEV_COMCFG_TOKEN_NSLP,   /* bitmap: bit 0 - nasSigLowPriority, bit 1 - overrideNasSignallingPriority */
	CI_DEV_COMCFG_TOKEN_EAB, 	/* bitmap: bit 0 - extendedAccessBarring, 1 - overrideExtendedAccessBarring */
	
	CI_DEV_COMCFG_TOKEN_ROHC, 	/*RoHC profiles, bitmap: bit 0~8, profile 0x0001/0x0002/0x0003/0x0004/0x0006/0x0101/0x0102/0x0103/0x0104 */
    /*Lilei, CQ00147330, 20231201, begin*/
    CI_DEV_COMCFG_TOKEN_ATTACH_WO_PDN = 15,  /* 0 - attachWithoutPdn not support, 1 - attachWithoutPdn support */
    /*Lilei, CQ00147330, 20231201, end*/

    CI_DEV_NUM_COMCFG_TOKEN

} _CiDevComcfgTokenType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Com Config types
 * \sa CIDEV_COMCFG_TOKEN_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiDevComcfgTokenType;
/**@}*/

//ICAT EXPORTED ENUM
/** \brief Vendor types */
/** \remarks Common Data Section */
typedef enum CIDEV_COMCFG_VENDOR_TYPE{
			
    CI_DEV_COMCFG_VENDOR_NONE = 0,     
    CI_DEV_COMCFG_VENDOR_ATT,          
    CI_DEV_COMCFG_VENDOR_CMCC,
    CI_DEV_COMCFG_VENDOR_IOT,     /**< it is not for vendor specific, just for some implements such as CC redial*/
    CI_DEV_COMCFG_VENDOR_TELCEL,
    CI_DEV_COMCFG_VENDOR_H3G,
    CI_DEV_COMCFG_VENDOR_VDF,
    CI_DEV_COMCFG_VENDOR_SILVER,  /**< it is not for vendor specific, just for some implements of MANUFACTURE*/
    CI_DEV_COMCFG_VENDOR_ORG,
    CI_DEV_COMCFG_VENDOR_TMOBILE,
    CI_DEV_COMCFG_VENDOR_VERIZON,
    CI_DEV_COMCFG_VENDOR_HP,
/*Added by Lilei for CQ58190 on 04042014, begin*/
    CI_DEV_COMCFG_VENDOR_CLOSE_RAMLOG_SWITCH,   /**< it is not for vendor specific, just for some implements */
    CI_DEV_COMCFG_VENDOR_2G_ROAMING,
    CI_DEV_COMCFG_VENDOR_RRM,
    CI_DEV_COMCFG_VENDOR_CMCC_FRSUPPORT,
    CI_DEV_COMCFG_VENDOR_SILENTRESET,           /**< it is not for vendor specific, just for some implements */
    CI_DEV_COMCFG_VENDOR_PSOPT,                 /**< it is not for vendor specific, just for some implements */
    CI_DEV_COMCFG_VENDOR_HOMETEST,
    CI_DEV_COMCFG_VENDOR_MTNET,
/*Added by Lilei for CQ58190 on 04042014, end*/
    CI_DEV_COMCFG_VENDOR_DEUTSCHETELE,
    CI_DEV_COMCFG_VENDOR_CMCC_5MODE_ROAMING,
    
    CI_DEV_NUM_COMCFG_VENDOR_TYPE

} _CiDevComcfgVendorType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Vendor types
 * \sa CIDEV_COMCFG_VENDOR_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiDevComcfgVendorType;
/**@}*/

//ICAT EXPORTED ENUM
/** \brief Manufacture types */
/** \remarks Common Data Section */
typedef enum CIDEV_COMCFG_MANUFACTURE_TYPE{
			
    CI_DEV_COMCFG_MANUFACTURE_NONE = 0,     
    CI_DEV_COMCFG_MANUFACTURE_M_SILVER,          
       
    CI_DEV_NUM_COMCFG_MANUFACTURE_TYPE

} _CiDevComcfgManufactureType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Manufacture types
 * \sa CIDEV_COMCFG_MANUFACTURE_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiDevComcfgManufactureType;
/**@}*/

//ICAT EXPORTED STRUCT
typedef struct CiDevComcfgToken_struct{
    CiDevComcfgTokenType	name;		/**< Token name \sa CiDevComcfgTokenType */
    /*UINT16*/UINT32		value;		/**< Token value */ //Modified by Lilei 04042014 CQ58190
} CiDevComcfgToken;

/** <paramref name="CI_DEV_PRIM_SET_COM_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetComConfigReq_struct{
    UINT8				numTokens;  					/**< Number of tokens to set */
    CiDevComcfgToken    Token[CI_DEV_NUM_COMCFG_TOKEN]; /**< Tokens info \sa CiDevComcfgToken */	
} CiDevPrimSetComConfigReq;

/** <paramref name="CI_DEV_PRIM_SET_COM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetComConfigCnf_struct{
	CiDevRc         rc;		/**< Result code. \sa CiDevRc. */
} CiDevPrimSetComConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_COM_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetComConfigReq_struct{
    CiBitRange 		tokens;		/**< This is a bitmap representing the Token to get. The bitmap format matches the enum CIDEV_COMCFG_TOKEN_TYPE */	
} CiDevPrimGetComConfigReq;

/** <paramref name="CI_DEV_PRIM_GET_COM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetComConfigCnf_struct{
	CiDevRc         	rc;								/**< Result code. \sa CiDevRc. */
	UINT8				numTokens;  					/**< Number of tokens */
    CiDevComcfgToken    Token[CI_DEV_NUM_COMCFG_TOKEN];	/**< Tokens info \sa CiDevComcfgToken */
} CiDevPrimGetComConfigCnf;

/* Lilei VZWRSRP&VZWRSRQ support -- Start */
/******************************************************************************
 * CI_DEV_PRIM_GET_LTE_MEAS_REQ & CI_DEV_PRIM_GET_LTE_MEAS_CNF
 * return LTE RSRP/RSRQ of cells, all cells which ERRC measured
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_GET_LTE_MEAS_REQ">   */
typedef CiEmptyPrim CiDevPrimGetLteMeasReq;

//ICAT EXPORTED STRUCT
typedef struct LteMeasInfo_tag{
	UINT16			cellID;		/**< Cell ID of lte rsrp&rsrq measurement info */
	UINT32			earfcn;		/**< Arfcn */
	UINT8			rsrp;		/**< Rsrp info */
	UINT8			rsrq;		/**< Rsrq Info */
}LteMeasInfo;

/** <paramref name="CI_DEV_PRIM_GET_LTE_MEAS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetLteMeasCnf_struct{
	CiDevRc			result;			/**< Result code. \sa CiDevRc. */
	UINT8			num;			/**< Number of cells that confirm rsrp&rsrq info. */
	LteMeasInfo		eMeasInfo[32];	/**< Rsrp&rsrq measurement info. \sa LteMeasInfo */
}CiDevPrimGetLteMeasCnf;
/* Lilei VZWRSRP&VZWRSRQ support -- End */


/* Lilei LTE&WIFI coexist support 20131022 -- Start */
/** \brief  LTE RRC state values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiDEVLTERRCSTATE_TAG
{
	CI_DEV_LTE_RRC_STATE_IDLE = 0,  /**< LTE RRC state IDLE */
	CI_DEV_LTE_RRC_STATE_CONNECTED  /**< LTE RRC state CONNECTED */
} _CiDevLteRrcState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief LTE RRC state
 * \sa CiDEVLTERRCSTATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevLteRrcState;
/**@}*/


/** \brief E-UTRAN band option values - E-UTRAN frequency bands are defined in 3GPP TS 36.101. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEVEUTRANBAND_TAG{
    CI_DEV_EUTRAN_BAND_FDD_1  = 1,		/**< E-UTRAN operating band 1*/
    CI_DEV_EUTRAN_BAND_FDD_2,			/**< E-UTRAN operating band 2 */
    CI_DEV_EUTRAN_BAND_FDD_3,			/**< E-UTRAN operating band 3 */
    CI_DEV_EUTRAN_BAND_FDD_4,			/**< E-UTRAN operating band 4 */
    CI_DEV_EUTRAN_BAND_FDD_5,			/**< E-UTRAN operating band 5 */
    CI_DEV_EUTRAN_BAND_FDD_6,			/**< E-UTRAN operating band 6 */
    CI_DEV_EUTRAN_BAND_FDD_7,			/**< E-UTRAN operating band 7 */
    CI_DEV_EUTRAN_BAND_FDD_8,			/**< E-UTRAN operating band 8 */
    CI_DEV_EUTRAN_BAND_FDD_9,			/**< E-UTRAN operating band 10 */
	CI_DEV_EUTRAN_BAND_FDD_10,          /**< E-UTRAN operating band 11 */
    CI_DEV_EUTRAN_BAND_FDD_11,          /**< E-UTRAN operating band 12 */
    CI_DEV_EUTRAN_BAND_FDD_12,          /**< E-UTRAN operating band 13 */
    CI_DEV_EUTRAN_BAND_FDD_13,          /**< E-UTRAN operating band 14 */
    CI_DEV_EUTRAN_BAND_FDD_14,          /**< E-UTRAN operating band 15 */
    CI_DEV_EUTRAN_BAND_FDD_15_NOT_USED, 
    CI_DEV_EUTRAN_BAND_FDD_16_NOT_USED, 
    CI_DEV_EUTRAN_BAND_FDD_17,          /**< E-UTRAN operating band 17 */
	CI_DEV_EUTRAN_BAND_FDD_18,          /**< E-UTRAN operating band 18 */
    CI_DEV_EUTRAN_BAND_FDD_19,          /**< E-UTRAN operating band 19 */
    CI_DEV_EUTRAN_BAND_FDD_20,          /**< E-UTRAN operating band 20 */
    CI_DEV_EUTRAN_BAND_FDD_21,          /**< E-UTRAN operating band 21 */
    CI_DEV_EUTRAN_BAND_FDD_22,          /**< E-UTRAN operating band 22 */
	CI_DEV_EUTRAN_BAND_FDD_23,          /**< E-UTRAN operating band 23 */
    CI_DEV_EUTRAN_BAND_FDD_24,          /**< E-UTRAN operating band 24 */
	CI_DEV_EUTRAN_BAND_FDD_25,          /**< E-UTRAN operating band 25 */
    CI_DEV_EUTRAN_BAND_FDD_26,          /**< E-UTRAN operating band 26 */
	CI_DEV_EUTRAN_BAND_FDD_27,          /**< E-UTRAN operating band 27 */
    CI_DEV_EUTRAN_BAND_FDD_28,          /**< E-UTRAN operating band 28 */
	CI_DEV_EUTRAN_BAND_FDD_29,          /**< E-UTRAN operating band 29. Restricted to E-UTRA operation when CA is configured */
    CI_DEV_EUTRAN_BAND_FDD_30_NOT_USED, 
    CI_DEV_EUTRAN_BAND_FDD_31_NOT_USED, 
    CI_DEV_EUTRAN_BAND_FDD_32_NOT_USED, 
    
    CI_DEV_EUTRAN_BAND_TDD_33,          /**< E-UTRAN operating band 33 */
	CI_DEV_EUTRAN_BAND_TDD_34,          /**< E-UTRAN operating band 34 */
    CI_DEV_EUTRAN_BAND_TDD_35,          /**< E-UTRAN operating band 35 */
    CI_DEV_EUTRAN_BAND_TDD_36,          /**< E-UTRAN operating band 36 */
    CI_DEV_EUTRAN_BAND_TDD_37,          /**< E-UTRAN operating band 37 */
    CI_DEV_EUTRAN_BAND_TDD_38,          /**< E-UTRAN operating band 38 */
	CI_DEV_EUTRAN_BAND_TDD_39,          /**< E-UTRAN operating band 39 */
    CI_DEV_EUTRAN_BAND_TDD_40,          /**< E-UTRAN operating band 40 */
	CI_DEV_EUTRAN_BAND_TDD_41,          /**< E-UTRAN operating band 41 */
    CI_DEV_EUTRAN_BAND_TDD_42,          /**< E-UTRAN operating band 42 */
	CI_DEV_EUTRAN_BAND_TDD_43,          /**< E-UTRAN operating band 43 */
	CI_DEV_EUTRAN_BAND_TDD_44,          /**< E-UTRAN operating band 44 */

    // More bands supported...
    CI_DEV_EUTRAN_BAND_FDD_65 = 65,
    CI_DEV_EUTRAN_BAND_FDD_66,
    CI_DEV_EUTRAN_BAND_FDD_96,
    
    CI_DEV_EUTRAN_BAND_NEXTVAL
} _CiDevEutranBand;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief E-UTRAN band options
 * \sa CIDEVEUTRANBAND_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiDevEutranBand;
/**@}*/

#define CI_DEV_NUM_EUTRAN_BAND (CI_DEV_EUTRAN_BAND_NEXTVAL-1)

/******************************************************************************
 * CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ & CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_CNF
 * Enable/disable the report of LTE coexist info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteCoexReportOptionReq_struct{
	CiBoolean		enableLteCoexReport; /**< Enable/disable LTE coexist info report */
}CiDevPrimSetLteCoexReportOptionReq;

/** <paramref name="CI_DEV_PRIM_SET_LTE_COEX_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteCoexReportOptionCnf_struct{
	CiDevRc			result; /**< Result code. \sa CiDevRc. */
}CiDevPrimSetLteCoexReportOptionCnf;


/******************************************************************************
 * CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ & CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF
 * Inquiry the LTE coexist info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_GET_LTE_COEX_INFO_REQ">   */
typedef CiEmptyPrim CiDevPrimGetLteCoexInfoReq;

/** <paramref name="CI_DEV_PRIM_GET_LTE_COEX_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetLteCoexInfoCnf_struct{
	CiDevRc				result;  /**< Result code. \sa CiDevRc. */
	CiBoolean			isLteOn; /**< TRUE: current operating on LTE; FALSE otherwise */
	CiDevLteRrcState	rrcState;/**< Current ERRC state: IDLE or CONNECTED */
	CiDevEutranBand		lteBand; /**< LTE current operation band */
	UINT32				earfcn;  /**< Earfcn */
	CiBoolean			tddSubframeConfigPresent;
	UINT8				tddUlDlConfig; /**< TD-LTE UL/DL configuration index: 0-6 */
	UINT8				tddSpecialSubframeConfig; /**< TD-LTE special subframe configuration index: 0-9 */
	CiBoolean			longDRXCyclePresent;
	UINT16				longDRXCycle;  /**< long DRX cycle in ms */
	CiBoolean			shortDRXCyclePresent;
	UINT16				shortDRXCycle; /**< short DRX cycle in ms */
}CiDevPrimGetLteCoexInfoCnf;


/******************************************************************************
 * CI_DEV_PRIM_LTE_COEX_INFO_IND
 * Indicate/report the LTE coexist info.
******************************************************************************/
/** <paramref name="CI_DEV_PRIM_LTE_COEX_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteCoexInfoInd_struct{
	CiBoolean			isLteOn; /**< TRUE: current operating on LTE; FALSE otherwise */
	CiDevLteRrcState	rrcState;/**< Current ERRC state: IDLE or CONNECTED */
	CiDevEutranBand		lteBand; /**< LTE current operation band */
	UINT32				earfcn;  /**< Earfcn */
	CiBoolean			tddSubframeConfigPresent;
	UINT8				tddUlDlConfig; /**< TD-LTE UL/DL configuration index: 0-6 */
	UINT8				tddSpecialSubframeConfig; /**< TD-LTE special subframe configuration index: 0-9 */
	CiBoolean			longDRXCyclePresent;
	UINT16				longDRXCycle;  /**< long DRX cycle in ms */
	CiBoolean			shortDRXCyclePresent;
	UINT16				shortDRXCycle; /**< short DRX cycle in ms */
}CiDevPrimLteCoexInfoInd;
/* Lilei LTE&WIFI coexist support 20131022 -- End */

/* Merged from UMTS7_Rel by Lilei 02182014, begin */
/*Add by Alan for L2RandomFillBitsEnabled on 02082014, CQ54160, begin*/
/** <paramref name="CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetL2RandFillEnabledReq_struct{
    CiBoolean    isL2RandomFillBitsEnabled;    /**<  TRUE: Enabled; FALSE: Disabled*/
} CiDevPrimSetL2RandFillEnabledReq;

/** <paramref name="CI_DEV_PRIM_SET_L2_RAND_FILL_ENABLED_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetL2RandFillEnabledCnf_struct{
    CiDevRc         rc;   /**< Result code. \sa CiDevRc. */
} CiDevPrimSetL2RandFillEnabledCnf;

/** <paramref name="CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_REQ">   */
typedef CiEmptyPrim CiDevPrimGetL2RandFillEnabledReq;

/** <paramref name="CI_DEV_PRIM_GET_L2_RAND_FILL_ENABLED_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetL2RandFillEnabledCnf_struct{
    CiDevRc         rc;   /**< Result code. \sa CiDevRc. */
    CiBoolean       isL2RandomFillBitsEnabled;  /**<  TRUE: Enabled; FALSE: Disabled*/
} CiDevPrimGetL2RandFillEnabledCnf;
/*Add by Alan for L2RandomFillBitsEnabled on 02082014, CQ54160, end*/

/*Add by Alan for reporting T323 on 02082014, CQ54159, begin*/
//ICAT EXPORTED STRUCT
/** <paramref name="CI_DEV_PRIM_T323_IND">   */
typedef struct CiDevPrimT323Ind_struct{
    CiBoolean  t323Valid;  
    UINT16     t_323;     
} CiDevPrimT323Ind;
/*Add by Alan for reporting T323 on 02082014, CQ54159, end*/
/* Merged from UMTS7_Rel by Lilei 02182014, end */


/*Add by Alan for MCC, MNC and CC on 03102014, CQ54159, begin*/
/** <paramref name="CI_DEV_PRIM_SET_MCC_MNC_CC_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetMccMncCcReq_struct{
    UINT16     countryCode;
    UINT16     operCode;
    UINT8       customerCode[3];
} CiDevPrimSetMccMncCcReq;

/** <paramref name="CI_DEV_PRIM_SET_MCC_MNC_CC_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetMccMncCcCnf_struct{
    CiDevRc         rc;   /**< Result code. \sa CiDevRc. */
} CiDevPrimSetMccMncCcCnf;

/** <paramref name="CI_DEV_PRIM_GET_MCC_MNC_CC_REQ">   */
typedef CiEmptyPrim CiDevPrimGetMccMncCcReq;

/** <paramref name="CI_DEV_PRIM_GET_MCC_MNC_CC_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetMccMncCcCnf_struct{
    CiDevRc         rc;   /**< Result code. \sa CiDevRc. */
    UINT16     countryCode;
    UINT16     operCode;
    UINT8       customerCode[3];
} CiDevPrimGetMccMncCcCnf;
/*Add by Alan for MCC, MNC and CC on 03102014, CQ54159, end*/

/*Added by Lilei for AT*L1DEBUG CQ60995 on 05162014, begin*/
#define CI_DEV_MAX_L1_DEBUG_REQ_LEN 10
#define CI_DEV_MAX_L1_DEBUG_RES_LEN 256

/** <paramref name="CI_DEV_PRIM_SET_L1DEBUG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetL1DebugReq_struct{
    UINT16      length;
    UINT8       data[CI_DEV_MAX_L1_DEBUG_REQ_LEN]; /**< L1 Debug data sent to L1 */
} CiDevPrimSetL1DebugReq;

/** <paramref name="CI_DEV_PRIM_SET_L1DEBUG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetL1DebugCnf_struct{
    CiDevRc     rc;   /**< Result code. \sa CiDevRc. */
} CiDevPrimSetL1DebugCnf;

/** <paramref name="CI_DEV_PRIM_L1DEBUG_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimL1DebugInfoInd_struct{
    UINT16      length;
    UINT8       data[CI_DEV_MAX_L1_DEBUG_RES_LEN]; /**< L1 Debug info received from L1 */
} CiDevPrimL1DebugInfoInd;
/*Added by Lilei for AT*L1DEBUG CQ60995 on 05162014, end*/

/*Lilei, CQ00079390, 20141217, begin*/
#define CI_DEV_MAX_IML_CFG_LEN 64

//ICAT EXPORTED ENUM
typedef enum CiDEVIMLLOGTYPE_TAG
{
    CI_DEV_IMLLOG_OFF = 0,
    CI_DEV_IMLLOG_2SD,
    CI_DEV_IMLLOG_2DDR,
    CI_DEV_IMLLOG_2HSL_BIGBOARD,
    CI_DEV_IMLLOG_2HSL_SMALLBOARD,
    CI_DEV_IMLLOG_2SU_ENABLE,
    CI_DEV_IMLLOG_2SU_DISABLE,
    /*Lilei, CQ00131002, 20210616, begin*/
    CI_DEV_IPCLOG_DISABLE,              /**< DSP IPC log close */
    CI_DEV_IPCLOG_ENABLE,               /**< DSP IPC log open */
    /*Lilei, CQ00131002, 20210616, end*/
    /*Lilei, CQ00140747, 20221215, begin*/
    CI_DEV_DIAGLOG_LEVEL,               /**< Diag log level */
    /*Lilei, CQ00140747, 20221215, end*/

    CI_DEV_NUM_IMLLOG_CFG
} _CiDevImlLogType;

typedef UINT8 CiDevImlLogType;


/** <paramref name="CI_DEV_PRIM_SET_IMLCONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetImlConfigReq_struct{
    CiDevImlLogType     imlLogType; /**< IML log type. */
    UINT8               cfgDataLen; /**< Config data length */
    UINT8               cfgData[CI_DEV_MAX_IML_CFG_LEN]; /**< Config data */
} CiDevPrimSetImlConfigReq;

/** <paramref name="CI_DEV_PRIM_SET_IMLCONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetImlConfigCnf_struct{
    CiDevRc             rc;   /**< Result code. \sa CiDevRc. */
} CiDevPrimSetImlConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_IMLCONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetImlConfigReq;

/** <paramref name="CI_DEV_PRIM_GET_IMLCONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetImlConfigCnf_struct{
    CiDevRc             rc;         /**< Result code. \sa CiDevRc. */
    CiDevImlLogType     imlLogType; /**< IML log type. */
    UINT8               cfgDataLen; /**< Only valid for IML2SU log type; For other types, it shall be zero */
    UINT8               cfgData[CI_DEV_MAX_IML_CFG_LEN]; /**< Config data for IML2SU log type. */
} CiDevPrimGetImlConfigCnf;
/*Lilei, CQ00079390, 20141217, end*/

#define CI_DEV_REQUEST_STRLEN_MAX 64
#define CI_DEV_REQUEST_ITEMNUM_MAX 14
#define CI_DEV_CNF_STRLEN_MAX (1024-64)



//ICAT EXPORTED ENUM
enum CiDevPrimMrdOperCmd_enum
{
	CI_DEV_MRD_CDF_CMD = 0, /* AT*MRD_CDF  no use any more, process by ap*/
	CI_DEV_MRD_IMEI_CMD,      /* AT*MRD_IMEI*/
	CI_DEV_MRD_MEP_CMD,      /* AT*MRD_MEP no use any more, process by ap*/
	CI_DEV_MRD_MIPS_CMD,      /* AT*CP_MIPS no use any more, process by ap*/

	CI_DEV_MRD_VSIM_CMD,	  /* AT*AVSIM */
	CI_DEV_MRD_ADC_CMD,	      /* AT*MRD_ADC */
	CI_DEV_MRD_RTPADC_CMD,    /* AT*MRD_RTPADC */
	
	CI_DEV_MRD_CMD_NUM
};

typedef UINT8 CiDevMrdType;
/** <paramref name="CI_DEV_PRIM_MRD_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimCpMrdOperReq_struct
{
	CiDevMrdType 		mrdType;   /**< MRD type. \sa CiDevPrimMrdOperCmd_enum. */
	UINT8				opType;    /* 0 - set VSIM; 1 - get VSIM; 3 - set IMEI */
	UINT8 			 	paraNums;  /* Always set to 1 */
	UINT8 				parameters[CI_DEV_REQUEST_ITEMNUM_MAX][CI_DEV_REQUEST_STRLEN_MAX];
} CiDevPrimCpMrdOperReq;
/** <paramref name="CI_DEV_PRIM_MRD_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimCpMrdOperCnf_struct
{
	CiDevRc             rc;
	CiDevMrdType     	mrdType;
	UINT8				resultCode;
	UINT16				errCode;	
	UINT8 				parameters[CI_DEV_CNF_STRLEN_MAX];
} CiDevPrimCpMrdOperCnf;


/*Lilei, CQ00080629, 20150104, begin*/
/** <paramref name="CI_DEV_PRIM_RB_TEST_MODE_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimRbTestModeInd_struct
{
    CiBoolean rbModeStatus;     /**<  0: RB test mode stop; 1: RB test mode start*/
} CiDevPrimRbTestModeInd;
/*Lilei, CQ00080629, 20150104, end*/

/*Lilei, CQ00085118, 20150202, begin*/
#define CI_DEV_MAX_LTE_BAND_ORDER_NUM 20

/** <paramref name="CI_DEV_PRIM_SET_LTE_BAND_ORDER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteBandOrderReq_struct{
    UINT8                   numOfLteBands; /**< Number of the ordered LTE bands */
    CiDevEutranBand         lteBands[CI_DEV_MAX_LTE_BAND_ORDER_NUM];   /**< LTE bands in order */
}CiDevPrimSetLteBandOrderReq;

/** <paramref name="CI_DEV_PRIM_SET_LTE_BAND_ORDER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetLteBandOrderCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
}CiDevPrimSetLteBandOrderCnf;

/** <paramref name="CI_DEV_PRIM_GET_LTE_BAND_ORDER_REQ">   */
typedef CiEmptyPrim CiDevPrimGetLteBandOrderReq;

/** <paramref name="CI_DEV_PRIM_GET_LTE_BAND_ORDER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetLteBandOrderCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
    UINT8                   numOfLteBands; /**< Number of the ordered LTE bands */
    CiDevEutranBand         lteBands[CI_DEV_MAX_LTE_BAND_ORDER_NUM];   /**< LTE bands in order */
}CiDevPrimGetLteBandOrderCnf;
/*Lilei, CQ00085118, 20150202, end*/

/*Lilei, CQ00087682, 20150304, begin*/
#define CI_DEV_MAX_SIZE_SALES_CODE 8
#define CI_DEV_MAX_NUM_SALES_CODE 10

//ICAT EXPORTED STRUCT
typedef struct CiDevSalesCode_struct{
    UINT8           len;
    UINT8           data[CI_DEV_MAX_SIZE_SALES_CODE];
}CiDevSalesCode;

/** <paramref name="CI_DEV_PRIM_SET_SALES_CODE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSalesCodeReq_struct{
    UINT8           codeNum;
    CiDevSalesCode  code[CI_DEV_MAX_NUM_SALES_CODE];   /**< Sales code info */
}CiDevPrimSetSalesCodeReq;

/** <paramref name="CI_DEV_PRIM_SET_SALES_CODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSalesCodeCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimSetSalesCodeCnf;


/** <paramref name="CI_DEV_PRIM_GET_SALES_CODE_REQ">   */
typedef CiEmptyPrim CiDevPrimGetSalesCodeReq;

/** <paramref name="CI_DEV_PRIM_GET_SALES_CODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSalesCodeCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
    UINT8           codeNum;
    CiDevSalesCode  code[CI_DEV_MAX_NUM_SALES_CODE];   /**< Sales code info */
}CiDevPrimGetSalesCodeCnf;


#define CI_DEV_MAX_NUM_FEATURES 32

//ICAT EXPORTED STRUCT
typedef struct CiDevFeature_struct{
   //UINT8            featureId;
   UINT32           featureId;
   UINT32           featureValue;
}CiDevFeature;

/** <paramref name="CI_DEV_PRIM_SET_OPER_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetOperConfigReq_struct{
   UINT8            numFeatures;
   CiDevFeature     feature[CI_DEV_MAX_NUM_FEATURES];   /**< Operators config info */
} CiDevPrimSetOperConfigReq;

/** <paramref name="CI_DEV_PRIM_SET_OPER_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetOperConfigCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimSetOperConfigCnf;

//ICAT EXPORTED ENUM
typedef enum CiDevGetOperCfgType_enum
{
    CI_DEV_GET_ALL_OPER_CFG = 0,
	CI_DEV_GET_SPECIFIC_OPER_CFG,
	
	CI_DEV_NUM_GET_OPER_CFG_TYPE
} _CiDevGetOperCfgType;

typedef UINT8 CiDevGetOperCfgType;

/** <paramref name="CI_DEV_PRIM_GET_OPER_CONFIG_REQ">   */
//typedef CiEmptyPrim CiDevPrimGetOperConfigReq;
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetOperConfigReq_struct{
   CiDevGetOperCfgType  type;
   UINT32               featureIdOrIndex;   /**< Feature index when type=0, specific feature ID when type=1 */
} CiDevPrimGetOperConfigReq;

/** <paramref name="CI_DEV_PRIM_GET_OPER_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetOperConfigCnf_struct{
   CiDevRc          rc;        /**< Result code. \sa CiDevRc. */
   UINT16           totalNum;  /**< Total num of feature IDs */
   UINT16           validNum;  /**< Valid num of feature IDs of this query */
   CiDevFeature     feature[CI_DEV_MAX_NUM_FEATURES];   /**< Operators config info */
} CiDevPrimGetOperConfigCnf;
/*Lilei, CQ00087682, 20150304, end*/

//added by taow 20170524 begin
/** <paramref name="CI_DEV_PRIM_GET_STATUS_REQ">   */
typedef CiEmptyPrim CiDevPrimGetStatusReq;

/** <paramref name="CI_DEV_PRIM_GET_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetStatusCnf_struct{
	CiDevRc          rc;        /**< Result code. \sa CiDevRc. */
    CiDevStatus status;		/**< Device status  \sa CiDevStatus */
} CiDevPrimGetStatusCnf;
//added by taow 20170524 end

/*Lilei, CQ00108730, 20171225, begin*/
/** <paramref name="CI_DEV_PRIM_FACTORY_RESET_REQ">   */
typedef CiEmptyPrim CiDevPrimFactoryResetReq;

/** <paramref name="CI_DEV_PRIM_FACTORY_RESET_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimFactoryResetCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimFactoryResetCnf;
/*Lilei, CQ00108730, 20171225, end*/

/*Lilei, CQ00112021, 20180903, begin*/
/** <paramref name="CI_DEV_PRIM_GET_IMS_UL_STATISTIC_REQ">   */
typedef CiEmptyPrim CiDevPrimGetImsUlStatisticReq;

/** <paramref name="CI_DEV_PRIM_GET_IMS_UL_STATISTIC_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetImsUlStatisticCnf_struct{
    CiDevRc     rc;                     /**< Result code. \sa CiDevRc. */
    UINT32      ulThroughPut;           /**< UL throughput of IMS video */
    UINT16      ulBler;                 /**< UL BLER of IMS video */
    UINT8       rsrp;                   /**< Value range: 0~97, invalid(0xFF) */
    UINT8       rsrq;                   /**< Value range: 0~34, invalid(0xFF) */
    INT16       snr;                    /**< Value range: [-10~40]*256 */
    UINT32      l2DiscardPacketsLen;    /**< Length of L2 discarded UL IMS video packet */
    UINT32      reserved1;
	UINT32      reserved2;
	UINT32      reserved3;
	UINT32      reserved4;
} CiDevPrimGetImsUlStatisticCnf;
/*Lilei, CQ00112021, 20180903, end*/

/*add by taow 20180525 CQ00110802 begin*/
/** <paramref name="CI_DEV_PRIM_SET_MEDATA_RESERVER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetMedataCommReserveReq_struct{
    UINT8             positionToSet; /*position of Medata comm reserved */
    UINT8             setConfigValue;   /*value to set */
}CiDevPrimSetMedataCommReserveReq;
/** <paramref name="CI_DEV_PRIM_SET_MEDATA_RESERVER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetMedataCommReserveCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
	/*added by taow 20181107 CQ00112754 begin */
    UINT8                   positionToSet; /*added by taow 20190218:position of Medata comm reserved */
	/*added by taow 20181107 CQ00112754 end*/
}CiDevPrimSetMedataCommReserveCnf;
/** <paramref name="CI_DEV_PRIM_GET_MEDATA_RESERVER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetMedataCommReserveReq_struct{
    UINT8             positionToGet; /*position of Medata comm reserved */
}CiDevPrimGetMedataCommReserveReq;
/** <paramref name="CI_DEV_PRIM_GET_MEDATA_RESERVER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetMedataCommReserveCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */	
    UINT8                   ConfigValue;   /*value to set */
	/*added by taow 20181107 CQ00112754 begin */
    UINT8                   positionToGet; /*added by taow 20190218:position of Medata comm reserved */
    /*added by taow 20181107 CQ00112754 end */
}CiDevPrimGetMedataCommReserveCnf;

/*add by taow 20180525 CQ00110802 end*/

/*Lilei, CQ00115548, 20190719, begin*/
/** <paramref name="CI_DEV_PRIM_SET_CELL_SELECT_CFG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetCellSelectCfgReq_struct{
    INT8        offset_scell;               /**< serving cell, SrxLev + offset, to check whether do neighbor cell measurement */
    INT8        offset_scell_qual;          /**< serving cell, Squal + offset, to check whether do neighbor cell measurement */
    INT8        offset_ncell_lte;           /**< neighbor cell, LTE RSRP - offset, for cell reselection evaluation */
    INT8        offset_ncell_lte_qual;      /**< neighbor cell, LTE RSRQ - offset, for cell reselection evaluation */
    INT8        offset_ncell_umts;          /**< neighbor cell, UMTS RSCP - offset, for cell reselection evaluation */
    INT8        offset_ncell_umts_qual;     /**< neighbor cell, UMTS EcN0 - offset, for cell reselection evaluation */
    INT8        offset_ncell_gsm;           /**< neighbor cell, GSM RSSI - offset, for cell reselection evaluation */
}CiDevPrimSetCellSelectCfgReq;

/** <paramref name="CI_DEV_PRIM_SET_CELL_SELECT_CFG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetCellSelectCfgCnf_struct{
    CiDevRc     rc;         /**< Result code. \sa CiDevRc. */
}CiDevPrimSetCellSelectCfgCnf;

/** <paramref name="CI_DEV_PRIM_GET_CELL_SELECT_CFG_REQ">   */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiDevPrimGetCellSelectCfgReq;

/** <paramref name="CI_DEV_PRIM_GET_CELL_SELECT_CFG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetCellSelectCfgCnf_struct{
    CiDevRc     rc;         /**< Result code. \sa CiDevRc. */
    INT8        offset_scell;               /**< serving cell, SrxLev + offset, to check whether do neighbor cell measurement */
    INT8        offset_scell_qual;          /**< serving cell, Squal + offset, to check whether do neighbor cell measurement */
    INT8        offset_ncell_lte;           /**< neighbor cell, LTE RSRP - offset, for cell reselection evaluation */
    INT8        offset_ncell_lte_qual;      /**< neighbor cell, LTE RSRQ - offset, for cell reselection evaluation */
    INT8        offset_ncell_umts;          /**< neighbor cell, UMTS RSCP - offset, for cell reselection evaluation */
    INT8        offset_ncell_umts_qual;     /**< neighbor cell, UMTS EcN0 - offset, for cell reselection evaluation */
    INT8        offset_ncell_gsm;           /**< neighbor cell, GSM RSSI - offset, for cell reselection evaluation */
}CiDevPrimGetCellSelectCfgCnf;
/*Lilei, CQ00115548, 20190719, end*/

/*Lilei, CQ00115868, 20190815, begin*/
typedef UINT8 CiDevCommonCause;

//ICAT EXPORTED ENUM
typedef enum CIDEV_EVENT_TYPE_AS_ENUM
{
    CI_DEV_RRC_EVENT_RACH_FAIL = 0,
    CI_DEV_RRC_EVENT_DL_LOSS_SYNC,
    CI_DEV_RRC_EVENT_SIB_MISSING,
    CI_DEV_RRC_EVENT_RLC_MAX_RETRANS,
    CI_DEV_RRC_EVENT_RRC_RECONFIG_ABNORMAL,
    CI_DEV_RRC_EVENT_RRC_REDIRECT_ABNORMAL,
    CI_DEV_RRC_EVENT_IRAT_RESELECTION_FAIL,
    CI_DEV_RRC_EVENT_RRC_ESTABLISH_SUCCESS,
    CI_DEV_RRC_EVENT_RRC_RELEASE,

    /*Lilei, CQ00144545, 20230706, begin*/
	CI_DEV_RRC_EVENT_LTE_RESELECTION_SUCCESS,
	CI_DEV_RRC_EVENT_LTE_HANDOVER_SUCCESS,
	CI_DEV_RRC_EVENT_LTE_REDIRECTION_SUCCESS,
	CI_DEV_RRC_EVENT_LTE_MEAS_REPORT_SENT,
	CI_DEV_RRC_EVENT_LTE_RRC_CONN_SETUP_NOT_RECEIVED,
    /*Lilei, CQ00144545, 20230706, end*/
    /*Lilei, CQ00146454, 20231023, begin*/
	CI_DEV_RRC_EVENT_LTE_MAC_SR_MAX,
    CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_SUCCESS,
    CI_DEV_RRC_EVENT_LTE_INTRA_HANDOVER_FAIL,
    CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_SUCCESS,
    CI_DEV_RRC_EVENT_LTE_INTER_HANDOVER_FAIL,
    CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_SUCCESS,
    CI_DEV_RRC_EVENT_LTE_INTER_BAND_HANDOVER_FAIL,
    CI_DEV_RRC_EVENT_LTE_RESELECTION_FAIL,
    /*Lilei, CQ00146454, 20231023, end*/

    CI_DEV_GRR_EVENT_RACH_FAIL = 0,             //radio link timeout, downlink signal fail,scell not reach threshhold
    CI_DEV_GRR_EVENT_RACH_TIMEOUT,              // rach timeout: t3126, t3146, t3147
    CI_DEV_GRR_EVENT_DCH_MDL_ERROR,             //dch mdl error:T200_EXPIRED_N200_TIMES, UNSOLICITED_DM_PERF_RELEASE,SEQ_ERROR_PERF_RELEASE
    CI_DEV_GRR_EVENT_PRACH_ERROR,               //scell not reach threshhold, radio link timeout, downlink signal fialure, mph error
    CI_DEV_GRR_EVENT_PDCH_TIMEOUT,              // T3166, T3168 etc.
    CI_DEV_GRR_EVENT_L2_MDL_ERROR,              //l2 est mdl error ind
    CI_DEV_GRR_EVENT_GSM_HANDOVER_FAIL,         //irat  CS handover fail
    CI_DEV_GRR_EVENT_GSM_IRAT_RESELECTION_FAIL, //irat reselection fail
    CI_DEV_GRR_EVENT_UL_TBF_ACTIVE,             //ul tbf active
    CI_DEV_GRR_EVENT_DL_TBF_ACTIVE,             //dl tbf active
    CI_DEV_GRR_EVENT_UL_TBF_INACTIVE,           //ul tbf release
    CI_DEV_GRR_EVENT_DL_TBF_INACTIVE            //dl tbf release
}_CiDevEventTypeAs;

typedef UINT8 CiDevEventTypeAs;

//ICAT EXPORTED ENUM
typedef enum CIDEV_EVENT_TYPE_MM_ENUM
{
    CI_DEV_GMM_EVENT_NEW_ATTACH_REQ = 0,            /*GPRS ATTACH START*/
    CI_DEV_GMM_EVENT_ATTACH_SUCCESS,                /*GPRS ATTACH SUCESS*/
    CI_DEV_GMM_EVENT_ATTACH_REJECT,                 /*GPRS ATTACH REJECT*/
    CI_DEV_GMM_EVENT_RAU_REJECT,                    /*GPRS RAU REJECT*/
    CI_DEV_GMM_EVENT_SERVICE_REJECT,                /*GPRS SERVICE REJECT*/
    CI_DEV_GMM_EVENT_AUTHENTICATION_REJECT,         /*GPRS AUTHENTICATION REJECT*/
    CI_DEV_GMM_EVENT_DETACH_REQ,                    /*GPRS DETACH REQUEST*/
    
    CI_DEV_MM_EVENT_LU_REJECT,                      /*LU REJECT*/
    CI_DEV_MM_EVENT_AUTHENTICATION_REJECT,          /*CS AUTHENTICATION REJECT*/
        
    CI_DEV_EMM_EVENT_NEW_ATTACH_REQ =0,             /*EPS ATTACH START*/
    CI_DEV_EMM_EVENT_ATTACH_SUCCESS,                /*EPS ATTACH SUCCESS*/
    CI_DEV_EMM_EVENT_ATTACH_REJECT,                 /*EPS ATTACH REJECT*/
    CI_DEV_EMM_EVENT_TAU_REJECT,                    /*EPS TAU REJECT*/
    CI_DEV_EMM_EVENT_SERVICE_REJECT,                /*EPS SERVICE REJECT*/
    CI_DEV_EMM_EVENT_AUTHENTICATION_REJECT,         /*EPS AUTHENTICATION REJECT*/
    CI_DEV_EMM_EVENT_DETACH_REQ,                    /*EPS DETACH REQUEST for MT*/
    CI_DEV_MM_TAU_ACCEPT,                            /*EPS TAU ACCEPT*/
    CI_DEV_EMM_EXTENDED_ACCESS_BARRED,
    /*Lilei, CQ00144545, 20230706, begin*/
    CI_DEV_EMM_ATTACH_TIMEOUT,                      /*EPS ATTACH timeout for all retries*/
    CI_DEV_EMM_TAU_TIMEOUT,                         /*EPS TAU timeout for all retries*/
    CI_DEV_EMM_SERVICE_REQ_TIMEOUT                  /*EPS SERVICE_REQ timeout for all retries*/
    /*Lilei, CQ00144545, 20230706, end*/
    
}_CiDevEventTypeMm;

typedef UINT8 CiDevEventTypeMm;

//ICAT EXPORTED ENUM
typedef enum CIDEV_EVENT_TYPE_SM_ENUM
{
    CI_DEV_SM_EVENT_PDP_ACT_REJ = 0,                /* PDP activation reject */
    CI_DEV_SM_EVENT_PDP_MODIFY_REJ,                 /* PDP modification reject */
    CI_DEV_SM_EVENT_PDP_DEACT_REJ,                  /* PDP deactivation reject */
    /*Lilei, CQ00144545, 20230706, begin*/
    CI_DEV_SM_EVENT_PDP_ACT_IGNORED                 /* PDP activation ignored */
    /*Lilei, CQ00144545, 20230706, end*/
}_CiDevEventTypeSm;

typedef UINT8 CiDevEventTypeSm;

/*Lilei, CQ00127026, 20201222, begin*/

// destin 2020.10.28 esm reject cause code start 
#ifdef QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT 
/* emm reject cause no all */
typedef enum
{   
    CI_ATTACH_REJECT_EMM_8 = 8,              /* EPS services and non-EPS services not allowed 8 */
    CI_ATTACH_REJECT_EMM_15 =15,             /* No Suitable Cells In tracking area EMM cause 15 */
    //CI_ATTACH_REJECT_ESM_PDN =33,          /* Requested service option not subscribed ESM cause 33 */
    
}emm_cause_enum_T;

/* Required for type_of_emm_cause... Refer section: 9.9.3.7 */

typedef enum
{
  LTE_NAS_CAUSE_NONE = -1,
  LTE_NAS_IMSI_UNKNOWN_IN_HSS = 2,
  LTE_NAS_ILLEGAL_UE = 3,
  LTE_NAS_IMSI_UNKNOWN_IN_VLR = 4, //new add
  LTE_NAS_IMEI_NOT_ACCEPTED = 5,
  LTE_NAS_ILLEGAL_ME = 6,
  LTE_NAS_EPS_SERVICES_NOT_ALLOWED = 7,
  LTE_NAS_EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED = 8,
  LTE_NAS_UE_ID_CANNOT_BE_DERIVED_BY_NW = 9,
  LTE_NAS_IMPLICITLY_DETACHED = 10,
  LTE_NAS_PLMN_NOT_ALLOWED = 11,
  LTE_NAS_TRACKING_AREA_NOT_ALLOWED =12,
  LTE_NAS_ROAMING_NOT_ALLOWED_IN_THIS_TRACKING_AREA=13,
  LTE_NAS_EPS_SERVICES_NOT_ALLOWED_IN_PLMN =14,
  LTE_NAS_NO_SUITABLE_CELLS_IN_TRACKING_AREA=15,
  LTE_NAS_MSC_TEMPORARILY_NOT_REACHABLE=16,
  LTE_NAS_NW_FAILURE=17,
  LTE_NAS_CS_DOMAIN_NOT_AVAILABLE=18,
  LTE_NAS_ESM_FAILURE=19,
  LTE_NAS_MAC_FAILURE=20,
  LTE_NAS_SYNCH_FAILURE=21,
  LTE_NAS_CONGESTION=22,
  LTE_NAS_UE_SECURITY_CAPABILITIES_MISMATCH=23,
  LTE_NAS_SECURITY_MODE_REJ_UNSPECIFIED =24,
  LTE_NAS_NOT_AUTHORIZED_FOR_THIS_CSG=25,
  LTE_NON_EPS_AUTH_UNACCEPTABLE = 26,
  LTE_NAS_CS_FALLBACK_CALL_EST_NOT_ALLOWED = 38,
  LTE_NAS_CS_DOMAIN_TEMP_NOT_AVAILABLE = 39,
  LTE_NAS_NO_EPS_BEARER_CONTEXT_ACTIVATED=40,
  LTE_NAS_SEVERE_NW_FAILURE =42,
  LTE_NAS_SEMANTICALLY_INCORRECT_MSG=95,
  LTE_NAS_INVALID_MANDATORY_INFO =96,
  LTE_NAS_NON_EXISTENT_MSG_TYPE=97,
  LTE_NAS_MSG_TYPE_INCOMPATIBLE_WITH_PROTOCOL_STATE=98,
  LTE_NAS_NON_EXISTANT_INFO=99,
  LTE_NAS_CONDITIONAL_IE_ERROR =100,
  LTE_NAS_MSG_INCOMPATIBLE_WITH_PROTOCOL_STATE=101,
  LTE_NAS_PROTOCOL_ERROR_UNSPECIFIED =111,

  LTE_NAS_NO_FAILURE = 256 /* IF ADDING ANY NEW CAUSE VALUES ADD BEFORE THIS*/
}lte_nas_emm_cause_type;

/*
* Refer Section: 9.9.4.2
* Reason a session management request (eSM) was rejected.
*/
typedef enum{
  NAS_ESM_OPTR_DETERMINED_BARRING = 8,                       /**< &nbsp; */
  NAS_ESM_INSUFFICIENT_RESOURCES = 26,                       /**< &nbsp; */
  NAS_ESM_UNKNOWN_MISSING_APN  =27,                          /**< &nbsp; */
  NAS_ESM_UNKNOWN_PDN_TYPE = 28,                             /**< &nbsp; */
  NAS_ESM_USER_AUTHENTICATION_FAILED = 29,                   /**< &nbsp; */
  NAS_ESM_OPN_REJ_SERVICING_GW_OR_PDN_GW = 30,               /**< &nbsp; */
  NAS_ESM_ACTIVATION_REJECTED = 31,                          /**< &nbsp; */
  NAS_ESM_SERV_OPT_NOT_SUPPORTED = 32,                       /**< &nbsp; */
  NAS_ESM_REQ_SERV_OPT_NOT_SPECIFIED =33,                    /**< &nbsp; */
  NAS_ESM_SERV_OPT_TEMP_OUT_OF_ORDER = 34,                   /**< &nbsp; */
  NAS_ESM_PTI_ALREADY_IN_USE =35,                            /**< &nbsp; */
  NAS_ESM_REGULAR_DEACTIVATION = 36,                         /**< &nbsp; */
  NAS_ESM_EPS_QOS_NOT_ACCEPTED = 37,                         /**< &nbsp; */
  NAS_ESM_NETWORK_FAILURE = 38,                              /**< &nbsp; */
  NAS_ESM_REACTIVATION_REQUIRED= 39,                         /**< &nbsp; */
  NAS_ESM_FEATURE_NOT_SUPPORTED = 40,                        /**< &nbsp; */
  NAS_ESM_SEMANTIC_ERR_IN_TFT_OPERATION =41,                 /**< &nbsp; */
  NAS_ESM_SYNTACTICAL_ERR_IN_TFT_OPERATION =42,              /**< &nbsp; */
  NAS_ESM_UNKNOWN_EPS_BEARER_CONTEXT = 43,                   /**< &nbsp; */
  NAS_ESM_SYMANTIC_ERR_IN_PKT_FILTER = 44,                   /**< &nbsp; */
  NAS_ESM_SYNTACTICAL_ERR_IN_PKT_FILTER =45,                 /**< &nbsp; */
  NAS_ESM_EPS_BEARER_CONT_WO_TFT_ALREADY_ACT = 46,           /**< &nbsp; */
  NAS_ESM_PTI_MISMATCH = 47,                                 /**< &nbsp; */
  /* This is not in the standard in table 9.9.4.4.1, but
     is referred to in section 7.3 of the standard */
  NAS_ESM_LAST_PDN_DISCONNECTED_NOT_ALLOWED = 49,            /**< &nbsp; */
  NAS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED = 50,                   /**< &nbsp; */
  NAS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED =51,                    /**< &nbsp; */
  NAS_ESM_SINGLE_ADR_BEARERS_ONLY_ALLOWED =52,               /**< &nbsp; */
  NAS_ESM_ESM_INFO_NOT_RECEIVED=53,                          /**< &nbsp; */
  NAS_ESM_PDN_CONN_DOES_NOT_EXIST =54,                       /**< &nbsp; */
  NAS_ESM_MULTIPLE_PDN_CONN_FOR_GIVEN_APN_NOT_ALLOWED =55,   /**< &nbsp; */
  NAS_ESM_COLLISION_WITH_NW_INIT_REQ =56,                    /**< &nbsp; */
  NAS_ESM_UNSUPPORTED_QCI_VALUE =59,                         /**< &nbsp; */
  NAS_ESM_BEARER_HANDLING_NOT_SUPPORTED =60,	
  NAS_ESM_MAX_PDP_CONTEXT_REACHED =65,                       /**< &nbsp; */
  NAS_ESM_APN_NOT_SUPPORTED_IN_PLMN_RAT_COMBINATION =66,     /**< &nbsp; */
  NAS_ESM_INVALID_PTI_VALUE =81,                             /**< &nbsp; */
  NAS_ESM_SYMANTICALLY_INVALID_MSG =95,                      /**< &nbsp; */
  NAS_ESM_INVALID_MANDATORY_INFORMATION = 96,                /**< &nbsp; */
  NAS_ESM_MSG_TYPE_NON_EXISTANT = 97,                        /**< &nbsp; */
  NAS_ESM_MSG_TYPE_INCOMPATIBLE_PROT_STATE = 98,             /**< &nbsp; */
  NAS_ESM_INFO_ELEMENT_NON_EXISTANT = 99,                    /**< &nbsp; */
  NAS_ESM_CONDITIONAL_IE_ERR = 100,                          /**< &nbsp; */
  NAS_ESM_MSG_INCOMPATIBLE_WITH_PRO_STATE= 101,              /**< &nbsp; */
  NAS_ESM_PROTOCOL_ERROR = 111,                              /**< &nbsp; */
  NAS_ESM_APN_RESTRICT_VAL_INCOMPAT_WITH_ACT_CONTEXT = 112,  /**< &nbsp; */
  NAS_ESM_NO_FAILURE  /**< &nbsp; */ /* IF ADDING ANY NEW CAUSE VALUES ADD BEFORE THIS*/
  }esm_cause_enum_T;
/*~ SENTINEL esm_cause_enum_T.NAS_ESM_NO_FAILURE */

/* --------------------------------------------------------------------
 isaac 20201231 2g/3g attach reject cause
 SM cause enumeration type, defined in Table 10.5.157/TS 24.008 
 This is the cause sent to the SM-SM peer entity.
** ------------------------------------------------------------------*/

/** Session management cause type.
*/
typedef enum
{
  /** @cond
  */
  SM_UNKNOWN_CAUSE = 0x01, /* For SM internal use only, not to be used in OTA */
  /** @endcond
  */
  SM_OPERATOR_DETERMINED_BARRING = 0x08,           /**< &nbsp; */
  SM_MBMS_BEARER_CAP_INSUFFICIENT = 0x18,          /**< &nbsp; */
  SM_LLC_SNDCP_FAILURE          = 0x19,            /**< &nbsp; */
  SM_INSUFFICIENT_RESOURCES,                       /**< &nbsp; */
  SM_MISSING_OR_UNKNOWN_APN,                       /**< &nbsp; */
  SM_UNKNOWN_PDP_ADDRESS_OR_TYPE,                  /**< &nbsp; */
  SM_USER_AUTHENTICATION_FAILED,                   /**< &nbsp; */
  SM_ACTIVATION_REJECTED_BY_GGSN,                  /**< &nbsp; */
  SM_ACTIVATION_REJECTED_UNSPECIFIED,              /**< &nbsp; */
  SM_SERVICE_OPTION_NOT_SUPPORTED,                 /**< &nbsp; */
  SM_SERVICE_NOT_SUBSCRIBED,                       /**< &nbsp; */
  SM_SERVICE_OUT_OR_ORDER,                         /**< &nbsp; */
  SM_NSAPI_ALREADY_USED,                           /**< &nbsp; */
  SM_REGULAR_DEACTIVATION,                         /**< &nbsp; */
  SM_QOS_NOT_ACCEPTED,                             /**< &nbsp; */
  SM_NETWORK_FAILURE,                              /**< &nbsp; */
  SM_REACTIVATION_REQUIRED,                        /**< &nbsp; */
  SM_FEATURE_NOT_SUPPORTED,                        /**< &nbsp; */
  SM_SEMANTIC_ERR_IN_TFT,                          /**< &nbsp; */
  SM_SYNTACTIC_ERR_IN_TFT,                         /**< &nbsp; */
  SM_UNKNOWN_PDP_CONTEXT,                          /**< &nbsp; */
  SM_SEMANTIC_ERR_IN_FILTER,                       /**< &nbsp; */
  SM_SYNTACTIC_ERR_IN_FILTER,                      /**< &nbsp; */
  SM_PDP_WITHOUT_TFT_ACTIVE,                       /**< &nbsp; */
  SM_MBMS_GROUP_MEMBERSHIP_TIMEOUT,                /**< &nbsp; */
  SM_ACTIVATION_REJECTED_BCM_VIOLATION = 0x30,     /**< &nbsp; */
  SM_PDP_TYPE_IPV4_ONLY_ALLOWED = 0x32,            /**< &nbsp; */
    //0 0 1 1 0 0 1 0 PDP type IPv4 only allowed
  SM_PDP_TYPE_IPV6_ONLY_ALLOWED = 0x33,            /**< &nbsp; */
    //0 0 1 1 0 0 1 1 PDP type IPv6 only allowed
  SM_SINGLE_ADR_BEARERS_ONLY_ALLOWED = 0x34,       /**< &nbsp; */
    //0 0 1 1 0 1 0 0 Single address bearers only allowed
  SM_COLLISION_WITH_NET_INITIATED_REQ = 0x38,		/**< &nbsp; */
  SM_BEARER_HANDLING_NOT_SUPPORTED	= 0x3C,			/**< &nbsp; */
  SM_MAX_NUM_OF_PDP_CONTEXTS_REACHED = 0x41,       /**< &nbsp; */
  //0 1 0 0 0 0 0 1 	Maximum number of PDP contexts reached
  SM_REQUESTED_APN_NOT_SUPPORTED_IN_CURRENT_RAT_PLMN_COBINATION = 0x42,       /**< &nbsp; */
  //0 1 0 0 0 0 1 0 	Requested APN not supported in current RAT and PLMN combination
  SM_INVALID_TRANS_ID = 0x51,                      /**< &nbsp; */
  SM_SEMANTIC_INCORRECT_MESG = 0x5F,               /**< &nbsp; */
  SM_INVALID_MANDATORY_INFO = 0x60,                /**< &nbsp; */
  SM_MESG_TYPE_NON_EXISTENT,                       /**< &nbsp; */
  SM_MESG_TYPE_NOT_COMPATIBLE,                     /**< &nbsp; */
  SM_IE_NON_EXISTENT,                              /**< &nbsp; */
  SM_CONDITIONAL_IE_ERR,                           /**< &nbsp; */
  SM_MESG_NOT_COMPATIBLE,                          /**< &nbsp; */
  SM_PROTOCOL_ERR = 0x6F,                          /**< &nbsp; */
  SM_APN_TYPE_CONFLICT                             /**< &nbsp; */
} sm_status_T;

/* *****************/
/* isaac 20200101 add gmm Reject causes.*/
/* *****************/
/** @name Rejection Causes
    @{ */
#define UNKNOWN_CAUSE                                   0xFF
#define IMSI_UNKNOWN_IN_HLR                             0x02 
#define ILLEGAL_MS                                      0x03 
#define IMSI_UNKNOWN_IN_VLR                             0x04
#define IMEI_NOT_ACCEPTED                               0x05 
#define ILLEGAL_ME                                      0x06 
#define GPRS_SERVICES_NOT_ALLOWED                       0x07 
#define GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED 0x08 
#define MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK    0x09 
#define IMPLICITLY_DETACHED                             0x0A 
#define PLMN_NOT_ALLOWED                                0x0B 
#define LA_NOT_ALLOWED                                  0x0C 
#define NATIONAL_ROAMING_NOT_ALLOWED                    0x0D 
#define GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN          0x0E 
#define NO_SUITABLE_CELLS_IN_LA                         0x0F 
#define MSC_TEMPORARILY_NOT_REACHABLE                   0x10 
#define NETWORK_FAILURE                                 0x11 
#define MAC_FAILURE                                     0x14 
#define SYNCH_FAILURE                                   0x15 
#define CONGESTTION                                     0x16 
#define GSM_AUTH_UNACCEPTED                             0x17
#define CSG_NOT_AUTHORIZED                              0x19
#define SMS_PROVIDED_VIA_GPRS_IN_THIS_ROUTING_AREA      0x1C
#define SERVICE_OPTION_NOT_SUPPORTED                    0x20 
#define REQ_SERV_OPT_NOT_SUBSCRIBED                     0x21 
#define SERVICE_OPT__OUT_OF_ORDER                       0x22 
#define CALL_CANNOT_BE_IDENTIFIED                       0x26 
#define NO_PDP_CONTEXT_ACTIVATED                        0x28 
#define RETRY_UPON_ENTRY_INTO_A_NEW_CELL_MIN_VALUE      0x30 
#define COLLISION_WITH_NET_INITIATED_REQ				0x38 
#define RETRY_UPON_ENTRY_INTO_A_NEW_CELL_MAX_VALUE      0x3F 
#define SEMANTICALLY_INCORRECT_MSG                      0x5F 
#define INVALID_MANDATORY_INFO                          0x60 
#define MESSAGE_TYPE_NON_EXISTANT                       0x61 
#define MESSAGE_TYPE_NOT_COMP_PRT_ST                    0x62 
#define IE_NON_EXISTANT                                 0x63 
#define MSG_NOT_COMPATIBLE_PROTOCOL_STATE               0x65

#define MAX_NAS_SPEC_CAUSE_CODE                         MSG_NOT_COMPATIBLE_PROTOCOL_STATE
#define RAB_RB_DS_L2_CLEANUP_COLLISION                  MAX_NAS_SPEC_CAUSE_CODE+1

#define AUTHENTICATION_REJECTED                         0xFF
/** MN internal error for WMS in the case of Connection Manager timer
    expiration. */
#define NO_RESPONSE_FROM_NEWTWORK                       126

/** Abort service is not available. */
#define ABORT_SERVICE_NOT_AVAILABLE                     0x22

/** @} */

/*
 * These definitions are taken from GSM 04.08 Table 10.86
 */

/** @name Call Control Cause Value
    @{ */
#define  CONDITIONAL_IE_ERROR                           100
#define  PROTOCOL_ERROR_UNSPECIFIED                     111


/*
    isaac 20210101 add mm cause
 RR abort causes sent to MM
*/
/** @name Radio Resource Causes Sent to MM
    @{ */

#define REASON_NOT_AVAILABLE         0x00 
#define ACCESS_CLASS_NOT_ALLOWED     0x01 
#define RANDOM_ACCESS_FAILURE        0x02 
#define OTHER_REASON                 0x03 
#define RR_CONNECTION_FAILURE        0x04 
#define REASON_INTERRAT_RESELECTION  0x05 
#define RR_ABORT_REDIAL_NOT_ALLOWED  0x06 
#define RR_ABORT_LAI_CHANGED         0X07 
#define RR_ABORT_GTOW_REDIRECTION_IN_PROGRESS 0x08 
#define RR_ABORT_IA_REJECT_RECEIVED  0x09 
#define RR_ABORT_CON_EST_NOT_ATTEMPTED  0x0A
/** @} */

typedef struct ceer_lookup_s
{
    INT16   code;
    char     *text;
} ceer_lookup_s_type;

typedef struct 
{
    CiDevCommonCause detach_cause;
    CiDevEventTypeMm detach_event;
}quec_detach_s_t;
extern void quec_clear_reject_cause_buff(void);
extern unsigned char quec_ci_lookup_cause_code
(
  const ceer_lookup_s_type  *table_ptr,
  const INT16                code,
  const ceer_lookup_s_type  **row_pptr
);

#endif
/* destin 2020.10.28 esm reject cause code end */


//ICAT EXPORTED STRUCT
typedef struct CiDevCommonGsmCellInfo_struct
{
    UINT16              cellId;
    UINT16              arfcn;
    UINT8               bsic;
} CiDevCommonGsmCellInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonUmtsCellInfo_struct
{
    UINT32              cellId;
    UINT16              uArfcn;
    UINT16              psc;
} CiDevCommonUmtsCellInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonLteCellInfo_struct
{
    UINT32              cellId;
    UINT32              euArfcn;
    UINT16              phyCellId;
} CiDevCommonLteCellInfo;
/*Lilei, CQ00127026, 20201222, end*/

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportAS_struct
{
    CiDevEventTypeAs    event;
    CiDevEngModeNetwork networkMode;
    /*Lilei, CQ00144545, 20230706, begin*/
    CiDevCommonLteCellInfo currentLteCell;
    CiDevCommonLteCellInfo sourceLteCell; /* Only valid for HO/Reselection/Redirect etc. */
    UINT8                  rsrpOfsourceCell;
    UINT8                  rsrqOfsourceCell;
    UINT8                  rsrpOfcurrentCell;
    UINT8                  rsrqOfcurrentCell;
    /*Lilei, CQ00144545, 20230706, end*/
} CiDevCommonReportAS;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportMm_struct
{
    CiDevCommonCause    cause;      /* For attach initiation or success, there's no cause (value 0) */
    CiDevEventTypeMm    event;
    /*Lilei, CQ00127026, 20201222, begin*/
    CiDevEngModeNetwork     network;    /* 0:GSM, 1:UMTS */
    CiDevCommonGsmCellInfo  gsmCellInfo;
    CiDevCommonUmtsCellInfo umtsCellInfo;
    /*Lilei, CQ00127026, 20201222, end*/
    CiDevCommonCause    remapCause;  /*CQ00140020, lilei, 20221205*/
} CiDevCommonReportMm;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportGmm_struct
{
    CiDevCommonCause    cause;
    CiDevEventTypeMm    event;
    /*Lilei, CQ00127026, 20201222, begin*/
    CiDevEngModeNetwork     network;    /* 0:GSM, 1:UMTS */
    CiDevCommonGsmCellInfo  gsmCellInfo;
    CiDevCommonUmtsCellInfo umtsCellInfo;
    /*Lilei, CQ00127026, 20201222, end*/
    CiDevCommonCause    remapCause;  /*CQ00140020, lilei, 20221205*/
} CiDevCommonReportGmm;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportSm_struct
{
    CiDevCommonCause    cause;
    CiDevEventTypeSm    event;
} CiDevCommonReportSm;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportEmm_struct
{
    CiDevCommonCause    cause;
    CiDevEventTypeMm    event;
    /*Lilei, CQ00127026, 20201222, begin*/
    CiDevCommonLteCellInfo lteCellInfo;
    /*Lilei, CQ00127026, 20201222, end*/
    CiDevCommonCause    remapCause;  /*CQ00140020, lilei, 20221205*/
} CiDevCommonReportEmm;

//ICAT EXPORTED STRUCT
typedef struct CiDevCommonReportEsm_struct
{
    CiDevCommonCause    cause;
    CiDevEventTypeSm    event;
    /*Lilei, CQ00144545, 20230706, begin*/
    CiDevCommonLteCellInfo lteCellInfo;
    /*Lilei, CQ00144545, 20230706, end*/
} CiDevCommonReportEsm;

//ICAT EXPORTED ENUM
typedef enum CIDEV_COMMON_REPORT_ENUM
{
    CI_DEV_COMMON_REPORT_AS,
    CI_DEV_COMMON_REPORT_MM,
    CI_DEV_COMMON_REPORT_GMM,
    CI_DEV_COMMON_REPORT_SM,
    CI_DEV_COMMON_REPORT_EMM,
    CI_DEV_COMMON_REPORT_ESM,

    CI_DEV_NUM_COMMON_REPORT_TYPES
} _CiDevCommonReportType;

typedef UINT8 CiDevCommonReportType;

//ICAT EXPORTED UNION
typedef union CiDevCommonReport_union
{
    CiDevCommonReportAS     as;             /* AS layer reject info */
    CiDevCommonReportMm     mm;             /* MM reject info */
    CiDevCommonReportGmm    gmm;            /* GMM reject info */
    CiDevCommonReportSm     sm;             /* SM reject info */
    CiDevCommonReportEmm    emm;            /* EMM reject info */
    CiDevCommonReportEsm    esm;            /* ESM reject info */
} CiDevCommonReport;

/** <paramref name="CI_DEV_PRIM_COMMON_REPORT_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimCommonReportInd_struct
{
  CiDevCommonReportType     type;
  CiDevCommonReport         info;
} CiDevPrimCommonReportInd;
/*Lilei, CQ00115868, 20190815, end*/
/*20190819 CQ00116678 add by taow begin*/
#define CI_DEV_MAX_NUM_ROAM_FORBID_PLMN 10

//ICAT EXPORTED ENUM
typedef enum CiDevCmdType_TAG{
    /*For #3748 roaming forbiden plmn */
    CI_DEV_CMD_SET = 0,        		/**< set */
    CI_DEV_CMD_DELETE = 1,          /**< Delete  one or limit per time*/
    
    /*For #46621 forbiden plmn */
    CI_DEV_CMD_DELETE_SIM = 2,      /**< Delete  SIM card FPLMN*/
    CI_DEV_CMD_DELETE_NVM = 3,      /**< Delete  NVM FPLMN*/
    CI_DEV_CMD_DELETE_ALL = 4,      /**< Delete  SIM card and NVM FPLMN*/
    
    CI_DEV_CMD_NUM,
} _CiDevCmdType;
/** \remarks Common Data Section */
typedef UINT8 CiDevCmdType;

/** <paramref name="CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRoamingForbidenPlmnReq_struct{
    CiDevCmdType            cmdType;
    UINT8                   numOfPlmnIdentity;
    CiDevLtePlmnIdentity    plmnIdentityList[CI_DEV_MAX_NUM_ROAM_FORBID_PLMN];	
}CiDevPrimSetRoamingForbidenPlmnReq;

/** <paramref name="CI_DEV_PRIM_SET_ROAMING_FORBIDEN_PLMN_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRoamingForbidenPlmnCnf_struct{
    CiDevRc     rc;         /**< Result code. \sa CiDevRc. */     
}CiDevPrimSetRoamingForbidenPlmnCnf;

/**	 <paramref name="CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_REQ"> */
typedef CiEmptyPrim CiDevPrimGetRoamingForbidenPlmnReq;

/** <paramref name="CI_DEV_PRIM_GET_ROAMING_FORBIDEN_PLMN_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetRoamingForbidenPlmnCnf_struct{
    CiDevRc                 rc;
    UINT8                   numOfPlmnIdentity;
    CiDevLtePlmnIdentity    plmnIdentityList[CI_DEV_MAX_NUM_ROAM_FORBID_PLMN];	
}CiDevPrimGetRoamingForbidenPlmnCnf;

#define CI_DEV_MAX_NUM_BLACK_CELL 10
//ICAT EXPORTED STRUCT
typedef struct CiDevBlackCellId_struct
{
    UINT32                  afrcn;          /**<  LTE : EARFCN; URTAN: UARFCN; GSM: ARFCN */
    UINT16                  cellId; /**< LTE : PCI; URTAN: PSC; GSM: BSCI */
}CiDevBlackCellId;

//ICAT EXPORTED STRUCT
typedef struct CiDevBlackCellList_struct{
   UINT8                   numOfBlackCell;
   CiDevBlackCellId        blackCellIdList[CI_DEV_MAX_NUM_BLACK_CELL];  
}CiDevLteBlackCellList,CiDevUmtsBlackCellList,CiDevGsmBlackCellList;

/** <paramref name="CI_DEV_PRIM_SET_BLACK_CELL_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetBlackCellReq_struct{
   CiDevCmdType             cmdType;
   CiDevLteBlackCellList    LteBlackCellList;
   CiDevUmtsBlackCellList   UmtsBlackCellList;
   CiDevGsmBlackCellList    GsmBlackCellList;  
}CiDevPrimSetBlackCellReq;


/** <paramref name="CI_DEV_PRIM_SET_BLACK_CELL_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetBlackCellCnf_struct{
   CiDevRc     rc;         /**< Result code. \sa CiDevRc. */     
}CiDevPrimSetBlackCellCnf;

/**  <paramref name="CI_DEV_PRIM_GET_BLACK_CELL_REQ"> */
typedef CiEmptyPrim CiDevPrimGetBlackCellReq;

/** <paramref name="CI_DEV_PRIM_GET_BLACK_CELL_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetBlackCellCnf_struct{
   CiDevRc                  rc;
   CiDevLteBlackCellList    LteBlackCellList;
   CiDevUmtsBlackCellList   UmtsBlackCellList;
   CiDevGsmBlackCellList    GsmBlackCellList;  
}CiDevPrimGetBlackCellCnf;

/*20190819 CQ00116678 add by taow end*/

/*Lilei, CQ00113795, 20190215, begin*/
#define CI_DEV_MAX_NUM_FEATURES_CFG 80

/** <paramref name="CI_DEV_PRIM_SET_FEATURE_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetFeatureConfigReq_struct{
    CiDevFeature    feature;   /**< Features config info */
} CiDevPrimSetFeatureConfigReq;

/** <paramref name="CI_DEV_PRIM_SET_FEATURE_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetFeatureConfigCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
    CiDevFeature    feature;   /**< Features config info */
} CiDevPrimSetFeatureConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_FEATURE_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetFeatureConfigReq_struct{
    UINT32          featureId;   /**< Feature index. 0xFF indicates all feauters */
} CiDevPrimGetFeatureConfigReq;

/** <paramref name="CI_DEV_PRIM_GET_FEATURE_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetFeatureConfigCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
    UINT16          numFeatures;  /**< Num of feature IDs */
    CiDevFeature    feature[CI_DEV_MAX_NUM_FEATURES_CFG];   /**< Features config info */
} CiDevPrimGetFeatureConfigCnf;

#define CI_DEV_MAX_NUM_ROAM_CFG 10

//ICAT EXPORTED ENUM
typedef enum CiDevPdpType_enum
{
    PDP_TYPE_IPV4 = 0x1,
    PDP_TYPE_IPV6 = 0x2,
    PDP_TYPE_IPV4V6 = 0x3,
    PDP_TYPE_UNUSED = 0x4
}_CiDevPdpType;

typedef UINT8 CiDevPdpType;

//ICAT EXPORTED ENUM
typedef enum CiDevSetRoamAction_enum
{
    CI_DEV_ROAM_ADD_UPDATE = 0,
    CI_DEV_ROAM_DELETE = 1,
    
    CI_DEV_NUM_ROAM_ACTIONS
}_CiDevSetRoamAction;

typedef UINT8 CiDevSetRoamAction;

//ICAT EXPORTED STRUCT
typedef struct CiDevRoamConfig_struct{
    CiDevLtePlmnIdentity     plmn;
    CiDevPdpType             attachPdpType;
} CiDevRoamConfig;

/** <paramref name="CI_DEV_PRIM_SET_ROAM_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRoamConfigReq_struct{
    CiDevSetRoamAction       action;
    CiDevRoamConfig          config;
} CiDevPrimSetRoamConfigReq;

/** <paramref name="CI_DEV_PRIM_SET_ROAM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetRoamConfigCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimSetRoamConfigCnf;

/** <paramref name="CI_DEV_PRIM_GET_ROAM_CONFIG_REQ">   */
typedef CiEmptyPrim CiDevPrimGetRoamConfigReq;

/** <paramref name="CI_DEV_PRIM_GET_ROAM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetRoamConfigCnf_struct{
    CiDevRc                  rc;        /**< Result code. \sa CiDevRc. */
    UINT16                   num;       /**< Num of configs */
    CiDevRoamConfig          config[CI_DEV_MAX_NUM_ROAM_CFG];   /**< Attach PDP type info */
} CiDevPrimGetRoamConfigCnf;
/*Lilei, CQ00113795, 20190215, end*/

/*Lilei, CQ00119368, 20200331, begin*/
//ICAT EXPORTED ENUM
typedef enum CIDEV_CELL_DECODE_RC_ENUM
{
    CI_DEV_CELL_DECODE_NONE = 0,
    CI_DEV_CELL_DECODE_SUCCESS = 1,
    CI_DEV_CELL_DECODE_FAIL = 2,
    
    CI_DEV_NUM_CELL_DECODE_RC
} _CiDevCellDecodeRc;

typedef UINT8 CiDevCellDecodeRc;

//ICAT EXPORTED ENUM
typedef enum CIDEV_CELL_TYPE_ENUM
{
    CI_DEV_CELL_TYPE_SEARCH = 0,        /**< Cell result from search */
    CI_DEV_CELL_TYPE_SVC = 1,           /**< Serving cell */
    CI_DEV_CELL_TYPE_NEIGHBOR = 2,      /**< Neighbor cell. Only for GSM */
    CI_DEV_CELL_TYPE_INTRA_FREQ = 3,
    CI_DEV_CELL_TYPE_INTER_FREQ = 4,
    CI_DEV_CELL_TYPE_INTERRAT_GSM = 5,
    CI_DEV_CELL_TYPE_INTERRAT_UMTS = 6,
    CI_DEV_CELL_TYPE_INTERRAT_LTE = 7,
    
    CI_DEV_NUM_CELL_TYPE
} _CiDevCellType;

typedef UINT8 CiDevCellType;

//ICAT EXPORTED STRUCT
typedef struct CiDevGsmCellInfoItem_struct
{
    UINT16      arfcn;             	/**< Absolute radio frequency channel number */
    UINT8       bsic;		   	    /**< Base transceiver station identity code; range 0h-3Fh (6 bits); 0xFF means not present */
    INT16       rssi;         	    /**< GSM carrier RSSI. rssi = rxLevel-110; 0x7FFF means not present */
    INT16       sinr;               /**< SINR; 0x7FFF means not present */
    CiDevCellDecodeRc   decodeRc;   /**< Cell decode return code */
    CiDevCellType       cellType;   /**< Which type of cell */
} CiDevGsmCellInfoItem;

//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsCellInfoItem_struct
{
    UINT16      arfcn;            	/**< Absolute radio frequency channel number */
    UINT16      psc;                /**< Primary scrambling code for FDD or Cell parameter id for TDD */
    INT16       rssi;           	/**< UTRA carrier RSSI; 0x7FFF means not present */
    INT16       rscp;        	    /**< CPICH/PCCPCH received signal code power; 0x7FFF means not present */
    INT16       ecN0;        	    /**< CPICH Ec/N0, only valid for FDD; 0x7FFF means not present */
    INT16       sinr;               /**< SINR; 0x7FFF means not present */
    CiDevCellDecodeRc   decodeRc;   /**< Cell decode return code*/
    CiDevCellType       cellType;   /**< Which type of cell */
} CiDevUmtsCellInfoItem;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteCellInfoItem_struct
{
    UINT32	    earfcn;             /**< Eutra absolute radio frequency channel number */
	UINT16	    physCellId;         /**< Physical cell identity */
    INT16       rssi;               /**< EUTRA carrier RSSI; 0x7FFF means not present */
	INT16       rsrp;               /**< Reference signal receive power; 0x7FFF means not present */
	INT16       rsrq;               /**< Reference signal receive quality; 0x7FFF means not present */
    INT16       sinr;               /**< SINR; 0x7FFF means not present */
    CiDevCellDecodeRc   decodeRc;   /**< Cell decode return code*/
    CiDevCellType       cellType;   /**< Which type of cell */
} CiDevLteCellInfoItem;

#define CI_DEV_MAX_CELLS_INFO 33    /* 1 serving cell + 32 neighbor cells */

/** <paramref name="CI_DEV_PRIM_CELLS_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimCellsInfoInd_struct
{
    CiDevEngModeNetwork         network;                                 /**< Current network type (GSM/UMTS/LTE) */
    UINT8                       numGsmCells;     		                 /**< Number of GSM cells */
    CiDevGsmCellInfoItem        gsmCellInfo[ CI_DEV_MAX_CELLS_INFO ];    /**< GSM cells info */
    UINT8                 	    numUmtsCells;                            /**< Number of UMTS cells */
    CiDevUmtsCellInfoItem       umtsCellInfo[ CI_DEV_MAX_CELLS_INFO ];   /**< UMTS cells info */
    UINT8                       numLteCells;                             /**< Number of LTE cells */
    CiDevLteCellInfoItem        lteCellInfo[ CI_DEV_MAX_CELLS_INFO ];    /**< LTE cells info */
    /*Lilei, CQ00135655, 20220224, begin*/
    /* Parameters only valid for GSM, begin */
    UINT8                       radioLinkTimeout;                        /**< RADIO_LINK_TIMEOUT */
    UINT8                       counterS;                                /**< Radio link counter S. Invalid if radioLinkTimeout=0 */
    UINT8                       dscInitValue;                            /**< Initial value of downlink signaling failure counter */
    UINT8                       dsfCount;                                /**< Downlink signaling failure counter. Invalid if dscInitValue=0 */
    CiDevEngModeState           mode;       				             /**< Current mode (idle/dedicated) \sa CiDevEngModeState */
    CiBoolean                   isInVoiceCall;                           /**< Whether in a voice call */
    /* Parameters only valid for GSM, end */
    /*Lilei, CQ00135655, 20220224, end*/
} CiDevPrimCellsInfoInd;
/*Lilei, CQ00119368, 20200331, end*/

/*Lilei, CQ00126499, 20201207, begin*/
/** <paramref name="CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetDrxDynamicAdujustReq_struct{
    CiBoolean                   dynamicFlag;    /**< TRUE: enable dynamic adjust, FALSE: disable */
    INT16                       rsrpTh;         /**< Threshold of RSRP, range [-144, -44], default -105 */
    INT16                       snrTh;          /**< Threshold of SNR, range [-20, 30], default 5 */
} CiDevPrimSetDrxDynamicAdujustReq;

/** <paramref name="CI_DEV_PRIM_SET_DRX_DYNAMIC_ADJUST_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetDrxDynamicAdujustCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimSetDrxDynamicAdujustCnf;
/*Lilei, CQ00126499, 20201207, end*/


/* ==============  Added for REL13 ====================================================*/
/** <paramref name="CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimConfigHwPsmProfileReq_struct{
    CiBoolean   hwPsmEnable;           /**< if enable for hardware PSM feature. */
	
    UINT32      psmWindowThreshold;    /**< threshold for PSM windown to check T3412 or eDRX length */
	UINT8       eDrxToT3324Threshold;  /**< threshold for eDRX when both PSM/eDRX enabled */	
}CiDevPrimConfigHwPsmProfileReq;

/** <paramref name="CI_DEV_PRIM_CONFIG_HW_PSM_PROFILE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimConfigHwPsmProfileCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
}CiDevPrimConfigHwPsmProfileCnf;

/** <paramref name="CI_DEV_PRIM_GET_HW_PSM_PROFILE_REQ">   */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiDevPrimGetHwPsmProfileReq;

/** <paramref name="CI_DEV_PRIM_GET_HW_PSM_PROFILE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetHwPsmProfileCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
	
    CiBoolean   hwPsmEnable;           /**< if enable for hardware PSM feature. */
    UINT32      psmWindowThreshold;    /**< threshold for PSM windown to check T3412 or eDRX length */
	UINT8       eDrxToT3324Threshold;  /**< threshold for eDRX when both PSM/eDRX enabled */	
}CiDevPrimGetHwPsmProfileCnf;

/*Lilei, CQ00127745, 20210119, begin*/
/** <paramref name="CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetAntennaTunerParamReq_struct{
	UINT8       paramId;    /**< ID of the set of antenna tuner parameters */	
} CiDevPrimSetAntennaTunerParamReq;

/** <paramref name="CI_DEV_PRIM_SET_ANTENNA_TUNER_PARAM_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetAntennaTunerParamCnf_struct{
    CiDevRc         rc;        /**< Result code. \sa CiDevRc. */
} CiDevPrimSetAntennaTunerParamCnf;
/*Lilei, CQ00127745, 20210119, end*/

/*Lilei, CQ00131521, 20210706, begin*/
/** <paramref name="CI_DEV_PRIM_PAGING_FAILURE_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimPagingFailureInd_struct
{
    UINT8                       reserve;
} CiDevPrimPagingFailureInd;
/*Lilei, CQ00131521, 20210706, end*/

/* add by taow 20220228 CQ00135794 begin*/

#define CI_DEV_NUM_FORBIDDEN_PLMN_SIM 8

//ICAT EXPORTED STRUCT
typedef struct CiDevForbidenPlmnListDataSim_struct{         

    CiDevLtePlmnIdentity    fPlmnList[CI_DEV_NUM_FORBIDDEN_PLMN_SIM];/**<the array is used in GET response*/
    UINT8                   numFPlmn; /**< set:MAX num is 1;
                                                                  * del: 0 del all ,1 del the PLMN in forbidenPlmnList[0]
                                                                  * get: max num is 8 CI_DEV_NUM_FORBIDDEN_PLMN_SIM*/
    UINT8				    reserved1[3];
}CiDevForbidenPlmnListDataSim;

#define CI_DEV_NUM_FORBIDDEN_PLMN_NVM 10

//ICAT EXPORTED STRUCT
typedef struct CiDevForbidenPlmnListDataNvm_struct{         
    CiDevLtePlmnIdentity    hPlmnList[CI_DEV_NUM_FORBIDDEN_PLMN_NVM]; 
    CiDevLtePlmnIdentity    fPlmnList[CI_DEV_NUM_FORBIDDEN_PLMN_NVM];
    UINT8                   NumHPlmn;
    UINT8                   numFPlmn; 
    UINT8                   currentIndex;/**<currentIndex is used in GET response*/
    UINT8                   totalNum;/**<totalNum  is used in GET responsenum of imsiPlmn stored in UE */
    UINT8				    reserved1[3];
}CiDevForbidenPlmnListDataNvm;

#define CI_DEV_NUM_EHPLMN_PER_IMSI           10

//ICAT EXPORTED STRUCT
typedef struct CiDevEhplmnList_struct
{
    CiDevLtePlmnIdentity        imsiPlmn;    
    CiDevLtePlmnIdentity        eHplmnList[CI_DEV_NUM_EHPLMN_PER_IMSI];
    UINT8                       numEhplmn;
    UINT8                       currentIndex;/**<currentIndex is used in GET response*/
    UINT8                       totalNum; /**<totalNum  is used in GET responsenum of imsiPlmn stored in UE */
    UINT8				        reserved1[3];
    
    
}CiDevEhplmnListData;

/* add by taow 20220228 CQ00135794 end*/
/*add by taow 20220829 CQ00138615 begin*/
#define CI_DEV_NUM_BARRED_PLMN 16

//ICAT EXPORTED STRUCT
typedef struct CiDevBarredPlmnData_Tag
{
    UINT8                   plmnNum;
    UINT8				    reserved1[3];
    CiDevLtePlmnIdentity	BarredPlmnList[CI_DEV_NUM_BARRED_PLMN];/** all PLMN will be barred in the list,including HPLMN */
}CiDevBarredPlmnData;

/*add by taow 20220829 CQ00138615 end*/

/*add by taow CQ00139968 20221108 begin */
#define     CI_DEV_REMAP_CAUSE_LIST_SIZE       10
#define     CI_DEV_REMAP_CAUSE_PRO_LIST_SIZE   10
//ICAT EXPORTED ENUM
typedef enum CiDevRemapProcedureTag
{
    CI_DEV_REMAP_GMM_ATTCH_RAU_REJ = 0,
    CI_DEV_REMAP_GMM_SERVICE_REJ,
    CI_DEV_REMAP_GMM_DETACH,
    CI_DEV_REMAP_MM_LU_REJ,
    CI_DEV_REMAP_CM_SERVICE_REJ,
    CI_DEV_REMAP_MM_ABORT,
    CI_DEV_REMAP_EMM_ATTACH_TAU_REJ,
    CI_DEV_REMAP_EMM_SERVICE_REJ,
    CI_DEV_REMAP_EMM_DETACH,
    CI_DEV_REMAP_MAX_PROC

} _CiDevRemapProcedure;


typedef UINT32 CiDevRemapProcedure;
//ICAT EXPORTED ENUM
typedef enum CiDevRemapCauseTag
{
    CI_DEV_REMAP_CAUSE_0 = 0,
    CI_DEV_REMAP_CAUSE_1,
    CI_DEV_REMAP_CAUSE_2,
    CI_DEV_REMAP_CAUSE_3,
    CI_DEV_REMAP_CAUSE_4,
    CI_DEV_REMAP_CAUSE_5,
    CI_DEV_REMAP_CAUSE_6,
    CI_DEV_REMAP_CAUSE_7,
    CI_DEV_REMAP_CAUSE_8,
    CI_DEV_REMAP_CAUSE_9,
    CI_DEV_REMAP_CAUSE_10,
    CI_DEV_REMAP_CAUSE_11,
    CI_DEV_REMAP_CAUSE_12,
    CI_DEV_REMAP_CAUSE_13,
    CI_DEV_REMAP_CAUSE_14,
    CI_DEV_REMAP_CAUSE_15,
    CI_DEV_REMAP_CAUSE_16,
    CI_DEV_REMAP_CAUSE_17,
    CI_DEV_REMAP_CAUSE_18,
    CI_DEV_REMAP_CAUSE_19,
    CI_DEV_REMAP_CAUSE_20,
    CI_DEV_REMAP_CAUSE_21,    
    CI_DEV_REMAP_CAUSE_22,
    CI_DEV_REMAP_CAUSE_23,
    CI_DEV_REMAP_CAUSE_24,
    CI_DEV_REMAP_CAUSE_25,
    CI_DEV_REMAP_CAUSE_26,
    CI_DEV_REMAP_CAUSE_27,
    CI_DEV_REMAP_CAUSE_28,
    CI_DEV_REMAP_CAUSE_29,
    CI_DEV_REMAP_CAUSE_30,
    CI_DEV_REMAP_CAUSE_31,
    CI_DEV_REMAP_CAUSE_32,
    CI_DEV_REMAP_CAUSE_33,
    CI_DEV_REMAP_CAUSE_34,
    CI_DEV_REMAP_CAUSE_35,
    CI_DEV_REMAP_CAUSE_36,
    CI_DEV_REMAP_CAUSE_37,
    CI_DEV_REMAP_CAUSE_38, 
    CI_DEV_REMAP_CAUSE_39, 
    CI_DEV_REMAP_CAUSE_40,    
    CI_DEV_REMAP_CAUSE_41,    
    CI_DEV_REMAP_CAUSE_42,
    CI_DEV_REMAP_CAUSE_95 = 95,
    CI_DEV_REMAP_CAUSE_96,
    CI_DEV_REMAP_CAUSE_97,
    CI_DEV_REMAP_CAUSE_98,
    CI_DEV_REMAP_CAUSE_99,
    CI_DEV_REMAP_CAUSE_100,
    CI_DEV_REMAP_CAUSE_101,
    CI_DEV_REMAP_CAUSE_111 = 111,
    CI_DEV_REMAP_CAUSE_NO_CAUSE= 0XFE,
    CI_DEV_REMAP_MAX_CAUSE = 255
} _CiDevRemapCause;
typedef UINT8 CiDevRemapCause;
//ICAT EXPORTED STRUCT
typedef struct CiDevRemapCauseEntryTag
{
    CiDevRemapCause              originalCause;
    CiDevRemapCause              remapHPLMNcause;
    CiDevRemapCause              remapVPLMNcause;
 
    UINT8                        reserved[5];
} CiDevRemapCauseEntry;

//ICAT EXPORTED STRUCT
typedef struct CiDevRemapCauseProEntryTag
{
    CiDevRemapProcedure          procedureId;
    CiDevRemapCauseEntry         remapCauseEntry[CI_DEV_REMAP_CAUSE_LIST_SIZE];
    UINT8     					 numCauseRemap;
    UINT8                        reserved[3];
} CiDevRemapCauseProEntry;
//ICAT EXPORTED STRUCT
typedef struct CiDevRemapCauseData_struct{   
    CiDevRemapCauseProEntry remapCauseProEntry[CI_DEV_REMAP_CAUSE_PRO_LIST_SIZE];       
    UINT8                   numCausePro; 
    UINT8                   reserved[3];
}CiDevRemapCauseData;
//ICAT EXPORTED STRUCT
typedef struct CiDevRejectCounterTag
{
    CiDevRemapCause              rejectCause;
    INT8                    rejectHplmnCounter;
    INT8                    rejectVplmnCounter;
    INT8                    reserved[1];
} CiDevRejectCounter;

//ICAT EXPORTED STRUCT
typedef struct CiDevRejectCounterData_struct{   
    CiDevRejectCounter    remapRejectCounter[CI_DEV_REMAP_CAUSE_LIST_SIZE];   
    INT8             numRejectCounter; 
    INT8             reserved[3];
}CiDevRejectCounterData;

/*add by taow CQ00139968 20221108 end */
/*add by taow 20221215 CQ00140628 begin*/

//ICAT EXPORTED STRUCT
typedef struct CiDevMultipleGsmBandTag
{
   UINT8         gsmMultiple;
   UINT8         dcsMultiple;
   UINT8         pcsMultiple;
   UINT8         reserved;
}CiDevMultipleGsmBand;
/*add by taow 20221215 CQ00140628  end*/
/*add by taow 20230720  CQ00144858 begin*/
//ICAT EXPORTED STRUCT
typedef struct CiDevRplmnInfoTag
{
	Boolean                      lastEpsRplmnIsValid;
	Boolean                      lastRplmnIsValid;
    CiDevEngModeNetwork          lastRplmnNwMode;
	CiDevLtePlmnIdentity         lastEpsRplmn;
	CiDevLtePlmnIdentity         lastRplmn;
}CiDevRplmnInfo;
/*add by taow 20230720  CQ00144858 end*/

/*add by taow 20231110 CQ00146922 begin*/
#define CI_DEV_MAX_NUM_WHITE_CELL 10
//ICAT EXPORTED STRUCT
typedef struct CiDevPlmnId_struct
{
    UINT16                  mcc;
    //2-3 digits of MNC
    UINT16                  mnc;
    //Length of MNC, value range (2,3)
    UINT8                   lenOfMnc;
    UINT8                   dummy;
}CiDevPlmnId;

//ICAT EXPORTED STRUCT
typedef struct CiDevWhiteCellId_struct
{
    UINT32                  xArfcn;          /**<  LTE : EARFCN; URTAN: UARFCN; GSM: ARFCN */
    UINT16                  xCellId;         /**< LTE : PCI; URTAN: PSC; GSM: BSIC */
    UINT16                  dummy0;
    UINT32                  dummy1[6]; 
}CiDevWhiteCellId;

//ICAT EXPORTED STRUCT
typedef struct CiDevWhiteCellList_struct{
   CiDevPlmnId             plmn;
   UINT8                   maxNumOfWhiteCell;
   UINT8                   numOfWhiteCell;
   CiDevWhiteCellId        whiteCellList[CI_DEV_MAX_NUM_WHITE_CELL];  
}CiDevLteWhiteCellList,CiDevUmtsWhiteCellList,CiDevGsmWhiteCellList;

//ICAT EXPORTED STRUCT
typedef struct CiDevWhiteCellListInfoTag
{   CiBoolean                    isEnable; /**<  TRUE : Enable; FALSE: DISABLE */
    UINT8                        dummy[3];
    CiDevLteWhiteCellList        lteWhiteCellList;
	CiDevUmtsWhiteCellList       umtsWhiteCellList;
	CiDevGsmWhiteCellList        gsmWhiteCellList;
}CiDevWhiteCellListInfo;
/*add by taow 20231110 CQ00146922 end*/


/* add by taow 20211214 CQ00134561 begin*/
//ICAT EXPORTED ENUM 
typedef enum CiDevFeatureId_TAG{
    CI_DEV_FT_BAND_FREQ_BASE = 0,  
    CI_DEV_FT_BAND_ORDER = 1, 
    CI_DEV_FT_FORBIDDEN_PLMN_SIM = 2,
    CI_DEV_FT_FORBIDDEN_PLMN_NVM = 3,
    CI_DEV_FT_EHPLMN = 4,
    /*add by taow 20220829 CQ00138615 begin*/
    CI_DEV_FT_BARRED_PLMN = 5,
    /*add by taow 20220829 CQ00138615 end*/
    CI_DEV_FT_MEAS_REPORT_CFG = 6, /*Lilei, CQ00138904, 20220916*/
    /*add by taow CQ00139968 20221108 begin */
    CI_DEV_FT_REMAP_CAUSE,
    CI_DEV_FT_REJECT_COUNTER,
    /*add by taow CQ00139968 20221108 end */
    /*add by taow 20221215 begin*/
    CI_DEV_FT_MULTIPLE_GSM_BAND,
    /*add by taow 20221215 end*/
    /*add by taow 20230720  CQ00144858 begin*/
    CI_DEV_FT_RPLMN_INFO,
    /*add by taow 20230720  CQ00144858 end*/
    /*add by taow 20231110 CQ00146922 begin*/
    CI_DEV_FT_WHITE_CELL_LIST,
    /*add by taow 20231110 CQ00146922 end*/
    CI_DEV_FT_NUM,
    
    CI_DEV_FT_MAX = 65535
} _CiDevFeatureId;
/** \remarks Common Data Section */
typedef UINT16 CiDevFeatureId;

#define CI_DEV_NUM_PARAM 20
//ICAT EXPORTED STRUCT
typedef struct CiDevBandOffset_Tag
{   
    UINT8       bandId;
	UINT8       reserved1[3];
	UINT32      bandFreqLow;
	UINT32      bandFreqHigh;
}CiDevBandFreq;

//ICAT EXPORTED STRUCT
typedef struct CiDevAbmmBandOffsetData_Tag
{
    UINT8                   bandFreqNum;
    UINT8				    reserved1[3];
    CiDevBandFreq	        bandFreq[CI_DEV_NUM_PARAM];
}CiDevBandFreqBaseData;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteSetBandOrderReq_struct{   
    UINT8               lteBandNum;    
    UINT8               lteBandList[CI_DEV_NUM_PARAM]; 
    UINT8               reserved1[3];
}CiDevLteSetBandOrderData;

//ICAT EXPORTED STRUCT
typedef struct CiDevMeasReportConfigData_struct{   
    INT8               offset_scell;        /*serving cell, LTE RSRP - offset, for check A1~A5 MR event Condition.*/
    INT8               offset_ncell_lte;    /*LTE ncell, LTE RSRP - offset, for check A1~A5 MR event Condition.*/
}CiDevMeasReportConfigData;

//ICAT EXPORTED UNION:_CiDevFeatureId
typedef union CiDevCommonFeatureData_union
{
    CiDevBandFreqBaseData         bandFreqBase;
    CiDevLteSetBandOrderData      lteSetBandOrder;
    /* add by taow 20220228 CQ00135794 end*/
    CiDevForbidenPlmnListDataSim  forbidenPlmnDataSim;
	CiDevForbidenPlmnListDataNvm  forbidenPlmnDataNvm;
    CiDevEhplmnListData           ehplmnData;             
    /* add by taow 20220228 CQ00135794 end*/
    
    /*add by taow 20220829 CQ00138615 begin*/
    CiDevBarredPlmnData           barredPlmnData;/** all PLMN will be barred in the list,including HPLMN */
    /*add by taow 20220829 CQ00138615 end*/
    CiDevMeasReportConfigData     measReportConfig; /*Lilei, CQ00138904, 20220916*/
    /*add by taow 20221108 CQ00139968 begin */
    CiDevRemapCauseData           remapCauseData;
    CiDevRejectCounterData        rejectCounterData;
    /*add by taow 20221108 CQ00139968 end */
    /*add by taow 20221215 begin*/
    CiDevMultipleGsmBand         multipleGsmBand;
    /*add by taow 20221215 end*/
     /*add by taow 20230720  CQ00144858 begin*/
    CiDevRplmnInfo               rplmnInfo;
    /*add by taow 20230720  CQ00144858 end*/
     /*add by taow 20231110 CQ00146922 begin*/
    CiDevWhiteCellListInfo       whiteCellListInfo;
     /*add by taow 20231110 CQ00146922 end*/
    UINT8   dummy[1024];
} CiDevCommonFeatureData;

/** <paramref name="CI_DEV_PRIM_SET_COMMON_FEATURE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetCommonFeatureReq_struct{
    CiDevCmdType            cmdType;   /*@ITEM_DESC@ 0: Set or modify CMD  1: Del CMD*/
                                        /** featureId == CI_DEV_FT_BAND_ORDER  cmdType only use CI_DEV_CMD_SET */
    
    UINT8                   reserved;
    CiDevFeatureId          featureId; /*@ITEM_DESC@ 0: Set Band Freq Base   1: Set lte Band Order 2:FPlmn sim 3:FPLMN nvm,4:ehplmn*/
    CiDevCommonFeatureData  commonFtData;
}CiDevPrimSetCommonFeatureReq;
/** <paramref name="CI_DEV_PRIM_SET_COMMON_FEATURE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetCommonFeatureCnf_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */ 
    CiDevFeatureId          featureId; /*@ITEM_DESC@ 0: Set Band Freq Base  1: Set lte Band Order 2:FPlmn sim 3:FPLMN nvm,4:ehplmn*/
    CiDevCommonFeatureData  commonFtData;
}CiDevPrimSetCommonFeatureCnf;

/** <paramref name="CI_DEV_PRIM_GET_COMMON_FEATURE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetCommonFeatureReq_struct{    
    CiDevFeatureId   featureId;/*@ITEM_DESC@ 0: Set Band Freq Base  1: Set lte Band Order 2:FPlmn sim 3:FPLMN nvm,4:ehplmn */
    UINT32           index;
    UINT32           reserved1;
    UINT32           reserved2;
    
}CiDevPrimGetCommonFeatureReq;
/** <paramref name="CI_DEV_PRIM_GET_COMMON_FEATURE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetCommonFeatureCnf_struct{
    CiDevRc                 rc;
    CiDevFeatureId          featureId;/*@ITEM_DESC@ 0: Set Band Freq Base  1: Set lte Band Order 2:FPlmn sim 3:FPLMN nvm,4:ehplmn*/
    CiDevCommonFeatureData  commonFtData;

}CiDevPrimGetCommonFeatureCnf;
/* add by taow 20211214 CQ00134561 end*/
/*add by lilei 20220119 CQ00135497 begin */
//ICAT EXPORTED ENUM
typedef enum CIDEV_TX_RX_OPTION_TAG{
    CI_DEV_TX_START = 0,
    CI_DEV_RX_START,
    CI_DEV_TX_RX_STOP,

    CI_DEV_NUM_TX_RX
} _CiDevTxRxOption;

typedef UINT8 CiDevTxRxOption;

/** <paramref name="CI_DEV_PRIM_SET_NST_TX_RX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetNstTxRxReq_struct {
	CiDevTxRxOption         option;         /**< Option. \sa CiDevTxRxOption */
    CiDevEngModeNetwork     networkMode;    /**< 0: GSM; 1: UMTS; 2: LTE */
    UINT8                   band;           /**< GSM: 1-PGSM,2-DCS,4-PCS,8-EGSM,16-GSM450,32-GSM480,64-GSM850; */
                                            /*     WCDMA: 1-BAND1,2-BAND2,...,14:BAND14;  LTE: 1-BAND1,2-BAND2... */
	UINT32                  arfcn;
    INT16                   power;          /**< Tx or Rx power. For GSM TX, range [0,1], otherwise in 0.1Dbm unit. */
    UINT8                   slot;           /**< GSM TX slot. Range [1,4]. */
	UINT8                   bandwidth; 	    /**< LTE bandwidth. Range [0,5]. */
    
    UINT32      			reserved1;
	UINT32      			reserved2;
	UINT32      			reserved3;
	UINT32      			reserved4;
    UINT32      			reserved5;
	UINT32      			reserved6;
	UINT32      			reserved7;
	UINT32      			reserved8;
} CiDevPrimSetNstTxRxReq;

/** <paramref name="CI_DEV_PRIM_SET_NST_TX_RX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetNstTxRxCnf_struct {
    CiDevRc                 rc;             /**< Result code. \sa CiDevRc */
	INT16                   rssiPri;        /**<  The Rssi value of primary antenna to be returned for RX mode. */
	INT16                   rssiSec;        /**<  The Rssi value of secondary antenna to be returned for RX mode. Only used for LTE now. */
    
    UINT32      			reserved1;
	UINT32      			reserved2;
	UINT32      			reserved3;
	UINT32      			reserved4;
} CiDevPrimSetNstTxRxCnf;
/*add by lilei 20220119 CQ00135497 end */

/* <INUSE> */
/**	 <paramref name="CI_DEV_PRIM_SET_SIM_SLOT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSimSlotReq_struct {
	UINT8     	     simSlot; 		/**< 0 - sim slot 1; 1 - sim slot 2 */
	UINT8            reserved[3];
}CiDevPrimSetSimSlotReq;

/* <INUSE> */
/**	 <paramref name="CI_DEV_PRIM_SET_SIM_SLOT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetSimSlotCnf_struct {
	CiDevRc          rc;	       /**< Result code  \sa CiDevRc */
}CiDevPrimSetSimSlotCnf;

/* <INUSE> */
/**	 <paramref name="CI_DEV_PRIM_GET_SIM_SLOT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSimSlotReq_struct {
	UINT8            reserved[4];
}CiDevPrimGetSimSlotReq;

/* <INUSE> */
/**	 <paramref name="CI_DEV_PRIM_GET_SIM_SLOT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetSimSlotCnf_struct {
	CiDevRc          rc;	       /**< Result code  \sa CiDevRc */
	
	UINT8     	     simSlot; 		/**< 0 - sim slot 1; 1 - sim slot 2 */
	UINT8            reserved[3];
}CiDevPrimGetSimSlotCnf;


/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_dev_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_DEV_NUM_CUST_PRIM will be set to 0 in the "ci_dev_cust.h" file.
 */
#include "ci_dev_cust.h"

#define CI_DEV_NUM_PRIM ( CI_DEV_NUM_COMMON_PRIM + CI_DEV_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_DEV_NUM_PRIM CI_DEV_NUM_COMMON_PRIM

#endif /* CI_CUSTOM_EXTENSION */


#ifdef NAS_UNIT_TEST
typedef struct CiDevPrimSetSimReqTag{
    UINT8 nasActiveSim;
} CiDevPrimSetSimReq;
#endif

/***************************Start of CI Interface Definitions of Old CI Versions***********************************************/

/******************************************************************************
 * All old CI interface definations should be backed up here, re-defined
 * with the suffix of CI version number
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiDevGsmServingCellInfo_v0002_struct
{
    UINT8     rxSigLevel;           /**< Receive signal level [range: 0h-3Fh] */
    UINT8     rxSigLevelFull;   /**< Receive signal level accessed over all TDMA frames  [range: 0h-3Fh]*/
    UINT8     rxSigLevelSub;    /**< Receive signal level accessed over subset of TDMA frames  [range: 0h-3Fh]*/
    UINT8     rxQualityFull;        /**< Receive quality accessed over all TDMA frames [range: 0-7] */
    UINT8     rxQualitySub;     /**< Receive quality accessed over subset of TDMA frames [range: 0-7] */
    UINT8     rac;                      /**< Routing area code [range: 0-1 (1 bit)] */
    UINT8     bsic;                 /**< Base transceiver station identity code [range: 0h-3Fh (6 bits)] */
    UINT8     nom;                  /**< Network operation mode [range: MODE_1= 0 / MODE_2= 1 / MODE_3= 2] */
    UINT8     nco;                  /**< Network control order  [range: NC_0=0 / NC_1=1 / NC_2=2 / NC_RESET=3] */
    UINT8     bs_pa_mfrms;      /**< Number of multiframes between paging messages sent [range: 0-7] */

    UINT16    mcc;                  /**< Mobile country code [range:  0-999 (3 digits)] */
    UINT16    mnc;                  /**< Mobile network code [range: 0-99 (2 digits)] */
    UINT16    lac;                  /**< Location area code [range: 0h-FFFFh (2 octets)] */
    UINT16    ci;                   /**< Cell identity [range: 0h-FFFFh (2 octets)] */
    UINT16    arfcn;                /**< Absolute radio frequency channel number [range:  0-1023] */

    INT16     C1;                   /**< Path loss criterion parameter #1 */

    INT16     C2;                   /**< Path loss criterion parameter #2 */

    INT16     C31;                  /**< GPRS signal level threshold criterion parameter*/

    INT16     C32;                   /**< GPRS cell ranking criterion parameter */


    UINT16    t3212;                /**< Periodic LA update timer (T3212) in minutes */
    UINT16    t3312;                /**< Periodic RA update timer (T3312) in minutes */

    CiBoolean pbcchSupport;                         /**< Support of PBCCH \sa CCI API Ref Manual */
    UINT8                   TxPowerLevel;           /**< Tx power level [range: 0h-3Fh] */
    UINT8                   timingAdv;              /**< Timing advance [range 0-63] */
    CiBoolean               hoppingChannel;         /**< Hopping channel */
    CiBoolean               EGPRSSupport;           /**< EGPRS support capability */
    CiDevEngChannelType     ChType;                         /**< Values are TCH_F = 1, TCH_H = 2, SDCCH_4 = 4, SDCCH_8 = 8 \sa CIDEV_ENGMODE_CHANNEL_TYPE */
    CiBoolean               nccPermitted;           /**< The NCC permitted parameter sets the NCCs (network color codes) that the mobile station is permitted to report. \sa CCI API Ref Manual */
    UINT8                   RadioLinkTimeout;       /**< Radio link timeout [range: value >=0] */
    UINT16                  hoCount;                /**< Handovers counter [range: value>=0] */
    UINT16                  hoSuccessCount;         /**< Success handovers counter [range: value>=0] */
    UINT16                  chanAssCount;           /**< Channel assignment counter [range: value>=0]*/
    UINT16                  chanAssSuccessCount;    /**< Success channel assignment counter [range: value>=0]*/

    UINT16    arfcnTch;                             /**< ARFCN for traffic channel, only valid for dedicated state [range:  0-1023]*/
    UINT8      timeSlot;                                /**< Time slot, only valid for dedicated state*/
    CiDevPacketIdleType  isInPacketIdle;                /**< Only valid for idle state \sa CiDevPacketIdleType */
    /*Michal Bukai - I-Mate Addition. Start:*/
    CiBoolean               IsForbiddenLA;          /**< Indicates if cell belongs to forbidden location area. FALSE: Cell is not in forbidden LA or forbidden status is unknown; TRUE: Cell is in forbidden LA. \sa CCI API Ref Manual */
    CiDevCellPrioriytType   CellPriority;           /**< Cell priority for cell selection or reselection. Cell priority can be normal, low or barred. \sa CiDevCellPrioriytType */
    UINT8                   HSN;                    /**< Hopping sequence number. Value 0 means cyclic hopping is done*/
    CiDevHoppingGroup       HoppingGroup;           /**< List of ARFCNs assigned for frequency hopping . \sa CiDevHoppingGroup */
    /*Michal Bukai - I-Mate Addition. End*/
/*Added by Lilei for Network Info CQ56702, begin*/
    UINT8                   gsmBand;                /**< 0:PGSM_900; 1:DCS_GSM_1800; 2:PCS_GSM_1900; 3:EGSM_900; 4:GSM_450; 5:GSM_480; 6:GSM_850 */
    UINT8                   channelMode;            /**< Mode of a dedicated channel, used during dedicated channel setup to specify channel mode (signaling-only, speech or data), mode version and data rate. */
/*Added by Lilei for Network Info CQ56702, end*/
/*Lilei, CQ00092855, 20150427, begin*/
    UINT8                   lenOfMnc;             /**< Length of MNC, value range (2,3) */
/*Lilei, CQ00092855, 20150427, end*/
 
}CiDevGsmServingCellInfo_V0001, CiDevGsmServingCellInfo_V0002;


//ICAT EXPORTED STRUCT
typedef struct CiDevEngModeGsmData_v0002_struct
{
    CiDevGsmServingCellInfo_V0002     		svcCellInfo;		/**< Serving cell information \sa CiDevGsmServingCellInfo_struct */

    CiDevGsmGMMInfo		    		    GMMInfo;		/**< Mobility management information  \sa CiDevGsmGMMInfo_struct */
    CiDevAMRInfo			    		AMRInfo;		/**< AMR information \sa CiDevAMRInfo_struct */
    CiDevGPRSPTMInfo		    		GPRSPTMInfo;	/**< Packet data information \sa CiDevGPRSPTMInfo_struct */

    UINT8                               numNCells;     		/**< Number of neighboring cells [0..CI_DEV_MAX_GSM_NEIGHBORING_CELLS] */
    UINT8                       			res1U8[3];    												/**< (padding) */
    CiDevGsmNeighboringCellInfo 		nbCellInfo[ CI_DEV_MAX_GSM_NEIGHBORING_CELLS ]; 		/**< Neighboring cell information \sa CiDevGsmNeighboringCellInfo_struct */

    UINT8                 		        numInterRATNCells;     									/**< Number of InterRAT cells [0..CI_DEV_MAX_GSM_NEIGHBORING_CELLS] */
   UINT8                       	                     res2U8[3];                     									/**< (padding) */
    CiDevGsmUMTSNeighboringCellInfo     InterRATCellInfo[ CI_DEV_MAX_GSM_NEIGHBORING_CELLS ];	/**< InterRAT cell information \sa CiDevCiDevGsmUMTSNeighboringCellInfo */

} CiDevEngModeGsmData_v0001,CiDevEngModeGsmData_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGsmEngmodeInfoInd_v0002_struct
{
  CiDevEngModeState     mode;       		/**< Current Mode (Idle/Dedicated). \sa CiDevEngModeState */
  UINT8                 releaseVersion; /**< 3GPP release versions */       
  UINT8               	res1U8[2];  		/**< (padding) */
  CiDevEngModeGsmData_v0002	info;  			/**< GSM Engineering Mode information. \sa CiDevEngModeGsmData_struct */
} CiDevPrimGsmEngmodeInfoInd_v0001,CiDevPrimGsmEngmodeInfoInd_v0002;
//ICAT EXPORTED STRUCT

typedef struct CiDevUmtsUeOperationStatus_v0002_struct
{
    CiDevEngModeUeRrcState  			rrcState;         				/**< RRC state \sa CiDevEngModeUeRrcState */
    UINT8                   					numLinks;         				/**< Number of radio links */

    UINT16                  					srncId;           				/**<  U-RNTI: SRNC identifier */
    UINT32                  					sRnti;            					/**<  U-RNTI: S-RNTI */
    CiCipherAlgorithmInfo   				csCipherInfo;     				/**<  CS domain ciphering information. \sa CiCipherAlgorithm_struct */
    CiCipherAlgorithmInfo   				psCipherInfo;     				/**<  PS domain ciphering information. \sa CiCipherAlgorithm_struct */
    CiBoolean	 						HSDPAActive;				/**<  TRUE - HSDPA is currently activated; FALSE - other  \sa CCI API Ref Manual  */
    CiBoolean	 						HSUPAActive;				/**<  TRUE - HSUPA is currently activated; FALSE - other  \sa CCI API Ref Manual  */
    UINT16							MccLastRegisteredNetwork;	/**<  Mcc of last registered network */
    UINT16							MncLastRegisteredNetwork;	/**<  Mnc of last registered network */
    INT32	       						TMSI;						/**<  TMSI */
    INT32	       						PTMSI;						/**<  PTMSI */
    CiBoolean                                             IsSingleMmRejectCause;		/**<  TRUE - only one MM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual  */
    CiBoolean                                             IsSingleGmmRejectCause;	/**<  TRUE - only one GMM reject cause reported during the last engineering information period; FALSE - other \sa CCI API Ref Manual  */
    CiDevEngMMRejectCauseCodeType	 MMRejectCause;				/**<  The one that was reported during the last engineering information period reject cause (10.5.3.6) sent in CM Service Reject, Abort, MM-Status, and Location Updating Reject messages to MM from the network. \sa CiDevEngMMRejectCauseCodeType */
    CiDevEngGMMRejectCauseCodeType	 GMMRejectCause;			/**<  Reported during the last engineering information period  \sa CiDevEngGMMRejectCauseCodeType */
    UINT8 								 mmState;					/**<  MM state refer to 3GPP 24.008 section 4.1.2  */  /* see enum MmState in Mm_comm.h. */
    UINT8 								 gmmState;					/**<  GMM state refer to 3GPP 24.008 section 4.1.3  */  /* see enum GmmState in Gmm_comm.h */
    UINT8								 gprsReadyState;				/**<  0 - IDLE_STATE / 1 - STANDBY_STATE / 2 - READY_STATE. */ /* see enum GprsReadyState in grrmrtyp.h. */
    UINT16							 readyTimerValueInSecs;		/**<  MM ready timer value in sec [value >0] */
    UINT8								 NumActivePDPContext;		/**<  Number of active PDP contexts */
	/*Michal Bukai - I-Mate Addition. Start:*/
	UINT32              ULThroughput;           /**< UL throughput in octets per second */
	UINT32              DLThroughput;           /**< DL throughput in octets per second */
	/*Michal Bukai - I-Mate Addition. End*/
/*Added by Lilei for Network Info CQ56702, begin*/
    UINT8                           serviceStatus;              /**< Service status */ /* see enum ServiceStatus in Mmr_sig.h. */
    UINT8                           pmmState;                   /**< UMM state for PS services */ /* see enum UmmState in Mm_comm.h. */
/*Added by Lilei for Network Info CQ56702, end*/
/*Lilei, CQ00082362, 20150116, begin*/
    UINT8                           LAU_status;                 /**<Current update status of the UE */ /* see enum LocationUpdateStatus in Mmr_sig.h. */
    UINT16                          LAU_count;                  /**<LAU attempt counter as held by UE; number of consecutive LAU failures in current LAU procedure attempt */
    UINT8                           RAU_status;                 /**<RAU status of the UE */ /* see enum GprsUpdateStatus in Mmr_sig.h. */
    UINT16                          RAU_count;                  /**<RAU attempt counter as held by UE; number of consecutive RAU failures in current RAU procedure attempt*/
/*Lilei, CQ00082362, 20150116, end*/
}CiDevUmtsUeOperationStatus_v0001,CiDevUmtsUeOperationStatus_v0002;

//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsServingCellInfo_v0002_struct
{
    CiBoolean                        		 	sCellMeasPresent; 	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    CiBoolean                         			sCellParamPresent;	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    CiBoolean                         			ueOpStatusPresent;	/**< TRUE - is present; FALSE - is not present. \sa CCI API Ref Manual */
    UINT8                             				res1U8;				/**< padding */
    CiDevUmtsServingCellMeasurements  	sCellMeas;  			/**< SCell measurements \sa CiDevUmtsServingCellMeasurements_struct */
    CiDevUmtsServingCellParameters    	sCellParam; 			/**< PLMN/cell parameters \sa CiDevUmtsServingCellParameters_struct 	*/
    CiDevUmtsUeOperationStatus_v0001        		ueOpStatus; 			/**< UE operation status \sa CiDevUmtsUeOperationStatus_struct 		*/
} CiDevUmtsServingCellInfo_v0001,CiDevUmtsServingCellInfo_v0002;

//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeSvcCellInfoInd_v0002_struct
{
  CiDevEngModeState   			mode;       		/**< Current mode (idle/dedicated) \sa CiDevEngModeState */
  UINT8               				res1U8[3];  		/**< (padding) */
  CiDevUmtsServingCellInfo_v0001 		info;  			/**< Engineering mode 3G (UMTS) serving cell information \sa CiDevUmtsServingCellInfo_struct */
} CiDevPrimUmtsEngmodeScellInfoInd_v0001,CiDevPrimUmtsEngmodeScellInfoInd_v0002;
/** \brief  Engineering mode 3G (UMTS) intra-frequency/inter-frequency FDD/TDD cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsFddTddNeighborInfo_v0002_struct
{
    /* Measurements */
    INT16  rscp;        	    /**< CPICH/PCCPCH received signal code power */
    INT16  utraRssi;           	/**< UTRA carrier RSSI */
    INT16  cpichEcN0;        	/**< CPICH Ec/N0, only valid for FDD */
    INT16  sQual;              	/**< Cell selection quality (Squal), only valid for FDD  */
    INT16  sRxLev;            	/**< Cell selection Rx level (Srxlev) */

    /* PLMN/Cell Parameters */
    UINT16   mcc;              	/**< Mobile country code */
    UINT16   mnc;              	/**< Mobile network code */
    UINT16   lac;                	/**< Location area code */
    UINT16   ci;                  	/**< Cell Identity */
    UINT16   arfcn;            	/**< Absolute radio frequency channel number */
    UINT16   psc_cellParameterId; /**< Primary scrambling code for FDD or Cell parameter id for TDD */

} CiDevUmtsFddTddNeighborInfo_v0001,CiDevUmtsFddTddNeighborInfo_v0002;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTERFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002_struct
{
    UINT8                     			numInterFreq; 											/**< Number of Inter-Frequency FDD Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsFddTddNeighborInfo_v0001 	 interFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];		/**< Inter-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */
} CiDevPrimUmtsEngmodeInterFreqInfoInd_v0001,CiDevPrimUmtsEngmodeInterFreqInfoInd_v0002;
/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTRAFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002_struct
{
    UINT8                     			numIntraFreq; 											/**< Number of Intra-Frequency FDD Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsFddTddNeighborInfo_v0001  	intraFreq[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ];		/**< Intra-Frequency Info. \sa CiDevUmtsFddTddNeighborInfo_struct */
} CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0001,CiDevPrimUmtsEngmodeIntraFreqInfoInd_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevUmtsGsmNeighborInfo_v0002_struct
{
    /* Measurements */
    INT16  gsmRssi;         	/**< GSM carrier RSSI */
    INT16  rxLev;             	/**< Cell selection Rx level */
    INT16  C1;                  /**< Path loss criterion parameter #1 */
    INT16  C2;                  /**< Path loss criterion parameter #2 */

    /* PLMN/Cell Parameters */
    UINT16  mcc;               	/**< Mobile country code */
    UINT16  mnc;               	/**< Mobile network code */
    UINT16  lac;                /**< Location area code */
    UINT16  ci;                 /**< Cell identity */
    UINT16  arfcn;             	/**< Absolute radio frequency channel number */
    UINT8   bsic;		   	    /**< Base transceiver station identity code; range 0h-3Fh (6 bits) */
    UINT8   res1U8;

}CiDevUmtsGsmNeighborInfo_v0001, CiDevUmtsGsmNeighborInfo_v0002;

/** <paramref name="CI_DEV_PRIM_UMTS_ENGMODE_INTERRAT_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimUmtsEngmodeInterRatInfoInd_v0002_struct
{
    UINT8                     			numInterRAT;  											/**< Number of Inter-RAT GSM Cells */
    UINT8                     			res1U8[3];    												/**< (padding) */
    CiDevUmtsGsmNeighborInfo_v0001 	 interRAT[ CI_DEV_MAX_UMTS_NEIGHBORING_CELLS ]; 		/**< Inter-Rat Info. \sa CiDevUmtsGsmNeighborInfo_struct */

}CiDevPrimUmtsEngmodeInterRatInfoInd_v0001, CiDevPrimUmtsEngmodeInterRatInfoInd_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellParams_v0002_struct
{
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                  mcc;
    UINT8                   lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                  mnc;        /**< 2-3 digits of MNC */
    UINT16                  tac;
    UINT16                  phyCellId;
    UINT32                  dlEuArfcn;
    UINT32                  ulEuArfcn;
    UINT16                  band;
    UINT8                   dlBandwidth;/*0 - 1.4M, 1 - 3M, 2 - 5M, 3 - 10M, 4 - 15M, 5 - 20M */
    UINT32                  cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
/*Added by taow for LTE EM L2 info, begin*/
	UINT8           		subFrameAssignType;
	UINT8           		specialSubframePatterns;
	UINT8           		transMode;
/*Added by taow for LTE EM L2 info, end*/

	
}CiDevLteEngScellParams_v0001,CiDevLteEngScellParams_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellMeas_v0002_struct
{
    UINT8                   rsrp;
    UINT8                   rsrq;
    INT8                    sinr;	
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT8                   mainRsrp; /**< Rsrp of main antenna. Value range: 0~97, invalid(0xFF) */
    UINT8                   diversityRsrp; /**< Rsrp of diversity antenna. Value range: 0~97, invalid(0xFF) */
    UINT8                   mainRsrq; /**< Rsrq of main antenna. Value range: 0~34, invalid(0xFF) */
    UINT8                   diversityRsrq; /**< Rsrq of diversity antenna. Value range: 0~34, invalid(0xFF) */
    UINT8                   rssi; /**< Value range: 0~128, invalid(0xFF). (rssi-128) for dbm format */
    UINT16                  cqi; /**< Value range: 0~15, invalid(0xFFFF). */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/	
/*Added by taow for LTE EM L2 info, begin*/	
	UINT8           		pathLoss;
	UINT32          		tb0DlTpt;
	UINT32          		tb1DlTpt;
	UINT32           		tb0DlPeakTpt;
    UINT32           		tb1DlPeakTpt;
    UINT32           		tb0UlPeakTpt;
    UINT32           		tb1UlPeakTpt;
	//EmacdlStatisticDataTag
	UINT32					dlThroughPut;     //dl throughtput unit bps, sum(dl tb size in bits)/dl statistic time duration
	UINT32      			dlPeakThroughPut; //Kbps
	UINT8       			averDlPRB;
	UINT8       			averCQITb0;
	UINT8       			averCQITb1;    
	UINT8       			rankIndex;
	// EmaculStatisticDataTag
	UINT32      			grantTotal;        //total received grant size in unit of BYTE	
	UINT32      			ulThroughPut; //Kbps
	UINT32      			ulPeakThroughPut; //Kbps
	INT16      				currPuschTxPower;
	UINT8       			averUlPRB;
  //add by taow 20150415 begin  
    UINT8       			reserved0;
    UINT16      			dlBler;
    UINT16      			ulBler;
    UINT32      			reserved1;        
	UINT32      			reserved2; 
	UINT32      			reserved3; 
	UINT32      			reserved4;
  //add by taow 20150415 end  
/*Added by taow for LTE EM L2 info, end*/

}CiDevLteEngScellMeas_v0001,CiDevLteEngScellMeas_v0002;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngScellInfo_v0002_struct
{
    CiDevLteEngScellParams_v0001       params;
    CiDevLteEngScellMeas_v0001         meas;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
    //CiDevLteEngineerBarredStatus            barredStatus;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    CiDevLteUeOperationStatus               ueOpStatus;     /**< UE operation status \sa CiDevLteUeOperationStatus */
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/
}CiDevLteEngScellInfo_v0001,CiDevLteEngScellInfo_v0002;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_SVCCELL_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeSvcCellInfoInd_v0002_struct
{
  //CiDevLteEngModeState              mode;               /**< Current mode (deactivated/idle/connected/reselection) \sa CiDevLteEngModeState */
  CiBoolean                         sCellPresent;       /**< Whether serving cell engmode info is present */
  UINT8               	            res1U8[3];          /**< (padding) */
  CiDevLteEngScellInfo_v0001 	            info;  	            /**< Engineering mode LTE serving cell information \sa CiDevLteEngScellInfo */
} CiDevPrimLteEngmodeScellInfoInd_v0001,CiDevPrimLteEngmodeScellInfoInd_v0002;
/**
 * Engineering mode information about
 * an Inter-Frequency LTE cell.
 */
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngInterFreqNcellInfo_v0001_struct
{
    UINT16                         phyCellId;
    UINT32                         euArfcn;
    UINT8                          rsrp;
    UINT8                          rsrq;
    //CiBoolean                      ncellSib1Valid;
    //CiDevLteEngNcellSib1           ncellSib1;
    //CiBoolean                      accessRestrictionsPresent;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                         mcc;
    UINT8                          lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                         mnc;        /**< 2-3 digits of MNC */
    UINT16                         tac;
    UINT32                         cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

}
CiDevLteEngInterFreqNcellInfo_v0001,CiDevLteEngInterFreqNcellInfo_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngIntraFreqNcellInfo_v0002_struct
{
    UINT16                        phyCellId;
    UINT32                        euArfcn;
    UINT8                         rsrp;
    UINT8                         rsrq;
    //CiBoolean                     ncellSib1Valid;
    //CiDevLteEngNcellSib1          ncellSib1;
    //CiBoolean                     accessRestrictionsPresent;
    //CiDevLteEngineerCellAccessRestrictions  accessRestrictions;
/*Added by Lilei for LTE Engineering Mode CQ56421, begin*/
    UINT16                        mcc;
    UINT8                         lenOfMnc;   /**< Length of MNC, value range (2,3) */
    UINT16                        mnc;        /**< 2-3 digits of MNC */
    UINT16                        tac;
    UINT32                        cellId;
/*Added by Lilei for LTE Engineering Mode CQ56421, end*/

}CiDevLteEngIntraFreqNcellInfo_v0001,CiDevLteEngIntraFreqNcellInfo_v0002;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTRAFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeIntraFreqInfoInd_v0002_struct
{
    UINT8                     	    numIntraFreq; 								/**< Number of Intra-Frequency Cells */
    UINT8                     	    res1U8[3];    								/**< (padding) */
    CiDevLteEngIntraFreqNcellInfo_v0001   intraFreq[ CI_DEV_LTE_MAX_CELL_INTRA ];		/**< Intra-Frequency Info. \sa CiDevLteEngIntraFreqNcellInfo */
} CiDevPrimLteEngmodeIntraFreqInfoInd_v0001,CiDevPrimLteEngmodeIntraFreqInfoInd_v0002;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTERFREQ_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeInterFreqInfoInd_v0002_struct
{
    UINT8                     	    numInterFreq;                               /**< Number of Inter-Frequency Cells */
    UINT8                     	    res1U8[3];    	                            /**< (padding) */
    CiDevLteEngInterFreqNcellInfo_v0001   interFreq[ CI_DEV_LTE_MAX_CELL_INTER ];	    /**< Inter-Frequency Info. \sa CiDevLteEngInterFreqNcellInfo */
} CiDevPrimLteEngmodeInterFreqInfoInd_v0001,CiDevPrimLteEngmodeInterFreqInfoInd_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraCellParams_v0002_Struct
{
    UINT16              mcc;              			/**< Mobile country code */
    UINT16              mnc;              			/**< Mobile network code */
    UINT16              lac;              			/**< Location area code */
    UINT32              ci;               			/**< Cell identity; as per 3G TS 25.331, 10.3.2.2 (28 bits) */
    UINT16              uArfcn;
    UINT16              psc_cellParameterId;        /**< Primary scrambling code for FDD or Cell parameter id for TDD */
    //UINT16              phyCellId;

}CiDevLteEngUtraCellParams_v0001,CiDevLteEngUtraCellParams_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraCellMeas_v0002_struct
{
    INT16               rscp;        	            /**< CPICH/PCCPCH received signal code power; in UMTS FDD/TDD messages RSCP is
                                                                                                transmitted as an integer value in the range of -120 dBm to -25 dBm.
                                                                                                The value is coded into integers from -5 to 99 according to 3GPP's 25.133.  */
    //INT16                pccpch_RSCP; //for TDD
    INT16               cpichEcN0;//For FDD
    //INT16                cpichRscp;//For FDD
}
CiDevLteEngUtraCellMeas_v0001,CiDevLteEngUtraCellMeas_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngUtraNcellInfo_v0002_struct
{
    CiDevLteEngUtraCellParams_v0001   params;
    CiDevLteEngUtraCellMeas_v0001     meas;
}CiDevLteEngUtraNcellInfo_v0001,CiDevLteEngUtraNcellInfo_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellParams_v0002_struct
{
    UINT16              mcc;               	        /**< Mobile country code */
    UINT16              mnc;               	        /**< Mobile network code */
    UINT16              lac;                        /**< Location area code */
    UINT32              ci;                         /**< Cell identity */
    UINT16              arfcn;                      /**< Absolute radio frequency channel number */
    //UINT8              gsmBandIndicator;
    //CiBoolean          bsicPresent; //ncc and bcc is valid only when bsicPresent is TURE.
    //CiDevLteEngBsic    bsic;
    UINT8               bsic;                       /**< Base transceiver station identity code; range 0h-3Fh (6 bits); 0xFF means not present */
}
CiDevLteEngGsmCellParams_v0001,CiDevLteEngGsmCellParams_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellMeas_v0002_struct
{
    INT16       rssi;         /**< GSM carrier RSSI */
}CiDevLteEngGsmCellMeas_v0001,CiDevLteEngGsmCellMeas_v0002;

//ICAT EXPORTED STRUCT
typedef struct CiDevLteEngGsmCellInfo_v0002_struct
{
    CiDevLteEngGsmCellParams_v0001   params;
    CiDevLteEngGsmCellMeas_v0001     meas;
}CiDevLteEngGsmCellInfo_v0001,CiDevLteEngGsmCellInfo_v0002;

/** <paramref name="CI_DEV_PRIM_LTE_ENGMODE_INTERRAT_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimLteEngmodeInterRatInfoInd_v0002_struct
{
    UINT8                     	    numInterRATUtra;                            /**< Number of Inter-RAT UMTS Cells */
    UINT8                     	    numInterRATGsm;                             /**< Number of Inter-RAT GSM Cells */
    UINT8                     	    res1U8[2];                                  /**< (padding) */
    CiDevLteEngUtraNcellInfo_v0001        interRATUtra[ CI_DEV_LTE_MAX_CELL_UTRA ];   /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */
    CiDevLteEngGsmCellInfo_v0001          interRATGsm[ CI_DEV_LTE_MAX_CELL_GSM ];     /**< Inter-Rat UMTS Info. \sa CiDevLteEngUtraNcellInfo */
} CiDevPrimLteEngmodeInterRatInfoInd_v0001,CiDevPrimLteEngmodeInterRatInfoInd_v0002;
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetMedataCommReserveCnf_v0001_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */
}CiDevPrimSetMedataCommReserveCnf_v0001,CiDevPrimSetMedataCommReserveCnf_v0002;

/** <paramref name="CI_DEV_PRIM_GET_MEDATA_RESERVER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetMedataCommReserveCnf_v0001_struct{
    CiDevRc                 rc;         /**< Result code. \sa CiDevRc. */	
    UINT8                   ConfigValue;   /*value to set */
}CiDevPrimGetMedataCommReserveCnf_v0001,CiDevPrimGetMedataCommReserveCnf_v0002;

/***************************End of CI Interface Definitions of Old CI Versions***********************************************/


#ifdef __cplusplus
	}
#endif //__cplusplus

#endif /* _CI_DEV_H_ */


/*                      end of ci_dev.h
--------------------------------------------------------------------------- */

