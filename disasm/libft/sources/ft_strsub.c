/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:11:47 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:54:11 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strsub() function allocates (with malloc(3) - actually with
** ft_strnew0()) and returns a "fresh" substring from the string pointed to by
** s. The substring begins at index start and is of size len.
**
** RETURN VALUE
** The ft_strsub() function returns a pointer to the substring.
**
** COMMENT
** If start and len aren't reffering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
** len is unlikely to be SIZE_MAX (stdint.h), otherwise the function returns
** NULL (as ft_strnew() will return NULL).
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *t;

	return (s && (t = ft_strnew0(len)) ? ft_memmove(t, s + start, len) : NULL);
}
