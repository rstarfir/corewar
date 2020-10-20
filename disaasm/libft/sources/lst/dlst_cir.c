/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_cir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:25 by domurdoc          #+#    #+#             */
/*   Updated: 2020/10/10 23:34:39 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/*
** The dlst_cir_push() function pushes data before cur. If an error occurs then
** 1 is returned.
*/

int		dlst_cir_push(t_dlst_cir *x, void *data)
{
	t_dlst	*new;

	if (!x || !(new = dlst_new(data)))
		return (1);
	if (!x->len)
	{
		new->next = new;
		new->prev = new;
	}
	else if (x->len == 1)
	{
		new->prev = x->cur;
		new->next = x->cur;
		x->cur->prev = new;
		x->cur->next = new;
	}
	else
		dlst_add_before(x->cur, new);
	x->cur = new;
	x->len++;
	return (0);
}

/*
** The lst_ht_pop() function extracts the data from the cur element in the
** list, frees the element and returns the data. If the list is empty then NULL
** is returned. If there is only one element left in the list then cur pointer
** will point to NULL after the extraction. If there are two elements left then
** the only left after the extraction will have next and prev pointers set to
** itself.
*/

void	*dlst_cir_pop(t_dlst_cir *x)
{
	void	*data;
	t_dlst	*tmp;

	if (!x || !x->len)
		return (NULL);
	tmp = x->cur;
	data = x->cur->data;
	x->cur = x->cur->next;
	if (x->len == 1)
		x->cur = NULL;
	else if (x->len == 2)
	{
		x->cur->next = x->cur;
		x->cur->prev = x->cur;
	}
	else
		dlst_disconnect(tmp);
	free(tmp);
	x->len--;
	return (data);
}

void	dlst_cir_init(t_dlst_cir *x)
{
	if (!x)
		return ;
	x->cur = NULL;
	x->len = 0;
}

void	dlst_cir_del(t_dlst_cir *x, void (*del)(void*))
{
	t_dlst	*prev;

	if (!x)
		return ;
	while (x->len)
	{
		prev = x->cur;
		x->cur = x->cur->next;
		if (del)
			del(prev->data);
		free(prev);
		x->len--;
	}
}
