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

static void		test_blocks(size_t block_size, size_t tests_count)
{
	void		*ptr;

	while (tests_count--)
	{
		if (!(ptr = malloc(block_size)))
			error_exit("malloc returned null");
		test_block(ptr, block_size, Allocated);
	}
}

void			test_malloc(void)
{
	test_blocks(1, 1000);
	test_blocks(TINY_THRESHOLD - sizeof(t_block), 1000);
	test_blocks(SMALL_THRESHOLD - sizeof(t_block), 1000);
	test_blocks(TINY_THRESHOLD, 1000);
	test_blocks(SMALL_THRESHOLD, 1000);
	test_blocks(LARGE_THRESHOLD, 1000);
}
