#ifndef _HEAP_H_
#define _HEAP_H_

#include "Commone.h"

#define HEAP_DEFULT_SIZE 20

typedef int HeapElemType;

typedef struct MinHeap
{
	HeapElemType * base;
	size_t  capacity;
	size_t  size;
}MinHeap;

void HeapInit(MinHeap *ph, int se = HEAP_DEFULT_SIZE);
void HeapInsert(MinHeap *ph, HeapElemType x);
void HeaShifUp(MinHeap *ph, int start);
void HeapShow(MinHeap *ph);
void HeapErase(MinHeap *hp);
void HeapShifDown(MinHeap *hp, int  start, int n);
void HeapCreate(MinHeap *hp, HeapElemType ar[], int n);
HeapElemType HeapTop(MinHeap *hp);
void HeapSort(MinHeap *hp, int arr[], int n);
bool HeapEmpty(MinHeap * hp);


void HeapInit(MinHeap *ph, int se )
{
	assert(ph != NULL);
	ph->capacity = se > HEAP_DEFULT_SIZE ? se : HEAP_DEFULT_SIZE;
	ph->base = (HeapElemType *)malloc(sizeof(HeapElemType)*ph->capacity);
	memset(ph->base, 0, sizeof(HeapElemType)*ph->capacity);
	ph->size = 0;
}

void HeapInsert(MinHeap *ph,HeapElemType x)
{
	assert(ph != NULL);
	if (ph->size >= ph->capacity)
	{
		printf("堆空间已满，%d 不能插入", x);
		return;
	}
	ph->base[ph->size] = x;
	HeaShifUp(ph, ph->size);
	ph->size++;
}
void HeaShifUp(MinHeap *ph, int start)
{
	int j = start;
	int i = (j - 1) / 2;
	while (j > 0)
	{
		if (ph->base[j] < ph->base[i])
		{
			Swap(&ph->base[j], &ph->base[i]);
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
}
void HeapShow(MinHeap *ph)
{
	assert(ph != NULL);
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ", ph->base[i]);
	}
	printf("\n");
}
void HeapErase(MinHeap *hp)
{
	assert(hp != NULL);
	if (hp->size == 0)
	{
		printf("堆已空！不能删除");
		return;
	}
	hp->size--;
	hp->base[0] = hp->base[hp->size];
	HeapShifDown(hp,0,hp->size);
}
void HeapShifDown(MinHeap *hp, int  start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1 < n &&hp->base[j] >hp->base[j+1])
		{
			j++;
		}
		if (hp->base[i]>hp->base[j])
		{
			Swap(&hp->base[i], &hp->base[j]);
			i = j;
			j = 2 * i + 1;
		}
		break;
	}
}
void HeapCreate(MinHeap *hp, HeapElemType ar[], int n)
{
	hp->capacity = n;
	hp->base = (HeapElemType*)malloc(sizeof(HeapElemType)*hp->capacity);
	assert(hp->base != NULL);
	for (int i = 0; i < n; i++)
	{
		hp->base[i] = ar[i];
	}
	hp->size = n;

	int curpos = n / 2 - 1;
	while (curpos >= 0)
	{
		HeapShifDown(hp, curpos, n); 
		curpos--;
	}
}
HeapElemType HeapTop(MinHeap *hp)
{
	assert(hp != NULL && hp->size > 0);
	return hp->base[0];
}
void HeapSort(MinHeap *hp, int arr[], int n)
{
	HeapCreate(hp, arr, n);
	while (hp->size > 0)
	{
		hp->size--;
		Swap(&hp->base[hp->size], &hp->base[0]);
		HeapShifDown(hp, 0, hp->size);
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = hp->base[i];
	}
}
bool HeapEmpty(MinHeap * hp)
{
	assert(hp != NULL);
	return hp->size == 0;
}
#endif