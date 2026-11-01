@echo off

::---------------------------------------------
::Script_name: asr_compressed_script.bat
::Author:      CP_PLATFORM_SH
::Time:        2020-07-22
::Version:     3.0
::Description: use  asr_split_file.exe
::                  asr_lzop.exe or asr_lzma.exe
::                  asr_merge_file.exe  
::             to partially compress the image

::使用方法：在当前目录放一个*.bin，双击该脚本，会生成一个xxx.bin(头部+压缩的文件)
::注意用户需要配置如下参数
::---------------------------------------------

::-----------------------------config parameters ---------------------------------------------
::PARAM1 --- TOOL
set TOOL1_SPLIT_FILE_TOOL=asr_split_file.exe
::set TOOL2_COMPRESS_TOOL_NAME=asr_lzop.exe
set TOOL2_COMPRESS_TOOL_NAME=asr_lzma.exe
set TOOL3_MERGE_FILE=asr_merge_file.exe

::PARMA2 --- SCRIPT INPUT_FILE AND OUTPUT FILE
set SCRIPT_INPUT_FILE_NAME=*%TARGET_PREFIX%*.bin
set SCRIPT_OUTPUT_FILE_NAME=%TARGET_PREFIX%.bin

::PARAM3 --- SPLIT
set SPLIT_ADDR_HEADER_SIZE=12 
set SPLIT_INPUT_FILE_NAME=*%TARGET_PREFIX%*.bin
set SPLIT_OUTPUT_FILE1_NAME=logo_no_compressed_sector1.bin
set SPLIT_OUTPUT_FILE2_NAME=logo_no_compressed_sector2.bin

::PARAM4 --- COMPRESS FILE
set COMPRESS_INPUT_FILE_NAME=%SPLIT_OUTPUT_FILE2_NAME% 
set COMPRESS_OUTPUT_FILE_NAME=logo_compressed_sector2.bin

::PARAM5 --- MERGE
set MERGE_INPUT_FILE1_NAME=%SPLIT_OUTPUT_FILE1_NAME%
set MERGE_INPUT_FILE2_NAME=%COMPRESS_OUTPUT_FILE_NAME%
set MERGE_OUTPUT_FILE_NAME=MERGE_OUTPUT_FILE.bin
::--------------------------------------------------------------------------------------------

::1. check source file: %SPLIT_INPUT_FILE_NAME% exist or not
if exist %SPLIT_INPUT_FILE_NAME% (
    echo %SPLIT_INPUT_FILE_NAME% exist!
)else (
    echo %SPLIT_INPUT_FILE_NAME% not exist!
    pause
)

::1. SPLIT FILE
echo "*********************** 1 SPLIT FILE *********************************************"
echo "start split %SPLIT_INPUT_FILE_NAME% into two file: %SPLIT_OUTPUT_FILE1_NAME% and %SPLIT_OUTPUT_FILE2_NAME%"
start /B /WAIT %TOOL1_SPLIT_FILE_TOOL% %SPLIT_ADDR_HEADER_SIZE% %SPLIT_INPUT_FILE_NAME% %SPLIT_OUTPUT_FILE1_NAME% %SPLIT_OUTPUT_FILE2_NAME%
echo "split end"


::2. partially compress image
echo "*********************** 2 partially compress image *******************************"
echo "partially compress image"
if "%TOOL2_COMPRESS_TOOL_NAME%"=="asr_lzop.exe" (
    start /B /WAIT %TOOL2_COMPRESS_TOOL_NAME% -9fv -o %COMPRESS_OUTPUT_FILE_NAME% %COMPRESS_INPUT_FILE_NAME%
)  else (
    start /B /WAIT %TOOL2_COMPRESS_TOOL_NAME% e %COMPRESS_INPUT_FILE_NAME% %COMPRESS_OUTPUT_FILE_NAME%
) 
del %COMPRESS_INPUT_FILE_NAME%  
echo "partially compress image end"


::3. MERGE FILE
echo "*********************** 3. MERGE FILE*********************************************"
echo "start merge file"
start /B /WAIT %TOOL3_MERGE_FILE% %MERGE_INPUT_FILE1_NAME% %MERGE_INPUT_FILE2_NAME% %MERGE_OUTPUT_FILE_NAME%
echo "merge end"

::4. output target file
rename %MERGE_OUTPUT_FILE_NAME% %SCRIPT_OUTPUT_FILE_NAME%










































