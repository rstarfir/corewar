/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:48:38 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:52:39 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strmapi() function applies the function f() to each character of the
** string s, when its index is passed to the function f() too, to create a
** "fresh" new string (with malloc(3) - actuall with ft_strnew0()) resulting
** from the successive application of f().
**
** RETURN VALUE
** The ft_strmapi() function returns a pointer to the new string.
**
** COMMENT
** If s or f() points to NULL or allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*tmp1;
	char			*tmp2;
	unsigned int	i;

	tmp1 = NULL;
	i = -1;
	if (s && f)
		if ((tmp1 = ft_strnew0(ft_strlen(s))))
		{
			tmp2 = tmp1;
			while (*s)
				*tmp2++ = f(++i, *s++);
		}
	return (tmp1);
}
