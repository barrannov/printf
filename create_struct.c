//
// Created by aleksandr on 11.02.17.
//
#include "ft_printf.h"

int check_t(char *c)
{
    int i;

    i = 0;
    char type[15] = "sSpdDioOuUxXcC";
    while(type[i])
    {
        if(*c == type[i])
            return (1);
        i++;
    }
    return (0);
}
/*This function adds all specification to structure*/

t_var create_struct(int *i ,char *str)
{
    t_var all;

    if(str[(*i)] == '%') {
    str++;
    }
  //  while (str[(*i)]) {
        if (check_t(str))
        {
            all.type = str[(*i)];
           // return (all);
        (*i)++;
         }
 //   }
    return (all);
}
