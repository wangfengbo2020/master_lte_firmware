TARGET_	= ${TARGET_BAT}

#Default: DS-5 is added in Patch
CC 	    = armcc.exe
LINK 	= armlink.exe
FROMELF	= fromelf.exe

src_dir = ../src
inc_dir = ../inc
scatter_dir = ..

obj_dir = obj

feedback = feedback.txt

SCATTER_FILE = scatter.scat

#common start
common_dir     = ../../common
common_src_dir = $(common_dir)/src
common_inc_dir = $(common_dir)/inc
common_lib_dir = $(common_dir)/lib
common_tool_dir = $(common_dir)/tool
obj_common_dir = obj_common
#common end

DSP_ADC_CONFIG_FILE_DIR   = $(common_lib_dir)
DSP_ADC_BUILD_CONFIG_NAME = .dsp_adc_build_config

include $(DSP_ADC_CONFIG_FILE_DIR)/$(DSP_ADC_BUILD_CONFIG_NAME)

cflag=-I$(inc_dir) --cpu Cortex-R5  --no_unaligned_access -g -O2 --apcs /inter --gnu --split_sections

#*************************PLATFORM********************
ifneq (,$(findstring OCPU,${QUECTEL_PROJ}))
	cflag += -DQUECTEL_OPEN_CPU
endif

#ASR-1606
ifneq (,$(findstring CRANEL,${CHIP_TYPE}))
	cflag += -DASR_PLATFORM_CRANEL
	cflag += -DCRANEL_CHIP
	ifneq (,$(findstring CRANEL_SINGLESIM,${CHIP_TYPE}))
		cflag += -DLTEONLY_SINGLE_SIM
		SCATTER_FILE = scatter_craneL_SingleSim.scat
	else
		SCATTER_FILE = scatter_craneL.scat
	endif
endif

#ASR-1603
ifneq (,$(findstring CRANEM,${CHIP_TYPE}))
	cflag += -DASR_PLATFORM_CRANEM
	#***SMALL_CODE*******#是否需要开启DSP ADC
	ifneq (,$(findstring LOGO,${SMALL_CODE}))
		cflag += -DSMALL_CODE_LOGO
	endif
endif
#*****************************************************

#common start
cflag += -I$(common_inc_dir)
#common end
ifneq (,$(findstring enable,${DMCHAGE}))
cflag += -I$(common_inc_dir)/charge
endif

src_dir_ = $(src_dir) $(common_src_dir)
#Macro Used if CP is Erased
#DEFS = -DCP_ERASE

cflag += $(DEFS)

#++++++++++++++++++++++
#1. NO LCD
ifneq (,$(findstring NO_LCD,${LCD_TYPE}))
#	cflag += -DLCD_USE_IN_CODE
#	cflag += -DLCD_ST7789V_MCU
#	cflag += -DNO_LCD
	lcd_type =${TARGET_SYFFIX}
endif


# check if enable charge
ifneq (,$(findstring enable,${DMCHAGE}))
	cflag += -DDMCHAGE
endif

TARGET = ${TARGET_}${lcd_type}
#++++++++++++++++++++++
srcs = $(src_dir)/main.c \
	$(src_dir)/version_logo.c


#common start
#add ../../common
#Note: create a new MACRO: "srcs_common"
cflag += -DCRANE_MCU_DONGLE
srcs_common = $(common_src_dir)/ui_os_api.c \
	$(common_src_dir)/plat_api.c \
	$(common_src_dir)/pwm_drv.c \
	$(common_src_dir)/asr_property.c \
	$(common_src_dir)/system.c \
	$(common_src_dir)/FreqChange.c \
	$(common_src_dir)/bsp_tavor.c \
	$(common_src_dir)/LzmaDec.c \
	$(common_src_dir)/tinyalloc.c \
	$(common_src_dir)/utilities.c \
	$(common_src_dir)/pmic.c \
	$(common_src_dir)/ningbo.c \
	$(common_src_dir)/guilin.c \
	$(common_src_dir)/guilin_lite.c \
	$(common_src_dir)/guilin_lite2.c \
	$(common_src_dir)/loadtable.c \
	$(common_src_dir)/ptable.c \
	$(common_src_dir)/lzop_buf.c \
	$(common_src_dir)/lzop.c \
	$(common_src_dir)/minilzo.c \
	$(common_src_dir)/qspi_core.c \
	$(common_src_dir)/qspi_dma.c \
	$(common_src_dir)/qspi_host.c \
	$(common_src_dir)/qspi_nor.c \
	$(common_src_dir)/uart.c \
	$(common_src_dir)/LzmaEnc.c \
	$(common_src_dir)/LzFind.c \
	$(common_src_dir)/LzmaLib.c \
	$(common_src_dir)/lzo1x_9x.c \
	$(common_src_dir)/lzo_mchw.c \
	$(common_src_dir)/lzo_swd.c \
	$(common_src_dir)/lzo1x_oo.c \
	$(common_src_dir)/logo_table.c \
	$(common_src_dir)/updater_table.c \
	$(common_src_dir)/asr_lzma.c \
	$(common_src_dir)/quec_startup_gpio.c	\
	$(common_src_dir)/ql_boot_power.c	\
	$(common_src_dir)/ql_boot_adc.c	\
#common end

#是否使用LCD
ifneq (,$(findstring USE_LCD,${LCD_TYPE}))
	srcs_common += \
	        $(common_src_dir)/quec_lcd_application.c \
		    $(common_src_dir)/quec_spi_drv.c \
		    $(common_src_dir)/quec_ssp_lcd.c \
			$(common_src_dir)/quec_spi.c
			
endif

ifneq (,$(findstring enable,${DMCHAGE}))
	srcs += $(src_dir)/charge/charge.c \
		$(src_dir)/charge/i2c.c \
		$(src_dir)/charge/charge_compound.c \
		$(src_dir)/charge/ningbo.c \
		$(src_dir)/charge/guilin.c \
		$(src_dir)/charge/pm812.c \
		$(src_dir)/charge/guilin_lite.c \
		$(src_dir)/charge/eta4256.c
endif

ifneq (,$(findstring SDCARD_USE,${SDCARD}))
	cflag += -DSDCARD_USE_IN_CODE
#add sdcard source code
	srcs += $(common_src_dir)/sdcard.c  \
	$(common_src_dir)/diskio.c \
	$(common_src_dir)/ff.c \
	$(common_src_dir)/ff_dump_mem.c \
	$(common_src_dir)/ffsystem.c \
	$(common_src_dir)/ffunicode.c
endif

dep_files = $(wildcard $(inc_dir)/*.h $(common_inc_dir)/*.h)
objs = $(patsubst %.c, ${obj_dir}/%.o, ${notdir ${srcs}})

#common start
dep_files += $(wildcard $(common_inc_dir)/*.h)
objs_common = $(patsubst %.c, ${obj_common_dir}/%.o, ${notdir ${srcs_common}})
#else
#objs_common =
#common end

ifneq (,$(findstring enable,${DMCHAGE}))
dep_files += $(wildcard $(inc_dir)/charge/*.h)
#objs += $(patsubst %.c, ${obj_dir}/charge/%.o, ${notdir ${srcs}})
endif

objs_sum = $(objs)

#common start
objs_sum += $(objs_common)
#common end

${TARGET}.axf:$(objs_sum)
	$(CC) $(cflag) -c $(src_dir)/OBM_StartUp.s -o $(obj_dir)/OBM_StartUp.o
	$(LINK) $(objs_sum) $(obj_dir)/OBM_StartUp.o --scatter $(scatter_dir)/$(SCATTER_FILE) --output $@ --map --symbols --info sizes,totals --list ${TARGET}.map --keep version_logo.o(IMGLOGO)

	$(FROMELF) --output ${TARGET}.bin --bin ${TARGET}.axf
	
#1. build srcs\*.c ---> obj/*.o
${obj_dir}/%.o:$(src_dir)/%.c $(dep_files) 
	if not exist "$(obj_dir)" mkdir $(obj_dir)
	$(CC) $(cflag) -c $< -o $@

#common start
#2. build $(common_src_dir)/*.c ---> obj_common/*.o
${obj_common_dir}/%.o: $(common_src_dir)/%.c $(dep_files) 
	if not exist "$(obj_common_dir)" mkdir $(obj_common_dir)
	$(CC) $(cflag) -c $< -o $@
#common end

ifneq (,$(findstring enable,${DMCHAGE}))
${obj_dir}/%.o:$(src_dir)/charge/%.c $(dep_files)
	if not exist "$(obj_dir)" mkdir $(obj_dir)
	$(CC) $(cflag) -c $< -o $@
endif

feedback:$(objs_sum)
	$(CC) $(cflag) -c $(src_dir)/OBM_StartUp.s -o obj/OBM_StartUp.o
	$(LINK) $(objs_sum) obj/OBM_StartUp.o --scatter ../$(SCATTER_FILE) --output feedback.axf --keep version_logo.o(IMGVERLOGO) --feedback=${feedback}
	rd /s /q $(obj_dir)
	del feedback.axf
	if exist $(obj_dir) rd /s /q $(obj_dir)
	if exist $(obj_common_dir) rd /s /q $(obj_common_dir)
	
clean:
	del ${TARGET_PREFIX}*.bin
	del ${TARGET_PREFIX}*.axf
	del ${TARGET_PREFIX}*.map
	del buildlog.txt	
	rd /s /q $(obj_dir)
	rd /s /q $(obj_common_dir)

handle_after_compress:
ifeq (,$(findstring CRANEL,${CHIP_TYPE}))
	rename ${TARGET_PREFIX}*.bin ${TARGET}.bin
#1. LOGO_SIZE = {logo.bin} size	
	perl $(common_tool_dir)/external_ext_bin_size_update.pl ${TARGET}.bin LOGO_SIZE
ifneq (,$(findstring y,$(CONFIG_APPEND_DSP_ADC)))		
#2. append dsp_adc.bin into {updater.bin}. ( note: need provide front.bin size --- UPD_SIZE)
	perl $(common_tool_dir)/external_ext_bin_append.pl APPEND ${TARGET}.bin LOGO_SIZE $(common_lib_dir)/dsp_adc_lzma.bin ADC_SIZE
endif
#3. EXT_SIZE =   {updater.bin + dsp_adc.bin} size	
	perl $(common_tool_dir)/external_ext_bin_size_update.pl ${TARGET}.bin EXT_SIZE
endif