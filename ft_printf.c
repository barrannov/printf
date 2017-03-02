/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:30:48 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 21:31:57 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

void			printt(t_var *all, char c)
{
	all->var++;
	write(1, &c, 1);
}

int				ft_printf(char *str, ...)
{
	int			i;
	va_list		myl;
	t_var		all;

	va_start(myl, str);
	all.var = 0;
	i = 0;
	while (str[i])
	{
		free_struct(&all);
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			all = create_struct(&i, str, all);
			all = go_through_struct(all, myl);
			!check_type(all.type) ? i-- : 0;
		}
		else if (str[i] != '%')
			printt(&all, str[i]);
		i++;
	}
	va_end(myl);
	return (all.var);
}
