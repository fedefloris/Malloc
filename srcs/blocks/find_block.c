/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:11 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_zone	*find_zone(t_zone *zones, t_block *block)
{
	while (zones)
	{
		if ((char*)block >= (char*)(zones + 1)
			&& (char*)block < (char*)zones + zones->size)
			return (zones);
		zones = zones->next;
	}
	return (NULL);
}

t_block			*find_block(void *ptr)
{
	t_block		*block;
	t_block		*curr;
	t_zone		*zone;

	block = (t_block*)((char*)ptr - sizeof(t_block));
	if (!(zone = find_zone(g_zones.tinies, block))
		&& !(zone = find_zone(g_zones.smalls, block)))
		return (NULL);
	curr = (t_block*)(zone + 1);
	while ((char*)curr < (char*)zone + zone->size)
	{
		if (curr == block)
			return (block);
		curr = (t_block*)((char*)curr + (1 << curr->size));
	}
	// should I really check all blocks?
	return (NULL);
}
