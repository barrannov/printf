//
// Created by Aleksandr Baranov on 2/16/17.
//
int check_size(char c)
{
	if (c == 'l')
		return (1);
	if (c == 'L')
		return (1);
	if (c == 'h')
		return (1);
	if (c == 'j')
		return (1);
	if (c == 'z')
		return (1);
	if (c == 't')
		return (1);
	return (0);
}

int create_size(char *str, int *i)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		(*i)++;
		return (1);
	}
	if (str[*i] == 'h' && str[*i + 1] != 'h' )
		return (2);
	if ((str[*i] == 'l' ) || (str[*i] == 'j') || (str[*i] == 'z'))
		return (3);
	return (0);
}