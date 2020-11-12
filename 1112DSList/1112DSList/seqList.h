#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "commone.h"

#define ElemType int // 定义元素类型
#define SEQLIST_SIZE 8 //顺序表默认大小

//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	rsize_t szie;
}SeqList;
//函数声明
void SeqListInit(SeqList *plist);//初始化顺序表
void SeqListDestory(SeqList *plist);//摧毁顺序表

void CheckCapacity(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);//尾部插入数据
void SeqListPopBack(SeqList *plist);//尾部删除数据
void SeqListPushFront(SeqList *plist, ElemType x);//头部插入数据
void SeqListPopfront(SeqList *plist);//头部删除数据
size_t SeqListFind(SeqList *plist, ElemType x);//按值查找元素

size_t SeqListLeng(SeqList *plist);//求顺序表的长度
void SeqListClear(SeqList *plist);//清空数据表
void SeqListInsert(SeqList* plist, size_t pos, ElemType x);//按位置插入元素
void SeqListErase(SeqList* plist, size_t pos);//按位置删除元素

void SeqListDisplay(SeqList *plist);//打印顺序表

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
		printf("空间已满，%d不能插入\n", x);
		return;
	}
	plist->base[plist->szie++] = x;
}
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	if (Isempty(plist))
	{
		printf("顺序表已空，不能尾部删除！\n");
	}
	plist->base[plist->szie--];
}
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("顺序表已满，%d不能插入！\n", x);
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
		printf("顺序表已空，不能头部删除！\n");
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
		printf("顺序表已满，%d不能在%d位置插入！\n", x, pos);
	}
	if (pos > plist->capacity || pos < 0)
	{
		printf("位置非法！不能插入！\n");
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
		printf("顺序表已空，不能删除！\n");
	}
	if (pos > plist->capacity || pos < 0)
	{
		printf("位置非法！不能删除！\n");
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