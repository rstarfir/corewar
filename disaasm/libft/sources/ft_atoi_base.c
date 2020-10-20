/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:17:53 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:44:55 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_atoi_base() converts the initial portion of the string pointed to by
** str in base BASE to int.
**
** RETURN VALUE
** The converted value.
**
** COMMENT
** The behaviour of the function equivalent to ft_atoi() function but uses
** ft_isbasedigit() to convert a char in base into decimal. If base is out of
** range 2..36 then 0 is returned.
*/

#include "libft.h"

int			ft_atoi_base(const char *str, int base)
{
	__int128_t	f;
	int			d;
	int			sign;

	f = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while ((d = ft_isbasedigit(*str++, base)) >= 0 && f <= LLONG_MAX)
		f = f * base + d;
	if (f > LLONG_MAX)
		f = sign < 0 ? 0 : -1;
	return (f * sign);
}
