/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:26:56 by rstarfir          #+#    #+#             */
/*   Updated: 2020/10/22 16:27:04 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_uint		reverse_byte_by_byte_int(t_uint num)
{
	t_uint	rev;

	rev = ((num & 0xFF) << 24) | ((num & 0xFF00) << 8) |
	((num & 0xFF0000) >> 8) | ((num & 0xFF000000) >> 24);
	return (rev);
}

t_ushort	reverse_byte_by_byte_short(t_ushort num)
{
	return ((num << 8) | (num >> 8));
}

void		print_binary_uchar(t_uchar n)
{
	t_uchar mask;

	mask = 1 << 7;
	while (mask)
	{
		if (n & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}

void		print_binary_uint(t_uint n)
{
	t_uint mask;

	mask = 1 << 31;
	while (mask)
	{
		if (n & mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
	}
	printf("\n");
}

void		print_binary_short(short n)
{
	unsigned short mask;

	mask = 1 << 15;
	while (mask)
	{
		if (n & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (mask == 256)
			write(1, " ", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}
