#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;
	int result;

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*head)->next;
	result = (*head)->n + ptr->n;
	ptr->n = result;
	pop(head, line_num);
}

/**
 * nop - Do nothing
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
}
