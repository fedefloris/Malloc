/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*get_block_from_buckets(t_block **blocks,
	int size_log2, int max_log2)
{
	t_block		*block;
	t_block		*buddy;
	int			i;

	block = NULL;
	i = size_log2;
	while (i <= max_log2)
	{
		ft_printf("Searching block in %d, Max_log2: %d\n", i, max_log2);
		if (blocks[i])
		{
			ft_printf("Free block found\n");
			block = blocks[i];
			blocks[i] = NULL;
			break ;
		}
		i++;
	}
	while (i != size_log2 && block)
	{
		ft_printf("i: %d, sizelog2: %d,", i, size_log2);
		ft_printf("Max_log2: %d, Start addr: %p ", max_log2,
			blocks + max_log2 + 1);
		ft_printf("BLOCK: %p, BUDDY: %p, Block distance: %d, ", block,
			BUDDY((char*)(blocks + max_log2 + 1), (char*)blocks + i, i),
			(char*)block - (char*)(blocks + max_log2 + 1));
		buddy = (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
			(char*)block, i - 1);
		ft_printf("Buddy distance: %d\n",
			(char*)buddy - (char*)(blocks + max_log2 + 1));
		buddy->size_log2 = i - 1;
		blocks[i - 1] = buddy;
		block->size_log2 = i - 1;
		i--;
	}
	return (block);
}

t_block	        *get_block_from_zone(t_zone *zone,
	int zone_size, int size_log2)
{
	return (get_block_from_buckets((t_block**)(zone + 1),
		size_log2, (zone_size == TINY_ZONE_SIZE) ?
			TINY_MAX_LOG2 : SMALL_MAX_LOG2));
}
