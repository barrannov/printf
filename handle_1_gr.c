//
// Created by Aleksandr Baranov on 2/22/17.
//

#include "ft_printf.h"

void start_output(t_var all, intmax_t arg, int len_of_num, int len_of_f)
{
	int pres;
	int white_s;
	all.plus == 1 ? len_of_f-- : 0;
	all.space == 1 ? len_of_f-- : 0;
	pres = (all.precision > len_of_num ? (all.precision - len_of_num) : 0);
	white_s = len_of_f - pres - len_of_num;
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			all.plus == 1 && all.min_val == 0 ? ft_putchar('+') : 0;
			all.min_val == 1 ? ft_putchar('-') : 0;
			white_s--;
			print_z(white_s);
			all.plus = 0;
			all.min_val = 0;
		}
		else
			print_w(white_s);
		white_s = 0;
	}
	all.plus == 1 && all.min_val == 0 ? ft_putchar('+') : 0;
	all.min_val == 1 ? ft_putchar('-') : 0;
	print_z(pres);
	ft_putnbr(arg);
	print_w(white_s);
}

void handle_1gr(t_var all, intmax_t arg)
{
	//Длина цифры
	int len_of_num;
	//Длина всего выводимого поля
	int len_of_f;

	len_of_f = 0;
	len_of_num = 0;
	if(all.plus || arg < 0)
	{
		len_of_f = 1;
		//len_of_num = 1;
	}
	if (arg < 0)
	{
		arg *= -1;
		all.min_val = 1;

	}


	len_of_num += count(arg, 10);
	len_of_f += check_biggest(all.width, all.precision, len_of_num);
	//printf("len of n %d\n", len_of_num);
	//printf("len of f %d\n", len_of_f);
	start_output(all, arg, len_of_num, len_of_f);
}