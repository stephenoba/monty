#include "monty.h"
#include <string.h>

char *line = NULL;

void push(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	write(1, "push", 4);
}

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	write(1, "pallyyyyyy\n", 11);
}


/**
 * get_opcode - get opcode from line
 *  *
 */
char *get_opcode(void)
{
	return ("pall");
}

/**
 * main - Entry point to`monty bytecode interprter`
 * @ac: argument count
 * @av: filepath
 *
 * Return: EXIT_SUCCESS on success of EXIT_FAILURE on failure
 */
int main(int ac, char *av[])
{
	FILE *stream;
	size_t len = 0;
	ssize_t wc;
	unsigned int lc;

	UNUSED(lc);
	if (ac != 2)
	{
		/* we can use fprintf here */
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((wc = getline(&line, &len, stream)) != -1)
	{
		printf("Retrieved line of length %ld\n", wc);
		fwrite(line, wc, 1, stdout);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
