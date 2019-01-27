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

	if (!size)
		return (NULL);
	ft_printf("Request of %zu bytes\n", size);
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
