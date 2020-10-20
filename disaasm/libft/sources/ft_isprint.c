/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:19:27 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:14 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isprint() function checks for any printable character including space.
**
** RETURN VALUE
** The ft_isprint() function returns a non zero value if the character c is
** printable, and zero if not.
*/

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
