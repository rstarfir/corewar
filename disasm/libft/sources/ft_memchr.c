/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:41:00 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:53 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_memchr() function scans the initial n bytes of the memory area pointed
** to by s for the first instance of c. Both c and the bytes of the memory area
** pointed to by s are interpreted as unsigned char.
**
** RETURN VALUE
** The ft_memchr() function returns a pointer to the matching byte or NULL if
** the character doesn't occur in the given memory area.
**
** COMMENT
** If s points to NULL the behavior is undefined. If n is equal to zero the
** function returns NULL.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*b;
	unsigned char		ch;

	ch = (unsigned char)c;
	b = (unsigned const char*)s;
	while (n-- > 0)
		if (*b++ == ch)
			return ((void*)(b - 1));
	return (NULL);
}
