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

static void		add_block(t_block **blocks,
	int max_log2, int size_log2)
{
	blocks[size_log2] = (t_block*)(blocks + max_log2 + 1);
	blocks[size_log2]->size_log2 = size_log2;
	blocks[size_log2]->next = NULL;
}

void			add_first_block(t_zone *zone, int zone_type)
{
	// we need to push many initial blocks
	if (zone_type == TINY_ZONE_SIZE)
		add_block(((t_block**)(zone + 1)), TINY_MAX_LOG2, TINY_MAX_LOG2);
	else
		add_block(((t_block**)(zone + 1)), SMALL_MAX_LOG2, TINY_MAX_LOG2);
}
