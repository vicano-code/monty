#include "monty.h"

/**
 * _mod - reminder of the division of the second top element
 * by the top element of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void _mod(stack_t **head, unsigned int line_num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0 || (*head)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n %= (*head)->n;
	pop(head, line_num);
}

/**
 * pchar - prints the char at the top of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void pchar(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n >= 0 && (*head)->n <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;
	ptr = *head;
	while (ptr != NULL && ptr->n != 0 &&
			(*head)->n >= 0 && (*head)->n <= 127)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");

}

/**
 * rotl - rotates the stack to the top. The top element becomes
 * the last one, and the second top element becomes the first one
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;
	ptr = *head;

	if (ptr->next == NULL)
	{
		while (ptr)
			ptr = ptr->next;
		ptr->next = *head;
		(*head)->prev = ptr;
		ptr->next->next = NULL;
		*head = (*head)->next;
		(*head)->next->prev = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom. The last element
 * of the stack becomes the top element of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;
	ptr = *head;
	if ((*head)->next != NULL)
	{
		while (ptr)
			ptr = ptr->next;
		(*head)->prev = ptr;
		ptr->next = *head;
		ptr->prev->next = NULL;
		ptr->prev = NULL;
		*head = ptr;

	}
}
