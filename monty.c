#include "monty.h"
var_t var;
info_t info;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	info.l_number = 0;
	info.fp = NULL;
	char *arg = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;

	if (argc != 2)
	{
		handle_err(1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		handle_err(2);
	}
	on_exit(free_info, &arg);
	on_exit(free_list, &stack);
	on_exit(free_info, fp);
	while (getline(&arg, &n, fp) != -1)
	{
		l_number++;
		op = strtok(arg, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, l_number);
		}
	}
	exit(EXIT_SUCCESS);
}
