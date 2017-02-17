#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

void initList(List* p_list)
{
	p_list->head = NULL;
	p_list->current_position = NULL;
	p_list->number_of_data = 0;
}

void insertElement(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	new_node->next_node = p_list->head;
	new_node->pre_node = NULL;

	if (p_list->head != NULL)
	{
		p_list->head->pre_node = new_node;
	}
	p_list->head = new_node;

	p_list->number_of_data++;
}

bool getFirstElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->head != NULL)
	{
		p_list->current_position = p_list->head;
		*p_data = p_list->current_position->data;
		result = true;
	}

	return result;
}

bool getNextElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->current_position->next_node != NULL)
	{
		p_list->current_position = p_list->current_position->next_node;
		*p_data = p_list->current_position->data;
		result = true;
	}

	return result;
}

bool getPreviousElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->current_position->pre_node != NULL)
	{
		p_list->current_position = p_list->current_position->pre_node;
		*p_data = p_list->current_position->data;
		result = true;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	Node* removed_node = p_list->current_position;
	ListData removed_data = removed_node->data;

	if (removed_node == p_list->head)
	{
		if (removed_node->next_node == NULL)
		{
			p_list->head = NULL;
		}
		else
		{
			removed_node->next_node->pre_node = removed_node->pre_node;
		}
	}
	else if (removed_node->next_node == NULL)
	{
		removed_node->pre_node->next_node = removed_node->next_node;
	}
	else
	{
		removed_node->pre_node->next_node = removed_node->next_node;
		removed_node->next_node->pre_node = removed_node->pre_node;
	}

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}
