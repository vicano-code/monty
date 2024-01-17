#include "monty.h"

/**
 * push - push element to stack
 * @head: pointer to head node of stack
 * @line_num: line number of opcode in file
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line_num)
{
	stack_t *new, *tmp;

	if (args[1] == NULL || sizeof(atoi(args[1])) != sizeof(int))
	{
		fprintf(stderr, "%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "memory allocation failure\n");
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		*head = new;
		new->n = atoi(args[1]);
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		tmp = *head;
		new->n = atoi(args[1]);
		*head = new;
		new->prev = NULL;
		new->next = tmp;
		tmp->prev = new;
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
	if (*head != NULL)
	{
		ptr = *head;
		while (ptr->next != NULL)
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

	if ((*head)->next == NULL)
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
