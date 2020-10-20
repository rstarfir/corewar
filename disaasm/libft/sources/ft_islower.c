/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:15:24 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:09 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_islower() function checks for a lowercase letter.
**
** RETURN VALUE
** The ft_islower() function returns a non zero value if the character c is a
** lowercase letter, and zero if not.
**
** COMMENT
** Only C locale.
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
