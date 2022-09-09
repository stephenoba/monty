#include "monty.h"

/**
 * malloc_failed - failure with malloc
 */
void malloc_failed(void)
{
	write(2, "Error: malloc failed\n", 21);
}

/**
 * raise_push_error - error with opecode
 * @line_number: line number
 * @stack: stack
 */
void raise_push_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * raise_pop_error - error with removing node
 * @line_number: line number
 * @stack: stack
 */
void raise_pop_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * raise_pint_error - error with removing node
 * @line_number: line number
 * @stack: stack
 */
void raise_pint_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * raise_swap_error - error with removing node
 * @line_number: line number
 * @stack: stack
 */
void raise_swap_error(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
