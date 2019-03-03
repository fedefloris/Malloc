#include "malloc.h"

int				main(void)
{
	free(NULL);
	free(0);
	free(malloc(NULL));
	free(malloc(0));
	free(malloc(1));
	free(malloc(8));
	free(malloc(15));
	free(malloc(16));
	free(malloc(17));
	free(malloc(31));
	free(malloc(INT_MAX));
	free(malloc(UINT_MAX));
	show_alloc_mem();
	return (0);
}
