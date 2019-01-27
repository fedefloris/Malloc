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

static void		display_blocks(t_zone *zone)
{
	t_block		*block;

	block = (t_block*)(zone + 1);
	ft_printf("Block-> size: %zu, left: %d, free: %d\n",
		1 << block->size, block->left, block->free);
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
		display_blocks(zone);
		zone = zone->next;
	}
	ft_putstr("\n");
}
