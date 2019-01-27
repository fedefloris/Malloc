/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		config_zone(t_zone *zone, int zone_type, size_t size)
{
	t_zone		**zones;

	if (zone_type == TINY_ZONE_SIZE)
		zones = &g_zones.tinies;
	else if (zone_type == SMALL_ZONE_SIZE)
		zones = &g_zones.smalls;
	else
		zones = &g_zones.larges;
	zone->size = size;
	zone->next = *zones;
	*zones = zone;
}

t_zone			*add_zone(int zone_type, size_t size)
{
	size_t		memory_size;
	char		*memory;

	memory_size = round_up_to_page_size(size);
	memory = mmap(0, memory_size, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (memory == MAP_FAILED)
		return (NULL);
	config_zone((t_zone*)memory, zone_type, memory_size);
	return ((t_zone*)memory);
}
