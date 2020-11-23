
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
void SListSort(SList *list);					//����
ElemType SListFront(SList list);				//��βԪ��
ElemType SListback(SList list);					//��ͷԪ��
void DeleteAll(SList *list);                    //ɾ������Ԫ��



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
void SListSort(SList *list)
{
	assert(list != NULL);
	if (SListLength(list) <= 1)
		return;
	SListNode *temp = *list, *prev = NULL;
	SListNode *p = *list;
	SListNode *q = p->next;
	p->next = NULL;

	while (q != NULL)
	{
		p = q;
		q = q->next;
		while (temp != NULL&&p->data > temp->data)
		{
			prev = temp;
			temp = temp->next;
		}
		if (prev == NULL)
		{
			p->next = *list;
			*list = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		temp = *list;
		prev = NULL;
	 }
}
ElemType SListFront(SList list)
{
	return list->data;
}
ElemType SListback(SList list)
{
	SListNode *p = list;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p->data;
}
void DeleteAll(SList *list)
{
	assert(list != NULL);
	SListNode *p = NULL;
	while (*list != NULL)
	{                                                                                                  
		p = *list;
		*list = p->next;
		free(p);
	}

}
void SListReverse(SList *list)
{
	assert(list != NULL);
	SListNode *p = *list;
	SListNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *list;
		*list = p;
	}
}
#endif