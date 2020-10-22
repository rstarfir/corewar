/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:20:06 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:54:47 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_toupper() function converts lowercase letters to uppercase.
**
** RETURN VALUE
** The ft_toupper() function returns an uppercase equivalent if c is a lowercase
** letter. Otherwise it returns c.
**
** COMMENT
** Only C locale.
*/

int	ft_toupper(int c)
{
	return (c >= 'a' && c <= 'z' ? c - 32 : c);
}
