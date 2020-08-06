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
/*void HeapCreate(MinHeap *php, HeapElemType ar[], int n);
void HeapShiftDown(MinHeap *php, int start, int n);*/


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
/*void HeapShiftDown(MinHeap *php, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && php->base[j]>php->base[j + 1]) //寻求左右子树中的最小值
			j++;
		if (php->base[i] > php->base[j])
		{
			Swap(&php->base[i], &php->base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}*/
#endif