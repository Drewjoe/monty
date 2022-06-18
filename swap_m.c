#include "monty.h"
extern var_t var;

/**
 * swap_m - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *next;
	(void)line_number;

	if (var.stack_len < 2)
	{
		handle_err(8);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}

