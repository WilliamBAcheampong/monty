#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *tail;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tail = *stack;
	while (tail->next)
		tail = tail->next;

	temp = tail->prev;
	temp->next = NULL;

	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}
