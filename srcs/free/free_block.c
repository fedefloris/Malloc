/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free_block(void *ptr)
{
	t_zone_type	zone_type;
	int			max_log2;
	t_block		*block;
	t_zone		*zone;

	if (!ptr || ptr == g_zones.empty_malloc || free_large_block(ptr)
		|| !(block = get_block_info(ptr, &zone, &zone_type)))
		return ;
	max_log2 = IS_TINY_ZONE(zone_type) ? TINY_MAX_LOG2 : SMALL_MAX_LOG2;
	free_small_block((t_block**)(zone + 1), &block, max_log2);
	if (block->size_log2 == max_log2)
		zone->max_blocks_count++;
	if (zone->max_blocks_count == zone->max_blocks && zone->next)
		remove_zone(zone, zone_type);
}
