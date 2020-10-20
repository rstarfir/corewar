/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:27 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:27 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/*
** The lst_new() function allocates memory (malloc(3)) for t_lst structure and
** returns it with next-pointer set to NULL and data being initialized with data
** passed to the function. If allocation fails returns NULL.
*/

t_lst	*lst_new(void *data)
{
	t_lst	*new;

	if ((new = malloc(sizeof(t_lst))))
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

/*
** The lst_add() function adds new element at the begining of the list.
*/

void	lst_add(t_lst **first, t_lst *new)
{
	if (first && new)
	{
		new->next = *first;
		*first = new;
	}
}

/*
** The lst_add_after() function adds new element after the previous one (last in
** the list).
*/

void	lst_add_after(t_lst *prev, t_lst *new)
{
	if (prev && new)
	{
		new->next = prev->next;
		prev->next = new;
	}
}

/*
** The lst_del() function walks along the list from the first and frees each
** element with free(3) and its data with del-function passed. In the end *first
** equals NULL.
*/

void	lst_del(t_lst **first, void (*del)(void*))
{
	t_lst	*lst;

	if (first)
		while (*first)
		{
			lst = *first;
			*first = (*first)->next;
			if (del)
				del(lst->data);
			free(lst);
		}
}
