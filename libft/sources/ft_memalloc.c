/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:01:00 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:39 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memalloc() function allocates (with malloc(3)) and returns a "fresh"
** memory area of size "size". The memory allocated is initialized to 0.
**
** RETURN VALUE
** The ft_memalloc() function returns a pointer to the allocated memory.
**
** COMMENT
** If the allocation fails or size is equal to zero, the function returns NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = size ? malloc(size) : NULL;
	return (tmp ? ft_memset(tmp, 0, size) : NULL);
}
