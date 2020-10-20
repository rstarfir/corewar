/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ht_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:55:34 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:55:34 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

/*
** The lst_ht_clear() function uses lst_del() function to delete the list and
** sets tail-pointer to NULL.
*/

void		lst_ht_clear(t_lst_ht *x, void (*del)(void*))
{
	if (x)
	{
		x->len = 0;
		lst_del(&x->head, del);
		x->tail = NULL;
	}
}
