
#ifndef _SLIST_H_
#define _SLIST_H_

#include "commone.h"
typedef int ElemType;//链表的数据类型

typedef struct SListNode
{
	ElemType data;			//数据域
	struct SListNode *next;//指针域

}SListNode;

typedef SListNode* SList;

//函数声明
void SListInit(SList *list);					//初始化链表
void SListpushBack(SList *list, ElemType x);	//尾部插入元素
void SListpushFront(SList *list, ElemType x);	//头部插入元素
void SListpopBack(SList *list);					//尾部删除元素
void SListpopFront(SList *list);				//头部删除元素
void SListDisplay(SList *list);					//打印链表的元素
size_t SListLength(SList *list);				//求链表的长度
SListNode *SListFind(SList list, ElemType key);//查找元素
void SListEraseByVal(SList *list, ElemType);	//按值删除



void SListInit(SList *list)
{
	assert(list != NULL);
	*list = NULL;
}
void SListpushBack(SList *list,ElemType x)
{
	assert(list != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	//链接节点
	SListNode *p = *list;
	if (p == NULL)
	{
		*list = s;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
	
}
void SListpushFront(SList *list, ElemType x)
{
	assert(list != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = *list;

	*list = s;
}
void SListpopBack(SList *list)
{
	assert(list != NULL);
	SListNode *prev = NULL;//前驱指针
	SListNode *p = *list; 
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
		*list = NULL;
	}
	else
	{
		prev->next = NULL;
	}
	free(p);
}
void SListpopFront(SList *list)
{
	assert(list != NULL);
	SListNode * p = *list; 
	if (*list != NULL)
	{
		*list = (*list)->next;
	}
	free(p);
}
SListNode *SListFind(SList list, ElemType key)
{
	assert(list != NULL);
	/*SListNode *p = *list;
	while (p != NULL)
	{
		if (p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;*/
	SListNode *p = list;
	while (p != NULL &&p->data != key)//注意条件顺序不能写反
	{
		p = p->next;
	}
	return p;
}
void SListEraseByVal(SList *list, ElemType key)
{
	assert(list != NULL);
	SListNode *p = SListFind(*list, key);
	if (p == NULL)
	{
		return;
	}
	//SListNode *q = *list;
	SListNode *prev = *list;
	while (prev != p && prev->next != p)
	{
		prev = prev->next;
	}
	if (prev == p)
		*list = p->next;
	else
		prev->next = p->next;
	free(p);
}
void SListDisplay(SList *list)
{
	//assert("list!=NULL");
	SListNode *p = *list;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");
}
size_t SListLength(SList *list)
{
	assert(list != NULL);
	SListNode *p = *list;
	size_t count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

#endif