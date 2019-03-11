/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_block_in_bucket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_test.h"

bool		is_block_in_bucket(t_block *block, t_zone *zone,
	int zone_type)
{
	t_block		**buckets;
	int			size_log2;
	int			max_log2;

	if (zone_type == LARGE_THRESHOLD)
		return (false);
	size_log2 = MINIMUM_LOG2;
	buckets = (t_block**)(zone + 1);
	max_log2 = (zone_type == TINY_ZONE_SIZE)
		? TINY_MAX_LOG2 : SMALL_MAX_LOG2;
	while (size_log2 <= max_log2)
	{
		if (find_block(buckets[size_log2], block, NULL))
			return (true);
		size_log2++;
	}
	return (false);
}
