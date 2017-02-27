#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"

int getNextIndex(int index);

void initQueue(Queue* p_queue)
{
	p_queue->front = 0;
	p_queue->rear = 0;
}

bool isEmpty(Queue* p_queue)
{
	return p_queue->front == p_queue->rear;
}

void enQueue(Queue* p_queue, QueueData data)
{
	if (getNextIndex(p_queue->rear) == p_queue->front)
	{
		puts("Queue is full.");
	}
	else
	{
		p_queue->rear = getNextIndex(p_queue->rear);
		p_queue->array[p_queue->rear] = data;
	}
}

QueueData deQueue(Queue* p_queue)
{
	if (isEmpty(p_queue))
	{
		puts("Queue is empty.");
		exit(-1);
	}

	p_queue->front = getNextIndex(p_queue->front);
	return p_queue->array[p_queue->front];
}

QueueData peek(Queue* p_queue)
{
	if (isEmpty(p_queue))
	{
		puts("Queue is empty.");
		exit(-1);
	}

	return p_queue->array[getNextIndex(p_queue->front)];
}

int getNextIndex(int index)
{
	int result = index + 1;

	if (index == QUEUE_MAX_LENGTH - 1)
	{
		result = 0;
	}

	return result;
}
