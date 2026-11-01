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
*  Filename: pdpdef.h
*
*  Authors:  Jin Rong
*
*  Description: Macro used for CM/Dialer/ATcmd
*
*  History:
*   Aug 6, 2018 - Creation of file
*
*  Notes:
*
******************************************************************************/

#ifndef PDP_DEF_H
#define PDP_DEF_H

#include "at_gbl_types.h"
#include "stdio.h"
#include "tftdef.h"

#define MAX_APN_INFO_LEN 99
#define PDP_AUTH_TYPE_STR_LEN 20

typedef enum {
	PDP_TYPE_SECONDARY,
	PDP_TYPE_PRIMARY
}PdpType_e;

//used by TFT module
struct TftInfoList_st{
	char bearer_id;
	PacketFilterInfo * packetinfo;
    void  *next;
};
typedef struct TftInfoList_st TftInfoList_CM;

//used by webUI module
typedef struct {
	char connection_num;
	PacketFilterInfo * packetinfo;
	void * next;
} TftInfoList_webUI;

typedef struct {
        void  *next;
        PacketFilterInfo PF;
} TftList;


typedef struct {
        int  IPAddr;
        int  PrimaryDNS;
        int  SecondaryDNS;
        int  GateWay;
        int  Mask;
} Ipv4Info;

typedef struct {
        int  IPV6Addr[4];
        int  PrimaryDNS[4];
        int  SecondaryDNS[4];
        int  GateWay[4];
        int  Mask[4];
} Ipv6Info;

typedef void (*StateChangedCb)(UINT8, INT32, void *);

typedef struct {
        unsigned int connected_tick;
        unsigned int total_connected_tick;
        UINT8  PDP_Type;                    /** 1-Primary, 0--secondary */
        UINT8  IP_Type;                     /** 0-IPV4V6; 1---IPV4; 2-IPV6 */
        UINT8  IsDefaultConnection;
        UINT8  PrimaryCID;
        UINT8  SecondaryCID;
        UINT8  QCI;
		UINT8  BearerID;
		UINT8  iptype_dialer;	/*modified by dialer 0 --Disable Auto APN; 1 -- IPV4V6; 2 -- IPV4; 3 -- IPV6*/
		UINT8  iptype_to_dialer; /*tell dialer the iptype to dial 0 --Disable Auto APN; 1 -- IPV4V6; 2 -- IPV4; 3 -- IPV6*/
        char  APN[MAX_APN_INFO_LEN + 1];
		char  LteAPN[MAX_APN_INFO_LEN + 1];
		/*added by shoujunl 131127 start*/
		char  Usr2G3G[MAX_APN_INFO_LEN + 1];
		char  PASWD2G3G[MAX_APN_INFO_LEN + 1];
		char  Authtype2G3G[PDP_AUTH_TYPE_STR_LEN];
		char  Usr4G[MAX_APN_INFO_LEN + 1];
		char  PASWD4G[MAX_APN_INFO_LEN + 1];
		char  Authtype4G[PDP_AUTH_TYPE_STR_LEN];
		/*added by shoujunl 131127 end*/
		int  redial_times;
		int  waiting_tickets;
		BOOL cidReplaced;
		UINT8 bypassFlag; /*BIT0: MBIM*/
		UINT8 pdpStatus;
		StateChangedCb onStateChanged;
} PdpInfo;

typedef struct {
        Ipv4Info *IPV4;
        Ipv6Info *IPV6;
        PacketFilterInfo *PF;
        PdpInfo Pdp_Info;
        char  ConnectionNumber;
} PdpContext;

typedef struct {
        void *next;
        PdpContext PDP;
} PdpContextList;

typedef struct _TelAtpPdpCtx
{
	BOOL queryInProcess;
	PdpContextList *head;
	PdpContextList *current;
	
}TelAtpPdpCtx;

typedef struct _TelAtpTftCtx
{
	BOOL queryInProcess;
	PacketFilterInfo *head;
	PacketFilterInfo *current;
	
}TelAtpTftCtx;


#endif


/* END OF FILE */
