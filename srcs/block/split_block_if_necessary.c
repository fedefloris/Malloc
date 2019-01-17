/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block_if_necessary.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		split_block_if_necessary(t_block *block, size_t size)
{
	if (block->size == sizeof(t_block) + size)
		return ;
	// Deal with memory alignment
	block->next = (t_block*)((char*)block + sizeof(t_block) + size);
	block->next->size = block->size - sizeof(t_block) - size;
	block->next->is_free = 1;
	block->next->next = NULL;
	block->size = sizeof(t_block) + size;
}
