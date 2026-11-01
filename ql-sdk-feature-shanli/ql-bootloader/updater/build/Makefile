TARGET_	= updater

#Default: DS-5 is added in Patch
CC 	    = armcc.exe
LINK 	= armlink.exe
FROMELF	= fromelf.exe
AR      = armar.exe

src_dir = ../src
inc_dir = ../inc
scatter_dir = ..

obj_dir = obj

#common start
src_common_dir = ../../common/src
inc_common_dir = ../../common/inc
obj_common_dir = obj\obj_common
#common end

#lcd start
src_lcd_dir = ../../common/src
inc_lcd_dir = ../../common/inc
obj_lcd_dir = obj\obj_lcd
#lcd end

#quectel start
src_quectel_dir = ../quectel/src
inc_quectel_dir = ../quectel/inc
obj_quectel_dir = ..\quectel\obj
#quectel end

lib_dir = ..\lib

feedback = feedback.txt
cflag=-I$(inc_dir) -I$(inc_common_dir) --cpu Cortex-R5  --no_unaligned_access -g -O2 --apcs /inter --gnu --feedback $(feedback)
#lcd start
cflag += -I$(inc_lcd_dir)
#lcd end

#lcd start
cflag += -I$(inc_quectel_dir)
#lcd end

cflag += -DFOTA_ASRDM  -DQUECTEL_FOTA  -DQUECTEL_PROJECT_EC200S -DQUECTEL_OPEN_CPU -DSUPPORT_FBP -DSUPPORT_EXTERNAL_NORFLASH

#extflash_start
#cflag += -DSUPPORT_EXTERNAL_NORFLASH
#extflash_end
src_dir_ = $(src_lcd_dir) $(src_quectel_dir)

TARGET = ${TARGET_}${lcd_type}

#common start
srcs_common = \
	$(src_common_dir)/plat_api.c \
	$(src_common_dir)/asr_property.c \
	$(src_common_dir)/bsp_tavor.c \
	$(src_common_dir)/utilities.c \
	$(src_common_dir)/pmic.c \
	$(src_common_dir)/ningbo.c \
	$(src_common_dir)/guilin.c \
	$(src_common_dir)/guilin_lite.c \
	$(src_common_dir)/guilin_lite2.c \
	$(src_common_dir)/FreqChange.c \
	$(src_common_dir)/uart.c \
	$(src_common_dir)/sdcard.c \
	$(src_common_dir)/diskio.c \
	$(src_common_dir)/ff.c \
	$(src_common_dir)/ff_dump_mem.c \
	$(src_common_dir)/ffsystem.c \
	$(src_common_dir)/ffunicode.c \
	$(src_common_dir)/qspi_core.c \
	$(src_common_dir)/qspi_dma.c \
	$(src_common_dir)/qspi_host.c \
	$(src_common_dir)/qspi_nor.c \
	$(src_common_dir)/system.c \
	$(src_common_dir)/loadtable.c \
	$(src_common_dir)/ptable.c \
	$(src_common_dir)/LzmaDec.c \
	$(src_common_dir)/lzop.c \
	$(src_common_dir)/lzop_buf.c \
	$(src_common_dir)/minilzo.c \
	$(src_common_dir)/LzmaEnc.c \
	$(src_common_dir)/LzFind.c \
	$(src_common_dir)/LzmaLib.c \
	$(src_common_dir)/lzo1x_9x.c \
	$(src_common_dir)/lzo_mchw.c \
	$(src_common_dir)/lzo_swd.c \
	$(src_common_dir)/lzo1x_oo.c \
	$(src_common_dir)/tinyalloc.c \
	$(src_common_dir)/updater_table.c \
	$(src_common_dir)/asr_lzma.c \
	$(src_common_dir)/logo_table.c \
	$(src_common_dir)/quec_startup_gpio.c \
	$(src_common_dir)/quec_spi_nor.c	\
	$(src_common_dir)/SPI.c	\
	$(src_common_dir)/quec_spi.c	\
	$(src_common_dir)/qspi_nor_bp.c
#common end

#lcd start
cflag += -DCRANE_MCU_DONGLE
srcs_lcd = \
	$(src_common_dir)/quec_lcd_application.c \
	$(src_common_dir)/quec_spi_drv.c \
	$(src_common_dir)/quec_ssp_lcd.c 
#lcd end

#quectel start
srcs_quectel = $(src_quectel_dir)/src/ql_updater_usr_func.c

#quectel end

#common start
dep_files += $(wildcard $(inc_common_dir)/*.h)
objs_common = $(patsubst %.c, ${obj_common_dir}/%.o, ${notdir ${srcs_common}})
#common end

#lcd start
dep_files += $(wildcard $(inc_lcd_dir)/*.h)
objs_lcd = $(patsubst %.c, ${obj_lcd_dir}/%.o, ${notdir ${srcs_lcd}})
#lcd end

#quectel start
dep_files += $(wildcard $(inc_quectel_dir)/*.h)
objs_quectel = $(patsubst %.c, ${obj_quectel_dir}/%.o, ${notdir ${srcs_quectel}})
#quectel end

#common start
objs_sum = $(objs_common)
#common end

#lcd start
objs_sum += $(objs_lcd)
#lcd end

#quectel start
objs_sum += $(objs_quectel)
#quectel end

LIB = ${lib_dir}/ql_updater.lib

ifeq (,$(findstring 4MRAM,${PSRAM_TYPE}))
#1. UPD_SIZE = {updater.bin} size
	perl $(common_tool_dir)/external_ext_bin_size_update.pl ${TARGET}.bin UPD_SIZE
ifneq (,$(findstring y,$(CONFIG_APPEND_DSP_ADC)))		
#2. append dsp_adc.bin into {updater.bin}. ( note: need provide front.bin size --- UPD_SIZE)
	perl $(common_tool_dir)/external_ext_bin_append.pl APPEND ${TARGET}.bin UPD_SIZE $(common_lib_dir)/dsp_adc_lzma.bin ADC_SIZE
endif	
#3. EXT_SIZE =   {updater.bin + dsp_adc.bin} size	
	perl $(common_tool_dir)/external_ext_bin_size_update.pl ${TARGET}.bin EXT_SIZE
#4. append "internal crc res" into end of image.
	perl $(common_tool_dir)/external_append_pad_crc.pl ${TARGET}.bin
endif

ifeq (,$(findstring 4MRAM,${PSRAM_TYPE}))
	scatter_file_name = scatter
endif

ifneq (,$(findstring 4MRAM,${PSRAM_TYPE}))
	scatter_file_name = scatter_craneL
	cflag += -DCRANEL_PSRAM_4M
endif

ifeq (,$(findstring 4MRAM,${PSRAM_TYPE}))
	cflag += -DSUPPORT_FBF_FOTA_VERSION
	cflag += -DSUPPORT_FBF_DFOTA_VERSION
	cflag += -DSUPPORT_NEW_MINI_OTA_VERSION
	cflag += -DSUPPORT_ADIFF_DFOTA_VERSION
endif

${TARGET}.axf:$(objs_sum)
	if not exist ${feedback} @echo "ERROR : make feedback firstly" && exit 1
	$(LINK) $(LIB) $(objs_sum) --scatter $(scatter_dir)/scatter.scat --output $@ --map --symbols --info sizes,totals --list ${TARGET}.map --keep version_block.o(IMGVERBLOCK)
	$(FROMELF) --output ${TARGET}.bin --bin ${TARGET}.axf

#common start
::1.build ../../common/*.c ----> obj/obj_common/*.o
${obj_common_dir}/%.o:${src_common_dir}/%.c $(dep_files)
	if not exist $(obj_common_dir) mkdir $(obj_common_dir)
	$(CC) $(cflag) --thumb -c $< -o $@
#common end

#lcd start
::2.build srcs/lcd/*.c ----> obj/obj_lcd/*.o
${obj_lcd_dir}/%.o:${src_lcd_dir}/%.c $(dep_files)
	if not exist $(obj_lcd_dir) mkdir $(obj_lcd_dir)
	$(CC) $(cflag) --thumb -c $< -o $@
#lcd end

#quectel start
::3.build quectel/src/*.c ----> quectel/obj/*.o
${obj_quectel_dir}/%.o:${src_quectel_dir}/%.c $(dep_files)
	if not exist $(obj_quectel_dir) mkdir $(obj_quectel_dir)
	$(CC) $(cflag) --thumb -c $< -o $@
#quectel end

feedback:$(objs_sum)
	$(LINK) ${LIB} $(objs_sum)  --scatter $(scatter_dir)/scatter.scat --output feedback.axf --keep version_block.o(IMGVERBLOCK) --feedback=${feedback}
	rd /s /q $(obj_dir)
	del feedback.axf


clean:
	del updater*.bin
	del updater*.map
	del updater*.axf
	del buildlog.txt
	rd /s /q  $(obj_dir)
	rd /s /q  $(obj_quectel_dir)
	
