#include "disasm.h"

t_bool	parse_null(t_var *data)
{
	data->r = read(data->fd, &data->tmp, 4);
	if (data->r < 1 || data->tmp != 0)
	{
		ft_putendl_fd("ERROR no zeros after champ name", 2);
		return (fals);
	}
	return (tru);
}

t_bool	read_size(t_var *data)
{
	data->r = read(data->fd, &data->opc, 1);
	data->champ_size--;
	if (data->opc > 0x15)
	{
		ft_putendl_fd("ERROR the instruction is out of range", 2);
		return (fals);
	}
	ft_printf("%s ", g_op_tab[data->opc - 1].name);
	if (g_op_tab[data->opc - 1].op_code != data->opc)
	{
		ft_putendl_fd("ERROR in op.c in order of opcodes\n", 2);
		return (fals);
	}
	return (tru);
}

t_bool	parse_instruction(t_var *data)
{
	if (read_size(data) == fals)
		return (fals);
	if (g_op_tab[data->opc - 1].args_number == 2 ||
	g_op_tab[data->opc - 1].args_number == 3)
	{
		data->r = read(data->fd, &data->ops_size, 1);
		data->champ_size--;
		parse_argument(data, (data->ops_size & 0xc0) >> 6, tru);
		if (g_op_tab[data->opc - 1].args_number == 2)
			parse_argument(data, (data->ops_size & 0x30) >> 4, fals);
		else
		{
			parse_argument(data, (data->ops_size & 0x30) >> 4, tru);
			parse_argument(data, (data->ops_size & 0xc) >> 2, fals);
		}
	}
	else
	{
		if (g_op_tab[data->opc - 1].t_dir_short)
			parse_argument(data, 2, fals);
		else
			parse_argument(data, 4, fals);
	}
	ft_printf("\n");
	return (tru);
}
