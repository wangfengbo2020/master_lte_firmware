::Note
::MUST excute build_all.bat in DS-5 env. 

::Turn off the echo from this line
@echo off

set DMCHAGE=disable
set LOGO_SUPPORT=enable
set SECBOOT_V2_SUPPORT=disable
set PL_TYPE=CRANEL_SINGLESIM
set DM_FOTA=enable
set FOTA_NO_UPDATER=enable

::create release directory
if not exist release md release

del /s /q /f release\*
::open comment(goto START and goto SUCCESS) to control build specilize boot33*.bin
::goto START
make clean
make feedback
make 
copy /Y boot33.bin release\boot33_craneL_SingleSim_logo.bin
copy /Y boot33.axf release\boot33_craneL_SingleSim_logo.axf
copy /Y boot33.map release\boot33_craneL_SingleSim_logo.map
::check file exist in release?
if not exist release\boot33_craneL_SingleSim_logo.bin goto ERROR
goto SUCCESS

:ERROR
::make clean
echo ****************************************************************
echo ***********************  ERROR  ********************************
echo ****************************************************************
goto END

:SUCCESS
make clean
echo ****************************************************************
echo ***********************  SUCCESS  ******************************
echo ****************************************************************
:END
