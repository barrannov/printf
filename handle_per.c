//
// Created by Aleksandr Baranov on 2/27/17.
//

#include "ft_printf.h"


void start_output3(t_var all, intmax_t arg, int len_of_num, int len_of_f)
{
	int pres;
	int white_s;


	pres = (all.precision > len_of_num ? (all.precision - len_of_num) : 0);
	white_s = len_of_f - pres - (len_of_num + (all.min_val == 1 || all.plus ? 1 : all.space));
	//printf("pres: %d\n", white_s);
	//printf("%d\n", len_of_num);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			print_z(white_s + (all.min_val == 1 ? 0 : all.plus));
			all.plus = 0;
		}
		else
			print_w(white_s);
		white_s = 0;
	}
print_z(pres);

	//if(all.precision != 0)
	ft_putchar('%') ;
	//print_w(apc);
	print_w(white_s);
}


t_var handle_per(t_var all, va_list list)
{
	//Длина всего выводимого поля
	int len_of_f;

	len_of_f = 0;
//	if (all.plus || arg < 0)
//	{
//		//len_of_f = 1;
//	}
	intmax_t arg = cast(all.size, list, &all);
	if (arg < 0)
	{
		arg = -arg;
		all.min_val = 1;

	}
	//printf("\nmy: %lld", arg);
	//return without minus

	len_of_f += check_biggest(all.width, all.precision ,1);
	all.var += len_of_f;
	//printf("len of n %d\n", len_of_num);
	//printf("len of f %d\n", len_of_f);
	start_output3(all, arg, 1, len_of_f);
	return all;
}