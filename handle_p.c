/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:17:48 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 22:17:52 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				neweveritep(t_var *all, intmax_t arg)
{
	if (all->min_val == 1)
		all->space = 0;
	if (arg == 0 && all->hash && all->precision != 0)
		all->hash = 0;
}

t_var				start_outputp(t_var all, uintmax_t arg,
							int len_of_num, int len_of_f)
{
	int		pres;
	int		white_s;

	pres = (all.precision > len_of_num ? (all.precision - len_of_num) : 0);
	white_s = len_of_f - pres - len_of_num - 2;
	if (all.width > 0 && all.precision == -1 && arg == 0)
		white_s--;
	if (all.min == 0)
		if (all.null == 1)
		{
			ft_putstr((const char *)"0x");
			print_z(white_s);
		}
		else
		{
			print_w(white_s);
			ft_putstr((const char *)"0x");
		}
	print_z(pres);
	(all.precision == 0 || all.precision > 0 && arg == 0)
	? 0 : handle_type(all.type, arg);
	return (all);
}

uintmax_t			castp(va_list arg)
{
	uintmax_t	temp;

	temp = va_arg(arg, uintmax_t);
	return (temp);
}

t_var				handle_p(t_var all, va_list list)
{
	int			len_of_num;
	int			len_of_f;
	uintmax_t	arg;

	len_of_f = 0;
	arg = castp(list);
	neweveritep(&all, arg);
	len_of_num = length_of_a(all, arg);
	len_of_f += check_biggest(all.width, all.precision + 2, len_of_num + 2);
	all.var += len_of_f;
	all.precision == -1 && arg == 0 && all.width == 0 ? all.var++ : 0;
	all = start_outputp(all, arg, len_of_num, len_of_f);
	return (all);
}
