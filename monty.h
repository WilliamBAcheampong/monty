#ifndef _MY_MONTY_H_
#define _MY_MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DELIMITERS " \n\t\a\b"


#define STACK 0
#define QUEUE 1

/* global tokens for opcode*/
extern char **opcode_tokens;

/**
 * struct stack_s - representation of a doubly linked list stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 *
* @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, FIFO
 * queues, LIFO
 */
typedef struct stack_s
{
int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function LIFO, FIFO
 * for stack, queues,
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delimiters);
char *get_int(int n);


/* basic functions for interpreter*/
int __check_mode(stack_t *stack);
void free_stack(stack_t **stack);
void free_token(void);
unsigned int token_arr_length(void);
int run_monty(FILE *script_fd);
int init_stack(stack_t **stack);
void set_opcode_token_error(int error_code);

/* functions: opcode */
void my_monty_pall(stack_t **stack, unsigned int line_number);
void my_monty_push(stack_t **stack, unsigned int line_number);

void my_monty_pint(stack_t **stack, unsigned int line_number);
void my_monty_pop(stack_t **stack, unsigned int line_number);
void my_monty_swap(stack_t **stack, unsigned int line_number);
void my_monty_add(stack_t **stack, unsigned int line_number);
void my_monty_nop(stack_t **stack, unsigned int line_number);
void my_monty_sub(stack_t **stack, unsigned int line_number);
void my_monty_div(stack_t **stack, unsigned int line_number);

void my_monty_mul(stack_t **stack, unsigned int line_number);
void my_monty_mod(stack_t **stack, unsigned int line_number);
void my_monty_pstr(stack_t **stack, unsigned int line_number);

void my_monty_pchar(stack_t **stack, unsigned int line_number);
void my_monty_rotl(stack_t **stack, unsigned int line_number);
void my_monty_rotr(stack_t **stack, unsigned int line_number);
void my_monty_stack(stack_t **stack, unsigned int line_number);
void my_monty_queue(stack_t **stack, unsigned int line_number);

/* error codes and messages */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int strange_op_error(char *opcode, unsigned int line_number);
int zero_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);


#endif /* _MY_MONTY_H_ */
