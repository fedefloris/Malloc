/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

void			test_block(void *ptr, size_t size, t_block_status status)
{
	int			zone_type;
	t_zone		*zone;
	t_block		*block;

	block = get_block_info(ptr, &zone, &zone_type);
	if (zone_type == LARGE_THRESHOLD)
		return ;
	if (!block)
		error_exit("ptr is an invalid pointer");
	if ((size_t)BLOCK_SIZE(block->size_log2) <= size)
		error_exit("bad value of block->size_log2");
	if (status == Allocated && block->next)
		error_exit("block->next of allocated block is not null");
	if (status == Allocated && is_block_in_bucket(block, zone, zone_type))
		error_exit("block is both allocated and inside bucket");
}
