#pragma once

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef int ListData;

typedef struct _Node
{
	ListData data;
	struct _Node* next_node;
	struct _Node* pre_node;
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

Bool getFirstElement(List* p_list, ListData* p_data);
Bool getNextElement(List* p_list, ListData* p_data);
Bool getPreviousElement(List* p_list, ListData* p_data);
