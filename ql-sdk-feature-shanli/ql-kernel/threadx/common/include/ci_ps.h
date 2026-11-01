/*------------------------------------------------------------
(C) Copyright [2006-2009] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_ps.h
Description : Data types file for the PS Service Group
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

#if !defined(_CI_PS_H_)
#define _CI_PS_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_cfg.h"
#include "ci_api_types.h"

/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_PS_VER_MAJOR 6
//#define CI_PS_VER_MINOR 0
#define CI_PS_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version

/* ----------------------------------------------------------------------------- */

/* CI_PS Primitive ID definitions */
/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_PS_PRIM
{
    CI_PS_PRIM_SET_ATTACH_STATE_REQ = 1,					/**< \brief Requests to attach ME to, or detach ME from, the packet domain service  \details */
    CI_PS_PRIM_SET_ATTACH_STATE_CNF,						/**< \brief Confirms a request and attaches ME to, or detaches ME from, the packet domain service  \details */
    CI_PS_PRIM_GET_ATTACH_STATE_REQ,						/**< \brief Requests to get the current packet domain service state \details */
    CI_PS_PRIM_GET_ATTACH_STATE_CNF,						/**< \brief Confirms a request and returns the current packet domain service state \details */
    CI_PS_PRIM_DEFINE_PDP_CTX_REQ,							/**< \brief Requests to define a PDP context for a specified CID \details   */
    CI_PS_PRIM_DEFINE_PDP_CTX_CNF,							/**< \brief Confirms a request to define a PDP context for a specified CID
    														 * \details If the PDP context address field is NULL, a dynamic address is requested.  */
    CI_PS_PRIM_DELETE_PDP_CTX_REQ,							/**< \brief Requests to delete a PDP context \details */
    CI_PS_PRIM_DELETE_PDP_CTX_CNF,							/**< \brief Confirms a request to delete a PDP context  \details */
    CI_PS_PRIM_GET_PDP_CTX_REQ,							/**< \brief Requests to get a PDP context definition \details */
    CI_PS_PRIM_GET_PDP_CTX_CNF = 10,								/**< \brief Confirms a request and returns the PDP context setting \details */
    CI_PS_PRIM_GET_PDP_CTX_CAPS_REQ,						/**< \brief Requests the PDP context capabilities supported by the cellular subsystem \details   */
    CI_PS_PRIM_GET_PDP_CTX_CAPS_CNF,						/**< \brief Confirms a request and returns the PDP context capabilities supported by the cellular subsystem \details   */
    CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ,					/**< \brief Requests to activate (or deactivate) one or all PDP contexts \details */
    CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF,					/**< \brief Confirms a request and activates (or deactivates) one or all PDP contexts \details */
    CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_REQ,				/**< \brief Requests to get the current activation state of all defined PDP contexts  \details   */
    CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_CNF,				/**< \brief Confirms a request and returns the current activation state of all defined PDP contexts \details   */
    CI_PS_PRIM_ENTER_DATA_STATE_REQ,						/**< \brief Requests to notify the cellular subsystem that the application subsystem is entering a data state, which means it is now going to send or receive packet data
    													 * \details This request triggers a PDP attach procedure and/or a PDP context activation procedure if they have not already been generated.
    													 * The parameter optimizedData enables the optimized ACI data plane.
    													 * This parameter must be set to TRUE to use the optimized DATA service group primitives.
    													 * Note that the option not to use the ACI optimized data plane is supported for backward compatibility.   */
    CI_PS_PRIM_ENTER_DATA_STATE_CNF,						/**< \brief Confirms a request and notifies the cellular subsystem that the application subsystem has entered a data state
    													 * \details Now, the cellular subsystem can start using the DATA service group
    *  primitives to send and receive data over the packet service domain. */
    CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_IND,					/**< \brief Indicates that a network initiated the activation or modification of a PDP context \details */
    CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_RSP = 20,					/**< \brief Responds to a mobile terminated PDP context indication \details   */
    CI_PS_PRIM_MT_PDP_CTX_ACTED_IND,						/**< \brief Indicates the mobile terminated PDP context is activated after manual or auto answer
    													 * \details The cellular subsystem assigns the CID (context ID) for the MT PDP context.  */
    CI_PS_PRIM_SET_GSMGPRS_CLASS_REQ,					/**< \brief Requests to set the mobile class for GSM/GPRS \details This primitive only applies to GSM/GPRS networks.  */
    CI_PS_PRIM_SET_GSMGPRS_CLASS_CNF,					/**< \brief Confirms the request and sets the mobile class for GSM/GPRS \details This primitive only applies to GSM/GPRS networks.  */
    CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ,					/**< \brief Requests the current setting of the GSM/GPRS mobile class \details This primitive only applies to GSM/GPRS networks.  */
    CI_PS_PRIM_GET_GSMGPRS_CLASS_CNF,					/**< \brief Confirms a request and gets the current GSM/GPRS mobile class \details This only applies to GSM/GPRS networks.  */
    CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ,					/**< \brief Requests the supported GSM/GPRS mobile classes \details   */
    CI_PS_PRIM_GET_GSMGPRS_CLASSES_CNF,					/**< \brief Confirms a request and returns the supported GSM/GPRS mobile classes \details  This only applies to GSM/GPRS networks. */
    CI_PS_PRIM_ENABLE_NW_REG_IND_REQ,						/**< \brief Requests to enable or disable GPRS network registration status reports \details   */
    CI_PS_PRIM_ENABLE_NW_REG_IND_CNF,						/**< \brief Confirms a request and enables or disables GPRS network registration status reports \details   */
    CI_PS_PRIM_NW_REG_IND = 30,									/**< \brief Indicates the GPRS network registration status \details GPRS network indications may be enabled or disabled by CI_PS_PRIM_ENABLE_NW_REG_IND_REQ.
    *  This indication is disabled by default. No explicit response is required.  */
    CI_PS_PRIM_SET_QOS_REQ,									/**< \brief Requests to set the QoS profile for a PDP context
    														 * \details The ME checks the minimum acceptable profile against the negotiated profile returned in the Activate PDP Context Accept message.
    														 * The required quality of service profile is used when the ME sends an Activate PDP Context Request message to the network.
    														 * This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_REQ for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_SET_QOS_CNF,									/**< \brief Confirms a request and sets the QoS profile
    														 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_CNF for 3G (R99) QoS profile parameters.   */
    CI_PS_PRIM_DEL_QOS_REQ,									/**< \brief Requests to delete the QoS profile for a PDP context
    														 * \details If a PDP context does not have a minimum or required
    *   QoS profile, the QoS is determined by the network on PDP context activation.
    														 * This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_DEL_3G_QOS_REQ for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_DEL_QOS_CNF,									/**< \brief Confirms a request and deletes the QoS profile setting
    														 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_DEL_3G_QOS_CNF for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_GET_QOS_REQ,									/**< \brief Requests the QoS profile for a PDP context
    														 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_REQ for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_GET_QOS_CNF,									/**< \brief Confirms a request and gets the QoS profile for a PDP context
    														 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_CNF for 3G (R99) QoS profile parameters.*/
    /*Michal Bukai - AutoAttach Configuration - Samsung - START*/
    CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_REQ,			/**< \brief Configure auto attach to PS domain on power up
    													* \details The configuration will be saved in NVM and will be effective in the next power up.  */
    CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_CNF,			/**< \brief  Confirms the request and updates NVM auto attach configuration \details */
    /*Michal Bukai - AutoAttach Configuration - Samsung - End*/
    CI_PS_PRIM_MT_PDP_CTX_REJECTED_IND,					/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_PS_PRIM_PDP_CTX_DEACTED_IND = 40,						/**< \brief Indicates that the PDP context has been deactivated
    													 * \details This indication is sent if PS event reports are enabled; see CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ.*/
    CI_PS_PRIM_PDP_CTX_REACTED_IND,						/**< \brief \details NOT SUPPORTED REMOVE FROM API  */
    CI_PS_PRIM_DETACHED_IND,							    /**< \brief Indicates that the ME has detached from the packet service domain
    													 * \details The indication is sent if PS event reports are enabled; see CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ.  */
    CI_PS_PRIM_GPRS_CLASS_CHANGED_IND,					/**< \brief Indicates that the GSM/GPRS mobile class has changed \details   */
    CI_PS_PRIM_GET_DEFINED_CID_LIST_REQ,					/**< \brief Requests the defined PDP context identifiers list \details   */
    CI_PS_PRIM_GET_DEFINED_CID_LIST_CNF,					/**< \brief Confirms a request and returns the defined PDP context identifiers list \details   */
    CI_PS_PRIM_GET_NW_REG_STATUS_REQ,						/**< \brief Requests the GPRS network registration status \details   */
    CI_PS_PRIM_GET_NW_REG_STATUS_CNF,						/**< \brief Confirms a request and returns the GPRS network registration status \details   */
    CI_PS_PRIM_GET_QOS_CAPS_REQ,							/**< \brief Requests the QoS capabilities
    													 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_CAPS_REQ for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_GET_QOS_CAPS_CNF,							/**< \brief Confirms a request and returns the QoS capabilities
    													 * \details This is only used for 2.5G (R97) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_3G_QOS_CAPS_CNF for 3G (R99) QoS profile parameters.*/
    CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ = 50,				/**< \brief Requests to enable or disable PS event reports
    													 * \details By default, event reporting indications are enabled.
    													 * Event indications include the following: \n
    													 * CI_PS_PRIM_PDP_CTX_DEACTED_IND \n
    													 * CI_PS_PRIM_DETACHED_IND */
    CI_PS_PRIM_ENABLE_EVENTS_REPORTING_CNF,				/**< \brief Confirms a request and enables or disables PS event reports \details   */

    /* SCR #1401348: 3G Quality of Service (QoS) primitives */
    CI_PS_PRIM_GET_3G_QOS_REQ,								/**< \brief Requests the 3G QoS profile for a PDP context
    														 * \details This is only used for 3G (R99) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_QOS_REQ for 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_GET_3G_QOS_CNF,								/**< \brief Confirms a request and returns the 3G QoS profile for a PDP context
    														 * \details This is only used for 3G (R99) QoS profile parameters.
    														 * Use CI_PS_PRIM_GET_QOS_CNF for 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_SET_3G_QOS_REQ,								/**< \brief Requests to set a 3G QoS profile for PDP context activation
    														 * \details The negotiated QoS profile cannot be written by this request.
    														 * If the qosType parameter is set to CI_PS_3G_QOSTYPE_NEG, CCI returns an error indication.
    *    The required and minimum quality of service profiles are used when the MT sends an Activate PDP Context Request for a primary or
    *    secondary PDP context or a Modify PDP Context Request to the network.
    														 * This primitive is used to set 3G (R99) QoS profile parameters
    														 * Use CI_PS_PRIM_SET_QOS_REQ to set the 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_SET_3G_QOS_CNF,								/**< \brief Confirms a request and sets a 3G QoS profile for a PDP context
    														 * \details This is only used for 3G (R99) QoS profile parameters.
    														 *  Use CI_PS_PRIM_SET_QOS_CNF for 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_DEL_3G_QOS_REQ,								/**< \brief Requests to delete the 3G QoS profile for a PDP context
    														 * \details The negotiated QoS profile cannot be deleted by this request.
    														 * If the qosType parameter is set to CI_PS_3G_QOSTYPE_NEG, CCI returns an error indication.
    														 * If a PDP context does not have a minimum or required QoS profile,
    														 * the QoS is determined by the network on PDP context activation.
    														 * This is only used for 3G (R99) QoS profile parameters.
    														 * Use CI_PS_PRIM_DEL_QOS_REQ for 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_DEL_3G_QOS_CNF,								/**< \brief Confirms a request and deletes the 3G QoS profile
    														 * \details This is only used for 3G (R99) QoS profile parameters.
    														 * Use CI_PS_PRIM_DEL_QOS_CNF for 2.5G (R97) QoS profile parameters. */

    CI_PS_PRIM_GET_3G_QOS_CAPS_REQ,						/**< \brief Requests the 3G QoS capabilities
    													 * \details This is only used for the 3G (R99) QoS profile parameters.
    													 * Use CI_PS_PRIM_GET_QOS_CAPS_REQ for 2.5G (R97) QoS profile parameters.*/
    CI_PS_PRIM_GET_3G_QOS_CAPS_CNF,						/**< \brief Confirms a request and gets the 3G QoS capabilities
    													 * \details This is only used for 3G (R99) QoS profile parameters.
    													 * Use CI_PS_PRIM_GET_QOS_CAPS_CNF for 2.5G (R97) QoS profile parameters.  */

    /* SCR #1438547: Secondary PDP Context primitives */
    CI_PS_PRIM_DEFINE_SEC_PDP_CTX_REQ = 60,						/**< \brief Requests to define a secondary PDP context \details   */
    CI_PS_PRIM_DEFINE_SEC_PDP_CTX_CNF,						/**< \brief Confirms a request to define a secondary PDP context \details   */
    CI_PS_PRIM_DELETE_SEC_PDP_CTX_REQ,					/**< \brief Requests to delete a secondary PDP context
    													 * \details An error is returned if the secondary PDP context does not exist.  */
    CI_PS_PRIM_DELETE_SEC_PDP_CTX_CNF,						/**< \brief Confirms a request to delete a secondary PDP context \details   */
    CI_PS_PRIM_GET_SEC_PDP_CTX_REQ,						/**< \brief Requests a secondary PDP context definition
    													 * \details An error is returned if the secondary PDP context does not exist. */
    CI_PS_PRIM_GET_SEC_PDP_CTX_CNF,						/**< \brief Confirms a request and returns the secondary PDP context definition  \details  An error is returned if the secondary PDP context does not exist. */

    /* SCR #1438547: traffic flow template (TFT) primitives */
    CI_PS_PRIM_DEFINE_TFT_FILTER_REQ,						/**< \brief Requests to define a traffic flow template (TFT) packet filter
    													 * \details Traffic flow templates are described in 3GPP TS 23.060 section 15.3.
    													 * Each PDP context connected to a particular PDP address and APN may be associated with a traffic flow template (TFT). (TFTs enable
    													 * filtering of downlink IP packets.)
    													 * A TFT contains one to eight packet filters.
    													 * The use of traffic flow templates allows multiple PDP contexts
    													 * (each with a different quality of service) to share the same PDP address.
    													 * The TFT packet filters are used to route incoming IP packets to their appropriate PDP contexts.
    													 * Only one PDP context may exist without an associated TFT, and this PDP context
    													 * is considered the default
    													 * PDP context. The network routes downlink packets
    													 * to this PDP context if none of the TFT packet filters apply.
    													 * A TFT, if one exists, is always associated with a PDP context during secondary PDP context activation.
    													 * A TFT may be added to an activated PDP context (either a primary or a secondary context)
    													 * using the MS-initiated PDP context modify procedure, which is initiated by a CI_PS_PRIM_MODIFY_PDP_CTX_REQ request.
    *  The packet filter contents field encoding is specified in 3GPP TS 24.008 Table 10.5.162 (Section 10.5.6.12).
    *  An error is returned if no more TFT packet filters are allowed.  */
    CI_PS_PRIM_DEFINE_TFT_FILTER_CNF,						/**< \brief Confirms a request and defines a TFT packet filter \details   */
    CI_PS_PRIM_DELETE_TFT_REQ,								/**< \brief Requests to delete the traffic flow template (TFT) associated with a PDP context \details All packet filters that comprise the indicated TFT are deleted.
    *    An error is returned when: \n
    *    No TFT exists for the indicated PDP context. \n
    *    The PDP context itself (either primary or secondary) is not defined. \n
    *    More than one PDP context is using a single PDP address, and deleting this TFT would violate the rule that only one PDP
    *        context using a particular PDP address may exist without a TFT associated with it. \n
    *    See 3GPP TS 23.060  section 15.3.1 (Rules for Operations on TFTs).  */
    CI_PS_PRIM_DELETE_TFT_CNF,								/**< \brief Confirms a request and deletes the traffic flow template \details   */
    CI_PS_PRIM_GET_TFT_REQ = 70,									/**< \brief Requests to get the traffic flow template (TFT) associated with a PDP context \details  Requests a list of all packet filters that comprise the TFT for the specified PDP context.
    *   An error is returned if a TFT does not exist for the indicated PDP context, or if the PDP context (either primary or secondary) is not
    *   defined. */
    CI_PS_PRIM_GET_TFT_CNF,									/**< \brief Confirms a request and gets the traffic flow template (TFT) associated with a PDP context \details   */

    /* SCR TBD: PDP context modify primitives */
    CI_PS_PRIM_MODIFY_PDP_CTX_REQ,							/**< \brief Requests to modify one PDP context or all active PDP contexts \details Allows the quality of service (QoS) and/or the traffic flow template (TFT) to be modified for a PDP context that has already been
    *  activated. This request can be used for either primary or secondary PDP contexts.
    *  Before issuing this request, set up or modify the QoS and/or TFT, using the appropriate CI requests.  */
    CI_PS_PRIM_MODIFY_PDP_CTX_CNF,							/**< \brief Confirms a request and modifies one PDP context or all active PDP contexts \details   */
    CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ,						/**< \brief Requests to get a list of context identifiers for all active PDP contexts \details This request is similar to CI_PS_PRIM_GET_DEFINED_CID_LIST_REQ except that it only returns information for active PDP contexts.
    *  It is provided to support the same functionality as the "AT+CGCMOD=?" command. See 3GPP TS 27.007 section 10.1.11.  */
    CI_PS_PRIM_GET_ACTIVE_CID_LIST_CNF,						/**< \brief Confirms a request and returns a list of context identifiers for all active PDP contexts  \details   */
    CI_PS_PRIM_REPORT_COUNTER_REQ,						/**< \brief Requests to configure the PDP Context Data Counter report
    													 * \details Data counters are maintained by the protocol stack for all active PDP contexts.
    													 * Data counter values are reported to the application subsystem using CI_PS_PRIM_COUNTER_IND.
    *  This request is rejected if the control plane has not been attached to packet domain services or there are no active PDP contexts.  */
    CI_PS_PRIM_REPORT_COUNTER_CNF,						/**< \brief Confirms a request and configures the PDP Context Data Counter report \details   */
    CI_PS_PRIM_RESET_COUNTER_REQ,			/**< \brief Requests to reset PDP context data counters
    									 * \details Data counters are maintained by the protocol stack for all active PDP contexts.
    									 * Depending on the parameter settings, this request resets the data counters to zero for one or all active PDP contexts.
    									 * This request is rejected if: \n
    *  The Control Plane is not attached to Packet Domain services. \n
    *  There are no active PDP contexts. \n
    *  The doAll parameter is FALSE and the CID parameter is invalid or does not specify an active PDP context.  */
    CI_PS_PRIM_RESET_COUNTER_CNF,							/**< \brief Confirms a request and resets PDP context data counters \details   */
    CI_PS_PRIM_COUNTER_IND = 80,									/**< \brief Indicates a PDP context data counter report \details  CCI sends this indication on request or periodically, as configured by CI_PS_PRIM_REPORT_COUNTER_REQ. If a periodic report cycle
    *  is stopped, this indication is disabled.
    *  The totals indicate the number of bytes (octets) sent and received since the data counters were last reset. \n
    *  The totalULBytes counter is the total number of uplink data octets before compression (if any). \n
    *  The totalDLBytes counter is the total number of downlink data octets after decompression (if any).  \n
    *  See also CI_PS_PRIM_RESET_COUNTER_REQ. */

    CI_PS_PRIM_SEND_DATA_REQ,								/**< \brief \details NOT SUPPORTED REMOVE FROM API  */

    CI_PS_PRIM_SEND_DATA_CNF,								/**< \brief \details NOT SUPPORTED REMOVE FROM API  */

    /* Michal Bukai & Boris Tsatkin  AT&T Smart Card support - Start*/
    /*** AT&T- Smart Card  CI_PS_PRIM_ ACL SERVICE: LIST , SET , EDIT   -BT6 */
    CI_PS_PRIM_SET_ACL_SERVICE_REQ,       /**< \brief Requests to enable or disable APN control list (ACL) service
    									 * \details PIN2 must be verified (using CI_SIM_PRIM_OPERCHV_REQ) before using this request */
    CI_PS_PRIM_SET_ACL_SERVICE_CNF,       /**< \brief Confirms the request to enable or disable APN control list (ACL) service
    									 * \details */
    CI_PS_PRIM_GET_ACL_SIZE_REQ,          /**< \brief Requests the size of the ACL list
    									 * \details */
    CI_PS_PRIM_GET_ACL_SIZE_CNF,          /**< \brief Confirms the request and returns the size of the ACL list
    									 * \details */
    CI_PS_PRIM_READ_ACL_ENTRY_REQ,		/**< \brief Requests to read an entry from the ACL list
    									 *   \details */
    CI_PS_PRIM_READ_ACL_ENTRY_CNF,		/**< \brief Confirms the request and returns the requested ACL entry
    									 *   \details */
    CI_PS_PRIM_EDIT_ACL_ENTRY_REQ,        /**< \brief Requests to edit an entry in the ACL list
    									 *   \details PIN2 must be verified (using CI_SIM_PRIM_OPERCHV_REQ) before using this request. */
    CI_PS_PRIM_EDIT_ACL_ENTRY_CNF = 90,        /**< \brief Confirms the request to edit an entry in the ACL list */
    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_PS_PRIM_LAST_COMMON_PRIM' */
    /* Michal Bukai & Boris Tsatkin  AT&T Smart Card support - End*/

    /* Michal Bukai 每 PDP authentication - Start*/
    CI_PS_PRIM_AUTHENTICATE_REQ, 	/**< \brief  Requests to add authentication parameters to a defined PDP context.
    							* \details The command must be sent after the PDP context was defined and before the PDP context is activated.
    							*  The authentication parameters will be sent to the GGSN in a protocol configuration information entry, when PDP context is activated.
    							*  In case authentication parameters are already defined for this PDP context the new authentication parameters will replace the existing parameters.
    							*  AuthenticationType  =  NONE, will delete authentication parameters defined for this PDP context.  */
    CI_PS_PRIM_AUTHENTICATE_CNF, /**< \brief Confirms the authentication request. \details   */
    /* Michal Bukai 每 PDP authentication - End*/
    /* Michal Bukai 每 Fast Dormancy - Start*/
    CI_PS_PRIM_FAST_DORMANT_REQ, 	/**< \brief  Requests to release data radio bearers, in order to speed entry to DRX mode.
    							* \details The application should use this request for offline applications such as push mail,
    							* in cases that it knows that data transition is complete and there is no anticipated data transmission in the next minute.
    							* The PS will send "Signalling connection release indication" to the NW requesting to release data radio bearers. */
    CI_PS_PRIM_FAST_DORMANT_CNF, 	/**< \brief Confirms the fast dormancy request.
    							* \details   The following result codes can be received:
    							* CIRC_PS_SUCCESS - Indicates "Signalling connection release indication" was sent to the NW
    							* CIRC_PS_FAILURE Indicates "Signalling connection release indication" was not sent to the NW due to one of the following reasons:
    							* Active RAT is not UMTS
    							* There no active PDP contexts
    							* There is an active CS connection
    							* RRC state is not CELL DCH or CELL FACH
    							* CIRC_PS SRVOPT_NOT_SUPPORTED -Indicates fast dormancy is not supported. */
    /* Michal Bukai 每 Fast Dormancy - End*/

    CI_PS_PRIM_GET_CURRENT_JOB_REQ, /**< \brief Requests current ongoing request for PS service group. */
    CI_PS_PRIM_GET_CURRENT_JOB_CNF, /**< \brief Confirms the current job request. */

    CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ, /**< \brief Requests to set configuration of fast dormancy. */
    CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_CNF, /**< \brief Confirms the configuration of fast dormancy. */

    CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND, /**< \brief Indicates SM cause code for PDP activation reject. */

    CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ = 100, /**< \brief Requests to set activation/deactvation of DSDS PS+Paging. */
    CI_PS_PRIM_SET_PS_PAGING_CONFIG_CNF, /**< \brief Confirms the configuration of DSDS PS+Paging */

    /*Michal Bukai - AutoAttach Configuration - Samsung - START*/
    CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_REQ,            /**< \brief Requests to read the configuration status of auto attach to PS domain on power up \details   */
    CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_CNF,            /**< \brief Confirms the request and returns auto attach configuration status \details   */
    /*Michal Bukai - AutoAttach Configuration - Samsung - END*/
    CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ,							/**< \brief Gets a PDP context definition. \details */
    CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_CNF,							/**< \brief Gets a PDP context definition. \details */
    CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ,				/**< \brief Gets all defined PDP contexts current activation state. \details   */
    CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_CNF,				/**< \brief Reports the current activation state of all defined PDP contexts. \details	 */
    CI_PS_PRIM_ENABLE_4G_NW_REG_IND_REQ,                  /**< \brief Enables/disables EPS network registration status reports. \details   */
    CI_PS_PRIM_ENABLE_4G_NW_REG_IND_CNF,                  /**< \brief Confirms request to enable/disable EPS network registration status reports. \details    */
    CI_PS_PRIM_4G_NW_REG_IND = 110,                                 
    CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ, 					/**< \brief Requests the EPS network registration status. \details   */
    CI_PS_PRIM_GET_4G_NW_REG_STATUS_CNF, 					/**< \brief Reports the EPS network registration status. \details	 */
    CI_PS_PRIM_GET_4G_QOS_REQ,
    CI_PS_PRIM_GET_4G_QOS_CNF,
    CI_PS_PRIM_SET_4G_QOS_REQ,
    CI_PS_PRIM_SET_4G_QOS_CNF,
    CI_PS_PRIM_DEL_4G_QOS_REQ,
    CI_PS_PRIM_DEL_4G_QOS_CNF,
    CI_PS_PRIM_GET_4G_QOS_CAPS_REQ,
    CI_PS_PRIM_GET_4G_QOS_CAPS_CNF = 120,

    CI_PS_PRIM_GET_4G_MODE_REQ,
    CI_PS_PRIM_GET_4G_MODE_CNF,
    CI_PS_PRIM_SET_4G_MODE_REQ,
    CI_PS_PRIM_SET_4G_MODE_CNF,
    CI_PS_PRIM_GET_4G_MODE_CAPS_REQ,
    CI_PS_PRIM_GET_4G_MODE_CAPS_CNF,
    CI_PS_PRIM_GET_PDP_ADDR_REQ,
    CI_PS_PRIM_GET_PDP_ADDR_CNF,
    CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ,
    CI_PS_PRIM_GET_PDP_ADDR_LIST_CNF = 130,   
    CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ,						/**< \brief Requests a Secondary PDP Context Read Dynamic Parameters .
    													 * \details Returns an error if the Secondary PDP Context does not exist. */
    CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_CNF,						/**< \brief Reports a Secondary PDP Context Dynamic Parameters . Indicates an error if the Secondary PDP Context does not exist. \details   */
    CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ,
    CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_CNF,
    CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ,
    CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CNF,
    CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ,
    CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_CNF,
    CI_PS_PRIM_GET_4G_EVET_REP_REQ,
    CI_PS_PRIM_GET_4G_EVET_REP_CNF = 140,
    CI_PS_PRIM_SET_4G_EVET_REP_REQ,
    CI_PS_PRIM_SET_4G_EVET_REP_CNF,
    CI_PS_PRIM_GET_4G_EVET_REP_CAPS_REQ,
    CI_PS_PRIM_GET_4G_EVET_REP_CAPS_CNF,


    CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ,
    CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CNF,
    CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_REQ,
    CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_CNF,
    CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ,
    CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_CNF = 150,

    CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ,   //Traffic Flow Template Read Dynamic Parameters +CGTFTRDP
    CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CNF,   //Traffic Flow Template Read Dynamic Parameters +CGTFTRDP
    CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ,   //Traffic Flow Template Read Dynamic Parameters +CGTFTRDP
    CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_CNF,   //Traffic Flow Template Read Dynamic Parameters +CGTFTRDP

    CI_PS_PRIM_DATACOMP_REPORTING_REQ,			/**< \brief Sets data compression reporting to on or off. Also used to read current setting of data
    												        compression reporting. Data compression
    												        reporting is used when AT+DR AT command is
    												        executed. If enabled, than sending of
    												        CI_PS_PRIM_DATACOMP_IND is enabled */
    CI_PS_PRIM_DATACOMP_REPORTING_CNF,			/**< \brief Confirmation to the sets data compression
    														reporting request. Returns the current setting
    														of the data compression reporting. */
    CI_PS_PRIM_DATACOMP_IND,					/**< \brief Indicates the status of the data compression. */

    CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_REQ,	/**< \brief Set command informs the MT whether the UE is currently available for voice calls with the IMS (see 3GPP TS 24.229)
    												* \details   The information can be used by the MT to determine "IMS voice not available" as defined in 3GPP TS 24.301, 
    												*	and for mobility management for IMS voice termination, see 3GPP TS 24.008 */
    CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_CNF, /**< \brief Confirmation to the setting of whether the UE is currently available for voice calls with the IMS */
    CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_REQ = 160, /**< \brief Gets the stored setting of the IMS voice call availability */
    CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_CNF,	/**< \brief Confirmation to the request to get the stored setting of the IMS voice call availability */
    CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_REQ,		/**< \brief Set command informs the MT whether the UE is currently available for SMS using IMS (see 3GPP TS 24.229)
    												* \details   The information can be used by the MT to determine the need to remain attached for non-EPS services, 
    												*	as defined in 3GPP TS 24.301 */
    CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_CNF,		/**< \brief Confirmation to the setting of whether the UE is currently available for SMS with the IMS */
    CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_REQ,		/**< \brief Gets the stored setting of the IMS SMS availability */
    CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_CNF,		/**< \brief Confirmation to the request to get the stored setting of the IMS SMS availability */
    CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_REQ,	/**< \brief Sets the Mobility Management for IMS Voice Termination to support terminating access domain selection by the network */
    CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_CNF,	/**< \brief Confirmation to the request to set the MM for IMS Voice Termination */
    CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_REQ,	/**< \brief Gets the setting of the Mobility Management for IMS Voice Termination */
    CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_CNF,	/**< \brief Confirmation to the request to get the stored setting of the MM for IMS Voice Termination */

    CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ = 170,     /** AT*CGDFLT, set the default PDP info */
    CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF, 
    CI_PS_PRIM_GET_DEFAULT_PDP_CTX_REQ,              /** AT*CGDFLT?, get the default PDP info */
    CI_PS_PRIM_GET_DEFAULT_PDP_CTX_CNF, 

    CI_PS_PRIM_SET_APN_REQ,                          /** AT+VZWAPNE=, used to set APN info */
    CI_PS_PRIM_SET_APN_CNF,
    CI_PS_PRIM_GET_APN_REQ,                          /** AT+VZWAPNE?, used to get APN info */
    CI_PS_PRIM_GET_APN_CNF,

    CI_PS_PRIM_SET_IMS_REG_STATE_REQ,                /** used to notify CP the IMS register state, as IMS on AP side now, when IMS register state changes, should notify CP */
    CI_PS_PRIM_SET_IMS_REG_STATE_CNF,
    CI_PS_PRIM_UE_EVENT_TO_IMS_IND = 180,            /** used by CP to notify the IMS module some UE event, such as: UICC removed, APN changed, etc */

    CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ,             /** AT+CIREG=[<n>], set whether need to report IMS register state. As IMS on AP side now, this CI do not need to be processed in CP side by now*/
    CI_PS_PRIM_SET_IMS_REG_INFO_IND_CNF,
    CI_PS_PRIM_IMS_REG_INFO_IND,                     /** +CIREGU: <reg_info>[,<ext_info>]. IMS module report the IMS state*/
    CI_PS_PRIM_GET_IMS_REG_INFO_REQ,                 /** AT+CIREG?, read command*/
    CI_PS_PRIM_GET_IMS_REG_INFO_CNF,

    CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_REQ,     /** AT*CGDFAUTH=<mode>,<type>[,<UserName>[,<Password>]]*/
    CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_CNF,
    CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_REQ,
    CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_CNF,     /** AT*CGDFAUTH=<mode>  */

    CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ = 190, /** AT+CVDP=[<setting>]/AT+CEVDP=[<setting>], UE's Voice Domain Preference  */
    CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_CNF,
    CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ,       /** AT+CVDP? AT+CEVDP? UE's Voice Domain Preference UTRAN  */
    CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_CNF,

    CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ,   /** AT+CEUS=[<setting>], UE's usage setting for EPS*/
    CI_PS_PRIM_SET_EPS_USAGE_SETTING_CNF,
    CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ,   /** AT+CEUS?, UE's usage setting for EPS*/
    CI_PS_PRIM_GET_EPS_USAGE_SETTING_CNF,

    CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_REQ,
    CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_CNF,
    
    CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_REQ = 200,
    CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_CNF,
    CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_REQ,
    CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_CNF,

    CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ,
    CI_PS_PRIM_SET_IMS_SERVICE_STATUS_CNF,

    CI_PS_PRIM_SUSPEND_RESUME_IND,

    CI_PS_PRIM_CHAP_AUTHENTICATE_REQ,       /** AT*CHAPAUTH=cid[,<challenge>[,<response>]], for PPP CHAP authentication */
    CI_PS_PRIM_CHAP_AUTHENTICATE_CNF,

    CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_REQ,       /** used to activate reconfigured PDP (an already activated PDP is re-defined) */
    CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF = 210,

/* ==============  Added for REL13 ====================================================*/
	CI_PS_PRIM_SET_PSM_CONFIG_REQ,
	CI_PS_PRIM_SET_PSM_CONFIG_CNF,
	CI_PS_PRIM_GET_PSM_CONFIG_REQ,
	CI_PS_PRIM_GET_PSM_CONFIG_CNF,
	
	CI_PS_PRIM_SET_EDRX_CONFIG_REQ,
	CI_PS_PRIM_SET_EDRX_CONFIG_CNF,
	CI_PS_PRIM_GET_EDRX_CONFIG_REQ,
	CI_PS_PRIM_GET_EDRX_CONFIG_CNF,
	CI_PS_PRIM_EDRX_INFO_IND,
	CI_PS_PRIM_READ_EDRX_DYN_PARA_REQ = 220,
	CI_PS_PRIM_READ_EDRX_DYN_PARA_CNF,

	CI_PS_PRIM_SET_CIOT_CONFIG_REQ,
	CI_PS_PRIM_SET_CIOT_CONFIG_CNF,
	CI_PS_PRIM_GET_CIOT_CONFIG_REQ,
	CI_PS_PRIM_GET_CIOT_CONFIG_CNF,
	CI_PS_PRIM_CIOT_NW_INFO_IND,

	CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_REQ,
	CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_CNF,
	CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_REQ,
	CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_CNF = 230,
	CI_PS_PRIM_SIGNALLING_CONNECTION_IND,

	CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_REQ,
	CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_CNF,
	CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_REQ,
	CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_CNF,
	
	CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_REQ,
	CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_CNF,
	CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_REQ,
	CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_CNF,
	CI_PS_PRIM_APN_BACKOFF_TIMER_STATUS_REPORT_IND = 240,
	CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_REQ,
	CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_CNF,

	CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ,
	CI_PS_PRIM_GET_APN_RATE_CONTROL_CNF,

	CI_PS_PRIM_GET_PDP_CONTEXT_INFO_REQ,
	CI_PS_PRIM_GET_PDP_CONTEXT_INFO_CNF,

    CI_PS_PRIM_SET_PDP_CTX_REMAP_REQ,
    CI_PS_PRIM_SET_PDP_CTX_REMAP_CNF,


    /* END OF COMMON PRIMITIVES LIST */
    CI_PS_PRIM_LAST_COMMON_PRIM

    /* the customer specific extension primitives are added starting from
    * CI_PS_PRIM_firstCustPrim = CI_PS_PRIM_LAST_COMMON_PRIM as the first identifier.
    * The actual primitive names and IDs are defined in the associated
    * 'ci_ps_cust_xxx.h' file.
    */

    /* DO NOT ADD ANY MORE PRIMITIVES HERE */

}_CiPsPrim;

/* specify the number of default common DAT primitives */
#define CI_PS_NUM_COMMON_PRIM ( CI_PS_PRIM_LAST_COMMON_PRIM - 1 )

/* Maximum number of PDP contexts supported.
 * Implementation specific. Should be 1 if only a single subscribed context is supported, otherwise should be
 * greater than possible NSAPIs, NSAPI only support [5-15] according to [6], 10.5.6.2
 */
//#define CI_PS_MAX_PDP_CTX_NUM CI_CFG_PS_MAX_PDP_CTX_NUM

/* NOTE: THE MAXIMUM NUMBER OF PDP CONTEXTS WAS TEMPORARILY REDUCED TO 8 IN ORDER TO */
/* MAKE THE PRIMITIVE CI_PS_PRIM_GET_3G_QOS_CAPS_CNF SMALLER BECAUSE OF THE SIZE     */
/* LIMIT IN MSL BUFFER (MSL_MTU_SIZE = 1024 BYTES ON COMM SUBSYSTEM). THIS MUST BE   */
/* RESTORED ONCE PRIMITIVE SEGMENTATION IS IMPLEMENTED IN CI STUBS                   */
//Fitz.xu 20211215: For 1601/3601, max cid is 8
//#if defined(DS3_CAT1) || defined(DS3_DATA_ONLY)
#define CI_PS_MAX_PDP_CTX_NUM 8 /* modify max PDP context to 8 for CAT1 DS3.0 */
#define CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM    ( CI_PS_MAX_PDP_CTX_NUM /*+ 7*/ )
/*#else
#define CI_PS_MAX_PDP_CTX_NUM 8
#define CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM    ( CI_PS_MAX_PDP_CTX_NUM + 7 )
#endif*/
/**@}*/

/** \brief CI return codes for the PS service group. Refer to TS 24.008 v3.11.0. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_PS
{
    CIRC_PS_SUCCESS = 0,                /**< Request completed successfully */
    CIRC_PS_FAILURE,                    /**< Request failed */

    /* failure to perform an Attach */
    CIRC_PS_ILLEGAL_MS = 0x03,                    /**< Illegal MS */
    CIRC_PS_ILLEGAL_ME = 0x06,            	    /**< Illegal ME */
    CIRC_PS_GPRS_SERVICES_NOT_ALLOWED = 0x07,     /**< GPRS service not allowed */
    CIRC_PS_OPER_DETERMINED_BARRING = 0x08,       /**< Operator Determined Barring */
    CIRC_PS_DETACH = 10, //0x0A                   /**< implicitly detached */
    CIRC_PS_PLMN_NOT_ALLOWED = 0x0B,              /**< PLMN not allowed */
    CIRC_PS_LA_NOT_ALLOWED = 0x0C,                /**< Location area not allowed */
    CIRC_PS_ROAMING_NOT_ALLOWED = 0x0D,           /**< Roaming not allowed in this location area */
    CIRC_PS_MSC_NOT_REACH = 16,   //0x10          /**< MSC temporarily not reachable */
    CIRC_PS_NW_CONGESTION = 22,   //0x16          /**< Congestion */
    CIRC_PS_RESOURCE_INSUFF = 26, //0x1A          /**< Insufficient resources */
    CIRC_PS_APN = 27,             //0x1B          /**< Missing or unknown APN */
    CIRC_PS_UNKNOWN_PDP_ADD_TYPE = 28, //0x1C     /**< unknown PDP address or PDP type */
    CIRC_PS_USER_AUTH_FAIL = 29,       //0x1D     /**< user authentication failed */
    CIRC_PS_ACT_REJECT_GGSN = 30,      //0x1E     /**< Activation rejected by GGSN */
    CIRC_PS_ACT_REJECT = 31,           //0x1F     /**< Activation rejected, unspecified */
    /* failure to Activate a context */
    CIRC_PS_SRVOPT_NOT_SUPPORTED = 32, //0x20     /**< Service option not supported */
    CIRC_PS_SRVOPT_NOT_SUBSCRIBED = 33,//0x21     /**< Requested service option not subscribed */
    CIRC_PS_SRVOPT_TEMP_OUT_OF_ORDER = 34,//0x22  /**< Service option temporarily out of order */
    CIRC_PS_NSAPI_ALREADY_USED = 35,   //0x23	    /**< NSAPI already used */
    CIRC_PS_QOS = 37,                  //0x25     /**< QoS not accepted */
    CIRC_PS_NETWORK_FAILURE = 38,      //0x26     /**< Network failure */
    CIRC_PS_REACTIVATION_REQ = 39,     //0x27     /**< Reactivation required */
    //Z.S. MT PDP support
    /* TFT errors for MT PDP start*/
    /* From spec (24.301/9.9.4.4) */ 
    CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION = 41,   //0x29   /* SM_CAUSE_SEMANTIC_ERROR_IN_TFT_OPERATION */
    CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION = 42,//0x2A   /* SM_CAUSE_SYNTACTICAL_ERROR_IN_TFT_OPERATION */
    CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY = 43, //0x2B             /* SM_CAUSE_UNKNOWN_PDP_CONTEXT */
    CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER = 44, //0x2C        /* SM_CAUSE_SEMANTIC_ERRORS_IN_PACKET_FILTER */
    CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER = 45,//0x2D      /* SM_CAUSE_SYNTACTICAL_ERRORS_IN_PACKET_FILTER */
    CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 46, //0x2E /* SM_CAUSE_PDP_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED */
    CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED = 49, //0x31
    CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED = 50, //0x32
    CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED = 51, //0x33
    CIRC_PS_ESM_PDN_TYPE_SINGLE_IP_ALLOWED = 52, //0x34
    CIRC_PS_PROTOCOL_ERROR_MIN = 95, //0x5F         /**< protocol errors - low range, old value, useless now */
    CIRC_PS_PROTOCOL_ERROR_MAX = 111,//0x6F         /**< protocol errors - high range, old value, useless now */
    /* TFT errors for MT PDP end*/
    CIRC_PS_UNSPECIFIED_ERROR = 148, //0x94         /**< Unspecified GPRS error */
    CIRC_PS_PDP_AUTHEN_FAILURE =149, //0x95  	    /**< PDP authentication failure */

    /* other GPRS errors */
    CIRC_PS_INVALID_MS_CLASS = 150, //0x96          /**< Invalid mobile class */

    /* Additional return codes, not specified in TS 27.007 - start from 200 */
    CIRC_PS_INFO_UNAVAILABLE = 200, //0xC8          /**< Requested information is unavailable */

    CIRC_PS_ALREADY_PROCESSING = 201,	//0xC9      /**< The requested command is already being processed, I.e., this REQ is redundant */
    CIRC_PS_BUSY_WITH_OTHER_JOB = 202, //0xCA       /**< The CP is busy processing another command so this one can't be serviced, and CP will not add the REQ into its queue */

    CIRC_PS_INVALID_PARAMETER = 203, //0xCB	        /**< Generic error - the requested service primitive has invalid parameters */
    CIRC_PS_INVALID_REQ = 204,       //0xCC         /**< Generic error - the requested service primitive can not be handled at current state */
    CIRC_PS_SIM_NOT_READY = 205,     //0xCD         /**< Generic error - the requested service primitive fails because SIM is not ready */
    CIRC_PS_ACCESS_DENIED = 206,     //0xCE         /**< Generic error - the requested service primitive fails because access is denied */
    CIRC_PS_INVALID_CID = 207,       //0xCF	        /**< Generic error - the requested Cid is invalid	*/
    CIRC_PS_TFT_PACKET_ERROR_DEFAULT_PDP = 208,	//0xD0	/**< Generic error - the TFT is invalid for default MT PDP	*/
    CIRC_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP = 209, //0xD1 /**< Generic error - the TFT is invalid for NON default MT PDP	*/
    CIRC_PS_PENDING_SUCCESS = 210, //0xD2           /**<LTE MO PDP equest completed successfully */
    CIRC_PS_RPM_REJECT = 880,	//0x370	            /**< Generic error - the RPM manager rejected the request.	*/

    /**** SM reject cause (24.008) also contained in CiPsRc vaule, one to one mapped with sml3_typ.h ****/
    CIRC_PS_SM_LLC_OR_SNDCP_FAILURE = 0x19,
    CIRC_PS_SM_INSUFFIC_RESOURCES = 0x1A,
    CIRC_PS_SM_MISSING_OR_UNKNOWN_APN = 0x1B,
    CIRC_PS_SM_UNKNOWN_PDP_ADDR_OR_TYPE = 0x1C,
    CIRC_PS_SM_USER_AUTH_FAILED = 0x1D,
    CIRC_PS_SM_ACTIV_REJ_BY_GGSN = 0x1E,
    CIRC_PS_SM_ACTIV_REJ_UNSPECIFIED = 0x1F,
    CIRC_PS_SM_SERVICE_OPT_NOT_SUPPORTED = 0x20,
    CIRC_PS_SM_SERVICE_OPT_NOT_SUBSCRIBED = 0x21,
    CIRC_PS_SM_SERVICE_OPT_TEMP_OUT_OF_ORDER = 0x22,
    CIRC_PS_SM_NSAPI_ALREADY_USED = 0x23,
    CIRC_PS_SM_REGULAR_DEACTIVATION = 0x24,
    CIRC_PS_SM_QOS_NOT_ACCEPTED = 0x25,
    CIRC_PS_SM_NETWORK_FAILURE = 0x26,
    CIRC_PS_SM_REACTIVATION_REQUIRED = 0x27,
    CIRC_PS_SM_FEATURE_NOT_SUPPORTED = 0x28,    /* Added for 0111-13748 */
    CIRC_PS_SM_SEMANTIC_ERROR_IN_TFT_OPERATION = 0x29,
    CIRC_PS_SM_SYNTACTICAL_ERROR_IN_TFT_OPERATION = 0x2A,
    CIRC_PS_SM_UNKNOWN_PDP_CONTEXT = 0x2B,
    CIRC_PS_SM_SEMANTIC_ERRORS_IN_PACKET_FILTER = 0x2C,
    CIRC_PS_SM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER = 0x2D,
    CIRC_PS_SM_PDP_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 0x2E,
    CIRC_PS_SM_PDP_TYPE_IPV4_ONLY_ALLOWED = 0x32,
    CIRC_PS_SM_PDP_TYPE_IPV6_ONLY_ALLOWED = 0x33,
    CIRC_PS_SM_SINGLE_ADDRESS_BEARERS_ONLY_ALLOWED = 0x34,
    CIRC_PS_SM_INVALID_TI_VALUE = 0x51,
    CIRC_PS_SM_SEMANTICALLY_INCORRECT_MSG = 0x5F,
    CIRC_PS_SM_INVALID_MAND_INFORMATION = 0x60,
    CIRC_PS_SM_MSG_TYPE_NONEXIST_OR_NOT_IMP = 0x61,
    CIRC_PS_SM_MSG_TYPE_INCOMPAT_WITH_STATE = 0x62,
    CIRC_PS_SM_IE_NONEXIST_OR_NOT_IMP = 0x63,
    CIRC_PS_SM_CONDITIONAL_IE_ERROR = 0x64,
    CIRC_PS_SM_MSG_INCOMPAT_WITH_STATE = 0x65,
    CIRC_PS_SM_PROTOCOL_ERROR_UNSPEC = 0x6F,
    /* Added for rel6: APN restriction value incompatible with active PDP context */
    CIRC_PS_SM_APN_RESTRICTION = 0x70, // last SM cause 

    /**** ESM reject cause also contained in CiPsRc vaule, one to one mapped with sml3_typ.h ****/
    // ESM cause, 24.301 - 9.9.4.4
    CIRC_PS_ESM_OPERATOR_DETERMINED_BARRING          = 0x08,
    CIRC_PS_ESM_INSUFFICIENT_RESOURCES               = 0x1a,
    CIRC_PS_ESM_UNKNOWN_OR_MISSING_APN               = 0x1b,
    CIRC_PS_ESM_UNKNOWN_PDN_TYPE                     = 0x1c,
    CIRC_PS_ESM_USER_AUTHENTICATION_FAILED           = 0x1d,
    CIRC_PS_ESM_REQUEST_REJECTED_BY_SERVING_GW_OR_PDN_GW = 0x1e,
    CIRC_PS_ESM_REQUEST_REJECTED_UNSPECIFIED         = 0x1f,
    CIRC_PS_ESM_SERVICE_OPTION_NOT_SUPPORTED         = 0x20,
    CIRC_PS_ESM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED = 0x21,
    CIRC_PS_ESM_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER = 0x22,
    CIRC_PS_ESM_PTI_ALREADY_IN_USE                      = 0x23,
    CIRC_PS_ESM_REGULAR_DEACTIVATION                    = 0x24,
    CIRC_PS_ESM_EPS_QOS_NOT_ACCEPTED                    = 0x25,
    CIRC_PS_ESM_NETWORK_FAILURE                         = 0x26,
    //CIRC_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION     = 0x29,
    //CIRC_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION  = 0x2a,
    //CIRC_PS_ESM_INVALID_EPS_BEARER_IDENTITY             = 0x2b,
    //CIRC_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER        = 0x2c,
    //CIRC_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER     = 0x2d,
    //CIRC_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED = 0x2e,
    CIRC_PS_ESM_PTI_MISMATCH                            = 0x2f,
    //CIRC_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED      = 0x31,
    //CIRC_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED              = 0x32,
    //CIRC_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED              = 0x33,
    CIRC_PS_ESM_SINGLE_ADDRESS_BEARERS_ONLY_ALLOWED     = 0x34,
    CIRC_PS_ESM_ESM_INFORMATION_NOT_RECEIVED            = 0x35,
    CIRC_PS_ESM_PDN_CONNECTION_DOES_NOT_EXIST           = 0x36,
    CIRC_PS_ESM_MULTIPLE_PDN_CONNECTIONS_FOR_A_GIVEN_APN_NOT_ALLOWED = 0x37,
    CIRC_PS_ESM_COLLISION_WITH_NETWORK_INITIATED_REQUEST= 0x38,
    CIRC_PS_ESM_UNSUPPORTED_QCI_VALUE                   = 0x3b,
    CIRC_PS_ESM_INVALID_PTI_VALUE                       = 0x51,
    CIRC_PS_ESM_SEMANTICALLY_INCORRECT_MESSAGE          = 0x5f,
    CIRC_PS_ESM_INVALID_MANDATORY_INFORMATION           = 0x60,
    CIRC_PS_ESM_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED = 0x61,
    CIRC_PS_ESM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE = 0x62,
    CIRC_PS_ESM_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED  = 0x63,
    CIRC_PS_ESM_CONDITIONAL_IE_ERROR                                = 0x64,
    CIRC_PS_ESM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE      = 0x65,
    CIRC_PS_ESM_PROTOCOL_ERROR_OR_UNSPECIFIED                       = 0x6f,
    CIRC_PS_ESM_APN_RESTRICTION_VALUE_INCOMPATIBLE_WITH_ACTIVE_EPS_BEARER_CONTEXT = 0x70,

    /****internal reject cause also contained in CiPsRc vaule, one to one mapped with sml3_typ.h ****/
    // internal reject start from 0x0100, and the cause before 0x0100 is reserved for 3GPP;
    /** !!!!!! Local cause !!!!!!!!!!*/
    CIRC_PS_INTERNAL_LOCAL_CAUSE_BASE                  = 0x0100,
    CIRC_PS_ENMERGNECY_BEARER_SERVICE_ALREADY_RUN      = 0x0101, // for emergency bearer only
    CIRC_PS_HANDOVER_FLAG                              = 0x0102, // IRAT
    CIRC_PS_CAUSE_EPS_SERVICE_NOT_AVAILABLE            = 0x0103, // EPS PS service not available,

    CIRC_PS_NOTIFY_REATTACH                            = 0x0104,
    CIRC_PS_NOTIFY_DETACH                              = 0x0105,
    CIRC_PS_PDN_REQUEST_NEED_RETRY                     = 0x0106,
    CIRC_PS_APN_IS_NOT_AVAILABLE                       = 0x0107, // APN is missing
    CIRC_PS_EMERGENCY_PDN_REQUEST_CONTAINS_APN         = 0x0108, // emergency bearer should not contain APN
    CIRC_PS_ATTACH_FOR_EMERGENCY_BEARER_SERVICE        = 0x0109, // emergency attached, but require additional bearer
    //ESM_CAUSE_IMS_BLOCK = 0x89,

    CIRC_PS_PDP_OPERATTION_NOT_ALLOWED                 = 0x010B, // PDP operation not allowed for some reason
    CIRC_PS_PDP_INPUT_PARAM_INVALID                    = 0x010C,
    CIRC_PS_T3396_RUNNING                              = 0x010D,
    CIRC_PS_TIMER_OUT_ERROR                            = 0x010E,

    //Cause for PDP activation request reject in AB side;
    CIRC_PS_NO_FREE_NSAPIS             = 0x0150,
    CIRC_PS_GPRS_SERVICE_NOT_AVAILABLE = 0x0151,
    CIRC_PS_POWERING_DOWN              = 0x0152,
    CIRC_PS_FDN_FAILURE                = 0x0153,
    CIRC_PS_APN_CHECK_FAILURE          = 0x0154,
    
    
    CIRC_PS_OPERATION_REJECT_BY_MM  = 0x0200, // reject by GMM/EMM
    CIRC_PS_PDP_REJECT_DSDS         = 0x3300, /**< PDP reject on DSDS */


    CIRC_PS_NO_CAUSE_SET            = 0x3400,

    /*!!!! internal cause add here !!!!*/
    CIRC_PS_CAUSE_UNKNOWN           = 0xFFFF,
    /* This one must always be last in the list! */
    CIRC_PS_NUM_RESCODES            = 0xFFFF    /**< Number of result codes */
} _CiPsRc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief CI return codes for the PS service group. Refer to TS 24.008 v3.11.0.
 *  \sa CIRC_PS
 * \remarks Common Data Section */
typedef UINT16 CiPsRc;
/**@}*/


//need to see uf the 3 last values are relevant.
/** \brief PDP types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSPDPTYPE_TAG
{
  CI_PS_PDP_TYPE_PPP = 0, 		/**< PPP */
  CI_PS_PDP_TYPE_IP,      		/**< IPv4 */
  CI_PS_PDP_TYPE_IPV6,    		/**< IPv6 */
  CI_PS_PDP_TYPE_IPV4V6,   		/**< IPv4v6 */
  CI_PS_PDP_TYPE_X25,   		/**< X25 */
  CI_PS_PDP_TYPE_OSPIH,   		/**< OSPIH */
  CI_PS_PDP_TYPE_NONIP,         /**< Non-IP */
  
  CI_PS_PDP_NUM_TYPES
} _CiPsPdpType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief PDP types
 *  \sa CIPSPDPTYPE_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsPdpType;
/**@}*/

/** \brief Action types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSACTIONTYPE_TAG
{//Z.S. MT PS support
	CI_PS_ACT_IND_ACTION = 0, /**< Indicates network initiated primary PDP context activation */
	CI_PS_ACT_SEC_IND_ACTION, 	/**< Indicates network initiated secondary PDP context activation */
	CI_PS_MODIFY_IND_ACTION, 	/**< Indicates network initiated primary PDP context modification */
	CI_PS_MODIFY_SEC_IND_ACTION,  /**< Indicates network initiated secondary PDP context modification */
	//CI_PS_TFT_PACKET_ERROR_NON_DEFAULT_PDP,  /**< Indicates  COMM to update the pdp tft packets */
	//CI_PS_TFT_PACKET_ERROR_DEFAULT_PDP,  /**< Indicates COMM  to release MT default pdp */
	CI_PS_NUMBER_OF_ACTION_TYPES
	//CIRC_PS_ACT_IND_ACTION = 0, /**< Indicates network initiated PDD context activation */
	//CIRC_PS_MODIFY_IND_ACTION,  /**< Indicates network initiated PDD context modification */
	//CIRC_PS_NUMBER_OF_ACTION_TYPES
}_CiPsActionType;

#define CI_PS_PDP_MODIFY_TFT_BIT 0x01
#define CI_PS_PDP_MODIFY_QOS_BIT 0x02

//ICAT EXPORTED ENUM
typedef enum CIPSPDPMODIFYCHANGEREASON_TAG
{
  CI_PS_PDP_MODIFY_RESERVED = 0,
  CI_PS_PDP_MODIFY_TFT = CI_PS_PDP_MODIFY_TFT_BIT,
  CI_PS_PDP_MODIFY_QOS = CI_PS_PDP_MODIFY_QOS_BIT,
  CI_PS_PDP_MODIFY_QOS_AND_TFT = CI_PS_PDP_MODIFY_TFT_BIT + CI_PS_PDP_MODIFY_QOS_BIT,

  CI_PS_PDP_MODIFY_INVALID_REASONS
} _CiPsPdpModifyChangeReason; //A bitmap that indicates what kind of change occurred (27.007 e50)

typedef UINT8 CiPsPdpModifyChangeReason;

typedef enum SacPsEventReportModeTag
{
  ST_PS_EVENT_REPORT_MODE_0,
  ST_PS_EVENT_REPORT_MODE_1,
  ST_PS_EVENT_REPORT_MODE_2
} _SacPsEventReportMode;
typedef UINT8 SacPsEventReportMode;


typedef enum SacPsEventReportBufferModeTag
{
  ST_PS_EVENT_REPORT_BUFFER_MODE_0,
  ST_PS_EVENT_REPORT_BUFFER_MODE_1
} _SacPsEventReportBufferMode;
typedef UINT8 SacPsEventReportBufferMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Action types
 *  \sa CIPSACTIONTYPE_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsActionType;

#define CI_PS_APN_MIN_SIZE 1
#define CI_PS_APN_MAX_SIZE 100
#define CI_PS_PDP_IP_V4_SIZE 16
#if 1
#define CI_PS_PDP_IP_V6_SIZE 64+1//SAMSUNG_PREVENT_FIX(+1 is added for terminating string)
#else
#define CI_PS_PDP_IP_V6_SIZE 64
#endif

#define CI_PS_PDP_IP_V4V6_SIZE 64
/**@}*/

/** \brief PDP address string */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpAddr_struct
{
   UINT8   len; 									/**< Length of the address field [CI_PS_PDP_IP_V4_SIZE| CI_PS_PDP_IP_V6_SIZE] */
   UINT8   valData[CI_PS_PDP_IP_V6_SIZE];		/**< Address field */
} CiPsPdpAddr; /* PDP address */


/** \brief PDP data compression values, only applicable to SNDCP */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSDCOMP_TAG
{
  CI_PS_DCOMP_OFF = 0,  			/**< Off; this is the default value */
  CI_PS_DCOMP_ON,       			/**< Manufacturer preferred compression */
  CI_PS_DCOMP_V42bis,   			/**< V.42 bis */
  CI_PS_DCOMP_V44,   				/**< V.44 */

  CI_PS_NUM_DCOMPS
} _CiPsDcomp;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief PDP data compression, only applicable to SNDCP
 *  \sa CIPSDCOMP_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsDcomp;
/**@}*/

/** \brief PDP header compression values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSHCOMP_TAG
{
  CI_PS_HCOMP_OFF=0,  /**< Off; this is the default value */
  CI_PS_HCOMP_TCPIP,  /**< TCPIP header compression - RFC 1144 */
  CI_PS_HCOMP_IP,     /**< IP header compression - RFC 2507 */

  CI_PS_NUM_HCOMPS
} _CiPsHcomp;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief PDP header compression
 *  \sa CIPSHCOMP_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsHcomp;
/**@}*/

typedef enum CIPSIPV4ALLOCTYPE_TAG
{
  CI_PS_IPV4_ALLOC_THROUGH_NAS_SIGNALING=0,
  CI_PS_IPV4_ALLOC_THROUGH_DHCP,
  
  CI_PS_NUM_IPV4_ALLOC
}_CiPsIpv4AllocType;

typedef UINT8 CiPsIpv4AllocType;

typedef enum CIPSEMERGENCYINDTYPE_TAG
{
  CI_PS_NOT_FOR_EMERGENCY_BEARER_SERVICES=0, /*0   PDP context is not for emergency bearer services*/
  CI_PS_FOR_EMERGENCY_BEARER_SERVICES,       /*1   PDP context is for emergency bearer services*/
  
  CI_PS_NUM_EMERGENCY_IND
}_CiPsEmergencyIndType;

typedef UINT8 CiPsEmergencyIndType;

typedef enum CIPSPCSCFDISCOVERYTYPE_TAG
{
  CI_PS_P_CSCF_ADDR_DISCOVERY_NOT_INFLUENCED_BY_CGDCONT=0,
  CI_PS_P_CSCF_ADDR_DISCOVERY_THROUGH_NAS_SIGNALLING,
  CI_PS_P_CSCF_ADDR_DISCOVERY_THROUGH_NAS_DHCP,
  
  CI_PS_NUM_P_CSCF_ADDR_DISCOVERY
}_CiPsPcscfDiscoveryType;

typedef UINT8 CiPsPcscfDiscoveryType;

typedef enum CIPSIMCNSIGNALLINGFLAGINDTYPE_TAG
{
  CI_PS_NOT_FOR_IM_CN_SIGNALLING_FLAG_IND=0,  /**  0   UE indicates that the PDP context is not for IM CN subsystem-related signalling only*/
  CI_PS_FOR_IM_CN_SIGNALLING_FLAG_IND,  /**  1   UE indicates that the PDP context is for IM CN subsystem-related signalling only*/
  
  CI_PS_NUM_IM_CN_SIGNALLING_FLAG_IND
}_CiPsImCnSignallingFlagIndType;

typedef UINT8 CiPsImCnSignallingFlagIndType;


typedef enum CIPSESMCAUSETYPE_TAG
{
    CI_PS_ESM_OPERATOR_DETERMINED_BARRING                                        =  0x08,
    CI_PS_ESM_INSUFFICIENT_RESOURCES                                             =  0x1a,
    CI_PS_ESM_UNKNOWN_OR_MISSING_APN                                             =  0x1b,
    CI_PS_ESM_UNKNOWN_PDN_TYPE                                                   =  0x1c,
    CI_PS_ESM_USER_AUTHENTICATION_FAILED                                         =  0x1d,
    CI_PS_ESM_REQUEST_REJECTED_BY_SERVING_GW_OR_PDN_GW                           =  0x1e,
    CI_PS_ESM_REQUEST_REJECTED_UNSPECIFIED                                       =  0x1f,
    CI_PS_ESM_SERVICE_OPTION_NOT_SUPPORTED                                       =  0x20,
    CI_PS_ESM_REQUESTED_SERVICE_OPTION_NOT_SUBSCRIBED                            =  0x21,
    CI_PS_ESM_SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER                            =  0x22,
    CI_PS_ESM_PTI_ALREADY_IN_USE                                                 =  0x23,
    CI_PS_ESM_REGULAR_DEACTIVATION                                               =  0x24,
    CI_PS_ESM_EPS_QOS_NOT_ACCEPTED                                               =  0x25,
    CI_PS_ESM_NETWORK_FAILURE                                                    =  0x26,
    CI_PS_ESM_REACTIVATION_REQUESTED                                             =  0x27,
    CI_PS_ESM_SEMANTIC_ERROR_IN_THE_TFT_OPERATION                                =  0x29,
    CI_PS_ESM_SYNTACTICAL_ERROR_IN_THE_TFT_OPERATION                             =  0x2a,
    CI_PS_ESM_INVALID_EPS_BEARER_IDENTITY                                        =  0x2b,
    CI_PS_ESM_SEMANTIC_ERRORS_IN_PACKET_FILTER                                   =  0x2c,
    CI_PS_ESM_SYNTACTICAL_ERRORS_IN_PACKET_FILTER                                =  0x2d,
    CI_PS_ESM_EPS_BEARER_CONTEXT_WITHOUT_TFT_ALREADY_ACTIVATED_                  =  0x2e,
    CI_PS_ESM_PTI_MISMATCH                                                       =  0x2f,
    CI_PS_ESM_LAST_PDN_DISCONNECTION_NOT_ALLOWED                                 =  0x31,
    CI_PS_ESM_PDN_TYPE_IPV4_ONLY_ALLOWED                                         =  0x32,
    CI_PS_ESM_PDN_TYPE_IPV6_ONLY_ALLOWED                                         =  0x33,
    CI_PS_ESM_SINGLE_ADDRESS_BEARERS_ONLY_ALLOWED                                =  0x34,
    CI_PS_ESM_ESM_INFORMATION_NOT_RECEIVED                                       =  0x35,
    CI_PS_ESM_PDN_CONNECTION_DOES_NOT_EXIST                                      =  0x36,
    CI_PS_ESM_MULTIPLE_PDN_CONNECTIONS_FOR_A_GIVEN_APN_NOT_ALLOWED               =  0x37,
    CI_PS_ESM_COLLISION_WITH_NETWORK_INITIATED_REQUEST                           =  0x38,
    CI_PS_ESM_UNSUPPORTED_QCI_VALUE                                              =  0x3b,
    CI_PS_ESM_BEARER_HANDLING_NOT_SUPPORTED                                      =  0x3c,
    CI_PS_ESM_MAX_NUM_OF_EPS_BEARERS_REACHED                                     =  0x41,
    CI_PS_ESM_REQUESTED_APN_NOT_SUPPORT_IN_CURRENT_RAT_PLMN_COMBINATION          =  0x42,
    CI_PS_ESM_INVALID_PTI_VALUE                                                  =  0x51,
    CI_PS_ESM_SEMANTICALLY_INCORRECT_MESSAGE                                     =  0x5f,
    CI_PS_ESM_INVALID_MANDATORY_INFORMATION                                      =  0x60,
    CI_PS_ESM_MESSAGE_TYPE_NONEXISTENT_OR_NOT_IMPLEMENTED                        =  0x61,
    CI_PS_ESM_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE                =  0x62,
    CI_PS_ESM_INFORMATION_ELEMENT_NONEXISTENT_OR_NOT_IMPLEMENTED                 =  0x63,
    CI_PS_ESM_CONDITIONAL_IE_ERROR                                               =  0x64,
    CI_PS_ESM_MESSAGE_NOT_COMPATIBLE_WITH_THE_PROTOCOL_STATE                     =  0x65,
    CI_PS_ESM_PROTOCOL_ERROR_OR_UNSPECIFIED                                      =  0x6f,
    CI_PS_ESM_APN_RESTRICTION_VALUE_INCOMPATIBLE_WITH_ACTIVE_EPS_BEARER_CONTEXT  =  0x70,
    //CI_PS_ESM_ENMERGNECY_BEARER_SERVICE_ALREADY_RUN                              =  0x81,
    //CI_PS_ESM_HANDOVER_FLAG                                                      = 0x82,  
    CI_PS_ESM_ATTACH_REJECT_NO_EITF                                              =  0x91
    //CI_PS_ESM_CAUSE_UNKNOWN                                                      =  0X0  
}_CiPsEsmCauseType;

typedef UINT8 CiPsEsmCauseType;

/******************************************************************************
 * ESM/SM following action, need to report to uplayer
 *****************************************************************************/
typedef enum CiPsSmFollowAct_tag
{
    CI_PS_SM_NO_FOLLOW_ACT = 0,
    CI_PS_SM_ETIF_ENABLE_RERRY,
    CI_PS_SM_ETIF_DISABLE_RERRY,
    CI_PS_SM_IPV4V6_CHANGE_IPV4_RERRY,
    CI_PS_SM_IPV4V6_CHANGE_IPV6_RERRY,
    CI_PS_SM_SEC_IPV4_PDP_RETRY,
    CI_PS_SM_SEC_IPV6_PDP_RETRY,
    CI_PS_SM_IPV4_CHANGE_IPV6_RETRY,
    CI_PS_SM_IPV6_CHANGE_IPV4_RETRY,

    CI_PS_SM_FOLLOW_ACT_NUM
}_CiPsSmFollowAct;

typedef UINT8 CiPsSmFollowAct;

typedef enum CiPsIpv4MtuDiscoveryType_Tag
{
  CI_PS_IPV4_MTU_DISCOVERY_NOT_INFLUENCED_BY_CGDCONT = 0,
  CI_PS_IPV4_MTU_DISCOVERY_THROUGH_NAS,
   
  CI_PS_NUM_IPV4_MTU_DISCOVERY
}_CiPsIpv4MtuDiscoveryType;

typedef UINT8 CiPsIpv4MtuDiscoveryType;

typedef enum CiPsLocalAddrIndType_Tag
{
  CI_PS_MS_NOT_SUPPORT_LOCAL_IP_ADDR_IN_TFT = 0,
  CI_PS_MS_SUPPORT_LOCAL_IP_ADDR_IN_TFT,
   
  CI_PS_NUM_LOCAL_ADDR_IND
}_CiPsLocalAddrIndType;

typedef UINT8 CiPsLocalAddrIndType;

typedef enum CiPsNonIpMtuDiscoveryType_Tag
{
  CI_PS_NONIP_MTU_DISCOVERY_NOT_INFLUENCED_BY_CGDCONT = 0,
  CI_PS_NONIP_MTU_DISCOVERY_THROUGH_NAS,
   
  CI_PS_NUM_NONIP_MTU_DISCOVERY
}_CiPsNonIpMtuDiscoveryType;

typedef UINT8 CiPsNonIpMtuDiscoveryType;

/******************************************************************************
 * For PDP context activation, the following unsolicited result codes and the 
 * corresponding events are defined:
 * +CGEV: NW PDN ACT <cid>
 * +CGEV: ME PDN ACT <cid>[,<reason>[,<cid_other>]]
 * +CGEV: NW ACT <p_cid>, <cid>, <event_type>
 * +CGEV: ME ACT <p_cid>, <cid>, <event_type>
 *****************************************************************************/
typedef enum CiPsMoPdpActReason_Tag
{
    CI_PS_PDP_IPV4_ONLY_ALLOWED = 0, // 0 IPv4 only allowed
    CI_PS_PDP_IPV6_ONLY_ALLOWED = 1, // 1 IPv6 only allowed
    CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC = 2, //2   single address bearers only allowed.
    CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_FAILED = 3,

    CI_PS_PDP_INVALID_REASON
}_CiPsMoPdpActReason;

typedef UINT8 CiPsMoPdpActReason;


/** \brief PDP context definition */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsID_struct
{
  UINT8        cid;/**< PDP Context Identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  UINT8        p_cid;
  UINT8        bearer_id;/**< PDP Context Identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsID;


#define CI_PS_PDP_ADDR_MAX_LENGTH 16
//ICAT EXPORTED ENUM
typedef enum CiPsPdpAddrType_tag
{
    CI_PS_PDP_INVALID_ADDR = 0,
    CI_PS_PDP_IPV4,          // 4 bytes length
    CI_PS_PDP_FULL_IPV6,     // 16 bytes length
    CI_PS_PDP_IPV6_INTERFACE // 8 bytes length
}CiPsPdpAddrType;

//ICAT EXPORTED STRUCT
typedef struct CiPsPdpIpAddr_struct
{
  UINT16   addrType;     //CiPsPdpAddrType, invalid - 0, ipv4 - 1, Full ipv6 - 2, Ipv6 interface - 3;
  UINT16   subnetLength; // 0 - invalid
  UINT8    valData[CI_PS_PDP_ADDR_MAX_LENGTH];  /**< Address field */
}CiPsPdpIpAddr; /* PDP address */ // size = 20 bytes

//ICAT EXPORTED ENUM
typedef enum CiPsPdpBearType_struct
{
    CI_PS_INVALID_PDP_TYPE = 0,
    CI_PS_PRIMARY_PDP = 1,
    CI_PS_DEFAULT_PDP = 1,

    CI_PS_SECONDARY_PDP = 2,
    CI_PS_DEDICATED_PDP = 2,
    
    CI_PS_MAX_PDP_TYPE
}_CiPsPdpBearType;

typedef UINT8 CiPsPdpBearType;

//ICAT EXPORTED ENUM
typedef enum CIPSREQTYPE_TAG
{
    CI_PS_REQ_FOR_NEW_OR_HANDOVER_PDP = 0,      /*0 - PDP context is for new PDP context establishment or for handover from a non-3GPP access network */
    CI_PS_REQ_FOR_EMERGENCY_BEARER_SERVICES = 1,/*1 - PDP context is for emergency bearer services */
    CI_PS_REQ_FOR_NEW_PDP = 2,                  /*2 - PDP context is for new PDP context establishment */
    CI_PS_REQ_FOR_HANDOVER = 3,                 /*3 - PDP context is for handover from a non-3GPP access network */
    CI_PS_REQ_FOR_HANDOVER_EMERGENCY = 4,       /*4 - PDP context is for handover of emergency bearer services from a non-3GPP access network */

    CI_PS_REQ_FOR_MMS = 10,                     /*10 - PDP context is for MMS (internal use only) */     
    
    CI_PS_NUM_REQ_TYPE
}_CiPsReqType;

typedef UINT8 CiPsReqType;

/** \brief PDP context definition. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtx_struct
{
    UINT8        	  cid;       				   /**< PDP context identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
    CiPsPdpType 	  type;      				   /**< PDP type \sa CiPsPdpType */
    UINT8        	  bearer_id;       			   /**< PDP Context Identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
    CiPsPdpBearType   pdpBearType;                    // 0 - invalid, 1 - primary/default PDP, 2 - dedicated/secondary PDP
    UINT8             p_cid;
    
    /* # Start Contiguous Code Section # */
    CiBoolean    	  apnPresent;    				/**< Flag indicating that the APN is present (optional field) \sa CCI API Ref Manual*/
    CiString          apn;           					/**< APN, length range [CI_PS_APN_MIN_SIZE - CI_PS_APN_MAX_SIZE]. \sa CCI API Ref Manual */
    //CiBoolean    		addrPresent;   				/**< Flag indicating that the address is present (optional field) \sa CCI API Ref Manual */
    CiPsPdpIpAddr     ipv4Addr;         					/**< PDP address \sa CiPsPdpAddr_struct */
    CiPsPdpIpAddr     ipv6Addr;
    CiBoolean         dcompPresent;  				/**< Flag indicating that data compression field is present \sa CCI API Ref Manual */
    CiPsDcomp         dcomp;        				 	/**< PDP data compression, only applicable to SNDCP, ignore it for UMTS \sa CiPsDcomp */
    CiBoolean         hcompPresent;  				/**< Flag indicating that header compression field is present \sa CCI API Ref Manual */
    CiPsHcomp         hcomp;         					/**< PDP header compression \sa CiPsHcomp */
    CiBoolean         pdParasPresent;				/**< Flag indicating that the pdParas is present (optional field) \sa CCI API Ref Manual*/
    CiString          pdParas;       				/**< PDP specific parameters \sa CCI API Ref Manual */

    CiBoolean         ipAddrAllocPresent;
    CiPsIpv4AllocType ipAddrAlloc;

    CiBoolean         reqTypePresent;               /**< Flag indicating that request type field is present \sa CiPsReqType */
    CiPsReqType       reqType;                      /**Type of PDP context activation request, refer to TS27.007 c80*/
    CiBoolean         pCscfDiscoveryPresent;
    CiPsPcscfDiscoveryType pCscfDiscovery;
    CiBoolean         imCnSignallingFlagIndPresent;
    CiPsImCnSignallingFlagIndType  imCnSignallingFlagInd;   /**IM_CN_Signalling_Flag_Ind*/
	
    CiBoolean         esmCausePresent;
    CiPsEsmCauseType  esmCause;
    CiPsSmFollowAct   smFlwAct; // SM following action

//#if defined(DS3_CAT1)
    CiBoolean         nslpiPresent;
    UINT8             nslpi;                /**NSLPI*/
    CiBoolean         securePcoPresent;
    UINT8             securePco;            /**securePCO*/
	
    CiBoolean                 ipv4MtudiscoveryPresent;
    CiPsIpv4MtuDiscoveryType  ipv4Mtudiscovery;     /**IPv4_MTU_discovery*/
    CiBoolean                 localAddrIndPresent;
    CiPsLocalAddrIndType      localAddrInd;         /**Local_Addr_ind*/
    CiBoolean                 nonIpMtuDiscoveryPresent;
    CiPsNonIpMtuDiscoveryType nonIpMtuDiscovery;    /**Non-IP_MTU_discovery*/
//#endif	
}CiPsPdpCtx;

/** \brief PDP context information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxInfo_struct
{
  CiBoolean   actState; /**< Activation state; TRUE: activate \sa CCI API Ref Manual */
  CiPsPdpCtx  pdpCtx;        /**< PDP context parameters \sa CiPsPdpCtx_struct */
} CiPsPdpCtxInfo;

/* APPS LOOPBACK SUPPORT */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxLoopback_struct
{
    UINT8        	  cid;       				   /**< PDP context identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
    CiPsPdpType 	  type;      				   /**< PDP type \sa CiPsPdpType */
}CiPsPdpCtxLoopback;

//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxInfoLoopback_struct
{
  CiBoolean             actState; /**< Activation state; TRUE: activate \sa CCI API Ref Manual */
  CiPsPdpCtxLoopback    pdpCtx;   /**< PDP context parameters \sa CiPsPdpCtx_struct */
} CiPsPdpCtxInfoLoopback;
/* APPS LOOPBACK SUPPORT - END*/

/** \brief PDP context capability */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxCap_struct
{
  CiNumericRange cids; 		/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] \sa CCI API Ref Manual  */
  CiPsPdpType    type;      /**< PDP type \sa CiPsPdpType  */
  CiBitRange     bitsDcomp;   /**< Data compression capability, represented as bit mask. Each bit represents a value in CiPsDcomp.  \sa CiPsDcomp */
  /* each bit represents a capability in CiPsDcomp,
                                 e.g. (bitsDcomp&(1<< CI_PS_HCOMP_OFF))!=0 means
                                        CI_PS_DCOMP_OFF is supported,
                                      (bitsDcomp&(1<<CI_PS_DCOMP_ON))!=0 means
                                        CI_PS_DCOMP_ON  is supported */
  CiBitRange     bitsHcomp;   /**< Header compression capability, represented as bit mask. Each bit represents a value in CiPsHcomp.  \sa CiPsHcomp*/

  /* TBD, not sure <pd1> to <pdn> is going to be presented */
} CiPsPdpCtxCap;


/** \brief PDP context capability profiles */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxCaps_struct
{
  UINT8         size;       /**< Number of capability profiles; currently only one profile is supported */
  CiPsPdpCtxCap  caps[CI_CURRENT_SUPPORT_PDP_NUM_TYPE];   /**< PDP context capabilities \sa CiPsPdpCtxCap_struct*/
} CiPsPdpCtxCaps;

/** \brief Activated status of the PDP context */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxActState_struct
{
  UINT8      	cid;       		/**< PDP context identification, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiBoolean  	activated; 	/**< TRUE: activated; FALSE: deactivated \sa CCI API Ref Manual */
} CiPsPdpCtxActState;

/** \addtogroup  SpecificSGRelated
 * @{ */
/** \brief Pointer to PDP activated status list
 * \sa  CiPsPdpCtxActState_struct
 * \remarks Common Data Section */
typedef CiPsPdpCtxActState *CiPsPdpCtxActStateListPtr;
/**@}*/

/** \brief L2 protocol types  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSL2P_TAG
{
  CI_PS_L2P_NONE=0,  	/**< Not PPP */
  CI_PS_L2P_PPP,     	/**< PPP */

  CI_PS_NUM_L2PS
} _CiPsL2P;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief L2 protocol types
 *  \sa CIPSL2P_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsL2P;
/**@}*/

/** \brief GSM/GPRS mobile class values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSGSMGPRSCLASS_TAG
{
  CI_PS_GSMGPRS_CLASS_A = 0,  		/**< Class A */
  CI_PS_GSMGPRS_CLASS_B,      		/**< Class B */
  CI_PS_GSMGPRS_CLASS_CS,     		/**< Class C, GPRS only */
  CI_PS_GSMGPRS_CLASS_CC,     		/**< Class C, circuit switch only */

  CI_PS_GSMGPRS_NUM_CLASSES
} _CiPsGsmGprsClass;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Mobile class for GSM/GPRS
 *  \sa CIPSGSMGPRSCLASS_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsGsmGprsClass;
/**@}*/

//ICAT EXPORTED ENUM
/** \brief Network registration configuration flag values */
/** \remarks Common Data Section */
typedef enum CIPSNWREGINDFLAG_TAG
{
  CI_PS_NW_REG_IND_DISABLE = 0,        /**< Disable network registration status reports, n = 0 */
  CI_PS_NW_REG_IND_ENABLE_STA_ONLY,    /**< Enable network registration status reports, n = 1 */
  CI_PS_NW_REG_IND_ENABLE_DETAIL,      /**< Enable detailed network registration status reports, n= 2 */
  CI_PS_NW_REG_IND_ENABLE_MORE_DETAIL, /**< Enable more detailed network registration status reports, n = 3 */
  CI_PS_NW_REG_IND_ENABLE_PSM,         /**< Enable more detailed network registration status reports, n = 4 */
  CI_PS_NW_REG_IND_ENABLE_PSM_DETAIL,  /**< Enable more detailed network registration status reports, n = 5 */

  CI_PS_NW_REG_IND_ENABLE_NUM
  
} _CiPsNwRegIndFlag;

/** \addtogroup  SpecificSGRelated
 * @{ */
/** \brief Configures network registration status reports
 *  \sa CIPSNWREGINDFLAG_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsNwRegIndFlag;
typedef UINT8 CiPs4GNwRegIndFlag;
/**@}*/


/** \brief Network registration status values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSNWREGSTATUS_TAG
{
  CI_PS_NW_REG_STA_NOT_REGED = 0, 				/**< Not registered and not searching */
  CI_PS_NW_REG_STA_REG_HPLMN,     				/**< Registered on home PLMN */
  CI_PS_NW_REG_STA_TRYING,        				/**< Not registered, but cellular subsystem is searching for a PLMN to register to */
  CI_PS_NW_REG_STA_REG_DENIED,    				/**< Registration denied */
  CI_PS_NW_REG_STA_UNKNOWN,       				/**< Unknown */
  CI_PS_NW_REG_STA_REG_ROAMING,    				/**< Registered on visited PLMN */
  CI_PS_NW_REG_STA_SMS_ONLY_HOME,				/**< registered for "SMS only", home network (applicable only when <AcT> indicates E-UTRAN) */
  CI_PS_NW_REG_STA_SMS_ONLY_ROAMING,			/**< registered for "SMS only", roaming (applicable only when <AcT> indicates E-UTRAN) */
  CI_PS_NW_REG_STA_EMERGENCY_ONLY_NOT_USED,		/**< attached for emergency bearer services only (see NOTE 2) (not applicable) */
  CI_PS_NW_REG_STA_CSFB_NOT_PREFERRED_HOME,		/**<registered for "CSFB not preferred", home network (applicable only when <AcT> indicates E-UTRAN) */
  CI_PS_NW_REG_STA_CSFB_NOT_PREFERRED_ROAMING,	/**<registered for "CSFB not preferred", roaming (applicable only when <AcT> indicates E-UTRAN) */
  CI_PS_NW_REG_STA_REG_EMERGENCY,    			/**< attached for emergency bearer services only*/

  CI_PS_NW_REG_STA_REG_DENIED_IN_ROAMING,       /**< registeration denied in roaming, only used for SSG project by now*/
  CI_PS_NW_REG_STA_SYNC_DONE_IN_LTE_ROAMING,    /**< sync done in LTE roaming network, only used for SSG project by now*/

  CI_PS_NW_REG_STA_ECALL_INACTIVE,              /**< eCall only when camp on LTE for eCall over IMS */

  CI_PS_NUM_REGSTATUS                			/**< Number of status values defined */
} _CiPsNwRegStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Network registration status
 *  \sa CIPSNWREGSTATUS_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPsNwRegStatus;
/**@}*/

/** \brief  Access technology modes (added in release 4; See TC 27.007) */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_ACT_TECH_MODE
{
  CI_PS_ACT_GSM = 0,            /**< GSM */
  CI_PS_ACT_GSM_COMPACT,		/**< Not supported */
  CI_PS_ACT_UTRAN,              /**< UTRAN */

  CI_PS_ACT_GSM_EGPRS,          /**< GSM w/EGPRS */
  CI_PS_ACT_UTRAN_HSDPA,        /**< UTRAN w/HSDPA */
  CI_PS_ACT_UTRAN_HSUPA,        /**< UTRAN w/HSUPA */
  CI_PS_ACT_UTRAN_HSPA,         /**< UTRAN w/HSDPA and HSUPA */
  CI_PS_ACT_EUTRAN,             /**< E-UTRAN */ 
  
  CI_PS_ACT_UTRAN_HSPA_PLUS,    /**< UTRAN w/HSPA+ */
  CI_PS_ACT_EUTRAN_PLUS,        /**< E-UTRAN  CA*/ 
  /* Added by taow 20190708 CQ00115423, begin */
  CI_PS_ACT_UTRAN_DC_HSPA,      /**< DC-HSPA*/
  /* Added by taow 20190708 CQ00115423, end */
  
  CI_PS_NUM_ACT
} _CiPsAccTechMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Access technology modes (added in release 4; see TC 27.007)
 * \sa CIPS_ACT_TECH_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiPsAccTechMode;

/** \brief cuase type for reject cause  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_CAUSE_TYPE {
    CI_PS_CAUSE_TYPE_PS = 0, 			/**< Indicates that <reject_cause> contains a GMM/EMM cause value, see 3GPP TS 24.008 [8] Annex G.*/
    CI_PS_CAUSE_TYPE_MANUFACTURER,      /**< Indicates that <reject_cause> contains a manufacturer specific cause  */
	CI_PS_CAUSE_NONE,
    CI_PS_NUM_CAUSE_TYPE
} _CiPsCauseType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Available values for cuase type
 *  \sa CIMM_CUASE_TYPE
 * \remarks Common Data Section */
typedef UINT8 CiPsCauseType;


/*  add by perse 01032018  add +CREG/+CGREG/+CEREG  indication content with rplmn  CQ00117472,begin */
//#if defined(CRANE_Z1)

//ICAT EXPORTED ENUM
typedef enum CIPS_NETOP_DIGIT_MNC {
    CIPS_NETOP_TWO_DIGIT_MNC = 2,   	/*2 digit */
    CIPS_NETOP_THREE_DIGIT_MNC,     	/*3 digit */
    /* This one must always be last in the list! */
    CIPS_NUM_NETOP_DIGIT_MNC      	
} _CiPsNetOpDigitMnc;

typedef UINT8 CiPsNetOpDigitMnc; /**< Reported as 2 digit or 3 digit  */
/** \brief Network registration information. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsNetworkId_struct {
    UINT16  CountryCode;    /**< 3-digit country code */
    UINT16  NetworkCode;    /**< 3-digit network code */

    CiPsNetOpDigitMnc MncDigit;         /**< MncDigit     \sa CiPsNetOpDigitMnc   */
} CiPsNetworkId;
//#endif
/*  add by perse 01032018  add +CREG/+CGREG/+CEREG  indication content with rplmn  CQ00117472,end */

/** \brief Network registration information. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsNwRegInfo_struct
{
    CiPsNwRegStatus   status;   /**< Network registration status \sa CiPsNwRegStatus */

    CiBoolean         lacPresent; /**< Indicates if LAC and cell ID are present \sa CCI API Ref Manual */
    UINT16            lac;        /**< Location area code */
    UINT32            cellId;     /**< Cell ID */
    CiPsAccTechMode   act;        /**< Network access technology (GSM, UTRAN, LTE etc.)  \sa CiPsAccTechMode */  
    UINT8             rac;        /**<one byte routing area code> */

    CiBoolean         causePresent; /**< Indicates if causeType and rejectCause are present> **/
    CiPsCauseType     causeType;    /**<cause_type>: integer type; indicates the type of <reject_cause>**/
    UINT32            rejectCause;  /**<reject_cause>: integer type; contains the cause of the failed registration **/
    /*  add by perse 01032018  add +CREG/+CGREG/+CEREG  indication content with rplmn  CQ00117472,begin */
	//#if defined(CRANE_Z1)
    CiPsNetworkId  rplmnInfo ;/**reprot rplmn information*/
	//#endif
     /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn  CQ00117472,end */
}CiPsNwRegInfo;

/** \brief 4G Network registration information. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPs4GNwRegInfo_struct
{
    CiPsNwRegStatus   status;     /**< Network registration status. \sa CiPsNwRegStatus */

    CiBoolean         tacPresent; /**< Indicates if LAC and Cell ID are present. \sa CCI API Ref Manual */
    UINT16            tac;        /**< String type; two byte tracking area code in hexadecimal format (e.g. "00C3" equals 195 in decimal)*/
    UINT32            cellId;     /**< Cell ID */
    CiPsAccTechMode   act;        /**< Network access technology (GSM, UTRAN, LTE etc.)  \sa CiPsAccTechMode */  

    CiBoolean         causePresent; /**< Indicates if causeType and rejectCause are present. >**/
    CiPsCauseType     causeType;    /**<cause_type>: integer type; indicates the type of <reject_cause>**/
    UINT32            rejectCause;  /**<reject_cause>: integer type; contains the cause of the failed registration.**/

//#if defined(DS3_CAT1)
    CiBoolean         activeTimePresent; /**< Indicates if Active Time is present. >**/
    UINT8             activeTime;        /**< string type, one byte in an 8 bit format, indicates the Active Timer value T3324 **/

    CiBoolean         periodicTauPresent; /**< Indicates if Periodic TAU is prenset. >**/
    UINT8             periodicTau;        /**< string type, one byte in an 8 bit format, indicates the extended periodic TAU value T3412 **/
//#endif

    /* add by xwzhou for CQ67291 on 08052014, begin */
    CiBoolean         volteAvailable;
    CiBoolean         imsEmergencyAvailable;
    /* add by xwzhou for CQ67291 on 08052014, end */
    /*  add by perse 01032018  add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472,begin */
	//#if defined(CRANE_Z1)
    CiPsNetworkId  rplmnInfo ;/**reprot rplmn information*/
	//#endif
    /*  add by perse 01032018 add +CREG/+CGREG/+CEREG  indication content with rplmn CQ00117472 ,end */
}CiPs4GNwRegInfo;


/** \brief 2.5G (R97) QoS: Reliability class. See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSQOSRELIABILITYCLASS
{
  CI_PS_QOS_RELIABILITY_CLASS_SUBSCRIBED = 0, 	/**< Subscribed reliability class */
  CI_PS_QOS_RELIABILITY_CLASS_1,              	/**< Acknowledged GTP, LLC, and RLC; protected data */
    CI_PS_QOS_RELIABILITY_CLASS_2,              /**< Unacknowledged GTP; acknowledged LLC and RLC, Protected data */
  CI_PS_QOS_RELIABILITY_CLASS_3,              	/**< Unacknowledged GTP and LLC; acknowledged RLC, Protected data */
  CI_PS_QOS_RELIABILITY_CLASS_4,              	/**< Unacknowledged GTP, LLC, and RLC, protected data */
  CI_PS_QOS_RELIABILITY_CLASS_5,              	/**< Unacknowledged GTP, LLC, and RLC, unprotected data */

  CI_PS_QOS_NUM_RELIABILITY_CLASSES
} _CiPsQosReliabilityClass;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Reliability class
 *  \sa CIPSQOSRELIABILITYCLASS
 * \remarks Common Data Section */
typedef UINT8 CiPsQosReliabilityClass;
/**@}*/

/** \brief 2.5G (R97) quality of service (QoS) profile. See 3GPP TS 24.008  section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsQosProfile_struct
{
  UINT8 precedence;         	/**< Precedence class */
  UINT8 delay;              	/**< Delay class */
  UINT8 reliability;        	/**< Reliability class */
  UINT8 peak;               	/**< Peak throughput */
  UINT8 mean;               	/**< Mean throughput */
} CiPsQosProfile;

// --------------- SCR #1401348: BEGIN ------------------------------------

/** \brief Secondary PDP context, as defined for the "AT+CGDSCONT" command */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsSecPdpCtx_struct
{
  UINT8        		cid;     					/**< PDP context identifier */
  UINT8        		p_cid;   					/**< Primary PDP context identifier */
  UINT8        	  	bearer_id;       			/**< PDP Context Identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiBoolean    		dcompPresent;			/**< TRUE if present \sa CCI API Ref Manual */
  CiBoolean    		hcompPresent;			/**< TRUE if present \sa CCI API Ref Manual */
  CiPsDcomp    	dcomp;					/**< PDP data compression, only applicable to SNDCP, ignore it for UMTS \sa CiPsDcomp */
  CiPsHcomp    	hcomp;					/**< PDP header compression  \sa CiPsHcomp */
  CiBoolean    imCnSigFlagPresent;
  CiPsImCnSignallingFlagIndType imCnSigFlag;
} CiPsSecPdpCtx;

/** \brief Secondary PDP context information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsSecPdpCtxInfo_struct
{
  CiBoolean     		actState; 			/**< Activation state \sa CCI API Ref Manual */
  CiPsSecPdpCtx  		secPdpCtx;			/**< Secondary PDP context information \sa CiPsSecPdpCtx_struct */
} CiPsSecPdpCtxInfo;

/** \brief QoS type values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GQOSTYPE_TAG
{
  CI_PS_3G_QOSTYPE_MIN = 0,   	/**< Minimum QoS */
  CI_PS_3G_QOSTYPE_REQ,       	/**< Requested QoS */
  CI_PS_3G_QOSTYPE_NEG,       	/**< Negotiated QoS */

  CI_PS_3G_QOSTYPE_NUMTYPES
} _CiPs3GQosType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief QoS types
 *  \sa CIPS3GQOSTYPE_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GQosType;
/**@}*/

/** \brief 3G QoS: traffic class values. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GTRAFFICCLASS_TAG
{
  CI_PS_3G_TRAFFIC_CLASS_CONVERSATIONAL = 0,  	/**< Conversational */
  CI_PS_3G_TRAFFIC_CLASS_STREAMING,           		/**< Streaming */
  CI_PS_3G_TRAFFIC_CLASS_INTERACTIVE,         		/**< Interactive */
  CI_PS_3G_TRAFFIC_CLASS_BACKGROUND,          		/**< Background */
  CI_PS_3G_TRAFFIC_CLASS_SUBSCRIBED,          		/**< Subscribed value */

  CI_PS_3G_TRAFFIC_CLASS_NUMCLASSES
} _CiPs3GTrafficClass;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief 3G QoS: traffic class. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8.
 *  \sa CIPS3GTRAFFICCLASS_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GTrafficClass;
/**@}*/

/** \brief 3G QoS: delivery order values. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GDLVORDER_TAG
{
  CI_PS_3G_DLV_ORDER_NO = 0,                  		/**< Without delivery order (no) */
  CI_PS_3G_DLV_ORDER_YES,                     			/**< With delivery order (yes) */
  CI_PS_3G_DLV_ORDER_SUBSCRIBED,              		/**< Subscribed value */

  CI_PS_3G_NUM_DLV_ORDER
} _CiPs3GDlvOrder;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief 3G QoS: delivery order values. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8.
 *  \sa CIPS3GDLVORDER_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GDlvOrder;
/**@}*/

/** \brief 3G QoS: delivery of erroneous SDUs. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GDLVERRORSDU_TAG
{
  CI_PS_3G_DLV_ERROR_SDU_NO = 0,                		/**< Erroneous SDUs are not delivered (no) */
  CI_PS_3G_DLV_ERROR_SDU_YES,                   		/**< Erroneous SDUs are delivered (yes) */
  CI_PS_3G_DLV_ERROR_SDU_NODETECT,              	/**< No detect ('-') */
  CI_PS_3G_DLV_ERROR_SDU_SUBSCRIBED,            	/**< Subscribed value */

  CI_PS_3G_NUM_DLV_ERROR_SDU
} _CiPs3GDlvErrorSdu;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  3G QoS: delivery of erroneous SDUs. See 3GPP TS 27.007 sections 10.1.6 through 10.1.8.
 *  \sa CIPS3GDLVERRORSDU_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GDlvErrorSdu;
/**@}*/

/** \brief 3G QoS: Residual BER values (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GRESIDUALBER_TAG
{
  CI_PS_3G_RESIDUAL_BER_SUBSCRIBED = 0,       	/**< Subscribed value */
  CI_PS_3G_RESIDUAL_BER_5EM2,                 		/**< 5 * 10^-2 */
  CI_PS_3G_RESIDUAL_BER_1EM2,                 		/**< 1 * 10^-2 */
  CI_PS_3G_RESIDUAL_BER_5EM3,                 		/**< 5 * 10^-3 */
  CI_PS_3G_RESIDUAL_BER_4EM3,                 		/**< 4 * 10^-3 */
  CI_PS_3G_RESIDUAL_BER_1EM3,                 		/**< 1 * 10^-3 */
  CI_PS_3G_RESIDUAL_BER_1EM4,                 		/**< 1 * 10^-4 */
  CI_PS_3G_RESIDUAL_BER_1EM5,                 		/**< 1 * 10^-5 */
  CI_PS_3G_RESIDUAL_BER_1EM6,                 		/**< 1 * 10^-6 */
  CI_PS_3G_RESIDUAL_BER_6EM8,                		/**< 6 * 10^-8 */

  CI_PS_3G_NUM_RESIDUAL_BER
} _CiPs3GResidualBer;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  3G QoS: Residual BER (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5.
 *  \sa CIPS3GRESIDUALBER_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GResidualBer;
/**@}*/

/** \brief 3G QoS: SDU error ratio values (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GSDUERRORRATIO_TAG
{
  CI_PS_3G_SDU_ERROR_RATIO_SUBSCRIBED = 0,    /**< Subscribed value */
  CI_PS_3G_SDU_ERROR_RATIO_1EM2,              /**< 1 * 10^-2 */
  CI_PS_3G_SDU_ERROR_RATIO_7EM3,              /**< 7 * 10^-3 */
  CI_PS_3G_SDU_ERROR_RATIO_1EM3,              /**< 1 * 10^-3 */
  CI_PS_3G_SDU_ERROR_RATIO_1EM4,              /**< 1 * 10^-4 */
  CI_PS_3G_SDU_ERROR_RATIO_1EM5,              /**< 1 * 10^-5 */
  CI_PS_3G_SDU_ERROR_RATIO_1EM6,              /**< 1 * 10^-6 */
  CI_PS_3G_SDU_ERROR_RATIO_1EM1,              /**< 1 * 10^-1 */

  CI_PS_3G_NUM_SDU_ERROR_RATIOS
} _CiPs3GSduErrorRatio;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  3G QoS: SDU error ratio (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5.
 *  \sa CIPS3GSDUERRORRATIO_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GSduErrorRatio;
/**@}*/

/** \brief 3G QoS: traffic handling priority values (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS3GTRAFFICPRIORITY_TAG
{
  CI_PS_3G_SDU_TRAFFIC_PRIORITY_SUBSCRIBED = 0,   	/**< Subscribed value */
  CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_1,          		/**< Priority Level 1 */
  CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_2,          		/**< Priority Level 2 */
  CI_PS_3G_SDU_TRAFFIC_PRIORITY_LEVEL_3,          		/**< Priority Level 3 */

  CI_PS_3G_NUM_TRAFFIC_PRIORITIES
} _CiPs3GTrafficPriority;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  3G QoS: traffic handling priority (TS 27.007 does not define values). See 3GPP TS 24.008 section 10.5.6.5.
 *  \sa CIPS3GTRAFFICPRIORITY_TAG
 * \remarks Common Data Section */
typedef UINT8 CiPs3GTrafficPriority;

/* 3G QoS: Value used for "Subscribed" setting in binary coded QoS parameter fields */
#define CI_3G_QOS_SUBSCRIBED_BINARY_VALUE 0
/**@}*/

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  2.5G (R97) quality of service (QoS) profile. See TS 24.008  section 10.5.6.5 for the parameter field definitions. \sa CiPsQosProfile
 * \remarks Common Data Section */
typedef CiPsQosProfile CiPs25GQosProfile;
/**@}*/

/** \brief 3G QoS: Possible extension octets for 3G QoS. See 3GPP TS 24.008 section 10.5.6.5 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSISEXTENSION_TAG
{
	CI_PS_3G_MAX_BIT_RATE_FOR_DL = 0,		/**< Maximum bit rate for DL */
	CI_PS_3G_GUARNTEED_BIT_RATE_FOR_DL , 	/**< Maximum guaranteed bit rate for DL */
	CI_PS_3G_MAX_BIT_RATE_FOR_UL,			/**< Maximum bit rate for UL */
	CI_PS_3G_GUARNTEED_BIT_RATE_FOR_UL, 	/**< Maximum guaranteed bit rate for UL */
	CI_PS_3G_NUM_EXTENTION_IND = 0x7FFFFFFF
}_CiPsIsExtensionType;


/** \addtogroup  SpecificSGRelated
Bit mask indicating if maximum bit rate and guaranteed bit rate for downlink or uplink are encoded as extension bytes.
 * @{ */
/**   \brief  3G QoS:  A set bit indicates the parameter is encoded as extension byte octet 15-octet 18 according to 3GPP TS 24.008 section 10.5.6.5.
					 A cleared bit indicates the parameter is encoded as octet 8, octet9, octet12, or octet 13 according to 3GPP TS 24.008 section 10.5.6.5.
					 Extended encoding for UL is supported in Release 7 products
 *  \sa CIPSISEXTENSION_TAG
 * \remarks Common Data Section */
typedef CiBitRange CiPsIsExtensionType;

/** \brief 3G QoS: Source statistic descriptor values. See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_SOURCE_STATI_DESC_TAG
{
	CI_PS_SOURCE_STAT_DESC_UNKNOWN = 0,   	/**< Unknown */
	CI_PS_SOURCE_STAT_DESC_SPEECH,			/**< Speech */
	CI_PS_SOURCE_STAT_DESC_NUM = 0x7F
}_CiPsSourceStatisticDescriptorType;

/** \addtogroup  SpecificSGRelated
Specifies characteristics of the source of submitted SDUs.
 * @{ */
/**   \brief  3G QoS:  Specifies characteristics of the source of submitted SDUs
 *  \sa
 * \remarks Common Data Section */
typedef UINT8 CiPsSourceStatisticDescriptorType;

/** \brief 3G QoS: Signaling indication values. See 3GPP TS 24.008 section 10.5.6.5. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_SIGNALLING_IND_TAG
{
	CI_PS_NOT_OPTIMIZED_FOR_SIGNALLING  = 0,   	/**< Not optimized for signaling traffic */
	CI_PS_OPTIMIZED_FOR_SIGNALLING,				/**< Optimized for signaling traffic */
	CI_PS_SIGNALLING_IND_NUM = 0x7F
}_CiPsSignallingIndicationType;

/** \addtogroup  SpecificSGRelated
Indicates the signaling nature of the submitted SDUs
 * @{ */
/**   \brief  3G QoS:  Indicates the signaling nature of the submitted SDUs
 *  \sa
 * \remarks Common Data Section */
typedef UINT8 CiPsSignallingIndicationType;

/** \brief 3G (R99) Quality of Service (QoS) profile. See TS 24.008 v3.11.0, Section 10.5.6.5 for the parameter field definitions.
 * Note that *all* QoS information is required from the MS, if it's available.
 * We need both the "R97" parameters (defined above) and the 3G ("R99") parameters. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPs3GQosProfile_struct
{
  CiPs3GTrafficClass    		trafficClass;       		/**< Traffic class \sa  CiPs3GTrafficClass */
  CiPs3GDlvOrder        		deliveryOrder;      		/**< Delivery order \sa  CiPs3GDlvOrder */
  CiPs3GDlvErrorSdu     	deliveryOfErrSdu;   			/**< Delivery of erroneous SDUs \sa  CiPs3GDlvErrorSdu */
  CiPs3GResidualBer     	resBER;             			/**< Residual bit error rate \sa  CiPs3GResidualBer */
  CiPs3GSduErrorRatio   	sduErrRatio;        			/**< SDU error ratio \sa  CiPs3GSduErrorRatio */
  CiPs3GTrafficPriority 		thPriority;         		/**< Traffic handling priority (interactive class only) \sa  CiPs3GTrafficPriority */

  UINT8                 			transDelay;         	/**< Transfer delay (conversational/streaming classes only) */
  UINT8                 			maxSduSize;         	/**< Max SDU size */
  UINT16                 			maxULRate;         		/**< Max bit rate, uplink */
  UINT16                 			maxDLRate;          	/**< Max bit rate, downlink */
  UINT16                 			guaranteedULRate;   	/**< Guaranteed bit rate, uplink */
  UINT16                 			guaranteedDLRate;   	/**< Guaranteed bit rate, downlink */
  CiPsIsExtensionType				IsExtension;			/**< Bit mask indicating if the parameters maxDLRate and guaranteedDLRate are encoded as 
  																	extension bytes */
  CiPsSourceStatisticDescriptorType SourceStatisticDescriptor; /**< Specifies characteristics of the source of submitted SDUs */																		
  CiPsSignallingIndicationType      SignallingIndication;	/**< Indicates the signaling nature of the submitted SDUs. */
    
} CiPs3GQosProfile;

/** \addtogroup  SpecificSGRelated
 * @{ */
/** \brief  Address mask
 * \sa  CiPsPdpAddr_struct
 * \remarks Common Data Section */
typedef CiPsPdpAddr CiPsPdpAddrMask;


/* Packet Filter for traffic flow template (TFT), as defined for the "AT+CGTFT" command.
 * References:  3GPP TS 27.007 Section 10.1.3
 *              3GPP TS 23.060 Section 15.3
 *              3GPP TS 24.008 Section 10.5.6.12
 *
 * Note: In reference 24.008 (10.5.6.12) indicates that there are also a single destination
 *       and single source port types, but these are not specified as part of the AT command
 *       in the 27.007 (10.1.3).
 */

#define CI_PS_MAX_TFT_FILTERS           16
#define CI_PS_MAX_IPV4_FILTER_LENGTH    32
#define CI_PS_MAX_IPV6_FILTER_LENGTH    60

#define CI_PS_MAX_FILTER_LENGTH         CI_PS_MAX_IPV4_FILTER_LENGTH
#define CI_PS_MAX_FILTER_CONTENTS       ( CI_PS_MAX_FILTER_LENGTH - 3 )
/**@}*/

//Z.S. MT PS support - start
/** \brief TFT direction according TS27.007 10.1.3 */
/** \remarks tft direction */
//ICAT EXPORTED ENUM
typedef enum CIPS_TFT_DIRECTION_IND_TAG
{
	CI_PS_TFT_DIRECTION_PRE_R7 = 0,   	
	CI_PS_TFT_DIRECTION_UPLINK,				
	CI_PS_TFT_DIRECTION_DOWNLINK,
	CI_PS_TFT_DIRECTION_BI_DIRECTIONAL,
  	CI_PS_NUM_TFT_DIR
}_CiPsTftDirectionIndicationType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  The transmission direction in which the packet
 *  		  filter shall be applied
 *  \sa CIPS_COUNTERREPORTTYPES
 * \remarks Common Data Section */
typedef UINT8 CiPsTftDirectionIndicationType;
/**@}*/
/** \brief TftFilter structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsTftFilter_struct
{
    UINT8            cid;                   /**< PDP Context Identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
    UINT8            pfId;          		/**< Packet filter identifier */
    UINT8            epIndex;       		/**< Evaluation precedence index */
    UINT8            pIdNextHdr;    		/**< Protocol number (ipv4) / next header (ipv6) */
    CiBoolean        pIdNextHdrPresent; 	/**< TRUE: if present \sa CCI API Ref Manual */ //Michal
    UINT8            tosTc;         			/**< Type of service / traffic class */
    CiBoolean        tosPresent;  			/**< TRUE: if present \sa CCI API Ref Manual */ //Michal
    UINT8            tosTcMask;     		/**< Type of service / traffic class mask */
    CiNumericRange   dstPortRange;  		/**< Destination port range \sa CCI API Ref Manual */
    CiBoolean        dstPortRangePresent; /**< TRUE: if present \sa CCI API Ref Manual */ //Michal
    CiNumericRange   srcPortRange;  		/**< Source port range \sa CCI API Ref Manual */
    CiBoolean		 srcPortRangePresent; /**< TRUE: if present \sa CCI API Ref Manual */ //Michal

    UINT32           ipSecSPI;      		/**< IPSec security parameter index */
    CiBoolean        ipSecSPIPresent; 	/**< TRUE: if present  \sa CCI API Ref Manual */ //Michal
    UINT32           flowLabel;     		/**< Flow label */
    CiBoolean        flowLabelPresent;  	/**< TRUE: if present  \sa CCI API Ref Manual */ //Michal
    CiPsPdpIpAddr    remoteAddrAndMask;       	    /**< remote address and subnet mask */ // the netmask infor store in this struct.
    //CiPsPdpAddrMask  	srcAddrMask;   				/**< Source address mask - subnet mask \sa CiPsPdpAddrMask */
    CiPsTftDirectionIndicationType  direction;					/**< specifies the transmission direction in which the packet filter shall be applied */
    UINT8            nwpfId;				/**< NW Packet filter identifier */
    
    CiPsPdpIpAddr    localAddrAndMask;     /**< local address and subnet mask, seems useless */ 
}CiPsTftFilter;

/** \brief TFT Action code. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPSTFTOPCODE_TAG
{
    CI_PS_TFT_OPCODE_SPARE = 0,
    CI_PS_TFT_OPCODE_CREATE_NEW,
    CI_PS_TFT_OPCODE_DELETE_EXISTING,
    CI_PS_TFT_OPCODE_ADD_PACKET_FILTERS,
    CI_PS_TFT_OPCODE_REPLACE_PACKET_FILTERS,
    CI_PS_TFT_OPCODE_DELETE_PACKET_FILTERS,
    CI_PS_TFT_OPCODE_NO_TFT_OPERATION,
    CI_PS_NUMBER_OF_TFT_OP_CODES
} _CiPsTftOpCode;
/** \addtogroup  SpecificSGRelated

 * @{ */
/**   \brief CIPSTFTOPCODE_TAG
 *  \sa CIPSTFTOPCODE_TAG
 * \remarks Common Data Section */	
typedef UINT8 CiPsTftOpCode;

#if 0 // useless
/** \brief TFT tamplate struct. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsTft_struct
{
	CiPsTftOpCode 		tftOpCode; 
	UINT8           	numFilters;        						/**< Number of packet filters */
  	CiPsTftFilter   	filters[CI_PS_MAX_TFT_FILTERS];		
} CiPsTrafficFlowTemplate; 
/** \brief PDP context definition */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
#endif
// --------------- SCR #1401348: END   ------------------------------------

/** \brief PDP context identifier structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsIndicatedPdpCtx_struct
{
  UINT8                 cid;      				/**< PDP context identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPsPdpType           type;     			    /**< PDP type \sa CiPsPdpType */
  CiPsPdpBearType       pdpBearType;            /**Primary PDP, or secondary PDP */
  UINT8                 p_cid;                  /**only valid, when secondary PDP*/

  //CiBoolean      		addrPresent;            /**< TRUE: if present \sa CCI API Ref Manual */
  //CiPsPdpAddr    		addr;                   /**< PDP address string \sa CiPsPdpAddr_struct  */
  CiPsPdpIpAddr         ipv4Addr;               /**if not vaiable, addrType = CI_PS_PDP_INVALID_ADDR*/
  CiPsPdpIpAddr         ipv6Addr;               /**if not vaiable, addrType = CI_PS_PDP_INVALID_ADDR*/
}CiPsIndicatedPdpCtx;


/** \brief 2.5G (R97) quality of service (QoS) capabilities. See TS 24.008 v3.11.0, section 10.5.6.5 for the range of values defined for each parameter. */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsQosCap_struct
{
  CiPsPdpType   		 type;			/**< PDP type \sa CiPsPdpType */
  CiNumericRange 		precedenceCap;   /**< Precedence class [0-4]  \sa CCI API Ref Manual */
  CiNumericRange 		delayCap;        	/**< Delay class [0-3] \sa CCI API Ref Manual  */
  CiNumericRange 		reliabilityCap;  	/**< Reliability class [0-5] \sa CCI API Ref Manual  */
  CiNumericRange 		peakCap;         	/**< Peak throughput [0-9] \sa CCI API Ref Manual  */
  CiNumericList  		meanCap;         	/**< Mean throughput [0-18, 31] \sa CCI API Ref Manual  */
} CiPsQosCap;

/** \brief List of QoS capabilities per defined PDP context */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPsQosCaps_struct
{
  UINT8 				size;								/**< Number of defined PDP contexts */
   CiPsQosCap   		caps[CI_CURRENT_SUPPORT_PDP_NUM_TYPE];		/**< QoS capabilities, optional if return code is not CIRC_PS_SUCCESS \sa CiPsQosCap_struc */
} CiPsQosCaps;

// --------------- SCR #1401348: BEGIN ------------------------------------

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  2.5G (R97) quality of service (QoS) capabilities. See TS 24.008  section 10.5.6.5 for the range of values defined for each parameter. \sa CiPsQosCap
 * \remarks Common Data Section */
typedef CiPsQosCap CiPs25GQosCap;
/**@}*/

/** \brief 3G (R99) quality of service (QoS) capabilities. See TS 24.008, section 10.5.6.5 for the range of values defined for each parameter.  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPs3GQosCap_struct
{
  CiPsPdpType    	type;					/**< PDP type \sa CiPsPdpType */
  CiNumericRange 	trafficClass;     		/**< Traffic class [0..4] \sa CCI API Ref Manual */
  CiNumericRange 	deliveryOrder;    		/**< Delivery order [0..2] \sa CCI API Ref Manual */
  CiNumericRange 	deliverErrSdu;    		/**< Delivery of erroneous SDUs [0..3] \sa CCI API Ref Manual */
  CiNumericRange 	resBER;           		/**< Residual BER [0..9] \sa CCI API Ref Manual */
  CiNumericRange 	errRatio;         		/**< SDU error ratio [0..7] \sa CCI API Ref Manual */
  CiNumericRange 	thPriority;       		/**< Traffic handling priority [0..3] \sa CCI API Ref Manual */

  CiNumericRange 	transDelay;       		/**< Transfer delay [0x00..0x3e] \sa CCI API Ref Manual */
  CiNumericRange 	maxSduSize;       		/**< Maximum SDU size [0x00..0x99] \sa CCI API Ref Manual */
  CiNumericRange 	maxULRate;        		/**< Max bit rate, uplink [0x00..0xff] \sa CCI API Ref Manual */
  CiNumericRange 	maxDLRate;        		/**< Max bit rate, downlink [0x00..0xff] \sa CCI API Ref Manual */
  CiNumericRange 	guaranteedULRate; 		/**< Guaranteed bit rate, uplink [0x00..0xff] \sa CCI API Ref Manual */
  CiNumericRange 	guaranteedDLRate; 		/**< Guaranteed bit rate, downlink [0x00..0xff] \sa CCI API Ref Manual */
  CiNumericRange 	SourceStatisticDescriptor; /**< Specifies characteristics of the source of submitted SDUs [0x00..0xff] \sa CCI API Ref Manual */
} CiPs3GQosCap;

/** \brief 3G quality of service (QoS) capabilities array  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiPs3GQosCaps_struct
{
  UINT8           		size;										/**< Size */
  CiPs3GQosCap 		caps[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];  	/** 3G QoS capability per defined PDP context \sa CiPs3GQosCap_struct */
																/*--3/5/2009 10:26AM
																 *  Note: need to check max size of array
																 * ------------*/
} CiPs3GQosCaps;

// --------------- SCR #1401348: END   ------------------------------------

//ICAT EXPORTED STRUCT
typedef struct CiNumericRangeBYTE_struct{
    UINT32 min; /* lower limit */
    UINT32 max; /* upper limit */
}CiNumericRangeBYTE;

/******************************************************************************
 *+CGEQOSRDP = <cid>,<QCI>,[<DL_GBR>,<UL_GBR>],[<DL_MBR>,<UL_MBR>][,<DL_AMBR>,<UL_AMBR>]
 *+CGEQOS=[<cid>[,<QCI>[,<DL_GBR>,<UL_GBR>[,<DL_MBR>,<UL_MBR]]]]
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPs4GQosProfile_struct
{
    UINT8                 		qci;         		/**Qos Class Identifier */
    CiBoolean                   gbrMbrPresent;      /**indicate whether GBR & MBR presnt */
    UINT32                 		maxULRate;         	/**<UL_MBR Max Bit Rate, Uplink, in kbps */
    UINT32                 		maxDLRate;          /**<DL_MBR Max Bit Rate, Downlink, in kbps (MAX 256000kbps) */
    UINT32                 		guaranteedULRate;   /**<UL_GBR Guaranteed Bit Rate, Uplink, in kbps */
    UINT32                 		guaranteedDLRate;   /**<DL_GBR Guaranteed Bit Rate, Downlink, in kbps */
    CiBoolean                   ambrPresent;        /**indicate whether AMBR presnt for +CGEQOSRDP */
    UINT32                      apnULAmbr;           /**<UL_AMBR, UL APN aggregate MBR, in kbps */
    UINT32                      apnDLAmbr;           /**<DL_AMBR, DL APN aggregate MBR, in kbps */
}CiPs4GQosProfile;

//ICAT EXPORTED STRUCT
typedef struct CiPs4GQosCap_struct
{
  UINT8                 		qci;         		/**Qos Class Identifier */
  CiNumericRangeBYTE            maxULRate;         		/**< Max Bit Rate, Uplink */
  CiNumericRangeBYTE            maxDLRate;          		/**< Max Bit Rate, Downlink */
  CiNumericRangeBYTE            guaranteedULRate;   		/**< Guaranteed Bit Rate, Uplink */
  CiNumericRangeBYTE            guaranteedDLRate;   		/**< Guaranteed Bit Rate, Downlink */
} CiPs4GQosCap;

//ICAT EXPORTED STRUCT
typedef struct CiPs4GQosCaps_struct
{
	UINT8 				size;										/**< Size. */
	/* # Start Contiguous Code Section # */
	  CiPs4GQosCap		caps[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];		/** 4G QoS capability per defined PDP context. \sa CiPs4GQosCap_struct */
																	
	/* # End Contiguous Code Section # */
} CiPs4GQosCaps;

/** \brief Data counter report type values  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_COUNTERREPORTTYPES
{
  CI_PS_COUNTER_REPORT_ONE_SHOT = 0,    	/**< A single CI_PS_PRIM_COUNTER_IND indication is sent when the information is received from the protocol stack. */
  CI_PS_COUNTER_REPORT_PERIODIC,        	/**< Periodic CI_PS_PRIM_COUNTER_IND indications to be sent at intervals specified
  *       by the interval parameter. The minimum value for the interval parameter is one second; if it is set to zero, CCI uses a
  *       one second interval. */
  CI_PS_COUNTER_REPORT_STOP,            		/**< Stop periodic report */

  CI_PS_NUM_COUNTER_REPORT_TYPES
} _CiPsCounterReportType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief  Data counter report types
 *  \sa CIPS_COUNTERREPORTTYPES
 * \remarks Common Data Section */
typedef UINT8 CiPsCounterReportType;
/**@}*/

/* --- Primitive Definitions --- */

typedef enum CiPsAttachStateCause_Tag
{
    CI_PS_ATTACH_STATE_NO_CAUSE = 0,
    CI_PS_ATTACH_EMERGENCY,

    CI_PS_DETACH_STATE_NO_CAUSE = 0x10, //detach failed cause, start from 0x10
    CI_PS_DETACH_IPV6_RS_FAIL = 0x11,
    CI_PS_DETACH_EMERGENCY,
    
    CI_PS_ATTACH_STATE_CAUSE_NUM
}_CiPsAttachStateCause;

typedef UINT8 CiPsAttachStateCause;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_ATTACH_STATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetAttachStateReq_struct
{
  CiBoolean            state;		/**< State of the PS attachment. TRUE: attach; FALSE: detach. \sa CCI API Ref Manual */
  CiPsAttachStateCause cause;
}CiPsPrimSetAttachStateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_ATTACH_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetAttachStateCnf_struct
{
  CiPsRc rc;		/**< Result code \sa CiPsRc */
} CiPsPrimSetAttachStateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_ATTACH_STATE_REQ">   */
typedef CiEmptyPrim CiPsPrimGetAttachStateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_ATTACH_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetAttachStateCnf_struct
{
  CiPsRc      	rc;		/**< Result code \sa CiPsRc */
  CiBoolean   	state;	/**< State of the PS attachment. TRUE: attached; FALSE: detached. \sa CCI API Ref Manual  */
} CiPsPrimGetAttachStateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefinePdpCtxReq_struct
{
  CiPsPdpCtx            	pdpCtx;			/**< PDP context definition \sa CiPsPdpCtx_struct */
} CiPsPrimDefinePdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefinePdpCtxCnf_struct
{
  CiPsRc rc;						/**< Result code \sa CiPsRc */
} CiPsPrimDefinePdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeletePdpCtxReq_struct
{
  UINT8  cid;		/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimDeletePdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeletePdpCtxCnf_struct
{
  CiPsRc rc;		/**< Result code \sa CiPsRc  */
} CiPsPrimDeletePdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpCtxReq_struct
{
  UINT8  cid;		/**< PDP context identifier   */
} CiPsPrimGetPdpCtxReq;

#define CI_MAX_PCO_OPTS 250

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpCtxCnf_struct
{

    CiPsRc 				rc;				/**< Result code \sa CiPsRc */
    CiBoolean 			ctxPresent;		/**< TRUE: if present \sa CCI API Ref Manual */
    CiPsPdpCtxInfo     	ctx;			/**< PDP context information, optional if rc is not CIRC_PS_SUCCESS \sa CiPsPdpCtxInfo_struct */
    UINT8               pcoData[CI_MAX_PCO_OPTS];   /**< Extended PCO to replace ctx.pdpCtx.pdParas.valStr */ /*Lilei, CQ00133813, 20211104*/
}CiPsPrimGetPdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GPdpCtxDynParaReq_struct
{
  UINT8  cid;		/**< PDP context identifier.   */
} CiPsPrimRead4GPdpCtxDynParaReq;

#define CI_PS_PDP_MAX_NW_ADDR_NUM 4
//ICAT EXPORTED STRUCT
typedef struct CiPsPdpCtxDynPara_struct
{
  UINT8         cid;
  CiBoolean     bidPresent;
  UINT8         bid;  // if CID actived, bear ID must configured
  CiBoolean     apnPresent;
  CiString      apn; // 104 bytes
  CiPsPdpIpAddr ipv4Addr;
  CiPsPdpIpAddr ipv6Addr;
  UINT8         gwAddrNum;
  UINT8         dnsAddrNum;
  UINT8         pCscfAddrNum;
  UINT8         reserved0;
  CiPsPdpIpAddr gwAddr[CI_PS_PDP_MAX_NW_ADDR_NUM];
  CiPsPdpIpAddr dnsAddr[CI_PS_PDP_MAX_NW_ADDR_NUM];
  CiPsPdpIpAddr pCscfAddr[CI_PS_PDP_MAX_NW_ADDR_NUM];  
  UINT8         imCnSigFlag;  //0, 1
  UINT8         lipaInd;      //0, 1

  CiPsSmFollowAct  smFlwAct;
  CiBoolean        smCausePresent; // ESM CAUSE from NW
  CiPsEsmCauseType smCause;        // ESM CAUSE from NW

  CiBoolean        ipv4MtuPresent;
  UINT16           ipv4Mtu;

//#if defined(DS3_CAT1)  
  CiBoolean 	   wlanOffloadPresent;
  UINT8 		   wlanOffload;		      /**WLAN_Offload : 0~3 not supported*/
  CiBoolean 	   localAddrIndPresent;
  UINT8 		   localAddrInd;		  /**Local_Addr_ind:0~1*/
  CiBoolean 	   nonIpMtuPresent;
  UINT16 		   nonIpMtu;	          /**Non-IP_MTU*/
  CiBoolean 	   servingPlmnRateControlPresent;
  UINT16 		   servingPlmnRateControlValue;       /**Serving_PLMN_rate_control_value*/
//#endif  
}CiPsPdpCtxDynPara;

/******************************************************************************
 * <INUSE> 
 ** <paramref name="CI_PS_PRIM_READ_4G_PDP_CTX_DYN_PARA_CNF">   
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GPdpCtxDynParaCnf_struct
{

  CiPsRc        rc;     // UINT16
  CiBoolean     ctxPresent;
  CiPsPdpCtxDynPara ctxDynPara;
} CiPsPrimRead4GPdpCtxDynParaCnf; // 438 bytes



/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTX_CAPS_REQ">   */
typedef CiEmptyPrim CiPsPrimGetPdpCtxCapsReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTX_CAPS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpCtxCapsCnf_struct
{
  CiPsRc                 		rc;					/**< Result code \sa CiPsRc */
  CiPsPdpCtxCaps         	pdpCtxCaps;			/**< PDP context capabilities supported by the cellular subsystem \sa CiPsPdpCtxCaps_struct */
} CiPsPrimGetPdpCtxCapsCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPdpCtxActStateReq_struct
{
  CiBoolean  	state;		/**< State of the PS attachment. TRUE: activate; FALSE: deactivate. \sa CCI API Ref Manual */
  CiBoolean  	doAll;		/**< Not supported*/
  UINT8      	cid;			/**< PDP context identifier */
  CiPsL2P    	l2p;			/**< L2 protocol type \sa CiPsL2P */
} CiPsPrimSetPdpCtxActStateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PDP_CTX_ACT_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPdpCtxActStateCnf_struct
{
    CiPsRc rc;	      /**< Result code \sa CiPsRc */

    CiBoolean         smCausePresent; // if activated PDP, SM caused from NW, if deactivate PDP, this flag not valid
    CiPsEsmCauseType  smCause;        // ESM CAUSE from NW
    CiPsSmFollowAct   smFlwAct;       // SM following action, if deactivate a PDP, not valid
}CiPsPrimSetPdpCtxActStateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_REQ">   */
typedef CiEmptyPrim CiPsPrimGetPdpCtxsActStateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpCtxsActStateCnf_struct
{
  CiPsRc 				rc;											/**< Result code \sa CiPsRc */
  UINT8  					num;									/**< Number of defined PDP contexts [0-CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPsPdpCtxActState        lst[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];	/**< Activation state for the defined PDP contexts \sa CiPsPdpCtxActState_struct */
} CiPsPrimGetPdpCtxsActStateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_PDP_CTXS_ACT_DYN_PARA_REQ">   */
typedef CiEmptyPrim CiPsPrimRead4GPdpCtxsActDynParaReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CTXS_ACT_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GPdpCtxsActDynParaCnf_struct
{
  CiPsRc    rc;/**< Result code. \sa CiPsRc */
  UINT8     num;/**< Number of defined PDP contexts [0-CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  UINT8     cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM]; /**< PDP context information, optional if rc is not CIRC_PS_SUCCESS. \sa CiPsPdpCtxInfo_struct */
} CiPsPrimRead4GPdpCtxsActDynParaCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENTER_DATA_STATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnterDataStateReq_struct
{
  UINT8     		cid;				/**< PDP context identifier */
  CiPsL2P   		l2p;				/**< L2 protocol type \sa CiPsL2P */
  CiBoolean 		optimizedData;      /**< TRUE indicates that optimized ACI data plane is used   \sa CCI API Ref Manual */
} CiPsPrimEnterDataStateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENTER_DATA_STATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnterDataStateCnf_struct
{
    CiPsRc rc;		/**< Result code \sa CiPsRc */
    CiBoolean         smCausePresent; // ESM CAUSE from NW
    CiPsEsmCauseType  smCause;        // ESM CAUSE from NW
    CiPsSmFollowAct   smFlwAct;        // SM following action
}CiPsPrimEnterDataStateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimMtPdpCtxActModifyInd_struct
{
  CiPsPdpCtx  		pdpCtx;				/**< PDP context information \sa CiPsPdpCtx_struct */
  CiPsActionType   	actionType;			/**< Action requested on PDP context - activation or modification \sa CiPsActionType  */

  CiPsPdpModifyChangeReason	change_reason;

} CiPsPrimMtPdpCtxActModifyInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_MT_PDP_CTX_ACT_MODIFY_RSP">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimMtPdpCtxActModifyRsp_struct{
   CiPsRc    		rc;			/**< Result code \sa CiPsRc */
   UINT8     		cid;		/**< PDP context identifier */
   CiBoolean 		accept;		/**< TRUE: accept; FALSE: reject \sa CCI API Ref Manual */
   CiPsL2P   		l2p;		/**< L2 protocol type \sa CiPsL2P */
} CiPsPrimMtPdpCtxActModifyRsp;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_MT_PDP_CTX_ACTED_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimMtPdpCtxActedInd_struct
{
    CiPsPdpCtx         pdpCtx;        /**< PDP context information  \sa CiPsPdpCtx_struct */
    CiBoolean          isMEInitiated; /** MO/MT; ME/NW */
    CiPsMoPdpActReason pdpReason;     /** for CGEV*/
    UINT8              cid_other;     // only valided when pdpReason = "CI_PS_PDP_SINGLE_ONLY_ALLOWED_SEC_SUCC"
}CiPsPrimMtPdpCtxActedInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_GSMGPRS_CLASS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetGsmGprsClassReq_struct
{
  CiPsGsmGprsClass 	classType;		/**< Mobile class for GSM/GPRS \sa CiPsGsmGprsClass */
} CiPsPrimSetGsmGprsClassReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_GSMGPRS_CLASS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetGsmGprsClassCnf_struct
{
  CiPsRc rc;		/**< Result code \sa CiPsRc */
} CiPsPrimSetGsmGprsClassCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_GSMGPRS_CLASS_REQ">   */
typedef CiEmptyPrim CiPsPrimGetGsmGprsClassReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_GSMGPRS_CLASS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetGsmGprsClassCnf_struct
{
  CiPsRc            		 	rc;			/**< Result code \sa CiPsRc */
  CiPsGsmGprsClass   		classType;	/**< Mobile class for GSM/GPRS  \sa CiPsGsmGprsClass */
} CiPsPrimGetGsmGprsClassCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_GSMGPRS_CLASSES_REQ">   */
typedef CiEmptyPrim CiPsPrimGetGsmGprsClassesReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_GSMGPRS_CLASSES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetGsmGprsClassesCnf_struct
{
  CiPsRc         		rc;			/**< Result code \sa CiPsRc  */
  CiBitRange     		classes;		/**< Mobile class for GSM/GPRS  \sa CCI API Ref Manual */
} CiPsPrimGetGsmGprsClassesCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_NW_REG_IND_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnableNwRegIndReq_struct
{
  CiPsNwRegIndFlag 	flag;		/**< Configures network registration status reports \sa CiPsNwRegIndFlag */
} CiPsPrimEnableNwRegIndReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_NW_REG_IND_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnableNwRegIndCnf_struct
{
  CiPsRc 			rc;			/**< Result code \sa CiPsRc */
} CiPsPrimEnableNwRegIndCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_NW_REG_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimNwRegInd_struct
{
  CiPsNwRegInfo 		nwRegInfo;		/**< Network registration information \sa CiPsNwRegInfo_struct */
} CiPsPrimNwRegInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_4G_NW_REG_IND_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnable4GNwRegIndReq_struct
{
  CiPs4GNwRegIndFlag 	flag;		/**< Configures nework registration status reports.\sa CiPsNwRegIndFlag */
} CiPsPrimEnable4GNwRegIndReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_4G_NW_REG_IND_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnable4GNwRegIndCnf_struct
{
  CiPsRc 			rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimEnable4GNwRegIndCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_4G_NW_REG_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrim4GNwRegInd_struct
{
  CiPs4GNwRegInfo 		nwRegInfo;		/**< Network registration information \sa CiPsPrim4GNwRegInd_struct */
} CiPsPrim4GNwRegInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetQosReq_struct
{
  CiBoolean         		isMin;		/**< Indicates if the profile requested is minimum or required QoS profile  \sa CCI API Ref Manual */
  UINT8             		cid;		/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPsQosProfile  		qosProf;		/**< QoS profile data \sa CiPsQosProfile_struct */
} CiPsPrimSetQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetQosCnf_struct
{
  CiPsRc				rc;			/**< Result code \sa CiPsRc */
} CiPsPrimSetQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDelQosReq_struct
{
  CiBoolean  		isMin;			/**< Indicates if the profile requested is minimum or required QoS profile  \sa CCI API Ref Manual */
  UINT8      		cid;				/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimDelQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDelQosCnf_struct
{
  CiPsRc 		rc;				/**< Result code \sa CiPsRc */
} CiPsPrimDelQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetQosReq_struct
{
  CiBoolean 		isMin;			/**< Indicates if the profile requested is minimum or required QoS profile  \sa CCI API Ref Manual */
  UINT8     		cid;				/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGetQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetQosCnf_struct
{
  CiPsRc          		rc;					/**< Result code \sa CiPsRc */
  CiBoolean 			qosProfPresent;		/**< Not in use \sa CCI API Ref Manual */
  CiPsQosProfile  		qosProf;				/**< QoS profile, optional if rc is not CIRC_PS_SUCCESS \sa CiPsQosProfile_struct */
} CiPsPrimGetQosCnf;

/*Michal Bukai - AutoAttach Configuration - Samsung - START*/
/*********************************************************/
/** <paramref name="CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnablePoweronAutoAttachReq_struct
{
  CiBoolean       enableAutoAttach;               /**< AutoAttach configuration. TRUE: Attach to PS domain will be automatically initiated on power up
                                                                                         * FALSE: Attach to PS domain will be initiated by the user. \sa CCI API Ref Manual */
} CiPsPrimEnablePoweronAutoAttachReq;

/** <paramref name="CI_PS_PRIM_ENABLE_POWERON_AUTO_ATTACH_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnablePoweronAutoAttachCnf_struct
{
  CiPsRc rc;    /**< Result code. \sa CiPsRc. */
} CiPsPrimEnablePoweronAutoAttachCnf;

/** <paramref name="CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_REQ"> */
typedef CiEmptyPrim CiPsPrimGetPoweronAutoAttachStatusReq;

/** <paramref name="CI_PS_PRIM_GET_POWERON_AUTO_ATTACH_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPoweronAutoAttachStatusCnf_struct
{
  CiPsRc rc;     /**< Result code. \sa CiPsRc. */
  CiBoolean       AutoAttachStatus;               /**< AutoAttach configuration. TRUE: Attach to PS domain will be automatically initiated on power up
                                                                                         * FALSE: Attach to PS domain will be initiated by the user. \sa CCI API Ref Manual */
} CiPsPrimGetPoweronAutoAttachStatusCnf;
/*Michal Bukai - AutoAttach Configuration - Samsung - END*/

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimMtPdpCtxRejectedInd_struct
{
  UINT8                  cause;
  CiPsIndicatedPdpCtx  indedPdpCtx;
} CiPsPrimMtPdpCtxRejectedInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_PDP_CTX_DEACTED_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimPdpCtxDeactedInd_struct
{
  UINT8                  cause;					/**< Cause for PDP context deactivation. SM cause is defined in 3GPP TS 24.008 section 10.5.6.6. */
  CiBoolean              isMEInitiated;				/**< TRUE if ME requested PDP context deactivation or PPP connection failure detected in comm . \sa CCI API Ref Manual */
  UINT8                  res1U8[2];     			/**< (padding) */
  CiPsIndicatedPdpCtx    indedPdpCtx;				/**< Indicated PDP context \sa CiPsPdpCtxInd_struct */
} CiPsPrimPdpCtxDeactedInd;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimPdpCtxReactedInd_struct
{
  CiPsIndicatedPdpCtx    indedPdpCtx;
} CiPsPrimPdpCtxReactedInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DETACHED_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDetachedInd_struct
{
  CiBoolean  		isMeDetach;		/**< Indicates if detach is initiated by ME or network. TRUE indicates by ME; FALSE indicates by network. \sa CCI API Ref Manual */
} CiPsPrimDetachedInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GPRS_CLASS_CHANGED_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGprsClassChangedInd_struct
{
  CiPsGsmGprsClass classType;		/**< Mobile class for GSM/GPRS \sa CiPsGsmGprsClass */
  CiBoolean IsMEClassChanged;       /**< TRUE if network mode changed. \sa CCI API Ref Manual */
} CiPsPrimGprsClassChangedInd;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_DEFINED_CID_LIST_REQ">   */
typedef CiEmptyPrim CiPsPrimGetDefinedCidListReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_DEFINED_CID_LIST_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefinedCidListCnf_struct
{
  CiPsRc 	rc;					/**< Result code \sa CiPsRc */
  UINT8  		size;			/**< Size of the CID list [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM] */
  UINT8  		cidLst[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];	/**< CID list */
} CiPsPrimGetDefinedCidListCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_NW_REG_STATUS_REQ">   */
typedef CiEmptyPrim CiPsPrimGetNwRegStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_NW_REG_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetNwRegStatusCnf_struct
{
    CiPsRc           rc;	       /**< Result code \sa CiPsRc */
    CiPsNwRegIndFlag regIndflag;   /** report level, n = 0,1,2,3**/
    CiPsNwRegInfo    nwRegInfo;    /**< Network registration information  \sa CiPsNwRegInfo_struct */
}CiPsPrimGetNwRegStatusCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_NW_REG_STATUS_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GNwRegStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_NW_REG_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GNwRegStatusCnf_struct
{
    CiPsRc         	   rc;	         /**< Result code. \sa CiPsRc */
    CiPs4GNwRegIndFlag regIndflag;   /** report level, n = 0,1,2,3**/
    CiPs4GNwRegInfo    nwRegInfo;    /**< Network registration information. \sa CiPs4GNwRegInfo_struct */
}CiPsPrimGet4GNwRegStatusCnf;

/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_QOS_CAPS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetQosCapsReq_struct
{
  CiBoolean  		isMin;		/**< Not in use  */
} CiPsPrimGetQosCapsReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_QOS_CAPS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetQosCapsCnf_struct
{
  CiPsRc       		rc;				/**< Result code \sa CiPsRc */
  CiBoolean 		qosCapsPresent;	/**< TRUE: if present  */
  CiPsQosCaps 	qosCaps;		/**< QoS capabilities, optional if rc is not CIRC_PS_SUCCESS \sa CiPsQosCaps_struct */

} CiPsPrimGetQosCapsCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_EVENTS_REPORTING_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnableEventsReportingReq_struct
{
  CiBoolean  enable;		/**< TRUE: enable events reporting; FALSE: disable events reporting; default: FALSE  \sa CCI API Ref Manual */
} CiPsPrimEnableEventsReportingReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_ENABLE_EVENTS_REPORTING_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEnableEventsReportingCnf_struct
{
  CiPsRc rc;		/**< Result code \sa CiPsRc */
} CiPsPrimEnableEventsReportingCnf;

// --------------- SCR #1401348: BEGIN ------------------------------------

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_3G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet3GQosReq_struct
{
  CiPs3GQosType 		qosType;   	/**< Specifies 3G minimum, required or negotiated QoS profile \sa CiPs3GQosType */  // REQ/MIN/NEG
  UINT8         			cid;			/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGet3GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_3G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet3GQosCnf_struct
{
  CiPsRc            		rc;							/**< Result code \sa CiPsRc */
  CiBoolean 			qosProfPresent;				/**< If TRUE, qosProf contains the 3G QoS profile; if FALSE, qosProf does not contain useful information  \sa CCI API Ref Manual */
  CiPs3GQosProfile  	qosProf;					/**< 3G QoS profile, optional if rc is not CIRC_PS_SUCCESS \sa CiPs3GQosProfile_struct  */
} CiPsPrimGet3GQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_3G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet3GQosReq_struct
{
  CiPs3GQosType     	qosType;  						/**< Specifies 3G minimum or required QoS profile \sa CiPs3GQosType */  // REQ/MIN (NEG is not valid here)
  UINT8             		cid;						/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPs3GQosProfile  	qosProf;						/**< 3G QoS profile \sa CiPs3GQosProfile_struct */
} CiPsPrimSet3GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_3G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet3GQosCnf_struct
{
  CiPsRc rc;			/**< Result code \sa CiPsRc */
} CiPsPrimSet3GQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_3G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDel3GQosReq_struct
{
  CiPs3GQosType 		qosType;    	/**< Specifies 3G minimum or required QoS profile \sa CiPs3GQosType */  // REQ/MIN (NEG is not valid here)
  UINT8         			cid;		/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimDel3GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_3G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDel3GQosCnf_struct
{
  CiPsRc rc;			/**< Result code \sa CiPsRc */
} CiPsPrimDel3GQosCnf;


/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_3G_QOS_CAPS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet3GQosCapsReq_struct
{
  CiPs3GQosType qosType;    /**< Not in use */ // REQ/MIN/NEG
} CiPsPrimGet3GQosCapsReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_3G_QOS_CAPS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet3GQosCapsCnf_struct
{
  CiPsRc          		rc;						/**< Result code \sa CiPsRc */
  CiBoolean 			qosCapsPresent;			/**< If TRUE, qosCaps contains the 3G QoS capabilities; if FALSE, qosCaps does not contain useful information. \sa CCI API Ref Manual*/
  CiPs3GQosCaps   	qosCaps;				/**< 3G QoS capabilities; optional if rc is not CIRC_PS_SUCCESS \sa CiPs3GQosCaps_struct */
} CiPsPrimGet3GQosCapsCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GQosReq_struct
{
  UINT8         			cid;			/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGet4GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GQosCnf_struct
{
  CiPsRc                rc;							/**< Result code. \sa CiPsRc */
  UINT8                 cid;                        /**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiBoolean 		    qosProfPresent;				/**< If TRUE, qosProf will have the 3G QoS profile; If FALSE, qosProf doesn't contain useful information;  \sa CCI API Ref Manual */
  CiPs4GQosProfile      qosProfile;					/**< 4G QoS profile, optional if rc is not CIRC_PS_SUCCESS; \sa CiPs3GQosProfile_struct  */
} CiPsPrimGet4GQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_4G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GQosReq_struct
{
  UINT8					  cid;								  /**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPs4GQosProfile  	  qosProfile;					/**< 4G QoS profile, optional if rc is not CIRC_PS_SUCCESS; \sa CiPs3GQosProfile_struct  */
} CiPsPrimSet4GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_4G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GQosCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimSet4GQosCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_4G_QOS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDel4GQosReq_struct
{
  UINT8         			cid;			/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimDel4GQosReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEL_4G_QOS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDel4GQosCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimDel4GQosCnf;

/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_QOS_CAPS_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GQosCapsReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_QOS_CAPS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GQosCapsCnf_struct
{
  CiPsRc          		rc;						/**< Result code. \sa CiPsRc */
  CiBoolean 			qosCapsPresent;			/**< If TRUE, qosCaps will have the 3G QoS capabilities; If FALSE, qosCaps doesn't contain useful information; \sa CCI API Ref Manual*/
  CiPs4GQosCaps  	    qosCaps;					/**< 4G QoS profile, optional if rc is not CIRC_PS_SUCCESS; \sa CiPs3GQosProfile_struct  */
} CiPsPrimGet4GQosCapsCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_MODE_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GModeReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_MODE_CNF">   */
//ICAT EXPORTED STRUCT

typedef struct CiPsPrimGet4GModeCnf_struct
{
  CiPsRc        rc; /**< Result code. \sa CiPsRc */
  UINT8         cipslteOperateMode;  
} CiPsPrimGet4GModeCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_4G_MODE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GModeReq_struct
{
  UINT8         cipslteOperateMode;
} CiPsPrimSet4GModeReq;
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_4G_MODE_CNF">   */
//ICAT EXPORTED STRUCT

typedef struct CiPsPrimSet4GModeCnf_struct
{
  CiPsRc        rc; /**< Result code. \sa CiPsRc */ 
} CiPsPrimSet4GModeCnf;

/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_MODE_CAPS_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GModeCapsReq;

 //ICAT EXPORTED STRUCT
typedef struct CiPsLteOperateModes_struct
{
  UINT8        ciPsLteOperateMode[4]; /** 4G QoS capability per defined PDP context. \sa CiPs4GQosCap_struct */
} CiPsLteOperateModes;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_QOS_CAPS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GModeCapsCnf_struct
{
  CiPsLteOperateModes    ciPsLteOperateModes;
} CiPsPrimGet4GModeCapsCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_ADDR_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpAddrReq_struct
{
  UINT8         num;
  UINT8         cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGetPdpAddrReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_ADDR_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpAddrCnf_struct
{
  CiPsRc        rc;
  UINT8         num;
  UINT8         cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  CiPsPdpAddr   pdpAddress[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
} CiPsPrimGetPdpAddrCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_ADDR_LIST_REQ">   */
typedef CiEmptyPrim CiPsPrimGetPdpAddrListReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_ADDR_LIST_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpAddrListCnf_struct
{
  CiPsRc        rc;
  UINT8         nums;
  UINT8         cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGetPdpAddrListCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_SEC_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineSecPdpCtxReq_struct
{
  CiPsSecPdpCtx  		secPdpCtx;		/**< Secondary PDP context \sa CiPsSecPdpCtx_struct */
} CiPsPrimDefineSecPdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_SEC_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineSecPdpCtxCnf_struct
{
  CiPsRc rc;		/**< Result code \sa CiPsRc */
} CiPsPrimDefineSecPdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_SEC_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeleteSecPdpCtxReq_struct
{
  UINT8 cid;			/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimDeleteSecPdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_SEC_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeleteSecPdpCtxCnf_struct
{
  CiPsRc rc;			/**< Result code \sa CiPsRc */
} CiPsPrimDeleteSecPdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_SEC_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetSecPdpCtxReq_struct
{
  UINT8 cid;			/**< Secondary PDP context ID [[0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1]] */
} CiPsPrimGetSecPdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_SEC_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetSecPdpCtxCnf_struct
{
  CiPsRc             		rc;							/**< Result code \sa CiPsRc */
  CiBoolean 			ctxPresent;					/**< Set to FALSE, if the result code parameter indicates an error  \sa CCI API Ref Manual */
  CiPsSecPdpCtxInfo  	ctx;							/**< Secondary PDP context information  \sa CiPsSecPdpCtxInfo_struct */
} CiPsPrimGetSecPdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GSecPdpCtxDynParaReq_struct
{
  UINT8 cid;			/**< Secondary PDP context ID [[0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1]] */
} CiPsPrimRead4GSecPdpCtxDynParaReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_SEC_PDP_CTX_DYN_PARA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GSecPdpCtxDynParaCnf_struct
{
  CiPsRc    rc;         /**< Result code. \sa CiPsRc */
  UINT8     num;
  CiPsID    psId[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
  CiPsImCnSignallingFlagIndType imCnSigFlag[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
} CiPsPrimRead4GSecPdpCtxDynParaCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_REQ">   */
typedef CiEmptyPrim CiPsPrimRead4GSecPdpCtxsActDynParaReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_4G_SEC_PDP_CTXS_ACT_DYN_PARA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GSecPdpCtxsActDynParaCnf_struct
{
  CiPsRc    rc;  /**< Result code. \sa CiPsRc */
  UINT8     num;
  UINT8     cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];  /**< Secondary PDP Context Information. \sa CiPsSecPdpCtxInfo_struct */
} CiPsPrimRead4GSecPdpCtxsActDynParaCnf;


/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_TFT_FILTER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineTftFilterReq_struct
{
  UINT8           cid;						/**< Secondary PDP context ID [[0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1]] */
  CiPsTftFilter   filter;					/**< TFT filter parameters \sa CiPsTftFilter_struct */
} CiPsPrimDefineTftFilterReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DEFINE_TFT_FILTER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineTftFilterCnf_struct
{
  CiPsRc 	rc;		/**< Result code \sa CiPsRc */
} CiPsPrimDefineTftFilterCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_TFT_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeleteTftReq_struct
{
  UINT8 	cid;			/**< Context ID [[0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1]] */
} CiPsPrimDeleteTftReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_DELETE_TFT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDeleteTftCnf_struct
{
  CiPsRc 	rc;			/**< Result code \sa CiPsRc */
} CiPsPrimDeleteTftCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_TFT_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetTftReq_struct
{
  UINT8 	cid;			/**< Context ID [[0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1]] */
} CiPsPrimGetTftReq;

/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_TFT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetTftCnf_struct
{
  CiPsRc          	rc;									/**< Result code \sa CiPsRc */
  UINT8           	numFilters;        						/**< Number of packet filters */
  CiPsTftFilter   	filters[CI_PS_MAX_TFT_FILTERS];		/**< Not in use */
} CiPsPrimGetTftCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_MODIFY_PDP_CTX_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimModifyPdpCtxReq_struct
{
  CiBoolean  		doAll;    /**< Not supported */
  UINT8     		cid;      /**< PDP context identifier */
} CiPsPrimModifyPdpCtxReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_MODIFY_PDP_CTX_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimModifyPdpCtxCnf_struct
{
  CiPsRc rc;			/**< Result code \sa CiPsRc */
} CiPsPrimModifyPdpCtxCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_ACTIVE_CID_LIST_REQ">   */
// Get List of Active Context ID's -- like the "AT+CGCMOD=?" command
typedef CiEmptyPrim CiPsPrimGetActiveCidListReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_ACTIVE_CID_LIST_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetActiveCidListCnf_struct
{
  CiPsRc 	rc;				/**< Result code \sa CiPsRc */
  UINT8 		size;			/**< Size of the CID list [0..CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM] */
  UINT8  		cidLst[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];			/**< CID list */
} CiPsPrimGetActiveCidListCnf;

// --------------- SCR #1401348: END   ------------------------------------

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_REPORT_COUNTER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReportCounterReq_struct
{
  CiPsCounterReportType 		type;       		/**< Report type \sa CiPsCounterReportType */
  UINT16                		interval;   		/**< Report interval (seconds), minimum report interval is 1 second. Required for periodic report configuration. */
} CiPsPrimReportCounterReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_REPORT_COUNTER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReportCounterCnf_struct
{
  CiPsRc rc;				/**< Result code \sa CiPsRc */
} CiPsPrimReportCounterCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_RESET_COUNTER_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimResetCounterReq_struct
{
  /*-----------------6/7/2009 11:53AM-----------------
   * doAll parameter is a fix for SCR 1980451 -> 1818954 #9.
   * --------------------------------------------------*/
  CiBoolean  	doAll;          	/**< Indicates if all counters should be reset; TRUE: reset all counters; FALSE: reset the counter for a requested context ID \sa CCI API Ref Manual*/
  UINT8 		cid;            	/**< Context ID, required if doAll == FALSE */
} CiPsPrimResetCounterReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_RESET_COUNTER_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimResetCounterCnf_struct
{
  CiPsRc rc;			/**< Result code \sa CiPsRc */
} CiPsPrimResetCounterCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_COUNTER_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimCounterInd_struct
{
  UINT8  		cid;           		/**< PDP context ID, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
  UINT32 		totalULBytes;  	/**< Total bytes sent on uplink (uncompressed) */
  UINT32 		totalDLBytes;  	/**< Total bytes received on downlink (uncompressed) */
} CiPsPrimCounterInd;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSendDataReq_struct
{
  UINT16 pcktsize;      /* Packet size range: 0 - 10000, default 1472 */
  UINT16 pcktcount;      /* Number of packets to send: 1 - 20, default 1 */
  UINT8  nsapi;           /* PDP context ID */
  UINT8  PAD1;
  UINT8  PAD2;
  UINT8  PAD3;
} CiPsPrimSendDataReq;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSendDataCnf_struct
{
  CiPsRc rc;
} CiPsPrimSendDataCnf;

/* Michal Bukai & Boris Tsatkin  AT&T Smart Card support - Start*/
/*****************************************************************/
/*
  *** AT&T- Smart Card  CI_PS_PRIM_ ACL SERVICE: LIST , SET , EDIT   -BT6
 */
/** \brief SIM access result values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiAbgpRequestStatusTag
{
  CI_ABGP_APN_OK,                    /**< OK */
  CI_ABGP_APN_NRAM_ERROR,            /**< APN NRAM error */
  CI_ABGP_APN_RECORD_NOT_FOUND,      /**< APN record not found */
#if defined (UPGRADE_3G)
  CI_ABGP_APN_INVALID_PARAMS,        /**< Invalid parameters specified in the request*/
  CI_ABGP_APN_SIM_ERROR,             /**< SIM error*/
  CI_ABGP_APN_FILE_NOT_FOUND,        /**< File does not exist */
  CI_ABGP_APN_POWERING_DOWN,         /**< Powering down*/
  CI_ABGP_APN_ACCESS_DENIED,         /**< PIN/PIN2 has not been verified*/
  CI_ABGP_APN_MEMORY_PROBLEM,        /**< ACL file is out of memory and cannot store an additional APN */ /* <CDR-SMCD-1124>*/
  CI_ABGP_APN_NOT_ALLOWED,           /**< Operation not allowed*/
  CI_ABGP_APN_SERVICE_NOT_AVAILCI_ABLE,  /**< Service not available*/
#endif
  CI_ABGP_ALLIGN =0xFFFF

} _CiPsSimResult;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief SIM access result \sa CiAbgpRequestStatusTag
 * \remarks Common Data Section */
typedef UINT16 CiPsSimResult;
/**@}*/

/*AT&T- Smart Card  CI_PS_PRIM_SET_ACL_SERVICE_REQ   <CDR-SMCD-1100><1101> -BT6 */
/** <paramref name="CI_PS_PRIM_SET_ACL_SERVICE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetAclReq_struct{
    CiBoolean simAclPresent;
    CiBoolean simAclEnable;	/**< TRUE: enable ACL service; FALSE: disable ACL service \sa CCI API Ref Manual */
    CiBoolean psAclPresent;
    CiBoolean psAclEnable;
}CiPsPrimSetAclReq;

/*AT&T- Smart Card  CI_PS_PRIM_SET_ACL_SERVICE_CNF   -BT6 */
/** <paramref name="CI_PS_PRIM_SET_ACL_SERVICE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetAclCnf_struct{
    CiPsRc rc;	/**< Result code \sa CiPsRc */
    CiPsSimResult SimCause; /**< SIM result code \sa CiPsSimResult */
    CiBoolean simAclEnable;	/**< Service status; TRUE: enabled, FALSE: disabled \sa CCI API Ref Manual*/
    CiBoolean psAclEnable;
}CiPsPrimSetAclCnf;

/*AT&T- Smart Card  CI_PS_PRIM_GET_ACL_SIZE_REQ <CDR-SMCD-1110><1120>  -BT6 */
/** <paramref name="CI_PS_PRIM_GET_ACL_SIZE_REQ">   */

typedef CiEmptyPrim CiPsPrimGetAclSizeReq;

/*AT&T- Smart Card  CI_PS_PRIM_GET_ACL_SIZE_CNF   -BT6 */
/** <paramref name="CI_PS_PRIM_GET_ACL_SIZE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetAclSizeCnf_struct{
	CiPsRc rc;	             /**< Result code \sa CiPsRc */
	CiPsSimResult SimCause;	/**< SIM result code \sa CiPsSimResult */
	UINT8 totalNumApns;  	/**< Number of APNs currently held in SIM file EF_ACL */
 } CiPsPrimGetAclSizeCnf;


/*AT&T- Smart Card  CI_PS_PRIM_READ_ACL_ENTRY_REQ  <CDR-SMCD-1110><1120>  -BT6 */
/** <paramref name="CI_PS_PRIM_READ_ACL_ENTRY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReadAclEntryReq_struct{
	UINT8 Index;        /**< Index into ACL list */
} CiPsPrimReadAclEntryReq;

/*AT&T- Smart Card  CI_PS_PRIM_READ_ACL_ENTRY_CNF   -BT6 */
/** <paramref name="CI_PS_PRIM_READ_ACL_ENTRY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReadAclEntryReqCnf_struct{
	CiPsRc rc;				/**< Result code \sa CiPsRc */
	CiPsSimResult SimCause;	/**< SIM result code \sa CiPsSimResult */
	CiLongAdrInfo apn ;		/**< Requested APN in string format  \sa CCI API Ref Manual*/
 } CiPsPrimReadAclEntryCnf;

/*AT&T- Smart Card  CI_PS_PRIM_EDIT_ACL_ENTRY_REQ  <CDR-SMCD-1120><1123> -BT6 */
/** <paramref name="CI_PS_PRIM_EDIT_ACL_ENTRY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEditAclEntryReq_struct{
	CiEditCmdType EditCommand;     /**< Edit command (add, delete, or replace) \sa CCI API Ref Manual*/
	UINT8 position;     			/**< Index into ACL list */
	/*To add the "Network provided APN" to the APN Control List, the length of the APN should be set to 0*/
	CiLongAdrInfo apn; /**< APN in string format; required for add or replace commands \sa CCI API Ref Manual*/
} CiPsPrimEditAclEntryReq;

/*AT&T- Smart Card  CI_PS_PRIM_EDIT_ACL_ENTRY_CNF   -BT6 */
/** <paramref name="CI_PS_PRIM_EDIT_ACL_ENTRY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEditAclEntryCnf_struct{
	CiPsRc rc;               /**< Result code \sa CiPsRc */
	CiPsSimResult SimCause;  /**< SIM result code \sa CiPsSimResult */
	UINT8 position;          /**< Index in ACL list */
} CiPsPrimEditAclEntryCnf;

/* Michal Bukai & Boris Tsatkin  AT&T Smart Card support - End*/
/*****************************************************************/
/* Michal Bukai 每 PDP authentication - Start*/
/*****************************************************************/

//ICAT EXPORTED ENUM
typedef enum CIPSAUTHENTICATIONTYPE_TAG
{
  CI_PS_AUTHENTICATION_TYPE_NONE,	/**< No authentication protocol */
  CI_PS_AUTHENTICATION_TYPE_PAP,	/**< Password authentication protocol */
  CI_PS_AUTHENTICATION_TYPE_CHAP,	/**< Challenge-Handshake authentication protocol */
  CI_PS_AUTHENTICATION_TYPE_PAP_CHAP,   /**< PAP preferred, CHAP as secondary */ /*Lilei, CQ00115591, 20190724*/
  CI_PS_AUTHENTICATION_TYPE_CHAP_PAP,   /**< CHAP preferred, PAP as secondary */ /*Lilei, CQ00115591, 20191021*/
  CI_PS_AUTHENTICATION_TYPE_PPP_CHAP,   /**< Challenge-Handshake authentication protocol for PPP */ /*Lilei, CQ00111775, 20180814*/
  
  CI_PS_AUTHENTICATION_TYPE_NUM

} _CiPsAuthenticationType;

typedef UINT8 CiPsAuthenticationType;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_AUTHENTICATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimAuthenticateReq_struct
{
  UINT8 					cid;            	/**< PDP context identifier */
  CiPsAuthenticationType	AuthenticationType; /**< Authentication type. \sa CiPsAuthenticationType */
/* !!!!!!!!!!!!!!!!!!!
 * When RIL completes the transition to contiguous memory, all CCI_xx_CONTIGUOUS
 * & CCI_APP_NONCONTIGUOUS flags must be removed.
 * ONLY the code BETWEEN the following 2 comment lines will REMAIN:
 * # Start Contiguous Code Section # and # End Contiguous Code Section #
 * All other code OUTSIDE these comments must be REMOVED - ( The backwards compatible code )
*/
/* # Start Contiguous Code Section # */
  CiStringExt  				UserName; 		/**< UserName octets. \sa CCI API Ref Manual */
  CiStringExt 				Password;     	/**< Password octets. \sa CCI API Ref Manual */
/* # End Contiguous Code Section # */

} CiPsPrimAuthenticateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_AUTHENTICATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimAuthenticateCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimAuthenticateCnf;

/*add by xwzhou for CQ56098 on 03052014, begin*/

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetDefaultPdpAuthenticateReq_struct
{
  UINT8                     modeType; // 0 - not save to NVM, 1 - save to NUM;
  CiPsAuthenticationType	authenticationType; /**< Authentication type. \sa CiPsAuthenticationType */ 
  CiBoolean                   authInfoPresent;
  CiStringExt 				userName; 		/**< UserName octets. \sa CCI API Ref Manual */
  CiStringExt 				password;     	/**< Password octets. \sa CCI API Ref Manual */
} CiPsPrimSetDefaultPdpAuthenticateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_DEFAULT_PDP_AUTHENTICATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetDefaultPdpAuthenticateCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimSetDefaultPdpAuthenticateCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefaultPdpAuthenticateReq_Tag
{
    UINT8 modeType; // 0 - current used, 1 - from NVM
}CiPsPrimGetDefaultPdpAuthenticateReq;
//typedef CiEmptyPrim CiPsPrimGetDefaultPdpAuthenticateReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_DEFAULT_PDP_AUTHENTICATE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefaultPdpAuthenticateCnf_struct
{
  CiPsRc rc;            /**< Result code. \sa CiPsRc */
  CiPsAuthenticationType	authenticationType; /**< Authentication type. \sa CiPsAuthenticationType */
  CiStringExt  				userName; 		/**< UserName octets. \sa CCI API Ref Manual */
  CiStringExt 				password;     	/**< Password octets. \sa CCI API Ref Manual */
} CiPsPrimGetDefaultPdpAuthenticateCnf;

/*add by xwzhou for CQ56098 on 03052014, end*/

/* Michal Bukai 每 PDP authentication - End*/
/*****************************************************************/

/* Michal Bukai 每 Fast Dormancy - Start*/
/*****************************************************************/

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_FAST_DORMANT_REQ">   */
typedef CiEmptyPrim CiPsPrimFastDormantReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_FAST_DORMANT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimFastDormantCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimFastDormantCnf;

/* Michal Bukai 每 Fast Dormancy - End*/
/*****************************************************************/

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_CURRENT_JOB_REQ">   */
typedef CiEmptyPrim CiPsPrimGetCurrentJobReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_CURRENT_JOB_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetCurrentJobCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
  CiPrimitiveID primId; /**< Primitive ID. \sa CiPrimitiveID */
} CiPsPrimGetCurrentJobCnf;

/* <INUSE> */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_FDY_OPTION{
    CIPS_FDY_DISABLE = 0,   /**< Disable PS power consuming control */
    CIPS_FDY_ENABLE,        /**< Enable PS power consuming control */

    /* This one must always be last in the list! */
    CIPS_NUM_FDY_OPTIONS    /**< Number of options defined */
} _CiPsFDYOpt;

typedef UINT8 CiPsFDYOpt;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_REQ">   */
typedef struct CiPsPrimSetFastDormancyConfigReq_struct
{
    /* add by xwzhou for CQ55965 on 03032014, begin */
    //CiPsFDYOpt  type;     /**< Type. \sa CiPsFDYOpt */
    //UINT16      interval; /**< Trigger Interval (seconds), the default value is 3*/
    INT16     mode;    /**< 0: disable fast dormancy timer; 1: enable fast dormancy timer*/
    UINT32    lcdOnTimerMsLength;       /**< (unit:ms),if timer length=0,disable FD*/
    UINT32    lcdOffTimerMsLength;      /**< (unit:ms),if timer length=0,disable FD*/
    UINT32    rel8LcdOnTimerMsLength;   /**< (unit:ms),if timer length=0,disable FD*/
    UINT32    rel8LcdOffTimerMsLength;  /**< (unit:ms),if timer length=0,disable FD*/
    /* add by xwzhou for CQ55965 on 03032014, end */
} CiPsPrimSetFastDormancyConfigReq;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_PS_PRIM_SET_FAST_DORMANCY_CONFIG_CNF">   */
typedef struct CiPsPrimSetFastDormancyConfigCnf_struct
{
    CiPsRc rc;     /**< Result code. \sa  CiPsRc */
} CiPsPrimSetFastDormancyConfigCnf;

typedef enum CiPsPdpTriggerType_Tag
{
    CI_PS_INVALID_PDP_TRIGGER_TYPE,
    CI_PS_23G_MO_PDP_TYPE,
    CI_PS_4G_MO_PDP_TYPE,
    CI_PS_4G_DEFAULT_PDP_TYPE,

    CI_PS_23G_MT_PDP_TYPE,  // 2/3G NW initiate PDP
    CI_PS_4G_MT_PDP_TYPE,   // 4G NW initiate PDP
    
    CI_PS_TRIGGER_TYPE_NUM
}_CiPsPdpTriggerType;

typedef UINT8 CiPsPdpTriggerType;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_PS_PRIM_PDP_ACTIVATION_REJECT_CAUSE_IND">   */
typedef struct CiPsPrimPdpActivationRejectCauseInd_struct
{
    CiPsPdpTriggerType pdpType; 
    CiBoolean          cidPresent;
    UINT8              cid;
    CiBoolean          smCausePresent;
    CiPsEsmCauseType   smCause;
    CiPsSmFollowAct    smflwAction;
}CiPsPrimPdpActivationRejectCauseInd;



/* CI_PS_PRIM_READ_4G_QOS_DYN_PARA_REQ    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GQosDynParaReq_struct{
	UINT8		  cid;				  /**< PDP Context ID, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimRead4GQosDynParaReq;

/* CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GQosDynParaCnf_struct{
	CiPsRc       rc;
    UINT8        num;
	CiPs4GQosProfile	  qosProfile[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];  /**< 4G QoS profile, optional if rc is not CIRC_PS_SUCCESS; \sa CiPs3GQosProfile_struct  */
    UINT8                 cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context  ID list, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimRead4GQosDynParaCnf;

/* CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CAPS_REQ    */
typedef CiEmptyPrim CiPsPrimRead4GQosDynParaCapsReq;

/* CI_PS_PRIM_READ_4G_QOS_DYN_PARA_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GQosDynParaCapsCnf_struct{
    CiPsRc           rc;  /**< Result code. \sa CiPsRc */
    UINT8            num;
    UINT8            cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context  ID list, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimRead4GQosDynParaCapsCnf;

/* CI_PS_PRIM_GET_4G_EVET_REP_REQ    */
typedef CiEmptyPrim CiPsPrimGet4GEventRepReq;

/* CI_PS_PRIM_GET_4G_EVET_REP_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GEventRepCnf_struct{
    CiPsRc        rc;
    UINT16        mode;               /**<
                                                                    *0 buffer unsolicited result codes in the MT; if MT result code buffer is full, the oldest ones can be discarded. No codes are forwarded to the TE.
                                                                    *1 discard unsolicited result codes when MT TE link is reserved (e.g. in on line data mode); otherwise forward them directly to the TE
                                                                    *2 buffer unsolicited result codes in the MT when MT TE link is reserved (e.g. in on line data mode) and flush them to the TE when MT TE link becomes available; otherwise forward them directly to the TE
                                                                    */
    UINT16        bfr;                /**<
                                                                    *0   MT buffer of unsolicited result codes defined within this command is cleared when <mode> 1 or 2 is entered
                                                                    *1   MT buffer of unsolicited result codes defined within this command is flushed to the TE when <mode> 1 or 2 is entered (OK response shall be given before flushing the codes)
                                                                    */
} CiPsPrimGet4GEventRepCnf;


/* CI_PS_PRIM_SET_4G_EVET_REP_REQ    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GEventRepReq_struct{
    UINT16    mode;   /**<
                                        *0 buffer unsolicited result codes in the MT; if MT result code buffer is full, the oldest ones can be discarded. No codes are forwarded to the TE.
                                        *1 discard unsolicited result codes when MT TE link is reserved (e.g. in on line data mode); otherwise forward them directly to the TE
                                        *2 buffer unsolicited result codes in the MT when MT TE link is reserved (e.g. in on line data mode) and flush them to the TE when MT TE link becomes available; otherwise forward them directly to the TE
                                        */
    UINT16    bfr;    /**<
                                        *0   MT buffer of unsolicited result codes defined within this command is cleared when <mode> 1 or 2 is entered
                                        *1   MT buffer of unsolicited result codes defined within this command is flushed to the TE when <mode> 1 or 2 is entered (OK response shall be given before flushing the codes)
                                        */        
} CiPsPrimSet4GEventRepReq;

/* CI_PS_PRIM_SET_4G_EVET_REP_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GEventRepCnf_struct{
    CiPsRc    rc;
                                    
} CiPsPrimSet4GEventRepCnf;




/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_MODE_CAPS_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GEventRepCapsReq;

//ICAT EXPORTED STRUCT
typedef struct SacPsEventReportCaps_struct
{
    SacPsEventReportMode   mode_min;
    SacPsEventReportMode    mode_max;
    SacPsEventReportBufferMode buffer_min;
    SacPsEventReportBufferMode buffer_max;
}
SacPsEventReportCaps;

/* CI_PS_PRIM_GET_4G_EVET_REP_CAPS_CNF    */

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GEventRepCapsCnf_struct{
    CiPsRc      rc;
    SacPsEventReportCaps   reportCaps;
} CiPsPrimGet4GEventRepCapsCnf;

/** \brief  UE＊s Voice Call Mode */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_VOICE_CALL_MODE_TAG
{
	CIPS_CS_ONLY = 0,
	CIPS_VOIP_ONLY,
	CIPS_CS_PREFERRED,
	CIPS_VOIP_PREFERRED,
	CIPS_VOICE_CALL_MODE_NUM
} _CiPsVoiceCallMode;


/* CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_REQ    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GVoiceCallModeReq_struct{
	UINT8		  cid;				  /**< PDP Context ID, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimGet4GVoiceCallModeReq;

/* CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GVoiceCallModeCnf_struct{
	CiPsRc        rc; 	
	UINT16		  mode;				  /* 0     CS_ONLY
	                                   * 1     VOIP_ONLY
	                                   * 2     CS_PREFERRED
	                                   * 3     VOIP_PREFERRED
	                                   */
} CiPsPrimGet4GVoiceCallModeCnf;


/* CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_REQ    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GVoiceCallModeReq_struct{
	UINT8		  cid;				  /**< PDP Context ID, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
	UINT16		  mode;				  /* 0     CS_ONLY
	                                   * 1     VOIP_ONLY
	                                   * 2     CS_PREFERRED
	                                   * 3     VOIP_PREFERRED
	                                   */
} CiPsPrimSet4GVoiceCallModeReq;

/* CI_PS_PRIM_SET_4G_VOICE_CALL_MODE_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSet4GVoiceCallModeCnf_struct{
	CiPsRc        rc; 	
} CiPsPrimSet4GVoiceCallModeCnf;




/* <NOTINUSE> */
/** <paramref name="CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_REQ">   */
typedef CiEmptyPrim CiPsPrimGet4GVoiceCallModeCapsReq;

/* CI_PS_PRIM_GET_4G_VOICE_CALL_MODE_CAPS_CNF    */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGet4GVoiceCallModeCapsCnf_struct{
	CiPsRc        rc; 	
	UINT16		  modebitmap;		   /*bit 0     CS_ONLY, will set 1
	                                    *bit 1     VOIP_ONLY
	                                    *bit 2     CS_PREFERRED
	                                    *bit 3     VOIP_PREFERRED
	                                    */
} CiPsPrimGet4GVoiceCallModeCapsCnf;


/* CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_REQ	 */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GTrafficFlowTempDynParaReq_struct{
	UINT8		  cid;				  /**< PDP Context ID, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimRead4GTrafficFlowTempDynParaReq;

/* CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CNF	 */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GTrafficFlowTempDynParaCnf_struct{
    CiPsRc        rc; 
    UINT8         numFilters;                       /**< Number of Packet Filters */
    CiPsTftOpCode opCode;                           /** Only valid when get TFT of a specified CID */
    CiPsTftFilter filters[CI_PS_MAX_TFT_FILTERS];   /**< Not in use */
}CiPsPrimRead4GTrafficFlowTempDynParaCnf;

/* CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_REQ	 */
typedef CiEmptyPrim CiPsPrimRead4GTrafficFlowTempDynParaCapsReq;

/* CI_PS_PRIM_READ_4G_TRAFFIC_FLOW_TEMP_DYN_PARA_CAPS_CNF	 */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf_struct{
    CiPsRc           rc;  /**< Result code. \sa CiPsRc */
    UINT8            num;
    UINT8            cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context  ID list, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
} CiPsPrimRead4GTrafficFlowTempDynParaCapsCnf;

/*****************************************************************/

//** <paramref name="CI_PS_PRIM_DATACOMP_REPORTING_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDataCompReportingReq_struct{
    UINT8					report;	    /**< 0 - Disable reporting;
											1 - Enable reporting;
											2 - Get current setting. \sa CiPsRc. */
} CiPsPrimDataCompReportingReq;

//** <paramref name="CI_PS_PRIM_DATACOMP_REPORTING_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDataCompReportingCnf_struct{
    CiPsRc			rc;	    				/**< Result code. \sa CiPsRc. */
    CiBoolean		dcomp_report_enabled;	/**< FALSE - report is enabled
												TRUE - report is disabled */
} CiPsPrimDataCompReportingCnf;


/** \brief PDP types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_DCOMP_STATUS_TAG
{
  CIPS_DCOMP_NONE, /**< Data compression is not in use */
  CIPS_DCOMP_BOTH, /**< V42B ITU-T Rec. V.42 bis is in use in
						both directions */
  CIPS_DCOMP_RX,   /**< V42B RD ITU-T Rec. V.42 bis is in use in receive direction only */
  CIPS_DCOMP_TX,   /**< V42B TD ITU-T Rec. V.42 bis is in use in transmit direction only */
  CIPS_DCOMP_TYPE_NUM,
} _CiPsDcompStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
typedef UINT8 CiPsDcompStatus;
/**@}*/

//** <paramref name="CI_PS_PRIM_DATACOMP_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDataCompInd_struct{
    UINT8			cid;	/**< PDP context identifier. */
    CiPsDcompStatus dcomp;	/**< Indicates the data compression status */
} CiPsPrimDataCompInd;

//ICAT EXPORTED STRUCT
/** <paramref name="CI_PS_PRIM_SET_PS_PAGING_CONFIG_REQ">   */
typedef struct CiPsPrimSetPsPagingyConfigReq_struct
{

    CiBoolean enable; /**< TRUE: Activate DSDS PS+Paing; FALSE: Deactivate DSDS PS+Paing \sa CCI API Ref Manual */
} CiPsPrimSetPsPagingyConfigReq;

/** \brief  UE＊s Voice Domain Preference */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIPS_VOICE_DOMAIN_PREFERNCE_TAG
{
	CIPS_VOICE_DOMAIN_CS = 0,
	CIPS_VOICE_DOMAIN_CS_PREFERRED,
	CIPS_VOICE_DOMAIN_IMS_PS_PREFERRED,
	CIPS_VOICE_DOMAIN_IMS_PS,
	CIPS_VOICE_DOMAIN_PREFERNCE_NUM
} _CiPsVoiceDomainPreference;

/** \addtogroup  SpecificSGRelated
 * @{ */
typedef UINT8 CiPsVoiceDomainPreference;
/**@}*/
//ICAT EXPORTED STRUCT
/** <paramref name="CI_PS_PRIM_SET_PS_PAGING_CONFIG_CNF">   */
typedef struct CiPsPrimSetPsPagingyConfigCnf_struct
{
    CiPsRc rc;     /**< Result code. \sa  CiPsRc */
} CiPsPrimSetPsPagingyConfigCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsVoiceCallAvailabilityReq_struct
{
	UINT8	state;				/**< 0 - Voice calls with the IMS are not available, 1 - Voice calls with the IMS are available */
} CiPsPrimSetImsVoiceCallAvailabilityReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_VOICE_CALL_AVAILABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsVoiceCallAvailabilityCnf_struct
{
	CiPsRc            	rc;							/**< Result code \sa CiPsRc */
} CiPsPrimSetImsVoiceCallAvailabilityCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_REQ">   */
typedef CiEmptyPrim CiPsPrimGetImsVoiceCallAvailabilityReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_IMS_VOICE_CALL_AVAILABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetImsVoiceCallAvailabilityCnf_struct
{
	CiPsRc  rc;						/**< Result code \sa CiPsRc */
	UINT8	state;					/**< 0 - Voice calls with the IMS are not available, 1 - Voice calls with the IMS are available */
} CiPsPrimGetImsVoiceCallAvailabilityCnf;


/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsSmsAvailabilityReq_struct
{
	UINT8	state;				/**< 0 - SMS using IMS is not available, 1 - SMS using IMS is available */
} CiPsPrimSetImsSmsAvailabilityReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_SMS_AVAILABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsSmsAvailabilityCnf_struct
{
	CiPsRc            	rc;							/**< Result code \sa CiPsRc */
} CiPsPrimSetImsSmsAvailabilityCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_REQ">   */
typedef CiEmptyPrim CiPsPrimGetImsSmsAvailabilityReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_IMS_SMS_AVAILABILITY_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetImsSmsAvailabilityCnf_struct
{
	CiPsRc  rc;						/**< Result code \sa CiPsRc */
	UINT8	state;					/**< 0 - SMS using IMS is not available, 1 - SMS using IMS is available */
} CiPsPrimGetImsSmsAvailabilityCnf;


/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_REQ">   AT+CMMIVT=[<setting>] */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetMmImsVoiceTerminationReq_struct
{
	CiBoolean	setting;				/**< If TRUE, Mobility Management for IMS Voice Termination disabled; if FALSE, Mobility Management for IMS Voice Termination enabled  \sa CCI API Ref Manual */
} CiPsPrimSetMmImsVoiceTerminationReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_MM_IMS_VOICE_TERMINATION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetMmImsVoiceTerminationCnf_struct
{
	CiPsRc            	rc;							/**< Result code \sa CiPsRc */
} CiPsPrimSetMmImsVoiceTerminationCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_REQ">   */
typedef CiEmptyPrim CiPsPrimGetMmImsVoiceTerminationReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_MM_IMS_VOICE_TERMINATION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetMmImsVoiceTerminationCnf_struct
{
	CiPsRc  rc;						/**< Result code \sa CiPsRc */
	CiBoolean	setting;			/**< If TRUE, Mobility Management for IMS Voice Termination disabled; if FALSE, Mobility Management for IMS Voice Termination enabled  \sa CCI API Ref Manual */
} CiPsPrimGetMmImsVoiceTerminationCnf;


#define	CI_PS_MAX_AUTH_TOKEN_LEN	128
#define	CI_PS_MAX_FLOW_ID			10

/** \brief TFT Flow identifier  */
/** \remarks Common Data Section */
/******************************************************************************
 * CI for AT CMD : AT*CGDFLT
 * AT*CGDFLT = <mode:0/1>,[<PDP_type:ip/ipv6/ipv4v6>,[<APN>,[<emg_ind:0/1>,
 *              [<ipcp_req:0/1>,[<pcscf_v6:0/1>,[<imcn_sig:0/1>,[<dns_v6:0/1>,
 *              [<nw_bear:0/1>,[<dsm_v6_ha:0/1>,[<dsm_v6_pref:0/1>,
 *              [<dsm_v6_ha_v4:0/1>,[<ip_via_nas:0/1>,[<ip_via_dhcp::0/1>,
 *              [<pcscf_v4:0/1>,[<dns_v4:0/1>,[<msisdn:0/1>,[<ifom:0/1>,
 *              [<v4mtu:0/1>,[<local_tft:0/1>]]]]]]]]]]]]]]]]
******************************************************************************/
/*  CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineDefaultPdpCtxReq_tag
{
    UINT8 modeType; // 0 - not save to NVM, 1 - save to NUM;

    CiBoolean   pdpTypePresent;
    CiPsPdpType pdpType;
    CiString    apn;
    CiBoolean   emgIndPresent;
    UINT8     emgInd; 
    CiBoolean ipcpReqPresent;
    UINT8     ipcpReq;
    CiBoolean pcscfIpv6ReqPresent;
    UINT8     pcscfIpv6Req;
    CiBoolean imcnSigPresent;
    UINT8     imcnSig;
    CiBoolean dnsIpv6Present;
    UINT8     dnsIpv6;
    CiBoolean nwBearPresent;
    UINT8     nwBear;
    CiBoolean dsmIpv6HaPresent;
    UINT8     dsmIpv6Ha;
    CiBoolean dsmIpv6PrefPresent;
    UINT8     dsmIpv6Pref;
    CiBoolean dsmIpv6HaIpv4Present;
    UINT8     dsmIpv6HaIpv4;
    CiBoolean ipViaNasPresent;
    UINT8     ipViaNas;
    CiBoolean ipViaDhcpPresent;
    UINT8     ipViaDhcp;
    CiBoolean pcscfIpv4Present;
    UINT8     pcscfIpv4;
    CiBoolean dnsIpv4Present;
    UINT8     dnsIpv4;
    CiBoolean msisdnPresent;
    UINT8     msisdn;
    CiBoolean ifomPresent;
    UINT8     ifom;
    CiBoolean v4mtuPresent;
    UINT8     v4mtu;
    CiBoolean localTftPresent;
    UINT8     localTft;
    CiBoolean etifPresent;
    UINT8     etifFlag;
    CiBoolean   roamPdpTypePresent; /*Lilei, CQ00113795, 20190514*/
    CiPsPdpType roamPdpType;
}CiPsPrimDefineDefaultPdpCtxReq;

/*  CI_PS_PRIM_DEFINE_DEFAULT_PDP_CTX_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimDefineDefaultPdpCtxCnf_tag
{
    CiPsRc rc;							/**< Result code \sa CiPsRc */
}CiPsPrimDefineDefaultPdpCtxCnf;

//typedef CiEmptyPrim CiPsPrimGetDefaultPdpReq;

/*  CI_PS_PRIM_GET_DEFAULT_PDP_CTX_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefaultPdpReq_Tag
{
    UINT8 modeType; // 0 - current used, 1 - from NVM
}CiPsPrimGetDefaultPdpReq;


/*  CI_PS_PRIM_GET_DEFAULT_PDP_CTX_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefaultPdpCtx_tag
{
    UINT8    modeType; // 0 - current used, 1 - from NVM
    CiString apn;
    CiPsPdpType pdpType;
    UINT8    emgInd; 
    UINT8    ipcpReq;
    UINT8    pcscfIpv6Req;
    UINT8    imcnSig;
    UINT8    dnsIpv6;
    UINT8    nwBear;
    UINT8    dsmIpv6Ha;
    UINT8    dsmIpv6Pref;
    UINT8    dsmIpv6HaIpv4;
    UINT8    ipViaNas;
    UINT8    ipViaDhcp;
    UINT8    pcscfIpv4;
    UINT8    dnsIpv4;
    UINT8    msisdn;
    UINT8    ifom;
    UINT8    v4mtu;
    UINT8    localTft;
    UINT8    etifFlag;
    CiPsPdpType roamPdpType; /*Lilei, CQ00113795, 20190514*/
}CiPsPrimGetDefaultPdpCtx;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetDefaultPdpCtxCnf_tag
{
    CiPsRc      rc;
    CiPsPrimGetDefaultPdpCtx pdpCtx;
}CiPsPrimGetDefaultPdpCtxCnf;

/******************************************************************************
 * Add new CI interface for AT CMD:
 * AT+VZWAPNE=<wapn>,<apncl>,<apnni>,<apntype>,<apnb>,<apned>,<apntime>
******************************************************************************/
#define CI_PS_MAX_APN_NUM 5

typedef enum CiPsApnAddrType_tag
{
    CI_PS_APN_ADDR_INVALID_TYPE = 0,
    CI_PS_APN_ADDR_IPV4_TYPE,
    CI_PS_APN_ADDR_IPV6_TYPE,
    CI_PS_APN_ADDR_IPV4V6_TYPE,
    CI_PS_APN_ADDR_MAX_TYPE
}CiPsApnAddrType;

typedef enum CiPsApnBearType_tag
{
    CI_PS_APN_BEAR_INVALID_TYPE = 0,
    CI_PS_APN_BEAR_LTE_TYPE,

    CI_PS_APN_BEAR_MAX_TYPE
}CiPsApnBearType;

/******  CI_PS_PRIM_SET_APN_REQ  & CI_PS_PRIM_SET_APN_CNF ********************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApnReq_Tag
{
    UINT8 wapn;  // which apn, 0 - no action, 1 - the first APN in apn table, 2 - the second APN , ....
    UINT8 apncl; // APN class
    
    CiString  apnni; // APN Network identifier

    CiBoolean apnTypePresent;
    UINT8     apnType; // 0 - invalid, 1 - ipv4, 2 - ipv6, 3 - ipv4v6 // CiPsApnAddrType

    CiBoolean apnBearPresent;
    UINT8     apnBear; // 0 - invalid, 1 - LTE // CiPsApnBearType

    CiBoolean apnedPresent;
    UINT8     apned;   // 0 - disable, 1 - enable

    CiBoolean apnTimePresent;
    UINT32    apnTime; 
}CiPsPrimSetApnReq;

/*  CI_PS_PRIM_SET_APN_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApnCnf_tag
{
    CiPsRc rc;							/**< Result code \sa CiPsRc */
}CiPsPrimSetApnCnf;


/******  CI_PS_PRIM_GET_APN_REQ  & CI_PS_PRIM_GET_APN_CNF ********************/
/* AT+VZWAPNE?*/
/*  CI_PS_PRIM_GET_APN_REQ */
typedef CiEmptyPrim CiPsPrimGetApnReq;

//ICAT EXPORTED STRUCT
typedef struct CiPsApnInfo_tag
{
  UINT8     apncl;
  UINT8     apnType; // 0 - invalid, 1 - ipv4, 2 - ipv6, 3 - ipv4v6 // CiPsApnAddrType
  UINT8     apnBear; // 0 - invalid, 1 - LTE // CiPsApnBearType
  UINT8     apned;   // 0 - disable, 1 - enable
  CiString  apnni;
  UINT32    apnTime; 
}CiPsApnInfo;

/*  CI_PS_PRIM_GET_APN_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetApnCnf_Tag
{
  CiPsRc      rc;  // UINT16, 2 bytes
  UINT8        num;
  CiPsApnInfo apnInfo[CI_PS_MAX_APN_NUM];
}CiPsPrimGetApnCnf;


/******************************************************************************
 * CI_PS_PRIM_SET_IMS_REG_STATE_REQ / CI_PS_PRIM_SET_IMS_REG_STATE_CNF
******************************************************************************/
/* CI_PS_PRIM_SET_IMS_REG_STATE_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsRegStateReq_Tag
{
    UINT8 state;    /**< 0 - IMS de-registered, 1 - IMS registered, 2- IMS Call Active*/
}CiPsPrimSetImsRegStateReq;

/*  CI_PS_PRIM_SET_IMS_REG_STATE_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsRegStateCnf_tag
{
    CiPsRc rc;							/**< Result code \sa CiPsRc */
}CiPsPrimSetImsRegStateCnf;

/******************************************************************************
 * CI_PS_PRIM_UE_EVENT_TO_IMS_IND, notify AP the UE event
******************************************************************************/
typedef enum CiPsUeToImsEvent_tag
{
    CIPS_TO_IMS_EVENT_SIMREMOVE = 0,
    CIPS_TO_IMS_EVENT_APN_CHANGE,
    CIPS_TO_IMS_EVENT_OTHER,
    CIPS_TO_IMS_EVENT_T3346_START,
    CIPS_TO_IMS_EVENT_T3346_EXPIRY,
    CIPS_TO_IMS_EVENT_T3346_STOP,
    /*During VOLTE, IMS data can't be sent to NW as ERRC connection released. 
     * MM and ERRC will info IMS  
     * and then  IMS will send IMS service end to MM. 
	 * add CQ00111246 20180710 by taow*/
    CIPS_TO_IMS_EVENT_ERRC_RELEASE_IND,
    CIPS_TO_IMS_EVENT_REATTACH,  /*add by taow CQ00115596 20190719  */
    CIPS_TO_IMS_EVENT_NEED_KEEP_ALIVE /*Lilei, CQ00138001, 20220725*/
}_CiPsUeToImsEvent;

typedef UINT8 CiPsUeToImsEvent;


/******************************************************************************
 * CI_PS_PRIM_UE_EVENT_TO_IMS_IND, notify AP the UE event
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimUeEventToImsInd_tag
{
    CiPsUeToImsEvent   ueEvent; // 0 - SIM removed, 1 - IMS APN changed, 2 - other, 3 - T3346 start, 4 - T3346 expiry, 5 - T3346 stop,6-ERRC RELEASE.
    CiBoolean imsNeedDeReg; // 0 - IMS not need to re-register, 1 - IMS need to de-register
}CiPsPrimUeEventToImsInd;


/******************************************************************************
 *add for ims, as IMS module located in AP side, these CIs defined for AP only
 * IMS Register information
 * <reg_info>, <ext_info> refer to ETSI TS 127 007 V11.5.0 (2013-01)
 * Section: 8.71 IMS registration information +CIREG
 * CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ/CI_PS_PRIM_SET_IMS_REG_INFO_IND_CNF
 * CI_PS_PRIM_IMS_REG_INFO_IND
 * CI_PS_PRIM_GET_IMS_REG_INFO_REQ/CI_PS_PRIM_GET_IMS_REG_INFO_CNF
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimImsRegInfo_struct
{
	UINT8 regInfo;
	UINT8 extInfo;
} CiPsPrimImsRegInfo;

/** CI_PS_PRIM_GET_IMS_REG_INFO_REQ */
typedef CiEmptyPrim CiPsPrimGetImsRegInfoReq;     //AT+CIREG?

/** CI_PS_PRIM_GET_IMS_REG_INFO_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetImsRegInfoCnf_struct       //+CIREG: <n>, <reg_info>, <ext_info>
{
	CiPsRc rc;
	UINT8 reportState;
	CiPsPrimImsRegInfo info;
} CiPsPrimGetImsRegInfoCnf;

/** CI_PS_PRIM_SET_IMS_REG_INFO_IND_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsRegInfoIndReq_struct  //AT+CIREG=n
{
	UINT8 reportState;
} CiPsPrimSetImsRegInfoIndReq;

/** CI_PS_PRIM_SET_IMS_REG_INFO_IND_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsRegInfoIndCnf_struct  //OK or false
{
	CiPsRc rc;
} CiPsPrimSetImsRegInfoIndCnf;

/** CI_PS_PRIM_IMS_REG_INFO_IND */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimImsRegInfoInd_struct   //+CIREGU: <reg_info>,<ext_info>
{
	UINT8 reportState;
	CiPsPrimImsRegInfo newInfo;
} CiPsPrimImsRegInfoInd;


/******************************************************************************
 *UE's Voice Domain Preference UTRAN/EUTRAN, AT CMD:
 * AT+CVDP=[<setting>] / AT+CEVDP=[<setting>]
 *  1   CS Voice only
 *  2   CS Voice preferred, IMS PS Voice as secondary
 *  3   IMS PS Voice preferred, CS Voice as secondary
 *  4   IMS PS Voice only
 * CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ = 190, 
 * CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_CNF,
 * CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ,       
 * CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_CNF,
******************************************************************************/
/** CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetVoiceDomainPreferenceReq_struct
{
	CiBoolean					eutran;	 /**< If TRUE, E-UTRAN; if FALSE, UTRAN  \sa CCI API Ref Manual */
	CiPsVoiceDomainPreference	setting; /**< indicates the voice domain preference of the UE \sa CiPsVoiceDomainPreference */
}CiPsPrimSetVoiceDomainPreferenceReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_VOICE_DOMAIN_PREFERENCE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetVoiceDomainPreferenceCnf_struct
{
	CiPsRc        rc;							/**< Result code \sa CiPsRc */
} CiPsPrimSetVoiceDomainPreferenceCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_REQ">   */
typedef CiEmptyPrim CiPsPrimGetVoiceDomainPreferenceReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_VOICE_DOMAIN_PREFERENCE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetVoiceDomainPreferenceCnf_struct
{
	CiPsRc            			rc;						/**< Result code \sa CiPsRc */
	CiPsVoiceDomainPreference	utran_setting;			/**< indicates the voice domain preference of the UE for UTRAN \sa CiPsVoiceDomainPreference */
	CiPsVoiceDomainPreference	eutan_setting;			/**< indicates the voice domain preference of the UE for E-UTRAN \sa CiPsVoiceDomainPreference */
} CiPsPrimGetVoiceDomainPreferenceCnf;


/******************************************************************************
 *UE's usage setting for EPS, AT CMD:
 * AT+CEUS=[<setting>]
 *  0   voice centric
 *  1   data centric
 * CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ, 
 * CI_PS_PRIM_SET_EPS_USAGE_SETTING_CNF,
 * CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ 
 * CI_PS_PRIM_GET_EPS_USAGE_SETTING_CNF,
******************************************************************************/

//ICAT EXPORTED ENUM
typedef enum CiPsEpsUsageSetting_Tag
{
	CIPS_EPS_VOICE_CENTRIC = 0,
	CIPS_EPS_DATA_CENTRIC,
	CIPS_EPS_CENTRIC_NUM
} _CiPsEpsUsageSetting;

typedef UINT8 CiPsEpsUsageSetting;

/** CI_PS_PRIM_SET_EPS_USAGE_SETTING_REQ */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetEpsUsageSettingReq_struct
{
    CiPsEpsUsageSetting epsUsageSetting; // 0/1
}CiPsPrimSetEpsUsageSettingReq;

/** CI_PS_PRIM_SET_EPS_USAGE_SETTING_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetEpsUsageSettingCnf_struct
{
    CiPsRc rc;
}CiPsPrimSetEpsUsageSettingCnf;

/** CI_PS_PRIM_GET_EPS_USAGE_SETTING_REQ */
typedef CiEmptyPrim CiPsPrimGetEpsUsageSettingReq;

/** CI_PS_PRIM_GET_EPS_USAGE_SETTING_CNF */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetEpsUsageSettingCnf_struct
{
    CiPsRc rc;
    CiPsEpsUsageSetting epsUsageSetting; // 0/1
}CiPsPrimGetEpsUsageSettingCnf;
    
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApUniversalSettingReq_struct
{
  CiBoolean     enableDataStatePresent;      
  UINT8         enableDataState;                        /**< State of Data enable setting. TRUE: enable; FALSE: disable.\sa CCI API Ref Manual */
} CiPsPrimSetApUniversalSettingReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_AP_UNIVERSAL_SETTING_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApUniversalSettingCnf_struct
{
	CiPsRc            			rc;						/**< Result code \sa CiPsRc */
} CiPsPrimSetApUniversalSettingCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPsServiceDomainReq_struct
{
  CiBoolean         psServiceEnable;                        /**< State of Data enable setting. TRUE: enable; FALSE: disable.\sa CCI API Ref Manual */
} CiPsPrimSetPsServiceDomainReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PS_SERVICE_DOMAIN_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPsServiceDomainCnf_struct
{
	CiPsRc            			rc;						/**< Result code \sa CiPsRc */
} CiPsPrimSetPsServiceDomainCnf;

/** CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_REQ */
typedef CiEmptyPrim CiPsPrimGetPsServiceDomainReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PS_SERVICE_DOMAIN_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPsServiceDomainCnf_struct
{
    CiBoolean         psServiceEnable;                        /**< State of Data enable setting. TRUE: enable; FALSE: disable.\sa CCI API Ref Manual */
} CiPsPrimGetPsServiceDomainCnf;

/******************************************************************************
 * CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ/CI_PS_PRIM_SET_IMS_SERVICE_STATUS_CNF
 * used for voLTE DSDS solution,
 * AP IMS module use it to notify CP the IMS service status
******************************************************************************/
typedef enum CiPsImsSrvType_enum
{
    CIPS_IMS_MO_CALL = 0,
    CIPS_IMS_SMS  = 1,
    CIPS_IMS_SS   = 2,
    CIPS_IMS_ECALL = 3, //emergency call
    CIPS_IMS_REGISTER = 4, //IMS APN setup or SIP register
    CIPS_IMS_DEREG = 5,
    CIPS_IMS_MT_CALL = 6,
    CIPS_POC_SVC = 7,       //POC normal PS service
    CIPS_POC_HEARTBEAT = 8, //POC heartbeat packet
    CIPS_POC_MO_ECALL_OVER_IMS = 9, //eCall over IMS
    CIPS_IMS_OTHER_SRV
}_CiPsImsSrvType;

typedef UINT8 CiPsImsSrvType;

typedef enum CiPsImsSrvStatus_enum
{
    CIPS_IMS_SRV_START = 0,
    CIPS_IMS_SRV_END,
    CIPS_IMS_SRV_FAILED,

    CIPS_IMS_SRV_STATUS_NUM
}_CiPsImsSrvStatus;

typedef UINT8 CiPsImsSrvStatus;

typedef enum CiPsImsSrvFailCause_enum
{
    CIPS_IMS_SRV_NO_CAUSE = 0,
    CIPS_IMS_CS_FAIL_CSFB_FOLLOW,
    CIPS_IMS_CACELLED_BY_NETWORK,
    CIPS_IMS_SRV_BOOTUP,
    CIPS_IMS_SRV_CANCELLED_BY_IMS,/*ims recieve CIPS_IMS_SRV_CAUSE_WAIT_FOR_RESUMECNF, and never recieve CIPS_IMS_SRV_CAUSE_SUCCESS before, ims will use it to inform MM to resume peer */
    
    CIPS_IMS_SRV_FAIL_CAUSE_NUM
}_CiPsImsSrvFailCause;

typedef UINT8 CiPsImsSrvFailCause;

typedef enum CiPsImsSrvCause_enum
{
    CIPS_IMS_SRV_CAUSE_SUCCESS = 0, /*Successful*/
    CIPS_IMS_SRV_CAUSE_TERMINATE,   /*Failed, another card is doing CS service*/
    CIPS_IMS_SRV_CAUSE_REDIAL,      /*Failed, another card is doning high priority service, IMS will redial later*/
    CIPS_IMS_SRV_CAUSE_WAIT_FOR_RESUMECNF, /*peer MM is in PS state or MM is waiting RESUME CNf,MM will use this*/
    CIPS_IMS_SRV_CAUSE_RAT_IS_23G,        /*Failed, inform IMS rat has been 23g,IMS need check how to retry service*/
    CIPS_IMS_SRV_CAUSE_RETRY_FOR_MT,      /*Failed, inform IMS to retry IMS MT CALL,IMS need check how to retry service*/
    CIPS_IMS_SRV_CAUSE_NUM
}_CiPsImsSrvCause;

typedef UINT16 CiPsImsSrvCause;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_SERVICE_STATUS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsServiceStatusReq_struct
{
    CiPsImsSrvType imsSrvType;
    CiPsImsSrvStatus imsSrvStatus;
    CiPsImsSrvFailCause srvFailCause;
}CiPsPrimSetImsServiceStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_IMS_SERVICE_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetImsServiceStatusCnf_struct
{
    CiPsRc rc;
    CiPsImsSrvCause cause;
}CiPsPrimSetImsServiceStatusCnf;


/******************************************************************************
 * CI_PS_PRIM_SUSPEND_RESUME_IND
 * use to notify AP the PDP status, whether UL path is OK
******************************************************************************/
typedef enum CiPsSuspendCause_enum
{
    CIPS_SUSPEND_NO_CAUSE = 0,
    CIPS_SUSPEND_BY_RAU_ATTACH,
    CIPS_SUSPEND_BY_LAU,
    CIPS_SUSPEND_BY_TAU,
    CIPS_SUSPEND_BY_CS_SERVICE,
    CIPS_SUSPEND_BY_DS_OPERATION,
    CIPS_SUSPEND_BY_POWERUP,
    
    CIPS_SUSPEND_CAUSE_NUM
}_CiPsSuspendCause;

typedef UINT16 CiPsSuspendCause;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SUSPEND_RESUME_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSuspendResumeInd_struct
{
    CiBoolean           suspended; // 0 - resume, 1 - suspended
    CiPsSuspendCause    suspendReason;
}CiPsPrimSuspendResumeInd;

/*Lilei, CQ00111775, 20180814, begin*/
/******************************************************************************
 * PPP CHAP authentication, configured by upper layer. AT CMD:
 * AT*CHAPAUTH=cid[,<challenge>[,<response>]]
 * CI_PS_PRIM_CHAP_AUTHENTICATE_REQ, 
 * CI_PS_PRIM_CHAP_AUTHENTICATE_CNF.
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimChapAuthenticateReq_struct
{
  UINT8             cid;            /**< PDP context identifier. 0xFF for LTE attach PDN; others for MO */
  CiStringExt       challenge; 		/**< CHAP challenge octets */
  CiStringExt       response;     	/**< CHAP response octets */
} CiPsPrimChapAuthenticateReq;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimChapAuthenticateCnf_struct
{
  CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimChapAuthenticateCnf;
/*Lilei, CQ00111775, 20180814, end*/

/*Lilei, CQ00112384, 20181101, begin*/
/******************************************************************************
 * Activate reconfigured PDP (an already activated PDP is re-defined).
 * Firstly activate the new PDP, then deact the old one, finally CNF.
 * CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_REQ, 
 * CI_PS_PRIM_ACTIVATE_RECONF_PDP_CTX_CNF.
******************************************************************************/
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimActivateReconfigPdpCtxReq_struct
{
    CiPsPdpCtx                pdpCtx;         /**< PDP context definition \sa CiPsPdpCtx_struct */
    CiBoolean                 authInfoPresent;
    CiPsAuthenticationType    authenticationType;   /**< Authentication type. \sa CiPsAuthenticationType */ 
    CiStringExt               userName;             /**< UserName octets. \sa CCI API Ref Manual */
    CiStringExt               password;             /**< Password octets. \sa CCI API Ref Manual */
}CiPsPrimActivateReconfigPdpCtxReq;

//ICAT EXPORTED STRUCT
typedef struct CiPsPrimActivateReconfigPdpCtxCnf_struct
{
    CiPsRc rc;			/**< Result code. \sa CiPsRc */
} CiPsPrimActivateReconfigPdpCtxCnf;
/*Lilei, CQ00112384, 20181101, end*/


/* ==============  Added for REL13 ====================================================*/

/* ========  AT+CPSMS  ========= */
typedef enum CiPsPsmModeType_enum
{
    CIPS_PSM_DISBABLE      = 0,   /** <disable the use of PSM */
    CIPS_PSM_ENABLE        = 1,   /** <enable the use of PSM */
    CIPS_PSM_DISABLE_RESET = 2,   /** <disable the use of PSM and discard all parameters for PSM */

    CIPS_PSM_NUM_MODE
}_CiPsPsmModeType;

typedef UINT8 CiPsPsmModeType;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PSM_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPsmConfigReq_struct
{
    CiPsPsmModeType  mode;     /**< Indication to disable or enable the use of PSM in the UE */

	CiBoolean        requestedPeriodRauPresent;
    UINT8            requestedPeriodRau;   /** <not used, set to 0 */
	CiBoolean        requestedGprsReadyTimerPresent;	
	UINT8            requestedGprsReadyTimer;    /** <not used, set to 0 */

	CiBoolean        requestedPeriodicTauPresent;	
	UINT8            requestedPeriodicTau;    /** <requested T3412 timer value, one byte in an 8 bit format */
	CiBoolean        requestedActiveTimePresent;		
	UINT8            requestedActiveTime;     /** <requested T3324 timer value, one byte in an 8 bit format  */
}CiPsPrimSetPsmConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PSM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPsmConfigCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimSetPsmConfigCnf;

/* <INUSE> */
/** CI_PS_PRIM_GET_PSM_CONFIG_REQ */
typedef CiEmptyPrim CiPsPrimGetPsmConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PSM_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPsmConfigCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

    CiPsPsmModeType  mode;     /**< Indication to disable or enable the use of PSM in the UE */

	CiBoolean        requestedPeriodRauPresent;
    UINT8            requestedPeriodRau;   /** <not used, set to 0 */
	CiBoolean        requestedGprsReadyTimerPresent;	
	UINT8            requestedGprsReadyTimer;    /** <not used, set to 0 */

	CiBoolean        requestedPeriodicTauPresent;	
	UINT8            requestedPeriodicTau;    /** <requested T3412 timer value, one byte in an 8 bit format  */
	CiBoolean        requestedActiveTimePresent;		
	UINT8            requestedActiveTime;     /** <requested T3324 timer value, one byte in an 8 bit format  */
} CiPsPrimGetPsmConfigCnf;

/* ========  AT+CEDRXS  ========= */
typedef enum CiPsEdrxModeType_enum
{
    CIPS_EDRX_DISBABLE      = 0,   /** <disable the use of eDRX */
    CIPS_EDRX_ENABLE        = 1,   /** <enable the use of eDRX */
    CIPS_EDRX_ENABLE_URC    = 2,   /** <enable the use of eDRX and enable the unsolicited result code */
	CIPS_EDRX_DISBABLE_RESET= 3,   /** <disable the use of eDRX and discard all parameters for eDRX */

    CIPS_EDRX_NUM_MODE
}_CiPsEdrxModeType;

typedef UINT8 CiPsEdrxModeType;

typedef enum CiPsEdrxActType_enum
{
    CIPS_EDRX_ACT_NONE      = 0,   /** <AcT is not using eDRX. This parameter value is only used in unsolicated result code */
    CIPS_EDRX_ACT_ECGSM     = 1,   /** <EC-GSM-IoT(A/Gb mode*/
    CIPS_EDRX_ACT_GSM       = 2,   /** <GSM(A/Gb mode) */
	CIPS_EDRX_ACT_UTRAN     = 3,   /** <UTRAN(Iu mode) */
	CIPS_EDRX_ACT_EUTRAN 	= 4,   /** <E-UTRAN(WB-S1 mode */
	CIPS_EDRX_ACT_EUTRAN_NB	= 5,   /** <E-UTRAN(NB-S1 mode) */

    CIPS_EDRX_NUM_ACT
}_CiPsEdrxActType;

typedef UINT8 CiPsEdrxActType;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_EDRX_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetEdrxConfigReq_struct
{
    CiPsEdrxModeType mode;     /**< indicates to disable or enable the use of eDRX in the UE */
	
	CiPsEdrxActType  eDrxAct;     /**< indicates the type of access technology */
	CiBoolean        requestedEdrxValuePresent;	
	UINT8            requestedEdrxValue;    /** <requested eDRX value, half a byte in a 4 bit format */
}CiPsPrimSetEdrxConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_EDRX_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetEdrxConfigCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimSetEdrxConfigCnf;

/* <INUSE> */
/** CI_PS_PRIM_GET_EDRX_CONFIG_REQ */
typedef CiEmptyPrim CiPsPrimGetEdrxConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_EDRX_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetEdrxConfigCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
	
	CiPsEdrxActType  eDrxAct;     /**< indicates the type of access technology */
	CiBoolean        requestedEdrxValuePresent;	
	UINT8            requestedEdrxValue;    /** <requested eDRX value, half a byte in a 4 bit format */
} CiPsPrimGetEdrxConfigCnf;

/* ========  AT+CEDRXP  ========= */
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_EDRX_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimEdrxInfoInd_struct
{
	CiPsEdrxActType  eDrxAct;   /**< indicates the type of access technology */

	CiBoolean        requestedEdrxValuePresent;	
	UINT8            requestedEdrxValue;    /** <requested eDRX value, half a byte in a 4 bit format */
	
	CiBoolean        nwProvidedEdrxvaluePresent;	
	UINT8            nwProvidedEdrxvalue;   /** <NW-provided eDRX value, half a byte in a 4 bit format */	
	CiBoolean        pagingTimerWindowPresent;	
	UINT8            pagingTimerWindow;     /** <NW-provided paing time window, half a byte in a 4 bit format */
} CiPsPrimEdrxInfoInd;

/* ========  AT+CEDRXRDP  ========= */
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_EDRX_DYN_PARA_REQ">   */
typedef CiEmptyPrim CiPsPrimReadEdrxDynParaReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_EDRX_DYN_PARA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReadEdrxDynParaCnf_struct
{
  CiPsRc    rc;         /**< Result code. \sa CiPsRc */

  CiPsEdrxActType  eDrxAct;   /**< indicates the type of access technology */
  
  CiBoolean 	   requestedEdrxValuePresent; 
  UINT8 		   requestedEdrxValue;	  /** <requested eDRX value, half a byte in a 4 bit format */
  
  CiBoolean 	   nwProvidedEdrxvaluePresent;	  
  UINT8 		   nwProvidedEdrxvalue;   /** <NW-provided eDRX value, half a byte in a 4 bit format */ 
  CiBoolean 	   pagingTimerWindowPresent;  
  UINT8 		   pagingTimerWindow;	  /** <NW-provided paing time window, half a byte in a 4 bit format */
} CiPsPrimReadEdrxDynParaCnf;

/* ========  AT+CCIOTOPT  ========= */
typedef enum CiPsCiotOption_enum
{
    CIPS_CIOT_DISABLE    	= 0,   /** <disable reporting */
	CIPS_CIOT_ENABLE 		= 1,   /** <enable reporting */
	CIPS_CIOT_DISABLE_RESET = 2,   /** <disable reporting and reset the parameters for CIoT EPS optimization to the default value */

    CIPS_CIOT_NUM_OPT
}_CiPsCiotOption;

typedef UINT8 CiPsCiotOption;

typedef enum CiPsCiotSupportedUeOpt_enum
{
    CIPS_CIOT_UE_NO  	= 0,   /** <No support */
	CIPS_CIOT_UE_CP		= 1,   /** <Support for control plane CIoT EPS optimization */
	CIPS_CIOT_UE_UP		= 2,   /** <Support for user plane CIoT EPS optimization */
	CIPS_CIOT_UE_CP_UP 	= 3,   /** <Support for both control plane CIoT EPS optimization and user plane CIoT EPS optimization */

    CIPS_CIOT_NUM_UE
}_CiPsCiotSupportedUeOpt;

typedef UINT8 CiPsCiotSupportedUeOpt;

typedef enum CiPsCiotPreferUeOpt_enum
{
    CIPS_CIOT_UE_PREFER_NO  	= 0,   /** <No preference */
	CIPS_CIOT_UE_PREFER_CP		= 1,   /** <Preference for control plane CIoT EPS optimization */
	CIPS_CIOT_UE_PERFER_UP		= 2,   /** <Preference for user plane CIoT EPS optimization */

    CIPS_CIOT_NUM_PREFER
}_CiPsCiotPreferUeOpt;

typedef UINT8 CiPsCiotPreferUeOpt;

typedef enum CiPsCiotSupportedNwOpt_enum
{
    CIPS_CIOT_NW_NO  	= 0,   /** <No support */
	CIPS_CIOT_NW_CP		= 1,   /** <Support for control plane CIoT EPS optimization */
	CIPS_CIOT_NW_UP		= 2,   /** <Support for user plane CIoT EPS optimization */
	CIPS_CIOT_NW_CP_UP 	= 3,   /** <Support for both control plane CIoT EPS optimization and user plane CIoT EPS optimization */

    CIPS_CIOT_NUM_NW
}_CiPsCiotSupportedNwOpt;

typedef UINT8 CiPsCiotSupportedNwOpt;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_CIOT_CONFIG_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetCiotConfigReq_struct
{
	CiPsCiotOption	        option; 	    /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */
	CiPsCiotSupportedUeOpt  supportedUeOpt; /**< indicates the UE's support for CIoT EPS optimization */
	CiPsCiotPreferUeOpt     preferUeOpt;    /**< indicates the UE's preference for CIoT EPS optimization */
}CiPsPrimSetCiotConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_CIOT_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetCiotConfigCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimSetCiotConfigCnf;

/* <INUSE> */
/** CI_PS_PRIM_GET_CIOT_CONFIG_REQ */
typedef CiEmptyPrim CiPsPrimGetCiotConfigReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_CIOT_CONFIG_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetCiotConfigReq_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

	CiPsCiotOption	        option; 	    /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */
	CiPsCiotSupportedUeOpt  supportedUeOpt; /**< indicates the UE's support for CIoT EPS optimization */
	CiPsCiotPreferUeOpt     preferUeOpt;    /**< indicates the UE's preference for CIoT EPS optimization */	
} CiPsPrimGetCiotConfigCnf;

/* ========  AT+CCIOTOPTI  ========= */
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_CIOT_NW_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimCiotNwInfoInd_struct
{
	CiPsCiotSupportedNwOpt  supportedNwOpt; /**< indicates the Network support for CIoT EPS optimization */
} CiPsPrimCiotNwInfoInd;

/* ========  AT+CSCON  ========= */
typedef enum CiPsSignallingConnectionOpt_enum
{
    CIPS_CSCON_DISABLE    	 = 0,   /** <disable unsolicited result code */
	CIPS_CSCON_ENABLE_MODE	 = 1,   /** <disable unsolicited result code +CSCON:<mode> */
	CIPS_CSCON_ENABLE_STATE  = 2,   /** <disable unsolicited result code +CSCON:<mode> ,<state>*/
	CIPS_CSCON_ENABLE_ACCESS = 3,   /** <disable unsolicited result code +CSCON:<mode> ,<state>,<access>*/

    CIPS_NUM_CSCON
}_CiPsSignallingConnectionOpt;

typedef UINT8 CiPsSignallingConnectionOpt;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimConfigSignallingConnectionReq_struct
{
	CiPsSignallingConnectionOpt     option; 	    /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */
}CiPsPrimConfigSignallingConnectionReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_CONFIG_SIGNALLING_CONNECTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimConfigSignallingConnectionCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimConfigSignallingConnectionCnf;

typedef enum CiPsCsconMode_enum
{
    CIPS_CSCON_MODE_IDLE    	= 0,   /** <idle */
	CIPS_CSCON_MODE_CONNECTED	= 1,   /** <connected */
	CIPS_CSCON_MODE_PSM			= 2,   /** < PSM in idle */
	CIPS_CSCON_MODE_DEACTIVATED = 3,   /** < deactivated */

    CIPS_CSCON_NUM_MODE
}_CiPsCsconMode;

typedef UINT8 CiPsCsconMode;

typedef enum CiPsCsconState_enum
{
    CIPS_CSCON_STATE_UTRAN_URA_PCH    	= 0,   /** <UTRAN URA_PCH state */
	CIPS_CSCON_STATE_UTRAN_CELL_PCH		= 1,   /** <UTRAN Cell_PCH state */
	CIPS_CSCON_STATE_UTRAN_CELL_FACH	= 2,   /** <UTRAN Cell_FACH state */	
	CIPS_CSCON_STATE_UTRAN_CELL_DCH		= 3,   /** <UTRAN Cell_DCH state  */
	CIPS_CSCON_STATE_GERAN_CS_CONNECT 	= 4,   /** <GERAN CS connected state */
	CIPS_CSCON_STATE_GERAN_PS_CONNECT	= 5,   /** <GERAN PS connected state */
	CIPS_CSCON_STATE_GERAN_COMBINED		= 6,   /** <GERAN CS and PS connected state */

	CIPS_CSCON_STATE_EUTRAN_CONNECT		= 7,   /** <E-UTRAN connected state */

    CIPS_CSCON_NUM_STATE
}_CiPsCsconState;

typedef UINT8 CiPsCsconState;

typedef enum CiPsCsconAccess_enum
{
    CIPS_CSCON_ACCESS_GERAN    		= 0,   /** <GERAN */
	CIPS_CSCON_ACCESS_UTRAN_TDD		= 1,   /** <UTRAN TDD */
	CIPS_CSCON_ACCESS_UTRAN_FDD		= 2,   /** <UTRAN FDD */	
	CIPS_CSCON_ACCESS_EUTRAN_TDD	= 3,   /** <E-UTRAN TDD */
	CIPS_CSCON_ACCESS_EUTRAN_FDD 	= 4,   /** <E-UTRAN FDD */

    CIPS_CSCON_NUM_ACCESS
}_CiPsCsconAccess;

typedef UINT8 CiPsCsconAccess;

/** <paramref name="CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_REQ">   */
typedef CiEmptyPrim CiPsPrimGetSignallingConnectionStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_SIGNALLING_CONNECTION_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetSignallingConnectionStatusCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

	CiPsSignallingConnectionOpt     option; 	    /**< Enables or disables reporting of unsolicated result codes +CCIOTOPTI */	
    CiPsCsconMode mode;            /**<indicates the signalling connection satus */

	CiBoolean statePresent;
	CiPsCsconState state;          /**<indicates the CS or PS state while in GERAN and the RRC state information if the MTis in connected mode while in UTRAN and E-UTRAN */
	
	CiBoolean accessPresent;
	CiPsCsconAccess access;        /**<indicates the current radio access type */
}CiPsPrimGetSignallingConnectionStatusCnf;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SIGNALLING_CONNECTION_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSignallingConnectionInd_struct
{
    CiPsCsconMode mode;            /**<indicates the signalling connection satus */

	CiBoolean statePresent;
	CiPsCsconState state;          /**<indicates the CS or PS state while in GERAN and the RRC state information if the MTis in connected mode while in UTRAN and E-UTRAN */
	
	CiBoolean accessPresent;
	CiPsCsconAccess access;        /**<indicates the current radio access type */
}CiPsPrimSignallingConnectionInd;

/* ========  AT+CIPCA  ========= */
typedef enum CiPsEpsAttachwithPdnOpt_enum
{
    CIPS_EPS_ATTACH_WITH_PDN   		= 0,   /** <EPS Attach with PDN connection */
	CIPS_EPS_ATTACH_WITHOUT_PDN		= 1,   /** <EPS Attach without PDN connection */

    CIPS_NUM_EPS_ATTACH_WITH_PDN
}_CiPsEpsAttachwithPdnOpt;

typedef UINT8 CiPsEpsAttachwithPdnOpt;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetInitialPdpActivationOptReq_struct
{
	UINT8	option; /**<Activation of PDP context upon attach, only used for 2/3G, 0 - Do not activate, 1 - Always activate, 2 - Activate when not roaming, 3 - No change in current setting only for EUTRAN */
	CiPsEpsAttachwithPdnOpt	attachWithoutPdn;  /**< EPS attach with or without PDN connection */
}CiPsPrimSetInitialPdpActivationOptReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_INITIAL_PDP_ACTIVATION_OPT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetInitialPdpActivationOptCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimSetInitialPdpActivationOptCnf;

/** <paramref name="CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_REQ">   */
typedef CiEmptyPrim CiPsPrimGetInitialPdpActivationOptReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_INITIAL_PDP_ACTIVATION_OPT_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetInitialPdpActivationOptCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

	UINT8	option; /**<Activation of PDP context upon attach, only used for 2/3G, 0 - Do not activate, 1 - Always activate, 2 - Activate when not roaming, 3 - No change in current setting only for EUTRAN */
	CiPsEpsAttachwithPdnOpt	attachWithoutPdn;  /**< EPS attach with or without PDN connection */	
}CiPsPrimGetInitialPdpActivationOptCnf;

/* ========  AT+CABTSR  ========= */
typedef enum CiPsApnBackoffTimerOpt_enum
{
    CIPS_APN_BACKOFF_STATUS_DISABLE  = 0,   /** <disable presentation of the unsolicited result code */
    CIPS_APN_BACKOFF_STATUS_ENABLE	 = 1,   /** <enable  presentation of the unsolicited result code +CABTSRI:<apn>,<event_type> */

    CIPS_NUM_APN_BACKOFF_STATUS
}_CiPsApnBackoffTimerOpt;

typedef UINT8 CiPsApnBackoffTimerOpt;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApnBackoffTimerStatusReq_struct
{
	CiPsApnBackoffTimerOpt	option; /**< 0- Disable presentation of the unsolicited result code, 1-Enable presentation of the unsolicited result code */
}CiPsPrimSetApnBackoffTimerStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_APN_BACKOFF_TIMER_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetApnBackoffTimerStatusCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
}CiPsPrimSetApnBackoffTimerStatusCnf;

/** <paramref name="CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_REQ">   */
typedef CiEmptyPrim CiPsPrimGetApnBackoffTimerStatusReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_APN_BACKOFF_TIMER_STATUS_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetApnBackoffTimerStatusCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

	CiPsApnBackoffTimerOpt	option; /**< 0- Disable presentation of the unsolicited result code, 1-Enable presentation of the unsolicited result code */
}CiPsPrimGetApnBackoffTimerStatusCnf;

/* ========  AT+CABTSRI  ========= */
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_APN_BACKOFF_TIMER_STATUS_REPORT_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimApnBackoffTimerStatusReportInd_struct
{
    CiString apn;

	UINT32  eventType; /**< 0- the back-off timer is started, 1-the backoff timer is stopped, 2-the back-off timer is expired */
	UINT32  backoffTimerValue; /**< Indicate the residual back-off timer value, in second */
	
	CiBoolean reAttempPresent;
	UINT8   reAttemptRatIndication; /**< 0- Re-attempt the seeion management afert inter-system change is allowed, 1- not allowed, now no need to support it */
	UINT8   reAttemptEplmnIndication; /**<0- Re-attempt the session management in an EPLMN is allowed, 1 - not allowed */
	
	CiBoolean nslpiPresent;
	UINT8   nslpi; /**< 0 -Indicates that this PDN connection was set to "MS is configured for NAS signalling low priority", 1 - set to "MS is not configured for NAS signalling low priority"*/
    UINT8   procedure; /**<0-all procedures, 1-PDN connectivity proc, 2-bearer resource allocation proc, 3-bearer resource modification proc,
                                                                                                 4-PDP activation proc, 5-secondary PDP activation proc, 6-PDP modification proc */
}CiPsPrimApnBackoffTimerStatusReportInd;

/* ========  AT+CABTRDP  ========= */
#define CI_PS_MAX_APN_BACKOFF_INFO_NUM 10

//ICAT EXPORTED STRUCT
typedef struct CiPsApnBackoffTimerInfo_struct
{
    CiString apn;

	UINT32  backoffTimerValue; /**< Indicate the residual back-off timer value, in second */

	CiBoolean reAttempPresent;
	UINT8   reAttemptRatIndication; /**< 0- Re-attempt the seeion management afert inter-system change is allowed, 1- not allowed, now no need to support it. */
	UINT8   reAttemptEplmnIndication; /**<0- Re-attempt the session management in an EPLMN is allowed, 1 - not allowed */
	
	CiBoolean nslpiPresent;
	UINT8   nslpi; /**< 0 -Indicates that this PDN connection was set to "MS is configured for NAS signalling low priority", 1 - set to "MS is not configured for NAS signalling low priority"*/
    UINT8   procedure; /**<0-all procedures, 1-PDN connectivity proc, 2-bearer resource allocation proc, 3-bearer resource modification proc,
                                                                                                 4-PDP activation proc, 5-secondary PDP activation proc, 6-PDP modification proc */
}CiPsApnBackoffTimerInfo;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReadApnBackoffTimerDynParaReq_struct
{
    CiBoolean apnPresent; /**< if it is omitted, all APNs associated with back-off timers in the current RAT and PLMN combination is returned */
    CiString  apn; 
}CiPsPrimReadApnBackoffTimerDynParaReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_READ_APN_BACKOFF_TIMER_DYN_PARA_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimReadApnBackoffTimerDynParaCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */

    UINT8					num; /**< Number of apn backoff timer info */
	CiPsApnBackoffTimerInfo list[CI_PS_MAX_APN_BACKOFF_INFO_NUM];
}CiPsPrimReadApnBackoffTimerDynParaCnf;

/* ========  AT+CGAPNRC  ========= */
//ICAT EXPORTED STRUCT
typedef struct CiPsApnRateCtrlnfo_struct
{
	UINT8   addExceptionReports; /**< 0- Additional_exception_reportes at max rate reached are not allowed to be sent, 1- allowed. */
	UINT8   ulTimeUnit; /**<0 -unrestricted, 1 -minute, 2 -hour, 3 -day, 4- week */
	UINT32  maxUlRate;  /**< specifies the time unit to be used for the max uplink rate */
}CiPsApnRateCtrlnfo;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_APN_RATE_CONTROL_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetApnRateControlReq_struct
{
	CiBoolean     cidPresent; /**< if the parameter<cid> is omitted, the APN rate control parameters for all active PDP contexs are returned */
	UINT8         cid;
} CiPsPrimGetApnRateControlReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_APN_RATE_CONTROL_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetApnRateControlCnf_struct
{
    CiPsRc rc;         /**< Result code. \sa CiPsRc */
	
  	UINT8              num;
  	UINT8              cid[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];/**< PDP context identifier [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
	CiPsApnRateCtrlnfo list[CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM];
} CiPsPrimGetApnRateControlCnf;


/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CONTEXT_INFO_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpContextInfoReq_struct
{
  UINT8  cid;		/**< PDP context identifier   */
} CiPsPrimGetPdpContextInfoReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_GET_PDP_CONTEXT_INFO_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimGetPdpContextInfoCnf_struct
{
    CiPsRc rc;				        /**< Result code \sa CiPsRc */

	UINT8             cid;       	/**< PDP context identifier, [0- CI_PS_MAX_MO_AND_MT_PDP_CTX_NUM-1] */
	CiBoolean 		  ctxValid;		/**< TRUE: if present, only for activated PDP */

	CiPsPdpType 	  type; 					   /**< PDP type \sa CiPsPdpType */
	UINT8			  bearerId;				       /**< Bearer id or NSAPI, 5~15 */
	CiPsPdpBearType   pdpBearType;				   /**< 0 - invalid, 1 - primary/default PDP, 2 - dedicated/secondary PDP */
	UINT8			  p_cid;                       /**< 255 - invalid */
	UINT8			  linked_bearerId;			   /**< Linded Bearer id, 5~15, 0 - invalid */

	CiBoolean		  apnPresent;				   /**< Flag indicating that the APN is present (optional field) \sa CCI API Ref Manual*/
	CiString		  apn;						   /**< APN, length range [CI_PS_APN_MIN_SIZE - CI_PS_APN_MAX_SIZE]. \sa CCI API Ref Manual */
	
	CiPsPdpIpAddr	  ipv4Addr; 				   /**< PDP address \sa CiPsPdpAddr_struct */
	CiPsPdpIpAddr	  ipv6Addr;

    CiBoolean         negEpsQosAvailable;          /**< 4G QoS profile */
    CiPs4GQosProfile  negEpsQosProfile;               

	CiBoolean		  neg3gQosAvailable;		   /**< 3G QoS profile */
	CiPs3GQosProfile  neg3gQosProfile;
	
	UINT8		      dnsAddrNum;                  /**< DNS address */
	CiPsPdpIpAddr     dnsAddr[CI_PS_PDP_MAX_NW_ADDR_NUM];	
}CiPsPrimGetPdpContextInfoCnf;

/*Lilei, CQ00138315, 20220815, begin*/
/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PDP_CTX_REMAP_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPdpCtxRemapReq_struct
{
  CiBoolean  	            state;		    /**< State of activation/deactivation. TRUE: activate; FALSE: deactivate. */
  UINT8      	            cid;			/**< PDP context identifier to  activate/deactivate*/
  UINT8      	            cidRemap;		/**< PDP context identifier to remap from when activate, or remap back to when deactivate */
  CiPsPdpType               type;           /**< PDP type */
  CiBoolean                 apnPresent;
  CiString                  apn;
  CiBoolean                 authInfoPresent;
  CiPsAuthenticationType    authenticationType;   /**< Authentication type. */ 
  CiStringExt               userName;             /**< UserName octets. */
  CiStringExt               password;             /**< Password octets. */
} CiPsPrimSetPdpCtxRemapReq;

/* <INUSE> */
/** <paramref name="CI_PS_PRIM_SET_PDP_CTX_REMAP_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiPsPrimSetPdpCtxRemapCnf_struct
{
    CiPsRc                  rc;             /**< Result code. \sa CiPsRc */
    UINT8                   cid;            /**< PDP context identifier to  activate/deactivate*/
    UINT8                   cidRemap;       /**< PDP context identifier to remap from when activate, or remap back to when deactivate */
} CiPsPrimSetPdpCtxRemapCnf;
/*Lilei, CQ00138315, 20220815, end*/


/////////////////////////////////////////////////
///****************END*********************///
////////////////////////////////////////////////

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_ps_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_PS_NUM_CUST_PRIM is set to 0 in the "ci_ps_cust.h" file.
 */
#include "ci_ps_cust.h"

#define CI_PS_NUM_PRIM ( CI_PS_NUM_COMMON_PRIM + CI_PS_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_PS_NUM_PRIM CI_PS_NUM_COMMON_PRIM

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

#endif /* _CI_PS_H_ */


/*                      end of ci_ps.h
--------------------------------------------------------------------------- */


