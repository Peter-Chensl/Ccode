#ifndef _QUEUE_H_
#define _QUEUE_H_


#include "Commone.h"

typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *head;
	LinkQueueNode *tail;
}LinkQueue;

void LinkQueueInit(LinkQueue *q);
void LinkQueueEn(LinkQueue *q,ElemType x);
void LinkQueueDe(LinkQueue *q);
ElemType LinkQueueFront(LinkQueue *q);
int LinkQueuesize(LinkQueue *q);
bool LinkQueueEmpty(LinkQueue *q);
void LnkQueueShow(LinkQueue * q);
void LinkQueueDestroy(LinkQueue *q);

void LinkQueueInit(LinkQueue *q)
{
	assert(q != NULL);
	q->head = q->tail = NULL;
}
void LinkQueueEn(LinkQueue *q,ElemType x)
{
	assert(q != NULL);
	LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;
	if (q->head == NULL)
	{
		q->head = q->tail = node;
	}
	else
	{
		q->tail->link = node;
		q->tail = node;
	}
}
void LinkQueueDe(LinkQueue *q)
{
	assert(q != NULL);
	if (q->head != NULL)
	{
		LinkQueueNode *p = q->head;
		if (q->head == q->tail)
		{
			q->head = q->tail = NULL;
		}
		else
		{
			q->head = p->link;
		}
		free(p);
	}
}
ElemType LinkQueueFront(LinkQueue *q)
{
	assert(q != NULL);
	assert(q->head != NULL);
	return q->head->data;
}
int LinkQueuesize(LinkQueue *q)
{
	assert(q != NULL);
	int size = 0;
	LinkQueueNode * p = q->head;
	while (q != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}
bool LinkQueueEmpty(LinkQueue *q)
{
	assert(q != NULL);
	return q->head == NULL; 
}
void LnkQueueShow(LinkQueue * q)
{
	assert(q != NULL);
	LinkQueueNode *p = q->head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}
void LinkQueueDestroy(LinkQueue *q)
{
	assert(q != NULL);
	LinkQueueNode * p = q->head;
	while (p != NULL)
	{
		p->link = q->head;
		free(p);
		p = q->head;

	}
}
#endif