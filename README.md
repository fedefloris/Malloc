# Malloc - 42Born2Code
[![Build Status](https://travis-ci.com/fedefloris/Malloc.svg?branch=master)](https://travis-ci.com/fedefloris/Malloc) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/7b0423c42b984f079c972bf75ca1508a)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=fedefloris/Malloc&amp;utm_campaign=Badge_Grade) ![](https://img.shields.io/github/license/fedefloris/Malloc.svg)

## Challenge
A dynamic zone memory allocator based on the buddy system.

In the buddy system we use blocks that are powers of two, we arrange things so that blocks of size 2^N always begin at memory addresses where the N least significant bits are zero.

For example:
  - blocks of size 2^0 can begin at any address.
  - blocks of size 2^1 can only begin at even addresses.
  - blocks of size 2^2 only begin at addresses with the least significant 2 bits equal to zero.

The constraints on the block addresses in the binary buddy system have an interesting consequence. When a block of size 2n+1 is split into two blocks of size 2n, the addresses of these two blocks will differ in exactly one bit, bit n, using the counting scheme that numbers bits starting with 0 at the least significant end. Thus, given a block of size 2n at address a, we can compute the address of its buddy, the other half of the block from which it was split, by exclusive-oring a with 2n.

For more details look at the [subject](subject.pdf).

## Using the project
```console
git clone --recursive https://github.com/fedefloris/Malloc.git && cd Malloc && make
```
Now you should see `libft_malloc.so` in the root folder.
```console
gcc your_file.c libft_malloc.so -I includes -I libft/includes
```
Example of `your_file.c`:
```c
#include "malloc.h"

int     main(void)
{
  void  *ptr;

  if (!(ptr = malloc(15)))
    ft_printf("malloc call failed\n");
  // ...
  // use ptr
  // ...
  free(ptr);
  return (0);
}
```
Unless you copy the library into one of the standard directories (e.g., /usr/lib), you need to specify the location of `libft_malloc.so`.

On Linux you can use `LD_LIBRARY_PATH`.
```console
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH
```

You could also use `LD_PRELOAD` to run programs with `libft_malloc.so` implementations of [malloc()](srcs/allocate/malloc.c), [realloc()](srcs/allocate/realloc.c), [calloc()](srcs/allocate/calloc.c) and [free()](srcs/free/free.c).
```console
LD_PRELOAD=./libft_malloc.so ls
```
## Running the tests
```console
make tests
```
## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
