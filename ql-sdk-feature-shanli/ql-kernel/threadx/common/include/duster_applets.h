/* -*- linux-c -*- */
/*******************************************************************************
*               Copyright 2009, Marvell Technology Group Ltd.
*
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL. NO RIGHTS ARE GRANTED
* HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT OF MARVELL OR ANY THIRD
* PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE DISCRETION TO REQUEST THAT THIS
* CODE BE IMMEDIATELY RETURNED TO MARVELL. THIS CODE IS PROVIDED "AS IS".
* MARVELL MAKES NO WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS
* ACCURACY, COMPLETENESS OR PERFORMANCE. MARVELL COMPRISES MARVELL TECHNOLOGY
* GROUP LTD. (MTGL) AND ITS SUBSIDIARIES, MARVELL INTERNATIONAL LTD. (MIL),
* MARVELL TECHNOLOGY, INC. (MTI), MARVELL SEMICONDUCTOR, INC. (MSI), MARVELL
* ASIA PTE LTD. (MAPL), MARVELL JAPAN K.K. (MJKK), GALILEO TECHNOLOGY LTD. (GTL)
* GALILEO TECHNOLOGY, INC. (GTI) AND RADLAN Computer Communications, LTD.
********************************************************************************
*/
#ifndef __APPLETS_H__
#define __APPLETS_H__

#include "osa.h"
#include "UART.h"
#include <duster.h>
//#include "common_print.h"
//#include "MrvXML.h"
//#include "csw_mrv_mem.h"

//#define DUSTER_DEBUG
#define module_maxnum 36

/*
#ifdef  DUSTER_DEBUG
#define duster_Printf	CPUartLogPrintf
#define duster_Long_Printf	LPUartLogPrintf
#else
#define duster_Printf
#define duster_Long_Printf
#endif
*/
#define duster_free(p) free(p)
#define duster_malloc(p) malloc(p)

#ifdef MRVL_USE_POOL_MEM
#define sms_malloc(Size) DusterMalloc((Size))
#define sms_free(p) DusterFree(p)
#else
#define sms_malloc(Size) malloc((Size))
#define sms_free(p) free(p)
#endif


#define DUSTER_LOG_DEBUG 3
#define DUSTER_LOG_CRITIC 2
#define DUSTER_LOG_ERROR 1

#ifdef LTEONLY_THIN
#define	DUSTER_LOG_LEVEL 2
#else
#define DUSTER_LOG_LEVEL 3
#endif

#define Duster_module_Printf CPUartLogPrintf

#define duster_Printf(fmt,args...) \
    { if (DUSTER_LOG_LEVEL >= DUSTER_LOG_DEBUG) CPUartLogPrintf(fmt, ##args);}
#define duster_Long_Printf(fmt,args...) \
    { if (DUSTER_LOG_LEVEL >= DUSTER_LOG_DEBUG) CPUartLogPrintf(fmt, ##args);}

#define DUSTER_ASSERT(fmt) do{if(!(fmt)){CPUartLogPrintf("ASSERT at file %s, line %d",__FILE__,__LINE__);ASSERT(0);}}while(0)
#define duster_log(fmt,args...)	\
    { if (DUSTER_LOG_LEVEL >= DUSTER_LOG_DEBUG) CPUartLogPrintf(fmt, ##args);}
#define duster_critic(fmt,args...)	\
    { if (DUSTER_LOG_LEVEL >= DUSTER_LOG_CRITIC) CPUartLogPrintf(fmt, ##args);}
#define duster_err(fmt,args...)	\
    { if (DUSTER_LOG_LEVEL >= DUSTER_LOG_ERROR) CPUartLogPrintf(fmt, ##args);}

#define DL_MAX_DLIST_FIELDS 30
#define DL_MAX_DLIST_RECORDS 30

#define DL_XML_ELEMENT_ITEM   "Item"
/* The UI expects "index" instead of "Index" */
#define DL_XML_ATTR_INDEX     "index"
#define DL_XML_ATTR_DELETE    "Delete"

typedef struct dlist_node {
	char   *dn_dlist[DL_MAX_DLIST_RECORDS][DL_MAX_DLIST_FIELDS];
	char   *dn_meta[DL_MAX_DLIST_FIELDS];
} dlist_node_t;

union dc_data {
	dlist_node_t *dc_dlist;
	char         *dc_string;
};

typedef struct duster_callback_args {
#define DUSTER_CB_ARGS_XML         1
#define DUSTER_CB_ARGS_LIST        2
#define DUSTER_CB_ARGS_STRING      3
#define DUSTER_CB_ARGS_DUMMYDUMMY  4
	short         dc_type;
	union dc_data dc_data;
	void         *dc_opaque;
	//MrvXMLElement *dc_root;
} dc_args_t;

struct applet_info {
	char   *di_modname;                      /* The name of the module, also found in the xml tags */
	int     di_version;                      /* The version no. of the module */
	int   (*di_handler_upgrades)(int);       /* Upgrades handler of the module, if the flash version
				               		  * and the di_version differ */
	int   (*di_handler_validate_func)(char *, dc_args_t *);
	int   (*di_handler_pre_set_func)(int, dc_args_t *); /*This callback will invoke before POST pramameters saved into psm*/
	char   *di_handler_pre_set_cmd; /*/ignore in this platform*/
	int   (*di_handler_post_set_func)(int, dc_args_t *); /*This callback will invoke after POST parameters saved into psm*/
	char   *di_handler_post_set_cmd;/*ignore in this platform*/
	int   (*di_handler_pre_get_func)(int, dc_args_t *);/*This callback will invoke in GET request, If save parameter into psm in this handler,the corresponding tags will change in XML for WebUI*/
	char   *di_handler_pre_get_cmd;/*ignore in this platform*/
	int   (*di_handler_post_get_func)(int, dc_args_t *);/*This callback will invoke in GET request, If save parameter into psm in this handler,the corresponding tags will NOT change in XML for WebUI*/
	char   *di_handler_post_get_cmd;/*ignore in this platform*/
	int   (*di_handler_dynamic)(int, int, dc_args_t *);  /* ignore in this platform */
	char    di_rd;                            /* Record Delimiter */
	char    di_fd;                            /* Field Delimiter */
};

/* Get the entire list of module applets */
struct applet_info *duster_get_module_applets(int *no);

#define DUSTER_CONFIG_START     1
#define DUSTER_CONFIG_STOP      2
#define DUSTER_CONFIG_SET       3
#define DUSTER_CONFIG_GET       4
#define DUSTER_CONFIG_GETLIST   5
#define DUSTER_CONFIG_SETLIST   6

#define DUSTER_CREATE_EVENT_HANDLER_FUNCNAME(event, modname, args...) \
int duster_call_module_##event##_handler(modname, ##args)

#ifdef WEBUI_SUPPORT
int duster_call_module_pre_set_handler(char *modname, int flags, dc_args_t *dca);
int duster_call_module_post_set_handler(char *modname, int flags, dc_args_t *dca);
int duster_call_module_pre_get_handler(char *modname, int flags, dc_args_t *dca);
int duster_call_module_post_get_handler(char *modname, int flags, dc_args_t *dca);
int duster_call_module_validate_handler(char *modname, char *variable_name, dc_args_t *dca);

int __duster_call_module_pre_set_handler(struct applet_info *di, int flags, dc_args_t *dca);
int __duster_call_module_post_set_handler(struct applet_info *di, int flags, dc_args_t *dca);
int __duster_call_module_pre_get_handler(struct applet_info *di, int flags, dc_args_t *dca);
int __duster_call_module_post_get_handler(struct applet_info *di, int flags, dc_args_t *dca);
int __duster_call_module_validate_handler(struct applet_info *di, char *variable_name, dc_args_t *dca);
int __duster_call_module_upgrade_handler(struct applet_info *di, int modver);
int __duster_call_module_dynamic_handler(struct applet_info *di, int getset, int flags, dc_args_t *dca);
int duster_call_module_dynamic_handler(char *modname, int getset, int flags, dc_args_t *dca);
void duster_call_module_get_delimiters(char *modname, char *fd, char *rd);
#endif

/* Duster Parser Actions */
#define DUSTER_PARSE_ACTION_SET  1
#define DUSTER_PARSE_ACTION_GET  2
#define DUSTER_PARSE_ACTION_VALIDATE  3

/* Duster Parser Flags */
#define DUSTER_PARSER_FL_PRINT     1     /* print only, dry-run */
#define DUSTER_PARSER_FL_DEFAULTS  2     /* Set variables only-if they don't exist */
#define DUSTER_PARSER_FL_RESTORE   4
#define DUSTER_PARSER_FL_SOMETHING 8
void dialer_Queue_init(void);

#ifdef WEBUI_SUPPORT
int dl_count_meta_fields(char *metaval, char delim);
int dl_get_meta_fields(char *metaval, dlist_node_t *dlist, char delim);
void dl_dlist_init(dlist_node_t *dlist);
void dl_variable_to_dlist_alloc(char *value, dlist_node_t *dlist,
			       int field_count, char field_delim, char record_delim,char *moduleName);
void dl_dlist_to_variable(char **value, dlist_node_t *dlist,
                         char field_delim, char record_delim);
void dl_free_dlist(dlist_node_t *dlist);
int duster_init(void);
void Dial_Allow_cb(char flag);
void Web_SMS_MsgQ_Reg(OSMsgQRef RegMsgQ);
void  register_module_number(unsigned int module_number);
void  calc_unread_SMS(void);
void  produceSMSList(void);
void wan_cellular_stop(void);
void wan_cellular_stop_cm(void);
void wan_cellular_start_cm(int Action, UINT32 AT_channel);
void wan_cellular_start(int Action, UINT32 AT_channel);
void wan_cellular_stop_cgregfail(void);
BOOL SelectNWMode(void);
#endif

void DHCP_register_cb(void (*callback)(UINT32));
char GetUsbMode(void);
void SetUsbMode(char mode);
void send_cgdcont(int atp_index, int cid, BOOL bootup);
int send_sim_download_profile(UINT32 at_channel);

#ifdef WEBUI_SUPPORT
extern unsigned int totalLocalSMSNum;
extern unsigned int totalSimSmsNum;
extern unsigned int UnreadSMSNum;
#endif

extern int gPsActDetail;
extern int gSysMainMode;
extern int gSysMode;

#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT
typedef struct
{
    INT16    mcc;    
	INT16    mnc;	
	
	char	*apn;
	char	*usrname;
	char	*paswd;
	char	*authtype;
	char	*iptype;    /*for IPTYPE, 0--IPV4V6, 1--IPV4, 2 -- IPV6 */
	
	void	*next;      //next param
} QUEC_APN_INFO, *QUEC_APN_INFO_P;
#endif

#endif /* ! __APPLETS_H__ */
