/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		display_zone(t_zone *zone, char *zone_name)
{
	ft_printf("--%s--\n", zone_name);
	while (zone)
	{
		ft_printf("%p\n", zone);
		zone = zone->next;
	}
	ft_putstr("\n");
}
