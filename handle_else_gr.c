//
// Created by Aleksandr Baranov on 2/25/17.
//

#include "ft_printf.h"

int choose_size_for_s(int width, int len, char  *arg)
{

	if (width > len)
		return width;
	else if(arg == NULL)
		return 6;
	else
		return len;
}


t_var handle_s(t_var all, char * arg)
{
	int len_of_f;
	char *res;
	int white_s;
	int str_len;


	res = ft_strnew(1);

	if (all.precision >= 0 && arg != NULL)
		res = ft_strndup((char *) arg, all.precision);
	else if (arg != NULL)
		res = ft_strdup((char *) arg);



	if (arg != NULL)
		str_len = (int) ft_strlen(res);
	else
		str_len = 0;
	len_of_f = choose_size_for_s(all.width, str_len, arg);
//	if(arg == NULL && len_of_f == str_len)
//		len_of_f -= 6;
	all.var += len_of_f;
	arg == NULL ? len_of_f -=6 : 0;
	white_s = len_of_f - str_len;
	//printf("pres: %d\n", len_of_f);
	//printf("%d\n", len_of_num);
	if (all.min == 0)
	{
		if (all.null == 1)
		{
			print_z(white_s);
		}
		else
			print_w(white_s);
		white_s = 0;
	}

	//print_z(pres);

	//if(all.precision != 0)

//	if (arg == NULL)
//	{
//		ft_putstr("(null)");
//		//all.var += 6;
//	}

		ft_putstr(res);
	print_w(white_s);
	return all;
}

t_var handle_else_gr(t_var all, va_list arg)
{

	//printf("\n%s", arg);
	uintmax_t temp;

	temp = va_arg(arg, uintmax_t);

	if(temp == 0)
		temp = (uintmax_t)"(null)";
	if (all.type == 's')
		all = handle_s(all, (char *)temp);
	//all.var += length_of_a(all, temp);
	return (all);
}