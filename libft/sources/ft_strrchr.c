/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:48:40 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:34 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strrchr() function looks for the last occurence of character c in the
** string pointed by s.
**
** RETURN VALUE
** The ft_strrchr() function returns a pointer to the matched character or NULL
** if the character is not found.
**
** COMMENT
** "Character" means "byte". The terminating null byte is considered part of the
** string, so that if c is specified as '\0', this function returns a pointer to
** the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;
	char	ch;

	b = NULL;
	ch = (char)c;
	while (*s)
		if (*s++ == ch)
			b = (char*)(s - 1);
	return (c == '\0' ? (char*)s : b);
}
