/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free(void *ptr)
{
	int			zone_type;
	t_block		*block;
	t_zone		*zone;

	if (!ptr || free_large_block(ptr))
		return ;
	find_block_info(ptr, &block, &zone, &zone_type);
	if (!block)
		return ; // invalid pointer for block
	free_small_block((t_block**)(zone + 1), block,
		(zone_type == TINY_ZONE_SIZE) ?
			TINY_MAX_LOG2 : SMALL_MAX_LOG2);
	// when should I call munmap?
}
