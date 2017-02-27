#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

void insertFirst(List* p_list, ListData data);
void insertSort(List* p_list, ListData data);

void initList(List* p_list)
{
	// head�� ���� ��带 ����Ų��.
	p_list->head = (Node*)malloc(sizeof(Node));
	p_list->head->next_node = NULL;
	p_list->number_of_data = 0;
	p_list->compare = NULL;
}

void insertElement(List* p_list, ListData data)
{
	// ���� ������ ������ �տ��� ���� ��带 �߰��ϰ�, ������ ���ؿ� ���� ������ ��ġ�� ��带 �߰��Ѵ�.
	(p_list->compare == NULL) ? insertFirst(p_list, data) : insertSort(p_list, data);
}

void insertFirst(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next_node = p_list->head->next_node;

	p_list->head->next_node = new_node;
	p_list->number_of_data++;
}

void insertSort(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;

	Node* target = p_list->head;

	// ���� ����� ���� ������ ������ ������ ���Ѵ�.
	while (target->next_node != NULL && p_list->compare(target->next_node->data, data) > 0)
	{
		// ���� �ϴ� ����� �����Ͱ� ������ �����̸� target�� �������� �̵��Ѵ�.
		target = target->next_node;
	}

	new_node->next_node = target->next_node;
	target->next_node = new_node;
	p_list->number_of_data++;
}

bool getFirstElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->head->next_node != NULL)
	{
		p_list->before = p_list->head;
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

	p_list->before->next_node = p_list->current->next_node;
	p_list->current = p_list->before;

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}

void setSortRule(List* p_list, Compare compare)
{
	p_list->compare = compare;
}
