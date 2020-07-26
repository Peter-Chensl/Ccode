#ifndef _STACK_H_
#define _STACK_H_

#include"Commone.h"
#define STACK_DEFAULT_SIZE 8

typedef struct SeqStack
{
	ElemType *base;
	size_t capacity;
	int top;
}SeqStack;

void SeqStackInit(SeqStack *pst,int sz);
void SeqStackPush(SeqStack *pst, ElemType x);
void SeqStackpop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst);
void SeqStacktop(SeqStack *pst, ElemType *top_val);
void SeqStackShow(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

bool IsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}
bool IsEmpety(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}
void SeqStackInit(SeqStack *pst,int sz)
{
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (ElemType *)malloc(sizeof(ElemType)*pst->capacity);
	pst->top = 0;
}
void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("栈已满，不能入栈");
		return;
	}
	pst->base[pst->top++] = x;
}
void SeqStackpop(SeqStack *pst)
{
	assert(pst != NULL);
	if (IsEmpety(pst))
	{
		printf("栈以空，不能出栈");
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	assert(!IsEmpety(pst));
	return pst->base[pst->top-1];
}
void SeqStacktop(SeqStack *pst, ElemType *top_val)
{
	assert(pst != NULL);
	if (IsEmpety(pst))
	{
		printf("栈已空，不能取栈顶元素！");
	}
	*top_val = pst->base[pst->top - 1];
}
void SeqStackShow(SeqStack * pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; i--){
		printf("| %d |\n", pst->base[i]);
	}
}
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

#endif