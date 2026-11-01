/*--------------------------------------------------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  Filename: telcmux.h
 *
 *  Description: AT interface prototypes for cmux related AT commands
 *
 *  History:
 *  Sep 4, 2017 - Rong Jin Creation of file
 *
 *  Notes:
 *
 ******************************************************************************/
#ifndef TELCMUX_H
#define TELCMUX_H

RETURNCODE_T  moduleInfo(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miGmr(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miCmux(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAsrProperty(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

RETURNCODE_T  miIpr(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miDns(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miPowerOff(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miSocketLed(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miGmrAll(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miCcid(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetUrc(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miType(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetCon(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetAct(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFoTa(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  miSetMiniSys(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
#ifdef QUECTEL_MINIFOTA_SUPPORT

RETURNCODE_T  quec_exec_qfotadl_cmd
(
	const utlAtParameterOp_T		op, 				 /* AT cmd type 		 */
	const char					   *command_name_p, 	 /* AT cmd name 		 */
	const utlAtParameterValue_P2c	parameter_values_p,  /* AT cmd value		 */
	const size_t					num_parameters, 	 /* AT cmd number		 */
	const char					   *info_text_p,		 /* AT cmd usage string  */
	unsigned int				   *xid_p,				 /* AT cmd handle		 */
	void						   *arg_p				 /* AT cmd parser number */
);
#endif

RETURNCODE_T  miDownload(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);


RETURNCODE_T  miEnterTransport(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);

#ifndef NO_EXTEND_MY_Q_AT
RETURNCODE_T  miIpFilter(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetSvc(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetOpen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetRead(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetWrite(const utlAtParameterOp_T op, const char *command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char *info_text_p, unsigned int *xid_p, void *arg_p);
RETURNCODE_T  miNetClose(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  miNetAck(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetAccept(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miNetCreate(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFtpOpen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFtpClose(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFtpSize(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFtpGet(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miFtpPut(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miBcch(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miBand(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miTimeUpdate(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miLACID(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  miGpsPos(const utlAtParameterOp_T op, const char * command_name_p, const utlAtParameterValue_P2c parameter_values_p, const size_t num_parameters, const char * info_text_p, unsigned int * xid_p, void * arg_p);
RETURNCODE_T  miKey(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#ifdef EXTEND_APDU_SUPPORT
RETURNCODE_T  miSetInfo(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
RETURNCODE_T  miSysInfo(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miSysInfoUrc(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miCtxConfig(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miCtxActive(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miCtxDeactive(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASROpen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRClose(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRState(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRSend(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRRead(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRSendEx(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRSwTmd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRGetError(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRSde(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASRCfg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpCfg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpOpen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpClose(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpCwd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpPwd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpPut(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpGet(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpSize(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpDel(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpMkdir(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpRmdir(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpMdtm(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpRename(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpList(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpNlist(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpMlsd(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpLen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miAFtpStat(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLCfg(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLOpen(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLSend(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLRecv(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLClose(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
RETURNCODE_T  miASSLState(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#ifdef AT_TCP_KEEPALIVE
RETURNCODE_T  miTcpKeepAlive(const utlAtParameterOp_T op,const char *command_name_p,const utlAtParameterValue_P2c parameter_values_p,const size_t num_parameters,const char *info_text_p, unsigned int *xid_p,void *arg_p);
#endif
#endif
#endif

