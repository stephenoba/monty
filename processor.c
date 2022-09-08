#include "monty.h"

/**
 * process_line - processes a line in monty byte code file
 * @stack: pointer to head of stack
 * @line_number: line number
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void process_line(stack_t **stack, unsigned int line_number)
{
	char *opcode;
	instruction_t instructions[] = {
		{ "push", op_push },
		{ "pall", op_pall },
		{ NULL, NULL }
	};
	int i;

	opcode = strtok(line, " ");

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			break;
		}
	}
	if (instructions[i].opcode == NULL)
	{
		raise_opcode_error(line_number, opcode);
	}
	instructions[i].f(stack, line_number);
}
