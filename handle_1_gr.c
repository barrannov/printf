/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_1_gr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:08:50 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 22:13:28 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		neweverite1(t_var *all)
{
	if (all->min_val == 1)
		all->space = 0;
}

int			instead_if(t_var *all, int white_s)
{
	all->space == 1 ? ft_putchar(' ') : 0;
	all->space = 0;
	if (all->plus == 1 && all->min_val == 0)
	{
		ft_putchar('+');
		white_s--;
	}
	all->min_val == 1 ? ft_putchar('-') : 0;
	print_z(white_s + (all->min_val == 1 ? 0 : all->plus));
	all->plus = 0;
	all->min_val = 0;
	return (white_s);
}

void		start_output(t_var all, intmax_t arg, int len_of_num, int len_of_f)
{
	int		pres;
	int		white_s;

	pres = (all.prec > len_of_num ? (all.prec - len_of_num) : 0);
	white_s = len_of_f - pres - (len_of_num + (all.min_val == 1
				|| all.plus ? 1 : all.space));
	if (all.min == 0)
	{
		if (all.null == 1)
			instead_if(&all, white_s);
		else
			print_w(white_s);
		white_s = 0;
	}
	all.space == 1 ? ft_putchar(' ') : 0;
	all.plus == 1 && all.min_val == 0 ? ft_putchar('+') : 0;
	all.min_val == 1 ? ft_putchar('-') : 0;
	print_z(pres);
	(all.prec == 0 && arg == 0) ? 0 : ft_putnbr(arg);
	print_w(white_s);
}

t_var		handle_1gr(t_var all, va_list list)
{
	int			len_of_num;
	int			len_of_f;
	intmax_t	arg;

	len_of_f = 0;
	len_of_num = 0;
	arg = cast(all.size, list, &all);
	if (arg < 0)
	{
		arg = -arg;
		all.min_val = 1;
	}
	neweverite1(&all);
	len_of_num += (all.prec == 0 && arg == 0) ? 0 : count(arg, 10);
	len_of_f += check_biggest(all.width,
		all.prec +
		(all.min_val ||
		all.plus ? 1 : 0) + all.space,
		len_of_num + (all.min_val || all.plus ? 1 : 0) + all.space);
	all.var += len_of_f;
	start_output(all, arg, len_of_num, len_of_f);
	return (all);
}
