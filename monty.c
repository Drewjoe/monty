#include "monty.h"

/**
 * main - an interpreter for monty byteCodes files.
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit_Succes(0) or Exit_Failure(1)
 */
int main(int argc, char **argv)
{
	info.type = STACK;
	if (argc != 2)
		handle_error(1);
	else
	{
	treat_monty(argv[1]);
	}
	return (EXIT_SUCCESS);
}
