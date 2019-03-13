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

# define ERROR_MESSAGE_HEADER "  Error: "
# define EXIT_ERROR_STATUS 1

void			error_exit(char *message);

void			test_blocks(size_t block_size, size_t tests_count);
void			test_allocated_block(void *ptr, size_t size);

#endif
