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

void	parse_argument_2_4_bytes(t_var *v)
{
	if (g_op_tab[v->opc - 1].t_dir_short)
	{
		v->r = read(v->fd, &v->sh, 2);
		v->champ_size -= 2;
		v->sh = reverse_byte_by_byte_short(v->sh);
		ft_printf("%%%hd", v->sh);
	}
	else
	{
		v->r = read(v->fd, &v->ui, 4);
		v->ui = reverse_byte_by_byte_int(v->ui);
		v->champ_size -= 4;
		ft_printf("%%%u", v->ui);
	}
}


void	parse_argument(t_var *v, t_uchar arg_type, t_bool comma)
{
	if (arg_type == 1)
	{
		v->r = read(v->fd, &v->uc, 1);
		v->champ_size--;
		ft_printf("r%hhu", v->uc);
	}
	else if (arg_type == 3)
	{
		v->r = read(v->fd, &v->sh, 2);
		v->champ_size -= 2;
		ft_printf("%hd", reverse_byte_by_byte_short(v->sh));
	}
	else if (arg_type == 2 || arg_type == 4)
		parse_argument_2_4_bytes(v);
	if (comma)
		ft_printf(", ");
	else
		ft_printf(" ");
}
