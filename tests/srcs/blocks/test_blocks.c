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

void		test_blocks(size_t block_size, size_t tests_count)
{
	void	*ptr;

	while (tests_count--)
	{
		if (!(ptr = malloc(block_size)))
			error_exit("malloc returned a null pointer");
		free(ptr);
		test_block(ptr, block_size, Allocated);
		test_block(ptr, block_size, Free);
	}
}
