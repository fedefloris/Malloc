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

static void		display_blocks(t_zone *zone, char *zones_name)
{
	t_block		*block;

	if (!ft_strcmp(zones_name, "TINY"))
		block = (t_block*)((t_block**)(zone + 1) + TINY_MAX_LOG2 + 1);
	else if (!ft_strcmp(zones_name, "SMALL"))
		block = (t_block*)((t_block**)(zone + 1) + SMALL_MAX_LOG2 + 1);
	else
		return ;
	while ((char*)block < (char*)zone + zone->size
		&& block->size_log2)
	{
		ft_printf("Block-> addr: %p, size: %zu\n",
			block, BLOCK_SIZE(block->size_log2));
		block = (t_block*)((char*)block + BLOCK_SIZE(block->size_log2));
	}
	ft_printf("\n\n");
}

void			display_zones(t_zone *zone, char *zones_name)
{
	ft_printf("--%s--\n", zones_name);
	while (zone)
	{
		ft_printf("Zone from %p to %p, size: %zu, next: %p\n",
			zone, (char*)zone + zone->size,
			zone->size, zone->next);

		display_blocks(zone, zones_name);
		zone = zone->next;
	}
	ft_putstr("\n");
}
