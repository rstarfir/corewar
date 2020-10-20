/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:32:54 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:44:45 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_atoi() converts the initial portion of the string pointed to by str to
** int.
**
** RETURN VALUE
** The converted value.
**
** COMMENT
** If str points to NULL, the behavior is undefined. The function passes the
** initial portion of spaces (defined in ft_isspace()), recognizes the sign if
** it is presented (one and only), converts the digits following straight
** after and terminates when the first non-digit character is found (including
** '\0').
** Using __int128_t instead of int is to reproduce lib atoi() behavior when
** long long is overflowed: the functions returns -1 in case of overflowing and
** 0 in case of underflowing.
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	__int128_t	f;
	int			sign;

	f = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while (ft_isdigit(*str) && f <= LLONG_MAX)
		f = (f << 3) + (f << 1) + *str++ + (~0x30 + 1);
	if (f > LLONG_MAX)
		f = sign < 0 ? 0 : -1;
	return (f * sign);
}
