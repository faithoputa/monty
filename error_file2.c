#define LINE_PREFIX "L%u: "
#define SHORT_STACK_ERR_MESSAGE "can't %s, stack too short"
#define DIV_ZERO_ERR_MESSAGE " division by zero"
#define PCHAR_ERR_MESSAGE "can't pchar, %s"

/**
 * error_func - Prints generic error messages for Monty bytecodes.
 * @line_number: Line number where error occurred.
 * @op: Operation where the error occurred.
 * @code: Error code representing the type of error.
 *
 * Return: (EXIT_FAILURE) always.
 */
int error_func(unsigned int line_number, char *op, int code)
{
    char *error_message;

    switch (code) {
        case ERROR_POP:
            error_message = op == NULL
                             ? POP_ERR_MESSAGE
                             : POP_ERR_MESSAGE_WITH_OP;
            break;
        case ERROR_PINT:
            error_message = pint_function_error(line_number, code);
            break;
        case ERROR_DIV:
            error_message = div_function_error(line_number, code);
            break;
        // add more cases for other errors
        default:
            error_message = "";
            break;
    }

    if (!error_message) {
        fprintf(stderr, LINE_PREFIX "[unknown error]");
    } else {
        fprintf(stderr, LINE_PREFIX "%s", error_message);
    }

    return EXIT_FAILURE;
}

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
    return error_func(line_number, NULL, ERROR_POP);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error
 *              occurred.
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_number)
{
    return error_func(line_number, NULL, ERROR_PINT);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error
 *             occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
    return error_func(line_number, op, ERROR_SHORT_STACK);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @line_  
*/
