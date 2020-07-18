#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "Common.h"
#pragma warning(disable:4996)

#define SEQLIST_DEFAULT_SIZE 8


//����˳���Ľṹ
typedef struct SeqList
{
	int *base;
	size_t  capacity;
	size_t  size;
} SeqList;


//����������
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListDestroy(SeqList *plist);
void SeqListInit(SeqList *plist);
void SeqListShow(SeqList *plist);
void SeqListPushFont(SeqList *plist, ElemType x);
void SeqlListPopBack(SeqList *plist);
void SeqlListpopfront(SeqList *plist);
void SeqlListClear(SeqList *plist);
bool SeqListinsertpos(SeqList *plist, ElemType x, size_t pos);
bool SeqListInsertVal(SeqList *plist, ElemType x);
void SeqListSort(SeqList *plist);
size_t SeqListCapacity(SeqList *plist);
void SeqlListErsePos(SeqList *plist,size_t pos);
int find(SeqList *plist, ElemType sky);
int SeqlListErseval(SeqList *plist, ElemType x);
void Reveser(SeqList *plist);

size_t SeqListLength(SeqList *plist);

bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}
void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
	plist->size = 0;
}
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist)){
		printf("˳���������%d ����β������\n", x);
		return;
	}
	plist->base[plist->size++] = x;
	
}

void SeqListShow(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
		printf("\n");
	}
}
void SeqListPushFont(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d ����ͷ������\n", x);
		return;
	}
	plist->base[0] = x;
	plist->size++;
}
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
void SeqlListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����ѿգ�����β��ɾ����\n");
		return;
	}
	plist->size--;
}
void SeqlListPopfront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����ѿգ�����ͷ��ɾ����\n");
		return;
	}
	for (size_t i = 0; i < plist->size; i++){
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
void SeqlListClear(SeqList *plist)
{
	assert(plist != NULL);
	plist->size = 0;
}
bool SeqListinsertpos(SeqList *plist ,ElemType x ,size_t pos)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d������%dλ�ò���\n", x, pos);
		return false;
	}
	if (pos<0 || pos > plist->size)
	{
		printf("Ҫ�����λ�á�%d���ǷǷ�λ�ã�%d���ܲ���", pos, x);
		return false;
	}
	for (size_t i = plist->size; i > pos; --i)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;

	return true;
}
bool SeqListInsertVal(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d���ܲ���\n");
		return false;
	}
#if 0
	size_t pos = 0;
	while (pos < plist->size && x >plist->base[pos])
	{
		pos++;
	}
	for (size_t i = plist->size; i > pos; --i)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
#endif
	size_t end = plist->size - 1;
	while (end >= 0 && x < plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end+1] = x;
	plist->size++; 
}
void SeqListSort(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i){
		for (size_t j = 0; j < plist->size - 1; ++j){
			if (plist->base[j] > plist->base[j + 1])
				Swap(&plist->base[j], &plist->base[j + 1]);
		}
	}

}
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
void SeqlListErsePos(SeqList *plist, int pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist)){
		printf("˳����ѿգ�������ɾ����\n");
		return;
	}
	if (pos < 0 && pos >= plist->size)
	{
		printf("ɾ����λ�÷Ƿ�������ɾ����\n");
		return;
	}
	for (size_t i = pos; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}
int SeqlListErseval(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	int pos = find(plist, x);
	if (pos = -1)
	{
		return;
	}
	SeqlListErsePos(plist, pos);

}
int find(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = 0;
	while (key != plist->base[pos])
	{
		pos++;
	}
	if (pos == plist->size)
	{
		pos = -1;
	}
	return pos;
}

void Reveser(SeqList *plist)
{
	assert(plist != NULL);
	if (plist->size == 1)
	{
		return;
	}
	int start = 0, end = plist->size - 1;
	while (start < end)
	{
		Swap(&plist->base[start], &plist->base[end]);
		start++, end--;
	}
}
#endif
