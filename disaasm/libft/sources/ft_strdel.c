/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:42:02 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:50:47 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strdel() function frees the string pointed to by as and puts as to
** NULL.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** The behavior is identical to ft_memdel().
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}
