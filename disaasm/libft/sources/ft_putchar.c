/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:19:57 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:34 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putchar() function ouputs the character c to the standard output.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** The ft_putchar() is ft_putchar_fd() with fd equal to 1.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}
