#!/usr/bin/env bash

set env DYLD_INSERT_LIBRARIES ./libft_malloc.so

# Colors
RED=$(tput setaf 1)
WHITE=$(tput setaf 7)
GREEN=$(tput setaf 2)

#Text styles
BOLD_TEXT=$(tput bold)
NORMAL_TEXT=$(tput sgr0)

# Testing 16-byte alignment
commands=(
    "ls"
    "ls -lRh"
    "ls -l /"
    "find ."
)
for command in "${commands[@]}"; do
    LD_PRELOAD=./libft_malloc.so ${command} 2>&1 > /dev/null
    echo "Testing with ${BOLD_TEXT}${command}${NORMAL_TEXT} ${GREEN}OK${WHITE}"
done
