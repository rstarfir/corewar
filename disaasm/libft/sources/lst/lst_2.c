/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:29 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:30 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int		lst_push(t_lst **head, void *data)
{
	t_lst	*new;

	if (!head || !(new = lst_new(data)))
		return (1);
	lst_add(head, new);
	return (0);
}

void	*lst_pop(t_lst **head)
{
	void	*data;
	t_lst	*tmp;

	if (!head || !*head)
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}
