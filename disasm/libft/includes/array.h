/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:42:59 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:43:00 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include "libft.h"

# define BH_LEFT(i)		(((i) << 1) + 1)
# define BH_RIGHT(i)	(((i) << 1) + 2)
# define BH_PARENT(i)	(((i) - 1) / 2)

typedef struct	s_array
{
	void		**data;
	uint32_t	len;
	uint32_t	cap;
	void		(*del)(void*);
	int			(*cmp)(void*, void*);
}				t_array;

t_array			*ar_new(uint32_t cap, void (*del)(void*));
int				ar_extend(t_array *ar, uint32_t extra_cap);
int				ar_add(t_array *ar, void *new);
void			ar_del(t_array **ar);

int				bh_add(t_array *ar, void *new);
void			*bh_extract(t_array *ar);

int				ar_quicksort(t_array *ar);

t_array			*ar_map(t_array *ar, void *(*func)(void*), void (*del)(void*));

#endif
