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
	t_zone		*zones;
	t_block		*block;

	block = NULL;
	zones = get_zones(zone_size);
	(void)zones;
	(void)size;
	// get power of 2 that fits requested size
	// if no zones get one
	// for every zone
	//  search a free block
	// return ((void*)(block + 1));
	return (block);
}
