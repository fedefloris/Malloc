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

void		free(void *ptr)
{
	t_block		*block;

	if (!ptr)
		return ;
	(void)block;
	// Maybe check if block is valid? (Might be too slow to check)
	// Free block
	// block = ((t_block*)ptr) - 1;
	// block->is_free = 1;
	// Merge blocks to avoid external fragmentation
	// Should call munmap sometimes?
}
