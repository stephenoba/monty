#include "monty.h"

/**
 * op_push - push an item to the stack
 * @stack: pointer to head
 * @line_number: line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *item;
	int n;

	item = strtok(NULL, " ");
	if (!item)
	{
		raise_opcode_error(line_number, "push", *stack);
	}
	n = atoi(item);
	if (n == 0)
	{
		raise_opcode_error(line_number, "push", *stack);
	}
	push(stack, n);
}

/**
 * op_pall - print the content in the stack
 * @stack: pointer to head
 * @line_number: line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

/**
 * op_pint - print the first item in the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	peek(*stack);
}

/**
 * op_pop - remove the first item in the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	int ret;

	ret = pop(stack);
	if (ret != 0)
	{
		raise_pop_error(line_number, *stack);
	}
}
