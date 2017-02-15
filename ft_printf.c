
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
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			i++;
		}
		else if (str[i] == '%')
		{

			i++;
			all = create_struct(&i, str, all);
            printf("\n");
            printf("  hash: %c", all.hash);
			printf("  null: %c", all.null);
			printf("  min: %c", all.min);
			printf("  space:{%c}", all.space);
			printf("  width: %d", all.width);
			printf("  precision: %d", all.precision);
			printf("  type: %c", all.type);
			printf("  size: %c", all.size);

			go_through_struct(all, va_arg(myl, char *));
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
	t_var aa;

	/* aa.type = 'w';
	 printf("%c\n", aa.type);
	 if(aa.type)
	 printf("%c\n", aa.type);
	*/

	char a[3] = "sd";
	ft_printf("%#.2#01.12..-.....#######..66..1....900#1000d              ", 5);
	// printf("\n%-#d", 5);

	return 0;
}
