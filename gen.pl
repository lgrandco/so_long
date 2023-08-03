#!/usr/bin/perl
use warnings;
use strict;
die "program x y (max is 120x67 for fullHD screen) wall_density( y/5 recommanded ) item_density ( y/10 recommanded )" unless (scalar(@ARGV) == 4);
my ($x, $y, $wall_density, $item_density) = @ARGV;
# print "$y.ox\n";
for (my $i = 0; $i < $x; $i++){
    print "1";
}
print "\n";
my @exit_=(int(rand($x-2) + 1),int(rand($y-2) + 1));
my @start=(int(rand($x-2) + 1),int(rand($y-2) + 1));
while ($start[0]==$exit_[0]){
    @start=(int(rand($x-2) + 1),int(rand($y-2) + 1));
}
for (my $i = 1; $i < $y-1; $i++) {
    print "1";
    for (my $j = 1; $j < $x-1; $j++) {
        if ($exit_[0]==$j and $exit_[1]==$i){
            print "E";
        }
        elsif ($start[0]==$j and $start[1]==$i){
            print "P";
        }
        elsif (int(rand($y) * 2) < $wall_density) {
            print "1";
        }
        elsif (int(rand($y) * 2) < $item_density){
            print "C";
        }
        else {
            print "0";
        }
    }
    print "1\n";
}
for (my $i = 0; $i < $x; $i++){
    print "1";
}
print "\n";
