/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_from_zones.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block			*get_block_from_zones(t_zone *zones, int size_log2)
{
	t_block		*block;

	block = NULL;
	ft_printf("Searching for a new block...\n");
	while (zones)
	{
		if ((block = get_block_from_zone(zones, size_log2)))
			break ;
		zones = zones->next;
	}
	return (block);
}
