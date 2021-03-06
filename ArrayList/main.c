#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

int main()
{
	List list;
	initList(&list);

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
