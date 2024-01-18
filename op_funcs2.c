#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _add(stack_t **head, unsigned int line_num)
{
	/* check if stack contains at least two elements */
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
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

/**
 * _sub - subtract top element from second top element of stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _sub(stack_t **head, unsigned int line_num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n -= (*head)->n;
	pop(head, line_num);
}
/**
 * _div - divides the second top element by the top element of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _div(stack_t **head, unsigned int line_num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0 || (*head)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(head, line_num);
}

/**
 * _mul - multiplies the second top element with the top element of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _mul(stack_t **head, unsigned int line_num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n *= (*head)->n;
	pop(head, line_num);
}
