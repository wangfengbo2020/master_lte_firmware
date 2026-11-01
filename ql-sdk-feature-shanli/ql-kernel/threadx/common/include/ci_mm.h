/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_mm.h
Description : Data types file for the MM Service Group

Notes       :

INTEL CONFIDENTIAL
Copyright 2006 Intel Corporation All Rights Reserved.
The source code contained or described herein and all documents related to the source code ("Material") are owned
by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
transmitted, distributed, or disclosed in any way without Intels prior express written permission.

No license under any patent, copyright, trade secret or other intellectual property right is granted to or
conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
Intel in writing.

Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice embedded
in Materials by Intel or Intels suppliers or licensors in any way.

=========================================================================== */

#if !defined(_CI_MM_H_)
#define _CI_MM_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_api_types.h"

/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_MM_VER_MAJOR 3
//#define CI_MM_VER_MINOR 1

//#define CI_MM_VER_MAJOR 4
//#define CI_MM_VER_MINOR 0
#define CI_MM_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version


#define CI_MM_MAX_CLI_IE_SIZE          12
#define CI_MM_MAX_LCS_CLIENT_IDENTITY_IE_SIZE         255

#define CI_MM_MAX_FRAT_LIST_SIZE	20

/* ----------------------------------------------------------------------------- */

/* CI_MM Primitive ID definitions */

/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_MM_PRIM
{
    CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_REQ = 1,		/**< \brief Requests the number of subscriber number entries in the MSISDN list \details */
    CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_CNF,		/**< \brief Confirms the request to return the number of subscriber number entries in the MSISDN list \details Requires the SIM to be inserted and ready, plus prior PIN1 validation. */
    CI_MM_PRIM_GET_SUBSCRIBER_INFO_REQ,					/**< \brief Requests subscriber information for a specified entry in the MSISDN list  \details This information is stored on the SIM, so for this request to succeed, the SIM must be inserted and ready.
 *   Access to the MSISDN list requires prior PIN1 (CHV1) validation.
 *   Use the CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_REQ to determine the number of MSISDN list entries. */
    CI_MM_PRIM_GET_SUBSCRIBER_INFO_CNF,					/**< \brief Confirms the request to return subscriber information for a specified entry in the MSISDN list \details */
    CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_REQ,	/**< \brief Requests the supported settings for the unsolicited network registration reporting option \details */
    CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_CNF,	/**< \brief Confirms the request to return the supported settings for the unsolicited network registration reporting option \details There should be no reason for an error result. */
    CI_MM_PRIM_GET_REGRESULT_OPTION_REQ,				/**< \brief Requests the current reporting option for Unsolicited Network Registration Result Indications \details See CI_MM_PRIM_SET_REGRESULT_OPTION for default information. */
    CI_MM_PRIM_GET_REGRESULT_OPTION_CNF,				/**< \brief Confirms the request to return the current reporting option for Unsolicited Network Registration Result Indications \details There should be no reason for an error result. */
    CI_MM_PRIM_SET_REGRESULT_OPTION_REQ,				/**< \brief Request to set the reporting option for Unsolicited Network Registration Result Indications \details Unsolicited Registration Result Indications (CI_MM_PRIM_REG_RESULT_IND) are sent (if enabled) only if the reported information
  *  has changed since the last indication.
  *  CIMM_REGRESULT_STATUS is the default reporting option. */
    CI_MM_PRIM_SET_REGRESULT_OPTION_CNF = 10,				/**< \brief Confirms a request to set the reporting option for Unsolicited Network Registration Result Indications \details */
    CI_MM_PRIM_REGRESULT_IND,								/**< \brief Indicates the Unsolicited Network Registration Result  \details Receipt of this indication (and the information it contains) can be configured by the
  *  CI_MM_PRIM_SET_REGRESULT_OPTION_REQ request.
  *  If this indication is enabled, the current registration status (if available) is reported.
  *  As a configuration option, current cell information (if available) can also be included.
  *  This information can also be requested at any time, using the CI_CC_PRIM_GET_REGRESULT_INFO_REQ request.
  *  No explicit response is required. */
    CI_MM_PRIM_GET_REGRESULT_INFO_REQ,					/**< \brief Requests the most recent registration result information \details See CI_MM_PRIM_SET_REGRESULT_OPTION for default information. */
    CI_MM_PRIM_GET_REGRESULT_INFO_CNF,					/**< \brief Confirms the request to return the most recent registration result information \details Use the CI_MM_PRIM_GET_REGRESULT_OPTION_REQ request to get the current registration result reporting option.
 *   This option setting may affect the availability of registration result information.
 *   The current registration status and location information (if available) are included. */
    CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_REQ,			/**< \brief Requests a list of supported format indicators for the network/operator ID information
														 * \details These format indicators are used in the CiMmNetOpIdInfo structure, to indicate how SAC should format the network or operator
 *   identification information.  */
    CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_CNF,			/**< \brief Confirms the request and returns a list of supported format indicators for the network/operator ID information
														 * \details There should be no reason for an error result. */
    CI_MM_PRIM_GET_ID_FORMAT_REQ,							/**< \brief  Requests the currently selected network operator ID format indicator  \details The network operator ID format indicator selects which of the supported formats SAC will use to represent the network/operator ID. */
    CI_MM_PRIM_GET_ID_FORMAT_CNF,							/**< \brief  Confirms the request to return the currently selected network operator ID format indicator  \details There should be no reason for an error result. */
    CI_MM_PRIM_SET_ID_FORMAT_REQ,							/**< \brief  Requests to set the network/operator ID format indicator \details The network operator ID format indicator selects which of the supported formats SAC will use to represent the network/operator ID
  *  when reporting network operator information. The default format indicator is set for a numeric network ID. */
    CI_MM_PRIM_SET_ID_FORMAT_CNF,							/**< \brief  Confirms the request to set the network/operator ID format indicator \details */
    CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_REQ = 20,		/**< \brief  Requests the number of operators present in the network \details */
    CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_CNF,		/**< \brief  Confirms the request to get the number of operators present in the network \details */
    CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_REQ,			/**< \brief  Requests information about a specified operator present in the network  \details Use CI_CC_PRIM_GET_NUM_NETWORK_OPERATORS_REQ to determine the number of operators present in the network,
  *  if there are any. This number determines the range of values for the Index parameter.
  *  Index values start at 1, which indicates the first operator in the network (usually the home network operator). */
    CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_CNF,			/**< \brief  Confirms the request to get information about a specified operator present in the network  \details There may be no operators currently present in the network. In that case, the network operator status information is not
  *  included.
  *  Status for network operators present should be indexed in the following order of precedence (with the highest precedence listed first):
  *  Home network operator (if present)
  *  Operators for networks that are referenced in the SIM
  *  Other network operators that are present
  *  The network and operator ID information is presented in all supported formats. If information for any of the formats is unavailable, SAC indicates this in the CiMmNetOpStatusInfo structure as follows:
  *  Unavailable operator ID has its Length field set to zero.
  *  Unavailable network ID has its fields set to CIMM_COUNTRYCODE_NONE and CIMM_NETWORKCODE_NONE. */
    CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ,		/**< \brief Requests the number of entries in the preferred network operators list  \details The preferred network operators list is stored on the SIM in the EFPLMNSel file.
  *  The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned, but the file must accommodate at least
  *  8 PLMN entries. See [1] for more information. */
    CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_CNF,		/**< \brief Confirms the request to get the number of entries in the preferred network operators list  \details If the SIM is not present and ready, SAC sets the NumPref parameter to zero. */
    CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_REQ,		/**< \brief  Requests information for a specified entry in the preferred network operators list  \details Use  CI_CC_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ to determine the number of entries in the preferred network
  *  operators list. This number determines the range of values for the Index parameter.
  *  The preferred operator list is stored in the EFPLMNSel file on the SIM, and requires the Card Holder Verification password CHV1
  *  (if enabled) to be established before access to this file is allowed.
  *  The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned, but the file must accommodate at least
  *  8 PLMN entries. See [1] for more information. */
    CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_CNF,		/**< \brief Confirms the request to get information for a specified entry in the preferred network operators list
													 * \details The network/operator ID information is presented in the default format, or in the format set by the most recent
  *  CI_CC_PRIM_SET_ID_FORMAT_REQ request. */
    CI_MM_PRIM_ADD_PREFERRED_OPERATOR_REQ,				/**< \brief Requests a new entry to be added to the preferred network operators list  \details Adds a new entry to the end of the Preferred Operators List.
  *  The Preferred Operators List is stored in the EFPLMNSel file on the SIM, and requires a Card Holder Verification password CHV1
  *  (if enabled) to be established before access to this file is allowed. */
    CI_MM_PRIM_ADD_PREFERRED_OPERATOR_CNF,				/**< \brief Confirms a request to add a new entry to the preferred network operators list  \details The network/operator ID information must be presented in the default format, or in the format set by the most recent CI_CC_PRIM_SET_ID_FORMAT_REQ request.
  *  If the request fails, the list is unchanged. The maximum number of entries in the EFPLMNSel file is specified when the SIM is
  *  provisioned, but the file must accommodate at least 8 PLMN entries. See [1] for more information.
  *  The number of entries in the list is returned regardless of the success/failure of the request. */
    CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_REQ = 30,			/**< \brief Requests an entry to be deleted from the preferred network operators list  \details Use CI_CC_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ to determine the number of entries in the preferred network
  *  operators list. This number determines the range of values for the Index parameter.
  *  The preferred operator list is stored in the EFPLMNSel file on the SIM, and requires a Card Holder Verification password CHV1
  *  (if enabled) to be verified before access to this file is allowed. */
    CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_CNF,			/**< \brief Confirms a request to delete an entry from the preferred network operators list  \details If the request fails, the list is unchanged.
  *  The maximum number of entries in the EFPLMNSel file is specified when the SIM is provisioned, but the file must accommodate at
  *  least 8 PLMN entries. See "Cellular Interface Application Programming Interface", revision i0.6, for more information.
  *  The number of entries in the list is returned regardless of the success/failure of the request. */
    CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_REQ,			/**< \brief Requests information about the current network operator (if there is one)   \details */
    CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_CNF,			/**< \brief Confirms the request to get information about the current network operator (if there is one)  \details */

    CI_MM_PRIM_AUTO_REGISTER_REQ,							/**< \brief Requests automatic registration  \details Uses PLNM lists stored on the SIM, so an installed SIM is required.
  *  The handset is always in automatic PLMN selection mode, except when a manual registration request is received.
  *  After completing a manual registration operation, SAC resets the registration mode to automatic. Therefore, the application layer
  *  does not need to use this request to reset the current registration mode to automatic.
  *  The PLMN selection mode (registration mode) is not saved to NVRAM; it is always set to automatic mode during SAC initialization. */
    CI_MM_PRIM_AUTO_REGISTER_CNF,							/**< \brief Confirms a request for automatic registration \details */
    CI_MM_PRIM_MANUAL_REGISTER_REQ,						/**< \brief  Requests manual registration \details The registration result itself is relayed by a CI_MM_PRIM_REGRESULT_IND indication. It can also be retrieved on demand, using
  *  the CI_MM_PRIM_GET_REGRESULT_INFO_REQ request.
  * On successful completion of this request, SAC resets the registration mode to CIMM_REGMODE_AUTOMATIC. */
    CI_MM_PRIM_MANUAL_REGISTER_CNF,						/**< \brief Confirms a request for manual registration  \details The registration result is relayed by CI_MM_PRIM_REGRESULT_IND, if this is enabled. The information can also
  *  be retrieved on demand, using CI_MM_PRIM_GET_REGRESULT_INFO_REQ.
  *  On successful completion of this request, SAC resets the current registration mode to automatic. */
    CI_MM_PRIM_DEREGISTER_REQ,							/**< \brief Requests deregistration  \details */
    CI_MM_PRIM_DEREGISTER_CNF,							/**< \brief Confirms a request for deregistration  \details The deregistration result is relayed by CI_MM_PRIM_REGRESULT_IND. It can also be retrieved on demand, using
  *  CI_MM_PRIM_GET_REGRESULT_INFO_REQ. */
    CI_MM_PRIM_GET_SIGQUALITY_IND_CONFIG_REQ = 40,			/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_MM_PRIM_GET_SIGQUALITY_IND_CONFIG_CNF,			/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_REQ,			/**< \brief Requests the current configuration for unsolicited signal quality indications \details Unsolicited signal quality indications can be configured in one of two ways:
  *   -	Report signal quality information periodically. The time interval is specified in 100 ms units.
  *   -	Report signal quality information when the RSS changes by more than a specified threshold. The threshold is specified in dBm.
  *   These two configuration options are mutually exclusive. */
    CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_CNF,			/**< \brief Confirms a request to set the current configuration for unsolicited signal quality indications \details */
    CI_MM_PRIM_SIGQUALITY_INFO_IND,						/**< \brief Indicates the unsolicited signal quality   \details This indication can be configured by CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_REQ.
  *  The RSS value is reported in dBm, and should be in the range -113dBm through -51 dBm.
  *  The bit error rate (BER) is reported as an encoded value between 0 and 7. The upper layers should convert this value to a suitable
  *  BER representation.
  *  No explicit response is required. */

    /*Modified by xwzhou for CQ on 08052013, begin*/  	   
    CI_MM_PRIM_EXTENDED_SIGQUALITY_INFO_IND,    //add by xwzhou
     /*Modified by xwzhou for CQ on 08052013, end*/  	   
// SCR #1401348
    CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_REQ,			/**< \brief Requests that network mode indication be enabled or disabled  \details The network mode indication (if enabled) is sent whenever the current network mode changes.
  *  By default, the network mode indication is disabled. */
    CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_CNF,			/**< \brief Confirms a request to enable or disable network mode indication. \details By default, the network mode indication is disabled. */
    CI_MM_PRIM_NETWORK_MODE_IND,							/**< \brief Indicates the current network mode   \details Each of the CiMmNetworkMode parameters indicates the PDP status for their indicated system:
  *  - gprsActive (1 - gprs is active, 0 - gprs is inactive)
  *  - egprsActive (1 - egprs is active, 0 - egprs is inactive)
  *  - hsdpaActive (1 - hsdpa is active, 0 - hsdpa is inactive)
  *  - hsupaActive (1 - hsupa is active, 0 - hsupa is inactive)
  *  This indication can be enabled or disabled by CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_REQ.
  *  By default, this indication is disabled.
  *  No explicit response is required. */
    CI_MM_PRIM_GET_NITZ_INFO_REQ,					/**< \brief Requests the current network identity and time zone (NITZ) information
													 * \details NITZ information is updated by the protocol stack whenever it changes, for example, when acquiring or re-acquiring network service. */
    CI_MM_PRIM_GET_NITZ_INFO_CNF = 50,					/**< \brief Confirms a request for current network identity and time zone (NITZ) information  \details */
    CI_MM_PRIM_NITZ_INFO_IND,						/**< \brief Indicates the status of the current network identity and time zone (NITZ) information
													 * \details NITZ information is reported by the protocol stack whenever it changes, for example, when acquiring or re-acquiring network service.
													 * NITZ indications are enabled by default. */

    CI_MM_PRIM_CIPHERING_STATUS_IND,						/**< \brief Indicates a ciphering status change   \details
 * The protocol stack sends a cipher indication signal to the application layer
 * specifying the CS and PS ciphering status. SAC captures this signal and sends a
 * 'CiMmPrimCipheringStatusInd' notification.
 * The authentication and ciphering procedure is always initiated and controlled by the network.
 * The following events trigger a cipher notification:
 *		- A request by the network to authenticate and/or set the ciphering mode
 *		- GPRS authenticate confirmation from the SIM
 *		- Processing the authentication result
 *		- Failure to release a CS connection
 *		- Invalidating the GPRS parameters that are stored on the SIM and
 *		  marking the SIM as invalid for GPRS services
 *		- Receiving a SYNC signal indicating ciphering mode setting or some channel assignment or modification
 *
 * An additional parameter is needed to indicate if display of
 * the ciphering indicator is required. This parameter is provided in the
 * OFM bit (first bit) of the 'additional information' entry (bytes 2 and 3) of the EF_AD (administrative
 * data) SIM/USIM file.
    */
    CI_MM_PRIM_AIR_INTERFACE_REJECT_CAUSE_IND,			/**< \brief  Indicates an air interface reject cause code  \details
 * The protocol stack sends an air interface reject cause code indication due to errors that
 * can occur during MM/GMM procedures such as LU/RA update reject, authentication reject, etc.
 * These reject codes are intended to enable vendors to give specific visual/audible feedback to the user.
 */
	/* Michal Bukai - Selection of preferred PLMN list +CPLS - START */
    CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_REQ,	/**< \brief Requests to select the preferred PLMN list
												 * \details The selected preffered PLMN list will be used when operation on the list is required */
    CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_CNF,  /**<  \brief Confirms the request to select a preferred PLMN list */
    CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_REQ,     /**< \brief Requests to read what is the selected preferred PLMN list */
    CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_CNF,     /**< \brief Confirms the response and returns the type of the selected preferred PLMN list */
	/* Michal Bukai - Selection of preferred PLMN list +CPLS - END */
	CI_MM_PRIM_BANDIND_IND,	/**< \brief  Indicates the current band
								 * \details Indications are sent when the band changes and band indications are enabled. */
	CI_MM_PRIM_SET_BANDIND_REQ,  /**< \brief  Requests to enable/disable band indications  \details  */
	CI_MM_PRIM_SET_BANDIND_CNF = 60,  /**< \brief  Confirms the request to enable/disable band indications  \details  */
	CI_MM_PRIM_GET_BANDIND_REQ,  /**< \brief  Requests the status of band indications (enabled/ disabled) and an indication of the current band  \details  */
	CI_MM_PRIM_GET_BANDIND_CNF,  /**< \brief  Confirms the request and returns the status of band indications (enabled/ disabled) and an indication of the current band \details  */
	CI_MM_PRIM_SERVICE_RESTRICTIONS_IND, /**< \brief Indicates if display of PLMN selection menus is allowed
										  * \details PLMN selection menu contol information is stored in SIM or USIM in bit 'PLMN Mode' of file EF-CSP (see CPHS Version 4.2).
										  * On power up the application should assume that display of PLMN selection menus is not allowed.
										  * This indication is sent on power if display of PLMN selection menus is allowed and whenever there is a change of this bit using OTA reprogramming.
										   */

    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_MM_PRIM_LAST_COMMON_PRIM' */
	//Michal Bukai - HOMEZONE support
	CI_MM_PRIM_HOMEZONE_IND, /**< \brief Indicates a change in HomeZone indication status \details  */
	/*Michal Bukai - Cell Lock - Start*/
    CI_MM_PRIM_CELL_LOCK_REQ,		/**< \brief Requests to activate or to deactivate cell lock \details  */
    CI_MM_PRIM_CELL_LOCK_CNF,		/**< \brief Confirms the request and activates or deactivates cell lock \details  */    
    CI_MM_PRIM_CELL_LOCK_IND,		/**< \brief Indicates the status of cell lock \details  */
	/*Michal Bukai - Cell Lock - End*/

    CI_MM_PRIM_SET_FAST_DORMANT_CAP_REQ,  /**< \brief  Requests to enable/disable fast dormancy capability, it will be saved in NVM  \details  */
    CI_MM_PRIM_SET_FAST_DORMANT_CAP_CNF,  /**< \brief  Confirms the request to enable/disable fast dormancy capability  \details  */
    CI_MM_PRIM_GET_FAST_DORMANT_CAP_REQ = 70,  /**< \brief  Requests the capability of fast dormancy (enabled/ disabled)  \details  */
    CI_MM_PRIM_GET_FAST_DORMANT_CAP_CNF,  /**< \brief  Confirms the request and returns the capability of fast dormancy (enabled/ disabled) \details  */

    CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_REQ,  /**< \brief  Requests to enable/disable NAS integrity check, it will be saved in NVM  \details  */
    CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_CNF,  /**< \brief  Confirms the request to enable/disable NAS integrity check  \details  */
    CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_REQ,  /**< \brief  Requests the configuration of NAS integrity check (enabled/ disabled) kept in NVM \details  */
    CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_CNF,  /**< \brief  Confirms the request and returns configuration of NAS integrity check (enabled/ disabled) \details  */

	CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_REQ, 	  /**< \brief  Requests the number of operators present in the network \details */
	CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_CNF, 	  /**< \brief  Confirms the request to get the number of operators present in the network \details */
	CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_REQ, 		  /**< \brief  Requests information about a specified operator present in the network  \details Use CI_CC_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_REQ to determine the number of operators present in the network,
	*  if there are any. This number determines the range of values for the Index parameter.
	*  Index values start at 1, which indicates the first operator in the network (usually the home network operator). */
	CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_CNF, 		  /**< \brief  Confirms the request to get information about a specified operator present in the network  \details There may be no operators currently present in the network. In that case, the network operator status information is not*/
    CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_REQ = 80,			/**< \brief Requests information about the current network operator (if there is one)	\details */
	CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_CNF,			/**< \brief Confirms the request to get information about the current network operator (if there is one)  \details */
	CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_REQ,			/**< \brief Requests information about the current network operator (if there is one)	\details */
	CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_CNF,			/**< \brief Confirms the request to get information about the current network operator (if there is one)  \details */

    CI_MM_PRIM_CS_SERVICE_NOTIFICATION_IND,   /**CSFB indication from APEX_MM*/
    CI_MM_PRIM_CS_SERVICE_NOTIFICATION_RSP,   /**CSFB respond from AP*/
	
	CI_MM_PRIM_DSAC_STATUS_IND, 		/**< \brief Indicates domain service access status \details  */  
	CI_MM_PRIM_SET_SRVCC_SUPPORT_REQ,		/**< \brief Set SRVCC Support of the UE. The network is updated when changing this parameter. \details  */  
	CI_MM_PRIM_SET_SRVCC_SUPPORT_CNF,		/**< \brief Confirms the setting of the SRVCC support. \details  */
	CI_MM_PRIM_GET_SRVCC_SUPPORT_REQ,		/**< \brief Get the SRVCC Support status of the UE. \details  */
	CI_MM_PRIM_GET_SRVCC_SUPPORT_CNF = 90,		/**< \brief Confirms the request to get the SRVCC support status. \details  */
	CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_REQ,	/**< \brief Set command enables or disables reporting of SRVCC handover information and
										* of IMS Voice Over PS sessions (IMSVOPS) indicator information \details  */
	CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_CNF,	/**< \brief Confirms the setting of the IMS reporting or SRVCC. \details  */
	CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_REQ,	/**< \brief Get the reporting of SRVCC handover information and of IMS Voice Over PS
										* sessions (IMSVOPS) indicator information \details  */
	CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_CNF,	/**< \brief Confirms the CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_REQ \details  */
	CI_MM_PRIM_IMSVOPS_IND,					/**< \brief IMS Voice Over PS sessions (IMSVOPS) supported indication from the network \details  */
	CI_MM_PRIM_SRVCC_HANDOVER_IND,			/**< \brief Reporting of SRVCC handover information indication \details  */
	CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_REQ,	/**< \brief Set reporting of new emergency numbers received from the network \details  */
	CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_CNF,	/**< \brief Confirms the request to set reporting of new emergency numbers received from the network. \details  */
	CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_REQ,		/**< \brief Get the reporting status of new emergency numbers received from the network \details  */
	CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_CNF = 100,		/**< \brief Confirm the request to get the reporting status of new emergency numbers received from the network. \details  */
	CI_MM_PRIM_EMERGENCY_NUMBER_REPORT_IND,			/**< \brief Unsolicited reporting of emergency numbers received from the network 
												* \details  sent if reporting was set with CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_REQ*/
	CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_REQ,	/**< \brief Set command enables reporting of changes in the emergency bearer services support indicators \details  */
	CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_CNF,	/**< \brief Confirmation to the setting of reporting of changes in the emergency bearer services support indicators \details  */
	CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_REQ,	/**< \brief Get the current setting of reporting of changes in the emergency bearer services support indicators \details  */
	CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_CNF,	/**< \brief Response to get the current setting of reporting of changes in the emergency bearer services support indicators 
												* \details  The indications emb_Iu_supp and emb_S1_supp are only set to supported when explicitly signalled from the network*/
	CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_IU_IND,	/**< \brief Unsolicited reporting of changes in the emergency bearer services support
												* indicators according to the network feature support information element, see
												* 3GPP TS 24.008 subclause 10.5.5.23 \details  */
	CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_S1_IND,	/**< \brief Unsolicited reporting of changes in the emergency bearer services support
												* indicators according to the EPS network feature support information element, see
												* 3GPP TS 24.301 subclause 9.9.3.12A \details  */
	CI_MM_PRIM_GET_SSAC_STATUS_REQ, /**< \brief Get current status of SSAC (Service Specific Access Control) related information \details  */  
	CI_MM_PRIM_GET_SSAC_STATUS_CNF, /**< \brief Confirmation for the request to get SSAC status \details  */ 
	CI_MM_PRIM_GET_SIGQUALITY_INFO_REQ = 110, /**< \brief Request signal quality information */
	CI_MM_PRIM_GET_SIGQUALITY_INFO_CNF, /**< \brief Reports the signal quality */

	CI_MM_PRIM_WB_CELL_LOCK_REQ,		/**< \brief Requests to activate or to deactivate WB-GSM band cell lock \details, used by G+W  */
	CI_MM_PRIM_WB_CELL_LOCK_CNF,		/**< \brief Confirms the request and activates or deactivates WB-GSM band cell lock \details  */  
	/*Michal Bukai - cancel PLMN search (Samsung)- Start*/
	CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_REQ,   /**< \brief Requests to cancel manual PLMN search
    										    * \details The primitive CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_REQ is used to trigger abort manual PLMN search.
    										    */
	CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_CNF,   /**< \brief Confirms the request and stops the manual PLMN search
                                               * \details If the search will be cencelled successfully CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_CNF with failure result will be returned.
    										    */
	/*Michal Bukai - cancel PLMN search (Samsung)- End*/  
    
	CI_MM_PRIM_TRIGGER_USER_RESELECTION_REQ, /**< \brief Request to trigger user PLMN selection */
	CI_MM_PRIM_TRIGGER_USER_RESELECTION_CNF, /**< \brief confirm that trigger user PLMN selection was received */
    
	CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_REQ, /**< \brief Sets the PLMN selection mode at power up
												* \details according to 3GPP TS 23.122, section 4.4.3.1 switch on reovery from lack of coverage. */
	CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_CNF, /**< \brief confirm the request to set the PLMN selection mode at power up
												* \details according to 3GPP TS 23.122, section 4.4.3.1 switch on reovery from lack of coverage.*/
	CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_REQ = 120, /**< \brief Gets the PLMN selection mode at power up
												* \details according to 3GPP TS 23.122, section 4.4.3.1 switch on reovery from lack of coverage.*/
	CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_CNF, /**< \brief Confirm the request to get the PLMN selection mode at power up
												* \details according to 3GPP TS 23.122, section 4.4.3.1 switch on reovery from lack of coverage.*/
    CI_MM_PRIM_NETWORK_MODE_REQ,
    CI_MM_PRIM_NETWORK_MODE_CNF,
	
	CI_MM_PRIM_FIRST_SEARCHED_NETWORK_OPERATOR_IND, /**First searched network operator indication from APEX_MM*/
    CI_MM_PRIM_FRAT_LIST_ACTION_REQ,
    CI_MM_PRIM_FRAT_LIST_ACTION_CNF,
    CI_MM_PRIM_GET_FRAT_LIST_REQ,
    CI_MM_PRIM_GET_FRAT_LIST_CNF,

	CI_MM_PRIM_CSG_AUTO_SEARCH_REQ, /**< \brief Request for Automatic camping on the strongest CSG cell. */
	CI_MM_PRIM_CSG_AUTO_SEARCH_CNF = 130, /**< \brief Confirm the request for Automatic camping on the strongest CSG cell. */
	CI_MM_PRIM_CSG_LIST_SEARCH_REQ, /**< \brief Request for searching all CSG cells. */
	CI_MM_PRIM_CSG_LIST_SEARCH_CNF, /**< \brief List of all the CSG which were found. */
	CI_MM_PRIM_CSG_SELECT_REQ,		/**< \brief Selects CSG ID, as a result the Comm. will try to camp on it */
	CI_MM_PRIM_CSG_SELECT_CNF,		/**< \brief Result of selecting CSG ID request. */
	CI_MM_PRIM_CSG_SEARCH_STOP_REQ, /**< \brief Request to stop CSG Search. */
	CI_MM_PRIM_CSG_SEARCH_STOP_CNF, /**< \brief Confirm that the stop request was received. */
	CI_MM_PRIM_REGRESULT_EXTENDED_IND, /** < \brief Indicates the Extended (csg info) Unsolicited Network Registration Result  \details Receipt of this indication (and the information it contains) can be configured by the
	*  CI_MM_PRIM_SET_REGRESULT_OPTION_REQ request.
	*  If this indication is enabled, the current registration status (if available) is reported.
	*  As a configuration option, current cell information (if available) can also be included.
	*  This information can also be requested at any time, using the CI_CC_PRIM_GET_REGRESULT_INFO_REQ request.*/
    CI_MM_PRIM_SET_SECURITY_CAPABILITY_REQ,
    CI_MM_PRIM_SET_SECURITY_CAPABILITY_CNF,
    CI_MM_PRIM_GET_SECURITY_CAPABILITY_REQ = 140,
    CI_MM_PRIM_GET_SECURITY_CAPABILITY_CNF,
    
    CI_MM_PRIM_NETWORK_CELL_MAT_INFO_IND,

    CI_MM_PRIM_EMERGENCY_CALL_STATUS_REQ,
    CI_MM_PRIM_EMERGENCY_CALL_STATUS_CNF,

    CI_MM_PRIM_NEW_ATTACH_IND, /** < \brief Indicates that MM is starting a new ATTACH process */ /* Added by liorgo, for CQ00086808, 08/03/2015 */
	CI_MM_PRIM_JAMMING_DETECTION_REQ,				/**< \brief  Request to configure jamming detection.*/
	CI_MM_PRIM_JAMMING_DETECTION_CNF,				/**< \brief  confirtm the reuqest to configure jamming detection.*/
	CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_REQ,	/**< \brief  request to read jamming detection configuration.*/
	CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_CNF,	/**< \brief  The configured valued of the jamming detection.*/
	CI_MM_PRIM_JAMMING_DETECTION_IND = 150,				/**< \brief  unsolicited reporting of change in jamming status.*/

    CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_REQ,/**< \brief  Change the GPRS and EGPRS multislot classes.*/
    CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_CNF,/**< \brief  Confirm the request to change GPRS and EGPRS multislot class.*/
    CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_REQ,/**< \brief  Request to read the GPRS and EGPRS multislot classes.*/
    CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_CNF,/**< \brief  The configured valued of GPRS and EGPRS multislot classes.*/
    CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_REQ, /**< \brief The command displays the name of the network of the requested type. In case the requested informationis not available, the command displays the network name which is most similar to the requested type.*/
    CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_CNF,/**< \brief  A confirmation for the request command, will return the operator name according to the type that was requested.*/
	CI_MM_PRIM_ECALLREG_REQ,/**< \brief Set the forced registration status*/
	CI_MM_PRIM_ECALLREG_CNF,/**< \brief Confirms the request to set the forced registration status*/	
	CI_MM_PRIM_RPM_INFO_REQ,
	CI_MM_PRIM_RPM_INFO_CNF =160,
	CI_MM_PRIM_RPM_INFO_IND,
	//add by taow 20171124 CQ00108549 begin
	CI_MM_PRIM_SET_NETWORK_SELECTION_REQ,
	CI_MM_PRIM_SET_NETWORK_SELECTION_CNF, 
	CI_MM_PRIM_GET_NETWORK_SELECTION_REQ,
	CI_MM_PRIM_GET_NETWORK_SELECTION_CNF, 
	CI_MM_PRIM_GET_LTE_CA_INFO_REQ, 
	CI_MM_PRIM_GET_LTE_CA_INFO_CNF,
	CI_MM_PRIM_GET_OPERATOR_INFO_REQ,
	CI_MM_PRIM_GET_OPERATOR_INFO_CNF,
	CI_MM_PRIM_OPERATOR_STATUS_IND =170,
	//add by taow 20171124 CQ00108549 end
   
	/*20190605 add for IMS BEGIN */
    CI_MM_PRIM_GET_ASRCURRENT_OPERATOR_INFO_REQ,			/**< \brief Requests information about the current network operator (if there is one)   \details */
    CI_MM_PRIM_GET_ASRCURRENT_OPERATOR_INFO_CNF,			/**< \brief Confirms the request to get information about the current network operator (if there is one)  \details */
	/*20190605 add for IMS BEGIN*/

	CI_MM_PRIM_GET_CELL_LOCK_INFO_REQ,
	CI_MM_PRIM_GET_CELL_LOCK_INFO_CNF,
	CI_MM_PRIM_NETWORK_SEARCH_IND, /*add CQ00114574 by taow 20190419*/
	CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_REQ,
    CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_CNF,
    /*add by taow CQ00125209 20201020 begin*/
    CI_MM_PRIM_SET_OOS_PHASE_PERIOD_REQ,
    CI_MM_PRIM_SET_OOS_PHASE_PERIOD_CNF,
    CI_MM_PRIM_GET_OOS_PHASE_PERIOD_REQ =180,
    CI_MM_PRIM_GET_OOS_PHASE_PERIOD_CNF,
    /*add by taow CQ00125209 20201020 end*/
    /*add by CQ00130201 taow 20210513 begin*/
    CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_REQ,
    CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_CNF,
    CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_REQ,
    CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_CNF,
    CI_MM_PRIM_GET_BANDS_SCAN_REQ,
    CI_MM_PRIM_GET_BANDS_SCAN_CNF,
    CI_MM_PRIM_GET_BANDS_SCAN_IND,
    CI_MM_PRIM_ABORT_BANDS_SCAN_REQ,
    CI_MM_PRIM_ABORT_BANDS_SCAN_CNF =190,

    /*add by CQ00130201 taow 20210513 end*/

	CI_MM_PRIM_NW_ECALL_OVER_IMS_SUPPORT_IND,	            /**< \brief Unsolicited reporting of changes in eCall over IMS support indicators according to SIB1 --36.331 rel14 and above \details  */
/*20220225 with  CQ00135513 for IMSECALL  for IMSECALL begin*/
	CI_MM_PRIM_IMSECALL_REG_REQ,	
	CI_MM_PRIM_IMSECALL_REG_CNF,
	/*20220225 with  CQ00135513 for IMSECALL  for IMSECALL end  */

    /*Lilei, CQ00134598, 20220418, begin*/
    CI_MM_PRIM_SET_RPM_REQ,
    CI_MM_PRIM_SET_RPM_CNF,
    /*Lilei, CQ00134598, 20220418, end*/
 /*add for new feature to support VSIM with CQ00141543  20230208 BEGIN*/	   
	CI_MM_PRIM_SET_SELECT_VSIM_REQ,
	CI_MM_PRIM_SET_SELECT_VSIM_CNF,
	
	CI_MM_PRIM_GET_SELECT_VSIM_REQ,
	CI_MM_PRIM_GET_SELECT_VSIM_CNF,
 /*add for new feature to support VSIM with CQ00141543  20230208 END*/	   

    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_MM_PRIM_LAST_COMMON_PRIM' */
    /* END OF COMMON PRIMITIVES LIST */
	CI_MM_PRIM_LAST_COMMON_PRIM

    /* The customer specific extension primitives are added starting from
     * CI_MM_PRIM_firstCustPrim = CI_MM_PRIM_LAST_COMMON_PRIM as the first identifier.
     * The actual primitive names and IDs are defined in the associated
     * 'ci_mm_cust_xxx.h' file.
     */

  /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiMmPrim;

/* specify the number of default common MM primitives */
#define CI_MM_NUM_COMMON_PRIM ( CI_MM_PRIM_LAST_COMMON_PRIM - 1 )
/**@}*/

/** \brief Mobility Management Return Codes  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_MM
{
    CIRC_MM_SUCCESS = 0,          			/**< Request completed successfully */
    CIRC_MM_FAIL,                 			/**< General failure (catch-all)    */
    CIRC_MM_INCOMPLETE_INFO,      			/**< Incomplete information for request */
    CIRC_MM_INVALID_ADDRESS,      			/**< Invalid address (phone number) */
    CIRC_MM_NO_SERVICE,           			/**< No network service */
    CIRC_MM_NOT_REGISTERED,       			/**< Not currently registered */
    CIRC_MM_REJECTED,             			/**< Request rejected by network */
    CIRC_MM_TIMEOUT,              			/**< Request timed out */
    CIRC_MM_UNAVAILABLE,          			/**< Information not available */
    CIRC_MM_NO_MORE_ENTRIES,      		/**< No more entries in list */
    CIRC_MM_NO_MORE_ROOM,         		/**< No more room in list */
	CIRC_MM_PLMN_LIST_SIM_NOK,    	/**< PLMN list SIM is not OK */
    CIRC_MM_PLMN_LIST_NOT_FOUND,  	/**< PLMN list is not found */
    CIRC_MM_PLMN_LIST_NOT_ALLOWED,	/**< PLMN list is not allowed */
	CIRC_MM_PLMN_LIST_MANUAL_NOT_ALLOWED, /* manual selection of */
    CIRC_MM_PLMN_LIST_MANUAL_NOT_ALLOWED_IN_DEDICATED_MODE, /* PLMN list is not allowed in dedicated mode*/
    CIRC_MM_INVALID_PARAMETER,			/**< Generic error - the requested service primitive has invalid parameters */
	CIRC_MM_INVALID_REQ,				/**< Generic error - the requested service primitive can not be handled at current state */
	CIRC_MM_SIM_NOT_READY,				/**< Generic error - the requested service primitive fails because SIM is not ready */

    CIRC_MM_CANCELLED,              /*procedure was cancelled*/ 
    
    CIRC_MM_NETWORK_NOT_ALLOWED_EMERGENCY_CALLS_ONLY,
	CIRC_MM_NO_SERVICE_BUT_SEARCHING,

    /* This one must always be last in the list! */
    CIRC_MM_NUM_RESCODES          		/**< Number of result codes defined */
} _CiMmResultCode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Mobility Management Return Codes
 *  \sa CIRC_MM
 * \remarks Common Data Section */
typedef UINT16 CiMmResultCode;
/**@}*/

/* Tal Porat/Michal Bukai - Network Selection - start */

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief MM state
 * \remarks Common Data Section */
typedef UINT32 CiMmCause;
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief GMM state
 * \remarks Common Data Section */
typedef UINT32 CiGmmCause;
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief EMM state
 * \remarks Common Data Section */
typedef UINT32 CiEmmCause;
/**@}*/

/** \brief Service Information: Information Transfer Capability (ITC) Indicators  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_PLMN_SELECTION_POWER_UP_MODE {
    CI_MM_PLMN_SELECTION_POWER_UP_MODE_AUTO = 0,		/**< At power up, use auto plmn selection mode*/
    CI_MM_PLMN_SELECTION_POWER_UP_MODE_MANUAL,			/**< At power up, use auto manual selection mode */
    CI_MM_PLMN_SELECTION_POWER_UP_MODE_LAST_USED, 		/**< At power up, use last used plmn mode before power down*/

    /* This one must always be last in the list! */
    CI_MM_NUM_PLMN_SELECTION_POWER_UP_MODE
} _CiMmPowerUpPlmnSelectionMode;

/** \addtogroup  SpecificSGRelated
 * @{ */

/** \brief cimm cause type  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_ERROR_CAUSE_TYPE {
	CI_MM_ERROR_CAUSE_TYPE_MM,						/**< MM Reject code is received during an MM procedure */
	CI_MM_ERROR_CAUSE_TYPE_GMM_NON_COMBINED,		/**< GMM Reject code is received during a non-combined GMM procedure for GPRS services */
	CI_MM_ERROR_CAUSE_TYPE_GMM_COMBINED_NON_GPRS,	/**< GMM reject code is received during a combined GMM procedure for non-GPRS services */
	CI_MM_ERROR_CAUSE_TYPE_GMM_COMBINED_GPRS,		/**< GMM reject code is received during a combined GMM procedure for GPRS and non-GPRS services */
	CI_MM_ERROR_CAUSE_TYPE_EMM_NON_COMBINED,		/**< EMM reject code is received for a non combined EMM procedure for EPS services */
	CI_MM_ERROR_CAUSE_TYPE_EMM_COMBINED_NON_EPS,	/**< EMM reject code is received during a combined procedure for non-EPS services */
	CI_MM_ERROR_CAUSE_TYPE_EMM_COMBINED_EPS,		/**< EMM reject code is received during a combined procedure for EPS and non-EPS services */

	/* This one must always be last in the list! */
	CIMM_NUM_ERROR_CAUSE_TYPES
} _CiMmErrorCauseType;

/**   \brief GMM state
 * \remarks Common Data Section */
typedef UINT8 CiMmErrorCauseType;

/**   \brief PLMN selection mode atpower up
 *  \sa CIMM_PLMN_SELECTION_POWER_UP_MODE */
typedef UINT8 CiMmPowerUpPlmnSelectionMode;
/**@}*/

/* Tal Porat/Michal Bukai - Network Selection - end */

/** \brief Subscriber Number Information: Associated Network Services  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_SERVICE {
    CIMM_SERVICE_ASYNC_MODEM = 0, 	/**< Asynchronous modem */
    CIMM_SERVICE_SYNC_MODEM,      		/**< Synchronous modem  */
    CIMM_SERVICE_PAD_ASYNC,       		/**< PAD access (asynchronous)  */
    CIMM_SERVICE_PACKET_SYNC,     		/**< Packet access (synchronous)  */
    CIMM_SERVICE_VOICE,           			/**< Voice  */
    CIMM_SERVICE_FAX,             			/**< Fax    */

    /* This one must always be last in the list! */
    CIMM_NUM_SERVICES             			/**< Number of network services defined */
} _CiMmService;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Subscriber Number Information: Associated network Services
 *  \sa CIMM_SERVICE
 * \remarks Common Data Section */
typedef UINT8 CiMmService;
/**@}*/

/** \brief Service Information: Information Transfer Capability (ITC) Indicators  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_ITC{
    CIMM_ITC_3_1_KHZ= 0,          	/**< 3.1 kHz */
    CIMM_ITC_UDI,                 		/**< Unrestricted digital information (UDI) */

    /* This one must always be last in the list! */
    CIMM_NUM_ITC                  		/**< Number of ITC indicators defined */
} _CiMmITC;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Service Information: Information Transfer Capability (ITC) Indicators
 *  \sa CIMM_ITC
 * \remarks Common Data Section */
typedef UINT8 CiMmITC;
/**@}*/

/** \brief Service Information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmServiceInfo_struct {
    CiBoolean     		Present;    	/**< Service information present? \sa CCI API Ref Manual */
    CiMmService   		SvcType;    	/**< Associated service type  \sa CiMmService */
    CiBsTypeSpeed 	Speed;      	/**< Connection speed \sa CCI API Ref Manual  */
    CiMmITC       		Itc;        		/**< Information transfer capability  \sa CiMmITC. */
} CiMmServiceInfo;

/** \brief Subscriber Service Information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSubscriberInfo_struct {
    CiAddressInfo   		Number;       	/**< Subscriber number (MSISDN) \sa CCI API Ref Manual */
    CiOptNameInfo   	AlphaTag;     /**< Associated alpha tag (optional)  \sa CCI API Ref Manual */
    CiMmServiceInfo 	SvcInfo;      	/**< Service information (optional) \sa CiMmServiceInfo_struct */
} CiMmSubscriberInfo;

/** \brief Registration Result Indication: Reporting Options  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_REGRESULT_OPTION{
    CIMM_REGRESULT_DISABLE = 0,   	/**< Disable reporting */
    CIMM_REGRESULT_STATUS,        	/**< Report registration status only */
    CIMM_REGRESULT_CELLINFO,      	/**< Report status and current cell information */
    CIMM_REGRESULT_MORE_DETAIL,     /**< Report more detail info: [,<cause_type>,<reject_cause>]]> */
    /* This one must always be last in the list! */
    CIMM_NUM_REGRESULT_OPTIONS    /**< Number of options defined */
} _CiMmRegResultOption;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Registration Result Indication: Reporting Options
 *  \sa CIMM_REGRESULT_OPTION
 * \remarks Common Data Section */
typedef UINT8 CiMmRegResultOption;

/* Default Reporting Option */
#define CIMM_REGRESULT_DEFAULT  ((UINT8) CIMM_REGRESULT_STATUS)
/**@}*/

/** \brief Registration result information: registration status indicators  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_REGSTATUS {
    CIMM_REGSTATUS_NOT_SEARCHING = 0,
    /**< Not registered, not searching operators */
    CIMM_REGSTATUS_HOME,			/**< Registered with home network */
    CIMM_REGSTATUS_SEARCHING,	/**< Not registered, searching operators */
    CIMM_REGSTATUS_DENIED,			/**< Registration denied */
    CIMM_REGSTATUS_UNKNOWN,		/**< Registration status unknown */
    CIMM_REGSTATUS_ROAMING,		/**< Registered, roaming */
    CIMM_REGSTATUS_SMS_ONLY_HOME,				/**< registered for "SMS only", home network (applicable only when <AcT> indicates E-UTRAN) */
    CIMM_REGSTATUS_SMS_ONLY_ROAMING,			/**< registered for "SMS only", roaming (applicable only when <AcT> indicates E-UTRAN) */
    CIMM_REGSTATUS_EMERGENCY_ONLY_NOT_USED,		/**< attached for emergency bearer services only (see NOTE 2) (not applicable) */
    CIMM_REGSTATUS_CSFB_NOT_PREFERRED_HOME,		/**<registered for "CSFB not preferred", home network (applicable only when <AcT> indicates E-UTRAN) */
    CIMM_REGSTATUS_CSFB_NOT_PREFERRED_ROAMING,	/**<registered for "CSFB not preferred", roaming (applicable only when <AcT> indicates E-UTRAN) */
    CIMM_REGSTATUS_EMERGENCY_ONLY,
    /**< Only emergency services are available*/
    CIMM_REGSTATUS_DENIED_IN_ROAMING,           /**< registeration denied in roaming*/
    CIMM_REGSTATUS_SYNC_DONE_IN_LTE_ROAMING,    /**< sync done in LTE roaming network*/
    CIMM_REGSTATUS_ECALL_INACTIVE,

    /* This one must always be last in the list! */
    CIMM_NUM_REGSTATUS			/**< Number of status values defined */
} _CiMmRegStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Registration result information: Registration status indicators
 *  \sa CIMM_REGSTATUS
 * \remarks Common Data Section */
typedef UINT8 CiMmRegStatus;
/**@}*/

/** \brief Registration mode values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_REGMODE {
    CIMM_REGMODE_AUTOMATIC = 0,   		/**< Automatic registration request */
    CIMM_REGMODE_MANUAL,          		/**< Manual registration request */
    CIMM_REGMODE_DEREGISTER,     		 /**< Deregistration request */
    CIMM_REGMODE_MANUAL_AUTO,     	/**< Manual request, fallback to automatic */

    /* This one must always be last in the list! */
    CIMM_NUM_REGMODES             			/**< Number of mode indicators defined */
} _CiMmRegMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Registration Mode \sa CIMM_REGMODE
 *  \sa CIMM_REGSTATUS
 * \remarks Common Data Section */
typedef UINT8 CiMmRegMode;
/**@}*/



/* Default Registration Mode */
#define CIMM_REGMODE_DEFAULT  ((UINT8) CIMM_REGMODE_AUTOMATIC)

/** \brief  Access technology modes (added in release 4; See TC 27.007) */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_ACT_TECH_MODE
{
  CI_MM_ACT_GSM = 0,            /**< GSM */
  CI_MM_ACT_GSM_COMPACT,		/**< Not supported */
  CI_MM_ACT_UTRAN,              /**< UTRAN */

  CI_MM_ACT_GSM_EGPRS,          /**< GSM w/EGPRS */
  CI_MM_ACT_UTRAN_HSDPA,        /**< UTRAN w/HSDPA */
  CI_MM_ACT_UTRAN_HSUPA,        /**< UTRAN w/HSUPA */
  CI_MM_ACT_UTRAN_HSPA,         /**< UTRAN w/HSDPA and HSUPA */
  CI_MM_ACT_EUTRAN,             /**< E-UTRAN */ 
 
  CI_MM_ACT_UTRAN_HSPA_PLUS,    /**< UTRAN w/HSPA+ */
  
  CI_MM_ACT_EUTRAN_PLUS,/*E-UTRAN CA*/
  /* Added by taow 20190708 CQ00115423, begin */
  CI_MM_ACT_UTRAN_DC_HSPA,/*DC-HSPA*/
  /* Added by taow 20190708 CQ00115423, end */
  CI_MM_NUM_ACT
} _CiMmAccTechMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Access technology modes (added in release 4; see TC 27.007)
 * \sa CIMM_ACT_TECH_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiMmAccTechMode;
/**@}*/

/** \brief Registration result information: optional current cell information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmCellInfo_struct {
    CiBoolean 	Present;    		/**< Current cell information present? \sa CCI API Ref Manual */
    UINT16  	LocArea;    		/**< Location area code */
    UINT32  CellId;     /**< Cell identifier. GSM case: 16 least significant bits, WCDMA case: CellId - 16 least significant bits, RNCID - 12 most significant bits */

    CiMmAccTechMode AcT; /**< Network access technology (GSM, UTRAN, LTE etc.)  \sa CiMmAccTechMode */
} CiMmCellInfo;

/** \brief Registration Result Information Structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmRegResultInfo_struct {
    CiMmRegStatus Status;     /**< Registration status  \sa CiMmRegStatus  */
    CiMmCellInfo  CellInfo;   /**< Current cell information (optional)  \sa CiMmRegStatus */
} CiMmRegResultInfo;

/** \brief  Network operator identification information: network/operator ID format indicators */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETOP_ID_FORMAT {
    CIMM_NETOP_ID_FORMAT_ALPHA_LONG = 0,  	/**< Operator ID: long alphanumeric */
    CIMM_NETOP_ID_FORMAT_ALPHA_SHORT,     	/**< Operator ID: short alphanumeric */
    CIMM_NETOP_ID_FORMAT_NETWORK,         		/**< Network ID (numeric) */

    /* This one must always be last in the list! */
    CIMM_NUM_NETOP_ID_FORMATS             /**< Number of format indicators defined */
} _CiMmNetOpIdFormat;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network operator identification information: network/operator ID format indicators
 * \sa CIMM_NETOP_ID_FORMAT */
/** \remarks Common Data Section */
typedef UINT8 CiMmNetOpIdFormat;

/* Default network/operator ID Format indicator */
#define CIMM_NETOP_ID_FORMAT_DEFAULT  ((UINT8) CIMM_NETOP_ID_FORMAT_NETWORK)

/* Operator Identification Information: Maximum Alphanumeric ID lengths */
#define CIMM_MAX_OPER_ID_LONG   32  /* Long alphanumeric  */ //Michal Bukai change from 16 to 32 - same as RIL define
#define CIMM_MAX_OPER_ID_SHORT  16   /* Short alphanumeric */ //Michal Bukai change from 8 to 16 - same as RIL define
/**@}*/

/*Added by xwzhou on 04092014 for CQ58416, begin*/
/** \brief  Network operator mnc digit indicators - for the network operator list */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETOP_DIGIT_MNC {
    CIMM_NETOP_TWO_DIGIT_MNC = 2,   	/*2 digit */
    CIMM_NETOP_THREE_DIGIT_MNC,     	/*3 digit */
    /* This one must always be last in the list! */
    CIMM_NUM_NETOP_DIGIT_MNC      	
} _CiMmNetOpDigitMnc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network operator mnc digit indicators */
/** \remarks Common Data Section */
typedef UINT8 CiMmNetOpDigitMnc; /**< Reported as 2 digit or 3 digit  */
/**@}*/
/*Added by xwzhou on 04092014 for CQ58416, end*/


/** \brief  Network operator identification information: network identification structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmNetworkId_struct {
    UINT16  CountryCode;    /**< 3-digit country code */
    UINT16  NetworkCode;    /**< 3-digit network code */
    /*Added by xwzhou on 04092014 for CQ58416, begin*/
    CiMmNetOpDigitMnc MncDigit;         /**< MncDigit     \sa CiMmNetOpDigitMnc   */
    /*Added by xwzhou on 04092014 for CQ58416, end*/
} CiMmNetworkId;

/* Network ID field values used if the information is unavailable*/
#define CIMM_COUNTRYCODE_NONE ((UINT16) 0)
#define CIMM_NETWORKCODE_NONE ((UINT8) 0)

/* Network operator Identification Information: Operator Identification structure */
#define CIMM_MAX_OPER_ID_LEN  CIMM_MAX_OPER_ID_LONG /* Maximum length (chars) of Operator Id */

#define CIMM_MAX_LSA_IDENTITY  3    /* Maximum LSA identity */

/** \brief  Operator  ID structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmOperatorId_struct {
    UINT8 	Length;                     					/**< Operator ID length (characters) */
    char  	Id[ CIMM_MAX_OPER_ID_LEN ]; 		/**< Operator ID */
} CiMmOperatorId;
/** \brief  Netwrok or operator ID*/
/** \remarks Common Data Section */
//ICAT EXPORTED UNION
typedef  union CiMmNetOpId_tag{
        CiMmNetworkId  	NetworkId;     		/**< Network ID  \sa CiMmNetworkId_struct */
        CiMmOperatorId 	OperatorId;    		/**< Operator ID \sa CiMmOperatorId_struct   */
} CiMmNetOpIdUnion;
/** \brief  Network or operator identification */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiNetOpIdInfo_struct {
    CiBoolean         		Present;        		/**< Indicates if network or operator ID is present \sa CCI API Ref Manual */
    CiMmNetOpIdFormat 		Format;        			/**< ID format: network or operator  \sa CiMmNetOpIdFormat   */
    CiMmNetOpIdUnion 		CiMmNetOpId;			/**< ID \sa CiMmNetOpId_tag*/

	CiMmAccTechMode	   AccTchMode;	   /**< Access radio technology; default is GSM \sa CiMmAccTechMode */
	UINT8 Domain; 	/**< CS or PS domain, 0:CS only;1:PS only;2:Combined CS/PS */

} CiMmNetOpIdInfo;

/** \brief  Network operator status indicators - for the network operator list */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETOPSTATUS {
    CIMM_NETOP_UNKNOWN = 0,   	/**< Operator status unavailable */
    CIMM_NETOP_AVAILABLE,     	/**< Operator is available */
    CIMM_NETOP_CURRENT,       	/**< Current operator */
    CIMM_NETOP_FORBIDDEN,     	/**< Operator is forbidden  */

    /* This one must always be last in the list! */
    CIMM_NUM_NETOPSTATUS      	/**< Number of status indicators defined  */
} _CiMmNetOpStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network operator status indicators - for the network operator list
 * \sa CIMM_NETOPSTATUS */
/** \remarks Common Data Section */
typedef UINT8 CiMmNetOpStatus;

/* Default network operator Status */
#define CIMM_NETOPSTATUS_DEFAULT  ((UINT8) CIMM_NETOP_UNKNOWN)
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Received signal strength indication (RSSI), measured in dBm */
/** \remarks Common Data Section */
typedef INT16 CiMmRssi;        /**< RSSI value */    /* value down to : -128dBm */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Encoded bit error rate (BER) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmEncodedBER; /**< Reported as an index between 0-7, inclusive  */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief reference signal received quality (RSRQ) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmRsrq; /**< Reported as an index between 0-34, inclusive  */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief reference signal received power (RSRP) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmRsrp; /**< Reported as an index between 0-97, inclusive  */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief received signal code power (RSCP) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmRscp; /**< Reported as an index between 0-96, inclusive  */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief ratio of the received energy per PN chip to the total received power spectral density (ECNO) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmEcno; /**< Reported as an index between 0-49, inclusive  */
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief received signal strength level (rxlev) indication */
/** \remarks Common Data Section */
typedef UINT8 CiMmRxlev; /**< Reported as an index between 0-63, inclusive  */
/**@}*/



/** \brief  Network operator status information structure for the network operator list.
 * If the supported network/operator ID formats are changed, this structure must change accordingly.  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiNetOpStatusInfo_struct {
    CiMmNetOpStatus    	Status;       		/**< Network operator status  \sa CiMmNetOpStatus */
    CiMmRssi           		Rssi;         		/**< RSSI value in dBm  \sa CiMmRssi  */
    CiMmOperatorId     		LongAlphaId;  	/**< Long alphanumeric operator ID  \sa CiMmOperatorId_struct   */
    CiMmOperatorId     		ShortAlphaId; 	/**< Short alphanumeric operator ID  \sa CiMmOperatorId */
    CiMmNetworkId      		NetworkId;    	/**< Network ID information  \sa CiMmNetworkId */
    CiMmAccTechMode    	AccTchMode;   	/**< Network access technology (GSM, UTRAN, etc.)  \sa CiMmAccTechMode */
} CiMmNetOpStatusInfo;

/** \brief  Signal quality indications: configuration options */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_SIGQUAL_OPTIONS {
    CIMM_SIGQUAL_OPTION_INTERVAL = 0,   	/**< Time interval - used for periodic reports */
    CIMM_SIGQUAL_OPTION_THRESHOLD,      	/**< RSSI threshold */
    CIMM_SIGQUAL_OPTION_DISABLE,      		/**< Disable indications */

    /* This one must always be last in the list! */
    CIMM_NUM_SIGQUAL_OPTIONS            		/**< Number of status indicators defined  */
} _CiMmSigQualOpts;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Signal Quality Indications: Configuration Options
 * \sa CIMM_SIGQUAL_OPTIONS */
/** \remarks Common Data Section */
typedef UINT8 CiMmSigQualOpts;
/** @} */

/* Signal Quality Indications: Configuration Defaults */
#define CIMM_SIGQUAL_OPTION_DEFAULT     ( (UINT8) CIMM_SIGQUAL_OPTION_THRESHOLD )
#define CIMM_SIGQUAL_THRESHOLD_DEFAULT  ( (UINT8) 10 )
#define CIMM_SIGQUAL_INTERVAL_DEFAULT   ( (UINT8) 20 )  /* 2 seconds */

/** \brief  Signal quality reports configuration: configuration values depend on report type interval or threshold */
/** \remarks Common Data Section */
//ICAT EXPORTED UNION
typedef    union CfgUnion_Tag{
      UINT8 		Interval;         	/**< Time Interval in 100ms units  */
      UINT8 		Threshold;        	/**< RSSI threshold in dBm  */
    } CfgUnion;
/** \brief  Signal quality indications configuration */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSigQualityConfig_struct {
    CiMmSigQualOpts Option;   		/**< Signal quality report type interval or theshold \sa CiMmSigQualOpts */
    CfgUnion Cfg;                   /**< Configuration \sa CfgUnion_Tag*/
} CiMmSigQualityConfig;

/** \brief Network mode indication values */
/*-----------------5/5/2009 1:44PM------------------
 *  SCR #1401348:
 * --------------------------------------------------*/
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETWORK_MODE
{
  CI_MM_NETWORK_MODE_GSM = 0,    /**< GSM */
  CI_MM_NETWORK_MODE_UMTS,       /**< UMTS */

  CI_MM_NETWORK_MODE_LTE,       /**< TD LTE */
  CI_MM_NETWORK_MODE_DEFAULT,
  CI_MM_NUM_NETWORK_MODES
} _CiMmNetworkMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network mode indication */
 /*  SCR #1401348 */
 /** \sa CIMM_NETWORK_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiMmNetworkMode;
/**@}*/


typedef enum CIMM_CELL_LOCK_ACT_MODE
{
    CIMM_CELL_LOCK_ACT_GSM,
	CIMM_CELL_LOCK_ACT_UMTS_TD,
	CIMM_CELL_LOCK_ACT_UMTS_W,
	CIMM_CELL_LOCK_ACT_LTE,
	CIMM_CELL_LOCK_ACT_INVALID
}_CiMmCellLockActMode;

typedef UINT8 CiMmCellLockActMode;

/** \brief  Signal quality indications: information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSigQualityInfo_struct {
    CiMmRssi        Rssi; /**< RSSI value in dBm  \sa CiMmRssi  */
    CiMmEncodedBER  BER;  /**< Encoded bit error rate  \sa CiMmEncodedBER */
    CiMmRsrq        Rsrq; /**Report reference signal received quality*/
    CiMmNetworkMode Mode;  /**< Network mode \sa CiMmNetworkMode */
    CiBoolean       IsLtePsOnly; /**TRUE: lte ps only, set 3G/2G RSSI to default;FALSE: just update lte RSSI*/
} CiMmSigQualityInfo;

/*Modified by xwzhou for CQ on 08052013, begin*/      

/** \brief  Signal quality indications: information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSigExtendedQualityInfo_struct {
    CiMmRxlev Rxlev;
    CiMmEncodedBER Ber;//bit error rate
    CiMmRscp Rscp;
    CiMmEcno Ecno;//RadioInfo->receiveQuality
    CiMmRsrq Rsrq;
    CiMmRsrp Rsrp;
//add by taow 20150730 begin 
    UINT8    LteCqi; 
    INT8    SINR;
//add by taow 20150730 end   
} CiMmSigExtendedQualityInfo;//add by xwuzhou 

/** \brief  Signal quality indications: information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSigNormalQualityInfo_struct {
    UINT8        Rssi; 
    CiMmEncodedBER Ber;
} CiMmSigNormalQualityInfo;//add by xwuzhou 

/*Modified by xwzhou for CQ on 08052013, end*/      


/** \brief  Cell capability network mode enumeration */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETWORK_MODE_REPORT
{
  CI_MM_NETWORK_MODE_REPORT_GSM = 0,				/**< GSM only */
  CI_MM_NETWORK_MODE_REPORT_UMTS,					/**< 3G only */
  CI_MM_NETWORK_MODE_REPORT_UMTS_HSDPA,			/**< 3G and HSDPA capabilities */
  CI_MM_NETWORK_MODE_REPORT_UMTS_HSUPA,			/**< 3G and HSUPA capabilities */
  CI_MM_NETWORK_MODE_REPORT_UMTS_HSDPA_HSUPA,	/**< 3G, HSDPA, and HSDPA capabilities */
  CI_MM_NETWORK_MODE_REPORT_GSM_EGPRS,			/**< GSM, GPRS, and EGPRS capabilities */
  CI_MM_NETWORK_MODE_REPORT_GSM_GPRS,           /**< GSM and GPRS capabilities */

  CI_MM_NETWORK_MODE_REPORT_UMTS_HSPA_PLUS = 8, /**< 3G and HSPA+ capabilities */
  CI_MM_NETWORK_MODE_REPORT_LTE,                /**< TD LTE capabilities */
  CI_MM_NUM_NETWORK_MODE_REPORTS
} _CiMmNetworkModeReport;

//ICAT EXPORTED ENUM
/** \brief  UMTS band values */
/** \remarks Common Data Section */

typedef enum CI_UMTS_BANDS_TYPE
{
	CI_BAND_1,  	/**< UMTS Band1 */
	CI_BAND_2,      /**< UMTS Band2 */
	CI_BAND_3,      /**< UMTS Band3 */
	CI_BAND_4,      /**< UMTS Band4 */
	CI_BAND_5,      /**< UMTS Band5 */
	CI_BAND_6,      /**< UMTS Band6 */
	CI_BAND_7,      /**< UMTS Band7 */
	CI_BAND_8,      /**< UMTS Band8 */
	CI_BAND_9,      /**< UMTS Band9 */
	CI_BAND_10,		/**< UMTS Band10 */
	CI_BAND_11,		/**< UMTS Band11 */
	CI_BAND_12,		/**< UMTS Band12 */
	CI_BAND_13,		/**< UMTS Band13 */
	CI_BAND_14,		/**< UMTS Band14 */
	CI_BAND_15,		/**< UMTS Band15 */
	CI_BAND_16,		/**< UMTS Band16 */
	CI_BAND_17, 	/**< UMTS Band17 */
	CI_BAND_18, 	/**< UMTS Band18 */
	CI_BAND_19, 	/**< UMTS Band19 */
	
	CI_BAND_GSM     /**< Band GSM */
}_CiUmtsBandsType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief UMTS band values
 * \sa CI_UMTS_BANDS_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiUmtsBandsType;
/**@}*/

//ICAT EXPORTED ENUM
/** \brief  LTE band values */
/** \remarks Common Data Section */

typedef enum CI_LTE_BANDS_TYPE
{
    CI_LTE_BAND_1 = 1,  /**< LTE Band1 */
    CI_LTE_BAND_2,  /**< LTE Band2 */
    CI_LTE_BAND_3,  /**< LTE Band3 */
    CI_LTE_BAND_4,  /**< LTE Band4 */
    CI_LTE_BAND_5,  /**< LTE Band5 */
    CI_LTE_BAND_6,  /**< LTE Band6 */
    CI_LTE_BAND_7,  /**< LTE Band7 */
    CI_LTE_BAND_8,  /**< LTE Band8 */
    CI_LTE_BAND_9,  /**< LTE Band9 */
    CI_LTE_BAND_10,  /**< LTE Band10 */
    
    CI_LTE_BAND_11,  /**< LTE Band11 */
    CI_LTE_BAND_12,  /**< LTE Band12 */
    CI_LTE_BAND_13,  /**< LTE Band13 */
    CI_LTE_BAND_14,  /**< LTE Band14 */
    CI_LTE_BAND_15,  /**< LTE Band15 */
    CI_LTE_BAND_16,  /**< LTE Band16 */
    CI_LTE_BAND_17,  /**< LTE Band17 */
    CI_LTE_BAND_18,  /**< LTE Band18 */
    CI_LTE_BAND_19,  /**< LTE Band19 */
    CI_LTE_BAND_20,  /**< LTE Band20 */
    
    CI_LTE_BAND_21,  /**< LTE Band21 */
    CI_LTE_BAND_22,  /**< LTE Band22 */
    CI_LTE_BAND_23,  /**< LTE Band23 */
    CI_LTE_BAND_24,  /**< LTE Band24 */
    CI_LTE_BAND_25,  /**< LTE Band25 */
    CI_LTE_BAND_26,  /**< LTE Band26 */
    CI_LTE_BAND_27,  /**< LTE Band27 */
    CI_LTE_BAND_28,  /**< LTE Band28 */
    CI_LTE_BAND_29,  /**< LTE Band29 */
    CI_LTE_BAND_30,  /**< LTE Band30 */
    
    CI_LTE_BAND_31,  /**< LTE Band31 */
    CI_LTE_BAND_32,  /**< LTE Band32 */
    CI_LTE_BAND_33,  /**< LTE Band33 */
    CI_LTE_BAND_34,  /**< LTE Band34 */
    CI_LTE_BAND_35,  /**< LTE Band35 */
    CI_LTE_BAND_36,  /**< LTE Band36 */
    CI_LTE_BAND_37,  /**< LTE Band37 */
    CI_LTE_BAND_38,  /**< LTE Band38 */
    CI_LTE_BAND_39,  /**< LTE Band39 */
    CI_LTE_BAND_40,  /**< LTE Band40 */
    
    CI_LTE_BAND_41,  /**< LTE Band41 */

	CI_LTE_BAND_64 = 64  /**< LTE Band64 */
    
}_CiLteBandsType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief LTE band values
 * \sa CI_LTE_BANDS_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiLteBandsType;
/**@}*/

//ICAT EXPORTED ENUM
/** \brief  GSM band values */
/** \remarks Common Data Section */

typedef enum CI_GSM_BANDS_TYPE
{
    CI_GSM_BAND        = 0,	/**< PGSM 900 (standard or primary) */
    CI_DCS_BAND        = 1, /**< DCS GSM 1800*/
    CI_PCS_BAND        = 2, /**< PCS GSM 1900*/
    CI_EGSM_BAND       = 3, /**< EGSM 900 (extended)*/
    CI_GSM_450_BAND    = 4, /**< GSM 450*/
    CI_GSM_480_BAND    = 5, /**< GSM 480*/
    CI_GSM_850_BAND    = 6, /**< GSM 850 */

    CI_NUM_BANDS,
#if defined (UPGRADE_3G)
    CI_UMTS_BAND       = 0xFE,   /**< UMTS */
#endif
    CI_INVALID_BAND    = 0xFF    /**< Invalid band */
}_CiGsmBandsType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GSM band values
 * \sa CI_GSM_BANDS_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiGsmBandsType;
/**@}*/

/**  \brief Current band: band values depend on access technology*/
/** \remarks Common Data Section */
//ICAT EXPORTED UNION
typedef union CiMmCurrentBandTag
{
	CiGsmBandsType    gsmBand;  		/**< access technology is GSM \sa CiGsmBandsType */
	CiGsmBandsType    gsmCompactBand;   /**< Not used */
	CiUmtsBandsType	umtsBand;   		/**< access technology is UMTS \sa CiUmtsBandsType */
    CiLteBandsType    lteBand;     /**< access technology is LTE \sa CiLteBandsType */
}CiMmCurrentBand;

//ICAT EXPORTED STRUCT
/** \brief  Current band */
/** \remarks Common Data Section */
typedef struct CiMmCurrentbandInfo_struct
{
	CiMmAccTechMode  accessTechnology;	/**< Access technology \sa CiMmAccTechMode */
	CiMmCurrentBand  currentBand;       /**< Current band \sa CiMmCurrentBandTag */
}CiMmCurrentBandInfo;



//typedef CurrentModeBand CiMmCurrentModeBand;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SCR #1401348: Network Mode indication
 * \sa CIMM_NETWORK_MODE_REPORT */
/** \remarks Common Data Section */
typedef UINT8 CiMmNetworkModeReport;
/**@}*/

/** \brief  NW mode indication support */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmNetworkHsMode_struct
{
	CiBoolean 	gprsActive;     	/**< TRUE - is active; FALSE - is not; \sa CCI API Ref Manual */
	CiBoolean 	egprsActive;		/**< TRUE - is active; FALSE - is not; \sa CCI API Ref Manual */
	CiBoolean 	hsdpaActive;		/**< TRUE - is active; FALSE - is not; \sa CCI API Ref Manual */
	CiBoolean 	hsupaActive;		/**< TRUE - is active; FALSE - is not; \sa CCI API Ref Manual */
    CiBoolean   hspaPlusActive;     /**< TRUE - is active; FALSE - is not; \sa CCI API Ref Manual */
} CiMmNetworkHsMode;

/** \brief  Daylight Savings Time Indicator */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_DSTIND
{
  CI_MM_DST_IND_NO_ADJUSTMENT = 0,
  CI_MM_DST_IND_PLUS_ONE_HOUR,
  CI_MM_DST_IND_PLUS_TWO_HOURS,

  CI_MM_NUM_DST_INDS
} _CiMmDstInd;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Daylight Savings Time Indicator
 * \sa CIMM_DSTIND */
/** \remarks Common Data Section */
typedef UINT8 CiMmDstInd;
/**@}*/

/** \brief  Universal time. See TS 23.040, Section 9.2.3.11 for time zone */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmUniTime_struct
{
  UINT8 	year;           		/**< Year   [ 00..99 ] */
  UINT8 	month;          	/**< Month  [ 1..12 ] */
  UINT8 	day;            		/**< Day    [ 1..31 ] */
  UINT8 	hour;           		/**< Hour   [ 0..59 ] */
  UINT8 	minute;         	/**< Minute [ 0..59 ] */
  UINT8 	second;         	/**< Second [ 0..59 ] */
  INT8  	locTimeZone;    	/**< Local time zone */
} CiMmUniTime;

/** \brief  Universal time. See TS 24.008, Section 10.5.3.5a for time netwporkname */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiNetworkNameCodingSchemeTag
{
    CI_NETWORK_NAME_SMS_CB_CODED   =  0,
    CI_NETWORK_NAME_UCS2_CODED     =  1
}
_CiNetworkNameCodingScheme;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Saving network name coding scheme
 * \sa CiNetworkNameCodingSchemeTag */
/** \remarks Common Data Section */
typedef UINT8 CiNetworkNameCodingScheme;
/**@}*/



/** \brief  LSA localized service area identity */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmLsaIdentity_struct
{
  UINT8 	length; 	/**< length */
  UINT8 	data[CIMM_MAX_LSA_IDENTITY];  /**< data */
} CiMmLsaIdentity;

//Michal Bukai - add boolean parameters which indicate which information the NITZ include

#define CIMM_MAX_NETWORK_NAME_LENGTH    64
//ICAT EXPORTED STRUCT
typedef struct CiMmNetworkName_struct
{
    CiBoolean                 extBit;
    CiBoolean                 addCIBit;/**<addCountryInitials*/
    CiNetworkNameCodingScheme networkNameDCS; /**< SMS_CB_CODED/UCS2_CODED */
    UINT8                     networkNameLength;
    UINT8                     numOfSpareBitsInLastOctet;
    char                      networkName[ CIMM_MAX_NETWORK_NAME_LENGTH ];

} CiMmNetworkName;

/** \brief  NITZ information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmNitzInfo_struct
{
  CiMmOperatorId longAlphaId;           /**< Long alphanumeric operator ID  \sa CiMmOperatorId_struct  */
  CiBoolean	     longAlphaIdPresent;    /**< TRUE - if long alphanumeric ID is present  \sa CCI API Ref Manual */
  CiMmOperatorId shortAlphaId;          /**< Short alphanumeric operator ID  \sa CiMmOperatorId_struct */
  CiBoolean	     shortAlphaIdPresent;   /**< TRUE - if short alphanumeric ID is present  \sa CCI API Ref Manual */
  CiMmNetworkId  networkId;             /**< Network ID information  \sa CiMmNetworkId */
  CiBoolean	     networkIdPresent;      /**< TRUE - if Network ID information is present  \sa CCI API Ref Manual */
  CiMmUniTime    uniTime;               /**< Universal time  \sa CiMmUniTime_struct */
  CiBoolean	     uniTimePresent;        /**< TRUE - if universal time is present  \sa CCI API Ref Manual */
  INT8           locTimeZone;           /**< local time zone */
  CiBoolean	     locTimeZonePresent;    /**< TRUE - if local time zone is present  \sa CCI API Ref Manual */
  CiMmDstInd     dstInd;                /**< Daylight savings indicator  \sa CiMmDstInd */
  CiBoolean      dstIndPresent;	        /**< TRUE - if daylight saving indicator present  \sa CCI API Ref Manual */
  CiMmLsaIdentity lsaIdentity;          /**< LSA - localized service area identity  \sa CiMmLsaIdentity */
  UINT8           domain;               /**< CS or PS domain, 0:CS;1:PS */
  
  CiNetworkNameCodingScheme networkNameCodingScheme; /** SMS_CB_CODED/UCS2_CODED */
  CiBoolean                 addCountryInitials;
  /*added by taow 20220708 CQ00137666 begin*/ 
  CiMmNetworkName        fullNWName;
  CiMmNetworkName        shortNWName;

  UINT32                    resrveData[4];
  /*added by taow 20220708 CQ00137666 end*/
} CiMmNitzInfo;

/** \brief  Enumeration for different way preferred operator could be added */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_ADDPREFOP_TYPES
{
  CI_MM_ADDPREFOP_FIRST_AVAILABLE = 0,
  CI_MM_ADDPREFOP_INSERT_AT_INDEX,

  CI_MM_NUM_ADD_PREFOP_TYPES
} _CiMmAddPrefOpType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Enumeration for different way preferred operator could be added
 * \sa CIMM_ADDPREFOP_TYPES */
/** \remarks Common Data Section */
typedef UINT8 CiMmAddPrefOpType;
/**@}*/

/*Michal Bukai - Selection of preferred PLMN list + CPLS - START */

/** \brief  Preferred PLMN list type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_LIST_INDEX_TYPE{
	CI_MM_LIST_INDEX_USER_CONTROLLED_WACTSUCCESS = 0,	/**< User controlled PLMN selector with Access Technology EFPLMNwAcT. if not found in the SIM/UICC then select PLMN preferred list EFPLMNsel */
	CI_MM_LIST_INDEX_OPERATOR_CONTROLLED_WACT,          /**< Operator controlled PLMN selector with Access Technology  FOPLMNwAcT */
	CI_MM_LIST_INDEX_HPLMN_WACT,                        /**< HPLMN selector with Access Technology EFHPLMNwAcT */

	CI_MM_NUM_LIST_INDEX_TYPES

} _CiMmListIndexType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Prefferred PLMN list type */
 /** \sa CIMM_LIST_INDEX_TYPE */
/** \remarks Common Data Section */
typedef UINT8 CiMmListIndexType;
/**@}*/


/*Michal Bukai - Selection of preferred PLMN list + CPLS - END */

/* -------------------------- CC Primitives ------------------------------- */

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_REQ"> */
typedef CiEmptyPrim CiMmPrimGetNumSubscriberNumbersReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NUM_SUBSCRIBER_NUMBERS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNumSubscriberNumbersCnf_struct{
    CiMmResultCode  	Result;			/**< Result code \sa CiMmResultCode */
    UINT8           		NumMSISDN;	/**< Number of entries in the MSISDN list  */
} CiMmPrimGetNumSubscriberNumbersCnf;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUBSCRIBER_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSubscriberInfoReq_struct{
    UINT8 		Index;		/**< MSISDN list entry number [1..number of MSISDN list entries] */
} CiMmPrimGetSubscriberInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUBSCRIBER_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSubscriberInfoCnf_struct{
    CiMmResultCode       Result;			/**< Result code \sa CiMmResultCode */
    CiMmSubscriberInfo  	info;				/**< Subscriber information \sa CiMmSubscriberInfo_struct */
} CiMmPrimGetSubscriberInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_REQ"> */
typedef CiEmptyPrim CiMmPrimGetSupportedRegResultOptionsReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUPPORTED_REGRESULT_OPTIONS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSupportedRegResultOptionsCnf_struct{
    CiMmResultCode      	Result;										/**< Result code \sa CiMmResultCode */
    UINT8               			NumOptions;									/**< Number of supported options */
    CiMmRegResultOption 	Option[ CIMM_NUM_REGRESULT_OPTIONS ];	/**< Supported options  \sa CiMmRegResultOption*/
} CiMmPrimGetSupportedRegResultOptionsCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_REGRESULT_OPTION_REQ"> */
typedef CiEmptyPrim CiMmPrimGetRegResultOptionReq;
/** <paramref name="CI_MM_PRIM_GET_BANDIND_REQ"> */
typedef CiEmptyPrim CiMmPrimGetBandIndReq;

/** <paramref name="CI_MM_PRIM_GET_BANDIND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetBandIndCnf_struct{
    CiMmResultCode      result;      /**< Result code \sa CiMmResultCode */
	CiBoolean enableBandInd;         /**< Enable status  \sa CCI API Ref Manual */
	CiMmCurrentBandInfo currentBand;  /**< Current band \sa CiMmCurrentbandInfo_struct */

}CiMmPrimGetBandIndCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_REGRESULT_OPTION_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetRegResultOptionCnf_struct{
    CiMmResultCode      		Result;		/**< Result code \sa CiMmResultCode */
    CiMmRegResultOption 		Option;		/**< Reporting option  \sa CiMmRegResultOption */
} CiMmPrimGetRegResultOptionCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_REGRESULT_OPTION_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetRegResultOptionReq_struct{
    CiMmRegResultOption 	Option;		/**< Reporting option  \sa CiMmRegResultOption */
} CiMmPrimSetRegResultOptionReq;

/** <paramref name="CI_MM_PRIM_SET_BANDIND_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetBandIndReq_struct{
	CiBoolean	enableBandInd;        /**< Enable/Disable band indications  \sa CCI API Ref Manual */
}CiMmPrimSetBandIndReq;

/** <paramref name="CI_MM_PRIM_SET_BANDIND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetBandIndCnf_struct{
    CiMmResultCode      result;            /**< Result code \sa CiMmResultCode */
}CiMmPrimSetBandIndCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_REGRESULT_OPTION_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetRegResultOptionCnf_struct{
    CiMmResultCode 	Result;				/**< Result code \sa CiMmResultCode */
} CiMmPrimSetRegResultOptionCnf;


/** \brief cuase type for reject cause  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_CAUSE_TYPE {
    CI_MM_CAUSE_TYPE_MM = 0, 			/**< Indicates that <reject_cause> contains an MM cause value, see 3GPP TS 24.008 [8] Annex G*/
    CI_MM_CAUSE_TYPE_MANUFACTURER,      /**< Indicates that <reject_cause> contains a manufacturer specific cause  */
	CI_MM_CAUSE_NONE,
    CIMM_NUM_CAUSE_TYPE
} _CiMmCauseType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Available values for cuase type
 *  \sa CIMM_CUASE_TYPE
 * \remarks Common Data Section */
typedef UINT8 CiMmCauseType;
/**@}*/

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_REGRESULT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimRegResultInd_struct{
  CiMmRegStatus  		RegStatus;		/**< Registration status  \sa CiMmRegStatus */
  CiMmCellInfo  			info;			/**< Current cell information \sa CiMmCellInfo_struct */
  /*  deleted by xwzhou 09052013  CQ43000,begin */
  //CiMmAccTechMode AccTchMode;		/**< Network access technology \sa CiMmAccTechMode */
  /*  deleted by xwzhou 09052013  CQ43000,end */
		
  CiMmCauseType causeType;			/**< cuase type  \sa CiMmCauseType */
  UINT16 rejectCause;				/**< contains the cause of the failed registration (if MM cause type, values define in 3GPP TS 24.008 [8] Annex G). The value is of type as defined by causeType */
  CiBoolean pscValid;				/**<Indicates if the psc field is valid. The psc should be valid only on UMTS */
  UINT16 psc;						/**< Primary scrambling code */
  /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472,begin */
  //#if defined(CRANE_Z1)
  CiMmNetworkId rplmnInfo; /**reprot rplmn information*/
  //#endif
  /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472,end */
} CiMmPrimRegResultInd;

/** <paramref name="CI_MM_PRIM_BANDIND_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimBandIndInd_struct
{
	CiMmCurrentBandInfo currentBand;  /**< Current band \sa CiMmCurrentbandInfo_struct */
}
CiMmPrimBandIndInd;
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_REGRESULT_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetRegResultInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_REGRESULT_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetRegResultInfoCnf_struct{
    CiMmResultCode  Result;		/**< Result code \sa CiMmResultCode */
    CiMmRegResultOption option;     /** just the n flag in CREG */
    CiMmRegStatus   RegStatus;		/**< Registration status  \sa CiMmRegStatus */
    CiMmCellInfo  	info;				/**< Current cell information \sa CiMmCellInfo_struct */
    /*  deleted by xwzhou 09052013  CQ43000,begin */
	//CiMmAccTechMode AccTchMode;		/**< Network access technology \sa CiMmAccTechMode */
	/*  deleted by xwzhou 09052013  CQ43000,end */
	CiMmCauseType	causeType;		/**< cuase type  \sa CiMmCauseType */
	UINT16			rejectCause;	/**< contains the cause of the failed registration (if MM cause type, values define in 3GPP TS 24.008 [8] Annex G). The value is of type as defined by causeType */
	CiBoolean pscValid;				/**<Indicates if the psc field is valid. The psc should be valid only on UMTS */
	UINT16 psc;						/**< Primary scrambling code */
    /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472,begin */
	//#if defined(CRANE_Z1)
    CiMmNetworkId rplmnInfo; /**reprot rplmn information*/
	//#endif
    /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472 end */
} CiMmPrimGetRegResultInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_REQ"> */
typedef CiEmptyPrim CiMmPrimGetSupportedIdFormatsReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SUPPORTED_ID_FORMATS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSupportedIdFormatsCnf_struct{
    CiMmResultCode    		Result;									       /**< Result code \sa CiMmResultCode */
    UINT8             			NumFormats;								/**< Number of supported formats  */
    CiMmNetOpIdFormat 	Format[ CIMM_NUM_NETOP_ID_FORMATS ];		/**< Supported formats  \sa CiMmNetOpIdFormat */
} CiMmPrimGetSupportedIdFormatsCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_ID_FORMAT_REQ"> */
typedef CiEmptyPrim CiMmPrimGetIdFormatReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_ID_FORMAT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetIdFormatCnf_struct{
    CiMmResultCode      		Result;		/**< Result code \sa CiMmResultCode */
    CiMmNetOpIdFormat   		Format;		/**< Current format  \sa CiMmNetOpIdFormat */
} CiMmPrimGetIdFormatCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_ID_FORMAT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetIdFormatReq_struct{
    CiMmNetOpIdFormat Format;		/**< Current format \sa CiMmNetOpIdFormat  */
} CiMmPrimSetIdFormatReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_ID_FORMAT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetIdFormatCnf_struct{
    CiMmResultCode Result;		/**< Result code \sa CiMmResultCode */
} CiMmPrimSetIdFormatCnf;

/* <INUSE> */
/**	CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_REQ - Requests the number of operators present in the network
*/
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNumNetworkOperatorsReq_struct{
    CiMmNetworkMode                   networkMode;   
    CiBoolean                         extendedNetworkSearch;	/**<TRUE  run extended Network PLMN Search. FALSE  run PLMN Search ;add CQ00114574 by taow 20190419*/
} CiMmPrimGetNumNetworkOperatorsReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NUM_NETWORK_OPERATORS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNumNetworkOperatorsCnf_struct{
    CiMmResultCode  	Result;			/**< Result code \sa CiMmResultCode */
    UINT8           		NumOperators;	/**< Number of operators present  */
} CiMmPrimGetNumNetworkOperatorsCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNetworkOperatorInfoReq_struct{
    UINT8 				Index;			/**< Numeric index, specifying the network operator for which information is requested [1..number of operators present]  */
} CiMmPrimGetNetworkOperatorInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NETWORK_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNetworkOperatorInfoCnf_struct{
    CiMmResultCode       	Result;		/**< Result code \sa CiMmResultCode */
    CiMmNetOpStatusInfo  	opStatus;		/**< Network operator status information, if available \sa CiNetOpStatusInfo_struct */
} CiMmPrimGetNetworkOperatorInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_REQ"> */
typedef CiEmptyPrim CiMmPrimGetNumPreferredOperatorsReq;

/* <INUSE> */
//ICAT EXPORTED STRUCT
/** <paramref name="CI_MM_PRIM_GET_NUM_PREFERRED_OPERATORS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNumPreferredOperatorsCnf_struct{
    CiMmResultCode  		Result;			/**< Result code \sa CiMmResultCode */
    UINT8          		    NumPref;    	/**< Number of entries in the list  */	
    UINT8          		    NumTotalInSim; 	/**< Number of total entries in the SIM  */
} CiMmPrimGetNumPreferredOperatorsCnf;


/* <NOTINUSE> */
/** <paramref name="CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetPreferredOperatorInfoReq_struct{
    UINT8 		Index;		/**< Not in use */
} CiMmPrimGetPreferredOperatorInfoReq;

/* <NOTINUSE> */
/** <paramref name="CI_MM_PRIM_GET_PREFERRED_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetPreferredOperatorInfoCnf_struct{
    CiMmResultCode    		Result;				/**< Result code \sa CiMmResultCode */
    CiMmNetOpIdInfo   		info;				/**< Network/operator ID information \sa CiNetOpIdInfo_struct */
    UINT8   	            AccTchMode;		    /**< Access Radio technology bitmap; bit 1 - GSM, bit2 - GSM COMPACT, bit 3 - UTRAN, bit4 - EUTRAN, bit 5 - NG-RAN */
} CiMmPrimGetPreferredOperatorInfoCnf;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_ADD_PREFERRED_OPERATOR_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimAddPreferredOperatorReq_struct{
  CiMmNetOpIdInfo  	info;				/**< New network/operator ID information \sa CiNetOpIdInfo_struct  */
  CiMmAddPrefOpType addPrefOpType;		/**< \sa CiMmAddPrefOpType */
  UINT8             		res1U8;         			/**< (padding) just in case */
  UINT16            		index;				/**< Entry number to add  */
  UINT8   	                AccTchMode;		    /**< ACT parameter for CPOL command bitmap; bit 1 - GSM, bit2 - GSM COMPACT, bit 3 - UTRAN, bit4 - EUTRAN, bit 5 - NG-RAN*/
} CiMmPrimAddPreferredOperatorReq;

/* <NOTINUSE> */
/** <paramref name="CI_MM_PRIM_ADD_PREFERRED_OPERATOR_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimAddPreferredOperatorCnf_struct{
    CiMmResultCode  	Result;				/**< Result code \sa CiMmResultCode */
    UINT8           		NumPref;			/**< Not in use */
} CiMmPrimAddPreferredOperatorCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimDeletePreferredOperatorReq_struct{
    UINT8 		Index;		/**< Index (entry number) to delete */
} CiMmPrimDeletePreferredOperatorReq;

/* <NOTINUSE> */
/** <paramref name="CI_MM_PRIM_DELETE_PREFERRED_OPERATOR_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimDeletePreferredOperatorCnf_struct{
    CiMmResultCode  	Result;				/**< Result code \sa CiMmResultCode */
    UINT8           		NumPref;			/**< Not in use */
} CiMmPrimDeletePreferredOperatorCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetCurrentOperatorInfoReq;

/*20190605 add for IMS BEGIN*/

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetAsrCurrentOperatorInfoReq;
/*20190605 add for IMS END*/


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_CURRENT_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetCurrentOperatorInfoCnf_struct{
   	CiMmResultCode    	Result;				/**< Result code \sa CiMmResultCode */
   	CiMmRegMode       	RegMode;			/**< Current registration mode \sa CiMmRegMode */
  	CiMmNetOpIdInfo   	info[2];				/**< Current network/operator ID information \sa CiNetOpIdInfo_struct */
    /*  deleted by xwzhou 09052013  CQ43000,begin */
   	//CiMmAccTechMode   	AccTchMode;		/**< Access radio technology; default is GSM \sa CiMmAccTechMode */
    /*  deleted by xwzhou 09052013  CQ43000,end */
} CiMmPrimGetCurrentOperatorInfoCnf;



/*20190605 add for IMS BEGIN*/
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_ASRCURRENT_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetAsrCurrentOperatorInfoCnf_struct{
   	CiMmResultCode    	Result;				/**< Result code \sa CiMmResultCode */
   	CiMmRegMode       	RegMode;			/**< Current registration mode \sa CiMmRegMode */
  	CiMmNetOpIdInfo   	info[2];				/**< Current network/operator ID information \sa CiNetOpIdInfo_struct */	
  	CiMmNetOpIdInfo   	info_alpha[2];				/**< Current network/operator ID information \sa CiNetOpIdInfo_struct */
  	CiMmNetOpIdInfo   	info_longAlpha[2];				/**< Current network/operator ID information \sa CiNetOpIdInfo_struct */	
} CiMmPrimGetAsrCurrentOperatorInfoCnf;


/*20190605 add for IMS END*/


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NETWORK_MODE_REQ"> */
typedef CiEmptyPrim CiMmPrimNetworkModeReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NETWORK_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNetworkModeCnf_struct {
	CiMmResultCode			result;		/**< Result code \sa CiMmResultCode */
	CiMmNetworkModeReport	mode;		/**< Cell capabilities network mode*/
	CiBoolean				gprsActive;	/**< Active high speed service: gprsActive (1 - gprs is active, 0 - gprs is inactive)*/
	CiBoolean				egprsActive;/**< Active high speed service: egprsActive (1 - egprs is active, 0 - egprs is inactive)*/
	CiBoolean				hsdpaActive;/**< Active high speed service: hsdpaActive (1 - hsdpa is active, 0 - hsdpa is inactive)*/
	CiBoolean				hsupaActive;/**< Active high speed service: hsupaActive (1 - hsupa is active, 0 - hsupa is inactive)*/
	CiBoolean				epsActive;	/**< Active high speed service: epsActive (1 - eps is active, 0 - eps is inactive)*/
	CiBoolean				dcHsdpaActive;	/**< Active high speed service: dcHsdpaActive (1 - dcHsdpa is active, 0 - dcHsdpa is inactive)*/
	CiBoolean				hspaPlusActive;	/**< Active high speed service: hspaPlusActive (1 - HSPA+ is active, 0 - HSPA+ is inactive)*/
} CiMmPrimNetworkModeCnf;
	
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_AUTO_REGISTER_REQ"> */
typedef CiEmptyPrim CiMmPrimAutoRegisterReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_AUTO_REGISTER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimAutoRegisterCnf_struct{
    CiMmResultCode Result;		/**< Result code \sa CiMmResultCode */
} CiMmPrimAutoRegisterCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_MANUAL_REGISTER_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimManualRegisterReq_struct{
    CiBoolean          		AutoFallback;			/**< TRUE - Fallback to automatic registration; FALSE - No fallback to automatic registration  \sa CCI API Ref Manual */
	CiMmNetOpIdInfo    		info;					/**< Network operator identification information \sa CiNetOpIdInfo_struct */
    CiMmAccTechMode    	AccTchMode;			/**< Access radio technology; default is GSM \sa CiMmAccTechMode */
} CiMmPrimManualRegisterReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_MANUAL_REGISTER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimManualRegisterCnf_struct{
    CiMmResultCode 		Result;		/**< Result code \sa CiMmResultCode */
} CiMmPrimManualRegisterCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_DEREGISTER_REQ"> */
typedef CiEmptyPrim CiMmPrimDeregisterReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_DEREGISTER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimDeregisterCnf_struct{
    CiMmResultCode 	Result;			/**< Result code \sa CiMmResultCode */
} CiMmPrimDeregisterCnf;

typedef CiEmptyPrim CiMmPrimGetSigQualityIndConfigReq;

//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSigQualityIndConfigCnf_struct{
    CiMmResultCode        Result;
	CiMmSigQualityConfig  config;
} CiMmPrimGetSigQualityIndConfigCnf;



/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetSigQualityIndConfigReq_struct{
  CiMmSigQualityConfig  	config;				/**< Signal quality configuration  \sa CiMmSigQualityConfig_struct */
} CiMmPrimSetSigQualityIndConfigReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SIGQUALITY_IND_CONFIG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetSigQualityIndConfigCnf_struct{
    CiMmResultCode 		Result;		/**< Result code \sa CiMmResultCode */
} CiMmPrimSetSigQualityIndConfigCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SIGQUALITY_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSigQualityInfoInd_struct{
    CiMmSigQualityInfo  	info;					/**< Signal quality information \sa CiMmSigQualityInfo_struct  */
} CiMmPrimSigQualityInfoInd;

/*Modified by xwzhou for CQ on 08052013, begin*/      

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_EXTENDED_SIGQUALITY_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimExtendedSigQualityInfoInd_struct{
    CiMmSigExtendedQualityInfo  	info;		/**< Signal quality information \sa CiMmSigExtendedQualityInfo_struct  */
} CiMmPrimExtendedSigQualityInfoInd;//add by xwzhou

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SIGQUALITY_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNormalSigQualityInfoInd_struct{
    CiMmSigNormalQualityInfo  	info;			/**< Signal quality information \sa CiMmSigQualityInfo_struct  */
} CiMmPrimNormalSigQualityInfoInd;//add by xwzhou

/*Modified by xwzhou for CQ on 08052013, end*/      

/*Modified by taow for CQ on 20160822, begin*/ 

/** \brief cuase type for  Get SigQuality  info Type*/
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_SIGQUALITY_TYPE {
    CI_MM_SIGQUALITY_CSQ = 0, 			/**< Indicates that <reject_cause> contains an MM cause value, see 3GPP TS 24.008 [8] Annex G*/
    CI_MM_SIGQUALITY_ECSQ,      /**< Indicates that <reject_cause> contains a manufacturer specific cause  */
	CI_MM_SIGQUALITY_NONE,    
} _CiMmSigQualityType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Available values for cuase type
 *  \sa CIMM_CUASE_TYPE
 * \remarks Common Data Section */
typedef UINT8 CiMmSigQualityType;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SIGQUALITY_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSigQualityInfoReq_struct{
	CiMmSigQualityType sigQualityType;

}CiMmPrimSigQualityInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SIGQUALITY_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSigQualityInfoCnf_struct {
	CiMmResultCode				result;
	CiMmSigQualityType			sigQualityType;
	CiMmSigNormalQualityInfo	normalInfo; 		/**< Signal quality information \sa CiMmSigQualityInfo_struct  */
	CiMmSigExtendedQualityInfo	extendedInfo;		/**< Signal quality information \sa CiMmSigExtendedQualityInfo_struct  */
} CiMmPrimSigQualityInfoCnf;


/*Modified by taow for CQ on 20160822, end*/ 



/* SCR #1401348-- START */

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEnableNetworkModeIndReq_struct
{
    CiBoolean enable;		/**< TRUE - Enable network mode indication; FALSE - Disable network mode indication (default) \sa CCI API Ref Manual */
} CiMmPrimEnableNetworkModeIndReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_ENABLE_NETWORK_MODE_IND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEnableNetworkModeIndCnf_struct{
    CiMmResultCode 	Result;		/**< Result code \sa CiMmResultCode */
} CiMmPrimEnableNetworkModeIndCnf;


//Michal Bukai - NW Mode Indication support



/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NETWORK_MODE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNetworkModeInd_struct
{
/* Michal Bukai enter Vadim modification for NetworkModeIndication */
#if 0
    CiMmNetworkMode  			mode;
#endif
    	CiMmNetworkModeReport 		mode;			/**< Cell capabilities network mode \sa CiMmNetworkModeReport */
	CiBoolean 					gprsActive;		/**< Active high speed service: gprsActive (1 - gprs is active, 0 - gprs is inactive) \sa CCI API Ref Manual */
	CiBoolean 					egprsActive;		/**< Active high speed service: egprsActive (1 - egprs is active, 0 - egprs is inactive) \sa CCI API Ref Manual */
	CiBoolean 					hsdpaActive;		/**< Active high speed service: hsdpaActive (1 - hsdpa is active, 0 - hsdpa is inactive) \sa CCI API Ref Manual */
	CiBoolean 					hsupaActive;		/**< Active high speed service: hsupaActive (1 - hsupa is active, 0 - hsupa is inactive) \sa CCI API Ref Manual */
    CiBoolean                   hspaPlusActive;     /**< Active high speed service: hspa+ (1 - hspa+ is active, 0 - hspa+ is inactive)  \sa CCI API Ref Manual */
	
	CiBoolean                   epsActive;		    /**< Active high speed service: epsActive (1 - eps is active, 0 - eps is inactive) \sa CCI API Ref Manual */

    UINT8 domain;    /**< CS or PS domain, 0:CS only;1:PS only;2:Combined CS/PS */
} CiMmPrimNetworkModeInd;

/* SCR #1401348-- END */

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NITZ_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetNitzInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NITZ_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNitzInfoCnf_struct
{
  CiMmResultCode 		Result;					/**< Result code \sa CiMmResultCode */
  CiMmNitzInfo   			info;				/**< NITZ information \sa CiMmNitzInfo_struct */
} CiMmPrimGetNitzInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NITZ_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNitzInfoInd_struct
{
  CiMmNitzInfo   	info;						/**< NITZ information \sa CiMmNitzInfo_struct */
} CiMmPrimNitzInfoInd;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CIPHERING_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCipheringStatusInd_struct {
  CiBoolean    CsCipheringOn;             		/**< TRUE if ON, FALSE if OFF; \sa CCI API Ref Manual */
  CiBoolean    PsCipheringOn;             		/**< TRUE if ON, FALSE if OFF; \sa CCI API Ref Manual */
  CiBoolean    CipheringIndicatorOn;      		/**< TRUE if required, FALSE if not required; \sa CCI API Ref Manual */

} CiMmPrimCipheringStatusInd;

/*Tal Porat/Michal Bukai - Network Selection*/

/** \brief MM Registartion/Authentication Reject type values */
/** \remarks Common Data Section */
typedef enum CIMM_REJECT_TYPE{
    CI_MM_LUP_REJECT = 0,      /**< Location Update Reject */
    CI_MM_AUTH_FAIL,           /**< MM Authentication fail */
    CI_MM_CS_AUTH_RJECT,       /**< NW CS Auth reject */

    CI_MM_NUM_REJECT_TYPE

}_CiMmRejectType;

typedef UINT8 CiMmRejectType;

/** \brief GMM Registartion/Authentication Reject type values */
/** \remarks Common Data Section */
typedef enum CIGMM_REJECT_TYPE{
    CI_GMM_GPRS_ATTACH_REJECT = 0,  /**< GPRS Attach/Combined Attach Reject */
    CI_GMM_RAU_REJECT,              /**< RAU/Combined RAU Reject */
    CI_GMM_PS_SECURITY_FAIL,        /**< PS security fail */
    CI_GMM_PS_AUTH_RJECT,           /**< NW PS Auth reject */   

    CI_GMM_NUM_REJECT_TYPE

}_CiGmmRejectType;

typedef UINT8 CiGmmRejectType;

/** \brief GMM Registartion/Authentication Reject type values */
/** \remarks Common Data Section */
typedef enum CIEMM_REJECT_TYPE{
    CI_EMM_ATTACH_REJECT = 0,  /**< EMM_ATTACH_REJECT */
    CI_EMM_TAU_REJECT,         /**< EMM_TAU_REJECT */
    CI_EMM_AUTH_FAIL,          /**< EMM_AUTH_FAIL */
    CI_EMM_AUTH_NW_REJECT,      /**< EMM_AUTH_NW_REJ */   

    CI_EMM_NUM_REJECT_TYPE
    
}_CiEmmRejectType;

typedef UINT8 CiEmmRejectType;


/** <paramref name="CI_MM_PRIM_AIR_INTERFACE_REJECT_CAUSE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimAirInterfaceRejectCauseInd_struct{
    CiMmRejectType  mmRejectType;   /**< MM Reject type  \sa CiMmRejectType */
    CiMmCause		mmCause;		/**< MM state  \sa CiMmCause */

    CiGmmRejectType gmmRejectType;  /**< GMM Reject type  \sa CiGmmRejectType */
    CiGmmCause		gmmCause; 		/**< GMM state  \sa CiGmmCause */

    CiEmmRejectType emmRejectType;
    CiEmmCause      emmCause;       /**< EMM state  \sa CiEmmCause */

    CiMmErrorCauseType	causeType;
}CiMmPrimAirInterfaceRejectCauseInd;

/*Michal Bukai - Selection of preferred PLMN list +CPLS - START */

/** <paramref name="CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSelectPreferredPlmnListReq_struct{
	CiMmListIndexType ListIndex;	/**< Preferred PLMN list type \sa CiMmListIndexType*/
} CiMmPrimSelectPreferredPlmnListReq;

/** <paramref name="CI_MM_PRIM_SELECT_PREFERRED_PLMN_LIST_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSelectPreferredPlmnListCnf_struct{
    CiMmResultCode Result;          /**< Result code \sa CiMmResultCode */
} CiMmPrimSelectPreferredPlmnListCnf;
/** <paramref name="CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_REQ"> */
typedef CiEmptyPrim CiMmPrimGetPreferredPlmnListReq;

/** <paramref name="CI_MM_PRIM_GET_PREFERRED_PLMN_LIST_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetPreferredPlmnListCnf_struct{
    CiMmResultCode      Result;     /**< Result code \sa CiMmResultCode */
    CiMmListIndexType ListIndex;    /**< Preferred PLMN list type \sa CiMmListIndexType*/
} CiMmPrimGetPreferredPlmnListCnf;
/*Michal Bukai - Selection of preferred PLMN list +CPLS - END */

//ENS CSP start
/* ********************************************************************************************* *
 * CiMmPrimServiceRestrictionsInd
 *
 * Notification of allowing/disallowing Manual PLMN selection option in the user menu.
 *
 * The protocol stack sends an indication regarding whether manual PLMN selection appearance in the user's menu.
 * the decision regarding allowing / disallowing the appearance of this option in the user's menu is done by SIM
 * (could be sent by OTA).
 */
/** <paramref name="CI_MM_PRIM_SERVICE_RESTRICTIONS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimServiceRestrictionsInd_struct
{
	CiBoolean	manualPlmnSelectionAllowed; /**< TRUE if display of PLMN selection menus is allowed  \sa CCI API Ref Manual */
} CiMmPrimServiceRestrictionsInd;

/*Michal Bukai - cancel PLMN search (Samsung)- Start:*/
/*****************************************************/
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_REQ"> */
typedef CiEmptyPrim CiMmPrimCancelManualPlmnSearchReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CANCEL_MANUAL_PLMN_SEARCH_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCancelManualPlmnSearchCnf_struct{
    CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
} CiMmPrimCancelManualPlmnSearchCnf;
/*Michal Buaki - cancel PLMN search (Samsung)- End:*/

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_TRIGGER_USER_RESELECTION_REQ"> */
typedef CiEmptyPrim CiMmPrimTriggerUserReselectionReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_TRIGGER_USER_RESELECTION_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimTriggerUserReselectionCnf_struct {
	CiMmResultCode					result;		/**< Result code */
} CiMmPrimTriggerUserReselectionCnf;


/*Michal Buaki - HOME ZONE support*/
/**********************************/
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_HOMEZONE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimHomeZoneInd_struct{
	CiBoolean		ZoneInd;		/**< TRUE - display HomeZone/CitiZone Indication for the zone specified in "ZoneId" field, FALSE -remove HomeZone/CitiZone indication \sa CCI API Ref Manual */
	UINT8			ZoneId;			/**< Zone ID*/	     	
	CiBoolean		IsCityZone;		/**< TRUE - detected zone is CityZone, FALSE - detected zone is HomeZone \sa CCI API Ref Manual */
	CiBoolean		ZoneTagPreset;	/**< TRUE - Zone TAG is included, FALSE - Zone TAG is not included \sa CCI API Ref Manual */
	CiString 		ZoneTag;		/**< 13-character string coded in the short message alphabet given in GSM 03.38 with bit 8 set to Zero. 0xff indicates end of string \sa CCI API Ref Manual */	     	
} CiMmPrimHomeZoneInd;

/****************************************/
/*Michal Bukai - Cell Lock - Start		*/
/****************************************/
//ICAT EXPORTED ENUM
/** \brief  Cell lock modes */
/** \remarks Common Data Section */
typedef enum CIMM_CELL_LOCK_MODE
{
    CIMM_CELL_LOCK_MODE_NONE  = 0, /**< Cell/Freq Lock and IRAT optimization disabled */
    CIMM_CELL_LOCK_MODE_LOCKFREQ  = 1, /**< Freq Lock enabled */
    CIMM_CELL_LOCK_MODE_LOCKCELL  = 2, /**< Cell Lock enabled */
    //CIMM_CELL_LOCK_MODE_IRAT_OPTIMIZATION  = 3, /**< IRAT optimization for cell reselection enabled */
    CIMM_CELL_LOCK_MODE_LOCKBAND = 3,
    //CIMM_CELL_LOCK_MODE_SYNC_CELL = 4, /**< LTE Cell sync detection enabled */

    CIMM_NUM_CELLLOCK_MODES,
}_CiMmCellLockMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief GSM band values
 * \sa CIMM_CELLLOCK_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiMmCellLockMode;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CELL_LOCK_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCellLockReq_struct{
    CiMmCellLockMode   mode;  /**< Cell lock mode \sa CiMmCellLockMode */
    CiMmCellLockActMode        act;      /**< Network mode \sa CiMmNetworkMode */
    UINT8              bandValue;
    UINT32             freq;              /**< Absolute radio frequency channel number; GSM number 0-1023, TD number 10054-10121 and 9404-9596 */
    INT16              cellId;    /**< Cell parameter ID This parameter if valid for 3G cells only 0-127, and for TD LTE cells only 0-503  */
    //INT8            tddOffset;          /**< RSCP threshold for IRAT cell reselection; -115~-25dB and default -85dB*/
} CiMmPrimCellLockReq;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CELL_LOCK_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCellLockCnf_struct{
    CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
} CiMmPrimCellLockCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CELL_LOCK_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCellLockInd_struct{
    CiMmCellLockMode  mode;             /**< Cell lock mode \sa CiMmCellLockMode */
    CiMmNetworkMode   networkMode;      /**< Network mode \sa CiMmNetworkMode */

    UINT16          arfcn;              /**< Absolute radio frequency channel number; GSM number 0-1023, TD number 10054-10121 and 9404-9596 */
    UINT8           cellParameterId;    /**< Cell parameter ID This parameter if valid for 3G cells only 0-127*/
    INT8            tddOffset;          /**< RSCP threshold for IRAT cell reselection; -115~-25dB and default -85dB*/
} CiMmPrimCellLockInd;
/****************************************/
/*Michal Bukai - Cell Lock - End		*/
/****************************************/

/* <INUSE>, this only used for LWG, to lock GSM+WCDMA frequence */
/** <paramref name="CI_MM_PRIM_WB_CELL_LOCK_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimWBCellLockReq_struct{
    CiBoolean  			ActivateCellLock;	/**< TRUE - activate cell lock; FALSE - deactivate cell lock \sa CiBoolean */
	CiMmCurrentBandInfo Band;				/**< Band \sa CiMmCurrentbandInfo */
	UINT16				arfcn;				/**< Absolute radio frequency channel number; number 0-1023 */
	UINT16				ScramblingCode;		/**< Primary scrambling code This parameter if valid for 3G cells only */
} CiMmPrimWBCellLockReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_WB_CELL_LOCK_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimWBCellLockCnf_struct{
    CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
} CiMmPrimWBCellLockCnf;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_FAST_DORMANT_CAP_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetFastDormantCapReq_struct{
    CiBoolean   fastDormantEnabled;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
} CiMmPrimSetFastDormantCapReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_FAST_DORMANT_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetFastDormantCapCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */
} CiMmPrimSetFastDormantCapCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_FAST_DORMANT_CAP_REQ"> */
typedef CiEmptyPrim CiMmPrimGetFastDormantCapReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_FAST_DORMANT_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetFastDormantCapCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */

    CiBoolean   fastDormantEnabled;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
} CiMmPrimGetFastDormantCapCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetNasIntegrityCheckReq_struct{
    CiBoolean   integrityCheckEnabled;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
} CiMmPrimSetNasIntegrityCheckReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_NAS_INTEGRITY_CHECK_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetNasIntegrityCheckCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */
} CiMmPrimSetNasIntegrityCheckCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_REQ"> */
typedef CiEmptyPrim CiMmPrimGetNasIntegrityCheckReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NAS_INTEGRITY_CHECK_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNasIntegrityCheckCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */

    CiBoolean   integrityCheckEnabled;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
} CiMmPrimGetNasIntegrityCheckCnf;

/* <INUSE> */
/**	CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_REQ - Requests the number of LTE operators present in the network
*/
typedef CiEmptyPrim CiMmPrimGetNumLteNetworkOperatorsReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NUM_LTE_NETWORK_OPERATORS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNumLteNetworkOperatorsCnf_struct{
    CiMmResultCode  Result;         /**< Result code \sa CiMmResultCode */
    UINT8           NumOperators;   /**< Number of operators present  */
} CiMmPrimGetNumLteNetworkOperatorsCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetLteNetworkOperatorInfoReq_struct{
    UINT8           Index;     /**< Numeric index, specifying the network operator for which information is requested [1..number of operators present]  */
} CiMmPrimGetLteNetworkOperatorInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_LTE_NETWORK_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetLteNetworkOperatorInfoCnf_struct{
    CiMmResultCode       Result;        /**< Result code \sa CiMmResultCode */

    CiMmNetOpStatusInfo  opStatus;      /**< Network operator status information, if available \sa CiNetOpStatusInfo_struct */
} CiMmPrimGetLteNetworkOperatorInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetLteBackgroundInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_LTE_BACKGROUND_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetLteBackgroundInfoCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */
    CiBoolean           status;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
    UINT16               interval; /**< Background search interval in minutes, 0:immediately;15,30,60 minutes;0xFFFF don't search*/
} CiMmPrimGetLteBackgroundInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetLteBackgroundInfoReq_struct{
    CiBoolean           status;   /**< TRUE - enabled; FALSE - disabled; \sa CCI API Ref Manual */
    UINT16              interval; /**< Background search interval in minutes, 0:immediately;15,30,60 minutes;0xFFFF don't search*/
} CiMmPrimSetLteBackgroundInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_LTE_BACKGROUND_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetLteBackgroundInfoCnf_struct{
    CiMmResultCode      result;   /**< Result code \sa CiMmResultCode */
} CiMmPrimSetLteBackgroundInfoCnf;

//ICAT EXPORTED ENUM
/** \brief  Paging Identity Element */
/** \remarks Common Data Section */
typedef enum CIMM_PAGING_IDENTITY_ELEMENT
{
    CI_MM_CN_PAGING_BY_IMSI,
    CI_MM_CN_PAGING_BY_TMSI,
    
    CI_MM_NUM_PAGING_IDENTITY_ELEMENT
}_CiMmPagingIdentityElement;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Paging Identity Element
 * \sa CIMM_PAGING_IDENTITY_ELEMENT */
/** \remarks Common Data Section */
typedef UINT8 CiMmPagingIdentityElement;

/** \brief  Cli Element structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmCliElement_struct
{
    INT8                            length;
    INT8                            data[CI_MM_MAX_CLI_IE_SIZE];      /* 24008,  10.5.4.9 */
}CiMmCliElement;

/** \brief  Ss Code Element structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmSsCodeElement_struct
{
    INT8                            value;                      /* 29002,  17.7.5 */
}CiMmSsCodeElement;

/** \brief  Lcs Indicator Element structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmLcsIndicatorElement_struct
{
    INT8                            value;
}CiMmLcsIndicatorElement;

/** \brief  Lcs Client Identity Element structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMmLcsClientIdentityElement_struct
{
    INT8                            length;
    INT8                            data[CI_MM_MAX_LCS_CLIENT_IDENTITY_IE_SIZE];   /* 29002,  17.7.13 */
}CiMmLcsClientIdentityElement;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CS_SERVICE_NOTIFICATION_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsServiceNotificationInd_struct{
    CiMmPagingIdentityElement       pagingIdentity;                          /* 24301,  9.9.3.25A */
    CiBoolean                     cliPresent;
    CiMmCliElement                  cli;                                     /* 24301,  9.9.3.38 */
    CiBoolean                     ssCodePresent;
    CiMmSsCodeElement               ssCode;                                  /* 24301,  9.9.3.39 */
    CiBoolean                     lcsIndicatorPresent;
    CiMmLcsIndicatorElement         lcsIndicator;                            /* 24301,  9.9.3.40 */
    CiBoolean                     lcsClientIdentityPresent;
    CiMmLcsClientIdentityElement    lcsClientIdentity;                       /* 24301,  9.9.3.41 */
}CiMmPrimCsServiceNotificationInd;

//ICAT EXPORTED ENUM
/** \brief  CIMM Respond Value */
/** \remarks Common Data Section */
typedef enum CIMM_RSP_VALUE
{
    CI_MM_CSFB_ACCEPT,
    CI_MM_CSFB_REJECT,
    CI_MM_CSFB_OTHERS,     //set it when timer expired,or others
    
    CI_MM_NUM_RSP_VALUE
}_CiMmRspValue;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CIMM Respond Value
 * \sa CIMM_RSP_VALUE */
/** \remarks Common Data Section */
typedef UINT8 CiMmRspValue;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_CS_SERVICE_NOTIFICATION_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsServiceNotificationRsp_struct{
   CiMmRspValue rspValue;
}CiMmPrimCsServiceNotificationRsp;

//Z.S. DSAC support
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_DSAC_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimDsacStatusInd_struct{
	CiBoolean   csDomainBarred;
	CiBoolean	psDomainBarred;
} CiMmPrimDsacStatusInd;
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SRVCC_SUPPORT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetSrvccSupportReq_struct {
	CiBoolean	srvcc_status;
} CiMmSetSrvccSupportReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SRVCC_SUPPORT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetSrvccSupportCnf_struct {
     CiMmResultCode  	result;							/**< Result code \sa CiMmResultCode */
} CiMmSetSrvccSupportCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SRVCC_SUPPORT_REQ"> */
typedef CiEmptyPrim CiMmGetSrvccSupportReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SRVCC_SUPPORT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmGetSrvccSupportCnf_struct {
     CiMmResultCode  	result;							/**< Result code \sa CiMmResultCode */
     CiBoolean			srvcc_status;
} CiMmGetSrvccSupportCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetImsNwReportModeReq_struct{
	CiBoolean	reporting;
}CiMmSetImsNwReportModeReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_IMS_NW_REPORT_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetImsNwReportModeCnf_struct{
	CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
}CiMmSetImsNwReportModeCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_REQ"> */
typedef CiEmptyPrim CiMmGetImsNwReportModeReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_IMS_NW_REPORT_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmGetImsNwReportModeCnf_struct{
	CiMmResultCode  result;			/**< Result code \sa CiMmResultCode */
	CiBoolean		reporting;
	CiBoolean		nwimsvops;
}CiMmGetImsNwReportModeCnf;

#define MAX_MM_SRVCC_REPORTS  2

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_IMSVOPS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmImsvopsInd_struct{
	CiBoolean	nwimsvops;
}CiMmImsvopsInd;

//ICAT EXPORTED ENUM
typedef enum CIMM_SRVCC_IND_TYPE {
    CI_MM_SRVCC_STARTED = 0,
    CI_MM_SRVCC_SUCCESSFUL,
    CI_MM_SRVCC_CANCELLED,
	CI_MM_SRVCC_GENERAL_FAILURE,
                
    /* This one must always be last in the list! */
    CI_MM_SRVCC_NUM_TYPE
} _CiMmSrvccType;

typedef UINT8 CiMmSrvccHType;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SRVCC_HANDOVER_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSrvccHandoverInd_struct{
	CiMmSrvccHType	srvcch;
}CiMmSrvccHandoverInd;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetEmergencyNumberReportModeReq_struct{
	CiBoolean	reporting;
}CiMmSetEmergencyNumberReportModeReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_EMERGENCY_NUMBER_REPORT_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetEmergencyNumberReportModeCnf_struct{
	CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
}CiMmSetEmergencyNumberReportModeCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_REQ"> */
typedef CiEmptyPrim CiMmGetEmergencyNumberReportReq;

//ICAT EXPORTED STRUCT
typedef struct CiMmEmergencyNumberInfo_struct{
	CHAR    	dialString[CI_MAX_ADDRESS_LENGTH];
	CiBitRange	ServiceCat; 
}CiMmEmergencyNumberInfo;

#define MAX_EMERGENCY_NUMBER 15

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_EMERGENCY_NUMBER_REPORT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmGetEmergencyNumberReportCnf_struct{
	CiMmResultCode  			result;			/**< Result code \sa CiMmResultCode */
	CiBoolean					reporting;		/** 0 - disable; 1 - enable */
	CiMmNetworkId       		networkId;
	UINT8               		numNumbers; 	/** num of emergency numbers */
	CiMmEmergencyNumberInfo    	numbers[MAX_EMERGENCY_NUMBER]; 
}CiMmGetEmergencyNumberReportCnf;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_EMERGENCY_NUMBER_REPORT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmEmergencyNumberReportInd_struct{
	CiBoolean			reporting;     /** 0 - disable; 1 - enable */
	CiMmNetworkId       networkId;
	UINT8               numNumbers; /** num of emergency numbers */
	CiMmEmergencyNumberInfo    numbers[MAX_EMERGENCY_NUMBER]; 
}CiMmEmergencyNumberReportInd;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetNwEmergencyBearerServicesReq_struct{
	CiBoolean	reporting;
}CiMmSetNwEmergencyBearerServicesReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_NW_EMERGENCY_BEARER_SERVICES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmSetNwEmergencyBearerServicesCnf_struct{
	CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
}CiMmSetNwEmergencyBearerServicesCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_REQ"> */
typedef CiEmptyPrim CiMmGetNwEmergencyBearerServicesReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_NW_EMERGENCY_BEARER_SERVICES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmGetNwEmergencyBearerServicesCnf_struct{
	CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
	CiBoolean			reporting;
	UINT8				emb_Iu_supp;
	UINT8				emb_S1_supp;
}CiMmGetNwEmergencyBearerServicesCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_IU_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmNwEmergencyBearerServicesIuInd_struct{
	UINT8				emb_Iu_supp;
}CiMmNwEmergencyBearerServicesIuInd;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NW_EMERGENCY_BEARER_SERVICES_S1_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmNwEmergencyBearerServicesS1Ind_struct{
	UINT8				emb_S1_supp;
}CiMmNwEmergencyBearerServicesS1Ind;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SSAC_STATUS_REQ"> */
typedef CiEmptyPrim CiMmGetSsacStatusReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SSAC_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmGetSsacStatusCnf_struct{
	CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
	UINT8				BFVoice;		/**< parameter shows the barring factor for MMTEL voice (0-16) */
	UINT8				BFVideo;		/**< parameter shows the barring factor for MMTEL video (0-16) */
	UINT8				BTVoice;		/**< parameter shows the barring timer for MMTEL voice (0-8) */
	UINT8				BTVideo;		/**< parameter shows the barring timer for MMTEL video (0-8) */
}CiMmGetSsacStatusCnf;




/* At*CSG  */
/**<  total number could be up to 40. up to 20 csg will send in a single response due to 2k limitation of max cnf  message. app will send multi  req to get full csg list */
//#define MAX_NUMBER_OF_CSG		40
#define MAX_NUMBER_OF_CSG		20
#define CI_MM_CSG_HNB_NAME_MAX	48
#define CI_MM_CSG_HNB_TYPE_MAX	12

typedef enum CiMmCsgWhiteListTypeTag
{
	CI_MM_CSG_WHITE_LIST_NONE		= 0,
	CI_MM_CSG_WHITE_LIST_ALLOWED	= 1,
	CI_MM_CSG_WHITE_LIST_OPERATOR	= 2,
	CI_MM_CSG_WHITE_LIST_ALLOWED_AND_OPERATOR = 3
}_CiMmCsgWhiteListType;

typedef UINT8 CiMmCsgWhiteListType;

//ICAT EXPORTED STRUCT
typedef struct CiMmCsgInfo_struct {
	UINT32		csgId;								/**< indicates the CSG ID of the cells which were found. */
	CiBoolean	hnbNamePresent;						/**< indicates if HnbName is used. TRUE - HnbName is used. False - HnbName is unused.*/
	UINT8		hnbName[CI_MM_CSG_HNB_NAME_MAX];	/**< text of up to 48 chars. */
	CiBoolean	hnbTypePresent;						/**< indicates if HnbType is used. TRUE - HnbType is used. False - HnbType is unused.*/
	UINT8		hnbType[CI_MM_CSG_HNB_TYPE_MAX];	/**< Additional information for this CSG. */
    CiMmCsgWhiteListType whileListType;
}CiMmCsgInfo;

//ICAT EXPORTED STRUCT
typedef struct CiMmCsgCellInfo_struct {
	CiMmCsgInfo				csgInfo;	/**< CSG information */
	CiMmNetworkId			networkId;	/**< Network ID */
	CiMmNetworkMode	        mode;		/**< Cell capabilities network mode */
} CiMmCsgCellInfo;


/** <paramref name="CI_MM_PRIM_CSG_AUTO_SEARCH_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimCsgAutoSearchReq;

/** <paramref name="CI_MM_PRIM_CSG_AUTO_SEARCH_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgAutoSearchCnf_struct {
	CiMmResultCode					result;		/**< Result code */
} CiMmPrimCsgAutoSearchCnf;

/** <paramref name="CI_MM_PRIM_CSG_LIST_SEARCH_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgListSearchReq_struct {
 	UINT8			csgIndexReq;		/**< indicates the CSG index requsted to get, 0 means beging of the new search, else is reading of the last resulsts from listed offset*/
} CiMmPrimCsgListSearchReq;

/**  total number could be up to 40. up to 20 csg will send in a single response due to 2k limitation of max cnf  message. app will send multi  req to get full csg list */
/** <paramref name="CI_MM_PRIM_CSG_LIST_SEARCH_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgListSearchCnf_struct {
	CiMmResultCode			result;						/**< Result code */
	UINT8					totalNumOfCsg;				/**< number of CSG ID which were found 0..MAX_NUMBER_OF_CSG (= 40) */
	UINT8					startCsgIndex;		        /**< first CSG ID inedx which were included in this message */
	UINT8					numCsgList;			        /**< number of CSG ID which were included in this message */
	CiMmCsgCellInfo			csgList[MAX_NUMBER_OF_CSG];	/**< list of all the CSG which were found and their parameters*/
} CiMmPrimCsgListSearchCnf;

/** <paramref name="CI_MM_PRIM_CSG_SELECT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgSelectReq_struct {
	UINT32			csgId;		/**< indicates the CSG ID of the cells which were found. bits 0-26: can receive any value. 27- 31 should be set to 0.*/
	CiMmNetworkId	networkId;	/**< Network ID */
	CiMmNetworkMode	mode;		/**< Selected network mode */
} CiMmPrimCsgSelectReq;

/** <paramref name="CI_MM_PRIM_CSG_SELECT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgSelectCnf_struct {
	CiMmResultCode					result;		/**< Result code */
} CiMmPrimCsgSelectCnf;

/** <paramref name="CI_MM_PRIM_CSG_SEARCH_STOP_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimCsgSearchStopReq;

/** <paramref name="CI_MM_PRIM_CSG_SEARCH_STOP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimCsgSearchStopCnf_struct {
	CiMmResultCode					result;		/**< Result code */
} CiMmPrimCsgSearchStopCnf;


/** <paramref name="CI_MM_PRIM_REGRESULT_EXTENDED_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimRegResultExtendedInd_struct{
  CiMmRegStatus		RegStatus;			/**< Registration status  \sa CiMmRegStatus */
  CiBoolean   		csgCellInfoPresent; /**< Indication if CSG Information field is valid */
  CiMmCsgCellInfo	csgCellInfo;   		/**< CSG  Information */
} CiMmPrimRegResultExtendedInd;


/** <paramref name="CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetPowerUpNetworkModeReq_struct {
    CiMmPowerUpPlmnSelectionMode	mode;		/**< Power up PLMN selection mode \sa CiMmPowerUpPlmnSelectionMode */
} CiMmPrimSetPowerUpNetworkModeReq;

/** <paramref name="CI_MM_PRIM_SET_POWER_UP_PLMN_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetPowerUpNetworkModeCnf_struct {
    CiMmResultCode	result;		/**< Result code */
} CiMmPrimSetPowerUpNetworkModeCnf;

/** <paramref name="CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_REQ"> */
typedef CiEmptyPrim CiMmPrimGetPowerUpNetworkModeReq;

/** <paramref name="CI_MM_PRIM_GET_POWER_UP_PLMN_MODE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetPowerUpNetworkModeCnf_struct {
    CiMmResultCode					result;		/**< Result code */
    CiMmPowerUpPlmnSelectionMode	mode;		/**< Power up PLMN selection mode \sa CiMmPowerUpPlmnSelectionMode */
} CiMmPrimGetPowerUpNetworkModeCnf;

typedef enum CIMM_FRAT_PLMN_ACTION{

	CI_MM_FRAT_ACTION_CLEAR_ALL,
	CI_MM_FRAT_ACTION_ADD,	
	CI_MM_FRAT_ACTION_DELETE,
	CI_MM_FRAT_ACTION_LAST	
}_CiMmFratPlmnAction;

typedef UINT32 CiMmFratPlmnAction;


//ICAT EXPORTED STRUCT
typedef struct CiMmPrimFratListActionReq_struct{
	       CiMmFratPlmnAction  action;
                CiMmNetworkId              newPlmn;                                           /**< PLMN mnc/mcc to be added to FRAT list*/
} CiMmPrimFratListActionReq;

//ICAT EXPORTED STRUCT
typedef struct CiMmPrimFratListActionCnf_struct{
                CiMmResultCode					result;		/**< Result code */
} CiMmPrimFratListActionCnf;


typedef CiEmptyPrim CiMmPrimGetFratListReq;

//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetFratListCnf_struct{
    UINT8                                               listSize;                                                                                                 /**< FRAT list size*/
    CiMmNetworkId              		fratList[CI_MM_MAX_FRAT_LIST_SIZE];                                             /**< FRAT list*/
} CiMmPrimGetFratListCnf;



/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SECURITY_CAPABILITY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetSecurityCapablilityReq_struct
{
  CiBoolean         nasSecCapPresent;
  CiBoolean         umtsRrcCACapPresent;
  CiBoolean         umtsRrcIPCapPresent;

  INT32             nasSecCap;
  INT16             umtsRrcCACap;
  INT16             umtsRrcIPCap;
} CiMmPrimSetSecurityCapablilityReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SECURITY_CAPABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetSecurityCapablilityCnf_struct
{
    CiMmResultCode					result;		/**< Result code */
} CiMmPrimSetSecurityCapablilityCnf;

/** CI_MM_PRIM_GET_SECURITY_CAPABILITY_REQ */
typedef CiEmptyPrim CiMmPrimGetSecurityCapablilityReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SECURITY_CAPABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetSecurityCapablilityCnf_struct
{
    CiMmResultCode					result;		/**< Result code */

    INT32             nasSecCap;
    INT16             umtsRrcCACap;
    INT16             umtsRrcIPCap;
} CiMmPrimGetSecurityCapablilityCnf;
//add by taow 20150506 for ciphering begin


/* <INUSE> this CI only used for SSG*/
/** <paramref name="CI_MM_PRIM_NETWORK_CELL_MAT_INFO_IND"> */
//ICAT EXPORTED ENUM
typedef enum CiMmCipheringIndicatorTag
{
    CI_MM_CIPHERING_NONE  = 0x00,  /* Ciphering not used */
    CI_MM_CIPHERING_CS    = 0x01,  /* EPS integrity Algorithm EIA/1 */
    CI_MM_CIPHERING_PS    = 0x02,
    CI_MM_CIPHERING_CS_PS = 0x03,

}
_CiMmCipheringIndicator;

typedef UINT8 CiMmCipheringIndicator;
//add by taow 20150506 for ciphering end


/* <INUSE> this CI only used for SSG*/
/** <paramref name="CI_MM_PRIM_NETWORK_CELL_MAT_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNetworkCellMatInfoInd_struct
{
    CiMmRegMode    regMode;  // <mode>, from COPS
    CiMmRegStatus  stat;     // <stat>, from CREG
    CiMmNetOpIdInfo netOpInfo; // <format>,<oper>,<act>,<domain>, from COPS
    
    CiBoolean      lacPresent; // in LTE NW mode, LAC maybe not existed
    UINT16         lac;        // <lac>, two bytes
    CiBoolean      racPresent; // in LTE NW mode, no RAC
    UINT8          rac;        // <RAC>, one byte
    CiBoolean      cellIdPresent;
    UINT32         cellId;     // <cellId>
    CiBoolean      tacPresent; // in LTE NW mode, no RAC
    UINT16         tac;        // <tac>, two bytes

    CiBoolean      nwDTMSupported;// whether NW support DTM
    CiBoolean      volteAvaiable; // whether NW support VOLTE
    CiBoolean      imsEmAvaiable; // whether NW support emergency bearer
    CiBoolean      t323Avaiable;
    
    UINT8  mmtelVoiceAcBarringFactor;  /*0-100, Voice service barring factor. From 0 to 100 where 0 means 0% probability and 100 means 100% probability. */
    UINT16 mmtelVoiceAcBarringTime;    /*0-512, Voice service mean access barring time value in seconds. */
    UINT8  mmtelVideoAcBarringFactor;  /*0-100, Video service barring factor. From 0 to 100 where 0 means 0% probability and 100 means 100% probability. */
    UINT16 mmtelVideoAcBarringTime;    /*0-512, Video service mean access barring time value in seconds. */

    CiBoolean      phyCellIdPresent;
	/*LTE:		phy cell ID;
	  *UMTS		Primary scrambling code
	  *GSM		bsic: base station identity code*/
    UINT16         phyCellId; 
    //add by taow 20150506 for ciphering begin
	CiMmCipheringIndicator cipheringIndicator;
    //add by taow 20150506 for ciphering end
  	/*add by taow 20181102 CQ00112738 begin*/
	/*GSM MODE  16-bit GSM Absolute RF channel number; this value must be reported *
        *wcdma 	 16-bit UMTS Absolute RF Channel Number; this value must be reported
        *lte		 18-bit LTE Absolute RF Channel Number; this value must be reported
        */
    UINT32  frequency;
	/*add by taow 20181102 CQ00112738 end*/
}CiMmPrimNetworkCellMatInfoInd;


/******************************************************************************
 * CI_MM_PRIM_EMERGENCY_CALL_STATUS_REQ/CI_MM_PRIM_EMERGENCY_CALL_STATUS_CNF
 * these two CI are used for emergency call service by SSIPC
 * Before ECC call start, SSG AP just use it to query avaiable RAT value for ECC call;
 * and if ECC call failed, SSG AP want to use it to change another RAT value
 * For example: 
 * a> if AP sends ECC start with 0xFF RAT, then CP will response with
 * available RAT(LTE) and RAT_Status(1), 
 * b> then, first of all, AP will try make ECC call using IMS over LTE;
 * c> If failed, the AP will send ECC set(0x04 and RAT(LTE)), then CP has to 
 * send next available ECC rat and response (ex. act = 3G and actStatus = 1)
 *****************************************************************************/
typedef enum _CiMmEccReqStatus_enum
{
    CI_MM_ECC_CALL_NONE = 0,
    CI_MM_ECC_CALL_START = 1,
    CI_MM_ECC_CALL_END = 2,
    CI_MM_ECC_CALL_CANCELED = 3, // eECC call canceled during setup
    CI_MM_ECC_CALL_SETUP_FAIL = 4
}_CiMmEccReqStatus;

typedef enum _CiMmEccCnfActStatus_enum
{
    CI_MM_ECC_NO_ACT = 0,
    CI_MM_ECC_CURRENT_ACT = 1,
}_CiMmEccCnfActStatus;

typedef UINT8 CiMmEccStatus;
typedef UINT8 CiMmEccCnfActStatus;

/* <INUSE> this CI only used for SSG*/
/* SSG want this API to get RAT value used for emergency call */
/** <paramref name="CI_MM_PRIM_EMERGENCY_CALL_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEmergencyCallStatusReq_struct
{
    CiMmEccStatus   eccStatus;
    CiMmAccTechMode reqAct;
}CiMmPrimEmergencyCallStatusReq;

/* SSG want this API to get RAT value used for emergency call */
/** <paramref name="CI_MM_PRIM_EMERGENCY_CALL_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEmergencyCallStatusCnf_struct
{
    CiMmResultCode  result;
    CiMmAccTechMode act;
    CiMmEccCnfActStatus actStatus;  
}CiMmPrimEmergencyCallStatusCnf;



/* Added by liorgo, for CQ00086808, 08/03/2015 - start*/
/** <paramref name="CI_MM_PRIM_NEW_ATTACH_IND"> */
typedef CiEmptyPrim CiMmPrimNewAttachInd;
/* Added by liorgo, for CQ00086808, 08/03/2015 - end*/
/*
Defines the jamming detection operation mode
*/
typedef enum CIMM_UCD_OP_MODE {
	CI_MM_UCD_OP_DISABLE_MODE = 0,
	CI_MM_UCD_OP_2G_JAM_DETECT_MODE,		/*Enable 2G jamming detection*/
	CI_MM_UCD_OP_JAM_INQ_MODE,		/*Request to receive the current jamming status*/
	CI_MM_UCD_OP_3G_JAM_DETECT_MODE,		/*Enable 3G jamming detection*/
	CI_MM_UCD_OP_2G_3G_JAM_DETECT_MODE,		/*Enable 2G and 3G jamming detection*/
	CI_MM_UCD_OP_2G_ADV_JAM_DETECT_MODE,		/*Enable advanced 2G jamming detection*/
	CI_MM_UCD_OP_3G_ADV_JAM_DETECT_MODE,		/*Enable advanced 3G jamming detection*/
	CI_MM_UCD_OP_2G_3G_ADV_JAM_DETECT_MODE		/*Enable 2G and 3G advanced jamming detection*/
} _CiMmUcdOpMode;

typedef UINT8 CiMmUcdOpMode;


/**<paramref name="CI_MM_PRIM_JAMMING_DETECTION_REQ">*/
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimJammingDetectionReq_struct{
	UINT8							mode;					/**< mode of operation */
	UINT8							minNumberOfGsmCarriers; /**< The number of 2G carriers  */
	UINT8							gsmRxLevThreshold;  /**< Threshold level for 2G carriers  */
	UINT8							minNumberOfUmtsCarriers; /**< The number of 3G carriers  */
	UINT8							umtsRssiLevThreshold; /**< Threshold level for 3G carriers  */
	CiBoolean         				networkIdPresent; /**< If true - a prefered network operator is attached  */
	CiMmNetworkId  					networkId; /**< Prefered network operator */
}CiMmPrimJammingDetectionReq;

/** \brief reported jamming status*/
/** \remarks  */
//ICAT EXPORTED ENUM
typedef enum CIMM_JAMMING_STATUS {
	CI_MM_2G_JAMMING_NOT_DETECTED = 0,
	CI_MM_2G_JAMMING_DETECTED,
	CI_MM_3G_JAMMING_NOT_DETECTED,
	CI_MM_3G_JAMMING_DETECTED
} _CiMmJammingStatus;

typedef UINT8 CiMmJammingStatus;

/**<paramref name="CI_MM_PRIM_JAMMING_DETECTION_IND">*/
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimJammingDetectionInd_struct{
	CiMmJammingStatus							active;					/**< jamming status report */
}CiMmPrimJammingDetectionInd;

/**<paramref name="CI_MM_PRIM_JAMMING_DETECTION_CNF">*/
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimJammingDetectionCnf_struct{
	CiMmResultCode							result;	/**< result code */
	CiBoolean         						activePresent;/**< if true - the current jamming status is return */
	UINT8									active;/**< the current jamming status */
}CiMmPrimJammingDetectionCnf;

/** <paramref name="CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimGetJammingDetectionStatusReq;

/** <paramref name="CI_MM_PRIM_GET_JAMMING_DETECTION_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetJammingDetectionStatusCnf_struct{
	CiMmResultCode					Result;
	UINT8							mode; /**< mode of operation */
	UINT8							minNumberOfGsmCarriers;/**< The number of 2G carriers  */
	UINT8							gsmRxLevThreshold; /**< Threshold level for 2G carriers  */
	UINT8							minNumberOfUmtsCarriers;/**< The number of 3G carriers  */
	UINT8							umtsRssiLevThreshold;/**< Threshold level for 3G carriers  */
	CiBoolean         				networkIdPresent;/**< If true - a prefered network operator is attached  */
	CiMmNetworkId  					networkId; /**< Prefered network operator */
}CiMmPrimGetJammingDetectionStatusCnf;

/** <paramref name="CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetGprsEgprsMultislotClassReq_struct{
	UINT8							msClassGprs; /**< Value is 10 or 12. Define the GPRS multislot Class according to 3GPP TS45.002 */
	UINT8							msClassEgprs;/**< Value is 10 or 12. Define the EGPRS multislot Class according to 3GPP TS45.002*/
}CiMmPrimSetGprsEgprsMultislotClassReq;

/** <paramref name="CI_MM_PRIM_SET_GPRS_EGPRS_MULTISLOT_CLASS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetGprsEgprsMultislotClassCnf_struct{
	CiMmResultCode					result;	/**< result code */
}CiMmPrimSetGprsEgprsMultislotClassCnf;

/** <paramref name="CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_REQ"> */
typedef CiEmptyPrim CiMmPrimGetGprsEgprsMultislotClassReq;

/** <paramref name="CI_MM_PRIM_GET_GPRS_EGPRS_MULTISLOT_CLASS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetGprsEgprsMultislotClassCnf_struct{
    CiMmResultCode					result;	/**< result code */
    UINT8							msClassGprs; /**< Value is 10 or 12. Define the GPRS multislot Class according to 3GPP TS45.002 */
    UINT8							msClassEgprs;/**< Value is 10 or 12. Define the EGPRS multislot Class according to 3GPP TS45.002*/
}CiMmPrimGetGprsEgprsMultislotClassCnf;
/** \brief Source of operator name returned */
/** \remarks  */
//ICAT EXPORTED ENUM
typedef enum CIMM_OPERATOR_NAME_SOURCE {
	CI_MM_OPERATOR_NAME_EONS,		/**< EF_OPL and EF_PNN files.*/
	CI_MM_OPERATOR_NAME_NITZ,		/**< NITZ service.*/
	CI_MM_OPERATOR_NAME_CPHS,		/**< CPHS Operator Name string.*/
	CI_MM_OPERATOR_NAME_MT,			/**< MT hardcoded operator name.*/
	CI_MM_OPERATOR_NAME_INVALID,	/**< String containing the operator name to be displayed.*/
} _CiMmOperatorNameSource;

#define CI_MM_MAX_OPERATOR_NAME  128	/* Maximum operator name */


typedef UINT8 CiMmOperatorDisplayType;
typedef UINT8 CiMmDisplayCondition;

//ICAT EXPORTED ENUM
typedef enum CIMM_OPERATOR_DISPLAY_TYPE {
    CI_MM_NUMERIC_FORMAT = 0, 			/**< The network name will appear as MCC/MNC, for example 425/01*/
    CI_MM_SHORT_NAME_IN_ROM,	/**< The short network name from the ROM will be returned*/
    CI_MM_LONG_NAME_IN_ROM,	/**< The long network name from the ROM will be returned*/
    CI_MM_SHORT_NAME_CPHS,	/**< The short network name that appears in the CPHS files on the SIM will be returned*/
    CI_MM_LONG_NAME_CPHS,	/**< The long network name that appears in the CPHS files on the SIM will be returned*/
    CI_MM_SHORT_NITZ_NAME,	/**< The short network name received by NITZ will be returned*/
    CI_MM_FULL_NITZ_NAME,	/**< The full network name received by NITZ will be returned*/
    CI_MM_SERVICE_PROVIDER_NAME,	/**< The network name that has been read from the EF_SPN file on the SIM will be returned*/
    CI_MM_EONS_SHORT_NAME,	/**< The short network name that appears in the EONS files on the SIM will be returned*/
    CI_MM_EONS_LONG_NAME,	/**< The long network name that appears in the EONS files on the SIM will be returned*/
    CI_MM_SHORT_NETWORK_NAME,	/**< Not supported - for future use*/
    CI_MM_LONG_NETWORK_NAME,	/**< Not supported - for future use*/
} _CiMmOperatorDisplayType;

typedef UINT8 CiMmOperatorNameSource;

/** \brief Which type of network name should be returned */
/** \remarks  */
//ICAT EXPORTED ENUM
typedef enum CIMM_DISPLAY_CONDITION {
    CI_MM_SPN_DONT_DISPLAY_PLMN = 0, 	/**< display of the registered PLMN is not required when the registered PLMN is either the HPLMN or a PLMN listed in SPDI list*/
    CI_MM_SPN_DISPLAY_PLMN,				/**< display of the registered PLMN is required when the registered PLMN is either the HPLMN or a PLMN listed in the SPDI list*/
    CI_MM_SPN_DISPLAY_NOT_APPLICABLE,	/**< */
} _CiMmDisplayCondition;

/** \brief  This struct will hold the requested network name
* to be displayed */
//ICAT EXPORTED STRUCT
typedef struct CiMmOperatorDisplayName_struct {
    INT8 Length;			/**<  The length of the string*/
    char OperatorName[CI_MM_MAX_OPERATOR_NAME]; /**< String containing the operator name to be displayed.*/
    CiMmOperatorNameSource OperatorNameSource;	/**< Source of returned operator name. */
} CiMmOperatorDisplayName;

/** <paramref name="CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetDisplayOperatorNameReq_struct {
    CiMmOperatorDisplayType	type; /**< Which type of network name should be returned. See CiMmOperatorDisplayType_enum */
} CiMmPrimGetDisplayOperatorNameReq;

/** <paramref name="CI_MM_PRIM_GET_DISPLAY_OPERATOR_NAME_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetDisplayOperatorNameCnf_struct {
    CiMmResultCode  				result; 	/**< Result code */
    CiMmOperatorDisplayType	type; /**< Which type of network name should be returned. See CiMmOperatorDisplayType_enum */
    CiMmOperatorDisplayName OperatorName; /**< The requested operator name to be displayed. See CiMmOperatorDisplayName_struct */
    CiMmDisplayCondition	DisplayCondition; /**< The display condition indicated by the SIM. see CiMmDisplayCondition_enum*/
} CiMmPrimGetDisplayOperatorNameCnf;

/* <INUSE> */
/**	 <paramref name="CI_MM_PRIM_ECALLREG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEcallRegReq_struct {
    CiBoolean   active;                  /**< TRUE - New requested implementaion is acrive; FALSE - Normal operation*/
}CiMmPrimEcallRegReq;

/* <INUSE> */
/**	 <paramref name="CI_MM_PRIM_ECALLREG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimEcallRegCnf_struct {
    CiMmResultCode    ResultCode;              /**< Result code  \sa CiMmResultCode */
}CiMmPrimEcallRegCnf;

/* <INUSE> */
/**	 <paramref name="CI_MM_PRIM_RPM_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimRpmInfoReq;

#define CIMM_MAX_PDP_BLOCK_INFO 4

//ICAT EXPORTED ENUM
typedef enum CiMmRpmPdpBlockReasonTag
{
	CI_MM_RPM_PDP_BLOCK_REASON_NONE,
	CI_MM_RPM_PDP_BLOCK_REASON_IGNORE,
	CI_MM_RPM_PDP_BLOCK_REASON_PERMANENT_REJECT,
	CI_MM_RPM_PDP_BLOCK_REASON_TEMP_REJECT,
	CI_MM_RPM_PDP_BLOCK_REASON_ACT_DEACT,
	CI_MM_RPM_PDP_BLOCK_REASONS
}CiMmRpmPdpBlockReason;

//ICAT EXPORTED STRUCT
typedef struct CiMMRpmPdpBlockInfoTag
{
	CiString  apn;
	UINT16    pdpBlockTime;
	CiMmRpmPdpBlockReason pdpBlockReason;
    /*Lilei, CQ00134598, 20220418, begin*/
    UINT8     F1;
    UINT8     F2;
    UINT8     F3;
    UINT8     F4;
    /*Lilei, CQ00134598, 20220418, end*/
}CiMMRpmPdpBlockInfo;

//ICAT EXPORTED STRUCT
typedef struct CiMmRpmParamsInfoTag
{
	UINT8	N1const;    /**< Amount of application resets allowed by RPM, this value will be constant either default or value from SIM */
	
	UINT8	N1;         /**< Amount of application resets allowed by RPM. 0x00 requirement is disabled, 0x01 to 0xFF number of resets per hour */
	UINT8	T1;         /**< Time to wait before PS is reset following a "Permanent" MM/GMM reject cause. 0x00 requirement is disabled, 0x01 to 0xFE in 6 minutes, 0xFF Time value to use T1_ext */
	UINT8	F1;         /**< Counter that decides how many times a PDP activation can be made when PDP activation is ignored by the NW. 0x00 requirement is  disabled, 0x01 to 0xFF the max attempts allowed */
	UINT8	F2;         /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a "Permanent" reject. 0x00 requirement is disabled, 0x01 to 0xFF the max attempts allowed */
	UINT8	F3;         /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a "Temporary" reject. 0x00 requirement is disabled, 0x01 to 0xFF the max attempts allowed */
	UINT8	F4;         /**< Counter that decides how many times a PDP activation/deactivation pair can be made. 0x00 disabled, 0x01 to 0xFF the max attempts allowed */

	UINT8	LR1;        /**< Every LR1 hours the CBR1 counter will be decremented by 1 (if it is 0 the requirement is disabled) */
	UINT8	LR2;        /**< Every LR2 hours the CR1 counter will be decremented by 1 (if it is 0 the requirement is disabled) */
	UINT8	LR3;        /**< Every LR3 hours the CPDP1-4 counters will be decremented by 1 (if it is 0 the requirement is disabled) */

	UINT8	CBR1;       /**< Counter that holds the number of application resets that were blocked by the RPM because of N1 limitation. 0x00 to 0xFF */
	UINT8	CR1;        /**< Counter that holds the number of times the PS was reset because of T1 expiration. 0x00 to 0xFF  */
	UINT8	CPDP1;      /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F1 limitation. 0x00 to 0xFF  */
	UINT8	CPDP2;      /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F2 limitation. 0x00 to 0xFF  */
	UINT8	CPDP3;      /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F3 limitation. 0x00 to 0xFF  */
	UINT8	CPDP4;      /**< Counter that holds the number of times a PDP activation req was rejected by RPM because of F4 limitation. 0x00 to 0xFF  */

	UINT8	Version; /**< Holds the current RPM version. 0x00 no version info,0x01 to 0xFF for Version 1~255 */

	CiBoolean 	rpmEnabledFileExists;     /**< TRUE - EF_RPM Enabled flag file exists on SIM, FALSE - EF_RPM Enabled flag file doesn't exist on SIM */
	CiBoolean 	rpmParamsExists;          /**< TRUE - EF_RPM Params file exists on SIM, FALSE - EF_RPM Params file doesn't exist on SIM */
	CiBoolean 	rpmOperLrCountersExists;  /**< TRUE - EF_RPM Operational Management Counters Leak Rate file exists on SIM, FALSE - EF_RPM Operational Management Counters Leak Rate file doesn't exist on SIM */
	CiBoolean 	rpmOperCountersExists;    /**< TRUE - EF_RPM Operational Management Counters file exists on SIM, FALSE - EF_RPM Operational Management Counters file doesn't exist on SIM */
	CiBoolean 	rpmVersionExists;         /**< TRUE - EF_RPM Version file exists on SIM, FALSE - EF_RPM Version file doesn't exist on SIM */
}CiMmRpmParamsInfo;

/* <INUSE> */
/**	 <paramref name="CI_MM_PRIM_RPM_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimRpmInfoCnf_struct {
    CiMmResultCode    result;              /**< Result code  \sa CiMmResultCode */
	CiBoolean att_SIM; /**< Is SIM AT&T */
	CiBoolean rpmSim;  /**< Is RPM SIM AT&T */
	CiBoolean RpmEnabled; /**< Is RPM enabled */
	
	CiMMRpmPdpBlockInfo pdpBlockInfo[CIMM_MAX_PDP_BLOCK_INFO];
	UINT16 resetBlockTime;
	
	CiMmRpmParamsInfo rpmData; /**< RPM parameters */
}CiMmPrimRpmInfoCnf;

/* <INUSE> */
/**	 <paramref name="CI_MM_PRIM_RPM_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimRpmInfoInd_struct {
	CiBoolean att_SIM; /**< Is SIM AT&T */
	CiBoolean rpmSim;  /**< Is RPM SIM AT&T */
	CiBoolean RpmEnabled; /**< Is RPM enabled */
	
	CiMMRpmPdpBlockInfo pdpBlockInfo[CIMM_MAX_PDP_BLOCK_INFO];
	UINT16 resetBlockTime;

	CiMmRpmParamsInfo rpmData; /**< RPM parameters */
}CiMmPrimRpmInfoInd;

//add by taow 20171124 CQ00108549 begin

//+ZSNT
//ICAT EXPORTED ENUM
typedef enum CIMmSELECTMODES_TAG{
    CI_MM_SELECT_AUTO  = 0,
 	CI_MM_SELECT_MANUAL,
    
    CI_MM_NUM_SELECT_MODES
} _CiMmSelectMode;

/** \remarks Common Data Section */
typedef UINT8 CiMmSelectMode;
//ICAT EXPORTED ENUM
typedef enum CIMMUSERNWMODES_TAG{
    CI_MM_USER_NW_GSM  = 0,		/**< GSM */
    CI_MM_USER_NW_UMTS ,    	/**< UMTS */    
    CI_MM_USER_NW_GSM_UMTS, 	/**< GSM_UMTS */    
    CI_MM_USER_NW_LTE,			/**< LTE */    
    CI_MM_USER_NW_GSM_LTE,		/**< GSM_LTE */
    CI_MM_USER_NW_UMTS_LTE,		/**< UMTS_LTE */    
    CI_MM_USER_NW_GSM_UMTS_LTE,	/**< GSM_UMTS_LTE */
     
    CI_MM_NUM_NW_MODES

} _CiMmUserNetworkMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network mode is used to define the RAT mode of the ME*/
/** \remarks Common Data Section */
typedef UINT8 CiMmUserNetworkMode;

/** <paramref name="CI_MM_PRIM_SET_NETWORK_SELECTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetNetworkSelectionReq_struct{
	CiMmUserNetworkMode		preferredMode;
    CiMmSelectMode      selectionMode;	
    CiMmUserNetworkMode    	networkMode;	
}CiMmPrimSetNetworkSelectionReq;

/** <paramref name="CI_MM_PRIM_SET_NETWORK_SELECTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetNetworkSelectionCnf_struct{
	CiMmResultCode          rc;        
}CiMmPrimSetNetworkSelectionCnf;

/**	 <paramref name="CI_MM_PRIM_GET_NETWORK_SELECTION_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimGetNetworkSelectionReq;

/** <paramref name="CI_MM_PRIM_GET_NETWORK_SELECTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNetworkSelectionCnf_struct{
	CiMmResultCode 		 rc;		
	CiMmUserNetworkMode	 preferredMode;
    CiMmSelectMode       selectionMode;	
    CiMmUserNetworkMode  networkMode;	
}CiMmPrimGetNetworkSelectionCnf;

//+ZCAINFO
/*add by taow CQ00120592 20200512 begin*/
//ICAT EXPORTED STRUCT
typedef struct CiMmCellMeas_struct
{
    UINT8             rsrp;
    UINT8             rsrq;
    INT16             rssi;
    INT8              sinr;
}
CiMmCellMeas;
/*add by taow CQ00120592 20200512 end*/

//ICAT EXPORTED STRUCT
typedef struct CiMmLteCaBandInfo_struct
{
	UINT8                   dlBandwidth;/**<0 - 1.4M, 1 - 3M, 2 - 5M, 3 - 10M, 4 - 15M, 5 - 20M */
	UINT16                  band;
    UINT32                  dlEuArfcn;   
    Boolean                 measValid;
    CiMmCellMeas            measResult;    
}
CiMmLteCaBandInfo;

//ICAT EXPORTED STRUCT
typedef struct CiMmLteRrcPcell_struct { 
	UINT16                  Pci;
	UINT32         			tac; 
	CiMmLteCaBandInfo  		BandInfo;         
  		
} CiMmLteRrcPcell;

//ICAT EXPORTED STRUCT
typedef struct CiMmLteRrcScell_struct { 
	UINT16        			Pci;
	UINT8     				ScellStatus;
	CiMmLteCaBandInfo  		BandInfo;     	
} CiMmLteRrcScell;

/**	 <paramref name="CI_MM_PRIM_GET_LTE_CA_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetLteCaInfoReq;

/** <paramref name="CI_MM_PRIM_GET_LTE_CA_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetLteCaInfoCnf_struct{
	CiMmResultCode 		 	rc;		
	CiMmLteRrcPcell			PcellInfo; 
	CiMmLteRrcScell			ScellInfo;
}CiMmPrimGetLteCaInfoCnf;


//ICAT EXPORTED STRUCT
typedef struct CiMmNetOpNameInfo_struct { 
   CiMmOperatorId    LongAlphaId;    /**<Long Alphanumeric Operator ID  */
   CiMmNetworkId  	 NetworkId;     		/**< Network ID  \sa CiMmNetworkId_struct */
} CiMmNetOpNameInfo;

//+ZDON
/**	 <paramref name="CI_MM_PRIM_GET_OPERATOR_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimGetOperatorInfoReq;

//ICAT EXPORTED ENUM
typedef enum CIMMROAMINGSTATUS_TAG{
    CI_MM_ROAMING_NONE  = 0,		
    CI_MM_ROAMING_ON ,    	   
    CI_MM_ROAMING_OFF,    
  
     
    CI_MM_NUM_ROAMING

} _CiMmRoamingStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Network mode is used to define the RAT mode of the ME*/
/** \remarks Common Data Section */
typedef UINT8 CiMmRoamingStatus;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_OPERATOR_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetOperatorInfoCnf_struct{
   	CiMmResultCode    	Result;				/**< Result code  */
   	CiMmNetOpNameInfo   RPlmn;			/**< Current registration mode  */
  	CiMmNetOpNameInfo   HPlmn;				/**< Current network/operator ID information */
  	CiMmRoamingStatus	RoamingStatus;
} CiMmPrimGetOperatorInfoCnf;
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_OPERATOR_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimOperatorStatusInd_struct{
   	CiMmNetOpNameInfo   RPlmn;			/**< Current registration mode  */
  	CiMmNetOpNameInfo   HPlmn;				/**< Current network/operator ID information */
  	CiMmRoamingStatus	RoamingStatus;
} CiMmPrimOperatorStatusInd;

	//add by taow 20171124 CQ00108549 end
/*add new cmd by taow 20180730 CQ00111537 begin*/
//+ZPAS
/**	 <paramref name="CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiMmPrimGetNetworkRegistrationStatusInfoReq;
    
/** \brief Registration result information: registration status indicators  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMM_NETWORKREGSTATUS {
    CIMM_NETWORK_REGSTATUS_NO_SERVICE = 0,
    CIMM_NETWORK_REGSTATUS_CS_ONLY,   /*2G cs or 3G cs */
    CIMM_NETWORK_REGSTATUS_PS_ONLY,			/* */
    CIMM_NETWORK_REGSTATUS_CS_PS,	/*combined attach */
    CIMM_NETWORK_REGSTATUS_CAMPED,		/*EMERGENCY */


    /* This one must always be last in the list! */
    CIMM_NUM_NETWORK_REGSTATUS			/**< Number of status values defined */
} _CiMmNetworkRegStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Registration result information: Registration status indicators
 *  \sa CIMM_NETWORKREGSTATUS
 * \remarks Common Data Section */
typedef UINT8 CiMmNetworkRegStatus;    
/** <paramref name="CI_MM_PRIM_GET_NETWORK_REGISTRATION_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetNetworkRegistrationStatusInfoCnf_struct{
    CiMmResultCode              result;         /**< Result code \sa CiMmResultCode */
    CiMmNetworkRegStatus  		RegStatus;		/**< Registration status  \sa CiMmRegStatus */
    CiMmAccTechMode             AcT;            /**< Network access technology (GSM, UTRAN, LTE etc.)  \sa CiMmAccTechMode */
}CiMmPrimGetNetworkRegistrationStatusInfoCnf;
/*add new cmd by taow 20180730 CQ00111537 end*/

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_FIRST_SEARCHED_NETWORK_OPERATOR_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimFirstSearchedNetworkOperatorInd_struct{
   CiBoolean        Present;
   CiMmNetworkId    NetworkId;  /**< Network ID information	\sa CiMmNetworkId */
   CiMmAccTechMode  AccTchMode;  /**< Network access technology (GSM, UTRAN, etc.)  \sa CiMmAccTechMode */
} CiMmPrimFirstSearchedNetworkOperatorInd;
 /*add CQ00114574 by taow 20190419 begin*/
#define MAX_PLMNS_ON_PER_RAT    20

/** <paramref name="CI_MM_PRIM_NETWORK_SEARCH_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNetworkSearchInd_struct {
    CiMmAccTechMode     Act;           /**< Access radio technology */
    UINT8				numPlmns;			/**< Number of shared PLMNs in that cell */
    CiMmNetworkId		plmns[MAX_PLMNS_ON_PER_RAT];
    INT32               rssiOrRscpOrRsrp[MAX_PLMNS_ON_PER_RAT];/**< 2G:RSSI;3G:RSCP;4G:RSRP*/ 
    INT32 		        rsrqOrEcno[MAX_PLMNS_ON_PER_RAT];/**< 2G: NA ;3G:rsrqOrEcno means UMTS ecno;4G: rsrqOrEcno means LTE rsrq*/ 
    UINT32              freq[MAX_PLMNS_ON_PER_RAT];	    

} CiMmPrimNetworkSearchInd;

/*add CQ00114574 by taow 20190419 end*/

/*Lilei, CQ00114910, 20190530, begin*/
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_CELL_LOCK_INFO_REQ"> */
typedef CiEmptyPrim CiMmPrimGetCellLockInfoReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_CELL_LOCK_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetCellLockInfoCnf_struct{
    CiMmResultCode      result;         /**< Result code \sa CiMmResultCode */
    CiMmCellLockMode    mode;           /**< Cell lock mode \sa CiMmCellLockMode */
    CiMmCellLockActMode act;            /**< Network mode \sa CiMmNetworkMode */
    UINT8               bandValue;
    UINT32              freq;           /**< Absolute radio frequency channel number; GSM number 0-1023, TD number 10054-10121 and 9404-9596 */
    INT16               cellId;         /**< Cell parameter ID This parameter if valid for 3G cells only 0-127, and for TD LTE cells only 0-503  */
} CiMmPrimGetCellLockInfoCnf;
/*Lilei, CQ00114910, 20190530, end*/

/*add by taow CQ00125209 20201020 begin*/
#define CI_MM_MAX_OOS_RECOVERY_PHASES 3

//ICAT EXPORTED ENUM
/** \remarks Common Data Section */
typedef enum CIMM_OOS_MODE
{
    CIMM_OOS_MODE_DISABLE = 0,
    CIMM_OOS_MODE_ENABLE,


    CIMM_NUM_OOS_MODES,
}_CiMmOosMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief
 * \sa CIMM_OOS_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiMmOosMode;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_OOS_PHASE_PERIOD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetOosPhasePeriodReq_struct{
    CiMmOosMode   mode;  
    UINT32        oosPhasePeriod[CI_MM_MAX_OOS_RECOVERY_PHASES];          

} CiMmPrimSetOosPhasePeriodReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_OOS_PHASE_PERIOD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetOosPhasePeriodCnf_struct{
    CiMmResultCode      result;         /**< Result code \sa CiMmResultCode */         

} CiMmPrimSetOosPhasePeriodCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_OOS_PHASE_PERIOD_REQ"> */
typedef CiEmptyPrim CiMmPrimGetOosPhasePeriodReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_OOS_PHASE_PERIOD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetOosPhasePeriodCnf_struct{
    CiMmResultCode      result; 
    CiMmOosMode         mode;
    UINT32              oosPhasePeriod[CI_MM_MAX_OOS_RECOVERY_PHASES];            

} CiMmPrimGetOosPhasePeriodCnf;



/*add by taow CQ00125209 20201020 end*/



/*add by CQ00130201 taow 20210513 begin*/
#define MAX_SCAN_RESULT_ON_PER_PLMNS    20
//ICAT EXPORTED ENUM
typedef enum CIMMGSMBNADSCAN_TAG{
    CI_MM_SCAN_GSM_NONE = 0, 
    CI_MM_SCAN_GSM900 = 0x01,  	        /**< P GSM 900 band */
    CI_MM_SCAN_GSM1800= 0x02,           /**< DCS 1800 band */
    CI_MM_SCAN_GSM850 = 0x04,           /**< GSM 850 band */    
    CI_MM_SCAN_GSM1900 =0x08,           /**<  PCS 1900 band */


    CI_MM_NUM_GSM_BAND
} _CiMmGSMBandScan;
#define UMTS_BAND_SCAN_MASK    0x000000BB

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetBandsScanConfigReq_struct{
    CiMmUserNetworkMode   networkMode; 
    CiBitRange            gsmBand;
    /**< A hexadecimal value that specifies the GSM  frequency band. If it is set to 0, it means not to change GSM  frequency band. Range: 0-FFFFFFFF. 
            (e.g.: 0x 00000003 = 00000001(GSM900) + 00000002(GSM1800)).
            00000000 No change
            00000001 GSM900  -->PGSM_BAND_BIT  (B8)
            00000002 GSM1800   (B3)
            00000004 GSM850     (B5)
            00000008 GSM1900   (B2)

            FFFFFFFF Any frequency band*/
    CiBitRange            umtsBand;
          /**< A hexadecimal value that specifies the WCDMA frequency band. If it is set to 0, it means not to change WCDMA frequency band. Range: 0-FFFFFFFF. 
                  (e.g.: 0x 00000013 = 00000001(WCDMA 2100) + 00000002(WCDMA 1900) + 00000010(WCDMA 850)).
                  00000001 band 1 (WCDMA 2100)
                  00000002 band 2 (WCDMA 1900)
                  00000004 band 3 (...)
                  00000008 band 4 (WCDMA 1700)
                  00000010 band 5 (WCDMA 850)
                  00000020 band 6 (WCDMA 800)
                  00000040 band 7 (...)
                  00000080 band 8 (WCDMA 900)
                  
                  FFFFFFFF Any frequency band*/

    CiBitRange          eutranBandL;/**< Bit mask indicating the required E-UTRAN bands Low part (bands 1 - 32).*/
    CiBitRange          eutranBandH;/**< Bit mask indicating the required E-UTRAN bands High part (bands 33 - 43).*/    
    CiBitRange          eutranBandExt;/**< Bit mask indicating the required E-UTRAN bands Extended part (bands 65 - 69). */         
    /**<  A hexadecimal value that specifies the LTE frequency band. If it is set to 0 or 0x40000000, it means not to change LTE frequency band. Range: 0-7FFFFDF3FFF
            (e.g.: 0x15=0x1(LTE B1) + 0x4(LTE B3) + 0x10(LTE B5)).
            0x1 (CM_BAND_PREF_LTE_EUTRAN_BAND1) LTE B1
            0x4 (CM_BAND_PREF_LTE_EUTRAN_BAND3) LTE B3
            0x10 (CM_BAND_PREF_LTE_EUTRAN_BAND5) LTE B5
            0x40 (CM_BAND_PREF_LTE_EUTRAN_BAND7) LTE B7
            0x80 (CM_BAND_PREF_LTE_EUTRAN_BAND8) LTE B8
            0x80000(CM_BAND_PREF_LTE_EUTRAN_BAND20) LTE B20
            
            (eutranBandL 0xFFFFFFFF && eutranBandH 0xFFFFFFFF &&  eutranBandExt 0xFFFFFFFF
            (CM_BAND_PREF_ANY) Any frequency band)*/ 

} CiMmPrimSetBandsScanConfigReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_BANDS_SCAN_CONFIG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetBandsScanConfigCnf_struct{
    CiMmResultCode      result;         /**< Result code \sa CiMmResultCode */         

} CiMmPrimSetBandsScanConfigCnf;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_REQ"> */
typedef CiEmptyPrim CiMmPrimGetBandsScanConfigReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_BANDS_SCAN_CONFIG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetBandsScanConfigCnf_struct{
    CiMmResultCode        result; 
    CiMmUserNetworkMode   networkMode; 
    CiBitRange            gsmBand;
    CiBitRange            umtsBand;

    CiBitRange          eutranBandL;/**< Bit mask indicating the required E-UTRAN bands Low part (bands 1 - 32).*/
    CiBitRange          eutranBandH;/**< Bit mask indicating the required E-UTRAN bands High part (bands 33 - 43).*/    
    CiBitRange          eutranBandExt;/**< Bit mask indicating the required E-UTRAN bands Extended part (bands 65 - 69). */ 
              

} CiMmPrimGetBandsScanConfigCnf;


//ICAT EXPORTED STRUCT
typedef struct CiMmBandsScanResultTag /*  Used to report frequencies of each PLMN*/
{
    CiMmAccTechMode     act;           /**< Access radio technology */
    UINT32              band;     /**< lte/umts/gsm  band*/
    UINT32              freq; 
    INT32               rscpOrGsmRssi; /**< 2G:RSSI;3G:RSCP;4G:RSRP*/  
    INT32               rsrqOrEcno;  /**< 2G: NA ;3G:rsrqOrEcno means UMTS ecno;4G: rsrqOrEcno means LTE rsrq*/ 

    UINT16              pciOrpscOrbsic;  /**< 2G:bsic 3G:psc,4G:pci*/
    UINT16              tacOrLac; /**<lte/gsm/umts use*/
    UINT32              cellId; /**<gsm/umts/LTE use*/
    INT16               rxlev;    /**<  only gsm use */
    INT16               c1; /**< only gsm use*/
    INT16               rssi;/**< use in LTE, umts */
  
    CiBoolean           gprsSupported; /**<only gsm use*/
    CiBoolean           cellBarred; /**< lte/gsm/umts use*/
	/*modify by taow CQ00143894 20230518 begin*/
	UINT8      			dlBandwidth;/**< 0: 1.4 MHZ, 1: 3MHZ, 2: 5MHZ, 4: 10MHZ, 5: 15MHZ, 6: 20MHZ.  */
	UINT8      			reserved0; 
    UINT16      		reserved1;
    //UINT32      		reserved1; 
    /*modify by taow CQ00143894 20230518 begin*/
    UINT32      		reserved2; 
    UINT32      		reserved3; 
    UINT32      		reserved4; 
    UINT32      		reserved5; 
    UINT32      		reserved6; 
    
    
}CiMmBandsScanResult;
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_BANDS_SCAN_REQ"> */
typedef CiEmptyPrim CiMmPrimGetBandsScanReq;



/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_BANDS_SCAN_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetBandsScanCnf_struct{   
    CiMmResultCode          result; 
}CiMmPrimGetBandsScanCnf;
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_BANDS_SCAN_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimGetBandsScanInd_struct{   

    CiMmOperatorId     	    longAlphaId;  	/**< Long alphanumeric operator ID  \sa CiMmOperatorId_struct   */
    CiMmOperatorId     	    shortAlphaId; 	/**< Short alphanumeric operator ID  \sa CiMmOperatorId */
    CiMmNetworkId      	    networkId;    	/**< Network ID information  \sa CiMmNetworkId */
    UINT32                  numScanResult;
    CiMmBandsScanResult     scanResult[MAX_SCAN_RESULT_ON_PER_PLMNS];

}CiMmPrimGetBandsScanInd;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_ABORT_BANDS_SCAN_REQ"> */
typedef CiEmptyPrim CiMmPrimAbortBandsScanReq;

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_ABORT_BANDS_SCAN_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimAbortBandsScanCnf_struct{
    CiMmResultCode        result; 
}CiMmPrimAbortBandsScanCnf;

/*add by CQ00130201 taow 20210513 end*/

/* <INUSE> */
/** <paramref name="CI_MM_PRIM_NW_ECALL_OVER_IMS_SUPPORT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimNwEcallOverImsSupportInd_struct{
	UINT8				eCall_IMS_supp;
}CiMmPrimNwEcallOverImsSupportInd;

/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */
/*20220225 with  CQ00135513 for IMSECALL  for IMSECALL begin*/
/** <paramref name="CI_MM_PRIM_IMSECALL_REG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimImsEcallRegReq_struct{	
    CiBoolean   active;                  /**< TRUE - New requested implementaion is acrive; FALSE - detach operation*/
}CiMmPrimImsEcallRegReq;

/** <paramref name="CI_MM_PRIM_IMSECALL_REG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimImsEcallRegCnf_struct{
	CiMmResultCode        result; 
}CiMmPrimImsEcallRegCnf;
/*20220225 with  CQ00135513 for IMSECALL  for IMSECALL end*/

/*Lilei, CQ00134598, 20220418, begin*/
/**<paramref name="CI_MM_PRIM_SET_RPM_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetRpmReq_struct{
    UINT8     option;            /**< Set options. 0: RPM enabled; 1: RPM params; 2: RPM LR */

    CiBoolean rpmEnabledPresent; /**< whether <rpmEnabled> is set or not */
    CiBoolean rpmEnabled;        /**< Is RPM enabled/disabled */

    /**< RPM params */
    CiBoolean N1constPresent;
    CiBoolean T1Present;
    CiBoolean F1Present;
    CiBoolean F2Present;
    CiBoolean F3Present;
    CiBoolean F4Present;
    UINT8     N1const;        /**< Amount of application resets allowed by RPM, this value will be constant either default or value from SIM */
    UINT8     T1;             /**< Time to wait before PS is reset following a "Permanent" MM/GMM reject cause. 0x00 requirement is disabled, 0x01 to 0xFE in 6 minutes, 0xFF Time value to use T1_ext */
    UINT8     F1;             /**< Counter that decides how many times a PDP activation can be made when PDP activation is ignored by the NW. 0x00 requirement is  disabled, 0x01 to 0xFF the max attempts allowed */
    UINT8     F2;             /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a "Permanent" reject. 0x00 requirement is disabled, 0x01 to 0xFF the max attempts allowed */
    UINT8     F3;             /**< Counter that decides how many times a PDP activation can be made when PDP activation is rejected by the NW with a "Temporary" reject. 0x00 requirement is disabled, 0x01 to 0xFF the max attempts allowed */
    UINT8     F4;             /**< Counter that decides how many times a PDP activation/deactivation pair can be made. 0x00 disabled, 0x01 to 0xFF the max attempts allowed */

    /**< RPM LR */
    CiBoolean LR1Present;
    CiBoolean LR2Present;
    CiBoolean LR3Present;
    UINT8     LR1;            /**< Every LR1 hours the CBR1 counter will be decremented by 1 (if it is 0 the requirement is disabled) */
    UINT8     LR2;            /**< Every LR2 hours the CR1 counter will be decremented by 1 (if it is 0 the requirement is disabled) */
    UINT8     LR3;            /**< Every LR3 hours the CPDP1-4 counters will be decremented by 1 (if it is 0 the requirement is disabled) */
}CiMmPrimSetRpmReq;

/**<paramref name="CI_MM_PRIM_SET_RPM_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetRpmCnf_struct {
    CiMmResultCode    result;       /**< Result code  \sa CiMmResultCode */
}CiMmPrimSetRpmCnf;
/*Lilei, CQ00134598, 20220418, end*/

/*Add API for process arfcn by CQ00113667  20190117 begin*/
#define CI_MAX_MODE_NUMER 3
#define  CI_MNC_UARFCN_LIST_SIZE  8


//ICAT EXPORTED STRUCT
typedef struct CiPlmnTag
{
    UINT16  mcc;    /**< 3-digit country code */
    UINT16  mnc;    /**< 3-digit network code */
	UINT16 accessTechnology;

}CiPlmn;

typedef struct CiRequestUarfcnListTag
{
	CiPlmn  rePlmn;

}CiRequestUarfcnList;

/*the  Arfcn for  ACT*/ 

//ICAT EXPORTED STRUCT
typedef struct CiArfcnListForCuTag
{
  UINT16     accessTechnology;
  UINT8          numArfcn;
  UINT32        arfcnList[CI_MNC_UARFCN_LIST_SIZE]; 
}
CiArfcnListForCu;

//ICAT EXPORTED STRUCT
typedef struct CiUarfcnInsrtFromCuTag
{
  CiPlmn  reqPlmn;
  CiArfcnListForCu  arfcnInsrtFromCu;
}CiUarfcnInsrtFromCu;

//ICAT EXPORTED STRUCT
typedef struct CiUarfcnListForCuTag
{
  CiPlmn  reqPlmn;
  CiArfcnListForCu  arfcnListForCu[CI_MAX_MODE_NUMER];
}CiUarfcnListForCu;



/*Add API for process arfcn by CQ00113667  20190117 end*/

/*CQ00137393 Add API for process modem related info, #54860, 20220617 Kevin code begin*/
//ICAT EXPORTED STRUCT
typedef struct CiModemInfoTag
{
	UINT8  cat; /**< 1, cat1; 4, cat4;*/
	UINT8  rel; /**<cat1, 9 or 13; cat4, 4;*/
	UINT8  antType; 
	UINT16 xo; /**<0, TCXO; 1, DCXO*/
	UINT8  resev[28];
}CiModemInfo;
/*CQ00137393 Add API for process modem related info, #54860, 20220617 Kevin code end*/

/*add for new feature to support VSIM with CQ00141543  20230208 BEGIN*/
/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SELECT_VSIM_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPrimSetSelectVsimReq_struct{
    UINT8   vsimEnable;  /* vsimEnable 0 :disable VSIM ;1: enable VSIM*/
	UINT8   resevered;
} CiMmPrimSetSelectVsimReq;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_SET_SELECT_VSIM_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPriSetSelectVsimCnf_struct{
    CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
} CiMmPrimSetSelectVsimCnf;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SELECT_VSIM_REQ"> */
typedef CiEmptyPrim CiMmPrimGetSelectVsimReq;


/* <INUSE> */
/** <paramref name="CI_MM_PRIM_GET_SELECT_VSIM_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMmPriGetSelectVsimCnf_struct{
    CiMmResultCode  	result;			/**< Result code \sa CiMmResultCode */
    UINT8   vsimEnable;  /* vsimEnable 0 :disable VSIM ;1: enable VSIM*/
	UINT8   resevered;
} CiMmPrimGetSelectVsimCnf;


 /*add for new feature to support VSIM with CQ00141543	20230208 END*/

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_mm_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_MM_NUM_CUST_PRIM is set to 0 in the "ci_mm_cust.h" file.
 */
#include "ci_mm_cust.h"

#define CI_MM_NUM_PRIM ( CI_MM_NUM_COMMON_PRIM + CI_MM_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_MM_NUM_PRIM CI_MM_NUM_COMMON_PRIM

#endif /* CI_CUSTOM_EXTENSION */


/***************************Start of CI Interface Definitions of Old CI Versions***********************************************/

/******************************************************************************
 * All old CI interface definations should be backed up here, re-defined
 * with the suffix of CI version number
******************************************************************************/

/***************************End of CI Interface Definitions of Old CI Versions***********************************************/

#ifdef __cplusplus
  }
#endif //__cplusplus





#endif /* _CI_MM_H_ */


/*                      end of ci_mm.h
--------------------------------------------------------------------------- */

