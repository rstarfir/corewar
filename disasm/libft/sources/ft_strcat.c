/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:12:04 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:50:13 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strcat() function appends the s2 string to the s1 string, which must
** be large enough to receive it, overwriting the terminating null byte ('\0')
** at the end of s1, and then adds a terminating null byte.
**
** RETURN VALUE
** The ft_strcat() function returns a pointer to the resulting string dst.
**
** COMMENT
** If dst is not large enough, the behavior is unpredictable.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while ((*tmp++ = *s2++))
		;
	return (s1);
}
