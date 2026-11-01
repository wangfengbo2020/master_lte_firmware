#ifndef __STUB_H__
#define __STUB_H__

#include <ci_dat.h>

typedef enum
{
	PDP_PPP = 0,
	PDP_DIRECTIP = 1,
	PDP_PPP_MODEM = 2,
	CSD_RAW = 3
}SVCTYPE;

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
#ifdef UNUSEDPARAM
#undef UNUSEDPARAM
#endif
#define UNUSEDPARAM(param)

typedef enum
{       // com events
	DATA_CHAN_INIT_STATE = 0,
	DATA_CHAN_NOTREADY_STATE,
	DATA_CHAN_READY_STATE,
	DATA_CHAN_SNUMSTATES
}DATACHANSTATES;

struct datahandle_obj
{
	CiDatConnInfo m_datConnInfo;
	BOOL m_fOptimizedData;
	INT16 m_maxPduSize;
	CiDatConnType m_connType;
	UINT32 m_cid;
	DATACHANSTATES chanState;
	UINT16 m_dwCurSendPduSeqNo;
	UINT16 m_dwCurSendReqHandle;
	SVCTYPE pdptype;
	UINT32 connectionType;
	UINT32 reqHandle;
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
	UINT32 len;        //length of databuf
	UINT8 *databuf;
}GCFDATA;

#endif
