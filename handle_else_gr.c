//
// Created by Aleksandr Baranov on 2/25/17.
//

#include "ft_printf.h"

t_var handle_else_gr(t_var all, va_list arg)
{

	//printf("\n%s", arg);
	char *temp;

	temp = va_arg(arg, char *);
	all.var += ft_strlen(temp);
	ft_putstr(temp);
	return (all);
}