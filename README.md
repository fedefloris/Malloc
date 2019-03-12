# Malloc - 42Born2Code
[![Build Status](https://travis-ci.com/fedefloris/Malloc.svg?branch=master)](https://travis-ci.com/fedefloris/Malloc) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/7b0423c42b984f079c972bf75ca1508a)](https://www.codacy.com?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=fedefloris/Malloc&amp;utm_campaign=Badge_Grade) ![](https://img.shields.io/github/license/fedefloris/Malloc.svg)

## Challenge
A dynamic zone memory allocator based on the buddy system.

For more details look at the [subject](subject.pdf).

## Using the project
```console
git clone --recursive https://github.com/fedefloris/Malloc.git && cd Malloc && make
```
Now you should see **libft_malloc.so** in the root folder.
```console
gcc your_file.c libft_malloc.so -I includes -I libft/includes
```
Example of **your_file.c**:
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
Unless you copy the library into one of the standard directories (e.g., /usr/lib), you need to specify the location of **libft_malloc.so**.

On Linux you can use **LD_LIBRARY_PATH**.
```console
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH
```

## Running the tests
```console
make tests
```
## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
