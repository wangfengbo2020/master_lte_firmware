/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File        : ci_dat.h
Description : Data types file for the DAT Service Group

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
#if !defined(_CI_DAT_H_)
#define _CI_DAT_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "ci_ps.h"
#include "ci_api_types.h"
#include "ci_cfg.h"
#if defined(ENV_LINUX)
#include "common_datastub.h"
#endif /*ENV_LINUX*/
#include "ci_mm.h"
/*CQ00128822 by xia 20200310 for nas unit test*/

//#ifdef NAS_UNIT_TEST
//#include "nas_stub.h"
//#endif
/** \addtogroup  SpecificSGRelated
 * @{ */

//#define CI_DAT_VER_MAJOR 4
//#define CI_DAT_VER_MINOR 0
#define CI_DAT_CURRENT_VER CI_SG_LATEST_VERSION // CP current version is always latest version


#ifdef PC_TTCN_INT_TEST
typedef int                 BOOL;
#endif
/* -----------------------------------------------------------------------------
 *    DAT Configuration definitions
 * ----------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------- */

/* CI_DAT Primitive ID definitions */
/** Summary of primitives */
//ICAT EXPORTED ENUM
typedef enum CI_DAT_PRIM {
    CI_DAT_PRIM_GET_MAX_PDU_SIZE_REQ = 1, /**< \brief Requests the maximum PDU size the underlying data link can send and receive\details */
    CI_DAT_PRIM_GET_MAX_PDU_SIZE_CNF,     /**< \brief Confirms the request to get the maximum PDU size the underlying transport link can send and receive
    									 * \details It is assumed that the upper layer of CI segments and assembles data based on this primitive.*/
    CI_DAT_PRIM_SEND_REQ,                 /**< \brief Requests CS/PS data
    *      \details This primitive is kept for backward compatibility. Instead, use CI_DAT_PRIM_SEND_DATA_OPT_REQ.*/
    CI_DAT_PRIM_SEND_CNF,					/**< \brief Confirms the request to send CS/PS data
    									 * \details This primitive is kept for backward compatibility. Instead, use CI_DAT_PRIM_SEND_DATA_OPT_CNF.*/
    CI_DAT_PRIM_RECV_IND,					/**< \brief Indicates receipt of CS/PS data
    									 * \details This primitive is kept for backward compatibility. Instead, use CI_DAT_PRIM_RECV_DATA_OPT_IND.*/
    CI_DAT_PRIM_RECV_RSP,					/**< \brief Responds confirming receipt of CS/PS data
    									 * \details  This primitive is kept for backward compatibility. Instead, use CI_DAT_PRIM_RECV_DATA_OPT_RSP.*/
    CI_DAT_PRIM_OK_IND,					/**< \brief  Indicates that a data connection was established
    									 * \details The data connection link should be set up using primitives in the CC or PS service group.
    									 * This primitive indicates that a data connection has been established and that data send and receive primitives can be used.*/
    CI_DAT_PRIM_NOK_IND,					/**< \brief  Indicates that a data connection was disconnected
    									 * \details The data connection link should be deactivated using primitives in the CC or PS
    *    service group before this primitive is used. After this primitive, sending and receiving data through the corresponding data connection is not allowed.*/
    /*  Begin of ACI optimization for data channel */
    CI_DAT_PRIM_SEND_DATA_OPT_REQ, 		/**< \brief Requests to send PS data over the optimized data plane
    									 * \details CI does not manipulate data by itself. It is a proxy, forwarding and receiving data between the application subsystem and cellular subsystem.
    									 * The maximum PDU size tells the upper layer of CI the throughput limitation between the application subsystem and cellular subsystem.
    									 * For example, for IP data, the upper layer of CI should build the IP packet based on the maximum PDU size or do IP fragmentation
    									 *  if the IP packet size is greater than the maximum PDU size.
    									 * The CI does not send or receive incomplete IP packets.
    									 * The same concept is applied to PPP data: the upper layer of CI makes sure the PPP data sent and received at the CI level is a whole PPP frame.
    									 * For raw data (such as CS streaming data), the upper layer of CI should split the raw data based on the maximum PDU size.\n
    									 * The data connection link should be set up using primitives in the CC or PS service group before this primitive is used.
    									 * For the data to be sent over the optimized data plane,
    									 * the CI_PS_PRIM_ENTER_DATA_STATE_REQ primitive must have been sent with the 'optimizedData' flag set to TRUE.
    									 * To avoid buffer overflow and data loss, do not send a new CI_DAT_PRIM_SEND_DATA_OPT_REQ primitive before a CI_DAT_PRIM_SEND_DATA_OPT_CNF primitive is received.
    									 * The data buffer can be freed or reused when the 'free primitive memory' callback function of the
    									 * CI_DAT_PRIM_SEND_DATA_OPT_REQ primitive is called by the lower layer; this may happen before or after the
    									 * CI_DAT_PRIM_SEND_DATA_OPT_CNF primitive is sent. */
    CI_DAT_PRIM_SEND_DATA_OPT_CNF = 10,    /**< \brief Confirms the request to send PS data over the optimized data plane \details   */
    CI_DAT_PRIM_RECV_DATA_OPT_IND,        /**< \brief Indicates that PS data was received over the optimized data plane
    									 * \details It is assumed that the upper layer of CI has segmented the data based on the
    									 * CI_DAT_PRIM_GET_MAX_PDU_SIZE_CNF primitive.
    									 * The data connection link must have been set up using primitives in the PS service group before this primitive can be used.
    									 * For the data to be sent over the optimized data plane, the CI_PS_PRIM_ENTER_DATA_STATE_REQ
    									 * primitive must have been sent with the 'optimizedData' flag set to TRUE.
    									 * To avoid buffer overflow and data loss, do not send a new CI_DAT_PRIM_RECV_DATA_OPT_IND primitive before a CI_DAT_PRIM_RECV_DATA_OPT_RSP primitive is received.
    									 * The Rx data buffer must be made available for reuse by the lower layer; for this purpose,
    									 * invoke the 'free primitive memory' callback function of the CI_DAT_PRIM_RECV_DATA_OPT_IND primitive (if it was registered).
    									 */
    CI_DAT_PRIM_RECV_DATA_OPT_RSP, 		/**< \brief Responds confirming receipt of CS/PS data over the optimized data plane
    									 * \details Response to received PS data over the optimized data plane.*/
    CI_DAT_PRIM_SET_UL_TP_IND_REQ,		/**< \brief Requests communication subsystem to enable/disable UL throughput indications and sets the report interval */
    CI_DAT_PRIM_SET_UL_TP_IND_CNF,		/**< \brief Confirms previous TP reports request */
    CI_DAT_PRIM_UL_TP_IND,				/**< \brief  Indicates UL throughput reports received from COMM MAC \details These indications are disabled by default. The primitive CI_DAT_PRIM_SET_UL_TP_IND_REQ is used to enable periodic reports */
    /* End of ACI optimization for data channel */


    CI_DAT_PRIM_TEST_APP_REQ,             /** This CI only used for internal testing, just simulate the test application*/
    CI_DAT_PRIM_TEST_APP_CNF, 
    CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_REQ,
    CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_CNF,
    CI_DAT_PRIM_CUMULATIVE_DATA_COUNT_IND = 20,

    CI_DAT_PRIM_SET_MBMS_CMD_REQ,
    CI_DAT_PRIM_SET_MBMS_CMD_CNF,
    CI_DAT_PRIM_GET_MBMS_CMD_REQ,
    CI_DAT_PRIM_GET_MBMS_CMD_CNF,
    CI_DAT_PRIM_GET_MBMS_CMD_AREA_INFO_REQ,   
    CI_DAT_PRIM_GET_MBMS_CMD_AREA_INFO_CNF,
    CI_DAT_PRIM_SET_MBMS_EV_REQ,
    CI_DAT_PRIM_SET_MBMS_EV_CNF,
    CI_DAT_PRIM_MBMS_EV_IND,

    /* ADD NEW COMMON PRIMITIVES HERE, BEFORE 'CI_DAT_PRIM_LAST_COMMON_PRIM' */

    /* END OF COMMON PRIMITIVES LIST */
    CI_DAT_PRIM_LAST_COMMON_PRIM

    /* the  customer specific extension primitives will be added starting from
    * CI_DAT_PRIM_firstCustPrim = CI_DAT_PRIM_LAST_COMMON_PRIM as the first identifier.
    * The actual primitive names and IDs are defined in the associated
    * 'ci_dat_cust_xxx.h' file.
    */

    /* DO NOT ADD ANY MORE PRIMITIVES HERE */

} _CiDatPrim;
/**@}*/
/* specify the number of default common DAT primitives */
#define CI_DAT_NUM_COMMON_PRIM ( CI_DAT_PRIM_LAST_COMMON_PRIM - 1 )


/* Data Types */
/** \brief Supported data types */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDATTYPE_TAG{
  CI_DAT_TYPE_PPP = 0,  /**< PPP */
  CI_DAT_TYPE_IP,       /**< IPv4 */
  CI_DAT_TYPE_IPV6,     /**< IPv6 */
  CI_DAT_TYPE_RAW,      /**< Raw data */
  CI_DAT_TYPE_HDLC,     /**< Not supported */
  CI_DAT_NUM_TYPES
} _CiDatType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Data type
 *  \sa CIDATTYPE_TAG
 * \remarks Common Data Section */
 typedef UINT8 CiDatType;
/**@}*/

/* Data Service Group Result Codes */
/** \brief Result codes */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIRC_DAT{

  CIRC_DAT_SUCCESS = 0,			/**< Request completed successfully */
  CIRC_DAT_FAILURE,				/**< Request failed */
  CIRC_DAT_CONNECTION_FAILED,	/**< Connection failed */
  CIRC_DAT_PDU_TOO_BIG,			/**< PDU is too big */
  CIRC_DAT_INVALID_PARAMETER,	/**< Generic error - the requested service primitive has invalid parameters */
  CIRC_DAT_INVALID_REQ,			/**< Generic error - the requested service primitive can not be handled at current state */
  CIRC_DAT_SIM_NOT_READY,		/**< Generic error - the requested service primitive fails because SIM is not ready */
  CIRC_DAT_ACCESS_DENIED,		/**< Generic error - the requested service primitive fails because access is denied */ 

  /* This one must always be last in the list! */
  CIRC_DAT_NUM_RESCODES       /* Number of result codes defined */
} _CiDatRc;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Result code
 *  \sa CIRC_DAT
 * \remarks Common Data Section */
typedef UINT16 CiDatRc;
/**@}*/


/* Data Service Group Network data types */
/** \brief Data network type values */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDATA_NW_TYPE_TAG{

   CI_DATA_NW_TYPE_GPRS_EDGE = 0,  /**< NW type is GPRS or EDGE */
   CI_DATA_NW_TYPE_UMTS,           /**< NW type is UMTS */              
   CI_DATA_NW_TYPE_HSDPA,         /**< NW type is HSDPA */
  /* This one must always be last in the list! */
  CI_DATA_NW_TYPE_NUM_TYPES      /* Number of data network types defined */
}  _CiDataNWType;
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Data NW type
 *  \sa CIDATA_NW_TYPE_TAG
 * \remarks Common Data Section */
typedef UINT8 CiDataNWType;
/**@}*/


/* Connection Types */
/** \brief Data connection type */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDATCONNTYPE_TAG{
  CI_DAT_CONNTYPE_CS = 0,   /**< CS connection */
  CI_DAT_CONNTYPE_PS,       /**< PS connection */
  CI_DAT_NUM_CONNTYPES
} _CiDatConnType;

#if !defined(ENV_LINUX)
/** \addtogroup  SpecificSGRelated
 * @{ */
/**   \brief Data connection type (CS or PS)
 *  \sa CIDATCONNTYPE_TAG
 * \remarks Common Data Section */
typedef UINT8 CiDatConnType;
/**@}*/
/* Connection Information */
/** \brief Data connection type */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDatConnInfo_struct{
  CiDatConnType type;   /**< Connection type \sa CiDatConnType */
  UINT32        id;     /**< Link ID: call ID for the CS connection; context ID for the PS connection */
} CiDatConnInfo;
#if defined (ON_PC)
typedef enum ATCI_CONNECTION_TYPE {
	ATCI_LOCAL,
	ATCI_REMOTE = 2
} _AtciConnectionType;

typedef struct directipconfig_tag {
  INT32 dwContextId;
  INT32 dwProtocol;
  struct
      {
        INT32 inIPAddress;
        INT32 inPrimaryDNS;
        INT32 inSecondaryDNS;
        INT32 inDefaultGateway;
        INT32 inSubnetMask;
      } ipv4;
} DIRECTIPCONFIG;

typedef struct _ipconfiglist
{
    DIRECTIPCONFIG directIpAddress;
    struct _ipconfiglist *next;
}DIRECTIPCONFIGLIST;

typedef enum
{   // com events
    DATA_CHAN_INIT_STATE = 0,
    DATA_CHAN_NOTREADY_STATE,
    DATA_CHAN_READY_STATE,
    DATA_CHAN_SNUMSTATES    
}DATACHANSTATES;

typedef enum
{
	PDP_PPP = 0,
	PDP_DIRECTIP=1,
	PSD_MODEM = 2,
	CSD_RAW = 3,
	CSD_MODEM = 4
}_SVCTYPE;

typedef UINT8 SVCTYPE;

struct datahandle_obj
{
	 CiDatConnInfo            m_datConnInfo;
	 BOOL			 m_fOptimizedData;
	 INT16                       m_maxPduSize;
	 CiDatConnType m_connType;
	 UINT32 m_cid;
	 DATACHANSTATES chanState;
	 UINT16 m_dwCurSendPduSeqNo;
	 UINT16 m_dwCurSendReqHandle;
	 SVCTYPE pdptype;
	 UINT32 connectionType;
//	 OSAFlagRef writeSync;
};

typedef struct _datahandle
{
    struct datahandle_obj handle;
    struct _datahandle *next;
}DATAHANDLELIST;


typedef struct
{
         UINT32 cid;
         UINT32 len;       //length of databuf
         UINT8 *databuf;
}GCFDATA;

#endif

#endif /* ! ENV_LINUX */

#if defined(ON_PC)&&(defined(UL_LOOPBACK) || defined(DL_LOOPBACK))
/* Data PDU */
// ICAT EXPORTED STRUCTURE
typedef struct CiDatPdu_struct{
  CiDatType type;      /* data type */
  UINT16    len;       /* data length */
  UINT8    data[200];      /* pointer to data */
  CiBoolean isLast;
  UINT8     seqNo;     /* sequence number for each CI Dat Pdu */
} CiDatPdu; 
#else
/** Data PDU */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDatPdu_struct{
  CiDatType 	type;      		/**< Data type \sa CiDatType */
  UINT16    	len;       		/**< Data length */
  UINT8         *data;          /**< Pointer to data */
  CiBoolean 	isLast;		/**< Indicates this is the last PDU \sa CCI API Ref Manual*/
  UINT8     	seqNo;     	/**< Sequence number for each CI data PDU */
} CiDatPdu;
#endif

/** \brief Data throughput indication */
/** \details */
/** \remarks Common Data Section */
//ICAT EXPORTED STRUCT
typedef struct CiDatUlTpInfo_struct{
  UINT16 cid;				/**< Context id  */
  UINT32 sentBytes;			/**< Number of bytes sent since previous indication  */
  UINT32 pendingBytes;		/**< Number of bytes pending in Tx queues  */
}CiDatUlTpInfo;

/* -------------------------- DAT Service Group Primitives ------------------------------ */

/* <INUSE> */


/** <paramref name="CI_DAT_PRIM_GET_MAX_PDU_SIZE_REQ">   */
typedef  struct CiDatPrimGetMaxPduSizeReq_struct{
  CiBoolean	optimizedData;  /**<  Request for the maximum PDU size when using the optimized data plane (if TRUE) or the control plane (if FALSE). Default value is FALSE. \sa CCI API Ref Manual */
}CiDatPrimGetMaxPduSizeReq;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_GET_MAX_PDU_SIZE_CNF">   */

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetMaxPduSizeCnf_struct{
  CiDatRc rc;      /**< Result code \sa CiDatRc */
  UINT16   size;  /**< The maximum PDU size depends on the underlying data link layer protocol. */
} CiDatPrimGetMaxPduSizeCnf;


/** <paramref name="CI_DAT_PRIM_SET_UL_TP_IND_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetUlTpIndReq_struct
{
   UINT16 reportInterval; /**< Enables TP reports from MAC at every report interval (milli seconds). Setting report interval to 0 disables the reports */
} CiDatPrimSetUlTpIndReq;

/** <paramref name="CI_DAT_PRIM_SET_UL_TP_IND_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetUlTpIndCnf_struct
{
   CiDatRc result;    /**< Result code \sa CiDatRc */
} CiDatPrimSetUlTpIndCnf;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_SEND_REQ">   */

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSendReq_struct{
  CiDatConnInfo  connInfo;	 /**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */

  /* # Start Contiguous Code Section # */
  CiDatPdu       sendPdu;  	/**< Transferred data PDU \sa CiDatPdu_struct */
  /* # End Contiguous Code Section # */
} CiDatPrimSendReq;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_SEND_CNF">   */

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSendCnf_struct{
  CiDatRc        rc;  		/**< Result code \sa CiDatRc */
  CiDatConnInfo  connInfo; 	/**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
} CiDatPrimSendCnf;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_RECV_IND">   */

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimRecvInd_struct{
  CiDatConnInfo  connInfo;  /**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */

 /* # Start Contiguous Code Section # */
  CiDatPdu      recvPdu;	/**< Received data PDU \sa CiDatPdu_struct */
  /* # End Contiguous Code Section # */
} CiDatPrimRecvInd;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_RECV_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimRecvRsp_struct{
  CiDatRc       rc;			/**< Result code \sa CiDatRc */
  CiDatConnInfo connInfo; 	/**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
} CiDatPrimRecvRsp;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_OK_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimOkInd_struct{
  CiDatConnInfo  connInfo;		/**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
  UINT16         maxPduSize;	/**< The maximum PDU size for the connection depends on the underlying data link layer protocol. */
} CiDatPrimOkInd;



/** <paramref name="CI_DAT_PRIM_UL_TP_IND">   */


//ICAT EXPORTED STRUCT
typedef struct CiDatPrimUlTpInd_struct{
	UINT32 minLimitBytes;             /**< The minimum number of bytes required to be in the mac Q in order to maintain an active UL TBF  */
	UINT32 maxLimitBytesHint;      /**< This value may be used to calculate an optimal value for flow control on Data Tx */
	CiDataNWType nwType;           /**< Network type  \sa CiDataNwType */
	UINT8 number;				/**< Number of valid UL throughput information indication elements, each context ID will have a separate indication element */
  CiDatUlTpInfo ulTpInfo[CI_PS_MAX_PDP_CTX_NUM]; /**<  Array of TP indications per context id \sa CiDatUlTpInfo_struct */
}CiDatPrimUlTpInd;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_NOK_IND">  */

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimNokInd_struct{
  CiDatConnInfo  connInfo;  		/**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
} CiDatPrimNokInd;

/* Begin of ACI optimization for data channel */

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_SEND_DATA_OPT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSendDataOptReq_struct {

  CiDatConnInfo    connInfo;    /**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
  CiDatPdu         sendPdu;      /**< Transferred data PDU \sa CiDatPdu_struct */
  BOOL             sinkPdu;

  CiPsL2P 		 l2p;

} CiDatPrimSendDataOptReq;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_SEND_DATA_OPT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSendDataOptCnf_struct{

  CiDatRc          	rc;          		/**< Result code \sa CiDatRc */
  CiDatConnInfo    	connInfo;    		/**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
  UINT8    		*pReqData;      		/**< Pointer to data */
} CiDatPrimSendDataOptCnf;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_RECV_DATA_OPT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimRecvDataOptInd_struct {

    CiDatConnInfo    connInfo;    /**< Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct*/
    CiDatPdu         recvPdu;      /**< Received data PDU \sa CiDatPdu_struct */
    UINT8           *pStartBuffer;       /**< Pointer to start of the buffer including data */
} CiDatPrimRecvDataOptInd;

/* <INUSE> */

/** <paramref name="CI_DAT_PRIM_RECV_DATA_OPT_RSP"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimRecvDataOptRsp_struct {

    CiDatRc             rc;                 /**<   Result code \sa CiDatRc */
    CiDatConnInfo       connInfo;           /**<   Connection information, including the PS or CS connection type and context ID for the PS and CS connection type, respectively \sa CiDatConnInfo_struct */
    UINT8               *pIndData;          /**< Pointer to data */
    UINT8               *pStartBuffer;      /**< Pointer to start of the buffer including data */
    CiIndicationHandle  dataIndHandle;
} CiDatPrimRecvDataOptRsp;
/* End of ACI optimization for data channel */

/******************************************************************************
 * CI_DAT_PRIM_TEST_APP_REQ/CI_DAT_PRIM_TEST_APP_CNF
 * CI added for internal testing (TTCN scripts) only, to simulate the test application
 * AT*VZWTESTAPP=<apn>,<state>[,<period>]
 ******************************************************************************/
/** <paramref name="CI_DAT_PRIM_TEST_APP_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimTestAppReq_struct{
    CiString apn;
    UINT8    state;     // 0-application disconnected; 1-application idle; 2-application transmitting
    UINT32   msPeriod;  // period in milli-second
}CiDatPrimTestAppReq;

/** <paramref name="CI_DAT_PRIM_TEST_APP_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimTestAppCnf_struct{
    CiDatRc  rc;
}CiDatPrimTestAppCnf;

/** <paramref name="CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_REQ"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetCumulativeDataReq_struct {

    UINT32		cid;                 /**<   Result code \sa CiDatRc */
} CiDatPrimGetCumulativeDataReq;
/* End of ACI optimization for data channel */

/** <paramref name="CI_DAT_PRIM_GET_CUMULATIVE_DATA_COUNT_CNF"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetCumulativeDataCnf_struct{
	CiDatRc    rc;
    UINT32     cid;
    UINT32     cumulativeDL;     // cumulative DL data bytes
    UINT32     cumulativeUL;  // cumulative UL data bytes
}CiDatPrimGetCumulativeDataCnf;

/** <paramref name="CI_DAT_PRIM_CUMULATIVE_DATA_COUNT_IND"> */
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimCumulativeDataInd_struct{
	UINT32 		cid;
	UINT32		cumulativeDL;     // cumulative DL data bytes
	UINT32   	cumulativeUL;  // cumulative UL data bytes
}CiDatPrimCumulativeDataInd;

#define CI_DAT_MBMS_MAX_AREA 8
#define CI_DAT_MBMS_MAX_SESSION 29
#define CI_DAT_MBMS_MAX_SAI 30
#define CI_DAT_MBMS_MAX_FREQ 10
//add by taow 20150204 begin
#define CI_DAT_MBMS_MAX_CURRENT_SAI 64
//add by taow 20150204 end


//ICAT EXPORTED ENUM
typedef enum Ci_DAT_MBMS_CMD_TAG
{
    CI_DAT_MBMS_CMD_ENABLER = 0,  
    CI_DAT_MBMS_CMD_ACT,
    CI_DAT_MBMS_CMD_DEACT,
    CI_DAT_MBMS_CMD_DEACT_ALL,
    CI_DAT_MBMS_CMD_SET_PREFER,
    CI_DAT_MBMS_CMD_GET_NW_TIME,
    CI_DAT_MBMS_CMD_GET_SIGNAL_LEVEL,
    CI_DAT_MBMS_CMD_GET_NW_INFO,
    CI_DAT_MBMS_CMD_GET_MODEM_STATUS,
    CI_DAT_MBMS_CMD_SET_HYSTERESIS,
    CI_DAT_MBMS_CMD_SET_AVAILABILITY_INFO,
    CI_DAT_MBMS_CMD_GET_CURRENT_SAIS //add by taow 20150204
} _CiDatMbmsCmd;

typedef UINT8 CiDatMbmsCmd;

//ICAT EXPORTED ENUM
typedef enum Ci_DAT_MBMS_PREFER_TAG
{
    CI_DAT_MBMS_PREFER_NONE = 0,  
    CI_DAT_MBMS_PREFER_UNICAST,
    CI_DAT_MBMS_PREFER_MULTICAST
} _CiDatMbmsPrefer;

typedef UINT8 CiDatMbmsPrefer;

//ICAT EXPORTED ENUM
typedef enum Ci_DAT_MBMS_MODEM_STATUS_TAG
{
    CI_DAT_MBMS_MODEM_STATUS_NONE = 0,  
    CI_DAT_MBMS_MODEM_STATUS_OFF,
    CI_DAT_MBMS_MODEM_STATUS_ON
} _CiDatMbmsModemStatus;

typedef UINT8 CiDatMbmsModemStatus;

//ICAT EXPORTED ENUM
typedef enum Ci_DAT_MBMS_EV_TAG
{
    CI_DAT_MBMS_EV_SERVICE_CHANGE = 0,  
    CI_DAT_MBMS_EV_NO_SERVICE,
    CI_DAT_MBMS_EV_ONLY_UNICAST_AVAIL,
    CI_DAT_MBMS_EV_UNICAST_AND_MBMS_AVAIL
} _CiDatMbmsEv;

typedef UINT8 CiDatMbmsEv;

//ICAT EXPORTED STRUCT
typedef struct CiDatMbmsTmgi_struct{
    UINT32    serviceId;
    UINT16    mcc;
    UINT16    mnc;
    CiMmNetOpDigitMnc mncDigit;
} CiDatMbmsTmgi;

//ICAT EXPORTED STRUCT
typedef struct CiDatMbmsSessionInfo_struct{
    CiDatMbmsTmgi    tmgi;
    CiBoolean    sessionIdPresent;
    UINT8    sessionId;
} CiDatMbmsSessionInfo;
//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSaiInfo_struct{
    UINT16    sai;
	UINT8     numOfFreq;
    UINT32    freq[CI_DAT_MBMS_MAX_FREQ];
} CiDatPrimSaiInfo;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetMbmsCmdReq_struct{
    CiDatMbmsCmd    cmd;  
    CiBoolean    enabler;
    CiDatMbmsTmgi    tmgi;
    CiDatMbmsPrefer   prefer;
    UINT8    inSessionHysteresis;
    UINT8    outSessionHysteresis;
    UINT8    inMbmsHysteresis;
    UINT8    outMbmsHysteresis;
    UINT8    numOfSai;
    CiDatPrimSaiInfo    saiInfo[CI_DAT_MBMS_MAX_SAI];	
} CiDatPrimSetMbmsCmdReq;
//add by taow 20150204 begin

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetMbmsCmdSaiListCnf_struct
{
    //UINT8    numOfSai;
    //UINT16  sai[CI_DAT_MBMS_MAX_CURRENT_SAI];
	//Boolean    	result;
    UINT8    	numOfCurrentSai;
    UINT16  		currentSai[CI_DAT_MBMS_MAX_CURRENT_SAI];
    UINT8   		numOfNeighborSai;
    UINT16  		neighborSai[CI_DAT_MBMS_MAX_CURRENT_SAI]; 
}
CiDatPrimGetMbmsCmdSaiListCnf;

//add by taow 20150428 begin

//ICAT EXPORTED STRUCT
typedef struct CiDatPlmnIdentityTag
{
    //3 digits of MMC
    UINT16                           mcc;
    //Length of MNC, value range (2,3)
    UINT8                            lenOfMnc;
    //2-3 digits of MNC
    UINT16                           mnc;
}CiDatPlmnIdentity;
//add by taow 20150428 end


//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetMbmsCmdCnf_struct{
    CiDatRc    rc;   /**< Result code. \sa CiDatRc. */
    CiDatMbmsCmd    cmd;  
    CiBoolean    enabler;
    UINT32    timingInfoHigh;
    UINT32    timingInfoLow;
    UINT16    signalLevel;
    UINT32    cellId;
    CiDatMbmsModemStatus    modemStatus;
	CiDatPrimGetMbmsCmdSaiListCnf currentSai;//add by taow 20150204 
	CiDatPlmnIdentity   plmnIdentity;// add by taow 20150428
} CiDatPrimSetMbmsCmdCnf;

//ICAT EXPORTED STRUCT
typedef CiEmptyPrim CiDatPrimGetMbmsCmdReq;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetMbmsCmdCnf_struct{
    CiDatRc    rc;   /**< Result code. \sa CiDatRc. */
    UINT8    numOfArea;
    UINT16    areaId[CI_DAT_MBMS_MAX_AREA];
} CiDatPrimGetMbmsCmdCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetMbmsCmdAreaInfoReq_struct{
    UINT16    areaId;
} CiDatPrimGetMbmsCmdAreaInfoReq;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimGetMbmsCmdAreaInfoCnf_struct{
    CiDatRc    rc;   /**< Result code. \sa CiDatRc. */
    UINT16    areaId;
    UINT8    numOfSession;
    CiDatMbmsSessionInfo    sessionInfo[CI_DAT_MBMS_MAX_SESSION];
} CiDatPrimGetMbmsCmdAreaInfoCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetMbmsEvReq_struct{
    CiBoolean    cmd;  
} CiDatPrimSetMbmsEvReq;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimSetMbmsEvCnf_struct{
    CiDatRc    rc;   /**< Result code. \sa CiDatRc. */
    CiBoolean    cmd;  
} CiDatPrimSetMbmsEvCnf;

//ICAT EXPORTED STRUCT
typedef struct CiDatPrimMbmsEvInd_struct{
    CiDatMbmsEv    ev;   
} CiDatPrimMbmsEvInd;


/* ADD NEW COMMON PRIMITIVES DEFINITIONS HERE */

#ifdef CI_CUSTOM_EXTENSION
/* it is assumed that only one customized set of extension primitives is
 * to be considered at one time. The selection of the particular customized
 * set is done in the 'ci_dat_cust.h' based on compile flags.
 *
 * Note: if no customer extension primitives are defined for this service group
 * the CI_DAT_NUM_CUST_PRIM will be set to 0 in the "ci_dat_cust.h" file.
 */
#include "ci_dat_cust.h"

#define CI_DAT_NUM_PRIM ( CI_DAT_NUM_COMMON_PRIM + CI_DAT_NUM_CUST_PRIM )

#else

/* if no customer extension is supported, only the default common set is considered */
#define CI_DAT_NUM_PRIM CI_DAT_NUM_COMMON_PRIM

#endif /* CI_CUSTOM_EXTENSION */


/***************************Start of CI Interface Definitions of Old CI Versions***********************************************/

/******************************************************************************
 * All old CI interface definations should be backed up here, re-defined
 * with the suffix of CI version number
******************************************************************************/

/******************************************************************************
 * V0010, headers
 * related CIs :
 * none.
******************************************************************************/

/******************************************************************************
 * V0020, headers
 * related CIs :
 * 
******************************************************************************/

/***************************End of CI Interface Definitions of Old CI Versions***********************************************/


#ifdef __cplusplus
	}
#endif //__cplusplus

#endif /* _CI_DAT_H_ */


/*                      end of ci_dat.h
--------------------------------------------------------------------------- */
