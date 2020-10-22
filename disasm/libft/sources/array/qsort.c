/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:16 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:16 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static uint32_t	partition(t_array *ar, uint32_t l, uint32_t r)
{
	void	*v;

	v = ar->data[l + (r - l) / 2];
	while (l <= r)
	{
		while (ar->cmp(ar->data[l], v) < 0)
			l++;
		while (ar->cmp(ar->data[r], v) > 0)
			r--;
		if (l >= r)
			break ;
		ft_swap_p(&ar->data[l++], &ar->data[r--]);
	}
	return (r);
}

static void		quicksort(t_array *ar, uint32_t l, uint32_t r)
{
	uint32_t	q;

	if (l < r)
	{
		q = partition(ar, l, r);
		quicksort(ar, l, q);
		quicksort(ar, q + 1, r);
	}
}

int				ar_quicksort(t_array *ar)
{
	if (ar && ar->cmp)
	{
		if (ar->len > 1)
			quicksort(ar, 0, ar->len - 1);
		return (0);
	}
	return (1);
}
