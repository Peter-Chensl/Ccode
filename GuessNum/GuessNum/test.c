#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

void Meau()//��ӡ��Ϸ�˵�
{
	printf("**************************\n");
	printf("*       1.��ʼ��Ϸ       *\n");
	printf("*       2.�˳���Ϸ       *\n");
	printf("**************************\n");
	printf("��ѡ��");
}
void PlayGame()
{
	printf("---------��Ϸ��ʼ-----------\n");
	srand((unsigned int)time(NULL)); 

	int num = rand() % 100 + 1;//ģ100�������ǿ��Ƽ�������ɵ�������100����
	printf("��Ϸ���򣺼�������������1-100֮������֣�����Ҫ�³���������ɵ�����Ϊ���٣�\n");
	for (;;)
	{
		printf("��²��������:");
		int guess = 0;

		scanf("%d", &guess);
		if (guess > num)
		{
			printf("��´��ˣ�");
		
		}
		else if (guess < num)
		{
			printf("���С�ˣ�");

		}
		else
		{
			printf("'��ϲ�㣬�¶��ˣ������ǣ�%d\n",num);
			break;
		}
	}
	printf("---------��Ϸ����----------- \n");
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
			printf("��Ϸ������\n");
			exit(0);
			break;
		default:
			printf("��������������������룡\n");
			break;
		}
		
	
	}

	system("pause");
	return 0;
}