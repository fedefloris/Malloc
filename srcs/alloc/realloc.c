/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
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
*/
void		*realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (malloc(size));
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	// check valid ptr, use same functions of free
	// try to change size
	// if it's not possible
	//   call malloc with the new size, memcpy and free previous
	return (NULL);
}
