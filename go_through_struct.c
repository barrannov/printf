#include "ft_printf.h"

/*This func obtain every node to the account function*/
void free_struct(t_var *strc)
{
    strc->parameter = NULL;
    strc->flags = NULL;
    strc->width = NULL;
    strc->precision = NULL;
    strc->size = NULL;
    strc->type = NULL;
}



void go_through_struct(t_var stc, void *arg)
{
    /*1. Check parameters
     *etc*/
 handle_type(stc.type, arg);

}