@echo off

::---------------------------------------------
::Script_name: support_asr_lzop_script_ver2.bat
::Author:      CP_PLATFORM_SH
::Time:        2020-03-19
::Version:     2.0
::Description: use  asr_logo1_create_header_file_ver1.exe
::                  asr_lzop.exe
::                  asr_logo2_merge_file_ver1.exe    
::             to generate logo.bin which is compressed
::输出文件名：  logo.bin

::使用方法：在当前目录放一个*logo*.bin，双击该脚本，会生成一个logo.bin(头部+压缩的文件)
::---------------------------------------------

::-----------------------------config parameters ---------------------------------------------
::PARAM1
set SOURCE_FILE_RENAME=logo_no_compressed.bin

::PARAM2
set TEMP1_FILE_NAME=logo_no_compressed_header.bin 
set TEMP_IN_OUT_FILE_NAME=logo_compressed.bin
::PARAM3
set OUTPUT_FILE_NAME=logo.bin

::PARAM4
set TOOL1_CREATE_HADER_FILE_TOOL=asr_logo1_create_header_file_ver1.exe
set TOOL2_COMPRESS_TOOL_NAME=lzma.exe
set TOOL3_MERGE_FILE=asr_logo2_merge_file_ver1.exe

::--------------------------------------------------------------------------------------------


::0. del %TEMP_IN_OUT_FILE_NAME% file
if exist %TEMP_IN_OUT_FILE_NAME% (
    del %TEMP_IN_OUT_FILE_NAME%
)else (
    echo %TEMP_IN_OUT_FILE_NAME% 文件不存在
)


if exist *logo*.bin (
    rename *logo*.bin %SOURCE_FILE_RENAME%
)else (
    echo 被压缩的文件不存在
)

::1. seperate header info from %SOURCE_FILE_RENAME%
echo "***********************1*******************************"
echo "start divide logo.bin into two file: header info and the other"
start /B /WAIT %TOOL1_CREATE_HADER_FILE_TOOL%
echo "divide end"


::2. compress the logo.bin except header 16 Bytes
echo "***********************2*******************************"
echo "start compress logo.bin"
start /B /WAIT %TOOL2_COMPRESS_TOOL_NAME% e %SOURCE_FILE_RENAME% %TEMP_IN_OUT_FILE_NAME%
echo "compress end"


::3. cat  logo header info and logo_compressed file
echo "***********************3*******************************"
echo "start merge file"
start /B /WAIT %TOOL3_MERGE_FILE%
echo "merge end"

::4. delete *.bin
rename %TEMP_IN_OUT_FILE_NAME% %OUTPUT_FILE_NAME%
del %SOURCE_FILE_RENAME%










































