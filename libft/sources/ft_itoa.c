/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:40:01 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:41 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_itao() function allocates and returns a string ending with
** '\0' representing the integer n.
**
** RETURN VALUE
** The ft_itoa() function returns a pointer to the string representing n.
**
** COMMENT
** If the allocation fails, the function returns NULL.
*/

#include "libft.h"

static int	nn(unsigned int n)
{
	int i;

	i = 1;
	while ((n /= 10) > 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	unsigned	f;
	int			e;
	char		*s;

	f = n;
	e = n < 0 ? nn(f) + 1 : nn(f);
	if ((s = malloc(sizeof(char) * (e + 1))))
	{
		s[e] = '\0';
		while ((int)(s[--e] = f % 10 + '0') && f / 10 > 0)
			f /= 10;
		if (n < 0)
			s[--e] = '-';
	}
	return (s);
}
