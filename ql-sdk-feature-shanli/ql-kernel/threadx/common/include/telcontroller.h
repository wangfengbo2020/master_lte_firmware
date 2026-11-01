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
*  Filename: telcontroller.h
*
*  Authors:  Vincent Yeung
*
*  Description: Telephony Controller Implementation for AT Command Server
*
*  History:
*   May 19, 2006 - Creation of file
*
*  Notes:
*
******************************************************************************/

#ifndef TELCONTROLLER_H
#define TELCONTROLLER_H

#include "telatci.h"
#include "utlAtParser.h"
#include "osa.h"


typedef struct _ATStubMsg
{
	UINT8  sATPInd;
	UINT32 length;
	char *data;
} ATParserMsg, *PATParserMsg;

typedef struct _ATRespMsg
{
	UINT32		msgId;
	void*		pparm;
	UINT32		length;

}ATRespMsg, ATIndMsg, *PATRespMsg,*PATIndMsg;

BOOL tcInit( char * ext_serial_path, char* modem_serial_path);
int tcWriteParser(TelAtParserID sAtpIndex, char * string, int len);


utlReturnCode_T atParserShellSetFunction(const utlAtParameterOp_T        op,
                                    const char                      *command_name_p,
                                    const utlAtParameterValue_P2c   parameter_values_p,
                                    const size_t                    num_parameters,
                                    const char                      *info_text_p,
                                    unsigned int                    *xid_p,
                                    void                            *arg_p);

utlReturnCode_T atParserShellGetFunction(const utlAtParameterOp_T        op,
                                    const char                      *command_name_p,
                                    const utlAtParameterValue_P2c   parameter_values_p,
                                    const size_t                    num_parameters,
                                    const char                      *info_text_p,
                                    unsigned int                    *xid_p,
                                    void                            *arg_p);

utlReturnCode_T ciAT(            const utlAtParameterOp_T        op,					
		const char                      *command_name_p,		
		const utlAtParameterValue_P2c   parameter_values_p,  
		const size_t                    num_parameters,		
		const char                      *info_text_p,       	
		unsigned int                    *xid_p,               		
		void                            *arg_p);

//int getFd(TelAtParserID sAtpIndex);
//OSAMsgQRef getMsgQ(TelAtParserID sAtpIndex);

int tcWriteParser(TelAtParserID sAtpIndex, char * string, int len);
int tcWriteParserForInd(TelAtParserID sAtpIndex, char * string, int len);

BOOL tcCreateMSGQ(OSMsgQRef* msgRef, UINT8 sATPIndex);
void ProcessAtChanThread(void *ptr);
int Switch_Modem_State(void);

#ifdef LWIP_IPNETBUF_SUPPORT
#ifdef VOLTE_ENABLE

//proxied commands/indications list
typedef struct utlAtProxyCommand_S{
	char* commandName; // the command name
	unsigned char	operation;		//The commands operations that can be proxied (SET-bit 3, GET-bit 2, TEST bit 5 - starting from bit 0)
	struct utlAtProxyCommand_S *next_p;
	struct utlAtProxyCommand_S *prev_p;
}utlAtProxyCommand_T,*utlAtProxyCommand_P;
unsigned int utlIsProxyReq(const char *cmdName, utlAtParameterOp_T cmdOp, unsigned int parserId);

unsigned int utlIsProxyInd(const char *indName,unsigned int parserId);

unsigned int utlIsReqForMasterCard(unsigned int parserId);

void utlIncProxyTimeoutCounter(unsigned int incValue,int parserId);

unsigned int utlIsProxySmsTrs(const char *cmdName);
#endif
#endif

 /***********************************************************************
 *
 * Name:		ATRecv
 *
 * Description: receive AT command and put them into queue
 *
 * Parameters:
 *	int		AtpIndex		 [IN]	channle index
 *	void				*data		 [IN]	at command data
 *	UINT32			length		 [IN]	he length of AT command
 *
 * Returns:
 *			TRUE: success
 *
 * Notes:
 *
 ***********************************************************************/
void ATRecv(int AtpIndex, void* data, UINT32 length);
 /***********************************************************************
 *
 * Name:		openAtChannel
 *
 * Description: open an at channel to process at commands
 *
 * Parameters:
 *	TelAtParserID		channel		 [IN]	channle index
 *
 * Returns:
 *			TRUE: success
 *
 * Notes:
 *
 ***********************************************************************/
BOOL openAtChannel(TelAtParserID channel);


BOOL IsValidChannel(TelAtParserID sAtpIndex,AT_CHANNEL_TYPE type);
BOOL IsValidAGPSChannel(TelAtParserID sAtpIndex);
UINT8 getSimIdFromChnlId(TelAtParserID chnlID,AT_CHANNEL_TYPE type);
UINT8 converChannelIdToIndex(TelAtParserID chnlID,AT_CHANNEL_TYPE type);

//fix build warnning
void at_send_recurse(utlAtParser_P parse_p);
#ifdef LWIP_IPNETBUF_SUPPORT
bool is_verbose_response(int atp_index);
#endif
#ifdef CSD_SUPPORT
bool is_report_localrate(int atp_index);
bool is_include_connect_text(int atp_index);
#endif
#endif

/* END OF FILE */
