#pragma once

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef int ListData; // 여러 타입에 대해 같은 이름으로 접근하기 위한 설정.
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

Bool getFirstElement(List* p_list, ListData* p_data);
Bool getNextElement(List* p_list, ListData* p_data);

ListData removeElement(List* p_list);
