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

#include "malloc.h"

bool		is_block_in_bucket(t_block *block, t_zone *zone,
	t_zone_type zone_type)
{
	t_block		**buckets;
	int			size_log2;
	int			max_log2;

	if (IS_LARGE_ZONE(zone_type))
		return (false);
	size_log2 = MINIMUM_LOG2;
	buckets = (t_block**)(zone + 1);
	max_log2 = IS_TINY_ZONE(zone_type) ? TINY_MAX_LOG2 : SMALL_MAX_LOG2;
	while (size_log2 <= max_log2)
	{
		if (find_block(buckets[size_log2], block, NULL))
			return (true);
		size_log2++;
	}
	return (false);
}
