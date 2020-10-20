/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:40:52 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:52:08 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strjoin() function allocates (with malloc(3) - actuall with
** ft_strnew0()) and returns a "fresh" string ending with '\0', result of the
** concatenation of s1 and s2.
**
** RETURN VALUE
** The ft_strjoin() function returns a pointer to the concatenated string.
**
** COMMENT
** (l1 + l2) >= l1 check for SIZE_MAX overflowing as a result of sum (that is
** nonsense, especially when SIZE_MAX is defined for 64-bit unsigned int).
** If both s1 and s2 point to NULL, the function returns NULL. If one of them
** points to NULL, the behavior is similar to ft_strdup() with a non-NULL
** pointer.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*b;
	size_t	l1;
	size_t	l2;

	b = NULL;
	l1 = s1 ? ft_strlen(s1) : 0;
	l2 = s2 ? ft_strlen(s2) : 0;
	if ((s1 || s2) && (l1 + l2) >= l1)
		b = ft_strnew0(l1 + l2);
	return (b ? (ft_memmove((ft_memmove(b, s1, l1) + l1), s2, l2) - l1) : b);
}
