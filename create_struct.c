//
// Created by aleksandr on 11.02.17.
//
#include "ft_printf.h"

int create_numbers(char *str, int *i)
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



int check_precision(char c)
{
	if(c == '.')
		return (1);
	return (0);
}

int check_size(char c)
{
	if(c == 'l')
		return (1);
	if(c == 'L')
		return (1);
	if(c == 'h')
		return (1);
	if(c == 'j')
		return (1);
	if(c == 'z')
		return (1);
	if(c == 't')
		return (1);
	return (0);
}

char *create_size(char *str, int i)
{

}

t_var create_struct(int *i, char *str, t_var all)
{
/*This function adds all specification to structure*/
	//t_var all;

int temp;
	// if(str[(*i)] == '%')
	//   (*i)++;
	//  while (str[(*i)]) {
	temp = 0;
	if (check_flag(str[*(i)]))
	{
		all.flags = create_flags(str, i);
		// return (all);
	//	printf("  flags: %s", all.flags);
		(*i)++;
		return 	create_struct(i, str, all);
	}
	if (check_width(str[*i]))
	{
		all.width = create_numbers(str, i);
	//	printf("  width: %d", all.width);
		(*i)++;
		return  create_struct(i, str, all);
	}
	if(check_precision(str[*i]))
	{
		(*i)++;
			temp = 	create_numbers(str, i);
		if(temp > 0)
			all.precision = temp;
		//printf("   precision: %d", all.precision);
		(*i)++;
		//free_struct(&all);
		return 	create_struct(i, str, all);
	}
	/*if(check_size(str[*i]))
	{
		all.size = create_size()
		(*i)++;
	}*/
	if (check_type(str[*i]))
	{
		all.type = str[(*i)];
	//	printf("    type: %c", all.type);
		// return (all);
		//(*i)++;
	}
	//printf("  flags: %s", all.flags);
	//printf("  width: %d", all.width);
	//printf("   precision: %d", all.precision);
	//printf("    type: %c", all.type);

//	else
//	{
//		write(1, &str[*i], 1);
//	}
	//   }
	return (all);
}
