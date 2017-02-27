//
// Created by Aleksandr Baranov on 2/13/17.
//
#include "ft_printf.h"


int check_type(char c)
{
	int i;

	i = 0;
	char type[15] = "sSpdDioOuUxXcC";
	while (type[i])
	{
		if (c == type[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void handle_type(char type, uintmax_t arg)
{
	char *hex;

	hex = "0123456789abcdef";
	//ft_putnbr((unsigned)arg);
//	if ( (int)arg < 0)
//		arg *= 1;
	if (type == 's')
	{
		ft_putstr((char *)arg);
	}
	else if (type == 'p')
	{
		ft_putstr((const char *) "0x");
		ft_putstr((const char *) (ft_itoa_base(arg, 16, hex)));
	}
	if (type == 'd' || type == 'i')
	{
		ft_putnbr(arg);
	}
	else if (type == 'o')
		ft_putstr(ft_itoa_base((unsigned) arg, 8, hex));
	else if (type == 'O')
		ft_putstr(ft_itoa_base(arg, 8, hex));
	if (type == 'u')
		ft_putnbr((unsigned long)arg);
	else if (type == 'U')
		ft_putnbr((unsigned long) arg);
	else if (type == 'X')
	{
		hex = "0123456789ABCDEF";
		ft_putstr(ft_itoa_base((unsigned long)arg, 16, hex));
	}
	else if (type == 'x')
		ft_putstr(ft_itoa_base((unsigned long)arg, 16, hex));
	else if (type == 'c' || type == 'C')
		ft_putchar(arg);
}