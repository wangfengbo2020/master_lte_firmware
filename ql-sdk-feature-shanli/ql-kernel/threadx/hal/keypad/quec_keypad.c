/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
#include "quec_keypad.h"
#include "bsp_hisr.h"
#include "gbl_types.h"
#include "intc_list.h"
#include "intc_xirq.h"
#include "mfpr_api.h"
#include "quec_debug.h"
#include "platform.h"

#ifdef QUEC_KEYPAD_SUPPORT

#define QUEC_DBG_EN 0U //none-zero enable dbug info
#if 0
#define keypad_log(fmt,...)   quec_debug_print_uart(fmt,##__VA_ARGS__)
#else
#define keypad_log(fmt,...) 
#endif
#define CHIP_REG_OR(reg_addr, value)    (*(volatile unsigned int *)(reg_addr) |= (unsigned int)(value))
#define REG_PMU_BASE   			0xD4282800
#define REG_PMU_PMU_SD_ROT_WAKE_CLR (REG_PMU_BASE+0x07c)
#define BIT_KB_WK_CLR				1<<3
#define write32(addr, val)  (*(volatile unsigned int *)(addr) = (val))
#define read32(addr)        (*(volatile unsigned int *)(addr))
#define EV_DM_BASE                   (50)
#define EV_KEY_UP                                (EV_DM_BASE+42)
#define EV_KEY_DOWN                              (EV_DM_BASE+40)  
#define KEYPAD_MATRIX_LENGTH 8
#define  KP_WAIT    (0xFFFFF)
#define  FLG_TRUE   1U
#define  FLG_FALSE  0U
#define  WKP_SOURCE_KEYPAD 1<<21

#define INT_KEYPAD					(9)
#define INT_KEY_PRESS               (116) 

#define	APBC_BASE					0xD4015000
#define	APBC_KPC_CLK_RST			(APBC_BASE+0x0030)	/* 32 bit	APBClock Clock/Reset Control*/
#define	APBC_KPC_CLK_RST_RST		1<<2	/* Keypad Controller Reset Generation */
#define	APBC_KPC_CLK_RST_FNCLK		1<<1	/* Keypad Controller Functional Clock Enable/Disable */
#define	APBC_KPC_CLK_RST_APBCLK		1<<0	/* Keypad Controller APB Bus Clock Enable/Disable */


/*******************************************************************
                        global variable
******************************************************************/
static OS_HISR g_keypress_hisr_ref = NULL;

static OS_HISR	keypad_hisr_ref;

unsigned int pressed_key[KEYPAD_COL_NUM_MAX] = {0, 0, 0, 0, 0};

unsigned int pressed_key_bak[KEYPAD_COL_NUM_MAX] = {0, 0, 0, 0, 0};

volatile KDCReg *kpc_reg = (KDCReg *)KPC_BASE;

volatile unsigned int matrixKeypressReg[4] = {KPC_ASMKP0,KPC_ASMKP1,KPC_ASMKP2,KPC_ASMKP3};

ValEventFunc keypad_callback_func = NULL;

static KEYPAD_KP_MKIN_E k_row_g[KEYPAD_MATRIX_LENGTH];

static KEYPAD_KP_MKOUT_E k_col_g[KEYPAD_MATRIX_LENGTH];

static unsigned int ISR_CNT = 0;

int keypad_wakeup_fromD2 = FALSE;

extern void mmiD2CallbackRegister(UINT32 prepare_func, UINT32 recover_func);

void Keypad_clear_wakup_interrupt(void)
{
	CHIP_REG_OR(REG_PMU_PMU_SD_ROT_WAKE_CLR,BIT_KB_WK_CLR);
}

static void keypad_hisr(void)
{
	unsigned int key_pressed_num = 0,pressed_col=0, pressed_row=0,i = 0;
	unsigned int key_pressed0 = 0;
	unsigned int timeout_cnt = 0;
	unsigned char key_val = 0;
	UI_EVENT key_evt = {0};
	int temp, temp2;
    
    Keypad_clear_wakup_interrupt();

	memcpy(&pressed_key_bak,&pressed_key,sizeof(pressed_key));
	memset(&pressed_key,0,sizeof(pressed_key));

	/* single key; auto mode */
	/* wait for KPC_AS_SO off for valid data */
	while ( kpc_reg->kpc_as & KPC_AS_SO ) {
		if((timeout_cnt++)> 0xfffff) {
			keypad_log("timeout Error -- scan on with interrupt!\r\n");
			return;
		}
	}

	key_pressed0 = kpc_reg->kpc_as;
	key_pressed_num = (key_pressed0 & KPC_AS_MUKP_MSK) >> KPC_AS_MUKP_BASE;
	
	if ( key_pressed_num == 1 ) { /* only one key */
		pressed_col = (key_pressed0 & KPC_AS_CP_MSK) >> KPC_AS_CP_BASE;
		pressed_row = (key_pressed0 & KPC_AS_RP_MSK) >> KPC_AS_RP_BASE;
		if (pressed_col != 0xf && pressed_row != 0xf) {
				pressed_key[pressed_col] |= BIT(pressed_row);
		} else {
            keypad_log("debug info: single key press pressed_col pressed_row data invalid\n");
            return;
        }
	} else if(key_pressed_num > 1) { /* more than one key */
		for (i = 0; i < (KEYPAD_COL_ROW_NUM+1)/2; i++) {
			timeout_cnt = 0;
			/* if scan-on, the data is invalid */
			while ( read32(matrixKeypressReg[i]) & KPC_AS_SO) {
				if ((timeout_cnt++)> 0xfffff) {
					keypad_log("timeout Error -- scan on with interrupt!\r\n");
					return;
				}
			}
			key_pressed0 = read32(matrixKeypressReg[i]);
            /*每个寄存器记录两列按键信息*/
			pressed_key[2*i] = GET_COLUMN_IDENTIFIES(key_pressed0,2*i); //读取2i 列第n行被按下
			pressed_key[2*i+1] = GET_COLUMN_IDENTIFIES(key_pressed0,2*i+1);//读取2i+1 列第n行被按下
		}
	}
    
	for (pressed_col = 0; pressed_col < KEYPAD_COL_NUM; pressed_col++ ){
		if (!pressed_key_bak[pressed_col] && !pressed_key[pressed_col])
			continue;
		for (pressed_row = 0; pressed_row < KEYPAD_ROW_NUM; pressed_row++ ){
			//key_val = KeypadMatrix_BOARD_CRANE_EVB[pressed_row][pressed_col];
			/*按下一次中断,松开一次中断,相邻两次按键状态必定不一样*/
			if ((pressed_key_bak[pressed_col]&BIT(pressed_row)) && (pressed_key[pressed_col]&BIT(pressed_row)))
			{
				//if(KP_0 == key_val) send_satrt_alarm_on_HW_req();
				keypad_log("always pressed word: 0x%x,0x%x \r\n",pressed_key_bak[pressed_col],pressed_key[pressed_col]);
			} 
            else if ((pressed_key_bak[pressed_col]&BIT(pressed_row)) && !(pressed_key[pressed_col]&BIT(pressed_row))) 
            {
                keypad_log("\r\n*k:%d-%d*\r\n",pressed_col,pressed_row);
				key_evt.nEventId = EV_KEY_UP;
				key_evt.nParam3 = 0;

				temp2 = 0;
				for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
                    /*注：1606的keypad行列颠倒*/
					if(k_row_g[temp] == pressed_col) {
                     //keypad_log("\r\n*row:%d,%d*\r\n",k_row_g[temp],temp);
						break;
					}
					if(k_row_g[temp] != KP_MKI_NO_VALID) {
                        keypad_log("\r\n*row:k_row_g[%d]=%d*\r\n",temp,k_row_g[temp]);
						temp2++;
					}
				}
				key_evt.nParam1 = temp2; // row index
				temp2 = 0;
				for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
					if(k_col_g[temp] == pressed_row) {
                        //keypad_log("\r\n*col:%d,%d*\r\n",k_col_g[temp],temp);
						break;
					}
					if(k_col_g[temp] != KP_MKO_NO_VALID) {
                        keypad_log("\r\n*row:k_col_g[%d]=%d*\r\n",temp,k_col_g[temp]);
						temp2++;
					}
				}
				key_evt.nParam2 = temp2; // col index
				
                if (keypad_callback_func)
                    keypad_callback_func(key_evt);
                //else
				//dm_SendKeyMessage(&key_evt);
			//	send_satrt_alarm_on_HW_req();
			}
            else if (!(pressed_key_bak[pressed_col]&BIT(pressed_row)) && (pressed_key[pressed_col]&BIT(pressed_row)))
            {
//				keypad_log("\r\n*k:%c-%c*\r\n",key_val,'D');
				key_evt.nEventId = EV_KEY_DOWN;
				key_evt.nParam3 = 0;
                
				temp2 = 0;
				for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
					if(k_row_g[temp] == pressed_col) {
						break;
					}
					if(k_row_g[temp] != KP_MKI_NO_VALID) {
						temp2++;
					}
				}
				key_evt.nParam1 = temp2;
				temp2 = 0;
				for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
					if(k_col_g[temp] == pressed_row) {
						break;
					}
					if(k_col_g[temp] != KP_MKO_NO_VALID) {
						temp2++;
					}
				}
				key_evt.nParam2 = temp2;

                if (keypad_callback_func)
                    keypad_callback_func(key_evt);
                //else
				//dm_SendKeyMessage(&key_evt);
			}
		}
	}
}
/*keypad唤醒中断*/
static void keypress_wakeup_hisr(void)
{
	INTC_InterruptSources INT_NUM;
	unsigned int key_pressed0 = 0, key_pressed_num = 0;
	unsigned int pressed_col, pressed_row;
	unsigned int d2_kp_num,d2_mukp01, d2_mukp23;
	unsigned int cnt = 0;
	int temp, temp2;
	unsigned char flg_no_wkup = FLG_FALSE;
	UI_EVENT key_evt = {0};
	
	#if(QUEC_DBG_EN)
		keypad_log("DBG===keypress_hisr============\r\n");
		dump_reg();
	#endif

	memcpy(&pressed_key_bak,&pressed_key,sizeof(pressed_key));
	memset(&pressed_key,0,sizeof(pressed_key));
	
	#if(QUEC_DBG_EN)
		keypad_log("DBG==chip is CRANEM\r\n");
	#endif
	cnt = 0;
	while(kpc_reg->d2_kp_num & BIT_31)
	{
		if(cnt > KP_WAIT )
		{
			#if(QUEC_DBG_EN)
				keypad_log("DBG==kpress_isr timeout!\r\n");
			#endif
            
			return;
		}
		cnt++;
	}	
	
	d2_kp_num = kpc_reg->d2_kp_num;
	d2_mukp01 = kpc_reg->d2_mukp01;
	d2_mukp23 = kpc_reg->d2_mukp23;
	key_pressed_num = (d2_kp_num & MASK_(26, 5))>>26;
	if(key_pressed_num == 1)
	{
		pressed_row = (d2_kp_num & MASK_( 22, 4));
		pressed_col = (d2_kp_num & MASK_( 18, 4));
		//keypad_log("=msk %X=col %X=====msk %X=row %X==\r\n",MASK_( 22, 4),pressed_col, MASK_( 18, 4), pressed_row);
		pressed_row = (pressed_row >> 22) % KEYPAD_COL_NUM;
		pressed_col = (pressed_col >> 18) % KEYPAD_ROW_NUM;

		pressed_col = pressed_col & 0xF;
		pressed_row = pressed_row & 0xF;	
		pressed_key[pressed_col] |= BIT(pressed_row); // update pressed_key

		#if(QUEC_DBG_EN)
			keypad_log("====%X-%d-%d-%d==%X==\r\n", d2_kp_num, key_pressed_num, pressed_col, pressed_row, MASK_(22, 4));
		#endif
		#if(1)
			temp2 = 0;
			for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
				if(k_row_g[temp] == pressed_col) {
					break;
				}
				if(k_row_g[temp] != KP_MKI_NO_VALID) {
					temp2++;
				}
			}
			key_evt.nParam1 = temp2; // row index
			temp2 = 0;
			for(temp =0; temp < KEYPAD_MATRIX_LENGTH; temp++) {
				if(k_col_g[temp] == pressed_row) {
					break;
				}
				if(k_col_g[temp] != KP_MKO_NO_VALID) {
					temp2++;
				}
			}
			key_evt.nParam2 = temp2; // col index
		#endif

		#if(0) //
			keypad_log("DBG===key_press row %d , col %d\r\n", pressed_row, pressed_col);
		#endif

		key_evt.nParam3 = 0; 
		//key_evt.keyval =  KeypadMatrix_BOARD_CRANE_EVB[pressed_row][pressed_col];
		key_evt.nEventId = EV_KEY_DOWN;

		if(keypad_callback_func)
		{
			keypad_callback_func(key_evt);
		}
		
	}
	else
	{ // only one key operation can wake the system up
	
		flg_no_wkup = FLG_TRUE;
		
	}

	kpc_reg->d2_kp_num = kpc_reg->d2_kp_num|BIT_0;
	cnt = 0;
	while(!(kpc_reg->d2_kp_num & BIT_1))
	{
		if(cnt > KP_WAIT)
		{
			#if(QUEC_DBG_EN)
				keypad_log("DBG==keypad= clear D2 timeout\r\n");
			#endif
			break;
		}
		cnt++;
	}
	kpc_reg->d2_kp_num = kpc_reg->d2_kp_num & (~BIT_0);

	if(flg_no_wkup == FLG_FALSE)
	{ // 
		#if(QUEC_DBG_EN)
			keypad_log("DBG==kernel==set key_press isr for sleep!\r\n");
		#endif
		Keypad_clear_wakup_interrupt();
		//if not wakeup by keypad, donot need send a keyval.
		INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEY_PRESS);
		INTCDisable((INTC_InterruptSources)INT_NUM);
		INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEYPAD);
		INTCEnable((INTC_InterruptSources)INT_NUM);
	}
}

int uikeypad_d2_enter_cb()
{
	INTC_InterruptSources INT_NUM;
	Keypad_clear_wakup_interrupt();//clear peding wake up source.

	#if(QUEC_DBG_EN)
		keypad_log("DBG=====enter D2\r\n");
	#endif
	
	INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEYPAD);	
	INTCDisable((INTC_InterruptSources)INT_NUM);

	INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEY_PRESS);	
	INTCEnable((INTC_InterruptSources)INT_NUM);
	return TRUE;
}

int uikeypad_d2_exit_cb(unsigned char exitFromD2)
{
	unsigned int INT_NUM = 0;
	unsigned int wakeup_src  = 0;	
	keypad_wakeup_fromD2 = exitFromD2;

    wakeup_src = BU_REG_READ(0xD4050048) & BU_REG_READ(0xD405004C);
	#if(QUEC_DBG_EN)
		keypad_log("DBG===g_keep_cwucrs %X\r\n", g_keep_cwucrs);
	#endif
	if(!(wakeup_src & WKP_SOURCE_KEYPAD))
	{ // system is not wakeup By keypad
		#if(QUEC_DBG_EN)
			keypad_log("DBG===kernel===wakeup not by keypad!\r\n");
		#endif
		Keypad_clear_wakup_interrupt();
		//if not wakeup by keypad, donot need send a keyval.
		INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEY_PRESS);
		INTCDisable((INTC_InterruptSources)INT_NUM);
		INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEYPAD);
		INTCEnable((INTC_InterruptSources)INT_NUM);
	}

	return TRUE;
}

void Keypad_init_clk(void)
{
	unsigned int value;
	keypad_log("Keypad_init_clk\n");
	value = read32(APBC_KPC_CLK_RST);
	value |=(APBC_KPC_CLK_RST_RST |APBC_KPC_CLK_RST_FNCLK |APBC_KPC_CLK_RST_APBCLK);
	write32 (APBC_KPC_CLK_RST, value);

	value = read32(APBC_KPC_CLK_RST);
	value &= (~APBC_KPC_CLK_RST_RST);
	value |=(APBC_KPC_CLK_RST_FNCLK |APBC_KPC_CLK_RST_APBCLK);
	write32 (APBC_KPC_CLK_RST, value);
	keypad_log("Keypad_init_clk done\n");
}

void set_debounce(int msecond) /* in msecond for both direct/matrix key */
{
	kpc_reg->kpc_kdi = ((msecond<<8) | msecond);
}

void Keypad_enable(Keypad_Type key_type)
{
	unsigned int value ;
	switch(key_type){
		case MATRIX_KEY:
			value =  KPC_PC_ME | KPC_PC_MIE;
			break;
		case DIRECT_KEY:
			value = KPC_PC_DE | KPC_PC_DIE;
			break;
		case ROTARY_0:
			value = KPC_PC_REE0;
			break;
		case ROTARY_1:
			value = KPC_PC_REE1;
		default: break;
	}
	kpc_reg->kpc_pc |= value;

}

void Keypad_interrupt_enable(void)
{
	kpc_reg->kpc_pc |= (KPC_PC_MIE);
}


void Keypad_interrupt_disable(void)
{
	kpc_reg->kpc_pc &= ((~KPC_PC_MIE) & (~KPC_PC_DIE));
}

void Deassert_all(void)
{
	unsigned int value;

	value = (~KPC_PC_MS7) & (~KPC_PC_MS6) 	\
			& (~KPC_PC_MS5)	& (~KPC_PC_MS4) & (~KPC_PC_MS3) 	\
			& (~KPC_PC_MS2) & (~KPC_PC_MS1) & (~KPC_PC_MS0) ;

	kpc_reg->kpc_pc &= value;

}

void Assert_all(void)
{
	unsigned int value;
	value = KPC_PC_MS7 | KPC_PC_MS6 | KPC_PC_MS5	\
		| KPC_PC_MS4 | KPC_PC_MS3 | KPC_PC_MS2 | KPC_PC_MS1 | KPC_PC_MS0;

	kpc_reg->kpc_pc |= value;
}


int is_mk()
{
	if ( kpc_reg->kpc_pc & KPC_PC_IMKP )
		return 0;
	else
		return 1;
}

int is_auto_mode(void)
{
	if ( kpc_reg->kpc_pc & KPC_PC_ASACT)
		return 1;
	else
		return 0;
}

void ValKeypadMultikeyEn(BOOL En)
{
    if (En)
        kpc_reg->kpc_pc &= ~KPC_PC_IMKP;
    else
        kpc_reg->kpc_pc |= KPC_PC_IMKP;
}

void ValKeypadRegister(ValEventFunc EventFuncP)
{
    keypad_callback_func = EventFuncP;
}

void Keypad_ISR(INTC_InterruptInfo interruptInfo)
{
	if( !is_auto_mode()) //not auto_mode
		return;
    ISR_CNT++;
	keypad_log("*I\r\n");
	OS_Activate_HISR(&keypad_hisr_ref);
}

void keypad_wakeup_ISR(INTC_InterruptInfo interruptInfo)
{
    Keypad_clear_wakup_interrupt();	
	OS_Activate_HISR(&g_keypress_hisr_ref);
}

/*初始化key_pad控制器*/
void Keypad_cfg(int is_auto, int is_mk, int debounce, Keypad_Type key_type)
{
	unsigned int value;
	volatile int i;
	INTC_ReturnCode intcStatus;
	INTC_InterruptSources INT_NUM;

    /*初始化keypad时钟*/
	Keypad_init_clk();
	/* Clear the auto scan bit */
	/* set/reset auto-scan-on-activity bit according to is_auto */
    /*初始化8行8列*/
	value = KPC_PC_MKRN_MSK | KPC_PC_MKCN_MSK | KPC_PC_MS0 | KPC_PC_MS1 |   \
			KPC_PC_MS2 | KPC_PC_MS3 | KPC_PC_MS4 | KPC_PC_MS5 | KPC_PC_MS6 | \
			KPC_PC_MS7 | KPC_PC_DN_MSK;
    
	if ( is_auto )
		value |= KPC_PC_ASACT ; //自动扫描
	else
		value &= ~KPC_PC_ASACT;

	/* set/reset multi-key according to is_mk */
	if ( is_mk )
		value &= ~KPC_PC_IMKP;//使能多按键
	else
		value |= KPC_PC_IMKP;


	kpc_reg->kpc_pc =  value;

	set_debounce(debounce); //设置按键防抖


	/* Enable keypad and interrupt for both Matrix and DirectKey*/
    Keypad_enable(key_type);

	//register interrupt handler
	//for keypad wake up interrupt
	INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEY_PRESS);
	intcStatus = INTCConfigure(INT_NUM, INTC_IRQ, INTC_HIGH_LEVEL);
	ASSERT(intcStatus == INTC_RC_OK);
	intcStatus = INTCBind(INT_NUM,keypad_wakeup_ISR);
	ASSERT(intcStatus == INTC_RC_OK);
	
	//interrupt_handler_set(INT_KEYPAD,Keypad_ISR);
	INT_NUM = (INTC_InterruptSources)INTCGetIntVirtualNum(INT_KEYPAD);

	intcStatus = INTCConfigure(INT_NUM, INTC_IRQ, INTC_HIGH_LEVEL);
	ASSERT(intcStatus == INTC_RC_OK);
	intcStatus = INTCBind(INT_NUM,Keypad_ISR);
	ASSERT(intcStatus == INTC_RC_OK);
	
	//enable interrupt
	//int_enable(INT_KEYPAD);
	INTCEnable(INT_NUM);

	for(i=0; i<50;i++)
		;
	/* Asseset_debouncert all column for manu mode */

}

INT32 ValKeypadInit(BOOL MultiKey, unsigned char KeyHoldDuration, KEYPAD_KP_MKOUT_E row[KEYPAD_MATRIX_LENGTH],
	                   KEYPAD_KP_MKIN_E col[KEYPAD_MATRIX_LENGTH])
{
    /*唤醒状态下keypad中断*/
    OS_Create_HISR(&keypad_hisr_ref, "uiKpdIsr", keypad_hisr, 2);
    /*休眠状态下keypad中断*/
    OS_Create_HISR(&g_keypress_hisr_ref, "uiKpressIsr", keypress_wakeup_hisr, 2);
    /*注册两个函数用于进休眠是打开keypad唤醒中断,退出休眠关闭keypad唤醒中断*/
    mmiD2CallbackRegister((unsigned int)uikeypad_d2_enter_cb, (unsigned int)uikeypad_d2_exit_cb);
    /*将用户传入的行列信息传入*/
    memcpy(k_row_g, row, sizeof(k_row_g));
    memcpy(k_col_g, col, sizeof(k_col_g));

	/*初始化按键控制器*/
    Keypad_cfg(AUTO, MultiKey, KeyHoldDuration, MATRIX_KEY);
    return 0;
}

 void quec_KeypadPinmuxCfg(KEYPAD_KP_MKOUT_E row[KEYPAD_MATRIX_LENGTH],KEYPAD_KP_MKIN_E col[KEYPAD_MATRIX_LENGTH])
{
    unsigned int key_pad_pin_out[10]={0};
    unsigned int key_pad_pin_in[10]={0};
    int i,j;
    for(i=0,j=0;i<KEYPAD_MATRIX_LENGTH;i++)
    {
        switch(row[i])
        {
#if defined(__QUECTEL_PROJECT_EC600MCN_LC__) || defined (__QUECTEL_PROJECT_EC600MCN_CC__)|| defined (__QUECTEL_PROJECT_EC600MCN_GC__) \
	|| defined(__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_MC__)|| defined (__QUECTEL_PROJECT_EC600MCN_LF__)\
	|| defined (__QUECTEL_PROJECT_EC600MCN_LE__) || defined (__QUECTEL_PROJECT_EC600MCN_NC__)|| defined (__QUECTEL_PROJECT_EC600MEU_LA__)\
	|| defined (__QUECTEL_PROJECT_EC600MLA_LA__)
           case KP_MKO0 : 
                key_pad_pin_out[j++]=MFP_REG(GPIO_72) | MFP_AF5 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("out0 \r\n");
                break;

		   case KP_MKO3 : 
                key_pad_pin_out[j++]=MFP_REG(GPIO_07) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("out3 \r\n");
                break;
				
#elif defined(__QUECTEL_PROJECT_EC800MCN_LC__) || defined(__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_LE__) \
|| defined (__QUECTEL_PROJECT_EC800MCN_LF__)|| defined (__QUECTEL_PROJECT_EC800MCN_MC__)|| defined(__QUECTEL_PROJECT_EC800MCN_GA__) \
|| defined(__QUECTEL_PROJECT_EC800MCN_GC__) || defined(__QUECTEL_PROJECT_EC800MCN_GM__)|| defined (__QUECTEL_PROJECT_EG810MCN_GA__) \
|| defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__)||defined(__QUECTEL_PROJECT_EC800MCN_GD__) \
|| defined (__QUECTEL_PROJECT_EG810MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__)|| defined (__QUECTEL_PROJECT_EG810MEU_LA__)\
|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) || defined (__QUECTEL_PROJECT_EG810MEU_LC__)\
|| defined (__QUECTEL_PROJECT_EG810MLA_LC__)



	 	  case KP_MKO0 : 
               key_pad_pin_out[j++]=MFP_REG(GPIO_01) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
               keypad_log("out0 \r\n");
               break;
			   
		  case KP_MKO7 : 
			   key_pad_pin_out[j++]=MFP_REG(GPIO_15) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
			   keypad_log("out7 \r\n");
			   break;
#endif
		   case KP_MKO1 : 
				key_pad_pin_out[j++]=MFP_REG(GPIO_03) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
				keypad_log("out1 \r\n");
				break;
				
		   case KP_MKO2 : 
				key_pad_pin_out[j++]=MFP_REG(GPIO_05) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
				keypad_log("out2 \r\n");
				break;
				
		   case KP_MKO4 : 
				key_pad_pin_out[j++]=MFP_REG(GPIO_09) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
				keypad_log("out4 \r\n");
				break;
			
		   case KP_MKO5 : 
				key_pad_pin_out[j++]=MFP_REG(GPIO_11) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
				keypad_log("out5 \r\n");
				break;
           default:
                keypad_log("KP_OUT_NO_VALID \r\n");
                break;       
        }
    }
    key_pad_pin_out[j] = MFP_EOC; 
    mfp_config(key_pad_pin_out);
    for(i=0,j=0;i<KEYPAD_MATRIX_LENGTH;i++)
    {
        switch(col[i])
        {
#if defined(__QUECTEL_PROJECT_EC600MCN_LC__)|| defined (__QUECTEL_PROJECT_EC600MCN_CC__) || defined (__QUECTEL_PROJECT_EC600MCN_GC__)|| defined(__QUECTEL_PROJECT_EC600MCN_LA__) || defined (__QUECTEL_PROJECT_EC600MCN_MC__)|| defined (__QUECTEL_PROJECT_EC600MCN_LF__)|| defined (__QUECTEL_PROJECT_EC600MCN_LE__)\
 || defined (__QUECTEL_PROJECT_EC600MCN_NC__) || defined (__QUECTEL_PROJECT_EC600MEU_LA__) || defined (__QUECTEL_PROJECT_EC600MLA_LA__)
           case KP_MKI0 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_71) | MFP_AF5 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in0 \r\n");
                break;

           case KP_MKI3 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_06) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in3 \r\n");
                break;
				
#elif defined(__QUECTEL_PROJECT_EC800MCN_LC__)|| defined (__QUECTEL_PROJECT_EC800MCN_LF__)|| defined (__QUECTEL_PROJECT_EC800MCN_LE__) \
|| defined(__QUECTEL_PROJECT_EC800MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_MC__)|| defined(__QUECTEL_PROJECT_EC800MCN_GA__) \
|| defined(__QUECTEL_PROJECT_EC800MCN_GC__)|| defined(__QUECTEL_PROJECT_EC800MCN_GM__)|| defined (__QUECTEL_PROJECT_EG810MCN_GA__)\
|| defined (__QUECTEL_PROJECT_EC800MCN_CC__) || defined (__QUECTEL_PROJECT_EC800MCN_NC__)|| defined(__QUECTEL_PROJECT_EC800MCN_GD__) \
|| defined (__QUECTEL_PROJECT_EG810MCN_LA__) || defined (__QUECTEL_PROJECT_EC800MCN_GB__)|| defined (__QUECTEL_PROJECT_EG810MEU_LA__)\
|| defined (__QUECTEL_PROJECT_EG810MCN_GB__) || defined (__QUECTEL_PROJECT_EG810MCN_LC__) || defined (__QUECTEL_PROJECT_EG810MEU_LC__)\
|| defined (__QUECTEL_PROJECT_EG810MLA_LC__)



		   case KP_MKI0 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_00) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in0 \r\n");
                break;

		   case KP_MKI7 :
                key_pad_pin_in[j++]=MFP_REG(GPIO_14) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in7 \r\n");
                break;
#endif
		   case KP_MKI1 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_02) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in1 \r\n");
                break;
				
           case KP_MKI2 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_04) | MFP_AF1 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in2 \r\n");
                break;
				
		   case KP_MKI4 : 
                key_pad_pin_in[j++]=MFP_REG(GPIO_08) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in4 \r\n");
                break;
            
           case KP_MKI5 :
                key_pad_pin_in[j++]=MFP_REG(GPIO_10) | MFP_AF2 | MFP_DRIVE_MEDIUM | MFP_PULL_LOW | MFP_SLEEP_DIR | MFP_LPM_EDGE_NONE ;
                keypad_log("in5 \r\n");
                break;

           default:
                keypad_log("KP_IN_NO_VALID \r\n");
                break;       
        }
    }
    key_pad_pin_in[j] = MFP_EOC; 
    mfp_config(key_pad_pin_in);
}
#endif
