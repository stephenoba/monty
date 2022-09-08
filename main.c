#include "monty.h"
#include <string.h>

char *line = NULL;

char *func(void)
{
	return strtok(NULL, " ");
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
	char *opcode;

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
		opcode = strtok(line, " ");
		printf("Retrieved line of length %ld with opcode %s\n", wc, opcode);
		printf("and item %s\n", func());
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
