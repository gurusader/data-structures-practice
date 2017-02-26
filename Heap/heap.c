#include "heap.h"

int getParentIndex(int index);
int getLeftChildIndex(int index);
int getHighPriorityChildIndex(Heap* p_heap, int index);

void initHeap(Heap* p_heap, Compare compare)
{
	p_heap->num_of_data = 0;
	p_heap->compare = compare;
}

bool isEmpty(Heap* p_heap)
{
	return p_heap->num_of_data == 0;
}

void insertElement(Heap* p_heap, HeapData data)
{
	int index = p_heap->num_of_data + 1;

	while (index != 1)
	{
		int parent_index = getParentIndex(index);
		if (p_heap->compare(data, p_heap->array[parent_index]) > 0)
		{
			p_heap->array[index] = p_heap->array[parent_index];
			index = parent_index;
		}
		else
		{
			break;
		}
	}

	p_heap->array[index] = data;
	p_heap->num_of_data++;
}

HeapData removeElement(Heap* p_heap)
{
	HeapData removed_data = p_heap->array[1];
	HeapData last_data = p_heap->array[p_heap->num_of_data];

	int parent_index = 1;
	int child_index;
	while ((child_index = getHighPriorityChildIndex(p_heap, parent_index)))
	{
		if (p_heap->compare(last_data, p_heap->array[child_index]) < 0)
		{
			p_heap->array[parent_index] = p_heap->array[child_index];
			parent_index = child_index;
		}
		else
		{
			break;
		}
	}

	p_heap->array[parent_index] = last_data;
	p_heap->num_of_data--;

	return removed_data;
}

int getParentIndex(int index)
{
	return index / 2;
}

int getLeftChildIndex(int index)
{
	return index * 2;
}

int getRightChildIndex(int index)
{
	return index * 2 + 1;
}

int getHighPriorityChildIndex(Heap* p_heap, int index)
{
	int result;

	int left_child_index = getLeftChildIndex(index);
	int right_child_index = getRightChildIndex(index);

	if (left_child_index > p_heap->num_of_data)
	{
		result = 0;
	}
	else if (left_child_index == p_heap->num_of_data)
	{
		result = left_child_index;
	}
	else
	{
		if (p_heap->compare(p_heap->array[left_child_index], p_heap->array[right_child_index]) > 0)
		{
			result = left_child_index;
		}
		else
		{
			result = right_child_index;
		}
	}

	return result;
}
