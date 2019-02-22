/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			free(void *ptr)
{
	// t_block		*block;

	if (!ptr || free_large_block(ptr))
		return ;
	// if (!(block = find_block(ptr)))
	// {
	// 	ft_printf("Invalid pointer\n");
	// 	return ;
	// }
	// merge_free_blocks(block);
	// when should I call munmap?
}
