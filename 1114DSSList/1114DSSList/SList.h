
#ifndef _SLIST_H_
#define _SLIST_H_

#include "commone.h"
typedef int ElemType;//�������������

typedef struct SListNode
{
	ElemType data;			//������
	struct SListNode *next;//ָ����

}SListNode;

typedef SListNode* SList;

//��������
void SListInit(SList *list);					//��ʼ������
void SListpushBack(SList *list, ElemType x);	//β������Ԫ��
void SListpushFront(SList *list, ElemType x);	//ͷ������Ԫ��
void SListpopBack(SList *list);					//β��ɾ��Ԫ��
void SListpopFront(SList *list);				//ͷ��ɾ��Ԫ��
void SListDisplay(SList *list);					//��ӡ�����Ԫ��
size_t SListLength(SList *list);				//������ĳ���
SListNode *SListFind(SList list, ElemType key);//����Ԫ��
void SListEraseByVal(SList *list, ElemType);	//��ֵɾ��



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

	//���ӽڵ�
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
	SListNode *prev = NULL;//ǰ��ָ��
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
	while (p != NULL &&p->data != key)//ע������˳����д��
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