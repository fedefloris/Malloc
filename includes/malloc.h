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
# include <sys/mman.h>

/*
** Zone memory management:
**   - From 1 to TINY_THRESHOLD in TINY_ZONE_SIZE bytes zones.
**   - From (TINY_THRESHOLD + 1) to SMALL_THRESHOLD
**       in SMALL_ZONE_SIZE bytes zones,
**   - From (M + 1) in LARGE_ZONE_SIZE bytes,
*/

# define TINY_THRESHOLD 100
# define TINY_ZONE_SIZE 1000

# define SMALL_THRESHOLD 500
# define SMALL_ZONE_SIZE 5000

# define LARGE_THRESHOLD 2400
# define LARGE_ZONE_SIZE 24000

typedef struct		s_block
{
	size_t			size;
	int				is_free;
	struct s_block	*next;
}					t_block;

typedef struct		s_zone
{
	t_block			*blocks;
	struct s_zone	*next;
}					t_zone;

typedef struct		s_zones
{
	t_zone			*tinies;
	t_zone			*smalls;
	t_zone			*larges;
}					t_zones;

extern t_zones		g_zones;

void				free(void *ptr);

void				*malloc(size_t size);
void				*malloc_small(size_t size, int zone_type);
void				*malloc_large(size_t size);

void				*realloc(void *ptr, size_t size);

t_block				*get_free_block(size_t size, int zone_type);
t_block				*get_new_block_from_system(int zone_type);
void				split_block_if_necessary(t_block *block, size_t size);

void				show_alloc_mem();
void				display_zone(t_block *blocks, char *zone_name);

#endif
