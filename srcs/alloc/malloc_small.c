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

static int		get_power_of_2(size_t request)
{
	int			power_of_2;
	size_t		size;

	size = 16;
	power_of_2 = 4;
	while (size < request)
	{
		power_of_2++;
		size *= 2;
	}
	return (power_of_2);
}

void			*malloc_small(size_t size, int zone_size)
{
	int			power_of_2;
	t_zone		*zones;
	t_block		*block;

	block = NULL;
	zones = get_zones(zone_size);
	power_of_2 = get_power_of_2(sizeof(t_block) + size);
	ft_printf("power of 2: %zu\n", power_of_2);
	if (!(block = get_block_from_zones(zones, power_of_2)))
		{}// add_new_zone() get_block_from_zones()
	if (!block)
		return (NULL);
	return ((void*)(block + 1));
}
