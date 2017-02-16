#include "ft_printf.h"

/*This func obtain every node to the account function*/
void free_struct(t_var *strc)
{
    strc->parameter = NULL;
    strc->hash = NULL;
    strc->min = NULL;
    strc->null = NULL;
    strc->space = NULL;
    strc->width = NULL;
    strc->precision = NULL;
    strc->size = 0;
    strc->type = NULL;
}



void go_through_struct(t_var stc, void *arg)
{
    /*1. Check parameters
     *etc*/
 handle_type(stc.type, arg);

}