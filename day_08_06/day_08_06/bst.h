#ifndef _BST_H_
#define _BST_H_
#include "Commone.h"

typedef int BstElemType;
typedef struct BSTNode
{
	BstElemType data;
	struct BSTNode *leftChild;
	struct BSTNode *rightChild;
}BSTNode;

typedef BSTNode *BSTree;
void BSTInit(BSTree *bst);
bool BstInsert(BSTree *bst, BstElemType x);
BstElemType BstMin(BSTree *bst);
BstElemType BstMax(BSTree *bst);
void BstSortPrint(BSTree *bst);
BSTNode *BstFind(BSTree *bst, BstElemType key);



void BSTInit(BSTree *bst)
{
	*bst = NULL;
}
bool BstInsert(BSTree *bst, BstElemType x)
{
	if (*bst == NULL)
	{
		*bst = (BSTNode *)malloc(sizeof(BSTNode));
		assert(bst != NULL);
		(*bst)->data = x;
		(*bst)->leftChild = (*bst)->rightChild = NULL;
		return true;
	}
	if (x < (*bst)->data)
		return BstInsert(&(*bst)->leftChild,x);
	else
		return BstInsert(&(*bst)->rightChild,x);
}
BstElemType BstMin(BSTree *bst)
{
	assert(bst != NULL);
	BSTNode *p = *bst;
	while (p->leftChild != NULL)
	{
		p = p->leftChild;
	}
	return p->data;
}
BstElemType BstMax(BSTree *bst)
{
	assert(bst != NULL);
	BSTNode *p = *bst;
	while (p->rightChild != NULL)
	{
		p = p->rightChild;
	}
	return p->data;
}
void BstSortPrint(BSTree *bst)
{
	assert(bst != NULL);
	if ((*bst) != NULL)
	{
		BstSortPrint(&(*bst)->leftChild);
		printf("%d ", (*bst)->data);
		BstSortPrint(&(*bst)->rightChild);
	}
}
BSTNode *BstFind(BSTree *bst, BstElemType key)
{
	assert(bst != NULL);
	if (*bst == NULL)
		return NULL;
	else
		if (key > (*bst)->data)
			BstFind(&(*bst)->rightChild, key);
		else 
			return BstFind(&(*bst)->leftChild, key);
	
}
bool BstErase(BSTree *bst,BSTNode*p)
{
	if (*bst != NULL)
	{
		if (p->data < (*bst)->data)
		{
			BstErase(&(*bst)->leftChild, p);
		}
		else if (p->data >(*bst)->data)
		{
			BstErase(&(*bst)->rightChild, p);
		}
		else
		{
			if (p->leftChild == NULL &&p->rightChild == NULL)
			{
				free(*bst);
				*bst = NULL;
			}
			else if (p->leftChild != NULL &&p->rightChild == NULL)
			{
				(*bst) = p->leftChild;
				free(p);
			}
			else if (p->leftChild != NULL &&p->rightChild != NULL)
			{
				(*bst) = p->rightChild;
				free(p);
			}
			else
			{
				BSTNode *s = p->leftChild;
				while (s->leftChild != NULL)
				{
					s = s->rightChild;
				}
				p->data = s->data;
				BstErase(&p->rightChild, s);
			}
			return true;
		}
	}
}
#endif