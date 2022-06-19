#include "monty.h"

/**
 * handle_err - print errors
 * @code: exit code
 */
void handle_err(int code)
{
	error_t er[] = {
		{1, monty_usage},
		{2, file_perm},
		{3, unknown_command},
		{4, malloc_fail},
		{5, push_use},
		{6, pint_err},
		{7, pop_err},
		{8, swap_err},
		{9, add_err},
		{10, sub_err},
		{11, div_err},
		{12, _zero},
		{13, mul_err},
		{14, mod_err},
		{0, NULL}
	};
	int i = 0;

	while ((er + i)->out)
	{
		if ((er + i)->out == code)
		{
			(er + i)->error_type();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/*
 * monty_usage - error for interpreter usage
 */
void monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * file_perm - error for no permession or can t open file
 */
void file_perm(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", info.fn);
}

/**
 * unknown_command - Unknown command error
 */
void unknown_command(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			info.l_number, info.arg[0]);
		free_info();
}

/**
 * malloc_fail - error in case malloc fail
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_info();
}

/**
 * push_use - Usage of push command error
 */
void push_use(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", info.l_number);
	free_info();
}

/**
 * pint_err - error when using pint command in empty stack
 */
void pint_err(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", info.l_number);
	free_info();
}

/**
 * pop_err - error when stack is empty
 */
void pop_err(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", info.l_number);
	free_info();
}

/**
 * swap_err - error when the stack len less than 2
 */
void swap_err(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", info.l_number);
	free_info();
}

/**
 * add_err - error when add command and stack too short
 */
void add_err(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", info.l_number);
	free_info();
}

/**
 * sub_err - error when sub command and stack too short
 */
void sub_err(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", info.l_number);
	free_info();
}

/**
 * div_err - error when stack too short command div
 */
void div_err(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", info.l_number);
	free_info();
}

/**
 * _zero - error when top stack is 0 can t do div or mod command
 */
void _zero(void)
{
	fprintf(stderr, "L%d: division by zero\n", info.l_number);
	free_info();
}

/**
 * mul_err - error when stack is too short to do mul command
 */
void mul_err(void)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", info.l_number);
	free_info();
}

/**
 * mod_err - error when stack is too short to do mod command
 */
void mod_err(void)
{
	frintf(stderr, "L%d: can't mod, stack too short\n");
	free_info();
}
