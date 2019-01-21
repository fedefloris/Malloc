/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zones		g_zones = {NULL, NULL, NULL};

void		*malloc(size_t size)
{
	void	*mem;

	ft_printf("Requesting %zd bytes\n", size);
	ft_printf("t_zones is %zd bytes\n", sizeof(t_zones));
	ft_printf("t_zone is %zd bytes\n", sizeof(t_zone));
	ft_printf("t_block is %zd bytes\n", sizeof(t_block));
	if (!size)
		return (NULL);
	// lock thread
	if (size <= TINY_THRESHOLD)
		mem = malloc_small(size, TINY_ZONE_SIZE);
	else if (size <= SMALL_THRESHOLD)
		mem = malloc_small(size, SMALL_ZONE_SIZE);
	else
		mem = malloc_large(size);
	// unlock thread
	return (mem);
}
