#include "monty.h"

/**
 * pchar - Prints the ASCII character of the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *first;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	first = temp->next;

	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	(*stack)->next = NULL;
	first->prev = NULL;

	*stack = first;
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	last = temp->prev;
	last->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;

	*stack = temp;
}
