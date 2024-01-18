#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *ptr, *tmp;
	int i = 0;
	int j = 0;
	int result = 0;

	tmp = *head;
	/* check if stack contains at least two elements */
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	
	ptr = *head;
	while (j < 2)
	{
		result += ptr->n;
		ptr = ptr->next;
		j++;
	}
	(*head)->next->n = result;
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
