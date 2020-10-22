/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:26:41 by rstarfir          #+#    #+#             */
/*   Updated: 2020/10/22 16:26:42 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool	check_file_name(int argc, char **argv)
{
	char	*point;
	int		i;

	i = 1;
	while (i < argc)
	{
		point = ft_strrchr(argv[i], '.');
		if (point == NULL)
		{
			ft_putstr_fd("ERROR format not supported for ", 2);
			ft_putendl_fd(argv[i], 2);
			return (fals);
		}
		if (ft_strncmp(point, ".cor", 4) != 0)
		{
			ft_putstr_fd("ERROR please provide .cor file", 2);
			return (fals);
		}
		i++;
	}
	return (tru);
}

t_bool	read_s_file(t_var *data, t_header *file)
{
	if (parse_magic_header(data) == fals)
		return (fals);
	parse_champ_name(data, file);
	if (parse_null(data) == fals)
		return (fals);
	if (parse_champ_size(data) == fals)
		return (fals);
	parse_champ_comment(data, file);
	if (parse_null(data) == fals)
		return (fals);
	while (data->champ_size > 0)
	{
		if (parse_instruction(data) == fals)
			return (fals);
	}
	return (tru);
}

t_bool	open_file(int argc, char **argv, t_header *file)
{
	int		i;
	t_var	data;

	i = 1;
	if (check_file_name(argc, argv) == fals)
		return (fals);
	while (i < argc)
	{
		data.fd = open(argv[i], O_RDONLY, 0);
		if (data.fd < 0)
		{
			ft_putendl_fd("ERROR couldn't open file", 2);
			return (fals);
		}
		read_s_file(&data, file);
		close(data.fd);
		i++;
	}
	return (tru);
}
