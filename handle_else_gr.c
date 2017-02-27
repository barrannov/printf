//
// Created by Aleksandr Baranov on 2/25/17.
//

#include "ft_printf.h"

int choose_size_for_s(int width, size_t len)
{
	if(width > len)
		return width;
	else
		return (int)len;
}


t_var handle_s(t_var all, uintmax_t arg)
{
	int len_of_f;
	char *res;
	int  white_s;

	res = ft_strnew(1);
	if(all.precision > 0 && arg != NULL)
		res = ft_strndup((char *)arg, all.precision);
	else if(arg != NULL)
		res = ft_strdup((char *)arg);
	len_of_f = choose_size_for_s(all.width, ft_strlen(arg != NULL ?res : 0));
	all.var += len_of_f;
	white_s = len_of_f - (int)ft_strlen(arg != NULL ?res : 0);
	//printf("pres: %d\n", len_of_f);
	//printf("%d\n", len_of_num);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			print_z(white_s);
		}
		else
			print_w(white_s);
		white_s = 0;
	}

	//print_z(pres);

	//if(all.precision != 0)

	ft_putstr(arg != NULL ? res : 0);
	//print_w(apc);
	print_w(white_s);
	return all;
}

t_var handle_else_gr(t_var all, va_list arg)
{

	//printf("\n%s", arg);
	uintmax_t temp;

	temp = va_arg(arg, char *);

	if (all.type == 's')
		all = handle_s(all, temp);
	//all.var += length_of_a(all, temp);
	return (all);
}