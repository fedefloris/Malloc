/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:11 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

bool		is_valid_block(t_block *block, t_zone *zone,
	t_zone_type zone_type)
{
	char		*blocks;

	blocks = (char*)zone;
	block += IS_TINY_ZONE(zone_type) ? TINY_BUCKETS_SIZE : SMALL_BUCKETS_SIZE;
	if ((intptr_t)block % 16 != 0)
		return (false);
	while (blocks < (char*)zone + zone->size
		&& ((t_block*)blocks)->size_log2)
	{
		if (blocks == (char*)block)
			return (true);
		blocks += BLOCK_SIZE(((t_block*)blocks)->size_log2);
	}
	return (true);
	// return (false);
}
