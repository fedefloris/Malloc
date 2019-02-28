#include "malloc.h"

# define SIZE 5

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
		// ft_printf("Before free()\n");
		// show_alloc_mem();
		free(test[i]);
		ft_printf("After free()\n");
		show_alloc_mem();
		i++;
	}
	ft_printf("End...\n");
	show_alloc_mem();
	return (0);
}
