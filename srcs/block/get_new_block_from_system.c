/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_block_from_system.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		config_block(t_block *block, int zone_type)
{
	// check memory alignment
	block->size = zone_type - sizeof(*block);
	block->is_free = 1;
}

t_block			*get_new_block_from_system(int zone_type)
{
	t_block		*block;

	// Deal with memory alignment
	block = (t_block*)mmap(0, zone_type, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (block == MAP_FAILED)
		return (NULL);
	config_block(block, zone_type);
	// append block to list according to zone_type
	return (block);
}
