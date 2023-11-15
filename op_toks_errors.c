#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = token_arr_len();
	char **new_toks;

	new_toks = realloc(op_toks, sizeof(char *) * (toks_len + 2));
	if (!new_toks)
	{
		malloc_error();
		return;
	}
	op_toks = new_toks;
	op_toks[toks_len] = get_int(error_code);
	if (!op_toks[toks_len])
	{
		malloc_error();
		return;
	}
	op_toks[toks_len + 1] = NULL;
}

