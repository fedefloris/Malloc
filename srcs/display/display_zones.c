/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_zones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// static void		display_free_blocks(t_block **free_blocks,
// 	int max_log2)
// {
// 	t_block		*block;
// 	size_t		max;
//
// 	max = max_log2;
// 	while (max_log2 >= MINIMUM_LOG2)
// 	{
// 		ft_printf("free_blocks[%d]:", max_log2);
// 		block = free_blocks[max_log2];
// 		while (block)
// 		{
// 			ft_printf(" %p", block);
// 			block = block->next;
// 		}
// 		ft_putstr("\n\n");
// 		max_log2--;
// 	}
// }

static void		display_blocks(t_zone *zone, char *zones_name)
{
	t_block		*block;

	if (!ft_strcmp(zones_name, "TINY"))
		block = (t_block*)((char*)zone + TINY_ZONE_HEADER_SIZE);
	else if (!ft_strcmp(zones_name, "SMALL"))
		block = (t_block*)((char*)zone + SMALL_ZONE_HEADER_SIZE);
	else
		return ;
	while ((char*)block < (char*)zone + zone->size
		&& block->size_log2)
	{
		ft_printf("%p - %zd bytes\n",
			block, (size_t)BLOCK_SIZE(block->size_log2));
		block = (t_block*)((char*)block + BLOCK_SIZE(block->size_log2));
	}
	// int			max_log2;
	//
	// if (!ft_strcmp(zones_name, "TINY"))
	// 	max_log2 = TINY_MAX_LOG2;
	// else if (!ft_strcmp(zones_name, "SMALL"))
	// 	max_log2 = SMALL_MAX_LOG2;
	// else
	// 	return ;
	// display_free_blocks((t_block**)((char*)zone + ZONE_HEADER_SIZE),
	// 	max_log2);
}

void			display_zones(t_zone *zone, char *zones_name)
{
	ft_printf("--%s--\n", zones_name);
	while (zone)
	{
		ft_printf("\nZone from %p to %p, size: %zu bytes, next: %p\n\n",
			zone, (char*)zone + zone->size,
			zone->size, zone->next);
		display_blocks(zone, zones_name);
		zone = zone->next;
	}
	ft_putstr("\n");
}
