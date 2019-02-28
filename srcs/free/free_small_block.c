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

void			free_small_block(t_block **blocks, t_block *block,
	t_zone *zone, int zone_type)
{
	int			size_log2;
	int			max_log2;
	t_block		*buddy;

	if (!block)
		return ; // invalid pointer for block
	(void)zone_type;
	if (zone_type == TINY_ZONE_SIZE)
		max_log2 = TINY_MAX_LOG2;
	else
		max_log2 = SMALL_MAX_LOG2;
	size_log2 = block->size_log2;
	(void)zone;
	t_block *temp;
	t_block *prev;
	while (size_log2 <= max_log2)
	{
		buddy = (t_block*)BUDDY((char*)(blocks + max_log2 + 1),
			(char*)block, size_log2);
		temp = blocks[size_log2];
		prev = NULL;
		while (temp)
		{
			if (buddy == temp)
			{
				ft_printf("Merge free blocks at %d\n", size_log2);
				break ;
			}
			prev = temp;
			temp = temp->next;
		}
		if (buddy != temp)
		{
			block->next = blocks[size_log2];
			blocks[size_log2] = block;
			return ;
		}
		block = (block < buddy) ? block : buddy;
		if (!prev)
			blocks[size_log2] = buddy->next;
		else
			prev->next = buddy->next;
		buddy->next = NULL;
		size_log2++;
	}
	// when should I call munmap?
}
