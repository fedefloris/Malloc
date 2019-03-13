/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:11 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_zone	*find_zone(t_zone *zones,
	t_zone_type zone_type, char *block)
{
	char		*lower_limit;
	char		*upper_limit;

	while (zones)
	{
		if (IS_TINY_ZONE(zone_type))
			lower_limit = (char*)zones + TINY_ZONE_HEADER_SIZE;
		else if (IS_SMALL_ZONE(zone_type))
			lower_limit = (char*)zones + SMALL_ZONE_HEADER_SIZE;
		else
			lower_limit = (char*)zones + LARGE_ZONE_HEADER_SIZE;
		upper_limit = (char*)zones + zones->size;
		if (block >= lower_limit && block < upper_limit)
			return (zones);
		zones = zones->next;
	}
	return (NULL);
}

t_block			*get_block_info(void *ptr, t_zone **zone,
	t_zone_type *zone_type)
{
	t_block		*block;

	*zone_type = 0;
	block = (t_block*)ptr - 1;
	if ((*zone = find_zone(g_zones.tinies,
			TINY_ZONE, (char*)block)))
		*zone_type = TINY_ZONE;
	else if ((*zone = find_zone(g_zones.smalls,
			SMALL_ZONE, (char*)block)))
		*zone_type = SMALL_ZONE;
	else if ((*zone = find_zone(g_zones.larges,
			LARGE_ZONE, (char*)ptr)))
	{
		*zone_type = LARGE_ZONE;
		return (NULL);
	}
	else
		return (NULL);
	return (block);
}
