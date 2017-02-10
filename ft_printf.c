//
// Created by aleksandr on 08.02.17.
//
#include <stdarg.h>
#include "stdio.h"
#include "ft_printf.h"

t_var create_struct(int *i, char *str)
{
    t_var all;

    while(str[i])
    {
        if(str[i] == '%') {
            if (str[i + 1] == 's')
                ft_putstr(va_arg(myl, char *));
            else if (str[i + 1] == 'd' || str[i + 1] == 'i')
                ft_putnbr(va_arg(myl, int));
            else if (str[i + 1] == '%')
                ft_putchar(str[i]);
            else
                ft_putchar(str[i  + 1]);
            i++;
        }
        else
            ft_putchar(str[i]);
        i++;
    }

}

/*This function does everything with */
void main_f(t_var all, void *argv)
{

}

int ft_printf(char *str, ...)
{
    int i;
    va_list myl;
    t_var all;
    va_start(myl, str);

    i = 0;
    while(str[i])
    {
        if(str[i] == '%') {
            myl = create_struct(&i, str);
        }
        i++;
    }

    va_end(myl);
    return 0;
}


int main() {
    char a[3] = "sd";
    ft_printf("%s%d%%ds%\nasxsxax", a, 5, 6);
  //  printf("%2$d %2$#x; %1$d %1$#x", 10, 16);
    return 0;
}
