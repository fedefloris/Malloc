#include "malloc.h"

# define SIZE 10

typedef struct	s_test
{
	char		a;
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
		test[i]->a = 'a';
		// free(test[i]);
		i++;
	}
	show_alloc_mem();
	return (0);
}
