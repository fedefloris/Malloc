/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:53:38 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include <stdbool.h>
# include <pthread.h>
# include <sys/mman.h>

typedef struct		s_block
{
	uint8_t			size_log2;
	char			padding[7];
	struct s_block	*next;
}					t_block;

typedef struct		s_zone
{
	size_t			size;
	struct s_zone	*next;
	size_t			max_blocks;
	size_t			max_blocks_count;
}					t_zone;

/*
** Block sizes as a power of 2.
*/
# define MINIMUM_LOG2 5
# define TINY_MAX_LOG2 11
# define SMALL_MAX_LOG2 16

# define BLOCK_SIZE(size_log2) (1 << (size_log2))
# define ROUND_UP(from, to) ((int)round_up_to(from, to))
# define BUDDY(addr, block, size) (((block - addr) ^ BLOCK_SIZE(size)) + addr)

/*
** TINY_BUCKETS_SIZE and SMALL_BUCKETS_SIZE must be multiple of 16
** otherwise they'll break the 16-bytes alignment.
*/

# define TINY_BUCKETS_SIZE ROUND_UP(sizeof(t_block*) * (TINY_MAX_LOG2 + 1), 16)
# define TINY_ZONE_HEADER_SIZE ((int)sizeof(t_zone) + TINY_BUCKETS_SIZE)

# define SMALL_BUCKETS_SIZE ROUND_UP(sizeof(t_block*) * (SMALL_MAX_LOG2+ 1), 16)
# define SMALL_ZONE_HEADER_SIZE ((int)sizeof(t_zone) + SMALL_BUCKETS_SIZE)

# define LARGE_ZONE_HEADER_SIZE sizeof(t_zone)

/*
** Zone memory management:
**   - Less than or equal to TINY_THRESHOLD in TINY_ZONE_SIZE bytes zone.
**   - From (TINY_THRESHOLD + 1) to SMALL_THRESHOLD included
**       in SMALL_ZONE_SIZE bytes zone.
**   - From (SMALL_THRESHOLD + 1) dedicate a large zone
*/

# define TINY_THRESHOLD (1 << TINY_MAX_LOG2)
# define TINY_ZONE_SIZE (TINY_THRESHOLD * 100 + TINY_ZONE_HEADER_SIZE)

# define SMALL_THRESHOLD (1 << SMALL_MAX_LOG2)
# define SMALL_ZONE_SIZE (SMALL_THRESHOLD * 100 + SMALL_ZONE_HEADER_SIZE)

# define LARGE_THRESHOLD (SMALL_THRESHOLD + 1)

typedef struct		s_zones
{
	char			empty_malloc[1];
	t_zone			*tinies;
	t_zone			*smalls;
	t_zone			*larges;
}					t_zones;

extern t_zones			g_zones;
extern pthread_mutex_t	g_mutex;

void				*malloc(size_t size);
void				*calloc(size_t elements_count, size_t element_size);
void				*realloc(void *ptr, size_t size);

void				*allocate(size_t size);
void				*allocate_small(size_t size, int zone_size);
void				*allocate_large(size_t size);

t_block				*get_block(int zone_size, int size_log2);
t_block				*get_block_from_zones(t_zone *zones,
						int zone_size, int size_log2);
t_block				*get_block_from_zone(t_zone *zone,
						int zone_size, int size_log2);

t_block				*get_block_info(void *ptr, t_zone **zone,
						int *zone_type);
bool				is_block_in_bucket(t_block *block, t_zone *zone,
						int zone_type);
bool				find_block(t_block *blocks, t_block *block,
						t_block **prev);

t_zone				*add_zone(int zone_type, size_t size);
void				remove_zone(t_zone *zone, int zone_type);
t_zone				**get_zones(int zone_type);

void				add_first_blocks(t_zone *zone, int zone_type);

int					get_size_log2(size_t request);
size_t				round_up_to(size_t from, size_t to);

void				free(void *ptr);
void				free_block(void *ptr);
bool				free_large_block(void *ptr);
void				free_small_block(t_block **blocks, t_block **block,
						int max_log2);

void				show_alloc_mem();
void				display_zones(t_zone *zone, int zone_type);

#endif
