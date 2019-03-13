/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*allocate(size_t size)
{
	if (!size)
		return (g_zones.empty_malloc);
	if (size <= TINY_THRESHOLD - sizeof(t_block))
		return (allocate_small(size, TINY_ZONE));
	else if (size <= SMALL_THRESHOLD - sizeof(t_block))
		return (allocate_small(size, SMALL_ZONE));
	return (allocate_large(size));
}
