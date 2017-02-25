#pragma once

#include <stdbool.h>

typedef int QueueData;

typedef struct _Node
{
	QueueData data;
	struct _Node* next_node;
} Node;

typedef struct _LinkedListQueue
{
	Node* front;
	Node* rear;
} LinkedListQueue;

typedef LinkedListQueue Queue;

void initQueue(Queue* p_queue);

bool isEmpty(Queue* p_queue);

void enQueue(Queue* p_queue, QueueData data);
QueueData deQueue(Queue* p_queue);
QueueData peek(Queue* p_queue);
