/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:43:57 by domurdoc          #+#    #+#             */
/*   Updated: 2020/10/10 23:34:53 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include "libft.h"

/*
** t_lst - single chained list.
*/

typedef struct		s_lst
{
	void			*data;
	struct s_lst	*next;
}					t_lst;

/*
** t_lst_ht - header holding pointers to the first and last elements of single
** chained list and its length.
*/

typedef struct		s_lst_ht
{
	size_t			len;
	t_lst			*head;
	t_lst			*tail;
}					t_lst_ht;

/*
** t_dlst - double chained list.
*/

typedef struct		s_dlst
{
	void			*data;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

/*
** t_dlst_cir - header holding length of the curcuit double chained list and the
** pointer to its element.
*/

typedef struct		s_dlst_cir
{
	size_t			len;
	t_dlst			*cur;
}					t_dlst_cir;

t_lst				*lst_new(void *data);
void				lst_add(t_lst **first, t_lst *new);
void				lst_add_after(t_lst *prev, t_lst *new);
void				lst_del(t_lst **first, void (*del)(void*));

int					lst_push(t_lst **head, void *data);
void				*lst_pop(t_lst **head);

t_lst_ht			*lst_ht_new(void);
int					lst_ht_push(t_lst_ht *x, void *data);
int					lst_ht_push_back(t_lst_ht *x, void *data);
void				*lst_ht_pop(t_lst_ht *x);
void				lst_ht_del(t_lst_ht *x, void (*del)(void*));
void				lst_ht_clear(t_lst_ht *x, void (*del)(void*));

t_dlst				*dlst_new(void *data);
void				dlst_add_before(t_dlst *cur, t_dlst *new);
void				dlst_add_after(t_dlst *cur, t_dlst *new);
void				dlst_disconnect(t_dlst *cur);
void				dlst_del(t_dlst **head, void (*del)(void*));

void				dlst_cir_init(t_dlst_cir *x);
int					dlst_cir_push(t_dlst_cir *x, void *data);
void				*dlst_cir_pop(t_dlst_cir *x);
void				dlst_cir_del(t_dlst_cir *x, void (*del)(void*));

#endif
