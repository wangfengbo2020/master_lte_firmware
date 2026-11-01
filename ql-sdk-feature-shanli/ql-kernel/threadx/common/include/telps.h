/******************************************************************************

*(C) Copyright 2007 Marvell International Ltd.

* All Rights Reserved

******************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 *	INTEL CONFIDENTIAL
 *	Copyright 2006 Intel Corporation All Rights Reserved.
 *	The source code contained or described herein and all documents related to the source code (“Material? are owned
 *	by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or
 *	its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of
 *	Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and
 *	treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted,
 *	transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.
 *
 *	No license under any patent, copyright, trade secret or other intellectual property right is granted to or
 *	conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement,
 *	estoppel or otherwise. Any license under such intellectual property rights must be express and approved by
 *	Intel in writing.
 *	-------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: telps.h
 *
 *  Authors:  Rovin Yu
 *
 *  Description: Macro definition for packet switched service related AT commands
 *
 *  History:
 *   Feb 18, 2008 - Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#ifndef TELPS_H
#define TELPS_H

#include "quec_cust_feature.h"

#define ATCI_PDP_ACTIVE    1
#define ATCI_PDP_INACTIVE  0
#define MAX_PORT_RANGE 65535

#ifdef QUECTEL_AT_COMMAND
extern INT32 CGATT_CGATTEX_FLAG;
#endif
#include "ci_ps.h"
#ifdef QUECTEL_PDP_CONTEXT_RETURN_FORMAT_ERROR_FIX
typedef enum 
{
	QUECTEL_PDP_TYPE_MIN = -1,
	QUECTEL_PDP_IP,
	QUECTEL_PDP_PPP,
	QUECTEL_PDP_IPV6,
	QUECTEL_PDP_IPV4V6,
	QUECTEL_PDP_TYPE_MAX
}quec_pdp_type_e_t;
extern void quec_get_pdp_type_str(char *pData,char *ch,char *result);
extern quec_pdp_type_e_t quec_get_pdp_type(char *pData);
#endif

RETURNCODE_T  ciPSRegStatus(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSetContext(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciPSAttach(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#ifdef QUECTEL_AT_COMMAND
RETURNCODE_T  ciPSAttachEX(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
RETURNCODE_T  ciPSAttachWithCause(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciPDPActivate(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciEnterData(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSetMinQOS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSetReqQOS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSetSContext(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSet3GQOS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciSet3GminQOS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciAUTHReq(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);//Michal Bukai - PAP_CHUP support (PDP Authentication)
RETURNCODE_T  ciReturnIp(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciPdpErrorReport(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciModifyContext(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGTFT(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciFastDormancy(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
/* Added by Daniel for LTE PC AT command server 20120201, begin */
RETURNCODE_T  ciSet4GQOS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGCONTRDP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGSCONTRDP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGTFTRDP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGEQOSRDP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGEREP(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCVMOD(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCEMODE(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGPADDR(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGPIAF(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciIRegStatus(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciERegStatus(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCGCLASS(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
/* Added by Daniel for LTE PC AT command server 20120201, end */
RETURNCODE_T  ciStarFDY(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciMobileData(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciPsPowerOnAutoAttach(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciPsPlusPaging(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciCGDFLT(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciCGDFAUTH(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciVZWAPNE(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);

RETURNCODE_T  ciEutranVoiceDomainPreference(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciEpsUsageSetting(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
#ifdef PLATFORM_FOR_PS_LW
RETURNCODE_T  ciSetAcl(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
#endif
RETURNCODE_T  ciSePsdc(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  ciPsPowerOnAutoAttach(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);

RETURNCODE_T  ciNotifyImsRegState(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciImsVoiceCallAvailability(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciImsSmsAvailability(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciPsSetImsSrv( const utlAtParameterOp_T op, const char  *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciPocCmd( const utlAtParameterOp_T op, const char  *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);


RETURNCODE_T  ciMmImsVoiceTermination(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciPsmConfig( const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCERDXS( const utlAtParameterOp_T op,const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters,const char *info_text_p,unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCEDRXRDP(const utlAtParameterOp_T op,const char	 *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciCCIOTOPT(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters, const char *info_text_p,unsigned int *xid_p,void *arg_p);

RETURNCODE_T  ciCSCON(const utlAtParameterOp_T op,const char  *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int	*xid_p, void *arg_p);
RETURNCODE_T  ciCIPCA(const utlAtParameterOp_T op,const char  *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciCABTSR(const utlAtParameterOp_T op,const char  *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciCABTRDP(const utlAtParameterOp_T op,const char  *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciCGAPNRC(const utlAtParameterOp_T op,const char	*command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#ifdef LWIP_IPNETBUF_SUPPORT
#ifndef NO_DIALER
RETURNCODE_T  ciSetCmContext( const utlAtParameterOp_T op, const char  *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciCmPDPActivate( const utlAtParameterOp_T op, const char  *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
#ifdef ATCMD_PDP_CONTEXT
RETURNCODE_T  ciTELCGCONT(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
RETURNCODE_T  ciNetActivate(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciNetifRef(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciNetifDns(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciNetif(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciNetifCm(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  ciStarMultiPdpSameApn(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
#ifdef PPP_ENABLE
RETURNCODE_T  ciChapAuthReq(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);//Michal Bukai - PAP_CHUP support (PDP Authentication)
#endif
RETURNCODE_T  ciMTUConfig(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  ciRegOption(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#ifndef NO_AUDIO
RETURNCODE_T  ciEcallSendMsd(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
#endif
RETURNCODE_T  ciStarReturnIp(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

bool convertBinStrToDecInt(UINT8 *binStr, UINT32 *outDec);






typedef struct CiPsPdpAddrConvert_struct
{
   UINT8   len; 									/**< Length of the address field [CI_PS_PDP_IP_V4_SIZE| CI_PS_PDP_IP_V6_SIZE] */
   UINT8   valData[CI_PS_PDP_IP_V6_SIZE];		/**< Address field */
} CiPsPdpAddr_convert; /* PDP address */

bool ConvertStrAddress2hexaddr (CiPsPdpAddr_convert *input);


#endif


