#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_stack.h"

void initStack(Stack* p_stack)
{
	p_stack->top_index = -1;
}

bool isEmpty(Stack* p_stack)
{
	return p_stack->top_index == -1;
}

void push(Stack* p_stack, StackData data)
{
	if (p_stack->top_index >= STACK_MAX_LENGTH - 1)
	{
		puts("Stack is full.");
	}
	else
	{
		p_stack->top_index++;
		p_stack->array[p_stack->top_index] = data;
	}
}

StackData pop(Stack* p_stack)
{
	if (isEmpty(p_stack))
	{
		puts("Stack is empty.");
		exit(-1);
	}

	StackData data = p_stack->array[p_stack->top_index];
	p_stack->top_index--;

	return data;
}

StackData peek(Stack* p_stack)
{
	if (isEmpty(p_stack))
	{
		puts("Stack is empty.");
		exit(-1);
	}

	return p_stack->array[p_stack->top_index];
}
