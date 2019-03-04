/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_blocks.c                                 :+:      :+:    :+:   */
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

static void		set_thresholds(int zone_type,
	size_t *threshold, int *max_log2)
{
	if (zone_type == TINY_ZONE_SIZE)
	{
		*threshold = TINY_THRESHOLD;
		*max_log2 = TINY_MAX_LOG2;
	}
	else
	{
		*threshold = SMALL_THRESHOLD;
		*max_log2 = SMALL_MAX_LOG2;
	}
}

void			add_first_blocks(t_zone *zone, int zone_type)
{
	char		*zone_memory;
	size_t		zone_size;
	size_t		threshold;
	int			max_log2;

	set_thresholds(zone_type, &threshold, &max_log2);
	if (zone_type == TINY_ZONE_SIZE)
	{
		zone_size = zone->size - TINY_ZONE_HEADER_SIZE;
		zone_memory = (char*)zone + TINY_ZONE_HEADER_SIZE;
	}
	else
	{
		zone_size = zone->size - SMALL_ZONE_HEADER_SIZE;
		zone_memory = (char*)zone + SMALL_ZONE_HEADER_SIZE;
	}
	while (zone_size >= threshold)
	{
		add_block((t_block**)(zone + 1), zone_memory, max_log2);
		zone->max_blocks_count++;
		zone_memory += threshold;
		zone_size -= threshold;
	}
}
