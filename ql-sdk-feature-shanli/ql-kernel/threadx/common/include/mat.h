/*----------------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------------------*/
/*                                                                      */
/*                                                                      */
/*  This file and the software in it is furnished under                 */
/*  license and may only be used or copied in accordance with the terms */
/*  of the license. The information in this file is furnished for       */
/*  informational use only, is subject to change without notice, and    */
/*  should not be construed as a commitment by Marvell Corporation.     */
/*  Marvell Corporation assumes no responsibility or liability for any  */
/*  errors or inaccuracies that may appear in this document or any      */
/*  software that may be provided in association with this document.    */
/*  Except as permitted by such license, no part of this document may   */
/*  be reproduced, stored in a retrieval system, or transmitted in any  */
/*  form or by any means without the express written consent of Marvell */
/*  Corporation.                                                        */
/*                                                                      */
/* Title: MAT module                                                    */
/*                                                                      */
/* Filename: mat.h                                                      */
/*                                                                      */
/* Author:   bchang                                                     */
/*                                                                      */
/* Project, Target, subsystem: Tavor, Arbel & Boerne RTOS, HAL          */
/*                                                                      */
/* Remarks: -                                                           */
/*                                                                      */
/* Created: 10/12/2013                                                  */
/*                                                                      */
/* Modified:                                                            */
/************************************************************************/

/************************************************************************/
#if !(defined __MAT_H__)
#define __MAT_H__

#include "global_types.h"
#include "quec_cust_feature.h"

/*---- parameter command type ----
  the type definition is generally following AT CMD string define
  AT commands are listed here.
*/
//ICAT EXPORTED ENUM
typedef enum
{
	MAT_E,
	MAT_I,
	MAT_L,
	MAT_M,
	MAT_O,
	MAT_P,
	MAT_Q,
	MAT_T,
	MAT_V,
	MAT_X,
	MAT_Z,
	MAT_ampC,
	MAT_ampD,
	MAT_ampF,
	MAT_ampS,
	MAT_ampZ,
	MAT_ampM,
	MAT_ampV,	
	MAT_CGMI,
	MAT_CGMM,
	MAT_CGMR,
	MAT_CGSN,
	MAT_CSCS,
	MAT_CIMI,
	MAT_ASTO,
	MAT_GMI,
	MAT_GMM,
	MAT_GMR,
	MAT_GSN,
	MAT_GOI,
	MAT_GCAP,
	MAT_GCI,
	MAT_IPR,
	MAT_ICF,
	MAT_IFC,
	MAT_IDSR,
	MAT_EXAMPLE,
	MAT_RawAT,
	MAT_A,
	MAT_D,
	MAT_H,
	MAT_CSTA,	
	MAT_CMOD,
	MAT_CVMOD,
	MAT_CHUP,	
	MAT_CBST,
	MAT_CVHU,
	MAT_CRLP,
	MAT_CEER,	
	MAT_CMUT,
	MAT_ECHUPVT,

	MAT_CREG,
	MAT_CIND,
	MAT_COPS,
	MAT_CPOL,
	MAT_CLCK,
	MAT_CPWD,
	MAT_CLIP,
	MAT_CLIR,
	MAT_COLP,
	MAT_COLR,
	MAT_CNAP,
	MAT_CCFC,
	MAT_CCWA,
	MAT_CHLD,
	MAT_CAOC,
	MAT_VTS,
	MAT_VTD,
	MAT_CSSN,
	MAT_CLCC,
	MAT_FCLASS,
	MAT_starCISCC,	
	MAT_dollarVTS,
	MAT_starDIALE,	
#ifdef VOLTE_ENABLE
	MAT_CIREP,
	MAT_CAVIMS,
	MAT_CASIMS,

	MAT_starCIIND,
	MAT_starIMSSRV,	
	MAT_POCCMD,	    
#endif
	MAT_CUSD,
	MAT_PEER,
	MAT_CSQ,
	MAT_starREJCUSE,
	MAT_CMUX,
#ifdef AT_FOR_GW20180208SN
	MAT_NETDMSG,
	MAT_CSQEX,
#endif
	MAT_CPAS,
	MAT_CFUN,
	MAT_starCFUN,
	#ifdef QUEC_MINI_SYSTEM_SUPPORT
	MAT_MINI_START,
	MAT_MINI_END,
	#endif
	MAT_CPIN,
	MAT_CPIN2,
	MAT_EPIN,
	MAT_CPINR,	
	MAT_starSIMDETEC,
	MAT_CPOFF,
	MAT_CTZR,
	MAT_CTZU,
	MAT_starCTZR,
	MAT_CPBS,
	MAT_CPBR,
	MAT_CPBW,
	MAT_CPBF,
	MAT_CSIM,
	MAT_CRSM,
	MAT_CGLA,
	MAT_CRLA,
	MAT_CCHO,
	MAT_CCHC,
	MAT_MSTK,
	MAT_starEUICC,
	MAT_CACM,
	MAT_CAMM,
	MAT_CCWE,
	MAT_ADMINDATA,	
	MAT_CGREG,
	MAT_starREGOPT,
	MAT_CGATT,
#ifdef QUECTEL_AT_COMMAND
	MAT_CGATTEX,
#endif
	MAT_CGACT,
	MAT_CGDATA,
	MAT_CGDCONT,
	MAT_CGDSCONT,
	MAT_CGQMIN,
	MAT_CGQREQ,
	MAT_CGEQREQ,
	MAT_CGEQMIN,
	MAT_GETIP,
	MAT_starTGSINK,
	MAT_CGSEND,
	MAT_starICSSINK,
	MAT_starAUTHReq,
	#ifdef CRANE_MCU_DONGLE
	MAT_starCHAPAUTH,
	#endif
	MAT_CMGF,
	MAT_starCMGF,
	MAT_CMSS,
	MAT_CMGS,
	MAT_CMGR,
	MAT_CMGW,
	MAT_CSCA,
	MAT_CSCB,
	MAT_CNMI,
	MAT_CGSMS,
	MAT_CMMS,
	MAT_CMGD,
	MAT_CMGL,
	MAT_CSMS,
	MAT_CPMS,
	MAT_CNMA,
	MAT_CSMP,
	MAT_CSDH,
	MAT_CSAS,
	MAT_CRES,
	MAT_CPNER,
	MAT_CGCI,
	MAT_CGOI,
	MAT_VDUMP,
	MAT_VPDUS,
	MAT_VHDL,
	MAT_VECHO,
	MAT_ATDB,
	MAT_starCCIREG,
	MAT_CPUC,
    MAT_CRC,
	MAT_CMEE,
	MAT_CDIP,
	MAT_CPLS,
	MAT_CGCMOD,
	MAT_CNUM,
	MAT_DS,
	MAT_CGTFT,
	MAT_starBAND,
	MAT_starBANDIND,
	MAT_starCLCK,
	MAT_starMEPCG,
	MAT_starENVSIM,
	MAT_starCNMA,
	MAT_starRSTMEMFULL,
	MAT_starPOWERIND,
	MAT_starFASTDORM,
	MAT_starCellLock,
	MAT_EEMOPT,
	MAT_EEMGINFO,
	MAT_ERGA,
	MAT_ERTCA,
	MAT_LPNWUL,
	MAT_LPLOCVR,
	MAT_starSYSSLEEP,
	MAT_starCam_I2C,
	MAT_starISP_REG,
	MAT_starCam_rawdump,
	MAT_starFILETEST,	
	MAT_starMRD_CDF,
	MAT_starMRD_IMEI,
	MAT_starMRD_MEP,
	MAT_starMRD_CalInfo,
	MAT_starMRD_MEPPLMN,
	MAT_starMRD_SN,
	MAT_starMRD_ITEM,
	MAT_starMRD_ADC,
	MAT_starMRD_RTPADC,
	//#ifdef AT_PRODUCTION_CMNDS
	MAT_starGSMTR,
	//#endif
	MAT_OFF,
	MAT_starCGSN,
	MAT_starMODEMTYPE,
	MAT_starHTCCTO,
	MAT_CMEMFULL,
	MAT_starEHSDPA,
	#ifdef CI_NEW_FEATURE1
	MAT_TPCN,
	MAT_FWDB,
	#endif
	MAT_starFDY,
	MAT_xorSYSINFO,
	MAT_starCPBC,
	MAT_starFDNBYPASS,
	MAT_starCSCB,
	MAT_starCBMCS,
	MAT_starNASCHK,
	MAT_CGEQOS,
	MAT_CEREG,
	MAT_CGCONTRDP,
	MAT_CGSCONTRDP,
	MAT_CGTFTRDP,
	MAT_CGEQOSRDP,
	MAT_CGEREP,
	MAT_CEMODE,
	MAT_CGPADDR,
	MAT_xorCACAP,
	MAT_CGCLASS,
	MAT_CESQ,
	MAT_BGLTEPLMN,
	MAT_STARCGDFAUTH,
	MAT_dollarMYMINISYS,
	MAT_dollarMYFOTA,
	MAT_VZWRSRP,
	MAT_VZWRSRQ,
	MAT_starCGDFLT,
#ifdef LWIP_IPNETBUF_SUPPORT
	MAT_STARNETACT,
	MAT_STARNETREF,
	MAT_STARNETDNS,
	MAT_STARNETIF,
	MAT_STARNETIFCM,
	MAT_STARMPSAPN,
#endif

	MAT_starMODEMRESET,
#ifdef AT_LABTOOL_CMNDS
	MAT_MVWFTST,
	MAT_MVWFIDRW,
	MAT_MVBTTEST,
	MAT_MVBTIDRW,
	MAT_MVFMTST,
#endif
	MAT_starVZWTESTAPP,
	MAT_VZWAPNE,
	MAT_COPN,
	MAT_starGATR,
	MAT_starGRIP,
	MAT_playMP3,
	MAT_starCGMR,
	MAT_starCOMCFG,
	MAT_starRFTEMP,
	MAT_startRFTEMPEX,
#ifdef CRANE_SOC_TEMPERATURE_SENSOR	
	MAT_starSOCTEMP,
#endif	
	MAT_TEMPTEST,
	MAT_BANSELCT,
	MAT_SYSSLEEP,
	MAT_PSSDC,
	MAT_starCGATT,
	MAT_CGPIAF,
	MAT_CIREG,
	MAT_starUSBT,
	MAT_starLTECOEX,
	MAT_LTEPOWER,
	MAT_LTETR,
	MAT_starCSQ,
	MAT_MAXPOWER,
	MAT_SIMDETEC,
	MAT_APPPIN,
	MAT_CPLMNS,
	MAT_starMOBILEDATA,
	MAT_MCCMNCCC,
	MAT_WS46,
	MAT_starCELL,
	MAT_CISRVCC,
	MAT_CEVDP,
	MAT_CEUS,
	/* add for BT SAP */
	MAT_BTSCNCT,
	MAT_BTSDISSCNCT,
	MAT_BTSTAPDU,
	MAT_BTSTATR,
	MAT_BTSCTRL,
	MAT_BTSCRSTAT,
	MAT_BTSTP,
	MAT_starWBAMR,
	MAT_CNMPSD,
	MAT_starREGMODE,
	MAT_starIMLCONFIG,
	MAT_CCLK,
	MAT_starURSLCT,
	MAT_starCBRAT,
	MAT_starSECCAP,
	MAT_starLTEBAND,
	MAT_starPSTHRESHOLD,
	MAT_CACL,
	MAT_LPECID,
	MAT_LPOTDOAABORT,
	MAT_LPOTDOAREQ,
    MAT_L1DEBUG,
	MAT_CSC,
	MAT_OPERCFG,
	MAT_starPSDC,
	MAT_CEN,
	MAT_CNEM,
	MAT_CMMIVT,
	MAT_CPSMS,
	MAT_CEDRXS,
	MAT_CEDRXRDP,
	MAT_CCIOTOPT,
	MAT_CRCES,
	MAT_CSCON,
	MAT_CIPCA,
	MAT_CABTSR,
	MAT_CABTRDP,
	MAT_CGAPNRC,
	MAT_MPBK,
	MAT_CSODCP,
	MAT_CRTDCP,
#ifdef LWIP_IPNETBUF_SUPPORT
	MAT_LOG,
	MAT_starDIALMODE,
	MAT_starAPNMODE,
	MAT_starAGDCONT,
	MAT_starAGACT,
	MAT_starLWIPCTRL,
	MAT_starNTP,
	MAT_starCGDCONT,
	MAT_starMTU,
	MAT_plusSWITCHSIM,
	MAT_plusDUALSIM,
	MAT_plusBINDSIM,
#endif
#if QUEC_DUAL_SIM_SUPPORT
#ifndef __QUECTEL_PROJECT_EG912YEM_AA__ 
	MAT_Q_QDSIM,
#endif
	MAT_Q_QDSTYPE,
	MAT_Q_QDSBIND,
	MAT_Q_QDSIMI,
	MAT_Q_QDSCCID,
	MAT_Q_QDSPIN,
	MAT_Q_QDSREG,
	MAT_Q_QDSGREG,
	MAT_Q_QDSEREG,
	MAT_Q_QDSQ,
	MAT_Q_QDSOPS,
	MAT_Q_QDSLOCK,
	MAT_Q_QDSRELEASE,
#endif
	//MAT_plusCWRITESIM,
//#ifdef BT_TEST_SUPPORT  20201214@xiaokeweng force enable as BT/WIFI could be enable/disable in SDK build
    MAT_BTTEST,
//#endif
	MAT_startECCLIST,
#ifdef QUEC_SMS_WHITE_SUPPORT
	MAT_Q_QTRUSTNUM,
	MAT_Q_QCHKTRUSTNUM,
	MAT_Q_QTNUMCTL,
#else
	MAT_TRUSTNUM,
#endif
	/* STASR1606-2810: CHKTRUSTNUM can not be shielded because the cloesd source IMS will use it for checking the trust number. */
	MAT_CHKTRUSTNUM,

	MAT_starISIMAID,
	MAT_CSSAC,
	MAT_MEDCR,
#ifdef QUECTEL_AT_COMMAND
	MAT_Q_QFOTADL,
#endif	
#ifdef CRANE_MCU_DONGLE
	MAT_STARREADVER,
	MAT_RESET,
	MAT_RSTSET,
#ifndef NO_EXTEND_MY_Q_AT
	MAT_DNS,
	MAT_dollarMYPOWEROFF,
	MAT_dollarMYSOCKETLED,
	MAT_dollarMYGMR,
	MAT_dollarMYCCID,
	MAT_dollarMYNETURC,
	MAT_dollarMYTYPE,
	MAT_dollarMYNETCON,
	MAT_dollarMYNETACT,
	MAT_dollarMYIPFILTER,
	MAT_dollarMYNETSRV,
	MAT_dollarMYNETOPEN,
	MAT_dollarMYNETREAD,
	MAT_dollarMYNETWRITE,
	MAT_dollarMYNETCLOSE,
	MAT_dollarMYNETACK,
	MAT_dollarMYNETACCEPT,
	MAT_dollarMYNETCREATE,
	MAT_dollarMYFTPOPEN,
	MAT_dollarMYFTPCLOSE,
	MAT_dollarMYFTPSIZE,
	MAT_dollarMYFTPGET,
	MAT_dollarMYFTPPUT,
	MAT_dollarMYBCCH,
	MAT_dollarMYBAND,
	MAT_dollarMYTIMEUPDATE,
	MAT_dollarMYLACID,
	MAT_dollarMYGPSPOS,
	MAT_dollarMYGETKEY,
	MAT_dollarMYSETINFO,
	MAT_dollarMYSYSINFO,
	MAT_dollarMYSYSINFOURC,
	MAT_QICSGP,
	MAT_QIACT,
	MAT_QIDEACT,
	MAT_QIOPEN,
	MAT_QICLOSE,
	MAT_QISTATE,
	MAT_QISEND,
	MAT_QIRD,
	MAT_QISENDEX,
	MAT_QISWTMD,
	MAT_QIGETERROR,
	MAT_QISDE,
	MAT_QICFG,
	MAT_QFTPCFG,
	MAT_QFTPOPEN,
	MAT_QFTPCLOSE,
	MAT_QFTPCWD,
	MAT_QFTPPWD,
	MAT_QFTPPUT,
	MAT_QFTPGET,
	MAT_QFTPSIZE,
	MAT_QFTPDEL,
	MAT_QFTPMKDIR,
	MAT_QFTPRMDIR,
	MAT_QFTPMDTM,
	MAT_QFTPRENAME,
	MAT_QFTPLIST,
	MAT_QFTPNLST,
	MAT_QFTPMLSD,
	MAT_QFTPLEN,
	MAT_QFTPSTAT,
	MAT_TCPKEEPALIVE,
#ifdef ATNET_SSL
	MAT_QSSLCFG,
	MAT_QSSLOPEN,
	MAT_QSSLSEND,
	MAT_QSSLRECV,
	MAT_QSSLCLOSE,
	MAT_QSSLSTATE,
#endif
#endif
#endif
	MAT_dollarMYDOWNLOAD,
#ifdef NEUL_COMMAND
	MAT_NSOCR,
	MAT_NSOST,
	MAT_NSORF,
	MAT_NSOCL,
	MAT_NCDP,
	MAT_NMGS,
	MAT_NMGR,
	MAT_NNMI,
	MAT_NSMI,
	MAT_NQMGR,
	MAT_NQMGS,
	MAT_NRB,
	MAT_NUESTATS,
	MAT_NEARFCN,
	MAT_NPING,
	MAT_NBAND,
	MAT_NLOGLEVEL,
	MAT_NCONFIG,
	MAT_NTSETID,
#endif

	MAT_xorHVER,
	MAT_CDU,
	MAT_starPROD,
	MAT_NVMFLUSH,
	MAT_starSLT,
	MAT_starPMICREG,
	MAT_starREGRW,
	MAT_ZDON,
	MAT_starASRCOPS,
	MAT_starICCID,
	MAT_CEN1,
	MAT_CEN2,
	MAT_starSULOGCFG,	
#ifdef ENABLE_WIFI_SCAN
	MAT_starWIFICTRL,
#endif
	MAT_starSIMPOLL,
	MAT_cellinfo,
	MAT_starEPIN,
	MAT_starVER,
//#ifdef WIFI_FUNCTION_SUPPOR 20201214@xiaokeweng force enable as BT/WIFI could be enable/disable in SDK build	
	MAT_WIFI_CMD,	
//#endif	
	MAT_Audio_CMD,
    MAT_starMRDBACKUP,
    MAT_starMRDWIFIMAC,
    MAT_starMRDBTID,
    MAT_starAUDNVM,
	MAT_starSPN,
    MAT_CMRSS,
    MAT_CMGSS,
    MAT_CMSMS,
    MAT_CMGMS,
    MAT_PACSP,  
    MAT_ENVCFG,
    MAT_CUAD,
#ifndef LTEONLY_THIN
#ifndef NO_AUDIO
    MAT_CECALL,
    MAT_ECALLDATA,
    MAT_ECALLVOICE,
    MAT_ECALLCFG,
    MAT_ECALLONLY,
    MAT_ECALLREG,
    MAT_ECALLONLYSIM,
    MAT_ECALLSYNC,
    MAT_ECALLSENDMSD,
#endif
#endif
    MAT_STARGETIP,
    MAT_CR,
	MAT_PROPERTY,
	MAT_UNKNOWN,
	MAT_CMD_UNKNOWN = MAT_UNKNOWN,

	/* response type for MAT */
	MAT_RSP_UNKNOWN = 1000,
	MAT_RSP_OK,
	MAT_RSP_ERROR,
	MAT_RSP_CME_ERROR,
	MAT_RSP_CMS_ERROR,
	MAT_RSP_BUSY,

	/* indication type for MAT */
	MAT_IND_CONNECT,
	MAT_IND_NO_CARRIER,
	MAT_IND_RING,
	MAT_IND_NO_ANSWER,
	MAT_IND_NO_DIALTONE,

	/* CC Indication */
	MAT_IND_CRING,
	MAT_IND_CCCM,
	MAT_IND_CSSU,
	MAT_IND_CSSI,
	MAT_IND_CR,
	MAT_IND_CEI,

	/* DEV Indication */
	MAT_IND_SYSCONFIG,
	MAT_IND_EEMGINFOBASIC,
	MAT_IND_EEMGINFOSVC,
	MAT_IND_EEMGINFOPS,
	MAT_IND_EEMGINFONC,
	MAT_IND_EEMGINBFTM,
	MAT_IND_EEMUMTSSVC,
	MAT_IND_EEMUMTSINTRA,
	MAT_IND_EEMUMTSINTER,
	MAT_IND_EEMUMTSINTERRAT,
	MAT_IND_EEMLTESVC,
	MAT_IND_EEMLTEINTRA,
	MAT_IND_EEMLTEINTER,
	MAT_IND_EEMLTEINTERRAT,
	MAT_IND_SNETIND,
	MAT_IND_LPNWDL,
	MAT_IND_LPSTATE,
	MAT_IND_LPMEAST,
	MAT_IND_LPRESET,
	MAT_IND_DIP,
	MAT_IND_LPOTDOAMEAS,
	/* MM Indication */
	MAT_IND_CACAP,
	MAT_IND_MODE,
	MAT_IND_COPN,
	MAT_IND_NITZ,
	MAT_IND_MSRI,
	MAT_IND_HOME_ZONE,

	/* MSG Indication */
	MAT_IND_MMSG,
	MAT_IND_CMTI,
	MAT_IND_CBM,
	MAT_IND_CDS,
	MAT_IND_CMT,

	/* PB Indication */
	MAT_IND_SCPBR,
	MAT_IND_MPBK,

	/* PS Indication */
	MAT_IND_CGEQNEG,
	MAT_IND_CGEV,

	/* SIM Indication */
	MAT_IND_COTA,
	MAT_IND_REFRESH,
	MAT_IND_SIM_RESET,
	MAT_IND_CARDMODE,
	MAT_IND_SPN,

	/* SS Indication */
	MAT_IND_LPLOC,
	MAT_IND_SSRC,

	/* DAT Indication */
	MAT_IND_PSSDC,

	/* the change of sim/usim availability status report */
	MAT_IND_BTSSTAT,

	MAT_IND_DSAC,
	MAT_IND_ADMINDATA,
	MAT_IND_CIMI,
	MAT_IND_PSLOAD,
	MAT_IND_RBLOOP,
	MAT_IND_CELL,
	MAT_IND_CIREPI,
	MAT_IND_CIREPH,
	MAT_IND_DATASTATUS,
	MAT_IND_CEDRXP,
	MAT_IND_CCIOTOPTI,
	MAT_IND_CABTSRI,
	MAT_IND_CIREGU,
	MAT_IND_AMRCODEC,
	MAT_IND_CNEC_ESM,
	MAT_IND_ATREADY,
	MAT_IND_PLMNLIST,
	MAT_IND_WIFICELLINFO,
#ifdef SINGLE_SIM
	MAT_plusSINGLESIM,
	MAT_SIMSLOT,
#endif
#ifdef QUECTEL_AT_COMMAND
    MAT_CWRITESIM,
    #if defined(__QUEC_OEM_VER_CBZ__)
    MAT_Q_QCRC,
    #endif
#if defined(__QUEC_OEM_VER_XGD__)
    MAT_Q_MRST,
#endif
	MAT_Q_QPOWD,
#ifdef YS_GNSS_SUPPORT
	MAT_Q_YSCPOF,
#endif
	MAT_Q_I,
	MAT_Q_E,
	MAT_Q_Z,
#ifndef QUECTEL_OPEN_CPU
	MAT_Q_AMP_F,
	MAT_Q_AMP_C,
	MAT_Q_AMP_D,
	MAT_Q_QPPPDROP,
	MAT_Q_QDIAGPORT,
	MAT_Q_DATAMODE,
	MAT_Q_QPDPTIMER,
	MAT_Q_QDEBOUNCE,
	MAT_Q_QSPN,
	MAT_Q_QSCLKCFG,
#endif	
	MAT_Q_IPR,
	MAT_Q_CBAUD,
	MAT_Q_IFC,
	MAT_Q_QSCLK,
#ifndef QUECTEL_OPEN_CPU
#ifdef QUEC_STARTUP_OPTIMIZATION
	MAT_Q_QSTARTUPTIME,
#endif
	#ifdef QUEC_CDMA_IMSI_SUPPORT
    MAT_Q_QCDMAIMSI,
    #endif
	MAT_Q_CMUX,
#endif/*QUECTEL_OPEN_CPU*/
	MAT_Q_QNETDEVCTL,
	MAT_Q_QDBGCFG,
#ifdef QUEC_ENGINEER_OUTPUT
	MAT_Q_QENGINFO,
#endif

	MAT_Q_EGMR,
	MAT_Q_QGMR,
#ifdef QUECTEL_AT_AP_MODEM_NEW_VERSION
	MAT_Q_QAPVER,
	MAT_Q_QSUB,
	MAT_Q_QAPSUB,
#endif
	MAT_Q_CUSTOMERAREA,
	MAT_Q_CVERSION,
	MAT_Q_CSUB,
	MAT_Q_QINF,
	MAT_Q_QURCCFG,
	MAT_Q_AMP_V,
	MAT_Q_AMP_W,
	MAT_Q_CMEE,
	MAT_Q_CFUN,
	MAT_Q_CSCS,
	MAT_Q_CGMI,
	MAT_Q_CGMM,
	MAT_Q_CGMR,
	MAT_Q_CGSN,
	MAT_Q_GSN,
	MAT_Q_QGSN,
	MAT_Q_QCCID,
	MAT_Q_CCID,
	MAT_Q_ICCID,
	MAT_Q_GMI,
	MAT_Q_GMM,
	MAT_Q_GMR,
	MAT_Q_QCFG,
	MAT_Q_QINDCFG,
	MAT_Q_QNWINFO,
	MAT_Q_CSQ,
	MAT_Q_QCSQ,
	MAT_Q_CGREG,
	MAT_Q_CEREG,
	MAT_Q_CREG,
	MAT_Q_CGEREP,
	MAT_Q_CTZR,
	MAT_Q_QENG,
	MAT_Q_QLTS,
	MAT_Q_QGDCNT,
	MAT_Q_QAUGDCNT,
	MAT_Q_QOEM,
	MAT_Q_SMONC,
	MAT_Q_QGPAPN,
	MAT_Q_QRFTESTMODE,
	MAT_Q_QRFTEST,
	MAT_Q_QRXFTM,
#ifdef QUEC_POWER_BACKOFF_SUPPORT
	MAT_Q_QPWRBACKOFF,
	MAT_Q_QGRIP,
#endif

#if defined (__QUEC_OEM_VER_NL__) || defined (__QUEC_OEM_VER_XGD__)
    MAT_Q_MCELL,
    MAT_Q_T3302,
#endif

#ifdef QUEC_G510_SOCKET_SUPPORT
    MAT_Q_IPCALL,
    MAT_Q_IPOPEN,
    MAT_Q_MIPCLOSE,
    MAT_Q_IPSETS,
    MAT_Q_MIPSEND,
    MAT_Q_MIPREAD,
    MAT_Q_MIPPUSH,
    MAT_Q_MIPFLUSH,
    MAT_Q_MIPSETS,
    MAT_Q_MIPCONF,
    MAT_Q_MIPODM,
    MAT_Q_MSDNS,
    MAT_Q_MIPDNS,
    MAT_Q_GTEST,
#else
	MAT_Q_QICSGP,
	MAT_Q_QIACT,
	MAT_Q_QIACTEX,
	MAT_Q_QIDEACT,
	MAT_Q_QIDEACTEX,
	MAT_Q_QIDNSCFG,
	MAT_Q_QIDNSGIP,
	MAT_Q_QICFG,
	MAT_Q_QIOPEN,
	MAT_Q_QIRD,
	MAT_Q_QISEND,
	MAT_Q_QISENDEX,
	MAT_Q_QISWTMD,
	MAT_Q_QISTATE,
	MAT_Q_QICLOSE,
	MAT_Q_QISDE,
	MAT_Q_QPING,
#endif
#ifdef QUECTEL_CTWing_SUPPORT
	MAT_Q_QICTWCFG,
	MAT_Q_QHTTPCTWINGAUTH,
	MAT_Q_QHTTPCTWINGURL,
	MAT_Q_QHTTPCTWINGPOST,
	MAT_Q_QCERTIFY,
#endif
	MAT_Q_QIACCEPT,
#ifdef QUEC_TCPIP_SWITCH_MULTIPLE_MODE_FEATURE
	MAT_Q_QISWCMD,
#endif
	MAT_Q_QNTP,
	MAT_Q_QIGETERROR,
#ifdef QUEC_G510_SOCKET_SUPPORT
    MAT_Q_GTSSLFILE,
    MAT_Q_GTSSLMODE,
    MAT_Q_GTSSLERR, 
    MAT_Q_GTSSLVER, 
    MAT_Q_GTCIPHER, 
    MAT_Q_GTSSLCFG, 
#else 
	MAT_Q_QSSLCFG,
	MAT_Q_QSSLOPEN,
	MAT_Q_QSSLRECV,
	MAT_Q_QSSLSEND,
	MAT_Q_QSSLCLOSE,
	MAT_Q_QSSLSTATE,
#endif
	MAT_Q_QDMCFG,
	MAT_Q_QDMCFGEX,
	MAT_Q_QDMSTART,
	MAT_Q_QDMSTOP,
	MAT_Q_QDMSTAT,
	MAT_Q_QMTCFG,
	MAT_Q_QMTOPEN,
	MAT_Q_QMTCLOSE,
	MAT_Q_QMTCONN,
	MAT_Q_QMTDISC,
	MAT_Q_QMTSUB,
	MAT_Q_QMTUNS,
	MAT_Q_QMTPUB,
	MAT_Q_QMTPUBEX,
	MAT_Q_QMTRECV,
#ifdef QUECTEL_MQTT_TRANSPARENT
    MAT_Q_QMTPUBDATA,
#endif
#ifdef QUEC_MQTT_UNIFY_SUPPORT
	MAT_Q_UNIKEYINFO,
	MAT_Q_UNIDELKEYINFO,
	MAT_Q_UNIKEYINFOM,
	MAT_Q_UNIDELKEYINFOM,
	MAT_Q_UNIMQTTCON,
	MAT_Q_UNIMQTTDISCON,
	MAT_Q_UNIMQTTSTATE,
	MAT_Q_UNIMQTTSUB,
	MAT_Q_UNIMQTTPUB,
#endif
	MAT_Q_QFTPCFG, 
	MAT_Q_QFTPOPEN,
	MAT_Q_QFTPCLOSE,
	MAT_Q_QFTPCWD, 
	MAT_Q_QFTPPWD, 
	MAT_Q_QFTPSIZE,
	MAT_Q_QFTPDEL, 
	MAT_Q_QFTPMKDIR,
	MAT_Q_QFTPRMDIR,
	MAT_Q_QFTPRENAME,
	MAT_Q_QFTPSTAT,
	MAT_Q_QFTPMDTM,
	MAT_Q_QFTPPUT, 
	MAT_Q_QFTPGET, 
	MAT_Q_QFTPLIST,
	MAT_Q_QFTPNLST,
	MAT_Q_QFTPMLSD,
	MAT_Q_QFTPLEN,
	MAT_Q_QHTTPCFG,
	MAT_Q_QHTTPURL,
	MAT_Q_QHTTPURLEX,
	MAT_Q_QHTTPGET,
	MAT_Q_QHTTPGETEX,
	MAT_Q_QHTTPPOST,
	MAT_Q_QHTTPPOSTFILE,
	MAT_Q_QHTTPPUT,
	MAT_Q_QHTTPPUTFILE,
	MAT_Q_QHTTPREAD,
	MAT_Q_QHTTPREADFILE,
	MAT_Q_QHTTPSTOP,
	MAT_Q_QLBS,
	MAT_Q_QLBSCFG,
#ifdef QUEC_HTTP_CFGEX_MULT_FILE_POST
    MAT_Q_QHTTPCFGEX,
    MAT_Q_QHTTPSEND,
#endif /*QUEC_HTTP_CFGEX_MULT_FILE_POST*/
	MAT_Q_QLBSDEBUG,
	MAT_Q_QCERT,
	MAT_Q_QSVN,
	MAT_Q_QIOTRPT,
	MAT_Q_QIOTRPTCFG,
	MAT_Q_QGPIOS,
	MAT_Q_QGPIOR,
	MAT_Q_QGPIOW,
	MAT_Q_MRDBACKUP,
	MAT_Q_QCMGR,
	MAT_Q_QCMGS,
	#if defined(__QUEC_OEM_VER_DM__)
	MAT_Q_QDMHTTPCFG,
    MAT_Q_QDMHTTPINFO,
    MAT_Q_QDMHTTPREG,
    #endif
#if QUEC_SMS_QCSMP_SUPPORT
    MAT_Q_QCSMP,
#endif
	MAT_Q_QINISTAT,
	MAT_Q_QPINC,
	MAT_Q_QSIMDET,
	MAT_Q_QSIMSTAT,
	MAT_Q_QAUDLOOP,
	MAT_Q_QAUDPLAYSPL,
#if QUEC_AUDIO_CODEC_SW_SUPPORT
	MAT_Q_QAUDSW,
#endif
#if QUEC_AT_CMD_CAMERA_SUPPORT
	MAT_Q_QCAMOPEN,
	MAT_Q_QCAMCLOSE,
	MAT_Q_QCAMIDFY,
	MAT_Q_QCAMCFG,
	MAT_Q_QGPIO,
	MAT_Q_QCAMAPPVER,
	MAT_Q_QCAMIIC,
#endif

#if defined(QUEC_CAMMERA_DECODE_AUTHORIZATION)||defined(QUEC_AUDIO_DENOISE)
#ifdef QUEC_CAMMERA_DECODE_AUTHORIZATION

	MAT_Q_QAUTHCODE,
	MAT_Q_UID,
#endif
	MAT_Q_QLICENSE,
	MAT_Q_QLICENSEINFO,

#endif
#if QUEC_AUDIO_HSDet_SUPPORT
	MAT_Q_QAUDHSDET,		
#endif
#if defined(QUEC_QPSND_SUPPORT)
	MAT_Q_QPSND,
#endif
#if defined(__QUEC_OEM_VER_NL__)
    MAT_Q_GTTS,
#else
    MAT_Q_QTTS,
#endif
#if defined(QUEC_QWTTS_SUPPORT)
	MAT_Q_QWTTS,
#endif
	MAT_Q_QAUDPLAY,
	MAT_Q_QAUDSTOP,
	MAT_Q_QAUDRD,
	MAT_Q_QSIDET,
	MAT_Q_QMIC,
	MAT_Q_CLVL,
	MAT_Q_QRXGAIN,
	MAT_Q_QAUDMUT,
#if QUEC_AUDIO_ACDB_SUPPORT
	MAT_Q_CLEVLE,
	MAT_Q_AUDUPDATE,
	MAT_Q_QEEC,
	MAT_Q_QCODECTABLE,
	MAT_Q_QEQTABLE,
	MAT_Q_QTXCODECTABLE,
	MAT_Q_QTXDSPGAIN,
	MAT_Q_QDSPTABLE,
#endif
	MAT_Q_QAUDINIT,
	MAT_Q_QAUDMOD,
	MAT_Q_QIIC,
	MAT_Q_QTTSETUP,
	MAT_Q_QTTSMODE,
	MAT_Q_QDAI,
	MAT_Q_QFLDS,
#if defined(QUEC_LDTMF_SUPPORT)
	MAT_Q_QDTMFVOL,
	MAT_Q_QLDTMF,
#endif	
#if defined(QUEC_WDTMF_SUPPORT)
	MAT_Q_QWDTMF,
#endif
#if defined(QUEC_DTMF_DETECT_SUPPORT)
	MAT_Q_QTONEDET,
#endif
#if	QUEC_LTONE_SUPPORT
	MAT_Q_QLTONE,
#endif
#ifdef QUEC_AUDIO_CFG_SUPPORT
	MAT_Q_QAUDCFG,
#endif
#if defined(__QUEC_OEM_VER_XGD__)
    MAT_Q_GTFLIST,
    MAT_Q_GTFSIZE,
    MAT_Q_GTFDELETE,
    MAT_Q_GTFOPEN,
    MAT_Q_GTFREAD,
    MAT_Q_GTFWRITE,
    MAT_Q_GTFSEEK,
#else
	MAT_Q_QFLST,
	MAT_Q_QFDEL,
	MAT_Q_QFOPEN,
	MAT_Q_QFREAD,
	MAT_Q_QFWRITE,
	MAT_Q_QFSEEK,
#endif
#ifdef QUEC_AT_FILE_CMD
	MAT_Q_QFREADDELYSET,
#endif
#ifdef QUEC_AT_GPS_ENABLE
#ifdef YS_GNSS_SUPPORT
	MAT_Q_YSGPS,
	MAT_Q_YSLBS,
	MAT_Q_YSGPSRD,
	MAT_Q_YSGPSANT,
#endif
	MAT_Q_QGPSCFG,
	MAT_Q_QGPSDEL,
	MAT_Q_QGPS,
	MAT_Q_QGPSEND,
	MAT_Q_QGPSLOC,
	MAT_Q_QGPSGNMEA,
	MAT_Q_QAGPS,
	MAT_Q_QGPSCOMMSG,
	MAT_Q_QGPSCMDSEND,
#ifdef HX_GNSS_SUPPORT
	MAT_Q_QGPSLOCGET,
	MAT_Q_QGPSSATGET,
	MAT_Q_QGPSDEBUG,
	MAT_Q_QGPSVBCKP,
#endif
	MAT_Q_QAGPSCFG,
#endif
	MAT_Q_QPTABLEVSTART,
	MAT_Q_QFPOSITION,
	MAT_Q_QFTUCAT,
#if defined(__QUEC_OEM_VER_XGD__)
    MAT_Q_GTFCLOSE,
#else
	MAT_Q_QFCLOSE,
#endif
	MAT_Q_QFUPL,
	MAT_Q_QFDWL,
	MAT_Q_QFRENAME,	
#ifdef QUEC_AT_SD_CHECK_SUPPORT
	MAT_Q_QFTCMD,
#endif
#ifdef QUEC_AT_MD5_CKECKSUM_SUPPORT
	MAT_Q_QFMD5,
#endif
	MAT_Q_QFSIZE,
	//MAT_Q_QFOTADL,
#ifdef QUEC_JIEDIAN_PROJECT
	MAT_Q_JFOTADL,
	MAT_Q_JFOTAGRD,
#endif
	MAT_Q_QDUMPCFG,
	MAT_Q_QFLASH,
	MAT_Q_QVOLCFG,
	MAT_Q_QPMICCFG,
	MAT_Q_QGPIOCFG,
	MAT_Q_QFOTAUPDATE,
	MAT_Q_QFATTEST,
	MAT_Q_QLEDSTAT,
	MAT_Q_QLEDCFG,
#if QUEC_LED_NET_MODE_COMPATIBLE_WITH_L610
	MAT_Q_QPWMCFG,
#endif
	MAT_Q_QADC,
	MAT_Q_QWSETMAC,
	MAT_Q_QTEMP,
	MAT_Q_FLASH_TEST,
	MAT_Q_FALSH_TEST,
	MAT_Q_QVSIM,
	MAT_Q_QMMSCFG,
	MAT_Q_QMMSEDIT,
	MAT_Q_QMMSEND,
#ifdef QUEC_CALL_DSCI_SUPPORT
    MAT_Q_QDSCI,
#endif
	MAT_Q_CINDCFG,
#endif
#ifdef QUEC_TCIOT_SUPPORT
	MAT_Q_TCREGNET,
	MAT_Q_TCDEVINFOSET,
	MAT_Q_TCCERTADD,
	MAT_Q_TCCERTCHECK,
	MAT_Q_TCCERTDEL,
	MAT_Q_TCPRDINFOSET,
	MAT_Q_TCMODULE,
	MAT_Q_TCDEVREG,
	MAT_Q_TCRESTORE,
	MAT_Q_TCMQTTCONN,    
	MAT_Q_TCMQTTDISCONN,
	MAT_Q_TCMQTTPUB,     
	MAT_Q_TCMQTTPUBL,    
	MAT_Q_TCMQTTPUBRAW, 
	MAT_Q_TCMQTTSUB,     
	MAT_Q_TCMQTTUNSUB,  
	MAT_Q_TCMQTTSTATE,
	MAT_Q_TCOTASET,
	MAT_Q_TCFWINFO,
	MAT_Q_TCREADFWDATA,
#endif
#ifdef QUEC_CIP_TCP_SUPPORT
	MAT_Q_CIPMUX,
	MAT_Q_CIPSTART,
	MAT_Q_CIPSEND,
	MAT_Q_CIPRXGET,
	MAT_Q_CIPCLOSE,
	MAT_Q_CIPSTATUS,
#endif
#ifdef QUECTEL_IPC_ENTERSLEEP_SUPPORT
    MAT_Q_ENTERSLEEP,
	MAT_Q_QHBSLEEP,
#endif
#if QUEC_AT_QGPIOEXT_SUPPORT
	MAT_Q_QGPIOEXT,
#endif

#if QUEC_SIM_PIN_CTRL_FUNC
	MAT_Q_QDSIM,
#endif

#if QUEC_CUSD_OPTIMIZE
    MAT_Q_QCUSDCVT,
#endif
#ifdef QUEC_USB_REMOTEWAKEUP_SUPPORT
	MAT_Q_REMOTEWAKE,
#endif
#ifdef QUEC_USB_QWIFISCAN_SUPPORT
	MAT_Q_CWLAPOPT,
	MAT_Q_CWLAP,
	MAT_Q_CWMODE,
#endif
#ifdef QUECTEL_CELL_SELECT_CFG
    MAT_Q_QCELLSELECTCFG,
#endif
#ifdef QUECT_ALIOT_FEATURE_SUPPORT
    MAT_Q_QALCFG,
    MAT_Q_QALIOTBS,
    MAT_Q_QALIOTREG,
    MAT_Q_QALIOTCLOSE,
    MAT_Q_QALIOTCONN,
    MAT_Q_QALIOTDISC,
    MAT_Q_QALIOTSUB,
    MAT_Q_QALIOTUNSUB,
    MAT_Q_QALIOTPUB,
    MAT_Q_QALIOTRECV,
#endif
#ifdef QUECTEL_SIM_POLL_CFG
        MAT_Q_SIMPOLLCFG,
#endif
#ifdef QUECTEL_CELL
   MAT_Q_CELL,
   MAT_Q_CELLEX,
#endif
#ifdef QUEC_SMTP_SUPPORT
   MAT_Q_QSMTPCFG,
   MAT_Q_QSMTPPUT,
   MAT_Q_QSMTPSUB,
   MAT_Q_QSMTPDST,
   MAT_Q_QSMTPBODY,
   MAT_Q_QSMTPATT,
   MAT_Q_QSMTPCLR,
#endif
#ifdef QUEC_IPV6_CONFIG
	MAT_Q_QIPV6CONFIG,
#endif
#ifdef QUEC_AT_FLASH_ERASE_COUNT_CMD
	MAT_Q_QERASECOUNT,
#endif
#ifdef QUEC_TCPIP_SEND_DIRECT_PUSH_DATA_FEATURE
	MAT_Q_QISENDX,
#endif
#ifdef QUEC_TCPIP_SENDCRC_SUPPORT
    MAT_Q_QISENDCRC,
#endif
#ifdef QUEC_STAR_CHARGE_CUSTOM_WANBANGDH_FEATURE
	MAT_Q_XXCD_TCPINIT,
	MAT_Q_XXCD_GETIP,
	MAT_Q_XXCD_SETIP,
	MAT_Q_XXCD_TCPSEND,
	MAT_Q_XXCD_TCPCLOSE,
	MAT_Q_XXCD_FTPINIT,
	MAT_Q_XXCD_FTPOPEN,
	MAT_Q_XXCD_FTPSIZE,
	MAT_Q_XXCD_FTPPUT,
	MAT_Q_XXCD_FTPGET,
	MAT_Q_XXCD_FTPCLOSE,
#endif
#ifdef QUEC_RSRP_SUPPORT
    MAT_Q_RSRP,
#endif
#ifdef QUECTEL_JAMDET_FEATURE
    MAT_Q_JAMDET_ENABLE,
    MAT_Q_JAMDET_CFG,
#endif
#ifdef QUEC_PRODUCTION_CFG_SUPPORT
        MAT_Q_SAWCFG,
#endif
#if defined(__QUEC_OEM_VER_LT__)
    MAT_Q_AVGRSSI,
    MAT_Q_QNWSCAN,
#endif
#ifdef QUECTEL_QUECFOTA_SUPPORT
	MAT_Q_QFOTACFG,
	MAT_Q_QFOTAUP,
#endif
#ifdef QUEC_CUSTOM_LAST_GASP_FEATURE
	MAT_Q_QLGGASPCFG,
	MAT_Q_QLGGASP,
#endif
#ifdef QUEC_ASR_ATCMD_PAGING_UPDATE_SUPPORT
    MAT_Q_QPAGUPDATE,
#endif
#ifdef QUEC_QCELLINFO_SUPPORT
    MAT_Q_QCELLINFOEX,
    MAT_Q_QCELLINFO,
#endif
#ifdef BT_SUPPORT
	MAT_Q_EBTADDR,
	MAT_Q_QBTPWR,
	MAT_Q_QBTSCAN,
	MAT_Q_QBTSCANC,

#endif
#ifdef QUEC_HEART_BEAT_LPC_FEATURE
	MAT_Q_QHBCFG,
	MAT_Q_QHBSTART,
	MAT_Q_QHBSTOP,
#endif
#ifdef QUEC_GPIO_CTRL_SUPPORT
	MAT_Q_GPIOCTRL,
#endif
#ifdef QUEC_QNVFD_DEL_NV_FEATURE
	MAT_Q_QNVFD,
#endif
#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
    MAT_Q_BLACKCELL,
    MAT_Q_BLACKCELLCFG,
#endif
#ifdef QUEC_LWIP_WAN_PING_FLAG_CFG_SUPPORT
	MAT_Q_QLWPINGCFG,
#endif
#if defined(__QUECTEL_PROJECT_EC800KCN_CC__)|| defined (__QUECTEL_PROJECT_EC800KCN_CK__)
    MAT_Q_HWINFO,
#endif
    MAT_Q_QIMSXML,
#ifdef QUEC_QSCLKEX_ENABLE
	MAT_Q_QSCLKEX,
	MAT_Q_QSCLKEXCFG,
#endif
#ifdef QUEC_UESTAT_SUPPORT
    MAT_Q_QUESTAT,
#endif
#ifdef QUEC_ADC_SUPPORT
#ifdef QUEC_CUST_FOR_IPC_SUPPORT 
	MAT_Q_QADCDET,
#endif
#endif
#ifdef QUEC_SLEEP_INFO_SUPPORT
    MAT_Q_QSLEEPINFO,
#endif
#if QUEC_SMS_QCMGSP_SUPPORT
    MAT_Q_QCMGSP,
#endif
#ifdef QUEC_CCED_SUPPORT
	MAT_Q_CCED,
#endif

#ifdef QUEC_CUST_FOR_POS_SUPPORT  /*2023-2-13 Barry.Liang 魔方客户定制AT 为假的实现*/
     MAT_Q_QMUXCFG,
     MAT_Q_QIREGAPP,
     MAT_Q_QIFGCNT,
#endif
#ifdef QUEC_BLACK_CELL_SUPPORT
	MAT_Q_BLACKCELLEX,
	MAT_Q_BLACKCELLCFGEX,
	MAT_Q_BLACKCELLWEIGHT,
	MAT_Q_BLACKLWIPCFG,
#endif
#if defined(QUEC_BLACK_CELL_SUPPORT)|| defined(QUEC_THIN_BLACK_CELL_SUPPORT)
	MAT_Q_BLACKEXTAND,
#endif
#ifdef QUEC_CUST_XIPING_SUPPORT
	MAT_Q_XPCFUN,
#endif
#ifdef QUEC_CUST_TESTFLAG_SUPPORT
    MAT_Q_QTESTFLAG,
#endif
#ifdef QUEC_QNWCFG_SUPPORT
	MAT_Q_QNWCFG,
#endif
#ifdef QUECTEL_NETWORK_REJECT_URC_SUPPORT
	MAT_Q_QNETWORKSTATUS,
#endif
	MAT_Q_QNWLOCK,
#ifdef QUEC_AUTOAPN_ADJUST_SUPPORT
	MAT_Q_QAUTOAPN,
	MAT_Q_QAUTOAPNURC,
#endif
#ifdef QUEC_IMS_XML_SUPPORT
	MAT_Q_QIMSXMLURC,
#endif
#ifdef QUEC_NETDUALCH_CFG
	MAT_Q_NETDUALCHCFG,
#endif
	MAT_Q_QMNCLK,	
#if QUEC_CEER_ESM_REJECT_CAUSE_SUPPORT
    MAT_Q_QCEER,
#endif
#ifdef QUEC_FGM842D_WIFI_SUPPORT
#ifndef QUECTEL_OPEN_CPU
	MAT_Q_QWIFI,
    MAT_Q_QWMODE,
    MAT_Q_QWCLIP,
    MAT_Q_QWAUTH,
    MAT_Q_QWSSID,
    MAT_Q_QWIFIOTA,
    MAT_Q_QWDEVIP,
    MAT_Q_QWVERSION,
    MAT_Q_QWCLIRM,
    MAT_Q_QWSPIERR,
    MAT_Q_QWSCAN,
    MAT_Q_QWPORT,
#endif
#endif
#ifdef	QUEC_OPER_OOS_PHASE_PERIOD
	MAT_Q_COOSPPT,
#endif
	NUM_OF_MAT_CMD
}  MATCmdType, MATRspType;


/*---- parameter service ID ----
*/
//ICAT EXPORTED ENUM
typedef enum
{
   MAT_SVC_0,
   MAT_SVC_1,
   MAT_SVC_2,
   MAT_SVC_3,
   MAT_SVC_4,
   MAT_SVC_5,
   MAT_SVC_6,
   MAT_SVC_7,
   MAT_SVC_8,
   MAT_SVC_9,
   MAT_SVC_10,
   MAT_SVC_11,
   MAT_SVC_12,
   MAT_SVC_13,
   MAT_SVC_14,
   MAT_SVC_15,
   MAT_SVC_16,
   MAT_SVC_17,
   MAT_SVC_18,
   MAT_SVC_19,
   MAT_SVC_20,
   MAT_SVC_21,
   MAT_SVC_22,
   MAT_SVC_23,
   MAT_SVC_24,
   MAT_SVC_25,
   MAT_SVC_26,
   MAT_SVC_27,
   MAT_SVC_28,
   MAT_SVC_29,
   MAT_SVC_30,
   MAT_SVC_31,
   MAT_SVC_32,
   MAT_SVC_33,
   MAT_SVC_34,
   MAT_SVC_35,
   MAT_SVC_36,
   MAT_SVC_37,
   MAT_SVC_38,
   MAT_SVC_39,
   MAT_SVC_40,
   MAT_SVC_41,
   MAT_SVC_42,
   MAT_SVC_43,
   MAT_SVC_44,
   MAT_SVC_45,
   MAT_SVC_46,
   MAT_SVC_47,
   MAT_SVC_48,
   MAT_SVC_49,
   MAT_SVC_50,
   MAT_SVC_51,
   MAT_SVC_52,
   MAT_SVC_53,
   MAT_SVC_54,
   MAT_SVC_55,
   MAT_SVC_56,
   MAT_SVC_57,
   MAT_SVC_58,
   MAT_SVC_59,
   MAT_SVC_60,
   MAT_SVC_61,
   MAT_SVC_62,
   MAT_SVC_63,
   NUM_OF_MAT_SVC
}MATSvcId;

//ICAT EXPORTED ENUM
typedef enum
{
	MAT_SIM_0,
	MAT_SIM_1,
	NUM_OF_MAT_SIM
}MATSimId;

/*---- data type of MAT parameters ----
*/
//ICAT EXPORTED ENUM
typedef enum {
    MAT_DATA_TYPE_DECIMAL,
    MAT_DATA_TYPE_STRING,
	MAT_DATA_TYPE_SET,
	MAT_DATA_TYPE_RANGE,
} MATDataType;

//ICAT EXPORTED STRUCT
struct MATParameterRange
{
	int min;
	int max;
};

/*---- data type of MAT parameters ----
*/
//ICAT EXPORTED STRUCT
struct MATParameterItem_T;
//ICAT EXPORTED STRUCT
typedef union MATDataValue_U {
    unsigned int	decimal;
    char			*string_p;
	struct MATParameterItem_T *set_p;
	struct MATParameterRange range;
} MATDataValue;

/*  parameters definition
     type       -- data type for value
     is_default -- if the AT parameter is omitted, we should pass a defaut value
     value      -- value for each parameter
*/
//ICAT EXPORTED STRUCT
typedef struct MATParameter_T
{
    MATDataType  type;
    BOOL         is_default;
    MATDataValue value;
}MATParameter;

/*
 * macro helper for setting parameter
 */
#define MAT_INT_VALUE(param, v) \
    do \
    { \
      (param).type = MAT_DATA_TYPE_DECIMAL; \
      (param).is_default = FALSE; \
      (param).value.decimal = (v); \
    } while (0)

#define MAT_STR_VALUE(param, v) \
    do \
    { \
      (param).type = MAT_DATA_TYPE_STRING; \
      (param).is_default = FALSE; \
      (param).value.string_p = (v); \
    } while (0)

#define MAT_RANGE_VALUE(param, min, max) \
    do	\
    {	\
      (param).type = MAT_DATA_TYPE_RANGE; \
      (param).is_default = FALSE;		\
      (param).value.range.min = (min); \
	  (param).value.range.max = (max); \
    } while (0)

#define MAT_DEFAULT_VALUE(param) \
    do \
    { \
      (param).type = MAT_DATA_TYPE_DECIMAL; \
      (param).is_default = TRUE; \
      (param).value.decimal = 0; \
    } while (0)

#define MAT_SET_VALUE(param, v)	\
    do \
    { \
      (param).type = MAT_DATA_TYPE_SET; \
      (param).is_default = FALSE; \
      (param).value.set_p = (v); \
    } while (0)

//ICAT EXPORTED ENUM
typedef enum
{
    MAT_RC_NULL,
    MAT_RC_OK,        // OK will be sent
    MAT_RC_ERROR,     // ERROR will be sent
    MAT_RC_CME_ERROR, // CME ERROR will be sent
    MAT_RC_CMS_ERROR, // CMS ERROR will be sent
    MAT_RC_RESERVED
}MATResultCode;

//ICAT EXPORTED STRUCT
typedef struct MATParameterItem_T
{
	UINT16  max_para_number;
    UINT16 num_Retparameters;
    MATParameter* RetPara;
}MATParameterItem, MATParameterSet;

//ICAT EXPORTED ENUM
typedef enum
{
    MAT_RET_CONFIRM,
    MAT_RET_INDICATION
}MATRetType;

//ICAT EXPORTED ENUM
typedef enum
{
	MAT_PAR_RESULT_CODE_OK,
	MAT_PAR_RESULT_CODE_ERROR
}MATParseResultCode;

//ICAT EXPORTED ENUM
typedef enum
{
    MAT_RET_SUCCESS,
	MAT_RET_TOO_MANY_PARAMETERS,
    MAT_RET_CURRENT_CH_HAS_CMD_PROCESSING,
    MAT_RET_PARA_TYPE_UNSUPPORT,
    MAT_RET_NULL_CLINET_TAG_POINTER,
    MAT_RET_NUM_PARA_ERROR,
    MAT_RET_PARA_TYPE_ERROR,
    MAT_RET_HANDLER_FAILURE,
    MAT_RET_FIND_FREE_CHANNEL_ERROR
}MATRecvRetType;

/* MMI<--MAT return parameters definition
   cmd_type          -- the command or indication type.
   resultCode        -- general result code: OK, ERROR, CME/CMS ERROR

   numItems          -- the number of items in the returned parameters
   RetParaItems      -- the detail value of each returned parameters
*/
//ICAT EXPORTED STRUCT
typedef struct MATReturnPara_T
{
    MATResultCode resultCode;
    UINT16 numItems;
    MATParameterItem* RetParaItems;
	MATRspType cmd_type;
} MATReturnPara;


typedef struct _ShmApiMsg
{
	int svcId;
	int procId;
	int msglen;
}ShmApiMsg;


#define SHM_HEADER_SIZE sizeof(ShmApiMsg)



/*
 * This function gets a byte steam from a string.
 *
 * @str the hex string, for example 010203ffeeef
 * @length the length of output byte stream
 *
 * @return the byte stream.
 * @note the byte stream must be free when not used.
 */
UINT8* MATGetDataFromStr(const char* str, int *length);
UINT8* MATGetStrFromData(const char* Bytestreamdata, int data_length);
#endif  /* _MAT_H_ */

