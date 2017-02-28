//
// Created by Aleksandr Baranov on 2/15/17.
//


#include "ft_printf.h"

void check_override(t_var *all )
{
	if (all->min == 1 && all->null == 1)
		all->null = 0;
	if (all->plus == 1 && all->space == 1)
		all->space = 0;
	if (all->precision > -1 && all->null == 1 && all->type != 'f' && all->type != 's')
		all->null = 0;
	if (all->width == 0 || all->width == all->precision)
		all->min = 0;
/*	if(all->width > 0 && (all->null == 0))
		all->space = 0;*/
	if(all->type != 'd' && all->type != 'i')
		all->plus = 0;
	if (all->type != 'd' && all->type != 'i')
	{
		all->plus = 0;
		all->space = 0;
	}
	if(all->type != 'O' && all->type != 'o' && all->type != 'i' && all->type != 'x' && all->type != 'X')
		all->hash = 0;
}

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


	if(str[*i] == '0' && !is_digit(str[*i - 1]))
		all.null = 1;
	if(str[*i] == '#')
		all.hash = 1;
	if(str[*i] == '-')
		all.min = 1;
	if(str[*i] == '+')
		all.plus = 1;
	if(str[*i] == ' ')
		all.space = 1;
	return (all);
}