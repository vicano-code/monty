#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* @args: op file tokenized line arguments*/
extern char *args[];

stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void split_line_args(char *line);
void (*op_func_select(void))(stack_t **head, unsigned int line_num);
void push(stack_t **head, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
void pint(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _mod(stack_t **head, unsigned int line_num);
void pchar(stack_t **head, unsigned int line_num);
void pstr(stack_t **head, unsigned int line_num);
void rotl(stack_t **head, unsigned int line_num);
void rotr(stack_t **head, unsigned int line_num);

#endif
