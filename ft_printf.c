
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

	i = 0;
	while (str[i])
	{
		free_struct(&all);
		if (str[i] == '%' && str[i + 1] == '%' && (i++))
			write(1, "%", 1);
		else if (str[i] == '%' && (size_t)(i + 1) != ft_strlen(str))
		{

			i++;
			all = create_struct(&i, str, all);

			if(all.type != '%')
				go_through_struct(all, myl);
			else
				write(1, "%", 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(myl);
	return 0;
}


int main()
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
//
	ft_printf("\nmy:{%14.3d}", -14);
	printf("\nor:{%14.3d}\n", -14);


	ft_printf("\n2my:{%0122d}", 45);
	printf("\n2or:{%0122d}\n", 45);

	ft_printf("\nmy:{%012d}", -45);
	printf("\nor:{%012d}\n", -45);

	ft_printf("\n3my:{% 012d}", 45);
	printf("\n3or:{% 012d}\n", 45);

	ft_printf("\nmy:{% 012d}", -45);
	printf("\nor:{% 012d}\n", -45);

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
//	//printf("%i", 1223456);
	return 0;
}
