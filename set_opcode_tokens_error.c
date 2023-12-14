#include "monty.h"

/**
 * set_opcode_token_error - Sets last element of opcode_tokens to
 *be an error code.
 * @error_code: Integer to store as a string in opcode_tokens.
 */
void set_opcode_token_error(int error_code)
{
	int toks_len = 0, g = 0;
	char *exit_str = NULL;
	char **new_tokens = NULL;

	toks_len = token_arr_length();
	new_tokens = malloc(sizeof(char *) * (toks_len + 2));
	if (!opcode_tokens)
	{
		malloc_error();
		return;
	}
	while (g < toks_len)
	{
		new_tokens[g] = opcode_tokens[g];
		g++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_tokens);
		malloc_error();
		return;
	}
	new_tokens[g++] = exit_str;
	new_tokens[g] = NULL;
	free(opcode_tokens);
	opcode_tokens = new_tokens;
}
