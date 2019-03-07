#!/usr/bin/env sh

set env DYLD_INSERT_LIBRARIES ./libft_malloc.so

echo "Testing ls"
LD_PRELOAD=./libft_malloc.so ls
LD_PRELOAD=./libft_malloc.so ls -Rlh
LD_PRELOAD=./libft_malloc.so ls /

echo "Testing find"
LD_PRELOAD=./libft_malloc.so find .
