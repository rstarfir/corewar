/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:40:38 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:51:10 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_striter() function applies the function f() to each character of the
** string s.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If s or f() points to NULL nothing happens.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
