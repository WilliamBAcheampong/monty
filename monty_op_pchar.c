#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar((*stack)->n);
    putchar('\n');
}
