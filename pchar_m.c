#include "monty.h"

/**
 * m_pchar - print character from top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of current operation
 * Return: void
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (var.stack_len < 1)
	{
		pchar_err();
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		pchar_err_2();
	}
	printf("%c\n", ch);
}

/**
 * pchar_err - error in case of empty stack
 */
void pchar_err(void)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}

/**
 * pchar_err_2 - error in case value out of range
 */
void pchar_err_2(void)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}
