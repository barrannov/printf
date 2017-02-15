#include "libft/libft.h"
#include "stdio.h"
#include <stdarg.h>
#include <stdlib.h>



typedef struct	s_var
{
    char parameter;
    char flags;
    int width;
    int precision;
    int length;
    char type;
} t_var;


char	*ft_itoa_base(long long value, int base, char *hex);
t_var create_struct(int *i ,char *str);
void go_through_struct(t_var stc, void *arg);
void free_struct(t_var *strc);
void handle_type(char type, void *arg);
int check_type(char c);
int check_flag(char c);
int check_width(char c);