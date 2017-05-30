#!/bin/bash

ps -elF | cut -d " " -f 3 | sort | uniq -c | sort
