/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/26 21:06:42 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

bool		find_block(t_block *blocks, t_block *block,
	t_block **prev)
{
	if (prev)
		*prev = NULL;
	while (blocks)
	{
		if (block == blocks)
			return (true);
		if (prev)
			*prev = blocks;
		blocks = blocks->next;
	}
	return (false);
}
