#include "malloc.h"

# define SIZE 1000

typedef struct	s_test
{
	char		a[10];
}				t_test;


int				main(void)
{
	t_test		*test[SIZE];
	size_t		i;

	i = 0;
	while (i < SIZE)
	{
		if (!(test[i] = (t_test*)malloc(sizeof(t_test))))
		{
			ft_printf("malloc() call failed");
			break ;
		}
		test[i]->a[2] = 'a';
		free(test[i]);
		i++;
	}
	// show_alloc_mem();
	return (0);
}
