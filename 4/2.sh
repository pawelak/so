#!/bin/bash

cat $1 | nl | head --line=30 | tail --lines=11
