
//#include "Typedef.h"
//#include "Errors.h"
//#include "bsp.h"
//#include "PlatformConfig.h"
//#include "osa.h"

#include <string.h>
//#include "UART.h"
#include "qspi_host.h"
#include "qspi_nor.h"
#include "qspi_dma.h"
//#include "crane_ds_mpu.h"
//#include "loadTable.h"
#include "qspi_nor_bp.h"

#ifdef SUPPORT_FBP

#define FBP_THIN

#ifdef SW_HANDLE_XIP
extern int spi_nor_wait(struct spi_flash_chip *chip, uint8_t *s, int pe, unsigned int *p_cpsr);
#else
extern int spi_nor_wait(struct spi_flash_chip *chip, uint8_t *s);
#endif

#if 0
extern BOOL IsMiniSystem(void);
extern UINT32 get_reserved_start_address(void);
extern UINT32 get_reserved_end_address(void);
extern UINT32 get_bootloader_end_address(void);
#endif

ProtectedAreaSizeType flash_protect_area_type = PORTION_NONE;
#define ALL_BP_BITS(x)	((x >> 2) & 0x1F)
#define ALL_BP_BITS_CLEAR(x) ( x & 0x83) // & 10000011
#define ALL_BP_BITS_GET(x) (x & 0x7C) // &01111100

#ifndef CRANEL_CHIP
ProtectAreaInfo ProtectAreaInfo_16M[PORTITION_MAX_TYPE] = 
{
	{PORTION_NONE, 				   0x0,      0x0},
	{PORTION_UPPER_1_64, 	       0xFC0000, 0xFFFFFF},
	{PORTION_UPPER_1_32, 		   0xF80000, 0xFFFFFF},
	{PORTION_UPPER_1_16, 		   0xF00000, 0xFFFFFF},
	{PORTION_UPPER_1_8,  		   0xE00000, 0xFFFFFF},
	{PORTION_UPPER_1_4,  		   0xC00000, 0xFFFFFF},
	{PORTION_UPPER_1_2,  		   0x800000, 0xFFFFFF},
	{PORTION_LOWER_1_64, 		   0x000000, 0x03FFFF},
	{PORTION_LOWER_1_32, 		   0x000000, 0x07FFFF},
	{PORTION_LOWER_1_16, 		   0x000000, 0x0FFFFF},
	{PORTION_LOWER_1_8,  		   0x000000, 0x1FFFFF},
	{PORTION_LOWER_1_4,  	   	   0x000000, 0x3FFFFF},
	{PORTION_LOWER_1_2,            0x000000, 0x7FFFFF},
	{PORTION_TOP_4K,               0xFFF000, 0xFFFFFF},
	{PORTION_TOP_8K,               0xFFE000, 0xFFFFFF},
	{PORTION_TOP_16K,    		   0xFFC000, 0xFFFFFF},
	{PORTION_TOP_32K,   		   0xFF8000, 0xFFFFFF},
	{PORTION_BOTTOM_4K,  		   0x000000, 0x000FFF},
	{PORTION_BOTTOM_8K,  		   0x000000, 0x001FFF},
	{PORTION_BOTTOM_16K, 		   0x000000, 0x003FFF},
	{PORTION_BOTTOM_32K, 		   0x000000, 0x007FFF},
	{PORTION_LOWER_63_64, 		   0x000000, 0xFBFFFF},
	{PORTION_LOWER_31_32, 		   0x000000, 0xF7FFFF},
	{PORTION_LOWER_15_16, 		   0x000000, 0xEFFFFF},
	{PORTION_LOWER_7_8, 		   0x000000, 0xDFFFFF},
	{PORTION_LOWER_3_4, 		   0x000000, 0xBFFFFF},
	{PORTION_UPPER_63_64, 	       0x040000, 0xFFFFFF},
	{PORTION_UPPER_31_32, 	       0x080000, 0xFFFFFF},
	{PORTION_UPPER_15_16, 	       0x100000, 0xFFFFFF},
	{PORTION_UPPER_7_8, 	       0x200000, 0xFFFFFF},
	{PORTION_UPPER_3_4, 	       0x400000, 0xFFFFFF},
	{PORTION_UNPROTECT_TOP_4K, 	   0x000000, 0xFFEFFF},
	{PORTION_UNPROTECT_TOP_8K, 	   0x000000, 0xFFDFFF},
	{PORTION_UNPROTECT_TOP_16K,    0x000000, 0xFFBFFF},
	{PORTION_UNPROTECT_TOP_32K,    0x000000, 0xFF7FFF},
	{PORTION_UNPROTECT_BOTTOM_4K,  0x001000, 0xFFFFFF},
	{PORTION_UNPROTECT_BOTTOM_8K,  0x002000, 0xFFFFFF},
	{PORTION_UNPROTECT_BOTTOM_16K, 0x004000, 0xFFFFFF},
	{PORTION_UNPROTECT_BOTTOM_32K, 0x008000, 0xFFFFFF},
	{PORTION_ALL, 				   0x000000, 0xFFFFFF},
};
#endif

ProtectAreaInfo ProtectAreaInfo_8M[] = 
{
	{PORTION_NONE, 				   0x0,      0x0},
#ifndef FBP_THIN
	{PORTION_UPPER_1_64, 	       0x7E0000, 0x7FFFFF},
	{PORTION_UPPER_1_32, 		   0x7C0000, 0x7FFFFF},
	{PORTION_UPPER_1_16, 		   0x780000, 0x7FFFFF},
	{PORTION_UPPER_1_8,  		   0x700000, 0x7FFFFF},
	{PORTION_UPPER_1_4,  		   0x600000, 0x7FFFFF},
	{PORTION_UPPER_1_2,  		   0x400000, 0x7FFFFF},
#endif	
	{PORTION_LOWER_1_64, 		   0x000000, 0x01FFFF},
	{PORTION_LOWER_1_32, 		   0x000000, 0x03FFFF},
	{PORTION_LOWER_1_16, 		   0x000000, 0x07FFFF},
	{PORTION_LOWER_1_8,  		   0x000000, 0x0FFFFF},
	{PORTION_LOWER_1_4,  	   	   0x000000, 0x1FFFFF},
	{PORTION_LOWER_1_2,            0x000000, 0x3FFFFF},
#ifndef FBP_THIN	
	{PORTION_TOP_4K,               0x7FF000, 0x7FFFFF},
	{PORTION_TOP_8K,               0x7FE000, 0x7FFFFF},
	{PORTION_TOP_16K,    		   0x7FC000, 0x7FFFFF},
	{PORTION_TOP_32K,   		   0x7F8000, 0x7FFFFF},
#endif	
	{PORTION_BOTTOM_4K,  		   0x000000, 0x000FFF},
	{PORTION_BOTTOM_8K,  		   0x000000, 0x001FFF},
	{PORTION_BOTTOM_16K, 		   0x000000, 0x003FFF},
	{PORTION_BOTTOM_32K, 		   0x000000, 0x007FFF},
	{PORTION_LOWER_63_64, 		   0x000000, 0x7DFFFF},
	{PORTION_LOWER_31_32, 		   0x000000, 0x7BFFFF},
	{PORTION_LOWER_15_16, 		   0x000000, 0x77FFFF},
	{PORTION_LOWER_7_8, 		   0x000000, 0x6FFFFF},
	{PORTION_LOWER_3_4, 		   0x000000, 0x5FFFFF},
#ifndef FBP_THIN	
	{PORTION_UPPER_63_64, 	       0x020000, 0x7FFFFF},
	{PORTION_UPPER_31_32, 	       0x040000, 0x7FFFFF},
	{PORTION_UPPER_15_16, 	       0x080000, 0x7FFFFF},
	{PORTION_UPPER_7_8, 	       0x100000, 0x7FFFFF},
	{PORTION_UPPER_3_4, 	       0x200000, 0x7FFFFF},
	{PORTION_UNPROTECT_TOP_4K, 	   0x000000, 0x7FEFFF},
	{PORTION_UNPROTECT_TOP_8K, 	   0x000000, 0x7FDFFF},
	{PORTION_UNPROTECT_TOP_16K,    0x000000, 0x7FBFFF},
	{PORTION_UNPROTECT_TOP_32K,    0x000000, 0x7F7FFF},
	{PORTION_UNPROTECT_BOTTOM_4K,  0x001000, 0x7FFFFF},
	{PORTION_UNPROTECT_BOTTOM_8K,  0x002000, 0x7FFFFF},
	{PORTION_UNPROTECT_BOTTOM_16K, 0x004000, 0x7FFFFF},
	{PORTION_UNPROTECT_BOTTOM_32K, 0x008000, 0x7FFFFF},
#endif	
	{PORTION_ALL, 				   0x000000, 0x7FFFFF},
};

ProtectAreaInfo ProtectAreaInfo_4M[] = 
{
	{PORTION_NONE, 				   0x0,      0x0},
#ifndef FBP_THIN	
	{PORTION_UPPER_1_64, 	       0x3F0000, 0x3FFFFF},
	{PORTION_UPPER_1_32, 		   0x3E0000, 0x3FFFFF},
	{PORTION_UPPER_1_16, 		   0x3C0000, 0x3FFFFF},
	{PORTION_UPPER_1_8,  		   0x380000, 0x3FFFFF},
	{PORTION_UPPER_1_4,  		   0x300000, 0x3FFFFF},
	{PORTION_UPPER_1_2,  		   0x200000, 0x3FFFFF},
#endif	
	{PORTION_LOWER_1_64, 		   0x000000, 0x00FFFF},
	{PORTION_LOWER_1_32, 		   0x000000, 0x01FFFF},
	{PORTION_LOWER_1_16, 		   0x000000, 0x03FFFF},
	{PORTION_LOWER_1_8,  		   0x000000, 0x07FFFF},
	{PORTION_LOWER_1_4,  	   	   0x000000, 0x0FFFFF},
	{PORTION_LOWER_1_2,            0x000000, 0x1FFFFF},
#ifndef FBP_THIN	
	{PORTION_TOP_4K,               0x3FF000, 0x3FFFFF},
	{PORTION_TOP_8K,               0x3FE000, 0x3FFFFF},
	{PORTION_TOP_16K,    		   0x3FC000, 0x3FFFFF},
	{PORTION_TOP_32K,   		   0x3F8000, 0x3FFFFF},
#endif	
	{PORTION_BOTTOM_4K,  		   0x000000, 0x000FFF},
	{PORTION_BOTTOM_8K,  		   0x000000, 0x001FFF},
	{PORTION_BOTTOM_16K, 		   0x000000, 0x003FFF},
	{PORTION_BOTTOM_32K, 		   0x000000, 0x007FFF},	
	{PORTION_LOWER_63_64, 		   0x000000, 0x3EFFFF},
	{PORTION_LOWER_31_32, 		   0x000000, 0x3DFFFF},
	{PORTION_LOWER_15_16, 		   0x000000, 0x3BFFFF},
	{PORTION_LOWER_7_8, 		   0x000000, 0x37FFFF},
	{PORTION_LOWER_3_4, 		   0x000000, 0x2FFFFF},
#ifndef FBP_THIN	
	{PORTION_UPPER_63_64, 	       0x010000, 0x3FFFFF},
	{PORTION_UPPER_31_32, 	       0x020000, 0x3FFFFF},
	{PORTION_UPPER_15_16, 	       0x040000, 0x3FFFFF},
	{PORTION_UPPER_7_8, 	       0x080000, 0x3FFFFF},
	{PORTION_UPPER_3_4, 	       0x100000, 0x3FFFFF},
	{PORTION_UNPROTECT_TOP_4K, 	   0x000000, 0x3FEFFF},
	{PORTION_UNPROTECT_TOP_8K, 	   0x000000, 0x3FDFFF},
	{PORTION_UNPROTECT_TOP_16K,    0x000000, 0x3FBFFF},
	{PORTION_UNPROTECT_TOP_32K,    0x000000, 0x3F7FFF},
	{PORTION_UNPROTECT_BOTTOM_4K,  0x001000, 0x3FFFFF},
	{PORTION_UNPROTECT_BOTTOM_8K,  0x002000, 0x3FFFFF},
	{PORTION_UNPROTECT_BOTTOM_16K, 0x004000, 0x3FFFFF},
	{PORTION_UNPROTECT_BOTTOM_32K, 0x008000, 0x3FFFFF},
#endif	
	{PORTION_ALL, 				   0x000000, 0x3FFFFF},
};

ProtectAreaInfo ProtectAreaInfo_2M[] = 
{
	{PORTION_NONE, 				   0x0,      0x0},
#ifndef FBP_THIN	
	{PORTION_UPPER_1_64, 	       0xFFFFFFFF, 0xFFFFFFFF}, //this is useless type in 2M flash
	{PORTION_UPPER_1_32, 		   0x1F0000, 0x1FFFFF},
	{PORTION_UPPER_1_16, 		   0x1E0000, 0x1FFFFF},
	{PORTION_UPPER_1_8,  		   0x1C0000, 0x1FFFFF},
	{PORTION_UPPER_1_4,  		   0x180000, 0x1FFFFF},
	{PORTION_UPPER_1_2,  		   0x100000, 0x1FFFFF},
	{PORTION_LOWER_1_64, 		   0xFFFFFFFF, 0xFFFFFFFF}, //this is useless type in 2M flash
#endif	
	{PORTION_LOWER_1_32, 		   0x000000, 0x00FFFF},
	{PORTION_LOWER_1_16, 		   0x000000, 0x01FFFF},
	{PORTION_LOWER_1_8,  		   0x000000, 0x03FFFF},
	{PORTION_LOWER_1_4,  	   	   0x000000, 0x07FFFF},
	{PORTION_LOWER_1_2,            0x000000, 0x0FFFFF},
#ifndef FBP_THIN	
	{PORTION_TOP_4K,               0x1FF000, 0x1FFFFF},
	{PORTION_TOP_8K,               0x1FE000, 0x1FFFFF},
	{PORTION_TOP_16K,    		   0x1FC000, 0x1FFFFF},
	{PORTION_TOP_32K,   		   0x1F8000, 0x1FFFFF},
#endif	
	{PORTION_BOTTOM_4K,  		   0x000000, 0x000FFF},
	{PORTION_BOTTOM_8K,  		   0x000000, 0x001FFF},
	{PORTION_BOTTOM_16K, 		   0x000000, 0x003FFF},
	{PORTION_BOTTOM_32K, 		   0x000000, 0x007FFF},
	{PORTION_LOWER_63_64, 		   0xFFFFFFFF, 0xFFFFFFFF}, //this is useless type in 2M flash	
	{PORTION_LOWER_31_32, 		   0x000000, 0x1EFFFF},
	{PORTION_LOWER_15_16, 		   0x000000, 0x1DFFFF},
	{PORTION_LOWER_7_8, 		   0x000000, 0x1BFFFF},
	{PORTION_LOWER_3_4, 		   0x000000, 0x17FFFF},
#ifndef FBP_THIN		
	{PORTION_UPPER_63_64, 	       0xFFFFFFFF, 0xFFFFFFFF}, //this is useless type in 2M flash
	{PORTION_UPPER_31_32, 	       0x010000, 0x1FFFFF},
	{PORTION_UPPER_15_16, 	       0x020000, 0x1FFFFF},
	{PORTION_UPPER_7_8, 	       0x040000, 0x1FFFFF},
	{PORTION_UPPER_3_4, 	       0x080000, 0x1FFFFF},
	{PORTION_UNPROTECT_TOP_4K, 	   0x000000, 0x1FEFFF},
	{PORTION_UNPROTECT_TOP_8K, 	   0x000000, 0x1FDFFF},
	{PORTION_UNPROTECT_TOP_16K,    0x000000, 0x1FBFFF},
	{PORTION_UNPROTECT_TOP_32K,    0x000000, 0x1F7FFF},
	{PORTION_UNPROTECT_BOTTOM_4K,  0x001000, 0x1FFFFF},
	{PORTION_UNPROTECT_BOTTOM_8K,  0x002000, 0x1FFFFF},
	{PORTION_UNPROTECT_BOTTOM_16K, 0x004000, 0x1FFFFF},
	{PORTION_UNPROTECT_BOTTOM_32K, 0x008000, 0x1FFFFF},
#endif	
	{PORTION_ALL, 				   0x000000, 0x1FFFFF},
};

int qspi_nor_find_fbp(uint32_t start_addr, uint32_t end_addr, struct spi_flash_chip *chip)
{
	ProtectAreaInfo *pProtectAreaInfo = NULL, *pTempProtectAreaInfo = NULL;
	//struct spi_flash_chip *chip = &nor_chip;
	int type_num = 0;
	int total_type = 0;
	int protect_type = -1;
	uint32_t size = 0, temp_size = 0;
	int first_entry = 1;

	if(!chip)
	{
		uart_printf("%s:chip is null\r\n", __func__);
		return protect_type;
	}

	uart_printf("%s: flash size is 0x%llx, name is %s\r\n", __func__, chip->size, chip->name);

		//160x series only built-in GD and XMC flash,both of them have the same FBP setting
#ifndef CRANEL_CHIP
	if(chip->size == 16*1024*1024){
		pProtectAreaInfo = &ProtectAreaInfo_16M[0];
		total_type = sizeof(ProtectAreaInfo_16M)/sizeof(ProtectAreaInfo);
	}	
	else 
#endif		
	if(chip->size == 8*1024*1024){
		pProtectAreaInfo = &ProtectAreaInfo_8M[0];
		total_type = sizeof(ProtectAreaInfo_8M)/sizeof(ProtectAreaInfo);
	}
	else if(chip->size == 4*1024*1024){
		pProtectAreaInfo = &ProtectAreaInfo_4M[0];
		total_type = sizeof(ProtectAreaInfo_4M)/sizeof(ProtectAreaInfo);
	}
	else if(chip->size == 2*1024*1024)
	{
		pProtectAreaInfo = &ProtectAreaInfo_2M[0];		
		total_type = sizeof(ProtectAreaInfo_2M)/sizeof(ProtectAreaInfo);
	}
	else
	{
		uart_printf("%s:unkown flash,not support fbp\r\n", __func__);
		return protect_type;
	}


	for(type_num = PORTION_NONE; type_num < total_type; type_num++)
	{

		pTempProtectAreaInfo = (ProtectAreaInfo *)(pProtectAreaInfo + type_num);

		if(pTempProtectAreaInfo->start_address == 0x0 && pTempProtectAreaInfo->end_address <= end_addr)
		{
			if(first_entry)
			{
				size = pTempProtectAreaInfo->end_address - 0x0;
				protect_type = pProtectAreaInfo[type_num].protect_type;
				first_entry = 0;
			}

			//CPUartLogPrintf("protect_type=%d,size=0x%x",protect_type,size);

			if(size < pTempProtectAreaInfo->end_address)
			{
				size = pTempProtectAreaInfo->end_address - 0x0;
				protect_type = pProtectAreaInfo[type_num].protect_type;
			}
		}
	}

	uart_printf("%s:find type is %d, protect area=0x0~0x%lx\r\n", __func__, protect_type, size);
	return protect_type;
	
}

int qspi_nor_set_fbp(ProtectedAreaSizeType protect_type, struct spi_flash_chip *chip)
{
	uint8_t status1,status2,n_status1,n_status2;
	uint8_t data[2];
	uint8_t status;
	int ret = 0;
	int is2MFlashFlag = 0;
	//struct spi_flash_chip *chip = &nor_chip;

	if(chip->size == 2*1024*1024)
	{
		is2MFlashFlag = 1;
		uart_printf("%s:set is2MFlashFlag to 1.\r\n", __func__);
	}

	ret = spi_nor_read_status1(chip, &status1);
	if(ret < 0)
	{
		uart_printf("%s:spi_nor_read_status1 failed.\r\n", __func__);
		return ret;
	}

	if((chip->options & SPINOR_WRITE_STATUS1_1BYTE) && !(chip->options & SPINOR_HAVE_WRITE_STATUS2))  //no read SR2 if no SR2
		status2 = 0;
	else
	{
		ret = spi_nor_read_status2(chip, &status2);
		if(ret < 0)
		{
			uart_printf("%s:spi_nor_read_status2 failed.\r\n", __func__);
			return ret;
		}
	}

	uart_printf("%s:org status1[0x%x],status2[0x%x].\r\n", __func__, status1, status2);
	n_status1 = status1;
	n_status2 = status2;

	switch(protect_type)
	{
		case PORTION_NONE:
		{
			if(is2MFlashFlag)
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = status1 | (6 << 2); // 2M flash only set bp2-bp1
				}
				else //CMP = 0
				{
					status1 = status1 & 0xE3; //b 11100011 clear bp2-bp0
				}
			}
			else
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = status1 | (7 << 2);
				}
				else //CMP = 0
				{
					status1 = status1 & 0xE3; //b 11100011 clear bp2-bp0
				}
			}
			//uart_printf("PORTION_NONE,status1[0x%x],status2[0x%lx]\r\n", __func__, status1, status2);
			break;
		}
		
		case PORTION_ALL:
		{
			if(is2MFlashFlag)
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = status1 & 0xE3; //b 11100011 clear bp2-bp0
				}
				else //CMP = 0
				{
					status1 = status1 | (6 << 2); // 2M flash only set bp2-bp1
				}
			}
			else
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = status1 & 0xE3; //b 11100011 clear bp2-bp0
				}
				else //CMP = 0
				{
					status1 = status1 | (7 << 2);
				}
			}
			//uart_printf("PORTION_ALL,status1[0x%x],status2[0x%lx]\r\n", __func__, status1, status2);
			break;
		}
#ifndef FBP_THIN		
		case PORTION_UPPER_1_64:
		{
			if(is2MFlashFlag)
			{
				uart_printf("%s:2M flash not support PORTION_UPPER_1_64\r\n", __func__);
				return -1;
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x04; // b 00000100
			}
			//uart_printf("PORTION_UPPER_1_64,status1[0x%x],status2[0x%lx]\r\n", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_1_32:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x04; // b  00000100
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x08; // b  00001000
			}
			//uart_printf("PORTION_UPPER_1_32,status1[0x%x],status2[0x%lx]\r\n", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_1_16:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x08; // b  00001000
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x0C; // b  00001100
			}
			//uart_printf("PORTION_UPPER_1_16,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_1_8:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x0C; // b  00001100
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x10; // b  00010000
			}
			//uart_printf("PORTION_UPPER_1_8,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_1_4:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x10; // b  00010000
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x12; // b  00010100
			}
			//uart_printf("PORTION_UPPER_1_4,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_1_2:
		{
			if(is2MFlashFlag)
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x34; // b  00110100
				}
				else //CMP = 0
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x12; // b  00010100
				}
			}
			else
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x38; // b  00111000
				}
				else //CMP = 0
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x14; // b  00011000
				}
			}
			//uart_printf("PORTION_UPPER_1_2,status1[0x%x],status2[0x%lx]\r\n", __func__, status1, status2);
			break;
		}
#endif
		case PORTION_LOWER_1_64:
		{
			if(is2MFlashFlag)
			{
				uart_printf("%s:2M flash not support PORTION_UPPER_1_64\r\n", __func__);
				return -1;
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x24; // b  00100100
			}
			//uart_printf("PORTION_LOWER_1_64,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_1_32:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x24; // b  00100100
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x28; // b  00101000
			}
			//uart_printf("PORTION_LOWER_1_32,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_1_16:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x28; // b  00101000
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x2C; // b  00101100
			}
			//uart_printf("PORTION_LOWER_1_16,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_1_8:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x2C; // b  00101100
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x30; // b  00110000
			}
			//uart_printf("PORTION_LOWER_1_8,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_1_4:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x30; // b  00110000
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x34; // b  00110100
			}
			//uart_printf("PORTION_LOWER_1_4,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_1_2:
		{
			if(is2MFlashFlag)
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x14; // b  00010100
				}
				else //CMP = 0
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x34; // b  00110100
				}
			}
			else
			{
				if(status2 & (1<<6)) //CMP = 1
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x18; // b  00011000
				}
				else //CMP = 0
				{
					status1 = ALL_BP_BITS_CLEAR(status1)| 0x38; // b  00111000
				}
			}
			//uart_printf("PORTION_LOWER_1_2,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#ifndef FBP_THIN
		case PORTION_TOP_4K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x44; // b  01000100
			//uart_printf("PORTION_TOP_4K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_TOP_8K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x48; // b  01001000
			//uart_printf("PORTION_TOP_8K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_TOP_16K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x4C; // b  01001100
			//uart_printf("PORTION_TOP_16K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_TOP_32K:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x50; // b  01010x00
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x58; // b  01011000
			}
			//uart_printf("PORTION_TOP_32K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#endif

		case PORTION_BOTTOM_4K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x64; // b  01100100
			//uart_printf("PORTION_BOTTOM_4K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_BOTTOM_8K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x68; // b  01101000
			//uart_printf("PORTION_BOTTOM_8K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_BOTTOM_16K:
		{
			status2 = status2 & 0xBF; // set cmp to 0;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x6C; // b  01101100
			//uart_printf("PORTION_BOTTOM_16K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_BOTTOM_32K:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x70; // b  01110X00
			}
			else
			{
				status2 = status2 & 0xBF; // set cmp to 0;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x70; // b  01111000	//XMC 4MB only support 0x70 but XMC 8MB/16MB support both 0x78 and 0x70
			}
			//uart_printf("PORTION_BOTTOM_32K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
		case PORTION_LOWER_63_64:
		{
			if(is2MFlashFlag)
			{
				uart_printf("%s:2M flash not support PORTION_LOWER_63_64\r\n", __func__);
				return -1;
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x04; // b  00000100
			}
			//uart_printf("PORTION_LOWER_63_64,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		
		case PORTION_LOWER_31_32:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x04; // b  00000100
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x08; // b  00001000
			}
			//uart_printf("PORTION_LOWER_31_32,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_15_16:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x08; // b  00001000
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x0C; // b  00001100
			}
			//uart_printf("PORTION_LOWER_15_16,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_7_8:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x0C; // b  00001100
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x10; // b  00010000
			}
			//uart_printf("PORTION_LOWER_7_8,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_LOWER_3_4:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x10; // b  00010000
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x14; // b  00010100
			}
			//uart_printf("PORTION_LOWER_3_4,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#ifndef FBP_THIN
		case PORTION_UPPER_63_64:
		{
			if(is2MFlashFlag)
			{
				uart_printf("%s:2M flash not support PORTION_UPPER_63_64\r\n", __func__);
				return -1;
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x24; // b  00100100
			}
			//uart_printf("PORTION_UPPER_63_64,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_31_32:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x24; // b  00100100
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x28; // b  00101000
			}
			//uart_printf("PORTION_UPPER_31_32,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_15_16:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x28; // b  00101000
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x2C; // b  00101100
			}
			//uart_printf("PORTION_UPPER_15_16,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_7_8:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x2C; // b  00101100
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x30; // b  00110000
			}
			//uart_printf("PORTION_UPPER_7_8,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UPPER_3_4:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x30; // b  00110000
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x34; // b  00110100
			}
			//uart_printf("PORTION_UPPER_3_4,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#endif
		case PORTION_UNPROTECT_TOP_4K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x44; // b  01000100
			//uart_printf("PORTION_UNPROTECT_TOP_4K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_TOP_8K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x48; // b  01001000
			//uart_printf("PORTION_UNPROTECT_TOP_8K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_TOP_16K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x4C; // b  01001100
			//uart_printf("PORTION_UNPROTECT_TOP_16K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_TOP_32K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x50; // b  01010000
			//uart_printf("PORTION_UNPROTECT_TOP_32K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#ifndef FBP_THIN
		case PORTION_UNPROTECT_BOTTOM_4K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x64; // b  01100100
			//uart_printf("PORTION_UNPROTECT_BOTTOM_4K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_BOTTOM_8K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x68; // b  01101000
			//uart_printf("PORTION_UNPROTECT_BOTTOM_8K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_BOTTOM_16K:
		{
			status2 = status2 | (1<<6); // set cmp to 1;
			status1 = ALL_BP_BITS_CLEAR(status1)| 0x6C; // b  01101100
			//uart_printf("PORTION_UNPROTECT_BOTTOM_16K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}

		case PORTION_UNPROTECT_BOTTOM_32K:
		{
			if(is2MFlashFlag)
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x70; // b  01110x00
			}
			else
			{
				status2 = status2 | (1<<6); // set cmp to 1;
				status1 = ALL_BP_BITS_CLEAR(status1)| 0x78; // b  01111000
			}
			//uart_printf("PORTION_UNPROTECT_BOTTOM_32K,status1[0x%x],status2[0x%lx]", __func__, status1, status2);
			break;
		}
#endif
		default:
		{
			uart_printf("%s:unkown type,not support.\r\n", __func__);
			return -1;
		}
	}

	uart_printf("%s:new status1[0x%x],status2[0x%x].\n", __func__, status1, status2);
	
	data[0] = status1;
	data[1] = status2;
	
	if((ALL_BP_BITS_GET(n_status1) == ALL_BP_BITS_GET(status1)) && (n_status2 == status2))
	{
		uart_printf("%s: fbp no change.\r\n", __func__);
		return 0;
	}
	//spi_nor_write_enable(chip);
	
	if (chip->options & SPINOR_HAVE_WRITE_STATUS2)
	{
		//uart_printf("%s:SPINOR_HAVE_WRITE_STATUS2,data_0[0x%x],data_1[0x%x]", __func__, data[0], data[1]);
		spi_nor_write_volatile_status_register_enable(chip);
		ret = spi_nor_write_status2(chip, &data[1]);
		if(ret != 0)
		{
			uart_printf("error %d spi_nor_write_status2\n", ret);
		}
		
		//uart_printf("%s:SPINOR_WRITE_STATUS1_1BYTE", __func__);
		spi_nor_write_volatile_status_register_enable(chip);
		ret = spi_nor_write_status1(chip, data, 1);
		if(ret != 0)
		{
			uart_printf("error %d spi_nor_write_status1 1byte\n", ret);
		}

	}	
	else if (chip->options & SPINOR_WRITE_STATUS1_1BYTE)
	{
		//CPUartLogPrintf("%s:SPINOR_WRITE_STATUS1_1BYTE", __func__);
		spi_nor_write_volatile_status_register_enable(chip);
		ret = spi_nor_write_status1(chip, data, 1);
		if(ret != 0)
		{
			uart_printf("error %d spi_nor_write_status1 1byte\n", ret);
		}
	}
	else
	{
		spi_nor_write_volatile_status_register_enable(chip);
		ret = spi_nor_write_status1(chip, data, 2);
		if(ret != 0)
		{
			uart_printf("error %d spi_nor_write_status1 2byte\n", ret);
		}
	}

	
	
#ifdef SW_HANDLE_XIP
	ret = spi_nor_wait(chip, &status, 0, NULL);
#else
	ret = spi_nor_wait(chip, &status);
#endif
	if (ret < 0) {
		uart_printf("error %d write status register\n", ret);
		return ret;
	}

	spi_nor_read_status1(chip, &n_status1);
	
	if((chip->options & SPINOR_WRITE_STATUS1_1BYTE) && !(chip->options & SPINOR_HAVE_WRITE_STATUS2)) ////no read SR2 if no SR2
		n_status2 = 0;
	else
		spi_nor_read_status2(chip, &n_status2);

	uart_printf("%s:read back,n_status1[0x%x],n_status2[0x%x].\r\n", __func__, n_status1, n_status2);
	if((ALL_BP_BITS_GET(n_status1) == ALL_BP_BITS_GET(status1)) && (n_status2 == status2))
	{
		flash_protect_area_type = protect_type;
		uart_printf("%s:fbp valid.\r\n", __func__);
	}

	return ret;
}

//flash hardware protect--chenjian
void crane_set_fbp(BOOL is_updater)
{
	//protect bootloader(low 64K) in updater only
	UINT32 protect_start_addr = 0x0; 
	UINT32 protect_end_addr = 0x10000; 
	int protect_type = -1;
	struct spi_flash_chip *chip = get_spi_flash_chip(1);

	if(chip==NULL){
		uart_printf("%s chip is null\n", __func__);
 		return;
    }

	if(is_updater == FALSE)
	{
		 protect_start_addr = 0x0;
		 protect_end_addr = get_reserved_end_address() - 0x80000000;
	}
	
	uart_printf("%s:protect_start_addr[0x%lx],protect_end_addr[0x%lx]\r\n", __func__, protect_start_addr, protect_end_addr);

	protect_type = qspi_nor_find_fbp(protect_start_addr, protect_end_addr, chip);
	if(protect_type < 0)
	{
		uart_printf("%s: cannt find match fbp type\r\n", __func__);
		return;
	}

	qspi_nor_set_fbp((ProtectedAreaSizeType)protect_type, chip);

	return;
}


#endif



