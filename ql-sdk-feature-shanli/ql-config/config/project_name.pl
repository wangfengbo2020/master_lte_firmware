
use Cwd;

$CURDIR = getcwd();
$CURDIR =~ s/\//\\/g;
my $project_name = uc $ARGV[0]; #所有小写转大写
my $EXT_FLASH = uc $ARGV[1];
my $APP_MODE = uc $ARGV[2];
my $cust_ver =  uc $ARGV[3];
my $OEM_cfg = uc $ARGV[4];
my $QuecVerfilePath = "$CURDIR\\..\\..\\ql-kernel\\threadx\\common\\include\\quectel_version.h";
my $CustVerfilePath = "$CURDIR\\..\\..\\ql-kernel\\threadx\\common\\include\\ql_cust_version.h";
my $cp_prjname_file = "$CURDIR\\..\\..\\ql-kernel\\threadx\\common\\include\\QuecPrjName.h";
my $app_prjname_file = "$CURDIR\\..\\..\\ql-application\\threadx\\common\\include\\QuecPrjName.h";
my $QUEC_CUR_PRJ_file = "$CURDIR\\..\\..\\ql-config\\config\\QuecCurPrj.txt";
my $QUEC_FLASH_Type_file = "$CURDIR\\..\\..\\ql-config\\config\\QuecFLashType.ini";
my $firmware_name_filepath = "$CURDIR\\..\\..\\ql-config\\quec-project\\scripts\\win32\\build_package.bat";
my $ram_size_file = "$CURDIR\\..\\..\\ql-kernel\\threadx\\config\\ram\\RAM_SIZE.ini";
my $flash_size_file = "$CURDIR\\..\\..\\ql-config\\config\\FLASH_SIZE.ini";
my $ext_flash_size_file = "$CURDIR\\..\\..\\ql-config\\config\\EXT_FLASH.ini";
my $APP_MODE_file = "$CURDIR\\..\\..\\ql-config\\config\\APP_MODE.ini";

#Get Ver
print "\n================PROJECT_INFO================\n";
print "project_name:".$project_name."\n";
print "cust_ver:".$cust_ver."\n";
print "extflash:".$EXT_FLASH."\n";
print "APP_MODE:".$APP_MODE."\n";
print "OEM_cfg:".$OEM_cfg."\n";
print "==============================================\n";

my $prjname_exit = 0;
my $PRJ_CUR = 0;
my $Ram_Size = "4M";
my $Flash_Size = "4M";
my $flash_type = "DEFAULT";

if($project_name =~ /EC200MCN_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC200MCN_LE/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC600MCN_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC600MCN_LE/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC800MCN_LE/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC600MEU_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC600MLA_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC600MCN_LC/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
     $Flash_Size = "4M";
}
elsif($project_name =~ /EC800MCN_LC/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $Flash_Size = "4M";
}
elsif($project_name =~ /EC800MCN_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EG810MCN_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EG810MEU_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC800MCN_GA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $flash_type = "HX_GPS";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC800MCN_GB/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $flash_type = "HX_GPS";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EG810MCN_GA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $flash_type = "HX_GPS";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EG810MCN_GB/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $flash_type = "HX_GPS";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC800MCN_GD/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $flash_type = "HX_GPS";
    $Flash_Size = "8M";
}
elsif($project_name =~ /EC800MCN_GC/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $flash_type = "HX_GPS";
    $Flash_Size = "4M";
}
elsif($project_name =~ /EC800MCN_GM/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $flash_type = "HX_GPS";
     $Flash_Size = "4M";
}
elsif($project_name =~ /EC200MCN_LC/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
     $Flash_Size = "4M";
}
elsif($project_name =~ /EC600MCN_LF/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $Flash_Size = "4M";
}
elsif($project_name =~ /EC800MCN_LF/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $Flash_Size = "4M";
}
elsif($project_name =~ /EC600MCN_CC/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "4M";
    $Flash_Size = "2M";
}
elsif($project_name =~ /EC200MCN_GB/)
{
	$prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
    $flash_type = "ASR_GPS_BT";
}
elsif($project_name =~ /EC100MCN_LA/)
{
    $prjname_exit = 1;
    $PRJ_CUR = $&;
    $Ram_Size = "8M";
    $Flash_Size = "8M";
}
else
{
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n     You must enter a project name [Not Support $project_name]    \n";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************";
	print "\n********************          ERROR          ***********************\n";
	unlink("$QUEC_CUR_PRJ_file");
    $prjname_exit = 0;
    exit -1;
}

if($project_name =~ /BT/)
{
	$flash_type .= "_BT";
}
if($EXT_FLASH =~ /EXT_FLASH_M02/)
{
	open(ext_flash_fd,">$ext_flash_size_file");
	print ext_flash_fd "2M";
	close ext_flash_fd;
	print "ext flash 2m \n";
}elsif($EXT_FLASH =~ /EXT_FLASH_M01/)
{
	open(ext_flash_fd,">$ext_flash_size_file");
	print ext_flash_fd "1M";
	close ext_flash_fd;
	print "ext flash 1m \n";
}elsif($EXT_FLASH =~ /EXT_FLASH_M16/)
{
	open(ext_flash_fd,">$ext_flash_size_file");
	print ext_flash_fd "16M";
	close ext_flash_fd;
	print "ext flash 16m \n";
}elsif($EXT_FLASH =~ /EXT_FLASH_M08/)
{
	open(ext_flash_fd,">$ext_flash_size_file");
	print ext_flash_fd "8M";
	close ext_flash_fd;
	print "ext flash 8m \n";
}elsif($EXT_FLASH =~ /NO_EXTFLASH/){
	open(ext_flash_fd,">$ext_flash_size_file");
	print ext_flash_fd "NO_EXTFLASH";
	close ext_flash_fd;
	print "ext flash 0m \n";
}
if($APP_MODE =~ /XIP/)
{
	open(app_mode_fd,">$APP_MODE_file");
	print app_mode_fd "XIP";
	close app_mode_fd;
	print "XIP APP \n";
}elsif($APP_MODE =~ /RAM/)
{
	open(app_mode_fd,">$APP_MODE_file");
	print app_mode_fd "RAM";
	close app_mode_fd;
	print "RAM APP \n";
}
print "\n*****************PRJ_CUR=$PRJ_CUR****flash_type=$flash_type***********************\n";
my $PRJ_DEF = "#define __QUECTEL_PROJECT_".$PRJ_CUR."__";

my $Ver_OEM_Def = ""; 
if($OEM_cfg ne 0)
{
	if ($OEM_cfg ne "")
	{
		print "\n=================================$OEM_cfg============================\n";
		$Ver_OEM_Def = "#define __QUEC_OEM_VER_".$OEM_cfg."__";
	}
}

if($prjname_exit==1)
{
    open(PrjDefFile,">$cp_prjname_file");
    print PrjDefFile "/************************* This file is modify automaticly, please don't edit it! ***************************/\n\n";
    print PrjDefFile "#ifndef __PRJ_DEF_FILE__\n";
    print PrjDefFile "#define __PRJ_DEF_FILE__\n\n";
    print PrjDefFile "$PRJ_DEF\n\n";
		print PrjDefFile "$OemProjDef\n\n";
    print PrjDefFile "$Ver_OEM_Def\n\n";
	if($OEM_cfg ne 0)
	{
		print PrjDefFile "#define MOB_SW_OEM \"$OEM_cfg\"\n\n";
	}
	else 
	{
		print PrjDefFile "#define MOB_SW_OEM \"\"\n\n";
	}
    print PrjDefFile "#endif\n";

    print "\n==========================Build Project ".$PRJ_CUR."==============================\n\n";
    open(PrjName,">$QUEC_CUR_PRJ_file");
    print PrjName "$PRJ_CUR";
    close(PrjName);
    close(PrjDefFile);
    system("copy /Y \"$cp_prjname_file\" \"$app_prjname_file\"");
    
   	open(FD,">$ram_size_file");
   	print FD $Ram_Size;
    close(FD);

    open(FD,">$flash_size_file");
   	print FD $Flash_Size;
    close(FD);
    
    open(FD,"<$QuecVerfilePath"); #spm jerry 闇�姹傚鏋滃彂鐗堜负BT鐗堟湰閭ｇ紪璇戜换浣昽c閮戒細鎵撳寘bt鍥轰欢 pony add 2023 08 22
    read FD, $read_flash_type, 300; 

 if ($read_flash_type =~ /BT/) {
    if ($flash_type !~ /_BT$/) {
        $flash_type = $flash_type . "_BT";
    }
    }   
    close(FD);
    open(FD,">$QUEC_FLASH_Type_file");
   	print FD $flash_type;
    close(FD);
}

if($cust_ver ne 0)
{
	if($cust_ver ne "")
	{
		open(CustVerFile,">$CustVerfilePath");
		print CustVerFile "/************************* This file is cust_version by modifying in perl script ***************************/\n\n";
		print CustVerFile "#ifndef __QL_CUST_VERSION_H__\n";
		print CustVerFile "#define __QL_CUST_VERSION_H__\n\n";
		print CustVerFile "char mob_cust_rev[100] =\"$cust_ver\";\n";
		print CustVerFile "#endif\n";
		close(CustVerFile);
	}
}
my $firmware_name = "";
open(CustVerFile,"<$CustVerfilePath");
while(<CustVerFile>)
{
    chomp;
    if($_=~ /mob_cust_rev/)
    {
        $_ =~ s/\s||;||\"//g;
        $_ =~ /\/\//;
        $_ =~ s/$'//;
        $_ =~ s/\/\///;
        $_ =~ s/charmob_cust_rev\[100\]\=//;
        if($_ ne "")
        { 
            print "\n==========cust_version :$_============\n" ;
            $firmware_name = $_;
        }
        else
        {
            print "cust_version not exist We will use the default version number";
            open (quecverFile ,"<$QuecVerfilePath");
            while(<quecverFile>)
            {
                chomp;
                if($_=~ /mob_sw_rev/)
                {
                    $_ =~ s/\s||;||\"//g;
                    $_ =~ s/charmob_sw_rev\[\]\=//;
                    $firmware_name = $_;
                    print "\n===============firmware_name:$firmware_name=============\n";
                    last;
                }
                
            }
            close(quecverFile);
        }
       last;
    }
}
close(CustVerFile);

if(-e $QuecVerfilePath)
{
 	open(FILE,"<",$QuecVerfilePath)||die"cannot open the file: $!\n";
 	@linelist=<FILE>;
   	my $t=0;
    foreach $eachline(@linelist){
        if($eachline=~/\Achar\smob_model_id\[\]\s=/)
        { 
            last;
        }
        $t=$t+1;  

    }
    close FILE;
    $linelist[$t]="char mob_model_id[] = \"$PRJ_CUR\"\;"."\r\n";
    open(FILE,">",$QuecVerfilePath)||die"cannot open the file: $!\n";
    print FILE @linelist;
    close FILE;
}
else
{
   	print "\n********************          ERROR          ***********************";
	print "\n                We didn't find any packaging scripts               \n";
	print "\n********************          ERROR          ***********************\n"; 
}

if(-e $firmware_name_filepath)
{
    @ARGV = "$firmware_name_filepath";
    local $^I='.bak';
    while (<>) {
            s/\Aset buildver=.*/set buildver=$firmware_name/;
            print;
    }
}
else
{
   	print "\n********************          ERROR          ***********************";
	print "\n                We didn't find any packaging scripts               \n";
	print "\n********************          ERROR          ***********************\n"; 
}

	

