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
	char		*final_byte;
	char		*byte;

	byte = (char*)block;
	final_byte = byte + sizeof(t_block) + BLOCK_SIZE(block->size_log2);
	ft_printf("    ");
	while (byte <= final_byte)
	{
		ft_printf((byte < (char*)(block + 1))
			? "$blue$" : "$cyan$");
		ft_printf("%08x ", *byte++);
		if (byte != final_byte + 1
				&& ((intptr_t)byte - (intptr_t)block) % 6 == 0)
			ft_printf("\n    ");
	}
	ft_printf("\n$eoc$");
}

void			display_block(t_block *block, bool allocated, bool hexdump)
{
	ft_printf("  %p to %p - % 6zd bytes - %s\n",
		block, (char*)block + BLOCK_SIZE(block->size_log2),
		(size_t)BLOCK_SIZE(block->size_log2),
		(allocated) ? "[x]" : "[ ]");
	if (hexdump && allocated)
		display_block_hexdump(block);
}
