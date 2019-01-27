/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zones.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		split_block(t_block *block)
{
	t_block		*right_buddy;

	block->size--;
	right_buddy = (t_block*)((char*)block + (1 << block->size));
	right_buddy->free = 1;
	right_buddy->left = 0;
	right_buddy->size = block->size;
}

static t_block	*get_block_from_zone(t_zone *zone, int size_log2)
{
	t_block		*block;

	block = (t_block*)(zone + 1);
	while ((char*)block < (char*)zone + zone->size)
	{
		if (block->free && size_log2 <= block->size)
		{
			if (size_log2 == block->size)
			{
				block->free = 0;
				return (block);
			}
			else
				split_block(block);
		}
		else
			block = (t_block*)((char*)block + (1 << block->size));
	}
	return (NULL);
}

t_block			*get_block_from_zones(t_zone *zones, int size_log2)
{
	t_block		*block;

	block = NULL;
	while (zones)
	{
		if ((block = get_block_from_zone(zones, size_log2)))
			break ;
		zones = zones->next;
	}
	return (block);
}
