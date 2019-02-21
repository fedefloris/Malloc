/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	        *get_block_from_zone(t_zone *zone, int size_log2)
{
	t_block		*block;
	int			i;

	// while i < max log2
	// 	find a block that is available
	// 	if found it block = block found, break;
	// if block found
	// 	remove block from free_blocks[i]
	// 	split block until i == size_log2
	// 	return last block
	i = size_log2;
	while (i < TINY_MAX_LOG2) // deal SMALL_MAX_LOG2
	{
		i++;
	}
	block = NULL;
	(void)zone;
	return (block);
}
