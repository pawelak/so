#!/bin/bash

find $1 -type d | wc -l
find $1 -name '*.sh' -o -name '*.pl' | wc -l
find $1 -name '*.[ch]' | wc -l
find $1 -iname '[a-z][a-z]' | wc -l
find $1 -wholename '*/src/*' | wc -l
find $1 ! -iname '[b]*' | wc -l
find $1 -mtime -15 | wc -l
find $1 -name '*.c' -a -size +100k | wc -l
find $1 -executable | wc -l
find $1 -perm -664 | wc -l


find $1 -type f | rev | grep '\.' | cut -d '.' -f 1 | rev | sort | uniq -c | sort -nr

