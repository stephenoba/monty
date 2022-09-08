#include "monty.h"

/**
 * malloc_failed - failure with malloc
 */
void malloc_failed(void)
{
	write(2, "Error: malloc failed\n", 21);
}

void raise_opcode_error(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free(line);
	exit(EXIT_FAILURE);
}
