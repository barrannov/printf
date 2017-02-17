
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
//			printf("  |hash: {%d}", all.hash);
//			printf("  null: {%d}", all.null);
//			printf("  min: {%d}", all.min);
//			printf("  space:{%d}", all.space);
//			printf("  plus:{%d}", all.plus);
//			printf("  width: {%d}", all.width);
//			printf("  precision: {%d}", all.precision);
//			printf("  size: {%d}", all.size);
//			printf("  type: {%c}|      ", all.type);
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
	t_var aa;

	/* aa.type = 'w';
	 printf("%c\n", aa.type);
	 if(aa.type)
	 printf("%c\n", aa.type);
	*/

	char a[3] = "sd";
	//ft_printf("{%.o}", "qwert");
	ft_printf("\n{%#......059.32...2#-   0d}{%#......059.32...2#-   0d}{%#......059.32...2#-   0d}{%#......059.32...2#-   0d}{%#......059.32...2#-   0d}", 45, 1, 3,4, 4);
	return 0;
}
