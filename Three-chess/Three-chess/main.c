#include "chess.h"

void meau() //游戏菜单
{
	printf("************************\n");
	printf("*     1.开始游戏       *\n");
	printf("*     2.退出游戏       *\n");
	printf("************************\n");
	printf("请选择：");
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
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (!quit);
	system("pause");
	return 0;
}