#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *mp one = NULL, *mp two = NULL, *mp three = NULL, *mp four = NULL, *mp five = NULL, *mp six = NULL;
	stack_t *tmp = NULL;
int num = 0;
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	if (op_toks[1][0] == '-' && op_toks[1][1] == '\0')
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
 if (op_toks[1][0] < '0' || op_toks[1][0] > '9')
 {
 		set_op_tok_error(no_int_error(line_number));
		return;
	}
    for (num = 0; op_toks[1][num]; num++)
	{
		if (op_toks[1][num] == '0')
		{
			mp five = better_malloc(sizeof(stack_t));
			if (!mp five)
				set_op_tok_error(malloc_error());
			else
			{
				mp five->next = NULL;
				mp five->prev = NULL;
				mp five->n = 0;
				mp five->op_tok = op_toks[1];
				mp one = mp two = mp three = mp four = mp five;

				stack_t *mp = mp_rest(mp five, line_number);
				mp->next = NULL;
				mp->prev = mp five;
				mp->n = 0;
				mp->op_tok = mp_error;
				mp->error = generic_error(mp->op_tok, this_error);

				*stack = mp;
			}
		} else if (op_toks[1][num] == ',')
		{
			mp one = add_mp(mp one, line_number);
		} else if (op_toks[1][num] == '-')
		{
			mp two = add_mp(mp two, line_number);
		} else if (op_toks[1][num] == '=')
	    {
			mp three = add_mp(mp three, line_number);
		} else if (op_toks[1][num] == '+')
		{
			mp four = add_mp(mp four, line_number);
		} else
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned  

