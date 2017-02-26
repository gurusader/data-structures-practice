#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int compare(HeapData data1, HeapData data2)
{
	return data2 - data1;
}

int main()
{
	Heap heap;
	initHeap(&heap, compare);

	insertElement(&heap, 1);
	insertElement(&heap, 2);
	insertElement(&heap, 3);
	insertElement(&heap, 4);

	for (int i = 1; i <= heap.num_of_data; i++)
	{
		printf("%d ", heap.array[i]);
	}

	puts("");

	system("pause");

	return 0;
}
