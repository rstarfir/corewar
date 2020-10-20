/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:32:25 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:53:16 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strnew() function allocates (with malloc(3)) and returns a "fresh"
** string ending with '\0'. Each character of the string is initialized at '\0'.
**
** RETURN VALUE
** The ft_strnew() function returns a pointer to the string.
**
** COMMENT
** If the allocation fails or if size equal to SIZE_MAX (stdint.h) the function
** returns NULL (as size + 1 = 0 passed to ft_memalloc() which will return
** NULL). If size is equal to zero a one byte ('\0') string will be created.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}

/*
** The ft_strnew0() function is the same but doesn't set all the chars with
** '\0', but only the last one.
*/

char	*ft_strnew0(size_t size)
{
	char	*str;

	if (!(size + 1))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	return (str);
}
