/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free_small_block(t_block *block, int zone_type)
{
	(void)block;
	(void)zone_type;
	// search BUDDY in free list of block->size_log2
	// check limits of size_log2
	// if BUDDY found merge blocks, repeat process if possible
	// when should I call munmap?
}
