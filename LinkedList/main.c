#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int compare(int data1, int data2)
{
	return (data1 < data2) ? 1 : 0;
}

int main()
{
	List list;
	initList(&list);
	setSortRule(&list, compare);

	insertElement(&list, 1);
	insertElement(&list, 1);
	insertElement(&list, 3);
	insertElement(&list, 3);
	insertElement(&list, 5);
	insertElement(&list, 5);

	ListData data;
	if (getFirstElement(&list, &data))
	{
		printf("%d ", data);

		while (getNextElement(&list, &data))
		{
			printf("%d ", data);
		}
	}

	puts("");

	if (getFirstElement(&list, &data))
	{
		if (data == 3)
		{
			removeElement(&list);
		}

		while (getNextElement(&list, &data))
		{
			if (data == 3)
			{
				removeElement(&list);
			}
		}
	}

	if (getFirstElement(&list, &data))
	{
		printf("%d ", data);

		while (getNextElement(&list, &data))
		{
			printf("%d ", data);
		}
	}

	puts("");

	system("pause");

	return 0;
}
