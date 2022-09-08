#include "monty.h"

/**
 * handle_error - handle errors
 * @error_code: error to handle
 * @stack: stack
 *
 * Return: EXIT_FAILURE
 */
int handle_error(int error_code, stack_t *stack)
{
	switch (error_code)
	{
	case 1:
		malloc_failed();
		break;
	}

	if (line)
		free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

