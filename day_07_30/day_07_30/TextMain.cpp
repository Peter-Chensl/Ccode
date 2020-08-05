#include "bintree.h"

int main()
{
/*
ABC##DE##F##G#H##
 */
	Bintree bt;
	BintreeInit(&bt);
	//BintreeCreate(&bt);
	const char *str = "ABC##DE##F##G#H##";
	int index = 0;
	bt = BinTreeCreate2(str, &index);
	printf("size = %d\n",BintreeSize(bt));
	printf("height = %d\n", Bintreeheight(bt));
	printf("先序遍历：" );
	BintreeVLR_Nor(bt);
	//BintreeVLR(bt);
	printf("\n");
	printf("中序遍历：");
	BintreeLVR_Nor(bt);
	printf("\n");
	printf("后序遍历：");
	BintreeLRV(bt);
	printf("\n");
	printf("层次遍历：");
	BinTreeLevel(bt);
	printf("\n");
	system("pause");
	return 0;
}