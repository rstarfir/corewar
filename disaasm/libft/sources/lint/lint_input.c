/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:25 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:56:49 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The lint_read() converts the initial portion of the string pointed to by str
** to lint.
**
** RETURN VALUE
** The converted value.
**
** COMMENT
** Similar to ft_atoi() function.
*/

#include "lint.h"

t_lint	lint_read(char *str)
{
	t_lint	res;
	t_sign	sign;

	sign = 1;
	lint_clear(&res);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		lint_mul_1(&res, &res, 10);
		lint_add_1(&res, &res, *str++ - '0');
	}
	res.sign = sign;
	return (res);
}
