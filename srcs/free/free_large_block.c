/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_large_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:56:30 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		find_large_zone(void *ptr, t_zone **zone, t_zone **prev)
{
	*prev = NULL;
	*zone = g_zones.larges;
	while (*zone)
	{
		if (((char*)ptr == (char*)(zone + 1)))
			return ;
		*prev = *zone;
		*zone = (*zone)->next;
	}
	*zone = NULL;
	*prev = NULL;
}

bool			free_large_block(void *ptr)
{
	t_zone		*prev;
	t_zone		*zone;

	zone = NULL;
	prev = NULL;
	find_large_zone(ptr, &zone, &prev);
	if (!zone)
		return (false);
	if (!prev)
		g_zones.larges = zone->next;
	else
		prev->next = zone->next;
	munmap((void*)zone, zone->size);
	return (true);
}
