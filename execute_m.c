#include "monty.h"
#include <stdio.h>

/**
 * exec_m - check op against valid opcodes
 * @op: op to check
 * @stack: double pointer to the beginnig of the stack
 * @line_number: script line number
 * Return: void
 */
void exec_m(stack_t **stack)
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
		if (strcmp(valid_ops[i].opcode, *info.arg) == 0)
		{
			valid_ops[i].f(stack, info.l_number);
			return;
		}
	}
	handle_err(3);
}

info_t info;
/**
 * treat_m - Treat the monty file
 * @filename: filename from argument
 * Return: data of the monty File
 */
int treat_m(char *filename)
{
	ssize_t n_r = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	info.fn = filename;
	info.fp = fopen(info.fn, "r");
	if (info.fp == NULL)
		handle_err(2);
	while ((n_r = fget(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_number++;
		free(info.arg);
		if (split() < 0)
			continue;
		if (info.arg == NULL)
			continue;
		exec_m(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}
/**
 * split - Split The Line Into Command and Arguments
 *Return: 0 On Success 1 On Failure
 */
int split(void)
{
	char *token;
	size_t bufsize = 20, i = 0;

	info.arg = malloc(bufsize * sizeof(char *));
	if (info.arg == NULL)
		handle_err(4);
	token = strtok(info.cmd, "\n\t\r ");
	while (token)
	{
		info.arg[i++] = token;
		if (i >= bufsize)
		{
			info.arg = realloc(info.arg, bufsize, bufsize * 2);
			if (info.arg == NULL)
			{
				handle_error(1);
			}
		}
		token = strtok(NULL, "\n\t\r ");
	}
	info.arg[i] = NULL;
	if (**info.arg == '#')
		return (-1);
	return (0);
}
