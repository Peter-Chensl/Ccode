#include "chess.h"

void meau() //��Ϸ�˵�
{
	printf("************************\n");
	printf("*     1.��ʼ��Ϸ       *\n");
	printf("*     2.�˳���Ϸ       *\n");
	printf("************************\n");
	printf("��ѡ��");
}
int main()
{
	int quit = 0;
	do{
		int select = 0;
		meau();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
	} while (!quit);
	system("pause");
	return 0;
}