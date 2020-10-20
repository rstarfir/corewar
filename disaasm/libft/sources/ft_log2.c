/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:59:39 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:47 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_log2() function finds the log base 2 of an integer with a lookup table
** g_log2[256].
**
** RETURN VALUE
** The ft_log2() function returns 8 bits log base two (floored).
**
** COMMENT
** http://graphics.stanford.edu/~seander/bithacks.html#IntegerLogLookup
*/

#include "libft.h"

static const uint8_t	g_log2[256] =
{
	0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

uint8_t	ft_log2(uint64_t x)
{
	uint64_t	tmp;

	if ((tmp = x >> 56))
		return (56 + g_log2[tmp]);
	if ((tmp = x >> 48))
		return (48 + g_log2[tmp]);
	if ((tmp = x >> 40))
		return (40 + g_log2[tmp]);
	if ((tmp = x >> 32))
		return (32 + g_log2[tmp]);
	if ((tmp = x >> 24))
		return (24 + g_log2[tmp]);
	if ((tmp = x >> 16))
		return (16 + g_log2[tmp]);
	if ((tmp = x >> 8))
		return (8 + g_log2[tmp]);
	return (g_log2[x]);
}
