/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:59:16 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:51:02 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strequ() function compares the two strings s1 and s2.
**
** RETURN VALUE
** The ft_strequ() function returns 1 if the strings are equal, otherwise it
** returns 0.
**
** COMMENT
** Actually the function is identical to ft_strcmp() but the value to return is
** modified a little.
** (the following conditions are to pass the 42-FileChecker test)
** If either s1 or s2 points to NULL the function returns 0. If both s1 and s2
** point to NULL the function returns 1. So unexpected behavior is unlikely to
** happen.
*/

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	return ((s1 && s2 && !ft_strcmp(s1, s2)) || (!s1 && !s2) ? 1 : 0);
}
