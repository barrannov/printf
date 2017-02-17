#include "ft_printf.h"

/*This func obtain every node to the account function*/
void free_struct(t_var *strc)
{
	strc->parameter = (char )NULL;
	strc->hash = 0;
	strc->min = 0;
	strc->null = 0;
	strc->space = 0;
	strc->width = 0;
	strc->precision = 0;
	strc->size = 0;
	strc->type = (char )NULL;
}

//DONE function that define length of argument and malloc memory for res
//TODO Проверить каждый тип на работоспособность с минусами и тд. Начать реализовывать порядок
//1. Function that returns base of type
//2. Function that returns length of str if arg is str
//DONE create funcs in  separate file that return length of arg
//

void start_fill_res(char *res, int len_r, t_var all, void *arg)
{
	int i;
	char null;
	char *str;

	str = ft_itoa((int) arg);
	//null = ' ';
		i = len_r;

		while (i >= i - ft_strlen(str))
		{
			res[i] = str[i];
			i--;
		}


	//if(all.null)
		null = '0';
	while (i >= 0)
	{
		res[i] = null;
		i--;
	}

}
void go_through_struct(t_var all, va_list arg)
{
	/*1. Check parameters
	 *etc*/
	char *res;
	void * temp;
	int t;

	temp = va_arg(arg, void * );
//	printf("\nsuize  :%d", all.size);
	all.size == 1 ? temp = (char)temp : 0;
	all.size == 2 ? temp = (short)temp : 0;
	all.size == 3 ? temp = (long)temp : 0;
	ft_putnbr(temp);
	t = length_of_a(all, temp);
	//Минус не сработает если поле меньшн числа
//	printf(" t: %d", t);
	if(t > all.width)
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
	res = ft_strnew(t);
	start_fill_res(&res, t, all, temp);
	ft_putstr(res);
	//handle_type(all.type, temp);
}