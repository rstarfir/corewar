/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:11:34 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:52:57 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strncmp() function compares the first (at most) n bytes of the two
** strings s1 and s2.
**
** RETURN VALUE
** The ft_strncmp() function returns an integer less tnan, equal to, or greater
** than zero if the first n bytes of s1 are found, respectively, to be less
** than, to match, or be greater than those of s2.
**
** COMMENT
** If n is zero the strings are considered equal. If s1 or s2 points to NULL,
** the behavior is undefined.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && *s1 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
