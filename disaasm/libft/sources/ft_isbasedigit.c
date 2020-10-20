/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbasedigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:45:41 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:45:42 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isbasedigit() takes a char C and checks if it is of base BASE.
**
** RETURN VALUE
** If BASE is not within 2..36 range, then -2 is returned. If C is out of
** current BASE, then -1 is returned. If C is in BASE, then positive or zero
** decimal equivalent is returned.
*/

#include "libft.h"

int				ft_isbasedigit(char c, int base)
{
	if (base < 2)
		return (-2);
	else if (base < 11)
		return (c >= '0' && c < '0' + base ? c - '0' : -1);
	else if (base < 37)
	{
		if (ft_isalpha(c))
		{
			c = 10 + ft_tolower(c) - 'a';
			return (c < base ? c : -1);
		}
		else if (ft_isdigit(c))
			return (c - '0');
		else
			return (-1);
	}
	else
		return (-2);
}
