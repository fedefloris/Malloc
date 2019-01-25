/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		config_mem(char *mem, size_t size)
{
	t_large_block	*block;
	t_zone			*zone;

	zone = (t_zone*)mem;
	zone->next = g_zones.larges;
	g_zones.larges = zone;
	block = (t_large_block*)(zone + 1);
	block->size = size;
}

void			*malloc_large(size_t size)
{
	size_t	mem_size;
	char	*mem;

	mem_size = round_up_to_page_size(sizeof(t_zone) +
		sizeof(t_large_block) + size);
	mem = mmap(0, mem_size,
		PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE,
		-1, 0);
	if (mem == MAP_FAILED)
		return (NULL);
	config_mem(mem, mem_size);
	return (mem + sizeof(t_zone) + sizeof(t_large_block));
}
