//
// Created by Aleksandr Baranov on 2/15/17.
//


#include "ft_printf.h"

int check_flag(char c, char b)
{
	int i;

	i = 0;
	char type[6] = "-0+ #";
	while (type[i])
	{
		if (c == type[i] && b != '.')
			return (1);
		i++;
	}
	return (0);
}
t_var create_flags(char *str, int *i, t_var all)
{


	if(str[*i] == '0' && !is_digit(str[*i - 1]))
		all.null = 1;
	if(str[*i] == 1)
		all.hash = '#';
	if(str[*i] == '-')
		all.min = 1;
	if(str[*i] == ' ')
		all.space = 1;
	if(str[*i] == '+')
		all.plus = 1;
	return (all);
}