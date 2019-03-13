/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			display_blocks(t_zone *zone, t_zone_type zone_type,
	bool hexdump)
{
	t_block		*block;

	if (IS_TINY_ZONE(zone_type))
		block = (t_block*)((char*)zone + TINY_ZONE_HEADER_SIZE);
	else if (IS_SMALL_ZONE(zone_type))
		block = (t_block*)((char*)zone + SMALL_ZONE_HEADER_SIZE);
	else
		return ;
	while ((char*)block < (char*)zone + zone->size
		&& block->size_log2)
	{
		display_block(block,
			is_block_allocated(block, zone, zone_type),
			hexdump);
		block = (t_block*)((char*)block + BLOCK_SIZE(block->size_log2));
	}
}
