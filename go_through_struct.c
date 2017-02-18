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
	strc->precision = 0;
	strc->size = 0;
	strc->plus = 0;
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

void start_fill_res(int len_r, t_var all, void *arg, int base)
{
	int i;
	char nul;
	char *str;
	char *hex;

	hex = "0123456789abcdef";
//	str = ft_itoa(arg);
	//printf("\nafter itoa:%d",str);
	nul = ' ';
	i = 0;
	int temp;
//	if ( str[0] == '0' && all.null != 1)
//	{
//		str[0] = '-';
//}

//	if( str[0] == ' ')
//		str = move_one(str);
	//if (all.type == 's')
	temp = length_of_a(all, (arg < 0 ? ((int) arg) : -(int) arg), &base);
	//printf("\ntemp : %d", temp);
	//else
	//	temp = count(arg, 1);

	if (arg < 0 && !all.min && all.null == 1)
	{
		ft_putchar('-');
		all.space = 0;
		all.plus = 0;
	}
	if (all.min == 0)
	{
		if (all.space == 1 && arg > 0)
		{
			ft_putchar(' ');
			len_r--;
			all.space = 0;
		}
		if (all.plus == 1 && arg > 0 && all.null == 1)
		{
			ft_putchar('+');
			all.plus = 0;
			len_r--;
		}
		else if (all.plus == 1 && arg > 0)
			len_r--;
		if (all.null == 1)
			nul = '0';
		while (i < len_r - temp)
		{
			ft_putchar(nul);
			i++;
		}

	}

	if (arg < 0 && !all.min && all.null != 1)
	{
		ft_putchar('-');
		len_r--;
		all.space = 0;
		//	arg = -arg;
		all.plus = 0;
	}
//i--;
	//if(all.null)
	temp = 0;
	if (all.space == 1 && arg > 0)
	{
		ft_putchar(' ');
		len_r--;
	}
	if (all.plus == 1 && arg > 0)
	{
		ft_putchar('+');
		len_r--;
	}
//	if(all.type == 'x'  && all.)
//	while (str[temp])
//	{
//
//		res[i] = str[temp];
//		temp++;
//		i++;
//	}
	//printf("arg: %d", arg);

	if (arg < 0 && (all.type == 'd' || all.type == 'i'))
	{
		ft_putchar('-');
		len_r--;

	}
//	if (arg < 0 && all.min == 1)
//		arg = -arg;
	handle_type(all.type, arg);

	//ft_putstr(ft_itoa_base(arg, base, hex));
	if (all.min == 1)
	{
		i++;
		i++;
		while (i < len_r)
		{
			ft_putchar(nul);
			i++;
		}
	}
//	return res;
}
//
//char *char_to_n(t_var all, int base, void *arg)
//{
//	char *hex;
//	char *str;
//
//	str = ft_strnew(1);
//	hex = "0123456789abcdef";
//
//	if (all.type == 's')
//	{
//		str = ft_strjoin(" ", arg);
//	}
//	else if (all.type == 'p')
//
//		str = ft_strjoin((const char *) "0x", (const char *) *(ft_itoa_base(()arg, 16, hex)));
//
//	if (all.type == 'd' || all.type == 'i')
//	{int a;
//		a= (int)arg;
//		str = ft_strjoin(arg < 0 ? "-" : str, ft_itoa_base(((a < 0) ? (-a) : (a)), 10, hex));
//	}
//	else if (all.type == 'o')
//		str = ft_strjoin(str, ft_itoa_base((int) arg, 8, hex));
//	else if (all.type == 'O')
//		str = ft_strjoin(str, ft_itoa_base(arg, 8, hex));
//	if (all.type == 'u')
//		str = ft_strjoin(str, ft_itoa_base((unsigned) arg, 10, hex));
//	else if (all.type == 'U')
//		str = ft_strjoin(str, ft_itoa_base((unsigned long) arg, 10, hex));
//	else if (all.type == 'X')
//	{
//		hex = "0123456789ABCDEF";
//		str = ft_strjoin(str, ft_itoa_base(arg, 16, hex));
//	}
//	else if (all.type == 'x')
//		str = ft_strjoin(str, ft_itoa_base(arg, 16, hex));
//	else if (all.type == 'c' || all.type == 'C')
//	{
//		str = ft_strnew(1);
//		str[0] = (char)arg;
//}
//	return  (str);
//}

long long cast(t_var all, void *temp)
{

	if (all.size == 1)
		return (unsigned char) temp;
	if (all.size == 2)
		return (unsigned short) temp;
	if (all.size == 3)
		return (long) temp;
	return ((long long) temp);
}

void go_through_struct(t_var all, va_list arg)
{
	/*1. Check parameters
	 *etc*/
	void *temp;
	int t;
	int base;
	char *str;
	temp = va_arg(arg, void *);
	temp = (void *) cast(all, temp);
//ft_putnbr(temp);
	base = 10;
	t = length_of_a(all, temp, &base);
	t = check_biggest(all.width, all.precision, t);
	//printf("t: %d\n", t);
	//printf("\nbase:%d", base);
	//Минус не сработает если поле меньшн числа
//	printf(" t: %d", t);
	if (t > all.width)
	{
		all.min = 0;
	}
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
	start_fill_res(t, all, temp, base);
	//handle_type(all.type, temp);
}