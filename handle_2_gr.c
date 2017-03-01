//
// Created by Aleksandr Baranov on 2/25/17.
//
#include "ft_printf.h"


void neweverite(t_var *all, intmax_t arg)
{
	if (all->min_val == 1)
		all->space = 0;
	//if (arg == NULL && all->type == 'c')
	//	all->precision = 0;
}


t_var start_output2(t_var all, uintmax_t arg, int len_of_num, int len_of_f)
{
	int pres;
	int white_s;
	int apc;

	apc = all.space;


//	arg == NULL ? len_of_f-- : 0;
	pres = (all.precision > len_of_num ? (all.precision - len_of_num) : 0);
	white_s = len_of_f - pres - (len_of_num + (all.min_val == 1 || all.plus ? 1 : all.space));
	//printf("pres: %d\n", white_s);
	//printf("%d\n", len_of_num);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			all.space == 1 ? ft_putchar(' ') : 0;
			all.space = 0;
			if (all.plus == 1 && all.min_val == 0)
			{
				ft_putchar('+');
				white_s--;
			}
			else if (all.min_val == 1)
				ft_putchar('-');
			if (all.hash == 1 && (all.type == 'x' || all.type == 'X') && arg > 0)
			{
				ft_putstr("0");
				all.hash = 0;
				ft_putchar(all.type);

			}
			if (all.hash == 1 && (all.type == 'o' || all.type == 'O'))
			{
				all.hash = 0;
				ft_putstr("0");
			}
			print_z(white_s + (all.min_val == 1 ? 0 : all.plus));
			all.plus = 0;
			all.min_val = 0;
		}
		else
			print_w(white_s);
		white_s = 0;
	}
	all.space == 1 ? ft_putchar(' ') : 0;
	all.plus == 1 && all.min_val == 0 ? ft_putchar('+') : 0;
	all.min_val == 1 ? ft_putchar('-') : 0;
	if (all.hash == 1 && (all.type == 'x' || all.type == 'X') && arg > 0)
	{
		ft_putstr("0");
		ft_putchar(all.type);
	}
	if (all.hash == 1 && (all.type == 'o' || all.type == 'O'))
	{
		ft_putstr("0");
	}
	print_z(pres);

	//printf("%U", arg);
	//if (all.precision != 0 && arg != 0)
	(all.precision == 0 && arg == 0) ? 0 : handle_type(all.type, arg);
	//print_w(apc);
	print_w(white_s);
	return all;
}

uintmax_t cast2(int size, va_list arg, t_var *all)
{
	uintmax_t temp;
	temp = va_arg(arg, uintmax_t);

	if(all->type == 'U')
		return  ((unsigned long)temp);
	if (all->type == 'o' || all->type == 'u' || all->type == 'x' || all->type == 'X')
	{
		if (size == 1)
			return (unsigned char) temp;
		if (size == 2)
		{
			return (unsigned short) temp;
		}
		if (size == 3)
			return (unsigned long) temp;
	}
	return ((unsigned int) temp);
}


t_var handle_2gr(t_var all, va_list list)
{

	//Длина цифры
	int len_of_num;
	//Длина всего выводимого поля
	int len_of_f;

	len_of_f = 0;
	len_of_num = 0;
//	if (all.plus || arg < 0)
//	{
//		//len_of_f = 1;
//	}

	uintmax_t arg = cast2(all.size, list, &all);
	if (arg < 0)
	{
		all.min_val = 1;

	}
//	printf("%d\n", arg);
	//printf("\nmy: %lld", arg);
	//return without minus
	neweverite(&all, arg);
	 if(all.precision == 0 && arg == 0)
	 {
		 len_of_num = 0;
		 all.hash && all.type != 'x' ? len_of_num++ : 0;
	 }
	else
		 len_of_num =  length_of_a(all, arg);
	len_of_f += check_biggest(all.width, all.precision + (all.min_val || all.plus ? 1 : 0) + all.space ,
							  len_of_num + (all.min_val || all.plus ? 1 : 0) + all.space );
	all.var += len_of_f;
	all = start_output2(all, arg, len_of_num, len_of_f);
	//printf("len of n %d\n", len_of_num);
	//printf("len of f %d\n", len_of_f);
	return (all);
}

