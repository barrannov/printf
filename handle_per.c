/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:04:36 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 17:04:39 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var		start_output3(t_var all, int len_of_num, int len_of_f)
{
	int white_s;

	white_s = len_of_f - (len_of_num + all.space);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			print_z(white_s);
		}
		else
			print_w(white_s);
		white_s = 0;
	}
	if (all.type == '%')
		ft_putchar('%');
	else
		all.var--;
	print_w(white_s);
	return (all);
}

t_var		handle_per(t_var all)
{
	int len_of_f;

	len_of_f = 0;
	all.prec = 0;
	len_of_f += check_biggest(all.width, all.prec, 1);
	all.var += len_of_f;
	all = start_output3(all, 1, len_of_f);
	return (all);
}
