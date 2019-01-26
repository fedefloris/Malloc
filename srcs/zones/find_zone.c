/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_zone	*find_block_in_large_zone(void *ptr)
{
	// void		*start;
	//
	// start = zone + 1;
	// while (zone)
	// {
	// 	if ((ptr > zone && ptr <))
	// 		return (zone);
	// 	zone = zone->next;
	// }
	(void)ptr;
	return (NULL);
}

void            find_zone(void *ptr, t_zone **zone)
{
	// if ((*zone = find_block_in_zone(g_zones.tinies, ptr)))
	// 	ft_printf("Found in g_zones.tinies\n");
	// if ((*zone = find_block_in_zone(g_zones.smalls, ptr)))
	// 	ft_printf("Found in g_zones.smalls\n");
	if ((*zone = find_block_in_large_zone(ptr)))
		ft_printf("Found in g_zones.larges\n");
}
