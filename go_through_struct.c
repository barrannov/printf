//
// Created by aleksandr on 11.02.17.
//
#include "ft_printf.h"

void go_through_struct(t_var stc, void *arg)
{
    long i =  &arg;
    if(stc.type == 's')
        ft_putstr(arg);
    else if(stc.type == 'p')
        ft_putnbr((int)arg);
    else if(stc.type == 'd' || stc.type == 'i')
        ft_putnbr((int)arg);

}