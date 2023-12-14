#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    if (*stack)
        (*stack)->prev = NULL;
}
