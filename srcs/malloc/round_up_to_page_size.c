/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_up_to_page_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t      round_up_to_page_size(size_t size)
{
	long	page_size;

	// Deal with memory alignment
	page_size = sysconf(_SC_PAGESIZE);
	ft_printf("page_size: %ld\n", page_size);
	return (size);
}
