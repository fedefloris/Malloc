/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zones.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*get_block_from_zone(t_zone *zone, int size_log2)
{
	t_block		*block;

	block = (t_block*)(zone + 1);
	(void)size_log2;
	// block = zone + 1
	// while not at the end of the zone
	//   if block is free and block size if greater/equal to size_log2
	//     if block size == size_log2
	//       mark block as allocated and return the block
	//     else
	//       split block in two blocks of size_log2 - 1
	//       continue to next iteration
	//   else
	//     jump to next block
	return (block);
}

t_block			*get_block_from_zones(t_zone *zones, int size_log2)
{
	t_block		*block;

	block = NULL;
	while (zones)
	{
		if ((block = get_block_from_zone(zones, size_log2)))
			break ;
		zones = zones->next;
	}
	return (block);
}
