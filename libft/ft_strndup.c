/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:46:48 by abaranov          #+#    #+#             */
/*   Updated: 2017/03/03 17:47:13 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * n + 1);
	if (res != NULL)
	{
		while (str[i] && i < n)
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
