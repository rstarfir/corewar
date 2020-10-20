/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:23:27 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:15 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_lstiter() function iterates the list lst and applies the function f to
** each link.
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If lst or f points to NULL, the function does nothing.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *b;

	if (f)
		while (lst)
		{
			b = lst->next;
			f(lst);
			lst = b;
		}
}
