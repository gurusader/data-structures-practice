#include <stdlib.h>
#include <stdbool.h>
#include "circular_linked_list.h"

void initList(List* p_list)
{
	p_list->tail = NULL;
	p_list->before = NULL;
	p_list->current = NULL;
	p_list->number_of_data = 0;
}

void insertElementHead(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	if (p_list->tail == NULL)
	{
		p_list->tail = new_node;

		// 처음 삽입한 노드의 다음 노드는 자기 자신이다.
		new_node->next_node = new_node;
	}
	else
	{
		new_node->next_node = p_list->tail->next_node;
		p_list->tail->next_node = new_node;
	}

	p_list->number_of_data++;
}

void insertElementTail(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	if (p_list->tail == NULL)
	{
		p_list->tail = new_node;
		new_node->next_node = new_node;
	}
	else
	{
		new_node->next_node = p_list->tail->next_node;
		p_list->tail->next_node = new_node;

		// tail이 새로 삽입한 노드를 가리킨다.
		p_list->tail = new_node;
	}

	p_list->number_of_data++;
}

bool getFirstElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->tail != NULL)
	{
		p_list->before = p_list->tail;

		// tail의 다음 노드는 첫 노드이다.
		p_list->current = p_list->tail->next_node;

		*p_data = p_list->current->data;

		result = true;
	}

	return result;
}

bool getNextElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->tail != NULL)
	{
		p_list->before = p_list->current;
		p_list->current = p_list->current->next_node;

		*p_data = p_list->current->data;

		result = true;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	Node* removed_node = p_list->current;
	ListData removed_data = removed_node->data;

	// 삭제할 노드가 tail이 가리키는 노드일 때
	if (removed_node == p_list->tail)
	{
		// 노드가 하나만 남아있다면 tail에 NULL을 대입한다.
		if (p_list->tail == p_list->tail->next_node)
		{
			p_list->tail = NULL;
		}
		else
		{
			p_list->tail = p_list->before;
		}
	}

	p_list->before->next_node = p_list->current->next_node;
	p_list->current = p_list->before;

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}
