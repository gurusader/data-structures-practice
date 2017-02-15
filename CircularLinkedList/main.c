#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

int main()
{
	List list;
	initList(&list);

	insertElementTail(&list, 1);
	insertElementTail(&list, 2);
	insertElementTail(&list, 3);
	insertElementHead(&list, 4);
	insertElementHead(&list, 5);
	insertElementHead(&list, 6);

	ListData data;
	if (getFirstElement(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < list.number_of_data - 1; i++)
		{
			if (getNextElement(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}

	puts("");

	int number_of_data = list.number_of_data;
	if (number_of_data != 0)
	{
		getFirstElement(&list, &data);

		if (data % 2 == 0)
		{
			removeElement(&list);
		}

		for (int i = 0; i < number_of_data - 1; i++)
		{
			getNextElement(&list, &data);

			if (data % 2 == 0)
			{
				removeElement(&list);
			}
		}
	}

	if (getFirstElement(&list, &data))
	{
		printf("%d ", data);

		for (int i = 0; i < list.number_of_data - 1; i++)
		{
			if (getNextElement(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}

	puts("");

	system("pause");

	return 0;
}
