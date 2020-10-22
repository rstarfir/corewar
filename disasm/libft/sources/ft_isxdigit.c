/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:56:52 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:46:33 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isxdigit() function checks c for hexidecimal digits (0-9, A-F, a-f).
**
** RETURN VALUE
** The ft_isxdigit() function returns a non zero value if the character c is a
** hexidecimal digit character, and zero if not.
*/

#include "libft.h"

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
