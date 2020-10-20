/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:30:01 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:49:32 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putnbr() function ouputs the integer n to the standard output.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** The ft_putnbr() is ft_putnbr_fd() with fd equal to 1.
*/

#include "libft.h"

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
