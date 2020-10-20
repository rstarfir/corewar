/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:07:28 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:10 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strnequ() function compares the first (at most) n bytes of the two
** strings s1 and s2.
**
** RETURN VALUE
** The ft_strnequ() function returns 1 if the first n bytes of the strings are
** found equal, otherwise it returns 0.
**
** COMMENT
** Actually the function is identical to ft_strncmp() but the value to return is
** modified a little.
** (the following conditions are to pass the 42-FileChecker test)
** If either s1 or s2 points to NULL the function returns 0. If both s1 and s2
** point to NULL the function returns 1. So unexpected behavior is unlikely to
** happen.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return ((s1 && s2 && !ft_strncmp(s1, s2, n)) || (!s1 && !s2) ? 1 : 0);
}
