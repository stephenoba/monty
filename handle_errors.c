#include "monty.h"

/**
 * handle_error - handle errors
 * @error_code: error to handle
 *
 * Return: EXIT_FAILURE
 */
int handle_error(int error_code)
{
	switch (error_code)
	{
	case 1:
		malloc_failed();
		break;
	}

	if (line)
		free(line);
	exit(EXIT_FAILURE);
}

