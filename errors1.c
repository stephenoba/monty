#include "monty.h"

/**
 * malloc_failed - failure with malloc
 */
void malloc_failed(void)
{
	write(2, "Error: malloc failed\n", 21);
}

/**
 * raise_opcode_error - error with opecode
 * @line_number: line number
 * @opcode: opcode
 * @stack: stack
 */
void raise_opcode_error(unsigned int line_number, char *opcode, stack_t *stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * raise_operation_error- raises error where execution of opcode fails
 * @msg: an error message, must end with a new line
 * @line_number: line where error occured
 * @stack: pointer to head of stack
 */
void raise_operation_error(char *msg, unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, msg, line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
