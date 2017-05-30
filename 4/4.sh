#!/bin/bash

mi=`whoami`
#echo $mi
ps -elF | grep -w $mi | tr -s ' ' ' ' | cut -d ' ' -f 1-9 #cut -c1-100  albo cut -d "/" -f 1






