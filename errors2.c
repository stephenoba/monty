#include "monty.h"

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
 * raise_add_error - error with removing node
 * @line_number: line number
 * @stack: stack
 */
void raise_add_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * raise_sub_error - error with removing node
 * @line_number: line number
 * @stack: stack
 */
void raise_sub_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
