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
	printf("���������" );
	BintreeVLR_Nor(bt);
	//BintreeVLR(bt);
	printf("\n");
	printf("���������");
	BintreeLVR_Nor(bt);
	printf("\n");
	printf("���������");
	BintreeLRV(bt);
	printf("\n");
	printf("��α�����");
	BinTreeLevel(bt);
	printf("\n");
	system("pause");
	return 0;
}