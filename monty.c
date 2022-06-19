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
	char *arg = NULL,
	info.cmd = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;

	if (argc != 2)
	{
		handle_err(1);
	}
	info.fp = fopen(argv[1], "r");
	if (info.fp == NULL)
	{
		handle_err(2);
	}
	_exit(free_info, &arg);
	_exit(free_list, &stack);
	_exit(free_info, info.fp);
	while (getline(&arg, &n, info.fp) != -1)
	{
		info.l_number++;
		info.cmd = strtok(arg, "\n\t\r ");
		if (info.cmd != NULL && info.cmd[0] != '#')
		{
			get_op(info.cmd, &stack, info.l_number);
		}
	}
	exit(EXIT_SUCCESS);
}
