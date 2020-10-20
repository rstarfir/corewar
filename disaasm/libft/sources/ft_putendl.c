/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:28:41 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:50 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putendl() function ouputs the string s to the standard output adding
** '\n' after it.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** The ft_putendl() is ft_putendl_fd() with fd equal to 1.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
