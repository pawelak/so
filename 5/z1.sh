#!/bin/bash

cd $1

echo "zad 1"
grep -ER 'TODO' | wc -l

echo "zad 2"
grep -ER '^\n' | wc -l

echo "zad 3"
grep -ER '.$' | wc -l

echo "zad 4"
grep -ER '\;$' | wc -l

echo "zad 5"
grep -ER '[\{\}]' | wc -l

echo "zad 6"
grep -ER '^[^a-zA-Z]+$' | wc -l

echo "zad 7"
grep -ER '\(\(' | wc -l

echo "zad 8"
grep -ER '0x[0-9a-fA-F]+' | wc -l		 

echo "zad 9"
grep -ER '\.[a-zA-Z]{3}$' | wc -l


echo "zad 10"
grep -ER 'struct ' | wc -l

echo "zad 11"
grep -ER '^void.+\(\)' | wc -l

echo "zad 12"
grep -ER '^void.+\(.+\)' | wc -l #[^ (] - lepiej 

echo "zad 13"
grep -ER '[a-z\.]+\@[a-z\.]+' | wc -l 

echo "zad 14"
grep -hoER ' [a-z]+' | sort | uniq -c | sort -nr 


