#pragma once

#include <stdbool.h>

typedef int QueueData;
#define QUEUE_MAX_LENGTH 100

typedef struct _ArrayQueue
{
	QueueData array[QUEUE_MAX_LENGTH];
	int front;
	int rear;
} ArrayQueue;

typedef ArrayQueue Queue;

void initQueue(Queue* p_queue);

bool isEmpty(Queue* p_queue);

void enQueue(Queue* p_queue, QueueData data);
QueueData deQueue(Queue* p_queue);
QueueData peek(Queue* p_queue);
