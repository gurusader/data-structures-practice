#pragma once

#include <stdbool.h>

typedef int ListData;
#define LIST_MAX_LENGTH 100

typedef struct _ArrayList
{
	ListData array[LIST_MAX_LENGTH];
	int number_of_data;
	int current_position;
} ArrayList;

typedef ArrayList List;

void initList(List* p_list);

void insertElement(List* p_list, ListData data);

bool getFirstElement(List* p_list, ListData* p_data);
bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);
