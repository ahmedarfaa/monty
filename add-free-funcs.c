#include "monty.h"

/**
 * _addnode - adding node to the head stack
 * @head: ..
 * @data: data to be added
*/
void _addnode(stack_t **head, int data)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = data;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
 * _addqueue - add node to the end of the  stack
 * @data: new_value
 * @head: ..
*/
void _addqueue(stack_t **head, int data)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = data;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
/**
* _free_stack - frees the doubly_linked_list
* @head: ..
*/
void _free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
