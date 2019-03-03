#include "malloc.h"

int				main(void)
{
	malloc(NULL);
	malloc(0);
	malloc(1);
	malloc(8);
	malloc(15);
	malloc(16);
	malloc(17);
	malloc(31);
	malloc(INT_MAX);
	malloc(UINT_MAX);
	show_alloc_mem();
	return (0);
}
