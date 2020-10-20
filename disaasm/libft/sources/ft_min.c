/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:48:26 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 12:48:27 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_min() function compares integers of size 4 bytes and returns the least
*/

#include <stdint.h>

int32_t	ft_min(int32_t a, int32_t b)
{
	return (a < b ? a : b);
}
