i#include "monty.h"

/**
 * pint_m - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void pint_m(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		handle_error(6);
	fprintf(stdout, "%d\n", (*stack)->n);
}
