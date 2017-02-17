#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

void initList(List* p_list)
{
	Node* dummy_node = (Node*)malloc(sizeof(Node));
	dummy_node->next_node = NULL;
	dummy_node->pre_node = NULL;

	p_list->head = dummy_node;
	p_list->current = NULL;

	p_list->number_of_data = 0;
}

void insertElement(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->pre_node = p_list->head;
	new_node->next_node = p_list->head->next_node;

	if (p_list->head->next_node != NULL)
	{
		p_list->head->next_node->pre_node = new_node;
	}
	p_list->head->next_node = new_node;

	p_list->number_of_data++;
}

bool getFirstElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->head->next_node != NULL)
	{
		p_list->current = p_list->head->next_node;
		*p_data = p_list->current->data;
		result = true;
	}

	return result;
}

bool getNextElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->current->next_node != NULL)
	{
		p_list->current = p_list->current->next_node;
		*p_data = p_list->current->data;
		result = true;
	}

	return result;
}

bool getPreviousElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->current->pre_node != p_list->head)
	{
		p_list->current = p_list->current->pre_node;
		*p_data = p_list->current->data;
		result = true;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	Node* removed_node = p_list->current;
	ListData removed_data = removed_node->data;

	if (removed_node->next_node != NULL)
	{
		removed_node->next_node->pre_node = removed_node->pre_node;
	}
	removed_node->pre_node->next_node = removed_node->next_node;

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}
