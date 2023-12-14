#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    /* Check for proper usage */
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

    /* Call the Monty interpreter function with the file path from argv[1] */
	monty_interpreter(argv[1]);

	return (EXIT_SUCCESS);
}
