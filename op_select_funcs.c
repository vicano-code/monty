#include "monty.h"

/**
 * op_select_func - select function for opcode
 * @h: head node of stack
 * @line_num: line number of opcode
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
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(args[0], ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
