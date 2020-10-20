/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ht.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:32 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:32 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst_ht	*lst_ht_new(void)
{
	t_lst_ht	*new;

	if (!(new = malloc(sizeof(t_lst_ht))))
		return (NULL);
	new->len = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

/*
** The lst_ht_push() function pushes data to the begining of the list. If an
** error occurs then 1 is returned.
*/

int			lst_ht_push(t_lst_ht *x, void *data)
{
	t_lst	*new;

	if (!x || !(new = lst_new(data)))
		return (1);
	lst_add(&x->head, new);
	if (!x->len++)
		x->tail = x->head;
	return (0);
}

/*
** The lst_ht_push_back() function pushes data to the end of the list. If an
** error occurs then 1 is returned.
*/

int			lst_ht_push_back(t_lst_ht *x, void *data)
{
	t_lst	*new;

	if (!x)
		return (1);
	if (!x->len)
		return (lst_ht_push(x, data));
	if (!(new = lst_new(data)))
		return (1);
	lst_add_after(x->tail, new);
	x->tail = new;
	x->len++;
	return (0);
}

/*
** The lst_ht_pop() function extracts the data from the first element in the
** list, frees the element and returns the data. If the list is empty then NULL
** is returned. If there is only one element left in the list then both head and
** tail pointers will point to NULL after the extraction.
*/

void		*lst_ht_pop(t_lst_ht *x)
{
	void	*data;
	t_lst	*tmp;

	if (!x || !x->len)
		return (NULL);
	tmp = x->head;
	data = x->head->data;
	x->head = x->head->next;
	free(tmp);
	if (x->len-- == 1)
		x->tail = NULL;
	return (data);
}

/*
** The lst_ht_del() function clears list with lst_ht_clear() and also frees
** t_lst_ht structure.
*/

void		lst_ht_del(t_lst_ht *x, void (*del)(void*))
{
	if (!x)
		return ;
	lst_ht_clear(x, del);
	free(x);
}
