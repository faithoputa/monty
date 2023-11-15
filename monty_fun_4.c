#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int value, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if (*stack == NULL || top->next == NULL || top->next->next == NULL)
		return;

	top = *stack;
	bottom = top->next->next;
	top->next->next->prev = *stack;
	*stack = top->next;
	top->next->next = bottom;
	bottom->prev = *stack;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if (*stack == NULL || top->next == NULL || top->next->next == NULL)
		return;

	top = *stack;
	bottom = top->next->next;
	top->next->next->prev = NULL;
	*stack = bottom;
	bottom->prev = *stack;
	bottom->next = top;

	(void)line_number;
}

/**
 * monty_push - Adds a value to the top of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @value: The value to add to the top of the stack.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * monty_queue - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = NULL;
	current->prev = NULL;
}

