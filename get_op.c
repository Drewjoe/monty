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
