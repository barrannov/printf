//
// Created by Aleksandr Baranov on 2/27/17.
//

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

