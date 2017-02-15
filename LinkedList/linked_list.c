#include <stdlib.h>
#include "linked_list.h"

void insertFirst(List* p_list, ListData data);

void initList(List* p_list)
{
	p_list->head = (Node*)malloc(sizeof(Node)); // head는 더미 노드를 가리킨다.
	p_list->head->next_node = NULL; // 더미 노드의 다음 노드는 없다.
	p_list->number_of_data = 0;
	p_list->compare = NULL;
}

void insertElement(List* p_list, ListData data)
{
	// 비교 기준이 없으면 앞에서 부터 노드를 추가하고, 있으면 기준에 따라 적합한 위치에 노드를 추가한다.
	(p_list->compare == NULL) ? insertFirst(p_list, data) : insertFirst(p_list, data);
}

void insertFirst(List* p_list, ListData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next_node = p_list->head->next_node; // 새 노드의 다음 노드로 더미 노드의 다음 노드를 지정한다.

	p_list->head->next_node = new_node; // 더미 노드의 다음 노드로 새 노드를 지정한다.
	p_list->number_of_data++;
}

Bool getFirstElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->head->next_node != NULL)
	{
		p_list->before = p_list->head; // before는 더미 노드를 가리킨다.
		p_list->current = p_list->head->next_node; // current는 더미 노드의 다음 노드를 가리킨다.

		*p_data = p_list->current->data;

		result = TRUE;
	}

	return result;
}

Bool getNextElement(List* p_list, ListData* p_data)
{
	Bool result = FALSE;

	if (p_list->current->next_node != NULL)
	{
		p_list->before = p_list->current;
		p_list->current = p_list->current->next_node;

		*p_data = p_list->current->data;

		result = TRUE;
	}

	return result;
}

ListData removeElement(List* p_list)
{
	Node* removed_node = p_list->current;
	ListData removed_data = removed_node->data;

	p_list->before->next_node = p_list->current->next_node; // before의 다음 노드로 삭제 노드의 다음 노드를 지정한다.
	p_list->current = p_list->before; // 삭제한 노드의 다음 노드의 참조를 위해 현재 current를 before와 같은 노드를 가리키게한다.

	free(removed_node);
	p_list->number_of_data--;

	return removed_data;
}

void setSortRule(List* p_list, int(*compare)(ListData data1, ListData data2))
{
}
