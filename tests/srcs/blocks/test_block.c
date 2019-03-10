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

static bool		is_block_in_bucket(t_block *block, t_zone *zone,
	int zone_type)
{
	(void)block;
	(void)zone;
	(void)zone_type;
	return (false);
}

void			test_block(void *ptr, size_t size, t_block_status status)
{
	int			zone_type;
	t_zone		*zone;
	t_block		*block;

	if (!(block = get_block_info(ptr, &zone, &zone_type)))
		error_exit("ptr is an invalid pointer");
	if ((size_t)BLOCK_SIZE(block->size_log2) <= size)
		error_exit("bad value of block->size_log2");
	if (status == Allocated && block->next)
		error_exit("block->next of allocated block is not null");
	if (status == Allocated && is_block_in_bucket(block, zone, zone_type))
		error_exit("block is both allocated and inside bucket");
}
