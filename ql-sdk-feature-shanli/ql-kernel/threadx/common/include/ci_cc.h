/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_cc.h
Description : Data types file for the CC Service Group

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

#if !defined(_CI_CC_H_)
#define _CI_CC_H_

#ifdef __cplusplus
    extern "C" {
#endif
#include "ci_api_types.h"
/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_CC_VER_MAJOR 3
//#define CI_CC_VER_MINOR 1
//#define CI_CC_VER_MAJOR 4
//#define CI_CC_VER_MINOR 0
#define CI_CC_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version


/* -----------------------------------------------------------------------------
 *    CC Configuration definitions
 * ----------------------------------------------------------------------------- */
/* default value for the interval between two DTMF tones in a string */
#define CICC_DTMF_DEFAULT_INTERVAL  	  30

/* Maximum length (bytes) of a DTMF digit string (CiCcPrimSendDtmfStringReq) */
#define CICC_MAX_DTMF_STRING_LENGTH   32

/* Maximum Number of calls (active and held) allowed at any time */
#define CICC_MAX_CURRENT_CALLS        7 /* Dictated by multiparty rules */

/*Maximum Number of data that send to ap from cp */
#define CICC_ECALL_AUDIO_INFO_MAX_LENGTH 128

/* ----------------------------------------------------------------------------- */

/* CI_CC Primitive ID definitions */

/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_CC_PRIM {
    CI_CC_PRIM_GET_NUMBERTYPE_REQ = 1,/**< \brief Requests the type of number \details   */
    CI_CC_PRIM_GET_NUMBERTYPE_CNF,    /**< \brief Confirms the request and returns the type of number \details See CI_CC_PRIM_SET_NUMBERTYPE_REQ for internal default information.
There should be no reason for an unsuccessful result.
   */
    CI_CC_PRIM_SET_NUMBERTYPE_REQ,	/**<  \brief  Requests to set the type of number to be used for subsequent outgoing calls
* \details Default values for the Address Type fields are based on the outgoing call requests themselves (in the Dial String parameter field).
* See also the CI_CC_PRIM_MAKE_CALL_REQ request.
* For international calls (where the '+' character appears as a prefix to the dial string), the values are:
* Type of Number = CI_NUMTYPE_INTERNATIONAL
* Numbering Plan = CI_NUMPLAN_E164_E163
* For all other calls (this is the SAC internal default), the values are:
* Type of Number = CI_NUMTYPE_UNKNOWN
* Numbering Plan = CI_NUMPLAN_E164_E163 */
    CI_CC_PRIM_SET_NUMBERTYPE_CNF,	/**< \brief Confirms the request and sets the type of number to be used for subsequent outgoing call requests \details */
    CI_CC_PRIM_GET_SUPPORTED_CALLMODES_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_GET_SUPPORTED_CALLMODES_CNF,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_GET_CALLMODE_REQ,			/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_GET_CALLMODE_CNF,    		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_SET_CALLMODE_REQ,   			/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
	CI_CC_PRIM_SET_CALLMODE_CNF = 10,    		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_REQ,	/**< \brief Requests supported Bearer Service Type parameter settings for data calls \details  */
    CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_CNF,	/**< \brief Confirms the request and returns the supported Bearer Service Type parameter settings for data calls \details  There should be no reason for an unsuccessful result.*/
    CI_CC_PRIM_GET_DATA_BSTYPE_REQ,	/**< \brief Requests currently selected Bearer Service Type information for outgoing (and incoming) data calls \details */
    CI_CC_PRIM_GET_DATA_BSTYPE_CNF,	/**< \brief Confirms the request and returns currently selected Bearer Service Type information for outgoing (and incoming) data calls  \details There should be no reason for an unsuccessful result.*/
    CI_CC_PRIM_SET_DATA_BSTYPE_REQ,	/**< \brief Requests Bearer Service Type information for outgoing (and incoming) data calls
									 * \details This information (or the default) is used when outgoing data calls (or multi-mode calls with a data component)
									 * are originated. It can also be used during mobile terminated data call setup.
									 * Not all combinations of the Data Bearer Service Type parameters are supported for GSM/UMTS.
									 * Other bearer capability information for outgoing and incoming calls is set up from internal defaults. */
    CI_CC_PRIM_SET_DATA_BSTYPE_CNF,	/**< \brief Confirms the request and sets Bearer Service Type information for outgoing (and incoming) data calls
  									*  \details This information can be "negotiated" with the network as required, on a per-call basis. */
    CI_CC_PRIM_GET_AUTOANSWER_ACTIVE_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_GET_AUTOANSWER_ACTIVE_CNF,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_REQ,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_CNF = 20,	/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_LIST_CURRENT_CALLS_REQ,      /**< \brief  Requests a list of current calls that are present in the mobile
											 * \details Requests current call information for all calls.
											 * CI_CC_PRIM_GET_CALLINFO_REQ can also be used to request call information for a specified call. */
	CI_CC_PRIM_LIST_CURRENT_CALLS_CNF,		/**< \brief  Confirms the request and returns a list of the current calls
											 *   \details Returns an array of current call information structures. CI_CC_PRIM_GET_CALLINFO_REQ can also be used to
 *   request call information for a specified call. If there are no current calls, NumCalls = 0, and the CallInfo array
 *   contains no useful information. There should be no reason for an unsuccessful result. */
    CI_CC_PRIM_GET_CALLINFO_REQ,			/**< \brief Requests current call information for a specified call identifier\details */
    CI_CC_PRIM_GET_CALLINFO_CNF,            /**< \brief Confirms the request and returns the current call information for a specified call identifier
											 * 	 \details Use CI_CC_PRIM_LIST_CURRENT_CALLS_REQ to request a list of current call identifiers. For a data call, the
  *  bearer service information may have been "negotiated" with the network. If Result indicates an error, the call
  *  information structure contains no useful information.
 */
    CI_CC_PRIM_MAKE_CALL_REQ,	/**< \brief Requests to make an outgoing call
								 * \details Uses the default call mode and current bearer service type information (or the appropriate defaults).
								 *  The default call mode is Single Mode; therefore, a CI_CC_PRIM_MAKE_CALL_REQ request uses
								 * the BasicCMode parameter to indicate which mode is required.
 *    Bearer service type is set by CI_CC_PRIM_SET_DATA_BSTYPE_REQ. Other bearer capability information is set up from internal defaults.
 *    Call options can be used to:
 *    - Enable or disable closed user group (CUG) information for this call;
 *    - Override the CLIR option for this call (force enable or disable).
 *    CUG information is configured by CI_SS_PRIM_SET_CUG_CONFIG_REQ.
 * 	  The default CLIR option is set up by CI_SS_PRIM_SET_CLIR_OPTION_REQ.
 *    Valid dial digits are defined in "Mobile Radio Interface layer 3 specification; Core Network Protocols - Stage 3", revision 3.11.0 ,3GPP TS 24.008.
 *    The supplied dial string can incorporate a prefix '+' character, to indicate that this is an international call. In this
 *    situation, SAC uses the default Address Type information (if necessary) for an international call. For details,
 *    see the CI_CC_PRIM_SET_NUMBERTYPE_REQ request.
 *    SAC uses the dial string digits to determine whether an emergency call is being requested.
 *    SAC also supports fixed dialing mode (if enabled in the SIM), using the fixed dialing numbers (FDN) list
 *    that is stored on the SIM. For the fixed number dialing support requirements, see:
 *    "Technical Specification Group Services and System Aspects. Service Aspects; Service principles", revision
 *    3.13.0, 3GPP TS 22.101, Section A.24. */
    CI_CC_PRIM_MAKE_CALL_CNF,		/**< \brief Confirms the request to make an outgoing call \details */
    CI_CC_PRIM_CALL_PROCEEDING_IND, /**< \brief  Indicates that an outgoing call is in progress
									 * \details This indication is triggered by a CALL PROCEEDING notification from the network. It indicates that the outgoing
  *  call request has been accepted, and is proceeding through the network. If in-band tones are available from the
  *  network, the receive audio path should be enabled, so that the subscriber can hear the tones. No
  *  explicit response is required.  */
    CI_CC_PRIM_MO_CALL_FAILED_IND,	/**< \brief Indicates that an outgoing (mobile originated) call failed
									 *   \details The reason for the call failure is indicated by the Cause parameter. If in-band tones are available from the
  *  network, the receive audio path should be enabled, so that the subscriber can hear the tones.
  *  No explicit response is required. */
    CI_CC_PRIM_ALERTING_IND,	/**< \brief Indicates that an outgoing call is alerting
								 * \details This indication is triggered by an ALERTING notification from the network, and indicates that the called party's phone is alerting.
 *    If in-band tones (ringback) are available from the network, the receive audio path should be
 *    enabled, so that the subscriber can hear the tones. Otherwise, the tones must be generated locally. */
    CI_CC_PRIM_CONNECT_IND = 30,	/**< \brief Indicates that an outgoing or incoming call is connected
							 * \details This indication is triggered by a connect notification from the network, indicating that the called party has accepted and
 *   answered the call, or an incoming call has been answered. If not already done, the audio paths should now be enabled. No explicit response is required. */
    CI_CC_PRIM_DISCONNECT_IND,	/**< \brief Indicates that a call was disconnected
								 * \details This indication is triggered by:
 *   - A disconnect message received from the network, indicating network-initiated call clearing
 *   - Mobile-initiated call clearing (hangup)
 *   The reason for call clearing is indicated by the Cause parameter. If not already done, the transmit and receive
 *   audio paths should now be disabled. No explicit response is required */
    CI_CC_PRIM_INCOMING_CALL_IND, 	/**< \brief  Indicates an incoming call
									 * \details SAC allocates a unique call identifier, which must be used for all subsequent requests that are directed to this call.
  * The incoming call setup from the network has already been accepted, and the mobile has sent an alerting indication to the network in response.
  * The subscriber can answer the call, using the CI_CC_PRIM_ANSWER_CALL_REQ request.
  * The subscriber can refuse the call (if allowed), using the CI_CC_PRIM_REFUSE_CALL_REQ request.
  * In either case, the subscriber must be alerted to the incoming call. */
    CI_CC_PRIM_CALL_WAITING_IND, /**< \brief Indicates the call waiting (CW) information for an incoming call
								  * \details AC allocates a unique call identifier, which must be used for all subsequent requests that are directed at this call.
  *  Call waiting indications are enabled or disabled by the CI_SS_SET_CW_OPTION_REQ request.
  *  This indication is enabled by default.
  *  This indication is received only if the call waiting supplementary service is provisioned.
  *  First, the active call must be held, then the subscriber can decide to answer or refuse the waiting call.
  *  No explicit response is required.*/
    CI_CC_PRIM_HELD_CALL_IND,/**< \brief Indicates that there is a held call
							  * \details SAC sends this indication if an active call is released while a held call exists.
							  * The held call can then be released or retrieved, as desired.
  *  No explicit response is required, although a request is needed to take the call off hold.*/
    CI_CC_PRIM_ANSWER_CALL_REQ, /**< \brief Requests to answer an incoming call
								 *   \details If auto-answer is active (see CI_CC_PRIM_SET_AUTOANSWER_ACTIVE_REQ),
								 * SAC may answer the incoming call automatically, and the CI_CC_PRIM_ANSWER_CALL_REQ request may not be required.
  								 * This request does not answer a waiting call.
								 * The active call must first be held or released, which triggers SAC to send a
								 * CI_CC_PRIM_INCOMING_CALL_IND indication for the waiting call. Then the waiting call can be answered.
  								 * This request does not switch modes for a multi-mode call (alternating voice/data, alternating voice/fax, or voice followed by data). To do this, use the CI_CC_PRIM_SWITCH_CALLMODE_REQ request. */
    CI_CC_PRIM_ANSWER_CALL_CNF, /**< \brief  Confirms the request to answer the incoming call
								 * \details The call identifier is included as a crosscheck or confirmation.*/
    CI_CC_PRIM_REFUSE_CALL_REQ, /**< \brief Requests to reject an incoming call \details The incoming call may be a call waiting. */
    CI_CC_PRIM_REFUSE_CALL_CNF, /**< \brief Confirms the reject request */
    CI_CC_PRIM_MT_CALL_FAILED_IND, /**< \brief  Indicates that an incoming (mobile terminated) call failed \details */
    CI_CC_PRIM_HOLD_CALL_REQ = 40,      /**< \brief Requests an active call to be held
									* \details This request can be used to hold the active call, if there is one.
 *   The subscriber can subsequently:
 *   retrieve the held call;
 *   set up another (outgoing) call;
 *   accept an incoming call.
 *   If another active call is set up, the user can subsequently:
 *   alternate between the active call and the held call;
 *   disconnect the active call;
 *   disconnect the held call;
 *   disconnect both the active call and the held call.
 *   GSM allows only one call to be held at any time (except for calls that are part of a multiparty call).
 *   If a held call already exists, this request fails with an error result.*/
    CI_CC_PRIM_HOLD_CALL_CNF,/**< \brief Confirms the request to hold a call */
    CI_CC_PRIM_RETRIEVE_CALL_REQ,  /**< \brief Requests a held call to be retrieved
									* \details  This request can be used to retrieve a held call, if there is one.
									* For GSM, the HOLD service does not allow more than one held call (non-multiparty) at any time.
									* The CallId parameter is provided here to accommodate multi-call procedures for other 3G protocols.
									* This request should not be used to perform operations on a multiparty (MPTY) call.
									* If this is attempted, the request fails with an error result.*/
    CI_CC_PRIM_RETRIEVE_CALL_CNF,	/**< \brief Confirms the request to retrieve a held call
									 * \details If Result is CIRC_CC_REJECTED, the cause information is reported as received in a retrieve reject message from the network.*/
    CI_CC_PRIM_SWITCH_ACTIVE_HELD_REQ,   /**< \brief Requests an active call and a held call to be switched (shuttle request)
										  * \details This request is used to transfer (shuttle) between an active call and a held call.
										  * The active call is held and the held call is retrieved (becomes the active call).
										  * The shuttle operation is handled by the network.
										  * The mobile must send a hold request for the current active call, immediately followed (see below) by a retrieve request for the held call.
										  * The HOLD service does not support more than one held call at any time. To avoid this, the network must receive the retrieve request within five seconds of receiving the hold request.
										  * The same result could be achieved by sending a CI_CC_PRIM_HOLD_CALL_REQ request for the active call,
										  * followed by a CI_CC_RETRIEVE_CALL_REQ request for the held call.
										  * However, the above timing requirements may not be fulfilled by this method, and the shuttle operation could fail.
										  * Use the CI_CC_PRIM_SHUTTLE_MPTY_REQ request for shuttle operations that involve multiparty (MPTY) conference calls. */
    CI_CC_PRIM_SWITCH_ACTIVE_HELD_CNF,  /**< \brief Confirms the request to switch between the active and held calls (shuttle request)
										 * \details */
    CI_CC_PRIM_CALL_DEFLECT_REQ,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_CALL_DEFLECT_CNF,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_REQ, /**< \brief Requests an explicit call transfer (ECT) for an active call and a held call
											* \details This request is used to connect an active call and a held call, and then to exit both calls.
											* The GSM standard allows ECT for a held call and an outgoing call in the alerting state
											* (an MO call that has been presented to the called party, but has not yet been answered).
											* This is described in the standard as a network option, and therefore is a valid operation only if the network supports it.
											* For more information, see 3GPP TS 22.091.
											* The ECT service requires the provision of the call Hold (HOLD) Supplementary Service.
											* If the subscriber has an active call, a held call, and a call waiting,
											* then after successful completion of the ECT request, the subscriber receives an incoming call indication for the waiting call.
											* Multiparty (MPTY) calls cannot be transferred by this (or any other) request.*/
    CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_CNF,	/**< \brief Confirms the explicit call transfer (ECT) request
											 * \details If the ECT request is successfully completed, there is a normal call between the original held party and
  *  the active/alerting party (see 3GPP TS 22.091, Section 5.8). SAC removes the call identifiers for the original
  *  calls. An attempt to use these call identifiers in any subsequent call related request fails with Result =
  *  CIRC_CC_INVALID_CALLID.	*/
    CI_CC_PRIM_RELEASE_CALL_REQ = 50, /**< \brief Requests release (hangup) of a call (mobile originated call clearing)
								  * \details Requests disconnect of an active or held call.
  *  If there is a held call and the active call is released, SAC sends a CI_CC_PRIM_HELD_CALL_IND indication for the held call. The subscriber then can either retrieve the held call or release it.
  *  If there is a waiting call and the active call is released, SAC sends a CI_CC_PRIM_INCOMING_CALL_IND indication for the waiting call, which can then be answered or refused.
  *  This request is also used to release individual calls in a multiparty call.
  *  If CallId is CICC_NO_CALL_ID and there is only one call in progress, this call is released. */
    CI_CC_PRIM_RELEASE_CALL_CNF,/**< \brief  Confirms the request to release (hangs up) an active or held call (mobile originated call clearing)*/
    CI_CC_PRIM_RELEASE_ALL_CALLS_REQ, /**< \brief Requests release (disconnect) of all calls (mobile originated call clearing)
									   * \details For GSM, there can be only one active call and only one held call.*/
    CI_CC_PRIM_RELEASE_ALL_CALLS_CNF, /**< \brief Confirms the request to release (disconnects) all calls (mobile originated call clearing)
									   * \details If the calls are successfully released (disconnected), SAC removes all individual call identifiers.
  *  An attempt to use any of these call identifiers in subsequent call related requests fails with Result =
  *  CIRC_CC_INVALID_CALLID.*/
    CI_CC_PRIM_SWITCH_CALLMODE_REQ,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_SWITCH_CALLMODE_CNF,		/**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
    CI_CC_PRIM_ESTABLISH_MPTY_REQ, /**< \brief Requests establishment of a multiparty (MPTY) conference call
									* \details This request is used to establish a multiparty call, starting with an active call and a held call.
 *   If this request completes successfully, the active and held calls are joined into a multiparty call, which
 *   then becomes active. The original call identifiers still exist for the two calls, and both calls are now marked as
 *   MPTY calls in their respective Call Information structures.*/
    CI_CC_PRIM_ESTABLISH_MPTY_CNF, /**< \brief Confirms the request to establish a multiparty (MPTY) conference call
								   * \details If Result indicates an error, the MPTY identifier is not valid and should be ignored.*/
    CI_CC_PRIM_ADD_TO_MPTY_REQ, /**< \brief Requests a new call to be added to an existing multiparty (MPTY) conference
								 * \details Before this request is sent, the existing MPTY call is held and the new call becomes active.
								 * On successful completion of this request, the expanded MPTY call becomes active.
 *    If a call was previously split from the MPTY call, this request can be used to add the call back into the conference. */
    CI_CC_PRIM_ADD_TO_MPTY_CNF,/**< \brief Confirms the request to add a new call to an existing multiparty (MPTY) conference call */
    CI_CC_PRIM_HOLD_MPTY_REQ = 60,  /**< \brief Requests an active multiparty (MPTY) call to be held
								* \details On successful completion of this request, the active MPTY call (if there is one) is held. */
    CI_CC_PRIM_HOLD_MPTY_CNF, 	/**< \brief Confirms the request to hold an active multiparty (MPTY) conference call */
    CI_CC_PRIM_RETRIEVE_MPTY_REQ,  /**< \brief Requests a held multiparty (MPTY) call to be retrieved
									* \details On successful completion of this request, the held MPTY call (if there is one) becomes active.*/
    CI_CC_PRIM_RETRIEVE_MPTY_CNF,   /**< \brief Confirms the request to retrieve a held multiparty (MPTY) conference call  */
    CI_CC_PRIM_SPLIT_FROM_MPTY_REQ,  /**< \brief Requests a call to be split from a multiparty (MPTY) conference
									  *  \details On successful completion of this request the existing MPTY call is held, except for the split call, which becomes active.
 * Use the CI_CC_PRIM_ADD_TO_MPTY_REQ request to add the split call back into the MPTY call. */
    CI_CC_PRIM_SPLIT_FROM_MPTY_CNF, /**< \brief Confirms the request to split a call from a multiparty (MPTY) conference call */
    CI_CC_PRIM_SHUTTLE_MPTY_REQ,  /**< \brief Requests to shuttle between a multiparty (MPTY) conference call and a single call
								   * \details The subscriber can use this request to shuttle back and forth between a multiparty (MPTY) call and a separate single call.
								   * This is similar to the shuttle operation between an active call and a held call. This is how it works:
  *  -	Single call active; MPTY call held   MPTY call active, single call held \n
  *  -	MPTY call active; single call held   Single call active, MPTY call held \n
  *  The shuttle operation is handled at the network. The mobile must send a hold (or hold MPTY) request for the current active call/MPTY, immediately followed (see below) by a retrieve (or retrieve MPTY) request for the held call/MPTY.
  *  There cannot be more than one held call at any time. To avoid this, the network must receive the retrieve request within five seconds of receiving the hold request.
  *  The same result could be achieved by sending a CI_CC_PRIM_HOLD_CALL_REQ or CI_CC_PRIM_HOLD_MPTY_REQ request for the active call/MPTY, followed by a CI_CC_RETRIEVE_CALL_REQ or CI_CC_RETRIEVE_MPTY_REQ request for the held call/MPTY. However, the above timing requirements may not be fulfilled by this method, and the shuttle operation could fail.
  * */
    CI_CC_PRIM_SHUTTLE_MPTY_CNF,	/**< \brief Confirms the request to shuttle between a multiparty (MPTY) conference call and a single call */
    CI_CC_PRIM_RELEASE_MPTY_REQ,   /**< \brief  Requests a multiparty (MPTY) conference call to be released
									* \details  On successful completion of this request, all calls for the MPTY call (if there is one) are released.
  *  To release calls individually from the MPTY call, use the CI_CC_RELEASE_CALL_REQ request.
									*/
    CI_CC_PRIM_RELEASE_MPTY_CNF,  /**< \brief Confirms the request to release an active multiparty (MPTY) conference call */
    CI_CC_PRIM_START_DTMF_REQ = 70,    /**< \brief Requests to start sending a DTMF digit to the network during an active call
								   * \details Valid DTMF digits are defined by the GSM Standard.
								   * DTMF digits can be sent only on an active speech connection, where a traffic channel has been allocated.
  *  A DTMF request cannot be sent while a previous DTMF request is still in progress. If this is attempted, the request fails with an error result.
  *  For this request, the application layer must handle the timing of individual DTMF digits, and must stop the transmission by issuing a CI_CC_PRIM_STOP_DTMF_REQ request at the appropriate time.
  */
    CI_CC_PRIM_START_DTMF_CNF,/**< \brief Confirms the request to start sending a DTMF digit to the network during an active call
							   * \details
  *  This confirmation is received in any of the following situations:
  *   -	 The DTMF digit was sent successfully.
  *   -	 A DTMF start reject message was received from the network.
  *   -	 SAC did not accept the DTMF request.
  *   -	 There was a timeout on receiving a response from the network.
   *  The application layer must handle the timing of individual DTMF digits, and must stop the transmission by issuing a CI_CC_PRIM_STOP_DTMF_REQ request at the appropriate time.
   *  */
    CI_CC_PRIM_STOP_DTMF_REQ,/**< \brief Requests to stop sending a DTMF digit to the network during an active call
							  * \details DTMF digits can only be sent on an active speech connection, where a traffic channel has been allocated.
 *   A DTMF request cannot be sent while a previous DTMF request is still in progress. If this is attempted, the request fails with an error result.
 *   Similarly, if this request is received when no DTMF tone is currently active, the request fails with an error result. */
    CI_CC_PRIM_STOP_DTMF_CNF, /**< \brief Confirms the request to stop sending a DTMF digit to the network during an active call
							   * \details This confirmation is received in any of the following situations:
							   * the DTMF digit was stopped successfully;
							   *  a DTMF stop reject message was received from the network;
							   *  SAC did not accept the DTMF request;
							   *  there was a timeout on receiving a response from the network. */

    CI_CC_PRIM_GET_DTMF_PACING_REQ,/**< \brief Requests the current DTMF pacing configuration values
									* \details The DTMF pacing configuration values are initially set to internal defaults.
 *   These values can be changed by a CI_CC_SET_DTMF_CONFIG_REQ request.
 *   The pacing configuration values are used by CI when sending strings of DTMF digits to the network. In this situation,
 *   CI performs a "handshake" with the network for each digit in turn, and uses the configured tone duration and inter-digit
 *   intervals to pace the individual tones. */
    CI_CC_PRIM_GET_DTMF_PACING_CNF,/**< \brief Confirms the request and returns the current DTMF pacing configuration values
									* \details There should be no reason for an unsuccessful result.
  *  On GSM, the network enforces the minimum inter-digit interval. SAC does not use the Interval field in the
  *  CiCcDtmfPacing structure. */
    CI_CC_PRIM_SET_DTMF_PACING_REQ, /**< \brief Requests to set the DTMF pacing configuration values
									 * \details If this request is not invoked, SAC uses default configuration values (CICC_MIN_DTMF_DURATION
  *  for duration and CICC_DTMF_DEFAULT_INTERVAL for interval).
  *  The pacing configuration values are used by SAC when sending strings of DTMF digits to the network
  *  (see the CI_CC_PRIM_SEND_DTMF_STRING_REQ request). In this situation, SAC performs a handshake with the
  *  network for each digit, and uses the configured tone duration and inter-digit intervals to pace the
  *  individual tones.
  *  SAC does not check for extremely large values in the supplied DTMF pacing configuration structure. However,
  *  if any of the pacing configuration values are set below the specified minimum values, which are specified in CICC_MIN_DTMF_DURATION
  *  for duration and CICC_DTMF_DEFAULT_INTERVAL for interval, this request fails with an error result.
  *  On GSM, the network enforces the minimum inter-digit interval. SAC does not use the interval field in the
  *  CiCcDtmfPacing structure. */
    CI_CC_PRIM_SET_DTMF_PACING_CNF, /**< \brief Confirms the request to set the DTMF pacing configuration values
									 * \details SAC returns an error result if any of the pacing configuration values are less then specified minimum values
  *  in the request (CICC_MIN_DTMF_DURATION for duration and CICC_DTMF_DEFAULT_INTERVAL for interval). */
    CI_CC_PRIM_SEND_DTMF_STRING_REQ,/**< \brief Requests a string of DTMF digits to be sent on an active call
									 * \details Valid DTMF digits are defined by the GSM Standard.
  *   DTMF digits can be sent only on an active speech connection, where a traffic channel has been allocated.
  *   If this is not the case, this request fails with an error result.
  *   As the GSM protocol provides only a single-digit DTMF control procedure, SAC sends the DTMF digits
  *   individually, using Start DTMF and Stop DTMF requests to the network.
  *   The DTMF pacing parameters (tone duration and inter-digit interval) can be specified by the
  *   CI_CC_PRIM_SET_DTMF_PACING_REQ request. See CICC_MIN_DTMF_DURATION
  *   and CICC_DTMF_DEFAULT_INTERVAL for the parameter defaults.
  *   On GSM, the network enforces the minimum inter-digit interval. SAC does not use the interval field in the
  *   CiCcDtmfPacing structure.*/
    CI_CC_PRIM_SEND_DTMF_STRING_CNF,/**< \brief Confirms the request to send a string of DTMF digits on an active call
									 * \details This confirmation is received in any of the following situations:
  *  the complete DTMF string was sent successfully;
  *  a DTMF Reject message (Start or Stop) was received from the network;
  *  SAC did not accept the DTMF request;
  *  there was a timeout on receiving a response from the network. */
    CI_CC_PRIM_CLIP_INFO_IND = 80,/**< \brief Indicates CLIP information (when enabled) for an incoming call
							  * \details CLIP indications are enabled or disabled by CI_SS_PRIM_SET_CLIP_OPTION_REQ.
  *  This indication is enabled by default.
  *  No explicit response is required. */
    CI_CC_PRIM_COLP_INFO_IND, /**< \brief Indicates CoLP information (when enabled locally) for an outgoing call
							   * \details CoLP indications are enabled or disabled by the CI_SS_PRIM_SET_COLP_OPTION_REQ.
 *   This indication is enabled by default.
 *   No explicit response is required.*/
    CI_CC_PRIM_CCM_UPDATE_IND, /**< \brief Indicates periodic current call meter (CCM) unsolicited reports
								* \details CCM unsolicited reports are enabled or disabled by CI_SS_PRIM_SET_CCM_OPTION_REQ.
								* If enabled indications are reported periodically, not more than once every 10 seconds during a call.
								* This indication is enabled by default.
								* No explicit response is required.*/
    CI_CC_PRIM_GET_CCM_VALUE_REQ, /**< \brief Requests the current value of the current call meter (CCM).
								   * \details The CCM value is normally requested only during a call, which is why this request is in the CC service group, but
  *  it can be requested at any time. Other quantities related to call charging (ACM, ACMmax, and PUCT) are accessible
  *  through the SIM Manager interface. For more information, see the SIM Service Group primitives. */
    CI_CC_PRIM_GET_CCM_VALUE_CNF, /**< \brief Confirms the request and returns the current value of the current call meter (CCM)
								   * \details If the Result Code indicates failure, the CCM value is not useful, and should be ignored. */
    CI_CC_PRIM_AOC_WARNING_IND,   /**< \brief Indicates an unsolicited advice of charge (AoC) warning
								   * \details If the advice of charge service is provisioned, SAC can send a warning indication during a call when the accumulated charge meter (ACM) is within 30 seconds of the programmed maximum (ACMmax) value.
								   * This indication can be enabled or disabled by the CI_SS_PRIM_SET_AOC_WARNING_ENABLE_REQ request.
In addition, this indication can be sent if a new incoming or outgoing call is set up when the ACM is within 30 seconds of the programmed ACMmax value.
This indication is enabled by default.
No explicit response is required.
*/
    CI_CC_PRIM_SSI_NOTIFY_IND,  	/**< \brief Indicates supplementary service intermediate (SSI) notification
									 * \details SSI notifications (if enabled, see CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ) are triggered by receipt of an intermediate supplementary service notification after mobile originated call setup, but before any call setup results are received.
									 * This notification is enabled by default.
									 * No explicit response is required.*/

    CI_CC_PRIM_SSU_NOTIFY_IND,	/**< \brief Indicates supplementary service unsolicited (SSU) notification
								 * \details SSU notifications (if enabled, see CI_SS_PRIM_SET_SS_NOTIFY_OPTIONS_REQ) are triggered by receipt of an unsolicited supplementary service notification at any of the following times:
								 * during mobile terminated call setup;
								 * during a call;
								 * whenever a forward check supplementary service notification is received (in call or out of call).
								 * This notification is enabled by default.
								 * No response is required.*/
    CI_CC_PRIM_LOCALCB_NOTIFY_IND,  /**< \brief  \details NOT SUPPORTED REMOVE FROM API  */
	CI_CC_PRIM_GET_ACM_VALUE_REQ,/**< \brief Requests the current value of the accumulated call meter (ACM)
								* \details The ACM value holds accumulated CCM units for the current call (if there is one) and all previous calls since the
 *  ACM was last reset. */

    CI_CC_PRIM_GET_ACM_VALUE_CNF = 90, /**< \brief Confirms the request and returns the current value of the accumulated call meter maximum value (ACMmax)
								   * \details If the Result code indicates failure, the ACMmax value is not useful, and should be ignored.*/
    CI_CC_PRIM_RESET_ACM_VALUE_REQ, /**< \brief Requests the accumulated call meter (ACM) to be reset to zero
									 * \details The ACM value holds accumulated CCM units for the current call (if there is one) and all previous calls since the ACM was last reset.
  *  This operation requires prior PIN2 verification.*/
    CI_CC_PRIM_RESET_ACM_VALUE_CNF,	/**< \brief Confirms the request to reset the accumulated call meter (ACM) to zero
									 * \details If the Result code indicates failure, the ACM value was not reset. */
    CI_CC_PRIM_GET_ACMMAX_VALUE_REQ, /**< \brief Requests the current value of the accumulated call meter maximum value (ACMmax)
									  * \details The ACMmax value holds the maximum value allowed for the ACM.
 *  If the ACM approaches the ACMmax value, SAC can issue a warning indication (if enabled).
									  * For more information, see the CI_CC_PRIM_AOC_WARNING_IND indication.*/
    CI_CC_PRIM_GET_ACMMAX_VALUE_CNF,	/**< \brief Confirms the request and returns the current value of the accumulated call meter maximum value (ACMmax)
										 * \details If the Result code indicates failure, the ACMmax value is not useful, and should be ignored.*/
    CI_CC_PRIM_SET_ACMMAX_VALUE_REQ,	/**< \brief Requests the accumulated call meter maximum (ACMmax) to be set to the supplied value
										 * \details The ACMmax value holds the maximum value allowed for the ACM.
 *   If the ACM is close to the ACMmax value, SAC can issue a warning indication (if enabled). For more information see the CI_CC_PRIM_AOC_WARNING_IND indication.
 *   Setting ACMmax to zero disables it, and effectively removes the maximum ACM limit. In this case, there are no CI_CC_PRIM_AOC_WARNING_IND indications, whether they are enabled locally or not.
 *   This operation requires prior PIN2 verification.*/
    CI_CC_PRIM_SET_ACMMAX_VALUE_CNF, /**< \brief Confirms the request to set the accumulated call meter maximum (ACMmax) value
								* \details  If the Result code indicates failure, the ACMmax value was not changed.*/
    CI_CC_PRIM_GET_PUCT_INFO_REQ, /**< \brief Requests the current Price per Unit and Currency Table (PUCT) information
								   * \details The PUCT information is used to enable the application to calculate the cost of a call, in a currency chosen by the subscriber.*/
    CI_CC_PRIM_GET_PUCT_INFO_CNF, /**< \brief Confirms the request and returns the current Price per Unit and Currency Table (PUCT) information
								   * \details If the Result code indicates failure, the PUCT information is not useful, and should be ignored. */
    CI_CC_PRIM_SET_PUCT_INFO_REQ, /**< \brief Requests the current Price per Unit and Currency Table (PUCT) information to be updated
								   *  \details The PUCT information is used to enable the application to calculate the cost of a call, in a currency chosen by the subscriber.
  *  This operation requires prior PIN2 validation.*/
    CI_CC_PRIM_SET_PUCT_INFO_CNF = 100, /**< \brief Confirms the request to update the current Price per Unit and Currency Table (PUCT) information
								   *  \details If the Result code indicates failure, the PUCT information was not updated.*/
    CI_CC_PRIM_GET_BASIC_CALLMODES_REQ, /**< \brief  Requests the basic call modes currently supported for outgoing calls
										 * \details The basic call mode is used when placing an outgoing call request while the current call mode is set to single mode.
										 * See CI_CC_PRIM_MAKE_CALL_REQ for more information.
  										 *  See CI_CC_PRIM_SET_CALLMODE_REQ for default call mode information. */

    CI_CC_PRIM_GET_BASIC_CALLMODES_CNF, /**< \brief  Confirms the request and returns the basic call modes currently supported for outgoing calls
										 * \details Use this request to return the supported basic call modes (or types).
  *  To place an outgoing call when the call mode is set to single mode, the basic call mode must be specified in the outgoing call request.
										 * See CI_CC_PRIM_SET_CALLMODE_REQ for default call mode information.
  *  There should be no reason for an unsuccessful result. */
    CI_CC_PRIM_GET_CALLOPTIONS_REQ, /**< \brief Requests to get the call options currently supported for outgoing calls
									 * \details See CI_CC_PRIM_MAKE_CALL_REQ for more information.*/
    CI_CC_PRIM_GET_CALLOPTIONS_CNF, /**< \brief Confirms the request and returns the call options currently supported for outgoing calls
									 * \details Returns the call options currently supported for outgoing calls.
  *  There should be no reason for an unsuccessful result.*/
    CI_CC_PRIM_GET_DATACOMP_CAP_REQ, /**< \brief Requests to get the V.42 bis data compression configuration capability
									  * \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_GET_DATACOMP_CAP_CNF, /**< \brief Confirms the request and returns the V.42 bis data compression configuration capability
									  * \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_GET_DATACOMP_REQ,	/**< \brief Requests to get the current V.42 bis data compression information
									 *  \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_GET_DATACOMP_CNF,   /**< \brief Confirms the request and returns the current V.42 bis data compression information
									 *  \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_SET_DATACOMP_REQ, 	/**< \brief Requests to configure V.42 bis data compression
									 * \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_SET_DATACOMP_CNF = 110,    /**< \brief Confirms the request to configures V.42 bis data compression
									 *  \details Mandatory if V.42 bis is supported.*/
    CI_CC_PRIM_GET_RLP_CAP_REQ,     /**< \brief Requests to get RLP configuration capability for NT data calls
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_GET_RLP_CAP_CNF,     /**< \brief Confirms the request and returns the RLP configuration capability for NT data calls
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_GET_RLP_CFG_REQ,     /**< \brief Requests the current RLP configuration for a RLP version
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_GET_RLP_CFG_CNF,     /**< \brief Confirms the request and returns the current RLP configuration for the requested version
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_SET_RLP_CFG_REQ,     /**< \brief Requests to configure the RLP for NT data calls
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_SET_RLP_CFG_CNF,     /**< \brief Confirms the request to configure the RLP for NT data calls
									 * \details Mandatory if RLP is supported. */
    CI_CC_PRIM_DATA_SERVICENEG_IND, /**< \brief Indicates the report of bearer service, during connect negotiation for data calls
									 * \details No explicit response is required.
  *   This notification can be enabled or disabled by the CI_CC_PRIM_ENABLE_DATA_SERVICENEG_REQ request. It is disabled by
  *   default. */
    CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_REQ, /**< \brief Requests that bearer service reporting during connect negotiation for data calls be enabled or disabled
   *  \details */
    CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_CNF, /**< \brief Confirms the request to enable/disable bearer service reporting during
  *  connect negotiation for data calls
												* \details Mandatory if RLP is supported. */
    CI_CC_PRIM_SET_UDUB_REQ = 120, /**< \brief Requests that user determined user busy (UDUB) for a waiting or incoming call be set
							  *  \details Use this request if the subscriber opts to refuse a waiting or incoming call by setting a user determined user busy (UDUB) condition.
							  * This informs the network that the call may be redirected to another number (if already set up).
  *  The network may clear the call with a busy indication to the calling party.*/
    CI_CC_PRIM_SET_UDUB_CNF,  /**< \brief Confirms the request to set UDUB for a waiting or incoming call
							  *  \details */
    CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_REQ, /**< \brief Requests a list of supported call manipulation operation codes for
  *   supplementary services within a call
							  *  \details These operations are described in TS 22.030, Section 6.5.5.1, and are implemented
  *   by the "AT+CHLD" command in TS 27.007 Section 7.13.*/
    CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_CNF,  /**< \brief Confirms the request and returns a list of supported call manipulation operation codes for
  *  supplementary services within a call
							  *  \details */
    CI_CC_PRIM_MANIPULATE_CALLS_REQ, /**< \brief Requests call manipulation for supplementary services within a call
							  *  \details This primitive performs the operations described in TS 22.030, Section 6.5.5.1,
									  * and are implemented by the "AT+CHLD" command in TS 27.007 Section 7.13.
  *  The CallId parameter is used only for the CI_CC_MANOP_RLS_CALL and CI_CC_MANOP_HOLD_ALL_EXCEPT_ONE operations.*/
    CI_CC_PRIM_MANIPULATE_CALLS_CNF,   /**< \brief Confirms the request to perform call manipulation for supplementary services within a call
							  *  \details */
    CI_CC_PRIM_LIST_CURRENT_CALLS_IND,   /**< \brief Indicates the current call information
							  *  \details */

 CI_CC_PRIM_CALL_DIAGNOSTIC_IND, /**< \brief  Indicates the diagnostic octets of a specific call
							  *  \details Diagnostic information is sent by the protocol stack in one of the following
 * notifications: CcDisconnectInd, CcDisconnectedInd, CcDisconnectingInd, CcFailureInd.
								  * SAC processes these signals and sends a corresponding CI indication primitive
 * (CI_CC_PRIM_DISCONNECT_IND, CI_CC_PRIM_MO_CALL_FAILED_IND, CI_CC_PRIM_MT_CALL_FAILED_IND,
 *  CI_DAT_PRIM_NOK_IND) but it does not include the diagnostic information.
 *  SAC sends the CiCcCustPrimCallDiagnosticInd each time it receives any of these
 * notifications from the protocol stack.
								  */
    CI_CC_PRIM_DTMF_EVENT_IND,   /**< \brief  Indicates a DTMF event
							  *  \details This notification is sent each time SAC receives a confirmation signal from the protocol
 * stack indicating that a start/stop DTMF request has been successfully completed.
 * In case of a single DTMF tone, the notification is sent along with the CiCcPrimStartDtmfCnf
 * and CiCcPrimStopDtmfCnf.
 * In case of a DTMF tone sequence, the notification is sent for each tone in the sequence
 * when that tone is started/stopped.
 * A DTMF aborted indication is sent when a Start or Stop DTMF request is rejected by SAC or the
 * network for various reasons (see GSM TS 04.08 section 8.4 and section 5.5.7.2.); also if no
 * answer is received from the network. */
    CI_CC_PRIM_CLEAR_BLACK_LIST_REQ, /**< \brief Requests to clear the call blacklist
							  *  \details To clear the entire blacklist is not yet supported by the protocol stack.
 * A blacklist is created by the protocol stack with the numbers that
 * are used to initiate MO calls and are marked as auto-dial numbers.
 * In this case, SAC would have to create its own blacklist and save all
 * the auto-dial numbers that are reported by the protocol stack as blacklisted.
 * For clearing the entire list, it sends a separate 'clear blacklist'
 * request for each dial number in the blacklist.
									  * NOTE: To support the blacklist functionality CI must add the capability of
 *       specifying if a number is auto-dial, when an MO call is requested.*/
    CI_CC_PRIM_CLEAR_BLACK_LIST_CNF = 130,  /**< \brief Confirms the request and returns the completion status of the request
							  *  \details */
    CI_CC_PRIM_SET_CTM_STATUS_REQ,  /**< \brief Requests to set the status of the CTM state when a CTM jack is connected and CTM is enabled in MENU
							  *  \details */
    CI_CC_PRIM_SET_CTM_STATUS_CNF, /**< \brief Confirms the request to set the status of the CTM state when a CTM jack is connected and CTM is enabled in MENU
							  *  \details */
    CI_CC_PRIM_CTM_NEG_REPORT_IND,  /**< \brief Indicates the CTM negotiation status report
							  *  \details */
	/*Michal Bukai - CDIP support */
	CI_CC_PRIM_CDIP_INFO_IND, /**< \brief  Indicates a report for CDIP information for an incoming call
							  *  \details CDIP indications are enabled or disabled by the CI_SS_SET_CDIP_OPTION_REQ request.
							   * This indication is enabled by default.
							   * No explicit response is required.*/
    CI_CC_PRIM_SYNC_AUDIO_REQ,  /**< \brief Requests to sync audio path.
                                                          *  \details */
    CI_CC_PRIM_SYNC_AUDIO_CNF,  /**< \brief Confirms a request to sync audio path.
                                                           * \details */
	/*Michal Bukai - ALS support - START */
	CI_CC_PRIM_GET_LINE_ID_REQ,/**< \brief Requests to read the selected line ID for outgoing calls.
								*  \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.
								*	A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.
								*	Each line will be associated with a separate directory number (MSISDN) and separate subscription profile.
								*	For outgoing calls, the handset shall enable the user to select the desired line.*/
	CI_CC_PRIM_GET_LINE_ID_CNF,/**< \brief Confirms the request and returns the selected line ID.
								*  \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.
								*	A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.
								*	Each line will be associated with a separate directory number (MSISDN) and separate subscription profile.
								*	For outgoing calls, the handset shall enable the user to select the desired line.*/
	CI_CC_PRIM_SET_LINE_ID_REQ,/**< \brief Requests to set the line ID for outgoing calls.
								*  \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.
								*	A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.
								*	Each line will be associated with a separate directory number (MSISDN) and separate subscription profile.
								*	For outgoing calls, the handset shall enable the user to select the desired line.*/
	CI_CC_PRIM_SET_LINE_ID_CNF = 140,/**< \brief Confirms the request and sets user requested line ID.
								*  \details ALS provides the MS with the capability of associating two alternate lines with one IMSI.
								*	A user will be able to make and receive calls on either line as desired and will be billed separately for calls on each line.
								*	Each line will be associated with a separate directory number (MSISDN) and separate subscription profile.
								*	For outgoing calls, the handset shall enable the user to select the desired line.*/
	/*Michal Bukai - ALS support - END */
	CI_CC_PRIM_READY_STATE_IND,
/*add by cherryli@2014.02.11 for CQ56277 begin.*/
	CI_CC_PRIM_SRVCC_STATUS_REQ,
	CI_CC_PRIM_SRVCC_STATUS_CNF,
/*add by cherryli@2014.02.11 for CQ56277 end.*/
    
    CI_CC_PRIM_CALL_END_INFO_IND,/*Added by cherryli@09.02.2014 for CQ69642.*/
/*merged by lxliu for CQ00098090 on 07152015 begin*/
/* CECALL */
    CI_CC_PRIM_SET_CECALL_REQ,      /**< \brief Request to trigger an eCall to the network.
                                    *  \details This CI is used when there is necessity to start eCall.
                                    *  eCall can be started manually in emergency case, automatically in the case car system decide that this is an emergency case;
                                    *  also manually for test purpose.*/
    CI_CC_PRIM_SET_CECALL_CNF,      /**< \brief Confirms the request to trigger an eCall to the network.*/
    CI_CC_PRIM_GET_CECALL_REQ,      /**< \brief Get command request the type of eCall that is currently in progress, if any.*/
    CI_CC_PRIM_GET_CECALL_CNF,      /**< \brief This command confirms the request and return type of eCall in progress or no eCall.*/
    CI_CC_PRIM_GET_CECALL_CAP_REQ,  /**< \brief Request to read the supported values and ranges of eCall type.*/
    CI_CC_PRIM_GET_CECALL_CAP_CNF = 150,  /**< \brief Confirms a request and return supported values of eCall type*/

    /*CI_CC_PRIM_CALL_PROGRESS_IND,   This primitive is removed by lxliu for CQ00100555*/
    /**< \brief This CI contains the progress indicator information element and is sent whenever a PROGRESS message is received
                                 * or another call control message (like SETUP, CALL PROCEEDING, ALERTING, CONNECT) includes the optional progress indicator
                                 * information element */

/*merged by lxliu for CQ00098090 on 07152015 end*/

/*Added by lxliu for CQ00100555 on 06082015*/
    CI_CC_PRIM_AUDIO_ECALL_TO_AP_INFO_IND,/*brief  This CI Indicates that the information which came from audio about ecall was sent to CI*/

    /*Merged by cherryli@04.26.2016 CQ105208 begin.*/
	CI_CC_PRIM_ECALL_CFG_REQ,		/**< \for eCall: defines what is the time interval in which the elapsed time since the eCall was operated (T3242/ T3243) is written to the NVM*/
	CI_CC_PRIM_ECALL_CFG_CNF,		/**< \for eCall: confirms the request to set the timer interval for writing to the NVM */
	CI_CC_PRIM_GET_ECALL_CFG_REQ,	/**< \for eCall: request to get the configured time interval for writing the elapsed time into the NVM, and if eCall operated - the elapsed time  */
	CI_CC_PRIM_GET_ECALL_CFG_CNF,	/**< \for eCall: response to the request to get the configured time interval and the elapsed time*/
	CI_CC_PRIM_ECALL_ONLY_REQ,		/**< \for eCallOnly: Forces the UE to act as an eCall-only mode */
	CI_CC_PRIM_ECALL_ONLY_CNF,		/**< \for eCallOnly: confirms the request to act as an eCall-only mode */
	CI_CC_PRIM_GET_ECALL_ONLY_REQ,	/**< \for eCallOnly: request to get the status of eCall-only mode */
	CI_CC_PRIM_GET_ECALL_ONLY_CNF,	/**< \for eCallOnly: confirms the request to get the status of eCall-only mode */
	CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_REQ = 160, /**< \brief Requests to set EMLPP subscriptions information */
	CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_CNF, /**< \brief Confirms request to set EMLPP subscriptions information */
	CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_REQ, /**< \brief Requests to get EMLPP subscriptions information */
	CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_CNF, /**< \brief Confirms request to get EMLPP subscriptions information */
    /*Merged by cherryli@04.26.2016 CQ105208 end.*/
	CI_CC_PRIM_LIST_CALL_INFO_IND, /*Added by cherryli@ 12.01.2017 CQ108522 .*/
    
    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_CC_PRIM_LAST_COMMON_PRIM' */
    /* END OF COMMON PRIMITIVES LIST */
    CI_CC_PRIM_LAST_COMMON_PRIM

    /* Customer specific extension primitives must be added starting from
     * CI_CC_PRIM_FIRST_CUST_PRIM = CI_CC_PRIM_LAST_COMMON_PRIM as the first identifier.
     * The actual primitive names and IDs are defined in the associated
     * 'ci_cc_cust_xxx.h' file.
     */

    /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiCcPrim;

/* specify the number of default common CC primitives */
#define CI_CC_NUM_COMMON_PRIM ( CI_CC_PRIM_LAST_COMMON_PRIM - 1 )
/**@}*/
/* the total number of primitives, CI_CC_NUM_PRIM, is calculated at the end
 * of this file based on existing customer extensions definitions, if any.
 */

/** \brief Call control return codes */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_CC {
    CIRC_CC_SUCCESS = 0,        		/**< Request completed successfully         */
    CIRC_CC_FAIL,               		/**< General failure (catch-all)            */
    CIRC_CC_INCOMPLETE_INFO,    		/**< Incomplete information for request     */
    CIRC_CC_BAD_DIALSTRING,     		/**< Invalid characters in dial string      */
    CIRC_CC_INVALID_ADDRESS,    		/**< Invalid address (phone number)         */
    CIRC_CC_INVALID_CALLID,     		/**< Invalid call identifier                */
    CIRC_CC_INVALID_MPTYID,     		/**< Invalid MPTY identifier                */
    CIRC_CC_NO_SERVICE,         		/**< No network service                     */
    CIRC_CC_FDN_ONLY,              		/**< Only fixed dialing numbers allowed     */
    CIRC_CC_EMERGENCY_ONLY,         	/**< Only emergency calls allowed           */
    CIRC_CC_CALL_BARRED,        		/**< Calls are barred                       */
    CIRC_CC_NO_MORE_CALLS,     		    /**< No more calls allowed                  */
    CIRC_CC_NO_MORE_TIME,       		/**< No more airtime left                   */
    CIRC_CC_NOT_PROVISIONED,    		/**< Service not provisioned                */
    CIRC_CC_CANNOT_SWITCH,      		/**< Call mode cannot be switched           */
    CIRC_CC_SWITCH_FAILED,      		/**< Failed to switch call mode             */
    CIRC_CC_REJECTED,           		/**< Request rejected by network            */
    CIRC_CC_TIMEOUT,            		/**< Request timed out                      */
    CIRC_CC_SIM_ACCESS_DENIED,      	/**< SIM access related error (CHV needed?) */
	CIRC_CC_INVALID_PARAMETER,			/**< Generic error - the requested service primitive has invalid parameters */
    CIRC_CC_INVALID_REQ,				/**< Generic error - the requested service primitive can not be handled at current state */
    CIRC_CC_SIM_NOT_READY,				/**< Generic error - the requested service primitive fails because SIM is not ready */
    CIRC_CC_ACCESS_DENIED,				/**< Generic error - the requested service primitive fails because access is denied */
	CIRC_CC_ST_MODIFIED,                /**< Call Modified By STK */
    /* << Define additional specific CC result codes here >> */
	/*added by cherryli@10.24.2018 CQ00112632 begin.*/
	CIRC_CC_RETRY,                      /**< Previous call is in disconnecting, retry later */
	/*added by cherryli@10.24.2018 CQ00112632 end.*/

    /* This one must always be last in the list! */
    CIRC_CC_NUM_RESCODES      		/**< Number of result codes defined */
} _CiCcResultCode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Result code
 *  \sa CIRC_CC
 * \remarks Common Data Section */
typedef UINT16 CiCcResultCode;

/**   \brief Call identifier (call ID)*/
/** \remarks Common Data Section */
typedef UINT16 CiCcCallId;

#define CICC_CALLID_MIN   0x0001  /* Minimum valid call identifier value */
#define CICC_CALLID_MAX   0xFFFF  /* Maximum valid call identifier value */
#define CICC_CALLID_NONE  0x0000  /* Indicates no call identifier assigned */

/**  \brief Multiparty call (MPTY) identifier */
/** \remarks Common Data Section */
typedef UINT16 CiCcMptyId;

#define CICC_MPTYID_MIN   0x0001  /* Minimum valid MPTY identifier value */
#define CICC_MPTYID_MAX   0xFFFF  /* Maximum valid MPTY identifier value */
#define CICC_MPTYID_NONE  0x0000  /* Indicates no MPTY identifier assigned */
/**@}*/
/**  \brief Call mode indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CMODE{
    CICC_CMODE_SINGLE = 0,      /**< Single mode (see below) */
    CICC_CMODE_ALT_VOICE_FAX,   /**< Alternating voice/fax (Teleservice 61) */
    CICC_CMODE_ALT_VOICE_DATA,  /**< Alternating voice/data (Bearer Svc 61) */
    CICC_CMODE_VOICE_THEN_DATA, /**< Voice followed by data (Bearer Svc 81) */
    /* This one must always be last in the list! */
    CICC_NUM_CMODES             /* Number of call modes defined */
} _CiCcCallMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call mode indicator
 * \sa CICC_CMODE */
/** \remarks Common Data Section */
typedef UINT8 CiCcCallMode;
/**@}*/
typedef enum CICC_CVMODE{
    CICC_CVMODE_CS_ONLY = 0,  
    CICC_CVMODE_VOIP_ONLY,  
    CICC_CVMODE_CS_PREFERRED, 
    CICC_CVMODE_VOIP_PREFERRED,   
    CICC_NUM_CVMODES           
} _CiCcVoiceMode;
typedef UINT8 CiCcVioceMode;

/* Default (Reset) Call Mode */
#define CICC_CMODE_DEFAULT  CICC_CMODE_SINGLE

/** \brief Basic call mode indicators - needed only if call mode is set for single mode (default) */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_BASIC_CMODE{
    CICC_BASIC_CMODE_VOICE = 0, 	/**< Basic call mode: voice */
    CICC_BASIC_CMODE_FAX,       		/**< Basic call mode: fax   */
    CICC_BASIC_CMODE_DATA,      		/**< Basic call mode: data  */

    /* This one must always be last in the list! */
    CICC_NUM_BASIC_CMODES       /* Number of basic call modes defined */
} _CiCcBasicCMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Basic call mode indicator
 * \sa CICC_BASIC_CMODE */
/** \remarks Common Data Section */
typedef UINT8 CiCcBasicCMode;
/**@}*/

/** \brief Current call mode indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CURRENT_CMODE{
    CICC_CURRENT_CMODE_VOICE = 0,               				/**< Voice only */
    CICC_CURRENT_CMODE_DATA,                    				/**< Data only */
    CICC_CURRENT_CMODE_FAX,                     				/**< Fax only */
    CICC_CURRENT_CMODE_VOICE_FB_DATA_IS_VOICE,  		/**< Voice followed by data, voice mode */
    CICC_CURRENT_CMODE_ALT_VOICE_DATA_IS_VOICE, 	/**< Alternating voice/data, voice mode */
    CICC_CURRENT_CMODE_ALT_VOICE_FAX_IS_VOICE,  		/**< Alternating voice/fax, voice mode  */
    CICC_CURRENT_CMODE_VOICE_FB_DATA_IS_DATA,   		/**< Voice followed by data, data mode  */
    CICC_CURRENT_CMODE_ALT_VOICE_DATA_IS_DATA,  	/**< Alternating voice/data, data mode  */
    CICC_CURRENT_CMODE_ALT_VOICE_FAX_IS_FAX,    		/**< Alternating voice/fax, fax mode    */
    CICC_CURRENT_CMODE_UNKNOWN,  /**< Unknown call mode */
    #ifdef SS_IPC_SUPPORT
	CICC_CURRENT_CMODE_EMERGENCY, /**< Emergency call mode */
	#endif

    /* This one must always be last in the list! */
    CICC_NUM_CURRENT_CMODES                     				/**< Number of current call modes defined */
} _CiCcCurrentCMode;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call mode indicator
 * \sa CICC_CURRENT_CMODE */
/** \remarks Common Data Section */
typedef UINT8 CiCcCurrentCMode;
/**@}*/


/**  \brief Current call state indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CURRENT_CSTATE{
    CICC_CURRENT_CSTATE_ACTIVE = 0, 		/**< Call is active     */
    CICC_CURRENT_CSTATE_HELD,      			/**< Call is held       */
    CICC_CURRENT_CSTATE_DIALING,    		/**< Dialing (MO call)  */
    CICC_CURRENT_CSTATE_ALERTING,   		/**< Alerting (MO call) */
    CICC_CURRENT_CSTATE_INCOMING,   		/**< Incoming MT call   */
    CICC_CURRENT_CSTATE_WAITING,    		/**< MT call waiting    */
    CICC_CURRENT_CSTATE_OFFERING,   		/**< MT call offering (call setup)  */
    /*Added by cherryli@ 12.01.2017 CQ108522 begin.*/
    CICC_CURRENT_CSTATE_DISCONNECTING,      /**< call in disconnect procedure.*/
    CICC_CURRENT_CSTATE_END,                /**< call is disconnected.*/
    /*Added by cherryli@ 12.01.2017 CQ108522 end.*/

    /* This one must always be last in the list! */
    CICC_NUM_CURRENT_CSTATES        /* Number of current call states defined  */
} _CiCcCurrentCState;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call state indicator
 * \sa CICC_CURRENT_CSTATE */
/** \remarks Common Data Section */
typedef UINT8 CiCcCurrentCState;
/**@}*/



/**  \brief Call direction values
*/
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CALL_DIRECTION{
    CICC_MO_CALL = 0,     	/**< Mobile originated call */
    CICC_MT_CALL          	/**< Mobile terminated call */
} _CiCcCallDirection;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call direction indicator
 * \sa CICC_CALL_DIRECTION */
/** \remarks Common Data Section */
typedef UINT8 CiCcCallDirection;
/**@}*/

/*add by cherryli@2014.02.11 for CQ56277 begin.*/
/**  \brief SRVCC HO values
*/
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_SRVCC_HO_STATE{
    CICC_SRVCC_HO_START,
    CICC_SRVCC_HO_SUCCESS,
    CICC_SRVCC_HO_CANCEL,
    CICC_SRVCC_HO_FAIL,
    
		CICC_SRVCC_HO_STATE

}_CiCcSrvccHoState;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call direction indicator
 * \sa CICC_CALL_DIRECTION */
/** \remarks Common Data Section */
typedef UINT8 CiCcSrvccHoState;
/**@}*/
/*add by cherryli@2014.02.11 for CQ56277 end.*/
/**  \brief Call type indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CALLTYPE{

    /* Single Modes */
    CICC_CALLTYPE_ASYNC = 0,            		 /**< Asynchronous transparent data                */
    CICC_CALLTYPE_SYNC,                			 /**< Synchronous transparent data                 */
    CICC_CALLTYPE_REL_ASYNC,            		/**< Asynchronous non-transparent data            */
    CICC_CALLTYPE_REL_SYNC,             			/**< Synchronous non-transparent data             */
    CICC_CALLTYPE_FAX,                  			/**< Facsimile                                    */
    CICC_CALLTYPE_VOICE,                			/**< Voice                                        */

    /* Voice mode followed by data mode (bearer service 81) */
    CICC_CALLTYPE_VOICE_THEN_ASYNC,     	/**< VOICE followed by ASYNC                      */
    CICC_CALLTYPE_VOICE_THEN_SYNC,      		/**< VOICE followed by SYNC                       */
    CICC_CALLTYPE_VOICE_THEN_REL_ASYNC, 	/**< VOICE followed by REL_ASYNC                  */
    CICC_CALLTYPE_VOICE_THEN_REL_SYNC,  	/**< VOICE followed by REL_SYNC                   */

    /* Alternating Voice/Data Mode, Voice Mode first (Bearer Service 61)                */
    CICC_CALLTYPE_ALT_VOICE_ASYNC,      		/**< Alternating VOICE/ASYNC, VOICE first         */
    CICC_CALLTYPE_ALT_VOICE_SYNC,       		/**< Alternating VOICE/SYNC, VOICE first          */
    CICC_CALLTYPE_ALT_VOICE_REL_ASYNC,  	/**< Alternating VOICE/REL_ASYNC, VOICE first     */
    CICC_CALLTYPE_ALT_VOICE_REL_SYNC,   	/**< Alternating VOICE/REL_SYNC, VOICE first      */

    /* Alternating Voice/Data Mode, Data Mode first (Bearer Service 61) */
    CICC_CALLTYPE_ALT_ASYNC_VOICE,      		/**< Alternating ASYNC/VOICE, ASYNC first         */
    CICC_CALLTYPE_ALT_SYNC_VOICE,       		/**< Alternating SYNC/VOICE, SYNC first           */
    CICC_CALLTYPE_ALT_REL_ASYNC_VOICE,  	/**< Alternating REL_ASYNC/VOICE, REL_ASYNC first */
    CICC_CALLTYPE_ALT_REL_SYNC_VOICE,   	/**< Alternating REL_SYNC/VOICE, REL_SYNC first   */

    /* Alternating Voice/Facsimile Modes (Teleservice 61) */
    CICC_CALLTYPE_ALT_VOICE_FAX,        		/**< Alternating VOICE/FAX, VOICE first           */
    CICC_CALLTYPE_ALT_FAX_VOICE,        		/**< Alternating VOICE/FAX, FAX first             */

    /* This one must always be last in the list! */
    CICC_NUM_CALLTYPES                 			/**< Number of call types defined */
} _CiCcCallType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call type indicators
 * \sa CICC_CALLTYPE */
/** \remarks Common Data Section */
typedef UINT8 CiCcCallType;
/**@}*/


/**  \brief Data bearer service type: Bearer service name indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_BSTYPE_NAME{

    /* UDI or 3.1 kHz Modem definitions */
    CICC_BSTYPE_NAME_DATA_ASYNC_UDI = 0,  	/**< Data circuit asynchronous (UDI, 3.1kHz)  */
    CICC_BSTYPE_NAME_DATA_SYNC_UDI,      	 /**< Data circuit synchronous (UDI, 3.1 kHz)  */
    CICC_BSTYPE_NAME_PAD_ASYNC_UDI,       	/**< PAD access asynchronous (UDI)            */
    CICC_BSTYPE_NAME_PACKET_SYNC_UDI,     	/**< Packet access synchronous (UDI)          */

    /* RDI definitions */
    CICC_BSTYPE_NAME_DATA_ASYNC_RDI = 0,  /**< Data circuit asynchronous (RDI)          */
    CICC_BSTYPE_NAME_DATA_SYNC_RDI,       	/**< Data circuit synchronous (RDI)           */
    CICC_BSTYPE_NAME_PAD_ASYNC_RDI,       	/**< PAD access asynchronous (RDI)            */
    CICC_BSTYPE_NAME_PACKET_SYNC_RDI,    	/**< Packet access synchronous (RDI)          */

    /* This one must always be last in the list! */
    CICC_NUM_BSTYPE_NAMES                 		/**< Number of bearer service names defined */
} _CiCcBsTypeName;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Bearer service name indicators
 * \sa CICC_BSTYPE_NAME */
/** \remarks Common Data Section */
typedef UINT8 CiCcBsTypeName;
/**@}*/


/** \brief Data bearer service type: Quality of service attribute or connection element indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_BSTYPE_CE{
    CICC_BSTYPE_CE_TRANSPARENT_ONLY = 0,  	/**< Transparent required               */
    CICC_BSTYPE_CE_NONTRANSPARENT_ONLY,   	/**< Non-transparent required           */
    CICC_BSTYPE_CE_PREFER_TRANSPARENT,    	/**< Either, transparent preferred      */
    CICC_BSTYPE_CE_PREFER_NONTRANSPARENT, 	/**< Either, non-transparent preferred  */

    /* This one must always be last in the list! */
    CICC_NUM_BSTYPE_CE                    				/**< Number of CE indicators defined */
} _CiCcBsTypeCe;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Quality of service attribute or connection element indicators
 * \sa CICC_BSTYPE_CE */
/** \remarks Common Data Section */
typedef UINT8 CiCcBsTypeCe;
/**@}*/


/** \brief Data bearer service type information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcDataBsTypeInfo_struct {
    CiBsTypeSpeed   Speed;   	 /**< Data speed indicator \sa CCI API Ref Manual */
    CiCcBsTypeName  Name;  	 /**< Bearer service name indicator \sa CiCcBsTypeName  */
    CiCcBsTypeCe    Ce;      		 /**< Connection element \sa CiCcBsTypeCe      */
} CiCcDataBsTypeInfo;

/** \brief  Supported data bearer service type parameter settings */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcSuppDataBsTypes_struct {
    CiNumericRange  bsTypeSpeedsRange;  	/**< Supported data speeds \sa CCI API Ref Manual  */
    CiNumericRange  bsTypeNamesRange; 	/**< Supported bearer service names \sa CCI API Ref Manual */
    CiNumericRange  bsTypeCeRange;  		/**< Supported connection elements \sa CCI API Ref Manual  */
} CiCcSuppDataBsTypes;

/** \brief Protocol discriminator as defined in 3GPP TS	24.008 section 10.5.4.25 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_PROTOCOL_DISC{

    CICC_PROTOCOL_DISC_USP = 0,         /* User specified protocol */
    CICC_PROTOCOL_DISC_OSIHLP,       	/* OSI higher layer protocol */
    CICC_PROTOCOL_DISC_X244,         	/* X.244 */
    CICC_PROTOCOL_DISC_RMCF3,         	/* Reserved for system mangement convergence function */
    CICC_PROTOCOL_DISC_IA5c4,          	/* IA5 characters */

    CICC_NUM_PROTOCOL_DISC       		/* Number of protocols discriminator defined */
} _CiCcProtocolDisc;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Protocols Discriminator values
 * \sa CICC_PROTOCOL_DISC */
/** \remarks Common Data Section */
typedef UINT8 CiCcProtocolDisc;
/**@}*/


/*Added by cherryli@ 12.01.2017 CQ108522 begin.*/
/**  \brief Callact mode indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_ACT_MODE{
	CICC_ACTMODE_NO_SRV =0,
	CICC_ACTMODE_CDMA,
    CICC_ACTMODE_GSM,   
    CICC_ACTMODE_UMTS, 
    CICC_ACTMODE_LTE,
    CICC_ACTMODE_TDS, 
    /* This one must always be last in the list! */
    CICC_NUM_ACTMODE             /* Number of call act modes defined */
} _CiCcActMode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call act mode indicator
 * \sa CICC_ACT_MODE */
/** \remarks Common Data Section */
typedef UINT8 CiCcActMode;
/**@}*/

/**  \brief AlertingType indicator values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_ALERTING_TYPE{
	CICC_AlERTING_TYPE_LOCAL,
	CICC_AlERTING_TYPE_REMOTE,
	CICC_NUM_AlERTING_TYPE
}_CiccAlertingType;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call act mode indicator
 * \sa CICC_ALERTING_TYPE*/
/** \remarks Common Data Section */
typedef UINT8 CiccAlertingType;
/**@}*/

/*Added by cherryli@ 12.01.2017 CQ108522 end.*/


/** \brief  Received user to user information.
*   \details If UUS1 SS is enabled during a call, the received UUS information will be indicated to the user.
*   Note that UUS information will be monitored on calls that the user activated UUS1 SS using CI_SS_PRIM_SET_UUS1_REQ.*/
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCCOptUUSInfo_struct {
    CiBoolean           UUSInfoValid;   /**< TRUE Indicates UUS information is valid  \sa CCI API Ref Manual */
	CiCcProtocolDisc	protocolDisc;   /**< Protocol discriminator as defined in 3GPP TS 24.008 section 10.5.4.25. This field is valid if UUSInfoValid == TRUE	\sa CiCcProtocolDisc*/
	CiString   			userUserInfo;	/**< User-user information element as defined in 3GPP TS 24.008 appendix O2. This field is valid if UUSInfoValid == TRUE \sa CCI API Ref Manual */
} CiCcOptUUSInfo;

/* Michal Bukai - IMS Support - End*/
/** \brief  Call Information structure.
*/
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcCallInfo_struct {
    CiCcCallId           CallId;        			/**< Unique call identifier \sa CiCcCallId  */
    CiBoolean            IsEmergency;   		/**< If TRUE indicates emergency call  \sa CCI API Ref Manual         */
    CiBoolean            IsMPTY;        		/**< If TRUE indicates this call is part of a multiparty call \sa CCI API Ref Manual  */
    CiCcCallDirection    Direction;     		/**< Call direction (MT or MO) indicator \sa CiCcCallDirection  */
    CiCcCurrentCState    State;         		/**< Current call state \sa CiCcCurrentCState                 */
    CiCcCurrentCMode     Mode;          		/**< Current call mode \sa CiCcCurrentCMode                 */
    CiCallerInfo        callerInfo;  			/**<  Caller information \sa CCI API Ref Manual */
    CiCcDataBsTypeInfo  dataSvcInfo; 	/**< Service information (for data calls) \sa CiCcDataBsTypeInfo_struct   */
    CiBoolean           IsAutoDial;    		/**<  If TRUE indicates an auto dial call \sa CCI API Ref Manual  */
#if !defined(PC_TTCN_INT_TEST)
	CiCcOptUUSInfo		optUUSInfo;			/**< Optional user to user information \sa CiCCOptUUSInfo  */
#endif
	UINT8				LineID;				/**< Line ID (ALS) - 1 or 2 */
	//CQ105208
	//CiCcCliValidity     CliValidity;        /**< CLI validity indicator*/
    CiCcEmlppCallPriority emlppCallPriority; /** calling-subscriber eMLPP call priority. coded according to 3GPP TS 24.008 section 10.5.1.11 */

} CiCcCallInfo;

/** \brief  MakeCall (dial) options (bitmap assignments) for individual outgoing call requests */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CALLOPTIONS {
    CICC_CALLOPTIONS_NONE           = 0x00, 	/**< CLIR as provisioned; no CUG information */
    CICC_CALLOPTIONS_CLIR_ALLOW     = 0x01, 	/**< Allow CLI presentation on this call     */
    CICC_CALLOPTIONS_CLIR_RESTRICT  = 0x02, 	/**< Restrict CLI presentation on this call  */
    CICC_CALLOPTIONS_CUG_ENABLE     = 0x04  	/**< Enable CUG information on this call      */
} _CiCcCallOptions;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief MakeCall (dial) options bitmap
 * \sa CICC_CALLOPTIONS */
/** \remarks Common Data Section */
typedef UINT8 CiCcCallOptions;
/**@}*/

/** \brief  Emergency service category bit definition */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_EMRGENCYCAT {
    CICC_EMERGENCYCAT_POLICE = 0,
    CICC_EMERGENCYCAT_AMBULANCE,
    CICC_EMERGENCYCAT_FIRE_BRIGADE,
    CICC_EMERGENCYCAT_MARINE_GUARD,
    CICC_EMERGENCYCAT_MOUNTAIN_RESCUE,
	CICC_NUM_EMERGENCYCAT
} _CiCcEmergencyCat;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Emergency service category bit definition
 * \sa CICC_EMRGENCYCAT */
/** \remarks Common Data Section */
typedef UINT8 CiCcEmergencyCat;
/**@}*/

/** \brief   Outgoing (make) call information
*/
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcMakeCallInfo_struct {
    CiCcBasicCMode   BasicCMode;  				/**< Basic call mode (if applicable) \sa CiCcBasicCMode */
    CiCcCallOptions  Options;     					/**< Call options bitmap \sa CiCcCallOptions    */
    CHAR             dialString[CI_MAX_ADDRESS_LENGTH];
    CiBoolean        IsAutoDial;    					/**< Is this an auto dial call? \sa CCI API Ref Manual   */
    CiBoolean        IsCtmCall;     					/**< Is this call is CTM TTY MO call? \sa CCI API Ref Manual */
    CiBoolean        IsEmergency;     					/**< Indicates if the call is an emergency call \sa CCI API Ref Manual */
    CiBitRange       ServiceCat;     					/**< Bit mask indicating the required emergency call service category. coded according to 3GPP TS 24.008[10][15] section 10.5.4.33. This filed is valid if IsEmergency is TRUE \sa CCI API Ref Manual */
  //CQ105208
    CiCcEmlppCallPriority emlppCallPriority;            /** User chosen eMLPP call priority. Coded according to 3GPP TS 24.008 section 10.5.1.11. Might be above the maximum priority level for which the service subscriber has a subscription in the network */
} CiCcMakeCallInfo;

/* Auto-Answer Timer Interval */
#define CICC_AUTOANSWER_INTERVAL  10  /* Interval is in seconds */

/** \brief  Status or failure cause codes \details Derived from TS 24.008, Table 10.5.123 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CAUSE {
    CICC_CAUSE_UNKNOWN = 0,               			/**< Unknown cause (includes "None")  */
    CICC_CAUSE_UNASSIGNED_NUMBER,         		/**< Unassigned (unallocated) number  */
    CICC_CAUSE_NO_ROUTE_TO_DEST,          		/**< No route to destination  */
    CICC_CAUSE_CHAN_UNACCEPTABLE,         		/**< Channel unacceptable */
    CICC_CAUSE_OPERATOR_BARRING,          		/**< Operator determined barring  */
    CICC_CAUSE_NORMAL_CLEARING,           		/**< Normal call clearing */
    CICC_CAUSE_USER_BUSY,                 			/**< User busy  */
    CICC_CAUSE_NO_USER_RESPONSE,          		/**< No user responding */
    CICC_CAUSE_ALERT_NO_ANSWER,           		/**< User alerting, no answer */
    CICC_CAUSE_CALL_REJECTED,             			/**< Call rejected  */
    CICC_CAUSE_NUMBER_CHANGED = 10,            		/**< Number changed */
    CICC_CAUSE_PREEMPTION,                			/**< Pre-emption  */
    CICC_CAUSE_NONSELECTED_USER_CLEAR,    	/**< Non selected user clearing */
    CICC_CAUSE_DEST_OUT_OF_ORDER,         		/**< Destination out of order */
    CICC_CAUSE_INVALID_NUMFORMAT,         		/**< Invalid number format (incomplete) */
    CICC_CAUSE_FACILITY_REJECT,           			/**< Facility rejected  */
    CICC_CAUSE_STATUSENQ_RESPONSE,       	       /**< Response to STATUS ENQUIRY */
    CICC_CAUSE_NORMAL_UNSPECIFIED,        		/**< Normal, unspecified  */
    CICC_CAUSE_NO_CCT_AVAILABLE,          		/**< No circuit/channel available */
    CICC_CAUSE_NETWORK_OUT_OF_ORDER,      	/**< Network out of order */
    CICC_CAUSE_TEMP_FAILURE = 20,              			/**< Temporary failure  */
    /*21-30*/
    CICC_CAUSE_CONGESTION,                			/**< Switching equipment congestion */
    CICC_CAUSE_ACCESSINFO_DISCARDED,     		 /**< Access information discarded */
    CICC_CAUSE_CIRCUIT_UNAVAILABLE,       		/**< Requested circuit/channel unavailable  */
    CICC_CAUSE_RESOURCES_UNAVAILABLE,     		/**< Resources unavailable, unspecified */
    CICC_CAUSE_QOS_UNAVAIL,               			/**< Quality of service (QoS) unavailable */
    CICC_CAUSE_FACILITY_NOTSUBSCRIBED,    		/**< Requested facility not subscribed  */
    CICC_CAUSE_MT_CALLBARRING_IN_CUG,     		/**< Incoming (MT) calls barred within CUG  */
    CICC_CAUSE_BEARERCAP_NOTAUTHORIZED,  	 /**< Bearer capability not authorized */
    CICC_CAUSE_BEARERCAP_UNAVAILABLE,     		/**< Bearer capability not available  */
    CICC_CAUSE_SVC_UNAVAILABLE = 30,          			/**< Service or option not available  */
    /*31-40*/
    CICC_CAUSE_BEARERSVC_NOT_IMPLEMENTED, 	/**< Bearer service not implemented */
    CICC_CAUSE_ACMMAX_REACHED,           			 /**< ACM equal to, or greater than, ACMmax  */
    CICC_CAUSE_FACILITY_NOT_IMPLEMENTED,  	/**< Requested facility not implemented */
    CICC_CAUSE_BEARERCAP_RDI_ONLY,        		/**< Only RDI bearer capability is available  */
    CICC_CAUSE_SVC_NOT_IMPLEMENTED,       		/**< Service or option not implemented  */
    CICC_CAUSE_INVALID_TRANSACTID,        		/**< Invalid transaction ID value */
    CICC_CAUSE_NOT_CUG_MEMBER,            		/**< User not member of CUG */
    CICC_CAUSE_DEST_INCOMPATIBLE,         		/**< Incompatible destination */
    CICC_CAUSE_INCORRECT_MESSAGE,         		/**< Semantically incorrect message */
    CICC_CAUSE_TRANSIT_NETWORK_INVALID = 40,   	/**< Invalid transit network selection  */
    /*41-50*/
    CICC_CAUSE_NO_SUCH_MSGTYPE,          		 /**< Message type non-existent or not implemented */
    CICC_CAUSE_MSGTYPE_WRONG_STATE,       		/**< Message type incompatible with current protocol state */
    CICC_CAUSE_NO_SUCH_IE,               		/**< Information element non-existent or not implemented */
    CICC_CAUSE_CONDITIONAL_IE_ERROR,     		 /**< Conditional IE error */
    CICC_CAUSE_MSG_WRONG_STATE,           		/**< Message incompatible with current protocol state */
    CICC_CAUSE_RECOVERY_AFTER_TIMEOUT,    	/**< Recovery after timer expiry  */
    CICC_CAUSE_PROTOCOL_ERROR,            		/**< Protocol error, unspecified  */
    CICC_CAUSE_INTERWORKING,              			/**< Interworking, unspecified  */

	/* Error codes originated locally */
    CICC_CAUSE_ABNORMAL,              			/**< Abnormal release  */
    CICC_CAUSE_ERROR_REESTABLISHMENT_BARRED = 50,       /**< Reestablishment barred  */
    /*51-60*/
    CICC_CAUSE_CELL_SELECTION_IN_PROGRESS,         /**< Cell seection in progress  */
    CICC_CAUSE_LOWER_LAYER_FAILURE,                /**< Lower layer failure  */
    CICC_CAUSE_RACH_FAIL,                          /**< Rach fail  */
    
    CICC_CAUSE_FDN_BLOCKED,                        /**< FDN Mismatch  */

    CICC_CAUSE_ACCESS_CLASS_BARRED,                /**< Cell barred  */

    CICC_CAUSE_MAND_IE_ERROR,                      /**< Invalid mandatory information */

    CICC_CAUSE_EMERGENCY_ONLY,              /**< Only Emergency calls allowed */
    CICC_CAUSE_NO_CS_SERVICE,
    CICC_CAUSE_DMM_DEDICATE,                       /**< other sim in dedicate mode */
    CICC_CAUSE_UNALLOCATED_TMSI = 60,                      /**< unallocated TMSI */
    /*61-70*/
    CICC_CAUSE_ILLEGAL_MS,                      /**< Illegal MS */
    CICC_CAUSE_ILLEGAL_ME,                      /**< Illegal ME */
    CICC_CAUSE_NETWORK_FAILURE,                      /**< Network failure */
    CICC_CAUSE_SYNCH_FAILURE,                      /**< Synch failure */
    CICC_CAUSE_CALL_CANNOT_BE_IDENTIFIED,                      /**< Call cannot be identified */
    CICC_CAUSE_AUTH_FAILURE,                    /**< Authentication failure */

    // 67

    /*Added by cherryli@09.02.2014 for CQ69642 begin.*/
    CICC_RRC_REL_CAUSE_NORMAL = 68,
    CICC_RRC_REL_CAUSE_UNSPEC,
    CICC_RRC_REL_CAUSE_PRE_EMPTIVE = 70,

    /*71-80*/
    CICC_RRC_REL_CAUSE_CONGESTION,
    CICC_RRC_REL_CAUSE_RE_ESTABLISH_REJECT,
    CICC_RRC_REL_CAUSE_DIRECTED_SIGNALLING_REESTABLISHMENT,
    CICC_RRC_REL_CAUSE_USER_INACTIVITY,
    /*Added by cherryli@09.02.2014 for CQ69642 end.*/

    /*Added by cherryli@06.28.2020 CQ00121837 begin.*/
	CICC_CAUSE_IN_REGISTER = 75,
    /*Added by cherryli@06.28.2020 CQ00121837 end.*/

    /* This one must always be last in the list! */
    CICC_NUM_CAUSES                       				/**< Number of cause codes defined  */
} _CiCcCause;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Status or failure cause codes
 * \sa CICC_CAUSE */
/** \remarks Common Data Section */
typedef UINT8 CiCcCause;
/**@}*/
/** \brief  Extended call type information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcExtCallType_struct {
    CiCcCallType   CallType;      			/**< Call type indicator \sa CiCcCallType   */
    CiSubaddrInfo subaddress;               /**< Optional subaddress information \sa CCI API Ref Manual */
} CiCcExtCallType;

/* Call Deflection (CD) Address Information */
//ICAT EXPORTED STRUCT
typedef struct CiCcCdAddressInfo_struct {
    CiBoolean        Present;     /* Is Call Deflection info present? */
    CiAddressInfo  number;
    CiSubaddrInfo  subaddress;

} CiCcCdAddressInfo;

/** \brief  DTMF pacing: Configuration information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcDtmfPacing_struct {
    UINT16  Duration;     	/**< DTMF tone duration (ms)    */
    UINT16  Interval;     		/**< Inter-digit interval (ms)  */
} CiCcDtmfPacing;

/* DTMF pacing: Minimum values (also used as defaults) */
#define CICC_MIN_DTMF_DURATION  300 /* Minimum DTMF tone duration (ms)        */
#define CICC_MIN_DTMF_INTERVAL  65  /* Minimum DTMF inter-digit interval (ms) */

/** \brief  CLI validity indicator values
 * \details Used in CLIP, CoLP, and call waiting indications */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CLI_VALIDITY{
    CLI_VALIDITY_VALID = 0,   		/**< CLI information is valid            */
    CLI_VALIDITY_WITHHELD,    	/**< CLI information withheld by caller  */
    CLI_VALIDITY_UNAVAILABLE, 	/**< CLI information is unavailable      */
	CLI_VALIDITY_NOT_PRESENT	/**< CLI information is not present 	 */
} _CiCcCliValidity;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CLI validity indicator
 * \sa CICC_CLI_VALIDITY */
/** \remarks Common Data Section */
typedef UINT8 CiCcCliValidity;
/**@}*/

/*add by cherryli begin*/

/** \brief  cause of notice indicator values
 * \details Used in CLIP */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CauseOfNoCli{

	CLI_CAUSE_OF_NO_CLI_UNAVAILABLE = 0,
	CLI_CAUSE_OF_NO_CLI_REJECT_BY_USER = 1,
	CLI_CAUSE_OF_NO_CLI_INTERACTION_WITH_OTHER_SERVICE = 2,
	CLI_CAUSE_OF_NO_CLI_COIN_LINE_PAYPHONE = 3
	
} _CiCauseOfNoCli;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CauseOfNoCli
 * \details Used in CLIP  */
/** \remarks Common Data Section */
typedef UINT8 CiCauseOfNoCli;
/**@}*/
/*add by cherryli end*/
/** \brief  Information for CLIP indications */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcClipInfo_struct {
	CiCcCallId   CallId;					/**< call identifier \sa CiCcCallId */
    CiCcCliValidity  CliValidity;   		/**< CLI validity indicator \sa CiCcCliValidity             */
    CiCallerInfo    callerInfo;              /**< Calling party (caller) information \sa CCI API Ref Manual  */
#ifdef SS_IPC_SUPPORT
	CiCauseOfNoCli	CauseOfNoCli;        /*add by cherryli*/	
#endif
} CiCcClipInfo;

/*Michal Bukai - CDIP support - Start:*/
/** \brief  Information for CDIP indications */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcCdipInfo_struct {
	CiCcCallId   CallId;			/**< call identifier \sa CiCcCallId */
    CiCcCliValidity  CliValidity;   /**< CLI validity indicator \sa CiCcCliValidity */
    CiCallerInfo    callerInfo;      /**< Called line Information \sa CCI API Ref Manual */
} CiCcCdipInfo;
/*SCR #1203743*/
/** \brief   Information for CoLP indications */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcColpInfo_struct {
	CiCcCallId   CallId;					/**< call identifier \sa CiCcCallId */
    CiCcCliValidity  CliValidity;   		/**< CLI validity indicator \sa CiCcCliValidity */
    CiCallerInfo    callerInfo;         /**< Connected party information \sa CCI API Ref Manual */
} CiCcColpInfo;

/** \brief  Information for call waiting (CW) indications */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcCwInfo_struct {
    CiCcCliValidity  CliValidity;   		/**< CLI validity indicator \sa CiCcCliValidity   */
    CiCallerInfo    callerInfo;			/**< Calling party (caller) information \sa CCI API Ref Manual */
  //CQ105208
    CiCcEmlppCallPriority emlppCallPriority; /** calling-subscriber eMLPP call priority. coded according to 3GPP TS 24.008 section 10.5.1.11 */
    CiBoolean             emlppAutoAnswer;   /**< Indicates whether it was decided by CP that the new incoming call should be auto-answered and on-going call shall be pre-empted */
} CiCcCwInfo;

/* PUCT Information */
#define CICC_MAX_CURR_LENGTH  3 /* Maximum length of current code string */

/** \brief  PUCT information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcPuctInfo_struct {
    CHAR            	curr[ CICC_MAX_CURR_LENGTH ]; 	/**< Currency string              */
    UINT16          	eppu;                         				/**< Extended price per unit      */
    CiBoolean       	negExp;                       			/**< TRUE if exponent is negative \sa CCI API Ref Manual */
    UINT8           	exp;                          				/**< Modulus of exponent          */
} CiCcPuctInfo;

/** \brief  Data compression direction values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICCDATACOMPDIR_TAG{
    CI_CC_DATACOMP_DIR_NONE = 0,  	/**< Negotiated, no compression (V.42 bis P0=0)             	*/
    CI_CC_DATACOMP_DIR_TX,        	/**< Transmit only                                          			*/
    CI_CC_DATACOMP_DIR_RX,        	/**< Receive only                                           			*/
    CI_CC_DATACOMP_DIR_BOTH,      	/**< Both directions, accept any direction (V.42 bis P0=11) 	*/

    /* This one must always be last in the list! */
    CI_CC_DATACOMPS_NUM_DIRS
} _CiCcDataCompDir;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Data compression direction
 * \sa CICCDATACOMPDIR_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiCcDataCompDir;
/**@}*/



/** \brief  Data compression information structure  */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcDataCompInfo_struct {
    CiCcDataCompDir 	dir;            		/**< Data compression direction, default: CI_CC_DATACOMP_BOTH \sa CiCcDataCompDir */
    CiBoolean       		zNegRequired;   	/**< Is compression negotiation required? Default: FALSE \sa CCI API Ref Manual */
    UINT16          		maxDict;        	/**< Maximum number of dictionary entries to be negotiated, [512-65535]         */
    UINT8           		maxStrLen;      	/**< Maximum string length to be negotiated (V.42 bis P2), [6-250], default: 6  */
} CiCcDataCompInfo;

/** \brief  Data compression capability */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcDataCompCap_struct {
    CiBitRange      		bitsDir;        			/**< Supported direction values \sa CCI API Ref Manual  */
    CiBitRange      		bitsNegComp;    		/**< Supported negotiation values \sa CCI API Ref Manual  */
    CiNumericRange  	maxDictRange;   		/**< Range of supported maximum number of dictionary entries \sa CCI API Ref Manual  */
    CiNumericRange  	maxStrLenRange; 	/**< Range of supported maximum string length to be negotiated \sa CCI API Ref Manual  */
} CiCcDataCompCap;

/** \brief  RLP config structure \details For valid range, default, and recommended value for each parameter refer to
 * 3GPP TS 24.022, 3.4.0, 5.5.
 */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcRlpCfg_struct {
    UINT8 winIWS;           		/**< IWF-to-MS window size                                			*/
    UINT8 winMWS;           		/**< MS-to-IWF window size                                			*/
    UINT8 ackTimer;         		/**< Acknowledgement timer (T1), units of 10 ms           		*/
    UINT8 reTxAttempts;     		/**< Retransmission attempts (N2)                         			*/
    UINT8 ver;              			/**< RLP version number, [0-2], default: 0, recommend: 2  	*/
    UINT8 reSeqPeriod;      		/**< Resequencing period (T4), units of 10 ms             		*/
    UINT8 initialT1;             		/**< Acknowledgement timer(T1), units of 10 ms  			*/
    UINT8 initialN2;             		/**< Retransmission attempts (N2), units of 10 ms 			*/
} CiCcRlpCfg;

/** \brief  RLP capability */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiCcRlpCap_struct {
    CiNumericRange  winIWSRange;       	 	/**< Range of supported IWF-to-MS window size  \sa CCI API Ref Manual. */
    CiNumericRange  winMWSRange;        	/**< Range of supported MS-to-IWF window size  \sa CCI API Ref Manual. */
    CiNumericRange  ackTimerRange;      		/**< Range of supported acknowledgement timer \sa CCI API Ref Manual.  */
    CiNumericRange  reTxAttemptsRange;  	/**< Range of supported retransmission attempts \sa CCI API Ref Manual. */
    CiBitRange      bitsVer;            			/**< Supported RLP version \sa CCI API Ref Manual.  					*/
    CiNumericRange  reSeqPeriodRange;   	/**< Range of supported resequencing period  \sa CCI API Ref Manual. 	*/
} CiCcRlpCap;

/**  \brief Call manipulate operation codes
 * 	 \details See TS 22.030 Section 6.5.5.1 and TS 27.007 Sections 7.13 (AT+CHLD) and 7.14 (AT+CTFR).
 *    Note that where both a held call and a waiting call exist, the waiting call always
 *    takes precedence in the call manipulate procedure.
 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICCCALLMANOP_TAG {

  CI_CC_MANOP_RLS_HELD_OR_UDUB = 0,     	/**< "AT+CHLD=0" - Release all held calls or set user determined user busy (UDUB) for a waiting call  */
  CI_CC_MANOP_RLS_ACT_ACCEPT_OTHER,     	/**< "AT+CHLD=1" - Release all active calls (if any exist) and accept the other (held or waiting) call*/
  CI_CC_MANOP_RLS_CALL,                 			/**< "AT+CHLD=1X" - Releases a specific active call X*/
  CI_CC_MANOP_HOLD_ACT_ACCEPT_OTHER,    /**< "AT+CHLD=2" Places all active calls (if any exist) on hold and accepts the other (held or waiting) call.*/
  CI_CC_MANOP_HOLD_ALL_EXCEPT_ONE,      	/**< "AT+CHLD=2X" - Places all active calls on hold except call X with which communication shall be supported*/
  CI_CC_MANOP_ADD_HELD_TO_MPTY,         	/**< "AT+CHLD=3" - Add a held call to the conversation (multiparty)*/
  CI_CC_MANOP_ECT,                     				/**< "AT+CHLD=4" - Connects the two calls and disconnects the subscriber from both calls (ECT)*/
  CI_CC_MANOP_CALL_REDIRECT,            		/**< "AT+CTFR" ("4*<number><SEND>") - Redirect an incoming or a waiting call to the specified number followed by SEND directory number */
  CI_CC_MANOP_CCBS,                     			/**< "AT+CHLD=5" - Activates the completion of calls when subscriber is busy */
  CI_CC_MANOP_NUM_OPS

} _CiCcCallManOp;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call manipulate operation code
 * \sa CICCCALLMANOP_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiCcCallManOp;
/**@}*/

/* SCR #123023 -- BEGIN */

/* Parameter definitions for CI "Release All Calls" request */
//ICAT EXPORTED ENUM
typedef enum CICC_RELEASE_WHICHCALLS
{
  CICC_WHICHCALLS_ALL_ACTIVE = 0,
  CICC_WHICHCALLS_ALL_HELD,
  CICC_WHICHCALLS_ALL_CALLS

} _CiCcReleaseWhichCalls;

typedef UINT8 CiCcReleaseWhichCalls;

/* SCR #123023 -- END */

/* -------------------------- CC Service Group Primitives ------------------------------ */
/** <paramref name="CI_CC_PRIM_GET_NUMBERTYPE_REQ">   */
typedef CiEmptyPrim CiCcPrimGetNumberTypeReq; 	/**< No parameters */

/** <paramref name="CI_CC_PRIM_GET_NUMBERTYPE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetNumberTypeCnf_struct{
    CiCcResultCode Result;	/**< Result code \sa CiCcResultCode */
    CiAddressType  numType;     /**< Type of number (address type) \sa CCI API Ref Manual */
} CiCcPrimGetNumberTypeCnf;

/** <paramref name="CI_CC_PRIM_SET_NUMBERTYPE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetNumberTypeReq_struct{
    CiAddressType  numType;       /**< Type of number (address type) \sa CCI API Ref Manual  */
} CiCcPrimSetNumberTypeReq;

/** <paramref name="CI_CC_PRIM_SET_NUMBERTYPE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetNumberTypeCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
} CiCcPrimSetNumberTypeCnf;
/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_CALLMODES_REQ">   */
typedef CiEmptyPrim CiCcPrimGetSupportedCallModesReq;

/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_CALLMODES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetSupportedCallModesCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    UINT8           NumModes;   /**< Number of supported call modes */
    CiCcCallMode    Modes[ CICC_NUM_CMODES ]; /**< Supported call modes \sa CiCcCallMode */
} CiCcPrimGetSupportedCallModesCnf;
/** <paramref name="CI_CC_PRIM_GET_CALLMODE_REQ">   */
typedef CiEmptyPrim CiCcPrimGetCallModeReq;

/** <paramref name="CI_CC_PRIM_GET_CALLMODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCallModeCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
    CiCcCallMode    Mode;   /**< Current call mode \sa CiCcCallMode */
} CiCcPrimGetCallModeCnf;

/** <paramref name="CI_CC_PRIM_SET_CALLMODE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCallModeReq_struct{
    CiCcCallMode  Mode; 	/**< Selected call mode \sa CiCcCallMode */
} CiCcPrimSetCallModeReq;

/** <paramref name="CI_CC_PRIM_SET_CALLMODE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCallModeCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
} CiCcPrimSetCallModeCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_REQ"> */
typedef CiEmptyPrim CiCcPrimGetSupportedDataBsTypesReq;

/* <INUSE> */

/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_DATA_BSTYPES_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetSupportedDataBsTypesCnf_struct{
    CiCcResultCode       Result;       	/**< Result code \sa CiCcResultCode */
    CiCcSuppDataBsTypes  types;          /**< Supported data bearer service type parameter settings \sa CiCcSuppDataBsTypes_struct */
} CiCcPrimGetSupportedDataBsTypesCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATA_BSTYPE_REQ">   */
typedef CiEmptyPrim CiCcPrimGetDataBsTypeReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATA_BSTYPE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetDataBsTypeCnf_struct{
    CiCcResultCode       Result; 			/**< Result code \sa CiCcResultCode */
    CiCcDataBsTypeInfo   info; 			    /**< Current data bearer service type information \sa CiCcDataBsTypeInfo_struct */
} CiCcPrimGetDataBsTypeCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DATA_BSTYPE_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDataBsTypeReq_struct{
    CiCcDataBsTypeInfo   info;
} CiCcPrimSetDataBsTypeReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DATA_BSTYPE_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDataBsTypeCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetDataBsTypeCnf;

typedef CiEmptyPrim CiCcPrimGetAutoAnswerActiveReq;

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetAutoAnswerActiveCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
    CiBoolean       Active;
} CiCcPrimGetAutoAnswerActiveCnf;

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetAutoAnswerActiveReq_struct{
    CiBoolean Active;
} CiCcPrimSetAutoAnswerActiveReq;

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetAutoAnswerActiveCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
} CiCcPrimSetAutoAnswerActiveCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_LIST_CURRENT_CALLS_REQ"> */
typedef CiEmptyPrim CiCcPrimListCurrentCallsReq;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_LIST_CURRENT_CALLS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimListCurrentCallsCnf_struct{
    CiCcResultCode  Result; 		/**< Result code \sa CiCcResultCode */
    UINT8           NumCalls;		/**<  Number of current calls */
    CiCcCallInfo    callInfo[ CICC_MAX_CURRENT_CALLS ];   /**<  Call information list \sa CiCcCallInfo_struct */
} CiCcPrimListCurrentCallsCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CALLINFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCallInfoReq_struct{
    CiCcCallId  CallId;		/**< Call identifier \sa CiCcCallId */
} CiCcPrimGetCallInfoReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CALLINFO_CNF"> */
 //ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCallInfoCnf_struct{
    CiCcResultCode   Result;			/**< Result code \sa CiCcResultCode */
    CiCcCallInfo    info;               /**< Current call information  \sa CiCcCallInfo_struct */
} CiCcPrimGetCallInfoCnf;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_MAKE_CALL_REQ"> */
 //ICAT EXPORTED STRUCT
typedef struct CiCcPrimMakeCallReq_struct{
    CiCcMakeCallInfo    info;           /**< Outgoing (make) call information  \sa CiCcMakeCallInfo_struct*/
} CiCcPrimMakeCallReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_MAKE_CALL_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimMakeCallCnf_struct{
    CiCcResultCode  Result;	/**< Result code \sa CiCcResultCode */
    CiCcCallId      CallId;       /**< Unique call identifier \sa CiCcCallId */
} CiCcPrimMakeCallCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_PROCEEDING_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallProceedingInd_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
    CiBoolean   InBandTones;  	/**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */
  //CQ105208
    CiCcEmlppCallPriority emlppCallPriorityGranted; /** The eMLPP call priority granted by the network. coded according to 3GPP TS 24.008 section 10.5.1.11 */
} CiCcPrimCallProceedingInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_MO_CALL_FAILED_IND"> */
 //ICAT EXPORTED STRUCT
typedef struct CiCcPrimMoCallFailedInd_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
    CiCcCause   Cause;			/**< Cause code \sa CiCcCause */
    CiBoolean   InBandTones;  	/**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */
								/* SCR #1255830 */
} CiCcPrimMoCallFailedInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ALERTING_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAlertingInd_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
    CiBoolean     InBandTones;	/**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */
} CiCcPrimAlertingInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CONNECT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimConnectInd_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
} CiCcPrimConnectInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_DISCONNECT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimDisconnectInd_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
    CiCcCause   Cause;			/**< Disconnect cause code \sa CiCcCause */
} CiCcPrimDisconnectInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_INCOMING_CALL_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimIncomingCallInd_struct{
    CiCcCallId       CallId;			/**< Incoming call identifier \sa CiCcCallId */
    CiCcExtCallType  callType;         /**< Extended call type information \sa CiCcExtCallType_struct */
   //CQ105208
    CiCcEmlppCallPriority emlppCallPriority; /** calling-subscriber eMLPP call priority. coded according to 3GPP TS 24.008 section 10.5.1.11 */
    CiBoolean             emlppAutoAnswer;   /**< Indicates whether it was decided by CP that the new incoming call should be auto-answered and on-going call shall be pre-empted */
} CiCcPrimIncomingCallInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_WAITING_IND">  */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallWaitingInd_struct{
    CiCcCallId   CallId;		/**< Waiting call identifier \sa CiCcCallId */
    CiCcCwInfo  info;          /**< Call waiting information for incoming call \sa CiCcCwInfo_struct */
} CiCcPrimCallWaitingInd;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_HELD_CALL_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimHeldCallInd_struct{
    CiCcCallId  CallId;		/**< Held call identifier \sa CiCcCallId */
} CiCcPrimHeldCallInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ANSWER_CALL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAnswerCallReq_struct{
    CiCcCallId  CallId;	/**< Call identifier \sa CiCcCallId */
} CiCcPrimAnswerCallReq;

/* <INUSE> */
/**	 <paramref name="CI_CC_PRIM_ANSWER_CALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAnswerCallCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcCallId      CallId;		/**< Call identifier \sa CiCcCallId */
} CiCcPrimAnswerCallCnf;
/* <INUSE> */
/** <paramref name="CI_CC_PRIM_REFUSE_CALL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRefuseCallReq_struct{
    CiCcCallId  CallId;			/**< Call identifier \sa CiCcCallId */
    UINT16   Cause;		/**< Cause Code. */
} CiCcPrimRefuseCallReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_REFUSE_CALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRefuseCallCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimRefuseCallCnf;
/** <paramref name="CI_CC_PRIM_MT_CALL_FAILED_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimMtCallFailedInd_struct{
    CiCcCallId  CallId; 		/**< Call identifier \sa CiCcCallId */
    CiCcCause   Cause;          /**< Cause of call failure  \sa CiCcCause */
	/* SCR #1255830 */
    CiBoolean   InBandTones;    /**< Indicates if in-band tones are available from network \sa CCI API Ref Manual */
} CiCcPrimMtCallFailedInd;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_HOLD_CALL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimHoldCallReq_struct{
    CiCcCallId  CallId;		/**< Call identifier for the active call \sa CiCcCallId */
} CiCcPrimHoldCallReq;

/* <NOTINUSE> */
/**  <paramref name="CI_CC_PRIM_HOLD_CALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimHoldCallCnf_struct{
    CiCcResultCode  Result;  /**< Result code \sa CiCcResultCode */
    CiCcCause       Cause;   	 /**< Not in use */
} CiCcPrimHoldCallCnf;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_RETRIEVE_CALL_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRetrieveCallReq_struct{
    CiCcCallId  CallId;		/**< Call identifier for the held call \sa CiCcCallId */
} CiCcPrimRetrieveCallReq;

/* <NOTINUSE> */
/** <paramref name="CI_CC_PRIM_RETRIEVE_CALL_CNF">  */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRetrieveCallCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcCause       Cause;		/**< Not in use */
} CiCcPrimRetrieveCallCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SWITCH_ACTIVE_HELD_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSwitchActiveHeldReq_struct{
    CiCcCallId  Active;	/**< Call identifier for the active call \sa CiCcCallId */
    CiCcCallId  Held;	/**< Call identifier for the held call \sa CiCcCallId*/
} CiCcPrimSwitchActiveHeldReq;

/* <NOTINUSE> */
/** <paramref name="CI_CC_PRIM_SWITCH_ACTIVE_HELD_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSwitchActiveHeldCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcCause       Cause;		/**< Not in use */
} CiCcPrimSwitchActiveHeldCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimExplicitCallTransferReq_struct{
    CiCcCallId  ActiveCall;		/**< Call identifier for the active call \sa CiCcCallId */
    CiCcCallId  HeldCall;		/**< Call identifier for the held call \sa CiCcCallId*/
} CiCcPrimExplicitCallTransferReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_EXPLICIT_CALL_TRANSFER_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimExplicitCallTransferCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimExplicitCallTransferCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_CALL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseCallReq_struct{
    CiCcCallId  CallId;		/**< Call identifier \sa CiCcCallId */
} CiCcPrimReleaseCallReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_CALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseCallCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimReleaseCallCnf;

/* <NOTINUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_ALL_CALLS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseAllCallsReq_struct{
    UINT8 WhichCalls;		/**< Not in use */
} CiCcPrimReleaseAllCallsReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_ALL_CALLS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseAllCallsCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimReleaseAllCallsCnf;

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSwitchCallModeReq_struct{
    CiCcCallId  CallId;
} CiCcPrimSwitchCallModeReq;

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSwitchCallModeCnf_struct{
    CiCcResultCode  Result;
} CiCcPrimSwitchCallModeCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ESTABLISH_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEstablishMptyReq_struct{
    CiCcCallId  ActiveCall;		/**< Call identifier for the active call \sa CiCcCallId */
    CiCcCallId  HeldCall;		/**< Call identifier for the held call \sa CiCcCallId */
} CiCcPrimEstablishMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ESTABLISH_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEstablishMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcMptyId      MptyId;		/**< MPTY identifier \sa CiCcMptyId */
} CiCcPrimEstablishMptyCnf;

/* <INUSE> */
/**  <paramref name="CI_CC_PRIM_ADD_TO_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAddToMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY identifier for the conference \sa CiCcMptyId */
    CiCcCallId  CallId;		/**< Call identifier for the new call \sa CiCcCallId */
} CiCcPrimAddToMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ADD_TO_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAddToMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimAddToMptyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_HOLD_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimHoldMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY Identifier \sa CiCcMptyId  */
} CiCcPrimHoldMptyReq;

/* <INUSE> */
/**	<paramref name="CI_CC_PRIM_HOLD_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimHoldMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimHoldMptyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RETRIEVE_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRetrieveMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY Identifier \sa CiCcMptyId */
} CiCcPrimRetrieveMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RETRIEVE_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimRetrieveMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimRetrieveMptyCnf;

/* <INUSE> */
/**	<paramref name="CI_CC_PRIM_SPLIT_FROM_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSplitFromMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY identifier for the conference \sa CiCcMptyId */
    CiCcCallId  CallId;		/**< Call identifier for the call to be split out \sa CiCcCallId */
} CiCcPrimSplitFromMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SPLIT_FROM_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSplitFromMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSplitFromMptyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SHUTTLE_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimShuttleMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY identifier for the conference \sa CiCcMptyId */
    CiCcCallId  CallId;		/**< Call identifier for the single call \sa CiCcCallId */
} CiCcPrimShuttleMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SHUTTLE_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimShuttleMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimShuttleMptyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_MPTY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseMptyReq_struct{
    CiCcMptyId  MptyId;		/**< MPTY identifier \sa CiCcMptyId */
} CiCcPrimReleaseMptyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RELEASE_MPTY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimReleaseMptyCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimReleaseMptyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_START_DTMF_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimStartDtmfReq_struct{
    CiCcCallId  CallId;		/**< Call identifier \sa CiCcCallId */
    UINT8       Digit;		/**< DTMF digit */
} CiCcPrimStartDtmfReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_START_DTMF_CNF"> */
 //ICAT EXPORTED STRUCT
typedef struct CiCcPrimStartDtmfCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimStartDtmfCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_STOP_DTMF_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimStopDtmfReq_struct{
    CiCcCallId  CallId;		/**< Call identifier \sa CiCcCallId */
} CiCcPrimStopDtmfReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_STOP_DTMF_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimStopDtmfCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimStopDtmfCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DTMF_PACING_REQ"> */
typedef CiEmptyPrim CiCcPrimGetDtmfPacingReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DTMF_PACING_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetDtmfPacingCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcDtmfPacing  Pacing;		/**< DTMF pacing configuration \sa CiCcDtmfPacing_struct */
} CiCcPrimGetDtmfPacingCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DTMF_PACING_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDtmfPacingReq_struct{
    CiCcDtmfPacing  Pacing;		/**< DTMF pacing configuration \sa CiCcDtmfPacing_struct */
} CiCcPrimSetDtmfPacingReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DTMF_PACING_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDtmfPacingCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetDtmfPacingCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SEND_DTMF_STRING_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSendDtmfStringReq_struct{
    CiCcCallId   CallId;		/**< Call identifier \sa CiCcCallId. */
    UINT8        digits[CICC_MAX_DTMF_STRING_LENGTH];	/**< DTMF digits */
} CiCcPrimSendDtmfStringReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SEND_DTMF_STRING_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSendDtmfStringCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSendDtmfStringCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CLIP_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimClipInfoInd_struct{
    CiCcClipInfo   info;				/**< CLIP information for incoming call \sa CiCcClipInfo_struct */
} CiCcPrimClipInfoInd;


/* Michal Bukai - CDIP Support - Start:*/
/** <paramref name="CI_CC_PRIM_CDIP_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCdipInfoInd_struct{
    CiCcCdipInfo   info;	/**< CDIP information for incoming call \sa  CiCcCdipInfo_struct */
} CiCcPrimCdipInfoInd;
/* Michal Bukai - CDIP Support - End*/

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_COLP_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimColpInfoInd_struct{
    CiCcColpInfo   info;					/**< CoLP information for incoming call \sa CiCcColpInfo_struct */
} CiCcPrimColpInfoInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CCM_UPDATE_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCcmUpdateInd_struct{
    UINT32  Ccm;			/**< Current CCM reading in Home units. Unsigned 24-bit integer. */
    UINT32  Duration;		/**< Current call duration in seconds. Unsigned 24-bit integer. */
} CiCcPrimCcmUpdateInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CCM_VALUE_REQ"> */
typedef CiEmptyPrim CiCcPrimGetCcmValueReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CCM_VALUE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCcmValueCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    UINT32          Ccm;			/**< Current CCM value in Home units. Unsigned 24-bit integer. */
    UINT32          Duration;		/**< Current call duration in seconds. Unsigned 24-bit integer. */
} CiCcPrimGetCcmValueCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_AOC_WARNING_IND"> */
typedef CiEmptyPrim CiCcPrimAocWarningInd;

/**  <paramref name="CI_CC_PRIM_SSI_NOTIFY_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSsiNotifyInd_struct{
    CiSsiNotifyInfo  info;	/**< Supplementary service intermediate (SSI) notification information \sa CI SS Spec */
} CiCcPrimSsiNotifyInd;

/** <paramref name="CI_CC_PRIM_SSU_NOTIFY_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSsuNotifyInd_struct{
    CiSsuNotifyInfo  info; /**< Supplementary service unsolicited (SSU) notification information \sa CI SS Spec */
} CiCcPrimSsuNotifyInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ACM_VALUE_REQ"> */
typedef CiEmptyPrim CiCcPrimGetAcmValueReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ACM_VALUE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetAcmValueCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    UINT32          Acm;			/**< Current ACM value. Unsigned 24-bit integer. */
} CiCcPrimGetAcmValueCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RESET_ACM_VALUE_REQ"> */
typedef CiEmptyPrim CiCcPrimResetAcmValueReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_RESET_ACM_VALUE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimResetAcmValueCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimResetAcmValueCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ACMMAX_VALUE_REQ"> */
typedef CiEmptyPrim CiCcPrimGetAcmMaxValueReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ACMMAX_VALUE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetAcmMaxValueCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    UINT32          AcmMax;		/**< Current ACMmax value. Unsigned 24-bit integer */
} CiCcPrimGetAcmMaxValueCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_ACMMAX_VALUE_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetAcmMaxValueReq_struct{
    UINT32  AcmMax;		/**< New ACMmax value. Unsigned 24-bit integer. */
} CiCcPrimSetAcmMaxValueReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_ACMMAX_VALUE_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetAcmMaxValueCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */

} CiCcPrimSetAcmMaxValueCnf;
/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_PUCT_INFO_REQ"> */
typedef CiEmptyPrim CiCcPrimGetPuctInfoReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_PUCT_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetPuctInfoCnf_struct{
    CiCcResultCode   Result;			/**< Result code \sa CiCcResultCode */
    CiCcPuctInfo    info;				/**< Current PUCT information \sa CiCcPuctInfo_struct */
} CiCcPrimGetPuctInfoCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_PUCT_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetPuctInfoReq_struct{
    CiCcPuctInfo    info;					/**< New PUCT information \sa CiCcPuctInfo_struct */
} CiCcPrimSetPuctInfoReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_PUCT_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetPuctInfoCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetPuctInfoCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_BASIC_CALLMODES_REQ"> */
typedef CiEmptyPrim CiCcPrimGetBasicCallModesReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_BASIC_CALLMODES_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetBasicCallModesCnf_struct{
    CiCcResultCode  	Result;								/**< Result code \sa CiCcResultCode */
    UINT8           		NumModes;							/**< Number of supported basic call modes */
    CiCcBasicCMode  	Modes[ CICC_NUM_BASIC_CMODES ]; 	/**< Supported basic call modes \sa CiCcBasicCMode  */
} CiCcPrimGetBasicCallModesCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CALLOPTIONS_REQ"> */
typedef CiEmptyPrim CiCcPrimGetCallOptionsReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CALLOPTIONS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCallOptionsCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
    CiCcCallOptions Options;		/**< Supported call options bitmap \sa CiCcCallOptions */
} CiCcPrimGetCallOptionsCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATACOMP_CAP_REQ"> */
typedef CiEmptyPrim CiCcPrimGetDataCompCapReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATACOMP_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetDataCompCapCnf_struct{
    CiCcResultCode   	Result;				/**< Result code \sa CiCcResultCode */
    CiCcDataCompCap  cap;					/**< Data compression configuration capability \sa CiCcDataCompCap_struct */
} CiCcPrimGetDataCompCapCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATACOMP_REQ"> */
typedef CiEmptyPrim CiCcPrimGetDataCompReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_DATACOMP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetDataCompCnf_struct{
    CiCcResultCode     	Result;				/**< Result code \sa CiCcResultCode */
    CiCcDataCompInfo   	info;				/**< Data compression information \sa CiCcDataCompInfo_struct */
} CiCcPrimGetDataCompCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DATACOMP_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDataCompReq_struct{
    CiCcDataCompInfo   		info;				/**< Data compression information  \sa CiCcDataCompInfo_struct */
} CiCcPrimSetDataCompReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_DATACOMP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetDataCompCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetDataCompCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_RLP_CAP_REQ"> */
typedef CiEmptyPrim CiCcPrimGetRlpCapReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_RLP_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetRlpCapCnf_struct{
    CiCcResultCode   Result;			/**< Result code \sa CiCcResultCode */
    CiCcRlpCap      cap;				/**< Data compression configuration capability \sa CiCcRlpCap_struct */
} CiCcPrimGetRlpCapCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_RLP_CFG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetRlpCfgReq_struct{
    UINT8 ver;			/**< RLP version.  */
} CiCcPrimGetRlpCfgReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_RLP_CFG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetRlpCfgCnf_struct{
    CiCcResultCode   	Result;					/**< Result code \sa CiCcResultCode */
    CiCcRlpCfg       		 cfg;						/**< RLP configuration \sa CiCcRlpCfg_struct */
} CiCcPrimGetRlpCfgCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_RLP_CFG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetRlpCfgReq_struct{
    CiCcRlpCfg   	cfg;							/**< RLP configuration \sa CiCcRlpCfg_struct */
} CiCcPrimSetRlpCfgReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_RLP_CFG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetRlpCfgCnf_struct{
    CiCcResultCode  Result;			/**< Result code \sa CiCcResultCode */
} CiCcPrimSetRlpCfgCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_DATA_SERVICENEG_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimDataServiceNegInd_struct{
    CiBoolean isAsync;				/**< Sync/async indication \sa CCI API Ref Manual */
    CiBoolean isTransparent;		/**< Transparent/non-transparent indication \sa CCI API Ref Manual */
} CiCcPrimDataServiceNegInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEnableDataServiceNegIndReq_struct{
    CiBoolean enable;		/**<  TRUE: enable reporting; FALSE: disable reporting, default \sa CCI API Ref Manual */
} CiCcPrimEnableDataServiceNegIndReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ENABLE_DATA_SERVICENEG_IND_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEnableDataServiceNegIndCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimEnableDataServiceNegIndCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_UDUB_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetUDUBReq_struct{
    CiCcCallId  CallId;		/**< Call identifier \sa CiCcCallId */
} CiCcPrimSetUDUBReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_UDUB_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetUDUBCnf_struct{
    CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetUDUBCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_REQ"> */
typedef CiEmptyPrim CiCcPrimGetSupportedCallManOpsReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_SUPPORTED_CALLMAN_OPS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetSupportedCallManOpsCnf_struct{
    CiCcResultCode  	Result;									/**< Result code \sa CiCcResultCode */
    UINT8           		NumOps;								/**< Number of operation codes [0..CI_CC_MANOP_NUM_OPS - 1] */
    CiCcCallManOp   	OpCodes[ CI_CC_MANOP_NUM_OPS ];		/**< Array of supported operation codes \sa CiCcCallManOp */
}   CiCcPrimGetSupportedCallManOpsCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_MANIPULATE_CALLS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimManipulateCallsReq_struct{
    CiCcCallManOp OpCode;		/**< Call manipulation operation code \sa CiCcCallManOp */
    CiCcCallId    	CallId;           /**< Call identifier \sa CiCcCallId */
} CiCcPrimManipulateCallsReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_MANIPULATE_CALLS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimManipulateCallsCnf_struct{
    CiCcResultCode Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimManipulateCallsCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_LIST_CURRENT_CALLS_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimListCurrentCallsInd_struct{
    UINT8           	NumCalls;							/**< Number of current calls [0..CICC_MAX_CURRENT_CALLS] */
    CiCcCallInfo    	callInfo[ CICC_MAX_CURRENT_CALLS ];	/**< Call information list \sa CiCcCallInfo_struct */
} CiCcPrimListCurrentCallsInd;

/*add by cherryli@2014.02.11 for CQ56277 begin.*/
/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SRVCC_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSrvccStatusReq_struct{
    UINT8           	NumCalls;							/**< Number of current calls [0..CICC_MAX_CURRENT_CALLS] */
    CiCcCallInfo    	callInfo[ CICC_MAX_CURRENT_CALLS ];	/**< Call information list \sa CiCcCallInfo_struct */
} CiCcPrimSrvccStatusReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SRVCC_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSrvccStatusCnf_struct{
	  CiCcCallId	CallId;
    CiCcResultCode Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSrvccStatusCnf;
/*add by cherryli@2014.02.11 for CQ56277 end.*/


/** \brief  DTMF tone status indicators */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_TONESTATUS{
  CICC_TONE_STARTED,     /**< DTMF tone started */
  CICC_TONE_STOPPED,     /**< DTMF tone stopped normally */
  CICC_TONE_ABORTED      /**< DTMF tone aborted due to abnormal condition */
} _CiCcToneStatus;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief DTMF tone status indicator
 * \sa CICC_TONESTATUS */
/** \remarks Common Data Section */
typedef UINT8 CiCcToneStatus;
/**@}*/

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_DTMF_EVENT_IND"> */

//ICAT EXPORTED STRUCT
typedef struct CiCcPrimDtmfEventInd_struct {

  CiCcCallId      	CallId;       		/**< Identifier of the call for which a DTMF operation was required \sa CiCcCallId */
  UINT8           	ToneDigit;    		/**< Indicates the DTMF tone digit; valid = "0123456789*#ABCD" */
  CiBoolean       	SingleTone;		/**< Indicates a single DTMF tone or a tone sent as part of a DTMF string \sa CCI API Ref Manual */
  CiCcToneStatus  ToneStatus;   	/**< Indicates the DTMF tone status (started, aborted, or stopped) \sa CiCcToneStatus*/

} CiCcPrimDtmfEventInd;

/* customer specific data types */

/* The cause IE is a type 4 information element with a minimum length of 4 octets
 * and a maximum length of 32 octets. The diagnostic field starts in byte 5. */
#define CICC_MAX_CAUSE_DIAGNOSTIC_LENGTH  28

/** \brief  Diagnostics information */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct _CiCcDiagnosticInfo_struct {

    UINT16  Length;  	/**< Number of bytes in diagnostic information */
    UINT8   Data[CICC_MAX_CAUSE_DIAGNOSTIC_LENGTH];    /**< Diagnostic information */

}  CiCcDiagnosticInfo;

/** \brief Coding standard
 * \details Coding standard is defined in octet 3 of Cause Information Element. See TS 24.008 10.5.4.11.
 * This coding standard is also used in the Progress Indicator, Call State,
 * High Layer Compatibility, and Low Layer Compatibility. */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiCcCodingStandardTag
{
    CICC_CODING_CCITT_Q931           =   0,			/**< Coding as specified in ITU-T Rec. Q.931 */
    CICC_CODING_OTHER_INTERNATL      =   1,		/**< Reserved for other international standards */
    CICC_CODING_NATIONAL             =   2,			/**< National standard */
    CICC_CODING_GSM_NETWORK          =   3		/**< Standard defined for the GSM PLMNS */
} _CiCcCodingStandard;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Coding standard (octet 3 of Cause Information Element) as per 24.008 10.5.4.11
 * \sa CiCcCodingStandardTag */
/** \remarks Common Data Section */
typedef UINT8 CiCcCodingStandard;
/**@}*/

/** \brief Location */
/** \details Location is defined in octet 3 of Cause Information Element. See TS 24.008 10.5.4.11.*/
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiCcLocationTag
{
    CICC_LOC_USER                    =   0,			/**< User */
    CICC_LOC_PRIV_LOCAL              =   1,		/**< Private network serving the local user */
    CICC_LOC_PUB_LOCAL               =   2,		/**< Public network serving the local user */
    CICC_LOC_TRANSIT                 =   3,			/**< Transit network */
    CICC_LOC_PUB_REMOTE              =   4,		/**< Public network serving the remote user */
    CICC_LOC_PRIV_REMOTE             =   5,		/**< Private network serving the remote user */
    CICC_LOC_INTERNATIONAL           =   7,		/**< International network */
    CICC_LOC_BEYOND_IWF              =   10		/**< Network beyond interworking point */
} _CiCcLocation;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Location (octet 3 of Cause Information Element) as per 24.008 10.5.4.11
 * \sa CiCcLocationTag */
/** \remarks Common Data Section */
typedef UINT8 CiCcLocation;
/**@}*/
/** \brief Recommendation
 * \details Recommendation is defined in octet 3a of Cause Information Element. See TS 24.008 10.5.4.11.
 * Recommendation shall be ignored if the coding standard is "CICC_CODING_GSM_NETWORK".
 * For all other coding standards 'Recommendation' is coded according to the specified coding standard.
 */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiCcRecommendationTag
{
    CICC_REC_Q931	=   0,	/**< Recommendation Q.931: "ISDN user-network interface layer 3 specification for basic control" */
    CICC_REC_GSM	=   1,      /**< Recommendation GSM */
    CICC_REC_X21		=   3,	/**< Recommendation X.21: "Interface between data terminal equipment (DTE) and data circuit-terminating equipment (DCE) for synchronous operation on public data networks" */
    CICC_REC_X25		=   4	/**< Recommendation X.25: "Interface between data terminal equipment (DTE) and data circuit-terminating equipment (DCE) for terminals operating in the packet mode and connected to public data networks by dedicated circuit" */
} _CiCcRecommendation;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Recommendation.
 * \sa CiCcRecommendationTag */
/** \remarks Common Data Section */
typedef UINT8 CiCcRecommendation;

/**  \brief Status or failure cause codes
 * \sa CiCcCause */
/** \remarks Common Data Section */
typedef CiCcCause CiCcCustCause;
/**@}*/
/** \brief Diagnostic information */

/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct _CiCcDiagnostic_struct {

  CiBoolean             		InfoPresent;			/**< TRUE - is present; FALSE - is not present \sa CCI API Ref Manual */
  CiCcCodingStandard		Coding;				/**< Coding standard (octet 3 of Cause Information Element) as per 24.008 10.5.4.11 \sa CiCcCodingStandard*/
  CiCcLocation          		Location;			/**< Location (octet 3 of Cause Information Element) as per 24.008 10.5.4.11 \sa CiCcLocation */
  CiCcRecommendation		Recommendation;	/**< Recommendation \sa CiCcRecommendation */
  CiCcCustCause         		Cause;				/**< Cause code \sa CiCcCustCause */
  CiCcDiagnosticInfo		Info;				/**< Diagnostic information \sa _CiCcDiagnosticInfo_struct */

} CiCcDiagnostic;

/* customer specific primitives */

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_DIAGNOSTIC_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallDiagnosticInd_struct {

  CiCcCallId          CallId;			/**< Call identifier \sa CiCcCallId */
  CiCcDiagnostic   Diagnostic1;		/**< First diagnostic information field \sa _CiCcDiagnosticInfo_struct */
  CiCcDiagnostic   Diagnostic2;		/**< Second diagnostic information field \sa _CiCcDiagnosticInfo_struct */

} CiCcPrimCallDiagnosticInd;


/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CLEAR_BLACK_LIST_REQ">  */
typedef CiEmptyPrim CiCcPrimClearBlackListReq;


/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CLEAR_BLACK_LIST_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimClearBlackListCnf_struct {

  CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */

} CiCcPrimClearBlackListCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_CTM_STATUS_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCtmStatusReq_struct {
    CiBoolean   Active;			/**< Current CTM status \sa CCI API Ref Manual */
}CiCcPrimSetCtmStatusReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_CTM_STATUS_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCtmStatuscnf_struct {
     CiCcResultCode  Result;		/**< Result code \sa CiCcResultCode */
} CiCcPrimSetCtmStatusCnf;

/** \brief CTM negotiation report status - values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CiCcCTMNegReportType_Tags {
	CTM_STARTED=1,   	/**< Started */
	CTM_SUCCEDED,		/**< Succeeded */
	CTM_FAILED			/**< Failed */
} _CiCcCTMNegReportType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief CTM negotiation report status
 * \sa CiCcCTMNegReportType_Tags */
/** \remarks Common Data Section */
typedef UINT8 CiCcCTMNegReportType;
/**@}*/

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CTM_NEG_REPORT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCTMNegReportInd_struct{
	CiCcCTMNegReportType CTMNegReport;		/**< Negotiation status result \sa CiCcCTMNegReportType */
}CiCcPrimCTMNegReportInd;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SYNC_AUDIO_REQ">  */
typedef CiEmptyPrim CiCcPrimSyncAudioReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SYNC_AUDIO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSyncAudioCnf_struct {
  CiCcResultCode  Result;       /**< Result code. \sa CiCcResultCode */
} CiCcPrimSyncAudioCnf;

/* Michal Bukai - IMS Support - Start:*/

/** \brief Protocol discriminator as defined in 3GPP TS	24.008 section 10.5.4.25 */

/***********************************************/
/*Michal Bukai - ALS support - START 		   */
/***********************************************/

/** <paramref name="CI_CC_PRIM_GET_LINE_ID_REQ">   */
typedef CiEmptyPrim CiCcPrimGetLineIdReq; 	/**< No parameters */

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_LINE_ID_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetLineIdCnf_struct {
	CiCcResultCode  	Result;				/**< Result code \sa CiCcResultCode */
	UINT8				LineID;				/**< Line ID - 1 or 2 */
}CiCcPrimGetLineIdCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_LINE_ID_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetLineIdReq_struct {
	UINT8				LineID;				/**< Line ID - 1 or 2 */
}CiCcPrimSetLineIdReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_LINE_ID_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetLineIdCnf_struct {
	CiCcResultCode  	Result;				/**< Result code \sa CiCcResultCode */
}CiCcPrimSetLineIdCnf;

/***********************************************/
/*Michal Bukai - ALS support - END	 		   */
/***********************************************/



/*************************************************/
/*Michal Bukai - Call Deflection support - START */
/*************************************************/
/** \brief Call deflection failure cause values */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CD_CAUSE{

    CICC_CD_ERROR = 0,			/* NW responded with error to call deflection request */
    CICC_CD_REJECT,       		/* OSI higher layer protocol */
    CICC_CD_NO_NW_RESPONSE,         	/* X.244 */
    CICC_CD_CALL_RELEASED,         	/* Reserved for system mangement convergence function */

    CICC_NUM_CD_CAUSE       		/* Number of protocols discriminator defined */
} _CiCcCDCauseType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call deflection failure cause
 * \sa CICC_PROTOCOL_DISC */
/** \remarks Common Data Section */
typedef UINT8 CiCcCDCauseType;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_DEFLECT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallDeflectReq_struct {
    CiCcCallId			CallId;				/**< Call identifier \sa CiCcCallId */
    CiAddressInfo		DeflectedNumber;	/**< Call identifier \sa CiAddressInfo */
    CiSubaddrInfo		DeflectedSubAddress;/**< Call identifier \sa CiSubaddrInfo */
}CiCcPrimCallDeflectReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_DEFLECT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallDeflectCnf_struct {
     CiCcResultCode  	Result;							/**< Result code \sa CiCcResultCode */
     CiCcCDCauseType	CallDeflectionFailCause;		/**< Call deflection failure cause \sa CiCcCDCauseType */
} CiCcPrimCallDeflectCnf;
/***********************************************/
/*Michal Bukai - Call Deflection support - END */
/***********************************************/
/* <INUSE> */
/**	 <paramref name="CI_CC_PRIM_READY_STATE_IND"> */
typedef CiEmptyPrim CiCcPrimReadyStateInd;

/*Merged for CQ00098090 by lxliu on 07152015 begin*/
/* CECALL */

/** \brief Call control return codes */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CI_CC_ECALL_TYPE {
    CI_CC_ECALL_TYPE_TEST = 0,			/**< test call */
    CI_CC_ECALL_TYPE_RECONFIGURE = 1,	/**< reconfiguration call */
    CI_CC_ECALL_TYPE_MANUAL = 2,		/**< manually initiated */
    CI_CC_ECALL_TYPE_AUTOMATIC = 3,		/**< automatically initiated */
    CI_CC_ECALL_TYPE_NO_ACTIVE = 4		/**< no active eCall */
} _CiCcECallTypeCode;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief eCall type */
typedef UINT16 CiCcECallTypeCode;
typedef UINT16 CiCcECallBitMaskTypes;

/** <paramref name="CI_CC_PRIM_SET_CECALL_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCeCallReq_struct {
    CiCcECallTypeCode	eCallType;			/**< eCall type */
}CiCcPrimSetCeCallReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_CECALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetCeCallCnf_struct {
     CiCcResultCode  	Result;				/**< Result code \sa CiCcResultCode */
} CiCcPrimSetCeCallCnf;

/** <paramref name="CI_CC_PRIM_GET_CECALL_REQ">   */
typedef CiEmptyPrim CiCcPrimGetCeCallReq; 	/**< No parameters */

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CECALL_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCeCallCnf_struct {
	CiCcResultCode  	Result;				/**< Result code \sa CiCcResultCode */
	CiCcECallTypeCode	eCallType;			/**< eCall type */
}CiCcPrimGetCeCallCnf;

/** <paramref name="CI_CC_PRIM_GET_CECALL_CAP_REQ">   */
typedef CiEmptyPrim CiCcPrimGetCeCallCapReq; 	/**< No parameters */

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_CECALL_CAP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetCeCallCapCnf_struct {
	CiCcResultCode	 		Result;						/**< Result code \sa CiCcResultCode */
	CiCcECallBitMaskTypes	eCallBitMaskSupportedTypes;	/**< eCall type */
}CiCcPrimGetCeCallCapCnf;
/*Merged for CQ00098090 by lxliu on 07152015 end*/

/*Added by lxliu for CQ00100555 on 06082015 begin*/
/* 
* <parameref name="CI_CC_PRIM_AUDIO_ECALL_TO_AP_INFO_IND">
*/
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimAudioEcallToApInfoInd_struct
{
    UINT16 Length;
    UINT8 RawData[CICC_ECALL_AUDIO_INFO_MAX_LENGTH];
}CiCcPrimAudioEcallToApInfoInd;
/*Added by lxliu for CQ00100555 on 06082015 end*/


/* Added by cherryli@09.02.2014 for CQ69642 begin.*/
/** \Brief Call end message type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CE_CAUSE{

    CICC_CE_CALL_END_UNDEFINE = 0,		/*default value.*/	
    CICC_CE_CALL_END_NORMAL,       		/*according to 24.008. involved:User busy.No user responding.User alerting no answer.
                                          user rejected.Destination out of order.Number changed.*/
    CICC_CE_CALL_END_RX_DISCONNECT,         	
    CICC_CE_CALL_END_RX_RELEASE,         	
    CICC_CE_CALL_END_UNRECOVERABLE,     /*RLC Reset(MaxRST or UL lost.Unrecoverable error in RLC on reset PDU).
                                          Cell Update(unrecoverable error).*/
    CICC_CE_CALL_END_RLF_OR_WEAK_SIGNAL,/*RL failure(T313 Expire)or phych est failure(T312 expire.Sync start fail).
                                          Cell Update(RLF).*/
    CICC_CE_CALL_END_RX_RRC_CONNECTION_RELEASE,
    CICC_CE_CALL_END_TX_DISCONNECT,     /*User disconnect req from AP.*/
    CICC_CE_CALL_END_TX_RELEASE,        /*No used now.*/
    CICC_CE_CALL_END_OTHERS ,

    CICC_NUM_CE_CAUSE       		
} _CiCcCEEventType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call deflection failure cause
 * \sa CICC_PROTOCOL_DISC */
/** \remarks Common Data Section */
typedef UINT8 CiCcCEEventType;
/**@}*/

/** \Brief Call end release cause */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_CE_MSG{

    CICC_CE_MSG_TYPE_UNDEFINE = 0,			
    CICC_CE_MSG_TYPE_CELL_UPDATE ,       		
    CICC_CE_MSG_TYPE_DISCONNECT ,         	
    CICC_CE_MSG_TYPE_RELEASE ,         	
    CICC_CE_MSG_TYPE_RRC_CONNECTION_RELEASE ,

    CICC_NUM_CE_MSG       		
} _CiCcCEMsgType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Call deflection failure cause
 * \sa CICC_PROTOCOL_DISC */
/** \remarks Common Data Section */
typedef UINT8 CiCcCEMsgType;
/**@}*/


/*Add by taow for SSG request to get RRC release casue 20140902,CQ 69749, , end*/
typedef struct CiCcPrimCallDropCauseInd_struct{
	CiCcCEEventType CallDropEventType;
	CiCcCause 		CallDropCause;
	UINT16    		psc_cellParameterId;          /**< Primary scrambling code for FDD or Cell parameter id for TDD */
   	INT16     		rscp;        	/**< CPICH/PCCPCH received signal code power; in UMTS FDD/TDD messages RSCP is
                                    transmitted as an integer value in the range of -120 dBm to -25 dBm.
                                    The value is coded into integers from -5 to 99 according to 3GPP's 25.133.  */
    
	//UINT16  		eci0;
	INT16     		txPower;         		/**< UE transmitted power */
	//UINT16             sir;
	UINT8			numberOfRabs;
	//UINT16    		ul_arfcn;            			/**< Absolute radio frequency channel number */
	UINT16    		arfcn;            			/**< Absolute radio frequency channel number */
	UINT8     		Gsm_rxSigLevelFull;				/**< Receive signal level accessed over all TDMA frames  [range: 0h-3Fh]*/
	UINT8     		Gsm_rxQualityFull;  		/**< Receive quality accessed over all TDMA frames [range: 0-7] */
        
}CiCcPrimCallDropCauseInfoInd;
/*Add by taow for SSG request to get RRC release casue 20140902,CQ 69749, , end*/

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_CALL_END_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimCallEndInfoInd_struct{
    CiCcCallId			 CallId;				/**< Call identifier \sa CiCcCallId */
	CiCcCurrentCState    State;         		/**< Current call state \sa CiCcCurrentCState                 */
    CiCcCEMsgType        CallEndMsg;
    CiCcCEEventType      CallEndType;
    CiCcCause            CallEndCause;
    CiCcPrimCallDropCauseInfoInd
                         SacDevInfo;
}CiCcPrimCallEndInfoInd;

/* Added by cherryli@09.02.2014 for CQ69642 end.*/


//CQ105208
//eCall write to timer configuration


/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ECALL_CFG_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCCPrimEcallCfgReq_struct {
     UINT16 			time;				/**< The time interval for writing eCall elapsed time to the NVM */
     UINT16 			intimer1;			/**< The eCall inactivity timer value */
     UINT16 			intimer2;			/**< The eCall inactivity timer value */
} CiCcPrimEcallCfgReq;


/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ECALL_CFG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCCPrimEcallCfgCnf_struct {
     CiCcResultCode			result;				/**< Result code \sa CiCcResultCode */
} CiCcPrimEcallCfgCnf;





/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ECALL_CFG_REQ">   */
typedef CiEmptyPrim CiCcPrimGetEcallCfgReq; 	/**< Request to get the time interval configured for writing to the NVM   */


/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ECALL_CFG_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCCPrimGetEcallCfgCnf_struct{
     CiCcResultCode			result;				/**< Result code \sa CiCcResultCode */
	 UINT16					time;				/**< The interval to write to the NVM, the eCall elapsed time */
	 UINT16					rtime;				/**< If an eCall was operated - the time elapsed since eCall was operated  */
	 UINT16					intimer1;			/**< The eCall inactivity timer value  */
	 UINT16					intimer2;			/**< The eCall inactivity timer value  */
} CiCcPrimGetEcallCfgCnf;


//eCallOnly

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ECALL_ONLY_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEcallOnlyReq_struct {
    CiBoolean Activate;                           /**< If set to TRUE, than UE will act as if the USIM is configured for eCall only mode. If set the FALSE, than the UE returns to normal mode of operation. */
    CHAR      testnum[CI_MAX_ADDRESS_LENGTH];     /**< The eCall test number */
    UINT8     testnumLen;
    CHAR      reconfignum[CI_MAX_ADDRESS_LENGTH]; /**< The eCall reconfiguration number */
    UINT8     reconfignumLen;
} CiCcPrimEcallOnlyReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_ECALL_ONLY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimEcallOnlyCnf_struct {
    CiCcResultCode Result;                        /**< Result code \sa CiCcResultCode */
} CiCcPrimEcallOnlyCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ECALL_ONLY_REQ">   */
typedef CiEmptyPrim CiCcPrimGetEcallOnlyReq; 	/**< Request to Get the eCall-only mode parameters */

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_ECALL_ONLY_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetEcallOnlyCnf_struct{
    CiCcResultCode Result;                 /**< Result code \sa CiCcResultCode */
    CiBoolean      Active;                 /**< If set to TRUE, than the UE is configured to act as eCall only mode. If SIM support eCall only always return FALSE */
    UINT8          simEcall;               /**< 0 â€?SIM does not support eCall (service No. 89 is â€œnot availableâ€?in the USIM); 1 â€?SIM supports eCall mode (Service No. 89 and Service No. 4 are "available"); 2 â€?SIM supports eCall only mode (Service No. 89 and Service No. 2 are "available" and FDN service is enabled in EFEST) */
    CHAR           testnum[CI_MAX_ADDRESS_LENGTH];     /**< The eCall test number */
    UINT8          testnumLen;
    CHAR           reconfignum[CI_MAX_ADDRESS_LENGTH]; /**< The eCall reconfiguration number */
    UINT8          reconfignumLen;
} CiCcPrimGetEcallOnlyCnf;
/* ********************************************************************************************* *
 * EMLPP
 */
/** \brief EMLPP subscriptions info types */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CICC_EMLPP_SUBSCRIPTIONS_INFO_TYPE {
  CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_ENABLED         = 0x00, /* Indicates the info type is enabled call priorities, only {0,1,..,4} are valid */
  CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_FAST_CALL_SETUP = 0x01, /* Indicates the info type is fast call set-up enabled priorities (and enabled), {0,1,..,4} are valid */
  CICC_EMLPP_CALL_SUBSCRIPTIONS_INFO_TYPE_AUTO_ANSWER     = 0x02, /* Indicates the info type is auto-answer enabled priorities (and enabled), all priorities are valid*/
} _CiCcEmlppSubscriptionsInfoType;

typedef UINT8 CiCcEmlppSubscriptionsInfoType;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetEmlppSubscriptionsInfoReq_struct {
  CiCcEmlppSubscriptionsInfoType infoType; /** Indicates which type of information is modified (fast call setup  OR automatic answer)*/
  CiCcEmlppCallPriority  callPriority;     /** Indicates which call priority shall be modified */
  CiBoolean      isEnabled;                /** Indicates whether the fast-call-set-up or auto-answer should be enabled/disabled */
} CiCcPrimSetEmlppSubscriptionsInfoReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_SET_EMLPP_SUBSCRIPTIONS_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimSetEmlppSubscriptionsInfoCnf_struct {
  CiCcResultCode Result;                  /**< Result code  \sa CiCcResultCode */
  CiCcEmlppSubscriptionsInfoType infoType; /** Indicates which type of information was modified*/
} CiCcPrimSetEmlppSubscriptionsInfoCnf;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetEmlppSubscriptionsInfoReq_struct {
  CiCcEmlppSubscriptionsInfoType infoType;  /** Indicates which type of information is required*/
} CiCcPrimGetEmlppSubscriptionsInfoReq;

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_GET_EMLPP_SUBSCRIPTIONS_INFO_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimGetEmlppSubscriptionsInfoCnf_struct {
  CiCcResultCode           Result;             /**< Result code  \sa CiCcResultCode */
  CiCcEmlppSubscriptionsInfoType   infoType;   /** Indicates which type of information is returned*/
  UINT8               numOfCallPriorities;     /** Indicates how many entries in the enabledCallPriorities array are valid*/
  CiCcEmlppCallPriority enabledCallPriorities[CICC_EMLPP_NUM_OF_PRIORITIES]; /** List of enabled priorities, depending on the infoType. it can be enabled / enabled + fast-call-set-up enabled /  enabled + auto-answer enabled */
} CiCcPrimGetEmlppSubscriptionsInfoCnf;

/*Added by cherryli@ 12.01.2017 CQ108522 begin.*/

/* <INUSE> */
/** <paramref name="CI_CC_PRIM_LIST_CALL_INFO_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiCcPrimListCallInfoInd_struct{
    UINT8           	NumCalls;							    /**< Number of current calls [0..CICC_MAX_CURRENT_CALLS] */
	CiCcActMode         callActMode;                            /**< Current network mode>*/
	CiccAlertingType    alertType[ CICC_MAX_CURRENT_CALLS ];    /**< InbandTones >*/
    CiCcCallInfo    	callInfo[ CICC_MAX_CURRENT_CALLS ];   	/**< Call information list \sa CiCcCallInfo_struct */
} CiCcPrimListCallInfoInd;
/*Added by cherryli@ 12.01.2017 CQ108522 end.*/



#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_cc_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_CC_NUM_CUST_PRIM will be set to 0 in the "ci_cc_cust.h" file.
 */
#include "ci_cc_cust.h"

#define CI_CC_NUM_PRIM ( CI_CC_NUM_COMMON_PRIM + CI_CC_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_CC_NUM_PRIM CI_CC_NUM_COMMON_PRIM

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

#endif /* _CI_CC_H_ */


/*                      end of ci_cc.h
--------------------------------------------------------------------------- */
