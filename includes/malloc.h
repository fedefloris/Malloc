/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include <stdbool.h>
# include <sys/mman.h>

/*
** Zone memory management:
**   - From 1 to TINY_THRESHOLD in TINY_ZONE_SIZE bytes zones.
**   - From (TINY_THRESHOLD + 1) to SMALL_THRESHOLD
**       in SMALL_ZONE_SIZE bytes zones,
**   - From (M + 1) dedicate a large zone
*/

# define TINY_THRESHOLD 100
# define TINY_ZONE_SIZE 1000

# define SMALL_THRESHOLD 500
# define SMALL_ZONE_SIZE 5000

// Note: MMAP_THRESHOLD is 128 kB by default
# define LARGE_THRESHOLD 2400

/*
** Block contains flags contained inside at least 4 bytes:
**
**   0000 000_ block state (free or not free)
**   0000 00_0 left or right child of binary tree
**   ____ __00 size of the block as power of 2
**
**   The size range from 0 to (2 ^ size) - 1
*/
typedef struct		s_block
{
	unsigned char	state : 1;
	unsigned char	left : 1;
	unsigned char	size : 6;
}					t_block;

typedef struct		s_zone
{
	size_t			size;
	struct s_zone	*next;
}					t_zone;

/*
** Pointers to first elements of zones
*/
typedef struct		s_zones
{
	t_zone			*tinies;
	t_zone			*smalls;
	t_zone			*larges;
}					t_zones;

extern t_zones		g_zones;

void				*malloc(size_t size);
void				*malloc_small(size_t size, int zone_size);
void				*malloc_large(size_t size);

void				*calloc(size_t elements_count, size_t element_size);
void				*realloc(void *ptr, size_t size);

void				*get_block_from_zones(t_zone *zones, int power_of_2);

size_t				round_up_to_page_size(size_t size);

void				free(void *ptr);
bool				free_large_block(void *ptr);

void				show_alloc_mem();
void				display_zone(t_zone *zone, char *zone_name);

#endif
