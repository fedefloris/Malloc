/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:00:43 by ffloris           #+#    #+#             */
/*   Updated: 2019/03/16 15:00:45 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <string.h>

#define M (1000 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	int		i;
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjour\n");
	print(addr1);
	addr2 = (char*)malloc(16 * M);
	addr3 = (char*)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}
