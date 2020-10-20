/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:20:54 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:49:48 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putstr() function ouputs the string s to the standard output.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** The ft_putstr() is ft_putstr_fd() with fd equal to 1. If s points to NULL,
** the function does nothing.
*/

#include "libft.h"

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}
