/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:00:42 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:28 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strnstr() function finds the first occurence of the substring needle
** in the string haystack within the first len bytes.
**
** RETURN VALUE
** The ft_strnstr() function returns a pointer to the beginning of the located
** substring, or NULL if the substring is not found.
**
** COMMENT
** If haystack or neddle points to NULL, the behavior is undefined. If haystack
** points to an empty string ('\0') but needle doesn't, the function returns
** NULL. If needle points to an empty string, the function returns the pointer
** to the beginning of the original string haystack (even if haystack-string is
** just '\0');
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp1;
	const char	*tmp2;
	size_t		i;

	while (*haystack && len > 0)
	{
		tmp1 = haystack++;
		tmp2 = needle;
		i = len--;
		while (i-- > 0 && *tmp2 && *tmp1++ == *tmp2)
			tmp2++;
		if (!*tmp2)
			return ((char*)(haystack - 1));
	}
	return (*needle ? NULL : (char*)haystack);
}
