/*------------------------------------------------------------
(C) Copyright [2006-2009] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/* ===========================================================================
File		: ci_dev_engm.h
Description : Data types file for the DEV service group

Notes	   :

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

#if !defined(_CI_DEV_ENGM_H_)
#define _CI_DEV_ENGM_H_

#include "ci_api_types.h"


/* ===================================================================================
				4G (LTE) Engineering Mode Structures
   ===================================================================================*/

#define CI_DEV_ENGM_MAX_RRC_MSG_LENGTH          256
#define CI_DEV_ENGM_MAX_NAS_MSG_LENGTH          400
#define CI_DEV_ENGM_MAX_EUTRA_MEAS              32
#define CI_DEV_ENGM_MAX_UTRA_MEAS               32
#define CI_DEV_ENGM_MAX_GERAN_MEAS              32

#define CI_DEV_ENGM_MAX_EUTRA_NEIGHB_MEAS		32
#define CI_DEV_ENGM_MAX_UTRA_NEIGHB_MEAS		32
#define CI_DEV_ENGM_MAX_GERAN_NEIGHB_MEAS		32

#define CI_DEV_ENGM_CQI_WB_DIST_LENGTH          16
#define CI_DEV_ENGM_CQI_SUB_BAND_DIST_LENGTH    4
#define CI_DEV_ENGM_RANK_IND_DIST_LENGTH        5
#define CI_DEV_ENGM_PMI_DIST_LENGTH             16

#define CI_DEV_ENGM_RRC_UASSIGNED_VALUE 		0xFF

/* The AT Command is:
   at+cged=1,reporting[0], reporting[1]
   Example: LT03 = 0x00000000-00000004
   at+cged=1,4,0
   Example: GS54 = 0x00000040-00000000
   For GS54 alone, do we need:
   at+cged=1,0,40
*/

/* 1st 32 bit, reporting[0] */
#define ENGM_LT01   (1 << 0)   /* 0x00000000-00000001  Enable reporting E-UTRA RRC Message */
#define ENGM_LT02   (1 << 1)   /* 0x00000000-00000002  Enable reporting E-UTRA NAS Message */
#define ENGM_LT03   (1 << 2)   /* 0x00000000-00000004  Enable reporting E-UTRA Measurement Report */
#define ENGM_LT04   (1 << 3)   /* 0x00000000-00000008  Enable reporting E-UTRA Inter-RAT Measurement Report */
#define ENGM_LT05   (1 << 4)   /* 0x00000000-00000010  Enable reporting E-UTRA Neighbor List */
#define ENGM_LT06   (1 << 5)   /* 0x00000000-00000020  Enable reporting E-UTRA RRC State */
#define ENGM_LT07   (1 << 6)   /* 0x00000000-00000040  Enable reporting E-UTRA MAC Control State */
#define ENGM_LT08   (1 << 7)   /* 0x00000000-00000080  Enable reporting E-UTRA MAC Random Access Attempt */
#define ENGM_LT017  (1 << 8)   /* 0x00000000-00000100  Enable reporting E-UTRA RLC Data Transfer Report */
#define ENGM_LT010  (1 << 9)   /* 0x00000000-00000200  Enable reporting E-UTRA EPS Bearer Context Status */
#define ENGM_LT011  (1 << 10)  /* 0x00000000-00000400  Enable reporting E-UTRA EPS Bearer QoS */
#define ENGM_LT012  (1 << 11)  /* 0x00000000-00000800  Enable reporting E-UTRA PUSCH Transmission Status */
#define ENGM_LT013  (1 << 12)  /* 0x00000000-00001000  Enable reporting E-UTRA Radio Link Sync Status */

#define ENGM_GS15   (1 << 16)  /* 0x00000000-00010000  Enable reporting GSM/UMTS PDP Context Activation SM Message */
#define ENGM_GS18   (1 << 17)  /* 0x00000000-00020000  Enable reporting GSM/UMTS PDP Context End SM Message */
#define ENGM_GS19   (1 << 18)  /* 0x00000000-00040000  Enable reporting GSM/UMTS PDP Context Request SM Message */
#define ENGM_GS40   (1 << 19)  /* 0x00000000-00080000  Enable reporting GSM/UMTS Attach Begin MM Message */
#define ENGM_GS41   (1 << 20)  /* 0x00000000-00100000  Enable reporting GSM/UMTS Attach End MM Message */
#define ENGM_GS42   (1 << 21)  /* 0x00000000-00200000  Enable reporting GSM/UMTS Detach Accept MM Message */
#define ENGM_GS43   (1 << 22)  /* 0x00000000-00400000  Enable reporting GSM/UMTS Routing Area Update MM Message */
#define ENGM_GS46   (1 << 23)  /* 0x00000000-00800000  Enable reporting GSM/GPRS/UMTS Network Info MM Message */
#define ENGM_GS47   (1 << 24)  /* 0x00000000-01000000  Enable reporting GSM/GPRS/UMTS Service State MM Message */
#define ENGM_GS6E   (1 << 25)  /* 0x00000000-02000000  Enable reporting GSM/GPRS/UMTS Radio Mode MM Message */

#define ENGM_GS30   (1 << 28)  /* 0x00000000-10000000  Enable reporting GSM/GPRS/EDGE Layer 3 Downlink Message GRR Message */
#define ENGM_GS31   (1 << 29)  /* 0x00000000-20000000  Enable reporting GSM/GPRS/EDGE Layer 3 Uplink Message GRR Message */
#define ENGM_RF51   (1 << 30)  /* 0x00000000-40000000  Enable reporting GSM Serving Cell Info GRR Message */
#define ENGM_RF53   (1 << 31)  /* 0x00000000-80000000  Enable reporting GSM Neighbor Measurement GRR Message */

/* 2nd 32 bit, reporting[1] */
#define ENGM_GS57   (1 << 4)  /* 0x00000010-00000000  Enable reporting GSM and WB Cell Change Begin RR Message */
#define ENGM_GS58   (1 << 5)  /* 0x00000020-00000000  Enable reporting GSM and WB Cell Change End RR Message */
#define ENGM_GS54   (1 << 6)  /* 0x00000040-00000000  Enable reporting GSM and WB Handover Begin RR Message */
#define ENGM_GS55   (1 << 7)  /* 0x00000080-00000000  Enable reporting GSM and WB Handover End RR Message */
#define ENGM_GS81   (1 << 8)  /* 0x00000100-00000000  Enable reporting GPRS/EDGE RLC Statistics RLC Message */

#define ENGM_RF52   (1 << 12)  /* 0x00001000-00000000  Enable reporting GSM Serving Cell Info L1 Message */
#define ENGM_RF54   (1 << 13)  /* 0x00002000-00000000  Enable reporting GSM Gprs Edge Link Quality L1 Message */

#define ENGM_GS34   (1 << 16)  /* 0x00010000-00000000  Enable reporting WB UMTS/HSPA Layer 3 Downlink RRC Message */
#define ENGM_GS35   (1 << 17)  /* 0x00020000-00000000  Enable reporting WB UMTS/HSPA Layer 3 Uplink RRC Message */
#define ENGM_GS67   (1 << 18)  /* 0x00040000-00000000  Enable reporting WB RRC State RRC Message */
#define ENGM_GS6F   (1 << 19)  /* 0x00080000-00000000  Enable reporting WB Compress Mode State RRC Message */
#define ENGM_RF61   (1 << 20)  /* 0x00100000-00000000  Enable reporting WB UMTS/HSPA Active and Monitored Set Info RRC Message */
#define ENGM_RF62   (1 << 21)  /* 0x00200000-00000000  Enable reporting WB Inter Neighbor Measurement RRC Message */
#define ENGM_RF60   (1 << 22)  /* 0x00400000-00000000  Enable reporting WB RF and Serving Cell Info RRC Message */

#define ENGM_GS6D   (1 << 24)  /* 0x01000000-00000000  Enable reporting WB Multi-RAB State RLC Message */
#define ENGM_GS84   (1 << 25)  /* 0x02000000-00000000  Enable reporting WB UMTS/HSPA RLC Statistics RLC Message */
#define ENGM_GS86   (1 << 26)  /* 0x04000000-00000000  Enable reporting WB RLC Reset RLC Message */

#define ENGM_GS83   (1 << 28)  /* 0x10000000-00000000  Enable reporting WB HSUPA Statistics PHY Message */
#define ENGM_GS88   (1 << 29)  /* 0x20000000-00000000  Enable reporting WB HSDPA Evolved Statistics PHY Message */
#define ENGM_RF63   (1 << 30)  /* 0x40000000-00000000  Enable reporting WB UMTS/HSPA Transport Channel Info L1 Message */
#define ENGM_RF64   (1 << 31)  /* 0x80000000-00000000  Enable reporting WB UMTS/HSPA Radio Link Sync Status L1 Message */

typedef UINT16 CiDevRc;


//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgClass
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_MSG_CLASS_TYPE
{
    CI_DEV_LTE_RRC_MSG_CLASS_BCCH_BCH = 0,  /* BCCH-BCH massage */
    CI_DEV_LTE_RRC_MSG_CLASS_BCCH_DL_SCH,   /* BCCH-DL-SCH message */
    CI_DEV_LTE_RRC_MSG_CLASS_PCCH,          /* PCCH message */
    CI_DEV_LTE_RRC_MSG_CLASS_DL_CCCH,       /* DL_CCCH message */
    CI_DEV_LTE_RRC_MSG_CLASS_DL_DCCH,       /* DL_DCCH message */
    CI_DEV_LTE_RRC_MSG_CLASS_UL_CCCH,       /* UL_CCCH message */
    CI_DEV_LTE_RRC_MSG_CLASS_UL_DCCH        /* UL_DCCH message */
} _CiDevLteRrcMsgClass;

typedef UINT8 CiDevLteRrcMsgClass;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / bch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_BCCH_BCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_BCCH_BCH_MSG_MASTR_INFO_BLK = 0  /* BCCH-BCH master information block massage */
} _CiDevLteRrcBcchBchMsgType;

typedef UINT8 CiDevLteRrcBcchBchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / dl_sch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_BCCH_DL_SCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO = 0,  /* BCCH-DL-SCH massage */
    CI_DEV_LTE_RRC_BCCH_DL_SCH_MSG_SYS_INFO_BLK_TYPE1  /* BCCH-DL-SCH System Information Block Type 1 message */
} _CiDevLteRrcBcchDlSchMsgType;

typedef UINT8 CiDevLteRrcBcchDlSchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / pcch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_PCCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_PCCH_MSG_PAGING = 0  /* PCCH Paging massage */
} _CiDevLteRrcPcchMsgType;

typedef UINT8 CiDevLteRrcPcchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / dl_ccch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_DL_CCCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST = 0,  /* DL-CCCH RRC Connection Reestablishment massage */
    CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REEST_REJ,  /* DL-CCCH RRC Connection Reestablishment Reject massage */
    CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_REJ,        /* DL-CCCH RRC Connection Reject massage */
    CI_DEV_LTE_RRC_DL_CCCH_MSG_RRC_CONN_SETUP       /* DL-CCCH RRC Connection Setup massage */
} _CiDevLteRrcDlCcchMsgType;

typedef UINT8 CiDevLteRrcDlCcchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / dl_dcch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_DL_DCCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_DL_DCCH_MSG_CSFB_PARAM_RESP = 0,  /* DL-DCCH CSFB Parameters Response */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_DL_INFO_TRANSFER,     /* DL-DCCH DL Information Transfer message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_HO_FROM_EUTRA_REQ,    /* DL-DCCH Handover From EUTRA Preparation Request message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_MOB_FROM_EUTRA_CMD,   /* DL-DCCH Mobility From EUTRA Command message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_RECFG,       /* DL-DCCH RRC Connection Reconfiguration message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_RRC_CONN_REL,         /* DL-DCCH RRC Connection Release message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_SECUR_MODE_CMD,       /* DL-DCCH Security Mode Command message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_UE_CAP_ENQ,           /* DL-DCCH UE Capability Enquiry message */
    CI_DEV_LTE_RRC_DL_DCCH_MSG_CNTR_CHECK            /* DL-DCCH Counter Check message */
} _CiDevLteRrcDlDcchMsgType;

typedef UINT8 CiDevLteRrcDlDcchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / ul_ccch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_UL_CCCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REEST_REQ = 0,   /* UL-CCCH RRC Connection Reestablishment Request massage */
    CI_DEV_LTE_RRC_UL_CCCH_MSG_RRC_CONN_REQ              /* UL-CCCH RRC Connection Request massage */
} _CiDevLteRrcUlCcchMsgType;

typedef UINT8 CiDevLteRrcUlCcchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType / ul_dcch
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_UL_DCCH_MSG_TYPE
{
    CI_DEV_LTE_RRC_UL_DCCH_MSG_CSFB_PARAM_REQ = 0,  /* UL-DCCH CSFB Parameters Request message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_MEAS_REPORT,         /* UL-DCCH Measurement Report message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_RECFG_CMP,  /* UL-DCCH RRC Connection Reconfiguration Complete message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_REEST_CMP,  /* UL-DCCH RRC Connection Reestablishment Complete message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_RRC_CONN_SETUP_CMP,  /* UL-DCCH RRC Connection Setup Complete message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_SECUR_MODE_CMP,      /* UL-DCCH Security Mode Complete message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_SECURE_MODE_FAIL,    /* UL-DCCH Security Mode Failure message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_UE_CAP_INFO,         /* UL-DCCH UE Capability Information message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_HO_PREP_TXR,         /* UL-DCCH UL Handover Preparation Transfer message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_INFO_TXR,            /* UL-DCCH UL Information Transfer message */
    CI_DEV_LTE_RRC_UL_DCCH_MSG_CNTR_CHK_RESP        /* UL-DCCH Counter Check Response message */
} _CiDevLteRrcUlDcchMsgType;

typedef UINT8 CiDevLteRrcUlDcchMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC / msgType
//ICAT EXPORTED UNION : _CiDevLteRrcMsgClass
typedef union CiDevLteRrcMsgType_Tag
{
    CiDevLteRrcBcchBchMsgType bch;
    CiDevLteRrcBcchDlSchMsgType dl_sch;
    CiDevLteRrcPcchMsgType pcch;
    CiDevLteRrcDlCcchMsgType dl_ccch;
    CiDevLteRrcDlDcchMsgType dl_dcch;
    CiDevLteRrcUlCcchMsgType ul_ccch;
    CiDevLteRrcUlDcchMsgType ul_dcch;
} CiDevLteRrcMsgType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RRC
//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevLteRrcMsgClass msgClass;
    CiDevLteRrcMsgType  msgType;
    UINT16              msgLength;

    // Important Note: Due to dynamic signal payload allocation, the "msg" field must be last!
    CHAR msg[CI_DEV_ENGM_MAX_RRC_MSG_LENGTH];
} CiDevLteEng_RRC;

//for CiDevCommonEngmodeInfo / CiDevLteEng_NAS
//ICAT EXPORTED STRUCT
typedef struct
{
    CiBoolean direction;  /* TRUE - Uplink NAS message transmitted. FALSE - Downlink NAS message received */
    UINT16    msgLength;
    CHAR msg[CI_DEV_ENGM_MAX_NAS_MSG_LENGTH];        /* hex encoded NAS message (unciphered) */
} CiDevLteEng_NAS;

//for CiDevCommonEngmodeInfo / CiDevLteEng_MSR / CiDevLteEng_EutraMeas
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 earfcn;     /* The EARFCN of the neighbor cell */
    UINT16 phyCellId;  /* The physical cell ID of the neighbor cell */
    UINT8 rsrp;        /* The average RSRP of the neighbor cell over last measurement period */
    UINT8 rsrq;        /* The average RSRQ of the neighbor cell over last measurement period */
} CiDevLteEng_EutraMeas;

//for CiDevCommonEngmodeInfo / CiDevLteEng_MSR
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 mcc;            /* The MCC of the serving cell */
    UINT16 mnc;            /* The MNC of the serving cell */
    UINT32 cellId;         /* The cell identity of the serving cell */
    UINT32 tac;            /* The tracking area code of the serving cell */
    UINT16 servEarfcn;     /* The EARFCN of the serving cell */
    UINT16 servPhyCellId;  /* The physical cell ID of the serving cell */
    UINT8 servRsrp;        /* The average RSRP of the serving cell over last measurement period */
    UINT8 servRsrq;        /* The average RSRQ of the serving cell over last measurement period */
    UINT8 servRssnr;       /* The average RSSNR of the serving cell over last measurement period in decibels */
    UINT8 FreqBandInd;     /* The operating band of the serving cell, see 3GPP TS 36.101/Table 5.5-1. */
    UINT8 dlBandwidth;     /* The transmission bandwidth configuration of the serving cell on the downlink, see 3GPP TS 36.101/Table 5.6-1. Value n6 corresponds to 6 resource blocks, n15 to 15 resource blocks and so on. */
    UINT8 ulBandwidth;     /* The transmission bandwidth configuration of the serving cell on the uplink, see 3GPP TS 36.101/Table 5.6-1. Value n6 corresponds to 6 resource blocks, n15 to 15 resource blocks and so on. */
    UINT8 numMeas;         /* The number of E-UTRA neighbor cell measurements included in the current instance of this metric */
    CiDevLteEng_EutraMeas meas[CI_DEV_ENGM_MAX_EUTRA_MEAS];  /* An array of structures with a length of numMeas */
} CiDevLteEng_MSR;

//for CiDevCommonEngmodeInfo / CiDevLteEng_InterMsr / CiDevLteEng_UtraMeas
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 uarfcn;  /* The UARFCN of the neighbor cell */
    UINT16 sc;      /* The neighbor cell primary scrambling code */
    UINT8 rscp;     /* The neighbor cell CPICH RSCP. */
    UINT8 ecno;     /* The neighbor cell CPICH Ec/N0. */
} CiDevLteEng_UtraMeas;

//for CiDevCommonEngmodeInfo / CiDevLteEng_InterMsr / CiDevLteEng_MeasGeran
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 arfcn;  /* The neighbor cell ARFCN. */
    UINT8 bsic;    /* The neighbor cell base station identity code. */
    UINT8 rssi;    /* The neighbor cell BCCH RSSI. */
} CiDevLteEng_MeasGeran;

//for CiDevCommonEngmodeInfo / CiDevLteEng_InterMsr
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 numMeasUtra;                    /* The number of UTRA inter-RAT neighbor cell measurements included in this instance of this metric */
    UINT8 numMeasGeran;                   /* The number of inter-RAT neighbor cell measurements included in this instance of this metric */
	CiDevLteEng_UtraMeas utraMeas[CI_DEV_ENGM_MAX_UTRA_MEAS];     /* An array of structures with a length of numMeasUtra */
	CiDevLteEng_MeasGeran geranMeas[CI_DEV_ENGM_MAX_GERAN_MEAS];  /* An array of structures with a length of numMeasGeran */
} CiDevLteEng_InterMsr;

//for CiDevCommonEngmodeInfo / CiDevLteEng_NeighborList / CiDevLteEng_NeighbEutra
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 earfcn;     /* The neighbor cell EARFCN. */
    UINT16 phyCellId;  /* The neighbor cell physical layer cell identity. */
} CiDevLteEng_NeighbEutra;

//for CiDevCommonEngmodeInfo / CiDevLteEng_NeighborList / CiDevLteEng_NeighbUtra
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 uarfcn;  /* The neighbor cell UARFCN. */
    UINT16 sc;      /* The neighbor cell primary scrambling code */
} CiDevLteEng_NeighbUtra;

//for CiDevCommonEngmodeInfo / CiDevLteEng_NeighborList / CiDevLteEng_NeighbGeran
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 arfcn;  /* The neighbor cell ARFCN. */
} CiDevLteEng_NeighbGeran;

//for CiDevCommonEngmodeInfo / CiDevLteEng_NeighborList
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 numNeighbEutra;  /* The number of E-UTRA neighbor cells */
    UINT16 numNeighbUtra;   /* The number of UTRA neighbor cells */
    UINT16 numNeighbGeran;  /* The number of neighbor cells */
    CiDevLteEng_NeighbEutra neighbEutra[CI_DEV_ENGM_MAX_EUTRA_NEIGHB_MEAS];  /* An array of structures with a length of numNeighbEutra */
    CiDevLteEng_NeighbUtra  neighbUtra[CI_DEV_ENGM_MAX_UTRA_NEIGHB_MEAS];    /* An array of structures with a length of numNeighbUtra */
    CiDevLteEng_NeighbGeran neighbGeran[CI_DEV_ENGM_MAX_GERAN_NEIGHB_MEAS];  /* An array of structures with a length of numNeighbGeran */
} CiDevLteEng_NeighborList;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RrcState / rrcState
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_STATE
{
    CI_DEV_LTE_RRC_STATE_NULL = 0,               /* The E-UTRA RRC state is not applicable. */
    CI_DEV_LTE_RRC_STATE_IDLE_,                   /* The E-UTRA RRC state is RRC_IDLE */
    CI_DEV_LTE_RRC_STATE_ATMPT_CONNECTION,       /* Attempting to establish an RRC connection and enter E-UTRA RRC_CONNECTED state. */
    CI_DEV_LTE_RRC_STATE_CONNECTED_,              /* The E-UTRA RRC state is RRC_CONNECTED */
    CI_DEV_LTE_RRC_STATE_ENDING,                 /* Leaving E-UTRA RRC_CONNECTED state. */
    CI_DEV_LTE_RRC_STATE_ATMPT_OUTBND_MOBILITY,  /* Attempting to leave E-UTRA, i.e., via handover, cell change order, or cell reselection */
    CI_DEV_LTE_RRC_STATE_ATMPT_INBND_MOBILITY    /* Attempting to enter E-UTRA, i.e., via handover, cell change order, or cell reselection */
} _CiDevLteRrcStateExt;

typedef UINT8 CiDevLteRrcStateExt;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RrcState / rrcCause
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RRC_CAUSE
{
    CI_DEV_LTE_RRC_CAUSE_EST_EMERGENCY = 0,            /* The RRC establishment cause is ¡®Emergency¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_EST_HIGH_PRIO_ACC,            /* The RRC establishment cause is ¡®High priority access¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_EST_MT_ACC,                   /* The RRC establishment cause is ¡®MT access¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_EST_MO_SIGNAL,                /* The RRC establishment cause is ¡®MO signaling¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_EST_MO_DATA,                  /* The RRC establishment cause is ¡®MO data¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_REEST_RECFG_FAIL,             /* The RRC reestablishment cause is ¡®Reconfiguration failure¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_REEST_HO_FAIL,                /* The RRC reestablishment cause is ¡®Handover failure¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_REEST_OTHER_FAIL,             /* The RRC reestablishment cause is ¡®Other failure¡¯ Ref. 3GPP TS 36.331, section 6.2.1 */
    CI_DEV_LTE_RRC_CAUSE_REL_OTHER_RECFG_FAIL,         /* RRC connection reconfiguration failed Ref. 3GPP TS 36.331, section 5.3.5.5 */
    CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_IRAT_RES,       /* EL Inter-RAT cell reselection occurred during RRC connection reestablishment Ref. 3GPP TS 36.331, section 5.3.7.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_T311_EXP,       /* RRC connection reestablishment failed due to T311 expiry Ref. 3GPP TS 36.331, section 5.3.7.6 */
    CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_CELL_NOT_SUIT,  /* RRC connection reestablishment failed due to T301 expiry or because the cell is no longer suitable Ref. 3GPP TS 36.331, section 5.3.7.7 */
    CI_DEV_LTE_RRC_CAUSE_REL_CONN_FAIL_REEST_REJ,      /* RRC connection reestablishment failed due to reestablishment rejection Ref. 3GPP TS 36.331, section 5.3.7.8 */
    CI_DEV_LTE_RRC_CAUSE_REL_LOAD_BAL_TAU_REQD,        /* The RRC connection was released with cause ¡®Load balancing TAU required¡¯ Ref. 3GPP TS 36.331, section 5.3.8.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_OTHER,                    /* The RRC connection was released with cause ¡®Other¡¯ Ref. 3GPP TS 36.331, section 5.3.8.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_T310_EXP,                 /* A radio link failure due to T310 expiry (loss of physical layer synchronization) has been detected Ref. 3GPP TS 36.331, section 5.3.11.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_RND_ACC,                  /* A radio link failure due to a random access problem has been detected Ref. 3GPP TS 36.331, section 5.3.11.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_MAX_RLC_RETRANS,          /* A radio link failure due to the maximum number of RLC retransmissions being reached has been detected Ref. 3GPP TS 36.331, section 5.3.11.3 */
    CI_DEV_LTE_RRC_CAUSE_REL_SUCC_MOB_FROM_EUTRAN,     /* Outbound mobility away from E-UTRAN was successful Ref. 3GPP TS 36.331, section 5.4.3.4 */
    CI_DEV_LTE_RRC_CAUSE_EST_FAIL_NO_RESP_FROM_CELL,   /* The RRC connection establishment procedure failed due to T300 expiry (no response from cell) Ref. 3GPP TS 36.331, section 7.3 */
    CI_DEV_LTE_RRC_CAUSE_EST_FAIL_REJ,                 /* The RRC connection was rejected by the cell Ref. 3GPP TS 36.331, section 7.3 */
    CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_RESEL,          /* The RRC connection establishment procedure failed due to cell reselection after the RRC Connection Request message was sent Ref. 3GPP TS 36.331, section 7.3 */
    CI_DEV_LTE_RRC_CAUSE_EST_FAIL_ABORTED,             /* The RRC connection was aborted by the UE Ref. 3GPP TS 36.331, section 7.3 */
    CI_DEV_LTE_RRC_CAUSE_EST_FAIL_CELL_BARRED,         /* The RRC connection establishment procedure failed because the cell is temporarily barred (T302, T303, or T305 is running) Ref. 3GPP TS 36.331, section 7.3 */
    CI_DEV_LTE_RRC_CAUSE_NO_SERVICE = 254,             /* The UE went to no service state either from idle or connected mode */
    CI_DEV_LTE_RRC_CAUSE_NA = 255                      /* RRC cause is not applicable to this state */
} _CiDevLteRrcCause;

typedef UINT8 CiDevLteRrcCause;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RrcState
//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevLteRrcStateExt rrcState;  /* The E-UTRA RRC state */
    CiDevLteRrcCause rrcCause;  /* The E-UTRA RRC cause */
} CiDevLteEng_RrcState;

//for CiDevCommonEngmodeInfo / CiDevLteEng_MAC
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 bufsize0;    /* 0-63; Buffer size for logical channel group #0 */
    UINT8 bufsize1;    /* 0-63; Buffer size for logical channel group #1 */
    UINT8 bufsize2;    /* 0-63; Buffer size for logical channel group #2 */
    UINT8 bufsize3;    /* 0-63; Buffer size for logical channel group #3 */
    UINT16 crnti;      /* C-RNTI */
    UINT8 ta;          /* 0-63; Timing Advance command */
    UINT8 powerHroom;  /* 0-63; Power Headroom */
} CiDevLteEng_MAC;

//for CiDevCommonEngmodeInfo / CiDevLteEng_MAC_RACH
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 earfcn;        /* The accessed cels EARFCN */
    UINT16 phyCellId;     /* The accessed cells physical cell identity */
    UINT16 raRnti;        /* 1-60; RA-RNTI */
    UINT8 preambleCount;  /* 1-200; Total number of preamble transmitted */
    UINT8 lastTxPower;    /* 0-63; Transmit power headroom upon transmission of the last preamble */
    UINT32 ulGrant;       /* UL grant indicated in the Random Access Response */
    UINT16 raTempCrnti;   /* The temporary C-RNTI indicated in the random Access Response */
    UINT16 ta;            /* 0-1282; Timing Advance indicated in the Random Access Response */
    UINT8 raRespSucc;     /* 0 - Random Access Response reception was not successful 1- Random Access Response reception was successful */
} CiDevLteEng_MAC_RACH;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC / CiDevLteEng_drb / rlcMode
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_RLC_MODE
{
    CI_DEV_LTE_RLC_MODE_TM = 0,  /* RLC Transparent Mode */
    CI_DEV_LTE_RLC_MODE_UM,      /* RLC Unacknowledged Mode */
    CI_DEV_LTE_RLC_MODE_AM       /* RLC Acknowledged Mode */
} _CiDevLteRlcMode;

typedef UINT8 CiDevLteRlcMode;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC / CiDevLteEng_drbDl
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8  drbId;         /* (1-32) DRB Id */
    UINT8  epsBearerId;   /* (0, 5-15) EPS Bearer Id */
    UINT8  logicalChId;   /* (3-10) DTCH Logical Channel Id */
    CiDevLteRlcMode rlcMode;  /* TM, UM, AM  RLC transfer mode */
    UINT32 rxSduCount;    /* Number of RLC SDUs received successfully on this DRB */
    UINT32 rxByteCount;   /* Number of RLC SDU bytes received successfully on this DRB */
    UINT32 rxPduCount;    /* Number of RLC PDUs received on this DTCH */
    UINT32 reRxPduCount;  /* Number of RLC PDUs requested for retransmission on this DTCH */
} CiDevLteEng_drbDl;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC / CiDevLteEng_drbUl
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8  drbId;         /* (1-32) DRB Id */
    UINT8  epsBearerId;   /* (0, 5-15) EPS Bearer Id */
    UINT8  logicalChId;   /* (3-10) DTCH Logical Channel Id */
    CiDevLteRlcMode rlcMode;  /* TM, UM, AM  RLC transfer mode */
    UINT32 txSduCount;    /* Number of RLC SDUs submitted via the RLC SAP for transmission on this DRB */
    UINT32 txByteCount;   /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this DRB */
    UINT32 txPduCount;    /* Number of RLC PDUs transmitted on this DTCH */
    UINT32 reTxPduCount;  /* Number of retransmitted RLC PDUs on this DTCH */
} CiDevLteEng_drbUl;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC / CiDevLteEng_srbDl
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8  srbId;         /* (1-2) The SRB Identity */
    UINT16 rxSduCount;    /* Number of RLC SDU's received successfully on this SRB */
    UINT16 rxByteCount;   /* Number of RLC SDU bytes received successfully on this SRB */
    UINT16 rxPduCount;    /* Number of RLC PDUs received on this DCCH */
    UINT16 reRxPduCount;  /* Number of RLC PDUs requested for retransmission on this DCCH */
} CiDevLteEng_srbDl;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC / CiDevLteEng_srbUl
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8  srbId;         /* (1-2) The SRB Identity */
    UINT16 txSduCount;    /* Number of RLC SDUs submitted via the RLC SAP for transmission on this SRB */
    UINT16 txByteCount;   /* Number of RLC SDU bytes submitted via the RLC SAP for transmission on this SRB */
    UINT16 txPduCount;    /* Number of RLC PDUs transmitted on this DCCH */
    UINT16 reTxPduCount;  /* Number of retransmitted RLC PDUs on this DCCH */
} CiDevLteEng_srbUl;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RLC
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16              rlcUlDuration;  /* In our implementation it is always 960  RLC uplink measurement period to which this metric pertains in milliseconds */
    UINT16              rlcDlDuration;  /* In our implementation it is always 960  RLC downlink measurement period to which this metric pertains in milliseconds */
    UINT8               numSrbUl;       /* (1-2) The number of uplink signaling radio bearers represented in this metric */
    UINT8               numSrbDl;       /* (1-2) The number of downlink signaling radio bearers represented in this metric */
    UINT8               numDrbUl;       /* (0-11) The number of uplink data radio bearers represented in this metric */
    UINT8               numDrbDl;       /* (0-11) The number of downlink data radio bearers represented in this metric */
    CiDevLteEng_srbUl   srbUl[2];       /* An array of structures with a length of numSrbUl */
    CiDevLteEng_srbDl   srbDl[2];       /* An array of structures with a length of numSrbDl */
    CiDevLteEng_drbUl   drbUl[12];      /* An array of structures with a length of numDrbUl */
    CiDevLteEng_drbDl   drbDl[12];      /* An array of structures with a length of numDrbDl */
} CiDevLteEng_RLC;

//for CiDevCommonEngmodeInfo / CiDevLteEng_EPS / epsBearerType
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_EPS_BEARER_TYPE
{
    CI_DEV_LTE_EPS_DEFAULT_BEARER = 0,  /* Default EPS Bearer */
    CI_DEV_LTE_EPS_DEDICATED_BEARER     /* Dedicated EPS Bearer */
} _CiDevLteEpsBearerType;

typedef UINT8 CiDevLteEpsBearerType;

//for CiDevCommonEngmodeInfo / CiDevLteEng_EPS / epsBearerNewState
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_EPS_BEARER_CONTEXT_STATE
{
    CI_DEV_LTE_EPS_BEARER_INACTIVE = 0,    /* The EPS bearer Context does not exist */
    CI_DEV_LTE_EPS_BEARER_ACTIVE,          /* The EPS bearer Context is active */
    CI_DEV_LTE_EPS_BEARER_ACTIVE_PENDING,  /* The EPS bearer Context exist but not active */
    CI_DEV_LTE_EPS_BEARER_MODIFY           /* The EPS bearer Context is in a process of being modified */
} _CiDevLteEpsBearereContextState;

typedef UINT8 CiDevLteEpsBearereContextState;

//for CiDevCommonEngmodeInfo / CiDevLteEng_EPS
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 pdnConnectionId;    /* PDN connection id */
    UINT8 epsBearerId;        /* EPS bearer Id */
    CiDevLteEpsBearerType          epsBearerType;      /* EPS bearer type (default or dedicated) */
    CiDevLteEpsBearereContextState epsBearerNewState;  /* The new EPS bearer context state (see 3GPP TS 24.301, 6.1.3.2) */
} CiDevLteEng_EPS;

//for CiDevCommonEngmodeInfo / CiDevLteEng_EPS_QoS / epsQos
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 qci;             /* QoS Class Identifier */
    UINT8 maxBitRateUl;    /* Maximum bit rate for uplink */
    UINT8 maxBitRateDl;    /* Maximum bit rate for downlink */
    UINT8 gbrUl;           /* Guaranteed bit rate for uplink */
    UINT8 gbrDl;           /* Guaranteed bit rate for downlink */
    UINT8 maxBitRateUlEx;  /* Maximum bit rate for uplink (extended) */
    UINT8 maxBitRateDlEx;  /* Maximum bit rate for downlink (extended) */
    UINT8 gbrUlEx;         /* Guaranteed bit rate for uplink (extended) */
    UINT8 gbrDlEx;         /* Guaranteed bit rate for downlink (extended) */
} CiDevLteEng_EpsQos;

//for CiDevCommonEngmodeInfo / CiDevLteEng_EPS_QoS
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 pdnConnectionId;      /* PDN connection id */
    UINT8 epsBearerId;          /* EPS bearer Id linked */
    UINT8 EpsBearerId;          /* The Linked EPS bearer Id when the QoS of a dedicated EPS bearer s assigned or changed */
    CiDevLteEng_EpsQos epsQos;  /* the EPS QoS */
} CiDevLteEng_EPS_QoS;

//for CiDevCommonEngmodeInfo / CiDevLteEng_PUSCH
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 totalPuschTxPower;    /* -112 - 23; Total UE transmit power for PUSCH transmission (dBm) */
    UINT8 puschTxPowerPerRb;    /* -10 - 23; UE transmit power for PUSCH transmission per resource block (dBm) */
    CiBoolean wbReportPresent;  /* Indication if cqiWbDist is valid. TRUE- CQI is present. */
    UINT8 numSubBandReport;     /* 1-4; Number of sub bands for the CQI */
    UINT8 cqiWbDist[CI_DEV_ENGM_CQI_WB_DIST_LENGTH];            /* CQI distribution over all sub-bands */
    UINT8 cqSubBandDist[CI_DEV_ENGM_CQI_SUB_BAND_DIST_LENGTH];  /* CQI distribution for each sub-band */
    UINT16 randIndDist[CI_DEV_ENGM_RANK_IND_DIST_LENGTH];       /* Rank Indicator (RI) distribution. */
    UINT16 pmiDist[CI_DEV_ENGM_PMI_DIST_LENGTH];                /* Precoding matrix Indicator (PMI) distribution */
} CiDevLteEng_PUSCH;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RadioLink / t310Status
//ICAT EXPORTED ENUM
typedef enum CIDEV_LTE_T310_STATUS
{
    CI_DEV_LTE_T310_STATUS_STOPPED = 0,  /* T310 timer has been stopped. Radio link restored */
    CI_DEV_LTE_T310_STATUS_STARTED,      /* T310 timer has been started. Physical layer problems detected */
    CI_DEV_LTE_T310_STATUS_EXPIRED,      /* T310 timer has expired. Radio link has failed */
    CI_DEV_LTE_T310_STATUS_UNKNOWN       /* T310 timer status is invalid */
} _CiDevLteT310Status;

typedef UINT8 CiDevLteT310Status;

//for CiDevCommonEngmodeInfo / CiDevLteEng_RadioLink
//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevLteT310Status t310Status;  /* The status of T310 timer associated with this radio link */
} CiDevLteEng_RadioLink;

/* ===================================================================================
                2G (GSM) & 3G (UMTS) Engineering Mode Structures
   ===================================================================================*/
#define CI_DEV_ENGM_URLC_MAX_NUM_PS_RBS						11		/* Max number of PS RBs	*/
#define CI_DEV_ENGM_URLC_MAX_NUM_CS_RBS 					3		/* Max number of CS RBs	*/
#define CI_DEV_ENGM_URLC_MAX_NUM_SRBS						8		/* Max number of SRBs	*/
#define CI_DEV_ENGM_UMAC_ETFCI_RANGE_MAX_SIZE 				128 	/* E-TFCI range size		*/
#define CI_DEV_ENGM_UMAC_ABSOLUT_GRANT_MAX_NUM_INDEX 		32 		/* Max numer of different absolut grante indexes 	*/
#define CI_DEV_ENGM_URLC_RESET_SEQUENCE_NUM_NOT_AVAILABLE 	255 	/* Reset sequence Number is not available 		*/
#define CI_DEV_ENGM_MAX_L3_GSM_DL_MSG                       251
#define CI_DEV_ENGM_MAX_L3_GSM_UL_MSG                       251
#define CI_DEV_ENGM_MAX_L3_WB_DL_MSG                        1520
#define CI_DEV_ENGM_MAX_L3_WB_UL_MSG                        1520
#define CI_DEV_ENGM_MAX_COMPRESS_MODE_CELL                  6
#define CI_DEV_ENGM_MAX_WB_INTRA_MEAS_CELL                  32
#define CI_DEV_ENGM_MAX_WB_INTER_MEAS_CELL                  32
#define CI_DEV_ENGM_MAX_NUM_OF_RADIO_LINKS                  6

/* GSM and WB SM Metric - Start */
/* GS15 - PDP Context Activation */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32 pdpContextId;
    UINT32 localIpAddress;
    UINT32 ipAddrPrimaryDns;
    UINT32 ipAddrSecondaryDns;
    UINT8  localIpv6Address[16];
    UINT8  strIpV6Dns1[16];
    UINT8  strIpV6Dns2[16];
} CiDevGsmUmtsComnPdpCActEng_SM;

/* GS18 - PDP Context End */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_SM_CAUSE_TYPE
{
    CI_DEV_SM_CAUSE_NO_NET_RESPONSE = 0,
    CI_DEV_SM_CAUSE_OP_DET_BARRING = 8,
    CI_DEV_SM_CAUSE_LLC_SNDCP_FAILURE = 25,
    CI_DEV_SM_CAUSE_INSUFF_RESOURCES = 26,
    CI_DEV_SM_CAUSE_UNKN_MISS_APN = 27,
    CI_DEV_SM_CAUSE_UNKN_PDP_ADDR_TYPE = 28,
    CI_DEV_SM_CAUSE_USER_AUTH_FAILED = 29,
    CI_DEV_SM_CAUSE_ACT_REJ_BY_GGSN = 30,
    CI_DEV_SM_CAUSE_ACT_REJ_UNSPEC = 31,
    CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUPP = 32,
    CI_DEV_SM_CAUSE_SERV_OPT_NOT_SUBS = 33,
    CI_DEV_SM_CAUSE_SERV_OPT_TEMP_OUT_OF_ORDER = 34,
    CI_DEV_SM_CAUSE_NSAPI_ALREADY_USED = 35,
    CI_DEV_SM_CAUSE_REG_PDP_CONT_DEACT = 36,
    CI_DEV_SM_CAUSE_QOS_NOT_ACCEPTED = 37,
    CI_DEV_SM_CAUSE_NETWORK_FAILURE = 38,
    CI_DEV_SM_CAUSE_REACTIVATION_REQUESTED = 39,
    CI_DEV_SM_CAUSE_FEAT_NOT_SUPP = 40,
    CI_DEV_SM_CAUSE_SEM_ERR_TFT_OP = 41,
    CI_DEV_SM_CAUSE_SYN_ERR_TFT_OP = 42,
    CI_DEV_SM_CAUSE_UNKN_PDP_CONTEXT = 43,
    CI_DEV_SM_CAUSE_SEM_ERR_PKT_FILTER = 44,
    CI_DEV_SM_CAUSE_SYN_ERR_PKT_FILTER = 45,
    CI_DEV_SM_CAUSE_PDP_CXT_WOUT_TFT_ACT = 46,
    CI_DEV_SM_CAUSE_MULTICAST_GRP_TIMEOUT = 47,
    CI_DEV_SM_CAUSE_ACTIVATION_REJ_BCM_VIOLATION = 48,
    CI_DEV_SM_CAUSE_IPV4_ONLY = 50,
    CI_DEV_SM_CAUSE_IPV6_ONLY = 51,
    CI_DEV_SM_CAUSE_SINGLE_ADDR_ONLY = 52,
    CI_DEV_SM_CAUSE_COLLISION = 56,
    CI_DEV_SM_CAUSE_INVALID_TRANS_ID_VALUE = 81,
    CI_DEV_SM_CAUSE_SEM_INCORRECT_MESSAGE = 95,
    CI_DEV_SM_CAUSE_INVALID_MANDATORY_INFO = 96,
    CI_DEV_SM_CAUSE_NONEXISTENT_MESSAGE_TYPE = 97,
    CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE_TYPE = 98,
    CI_DEV_SM_CAUSE_NONEXISTENT_INFO_ELEMENT = 99,
    CI_DEV_SM_CAUSE_CONDITIONAL_IE_ERROR = 100,
    CI_DEV_SM_CAUSE_INCOMPATIBLE_MESSAGE = 101,
    CI_DEV_SM_CAUSE_PROTOCOL_ERROR_UNSPEC = 111,
    CI_DEV_SM_CAUSE_INCOMPATIBLE_APN_RESTR_VALUE = 112
} _CiDevSmCauseType;

typedef UINT8 CiDevSmCauseType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_SM_PDP_INITIATOR_TYPE
{
    CI_DEV_SM_NETWORK_INITIATED = 0,
    CI_DEV_SM_UE_INITIATED
} _CiDevSmPdpInitiatorType;

typedef UINT8 CiDevSmPdpInitiatorType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32                  pdpContextId;
    CiDevSmCauseType        termCode;
    CiDevSmPdpInitiatorType pdpInitiator;
} CiDevGsmUmtsComnPdpCEndEng_SM;

/* GS19 - PDP Context Request */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_SM_ORDINAL_TYPE
{
    CI_DEV_SM_PRIMARY_PDP_CONTEXT = 0,
    CI_DEV_SM_SECONDARY_PDP_CONTEXT
} _CiDevSmOrdinalType;

typedef UINT8 CiDevSmOrdinalType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32                  pdpContextId;
    UINT32                  assocContextId;
    CiDevSmOrdinalType      ordinal;
    CiDevSmPdpInitiatorType pdpInitiator;
    UINT8                   nsapi;
    UINT8                   sapi;
    UINT8                   apn[100];
} CiDevGsmUmtsComnPdpCReqEng_SM;

/* GSM and WB SM Metric - End */

/* GSM and WB MM Metric - Start */
/* GS40 - Attach Begin */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_ATTACH_TYPE
{
    CI_DEV_MM_GPRS_ATTACH = 0,
    CI_DEV_MM_GPRS_ATTACH_WHILE_IMSI_ATTACHED,
    CI_DEV_MM_COMB_GPRS_ATTACH_IMSI_ATTACH,
    CI_DEV_MM_IMSI_ATTACH
} _CiDevMmAttachType;

typedef UINT8 CiDevMmAttachType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_IDENTITY_TYPE
{
    CI_DEV_MM_NO_IDENTITY = 0,
    CI_DEV_MM_IMSI,
    CI_DEV_MM_IMEI,
    CI_DEV_MM_IMEISV,
    CI_DEV_MM_TMSI_PTMSI
} _CiDevMmIdentityType;

typedef UINT8 CiDevMmIdentityType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevMmAttachType   attachType;
    CiDevMmIdentityType identityType;
    UINT8               strIdentity[16];
} CiDevGsmUmtsComnAttachBeginEng_MM;

/* GS41 - Attach End */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_ATTACH_MSG_TYPE
{
    CI_DEV_MM_ATTACH_ACCEPT = 0,
    CI_DEV_MM_ATTACH_COMPLETE,
    CI_DEV_MM_ATTACH_REJECT,
    CI_DEV_MM_LOC_UPDATE_ACCEPT,
    CI_DEV_MM_LOC_UPDATE_REJECT
} _CiDevMmAttachMsgType;

typedef UINT8 CiDevMmAttachMsgType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_ATTACH_RESULT_TYPE
{
    CI_DEV_MM_GPRS_ONLY_ATTACHED = 0,
    CI_DEV_MM_COMB_GPRS_IMSI_ATTACHED,
    CI_DEV_MM_IMSI_ATTACHED
} _CiDevMmAttachResultType;

typedef UINT8 CiDevMmAttachResultType;

/*
typedef enum CI_DEV_MM_GMM_CAUSE_TYPE
{
    CAUSE_UNASSIGNED_NO = 0,
    CAUSE_NO_ROUTE_TO_DEST,
    CAUSE_CHAN_UNACCEPTABLE,
    CAUSE_OPER_DETERM_BARRING,
    CAUSE_NORMAL_CLEARING,
    CAUSE_USER_BUSY,
    CAUSE_NO_USER_RESPONDING,
    CAUSE_ALERTING_NO_ANSWER,
    CAUSE_CALL_REJECTED,
    CAUSE_NUMBER_CHANGED,
    CAUSE_PREEMPTION,
    CAUSE_NONSEL_USER_CLRING,
    CAUSE_DEST_OUT_OF_ORDER,
    CAUSE_INVALID_NO_FORMAT,
    CAUSE_FACILITY_REJECTED,
    CAUSE_RSP_TO_STATUS_ENQ,
    CAUSE_NORMAL_UNSPECIFIED,
    CAUSE_NO_CIRC_CHAN_AV,
    CAUSE_NET_OUT_OF_ORDER,
    CAUSE_TEMP_FAILURE,
    CAUSE_SWITCH_CONGESTION,
    CAUSE_ACC_INFO_DISCARDED,
    CAUSE_REQ_CIRC_CHAN_UNAV,
    CAUSE_RESOURCES_UNAV,
    CAUSE_QOS_UNAV,
    CAUSE_REQ_FAC_NOT_SUBSCR,
    CAUSE_CUG_INCOMING_BARRED,
    CAUSE_BEAR_CAP_NOT_AUTH,
    CAUSE_BEAR_CAP_UNAV,
    CAUSE_SERV_OPT_UNAV,
    CAUSE_BEAR_SVC_NOT_IMPL,
    CAUSE_ACM_EQ_OR_GT_ACMMAX,
    CAUSE_REQ_FACIL_NOT_IMPL,
    CAUSE_ONLY_RESTRIC_DIG_AV,
    CAUSE_SVC_OPT_NOT_IMPL,
    CAUSE_INVALID_TI,
    CAUSE_USER_NOT_IN_CUG,
    CAUSE_INCOMPAT_DEST,
    CAUSE_INVALID_TRANSIT_NET,
    CAUSE_INVALID_MSG_SEMANTIC,
    CAUSE_MAND_IE_ERROR,
    CAUSE_MSG_NONEXISTENT,
    CAUSE_MSG_GEN_ERROR,
    CAUSE_IE_NONEXISTENT,
    CAUSE_INVALID_CONDITION_IE,
    CAUSE_MSG_INCOMPAT_STATE,
    CAUSE_RECOV_ON_TIMER_EXP,
    CAUSE_PROTOCOL_ERROR,
    CAUSE_INTERWORKING
}_CiDevMmGmmCauseType;
*/

typedef UINT8 CiDevMmGmmCauseType; // TODO: [Alon] Not sure about this one.

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32                  Identity;
    CiDevMmAttachMsgType    attachMsgType;
    CiDevMmGmmCauseType     gmmCause;
    CiDevMmAttachResultType attachResult;
} CiDevGsmUmtsComnAttachEndEng_MM;

/* GS42 - Detach Accept */
typedef UINT8 CiDevGsmUmtsComnDetachAcceptEng_MM; // TODO: [Alon] G42 not clear

/* GS43 - Routing Area Update */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_AREA_UPDATE_RESULT_TYPE
{
    CI_DEV_MM_AREA_UPDATE_RESULT_RA_UPDATED = 0,
    CI_DEV_MM_AREA_UPDATE_RESULT_COMB_RA_LA_UPDATED = 1
} _CiDevMmAreaUpdateResultType;

typedef UINT8 CiDevMmAreaUpdateResultType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32 Identity;
    UINT16 newLAC;
    UINT8 newRAC;
    CiDevMmGmmCauseType gmmCause;
    CiDevMmAreaUpdateResultType raUpdateRes;
} CiDevGsmUmtsComnRAUEng_MM;

/* GS46 - GSM/GPRS/UMTS Network Info */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_ACCESS_TECH_TYPE
{
    CI_DEV_MM_ACCESS_TECH_UNKNOWN = 0,
    CI_DEV_MM_ACCESS_TECH_GERAN   = 1,
    CI_DEV_MM_ACCESS_TECH_UTRAN   = 2,
    CI_DEV_MM_ACCESS_TECH_NONE    = 255
} _CiDevMmAccessTechType;

typedef UINT8 CiDevMmAccessTechType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_FREQ_BAND_TYPE
{
    CI_DEV_MM_BAND_INFO_T_GSM_380,
    CI_DEV_MM_BAND_INFO_T_GSM_410,
    CI_DEV_MM_BAND_INFO_GSM_450,
    CI_DEV_MM_BAND_INFO_GSM_480,
    CI_DEV_MM_BAND_INFO_GSM_710,
    CI_DEV_MM_BAND_INFO_GSM_750,
    CI_DEV_MM_BAND_INFO_T_GSM_810,
    CI_DEV_MM_BAND_INFO_GSM_850,
    CI_DEV_MM_BAND_INFO_P_GSM_900,
    CI_DEV_MM_BAND_INFO_E_GSM_900,
    CI_DEV_MM_BAND_INFO_R_GSM_900,
    CI_DEV_MM_BAND_INFO_T_GSM_900,
    CI_DEV_MM_BAND_INFO_DCS_1800,
    CI_DEV_MM_BAND_INFO_PCS_1800,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_I,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_II,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_III,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_IV,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_V,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_VI,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_VII,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_VIII,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_IX,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_X,
    CI_DEV_MM_BAND_INFO_UTRA_FDD_XI,
    CI_DEV_MM_BAND_INFO_NOT_AVAILABLE = 255
} _CiDevMmFreqBandType;

typedef UINT8 CiDevMmFreqBandType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                 fieldValidity;
    UINT8                 rac;
    CiDevMmAccessTechType accessTech;
    CiDevMmFreqBandType   freqBand;
    UINT16                mcc;
    UINT16                mnc;
    UINT16                lac;
    UINT32                cellId;
    UINT16                rncID;
} CiDevGsmUmtsComnNetInfoEng_MM;

/* GS47 - Service State */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_RADIO_SVC_STATE_TYPE
{
    CI_DEV_MM_RADIO_SERV_STATE_UNKNOWN = 0,
    CI_DEV_MM_RADIO_SERV_STATE_OFF,
    CI_DEV_MM_RADIO_SERV_STATE_SEARCHING,
    CI_DEV_MM_RADIO_SERV_STATE_NO_SERVICE,
    CI_DEV_MM_RADIO_SERV_STATE_2G,
    CI_DEV_MM_RADIO_SERV_STATE_3G,
    CI_DEV_MM_RADIO_SERV_STATE_4G
} _CiDevMmRadioSvcStateType;

typedef UINT8 CiDevMmRadioSvcStateType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_NETWORK_SVC_STATE_TYPE
{
    CI_DEV_MM_NETW_SERV_STATE_NONE = 0,
    CI_DEV_MM_NETW_SERV_STATE_EMERGENCY,
    CI_DEV_MM_NETW_SERV_STATE_HOME,
    CI_DEV_MM_NETW_SERV_STATE_HOME_EQUIV,
    CI_DEV_MM_NETW_SERV_STATE_ROAM
} _CiDevMmNetworkSvcStateType;

typedef UINT8 CiDevMmNetworkSvcStateType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevMmRadioSvcStateType   radioSvcState;
    CiDevMmNetworkSvcStateType networkSvcState;
} CiDevGsmUmtsComnServcStateEng_MM;

/* GS6E - Radio Mode */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_MM_RADIO_MODE_TYPE
{
    CI_DEV_MM_RADIO_MODE_NONE = 0,
    CI_DEV_MM_RADIO_MODE_GSM,
    CI_DEV_MM_RADIO_MODE_GPRS,
    CI_DEV_MM_RADIO_MODE_EDGE,
    CI_DEV_MM_RADIO_MODE_WCDMA,
    CI_DEV_MM_RADIO_MODE_HSDPA,
    CI_DEV_MM_RADIO_MODE_HSUPA,
    CI_DEV_MM_RADIO_MODE_HSPA,
    CI_DEV_MM_RADIO_MODE_HSPA_PLUS,
    CI_DEV_MM_RADIO_MODE_LTE,
    CI_DEV_MM_RADIO_MODE_RTT,
    CI_DEV_MM_RADIO_MODE_EVDO,
    CI_DEV_MM_RADIO_MODE_WIFI
} _CiDevMmRadioModeType;

typedef UINT8 CiDevMmRadioModeType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevMmRadioModeType radioMode;
} CiDevGsmUmtsComnRadioModeEng_MM;

/* GS30 - GSM/GPRS/EDGE Layer 3 Downlink Message */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_PROTOCOL_DICRIMINATOR_TYPE
{
    CI_DEV_RR_DISCR_GROUP_CALL_CONTROL = 0,   /* Group call control */
    CI_DEV_RR_DISCR_BC_CALL_CONTROL    = 1,   /* Broadcast call control */
    CI_DEV_RR_DISCR_RESERVED1          = 2,   /* Reserved */
    CI_DEV_RR_DISCR_CALL_CONTROL       = 3,   /* Call control; call related SS messages */
    CI_DEV_RR_DISCR_GTTP               = 4,   /* GPRS transparent transport protocol (GTTP) */
    CI_DEV_RR_DISCR_MM                 = 5,   /* Mobility management messages */
    CI_DEV_RR_DISCR_RR                 = 6,   /* Radio resources management messages */
    CI_DEV_RR_DISCR_GMM                = 8,   /* GPRS mobility management messages */
    CI_DEV_RR_DISCR_SMS                = 9,   /* SMS messages */
    CI_DEV_RR_DISCR_SM                 = 10,  /* GPRS session management messages */
    CI_DEV_RR_DISCR_SS                 = 11,  /* Non call related SS messages */
    CI_DEV_RR_DISCR_LCS                = 12,  /* Location services */
    CI_DEV_RR_DISCR_RESERVED2          = 14,  /* Reserved */
    CI_DEV_RR_DISCR_RESERVED3          = 15   /* Reserved */
} _CiDevRrProtocolDicriminatorType;

typedef UINT8 CiDevRrProtocolDicriminatorType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_LOGICAL_CHANNEL_TYPE
{
    CI_DEV_RR_CHANNEL_BCCH = 0,          /* GSM Broadcast Control Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PCH,               /* GSM Paging Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_RACH,              /* GSM Random Access Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_AGCH,              /* GSM Access Grant Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_NCH,               /* GSM Notification Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_SACCH,             /* GSM Slow Associated Control Channel */
    CI_DEV_RR_CHANNEL_FACCH,             /* GSM Fast Associated Control Channel */
    CI_DEV_RR_CHANNEL_SDCCH,             /* GSM Standalone Dedicated Control Channel */
    CI_DEV_RR_CHANNEL_PBCCH,             /* GPRS Packet Broadcast Control Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PPCH,              /* GPRS Packet Paging Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PRACH,             /* GPRS Packet Random Access Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_PAGCH,             /* GPRS Packet Access Grant Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PACCH,             /* GPRS Packet Associated Control Channel */
    CI_DEV_RR_CHANNEL_CCCH_RACH,         /* UMTS Common Control Channel over Random Access Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_DCCH_RACH,         /* UMTS Dedicated Control Channel over Random Access Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_DCCH_DCH,          /* UMTS Dedicated Control Channel over Random Access Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_DCCH_EDCH,         /* UMTS Dedicated Control Channel over Enhanced Dedicated Channel (Uplink only) */
    CI_DEV_RR_CHANNEL_BCCH_BCH,          /* UMTS Broadcast Control Channel over Broadcast Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_BCCH_FACH,         /* UMTS Broadcast Control Channel over Forward Access Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_BCCH_HSDSCH,       /* UMTS Broadcast Control Channel over High-speed Downlink Shared Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PCCH_PCH,          /* UMTS Paging Control Channel over Paging Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_PCCH_HSDSCH,       /* UMTS Paging Control Channel over High-speed Downlink Shared Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_CCCH_FACH,         /* UMTS Common Control Channel over Forward Access Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_CCCH_HSDSCH,       /* UMTS Common Control Channel over High-speed Downlink Shared Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_DCCH_FACH,         /* UMTS Dedicated Control Channel over Forward Access Channel (Downlink only) */
    CI_DEV_RR_CHANNEL_DCCH_HSDSCH,       /* UMTS Dedicated Control Channel over High-speed Downlink Shared Channel (Downlink only) */
    CI_DEV_CHANNEL_NOT_APPLICABLE = 255  /* Not applicable for this L3 protocol */
} _CiDevRrLogicalChannelType;

typedef UINT8 CiDevRrLogicalChannelType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                           transactionId;
    CiDevRrProtocolDicriminatorType protDiscr;
    UINT8                           msgType;
    CiDevRrLogicalChannelType       logicalChannelType;
    UINT8                           msg[CI_DEV_ENGM_MAX_L3_GSM_DL_MSG];
} CiDevGsmLayer3DwnlnkMsgEng_GRR;

/* GS31 - GSM/GPRS/EDGE Layer 3 Uplink Message */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                           transactionId;
    CiDevRrProtocolDicriminatorType protDiscr;
    UINT8                           sendSeqNum;
    UINT8                           msgType;
    CiDevRrLogicalChannelType       logicalChannelType;
    UINT8                           msg[CI_DEV_ENGM_MAX_L3_GSM_UL_MSG];
} CiDevGsmLayer3UplnkMsgEng_GRR;

/* RF51 - GSM /GPRS/EDGE RF Serving Cell Info */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 bcchArfcn;
    UINT8  rxLev;
    UINT8  bsic;
    BOOL   bandInd;
} CiDevGsmRfServingCellInfoEng_GRR;

/* RF53 - GSM Neighbor Measurements */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 arfcn;
    UINT8  bsic;
    UINT8  rxLev;
} CiDevRrGsmNcellMeasType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 uarfcn;
    UINT16 scramblingCode;
    UINT8  rssi;
    UINT8  ecNo;
    UINT8  rscp;
} CiDevRrInterRatMeasType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   numGsmMeas;
    BOOL                    numInterRatMeas;
    CiDevRrGsmNcellMeasType gsmMeas[32];
    CiDevRrInterRatMeasType interRatMeas[32];
} CiDevGsmNeighbrMeasEng_GRR;

/* GS57 - Cell Change Begin */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_CELL_CHANGE_ORDER_TYPE
{
    CI_DEV_RR_CCO_MSG_RR_CELL_CHANGE_ORDER = 0,      /* RR-Cell Change Order */
    CI_DEV_RR_CCO_MSG_PACKET_CELL_CHANGE_ORDER,      /* Packet Cell Change Order */
    CI_DEV_RR_CCO_MSG_CELL_CHANGE_ORDER_FROM_UTRAN,  /* Cell Change Order From UTRAN */
    CI_DEV_RR_CCO_MSG_PS_HANDOVER_COMMAND,           /* PS Handover Command */
} _CiDevRrCellCngOrdMsgType;

typedef UINT8 CiDevRrCellCngOrdMsgType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrCellCngOrdMsgType    cellChangeMsg;  /* Cell change message type */
    UINT8                       targetBsic;     /* GERAN Target cell: BSIC (0xFF if not applicable) */
    UINT16                      targetArfcn;    /* Bit 15: ARFCN is DCS (0) or PCS (1) ; Bits 0-14: GERAN Target cell: ARFCN (0x7FFF if not applicable) */
    UINT16                      targetUarfcn;   /* UTRAN Target cell: UARFCN (0xFFFF if not applicable) */
    UINT16                      targetSc;       /* UTRAN Target cell: Primary Scrambling code (0xFFFF if not applicable) */
} CiDevGsmWbCellChngBginEng_RR;

/* GS58 - Cell Change End */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_RESULT_TYPE
{
    CI_DEV_RR_RESULT_SUCCESS = 0,   /* The procedure was successful */
    CI_DEV_RR_RESULT_FAILURE,       /* The procedure was unsuccessful */
    CI_DEV_RR_RESULT_UNKNOWN = 255  /* The result of the procedure is invalid or unknown, or this field is not applicable */
} _CiDevRrResultType;

typedef UINT8 CiDevRrResultType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_IRAT_CH_CAUSE_TYPE
{
    CI_DEV_RR_RAT_CH_CAUSE_CONFIGURATION_UNACCEPTABLE = 0,  /* Configuration unacceptable */
    CI_DEV_RR_IRAT_CH_CAUSE_PHYSICAL_CHAN_FAILURE,          /* Physical Channel Failure */
    CI_DEV_RR_RAT_CH_CAUSE_PROTOCOL_ERROR,                  /* Protocol Error */
    CI_DEV_RR_IRAT_CH_CAUSE_UNSPECIFIED                     /* Unspecified */
} _CiDevRrIratChCauseType;

typedef UINT8 CiDevRrIratChCauseType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_PROTOCOL_ERROR_CAUSE_TYPE
{
    CI_DEV_RR_PROT_ERR_CAUSE_ASN_VIOL_ENC_ERR = 0,       /* ASN.1 violation or encoding error */
    CI_DEV_RR_PROT_ERR_CAUSE_MSG_TYPE_NON_EXIST,         /* Message type non-existent or not implemented */
    CI_DEV_RR_PROT_ERR_CAUSE_MSG_NOT_COMPATIBLE,         /* Message not compatible with receiver state */
    CI_DEV_RR_PROT_ERR_CAUSE_IE_VALUE_NOT_COMPREHENDED,  /* Information element value not comprehended */
    CI_DEV_RR_PROT_ERR_CAUSE_IE_MISSING,                 /* Information element missing */
    CI_DEV_RR_PROT_ERR_CAUSE_MSG_EXT_NOT_COMPREHENDED,   /* Message extension not comprehended */
    CI_DEV_RR_PROT_ERR_CAUSE_UNKNOWN = 255               /* Error cause is not known or cannot be supplied */
} _CiDevRrProtErrCauseType;

typedef UINT8 CiDevRrProtErrCauseType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_CELL_CHANGE_FAIL_TYPE
{
    CI_DEV_RR_CELL_CH_FAIL_FREQ_NOT_IMPLEMENTED = 0,  /* Frequency not implemented */
    CI_DEV_RR_CELL_CH_FAIL_NO_RESP_ON_TARGET_CELL,    /* No response on target cell */
    CI_DEV_RR_CELL_CH_FAIL_IMMED_ASS_PACCESS_REJ,     /* Immediate Assign Reject or Packet Access Reject on target cell */
    CI_DEV_RR_CELL_CH_FAIL_ON_GOING_CS_CONN,          /* On going CS connection */
    CI_DEV_RR_CELL_CH_FAIL_MS_IN_GMM_STANDBY,         /* MS in GMM Standby state */
    CI_DEV_RR_CELL_CH_FAIL_FORCED_TO_STANDBY,         /* Forced to the Standby state */
    CI_DEV_RR_CELL_CH_FAIL_RESERVED                   /* Reserved */
} _CiDevRrCellChngFailType;

typedef UINT8 CiDevRrCellChngFailType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrResultType           Result;       /* Result of the cell change procedure */
    CiDevRrIratChCauseType      irFailure;    /* Inter-RAT Cell Change failure */
    CiDevRrProtErrCauseType     irProtCause;  /* Protocol error cause, only valid if IrFailure = RR_CH_CAUSE_PROTOCOL_ERROR */
    CiDevRrCellChngFailType     cellChCause;  /* Packet Cell Change Failure */
} CiDevGsmWbCellChngEndEng_RR;

/* GS54 - Handover Begin */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_HANDOVER_TYPE
{
    CI_DEV_RR_HANDOVER_TYPE_GSM_NON_SYNCHRONIZED = 0,  /* non-synchronized (GSM) */
    CI_DEV_RR_HANDOVER_TYPE_GSM_SYNCHRONIZED,          /* synchronized (GSM) */
    CI_DEV_RR_HANDOVER_TYPE_GSM_PRE_SYNCHRONIZED,      /* pre-synchronized (GSM) */
    CI_DEV_RR_HANDOVER_TYPE_GSM_PSEUDO_SYNCHRONIZED,   /* pseudo-synchronized (GSM) */
    CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTRA_FREQUENCY,     /* intra-frequency (WCDMA) */
    CI_DEV_RR_HANDOVER_TYPE_WCDMA_INTER_FREQUENCY,     /* inter-frequency (WCDMA) */
    CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_GSM_TO_WCDMA,    /* inter-RAT (GSM to WCDMA) */
    CI_DEV_RR_HANDOVER_TYPE_INTER_RAT_WCDMA_TO_GSM     /* inter-RAT (WCDMA to GSM) */
} _CiDevRrhandoverType;

typedef UINT8 CiDevRrhandoverType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrhandoverType handoverType;  /* Type of handover to be performed */
    UINT8               targetBsic;    /*   GERAN Target cell: BSIC (0xFF if not applicable) */
    UINT16              targetArfcn;   /* Bit 15: ARFCN is DCS (0) or PCS (1)  Bits 0-14: GERAN Target cell: ARFCN (0x7FFF if not applicable) */
    UINT16              targetUarfcn;  /* UTRAN Target cell: UARFCN (0xFFFF if not applicable) */
    UINT16              targetSc;      /* UTRAN Target cell: Primary Scrambling code (0xFFFF if not applicable) */
} CiDevGsmWbHandoverBgnEng_RR;

/* GS55 - Handover End */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_HANDOVER_END_TYPE
{
    CI_DEV_RR_HANDOVER_END_COMPLETE = 0,               /* HANDOVER COMPLETE */
    CI_DEV_RR_HANDOVER_END_FAILURE,                    /* HANDOVER FAILURE */
    CI_DEV_RR_HANDOVER_END_TO_UTRAN_COMPLETE,          /* HANDOVER TO UTRAN COMPLETE */
    CI_DEV_RR_HANDOVER_END_FROM_UTRAN_FAILURE,         /* HANDOVER FROM UTRAN FAILURE */
    CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_COMPLETE,  /* RADIO BEARER SETUP COMPLETE... */
    CI_DEV_RR_HANDOVER_END_WCDMA_INTER_FREQ_FAILURE    /* RADIO BEARER SETUP FAILURE... */
} _CiDevRrhandoverEndType;

typedef UINT8 CiDevRrhandoverEndType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_CAUSE_TYPE
{
    CI_DEV_RR_CAUSE_NORMAL_EVENT                      = 0,    /* Normal event */
    CI_DEV_RR_CAUSE_ABNORMAL_REL_UNSPECIFIED          = 1,    /* Abnormal release, unspecified */
    CI_DEV_RR_CAUSE_ABNORMAL_REL_CHAN_UNACCEPTABLE    = 2,    /* Abnormal release, channel unacceptable */
    CI_DEV_RR_CAUSE_ABNORMAL_REL_TIMER_EXPIRED        = 3,    /* Abnormal release, timer expired */
    CI_DEV_RR_CAUSE_ABNORMAL_REL_NO_ACT_ON_RADIO_PATH = 4,    /* Abnormal release, no activity on the radio path */
    CI_DEV_RR_CAUSE_PREEMPTIVE_RELEASE                = 5,    /* Preemptive release */
    CI_DEV_RR_CAUSE_UTRAN_CONFIG_UNKNOWN              = 6,    /* UTRAN configuration unknown */
    CI_DEV_RR_CAUSE_HO_IMPOSSIBLE_TA_OOR              = 8,    /* Handover impossible, timing advance out of range */
    CI_DEV_RR_CAUSE_CHANNEL_MODE_UNACCEPTABLE         = 9,    /* Channel mode unacceptable */
    CI_DEV_RR_CAUSE_FREQ_NOT_IMPLEMENTED              = 10,   /* Frequency not implemented */
    CI_DEV_RR_CAUSE_ORIG_TALKER_LEAVING_GROUP_AREA    = 11,   /* Originator or talker leaving group call area */
    CI_DEV_RR_CAUSE_LOWER_LAYER_FAILURE               = 12,   /* Lower layer failure */
    CI_DEV_RR_CAUSE_CALL_ALREADY_CLEARED              = 65,   /* Call already cleared */
    CI_DEV_RR_CAUSE_SEMAN_INCORRECT_MESSAGE           = 95,   /* Semantically incorrect message */
    CI_DEV_RR_CAUSE_INVALID_MAND_INFO                 = 96,   /* Invalid mandatory information */
    CI_DEV_RR_CAUSE_MESSAGE_TYPE_NON_EXISTENT         = 97,   /* Message type non-existent or not implemented */
    CI_DEV_RR_CAUSE_MESSAGE_TYPE_NOT_COMPATIBLE       = 98,   /* Message type not compatible with protocol state */
    CI_DEV_RR_CAUSE_CONDITIONAL_IE_ERROR              = 100,  /* Conditional IE error */
    CI_DEV_RR_CAUSE_NO_CELL_ALLOC_AVAILABLE           = 101,  /* No cell allocation available */
    CI_DEV_RR_CAUSE_PROTOCOL_ERR_UNSPECIFIED          = 111   /* Protocol error unspecified */
} _CiDevRrCauseType;

typedef UINT8 CiDevRrCauseType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_IRAT_HANDOVER_FAILURE_TYPE
{
    CI_DEV_RR_IRAT_HO_CAUSE_CONFIGURATION_UNACCEPTABLE,  /* Configuration unacceptable */
    CI_DEV_RR_IRAT_HO_CAUSE_PHYSICAL_CHAN_FAILURE,       /* Physical Channel Failure */
    CI_DEV_RR_IRAT_HO_CAUSE_PROTOCOL_ERROR,              /* Protocol Error */
    CI_DEV_RR_IRAT_HO_CAUSE_INTER_RAT_PROTOCOL_ERROR,    /* Inter-Rat protocol error */
    CI_DEV_RR_IRAT_HO_CAUSE_UNSPECIFIED                  /* Unspecified */
}  _CiDevRrIrHandoverFailureType;

typedef UINT8 CiDevRrIrHandoverFailureType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_RRC_HANDOVER_FAILURE_TYPE
{
    CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_UNSUPPORTED = 0,  /* Configuration unsupported */
    CI_DEV_RR_FAILURE_CAUSE_PHYSICAL_CHANNEL_FAILURE,       /* Physical Channel Failure */
    CI_DEV_RR_FAILURE_CAUSE_INCOMPAT_SIM_RECONFIGURATION,   /* Incompatible Simultaneous Reconfiguration */
    CI_DEV_RR_FAILURE_CAUSE_COMPRESSED_MODE_RT_ERROR,       /* Compressed Mode Runtime Error */
    CI_DEV_RR_FAILURE_CAUSE_PROTOCOL_ERROR,                 /* Protocol Error */
    CI_DEV_RR_FAILURE_CAUSE_CELL_UPDATE_OCCURRED,           /* Cell Update Occurred */
    CI_DEV_RR_FAILURE_CAUSE_INVALID_CONFIGURATION,          /* Invalid Configuration */
    CI_DEV_RR_FAILURE_CAUSE_CONFIGURATION_INCOMPLETE,       /* Configuration Incomplete */
    CI_DEV_RR_FAILURE_CAUSE_UNSUPPORTED_MEASUREMENT,        /* Unsupported Measurement */
    CI_DEV_RR_FAILURE_CAUSE_UNKNOWN = 255                   /* Unknown or successful configuration */
} _CiDevRrcHandoverFailureType;

typedef UINT8 CiDevRrcHandoverFailureType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrhandoverEndType       handoverMsg;         /* Type of handover message sent */
    CiDevRrCauseType             rrCause;             /* RR Cause IE from HANDOVER COMPLETE & HANDOVER FAILURE messages.  The values are derived directly from 3GPP TS 44.018 section 10.5.2.31, RR Cause */
    CiDevRrIrHandoverFailureType irHandoverFailure;   /* Inter-RAT handover failure cause for normal handovers */
    CiDevRrcHandoverFailureType  rrcHandoverFailure;  /* RRC failure cause for UMTS hard handovers */
    CiDevRrProtErrCauseType      iRProtCause;         /* Protocol error cause, only valid if ucIRFailure = IQ_IRAT_CAUSE_INTER_RAT_PROTOCOL_ERROR or IQ_FAILURE_CAUSE_PROTOCOL_ERROR */
} CiDevGsmWbHandoverEndEng_RR;

/* GS81 - GPRS/EDGE RLC Statistics */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RLC_UL_MODE_TYPE
{
    CI_DEV_RLC_MODE_UNKNOWN = 0,      /* Mode could not be determined */
    CI_DEV_RLC_MODE_UNACKNOWLEDGED,   /* Unacknowledged mode */
    CI_DEV_RLC_MODE_ACKNOWLEDGED,     /* Acknowledged mode */
    CI_DEV_RLC_MODE_TRANSPARENT,      /* Transparent mode */
    CI_DEV_RLC_MODE_FLEXIBLELAYERONE  /* FLO mode (GPRS/EDGE only) */
} _CiDevRlcUlModeType;

typedef UINT8 CiDevRlcUlModeType;

typedef CiDevRlcUlModeType CiDevRlcDlModeType;

//ICAT EXPORTED ENUM
typedef enum CI_DEV_RLC_MCS_TYPE
{
    CI_DEV_RLC_MCS_TYPE_CS1 = 0,              /* GPRS Coding Scheme 1 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_CS2,                  /* GPRS Coding Scheme 2 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_CS3,                  /* GPRS Coding Scheme 3 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_CS4,                  /* GPRS Coding Scheme 4 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_MCS1,                 /* EDGE Modulation Coding Scheme 1 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_MCS2,                 /* EDGE Modulation Coding Scheme 2 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_MCS3,                 /* EDGE Modulation Coding Scheme 3 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_MCS4,                 /* EDGE Modulation Coding Scheme 4 (GMSK) */
    CI_DEV_RLC_MCS_TYPE_MCS5,                 /* EDGE Modulation Coding Scheme 5 (8PSK) */
    CI_DEV_RLC_MCS_TYPE_MCS6,                 /* EDGE Modulation Coding Scheme 6 (8PSK) */
    CI_DEV_RLC_MCS_TYPE_MCS7,                 /* EDGE Modulation Coding Scheme 7 (8PSK) */
    CI_DEV_RLC_MCS_TYPE_MCS8,                 /* EDGE Modulation Coding Scheme 8 (8PSK) */
    CI_DEV_RLC_MCS_TYPE_MCS9,                 /* EDGE Modulation Coding Scheme 9 (8PSK) */
    CI_DEV_RLC_MCS_TYPE_NOT_APPLICABLE = 255  /* The modulation and coding scheme is not applicable, e.g., in the case of UMTS */
} _CiDevRlcMcsType;

typedef UINT8 CiDevRlcMcsType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32             rlcUlDuration;
    UINT32             rlcUlByteCnt;
    UINT32             rlcUlBlkCnt;
    UINT32             rlcUlRetrBlkCnt;
    UINT32             rlcDlDuration;
    UINT32             rlcDlByteCnt;
    UINT32             rlcDlBlkCnt;
    UINT32             rlcDlMissingBlkCnt;
    CiDevRlcUlModeType rlcUlMode;
    CiDevRlcDlModeType rlcDlMode;
    CiDevRlcMcsType    ulCodingScheme;
    CiDevRlcMcsType    dlCodingScheme;
} CiDevGsmGprsEdgeRlcStatisticsEng_RLC;

/* RF52 - GSM RF Dedicated Set Info */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_L1_CODEC_TYPE
{
    CI_DEV_L1_CODEC_TYPE_GSM_FR = 0,          /* GSM Full Rate (13.0 kBit/s) */
    CI_DEV_L1_CODEC_TYPE_GSM_HR,              /* GSM Half Rate (5.6 kBit/s) */
    CI_DEV_L1_CODEC_TYPE_GSM_EFR,             /* GSM Enhanced Full Rate (12.2 kBit/s) */
    CI_DEV_L1_CODEC_TYPE_FR_AMR,              /* Full Rate Adaptive Multi-Rate */
    CI_DEV_L1_CODEC_TYPE_HR_AMR,              /* Half Rate Adaptive Multi-Rate */
    CI_DEV_L1_CODEC_TYPE_UMTS_AMR,            /* UMTS Adaptive Multi-Rate */
    CI_DEV_L1_CODEC_TYPE_UMTS_AMR2,           /* UMTS Adaptive Multi-Rate 2 */
    CI_DEV_L1_CODEC_TYPE_TDMA_EFR,            /* TDMA Enhanced Full Rate (7.4 kBit/s) */
    CI_DEV_L1_CODEC_TYPE_PDC_EFR,             /* PDC Enhanced Full Rate (6.7 kBit/s) */
    CI_DEV_L1_CODEC_TYPE_FR_AMR_WB,           /* Full Rate Adaptive Multi-Rate WideBand */
    CI_DEV_L1_CODEC_TYPE_UMTS_AMR_WB,         /* UMTS Adaptive Multi-Rate WideBand */
    CI_DEV_L1_CODEC_TYPE_OHR_AMR,             /* 8PSK Half Rate Adaptive Multi-Rate */
    CI_DEV_L1_CODEC_TYPE_OFR_AMR_WB,          /* 8PSK Full Rate Adaptive Multi-Rate WideBand */
    CI_DEV_L1_CODEC_TYPE_OHR_AMR_WB,          /* 8PSK Half Rate Adaptive Multi-Rate WideBand */
    CI_DEV_L1_CODEC_TYPE_NOT_APPLICABLE = 99  /* Speech codec not in use */
} _CiDevL1CodecType;

typedef UINT8 CiDevL1CodecType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16           dedArfcn;
    UINT8            Maio;
    UINT8            hsn;
    UINT8            timeslot;
    UINT8            rxLevelFull;
    UINT8            rxLevelSub;
    UINT8            rxQualFul;
    UINT8            rxQualSub;
    UINT8            ferFull;
    UINT8            ferSub;
    CiDevL1CodecType codec;
    UINT8            timingAdv;
    UINT8            powerLevel;
    UINT8            dedConfig;
    BOOL             bandInd;
} CiDevGsmSrvCellInfoEng_L1;

/* RF54 - GPRS/EDGE Link Quality Info */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 fer;
    UINT8 ber;
    UINT8 c2i;
    UINT8 iLevel;
} CiDevL1GprsPdchType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevL1GprsPdchType pdch[8];
    UINT8               cValue;
    UINT8               rxQual;
    UINT8               meanBep;
    UINT8               cvBep;
    UINT8               signalVar;
} CiDevGsmGprsEdgeLinkQualityEng_L1;


/* GS34 - UMTS/HSPA Layer 3 Downlink Message */
typedef _CiDevRrProtocolDicriminatorType _CiDevRrNasProtDiscrType;
typedef UINT8 CiDevRrNasProtDiscrType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrLogicalChannelType logicalTransportChannelType;
    UINT8                     rrcMessageType;
    UINT8                     rrcTransactionId;
    CiDevRrNasProtDiscrType   nasProtocolDiscriminator;
    UINT8                     nasMessageType;
    UINT8                     nasTransactionId;
    UINT8                     Msg[CI_DEV_ENGM_MAX_L3_WB_DL_MSG];
} CiDevWbLayer3DwnlnkMsgEng_RRC;

/* GS35 - UMTS/HSPA Layer 3 UPLINK Message */
//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrLogicalChannelType logicalTransportChannelType;
    UINT8                     rrcMessageType;
    UINT8                     rrcTransactionId;
    CiDevRrNasProtDiscrType   nasProtocolDiscriminator;
    UINT8                     nasMessageType;
    UINT8                     nasTransactionId;
    UINT8                     Msg[CI_DEV_ENGM_MAX_L3_WB_UL_MSG];
} CiDevWbLayer3UplnkMsgEng_RRC;

/* GS67 - RRC State */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_RR_RRC_STATE_TYPE
{
    CI_DEV_RRC_STATE_TYPE_IDLE = 0,   /* IDLE */
    CI_DEV_RRC_STATE_TYPE_URA_PCH,    /* URA_PCH */
    CI_DEV_RRC_STATE_TYPE_CELL_PCH,   /* CELL_PCH */
    CI_DEV_RRC_STATE_TYPE_CELL_FACH,  /* CELL_FACH */
    CI_DEV_RRC_STATE_TYPE_CELL_DC     /* CELL_DCH */
} _CiDevRrRrcStateType;

typedef UINT8 CiDevRrRrcStateType;

//ICAT EXPORTED STRUCT
typedef struct
{
    CiDevRrRrcStateType rrcState;
} CiDevWbRrcStateEng_RRC;

/* GS6F - Compress Mode State */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 tgpsId;
    UINT8 tgpsStatus;
} CiDevRrCmInfoType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8             numCmInfo;
    CiDevRrCmInfoType cmInfo[CI_DEV_ENGM_MAX_COMPRESS_MODE_CELL];
} CiDevWbCompressModeStateEng_RRC;

/* RF61 - UMTS/HSPA Active and Monitored Set Info */
typedef CiDevRrInterRatMeasType CiDevRrCellsListType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                numActive;
    UINT8                numMonitored;
    UINT8                numDetected;
    CiDevRrCellsListType cells[CI_DEV_ENGM_MAX_WB_INTRA_MEAS_CELL + CI_DEV_ENGM_MAX_WB_INTER_MEAS_CELL];
} CiDevWbActiveAndMonitoredSetInfoEng_RRC;

/* RF62 - UMTS/HSPA Inter RAT Neighbor Measurements */
typedef CiDevRrGsmNcellMeasType CiDevRrNeighMeasCellsListType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                         numMeas;
    BOOL                          bandInd;
    CiDevRrNeighMeasCellsListType measCells[32];
} CiDevWbInterRatNeighborMeasEng_RRC;

/* RF60 - UMTS/HSPA RF Info */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 Uarfcn;
    UINT16 scellScramblingCode;
    UINT8  scellRssi;
    UINT8  scellEcN0;
    UINT8  scellRscp;
    UINT8  txPower;
} CiDevWBRfInfoEng_RRC;

/* GS6D - Multi-RAB State */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32 contextId;      /* The identity of PDP context associated with the referenced PS radio bearer */
    UINT8  rabId;          /* The identity of the PS radio access bearer (RAB) to which this structure pertains */
    UINT8  nsapi;          /* The NSAPI associated with the referenced PS RAB */
    UINT8  radioBearerId;  /* The identity of radio bearer currently associated with the referenced PS RAB */
} CiDevRlcPsRbInfoType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 rabId;          /* The identity of the PS radio access bearer (RAB) to which this structure pertains */
    UINT8 radioBearerId;  /* The identity of radio bearer currently associated with the referenced CS RAB */
} CiDevRlcCsRbInfoType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8 radioBearerId;  /* The identity of the signaling radio bearer */
} CiDevRlcSrbInfoType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                numPsRb;  /* The number of PS RBs and PDP context IDs about which this metric contains information */
    UINT8                numCsRb;  /* The number of CS RBs about which this metric contains information */
    UINT8                numSrb;   /* The number of SRBs about which this metric contains information */
	CiDevRlcPsRbInfoType	psRbInfo[CI_DEV_ENGM_URLC_MAX_NUM_PS_RBS];	/* An array of structures of type CiRlcPsRbInfoType */
	CiDevRlcCsRbInfoType	csRbInfo[CI_DEV_ENGM_URLC_MAX_NUM_CS_RBS];	/* An array of structures of type CiRlcCsRbInfoType */
	CiDevRlcSrbInfoType		srbRbInfo[CI_DEV_ENGM_URLC_MAX_NUM_SRBS];	/* An array of structures of type CiRlcSrbInfoType */
} CiDevWBMultiRabStateEng_RLC;

/* GS84 - UMTS/HSPA RLC Statistics */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8              userRBId;       /* The ID of the user radio bearer to which this structure pertains */
    CiDevRlcUlModeType rlcMode;        /* The RLC mode of operation for this radio bearer this metric pertains in milliseconds */
    UINT32             rlcByteCnt;     /* Number of new RLC data (payload) bytes received (UL) or transmitted (DL) on this radio bearer */
    UINT32             rlcBlkCnt;      /* Number of new RLC PDUs received or transmitted on this radio bearer */
    UINT32             rlcRetrBlkCnt;  /* Number retransmitted PDUs (UL) or number of PDUs requested for  retransmission (DL) on this radio bearer */
} CiDevRlcUlStatsType;

typedef CiDevRlcUlStatsType CiDevRlcDlStatsType;

//ICAT EXPORTED STRUCT
typedef struct
{
	unsigned long 		rlcUlDuration;  		/* RLC uplink measurement period to which this metric pertains in milliseconds */
	unsigned long 		rlcDlDuration;  		/* RLC downlink measurement period to which this metric pertains in milliseconds */
	unsigned char 		numUlUserRB; 	  	 	/* Number of uplink user radio bearers to which this metric pertains (The deprecated name of this field was ucNumUlTrCh) */
	unsigned char 		numDlUserRB;    	 	/* Number of user radio bearers to which this metric pertains (The deprecated name of this field was ucNumDlTrCh) */
    CiDevRlcUlStatsType rlcUlStats[CI_DEV_ENGM_URLC_MAX_NUM_PS_RBS];  /* An array of structure type iq_rb_rlc_stats_t whose length is numUlUserRB (The deprecated name of this field was iq_trch_rlc_stats_t) */
    CiDevRlcDlStatsType rlcDlStats[CI_DEV_ENGM_URLC_MAX_NUM_PS_RBS];  /* An array of structure type iq_rb_rlc_stats_t whose length is numDlUserRB (The deprecated name of this field was iq_trch_rlc_stats_t) */
} CiDevWBUmtsHspaRlcStatisticsEng_RLC;

/* GS86 - RLC Reset */
//ICAT EXPORTED ENUM
typedef enum UrlcEngModeResetPduTypeTag
{
	URLC_ENG_MODE_RESET_PDU				= 1,
	URLC_ENG_MODE_RESET_ACK_PDU			= 2
} UrlcEngModeResetPduType;

//ICAT EXPORTED ENUM
typedef enum UrlcEngModeDirectionTypeTag
{
	URLC_ENG_MODE_DL_DIRECTION			= 0,	/* The PDU was received by the UE */
	URLC_ENG_MODE_UL_DIRECTION			= 1		/* The PDU was transmitted by the UE */
} UrlcEngModeDirectionType;

//ICAT EXPORTED ENUM
typedef enum UrlcEngModeMaxResetTag
{
	URLC_ENG_MODE_MAX_RESET_NOT_REACHED	 = 0,	/* MaxRST has not yet been reached for this AM-RLC entity */
	URLC_ENG_MODE_MAX_RESET_REACHED		 = 1	/* MaxRST has been reached (i.e., transmission of this PDU is prohibited) All other values are reserved */
} UrlcEngModeMaxReset;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                   radioBearerId;
	UINT8					direction;		/* 0: The PDU was received by the UE
											* 1: The PDU was transmitted by the UE
											* All other values are reserved */
	UINT8					pduType; 	 	/* The type of PDU to which this metric pertains:
							 				 * 1: RESET PDU
											 * 2: RESET ACK PDU
											 * All other values are reserved
											 * NOTE: This field corresponds to PDU Type as defined in 3GPP TS 25.322/9.2.2.2 */

	UINT8					resetSeqNum; 	/* The sequence number of the reset transaction to which this metric pertains.
											  * Shall be set to 255 if the Reset sequence, Number is not available
					 						  * NOTE: This field corresponds to Reset Sequence Number as defined in 3GPP TS 25.322/9.2.2.13 */

	UINT8					maxRst;	     	/* 0: MaxRST has not yet been reached for this AM-RLC entity
											 * 1: MaxRST has been reached (i.e., transmission of this PDU is prohibited)
											 * All other values are reserved */
} CiDevWBRlcResetEng_RLC;

/* GS83 - HSUPA Statistics */
//ICAT EXPORTED STRUCT
typedef struct
{
	UINT32					txDuration;			/* Duration of measurement period in milliseconds */
	UINT32					octetCnt;			/* Total number of octets transmitted in the measurement period, including retransmissions */
	UINT16					ackBlkCnt;			/* Positive acknowledgment (ACK) block count, indicating the number of blocks transmitted
							   	    				by the UE and successfully received by the Node B */

	UINT16					nackBlkCnt;			/* Negative acknowledgment (NACK) block count, indicating the number of blocks transmitted
							     					by the UE but not successfully decoded/received by the Node B */

	UINT8					servingGrant[CI_DEV_ENGM_UMAC_ABSOLUT_GRANT_MAX_NUM_INDEX];
												/* Uplink Serving Grant contains distribution count of E-AGCH
								    				Absolute Grant Value Indexes observed during that metric reporting period */

	UINT16					servingCell; 		/* From PHY yyyy metric, HSUPA Serving Cell */


	UINT16					happyCnt;			/* The happy bit count is the number of sampled happy bits during the measurement period */


	UINT16					unhappyCnt;			/* The unhappy bit count is the number of sampled unhappy bits during the measurement period */

	UINT16					etfciSampleCnt;		/* Number of E-TFCI samples in the array ETFCI */

	UINT8					etfci[CI_DEV_ENGM_UMAC_ETFCI_RANGE_MAX_SIZE];
												/* Array of uplink E-DCH transport format combination indicator (E-TFCI)
							    					samples in the range (0..127), used to identify the transport block size on E-DCH */


	UINT16					bpskBlkCnt;			/* From PHY yyyy metric, number of transport blocks transmitted using BSPK modulation */


	UINT16					qam16BlkCnt;		/* From PHY yyyy metric, number of transport blocks transmitted using 16QAM modulation */
} CiDevWBHsupaStatisticsEng_Phy;

/* GS88 - HSDPA Evolved Statistics */
//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16 ack;
    UINT16 nack;
    UINT16 dtx;
} CiDevPhycCqiDistType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16               qpskBlkCnt;
    UINT16               qam16BlkCnt;
    UINT16               Qam64BlkCnt;
    UINT16               decodeAttemptCnt;
    UINT16               decodeValidCnt;
    UINT16               hsScchLessCnt;
    CiDevPhycCqiDistType cqiDistPrimary[31];
    UINT16               numCodesAlloc[16];
    UINT16               mimoCqiReporting;
    UINT16               trBlkSizePrSampleCnt;
    UINT16               trBlkSizeSecSampleCnt;  /* Not in use */
    UINT16               numPciAlloc[4];
    CiDevPhycCqiDistType cqiDistSecondary[31];
    UINT16               trBlkSizePrimary[100];     /* Size is max of trBlkSizePrSampleCnt */
} CiDevPhycHsDschStatsType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT32                   rcvByteCnt;
    UINT16                   hsDschCellCnt;
    CiDevPhycHsDschStatsType hsDschCelStats[2];
} CiDevWBHsdpaEvolvedStatisticsEng_Phy;

/* RF63 - UMTS/HSPA Transport Channel Info */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_PHYC_TRANSPORT_CH_TYPE
{
    CI_DEV_PHYC_TR_CH_TYPE_DL_DCH = 0,  /* Downlink dedicated transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_UL_DCH,      /* Uplink dedicated transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_EDCH,        /* Enhanced (uplink) dedicated transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_BCH,         /* Broadcast common transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_FACH,        /* Forward access common transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_PCH,         /* Paging common transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_RACH,        /* Random access common transport channel */
    CI_DEV_PHYC_TR_CH_TYPE_HSDSCH,      /* High speed downlink shared transport channel */
    CI_DEV_TR_CH_TYPE_UNKNOWN = 255     /* The transport channel type is unknown */
} _CiDevPhycTransportChType;

typedef UINT8 CiDevPhycTransportChType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                    trChId;
    CiDevPhycTransportChType trChType;
    UINT16                   numTrBlocks;
    UINT16                   numErrTrBlocks;
} CiDevL1TransportChType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                  numTrCh;
    CiDevL1TransportChType trCh[25];
} CiDevWBUmtsHspaTransportChannelInfoEng_L1;

/* RF64 - UMTS/HSPA Radio Link Sync Status */
//ICAT EXPORTED ENUM
typedef enum CI_DEV_L1_T313_STATUS_TYPE
{
    CI_DEV_L1_T313_STATUS_STOPPED = 0,   /* The T313 timer for the RLS is stopped (the radio link has been restored) */
    CI_DEV_L1_T313_STATUS_RUNNING,       /* The T313 timer for the RLS has been started */
    CI_DEV_L1_T313_STATUS_EXPIRED,       /* The T313 timer for the RLS has expired (the radio link has failed) */
    CI_DEV_L1_T313_STATUS_UNKNOWN = 255  /* The T313 timer is status is invalid or unknown, or this field is not applicable */
} _CiDevL1T313StatusType;

typedef UINT8 CiDevL1T313StatusType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT16                ScramblingCode;
    UINT8                 tpcCombinationIndex;
    CiDevL1T313StatusType t313Status;
} CiDevL1SyncStatusType;

//ICAT EXPORTED STRUCT
typedef struct
{
    UINT8                 numRlSyncStatus;
    CiDevL1SyncStatusType RlSyncStatus[6];
} CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1;

//ICAT EXPORTED ENUM
typedef enum CIDEV_COMMON_ENGMODE_INFO_TAG
{
    CI_DEV_LT01_ERRC_MSG = 0,                                     /* E-UTRA RRC Message */
    CI_DEV_LT02_NAS_MSG,                                          /* E-UTRA NAS Message */
    CI_DEV_LT03_LTE_MSR_MSG,                                      /* E-UTRA Measurement Report */
    CI_DEV_LT04_LTE_INTER_MSR_MSG,                                /* E-UTRA Inter-RAT Measurement Report */
    CI_DEV_LT05_LTE_NEIGHBOR_LIST_MSG,                            /* E-UTRA Neighbor List */
    CI_DEV_LT06_LTE_ERRC_STATE_MSG,                               /* E-UTRA RRC State */
    CI_DEV_LT07_LTE_MAC_CONTROL_MSG,                              /* E-UTRA MAC Control State */
    CI_DEV_LT08_LTE_MAC_RACH_MSG,                                 /* E-UTRA MAC Random Access Attempt */
    CI_DEV_LT17_LTE_RLC_MSG,                                      /* E-UTRA RLC Data Transfer Report */
    CI_DEV_LT10_LTE_EPS_MSG,                                      /* E-UTRA EPS Bearer Context Status */
    CI_DEV_LT11_LTE_EPS_QOS_MSG,                                  /* E-UTRA EPS Bearer QoS */
    CI_DEV_LT12_LTE_PUSCH_STATUS_MSG,                             /* E-UTRA PUSCH Transmission Status */
    CI_DEV_LT13_LTE_RADIO_LINK_MSG,                               /* E-UTRA Radio Link Sync Status */
    CI_DEV_GS15_SM_PDP_CONTECXT_ACTIVATION,                       /* GSM/UMTS PDP Context Activation SM Message */
    CI_DEV_GS18_SM_PDP_CONTEXT_END,                               /* GSM/UMTS PDP Context End SM Message */
    CI_DEV_GS19_SM_PDP_CONTEXT_REQUEST,                           /* GSM/UMTS PDP Context Request SM Message */
    CI_DEV_GS40_MM_ATTACH_BEGIN,                                  /* GSM/UMTS Attach Begin MM Message */
    CI_DEV_GS41_MM_ATTACH_END,                                    /* GSM/UMTS Attach End MM Message */
    CI_DEV_GS42_MM_DETACH_END,                                    /* GSM/UMTS Detach Accept MM Message */
    CI_DEV_GS43_MM_ROUTING_AREA_UPDATE,                           /* GSM/UMTS Routing Area Update MM Message */
    CI_DEV_GS46_MM_NETWORK_INFO,                                  /* GSM/GPRS/UMTS Network Info MM Message */
    CI_DEV_GS47_MM_SERVICE_STATE,                                 /* GSM/GPRS/UMTS Service State MM Message */
    CI_DEV_GS6E_MM_RADIO_MODE,                                    /* GSM/GPRS/UMTS Radio Mode MM Message */
    CI_DEV_GS30_GRR_LAYER_3_DOWNLINK_MSG,                         /* GSM/GPRS/EDGE Layer 3 Downlink Message GRR Message */
    CI_DEV_GS31_GRR_LAYER_3_UPLINK_MSG,                           /* GSM/GPRS/EDGE Layer 3 Uplink Message GRR Message */
    CI_DEV_RF51_GRR_GSM_GPRS_EDGE_RF_SERVING_CELL_INFO,           /* GSM Serving Cell Info GRR Message */
    CI_DEV_RF53_GRR_NEIGHBOR_MEASUERMENT_MSG,                     /* GSM Neighbor Measurement GRR Message */
    CI_DEV_GS57_RR_CELL_CHANGE_BEGIN_MSG,                         /* GSM and WB Cell Change Begin RR Message */
    CI_DEV_GS58_RR_CELL_CHANGE_END_MSG,                           /* GSM and WB Cell Change End RR Message */
    CI_DEV_GS54_RR_HANDOVER_BEGIN_MSG,                            /* GSM and WB Handover Begin RR Message */
    CI_DEV_GS55_RR_HANDOVER_END_MSG,                              /* GSM and WB Handover End RR Message */
    CI_DEV_GS81_RLC_GPRS_EDGE_RLC_STATISTICS,                     /* GPRS/EDGE RLC Statistics RLC Message */
    CI_DEV_RF52_L1_GSM_SERVING_CELL_INFO_MSG,                     /* GSM Serving Cell Info L1 Message */
    CI_DEV_RF54_L1_GPRS_EDGE_LINK_QUALITY_MSG,                    /* GSM Gprs Edge Link Quality L1 Message */
    CI_DEV_GS34_RRC_UMTS_HSPA_LAYER3_DOWNLINK_MSG,                /* WB UMTS/HSPA Layer 3 Downlink RRC Message */
    CI_DEV_GS35_RRC_UMTS_HSPA_LAYER3_UPLINK_MSG,                  /* WB UMTS/HSPA Layer 3 Uplink RRC Message */
    CI_DEV_GS67_RRC_STATE_MSG,                                    /* WB RRC State RRC Message */
    CI_DEV_GS6F_RRC_COMPRESS_MODE_STATE_MSG,                      /* WB CompressModeState RRC Message */
    CI_DEV_RF61_RRC_UMTS_HSPA_ACTIVE_AND_MONITORED_SET_INFO_MSG,  /* WB UMTS/HSPA Active and Monitored Set Info RRC Message */
    CI_DEV_RF62_RRC_INTER_NEIGHBOR_MEAS_MSG,                      /* WB Inter Neighbor Measurement RRC Message */
    CI_DEV_RF60_RRC_RF_SERVING_CELL_INFO_MSG,                     /* WB RF and Serving Cell Info RRC Message */
    CI_DEV_GS6D_RLC_WB_MULTI_RAB_STATE_MSG,                       /* WB Multi-RAB State RLC Message */
    CI_DEV_GS84_RLC_UMTS_HSPA_RLC_STATISTICS_MSG,                 /* WB UMTS/HSPA RLC Statistics RLC Message */
    CI_DEV_GS86_RLC_RESET_MSG,                                    /* WB RLC Reset RLC Message */
    CI_DEV_GS83_PHY_HSUPA_STATISTICS_MSG,                         /* WB HSUPA Statistics PHY Message */
    CI_DEV_GS88_PHY_HSDPA_EVOLVED_STATISTIC_MSG,                  /* WB HSDPA Evolved Statistics PHY Message */
    CI_DEV_RF63_L1_UMTS_HSPA_TRANSPORT_CHANNEL_INFO_MSG,          /* WB UMTS/HSPA Transport Channel Info L1 Message */
    CI_DEV_RF64_L1_UMTS_HSPA_RADIO_LINK_SYNC_STATUS_MSG,          /* WB UMTS/HSPA Radio Link Sync Status L1 Message */

    /* This must be the last entry */
    CI_DEV_NUM_INFO_TYPES
} _CiDevCommonEngmodeInfoType;

typedef UINT8 CiDevCommonEngmodeInfoType;

//ICAT EXPORTED UNION : _CiDevCommonEngmodeInfoType
typedef union CiDevCommonEngmodeInfo_struct
{
    CiDevLteEng_RRC                           LT01;  /* E-UTRA RRC Message */
    CiDevLteEng_NAS                           LT02;  /* E-UTRA NAS Message */
    CiDevLteEng_MSR                           LT03;  /* E-UTRA Measurement Report */
    CiDevLteEng_InterMsr                      LT04;  /* E-UTRA Inter-RAT Measurement Report */
    CiDevLteEng_NeighborList                  LT05;  /* E-UTRA Neighbor List */
    CiDevLteEng_RrcState                      LT06;  /* E-UTRA RRC State */
    CiDevLteEng_MAC                           LT07;  /* E-UTRA MAC Control State */
    CiDevLteEng_MAC_RACH                      LT08;  /* E-UTRA MAC Random Access Attempt */
    CiDevLteEng_RLC                           LT17;  /* E-UTRA RLC Data Transfer Report */
    CiDevLteEng_EPS                           LT10;  /* E-UTRA EPS Bearer Context Status */
    CiDevLteEng_EPS_QoS                       LT11;  /* E-UTRA EPS Bearer QoS */
    CiDevLteEng_PUSCH                         LT12;  /* E-UTRA PUSCH Transmission Status */
    CiDevLteEng_RadioLink                     LT13;  /* E-UTRA Radio Link Sync Status */
    CiDevGsmUmtsComnPdpCActEng_SM             GS15;  /* PDP Context Activation GSM/UMTS PDP Context Activation SM Message */
    CiDevGsmUmtsComnPdpCEndEng_SM             GS18;  /* PDP Context End GSM/UMTS PDP Context End SM Message */
    CiDevGsmUmtsComnPdpCReqEng_SM             GS19;  /* PDP Context Request GSM/UMTS PDP Context Request SM Message */
    CiDevGsmUmtsComnAttachBeginEng_MM         GS40;  /* Attach Begin GSM/UMTS Attach Begin MM Message */
    CiDevGsmUmtsComnAttachEndEng_MM           GS41;  /* Attach End GSM/UMTS Attach End MM Message */
    CiDevGsmUmtsComnDetachAcceptEng_MM        GS42;  /* Detach Accept GSM/UMTS Detach Accept MM Message */
    CiDevGsmUmtsComnRAUEng_MM                 GS43;  /* Routing Area Update GSM/UMTS Routing Area Update MM Message */
    CiDevGsmUmtsComnNetInfoEng_MM             GS46;  /* GSM/GPRS/UMTS Network Info GSM/GPRS/UMTS Network Info MM Message */
    CiDevGsmUmtsComnServcStateEng_MM          GS47;  /* Service State GSM/GPRS/UMTS Service State MM Message */
    CiDevGsmUmtsComnRadioModeEng_MM           GS6E;  /* Radio Mode GSM/GPRS/UMTS Radio Mode MM Message */
    CiDevGsmLayer3DwnlnkMsgEng_GRR            GS30;  /* GSM/GPRS/EDGE Layer 3 Downlink Message GSM/GPRS/EDGE Layer 3 Downlink Message GRR Message */
    CiDevGsmLayer3UplnkMsgEng_GRR             GS31;  /* GSM/GPRS/EDGE Layer 3 Uplink Message GSM/GPRS/EDGE Layer 3 Uplink Message GRR Message */
    CiDevGsmRfServingCellInfoEng_GRR          RF51;  /* GSM /GPRS/EDGE RF Serving Cell Info GSM Serving Cell Info GRR Message */
    CiDevGsmNeighbrMeasEng_GRR                RF53;  /* GSM Neighbor Measurements GSM Neighbor Measurement GRR Message */
    CiDevGsmWbCellChngBginEng_RR              GS57;  /* Cell Change Begin GSM and WB Cell Change Begin RR Message */
    CiDevGsmWbCellChngEndEng_RR               GS58;  /* Cell Change End GSM and WB Cell Change End RR Message */
    CiDevGsmWbHandoverBgnEng_RR               GS54;  /* Handover Begin GSM and WB Handover Begin RR Message */
    CiDevGsmWbHandoverEndEng_RR               GS55;  /* Handover End GSM and WB Handover End RR Message */
    CiDevGsmGprsEdgeRlcStatisticsEng_RLC      GS81;  /* GPRS/EDGE RLC Statistics GPRS/EDGE RLC Statistics RLC Message */
    CiDevGsmSrvCellInfoEng_L1                 RF52;  /* GSM RF Dedicated Set Info GSM Serving Cell Info L1 Message */
    CiDevGsmGprsEdgeLinkQualityEng_L1         RF54;  /* GPRS/EDGE Link Quality Info GSM Gprs Edge Link Quality L1 Message */
    CiDevWbLayer3DwnlnkMsgEng_RRC             GS34;  /* UMTS/HSPA Layer 3 Downlink Message WB UMTS/HSPA Layer 3 Downlink RRC Message */
    CiDevWbLayer3UplnkMsgEng_RRC              GS35;  /* UMTS/HSPA Layer 3 UPLINK Message WB UMTS/HSPA Layer 3 Uplink RRC Message */
    CiDevWbRrcStateEng_RRC                    GS67;  /* RRC State WB RRC State RRC Message */
    CiDevWbCompressModeStateEng_RRC           GS6F;  /* Compress Mode State WB CompressModeState RRC Message */
    CiDevWbActiveAndMonitoredSetInfoEng_RRC   RF61;  /* UMTS/HSPA Active and Monitored Set Info WB UMTS/HSPA Active and Monitored Set Info RRC Message */
    CiDevWbInterRatNeighborMeasEng_RRC        RF62;  /* UMTS/HSPA Inter RAT Neighbor Measurements WB Inter Neighbor Measurement RRC Message */
    CiDevWBRfInfoEng_RRC                      RF60;  /* UMTS/HSPA RF Info WB RF and Serving Cell Info RRC Message */
    CiDevWBMultiRabStateEng_RLC               GS6D;  /* Multi-RAB State WB Multi-RAB State RLC Message */
    CiDevWBUmtsHspaRlcStatisticsEng_RLC       GS84;  /* UMTS/HSPA RLC Statistics WB UMTS/HSPA RLC Statistics RLC Message */
    CiDevWBRlcResetEng_RLC                    GS86;  /* RLC Reset WB RLC Reset RLC Message */
    CiDevWBHsupaStatisticsEng_Phy             GS83;  /* HSUPA Statistics WB HSUPA Statistics PHY Message */
    CiDevWBHsdpaEvolvedStatisticsEng_Phy      GS88;  /* HSDPA Evolved Statistics WB HSDPA Evolved Statistics PHY Message */
    CiDevWBUmtsHspaTransportChannelInfoEng_L1 RF63;  /* UMTS/HSPA Transport Channel Info WB UMTS/HSPA Transport Channel Info L1 Message */
    CiDevWBUmtsHspaRadioLinkSyncStatusEng_L1  RF64;  /* UMTS/HSPA Radio Link Sync Status WB UMTS/HSPA Radio Link Sync Status L1 Message */
} CiDevCommonEngmodeInfo;

/** <paramref name="CI_DEV_PRIM_COMMON_ENGMODE_INFO_IND">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevCommonEngmodeInfoInd_struct
{
  CiDevCommonEngmodeInfoType type;
  CiDevCommonEngmodeInfo     info;
} CiDevCommonEngmodeInfoInd;
 
//ICAT EXPORTED STRUCT
typedef struct CiDevCommonEngmodeDB_struct
{
    CiDevLteEng_RRC          LT01;  /* E-UTRA RRC Message */
    CiDevLteEng_NAS          LT02;  /* E-UTRA NAS Message */
    CiDevLteEng_MSR          LT03;  /* E-UTRA Measurement Report */
    CiDevLteEng_InterMsr     LT04;  /* E-UTRA Inter-RAT Measurement Report */
    CiDevLteEng_NeighborList LT05;  /* E-UTRA Neighbor List */
    CiDevLteEng_RrcState     LT06;  /* E-UTRA RRC State */
    CiDevLteEng_MAC          LT07;  /* E-UTRA MAC Control State */
    CiDevLteEng_MAC_RACH     LT08;  /* E-UTRA MAC Random Access Attempt */
    CiDevLteEng_RLC          LT17;  /* E-UTRA RLC Data Transfer Report */
    CiDevLteEng_EPS          LT10;  /* E-UTRA EPS Bearer Context Status */
    CiDevLteEng_EPS_QoS      LT11;  /* E-UTRA EPS Bearer QoS */
    CiDevLteEng_PUSCH        LT12;  /* E-UTRA PUSCH Transmission Status */
    CiDevLteEng_RadioLink    LT13;  /* E-UTRA Radio Link Sync Status */
} CiDevCommonEngmodeDB;

/** \brief Engineering mode: Reporting option type */
/** \remarks Common Data Section */
//ICAT EXPORTED ENUM
typedef enum CIDEV_EXT_ENGMODE_REPORTOPTION_TAG
{
    CI_DEV_EM_OPTION_TURN_OFF,  /**< Engineering mode report delivery: Turn off */
    CI_DEV_EM_OPTION_START      /**< Engineering mode report delivery: Turn On */
} _CiDevExtEngModeReportOption;

/** \addtogroup  SpecificSGRelated
 * @{ */
/**  \brief Engineering mode: reporting option type
 * \sa CIDEV_ENGMODE_REPORTOPTION_TAG */
/** \remarks Common Data Section */
typedef UINT8 CiDevExtEngModeReportOption;

/**@}*/
/** <paramref name="CI_DEV_PRIM_SET_EXT_ENGMODE_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetExtEngmodeRepOptReq_struct
{
    CiDevExtEngModeReportOption reportOption;  /* Start / Stop Eng Info report */
    UINT32                   reporting[2];
} CiDevPrimSetExtEngmodeRepOptReq;

/** <paramref name="CI_DEV_PRIM_SET_EXTENGMODE_REPORT_OPTION_CNF">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimSetExtEngmodeRepOptCnf_struct
{
    CiDevRc rc;			/**< Result code \sa  CiDevRc */
    UINT8   res1U8[2];
} CiDevPrimSetExtEngmodeRepOptCnf;

/** <paramref name="CI_DEV_PRIM_GET_EXT_ENGMODE_INFO_REQ">   */
typedef CiEmptyPrim CiDevPrimGetExtEngmodeInfoReq;

/** <paramref name="CI_DEV_PRIM_GET_EXT_ENGMODE_REPORT_OPTION_REQ">   */
//ICAT EXPORTED STRUCT
typedef struct CiDevPrimGetExtEngmodeInfoCnf_struct
{
    CiDevRc rc;			/**< Result code \sa  CiDevRc */
} CiDevPrimGetExtEngmodeInfoCnf;



#endif  /* _CI_DEV_ENGM_H_ */

