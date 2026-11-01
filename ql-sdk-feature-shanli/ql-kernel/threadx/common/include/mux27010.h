#ifndef _MUX27010_H_
#define _MUX27010_H_
#include "mux_def.h"
typedef enum{
	DlcOpened=1,
	DlcClosed,
	DlcFlowBlockedPeer,
	DlcFlowUnblockedPeer,
	DlcFlowBlockedBufOver,
	DlcFlowUnblockedBufover
}DlcLinkStatus;
typedef void (*tx_done_t)(unsigned int dlc,void* buffer, unsigned int length);
typedef void (*rx_ind_t)(unsigned int dlci, void* buffer, unsigned int length);
typedef void	(*DlcLinkStatusIndCB)(unsigned int dlci,DlcLinkStatus status) ;			//	Link status (TRUE=Up, FALSE=Down).
typedef struct
{
   rx_ind_t RxIndCB;       //  Data indication (Pointer to the data & its length).
   DlcLinkStatusIndCB LinkStatusIndCB;          //  Link status (TRUE=Up, FALSE=Down).
   tx_done_t TxDoneCnfCB;            //  Tx complete (Pointer to buffer) - can free the buffer.

} MUX_CallBackFuncS ;
typedef struct muxparameter
{
	unsigned short int mode;
	unsigned short int subset;
	unsigned int port_speed;
	unsigned short int max_frame_size;
	unsigned short int ack_time;
	unsigned char max_retx_num;
	unsigned char response_time;
	unsigned char wakeup_response_time;
	unsigned char window_size;

}muxparameter;
/*error kind define end*/
#define parametererr    (1)
#define timeoutererr    (2)
#define dlcclosederr    (3)
#define muxclosederr    (4)
#define DlcTxQueueOverflow    (5)
#define DlcTxFlowControlOn    (6)
#define MuxTxFlowControlOn    (7)

#define Nomemory   (8)


/*error kind define end*/


extern void mux27010_init(void);
extern void mux27010_startup(muxparameter *);
extern int	 mux27010_dlc_open(int service_id,MUX_CallBackFuncS * Funcs);
extern void mux27010_dlc_close(int dlci);
extern int  mux27010_write(int dlci,char* packet, int length);
extern void mux27010_flow_control_on(void);
extern void mux27010_flow_control_off(void);
extern void mux27010_channel_block(int dlci);
extern void mux27010_channel_resume(int dlci);
extern int  mux27010_channel_get_status(int dlci);
extern int mux27010_dlc_upload_processing(int dlc);
extern void mux27010_read_ack(int dlci,char *buffer);
void mux27010_test(void);
void mux27010_startup(muxparameter * par);

#endif //#ifndef _MUX27010_H_

