#!/bin/bash

cat $1 | while read x y 
do
	echo $((x+y))
done
