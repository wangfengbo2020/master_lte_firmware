/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/*
 * @Author: Pony.ma 
 * @Date: 2020-01-08 09:25:22 
 * @Last Modified by:   Pony.ma 
 * @Last Modified time: 2020-01-08 09:25:22 
 */


#ifndef _QL_SIM_H
#define _QL_SIM_H


#include "ql_gpio.h"

typedef enum
{
	QL_SIM_0,
	QL_SIM_1,
	NUM_OF_QL_SIM
}CMSimID_ex;

//ĞÎ²Î
typedef void (*SwitchSimDoneCb)(UINT8);

#define QL_SIM_MCC_LEN      4   /**  Length of the MCC. */
#define QL_SIM_MNC_MAX      4   /**  Maximum length of the MNC. */
#define QL_SIM_PLMN_NUM_MAX 24  /**  Maximum number of PLMN data sets. */

typedef void (*sim_detect_calback)(PIN_LEVEL_E pinlevel);

typedef enum 
{
	QL_SIM_SUCCESS,
	QL_SIM_GENERIC_FAILURE,
}QL_SIM_ERROR_CODE;



typedef struct 
{
    uint8_t mcc[QL_SIM_MCC_LEN];  /**< MCC value in ASCII characters.*/
    uint8_t mnc[QL_SIM_MNC_MAX];  /**< MNC value in ASCII characters.*/
}QL_SIM_PLMN_INFO;  

typedef struct 
{
    unsigned int          preferred_operator_list_num;                    /**< Must be set to the number of elements in preferred_operator_list. */
    QL_SIM_PLMN_INFO    preferred_operator_list[QL_SIM_PLMN_NUM_MAX];   /**< Preferred operator list. */
}QL_SIM_PREFERRED_OPERATOR_LIST;    /* Message */

#define QL_SIM_PIN_LEN_MAX  16   /**  Maximum length of PIN data. */ 
typedef struct 
{
    uint8_t                     pin_value[QL_SIM_PIN_LEN_MAX];  /*  Value of the PIN */
}QL_SIM_VERIFY_PIN_INFO;  

typedef struct 
{
    uint8_t                     old_pin_value[QL_SIM_PIN_LEN_MAX];  /**< Value of the old PIN as a sequence of ASCII characters. */
    uint8_t                     new_pin_value[QL_SIM_PIN_LEN_MAX];  /**< Value of the new PIN as a sequence of ASCII characters. */
}QL_SIM_CHANGE_PIN_INFO; 

typedef struct 
{
    uint8_t                     puk_value[QL_SIM_PIN_LEN_MAX];      /**< Value of the PUK as a sequence of ASCII characters. */
    uint8_t                     new_pin_value[QL_SIM_PIN_LEN_MAX];  /**< Value of the new PIN as a sequence of ASCII characters. */
}QL_SIM_UNBLOCK_PIN_INFO;  

typedef enum 
{
    QL_SIM_CARD_TYPE_UNKNOWN  = 0,    /**<  Unidentified card type.  */
    QL_SIM_CARD_TYPE_ICC      = 1,    /**<  Card of SIM or RUIM type.  */
    QL_SIM_CARD_TYPE_UICC     = 2,    /**<  Card of USIM or CSIM type.  */
}QL_SIM_CARD_TYPE;  
	
typedef enum 
{
   QL_SIM_STATUS_NOT_INSERTED,
   QL_SIM_STATUS_READY,
   QL_SIM_STATUS_SIM_PIN,
   QL_SIM_STATUS_SIM_PUK,
   QL_SIM_STATUS_PH_SIM_LOCK_PIN,
   QL_SIM_STATUS_PH_SIM_LOCK_PUK,
   QL_SIM_STATUS_PH_FSIM_PIN,
   QL_SIM_STATUS_PH_FSIM_PUK,
   QL_SIM_STATUS_SIM_PIN2,
   QL_SIM_STATUS_SIM_PUK2,
   QL_SIM_STATUS_PH_NET_PIN,
   QL_SIM_STATUS_PH_NET_PUK,
   QL_SIM_STATUS_PH_NET_SUB_PIN,
   QL_SIM_STATUS_PH_NET_SUB_PUK,
   QL_SIM_STATUS_PH_SP_PIN,
   QL_SIM_STATUS_PH_SP_PUK,
   QL_SIM_STATUS_PH_CORP_PIN,
   QL_SIM_STATUS_PH_CORP_PUK,
   QL_SIM_STATUS_BUSY,
   QL_SIM_STATUS_BLOCKED,
   QL_SIM_STATUS_UNKNOWN//20
}QL_SIM_STATUS;    /**< Card state. */

#define QL_SIM_ICCID_LEN 10
#define QL_SIM_IMSI_LEN 16

typedef struct {
    //QL_SIM_STATUS card_status;
    char imsi[QL_SIM_IMSI_LEN];
    UINT8 iccid[QL_SIM_ICCID_LEN*2+1];
    QL_SIM_STATUS card_status;
} QL_SIMCARD_INFO;

typedef struct 
{
    uint8_t                         pin1_num_retries;       /**<   Number of PIN 1 retries. */
    uint8_t                         puk1_num_retries;       /**<   Number of PUK 1 retries. */
    uint8_t                         pin2_num_retries;       /**<   Number of PIN 2 retries. */
    uint8_t                         puk2_num_retries;       /**<   Number of PUK 2 retries. */
}QL_SIM_CARD_PIN_INFO; 



typedef struct 
{
    QL_SIM_CARD_TYPE      card_type; // SIM card type
    QL_SIM_STATUS     card_state;  //SIM card state
    QL_SIM_CARD_PIN_INFO  card_pin_info; // PIN info
}QL_SIM_CARD_INFO; 

typedef enum 
{
    QL_SIM_FILE_TYPE_UNKNOWN      = 0,/**<  Unknown file type  */
    QL_SIM_FILE_TYPE_TRANSPARENT  = 1,/**< File structure consisting of a sequence of bytes.  */
    QL_SIM_FILE_TYPE_CYCLIC       = 2,/**< File structure consisting of a sequence of records, each containing the same fixed size in 
                                                     chronological order. Once all the records have been used, the oldest data is overwritten.  */
    QL_SIM_FILE_TYPE_LINEAR_FIXED  = 3,    /**< File structure consisting of a sequence of records, each containing the same fixed size.  */
}QL_SIM_FILE_TYPE;

typedef enum 
{
    QL_SIM_FILE_ACCESS_TYPE_ALWAYS      =0,
    QL_SIM_FILE_ACCESS_TYPE_CHV1        =1,
    QL_SIM_FILE_ACCESS_TYPE_CHV2        =2,
    QL_SIM_FILE_ACCESS_TYPE_ADM         =3,
}QL_SIM_FILE_ACCESS_TYPE;
	
typedef struct 
{
    QL_SIM_FILE_ACCESS_TYPE read_access;
    QL_SIM_FILE_ACCESS_TYPE update_access;
}QL_SIM_FILE_ACCESS_INFO;

typedef enum 
{
    QL_SIM_FILE_STATUS_INVALID      =0,
    QL_SIM_FILE_STATUS_EFFECTIVE    =1,
}QL_SIM_FILE_STATUS;


typedef struct 
{
    unsigned int                id;
    QL_SIM_FILE_TYPE            type;    /**<   File type: */
    QL_SIM_FILE_ACCESS_INFO     access;    /**<   File access conditions: */
    QL_SIM_FILE_STATUS          status;    /**<   File status: */
    unsigned int                size;      /**<   Size of transparent files.*/
    unsigned int                record_len;    /**<   Size of each cyclic or linear fixed file record.*/
    unsigned int                record_count;   /**<   Number of cyclic or linear fixed file records.*/
}QL_SIM_FILE_INFO; 

typedef struct 
{
    int sw1;
    int sw2;
}QL_SIM_FILE_OPERATION_RET;

#define QL_SIM_DATA_LEN_MAX     255
typedef struct 
{
    unsigned int    data_len;                        /**< Must be set to the number of elements in data. */
    uint8_t     data[QL_SIM_DATA_LEN_MAX];       /**< Data retrieved from the card. */
}QL_SIM_CARD_FILE_DATA; 

typedef enum
{
    QL_SIM_PHONE_BOOK_STORAGE_DC,
    QL_SIM_PHONE_BOOK_STORAGE_EN,
    QL_SIM_PHONE_BOOK_STORAGE_FD,
    QL_SIM_PHONE_BOOK_STORAGE_LD,
    QL_SIM_PHONE_BOOK_STORAGE_MC,
    QL_SIM_PHONE_BOOK_STORAGE_ME,
    QL_SIM_PHONE_BOOK_STORAGE_MT,
    QL_SIM_PHONE_BOOK_STORAGE_ON,
    QL_SIM_PHONE_BOOK_STORAGE_RC,
    QL_SIM_PHONE_BOOK_STORAGE_SM,
    QL_SIM_PHONE_BOOK_STORAGE_AP,
    QL_SIM_PHONE_BOOK_STORAGE_MBDN,
    QL_SIM_PHONE_BOOK_STORAGE_MN,
    QL_SIM_PHONE_BOOK_STORAGE_SDN,
    QL_SIM_PHONE_BOOK_STORAGE_ICI,
    QL_SIM_PHONE_BOOK_STORAGE_OCI,
}QL_SIM_PHONE_BOOK_STORAGE;

#define QL_SIM_PHONE_BOOK_RECORDS_MAX_COUNT 20

typedef struct 
{ // when write, if phonenum is empty, it means to delete this item specified by index  
    int          index;  // the record index in phone book
    uint8_t      username[32];   //  username
    uint8_t      phonenum[24];   //  Phone number, it can include '+'*/
}QL_SIM_PHONE_BOOK_RECORD_INFO;


typedef struct 
{
    int record_count;  //the count of record
    QL_SIM_PHONE_BOOK_RECORD_INFO record[QL_SIM_PHONE_BOOK_RECORDS_MAX_COUNT]; // the list of record
}QL_SIM_PHONE_BOOK_RECORDS_INFO;

typedef enum {
	QL_SIM_QPINC_QUERY_SC = 0, //(U)SIM PIN
	QL_SIM_QPINC_QUERY_P2,	   //(U)SIM PIN2
}QL_SIM_PIN_FACILITY;

typedef struct {
    QL_SIM_PIN_FACILITY sim_facility;
    int pincounter; 	//Number of attempts left to enter the password of PIN
    int pukcounter;		//Number of attempts left to enter the password of PUK.
}QL_SIM_PIN_REMAINDER_COUNTER;

/*****************************************************************
* Function: ql_sim_get_cur_SimId
*
* Description:
* 	get current sim ID
*   (Ë«¿¨µ¥´ıÄ£Ê½ÏÂ)»ñÈ¡µ±Ç°Ö÷¿¨ÊÇSIM¼¸
* Parameters:
* 	
* 	
* Return:
* 	0--sim1
*	1--sim2
*
*****************************************************************/
extern int ql_sim_get_cur_SimId(void);

/*****************************************************************
* Function: ql_sim_switch_card
*
* Description:
* 	switch current sim card 
* 
* Parameters:
* 	simID--what you want to set now
*   callbk--when switch sim done, will run it
* 	
* Return:
* 	0--success
*  -1--fail
*
*****************************************************************/
extern int ql_sim_switch_card(int simID);

/*****************************************************************
* Function: ql_sim_switch_card_ex
*
* Description:
* 	switch current sim card 
* 
* Parameters:
* 	simID--the simcard you want to set now
*   callbk--when switch sim done, will run it
* 	
* Return:
* 	0--success
*  -1--fail
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_switch_card_ex(CMSimID_ex simID, SwitchSimDoneCb cb);
/*****************************************************************
* Function: ql_sim_get_simcard_info
*
* Description:
* 	»ñÈ¡µÄ¿¨µÄĞÅÏ¢(Èçimsi,iccid)
* 
* Parameters:
* 	simID--0£»¿¨1£»1£»¿¨2
*   pt_info--»ñÈ¡µÄĞÅÏ¢´æ´¢µÄÎ»ÖÃ
* 	
* Return:
* 	0--success
*  -1--fail
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_get_simcard_info(QL_SIMCARD_INFO *pt_info, CMSimID_ex sim_id);

/*****************************************************************
* Function: ql_sim_get_imsi
*
* Description:
* 	»ñÈ¡ SIM ¿¨µÄ IMSI¡£
* 
* Parameters:
* 	imsi	  		[out] 		SIM ¿¨µÄ IMSI£¬×Ö·û´®¡£  
* 	imsi_len	  	[in] 		imsi Êı×éµÄ³¤¶È¡£
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_get_imsi(char *imsi,size_t imsi_len);


/*****************************************************************
* Function: ql_sim_get_iccid
*
* Description:
* 	»ñÈ¡ SIM ¿¨µÄ ICCID¡£
* 
* Parameters:
* 	iccid	  		[out] 		SIM ¿¨µÄ ICCID£¬×Ö·û´®¡£ 
* 	iccid_len	  	[in] 		iccid Êı×éµÄ³¤¶È¡£  
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_get_iccid(char *iccid,size_t iccid_len);


/*****************************************************************
* Function: ql_sim_get_phonenumber
*
* Description:
* 	»ñÈ¡ SIM ¿¨±¾»úºÅÂë¡£ 
* 
* Parameters:
* 	phonenumber	  		[out] 	SIM ¿¨±¾»úºÅÂë£¬×Ö·û´®¡£  
* 	phonenumber_len	  	[in] 	phonenumber Êı×éµÄ³¤¶È¡£  
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_get_phonenumber(char *phonenumber,size_t phonenumber_len);


/*****************************************************************
* Function: ql_sim_verify_pin
*
* Description:
* 	µ± SIM ×´Ì¬ÎªÇëÇó PIN/PIN2£¬ÊäÈë PIN/PIN2 Âë£¬½øĞĞÑéÖ¤¡£ 
* 
* Parameters:
* 	pt_info	  			[in] 	PIN/PIN2 Âë£¬¼û QL_SIM_VERIFY_PIN_INFO¡£ 
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_verify_pin(QL_SIM_VERIFY_PIN_INFO       *pt_info); // [IN] PIN/PIN2


/*****************************************************************
* Function: ql_sim_change_pin
*
* Description:
* 	¸ü¸Ä SIM ¿¨µÄ PIN Âë
* 
* Parameters:
* 	pt_info	  			[in] 	ÊäÈë¾ÉµÄ PIN ºÍĞÂµÄ PIN£¬¼û QL_SIM_CHANGE_PIN_INFO¡£  
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_change_pin(QL_SIM_CHANGE_PIN_INFO       *pt_info );  // [IN] PIN


/*****************************************************************
* Function: ql_sim_unblock_pin
*
* Description:
* 	µ±¶à´Î´íÎóÊäÈë PIN/PIN2 Âëºó£¬SIM ¿¨×´Ì¬ÎªÇëÇó PUK/PUK2 Ê±£¬
*	ÊäÈë PUK/PUK2 ÂëºÍĞÂµÄ PIN/PIN2 Âë½øĞĞ½âËø¡£
* 
* Parameters: 
* 	pt_info	  			[in] 	ÊäÈë PUK/PUK2 ÂëºÍĞÂµÄ PIN/PIN2 Âë£¬¼û QL_SIM_UNBLOCK_PIN_INFO¡£  
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_unblock_pin(QL_SIM_UNBLOCK_PIN_INFO       *pt_info);// [IN] input PUK/PUK2 and new PIN/PIN2


/*****************************************************************
* Function: ql_sim_enable_pin
*
* Description:
* 	ÆôÓÃ SIM ¿¨ PIN ÂëÑéÖ¤¡£ 
* 
* Parameters: 
* 	pt_info			  	[in] 	ÊäÈë PIN Âë£¬¼û QL_SIM_VERIFY_PIN_INFO¡£ 
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_enable_pin(QL_SIM_VERIFY_PIN_INFO       *pt_info);// [IN] PIN


/*****************************************************************
* Function: ql_sim_disable_pin
*
* Description:
* 	¹Ø±Õ SIM ¿¨ PIN ÂëÑéÖ¤
* 
* Parameters:
* 	pt_info	  			[in] 	ÊäÈë PIN Âë£¬¼û QL_SIM_VERIFY_PIN_INFO¡£ 
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_disable_pin(QL_SIM_VERIFY_PIN_INFO       *pt_info );  // [IN] PIN 


/*****************************************************************
* Function: ql_sim_get_card_status
*
* Description:
* 	»ñÈ¡ µ±Ç°SIM ¿¨(Ö÷¿¨)×´Ì¬ĞÅÏ¢¡£
* 
* Parameters:
* 	card_status	  		[out] 	·µ»Ø SIM ¿¨ÀàĞÍĞÅÏ¢£¬¼û QL_SIM_STATUS 
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_get_card_status(int         *card_status);///< [OUT] sim card status info output


/*****************************************************************
* Function: ql_sim_read_phonebook_record
*
* Description:
* 	»ñÈ¡ SIM ¿¨ÉÏÖ¸¶¨µç»°±¾ÖĞµÄÒ»Ìõ»ò¶àÌõµç»°ºÅÂë¼ÇÂ¼¡£ 
* 
* Parameters:
* 	storage	  		[in] 	ĞèÒª¶ÁÈ¡µç»°ºÅÂë¼ÇÂ¼µÄµç»°±¾´æ´¢Î»ÖÃ¡£¼û QL_SIM_PHONE_BOOK_STORAGE ¡£ 
* 	start_index	  	[in] 	ĞèÒª¶ÁÈ¡µç»°ºÅÂë¼ÇÂ¼µÄÆğÊ¼±àºÅ¡£start_index Îª 0 ±íÊ¾²»Ê¹ÓÃ±àºÅ»ñÈ¡µç»°ºÅÂë¼ÇÂ¼¡£  
* 	end_index	  	[in] 	ĞèÒª¶ÁÈ¡µç»°ºÅÂë¼ÇÂ¼µÄ½áÊø±àºÅ¡£  
* 	username	  	[in] 	µ± start_index Îª 0 Ê±ÓĞĞ§£¬µç»°ºÅÂëÖĞµÄÓÃ»§Ãû¡£  
* 	records	  		[out] 	·µ»Øµç»°ºÅÂë¼ÇÂ¼ÁĞ±í£¬¼û QL_SIM_PHONE_BOOK_RECORDS_INFO¡£  
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_read_phonebook_record
(
    QL_SIM_PHONE_BOOK_STORAGE storage, //IN the storage position of the phone book
    int start_index,
    int end_index,
    char *username,
    QL_SIM_PHONE_BOOK_RECORDS_INFO   *records  // the list of records 
);

extern QL_SIM_ERROR_CODE ql_sim_read_phonebook_record_ex
(
    QL_SIM_PHONE_BOOK_STORAGE storage, //IN the storage position of the phone book
    int start_index,
    int end_index,
    char *username,
    QL_SIM_PHONE_BOOK_RECORDS_INFO   *records  // the list of records 
);

/*****************************************************************
* Function: ql_sim_write_phonebook_record
*
* Description:
* 	»ñÈ¡ SIM ¿¨ÉÏÖ¸¶¨µç»°±¾ÖĞµÄÒ»Ìõ»ò¶àÌõµç»°ºÅÂë¼ÇÂ¼¡£ 
* 
* Parameters:
* 	storage	  		[in] 	ĞèÒª¶ÁÈ¡µç»°ºÅÂë¼ÇÂ¼µÄµç»°±¾´æ´¢Î»ÖÃ¡£   
* 	record	  		[in] 	ĞèÒªĞ´ÈëµÄµç»°ºÅÂë¼ÇÂ¼£¬¼û QL_SIM_PHONE_BOOK_RECORD_INFO¡£ 
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
extern QL_SIM_ERROR_CODE ql_sim_write_phonebook_record
(
    QL_SIM_PHONE_BOOK_STORAGE storage, //IN the storage position of the phone book
    QL_SIM_PHONE_BOOK_RECORD_INFO   *record //IN  a record
);

/*****************************************************************
* Function: ql_sim_config_detect
*
* Description:
* 	ÅäÖÃSIM¿¨ÈÈ²å°Î¹¦ÄÜ¡£ 
* 
* Parameters:
* 	detenable	  		[in] 	ÊÇ·ñÊ¹ÄÜSIM ¼ì²â(0--²»Ê¹ÄÜ,1--Ê¹ÄÜ)¡£   
* 	insertlevel	  		[in] 	SIM¿¨²åÈëÊ±ºòµÄSIM¿¨½ÅµçÆ½(0--µÍµçÆ½,1--¸ßµçÆ½) 
*   detectcallback      [in]    µ±¼ì²âµ½SIM¿¨¼ì²â½ÅÓĞÌø±ä,Õâ¸öcallback»á±»Ö´ĞĞ
* Return:
* 	QL_SIM_SUCCESS				³É¹¦¡£
*	QL_SIM_GENERIC_FAILURE		Ê§°Ü¡£
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_config_hot_plug_detect(unsigned char  detenable,PIN_LEVEL_E insertlevel,sim_detect_calback detectcallback);

/*****************************************************************
* Function: ql_set_dual_sim_single_imei
*
* Description:
* 	To support dual sim single IMEI 
* 
* Parameters:
* 	enable	  		[in] 	0-Not support dual sim single imei; 1-Support.
*
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
* Note: This setting will be saved to nvm and will take effect after reset.
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_set_dual_sim_single_imei(unsigned char enable);

/*****************************************************************
* Function: ql_sim_open_logical_channel
*
* Description:
* 	 è¯¥å‘½ä»¤ç”¨äºå¼€å¯(U)SIMå¡çš„é€»è¾‘ä¿¡é“(AT+CCHO)
* 
* Parameters:
* 	dfName	  		[in] 	å­—ç¬¦ä¸²ç±»å‹ã€‚UICC ä¸­çš„æ‰€æœ‰å¯é€‰åº”ç”¨ç¨‹åºï¼Œä»¥1 åˆ°16 å­—èŠ‚æ–¹å¼ç¼–ç çš„DF åç§°æ¥å¼•ç”¨ã€‚
* 	sessionId	  	[out] 	UINT16*ç±»å‹ã€‚æ™ºèƒ½å¡ä¸Šçš„ç›®æ ‡åº”ç”¨ç¨‹åºä½¿ç”¨é€»è¾‘ä¿¡é“çš„ä¼šè¯IDã€‚
*
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_open_logical_channel(char *dfName, UINT16* sessionId);

/*****************************************************************
* Function: ql_sim_close_logical_channel
*
* Description:
* 	 è¯¥å‘½ä»¤ä½¿ç”¨æŒ‡å®šçš„<sessionID>å…³é—­(U)SIMå¡çš„é€»è¾‘ä¿¡é“(AT+CCHC)
* 
* Parameters:
* 	sessionId	  		[in] 	æ•´å‹ã€‚æ™ºèƒ½å¡ä¸Šçš„ç›®æ ‡åº”ç”¨ç¨‹åºä½¿ç”¨é€»è¾‘ä¿¡é“çš„ä¼šè¯IDã€‚
*
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_close_logical_channel(UINT16 sessionId);

/*****************************************************************
* Function: ql_sim_access_logical_channel
*
* Description:
* 	 è¯¥å‘½ä»¤ç”¨äºè®¿é—®UICCé€»è¾‘ä¿¡é“(AT+CGLA)
* 
* Parameters:
* 	sessionId	  		[in] 	æ•´å‹ã€‚ä¼šè¯IDã€‚ç”¨äºå°†APDU å‘½ä»¤å‘é€åˆ°UICC çš„ä¼šè¯çš„æ ‡è¯†ç¬¦ã€‚æ™ºèƒ½å¡ä¸Šçš„ç›®æ ‡åº”ç”¨ç¨‹åºä½¿ç”¨é€»è¾‘ä¿¡é“è€Œéé»˜è®¤ä¿¡é“ï¼ˆä¿¡é“"0"ï¼‰æ—¶ï¼Œå¿…é¡»è¾“å…¥è¯¥å‚æ•°å‘UICC å‘é€å‘½ä»¤ã€‚
* 	commandlength	  	[in] 	æ•´å‹ã€‚åœ¨ <command> ä¸­å‘é€ç»™TEçš„å­—ç¬¦é•¿åº¦ï¼ˆæ˜¯å‘½ä»¤æˆ–å“åº”å®é™…é•¿åº¦çš„ä¸¤å€ï¼‰ã€‚
* 	command 	  		[in] 	åå…­è¿›åˆ¶å­—ç¬¦æ ¼å¼ã€‚MT ä¼ é€’ç»™UICC çš„å‘½ä»¤ã€‚è¯¦æƒ…å¯å‚è€ƒ3GPP TS 31.101ä¸­çš„ AT+CSCSã€‚
* 	resplength	  		[out] 	UINT16*ç±»å‹ã€‚åœ¨<response> ä¸­å‘é€ç»™TEçš„å­—ç¬¦é•¿åº¦ï¼ˆæ˜¯å‘½ä»¤æˆ–å“åº”å®é™…é•¿åº¦çš„ä¸¤å€ï¼‰ã€‚ 
* 	response	  		[out] 	åå…­è¿›åˆ¶å­—ç¬¦æ ¼å¼ã€‚UICC ç»™MT ä¼ é€’çš„å‘½ä»¤çš„å“åº”ã€‚è¯¦æƒ…å¯å‚è€ƒ3GPP TS 31.101ä¸­çš„ AT+CSCSã€‚
* 	
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_access_logical_channel(UINT16 sessionId, UINT16 commandlength, char *command, UINT16* resplength, char *response);

/*****************************************************************
* Function: ql_sim_display_pin_remainder_counter
*
* Description:
* 	queries the number of attempts left to enter the password of (U)SIM PIN/PUK 
* 
* Parameters:
* 	sim_pin_facility					[in] 	0/1 (0--"SC"(U)SIM PIN, 1--"P2"(U)SIM PIN2)ã€‚   
* 	sim_pin_remainder_counter	  		[out] 	number of attempts left to enter the password of (U)SIM PIN/PUK,As shown in QL_SIM_PIN_REMAINDER_COUNTER
*
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_display_pin_remainder_counter(QL_SIM_PIN_FACILITY sim_pin_facility, QL_SIM_PIN_REMAINDER_COUNTER *sim_pin_remainder_counter);

/*****************************************************************
* Function: ql_sim_facility_possword_change
*
* Description:
* 	sets a new password for the facility lock function defined by command Facility Lock +CLCK. 
* 
* Parameters:
* 	sim_pin_facility					[in] 	0-"SC"(U)SIM PIN, 1-"P2"(U)SIM PIN2ã€‚Currently, only SC is supported
* 	oldpwd                  	  		[in] 	old password
* 	oldpwd                  	  		[in] 	new password
*
* Return:
* 	QL_SIM_SUCCESS				Operation success.
*	QL_SIM_GENERIC_FAILURE		Operation failed.
*
*****************************************************************/
QL_SIM_ERROR_CODE ql_sim_facility_possword_change(QL_SIM_PIN_FACILITY sim_pin_facility, char* oldpwd, char* newpwd);

#endif

