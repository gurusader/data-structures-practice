#include <stdio.h>
#include <stdlib.h>
#include "linked_list_stack.h"

int main()
{
	Stack stack;
	initStack(&stack);

	push(&stack, 2);
	push(&stack, 4);
	push(&stack, 6);
	push(&stack, 8);

	printf("%d\n", peek(&stack));

	while (!isEmpty(&stack))
	{
		printf("%d ", pop(&stack));
	}

	puts("");

	system("pause");

	return 0;
}
