/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:24:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/10/22 16:28:02 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef enum	e_bool
{
	fals,
	tru
}				t_bool;

typedef	unsigned char	t_uchar;
typedef	unsigned short	t_ushort;
typedef unsigned int	t_uint;

typedef	struct	s_var
{
	t_uchar		uc;
	short		sh;
	t_uint		ui;
	int			fd;
	int			r;
	t_uchar		opc;
	t_uchar		ops_size;
	t_uint		tmp;
	t_uint		champ_size;
	t_uchar		bt;
}				t_var;

t_uint			reverse_byte_by_byte_int(t_uint num);
t_ushort		reverse_byte_by_byte_short(t_ushort num);

void			print_binary_short(short n);
void			print_binary_uint(t_uint n);
void			print_binary_uchar(t_uchar n);

t_bool			read_s_file(t_var *v, t_header *f);
t_bool			open_file(int argc, char **argv, t_header *f);
t_bool			read_size(t_var *v);
t_bool			parse_instruction(t_var *v);

t_bool			check_file_name(int argc, char **argv);
t_uchar			arg_byte(t_uchar opc, t_uchar arg);
void			parse_argument_2_4_bytes(t_var *v);
void			parse_argument(t_var *v, t_uchar arg_type, t_bool comma);

t_bool			parse_magic_header(t_var *v);
void			parse_champ_name(t_var *v, t_header *f);
void			parse_champ_comment(t_var *v, t_header *f);

t_bool			parse_champ_size(t_var *v);
t_bool			parse_null(t_var *v);

#endif
