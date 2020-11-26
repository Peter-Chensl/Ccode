#ifndef _DCLIST_H_
#define _DCLIST_H_

#include "commone.h"
 
typedef struct DCListNode
{
	Elemtype item;
	DCListNode *next;
	DCListNode *pre;
}DCListNode;

typedef DCListNode* Dclist;

//函数声明
DCListNode *_buyNode(Elemtype v = Elemtype());
void DCListInit(Dclist* phead);
void DCListPushback(Dclist* phead, Elemtype x);
void DCListPushfront(Dclist* phead, Elemtype x);
void DCListpopfront(Dclist* phead);
void DCListpopback(Dclist* phead);
void DCListDisplay(Dclist phead);
size_t DCListLength(Dclist phead);
DCListNode * DCListfind(Dclist phead, Elemtype x);
Elemtype DCListFrontVal(Dclist phead);
Elemtype DCListlastVal(Dclist phead);
void DCListClear(Dclist *phead);
void DCListErasebyval(Dclist *phead, Elemtype x);
void DCListInsertbyval(Dclist *phead, Elemtype x);
//函数实现
DCListNode *buyNode(Elemtype v = Elemtype())
{
	DCListNode* S = (DCListNode *)malloc(sizeof(DCListNode));
	assert(S != NULL);
	S->item = v;
	S->next = S->pre = S;
	return S;
}
void DCListInit(Dclist* phead)
{
	
	*phead = buyNode();
}
void DCListPushback(Dclist* phead, Elemtype x)
{
	assert(phead != NULL);
	DCListNode *s = buyNode(x);
	DCListNode* p = *phead;
	s->pre = p->pre;
	s->next = p;
	p->pre->next = s;
	p->pre = s;
}
void DCListPushfront(Dclist* phead, Elemtype x)
{
	assert(phead != NULL);
	DCListNode *s = buyNode(x);
	DCListNode *p = *phead;

	s->next = p->next;
	s->pre = p;
	p->next->pre = s;
	p->next = s;
	/*s->pre->next = s;
	s->next->pre = s;*/

}
void DCListpopfront(Dclist* phead)
{
	assert(phead != NULL);
	DCListNode *p = *phead;
	if (p->next == p)
		return;
	DCListNode *q = (*phead)->next;
	p->next = q->next;
	q->next->pre = p;
	free(q);
}
void DCListpopback(Dclist* phead)
{
	assert(phead != NULL);
	DCListNode *ph = *phead;
	if (ph->next == ph)
		return;
	else
	{
		DCListNode *p = (*phead)->pre;
		(*phead)->pre= p->pre;
		p->pre->next = *phead;
		free(p);
	}
	
}
void DCListDisplay(Dclist *phead)
{
	DCListNode *p = (*phead)->next;
	while (p != (*phead))
	{
		printf("%d->", p->item);
		p = p->next;
	}
	printf("Over.\n");
}
size_t DCListLength(Dclist phead)
{
	assert(phead != NULL);
	size_t count = 0;
	DCListNode *p = phead->next;
	while (p != phead)
	{
		p = p->next;
		count++;
	}
	return count;
}
DCListNode* DCListfind(Dclist phead, Elemtype x)
{
	assert(phead != NULL);
	DCListNode *p = phead;
	while (p != phead&&p->item != x)
	{
		p = p->next;

	}
	return p;
}
Elemtype DCListFrontVal(Dclist phead)
{
	assert(phead);
	return phead->next->item;
}
Elemtype DCListlastVal(Dclist phead)
{
	assert(phead);
	return phead->pre->item;
}
void DCListClear(Dclist *phead)
{
	assert(phead);
	DCListNode *p = *phead;
	if (p->next == p)
		return;
	DCListNode *q = p->next;
	while (q != *phead)
	{
		p->next = q->next;
		q->next->pre = p->next;
		free(q);
		q = (*phead)->next;
	}
}
void DCListErasebyval(Dclist phead,Elemtype x)
{
	assert(phead!=NULL);
	DCListNode *p = DCListfind(phead, x);
	if (p == NULL)
		return;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}
void DCListInsertbyval(Dclist *phead, Elemtype x)
{
	assert(phead);
}
#endif