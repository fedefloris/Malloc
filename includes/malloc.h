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

# define TINY_SIZE 100 // from 1 to N bytes
# define SMALL_SIZE 180 // from (N + 1) to M bytes
# define LARGE_SIZE MMAP_THRESHOLD // from (M + 1) bytes

typedef struct		s_block
{
	size_t			size;
	int				is_free;
	struct s_block	*next;
}					t_block;

typedef struct		s_zones
{
	t_block			*tinies;
	t_block			*smalls;
	t_block			*larges;
}					t_zones;

extern t_zones		g_zones;

void				free(void *ptr);

void				*malloc(size_t size);
void				*malloc_tiny(size_t size);
void				*malloc_small(size_t size);
void				*malloc_large(size_t size);

void				*realloc(void *ptr, size_t size);

t_block				*get_free_block(size_t size, int zone_type);

void				show_alloc_mem();

#endif
