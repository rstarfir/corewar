/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:12:42 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:03 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strncpy() function copies at most len bytes (including '\0' if it is
** presented within len bytes) of the string pointed to by src to the buffer
** pointed to by dst which must be large enough to receive the copy.
**
** RETURN VALUE
** The ft_strncpy() function returns a pointer to the destination string dst.
**
** COMMENT
** If the length of src is less than len, the function writes additional null
** bytes to dst to ensure that a total of n bytes are written.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (len-- > 0)
		*d++ = *src ? *src++ : '\0';
	return (dst);
}
