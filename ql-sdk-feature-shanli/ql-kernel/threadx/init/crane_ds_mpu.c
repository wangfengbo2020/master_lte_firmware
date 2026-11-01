#include "bsp.h"
#include "crane_ds_mpu.h"
#include "loadTable.h"
#include "UART.h"
#include "quec_cust_patch.h"

unsigned int region_cnt = 0;

BOOL xip_access_enable = TRUE;

static unsigned int crane_ds_mpu_16M_psram_8M_flash_xip(unsigned int cnt) {
#ifdef CRANE_MCU_DONGLE
    /*
	mpu_config_region_set_mem(region_num,	base_address,	REGION_SIZE,	ACCESS_PERMISSION,	cacheable,	shared,	execute_never)  */
	mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
	mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
	mpu_config_region_set_mem(cnt++,        0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support all 8M/16M/32M flash)
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_16MB,       FULL_ACCESS,            1,              0,      0);//[ 16M] PSRAM_BACKGROUND (support both 8M/16M PSRAM)

#if defined(DM_LTEONLY_16MPSRAM)
    mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_4MB,        READ_ONLY,              1,              0,      0);
	mpu_config_region_set_mem(cnt++,        0x7E400000,     REG_1MB,        READ_ONLY,              1,              0,      0);//[ 8M] DDR_PSRAM_CODE
#else
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_8MB,        READ_ONLY,              1,              0,      0);//[ 8M] DDR_PSRAM_CODE
#ifndef QUEC_PATCH_BUG_26578
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_2MB,        READ_ONLY,              0,              1,      1);//[ 2M] DDR_DSP_RO
    mpu_config_region_set_mem(cnt++,        0x7E200000,     REG_64KB,       READ_ONLY,              0,              1,      1);//[ 64K] DDR_DSP_RO
#endif
#endif
    mpu_config_region_set_mem(cnt++,        0x7EF00000,     REG_1MB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
	/*
	mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
	mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);												   //[  1G] ASIC_REG_ADDR (force align)
	mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)
#else
	/*
	mpu_config_region_set_mem(region_num,	base_address,	REGION_SIZE,	ACCESS_PERMISSION,	cacheable,	shared,	execute_never)  */
	mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
	mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
	mpu_config_region_set_mem(cnt++,        0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support both 16M/32M flash)
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_16MB,       FULL_ACCESS,            1,              0,      0);//[ 16M] PSRAM_BACKGROUND
#ifdef ENABLE_CAT1_LG
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_2MB,        READ_ONLY,              1,              0,      0);//[  3M] DDR_DSP_RO & PS_CRANE_MCU_DONGLE
	mpu_config_region_set_mem(cnt++,        0x7E200000,     REG_1MB,        READ_ONLY,              1,              0,      0);
#else
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_2MB,        READ_ONLY,              1,              0,      0);//[2.5M] DDR_DSP_RO & PS_CRANE_MCU_DONGLE
	mpu_config_region_set_mem(cnt++,        0x7E200000,     REG_1MB,        READ_ONLY,              1,              0,      0);
	mpu_config_region_set_mem(cnt++,        0x7E280000,     REG_512KB,      FULL_ACCESS,            1,              0,      0);
#endif

	mpu_config_region_set_mem(cnt++,        0x7EE80000,     REG_512KB,      FULL_ACCESS,            0,              1,      0);//[1.5M] DDR_NONCACHE
	mpu_config_region_set_mem(cnt++,        0x7EF00000,     REG_1MB,        FULL_ACCESS,            0,              1,      0);
	/*
	mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
	mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);												   //[  1G] ASIC_REG_ADDR (force align)
	mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)
#endif
	return (cnt-1);//return configed region count
}

static unsigned int crane_ds_mpu_16M_psram_16M_flash_psram(unsigned int cnt) {
	/*
	mpu_config_region_set_mem(region_num,	base_address,	REGION_SIZE,	ACCESS_PERMISSION,	cacheable,	shared,	execute_never)  */
	mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
	mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
	mpu_config_region_set_mem(cnt++,        0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support both 16M/32M flash)
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_16MB,       FULL_ACCESS,            1,              0,      0);//[ 16M] PSRAM_BACKGROUND (support both 8M/16M PSRAM)
#ifdef ENABLE_CAT1_LG
	//TODO:xiaoke for further refine
	/*
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_2MB,        READ_ONLY,            0,              0,      1);//[2.25M] DDR_DSP_RO
	mpu_config_region_set_mem(cnt++,        0x7E200000,     REG_256KB,      READ_ONLY,              0,              0,      1);//[+256K]
	*/
#else
	//TODO:xiaoke for further refine
	/*
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_1MB,        FULL_ACCESS,            0,              0,      1);//[1.5M] DDR_DSP_RO
	mpu_config_region_set_mem(cnt++,        0x7E100000,     REG_512KB,      READ_ONLY,              p,              1,      1);
	*/
#endif
	mpu_config_region_set_mem(cnt++,        0x7EE00000,     REG_2MB,        FULL_ACCESS,            0,              1,      1);//[1.5M] DDR_NONCACHE
	mpu_config_region_set_mem(cnt++,        0x7EE00000,     REG_512KB,      FULL_ACCESS,            1,              0,      0);

	/*
	mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
	mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);												   //[  1G] ASIC_REG_ADDR (force align)
	mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)

	return (cnt-1);//return configed region count
}

static unsigned int crane_ds_mpu_8M_psram_8M_flash_xip(unsigned int cnt) {
#ifdef CRANE_MCU_DONGLE
    /*
    mpu_config_region_set_mem(region_num,   base_address,   REGION_SIZE,    ACCESS_PERMISSION,  cacheable,  shared, execute_never)  */
    mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
    mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
    mpu_config_region_set_mem(cnt++,        0x80000000,     REG_8MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support all 8M/16M/32M flash)
    mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_8MB,        FULL_ACCESS,            1,              0,      0);//[ 8M] PSRAM_BACKGROUND (support both 8M/16M PSRAM)

	//DSP_RO 仅能只读权限
    #if defined(CRANEM_8MRAM)
    mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_4MB,        READ_ONLY,              1,              0,      0);
    mpu_config_region_set_mem(cnt++,        0x7E400000,     REG_256KB,      READ_ONLY,              1,              0,      0);
	#endif
	
#ifdef SINGLE_SIM
	//1609 8+8 的单卡基线走这里
    mpu_config_region_set_mem(cnt++,        0x7E760000,     REG_128KB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
    mpu_config_region_set_mem(cnt++,        0x7E780000,     REG_512KB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
#else
    mpu_config_region_set_mem(cnt++,        0x7E700000,     REG_1MB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
#endif
    /*
    mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
    mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);                                                //[  1G] ASIC_REG_ADDR (force align)
    mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)

#else
	/*
	mpu_config_region_set_mem(region_num,	base_address,	REGION_SIZE,	ACCESS_PERMISSION,	cacheable,	shared,	execute_never)  */
	mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
	mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
	mpu_config_region_set_mem(cnt++,        0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support all 8M/16M/32M flash)
	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_16MB,       FULL_ACCESS,            1,              0,      0);//[ 16M] PSRAM_BACKGROUND (support both 8M/16M PSRAM)

	mpu_config_region_set_mem(cnt++,        0x7E180000,     REG_512KB,      READ_ONLY,              1,              0,      0);//[+512K] DDR_PSRAM_CODE
	mpu_config_region_set_mem(cnt++,        0x7E200000,     REG_512KB,      READ_ONLY,              1,              0,      0);//[+512K]
	mpu_config_region_set_mem(cnt++,		0x7E680000, 	REG_512KB,		FULL_ACCESS,			0,				1,		0);//[+    512K] DDR_NONCACHE

	mpu_config_region_set_mem(cnt++,        0x7E700000,     REG_1MB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE

	mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_1MB,        READ_ONLY,              0,              1,      1);//[1.5M] DDR_DSP_RO
	mpu_config_region_set_mem(cnt++,        0x7E100000,     REG_512KB,      READ_ONLY,              0,              1,      1);

	/*
	mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
	mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);												   //[  1G] ASIC_REG_ADDR (force align)
	mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)
#endif
	return (cnt-1);//return configed region count
}


#ifdef CRANEL_4MRAM
static unsigned int crane_ds_mpu_4M_psram_4M_flash_xip(unsigned int cnt) {
#ifdef CRANE_MCU_DONGLE
    /*
    mpu_config_region_set_mem(region_num,   base_address,   REGION_SIZE,    ACCESS_PERMISSION,  cacheable,  shared, execute_never)  */
    mpu_config_region_set_mem(cnt++,        0x00000000,     REG_64KB,       READ_ONLY,              0,              0,      0);//[ 64K] ATCM
    mpu_config_region_set_mem(cnt++,        0xB0020000,     REG_64KB,       FULL_ACCESS,            0,              0,      1);//[ 64k] BTCM
    mpu_config_region_set_mem(cnt++,        0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);//[ 32M] DDR_QSPI_NOR_FLASH (support all 8M/16M/32M flash)
    mpu_config_region_set_mem(cnt++,        0x7E000000,     REG_4MB,        FULL_ACCESS,            1,              0,      0);//[ 4M] PSRAM_BACKGROUND (support both 8M/16M PSRAM)

#ifdef ASR_PLATFORM_CRANELR
	#ifdef SINGLE_SIM
		//1602 CRANELR 4M Flash+4M RAM的 单卡项目,1602 2M Flash项目也是此配置
	    mpu_config_region_set_mem(cnt++,        0x7E368000,     REG_32KB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
	    mpu_config_region_set_mem(cnt++,        0x7E370000,     REG_64KB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
		mpu_config_region_set_mem(cnt++,        0x7E380000,     REG_512KB,        FULL_ACCESS,            0,              1,      0);//[  1M] DDR_NONCACHE
	#endif
#else
//fOR 1606 Or 1609 
	#ifdef SINGLE_SIM
		#ifdef QUEC_4MFLASH_SUPPORT_IMS
		//for 1606 CRANEL 4+4 单卡支持IMS功能,但是不支持USB NET 功能
		mpu_config_region_set_mem(cnt++,		0x7E380000, 	REG_512KB,		  FULL_ACCESS,			  0,			  1,	  0);//[  1M] DDR_NONCACHE
		#else
		//1606 CRANEL 2M Flash+4M RAM的项目 和1606 4+4 的单卡基线也使用此配置
		mpu_config_region_set_mem(cnt++,		0x7E368000, 	REG_32KB,		 FULL_ACCESS,			 0, 			 1, 	 0);//[  1M] DDR_NONCACHE
		mpu_config_region_set_mem(cnt++,		0x7E370000, 	REG_64KB,		 FULL_ACCESS,			 0, 			 1, 	 0);//[  1M] DDR_NONCACHE
		mpu_config_region_set_mem(cnt++,		0x7E380000, 	REG_512KB,		  FULL_ACCESS,			  0,			  1,	  0);//[  1M] DDR_NONCACHE
		#endif
	#else
		//1606 CRANEL 4M Flash+4M RAM的项目
		mpu_config_region_set_mem(cnt++,		0x7E330000, 	REG_64KB,		 FULL_ACCESS,			 0, 			 1, 	 0);//[  1M] DDR_NONCACHE
		mpu_config_region_set_mem(cnt++,		0x7E340000, 	REG_256KB,		  FULL_ACCESS,			  0,			  1,	  0);//[  1M] DDR_NONCACHE
		mpu_config_region_set_mem(cnt++,		0x7E380000, 	REG_512KB,		  FULL_ACCESS,			  0,			  1,	  0);//[  1M] DDR_NONCACHE
	#endif
#endif

    /*
    mpu_config_region_set_dev(region_num,   base_address,   region_size,    shared); */
    mpu_config_region_set_dev(cnt++,        0xC0000000,     REG_1GB,        1);                                                //[  1G] ASIC_REG_ADDR (force align)
    mpu_config_region_set_mem(cnt++,        0xD1000000,     REG_64KB,       FULL_ACCESS,            0,              1,      1);//[ 64K] SQU (non align)

#endif
	return (cnt-1);//return configed region count
}
#endif

//xiaokeweng@20191008 flash cache_line auto config
//for partition table , the XIP code part should be cacheable
//but the NVM/factory/fota_pkg should always be noncache ,
//so implement solution to detect the cache_line address
//aligned inside [dsp_start_addr ~ reserved_end_addr] for C-code MPU audo reconfig

#define CACHELINE_ALIGN_REGION_SIZE(REG_N)  (2 << REG_N)

static unsigned int crane_ds_mpu_flash_noncache_line_auto_mpu(unsigned int cnt){

	//ptable fetch noncache_line area [dsp.bin.start ~ reserved.end]
	unsigned int dsp_start_addr	   = get_dsp_start_address_offset();
    #ifdef QUECTEL_OPEN_CPU
    /*以app结束地址为cache结束地址*/
    unsigned int reserved_end_addr = get_flash_cache_end_address_offset();
    #else
	unsigned int reserved_end_addr = get_reserved_end_address_offset();
    #endif
    
	unsigned int cache_line_max = reserved_end_addr;
	unsigned int cache_line_min = dsp_start_addr;
	unsigned int cache_line = 0;

	unsigned int tmp_addr = cache_line_max;
	unsigned int tmp_align= REG_16MB;
	unsigned int min_align= REG_1MB;
	unsigned int mpu_num= 0;

	if(is_partition_internal_flash("nvm")){
		mpu_config_region_set_mem(++cnt,        0x80000000,     REG_32MB,       FULL_ACCESS,            1,              0,      0);
	}else{
	uart_printf("[MPU] cache_line_max = [0x%0.8x], cache_line_min = [0x%0.8x]\r\n",cache_line_max,cache_line_min);

#if (defined(CRANEL_4MRAM) || defined(CRANEL_8MRAM))
	min_align = REG_4KB;
#endif
#ifdef QUECTEL_OPEN_CPU
	while(!(cache_line > cache_line_max) && (tmp_align >= min_align)) {   // open 配置到app_end前
#else
	while(!(cache_line >= cache_line_min && cache_line <= cache_line_max) && (tmp_align >= min_align)) {
#endif
		uart_printf("[MPU] tmp_addr = [0x%0.8x],CACHELINE_ALIGN_REGION_SIZE(tmp_align) = [0x%0.8x] , add/align=[%d]\r\n"
				,tmp_addr
				,CACHELINE_ALIGN_REGION_SIZE(tmp_align)
				,tmp_addr/CACHELINE_ALIGN_REGION_SIZE(tmp_align));

		if(tmp_addr/CACHELINE_ALIGN_REGION_SIZE(tmp_align) == 1){

			//update tmp_addr
			tmp_addr   -= CACHELINE_ALIGN_REGION_SIZE(tmp_align);

			//reconfig mpu
		    //mpu_config_region_set_mem(region_num,	base_address,			REGION_SIZE,	ACCESS_PERMISSION,	cacheable,	shared,	execute_never)
			mpu_config_region_set_mem(++cnt,        0x80000000+cache_line,	(region_size)tmp_align,       FULL_ACCESS,            1,              0,      0);//RO cacheable code onside flash

			//update cache_line
			cache_line += CACHELINE_ALIGN_REGION_SIZE(tmp_align);

			uart_printf("[MPU] cnt=[%0.2d],tmp_align=[0x%0.2x],CACHELINE_ALIGN_REGION_SIZE(tmp_align) = [0x%0.8x],cache_line = [0x%0.8x]\r\n"
					,cnt
					,tmp_align
					,CACHELINE_ALIGN_REGION_SIZE(tmp_align)
					,cache_line);
		}
		
		if(cnt>=15){
			//mpu region cnt at[0-14],cnt 15 should be used by ASR,if cnt exceed 14 will happen assert!
			RTI_LOG("MPU[%d] num error!", cnt);
#ifdef QUECTEL_OPEN_CPU
			break;    //不超过15条   第15条后面会重新配置
#else
			ASSERT(0);
#endif
		}
		
		//reset unused mpu region
		mpu_num = cnt;
		while(mpu_num<15){
			mpu_config_region_set_mem(++mpu_num,		0x00000000, 	0x00,		NO_ACCESS,			  1,			  0,	  0);
		}

		//update tmp_align
		tmp_align -= 0x01;
		}
	}

	return (cnt);
}

void crane_ds_mpu(void) {
	unsigned int cnt ;
	//uart_printf("[MPU] function:%s,line:%d\r\n", __func__,__LINE__);

    CPUartLogPrintf("Crane mpu configure");

	//step1:entry action, disable I/D cache,set 4G FULL_ACCESS background on region BACKGROUND_REGION
	mpu_config_entry_action();

	//step2:config and enable project mpu , start from (BACKGROUND_REGION+1)
	cnt = (BACKGROUND_REGION + 1);
#ifdef RUN_XIP_MODE
    #if defined(CRANEM_8MRAM) || defined(_8MNORFLASH) || defined(LTEONLY_8M8M)//8M_FLASH
		#if defined(CRANELS_16M16M)
	        cnt = crane_ds_mpu_16M_psram_16M_flash_xip(cnt);
		#else
			//1606 系列的8M PSRAM项目
		    cnt = crane_ds_mpu_8M_psram_8M_flash_xip(cnt);
		#endif
	#elif defined(CRANEL_4MRAM)
		//1606和1602 系列的 4M PSRAM的项目均走这里，包括2M FLASH和 4M FLASH
		cnt = crane_ds_mpu_4M_psram_4M_flash_xip(cnt);
	#else
		cnt = crane_ds_mpu_16M_psram_8M_flash_xip(cnt);
	#endif
#else
	cnt = crane_ds_mpu_16M_psram_16M_flash_psram(cnt);
#endif
	cnt = crane_ds_mpu_flash_noncache_line_auto_mpu(cnt);

	//step3:exit action, enable I/D cache,enable 4G NO_ACCESS background on region BACKGROUND_REGION
	mpu_config_exit_action();

    region_cnt = cnt;

    crane_ds_mpu_xip_enable(TRUE);
	//step4:uart dump configed mpu region
	mpu_config_uart_dump(15);

	//uart_printf("[MPU] function:%s,line:%d\r\n", __func__,__LINE__);

	return;
}

void crane_ds_mpu_xip_enable(bool enable)
{
    if(enable)
    {
        mpu_config_region_set_mem(15,   0x80000000,     0x00,       NO_ACCESS,            1,              0,      TRUE);
    }
    else
    {
        mpu_config_region_set_mem(15,   0x80000000,     REG_32MB,   NO_ACCESS,            1,              0,      TRUE);
    }

    if(!SysIsAssert())
    {
        xip_access_enable = enable;
    }
}
void crane_ds_mpu_xip_cache_enable(void)
{
    mpu_config_region_set_mem(15,   0x80000000,     0x00,       FULL_ACCESS,            0,              0,      0);
}

void crane_ds_mpu_xip_cache_disable(void)
{   
    mpu_config_region_set_mem(15,   0x80000000,     REG_32MB,       FULL_ACCESS,            0,              0,      0);

}
