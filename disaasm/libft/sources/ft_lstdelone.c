/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:56:24 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:07 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_lstdelone() function takes as a parameter a link's pointer address
** alst and frees the memory of the link's content using the fuction del, and
** then frees the link's memory using free(3) - actually with ft_memdel().
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If alst or *alst or del points to NULL, the function does nothing.
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}
