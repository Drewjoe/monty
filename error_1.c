#include "monty.h"

/**
 * malloc_fail - error in case malloc fail
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_info();
}

/**
 *push_use - Usage of push command error
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
