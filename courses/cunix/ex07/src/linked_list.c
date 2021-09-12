#include <stdlib.h>
#include <stdio.h>
#include <linked_list.h>

node_t *list_create(void *data)
{
	node_t *head = (node_t*) malloc(sizeof(node_t));
	node_t *first = (node_t*) malloc(sizeof(node_t));

	head->data = NULL;
	head->next = first;
	first->data = data;
	first->next = NULL;

	return head;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
	node_t *prev_node = *head;
	node_t *current = prev_node->next;
	while(current->next != NULL)
	{
		fp(prev_node->data);
		free(prev_node);
		prev_node = current;
		current = current->next;
	}
}

void list_push(node_t *head, void *data)
{
	node_t* current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}
	node_t *last = (node_t*) malloc(sizeof(node_t));
	current->next = last;
	last->data = data;
	last->next = NULL;
}

void list_unshift(node_t **head, void *data)
{
	node_t *new_first = (node_t*) malloc(sizeof(node_t));

	new_first->data = data;
	new_first->next = (*head)->next;
	(*head)->next = new_first;
}

void *list_pop(node_t **head)
{
	node_t* pre_last = *head;
	while(pre_last->next->next != NULL)
	{
		pre_last = pre_last->next;
	}
	node_t* ret_node = pre_last->next;
	pre_last = NULL;
	return ret_node->data;
}

void *list_shift(node_t **head)
{
	node_t* ret_node = (*head)->next;
	(*head)->next = ret_node->next;
	return ret_node->data;
}

void *list_remove(node_t **head, int pos)
{
	node_t* current = (*head)->next;
	int num = 0;
	while(num == pos-1)
	{
		current = current->next;
	}
	node_t *ret_node = current->next;
	current->next = ret_node->next;
	return ret_node->data;
}

void list_print(node_t *head)
{
	node_t *current = head->next;
	while(current->next != NULL)
	{
		printf("%p", current->data);
		current = current->next;
	}
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
	node_t *current = head->next;
	while(current->next != NULL)
	{
		fp(current->data);
		current = current->next;
	}
}
