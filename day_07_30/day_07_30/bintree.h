#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "Commone.h"

typedef char BintreeElemType;

typedef struct BintreeNode
{
	BintreeElemType data;
	BintreeNode *leftChird;
	BintreeNode *rightChird;
}BintreeNode;

typedef BintreeNode *Bintree;
//////////////////////////////////////////////////
struct BintreeNode;
typedef BintreeNode *LinkQueueElemType;
typedef struct LinkQueueNode
{
	LinkQueueElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode *head;
	LinkQueueNode *tail;
}LinkQueue;

void LinkQueueInit(LinkQueue *ls);
void LinkQueueEn(LinkQueue *ls, LinkQueueElemType x);
void LinkQueueDe(LinkQueue *ls);
LinkQueueElemType LinkQueueFront(LinkQueue *ls);
void LinkQueueDestroy(LinkQueue *ls);
bool IsEmpty(LinkQueue *ls);


void LinkQueueInit(LinkQueue *ls)
{
	assert(ls != NULL);
	ls->head = ls->tail = NULL;
}
void LinkQueueEn(LinkQueue *ls, LinkQueueElemType x)
{
	assert(ls != NULL);
	LinkQueueNode *s = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->link = NULL;

	if (ls->head == NULL)
	{
		ls->head = ls->tail = s;
	}
	else
	{
		ls->tail->link = s;
		ls->tail = s;
	}
}
void LinkQueueDe(LinkQueue *ls)
{
	assert(ls != NULL);
	if (ls->head != NULL)
	{
		LinkQueueNode *s = ls->head;
		if (ls->head == ls->tail)
		{
			ls->head = ls->tail = NULL;
		}
		else
		{
			ls->head = s->link;
		}
		free(s);
	}
	
}
/*LinkQueueElemType LinkQueueFront(LinkQueue *ls)
{
	assert(ls != NULL);
	assert(ls->head != NULL);
	return ls->head->data;
}*/
LinkQueueElemType LinkQueueFront(LinkQueue *ls)
{
	assert(ls != NULL);
	assert(ls->head != NULL);
	return ls->head->data;  //return pq->tail->data
}
void LinkQueueDestroy(LinkQueue *ls)
{
	assert(ls != NULL);
	LinkQueueNode *p = ls->head;
	while (p != NULL)
	{
		ls->head = p->link;
		free(p);
		p = ls->head;
	}
}
bool IsEmpty(LinkQueue *ls)
{
	assert(ls != NULL);
	return ls->head == NULL;
}
////////////////////////////////////////////////
typedef BintreeNode * LinkStackiElemType;
typedef struct LinkStackNode
{
	LinkStackiElemType data;
	LinkStackNode* link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
void LinkStackInit(LinkStack *st);
void LinkStackPush(LinkStack *st, LinkStackiElemType x);
void LinkStackPop(LinkStack *st);
LinkStackiElemType LinkStackTop(LinkStack *st);
void LinkStackDestroy(LinkStack *st);
bool LinkStackEmpty(LinkStack *st);


void LinkStackInit(LinkStack *st)
{
	assert(st != NULL);
	*st = NULL;
}
void LinkStackPush(LinkStack *st,LinkStackiElemType x)
{
	assert(st != NULL);
	LinkStackNode *s = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	assert(s != NULL);
	s->data = x;
	s->link = *st;
	*st = s;
}
void LinkStackPop(LinkStack *st)
{
	assert(st != NULL);
	if (*st != NULL)
	{
		LinkStackNode *p = *st;
		*st = p->link;
		free(p);
	}
}
LinkStackiElemType LinkStackTop(LinkStack *st)
{
	assert(st != NULL && *st != NULL);
	return (*st)->data;
}
void LinkStackDestroy(LinkStack *st)
{
	assert(st != NULL);
	LinkStackNode* p = *st;
	while (p != NULL)
	{
		(*st) = p->link;
		free(p);
		p = *st;
	}
}
bool LinkStackEmpty(LinkStack *st)
{
	assert(st != NULL);
	return *st == NULL;
}
///////////////////////////////////////////////
void BintreeInit(Bintree *bt);
void BintreeCreate(Bintree *bt);
Bintree BintreeCreate1();
Bintree BinTreeCreate2(const char *s,int *i);

int BintreeSize(Bintree bt);
void BintreeVLR(Bintree bt);
void BintreeLVR(Bintree bt);
void BintreeLRV(Bintree bt);
void BinTreeLevel(Bintree bt);
//二叉树的非递归遍历
void BintreeVLR_Nor(Bintree bt);
void BintreeLVR_Nor(Bintree bt);
void BintreeLRV_Nor(Bintree bt);

int Bintreeheight(Bintree bt);
BintreeNode* left(BintreeNode *p);
BintreeNode* right(BintreeNode *p);
BintreeNode* find(Bintree t, BintreeElemType key);
BintreeNode* BintreeParent(Bintree t, BintreeNode *p);
BintreeNode* BintreeClone(Bintree t);
bool BintreeEqul(Bintree b1, Bintree b2);

void BintreeInit(Bintree *bt)
{
	*bt = NULL;
}
void BintreeCreate(Bintree *bt)
{
	assert(bt != NULL);
	BintreeElemType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*bt = NULL;
	}
	else
	{
		*bt = (BintreeNode*)malloc(sizeof(BintreeNode));
		assert(bt != NULL);
		(*bt)->data = item;
		BintreeCreate(&(*bt)->leftChird);
		BintreeCreate(&(*bt)->rightChird);
	}
}
Bintree BintreeCreate1()
{
	BintreeElemType item;
	scanf("%c", &item);
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BintreeNode *bt = (BintreeNode *)malloc(sizeof(BintreeNode));
		assert(bt != NULL);
		bt->data = item;
		bt->leftChird = BintreeCreate1();
		bt->rightChird = BintreeCreate1();
		return bt;
	}
}

Bintree BinTreeCreate2(const char *s, int *i)
{
	assert(s != NULL);
	if (s[*i] == '\0' || s[*i] == '#')
		return NULL;
	else
	{
		BintreeNode *t = (BintreeNode*)malloc(sizeof(BintreeNode));
		assert(t != NULL);
		t->data = s[*i];
		(*i)++;
		t->leftChird = BinTreeCreate2(s, i);
		(*i)++;
		t->rightChird = BinTreeCreate2(s, i);
		return t;
	}
}

int BintreeSize(Bintree bt)
{
	if (bt == NULL)
	{
		return 0;
	}
else
{
	return BintreeSize(bt->leftChird) + BintreeSize(bt->rightChird)+1;
}
	
}
void BintreeVLR(Bintree bt)
{
	if (bt != NULL)
	{
		printf("%c ", bt->data);
		BintreeVLR(bt->leftChird);
		BintreeVLR(bt->rightChird);
	}
}
void BintreeLVR(Bintree bt)
{
	if (bt != NULL)
	{
		BintreeLVR(bt->leftChird);
		printf("%c ", bt->data);
		BintreeLVR(bt->rightChird);
	}
}
void BintreeLRV(Bintree bt)
{
	if (bt != NULL)
	{
		BintreeLRV(bt->leftChird);
		BintreeLRV(bt->rightChird);
		printf("%c ", bt->data);
	}
}
void BinTreeLevel(Bintree t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while (!IsEmpty(&Q))
		{
			BintreeNode* p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if (p->leftChird != NULL)
				LinkQueueEn(&Q, p->leftChird);
			if (p->rightChird != NULL)
				LinkQueueEn(&Q, p->rightChird);
		}

		LinkQueueDestroy(&Q);
	}
}
int Bintreeheight(Bintree bt)
{
	
	if (bt == NULL)
	{
		return 0;
	}
	else
	{
		int left = Bintreeheight(bt->leftChird);
		int right = Bintreeheight(bt->rightChird);
		return (left > right ? left : right) + 1;
	}
}
BintreeNode* left(BintreeNode *p)
{
	assert(p != NULL);
	return p->leftChird;
}
BintreeNode* right(BintreeNode *p)
{
	assert(p != NULL);
	return p->rightChird;
}
BintreeNode* find(Bintree t, BintreeElemType key)
{
	if (t == NULL || t->data == key)
	{
		return t;
	}
	BintreeNode *p = find(t->leftChird, key);
	if (p != NULL)
	{
		return p;
	}
	return find(t->rightChird, key);
}
BintreeNode* BintreeParent(Bintree t, BintreeNode *p)
{
	if (t == NULL || p == NULL || t->data == p->data)
	{
		return NULL;
	}
	if (t->leftChird == p || t->rightChird == p)
	{
		return p;
	}
	BintreeNode *pr = BintreeParent(t->leftChird, p);
	if (pr != NULL)
	{
		return pr;
	}
	return BintreeParent(t->rightChird, p);
}
BintreeNode* BintreeClone(Bintree t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BintreeNode *bt = (BintreeNode *)malloc(sizeof(BintreeNode));
		bt->data = t->data;
		bt->leftChird = BintreeClone(t->leftChird);
		bt->rightChird = BintreeClone(t->rightChird);
		return bt;
	}
}
bool BintreeEqul(Bintree b1, Bintree b2)
{
	if (b1 == NULL && b2 == NULL)
		return true;
	if (b1 == NULL || b2 == NULL)
		return false;
	if (b1->data == b2->data && BintreeEqul(b1->leftChird, b2->rightChird) && BintreeEqul(b1->rightChird, b2->rightChird))
		return true;
		
}
void BintreeVLR_Nor(Bintree bt)
{
	if (bt != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);

		LinkStackPush(&st, bt);
		while (!LinkStackEmpty(&st))
		{
			BintreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChird != NULL)
			{
				LinkStackPush(&st, p->rightChird);
			}
			if (p->leftChird != NULL)
			{
				LinkStackPush(&st, p->leftChird);
			}
			
		}
		LinkStackDestroy(&st);

	}
}
void BintreeLVR_Nor(Bintree bt)
{
	if (bt != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		do
		{
			while (bt != NULL)
			{
				LinkStackPush(&st, bt);
				bt = bt->leftChird;
			}
			BintreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChird != NULL)
			{
				bt = p->rightChird;
			}
		} while (!LinkStackEmpty(&st) || bt != NULL);
	}
}
void BintreeLRV_Nor(Bintree bt)
{
	BintreeNode * pre = NULL;
	if (bt != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		do
		{
			while (bt != NULL)
			{
				LinkStackPush(&st, bt);
				bt = bt->leftChird;
			}
			BintreeNode *p =  LinkStackTop(&st);
			if (p->rightChird == NULL || p->rightChird == pre)
			{
				LinkStackPop(&st);
				printf("%c ", p->data);
			}
			else
			{
				bt = p->rightChird;
			}
		} while (!LinkStackEmpty(&st));
	}
}
#endif