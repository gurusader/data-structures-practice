#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list_queue.h"

void initQueue(Queue* p_queue)
{
	p_queue->front = NULL;
	p_queue->rear = NULL;
}

bool isEmpty(Queue* p_queue)
{
	return p_queue->front == NULL;
}

void enQueue(Queue* p_queue, QueueData data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next_node = NULL;

	if (isEmpty(p_queue))
	{
		p_queue->front = new_node;
		p_queue->rear = new_node;
	}
	else
	{
		p_queue->rear->next_node = new_node;
		p_queue->rear = new_node;
	}
}

QueueData deQueue(Queue* p_queue)
{
	Node* removed_node;
	QueueData removed_data;

	if (isEmpty(p_queue))
	{
		puts("Queue is empty.");
		exit(-1);
	}

	removed_node = p_queue->front;
	removed_data = removed_node->data;
	p_queue->front = p_queue->front->next_node;

	free(removed_node);

	return removed_data;
}

QueueData peek(Queue* p_queue)
{
	if (isEmpty(p_queue))
	{
		puts("Queue is empty.");
		exit(-1);
	}

	return p_queue->front->data;
}
