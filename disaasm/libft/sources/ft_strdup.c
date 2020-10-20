/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:04:42 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:50:55 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strdup() function duplicates the string s1. Memory for the new string
** is obtained with malloc(3), and can be freed with free(3).
**
** RETURN VALUE
** On success, the ft_strdup() function returns a pointer to the duplicated
** string. It returns NULL if the allocation fails.
**
** COMMENT
** The original strdup() function puts errno from errno.h to ENOMEM if
** insufficient memory available to allocate duplicate string. But as using
** anything else except includes string.h and stdlib.h is forbidden according
** to the task (inspite of the fact that it is successfully accepted
** by MOULINETTE), I decided not to use it. As a matter of fact, Libftest
** doesn't allow us to put errno.h.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		ft_strcpy(s2, s1);
	return (s2);
}
