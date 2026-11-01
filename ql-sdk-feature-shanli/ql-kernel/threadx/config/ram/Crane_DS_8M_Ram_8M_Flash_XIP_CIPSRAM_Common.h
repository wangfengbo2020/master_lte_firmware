#ifndef __CONFIG_H__
#define __CONFIG_H__


/*******************************************************************************************************************
|--------------|0x7E000000
|              |
|DSP_RO        |
|--------------|0x7E070000
|              |
|HEAP          |
|--------------|
|              |
|(APP_RW)      |
|--------------|0x7E4A0000
|              |
|KERNEL_RW     |
|--------------|0x7E680000
|              |
|KERNEL_RO     |
|--------------|0x7E700000
|              |
|NOCACHE       |
|--------------|0x7E800000

NOTES://2022/04/25
1、HEAP区域为Kernel和App共享，由malloc统一分配使用；
//The HEAP area is shared by the Kernel and App, and is allocated and used uniformly by malloc

2、APP_RW为客户APP的数据段，可由上表计算其起始位置;app_linkscript.ld文件中的__RAM_START_ADDR与这里起始值保持一致;
//APP_RW is the data segment of the client APP, and its starting position can be calculated from the above table; 
//__RAM_START_ADDR in the app_linkscript.ld file is consistent with the starting value here;

3、HAEP区和APP_RW区总的大小被限定(0x430000),客户可以通过DDR_HEAP_SIZE和APP_RW_DATA_SIZE动态调整,两者的大小。
调整后需要重新计算APP_RW区的起始地址
//The total size of the HAEP area and the APP_RW area is limited (0x430000). The customer can dynamically adjust the size of the two through DDR_HEAP_SIZE and APP_RW_DATA_SIZE. 
//After adjustment, the starting address of the APP_RW area needs to be recalculated
*******************************************************************************************************************/

#define QSPI_BASE_ADDR  (0x80022000)
#define DDR_RO_SIZE     (0x007DE000)
#define PSRAM_BASE_ADDR (0x7E000000)
#define PSRAM_SIZE      (0x00800000)
#define PSRAM_END_MARK  (PSRAM_BASE_ADDR + PSRAM_SIZE)

    //PSRAM_BLOCK_1
	//[REGN] DDR_DSP_RO
	//[DESC] DSP image load region
	//[SIZE] 448K
	#define MSA_BASE_ADDR   (PSRAM_BASE_ADDR)
	#define MSA_SIZE        (0x00070000)//DSP 448K

#ifdef QUECTEL_OPEN_CPU

    //[REGN] DDR_HEAP
    //[DESC] Os HEAP region,Kernel和App共享的Heap 区域，由malloc进行分配
    //[SIZE] 3.7M
	#define DDR_HEAP_BASE_ADDR (MSA_BASE_ADDR + MSA_SIZE)
	#define DDR_HEAP_SIZE	   (0x003B0000)

	//[REGN] APP_CODE_IN_PSRAM
    //[DESC] APP RW DATA ,客户APP侧的RW数据区，其中APP侧app_linkscript.ld的__RAM_START_ADDR值
    		 //应该与此起始地址相同
    //[SIZE] 800Kb
	#define APP_RW_DATA_BASE_ADDR  (DDR_HEAP_BASE_ADDR + DDR_HEAP_SIZE)//0x7E220000
	#define APP_RW_DATA_SIZE	   (0X00049000)

    //[REGN] DDR_RW_DATA
	//[DESC] RW data
	//[SIZE] 1920Kb
	#define DDR_RW_DATA_BASE_ADDR  (APP_RW_DATA_BASE_ADDR + APP_RW_DATA_SIZE)
	#define DDR_RW_DATA_SIZE	   (0x217000)

	//[REGN] PS_CODE_IN_PSRAM & DDR_RW_DATA
	//[DESC] effective essential code running on PSRAM & RW data
	//[SIZE] 512Kb
	#define PS_CODE_IN_PSRAM_BASE  (DDR_RW_DATA_BASE_ADDR + DDR_RW_DATA_SIZE)
	#define PS_CODE_IN_PSRAM_SIZE  (0x00080000)	
	
#else
    //[REGN] DDR_HEAP
    //[DESC] Os HEAP region
    //[SIZE] 4.5M
	#define DDR_HEAP_BASE_ADDR (MSA_BASE_ADDR + MSA_SIZE)
	#define DDR_HEAP_SIZE      (0x00470000 - 0x000E0000)

    //[REGN] DDR_RW_DATA
	//[DESC] RW data
	//[SIZE] 1.5M
	#define DDR_RW_DATA_BASE_ADDR  (DDR_HEAP_BASE_ADDR + DDR_HEAP_SIZE)
    #define DDR_RW_DATA_SIZE       (0x00180000 + 0x000E0000)

	//[REGN] PS_CODE_IN_PSRAM & DDR_RW_DATA
	//[DESC] effective essential code running on PSRAM & RW data
	//[SIZE] 640K
	#define PS_CODE_IN_PSRAM_BASE  (DDR_RW_DATA_BASE_ADDR + DDR_RW_DATA_SIZE)
    #define PS_CODE_IN_PSRAM_SIZE  (0x000A0000-8)
    #define APP_RW_DATA_BASE_ADDR  (PS_CODE_IN_PSRAM_BASE + PS_CODE_IN_PSRAM_SIZE)
    #define APP_RW_DATA_SIZE       8
#endif

//PSRAM_BLOCK_2
	//[REGN] NONCACHE_REGION
	//[DESC] ALL NONCACHE regions
	//[SIZE] 1M
	#define DDR_NONCACHE_AREA_TOTAL_SIZE     (0x00100000)
	#define DDR_NONCACHE_AREA_TOTAL_START    (PSRAM_BASE_ADDR + PSRAM_SIZE - DDR_NONCACHE_AREA_TOTAL_SIZE)
	#define DDR_NONCACHE_PS_UL_BASE_ADDR     (DDR_NONCACHE_AREA_TOTAL_START)
	#define DDR_NONCACHE_PS_UL_SIZE          (0x0003E800)
	#define DDR_NONCACHE_PS_DL_BASE_ADDR     (DDR_NONCACHE_PS_UL_BASE_ADDR + DDR_NONCACHE_PS_UL_SIZE)
	#define DDR_NONCACHE_PS_DL_SIZE          (0x00019000)
	#define PS_NONCACHE_DATA_BASE_ADDR       (DDR_NONCACHE_PS_DL_BASE_ADDR + DDR_NONCACHE_PS_DL_SIZE)
	#define PS_NONCACHE_DATA_SIZE            (0x00070000)
	#define DDR_NONCACHE_BASE_ADDR           (PS_NONCACHE_DATA_BASE_ADDR + PS_NONCACHE_DATA_SIZE)
	#define DDR_NONCACHE_SIZE                (0x00001000)
	#define D2_VECT_BASE_ADDR                (DDR_NONCACHE_BASE_ADDR + DDR_NONCACHE_SIZE)
	#define D2_VECT_SIZE                     (0x00000100)
	#define DDR_PRIVATE_RW_AREA_BASE_ADDR    (D2_VECT_BASE_ADDR + D2_VECT_SIZE)
	#define DDR_PRIVATE_RW_AREA_SIZE         (0x00001C00 - D2_VECT_SIZE)
	#define DDR_NONCACHE_PTABLE_BASE_ADDR    (DDR_PRIVATE_RW_AREA_BASE_ADDR + DDR_PRIVATE_RW_AREA_SIZE)
	#define DDR_NONCACHE_PTABLE_SIZE         (0x00001000)
	#define DDR_NONCACHE_PROP_BASE_ADDR      (DDR_NONCACHE_PTABLE_BASE_ADDR + DDR_NONCACHE_PTABLE_SIZE)
	#define DDR_NONCACHE_PROP_SIZE           (0x00001000)
	#define DDR_NONCACHE_USB_BASE_ADDR       (DDR_NONCACHE_PROP_BASE_ADDR + DDR_NONCACHE_PROP_SIZE)
	#define DDR_NONCACHE_USB_SIZE            (DDR_NONCACHE_AREA_TOTAL_SIZE - (DDR_NONCACHE_USB_BASE_ADDR - DDR_NONCACHE_AREA_TOTAL_START))


#define ARBEL_DDR_BASE_ADDR     QSPI_BASE_ADDR
#define DDR_RW_BASE_ADDR        PSRAM_BASE_ADDR
#define DDR_RO_INIT_CODE_SIZE   (0x00001200)
#define DTCM_BASE_ADDR          (0xB0020000)
#define DTCM_SIZE               (0x00010000)

#define SQU_USB_POOL_ADDR       (0xD1001000)
#define SQU_USB_POOL_SIZE       (0x00002000)
#ifdef CRANEL_8MRAM
#define SQU_USB_DQH_ADDR        (0xD1004800)
#else
#define SQU_USB_DQH_ADDR        (0xD100A000)
#endif
#define SQU_USB_DQH_SIZE        (0x00000800)
#ifdef CRANEL_8MRAM
#define SQU_LTEBMBLOCK_BUF_ADDR (0xD1007000)
#else
#define SQU_LTEBMBLOCK_BUF_ADDR (0xD100A800)
#endif
#define SQU_LTEBMBLOCK_BUF_SIZE (0x00001000)

#endif
