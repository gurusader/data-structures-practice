#pragma once

#include <stdbool.h>

typedef int StackData;

typedef struct _Node
{
	StackData data;
	struct _Node* next_node;
} Node;

typedef struct _LinkedListStack
{
	Node* head;
} LinkedListStack;

typedef LinkedListStack Stack;

void initStack(Stack* p_stack);

bool isEmpty(Stack* p_stack);

void push(Stack* p_stack, StackData data);
StackData pop(Stack* p_stack);
StackData peek(Stack* p_stack);
