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

	if (!(block = get_free_block(size, zone_type)))
	{
		// check if we can have more memory from the system
		return (NULL);
	}
	// Split the block if block->size > size
	// Deal with memory alignment
	block->is_free = 0;
	return ((void*)(block + 1));
}
