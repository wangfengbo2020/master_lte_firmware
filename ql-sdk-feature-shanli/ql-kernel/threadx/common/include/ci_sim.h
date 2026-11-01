/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_sim.h
Description : Data types file for the SIM Service Group
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

#if !defined(_CI_SIM_H_)
#define _CI_SIM_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_api_types.h"
#include <ci_cc.h>
/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_SIM_VER_MAJOR 3
//#define CI_SIM_VER_MINOR 1
//#define CI_SIM_VER_MAJOR 3
//#define CI_SIM_VER_MINOR 0
#define CI_SIM_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version

/* Add by jungle for CQ00057999 on 2014-04-02 Begin */
#define UICC_MAX_AID_COUNT               8
#define UICC_AID_MAX_SIZE                16
/* Add by jungle for CQ00057999 on 2014-04-02 End */

/* ----------------------------------------------------------------------------- */

/* CI_SIM Primitive ID definitions */

/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_PRIM
{
  CI_SIM_PRIM_EXECCMD_REQ = 1,						/**< \brief Requests to execute a SIM command \details   */
  CI_SIM_PRIM_EXECCMD_CNF,							/**< \brief Confirms the request to execute a SIM command \details   */
  CI_SIM_PRIM_DEVICE_IND,								/**< \brief Indicates that the current SIM status changed \details   */
  CI_SIM_PRIM_PERSONALIZEME_REQ,						/**< \brief Requests that ME personalization be activated, deactivated, disabled, or queried \details   */
  CI_SIM_PRIM_PERSONALIZEME_CNF,						/**< \brief Confirms the request to activate, deactivate, disable, or query ME personalization \details   */
  CI_SIM_PRIM_OPERCHV_REQ,							/**< \brief Requests that CHVs be verified, enabled, disabled, changed, unblocked, or queried \details   */
  CI_SIM_PRIM_OPERCHV_CNF,							/**< \brief Confirms the request to verify, enable, disable, change, unblock, or query CHVs \details   */
  CI_SIM_PRIM_DOWNLOADPROFILE_REQ,					/**< \brief Requests a download of the profile that shows ME capabilities relevant to SIM Application Toolkit functionality \details The functionality of this primitive is equivalent to using the SIM command TERMINAL PROFILE in the CI_SIM_PRIM_EXECCMD_REQ primitive.
  *  This primitive saves upper layer effort to build a header for the Terminal Profile SIM command.
  *  If the pProfile pointer is NULL for this request, the communications interface assumes that the application layer does not support
  *  SIM Application Toolkit operations.  */
  CI_SIM_PRIM_DOWNLOADPROFILE_CNF,					/**< \brief Confirms the request to download the profile that shows ME capabilities relevant to SIM Application Toolkit functionality  \details   */
  CI_SIM_PRIM_ENDATSESSION_IND,						/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SIM_PRIM_PROACTIVE_CMD_IND,						/**< \brief Indicates a SIMAT proactive command  \details This primitive forwards the SIMAT proactive command with its original syntax. The primitive CI_SIM_PRIM_ENABLE_SIMAT_INDS_REQ enables and disables proactive command indication.  */
  CI_SIM_PRIM_PROACTIVE_CMD_RSP,						/**< \brief Responds to the SIMAT proactive command  \details The primitive forwards a SIMAT proactive command response from the entity, such as DISPLAY or TERMINAL, that received the proactive command.  */
  CI_SIM_PRIM_ENVELOPE_CMD_REQ,						/**< \brief Requests that an ENVELOPE command be executed \details   */
  CI_SIM_PRIM_ENVELOPE_CMD_CNF,						/**< \brief Confirms the request to execute an ENVELOPE command  \details   */
  CI_SIM_PRIM_GET_SUBSCRIBER_ID_REQ,					/**< \brief Requests the subscriber ID \details   */
  CI_SIM_PRIM_GET_SUBSCRIBER_ID_CNF,					/**< \brief Confirms the request for the subscriber ID  \details   */
  CI_SIM_PRIM_GET_PIN_STATE_REQ,						/**< \brief Requests the current PIN state \details   */
  CI_SIM_PRIM_GET_PIN_STATE_CNF,						/**< \brief Confirms the request for the current PIN state \details   */
  CI_SIM_PRIM_GET_TERMINALPROFILE_REQ,				/**< \brief Requests the SIMAT terminal profile  \details   */
  CI_SIM_PRIM_GET_TERMINALPROFILE_CNF,				/**< \brief Confirms the request and returns the SIMAT terminal profile \details   */
  CI_SIM_PRIM_ENABLE_SIMAT_INDS_REQ,					/**< \brief Requests that SIMAT related indications, such as the proactive SIM command indication and the SIMAT session ended indication, be enabled or disabled  \details   */
  CI_SIM_PRIM_ENABLE_SIMAT_INDS_CNF,					/**< \brief Confirms the request to enable or disable SIMAT related indications  \details   */
  CI_SIM_PRIM_LOCK_FACILITY_REQ,						/**< \brief Requests to lock, unlock, or query SIM-related ME  \details   */
  CI_SIM_PRIM_LOCK_FACILITY_CNF,						/**< \brief Confirms a request to lock, unlock, or query SIM-related ME  \details   */
  CI_SIM_PRIM_GET_FACILITY_CAP_REQ,					/**< \brief Requests the bitmask of supported SIM-related facility codes \details   */
  CI_SIM_PRIM_GET_FACILITY_CAP_CNF,					/**< \brief Confirms the request for the bitmask of supported SIM-related facility codes \details   */
  CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_REQ,				/**< \brief Requests SIM Application Toolkit (SIMAT) notification capability information. \details   */
  CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_CNF,				/**< \brief Confirms the request for SIM Application Toolkit (SIMAT) notification capability information \details   */
  CI_SIM_PRIM_GET_CALL_SETUP_ACK_IND,				/**< \brief Indicates that the SIM Application Toolkit (SIMAT) has initiated an outgoing CALL SETUP operation, and requests confirmation/acknowledgment from the mobile user \details The application returns the required acknowledgment in a CI_SIM_PRIM_GET_CALL_SETUP_ACK_RSP response.  */
  CI_SIM_PRIM_GET_CALL_SETUP_ACK_RSP,				/**< \brief Responds with an acknowledgment from the mobile user for an outgoing CALL SETUP indication  \details The mobile user may accept (allow) or reject (disallow) the SIMAT initiated CALL SETUP operation.
*     If the user allows the CALL SETUP, it proceeds. If the user disallows the CALL SETUP, it is aborted.
*     If the CALL SETUP is allowed to proceed, the MO call progression is managed by the normal call control procedures. See the
*     CI CC Service Group API definition for more information.  */

  /* service provider name */
  CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_REQ,		/**< \brief Requests the service provider name, as stored on SIM or USIM \details The PIN status is not required to read this information.  */
  CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_CNF,		/**< \brief Confirms the request to get the service provider name, as stored on SIM or USIM \details The service provider name is coded as 7-bit GSM characters, with the most-significant bit of each character set to zero.
  *  The service provider name pointer is NULL if the result code indicates an error.  */

  /* Message Waiting Information */
  CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_REQ,		/**< \brief Requests to get message waiting information stored on SIM or USIM \details The PIN status is required to read this information.  */
  CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_CNF,			/**< \brief Confirms the request to get message waiting information stored on SIM or USIM \details If the result code indicates an error, the message waiting status information is not useful.
  *  There is a difference between the message categories defined for 2G and 3G SIM storage. This is rationalized by the CCI implementation.  */
  CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_REQ,			/**< \brief Requests to set message waiting information on SIM or USIM  \details Requires PIN status to write this information. There is a difference between the message categories defined for 2G and 3G SIM storage. This is rationalized by the CCI implementation.  */
  CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_CNF,			/**< \brief Confirms a request to set the message waiting information on SIM or USIM \details   */

  /* SIM Service Table */
  CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_REQ,				/**< \brief Requests to get the SIM Service Table from SIM or USIM  \details The PIN status is required to read this information. If CPHS features are not supported by the handset, this information is unavailable.  */
  CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_CNF,				/**< \brief Confirms the request to get the SIM Service Table from SIM or USIM \details If CPHS features are not supported by the handset, this information is unavailable.  */

  /* CPHS Customer Service Profile */
  CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_REQ,	/**< \brief Requests to get the CPHS customer service profile from SIM or USIM \details The PIN status is required to read this information. If CPHS features are not supported by the handset, this information is unavailable. */
  CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_CNF,	/**< \brief Confirms the request and returns the CPHS customer service profile from SIM or USIM. \details If CPHS features are not supported by the handset, this information is unavailable.  */

  /* Display Alpha and Icon Identifiers */
  CI_SIM_PRIM_SIMAT_DISPLAY_INFO_IND,					/**< \brief Indicates to the application that text and optionally an icon should be displayed.
														 *  The text to be displayed results from a SAT transaction such as SS, SMS, USSD, SS, or send DTMF. \details   */

  /* Default Language */
  CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_REQ,			/**< \brief Requests the default language stored on the SIM/USIM card \details   */
  CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_CNF,				/**< \brief Confirms the request to get the default language stored on the SIM/USIM card and returns the first entry in the EF_LP file \details Extract from ETSI TS 102.221: "the language code is a pair of alphanumeric characters, as defined in ISO 639 [30].
  *  Each alphanumeric character shall be coded on one byte using the SMS default 7-bit coded alphabet as defined in TS 23.038
  *  ("Man-machine Interface (MMI) of the User Equipment", revision 3.4.0, Doc Number 3GPP TS 22.030)
  *  with bit 8 set to 0.". 'FF FF' means undefined default language.  */

  /* Generic SIM commands */
  CI_SIM_PRIM_GENERIC_CMD_REQ,						/**< \brief Requests to send a generic command to the SIM/USIM card
													 * \details The request reflects the structure of a SIM application protocol data unit (APDU),
													 * as defined in ETSI 102.221. The 'class of instruction' element is not controlled by the user, comm. use class 0x0 or 0xa depending on the command.
													 * Note that updating a file using this command only updates the file on the SIM; it does not trigger a REFRESH of the ME memory. */
  CI_SIM_PRIM_GENERIC_CMD_CNF,						/**< \brief Confirms a request to send a generic command to the SIM or USIM  \details  */

  /* Indication of card type, status and PIN state */
  CI_SIM_PRIM_CARD_IND,								/**< \brief Indicates that the current SIM/USIM status changed \details This indication is sent each time CI_SIM_PRIM_DEVICE_IND is sent.  */

  CI_SIM_PRIM_IS_EMERGENCY_NUMBER_REQ,				/**< \brief Requests to determine if the specified dial number is an emergency call code \details   */
  CI_SIM_PRIM_IS_EMERGENCY_NUMBER_CNF,				/**< \brief Confirms the request to determine if the specified number is an emergency call code \details If a SIM card is present, the EF_ECC SIM card file is searched for the specified number. If a SIM card is not present, a default table of possible emergency call codes is searched for the specified number, as per TS 22.101. */

  CI_SIM_PRIM_SIM_OWNED_IND,							/**< \brief Indicates whether the SIM is owned
														 * \details This indication is sent each time a SIM-OK notification is received
 * from the protocol stack and indicates that the SIM card can be accessed. SIM owned is TRUE if the IMSI did not change
 * since the last SIM-OK notification.  */
  CI_SIM_PRIM_SIM_CHANGED_IND,						/**< \brief Indicates whether the IMSI on the current SIM has changed
													 * \details  This indication is sent each time a SIM-OK notification is received
 * from the protocol stack. */
  CI_SIM_PRIM_DEVICE_STATUS_REQ,						/**< \brief Requests SIM status \details   */
  CI_SIM_PRIM_DEVICE_STATUS_CNF,						/**< \brief Confirms the request for the current SIM status \details   */
  CI_SIM_PRIM_READ_MEP_CODES_REQ,			/**< \brief   Requests the MEP codes for a specified category  \details This operation does not require a password.*/
  CI_SIM_PRIM_READ_MEP_CODES_CNF,			/**< \brief   Confirms the request and returns the MEP codes for the specified category \details */
  CI_SIM_PRIM_UDP_LOCK_REQ, 					/**< \brief   Requests an activate, deactivate, or query UDP lock  \details  An operation can be done on only one category at a time. A password is required for an unlock operation. */
  CI_SIM_PRIM_UDP_LOCK_CNF, 					/**< \brief   Confirms the UDP lock request \details */
  CI_SIM_PRIM_UDP_CHANGE_PASSWORD_REQ,  	/**< \brief   Requests to set a new password for a UDP lock \details */
  CI_SIM_PRIM_UDP_CHANGE_PASSWORD_CNF, 	/**< \brief   Confirms the request to set a new password for a UDP lock \details */
  CI_SIM_PRIM_UDP_ASL_REQ,					/**< \brief  Requests to manipulate the UDP authorized SIM list \details */
  CI_SIM_PRIM_UDP_ASL_CNF,					/**< \brief  Confirms the request to manipulate the UDP authorized SIM list  \details */
/* Michal Bukai - Virtual SIM support - START */
   CI_SIM_PRIM_SET_VSIM_REQ,                /**< \brief  Requests to enable virtual SIM
											 * \details Virtual SIM can be enabled if no SIM is inserted.
											 * An error is sent if the user tried to enable virtual SIM while a SIM is inserted.
											 * The application needs to reset the communication subsystem after receiving a confirmation. */
   CI_SIM_PRIM_SET_VSIM_CNF,                 /**< \brief Confirms setting virtual SIM
											  * \details Virtual SIM can be enabled if no SIM is inserted.
											 * An error is sent if the user tried to enable virtual SIM while a SIM is inserted.
											 * The application needs to reset the communication subsystem after receiving a confirmation. */
   CI_SIM_PRIM_GET_VSIM_REQ,                 /**< \brief Requests the current setting of the virtual SIM (enabled / disabled) \details*/
   CI_SIM_PRIM_GET_VSIM_CNF,                 /**< \brief Confirms the request and returns the current setting of the virtual SIM (enabled / disabled) \details*/
/* Michal Bukai - Virtual SIM support - END */
/*Michal Bukai - OTA support for AT&T - START*/
  CI_SIM_PRIM_CHECK_MMI_STATE_IND,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SIM_PRIM_CHECK_MMI_STATE_RSP,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
/*Michal Bukai - OTA support for AT&T - END*/
/*Michal Bukai - BT SAP support - START*/
  CI_SIM_PRIM_BTSAP_CONNECT_REQ,					/**< \brief Requests to start a BT SAP session \details */
  CI_SIM_PRIM_BTSAP_CONNECT_CNF,					/**< \brief Confirms the request to start a BT SAP session \details */
  CI_SIM_PRIM_BTSAP_DISCONNECT_REQ, 				/**< \brief Requests to disconnect from a BT SAP session \details */
  CI_SIM_PRIM_BTSAP_DISCONNECT_CNF, 				/**< \brief Confirms the request to disconnect from a BT SAP session \details */
  CI_SIM_PRIM_BTSAP_TRANSFER_APDU_REQ,				/**< \brief Requests to transfer APDU to the SIM/USIM \details */
  CI_SIM_PRIM_BTSAP_TRANSFER_APDU_CNF,				/**< \brief Confirms the request to transfer APDU to the SIM/USIM and may return a response APDU from the SIM/USIM \details */
  CI_SIM_PRIM_BTSAP_TRANSFER_ATR_REQ,				/**< \brief Requests to get Answer To Reset data from SIM/USIM \details */
  CI_SIM_PRIM_BTSAP_TRANSFER_ATR_CNF,				/**< \brief Confirms the request to get Answer To Reset data from SIM/USIM \details */
  CI_SIM_PRIM_BTSAP_SIM_CONTROL_REQ,				/**< \brief Requests to control SIM/USIM status, this command can be used to power off, power on or reset the SIM/USIM \details */
  CI_SIM_PRIM_BTSAP_SIM_CONTROL_CNF,				/**< \brief Confirms the SIM control request \details */
  CI_SIM_PRIM_BTSAP_STATUS_IND,						/**< \brief indicates a change in the availably of the subscription module during BT SAP connection \details */
  CI_SIM_PRIM_BTSAP_STATUS_REQ,						/**< \brief Requests the subscription module availability status during BT SAP connection \details */
  CI_SIM_PRIM_BTSAP_STATUS_CNF,						/**< \brief Confirms the request and returns the status of the subscription module during BT SAP connection \details */
  CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_REQ,		/**< \brief Requests to set transport protocol \details */
  CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_CNF,		/**< \brief Confirms the request to set transport protocol \details */
/*Michal Bukai - BT SAP support - END*/
/*Michal Bukai - Add IMSI to MEP code group - START*/
  CI_SIM_PRIM_MEP_ADD_IMSI_REQ,	/**< \brief  Requests to add the current IMSI to MEP SIM /USIM code group
								* \details This operation requires a password.
								* This operation requires that SIM/USIM personalization is deactivated.*/
  CI_SIM_PRIM_MEP_ADD_IMSI_CNF,	/**< \brief Confirms the request to add the current IMSI to MEP SIM /USIM code group. \details   */
/*Michal Bukai - Add IMSI to MEP code group - END*/
/*Michal Bukai - SIM Logic CH - NFC\ISIM support - START*/
  CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_REQ,		/**< \brief  Requests to open a logical channel that will be used to access the UICC application identified by DFname.  \details The UICC will open a new logical channel; select the application identified by the DFname, and return a session ID that will be used to identify the new channel.*/
  CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_CNF,		/**< \brief  Confirms the request to open a logical channel and returns the session ID.  \details */
  CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_REQ,	/**< \brief  Requests to close a logical channel.  \details */
  CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_CNF,	/**< \brief  Confirms the request to close a logical channel.  \details */
/*Michal Bukai - SIM Logic CH - NFC\ISIM support support - END*/
/*Michal Bukai - additional SIMAT primitives - START*/
  CI_SIM_PRIM_SIMAT_CC_STATUS_IND,					/**< \brief Indicates the SIM Application Toolkit (SIMAT) call control status response 
													* \details If call control service in SIMAT is activated, all dialled digit strings, supplementary service control strings and USSD strings are passed to the UICC before the call setup request, 
													* the supplementary service operation or the USSD operation is sent to the network.
													* The SIMAT has the ability to allow, bar or modify the request. 
													* In addition SIMAT has the ability to replace the request by another operation, for instance call request may be replaced by SS or USSD operation.
													*/
  CI_SIM_PRIM_SIMAT_SEND_CALL_SETUP_RSP_IND,		/**< \brief Indicates the response sent to SIM Application Toolkit (SIMAT) after call setup. \details */
  CI_SIM_PRIM_SIMAT_SEND_SS_USSD_RSP_IND, 			/**< \brief Indicates the response sent to SIM Application Toolkit (SIMAT) after SS or USSD operation. \details */
  CI_SIM_PRIM_SIMAT_SM_CONTROL_STATUS_IND, 			/**< \brief Indicates the SIM Application Toolkit (SIMAT) short message control status response. 
													\details If SM control service in SIMAT is activated, all MO short messages are passed to the UICC before the short message is sent to the network.
													* The SIMAT has the ability to allow, bar or modify the destination address.
													*/
  CI_SIM_PRIM_SIMAT_SEND_SM_RSP_IND,				/**< \brief Indicates the response sent to SIM Application Toolkit (SIMAT) after SM operation. \details */
/*Michal Bukai - additional SIMAT primitives - END*/

/*Michal Bukai - RSAP support - START*/
  CI_SIM_PRIM_RSAP_CONN_REQ_IND,		/**< \brief  Request to connect to a remote SIM received from the protocol stack \details */
  CI_SIM_PRIM_RSAP_CONN_REQ_RSP,		/**< \Response to protocol stack request to connect to a remote SIM \details */
  CI_SIM_PRIM_RSAP_STAT_REQ,			/**< \brief  Request received from a SAP conversion module to update the RSAP card status. 
										* \details This request is actually an indication from a remote SAP conversion module indicating a status change in the remote connection or card status */
  CI_SIM_PRIM_RSAP_STAT_CNF,			/**< \brief  Confirms that the update of the remote card status was received by the protocol stack \details */
  CI_SIM_PRIM_RSAP_DISCONN_REQ_IND,		/**< \brief  Request to disconnect from a remote SIM received from the protocol stack \details */
  CI_SIM_PRIM_RSAP_DISCONN_REQ_RSP,		/**< \Response to protocol stack request to disconnect from a remote SIM \details */
  CI_SIM_PRIM_RSAP_GET_ATR_IND,			/**< \brief Request to get ATR from a remote SIM received from the protocol stack \details */
  CI_SIM_PRIM_RSAP_GET_ATR_RSP,			/**< \brief Response from a remote SIM with the ATR APDU \details */
  CI_SIM_PRIM_RSAP_GET_STATUS_REQ_IND,	/**< \brief  Request from the protocol stack to get the RSAP connection status. 
										* \details The request is answered by CI_SIM_PRIM_RSAP_CONN_STAT_REQ */

  CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_IND,	/**< \brief Request from the protocol stack to change the transport protocol of the remote SIM \details */
  CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_RSP,	/**< \brief Response to a protocol stack request to change the transport protocol of the remote SIM.
										* \details If the requested transport protocol is supported by the remote SIM and by the SAP conversion module, 
										* the requested transport protocol is selected and the remote SIM is reset.	If the requested transport protocol is not supported, 
										* SIM status is changed to CARD_NOT_ACC. The request is followed by CI_SIM_PRIM_RSAP_CONN_STAT_REQ, which indicates the new remote SIM status.*/
  CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_IND,	/**< \brief  Request from the protocol stack to control the remote SIM status. 
										* \details This command can be used to power off, power on, or reset the remote SIM */
  CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_RSP,	/**< \brief  Response to a protocol stack request to control the remote SIM status. 
										* \details The response is followed by CI_SIM_PRIM_RSAP_CONN_STAT_REQ, which indicates the new status of the remote SIM.*/
  CI_SIM_PRIM_RSAP_SIM_SELECT_REQ,		/**< \brief Request to select the local or remote SIM \details */
  CI_SIM_PRIM_RSAP_SIM_SELECT_CNF,		/**< \brief Confirms the request to select the local or remote SIM \details */
  CI_SIM_PRIM_RSAP_STATUS_IND,			/**< \brief Indicates that the current SIM/USIM status changed during RSAP connection \details */
  CI_SIM_PRIM_RSAP_TRANSFER_APDU_IND,	/**< \brief Request from the protocol stack to transfer APDU to the remote SIM \details */
  CI_SIM_PRIM_RSAP_TRANSFER_APDU_RSP,	/**< \brief Request from the protocol stack to transfer APDU to the remote SIM. 
										* \details A response APDU is returned if the transfer of APDU is successful.*/
  /*Michal Bukai - RSAP support - END*/

  CI_SIM_PRIM_DEVICE_RSP, 				/**< \brief Response to CI_SIM_PRIM_DEVICE_RSP.
										* \details This response is confirms that the CI_SIM_PRIM_DEVICE_RSP has been received and handled. Specially the SIM clock stop level. This indicates the Comm that D2 can be enabled on SIM driver level.*/
//ICC ID feature
  CI_SIM_PRIM_ICCID_IND, 				/**< \brief Indicates the content of the EF-ICCID file. This indication is sent at init. The EF-ICCID can be accessed even if PIN is required.*/
  CI_SIM_PRIM_GET_ICCID_REQ, 			/**< \brief Request to get the content of the EF-ICCID file. Can be sent if ICC is ready.
										* \details Can be sent when the SIM state is CI_SIM_ST_READY or CI_SIM_ST_INSERTED.	Otherwise the request will fail.*/

  CI_SIM_PRIM_GET_ICCID_CNF,			/**< \brief Confirmation with the ICC id to the request to get the ICC Id.*/
//ICC ID feature
  CI_SIM_PRIM_EAP_AUTHENTICATION_REQ,	/**< \brief Requests to exchange EAP packets with the UICC. */
  CI_SIM_PRIM_EAP_AUTHENTICATION_CNF,	/**< \brief Confirms the EAP authentication request and returns the authentication response */

  CI_SIM_EAP_RETRIEVE_PARAMETERS_REQ, /**< \brief Requests to retrieve EAP parameters from the UICC. */
  CI_SIM_EAP_RETRIEVE_PARAMETERS_CNF, /**< \brief Confirms the request to retrieve EAP parameters and returns the contents of the
										* \elementary file corresponding to requested parameter.*/

  CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_REQ,/**< \brief Requests to get number of applications available on the UICC. */
  CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_CNF,/**< \brief Confirms the request to get number of applications available on the UICC. */

  CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_REQ, /**< \brief Requests to get list of applications available on the UICC. */
  CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_CNF, /**< \brief Confirms the request to get list of applications available on the UICC. */
  /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_SIM_PRIM_LAST_COMMON_PRIM' */
  /*2013.12.11, added by Xili for CQ00051618, begin*/
  CI_SIM_PRIM_ISIM_AID_IND,                         /**< \brief Indicates the content of the ISIM Aid. This indication is sent at init if it had one. */
  /*2013.12.11, added by Xili for CQ00051618, end*/

  /* Add by jungle for CQ00057999 on 2014-04-02 Begin */
  CI_SIM_PRIM_APP_PIN_REQ,
  CI_SIM_PRIM_APP_PIN_CNF,
  /* Add by jungle for CQ00057999 on 2014-04-02 End*/

  /*2014.05.08, added by Xili for CQ00060947, begin*/
  CI_SIM_PRIM_ADMIN_DATA_IND,  
  /*2014.05.08, added by Xili for CQ00060947, end*/

  /*2015.03.19, mod by Xili for adding ECC list indication, CQ00088196 begin*/
  CI_SIM_PRIM_ECC_LIST_IND,  
  /*2015.03.19, mod by Xili for adding ECC list indication, CQ00088196 end*/

  /* Mod by jungle for CQ00089692 on 2015-04-08 Begin */
  CI_SIM_PRIM_EXEC_LARGE_CMD_CNF,
  CI_SIM_PRIM_GENERIC_LARGE_CMD_CNF,
  /* Mod by jungle for CQ00089692 on 2015-04-08 End */

  /*CQ00113882, Cgliu, 2019-02-26, Begin*/
  CI_SIM_PRIM_UPDATE_COUNT_REQ,
  CI_SIM_PRIM_UPDATE_COUNT_CNF,
  /*CQ00113882, Cgliu, 2019-02-26, End  */   
  /*CQ00116569, Cgliu, 2019-10-15, Begin*/
  /*Add *SIMPOLL command...*/
  CI_SIM_PRIM_SET_POLL_REQ,              
  CI_SIM_PRIM_SET_POLL_CNF,                
  CI_SIM_PRIM_GET_POLL_REQ,
  CI_SIM_PRIM_GET_POLL_CNF,
  /*CQ00116569, Cgliu, 2019-10-15, End  */  
  
  /* END OF COMMON PRIMITIVES LIST */
  CI_SIM_PRIM_LAST_COMMON_PRIM

  /* The customer specific extension primitives are added starting from
  * CI_SIM_PRIM_firstCustPrim = CI_SIM_PRIM_LAST_COMMON_PRIM as the first identifier.
  * The actual primitive names and IDs are defined in the associated
  * 'ci_sim_cust_xxx.h' file.
  */

  /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiSimPrim;

/* specify the number of default common SIM primitives */
#define CI_SIM_NUM_COMMON_PRIM ( CI_SIM_PRIM_LAST_COMMON_PRIM - 1 )
#define CI_SIM_LARGE_APDU_SIZE   2050  /* Add by jungle for CQ00089692 on 2015-04-08 */
#define CI_SIM_MAX_CMD_DATA_SIZE 261
/**@}*/

#define EF_SMS        28476
#define EF_FDN        28475
#define EF_EXT2       28491/*Michal Bukai - Extension2 support - update FDN PB with long numbers */

#define READ_BINARY        176
#define READ_RECORD        178
#define GET_RESPONSE        192
#define UPDATE_BINARY        214
#define UPDATE_RECORD        220
#define _STATUS			242
#define RETRIEVE_DATA       203
#define SET_DATA        219
#define LAST_RECORD        25
#define FIRST_RECORD        25
#define INVALID_INDEX	-1
#define EMPTY		0xFF
#define CI_MEP_MAX_PASSWORD_LENGTH     32

/** \brief SIM command structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimCmdReq_Struct {
    UINT16  	len;    									/**< Length of SIM command [5-CI_SIM_MAX_CMD_DATA_SIZE] */
    UINT8   	data[CI_SIM_MAX_CMD_DATA_SIZE];		/**< SIM command data. The format is according to 3GPP TS 11.11, v8.6.0, 9. */
} CiSimCmdReq;

//ICAT EXPORTED STRUCT
typedef struct CiMepPassword_struct{
    UINT8  len;    /* length of the password, [CI_MIN_PASSWORD_LENGTH - CI_MAX_PASSWORD_LENGTH] */

    UINT8        data[CI_MEP_MAX_PASSWORD_LENGTH];

}CiMepPassword;


/** \brief Confirmation to SIM command structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimCmdRsp_Struct {
    UINT16  len;     									/**< Length of the SIM response, [2-CI_SIM_MAX_CMD_DATA_SIZE] */
    UINT8   data[CI_SIM_MAX_CMD_DATA_SIZE];		/**< SIM response. The format is according to 3GPP TS 11.11, v8.6.0, 9. */
} CiSimCmdRsp;

/* Add by jungle for CQ00089692 on 2015-04-08 Begin */
//ICAT EXPORTED STRUCT
typedef struct CiSimLargeCmdRsp_Struct {
    UINT16  len; 
    UINT8   data[CI_SIM_LARGE_APDU_SIZE]; 
} CiSimLargeCmdRsp;
/* Add by jungle for CQ00089692 on 2015-04-08 End */

/* Description of the SIM behavior from the CCI point of view; use of
 * CiSimStatus & CiSimPinState
 *
 * After the SIM card is inserted, the protocol stack needs to perform an
 * initialization phase to obtain and validate all the required
 * information about the SIM card.
 * If PIN1 is enabled, then the protocol stack would need to perform PIN
 * validation before the initialization; the PIN must be obtained from the
 * application, so the protocol stack sends a 'PIN required' notification and
 * waits for the response.
 * If PIN1 is not required then the initialization is started immediately.
 * SIM can be accessed only after the successful completion of the initialization phase;
 * (appropriate notification (ex: SIM OK) is sent to the upper layers.
 * At any time, an indication of SIM error would mean that SIM is invalid and
 * SIM related functionality cannot be used; exception is the error indicating
 * that SIM was rejected by the network, in which case access to the phone book
 * should still be possible.
 * CCI sends the' CiSimPrimDeviceInd/CiSimPrimCardInd' notification each time a change
 * occurs in the SIM status as well as the PIN state.
 * Based on the above behavior design, the following diagram shows the SIM status & PIN
 * state transitions at the CCI level:
 *
 * 1)	at startup
 *
 *    status = not ready
 *    pinState = removed
 *
 * 2)	CCI received 'SIM card inserted' indication from protocol stack; CCI sends:
 *
 *    status = inserted
 *    pinState = waitInit
 *
 * 3)	CCI received 'PIN required' indication from protocol stack; CCI sends:
 *
 *    status = inserted
 *    pinState = pin1Required/unblockPin1Required/others
 *
 * 4)	APP sends the PIN to CCI; CCI sends:
 *
 *    status = inserted
 *    pinState = waitInit
 *
 * 5)	CCI received 'SIM is OK' (initialization completed & SIM ready to be accessed)
 *    indication from protocol stack; CCI sends:
 *
 *    status = ready
 *    pinState = ready
 *
 * 6)	in the ready state, if CCI receives 'SIM rejected by the network' indication from
 *    protocol stack; CCI sends:
 *
 *    status = ready
 *    pinState = rejectedByNetwork
 *
 * 7)	at any other time, if CCI receives 'SIM is NOT OK' indication from protocol stack; CCI sends:
 *
 *    status = not ready
 *    pinState = initError, mepError, removed, etc.
 *
 */

/** \brief SIM status values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMSTATUS_TAG {
    CI_SIM_ST_READY = 0,      	/**< SIM is initialized/validated and can be accessed. */
    CI_SIM_ST_NOT_READY,      /**< SIM is not inserted or has not been successfully initialized/validated. */

    CI_SIM_ST_INSERTED,       	/**< SIM is inserted and is being initialized/validated. */
    CI_SIM_ST_ERROR,            /**< SIM is inserted, but frame error happens */

    CI_SIM_ST_SIM_PRESENT,     /**< SIM1/2 is inserted, specially only for SIM2 detect first */
    CI_SIM_ST_SIM_ABSENT,      /**< SIM1/2 is not inserted, specially only for SIM2 detect first */

    CI_SIM_NUM_STATUSES
} _CiSimStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM status
 * \sa CISIMSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimStatus;
/**@}*/

/** \brief SIM PIN state values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMPINSTATE_TAG {
    CI_SIM_PIN_ST_READY,                         					/**< SIM is ready */

    CI_SIM_PIN_ST_CHV1_REQUIRED,                 	 /**< SIM is locked; waiting for a CHV1 password  */
    CI_SIM_PIN_ST_CHV2_REQUIRED,                 	 /**< SIM is locked; waiting for a CHV2 password  */
    CI_SIM_PIN_ST_UNBLOCK_CHV1_REQUIRED,         	 /**< SIM is blocked; CHV1 unblocking password is required */
    CI_SIM_PIN_ST_UNBLOCK_CHV2_REQUIRED,         	 /**< SIM is blocked; CHV2 unblocking password is required */

    /* Note: the '**CK' states are not fully supported at this time */
    CI_SIM_PIN_ST_PCK_REQUIRED,                 	/**< SIM is locked due to a SIM/USIM personalization check failure.
													 * SIM is waiting for a PCK control key to deactivate SIM/USIM personalization. */
    CI_SIM_PIN_ST_NCK_REQUIRED,                  	/**< SIM is locked due to a network personalization check failure.
													 * SIM is waiting for a NCK control key to deactivate network personalization. */
    CI_SIM_PIN_ST_NSCK_REQUIRED,                 	/**< SIM is locked due to a network subset personalization check failure.
													 * SIM is waiting for a NSCK control key to deactivate network subset personalization. */
	CI_SIM_PIN_ST_SPCK_REQUIRED,                 	/**< SIM is locked due to a service provider personalization check failure.
													 * SIM is waiting for a SPCK control key to deactivate service provider personalization. */
	CI_SIM_PIN_ST_CCK_REQUIRED,                      /**< SIM is locked due to a corporate personalization check failure.
													 * SIM is waiting for a CCK control key to deactivate corporate personalization. */
    CI_SIM_PIN_ST_UNBLOCK_PCK_REQUIRED,          	 /**< SIM is blocked due to an incorrect PCK; an MEP unblocking password is required. */
    CI_SIM_PIN_ST_UNBLOCK_NCK_REQUIRED,          	 /**< SIM is blocked due to an incorrect NCK; an MEP unblocking password is required. */
    CI_SIM_PIN_ST_UNBLOCK_NSCK_REQUIRED,         	 /**< SIM is blocked due to an incorrect NSCK; an MEP unblocking password is required. */
    CI_SIM_PIN_ST_UNBLOCK_SPCK_REQUIRED,         	 /**< SIM is blocked due to an incorrect SPCK; an MEP unblocking password is required. */
    CI_SIM_PIN_ST_UNBLOCK_CCK_REQUIRED,          	 /**< SIM is blocked due to an incorrect CCK; an MEP unblocking password is required. */

    /* note, according to 3GPP TS 22.022, v3.4.0, there is no standard way to unblock a locked */
    /* personalization key */

    /* Note: the 'HIDDENKEY' states are not supported at this time */
    CI_SIM_PIN_ST_HIDDENKEY_REQUIRED,            			/**< Expecting key for hidden phone book entries */
    CI_SIM_PIN_ST_UNBLOCK_HIDDENKEY_REQUIRED,    		/**< Expecting code to unblock the hidden key */

    CI_SIM_PIN_ST_UNIVERSALPIN_REQUIRED,         			/**< Expecting the universal PIN */
    CI_SIM_PIN_ST_UNBLOCK_UNIVERSALPIN_REQUIRED,		/**< Expecting code to unblock the universal PIN */

    CI_SIM_PIN_ST_CHV1_BLOCKED,                  				/**< Use of CHV1 is blocked */
    CI_SIM_PIN_ST_CHV2_BLOCKED,                  				/**< Use of CHV2 is blocked */
    CI_SIM_PIN_ST_UNIVERSALPIN_BLOCKED,          			/**< Use of the universal PIN is blocked */
    CI_SIM_PIN_ST_UNBLOCK_CHV1_BLOCKED,          		/**< Use of code to unblock the CHV1 is blocked */
    CI_SIM_PIN_ST_UNBLOCK_CHV2_BLOCKED,          		/**< Use of code to unblock the CHV2 is blocked */
    CI_SIM_PIN_ST_UNBLOCK_UNIVERSALPIN_BLOCKED,	 	/**< Use of code to unblock the universal PIN is blocked */

    CI_SIM_PIN_ST_NETWORK_REJECTED,              			/**< SIM was rejected by the network. See GSM 03.22 for possible reasons of network rejection. For example, IMSI is unknown in
                                                            *    the HLR or the IMSI is on the blacklist.  */
    CI_SIM_PIN_ST_WAIT_INITIALISATION,           			/**< SIM is being initialized; waiting for completion */
    CI_SIM_PIN_ST_INIT_FAILED,                   					/**< SIM initialization failed */
    CI_SIM_PIN_ST_REMOVED,                       				/**< SIM was removed */
    CI_SIM_PIN_ST_WRONG_SIM,                     				/**< SIM was inserted but was not accepted by the protocol stack */
    CI_SIM_PIN_ST_GENERAL_ERROR,                 				/**< SIM access encountered a serious error */
    CI_SIM_PIN_ST_MEP_ERROR,                     				/**< Error in checking or accessing ME personalization data */
    CI_SIM_PIN_ST_UDP_ERROR,							/**< Error in checking or accessing UDP personalization data */
    CI_SIM_PIN_ST_CPHS_ERROR,                    				/**<  Error in accessing CPHS data */

	CI_SIM_PIN_ST_EMPTY_ESIM,                           /**<  SIM is being initialized, but empty eSIM */

    CI_SIM_PIN_NUM_STATES
} _CiSimPinState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM PIN state
 * \sa CISIMPINSTATE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimPinState;
/**@}*/

/** \brief Result code values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMRC_TAG {
    CIRC_SIM_OK = 0,                			/**< Success */
    CIRC_SIM_FAILURE,               			/**< CME 13 - SIM failure */
    CIRC_SIM_MEM_PROBLEM,          		 		/**< CME 23 - Memory problem */
    CIRC_SIM_SIMAT_BUSY,            			/**< CME 14 - SIMAT busy */
    CIRC_SIM_INFO_UNAVAILABLE,      			/**< CME 100 - Requested information is unavailable */
    CIRC_SIM_NOT_INSERTED,          			/**< CME 10 - SIM not inserted */
    CIRC_SIM_PIN_REQUIRED,          			/**< CME 11 - SIM PIN (CHV1) required */
    CIRC_SIM_PUK_REQUIRED,          			/**< CME 12 - SIM PUK required */
    CIRC_SIM_BUSY,                  			/**< CME 14 - SIM busy */
    CIRC_SIM_WRONG,                 			/**< CME 15 - SIM wrong */
    CIRC_SIM_INCORRECT_PASSWORD,    			/**< CME 16 - Incorrect password  */
    CIRC_SIM_PIN2_REQUIRED,         			/**< CME 17 - SIM PIN2 (CHV2) required  */
    CIRC_SIM_PUK2_REQUIRED,         			/**< CME 18 - SIM PUK2 required */
    CIRC_SIM_OPERATION_NOT_ALLOWED, 			/**< CME 3 - Operation not allowed */
    CIRC_SIM_MEMORY_FULL,           			/**< CME 20 - Memory full */
    CIRC_SIM_UNKNOWN,               			/**< CME 100 - General error */
    CIRC_SIM_PERSONALISATION_DISABLED,			/**< CME 3 - Operation failed since personalization is disabled */
    CIRC_SIM_PERSONALISATION_BLOCKED,			/**< CME 41, CME 43, CME 45 or CME 47 - Operation failed since personalization is blocked */
    CIRC_SIM_PERSONALISATION_UNKNOWN,			/**< CME 100 - Operation failed since personalization database is not available */
    CIRC_SIM_PERSONALISATION_NOT_SUPPORTED,		/**< CME 4 - Operation failed since personalization is not supported */
    CI_SIM_BTSAP_RC_ERR_CARD_NOT_ACC, 	 		/**< Error, card not accessible */
	CI_SIM_BTSAP_RC_ERR_CARD_POWERED_OFF,		/**< Error, card (already) powered off */
	CI_SIM_BTSAP_RC_ERR_CARD_REMOVED,			/**< Error, card removed */
	CI_SIM_BTSAP_RC_ERR_CARD_POWERED_ON,		/**< Error, card (already) powered on */
	CI_SIM_BTSAP_RC_ERR_DATA_NOT_AVAILABLE,		/**< Error, data not available */
	CI_SIM_BTSAP_RC_ERR_NOT_SUPPORTED,			/**< Error, not supported */
	CIRC_SIM_INVALID_PARAMETER,					/**< Generic error - the requested service primitive has invalid parameters */
	CIRC_SIM_INVALID_REQ,						/**< Generic error - the requested service primitive can not be handled at current state */
	CIRC_SIM_SIM_NOT_READY,						/**< Generic error - the requested service primitive fails because SIM is not ready */
	CIRC_SIM_ACCESS_DENIED,						/**< Generic error - the requested service primitive fails because access is denied */
    CIRC_SIM_LONG_STR,							/**< Generic error  - the requested service primitive has an invalid parameter with string too long  */


    CIRC_SIM_NUM_RESCODES
} _CiSimRc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Result code
 * \sa CISIMRC_TAG */
/** \remarks Common Data Section */
typedef UINT16 CiSimRc;
/**@}*/

/*Michal Bukai - OTA support for AT&T - START*/
/*********************************************/

/** \brief MMI State values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMMMISTATE_TAG {
    CI_SIM_MMI_IDLE = 0,                	/**< MMI is in idle screen and user did not enter any keys */
    CI_SIM_MMI_BUSY,               			/**< There is an acitve menu or the user entered keys on the idle screen */
   
    CI_SIM_MMI_NUM_STATE
} _CiSimMMIState;
typedef UINT8 CiSimMMIState;

/*********************************************/
/** \brief CHV type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMCHVNO_TAG {
    CI_SIM_CHV_1 = 1, 	/**< CHV1 */
    CI_SIM_CHV_2,     		/**< CHV2 */

    CI_SIM_CHV_NEXT_FREE
} _CiSimChvNo;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CHV type
 * \sa CISIMCHVNO_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimChvNo;

#define CI_SIM_NUM_CHVS ( CI_SIM_CHV_NEXT_FREE - 1 )
/**@}*/

/** \brief CHV operation values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMCHVOPER_TAG {
    CI_SIM_CHV_VERIFY = 0,  	/**< Verify CHV value */
    CI_SIM_CHV_CHANGE,      	/**< Change CHV value */
    CI_SIM_CHV_DISABLE,     	/**< Disable the need for CHV verification, only applied to CHV1 */
    CI_SIM_CHV_ENABLE,      	/**< Enable the need for CHV verification, only applied to CHV1 */
    CI_SIM_CHV_UNBLOCK,     	/**< Unblock CHV */
    CI_SIM_CHV_QUERY,       	/**< Query CHV enable/disable status, only applied to CHV1 */

    CI_SIM_CHV_NUM_OPERS
} _CiSimChvOper;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CHV operation
 * \sa CISIMCHVOPER_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimChvOper;

#define CI_SIM_MIN_CHV_SIZE           4
#define CI_SIM_MAX_CHV_SIZE           8
#define CI_SIM_UNBLOCK_CHV_SIZE       8
/*2014.02.07, mod by Xili for CQ00056260, begin*/
#define CI_SIM_MAX_ME_PROFILE_SIZE    64//20 /* according to 3GPP TS 11.14, 5.2 */
/*2014.02.07, mod by Xili for CQ00056260, end*/

#define CI_SIM_ME_NORMAL_CK_MIN_SIZE  8
#define CI_SIM_ME_SIM_CK_MIN_SIZE     6
#define CI_SIM_ME_CK_MAX_SIZE         16
/**@}*/

/*******************************************************/
/* MEP UDP support - START    						   */
/*******************************************************/
#define  CI_SIM_MEP_MAX_NUMBER_OF_CODES  			100 /*3*/ /* here should be changed to 100, but may be due to CI length limiation !!*/
#define  CI_SIM_MEP_NUM_MEP_SUBSET_DIGITS       	2
#define  CI_SIM_MEP_MAX_IMSI_LENGTH  				8
#define  CI_SIM_MEP_NUM_MEP_NETWORKS     			100
#define  CI_SIM_UDP_ICCID_LEN                  		10
#define  CI_SIM_UDP_MAX_NUMBER_OF_ASL_ELEMENTS		10

/** \brief Operation on ME personalization values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMPERSMEOPER_TAG {
    CI_SIM_PERSME_ACTIVATE_PERSONALISATION,   	/**< Activates MEP. This operation requires the SIM pin state to be CI_SIM_PIN_ST_READY.  */
    CI_SIM_PERSME_DEACTIVATE_PERSONALISATION, 	/**< Deactivates MEP. This operation can be done in any SIM pin state and requires an MEP category password. */
    CI_SIM_PERSME_DISABLE_PERSONALISATION,    		/**< Disables MEP. This operation permanently deactivates the requested MEP category and can be done in any SIM pin state. The operation requires an MEP category password. */
    CI_SIM_PERSME_READ_PERSONALIZATION_STATUS,  	/**< Reads MEP status. This operation can be done in any SIM pin state.  */
    CI_SIM_PERSME_UNBLOCK_PERSONALISATION,          /**< Unblocks the SIM. This operation requires an MEP unblocking password.  */
    CI_SIM_PERSME_NUM_OPERS
} _CiSimPersOper;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Operation on ME personalization
 * \sa CISIMPERSMEOPER_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimPersOper;
/**@}*/

/** \brief Personalization category values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMPERSCAT_TAG {
    CI_SIM_PERS_CAT_SIM,					/**< SIM MEP category */
    CI_SIM_PERS_CAT_NETWORK,				/**< Network MEP category */
    CI_SIM_PERS_CAT_NETWORKSUBSET,		/**< Sub network MEP category */
    CI_SIM_PERS_CAT_SERVICEPROVIDER,		/**< Service provider MEP category */
    CI_SIM_PERS_CAT_CORPORATE,			/**< Corporate MEP category */
    CI_SIM_PERS_CAT_ZTE,               /*CQ00108573, Cgliu, 2017-12-12*/

    CI_SIM_PERS_NUM_CATS
} _CiSimPersCat;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Personalization category
 * \sa CISIMPERSCAT_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimPersCat;
/**@}*/



/*  9906-4268 From GSM 02.22 Page 9, the MEP network subset test shall be
 * performed on digits 6 and 7 of the IMSI, which translates to a single
 * msin array element since they are stored as 2 BCD's per byte. So change
 * number of subset digits to 1
 */
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief BCD structure  */
/** \remarks Common Data Section */
typedef UINT8  CiSimMEP_BCD;    /**< Valid digits are between 0-9. The digit 0xf is used for unused values */
/**@}*/

/** \remarks Common Data Section */
/** \brief  International mobile subscriber identity */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEP_IMSI_Tag
{
    UINT8        length;                         /**< Number of bytes */
    UINT8        contents [CI_SIM_MEP_MAX_IMSI_LENGTH];   /**< IMSI value represented as an array of bytes; each byte contains 2 digits */
} CiSimMEP_IMSI;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Mobile network code  */
/** \remarks Common Data Section */
typedef UINT16 CiSimMEP_MNC;
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Mobile country code  */
/** \remarks Common Data Section */
typedef UINT16 CiSimMEP_MCC;
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Access technology ID.
 * Coding of the access technology field is described in ETSI TS 131 102.
 * A bitmap is used. A set bit indicates the access technology is selected.
 * In the first byte, bit 8 specifies whether UTRAN is selected.
 * In the second byte, bit 8 specifies whether GSM is selected and
 * bit 7 specifies whether GSM COMPACT is selected. */
 /** \remarks Common Data Section */
typedef UINT16 CiSimMEP_AccessTechnologyId;
/**@}*/

/** \brief Type for public land mobile network definition */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEP_PLMN_Tag
{
  CiSimMEP_MCC                		mcc;              		/**< Mobile country code  \sa CiSimMEP_MCC */
  CiSimMEP_MNC                		mnc;              		/**< Mobile network code \sa CiSimMEP_MNC */
  CiSimMEP_AccessTechnologyId 	accessTechnology; 			/**< Access technology \sa CiSimMEP_AccessTechnologyId */
} CiSimMEP_PLMN;

/** \brief Type for PLMN with MNC length */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEPCodeType_PLMN_Tag
{
   CiSimMEP_PLMN    	 	plmn;                   		/**< PLMN \sa CiSimMEP_PLMN_Tag */
   CiBoolean     	        mncThreeDigitsDecoding; 		/**< If TRUE indicates 3 digit coding is used else 4 digit coding is used \sa CCI API Ref Manual */
} CiSimMEPCodeType_PLMN;


/** \brief MEP network subset code structure; see 3GPP TS 122.022 MEP  */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEPCodeType_NS_Tag
{
  CiSimMEP_BCD			networkSubsetId;  /**< Bits 0-3 = IMSI digit 6, Bits 4-7 = IMSI digit 7. \sa CiSimMEP_BCD */
} CiSimMEPCodeType_NS;

/** \brief MEP service provider code structure; see 3GPP TS 122.022 MEP  */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEPCodeType_SP_Tag
{
  UINT8      				serviceproviderId;  /**< Service provider ID */
} CiSimMEPCodeType_SP;

/** \brief MEP corporate code structure; see 3GPP TS 122.022 MEP  */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEPCodeType_CP_Tag
{
  UINT8      				corporateId;      /**< Corporate ID */
} CiSimMEPCodeType_CP;

/** \brief MEP SIM/USIM code structure; see 3GPP TS 122.022 MEP  */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimMEPCodeType_SIMUSIM_Tag
{
  CiSimMEP_IMSI      		simId;          /**< IMSI  \sa CiSimMEP_IMSI_Tag */
} CiSimMEPCodeType_SIMUSIM;

/** \brief  MEP codes - code structure depends on MEP category */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED UNION
typedef union CiSimMEPCodeType_Tag
{
	CiSimMEPCodeType_PLMN		  		Network;	/**< Network code - PLMN \sa  CiSimMEPCodeType_PLMN_Tag  */
	CiSimMEPCodeType_NS 	            NetworkSubset;    /**< Network subset code - IMSI bits 6 and 7 \sa  CiSimMEPCodeType_NS_Tag  */
	CiSimMEPCodeType_SP 				SP;               /**< Service provider code \sa CiSimMEPCodeType_SP_Tag */
	CiSimMEPCodeType_CP 				Corporate;        /**< Corporate code \sa CiSimMEPCodeType_CP_Tag */
	CiSimMEPCodeType_SIMUSIM 			SimUsim;          /**< SIM / USIM code - IMSI \sa CiSimMEPCodeType_SIMUSIM_Tag */
} CiSimMEPCodeType;

/** \brief  Operation on UDP lock */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMUDPOPER {
    CI_SIM_UDP_OPER_ACTIVATE_PERSONALISATION, 		/**< Activate */
    CI_SIM_UDP_OPER_DEACTIVATE_PERSONALISATION,     /**< Deactivate - this operation requires a password */
    CI_SIM_UDP_READ_PERSONALIZATION_STATUS,         /**< Read UDP lock status */
    CI_SIM_UDP_OPER_NUM
} _CiSimUDPOper;

typedef UINT8 CiSimUDPOper;

/** \brief  UDP category */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMUDPCAT {
    CI_SIM_UDP_CAT_UNAUTHERIZED_SIM_DETECTION,    	/**< Unauthorized SIM detection - SIM is unauthorized if its ICCID does not match any of the values stored in the authorized SIM list */
    CI_SIM_UDP_CAT_INVALID_SIM_DETECTION,           /**< Invalid SIM detection - SIM is invalid if it is rejected by the network */
    CI_SIM_UDP_CAT_NUM
} _CiSimUDPCat;

typedef UINT8 CiSimUDPCat;

/** \brief  UDP lock status values*/
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSIMUDPSTATUS_TAG {
    CI_SIM_UDP_UNKNOWN,				/**< Data based was not read  */
    CI_SIM_UDP_INACTIVE,    		/**< UDP lock is not active */
    CI_SIM_UDP_ACTIVE,      		/**< UDP lock is active */
    CI_SIM_UDP_IS_NOT_SUPPORTED,  	/**< UDP lock feature is not supported */
    CI_SIM_UDP_STATUS_NUM
} _CiSimUDPStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief UDP lock status
 * \sa CiSIMUDPSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimUDPStatus;	/**< UDP lock status */
/**@}*/

/** \brief  SIM ICCID structure */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimIccid_Tag
{
    UINT8    data[CI_SIM_UDP_ICCID_LEN];
}CiSimIccid;

/** \brief User data protection authorized SIM list operation values */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSIMUDPASLOPER_Tag {
    CI_SIM_UDP_ASL_ADD_CURRENT_SIM,   /**< Add ICCID of current SIM to authorized SIM list */
    CI_SIM_UDP_ASL_DELETE,            /**< Delete specified ICCID from authorized SIM list */
    CI_SIM_UDP_ASL_DELETE_ALL,        /**< Delete all values from authorized SIM list */
    CI_SIM_UDP_ASL_READ_ALL,          /**< Read authorized SIM list */
    CI_SIM_UDP_ASL_OPER_NUM
}_CiSimUDPASLOper;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief User data protection authorized SIM list operation
 * \sa CiSIMUDPASLOPER_Tag */
/** \remarks Common Data Section */
typedef UINT8 CiSimUDPASLOper;

/**@}*/

/** \brief  RTC data structure */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiRtcDate_Tag
{
  UINT16 	year;  		/**< RTC year */
  UINT8  	month; 		/**< RTC month (1-12) */
  UINT8  	day;   		/**< RTC day of month (1-31) */
} CiRtcDate;

/** \brief  UDP ASL entry data structure */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimUDPASLEntry_Tag
{
    CiSimIccid		iccid;		/**< \sa  CiSimIccid_Tag */
    CiRtcDate  		updateTime;	/**< \sa  CiRtcDate_Tag */
} CiSimUDPASLEntry;

/** \brief MEP status indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMPERSSTATUS_TAG {
    CI_SIM_MEP_ACTIVATED, 				/**< Activated */
    CI_SIM_MEP_DEACTIVATED,				/**< Deactivated */
    CI_SIM_MEP_DISABLED,				/**< Disabled - permanently deactivated */
    CI_SIM_MEP_BLOCKED,					/**< Blocked */
    CI_SIM_MEP_UNKNOWN,					/**< Unknown - database not read or corrupted */
    CI_SIM_PERS_ST_IS_NOT_SUPPORTED,    /**< Personalization not supported */

    CI_SIM_PERS_NUM_STATUSES
} _CiSimPersStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief MEP status indicator
 * \sa CISIMPERSSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimPersStatus;
/**@}*/

/*******************************************************/
/* SimLock MEP UDP support - END                       */
/*******************************************************/

/** \brief SIMAT terminal profile. Refer to 3GPP TS 11.14, v3.10.0, 5 */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimTermProfile_Struct {
    UINT8 len;   									/**< Length of the terminal profile [1- CI_SIM_MAX_ME_PROFILE_SIZE] */
    UINT8 data[CI_SIM_MAX_ME_PROFILE_SIZE];		/**< Terminal profile data.
     													* Content conforms to 3GPP TS 11.14, v3.10.0, 5.2; if empty, communication
     													* subsystem assumes ME doesn't support SIMAT. */
} CiSimTermProfile;

/** \brief SIM-related facility lock mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMFACLCKMODE_TAG {
    CI_SIM_FACLCK_MODE_UNLOCK = 0,  /**< Unlock */
    CI_SIM_FACLCK_MODE_LOCK,        /**< Lock */
    CI_SIM_FACLCK_MODE_QUERY,       /**< Query */

    CI_SIM_FACLCK_NUM_MODES
} _CiSimFacLckMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM-related facility lock mode
 * \sa CISIMFACLCKMODE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimFacLckMode;
/**@}*/

/** \brief SIM-related facility code */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMFACCODE_TAG {
    CI_SIM_FAC_CODE_SIM = 0,    /**< Locks SIM, needs to be unlocked with CHV1 */
    CI_SIM_FAC_CODE_FDN,        /**< Enables FDN feature, needs CHV2 verification,
                                   		*  refer to 3GPP 11.11 and 3GPP 11.14 */

    /* The following facility codes are related to personalization. Refer to 3GPP TS 22.022 */
    CI_SIM_FAC_CODE_PERS_FSIM,  /**< SIM personalization, lock phone with the first inserted SIM. Not supported */

    CI_SIM_FAC_CODE_P2, /* Add by jungle for CQ00055548 on 2014-03-04 */
    
    CI_SIM_FAC_NUM_CODES
} _CiSimFacCode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM-related facility code
 * \sa CISIMFACCODE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimFacCode;
/**@}*/

/** \brief SIM-related facility lock status */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMFACSTATUS_TAG {
    CI_SIM_FACLCK_ST_DEACTIVE = 0, 	/**< Not active */
    CI_SIM_FACLCK_ST_ACTIVE,        /**< Active */

    CI_SIM_FACLCK_NUM_STS
} _CiSimFacStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM-related facility lock status
 * \sa CISIMFACSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimFacStatus;

#define CI_SIM_MAX_LINEARFIXEDFILE_RECORDS    254
#define CI_SIM_MAX_LINEARFIXEDFILE_RECORD_SZE 255
/**@}*/

/** \brief SIM Toolkit (SIMAT) notification support options */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMATNOTIFYSUPPORT_TAG {
  CI_SIMATNOT_NOT_IMPLEMENTED = 0,  		/**< Not implemented */
  CI_SIMATNOT_APP_IMPLEMENTS,       		/**< Implemented in the application */
  CI_SIMATNOT_SIMAT_IMPLEMENTS_NO_NOTIFY,   /**< Implemented in the communication subsystem without notifying the application */
  CI_SIMATNOT_SIMAT_IMPLEMENTS_NOTIFY,     	/**< Implemented in the communication subsystem and the application is notified */
  CI_SIMATNOT_SIMAT_IMPLEMENTS_WITH_APP_INPUT,  /**< Implemented in the communication subsystem but requires input from the application */

  CI_NUM_SIMATNOT_SUPPORT_OPTIONS
} _CiSimatNotifySupport;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM Application Toolkit (SIMAT) notification support options
 * \sa CISIMATNOTIFYSUPPORT_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimatNotifySupport;
/**@}*/

/** \brief SIM Application Toolkit (SIMAT) Notification Capabilities structure. See 3GPP TS 11.14 (v8.11.0) Section 6 */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimatNotifyCap_struct {
  CiSimatNotifySupport  capDisplayText;			/**< DISPLAY TEXT, which displays text or an icon on the screen.  \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capGetInkey;				/**< GET INKEY, which sends text or an icon to the display and requests a single character response in return. It is intended to allow a dialog between the SIM and the user, particularly for selecting an option from a menu. \sa CiSimatNotifySupport*/
  CiSimatNotifySupport  capGetInput;				/**< GET INPUT, which sends text or an icon to the display and requests a response in return. It is intended to allow a dialog between the SIM and the user. \sa CiSimatNotifySupport*/
  CiSimatNotifySupport  capMoreTime;			/**< MORE TIME, which does not request any action from the ME. The ME is required to respond with TERMINAL RESPONSE (OK) as normal. The purpose of the MORE TIME command is to provide a mechanism for the SIM Application Toolkit task in the SIM to request more processing time. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capPlayTone;			/**< PLAY TONE, which requests the ME to play a tone in its earpiece, ringer, or other appropriate loudspeaker. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capPollInterval;			/**< POLL INTERVAL, which negotiates how often the ME sends STATUS commands to the SIM during idle mode. Polling is disabled with POLLING OFF. Use of STATUS for the proactive SIM is described in TS 11.11. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capRefresh;				/**< REFRESH, which requests the ME to carry out a SIM initialization according to TS 11.11 subclause 12.2.1, and/or advises the ME that the contents or structure of EFs on the SIM have been changed. The command also makes it possible to restart a card session by resetting the SIM. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSetupMenu;			/**< SETUP MENU: The SIM shall supply a set of menu items, which shall be integrated with the menu system (or other MMI facility) to give the user the opportunity to choose one of these menu items at his own discretion. Each item comprises a short identifier (used to indicate the selection), a text string, and optionally an icon identifier, contained in an item icon identifier list data object located at the end of the list of items. \sa CiSimatNotifySupport*/
  CiSimatNotifySupport  capSelectItem;			/**< SELECT ITEM, where the SIM supplies a list of items, and the user is expected to choose one. The ME presents the list in an implementation-dependent way. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSendSMS;			/**< SEND DATA, which requests the ME to send data on the specified channel provided by the SIM (if class "e" is supported). \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSendSS;				/**< SEND SS, which sends an SS request to the network. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSendUSSD;			/**< SEND USSD, which sends a USSD string to the network. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSetupCall;			/**< SET UP CALL, of which there are three types:
												 * set up a call, but only if not currently busy on another call;
												 * set up a call, putting all other calls (if any) on hold;
												 * set up a call, disconnecting all other calls (if any) \sa CiSimatNotifySupport*/
  CiSimatNotifySupport  capPollingOff;			/**< POLLING OFF - This command disables the Proactive Polling (defined in TS 11.11 [20]). SIM Presence Detection (defined in TS 11.11 [20]) is not affected by this command. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSetupIdleModeText;	/**< SETUP IDLE MODE TEXT  \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capProvideLocalInfo;		/**< Provide local information -
													 *  This command requests the ME to send current local information to the SIM.
													 * At present, this information is restricted to
													 *  location information (the mobile country code (MCC), mobile network code (MNC), location area code (LAC) and cell ID of the current serving cell);
													 * the IMEI of the ME;
													 * the network measurement results and the BCCH channel list;
													 * the current date, time and time zone;
													 * the current ME language setting;
													 * the timing advance \sa CiSimatNotifySupport*/
  CiSimatNotifySupport  capSetupEventList;		/**< SET UP EVENT LIST - The SIM shall use this command to supply a set of events. This set of events shall become the current list of events that the ME is to monitor. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capLaunchBrowser;		/**< LAUNCH BROWSER, which requests a browser inside a browser enabled ME to interpret the content corresponding to a URL. \sa CiSimatNotifySupport */

/*Mason BIP support - START*/
  CiSimatNotifySupport  capOpenChannel;       /**< OPEN CHANNEL realted to GPRS. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capCloseChannel;      /**< CLOSE CHANNEL. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capReceiveData;       /**< RECEIVE DATA. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capSendData;          /**< SEND DATA. \sa CiSimatNotifySupport */
  CiSimatNotifySupport  capGetChannelStatus;  /**< GET CHANNEL STATUS. \sa CiSimatNotifySupport */
/*Mason BIP support - END*/
} CiSimatNotifyCap;

#define CI_NUM_SIMAT_NOTIFY_CAPS  ( sizeof( CiSimatNotifyCap ) / sizeof( CiSimatNotifySupport ) )

/* Maximum length of Alpha IDs for SIM Application Toolkit operations - in particular for the
 * SIMAT "Call Setup Get Ack" indication. According to the Protocol Stack configuration header
 * file, this size must be defined to 241 to "satisfy certain test cases". */
#define CI_SIMAT_MAX_ALPHATAG_LENGTH  241

/** \brief SIM Application Toolkit (SIMAT) Alpha Tag structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimatAlphaTag_struct {
  UINT16 	len;										/**< Length */
  UINT8  	tag[ CI_SIMAT_MAX_ALPHATAG_LENGTH ];	/**< Tag data */
} CiSimatAlphaTag;

/** \brief Message waiting flag (indicator) bitmaps. See ETSI TS 131 102 V5.7.0 (2003-12) */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_MSGWAITING_FLAGS_TAG
{
  CI_SIM_MSG_WAITING_VOICE = 0x01,    	/**< Voice mail messages waiting */
  CI_SIM_MSG_WAITING_FAX   = 0x02,    	/**< Fax messages waiting */
  CI_SIM_MSG_WAITING_EMAIL = 0x04,    	/**< Email messages waiting */
  CI_SIM_MSG_WAITING_OTHER = 0x08     	/**< Other messages waiting */
} _CiSimMsgWaitingFlags;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message waiting flag (indicator) bitmaps. See ETSI TS 131 102 V5.7.0 (2003-12).
 * \sa CI_SIM_MSGWAITING_FLAGS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimMsgWaitingFlags;
/**@}*/

/** \brief Message waiting status information. See ETSI TS 131 102 V5.7.0 (2003-12) */
/** \remarks Common Data Section */

/*   <CDR-SMCD-610>620><630> <990> Support Message Waiting Ind files: MWIS / VMWF   --BT45*/
//ICAT EXPORTED STRUCT
typedef struct CiSimMsgWaitingInfo_struct
{
  UINT8  			flags;   /**<  Bit mask indicating message waiting status. A set bit indicates there is a message waiting in the specified group. Bit 0 - Voice mail ; Bit 1 - Fax; Bit 2 - Email; Bit 3 - other */
   				 	/*If "flags" == TRUE : next values contains message numbers		(for MWIS file)
	   				If FALSE:     Next value are only flags: 0- No Msg, Else Msg Exist (for VMWF file) */
  UINT8                 numVoice;     /**< Number of voice mail messages waiting */
  UINT8                 numFax;       /**< Number of fax messages waiting */
  UINT8                 numEmail;     /**< Number of email messages waiting */
  UINT8                 numOther;     /**< Number of other messages waiting */
} CiSimMsgWaitingInfo;

/* SIM Service Table structure. See ETSI TS 131 102 V5.7.0 (2003-12) */
#define CI_SIM_MAX_SERVICETABLE_SVCS  56
#define CI_SIM_MAX_SERVICETABLE_SIZE  ( ( CI_SIM_MAX_SERVICETABLE_SVCS + 7 ) / 8 )

/** \brief SIM service table structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimServiceTable_struct
{
  UINT8 	size;                     							/**< Actual number of bytes used in services[] array */
  UINT8 	services[ CI_SIM_MAX_SERVICETABLE_SIZE ];	/**< SIM service table */
} CiSimServiceTable;

/** \brief CPHS customer service profile structure. See CPHS document, Phase 2, ver 4.2.
  *          The field order in this structure and the coding of the bitmaps are defined in Section B.4.7 of the CPHS document.*/
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimCustServiceProfile_struct
{
  UINT8 cspCallOffering;          			/**< Bitmap: Call offering services */
  UINT8 cspCallRestriction;       			/**< Bitmap: Call restriction services */
  UINT8 cspOtherSuppServices;     		/**< Bitmap: Other supplementary services */
  UINT8 cspCallCompletion;        		/**< Bitmap: Call completion services */
  UINT8 cspTeleServices;          			/**< Bitmap: Teleservices */
  UINT8 cspCphsTeleServices;      		/**< Bitmap: CPHS teleservices */
  UINT8 cspCphsFeatures;          		/**< Bitmap: CPHS features */
  UINT8 cspNumberIdent;           		/**< Bitmap: Number identification services */
  UINT8 cspPhase2PlusServices;    		/**< Bitmap: Phase 2+ services */
  UINT8 cspValueAddedServices;    		/**< Bitmap: Value added services */
  UINT8 cspInformationNumbers;    		/**< Bitmap: CPHS information numbers */
} CiSimCustServiceProfile;

/** \brief Type of SIMAT proactive command that triggered the display information indication */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMATDISPLAYCMDTYPE_TAG {
  CI_SIMAT_DISPLAYCMD_SMS = 0,               /**< SMS */
  CI_SIMAT_DISPLAYCMD_USSD,                  /**< USSD */
  CI_SIMAT_DISPLAYCMD_SS,                    /**< SS */
  CI_SIMAT_DISPLAYCMD_SD,   			    /**< SEND DTMF */
  CI_NUM_SIMAT_NUM_DISPLAYCMD_TYPES
} _CiSimatDisplayCmdType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM Toolkit (SIMAT) display cmd type
 * \sa CISIMATDISPLAYCMDTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimatDisplayCmdType;
/**@}*/

/** \brief SIM Toolkit (SIMAT) icon display. See 3GPP 11.14 ver 8.15.0 sec. 12.31. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMATICONDISPLAY_TAG {
  CI_SIMAT_DISPLAY_ICONID_ONLY = 0,           /**< Display only icons */
  CI_SIMAT_DISPLAY_ICONID_WITH_ALPHAID,        /**< Display icons and text */
  CI_NUM_SIMAT_NUM_DISPLAY_ICON_TYPES
} _CiSimatIconDisplay;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM Toolkit (SIMAT) icon display. See 3GPP 11.14 ver 8.15.0 sec. 12.31.
 * \sa CISIMATICONDISPLAY_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimatIconDisplay;
/**@}*/

/** \brief SIM Application Toolkit (SIMAT) Icon Tag structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimatIconTag_struct {
  CiSimatIconDisplay 	display;		/**< Icon display \sa CiSimatIconDisplay */
  UINT8              		tag;			/**< Icon tag data */
} CiSimatIconTag;

/* undefined default language */
#define CI_SIM_LANG_UNSPECIFIED 0xFFFF

/** \brief Generic command types as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221; some naming inconsistencies are noted.  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMGENERICCMDTYPE_TAG
{
    CI_SIM_SELECT             = 0xa4,
    CI_SIM_STATUS             = 0xf2,

    CI_SIM_READ_BINARY        = 0xb0,
    CI_SIM_UPDATE_BINARY      = 0xd6,
    CI_SIM_READ_RECORD        = 0xb2,
    CI_SIM_UPDATE_RECORD      = 0xdc,

    CI_SIM_SEARCH_RECORD      = 0xa2,					/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_SEEK               = 0xa2,					/**< Named as in 3gpp TS 11.11 sec 9.2 */
    CI_SIM_INCREASE           = 0x32,

    CI_SIM_VERIFY             = 0x20,					/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_VERIFY_CHV         = 0x20,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_CHANGE_PIN         = 0x24,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_CHANGE_CHV         = 0x24,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_DISABLE_PIN        = 0x26,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_DISABLE_CHV        = 0x26,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_ENABLE_PIN         = 0x28,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_ENABLE_CHV         = 0x28,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_UNBLOCK_PIN        = 0x2c,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_UNBLOCK_CHV        = 0x2c,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_DEACTIVATE_FILE    = 0x04,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_INVALIDATE         = 0x04,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_ACTIVATE_FILE      = 0x44,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_REHABILITATE       = 0x44,				/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_AUTHENTICATE       = 0x88,				/**< Named as in ETSI TS 102.221 sec 10.1.2 */
    CI_SIM_RUN_GSM_ALGORITHM  = 0x88,			/**< Named as in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_SLEEP              = 0xfa,					/**< Only defined in 3gpp TS 11.11 sec 9.2 */
    CI_SIM_GET_RESPONSE       = 0xc0,				/**< Only defined in 3gpp TS 11.11 sec 9.2 */

    CI_SIM_TERMINAL_PROFILE   =	0x10,
    CI_SIM_ENVELOPE           =	0xC2,
    CI_SIM_FETCH              =	0x12,
    CI_SIM_TERMINAL_RESPONSE  =	0x14,

    CI_SIM_MANAGE_CHANNEL     = 0x70,			/**< Only defined in ETSI TS 102.221 */

    /* this should always be the last entry  */
    CI_SIM_INVALID_CMD        = 0x00

} _CiSimGenericCmdType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Generic command types as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221; some naming inconsistencies are noted
 * \sa CISIMGENERICCMDTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimGenericCmdType;
/**@}*/

/** \brief Generic access mode types for linear files; as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMGENERICRWMODETYPE_TAG
{
  CI_SIM_NEXT_REC          =   0x02,
  CI_SIM_PREVIOUS_REC      =   0x03,
  CI_SIM_CURRENT_ABSOLUTE  =   0x04
} _CiSimGenericRwModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Generic access mode types for linear files
 * \sa CISIMGENERICRWMODETYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimGenericRwModeType;
/**@}*/

/** \brief Generic SELECT mode types as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMGENERICSELECTMODETYPE_TAG
{
  CI_SIM_SELECT_BY_FILE_ID = 0x00,
  CI_SIM_SELECT_CHILD_DF = 0x01,
  CI_SIM_SELECT_PARENT_DF = 0x03,
  CI_SIM_SELECT_BY_DF_NAME = 0x04,
  CI_SIM_SELECT_BY_PATH_FROM_MF = 0x08,
  CI_SIM_SELECT_BY_PATH_FROM_DF = 0x09

} _CiSimGenericSelectModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Generic access mode types for linear files
 * \sa CISIMGENERICSELECTMODETYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimGenericSelectModeType;
/**@}*/

/** \brief Specifies the referencing path for the DF/EF file to be selected  */
/** \remarks Common Data Section */
typedef CiString CiSimFilePath;

/** \brief Generic SELECT mode types as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221   */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMGENERICRESPONSETYPE_TAG
{
  CI_SIM_RETURN_FCP = 0x04,
  CI_SIM_RETURN_NO_DATA = 0x0C

/* NOTE: more to be defined as needed */
} _CiSimGenericResponseType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Generic SELECT mode types as defined in 3gpp TS 11.11 sec 9.2 as well as in ETSI TS 102.221
 * \sa CISIMGENERICRESPONSETYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimGenericResponseType;
/**@}*/

/* ********** */
/* Primitives */
/* ********** */

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_EXECCMD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimExecCmdReq_struct {
    /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/
    UINT16				SessionId;	/**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
    CiSimCmdReq 		cmd;		/**< SIM Command. \sa CiSimCmdReq_Struct */
} CiSimPrimExecCmdReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_EXECCMD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimExecCmdCnf_struct{
    CiSimRc      rc;		/**< Result code  \sa CiSimRc */
    CiSimCmdRsp   cnf;					/**< Confirmation of last SIM command request; if rc is CI_SIM_CMDREQ_FAILURE, this field is optional. \sa CiSimCmdRsp */
    /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/
    UINT16				SessionId;	/**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
} CiSimPrimExecCmdCnf;

/* Add by jungle for CQ00089692 on 2015-04-08 Begin */
/* <INUSE> */
/**  <paramref name="CI_SIM_PRIM_EXEC_LARGE_CMD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimExecLargeCmdCnf_struct{
    CiSimRc      rc;         /**< Result code  \sa CiSimRc */
    CiSimLargeCmdRsp  cnf;        /**< Confirmation of last SIM command request; if rc is CI_SIM_CMDREQ_FAILURE, this field is optional. \sa CiSimCmdRsp */
    UINT16       SessionId;  /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
} CiSimPrimExecLargeCmdCnf;
/* Add by jungle for CQ00089692 on 2015-04-08 End */

/** \brief Indicates the clock stop preferred level of the
 *         current SIM */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_CLOCK_STOP_LEVEL_TAG{
    CI_SIM_CLOCK_STOP_NONE = 0,	/**< Clock Stop No Level Preferred */
    CI_SIM_CLOCK_STOP_LOW,		/**< Clock Stop Low Level Preferred */
    CI_SIM_CLOCK_STOP_HIGH, 	/**< Clock Stop High Level Preferred */
	CI_SIM_CLOCK_STOP_NUM
} _CiSimClockStopLevel;


/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Indicates the clock stop preferred level of the
 *          current SIM.
 * \sa CI_SIM_CLOCK_STOP_LEVEL_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiSimClockStopLevel;
/**@}*/

/** \brief
 * \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_ECALL_SUPPORT_TYPE_TAG{
    CI_SIM_ECALL_NONE = 0,
    CI_SIM_ECALL_SUPPORTED,
    CI_SIM_ECALL_ONLY,
	CI_SIM_ECALL_NUM
} _CiSimEcallSuppurtType;


/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief
 * \sa CI_SIM_ECALL_SUPPORT_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimEcallSuppurtType;
/**@}*/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_DEVICE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimDeviceInd_struct {
    CiSimStatus     		status;			/**< SIM Status.\sa CiSimStatus */
    CiSimPinState   	pinState;		/**< PIN state when SIM becomes ready, ignored if status is NOT CI_SIM_ST_ READY. \sa CiSimPinState */
	/*Michal Bukai - OTA support for AT&T*/
	CiBoolean		ProactiveSessionStatus;	/**< Indicates if in proactive session or not. \sa CCI API Ref Manual */
    /*merged by cherryli@04.26.2016 CQ105208 begin.*/
	CiBoolean			EcallData;		/**< TRUE if service 48 is enabled on SIM and this SIM support eCall \sa */
	CiBoolean			EcallOnlyMode;	/**< TRUE if the SIM works in eCall only mode \sa */
    /*merged by cherryli@04.26.2016 CQ105208 end.*/
} CiSimPrimDeviceInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_PERSONALIZEME_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimPersonalizeMEReq_struct{
    CiSimPersOper 		oper;					/**< Operation on ME personalization  \sa CiSimPersOper */
    CiSimPersCat  		cat;						/**< Personalization category  \sa CiSimPersCat */
    CiMepPassword    	pass;					/**< this field is optional if oper is CI_SIM_PERS_OPER_DISABLE or CI_SIM_PERS_OPER_QUERY. \sa CCI API Ref Manual */
} CiSimPrimPersonalizeMEReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_PERSONALIZEME_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimPersonalizeMECnf_struct{
    CiSimRc         		rc;		/**< Result code \sa CiSimRc */
    CiSimPersStatus 	status;	/**< Personalization indicator status \sa CiSimPersStatus */
} CiSimPrimPersonalizeMECnf;

/*******************************************************/
/* MEP UDP support - START                             */
/*******************************************************/

/** <paramref name="CI_SIM_PRIM_READ_MEP_CODES_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimReadMEPCodesReq_struct {
    CiSimPersCat  		MEPCategory;	/**< Personalization category \sa CiSimPersCat */
} CiSimPrimReadMEPCodesReq;

/** <paramref name="CI_SIM_PRIM_READ_MEP_CODES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimReadMEPCodesCnf_struct {
    CiSimRc 			rc;											/**< Result code \sa _CiSimRc */
    CiSimPersCat  		MEPCategory;								/**< Personalization category \sa CiSimPersCat */
    UINT8                      NumberOfcodes;  							/**< Number of codes stored in ME */
    CiSimMEPCodeType Codes[CI_SIM_MEP_MAX_NUMBER_OF_CODES]; /**< MEP personalization codes \sa CiSimMEPCodeType_Tag */
} CiSimPrimReadMEPCodesCnf;

/** <paramref name="CI_SIM_PRIM_UDP_LOCK_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPLockReq_struct {
    CiSimUDPOper 		oper;							/**< Operation on UDP lock \sa CiSimUDPOper */
    CiSimUDPCat  		UDPCategory;					/**< UDP category \sa CiSimUDPCat */
    CiPassword    		Pass;					/**< This is the password required to deactivate the UDP lock. This field is optional in activate or read status operations. \sa CCI API Ref Manual */
} CiSimPrimUDPLockReq;

/** <paramref name="CI_SIM_PRIM_UDP_LOCK_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPLockCnf_struct {
    CiSimRc 			rc;		/**< Result code. Note that the following values are not valid for UDP: CIR_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */
    CiSimUDPStatus      status;	/**< UDP lock status  \sa CiSimUDPStatus */
} CiSimPrimUDPLockCnf;

/** <paramref name="CI_SIM_PRIM_UDP_CHANGE_PASSWORD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPChangePasswordReq_struct {
    CiPassword			 oldPassword;  	/**< This is the current password required to unlock the UE. \sa CCI API Ref Manual */
    CiPassword			 newPassword;  	/**< This is the new password. \sa CCI API Ref Manual */
} CiSimPrimUDPChangePasswordReq;

/** <paramref name="CI_SIM_PRIM_UDP_CHANGE_PASSWORD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPChangePasswordCnf_struct {
    CiSimRc 		    rc;		/**< Result code. Note that the following values are not valid for UDP: CIRC_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */
} CiSimPrimUDPChangePasswordCnf;

/** <paramref name="CI_SIM_PRIM_UDP_ASL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPASLReq_struct {
    CiSimUDPASLOper            Oper;  			/**< Operation that should be performed on ASL  \sa CiSimUDPASLOper */
    CiSimIccid                         Iccid;  			/**< Required only for delete operation  \sa CiSimIccid_Tag */
} CiSimPrimUDPASLReq;

/** <paramref name="CI_SIM_PRIM_UDP_ASL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUDPASLCnf_struct {
    CiSimRc 			rc;		/**< Result code. Note that the following values are not valid for UDP: CIRC_SIM_ PERSONALISATION_DISABLED and CIRC_SIM_ PERSONALISATION_BLOCKED. \sa _CiSimRc */
    UINT8            		num;  	/**< Number of entries in ASL. Valid if operation was READ_ALL. 0 means there are no entries in ASL [range: 0 - max number of ASL elements].  */
    CiSimUDPASLEntry TypeAutherizedSIMlist[CI_SIM_UDP_MAX_NUMBER_OF_ASL_ELEMENTS]; /**< Valid if operation was READ_ALL. Reports the ICCID of all SIMs in the authorized list and the date they were added. \sa CiSimUDPASLEntry_Tag */
} CiSimPrimUDPASLCnf;

/*******************************************************/
/* MEP UDP support - END      */
/*******************************************************/


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_OPERCHV_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimOperChvReq_struct{
    CiSimChvOper 		oper;				/**< \sa CiSimChvOper */
    CiSimChvNo   		chvNo;				/**< \sa CiSimChvNo */
    CiPassword    		chvVal;				/**< \sa CCI API Ref Manual */
    CiPassword    		newChvVal;			/**< \sa CCI API Ref Manual */
} CiSimPrimOperChvReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_OPERCHV_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimOperChvCnf_struct{
    CiSimRc      	rc;					/**< Result code \sa CiSimRc */
    CiBoolean   	enabled;			/**< Not optional if operation is CI_SIM_CHV_QUERY. TRUE: CHV1 is enabled; FALSE: CHV1 is disabled. \sa CCI API Ref Manual */
} CiSimPrimOperChvCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_DOWNLOADPROFILE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimDownloadProfileReq_struct{
   	CiSimTermProfile  	profile;					/**< Terminal profile structure \sa CiSimTermProfile_Struct */
} CiSimPrimDownloadProfileReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_DOWNLOADPROFILE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimDownloadProfileCnf_struct{
    CiSimRc rc;			/**< Result code \sa CiSimRc */
} CiSimPrimDownloadProfileCnf;

/**	 <paramref name="CI_SIM_PRIM_ENDATSESSION_IND"> */
/* Mod by jungle for CQ00055562 on 2014-03-04 Begin */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEndAtSessionInd_struct{
    UINT8 fetchSize;
}CiSimPrimEndAtSessionInd;
/* Mod by jungle for CQ00055562 on 2014-03-04 End */

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_PROACTIVE_CMD_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimProactiveCmdInd_struct{
    UINT16  		len;									/**< Length of the proactive command data [1-255] */
 	UINT8    		data[CI_SIM_MAX_CMD_DATA_SIZE];	/**< Proactive command data */
} CiSimPrimProactiveCmdInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_PROACTIVE_CMD_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimProactiveCmdRsp_struct{
    UINT16  		len;									/**< Length of the terminal response command data [1-255] */
    UINT8 			data[CI_SIM_MAX_CMD_DATA_SIZE];	/**< Terminal response command data */
} CiSimPrimProactiveCmdRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ENVELOPE_CMD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEnvelopeCmdReq_struct{
    UINT16  	len;									/**< Length of the envelope command data [1-255] */
    UINT8 		data[CI_SIM_MAX_CMD_DATA_SIZE];	/**< Envelope command data */
} CiSimPrimEnvelopeCmdReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ENVELOPE_CMD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEnvelopeCmdCnf_struct{
    CiSimRc      rc;									/**< Result code \sa CiSimRc */
    CiSimCmdRsp   cnf;								/**< Confirmation to an ENVELOPE command request; if rc is CI_SIM_CMDREQ_FAILURE, this field is optional. \sa CiSimCmdRsp_Struct */
} CiSimPrimEnvelopeCmdCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SUBSCRIBER_ID_REQ"> */
typedef CiEmptyPrim CiSimPrimGetSubscriberIdReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SUBSCRIBER_ID_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetSubscriberIdCnf_struct{
    CiSimRc   rc;				/**< Result code  \sa CiSimRc */
    CiString  	subscriberStr;	/**< Subscriber ID string \sa CCI API Ref Manual */
} CiSimPrimGetSubscriberIdCnf;

/**	 <paramref name="CI_SIM_PRIM_GET_PIN_STATE_REQ"> */
typedef CiEmptyPrim CiSimPrimGetPinStateReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_PIN_STATE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetPinStateCnf_struct{
    CiSimRc       		rc;					/**< Result code  \sa CiSimRc */
    CiSimPinState 		state;				/**< Current PIN state \sa CiSimPinState */
    UINT8 				chv1NumRetrys;		/**< Pin1 status - number of remaining retries */
    UINT8 				chv2NumRetrys;		/**< Pin2 status - number of remaining retries */
    UINT8 				puk1NumRetrys;		/**< Unblock pin1 status - number of remaining retries */
    UINT8 				puk2NumRetrys;		/**< Unblock pin2 status - number of remaining retries */
	UINT8 				MEPSimNumRetrys;	/**< SIM MEP category - number of remaining retries */
    UINT8 				MEPNwNumRetrys;		/**< Network MEP category  - number of remaining retries */
    UINT8 				MEPNwsubNumRetrys;	/**< Sub Network MEP category  - number of remaining retries */
    UINT8 				MEPSPNumRetrys;		/**< Service provider MEP category  - number of remaining retries */
	UINT8 				MEPCorpNumRetrys;	/**< Corporate MEP category  - number of remaining retries */

} CiSimPrimGetPinStateCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_TERMINALPROFILE_REQ"> */
typedef CiEmptyPrim CiSimPrimGetTerminalProfileReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_TERMINALPROFILE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetTerminalProfileCnf_struct{
    CiSimRc           		rc;						/**< Result code  \sa CiSimRc */
    CiSimTermProfile 	profile;					/**< The terminal profile structure; optional if rc is not CIRC_SIM_OK. \sa CiSimTermProfile_Struct */
} CiSimPrimGetTerminalProfileCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ENABLE_SIMAT_INDS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEnableSimatIndsReq_struct{
    CiBoolean  		enable;						/**< TRUE: enable the indication report; FALSE: disable the indication report, default \sa CCI API Ref Manual */
} CiSimPrimEnableSimatIndsReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ENABLE_SIMAT_INDS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEnableSimatIndsCnf_struct{
    CiSimRc 		rc;							/**< Result code  \sa CiSimRc */
} CiSimPrimEnableSimatIndsCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_LOCK_FACILITY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimLockFacilityReq_struct{
    CiSimFacLckMode 		mode;			/**< Facility setting mode \sa CiSimFacLckMode */
    CiSimFacCode    		fac;				/**< Facility code \sa CiSimFacCode */
    CiPassword      		pass;				/**< Password, optional if mode is CI_SIM_FACLCK_MODE_QUERY \sa CCI API Ref Manual */
} CiSimPrimLockFacilityReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_LOCK_FACILITY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimLockFacilityCnf_struct{
    CiSimRc         		rc;			/**< Result code  \sa CiSimRc */
    CiSimFacStatus  	status;		/**< Optional if rc is not CIRC_SIM_OK \sa CiSimFacStatus */
} CiSimPrimLockFacilityCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_FACILITY_CAP_REQ"> */
typedef CiEmptyPrim CiSimPrimGetFacilityCapReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_FACILITY_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetFacilityCapCnf_struct{
    CiSimRc     		rc;			/**< Result code  \sa CiSimRc */
    CiBitRange  		bitsFac;		/**< Optional if rc is not CIRC_SIM_OK \sa CCI API Ref Manual */
} CiSimPrimGetFacilityCapCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_REQ"> */
typedef CiEmptyPrim CiSimPrimGetSimatNotifyCapReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SIMAT_NOTIFY_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetSimatNotifyCapCnf_struct{
    CiSimRc            		rc;						/**< Result code  \sa CiSimRc */
    CiSimatNotifyCap   		caps;					/**< SIMAT notification capability information  \sa CiSimatNotifyCap_struct */
} CiSimPrimGetSimatNotifyCapCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_CALL_SETUP_ACK_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetCallSetupAckInd_struct{
    CiBoolean  			alphaIdPresent;				/**< Indicates whether the CALL SETUP has an accompanying alphanumeric ID string \sa CCI API Ref Manual */
   	CiSimatAlphaTag  	alphaId;						/**< Optional alphanumeric ID  \sa CiSimatAlphaTag_struct */
} CiSimPrimGetCallSetupAckInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_CALL_SETUP_ACK_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetCallSetupAckRsp_struct{
    CiBoolean  		accept;							/**< CALL SETUP response  \sa CCI API Ref Manual */
} CiSimPrimGetCallSetupAckRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetServiceProviderNameReq_struct{
    UINT8  		type;							/**< SPN type: 0-GSM_SPN, 1-USIM_SPN. \sa CCI API Ref Manual */
} CiSimPrimGetServiceProviderNameReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SERVICE_PROVIDER_NAME_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetServiceProviderNameCnf_struct
{
    CiSimRc      	rc;						/**< Result code  \sa CiSimRc */
    UINT8  		    dispRplmn;				/**<  Display RPLMN: 0-no display, 1-display, 99-invalid. \sa CCI API Ref Manual */
    CiNameInfo  	spName;					/**< Service provider name; NULL pointer if name is not available \sa CCI API Ref Manual */
} CiSimPrimGetServiceProviderNameCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_REQ"> */
typedef CiEmptyPrim CiSimPrimGetMessageWaitingInfoReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_MESSAGE_WAITING_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetMessageWaitingInfoCnf_struct
{
    CiSimRc           			rc;		/**< Result code  \sa CiSimRc */
    CiSimMsgWaitingInfo  	info;	/**< Message waiting information \sa CiSimMsgWaitingInfo_struct */
} CiSimPrimGetMessageWaitingInfoCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSetMessageWaitingInfoReq_struct
{
    CiSimMsgWaitingInfo  	info;		/**< Message waiting information \sa CiSimMsgWaitingInfo_struct */
} CiSimPrimSetMessageWaitingInfoReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SET_MESSAGE_WAITING_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSetMessageWaitingInfoCnf_struct
{
    CiSimRc 				rc;			/**< Result code  \sa CiSimRc */
} CiSimPrimSetMessageWaitingInfoCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_REQ"> */
typedef CiEmptyPrim CiSimPrimGetSimServiceTableReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_SIM_SERVICE_TABLE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetSimServiceTableCnf_struct
{
  CiSimRc           		rc;				/**< Result code  \sa CiSimRc */
  CiBoolean         		sstPresent;		/**< Indicates whether SIM Service Table is present  \sa CCI API Ref Manual */
  CiSimServiceTable 	sst;				/**< SIM Service Table (if available) \sa CiSimServiceTable_struct */
} CiSimPrimGetSimServiceTableCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_REQ"> */
typedef CiEmptyPrim CiSimPrimGetCustomerServiceProfileReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_CUSTOMER_SERVICE_PROFILE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetCustomerServiceProfileCnf_struct
{
  CiSimRc                 		rc;				/**< Result code \sa CiSimRc. */
  CiBoolean               		cspPresent;		/**< Indicates whether Customer Service Profile is present \sa CCI API Ref Manual */
  CiSimCustServiceProfile 	csp;				/**< Customer Service Profile (if available) \sa CiSimCustServiceProfile_struct */
} CiSimPrimGetCustomerServiceProfileCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_DISPLAY_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSimatDisplayInfoInd_struct {
  CiSimatDisplayCmdType   	type;				/**< Type of SIMAT proactive command that triggered the display info indication \sa CiSimatDisplayCmdType */
  CiBoolean               		alphaIdPresent;		/**< Indicates whether alpha identifier is present \sa CCI API Ref Manual */
  CiBoolean               		iconIdPresent;		/**< Indicates whether icon identifier is present \sa CCI API Ref Manual */
  CiSimatAlphaTag         	alphaId;				/**< Alpha ID (if available) \sa CiSimatAlphaTag_struct  */
  CiSimatIconTag          		iconId;				/**< Icon ID (if available) \sa CiSimatIconTag_struct */
} CiSimPrimSimatDisplayInfoInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_REQ"> */
/* request for the default language stored on the SIM card */
typedef CiEmptyPrim CiSimPrimGetDefaultLanguageReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_DEFAULT_LANGUAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetDefaultLanguageCnf_struct
{
  CiSimRc      rc;				/**< Result code  \sa CiSimRc */
  UINT16       	language;           	/**< One byte for each alphanumeric character */

} CiSimPrimGetDefaultLanguageCnf;

#define CI_SIM_MAX_APDU_HEADER_SIZE		6
#define CI_SIM_MAX_APDU_DATA_SIZE		255
#define CI_SIM_MAX_APDU_SIZE			(CI_SIM_MAX_APDU_DATA_SIZE + CI_SIM_MAX_APDU_HEADER_SIZE)
#define CI_SIM_MIN_APDU_SIZE			4

/* request to send a generic command to the SIM card */
/* the request structure reflects the structure of a SIM */
/* application protocol data unit (APDU), as per ETSI 102.221 & TS 11.11 */
/* Note: the class of instruction is transparent */

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GENERIC_CMD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGenericCmdReq_struct
{
  CiSimFilePath         		path;               					/**< Path of the elementary file \sa CiSimFilePath */
  CiSimGenericCmdType   	instruction;        						/**< Instruction code \sa CiSimGenericCmdType */
  UINT8                 			param1;             				/**< Instruction parameter 1 for the instruction */
  UINT8                 			param2;								/**< Instruction parameter 2 for the instruction*/
  UINT8                 			length;             						/**< Number of bytes in the command data string */
  UINT8					data[CI_SIM_MAX_APDU_DATA_SIZE];   	/**< Command data string */
  CiBoolean             		responseExpected;   					/**< Indicates if a response is expected by the application \sa CCI API Ref Manual */
  UINT8                 			responseLength;     					/**< Number of bytes expected in the response data string */
  /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/
  UINT16				SessionId; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
} CiSimPrimGenericCmdReq;

/* confirmation to a previous request to send a generic command to the SIM card */

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GENERIC_CMD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGenericCmdCnf_struct{
  CiSimRc        			rc;				/**< Result code  \sa CiSimRc */
  CiSimCmdRsp    			cnf;				/**< SIM generic command response \sa CiSimCmdRsp_Struct */
  UINT8          				sw1;        		/**< Status byte 1 as returned from the card */
  UINT8          				sw2;       		 /**< Status byte 2 as returned from the card */
  /*Michal Bukai - SIM Logic CH - NFC\ISIM support*/
  UINT16				SessionId; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
} CiSimPrimGenericCmdCnf;

/* Add by jungle for CQ00089692 on 2015-04-08 Begin */
/* <INUSE> */
/**  <paramref name="CI_SIM_PRIM_GENERIC_LARGE_CMD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGenericLargeCmdCnf_struct{
  CiSimRc               rc;             /**< Result code  \sa CiSimRc */
  CiSimLargeCmdRsp      cnf;                /**< SIM generic command response \sa CiSimCmdRsp_Struct */
  UINT16                SessionId; /**< A session Id to be used in order to target a specific application on the smart card using logical channel mechanism. */
} CiSimPrimGenericLargeCmdCnf;
/* Add by jungle for CQ00089692 on 2015-04-08 End */

/*CQ00116569, Cgliu, 2019-10-15, Begin*/
/*Add *SIMPOLL command...*/
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SET_POLL_REQ"> */   
//ICAT EXPORTED STRUCT   
typedef struct CiSimPrimSetPollReq_struct {
   UINT8       mode;                /*0: disable polling; 1: enable polling (Default); others RFU*/			
   UINT8       pollingConfig;       /*0: use UE default inverval,28s, (Default);1: enable polling config value; others RFU*/
   UINT8       stkPolling;          /*0: don't use stk polling interval; 1: use the stk polling interval(default); others RFU*/
   UINT32      interval;            /*unit: second*/
}CiSimPrimSetPollReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SET_POLL_CNF"> */     
//ICAT EXPORTED STRUCT    
typedef struct CiSimPrimSetPollCnf_struct{
    CiSimRc 		result;     /**< Result code  \sa CiSimRc */
}CiSimPrimSetPollCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_POLL_REQ"> */ 
typedef CiEmptyPrim CiSimPrimGetPollReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_POLL_CNF"> */ 
//ICAT EXPORTED STRUCT   
typedef struct CiSimPrimGetPollCnf_struct{
   CiSimRc 		result; 	/**< Result code  \sa CiSimRc */
   UINT8       mode;           /*0: disable polling; 1: enable polling (Default); others RFU*/			
   UINT8       pollingConfig;  /*0: use UE default inverval,28s, (Default);1: enable polling config value; others RFU*/
   UINT8       stkPolling;     /*0: don't use stk polling interval; 1: use the stk polling interval(default); others RFU*/
   UINT32      interval;        /*unit: second*/
}CiSimPrimGetPollCnf;   
/*CQ00116569, Cgliu, 2019-10-15, End  */

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_DEVICE_RSP"> */
typedef CiEmptyPrim CiSimPrimDeviceRsp;


/**********************************************************/
/*  Michal Bukai - USIM Clock stop level  support - END  */
/*********************************************************/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_CARD_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimCardInd_struct {
  CiSimStatus     			status;		/**< SIM Status. \sa CiSimStatus */
  CiSimPinState   			pinState;	/**< PIN state when SIM becomes ready, ignored if status is NOT CI_SIM_ST_READY. \sa CiSimPinState */
  CiBoolean       			cardIsUicc;   /**< TRUE if USIM card; FALSE if SIM card. \sa CCI API Ref Manual */

  CiBoolean                 isTestCard;   /**< TRUE if Test card; FALSE if normal/special card. \sa CCI API Ref Manual */
  /*2015.01.13, mod by Xili for #517213, CQ00081907 begin*/
  /*mod for CQ00085367 by yunhail 2015 02 13 begin*/
  /*delete the SS_IPC_SUPPORT*/
  /*mod for CQ00085367 by yunhail 2015 02 13 end*/
  CiString			        ImsiStr;		/**<	Subscriber ID (IMSI)string. The value is valid
											only if SIM status is CI_SIM_ST_READY and pin state is CI_SIM_PIN_ST_READY \sa */
  /*mod for CQ00085367 by yunhail 2015 02 13 begin*/
  /*delete the SS_IPC_SUPPORT*/
  /*mod for CQ00085367 by yunhail 2015 02 13 end*/                                         
  /*2015.01.13, mod by Xili for #517213, CQ00081907 end*/										
} CiSimPrimCardInd;

/* size is 6 digits, as specified in TS 11.11 & ETSI TS 131.102 */
/* one byte is added for the null terminator */
#define CI_SIM_ECC_MAX_LENGTH 7

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_IS_EMERGENCY_NUMBER_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimIsEmergencyNumberReq_struct {
  CHAR     eccDigitsStr[CI_SIM_ECC_MAX_LENGTH]; 		/**< Null-terminated dial string \sa CCI API Ref Manual */
} CiSimPrimIsEmergencyNumberReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_IS_EMERGENCY_NUMBER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimIsEmergencyNumberCnf_struct {
  CiSimRc         rc;					/**< Result code  \sa CiSimRc */
  CiBoolean       isEmergency;		/**< TRUE = number is an emergency call code; FALSE = otherwise \sa CCI API Ref Manual */
} CiSimPrimIsEmergencyNumberCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIM_OWNED_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSimOwnedInd_struct {

  CiBoolean       isOwned;			/**< TRUE = the SIM is owned; FALSE = the SIM is not owned \sa CCI API Ref Manual  */

}  CiSimPrimSimOwnedInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIM_CHANGED_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSimChangedInd_struct {

  CiBoolean       			isChanged;	 /**< TRUE = the current SIM card has changed; FALSE = the current SIM card has not changed  \sa CCI API Ref Manual */

} CiSimPrimSimChangedInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_DEVICE_STATUS_REQ"> */
typedef CiEmptyPrim CiSimPrimDeviceStatusReq;

/* <NOTINUSE> */
/**	 <paramref name="CI_SIM_PRIM_DEVICE_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimDeviceStatusCnf_struct{

	CiSimRc 				rc;			/**< Result code  \sa CiSimRc */
	CiSimStatus 			SIMstatus; 	/**< SIM status  \sa CiSimStatus */
	CiSimPinState 		pinState;	/**< Not in use  \sa CiSimPinState */
}CiSimPrimDeviceStatusCnf;
/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */

/* Michal Bukai - Virtual SIM support - START */
/**	 <paramref name="CI_SIM_PRIM_SET_VSIM_REQ"> */
typedef CiEmptyPrim CiSimPrimSetVSimReq;

/**	 <paramref name="CI_SIM_PRIM_SET_VSIM_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSetVSimCnf_struct{
	CiSimRc 		result; 	/**< Result code  \sa CiSimRc */
}CiSimPrimSetVSimCnf;

/**	 <paramref name="CI_SIM_PRIM_GET_VSIM_REQ"> */
typedef CiEmptyPrim CiSimPrimGetVSimReq;

/**	 <paramref name="CI_SIM_PRIM_GET_VSIM_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetVSimCnf_struct{
	CiSimRc 		result;		/**< Result code  \sa CiSimRc */
	CiBoolean       status;     /**< Virtual SIM status: TRUE = enabled; FALSE = disabled \sa CCI API Ref Manual */
}CiSimPrimGetVSimCnf;

/**< Michal Bukai - Virtual SIM support - END */
/*Michal Bukai - OTA support for AT&T - START*/
/*********************************************/

/* <INUSE> */
/** <paramref name="CI_SIM_PRIM_CHECK_MMI_STATE_IND"> */
typedef struct CiSimPrimCheckMMIStateInd_struct{
    UINT16  		len;							/**< Length of the proactive command data [1-255] */
 	UINT8    		data[CI_SIM_MAX_CMD_DATA_SIZE];	/**< Proactive command data for SIM refresh */
}CiSimPrimCheckMMIStateInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_CHECK_MMI_STATE_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimCheckMMIStateRsp_struct {
  CiSimMMIState	MMIState;	/**< Indicates if MMI state is IDLE or BUSY. \sa CiSimPinState */
  UINT8 generalResult; 	/**< General result of TR for SIM refresh if reject, used only when MMI state is busy */
  UINT8 addtionResult;  /**< Additional result of TR for SIM refresh if reject, 0 means no addtional result */
} CiSimPrimCheckMMIStateRsp;

/*********************************************/
/*  Michal Bukai - BT SAP support - START  */
/*******************************************/

/** \brief Values of BT SAP connection status */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_BTSAP_CONN_STAT_TAG {
    CI_SIM_BTSAP_OK = 0,    							/**< OK, Server can fulfill requirements */
    CI_SIM_BTSAP_UNABLE_TO_ESTABLISH_CONNECTION,        /**< Error, Server unable to establish connection */
    CI_SIM_BTSAP_MAX_MESSAGE_SIZE_NOT_SUPPORTED, 	 	/**< SIM personalization, lock phone with the first */
	CI_SIM_BTSAP_MAX_MESSAGE_SIZE_TOO_SMALL,			/**< Error, maximum message size by Client is too small */
	CI_SIM_BTSAP_ONGOING_CALL,							/**< OK, ongoing call */
    CI_SIM_BTSAP_NUM_STATE
} _CiSimBTSapConnectionStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM BT SAP session connection status.
 * \sa CI_SIM_BTSAP_CONN_STAT_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimBTSapConnectionStatus;
/**@}*/

/** \brief Values of subscription module availability status during BT SAP connection */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_BTSAP_STATUS_TAG {
    CI_SIM_BTSAP_STAT_ERR = 0,			/**< Unknown error */
    CI_SIM_BTSAP_STAT_CARD_RESET,		/**< Card reset */
    CI_SIM_BTSAP_STAT_CARD_NOT_ACC, 	/**< Card not accessible */
	CI_SIM_BTSAP_STAT_CARD_REMOVED,		/**< Card removed */
	CI_SIM_BTSAP_STAT_CARD_INSERTED,	/**< Card inserted */
    CI_SIM_BTSAP_STAT_CARD_RECOVERED,	/**< Card recovered */
    CI_SIM_BTSAP_STAT_NUM_STATE
} _CiSimBTSapStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM BT SAP subscription module availability status.
 * \sa CI_SIM_BTSAP_STATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimBTSapStatus;
/**@}*/


/** \brief Values of Transaction protocol setting during BT SAP connection */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_BTSAP_TP_TAG {
    CI_SIM_BTSAP_TP_T0 = 0,			/**< T=0 */
	CI_SIM_BTSAP_TP_T1,				/**< T=1 */
    CI_SIM_BTSAP_TP_NUM_STATE

} _CiSimTransportProtocol;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Transaction protocol setting.
 * \sa CI_SIM_BTSAP_TP_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimTransportProtocol;
/**@}*/


/** \brief Values of SIM control operations during BT SAP connection */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SIM_BTSAP_CONTROL_TAG {
    CI_SIM_BTSAP_POWER_OFF = 0,			/**< Power off the SIM/USIM */
    CI_SIM_BTSAP_POWER_ON,				/**< Power on the SIM/USIM */
    CI_SIM_BTSAP_RESET,					/**< Reset the SIM/USIM */
    CI_SIM_BTSAP_NUM_CONTROL

} _CiSimBTSapControl;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM control operation.
 * \sa CI_SIM_BTSAP_CONTROL_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimBTSapControl;
/**@}*/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_CONNECT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPConnectReq_struct {
    UINT16	maxMsgSize;		/**< Maximum message size requested by the Client */
} CiSimPrimBTSAPConnectReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_CONNECT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPConnectCnf_struct {
    CiSimBTSapConnectionStatus ConnectionStatus;		/**< Connection status. \sa CiSimBTSapConnectionStatus */
    UINT16 maxMsgSize;									/**< Maximum message size supported by comm. subsystem */
	CiSimRc ResultCode;									/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPConnectCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_DISCONNECT_REQ"> */
typedef CiEmptyPrim CiSimPrimBTSAPDisconnectReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_DISCONNECT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPDisconnectCnf_struct {
	CiSimRc ResultCode;			/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPDisconnectCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_TRANSFER_APDU_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPTransferApduReq_struct {
    CiSimCmdReq	CommandAPDU;		/**< SIM command; If command type is not APDU7816 it is coded according to Referenced Documents [12]; If command type is APDU7816 it is coded according to Referenced Documents [25]. \sa CiSimCmdReq */
} CiSimPrimBTSAPTransferApduReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_TRANSFER_APDU_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPTransferApduCnf_struct {
    CiSimCmdRsp ResponseAPDU;					/**< SIM response is optional and will be present only if command was processed without errors.
												Coding of the response depends on the APDU that was sent to the SIM/USIM
												If command type is not APDU7816 it is coded according to Referenced Documents [12]
												If command type is APDU7816 it is coded according to Referenced Documents [25]. \sa CiSimCmdRsp */
	CiSimRc ResultCode;							/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPTransferApduCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_TRANSFER_ATR_REQ"> */
typedef CiEmptyPrim CiSimPrimBTSAPTransferAtrReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_TRANSFER_ATR_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPTransferAtrCnf_struct {
    CiSimCmdRsp ATRData;						/**< ATR will be present only if there are no errors ATR is coded according to Referenced Documents [25] \sa CiSimCmdRsp */
	CiSimRc ResultCode;							/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPTransferAtrCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_SIM_CONTROL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPSimControlReq_struct {
    CiSimBTSapControl	Control;		/**< SIM control operation. \sa CiSimBTSapControl */
} CiSimPrimBTSAPSimControlReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_SIM_CONTROL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPSimControlCnf_struct {
	CiSimRc ResultCode;					/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPSimControlCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPStatusInd_struct {
	CiSimBTSapStatus StatusChange;		/**< Subscription module availability status. \sa CiSimBTSapStatus */
} CiSimPrimBTSAPStatusInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_STATUS_REQ"> */
typedef CiEmptyPrim CiSimPrimBTSAPStatusReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPStatusCnf_struct {
    CiSimBTSapStatus Status;					/**< Status of the subscription module availability  \sa CiSimBTSapStatus */
	CiSimRc ResultCode;							/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPStatusCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPSetTransportProtocolReq_struct {
    CiSimTransportProtocol	TransportProtocol;		/**< Transport Protocol type T=0 or T=1 \sa CiSimTransportProtocol */
} CiSimPrimBTSAPSetTransportProtocolReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_BTSAP_SET_TRANSPORT_PROTOCOL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimBTSAPSetTransportProtocolCnf_struct {
	CiSimRc ResultCode;			/**< result code. \sa CiSimRc */
} CiSimPrimBTSAPSetTransportProtocolCnf;

/*  Michal Bukai - BT SAP support - END   */
/******************************************/
/*Michal Bukai - Add IMSI to MEP code group - START*/
/***************************************************/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_MEP_ADD_IMSI_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimMEPAddIMSIReq_struct{

	/* # Start Contiguous Code Section # */
    CiPassword    		pass;					/**< The password is the personalization control key PCK. \sa CCI API Ref Manual */
	/* # End Contiguous Code Section # */
}CiSimPrimMEPAddIMSIReq;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_MEP_ADD_IMSI_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimMEPAddIMSICnf_struct {
  CiSimRc         rc;					/**< Result code  \sa CiSimRc */
} CiSimPrimMEPAddIMSICnf;

/**************************************************/
/*Michal Bukai - Add IMSI to MEP code group - END */
/**************************************************/

/*************************************/
/*Michal Bukai - SIM Logic CH - NFC\ISIM support - START*/
/*************************************/

/** \brief Values of Authentication types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMUICCEXTAUTHTYPE_TAG {
    CI_SIM_UICC_AUTH_IMS_AKA = 0,		/**< See 3GPP TS 31.103 section 7.1.2.1 */
    CI_SIM_UICC_AUTH_GBA_BOOT,			/**< See 3GPP TS 31.103 section 7.1.2.3 */
	CI_SIM_UICC_AUTH_GBA_NAF,			/**< See 3GPP TS 31.103 section 7.1.2.4 */
    CI_SIM_UICC_AUTH_HTTP_DIGEST,       /**< See 3GPP TS 31.103 section 7.1.2.2 */

    CI_SIM_UICC_AUTH_NUM_TYPES
} _CiSimUiccExtAuthType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Values of Authentication types.
 * \sa CISIMUICCEXTAUTHTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimUiccExtAuthType;
/**@}*/

#define CI_SIM_MAX_AID_SIZE		16

/** \brief DFName structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CISIMDfName_struct{
    UINT8	  	len;    						/**< Length */
    UINT8   	data[CI_SIM_MAX_AID_SIZE];		/**< Array of 1 to 16 bytes in hexadecimal format representing the AID of the UICC application */
} CISIMDfName;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimOpenLogicalChannelReq_struct
{
    CISIMDfName				DFname; 	/**< DFName is the AID. All selectable applications are represented in the UICC by an AID coded on 1 to 16 hexadecimal bytes. \sa CISIMDfName_struct */
    UINT16                  SessionId;  /**< A session ID to be used to open the logical channel id if assigned */
} CiSimPrimOpenLogicalChannelReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_OPEN_LOGICAL_CHANNEL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimOpenLogicalChannelCnf_struct
{
    CiSimRc 				rc;			/**< result code. \sa CiSimRc */
	UINT16					SessionId;	/**< A session ID to be used to target a specific application on the smart card using the logical channel mechanism. */
	UINT16					StatusWord; /**< Status Word is used to return if SIM fail with statusWord, just ingore if it is 0 */
} CiSimPrimOpenLogicalChannelCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimCloseLogicalChannelReq_struct
{
	UINT16					SessionId;	/**< A session ID to be used to target a specific application on the smart card using the logical channel mechanism. */
} CiSimPrimCloseLogicalChannelReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_CLOSE_LOGICAL_CHANNEL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimCloseLogicalChannelCnf_struct
{
    CiSimRc 				rc;			/**< result code. \sa CiSimRc */
} CiSimPrimCloseLogicalChannelCnf;
/*************************************/
/*Michal Bukai - SIM Logic CH - NFC\ISIM support - END  */
/*************************************/

/* Add by jungle for CQ00057999 on 2014-04-02 Begin */
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_APP_PIN_REQ"> */
typedef CiEmptyPrim CiSimPrimAppPinReq;

/** \brief AppPinInfoArr structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct AppPinInfoArrTag
{
    UINT8      AIDlength;
    UINT8      AIDdata[UICC_AID_MAX_SIZE];

    CiBoolean  isPIN1Enabled;
    UINT8      PIN1RetryCount;
    UINT8      PUK1RetryCount;
    
    CiBoolean  isPIN2Enabled;
    UINT8      PIN2RetryCount;
    UINT8      PUK2RetryCount; 
}AppPinInfoArr;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_APP_PIN_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimAppPinCnf_struct
{
    CiSimRc             rc;
    UINT8               AIDnum;
    AppPinInfoArr       appPinInfo[UICC_MAX_AID_COUNT];    
}CiSimPrimAppPinCnf;
/* Add by jungle for CQ00057999 on 2014-04-02 End */

/****************************************************/
/*Michal Bukai - additional SIMAT primitives - START*/
/****************************************************/

/** \brief values of SIMAT CC status response */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMSIMATCCSTATUS_TAG {
    CI_SIM_SIMAT_CC_STATUS_NO_CHANGE = 0,			/**< The request was not modified by SIMAT CC */
    CI_SIM_SIMAT_CC_STATUS_CALL_CHANGED,			/**< SIMAT CC changed a call setup request */
	CI_SIM_SIMAT_CC_STATUS_CALL_BARRED,				/**< SIMAT CC barred a call setup request */
	CI_SIM_SIMAT_CC_STATUS_CALL_REPLACED_BY_SS,		/**< SIMAT CC replaced a call setup request with an SS operation */
	CI_SIM_SIMAT_CC_STATUS_SS_CHANGED,				/**< SIMAT CC changed an SS operation */
	CI_SIM_SIMAT_CC_STATUS_SS_BARRED,				/**< SIMAT CC barred an SS operation  */
	CI_SIM_SIMAT_CC_STATUS_SS_REPLACED_BY_CALL,		/**< SIMAT CC replaced an SS operation request with call setup  */
	CI_SIM_SIMAT_CC_STATUS_SS_FAILED,				/**< SIMAT CC changed an SS operation or replaced a call setup request or a USSD operation with an SS operation and SS operation failed  */
	CI_SIM_SIMAT_CC_STATUS_CALL_FAILED,				/**< SIMAT CC changed a call setup request or replaced an SS operation or a USSD operation with a call setup request and call setup failed  */
	CI_SIM_SIMAT_CC_STATUS_SS_OK,					/**< SIMAT CC changed an SS operation or replaced a call setup request or a USSD operation with an SS operation and SS operation is OK  */
	CI_SIM_SIMAT_CC_STATUS_USSD_FAILED,				/**< SIMAT CC changed a USSD operation or replaced a call setup request or an SS operation with a USSD operation and USSD operation failed  */
	CI_SIM_SIMAT_CC_STATUS_USSD_OK,					/**< SIMAT CC changed a USSD operation or replaced a call setup request or an SS operation with a USSD operation and USSD operation is OK  */
	CI_SIM_SIMAT_CC_STATUS_CALL_REPLACED_BY_USSD,	/**< SIMAT CC replaced a call setup request with a USSD operation  */
	CI_SIM_SIMAT_CC_STATUS_SS_REPLACED_BY_USSD,		/**< SIMAT CC replaced an SS operation request with a USSD operation  */
	CI_SIM_SIMAT_CC_STATUS_USSD_CHANGED,			/**< SIMAT CC changed a USSD operation */
	CI_SIM_SIMAT_CC_STATUS_USSD_BARRED,				/**< SIMAT CC barred a USSD operation */
	CI_SIM_SIMAT_CC_STATUS_USSD_REPLACED_BY_CALL ,	/**< SIMAT CC replaced a USSD operation with call setup */
	CI_SIM_SIMAT_CC_STATUS_USSD_REPLACED_BY_SS,	/**< SIMAT CC replaced a USSD operation with an SS operation  */

    CI_SIM_SIMAT_CC_STATUS_NUM_TYPES
}_CiSimSIMATCcStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIMAT CC status response type
 * \sa CISIMSIMATCCSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimSIMATCcStatus;
/**@}*/

/** \brief SIMAT CC operation values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMSIMATCCOPERATION_TAG {
    CI_SIM_SIMAT_CC_CALL_SET_UP = 0,		/**< Call setup */
    CI_SIM_SIMAT_CC_SS_OPERATION,			/**< SS operation */
	CI_SIM_SIMAT_CC_USSD_OPERATION,			/**< USSD operation */

    CI_SIM_SIMAT_CC_OPERATION_NUM_TYPES 
}_CiSimSIMATCcOperation;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIMAT CC operation type
 * \sa CISIMSIMATCCOPERATION_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimSIMATCcOperation;
/**@}*/

/** \brief values of SIMAT SM status response */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMSIMATSMSTATUS_TAG {
    CI_SIM_SIMAT_SM_STATUS_NO_CHANGE = 0,	/**< SIMAT SM did not modify an SMS request */
    CI_SIM_SIMAT_SM_STATUS_CHANGED,			/**< SIMAT SM changed an SMS destination address */
	CI_SIM_SIMAT_SM_STATUS_BARRED,			/**< SIMAT CC barred a call setup request */
	
    CI_SIM_SIMAT_SM_STATUS_NUM_TYPES
}_CiSimSIMATSmStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIMAT SM status response
 * \sa CISIMSIMATSMSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimSIMATSmStatus;
/**@}*/

/* [Start] EV - New fields for RIL_Stk_CallCtrl_Result implementation */
/** \brief values of SIMAT CC control result */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMCCCONTROLRESULT_TAG {
    CI_SIM_CC_NO_CONTROL,			/**< SIMAT CC did not allow a  request */
    CI_SIM_CC_ALLOWED_NO_MOD,		/**< SIMAT CC did allow a request without modifications */
	CI_SIM_CC_NOT_ALLOWED,			/**< SIMAT CC barred a request */
	CI_SIM_CC_ALLOWED_WITH_MOD,		/**< SIMAT CC did allow a request with modifications */

    CI_SIM_CC_NUM_TYPES
}_CiSimCcControlResult;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIMAT CC control result
 * \sa CISIMCCCONTROLRESULT_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimCcControlResult;
/**@}*/

/** \brief values of SIMAT CC call type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMCCCALLTYPE_TAG {
    CI_SIM_CC_CALL_TYPE_MO_VOICE,	/**< SIMAT CC original call type is MO voice */
    CI_SIM_CC_CALL_TYPE_MO_SMS,		/**< SIMAT CC original call type is MO SMS */
	CI_SIM_CC_CALL_TYPE_MO_SS,		/**< SIMAT CC original call type is MO SS */
	CI_SIM_CC_CALL_TYPE_MO_USSD,	/**< SIMAT CC original call type is MO USSD */
	CI_SIM_CC_CALL_PDP_CTXT,		/**< SIMAT CC original call type is PDP context (not supported) */

    CI_SIM_CC_CALL_TYPE_NUM_TYPES
}_CiSimCcCallType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIMAT CC call type
 * \sa CISIMCCCALLTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimCcCallType;
/**@}*/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_CC_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSIMATCcStatusInd_struct{
	CiSimSIMATCcStatus		status;			/**< SIMAT CC status response  \sa CiSimSIMATCcStatus */
	CiSimSIMATCcOperation	OperationType;	/**< The operation type that was passed to USIM  \sa CiSimSIMATCcOperation */
	CiBoolean				alphaIdPresent;	/**< Indicates whether the SIMAT CC status response has an accompanying alphanumeric ID string \sa CCI API Ref Manual */
	CiSimatAlphaTag			alphaId;		/**< Optional alphanumeric ID \sa CiSimatAlphaTag_struct  */

    CiBoolean               addressPresent; /**< Indicates whether the SIMAT CC status response has a changed called number \sa CCI API Ref Manual */
    CiAddressInfo           AddressInfo;    /**< Optional changed called number \sa CiAddressInfo_struct  */

    /* Add by jungle for CQ00057794 on 2014-03-31 Begin */
    UINT8                   ccRawDataLen;
    UINT8                   ccRawData[255];                
    /* Add by jungle for CQ00057794 on 2014-03-31 End */    
}CiSimPrimSIMATCcStatusInd;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_SEND_CALL_SETUP_RSP_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSIMATSendCallSetupRspInd_struct{
	CiBoolean			status;	/**< Response sent to SIMAT; TRUE: call setup is OK; FALSE: call setup failed. \sa CCI API Ref Manual */

    UINT8 generalResult;        /** If status is set to FALSE, will fill general result to notify AP if it is ME(0x20) or NET(0x21) failed */
    UINT8 additionResult;       /** If addtion result is present will fill it, else set it to 0x00 */
}CiSimPrimSIMATSendCallSetupRspInd;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_SEND_SS_USSD_RSP_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSIMATSendSsUssdRspInd_struct{
	CiBoolean				status;	/**< Response sent to SIMAT; TRUE: SS or USSD operation is OK; FALSE: SS or USSD operation failed. \sa CCI API Ref Manual */
	CiSimSIMATCcOperation	OperationType;	/**< The operation type that was passed to USIM  \sa CiSimSIMATCcOperation */
}CiSimPrimSIMATSendSsUssdRspInd;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_SM_CONTROL_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSIMATSmControlStatusInd_struct{
	CiSimSIMATSmStatus	status;			/**< SIMAT SM status response  \sa CiSimSIMATSmStatus */
	CiBoolean			alphaIdPresent;	/**< Indicates whether the SIMAT SM status response has an accompanying alphanumeric ID string \sa CCI API Ref Manual */
	CiSimatAlphaTag		alphaId;		/**< Optional alphanumeric ID \sa CiSimatAlphaTag_struct  */
    /* Add by jungle for CQ00057794 on 2014-03-31 Begin */
    UINT8               ccRawDataLen;
    UINT8               ccRawData[255];                
    /* Add by jungle for CQ00057794 on 2014-03-31 End */    
}CiSimPrimSIMATSmControlStatusInd;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_SIMAT_SEND_SM_RSP_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimSIMATSendSmRspInd_struct{
	CiBoolean			status;	/**< Response sent to SIMAT; TRUE: SM operation is OK;FALSE: SM operation failed. \sa CCI API Ref Manual */

    UINT8 generalResult;        /** If status is set to FALSE, will fill general result to notify AP if it is ME(0x20) or RP-ERR(0x35) or SMS control(0x39) failed */
    UINT8 additionResult;       /** If addtion result is present will fill it, else set it to 0x00 */
}CiSimPrimSIMATSendSmRspInd;



/****************************************************/
/*Michal Bukai - additional SIMAT primitives - END  */
/****************************************************/
/**************************************/
/*Michal Bukai - RSAP support - START */
/**************************************/

/** \brief Values of RSAP service type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMRSAPSERVICETYPE_TAG {
    CI_SIM_RSAP_SERVICE_RECONNECT = 0,	/**< Reconnect to local or remote SIM */
    CI_SIM_RSAP_SERVICE_DISCONNECT,		/**< Disconnect from local or remote SIM */
    CI_SIM_RSAP_SERVICE_NUM_TYPES 		
} _CiSimRsapServiceType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief RSAP service type.
 * \sa CISIMRSAPSERVICETYPE_TAG */ 
/** \remarks Common Data Section */
typedef UINT8 CiSimRsapServiceType;
/**@}*/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_CONN_REQ_IND"> */
typedef CiEmptyPrim CiSimPrimRsapConnReqInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_CONN_REQ_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapConnReqRsp_struct {
	CiSimRc         	ResultCode;			/**< Result code  \sa CiSimRc */
	CiSimBTSapConnectionStatus	ConnecitonStatus;	/**< RSAP connection status  \sa CiSimBTSapConnectionStatus */
}CiSimPrimRsapConnReqRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_STAT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapStatReq_struct {
	CiSimBTSapStatus	status;	/**< RSAP connection status  \sa CiSimBTSapStatus */
}CiSimPrimRsapStatReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_STAT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapStatCnf_struct {
	CiSimRc   	ResultCode;		/**< Result code  \sa CiSimRc */
}CiSimPrimRsapStatCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_DISCONN_REQ_IND"> */
typedef CiEmptyPrim CiSimPrimRsapDisconnReqInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_DISCONN_REQ_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapDisconnReqRsp_struct {
	CiSimRc      	ResultCode;		/**< Result code  \sa CiSimRc */
}CiSimPrimRsapDisconnReqRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_GET_ATR_IND"> */
typedef CiEmptyPrim CiSimPrimRsapGetAtrInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_GET_ATR_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapGetAtrRsp_struct {
	CiSimRc         	ResultCode;	/**< Result code  \sa CiSimRc */
	CiSimCmdRsp			ATRData;	/**< ATR will be present only if there are no errors.\sa CiSimCmdRsp */
}CiSimPrimRsapGetAtrRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_GET_STATUS_REQ_IND"> */
typedef CiEmptyPrim CiSimPrimRsapGetStatusInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSetTranPReqInd_struct {
    CiSimTransportProtocol	TransportProtocol;		/**< Transport Protocol type T=0 or T=1 \sa CiSimTransportProtocol */
}CiSimPrimRsapSetTranPReqInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SET_TRAN_P_REQ_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSetTranPReqRsp_struct {
	CiSimRc         	ResultCode;	/**< Result code  \sa CiSimRc */
}CiSimPrimRsapSetTranPReqRsp;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSimControlReqInd_struct {
	CiSimBTSapControl	Control;		/**< SIM control operation. \sa CiSimBTSapControl */
}CiSimPrimRsapSimControlReqInd;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SIM_CONTROL_REQ_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSimControlReqRsp_struct {
	CiSimRc         	ResultCode;	/**< Result code  \sa CiSimRc */
}CiSimPrimRsapSimControlReqRsp;


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SIM_SELECT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSimSelectReq_struct {
	CiSimRsapServiceType ServiceType;		/**< Type of operation required: reconnect or disconnect  \sa CiSimRsapServiceType */
	CiBoolean     	     RemoteSIM; 		/**< TRUE - Select remote SIM; FALSE - Select local SIM	\sa CCI API Ref Manual */
}CiSimPrimRsapSimSelectReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_SIM_SELECT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapSimSelectCnf_struct {
	CiSimRc         	ResultCode;	/**< Result code  \sa CiSimRc */
}CiSimPrimRsapSimSelectCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_RSAP_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapStatusInd_struct {
	CiSimBTSapStatus	status;	/**< RSAP connection status  \sa CiSimBTSapStatus */
}CiSimPrimRsapStatusInd;

/* <INUSE> */
/**  <paramref name="CI_SIM_PRIM_RSAP_TRANSFER_APDU_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapTransferAPDUInd_struct {
	CiSimCmdReq			CommandAPDU;	/**< SIM command.\sa CiSimCmdReq */
}CiSimPrimRsapTransferAPDUInd;

/* <INUSE> */
/**  <paramref name="CI_SIM_PRIM_RSAP_TRANSFER_APDU_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimRsapTransferAPDURsp_struct {
	CiSimRc         	ResultCode;		/**< Result code  \sa CiSimRc */
	CiSimCmdRsp			ResponseAPDU;	/**< SIM response is optional and is only sent if the command was processed without errors.\sa CiSimCmdRsp */
}CiSimPrimRsapTransferAPDURsp;

/**************************************/
/*Michal Bukai - RSAP support - END   */
/**************************************/


//ICC ID feature 
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ICCID_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimIccidInd_struct {
	CiSimIccid	iccid;	/**< ICC Id value \sa CiSimIccid */
}CiSimPrimIccidInd;

/*2013.12.11, added by Xili for CQ00051618, begin*/
/* Delete by jungle for CQ00057999 on 2014-04-02 */
//ISIM AID feature 
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ISIM_AID_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimIsimAidInd_struct {
    CiSimPinState         isimPinState;
    UINT8                 isimAIDlength;
    UINT8                 isimAIDdata[UICC_AID_MAX_SIZE];	/**< ISIM Aid value \sa CiSimIsimAid */
}CiSimPrimIsimAidInd;
/*2013.12.11, added by Xili for CQ00051618, end*/

/*2014.05.08, added by Xili for CQ00060947, begin*/
/** \brief values of EF_AD MS operation mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum EfAdMsOperationModeTag
{
    EF_AD_MS_OPERN_NORMAL               = 0x00, /* normal operation */
    EF_AD_MS_OPERN_TA                   = 0x80, /* type approval operation */
    EF_AD_MS_OPERN_NORMAL_PLUS_SPECIFIC = 0x01, /* normal + specific operation */
    EF_AD_MS_OPERN_TA_PLUS_SPECIFIC     = 0x81, /* type approval + specific operation */
    EF_AD_MS_OPERN_MAINTENANCE          = 0x02, /* maintenance operation */
    EF_AD_MS_OPERN_CELL_TEST            = 0x04  /* cell test operation */
}_EfAdMsOperationMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief EF_AD MS operation mode
 * \sa EfAdMsOperationMode_Tag */
/** \remarks Common Data Section */
typedef UINT8 EfAdMsOperationMode;
/**@}*/


//ADMIN DATA feature 
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ADMIN_DATA_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimAdminDataInd_struct
{
    EfAdMsOperationMode                 efadmsOperationMode;
    /* MSB is byte 1 2 of AD file */
    UINT8                            mncLength;
    UINT32                           additionalInfo;    
}CiSimPrimAdminDataInd;
/*2014.05.08, added by Xili for CQ00060947, end*/

/*2015.03.19, mod by Xili for adding ECC list indication, CQ00088196 begin*/
#define CI_SIM_ECC_LIST_MAX_SIZE       20

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief EF_ECC LIST
 * \sa CiSimEmergencyCallCode_Tag */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSimEmergencyCallCode_struct
{
    UINT8                  serviceCategory;
    CHAR                   EmergencyCallCode[CI_SIM_ECC_MAX_LENGTH];
}CiSimEmergencyCallCode;
/**@}*/

//ECC LIST feature 
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_ECC_LIST_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEccListInd_struct
{  
  UINT8                      numEccsOnSim;    
  CiSimEmergencyCallCode     eccList[CI_SIM_ECC_LIST_MAX_SIZE];
}  CiSimPrimEccListInd;
/*2015.03.19, mod by Xili for adding ECC list indication, CQ00088196 end*/


/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_ICCID_REQ"> */
typedef CiEmptyPrim CiSimPrimGetIccidReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_ICCID_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetIccidCnf_struct {
	CiSimRc         	ResultCode;		/**< Result code  \sa CiSimRc */
	CiSimIccid			iccid;			/**< ICC Id value \sa CiSimIccid */
}CiSimPrimGetIccidCnf;
//ICC ID feature

#define MAX_LENGTH_EAP_DATA		256
#define MAX_LENGTH_EAP_METHOD	8

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_EAP_AUTHENTICATION_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEAPAuthenticationReq_struct{
	CISIMDfName	DFname;
	UINT8		EAPMethod[MAX_LENGTH_EAP_METHOD];
	UINT8		length;
	UINT8		EAPPacketData[MAX_LENGTH_EAP_DATA];
	UINT16		DFeap;
}CiSimPrimEAPAuthenticationReq;

/**	 <paramref name="CI_SIM_PRIM_EAP_AUTHENTICATION_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimEAPAuthenticationCnf_struct{
	CiSimRc		rc;		/**< Result code  \sa CiSimRc */
	UINT8		length;
	UINT8		EAPPacketResponse[MAX_LENGTH_EAP_DATA];
	UINT32		EAPSessionID;
}CiSimPrimEAPAuthenticationCnf;
/** \brief  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISIMACTAPPYPE_TAG {
    CI_SIM_ACT_APP_NONE = 0,	/**< no SIM or USIM active */
    CI_SIM_ACT_APP_SIM,			/**< active application is SIM */
    CI_SIM_ACT_APP_USIM,		/**< active application is USIM, followed by <AID> */
	CI_SIM_ACT_APP_NUM_TYPES
} _CiSimActAppType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief RSAP service type.
 * \sa CISIMRSAPSERVICETYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiSimActAppType;
/**@}*/

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetNumUiccApplicationsReq_struct{
	UINT8		option;
}CiSimPrimGetNumUiccApplicationsReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_NUM_UICC_APPLICATIONS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetNumUiccApplicationsCnf_struct{
	CiSimRc				rc;								/**< Result code  \sa CiSimRc */
	UINT16				NumUiccApplication;
	CiSimActAppType		active_application;
	CISIMDfName			aid;
}CiSimPrimGetNumUiccApplicationsCnf;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetUiccApplicationsInfoReq_struct{
	UINT8		index;
}CiSimPrimGetUiccApplicationsInfoReq;

#define MAX_EF_DIR_LENGTH		127

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_GET_UICC_APPLICATIONS_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimGetUiccApplicationsInfoCnf_struct{
	CiSimRc				rc;								/**< Result code  \sa CiSimRc */
	UINT8				responseLen;
	UINT8				response[MAX_EF_DIR_LENGTH];
	UINT8				index;
}CiSimPrimGetUiccApplicationsInfoCnf;

typedef enum CISIMEAPPARAMETERS_TAG {
	CI_SIM_EAP_KEYS = 1,
	CI_SIM_EAP_STATUS,
	CI_SIM_EAP_IDENTITY,
	CI_SIM_EAP_PSEUDONYM,
	CI_SIM_EAP_NUM_TYPES
}_CiSimEapParameters;

typedef UINT8 CiSimEapParameters;


/* <INUSE> */
/**	 <paramref name="CI_SIM_EAP_RETRIEVE_PARAMETERS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimEapRetrieveParametersReq_struct{
	UINT32				EAPSessionID;
	CiSimEapParameters	EAPParameters;
}CiSimEapRetrieveParametersReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_EAP_RETRIEVE_PARAMETERS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimEapRetrieveParametersCnf_struct{
	CiSimRc		rc;								/**< Result code  \sa CiSimRc */
	UINT8		length;
	UINT8		EAPParamResp[MAX_LENGTH_EAP_DATA];
}CiSimEapRetrieveParametersCnf;

/*CQ00113882, Cgliu, 2019-02-26, Begin*/
/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_UPDATE_COUNT_REQ"> */
typedef CiEmptyPrim CiSimPrimUpdateCountReq;

/* <INUSE> */
/**	 <paramref name="CI_SIM_PRIM_UPDATE_COUNT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSimPrimUpdateCountCnf_struct
{   
    CiSimRc             rc;          /**< Result code  \sa CiSimRc */
    UINT32              totalCount;
    UINT16              startHfn; 
    UINT32              updateStartHfnCount;    
    UINT16              keyps; 
    UINT32              updateKeypsCount;    
    UINT16              kc; 
    UINT32              updateKcCount; 
    UINT16              psloci; 
    UINT32              updatePsLociCount;  
    UINT16              kcGprs; 
    UINT32              updateKcGprsCount;  
    UINT16              loci; 
    UINT32              updateLociCount;  
    UINT16              keys; 
    UINT32              updateKeysCount;   
    /*CQ00113882, Cgliu, 2019-11-27, Begin*/    
    UINT16              epsloci;        /*6FE3*/
    UINT32              updateEpslociCount; 
    UINT16              epsnsc;         /*6FE4*/
    UINT32              updateEpsnscCount;  
    /*CQ00113882, Cgliu, 2019-11-27, End  */     
}CiSimPrimUpdateCountCnf;
/*CQ00113882, Cgliu, 2019-02-26, End  */


#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_sim_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_SIM_NUM_CUST_PRIM is set to 0 in the "ci_sim_cust.h" file.
 */
#include "ci_sim_cust.h"

#define CI_SIM_NUM_PRIM ( CI_SIM_NUM_COMMON_PRIM + CI_SIM_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_SIM_NUM_PRIM CI_SIM_NUM_COMMON_PRIM

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

#endif /* _CI_SIM_H_ */


/*                      end of ci_sim.h
--------------------------------------------------------------------------- */

