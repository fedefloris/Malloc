#include "malloc.h"

typedef struct	s_test
{
	size_t		a;
	size_t		b;
	size_t		c;
}				t_test;

int	main(void)
{
	t_test		*test;

	if (!(test = (t_test*)malloc(sizeof(t_test))))
		ft_printf("malloc() call failed");
	test->a = 2;
	test->b = 9201230;
	test->c = 1900123123;
	ft_printf("Test values: a = %zd, b = %zd, c = %zd\n",
		test->a, test->b, test->c);
	free(test);
	ft_printf("test after free() call, %p\n", test);
	return (0);
}
