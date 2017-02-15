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

char *create_flags(char *str, int *i)
{
	char *res;
	int j;

	res = ft_strnew(6);
	j = 0;
	while (check_flag(str[*i]))
	{
		res[j] = str[*i];
		(*i)++;
		j++;
	}
	(*i)--;
	return (res);
}