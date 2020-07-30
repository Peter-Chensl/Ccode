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

void BintreeInit(Bintree *bt);
void BintreeCreate(Bintree *bt);
int BintreeSize(Bintree bt);
void BintreeVLR(Bintree bt);
void BintreeLVR(Bintree bt);
void BintreeLRV(Bintree bt);
void BintreeLelve(Bintree bt);
int Bintreeheight(Bintree bt);
//BintreeNode *


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
void BintreeLelve(Bintree bt)
{

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
#endif