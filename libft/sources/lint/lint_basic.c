/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:08:57 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:58 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** - lint_clear() function makes lint pozitive, zero-length and sets all
**   the limbs to 0. Returns nothing.
**
** - lint_assign() function makes lint pointed to by dst of an usisnged integer
**   within t_dlimb size value, pozitive or negative depending on sign
**   (1 = "plus", -1 = "minus").
**
** - lint_copy() function copies src lint ot dst. Actually one can copy a lint
**   with simple assignment: a = b, where b - source, a - destination.
*/

#include "lint.h"

void	lint_clear(t_lint *dst)
{
	t_count	i;

	i = -1;
	dst->sign = 1;
	dst->size = 0;
	while (++i < SIZE)
		dst->limb[i] = 0;
}

void	lint_assign(t_lint *dst, t_dlimb src, t_sign sign)
{
	dst->limb[0] = (t_limb)src;
	dst->limb[1] = (t_limb)(src >> LSIZE);
	dst->sign = sign < 0 ? -1 : 1;
	dst->size = 2;
	dst->size = lint_normsize(dst);
}

t_size	lint_normsize(t_lint *src)
{
	t_count	i;

	i = src->size;
	while (--i >= 0 && !src->limb[i])
		;
	return (i + 1);
}

void	lint_copy(t_lint *dst, t_lint *src)
{
	t_count	i;

	i = -1;
	while (++i < src->size)
		dst->limb[i] = src->limb[i];
	dst->size = i;
	dst->sign = src->sign;
}
