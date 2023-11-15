/**
 * monty_nop - Do nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void monty_nop(stack_t *stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Print the character in the top value of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t *stack, unsigned int line_number)
{
	if (!stack->next)
	{
		set_op_tok_error(pchar_error(line_number, "Stack is empty"));
		return;
	}

	if (stack->next->n < 0 || stack->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "Value out of range"));
		return;
	}

	putchar(stack->next->n);
}

/**
 * monty_pstr - Print the string in the top value of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t *stack, unsigned int line_number)
{
	stack_t *tmp = stack->next;

	while (tmp && tmp->n && (tmp->n > 0 && tmp->n <= 127))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}

	putchar('\n');

	(void)line_number;
}

