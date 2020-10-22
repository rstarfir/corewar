/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:17:28 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:59 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memcmp() function compares the first n bytes (each interpreted as
** unsigned char) of the memory areas s1 and s2.
**
** RETURN VALUE
** The ft_memcmp() function returns an integer less than, equal to, or greater
** than zero if the first n bytes of s1 is found, respectively, to be less than,
** to match, or be greater than the first n bytes of s2.
**
** COMMENT
** If s1 or s2 or both NULL the behavior is undefined but if n is equal to zero
** the function returns 0.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *b1;
	unsigned const char *b2;

	if (n == 0)
		return (0);
	b1 = (unsigned const char *)s1;
	b2 = (unsigned const char *)s2;
	while (n-- > 1 && *b1 == *b2 && b1++ && b2++)
		;
	return (*b1 - *b2);
}
