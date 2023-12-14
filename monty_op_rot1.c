#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *tail;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;

	tail = *stack;
	while (tail->next)
		tail = tail->next;

	temp->prev = tail;
	temp->next = NULL;
	tail->next = temp;
}
