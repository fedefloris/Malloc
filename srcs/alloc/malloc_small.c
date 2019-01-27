/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_zone	*get_zones(int zone_size)
{
	if (zone_size == TINY_ZONE_SIZE)
		return (g_zones.tinies);
	return (g_zones.smalls);
}

void			*malloc_small(size_t size, int zone_size)
{
	int			size_log2;
	t_zone		*zones;
	t_block		*block;

	zones = get_zones(zone_size);
	size_log2 = get_size_log2(sizeof(t_block) + size);
	if (!(block = get_block(zones, size_log2)))
		return (NULL);
	return ((void*)(block + 1));
}
