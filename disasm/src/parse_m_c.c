/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_m_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:26:52 by rstarfir          #+#    #+#             */
/*   Updated: 2020/10/22 16:41:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool		parse_magic_header(t_var *data)
{
	unsigned int	mag;

	data->r = read(data->fd, &mag, 4);
	if (mag != 0xf383ea00 || data->r < 1)
	{
		ft_putstr_fd("ERROR: not binary file provided. ", 2);
		ft_putendl_fd("Magic header is not suitable", 2);
		return (fals);
	}
	return (tru);
}

void		parse_champ_name(t_var *data, t_header *file)
{
	int i;

	data->r = read(data->fd, file->prog_name, PROG_NAME_LENGTH);
	file->prog_name[PROG_NAME_LENGTH] = '\0';
	i = 0;
	while (i < 128)
	{
		if (!ft_isprint(file->prog_name[i]))
		{
			file->prog_name[i] = '\0';
			break ;
		}
		i++;
	}
	ft_printf(".name \"%s\"\n", file->prog_name);
}

t_bool		parse_champ_size(t_var *data)
{
	data->r = read(data->fd, &data->champ_size, 4);
	data->champ_size = reverse_byte_by_byte_int(data->champ_size);
	if (data->champ_size >= MEM_SIZE)
	{
		ft_putendl_fd("ERROR: instructions for champion exceed 682 bytes.", 2);
		return (fals);
	}
	return (tru);
}

void		parse_champ_comment(t_var *data, t_header *file)
{
	int i;

	data->r = read(data->fd, file->comment, COMMENT_LENGTH);
	file->comment[COMMENT_LENGTH] = '\0';
	i = 0;
	while (i < 2048)
	{
		if (!ft_isprint(file->comment[i]))
		{
			file->comment[i] = '\0';
			break ;
		}
		i++;
	}
	ft_printf(".comment \"%s\"\n", file->comment);
}
