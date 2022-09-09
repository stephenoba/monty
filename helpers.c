#include "monty.h"

/**
 * is_number - checks if a given string is a number
 * @str: string
 *
 * Return: 0 or 1
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
