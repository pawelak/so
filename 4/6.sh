#!/bin/bash

find $1 -type f | rev | grep '\.' | cut -d '.' -f 1 | rev | sort | uniq -c | sort -nr

