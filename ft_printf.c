
//
// Created by aleksandr on 08.02.17.
//
#include <stdarg.h>


int ft_printf(char *str, ...)
{
    int i;
    va_list myl;
    t_var all;
    va_start(myl, str);

    i = 0;
    while (str[i]) {
        if (str[i] == '%')
        {
            all = create_struct(&i,str);
            go_through_struct(all, va_arg(myl, char *));
        }
        else
            write(1, &str[i], 1);
        i++;
    }

    va_end(myl);
    return 0;
}


int main() {
    char a[3] = "sd";
    ft_printf("%p%d", a, 1);
    printf("\n%o%d", 100, a);
    return 0;
}
