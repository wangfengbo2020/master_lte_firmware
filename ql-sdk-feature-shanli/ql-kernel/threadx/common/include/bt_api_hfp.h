#ifndef BT_API_HFP_H
#define BT_API_HFP_H

#define BT_CALL_BLOCK_COUNT     15
#define BT_CALL_WHITE_LIST_COUNT 20
struct bt_call_block {
    unsigned char list[BT_CALL_BLOCK_COUNT][MAX_BT_PHONE_NUMBER];
};

struct bt_call_white {
    unsigned char list[BT_CALL_WHITE_LIST_COUNT][MAX_BT_PHONE_NUMBER];
};

enum ciev_index {
    CIEV_CALL = 0,
    CIEV_CALLSETUP, /* 0: means not currently in call setup.
                       1: means an incoming call process ongoing
                       2: means an outgoing call setup is ongoing (outgoing call setup in dialing state)
                       3: means remote party being alerted in an outgoing call (outgoing call setup in alerting state) */
    CIEV_SERVICE,
    CIEV_SIGNAL,
    CIEV_ROAMING,
    CIEV_BATTERY_CHAGER,
    CIEV_CALLHELD, /* 0: no call on hold
                      1: a call is placed on hold or active/held calls swapped
                      2: call on hold, no call active */
};

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

void appbt_hfp_init(void);

// API: internal used, for record init
void appbt_hfp_init_call_record(void);


// API: set phone block number list
int appbt_hfp_set_blocklist(struct bt_call_block *block);
int appbt_hfp_set_whitelist(struct bt_call_white *white);

// API: setup a HFP connection to other device
// Parameters: address of target device
int appbt_hfp_connect(struct bt_addr addr, int call_status);

// API: disconnect HFP connection
int appbt_hfp_disconnect(void);

// API: accept HFP connection, initiate by HF
// Parameters: call_status: 0 - no call
//                          1 - incomming
//                          2 - out going
//                          4 - active
//                          5 - active + held
//             addr: address of HF
int appbt_hfp_accept_connection(int call_status, struct bt_addr addr);

// API: reject HFP connection, initiate by HF
int appbt_hfp_reject_connection(struct bt_addr addr);

// API: send call status to remote device
int appbt_hfp_update_callstatus(enum ciev_index index, int value, int delay);

// API: send phone number to remote device
int appbt_hfp_update_phone_number(const char *num, int type);

// API: send call hold status(+BTRH:xx) to remote device
// Parameters: 0 - the incoming call on hold
//             1 - accepting the call 
//             2 - incoming call was rejected
int appbt_hfp_update_callhold(int status);

// API: hold the call
int appbt_hfp_callhold(int reject);

// API: active or deactive voice recogonition function
int appbt_hfp_voice_recogonition(int enable);

// API: set speaker gain of HFP
int appbt_hfp_set_speaker_gain(int gain);

int appbt_hfp_send_AT_rawdata(const char *data, int length);

// API: set microphone gain of HFP
int appbt_hfp_set_microphone_gain(int gain);

// API: setup a SCO connection to other device
// Parameters: address of target device
int appbt_sco_connect(struct bt_addr addr);

// API: disconnect SCO connection
// Parameters: SCO handle
int appbt_sco_disconnect(unsigned short int handle);

int appbt_switch_voice_to_phone(void);

int appbt_switch_voice_to_headset(void);

int appbt_get_sco_status(void);
#ifdef QUECTEL_PROJECT_CUST
	void quec_bt_hfp_atchld(struct bt_task_event * msg);
	#endif

#ifdef __cplusplus
}
#endif // __cplusplus 

#endif

