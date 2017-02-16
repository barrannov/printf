//
// Created by Aleksandr Baranov on 2/16/17.
//

#include "ft_printf.h"

char *itoa_basee(int value, int base)
{
	static char rep[] = "0123456789abcdef";
	static char buf[50];
	char *ptr;
	int num;

	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}
int count(long long arg, int base)
{
	int i;

	i = 0;
	while(arg > 0)
	{
		arg /= base;
		i++;
	}
	return (i);
}
int length_of_a(char type, int arg)
{
	char *hex;

	char *str = itoa_basee(arg, 16);
	hex = "0123456789ABCDEF";
	if (type == 's')
		return ((int)ft_strlen((char *)arg));
	else if (type == 'p')
		printf("%s", str);
			//printf("%s", ft_itoa_base((int)arg, 16, hex));
	else if (type == 'd' || type == 'i')
		return count((int)arg, 10);
	else if (type == 'o')
		return count((int)arg, 8);
	else if (type == 'O')
		return count(arg, 8);
	else if (type == 'u')
		return count((unsigned int) arg, 10);
	else if (type == 'U')
		return count((unsigned long) arg, 10);
	else if (type == 'X')
	{
		return count(arg, 16);
	}
	else if (type == 'x')
		return count(arg, 16);
	else if (type == 'c' || type == 'C')
		return 1;
	return 0;
}
