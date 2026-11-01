//PPC Version : V2.1.9.30
//PPL Source File Name : \tavor\Arbel\obj_PMD2NONE\prepass_results\usbmgrttpal.ppp
//PPL Source File Name : \\tavor\\Arbel\\src\\usbmgrttpal.c
typedef unsigned int size_t ;
typedef unsigned char Char ;
typedef unsigned char Int8 ;
typedef signed char SignedInt8 ;
typedef unsigned short Int16 ;
typedef signed short SignedInt16 ;
typedef unsigned long Int32 ;
typedef signed long SignedInt32 ;
typedef Int8 Boolean ;
typedef SignedInt8 TP_SInt8 ;
typedef SignedInt16 TP_SInt16 ;
typedef SignedInt32 TP_SInt32 ;
typedef Int8 TP_UInt8 ;
typedef Int16 TP_UInt16 ;
typedef Int32 TP_UInt32 ;
typedef Boolean TP_Boolean ;
typedef char * TP_String ;
typedef char TP_Char ;
typedef TP_UInt16 TP_WChar ;
typedef TP_WChar TP_TChar ;
typedef union SysBasicTypesUnionTag
 {
 Int8 int8Member ;
 SignedInt8 signedInt8Member ;
 Int16 int16Member ;
 SignedInt16 signedInt16Member ;
 Int32 int32Member ;
 SignedInt32 signedInt32Member ;
 Boolean booleanMember ;
 void *pointerMember ;

 TP_SInt8 tp_SInt8Member ;
 TP_SInt16 tp_SInt16Member ;
 TP_SInt32 tp_SInt32Member ;
 TP_UInt8 tp_UInt8Member ;
 TP_UInt16 tp_UInt16Member ;
 TP_UInt32 tp_UInt32Member ;
 TP_Boolean tp_BooleanMember ;
 TP_String tp_StringMember ;
 TP_Char tp_CharMember ;
 TP_WChar tp_WCharMember ;
 TP_TChar tp_TCharMember ;
 } SysBasicTypesUnion ;
typedef unsigned char BOOL ;
typedef unsigned char UINT8 ;
typedef unsigned short UINT16 ;
typedef unsigned long UINT32 ;
typedef char CHAR ;
typedef signed char INT8 ;
typedef signed short INT16 ;
typedef signed long INT32 ;
typedef unsigned char Bool ;
typedef UINT8 BYTE ;
typedef UINT8 UBYTE ;
typedef UINT16 UWORD ;
typedef UINT16 WORD ;
typedef INT16 SWORD ;
typedef UINT32 DWORD ;
typedef unsigned long long UINT64 ;
typedef void* VOID_PTR ;
typedef volatile UINT8 *V_UINT8_PTR ;
typedef volatile UINT16 *V_UINT16_PTR ;
typedef volatile UINT32 *V_UINT32_PTR ;
typedef unsigned int U32Bits ;
typedef BOOL BOOLEAN ;
typedef const char * SwVersion ;
typedef void ( *TIMER_CALLBACK_FUNCTION ) ( UINT8 ) ;
typedef void ( *ACC_TIMER_CALLBACK ) ( UINT32 ) ;
typedef int TIMER_STATUS ;
typedef int TIMER_ID ;
typedef unsigned long long Ulong64 ;
//ICAT EXPORTED STRUCT 
 typedef struct 
 {	 
 UINT16 lineNo ; // CONST	 
 char idString [ 14 ] ; // CONST = 16 bytes	 
 UINT32 timeStamp ; // var	 
 UINT32 param1 ; // var	 
 UINT32 param2 ; // var	 
 UINT32 param3 ; // var	 
 } BspLogRecord;

//ICAT EXPORTED ENUM 
 typedef enum TaskIdTag /* tasks sent to identified by their task ids */ 
 {	 
 /* @ENUM_DESC@ TBD */	 
	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / kisystsk.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : System task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a	 
 ** #if !defined KISYSTSK_H	 
 ** as it can be legitimately included twice	 
 **	 
 ** This must never be included directly by any file outside of the kernel.	 
 */	 
	 
 KI_TASK_SET_START_0 = ( 0 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** External Client task Set , not for TTPCom use	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / extask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : External GKI Task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** Add ids for any tasks external to the TTPCom Product.	 
 ** ( the format is as in the comment below. )	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** Example task specification	 
 **	 
 ** Task Id Queue Id Entry Point Stack Queue Priority	 
 ** KI_TASK_DEF ( SIM_TASK_ID , SIM_QUEUE_ID , SimManagerTask , 1024 , 30 , 8 )	 
 **	 
 */	 
	 
	 
	 
	 
 PS_L2_TOOL_TASK_ID ,	 
	 
	 
	 
	 
 /*	 
 ** Create aliases for any task id handled by a GKI task.	 
 */	 
 START_EX_ALIASES ,	 
	 
 /*	 
 ** Example alias definition	 
 **	 
 ** Real Task Id Alias Task Id Alias Queue Id	 
 ** KI_ALIAS_DEF ( AL_TASK_ID , ALSM_TASK_ID , ALSM_QUEUE_ID )	 
 **	 
 ** WARNING: When using aliases the value in the enumeration must be stored	 
 ** first ( using the KI_START_ALIAS macro ) and then re-instated after	 
 ** ( using the KI_END_ALIAS macro ) the alias definition. See	 
 ** kisystsk.h as an example.	 
 **	 
 */	 
	 
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **	 
 ** Add external aliases here **	 
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */	 
	 
 STOP_EX_ALIASES = START_EX_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_0 ,	 
	 
 KI_TASK_SET_START_1 = ( 1 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** External Silicon Client task set , not for TTPCom use	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / platforms / hermon / sys / gki.typ / api / cfg / exstask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2007 / 1 / 12 13 :10:41 $	 
 **************************************************************************	 
 * File Description :	 
 * Task Definitions for the Hermon Silicon Platform	 
 **************************************************************************/	 
	 
 /*	 
 ** Add ids for any tasks external to the TTPCom Product.	 
 ** ( the format is as in the comment below. )	 
 */	 
	 
 /*	 
 ** Modifiers to TTPCom CORE task stack sizes	 
 ** The values here are ADDED to the CORE stack	 
 ** size defined in the ??task.h file	 
 */	 
	 
 // The SimDriver is using the sprintf ( ) which requires min 256 bytes on stack	 
	 
	 
 /*	 
 ** Modifiers to TTPCom CORE task queue lengths	 
 ** The values here are ADDED to the CORE queue	 
 ** size defined in the ??task.h file	 
 */	 
	 
	 
	 
 /* Modifiers to TTPCom CORE task priorities	 
 ** The values here REPLACE the CORE task	 
 ** priorities defined in the ??task.h file	 
 */	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** Example task specification	 
 **	 
 ** Task Id Queue Id Entry Point Stack Queue Priority	 
 ** KI_TASK_DEF ( SIM_TASK_ID , SIM_QUEUE_ID , SimManagerTask , 1024 , 30 , 8 )	 
 **	 
 */	 
	 
	 
	 
	 
	 
 /*	 
 to reserve a dummy SAC task id to avoid the first SAC related task id	 
 has the same number as START_AL_ALIASES	 
 */	 
 SAC_DUMMY_TASK_ID ,	 
	 
	 
	 
	 
	 
 SAC_RESERVED_TASK_ID ,	 
	 
	 
 /* SAC_TEST_TASK definition */	 
	 
	 
	 
 SAC_TEST_TASK_ID ,	 
	 
	 
 /* SAC_OSA_TASK definition */	 
	 
 SAC_OSA_TASK_ID ,	 
	 
	 
	 
	 
	 
 INTEL_NON_GKI_TASK_ID , /* Psudeo Intel task */	 
	 
	 
 HA_COMMS_TASK_ID ,	 
	 
	 
	 
	 
 /* Map HAW and AMR tasks to the UP_PHY_TASK_ID on Hermon */	 
	 
	 
	 
	 
 /*	 
 ** Create aliases for any task id handled by a GKI task.	 
 */	 
 START_EXS_ALIASES ,	 
	 
 /*	 
 ** Example alias definition	 
 **	 
 ** Real Task Id Alias Task Id Alias Queue Id	 
 ** KI_ALIAS_DEF ( AL_TASK_ID , ALSM_TASK_ID , ALSM_QUEUE_ID )	 
 **	 
 ** WARNING: When using aliases the value in the enumeration must be stored	 
 ** first ( using the KI_START_ALIAS macro ) and then re-instated after	 
 ** ( using the KI_END_ALIAS macro ) the alias definition. See	 
 ** kisystsk.h as an example.	 
 **	 
 */	 
	 
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **	 
 ** Add external aliases here **	 
 ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */	 
	 
	 
 STOP_EXS_ALIASES = START_EXS_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
	 
 KI_TASK_SET_STOP_1 ,	 
	 
 KI_TASK_SET_START_2 = ( 2 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** GKI / System Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / kitask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : GKI / System task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
 TIMER_TASK_ID ,	 
	 
	 
 TEST_TASK_ID ,	 
	 
 EMMI_LOW_PRI_TASK_ID ,	 
 EMMI_HIGH_PRI_TASK_ID ,	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_2 ,	 
	 
 KI_TASK_SET_START_3 = ( 3 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Layer 1 Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / l1task.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Layer 1 task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 LOW_PRIORITY_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 L1_PROF_TASK_ID ,	 
	 
	 
	 
	 
	 
 /* CQ00100336 - Begin */	 
 // 3 G L1C	 
	 
	 
	 
 /* CQ00100336 - End */	 
	 
	 
	 
	 
	 
	 
	 
 MINI_LOGGER_TASK_ID ,	 
 ML_SIGNAL_DUMPER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MIPS_MANAGER_TASK_ID ,	 
	 
	 
	 
	 
	 
 L1_VCXO_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_3 ,	 
	 
 KI_TASK_SET_START_4 = ( 4 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Device Management Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / dmtask.h#4 $	 
 * $Revision: #4 $	 
 * $DateTime: 2007 / 3 / 30 13 :53:25 $	 
 **************************************************************************	 
 * File Description : Device Management task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
 L1_SD_TASK_ID ,	 
	 
 L1_SD_TASK_ID2 ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 // KI_TASK_DEF ( L1_AL_TASK_ID , L1_AL_QUEUE_ID , L1AlTask , 4094 , 30 , 51 ) // CQ00136121	 
	 
	 
	 
 /* Redundant task - may be reused */	 
 L1_BM_TASK_ID ,	 
	 
 /* Redundant task - may be reused */	 
 L1_SP_TASK_ID ,	 
	 
	 
	 
	 
 L1_CTM_TASK_ID ,	 
	 
	 
 // KI_TASK_DEF ( DM_TASK_ID , DM_QUEUE_ID , DmTask , 1024 , 30 , 51 )	 
	 
	 
	 
 DTF_STIMULATE_TASK_ID ,	 
 DTF_SIMULATE_TASK_ID ,	 
	 
 DTF_SELF_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 DM_NVM_TASK_ID ,	 
	 
	 
	 
	 
	 
 DM_BM_TASK_ID ,	 
	 
	 
	 
	 
 DM_RTC_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* Use NVRAM task unless explicitly removed */	 
	 
	 
	 
 DM_NVP_TASK_ID , // CQ00146716 change 80 to 81 fo #91812 by yuling	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 USB_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 IRDA_TASK_ID ,	 
 IRDA_STACK_TASK_ID ,	 
 IRDA_FRAMER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 OBEX_TASK_ID ,	 
 OBEX_TEST_TASK_ID ,	 
	 
	 
	 
 /* A task priority of 9 is chosen as priority range 0 -9 are reserved for interrupt launched	 
 * tasks such as L1_AL_HI_TASK_ID. This task is triggered by the L1 frame interrupt and	 
 * provides a periodic tick to the L1AL layer. */	 
	 
 /* L1_AL_HI_TASK stack max usage measured at 660 on 430 gpdev build 2005 _June_08. Allow some	 
 * extra to support use of printf & other debugging => size=800 */	 
 // KI_TASK_DEF ( L1_AL_HI_TASK_ID , L1_AL_HI_QUEUE_ID , L1AlHiTask , 800 , 1 , 16 ) // CQ00136121	 
	 
	 
	 
	 
	 
	 
	 
 SIM_IF_CHECK_TASK_ID ,	 
	 
	 
	 
 /* include as part of Camera Multiplex layer Test Task */	 
	 
	 
	 
	 
	 
	 
	 
 CATT_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MP_SERIALPORT_DRV_TASK_ID ,	 
	 
	 
	 
 /* This is the USB EMMI task */	 
	 
	 
	 
 USB_EMMI_COMMS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TAC_TASK_ID ,	 
	 
	 
 START_DM_ALIASES ,	 
	 
 SIMDRV_TASK_ID = L1_SD_TASK_ID ,	 
	 
 SIMDRV_TASK_ID2 = L1_SD_TASK_ID2 ,	 
	 
	 
	 
	 
	 
 HAD_L1_SD_TASK_ID = L1_SD_TASK_ID ,	 
	 
	 
	 
	 
	 
 // KI_ALIAS_DEF ( L1_AL_TASK_ID , L1AM_TASK_ID , L1AM_QUEUE_ID ) // CQ00136121	 
	 
	 
 STOP_DM_ALIASES = START_DM_ALIASES - 1 ,	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_4 ,	 
	 
 KI_TASK_SET_START_5 = ( 5 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Protocol Stack Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / pstask.h#6 $	 
 * $Revision: #6 $	 
 * $DateTime: 2007 / 3 / 19 13 :59:30 $	 
 **************************************************************************	 
 * File Description : Protocol Stack task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deliberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
 NAS_STUB_TASK_ID ,	 
	 
	 
	 
 L2_BCH_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 L2_BCH_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 L2_DD_TASK_ID ,	 
 L2_CBCH_TASK_ID ,	 
 L2_SACCH_0_TASK_ID ,	 
 L2_SACCH_3_TASK_ID ,	 
 L2_DCCH_0_TASK_ID ,	 
 L2_DCCH_3_TASK_ID ,	 
 GRR_TASK_ID ,	 
 GRR_2_TASK_ID ,	 
	 
	 
	 
 CB_TASK_ID ,	 
	 
 CB_2_TASK_ID ,	 
	 
	 
 /*Modifed size to 5000 by Fengzhuan , CQ00023736 , 20121029 , begin*/	 
 MM_TASK_ID ,	 
 /*Modifed size to 5000 by Fengzhuan , CQ00023736 , 20121029 , end*/	 
	 
	 
 /*Modified by Hanko for CQ67542 20140808 , begin*/	 
 MM_2_TASK_ID ,	 
 /*Modified by Hanko for CQ67542 20140808 , end*/	 
	 
 /*CQ00146133 , Cgliu , 2023 -09-27 , Begin*/	 
	 
	 
 SIM_TASK_ID ,	 
	 
 SIM_2_TASK_ID ,	 
	 
	 
	 
 /*CQ00146133 , Cgliu , 2023 -09-27 , End */	 
	 
	 
 TIM_TASK_ID , // CQ00146716 // change from 55 to 81 , stack from 360 t0 1300 20231012 by yuling	 
	 
 /*Modified by fxzhang , CQ00108415 , 20171116 , begin*/	 
 // #if !defined ( UPGRADE_DSDS_EXCLUDE_SIM2_L1 )	 
 // KI_RESERVED_TASK ( TIM_2_TASK_ID , TIM_2_QUEUE_ID )	 
 // #else	 
 TIM_2_TASK_ID , // CQ00146716 // change from 55 to 81 , stack from 360 t0 1300 20231012 by yuling	 
 /*KI_RESERVED_TASK ( TIM_2_TASK_ID , TIM_2_QUEUE_ID ) */	 
 // #endif	 
 /*Modified by fxzhang , CQ00108415 , 20171116 , end*/	 
	 
	 
	 
	 
 SMTL_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
	 
 SMTL_2_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 SMCM_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
	 
 SMCM_2_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 SMRL_TASK_ID ,	 
	 
 SMRL_2_TASK_ID ,	 
	 
	 
	 
	 
 START_PS_AS_ALIASES ,	 
	 
	 
	 
 STOP_PS_AS_ALIASES = START_PS_AS_ALIASES - 1 ,	 
	 
	 
 START_PS_NAS_ALIASES ,	 
 GP_GMM_TASK_ID = MM_TASK_ID ,	 
	 
 GP_GMM_2_TASK_ID = MM_2_TASK_ID ,	 
	 
	 
	 
 GP_SMS_TASK_ID = SMCM_TASK_ID , /* To bottom SMS */	 
	 
 STOP_PS_NAS_ALIASES = START_PS_NAS_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA14_ID ,	 
	 
	 
 /*CQ00119446 add begin*/	 
	 
 VG_CI_TASK_ID ,	 
	 
	 
 /*Cat0 20160615 transient*/	 
 // KI_ALIAS_DEF ( UNKNOWNS_TASK_ID , VG_RTFDP_TASK_ID , VG_RTFDP_QUEUE_ID )	 
 VG_RTFDP_TASK_ID ,	 
	 
 PCCI_STUB_TASK_ID ,	 
 MODEM_TASK_ID ,	 
 ATPARSER_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 ATPARSER_1_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
	 
	 
	 
	 
 VG_MUX_TASK_ID ,	 
	 
	 
	 
	 
	 
 VG_MUX1_TASK_ID ,	 
	 
	 
 // MR	 
	 
	 
 VG_MUX_NULL_NOPL_TASK_ID ,	 
 // KI_TASK_DEF ( VG_MUX_NULL_NOPL_TASK_ID , VG_MUX_NULL_NOPL_QUEUE_ID , VgMux1NoPLTask , 1000 , 30 , 55 )	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_MUX2_TASK_ID ,	 
	 
	 
	 
 VG_MUX_USBNULL_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* Reduce impact on TaskID ' s next time MUX tasks have to be added */	 
 VG_MUX_SPARE1 ,	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710S_TASK_ID ,	 
	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 VG_MUX_GSM710S_1_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 START_MUX_ALIASES ,	 
	 
	 
	 
	 
	 
 VG_MUX_NULL_TASK_ID = VG_MUX1_TASK_ID ,	 
	 
 VG_DS_TASK_ID = VG_CI_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 STOP_MUX_ALIASES = START_MUX_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
	 
 CSR_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 CSR_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
	 
	 
	 
	 
 GP_MAC_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 GP_MAC_2_TASK_ID ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 GP_RD_TASK_ID ,	 
	 
 GP_RD_2_TASK_ID ,	 
	 
 GP_LLC_TASK_ID ,	 
	 
 GP_LLC_2_TASK_ID ,	 
	 
	 
	 
	 
 // KI_TASK_DEF ( GP_SNDCP_TASK_ID , GP_SNDCP_QUEUE_ID , / *GpSndcpTask* / UpUlbgTask , 900 , 1000 , 62 ) // TODO: This is a workaround!!!	 
	 
 UP_DLBG_TASK_ID ,	 
	 
 UP_DLBG_2_TASK_ID ,	 
	 
	 
 GP_SM_TASK_ID ,	 
	 
 GP_SM_2_TASK_ID ,	 
	 
	 
 /* Modified by Daniel for CQ00018823 20120605 , begin */	 
 GP_PPP_TASK_ID ,	 
 // KI_TASK_DEF ( GP_PPP_TASK_ID , GP_PPP_QUEUE_ID , GpPppTask , 2000 , 272 , 65 )	 
	 
 GP_PPP_2_TASK_ID ,	 
 // KI_TASK_DEF ( GP_PPP_2_TASK_ID , GP_PPP_2_QUEUE_ID , GpPppTask , 2000 , 272 , 65 )	 
	 
 /* Modified by Daniel for CQ00018823 20120605 , end */	 
	 
	 
	 
	 
	 
	 
	 
 UT_TMM_TASK_ID ,	 
	 
	 
 /* Only used for unit testing - reserved here to keep task IDs the same */	 
 GP_UNITTEST_TASK_ID ,	 
 /* Only used for simulation testing - reserved here to keep task IDs the same */	 
 GP_AUXRD_TASK_ID ,	 
 GP_AUXLLC_TASK_ID ,	 
 GP_AUXSNDCP_TASK_ID ,	 
 GP_PPP_DIALLER_TASK_ID ,	 
 GP_DS_DIALLER_TASK_ID ,	 
 GP_PPP_PC_COMMS_TASK_ID ,	 
 GP_PPP_PC_COMMS_DIALLER_TASK_ID ,	 
	 
	 
	 
	 
 // 20100506 hlhu: add for lte psas start	 
	 
 LTE_L1A_TASK_ID , // CQ64122	 
	 
 LTE_L1A_2_TASK_ID , /*CQ00107342 add*/	 
	 
	 
 LTE_RRC_TASK_ID ,	 
	 
	 
	 
	 
	 
 LTE_RRC_2_TASK_ID ,	 
	 
	 
	 
	 
 // KI_TASK_DEF ( LTE_L1_SIMU_TASK_ID , LTE_L1_SIMU_QUEUE_ID , tLteL1SimulatorTask , 5000 , 30 , 29 )	 
 LTE_MACRLC_TASK_ID ,	 
	 
	 
 LTE_MACRLC_2_TASK_ID ,	 
	 
 // #if defined ( UPGRADE_DSDS )	 
 // KI_TASK_DEF ( LTE_MACRLC_2_TASK_ID , LTE_MACRLC_2_QUEUE_ID , tLteMacRlcTask2 , 5000 , 600 , 30 )	 
 // #endif	 
	 
	 
	 
 PLMS_TASK_ID ,	 
	 
	 
 // #ifdef LTE_TARGET_TEST_MCU_ONLY	 
	 
	 
	 
 // added by jcweng to process the signals from Anite / TTCN2C side	 
 LTE_ANITE_ADAPOTR_TASK_ID ,	 
	 
	 
	 
 // 20100506 hlhu: add for lte psas end	 
	 
	 
	 
	 
 START_UPS_ALIASES ,	 
	 
 UP_BMC_TASK_ID = CB_TASK_ID ,	 
	 
 UP_PDCP_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
 UP_PDCP_2_TASK_ID = LTE_MACRLC_2_TASK_ID ,	 
	 
	 
	 
	 
	 
 UP_RABM_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
 UP_ULBG_TASK_ID = LTE_MACRLC_TASK_ID ,	 
 // KI_ALIAS_DEF ( LTE_MACRLC_TASK_2_ID , UP_ULBG_2_TASK_ID , UP_ULBG_2_QUEUE_ID )	 
	 
 // KI_ALIAS_DEF ( GP_SNDCP_TASK_ID , UP_ULBG_TASK_ID , UP_ULBG_QUEUE_ID ) // TODO: remove	 
	 
 UP_ULBG_2_TASK_ID = LTE_MACRLC_2_TASK_ID , // TODO: remove	 
 // KI_ALIAS_DEF ( LTE_MACRLC_2_TASK_ID , UP_PDCP_2_TASK_ID , UP_PDCP_2_QUEUE_ID )	 
 GP_SNDCP_2_TASK_ID = LTE_MACRLC_2_TASK_ID ,	 
	 
	 
	 
	 
 GP_SNDCP_TASK_ID = LTE_MACRLC_TASK_ID ,	 
	 
	 
	 
 STOP_UPS_ALIASES = START_UPS_ALIASES - 1 ,	 
	 
	 
	 
	 
	 
	 
 TASK_BL_ID , // change queue 30 by aliOS	 
	 
 TASK_BL_2_ID , // add by aliOS	 
	 
	 
 TASK_ANRM2_ID_DUMMY ,	 
 /*Modified by perse for CQ00111012 20180625 , begin*/	 
 TASK_ANRM2_ID_2_DUMMY ,	 
 /*Modified by perse for CQ00111012 20180625 , end*/	 
 START_USE_ANRM2 ,	 
 TASK_ANRM2_ID = DM_NVM_TASK_ID ,	 
 STOP_USE_ANRM2 = START_USE_ANRM2 - 1 ,	 
	 
	 
	 
 VG_MUX_IP_TRAN_TASK_ID ,	 
	 
 /* Streaming tasks */	 
	 
	 
	 
 SNTP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTSP_TASK_ID ,	 
	 
	 
	 
	 
	 
 RTP_RTSP_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_FS_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 POC_TASK_ID ,	 
	 
	 
	 
	 
	 
 SIP_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_GMX_NULL_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710E_TASK_ID ,	 
	 
	 
	 
	 
 VG_MUX_GSM710E_NOPL_TASK_ID ,	 
 // KI_TASK_DEF ( VG_MUX_GSM710E_NOPL_TASK_ID , VG_MUX_GSM710E_NOPL_QUEUE_ID , VgMux710eNoPLTask , 615 , 30 , 55 )	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 VG_MUX_GSM710SM_TASK_ID ,	 
	 
	 
	 
 // redefine pdcp task id	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 // 2017 -09-26 , WQS , move TTCN PC Test related tasks to the end for correct display in CATStudio	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_5 ,	 
	 
 KI_TASK_SET_START_6 = ( 6 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Application Layer Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / aftask.h#5 $	 
 * $Revision: #5 $	 
 * $DateTime: 2007 / 3 / 30 13 :53:25 $	 
 **************************************************************************	 
 * File Description : Application Foreground task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TCPIP_TASK_ID ,	 
	 
 BLIP_TASK_ID ,	 
 LPPP_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 WPPP_TASK_ID ,	 
	 
	 
 /* Application Layer */	 
 AAUD_TASK_ID ,	 
	 
	 
 /*remove 20220927 CQ00139071 begin*/	 
	 
 /*remove 20220927 CQ00139071 end*/	 
 TASK_DISH_ID ,	 
	 
 TASK_EXTRA2_ID ,	 
	 
 /* 20163 removed AEIT task */	 
 TASK_NOT_USED_ID ,	 
	 
 TASK_ATCV_MAILER_ID ,	 
 TASK_AL_TEST_ID ,	 
 TASK_AL_SCRIPT_ID ,	 
	 
	 
	 
	 
 TASK_AL_TEST2_ID ,	 
	 
	 
	 
	 
	 
	 
	 
 SIMAT_TASK_ID ,	 
	 
 SIMAT_2_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA4_ID ,	 
 TASK_EXTRA5_ID ,	 
	 
 /* WAP Tasks */	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA6_ID ,	 
 TASK_EXTRA7_ID ,	 
	 
	 
	 
 TASK_EXTRA8_ID ,	 
	 
	 
	 
	 
 TASK_EXTRA9_ID ,	 
	 
	 
	 
	 
	 
 MMI_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA10_ID ,	 
	 
	 
	 
	 
	 
	 
 TASK_EXTRA11_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA12_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA13_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA15_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA16_ID ,	 
	 
	 
 START_AB_ALIASES ,	 
	 
 ALSH_TASK_ID = TASK_BL_ID ,	 
 AL_TASK_ID = TASK_BL_ID ,	 
	 
	 
	 
	 
	 
 GP_ABGP_TASK_ID = TASK_BL_ID ,	 
	 
	 
	 
	 
	 
 STOP_AB_ALIASES = START_AB_ALIASES - 1 ,	 
	 
	 
	 
	 
 /*	 
 Absorb task receives signals and deletes them. Useful when a destination task is needed for IND	 
 and CNF signals.	 
 */	 
	 
	 
	 
 ABSORB_TASK_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA17_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA18_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA19_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA20_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA21_ID ,	 
	 
	 
	 
	 
	 
 TASK_EXTRA22_ID ,	 
	 
	 
	 
	 
	 
 FM_TASK_ID ,	 
	 
	 
 TASK_EXTRA23_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 SOCKTEST_TASK_ID ,	 
	 
	 
 /* Transport Task */	 
	 
	 
	 
 TRANSPORT_TASK_ID ,	 
	 
	 
	 
	 
	 
 AP_BG_TASK_ID ,	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_6 ,	 
	 
 KI_TASK_SET_START_7 = ( 7 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Mapal Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2006 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / mptask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Mapal task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
 MAPAL_TASK_ID ,	 
 MAPAL_DRIVERS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MP_RESERVED0_TASK_ID ,	 
 MP_RESERVED1_TASK_ID ,	 
	 
	 
	 
	 
	 
 MAPAL_SPAL_HF_TASK_ID ,	 
	 
	 
	 
	 
	 
 MP_RESERVED2_TASK_ID ,	 
 MP_RESERVED3_TASK_ID ,	 
	 
	 
	 
	 
 MP_TESTING_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
 MP_TARGET_DRIVER_TEST_TASK_ID ,	 
 MP_PC_AUTOTEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MP_PC_BORG_AUTOTEST_TASK_ID ,	 
 PC_DRIVER_DEBUG_TEST_TASK_ID ,	 
	 
	 
	 
 MAPAL_DPRAMHWFWD_TASK_ID ,	 
 MAPAL_COMMS_TASK_ID ,	 
 MAPAL_FWDTEST_TASK_ID ,	 
 MAPAL_LOGGING_TASK_ID ,	 
	 
	 
	 
	 
	 
 MP_GKI_TEST_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MP_ASYNC_APP1_TASK_ID ,	 
 MP_ASYNC_DRV1_TASK_ID ,	 
	 
	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_7 ,	 
	 
 KI_TASK_SET_START_8 = ( 8 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Bluetooth Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / bttask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Bluetooth task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deiberately does not have a multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 BT_SCHEDULER_TASK_ID ,	 
 BT_SCHEDULER_TEST_TASK_ID ,	 
 BT_BG_TASK_ID ,	 
 ABBT_AU_TASK_ID ,	 
 RMT_SIM_TASK_ID ,	 
	 
	 
	 
 /* END OF FILE */	 
	 
 KI_TASK_SET_STOP_8 ,	 
	 
 KI_TASK_SET_START_9 = ( 9 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Test Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / testtask.h#1 $	 
 * $Revision: #1 $	 
 * $DateTime: 2006 / 10 / 17 10 :20:49 $	 
 **************************************************************************	 
 * File Description : Protocol stack test task definitions	 
 **************************************************************************/	 
	 
 /* UPGRADE_COOLART should never be defined for a MS target build.	 
 * It is used exclusively for the testing of protocol stacks */	 
	 
	 
	 
	 
	 
	 
 KI_TASK_SET_STOP_9 ,	 
	 
 KI_TASK_SET_START_10 = ( 10 << ( 8 ) ) ,	 
 /*******************************************************************************	 
 ** Multimedia Set	 
 *******************************************************************************/	 
	 
 /*------------------------------------------------------------	 
 ( C ) Copyright [ 2006 -2008 ] Marvell International Ltd.	 
 All Rights Reserved	 
 ------------------------------------------------------------*/	 
	 
 /**************************************************************************	 
 * TTPCom Software Copyright ( c ) 1997 -2005 TTPCom Ltd	 
 * Licensed to Marvell International Ltd	 
 **************************************************************************	 
 * $Id: / / central / main / wsd / sys / gki.typ / api / cfg / mediatask.h#4 $	 
 * $Revision: #4 $	 
 * $DateTime: 2007 / 2 / 2 13 :54:44 $	 
 **************************************************************************	 
 * File Description : Multimedia task definitions	 
 **************************************************************************/	 
	 
 /*	 
 ** This file deliberately does not have multiple inclusion protection	 
 ** as it can be legitimately included twice.	 
 **	 
 ** This must never be included directly by any file outside of the GKI.	 
 */	 
	 
 /*	 
 ** Priorities ( low number is high priority )	 
 **	 
 ** 0 to 9 Tasks which respresent work which is launched by an interrupt	 
 ** 10 to 39 High priority task e.g. Timer task	 
 ** 40 to 69 Medium priority task e.g. RR	 
 ** 70 to 99 Low priority task e.g. AL	 
 */	 
	 
 /*	 
 ** GKI Task ID , GKI Queue ID , Entry Point Stack , Queue , Priority , Stack Pool	 
 */	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MMAC_TASK_ID ,	 
 MMAC_HIGH_PRIORITY_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
 MF_PROCS0_TASK_ID ,	 
 MF_PROCS1_TASK_ID ,	 
 MF_RM_TASK_ID ,	 
 MF_COMMS_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MEDIA_CONTROLLER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 MDS_CONTROL_TASK_ID ,	 
 VIDEO_RENDER_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MES_CONTROL_TASK_ID ,	 
 MES_CAPTURE_TASK_ID ,	 
	 
	 
 CME_SM_SETUP_TASK_ID ,	 
 CME_AUDIO_LOW_PRI_TASK_ID ,	 
	 
	 
	 
	 
 MMCC_TASK_ID ,	 
	 
	 
	 
	 
	 
 AM_TASK_ID ,	 
	 
	 
	 
	 
 AU_DDR_TASK_ID ,	 
	 
	 
	 
	 
	 
	 
 MMSC_CONTROLLER_TASK_ID ,	 
	 
	 
	 
	 
	 
 AU_ROUTER_TASK_ID ,	 
	 
	 
	 
 KI_TASK_SET_STOP_10 ,	 
	 
 /* END OF FILE */	 
	 
	 
	 
	 
	 
	 
	 
 KI_TASK_ID_END ,	 
 /* Task sets add one to the end of a set for the task set stop id ,	 
 ** so need to subtract one to get the max id. */	 
 KI_MAX_TASK_ID = KI_TASK_ID_END - 1 ,	 
 UNKNOWN_TASK_ID = 0xFFFF ,	 
	 
 /* This is the task id used by PassThru tasks in Genie.	 
 ** Do not send signals from target entities to this task	 
 ** as it does not exist on the target. */	 
 PASS_THRU_TASK_ID = 0 ,	 
	 
 UNKNOWN_TASK = UNKNOWN_TASK_ID	 
	 
 /* Any new TaskId which is to be recognised by GENIE should end in the	 
 ** string " _ID " ; conversely , any value which is not to be displayed by	 
 ** GENIE should NOT end in this string. */	 
	 
 } TaskId , KiTaskId;

typedef signed int ptrdiff_t ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef Int32 FrameTicks ;
typedef Int32 KernelTicks ;
typedef Int8 EmptySignal ;
typedef Int8 SignalNotYetDefined ;
typedef Int8 KiTimerIndex ;
typedef Int16 KiTimerId ;
typedef Int16 KiTimerUserValue ;
//ICAT EXPORTED ENUM 
 typedef enum LlcFrameFormatTag 
 {	 
 FRAME_I ,	 
 FRAME_S ,	 
 FRAME_UI ,	 
 FRAME_U ,	 
 FRAME_INVALID	 
 } 
 LlcFrameFormat;

//ICAT EXPORTED UNION : LlcFrameFormat 
 typedef union ControlFieldTag 
 { /* Four types of LLC frame formats: */	 
 FormatI formatI ; /* I+S */	 
 FormatS formatS ;	 
 FormatUI formatUI ;	 
 FormatU formatU ;	 
 } 
 ControlField;

//ICAT EXPORTED STRUCT 
 typedef struct LlcHeaderTag 
 {	 
 LlcFrameFormat format ; /* I+S , S , UI or U */	 
 AddressField address ;	 
 ControlField control ;	 
 Int8 length ; /* LLC header length ( Address and Control fields ) */	 
 FrameError error ;	 
 } 
 LlcHeader;

typedef Int16 Mnc ;
typedef Int16 Mcc ;
typedef Int16 AccessTechnologyId ;
//ICAT EXPORTED STRUCT 
 typedef struct PlmnTag 
 {	 
 Mcc mcc ; /**< Mobile Country Code. */	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number*/	 
 Mnc mnc ; /**< Mobile Network Code. */	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number*/	 
 AccessTechnologyId accessTechnology ; /**< Access Technology: GSM_ACCESS_TECHNOLOGY , UTRAN_ACCESS_TECHNOLOGY or GSM_COMPACT_ACCESS_TECHNOLOGY. */	 
 /* @ITEM_DESC@ Access Technology ID. For coding see ETSI TS 131 102 . @ITEM_MODE@ ReadWrite @ITEM_UNIT@ bitmap	 
 @ITEM_DEPENDENCY@ ETSI TS 131 102 . */	 
 } 
 Plmn;

//ICAT EXPORTED STRUCT 
 typedef struct SimPlmnTag 
 {	 
 /* @STRUCT_DESC@ PLMN with MNC length */	 
 Plmn plmn ; /**< PLMN. */	 
 /* @ITEM_DESC@ PLMN @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 Boolean mncThreeDigitsDecoding ; /**< Is three digit encoding used. */	 
 /* @ITEM_DESC@ Is three digit encoding used @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 } 
 SimPlmn;

//ICAT EXPORTED ENUM 
 typedef enum PlmnNameCodingSchemeTag 
 {	 
 PLMN_CODING_DEFAULT , /**< Default coding scheme. */	 
 PLMN_CODING_UCS2 /**< UCS2 coding scheme. */	 
 } 
 PlmnNameCodingScheme;

//ICAT EXPORTED ENUM 
 typedef enum FreqBandTag 
 {	 
 FreqBand_dcs1800Band ,	 
 FreqBand_pcs1900Band	 
 } 
 FreqBand;

typedef Int8 FullName [ ( ( 25 ) ) ] ;
typedef Int8 AbbrName [ ( ( 11 ) ) ] ;
typedef Int8 Initials [ ( 4 ) ] ;
typedef Int8 FormatSpecifier [ ( 14 ) ] ;
//ICAT EXPORTED STRUCT 
 typedef struct PlmnNameTag 
 {	 
 /* @STRUCT_DESC@ PLMN Name */	 
 PlmnNameCodingScheme plmnCoding ; /**< Coding scheme for ' full ' , ' abbr ' & ' initials ' . */	 
 /* @ITEM_DESC@ @ITEM_MODE@ ReadWrite @ITEM_UNIT@ See enum for values*/	 
 FullName full ; /**< Full network name ( long ) . */	 
 AbbrName abbr ; /**< Abbreviated network name ( short ) . */	 
 Initials initials ; /**< Country initials. */	 
 FormatSpecifier format ; /**< Format specifier. */	 
 } 
 PlmnName;

//ICAT EXPORTED STRUCT 
 typedef struct PlmnIdTag 
 {	 
 /* @STRUCT_DESC@ PLMN ID */	 
	 
 Boolean present ; /**< Is present. */	 
 /* @ITEM_DESC@ Is present @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 Plmn plmn ; /**< PLMN. */	 
 /* @ITEM_DESC@ PLMN @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 Boolean threeDigitMnc ; /**< Is the MNC three digit. */	 
 /* @ITEM_DESC@ Is present @ITEM_MODE@ ReadWrite @ITEM_UNIT@ on / off ( 0 -not active , 1 -active ) */	 
 PlmnName plmnName ; /**< PLMN Name. */	 
 /* @ITEM_DESC@ PLMN Name @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 } 
 PlmnId;

typedef Int16 Arfcn ;
typedef Int16 ReducedFrameNumber ;
typedef Int8 Bsic ;
typedef Int8 Tsc ;
typedef SignedInt32 Otd ;
//ICAT EXPORTED ENUM 
 typedef enum BandTag 
 {	 
 GSM_BAND = 0 ,	 
 DCS_BAND = 1 ,	 
 PCS_BAND = 2 ,	 
 EGSM_BAND = 3 ,	 
 GSM_450_BAND = 4 ,	 
 GSM_480_BAND = 5 ,	 
 GSM_850_BAND = 6 ,	 
 NUM_BANDS , /**< The number of bands supported by Layer 1 and RR */	 
 /*2013.12.30 , mod by Xili for CQ00051491 , begin*/	 
 /* used by SIMAT */	 
 LTE_BAND = 0xFD ,	 
 /*2013.12.30 , mod by Xili for CQ00051491 , end*/	 
 /* used by MM */	 
 UMTS_BAND = 0xFE ,	 
 INVALID_BAND = 0xFF	 
 } 
 Band;

//ICAT EXPORTED ENUM 
 typedef enum BandModeTag 
 {	 
 /* @ENUM_DESC@ GSM Band Mode */	 
 ZERO_BAND_MODE = 0x0000 ,	 
 PGSM_MODE = 0x0001 , /**< Autoband enabled */	 
 EGSM_MODE = ( 0x0001 + 0x0008 ) , /**< Autoband enabled */	 
 DCS_MODE = 0x0002 , /**< Autoband enabled */	 
 PGSM_DCS_MODE = 0x0001 + 0x0002 , /**< Autoband enabled */	 
 EGSM_DCS_MODE = ( 0x0001 + 0x0008 ) + 0x0002 , /**< Autoband enabled */	 
 PCS_MODE = 0x0004 , /**< Autoband enabled */	 
 PGSM_PCS_MODE = 0x0001 + 0x0004 , /**< Autoband enabled */	 
 EGSM_PCS_MODE = ( 0x0001 + 0x0008 ) + 0x0004 , /**< Autoband enabled */	 
	 
 PGSM_PCS_MODE_LOCK = 0x0001 + 0x0004 + 0x0200 , /**< LOCK the MS to PGSM / PCS mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only */	 
 EGSM_PCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0004 + 0x0200 , /**< LOCK the MS to EGSM / PCS mode. Autoband DISABLED. For use in testing and 900 / 1900 countries only */	 
 EGSM_DCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0200 , /**< LOCK the MS to EGSM / DCS mode. Autoband DISABLED. For use in testing and 900 / 1800 countries only */	 
 DCS_MODE_LOCK = 0x0002 + 0x0200 , /**< LOCK the MS to DCS mode. Autoband DISABLED. For use in testing only */	 
 PCS_MODE_LOCK = 0x0004 + 0x0200 , /**< LOCK the MS to PCS mode. Autoband DISABLED. For use in testing only */	 
 EGSM_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0200 , /**< LOCK the MS to EGSM mode. Autoband DISABLED. For use in testing only */	 
	 
 /* Band mode for GSM850 support */	 
 GSM850_MODE = 0x0040 , /**< Autoband enabled */	 
 GSM850_PCS_MODE = 0x0040 + 0x0004 , /**< Autoband enabled */	 
 GSM850_PCS_MODE_LOCK = 0x0040 + 0x0004 + 0x0200 , /**< LOCK the MS to GSM850 / PCS1900 mode. */	 
 GSM850_PCS_EGSM_DCS_MODE = 0x0040 + 0x0004 + EGSM_DCS_MODE ,	 
 GSM850_DCS_EGSM_MODE = 0x0040 + EGSM_DCS_MODE , /**< Autoband enabled */	 
 GSM850_PCS_EGSM_MODE = 0x0040 + EGSM_PCS_MODE , /**< Autoband enabled */	 
	 
 GSM850_DCS_MODE = 0x0040 + 0x0002 , /**< Autoband enabled */	 
 GSM850_MODE_LOCK = 0x0040 + 0x0200 , /**< LOCK the MS to GSM850 mode. Autoband DISABLED. For use in testing only */	 
 GSM850_DCS_MODE_LOCK = 0x0040 + 0x0002 + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
 GSM850_DCS_EGSM_MODE_LOCK = 0x0040 + EGSM_DCS_MODE + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
 GSM850_PCS_EGSM_MODE_LOCK = 0x0040 + EGSM_PCS_MODE + 0x0200 , /**< LOCK the MS to GSM850 / DCS1800 mode. Autoband DISABLED. For use in testing and 850 / 1800 countries only */	 
	 
 EGSM_DCS_PCS_MODE = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004 ,	 
 EGSM_DCS_PCS_MODE_LOCK = ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004 + 0x0200 ,	 
	 
 /* used by MM */	 
 UMTS_MODE = 0x0100 ,	 
 /* used by MM */	 
 LTE_MODE = 0x0400 ,	 
	 
 QUAD_MODE = 0x0002 + 0x0004 + ( 0x0001 + 0x0008 ) + 0x0040 ,	 
 QUAD_MODE_LOCK = QUAD_MODE + 0x0200 ,	 
	 
 /* This is used to verify value is within the allowed range. */	 
 /* Note that the value should be updated if new bit is added.*/	 
 ALL_BITS_BAND_MODE = 0x0200 + 0x0100 + 0x0080 + 0x0040 + ( 0x0010 + 0x0020 ) + ( 0x0001 + 0x0008 ) + 0x0002 + 0x0004	 
 + 0x0400 ,	 
	 
 INVALID_BAND_MODE = 0xffff	 
 } 
 BandMode;

//ICAT EXPORTED ENUM 
 typedef enum NetworkModeTag 
 {	 
 /* @ENUM_DESC@ used in PLMN search to determine the networks to search */	 
	 
 NMODE_GSM ,	 
 NMODE_UMTS ,	 
 NMODE_LTE ,	 
 NMODE_GSM_UMTS ,	 
 NMODE_GSM_LTE ,	 
 NMODE_UMTS_LTE ,	 
 NMODE_GSM_UMTS_LTE ,	 
 NMODE_NULL	 
 } 
 NetworkMode;

//ICAT EXPORTED ENUM 
 typedef enum NetworkModeBitMaskTag 
 {	 
 NW_MODE_NO_RATS = 0 ,	 
 NW_MODE_BIT_GSM = 0x01 ,	 
 NW_MODE_BIT_UMTS = 0x02 ,	 
 NW_MODE_BIT_DUAL_RAT = NW_MODE_BIT_GSM | NW_MODE_BIT_UMTS ,	 
 NW_MODE_BIT_LTE = 0x04 ,	 
 NW_MODE_BIT_GSM_LTE = NW_MODE_BIT_GSM | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_UMTS_LTE = NW_MODE_BIT_UMTS | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_TRI_RAT = NW_MODE_BIT_DUAL_RAT | NW_MODE_BIT_LTE ,	 
 NW_MODE_BIT_ALL_RATS = NW_MODE_BIT_TRI_RAT ,	 
 NW_MODE_BIT_MAX	 
 } NetworkModeBitMask;

//ICAT EXPORTED ENUM 
 typedef enum UmtsWorkModeTag 
 {	 
 UWMODE_TDD ,	 
 UWMODE_FDD	 
 } 
 UmtsWorkMode;

//ICAT EXPORTED ENUM 
 typedef enum LteOperateModeTag 
 {	 
 PS_MODE_2 ,	 
 CS_PS_MODE_1 ,	 
 CS_PS_MODE_2 ,	 
 PS_MODE_1	 
 } 
 LteOperateMode;

//ICAT EXPORTED ENUM 
 typedef enum LteUsageSettingTag 
 {	 
 VOICE_CENTRIC ,	 
 DATA_CENTRIC	 
 } 
 LteUsageSetting;

//ICAT EXPORTED ENUM 
 typedef enum LteVoiceDomainPreferTag 
 {	 
 CS_VOICE_ONLY ,	 
 IMS_PS_VOICE_ONLY ,	 
 CS_PS_VOICE_PREFER_IMS_PS_VOICE_SEC ,	 
 IMS_PS_VOICE_PREFER_CS_VOICE_SEC	 
 } 
 LteVoiceDomainPrefer;

//ICAT EXPORTED ENUM 
 typedef enum LteSmsDomainTag 
 {	 
 SMS_OVER_IMS ,	 
 SMS_OVER_SGS	 
 } 
 LteSmsDomain;

//ICAT EXPORTED ENUM 
 typedef enum AccessBurstTypeTag 
 {	 
 EIGHT_BIT_ACCESS_BURST = 0 ,	 
 ELEVEN_BIT_ACCESS_BURST = 1 ,	 
 ACCESS_BURST_NOT_DEFINED = 2	 
 } 
 AccessBurstType;

typedef Int32
 Tmsi ;
typedef Int16
 AccessClass ;
typedef Int16
 Lac ;
typedef Int8
 Rac ;
typedef Int16
 CellId ;
typedef Int8
 TmsiTime ;
typedef Int16
 Tac ;
typedef Int32
 MTmsi ;
typedef Int16
 MmeGroupId ;
typedef Int8
 MmeCode ;
//ICAT EXPORTED STRUCT 
 typedef struct TaiTag 
 {	 
 Mcc mcc ;	 
 Mnc mnc ;	 
 Tac tac ;	 
 Int8 rawIe [ 5 ] ;	 
 } 
 Tai;

typedef Tai TrackingAreaIdentityElement ;
//ICAT EXPORTED ENUM 
 typedef enum PartialTaiListTypeTag 
 {	 
 PARTIAL_TAI_LIST_TYPE_0 = 0 , /* Type of list = " 0 " */	 
 PARTIAL_TAI_LIST_TYPE_1 = 1 , /* Type of list = " 1 " */	 
 PARTIAL_TAI_LIST_TYPE_2 = 2 /* Type of list = " 10 " */	 
 } 
 PartialTaiListType;

//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiList_0Tag 
 {	 
 Mcc mcc ;	 
 Mnc mnc ;	 
 Tac tac [ 16 ] ;	 
 } 
 PartialTaiList_0;

typedef PartialTaiList_0 PartialTaiList_1 ;
//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiList_2Tag 
 {	 
 Tai tai [ 16 ] ;	 
 } 
 PartialTaiList_2;

//ICAT EXPORTED UNION:PartialTaiListType 
 typedef union TaiListUnionElementTag 
 
 {	 
 PartialTaiList_0 taiListType_0 ;	 
 PartialTaiList_1 taiListType_1 ;	 
 PartialTaiList_2 taiListType_2 ;	 
 } TaiListUnion;

//ICAT EXPORTED STRUCT 
 typedef struct PartialTaiListElementTag 
 {	 
 PartialTaiListType taiListType ;	 
 Int16 numOfElements ; /* 1 ~16 */	 
 TaiListUnion taiListUnion ;	 
 } 
 PartialTaiList;

//ICAT EXPORTED STRUCT 
 typedef struct TaiListElementTag 
 { /* Refer to 9.900000 .3.33-24.301 */	 
 Int16 numOfList ; /* Number of Partial tracking area identity list */	 
 PartialTaiList partialTaiList [ 16 ] ;	 
 } 
 TaiListElement;

//ICAT EXPORTED STRUCT 
 typedef struct GutiTag 
 {	 
 Int8 guti [ 10 ] ;	 
 } 
 Guti;

//ICAT EXPORTED ENUM 
 typedef enum TinTag 
 {	 
 TIN_PTMSI ,	 
 TIN_GUTI ,	 
 TIN_RAT_RELATED_TMSI ,	 
 TIN_DELETED	 
 } 
 Tin;

//ICAT EXPORTED ENUM 
 typedef enum MsOperationModeTag 
 {	 
 MS_OPERN_NORMAL = 0x00 , /* normal operation */	 
 MS_OPERN_TA = 0x80 , /* type approval operation */	 
 MS_OPERN_NORMAL_PLUS_SPECIFIC = 0x01 , /* normal + specific operation */	 
 MS_OPERN_TA_PLUS_SPECIFIC = 0x81 , /* type approval + specific operation */	 
 MS_OPERN_MAINTENANCE = 0x02 , /* maintenance operation */	 
 MS_OPERN_CELL_TEST = 0x04 /* cell test operation */	 
 } 
 MsOperationMode;

//ICAT EXPORTED ENUM 
 typedef enum KeySequenceTag 
 {	 
 KEY_SEQUENCE_0 = 0 ,	 
 KEY_SEQUENCE_1 = 1 ,	 
 KEY_SEQUENCE_2 = 2 ,	 
 KEY_SEQUENCE_3 = 3 ,	 
 KEY_SEQUENCE_4 = 4 ,	 
 KEY_SEQUENCE_5 = 5 ,	 
 KEY_SEQUENCE_6 = 6 ,	 
 NO_KEY_SEQUENCE_AVAILABLE = 7	 
 } 
 KeySequence;

//ICAT EXPORTED STRUCT 
 typedef struct LocationAreaIdTag 
 {	 
 Mcc mcc ;	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Mnc mnc ;	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Lac lac ;	 
 /* @ITEM_DESC@ Location area code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ code*/	 
 Int8 rawIe [ 5 ] ;	 
 /* @ITEM_DESC@ Information as read on SI @ITEM_MODE@ ReadWrite @ITEM_UNIT@ */	 
 } 
 LocationAreaIdElement;

typedef LocationAreaIdElement Lai ;
typedef LocationAreaIdElement LocationAreaId ;
//ICAT EXPORTED STRUCT 
 typedef struct EquivalentPlmnTag 
 {	 
 /* @STRUCT_DESC@ Equivalent PLMN */	 
 Mcc mcc ;	 
 /* @ITEM_DESC@ Mobile Country Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 Mnc mnc ;	 
 /* @ITEM_DESC@ Mobile Network Code @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 } 
 EquivalentPlmn;

//ICAT EXPORTED STRUCT 
 typedef struct EquivalentPlmnListTag 
 {	 
 /* @STRUCT_DESC@ List of Equivalent PLMNs */	 
 Int16 numPlmn ;	 
 /* @ITEM_DESC@ Number of PLMNs in the list @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number */	 
 EquivalentPlmn plmn [ 16 ] ;	 
 /* @ITEM_DESC@ Array of Equivalent PLMNs @ITEM_MODE@ ReadWrite @ITEM_UNIT@ see structure definition */	 
 } 
 EquivalentPlmnListElement;

typedef EquivalentPlmnListElement EquivalentPlmnList ;
//ICAT EXPORTED STRUCT 
 typedef struct ChannelBitMapTag 
 {	 
 Boolean valid ;	 
 Int8 channelData [ 128 ] ;	 
 } 
 BaList;

//ICAT EXPORTED ENUM 
 typedef enum MmErrorCauseTag 
 {	 
 MM_ERROR_UNEX_CAMP_REQ ,	 
 MM_ERROR_UNEX_REG_REQ ,	 
 MM_ERROR_UNEX_NREG_REQ ,	 
 MM_ERROR_UNEX_PLMN_LIST_REQ ,	 
 MM_ERROR_UNEX_PLMN_LIST_RRC_CONN_EXIST_REQ ,	 
 MM_ERROR_UNEX_CAMP_REQ_IN_REG_PROC ,	 
 MM_ERROR_SIM_PROBLEM	 
 } 
 MmErrorCause;

//ICAT EXPORTED ENUM 
 typedef enum MmStateTag /* defined in 4.100000 .2.1.1 */ 
 {	 
 /* GRR */	 
 /* connection y / n */	 
 M0_MM_NULL = 0 , /* n */	 
 M3_WAIT_FOR_LOC_UPDATE_RESPONSE = 3 , /* y */	 
 M5_WAIT_FOR_OUTGOING_MM_CONNECTION = 5 , /* y */	 
 M6_MM_CONNECTION_ACTIVE = 6 , /* y */	 
 M7_IMSI_DETACH_INITIATED = 7 , /* y */	 
 M9_WAIT_FOR_NETWORK_COMMAND = 9 , /* y */	 
 M10_LOCATION_UPDATE_REJECTED = 10 , /* y */	 
 M13_RR_CONN_PENDING_LOC_UPDATING = 13 , /* n */	 
 M14_RR_CONN_PENDING_MM_CONNECTION = 14 , /* n */	 
 M15_RR_CONN_PENDING_IMSI_DETACH = 15 , /* n */	 
 M17_WAIT_FOR_CM_REESTABLISH = 17 , /* n */	 
 M18_WAIT_FOR_RR_ACTIVE = 18 , /* n */	 
 M20_WAIT_FOR_ADDITIONAL_OUTGOING_MM_CONNECTION = 20 , /* y */	 
	 
 M23_LOCATION_UPDATE_PENDING = 23 ,	 
 M24_IMSI_DETACH_PENDING = 24 ,	 
	 
	 
	 
 M25_RR_CONNECTION_RELEASE_NOT_ALLOWED = 25 ,	 
	 
	 
	 
 M19_MM_IDLE_NORMAL_SERVICE = 191 , /* state 19.100000 */ /* n */	 
 M19_MM_IDLE_ATTEMPTING_TO_UPDATE = 192 , /* state 19.200000 */ /* n */	 
 M19_MM_IDLE_LIMITED_SERVICE = 193 , /* state 19.300000 */ /* n */	 
 M19_MM_IDLE_NO_IMSI = 194 , /* state 19.400000 */ /* n */	 
 M19_MM_IDLE_NO_CELL_AVAILABLE = 195 , /* state 19.500000 */ /* n */	 
 M19_MM_IDLE_LOC_UPDATE_NEEDED = 196 , /* state 19.600000 */ /* n */	 
	 
 M19_MM_IDLE_ECALL_INACTIVE = 197 , /* state 19.110000 */ /*added by xyma for CQ00100279 20150814 */	 
 /*	 
 ** Other MM states are not implemented ; they are insufficient to	 
 ** describe behaviour.	 
 */	 
 MM_NUM_STATES /* leave as last constant */	 
 } 
 MmState;

//ICAT EXPORTED ENUM 
 typedef enum UmmStateTag 
 {	 
 UMM_DETACHED ,	 
 UMM_IDLE ,	 
 UMM_CONNECTED ,	 
 NUM_UMM_STATES	 
 } UmmState;

//ICAT EXPORTED ENUM 
 typedef enum EmmEpsStateTag 
 {	 
 EMM_DETACHED ,	 
 EMM_IDLE ,	 
 EMM_CONNECTED ,	 
 EMM_IDLE_SUSPEND , // add by xyma for CQ00125818 2021.100000 .4	 
 NUM_EMM_STATES	 
 } 
 EmmEpsState;

//ICAT EXPORTED ENUM 
 typedef enum SRStateTag 
 {	 
 S_START = 0 ,	 
 S_SUCCESS ,	 
 S_CANCEL ,	 
 S_FAIL	 
 } SRState;

//ICAT EXPORTED ENUM 
 typedef enum EmmStateTag /* defined in 24301 5.100000 .3 */ 
 {	 
 EMM_NULL = 0 ,	 
 EMM_REGISTERED_INITIATED = 1 ,	 
 EMM_DEREGISTERED_INITIATED = 2 ,	 
 EMM_TRACKING_AREA_UPDATING_INITIATED = 3 ,	 
 EMM_REGISTERED_NORMAL_SERVICE = 10 ,	 
 EMM_REGISTERED_UPDATE_NEEDED = 12 ,	 
 EMM_REGISTERED_ATTEMPTING_TO_UPDATE = 13 ,	 
 EMM_REGISTERED_NO_CELL_AVAILABLE = 14 ,	 
 EMM_REGISTERED_LIMITED_SERVICE = 15 ,	 
 EMM_REGISTERED_ATTEMPTING_TO_UPDATE_MM = 16 ,	 
 EMM_DEREGISTERED_NORMAL_SERVICE = 20 ,	 
 EMM_DEREGISTERED_LIMITED_SERVICE = 21 ,	 
 EMM_DEREGISTERED_ATTACH_NEEDED = 22 ,	 
 EMM_DEREGISTERED_ATTEMPTING_TO_ATTACH = 23 ,	 
 EMM_DEREGISTERED_NO_IMSI = 24 ,	 
 EMM_DEREGISTERED_NO_CELL_AVAILABLE = 25 ,	 
 EMM_DEREGISTERED_PLMN_SEARCH = 27 ,	 
 EMM_REGISTERED_IMSI_DETACH_INITIATED = 28 ,	 
 EMM_SERVICE_REQUEST_INITIATED = 29 ,	 
 EMM_NUM_STATES /* leave as last constant */	 
 } 
 EmmState;

//ICAT EXPORTED ENUM 
 typedef enum EmmSpecificProcedureTag 
 {	 
 EPS_ONLY_ATTACH_PROC = 0 ,	 
 EMM_COMBINED_ATTACH_PROC ,	 
 EMM_PERIODIC_TA_PROC ,	 
 EMM_NORMAL_TA_PROC ,	 
 EMM_COMBINED_TA_PROC ,	 
 EMM_COMBINED_TA_WITH_IMSI_PROC ,	 
 EPS_ONLY_DETACH_PROC ,	 
 EPS_IMSI_DETACH_PROC ,	 
 EPS_ONLY_MT_DETACH ,	 
 EPS_MT_DETACH_REATTACH ,	 
 EMM_COMBINED_DETACH_PROC ,	 
 EMM_CELL_UPDATE_PROC ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_TAU ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_ATTACH ,	 
 EMM_SERVICE_REQUEST_PROC ,	 
 EMM_WAIT_FOR_ESM_RESP_FOR_PAGING ,	 
 /* added by xyma for CQ00059052 , 2014.040000 .18 , begin*/	 
 EPS_EMERGENCY_ATTACH_PROC ,	 
 /* added by xyma for CQ00059052 , 2014.040000 .18 , end*/	 
 NO_EMM_SPECIFIC_PROC	 
 } EmmSpecificProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EmmCommonProcedureTag 
 {	 
 EMM_EPS_AUTHEN_PROC = 0 ,	 
 /* All the other EMM common procedures are single signal procedures so are not really needed here */	 
 NO_EMM_COMMON_PROC	 
 } EmmCommonProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EmmProcedureStatusTag 
 {	 
 EMM_AWAITING_EXECUTION = 0 ,	 
 EMM_EXECUTING ,	 
 EMM_AWAITING_COMPLETION ,	 
 EMM_NO_ACTIVE_PROC	 
 } EmmProcedureStatus;

//ICAT EXPORTED STRUCT 
 typedef struct EmmProcedureTag 
 {	 
 EmmSpecificProcedure emmSpecificProc ;	 
 EmmCommonProcedure emmCommonProc ;	 
 EmmProcedureStatus emmSpecificProcStatus ;	 
 } EmmProcedure;

//ICAT EXPORTED ENUM 
 typedef enum EpsOptPreferModeTag 
 {	 
 EPS_OPT_CP_ONLY ,	 
 EPS_OPT_UP_ONLY ,	 
 EPS_OPT_CP_PREFER ,	 
 EPS_OPT_UP_PREFER ,	 
 EPS_OPT_RESERVED = 0xFF	 
 } 
 EpsOptPreferMode;

//ICAT EXPORTED ENUM 
 typedef enum CsrProcIdTag 
 {	 
 CSR_NO_PROC ,	 
 CSR_PROC_CSRR ,	 
 CSR_PROC_CSRP ,	 
 CSR_PROC_CSRS ,	 
 CSR_PROC_CSRC	 
 // CQ00070469 add begin	 
	 
	 
	 
 // CQ00070469 add end	 
 } 
 CsrProcId;

//ICAT EXPORTED ENUM 
 typedef enum CsrcStateTag 
 {	 
 CSRC_IDLE ,	 
 CSRC_AWAIT_CPHY_FIND_CELL_CNF ,	 
 CSRC_AWAIT_SYS_INFO ,	 
 CSRC_AWAIT_CPHY_CELL_SELECT_CNF ,	 
 CSRC_AWAIT_CPHY_NEXT_CELL_CNF ,	 
 /* PTK_CQ00236868 begin */	 
 CSRC_SEARCH_ABORTING_WAIT_L1_CNF	 
 /* PTK_CQ00236868 end */	 
 } 
 CsrcState;

//ICAT EXPORTED ENUM 
 typedef enum CsrrReselectorStateTag 
 {	 
	 
 CSRR_AWAIT_RESELECT_TO_UMTS_FAIL_CNF ,	 
 CSRR_AWAIT_RESELECTION_TO_GSM ,	 
 CSRR_SUSPENDED_DUE_TO_CCOFU ,	 
	 
 CSRR_IDLE ,	 
 CSRR_AWAIT_MEASUREMENTS ,	 
 CSRR_AWAIT_BCH_DECODING_CNF ,	 
 CSRR_AWAIT_SYS_INFO ,	 
 CSRR_AWAIT_L1_CAMPED_ON_CELL ,	 
 CSRR_AWAIT_PHY_RESYNCH_TO_SERV_CELL ,	 
 CSRR_RANKING_CSRP_ACTIVE ,	 
 CSRR_ABORTING	 
 ,	 
 CSRR_AWAIT_RESELECTION_TO_LTE ,	 
 CSRR_AWAIT_DEACTIVATE_CNF	 
 } 
 CsrrReselectorState;

//ICAT EXPORTED ENUM 
 typedef enum CsrpPlmsStateTag 
 {	 
 CSRP_PLMS_NOT_SEARCHING , /* idle */	 
 CSRP_PLMS_WAIT_PLMS_FREQ_SCAN , /* RSSI scan is done by PLMS task */	 
 CSRP_PLMS_UMTS_WAIT_FOR_BCH_ESTABLISH , /* Waiting for L1 to open BCH */	 
 CSRP_PLMS_UMTS_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_UMTS_WAIT_FOR_BCH_RELEASE , /* Waiting for L1 to close BCH */	 
 CSRP_PLMS_GSM_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_LTE_READING_SIBS , /* Reading BCCH info */	 
 CSRP_PLMS_LTE_WAIT_FOR_BCH_RELEASE /* Waiting for L1 to close BCH */	 
	 
 } 
 CsrpPlmsState;

//ICAT EXPORTED ENUM 
 typedef enum CsrpActiveStateTag 
 {	 
 CSRP_STATE_NOT_SEARCHING , /* idle */	 
 CSRP_STATE_ACTIVE , /* active */	 
 CSRP_STATE_ABORTING_AWAIT_PLMS , /* Waiting for PLMS to trigger CSRP abort */	 
 CSRP_STATE_ABORTING_AWAIT_L1_CNF , /* Waiting for L1 CNF so abort can take place */	 
 CSRP_STATE_SUSPENDING_AWAIT_PLMS , /* Waiting for PLMS to trigger CSRP suspend */	 
 CSRP_STATE_SUSPENDING_AWAIT_L1_CNF , /* Waiting for L1 CNF so suspend can take place */	 
 CSRP_STATE_SUSPENDED , /* PLMN search process is suspended */	 
 CSRP_STATE_COMPLETING_AWAIT_L1_CNF /*Waiting for L1 to deactivate before completing search*/	 
 } 
 CsrpActiveState;

//ICAT EXPORTED ENUM 
 typedef enum CsrsSearchStatusTag 
 {	 
 CSRS_NOT_SEARCHING ,	 
 CSRS_SEARCH_WAIT_FOR_SCAN_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_SEARCH_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_SEARCH_BCH ,	 
 CSRS_SEARCH_WAIT_FOR_CHECK_PLMN_REJ_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_CHECK_PLMN_REJ_BCH ,	 
 CSRS_SEARCH_WAIT_PHY_DEACTIVATE_CNF ,	 
 CSRS_SEARCH_ABORTING_WAIT_L1_CNF ,	 
 CSRS_SEARCH_WAIT_FOR_PLMS , // search is ongoing in PLMS	 
 CSRS_SEARCH_WAIT_FB_BCH_CNF , // Wating for CphyFgBchCnf	 
 CSRS_SEARCH_WAIT_PLMS_ABORT , // Wating for PLMS to Abort the search	 
 CSRS_SEARCH_WAIT_FOR_IRAT_RESEL , // ICS started in another RAT waiting for reselection to URR	 
 CSRS_SEARCH_WAIT_HAW_INIT ,	 
 CSRS_SEARCH_WAIT_FB_BCH_CNF_BEFORE_PLMS_ABORT // Wating for CphyFgBchCnf Before aborting PLMS	 
 } 
 CsrsSearchStatus;

//ICAT EXPORTED ENUM 
 typedef enum UrrCSRExitCodesTag 
 {	 
 // CSRC	 
 CSRC_CELL_SELECTION_FAILURE_OOS = 1 ,	 
 CSRC_CELL_CAMPED_ON_SUITABLE_CELL ,	 
 CSRC_CSRTU_FAILURE ,	 
 CSRC_CSRTU_T3174_EXPIRY ,	 
 CSRC_REDIRECTION_FAILED ,	 
 /* PTK_CQ00236868 begin */	 
 CSRC_ABORT_REQUEST ,	 
 /* PTK_CQ00236868 end */	 
 // CSRS	 
 CSRS_ABORT_REQUEST ,	 
 CSRS_INITIAL_CELL_SELECTION_SUCCESS ,	 
 CSRS_FAIL_TO_SELECT_ANY_CELL ,	 
 // CSRR	 
 CSRR_ABORT_REQUEST ,	 
 // CSRR_START_INTERNAL_PLMN_SEARCH , / * CQ00094524 * /	 
 CSRR_START_ICS_IDLE_OOS ,	 
 CSRR_COMPLETE_RESELECTION ,	 
 CSRR_OOS_DETECTED ,	 
 CSRR_RESELECTION_REQUIRED ,	 
 CSRR_ABORT_SUSPENDED_PLMN ,	 
 CSRR_START_CSRR_PROC ,	 
 // CSRP	 
 CSRP_START_CELL_RESELECTION ,	 
 CSRP_ABORT_REQUEST ,	 
 CSRP_ABORT_GSM_MODE_PLMN ,	 
 CSRP_ABORT_LTE_MODE_PLMN ,	 
 CSRP_SUSPENSION_COMPLETE ,	 
 CSRP_FG_GSM_OOS_CONN_NON_DCH_COMPLETE	 
 // CQ00070469 add begin	 
	 
 // CQ00070469 add end	 
 } 
 UrrCSRExitCodes;

//ICAT EXPORTED ENUM 
 typedef enum UrrCerStateTag 
 {	 
 CER_IDLE ,	 
 CER_CONNECTING_WAIT_TX ,	 
 CER_RETRYING_WAIT_TX ,	 
 CER_WAIT_CONNECTION_SETUP ,	 
 CER_WAIT_SETUP_COMPLETE_TX ,	 
 CER_REJECTED_WAIT ,	 
 CER_REJECTED_NEW_FREQ_WAIT_SELECTION ,	 
 CER_REJECTED_SAME_FREQ_WAIT_SIBS ,	 
 CER_REJECTED_DIFF_FREQ_WAIT_SIBS ,	 
 CER_REJECTED_NEW_RAT_WAIT_SELECTION ,	 
 CER_DISC_DCH_WAIT_TX ,	 
 CER_DISC_FACH_WAIT_TX ,	 
 CER_CONNECTED ,	 
 CER_WAIT_IDT_TX_CONFIRM ,	 
 CER_WAIT_RBC_PROCESS_RRC_CONN_SETUP ,	 
 CER_WAIT_RACH_MEAS_RESULTS ,	 
 CER_WAIT_RBC_PROCESS_RRC_CON_RELEASE_FACH ,	 
 CER_WAIT_RBC_PROCESS_RRC_CON_RELEASE_DCH ,	 
 CER_DISC_DCH_WAIT_ALL_SIBS_DISTRIBUTED ,	 
 CER_WAIT_CSR_PLMN_ABORT_CNF ,	 
	 
 CER_WAIT_IRAT_DS_SUSPEND_CNF ,	 
	 
 CER_WAIT_CELL_UPDATE_OCCURRED ,	 
 CER_WAIT_RBC_MOVE_TO_FACH	 
 } 
 UrrCerState;

typedef union KiStateMachinesStateTag
 {
 Int16 genState ;
 MmState MM_state ;

 EmmState EMM_state ;



 CsrProcId CSR_Active_Proc ;
 CsrcState CSRC_State ;
 CsrsSearchStatus CSRS_State ;
 CsrrReselectorState CSRR_State ;




 CsrpActiveState CSRP_State ;


 UrrCerState URR_CER_State ;


 } KiStateMachinesState ;
typedef SignalNotYetDefined KiMemReadReq ;
typedef SignalNotYetDefined KiMemReadCnf ;
typedef SignalNotYetDefined KiMemWriteReq ;
typedef SignalNotYetDefined KiMemWriteCnf ;
typedef SignalNotYetDefined KiMemReadMultiReq ;
typedef SignalNotYetDefined KiMemReadMultiCnf ;
typedef SignalNotYetDefined KiMemWriteMultiReq ;
typedef SignalNotYetDefined KiMemWriteMultiCnf ;
typedef unsigned long UNSIGNED ;
typedef long SIGNED ;
typedef unsigned char DATA_ELEMENT ;
typedef DATA_ELEMENT OPTION ;
typedef DATA_ELEMENT BOOLEAN ;
typedef int STATUS ;
typedef unsigned char UNSIGNED_CHAR ;
typedef unsigned int UNSIGNED_INT ;
typedef int INT ;
typedef unsigned long * UNSIGNED_PTR ;
typedef unsigned char * BYTE_PTR ;
typedef unsigned int size_t ;
typedef unsigned short wchar_t ;
typedef int ( *__heapprt ) ( void * , char const * , ... ) ;
typedef char CHAR ;
typedef unsigned char UCHAR ;
typedef int INT ;
typedef unsigned int UINT ;
typedef long LONG ;
typedef unsigned long ULONG ;
typedef short SHORT ;
typedef unsigned short USHORT ;
//ICAT EXPORTED ENUM 
 typedef enum 
 {	 
 OSA_TASK_READY ,	 
 OSA_TASK_COMPLETED ,	 
 OSA_TASK_TERMINATED ,	 
 OSA_TASK_SUSPENDED ,	 
 OSA_TASK_SLEEP ,	 
 OSA_TASK_QUEUE_SUSP ,	 
 OSA_TASK_SEMAPHORE_SUSP ,	 
 OSA_TASK_EVENT_FLAG ,	 
 OSA_TASK_BLOCK_MEMORY ,	 
 OSA_TASK_MUTEX_SUSP ,	 
 OSA_TASK_STATE_UNKNOWN ,	 
 } OSA_TASK_STATE;

//ICAT EXPORTED STRUCT 
 typedef struct OSA_TASK_STRUCT 
 {	 
 char *task_name ; /* Pointer to thread ' s name */	 
 unsigned int task_priority ; /* Priority of thread ( 0 -255 ) */	 
 unsigned long task_stack_def_val ; /* default vaule of thread */	 
 OSA_TASK_STATE task_state ; /* Thread ' s execution state */	 
 unsigned long task_stack_ptr ; /* Thread ' s stack pointer */	 
 unsigned long task_stack_start ; /* Stack starting address */	 
 unsigned long task_stack_end ; /* Stack ending address */	 
 unsigned long task_stack_size ; /* Stack size */	 
 unsigned long task_run_count ; /* Thread ' s run counter */	 
	 
 } OSA_TASK;

typedef void *OsaRefT ;
typedef UINT8 OSA_STATUS ;
typedef UINT8 OS_STATUS ;
typedef void* OS_HISR ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSASemaRef ;
typedef void* OSAMutexRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPoolRef ;
typedef void* OSATimerRef ;
typedef void* OSAFlagRef ;
typedef void* OSAPartitionPoolRef ;
typedef void* OSTaskRef ;
typedef void* OSSemaRef ;
typedef void* OSMutexRef ;
typedef void* OSMsgQRef ;
typedef void* OSMailboxQRef ;
typedef void* OSPoolRef ;
typedef void* OSTimerRef ;
typedef void* OSFlagRef ;
typedef UINT8 OS_STATUS ;
typedef OsaTimerStatusParamsT OSATimerStatus ;
typedef void* OSATaskRef ;
typedef void* OSAHISRRef ;
typedef void* OSAMsgQRef ;
typedef void* OSAMailboxQRef ;
typedef void* OSAPartitionPoolRef ;
typedef UINT8 OS_STATUS ;
typedef void ( *USBDeviceTransactionCompletedNotifyFn ) ( USBDevice_EndpointE ,
 UINT8 * ,
 UINT32 ,
 BOOL ) ;
typedef void ( *USBDeviceStatusNotifyFn ) ( USBDevice_StatusE ) ;
typedef void ( *USBDeviceVendorClassRequestNotifyFn ) ( USB_SetupCmdS * ) ;
typedef void ( *USBDeviceEndpointZeroNotifyFn ) ( USB_SetupCmdS * ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointMultiTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT32 numOfBuffers ,
 USBDevice_MultiTransmitListS *pMultiList ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointTransmit ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pTxBuffer ,
 UINT32 txLength ,
 BOOL autoZLP ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelTransmit ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointCancelReceive ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompleted ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceiveCompletedExt ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 next_packet_expected_length ,
 BOOL expect_zlp ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointReceive ) ( USBDevice_EndpointE endpoint ,
 UINT8 *pRxBuffer ,
 UINT32 length ,
 BOOL expect_zlp ) ;
typedef void ( *fpUSBDeviceVendorClassResponse ) ( UINT8 *pBuffer ,
 UINT16 bufferLength ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointAbort ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointClose ) ( USBDevice_EndpointE endpoint ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointOpen ) ( USBDevice_EndpointE endpoint ,
 USBDevice_UsageTypeE usageType ,
 UINT8 dmaChannel ,
 UINT8 *pDescBuffer ,
 UINT16 descBufferLength ,
 USBDeviceTransactionCompletedNotifyFn transactionCompletedNotifyFn ) ;
typedef USBCDevice_ReturnCodeE ( *fpUSBDeviceEndpointStall ) ( USBDevice_EndpointE endpoint ) ;
typedef void ( *fpUSBDevicePhase2Init ) ( void ) ;
typedef BOOL ( *fpUSBDeviceIsControllerEnabled ) ( void ) ;
typedef void ( *fpUSBDeviceCableDetectionNotify ) ( USBCable_StatusE ) ;
typedef void ( *UsbWkpCallback ) ( void ) ;
typedef void ( *USBMgrControlIndicationFunc ) ( USBMgr_Status , USBMgr_Error , UINT32 ) ;
typedef void ( *USBMgrTxIndicationFunc ) ( UINT32 , UINT8 , UINT8* , UINT32 ) ;
typedef void ( *USBMgrRxIndicationFunc ) ( UINT8 , UINT8 * , UINT32 ) ;
typedef void ( *USBMgrSetupCommandRspFunc ) ( UINT8* , UINT16 ) ;
typedef void ( *USBMgrSetupCommandIndicationFunc ) ( USBMgr_SetupDataStruct * ) ;
typedef void * USBMGR_IF_HANDLER ;
//ICAT EXPORTED STRUCT 
 typedef struct RtcDateTag 
 {	 
 /* @STRUCT_DESC@ RTC date ( set or read ) */	 
 Int16 year ; /**< RTC year. */	 
 /* @ITEM_DESC@ RTC year @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number*/	 
 Int8 month ; /**< RTC month ( 1 -12 ) . */	 
 /* @ITEM_DESC@ RTC month @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number ( 1 -12 ) */	 
 Int8 day ; /**< RTC day of month ( 1 -31 ) . */	 
 /* @ITEM_DESC@ RTC day @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number ( 1 -31 ) */	 
 } 
 RtcDate;

//ICAT EXPORTED STRUCT 
 typedef struct RtcTimeTag 
 {	 
 /* @STRUCT_DESC@ RTC time ( set or read ) */	 
 Int8 hours ; /**< RTC hours ( 0 -23 ) . */	 
 /* @ITEM_DESC@ RTC hours @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number ( 0 -23 ) */	 
 Int8 minutes ; /**< RTC minutes ( 0 -59 ) . */	 
 /* @ITEM_DESC@ RTC minutes @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number ( 0 -59 ) */	 
 Int8 seconds ; /**< RTC seconds ( 0 -59 ) . */	 
 /* @ITEM_DESC@ RTC seconds @ITEM_MODE@ ReadWrite @ITEM_UNIT@ number ( 0 -59 ) */	 
 } 
 RtcTime;

typedef Int8 L1AudioVolume ;
typedef Int8 L1AudioChannel ;
typedef Int16 L1AudioFrequency ;
typedef L1AudioDevice L1AudioDeviceList [ 3 ] ;
typedef Int16 RecordNumber ;
typedef Int16 DataLength ;
typedef Int16 DataChecksum ;
typedef Int32 NvDataType ;
typedef EmptySignal L1AlAudioCustomToneReq ;
typedef EmptySignal L1AlAudioCustomToneStopReq ;
typedef EmptySignal L1AlAudioCustomToneStopInd ;
typedef EmptySignal L1AlAudioCustomToneBufferFreeInd ;
typedef EmptySignal L1AlMemoPlaybackBufferFreeReq ;
typedef EmptySignal L1AlMmacChannelStartReq ;
typedef EmptySignal L1AlMmacChannelStartCnf ;
typedef EmptySignal L1AlMmacChannelStopReq ;
typedef EmptySignal L1AlMmacChannelStopInd ;
typedef EmptySignal L1AlPCMStreamingInputReq ;
typedef EmptySignal L1AlPCMStreamingOutputReq ;
typedef EmptySignal L1AlPCMStreamingStopReq ;
typedef EmptySignal L1AlPCMStreamingInputCnf ;
typedef EmptySignal L1AlPCMStreamingOutputCnf ;
typedef EmptySignal L1AlPCMStreamingStopCnf ;
typedef EmptySignal L1AlMtsTimerStartReq ;
typedef EmptySignal L1AlMtsTimerStartCnf ;
typedef EmptySignal L1AlMtsTimerStopReq ;
typedef EmptySignal L1AlMtsTimerStopCnf ;
typedef EmptySignal L1AlBbcDebugReq ;
