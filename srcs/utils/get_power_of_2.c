/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_power_of_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			get_power_of_2(size_t request)
{
	int			power_of_2;
	size_t		size;

	size = 16;
	power_of_2 = 4;
	while (size < request)
	{
		power_of_2++;
		size *= 2;
	}
	return (power_of_2);
}
