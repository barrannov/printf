//
// Created by Aleksandr Baranov on 3/2/17.
//


#include "ft_printf.h"

void neweveritep(t_var *all, intmax_t arg)
{
	if (all->min_val == 1)
		all->space = 0;
	if(arg == 0 && all->hash && all->precision != 0)
		all->hash = 0;

}


t_var start_outputp(t_var all, uintmax_t arg, int len_of_num, int len_of_f)
{
	int pres;
	int white_s;

	pres = (all.precision > len_of_num ? (all.precision - len_of_num) : 0);
	white_s = len_of_f - pres - len_of_num - 2;
//	printf("pres: %d\n", white_s);
	//printf("%d\n", len_of_num);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			ft_putstr((const char *) "0x");
			print_z(white_s);
		}
		else
		{
			print_w(white_s);
			ft_putstr((const char *) "0x");
		}
		white_s = 0;
	}
	print_z(pres);
	(all.precision == 0 || all.precision > 0 && arg == 0 ) ? 0 : handle_type(all.type, arg);
	print_w(white_s);
	return all;
}

uintmax_t castp(int size, va_list arg, t_var *all)
{
	uintmax_t temp;
	temp = va_arg(arg, uintmax_t);

	return ( temp);
}


t_var handle_p(t_var all, va_list list)
{

	//Длина цифры
	int len_of_num;
	//Длина всего выводимого поля
	int len_of_f;

	len_of_f = 0;
//	if (all.plus || arg < 0)
//	{
//		//len_of_f = 1;
//	}

	uintmax_t arg = castp(all.size, list, &all);
//	printf("%d\n", arg);
	//printf("\nmy: %lld", arg);
	//return without minus
	neweveritep(&all, arg);



	len_of_num = length_of_a(all, arg);
//	if(arg == 0 && all.precision == -1)
//		len_of_num = 1;
	len_of_f += check_biggest(all.width, all.precision + 2, len_of_num + 2);
	all.var += len_of_f;
	all.precision == -1 && arg == 0 && all.width == 0? all.var++ : 0;
	all = start_outputp(all, arg, len_of_num, len_of_f);
	//printf("len of n %d\n", len_of_num);
	//printf("len of f %d\n", len_of_f);
	return (all);
}


