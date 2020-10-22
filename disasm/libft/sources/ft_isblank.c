/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:52:09 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:45:55 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isblank() function checks for a blank character (space and horizontal
** tab '\t').
**
** RETURN VALUE
** The ft_isblank() function returns a non zero value if the character c is a
** blank character, and zero if not.
*/

int		ft_isblank(int c)
{
	return (c == 9 || c == 32);
}
