/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_up_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:55:31 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		round_up_to(size_t from, size_t to)
{
	if (from % to)
		return (from - (from % to) + to);
	return (from);
}
