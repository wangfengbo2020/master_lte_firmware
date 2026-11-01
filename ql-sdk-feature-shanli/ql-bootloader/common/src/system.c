#include <stdio.h>
#include "system.h"
#include "common.h"
#include "utilities.h"
#include "bsp.h"

/* Base address should be aligned with the size,  the max size is 4GB */
static unsigned int convert_region_size(unsigned long long size, unsigned int base)
{
    unsigned val;

    if (size < 32 || (size & (size - 1))) {
        uart_printf("Size should be power of two between 32 Bytes and 4GB\n");
        goto error;
    }

    if (base & (size - 1)) {
        uart_printf("Base must be aligned to the size\n");
        goto error;
    }

    val = 0;
    while (size) {
        val++;
        size >>= 1;
    }
    val -= 2; /* 32 bytes-> 0x4, 4GB -> 0x1F */

    return val;
error:
    return 0;
}


#define Bit_B(access_ctrl)         ((access_ctrl>>0) & 0x1)
#define Bit_C(access_ctrl)         ((access_ctrl>>1) & 0x1)
#define is_device(access_ctrl)     (Bit_B(access_ctrl)!=Bit_C(access_ctrl))
#define region_size_convert(region_size)       ((0x1<<((region_size)+1))-1)
#define cacheable_convert(access_ctrl)         ((access_ctrl&(0x1<<3 ))?"0":"1")
#define shared_convert(access_ctrl)            ((access_ctrl&(0x1<<2 ))?"1":"0")
#define execute_never_convert(access_ctrl)     ((access_ctrl&(0x1<<12))?"1":"0")
#define access_permission_convert(access_ctrl) ((access_ctrl>>8)&(0x7))
#define access_permission_to_string(access_ctrl) ((access_permission_convert(access_ctrl)==NO_ACCESS)?"NO_ACCESS":(access_permission_convert(access_ctrl)==READ_ONLY?"READ_ONLY":"FULL_ACCESS"))

void mpu_value_check(void)
{
#ifdef FOTA_ASRDM
	unsigned int i;
	unsigned int val_base_addr,val_access_ctrl,val_reg_size;
	
	uart_printf("[MPU][%3s][%10s][%10s][%10s][%12s][%5s][%5s][%5s]\r\n","RGN","BASE","END","SIZE","PERMISSION","CACHE","SHARE","N_EXE");
	for(i=0;i<MAX_REGION_NUM;i++)
	{
		mpu_set_region_num(i);
		val_base_addr=mpu_get_region_base_addr();
		val_access_ctrl=mpu_get_region_access_ctrl();
		val_reg_size=mpu_get_region_size();

		uart_printf("[MPU][%3d][0x%.08x][0x%.08x][0x%.08x][%12s][%5s][%5s][%5s],access_ctr[%08x]\r\n",
				i,
				val_base_addr,
				val_base_addr + region_size_convert(val_reg_size),
				region_size_convert(val_reg_size),
				access_permission_to_string(val_access_ctrl),
				(is_device(val_access_ctrl))?"0":cacheable_convert(val_access_ctrl),
				shared_convert(val_access_ctrl),
				execute_never_convert(val_access_ctrl),
				val_access_ctrl);
	}
#endif
}

#define  acc_ctrl_convert(ap,cacheable,shared,execute_never)  (((execute_never)<<12)|(ap<<8)|((cacheable?0:1)<<3)|(shared<<2)|((cacheable?1:0)<<1)|(cacheable?1:0))


void mpu_config_region_set_mem(unsigned int region_num, unsigned int base_address, region_size region_size,                                                 
                access_permission ap,unsigned int cacheable,unsigned int  shared,unsigned int execute_never)
{

    if (region_num >= MAX_REGION_NUM) {
        uart_printf("Invalid region num %d\n", region_num);
        goto error;
    }

    mpu_set_region_num(region_num);
    mpu_set_region_base_addr(base_address);
    mpu_set_region_access_ctrl(acc_ctrl_convert(ap,cacheable,shared,execute_never));
    mpu_set_region_size(region_size);

    return ;
error:
    uart_printf("set_mpu_region failed\n");
    return ;
}

int mpu_set_by_region_size(unsigned int num, unsigned int base, region_size size, unsigned int acc_ctrl)
{
	//unsigned int region_size;

	if (num >= MAX_REGION_NUM) {
		uart_printf("Invalid region num %d\n", num);
		goto error;
	}

	//region_size = convert_region_size(size, base);
	//if (size == 0) {
	//	goto error;
	//}

	mpu_set_region_num(num);
	mpu_set_region_base_addr(base);
	mpu_set_region_access_ctrl(acc_ctrl);
	mpu_set_region_size(size);

	return 0;
error:
	uart_printf("mpu_set_region_size failed\n");
	return -1;
}


int mpu_set_region(unsigned int num, unsigned int base, unsigned int size, unsigned int acc_ctrl)
{
    unsigned int region_size;

    if (num >= MAX_REGION_NUM) {
        uart_printf("Invalid region num %d\n", num);
        goto error;
    }

    region_size = convert_region_size(size, base);
    if (region_size == 0) {
        goto error;
    }

    mpu_set_region_num(num);
    mpu_set_region_base_addr(base);
    mpu_set_region_access_ctrl(acc_ctrl);
    mpu_set_region_size(region_size);

    return 0;
error:
    uart_printf("set_mpu_region failed\n");
    return -1;
}

#define SIZEOF_CACHE_LINE	32
#define CACHE_LINE_MASK		(SIZEOF_CACHE_LINE -1)

void CacheInvalidateMemory(void *pMem, unsigned int size)
{
	unsigned int address =(unsigned int)pMem & ~CACHE_LINE_MASK;
	//unsigned int cpsr;
	unsigned int end_address = (unsigned int)pMem + size;
	unsigned int last_address_to_invalidate = end_address & ~CACHE_LINE_MASK;
	
	if(address != (unsigned int)pMem)
	{
		//cpsr = disableInterrupts();
		CPUCleanDCacheLine(address);
		CPUInvalidateDCacheLine(address);
		//restoreInterrupts(cpsr);
		address += SIZEOF_CACHE_LINE;
	}

	for(;address<last_address_to_invalidate ; address+=SIZEOF_CACHE_LINE)
		CPUInvalidateDCacheLine(address);

	if(last_address_to_invalidate != end_address)
	{
		//cpsr = disableInterrupts();
		CPUCleanDCacheLine(address);
		CPUInvalidateDCacheLine(address);
		//restoreInterrupts(cpsr);
	}
	return;

}

void CacheCleanMemory(void *pMem, unsigned int size)
{
	unsigned int address =(unsigned int)pMem & ~CACHE_LINE_MASK;
	unsigned int end_address;
	for(end_address= ((unsigned int)pMem+size);address<end_address ; address+=SIZEOF_CACHE_LINE)
		CPUCleanDCacheLine(address);
	
	return;
}



int reset_all_mpu_reg(void)
{
	int i=0;
	for(i=0;i<MAX_REGION_NUM;i++)
	{
		mpu_set_by_region_size(i, 0, 0, 0);
		mpu_enable_region(i, 1);
	}
	
	//mpu_value_check();
}

int reset_mpu_reg(int num)
{

	mpu_set_by_region_size(num, 0, 0, 0);
	mpu_enable_region(num, 1);
	//mpu_value_check();
}



int set_mpu_reg_background(int access )
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0x00000000;
    region_size      size = REG_4GB;

	if(access){
		//set default 4G background to FULL_ACCESS
		/* Grant read, write and excution privilege to the code area */
		acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)		/* read, write */
				   | MPU_REGION_ACCESS_CTRL_TEX(0x1);	/* non-cacheable */

	}else{
		//set default 4G background to NO_ACCESS
		acc_ctrl = 	MPU_REGION_ACCESS_CTRL_TEX(0x1)	/* non-cacheable */
					| MPU_REGION_ACCESS_CTRL_XN	 /* Execute Never */
					| MPU_REGION_ACCESS_CTRL_S;   /* Shared */
	}


    mpu_set_by_region_size(0, base, size, acc_ctrl);
    mpu_enable_region(0, 1);
    return 0;
}


int set_mpu_reg_itcm(void)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0x00000000;//ITCM
    size_t      size = 0x00010000;//64K

	//if(read_only){
	    /* Grant read, write and excution privilege to the code area */
	//    acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x6)       /* read only */
	//               | MPU_REGION_ACCESS_CTRL_TEX(0x1);   /* non-cacheable */
	//}else{
	    /* Grant read, write and excution privilege to the code area */
	    acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)       /* read and write */
	               | MPU_REGION_ACCESS_CTRL_TEX(0x1);   /* non-cacheable */

	//}

    mpu_set_region(1, base, size, acc_ctrl);
    mpu_enable_region(1, 1);
    return 0;
}

int set_mpu_reg_dtcm(void)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0xB0020000;//DTCM
    size_t      size = 0x00010000;//64K

    /* Grant read, write and excution privilege to the code area */
    acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)       /* read and write */
               | MPU_REGION_ACCESS_CTRL_TEX(0x1)	/* non-cacheable */
               | MPU_REGION_ACCESS_CTRL_XN;   		/* Execute Never */	



    mpu_set_region(2, base, size, acc_ctrl);
    mpu_enable_region(2, 1);
    return 0;
}

int set_mpu_reg_flash(size_t        size)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0x80000000;//FLASH
    //size_t      size = 0x01000000; //16MB

    /* Grant read, write and excution privilege to the code area */
    acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)        /* read and write */
               | MPU_REGION_ACCESS_CTRL_TEX(0x1);   /* non-cacheable */

#ifdef FOTA_ASRDM
	acc_ctrl = acc_ctrl | MPU_REGION_ACCESS_CTRL_XN;   		/* Execute Never */	
#endif	   
				
    mpu_set_region(3, base, size, acc_ctrl);
    mpu_enable_region(3, 1);
    return 0;
}


int set_mpu_reg_asic_reg(void)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0xC0000000;//ASIC REG
    size_t      size = 0x40000000;// 1GB
    acc_ctrl =MPU_REGION_ACCESS_CTRL_XN
            | MPU_REGION_ACCESS_CTRL_AP(0x3)       /* read, write */
            | MPU_REGION_ACCESS_CTRL_TEX(0x0)   /* non-cacheable */
            | MPU_REGION_ACCESS_CTRL_B;         /* bufferable */

    mpu_set_region(4, base, size, acc_ctrl);
    mpu_enable_region(4, 1);

    return 0;
}



int set_mpu_reg_psram(unsigned int enable_cache )
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0x7E000000;//PSRAM base address
    size_t      size = 0x01000000;//16M

	UINT8 fuse_psram=getPsramFuse();
	switch(fuse_psram)
	{
		case AP_8M:
		case WB_8M:
        case WB_250MHZ_8M:
		case WB_XCCELA_8M:
		case AP_250MHZ_8M:
			size = 0x00800000;//8M
			break;
		case WB_4M:
        case AP_4M:
		case WB_XCCELA_4M:
			size = 0x00400000;//4M
			break;
		default:
			break;
	}
	if(enable_cache){
		/* Grant read, write and excution privilege to the code area */
		acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)		/* read, write */
				   | MPU_REGION_ACCESS_CTRL_B		   /* bufferable */
				   | MPU_REGION_ACCESS_CTRL_C;		   /* cacheable */

	}else{
		/* Grant read, write and excution privilege to the code area */
		acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)		/* read, write */
				   | MPU_REGION_ACCESS_CTRL_TEX(0x1);	/* non-cacheable */
	}

    mpu_set_region(5, base, size, acc_ctrl);
    mpu_enable_region(5, 1);
    return 0;
}


int set_mpu_reg_squ(void)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0xD1000000;//SQU base address
    size_t      size = 0x00010000;//64k

	if(CHIP_IS_CRANEL||CHIP_IS_CRANELS || CHIP_IS_CRANELR){
		size = 0x00008000;//32k
	}

	/* Grant read, write and excution privilege to the code area */
	acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)		/* read, write */
			   | MPU_REGION_ACCESS_CTRL_TEX(0x1)	/* non-cacheable */
			   | MPU_REGION_ACCESS_CTRL_S			/* Shared */
			   | MPU_REGION_ACCESS_CTRL_XN;			/* Execute Never */ 


    mpu_set_region(6, base, size, acc_ctrl);
    mpu_enable_region(6, 1);
    return 0;
}

int set_mpu_reg_arom(void)
{
    unsigned int acc_ctrl;
    uintptr_t   base = 0xD1F00000;
    size_t      size = 0x00020000;//128k


	/* Grant read, write and excution privilege to the code area */
	acc_ctrl = MPU_REGION_ACCESS_CTRL_AP(0x3)		/* read, write */
			   | MPU_REGION_ACCESS_CTRL_TEX(0x1);	/* non-cacheable */


    mpu_set_region(7, base, size, acc_ctrl);
    mpu_enable_region(7, 1);
    return 0;
}



void enable_psram_cache(void)
{
	unsigned int val;
	val = sctlr_get();
	val |=	SCTLR_C;
	sctlr_set(val);
	val = sctlr_get();
	set_mpu_reg_psram(1);

	//mpu_value_check();
	
}

void disable_psram_cache(void)
{
	unsigned int val;
	unsigned int addr=0x7E000000;//PSRAM base address
    size_t      size = 0x01000000;//16M

	UINT8 fuse_psram=getPsramFuse();
	switch(fuse_psram)
	{
		case AP_8M:
		case WB_8M:
        case WB_250MHZ_8M:
		case WB_XCCELA_8M:
		case AP_250MHZ_8M:
			size = 0x00800000;//8M
			break;
		case WB_4M:
        case AP_4M:
		case WB_XCCELA_4M:
			size = 0x00400000;//8M
			break;
		default:
			break;
	}
	
	CacheCleanMemory(addr,size);
	val = sctlr_get();
	val &=	~SCTLR_C;
	sctlr_set(val);
	val = sctlr_get();
	set_mpu_reg_psram(0);

	//mpu_value_check();
}

