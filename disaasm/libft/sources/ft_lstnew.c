/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:19:52 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:47:29 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_lstnew() function allocates and returns a "fresh" link. The varialbes
** content and content_size of the new link are initialized by copy of the
** parameters of the function. The variable next is initialized to NULL.
**
** RETURN VALUE
** The ft_lstnew() function returns a pointer to the new link.
**
** COMMENT
** If the parameter content is NULL, the variable content is initialized to NULL
** and the variable content_size is initialized to 0 even if the paramter
** content_size isn't. If the allocation fails, all the memory previousely
** allocated is freed and the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *b;

	if ((b = (t_list*)malloc(sizeof(t_list))))
	{
		b->next = NULL;
		if ((b->content = content && content_size ? malloc(content_size) : 0))
			b->content = ft_memcpy(b->content, content, content_size);
		else if (content && content_size)
			ft_memdel((void**)&b);
		if (b)
			b->content_size = content ? content_size : 0;
	}
	return (b);
}
