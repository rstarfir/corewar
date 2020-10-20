/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:14:25 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:24 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memset() function fills the first len bytes of the memory area pointed
** to by b with the constant byte c.
**
** RETURN VALUE
** The ft_memset() function returns a pointer to the memory area b.
**
** COMMENT
** If b points to NULL the behavior is undefined. If len is equal to zero the
** ft_memset() does nothing.
** The function is unlikely to work properly with a locale different from C.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned char	ch;

	tmp = (unsigned char*)b;
	ch = (unsigned char)c;
	while (len-- > 0)
		*tmp++ = ch;
	return (b);
}
