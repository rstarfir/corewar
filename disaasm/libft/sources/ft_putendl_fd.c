/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:39:45 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:57 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_putendl_fd() function ouputs the string s to the file descriptor fd
** adding '\n' after it.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If s points to NULL, the functions does nothing.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
