#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vld.h>
#include <stack>
#include <stdbool.h>

typedef  char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	LinkStackNode *link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;

void LinkStackInit(LinkStack *ls);
void LinkStackPush(LinkStack *ls, ElemType x);
bool LinkStackIsEmpty(LinkStack *ls);
void LinkStackPop(LinkStack *ls);
ElemType LinkStackTop(LinkStack *ls);
void LinkStackDestroy(LinkStack *ls);
bool isValid(LinkStack *ls);

void LinkStackInit(LinkStack *ls)
{
	assert(ls != NULL);
	*ls = NULL;
}
void LinkStackPush(LinkStack *ls, ElemType x)
{
	assert(ls != NULL);
	LinkStackNode *s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	s->data = x;
	s->link = *ls;
	*ls = s;
}
bool LinkStackIsEmpty(LinkStack *ls)
{
	assert(ls != NULL);
	return *ls == NULL;
}
void LinkStackPop(LinkStack *ls)
{
	assert(ls != NULL);
	if (*ls != NULL)
	{
		LinkStackNode *p = *ls;
		*ls = p->link;
		free(p);
	}
}
ElemType LinkStackTop(LinkStack *ls)
{
	assert(ls != NULL&&*ls != NULL);
	return (*ls)->data;
}
void LinkStackDestroy(LinkStack *ls)
{
	assert(ls != NULL);
	LinkStackNode *p = *ls;
	while (p != NULL)
	{
		(*ls) = p->link;
		free(p);
		p = *ls;
	}
}
bool isValid(char *s)
{
	if (s == NULL)
	{
		return false;
	}
	if (*s == '\0')
	{
		return true;
	}
	LinkStack st;
	LinkStackInit(&st);
	while (*s != '\0')
	{
		if (*s == '{' || *s == '[' || *s == '(')
		{
			LinkStackPush(&st, *s);
		}
		else
		{
			if (LinkStackIsEmpty(&st))
			{
				return false;
			}
			char top = LinkStackTop(&st);
			if ((*s == '}'&&top != '{') || (*s == ']'&&top != '[') || (*s == ')' && top != '('))
			{
				return false;
			}
			LinkStackPop(&st);
		}
		s++;
	}
	bool flag = LinkStackIsEmpty(&st);
	LinkStackDestroy(&st);
	return flag;
}

int main()
{
	char *str = "{()}";
	bool flag = isValid(str);
	if (flag)
	{
		printf("OK!\n");

	}
	else
	{
		printf("Error!\n");
	}
	system("pause");
	return 0;
}