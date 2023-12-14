#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;

    while (first->next)
        first = first->next;

    last = first->prev;
    last->next = NULL;
    first->prev = NULL;
    first->next = *stack;
    (*stack)->prev = first;
    *stack = first;
}
