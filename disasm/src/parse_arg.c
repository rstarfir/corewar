#include "disasm.h"

t_uchar	arg_byte(t_uchar opc, t_uchar arg)
{
	if (arg == 1)
		return (1);
	else if (arg == 3)
		return (2);
	else if (arg == 2)
	{
		if (g_op_tab[opc - 1].t_dir_short)
			return (2);
		return (4);
	}
	return (0);
}

void	parse_argument_2_4_bytes(t_var *data)
{
	if (g_op_tab[data->opc - 1].t_dir_short)
	{
		data->r = read(data->fd, &data->sh, 2);
		data->champ_size -= 2;
		data->sh = reverse_byte_by_byte_short(data->sh);
		ft_printf("%%%hd", data->sh);
	}
	else
	{
		data->r = read(data->fd, &data->ui, 4);
		data->ui = reverse_byte_by_byte_int(data->ui);
		data->champ_size -= 4;
		ft_printf("%%%u", data->ui);
	}
}


void	parse_argument(t_var *data, t_uchar arg_type, t_bool comma)
{
	if (arg_type == 1)
	{
		data->r = read(data->fd, &data->uc, 1);
		data->champ_size--;
		ft_printf("r%hhu", data->uc);
	}
	else if (arg_type == 3)
	{
		data->r = read(data->fd, &data->sh, 2);
		data->champ_size -= 2;
		ft_printf("%hd", reverse_byte_by_byte_short(data->sh));
	}
	else if (arg_type == 2 || arg_type == 4)
		parse_argument_2_4_bytes(data);
	if (comma)
		ft_printf(", ");
	else
		ft_printf(" ");
}
