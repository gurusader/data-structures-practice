#pragma once

#include <stdbool.h>

typedef int ListData;

typedef struct _Node
{
	ListData data;
	struct _Node* pre_node;
	struct _Node* next_node;
} Node;

typedef struct _DoublyLinkedList
{
	Node* head;
	Node* current;
	int number_of_data;
} DoublyLinkedList;

typedef DoublyLinkedList List;

void initList(List* p_list);

void insertElement(List* p_list, ListData data);

bool getFirstElement(List* p_list, ListData* p_data);
bool getPreviousElement(List* p_list, ListData* p_data);
bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);
