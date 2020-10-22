/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:34:23 by rstarfir          #+#    #+#             */
/*   Updated: 2020/10/22 16:34:28 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int	main(int argc, char **argv)
{
	t_header s_file;

	open_file(argc, argv, &s_file);
	return (0);
}
