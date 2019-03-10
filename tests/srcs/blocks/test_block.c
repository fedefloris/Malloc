/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

void			test_block(void *ptr, size_t size, t_block_status status)
{
	int			zone_type;
	t_zone		*zone;
	t_block		*block;

	if (!(block = get_block_info(ptr, &zone, &zone_type)))
	{} //error
	test_block_header(block, size, status);
	// test_block_
}
