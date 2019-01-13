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
# define SMALL_SIZE 100 // from (N + 1) to M bytes
# define LARGE_SIZE 100 // from (M + 1) bytes

typedef struct		s_block
{
	size_t			size;
	int				is_free;
	struct s_block	*next;
}					t_block;

extern t_block		*g_blocks;

void				free(void *ptr);

void				*malloc(size_t size);
void				*malloc_large(size_t size);

void				*realloc(void *ptr, size_t size);

void				show_alloc_mem();

#endif
