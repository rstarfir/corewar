/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:17:20 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:02 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isdigit() function checks c for a digit (0 through 9).
**
** RETURN VALUE
** The ft_isdigit() function returns a non zero value if the character c is a
** digit character, and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
