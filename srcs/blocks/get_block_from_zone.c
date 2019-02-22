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
	int			i;

	block = NULL;
	i = size_log2;
	while (i <= max_log2)
	{
		ft_printf("Getting block from freelist, i: %d\n", i);
		if (blocks[i])
		{
			ft_printf("free block found\n");
			block = blocks[i];
			blocks[i] = NULL;
			break ;
		}
		i++;
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
