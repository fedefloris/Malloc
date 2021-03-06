/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/26 21:06:19 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block		*split_block_until_optimal(t_block **blocks,
	int i, int size_log2, int buckets_size)
{
	t_block		*block;
	t_block		*buddy;

	block = blocks[i];
	blocks[i] = block->next;
	block->next = NULL;
	block->size_log2 = size_log2;
	while (i > size_log2)
	{
		buddy = (t_block*)BUDDY(((char*)blocks + buckets_size),
			(char*)block, i - 1);
		buddy->size_log2 = i - 1;
		buddy->next = blocks[i - 1];
		blocks[i - 1] = buddy;
		i--;
	}
	return (block);
}

static void			get_available_bucket_index(t_block **blocks,
	int max_log2, int *i)
{
	while (*i <= max_log2)
	{
		if (blocks[*i])
			break ;
		(*i)++;
	}
}

static t_block		*get_block_from_buckets(t_zone *zone,
	int size_log2, int max_log2, int buckets_size)
{
	int			i;

	i = size_log2;
	get_available_bucket_index((t_block**)(zone + 1),
		max_log2, &i);
	if (i == max_log2)
		zone->max_blocks_count--;
	else if (i > max_log2)
		return (NULL);
	return (split_block_until_optimal((t_block**)(zone + 1),
		i, size_log2, buckets_size));
}

t_block				*get_block_from_zone(t_zone *zone,
	t_zone_type zone_type, int size_log2)
{
	return (get_block_from_buckets(zone, size_log2,
		IS_TINY_ZONE(zone_type) ? TINY_MAX_LOG2 : SMALL_MAX_LOG2,
		IS_TINY_ZONE(zone_type) ? TINY_BUCKETS_SIZE
			: SMALL_BUCKETS_SIZE));
}
