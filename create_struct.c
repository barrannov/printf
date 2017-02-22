//
// Created by aleksandr on 11.02.17.
//
#include "ft_printf.h"

int create_numbers(char *str, int *i)
{
	int width;
	char *temp;
	int j;

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


int check_precision(char c, char b)
{
	if (c == '.' && is_digit(b))
		return (1);
	return (0);
}
t_var create_struct(int *i, char *str, t_var all)
{
/*This function adds all specification to structure*/
	//t_var all;

	int temp;

	if (str[*i] == '%')
	{
		free_struct(&all);
		all.type = '%';
		return all;
	}
	if (check_flag(str[*(i)]))
		all = create_flags(str, i, all);
	if (is_digit(str[*i]))
		all.width = create_numbers(str, i);
	if (check_precision(str[*i], str[*i + 1]))
	{
		(*i)++;
		temp = create_numbers(str, i);
		all.precision = temp;
	}
	if (check_size(str[*i]))
	{
		all.size = (temp = create_size(str, i)) > all.size ? temp : all.size;
	}
	if (check_type(str[*i]))
	{
		all.type = str[(*i)];
		check_override(&all);
		return (all);
	}
	(*i)++;
	return create_struct(i, str, all);
}
