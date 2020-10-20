/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:24:33 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:11 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memdel() function frees the memory pointed to by the pointer ap and
** puts ap to NULL.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If the address of the pointer ap is NULL or if it points to NULL nothing
** happens.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
