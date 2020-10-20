/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_1_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:44:35 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:59:01 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The function prepares the buffer and calls ganarating algorithm -
** fpn_dragon4().
**
** COMMENT
** Extra.
*/

#include "fpn.h"

void	fpn_k(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	bf->s = x->sign;
	if (x->mant)
		fpn_dragon4(x, bf, free_uniqe, fs->p);
}
