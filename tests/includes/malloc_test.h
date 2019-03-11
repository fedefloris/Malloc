/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2019/01/29 20:53:38 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_TEST_H
# define MALLOC_TEST_H

# include "malloc.h"

# define ERROR_COLOR "\033[1;31m"
# define STANDARD_COLOR "\033[0m"

# define ERROR_MESSAGE_HEADER "  Error: "
# define EXIT_ERROR_STATUS 1
# define STD_ERROR 2

typedef enum	e_block_status
{
	Free,
	Allocated
}
				t_block_status;

void			test_free(void);
void			test_malloc(void);

void			error_exit(char *message);

void			test_block(void *ptr, size_t size,
					t_block_status status);

bool			is_block_in_bucket(t_block *block, t_zone *zone,
					int zone_type);

#endif
