#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}

	current = *stack;
	while (current && current->n != 0 && current->n >= 32 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
