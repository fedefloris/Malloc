/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/26 21:06:42 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// static void		merge_blocks()

static bool		find_block(t_block *blocks, t_block *block,
	t_block **prev)
{
	*prev = NULL;
	while (blocks)
	{
		if (block == blocks)
			return (true);
		*prev = blocks;
		blocks = blocks->next;
	}
	return (false);
}

void			free_small_block(t_block **blocks, t_block *block,
	int max_log2)
{
	int			size_log2;
	t_block		*buddy;
	t_block		*prev;

	size_log2 = block->size_log2;
	while (size_log2 <= max_log2)
	{
		buddy = (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
			(char*)block, size_log2);
		ft_printf("Buddy %p with block %p at %d, max_log2: %d\n",
			block, buddy, size_log2, max_log2);
		if (size_log2 == max_log2 ||
			!find_block(blocks[size_log2], buddy, &prev))
		{
			ft_printf("Not found\n");
			block->size_log2 = size_log2;
			block->next = blocks[size_log2];
			blocks[size_log2] = block;
			return ;
		}
		ft_printf("Found, merging...\n");
		block = (block < buddy) ? block : buddy;
		if (!prev)
			blocks[size_log2] = buddy->next;
		else
			prev->next = buddy->next;
		size_log2++;
	}
}
