/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_zones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	get_zone_header_size(t_zone_type zone_type)
{
	if (IS_TINY_ZONE(zone_type))
		return (TINY_ZONE_HEADER_SIZE);
	else if (IS_SMALL_ZONE(zone_type))
		return (SMALL_ZONE_HEADER_SIZE);
	return (LARGE_ZONE_HEADER_SIZE);
}

static void		display_zone_header_hexdump(t_zone *zone,
	t_zone_type zone_type)
{
	char		*final_byte;
	char		*byte;

	byte = (char*)zone;
	final_byte = byte + get_zone_header_size(zone_type);
	ft_printf("  Header:        %zd bytes\n\n", final_byte - byte);
	ft_printf("  Zone header:   $red$red$eoc$\n");
	if (!IS_LARGE_ZONE(zone_type))
		ft_printf("  Buckets:       $yellow$yellow$eoc$\n\n");
	else
		ft_putstr("\n");
	ft_putstr("  ");
	while (byte < final_byte)
	{
		ft_printf((byte < (char*)(zone + 1))
			? "$red$" : "$yellow$");
		ft_printf("%08x ", *byte++);
		if (byte != final_byte
				&& ((intptr_t)byte - (intptr_t)zone) % 6 == 0)
			ft_printf("\n  ");
	}
	ft_printf("\n\n$eoc$");
}

static void		display_zone(t_zone *zone, t_zone_type zone_type,
	bool hexdump)
{
	ft_printf("\nZone: %p to %p   %12zu bytes\n\n",
		zone, (char*)zone + zone->size,
		zone->size, zone->next);
	if (hexdump)
		display_zone_header_hexdump(zone, zone_type);
	display_blocks(zone, zone_type, hexdump);
}

void			display_zones(t_zone *zone, t_zone_type zone_type,
	bool hexdump)
{
	while (zone)
	{
		display_zone(zone, zone_type, hexdump);
		zone = zone->next;
	}
	ft_putstr("\n");
}
