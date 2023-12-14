#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    last = first;

    while (last->next)
        last = last->next;

    first->prev = last;
    last->next = first;
    *stack = first->next;
    first->next = NULL;
    (*stack)->prev = NULL;
}
