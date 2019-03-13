/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:54:27 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone		**get_zones(t_zone_type zone_type)
{
	if (IS_TINY_ZONE(zone_type))
		return (&g_zones.tinies);
	else if (IS_SMALL_ZONE(zone_type))
		return (&g_zones.smalls);
	return (&g_zones.larges);
}
