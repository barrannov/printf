//
// Created by aleksandr on 11.02.17.
//

#include "printf.h"
#include "stdlib.h"

char	*ft_itoa_base(long long value, int base, char *hex)
{
    int		i;
    long long		n;
    char	*s;

    i = (value < 0 && base == 10) ? 2 : 1;
    n = value;
    while (n /= base)
        i++;
    if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
        return (NULL);
    s[i] = 0;
    if (value < 0 && base == 10)
        s[0] = '-';
    if (value == 0)
        s[0] = '0';
    n = value;
    while (n)
    {
        s[--i] = hex[(n < 0) ? -(n % base) : n % base];
        n /= base;
    }
    return (s);
}