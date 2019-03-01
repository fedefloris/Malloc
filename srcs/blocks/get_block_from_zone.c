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
	int i, int size_log2, int max_log2)
{
	t_block		*block;
	t_block		*buddy;

	if (i > max_log2)
		return (NULL);
	block = blocks[i];
	blocks[i] = block->next;
	block->next = NULL;
	while (i != size_log2 && block)
	{
		ft_printf("i: %d, sizelog2: %d\n", i, size_log2);
		buddy = (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
			(char*)block, i - 1);
		buddy->size_log2 = i - 1;
		buddy->next = blocks[i - 1];
		blocks[i - 1] = buddy;
		block->size_log2 = i - 1;
		i--;
	}
	ft_printf("Return block %p, buddy %p, block->size_log2 = %d\n",
		block, (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
		(char*)block, block->size_log2), block->size_log2);
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
	if (*i <= max_log2)
		ft_printf("Free block found at %d\n", *i);
}

static t_block		*get_block_from_buckets(t_block **blocks,
	int size_log2, int max_log2)
{
	int			i;

	i = size_log2;
	get_available_bucket_index(blocks, max_log2, &i);
	return (split_block_until_optimal(blocks, i, size_log2, max_log2));
}

t_block				*get_block_from_zone(t_zone *zone,
		int zone_size, int size_log2)
{
	return (get_block_from_buckets((t_block**)(zone + 1),
		size_log2, (zone_size == TINY_ZONE_SIZE) ?
			TINY_MAX_LOG2 : SMALL_MAX_LOG2));
}
