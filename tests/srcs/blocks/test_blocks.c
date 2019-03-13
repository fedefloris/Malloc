/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

static void		*test_malloc(size_t block_size)
{
	char		*ptr;

	if (!(ptr = (char*)malloc(block_size)))
		error_exit("malloc returned a null pointer");
	ft_memset(ptr, 42, block_size);
	test_allocated_block(ptr, block_size);
	return (ptr);
}

static void		test_malloc_realloc_free(size_t block_size)
{
	char		*ptr;

	ptr = test_malloc(block_size);
	if (!(ptr = (char*)realloc(ptr, block_size * 2))
		&& block_size * 2 != 0)
		error_exit("realloc returned a null pointer");
	if (block_size * 2 != 0)
	{
		ft_memset(ptr, 42, block_size);
		test_allocated_block(ptr, block_size * 2);
	}
	free(ptr);
}

static void		test_realloc_free(size_t block_size)
{
	char		*ptr;

	if (!(ptr = (char*)realloc(NULL, block_size)) && block_size)
		error_exit("realloc returned a null pointer");
	if (block_size)
	{
		ft_memset(ptr, 42, block_size);
		test_allocated_block(ptr, block_size);
	}
	free(ptr);
	ptr = realloc(test_malloc(block_size), 0);
}

static void		test_malloc_free(size_t block_size)
{
	free(test_malloc(block_size));
}

void			test_blocks(size_t block_size, size_t tests_count)
{
	while (tests_count--)
	{
		test_malloc_free(block_size);
		test_realloc_free(block_size);
		test_malloc_realloc_free(block_size);
	}
}
