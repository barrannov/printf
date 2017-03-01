#include "ft_printf.h"

/*This func obtain every node to the account function*/
void free_struct(t_var *strc)
{
	strc->parameter = (char) NULL;
	strc->hash = 0;
	strc->min = 0;
	strc->null = 0;
	strc->space = 0;
	strc->width = 0;
	strc->precision = -1;
	strc->size = 0;
	strc->plus = 0;
	strc->min_val = 0;
	strc->type = (char) NULL;
}

//DONE function that define length of argument and malloc memory for res
//TODO Проверить каждый тип на работоспособность с минусами и тд. Начать реализовывать порядок
//1. Function that returns base of type
//2. Function that returns length of str if arg is str
//DONE create funcs in  separate file that return length of arg
//

char *move_one(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void put_m_or_p(t_var *all, uintmax_t *arg, int len_of_num, int *len_r)
{

	if ((int) arg < 0 && ((all->null == 1 || len_of_num == *len_r)))
	{
		*arg *= (uintmax_t) 1;
		ft_putchar('-');
		all->plus = 0;
	}
	else if (all->plus == 1 && (all->null == 1 || len_of_num == *len_r))
	{
		ft_putchar('+');
		(*len_r)--;
		all->plus = 0;
	}
	if (all->plus)
		(*len_r)--;
}


void start_fill_res(int len_r, t_var all, uintmax_t arg, int base)
{
	int i;
	char nul;
//	char *str;
	char *hex;

	hex = "0123456789abcdef";
//	str = ft_itoa(arg);

	nul = ' ';
	i = 0;
	int len_of_num;

//	len_of_num = length_of_a(all, arg, &base);
	int pres;

	pres = 0;

	if (all.precision > len_of_num)
	{
		pres = all.precision - len_of_num;
		len_r -= pres;

	}
	if ((int) arg < 0)
	{
		all.space = 0;

	}

	//printf("%d\n", len_of_num);
	//printf("len_r :  %d\n", len_r);
	//printf("len_of_num :  %d\n", len_of_num);
	if (all.min == 0)
	{

		put_m_or_p(&all, &arg, len_of_num, &len_r);

		if (all.null)
		{
			nul = '0';
			all.null = 0;
		}
		if (all.space == 1 && (int) arg > 0)
		{
			ft_putchar(' ');
			len_r--;
			all.space = 0;
		}
		if (all.hash == 1 && all.type == 'o')
		{
			ft_putstr("0");
			len_r--;
			all.hash = 0;
		}
		if (all.hash == 1 && (all.type == 'x' || all.type == 'X'))
		{
			ft_putstr("0x");
			len_r -= 2;
			all.hash = 0;
		}

		while (len_r > len_of_num)
		{
			ft_putchar(nul);
			len_r--;
		}
	}
//	printf("pres :  %d\n", pres);

	if (arg != '\0')
	{
		put_m_or_p(&all, &arg, len_of_num, &len_r);

		if (all.space == 1 && (uintmax_t) arg > 0)
		{
			ft_putchar(' ');
			len_r--;
			all.space = 0;
		}
		if (all.plus == 1 && (uintmax_t) arg > 0)
		{
			ft_putchar('+');
			all.plus = 0;
		}
		if ((int) arg < 0)
		{
			ft_putchar('-');
			arg *= 1;
		}
		if (all.hash == 1 && all.type == 'o')
		{
			ft_putstr("0");
			len_r--;
			all.hash = 0;
		}
		if (all.hash == 1 && (all.type == 'x' || all.type == 'X'))
		{
			ft_putstr("0x");
			len_r -= 2;
			all.hash = 0;
		}

		while (pres)
		{
			ft_putchar('0');
			pres--;
		}


		handle_type(all.type, arg);

		arg = '\0';
		len_r -= len_of_num;
		all.min = 0;
	}
	if (len_r > 0)
		return start_fill_res(len_r, all, arg, base);
}

intmax_t cast(int size, va_list arg, t_var *all)
{
	intmax_t temp;
	temp = va_arg(arg, intmax_t);

	if (size == 1)
		return (char) temp;
	if (size == 2)
		return (short) temp;
	if (size == 3)
		return (long) temp;
	return ((int) temp);
}

t_var go_through_struct(t_var all, va_list arg)
{
	/*1. Check parameters
	 *etc*/
	intmax_t temp;
	int t;
	int base;
//	char *str;
//	temp = va_arg(arg, uintmax_t);
	//temp = cast(all.size, arg, &all);


	if (isgrop1(all.type))
		all = handle_1gr(all, arg);
	else if (isgrop2(all.type))
		all = handle_2gr(all, arg);
	else if (all.type == '%')
		all = handle_per(all, arg);
	else
		all = handle_else_gr(all, arg);










//ft_putnbr(temp);
//	base = 10;
//	t = length_of_a(all, temp, &base);
//	t = check_biggest(all.width, all.precision, t);
//	if (all.type == 's')
//	{
//		ft_putstr((char *)temp);
//		return all;
//	}
	//printf("t: %d\n", t);
//	all.var += t;
	//printf("t: %d\n", t);
	//printf("\nbase:%d", base);
	//Минус не сработает если поле меньшн числа
//	printf(" t: %d", t);
//	if (t > all.width)
//	{
//		all.min = 0;
//	}
/*	printf("  |hash: {%d}", all.hash);
	printf("  null: {%d}", all.null);
	printf("  min: {%d}", all.min);
	printf("  space:{%d}", all.space);
	printf("  plus:{%d}", all.plus);
	printf("  width: {%d}", all.width);
	printf("  precision: {%d}", all.precision);
	printf("  size: {%d}", all.size);
	printf("  type: {%c}|      ", all.type);*/
//	res = ft_strnew(t);
	//str = char_to_n(all, base, temp);
//	printf("%s", str);
	//Сдесь можно создать нули для пресижион и джоин
	//start_fill_res(t, all, temp, base);
	//handle_type(all.type, temp);
	return all;
}