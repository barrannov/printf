/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:25:40 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 16:25:45 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(char c)
{
	int		i;
	char	*type;

	i = 0;
	type = "sSpdDioOuUxXcC%";
	while (type[i])
	{
		if (c == type[i])
			return (1);
		i++;
	}
	return (0);
}

void	handle_type(char type, uintmax_t arg)
{
	char *hex;

	hex = "0123456789abcdef";
	type == 's' ? ft_putstr((char *)arg) : 0;
	type == 'p' ? ft_putstr((const char *)(ft_itoa_base(arg, 16, hex))) : 0;
	if (type == 'd' || type == 'i')
		ft_putnbr(arg);
	else if (type == 'o')
		ft_putstr(ft_itoa_base((unsigned long)arg, 8, hex));
	else if (type == 'O')
		ft_putstr(ft_itoa_base(arg, 8, hex));
	if (type == 'u')
		ft_putstr(ft_itoa_base((unsigned long)arg, 10, hex));
	else if (type == 'U')
		ft_putstr(ft_itoa_base((unsigned long)arg, 10, hex));
	else if (type == 'X')
	{
		hex = "0123456789ABCDEF";
		ft_putstr(ft_itoa_base((unsigned long)arg, 16, hex));
	}
	else if (type == 'x')
		ft_putstr(ft_itoa_base((unsigned long)arg, 16, hex));
	else if ((type == 'c' || type == 'C'))
		ft_putchar((char)arg);
}
