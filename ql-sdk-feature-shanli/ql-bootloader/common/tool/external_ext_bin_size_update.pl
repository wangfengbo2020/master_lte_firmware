#!/usr/bin/perl
#
#[20210225][xiaokeweng@asrmicro.com]
# COMM: update ext info BIN_SIZE update for Ext combined image
#
#      ---------------------------------- 
#      | Updater (with Ext info)        |
#      |--------------------------------|
#      | dsp_adc.bin                    |
#      |--------------------------------|
#      | crc                            |
#      |--------------------------------|
#

use Fcntl;

$DEBUG=1;
$LOADTABLE_HEADER_LENGTH=0x1200;
$IMG_FILENAME = $ARGV[0];
$BINARY_SIZE_STRING= $ARGV[1];

my $binary_size= -s $IMG_FILENAME;
sysopen(INPUT_STREAM,"$IMG_FILENAME",O_BINARY|O_RDWR)
	or error_exit("Can't open [$IMG_FILENAME] for reading; $!");

#print sprintf ("binary_size=[0x%.08x]\n", $binary_size);
sysread(INPUT_STREAM,$loadtable_header,$LOADTABLE_HEADER_LENGTH);
$index=index($loadtable_header,$BINARY_SIZE_STRING);
if ($index == -1){
	error_exit("NO BINARY_SIZE_STRING [$BINARY_SIZE_STRING] detect, exit");
}

sysseek(INPUT_STREAM,$index,0);
sysread(INPUT_STREAM,$ITEM_NAME,12);
sysseek(INPUT_STREAM,$index+12,0);
sysread(INPUT_STREAM,$original_val,4);

#print sprintf ("original_val =[0x%.08x  ]\r\n",raw_to_hex($original_val));

#   typedef struct{
#       char    name[12];
#       UINT32  value;
#   }armlink_symbol_item;
#
#
sysseek(INPUT_STREAM,$index+12,0);
$tmp_raw = hex_32_reorder($binary_size);
syswrite(INPUT_STREAM,pack("H*",sprintf("%08x",$tmp_raw)),4);

sysseek(INPUT_STREAM,$index+12,0);
sysread(INPUT_STREAM,$filled_in_val,4);
#print sprintf ("filledin_val =[0x%.08x  ]\r\n",raw_to_hex($filled_in_val));

print sprintf ("[%12s]=[0x%.08x  ] -> [0x%.08x  ]\r\n",
	$ITEM_NAME,raw_to_hex($original_val),raw_to_hex($filled_in_val));

close INPUT_STREAM;

# functions
#
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
	exit(1);
}
