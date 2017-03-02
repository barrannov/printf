/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:55:47 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/02 16:55:51 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(uintmax_t value, int base, char *hex)
{
	int			i;
	uintmax_t	n;
	char		*s;
	uintmax_t	a;

	a = 0;
	i = (value < a && base == 10) ? 2 : 1;
	n = value;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	if (value < a && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[(n < a) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}
