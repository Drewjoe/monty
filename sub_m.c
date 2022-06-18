#include "monty.h"

/**
 * sub_m - subtracts the top element of the stack
 * @stack: Pointer To The head
 * @line_number: The Line Number
 * Return:Void
 */
void sub_m(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		handle_err(10);
	}
	n = (*stack)->n;
	pop_m(stack, line_number);
	(*stack)->n -= n;
}
