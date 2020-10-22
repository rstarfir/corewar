/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:21:05 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:52:51 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strncat() function appends at most n bytes of the s2 string to the s1
** string, which must be large enough to receive it, overwriting the terminating
** null byte ('\0') at the end of s1, and then adds a terminating null byte.
**
** RETURN VALUE
** The ft_strncat() function returns a pointer to the resulting string dst.
**
** COMMENT
** If dst is not large enough, the behavior is unpredictable.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while (n-- > 0 && *s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (s1);
}
