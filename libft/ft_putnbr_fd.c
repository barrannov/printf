/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:26:34 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 14:02:12 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(intmax_t n, int fd)
{
	if(n == -9223372036854775807 - 1)
	{
		ft_putnbr_fd(9223372036, fd);
		ft_putnbr_fd(854775808, fd);
		return;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(214748, fd);
			ft_putnbr_fd(3648, fd);
			return ;
		}
		else
			n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		//printf("arg: %d", n);
		ft_putchar_fd((char)(n % 10) + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
