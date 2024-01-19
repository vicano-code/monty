#include "monty.h"

/**
 * op_func_select - select function for opcode
 * @void - no argument
 * Return: Nothing
 */
void (*op_func_select(void))(stack_t **h, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	while (ops[i].opcode != NULL)
	{
		if (strcmp(args[0], ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
