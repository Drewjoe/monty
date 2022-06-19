#include "monty.h"

/**
 * get_op - check op against valid opcodes
 * @op: op to check
 * @stack: double pointer to the beginnig of the stack
 * @line_number: script line number
 * Return: void
 */
void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t valid_ops[] = {
		{"push", push_m},
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"add", add_m},
		{"nop", nop_m},
		{"sub", sub_m},
		{"mul", mul_m},
		{"div", div_m},
		{"mod", mod_m},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_m},
		{"queue", queue_m},
		{"pchar", pchar_m},
		{"pstr", pstr_m},
		{NULL, NULL},
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_number);
			return;
		}
	}
	handle_err(3);
}

#include "monty.h"
info_t info;
/**
 * treat_m - Treat The Monty File
 * @filename: Filename From Argument
 * Return: Data Of The Monty File
 */
int treat_m(char *filename)
{
	ssize_t n_r = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	info.fn = filename;
	info.fp = fopen(info.fn, "r");
	if (info.fp == NULL)
		handle_err
		(2);
	while ((n_r = getline(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_number++;
		free(info.arg);
		if (split() < 0)
			continue;
		if (info.arg == NULL)
			continue;
		get_op(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}
