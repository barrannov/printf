//
// Created by Aleksandr Baranov on 2/13/17.
//
#include "ft_printf.h"

void handle_type(char type, void *arg)
{
    if(type == 's')
        ft_putstr(arg);
    else if(type == 'p')
        ft_putnbr((int)arg);
    else if(type == 'd' || type == 'i')
        ft_putnbr((int)arg);
}