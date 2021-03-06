#pragma once

#include <stdbool.h>

typedef int ListData;

typedef struct _Node
{
	ListData data;
	struct _Node* next_node;
} Node;

// 비교 기준을 지정하기 위한 함수 포인터.
typedef int (*Compare)(ListData data1, ListData data2);

typedef struct _LinkedList
{
	Node* head;
	Node* before;
	Node* current;
	int number_of_data;
	Compare compare;
} LinkedList;

typedef LinkedList List;

void initList(List* p_list);

void insertElement(List* p_list, ListData data);

bool getFirstElement(List* p_list, ListData* p_data);
bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);

void setSortRule(List* p_list, Compare compare);
