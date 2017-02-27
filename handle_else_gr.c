//
// Created by Aleksandr Baranov on 2/25/17.
//

#include "ft_printf.h"

int choose_size_for_s(int pres, int widthm, size_t len)
{
	int t;

	t = 0;
	return t;
}


t_var handle_s(t_var all, uintmax_t arg)
{
	int len_of_f;
	char *res;

	if(all.precision > 0)
		res = ft_strndup((char *)arg, all.precision);
	else
		res = ft_strdup((char *)arg);
	len_of_f = choose_size_for_s(all.precision, all.width, ft_strlen( (char*) arg));
}

t_var handle_else_gr(t_var all, va_list arg)
{

	//printf("\n%s", arg);
	uintmax_t temp;

	temp = va_arg(arg, char *);

	if (all.type == 's')
		all = handle_s(all, temp);
	all.var += length_of_a(all, temp);
	ft_putstr((char *) temp);
	return (all);
}