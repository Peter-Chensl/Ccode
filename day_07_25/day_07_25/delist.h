#ifndef _DELIST_H_
#define _DELIST_H_

#include"Commone.h"

//带头结点的双向链表
typedef struct DCListNode
{
	ElemType data;
	DCListNode *nest;
	DCListNode *prev;
}DCListNode;

typedef DCListNode* DCList;

void DCListInit(DCList *phead);
//DCListNode* BuyNode(ElemType v = ElemType());
void DCListPushBack(DCList *phead, ElemType x);
void DCListPushfront(DCList *phead, ElemType x);
void DCListShow(DCList phead);
void DCListPopBack(DCList *phead);
void DCListPopfront(DCList *phead);
size_t DCListlength(DCList phead);
size_t DCListfront(DCList phead);
size_t DCListback(DCList phead);
void DCListClear(DCList *phead);
void DCListDestroy(DCList *phead);
DCListNode *find(DCList phead, ElemType key);
void DCListEraseByVal(DCList phead, ElemType x);
void DCListSort(DCList phead);
void reveser(DCList phead);
void DCListInsertByVal(DCList phead, ElemType x);

DCListNode* BuyNode(ElemType v = ElemType())
{
	DCListNode *S = (DCListNode*)malloc(sizeof(DCListNode));
	assert(S != NULL);
	S->data = v;
	S->nest = S->prev = S;
	return S;
}
void DCListInit(DCList *phead)
{
	//
	/*DCListNode *s= (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->nest = s->prev = s;
	*phead = s;*/
	*phead = BuyNode();
}
void DCListPushBack(DCList *phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = BuyNode(x);
	DCListNode *head = *phead;
	s->prev = head->prev;
	s->nest = head;
	head->prev->nest = s;
	head->prev = s;
}
void DCListPushfront(DCList *phead, ElemType x)
{
	DCListNode *s = BuyNode(x);
	DCListNode *head = *phead;
	s->prev = head;
	s->nest = head->nest;
	head->prev = s->nest;
	head->nest = s;
}

void DCListShow(DCList phead)
{
	//assert(phead != NULL);
	DCListNode *p = phead->nest;
	while (p != phead)
	{
		printf("%d->", p->data);
		p = p->nest;
	}
	printf("over\n");
}
void DCListPopBack(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	DCListNode *p = head->prev;
	if (head->nest == head)
		return;
	head->prev = p->prev;
	p->prev->nest = head;
	free(p);
}
void DCListPopfront(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->nest == head)
		return;
	DCListNode *p = head->nest;
	p->nest->prev = p->prev;
	p->prev->nest = p->nest;
	free(p);
}
size_t DCListlength(DCList phead)
{
	assert(phead != NULL);
	DCListNode *head = phead;
	DCListNode *p = head;
	int count = 0;
	while (p->nest != head)
	{
		count++;
		p = p->nest;
	}
	return count;
}
size_t DCListfront(DCList phead)
{
	assert(phead != NULL);
	assert(phead ->nest!= phead);
	return phead->nest->data;
}
size_t DCListback(DCList phead)
{
	assert(phead != NULL);
	assert(phead->nest != phead);
	return phead->prev->data;
}
void DCListClear(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;
	if (head->nest == head)
	{
		return;
	}
	DCListNode *p = head->nest;
	while (p != head)
	{
		p->nest->prev = p->prev;
		p->prev->nest = p->nest;
		free(p);
		p = head->nest;
	}
}
void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);
	*phead = NULL;
}
DCListNode* find(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode *p = phead->nest;
	while (p != phead && p->data != key)
	{
		p = p->nest;
	}
	if (p == phead)
	{
		return NULL;
	}
	return p;
}
void DCListEraseByVal(DCList phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *p = find(phead, x);
	if (p == NULL)
	{
		printf("删除失败！");
		return;
	}
	else
	{
		p->prev->nest = p->nest;
		p->nest->prev = p->prev;
		free(p);
	}
}
void DCListSort(DCList phead)
{
	assert(phead != NULL);
	if (DCListlength(phead) == 1)
	{
		return;
	}
	DCListNode *p = phead->nest;
	DCListNode *q = p->nest;
	p->nest = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->nest;

		DCListNode *tmp = phead->nest;
		while (tmp != phead && p->data > tmp->data)
		{
			tmp = tmp->nest;
		}
		p->nest = tmp;
		p->prev = tmp->prev;
		p->nest->prev = p;
		p->prev->nest = p;
	}
}
void DCListInsertByVal(DCList phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *p = phead->nest;
	while (p != phead && x > p->data)
	{
		p = p->nest;
	}

	DCListNode *s = BuyNode(x);
	s->nest = p;
	s->prev = p->prev;
	s->prev->nest = s;
	s->nest->prev = s;

}
void reveser(DCList phead)
{
	assert(phead != NULL);
	if (DCListlength(phead) == 1)
	{
		return;
	}
	DCListNode *p = phead->nest;
	DCListNode *q = p->nest;
	p->nest = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->nest;

		p->nest = phead->nest;
		p->prev = phead;
		p->nest->prev = p;
		p->prev->nest = p;
	}
}
#endif 