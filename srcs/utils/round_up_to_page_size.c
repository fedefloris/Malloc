/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_up_to_page_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:31 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		round_up_to_page_size(size_t size)
{
	long	page_size;

	page_size = sysconf(_SC_PAGESIZE);
	if (size % page_size)
		return (size - (size % page_size) + page_size);
	return (size);
}
