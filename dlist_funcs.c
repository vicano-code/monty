#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: pointer to the head node of the list
 * @n: new node value
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if ((*head) == NULL)
	{
		*head = new;
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->n = n;
		new->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}

/**
 * free_dlistint - frees a stack_t list.
 * @head: pointer to head node of list
 * Return: Nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *ptr;

	if (head == NULL)
		return;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}
