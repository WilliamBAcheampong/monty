#include "monty.h"

/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* No operation */
}

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * div_op - Divides the second top element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second top
 * element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the Monty byte code file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
