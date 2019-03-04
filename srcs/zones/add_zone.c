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
	{
		zones = &g_zones.tinies;
		ft_bzero(zone + 1, TINY_BUCKETS_SIZE);
	}
	else if (zone_type == SMALL_ZONE_SIZE)
	{
		zones = &g_zones.smalls;
		ft_bzero(zone + 1, SMALL_BUCKETS_SIZE);
	}
	else
		zones = &g_zones.larges;
	zone->size = size;
	zone->next = *zones;
	zone->max_blocks_count = 0;
	*zones = zone;
}

t_zone			*add_zone(int zone_type, size_t size)
{
	size_t		zone_size;
	char		*memory;

	zone_size = round_up_to(size, sysconf(_SC_PAGESIZE));
	memory = mmap(0, zone_size, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (memory == MAP_FAILED)
		return (NULL);
	config_zone((t_zone*)memory, zone_type, zone_size);
	if (zone_type != LARGE_THRESHOLD)
		add_first_blocks((t_zone*)memory, zone_type);
	((t_zone*)memory)->max_blocks = ((t_zone*)memory)->max_blocks_count;
	return ((t_zone*)memory);
}
