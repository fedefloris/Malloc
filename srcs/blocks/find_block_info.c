/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:11 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_zone	*find_zone(t_zone *zones, t_block *block)
{
	while (zones)
	{
		if ((char*)block >= (char*)(zones + 1)
			&& (char*)block < (char*)zones + zones->size)
			return (zones);
		zones = zones->next;
	}
	// t_block		*curr;
	// should I check all blocks?
	// curr = (t_block*)(zone + 1);
	// while ((char*)curr < (char*)zone + zone->size)
	// {
	// check if curr->size_log2 == 0 to avoid useless loop cycles
	// 	if (curr == block)
	// 		return (block);
	// 	curr = (t_block*)((char*)curr + (1 << curr->size_log2));
	// }
	// return (NULL);
	return (NULL);
}

void			find_block_info(void *ptr, t_block **block,
	t_zone **zone, int *zone_type)
{
	*zone_type = 0;
	*block = (t_block*)((char*)ptr - sizeof(t_block));
	if ((*zone = find_zone(g_zones.tinies, *block)))
		*zone_type = TINY_ZONE_SIZE;
	else if ((*zone = find_zone(g_zones.smalls, *block)))
		*zone_type = SMALL_ZONE_SIZE;
	else
		*block = NULL;
}
