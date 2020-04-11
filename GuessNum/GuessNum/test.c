#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

void Meau()//打印游戏菜单
{
	printf("**************************\n");
	printf("*       1.开始游戏       *\n");
	printf("*       2.退出游戏       *\n");
	printf("**************************\n");
	printf("请选择：");
}
void PlayGame()
{
	printf("---------游戏开始-----------\n");
	srand((unsigned int)time(NULL)); 

	int num = rand() % 100 + 1;//模100的作用是控制计算机生成的数字在100以内
	printf("游戏规则：计算机会随机生成1-100之间的数字，你需要猜出计算机生成的数字为多少！\n");
	for (;;)
	{
		printf("你猜测的数字是:");
		int guess = 0;

		scanf("%d", &guess);
		if (guess > num)
		{
			printf("你猜大了！");
		
		}
		else if (guess < num)
		{
			printf("你猜小了！");

		}
		else
		{
			printf("'恭喜你，猜对了！数字是：%d\n",num);
			break;
		}
	}
	printf("---------游戏结束----------- \n");
}

int main()
{
	int quit = 0;
	while (!quit)
	{
		Meau();
		int meau = 0;
		scanf("%d", &meau);
		switch (meau)
		{
		case 1:
			PlayGame();
			break;
		case 2:
			printf("游戏结束！\n");
			exit(0);
			break;
		default:
			printf("你的输入有误，请重新输入！\n");
			break;
		}
		
	
	}

	system("pause");
	return 0;
}