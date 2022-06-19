#include "monty.h"

/**
 * pchar_m - print character from top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of current operation
 * Return: void
 */
void pchar_m(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		vfprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
