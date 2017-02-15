#include <stdlib.h>
#include "linked_list.h"

void insertFirst(List* p_list, ListData data);

void initList(List* p_list)
{
	p_list->head = (Node*)malloc(sizeof(Node)); // head�� ���� ��带 ����Ų��.
	p_list->head->next_node = NULL; // ���� ����� ���� ���� ����.
	p_list->number_of_data = 0;
	p_list->compare = NULL;
}

void insertElement(List* p_list, ListData data)
{
	// �� ������ ������ �տ��� ���� ��带 �߰��ϰ�, ������ ���ؿ� ���� ������ ��ġ�� ��带 �߰��Ѵ�.
	(p_list->compare == NULL) ? insertFirst(p_list, data) : insertFirst(p_list, data);
}

void insertFirst(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next_node = p_list->head->next_node; // �� ����� ���� ���� ���� ����� ���� ��带 �����Ѵ�.

	p_list->head->next_node = new_node; // ���� ����� ���� ���� �� ��带 �����Ѵ�.
	p_list->number_of_data++;
}

Bool getFirstElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->head->next_node != NULL)
	{
		p_list->before = p_list->head; // before�� ���� ��带 ����Ų��.
		p_list->current = p_list->head->next_node; // current�� ���� ����� ���� ��带 ����Ų��.

		*p_data = p_list->current->data;

		result = TRUE;
	}

	return result;
}

Bool getNextElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->current->next_node != NULL)
	{
		p_list->before = p_list->current;
		p_list->current = p_list->current->next_node;

		*p_data = p_list->current->data;

		result = TRUE;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	Node* removed_node = p_list->current;
	ListData removed_data = removed_node->data;

	p_list->before->next_node = p_list->current->next_node; // before�� ���� ���� ���� ����� ���� ��带 �����Ѵ�.
	p_list->current = p_list->before; // ������ ����� ���� ����� ������ ���� ���� current�� before�� ���� ��带 ����Ű���Ѵ�.

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}

void setSortRule(List* p_list, int(*compare)(ListData data1, ListData data2))
{
}
