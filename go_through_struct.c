/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:39:23 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 21:39:24 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			free_struct(t_var *strc)
{
	strc->hash = 0;
	strc->min = 0;
	strc->null = 0;
	strc->space = 0;
	strc->width = 0;
	strc->prec = -1;
	strc->size = 0;
	strc->plus = 0;
	strc->min_val = 0;
	strc->t = 0;
	strc->type = (char)NULL;
}

intmax_t		cast(int size, va_list arg, t_var *all)
{
	intmax_t	temp;

	temp = va_arg(arg, intmax_t);
	if (all->type == 'D')
		return ((long)temp);
	if (size == 1)
		return (char)temp;
	if (size == 2)
		return (short)temp;
	if (size == 3)
		return (long)temp;
	return ((int)temp);
}

t_var			go_through_struct(t_var all, va_list arg)
{
	if (isgrop1(all.type))
		all = handle_1gr(all, arg);
	else if (isgrop2(all.type))
		all = handle_2gr(all, arg);
	else if (all.type == 'p')
		all = handle_p(all, arg);
	else if (all.type == 's')
		all = handle_else_gr(all, arg);
	else
		all = handle_per(all);
	return (all);
}
