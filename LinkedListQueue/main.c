#include <stdio.h>
#include <stdlib.h>
#include "linked_list_queue.h"

int main()
{
	Queue queue;
	initQueue(&queue);

	enQueue(&queue, 2);
	enQueue(&queue, 4);
	enQueue(&queue, 6);
	enQueue(&queue, 8);

	printf("%d\n", peek(&queue));

	while (!isEmpty(&queue))
	{
		printf("%d ", deQueue(&queue));
	}

	puts("");

	system("pause");

	return 0;
}
