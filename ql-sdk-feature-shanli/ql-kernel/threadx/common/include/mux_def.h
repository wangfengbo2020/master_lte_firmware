#ifndef _MUX_DEF_H_
#define _MUX_DEF_H_
typedef struct{
unsigned short service_id;
unsigned short priority;
unsigned short MTU;
unsigned short feature;
}dlc_cfg_parameter; 

/*the service identifier definition*/
#define Channel_Control      (0)
#define DLCAT_1				 (1)     
#define DLCAT_2				 (2)
#define DLCAT_3              (3)
#define DLCAT_4              (4)
#define DLCAT_5				 (5)
#define DLCAT_IND			 (6)
#define DLCAT_7				 (7)
#define DLCAT_8				 (8)

#define DLCATDATA_1              (9)
#define DLCATDATA_2              (10)
#define DLCATDATA_3              (11)
#define DLCATDATA_4              (12)
#define DLCATDATA_5              (13)
#define DLCATDATA_6              (14)
#define DLCATDATA_7              (15)
#define DLCATDATA_8              (16)
#define DLCATDATA_9              (17)
#define DLCATDATA_10              (18)
#define DLCATDATA_11			 (19)
#define DLCATDATA_12			 (20)
#define RELIABL_DATA		 (21)

#define Audio_Data 			 (33)	/*Marvell Audio control and data*/
#define NVM_Access  		 (34)	/*NVM access control*/
#define DIAG_DATA 				 (36)
#define TEST_DATA				 (37)
#define VTCSD_DATA				 (38)


#define RESERVED 				 (0xffff)

/*DLC channel feature*/
#define DLC_CONTROL_CHANNEL     (0)
#define DLC_AT_CHANNEL			(1)
#define DLC_AT_DATA_CHANNEL	    (2)
#define RAW_DATA_CHANNEL		(3)
#define MAX_DLC_NUM 32

#define customer_count (2)
#define default_mtu (1509)
#define max_retransmit_num (3)
#define datachannelmtu (2048)
#define AT_MODE 0      /*0:at mode;1:data mode*/
#define DATA_MODE 1       /*0:at mode;1:data mode*/
#define OTHER_MODE 3
/*service identifier define end*/
#define MUXDATAALIGN 				(4)


//ICAT EXPORTED ENUM
typedef enum {
	DLC_SVC_TYPE1=0,//APSE
	DLC_SVC_TYPE2  //INTEL
} DLC_SVC_TYPE;

//ICAT EXPORTED ENUM
typedef enum{
	MUX_USB=0,
	MUX_SPI,
	MUX_SDIO,
	MUX_HSI,
	MUX_ASI
}MUX_HAL_TYPE;

//ICAT EXPORTED STRUCT
typedef struct {
	DLC_SVC_TYPE DlcSvcType;
	MUX_HAL_TYPE MuxHalType;
} MUX27010Cfg_t;
typedef struct{
	unsigned char type;					/* custom type */
	DLC_SVC_TYPE MuxDlcSvcType;						/* custom name */
	MUX_HAL_TYPE MuxHalType;
}CUSTOM_MUX_MAP_ITEM;

#endif
