/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.

 NOTE:usb hid demo fucntion use two usb interface,
 one is hid standard keyborad another is a customer hid device.
 all follow Device Class Definition for Human Interface Devices (HID).
 The keyborad is report device which is free driver usage as we all known.
 The customer hid interface is used for data transmition between host and device.

=================================================================*/

#include <stdio.h>
#include "ql_application.h"
#include "ql_usb_hid.h"

#define QL_KEYBOARD_REPORT_SIZE  8    //don't change it, one time report size must max is 8 byte, because it's hid keyboard report descript;
#define QL_CUST_HID_REPORT_SIZE  64   //don't change it, one time report size must max is 64 byte because usb interruct ep max len;
#define hid_max(a, b) (((a) > (b)) ? (a) : (b))
#define hid_min(a, b) (((a) < (b)) ? (a) : (b))

#define APP_DEBUG(fmt, args...)				printf(fmt, ##args)

/*KEYBOARD REPORT FORMATE

[Modifier Codes][Reserved][ Key arrays]
 Modifier Codes       8 bit  
			.... ...0 = Key: LeftControl: bit 0
			.... ..0. = Key: LeftShift: bit 1
			.... .0.. = Key: LeftAlt: bit 2
			.... 0... = Key: LeftGUI: bit 3
			...0 .... = Key: RightControl: bit 4
			..0. .... = Key: RightShift: bit 5
			.0.. .... = Key: RightAlt: bit 6
			0... .... = Key: RightGUI:bit 7
 Reserved byte        1 byte -> hold 0x00
 Key code arrays      6 byte 
 more infomation see HID Usage Tables FOR Universal Serial Bus
*/

// keyboard test value array
UINT8 key_value[8][QL_KEYBOARD_REPORT_SIZE] = 
{
	{0x00, 0x00, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},// a b c ...
	{0x02, 0x00, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},// shitf + a b c  ... = ABC...
	{0x02, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04},// A
	{0x00, 0x00, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x00},
	{0x01, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00},//ctrl + z


	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//end 
};
// key value send need send emty data sync state.
UINT8 key_empty_data[QL_KEYBOARD_REPORT_SIZE] = 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

typedef struct
{
	unsigned char ascii;
	unsigned char key;
	unsigned char shift;
} ql_asc_trans_key;

//more infomation see HID Usage Tables FOR Universal Serial Bus (USB)-10 Keyboard/Keypad Page (0x07) and ascii table.
ql_asc_trans_key ql_key_map[]=
{
	//a - z 
	{0x61,0x04,0x00},{0x62,0x05,0x00},{0x63,0x06,0x00},{0x64,0x07,0x00},
	{0x65,0x08,0x00},{0x66,0x09,0x00},{0x0A,0x67,0x00},{0x68,0x0B,0x00},
	{0x69,0x0C,0x00},{0x6A,0x0D,0x00},{0x6B,0x0E,0x00},{0x6C,0x0F,0x00},
	{0x6D,0x10,0x00},{0x6E,0x11,0x00},{0x6F,0x12,0x00},{0x70,0x13,0x00},
	{0x71,0x14,0x00},{0x72,0x15,0x00},{0x73,0x16,0x00},{0x74,0x17,0x00},
	{0x75,0x18,0x00},{0x76,0x19,0x00},{0x77,0x1A,0x00},{0x78,0x1B,0x00},
	{0x79,0x1C,0x00},{0x7A,0x1D,0x00},
	//A -- Z shift+
	{0x41,0x04,0x01},{0x42,0x05,0x01},{0x43,0x06,0x01},{0x44,0x07,0x01},
	{0x45,0x08,0x01},{0x46,0x09,0x01},{0x4A,0x67,0x01},{0x48,0x0B,0x01},
	{0x49,0x0C,0x01},{0x4A,0x0D,0x01},{0x4B,0x0E,0x01},{0x4C,0x0F,0x01},
	{0x4D,0x10,0x01},{0x4E,0x11,0x01},{0x4F,0x12,0x01},{0x50,0x13,0x01},
	{0x51,0x14,0x01},{0x52,0x15,0x01},{0x53,0x16,0x01},{0x54,0x17,0x01},
	{0x55,0x18,0x01},{0x56,0x19,0x01},{0x57,0x1A,0x01},{0x58,0x1B,0x01},
	{0x59,0x1C,0x01},{0x5A,0x1D,0x01},
	//0 1 2 3 - 9
	{0x30,0x27,0x00},{0x31,0x1E,0x00},{0x32,0x1F,0x00},{0x33,0x20,0x00}, 
	{0x34,0x21,0x00},{0x35,0x22,0x00},{0x36,0x23,0x00},{0x37,0x24,0x00}, 
	{0x38,0x25,0x00}, {0x39,0x26,0x00}, 
	//shift+
	{0x29,0x27,0x01}, // )
	{0x21,0x1E,0x01}, // !
	{0x40,0x1F,0x01}, // @
	{0x23,0x20,0x01}, // #
	{0x24,0x21,0x01}, // $
	{0x25,0x22,0x01}, // %
	{0x5E,0x23,0x01}, // ^
	{0x26,0x24,0x01}, // &
	{0x2A,0x25,0x01}, // *
	{0x28,0x26,0x01}, // (
	{0x20,0x2C,0x00}, // space 
	{0x0D,0x28,0x00}, // enter

	// Add more if you need

	{0x00,0x00,0x00}// map end
};

ql_asc_trans_key* quec_key_find_by_assii(ql_asc_trans_key* map, unsigned char ascii)
{
	ql_asc_trans_key* map_ptr = NULL;
	map_ptr = map;
	do
	{
		if(map_ptr->ascii == ascii){
			return map_ptr;
		}
		map_ptr++;
	} while(map_ptr->ascii != 0x00 && map_ptr->key != 0x00);
	
	return NULL;
}

void quec_usb_hid_sta_keyboard_test(ql_uhid_dev* dev)
{
	int i = 0;
	ql_asc_trans_key *trans_key = NULL;
	unsigned char key_array[QL_KEYBOARD_REPORT_SIZE] = {0};
	char test_str[]="abcdefghijklmnopqrstuvwxyz 1234567890 !@#$%^&*() ABCDEFGHIJKLMNOPQRSTUVWXYZ 1!@2#3DeStIn\r\n";
	int ret = 0;
	
	printf("usb_hid_sta_keyboard_test in");
	// way 1:ascii report test
	for(i = 0;i < strlen(test_str);i++ ){
		trans_key = quec_key_find_by_assii(&ql_key_map, test_str[i]);
		if(trans_key != NULL){
			//printf("trans_key:0x%x shift:0x%x\r\n", trans_key->key, trans_key->shift);
			if(trans_key->shift){
				key_array[0] = 0x02;// shift down
				//NOTE most PC keyboard language input mode change is with Shift, please keep it colse.
			}

			// only report one byte once time.
			key_array[2] = trans_key->key;
			ret = dev->send(key_array, QL_KEYBOARD_REPORT_SIZE);
			if(ret != USB_DEVICE_RC_OK) {
				printf("key_array send error %d",ret);
			}
			ret = dev->send(key_empty_data, QL_KEYBOARD_REPORT_SIZE);
			if(ret != USB_DEVICE_RC_OK) {
				printf("key_empty_data send error %d",ret);
			}

			memset(key_array, 0, sizeof(key_array));
			ql_rtos_task_sleep_ms(20);//host interval
		}
	}

	// way 2:raw key report test
	if(dev->id == QL_USB_HID_DEV_KEYBOARD){
		if(dev->send != NULL){
			ret = dev->send(key_value[0], QL_KEYBOARD_REPORT_SIZE);
			if(ret != USB_DEVICE_RC_OK) {
				printf("key_value send error %d",ret);
			}
			ret = dev->send(key_empty_data, QL_KEYBOARD_REPORT_SIZE);
			if(ret != USB_DEVICE_RC_OK) {
				printf("key_empty_data send error %d",ret);
			}

		}
	}
	
	printf("usb_hid_sta_keyboard_test leave.");
	
}

void quec_usb_hid_cust_hid_recv_cb(char * buf, char len)
{
	char recv_buf[64+1] = {0};
	memcpy(recv_buf, buf, len);
	printf("recv form cust hid buf[%d]:\r\n%s", len, recv_buf);
	//NOTE:in high level task process, please keep lowest latency in this function.
	
}

void quec_usb_hid_cust_hid_test(ql_uhid_dev* dev)
{
	char test_buf[QL_CUST_HID_REPORT_SIZE] = "abc123%!~?[]1234567890<>@##%";
    int ret = 0;
    char dtd_num = 0;
	//send data
	if(dev->id == QL_USB_HID_DEV_CUST_HID){
		if(dev->send != NULL){
			printf("usb_hid_cust_hid_test send ");
			dtd_num = ql_usb_device_get_hid_dtd_cnt(QL_USB_HID_DEV_CUST_HID);
			if(dtd_num > 20) {
				printf("dtd cnt %d stop send\r\n",dtd_num);
			//	ql_usb_device_free_hid_dtd(QL_USB_HID_DEV_CUST_HID);  //The upper computer has not released the data mounted on the current dtd or is waiting for the data to be removed
				return;
			}
			ret = dev->send(test_buf, hid_min(strlen(test_buf), QL_CUST_HID_REPORT_SIZE));
			if(ret != USB_DEVICE_RC_OK) {
				printf("usb_hid_cust_hid_test send error %d",ret);
			}
		}
	}
}

static void quec_usb_hid_test(void * argv)
{
	int ret = 0;
	ql_uhid_dev* dev_keyboard = NULL;
	ql_uhid_dev* dev_cust_hid = NULL;
	ql_rtos_task_sleep_s(10);

	APP_DEBUG("<------example_usb_hid.c------>\r\n");
	//dev_keyboard; a standard keyborad hid device a single direction device.
	dev_keyboard = ql_usb_hid_get_device(QL_USB_HID_DEV_KEYBOARD); 
	//dev_cust_hid; a customer hid device with both direction's transmition.
	dev_cust_hid = ql_usb_hid_get_device(QL_USB_HID_DEV_CUST_HID); 
	if(dev_cust_hid != NULL ){
		//register recv data callback.
		ret = ql_usb_hid_recv_set_cb(dev_cust_hid, quec_usb_hid_cust_hid_recv_cb);
		if(ret != 0){
			APP_DEBUG("ql_usb_hid_set_recv_cb err!!\r\n");
		}
	}

	while(1)
	{
		APP_DEBUG("heap size=%d\r\n", ql_rtos_get_free_heap_size());
		quec_usb_hid_cust_hid_test(dev_cust_hid);
		ql_rtos_task_sleep_s(5);
		//quec_usb_hid_sta_keyboard_test(dev_keyboard);
		//ql_rtos_task_sleep_s(5);
	}

}

//application_init(quec_usb_hid_test, "qUsbHidT", 2, 0);



