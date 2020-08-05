#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma warning(disable:4996)

typedef struct BintreeNode
{
	char data;
	BintreeNode *leftChild;
	BintreeNode *RightChild;
}BintreeNode;

typedef struct BintreeNode *Bintree;
BintreeNode *BintreeCreate(const char *str,int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
	{
		return NULL;
	}
	else
	{
		BintreeNode *p = (BintreeNode *)malloc(sizeof(BintreeNode));
		assert(p != NULL);
		p->data = str[*i];
		(*i)++;
		p->leftChild=BintreeCreate(str, i);
		(*i)++;
		p->RightChild=BintreeCreate(str, i); 
		return p;
	}
	
}
void BintreeLVR(Bintree b)
{
	if (b != NULL)
	{
		BintreeLVR(b->leftChild);
		printf("%c ", b->data);
		BintreeLVR(b->RightChild);
	}
}
int main()
{
	Bintree b;
	char str[100] = {0};
	scanf("%s", str);
	int i = 0;
	b = BintreeCreate(str, &i);
	BintreeLVR(b);
	system("pause");
	return 0;
}