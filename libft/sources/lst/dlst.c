/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:22 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:23 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/*
** The dlst_new() function allocates memory (malloc(3)) for t_dlst structure and
** returns it with next and prev pointers set to NULL and data being initialized
** with data passed to the function. If allocation fails returns NULL.
*/

t_dlst	*dlst_new(void *data)
{
	t_dlst	*new;

	if ((new = malloc(sizeof(t_dlst))))
	{
		new->data = data;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

/*
** The dlst_add_before() function adds new element before the cur-element.
*/

void	dlst_add_before(t_dlst *cur, t_dlst *new)
{
	if (cur && new)
	{
		if (cur->prev)
			cur->prev->next = new;
		new->prev = cur->prev;
		new->next = cur;
		cur->prev = new;
	}
}

/*
** The dlst_add_after() function adds new element after the cur-element.
*/

void	dlst_add_after(t_dlst *cur, t_dlst *new)
{
	if (cur && new)
	{
		if (cur->next)
			cur->next->prev = new;
		new->next = cur->next;
		new->prev = cur;
		cur->next = new;
	}
}

/*
** The dlst_disconnect() function breaks connections of the cur-element with
** next and prev and connects adjacent elements to each other.
** Expacts the list to have at least 3 elements.
*/

void	dlst_disconnect(t_dlst *cur)
{
	if (!cur)
		return ;
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	cur->prev = NULL;
	cur->next = NULL;
}

/*
** The dlst_del() function walks along the list from the head and frees each
** element with free(3) and its data with del-function passed. In the end *head
** equals NULL.
*/

void	dlst_del(t_dlst **head, void (*del)(void*))
{
	t_dlst	*cur;

	while (*head)
	{
		cur = *head;
		*head = (*head)->next;
		if (del)
			del(cur->data);
		free(cur);
	}
}
