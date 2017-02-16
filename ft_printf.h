#include "libft/libft.h"
#include "stdio.h"
#include <stdarg.h>
#include <stdlib.h>

typedef struct	s_var
{
    char parameter;
    int null;
	int hash;
	int min;
	int space;
	int plus;
    int width;
    int precision;
    int size;
    char type;
} t_var;


char	*ft_itoa_base(long long value, int base, char *hex);
t_var create_struct(int *i, char *str, t_var all);
void go_through_struct(t_var all, va_list arg);
void free_struct(t_var *strc);
void handle_type(char type, int arg);
int check_type(char c);
int check_flag(char c, char b);
int is_digit(char c);
void check_override(t_var *all);
int check_size(char c);
int create_size(char *str, int *i);
t_var create_flags(char *str, int *i, t_var all);
int length_of_a(t_var all, int temp);