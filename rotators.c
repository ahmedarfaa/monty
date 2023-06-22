#include "monty.h"

/**
  *_rotr- a rotator for the stack
  *@head: head of the stack
  *@count: number of lines
 */

void _rotr(stack_t **head, unsigned int count)
{
	stack_t *copy;
	(void)count;
	copy = *head;
	if (*head == 0 || (*head)->next == 0)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
  *_rotl- a function that rotates
  *@head: head of the stack
  *@count: number of lines
 */

void _rotl(stack_t **head, unsigned int count)
{
	stack_t *tmp = *head;
	stack_t *tot = *head;
	(void)count;

	if (*head == 0 || (*head)->next == 0)
	{
		return;
	}
	tot = (*head)->next;
	tot->prev = 0;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = 0;
	(*head)->prev = tmp;
	(*head) = tot;
}

