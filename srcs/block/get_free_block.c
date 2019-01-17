/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_free_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		*get_free_block(size_t size, int zone_type)
{
	t_zone		*zones;
	t_block		*blocks;

	blocks = NULL;
	zones = g_zones.tinies;
	if (zone_type == SMALL_ZONE_SIZE)
		zones = g_zones.smalls;
	while (zones)
	{
		blocks = zones->blocks;
		while (blocks)
		{
			if (blocks->is_free && blocks->size >= size)
				break ;
			blocks = blocks->next;
		}
		zones = zones->next;
	}
	return (blocks);
}
