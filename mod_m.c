#include "monty.h"

/**
 * mod_m - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		handle_err(14);
	}
	n = (*stack)->n;
	pop_m(stack, line_number);
	if (n == 0)
	{
		handle_err(12);
	}
	(*stack)->n %= n;
}
