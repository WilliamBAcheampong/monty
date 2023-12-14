#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <string.h>


void free_token(void);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
unsigned int token_arr_length(void);
int run_monty(FILE *script_fd);
int is_emptyLine(char *line, char *delimiters);

/**
 * free_token - Frees the global opcode_tokens array of strings.
 */
void free_token(void)
{
	size_t f = 0;

	if (opcode_tokens == NULL)
		return;

	for (f = 0; opcode_tokens[f]; f++)
		free(opcode_tokens[f]);

	free(opcode_tokens);
}

/**
 * token_arr_length - Gets the length of current opcode_tokens.
 *
 * Return: Length of current opcode_tokens (as int).
 */
unsigned int token_arr_length(void)
{
	unsigned int toks_len = 0;

	while (opcode_tokens[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_emptyLine - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delimiters: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_emptyLine(char *line, char *delimiters)
{
	int c, v;

	for (c = 0; line[c]; c++)
	{
		for (v = 0; delimiters[v]; v++)
		{
			if (line[c] == delimiters[v])
				break;
		}
		if (delimiters[v] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", my_monty_push},
		{"pall", my_monty_pall},
		{"swap", my_monty_swap},
		{"pint", my_monty_pint},
		{"pop", my_monty_pop},

		{"add", my_monty_add},
		{"nop", my_monty_nop},
		{"sub", my_monty_sub},
		{"div", my_monty_div},
		{"pchar", my_monty_pchar},
		{"mul", my_monty_mul},
		{"mod", my_monty_mod},

		{"pstr", my_monty_pstr},
		{"rotr", my_monty_rotr},
		{"rotl", my_monty_rotl},

		{"stack", my_monty_stack},
		{"queue", my_monty_queue},
		{NULL, NULL}
	};
	int y;

	for (y = 0; op_funcs[y].opcode; y++)
	{
		if (strcmp(opcode, op_funcs[y].opcode) == 0)
			return (op_funcs[y].f);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		opcode_tokens = strtow(line, DELIMITERS);
		if (opcode_tokens == NULL)
		{
			if (is_emptyLine(line, DELIMITERS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (opcode_tokens[0][0] == '#') /* comment line */
		{
			free_token();
			continue;
		}
		op_func = get_op_func(opcode_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = strange_op_error(opcode_tokens[0], line_number);
			free_token();
			break;
		}
		prev_tok_len = token_arr_length();
		op_func(&stack, line_number);
		if (token_arr_length() != prev_tok_len)
		{
			if (opcode_tokens && opcode_tokens[prev_tok_len])
				exit_status = atoi(opcode_tokens[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_token();
			break;
		}
		free_token();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
