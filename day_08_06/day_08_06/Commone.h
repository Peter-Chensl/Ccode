#ifndef _COMMONE_H_
#define _COMMONE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <vld.h>
#define Elemtype int
void Swap(Elemtype *a, Elemtype *b)
{
	Elemtype temp = *a;
	*a = *b;
	*b = temp;
}

#pragma warning(disable:4996)

#endif