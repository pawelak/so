#!/usr/bin/perl

use strict;
use warnings;

my $file = $ARGV[0];
open my $info, $file or die "nie!";
my $count = 1;
while( my $line = <$info>)
{
	print "$count $line";
	$count *= 2;
	if($count == 1) { $count = 2; }
}






