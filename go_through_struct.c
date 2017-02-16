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

//TODO function that define length of argument and malloc memory for res

//1. Function that returns base of type
//2. Function that returns length of str if arg is str
//TODO create funcs in  separate file that return length of arg
//

void go_through_struct(t_var all, va_list arg)
{
	/*1. Check parameters
	 *etc*/
	char *res;
	int temp;
	temp = va_arg(arg, int );

	int t;

	t = length_of_a(all.type, temp);
	int a;

	a = all.width > t ? all.width : t;
	printf("  %d", a);
	res = ft_strnew((size_t)(all.width > t ? all.width : t));

	//handle_type(all.type, arg);

}