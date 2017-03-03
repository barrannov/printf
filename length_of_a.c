/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_of_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:34:07 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 16:34:09 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count(uintmax_t arg, int base)
{
	int i;

	i = (arg == 0) ? 1 : 0;
	while (arg > 0)
	{
		arg /= base;
		i++;
	}
	return (i);
}

int		check_biggest(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	if (c >= a && c >= b)
		return (c);
	return (0);
}

int		length_of_a(t_var all, uintmax_t arg)
{
	int		t;
	char	*hex;

	hex = "0123456789abcdef";
	t = 0;
	if (all.type == 's')
		t = ((int)ft_strlen((char *)arg));
	else if (all.type == 'p')
		t = ((arg != 0 ? count(arg, 16) : 0));
	else if (all.type == 'd' || all.type == 'i')
		t += count(arg, 10);
	else if (all.type == 'o' || all.type == 'O')
		t = count(arg, 8);
	else if (all.type == 'u' || all.type == 'U')
		t = count((unsigned long)arg, 10);
	else if (all.type == 'X' || all.type == 'x')
		t = ft_strlen(ft_itoa_base((unsigned long)arg, 16, hex));
	else if (all.type == 'c' || all.type == 'C')
		t = 1;
	if (all.hash == 1 && (all.type == 'x' || all.type == 'X') && arg > 0)
		t += 2;
	if (all.hash == 1 && (all.type == 'o' || all.type == 'O'))
		t++;
	return (t);
}
