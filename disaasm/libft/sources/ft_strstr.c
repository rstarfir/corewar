/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:54:34 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:54:02 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strstr() function finds the first occurence of the substring needle in
** the string haystack.
**
** RETURN VALUE
** The ft_strstr() function returns a pointer to the beginning of the located
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

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp1;
	const char	*tmp2;

	while (*haystack)
	{
		tmp1 = haystack++;
		tmp2 = needle;
		while (*tmp2 && *tmp1++ == *tmp2)
			tmp2++;
		if (!*tmp2)
			return ((char*)(haystack - 1));
	}
	return (*needle ? NULL : (char*)haystack);
}
