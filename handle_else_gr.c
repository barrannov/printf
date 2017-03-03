/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_else_gr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:11:36 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 17:11:40 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			choose_size_for_s(int width, int len, char *arg)
{
	if (width > len)
		return (width);
	else if (arg == NULL)
		return (6);
	else
		return (len);
}

t_var		handle_s(t_var all, char *arg)
{
	int		len_of_f;
	char	*res;
	int		white_s;
	int		str_len;

	res = ft_strnew(1);
	if (all.prec >= 0 && arg != NULL)
		res = ft_strndup(arg, all.prec);
	else if (arg != NULL)
		res = ft_strdup(arg);
	str_len = arg != NULL ? (int)ft_strlen(res) : 0;
	len_of_f = choose_size_for_s(all.width, str_len, arg);
	all.var += len_of_f;
	arg == NULL ? len_of_f -= 6 : 0;
	white_s = len_of_f - str_len;
	if (all.min == 0)
	{
		all.null == 1 ? print_z(white_s) : print_w(white_s);
		white_s = 0;
	}
	ft_putstr(res);
	print_w(white_s);
	return (all);
}

t_var		handle_else_gr(t_var all, va_list arg)
{
	uintmax_t temp;

	temp = va_arg(arg, uintmax_t);
	if (temp == 0)
		temp = (uintmax_t)"(null)";
	if (all.type == 's')
		all = handle_s(all, (char *)temp);
	return (all);
}
