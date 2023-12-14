#include "monty.h"

void my_monty_push(stack_t **stack, unsigned int line_number);
void my_monty_swap(stack_t **stack, unsigned int line_number);
void my_monty_pint(stack_t **stack, unsigned int line_number);
void my_monty_pop(stack_t **stack, unsigned int line_number);

void my_monty_pall(stack_t **stack, unsigned int line_number);



/**
 * my_monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * my_monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_opcode_token_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * my_monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_opcode_token_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}



/**
 * my_monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_opcode_token_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * my_monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty
 * bytecodes file.
 */
void my_monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new1;
	int k;

	new1 = malloc(sizeof(stack_t));
	if (new1 == NULL)
	{
		set_opcode_token_error(malloc_error());
		return;
	}

	if (opcode_tokens[1] == NULL)
	{
		set_opcode_token_error(zero_int_error(line_number));
		return;
	}

	for (k = 0; opcode_tokens[1][k]; k++)
	{
		if (opcode_tokens[1][k] == '-' && k == 0)
			continue;
		if (opcode_tokens[1][k] < '0' || opcode_tokens[1][k] > '9')
		{
			set_opcode_token_error(zero_int_error(line_number));
			return;
		}
	}
	new1->n = atoi(opcode_tokens[1]);

	if (__check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new1->prev = *stack;
		new1->next = tmp;
		if (tmp)
			tmp->prev = new1;
		(*stack)->next = new1;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new1->prev = tmp;
		new1->next = NULL;
		tmp->next = new1;
	}
}
