#include "mpu.h"
#include "utilities.h"
#include "UART.h"
#include "quec_cust_patch.h"

#pragma arm section code="mpu"
static void mpu_config_region_set(unsigned int region_num, unsigned int base_address, region_size region_size,
		unsigned int XN,access_permission AP,unsigned int TEX,unsigned int S,unsigned int C,unsigned int B)
{
	unsigned int cp15_control_reg;

	cp15_control_reg = region_num;
	mpu_cp15_write(c6, c2, 0, cp15_control_reg);    //region num
	mpu_isb();

	cp15_control_reg = base_address;
	mpu_cp15_write(c6, c1, 0, cp15_control_reg);    //base addr

#ifdef QUEC_PATCH_BUG_32240
    if(region_size == 0)
    {
        cp15_control_reg = 0;                       //region disable
    }
    else
    {
	    cp15_control_reg = (region_size << 1|0x1);
	}
#else
	cp15_control_reg = (region_size << 1|0x1);
#endif
	mpu_cp15_write(c6, c1, 2, cp15_control_reg);    //region_size & force enable

	//[12]    XN  : execute never
	//[10:8]  AP  : access permission
	//[5:3]   TEX : type extension defines
	//[2]     S   : share
	//[1]     C   : inner cache policy bit
	//[0]     B   : inner caceh policy bit
	cp15_control_reg = ((XN << 12)|(AP << 8)|(TEX << 3)|(S << 2)|(C << 1)|B);  //attri
	mpu_cp15_write(c6, c1, 4, cp15_control_reg);
	mpu_isb();
	mpu_dsb();
}

void mpu_config_region_set_mem(unsigned int region_num, unsigned int base_address, region_size region_size,
		access_permission ap,bool cacheable,bool shared,bool execute_never)
{
	mpu_config_region_set(region_num, base_address, region_size,
		    execute_never,ap,(cacheable?0:1),shared,(cacheable?1:0),(cacheable?1:0));
}

void mpu_config_region_set_dev(unsigned int region_num, unsigned int base_address, region_size region_size,
		bool shared)
{
	mpu_config_region_set(region_num, base_address, region_size,
		    1,FULL_ACCESS,0,0,(shared?0:1),(shared?1:0));
}

void mpu_config_entry_action(void){
	unsigned int cp15_control_reg;

	/*
	MRC   p15, 0, r0, c1, c0, 0               ; Read CP15 Control Register
	BIC   r0, r0, #0x05                       ; Disable data cache (C bit)
	BIC   r0, r0, #0x1000                     ; Disable instruction cache (I bit)
	DSB                                       ; Ensure all previous loads/stores have completed
	MCR   p15, 0, r0, c1, c0, 0               ; Write CP15 Control Register
	ISB                                       ; Ensure subsequent insts execute wrt new MPU settings
	*/

	mpu_cp15_read(c1, c0, 0, cp15_control_reg);
	cp15_control_reg &= ~(SCTRL_D|SCTRL_I);
	mpu_dsb();
	mpu_cp15_write(c1, c0, 0, cp15_control_reg);
	mpu_dsb();
	mpu_isb();

	/*
	; In the Cortex-R5, the Z-bit of the SCTLR does not control the program flow prediction.
	; Some control bits in the ACTLR control the program flow and prefetch features instead.
	; These are enabled by default, but are shown here for completeness.

	MRC   p15, 0, r0, c1, c0, 1               ; Read ACTLR
	ORR   r0, r0, #(0x1 << 17)                ; Enable RSDIS bit 17 to disable the return stack
	ORR   r0, r0, #(0x1 << 16)                ; Clear BP bit 15 and set BP bit 16:
	BIC   r0, r0, #(0x1 << 15)                ; Branch always not taken and history table updates disabled
	MCR   p15, 0, r0, c1, c0, 1               ; Write ACTLR
	DSB                                       ; Complete all outstanding explicit memory operations
	*/
	mpu_cp15_read(c1, c0, 1, cp15_control_reg);
	cp15_control_reg |= (ACTLR_RSDIS|ACTLR_BP_1);
	cp15_control_reg &= ~(ACTLR_BP_0);
	mpu_cp15_write(c1, c0, 1, cp15_control_reg);
	mpu_dsb();

	/*
	MOV     r0, #0
	MCR     p15, 0, r0, c7, c5, 0           ; Invalidate entire instruction cache
	MCR     p15, 0, r0, c15, c5, 0          ; Invalidate entire data cache
	*/
	cp15_control_reg = 0;
	mpu_cp15_write(c7, c5, 0, cp15_control_reg);
	mpu_cp15_write(c15, c5, 0, cp15_control_reg);

	//set default 4G background to FULL_ACCESS
	mpu_config_region_set_mem(BACKGROUND_REGION,             0x00000000,     REG_4GB,        FULL_ACCESS,            1,              0,      0);//4G_BG

	return;
}

void mpu_config_exit_action(void){
	unsigned int cp15_control_reg;

	/*
        MRC     p15, 0, r0, c1, c0, 1           ; Read ACTLR
        BIC     r0, r0, #(0x1 << 17)            ; Clear RSDIS bit 17 to enable return stack
        BIC     r0, r0, #(0x1 << 16)            ; Clear BP bit 15 and BP bit 16:
        BIC     r0, r0, #(0x1 << 15)            ; Normal operation, BP is taken from the global history table.
        MCR     p15, 0, r0, c1, c0, 1           ; Write ACTLR
	*/
	mpu_cp15_read(c1, c0, 1, cp15_control_reg);
	cp15_control_reg &= ~(ACTLR_BP_0|ACTLR_BP_1|ACTLR_RSDIS);
	mpu_cp15_write(c1, c0, 1, cp15_control_reg);
	mpu_dsb();

	/*
        MRC 	p15, 0, r0, c1, c0, 0		; read CP15 register 1
        ORR 	r0, r0, #(0x1 << 12)		; enable I Cache
        ORR 	r0, r0, #(0x1 << 2) 		; enable D Cache
        DSB
        MCR 	p15, 0, r0, c1, c0, 0		; write CP15 register 1
        ISB
        */
	mpu_cp15_read(c1, c0, 0, cp15_control_reg);
	cp15_control_reg |= (SCTRL_D|SCTRL_I);
	mpu_dsb();
	mpu_cp15_write(c1, c0, 0, cp15_control_reg);
	mpu_isb();

	//set default 4G background to NO_ACCESS
	mpu_config_region_set_mem(BACKGROUND_REGION,             0x00000000,     REG_4GB,        NO_ACCESS,              0,              1,      1);//OVERLAY_4G_BG

	return;
}
#pragma arm section code

void mpu_config_uart_dump(unsigned int region_cnt){
	unsigned int base_address,size,access_ctrl;
	unsigned int cnt = 0, region_size = 0;


	RTI_LOG("[MPU][%3s][%10s][%10s][%10s][%12s][%5s][%5s][%5s]\r\n","RGN","BASE","END","SIZE","PERMISSION","CACHE","SHARE","N_EXE");

	do{
		mpu_cp15_write(c6, c2, 0, cnt);         //region num
		mpu_isb();
		mpu_cp15_read(c6, c1, 0, base_address); //base
		mpu_cp15_read(c6, c1, 2, size);         //size
		mpu_cp15_read(c6, c1, 4, access_ctrl);  //access_ctrl
        region_size = region_size_convert(size);
		RTI_LOG("[MPU][%3d][0x%.08x][0x%.08x][0x%.08x][%12s][%5s][%5s][%5s]\r\n",
				cnt,
				base_address,
				base_address + region_size,
				region_size,
				access_permission_to_string(access_ctrl),
				(is_device(access_ctrl))?"0":cacheable_convert(access_ctrl),
				shared_convert(access_ctrl),
				execute_never_convert(access_ctrl));
        if((base_address % (region_size + 1)) != 0)
        {
            RTI_LOG("MPU%d, base address 0x%x, region size 0x%x", cnt, base_address, region_size+1);
            ASSERT(0);
        }
	}while(cnt++ < region_cnt);

	return;
}
