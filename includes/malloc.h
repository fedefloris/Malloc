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
# include <sys/mman.h>

/*
** Alignment? 16?
*/
typedef struct		s_block
{
	// struct s_block	*next; // Do I need it?
	// struct s_block	*prev; // Do I need it?
	uint8_t			size_log2;
	char			padding[7];
}					t_block;

typedef struct		s_zone
{
	size_t			size;
	struct s_zone	*next;
}					t_zone;

# define MINIMUM_LOG2 2
# define TINY_MAX_LOG2 10
# define SMALL_MAX_LOG2 15
# define BLOCK_SIZE(size_log2) (1 << size_log2)
# define BUDDY(addr, block, size) (((block - addr) ^ BLOCK_SIZE(size)) + addr)

/*
** Bucket of free blocks used by the buddy allocator
*/
typedef struct		s_tiny_blocks
{
	t_block			*free_blocks[TINY_MAX_LOG2 + 1];
}					t_tiny_blocks;

typedef struct		s_small_blocks
{
	t_block			*free_blocks[SMALL_MAX_LOG2 + 1];
}					t_small_blocks;

/*
** Header sizes
*/
# define BLOCK_HEADER_SIZE sizeof(t_block)
# define ZONE_HEADER_SIZE sizeof(t_zone)
# define TINY_ZONE_HEADER_SIZE (ZONE_HEADER_SIZE + sizeof(t_tiny_blocks))
# define SMALL_ZONE_HEADER_SIZE (ZONE_HEADER_SIZE + sizeof(t_small_blocks))

/*
** Zone memory management:
**   - Less than or equal to TINY_THRESHOLD in TINY_ZONE_SIZE bytes zone.
**   - From (TINY_THRESHOLD + 1) to SMALL_THRESHOLD included
**       in SMALL_ZONE_SIZE bytes zone.
**   - From (SMALL_THRESHOLD + 1) dedicate a large zone
*/

# define TINY_THRESHOLD ((1 << TINY_MAX_LOG2) - BLOCK_HEADER_SIZE)
# define TINY_ZONE_SIZE (TINY_THRESHOLD * 100 + TINY_ZONE_HEADER_SIZE)

# define SMALL_THRESHOLD ((1 << SMALL_MAX_LOG2) - BLOCK_HEADER_SIZE)
# define SMALL_ZONE_SIZE (SMALL_THRESHOLD * 100 + SMALL_ZONE_HEADER_SIZE)

# define LARGE_THRESHOLD (SMALL_THRESHOLD + 1)

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

t_block				*find_block(void *ptr);
void				merge_free_blocks(t_block *block);
t_block				*get_block(int zone_size, int size_log2);
t_block				*get_block_from_zones(t_zone *zones, int size_log2);
t_block				*get_block_from_zone(t_zone *zone, int size_log2);
void				add_first_block(t_zone *zone, int zone_type);

void				free(void *ptr);
bool				free_large_block(void *ptr);

void				show_alloc_mem();
void				display_zones(t_zone *zone, char *zones_name);

int					get_size_log2(size_t request);
size_t				round_up_to_page_size(size_t size);

t_zone				*add_zone(int zone_type, size_t size);
#endif
