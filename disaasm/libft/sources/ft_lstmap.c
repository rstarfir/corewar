/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:29:35 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:23 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_lstmap() function iterates a list lst and applies the function f to
** each link to create a "fresh" list (using malloc(3) - in this case
** ft_lstnew()) resulting from the successive applications of f.
**
** RETURN VALUE
** The ft_lstmap() function returns a pointer to the new list.
**
** COMMENT
** If the allocation fails, all the memory allocated is freed with ft_memdel()
** and the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		if ((new = ft_lstnew(tmp->content, tmp->content_size)) && lst->next)
			if (!(new->next = ft_lstmap(lst->next, f)))
			{
				ft_memdel(&new->content);
				ft_memdel((void**)&new);
			}
	}
	return (new);
}
