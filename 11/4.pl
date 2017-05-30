#!/usr/bin/perl

use strict;
use warnings;

my $d = '..';
my $count = 0;
my $t = opendir(DIR,'.');
while(my $file = readdir(DIR)) {
	if(-f $file)
	{
		++$count;
		print $file;
		print "\n";
	}	
}
print "licza plikow: $count";
print "\n";






