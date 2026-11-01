/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_ss.h
Description : Data types file for the ss service group

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

#if !defined(_CI_SS_H_)
#define _CI_SS_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_api_types.h"
/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_SS_VER_MAJOR 3
//#define CI_SS_VER_MINOR 1

//#define CI_SS_VER_MAJOR 3
//#define CI_SS_VER_MINOR 0
#define CI_SS_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version



/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_SS_PRIM {
  CI_SS_PRIM_GET_CLIP_STATUS_REQ = 1, 	/**< \brief Requests status information for the CLIP (Calling Line Identification Presentation) supplementary service
										 * \details Requests the local CLIP presentation option setting and interrogates the CLIP provision status at the network.
 *   If enabled, CLIP information is reported by the CI_CC_PRIM_CLIP_INFO_IND indication.
 *   If the CLIP service is provisioned, local CLIP presentation is enabled by default.
 *   There is no reason for an unsuccessful result. */
  CI_SS_PRIM_GET_CLIP_STATUS_CNF,		/**< \brief Confirms the request for the local CLIP presentation and provision status  \details Reports the local CLIP presentation option setting and the CLIP provision status at the network.
  *  If the CLIP service is provisioned, local CLIP presentation is enabled by default.
  *  There is no reason for an unsuccessful result. */
  CI_SS_PRIM_SET_CLIP_OPTION_REQ,		/**< \brief Requests to set the local presentation option for CLIP (Calling Line Identification Presentation) information on incoming calls
										 * \details This option affects only the presentation of CLIP information at the mobile.
										 * It does not affect the operation of the CLIP service at the network.
										 * The provisioned setting for CLIP is unchanged.
  *  The default value is 1 (CLIP presentation enabled). This request fails if the CLIP  service is not provisioned. */
  CI_SS_PRIM_SET_CLIP_OPTION_CNF,       /**< \brief Confirms a request to set the local presentation option for CLIP (Calling Line Identification Presentation) information on incoming calls
										 * \details This option only affects the presentation of CLIP information at the mobile.
										 * It does not affect the operation of the CLIP service at the network.
										 * The provisioned setting for CLIP is unchanged. */
  CI_SS_PRIM_GET_CLIR_STATUS_REQ,       /**< \brief Requests status information for the CLIR (Calling Line Identification Restriction) supplementary service.
										 * \details Requests the local CLIR presentation option setting and interrogates the CLIR provision status at the network.*/
  CI_SS_PRIM_GET_CLIR_STATUS_CNF,       /**< \brief Confirms a request for status information of the CLIR (Calling Line Identification Restriction) supplementary service
										 * \details Reports the local CLIR presentation option setting and the CLIR provision status at the network.
  *  See the CI_SS_PRIM_SET_CLIR_OPTION_REQ request for definitions of the temporary and permanent CLIR settings.
  *  There is no reason for an unsuccessful result.*/
  CI_SS_PRIM_SET_CLIR_OPTION_REQ,       /**< \brief Requests to set the local option to provide CLIR (Calling Line Identification Restriction) information on outgoing calls
										 * \details Unlike the CLIP service, the CLIR setting can override the provision setting. The new setting is used as a temporary setting for all outgoing calls
 *   until it is revoked by using this request to set the local parameter to 0.
 *   The Provision setting is still preserved as the permanent setting.
 *   The default value is 2 (CLIR presentation allowed).
 *   The request fails if the CLIR service is not provisioned. */
  CI_SS_PRIM_SET_CLIR_OPTION_CNF,       /**< \brief Confirms a request to set the local option to provide CLIR (Calling Line Identification Restriction) information on outgoing
  *  calls  \details */
  CI_SS_PRIM_GET_COLP_STATUS_REQ,       /**< \brief Requests status information for the CoLP (Connected Line Identification Presentation) supplementary service
										 * \details Requests the local CoLP presentation option setting and interrogates the CoLP provision status at the network.
  *  If enabled, CoLP information is reported by CI_CC_PRIM_COLP_INFO_IND. */
  CI_SS_PRIM_GET_COLP_STATUS_CNF,       /**< \brief Confirms a request to get the CoLP (Connected Line Identification Presentation) supplementary service
										 * \details Reports the local CoLP presentation option setting and the CoLP provision status at the network.
  *  There is no reason for an unsuccessful result. */
  CI_SS_PRIM_SET_COLP_OPTION_REQ,       /**< \brief Requests to enable or disable local presentation of CoLP (Connected Line Identification Presentation) information for outgoing calls  \details */
  CI_SS_PRIM_SET_COLP_OPTION_CNF,       /**< \brief Confirms a request to set the local CoLP (Connected Line Identification Presentation) option
										 * \details  This option only affects the local presentation of CoLP information (at the mobile); it does not affect the operation of the
  *  CoLP service at the network. The provisioned setting for CoLP is unchanged.*/
  CI_SS_PRIM_GET_CUG_CONFIG_REQ,        /**< \brief Requests current configuration information for the CUG (Closed User Groups) supplementary service
										 * \details If the provisioned CUG information has been temporarily overridden, this request retrieves the temporary CUG
  *  configuration information.*/
  CI_SS_PRIM_GET_CUG_CONFIG_CNF,        /**< \brief Confirms a request to get current configuration information for the CUG (Closed User Groups) supplementary service
										 * \details If the provisioned CUG information has been temporarily overridden, the temporary CUG configuration information is
  *  reported. Otherwise, the CUG configuration information is not meaningful. See CI_SS_PRIM_SET_CUG_CONFIG_REQ for more
  *  information on the CUG override settings. By default, CUG temporary mode is disabled. The provisioned (preferential) CUG
  *  index is used for all CUG-related outgoing calls, until temporary mode is enabled.
  *  There is no reason for an unsuccessful result.*/
  CI_SS_PRIM_SET_CUG_CONFIG_REQ,        /**< \brief Requests to set up configuration information for the CUG (Closed User Groups) supplementary service
										 * \details This request can be used for the following operations:
  *  Enable CUG temporary mode, and use supplied data to override the provisioned CUG information
  *  Stay in CUG temporary mode and use supplied data to modify current information
  *  Disable (revoke) CUG temporary mode, and revert to the provisioned CUG information
  *  Current CUG information (provisioned or overridden) is used for all CUG-related outgoing calls until the information is
  *  changed, or the CUG temporary mode is revoked.
 *   If this request is used to disable CUG temporary mode, the CUG configuration information is not applicable, and is ignored.
 *   CUG temporary mode is disabled by default, and the mobile uses the provisioned CUG information for all CUG-related outgoing calls. */
  CI_SS_PRIM_SET_CUG_CONFIG_CNF,        /**< \brief Confirms the request for new configuration information for the CUG supplementary service  \details */
  CI_SS_PRIM_GET_CNAP_STATUS_REQ, /**< \brief Requests status information for the CNAP (Calling Name Presentation) supplementary service
								   * \details Requests the local CNAP presentation option setting and interrogates the CNAP provision status at the network.*/
  //Michal Bukai - CNAP support
  CI_SS_PRIM_GET_CNAP_STATUS_CNF, /**< \brief Confirms the request to get the local CNAP settings and provision status  \details */
  //Michal Bukai - CNAP support
  CI_SS_PRIM_SET_CNAP_OPTION_REQ, /**< \brief Requests to update CNAP presentation options in the communication subsystem  \details */  //Michal Bukai - CNAP support
  CI_SS_PRIM_SET_CNAP_OPTION_CNF, /**< \brief Confirms the request to update CNAP presentation options   \details */   //Michal Bukai - CNAP support
  CI_SS_PRIM_REGISTER_CF_INFO_REQ,		/**< \brief Requests registration of new call forwarding information
										 * \details This request attempts to register the following call forwarding information:
  *  The class (or classes) of service
  *  The call forwarding condition (or conditions) desired
  *  The call forwarding number, optionally with an accompanying subaddress
  *  More than one class of service can be indicated in this request. This can be achieved by setting the appropriate bits in the
  *  Classes parameter. For more information, see the CiSsCfRegisterInfo structure definition.
  *  The call forwarding number must be:
  *  A valid directory number
  *  Not the mobile subscriber's own number
  *  Not a special service number (such as "911" or "411")
  *  Call forwarding must be registered separately for each of the supported conditions. However, the "All Call Forwarding" or
  *  "All Conditional Call Forwarding" can be used to set up multiple conditions in a single registration request. A registration
  *  request is sent to the network, which can accept or reject the request. */
  CI_SS_PRIM_REGISTER_CF_INFO_CNF,      /**< \brief Confirms a call forwarding registration request
										 * \details On successful registration, the call forwarding service is automatically activated with the registered information.
  *  This information remains in effect until it is changed by another registration request, or until it is erased. */
  CI_SS_PRIM_ERASE_CF_INFO_REQ,         /**< \brief Requests that call forwarding information be erased
										 * \details This request attempts to erase the following call forwarding information:
  *  The class (or classes) of service
  *  The call forwarding condition (or conditions) desired
  *  More than one class of service can be indicated in this request. This can be achieved by setting the appropriate bits in
  *  the Classes parameter. For more information, see the CiSsCfEraseInfo structure definition.
  *  Call forwarding must be erased separately for each of the supported conditions. However, the "All Call Forwarding" or
  *  "All Conditional Call Forwarding" can be used to set up multiple conditions in a single erase request.
  *  Note that a registration request with updated information effectively erases (and overrides) the information set up by
  *  the previous registration. An erase request is sent to the network, which can accept or reject the request. */
  CI_SS_PRIM_ERASE_CF_INFO_CNF,         /**< \brief Confirms a request to erase call forwarding information
										 * \details When call forwarding information is successfully erased, previously registered call forwarding information is erased at the network, and the call forwarding
  *  service is automatically deactivated. */
  CI_SS_PRIM_GET_CF_REASONS_REQ,        /**< \brief Requests a list of supported call forwarding reasons  \details */
  CI_SS_PRIM_GET_CF_REASONS_CNF,        /**< \brief Confirms a request to get a list of supported call forwarding reasons
										 * \details This primitive provides information as requested by the "AT+CCFC=?" test command.
  *  There is no reason for an unsuccessful result. */
  CI_SS_PRIM_SET_CF_ACTIVATION_REQ,     /**< \brief Requests activation or deactivation of a call forwarding service
										 * \details Call forwarding is automatically activated by the network (for appropriate classes and reasons) on successful registration.
  *  See the CI_SS_PRIM_REGISTER_CF_INFO_REQ request (and its confirmation) for more information.
  *  Call forwarding is automatically deactivated by the network (for appropriate classes and reasons) on successful erasure.
  *  See the CI_SS_PRIM_ERASE_CF_INFO_REQ request (and its confirmation) for more information. This request fails if the
  *  call forwarding service is not provisioned. */
  CI_SS_PRIM_SET_CF_ACTIVATION_CNF,     /**< \brief Confirms a request to activate or deactivate a call forwarding service
										 * \details The network rejects the activation request if it conflicts with other supplementary services.*/
  CI_SS_PRIM_INTERROGATE_CF_INFO_REQ,   /**< \brief Requests the interrogation of call forwarding services
										 * \details  An interrogation request is sent to the network, which can accept or reject the request. */
  CI_SS_PRIM_INTERROGATE_CF_INFO_CNF,   /**< \brief Confirms the request to interrogate the call forwarding services
										 * \details If the Result parameter indicates an error, the call forwarding registration information is not likely to be meaningful.*/
  CI_SS_PRIM_SET_CW_ACTIVATION_REQ,     /**< \brief Requests activation or deactivation of call waiting (CW) for a specified class of service
										 * \details Activates or deactivates the call waiting service at the network. If provisioned, call waiting is activated by default. */
  CI_SS_PRIM_SET_CW_ACTIVATION_CNF,     /**< \brief Confirms the request to activate or deactivate call waiting for a specified class of service.
										 * \details The network rejects the activation request if it conflicts with other supplementary services.*/
  CI_SS_PRIM_GET_CW_OPTION_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_CW_OPTION_CNF, /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_CW_OPTION_REQ,         /**< \brief Requests to set the local presentation option for incoming call waiting indications
										 * \details Call waiting information (if enabled) is reported by CI_CC_PRIM_CALL_WAITING_IND.
If the call waiting service has been deactivated at the network, a CI_SS_PRIM_SET_CW_OPTION_REQ request to enable local call waiting indications has no effect until the service is re-activated by a CI_SS_PRIM_SET_CW_ACTIVATION_REQ request.
Local call waiting indications are enabled by default.
 */
  CI_SS_PRIM_SET_CW_OPTION_CNF,         /**< \brief Confirms a request to set the local presentation option for incoming call waiting indications
										 * \details There is no reason for an unsuccessful result.*/
  CI_SS_PRIM_GET_CW_ACTIVE_STATUS_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_CW_ACTIVE_STATUS_CNF,  /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_USSD_ENABLE_REQ,       /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_USSD_ENABLE_CNF,       /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_USSD_ENABLE_REQ,       /**< \brief Requests to enable or disable unsolicited USSD indications
										 * \details USSD indications are used to configure reports of incoming USSD information.
										 * Unsolicited USSD indications (CI_SS_PRIM_RECEIVED_USSD_INFO_IND) are enabled by default.
										 * USSD sessions are independent of call status; they can exist when a call is active or inactive.  */
  CI_SS_PRIM_SET_USSD_ENABLE_CNF,       /**< \brief Confirms a request to enable or disable unsolicited USSD indications
										 * \details  */
  CI_SS_PRIM_RECEIVED_USSD_INFO_IND,    /**< \brief Indicates the receipt of incoming USSD information
										 * \details Unsolicited USSD indications (CI_SS_PRIM_RECEIVED_USSD_INFO_IND) are enabled by default.
										 * USSD sessions are independent of call status; they can exist when a call is active or inactive.
										 * USSD indications are used for incoming USSD information.
  *  The Status field allows the USSD receiver to determine what action is required, or to receive status notifications for the
  *  current USSD session. The mobile client can use this information to support both network initiated USSD sessions and mobile
  *  initiated USSD sessions:
  *  Status = CISS_USSD_STATUS_NO_INFO_NEEDED is used for network-initiated USSD-Notify operations. These indicate
  *  incoming USSD strings, during a network initiated USSD session.
  *  Status = CISS_USSD_STATUS_MORE_INFO_NEEDED is used for network-initiated USSD-Request operations. These indicate
  *  requests for outgoing USSD strings, during a mobile initiated USSD session.
  *  These indications can be enabled or disabled (suppressed) using CI_SS_PRIM_SET_USSD_ENABLE_REQ.
										 * Indications are enabled by default.
  *  USSD sessions are independent of call status; they can exist when a call is active or inactive. */
  CI_SS_PRIM_RECEIVED_USSD_INFO_RSP,    /**< \brief Responds to incoming (received) USSD information
										 * \details USSD sessions are independent of call status; they can exist when a call is active or inactive. */
  CI_SS_PRIM_START_USSD_SESSION_REQ,    /**< \brief Requests to start a mobile-originated (MO) USSD session
										 * \details This request is used only to initiate (start) a USSD session from the mobile end.
										 * Thereafter, all mobile-originated USSD
										 * message transfers are controlled from the network end.
										 * The network sends messages to the mobile to request its USS data,
  *  and the mobile sends its USS data in response to these requests (by sending CI_SS_PRIM_RECEIVED_USSD_INFO_RSP
  *  responses for CI_SS_PRIM_RECEIVED_USSD_INFO indications). USSD sessions can be established either during a call or out
  *  of call. */
  CI_SS_PRIM_START_USSD_SESSION_CNF,    /**< \brief Confirms a request to initiate a mobile-originated (MO) USSD session
										 * \details This signal confirms that the USSD information was sent from the mobile.
  *  The network can indicate any procedural errors by sending appropriate USSD information to the mobile.
  *  USSD sessions are independent of call status; they can exist when a call is active or inactive. */
  CI_SS_PRIM_ABORT_USSD_SESSION_REQ,    /**< \brief Requests the current USSD session to be aborted
										 * \details This request is used to abort the current USSD session from the mobile end. The mobile can abort any USSD session,
  *  whether initiated from the mobile of from the network. USSD sessions can be aborted at any time, regardless of the call state. */
  CI_SS_PRIM_ABORT_USSD_SESSION_CNF,    /**< \brief Confirms a request to abort a USSD session
										 * \details This signal confirms that the USSD abort request was sent from the mobile.
  *   The network can indicate any procedural errors by sending appropriate USSD information to the mobile.
  *   USSD sessions can be aborted at any time, regardless of the call state.*/
  CI_SS_PRIM_GET_CCM_OPTION_REQ,  	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_CCM_OPTION_CNF,    /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_CCM_OPTION_REQ,        /**< \brief Requests to enable or disable periodic current call meter (CCM) unsolicited reports
										 * \details Periodic CCM unsolicited reports are indicated by CI_CC_PRIM_CCM_UPDATE_IND.
These indications are enabled by default.
 */
  CI_SS_PRIM_SET_CCM_OPTION_CNF,        /**< \brief Confirms a request to enable or disable unsolicited current call meter (CCM) update indications
										 * \details There is no reason for an unsuccessful result.
										 * Not supported by SAC.  */
  CI_SS_PRIM_GET_AOC_WARNING_ENABLE_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_AOC_WARNING_ENABLE_CNF,    /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_AOC_WARNING_ENABLE_REQ,	/**< \brief Requests to enable or disable the advice of charge (AoC) warning ("ACM near ACMmax") indication
											 * \details If the advice of charge service is provisioned,
SAC can send a CI_CC_PRIM_AOC_WARNING_IND indication during a call when the accumulated charge meter (ACM) is within 30 seconds of the programmed maximum value (ACMmax). This indication can be enabled or disabled by the subscriber.
In addition, this indication can be sent if a new incoming or outgoing call is set up when the ACM is within 30 seconds of the programmed ACMmax value.
If the advice of charge service is not provisioned, SAC does not send an AoC warning indication, even if the indication has been enabled.
The AoC warning indication is enabled by default.
											 * Not supported by SAC.
*/
  CI_SS_PRIM_SET_AOC_WARNING_ENABLE_CNF,    /**< \brief Confirms a request to enable or disable the advice of charge (AoC) warning ("ACM near ACMmax") indication
											 * \details Not supported by SAC.*/
  CI_SS_PRIM_GET_SS_NOTIFY_OPTIONS_REQ,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_SS_NOTIFY_OPTIONS_CNF,     /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ,     /**< \brief Request to set the enable/disable options for supplementary service intermediate (SSI) and unsolicited (SSU) notifications
											 * \details SSI notifications (CI_CC_PRIM_SSI_NOTIFY_IND) and SSU notifications (CI_CC_PRIM_SSU_NOTIFY_IND) are both enabled by default.
											 * Not supported by SAC. */
  CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_CNF,     /**< \brief Confirms the request to set the current enable/disable options for supplementary service intermediate (SSI) and unsolicited (SSU) notifications
											 * \details There is no reason for an unsuccessful result.
										 * Not supported by SAC.*/
  CI_SS_PRIM_GET_LOCALCB_LOCKS_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_LOCALCB_LOCKS_CNF, /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_LOCALCB_LOCK_ACTIVE_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_LOCALCB_LOCK_ACTIVE_CNF,   /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_LOCALCB_LOCK_ACTIVE_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_LOCALCB_LOCK_ACTIVE_CNF,   /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_LOCALCB_NOTIFY_OPTION_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_SET_LOCALCB_NOTIFY_OPTION_CNF, /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_CHANGE_CB_PASSWORD_REQ,        /**< \brief Requests the call barring (CB) password to be changed
											 * \details The call barring supplementary service can be provisioned with the option "Control of Barring Services by Subscriber Using
  *  Password". In this case, the service provider registers an initial (default) password at provision time. The mobile subscriber
  *  can change the password at any time, using this request, and must provide the existing (old) password, a replacement
  *  (new) password, and optional verification of the new password. If new password verification is not supplied, the new
  *  password is sent to the network twice.
  *  Each password must be an array of digits. The password length (CI_SS_CB_PASSWORD_LENGTH) is defined by the GSM
  *  standard.
  *  The network supports one password per subscriber, to be used for all barring services. Therefore, a service code (or
  *  facility lock identifier) is not required for this request.
  *  A registration request is sent to the network to register the new password. Successful registration replaces the old
  *  password with the new password, erasing the old password. Therefore, there is no need for a specific request to erase the
  *  call blocking password.
  *  The registration request is rejected if:
  *    The service was provisioned with the option "Control of Barring Services by Service Provider". In this situation, the subscriber cannot activate or deactivate the call barring service.
  *    The service is not provisioned.
  *    The old password is invalid, or does not match the password currently registered with the network.
  *    The new password is invalid.
  *    The verification of the new password is present, but does not match the new password.
  * The reject cause is indicated in the confirmation response to this request.
  * If the request fails, the subscriber is allowed to retry it (with corrected passwords), for up to three consecutive attempts.
  * After that, all call barring requests that require a password are refused until the password is re-enabled by the service
  * provider.
*/
  CI_SS_PRIM_CHANGE_CB_PASSWORD_CNF,        /**< \brief Confirms a request to change the call barring (CB) password
											 * \details The CIRC_SS_NOT_REGISTERED result code most likely indicates that no password was registered when the call barring
  *  service was provisioned. This is the case if the service was provisioned with the option "Control of Barring Services by
  *  Service Provider".*/
  CI_SS_PRIM_GET_CB_STATUS_REQ,             /**< \brief Requests call barring (CB) status information for a specified class of service
											 * \details Status information can be requested only for a single class of service, such as voice service.
											 * An interrogation request is sent to the network. */
  CI_SS_PRIM_GET_CB_STATUS_CNF,             /**< \brief Confirms a request for call barring (CB) status information for a specified class of service
											 * \details The CIRC_SS_NOT_PROVISIONED result indicates one of the following situations:
  *  -	Call barring was not provisioned at all
  *  -	Call barring was provisioned with the option "Control of Barring Services by Service Provider". In this case, the subscriber cannot activate or deactivate the service.
 */
  CI_SS_PRIM_SET_CB_ACTIVATE_REQ,           /**< \brief Requests call barring to be activated or deactivated for a specified class (or classes) of service
											 * \details
  *   If the call barring supplementary service was provisioned with the option "Control of Barring Services by Service Provider",
  *   the subscriber is not allowed to activate or deactivate the call barring service using this request. If this is attempted, the
  *   network rejects the request, and an appropriate error indication is returned in the CI_SS_PRIM_SET_CB_ACTIVATE_CNF
  *   response.
  *   If the call barring supplementary service was provisioned with the option "Control of Barring Services by Subscriber Using
  *   Password", a password may be required for this request.
  *   An activation or deactivation request is sent to the network, which can accept or reject it. The request is rejected
  *   if:
  *   The service was provisioned with the option "Control of Barring Services by Service Provider". In this situation, the
  *        subscriber cannot activate or deactivate the service.
  *   The service was not provisioned.
  *   The current network does not support call barring.
  *   According to 3G TS 27.007, the following call barring service codes may be used only with a deactivate request:
  *   All barring services, All outgoing barring services and all incoming barring services.
  *   If an "Activate Call Barring Service" request is used with any of these service codes, it is rejected as an
  *   "invalid request", and is not sent to the network.
  *   If this request fails with a password error, the subscriber is allowed to re-attempt it (with a corrected password). If an
  *   incorrect password is entered more than three consecutive times, all call barring requests that require a password are
  *   rejected (by the network) until the password is re-enabled by the service provider.
  *   Call barring (when activated) must not affect the subscriber's ability to place emergency calls.
  *   The default (initial) activation state is a SAC configuration issue. */
  CI_SS_PRIM_SET_CB_ACTIVATE_CNF,           /**< \brief Confirms a request to activate or deactivate call barring (CB) for a specified class of service
											 * \details The CIRC_SS_NOT_REGISTERED result code most likely indicates that no password was registered when the call barring
  *  service was provisioned. This is the case if the service was provisioned with the option "Control of Barring Services by
  *  Service Provider". In this situation, the subscriber is not allowed to activate or deactivate the call barring service using the
  *  CI_SS_PRIM_SET_CB_ACTIVATE_REQ request.*/
  CI_SS_PRIM_GET_CB_TYPES_REQ,              /**< \brief Requests a list of supported call barring types (service codes)  \details */
  CI_SS_PRIM_GET_CB_TYPES_CNF,              /**< \brief Confirms a request to get a list of supported call barring types (service codes)
											 * \details There should be no reason for an unsuccessful result.  */
  CI_SS_PRIM_GET_BASIC_SVC_CLASSES_REQ,     /**< \brief Requests a list of supported basic service classes for call barring and call forwarding  \details */
  CI_SS_PRIM_GET_BASIC_SVC_CLASSES_CNF,     /**< \brief Confirms a request to get a list of supported basic service classes for call barring and call forwarding
											 * \details There is no reason for an unsuccessful result.*/
  CI_SS_PRIM_GET_ACTIVE_CW_CLASSES_REQ,     /**< \brief Requests an indication of basic services for which call waiting is active  \details */
  CI_SS_PRIM_GET_ACTIVE_CW_CLASSES_CNF,     /**< \brief Confirms a request to get an indication of basic services for which call waiting is active
											 * \details The returned bitmap indicates the call waiting status for each of the requested services. If call waiting is active for a basic
  *  service, the corresponding bit is set to 1 in the returned bitmap. Otherwise, the bit is set to zero.
  *  For the ActClasses bitmap, only those bits with corresponding bits set to 1 in the ReqClasses bitmap are meaningful.
*/

  CI_SS_PRIM_GET_CB_MAP_STATUS_REQ,         /**< \brief Requests to get the basic services for the call barring status  \details */
  CI_SS_PRIM_GET_CB_MAP_STATUS_CNF,         /**< \brief Confirms the request and returns the basic services for call barring status
  \details */

  CI_SS_PRIM_PRIVACY_CTRL_REG_REQ,          /**< \brief Requests to register support of privacy control services
											 * \details Position location service. */
  CI_SS_PRIM_PRIVACY_CTRL_REG_CNF,          /**< \brief Confirms the request to register support of privacy control services
											 * \details Position location service.*/
  CI_SS_PRIM_LOCATION_IND,                  /**< \brief Indicates that the location information of the mobile was requested
											 * \details Position location service. */
  CI_SS_PRIM_LOCATION_VERIFY_RSP,           /**< \brief Responds with the location verification information
											 * \details Position location service.*/
  CI_SS_PRIM_GET_LOCATION_REQ,              /**< \brief Requests to get the mobile's position location from the network
											 * \details Position location service. */
  CI_SS_PRIM_GET_LOCATION_CNF,              /**< \brief Confirms the request to get the position location of the mobile from the network
											 * \details Position location service. */
  CI_SS_PRIM_GET_LCS_NWSTATE_REQ,           /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_GET_LCS_NWSTATE_CNF,           /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_LCS_NWSTATE_CFG_IND_REQ,       /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_LCS_NWSTATE_CFG_IND_CNF,       /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
  CI_SS_PRIM_LCS_NWSTATE_IND,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */


  CI_SS_PRIM_SERVICE_REQUEST_COMPLETE_IND,  /**< \brief Indicates the completion status of the supplementary service request
											 * \details This notification is sent in reply to a supplementary service request. It is based on the status information returned by the protocol stack.
											 * The returned status is decoded from the Facility Information Element, when present, by the protocol stack as follows: ACTIVE, REGISTERED, PROVISIONED, QUIESCENT. */
  CI_SS_PRIM_GET_COLR_STATUS_REQ,           /**< \brief Requests to interrogate the network for CoLR (Connected Line Identification Restriction) service support  \details */
  CI_SS_PRIM_GET_COLR_STATUS_CNF,           /**< \brief Confirms the request to the previous interrogation of the CoLR (Connected Line Identification Restriction) service support  \details */

  /*Michal Bukai - CDIP support - Start:*/
  CI_SS_PRIM_GET_CDIP_STATUS_REQ,           /**< \brief Requests the status of the CDIP supplementary service
											 * \details Requests the local CDIP presentation option setting and interrogates the CDIP provision status at the network.
If enabled, CDIP information is reported by the CI_CC_PRIM_CDIP_INFO_IND primitive.
If the CDIP service is provisioned, local CDIP presentation is enabled by default.
There is no reason for an unsuccessful result.  */
  CI_SS_PRIM_GET_CDIP_STATUS_CNF,           /**< \brief Confirms the request for the status of the CDIP supplementary service
											 * \details Confirms the request and reports the local CDIP presentation option setting and the CDIP provision status at the network.
											 * If the CDIP service is provisioned, local CDIP presentation is enabled by default.
											 *  There is no reason for an unsuccessful result.*/
  CI_SS_PRIM_SET_CDIP_OPTION_REQ,           /**< \brief Requests to set the local presentation option for CDIP information on incoming calls
											 * \details This option affects only the local presentation of CDIP information (at the mobile);
											 * it does not affect the operation of the CDIP service at the network.
											 * The provisioned setting for CDIP is unchanged.
											 * By default CDIP presentation is enabled.
											 * This request fails if CDIP service is not provisioned. */
  CI_SS_PRIM_SET_CDIP_OPTION_CNF,           /**< \brief Confirms a request to set the local presentation option for CDIP information on incoming calls
											 * \details This option affects only the local presentation of CDIP information (at the mobile);
											 * it does not affect the operation of the CDIP service at the network.
											 * The provisioned setting for CDIP is unchanged. */
  /*Michal Bukai - CDIP support - End*/
  /*Michal Bukai - IMS support - Start */
  CI_SS_PRIM_SET_UUS1_REQ,	/**< \brief Requests to set user to user signaling data using Service 1 implicit activation
							* \details This message will define user data that should be sent during the next call setup
							* USS1 data will be deleted after the call is disconnected.*/
  CI_SS_PRIM_SET_UUS1_CNF,	/**< \brief Confirms the request to set user to user signaling data  \details */
  /*Michal Bukai - IMS support - End */
  
  CI_SS_PRIM_MMI_CODE_FDN_CHECK_REQ,    /**< \brief Requests to do FDN check for MMI codes in MO SS procedures
                                                                      */ 
  CI_SS_PRIM_MMI_CODE_FDN_CHECK_CNF,    /**< \brief Confirms the request to do FDN check for MMI codes in MO SS procedures.
                                                                      */
  /*Added by Liubin for at+cuus1, 2015-09-01,begin*/
  CI_SS_PRIM_GET_UUS1_REQ,	/**< \brief Requests to get the setting of the user to user signaling data using service 1 implicit activation */
  CI_SS_PRIM_GET_UUS1_CNF,	/**< \brief Confirms the request to get user to user signaling data information */
  CI_SS_PRIM_INTERROGATE_EMLPP_INFO_REQ, /**< \brief Requests EMLPP interrogation */
  CI_SS_PRIM_INTERROGATE_EMLPP_INFO_CNF, /**< \brief Confirms EMLPP interrogation request  */
  CI_SS_PRIM_REGISTER_EMLPP_INFO_REQ, /**< \brief Requests EMLPP registration */
  CI_SS_PRIM_REGISTER_EMLPP_INFO_CNF, /**< \brief Confirms EMLPP registration request  */

  CI_SS_PRIM_GET_LOCAL_PROFILE_REQ, /**< \brief Requests profile of local potions for +CLIP/+COLP/+CLIR/+CCWA   */
  CI_SS_PRIM_GET_LOCAL_PROFILE_CNF, /**< \brief Confirms profile of local potions for +CLIP/+COLP/+CLIR/+CCWA   */


  /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_SS_PRIM_LAST_COMMON_PRIM' */

  /* END OF COMMON PRIMITIVES LIST */
  CI_SS_PRIM_LAST_COMMON_PRIM

  /* The customer specific extension primitives are added starting from
   * CI_SS_PRIM_FIRST_CUST_PRIM = CI_SS_PRIM_LAST_COMMON_PRIM as the first identifier.
   * The actual primitive names and IDs are defined in the associated
   * 'ci_ss_cust_xxx.h' file.
   */

  /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiSsPrim;

/* specify the number of default common CC primitives */
#define CI_SS_NUM_COMMON_PRIM ( CI_SS_PRIM_LAST_COMMON_PRIM - 1 )
/**@}*/


/** \brief Supplementary Services Return Codes */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_SS{
  CIRC_SS_SUCCESS = 0,          /**< Request completed successfully */
  CIRC_SS_FAIL,                 /**< General failure (catch-all, if needed) */
  CIRC_SS_NOT_PROVISIONED,      /**< Supplementary service not provisioned  */
  CIRC_SS_NOT_REGISTERED,       /**< Supplementary service not registered */
  CIRC_SS_REJECTED,             /**< Request rejected by network  */
  CIRC_SS_INCORRECT_PWD,              /**< Incorrect password */
  CIRC_SS_INVALID_PARAMETER,	/**< Generic error - the requested service primitive has invalid parameters */
  CIRC_SS_INVALID_REQ,			/**< Generic error - the requested service primitive can not be handled at current state */
  CIRC_SS_SIM_NOT_READY,		/**< Generic error - the requested service primitive fails because SIM is not ready */
  CIRC_SS_ACCESS_DENIED,		/**< Generic error - the requested service primitive fails because access is denied */
  CIRC_SS_FDN_ONLY, 			/**< Only fixed dialing numbers allowed */

  /* This one must always be last in the list! */
  CIRC_SS_NUM_RESCODES          	/**< Number of result codes defined */
} _CiSsResultCode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Result code
 *  \sa CIRC_SS
 * \remarks Common Data Section */
typedef UINT16 CiSsResultCode;
/**@}*/
//modify by taow cq 54253 begin
typedef enum SS_ERROR_CODE_TAG
{
  CiSS_ERROR_CODE_NULL           =0,
  CiSS_UNKNOWN_SUBSCRIBER        =1,
  CiSS_ILLEGAL_SUBSCRIBER        =9,
  CiSS_BRERSERV_NOT_PROV        =10,
  CiSS_TELESERV_NOT_PROV        =11,
  CiSS_ILLEGAL_EQUIPMENT        =12,
  CiSS_CALL_BARRED              =13,
  CiSS_ILLEGAL_OPERATION        =16,
  CiSS_ERROR_STATUS              =17,
  CiSS_NOT_AVAILABLE            =18,
  CiSS_SUBS_VIOLATION            =19,
  CiSS_INCOMPATIBILITY          =20,
  CiSS_FACILITY_NOT_SUPPORTED    =21,
  CiSS_ABSENT_SUBSCRIBER        =27,
  CiSS_SYSTEM_FAILURE            =34,
  CiSS_DATA_MISSING              =35,
  CiSS_UNEXPECTED_DATA_VALUE    =36,
  CiSS_PWD_REGISTRATION_FAILURE  =37,
  CiSS_NEGATIVE_PWD_CHECK        =38,
  CiSS_NUMOF_PWD_ATTEMPT_VIOL    =43,
  CiSS_POSITION_METHOD_FAILURE   =54,
  CiSS_UNKNOWN_ALPHABET          =71,
  CiSS_USSD_BUSY                =72,
  CiSS_MAXMPTY_CALLS_EXCEEDED   =126,
  CiSS_RESOURCES_NOT_AVAILABLE  =127
}_CiSsErrorCode;
typedef UINT16 CiSsErrorCode;

//modify by taow cq 54253 end

/** \brief Basic service class map allocations for supplementary services */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISS_BASIC_SERVICE_MAP
{
  CISS_BSMAP_NONE       = 0x00, 			/**< No services specified */   // SCR #1994470
  CISS_BSMAP_VOICE      = 0x01, 			/**< Voice service  */
  CISS_BSMAP_DATA       = 0x02, 			/**< Data service */
  CISS_BSMAP_FAX        = 0x04, 			/**< Fax service  */
  CISS_BSMAP_TELE_EXCEPSMS = 0x05,			/**< all tele services except SMS>*/
  CISS_BSMAP_SMS        = 0x08, 			/**< Short message service (SMS)  */
  CISS_BSMAP_DATA_TELE	= 0x0c,				/**<all Data Teleservices> */
  CISS_BSMAP_TELE		= 0x0d,				/**<all tele services>*/
  CISS_BSMAP_DATA_SYNC  = 0x10, 		/**< Data circuit sync  */
  CISS_BSMAP_DATA_ASYNC = 0x20, 		/**< Data circuit async */
  CISS_BSMAP_PACKET     = 0x40, 		/**< Dedicated packet access  */
  CISS_BSMAP_PAD        = 0x80, 			/**< Dedicated PAD access */
  CISS_BSMAP_SYNCHRONOUS  = 0x50,			/**<ALL SYNC HRONOUS SERVICES>*/
  CISS_BSMAP_ASYNCHRONOUS = 0Xa0,			/**<ALL ASYNC HRONOUS SERVICES>*/
  CISS_BSMAP_ALL        = 0xFF  			/**< All services */            // SCR #1994470

} _CiSsBasicServiceMap;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Bit map for SS basic services
 *  \sa CISS_BASIC_SERVICE_MAP
 * \remarks Common Data Section */
typedef UINT8 CiSsBasicServiceMap;
/**@}*/



/* Default BasicServiceMap is (Voice + Data + Fax)  */
#define CISS_BSMAP_DEFAULT  ( CISS_BSMAP_VOICE | CISS_BSMAP_DATA | CISS_BSMAP_FAX )

/* Calling Party (Caller) Information - for CLIP and CoLP indications */
/* ** SCR #1247683: CiSsCallerInfo definition removed */

/* CLI Validity Indicators - used in CLIP and call waiting indications */
/* ** SCR #1247683: CiSsCliValidity definition removed */

/* Information for CLIP indications */
/* ** SCR #1247683: CiSsClipInfo definition removed */

/* Information for CoLP indications */
/* ** SCR #1247683: CiSsColpInfo definition removed */

/* Information for call waiting (CW) indications */
/* ** SCR #1247683: CiSsCwInfo definition removed */


/** \brief CUG temporary (override) configuration information
 *  \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsCugConfigInfo_struct {
  UINT8 TempCugIndex;                	/**< Temporary CUG index  */
  UINT8 TempCugInfo;                  	/**< Temporary CUG information (suppression)  */
} CiSsCugConfigInfo;

/* Temporary CUG Mode (see the "AT+CCUG" command) */
#define CI_CUG_TEMPMODE_DISABLED          0     /* Temporary mode disabled                  */
#define CI_CUG_TEMPMODE_ENABLED           1     /* Temporary mode enabled                   */

/* Temporary CUG Index - the valid range of values should already be defined elsewhere! */
#define CI_CUG_TEMPINDEX_NONE             10    /* No index (from "AT+CCUG" command)        */

/* Temporary CUG Information (Suppression) is a bitmap. More than one bit may be set at a time */
#define CI_CUG_TEMPINFO_NONE              0x00  /* No information                           */
#define CI_CUG_TEMPINFO_SUPPRESS_OA       0x01  /* Suppress outgoing access (OA)            */
#define CI_CUG_TEMPINFO_SUPPRESS_PREF_CUG 0x02  /* Suppress preferential (provisioned) CUG  */

/** Call forwarding: Reasons (Conditions) supported by CI.
 *    We may not support all of the "reason" values defined for "AT+CCFC" in [3].
 */
#define CICF_MAX_REASONS  6       	/**< As defined by the "AT+CCFC" command  */


/** \brief CF reasons */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICF_REASON {
  CICF_REASON_CFU = 0,            		/**< Call forward unconditional (CFU) */
  CICF_REASON_CFB,                		/**< Call forward on user busy (CFB)  */
  CICF_REASON_CFNRY,              		/**< Call forward on no reply (CFNRy) */
  CICF_REASON_CFNRC,              		/**< Call forward on not reachable (CFNRc)  */
  CICF_REASON_ALL,                		/**< All call forwarding  */
  CICF_REASON_ALL_CONDITIONAL,    	/**< All conditional call forwarding  */

  /* This one must always be last! */
  CICF_NUM_REASONS                		/**< Number of supported CF reasons */

} _CiSsCfReason;
/** \brief ussd reasons */
/** \remarks USSD release cause */
//modify by taow cq 55973 begin

//ICAT EXPORTED ENUM
typedef enum CI_SS_CAUSE_Tag
{ 
    CISS_UNASSIGNED_NO             =   1,
    CISS_NO_ROUTE_TO_DEST          =   3,
    CISS_CHAN_UNACCEPTABLE         =   6,
    CISS_OPER_DETERM_BARRING       =   8,
    CISS_NORMAL_CLEARING           =   16,
    CISS_USER_BUSY                 =   17,
    CISS_NO_USER_RESPONDING        =   18,
    CISS_ALERTING_NO_ANSWER        =   19,
    CISS_CALL_REJECTED             =   21,
    CISS_NUMBER_CHANGED            =   22,
    CISS_PREEMPTION                =   25,
    CISS_NONSEL_USER_CLRING        =   26,
    CISS_DEST_OUT_OF_ORDER         =   27,
    CISS_INVALID_NO_FORMAT         =   28,
    CISS_FACILITY_REJECTED         =   29,
    CISS_RSP_TO_STATUS_ENQ         =   30,
    CISS_NORMAL_UNSPECIFIED        =   31,
    CISS_NO_CIRC_CHAN_AV           =   34,
    CISS_NET_OUT_OF_ORDER          =   38,
    CISS_TEMP_FAILURE              =   41,
    CISS_SWITCH_CONGESTION         =   42,
    CISS_ACC_INFO_DISCARDED        =   43,
    CISS_REQ_CIRC_CHAN_UNAV        =   44,
    CISS_RESOURCES_UNAV            =   47,
    CISS_QOS_UNAV                  =   49,
    CISS_REQ_FAC_NOT_SUBSCR        =   50,
    CISS_CUG_INCOMING_BARRED       =   55,
    CISS_BEAR_CAP_NOT_AUTH         =   57,
    CISS_BEAR_CAP_UNAV             =   58,
    CISS_SERV_OPT_UNAV             =   63,
    CISS_BEAR_SVC_NOT_IMPL         =   65,
    CISS_ACM_EQ_OR_GT_ACMMAX       =   68, /* FR9608-0481 */
    CISS_REQ_FACIL_NOT_IMPL        =   69,
    CISS_ONLY_RESTRIC_DIG_AV       =   70,
    CISS_SVC_OPT_NOT_IMPL          =   79,
    CISS_INVALID_TI                =   81,
    CISS_USER_NOT_IN_CUG           =   87,
    CISS_INCOMPAT_DEST             =   88,
    CISS_INVALID_TRANSIT_NET       =   91,
    CISS_INVALID_MSG_SEMANTIC      =   95,
    CISS_MAND_IE_ERROR             =   96,
    CISS_MSG_NONEXISTENT           =   97,
    CISS_MSG_GEN_ERROR             =   98,
    CISS_IE_NONEXISTENT            =   99,
    CISS_INVALID_CONDITION_IE      =   100,
    CISS_MSG_INCOMPAT_STATE        =   101,
    CISS_RECOV_ON_TIMER_EXP        =   102,
    CISS_PROTOCOL_ERROR            =   111,
    CISS_INTERWORKING              =   127,
	CISS_NUM_CAUSE

}_CiSsNwReleaseCause;
typedef UINT16 CiSsNwReleaseCause;


//ICAT EXPORTED ENUM
typedef enum CiSsProblemTagTag
{
  CiSs_GENERAL_TAG              =0x0,     /* 0x80 & 0x1F */
  CiSs_INVOKE_TAG                =0x1,     /* 0x81 & 0x1F */
  CiSs_RETURN_RESULT_TAG        =0x2,     /* 0x82 & 0x1F */
  CiSs_RETURN_ERROR_TAG          =0x3      /* 0x83 & 0x1F */
}_CiSsProblemTag;
typedef UINT8 CiSsProblemTag;

//ICAT EXPORTED ENUM
typedef enum CiSsProblemCodeTag
{
  CiSsGEN_UNRECOGNISED          =0x00,
  CiSsGEN_MISTYPED              =0x01,
  CiSsGEN_BAD_STRUCTURE          =0x02,

  CiSsINV_DUPLICATE_ID          =0x00,
  CiSsINV_UNRECOG_ID            =0x01,
  CiSsINV_MISTYPED              =0x02,
  CiSsINV_RESOURCE_LIMIT        =0x03,
  CiSsINV_INITIATE_RELEASE      =0x04,
  CiSsINV_UNRECOG_LINK          =0x05,
  CiSsINV_LINK_RSP_UNEXP        =0x06,
  CiSsINV_UNEXP_LINK_OP          =0x07,

  CiSsRETRES_UNRECOG_ID          =0x00,
  CiSsRETRES_UNEXPECTED          =0x01,
  CiSsRETRES_MISTYPED            =0x02,

  CiSsRETERR_UNRECOG_ID          =0x00,
  CiSsRETERR_UNEXPECTED          =0x01,
  CiSsRETERR_UNRECOG_ERR        =0x02,
  CiSsRETERR_UNEXP_ERR          =0x03,
  CiSsRETERR_MISTYPED            =0x04
}_CiSsProblemCode;


typedef UINT8 CiSsProblemCode;

//ICAT EXPORTED STRUCT
typedef struct CiSsRejectCode_struct {
  CiSsProblemTag	ProblemTag;         	
  CiSsProblemCode 	ProblemCode;        		
} CiSsRejectCode;


//ICAT EXPORTED ENUM
typedef enum CiSsCancelCodeTag
{
  CiSS_NO_PIPES                  =0,
  CiSS_ONGOING_TRANSACTIONS,
  CiSS_MNSS_REJECT,
  CiSS_NO_CONTROL,
  CiSS_INVALID_INVOKE_ID,
  CiSS_FDN_FAILURE
}_CiSsCancelCode;
typedef UINT16 CiSsCancelCode;
//ICAT EXPORTED ENUM
typedef enum CiSsNormalCodeTag
{
  CiSS_NORMAL_CODE         =0,
}_CiSsNormalCode;
typedef UINT16 CiSsNormalCode;


//ICAT EXPORTED ENUM
typedef enum CiSsFailTypeTag
{ 
  CiSS_NORMAL_RETURN_TYPE	=0,
  CiSS_REJECT_TYPE,         
  CiSS_ERROR_TYPE,
  CiSS_CANCEL_TYPE,
  CiSS_RELEASE_TYPE
}_CiSsFailType;
typedef UINT16 CiSsFailType;

//ICAT EXPORTED UNION:CiSsFailType
typedef union CiSsFailCode_struct {
  CiSsNormalCode		NormalCode;
  CiSsRejectCode 		RejectCode;
  CiSsErrorCode			ErrorCode;
  CiSsCancelCode		CancelCode;
  CiSsNwReleaseCause    ReleaseCause;         	       		
} CiSsFailCode;


//ICAT EXPORTED STRUCT
typedef struct CiSsFailReason_struct {
  CiSsFailType	FailType;         	
  CiSsFailCode 	FailCode;        		
} CiSsFailReason;
//modify by taow cq 55973 end


/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief CF reason
 *  \sa CICF_REASON
 * \remarks Common Data Section */
typedef UINT8 CiSsCfReason;
/**@}*/

/* Call forwarding: CFNRy Timer definitions. See [10]. */
#define CI_CFNRY_TIMER_MIN      5     /* Minimum timer duration (seconds) */
#define CI_CFNRY_TIMER_MAX      30    /* Maximum timer duration (seconds) */
#define CI_CFNRY_TIMER_STEP     5     /* Timer duration step interval (seconds) */
#define CI_CFNRY_TIMER_DEFAULT  20    /* Default timer duration (seconds) */

/** \brief Call forwarding: Information for registration requests to the network */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsCfRegisterInfo_struct {
  CiSsCfReason        		Reason;         	/**< Call forwarding reason (condition) \sa CiSsCfReason */
  CiSsBasicServiceMap 	Classes;        		/**< Classes of service (bitmap) \sa CiSsBasicServiceMap  */
  CiAddressInfo       		Number;         	/**< Call forwarding number \sa CCI API Ref Manual  */
  CiSubaddrInfo       		OptSubaddr;     	/**< Optional subaddress \sa CCI API Ref Manual */
  UINT8               			CFNRyDuration;  	/**< CFNRy timer duration (seconds) */
  
  UINT8                    ssStatus;   /**< 0 - Call forwarding not active; 1 - Call forwarding active; only used for CCFC query if forwardingFeatureList is present */
} CiSsCfRegisterInfo;

/** \brief Call forwarding: Information for erasure requests to the network */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsCfEraseInfo_struct {
  CiSsCfReason        		Reason;         	/**< Call forwarding reason (condition) \sa CiSsCfReason */
  CiSsBasicServiceMap 	Classes;        		/**< Classes of service (bitmap)  \sa CiSsBasicServiceMap  */
} CiSsCfEraseInfo;

/** \brief  Basic service class definitions for supplementary services */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISS_BASIC_SERVICE
{
  CISS_SERVICE_NONE = 0,              /**< No services specified */   // SCR #1994470
  CISS_SERVICE_VOICE,                 /**< Voice service  */
  CISS_SERVICE_DATA,                  /**< Data service */
  CISS_SERVICE_FAX,                   /**< Fax service  */
  CISS_SERVICE_SMS,                   /**< Short message service (SMS)  */
  CISS_SERVICE_DATA_SYNC,             /**< Data circuit sync  */
  CISS_SERVICE_DATA_ASYNC,            /**< Data circuit async */
  CISS_SERVICE_PACKET,                /**< Dedicated packet access  */
  CISS_SERVICE_PAD,                   /**< Dedicated PAD access */
  /* This one must always be last in the list! */
  CISS_NUM_SERVICES                   /* Number of basic service options supported */
} _CiSsBasicService;


/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Basic service class for supplementary services
 *  \sa CISS_BASIC_SERVICE
 * \remarks Common Data Section */
typedef UINT8 CiSsBasicService;
/**@}*/



/** \brief USSD status definitions. See the "AT+CUSD" command in [4]. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISS_USSD_STATUS {
  CISS_USSD_STATUS_NO_INFO_NEEDED = 0,  		/**< No further information needed for MO operation  */
  CISS_USSD_STATUS_MORE_INFO_NEEDED,    		/**< Further information needed for MO operation */
  CISS_USSD_STATUS_TERMINATED,          			/**< USSD terminated by network */
  CISS_USSD_STATUS_OTHER_CLIENT_RESP,   		/**< Other client has responded */
  CISS_USSD_STATUS_NOT_SUPPORTED,       		/**< Operation not supported  */
  CISS_USSD_STATUS_TIMEOUT,             			/**< Network timeout  */
  CISS_USSD_STATUS_INPROGRESS,                  /**< PHASE 2    fail and retry phase 1 */

  /* << Define additional allocations here >> */

  /* This one must always be last in the list! */
  CISS_NUM_USSD_STATUS                  				/**< Number of USSD status codes defined  */

} _CiSsUssdStatus;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief USSD status
 *  \sa CISS_USSD_STATUS
 * \remarks Common Data Section */
typedef UINT8 CiSsUssdStatus;
/**@}*/



/* SCR #1698551: USSD Character Set definitions. See the AT+CSCS command (TS 27.007) */
//ICAT EXPORTED ENUM
typedef enum CISS_USSD_CHARSET
{
  /* Character Set codes for MT-USSD */
  CISS_USSD_UNKNOWN = 0,                /* Unknown representation */
  CISS_USSD_CHARSET_IRA,                /* IRA "ASCII" text string */
  CISS_USSD_CHARSET_HEX,                /* Hexadecimal digit character string */
  CISS_USSD_CHARSET_USER,               /* User-specified representation */

  /* Character Set codes for MO-USSD */
  CISS_USSD_CHARSET_MO_GSM7BIT,         /* IRA text -> GSM 7-bit */
  CISS_USSD_CHARSET_MO_UCS2,            /* Hex digit string -> UCS2 */

  /* << Define additional character set definitions here >> */
  CISS_USSD_CHARSET_TRANPARENT_MODE,         /* GSM 7-bit packed and and encodded ready to tramit over the air, used in USSD proactive*/
  /* This one must always be last in the list! */
  CISS_NUM_USSD_CHARSETS                /* Number of USSD character set codes defined */

} _CiUssdCharSet;

typedef UINT8 CiUssdCharSet;

/** \brief USSD: Unstructured supplementary service data information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsUssdInfo_struct {
  CiUssdCharSet	CharSet;                    				/**< Data Character Set indicator */  // SCR #1698551
  UINT8         		DataLength;                 			/**< USS Data length (characters) */
  UINT8          		Data[ CI_MAX_USSD_LENGTH ]; 	/* USS Data */
} CiSsUssdInfo;

/** \brief  Network Call Barring: Service Codes (Call Barring Types). */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISS_CB_SERVICE_CODE {
  CISS_CB_LOCK_BAOC = 0,      /**< Bar all outgoing calls  */
  CISS_CB_LOCK_BOIC,          /**< Bar outgoing international calls  */
  CISS_CB_LOCK_BOIC_EXHC,     /**< Bar outgoing international calls  */
                              /**<  except to the home PLMN country  */
  CISS_CB_LOCK_BAIC,          /**< Bar all incoming calls  */
  CISS_CB_LOCK_BAIC_ROAMING,  /**< Bar incoming calls when roaming outside  */
                              /*  of the home PLMN country */
  CISS_CB_LOCK_ALL,           /**< All barring services  */
  CISS_CB_LOCK_ALL_OUTGOING,  /**< All outgoing barring services */
  CISS_CB_LOCK_ALL_INCOMING,  /**< All incoming barring services */

  /* This one must always be last in the list! */

  CISS_NUM_CB_LOCK_CODES      /* Number of call barring codes */

} _CiSsCbServiceCode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Call barring service code
 *  \sa CISS_CB_SERVICE_CODE
 * \remarks Common Data Section */
typedef UINT16 CiSsCbServiceCode;
/**@}*/



/* Indicator for "No Call Barring Lock in use" */
#define CI_SS_CB_LOCK_NO_LOCK     ( (CiSsCbServiceCode) (-1) )
#define CI_SS_CB_PASSWORD_LENGTH  4 /* Required password length (digits only) */

/* Local Call Barring: Facility (Lock) Identifiers (applied to incoming calls only).
 * Some appear to be identified in the "AT+CLCK" command (see [3]). The protocol stack may
 * not support all (or any) of them - and it may support others.
 *
 * The entire local call barring facility needs further investigation.
 * See [13] Section A.19, which talks about a Barred Dialing List (BDN) in the SIM.
*/
//ICAT EXPORTED ENUM
typedef enum CISS_LOCALCB_LOCK_ID {
  CISS_LOCALCB_LOCK_NM = 0, /* Bar caller numbers not in ME phonebook */
  CISS_LOCALCB_LOCK_NS,     /* Bar caller numbers not in SIM phonebook  */
  CISS_LOCALCB_LOCK_NA,     /* Bar caller numbers not in ME or SIM PB */

  /* << Put any additional definitions here >> */

  /* This one must always be last in the list! */
  CISS_NUM_LOCALCB_LOCKS    /* Number of local call barring lock IDs  */

} _CiSsLocalCbLockId;
typedef UINT8 CiSsLocalCbLockId;


/* Constant definitions for position location */


//ICAT EXPORTED ENUM
typedef enum CISS_LCS_NW_STATE {
  CISS_LCS_AVAILABLE=0,
  CISS_LCS_NOT_AVAILABLE,
  CISS_LCS_TEMPORARY_NOT_AVAILABLE,

  /* This one must always be last in the list! */
  CISS_NUM_LCS_NW_STATE
} _CiSsLcsNwState;
typedef UINT8 CiSsLcsNwState;



//ICAT EXPORTED STRUCT
typedef struct CiSsPrivateExtension_struct{
  CiBoolean present;
  UINT8     extId;
  UINT8     extType;
} CiSsPrivateExtension;

//ICAT EXPORTED STRUCT
typedef struct CiSsPcsExtensions_struct{
  /* TBD: 3gpp spec 24.080 does not really define anything for this field */
  UINT8 pcsExtention;
} CiSsPcsExtensions;

//ICAT EXPORTED ENUM
typedef enum CISS_SUPP_GAD_SHAPES {
  CISS_ELLIPSOID_PT                    =0x01,
  CISS_ELLIPSOID_PT_UNCERT_CIRCLE      =0x02,
  CISS_ELLIPSOID_PT_UNCERT_ELLIPSE     =0x04,
  CISS_POLYGON                         =0x08,
  CISS_ELLIPSOID_PT_ALT                =0x10,
  CISS_ELLIPSOID_PT_ALT_UNCERT_ELIPSOID=0x20,
  CISS_ELLIPSOID_ARC                   =0x40,
} _CiSsSuppGadShapes;

typedef UINT8 CiSsSuppGadShapes;



/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CLIP_STATUS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetClipStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CLIP_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetClipStatusCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode*/
  UINT8 Local;            		/**< Local CLIP enable/disable status */
  UINT8 Provision;        		/**< CLIP provision status */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetClipStatusCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CLIP_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetClipOptionReq_struct{
  UINT8 Local;		/**< 0 - Disable local CLIP presentation; 1 - Enable local CLIP presentation */
} CiSsPrimSetClipOptionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CLIP_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetClipOptionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetClipOptionCnf;

/*Michal Bukai - CDIP support - Start:*/
/** <paramref name="CI_SS_PRIM_GET_CDIP_STATUS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetCdipStatusReq;

/** <paramref name="CI_SS_PRIM_GET_CDIP_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCdipStatusCnf_struct{
  CiSsResultCode Result;  /**< Result code  \sa CiSsResultCode */
  UINT8 Local;            /**< Local CDIP enable/disable status */
  UINT8 Provision;        /**< CDIP provision status */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetCdipStatusCnf;

/** <paramref name="CI_SS_PRIM_SET_CDIP_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCdipOptionReq_struct{
  UINT8 Local; 	/**< Local setting of CDIP status permitted values are Enable (1); Disable (0) */
} CiSsPrimSetCdipOptionReq;

/** <paramref name="CI_SS_PRIM_SET_CDIP_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCdipOptionCnf_struct{
  CiSsResultCode Result; /**< Result code  \sa CiSsResultCode */
} CiSsPrimSetCdipOptionCnf;
/*Michal Bukai - CDIP support - End*/
/*Michal Bukai - IMS support - Start:*/

/** \brief Protocol discriminator as defined in 3GPP TS	24.008 section 10.5.4.25 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CISS_PROTOCOL_DISC{

    CISS_PROTOCOL_DISC_USP = 0,         /* User specified protocol */
    CISS_PROTOCOL_DISC_OSIHLP,       	/* OSI higher layer protocol */
    CISS_PROTOCOL_DISC_X244,         	/* X.244 */
    CISS_PROTOCOL_DISC_RMCF3,         	/* Reserved for system mangement convergence function */
    CISS_PROTOCOL_DISC_IA5c4,          	/* IA5 characters */

    CISS_NUM_PROTOCOL_DISC       		/* Number of protocols discriminator defined */
} _CiSsProtocolDisc;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Protocols Discriminator values
 * \sa CISS_PROTOCOL_DISC */
/** \remarks Common Data Section */
typedef UINT8 CiSsProtocolDisc;
/**@}*/

/* <INUSE> */
/*Modified by Liubin for at+cuus1, 2015-09-01,begin*/
#if 0
typedef struct CiSsPrimSetUus1Req_struct{
	CiSsProtocolDisc	protocolDisc;   /**< Protocol discriminator as defined in 3GPP TS 24.008 section 10.5.4.25	\sa CiSsProtocolDisc*/
	CiString   			userUserInfo;	/**< User-user information element as defined in 3GPP TS 24.008 appendix O2 \sa CCI API Ref Manual */
#endif


#define 	UUS_INFO_DATA_LEN	108
typedef struct _CiSsUus1_struct
{
	CiBoolean			msgValid;
	UINT8				uusInfoLen;
	CiSsProtocolDisc	protocolDisc;   /**< Protocol discriminator as defined in 3GPP TS 24.008 section 10.5.4.25	\sa CiSsProtocolDisc*/
	UINT8				UusInfo[UUS_INFO_DATA_LEN];
} CiSsUus1_struct;
//ICAT EXPORTED STRUCT

/** <paramref name="CI_SS_PRIM_SET_UUS1_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetUus1Req_struct{
	CiSsUus1_struct	Uus1[7];
} CiSsPrimSetUus1Req;
/*Modified by Liubin for at+cuus1, 2015-09-01,end*/

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_UUS1_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetUus1Cnf_struct{
	CiSsResultCode	Result; 	  /**< Result code. \sa CiSsResultCode */
} CiSsPrimSetUus1Cnf;

/*Michal Bukai - IMS support - End*/
/*Added by Liubin for at+cuus1, 2015-09-01,begin*/
//ICAT EXPORTED STRUCT
/** <paramref name="CI_SS_PRIM_GET_UUS1_REQ">   */
typedef CiEmptyPrim CiSsPrimGetUus1Req;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_SS_PRIM_GET_UUS1_CNF">   */
typedef struct CiSsPrimGetUus1Cnf_struct{
	CiSsResultCode Result;		  /**< Result code	\sa CiSsResultCode */
	CiSsUus1_struct	Uus1[7];
} CiSsPrimGetUus1Cnf;
/*Added by Liubin for at+cuus1, 2015-09-01,end*/

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CLIR_STATUS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetClirStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CLIR_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetClirStatusCnf_struct{
  CiSsResultCode Result;		/**< Result code. \sa CiSsResultCode */
  UINT8 Local;              		/**< Local CLIR Presentation (Invoke/Suppress/Revoke) Status */
  UINT8 Provision;          		/**< CLIR Provision Status */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetClirStatusCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CLIR_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetClirOptionReq_struct{
  UINT8 Local;		/**< CLIR presentation as per provision (revoke temporary setting);
                              *    Invoke CLIR (temporary setting = restrict presentation);
                              *    Suppress CLIR (temporary setting = allow presentation) [range: 0-2] */
} CiSsPrimSetClirOptionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CLIR_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetClirOptionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetClirOptionCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_COLP_STATUS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetColpStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_COLP_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetColpStatusCnf_struct{
  CiSsResultCode 	Result;					/**< Result code  \sa CiSsResultCode */
  UINT8 			Local;            		/**< Local CoLP presentation (enable/disable) status [range: 0-1] */
  UINT8 			Provision;        		/**< CoLP provision status [range: 0-2]  */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetColpStatusCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_COLP_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetColpOptionReq_struct{
  UINT8 	Local;		/**< 0 - Disable local CoLP presentation; 1 - Enable local CoLP presentation */
} CiSsPrimSetColpOptionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_COLP_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetColpOptionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetColpOptionCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CUG_CONFIG_REQ">   */
typedef CiEmptyPrim CiSsPrimGetCugConfigReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CUG_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCugConfigCnf_struct{
  CiSsResultCode      Result;		/**< Result code  \sa CiSsResultCode */
  UINT8               TempMode;		/**< 0 - CUG temporary mode disabled; 1 - CUG temporary mode enabled */
  CiSsCugConfigInfo   info;			/**< Temporary (override) CUG configuration information \sa CiSsCugConfigInfo_struct */
} CiSsPrimGetCugConfigCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CUG_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCugConfigReq_struct{
  UINT8               TempMode;		/**< 0 - Disable CUG temporary mode; 1 - Enable CUG temporary mode */
  CiSsCugConfigInfo   info;			/**< Temporary (override) CUG configuration information \sa CiSsCugConfigInfo_struct */
} CiSsPrimSetCugConfigReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CUG_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCugConfigCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetCugConfigCnf;

///////////////////////Michal Bukai - CNAP support

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CNAP_STATUS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetCnapStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CNAP_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCnapStatusCnf_struct{
	CiSsResultCode 	Result;		/**< Result code  \sa CiSsResultCode */
	UINT8 			Local;		/**< Local CNAP presentation (invoke/suppress/revoke) status */
	UINT8 			Provision;	/**< CNAP provision status */
	CiSsErrorCode  ErrorCode;
} CiSsPrimGetCnapStatusCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CNAP_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCnapOptionReq_struct{
UINT8 			Local;		/**< Local CNAP presentation (invoke/suppress/revoke) status */
} CiSsPrimSetCnapOptionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CNAP_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCnapOptionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetCnapOptionCnf;

///////////////////////Michal Bukai - CNAP support

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_REGISTER_CF_INFO_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimRegisterCfInfoReq_struct{
  CiSsCfRegisterInfo   info;			/**< Call forwarding registration information \sa CiSsCfRegisterInfo_struct */
} CiSsPrimRegisterCfInfoReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_REGISTER_CF_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimRegisterCfInfoCnf_struct{
  CiSsResultCode Result;		/**< Result code. \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimRegisterCfInfoCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_ERASE_CF_INFO_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimEraseCfInfoReq_struct{
  CiSsCfEraseInfo   info;			/**< Call forwarding erasure information \sa CiSsCfEraseInfo_struct */
} CiSsPrimEraseCfInfoReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_ERASE_CF_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimEraseCfInfoCnf_struct{
  CiSsResultCode Result;		/**< Result code. \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimEraseCfInfoCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CF_REASONS_REQ">   */
typedef CiEmptyPrim CiSsPrimGetCfReasonsReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CF_REASONS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCfReasonsCnf_struct{
  CiSsResultCode  Result;							/**< Result code  \sa CiSsResultCode */
  UINT8           	NumReasons;					/**< Number of supported CF reasons [range: 0..CICF_NUM_REASONS] */
  UINT8           	Reasons[ CICF_MAX_REASONS ];	/**< List of supported CF reasons \sa CICF_REASON */
} CiSsPrimGetCfReasonsCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CF_ACTIVATION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCfActivationReq_struct{
  UINT8               			Reason;		/**< CF reason (condition) to be activated or deactivated \sa CICF_REASON. */
  CiSsBasicServiceMap 	Classes;		/**< Class (or classes) of service for which CF is to be activated or deactivated \sa CiSsBasicServiceMap  */
  CiBoolean           			Activate;		/**< Activates the call forwarding service. Deactivates the call forwarding service. \sa CCI API Ref Manual */
} CiSsPrimSetCfActivationReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CF_ACTIVATION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCfActivationCnf_struct{
  CiSsResultCode 			Result;		/**< Result code. \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimSetCfActivationCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_INTERROGATE_CF_INFO_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimInterrogateCfInfoReq_struct{
  UINT8               		Reason;		/**< CF reason (condition) to be interrogated \sa CICF_REASON. */
  CiSsBasicServiceMap Classes;		/**< Class (or classes) of service \sa CiSsBasicServiceMap */
} CiSsPrimInterrogateCfInfoReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_INTERROGATE_CF_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimInterrogateCfInfoCnf_struct{
  CiSsResultCode      	Result;		/**< Result code  \sa CiSsResultCode */
  UINT8               		Status;		/**< 0 - Call forwarding not active; 1 - Call forwarding active */
  UINT8               		NumCfInfo;	/**< Number of information structures */
  CiSsCfRegisterInfo   	info[CISS_NUM_SERVICES];	/**< Array of CF registration information structures for various basic services \sa CiSsCfRegisterInfo_struct */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimInterrogateCfInfoCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CW_ACTIVATION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCwActivationReq_struct{
  CiBoolean           		Activate;		/**< TRUE - Activate call waiting service; FALSE - Deactivate call forwarding service \sa CCI API Ref Manual*/
  CiSsBasicServiceMap Classes;		/**< Class (or classes) of service for which call waiting is to be activated or deactivated \sa CiSsBasicServiceMap */
} CiSsPrimSetCwActivationReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CW_ACTIVATION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCwActivationCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimSetCwActivationCnf;

typedef CiEmptyPrim CiSsPrimGetCwOptionReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCwOptionCnf_struct{
  CiSsResultCode  Result;
  UINT8           Local;
} CiSsPrimGetCwOptionCnf;

/** <paramref name="CI_SS_PRIM_SET_CW_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCwOptionReq_struct{
  CiBoolean Local;		/**< Enables/disables local presentation of CW indications \sa CCI API Ref Manual */
} CiSsPrimSetCwOptionReq;

/** <paramref name="CI_SS_PRIM_SET_CW_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCwOptionCnf_struct{
  CiSsResultCode Result;	/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetCwOptionCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCwActiveStatusReq_struct{
  CiSsBasicService Class;
} CiSsPrimGetCwActiveStatusReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCwActiveStatusCnf_struct{
  CiSsResultCode    Result;
  CiSsBasicService  Class;
  UINT8             Status;
} CiSsPrimGetCwActiveStatusCnf;

typedef CiEmptyPrim CiSsPrimGetUssdEnableReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetUssdEnableCnf_struct{
  CiSsResultCode  Result;
  CiBoolean       Enabled;
} CiSsPrimGetUssdEnableCnf;

/** <paramref name="CI_SS_PRIM_SET_USSD_ENABLE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetUssdEnableReq_struct{
  CiBoolean       Enable; 	/**< Enable / disable USSD status indication \sa CCI API Ref Manual */
} CiSsPrimSetUssdEnableReq;

/** <paramref name="CI_SS_PRIM_SET_USSD_ENABLE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetUssdEnableCnf_struct{
  CiSsResultCode Result;	/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetUssdEnableCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_RECEIVED_USSD_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimReceivedUssdInfoInd_struct{
  CiSsUssdStatus   	Status;		/**< USSD status indication \sa CiSsUssdStatus */
  CiSsUssdInfo   	info;		/**< Incoming USSD information \sa CiSsUssdInfo_struct */
  CiSsFailReason 	FailReason;
} CiSsPrimReceivedUssdInfoInd;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_RECEIVED_USSD_INFO_RSP">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimReceivedUssdInfoRsp_struct{
  CiSsUssdInfo   	info;		/**< Outgoing USSD information \sa CiSsUssdInfo_struct */
} CiSsPrimReceivedUssdInfoRsp;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_START_USSD_SESSION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimStartUssdSessionReq_struct{
  CiSsUssdInfo   	info;			/**< Outgoing USSD information \sa CiSsUssdInfo_struct */
} CiSsPrimStartUssdSessionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_START_USSD_SESSION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimStartUssdSessionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimStartUssdSessionCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_ABORT_USSD_SESSION_REQ">   */
typedef CiEmptyPrim CiSsPrimAbortUssdSessionReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_ABORT_USSD_SESSION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimAbortUssdSessionCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
} CiSsPrimAbortUssdSessionCnf;

typedef CiEmptyPrim CiSsPrimGetCcmOptionReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCcmOptionCnf_struct{
  CiSsResultCode  Result;
  CiBoolean       Enabled;
} CiSsPrimGetCcmOptionCnf;

/** <paramref name="CI_SS_PRIM_SET_CCM_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCcmOptionReq_struct{
  CiBoolean       Enable; /**< Enable/disable periodic CCM update indications \sa CCI API Ref Manual */

} CiSsPrimSetCcmOptionReq;

/** <paramref name="CI_SS_PRIM_SET_CCM_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCcmOptionCnf_struct{
  CiSsResultCode Result;	/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetCcmOptionCnf;

typedef CiEmptyPrim CiSsPrimGetAocWarningEnableReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetAocWarningEnableCnf_struct{
  CiSsResultCode  Result;
  CiBoolean       Enabled;
} CiSsPrimGetAocWarningEnableCnf;

/** <paramref name="CI_SS_PRIM_SET_AOC_WARNING_ENABLE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetAocWarningEnableReq_struct{
  CiBoolean       Enable; /**< Enable/disable AoC warning indication \sa CCI API Ref Manual */
} CiSsPrimSetAocWarningEnableReq;

/** <paramref name="CI_SS_PRIM_SET_AOC_WARNING_ENABLE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetAocWarningEnableCnf_struct{
  CiSsResultCode Result; /**< Result code  \sa CiSsResultCode */
} CiSsPrimSetAocWarningEnableCnf;

typedef CiEmptyPrim CiSsPrimGetSsNotifyOptionsReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetSsNotifyOptionsCnf_struct{
  CiSsResultCode  Result;
  CiBoolean       SsiEnabled;
  CiBoolean       SsuEnabled;
} CiSsPrimGetSsNotifyOptionsCnf;

/** <paramref name="CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetSsNotifyOptionsReq_struct{
  CiBoolean SsiEnable;	/**< Enable/disable SSI (supplementary service intermediate) notifications \sa CCI API Ref Manual */
  CiBoolean SsuEnable; /**< Enable/disable SSU (supplementary service unsolicited) notifications \sa CCI API Ref Manual */
} CiSsPrimSetSsNotifyOptionsReq;

/** <paramref name="CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetSsNotifyOptionsCnf_struct{
  CiSsResultCode Result; 	/**< Result code  \sa CiSsResultCode */
} CiSsPrimSetSsNotifyOptionsCnf;

typedef CiEmptyPrim CiSsPrimGetLocalCbLocksReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocalCbLocksCnf_struct{
  CiSsResultCode Result;
  UINT8 NumLocks;
  CiSsLocalCbLockId Facility[CISS_NUM_LOCALCB_LOCKS ];
} CiSsPrimGetLocalCbLocksCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocalCbLockActiveReq_struct{
  CiSsLocalCbLockId Facility;
} CiSsPrimGetLocalCbLockActiveReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocalCbLockActiveCnf_struct{
  CiSsResultCode  Result;
  CiBoolean       Active;
} CiSsPrimGetLocalCbLockActiveCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetLocalCbLockActiveReq_struct{
  CiSsLocalCbLockId Facility;
  CiBoolean         Enable;
  CiPassword   password;
} CiSsPrimSetLocalCbLockActiveReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetLocalCbLockActiveCnf_struct{
  CiSsResultCode Result;
} CiSsPrimSetLocalCbLockActiveCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetLocalCbNotifyOptionReq_struct{
  CiBoolean Enable;
} CiSsPrimSetLocalCbNotifyOptionReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetLocalCbNotifyOptionCnf_struct{
  CiSsResultCode Result;
} CiSsPrimSetLocalCbNotifyOptionCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_CHANGE_CB_PASSWORD_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimChangeCbPasswordReq_struct{
  CiPassword  oldPassword;				/**< Old (existing) password  \sa CCI API Ref Manual */
  CiPassword  newPassword;				/**< New (replacement) password  \sa CCI API Ref Manual */
  CiPassword  newPasswdVerification;	/**< Repeat of new password \sa CCI API Ref Manual */
  CiSsCbServiceCode ssCode;  //add by taow for CQ88404 20150325
} CiSsPrimChangeCbPasswordReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_CHANGE_CB_PASSWORD_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimChangeCbPasswordCnf_struct{
  CiSsResultCode Result;		/**< Result code  \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimChangeCbPasswordCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_STATUS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCbStatusReq_struct{
  CiSsCbServiceCode 	Service;		/**< Call barring service code  \sa CiSsCbServiceCode */
  CiSsBasicService  	Class;		/**< Class of service for which CB status information is requested \sa CiSsCbServiceCode */
} CiSsPrimGetCbStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCbStatusCnf_struct{
  CiSsResultCode  Result;		/**< Result code  \sa CiSsResultCode */
  CiBoolean       	Active;		/**< TRUE - Call barring is active; FALSE - Call barring is inactive \sa CCI API Ref Manual */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetCbStatusCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CB_ACTIVATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCbActivationReq_struct{
  CiSsCbServiceCode   	Service;		/**< Call barring service code  \sa CiSsCbServiceCode */
  CiBoolean           		Activate;		/**< TRUE - Activate call barring service; FALSE - Deactivate call barring service \sa CCI API Ref Manual */
  CiSsBasicServiceMap Classes;		/**< Class (or classes) of service for which call barring is to be activated or deactivated (bit map) \sa CiSsBasicServiceMap */
  CiPassword   password;			/**< Call barring password (if required) \sa CCI API Ref Manual */
} CiSsPrimSetCbActivationReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_SET_CB_ACTIVATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSetCbActivateCnf_struct{
  CiSsResultCode Result;		/**< Result code. \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimSetCbActivateCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_TYPES_REQ">   */
typedef CiEmptyPrim CiSsPrimGetCbTypesReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_TYPES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCbTypesCnf_struct{
  CiSsResultCode    		Result;									/**< Result code  \sa CiSsResultCode */
  UINT8             			NumCbTypes;							/**< Number of supported CB types [range: 0.. CI_NUM_CB_LOCK_CODES] */
  CiSsCbServiceCode 		CbTypes[ CISS_NUM_CB_LOCK_CODES ];	/**< List of supported CB types \sa CiSsCbServiceCode */
} CiSsPrimGetCbTypesCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_BASIC_SVC_CLASSES_REQ">   */
typedef CiEmptyPrim CiSsPrimGetBasicSvcClassesReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_BASIC_SVC_CLASSES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetBasicSvcClassesCnf_struct{
  CiSsResultCode    	Result;							/**< Result code  \sa CiSsResultCode */
  UINT8             		NumClasses;						/**< Number of supported classes [range: 0..CICF_NUM_SERVICES] */
  CiSsBasicService  	Classes[ CISS_NUM_SERVICES ];    /**< List of supported classes \sa CiSsBasicService */
} CiSsPrimGetBasicSvcClassesCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_ACTIVE_CW_CLASSES_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetActiveCwClassesReq_struct{
  CiSsBasicServiceMap Classes;		/**< Bitmap of basic services to be interrogated \sa CiSsBasicServiceMap */
} CiSsPrimGetActiveCwClassesReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_ACTIVE_CW_CLASSES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetActiveCwClassesCnf_struct{
  CiSsResultCode 			Result;			/**< Result code  \sa CiSsResultCode */
  CiSsBasicServiceMap 	ReqClasses;		/**< Requested bitmap of basic services (copied directly from the request) \sa CiSsBasicServiceMap */
  CiSsBasicServiceMap 	ActClasses;		/**< Bitmap of call waiting status for each of the basic services that were interrogated \sa CiSsBasicServiceMap */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetActiveCwClassesCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_MAP_STATUS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCbMapStatusReq_struct{
  CiSsCbServiceCode    	Service;		/**< Call barring service code  \sa CiSsCbServiceCode */
  CiSsBasicServiceMap  	Classes;		/**< Bitmap of basic services to be interrogated \sa CiSsBasicServiceMap */
} CiSsPrimGetCbMapStatusReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_CB_MAP_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetCbMapStatusCnf_struct{
  CiSsResultCode      		Result;			/**< Result code  \sa CiSsResultCode */
  CiSsCbServiceCode   		Service;			/**< Call barring service code  \sa CiSsCbServiceCode */
  CiSsBasicServiceMap 	ReqClasses;		/**< Requested bitmap of basic services (copied directly from the request) \sa CiSsBasicServiceMap */
  CiSsBasicServiceMap 	ActClasses;		/**< Bitmap of call waiting status for each of the basic services that were interrogated \sa CiSsBasicServiceMap */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimGetCbMapStatusCnf;



/* <INUSE> */
/** <paramref name="CI_SS_PRIM_PRIVACY_CTRL_REG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimPrivacyCtrlRegReq_struct
{
  CiBoolean SupportPrivacy;		/**< TRUE enables support for privacy control services; FALSE disables this support \sa CCI API Ref Manual */
} CiSsPrimPrivacyCtrlRegReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_PRIVACY_CTRL_REG_CNF">   */
/**  -
*/
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimPrivacyCtrlRegCnf_struct
{
  CiSsResultCode result;		/**< Result code  \sa CiSsResultCode */
  CiSsErrorCode  ErrorCode; 
} CiSsPrimPrivacyCtrlRegCnf;

/* MOLR request definitions */

#define   CI_SS_MAX_NUM_PRIVATE_EXTENSIONS  						10
#define   CI_SS_MAX_EXTERNAL_ADDRESS_SIZE   						20
#define   CI_SS_MAX_MLC_NUMBER_SIZE          							9
#define   CI_SS_MAX_ASSISTANCE_DATA_SIZE    						38
#define   CI_SS_MAX_EXTENSION_TYPE_SIZE     						16  /* Look at IOC for private MAP extensions */
#define   CI_SS_MAX_EXTENSION_ID_SIZE       							16  /* Section 17.7.11  29.002 */

#define     CI_SS_PRIM_L2_MESSAGE_SIZE                            				251
#define     CI_SS_PRIM_MAX_FACILITY_DATA_LENGTH         				(CI_SS_PRIM_L2_MESSAGE_SIZE - 2)
#define     CI_SS_PRIM_MAX_LOCATION_ESTIMATE_STRING_SIZE      		20
#define     CI_SS_PRIM_MAX_DECIPHERING_KEYS_STRING_SIZE       		15
#define     CI_SS_PRIM_MAX_ADD_LOCATION_ESTIMATE_STRING_SIZE  	91


/* MOLR request typedefs */
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief This is a 'live' invoke handler
 *  \sa CISS_CB_SERVICE_CODE
 * \remarks Common Data Section */
typedef INT16  CiSsPrimInvokeHandle;
/**@}*/


/** \brief Tasks sent to identified by their task IDs  . */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimTaskIdTag
{
    CiSS_PRIM_SAC_TASK_ID,
    CiSS_PRIM_UNKNOWN_TASK                = 0xFF

    /* Any new TaskId which is to be recognized by GENIE should end in the
    ** string "_ID"; conversely, any value which is not to be displayed by
    ** GENIE should NOT end in this string. */

} _CiSsPrimTaskId;

typedef UINT8 CiSsPrimTaskId;

//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsCodeTag
{
  /* all LCS privacy exception classes */
  CI_SS_PRIM_SS_ALL_LCS_PRIVACY_EXCEPTION = 0xB0,
  /* Allow location by any LCS client */
  CI_SS_PRIM_SS_LCS_UNIVERSAL             = 0xB1,
  /* allow location by any value added LCS client to which
   * a call is established from the target MS */
  CI_SS_PRIM_SS_LCS_CALL_RELATED          = 0xB2,
  /* allow location by designated external value added LCS clients */
  CI_SS_PRIM_SS_LCS_CALL_UNRELATED        = 0xB3,
  /* allow location by designated PLMN operator LCS clients */
  CI_SS_PRIM_SS_LCS_PLMN_OPERATOR         = 0xB4,
  /* all Mobile Originating location request classes */
  CI_SS_PRIM_SS_LCS_ALL_MOLR_SS           = 0xC0,
  /* allow an MS to request its own location */
  CI_SS_PRIM_SS_LCS_BASIC_SELF_LOCATION   = 0xC1,
  /* allow an MS to perform self location without interaction with
   * the PLMN for a pre-determined period of time */
  CI_SS_PRIM_SS_LCS_AUTONOMOUS_SELF_LOCATION  = 0xC2,
  /* allow an MS to request transfer of its location to another LCS client */
  CI_SS_PRIM_SS_LCS_TRANSFER_TO_THIRD_PARTY   = 0xC3,
   /* UPGRADE_AGPS */
} _CiSsPrimSsCode;
typedef UINT8 CiSsPrimSsCode;

//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsMolrTypeTag
{
    CI_SS_PRIM_LOCATION_ESTIMATE   = 0,
    CI_SS_PRIM_ASSISTANCE_DATA     = 1,
    CI_SS_PRIM_DECIPHERING_KEYS    = 2
}_CiSsPrimSsLcsMolrType;
typedef UINT8 CiSsPrimSsLcsMolrType;

//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsLocationMethodTag
{
    CI_SS_PRIM_MS_BASED_EOTD       = 0,
    CI_SS_PRIM_MS_ASSISTED_EOTD    = 1,
    CI_SS_PRIM_ASSISTED_GPS        = 2
}_CiSsPrimSsLcsLocationMethod;
typedef UINT8 CiSsPrimSsLcsLocationMethod;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptLocationMethodTag
{
    CiBoolean                                  present;
    CiSsPrimSsLcsLocationMethod     method;
}CiSsPrimSsLcsOptLocationMethod;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptAccuracyTag
{
  CiBoolean         present;
  INT8                 accuracy; /* IMPLICIT OCTET STRING - SIZE 1 */
}CiSsPrimSsLcsOptAccuracy;

//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsResponseTimeCatagoryTag
{
    CI_SS_PRIM_LOW_DELAY           = 0,
    CI_SS_PRIM_DELAY_TOLERANT   = 1
}_CiSsPrimSsLcsResponseTimeCatagory;
typedef UINT8 CiSsPrimSsLcsResponseTimeCatagory;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptResponseTimeTag
{
  CiBoolean                     			       present;
  CiSsPrimSsLcsResponseTimeCatagory      responseTimeCatagory; /* ENUMERATED */
}CiSsPrimSsLcsOptResponseTime;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsExtensionIdTag
{
   INT8         n;   /* OCTET STRING  - should not exceed 16 octets */
   INT8         data[CI_SS_MAX_EXTENSION_ID_SIZE];
}CiSsPrimSsLcsExtensionId;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsExtensionTypeTag
{
   INT8         n;  /* OCTET STRING  - should not exceed 16 octets */
   INT8         data[CI_SS_MAX_EXTENSION_TYPE_SIZE];
}CiSsPrimSsLcsExtensionType;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsPrivateExtListDataTag
{
   CiBoolean                                  extTypePresent;
   CiSsPrimSsLcsExtensionType       extType;
   CiSsPrimSsLcsExtensionId           extId;
}CiSsPrimSsLcsPrivateExtListData;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsPrivateExtensionListTag
{
   INT8                       				n; /* 1 to maxNumOfPrivateExtensions */
   CiSsPrimSsLcsPrivateExtListData      data[CI_SS_MAX_NUM_PRIVATE_EXTENSIONS];
}CiSsPrimSsLcsPrivateExtensionList;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsPcsExtensionsTag
{
   INT8                      _dummy_; /* Not used */
}CiSsPrimSsLcsPcsExtensions;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsExtensionContainerTag
{
   CiBoolean                        			   privateExtensionListPresent;
   CiSsPrimSsLcsPrivateExtensionList      privateExtensionList;
   CiBoolean                        			   pcs_ExtensionsPresent;
   CiSsPrimSsLcsPcsExtensions               pcs_Extensions;
}CiSsPrimSsLcsExtensionContainer;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptExtensionContainerTag
{
   CiBoolean                        			   present;
   CiSsPrimSsLcsExtensionContainer        data;
}CiSsPrimSsLcsOptExtensionContainer;

//ICAT EXPORTED STRUCT
typedef struct  CiSsPrimSsLcsQosTag
{
   CiSsPrimSsLcsOptAccuracy      		   horizontalAccuracy;    /* Optional octet string */
   CiBoolean                     			   verticalCoordReq;      /* IMPLICIT NULL OPTIONAL */
   CiSsPrimSsLcsOptAccuracy      		   verticalAccuracy;      /* Optional octet string */
   CiSsPrimSsLcsOptResponseTime         responseTime;          /* IMPLICIT SEQUENCE */
   CiSsPrimSsLcsOptExtensionContainer  optExtensionContainer; /* IMPLICIT SEQUENCE */
}CiSsPrimSsLcsQos;

//ICAT EXPORTED STRUCT
typedef struct  CiSsPrimSsLcsOptQosTag
{
   CiBoolean         		present;
   CiSsPrimSsLcsQos      lcsQos;
}CiSsPrimSsLcsOptQos;

/** \brief External Address.   */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptExternalAddressTag
{
   CiBoolean     present;                                         /**< Indicates if address is present \sa CCI API Ref Manual. */
   INT8        addressLength;                                     /**< Address length; maximum is 20 */
   INT8        externalAddress[CI_SS_MAX_EXTERNAL_ADDRESS_SIZE];  /**< External address */
}CiSsPrimSsLcsOptExternalAddress;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptClientExternalIdTag
{
   CiBoolean                     			   present;
   CiSsPrimSsLcsOptExternalAddress       optExternalAddress;
   CiSsPrimSsLcsOptExtensionContainer  optExtensionContainer;    /* Implicit sequence */
}CiSsPrimSsLcsOptClientExternalId;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptMlcNumberTag
{
   CiBoolean       present;
   INT8          mlcNumberLength;
   INT8          mlcNumber[CI_SS_MAX_MLC_NUMBER_SIZE];
}CiSsPrimSsLcsOptMlcNumber;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptGpsAssistanceDataTag
{
   CiBoolean       present;
   INT8          assistanceDataLength;
   INT8          assistanceData[CI_SS_MAX_ASSISTANCE_DATA_SIZE];
}CiSsPrimSsLcsOptGpsAssistanceData;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptSupportedGADShapesTag
{
   CiBoolean       present;
   INT16             supportedGADShapesBitMask;     /*Implicit bit string */
}CiSsPrimSsLcsOptSupportedGADShapes;


//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptLcsServiceTypeIdTag
{
   CiBoolean       present;
   INT8          lcsServiceTypeId;
}CiSsPrimSsLcsOptLcsServiceTypeId;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsMOLRDataTag
{
   CiSsPrimSsLcsMolrType                      	lcsMolrType;
   CiSsPrimSsLcsOptLocationMethod        	lcsOptLocationMethod;
   CiSsPrimSsLcsOptQos                   	       lcsOptQos;
   CiSsPrimSsLcsOptClientExternalId       	lcsOptClientExternalId;
   CiSsPrimSsLcsOptMlcNumber              	lcsOptMlcNumber;
   CiSsPrimSsLcsOptGpsAssistanceData   	lcsOptGpsAssistanceData;
   CiSsPrimSsLcsOptSupportedGADShapes  lcsOptSupportedGADShapes;
   CiSsPrimSsLcsOptLcsServiceTypeId    	lcsOptLcsServiceTypeId;
}CiSsPrimSsLcsMOLRData;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_LOCATION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocationReq_struct
{
   CiSsPrimTaskId                		 taskId;	    /**< Application background task ID. It is copied from the APEX interface. \sa CiSsPrimTaskIdTag */
   CiSsPrimInvokeHandle       		moInvokeHandle;		/**< This must correspond to a 'live' invokeHandle associated with an outgoing invoke.  If a matching invoke handle is not found then this signal is not generated. It is copied from the APEX interface. \sa CiSsPrimInvokeHandle */
   CiSsPrimSsCode                		ssCode;				/**< The operationCode is the same in the originating invoke message. \sa CiSsPrimSsCodeTag */
   CiSsPrimSsLcsMOLRData          	lcsMOLRData;		/**< LCS mobile originating location request data \sa CiSsPrimSsLcsMOLRDataTag */
} CiSsPrimGetLocationReq;

/** \brief SS result parameter values   */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsResultParameterTypeTag
{
  CI_SS_PRIM_SS_NO_DATA                    =0,
  CI_SS_PRIM_SS_FORWARD_INFO                ,
  CI_SS_PRIM_SS_CALL_BARRING_INFO           ,
  CI_SS_PRIM_SS_CUG_INFO                    ,
  CI_SS_PRIM_SS_INFO_DATA                   ,
  CI_SS_PRIM_SS_STATUS                      ,
  CI_SS_PRIM_SS_FWD_TO_NUMBER               ,
  CI_SS_PRIM_SS_BS_GROUP_LIST               ,
  CI_SS_PRIM_SS_FWD_FEATURE_LIST            ,
  CI_SS_PRIM_SS_USS_USER_DATA               ,
  CI_SS_PRIM_SS_USS_USER_ARG                ,
  CI_SS_PRIM_SS_RAW_DATA                    ,
  CI_SS_PRIM_SS_PASSWORD                    ,
  CI_SS_PRIM_SS_CLIR_INFO                   ,
  CI_SS_PRIM_SS_LCS_MOLR
}_CiSsPrimSsResultParameterType;
typedef UINT8 CiSsPrimSsResultParameterType;


/** \brief Operation code   */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsOperationCodeTag
{
  CI_SS_PRIM_MO_LCS_MOLR               =115,
  CI_SS_PRIM_MT_LCS_LOCATION_NOTIFY    =116,
}_CiSsPrimSsOperationCode;

typedef UINT8 CiSsPrimSsOperationCode;

/**  \brief  Location estimate result */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptLocationEstimateResultTag
{
   CiBoolean        present;    /**< Indicates if result is present \sa CCI API Ref Manual. */
   INT8           length;
   INT8           data[CI_SS_PRIM_MAX_LOCATION_ESTIMATE_STRING_SIZE]; /**< IMPLICIT OCTET STRING */
}CiSsPrimSsLcsOptLocationEstimateResult;

/**  \brief  Deciphering Keys Result  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptDecipheringKeysResultTag
{
   CiBoolean        present;       /**< Indicates if result is present \sa CCI API Ref Manual. */
   INT8                length;
   INT8               data[CI_SS_PRIM_MAX_DECIPHERING_KEYS_STRING_SIZE]; /**< Fixed size of 15 bytes, implicit octet string */
}CiSsPrimSsLcsOptDecipheringKeysResult;

/**  \brief  Add location estimate result */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptAddLocationEstimateResultTag
{
   CiBoolean        present;         /**< Indicates if result is present \sa CCI API Ref Manual. */
   INT8           length;
   INT8           data[CI_SS_PRIM_MAX_ADD_LOCATION_ESTIMATE_STRING_SIZE]; /**< Implicit octet string */
}CiSsPrimSsLcsOptAddLocationEstimateResult;

/**  \brief  MOLR Result Info */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsMOLRResultInfoTag
{
   CiSsPrimSsLcsOptLocationEstimateResult          optLocEstimateResult;    /**<  Location estimate result - optional \sa CiSsPrimSsLcsOptLocationEstimateResultTag.*/
   CiSsPrimSsLcsOptDecipheringKeysResult          optDecipherKeysResult;    /**<   Deciphering keys result - optional \sa CiSsPrimSsLcsOptDecipheringKeysResultTag.*/
   CiSsPrimSsLcsOptAddLocationEstimateResult     optAddLocEstimateResult;   /**<   Add location estimate result - optional \sa CiSsPrimSsLcsOptAddLocationEstimateResultTag. */
}CiSsPrimSsLcsMOLRResultInfo;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief   MOLR result information */
/** \remarks Common Data Section */
//ICAT EXPORTED UNION
typedef union CiSsPrimSsResultDataTag
{
  CiSsPrimSsLcsMOLRResultInfo         molrResultInfo;  /**< \sa MOLR Result Info CiSsPrimSsLcsMOLRResultInfoTag */
}CiSsPrimSsResultData;

/**@}*/
/** <paramref name="CI_SS_PRIM_GET_LOCATION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocationCnf_struct
{
  CiSsPrimTaskId                   		 taskId; 	/**< Application background task ID. It is copied from the APEX interface. \sa CiSsPrimTaskIdTag */
  CiSsPrimInvokeHandle          		moInvokeHandle; /**< This must correspond to a 'live' invokeHandle associated with an outgoing invoke.  If a matching invoke handle is not found then this signal is not generated. It is copied from the APEX interface. \sa CiSsPrimInvokeHandle */
  CiSsPrimSsOperationCode    		ssOperationCode;   /**< "MOLR type" or "Location notify" type \sa  CiSsPrimSsOperationCodeTag. */
  CiSsPrimSsResultParameterType       ssResultParameterType;  /**< Type of SS result parameter (should be SS_LCS_MOLR) \sa CiSsPrimSsResultParameterTypeTag */
  CiSsPrimSsResultData                      ssResultData;     /**< MO-LR result information (response to MO-LR request info) \sa CiSsPrimSsResultDataTag */
}CiSsPrimGetLocationCnf;

/* MTLR request definitions */
#define   CI_SS_MAX_LCS_NAME_STRING_LENGTH             63
#define   CI_SS_MAX_LCS_CODEWORD_SIZE                  20


/* MTLR request typedefs */
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief */
/** \remarks Common Data Section */
typedef signed   char CiSsPrimSignedInt8;
/**@}*/


/**  \brief LCS notification type values  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsNotificationTypeTag
{
   CI_SS_NOTIFY_LOCATION_ALLOWED                               = 0,
   CI_SS_NOTIFY_AND_VERIFY_LOCATION_ALLOWED_IF_NO_RESPONSE     = 1,
   CI_SS_NOTIFY_AND_VERIFY_LOCATION_NOT_ALLOWED_IF_NO_RESPONSE = 2,
   CI_SS_LOCATION_NOT_ALLOWED                                  = 3
}_CiSsPrimSsLcsNotificationType;

typedef UINT8 CiSsPrimSsLcsNotificationType;

/**  \brief LCS location information */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsLocationEstimateTypeTag
{
   CI_SS_CURRENT_LOCATION               = 0,
   CI_SS_CURRENT_OR_LAST_KNOWN_LOCATION = 1,
   CI_SS_INITIAL_LOCATION               = 2,
   CI_SS_ACTIVATE_DEFERRED_LOCATION     = 3,
   CI_SS_CANCEL_DEFERRED_LOCATION       = 4
}_CiSsPrimSsLcsLocationEstimateType;

typedef UINT8 CiSsPrimSsLcsLocationEstimateType;

/**  \brief LCS location information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsLocationTypeTag
{
   CiSsPrimSsLcsLocationEstimateType        locEstimateType;	/**< LCS Location estimate type \sa  CiSsPrimSsLcsLocationEstimateTypeTag. */
   CiBoolean                      				deferredLocationTypePresent;   /**< Indicated if deferred location type is present \sa  CCI API Ref Manual. */
   INT16                        				deferredLocationType;          /**< Deferred location type */
}CiSsPrimSsLcsLocationType;

/** \brief  LCS data coding scheme */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsDataCodingSchemeTag
{
   INT8        scheme;
}CiSsPrimSsLcsDataCodingScheme;

/** \brief  LCS name string */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsNameStringTag
{
   INT8        length;
   INT8        name[CI_SS_MAX_LCS_NAME_STRING_LENGTH];
}CiSsPrimSsLcsNameString;

/** \brief  LCS format indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsFormatIndicatorTag
{
    CI_SS_FORMAT_INDICATOR_LOGICAL_NAME       =  0,
    CI_SS_FORMAT_INDICATOR_EMAIL_ADDRESS      =  1,
    CI_SS_FORMAT_INDICATOR_MSISDN             =  2,
    CI_SS_FORMAT_INDICATOR_URL                =  3,
    CI_SS_FORMAT_INDICATOR_SIP_URL            =  4
}_CiSsPrimSsLcsFormatIndicator;
typedef UINT8 CiSsPrimSsLcsFormatIndicator;

/** \brief  LCS format indicator */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptFormatIndicatorTag
{
    CiBoolean               present; /**< Indicates if format indicator is present \sa CCI API Ref Manual. */
    CiSsPrimSsLcsFormatIndicator  formatIndicator;  /**< Format indicator \sa CiSsPrimSsLcsFormatIndicatorTag. */
}CiSsPrimSsLcsOptFormatIndicator;

/** \brief  Client Name */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptClientNameTag
{
    CiBoolean                     				present; 	/**< Indicates if name is present \sa CCI API Ref Manual. */
    CiSsPrimSsLcsDataCodingScheme          dataCodingScheme;  /**< Data coding scheme \sa  CiSsPrimSsLcsDataCodingSchemeTag */
    CiSsPrimSsLcsNameString             		nameString;   /**< Name string \sa  CiSsPrimSsLcsNameStringTag*/
    CiSsPrimSsLcsOptFormatIndicator     	optFormatIndicator;  /**< Format indicator \sa  CiSsPrimSsLcsOptFormatIndicatorTag */
}CiSsPrimSsLcsOptClientName;

/** \brief LCS requestor ID */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptRequestorIDTag
{
    CiBoolean                     present;  /**< Indicates if ID is present \sa CCI API Ref Manual. */
    CiSsPrimSsLcsDataCodingScheme       dataCodingScheme;    /**< Data coding scheme \sa  CiSsPrimSsLcsDataCodingSchemeTag*/
    CiSsPrimSsLcsNameString             requestorIdString;   /**< Name string \sa  CiSsPrimSsLcsNameStringTag*/
    CiSsPrimSsLcsOptFormatIndicator     optFormatIndicator;  /**< Format indicator. \sa  CiSsPrimSsLcsOptFormatIndicatorTag */
}CiSsPrimSsLcsOptRequestorID;

/** \brief LCS Codeword */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptCodewordTag
{
    CiBoolean                     				present;   /**< Indicates if codeword is present \sa CCI API Ref Manual. */
    CiSsPrimSsLcsDataCodingScheme          dataCodingScheme;   /**< Data coding scheme \sa  CiSsPrimSsLcsDataCodingSchemeTag*/
    INT8                       					length;        /**< Codeword length */
    INT8                        					codewordString[CI_SS_MAX_LCS_CODEWORD_SIZE];   /**< Codeword  */
}CiSsPrimSsLcsOptCodeword;

/** \brief LCS Service type ID */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsOptServiceTypeIdTag
{
    CiBoolean                     present; 	/**< Indicates if service type ID is present \sa CCI API Ref Manual. */
    CiSsPrimSignedInt8       serviceTypeId; /**< Service type ID \sa CiSsPrimSignedInt8 */
}CiSsPrimSsLcsOptServiceTypeId;

/** \brief LCS client location-notification data */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsLocNotifyInfoTag
{
    CiSsPrimSsLcsNotificationType         notifyType; /**< LCS notification type \sa CiSsPrimSsLcsNotificationTypeTag  */
    CiSsPrimSsLcsLocationType             locationType; /**< LCS location information \sa CiSsPrimSsLcsLocationTypeTag  */
    CiSsPrimSsLcsOptClientExternalId    lcsOptClientExternalId;  /**< LCS client external ID - optional value  \sa CiSsPrimSsLcsOptClientExternalIdTag  */
    CiSsPrimSsLcsOptClientName          lcsOptClientName;        /**< LCS client name - optional value  \sa CiSsPrimSsLcsOptClientNameTag  */
    CiSsPrimSsLcsOptRequestorID         lcsOptRequestorId;       /**< LCS requestor ID - optional value  \sa CiSsPrimSsLcsOptRequestorIDTag  */
    CiSsPrimSsLcsOptCodeword            lcsOptCodeword;          /**< LCS codeword - optional value  \sa CiSsPrimSsLcsOptCodewordTag */
    CiSsPrimSsLcsOptServiceTypeId      lcsOptServiceTypeId;      /**< LCS service type ID - optional value  \sa CiSsPrimSsLcsOptServiceTypeIdTag */
}CiSsPrimSsLcsLocNotifyInfo;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_LOCATION_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimLocationInd_struct
{
   CiSsPrimTaskId                     	taskId;				/**< Application background task ID. It is copied from the APEX interface. \sa CiSsPrimTaskIdTag */
   CiSsPrimInvokeHandle           	mtInvokeHandle;		/**< This must correspond to a 'live' invokeHandle associated with an
                                                                     *     outgoing invoke.  If a matching invoke handle is not found then this
                                                                     *     signal is not generated. It is copied from the APEX interface. \sa CiSsPrimInvokeHandle. */
   CiSsPrimSsLcsLocNotifyInfo    	ssLcsLocNotifyInfo;	/**<  LCS client location-notification data. For example, it could be used to identify a
                                                                     *     location service provider. \sa CiSsPrimSsLcsLocNotifyInfoTag */
} CiSsPrimLocationInd;


/** \brief Location notification response values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiSsPrimSsLcsVerificationResponseTag
{
   CI_SS_PERMISSION_DENIED   =  0,
   CI_SS_PERMISSION_GRANTED  =  1
}_CiSsPrimSsLcsVerificationResponse;
typedef UINT8 CiSsPrimSsLcsVerificationResponse;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimSsLcsLocationNotificationResTag
{
   CiBoolean                      present;	/**< Indicates if location notification response is present \sa CCI API Ref Manual. */
   CiSsPrimSsLcsVerificationResponse    verificationResponse; /**< Location notification response \sa CiSsPrimSsLcsVerificationResponseTag. */

}CiSsPrimSsLcsLocationNotificationRes;

/** <paramref name="CI_SS_PRIM_LOCATION_VERIFY_RSP">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimLocationVerifyRsp_struct
{
   CiSsPrimTaskId                          taskId; 	/**< Application background task ID. It is copied from the APEX interface. \sa CiSsPrimTaskIdTag */
   CiSsPrimInvokeHandle                mtInvokeHandle;  /**< This must correspond to a 'live' invokeHandle associated with an outgoing invoke.  If a matching invoke handle is not found then this signal is not generated. It is copied from the APEX interface. \sa \sa CiSsPrimInvokeHandle.\sa CiSsPrimInvokeHandle. */
   CiSsPrimSsLcsLocationNotificationRes    response;  /**< Data indicating to the network entity whether a positioning session can take place. \sa CiSsPrimSsLcsLocationNotificationResTag */
}CiSsPrimLocationVerifyRsp;


typedef CiEmptyPrim CiSsPrimGetLcsNwstateReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLcsNwstateCnf_struct
{
  CiSsResultCode result;
  CiSsLcsNwState nwState;
} CiSsPrimGetLcsNwstateCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimLcsNwstateCfgIndReq_struct
{
  CiBoolean reportChanges;

} CiSsPrimLcsNwstateCfgIndReq;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimLcsNwstateCfgIndCnf_struct
{
  CiSsResultCode result;
} CiSsPrimLcsNwstateCfgIndCnf;

//ICAT EXPORTED STRUCT
typedef struct CiSsPrimLcsNwstateInd_struct
{
  CiSsLcsNwState nwState;
} CiSsPrimLcsNwstateInd;



/* ********************************************************************************************* *
 * enum list for the completion status of service request
 */

/**  \brief SS request completion status values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_SS_REQ_STATUS {

  CI_SS_ACTIVE,
  CI_SS_REGISTERED,
  CI_SS_PROVISIONED,
  CI_SS_QUIESCENT,

  CI_SS_NUM_REQ_STATUS

} _CiSsReqStatus;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SS request status
 * \sa CI_SS_REQ_STATUS */
/** \remarks Common Data Section */
typedef UINT8 CiSsReqStatus;
/**@}*/

#define     CI_MAX_FACILITY_DATA_LENGTH            249

//ICAT EXPORTED STRUCT
typedef struct CiSsFacilityTag
{
    UINT16                           dataLength;
    UINT8                            data[CI_MAX_FACILITY_DATA_LENGTH];
}
CiSsFacility;


/* ********************************************************************************************* *
 * CiSsPrimServiceRequestCompleteInd
 *
 * Supplementary Service Request Complete notification, provides
 * the state of an SS
 *
 * This notification is sent in reply to a supplementary service Request
 * and it's based on the status information returned by the protocol stack.
 * The returned status is decoded from the Facility Information Element, when
 * present, by the protocol stack as follows: ACTIVE, REGISTERED, PROVISIONED,
 * QUIESCENT.
 *
 * This indication may come right after a CI_SS_xx_CNF reply primitive.
 *
 */
/** <paramref name="CI_SS_PRIM_SERVICE_REQUEST_COMPLETE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimServiceRequestCompleteInd_struct {
  CiSsReqStatus    ReqStatus; /**< Completion status \sa CiSsReqStatus */ 
  CiBoolean                   facilityPresent;
  CiSsFacility                  facilityOptional;
} CiSsPrimServiceRequestCompleteInd;


/* ********************************************************************************************* *
 * CiSsPrimGetColrStatusReq
 *
 * Interrogation of the CoLR Service support
 *
 */
/** <paramref name="CI_SS_PRIM_GET_COLR_STATUS_REQ"> */
typedef CiEmptyPrim CiSsPrimGetColrStatusReq;

/** <paramref name="CI_SS_PRIM_GET_COLR_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetColrStatusCnf_struct{
  CiSsResultCode    Result;           /**< Result code  \sa CiSsResultCode*/
  UINT8             Local;            /**< Local CoLR presentation status - not available */
  UINT8             Provision;        /**< CoLR provision status */
  CiSsErrorCode  ErrorCode; 

} CiSsPrimGetColrStatusCnf;

/* ********************************************************************************************* *
 * EMLPP
 */

/** <paramref name="CI_SS_PRIM_INTERROGATE_EMLPP_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiSsPrimInterrogateEmlppInfoReq;

/** <paramref name="CI_SS_PRIM_INTERROGATE_EMLPP_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimInterrogateEmlppInfoCnf_struct{
  CiSsResultCode        Result;                  /**< Result code  \sa CiSsResultCode */
  CiCcEmlppCallPriority defaultCallPriority;     /** Identifies the default priority level which is activated in the network. coded according to 3GPP TS 24.008 section 10.5.1.11. */
  CiCcEmlppCallPriority maxCallPriority;         /** Identifies the maximum priority level for which the service subscriber has a subscription in the network. coded according to 3GPP TS 24.008 section 10.5.1.11. */
} CiSsPrimInterrogateEmlppInfoCnf;

/** <paramref name="CI_SS_PRIM_REGISTER_EMLPP_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimRegisterEmlppInfoReq_struct{
      CiCcEmlppCallPriority defaultCallPriority;  /** Identifies the default priority level to be activated in the network. coded according to 3GPP TS 24.008 section 10.5.1.11. */
} CiSsPrimRegisterEmlppInfoReq;

/** <paramref name="CI_SS_PRIM_REGISTER_EMLPP_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimRegisterEmlppInfoCnf_struct{
  CiSsResultCode        Result;                   /**< Result code  \sa CiSsResultCode */
} CiSsPrimRegisterEmlppInfoCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_MMI_CODE_FDN_CHECK_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimMmiCodeFdnCheckReq_struct{
    CHAR             scString[CI_MAX_ADDRESS_LENGTH];  /**< SC code number */

    CiPrimitiveID    ssPrimId;     /**< Primitive ID for SS service group  \sa CiPrimitiveID */
    CiSsUssdInfo     ssData;       /**< Request data with max structure size for SS service group  \sa CiSsUssdInfo */
} CiSsPrimMmiCodeFdnCheckReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_MMI_CODE_FDN_CHECK_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimMmiCodeFdnCheckCnf_struct{
  CiSsResultCode     result; /**< Result code  \sa CiSsResultCode */
  
  CiPrimitiveID    ssPrimId;     /**< Primitive ID for SS service group  \sa CiPrimitiveID */
  CiSsUssdInfo     ssData;       /**< Request data with max structure size for SS service group  \sa CiSsUssdInfo */
} CiSsPrimMmiCodeFdnCheckCnf;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_LOCAL_PROFILE_REQ">   */
typedef CiEmptyPrim CiSsPrimGetLocalProfileReq;

/* <INUSE> */
/** <paramref name="CI_SS_PRIM_GET_LOCAL_PROFILE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiSsPrimGetLocalProfileCnf_struct{
  CiSsResultCode     result; /**< Result code  \sa CiSsResultCode */
  
  UINT8         clipOption;
  UINT8         clirOption;
  UINT8         colpOption;  
  UINT8         cdipOption;
  
  UINT8         cwOption;
  UINT8         cnapOption;
} CiSsPrimGetLocalProfileCnf;


/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_ss_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_SS_NUM_CUST_PRIM is set to 0 in the "ci_ss_cust.h" file.
 */
#include "ci_ss_cust.h"

#define CI_SS_NUM_PRIM CI_SS_NUM_COMMON_PRIM + CI_SS_NUM_CUST_PRIM

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_SS_NUM_PRIM CI_SS_NUM_COMMON_PRIM

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

#endif /* _CI_SS_H_ */

/*                      end of ci_ss.h
--------------------------------------------------------------------------- */

