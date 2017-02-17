#include <stdio.h>
#include <stdbool.h>
#include "array_list.h"

void initList(List* p_list)
{
	p_list->number_of_data = 0;
	p_list->current_position = -1;
}

void insertElement(List* p_list, ListData data)
{
	if (p_list->number_of_data >= LIST_MAX_LENGTH)
	{
		puts("List is full.");
	}
	else
	{
		p_list->array[p_list->number_of_data] = data;
		p_list->number_of_data++;
	}
}

bool getFirstElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->number_of_data > 0)
	{
		p_list->current_position = 0;
		*p_data = p_list->array[0];
		result = true;
	}

	return result;
}

bool getNextElement(List* p_list, ListData* p_data)
{
	bool result = false;

	if (p_list->current_position < p_list->number_of_data - 1)
	{
		p_list->current_position++;
		*p_data = p_list->array[p_list->current_position];
		result = true;
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

	// ������ ����� ��ġ�� �̵��� ���� ����� ������ ���� ���� ��ġ�� �ϳ� ������ �̵��Ѵ�.
	p_list->current_position--;

	return removed_data;
}
