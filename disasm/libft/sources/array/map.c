/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:14 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:14 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ar_map(t_array *ar, void *(*func)(void*), void (*del)(void*))
{
	t_array		*new_ar;

	if (!ar || !func)
		return (NULL);
	if (!(new_ar = ar_new(ar->len, del)))
		return (NULL);
	while (new_ar->len < ar->len)
	{
		if (!(new_ar->data[new_ar->len] = func(ar->data[new_ar->len])))
		{
			ar_del(&new_ar);
			return (NULL);
		}
		new_ar->len++;
	}
	return (new_ar);
}
