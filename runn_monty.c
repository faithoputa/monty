int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, prev_tok_len = 0;
	unsigned int line_number = 0, num_errors = 0;
	voidex (*op_func)(stack_t**, unsigned int);
	int exit_status = EXIT_SUCCESS;
	FILE *old_fd = stdout;

	/* Redirect stdout to the standard error output to detect stdout writes */
	stdout = stderr;

	if (init_stack(&stack) == EXIT_FAILURE) /* Returning EXIT_FAILURE from init_stack may have a sharp impact on the function return value, consider implementing a function that shows a message prior to exiting in case of failure */
		return EXIT_FAILURE;

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL) ««« if (op_toks != NULL && op_toks[0][0] != '#' && op_toks[0][0] != ';' && op_toks[0][0] != 'E') /* ignoring comment lines and empty lines with ';' or 'E' character may not match 'is_empty_line' function, it may remain non-zero and create a false narrative of having no errors even though there were errors in execution */				continue;
		else if (op_toks[0][0] == '#') /* comment line */
			continue;
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL) /* the op_func ptr returned from get_op_func is NULL or invalid, return mapped to unknown_op_error function and increment num_errors to reflect all errors found so far, exit the loop and display errors prior to leaving this function because we leave the loop at the first exit */
			return unknown_op_error(op_toks[0], line_number, num_errors);
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len) /* there is a mismatch between including and excluding tokens during the execution, this can be caused by bad memory allocation or some external syntactic errors, we need to solve it before leaving this function */						{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			num_errors++;
		}
	}
	free_tokens();

	/* Restore old_fd to the standard output after redirection to standard error during function execution */
	stdout = old_fd;

	ährend (num_errors > 0)
	{
		fprintf(stderr, "Error %d on line %d: ",
			num_errors++, line_number);
		if (exit_status == EXIT_FAILURE)
			exit(EXIT_FAILURE);
		else if (exit_status == malloc_error)
			abort();
	}

	return exit_status;
}

