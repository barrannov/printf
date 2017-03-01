
//
// Created by aleksandr on 08.02.17.
//
#include <limits.h>
#include "ft_printf.h"


int ft_printf(char *str, ...)
{
	int i;
	va_list myl;
	t_var all;
	va_start(myl, str);

	all.var = 0;
	i = 0;
	while (str[i])
	{
		free_struct(&all);
//		if (str[i] == '%' && str[i + 1] == '%' && (i++))
//		{
//			all.var++;
//			write(1, "%", 1);
//		}
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				i++;
				all = create_struct(&i, str, all);
				//	if (check_type(all.type))
				all = go_through_struct(all, myl);
			}
// else
//			{
//				all.var++;
//				write(1, "%", 1);
//			}
		}
		else
		{
			all.var++;
			write(1, &str[i], 1);
		}
		i++;
	}

	va_end(myl);
	//printf("var : %d\n", all.var);
	return all.var;
}


int main()
{
	char test_simple_mix[5] = "qwdg";
	printf("\n%d\n", ft_printf("%.5p", 0));
	printf("\n%d\n", printf("%.5p", 0));
//	printf("\n%d\n",  printf("%5h", -9223372036854775808));
	return 0;
}
