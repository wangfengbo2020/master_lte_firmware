TARGET_	= boot33

#Default: DS-5 is added in Patch
CC 	    = armcc.exe
LINK 	= armlink.exe
FROMELF	= fromelf.exe

src_dir = src
inc_dir = inc
obj_dir = obj
feedback_file = feedback.txt
SCATTER_FILE = scatter.scat

ifneq (,$(findstring CRANEL,${PL_TYPE}))
	ifneq (,$(findstring SINGLESIM,${PL_TYPE}))
	SCATTER_FILE = scatter_craneL_singlesim.scat
	else
	SCATTER_FILE = scatter_craneL.scat
	endif
endif
#common start
src_common_dir = ../common/src
inc_common_dir = ../common/inc
obj_common_dir = obj_common
#common end
cflag=-I$(inc_dir) --cpu Cortex-R5  --no_unaligned_access -g -O2 --apcs /inter --gnu --split_sections --feedback $(feedback_file)
#common start
cflag += -I$(inc_common_dir)
#common end

############### Define Macro in Boot33 ########################
#Macro used in boot33 can add variable: "DEFS"

#1. Macro Used if CP is Erased
DEFS = -DCP_ERASE

#2. Macro Used to check ONKEY
#DEFS += -DONKEY_CHECK

#3. Macro Used to support compressed logo bin
DEFS += -DSUPPORT_COMPRESSED_LOGO -DSUPPORT_FBP

#Last, append variable DEFS into cflag
cflag += $(DEFS)
#####################################################

ifneq (,$(findstring enable,${DMCHAGE}))
	cflag += -DDMCHAGE
endif

ifneq (,$(findstring disable,${LOGO_SUPPORT}))
	cflag += -DSUPPORT_NO_LOGO
	logo_type = _nologo
endif

ifneq (,$(findstring OCPU,${QUECTEL_PROJ}))
	cflag += -DQUECTEL_OPEN_CPU
endif


#ASR-1606
ifneq (,$(findstring CRANEL,${PL_TYPE}))
	cflag += -DASR_PLATFORM_CRANEL
	cflag += -DCRANEL_CHIP
	ifneq (,$(findstring SINGLESIM,${PL_TYPE}))
		cflag += -DLTEONLY_SINGLE_SIM
	endif
endif

ifneq (,$(findstring enable,${DM_FOTA}))
	cflag += -DBOOT33_FOTA_SUPPORT
endif

ifneq (,$(findstring enable,${FOTA_NO_UPDATER}))
	cflag += -DBOOT33_FOTA_NO_UPDATER
endif

#Boot33 Naming Rule
TARGET = ${TARGET_}${lcd_type}${logo_type}

srcs = $(src_dir)/main.c \
	$(src_dir)/version_block.c \
	$(src_dir)/ota.c\
	$(src_dir)/boot_flasherase_check.c

############ BOOT33 SECBOOT START ##############
# enable below part for BOOT33 SECBOOT support

#[secboot version 1]
#   support for full range of CRANE chips.
#   boot33 implement secboot code , more memory consumption for boot33 execution.
#   

#cflag += -DMBEDTLS_CONFIG_FILE=\"mbedtls_config.h\" \
	-DTF_MBEDTLS_KEY_ALG_ID=1 \
	-DTF_MBEDTLS_HASH_ALG_ID=1 \
	-DBOOT33_SECBOOT_SUPPORT \
	-DBOOT33_SECBOOT_V1
#srcs += $(src_dir)/fip.c \
		$(src_dir)/secboot.c \
		$(src_dir)/asn1parse.c \
		$(src_dir)/oid.c \
		$(src_dir)/sha256.c \
		$(src_dir)/md.c \
		$(src_dir)/x509.c \
		$(src_dir)/pkparse.c \
		$(src_dir)/pk.c \
		$(src_dir)/pk_wrap.c \
		$(src_dir)/rsa.c \
		$(src_dir)/rsa_internal.c \
		$(src_dir)/md_wrap.c \
		$(src_dir)/bignum.c \
		$(src_dir)/platform_util.c \
		$(src_dir)/mbedtls_common.c \
		$(src_dir)/mbedtls_crypto.c \
		$(src_dir)/mbedtls_x509_parser.c

#[secboot version 2]
#   support for particular latest design CRANE chips e.g. CRANE_L/CRANE_W.
#   boot33 call tls code which remain from previouse execution image or bootrom.
#   would save more memory for boot33.
#
ifneq (,$(findstring enable,${SECBOOT_V2_SUPPORT}))
cflag += -DBOOT33_SECBOOT_SUPPORT \
	-DBOOT33_SECBOOT_V2
srcs += $(src_dir)/fip_v2.c \
		$(src_dir)/secboot_v2.c \
		$(src_dir)/syscall.c \
		$(src_dir)/syscall_ver.c \
		$(src_dir)/syscall_secboot.c
endif
############ BOOT33 SECBOOT END ##############

#common start
srcs_common = $(src_common_dir)/asr_property.c \
				$(src_common_dir)/system.c \
				$(src_common_dir)/FreqChange.c \
				$(src_common_dir)/LzmaDec.c \
				$(src_common_dir)/tinyalloc.c \
				$(src_common_dir)/pmic.c \
				$(src_common_dir)/ningbo.c \
				$(src_common_dir)/guilin.c \
				$(src_common_dir)/utilities.c \
				$(src_common_dir)/loadtable.c \
				$(src_common_dir)/ptable.c \
				$(src_common_dir)/minilzo.c \
				$(src_common_dir)/lzop_buf.c \
				$(src_common_dir)/lzop.c \
				$(src_common_dir)/qspi_core.c \
				$(src_common_dir)/qspi_dma.c \
				$(src_common_dir)/qspi_host.c \
				$(src_common_dir)/qspi_nor.c \
				$(src_common_dir)/uart.c \
				$(src_common_dir)/guilin_lite.c \
				$(src_common_dir)/guilin_lite2.c \
				$(src_common_dir)/bsp_tavor.c \
				$(src_common_dir)/LzmaEnc.c \
				$(src_common_dir)/LzFind.c \
				$(src_common_dir)/LzmaLib.c \
				$(src_common_dir)/lzo1x_9x.c \
				$(src_common_dir)/lzo_mchw.c \
				$(src_common_dir)/lzo_swd.c \
				$(src_common_dir)/lzo1x_oo.c \
				$(src_common_dir)/updater_table.c \
				$(src_common_dir)/asr_lzma.c \
				$(src_common_dir)/logo_table.c \
				$(src_common_dir)/ql_boot_power.c	\
				$(src_common_dir)/quec_startup_gpio.c	\
				$(src_common_dir)/ql_boot_pwm.c \
				$(src_common_dir)/qspi_nor_bp.c \

ifneq (,$(findstring SPINOR_SUPPORT,${PL_TYPE}))
	cflag += -DSPINOR_SUPPORT
	srcs_common += $(src_common_dir)/SPI.c
endif

ifneq (,$(findstring enable,${DMCHAGE}))
	srcs += src/dm_charge.c \
		src/dm_ningbo.c \
		src/dm_guilin.c \
		src/dm_pm812.c \
		src/dm_i2c.c
endif
ifneq (,$(findstring SDCARD_USE,${SDCARD}))
	cflag += -DSDCARD_USE_IN_CODE
#add sdcard source code
	srcs += $(src_common_dir)/sdcard.c  \
	$(src_common_dir)/diskio.c \
	$(src_common_dir)/ff.c \
	$(src_common_dir)/ff_dump_mem.c \
	$(src_common_dir)/ffsystem.c \
	$(src_common_dir)/ffunicode.c
endif
dep_files = $(wildcard $(inc_dir)/*.h)
objs = $(patsubst %.c, ${obj_dir}/%.o, ${notdir ${srcs}})

dep_files += $(wildcard $(inc_common_dir)/*.h)
objs_common = $(patsubst %.c, ${obj_common_dir}/%.o, ${notdir ${srcs_common}})

objs_sum = $(objs) $(objs_common)

${TARGET}.axf:$(objs_sum)
	if not exist ${feedback_file} @echo "ERROR : make feedback firstly" && exit 1
	$(CC) $(cflag) -c $(src_dir)/OBM_StartUp.s -o $(obj_dir)/OBM_StartUp.o
	$(LINK) $(objs_sum) $(obj_dir)/OBM_StartUp.o --scatter $(SCATTER_FILE) --output $@ --map --symbols --info sizes,totals --list ${TARGET}.map --keep version_block.o\(IMGVERBLOCK\)
	$(FROMELF) --output ${TARGET}.bin --bin ${TARGET}.axf

${obj_common_dir}/%.o: $(src_common_dir)/%.c $(dep_files) 
	if not exist $(obj_common_dir) mkdir $(obj_common_dir)
	$(CC) $(cflag) --thumb -c $< -o $@

${obj_dir}/%.o:${src_dir}/%.c $(dep_files)
	if not exist $(obj_dir) mkdir $(obj_dir)
	$(CC) $(cflag) --thumb -c $< -o $@

feedback:$(objs_sum)
	$(CC) $(cflag) -c $(src_dir)/OBM_StartUp.s -o $(obj_dir)/OBM_StartUp.o
	$(LINK) $(objs_sum) $(obj_dir)/OBM_StartUp.o --scatter $(SCATTER_FILE) --output $(feedback_file).axf --keep version_block.o\(IMGVERBLOCK\) --feedback=${feedback_file}
	rd /s /q $(obj_dir)
	del $(feedback_file).axf

clean:
	rd /s /q $(obj_dir)
	del $(feedback_file)*
	rd /s /q $(obj_common_dir)
	del $(TARGET)*.*
