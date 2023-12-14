#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int value;

    if (!stack)
    {
        fprintf(stderr, "L%d: stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(global_data.argument);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (!*stack)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
