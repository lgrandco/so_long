#!/bin/sh
if [ "$#" -ne 4 ]; then
    echo "program x y (max is 120x67 for fullHD screen) wall_density( y/5 recommanded ) item_density ( y/10 recommanded )"
    exit 1
fi
./gen.pl $@ > maps/usr_generated_map.ber
make; ./so_long maps/usr_generated_map.ber
