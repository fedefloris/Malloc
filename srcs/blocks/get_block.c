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

t_block			*get_block(int zone_size, int size_log2)
{
	t_block		*block;
	t_zone		*zones;

	zones = *get_zones(zone_size);
	if (!(block = get_block_from_zones(zones, zone_size, size_log2)))
	{
		if (!(zones = add_zone(zone_size, zone_size)))
			return (NULL);
		return (get_block_from_zones(zones, zone_size, size_log2));
	}
	return (block);
}
