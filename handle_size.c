/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:37:10 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 16:37:12 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_size(char c)
{
	if (c == 'l')
		return (1);
	if (c == 'L')
		return (1);
	if (c == 'h')
		return (1);
	if (c == 'j')
		return (1);
	if (c == 'z')
		return (1);
	if (c == 't')
		return (1);
	return (0);
}

int				create_size(char *str, int *i)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		(*i)++;
		return (1);
	}
	if (str[*i] == 'h' && str[*i + 1] != 'h')
		return (2);
	if ((str[*i] == 'l') || (str[*i] == 'j') || (str[*i] == 'z'))
		return (3);
	return (0);
}

void			neweverite(t_var *all, intmax_t arg)
{
	if (all->min_val == 1)
		all->space = 0;
	if (arg == 0 && all->hash && all->prec != 0)
		all->hash = 0;
	if (all->type == 'c')
		all->prec = 0;
}

uintmax_t		cast2(int size, va_list arg, t_var *all)
{
	uintmax_t temp;

	temp = va_arg(arg, uintmax_t);
	neweverite(all, temp);
	if (all->type == 'U')
		return ((unsigned long)temp);
	if (all->type != 'p' || all->type != 'O')
	{
		if (size == 1)
			return (unsigned char)temp;
		if (size == 2)
			return (unsigned short)temp;
		if (size == 3)
			return (unsigned long)temp;
	}
	if (all->type == 'p' || all->type == 'O')
		return (temp);
	return ((unsigned int)temp);
}

int				is_digit(char c)
{
	if (c > 48 && c < 58)
		return (1);
	return (0);
}
