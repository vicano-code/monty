#include "monty.h"

/**
 * push - push element to stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line_num)
{

	if (args[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[1], "-0") == 0)
		args[1] = "0";
	if (strcmp(args[1], "0") != 0 && atoi(args[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	if (add_dnodeint(head, atoi(args[1])) == NULL)
	{
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print stack elements
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	(void)line_num;
	if (head != NULL || *head != NULL)
	{
		ptr = *head;
		while (ptr)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *ptr;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(ptr);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(ptr);
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *tmp, *ptr;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	ptr = (*head)->next;
	if (ptr->next == NULL)
	{
		tmp->next = NULL;
		tmp->prev = ptr;
		ptr->prev = NULL;
		ptr->next = tmp;
		*head = ptr;
	}
	else
	{
		tmp->next = ptr->next;
		tmp->prev = ptr;
		ptr->prev = NULL;
		ptr->next = tmp;
		*head = ptr;
	}
}
