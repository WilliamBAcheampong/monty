#include "monty.h"
int f_open_error(char *filename);
int usage_error(void);
int zero_int_error(unsigned int line_number);
int malloc_error(void);
int strange_op_error(char *opcode, unsigned int line_number);

/**
 * usage_error - this prints error messages during usage.
 *
 * Return: always (EXIT_FAILURE).
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * zero_int_error - Prints invalid push argument error messages.
 * @line_number: Line number in file
  * where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int zero_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * f_open_error - Prints file opening error messages with file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * strange_op_error - Print strange error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int strange_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}
