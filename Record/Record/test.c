#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable:4996) 

#define SIZE 128
#define TRY_COUNT 3

#define TRY_NAME "С��" 
#define TRY_PSD "nihao"

int main()
{
	//��д����ʵ��ģ���û��ĵ�¼����������ֻ�ܵ�¼����
	char name[SIZE];//�û���
	char password[SIZE];//����
	int count = 0;//����Ĵ���
	START:
	count = TRY_COUNT;
	while (count > 0)
	{
		printf("����������˺ţ�");
		scanf("%s", name);
		printf("������������룺");
		scanf("%s", password);

		if (strcmp(name, TRY_NAME) == 0 && strcmp(password, TRY_PSD) == 0)
		{
			printf("��ӭ %s���룡\n", name);
			break;
		}
		else
		{
			count--;
			printf("��¼ʧ�ܣ���������û����������Ƿ���ȷ������ʣ��%d���λ���!\n", count);
		}
	}
	if (count == 0)
	{
		printf("��¼ʧ�ܣ�����60S�����ԣ�\n");
		int _time = 60;
		while (_time > 0)
		{
			printf("��ʣ...%ds\r", _time);
			Sleep(1000);
			_time--;
		}
		printf("\n");
		goto START;
	}
	system("pause");
	return 0;
}