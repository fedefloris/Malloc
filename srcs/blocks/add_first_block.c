/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		add_first_block(t_zone *zone, int zone_type)
{
	t_block		*block;

	ft_printf("size with tinies: %zd\n",
		zone->size - sizeof(zone) - sizeof(t_tiny_blocks));
	if (zone_type == TINY_ZONE_SIZE)
	{
		block = (t_block*)(zone + 1) + TINY_MAX_LOG2 + 1;
		block->size_log2 = TINY_MAX_LOG2;
		((t_block**)(zone + 1))[TINY_MAX_LOG2] = block;
	}
	else
	{
		block = (t_block*)(zone + 1) + SMALL_MAX_LOG2 + 1;
		block->size_log2 = SMALL_MAX_LOG2;
		((t_block**)(zone + 1))[SMALL_MAX_LOG2] = block;
	}
	// TODO: memset to zero for freelist
}
