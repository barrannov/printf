/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:40:38 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 17:40:47 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			create_numbers(char *str, int *i)
{
	int		width;
	char	*temp;
	int		j;

	j = 0;
	temp = str;
	while (j < *i)
	{
		temp++;
		j++;
	}
	width = ft_atoi(temp);
	while (*temp > 48 && *temp < 58)
	{
		temp++;
		(*i)++;
	}
	(*i)--;
	return (width);
}

int			check_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

t_var		create_struct(int *i, char *str, t_var all)
{
	if (check_flag(str[*(i)]))
		all = create_flags(str, i, all);
	else if (is_digit(str[*i]))
		all.width = create_numbers(str, i);
	else if (check_precision(str[*i]))
	{
		all.prec = 0;
		is_digit(str[*i + 1]) ? (*i)++ : 0;
		is_digit(str[*i]) ? all.prec = create_numbers(str, i) : 0;
	}
	else if (check_size(str[*i]))
	{
		all.t = create_size(str, i);
		all.t > all.size ? all.size = all.t : 0;
	}
	else if (check_type(str[*i]))
	{
		all.type = str[(*i)];
		check_override(&all);
		return (all);
	}
	else
		return (all);
	(*i)++;
	return (create_struct(i, str, all));
}
