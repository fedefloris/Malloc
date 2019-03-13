/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static bool		find_zone(t_zone *zones, t_zone *zone, t_zone **prev)
{
	*prev = NULL;
	while (zones)
	{
		if (zones == zone)
			return (true);
		*prev = zones;
		zones = (zones)->next;
	}
	return (false);
}

void			remove_zone(t_zone *zone, t_zone_type zone_type)
{
	t_zone		**zones;
	t_zone		*prev;

	zones = get_zones(zone_type);
	if (!find_zone(*zones, zone, &prev))
		return ;
	if (!prev)
		*zones = (*zones)->next;
	else
		prev->next = zone->next;
	munmap(zone, zone->size);
}
