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
	if (!size)
		return (NULL);
	if (size <= TINY_SIZE)
		return (malloc_small(size, TINY_SIZE));
	if (size <= SMALL_SIZE)
		return (malloc_small(size, SMALL_SIZE));
	return (malloc_large(size));
}
