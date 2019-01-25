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

static void		config_memory(char *memory, size_t size)
{
	t_large_block	*block;
	t_zone			*zone;

	zone = (t_zone*)memory;
	zone->next = g_zones.larges;
	g_zones.larges = zone;
	block = (t_large_block*)(zone + 1);
	block->size = size;
}

void			*malloc_large(size_t size)
{
	size_t		memory_size;
	char		*memory;

	memory_size = round_up_to_page_size(sizeof(t_zone) +
		sizeof(t_large_block) + size);
	memory = mmap(0, memory_size, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (memory == MAP_FAILED)
		return (NULL);
	config_memory(memory, memory_size);
	return (memory + sizeof(t_zone) + sizeof(t_large_block));
}
