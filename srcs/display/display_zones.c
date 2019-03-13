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

static void		display_blocks(t_zone *zone, t_zone_type zone_type)
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
		ft_printf("  From %p to %p - %zd bytes - allocated: %s\n",
			block, (char*)block + BLOCK_SIZE(block->size_log2),
			(size_t)BLOCK_SIZE(block->size_log2),
			is_block_allocated(block, zone, zone_type) ? "yes" : "no");
		block = (t_block*)((char*)block + BLOCK_SIZE(block->size_log2));
	}
}

void			display_zones(t_zone *zone, t_zone_type zone_type)
{
	while (zone)
	{
		ft_printf("\nZone from %p to %p - %zu bytes - next: %p\n\n",
			zone, (char*)zone + zone->size,
			zone->size, zone->next);
		display_blocks(zone, zone_type);
		zone = zone->next;
	}
	ft_putstr("\n");
}
