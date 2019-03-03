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

/*
** The realloc() function changes the size of the memory block pointed to
** by ptr to size bytes.
** The contents will be unchanged in the range from the start of the
** region up to the minimum of the old  and  new  sizes.
** If  the new size is larger than the old size,
** the added memory will not be initialized.
** If ptr is NULL, then the call is equivalent to malloc(size),
** for all values of size;
** if size is equal to zero, and ptr is not NULL,
** then the call is equivalent to free(ptr).
** Unless ptr is NULL, it must have been returned by an earlier call
** to  malloc(),  calloc(), or realloc().
** If the area pointed to was moved, a free(ptr) is done.
** The realloc() function returns a pointer to the newly allocated memory,
** which is suitably aligned for any built-in type and
** may be different from ptr, or NULL if the request fails.
** If  size was equal to 0, either NULL or a pointer suitable
** to be passed to free() is returned.
** If realloc() fails, the original block is left untouched;
** it is not freed or moved.
*/

void	*realloc(void *ptr, size_t size)
{
	int			zone_type;
	t_block		*block;
	t_zone		*zone;

	pthread_mutex_lock(&g_mutex);
	if (!ptr)
		return (allocate(size));
	if (!size)
	{
		free_block(ptr);
		return (NULL);
	}
	pthread_mutex_unlock(&g_mutex);
	find_block_info(ptr, &block, &zone, &zone_type);
	if (!block)
		return (NULL);
	if (BLOCK_SIZE(block->size_log2) - sizeof(t_block) >= size)
		return (ptr);
	if (!(ptr = allocate(size)))
		return (NULL);
	ft_memcpy(ptr, block + 1,
		BLOCK_SIZE(block->size_log2) - sizeof(t_block));
	free_block(block + 1);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
