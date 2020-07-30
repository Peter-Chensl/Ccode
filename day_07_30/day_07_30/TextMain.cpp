#include "bintree.h"

void main()
{
/*
ABC##DE##F##G#H##
 */
	Bintree bt;
	BintreeInit(&bt);
	BintreeCreate(&bt); 
	printf("size = %d\n",BintreeSize(bt));
	printf("height = %d\n", Bintreeheight(bt));
	printf("先序遍历：" );
	BintreeVLR(bt);
	printf("\n");
	printf("中序遍历：");
	BintreeLVR(bt);
	printf("\n");
	printf("后序遍历：");
	BintreeLRV(bt);
	printf("\n");
	printf("层次遍历：");
	BintreeLelve(bt);
	printf("\n");
	system("pause");
}