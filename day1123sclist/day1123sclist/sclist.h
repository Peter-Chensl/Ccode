#ifndef _SCLIST_H_
#define _SCLIST_H_
#include "commone.h"

typedef struct SCListNode
{
	Elemtype data;
	SCListNode *next;
};

typedef SCListNode * sclist;
////////////////////////////////
//函数声明
bool Isempty(sclist* phead)
{
	SCListNode* p = *phead;
	return p == *phead;
}
void SClistInit(sclist* phead);
void SCListpushback(sclist* phead, Elemtype x);
void SCListpushfront(sclist* phead,Elemtype x);
void SCListpopback(sclist* phead);
void SCListpopfront(sclist* phead);
void SClistdisplay(sclist phead);
size_t SCListLength(sclist phead);
SCListNode* SCListFind(sclist phead, Elemtype x);


//函数实现
void SClistInit(sclist* phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
void SCListpushback(sclist* phead, Elemtype x)
{
	assert(phead != NULL);
	SCListNode* s = (SCListNode *)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;
	SCListNode* p = *phead;
	if (p == NULL)
	{
		*phead = s;
	}
	else
	{
		while (p->next != *phead)
		{
			p = p->next;
		}
		p->next = s;
	}
	s->next = *phead;
}
void SCListpushfront(sclist* phead,Elemtype x)
{
	assert(phead != NULL);
	SCListNode *s = (SCListNode *)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = x;
	SCListNode *p = *phead;
	if (p == NULL)
	{
		*phead = s;
	}
	else
	{
		
		while (p->next != *phead)
		{
			p = p->next;
		}
		p->next = s;
	}
	s->next = *phead;
	*phead = s;
}
void SClistdisplay(sclist phead)
{
	//assert(phead != NULL);
	SCListNode *p = phead;
	if (phead != NULL)
	{
		while (p->next != phead)
		{
			printf("%d->", p->data);
			p = p->next;
		}
		printf("%d->", p->data);
	}
	printf("Over.\n");
}
void SCListpopback(sclist* phead)
{
	assert(phead != NULL);
	SCListNode* p = *phead;
	SCListNode* prev = NULL;
	if (p->next == *phead)
	{
		*phead = NULL;
		free(p);
	}
	else
	{
		while (p->next != *phead)
		{
			prev = p;
			p = p->next;
		}
		prev->next = *phead;
		free(p);
	}
	
}
void SCListpopfront(sclist* phead)
{
	assert(phead != NULL);
	SCListNode* p = *phead;
	SCListNode* q = NULL;
	if (p->next == *phead)
	{
		*phead = NULL;
		free(p);
	}
	else
	{
		q = p;
		while (q->next != *phead)
		{
			q = q->next;
		}
		*phead = (*phead)->next;
		q->next = *phead;
		free(p);
	}
	
}
size_t SCListLength(sclist phead)
{
	size_t count = 0;
	assert(phead != NULL);
	SCListNode *p = phead;
	while (p->next != phead)
	{
		p = p->next;
		count++;
	}
	return count+1;
}
SCListNode* SCListFind(sclist phead, Elemtype x)
{
	assert(phead != NULL);
	SCListNode *p = phead;
	while (p->next != phead)
	{
		if (p->data == x)
			return p;
			break;
	}
	return NULL;
}
#endif