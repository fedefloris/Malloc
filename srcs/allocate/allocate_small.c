/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*allocate_small(size_t size, t_zone_type zone_type)
{
	int			size_log2;
	t_block		*block;

	size_log2 = get_size_log2(sizeof(t_block) + size);
	if (!(block = get_block(zone_type, size_log2)))
		return (NULL);
	return (block + 1);
}
