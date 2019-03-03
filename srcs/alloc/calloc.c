/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*calloc(size_t elements_count, size_t element_size)
{
	void	*mem;

	pthread_mutex_lock(&g_mutex);
	// check for overflow
	if ((mem = allocate(elements_count * element_size)))
		ft_bzero(mem, elements_count * element_size);
	pthread_mutex_unlock(&g_mutex);
	return (mem);
}
