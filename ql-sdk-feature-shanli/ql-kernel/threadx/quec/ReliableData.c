/*------------------------------------------------------------
(C) Copyright [2006-2008] Marvell International Ltd.
All Rights Reserved
------------------------------------------------------------*/

/******************************************************************************
**  COPYRIGHT Oct 31, 2007 Marvell Inernational Ltd.
**  All Rights Reserved
**
**
**  This software as well as the software described in it is furnished under
**  license and may only be used or copied in accordance with the terms of the
**  license. The information in this file is furnished for informational use
**  only, is subject to change without notice, and should not be construed as
**  a commitment by Intel Corporation. Marvell Corporation assumes no
**  responsibility or liability for any errors or inaccuracies that may appear
**  in this document or any software that may be provided in association with
**  this document.
**  Except as permitted by such license, no part of this document may be
**  reproduced, stored in a retrieval system, or transmitted in any form or by
**  any means without the express written consent of Marvell Corporation.
**
**   Copyright (C) 1995-2002 Jean-loup Gailly and Mark Adler
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Jean-loup Gailly        Mark Adler
**  jloup@gzip.org          madler@alumni.caltech.edu
**
**  FILENAME:  ReliableData.c
**
**  PURPOSE:  up pack the Reliable data area to data that the COM can use as
** 			static or as files
******************************************************************************/


/*----------- Local include files --------------------------------------------*/
#include "diag.h"
#include "ReliableData.h"
#include "csw_mem.h"
#include "nvm_header.h"
#include "loadTable.h"
#include "asserts.h"
#include "IMEI.h"
#include "mep.h"
#include "platform_nvm.h"
#include "mux27010.h"
#include "mux_def.h"
#include "utlAtParser.h"
#include "loadTable.h"
#include "qspi_nor.h"
#include "UART.h"
#include "MRD.h"
#include "crossPlatformSW.h"
#include "psm_wrapper.h"
#include "quec_cust_patch.h"
#ifdef LZMA_SUPPORT
#include "LzmaLib.h"
#endif

#include "telprod.h"	//Fias.fan @20220617 //增加SN2的读写接口和AT

//#define RD_DEBUG

/* in the shared DDR there is a use of the 10KB-
 * we skipped it to the free area, OBM is doing the same*/
#define RD_DDR_OFFSET       (1024*10)
#define RD_AT_LOOPBACK

char gWifiMACAddr[6];
char gBtMACAddr[6];
char gSerialNumber[36] = {0};

#ifdef QUECTEL_PROJECT_CUST
char IMEI_WEB[IMEI_NUMBER_SIZE+1] = {0};
char IMEI_WEB_2[IMEI_NUMBER_SIZE+1] = {0};
char QUEC_SN[36] = {0};
char QUEC_SN_1[36] = {0};		//Fias.fan @20220617 //增加SN2的读写接口和AT

#ifdef  QUEC_CAMMERA_DECODE_AUTHORIZATION
char QRCODE_WEB[MAX_QRCODE_LEN+1] = {0};
char QRLICENSE_WEB[MAX_LICENSEINFO_LEN+1] = {0};
#endif
#endif

/*----------- Local function --------------------------------------------*/
static BOOL RDSaveFilesToFS(RD_TCHAR *pFile_name,void *buff, size_t size,size_t element_size);
static UINT32 ReliableDataCalculateCheckSum(UINT32 *pBuf,UINT32 *pRD_DDR_end);
int UpdateIMEI(void);
void UpdateIMEI2(void);
extern void log_printf(const char* fmt, ...);
extern void DbgPrintf(char* fmt, ...);
int FDI_Access(const char *path, UINT32 mode);
extern void RDHandleGenData(const char *pFile_name,void *buff, size_t size);
extern void setSimEncrptKey(char *data);
extern void RDSaveADCFileToMRD(PM803_ADC_TYPE type);

extern UINT32 factory_flash_type;
/************************************************************************************
 * Function     : PreReliableDataPhase1
 ************************************************************************************
 *
 * Description  : Pre Phase 1 this is called at Cinit1.c
 * 				IMEI is being update at ReliableDataPrePhase1
 *				this is for solving issue with COM silent reset.
 *				If only COM is reseting OBM will not copy this information
 *				so IMEI info must be kept in a retain DDR area - we keep it
 *				 as const and modify it before MPU is activated
 *               if RD_FAIL we need to initlize the IMEI with default.
 * Input:         void
 *
 * Output:
 ************************************************************************************/
void  ReliableDataPrePhase1 ( void )
{
	BOOL retVal;


//    memset(&gstMrdDebug, 0, sizeof(gstMrdDebug));

//	gstMrdDebug.ulDebugInfoTag = 0x5A5A5A5A;

	/*initlize with default - this will be override in case a valid IMEI will be found
	 * or this will be the IMEI in case no IMEI entry exist*/

	CPUartLogPrintf("ReliableDataPrePhase1");

	IMEIinit(NULL);
	IMEI2init(NULL);

//stMrdDebug.ulMrdInfo = 1;

	retVal = ReliableDataUnPack(RD_PRE_PHASE2);

	if(retVal == RD_FAIL)
	{
//gstMrdDebug.ulMrdInfo |= 1<<1;
   		IMEIinit(NULL);//in case we couldn't up-pack ( buffer is not valid) initlize with default.
		IMEI2init(NULL);
	}


#if defined(RD_DEBUG)
	ASSERT(retVal == RD_SUCCESS);
#endif
}

/************************************************************************************
 * Function     : ReliableDataPhase1
 ************************************************************************************
 *                                                                                  *
 * Description  : Phase 1								                            *
 *                                                                                  *
 * Input:         void											                    *
 *                                                                                  *
 * Output:        															        *
 ************************************************************************************/
void  ReliableDataPhase1 ( void )
{
  //none

}
#ifdef RD_AT_LOOPBACK
typedef struct _ATRDMsg
{
	UINT32 length;
	char *data;
} ATRDMsg;


#define utlAT_MAX_RESPONSE_LENGTH  400

static UINT32 rd_dlc_opened=0;
int RD_PORT_SID = 0;
static OSATaskRef RDPortTaskRef;
static OSMsgQRef gATRDMsgQ = NULL;




extern UINT32 xid_for_rd;
extern UINT8 DefaultModem;
#define RD_RX    0x1
#define NUM_ELEMS(x)  (sizeof(x)/sizeof(x[0]))
#define RD_MESSAGE_Q_SIZE		16

__align(4) static UINT8 RDPortTaskStack[2048];





/** returns 1 if line starts with prefix, 0 if it does not */

int strStartsWith(const char *line, const char *prefix)

{

         for (; *line != '\0' && *prefix != '\0'; line++, prefix++)

         {

                   if (*line != *prefix)

                   {

                            return 0;

                   }

         }



         return *prefix == '\0';

}





/**

 * returns 1 if line is a final response indicating error

 * See 27.007 annex B

 * WARNING: NO CARRIER are alyways unsolicited

 */

static int isFinalResponseError(const char *line)

{

         static const char * s_finalResponsesError[] = {

                   "ERROR",

                   "+CMS ERROR:",

                   "+CME ERROR:",

                   "NO ANSWER",

                   "NO DIALTONE",

         };

         size_t i;

 

         for (i = 0; i < NUM_ELEMS(s_finalResponsesError); i++)

         {

                   if (strStartsWith(line, s_finalResponsesError[i]))

                   {

                            return 1;

                   }

         }

 

         return 0;

}

 

/**

 * returns 1 if line is a final response indicating success

 * See 27.007 annex B

 */

static int isFinalResponseSuccess(const char *line)

{

         static const char * s_finalResponsesSuccess[] = {

                   "OK",

                   "CONNECT"   /* some stacks start up data on another channel */

         };

         size_t i;

 

         for (i = 0; i < NUM_ELEMS(s_finalResponsesSuccess); i++)

         {

                   if (strStartsWith(line, s_finalResponsesSuccess[i]))

                   {

                            return 1;

                   }

         }

 

         return 0;

}

 

/**

 * returns 1 if line is a final response, either  error or success

 * See 27.007 annex B

 * WARNING: NO CARRIER and others are sometimes unsolicited

 */

static int isFinalResponse(const char *line)

{

         return (isFinalResponseSuccess(line) || isFinalResponseError(line));

}



void rd_linkstatus_ind(unsigned int dlci,DlcLinkStatus status)
{
	
	if (status == DlcOpened)
		rd_dlc_opened = 1;
	else
		rd_dlc_opened = 0;
}

static void rd_Port_TxDoneInd(unsigned int dlci,void* responce_str, unsigned int length)
{
	
	
}

static void rd_Port_DataInd(unsigned int dlci, void* buffer, unsigned int length)
{
	int i;
	OSA_STATUS status;
	ATRDMsg msg;
	msg.length = length;
	msg.data = malloc(length + 1);
	memset(msg.data, 0, length + 1);
	memcpy(msg.data, buffer, length);

	mux27010_read_ack(dlci,buffer);
	//uart_printf("rd_port %d recv %s len %d\r\n",dlci,msg.data,msg.length);
	DIAG_FILTER(SW_PLAT,RDA,rd_Port_DataInd,DIAG_INFORMATION)
   	diagPrintf("rd_port %d recv %s len %d",dlci,msg.data,msg.length);
	/*
	for(i=0;i<length;i++)
	{
		uart_printf("0x%x",msg.data[i]);

	}
	*/
	status = OSAMsgQSend(gATRDMsgQ, sizeof(msg), (UINT8*)&msg, OSA_NO_SUSPEND);
	if (status != OS_SUCCESS)
	{
		ASSERT(0);
	}
	
	


}

#if 0
extern UINT32 At_loopback_channel;
void rd_PortTask(void *ptrPara)
{

	MUX_CallBackFuncS func;
	OSA_STATUS status;
	UINT32 flag;
	char*	ptr;
	UINT8	ATRDMsg_buf[RD_MESSAGE_Q_SIZE];
	ATRDMsg *pATRDMsg;
	
	func.LinkStatusIndCB = rd_linkstatus_ind;
	func.RxIndCB = rd_Port_DataInd;
	func.TxDoneCnfCB = rd_Port_TxDoneInd;
	



	while(1)
	{
		RD_PORT_SID = mux27010_dlc_open(RELIABL_DATA, &func);

		if(RD_PORT_SID < 0) OSATaskSleep(100);
		else break;
	}
	
	while(1)
	{
		status = OSAMsgQRecv(gATRDMsgQ, ATRDMsg_buf, RD_MESSAGE_Q_SIZE, OSA_SUSPEND);	
		if(status != OS_SUCCESS)
	        {
	            ASSERT(0);
	        }
		pATRDMsg = (ATRDMsg*)ATRDMsg_buf;

		//uart_printf("msgq recv %s\r\n",pATRDMsg->data);
		//uart_printf("isFinalResponse %d\r\n",isFinalResponse(pATRDMsg->data+2));
		
		if(isFinalResponse(pATRDMsg->data+2))
		{
			//uart_printf("final responce\r\n");
			DIAG_FILTER(SW_PLAT,RDA,rd_PortTask,DIAG_INFORMATION)
   			diagPrintf("rd_at got final responce");
			utlAtCommandResponse(xid_for_rd,utlAT_COMMAND_RESPONSE_TYPE_CUSTOM, "");
		}
		
		//uart_printf("rd_port remove at node done\r\n");
		//uart_printf("DefaultModem %d\r\n",DefaultModem);
		
		ptr=(char *)malloc(pATRDMsg->length+1);
		ASSERT(ptr!= NULL);
		memcpy(ptr,pATRDMsg->data,pATRDMsg->length);
		#if 0
		free(pATRDMsg->data);
		
		DIAG_FILTER(SW_PLAT,RDA,rd_PortTask,DIAG_INFORMATION)
   		diagPrintf("loopback responce %s  len%d",pATRDMsg->data,pATRDMsg->length);
		#else
		/*Fixed coverity[pass_freed_arg]*/		
		DIAG_FILTER(SW_PLAT,RDA,rd_PortTask,DIAG_INFORMATION)
   		diagPrintf("loopback responce %s  len%d",pATRDMsg->data,pATRDMsg->length);

		free(pATRDMsg->data);
		#endif
		
		while (mux27010_write(At_loopback_channel, ptr, pATRDMsg->length) < 0)
		{
						
			OSATaskSleep(100);
				
		}
		//uart_printf("rd_port send responce done\r\n");
	}


}
#endif
#endif

/************************************************************************************
 * Function     : ReliableDataPhase2
 ************************************************************************************
 *                                                                                  *
 * Description  : Phase 2 - all data that need to be converted to files             *
 *                                                                                  *
 * Input:         void											                    *
 *                                                                                  *
 * Output:        															        *
 ************************************************************************************/

char *filter_list_buf=NULL;


void  ReliableDataPhase2 ( void )
{
  	BOOL retVal;
	OSA_STATUS status;

	uart_printf("ReliableDataPhase2\r\n");

	APReliableDataGenFilter();

    uart_printf("UnPack Reliable Data\r\n");

	retVal = APReliableDataUnPack(RD_PHASE2);
	if( retVal != RD_SUCCESS)
	{
        RTI_LOG("Fail to unpack reliable data.");
	}

    uart_printf("UnPack Factory Data\r\n");

 	retVal = ReliableDataUnPack(RD_PHASE2);
	
	if( retVal != RD_SUCCESS)
	{
	    RTI_LOG("Fail to unpack factory data.");
 		DIAG_FILTER(SW_PLAT,RDA,ReliableDataPhase2FAIL,DIAG_INFORMATION)
   		diagPrintf("*** WARNING ***- Reliable Data area in not valid - no IMEI no MEP no NVM files ***");
	}
	else
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataPhase2SUCCESS,DIAG_INFORMATION)
   		diagPrintf("*** SUCCESS *** - Reliable Data is valid ***");
	}
	if(filter_list_buf!=NULL)
		free(filter_list_buf);

#if defined(RD_DEBUG)
	ASSERT(retVal == RD_SUCCESS);
#endif
}


char mrd_nvm_mask_list[][64]={"TTPCom_NRAM2_ABMM_WRITEABLE_DATA.gki",
								"SystemControl.nvm",
								"TTPCom_NRAM2_APN_PDN_LIST_DATA.nvm"};

BOOL mrd_nvm_mask(char *filename)
{
	UINT32 cnt;
	UINT32 i;
	FILE_INFO  info;

	uart_printf("Check %s\r\n", filename);

	if(strcmp(filename,"FilterList.txt")==0)
	{
		uart_printf("FilterList.txt itself, not unpack\r\n");
		return TRUE;
	}

#if 0
	if(FDI_findfirst(filename, &info) == 0)
	{
		uart_printf("mrd_nvm_mask file exist\r\n");
	}
	else
	{
		uart_printf("mrd_nvm_mask file not exist\r\n");
		return FALSE;
	}


	cnt=sizeof(mrd_nvm_mask_list)/64;

	for(i=0;i<cnt;i++)
	{
		if(strcmp(filename,mrd_nvm_mask_list[i])==0)
		{
			DbgPrintf("mrd_nvm_mask file in filter list\r\n");
			return TRUE;
		}
	}


	if(filter_list_buf!=NULL)
	{
		if(strstr(filter_list_buf, filename)!=NULL)
		{
			uart_printf("mrd_nvm_mask file in filter list\r\n");
			return TRUE;
		}
	}

	uart_printf("mrd_nvm_mask file not in filter list\r\n");
#endif
	return FALSE;
}

#define UNPACK_RET_OK			0
#define UNPACK_RET_MRD_ERROR	1
#define UNPACK_RET_MRD_NO_NVM	2
#define UNPACK_RET_NVM_OPEN		3



UINT32 mrd_nvm_unpack(char *filename)
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;
	UINT8 dbgi =0;
	UINT32 *MepEntryData = NULL;
	UINT32 *MepEntryData2 = NULL;
	UINT32 flag=0;

	BOOL IsPhase2=TRUE;

 	
    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_RDATA_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
		return UNPACK_RET_MRD_ERROR;

 
    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;

	if (IsPhase2)
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack,DIAG_INFORMATION)
   		diagPrintf("RDPhase1 DDR buffer at address=[%lx],upper limit[%lx]",RD_DDR_begin,RD_DDR_end);
	}

	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{
 		if(IsPhase2)
		{
			DbgPrintf("RD validBufferStamp OK =[%lx]\r\n",header.validBufferStamp);
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStampValid,DIAG_INFORMATION)
   			diagPrintf("RD validBufferStamp OK =[%lx]",header.validBufferStamp);
		}

	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{
 		if(IsPhase2)
		{
			/*this is ok*/
			DbgPrintf("RD validBufferStamp checksum is ok =[%lx]\r\n",header.validBufferStamp);
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCS,DIAG_INFORMATION)
   		 	diagPrintf("RD validBufferStamp checksum is ok =[%lx]",header.validBufferStamp);
		}
	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
 		if(IsPhase2)
		{
			DbgPrintf("RD WRONG validBufferStamp =[%lx]\r\n",header.validBufferStamp);
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStamp,DIAG_INFORMATION)
   		 	diagPrintf("RD WRONG validBufferStamp =[%lx]",header.validBufferStamp);
		}

		return UNPACK_RET_MRD_ERROR;
	}

 
	if(IsPhase2)
	{
		DbgPrintf("RD header version doesn't fit =[%lx] vs.[%lx]\r\n",header.version,RD_FORMAT_VER);
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);

	}



	/* check format version in case of failure print only if we at phase2 after diag is ready */
	if(header.version != RD_FORMAT_VER && IsPhase2)
	{
 		DbgPrintf("RD header version doesn't fit =[%lx] vs.[%lx]\r\n",header.version,RD_FORMAT_VER);
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);
		 //no return since we support Legacy mode
	}

	/* check stamp in case of failure print only if we at phase2 after diag is ready */
	if ((header.validBufferStamp != VALID_BUF_STMP)&& IsPhase2 )
	{
 		DbgPrintf("RD header.version =[%lx]\r\n",header.version);
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersion,DIAG_INFORMATION)
   		diagPrintf("RD header.version =[%lx]",header.version);
	}

	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and 
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);
		
		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{
 			if(IsPhase2)
			{
			DbgPrintf("RD WRONG header.bufCheckSum [%lx] != [%lx]\r\n",header.bufCheckSum,checksum);
			 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCheckSum,DIAG_INFORMATION)
   			 diagPrintf("RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
			}
			return UNPACK_RET_MRD_ERROR;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/
		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
 	}

	pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_BUFFER_HEADER)); //skipping the buffer header

 
	do
	{
		UINT32 entry_size=0;
		UINT8  pad_size=0;

		if (IsPhase2)
		{
			DbgPrintf("RD Convert data indx[%lx]\r\n",dbgi++);
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDo,DIAG_INFORMATION)
   			diagPrintf("RD Convert data indx[%lx]",dbgi++);
		}

		memcpy(&entry,(RD_ENTRY*)pRAMbuf,sizeof(RD_ENTRY));

		pRAMbuf--;
		entry.pEntryData = (UINT32*)((UINT8*)pRAMbuf +  (sizeof(RD_ENTRY))); //update the data pointer

		entry_size = (entry.fileAndPadSize & 0x00FFFFFF);
 		pad_size = (UINT8)(((entry.fileAndPadSize & 0xFF000000) >> 24));

		/* move the pointer to next entry - the entry data was copied above ->entry*/
	    pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_ENTRY) + (entry_size));

		if (IsPhase2 )
		{
			DbgPrintf("ReliableData:Entry type:[0x%lx] exit on [0x%lx]\r\n",entry.entryType,END_BUF_STMP);
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDo1,DIAG_INFORMATION)
   		    diagPrintf("ReliableData:Entry type:[0x%lx] exit on [0x%lx]",entry.entryType,END_BUF_STMP);
		}

 		switch(entry.entryType)
 		{

		   	case NVM_TYPE:
 
  					if (IsPhase2 )
  					{
  						DbgPrintf("NVM_TYPE\r\n");
						DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackNVM,DIAG_INFORMATION)
   	    	 			diagPrintf("update - RD NVM_TYPE size [%lx]",entry_size);

						if(strcmp(entry.file_name,filename)==0)
						{
							DbgPrintf("%s, match\r\n",entry.file_name);
 							UINT32 file_size;

						    file_size = entry_size - pad_size;

							/* according to desgin when ever we will reach here we will create new files and override exsiting ones*/
				   			retVal = RDSaveFilesToFS(entry.file_name, entry.pEntryData ,file_size,sizeof(UINT8) );//create file

				   			if(retVal != TRUE)
				   			{
				   				flag=2;

				   			}
							else
							{
								flag=1;
							}
						}
						else
						{
							DbgPrintf("%s, not match\r\n",entry.file_name);
						}
					}

			break;

		   	default:
		   	{
		   		// pRAMbuf = (UINT32*)RD_DDR_end; //if we didn't find a valid entry type then no need to search any more.
				if (IsPhase2)
				{
				    DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack_Unhandle,DIAG_INFORMATION)
				    diagPrintf("Unhandled entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
				}
		   	}
		   	break;

		} //switch
	}while((entry.entryType != (UINT32)END_BUF_STMP) && (pRAMbuf < (UINT32*)RD_DDR_end )); //while


 
	if(flag==1)
	  	return UNPACK_RET_OK;
	else if(flag==2)
		return UNPACK_RET_NVM_OPEN;
	else
		return UNPACK_RET_MRD_NO_NVM;
}




/************************************************************************************
 * Function     : ReliableDataUnPack
 ************************************************************************************
 *                                                                                  *
 * Description  : un pack Reliable data and  called the appropiate function         *
 *                                                                                  *
 * Input:         IsPhase2 -  for knowing when we can use DIAG/NVM etc.             *
 *                                                                                  *
 * Output:        															        *
 ************************************************************************************/


BOOL   ReliableDataCheck ( )
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;


 	
    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_RDATA_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
		return RD_FAIL;

 
    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;



	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{


	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{

	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
		return RD_FAIL;
	}

 


	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and 
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

		uart_printf("checksum=0x%x,0x%x\r\n", header.bufCheckSum, checksum);

		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{

			return RD_FAIL;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/
		 
//		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
		return RD_SUCCESS;
 	}

	return RD_SUCCESS;
}


BOOL   ReliableDataBakCheck ( )
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;

 	
    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_RDATA_Bak_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
		return RD_FAIL;

 
    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;



	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{


	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{

	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
		return RD_FAIL;
	}

 


	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and 
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

		uart_printf("checksum=0x%x,0x%x\r\n", header.bufCheckSum, checksum);

		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{

			return RD_FAIL;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/
		 
//		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
		return RD_SUCCESS;
 	}

	return RD_SUCCESS;
}

void   ReliableDataVerify ( )
{
	UINT32 a_ok;
	UINT32 b_ok;
	UINT8 *buf;
	UINT8 *buf_bak;
	UINT32 len;
	UINT32 i;

//	#define CRANE_QSPI_BASE_ADD 0x80000000
	UINT32 CRANE_FLASH_BASE_ADD=0;
	extern UINT32 factory_flash_type;

	UINT32 begin,end;

	if(factory_flash_type==0)
		CRANE_FLASH_BASE_ADD=0x80000000;
	else if(factory_flash_type==1)
		CRANE_FLASH_BASE_ADD=0x90000000;
	else
		ASSERT(0);

	if(ReliableDataCheck()==RD_SUCCESS)
		a_ok=1;
	else
		a_ok=0;

	if(ReliableDataBakCheck()==RD_SUCCESS)
		b_ok=1;
	else
		b_ok=0;

	uart_printf("%s, a_ok=%u, b_ok=%u\r\n",__func__, a_ok, b_ok);


	getAppCom_RDATA_MemAddr(&begin, &end);
	len=end+4-begin;
	uart_printf("%s, begin=0x%x, end=0x%x, len=0x%x\r\n",__func__, begin, end, len);


	buf=(UINT8*)malloc(len);
    if(buf == NULL)
        return ;

	buf_bak=(UINT8*)malloc(len);
    if( buf_bak == NULL)
    {
        if (buf)
            free(buf);
        return ;
    }

	if(a_ok==0)
	{

		getAppCom_RDATA_MemAddr(&begin, &end);

		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

		for(i=0;i<len;i++)
		{
			if(buf[i]!=0xFF)
			{
				RTI_LOG("Need Erase begin(0x%x),len(0x%x)\r\n",begin,len);
				//Sharon.li@20220517 由于ASR CraneL 平台factory分区是32K的，需要使用4K对齐的擦除接口
				#if defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM)
				spi_nor_do_erase_4k((begin - CRANE_FLASH_BASE_ADD), len, factory_flash_type);
				#else
				spi_nor_do_erase((begin - CRANE_FLASH_BASE_ADD), len, factory_flash_type);
				#endif
				break;
			}
		}
		if(i==len)
			uart_printf("factory a all 0xFF\r\n");

	}


	if(b_ok==0)
	{
		getAppCom_RDATA_Bak_MemAddr(&begin, &end);

		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

		for(i=0;i<len;i++)
		{
			if(buf[i]!=0xFF)
			{
				RTI_LOG("Need Erase begin(0x%x),len(0x%x)\r\n",begin,len);
				
				//Sharon.li@20220517 由于ASR CraneL 平台factory分区是32K的，需要使用4K对齐的擦除接口
				#if defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM)
				spi_nor_do_erase_4k((begin - CRANE_FLASH_BASE_ADD), len, factory_flash_type);
				#else
				spi_nor_do_erase((begin - CRANE_FLASH_BASE_ADD), len, factory_flash_type);
				#endif
				break;
			}
		}
		if(i==len)
			uart_printf("factory b all 0xFF\r\n");
	}


	if((a_ok==0)&&(b_ok==0))
	{
		uart_printf("Do nothing\r\n");
	}
	else if((a_ok==1)&&(b_ok==0))
	{
		getAppCom_RDATA_MemAddr(&begin, &end);
		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

		getAppCom_RDATA_Bak_MemAddr(&begin, &end);
		spi_nor_do_write((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

	}
	else if((a_ok==0)&&(b_ok==1))
	{
		getAppCom_RDATA_Bak_MemAddr(&begin, &end);
		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

		getAppCom_RDATA_MemAddr(&begin, &end);
		spi_nor_do_write((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);
	}
	else if((a_ok==1)&&(b_ok==1))
	{
		getAppCom_RDATA_MemAddr(&begin, &end);
		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);

		getAppCom_RDATA_Bak_MemAddr(&begin, &end);
		spi_nor_do_read((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf_bak, len, factory_flash_type);

		if(memcmp(buf, buf_bak, len)!=0)
		{
			RTI_LOG("factory a!=b\r\n");
			#if defined(CRANEL_8MRAM)   // quectel add  ab校验都ok 但是内容不一致时 以a区为准 覆盖b区
			spi_nor_do_erase_4k((begin - CRANE_FLASH_BASE_ADD), len, factory_flash_type);  //擦备份区 主区数据copy到备份
			spi_nor_do_write((begin - CRANE_FLASH_BASE_ADD), (unsigned int)buf, len, factory_flash_type);
			#endif
		}
	}

    if(buf != NULL)
    {
    	free(buf);
        buf = NULL;
    }

    if(buf_bak != NULL)
    {
    	free(buf_bak);
        buf_bak = NULL;
    }

}


unsigned int rf_calib_status=0;
unsigned int rd_imei_flag=0;
unsigned int rd_mep_flag=0;
unsigned int fact_imei_flag=0;
extern UINT32 mrd_extra_info_init(PM803_ADC_TYPE type);

unsigned int rf_calibration_status(void)
{
	return rf_calib_status;
}

static void * parse_compressed_file_name(RD_TCHAR *pFile_name)
{
#ifdef LZMA_SUPPORT
    void *uncompressd_name = NULL;
    UINT32 len = strlen(pFile_name);

    if(len < 5)
    {
        return NULL;
    }

    if(memcmp(pFile_name + len - 5, ".lzma", 5) != 0)
    {
        return NULL;
    }

    uncompressd_name = (UINT32 *)malloc(len + 1);
    if(uncompressd_name == NULL)
    {
        return NULL;
    }

    memset(uncompressd_name, 0, len + 1);
    memcpy(uncompressd_name, pFile_name, len - 5);

    return uncompressd_name;
#else
    return NULL;
#endif
}


static void * parse_compressed_file(RD_TCHAR *pFile_name,void *buff, size_t *size)
{
#ifdef LZMA_SUPPORT
    void *uncompressd_buf=NULL;
    int res = 0;
    unsigned long len = strlen(pFile_name);
    size_t srcLen = *size, dstLen = 0;

    if(len < 5)
    {
        return NULL;
    }
    if(memcmp(pFile_name + len - 5, ".lzma", 5) != 0)
    {
        return NULL;
    }

    res = isLzmaCompressed((const unsigned char *)buff);
    if(res == 0)
    {
        return NULL;
    }

    dstLen = LzmaUncompressLen((const unsigned char *)buff);
    uncompressd_buf=(UINT32 *)malloc(dstLen);
    if(uncompressd_buf == NULL)
    {
        return NULL;
    }

    res = LzmaUncompress((unsigned char *)uncompressd_buf, &dstLen, (const unsigned char *)buff, &srcLen);
    if(res != 0)
    {
        free(uncompressd_buf);
        return NULL;
    }

    *(pFile_name+ len - 5) = '\0';
    *size = dstLen;

    return uncompressd_buf;
#else
    return NULL;
#endif
}

#if QUEC_MULT_HARDWARE_SUPPORT
#define   QUEC_BAND_GSM_900        0x01 //B8
#define   QUEC_BAND_GSM_1800        0x02        //B3
#define   QUEC_BAND_GSM_850        0x04         //B5
#define   QUEC_BAND_GSM_1900        0x08        //B2
#define   QUEC_BAND_WCDMA_2100        0x10         //B1
#define   QUEC_BAND_WCDMA_1900        0x20        //B2
#define   QUEC_BAND_WCDMA_850        0x40         //B5
#define   QUEC_BAND_WCDMA_900        0x80        //B8
#define   QUEC_BAND_WCDMA_800        0x100         //B6
#define   QUEC_BAND_WCDMA_1700        0x200        //B4
#define   QUEC_BAND_LTE_BAND1        0x01         
#define   QUEC_BAND_LTE_BAND2        0x02        
#define   QUEC_BAND_LTE_BAND3        0x04         
#define   QUEC_BAND_LTE_BAND4        0x08        
#define   QUEC_BAND_LTE_BAND5        0x10         
#define   QUEC_BAND_LTE_BAND7        0x40        
#define   QUEC_BAND_LTE_BAND8        0x80        
#define   QUEC_BAND_LTE_BAND17        0x10000          
#define   QUEC_BAND_LTE_BAND20        0x80000         
#define   QUEC_BAND_LTE_BAND28        0x8000000         	//add band 28
#define   QUEC_BAND_LTE_BAND31        0x40000000         	//add band 31
#define   QUEC_BAND_LTE_BAND33        0x100000000           //add band 33
#define   QUEC_BAND_LTE_BAND34        0x200000000           //add band 34
#define   QUEC_BAND_LTE_BAND38        0x2000000000          
#define   QUEC_BAND_LTE_BAND39        0x4000000000         
#define   QUEC_BAND_LTE_BAND40        0x8000000000          
#define   QUEC_BAND_LTE_BAND41        0x10000000000        
#define   QUEC_BAND_LTE_BAND65        0x1        
#define   QUEC_BAND_LTE_BAND66        0x2        
#define   QUEC_BAND_LTE_BAND72        0x80        

quec_mult_hardware_s quec_mult_hardware[]={
{"TTPCom_NRAM2_CUSTOMIZATION_DATA_EC600MCNCC.gki",0,0,0,
QUEC_BAND_LTE_BAND1|QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND5|QUEC_BAND_LTE_BAND8|QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41},
{"TTPCom_NRAM2_CUSTOMIZATION_DATA_EC600MCNMC.gki",1,0,0,
QUEC_BAND_LTE_BAND3|QUEC_BAND_LTE_BAND8|QUEC_BAND_LTE_BAND34|QUEC_BAND_LTE_BAND38|QUEC_BAND_LTE_BAND39|QUEC_BAND_LTE_BAND40|QUEC_BAND_LTE_BAND41}
};
#define QUEC_RD_CUSTOMIZATION_DEFAULT_GKI "TTPCom_NRAM2_CUSTOMIZATION_DATA.gki"
#define QUEC_RD_CUSTOMIZATION_DATA_GKI "TTPCom_NRAM2_CUSTOMIZATION_DATA"
typedef struct{
char pose;
char pin_level;
}quec_mult_pin_s;
quec_mult_pin_s quec_mult_hardware_record={0xff,0xff};

UINT64 quec_mult_hardware_band(char *band_mode)
{
    UINT64 temp_band=0;
    if(band_mode==NULL || quec_mult_hardware_record.pose==0xff)
    return 0;
    if(memcmp(band_mode,"GSM",strlen("GSM"))==0)
    {
        temp_band=quec_mult_hardware[quec_mult_hardware_record.pose].GSM_BAND;
    }
    else if(memcmp(band_mode,"WCDMA",strlen("WCDMA"))==0)
    {
        temp_band=quec_mult_hardware[quec_mult_hardware_record.pose].WCDMA_BAND;

    }
    else if(memcmp(band_mode,"LTE",strlen("LTE"))==0)
    {
        temp_band=quec_mult_hardware[quec_mult_hardware_record.pose].LTE_BAND;
    }
    else
    {
        CPUartLogPrintf("%s,%d,error",__FUNCTION__,__LINE__);
    }
    return temp_band;
}
BOOL quec_mult_hardware_det(char *file_name,UINT32 *pdata,UINT32 file_size)
{
   char pose,parm_num;
   BOOL retVal;
   UINT32 nvm_size=0;
   char temp_file_name[64]={0};
   if(file_name==NULL || pdata==NULL)
   return FALSE;
   int gpio_level=0;
    FILE_ID fileId = 0;
	void *buf = NULL;
   *(volatile UINT32* )module_det_pin_mfpr |=(0x5<<13)|(1<<7); //PULLDN INPUT GPIO32
   *(volatile UINT32* )module_det_pin_mfpr &=~(0x1<<14);
   *((volatile UINT32* )module_det_pin_register+0x60) |=(0x1<<5); 
   gpio_level=(*((volatile UINT32* )module_det_pin_register)>>5&0x01);  
   parm_num=sizeof(quec_mult_hardware)/sizeof(quec_mult_hardware_s);
   quec_mult_hardware_record.pin_level=gpio_level;
    for(pose=0;pose<parm_num;pose++)
    {
      if(!memcmp(file_name, quec_mult_hardware[pose].module_oc, strlen(quec_mult_hardware[pose].module_oc)))
      {
       if(gpio_level==quec_mult_hardware[pose].module_det_level)
       break;
      }
    }
    if(parm_num==pose)
    {
       return TRUE;
    }
    quec_mult_hardware_record.pose=pose;
    RTI_LOG("pose:%d,gpio_level=%d",pose,gpio_level);
     if(gpio_level==1)//reduce power current
     {
         *(volatile UINT32* )module_det_pin_mfpr |=(0x3<<14)|(1<<7); //PULLUP INPUT GPIO32
         *(volatile UINT32* )module_det_pin_mfpr &=~(0x1<<13);
     }

	 fileId = FDI_fopen(QUEC_RD_CUSTOMIZATION_DEFAULT_GKI, "rb");
    if(fileId != 0)
    {
        nvm_size = FDI_GetFileSize(fileId);
        FDI_fclose(fileId);
    }

    if(buf)
    {
        free(buf);
        buf = NULL;
    }

    /* If file dosn't exist, create and copy it from reliable data. */
    if(nvm_size == 0)
    {
 
		/* according to desgin when ever we will reach here we will create new files and override exsiting ones*/
			retVal = RDSaveFilesToFS(QUEC_RD_CUSTOMIZATION_DEFAULT_GKI, pdata, file_size, sizeof(UINT8));//create file
			ASSERT(retVal == TRUE);

			if(buf)
			{
			    free(buf);
			    buf = NULL;
		    }
    }
    RTI_LOG("MULT USE FILE:%s",file_name);
    return TRUE;
}
#endif


BOOL ReliableDataUnPack (BOOL IsPhase2)
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	UINT32* pRAMbuf_ori;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;
	UINT8 dbgi =0;
	UINT32 *MepEntryData = NULL;
	UINT32 *MepEntryData2 = NULL;
	UINT32 factory_len=0;

	rf_calib_status=0;

	if (IsPhase2)
	{
		//Sharon.li@20220517 CraneL 8M的项目打开factory_a和factor_b互相备份
		//4M的项目，没有factory_b 分区
		//Sharon.li@20230915 定义此宏MRD_FACTORY_MIN_SIZE，代表没有factor_b分区
		#ifndef MRD_FACTORY_MIN_SIZE
			ReliableDataVerify();
		#endif
		
		#ifndef LTEONLY_THIN  
		#ifdef ASR_PLATFORM_CRANEM
		mrd_extra_info_init(ADC_VBAT);
		RDSaveADCFileToMRD(ADC_VBAT);

		mrd_extra_info_init(ADC_RTP);
		RDSaveADCFileToMRD(ADC_RTP);	
		#endif
		#endif
	}


    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_RDATA_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
	{
	    RTI_LOG("ReliableDataUnPack: 0x%x is invalid addresss", begin);
		return RD_FAIL;
    }

    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;

	if (IsPhase2)
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack,DIAG_INFORMATION)
   		diagPrintf("RDPhase1 DDR buffer at address=[%lx],upper limit[%lx]",RD_DDR_begin,RD_DDR_end);
	}

	if(factory_flash_type==SPI_FLASH_INTERNAL)
	{
		factory_len=RD_DDR_end+4-RD_DDR_begin;

		pRAMbuf_ori=(UINT32 *)malloc(factory_len);
		if(pRAMbuf_ori)
		{
			spi_nor_do_read(RD_DDR_begin-CRANE_SPI_BASE_ADD, (unsigned int)pRAMbuf_ori, factory_len, factory_flash_type);
			RD_DDR_end=(UINT32)pRAMbuf_ori+factory_len-4;
			pRAMbuf=pRAMbuf_ori;
		}
		else
			return RD_FAIL;
	}

	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));
	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{
 		if(IsPhase2)
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStampValid,DIAG_INFORMATION)
   			diagPrintf("RD validBufferStamp OK =[%lx]",header.validBufferStamp);
		}

	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{
 		if(IsPhase2)
		{
			/*this is ok*/
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCS,DIAG_INFORMATION)
   		 	diagPrintf("RD validBufferStamp checksum is ok =[%lx]",header.validBufferStamp);
		}
	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
 		if(IsPhase2)
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStamp,DIAG_INFORMATION)
   		 	diagPrintf("RD WRONG validBufferStamp =[%lx]",header.validBufferStamp);
   		 	RTI_LOG("RD WRONG validBufferStamp =[%lx]",header.validBufferStamp);
		}

		if(factory_flash_type==SPI_FLASH_INTERNAL)
			free(pRAMbuf_ori);
		return RD_FAIL;
	}

	if(IsPhase2)
	{
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);
	}

	/* check format version in case of failure print only if we at phase2 after diag is ready */
	if(header.version != RD_FORMAT_VER && IsPhase2)
	{
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);
		 //no return since we support Legacy mode
	}

	/* check stamp in case of failure print only if we at phase2 after diag is ready */
	if ((header.validBufferStamp != VALID_BUF_STMP)&& IsPhase2 )
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersion,DIAG_INFORMATION)
   		diagPrintf("RD header.version =[%lx]",header.version);
	}

	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{
 			if(IsPhase2)
			{
			 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCheckSum,DIAG_INFORMATION)
   			 diagPrintf("RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
   			 RTI_LOG("RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
			}
			if(factory_flash_type==SPI_FLASH_INTERNAL)
				free(pRAMbuf_ori);
			return RD_FAIL;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/
		 
//		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
 	}

	pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_BUFFER_HEADER)); //skipping the buffer header
	do
	{
		UINT32 entry_size=0;
		UINT8  pad_size=0;

		memcpy(&entry,(RD_ENTRY*)pRAMbuf,sizeof(RD_ENTRY));

		pRAMbuf--;
		entry.pEntryData = (UINT32*)((UINT8*)pRAMbuf +  (sizeof(RD_ENTRY))); //update the data pointer

		entry_size = (entry.fileAndPadSize & 0x00FFFFFF);
 		pad_size = (UINT8)(((entry.fileAndPadSize & 0xFF000000) >> 24));

		/* move the pointer to next entry - the entry data was copied above ->entry*/
	    pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_ENTRY) + (entry_size));

		if (IsPhase2 )
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDo1,DIAG_INFORMATION)
   		    diagPrintf("ReliableData:Entry type:[0x%lx] exit on [0x%lx]",entry.entryType,END_BUF_STMP);
		}

 		switch(entry.entryType)
 		{
 			case IMEI_TYPE:
				if (IsPhase2)
				{
#ifdef QUECTEL_PROJECT_CUST
					if (strcmp(entry.file_name, "IMEI2.bin") == 0)
					{
						memcpy(IMEI_WEB_2, ((IMEIExtendedData *)entry.pEntryData)->DeycrptNumber, IMEI_NUMBER_SIZE);
					} else {
						memcpy(IMEI_WEB, ((IMEIExtendedData *)entry.pEntryData)->DeycrptNumber, IMEI_NUMBER_SIZE);
					}
#endif
					DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackIMEI,DIAG_INFORMATION)
	    		 	diagPrintf("skip - RD IMEI_TYPE size [%lx] was update at ReliableData Pre Phase1",entry_size);
				}
				/*IMEI is being update at ReliableDataPrePhase1
				 * this is for solving issue with COM silent reset.
				 * If only COM is reseting OBM will not copy this information
				 * so IMEI info must be kept in a retain DDR area - we keep it
				 * as const and modify it before MPU is activated */
				if (!IsPhase2)//if not phase2
				{
					fact_imei_flag=1;
					/* whether it's the second IMEI */
					if (strcmp(entry.file_name, "IMEI2.bin") == 0)
					{
 						IMEI2init(entry.pEntryData);
						if (header.version > RD_FORAMT_LGCY)
						{
 							IMEI2ExtendedInit(entry.pEntryData);
						}
					}
					else
					{
 						IMEIinit(entry.pEntryData);//default IMEI will be update in case we will not arrive here at prePhase1
						if(header.version > RD_FORAMT_LGCY)//if it's not Legacy call extended IEMI init
						{
 							IMEIExtendedInit(entry.pEntryData);
						}
					}
				}
			    break;
 			case MEP_TYPE:
				if (IsPhase2&&(rd_mep_flag==0))
				{
					fatal_printf("MEP_TYPE\r\n");
				   	DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMEP,DIAG_INFORMATION)
   	    	 	   	diagPrintf("update - RD MEP_TYPE size [%lx]",entry_size);

					if (strcmp(entry.file_name, "MEP2.bin") == 0)
					{
 						/*Fix coverity[overwrite_var]*/
						if(MepEntryData2 != NULL)
						{
 							free(MepEntryData2);
							MepEntryData2 = NULL;
						}
						// MEPInit ( (MEP_FIX *)entry.pEntryData );
						// pxxiong, save the mep entry data and handle it later
						MepEntryData2 = malloc (entry_size);
						ASSERT(MepEntryData2 != NULL);
						/* note: MepEntryData will have more data then entry data */
						memcpy(MepEntryData2, entry.pEntryData, entry_size);
					}
					else
					{
 						/*Fix coverity[overwrite_var]*/
						if(MepEntryData != NULL)
						{
 							free(MepEntryData);
							MepEntryData = NULL;
						}
						// MEPInit ( (MEP_FIX *)entry.pEntryData );
						// pxxiong, save the mep entry data and handle it later
						MepEntryData = malloc (entry_size);
						ASSERT(MepEntryData != NULL);
						/* note: MepEntryData will have more data then entry data */
						memcpy(MepEntryData, entry.pEntryData, entry_size);
					}
				}
                break;
		   	case NVM_TYPE:
  					if (IsPhase2 )
  					{
						DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackNVM,DIAG_INFORMATION)
   	    	 			diagPrintf("update - RD NVM_TYPE size [%lx]",entry_size);
						if(strcmp(entry.file_name,"GsmCalData.nvm")==0)
							rf_calib_status+=1;
						else if(strcmp(entry.file_name,"LteCalData.nvm")==0)
							rf_calib_status+=2;

						if(p_PlatformNvm->RD_LoadCalibFiles == RD_DONT_LOAD_CALIB_FILES_FROM_FALSH)
						{
 							/* Don't convert the ReliableData area to clib files -
							 *  the exisiting calib files in the NVM will be used */
   							DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCalibFromFS,DIAG_INFORMATION)
   	    	 				diagPrintf(" USE ## %s ## from NVM, DON'T LOAD from FLASH",entry.file_name);
						}
						else if(mrd_nvm_mask(entry.file_name)==TRUE)
						{
   							DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack02,DIAG_INFORMATION)
   	    	 				diagPrintf(" ## %s ## MRD MASK",entry.file_name);
						}
						else
						{
 							UINT32 file_size;
						    file_size = entry_size - pad_size;

#if QUEC_MULT_HARDWARE_SUPPORT
                            if((memcmp(entry.file_name,QUEC_RD_CUSTOMIZATION_DEFAULT_GKI,strlen(QUEC_RD_CUSTOMIZATION_DEFAULT_GKI))!=0)
                            &&(memcmp(entry.file_name,QUEC_RD_CUSTOMIZATION_DATA_GKI,strlen(QUEC_RD_CUSTOMIZATION_DATA_GKI))==0))
                            {
                                if(quec_mult_hardware_det(entry.file_name,entry.pEntryData,file_size)==TRUE)
                                {
                                   break;
                                } 
                            }
#endif
				   			retVal = RDSaveFilesToFS(entry.file_name, entry.pEntryData ,file_size,sizeof(UINT8) );//create file
				   			ASSERT(retVal == TRUE);
						}
					}
			    break;
			case GEN_DATA_TYPE:
			    if (IsPhase2)
                    RDHandleGenData((const char *)entry.file_name, entry.pEntryData, entry_size - pad_size);
				break;
			//case RESERVED_TYPE:
			case MRD_BTID_TYPE:
                if(IsPhase2) {
					#ifdef BT_SUPPORT
                    BtIDInit(entry.pEntryData);
					#endif
                }
                break;
			case SERIAL_NUM_TYPE:
				if (IsPhase2)
				{
#ifdef QUECTEL_PROJECT_CUST

					if (strcmp(entry.file_name,SERIAL2_NUM_FILE_NAME) == 0)
					{
						snprintf(QUEC_SN_1, sizeof(QUEC_SN_1), "%s", (const char *)entry.pEntryData);
					}
					else if(entry_size - pad_size > 0)
					{
				  		snprintf(QUEC_SN, sizeof(QUEC_SN), "%s", (const char *)entry.pEntryData);
					}
#endif
                    UINT32 file_size = 0;
                    char *saved_sn;
                    file_size = entry_size - pad_size;
                    if (file_size > 0)
                    {
                        snprintf(gSerialNumber, sizeof(gSerialNumber) - 1, "%s", (const char *)entry.pEntryData);
                        saved_sn = psm_get_wrapper("sysinfo", NULL, "serial_number");
                        if (saved_sn && strncmp(saved_sn, "", 1))
                        {
                            if (strcmp(gSerialNumber, saved_sn))
                            {
                                psm_set_wrapper("sysinfo", NULL, "serial_number", gSerialNumber);
                                psm_commit__();
                            }
                        }
                        else
                        {
                            psm_set_wrapper("sysinfo", NULL, "serial_number", gSerialNumber);
                            psm_commit__();
                        }
                        if (saved_sn)
                        {
                            free(saved_sn);
                            saved_sn = NULL;
                        }
                    }
				   DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackSN_1,DIAG_INFORMATION)
   	    	 	   diagPrintf("update - RD SERIAL_NUM_TYPE size [%lx]",entry_size);
				   DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackSN_2,DIAG_INFORMATION)
				   diagPrintf("update - RD SERIAL_NUM_TYPE buffer address [%lx]",pRAMbuf);
				}
				break;
			case MRD_WIFIMAC_TYPE:
                {
                    if(IsPhase2)
                    {
                        UINT32 file_size = 0;
                        file_size = entry_size - pad_size;
                        memcpy(gWifiMACAddr, entry.pEntryData, 6);
                        fatal_printf("WIFIMAC %02x:%02x:%02x:%02x:%02x:%02x\r\n", gWifiMACAddr[0],gWifiMACAddr[1],gWifiMACAddr[2],
                                    gWifiMACAddr[3],gWifiMACAddr[4],gWifiMACAddr[5]);
                    }
                    break;
                }
		   	default:
                {
                    // pRAMbuf = (UINT32*)RD_DDR_end; //if we didn't find a valid entry type then no need to search any more.
                    if (IsPhase2)
                    {
                        DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack_Unhandle,DIAG_INFORMATION)
                        diagPrintf("Unhandled entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
                    }
                }
                break;
		} //switch
	}while((entry.entryType != (UINT32)END_BUF_STMP) && (pRAMbuf < (UINT32*)RD_DDR_end )); //while

	if (IsPhase2)
	{
		{
			if(MepEntryData != NULL)
			{
#ifndef REMOVE_MEP
				/* update IMEI */
				UpdateIMEI();
				DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMep,DIAG_INFORMATION)
				diagPrintf("handle the mep data in the reliable.");
				MEPInit ((MEP_FIX *)MepEntryData);
#endif
				free(MepEntryData);
	 		}

			if (MepEntryData2 != NULL)
			{
#ifndef REMOVE_MEP
	 			/* update IMEI */
				UpdateIMEI2();
				DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMep2,DIAG_INFORMATION)
				diagPrintf("handle the mep2 data in the reliable.");
				MEPInit_2 ((MEP_FIX *)MepEntryData2);
#endif
				free(MepEntryData2);
			}
		}
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDone,DIAG_INFORMATION)
		diagPrintf("RD Convert Raw Data to COM data - Done");
	}

	if(factory_flash_type==SPI_FLASH_INTERNAL)
		free(pRAMbuf_ori);

  	return RD_SUCCESS;
}

BOOL   APReliableDataGenFilter (void)
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;
	UINT8 dbgi =0;
	UINT32 *MepEntryData = NULL;
	UINT32 *MepEntryData2 = NULL;
	BOOL IsPhase2=TRUE;


    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_APRDATA_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
		return RD_FAIL;


    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;



	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{


	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{

	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
		return RD_FAIL;
	}

	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{
 			if(IsPhase2)
			{
			 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCheckSum,DIAG_INFORMATION)
   			 diagPrintf("RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
			}
			return RD_FAIL;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/

//		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
 	}

	pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_BUFFER_HEADER)); //skipping the buffer header


	do
	{
		UINT32 entry_size=0;
		UINT8  pad_size=0;

		memcpy(&entry,(RD_ENTRY*)pRAMbuf,sizeof(RD_ENTRY));

		pRAMbuf--;
		entry.pEntryData = (UINT32*)((UINT8*)pRAMbuf +  (sizeof(RD_ENTRY))); //update the data pointer

		entry_size = (entry.fileAndPadSize & 0x00FFFFFF);
 		pad_size = (UINT8)(((entry.fileAndPadSize & 0xFF000000) >> 24));

		/* move the pointer to next entry - the entry data was copied above ->entry*/
	    pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_ENTRY) + (entry_size));

		if (IsPhase2 )
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDo1,DIAG_INFORMATION)
   		    diagPrintf("ReliableData:Entry type:[0x%lx] exit on [0x%lx]",entry.entryType,END_BUF_STMP);
		}

 		switch(entry.entryType)
 		{
		   	case NVM_TYPE:

  					if (IsPhase2 )
  					{
						DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackNVM,DIAG_INFORMATION)
   	    	 			diagPrintf("update - RD NVM_TYPE size [%lx]",entry_size);

						if(p_PlatformNvm->RD_LoadCalibFiles == RD_DONT_LOAD_CALIB_FILES_FROM_FALSH)
						{
 							/* Don't convert the ReliableData area to clib files -
							 *  the exisiting calib files in the NVM will be used */
   							DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCalibFromFS,DIAG_INFORMATION)
   	    	 				diagPrintf(" USE ## %s ## from NVM, DON'T LOAD from FLASH",entry.file_name);
						}
						else
						{
 							UINT32 file_size;

						    file_size = entry_size - pad_size;

							if(strcmp(entry.file_name,"FilterList.txt")==0)
							{
//					   			retVal = RDSaveFilesToFS(entry.file_name, entry.pEntryData ,file_size,sizeof(UINT8) );//create file
//					   			ASSERT(retVal == TRUE);

								filter_list_buf=(char*)malloc(file_size+1);
								memcpy(filter_list_buf,entry.pEntryData,file_size);
								filter_list_buf[file_size]=0;

							}
						}
					}

			break;

		   	default:
		   	{
		   		// pRAMbuf = (UINT32*)RD_DDR_end; //if we didn't find a valid entry type then no need to search any more.
				if (IsPhase2)
				{
				    DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack_Unhandle,DIAG_INFORMATION)
				    diagPrintf("Unhandled entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
				}
		   	}
		   	break;

		} //switch
	}while((entry.entryType != (UINT32)END_BUF_STMP) && (pRAMbuf < (UINT32*)RD_DDR_end )); //while







  	return RD_SUCCESS;
}




BOOL   APReliableDataUnPack ( BOOL IsPhase2 )
{
	UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
	UINT32* pRAMbuf;
	RD_BUFFER_HEADER header ={0};
	RD_ENTRY entry ={0};
	UINT32 checksum;
	BOOL retVal;
	UINT8 dbgi =0;
	UINT32 *MepEntryData = NULL;
	UINT32 *MepEntryData2 = NULL;

    // This should be aligned with the TIM, as OBM places RDA according to TIM.
	//getAppComShareMemAddr(&begin, &end); // old location.
	getAppCom_APRDATA_MemAddr(&begin, &end); // new location.

	if (begin == INVALID_ADDRESS)
	{
	    RTI_LOG("APReliableDataUnPack: 0x%x is invalid addresss", begin);
		return RD_FAIL;
    }

    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

	pRAMbuf = (UINT32*)(RD_DDR_begin) ;

	if (IsPhase2)
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack,DIAG_INFORMATION)
   		diagPrintf("RDPhase1 DDR buffer at address=[%lx],upper limit[%lx]",RD_DDR_begin,RD_DDR_end);
	}

	memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


	if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
	{
 		if(IsPhase2)
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStampValid,DIAG_INFORMATION)
   			diagPrintf("RD validBufferStamp OK =[%lx]",header.validBufferStamp);
		}

	}
	else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
	{
 		if(IsPhase2)
		{
			/*this is ok*/
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCS,DIAG_INFORMATION)
   		 	diagPrintf("RD validBufferStamp checksum is ok =[%lx]",header.validBufferStamp);
		}
	}
	else //if we here is not a valid buffer stamp and not a valid check sum
	{
 		if(IsPhase2)
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackStamp,DIAG_INFORMATION)
   		 	diagPrintf("RD WRONG validBufferStamp =[%lx]",header.validBufferStamp);
   		 	RTI_LOG("AP RD WRONG validBufferStamp =[%lx]",header.validBufferStamp);
		}

		return RD_FAIL;
	}


	if(IsPhase2)
	{
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);

	}



	/* check format version in case of failure print only if we at phase2 after diag is ready */
	if(header.version != RD_FORMAT_VER && IsPhase2)
	{
		 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersionFail,DIAG_INFORMATION)
   		 diagPrintf("RD header version doesn't fit =[%lx] vs.[%lx]",header.version,RD_FORMAT_VER);
		 //no return since we support Legacy mode
	}

	/* check stamp in case of failure print only if we at phase2 after diag is ready */
	if ((header.validBufferStamp != VALID_BUF_STMP)&& IsPhase2 )
	{
		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackVersion,DIAG_INFORMATION)
   		diagPrintf("RD header.version =[%lx]",header.version);
	}

	/*if we did check sum verification don't do it again*/
	if (header.validBufferStamp != VALID_CS_OK)
	{
 		/* Checksum is done in Phase1 and
		 * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
		 * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
		checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

		/* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
		if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
		{
 			if(IsPhase2)
			{
			 DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCheckSum,DIAG_INFORMATION)
   			 diagPrintf("RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
   			 RTI_LOG("AP RD WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
			}
			return RD_FAIL;
		}
		/* update the buffer valid stamp -
		 * the check sum is ok if we here.
		 * For next time we will not do checkSum.
		 * this was done in ReliableDataPrePhase1
		 * ( modify the valid buf stamp to other signature)*/

//		*(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
 	}

	pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_BUFFER_HEADER)); //skipping the buffer header


	do
	{
		UINT32 entry_size=0;
		UINT8  pad_size=0;

		memcpy(&entry,(RD_ENTRY*)pRAMbuf,sizeof(RD_ENTRY));

		pRAMbuf--;
		entry.pEntryData = (UINT32*)((UINT8*)pRAMbuf +  (sizeof(RD_ENTRY))); //update the data pointer

		entry_size = (entry.fileAndPadSize & 0x00FFFFFF);
 		pad_size = (UINT8)(((entry.fileAndPadSize & 0xFF000000) >> 24));

		/* move the pointer to next entry - the entry data was copied above ->entry*/
	    pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_ENTRY) + (entry_size));

		if (IsPhase2 )
		{
			DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDo1,DIAG_INFORMATION)
   		    diagPrintf("ReliableData:Entry type:[0x%lx] exit on [0x%lx]",entry.entryType,END_BUF_STMP);
		}

 		switch(entry.entryType)
 		{
 			case IMEI_TYPE:

				if (IsPhase2)
				{
				    uart_printf("IMEI_TYPE\r\n");
					DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackIMEI,DIAG_INFORMATION)
	    		 	diagPrintf("skip - RD IMEI_TYPE size [%lx] was update at ReliableData Pre Phase1",entry_size);
				}
				/*IMEI is being update at ReliableDataPrePhase1
				 * this is for solving issue with COM silent reset.
				 * If only COM is reseting OBM will not copy this information
				 * so IMEI info must be kept in a retain DDR area - we keep it
				 * as const and modify it before MPU is activated */
				if(fact_imei_flag==0)	//if (!IsPhase2)//if not phase2
				{
					rd_imei_flag=1;
					/* whether it's the second IMEI */
					if (strcmp(entry.file_name, "IMEI2.bin") == 0)
					{
 						IMEI2init(entry.pEntryData);
						if (header.version > RD_FORAMT_LGCY)
						{
 							IMEI2ExtendedInit(entry.pEntryData);
						}
					}
					else
					{
 						IMEIinit(entry.pEntryData);//default IMEI will be update in case we will not arrive here at prePhase1

						if( header.version > RD_FORAMT_LGCY)//if it's not Legacy call extended IEMI init
						{
 							IMEIExtendedInit(entry.pEntryData);
						}
					}
				}

			break;
#if 	1
 			case MEP_TYPE:

				if (IsPhase2)
				{
					uart_printf("MEP_TYPE\r\n");
				   	DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMEP,DIAG_INFORMATION)
   	    	 	   	diagPrintf("update - RD MEP_TYPE size [%lx]",entry_size);

					rd_mep_flag=1;
					if (strcmp(entry.file_name, "MEP2.bin") == 0)
					{
 						/*Fix coverity[overwrite_var]*/
						if(MepEntryData2 != NULL)
						{
 							free(MepEntryData2);
							MepEntryData2 = NULL;
						}

						// MEPInit ( (MEP_FIX *)entry.pEntryData );
						// pxxiong, save the mep entry data and handle it later
						MepEntryData2 = malloc (entry_size);
						ASSERT(MepEntryData2 != NULL);

						/* note: MepEntryData will have more data then entry data */
						memcpy(MepEntryData2, entry.pEntryData, entry_size);
					}
					else
					{
 						/*Fix coverity[overwrite_var]*/
						if(MepEntryData != NULL)
						{
 							free(MepEntryData);
							MepEntryData = NULL;
						}

						// MEPInit ( (MEP_FIX *)entry.pEntryData );
						// pxxiong, save the mep entry data and handle it later
						MepEntryData = malloc (entry_size);
						ASSERT(MepEntryData != NULL);

						/* note: MepEntryData will have more data then entry data */
						memcpy(MepEntryData, entry.pEntryData, entry_size);
					}
				}

	  		break;
#endif
            case EMPTY_TYPE:
                    if(strcmp(entry.file_name, IMS_CFG_FILE) != 0)
                    {
                        RTI_LOG("Unknown empty entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
                        break;
                    }
		   	case NVM_TYPE:

  					if (IsPhase2 )
  					{
  					    uart_printf("NVM_TYPE\r\n");
						DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackNVM,DIAG_INFORMATION)
   	    	 			diagPrintf("update - RD NVM_TYPE size [%lx]",entry_size);

						if(p_PlatformNvm->RD_LoadCalibFiles == RD_DONT_LOAD_CALIB_FILES_FROM_FALSH)
						{
 							/* Don't convert the ReliableData area to clib files -
							 *  the exisiting calib files in the NVM will be used */
   							DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackCalibFromFS,DIAG_INFORMATION)
   	    	 				diagPrintf(" USE ## %s ## from NVM, DON'T LOAD from FLASH",entry.file_name);
						}
						else if(mrd_nvm_mask(entry.file_name)==TRUE)
						{
   							DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack02,DIAG_INFORMATION)
   	    	 				diagPrintf(" ## %s ## MRD MASK",entry.file_name);
						}
						else
						{
						    FILE_ID fileId = 0;
 							UINT32 file_size = 0, nvm_size = 0;
 							void *buf = NULL;

						    file_size = entry_size - pad_size;

                            buf = parse_compressed_file_name(entry.file_name);

#if QUEC_MULT_HARDWARE_SUPPORT
                            if((buf==NULL) && (memcmp(entry.file_name,QUEC_RD_CUSTOMIZATION_DEFAULT_GKI,strlen(QUEC_RD_CUSTOMIZATION_DEFAULT_GKI))!=0)
                            &&(memcmp(entry.file_name,QUEC_RD_CUSTOMIZATION_DATA_GKI,strlen(QUEC_RD_CUSTOMIZATION_DATA_GKI))==0))
                            {
                                if(quec_mult_hardware_det(entry.file_name,entry.pEntryData,file_size)==TRUE)
                                {
                                   break;
                                } 
                            }
#endif
						    fileId = FDI_fopen(((buf == NULL) ? entry.file_name : buf), "rb");
                            if(fileId != 0)
                            {
                                nvm_size = FDI_GetFileSize(fileId);
                                FDI_fclose(fileId);
                            }

                            if(buf)
                            {
                                free(buf);
                                buf = NULL;
                            }

						    /* If file dosn't exist, create and copy it from reliable data. */
                            if((nvm_size == 0)||(!memcmp(entry.file_name, IMS_CFG_FILE, strlen(IMS_CFG_FILE))))
                            {
                                buf = parse_compressed_file(entry.file_name, entry.pEntryData, (size_t *)&file_size);

    							/* according to desgin when ever we will reach here we will create new files and override exsiting ones*/
    				   			retVal = RDSaveFilesToFS(entry.file_name, ((buf == NULL) ? entry.pEntryData : buf), file_size, sizeof(UINT8));//create file
    				   			ASSERT(retVal == TRUE);

    				   			if(buf)
    				   			{
    				   			    free(buf);
    				   			    buf = NULL;
				   			    }
                            }
						}
					}

			break;
			case GEN_DATA_TYPE:
			    if (IsPhase2)
			    {
			        uart_printf("GEN_DATA_TYPE\r\n");
			        RDHandleGenData((const char *)entry.file_name, entry.pEntryData, entry_size - pad_size);
		        }
				break;

			//case RESERVED_TYPE:
			case MRD_BTID_TYPE:
				break;

			case SERIAL_NUM_TYPE:
				if (IsPhase2)
				{
                    UINT32 file_size = 0;
                    char *saved_sn;

                    uart_printf("SERIAL_NUM_TYPE\r\n");

                    file_size = entry_size - pad_size;

                    if (file_size > 0)
                    {
                        snprintf(gSerialNumber, sizeof(gSerialNumber) - 1, "%s", (const char *)entry.pEntryData);
                        saved_sn = psm_get_wrapper("sysinfo", NULL, "serial_number");
                        if (saved_sn && strncmp(saved_sn, "", 1))
                        {
                            if (strcmp(gSerialNumber, saved_sn))
                            {
                                psm_set_wrapper("sysinfo", NULL, "serial_number", gSerialNumber);
                                psm_commit__();
                            }
                        }
                        else
                        {
                            psm_set_wrapper("sysinfo", NULL, "serial_number", gSerialNumber);
                            psm_commit__();
                        }
                        if (saved_sn)
                        {
                            free(saved_sn);
                            saved_sn = NULL;
                        }
                    }
                    DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackSN_1,DIAG_INFORMATION)
                    diagPrintf("update - RD SERIAL_NUM_TYPE size [%lx]",entry_size);

                    DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackSN_2,DIAG_INFORMATION)
                    diagPrintf("update - RD SERIAL_NUM_TYPE buffer address [%lx]",pRAMbuf);
				}
				break;

			case (UINT32)MRD_SIMKEY_TYPE:
			    uart_printf("MRD_SIMKEY_TYPE\r\n");
			    setSimEncrptKey((char *)entry.pEntryData);
			    break;
		   	default:
		   	{
		   		// pRAMbuf = (UINT32*)RD_DDR_end; //if we didn't find a valid entry type then no need to search any more.
				if (IsPhase2)
				{
				    if(entry.entryType != END_BUF_STMP)
				    {
				        RTI_LOG("Unknown entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
				    }
				    DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPack_Unhandle,DIAG_INFORMATION)
				    diagPrintf("Unhandled entry: type: 0x%lx, name: %s", entry.entryType, entry.file_name);
				}
		   	}
		   	break;

		} //switch
	}while((entry.entryType != (UINT32)END_BUF_STMP) && (pRAMbuf < (UINT32*)RD_DDR_end )); //while

	if (IsPhase2)
	{
		{
			if(MepEntryData != NULL)
			{
#ifndef REMOVE_MEP			
	 			uart_printf("UpdateIMEI\r\n");
				/* update IMEI */
				UpdateIMEI();

				DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMep,DIAG_INFORMATION)
				diagPrintf("handle the mep data in the reliable.");

				uart_printf("handle the mep data in the reliable.\n");
				MEPInit ((MEP_FIX *)MepEntryData);
#endif
				free(MepEntryData);
	 		}

			if (MepEntryData2 != NULL)
			{
#ifndef REMOVE_MEP
				uart_printf("UpdateIMEI2\r\n");

	 			/* update IMEI */
				UpdateIMEI2();

				DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackMep2,DIAG_INFORMATION)
				diagPrintf("handle the mep2 data in the reliable.");

				uart_printf("handle the mep2 data in the reliable.\r\n");
				MEPInit_2 ((MEP_FIX *)MepEntryData2);
#endif
				free(MepEntryData2);
			}

		}

		DIAG_FILTER(SW_PLAT,RDA,ReliableDataUnPackDone,DIAG_INFORMATION)
		diagPrintf("RD Convert Raw Data to COM data - Done");
	}


  	return RD_SUCCESS;
}

BOOL   APReliableDataClean( void )
{
    UINT32 begin,end,RD_DDR_begin,RD_DDR_end;
    UINT32* pRAMbuf;
    RD_BUFFER_HEADER header ={0};
    RD_ENTRY entry ={0};
    UINT32 checksum;
    BOOL retVal;
    UINT8 dbgi =0;
    UINT32 *MepEntryData = NULL;
    UINT32 *MepEntryData2 = NULL;


    // This should be aligned with the TIM, as OBM places RDA according to TIM.
    //getAppComShareMemAddr(&begin, &end); // old location.
    getAppCom_APRDATA_MemAddr(&begin, &end); // new location.

    if (begin == INVALID_ADDRESS)
    {
        DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanAddrValid,DIAG_INFORMATION)
        diagPrintf("AP RD CL invalid addresss 0x%x]",begin);
        //RTI_LOG("APReliableDataClean: 0x%x is invalid addresss", begin);
        return RD_FAIL;
    }

    //RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)+ RD_DDR_OFFSET); //old location
    RD_DDR_begin = (UINT32)(ADDR_CONVERT(begin)); //new location - in the new location RDA start from the beging
    RD_DDR_end   = (UINT32)ADDR_CONVERT(end);   //to avoid compile warning only

    pRAMbuf = (UINT32*)(RD_DDR_begin) ;


    memcpy(&header,(RD_BUFFER_HEADER*)pRAMbuf,sizeof(RD_BUFFER_HEADER));


    if (header.validBufferStamp == VALID_BUF_STMP) // is this valid buffer stamp
    {

        DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanStampValid,DIAG_INFORMATION)
        diagPrintf("AP RD CL validBufferStamp OK =[%lx]",header.validBufferStamp);


    }
    else if( header.validBufferStamp == VALID_CS_OK)//is check sum was done
    {

        /*this is ok*/
        DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanCS,DIAG_INFORMATION)
        diagPrintf("AP RD CL validBufferStamp checksum is ok =[%lx]",header.validBufferStamp);

    }
    else //if we here is not a valid buffer stamp and not a valid check sum
    {

        DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanStamp,DIAG_INFORMATION)
        diagPrintf("AP RD CL WRONG validBufferStamp =[%lx]",header.validBufferStamp);
        //RTI_LOG("AP RD CL WRONG validBufferStamp =[%lx]",header.validBufferStamp);
        return RD_FAIL;
    }


    /*if we did check sum verification don't do it again*/
    if (header.validBufferStamp != VALID_CS_OK)
    {
        /* Checksum is done in Phase1 and
         * - on checksum match header.validBufferStamp is set to VALID_CS_OK;
         * - on mismatch checksum is re-calculated in Phase2 and mismatch is reported with expected and actul values */
        checksum = ReliableDataCalculateCheckSum(pRAMbuf,(UINT32*)RD_DDR_end);

        /* Bypass CRC check on RDA files created by legacy tool version: had issues with CRC in misaligned cases */
        if ((header.bufCheckSum != checksum) && (header.version > RD_FORAMT_LGCY))
        {

             DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanCheckSum,DIAG_INFORMATION)
             diagPrintf("AP RD CL WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
             //RTI_LOG("AP RD CL WRONG header.bufCheckSum [%lx] != [%lx]",header.bufCheckSum,checksum);
             return RD_FAIL;
        }
        /* update the buffer valid stamp -
         * the check sum is ok if we here.
         * For next time we will not do checkSum.
         * this was done in ReliableDataPrePhase1
         * ( modify the valid buf stamp to other signature)*/

//      *(UINT32*)RD_DDR_begin = (UINT32)VALID_CS_OK;
    }

    pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_BUFFER_HEADER)); //skipping the buffer header


    do
    {
        UINT32 entry_size=0;
        UINT8  pad_size=0;
        void *buf = NULL;

        
        memcpy(&entry,(RD_ENTRY*)pRAMbuf,sizeof(RD_ENTRY));

        pRAMbuf--;
        entry.pEntryData = (UINT32*)((UINT8*)pRAMbuf +  (sizeof(RD_ENTRY))); //update the data pointer

        entry_size = (entry.fileAndPadSize & 0x00FFFFFF);
        pad_size = (UINT8)(((entry.fileAndPadSize & 0xFF000000) >> 24));

        /* move the pointer to next entry - the entry data was copied above ->entry*/
        pRAMbuf = (UINT32*)(((UINT32)pRAMbuf)+sizeof(RD_ENTRY) + (entry_size));

        DIAG_FILTER(SW_PLAT,RDA,APReliableDataCleanRemove,DIAG_INFORMATION)
        diagPrintf("AP RD CL file name : %s",entry.file_name);
        //RTI_LOG("AP RD CL file name : %s",entry.file_name);
        buf = parse_compressed_file_name(entry.file_name);
        if(buf == NULL){
            FDI_remove(entry.file_name);
        }else{
            //RTI_LOG("AP RD CL buf name : %s",buf);
            FDI_remove(buf);
            free(buf);
            buf = NULL;
        }


    }while((entry.entryType != (UINT32)END_BUF_STMP) && (pRAMbuf < (UINT32*)RD_DDR_end )); //while



    return RD_SUCCESS;
}





/************************************************************************************
 * Function     : RDSaveFilesToFS
 ************************************************************************************
 *                                                                                  *
 * Description  :  create files in the FFOS FS ( WinCE /Linux/RTOS)
 *
 *
 * Input:         pFile_name - pointer to file name
 * 				  buff - pointer to file data
 * 				  size - size of data in bytes.
 * 				  element_size - size of element.
 *
 * Output:        TRUE - file was created successfuly.
 *
 *  the code here should use NVM client API to save file into FS
 *  Saving file that was extract from the buffer will be done from
 *  COM side only - meaning that it will be fit for all FS that will
 *  exist in the server side (APP side) since NVM client-server gives
 *  this generic service
 ************************************************************************************/
static BOOL RDSaveFilesToFS(RD_TCHAR *pFile_name,void *buff, size_t size,size_t element_size)
{
#if defined (NVM_INCLUDE)
    UINT32 actualSize =0;
    RD_TCHAR file_name[RD_FILE_NAME_SIZE];
    RD_FILE_ID file_id;
    RD_FILE_ID file_id_ori;
    unsigned char *buf_ori;
    unsigned int bypass=0;

    strcpy(file_name, pFile_name);

#if defined(RD_DEBUG)
    /* save the files in FS with prefix char 'TEST' to indicate test*/
    file_name[0]='T';
    file_name[1]='E';
    file_name[2]='S';
    file_name[3]='T';
#endif

    DIAG_FILTER(SW_PLAT,RDA,RDSaveFilesToFSOpen,DIAG_INFORMATION)
    diagPrintf("RD save data to file (open)");

    uart_printf("RD save %s to FS\r\n", pFile_name);

    buf_ori = (unsigned char*)malloc(size * element_size);

    if(buf_ori == NULL)
    {
        ASSERT(0);
    }

    file_id_ori = FDI_fopen(file_name, (char*)"rb");

    if(file_id_ori!=0)
    {
        actualSize = FDI_fread((UINT8*)buf_ori, element_size, size, file_id_ori);

        FDI_fclose(file_id_ori);

        if(memcmp(buf_ori, buff, element_size * size)==0)
        {
        	bypass=1;
        }

        if(bypass==1)
        {
            uart_printf("%s same not copy\r\n", pFile_name);
            free(buf_ori);
            return RD_SUCCESS;
        }
        else
        {
            uart_printf("%s different copy\r\n", pFile_name);
        }
    }

    file_id = FDI_fopen(file_name, (char*)"wb");

    if (file_id == 0)
    {
        DIAG_FILTER(SW_PLAT,RDA,RDSaveFilesToFSFail,DIAG_INFORMATION)
        diagPrintf("RD save data to file (open fail)");

        free(buf_ori);
        return RD_FAIL;
    }

    memcpy(buf_ori, buff, element_size * size);
    actualSize = FDI_fwrite((UINT8*)buf_ori, size, element_size, file_id);

    ASSERT(actualSize > 0);

    FDI_fclose(file_id);

    DIAG_FILTER(SW_PLAT,RDA,RDSaveFilesToFSClose,DIAG_INFORMATION)
    diagPrintf("RD save data to file (close)");

    free(buf_ori);
    return RD_SUCCESS;
#else
    DIAG_FILTER(SW_PLAT,RDA,RDSaveFilesToFSFail,DIAG_INFORMATION)
    diagPrintf("RD save data to file (open fail)");
    return RD_FAIL;
#endif
}
/************************************************************************************
 * Function     : ReliableDataCalculateCheckSum
 ************************************************************************************
 *                                                                                  *
 * Description  :  calculate 32b check sum
 * An Adler-32 checksum is obtained by calculating two 16-bit checksums A and B
 * and concatenating their bits into a 32-bit integer. A is the sum of all bytes
 * in the string plus one, and B is the sum of the individual values of A from
 * each step.At the beginning of an Adler-32 run, A is initialized to 1, B to 0.
 * The sums are done modulo 65521 (the largest prime number smaller than 216).
 * The bytes are stored in network order (big endian),
 * B occupying the two most significant bytes.
 * The magic value 5550 is the largest number of sums that can be performed
 * without overflowing.
 *
 * Input: pBuf - pointer to the data buffer
 *
 * OutPut: UINT32 check sum value
 *
 *************************************************************************************/
static UINT32 	ReliableDataCalculateCheckSum(UINT32 *pBuf,UINT32 *pRD_DDR_end)
{
#define MOD_ADLER 65521
#define MOD_LOOPS 5550
   UINT32 check_sum =0;
   UINT8* pRAMbuf = (UINT8*)pBuf;
   UINT32 a = 1,b = 0,index=0;


   UINT32 addr;

   check_sum = 0;

   pRAMbuf +=8;//skip the valid stamp & checksum field

  do
   {
	  //Adler32 Checksum
        a += (UINT32)(*pRAMbuf++);
		index++;
        b += a;
		/*
	       Algorithm is defined as mod MOD_ADLER at every modification to a and b.
	       For efficiency reasons this mod can be done once in a while to keep (a) and (b) in range (32-bit signed)
	       The result is invariant of MOD_LOOPS value.
		   a<5550*256; b<(5551*256/2)*5550=3943430400 (in range)
		 */
		if(index == MOD_LOOPS)
		{
			index =0;
			a %= MOD_ADLER;
			b %= MOD_ADLER;
		}
	   // TBD: MISALIGNED 32-BIT ACCESS HERE AT EVERY BYTE ADDRESS, VERY INEFFICIENT & REDUNDANT
       // Kept here for now for compatibility with old version of the tool that produces RDA with DADADADA at misaligned offset

	   addr=(UINT32)pRAMbuf;
		addr&=~0x3;

   } while( *(UINT32*)addr != (UINT32)END_BUF_STMP && (pRAMbuf < (UINT8*)pRD_DDR_end ));

   if(index)
   {
		a %= MOD_ADLER;
		b %= MOD_ADLER;
   }

   check_sum =  (b << 16) | a;

   return (check_sum);
}

/*
 * IMEI.nvm is used to save the last used IMEI in the phone.
 * If the IMEI was changed, this IMEI file must be updated.
 */
#define IMEI_NVM	"IMEI.nvm"
#define IMEI2_NVM	"IMEI2.nvm"
#define MEP_NVM		"MEP.nvm"
#define MEP2_NVM	"MEP2.nvm"

#define NVM_HEAD_SET_STRING(header,field,value) \
   strncpy(header.field,value,sizeof(header.field)-1)

int UpdateIMEI(void)
{
	FILE_ID 			fd;
	FILE_INFO			info;
	UINT32 				length;
	NVM_Header_ts		header;

	IMEIData            imei, localIMEI;


	/** IMEI1 **/
	IMEIRead(&localIMEI);

	fd = FDI_fopen(IMEI_NVM, "rb");
	if (fd != 0)
	{
 		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		/* read structure */
		length = FDI_fread((void *)(&imei), sizeof(imei), 1, fd);
		/* close file */
		FDI_fclose(fd);

		if (length == 1)
		{
 			if (memcmp(imei.digits, localIMEI.digits, sizeof(imei.digits)) == 0)
			{
 				/* the IMEI is the same, return it */
				log_printf("IMEI is the same.\n");
				return 0;
			}
		}
	}


	/* remove mep.nvm file */
	log_printf("remove MEP.nvm\n");
	FDI_remove(MEP_NVM);
	/* use the local IMEI */
	memcpy(&imei, &localIMEI, sizeof(imei));

	/* write diag cfg */
	fd = FDI_fopen(IMEI_NVM, "wb");
	if (fd != 0)
	{
		/* write structure header */
		memset(&header, 0x0, sizeof(header));
		header.StructSize = sizeof(imei);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"IMEIData");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

		FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		/* write structure */
		FDI_fwrite((void*)&imei, sizeof(imei), 1, fd);
		/* close file */
		FDI_fclose(fd);


		return 0;
	}


	/*Fix coverity[missing_return]*/
	return -1;

}

void UpdateIMEI2(void)
{
	FILE_ID 			fd;
	FILE_INFO			info;
	UINT32 				length;
	NVM_Header_ts		header;

	IMEIData            imei, localIMEI;

	/** IMEI2 **/
	IMEI2Read(&localIMEI);

	fd = FDI_fopen(IMEI2_NVM, "rb");
	if (fd != 0)
	{
		/* read structure header */
		length = FDI_fread((void *)(&header), sizeof(NVM_Header_ts), 1, fd);
		/* read structure */
		length = FDI_fread((void *)(&imei), sizeof(imei), 1, fd);
		/* close file */
		FDI_fclose(fd);

		if (length == 1)
		{
			if (memcmp(imei.digits, localIMEI.digits, sizeof(imei.digits)) == 0)
			{
				/* the IMEI is the same, return it */
				log_printf("IMEI2 is the same.\n");
				return;
			}
		}
	}

	/* remove mep.nvm file */
	log_printf("remove MEP2.nvm\n");
	FDI_remove(MEP2_NVM);
	/* use the local IMEI */
	memcpy(&imei, &localIMEI, sizeof(imei));

	/* write diag cfg */
	fd = FDI_fopen(IMEI2_NVM, "wb");
	if (fd != 0)
	{
		/* write structure header */
		memset(&header, 0x0, sizeof(header));
		header.StructSize = sizeof(imei);
		header.NumofStructs = 1;
		NVM_HEAD_SET_STRING(header,StructName,"IMEIData");
		NVM_HEAD_SET_STRING(header,Date,"");
		NVM_HEAD_SET_STRING(header,time,"");
		NVM_HEAD_SET_STRING(header,Version,"1.0");
		NVM_HEAD_SET_STRING(header,HW_ID,"");
		NVM_HEAD_SET_STRING(header,CalibVersion,"");

		FDI_fwrite(&header, sizeof(NVM_Header_ts), 1, fd);

		/* write structure */
		FDI_fwrite((void*)&imei, sizeof(imei), 1, fd);
		/* close file */
		FDI_fclose(fd);
	}

	return;
}

/************************************************************************************
 * Function     : RDTest
 ************************************************************************************
 *                                                                                  *
 * Description  : test														        *
 *                                                                                  *
 * Input:         void											                    *
 *                                                                                  *
 * Output:        															        *
 ************************************************************************************/
//ICAT EXPORTED FUNCTION - ReliableData,TEST,RDTest
void RDTest (void *p)
{
	BOOL  param = RD_PHASE2;
	if( p )
	   param = *( UINT8 *)p;

	ReliableDataUnPack(param);
}

char *getSerialNumber(void)
{
    return gSerialNumber;
}
