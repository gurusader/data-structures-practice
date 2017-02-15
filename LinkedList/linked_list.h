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

typedef struct _LinkedList
{
	Node* head;
	Node* current;
	Node* before;
	int number_of_data;
	int(*compare)(ListData data1, ListData data2); // 비교 기준을 지정하기 위한 함수 포인터.
} LinkedList;

typedef LinkedList List;

void initList(List* p_list);

void insertElement(List* p_list, ListData data);

Bool getFirstElement(List* p_list, ListData* p_data);
Bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);

void setSortRule(List* p_list, int(*compare)(ListData data1, ListData data2));
