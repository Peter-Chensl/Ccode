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
	printf("���������" );
	BintreeVLR(bt);
	printf("\n");
	printf("���������");
	BintreeLVR(bt);
	printf("\n");
	printf("���������");
	BintreeLRV(bt);
	printf("\n");
	printf("��α�����");
	BintreeLelve(bt);
	printf("\n");
	system("pause");
}