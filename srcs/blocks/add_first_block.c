/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		add_block(t_block **blocks, char *memory, int size_log2)
{
	t_block		*block;

	block = blocks[size_log2];
	blocks[size_log2] = (t_block*)memory;
	blocks[size_log2]->size_log2 = size_log2;
	blocks[size_log2]->next = block;
}

void			add_first_block(t_zone *zone, int zone_type)
{
	char		*zone_memory;
	size_t		zone_size;

	zone_memory = (char*)zone;
	if (zone_type == TINY_ZONE_SIZE)
	{
		zone_size = zone->size - TINY_ZONE_HEADER_SIZE;
		zone_memory += TINY_ZONE_HEADER_SIZE;
		while (zone_size >= TINY_THRESHOLD)
		{
			add_block((t_block**)(zone + 1), zone_memory, TINY_MAX_LOG2);
			zone_memory += TINY_THRESHOLD;
			zone_size -= TINY_THRESHOLD;
		}
	}
	else
	{
		zone_size = zone->size - SMALL_ZONE_HEADER_SIZE;
		zone_memory += SMALL_ZONE_HEADER_SIZE;
		while (zone_size > SMALL_THRESHOLD)
		{
			add_block((t_block**)(zone + 1), zone_memory, SMALL_MAX_LOG2);
			zone_memory += SMALL_THRESHOLD;
			zone_size -= SMALL_THRESHOLD;
		}
	}
}
