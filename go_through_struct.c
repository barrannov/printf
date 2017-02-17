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

void go_through_struct(t_var all, va_list arg)
{
	/*1. Check parameters
	 *etc*/
	char *res;
	int temp;
	int t;

	temp = va_arg(arg, int );
	t = length_of_a(all, temp);
	printf("  %d", t);
	res = ft_strnew((size_t)length_of_a(all, temp));
	handle_type(all.type, arg);
}