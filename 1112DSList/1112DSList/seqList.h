#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "commone.h"

#define ElemType int // ����Ԫ������
#define SEQLIST_SIZE 8 //˳���Ĭ�ϴ�С

//����˳���Ľṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	rsize_t szie;
}SeqList;
//��������
void SeqListInit(SeqList *plist);//��ʼ��˳���
void SeqListDestory(SeqList *plist);//�ݻ�˳���

void CheckCapacity(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);//β����������
void SeqListPopBack(SeqList *plist);//β��ɾ������
void SeqListPushFront(SeqList *plist, ElemType x);//ͷ����������
void SeqListPopfront(SeqList *plist);//ͷ��ɾ������
size_t SeqListFind(SeqList *plist, ElemType x);//��ֵ����Ԫ��

size_t SeqListLeng(SeqList *plist);//��˳���ĳ���
void SeqListClear(SeqList *plist);//������ݱ�
void SeqListInsert(SeqList* plist, size_t pos, ElemType x);//��λ�ò���Ԫ��
void SeqListErase(SeqList* plist, size_t pos);//��λ��ɾ��Ԫ��

void SeqListDisplay(SeqList *plist);//��ӡ˳���

//////////////////////////////////////
bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->szie == plist->capacity;
}
bool Isempty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->szie == 0;
}
void SeqListInit(SeqList *plist)
{
	plist->capacity = SEQLIST_SIZE;
	plist->base =(ElemType*)malloc(sizeof(ElemType)*plist->capacity);
	plist->szie = 0;
}
void SeqListDestory(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->szie = 0;
}
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist!=NULL);
	if (IsFull(plist))
	{
		printf("�ռ�������%d���ܲ���\n", x);
		return;
	}
	plist->base[plist->szie++] = x;
}
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	if (Isempty(plist))
	{
		printf("˳����ѿգ�����β��ɾ����\n");
	}
	plist->base[plist->szie--];
}
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d���ܲ��룡\n", x);
		return;
	}
	for (size_t i = plist->szie; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->szie++;
}
void SeqListPopfront(SeqList *plist)
{
	assert(plist != NULL);
	if (Isempty(plist))
	{
		printf("˳����ѿգ�����ͷ��ɾ����\n");
	}
	for (size_t i = 0; i < plist->szie; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->szie--;

}

void SeqListDisplay(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->szie; ++i)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}
size_t SeqListLeng(SeqList *plist)
{
	assert(plist != NULL);
	return plist->szie;
}
size_t SeqListFind(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->szie; i++)
	{
		if (plist->base[i] == x)
			return i;
	}
	return -1;
}
void SeqListInsert(SeqList* plist, size_t pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d������%dλ�ò��룡\n", x, pos);
	}
	if (pos > plist->capacity || pos < 0)
	{
		printf("λ�÷Ƿ������ܲ��룡\n");
	}
	for (size_t i = plist->szie; i>pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->szie++;
}
void SeqListErase(SeqList* plist, size_t pos)
{
	assert(plist != NULL);
	if (Isempty(plist))
	{
		printf("˳����ѿգ�����ɾ����\n");
	}
	if (pos > plist->capacity || pos < 0)
	{
		printf("λ�÷Ƿ�������ɾ����\n");
	}
	for (size_t i = pos; i < plist->szie; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->szie--;
}
void SeqListClear(SeqList *plist)
{
	assert(plist != NULL);
	plist->szie = 0;
}
#endif