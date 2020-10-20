/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:11 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:12 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	bh_sift_down(t_array *ar, int64_t i)
{
	uint32_t	left;
	uint32_t	right;
	uint32_t	lesser;

	while ((left = BH_LEFT(i)) < ar->len)
	{
		right = left + 1;
		lesser = left;
		if (right < ar->len && ar->cmp(ar->data[left], ar->data[right]) > 0)
			lesser = right;
		if (ar->cmp(ar->data[i], ar->data[lesser]) <= 0)
			break ;
		ft_swap_p(&ar->data[i], &ar->data[lesser]);
		i = lesser;
	}
}

void	bh_sift_up(t_array *ar, int64_t i)
{
	uint32_t	parent;

	while (ar->cmp(ar->data[i], ar->data[(parent = BH_PARENT(i))]) < 0)
	{
		ft_swap_p(&ar->data[i], &ar->data[parent]);
		i = parent;
	}
}

int		bh_add(t_array *ar, void *new)
{
	if (ar_add(ar, new))
		return (1);
	bh_sift_up(ar, ar->len - 1);
	return (0);
}

void	*bh_extract(t_array *ar)
{
	void	*data;

	data = NULL;
	if (ar->len > 0)
	{
		data = ar->data[0];
		if (--ar->len > 0)
		{
			ar->data[0] = ar->data[ar->len];
			bh_sift_down(ar, 0);
		}
	}
	return (data);
}
