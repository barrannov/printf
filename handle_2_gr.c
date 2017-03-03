/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2_gr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:26:18 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 15:42:44 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_var	instead_if(t_var all, int *white_s, uintmax_t arg)
{
	all.space == 1 ? ft_putchar(' ') : 0;
	all.space = 0;
	if (all.plus == 1 && all.min_val == 0)
	{
		ft_putchar('+');
		white_s--;
	}
	else if (all.min_val == 1)
		ft_putchar('-');
	if (all.hash == 1 && (all.type == 'x' || all.type == 'X') && arg > 0)
	{
		ft_putstr("0");
		all.hash = 0;
		ft_putchar(all.type);
	}
	if (all.hash == 1 && (all.type == 'o' || all.type == 'O'))
	{
		all.hash = 0;
		ft_putstr("0");
	}
	print_z(*white_s + (all.min_val == 1 ? 0 : all.plus));
	all.plus = 0;
	all.min_val = 0;
	return (all);
}

static t_var	all_min(t_var all, int *white_s, uintmax_t arg)
{
	if (all.null == 1)
		all = instead_if(all, white_s, arg);
	else
		print_w(*white_s);
	*white_s = 0;
	return (all);
}

t_var			start_o2(t_var all, uintmax_t arg, int len_of_num, int len_of_f)
{
	int pres;
	int white_s;

	pres = (all.prec > len_of_num ? (all.prec - len_of_num) : 0);
	if (all.type == 'x' && all.hash == 1 && all.prec > 0)
	{
		pres += 2;
		all.var += 2;
	}
	white_s = len_of_f - pres - (len_of_num + (all.space));
	all.min == 0 ? all = all_min(all, &white_s, arg) : all;
	all.space == 1 ? ft_putchar(' ') : 0;
	all.plus == 1 && all.min_val == 0 ? ft_putchar('+') : 0;
	all.min_val == 1 ? ft_putchar('-') : 0;
	if (all.hash == 1 && (all.type == 'x' || all.type == 'X') && arg > 0)
	{
		ft_putstr("0");
		ft_putchar(all.type);
	}
	all.hash == 1 && (all.type == 'o' || all.type == 'O') ? ft_putstr("0") : 0;
	all.type == 'p' ? ft_putstr((const char *)"0x") : 0;
	print_z(pres);
	(all.prec == 0 && !arg && all.type != 'c') ? 0 : handle_type(all.type, arg);
	print_w(white_s);
	return (all);
}

t_var			handle_2gr(t_var all, va_list list)
{
	int			len_of_num;
	int			len_of_f;
	uintmax_t	arg;

	len_of_f = 0;
	arg = cast2(all.size, list, &all);
	if (all.prec == 0 && arg == 0 && all.type != 'c')
	{
		len_of_num = 0;
		all.hash && all.type != 'x' ? len_of_num++ : 0;
		all.type == 'p' ? len_of_num += 2 : 0;
	}
	else if (arg == 0 && all.type == 'c')
	{
		all.prec = 0;
		len_of_num = 1;
	}
	else
		len_of_num = length_of_a(all, arg);
	len_of_f += check_biggest(all.width,
			all.prec + all.space, len_of_num + all.space);
	all.var += len_of_f;
	all = start_o2(all, arg, len_of_num, len_of_f);
	return (all);
}
