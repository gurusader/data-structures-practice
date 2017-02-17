#pragma once

#include <stdbool.h>

typedef int StackData;
#define STACK_MAX_LENGTH 100

typedef struct _ArrayStack
{
	StackData array[STACK_MAX_LENGTH];
	int top_index;
} ArrayStack;

typedef ArrayStack Stack;

void initStack(Stack* p_stack);

bool isEmpty(Stack* p_stack);

void push(Stack* p_stack, StackData data);
StackData pop(Stack* p_stack);
StackData peek(Stack* p_stack);
