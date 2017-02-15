#include <stdio.h>
#include "array_list.h"

void initList(List* p_list)
{
	p_list->number_of_data = 0;
	p_list->current_position = -1; // ����Ʈ �ʱ�ȭ ������ � ��ҵ� ����Ű�� ����.
}

void insertElement(List* p_list, ListData data)
{
	if (p_list->number_of_data >= LIST_MAX_LENGTH)
	{
		puts("Can not insert.");
	}
	else
	{
		p_list->array[p_list->number_of_data] = data;
		p_list->number_of_data++;
	}
}

Bool getFirstElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->number_of_data > 0)
	{
		p_list->current_position = 0;
		*p_data = p_list->array[0];
		result = TRUE;
	}

	return result;
}

Bool getNextElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->current_position < p_list->number_of_data - 1)
	{
		p_list->current_position++;
		*p_data = p_list->array[p_list->current_position];
		result = TRUE;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	ListData removed_data = p_list->array[p_list->current_position];

	int start_position = p_list->current_position;
	int end_position = p_list->number_of_data - 1;

	for (int i = start_position; i < end_position; i++)
	{
		p_list->array[i] = p_list->array[i + 1];
	}

	p_list->number_of_data--;
	p_list->current_position--; // ������ ����� ��ġ�� �̵��� ���� ����� ������ ���� ���� ��ġ�� �ϳ� ������ �̵�.

	return removed_data;
}
