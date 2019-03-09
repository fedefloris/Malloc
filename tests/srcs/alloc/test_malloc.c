/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

# define COUNT 250

void		test_malloc(void)
{
	char	*mem[COUNT];
	int		count;

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
}
