/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

int		main(void)
{
	test_blocks(1, 1000);
	test_blocks(16, 1000);
	test_blocks(350, 1000);
	test_blocks(TINY_THRESHOLD - sizeof(t_block), 1000);
	test_blocks(SMALL_THRESHOLD - sizeof(t_block), 1000);
	test_blocks(TINY_THRESHOLD, 1000);
	test_blocks(SMALL_THRESHOLD, 1000);
	test_blocks(LARGE_THRESHOLD, 1000);
	return (0);
}
