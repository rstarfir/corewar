/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:59:22 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:50:27 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_strclr() function clears the string s by filling it with '\0'.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If s points to NULL, nothing happens.
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
