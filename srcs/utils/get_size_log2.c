/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_log2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			get_size_log2(size_t request)
{
	int			size_log2;
	size_t		size;

	size = 16; // define costants in malloc.h
	size_log2 = 4; // define costants in malloc.h
	while (size < request)
	{
		size_log2++;
		size *= 2;
	}
	return (size_log2);
}
