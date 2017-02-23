
//
// Created by aleksandr on 08.02.17.
//
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
		if (str[i] == '%' && str[i + 1] == '%' && (i++))
		{
			all.var++;
			write(1, "%", 1);
		}
		else if (str[i] == '%' && (size_t)(i + 1) != ft_strlen(str))
		{

			i++;
			all = create_struct(&i, str, all);
			if (all.type != '%')
				all = go_through_struct(all, myl);
			else
			{
				all.var++;
				write(1, "%", 1);
			}
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


int manin()
{
//	t_var aa;

	/* aa.type = 'w';
	 printf("%c\n", aa.type);
	 if(aa.type)
	 printf("%c\n", aa.type);
	*/
	char *hex;
//
	hex = "0123456789abcdef";
	//ft_putstr(ft_itoa_base(-45, 16, hex));
//	char a[3] = "sd";
	//ft_printf("{%}");
	//ft_printf("\nmy :%u", 45);
	//ft_printf("\n1my:{%12d}", 45);
//	printf("\n% d\n", -15);

	//ft_printf("\nmy:{%5%}", 14);
	//1printf("\nor:{%14.10d}\n", 14);

ft_printf("%+d", -42);
//	uintmax_t a;
//
//	a = (uintmax_t)-45;
//
//	if((long long)a < 0)
//		a = (uintmax_t)-a;
//	printf("%d\n", count(a, 10));
//	printf("%lli", -112121212122);
//	ft_putnbr(21142342342);


	//ft_printf("%u", 4294967295);
//	ft_printf("%d\n", 2147483648);
//	printf("%d\n",2147483648);
//	ft_printf("\n2my:{% 6+-.4d}\n", -45);
//	printf("\n2or:{% 6+-.4d}\n", -45);
//
//	printf("%d\n", ft_printf("%d", 2147483648));
	ft_printf("\n%10.5d", 4242);

	//printf("%d", printf("%d", 2147483648));
	printf("\nmy:{%012d}",-45);
	printf("\nor:{%012d}\n", -45);
//
	ft_printf("\n3my:{% 012d}", 45);
	printf("\n3or:{% 012d}\n", 45);

	ft_printf("\nmy:{% 12d}", -45);
	printf("\nor:{% 12d}\n", -45);

	ft_printf("\n4my:{%+012d}", 45);
	printf("\n4or:{%+012d}\n", 45);

	ft_printf("\nmy:{%+012d}", -45);
	printf("\nor:{%+012d}\n", -45);

	ft_printf("\n5my:{%12d}", 45);
	printf("\n5or:{%12d}\n", 45);

	ft_printf("\nmy:{%-12d}", -45);
	printf("\nor:{%-12d}\n", -45);

	ft_printf("\n6my:{%- 12d}", 45);
	printf("\n6or:{%- 12d}\n", 45);

	ft_printf("\nmy:{%- 12d}", -45);
	printf("\nor:{%- 12d}\n", -45);

	ft_printf("\n7my:{%-+#12x}", 45);
	printf("\n7or:{%-+#12x}\n", 45);
//
//
//	ft_printf("\nmy:%ho", -12);
//	printf("\nor:{%ho}\n", -12);
	//printf("%i", 1223456);
	return 0;
}
