#include "monty.h"
void my_monty_pchar(stack_t **stack, unsigned int line_number);

void my_monty_nop(stack_t **stack, unsigned int line_number);
void my_monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * my_monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * my_monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}

/**
 * my_monty_pchar - Prints the character in the top value
 * node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_opcode_token_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_opcode_token_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
