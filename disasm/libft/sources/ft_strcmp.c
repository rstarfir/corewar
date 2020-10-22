/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:05:05 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:50:34 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strcmp() function compares the two strings s1 and s2.
**
** RETURN VALUE
** The ft_strcmp() function returns an integer less tnan, equal to, or greater
** than zero if s1 is found, respectively, to be less than, to match, or be
** greater than s2.
**
** COMMENT
** If s1 or s2 points to NULL, the behavior is undefined.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2 && s1++ && s2++)
		;
	return ((int)(*s1) - (int)(*s2));
}
