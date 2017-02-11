#include "libft/libft.h"
#include "stdio.h"
#include "ft_printf.h"

#include <stdlib.h>



typedef struct	s_var
{
    //char parameter;
   // char flags;
    //char width;
  //  int precision;
//    int length;
    char type;
} t_var;


char	*ft_itoa_base(int value, int base);
t_var create_struct(int *i ,char *str);
void go_through_struct(t_var stc, void *arg);