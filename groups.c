//
// Created by Aleksandr Baranov on 2/21/17.
//

int isgrop1(char c)
{
	if(c == 'd' || c == 'i' )
		return (1);
	return (0);
}

int isgrop2(char c)
{
	if(
			c == 'p' ||
			c == 'o' ||
			c == 'O' ||
			c == 'u' ||
			c == 'U' ||
			c == 'X' ||
			c == 'x' ||
			c == 'C' ||
			c == 'c')
		return (1);
	return (0);
}

