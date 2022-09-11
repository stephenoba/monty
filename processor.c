#include "monty.h"

/**
 * get_instruction - gets instruction
 * @opcode: opcode to search for
 *
 * Return: instruction
 */
instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{ "push", op_push },
		{ "pall", op_pall },
		{ "pint", op_pint },
		{ "pop", op_pop },
		{ "swap", op_swap },
		{ "add", op_add },
		{ "sub", op_sub },
		{ "nop", op_nop },
		{ "div", op_div },
		{ "mul", op_mul },
		{ "mod", op_mod },
		{ "pchar", op_pchar },
		{ "pstr", op_pstr },
		{ "rotl", op_rotl },
		{ "rotr", op_rotr },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			break;
		}
	}
	return (instructions[i]);
}

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
	instruction_t instruction;

	opcode = strtok(line, " ");
	instruction = get_instruction(opcode);

	if (instruction.opcode == NULL)
	{
		if (opcode[0] != '#')
			raise_opcode_error(line_number, opcode, *stack);
		op_nop(stack, line_number);
	}
	else
	{
		instruction.f(stack, line_number);
	}
}
