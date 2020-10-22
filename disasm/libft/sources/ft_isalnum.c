/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:18:01 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:45:20 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_isalnum() function checks c for an alphanumeric character.
**
** RETURN VALUE
** The ft_isalnum() function returns a non zero value if the character c is a
** alphanumeric character, and zero if not.
**
** COMMENT
** Only C locale.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
