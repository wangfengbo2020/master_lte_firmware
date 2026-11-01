/*------------------------------------------------------------
(C) Copyright [2006-2009] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_msg.h
Description : Data types file for the MSG Service Group
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

#if !defined(_CI_MSG_H_)
#define _CI_MSG_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_api_types.h"

/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_MSG_VER_MAJOR 3
//#define CI_MSG_VER_MINOR 1

//#define CI_MSG_VER_MAJOR 3
//#define CI_MSG_VER_MINOR 0
#define CI_MSG_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version


/* -----------------------------------------------------------------------------
 *    MSG Configuration definitions
 * ----------------------------------------------------------------------------- */

/* Maximum number of CBMI (mids) list entries for Get/Set CBM Types primitives */
#define CIMSG_MAX_MIDS_LIST_SIZE        50    /* For local mids List        */
#define CIMSG_MAX_MIDS_RANGELST_SIZE    5     /* For mids RangeLst[ ] array */
#define CIMSG_MAX_MIDS_INDVLIST_SIZE    50    /* For mids IndvList[ ] array */

/* Maximum number of LP (dcss) list entries for Get/Set CBM Types primitives */
#define CIMSG_MAX_DCSS_LIST_SIZE        30    /* For local dcss List        */
#define CIMSG_MAX_DCSS_RANGELST_SIZE    3     /* For dcss RangeLst[ ] array */
#define CIMSG_MAX_DCSS_INDVLIST_SIZE    30    /* For dcss IndvList[ ] array */

/* Maximum values for CBMI (mids) and LP (dcss) themselves */
#define CIMSG_MAX_MIDS_VALUE            65535
#define CIMSG_MAX_DCSS_VALUE            63   /* refer to 3G TS 23.038 */

#define CI_MSG_MAX_SUPPORTED_SERVICES   3

#define CI_MSG_MAX_PARAMETER_LENGTH     157


/* ----------------------------------------------------------------------------- */

/* CI_MSG Primitive ID definitions */

/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_MSG_PRIM {
    CI_MSG_PRIM_GET_SUPPORTED_SERVICES_REQ=1,		/**< \brief Requests to get a list of the SMS services supported by the cellular subsystem \details  */
    CI_MSG_PRIM_GET_SUPPORTED_SERVICES_CNF,			/**< \brief Confirms a request and gets a list of the SMS services supported by the cellular subsystem \details  */
    CI_MSG_PRIM_SELECT_SERVICE_REQ,					/**< \brief Requests to select an SMS messaging service \details  */
    CI_MSG_PRIM_SELECT_SERVICE_CNF,					/**< \brief Confirms a request and selects an SMS messaging service \details  */
    CI_MSG_PRIM_GET_CURRENT_SERVICE_INFO_REQ,		/**< \brief Requests information about the currently selected SMS messaging service \details  */
    CI_MSG_PRIM_GET_CURRENT_SERVICE_INFO_CNF,		/**< \brief Confirms a request and returns information about the selected SMS messaging service \details  */
    CI_MSG_PRIM_GET_SUPPORTED_STORAGES_REQ,		/**< \brief Requests to get information about the memory storages supported for read, write, and receive related operations
												 * \details  */
    CI_MSG_PRIM_GET_SUPPORTED_STORAGES_CNF,		/**< \brief Confirms a request and returns a list of supported memory storage options for read, write, and receive related operations \details  */

    CI_MSG_PRIM_SELECT_STORAGE_REQ,					/**< \brief Requests to select memory storage for a specified memory storage operation (read, write or receive)
													 * \details Regardless of the storage type selected for storage operation CI_MSG_STRGOPERTYPE_RECV,
													 * received CBMs are always stored in CI_MSG_STORAGE_BM and
													 * received status reports are stored in CI_MSG_STORAGE_SR.
													 * The only exception is when message indication is configured by CI_MSG_PRIM_CONFIG_MSG_IND_REQ
													 *  to forward status reports to the application subsystem. */
    CI_MSG_PRIM_SELECT_STORAGE_CNF,					/**< \brief Confirms a request and selects memory storage for the requested memory storage operation
													 * \details Regardless of the storage type selected for storage operation CI_MSG_STRGOPERTYPE_RECV,
													 * received CBMs are always stored in CI_MSG_STORAGE_BM and
													 * received status reports are stored in CI_MSG_STORAGE_SR.
													 * The only exception is when message indication is configured by CI_MSG_PRIM_CONFIG_MSG_IND_REQ
													 *  to forward the status reports to the application subsystem.  */
    CI_MSG_PRIM_GET_CURRENT_STORAGE_INFO_REQ,		/**< \brief Requests information about the current memory storage being used for read, write, and receive related operations \details  */
    CI_MSG_PRIM_GET_CURRENT_STORAGE_INFO_CNF,		/**< \brief Confirms a request and returns information about the current memory storage being used for read, write, and receive related operations \details  */
    CI_MSG_PRIM_READ_MESSAGE_REQ,					/**< \brief Requests to read a message
													 * \details The memory storage, on which the read access operates, is determined by CI_MSG_PRIM_SELECT_STORAGE_REQ with type set
  *  to CI_MSG_STRGOPERTYPE_READ_DELETE. The message can be an SMS message or CB message, depending on the type of memory storage.
													 * This primitive is used only for messages that are stored in SIM. */
    CI_MSG_PRIM_READ_MESSAGE_CNF,					/**< \brief Confirms a request and returns the stored message \details The application subsystem must be able to understand a PDU formatted according to TS 23.040 and TS 23.041.
  *  If the message read is an SMS message, pData consists of the TS 24.011 SC address followed by TS 23.040 TPDU; if the message read is a CBS message, pData consists of TS 23.041 TPDU. */
    CI_MSG_PRIM_DELETE_MESSAGE_REQ,					/**< \brief Requests to delete messages from the selected memory storage \details The memory storage, on which the delete access operates, is determined by CI_MSG_PRIM_SELECT_STORAGE_REQ with type
  *  set to CI_MSG_STRGOPERTYPE_READ_DELETE. Either SMS messages or CB messages can be deleted, depending on the type of memory storage.
													 * This primitive is used only for messages that are stored in SIM. */
    CI_MSG_PRIM_DELETE_MESSAGE_CNF,					/**< \brief Confirms a request and deletes the specified messages \details  */
    CI_MSG_PRIM_SEND_MESSAGE_REQ,					/**< \brief Requests to send an SMS message to the SMSC
													 * \details This primitive is used to send an SMS message of type SMS-SUBMIT.
													 * Refer to 3GPP TS 23.040 section 9.2.2.2.*/
    CI_MSG_PRIM_SEND_MESSAGE_CNF,					/**< \brief Confirms a request and sends an SMS message to the SMSC \details  */
    CI_MSG_PRIM_WRITE_MESSAGE_REQ,					/**< \brief Requests to store an SMS message on the selected memory storage with operation type CI_MSG_STRGOPERTYPE_WRITE_SEND \details The stored SMS message can be either CI_MSG_MSG_TYPE_SUBMIT or CI_MSG_MSG_TYPE_COMMAND. For more information, refer to
  *  TS 23.040 v3.8.0 9.2.2.2 and 9.2.2.4. This primitive is used only for messages that are stored in SIM.*/
    CI_MSG_PRIM_WRITE_MESSAGE_CNF,					/**< \brief Confirms a request and stores an SMS message on the selected memory storage with operation type CI_MSG_STRGOPERTYPE_WRITE_SEND \details  */
    CI_MSG_PRIM_SEND_COMMAND_REQ,					/**< \brief Requests to send an SMS command message to the SMSC
													 * \details This primitive is used to send an SMS message of type SMS-COMMAND,
													 * refer to 3GPP TS 23.040 section  9.2.2.4. */
    CI_MSG_PRIM_SEND_COMMAND_CNF,					/**< \brief Confirms a request and sends an SMS command message to the SMSC \details  */
    CI_MSG_PRIM_SEND_STORED_MESSAGE_REQ,			/**< \brief Requests to send a stored SMS message in the selected memory storage to the SMSC with operation type CI_MSG_STRGOPERTYPE_WRITE_SEND
													 * \details This primitive is used only for messages that are stored in SIM.  */
    CI_MSG_PRIM_SEND_STORED_MESSAGE_CNF,			/**< \brief Confirms a request and sends a stored SMS message in the selected memory storage to the SMSC with operation type CI_MSG_STRGOPERTYPE_WRITE_SEND \details  */
    CI_MSG_PRIM_CONFIG_MSG_IND_REQ,					/**< \brief Requests to configure whether received messages should be indicated, and, if so, how
													 * \details For SMS-deliver messages, CBM messages, and SMS-STATUS-REPORT messages, the default setting is CI_MSG_MSG_IND_DISABLE.
													 * Selecting one of the enable options also defines the message storage option for received messages.
													 * CI_MSG_MSG_IND_INDEX indicates that received messages will be stored in SIM by the communication subsystem.
													 * CI_MSG_MSG_IND_MSG or CI_MSG_MSG_IND_CLASS3_MSG indicates that received messages will be forwarded to the application subsystem for storage. */
    CI_MSG_PRIM_CONFIG_MSG_IND_CNF,					/**< \brief Confirms a request to configure message indications \details  */
    CI_MSG_PRIM_NEWMSG_INDEX_IND,					/**< \brief Indicates that an SMS message was received and stored on the cellular side
													 * \details This is applicable only when message indication configuration is CI_MSG_MSG_IND_INDEX (see CI_MSG_PRIM_CONFIG_MSG_IND_REQ). */
    CI_MSG_PRIM_NEWMSG_IND,							/**< \brief Indicates that an SMS message was received and forwards the messages to the application
													 * \details This is applicable only when message indication configuration is CI_MSG_MSG_IND_MSG (see CI_MSG_PRIM_CONFIG_MSG_IND_REQ).
													 * The message is not stored by the communication subsystem. */
    CI_MSG_PRIM_NEWMSG_RSP,							/**< \brief Responds by acknowledging the reception of an SMS message from CI_MSG_PRIM_NEWMSG_IND \details This is applicable only when the cellular subsystem supports the CI_MSG_SERVICE_WITH_ACK service and CI_MSG_MSG_IND_MSG is enabled.
  *  If ME does not get an acknowledgement within the required time (network timeout), ME sends RP-ERROR to the network. */
    CI_MSG_PRIM_GET_SMSC_ADDR_REQ,					/**< \brief Requests the SMSC address, through which mobile originated SMSs are transmitted \details  */
    CI_MSG_PRIM_GET_SMSC_ADDR_CNF,					/**< \brief Confirms a request and returns the SMSC address \details  */
    CI_MSG_PRIM_SET_SMSC_ADDR_REQ,					/**< \brief Requests to set the SMSC address, through which mobile originated SMSs are transmitted \details  */
    CI_MSG_PRIM_SET_SMSC_ADDR_CNF,					/**< \brief Confirms a request and sets the SMSC address \details  */
    CI_MSG_PRIM_GET_MOSMS_SERVICE_CAP_REQ,			/**< \brief Requests to get the MO SMS service capability \details  */
    CI_MSG_PRIM_GET_MOSMS_SERVICE_CAP_CNF,			/**< \brief Confirms a request and returns the MO SMS service capability \details  */
    CI_MSG_PRIM_GET_MOSMS_SERVICE_REQ,				/**< \brief Requests to get the current MO SMS service configuration \details  */
    CI_MSG_PRIM_GET_MOSMS_SERVICE_CNF,				/**< \brief Confirms a request and returns the current MO SMS service configuration \details  */
    CI_MSG_PRIM_SET_MOSMS_SERVICE_REQ,				/**< \brief Requests to set the MO SMS service configuration \details  */
    CI_MSG_PRIM_SET_MOSMS_SERVICE_CNF,				/**< \brief Confirms a request and sets the MO SMS service configuration \details  */
    CI_MSG_PRIM_GET_CBM_TYPES_CAP_REQ,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_MSG_PRIM_GET_CBM_TYPES_CAP_CNF,				/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_MSG_PRIM_GET_CBM_TYPES_REQ,					/**< \brief Requests to get the current CBM types setting \details  */
    CI_MSG_PRIM_GET_CBM_TYPES_CNF,					/**< \brief Confirms a request and returns the current CBM types setting \details  */
    CI_MSG_PRIM_SET_CBM_TYPES_REQ,					/**< \brief Requests to set the CBM types setting, which determines what type of CBMs are to be received by the client \details  */
    CI_MSG_PRIM_SET_CBM_TYPES_CNF,					/**< \brief Confirms a request and sets the CBM types setting \details  */
    CI_MSG_PRIM_SELECT_STORAGES_REQ,				/**< \brief Requests to select memory storage for read, write, and receive related operations \details For type CI_MSG_STRGOPERTYPE_RECV, regardless of the storage selected, received CBMs are always stored in
  *   CI_MSG_STORAGE_BM. Received status reports are always stored in CI_MSG_STORAGE_SR unless
  *   CI_MSG_PRIM_CONFIG_MSG_IND_REQ requests received messages to be forwarded to the application subsystem directly without
  *   storing them on the cellular side. */
    CI_MSG_PRIM_SELECT_STORAGES_CNF,					/**< \brief Confirms a request and selects memory storage for read, write, and receive related operations \details The cellular subsystem must have a set of default storage locations for different types of storage operations. */

    CI_MSG_PRIM_WRITE_MSG_WITH_INDEX_REQ,			/**< \brief Requests to write a message to the current storage, given an index
													 * \details This primitive is used only for messages that are stored in SIM. */
    CI_MSG_PRIM_WRITE_MSG_WITH_INDEX_CNF,			/**< \brief Confirms a request and writes a message to the current storage, given an index \details  */

    CI_MSG_PRIM_MESSAGE_WAITING_IND,					/**< \brief Indicates that there is a message waiting
														 * \details Refer to 3GPP TS 23.040 for details regarding the message waiting service.
														 * "The Messages Waiting is the service element that enables the PLMN to
 * provide the HLR, SGSN and VLR with which the recipient MS is associated with the information
 * that there is a message in the originating SC waiting to be delivered to the MS. The service
 * element is only used in case of previous unsuccessful delivery attempt(s) due to temporarily
 * absent mobile or MS memory capacity exceeded."
 * "There are three levels of "Message Waiting" indication: The first level is to set the
 * Protocol Identifier to "Return Call message". The second level uses the Data Coding Scheme
 * TP_DCS (see 3GPP TS 23.038) to indicate the type of message waiting and whether there are
 * some messages or no messages. The third level provides the maximum detail level for analysis by
 * the mobile and is extracted from TP_UDH; this information shall be stored by the ME in the
 * Message Waiting Indication Status (EF_MWIS file) on the SIM (see 3GPP TS 51.011) or
 * USIM (see 3GPP TS 31.102) when present or otherwise should be stored in the ME." \n
 * \n
 * Message waiting status information can be provided in the TC_DCS or TC_UDH of
 * SMS_DELIVER, SMS_SUBMIT_REPORT, and SMS_STATUS_REPORT messages, as
 * specified in TS 23.040 (section 9.2.3.24.2 Special SMS Message Indication) and
 * TS 23.038 (section 4. SMS Data Coding Scheme). Where disagreement occurs, TP_UDH
 * overrides the TP_DCS. \n
 * \n
 * The indicationActive field provides the indication sense (how it is presented to the user)
 * for the message waiting status on systems connected to the GSM/UMTS PLMN. It is specified
 * only by TP_DCS.
 * The msgCount field is specified only through TP_UDH. When only TP_DCS is provided, the
 * msgCount is set to zero (0). (Currently it is always set to zero because the protocol stack
 * doesn't support the third level of MWI.) */
    CI_MSG_PRIM_STORAGE_STATUS_IND,					/**< \brief Indicates a status change in short message storage  \details The notification is sent when a change occurs in any of the
 * parameters listed in the primitive definition. SAC maintains
 * the current values of these parameters and checks their status
 * when it receives any of the following protocol stack signals:
 * SmsReadyInd, SmsStatusCnf, SmsReadCnf, SmsDeliveryInd, SmsStoreInd,
 * SmsMsgReceivedInd, SmsDeleteCnf, or SmsRecordChangedInd.
 * The memCapExceeded and usedRecords parameters are specified in
 * each of these signals; the other parameters are specified by the SmsReadyInd
 * and SmsStatusCnf signals. \n
 *
 * The name of the primitive parameters is as per the 3GPP spec and the actual
 * information can be retrieved from the SIM card by reading the EF_SMS and EF_SMSS. */

    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_MSG_PRIM_LAST_COMMON_PRIM' */
/*Michal Bukai - SMS Full Feature*/
    CI_MSG_PRIM_RESET_MEMCAP_FULL_REQ,  /**< \brief Requests to reset memory full status. \details The PS will send the networkan indication that there is enough memory to send at least one SMS. The network can start forwarding the pending messages that were held due to memory full status  */
	CI_MSG_PRIM_RESET_MEMCAP_FULL_CNF, /**< \brief Confirm the request to reset memory full status. \details */

    CI_MSG_PRIM_SET_RECORD_STATUS_REQ,  /**<\brief Requests to set RECORD status. \details The PS will update its cache with the  status to sync-up with AP  */
    CI_MSG_PRIM_SET_RECORD_STATUS_CNF,  /**<\brief confirm the requst to set RECORD status. \details  */

    CI_MSG_PRIM_SET_FILTER_STATUS_REQ,  /**< \brief Sets a CBM filter setting that decides which types of CBMs are to be received by the client \details  */
    CI_MSG_PRIM_SET_FILTER_STATUS_CNF,  /**< \brief Confirms a request to set the CBM filter \details  */
    CI_MSG_PRIM_GET_FILTER_STATUS_REQ,  /**< \brief gets a CBM filter setting that decides which types of CBMs are to be received by the client \details  */
    CI_MSG_PRIM_GET_FILTER_STATUS_CNF,  /**< \brief Confirms a request to get the CBM filter \details  */

    CI_MSG_PRIM_LOCK_SMS_STATUS_REQ,    /**<\brief Requests to set RECORD status. \details The PS will update its cache with the  status to sync-up with AP  */
    CI_MSG_PRIM_LOCK_SMS_STATUS_CNF,    /**<\brief confirm the requst to set RECORD status. \details  */

    CI_MSG_PRIM_GET_MSG_IND_CONFIG_REQ, /**< \brief Requests to read the selected message indication configuration. \details */
    CI_MSG_PRIM_GET_MSG_IND_CONFIG_CNF, /**< \brief Confirms a request and returns the selected message indication configuration. 
										The message indication configuration also defines the message storage option for received messages. 
										CI_MSG_MSG_IND_INDEX indicates that received messages will be stored in SIM by the communication subsystem. 
										CI_MSG_MSG_IND_MSG or CI_MSG_MSG_IND_CLASS3_MSG indicates that received messages will be forwarded to 
										the application subsystem for storage \details */

	CI_MSG_PRIM_GET_SMSC_PARAMS_REQ,	/**< \brief Requests the SMSC additional parameters */
	CI_MSG_PRIM_GET_SMSC_PARAMS_CNF,	/**< \brief Confirms a request and returns the SMSC parameters */
	CI_MSG_PRIM_SET_SMSC_PARAMS_REQ,	/**< \brief Requests to set the SMSC parameters */
	CI_MSG_PRIM_SET_SMSC_PARAMS_CNF,	/**< \brief Confirms a request and sets the SMSC parameters */
	CI_MSG_PRIM_SET_CB_RAT_REQ,          /*brief requests to set CB on/off on RAT*/ 
    CI_MSG_PRIM_SET_CB_RAT_CNF,          /*brief comfirm to the request*/
	
	CI_MSG_PRIM_GET_STORED_SMS_STATUS_REQ,	/**<\brief  */		
	CI_MSG_PRIM_GET_STORED_SMS_STATUS_CNF,	/**<\brief */				
	CI_MSG_PRIM_GET_SMS_STATUS_REQ,			/**<\brief */		 
	CI_MSG_PRIM_GET_SMS_STATUS_CNF, 		/**<\brief  */		
	CI_MSG_PRIM_SET_SMS_STATUS_REQ, 		/**<\brief  */			
	CI_MSG_PRIM_SET_SMS_STATUS_CNF, 		/**<\brief  */	
	CI_MSG_PRIM_GET_PARAMETER_COUNT_STATUS_REQ,		/**<\brief  */
	CI_MSG_PRIM_GET_PARAMETER_COUNT_STATUS_CNF,		/**<\brief  */
	CI_MSG_PRIM_SET_PARAMETER_REQ,				    /**<\brief  */
	CI_MSG_PRIM_SET_PARAMETER_CNF,					/**<\brief  */
	CI_MSG_PRIM_GET_PARAMETER_REQ, 					/**<\brief  */
	CI_MSG_PRIM_GET_PARAMETER_CNF,					/**<\brief  */

	/*CQ00134417,sms config retry timer and retey number, 20211215,perse,begin*/
    CI_MSG_PRIM_SET_SM_RESEND_PARA_REQ, 			/**<\brief  */
    CI_MSG_PRIM_SET_SM_RESEND_PARA_CNF,				/**<\brief  */
    CI_MSG_PRIM_GET_SM_RESEND_PARA_REQ,             /**<\brief  */
    CI_MSG_PRIM_GET_SM_RESEND_PARA_CNF,             /**<\brief  */
	/*CQ00134417,sms config retry timer and retey number, 20211215,perse,end*/

    /* END OF COMMON PRIMITIVES LIST */
    CI_MSG_PRIM_LAST_COMMON_PRIM

    /* the  customer specific extension primitives will be added starting from
    * CI_MSG_PRIM_firstCustPrim = CI_MSG_PRIM_LAST_COMMON_PRIM as the first identifier.
    * The actual primitive names and IDs are defined in the associated
    * 'ci_msg_cust_xxx.h' file.
    */

    /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiMsgPrim;

/* specify the number of default common DEV primitives */
#define CI_MSG_NUM_COMMON_PRIM ( CI_MSG_PRIM_LAST_COMMON_PRIM - 1 )
/**@}*/

/** \brief  Service types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGSERVICE_TAG{
    CI_MSG_SERVICE_NORMAL = 0,          		/**< Application subsystem does NOT acknowledge receipt of messages routed
                                           						directly from the cellular subsystem */
    CI_MSG_SERVICE_WITH_ACK,            		/**< Application subsystem acknowledges receipt of messages routed
                                           						directly from the cellular subsystem */
    CI_MSG_SERVICE_MANUFACTURER = 128   	/**< 	Manufacturer specific */
} _CiMsgService;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Service types
 * \sa CIMSGSERVICE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgService;

/* specify the number of default common DEV primitives */
#define CI_MSG_SERVICE_MAX 3 /*This is a hard coded value of the number of message services that are enumerated*/
/**@}*/

/** \brief  Result codes  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_MSG_TAG{
    CIRC_MSG_SUCCESS = 0,               			/**< Request completed successfully */
    CIRC_MSG_FAIL,                      				/**< General failure (catch-all) */

    CIRC_MSG_SERVICEME_RESERVED = 301,  	/**< SMS service of ME reserved */
    CIRC_MSG_INVALID_PDU_PARAMETER,     	/**< Invalid PDU parameter */
    CIRC_MSG_PHSIM_PIN_REQUIRED,       		 /**< SIM personalization key (CPK) required  */
    CIRC_MSG_INVALID_MEM_INDEX,         		/**< Invalid memory index */
    CIRC_MSG_SIM_MEM_FULL,              		/**< SIM memory full */
    CIRC_MSG_SC_ADDR_UNKNOWN,           		/**< SC address unknown */
    CIRC_MSG_NO_ACK_EXPECTED,           		/**< No acknowledgement expected */
    CIRC_MSG_ERROR_UNSPEC,              		/**< SM_CAUSE_PROTOCOL_ERROR_UNSPEC */
    CIRC_MSG_FDN_FAILURE,               			/**< FDN failure */
    CIRC_MSG_OPERATION_IN_PROGRESS,     	/**< Request is rejected - a previous request is still in progress */

	CIRC_MSG_INVALID_PARAMETER,				/**< Generic error - the requested service primitive has invalid parameters */
	CIRC_MSG_INVALID_REQ,					/**< Generic error - the requested service primitive can not be handled at current state */
	CIRC_MSG_SIM_NOT_READY,					/**< Generic error - the requested service primitive fails because SIM is not ready */
	CIRC_MSG_ACCESS_DENIED,					/**< Generic error - the requested service primitive fails because access is denied */
	CIRC_MSG_FAIL_NO_RESPONSE,				/**< No response from network */

	CIRC_MSG_NUM_RESCODES               		/**< Number of result codes */
} _CiMsgRc;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Result codes
 * \sa CIRC_MSG_TAG */
/** \remarks Common Data Section */
typedef UINT16 CiMsgRc;
/**@}*/

/*Tal Porat/Michal Bukai - Network Selection*/

/** \brief  RP-Cause ( TC24.011 8.2.5.4 ). This element is a variable length element always included in the RP-ERROR message. */
/** \remarks Common Data Section */
typedef enum CIMSGRPCAUSE_TAG
{
	CI_MSG_RP_CAUSE_UNASSIGNED_NO 				=	1,			/**< Unassigned (unallocated) number */
	CI_MSG_RP_CAUSE_OPER_DETERM_BARRING		=	8,			/**< Operator determined barring */
	CI_MSG_RP_CAUSE_CALL_BARRED				=	10,			/**< Call barred */
	CI_MSG_RP_CAUSE_RESERVED					=	11,			/**< Reserved */
	CI_MSG_RP_CAUSE_CALL_REJECTED 				=	21,			/**< Short message transfer rejected */
	CI_MSG_RP_CAUSE_NUMBER_CHANGED			=	22, 		       /**< Memory capacity exceeded */
	CI_MSG_RP_CAUSE_DEST_OUT_OF_ORDER 		=	27,			/**< Destination out of order */
	CI_MSG_RP_CAUSE_INVALID_NO_FORMAT 			=	28,			/**< Unidentified subscriber */
	CI_MSG_RP_CAUSE_FACILITY_REJECTED 			=	29,			/**< Facility rejected */
	CI_MSG_RP_CAUSE_UNKNOWN_SUBSCRIBER 		=	30,			/**< Unknown subscriber */
	CI_MSG_RP_CAUSE_NET_OUT_OF_ORDER			=	38,			/**< Network out of order */
	CI_MSG_RP_CAUSE_TEMP_FAILURE				=	41,			/**< Temporary failure */
	CI_MSG_RP_CAUSE_SWITCH_CONGESTION 		=	42,			/**< Congestion */
	CI_MSG_RP_CAUSE_RESOURCES_UNAV			=	47,			/**< Resources unavailable, unspecified */
	CI_MSG_RP_CAUSE_REQ_FAC_NOT_SUBSCR		=	50,			/**< Requested facility not subscribed */
	CI_MSG_RP_CAUSE_REQ_FACIL_NOT_IMPL			=	69,			/**< Requested facility not implemented */
	CI_MSG_RP_CAUSE_INVALID_TI					=	81,			/**< Invalid short message transfer reference value */
	CI_MSG_RP_CAUSE_INVALID_MSG_SEMANTIC		=	95,			/**< Semantically incorrect message */
	CI_MSG_RP_CAUSE_MAND_IE_ERROR 				=	96,			/**< Invalid mandatory information */
	CI_MSG_RP_CAUSE_MSG_NONEXISTENT			=	97,			/**< Message type non-existent or not implemented */
	CI_MSG_RP_CAUSE_MSG_GEN_ERROR 			=	98,			/**< Message not compatible with short message protocol state */
	CI_MSG_RP_CAUSE_IE_NONEXISTENT				=	99,			/**< Information element non-existent or not implemented */
	CI_MSG_RP_CAUSE_PROTOCOL_ERROR			=	111,		/**< Protocol error, unspecified */
	CI_MSG_RP_CAUSE_INTERWORKING				=	127,		/**< Interworking, unspecified */

	CI_MSG_RP_CAUSE_MM_NO_CS_SERVICE                =   0x3203,  /**< Internal cause for no CS service */
	
	CI_MSG_RP_CAUSE_ALIGN_32_BIT					=	0XFFFF		/**< Used for alignment */
} _CiMsgRpCause;

/* TP Failure-Cause */
typedef enum CiMSGTPFAILURECAUSE_TAG
{
   /*
   ** Protocol Id Errors
   */
   CI_MSG_TP_TELEMATIC_NOT_SUPPORTED        	=   0x80,
   CI_MSG_TP_MSG_TYPE0_NOT_SUPPORTED,
   CI_MSG_TP_CANT_REPLACE_SHORT_MSG,
   CI_MSG_TP_UNSPECIFIED_TPPID_ERROR        	=   0x8F,
   /*
   ** Data Coding Scheme Errors
   */
   CI_MSG_TP_ALPHABET_NOT_SUPPORTED         	=   0x90,
   CI_MSG_TP_MSG_CLASS_NOT_SUPPORTED,
   CI_MSG_TP_UNSPECIFIED_DATA_CODING_ERROR  =   0x9F,
   /*
   ** Command Errors
   */
   CI_MSG_TP_CANT_ACTION_COMMAND            		=   0xA0,
   CI_MSG_TP_UNSUPPORTED_COMMAND,
   CI_MSG_TP_UNSPECIFIED_COMMAND_ERROR      	=   0xAF,
   /*
   ** Other Errors
   */
   CI_MSG_TP_TPDU_NOT_SUPPORTED             		=   0xB0,

   CI_MSG_TP_SC_BUSY                        				=   0xC0,
   CI_MSG_TP_NO_SC_SUBSCRIPTION,
   CI_MSG_TP_SC_SYSTEM_FAILURE,
   CI_MSG_TP_INVALID_SME_ADDRESS,
   CI_MSG_TP_DESTINATION_SME_BARRED,
   CI_MSG_TP_SM_REJECTED_DUPLICATE_SM,

   CI_MSG_TP_SIM_STORAGE_FULL               		=   0xD0,
   CI_MSG_TP_SIM_NO_SMS_CAPABILITY,
   CI_MSG_TP_SIM_NO_CAPACITY                			=   0xD1,   		/**< REDUNDANT Do not use */
   CI_MSG_TP_ERROR_IN_MS,
   CI_MSG_TP_MEMORY_CAPACITY_EXCEEDED,
   CI_MSG_TP_SIM_APPLICATION_TOOLKIT_BUSY,
   CI_MSG_TP_SIM_DATA_DOWNLOAD_ERROR,

   CI_MSG_TP_UNSPECIFIED_ERROR              		=   0xFF,
   CI_MSG_TP_NO_ERROR                       			=   0x100,   		/**< internal code */
   CI_MSG_TP_CAUSE_ALIGN_32_BIT 				=   0XFFFF	   	/**< Used for alignment */
} _CiMsgTpFailureCause;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief TP failure - cause
 * \sa CIMSGRPCAUSE_TAG */
/** \remarks Common Data Section */
typedef UINT16 CiMsgCause;
/**@}*/

/** \brief Types of messages supported by the ME */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgMsgTypesInfo_struct{
    CiBoolean  mtSupported;  	/**< TRUE indicates mobile terminated messages are supported \sa CCI API Ref Manual */
    CiBoolean  moSupported;  	/**< TRUE indicates mobile originated messages supported  \sa CCI API Ref Manual */
    CiBoolean  bmSupported;  	/**< TRUE indicates broadcast messages are supported  \sa CCI API Ref Manual */
} CiMsgMsgTypesInfo;

/** \brief Message storage */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGSTORAGE_TAG{
    CI_MSG_STORAGE_BM = 0,  	/**< Broadcast message storage (in volatile memory) */
    CI_MSG_STORAGE_ME,      		/**< ME message storage */
    CI_MSG_STORAGE_MT,      		/**< Any of the storage locations associated with ME */
    CI_MSG_STORAGE_SM,      		/**< SIM message storage */
    CI_MSG_STORAGE_SR,      		/**< Status report storage */

    CI_MSG_NUM_STORAGES
} _CiMsgStorage;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message storage
 * \sa CIMSGSTORAGE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgStorage;
/**@}*/

/** \brief Storage operation types  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGSTORAGEOPERTYPE_TAG{
    CI_MSG_STRGOPERTYPE_READ_DELETE = 0,  	/**< Storage from which messages are read and deleted, default SIM */
    CI_MSG_STRGOPERTYPE_WRITE_SEND,      	/**< Storage to which write and send operations are directed */
    CI_MSG_STRGOPERTYPE_RECV,            	/**< The preferred storage for received SMS  */

    CI_MSG_NUM_STRGOPERTYPES
} _CiMsgStorageOperType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Storage operation types
 * \sa CIMSGSTORAGEOPERTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgStorageOperType;
/**@}*/

/** \brief Storage list information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgStorageList_struct{
    UINT8           len;                  					/**< [1..CI_MSG_NUM_STORAGES] */
    CiMsgStorage    storageList[CI_MSG_NUM_STORAGES];		 /**< Message storage list \sa CiMsgStorage */
} CiMsgStorageList;

/** \brief Message storage information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgStorageInfo_struct{
    CiMsgStorage 	storage; 		/**< Memory storage  \sa CiMsgStorage */
    UINT16 		used;           	/**< Number of used message locations in storage */
    UINT16 		total;          	/**< Total number of message locations in storage */
}CiMsgStorageInfo;

/** \brief Message storage setting information structure */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgStorageSetting_struct{
    CiMsgStorageInfo 	setting[CI_MSG_NUM_STRGOPERTYPES];	/**< Message storage information \sa CiMsgStorageInfo */
} CiMsgStorageSetting;

/** \brief Message types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGMSGTYPE_TAG{
    CI_MSG_MSG_TYPE_DELIVER = 0,    			/**<SMS-DELIVER PDU */
    CI_MSG_MSG_TYPE_DELIVER_REPORT, 		/**< SMS-DELIVER-REPORT PDU */
    CI_MSG_MSG_TYPE_SUBMIT,         			/**< SMS-SUBMIT PDU */
    CI_MSG_MSG_TYPE_SUBMIT_REPORT,  		/**< SMS-SUBMIT-REPORT PDU */
    CI_MSG_MSG_TYPE_STATUS_REPORT,  		/**< SMS-STATUS-REPORT PDU */
    CI_MSG_MSG_TYPE_COMMAND,        		/**< SMS-COMMAND PDU */
    CI_MSG_MSG_TYPE_CBS,            			/**< CBS PDU */
    CI_MSG_MSG_TYPE_ETWS_PRIMARY_NOTIFICATION,/**< LTE CBS PDU */
    CI_MSG_MSG_TYPE_ETWS_SECONDARY_NOTIFICATION,/**< LTE CBS PDU */
    CI_MSG_MSG_TYPE_CMAS_NOTIFICATION,/**< LTE CBS PDU */
    
    CI_MSG_MSG_NUM_TYPES
} _CiMsgMsgType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message types
 * \sa CIMSGMSGTYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMsgType;
/**@}*/

/** \brief Status of the message */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGMSGSTATUS_TAG{
    CI_MSG_MSG_STAT_REC_UNREAD = 0, 		/**< Received unread message */
    CI_MSG_MSG_STAT_READ,           			/**< Received read message */
    CI_MSG_MSG_STAT_STO_UNSENT,     		/**< Stored unsent message (only applicable to SMS) */
    CI_MSG_MSG_STAT_STO_SENT,       			/**< Stored sent message (only applicable to SMS) */
    CI_MSG_MSG_STAT_ALL,            			/**< All messages */
    CI_MSG_MSG_STAT_REC_EMPTY,      		/**< SCR1623261: added to correct the empty slot read problem */

    CI_MSG_MSG_NUM_STAT
} _CiMsgMsgStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Status of the message
 * \sa CIMSGMSGSTATUS_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMsgStatus;
/**@}*/

/** \brief ETWS warning type*/
//ICAT EXPORTED ENUM
typedef enum CIETWSWARNINGTYPE_TAG{
  CI_WARNING_TYPE_EARTHQUAKE,
  CI_WARNING_TYPE_TSUNAMI,
  CI_WARNING_TYPE_EARTHQUAKE_TSUNAMI,
  CI_WARNING_TYPE_TEST,
  CI_WARNING_TYPE_OTHER,
  CI_WARNING_TYPE_RESERVED
}_CiEtwsWarningType;
typedef UINT8 CiEtwsWarningType;
/** \brief Message PDU */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPdu_struct{
    UINT16  len;        								/**< Length of the TPDU */
    UINT8   data[ CI_MAX_CI_MSG_PDU_SIZE ];		/**< TPDU (transfer protocol data unit) */
} CiMsgPdu;

/** \brief ETWS struct */
//ICAT EXPORTED STRUCT
typedef struct CiEtwsMsgInfo_struct{
    CiEtwsWarningType	warningType;
	CiBoolean				activateAlert;
	CiBoolean 			activatePopup;
} CiEtwsMsgInfo;

/** \brief Delete flags */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGMSGDELFLAG_TAG{
    CI_MSG_MSG_DELFLAG_INDEX=0,           			/**< Delete message at the specified index */
    CI_MSG_MSG_DELFLAG_ALL_READ,           			/**< Delete all messages that have been read */
    CI_MSG_MSG_DELFLAG_ALL_READ_OR_SENT,  		 /**< Delete all messages that have been read or sent */
    CI_MSG_MSG_DELFLAG_ALL_READ_OR_MO,     		/**< Delete all messages that have been read or are mobile originated */

    CI_MSG_MSG_NUM_DELFLAGS
} _CiMsgMsgDelFlag;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Common data section
 * \sa CIMSGMSGDELFLAG_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMsgDelFlag;
/**@}*/

/** \brief Message indication settings  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGMSGINDSETTING_TAG{
    CI_MSG_MSG_IND_DISABLE=0, 			/**< Store the received message on the cellular side;
                                 				  disable indication that a new message was received. */
    CI_MSG_MSG_IND_INDEX,     			/**< Store the received message on the cellular side;
                                 				  indicate memory storage and memory location. */
    CI_MSG_MSG_IND_MSG,       			/**< Do not store the received message on the cellular side;
                                 				  forward the message to the application side directly. */
    CI_MSG_MSG_IND_CLASS3_MSG,		/**< Do not store a CLASS 3 message (SM/CBM) on the
                                 				 cellular side; forward the message to the application side directly. */
    CI_MSG_MSG_NUM_INDS
} _CiMsgMsgIndSetting;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message indication settings
 * \sa CIMSGMSGINDSETTING_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMsgIndSetting;
/**@}*/

/** \brief MO SMS service information  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIMSGMOSMSSRVCFG_TAG{
    CI_MSG_MOSMS_SRV_PS = 0,        				/**< PS domain */
    CI_MSG_MOSMS_SRV_CS,            				/**< CS domain */
    CI_MSG_MOSMS_SRV_PS_PREFERRED,  			/**< PS preferred, use CS if PS not available */
    CI_MSG_MOSMS_SRV_CS_PREFERRED,  			/**< CS preferred, use PS if CS not available */
    CI_MSG_MOSMS_NUM_SRVS
} _CiMsgMoSmsSrvCfg;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief MO SMS service information
 * \sa CIMSGMOSMSSRVCFG_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMoSmsSrvCfg;
/**@}*/

//ICAT EXPORTED ENUM
typedef enum CiMsgCbModeType_TAG{
    CI_MSG_CB_MODE_ADD = 0,        		/**< Add */
    CI_MSG_CB_MODE_DELETE,            	/**< Delete */
    CI_MSG_CB_MODE_REPLACE,  			/**< Replace */
    CI_MSG_CB_MODE_NUM,
} _CiMsgCBSModeType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Update mode of CBMI and DCSS lists */
/** \remarks Common Data Section */
typedef UINT8 CiMsgCBSModeType;
/**@}*/

/** \brief CBM message types set information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiMsgCbmTypesSet_struct{
    CiMsgCBSModeType    mode; 			/**< Mode; 0 -Add, 1 - Delete, 2 - Replace \sa CCI API Ref Manual */
    CiNumericList 		mids; 			/**< CBM message identifiers, see 3GPP TS 23.041 section 9.4.1.2.2 \sa CCI API Ref Manual */
    CiNumericList dcss; 			/**< CBM data coding schemes, see 3GPP TS 23.038 section 5 \sa CCI API Ref Manual */
} CiMsgCbmTypesSet;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SUPPORTED_SERVICES_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetSupportedServicesReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SUPPORTED_SERVICES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSupportedServicesCnf_struct{
    CiMsgRc         			rc;									/**< Result code \sa CiMsgRc */
    UINT8           			len;									/**< Length of the supported SMS services list [1- CI_MSG_MAX_SUPPORTED_SERVICES] */
    CiMsgService   			serviceLst[CI_MSG_SERVICE_MAX];		/**< Supported SMS services list \sa CiMsgService */
} CiMsgPrimGetSupportedServicesCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_SERVICE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectServiceReq_struct{
    CiMsgService        service;			/**< SMS message service \sa CiMsgService */
} CiMsgPrimSelectServiceReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_SERVICE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectServiceCnf_struct{
    CiMsgRc             		rc;					/**<  Result code applicable values are CIRC_MSG_SUCCESS or CIRC_MSG_SERVICEME_RESERVED \sa CiMsgRc  */
    CiMsgMsgTypesInfo   	msgTypesInfo;		/**< Types of messages supported, optional if rc is not CIRC_MSG_SUCCESS \sa CiMsgMsgTypesInfo_struct */
} CiMsgPrimSelectServiceCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CURRENT_SERVICE_INFO_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetCurrentServiceInfoReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CURRENT_SERVICE_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetCurrentServiceInfoCnf_struct{
    CiMsgRc             			rc;				/**< Result code \sa CiMsgRc */
    CiMsgService       		 	service;			/**< Current SMS service setting \sa CiMsgService */
    CiMsgMsgTypesInfo   		msgTypesInfo;	/**< Types of messages supported by current SMS messaging service \sa CiMsgMsgTypesInfo_struct  */
} CiMsgPrimGetCurrentServiceInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SUPPORTED_STORAGES_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetSupportedStoragesReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SUPPORTED_STORAGES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSupportedStoragesCnf_struct{
    CiMsgRc            		rc;										/**< Result code  \sa CiMsgRc */
    UINT8              			len;								/**< Length of storage lists */
    CiMsgStorageList   lists[ CI_MSG_NUM_STRGOPERTYPES ];  /**< Lists types of SMS storage supported \sa CiMsgStorageList_struct */
} CiMsgPrimGetSupportedStoragesCnf;


/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_STORAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectStorageReq_struct{
    CiMsgStorageOperType 	type;		/**< Storage operation type \sa CiMsgStorageOperType */
    CiMsgStorage         		storage;		/**< Storage to be associated with the storage operation type \sa CiMsgStorage */
} CiMsgPrimSelectStorageReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_STORAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectStorageCnf_struct{
    CiMsgRc               		rc;			/**< Result code \sa CiMsgRc */
    CiMsgStorageSetting   	set;			/**< Set of memory storage information being used, optional when rc is not CIRC_MSG_SUCCESS \sa CiMsgStorageSetting_struct */
} CiMsgPrimSelectStorageCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CURRENT_STORAGE_INFO_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetCurrentStorageInfoReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CURRENT_STORAGE_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetCurrentStorageInfoCnf_struct{
    CiMsgRc           		rc;					/**< Result code  \sa CiMsgRc */
    CiMsgStorageSetting   	set;					/**< Current memory storage being used \sa CiMsgStorageSetting_struct */
} CiMsgPrimGetCurrentStorageInfoCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_READ_MESSAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimReadMessageReq_struct{
    UINT16 index;		/**< Index for memory storage */
} CiMsgPrimReadMessageReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_READ_MESSAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimReadMessageCnf_struct{
    CiMsgRc   			rc;						/**< Result code  \sa CiMsgRc */
    UINT8     			status;					/**< Status of the message \sa CiMsgMsgStatus */
    CiBoolean 			pduPresent;				/**< TRUE - if present \sa CCI API Ref Manual */
    CiMsgPdu  			pdu;					/**< Message that was read  \sa CiMsgPdu_struct */
    CiOptAddressInfo  	optSca;   				/**< Optional service center address \sa CCI API Ref Manual */
										/* SCR #1777605: */
} CiMsgPrimReadMessageCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_DELETE_MESSAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimDeleteMessageReq_struct{
    CiMsgMsgDelFlag   	flag;		/**< Delete flag, default: CI_MSG_MSG_DELFLAG_INDEX \sa CiMsgMsgDelFlag */
    UINT16            		index;		/**< Index, ignored if flag is not CI_MSG_MSG_DELFLAG_INDEX */
} CiMsgPrimDeleteMessageReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_DELETE_MESSAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimDeleteMessageCnf_struct{
    CiMsgRc rc;		/**< Result code  \sa CiMsgRc */
} CiMsgPrimDeleteMessageCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_MESSAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendMessageReq_struct
{
    CiMsgPdu  		pdu;				/**< Message that was sent \sa CiMsgPdu_struct */
    CiBoolean 			bMoreMessage;		/**< TRUE: send SIG_APEX_SM_SEND_MORE_REQ to PS \sa CCI API Ref Manual */
    UINT8     			res1U8[3];     			/**< padding */
    CiOptAddressInfo  	optSca;   			/**< Optional service center address \sa CCI API Ref Manual */
											/*--------5/26/2009 1:57PM--------
											 * SCR #1777605:
											 * --------------------------------*/

} CiMsgPrimSendMessageReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_MESSAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendMessageCnf_struct{
    CiMsgRc   rc;	/**< Result code  \sa CiMsgRc */
    UINT8     reference;	/**< TP-Message-Reference */
	/*Tal Porat/Michal Bukai - Network Selection*/
	UINT8     res1U8;     /**< padding */
	CiMsgCause	rpCause;	/**< Short message air interface reject cause - RP-cause \sa CiMsgRpCause */
	CiMsgCause	tpCause;		/**< Short message air interface reject cause - transport cause \sa CiMsgTpFailureCause */
	/*Tal Porat/Michal Bukai - Network Selection*/
    CiBoolean 			ackPduPresent;		/**< TRUE: if present \sa CCI API Ref Manual */
    CiMsgPdu  		ackPdu;				/**< RP-User-Data element of RP-ACK PDU (SMS-SUBMIT-REPORT TPDU for RP-ACK); refer
                                                          *    to TS 23.040 v3.8.0 9.2.2.2a. Valid when CI_MSG_SERVICE_WITH_ACK is enabled and
                                                          *    network supports it. \sa CiMsgPdu_struct*/
} CiMsgPrimSendMessageCnf;



/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_WRITE_MESSAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimWriteMessageReq_struct{
   	CiMsgPdu  		pdu;    					/**< PDU data structure \sa CiMsgPdu_struct */
	CiMsgMsgStatus    status;					/**< Message status to be set with the message \sa CiMsgMsgStatus */
	CiBoolean 		statusPresent;			/**< TRUE: if present \sa CCI API Ref Manual  */
	UINT8     			res1U8[2];				/**< padding */
	CiOptAddressInfo  optSca;  					/**< Optional service center address \sa CCI API Ref Manual  */
} CiMsgPrimWriteMessageReq;

/* <INUSE> */
/** CI_MSG_PRIM_WRITE_MESSAGE_CNF - Confirmation of storing an SMS message to the selected memory storage with operation type CI_MSG_STRGOPERTYPE_WRITE_SEND
*/
/** <paramref name="CI_MSG_PRIM_WRITE_MESSAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimWriteMessageCnf_struct{
    CiMsgRc 			rc;						/**< Result code  \sa CiMsgRc */
    UINT16 			index;					/**< Memory location of the stored message */
} CiMsgPrimWriteMessageCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_COMMAND_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendCommandReq_struct{
     CiMsgPdu  	pdu;		/**< Message that was sent  \sa CiMsgPdu_struct */
} CiMsgPrimSendCommandReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_COMMAND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendCommandCnf_struct{
    CiMsgRc   		rc;					/**< Result code  \sa CiMsgRc */
    UINT8     		reference;			/**< TP-Message-Reference, refer to TS 23.040 v3.8.0 9.2.3.6 */
    CiBoolean 		ackPduPresent;		/**< TRUE: if present  \sa CCI API Ref Manual */
    CiMsgPdu  	ackPdu;				/**< RP-User-Data element of RP-ACK PDU (SMS-SUBMIT-REPORT TPDU for RP-ACK); refer to
                                                    *  TS 23.040 v3.8.0 9.2.2.2a. Valid when CI_MSG_SERVICE_WITH_ACK is enabled and network
                                                    *  supports it. \sa CiMsgPdu_struct */
} CiMsgPrimSendCommandCnf;



/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_STORED_MESSAGE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendStoredMessageReq_struct
{
    CiAddressInfo  		destAddr;	/**<Optional, TP-Destination-Address, to replace the address in the stored message \sa CCI API Ref Manual */
	UINT16         		index;				/**< Memory location */
    CiBoolean      		bMoreMessage;		/**< TRUE: send SIG_APEX_SM_SEND_MORE_REQ to PS  \sa CCI API Ref Manual */
	CiBoolean      		destAddrPresent;		/**< Optional, TP-Destination-Address, used to replace the address in the stored message  \sa CCI API Ref Manual */
    CiOptAddressInfo  	optSca;  			/**< Optional service center address \sa CCI API Ref Manual */

} CiMsgPrimSendStoredMessageReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SEND_STORED_MESSAGE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSendStoredMessageCnf_struct{
    CiMsgRc   		rc;						/**< Result code  \sa CiMsgRc */
    UINT8     		reference;				/**< TP-Message-Reference, refer to TS 23.040 v3.8.0 9.2.3.6 */
	/*Tal Porat/Michal Bukai - Network Selection*/
	UINT8     res1U8;     /**< padding */
	CiMsgCause	rpCause;				/**< Short message air interface reject cause - RP-cause \sa CiMsgRpCause */
	CiMsgCause	tpCause;					/**< Short message air interface reject cause - transport cause \sa CiMsgTpFailureCause */
	/*Tal Porat/Michal Bukai - Network Selection*/
    CiBoolean 		ackPduPresent;			/**< TRUE: if present */
    CiMsgPdu  	ackPdu;					/**< RP-User-Data element of RP-ACK PDU (SMS-SUBMIT-REPORT TPDU for RP-ACK); refer to
                                                    	  *    TS 23.040 v3.8.0 9.2.2.2a. Valid when CI_MSG_SERVICE_WITH_ACK is enabled and network
                                                          *    supports it. \sa CiMsgPdu_struct*/
} CiMsgPrimSendStoredMessageCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_CONFIG_MSG_IND_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimConfigMsgIndReq_struct{
    CiMsgMsgIndSetting 	smsDeliverIndSetting;			/**< Indication setting for SMS-Deliver messages \sa CiMsgMsgIndSetting */
    CiMsgMsgIndSetting 	cbmIndSetting;				/**< Indication setting for CBM messages \sa CiMsgMsgIndSetting */
    CiMsgMsgIndSetting 	smsStatusReportIndSetting;	/**< Indication setting for SMS-STATUS-REPORT messages \sa CiMsgMsgIndSetting */
} CiMsgPrimConfigMsgIndReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_CONFIG_MSG_IND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimConfigMsgIndCnf_struct{
    CiMsgRc 				rc;							/**< Result code  \sa CiMsgRc */
} CiMsgPrimConfigMsgIndCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_NEWMSG_INDEX_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimNewMsgIndexInd_struct{
    CiMsgMsgType 		type;			/**< Type of new message received; values are CI_MSG_MSG_TYPE_DELIVER, CI_MSG_MSG_TYPE_STATUS_REPORT, and CI_MSG_MSG_TYPE_CBS \sa CiMsgMsgType */
    CiMsgStorage 		storage;			/**< Where message is stored \sa CiMsgStorage */
    UINT16        		index;			/**< Memory location */
} CiMsgPrimNewMsgIndexInd;

/** \brief  Message coding format */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CbCIMessageCoding_Tag
{
	CB_CI_DEFAULT_ALPHABET,   /**< Default 7 bit coding */
	CB_CI_8_BIT_DATA,         /**< 8 bit coding */
	CB_CI_UCS2_ALPHABET,      /**< UCS2 coding */
	CI_noMoreCodings
}_CbCIMessageCoding;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message coding tags
 * \sa CbCIMessageCoding_Tag */
/** \remarks Common Data Section */
typedef UINT8 CbCIMessageCoding;
/**@}*/

/*Michal Bukai - SMS Memory Full Feature*/
/** \brief  Message Type Tag  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiMsgStoreDeliveryMsgType_Tag
{
      MSG_STORE_MSG_TYPE,
      MSG_DELIVERY_MSG_TYPE,
	MSG_STORE_DELIVERY_MSG_TYPE_NUM
} _CiMsgStoreDeliveryMsgType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message Coding Tag
 * \sa CiMsgStoreDeliveryMsgType_Tag */
/** \remarks Common Data Section */
typedef UINT8 CiMsgStoreDeliveryMsgType;
/**@}*/
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_NEWMSG_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimNewMsgInd_struct{
    CiMsgMsgType   				type;				/**< Type of new message received; values are CI_MSG_MSG_TYPE_DELIVER, CI_MSG_MSG_TYPE_STATUS_REPORT, and CI_MSG_MSG_TYPE_CBS \sa CiMsgMsgType */
	/*Michal Bukai - SMS Memory Full Feature*/
	INT8        				ShortMsgId;			/**< Short message id. */
	CiMsgStoreDeliveryMsgType  	msgType;	  		/**< \sa CiMsgStoreDeliveryMsgType */
    INT16           			commandRef;		/**< Additional reference to hold ABSM transaction */
	UINT8     					res1U8[2];			/* Padding */
	CbCIMessageCoding  			messageCoding;    	/**< Message coding. \sa CbCIMessageCoding */
	CiMsgPdu  					pdu;				/**< New message received \sa CiMsgPdu_struct */
    CiOptAddressInfo  			optSca;  	 		/**< Optional service center address \sa CCI API Ref Manual */ // SCR #1777605: Optional Service Center Address
    CiEtwsMsgInfo				etwsInfo;
} CiMsgPrimNewMsgInd;


/* <NOTINUSE> */
/** <paramref name="CI_MSG_PRIM_NEWMSG_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimNewMsgRsp_struct{
    CiBoolean  success;				/**< TRUE if acknowledgement is positive; FALSE if acknowledgement is negative \sa CCI API Ref Manual */
	/*Michal Bukai - SMS Memory Full Feature*/
	CiBoolean  					memory_full;			/**< TRUE if ME memory is full; \sa CCI API Ref Manual */
	CiMsgStoreDeliveryMsgType  	msgType;	  		/**< \sa CiMsgStoreDeliveryMsgType */
	INT8        				ShortMsgId;			/**< Short message id. */
    INT16           			commandRef;		/**< Additional reference to hold ABSM transaction */
	UINT8     					res1U8[2];			/* Padding */
    CiBoolean 					pduPresent;			/**< Not in use */
    CiMsgPdu  					pdu;				/**< Not in use */
} CiMsgPrimNewMsgRsp;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMSC_ADDR_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetSmscAddrReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMSC_ADDR_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmscAddrCnf_struct{
    CiMsgRc        		rc;				/**< Result code  \sa CiMsgRc */
     CiBoolean 			scaPresent;		/**< TRUE: if present  \sa CCI API Ref Manual */
    CiAddressInfo 		sca;				/**< Service center address \sa CCI API Ref Manual */
} CiMsgPrimGetSmscAddrCnf;


/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMSC_ADDR_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmscAddrReq_struct{
    CiAddressInfo sca;					/**< Service center address \sa CCI API Ref Manual  */
} CiMsgPrimSetSmscAddrReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMSC_ADDR_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmscAddrCnf_struct{
    CiMsgRc     rc;		/**< Result code  \sa CiMsgRc */
} CiMsgPrimSetSmscAddrCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_MOSMS_SERVICE_CAP_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetMoSmsServiceCapReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_MOSMS_SERVICE_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetMoSmsServiceCapCnf_struct{
    CiMsgRc     rc;						/**< Result code  \sa CiMsgRc */
    CiBitRange  bitsMoSmsSrvCfg;		/**< Supported MO SMS services \sa CCI API Ref Manual */
} CiMsgPrimGetMoSmsServiceCapCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_MOSMS_SERVICE_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetMoSmsServiceReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_MOSMS_SERVICE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetMoSmsServiceCnf_struct{
    CiMsgRc          			rc;		/**< Result code  \sa CiMsgRc */
    CiMsgMoSmsSrvCfg 		cfg;		/**< MO SMS service configuration \sa CiMsgMoSmsSrvCfg */
} CiMsgPrimGetMoSmsServiceCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_MOSMS_SERVICE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetMoSmsServiceReq_struct{
    CiMsgMoSmsSrvCfg 		cfg;		/**< MO SMS service information \sa CiMsgMoSmsSrvCfg */
} CiMsgPrimSetMoSmsServiceReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_MOSMS_SERVICE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetMoSmsServiceCnf_struct{
    CiMsgRc    	rc;			/**< Result code  \sa CiMsgRc */
} CiMsgPrimSetMoSmsServiceCnf;

typedef CiEmptyPrim CiMsgPrimGetCbmTypesCapReq;

//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetCbmTypesCapCnf_struct{
    CiMsgRc       rc;
    CiBitRange    bitsMode;
} CiMsgPrimGetCbmTypesCapCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CBM_TYPES_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetCbmTypesReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_CBM_TYPES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetCbmTypesCnf_struct{
    CiMsgRc            rc;							/**< Result code  \sa CiMsgRc */
    CiBoolean 				setPresent;			/**< TRUE: if present */
    CiMsgCbmTypesSet  	set;				/**< CBM types setting \sa CiMsgCbmTypesSet_struct */
	CiBoolean			EnableAll;			/**< TRUE: Receive all cell broadcast messages; 
												FALSE: Filter cell broadcast messages according to CBMI and data coding schemes \sa CCI API Ref Manual */
	CiBoolean			DisableDcss;		/**< TRUE: Disable filtering of cell broadcast messages according to data coding schemes;
												FALSE: Enable filtering of cell broadcast messages according to data coding schemes \sa CCI API Ref Manual */
} CiMsgPrimGetCbmTypesCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_CBM_TYPES_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetCbmTypesReq_struct{
     CiMsgCbmTypesSet  	set;				/**< CBM types setting \sa CiMsgCbmTypesSet_struct */
	 CiBoolean     		EnableAll; 			/**< TRUE: Receive all cell broadcast messages; 
												FALSE: Filter cell broadcast messages according to CBMI and data coding schemes	\sa CCI API Ref Manual */
	 CiBoolean     		DisableDcss;		/**< TRUE: Disable filtering of cell broadcast messages according to data coding schemes
												FALSE: Enable filtering of cell broadcast messages according to data coding schemes \sa CCI API Ref Manual */
} CiMsgPrimSetCbmTypesReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_CBM_TYPES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetCbmTypesCnf_struct{
    CiMsgRc  				rc;					/**< Result code  \sa CiMsgRc */
} CiMsgPrimSetCbmTypesCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_FILTER_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetFilterStatusReq_struct{
 /* !!!!!!!!!!!!!!!!!!!
  * When RIL completes the transition to contiguous memory, all CCI_xx_CONTIGUOUS
  * & CCI_APP_NONCONTIGUOUS flags must be removed.
  * ONLY the code BETWEEN the following 2 comment lines will REMAIN:
  * # Start Contiguous Code Section # and # End Contiguous Code Section #
  * All other code OUTSIDE these comments must be REMOVED - ( The backwards compatible code )
  */
	 CiBoolean     		EnableAll; 			/**< TRUE: Receive all cell broadcast messages; 
												FALSE: Filter cell broadcast messages according to CBMI and data coding schemes	\sa CCI API Ref Manual */

     CiBoolean		    DisableCb;		   /**< TRUE: Disable CBS */
												
} CiMsgPrimSetFilterStatusReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_FILTER_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetFilterStatusCnf_struct{
    CiMsgRc  				rc;					/**< Result code. \sa CiMsgRc */
} CiMsgPrimSetFilterStatusCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_FILTER_STATUS_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetFilterStatusReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_FILTER_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetFilterStatusCnf_struct{
    CiMsgRc  				rc;					/**< Result code. \sa CiMsgRc */
	
	CiBoolean		   EnableAll;		   /**< TRUE: Receive all cell broadcast messages; */
	
	CiBoolean		   DisableCb;		   /**< TRUE: Disable CBS */
} CiMsgPrimGetFilterStatusCnf;
/*adding by sunny on 20130702 for #484293,begin*/
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_CB_RAT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetCbRatReq_struct{
	UINT8		   cbRat;		   /**< 0: GSM+W;1:G only;2:W only ,3:LTE only,4:lte gsm,5:lte, w,6,lte w,gsm*/
} CiMsgPrimSetCbRatReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_CB_RAT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetCbRatCnf_struct{
	CiMsgRc		   rc;		   /**< 0: success */
} CiMsgPrimSetCbRatCnf;
/*adding by sunny on 20130702 for #484293,end*/
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_STORAGES_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectStoragesReq_struct{
	CiBitRange        		bitsType;								 /**< Bit maps of CiMsgStorageOperType \sa CCI API Ref Manual */
	CiMsgStorage      		storages[CI_MSG_NUM_STRGOPERTYPES];	/**< Storage to be associated with the storage operation type \sa CiMsgStorage */
} CiMsgPrimSelectStoragesReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SELECT_STORAGES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSelectStoragesCnf_struct{
	CiMsgRc             		rc;					/**< Result code  \sa CiMsgRc */
	CiBitRange           		bitsType;			/**< Bit maps of CiMsgStorageOperType required \sa CCI API Ref Manual */
    CiMsgStorageSetting    	set;					/**< Set of memory storage information being used; optional when rc is not CIRC_MSG_SUCCESS. \sa CiMsgStorageSetting_struct */
} CiMsgPrimSelectStoragesCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_WRITE_MSG_WITH_INDEX_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimWriteMsgWithIndexReq_struct{
  UINT16           		index;					/**< Index of message to be written */
  CiMsgMsgStatus   	status;					/**< Message status \sa CiMsgMsgStatus */
  CiMsgPdu  		pdu;					/**< Message PDU \sa CiMsgPdu_struct */
  CiOptAddressInfo  	optSca;   				/**< Optional service center address \sa CCI API Ref Manual */
												/*------5/26/2009 1:56PM------
												 * SCR #1777605:
											 * ----------------------------*/
} CiMsgPrimWriteMsgWithIndexReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_WRITE_MSG_WITH_INDEX_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimWriteMsgWithIndexCnf_struct{
  CiMsgRc 		rc;			/**< Result code  \sa CiMsgRc */
  UINT16 			index;		/**< Index for memory storage */
} CiMsgPrimWriteMsgWithIndexCnf;


/** \brief  Message waiting indication types (bits 6..0 show the message indication IE)  */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_MSG_MSGWAITING_TYPE_TAG
{
  CI_MSG_MSGWAITING_VOICE = 0x00,    	/**< Voice mail messages waiting */
  CI_MSG_MSGWAITING_FAX   = 0x01,    	/**< Fax messages waiting */
  CI_MSG_MSGWAITING_EMAIL = 0x02,    	/**< Email messages waiting */
  CI_MSG_MSGWAITING_OTHER = 0x03     	/**< Other messages waiting */
} _CiMsgMsgWaitingType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Message waiting indication type (bits 6..0 show the message indication IE)
 * \sa CI_MSG_MSGWAITING_TYPE_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiMsgMsgWaitingType;
/**@}*/

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_MESSAGE_WAITING_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimMessageWaitingInd_struct
{

  CiMsgMsgWaitingType    	msgType;            		/**< Message type: voice, fax, email, other \sa CiMsgMsgWaitingType */
  CiBoolean              		indicationActive;   	/**< TRUE = active; FALSE = inactive \sa CCI API Ref Manual */
  UINT8                  		msgCount;           		/**< Number of waiting messages of the specified type */
  CiBoolean              		udhPresent;		/**< 	UDHI (User Data Header information) method is present. \sa CCI API Ref Manual */
  CiBoolean              		cphsPresent; 	/**< CPHS (Common PCN Handset Specification) method is present.  \sa CCI API Ref Manual */
  CiBoolean              		dcsPresent;		/**< DCS (TP-Data-Coding-Scheme method) method is present.  \sa CCI API Ref Manual */
  CiBoolean              		cphsLine1;	     /**< Defined in CPHS case.  \sa CCI API Ref Manual */
  CiBoolean              		cphsLine2;	     /**< Defined in CPHS case. \sa CCI API Ref Manual */
  CiBoolean              		storeMessage;    /**< Defined in UDH, CPHS, DCS case.  \sa CCI API Ref Manual */
  CiBoolean              		userDataHeaderPresent; 	/**< user data is present in TP-UD.  \sa CCI API Ref Manual */
} CiMsgPrimMessageWaitingInd;

/** \brief MO SMS Status enumeration */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_MSG_STATUS_TAG
{
  CI_MSG_SIM_READY   = 0,    	/**< SMS ready for SIM */
  CI_MSG_NOT_READY,    	        /**< SMS not ready */
  CI_MSG_SEND_READY,      	    /**< ready for MO */
  CI_MSG_SEND_RECV_READY,     	/**< ready for both MO/MT */

  CI_MSG_NUM_STATUS
} _CiMsgStatus;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Service type enumeration.
 * \sa CI_MSG_STATUS_TAG */
typedef UINT8 CiMsgStatus;
/**@}*/

/*CQ00121698,sac report  status of card sms after sms ready,2020-6-22,perse,begin*/
//ICAT EXPORTED STRUCT
typedef struct CiMsgRecdStatus{
   UINT8	recdIndex; 			/**< record index */
   CiMsgMsgStatus	recdStatus;		/**< record status */
}CiMsgRecdStatus;
/*CQ00121698,sac report  status of card sms after sms ready,2020-6-22,perse,end*/

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_STORAGE_STATUS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimStorageStatusInd_struct {

  CiBoolean  	memCapExceeded;      	/**< Indicates if the memory capacity has been reached or exceeded \sa CCI API Ref Manual */
  UINT8      	usedRecords;         		/**< Number of currently used SMS file records on the SIM */
  UINT8      	totalSmsRecords;     		/**< Number of total SMS file records on the SIM */
  UINT8      	firstFreeRecord;     		/**< First free SMS file record */

  CiMsgStatus   smsStatus;     		    /**< status for SMS service group */
  
  /*CQ00121698,sac report  status of card sms after sms ready,2020-6-22,perse,begin*/
  CiMsgRecdStatus  smsRecdStatus[200];  /**< status for each SMS record */
  UINT8            smsRecdVallen;       /**< number of SMS records */
  /*CQ00121698,sac report  status of card sms after sms ready,2020-6-22,perse,end*/
} CiMsgPrimStorageStatusInd;

/*Michal Bukai - SMS Memory Full Feature*/
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_RESET_MEMCAP_FULL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimResetMemcapFullReq_struct {
	UINT8 		memcapFull;			/**< 0: not full ,1:full and not report,2: full and report,other:full and not report.CQ00147288 */
} CiMsgPrimResetMemcapFullReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_RESET_MEMCAP_FULL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimResetMemcapFullCnf_struct {
	CiMsgRc 		rc;			/**< Result code. \sa CiMsgRc */
} CiMsgPrimResetMemcapFullCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_RECORD_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetRecordStatusReq_struct {
  UINT16          index;          /**< Index into the memory storage. */  
  CiMsgMsgStatus  status;         /**< Message status to be set with the message. \sa CiMsgMsgStatus */
  UINT8 		  memStoreIndex;
} CiMsgPrimSetRecordStatusReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_RECORD_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetRecordStatusCnf_struct {
  CiMsgRc       rc;     /**< Result code. \sa CiMsgRc */
} CiMsgPrimSetRecordStatusCnf;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_LOCK_SMS_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimLockSmsStatusReq_struct {
  CiBoolean       lockSmsStatus;         /**< lock SMS status in SIM */
} CiMsgPrimLockSmsStatusReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_STORED_SMS_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetStoredSmsStatusReq_struct {
	UINT8 		  	memStoreIndex;
	UINT16          index;          /**< Index into the memory storage. */ 	
} CiMsgPrimGetStoredSmsStatusReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_STORED_SMS_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetStoredSmsStatusCnf_struct {	
	UINT8 		    memStoreIndex;
	CiMsgMsgStatus  status;		  /**< Message status to be set with the message. \sa CiMsgMsgStatus */
	UINT16			index;			/**< Index into the memory storage. */
	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */
} CiMsgPrimGetStoredSmsStatusCnf;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMS_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsStatusReq_struct {
	UINT8 		    memStoreIndex;        
} CiMsgPrimGetSmsStatusReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMS_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsStatusCnf_struct {
	UINT8 		    memStoreIndex; 
	UINT8		    initMsgRef;	  
	UINT8		    memoryExceededFlag;
	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */  
} CiMsgPrimGetSmsStatusCnf;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMS_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmsStatusReq_struct {
  	UINT8 		    memStoreIndex; 
	UINT8		    initMsgRef;	  
	UINT8		    memoryExceededFlag;       
} CiMsgPrimSetSmsStatusReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMS_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmsStatusCnf_struct {
  	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */          
} CiMsgPrimSetSmsStatusCnf;
/** <paramref name="CI_MSG_PRIM_GET_PARAMETER_COUNT_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsParameterCountReq_struct {
	UINT8 		    memStoreIndex;        
} CiMsgPrimGetSmsParameterCountReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_PARAMETER_COUNT_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsParameterCountCnf_struct {
	UINT8 		    memStoreIndex; 
	UINT8		    recordCount;	 	
	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */  
} CiMsgPrimGetSmsParameterCountCnf;
/** <paramref name="CI_MSG_PRIM_SET_PARAMETER_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmsParameterReq_struct {
	UINT8 		    memStoreIndex; 
	UINT8		    index;	  
	UINT8		    recordLength;	 
	UINT8			record[CI_MSG_MAX_PARAMETER_LENGTH];        
} CiMsgPrimSetSmsParameterReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_PARAMETER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmsParameterCnf_struct {	 
	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */  
} CiMsgPrimSetSmsParameterCnf;
/** <paramref name="CI_MSG_PRIM_GET_PARAMETER_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsParameterReq_struct {
	UINT8 		    memStoreIndex; 
	UINT8 			index;
} CiMsgPrimGetSmsParameterReq;
/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_PARAMETER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmsParameterCnf_struct {
	CiMsgRc       	rc;     /**< Result code. \sa CiMsgRc */ 
	UINT8 		    memStoreIndex; 
	UINT8		    index;	  
	UINT8		    recordLength;		 
	UINT8			record[CI_MSG_MAX_PARAMETER_LENGTH];
} CiMsgPrimGetSmsParameterCnf;


/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_LOCK_SMS_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimLockSmsStatusCnf_struct {
  CiMsgRc       rc;     /**< Result code. \sa CiMsgRc */
} CiMsgPrimLockSmsStatusCnf;

/* <INUSE> */
typedef CiEmptyPrim CiMsgPrimGetMsgIndConfigReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_MSG_IND_CONFIG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetMsgIndConfigCnf_struct{
	CiMsgRc 			rc; 						/**< Result code. \sa CiMsgRc */
	CiMsgMsgIndSetting	smsDeliverIndSetting;		/**< Indication setting for SMS-Deliver messages \sa CiMsgMsgIndSetting */
	CiMsgMsgIndSetting	cbmIndSetting;				/**< Indication setting for CBM messages \sa CiMsgMsgIndSetting */
	CiMsgMsgIndSetting	smsStatusReportIndSetting;	/**< Indication setting for SMS-STATUS-REPORT messages \sa CiMsgMsgIndSetting */
}CiMsgPrimGetMsgIndConfigCnf;

//////////////////

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMSC_PARAMS_REQ"> */
typedef CiEmptyPrim CiMsgPrimGetSmscParamsReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_GET_SMSC_PARAMS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimGetSmscParamsCnf_struct{
	CiMsgRc 			rc; 						/**< Result code. \sa CiMsgRc */
	CiBoolean			pidPresent;					/**< TRUE: if pid present */
	UINT8				pid;						/**< Protocol Identifier */
	CiBoolean			dcsPresent;					/**< TRUE: if dcs present */
	UINT8				dcs;						/**< Data Coding Scheme */
	CiBoolean			vpPresent;					/**< TRUE: if vp present */
	UINT8				vp;							/**< Validity Period */
} CiMsgPrimGetSmscParamsCnf;


/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMSC_PARAMS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmscParamsReq_struct{
	CiBoolean			pidPresent;					/**< TRUE: if pid present */
	UINT8				pid;						/**< Protocol Identifier */
	CiBoolean			dcsPresent;					/**< TRUE: if dcs present */
	UINT8				dcs;						/**< Data Coding Scheme */
	CiBoolean			vpPresent;					/**< TRUE: if vp present */
	UINT8				vp;							/**< Validity Period */
} CiMsgPrimSetSmscParamsReq;

/* <INUSE> */
/** <paramref name="CI_MSG_PRIM_SET_SMSC_PARAMS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiMsgPrimSetSmscParamsCnf_struct{
  CiMsgRc				rc;							/**< Result code  \sa CiMsgRc */
} CiMsgPrimSetSmscParamsCnf;
typedef struct CiMsgPrimSetSmResendParaReq_struct{
    UINT8   tr1mTimeValue;
    UINT8   retramTimeValue;
    UINT8   retryNum;	
    UINT8   isRetryRpError;//reserved1,CQ00136220
    UINT8   reserved2;
    UINT8   reserved3;
    UINT8   reserved4;
    UINT8   reserved5;
} CiMsgPrimSetSmResendParaReq;
typedef struct CiMsgPrimSetSmResendParaCnf_struct{
    CiMsgRc 				rc;							/**< Result code  \sa CiMsgRc */
} CiMsgPrimSetSmResendParaCnf;

typedef CiEmptyPrim CiMsgPrimGetSmResendParaReq;
typedef struct CiMsgPrimGetSmResendParaCnf_struct{
     CiMsgRc 	rc;							/**< Result code  \sa CiMsgRc */
     UINT8 	    tr1mTimeValue;	
     UINT8      retramTimeValue;
     UINT8 	    retryNum;
     CiBoolean	defaultFlag;
	 UINT8      isRetryRpError;	  //CQ00136220
} CiMsgPrimGetSmResendParaCnf;
/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_msg_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_MSG_NUM_CUST_PRIM will be set to 0 in the "ci_msg_cust.h" file.
 */
#include "ci_msg_cust.h"

#define CI_MSG_NUM_PRIM ( CI_MSG_NUM_COMMON_PRIM + CI_MSG_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_MSG_NUM_PRIM CI_MSG_NUM_COMMON_PRIM

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

#endif /* _CI_MSG_H_ */


/*                      end of ci_msg.h
--------------------------------------------------------------------------- */


