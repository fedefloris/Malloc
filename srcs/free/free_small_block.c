/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// static void		merge_blocks()

void			free_small_block(t_block **blocks, t_block *block,
	t_zone *zone, int zone_type)
{
	size_t		size_log2;
	size_t		max_log2;
	// t_block		*buddy;

	(void)zone;
	(void)blocks;
	if (!block)
		return ; // invalid pointer for block
	if (zone_type == TINY_ZONE_SIZE)
		max_log2 = TINY_MAX_LOG2;
	else
		max_log2 = SMALL_MAX_LOG2;
	size_log2 = block->size_log2;
	while (size_log2 <= max_log2)
	{
		// buddy = (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
		// 	(char*)block, i - 1);
		// search BUDDY in free list of block->size_log2
		// if BUDDY found merge blocks
		size_log2++;
	}
	// when should I call munmap?
}
