#pragma once

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef int ListData;

typedef struct _Node
{
	ListData data;
	struct _Node* next_node;
} Node;

typedef struct _CircularLinkedList
{
	Node* tail;
	Node* current;
	Node* before;
	int number_of_data;
} CircularLinkedList;

typedef CircularLinkedList List;

void initList(List* p_list);

void insertElementHead(List* p_list, ListData data);
void insertElementTail(List* p_list, ListData data);

Bool getFirstElement(List* p_list, ListData* p_data);
Bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);
