/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:07:06 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:01 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_lstdel() function takes as a parameter the address of a pointer to a
** link and frees the memory of this link and every successors of that link
** using the function del and free(3) (realized in ft_lstdelone()).
**
** RETURN VALUE
** Nothing.
**
** COMMENT
** If alst or *alst or del ponints to NULL, the function does nothing.
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *b;

	if (alst && *alst && del)
	{
		b = *alst;
		while (b)
		{
			b = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = b;
		}
	}
}
