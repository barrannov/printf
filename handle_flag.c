//
// Created by Aleksandr Baranov on 2/15/17.
//


#include "ft_printf.h"

int check_flag(char c)
{
	int i;

	i = 0;
	char type[6] = "-0+ #";
	while (type[i])
	{
		if (c == type[i])
			return (1);
		i++;
	}
	return (0);
}
t_var create_flags(char *str, int *i, t_var all)
{


	if(str[*i] == '0')
		all.null = '0';
	if(str[*i] == '#')
		all.hash = '#';
	if(str[*i] == '-')
		all.min = '-';
	if(str[*i] == ' ')
		all.space = ' ';
	(*i)++;
	return (all);
}