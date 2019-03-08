#include "malloc.h"
#include "malloc_test.h"

# define COUNT 250

int				main(void)
{
	char		*mem[COUNT];
	int			count;

	count = 0;
	while (count < COUNT)
	{
		if (!(mem[count] = malloc(450)))
			ft_printf("Fail to allocate\n");
		count++;
	}
	count = 0;
	while (count < COUNT)
	{
		test_block(mem[count], 450, Allocated);
		free(mem[count]);
		count++;
	}
	show_alloc_mem();
	return (0);
}
