/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		display_block_hexdump(t_block *block)
{
	(void)block;
}

void			display_block(t_block *block, bool allocated, bool hexdump)
{
	ft_printf("  %p to %p - % 6zd bytes - %s\n",
		block, (char*)block + BLOCK_SIZE(block->size_log2),
		(size_t)BLOCK_SIZE(block->size_log2),
		(allocated) ? "[x]" : "[ ]");
	if (hexdump)
		display_block_hexdump(block);
}
