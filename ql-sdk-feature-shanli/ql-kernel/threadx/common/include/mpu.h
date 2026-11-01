#define SCTRL_I		0x1000 /* Instruction cache */
#define SCTRL_D		0x0004 /* data cache */


#define ACTLR_DBWR   (1 << 14)  /* disable write burst in the AXI master */
#define ACTLR_BP_0   (1 << 15)	/* BP this field controls the branch prediction policy */
#define ACTLR_BP_1   (1 << 16)
#define ACTLR_RSDIS  (1 << 17)  /* return stack disable */


#define mpu_cp15_read(primary_reg, secondary_reg, opcode, value) \
	  __asm{MRC p15, 0, value, primary_reg, secondary_reg, opcode }

#define mpu_cp15_write(primary_reg, secondary_reg, opcode, value) \
	  __asm{MCR p15, 0, value, primary_reg, secondary_reg, opcode }

#define mpu_isb() __asm{isb}
#define mpu_dsb() __asm{dsb}

//region size
typedef enum {
        REG_4KB		=0x0B,
        REG_8KB		=0x0C,
        REG_16KB	=0x0D,
        REG_32KB	=0x0E,
        REG_64KB	=0x0F,
        REG_128KB	=0x10,
        REG_256KB	=0x11,
        REG_512KB	=0x12,
        REG_1MB		=0x13,
        REG_2MB		=0x14,
        REG_4MB		=0x15,
        REG_8MB		=0x16,
        REG_16MB	=0x17,
        REG_32MB	=0x18,
        REG_64MB	=0x19,
        REG_128MB	=0x1A,
        REG_256MB	=0x1B,
        REG_512MB	=0x1C,
        REG_1GB		=0x1D,
        REG_2GB		=0x1E,
        REG_4GB		=0x1F
}region_size;

//ACCESS_PERMISSION
typedef enum {
	NO_ACCESS     =0x0,
	FULL_ACCESS   =0x3,
	READ_ONLY     =0x6
}access_permission;

#define BACKGROUND_REGION 0

//use Bit[0] & Bit[1] to detect whether a device property MPU config
#define Bit_B(access_ctrl)         ((access_ctrl>>0) & 0x1)
#define Bit_C(access_ctrl)         ((access_ctrl>>1) & 0x1)
#define is_device(access_ctrl)     (Bit_B(access_ctrl)!=Bit_C(access_ctrl))
#define region_size_convert(region_size)       ((0x1<<(((region_size & (~(0x1)))>>1)+1))-1)
#define cacheable_convert(access_ctrl)         ((access_ctrl&(0x1<<3 ))?"0":"1")
#define shared_convert(access_ctrl)            ((access_ctrl&(0x1<<2 ))?"1":"0")
#define execute_never_convert(access_ctrl)     ((access_ctrl&(0x1<<12))?"1":"0")
#define access_permission_convert(access_ctrl) ((access_ctrl>>8)&(0x7))
#define access_permission_to_string(access_ctrl) ((access_permission_convert(access_ctrl)==NO_ACCESS)?"NO_ACCESS": \
		(access_permission_convert(access_ctrl)==READ_ONLY?"READ_ONLY":"FULL_ACCESS"))

//typedef unsigned char bool;
#include "stdbool.h"

void mpu_config_region_set_mem(unsigned int region_num, unsigned int base_address, region_size region_size,
		access_permission ap,bool cacheable,bool shared,bool execute_never);
void mpu_config_region_set_dev(unsigned int region_num, unsigned int base_address, region_size region_size,
		bool shared);
void mpu_config_entry_action(void);
void mpu_config_exit_action(void);
void mpu_config_uart_dump(unsigned int region_cnt);
