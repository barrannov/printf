//
// Created by Aleksandr Baranov on 2/15/17.
//
int check_flag(char c)
{
	int i;

	i = 0;
	char type[6] = "-0+ #";
	while (type[i])
	{
		if (c == type[i])
			return (1);
		i++;
	}
	return (0);
}
