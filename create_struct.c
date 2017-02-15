//
// Created by aleksandr on 11.02.17.
//
#include "ft_printf.h"

int create_width(char *str, int *i)
{
	int width;
	char *temp;
	int j;

	j = 0;
	temp = str;
	while (j < *i)
	{
		temp++;
		j++;
	}
	width = ft_atoi(temp);
	while (*temp > 48 && *temp < 58)
	{
		temp++;
		(*i)++;
	}
	(*i)--;
	return (width);
}

/*This function adds all specification to structure*/

t_var create_struct(int *i, char *str)
{
	t_var all;


	// if(str[(*i)] == '%')
	//   (*i)++;
	//  while (str[(*i)]) {
	if (check_flag(str[*(i)]))
	{
		all.flags = str[*i];
		// return (all);
		//printf("%c", all.flags);
		(*i)++;
	}
	if (check_width(str[*i]))
	{
		all.width = create_width(str, i);
		//printf("%d", all.width);
		(*i)++;
	}
	if (check_type(str[*i]))
	{
		all.type = str[(*i)];
		// return (all);
		//(*i)++;
	}
	else
	{
		write(1, &str[*i], 1);
	}
	//   }
	return (all);
}
