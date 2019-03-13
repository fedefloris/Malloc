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

void			display_zones(t_zone *zone, t_zone_type zone_type,
	bool hexdump)
{
	while (zone)
	{
		ft_printf("\nZone from %p to %p - %zu bytes - next: %p\n\n",
			zone, (char*)zone + zone->size,
			zone->size, zone->next);
		display_blocks(zone, zone_type, hexdump);
		zone = zone->next;
	}
	ft_putstr("\n");
}
