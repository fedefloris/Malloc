/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/02/26 21:05:24 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		*reallocate_block(void *ptr, size_t size)
{
	int			zone_type;
	t_block		*block;
	t_zone		*zone;

	// deal with large block
	if (!(block = get_block_info(ptr, &zone, &zone_type)))
		return (NULL);
	if (BLOCK_SIZE(block->size_log2) - sizeof(t_block) >= size)
		return (ptr);
	if (!(ptr = allocate(size)))
		return (NULL);
	ft_memcpy(ptr, block + 1,
		BLOCK_SIZE(block->size_log2) - sizeof(t_block));
	free_block(block + 1);
	return (ptr);
}

static void		*reallocate(void *ptr, size_t size)
{
	if (!ptr)
		return (allocate(size));
	if (!size)
	{
		free_block(ptr);
		return (NULL);
	}
	return (reallocate_block(ptr, size));
}

void			*realloc(void *ptr, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	ptr = reallocate(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
