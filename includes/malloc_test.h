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

# define ERROR_MESSAGE_HEADER "Error: "
# define EXIT_ERROR_STATUS 1
# define STD_ERROR 2

typedef enum    e_block_status
{
	Free,
	Allocated
}
				t_block_status;

void			error_exit(char *message);

void			test_block(void *ptr, size_t size,
					t_block_status status);
void			test_block_header(void *ptr, size_t size,
					t_block_status status);

#endif
