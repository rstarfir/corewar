/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:31 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:49:40 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putnbr_fd() function ouputs the integer n to the file descriptor fd.
**
** RETURN VALUE
** Nothing.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		buf[16];
	int			i;
	unsigned	f;

	i = 16;
	f = n;
	while ((int)(buf[--i] = f % 10 + '0') && f / 10 > 0)
		f /= 10;
	if (n < 0)
		buf[--i] = '-';
	write(fd, buf + i, 16 - i);
}
