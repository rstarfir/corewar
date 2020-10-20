/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:11:52 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:28 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isupper() function checks for an uppercase letter.
**
** RETURN VALUE
** The ft_isupper() function returns a non zero value if the character c is an
** uppercase letter, and zero if not.
**
** COMMENT
** Only C locale.
*/

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
