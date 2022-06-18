#include "monty.h"

/**
 * pop_m - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 * Return: void
 */
void pop_m(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;
	(void)line_number;

	if (*stack == NULL)
		handle_err(7);
	pop = pop->next;
	free(*stack);
	*stack = pop;
	if (pop != NULL)
		pop->prev = NULL;
}
