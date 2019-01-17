/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*malloc_small(size_t size, int zone_type)
{
	t_block		*block;

	// first fit algorithm, pretty slow
	// think about buddy implementation
	if (!(block = get_free_block(size, zone_type))
		&& !(block = get_new_block_from_system(zone_type)))
		return (NULL);
	block->is_free = 0;
	split_block_if_necessary(block, size);
	return ((void*)(block + 1));
}
