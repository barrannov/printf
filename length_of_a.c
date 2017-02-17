//
// Created by Aleksandr Baranov on 2/16/17.
//

#include "ft_printf.h"

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

int check_biggest(int a, int b, int c)
{
    if(a >= b && b >= c || a >= c && c >= b)
        return a;
    if(b >= a&& a >= c || b >= c && c>= a)
		return b;
    if(c >= a && a>= b || c >= b&&a >= a)
        return c;

}

int length_of_a(t_var all, int arg)
{
    int t;

    t = 0;
	if (all.type == 's')
		t = ((int)ft_strlen((char *)arg));
	else if (all.type == 'p')
        t = (count(arg, 16) + 2);
    else if (all.type == 'd' || all.type == 'i')
		t = count(arg, 10);
	else if (all.type == 'o' || all.type == 'O')
		t =  count(arg, 8);
	else if (all.type == 'u')
		t = count((unsigned int) arg, 10);
	else if (all.type == 'U')
		t = count((unsigned long) arg, 10);
	else if (all.type == 'X' || all.type == 'x')
		t = count(arg, 16);
	else if (all.type == 'c' || all.type == 'C')
		t = 1;
    t = check_biggest(all.width, all.precision, t);

	return t;
}
