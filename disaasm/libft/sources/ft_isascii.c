/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:18:32 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:45:35 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isascii() function checks whether c is a 7-bit unsigned char value
** that fits into the ASCII character set.
**
** RETURN VALUE
** The ft_isascii() function returns a non zero value if the character c fits
** ASCII, and zero if not.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
