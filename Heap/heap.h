#pragma once

#include <stdbool.h>

typedef int HeapData;
#define HEAP_MAX_LENGTH 100

typedef int (*Compare)(HeapData data1, HeapData data2);

typedef struct _Heap
{
	HeapData array[HEAP_MAX_LENGTH];
	int num_of_data;
	Compare compare;
} Heap;

void initHeap(Heap* p_heap, Compare compare);

bool isEmpty(Heap* p_heap);

void insertElement(Heap* p_heap, HeapData data);
HeapData removeElement(Heap* p_heap);
