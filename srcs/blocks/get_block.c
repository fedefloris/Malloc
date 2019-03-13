/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:54:27 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block			*get_block(t_zone_type zone_type, int size_log2)
{
	t_block		*block;
	t_zone		*zones;

	zones = *get_zones(zone_type);
	if (!(block = get_block_from_zones(zones, zone_type, size_log2)))
	{
		if (!(zones = add_zone(zone_type,
			IS_TINY_ZONE(zone_type) ? TINY_ZONE_SIZE : SMALL_ZONE_SIZE)))
			return (NULL);
		return (get_block_from_zones(zones, zone_type, size_log2));
	}
	return (block);
}
