/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:28:46 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:17 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memmove() function copies len bytes from memory area src to memory
** area dst. The memory areas may overlap.
**
** RETURN VALUE
** The ft_memmove() function returns a pointer to dst.
**
** COMMENT
** All the cases with NULL-pointers are processed by ft_memcpy() to meet
** 42-FileChecker requirements.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char*)dst + len;
	s = (unsigned const char*)src + len;
	if (src && (src < dst))
		while (len-- > 0)
			*--d = *--s;
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
