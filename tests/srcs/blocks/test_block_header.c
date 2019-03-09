/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_block_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

void			test_block_header(void *ptr, size_t size,
					t_block_status status)
{
	t_block		*block;

	block = (t_block*)ptr - 1;
	if ((size_t)BLOCK_SIZE(block->size_log2) <= size)
		error_exit("bad value of block->size_log2");
	if (status == Allocated && block->next)
		error_exit("block->next of allocated block is not null");
}
