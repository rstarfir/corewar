/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:09:24 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:56:23 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** - lint_cmp() function compares lint a and b.
**
** - lint_cmp_abs() function compares absolute values of lint a and b.
**
** RETURN VALUE
** -1, 0 or 1 if a correspondingly less, equal or greater then b.
*/

#include "lint.h"

t_sign	lint_cmp_es(t_lint *a, t_lint *b)
{
	t_count	i;

	i = a->size;
	while (--i >= 0 && a->limb[i] == b->limb[i])
		;
	if (i < 0)
		return (0);
	else
		return (a->limb[i] < b->limb[i] ? -1 : 1);
}

t_sign	lint_cmp(t_lint *a, t_lint *b)
{
	t_size	ss_a;
	t_size	ss_b;

	ss_a = a->sign * a->size;
	ss_b = b->sign * b->size;
	if (ss_a > ss_b)
		return (1);
	else if (ss_a < ss_b)
		return (-1);
	else
		return (ss_a < 0 ? -lint_cmp_es(a, b) : lint_cmp_es(a, b));
}

t_sign	lint_cmp_abs(t_lint *a, t_lint *b)
{
	if (a->size > b->size)
		return (1);
	else if (a->size < b->size)
		return (-1);
	else
		return (lint_cmp_es(a, b));
}
