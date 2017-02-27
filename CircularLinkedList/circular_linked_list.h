#pragma once

#include <stdbool.h>

typedef int ListData;

typedef struct _Node
{
	ListData data;
	struct _Node* next_node;
} Node;

typedef struct _CircularLinkedList
{
	Node* tail;
	Node* before;
	Node* current;
	int number_of_data;
} CircularLinkedList;

typedef CircularLinkedList List;

void initList(List* p_list);

void insertElementHead(List* p_list, ListData data);
void insertElementTail(List* p_list, ListData data);

bool getFirstElement(List* p_list, ListData* p_data);
bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);
