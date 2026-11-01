#!/usr/bin/perl
#
#[20220803][xiaokeweng@asrmicro.com]
# COMM: implement a perl script to do ICAT Command filter
# usage:
#       {SCRIPT}.pl <white_list_file> [*.pp]...
#
#
use Fcntl;
use File::Copy;
use File::Basename;

$DEBUG=0;

$SCRIPT_VERSION=20220803;
$SCRIPT_TAG="ICAT_CMD_FILTER";

$PARTTERN_STRING="\/\/ICAT\ EXPORTED\ FUNCTION";
$PARTTERN_MASK="_FILTER_DUMMY";
$PARTTERN_TAIL=" - ";

debug_msg("ARGV = @ARGV");
$WHITE_LIST_FILE=shift(@ARGV);
$OUTPUT_FOLDER=shift(@ARGV);

my @Whitelist_array = ();
my @copy_pp_file_list = ();

print sprintf (">%-15s--%-20s<\n","---------------","--------------------");
print sprintf ("[%-15s][%-20s] %s\n","$SCRIPT_TAG","VERSION",$SCRIPT_VERSION);
print sprintf ("[%-15s][%-20s] %s\n","$SCRIPT_TAG","WHITE_LIST",$WHITE_LIST_FILE);
print sprintf ("[%-15s][%-20s] %s\n","$SCRIPT_TAG","OUTPUT_FOLDER",$OUTPUT_FOLDER);

###########################
#
# STEP 0: load white list file
#
debug_msg("STEP 0++");
open (WL, $WHITE_LIST_FILE) or die "$!, open $WHITE_LIST_FILE\n";
while ( $m_WL = <WL> )
{
	if( $m_WL !~ /^#/ ){
		push @Whitelist_array, $m_WL;
	} else {
		debug_msg("comment item $m_WL");
	}
}
close WL;
debug_msg("Whitelist_array=@Whitelist_array");
debug_msg("STEP 0--");

print sprintf (">%-15s--%-20s<\n","---------------","--------------------");


###########################
#
# STEP 0: copy all input <.pp> files into $OUTPUT_FOLDER
#
debug_msg("STEP 1++");
print sprintf ("[%-15s][%-20s]\n","$SCRIPT_TAG","COPY_ALL_ICAT_CMD");
print("@ARGV\n");
foreach my $M_PP_FILE (@ARGV)
{
	$M_PP_FILE_basename = basename($M_PP_FILE);
	$M_PP_FILE_copy_dst = "$OUTPUT_FOLDER/$M_PP_FILE_basename";
	debug_msg("$M_PP_FILE ==> $M_PP_FILE_copy_dst");

	copy($M_PP_FILE,$M_PP_FILE_copy_dst);
	push @copy_pp_file_list, "$M_PP_FILE_copy_dst";
}
debug_msg("[copy_pp_file_list] = @copy_pp_file_list");
debug_msg("STEP 1--");

###########################
#
# STEP 2: dummy all command by mask the format string "ICAT EXPORTED FUNCTION"
#
debug_msg("STEP 2++");
print sprintf ("[%-15s][%-20s]\n","$SCRIPT_TAG","MASK_ALL_ICAT_CMD");
print("@copy_pp_file_list\n");
foreach my $M_PP_FILE (@copy_pp_file_list)
{
	debug_msg("dummy $M_PP_FILE");
	system("perl -p -i\".conv1\" -e \"s#$PARTTERN_STRING$PARTTERN_TAIL#$PARTTERN_STRING$PARTTERN_MASK$PARTTERN_TAIL#g\" $M_PP_FILE");
	debug_msg("remove $M_PP_FILE.conv1");
	unlink("$M_PP_FILE.conv1")
}
debug_msg("STEP 2--");
print sprintf (">%-15s--%-20s<\n","---------------","--------------------");

###########################
#
# STEP 3: recover the command list in whitelist
#
# item format:
# CAT1,CAT2,CAT3=GROUP
#
debug_msg("STEP 3++");
debug_msg("[copy_pp_file_list] = @copy_pp_file_list");

while ( $M_WHITE_LIST_COMMAND = <@Whitelist_array> )
{
	debug_msg("M_WHITE_LIST_COMMAND=$M_WHITE_LIST_COMMAND");
	$M_WHITE_LIST_COMMAND_PARTTEN = $M_WHITE_LIST_COMMAND;
	$M_WHITE_LIST_COMMAND_GROUP   = $M_WHITE_LIST_COMMAND;

	timestamp_msg();

	print sprintf ("[%-15s][%-20s] %s\n","$SCRIPT_TAG","ENABLE_ICAT_CMD",$M_WHITE_LIST_COMMAND);
	$M_WHITE_LIST_COMMAND_PARTTEN =~ s#\=.*##g;
	$M_WHITE_LIST_COMMAND_PARTTEN =~ s#,# , #g;
	debug_msg("M_WHITE_LIST_COMMAND_PARTTEN=$M_WHITE_LIST_COMMAND_PARTTEN");

	$M_WHITE_LIST_COMMAND_GROUP =~ s#.*\=##g;
	debug_msg("M_WHITE_LIST_COMMAND_GROUP=$M_WHITE_LIST_COMMAND_GROUP");

	@group_pp_file_list = grep(/$M_WHITE_LIST_COMMAND_GROUP/, @copy_pp_file_list);
	debug_msg("[group_pp_file_list] = @group_pp_file_list");

	if( @group_pp_file_list ){
		system("perl -p -i\".conv2\" -e \"s#$PARTTERN_MASK$PARTTERN_TAIL$M_WHITE_LIST_COMMAND_PARTTEN#$PARTTERN_TAIL$M_WHITE_LIST_COMMAND_PARTTEN#g\" @group_pp_file_list");
	}
}

foreach my $M_PP_FILE (@copy_pp_file_list)
{
	debug_msg("remove $M_PP_FILE.conv2");
	unlink("$M_PP_FILE.conv2")
}
debug_msg("STEP 3--");
print sprintf (">%-15s--%-20s<\n","---------------","--------------------");

###########################
#
# common functions
#
sub debug_msg{
	unless($DEBUG){return};
	local $DEBUG_MSG="DEBUG >>> :";
	timestamp_msg();
	print "$DEBUG_MSG @_";
	print "\n";
}

sub timestamp_msg{
	($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime();
	printf ("[%04d%02d%02d%02d%02d%02d] ",$year+1900,$mon+1,$mday,$hour,$min,$sec);
}
