/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:46:01 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:00:22 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_str() function is called by hub() in case of str-type.
**
** RETURN VALUE
** The function returns the length of the resulting string or -1 in case of an
** error.
*/

#include "ft_printf.h"
#include "wc.h"

static int	str_str(char **str, char *src, t_fs *fs)
{
	t_bf	bf;
	int		i;

	if (!(bf.b = src ? src : ft_strdup("(null)")))
		return (-1);
	bf.i = ft_strlen(bf.b);
	i = res_string(str, &bf, fs, fa_str);
	src ? 0 : free(bf.b);
	return (i);
}

static int	str_wstr(char **str, wchar_t *src, t_fs *fs)
{
	t_bf	bf;
	int		i;

	if (src)
	{
		if ((i = wcs_get(src, &bf.b)) < 0)
			return (-1);
		bf.i = i;
	}
	else
	{
		if (!(bf.b = ft_strdup("(null)")))
			return (-1);
		bf.i = ft_strlen(bf.b);
	}
	i = res_string(str, &bf, fs, fa_str);
	free(bf.b);
	return (i);
}

int			hub_str(char **str, va_list ap, t_fs *fs)
{
	if (fs->t == 'S')
		fs->s = 'l';
	if (fs->s == 'l')
		return (str_wstr(str, (wchar_t*)va_arg(ap, wint_t*), fs));
	else
		return (str_str(str, va_arg(ap, char*), fs));
}
