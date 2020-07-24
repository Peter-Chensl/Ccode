#ifndef _SLIST_H_
#define _SLIST_H_

#include "Commone.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef SListNode* SList;
void SListInit(SList *phead);
void SListPushBack(SList *phead, ElemType x);
void SListPushFront(SList *phead, ElemType x);
void SListPopback(SList *phead);
void SListPopfront(SList *phead);
void SListShow(SList *phead);
size_t SListlength(SList *phead);
SListNode* find(SList *phead, ElemType key);
void SListEraseByval(SList *phead, ElemType key);
void SListSort(SList *phead);
void SListInsertByVal(SList *phead, ElemType key);
void SListReverse(SList *phead);

void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->data = NULL;

	
	SListNode *p = *phead;
	if (p == NULL){
		*phead = s;
	}
	else
	{
		while (p->next != NULL){
			p = p->next;
		}
		p->next = s;
	}
	
}
void SListPushFront(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;

	s->data = *phead;
	phead = s;

}
void SListPopback(SList *phead)
{
	//assert(phead != NULL);
	SListNode *p = *phead;
	SListNode *prev = NULL;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
	}
	if (prev == NULL)
	{
		*phead = NULL;
	}
	else
	{
		prev->next = NULL;
	}
	free(p);
}
void SListPopfront(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	if (p != NULL){
		*phead = p->next;
		free(p);
	}
}
void SListShow(SList phead)
{
	assert(phead != NULL);
	SListNode *p = phead;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->data;
	}
	printf("Over");
}
size_t SListlength(SList *phead)
{
	assert(phead != NULL);
	size_t count = 0;
	SListNode *p = *phead;
	while (p->data != NULL)
	{
		p = p->next;
	}
	return count;
}
SListNode* find(SList *phead, ElemType key)
{
#if 0
	SListNode *p = phead;
	while (p != NULL)
	{
		if (p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
#endif
	SListNode *p = phead;
	while (p != NULL && p->data != key)
	{
		p = p->next;
	}
	return p;
}
void SListEraseByval(SList *phead, ElemType key)
{
	assert(phead != NULL);
	SListNode *p = find(*phead, key);
	if (p == NULL){
		return;
	}
	SListNode *prev = *phead;
	while (prev != p && prev ->next != NULL)
	{
		prev = prev->next; 
	}
	if (prev == p)
	{
		*phead = p->next;
	}
	else
	{
		prev->next = p->next;
	}
	free(p) ;

}
void SListSort(SList *phead)
{
	assert(phead != NULL);
	if (SListlength(*phead) <= 1)
	{
		return;
	}
	SListNode *temp = *phead,*prev = NULL;
	SListNode *p = phead;
	SListNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		while (temp != NULL&&p->next > temp->data)
		{
			prev = temp;
			temp = temp->next;
		}
		if (prev == NULL)
		{
			p->next = *phead;
			*phead = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		temp = *phead;
		prev = NULL;
	}
}
void SListInsertByVal(SList *phead, ElemType key)
{
	assert(phead != NULL);
	SListNode *p = *phead, *prev = NULL;
	while (p != NULL && key>p->data)
	{
		prev = p;
		p = p->next;
	}
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = key;
	if (prev == NULL)
	{
		s->next = *phead;
		*phead = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}

}
void SListReverse(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	SListNode *q = p->next;

	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}
}
#endif