/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:43 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:44 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strsplit() function allocates (with malloc(3)) and returns an array of
** "fresh" strings (all ending with '\0', including the array itself) obtained
** by splitting s using the character c as a delimiter.
**
** RETURN VALUE
** The ft_strsplit function returns the array of "fresh" strings result of the
** split.
**
** COMMENT
** If s points to NULL, the function returns NULL. If the allocation fails all
** the memory previously allocated is freed and the function returns NULL.
*/

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s && *s)
		if (*s++ != c && (*s == c || *s == '\0'))
			i++;
	return (i);
}

static size_t	find_word(char **s, char **beg, char c)
{
	while (**s == c)
		(*s)++;
	*beg = *s;
	while (**s && **s != c)
		(*s)++;
	return (*s - *beg);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**b;
	char	**t;
	char	*beg;
	size_t	len;

	if (!s || !(b = (char**)malloc(sizeof(char*) * (wc(s, c) + 1))))
		return (NULL);
	t = b;
	while ((len = find_word((char**)&s, &beg, c)))
	{
		if (!(*b++ = ft_strsub(beg, 0, len)))
		{
			while (*t)
				free(*t++);
			free(t);
			return (NULL);
		}
	}
	*b = NULL;
	return (t);
}
