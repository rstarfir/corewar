/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:36:14 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:45 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memccpy() copies no more than n bytes from memory area src to memory
** area dst, stopping when the character c is found in src.
**
** RETURN VALUE
** The ft_memccpy() function returns a pointer to the next character in dst
** after c, or NULL if c was not found in the first n characters of src.
**
** COMMENT
** If one and only one of the pointers is NULL the behavior is undefined. If
** both of them are NULL the ft_memccpy() just returns NULL without copying.
** (the conditions above were used to meet the 42-FileChecker requirements).
** If n is equal to zero copying doesn't occur and the function returns NULL.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		ch;

	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	ch = (unsigned char)c;
	if (s || d)
		while (n-- > 0)
		{
			*d++ = *s;
			if (*s++ == ch)
				return ((void*)d);
		}
	return (NULL);
}
