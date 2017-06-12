/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:00:08 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 18:00:09 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdio.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct	s_var
{
	int			null;
	int			hash;
	int			min;
	int			space;
	int			plus;
	int			width;
	int			prec;
	int			size;
	char		type;
	int			var;
	int			min_val;
	int			t;
}				t_var;

int				ft_printf(char *str, ...);
char			*ft_itoa_base(uintmax_t value, int base, char *hex);
t_var			create_struct(int *i, char *str, t_var all);
t_var			go_through_struct(t_var all, va_list arg);
void			free_struct(t_var *strc);
void			handle_type(char type, uintmax_t arg);
int				check_type(char c);
int				check_flag(char c);
int				is_digit(char c);
void			check_override(t_var *all);
int				check_size(char c);
int				create_size(char *str, int *i);
t_var			create_flags(char *str, int *i, t_var all);
int				length_of_a(t_var all, uintmax_t temp);
int				check_biggest(int a, int b, int c);
t_var			handle_p(t_var all, va_list list);
uintmax_t		cast2(int size, va_list arg, t_var *all);
t_var			handle_1gr(t_var all, va_list list);
t_var			handle_2gr(t_var all, va_list list);
t_var			handle_else_gr(t_var all, va_list arg);
t_var			handle_per(t_var all);
int				count(uintmax_t arg, int base);
t_var			handle_1gr(t_var all, va_list list);
intmax_t		cast(int size, va_list arg, t_var *all);
int				isgrop1(char c);
int				isgrop2(char c);
void			print_w(int i);
void			print_z(int i);

#endif
