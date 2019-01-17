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

void		display_zone(t_block *blocks, char *zone_name)
{
	ft_printf("%s: %p\n", zone_name, blocks);
	while (blocks)
	{
		ft_printf("%p - %p: %zd bytes, free: %d\n",
			blocks, blocks->next, blocks->size, blocks->is_free);
		blocks = blocks->next;
	}
}
