#!/usr/bin/perl
#
##[20210225][xiaokeweng@asrmicro.com]
#
#      ---------------------------------- 
#      | Updater (with Ext info)        |
#      |--------------------------------|
#      | dsp_adc.bin                    |
#      |--------------------------------|
#      | crc                            |
#      |--------------------------------|
#
# to append {dsp_adc.bin} to {updater.bin}
# and ADC_SIZE into {Ext info}
#
# cmd should be :
#
# perl {this_script*.pl} APPEND UPD_SIZE updater.bin ADC_SIZE dsp_adc.bin
#


use Fcntl;
#use Switch;

$DEBUG=1;
$OPERATION_ARGV       =glob $ARGV[0]; #{"APPEND"}
$FRONT_IMG_FILENAME   =glob $ARGV[1]; #front bin
$FRONT_SIZE_STRING    =glob $ARGV[2]; #front bin ext info string
$APPEND_IMG_FILENAME  =glob $ARGV[3]; #append bin
$APPEND_SIZE_STRING   =glob $ARGV[4]; #append bin ext info string

# NULL = 0x4c4c554e;
$LT_INVALID_ADDRESS="NULL";
$LOADTABLE_HEADER_LENGTH=0x1200;

$PART_1 = "pi_front";
$PART_2 = "pi_tail";
$PART_TMP = "pi_tmp";

debug_msg("ARGV[0]:$OPERATION_ARGV");
debug_msg("ARGV[1]:$FRONT_IMG_FILENAME");
debug_msg("ARGV[2]:$FRONT_SIZE_STRING");
debug_msg("ARGV[3]:$APPEND_IMG_FILENAME");
debug_msg("ARGV[4]:$APPEND_SIZE_STRING");
print sprintf ("|%s\n","-------------------------------------------------------------------------------");

#
#step-0 : input argv verification
#
debug_msg("STEP_0");
	sysopen(INPUT_STREAM,"$APPEND_IMG_FILENAME",O_BINARY|O_RDONLY)
		or error_exit("Can't open [$APPEND_IMG_FILENAME] for reading; $!");
	close INPUT_STREAM;
	sysopen(INPUT_STREAM,"$FRONT_IMG_FILENAME",O_BINARY|O_RDWR)
		or error_exit("Can't open [$FRONT_IMG_FILENAME] for reading; $!");

#
#step-1 : count input {$FRONT_IMG_FILENAME} size to do further compare with val of item $("BIN_SIZE")
#
debug_msg("STEP_1");
my $input_front_bin_size= -s $FRONT_IMG_FILENAME;
if($DEBUG){print sprintf ("input_front_bin_size=[0x%.08x]\n", $input_front_bin_size)};

#
#step-2 : detect item {"BIN_SIZE"} and verify if val available as [$lt_front_bin_size]
#
#load the first {$LOADTABLE_HEADER_LENGTH} binary to parse
#
#/csw/BSP/inc/loadTable.h
#   typedef struct{
#       char    name[12];
#       UINT32  value;
#   }armlink_symbol_item;
#
debug_msg("STEP_2");
sysread(INPUT_STREAM,$loadtable_header,$LOADTABLE_HEADER_LENGTH);

#index of "BIN_SIZE"
$index=index($loadtable_header,$FRONT_SIZE_STRING);
if ($index == -1){
	error_exit("NO [$FRONT_SIZE_STRING] detect, exit");
}

#read val of "BIN_SIZE" and do compare check
sysseek(INPUT_STREAM,$index+12,0);
sysread(INPUT_STREAM,$lt_front_bin_size,4);
$lt_front_bin_size=raw_to_hex($lt_front_bin_size);
if($DEBUG){print sprintf ("lt_front_bin_size=[0x%.08x]\r\n",$lt_front_bin_size)};

if($OPERATION_ARGV =~ /APPEND/i){
	if ( $lt_front_bin_size != $input_front_bin_size){
		error_exit("item [$FRONT_SIZE_STRING] unmatch with [$FRONT_IMG_FILENAME] size, exit");
	}
}

#
#step-3 : count input {$APPEND_IMG_FILENAME} size , going to fill in item {"APPEND_SIZE_STRING"}
#
debug_msg("STEP_3");
$input_append_bin_size= -s $APPEND_IMG_FILENAME;
if($DEBUG){print sprintf ("input_append_binary_size=[0x%.08x]\n", $input_append_bin_size)};

$index=index($loadtable_header,$APPEND_SIZE_STRING);
if ($index == -1){
	error_exit("NO [$APPEND_SIZE_STRING] detect, exit");
}

#
#step-4 do raw RW action
#
debug_msg("STEP_4");
if($OPERATION_ARGV =~ /APPEND/i){
		sysseek(INPUT_STREAM,$index+12,0);
		sysread(INPUT_STREAM,$tmp_size,4);
		if($tmp_size !~ /$LT_INVALID_ADDRESS/){
			error_exit("item [$APPEND_SIZE_STRING][$tmp_size] is not NULL");
		}
		sysseek(INPUT_STREAM,$index+12,0);
		$tmp_size = hex_32_reorder($input_append_bin_size);
		syswrite(INPUT_STREAM,pack("H*",sprintf("%08x",$tmp_size)),4);
		close INPUT_STREAM;

		#step-4 : do binary file append action
		file_append($FRONT_IMG_FILENAME,$APPEND_IMG_FILENAME);


print sprintf ("|%-53s|  0x%0.8x = %6.3f(KB)\n",$FRONT_IMG_FILENAME
	,$input_front_bin_size,$input_front_bin_size/1024);

print sprintf ("|%s\n","            +                                                                   ");
print sprintf ("|%-53s|  0x%0.8x = %6.3f(KB)\n",$APPEND_IMG_FILENAME
	,$input_append_bin_size,$input_append_bin_size/1024);

#print sprintf ("|%s|\n","-------------------------------------------------------------------------------");
print sprintf ("|%s\n","            =                                                                   ");
print sprintf ("|%-53s|  0x%0.8x = %6.3f(KB)\n",$FRONT_IMG_FILENAME,
	($input_front_bin_size+$input_append_bin_size),($input_front_bin_size+$input_append_bin_size)/1024);
}

#
#step-5 printf handle success result info
#
	print sprintf ("|%s\n","-------------------------------------------------------------------------------");


#
# common functions
#
sub debug_msg{
	unless($DEBUG){return};
	local $DEBUG_MSG="DEBUG >>> :";
	print "$DEBUG_MSG @_";
	print "\n";
}

sub hex_32_reorder{
   local $m_hex = $_[0];
   $m_hex = ((($m_hex&0x000000ff)<<24)|
		(($m_hex&0x0000ff00)<<8)|
		(($m_hex&0x00ff0000)>>8)|
		(($m_hex&0xff000000)>>24));
   return $m_hex;
}

sub raw_to_hex{
   local $m_hex = hex(unpack("H*",$_[0]));
   $m_hex = hex_32_reorder($m_hex);
   return $m_hex;
}

sub error_exit{
	local $ERROR_MSG="\nERROR:**";
	print "----------------------";
	print "$ERROR_MSG @_";
	print "\n";
	print "****************************************************************\n";
	print("$OPERATION_ARGV ERROR!\n");
	print "****************************************************************\n";	
	print sprintf ("|%s|\n","-------------------------------------------------------------------------------");
	exit(1);
}

sub file_append{
	open(RH,$_[1]) or die "$!";
	binmode RH;
	my @src_1=<RH>;
	close RH;
	open(WH,">>$_[0]") or die "$!";
	binmode WH;
	my $i;
	for($i = 0; $i < @src_1; $i++){
		print WH $src_1[$i];
	}
	close WH;
}

sub file_merge{
	open(RH,$_[0]) or die "$!";
	binmode RH;
	my @src_1=<RH>;
	close RH;

	open(RH,$_[1]) or die "$!";
	binmode RH;
	my @src_2=<RH>;
	close RH;

	#create&overwrite for input file arg0
	open(WH,">$_[2]") or die "$!";
	binmode WH;
	my $i;
	for($i = 0; $i < @src_1; $i++){
		print WH $src_1[$i];
	}
	close WH;

	#append for input file arg1
	open(WH,">>$_[2]") or die "$!";
	binmode WH;
	my $i;
	for($i = 0; $i < @src_2; $i++){
		print WH $src_2[$i];
	}
	close WH;

}
