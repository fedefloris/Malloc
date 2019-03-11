/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:54:50 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	ft_printf("-- Allocated tiny blocks --\n");
	display_zones(g_zones.tinies, TINY_ZONE_SIZE);
	ft_printf("-- Allocated small blocks --\n");
	display_zones(g_zones.smalls, SMALL_ZONE_SIZE);
	ft_printf("-- Allocated large blocks --\n");
	display_zones(g_zones.larges, LARGE_THRESHOLD);
	pthread_mutex_unlock(&g_mutex);
}
