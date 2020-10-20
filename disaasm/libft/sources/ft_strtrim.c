/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:55:39 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:54:19 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strtrim() function allocates (with malloc(3) - actually with
** ft_strsub()) and returns a copy of the string pointed to by s without
** whitespaces at the beginning or at the end of the string.
**
** RETURN VALUE
** The ft_strtrim() function returns the "fresh" trimmed string or a copy of s.
**
** COMMENT
** If the allocation fails or s points to NULL, the function returns NULL. If
** the input string is only made up of whitespaces or is empty the function
** returns a one-byte ('\0') string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*s1;
	char const	*s2;

	if (!s)
		return (NULL);
	s1 = s;
	while (*s1 && ft_isspace(*s1))
		s1++;
	s2 = s1;
	while (*s2)
		s2++;
	while (--s2 > s1 && ft_isspace(*s2))
		;
	return (ft_strsub(s1, 0, s2 - s1 + 1));
}
