/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:51:26 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:52:00 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_striteri() function applies the function f() to each character of the
** string s, when its index is passed to the function f() too.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If s or f() points to NULL nothing happens.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = -1;
	if (s && f)
		while (*s)
			f(++i, s++);
}
