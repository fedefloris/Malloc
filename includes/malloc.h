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
** 8-bytes aligned
*/
typedef struct		s_block
{
	bool			free;
	bool			left;
	unsigned char	size;
	char			padding[4];
}					t_block;

typedef struct		s_zone
{
	size_t			size;
	struct s_zone	*next;
}					t_zone;

/*
** Zone memory management:
**   - From 1 to TINY_THRESHOLD in TINY_ZONE_SIZE bytes zones.
**   - From (TINY_THRESHOLD + 1) to SMALL_THRESHOLD
**       in SMALL_ZONE_SIZE bytes zones,
**   - From (M + 1) dedicate a large zone
*/

# define TINY_THRESHOLD (64 - sizeof(t_block))
# define TINY_ZONE_SIZE (8192 - sizeof(t_zone))
# define TINY_BLOCK_LOG2 13

# define SMALL_THRESHOLD (128 - sizeof(t_block))
# define SMALL_ZONE_SIZE (8192 - sizeof(t_zone))
# define SMALL_BLOCK_LOG2 14

/*
** Note: MMAP_THRESHOLD is 128 kB by default
*/
# define LARGE_THRESHOLD 1024 + sizeof(t_block)

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

void				free(void *ptr);
bool				free_large_block(void *ptr);

void				show_alloc_mem();
void				display_zones(t_zone *zone, char *zones_name);

int					get_size_log2(size_t request);
size_t				round_up_to_page_size(size_t size);

t_zone				*add_zone(int zone_type, size_t size);
#endif
