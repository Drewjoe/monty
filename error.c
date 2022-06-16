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

