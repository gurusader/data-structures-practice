#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list_stack.h"

void initStack(Stack* p_stack)
{
	p_stack->head = NULL;
}

bool isEmpty(Stack* p_stack)
{
	return (p_stack->head == NULL);
}

void push(Stack* p_stack, StackData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next_node = p_stack->head;

	p_stack->head = new_node;
}

StackData pop(Stack* p_stack)
{
	if (isEmpty(p_stack))
	{
		puts("Stack is empty.");
		exit(-1);
	}

	Node* removed_node = p_stack->head;
	StackData removed_data = p_stack->head->data;

	p_stack->head = p_stack->head->next_node;

	free(removed_node);
	return removed_data;
}

StackData peek(Stack* p_stack)
{
	if (isEmpty(p_stack))
	{
		puts("Stack is empty.");
		exit(-1);
	}

	return p_stack->head->data;
}
