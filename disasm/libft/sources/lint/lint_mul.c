/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:49 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:56:55 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** - lint_mul() function multiplies lints pointed at by a and b and assigns the
**   result to res. a and b can point to the same lint.
**
** - lint_mul_1() function multiplies lint pointed at by a and limb b and
**   assigns the result to res.
**
** COMMENT
** The operations can be done in-place.
*/

#include "lint.h"

static void	lint_add_sh(t_lint *res, t_lint *a, t_lint *b, t_size sh)
{
	t_limb	carry;
	t_limb	tmp;
	t_size	bigger_size;
	t_count	i;

	i = -1;
	carry = 0;
	bigger_size = a->size > b->size + sh ? a->size : b->size + sh;
	while (++i < sh)
		res->limb[i] = a->limb[i];
	while (i < bigger_size || carry)
	{
		tmp = a->limb[i] + b->limb[i - sh] + carry;
		carry = ((a->limb[i] & b->limb[i - sh]) | ((a->limb[i] |
						b->limb[i - sh]) & (~tmp))) >> (LSIZE - 1);
		res->limb[i++] = tmp;
	}
	res->size = i;
}

void		lint_mul_1(t_lint *res, t_lint *a, t_limb b)
{
	t_dlimb s_;
	t_count	i;

	i = -1;
	s_ = 0;
	while (++i < a->size)
	{
		s_ += (t_dlimb)a->limb[i] * b;
		res->limb[i] = (t_limb)s_;
		s_ >>= LSIZE;
	}
	res->limb[i++] = (t_limb)s_;
	res->size = i;
	res->size = lint_normsize(res);
	res->sign = a->sign;
}

void		lint_mul(t_lint *res, t_lint *a, t_lint *b)
{
	t_lint	add_res;
	t_lint	mul_res;
	t_count	i;

	i = -1;
	lint_clear(&add_res);
	while (++i < b->size)
	{
		lint_mul_1(&mul_res, a, b->limb[i]);
		lint_add_sh(&add_res, &add_res, &mul_res, i);
	}
	add_res.sign = a->sign * b->sign;
	lint_copy(res, &add_res);
}
